#include "MeetingRoom.h"

MeetingRoom::MeetingRoom() {
	recordStatus = false;
	guestNum = 0;
}

MeetingRoom::MeetingRoom(string hostName) {
	recordStatus = false;
	guestNum = 0;
	host = new Host(hostName);
	sharedContents = "None";
}

string MeetingRoom::getHostName() {
	return host->getName();
}

Guest* MeetingRoom::join(Guest *guest) {
	guestList.push_back(guest);
	cout << guest->getName() << "���� �����ϼ̽��ϴ�." << endl;
	guestNum++;
	return guestList[guestNum - 1];
}

void  MeetingRoom::recordSet() {
	if (recordStatus == true) {
		recordStatus = false;
		cout << "[info] ��ȭ ����" << endl<<endl;
	}
	else {
		recordStatus = true;
		cout << "[info] ��ȭ ����" << endl<<endl;
	}
}

void MeetingRoom::showRoomStatus() {
	cout <<endl<< "[Room Status] ������ ������ : " << sharedContents << " / ��ȭ ���� : ";
	if (recordStatus)
		cout << "��ȭ��" << endl<<endl;
	else
		cout << "��ȭ ����" << endl<<endl;
}

void MeetingRoom:: showHostStatus() {
	cout << "[My Status] ����ũ : ";
	if (host->getMicStatus())
		cout << "ON";
	else
		cout << "OFF";
	cout << " ī�޶� : ";
	if (host->getCamStatus())
		cout << "ON"<<endl<<endl;
	else
		cout << "OFF" << endl << endl;
}

void MeetingRoom::showGuestStatus(Guest* me) {
	cout << "[My Status] ����ũ : ";
	if (me->getMicStatus())
		cout << "ON";
	else
		cout << "OFF";
	cout << " ī�޶� : ";
	if (me->getCamStatus())
		cout << "ON"<<endl<<endl;
	else
		cout << "OFF" << endl << endl;
}


void MeetingRoom::printChat() {
	if (!chatLog.empty()) {
		for (int i = 0; i < chatLog.size(); i++) {
			cout << chatLog[i] << endl;
		}
	}
}

void MeetingRoom::chat(string userName) {
	cout << "--------ä��--------" << endl;
	printChat();
	string result = userName + "���� ��ο��� : ";
	string chatInput;
	cout << "[info] �Է� : ";
	getline(cin, chatInput);
	result.append(chatInput);
	chatLog.push_back(result);
	cout << "--------------------" << endl<<endl;
}


void MeetingRoom::printPList() {
	cout << "--------������(" << guestNum + 1 << ")--------" << endl;
	cout << host->getName() << "(ȣ��Ʈ) - [Mic";
	if (host->getMicStatus())
		cout << " ON]";
	else
		cout << " OFF]";
	cout << " [Cam";
	if (host->getCamStatus())
		cout << " ON]";
	else
		cout << " OFF]";
	cout << endl;
	for (int i = 0; i < guestNum; i++) {
		cout << guestList[i]->getName()<<" - [MIC"; 
		if (guestList[i]->getMicStatus())
			cout << " ON]";
		else
			cout << " OFF]";
		cout << " [Cam";
		if (guestList[i]->getCamStatus())
			cout << " ON]";
		else
			cout << " OFF]";
		cout << endl;
	}
	cout << "--------------------------------------------" << endl<<endl;
}


void MeetingRoom::guestControl() {
	cout << "--------������ ����ũ ON/OFF Control--------" << endl;
	string name;
	cout << "�̸� �Է� : ";
	getline(cin, name);
	for (int i = 0; i < guestNum; i++) {
		if (guestList[i]->getName() == name) {
			guestList[i]->micOnOff();
			cout << "[info] �Ϸ�" << endl<<endl;
		}
	}
	cout << "--------------------------------------------" << endl;
	
}

void MeetingRoom:: checkHands() {
	bool exist = false;
	for (int i = 0; i < guestNum; i++) {
		if (guestList[i]->getHandsUp() == true) {
			exist = true;
			cout << "[info]" << guestList[i]->getName() << "���� ���� ������ϴ�" << endl<<endl;
		}
	}
	if (exist == false)
		cout << "[info] �� �� ����� �����ϴ�" << endl<<endl;
}

void MeetingRoom::hostUI() {
	cout << "---- " << host->getName() << "'s Personal Room ----" << endl;
	cout << "[info] �ٸ� ����ڰ� ������ ������ ��ٸ��� ��" << endl<<endl;
	///////////////������ ���� ������ Guest �θ� ����/////////////////
	join(new Guest("��ȫ��"));
	join(new Guest("���İ�"));
	//////////////////////////////////////////////////////////////////
	int select=0;
	while (select!=8) {
		showRoomStatus();
		showHostStatus();
		cout << "--- ���� ---" << endl;
		cout << "(1) - ���Ұ�/���Ұ� ����" << endl;
		cout << "(2) - �� ���� ����/����" << endl;
		cout << "(3) - ������ ����" << endl;
		cout << "(4) - ��ȭ ����/����" << endl;
		cout << "(5) - ������" << endl;
		cout << "(6) - �� �� ��� üũ" << endl;
		cout << "(7) - ä��" << endl;
		cout << "(8) - ���� ����" << endl;
		cout << ">>";
		cin >> select;
		cin.ignore();

		switch (select) {
		case 1:
			host->micOnOff();
			break;
		case 2:
			host->cameraOnOff();
			break;
		case 3:
			sharedContents = host->shareContents();
			break;
		case 4:
			recordSet();
			break;
		case 5:
			printPList();
			guestControl();
			break;
		case 6:
			checkHands();
			break;
		case 7:
			chat(host->getName());
			break;
		case 8:
			break;
		}
	}


}

void MeetingRoom::GuestUI(string userName) {
	Guest* me = join(new Guest(userName));
	cout << "---- " << host->getName() << "'s Personal Room ----" << endl;
	///////////////������ ���� ������ Guest �θ� ����/////////////////
	join(new Guest("��ȫ��"));
	join(new Guest("���İ�"));
	//////////////////////////////////////////////////////////////////
	int select = 0;
	while (select != 8) {
		showRoomStatus();
		showGuestStatus(me);
		cout << "--- >����< ---" << endl;
		cout << "(1) - ���Ұ�/���Ұ� ����" << endl;
		cout << "(2) - �� ���� ����/����" << endl;
		cout << "(3) - ������ ����" << endl;
		cout << "(4) - ������" << endl;
		cout << "(5) - ä��" << endl;
		cout << "(6) - �޸�" << endl;
		cout << "(7) - �� ����" << endl;
		cout << "(8) - ���� ����" << endl;
		cout << ">>";
		cin >> select;
		cin.ignore();

		switch (select) {
		case 1:
			me->micOnOff();
			break;
		case 2:
			me->cameraOnOff();
			break;
		case 3:
			sharedContents = me->shareContents();
			break;
		case 4:
			printPList();
			break;
		case 5:
			chat(me->getName());
			break;
		case 6:
			me->memoing();
			break;
		case 7:
			me->setHandsUp();
			break;
		case 8:
			break;
		}
	}

}







