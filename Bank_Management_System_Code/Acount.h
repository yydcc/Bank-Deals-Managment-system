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
    string name;//�˻�����
    string user_id;//�û�Ψһ��ʶ
    string card_id;//�����˺�
    string password;//�˻���¼����
    struct date create_time; //��������
    double balance;//���
    acount_state state;//�˻�״̬�Ƿ����
	public:
	Acount() = default;
    Acount(string,string,string,double,acount_state,const date&);
    Acount(string,string,string,string,double,acount_state,const date&);
    string gernerate_card_id(); // ���ݿ���ʱ�估��������������˺�
    void show_information(); // չʾ�˻��������û�Ψһ��ʶ�������˺ţ����������ڣ��˺��Ƿ���õ���Ϣ 
	string get_name();	//��������	 
    string get_user_id();//�����û�id 
    string get_card_id();//���ؿ��� 
    string get_state();//����״̬ 
    double get_balance();//������� 
    string get_password();//�������� 
    bool set_state(acount_state state);//����״̬ 
    struct date& get_create_time();//���ؿ���ʱ�� 
    void set_password(string new_password); //������������
    void transfer_payment(string obj,string obj_name,double money);//ת��
    void transfer_get_payment(string transferor,string transferor_name,double money);//���ܱ��˵�ת��
    void show_deals();//��Ļ��ӡ���׼�¼�� 
    void deposit(double);//���
    void withdraw(double);//ȡ��
    bool add_deal(const deal&);//�������׼�¼ 
};
#endif
