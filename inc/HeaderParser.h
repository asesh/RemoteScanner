#pragma once

class CHeaderParser
{
public:
	CHeaderParser(const std::ostream &refHeaderStream);
	CHeaderParser(const boost::asio::streambuf &refHeaderStreamBuffer);
	~CHeaderParser();

	bool getResponseStatus() const;

private:
};