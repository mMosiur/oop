#include "server.h"
#include "client.h"
#include<iostream>

namespace connection {


Server::Server()
{

}

std::shared_ptr<Client> Server::newConnection(std::string id) {
    //if(clients.find(address)==clients.end())
    clients[id]=std::make_shared<Client>(id, shared_from_this());
    return clients[id];
}

void Server::forward(std::string sender, std::string recipient, std::string message) {
    clients[recipient]->receive(sender,message);
}

}
