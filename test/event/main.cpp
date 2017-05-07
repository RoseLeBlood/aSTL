#include "../../include/string.hpp"
#include "../../include/string_utils.hpp"
#include "../../include/event.hpp"
#include "../../include/iostream.hpp"
#include "../../include/application.hpp"

#include <conio.h>

class Server;
class Client;

using ServerEvent = std::event<Server, std::string>;
using ClientDelegate = std::delegate<Client, Server, std::string>;

class Server
{
public:
    ServerEvent MessageSent;

    void SendMessage(std::delegateparam<std::string>* p_msg)
    {
        std::Console::writeline("Server send message: ");
        MessageSent(this, p_msg);
    }
};

class Client
{
    void MessageSentHandler(const Server* p_sender, std::delegateparam<std::string>* p)
    {
        static int iindex; iindex++;
        
        std::Console::writeline(std::frmstring("Client%d reach messages: ", iindex));
	for(auto i = p->m_data.begin(); i != p->m_data.end(); i++) {
            std::Console::writeline(std::frmstring(" %s", (*i).c_str()));
	}
        std::Console::writeline("-------------------------------");
    }
public:
    Client(Server* p_server)
    {
        p_server->MessageSent += new ClientDelegate(this, &Client::MessageSentHandler);
    }
}; 


int asMain(std::list<std::string> args)  {
    Server server;
    Client client1(&server), client2(&server), client3(&server);

    std::delegateparam<std::string> param;
    param += ( std::string("Hallo Welt"));
    param += ( std::string("Wie geht's?"));
    param += ( std::string("Ach ganz gut"));

    server.SendMessage(&param);

    std::Console::writeline(std::string("Bitte druecken Sie eine Taste ..."));
      _getch();
    return 0;
}

