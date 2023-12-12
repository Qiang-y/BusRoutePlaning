#ifndef _PLACE_H_
#define _PLACE_H_
#include"Config.h"
class Places{
public:
    std::string name;
    std::string info;
public:
    Places();//= default;
    Places(std::string _name, std::string _info);
    ~Places();
};

#endif // PLACE_H
