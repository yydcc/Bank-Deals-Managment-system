#ifndef __MYView_controller__
#define __MYView_controller__
#include "Bank.h"
#include "Admin.h"
#include "Acount.h"
#include "global.h"
using std::string;
class View_controller{
    private:
    string tmp_user;	//��ǰ�ĵ�¼�û� 
    string tmp_admin;	//��ǰ�ĵ�¼����Ա
	Bank* bank; //����ͼ_����������Ƶ����ж��� 
	//Ϊ���������г�Աд�ĳ�Ա��������д�����Է���    
	Admin* bank_admin;	// ������ʽ����Ա 
    map<string,Admin*>* admins; // ����Ա�� 
    map<string,Acount*>* users;// �û��� 
    public:
    ~View_controller(); 
    View_controller(Bank* x); //�����и���Ա���ݸ��ö���ĳ�Ա�����ڴ����д 
    void main_menu();//��¼��ʼ���棬ѡ���¼ģʽ���˳�ϵͳ
    void user_login();    //�û���¼����
    void admin_login();     //����Ա��¼����
    void user_menu();   //�û��������
    void admin_menu();  //����Ա�������
    void run();//����չʾ���߼�����������

    //�û�������ʾ�����ƺ���
    void show_ones_information(string);//չʾ������Ϣ 
    void show_balance(string);//չʾ��� 
    void deposit(string);//��� 
    void withdraw(string);//ȡ�� 
    void transfer(string);//ת�� 
    void show_deals(string);//չʾ���׼�¼ 
    void set_password(string);// ��������

    //����Ա������ʾ�����ƺ���
    void create_acount();//���� 
    void set_state();//Ϊ�û�����״̬,"����"��"�쳣" 
    void destory_user();//�����˻� 
    void show_all_users();//չʾ��ǰ�û��������û���Ϣ 
	void show_user();//��ѯ�����û� 
    void show_user_deals();//��ѯ�����û����׼�¼ 
    void set_my_password();//���ù���Ա�������� 
};

#endif
