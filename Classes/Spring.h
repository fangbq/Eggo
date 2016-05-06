#ifndef __Spring_H__
#define __Spring_H__

#include "cocos2d.h"
#include "Entity.h"
USING_NS_CC;

class Player;
class Spring : public Entity {
public:
	Spring();
	~Spring();
	CREATE_FUNC(Spring);
	virtual bool init();

public:
	void show();    // ��ʾ����
	void hide();    // ���ص���
	// void reset();   // ���õ�������

	bool isAlive(); // �Ƿ�״̬

	// �����ײ
	bool isCollideWithPlayer(Player* player);
private:
	bool m_isAlive;
};

#endif
