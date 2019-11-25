#include <thread>        
#include <chrono>
using namespace std;

int main()
{
	clock_t begin = clock();
	system("start notepad.exe ");

	system("tasklist /v /fi \"imagename EQ Notepad.exe\" /FO LIST | FIND \"PID:\"");

    	std:this_thread::sleep_for(std::chrono::seconds(3));
	clock_t end = clock();

	system("Taskkill /IM Notepad.exe /F");

	return 0;
}
