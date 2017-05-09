#include "../../include/string.hpp"
#include "../../include/string_utils.hpp"
#include "../../include/event.hpp"
#include "../../include/iostream.hpp"
#include "../../include/application.hpp"

#include <conio.h>

class serverEventArgs : public std::eventArgs {
public:
   serverEventArgs(std::string msg)  { m_msg = msg; }
   std::string getMessage() { return m_msg; }
private:
    std::string m_msg;   
};
class Server : public std::object
{
public:
    std::event<serverEventArgs> MessageSent;

    void SendMessage(serverEventArgs p_msg)
    {
        std::Console::writeline("Server send message: ");
        MessageSent(this, p_msg);
    }
};


class test : public std::Program {
public:
    int Main() {
        Server server;
        
        server.MessageSent += new std::delegate<test, serverEventArgs>
                (this, &test::Server_OnMessageSent);
        server.MessageSent += new std::delegate<test, serverEventArgs>
                (this, &test::Server_OnMessageSent);
        server.MessageSent += new std::delegate<test, serverEventArgs>
                (this, &test::Server_OnMessageSent);
        
        server.SendMessage(serverEventArgs(std::string("Hallo C++ EventSystem")));
        
        std::Console::writeline("Bitte druecken Sie eine Taste ...");
        _getch();
        
        return 0;
    }
private:
    void Server_OnMessageSent(const std::object* sender, serverEventArgs msg) {
        static int iindex; iindex++;
        
        std::Console::writeline(std::frmstring("Client%d reach messages: %s", 
                iindex, msg.getMessage().c_str()));
    }

};

SET_PROGRAM(test);



