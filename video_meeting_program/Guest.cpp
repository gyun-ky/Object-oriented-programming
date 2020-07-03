#include "Guest.h"

Guest::Guest() {
	this->cam = false;
	this->mic = false;
	this->handsUp = false;
}

Guest::Guest(string guestName) {
	this->name = guestName;
	this->cam = false;
	this->mic = false;
	this->handsUp = false;
	this->contentsList[0] = "화면";
	this->contentsList[1] = "응용프로그램1";
	this->contentsList[2] = "응용프로그램2";
}

string Guest::getName() {
	return name;
}

bool Guest::getMicStatus() {
	return mic;
}

bool Guest::getCamStatus() {
	return cam;
}

void Guest::cameraOnOff() {
	if (this->cam == true) {
		this->cam = false;
		cout << "[info] 내 비디오 중지" << endl;
	}
	else {
		this->cam = true;
		cout << "[info] 내 비디오 시작" << endl;
	}
}

void Guest::micOnOff() {
	if (this->mic == true) {
		this->mic = false;
		cout << "[info] 음소거" << endl;
	}
	else {
		this->mic = true;
		cout << "[info] 음소거 해제" << endl;
	}
}

string Guest::shareContents() {
	cout << "--------공유 컨텐츠 선택--------" << endl;
	int select;
	for (int i = 0; i < 3; i++) {
		cout << "(" << i + 1 << ") - " << contentsList[i] << endl;
	}
	cout << "(4) - 공유 중단" << endl;
	cout << ">>";
	cin >> select;
	
	if (select > 4 || select < 0)
		cout << "[Error] 잘못된 선택 입니다 오류 종료" << endl;
	else if (select == 4)
		return "none";
	else
		return contentsList[select-1];
}

void Guest::memoing() {
	string memoline;
	cout << "--------메모--------" << endl;
	if (!memo.empty()) {
		for (int i = 0; i < memo.size(); i++) {
			cout << memo[i] << endl;
		}
	}
	cout << "입력 : ";
	getline(cin, memoline);
	memo.push_back(memoline);
	cout << "--------------------" << endl;
}

void Guest::setHandsUp() {
	if (handsUp == false) {
		handsUp = true;
		cout << "[info] 손을 들었습니다." << endl<<endl;
	}
	else {
		handsUp = false;
		cout << "[info] 손을 내렸습니다." << endl << endl;
	}
}

bool Guest::getHandsUp() {
	return handsUp;
}


