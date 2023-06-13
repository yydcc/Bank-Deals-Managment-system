#ifndef __MYBANK__
#define __MYBANK__
#include <map>
#include <string>
#include "Acount.h"
#include "Admin.h"
using namespace std;
class Admin;
class Acount;
class Bank{
    private:
    map<string,Acount*> users;//用户表 
    map<string,Admin*> admins;//管理员表 
    Admin* Bank_admin;//形式管理员 
    public:
    Bank(); 
    ~Bank();
    bool read_users();//从文件中读取用户信息到用户表 
    bool read_admins();//从文件中读取管理员信息到管理员表 
    Admin* get_admin();//返回管理员  
    map<string,Acount*>* get_users_sheet();//返回用户表  
    map<string,Admin*>* get_admins_sheet();//返回管理员表 
    bool save_users();	//在文件中保存用户表 
    bool save_admins();//在文件中保存管理员表 
};
#endif

