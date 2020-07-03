#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Guest
{
private:
	string name;
	bool cam, mic, handsUp;
	string contentsList[3];
	vector<string> memo;
public:
	Guest();
	Guest(string guestName);
	string getName();
	bool getMicStatus();
	bool getCamStatus();
	void cameraOnOff();
	void micOnOff();
	string shareContents();
	void memoing();
	void setHandsUp();
	bool getHandsUp();
};



