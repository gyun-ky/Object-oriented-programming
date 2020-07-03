#pragma once
#include <iostream>
#include <string>
using namespace std;

class Host
{
private:
	string name;
	bool cam, mic;
	string contentsList[3];
public:
	Host();
	Host(string hostName);
	string getName();
	bool getMicStatus();
	bool getCamStatus();
	void cameraOnOff();
	void micOnOff();
	string shareContents();
};

