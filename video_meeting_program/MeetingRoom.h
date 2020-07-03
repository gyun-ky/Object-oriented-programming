#pragma once

#include "Host.h"
#include "Guest.h"
class MeetingRoom
{
private:
	Host *host;
	int guestNum;
	vector<Guest*> guestList;
	string sharedContents;
	vector<string> chatLog;
	bool recordStatus;
	
public:
	MeetingRoom();
	MeetingRoom(string hostName);
	int roomNum;
	string getHostName();

	Guest* join(Guest *student);
	void recordSet();

	void showRoomStatus();
	void showHostStatus();
	void showGuestStatus(Guest* me);

	void printChat();
	void chat(string userName);

	void printPList();
	
	void guestControl();
	void checkHands();
	
	void hostUI();
	void GuestUI(string userName);
	
};

