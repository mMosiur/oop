#include "client.h"
#include "server.h"
#include <iostream>
namespace connection {
Client::Client(std::string id, std::shared_ptr<Server> server) : id(id), server(server)
{

}

void Client::send(std::string recipient, std::string message) {
    server->forward(id,recipient,message);
}

void Client::receive(std::string sender, std::string message) {
    std::cout << "(" << id << ") " << sender << ": " << message << "\n";
}
}
