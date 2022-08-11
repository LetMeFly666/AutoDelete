#include "AutoDelete.h"

void AutoDelete::defaultInit() {
    #pragma warning(suppress : 4996)
	string exeAbsolutePath = _pgmptr;
	cout << exeAbsolutePath << endl;
	function<int(string&)> getLastSplitLocation = [](string& s) {
		for (int i = int(s.size()); i >= 0; i--) {
			if (s[i] == '\\' || s[i] == '/')
				return i;
		}
		return 0;
	};
	tempFilePath = exeAbsolutePath.substr(0, getLastSplitLocation(exeAbsolutePath)) + "\\.AutoDelete";
	intervalTime = 300;  // 300s
}

AutoDelete::AutoDelete() {
	defaultInit();
	run();
}

AutoDelete::AutoDelete(string tempFilePath) {
	defaultInit();
	this->tempFilePath = tempFilePath;
	run();
}

AutoDelete::AutoDelete(time_t intervalTime) {
	defaultInit();
	this->intervalTime = intervalTime;
	run();
}

AutoDelete::AutoDelete(string tempFilePath, time_t intervalTime) {
	defaultInit();
	this->tempFilePath = tempFilePath;
	this->intervalTime = intervalTime;
	run();
}

void AutoDelete::run() {
	while (true) {
		execute();
		Sleep(intervalTime * 1000);
	}
}

void AutoDelete::execute() {
	cout << "Execute!" << endl;
	static bool firstExecute = true;

	if (firstExecute) {
		firstExecute = false;
		cout << "Inspect if dir exists." << endl;

		//function<LPCWSTR(string)> string2LPCWSTR = [](string s) {
//	CString str = CString(s.c_str());
//	USES_CONVERSION;
//	LPCWSTR lpcwstr = A2CW(W2A(str));
//	str.ReleaseBuffer();
//	return lpcwstr;
//};

		function<void(string)> make1fileIfNotExists = [](string fileName) {
			fstream fs;
			fs.open(fileName, ios::in);
			if (!fs) {
				cout << "Creating " << fileName << endl;
				ofstream ostr(fileName, ios::out);
				if (!ostr) {
					cout << "Creating '" << fileName << "' Failed!" << endl;
					ostr.close();
					exit(-1);
				}
				ostr.close();
			}
			fs.close();
		};

		function<void(string)> create1directoryIfNotExists = [](string path) {
			CString tempCString;
			LPCWSTR Lpath;
			string2LPCWSTR(path, Lpath, tempCString);
			CreateDirectory(Lpath, NULL);
		};
		
		create1directoryIfNotExists(tempFilePath);
		create1directoryIfNotExists(tempFilePath + "\\.LetMeFly");
		
		make1fileIfNotExists(tempFilePath + "\\.LetMeFly\\todo.TFad");
		make1fileIfNotExists(tempFilePath + "\\.LetMeFly\\already.TFad");
	}
	
}