// framework.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "datetime.h"
#include <ctime>
#include <time.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <windows.h>
#include <WinInet.h>
#include <vector>

using namespace std;

class http_client
{
	HINTERNET hInternet, hConnect, hRequest, hUrl;
public:
	std::string get_page(std::string url)
	{
		string result;
		char buffer[4096];
		memset(buffer, 0, 4096);
		std::vector<char> vb;


		hInternet = InternetOpen(TEXT("3d_engine"), INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
		if (hInternet != NULL)
		{
			hConnect = InternetOpenUrlA(hInternet, url.c_str(), NULL, 0, 0, NULL);

			if (hConnect != NULL)
			{
				DWORD dwByteRead = 0;
				do
				{ 
					InternetReadFile(hConnect, buffer, sizeof(buffer) - 1, &dwByteRead);
					result.copy(buffer, dwByteRead);

					vb.insert(vb.end(), buffer, buffer+dwByteRead);

					memset(buffer, 0, 4096);
				} while (dwByteRead);

				InternetCloseHandle(hConnect);
			}
			InternetCloseHandle(hInternet);
		}
		return result;
	}
};



int main()
{
	http_client hc;

	string page = hc.get_page("https://dev.virtualearth.net/REST/V1/Imagery/Map/road?mapArea=35.799994,25.642090,42.114524,44.615479&ms=500,500&pp=37.428175,-122.169680;;ST&ml=TrafficFlow&key=AuxHX17Q-LDnXLPRCncQ3tEFgpfR4e7rSMCIMH3Faig4GP54xCFGghlyW_oTfu0c");

	std::cout << page.size();
    return 0;
}

