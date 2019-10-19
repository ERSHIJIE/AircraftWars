#pragma once
#include <list>
#include "BasicObject.h"

class Scence {
private:
	int scenceId;
public:
	//初始化场景 ID：1000
	void ScenceOrigin();
	//帮助场景 ID：1001
	void ScenceHelp();
	//暂停场景 ID：1002
	void ScencePause();
	//战斗场景 ID：1003
	void ScenceFight();
	//结算场景 ID：1004
	void ScenceEnd();
	//充值场景 ID：1005
	void ScenceRecharge();
};

std::list<Actor> l;
