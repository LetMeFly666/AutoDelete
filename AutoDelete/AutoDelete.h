#pragma once
#include <iostream>
#include <Windows.h>
#include <time.h>
using namespace std;

class AutoDelete {
private:
	time_t lastDetectTime;
	string tempFilePath;
	time_t intervalTime;

	void defaultInit();

public:
	AutoDelete();
	AutoDelete(string tempFilePath);
	AutoDelete(time_t intervalTime);
	AutoDelete(string tempFilePaht, time_t intervalTime);
	bool set1delete(string filePath, time_t deleteTime);
};