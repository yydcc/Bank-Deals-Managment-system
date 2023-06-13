#include "deal.h"
#include <string>
using namespace std;
deal::deal(deal_type type,string obj,string obj_name,double money,const date& time)
:type(type),obj(obj),obj_name(obj_name),money(money),time(time){} 

//����ö������ȷ���������� 
string deal::get_type()const{
    if(type == in) return "ת��";
    else if(type == out) return "ת��";
    else if(type == depos) return "���";
    else if(type == withd) return "ȡ��";
}
