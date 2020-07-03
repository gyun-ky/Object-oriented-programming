#include "WebexManager.h"

WebexManager::WebexManager() {
	userNum = 4;
	meetingRoomNum = 2;
	userList.insert(pair<string, string>("윤영", "교수님123"));
	userList.insert(pair<string, string>("김기윤", "학생123"));
	userList.insert(pair<string, string>("김일도", "교수님123"));
	userList.insert(pair<string, string>("김티동", "학생123"));

	authority.insert(pair<string, int>("윤영", 1));
	authority.insert(pair<string, int>("김기윤", 2));
	authority.insert(pair<string, int>("김일도", 1));
	authority.insert(pair<string, int>("김티동", 2));
	meetingRoomList.push_back(MeetingRoom("김일도"));
	meetingRoomList[0].roomNum = 101;
	meetingRoomList.push_back(MeetingRoom("김티동"));
	meetingRoomList[1].roomNum = 102;
}

MeetingRoom* WebexManager::createRoom(string hostName) {
	meetingRoomList.push_back(MeetingRoom(hostName));
	meetingRoomList[meetingRoomNum].roomNum = (100 + meetingRoomNum+1);

	cout << "[info] 미팅룸이 생성되었습니다. RoomNum : " << meetingRoomList[meetingRoomNum] .roomNum<< endl<<endl;
	meetingRoomNum++;
	return &meetingRoomList[meetingRoomNum - 1];
}

MeetingRoom* WebexManager::joinRoom(int roomNum) {
	if (!meetingRoomList.empty()) {
		for (int i = 0; i < meetingRoomNum; i++) {
			if (meetingRoomList[i].roomNum == roomNum)
				return &meetingRoomList[i];
		}
	}
	cout << "[Error] 없거나 잘못된 미팅룸입니다" << endl;
}

void WebexManager::printRoomList() {
	vector<MeetingRoom> ::iterator iter;
	cout << endl;
	cout << "[열려있는 미팅룸 리스트]" << endl;
	for (iter = meetingRoomList.begin(); iter != meetingRoomList.end(); iter++) {
		cout << iter->getHostName() << "님의 미팅룸 : " << iter->roomNum <<endl;
	}
}
void WebexManager::endRoom(string hostName) {
	vector<MeetingRoom> ::iterator iter;
	for (iter = meetingRoomList.begin(); iter != meetingRoomList.end(); ) {
		if (iter->getHostName() == hostName)
			iter = meetingRoomList.erase(iter);
		else
			++iter;
	}
	cout << "[info] 미팅룸이 종료되었습니다." << endl << endl;
}

bool WebexManager::login(string userName) {
	
	string pw;
	map<string, string>::iterator iter;
	for (iter = userList.begin(); iter != userList.end(); iter++) {
		if (iter->first == userName) {
			cout << "비밀번호 : ";
			getline(cin, pw);
			if (iter->second == pw) {
				cout << "[info] 안녕하세요," << userName << "님!" << endl;
				return true;
			}
			else {
				return false;
			}
		}
	}
	return false;
}

void WebexManager::endManager() {
	cout << "***** webex를 종료합니다 *****" << endl;
}

int WebexManager::menu() {
	int select;
	cout << "--- 선택 ---" << endl;
	cout << "(1) - 미팅룸 시작하기" << endl;
	cout << "(2) - 미팅룸 참가하기" << endl;
	cout << "(3) - Webex 종료하기" << endl;
	cout << ">>";
	cin >> select;
	cin.ignore();
	return select;
}

void WebexManager::initManager() {
	cout << "***** webex를 시작합니다 *****" << endl;
	string userName;
	while (1) {
		cout << "--- 로그인 ---" << endl;
		cout << "아이디 : ";
		getline(cin, userName);
		if (login(userName)) {
			break;
		}
		else {
			cout << "[Error] 비밀번호가 틀리거나 등록된 회원이 아닙니다" << endl;
			cout << "다시 로그인 하세요" << endl;
		}
	}
	int sel = 0;
	while (sel != 3) {
		sel = menu();
		if (sel == 1 && authority[userName] == 2) {
			cout << "[Error] 학생 권한입니다! 강의 미팅룸을 생성할 수 없습니다." << endl << endl;
			continue;
		}
		int selectRoomNum; //참여할 미팅룸 번호 변수
		MeetingRoom* mr = NULL;
		switch (sel) {
		case 1:
			mr = createRoom(userName);
			mr->hostUI();
			endRoom(userName);
			break;
		case 2:
			int selectRoomNum;
			printRoomList();
			cout << "참여할 미팅룸 번호 입력 >>";
			cin >> selectRoomNum;
			cin.ignore();
			mr = joinRoom(selectRoomNum);
			mr->GuestUI(userName);
			break;
		case 3:
			endManager();
			break;
		}
	}
}