#ifndef _CONFIG_H_
#define _CONFIG_H_

/*
 *      用来设置某些设置
 */
#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<utility>
#include"json.hpp"
using json = nlohmann::json;
//展示错误信息
#define err(Msg) (std::cout << "[" << __LINE__ << "]" << Msg << " err" << std::endl);

#endif // _CONFIG_H_
