#ifndef __MYDEAL__
#define __MYDEAL__
#include  "global.h"
#include "date.h"
struct date;

struct deal{
	deal_type type;//�������ͣ�����or֧��or���orȡ��
    double money;//ת�˽��
    string obj;//ת�ʶ����ת���˵�user_id 
    string obj_name;//ת�˶����ת��������������ʾ
    struct date time;//ת��ʱ��
    deal() = default;
    deal(deal_type type,string obj ,string obj_name,double money,const date& time);
    string get_type()const;
};

#endif 
