#include "stdafx.h"
#include "Connection.h"
#include "Bundle.h"
#include "NetWork.h"
#include "App.h"
#include "Poco\Net\NetException.h"

const int kHeaderLength_ = 4;

void Connection::run() {
    Poco::Net::StreamSocket& ss = socket();
    try {
        int length = ss.receiveBytes(mBuffer.getBuffer(), mBuffer.length());
        if (length == 0) {
            disconnect();
        } else {
            while (mBuffer.getPosition() < length) {
                if (mHeader == 0) {
                    mBuffer.readInt(mHeader);
                    mTargetLength = mHeader;
                } else {
                    App::Net.addMessage(mBuffer.currentPointer(), mTargetLength, this);
                    mBuffer.forwardPosition(mTargetLength);
                    mTargetLength = kHeaderLength_;
                    mHeader = 0;
                }
            }
        }
    } catch (Poco::Net::ConnectionResetException& exc) {
        App::Net.onDisconnect.invoke(this);
        std::cerr << "Disconnect by remote!: " << exc.displayText() << std::endl;
    }
}

void Connection::disconnect() {

}

Connection::Connection(const Poco::Net::StreamSocket& s) : TCPServerConnection(s)
    , mBuffer(Default::ReceiveBufferSize)
    , mTargetLength(kHeaderLength_) {
    this->socket().setBlocking(true);
    App::Net.onConnect.invoke(this);
}

Connection::~Connection() {
    this->socket().close();
}


