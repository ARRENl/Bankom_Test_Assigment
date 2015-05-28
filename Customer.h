#ifndef Customer_h
#define Customer_h

#include <Windows.h>
#include <cstdio>
#include <iostream>

namespace TestApp
{
	#define MAX_CLIENT_ID_SIZE 9 // MAX_CLIENT_ID_SIZE % 2 = must be 0 always
	#define MAX_CLIENT_DATA_SIZE 255

	class Customer
	{
	protected:
		DWORD c_timestamp;
		char c_client_id[MAX_CLIENT_ID_SIZE];
		BYTE c_priority;
		char* c_client_data;

		//METHODS
		void setClientID(char* str);
		BYTE setClientPriority();
		void setClientData(char* str);
		char* getHexString(const int characters_number);

	public:
		Customer();
		virtual ~Customer();
		char* getClientID();
		BYTE getClientPriority();
		const char* getClientData();
		DWORD getTimeStamp();
	};
}

#endif