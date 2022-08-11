#pragma once
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <atlstr.h>  // char -> LPCWSTR
#include <functional>  // function<int(string&)>
#include <fstream>
using namespace std;

#define string2LPCWSTR(stringS, LPCWSTRS, CStringTempS) \
	CStringTempS = CString(stringS.c_str());\
	USES_CONVERSION;\
	LPCWSTRS = A2CW(W2A(CStringTempS));\
	CStringTempS.ReleaseBuffer();\

class AutoDelete {  // 一直运行，待删除文件保存在tempFilePath，每隔intervalTime秒执行一次删除操作
private:
	string tempFilePath;
	time_t intervalTime;

	void defaultInit();

	void run();  // 一直运行，每隔intervalTime时间执行一次

	void execute();  // 真正执行函数，被调用后立即执行

public:
	AutoDelete();
	AutoDelete(string tempFilePath);
	AutoDelete(time_t intervalTime);
	AutoDelete(string tempFilePath, time_t intervalTime);
};

class SetDelete {

};