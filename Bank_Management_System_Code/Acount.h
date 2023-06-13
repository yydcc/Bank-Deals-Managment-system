#ifndef __MYACOUNT__
#define __MYACOUNT__
#include <string>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Admin.h" 
#include "global.h" 
#include "date.h"
#include "deal.h"
using namespace std;
struct date;

class Acount
{
private:
    string name;//账户姓名
    string user_id;//用户唯一标识
    string card_id;//银行账号
    string password;//账户登录密码
    struct date create_time; //开户日期
    double balance;//余额
    acount_state state;//账户状态是否可用
	public:
	Acount() = default;
    Acount(string,string,string,double,acount_state,const date&);
    Acount(string,string,string,string,double,acount_state,const date&);
    string gernerate_card_id(); // 根据开户时间及随机数分配银行账号
    void show_information(); // 展示账户姓名，用户唯一标识，银行账号，余额，开户日期，账号是否可用等信息 
	string get_name();	//返回姓名	 
    string get_user_id();//返回用户id 
    string get_card_id();//返回卡号 
    string get_state();//返回状态 
    double get_balance();//返回余额 
    string get_password();//返回密码 
    bool set_state(acount_state state);//设置状态 
    struct date& get_create_time();//返回开户时间 
    void set_password(string new_password); //重新设置密码
    void transfer_payment(string obj,string obj_name,double money);//转账
    void transfer_get_payment(string transferor,string transferor_name,double money);//接受别人的转账
    void show_deals();//屏幕打印交易记录表 
    void deposit(double);//存款
    void withdraw(double);//取款
    bool add_deal(const deal&);//新增交易记录 
};
#endif
