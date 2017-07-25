#pragma once
#include "Poco\Net\StreamSocket.h"
#include "PKG.h"
#include "google\protobuf\message_lite.h"
static const u32 HEADER_LENGTH = sizeof(u32);

class Connection;

class CX_LIB BundleReceiver {
  public:

    BundleReceiver(Connection* ss, char* data, u16 len);

    ~BundleReceiver();

    bool valid() const;

    PKG* get() const;

  private:

    Poco::Net::StreamSocket* mSocket;

    char* mBuffer;

    u32 mLength;
};

class CX_LIB BundleSender {
  private:
    BundleSender();
  public:
    static BundleSender& GetInstance() {
        static BundleSender sender;
        return sender;
    }
    void setConnection(Poco::Net::StreamSocket& ss);
    void send(PKG* pkg, int len);
    void sendFlatbuffer(u32 opcode, u32 length, char* data);
    void sendProtoBuffer(u32 opcode, google::protobuf::MessageLite* message);
  private:
    Poco::Net::StreamSocket* mSocket;
    Basic::Buffer mBuffer;
    u32 mLength;
};
#define SendPKG(streamSocket,pkg) {BundleSender sender(streamSocket);sender.send(&pkg,sizeof(pkg));}
#define SendFlatbuffer(streamSocket,opcode,length,data) {BundleSender sender(streamSocket);sender.sendFlatbuffer(opcode,length,(char*)data);}
#define SendProtoBuffer(connection,opcode,data) \
{\
	BundleSender::GetInstance().setConnection(connection);\
	BundleSender::GetInstance().sendProtoBuffer(opcode, &data);\
}

