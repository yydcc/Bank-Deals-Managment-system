#ifndef __MYDEAL__
#define __MYDEAL__
#include  "global.h"
#include "date.h"
struct date;

struct deal{
	deal_type type;//交易类型，收入or支出or存款or取款
    double money;//转账金额
    string obj;//转帐对象或转账人的user_id 
    string obj_name;//转账对象或转账姓名，用于显示
    struct date time;//转账时间
    deal() = default;
    deal(deal_type type,string obj ,string obj_name,double money,const date& time);
    string get_type()const;
};

#endif 
