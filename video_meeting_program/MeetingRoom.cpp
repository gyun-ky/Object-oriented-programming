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
	cout << guest->getName() << "님이 입장하셨습니다." << endl;
	guestNum++;
	return guestList[guestNum - 1];
}

void  MeetingRoom::recordSet() {
	if (recordStatus == true) {
		recordStatus = false;
		cout << "[info] 녹화 중지" << endl<<endl;
	}
	else {
		recordStatus = true;
		cout << "[info] 녹화 시작" << endl<<endl;
	}
}

void MeetingRoom::showRoomStatus() {
	cout <<endl<< "[Room Status] 공유된 컨텐츠 : " << sharedContents << " / 녹화 상태 : ";
	if (recordStatus)
		cout << "녹화중" << endl<<endl;
	else
		cout << "녹화 중지" << endl<<endl;
}

void MeetingRoom:: showHostStatus() {
	cout << "[My Status] 마이크 : ";
	if (host->getMicStatus())
		cout << "ON";
	else
		cout << "OFF";
	cout << " 카메라 : ";
	if (host->getCamStatus())
		cout << "ON"<<endl<<endl;
	else
		cout << "OFF" << endl << endl;
}

void MeetingRoom::showGuestStatus(Guest* me) {
	cout << "[My Status] 마이크 : ";
	if (me->getMicStatus())
		cout << "ON";
	else
		cout << "OFF";
	cout << " 카메라 : ";
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
	cout << "--------채팅--------" << endl;
	printChat();
	string result = userName + "님이 모두에게 : ";
	string chatInput;
	cout << "[info] 입력 : ";
	getline(cin, chatInput);
	result.append(chatInput);
	chatLog.push_back(result);
	cout << "--------------------" << endl<<endl;
}


void MeetingRoom::printPList() {
	cout << "--------참가자(" << guestNum + 1 << ")--------" << endl;
	cout << host->getName() << "(호스트) - [Mic";
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
	cout << "--------수강자 마이크 ON/OFF Control--------" << endl;
	string name;
	cout << "이름 입력 : ";
	getline(cin, name);
	for (int i = 0; i < guestNum; i++) {
		if (guestList[i]->getName() == name) {
			guestList[i]->micOnOff();
			cout << "[info] 완료" << endl<<endl;
		}
	}
	cout << "--------------------------------------------" << endl;
	
}

void MeetingRoom:: checkHands() {
	bool exist = false;
	for (int i = 0; i < guestNum; i++) {
		if (guestList[i]->getHandsUp() == true) {
			exist = true;
			cout << "[info]" << guestList[i]->getName() << "님이 손을 들었습니다" << endl<<endl;
		}
	}
	if (exist == false)
		cout << "[info] 손 든 사람이 없습니다" << endl<<endl;
}

void MeetingRoom::hostUI() {
	cout << "---- " << host->getName() << "'s Personal Room ----" << endl;
	cout << "[info] 다른 사용자가 참가할 때까지 기다리는 중" << endl<<endl;
	///////////////구현을 위한 가상의 Guest 두명 투입/////////////////
	join(new Guest("김홍익"));
	join(new Guest("김컴공"));
	//////////////////////////////////////////////////////////////////
	int select=0;
	while (select!=8) {
		showRoomStatus();
		showHostStatus();
		cout << "--- 선택 ---" << endl;
		cout << "(1) - 음소거/음소거 해제" << endl;
		cout << "(2) - 내 비디오 시작/중지" << endl;
		cout << "(3) - 콘텐츠 공유" << endl;
		cout << "(4) - 녹화 시작/중지" << endl;
		cout << "(5) - 참가자" << endl;
		cout << "(6) - 손 든 사람 체크" << endl;
		cout << "(7) - 채팅" << endl;
		cout << "(8) - 미팅 종료" << endl;
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
	///////////////구현을 위한 가상의 Guest 두명 투입/////////////////
	join(new Guest("김홍익"));
	join(new Guest("김컴공"));
	//////////////////////////////////////////////////////////////////
	int select = 0;
	while (select != 8) {
		showRoomStatus();
		showGuestStatus(me);
		cout << "--- >선택< ---" << endl;
		cout << "(1) - 음소거/음소거 해제" << endl;
		cout << "(2) - 내 비디오 시작/중지" << endl;
		cout << "(3) - 콘텐츠 공유" << endl;
		cout << "(4) - 참가자" << endl;
		cout << "(5) - 채팅" << endl;
		cout << "(6) - 메모" << endl;
		cout << "(7) - 손 흔들기" << endl;
		cout << "(8) - 미팅 종료" << endl;
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







