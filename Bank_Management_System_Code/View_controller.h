#ifndef __MYView_controller__
#define __MYView_controller__
#include "Bank.h"
#include "Admin.h"
#include "Acount.h"
#include "global.h"
using std::string;
class View_controller{
    private:
    string tmp_user;	//当前的登录用户 
    string tmp_admin;	//当前的登录管理员
	Bank* bank; //该视图_操作对象控制的银行对象 
	//为了适配银行成员写的成员，否则在写代码略繁琐    
	Admin* bank_admin;	// 银行形式管理员 
    map<string,Admin*>* admins; // 管理员表 
    map<string,Acount*>* users;// 用户表 
    public:
    ~View_controller(); 
    View_controller(Bank* x); //将银行各成员传递给该对象的成员，便于代码编写 
    void main_menu();//登录初始界面，选择登录模式或退出系统
    void user_login();    //用户登录界面
    void admin_login();     //管理员登录界面
    void user_menu();   //用户操作面板
    void admin_menu();  //管理员操作面板
    void run();//界面展示的逻辑及操作控制

    //用户操作显示及控制函数
    void show_ones_information(string);//展示个人信息 
    void show_balance(string);//展示余额 
    void deposit(string);//存款 
    void withdraw(string);//取款 
    void transfer(string);//转账 
    void show_deals(string);//展示交易记录 
    void set_password(string);// 设置密码

    //管理员操作显示及控制函数
    void create_acount();//开户 
    void set_state();//为用户设置状态,"正常"或"异常" 
    void destory_user();//销毁账户 
    void show_all_users();//展示当前用户表所有用户信息 
	void show_user();//查询单个用户 
    void show_user_deals();//查询单个用户交易记录 
    void set_my_password();//设置管理员自身密码 
};

#endif
