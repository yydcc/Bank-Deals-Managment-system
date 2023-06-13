#include "Bank.h"
#include "Admin.h"
#include "Acount.h"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
Bank::Bank(){
    Bank_admin = new Admin();
    read_admins();
    read_users();
}
Bank::~Bank(){    //析构函数，先进行信息保存，然后释放内存 
    save_admins();
    save_users();
    for(auto it = users.begin();it!=users.end();it++){
    		delete it->second;
	} 
	delete Bank_admin;
			  
}
bool Bank::read_users(){
    fstream in(users_path,ios::in);
    if(!in.is_open()) {
        cout << "can not open the file\n";
        return false;
    }
    string title;
    getline(in,title);
    if(title == "") return false;
	string name;
    string user_id;
    string card_id;
    string password;
    double balance;
    string state;
   	string  create_time;
    while(in >> user_id >> name >> card_id >> balance >> password >> create_time >> state){
        acount_state temp_state;
        if(state == "异常") temp_state = disabled;
        else temp_state = available;
        for(auto&c: create_time){
            if(c == '/' || c ==':' || c == '-') c =' ';
        }
        date temp_date;
        stringstream ss;
        ss << create_time;
        ss >>  temp_date;
        Acount* temp_acount = new Acount(name,user_id,card_id,password,balance,temp_state,temp_date);
        users.insert(make_pair(user_id,temp_acount));//可能有问题
    }
    in.close();
    return true;
}
bool Bank::read_admins(){
    fstream in(admins_path,ios::in);
    if(!in.is_open()){
        cout << "can not open the file\n";
        return false;
    }
    string title;
    getline(in,title);
    if(title == "") return false;
    string admin_id;
    string password;
    while(in >> admin_id >> password){
        Admin* temp_admin = new Admin(admin_id,password);
        admins.insert(make_pair(admin_id,temp_admin));//可能有问题
    }
    in.close();
    return true;
}

Admin* Bank::get_admin(){
    return this->Bank_admin;
}

map<string,Acount*>* Bank::get_users_sheet(){
    return &users;
}

map<string,Admin*>* Bank::get_admins_sheet(){
    return &admins;
}

bool Bank::save_admins(){
	fstream out(admins_path,ios::out);
	if(!out.is_open()){
		cout << "can not open the file\n";
		system("pause"); 
		return false;
	}
	string title = "账号\t\t密码";
		out << title << endl;
	for(auto it = admins.begin();it != admins.end();it++){
		out << it->first << "\t\t" << it->second->get_password() << endl;
	}
	out.close();
	return true;
}

bool Bank::save_users(){
	fstream out(users_path,ios::out);
	if(!out.is_open()){
		cout << "can not open the file" << endl;
			system("pause");
		return false;
	}
	
	string title = "用户id\t\t用户名\t\t卡号\t\t\t余额(元)\t密码\t\t\t开户时间\t\t\t账户状态";
	out << title << endl;
	for(auto it = users.begin();it != users.end();it++){
		out << it->second->get_user_id() << "\t\t"<< it->second->get_name() << "\t\t" <<
		it->second->get_card_id() << "\t\t" <<it->second->get_balance() << "\t\t" << it->second->get_password() << "\t\t" <<
	 	it->second->get_create_time() << "\t\t" << it->second->get_state() << endl; 
	} 
	out.close();
	return true;
}



