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
    string admin_id;//����Ա��¼�˺� 
    string password;//��¼���� 
    public:
    Admin() = default;
    Admin(string, string);
    string get_password();//�����˻����� 
    Acount* find_userx(map<string,Acount*>& users,string user_id);//���û��������ĳ�û� 
    void create_acount(map<string,Acount*>& users,string,string,string,double,acount_state);//�����û���������û��� 
    void destory_acount(map<string,Acount*>& users, string user_id);//ע�����û����˻�
    bool set_state(map<string,Acount*>& users,string user_id,acount_state state);//ͣ�û����������˻�
    void transfer(map<string,Acount*>& users,string from_id,string to_id,double money);//ִ��ת��
    void deposit(map<string,Acount*>& users,string user_id,double money); //Ϊ�û�ִ�д��
    void withdraw(map<string,Acount*>&users,string user_id,double money);//Ϊ�û�ִ��ȡ��    
    void show_acounts(map<string,Acount*>& users);//��ӡ�����е����������û�
    void show_deals(map<string,Acount*>& users,string user_id); //��ӡĳ�û��Ľ���
    bool set_password(map<string,Acount*>& users,string user_id,string password);//�����û�����
    double get_balance(map<string,Acount*>&users,string user_id);//�����û����
    void change_self_password(string password);  //������������ 
};
#endif
