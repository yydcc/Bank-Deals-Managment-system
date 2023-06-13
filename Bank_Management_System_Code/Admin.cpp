#include "Admin.h"
#include "Acount.h"
#include <string>
#include <iostream>
using namespace std;
Admin::Admin(string admin_id,string password):
admin_id(admin_id),password(password){}

void Admin::create_acount(map<string,Acount*>& users,string name,string user_id,string password,double balance,acount_state state){
    Acount* new_user = new Acount(name,user_id,password,balance,state,date(0));
    deal* new_deal = new deal(depos,string("000000"),string("MyBank"),balance,date(0));
    new_user->add_deal(*new_deal);
	users.insert(std::make_pair(new_user->get_user_id(),new_user));
}

Acount* Admin::find_userx(map<string,Acount*>& users,string user_id ){
    auto it = users.find(user_id);
    if(it == users.end()) return nullptr;
    else return it->second;
 }

void Admin::destory_acount(map<string,Acount*>& users,string user_id){
    if(this->find_userx(users,user_id) != nullptr)
        users.erase(user_id);
}

bool Admin::set_state(map<string,Acount*>& users,string user_id,acount_state state){
    auto it = this->find_userx(users,user_id);
    if(it == nullptr) return false;
    else it->set_state(state);
    return true;
}

void Admin::show_acounts(map<string,Acount*>& users){
     cout << "用户姓名\t" << "用户id\t\t" << "银行账号\t\t" << "余额（元）\t" << "开户时间\t" << "\t账户状态" << endl;
    for(auto it = users.begin();it!= users.end();it++){
        auto it1 = it->second;
        cout << it1->get_name() << "\t\t" << it1->get_user_id()<<"\t\t"  
        << it1->get_card_id() << "\t\t" << it1->get_balance() << "\t\t" 
        << it1->get_create_time().year <<"年" << it1->get_create_time().month << "月" 
        << it1->get_create_time().day << "日" << "\t\t" << it1->get_state() << endl;
    }
}

void Admin::show_deals(map<string,Acount*>& users,string user_id){
    auto it = find_userx(users,user_id);
    if(it == nullptr) return;
    else it->show_deals();
    return;
}

bool Admin::set_password(map<string,Acount*>& users,string user_id,string password){
    auto it = find_userx(users,user_id);
    if( it == nullptr) return false;
    else it->set_password(password);
    return true;
}

void Admin::transfer(map<string,Acount*>&users,string from_id,string to_id,double money){
    auto from = find_userx(users,from_id),to = find_userx(users,to_id);
    if(from == nullptr || to == nullptr) return ;
    from->transfer_payment(to_id,to->get_name(),money);
    to->transfer_get_payment(from_id,from->get_name(),money);
}

void Admin::deposit(map<string,Acount*>& users,string user_id,double money){
    auto it = find_userx(users,user_id);
    if(it == nullptr) return;
    else it->deposit(money);
}

void Admin::withdraw(map<string,Acount*>& users,string user_id,double money){
    auto it = find_userx(users,user_id);
    if(it == nullptr) return;
    else it->withdraw(money);
}

void Admin::change_self_password(string password){
    this->password = password;
}
string Admin::get_password(){
    return this->password;
}

double Admin::get_balance(map<string,Acount*>& users,string user_id){
    auto it = find_userx(users,user_id);
    if(it == nullptr) return -1.0;
    else return it->get_balance();
}

