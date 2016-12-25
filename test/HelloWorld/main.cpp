#include "../../include/string.hpp"
#include "../../include/iostream.hpp"
#include "../../include/singleton.hpp"
#include "../../include/stl.hpp"
#include "../../include/hash.hpp"
#include "../../include/application.hpp"
#include <conio.h>

class test : public std::singleton<test>
{
public:
     int Ausgabe() {
        std::string var = std::string("Hello world");
        std::string outstring = std::frmstring(
                "%s from asSTL v. %s",
                var.c_str(),
                std::asstlVersion().c_str() );
        std::Console::writeline(outstring);
        
        std::hash<std::string> g;
        uint32_t crc = g(var);
        std::Console::writeline(
            std::frmstring("Bitte druecken Sie eine Taste ... 0x%X", crc));
        _getch();
        return 0;
     }
};

int asMain(std::list<std::string> args) {
    return test::get().Ausgabe();
}

