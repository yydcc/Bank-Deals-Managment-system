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
	date(int dummy); //������Ĳ��������ݵ�ǰʱ���ʼ�� 
    ~date()=default;
}; 

//����������� 
ostream& operator << (ostream& os,const date& x);
istream& operator >>(istream& is,date& x);

#endif
