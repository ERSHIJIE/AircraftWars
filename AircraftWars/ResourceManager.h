#pragma once
#include <list>
#include "BasicObject.h"

class Scence {
private:
	int scenceId;
public:
	//��ʼ������ ID��1000
	void ScenceOrigin();
	//�������� ID��1001
	void ScenceHelp();
	//��ͣ���� ID��1002
	void ScencePause();
	//ս������ ID��1003
	void ScenceFight();
	//���㳡�� ID��1004
	void ScenceEnd();
	//��ֵ���� ID��1005
	void ScenceRecharge();
};

std::list<Actor> l;
