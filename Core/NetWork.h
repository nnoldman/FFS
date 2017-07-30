#pragma once

#include "Poco/Net/TCPServer.h"
#include "Poco/Net/TCPServerConnection.h"
#include "Poco/Net/TCPServerConnectionFactory.h"
#include "Poco/Net/TCPServerParams.h"
#include "Poco/Net/StreamSocket.h"
#include "ProtocoBuffer.h"
#include "Connection.h"
#include "ConfigInfo.h"
#include "Poco/Mutex.h"

class CX_LIB NetWork : CallbackObject {
  public:
    Delegate onMessage;
    Delegate onDisconnect;
    Delegate onConnect;
  public:
    struct MsgArgs : public uEventArgs {
        ProtocoBuffer* pkg;
        Connection* connect;
        MsgArgs() : pkg(nullptr), connect(nullptr) {
        }
    };
    struct ConnectArg : uEventArgs {
        Connection* connect;
        ConnectArg() {
        }
    };
    struct Packet {
        u32 len;
        char* data;
        Connection* con;
        Packet() : data(nullptr), con(nullptr), len(0) {
        };
        ~Packet() {
            delete[] data;
        }
    };
  public:
    NetWork();
    ~NetWork();

    bool initialize(const NetConfig& config);

    void prosess();

    void addMessage(void* data, u32 len, Connection* con);

  private:

    Poco::Mutex mLock;

    Array<Packet*> mDataArray;

    Poco::Net::TCPServer* mServer;
};

