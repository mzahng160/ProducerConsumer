// ProducerConsumer.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "myRingQueue.h"
#include <windows.h>
#include <iostream> 

using namespace std;

const int g_Number = 5;
DWORD WINAPI ThreadProc1(__in  LPVOID lpParameter);
DWORD WINAPI ThreadProc2(__in  LPVOID lpParameter);
DWORD WINAPI ThreadProc3(__in  LPVOID lpParameter);
DWORD WINAPI ThreadProc4(__in  LPVOID lpParameter);
DWORD WINAPI ThreadProc5(__in  LPVOID lpParameter);

HANDLE hSemp1, hSemp2, hSemp3;



void ProducerPut(myRingQueue *q, int element)
{
	if (q->QueueFull())
	{
		WaitForSingleObject(hSemp2, INFINITE);//等待信号量
	}
	else
	{
		q->EnQueue(element);
		ReleaseSemaphore(hSemp2, 1, NULL);//释放信号量 
	}
	
}

void ConsumerGet(myRingQueue *q, int& element)
{
	if (q->QueueEmpty())
	{
		WaitForSingleObject(hSemp2, INFINITE);//等待信号量
	}
	else
	{
		q->DeQueue(element);
		ReleaseSemaphore(hSemp2, 1, NULL);//释放信号量 
	}

	
}

int main()
{
	myRingQueue *q = new myRingQueue(10);

	hSemp1 = CreateSemaphore(NULL, 1, 1, NULL);
	hSemp2 = CreateSemaphore(NULL, 1, 1, NULL);
	//hSemp3 = CreateSemaphore(NULL, 1, 1, NULL);

	HANDLE hThread[g_Number] = { 0 };
	int first = 1, second = 2, third = 3;
	hThread[0] = CreateThread(NULL, 0, ThreadProc1, (LPVOID)first, 0, NULL);
	hThread[1] = CreateThread(NULL, 0, ThreadProc2, (LPVOID)second, 0, NULL);
	hThread[2] = CreateThread(NULL, 0, ThreadProc3, (LPVOID)third, 0, NULL);

	hThread[3] = CreateThread(NULL, 0, ThreadProc4, q, 0, NULL);
	hThread[4] = CreateThread(NULL, 0, ThreadProc5, q, 0, NULL);

	WaitForMultipleObjects(g_Number, hThread, TRUE, INFINITE);
	CloseHandle(hThread[0]);
	CloseHandle(hThread[1]);
	CloseHandle(hThread[2]);

	CloseHandle(hSemp1);
	CloseHandle(hSemp2);
	//CloseHandle(hSemp3);

	delete q;
	q = NULL;
	return 0;
}

DWORD WINAPI ThreadProc1(__in  LPVOID lpParameter)
{
	WaitForSingleObject(hSemp1, INFINITE);//等待信号量 
	cout << (int)lpParameter << endl;
	ReleaseSemaphore(hSemp1, 1, NULL);//释放信号量 
	return 0;
}

DWORD WINAPI ThreadProc2(__in  LPVOID lpParameter)
{
	WaitForSingleObject(hSemp1, INFINITE);//等待信号量 
	cout << (int)lpParameter << endl;
	ReleaseSemaphore(hSemp1, 1, NULL);//释放信号量 
	return 0;
}

DWORD WINAPI ThreadProc3(__in  LPVOID lpParameter)
{
	WaitForSingleObject(hSemp1, INFINITE);//等待信号量 
	cout << (int)lpParameter << endl;
	ReleaseSemaphore(hSemp1, 1, NULL);//释放信号量 
	return 0;
}

DWORD WINAPI ThreadProc4(__in  LPVOID lpParameter)
{
	while (1)
	{
		int i = 0;
		ConsumerGet((myRingQueue *)lpParameter, i);
		cout << "ConsumerGet " << i << endl;
		Sleep(1000);
	}
	return 0;
}

DWORD WINAPI ThreadProc5(__in  LPVOID lpParameter)
{
	while (1)
	{
		myRingQueue * q = (myRingQueue *)lpParameter;
		ProducerPut((myRingQueue *)lpParameter, 1);
		q->QueueTraverse();
		Sleep(1000);
	}

	return 0;
}

