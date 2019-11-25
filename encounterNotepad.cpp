#include <thread>
#include <windows.h>        
using namespace std;

int main()
{
	system("tasklist | find /i \"notepad.exe\" && taskkill /im notepad.exe /F || echo process \"notepad.exe\" not found in the list of running process!");

  return 0;
}




