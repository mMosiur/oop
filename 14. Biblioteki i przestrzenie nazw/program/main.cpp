#include <iostream>
#include <server.h>
#include <client.h>

using namespace std;

int main()
{
    shared_ptr<connection::Server> server = make_shared<connection::Server>();
    shared_ptr<connection::Client> client1 = server->newConnection("aaa");
    shared_ptr<connection::Client> client2 = server->newConnection("bbb");
    shared_ptr<connection::Client> client3 = server->newConnection("ccc");

    client1->send("bbb","hello!");

    return 0;
}
