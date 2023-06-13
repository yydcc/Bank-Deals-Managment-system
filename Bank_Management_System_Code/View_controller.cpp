#include "View_controller.h"
#include "Bank.h"
#include "Admin.h"
#include "Acount.h"
#include <map>
#include <string>
#include <iomanip>
using namespace std;

View_controller::View_controller(Bank *x){
    this->bank = x;
    bank_admin = bank->get_admin();
    admins = bank->get_admins_sheet();
    users = bank->get_users_sheet();
}

View_controller::~View_controller(){
    cout << "\t\t~~感谢您的使用，欢迎下次再来~~" << "\n";
    system("pause");
}
void View_controller::main_menu(){
	system("cls");
    system("color F5");
    cout << "\t\t~~欢迎来到银行交易管理系统~~\t\t" << endl;
    cout << "\t\t   -------------------------   " << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|      ~~请选择登录模式~~     |" << endl;
	cout << "\t\t|                             |" << endl;
    cout << "\t\t|          1.储户             |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|          2.管理员           |" << endl; 
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|          0.退出系统         |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t-------------------------------" << endl;
}

void View_controller::user_login(){
    cout << "\t\t尊敬的用户,请输入您的账号与密码" << endl;
    string user_id;
    string password;
    int time = 3;
    bool flg = false;
    while(!flg && time--){
        cin >> user_id >> password;
        auto it = bank_admin->find_userx(*users,user_id);
        if(it == nullptr) {
            cout << "\t\t\t不存在该账号，请重新输入" << endl;
            continue;
        }
        else if(it->get_password() != password){
            cout << "\t\t账户或密码输入有误,请重新输入" << endl;
            continue;
        }
        tmp_user = user_id;
        flg = true;
    }
    if(flg){
    	cout << "\t\t~~登录成功~~" << endl;
		system("pause");
        user_menu();        
    } 
    else {
        cout << "\t\t您已经连续三次输入错误,将为您自动退出系统"<< endl;
        exit(0);
    }
}

void View_controller::admin_login(){
    cout << "\t\t尊敬的管理员,请输入您的账号与密码" << endl;
    string admin_id;
    string password;
    int time = 3;
    bool flg = false;
    while(!flg && time--){
        cin >> admin_id >> password;
        auto it = admins->find(admin_id);
        if(it == admins->end()) {
            cout << "\t\t\t不存在该账号,请重新输入" << endl;
            continue;
        }
        else if(it->second->get_password() != password){
            cout << "\t\t账户或密码输入有误,请重新输入" << endl;
            continue;
        }
        tmp_admin = admin_id;
        flg = true;
    }
    if(flg){
    	cout << "\t\t~~登录成功~~" << endl;
		system("pause"); 
        admin_menu(); 
    } 
    else {
        cout << "\t\t您已经连续三次输入错误,将为您自动退出系统"<< endl;
        exit(0);
    }
}

void View_controller::user_menu(){
	bool flg = true;
	while(flg){
	system("cls");
   	cout << "\t\t         银行交易管理系统        " << endl; 
    cout << "\t\t  -----------------------------  " << endl; 
	cout << "\t\t|                               |" << endl;
	cout << "\t\t|         1.展示个人信息        |" << endl;
    cout << "\t\t|         2.余额查询            |" << endl;
    cout << "\t\t|         3.存款                |" << endl;
    cout << "\t\t|         4.取款                |" << endl;
    cout << "\t\t|         5.转账                |" << endl;
    cout << "\t\t|         6.查询交易记录        |" << endl;
    cout << "\t\t|         7.修改密码            |" << endl;
    cout << "\t\t|         0.返回上一级          |" << endl;
    cout << "\t\t---------------------------------" << endl;
    cout << "\t\t~~请输入您要进行的操作~~(0~7):"    <<endl;
	int choice;
    cin >> choice;
    switch(choice){
        case 0: return;
    	case 1:show_ones_information(tmp_user);
    	break;
    	case 2:show_balance(tmp_user);
    	break;
    	case 3:deposit(tmp_user);	
			   bank->save_users();
        break;
        case 4:withdraw(tmp_user);
               bank->save_users();
        break;
        case 5:transfer(tmp_user);
        	   bank->save_users();
        break;
        case 6:show_deals(tmp_user);
        break;
        case 7:set_password(tmp_user);
        	   bank->save_users();
		break;
        default:
        cout << "\t\t输入有误,请重新输入" << endl;
        system("pause");
	}
    }   
}

void View_controller::admin_menu(){
		bool flg = true;
	 	while(flg){
	 	system("cls");
		cout << "\t\t         银行交易管理系统        " << endl; 
	    cout << "\t\t  -----------------------------  " << endl; 
	    cout << "\t\t|         1.开户                |" << endl;
	    cout << "\t\t|         2.设置用户状态        |" << endl;
	    cout << "\t\t|         3.删除用户            |" << endl;
	    cout << "\t\t|         4.查询用户信息        |" << endl;
	    cout << "\t\t|         5.查询用户交易记录    |" << endl;
        cout << "\t\t|         6.查询所有用户信息    |" << endl;
	    cout << "\t\t|         7.修改管理员密码      |" << endl;
	    cout << "\t\t|         0.返回上一级          |" << endl;
		cout << "\t\t---------------------------------" << endl;
    	cout << "\t\t~~请输入您要进行的操作~~(0~7):"    <<endl;
		int choice;
    	cin >> choice; 
        switch(choice){
        case 0: return ;
    	case 1:create_acount();
    			bank->save_users();
    	break;
    	case 2:set_state();
    		bank->save_users();
    	break;
    	case 3:destory_user();
        	   bank->save_users();
		break;
        case 4:show_user();
        break;
        case 5:show_user_deals();
        break;
        case 6:show_all_users();
        break;
        case 7:set_my_password();
        	   bank->save_admins(); 
        break;
        default:
        cout << "\t\t输入有误,请重新输入" << endl;
        system("pause");
    }
}
}
void View_controller::run(){
    bool flg = true;
    int option;
    while(true){
        main_menu();
        cin >> option;
        switch (option)
        {
        case 0: return;
            break;
        case 1:
            user_login();
            break;
        case 2:admin_login();
            break;
        default:
            cout << "\t\t输入有误,请重新输入" << endl;
            system("pause");
        }
    }

}


void View_controller::show_balance(string user_id){
    auto it = this->bank_admin->find_userx(*users,user_id);
    cout << "\t\t用户" << it->get_name() <<"的账户" << it->get_card_id() << "余额为" <<fixed << setprecision(2)<<it->get_balance() << "元" << endl;
    system("pause");
}

void View_controller::show_ones_information(string user_id){
    auto it = bank_admin->find_userx(*users,user_id);
    it->show_information();
    system("pause");
}

void View_controller::deposit(string user_id){
    auto it = bank_admin->find_userx(*users,user_id);
    if(it->get_state() == "异常") {
        cout << "\t\t账户异常，无法存款" << endl;
        system("pause");
        return;
    }
    cout << "\t\t请输入您要存款的金额(元) "<< endl;
    double money;
    cin >> money;
    if(money <= 0){
		cout << "\t\t输入有误，请输入一个正数" << endl;
		system("pause");
		return;
	}
    bank_admin->deposit(*users,user_id,money);
    cout << "\t\t~~存款成功~~"<< endl;
    system("pause");
}

void View_controller::withdraw(string user_id){
	auto it = bank_admin->find_userx(*users,user_id);
    if(it->get_state() == "异常") {
        cout << "\t\t账户异常，无法取款" << endl;
        system("pause");
        return;
    }
    cout << "\t\t请输入您要取款的金额(元)"<< endl;
    double money;
    cin >> money;
    if(money <= 0){
		cout << "\t\t输入有误，请输入一个正数" << endl;
		system("pause");
		return;
	}
    if(it->get_balance() < money){
        cout << "\t\t余额不足,取款失败" << endl;
        system("pause"); 
        return;
    } 
    bank_admin->withdraw(*users,user_id,money);
    cout << "\t\t~~取款成功~~" << endl;
    system("pause");
}

void View_controller::transfer(string user_id){
    auto it = bank_admin->find_userx(*users,user_id);
    if(it->get_state() == "异常") {
        cout << "\t\t账户异常，无法转账" << endl;
        system("pause");
        return;
    }
    string to_id,name;
    double money;
    cout << "\t\t请输入收款人id"<< endl;
    cin >> to_id;
    auto to = bank_admin->find_userx(*users,to_id);
    if(to == nullptr) {
        cout << "\t\t不存在该用户,操作失败"<< endl;
        system("pause");
        return;
    }
    cout << "\t\t请输入收款人姓名"<<endl;
    cin >> name;
    if(to->get_name()!=name){
        cout << "\t\t收款人id与姓名不匹配,转账失败"<<endl;
        system("pause");
        return;
    }
    cout << "\t\t请输入转账金额" << endl;
    cin >> money;
    auto from = bank_admin->find_userx(*users,user_id);
    if(money <= 0){
		cout << "\t\t输入有误，请输入一个正数" << endl;
		cout << "\t\t转账失败" << endl;
		system("pause");
		return;
	}
    if(money > from->get_balance()){
        cout << "\t\t余额不足,转账失败"<< endl;
        system("pause");
        return;
    }
    bank_admin->transfer(*users,user_id,to_id,money);
    cout << "\t\t~~转账成功" << endl;
	system("pause");
}

void View_controller::show_deals(string user_id){
    bank_admin->show_deals(*users,user_id);
    system("pause");
}

void View_controller::set_password(string user_id){
    auto it = bank_admin->find_userx(*users,user_id);
    if(it->get_state() == "异常") {
        cout << "\t\t账户异常，无法重设密码" << endl;
        system("pause");
        return;
    }
    string new_password;
    cout << "\t\t请输入您要更改的密码" << endl;
    cin >> new_password;
    bank_admin->set_password(*users,user_id,new_password);
    cout << "\t\t~~成功更改密码~~"<< endl;
    system("pause");
}

void View_controller::create_acount(){
    string user_id;
    string name;
    string password;
    double money;
    cout << "\t\t请输入开户人的id"<< endl;
    cin >> user_id;
    cout << "\t\t请输入开户人姓名"<< endl;
    cin >> name;
    cout << "\t\t请设置账户密码" << endl;
    cin >> password;
    cout << "\t\t请输入开户金额"<< endl;
    cin >> money;
    if(money <= 0){
		cout << "\t\t输入有误，请输入一个正数" << endl;
		cout << "\t\t开户失败" << endl; 
		system("pause");
		return;
	}
    bank_admin->create_acount(*users,name,user_id,password,money,available);
    cout << "\t\t~~账户创建成功" << endl;
    system("pause");
}

void View_controller::set_state(){
    cout << "\t\t请输入您要设置状态的用户id"<< endl;
    string user_id;
    cin >> user_id;
    auto it = bank_admin->find_userx(*users,user_id);
    if(it == nullptr) {
        cout << "\t\t不存在该用户,操作错误"<<endl;
        system("pause");
        return;
    }
    it->show_information();
    int option;
    if(it->get_state() == "正常"){
        cout << "\t\t当前账户状态正常,是否为您禁用该账户" << endl;
        cout << "\t\t\t1.是" << endl << "\t\t\t2.否" << endl;
        cin >> option;
        if(option == 1){  
		 it->set_state(disabled);
		}
        else if(option == 2){

        }
        else {
            cout  << "\t\t输入有误,操作失败" << endl;
            system("pause");
            return;
        }
    }
    else if(it->get_state() == "异常"){
         cout << "\t\t当前账户状态异常,是否为您启用该账户" << endl;
        cout << "\t\t\t1.是" << endl << "\t\t\t2.否" << endl;
        cin >> option;
        if(option == 1){
            it->set_state(available);
        }
        else if(option == 2){}
        else {
            cout << "\t\t输入有误,操作失败"<<endl;
       		system("pause");
       		return;
	    }
        
    }
    system("pause");
}

void View_controller::destory_user(){
    cout << "\t\t请输入您要销毁的用户id"<< endl;
    string user_id;
    cin >> user_id;
    auto it = bank_admin->find_userx(*users,user_id);
    if(it == nullptr){
        cout << "\t\t不存在该用户,操作失败"<< endl;
        system("pause");
        return;
    }
    it->show_information();
    cout << "\t\t是否为您销毁该账户"<< endl;
    cout << "\t\t\t1.是"<< endl;
    cout << "\t\t\t2.否" << endl;
    int option;
    cin >> option;
    if(option == 1){
        bank_admin->destory_acount(*users,user_id);
        cout << "\t\t\t~~销毁成功"<< endl;
        system("pause");
        return;
    }
    else if(option == 2){
        return;
    }
    else {
        cout << "\t\t输入有误,操作失败"<< endl;
        system("pause");
        return; 
    }
    system("pause");
}

void View_controller::show_user(){
    cout << "\t\t请输入您要查询的用户id"<< endl;
    string user_id;
    cin >> user_id;
    auto it = bank_admin->find_userx(*users,user_id);
    if(it == nullptr){
        cout << "\t\t不存在该用户,操作失败" << endl;
        system("pause");
        return;
    }
    it->show_information();
    system("pause");
}

void View_controller::show_user_deals(){
    cout << "\t\t请输入您要查询的用户id"<< endl;
    string user_id;
    cin >> user_id;
    auto it = bank_admin->find_userx(*users,user_id);
    if(it == nullptr){
        cout << "\t\t不存在该用户,操作失败" << endl;
        system("pause");
        return;
    }
    it->show_deals();
    system("pause");
}

void View_controller::set_my_password(){
    string password;
    cout << "\t\t请输入新密码 "<<endl;
    cin >> password;
  	auto it = admins->find(tmp_admin);
  	it->second->change_self_password(password);
  	cout << "\t\t~~密码修改成功~~" << endl; 
    system("pause");
}

void View_controller::show_all_users(){
    if(users->empty()) {
        cout << "\t\t当前用户表为空,无信息可查询" << endl;
        system("pause"); 
        return; 
    }
    cout << "\t\t银行当前共有" << users->size() << "个用户" << endl; 
    cout << "\t\t银行当前所有用户信息如下表" << endl;
    bank_admin->show_acounts(*users);
    system("pause"); 
}

