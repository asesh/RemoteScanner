//
//

#include "StdAfx.h"

#include "ConsoleOutput.h"

CConsoleOutput *CConsoleOutput::create()
{
	CConsoleOutput *pConsoleOutput = new CConsoleOutput();
	if (pConsoleOutput == nullptr)
		return nullptr;

	return pConsoleOutput;
}

//CConsoleOutput *CConsoleOutput::get()
//{
//	return 
//}

void CConsoleOutput::destroy()
{
	DELETEPTR(this);
}

void CConsoleOutput::display(const std::wstring &refOutputString)
{
	std::lock_guard<std::mutex> oLocalDisplayMutex(m_oOutputMutex);

	std::wcout << refOutputString.data() << std::endl;

}

CConsoleOutput::CConsoleOutput()
{


}

CConsoleOutput::~CConsoleOutput()
{

}
