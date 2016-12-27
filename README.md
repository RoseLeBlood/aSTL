# aSTL anothers STL
Eine etwas andere Standard Libary Implantierung für den Bereich der spiele Programmierung oder Netzwerk Bereich. Für den spiele Bereich sind mathe Klassen vor implantiert unter include/math:

* template <typename T> class vector2 | vec2f<float>, vec2d<double>  
* template <typename T> class vector3 | vec3f<float>, vec3d<double>  
* template <typename T> class vector4 | vec4f<float>, vec4d<double>
* template <typename T> class rectangle 
* template <typename T> class matrix4x4 

----
Weitere Futures:
* delegates event system - see test/event/main.cpp
* properties
* string format function (std::frmstring(const char* fmt, ...); )
* another stdout and stdin output see: test/HelloWorld/main.cpp - class std::Console  

Geplante Implantierungen:
* network class for socket, tcp, ud
*img load and save
* network streams
* hash funktions
* thread and threadsafe
