#pragma once

#include <boost/asio.hpp>

class CWebConnection
{
public:
	CWebConnection();
	~CWebConnection();

	bool create(const std::string &refAddress);

	void wait();

protected:
	boost::asio::io_service m_oIOService;

	boost::asio::ip::tcp::socket *m_pSocket;

};