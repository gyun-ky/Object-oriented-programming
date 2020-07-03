#include "Host.h"

Host::Host() {
	this->cam = false;
	this->mic = false;
}

Host::Host(string hostName) {
	this->name = hostName;
	this->cam = false;
	this->mic = false;
	this->contentsList[0] = "화면";
	this->contentsList[1] = "응용프로그램1";
	this->contentsList[2] = "응용프로그램2";
}

string Host::getName() {
	return name;
}

bool Host::getMicStatus() {
	return mic;
}

bool Host::getCamStatus() {
	return cam;
}
void Host::cameraOnOff() {
	if (this->cam == true) {
		this->cam = false;
		cout << "[info] 내 비디오 중지" << endl;
	}
	else {
		this->cam = true;
		cout << "[info] 내 비디오 시작" << endl;
	}
}

void Host::micOnOff() {
	if (this->mic == true) {
		this->mic = false;
		cout << "[info] 음소거" << endl;
	}
	else {
		this->mic = true;
		cout << "[info] 음소거 해제" << endl;
	}
}

string Host::shareContents() {
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
		return contentsList[select - 1];
}


