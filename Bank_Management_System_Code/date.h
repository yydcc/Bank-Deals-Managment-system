#ifndef __MYDATE__
#define __MYDATE__
#include <iostream>
#include <fstream>
using namespace std;
struct date{
	public:
    int year,month,day,hour,minute;
    date() = default;
    date(int year,int month,int day,int hour,int minute);
	date(int dummy); //无意义的参数，根据当前时间初始化 
    ~date()=default;
}; 

//输入输出重载 
ostream& operator << (ostream& os,const date& x);
istream& operator >>(istream& is,date& x);

#endif
