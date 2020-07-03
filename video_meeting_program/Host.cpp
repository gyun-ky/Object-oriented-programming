#include "Host.h"

Host::Host() {
	this->cam = false;
	this->mic = false;
}

Host::Host(string hostName) {
	this->name = hostName;
	this->cam = false;
	this->mic = false;
	this->contentsList[0] = "ȭ��";
	this->contentsList[1] = "�������α׷�1";
	this->contentsList[2] = "�������α׷�2";
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
		cout << "[info] �� ���� ����" << endl;
	}
	else {
		this->cam = true;
		cout << "[info] �� ���� ����" << endl;
	}
}

void Host::micOnOff() {
	if (this->mic == true) {
		this->mic = false;
		cout << "[info] ���Ұ�" << endl;
	}
	else {
		this->mic = true;
		cout << "[info] ���Ұ� ����" << endl;
	}
}

string Host::shareContents() {
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
		return contentsList[select - 1];
}


