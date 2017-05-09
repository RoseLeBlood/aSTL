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
        string var = string("Hello world");
        string outstring = std::frmstring(
                "%s from asSTL v. %s",
                var.c_str(),
                asstlVersion().c_str() );
        Console::writeline(outstring);
        return 0;
     }
};
SET_PROGRAM(test);


