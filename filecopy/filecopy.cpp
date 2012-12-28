// filecopy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define BUFSIZE 1024 * 1024
#define SIZE 1

int _tmain(int argc, _TCHAR* argv[])
{
	TCHAR * name = argv[1];
	printf("File name is %s\n", name);
	HANDLE h = CreateFile(name, GENERIC_WRITE,	0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_NO_BUFFERING | FILE_FLAG_WRITE_THROUGH, NULL);
	if (h == INVALID_HANDLE_VALUE) return -1;
	char buffer[BUFSIZE];
	DWORD dwBytesWritten;
	BOOL fSuccess;
	for (int i = 0; i < SIZE; i++)
	{
		fSuccess = WriteFile(h, &buffer, BUFSIZE, &dwBytesWritten, NULL);
		if (!fSuccess) 
		{
			printf ("WriteFile failed (%d)\n", GetLastError());
			return -1;
		}

	}
	CloseHandle(h);
	return 0;
}


