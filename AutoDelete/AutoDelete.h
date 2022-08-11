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

class AutoDelete {  // һֱ���У���ɾ���ļ�������tempFilePath��ÿ��intervalTime��ִ��һ��ɾ������
private:
	string tempFilePath;
	time_t intervalTime;

	void defaultInit();

	void run();  // һֱ���У�ÿ��intervalTimeʱ��ִ��һ��

	void execute();  // ����ִ�к����������ú�����ִ��

public:
	AutoDelete();
	AutoDelete(string tempFilePath);
	AutoDelete(time_t intervalTime);
	AutoDelete(string tempFilePath, time_t intervalTime);
};

class SetDelete {

};