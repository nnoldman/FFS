#include "stdafx.h"
#include "Bundle.h"
#include "Core\Connection.h"

BundleReceiver::BundleReceiver(Connection* ss, char* data, u16 len)
    : mSocket(&ss->getSocket())
    , mLength(len)
    , mBuffer(data) {

}

BundleReceiver::~BundleReceiver() {
}

bool BundleReceiver::valid() const {
    u16 len = *((u16*)mBuffer);
    return len + kHeaderLength == mLength;
}

ProtocoBuffer* BundleReceiver::get() const {
    return (ProtocoBuffer*)(mBuffer);
}

BundleSender::BundleSender()
    : mBuffer(Default::ReceiveBufferSize) {
}

void BundleSender::setConnection(Poco::Net::StreamSocket& ss) {
    mSocket = &ss;
}

void BundleSender::send(ProtocoBuffer* pkg, int len) {
    mBuffer.clear();
    mLength = kIDLength + len;
    dMemoryCopy(mBuffer.getPointer(), &mLength, kIDLength);
    dMemoryCopy(mBuffer.getPointer() + kIDLength, pkg, len);
    mSocket->sendBytes(mBuffer.getPointer(), mLength);
}

void BundleSender::sendFlatbuffer(u32 opcode, u32 length, char* data) {
    mBuffer.clear();
    mLength = kIDLength + length;
    dMemoryCopy(mBuffer.getPointer(), &mLength, kIDLength);
    dMemoryCopy(mBuffer.getPointer() + kIDLength, data, length);
    mSocket->sendBytes(mBuffer.getPointer(), mLength);
}

void BundleSender::sendProtoBuffer(u32 opcode, google::protobuf::MessageLite* message) {
    mBuffer.clear();
    u32 len = message->ByteSize();
    mLength = kIDLength + len;
    dMemoryCopy(mBuffer.getPointer(), &mLength, kIDLength);
    message->SerializeToArray((void*)(mBuffer.getPointer() + kIDLength), len);
    mSocket->sendBytes(mBuffer.getPointer(), mLength);
}

