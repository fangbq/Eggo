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
		/* ���ÿɼ� */
		setVisible(true);

		/* ��ǹ���Ϊ�״̬ */
		m_isAlive = true;
	}
}

void Spring::hide()
{
	if (getSprite() != NULL)
	{
		/* ���ò��ɼ� */
		setVisible(false);

		/* ���ù������� */
		// reset();

		/* ��ǹ���Ϊ�ǻ״̬ */
		m_isAlive = false;
	}
}

/*
void Spring::reset()
{
	if (getSprite() != NULL)
	{
		// ��ʼ����������
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