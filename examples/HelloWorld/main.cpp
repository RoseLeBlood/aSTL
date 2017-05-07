#include "../../include/string.hpp"
#include "../../include/iostream.hpp"
#include "../../include/stl.hpp"
#include "../../include/application.hpp"

#include <conio.h>
using namespace std;

class test : public Program
{
public:
    override int Main() {
        application::get().ExitAppEvent +=
                new delegate<test, int>(this, &test::OnAppExit);
                  
        string var = string("Hello world");
        string outstring = std::frmstring(
                "%s from asSTL v. %s",
                var.c_str(),
                asstlVersion().c_str() );
        Console::writeline(outstring);
        
        
        return 0;
     }
private:   
     void OnAppExit(const std::object* sender, int p) {
        Console::writeline(
            frmstring("ExitCode: %d\nBitte druecken Sie eine Taste ...", p));
        _getch();
     }
};
SET_PROGRAM(test);


