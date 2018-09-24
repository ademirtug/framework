// framework.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ctime>
#include <time.h>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>



class datetime
{
	struct tm _val;
public:
	datetime()
	{
	}
	datetime(const datetime& dt2)
	{
		this->_val = dt2._val;
	}
	~datetime()
	{
	}


	static datetime now()
	{
		datetime dt;

		time_t now = time(0);
		dt._val = *localtime(&now);

		return dt;
	}

	std::string tostring()
	{
		return tostring("%Y-%m-%dT%H:%M:%SZ");
	}
	std::string tostring(std::string format)
	{
		std::string val;

		char buff[100];
		strftime(buff, 100, format.c_str(), &_val);
		val += buff;
		
		return val;
	}
	datetime operator=(const std::string val)
	{
		datetime dt;


		//
		//std::tm t;
		//std::istringstream ss(val);
		//ss >> std::get_time(dt._tmval, "%Y-%m-%dT%H:");

		return dt;
	}


};


int main()
{


	datetime dt = datetime::now();

	std::cout << dt.tostring();
	
	std::string x = "2018-01-01T09:09:09Z";
	datetime dt2;// = x;
	dt2 = x;

	std::cout << dt2.tostring();

    return 0;
}

