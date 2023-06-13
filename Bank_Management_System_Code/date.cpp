#include "date.h"
#include <ctime>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

date::date(int year,int month,int day,int hour,int minute)
:year(year),month(month),day(day),hour(hour),minute(minute){
}

date::date(int dummy){//����ctime���еĺ�����λ��ǰʱ�� 
	time_t my_time =  time(NULL);
    struct tm* my_tm = localtime(&my_time);
    this->year = my_tm->tm_year + 1900;  //���ص���1900������������ 
    this->month = my_tm->tm_mon + 1;//���ص���0~11 
    this->day = my_tm->tm_mday;
    this->hour = my_tm->tm_hour;
    this->minute = my_tm->tm_min;
}
//�����ض���ʽ������� 
ostream& operator << (ostream& os,const date& x){
    os << x.year <<'/' << x.month << '/' <<  x.day << '-'<< x.hour << ':' <<setw(2) <<setfill('0')<< x.minute ;
	return os;
}

istream& operator >>(istream& is,date& x){
    is >> x.year >> x.month >> x.day >> x.hour >> x.minute;
	return is;
} 
