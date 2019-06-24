#ifndef CLIENT_H
#define CLIENT_H

#include <functional>
#include <memory>
#include <string>

namespace connection {


class Server;

class Client
{
    std::string id;
    std::shared_ptr<Server> server;
    void receive(std::string sender, std::string message);

public:
    Client(std::string id, std::shared_ptr<Server> server);
    void send(std::string recipient, std::string message);
    friend class Server;

};
}

#endif // CLIENT_H
