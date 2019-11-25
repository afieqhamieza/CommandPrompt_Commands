#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

BOOL TerminateMyProcess(DWORD dwProcessId, UINT uExitCode)
{
	DWORD dwDesiredAccess = PROCESS_TERMINATE;
	BOOL  bInheritHandle = FALSE;
	HANDLE hProcess = OpenProcess(dwDesiredAccess, bInheritHandle, dwProcessId);

	if (hProcess == NULL)
		return FALSE;

	BOOL result = TerminateProcess(hProcess, uExitCode);

	CloseHandle(hProcess);

	return result;
}

int main()
{
	int choice=2;

	while (choice == 2)
	{
		cout << "Using more than 200k: " << endl;
		system("tasklist /fi \"MEMUSAGE gt 200\"");

		cout << "\n\nusing more than 3 minutes: " << endl;
		system("tasklist /fi \"CPUTIME gt 00:03:00\"");

		cout << "\n\n\n1 - kill a process\n"
			   << "2 - refresh\n"
			   << "0 - exit\n"
			   << "enter a choice: ";
		cin  >> choice;

		if (choice == 1)
		{
			DWORD pid_in;

			cout << "Enter the PID: ";
			cin  >> pid_in;

			TerminateMyProcess(pid_in, 1);

			cout << "1 - kill a process\n"
				   << "2 - refresh\n"
				   << "0 - exit\n"
				   << "enter a choice: ";
			cin  >> choice;
		}
		else if (choice == 2)
			continue;
		else
			exit(1);
	}

	return 0;
}


