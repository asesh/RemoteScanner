#pragma once

// CConsoleOutput class
// Singleton class
class CConsoleOutput
{
public: // Public methods
	static CConsoleOutput *create();
	//static CConsoleOutput *get();
	void destroy();

	void display(const std::wstring &refOutputString);

	// Deleted member functions
	CConsoleOutput(const CConsoleOutput &refConsoleOutput) = delete;
	CConsoleOutput operator=(CConsoleOutput) = delete;


protected:
	std::mutex m_oOutputMutex;

protected: // Protected methods

	CConsoleOutput();
	~CConsoleOutput();
};
