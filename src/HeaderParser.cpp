// HeaderParse.cpp: 
//

#include "../inc/StdAfx.h"

#include <boost/asio.hpp>

#include "../inc/HeaderParser.h"

CHeaderParser::CHeaderParser(const std::ostream &refHeaderStream)
{
	std::string oLineBuffer;

	//if (std::getline(refHeaderStream, oLineBuffer))
	//{

	//}
}

CHeaderParser::CHeaderParser(const boost::asio::streambuf &refStreamBuffer)
{
	//std::istream oInputStream(refStreamBuffer);
}

CHeaderParser::~CHeaderParser()
{

}

bool CHeaderParser::getResponseStatus() const
{
	return true;
}