#ifndef __MYADMIN__
#define __MYADMIN__
#include <string>
#include "Acount.h"
#include "Bank.h"
#include "global.h"
using namespace std;
class Acount;
class Admin{
    private:
    string admin_id;//管理员登录账号 
    string password;//登录密码 
    public:
    Admin() = default;
    Admin(string, string);
    string get_password();//返回账户密码 
    Acount* find_userx(map<string,Acount*>& users,string user_id);//在用户表里查找某用户 
    void create_acount(map<string,Acount*>& users,string,string,string,double,acount_state);//创建用户并添加至用户表 
    void destory_acount(map<string,Acount*>& users, string user_id);//注销该用户的账户
    bool set_state(map<string,Acount*>& users,string user_id,acount_state state);//停用或重新启用账户
    void transfer(map<string,Acount*>& users,string from_id,string to_id,double money);//执行转账
    void deposit(map<string,Acount*>& users,string user_id,double money); //为用户执行存款
    void withdraw(map<string,Acount*>&users,string user_id,double money);//为用户执行取款    
    void show_acounts(map<string,Acount*>& users);//打印该银行的所有现有用户
    void show_deals(map<string,Acount*>& users,string user_id); //打印某用户的交易
    bool set_password(map<string,Acount*>& users,string user_id,string password);//更改用户密码
    double get_balance(map<string,Acount*>&users,string user_id);//返回用户余额
    void change_self_password(string password);  //更改自身密码 
};
#endif
