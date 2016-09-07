// MainFrame.cpp: 
// 

#include "StdAfx.h"
#include "ConsoleOutput.h"
#include "WebConnection.h"

#ifdef _WIN32 // Windows

#include <Windows.h>

#endif // _WIN32

//std::atomic<std::wstring> g_atomReadData;

void threadProc1(CConsoleOutput *const pConsoleOutput)
{
}
void threadProc2(CConsoleOutput *const pConsoleOutput)
{
}

int main()
{
#ifdef _DEBUG

	::_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

#endif // _DEBUG

#ifdef _WIN32 // Windows

	::SetConsoleTitle(L"Web Scanner");

#endif // _WIN32

	std::string oInputInternetAddress;

	CConsoleOutput *pConsoleOutput = CConsoleOutput::create();

	pConsoleOutput->display(L"Enter the internet address you want to connect to: ");

	std::cin >> oInputInternetAddress;

	CWebConnection *pWebConnection = new CWebConnection();
	pWebConnection->create(oInputInternetAddress);

	pWebConnection->wait();

	DELETEPTR_FREE(pWebConnection);

	pConsoleOutput->destroy();

	::system("pause");

	return 0;
}
