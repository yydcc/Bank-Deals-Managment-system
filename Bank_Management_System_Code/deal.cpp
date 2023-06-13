#include "deal.h"
#include <string>
using namespace std;
deal::deal(deal_type type,string obj,string obj_name,double money,const date& time)
:type(type),obj(obj),obj_name(obj_name),money(money),time(time){} 

//根据枚举类型确定交易类型 
string deal::get_type()const{
    if(type == in) return "转入";
    else if(type == out) return "转出";
    else if(type == depos) return "存款";
    else if(type == withd) return "取款";
}
