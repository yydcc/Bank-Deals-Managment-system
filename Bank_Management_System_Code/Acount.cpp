#include <iostream>
#include <fstream>
#include <iomanip>
#include "Acount.h"
#include "deal.h"
#include "date.h"
#include <ctime>
using namespace std;
Acount::Acount(string name,string user_id,string password,double balance,acount_state state = available,const date& time = date(0))
:name(name),user_id(user_id),password(password),state(state),balance(balance),create_time(time){
    card_id = gernerate_card_id();
}
Acount::Acount(string name,string user_id,string card_id,string password,double balance,acount_state state = available,const date& time = date(0))
:name(name),user_id(user_id),card_id(card_id),password(password),balance(balance),state(state),create_time(time){}
string Acount::gernerate_card_id(){
    char time_buff[128]={0};
    sprintf(time_buff,"%d%d%d",this->create_time.year,this->create_time.minute,this->create_time.day);
    int rand_num=rand()%200+100;
    char buf[128]={0};
    sprintf(buf,"%d",rand_num);
    return string(time_buff) + string(buf);
}

string Acount::get_name(){
    return this->name;
}

string Acount::get_card_id(){
    return this->card_id;
}

struct date& Acount::get_create_time(){
    return this->create_time;
}

string Acount::get_user_id(){
    return this->user_id;
}

double Acount::get_balance(){
    return this->balance;
}

string Acount::get_password(){
    return this->password;
}

string Acount::get_state(){
    if(this->state == available) return "正常";
    else return "异常";
}
bool Acount::set_state(acount_state state){
    this->state = state;
} 

void Acount::set_password(string new_password){
    this->password = new_password;
}
void Acount::transfer_payment(string obj,string obj_name,double money){
    deal* new_deal = new deal(out,obj,obj_name,money,date(0));
    this->balance -= money;
    this->add_deal(*new_deal);
}

void Acount::transfer_get_payment(string transferor,string transferor_name,double money){
    deal* new_deal =  new deal(in,transferor,transferor_name,money,date(0));
    this->balance += money;
   	this->add_deal(*new_deal);
}
void Acount::show_information(){
    // 展示账户姓名，用户唯一标识，银行账号，余额，开户日期，账号是否可用等信息
    cout << "用户姓名: " << this->name << "\t" << "用户id: " << this->user_id << "\t"
    << "银行账号: " << this->card_id << "\t" << "余额: "  << this->balance << "元\t" << "开户日期: " << this->create_time.year <<"年"<<this->create_time.month<<"月"
    <<this->create_time.day<<"日\t"<<"账户状态:" <<this->get_state() <<"\n";
}

void Acount::deposit(double add_money){
    deal* new_deal = new deal(depos,string("000000"),string("MyBank"),add_money,date(0));
    this->balance += add_money;
   	add_deal(*new_deal);
}
void Acount::withdraw(double sub_money){
    deal* new_deal = new deal(withd,string("000000"),string("MyBank"),sub_money,date(0));
    this->balance -= sub_money;
    add_deal(*new_deal);
}
void Acount::show_deals(){
    ifstream user_in(deal_path+this->get_name()+this->get_card_id()+"_deals.txt",ios::in);
    if(!user_in.is_open()){
        cout << "\t\tcan not open the file\n";
        return ;
    }
    string title;
    getline(user_in,title);
    if(title == ""){
    	cout << "\t\t" <<this->get_name() <<"的账户" << this->get_card_id() <<"交易记录为空" << endl;
	    return;//数据为空，直接退出
	}
	cout << "用户"<< get_name() << "的交易记录如下表："<<endl;
	cout << deal_title << endl;
    string temp_type;
    string temp_id;
    string temp_name;
    string temp_time;
    double temp_money;
    while(user_in >> temp_type >> temp_name >> temp_id >> temp_money >> temp_time){
    	cout <<  temp_type <<"\t\t\t"<< temp_name << "\t\t\t" << temp_id << "\t\t\t"<< temp_money <<"\t\t\t" << temp_time << endl;
    }
    user_in.close();
    return;
}

bool Acount::add_deal(const deal& new_deal){
	fstream out(deal_path + this->get_name()+ this->get_card_id() + "_deals.txt",ios::out | ios::app);
	if(!out.is_open()) {
		cout << "\t\tcan not open the file\n";
		system("pause");
	}
	out.seekg(0,ios::beg);
	int st = out.tellg();
	out.seekg(0,ios::end);
	int ed = out.tellg();
	if(ed - st == 0){
	out << deal_title << endl;
	}
	out << new_deal.get_type() << "\t\t\t" << new_deal.obj_name << "\t\t" << new_deal.obj << "\t\t" << new_deal.money << "\t\t\t" << new_deal.time << endl;
	out.close();
}

