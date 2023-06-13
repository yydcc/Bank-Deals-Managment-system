#ifndef __MYGLOBAL__
#define __MYGLOBAL__ 

//此文件为全局变量区 

extern const char* users_path;//存储用户表路径 
extern const char* admins_path;//存储管理员表路径 
extern const char* deal_path;//交易文件夹路径 
extern const char* deal_title;//交易信息文件头
 
enum acount_state{disabled = 0,available};//用户状态枚举 
enum deal_type{in = 0,out,depos,withd};//交易类型枚举 
#endif
