#ifndef SERVER_H
#define SERVER_H

#include <map>
#include <string>
#include <memory>

#include "client.h"
namespace connection {


class Server : public std::enable_shared_from_this<Server>
{
    std::map<std::string, std::shared_ptr<Client>> clients;
    void forward(std::string sender, std::string recipient, std::string message);

public:
    Server();
    std::shared_ptr<Client> newConnection(std::string address);
    friend void Client::send(std::string recipient, std::string message);

};
}

#endif // SERVER_H
