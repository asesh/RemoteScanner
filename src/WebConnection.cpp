//
//

#include "StdAfx.h"

#define _WIN32_WINNT 0x0501

//#include <WinSock2.h>
//#include <boost/asio.hpp>

#include "WebConnection.h"

#ifdef _MSC_VER

#include <Windows.h>

#endif // _MSC_VER

//----------------------------------------------------------------------
// Name: CWebConnection
// Desc: Default constructor
//----------------------------------------------------------------------
CWebConnection::CWebConnection()
{
	m_pSocket = new boost::asio::ip::tcp::socket(m_oIOService);
}

//----------------------------------------------------------------------
// Name: ~CWebConnection
// Desc: Destructor
//----------------------------------------------------------------------
CWebConnection::~CWebConnection()
{
	DELETEPTR_FREE(m_pSocket);
}

//----------------------------------------------------------------------
// Name: create
// Desc: Create a connection to the specific site
//----------------------------------------------------------------------
bool CWebConnection::create(const std::string &refAddress)
{
	std::string oHostAddress, oSubAddress, oProtocol = "http";

	size_t stProtocolOffset = refAddress.find("//");
	if (stProtocolOffset != std::string::npos)
	{
		oProtocol = refAddress.substr(0, stProtocolOffset - 1);
	}

	size_t stOffset = refAddress.find('/');
	if (stOffset != std::string::npos)
	{
		oHostAddress = refAddress.substr(0, stOffset);
		oSubAddress = refAddress.substr(stOffset);
	}
	else
		oHostAddress = refAddress;

	boost::asio::ip::tcp::resolver oResolver(m_oIOService);
	
	boost::asio::ip::tcp::resolver::query oQuery(oHostAddress, oProtocol);

	boost::asio::ip::tcp::resolver::iterator itEndPoints;

	try
	{
		itEndPoints = oResolver.resolve(oQuery);
	}
	catch (boost::system::system_error &refSystemError)
	{
		std::cerr << "Error: Retrieving the IP address of the specified host. Are you connected to the internet or is the address valid?" << std::endl;

		return false;
	}

	boost::asio::ip::tcp::endpoint oEndPoint = *itEndPoints;

	std::cout << "Connecting to the specified host: " << oEndPoint << std::endl;

	try
	{
		m_pSocket->connect(oEndPoint);

	}
	catch (boost::system::system_error &refSystemError)
	{
		std::cerr << "Error connecting to the specified endpoint: " << refSystemError.what() << std::endl;

		return false;
	}

	std::cout << "Connected to the specified host" << std::endl;

	std::cout << "Sending request to retrieve header data" << std::endl;

	// Form the request
	boost::asio::streambuf oRequestBUff;
	std::ostream oRequestStream(&oRequestBUff);
	oRequestStream << "GET "<< oSubAddress <<" HTTP/1.1\r\n"
		<< "Connection: Close\r\n"
		<< "Host: "<< oHostAddress << "\r\n\r\n";
	size_t stBytesSent = boost::asio::write(*m_pSocket, oRequestBUff);

	// Read the response code
	boost::asio::streambuf oHeaderBuff;
	std::ostream oRetrievedDataStream(&oHeaderBuff);
	boost::system::error_code oErrorCode;
	boost::asio::read_until(*m_pSocket, oHeaderBuff, "\r\n");

	// Output the retrieved header data
	std::cout << &oHeaderBuff << std::endl;

	// Check the header
	int nSuccessCode;
	std::string oHttpVersion;
	std::istream oResponseStream(&oHeaderBuff);

	oResponseStream >> oHttpVersion>>nSuccessCode;

	//std::getline(oResponseStream, oHttpVersion);

	m_pSocket->close();

	return true;
}

//----------------------------------------------------------------------
// Name: wait
// Desc: waits for the operations to complete
//----------------------------------------------------------------------
void CWebConnection::wait()
{

}