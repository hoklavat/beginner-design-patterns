//25-NullObject

#include <iostream>
#include <string>
using namespace std;

struct Log{
	virtual void LogInfo(const string& message) const = 0;
};

struct ConsoleLog: Log{
	void LogInfo(const string& message) const override{
		cout << message << endl;
	}
};

template <typename LogType>
struct PaymentProcessing{
	static_assert(is_base_of<Log, LogType>::value, "LogType must be a Log");

	LogType log;

	void Process(){
		log.LogMessage("Processing payments...");
	}
};

struct NullLog: Log{
	void LogInfo(const string& message) const override {}
};

int main(){
	PaymentProcessing<NullLog> pp;
	getchar();
	
	return 0;
}