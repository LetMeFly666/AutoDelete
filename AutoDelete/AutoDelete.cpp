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
	cout << "Executing..." << endl;
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
	
	ifstream istr(tempFilePath + "\\.LetMeFly\\todo.TFad", ios::in);
	if (!istr) {
		cout << "Error! Cannot open file '" << tempFilePath << "\\.LetMeFly\\todo.TFad'" << endl;
		return;
	}
	string line;
	int lineNum = 0;
	vector<string> remain;
	vector<string> toAlready;
	while (getline(istr, line)) {
		lineNum++;
		if (line.empty())
			continue;
		string filePath, timeStamp;
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == '?') {
				filePath = line.substr(0, i);
				timeStamp = line.substr(i + 1, line.size() - i - 1);
			}
		}
		if (filePath.empty() || timeStamp.empty()) {
			cout << "Data in line #" << lineNum << " '" << line << "' is corrupted!" << endl;
			return;
		}
		cout << filePath << " : " << timeStamp << endl;
		if (timeStamp.size() != 10) {
			cout << "The length of the timestamp should be 10, but '" << timeStamp << "' isn't." << endl;
		}
		time_t realTimeStamp = 0;
		for (char& c : timeStamp) {
			if (c >= '0' && c <= '9')
				realTimeStamp *= 10, realTimeStamp += c - '0';
			else {
				cout << timeStamp << " contain a char which isn't a number." << endl;
				return;
			}
		}
		if (realTimeStamp < time(NULL)) {
			cout << "Delete file '" << filePath << "' " << endl;
			string cmd = "del " + filePath;
			system(cmd.c_str());
			toAlready.push_back(line);
		}
		else {
			remain.push_back(line);
		}
	}
	istr.close();

	function<bool(string, vector<string>, _Iosb<int>::_Openmode)> keep1file = [](string filePath, vector<string> toWrite, _Iosb<int>::_Openmode keepMode) {
		ofstream ostr(filePath, keepMode);
		if (!ostr) {
			cout << "Writing in file '" << filePath << "' failed." << endl;
			return false;
		}
		for (string& s : toWrite) {
			ostr << s << endl;
		}
		ostr.close();
		return true;
	};

	if (!keep1file(tempFilePath + "\\.LetMeFly\\todo.TFad", remain, ios::out)) {
		return;
	}
	if (!keep1file(tempFilePath + "\\.LetMeFly\\already.TFad", toAlready, ios::app)) {
		return;
	}

	cout << "End of the execution." << endl;
}