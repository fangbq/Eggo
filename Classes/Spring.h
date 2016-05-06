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
	void show();    // 显示弹簧
	void hide();    // 隐藏弹簧
	// void reset();   // 重置弹簧数据

	bool isAlive(); // 是否活动状态

	// 检查碰撞
	bool isCollideWithPlayer(Player* player);
private:
	bool m_isAlive;
};

#endif
