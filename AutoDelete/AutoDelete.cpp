#include "AutoDelete.h"

void AutoDelete::defaultInit() {
	lastDetectTime = time(NULL);
	tempFilePath = ".AutoDelete";
	intervalTime = 300;  // 300s
}

AutoDelete::AutoDelete() {
	defaultInit();
}

AutoDelete::AutoDelete(string tempFilePath) {
	defaultInit();
	this->tempFilePath = tempFilePath;
}

AutoDelete::AutoDelete(time_t intervalTime) {
	defaultInit();
	this->intervalTime = intervalTime;
}

AutoDelete::AutoDelete(string tempFilePath, time_t intervalTime) {
	defaultInit();
	this->tempFilePath = tempFilePath;
	this->intervalTime = intervalTime;
}

bool AutoDelete::set1delete(string filePath, time_t deleteTime) {
	
}