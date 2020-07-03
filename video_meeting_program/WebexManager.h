#pragma once
#include "Host.h"
#include "Guest.h"
#include "MeetingRoom.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

class WebexManager
{
private:
	int userNum;
	int meetingRoomNum;
	map<string, string> userList;
	map<string, int> authority; //1이면 교수, 2면 학생권한
	vector<MeetingRoom> meetingRoomList;
public:
	WebexManager();
	MeetingRoom* createRoom(string hostName);
	MeetingRoom* joinRoom(int roomNum);
	void printRoomList();
	void endRoom(string hostName);
	bool login(string userName);
	void endManager();
	int menu();
	void initManager();
};

