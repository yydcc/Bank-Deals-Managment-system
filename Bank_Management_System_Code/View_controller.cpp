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
    cout << "\t\t~~��л����ʹ�ã���ӭ�´�����~~" << "\n";
    system("pause");
}
void View_controller::main_menu(){
	system("cls");
    system("color F5");
    cout << "\t\t~~��ӭ�������н��׹���ϵͳ~~\t\t" << endl;
    cout << "\t\t   -------------------------   " << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|      ~~��ѡ���¼ģʽ~~     |" << endl;
	cout << "\t\t|                             |" << endl;
    cout << "\t\t|          1.����             |" << endl;
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|          2.����Ա           |" << endl; 
    cout << "\t\t|                             |" << endl;
    cout << "\t\t|          0.�˳�ϵͳ         |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t-------------------------------" << endl;
}

void View_controller::user_login(){
    cout << "\t\t�𾴵��û�,�����������˺�������" << endl;
    string user_id;
    string password;
    int time = 3;
    bool flg = false;
    while(!flg && time--){
        cin >> user_id >> password;
        auto it = bank_admin->find_userx(*users,user_id);
        if(it == nullptr) {
            cout << "\t\t\t�����ڸ��˺ţ�����������" << endl;
            continue;
        }
        else if(it->get_password() != password){
            cout << "\t\t�˻���������������,����������" << endl;
            continue;
        }
        tmp_user = user_id;
        flg = true;
    }
    if(flg){
    	cout << "\t\t~~��¼�ɹ�~~" << endl;
		system("pause");
        user_menu();        
    } 
    else {
        cout << "\t\t���Ѿ����������������,��Ϊ���Զ��˳�ϵͳ"<< endl;
        exit(0);
    }
}

void View_controller::admin_login(){
    cout << "\t\t�𾴵Ĺ���Ա,�����������˺�������" << endl;
    string admin_id;
    string password;
    int time = 3;
    bool flg = false;
    while(!flg && time--){
        cin >> admin_id >> password;
        auto it = admins->find(admin_id);
        if(it == admins->end()) {
            cout << "\t\t\t�����ڸ��˺�,����������" << endl;
            continue;
        }
        else if(it->second->get_password() != password){
            cout << "\t\t�˻���������������,����������" << endl;
            continue;
        }
        tmp_admin = admin_id;
        flg = true;
    }
    if(flg){
    	cout << "\t\t~~��¼�ɹ�~~" << endl;
		system("pause"); 
        admin_menu(); 
    } 
    else {
        cout << "\t\t���Ѿ����������������,��Ϊ���Զ��˳�ϵͳ"<< endl;
        exit(0);
    }
}

void View_controller::user_menu(){
	bool flg = true;
	while(flg){
	system("cls");
   	cout << "\t\t         ���н��׹���ϵͳ        " << endl; 
    cout << "\t\t  -----------------------------  " << endl; 
	cout << "\t\t|                               |" << endl;
	cout << "\t\t|         1.չʾ������Ϣ        |" << endl;
    cout << "\t\t|         2.����ѯ            |" << endl;
    cout << "\t\t|         3.���                |" << endl;
    cout << "\t\t|         4.ȡ��                |" << endl;
    cout << "\t\t|         5.ת��                |" << endl;
    cout << "\t\t|         6.��ѯ���׼�¼        |" << endl;
    cout << "\t\t|         7.�޸�����            |" << endl;
    cout << "\t\t|         0.������һ��          |" << endl;
    cout << "\t\t---------------------------------" << endl;
    cout << "\t\t~~��������Ҫ���еĲ���~~(0~7):"    <<endl;
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
        cout << "\t\t��������,����������" << endl;
        system("pause");
	}
    }   
}

void View_controller::admin_menu(){
		bool flg = true;
	 	while(flg){
	 	system("cls");
		cout << "\t\t         ���н��׹���ϵͳ        " << endl; 
	    cout << "\t\t  -----------------------------  " << endl; 
	    cout << "\t\t|         1.����                |" << endl;
	    cout << "\t\t|         2.�����û�״̬        |" << endl;
	    cout << "\t\t|         3.ɾ���û�            |" << endl;
	    cout << "\t\t|         4.��ѯ�û���Ϣ        |" << endl;
	    cout << "\t\t|         5.��ѯ�û����׼�¼    |" << endl;
        cout << "\t\t|         6.��ѯ�����û���Ϣ    |" << endl;
	    cout << "\t\t|         7.�޸Ĺ���Ա����      |" << endl;
	    cout << "\t\t|         0.������һ��          |" << endl;
		cout << "\t\t---------------------------------" << endl;
    	cout << "\t\t~~��������Ҫ���еĲ���~~(0~7):"    <<endl;
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
        cout << "\t\t��������,����������" << endl;
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
            cout << "\t\t��������,����������" << endl;
            system("pause");
        }
    }

}


void View_controller::show_balance(string user_id){
    auto it = this->bank_admin->find_userx(*users,user_id);
    cout << "\t\t�û�" << it->get_name() <<"���˻�" << it->get_card_id() << "���Ϊ" <<fixed << setprecision(2)<<it->get_balance() << "Ԫ" << endl;
    system("pause");
}

void View_controller::show_ones_information(string user_id){
    auto it = bank_admin->find_userx(*users,user_id);
    it->show_information();
    system("pause");
}

void View_controller::deposit(string user_id){
    auto it = bank_admin->find_userx(*users,user_id);
    if(it->get_state() == "�쳣") {
        cout << "\t\t�˻��쳣���޷����" << endl;
        system("pause");
        return;
    }
    cout << "\t\t��������Ҫ���Ľ��(Ԫ) "<< endl;
    double money;
    cin >> money;
    if(money <= 0){
		cout << "\t\t��������������һ������" << endl;
		system("pause");
		return;
	}
    bank_admin->deposit(*users,user_id,money);
    cout << "\t\t~~���ɹ�~~"<< endl;
    system("pause");
}

void View_controller::withdraw(string user_id){
	auto it = bank_admin->find_userx(*users,user_id);
    if(it->get_state() == "�쳣") {
        cout << "\t\t�˻��쳣���޷�ȡ��" << endl;
        system("pause");
        return;
    }
    cout << "\t\t��������Ҫȡ��Ľ��(Ԫ)"<< endl;
    double money;
    cin >> money;
    if(money <= 0){
		cout << "\t\t��������������һ������" << endl;
		system("pause");
		return;
	}
    if(it->get_balance() < money){
        cout << "\t\t����,ȡ��ʧ��" << endl;
        system("pause"); 
        return;
    } 
    bank_admin->withdraw(*users,user_id,money);
    cout << "\t\t~~ȡ��ɹ�~~" << endl;
    system("pause");
}

void View_controller::transfer(string user_id){
    auto it = bank_admin->find_userx(*users,user_id);
    if(it->get_state() == "�쳣") {
        cout << "\t\t�˻��쳣���޷�ת��" << endl;
        system("pause");
        return;
    }
    string to_id,name;
    double money;
    cout << "\t\t�������տ���id"<< endl;
    cin >> to_id;
    auto to = bank_admin->find_userx(*users,to_id);
    if(to == nullptr) {
        cout << "\t\t�����ڸ��û�,����ʧ��"<< endl;
        system("pause");
        return;
    }
    cout << "\t\t�������տ�������"<<endl;
    cin >> name;
    if(to->get_name()!=name){
        cout << "\t\t�տ���id��������ƥ��,ת��ʧ��"<<endl;
        system("pause");
        return;
    }
    cout << "\t\t������ת�˽��" << endl;
    cin >> money;
    auto from = bank_admin->find_userx(*users,user_id);
    if(money <= 0){
		cout << "\t\t��������������һ������" << endl;
		cout << "\t\tת��ʧ��" << endl;
		system("pause");
		return;
	}
    if(money > from->get_balance()){
        cout << "\t\t����,ת��ʧ��"<< endl;
        system("pause");
        return;
    }
    bank_admin->transfer(*users,user_id,to_id,money);
    cout << "\t\t~~ת�˳ɹ�" << endl;
	system("pause");
}

void View_controller::show_deals(string user_id){
    bank_admin->show_deals(*users,user_id);
    system("pause");
}

void View_controller::set_password(string user_id){
    auto it = bank_admin->find_userx(*users,user_id);
    if(it->get_state() == "�쳣") {
        cout << "\t\t�˻��쳣���޷���������" << endl;
        system("pause");
        return;
    }
    string new_password;
    cout << "\t\t��������Ҫ���ĵ�����" << endl;
    cin >> new_password;
    bank_admin->set_password(*users,user_id,new_password);
    cout << "\t\t~~�ɹ���������~~"<< endl;
    system("pause");
}

void View_controller::create_acount(){
    string user_id;
    string name;
    string password;
    double money;
    cout << "\t\t�����뿪���˵�id"<< endl;
    cin >> user_id;
    cout << "\t\t�����뿪��������"<< endl;
    cin >> name;
    cout << "\t\t�������˻�����" << endl;
    cin >> password;
    cout << "\t\t�����뿪�����"<< endl;
    cin >> money;
    if(money <= 0){
		cout << "\t\t��������������һ������" << endl;
		cout << "\t\t����ʧ��" << endl; 
		system("pause");
		return;
	}
    bank_admin->create_acount(*users,name,user_id,password,money,available);
    cout << "\t\t~~�˻������ɹ�" << endl;
    system("pause");
}

void View_controller::set_state(){
    cout << "\t\t��������Ҫ����״̬���û�id"<< endl;
    string user_id;
    cin >> user_id;
    auto it = bank_admin->find_userx(*users,user_id);
    if(it == nullptr) {
        cout << "\t\t�����ڸ��û�,��������"<<endl;
        system("pause");
        return;
    }
    it->show_information();
    int option;
    if(it->get_state() == "����"){
        cout << "\t\t��ǰ�˻�״̬����,�Ƿ�Ϊ�����ø��˻�" << endl;
        cout << "\t\t\t1.��" << endl << "\t\t\t2.��" << endl;
        cin >> option;
        if(option == 1){  
		 it->set_state(disabled);
		}
        else if(option == 2){

        }
        else {
            cout  << "\t\t��������,����ʧ��" << endl;
            system("pause");
            return;
        }
    }
    else if(it->get_state() == "�쳣"){
         cout << "\t\t��ǰ�˻�״̬�쳣,�Ƿ�Ϊ�����ø��˻�" << endl;
        cout << "\t\t\t1.��" << endl << "\t\t\t2.��" << endl;
        cin >> option;
        if(option == 1){
            it->set_state(available);
        }
        else if(option == 2){}
        else {
            cout << "\t\t��������,����ʧ��"<<endl;
       		system("pause");
       		return;
	    }
        
    }
    system("pause");
}

void View_controller::destory_user(){
    cout << "\t\t��������Ҫ���ٵ��û�id"<< endl;
    string user_id;
    cin >> user_id;
    auto it = bank_admin->find_userx(*users,user_id);
    if(it == nullptr){
        cout << "\t\t�����ڸ��û�,����ʧ��"<< endl;
        system("pause");
        return;
    }
    it->show_information();
    cout << "\t\t�Ƿ�Ϊ�����ٸ��˻�"<< endl;
    cout << "\t\t\t1.��"<< endl;
    cout << "\t\t\t2.��" << endl;
    int option;
    cin >> option;
    if(option == 1){
        bank_admin->destory_acount(*users,user_id);
        cout << "\t\t\t~~���ٳɹ�"<< endl;
        system("pause");
        return;
    }
    else if(option == 2){
        return;
    }
    else {
        cout << "\t\t��������,����ʧ��"<< endl;
        system("pause");
        return; 
    }
    system("pause");
}

void View_controller::show_user(){
    cout << "\t\t��������Ҫ��ѯ���û�id"<< endl;
    string user_id;
    cin >> user_id;
    auto it = bank_admin->find_userx(*users,user_id);
    if(it == nullptr){
        cout << "\t\t�����ڸ��û�,����ʧ��" << endl;
        system("pause");
        return;
    }
    it->show_information();
    system("pause");
}

void View_controller::show_user_deals(){
    cout << "\t\t��������Ҫ��ѯ���û�id"<< endl;
    string user_id;
    cin >> user_id;
    auto it = bank_admin->find_userx(*users,user_id);
    if(it == nullptr){
        cout << "\t\t�����ڸ��û�,����ʧ��" << endl;
        system("pause");
        return;
    }
    it->show_deals();
    system("pause");
}

void View_controller::set_my_password(){
    string password;
    cout << "\t\t������������ "<<endl;
    cin >> password;
  	auto it = admins->find(tmp_admin);
  	it->second->change_self_password(password);
  	cout << "\t\t~~�����޸ĳɹ�~~" << endl; 
    system("pause");
}

void View_controller::show_all_users(){
    if(users->empty()) {
        cout << "\t\t��ǰ�û���Ϊ��,����Ϣ�ɲ�ѯ" << endl;
        system("pause"); 
        return; 
    }
    cout << "\t\t���е�ǰ����" << users->size() << "���û�" << endl; 
    cout << "\t\t���е�ǰ�����û���Ϣ���±�" << endl;
    bank_admin->show_acounts(*users);
    system("pause"); 
}

