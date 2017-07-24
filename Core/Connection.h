#pragma once
#include "Poco\Net\TCPServerConnection.h"
#include "PKG.h"
#include "uString.h"
class Connection : public Poco::Net::TCPServerConnection {
  public:
    Connection(const Poco::Net::StreamSocket& s);

    ~Connection();

    void run();

    inline Poco::Net::StreamSocket& getSocket();

  private:

    Array<PKG*> mPKGList;

    Basic::uString mAddress;
};
inline Poco::Net::StreamSocket& Connection::getSocket() {
    return socket();
}
