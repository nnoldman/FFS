#pragma once
#include "Poco\Net\TCPServerConnection.h"
#include "ProtocoBuffer.h"
#include "uString.h"
class COREAPI Connection : public Poco::Net::TCPServerConnection {
  public:
    Connection(const Poco::Net::StreamSocket& s);

    ~Connection();

    void run();

    inline Poco::Net::StreamSocket& getSocket();

  private:
    void disconnect();
  private:
    Array<ProtocoBuffer*> mPKGList;

    Basic::uString mAddress;
    Basic::Buffer mBuffer;
    int mTargetLength;
    int mHeader = 0;
};
inline Poco::Net::StreamSocket& Connection::getSocket() {
    return socket();
}
