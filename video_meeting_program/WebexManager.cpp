#include "WebexManager.h"

WebexManager::WebexManager() {
	userNum = 4;
	meetingRoomNum = 2;
	userList.insert(pair<string, string>("����", "������123"));
	userList.insert(pair<string, string>("�����", "�л�123"));
	userList.insert(pair<string, string>("���ϵ�", "������123"));
	userList.insert(pair<string, string>("��Ƽ��", "�л�123"));

	authority.insert(pair<string, int>("����", 1));
	authority.insert(pair<string, int>("�����", 2));
	authority.insert(pair<string, int>("���ϵ�", 1));
	authority.insert(pair<string, int>("��Ƽ��", 2));
	meetingRoomList.push_back(MeetingRoom("���ϵ�"));
	meetingRoomList[0].roomNum = 101;
	meetingRoomList.push_back(MeetingRoom("��Ƽ��"));
	meetingRoomList[1].roomNum = 102;
}

MeetingRoom* WebexManager::createRoom(string hostName) {
	meetingRoomList.push_back(MeetingRoom(hostName));
	meetingRoomList[meetingRoomNum].roomNum = (100 + meetingRoomNum+1);

	cout << "[info] ���÷��� �����Ǿ����ϴ�. RoomNum : " << meetingRoomList[meetingRoomNum] .roomNum<< endl<<endl;
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
	cout << "[Error] ���ų� �߸��� ���÷��Դϴ�" << endl;
}

void WebexManager::printRoomList() {
	vector<MeetingRoom> ::iterator iter;
	cout << endl;
	cout << "[�����ִ� ���÷� ����Ʈ]" << endl;
	for (iter = meetingRoomList.begin(); iter != meetingRoomList.end(); iter++) {
		cout << iter->getHostName() << "���� ���÷� : " << iter->roomNum <<endl;
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
	cout << "[info] ���÷��� ����Ǿ����ϴ�." << endl << endl;
}

bool WebexManager::login(string userName) {
	
	string pw;
	map<string, string>::iterator iter;
	for (iter = userList.begin(); iter != userList.end(); iter++) {
		if (iter->first == userName) {
			cout << "��й�ȣ : ";
			getline(cin, pw);
			if (iter->second == pw) {
				cout << "[info] �ȳ��ϼ���," << userName << "��!" << endl;
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
	cout << "***** webex�� �����մϴ� *****" << endl;
}

int WebexManager::menu() {
	int select;
	cout << "--- ���� ---" << endl;
	cout << "(1) - ���÷� �����ϱ�" << endl;
	cout << "(2) - ���÷� �����ϱ�" << endl;
	cout << "(3) - Webex �����ϱ�" << endl;
	cout << ">>";
	cin >> select;
	cin.ignore();
	return select;
}

void WebexManager::initManager() {
	cout << "***** webex�� �����մϴ� *****" << endl;
	string userName;
	while (1) {
		cout << "--- �α��� ---" << endl;
		cout << "���̵� : ";
		getline(cin, userName);
		if (login(userName)) {
			break;
		}
		else {
			cout << "[Error] ��й�ȣ�� Ʋ���ų� ��ϵ� ȸ���� �ƴմϴ�" << endl;
			cout << "�ٽ� �α��� �ϼ���" << endl;
		}
	}
	int sel = 0;
	while (sel != 3) {
		sel = menu();
		if (sel == 1 && authority[userName] == 2) {
			cout << "[Error] �л� �����Դϴ�! ���� ���÷��� ������ �� �����ϴ�." << endl << endl;
			continue;
		}
		int selectRoomNum; //������ ���÷� ��ȣ ����
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
			cout << "������ ���÷� ��ȣ �Է� >>";
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