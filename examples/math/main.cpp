/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: annas
 *
 * Created on 30. November 2016, 15:38
 */

#include "../../include/math/matrix4x4.hpp"
#include "../../include/iostream.hpp"
#include "../../include/application.hpp"
#include <conio.h>


#include <conio.h>
using namespace std;

class test : public Program
{
public:
    override int Main() {
        vec2();
        vec3();
        vec4();

        std::math::mat4f mat = std::math::matrix4x4_identity<float>();

        std::Console::writeline( std::frmstring("mat4:\n%s" ,mat.to_string().c_str()) );
        
        
        
        return 0;
     }
private:   
     void vec2()
    {
        std::math::vec2f a = std::math::vec2f(3,2);
        std::math::vec2f b = std::math::vec2f(1,2);
        std::math::vec2f c = a + b;

        std::Console::writeline(std::frmstring("vec2: %s + %s = %s" ,std::vec2_string(a).c_str(),
                std::vec2_string(b).c_str(), std::vec2_string(c).c_str()) );

        c = a * b;
        std::Console::writeline(std::frmstring("vec2: %s * %s = %s" , a.to_string().c_str(),
                 b.to_string().c_str(), c.to_string().c_str()) );

        c = a - b;
        std::Console::writeline(std::frmstring("vec2: %s - %s = %s" , a.to_string().c_str(),
                 b.to_string().c_str(), c.to_string().c_str()) );

         c = a / b;
        std::Console::writeline(std::frmstring("vec2: %s / %s = %s" , a.to_string().c_str(),
                 b.to_string().c_str(), c.to_string().c_str()) );
    }
    void vec3()
    {
        std::math::vec3f a = std::math::vec3f(3,2,1);
        std::math::vec3f b = std::math::vec3f(1,2,3);
        std::math::vec3f c = a + b;

        std::Console::writeline(std::frmstring("vec3: %s + %s = %s" ,std::vec3_string(a).c_str(),
                std::vec3_string(b).c_str(), std::vec3_string(c).c_str()) );

        c = a * b;
        std::Console::writeline(std::frmstring("vec3: %s * %s = %s" , a.to_string().c_str(),
                 b.to_string().c_str(), c.to_string().c_str()) );

        c = a - b;
        std::Console::writeline(std::frmstring("vec3: %s - %s = %s" , a.to_string().c_str(),
                 b.to_string().c_str(), c.to_string().c_str()) );

         c = a / b;
        std::Console::writeline(std::frmstring("vec3: %s / %s = %s" , a.to_string().c_str(),
                 b.to_string().c_str(), c.to_string().c_str()) );
    }
    void vec4()
    {
        std::math::vec4f a = std::math::vec4f(3,2,1,0.5f);
        std::math::vec4f b = std::math::vec4f(1,2,3,4);
        std::math::vec4f c = a + b;

        std::Console::writeline(std::frmstring("vec4: %s + %s = %s" ,std::vec4_string(a).c_str(),
                std::vec4_string(b).c_str(), std::vec4_string(c).c_str()) );

        c = a * b;
        std::Console::writeline(std::frmstring("vec4: %s * %s = %s" , a.to_string().c_str(),
                 b.to_string().c_str(), c.to_string().c_str()) );

        c = a - b;
        std::Console::writeline(std::frmstring("vec4: %s - %s = %s" , a.to_string().c_str(),
                 b.to_string().c_str(), c.to_string().c_str()) );

         c = a / b;
        std::Console::writeline(std::frmstring("vec4: %s / %s = %s" , a.to_string().c_str(),
                 b.to_string().c_str(), c.to_string().c_str()) );
    }
 
};
SET_PROGRAM(test);




