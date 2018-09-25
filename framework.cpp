// framework.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "datetime.h"
#include "http_client.h"


#include <string>
#include <iostream>
#include <vector>


using namespace std;


int main()
{
	http_client hc;

	string page = hc.get_page("https://dev.virtualearth.net/REST/V1/Imagery/Map/road?mapArea=35.799994,25.642090,42.114524,44.615479&ms=500,500&pp=37.428175,-122.169680;;ST&ml=TrafficFlow&key=AuxHX17Q-LDnXLPRCncQ3tEFgpfR4e7rSMCIMH3Faig4GP54xCFGghlyW_oTfu0c");

	std::cout << page.size();
    return 0;
}

