//#include <windows.h>
//#include <stdio.h>

#include "Customer.h"

namespace TestApp
{
	Customer::Customer()
	{
		c_timestamp = GetTickCount();
		setClientID(c_client_id);
		c_priority = setClientPriority();
		setClientData(c_client_data);
	}

	Customer::~Customer()
	{
		delete c_client_id;
		delete c_client_data;
	}

	void Customer::setClientID(char* str)
	{
		unsigned char STR_LEN = MAX_CLIENT_ID_SIZE - 1;
		int i;
		for (i = 0; i < STR_LEN; i += 2)
		{
			sprintf(str + i, "%02X", rand() % 16);
		}
		str[i] = '\0';
	}
	BYTE Customer::setClientPriority()
	{
		return static_cast<BYTE>(rand() % 256);
	}
	void Customer::setClientData(char* str)
	{
		str = new char[MAX_CLIENT_DATA_SIZE];
		unsigned char STR_LEN = sizeof(*str) + 1;
		int i;
		for (i = 0; i < STR_LEN; i += 2)
		{
			sprintf(str + i, "%02X", rand() % 16);
		}
		str[i] = '\0';
	}
	char* Customer::getHexString(const int characters_number)
	{
		char *str = new char[characters_number];
		unsigned char STR_LEN = sizeof(*str) + 1;
		int i;
		for (i = 0; i < STR_LEN; i += 2)
		{
			sprintf(str + i, "%02X", rand() % 16);
		}
		str[i] = '\0';

		return str;
	}
	char* Customer::getClientID()
	{
		return c_client_id;
	}
	BYTE Customer::getClientPriority()
	{
		return this->c_priority;
	}
	DWORD Customer::getTimeStamp()
	{
		return this->c_timestamp;
	}
}
