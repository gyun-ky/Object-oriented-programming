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
	this->contentsList[0] = "ȭ��";
	this->contentsList[1] = "�������α׷�1";
	this->contentsList[2] = "�������α׷�2";
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
		cout << "[info] �� ���� ����" << endl;
	}
	else {
		this->cam = true;
		cout << "[info] �� ���� ����" << endl;
	}
}

void Guest::micOnOff() {
	if (this->mic == true) {
		this->mic = false;
		cout << "[info] ���Ұ�" << endl;
	}
	else {
		this->mic = true;
		cout << "[info] ���Ұ� ����" << endl;
	}
}

string Guest::shareContents() {
	cout << "--------���� ������ ����--------" << endl;
	int select;
	for (int i = 0; i < 3; i++) {
		cout << "(" << i + 1 << ") - " << contentsList[i] << endl;
	}
	cout << "(4) - ���� �ߴ�" << endl;
	cout << ">>";
	cin >> select;
	
	if (select > 4 || select < 0)
		cout << "[Error] �߸��� ���� �Դϴ� ���� ����" << endl;
	else if (select == 4)
		return "none";
	else
		return contentsList[select-1];
}

void Guest::memoing() {
	string memoline;
	cout << "--------�޸�--------" << endl;
	if (!memo.empty()) {
		for (int i = 0; i < memo.size(); i++) {
			cout << memo[i] << endl;
		}
	}
	cout << "�Է� : ";
	getline(cin, memoline);
	memo.push_back(memoline);
	cout << "--------------------" << endl;
}

void Guest::setHandsUp() {
	if (handsUp == false) {
		handsUp = true;
		cout << "[info] ���� ������ϴ�." << endl<<endl;
	}
	else {
		handsUp = false;
		cout << "[info] ���� ���Ƚ��ϴ�." << endl << endl;
	}
}

bool Guest::getHandsUp() {
	return handsUp;
}


