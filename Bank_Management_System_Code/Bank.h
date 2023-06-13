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
    map<string,Acount*> users;//�û��� 
    map<string,Admin*> admins;//����Ա�� 
    Admin* Bank_admin;//��ʽ����Ա 
    public:
    Bank(); 
    ~Bank();
    bool read_users();//���ļ��ж�ȡ�û���Ϣ���û��� 
    bool read_admins();//���ļ��ж�ȡ����Ա��Ϣ������Ա�� 
    Admin* get_admin();//���ع���Ա  
    map<string,Acount*>* get_users_sheet();//�����û���  
    map<string,Admin*>* get_admins_sheet();//���ع���Ա�� 
    bool save_users();	//���ļ��б����û��� 
    bool save_admins();//���ļ��б������Ա�� 
};
#endif

