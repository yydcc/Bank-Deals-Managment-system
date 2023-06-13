#include "date.h"
#include <ctime>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

date::date(int year,int month,int day,int hour,int minute)
:year(year),month(month),day(day),hour(hour),minute(minute){
}

date::date(int dummy){//利用ctime库中的函数定位当前时间 
	time_t my_time =  time(NULL);
    struct tm* my_tm = localtime(&my_time);
    this->year = my_tm->tm_year + 1900;  //返回的是1900到现在相差年份 
    this->month = my_tm->tm_mon + 1;//返回的是0~11 
    this->day = my_tm->tm_mday;
    this->hour = my_tm->tm_hour;
    this->minute = my_tm->tm_min;
}
//按照特定格式输出日期 
ostream& operator << (ostream& os,const date& x){
    os << x.year <<'/' << x.month << '/' <<  x.day << '-'<< x.hour << ':' <<setw(2) <<setfill('0')<< x.minute ;
	return os;
}

istream& operator >>(istream& is,date& x){
    is >> x.year >> x.month >> x.day >> x.hour >> x.minute;
	return is;
} 
