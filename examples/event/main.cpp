#include "../../include/string.hpp"
#include "../../include/string_utils.hpp"
#include "../../include/event.hpp"
#include "../../include/iostream.hpp"
#include "../../include/application.hpp"

#include <conio.h>


class Server : public std::object
{
public:
    std::event<const char*> MessageSent;

    void SendMessage(std::string p_msg)
    {
        std::Console::writeline("Server send message: ");
        MessageSent(this, p_msg.c_str());
    }
};


class test : public std::Program {
public:
    override int Main() {
        std::application::get().ExitAppEvent +=
             new std::delegate<test, int>(this, &test::Application_OnAppExit);
        
        Server server;
        
        server.MessageSent += new std::delegate<test, const char*>
                (this, &test::Server_OnMessageSent);
        server.MessageSent += new std::delegate<test, const char*>
                (this, &test::Server_OnMessageSent);
        server.MessageSent += new std::delegate<test, const char*>
                (this, &test::Server_OnMessageSent);
        
        server.SendMessage(std::string("Hallo C++ EventSystem"));
        
        return 0;
    }
private:
    void Server_OnMessageSent(const std::object* sender, const char* msg) {
        static int iindex; iindex++;
        
        std::Console::writeline(std::frmstring("Client%d reach messages: %s", 
                iindex, msg));
    }
    void Application_OnAppExit(const std::object* sender, int p) {
        std::Console::writeline(
        std::frmstring("ExitCode: %d\nBitte druecken Sie eine Taste ...", p));
        _getch();
     }
};

SET_PROGRAM(test);



