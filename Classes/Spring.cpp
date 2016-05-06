#include "Spring.h"
#include "Player.h"
// #include "ccMacros.h"

Spring::Spring()
{
	m_isAlive = false;
}

Spring::~Spring()
{
}

bool Spring::init()
{
	bool bRet = false;

	do {
		bRet = true;
	} while (0);

	return bRet;
}

void Spring::show()
{
	if (getSprite() != NULL)
	{
		/* 设置可见 */
		setVisible(true);

		/* 标记怪物为活动状态 */
		m_isAlive = true;
	}
}

void Spring::hide()
{
	if (getSprite() != NULL)
	{
		/* 设置不可见 */
		setVisible(false);

		/* 重置怪物数据 */
		// reset();

		/* 标记怪物为非活动状态 */
		m_isAlive = false;
	}
}

/*
void Spring::reset()
{
	if (getSprite() != NULL)
	{
		// 初始化怪物坐标
		setPosition(Point(800 + CCRANDOM_0_1() * 2000, 200 - CCRANDOM_0_1() * 100));
	}
}
*/

/*
bool Spring::isAlive()
{
	return m_isAlive;
}
*/

bool Spring::isCollideWithPlayer(Player* player)
{
	Rect entityRect = player->getBoundingBox();

	Point mosterPos = getPosition();

	return entityRect.containsPoint(mosterPos);
}