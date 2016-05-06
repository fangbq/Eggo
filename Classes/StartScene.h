#ifndef __START_SCENE_H__
#define __START_SCENE_H__

#include "cocos2d.h"
#include "TollgateScene.h"
// #include "ui\CocosGUI.h"
#include "cocostudio\CocoStudio.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace cocos2d::ui;
using namespace CocosDenshion;

class StartScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene() {
		auto scene = Scene::create();
		auto layer = StartScene::create();
		scene->addChild(layer);

		return scene;
	}
	virtual bool init() {
		if (!Layer::init())
		{
			return false;
		}
		Size visibleSize = Director::getInstance()->getVisibleSize();
		Vec2 origin = Director::getInstance()->getVisibleOrigin();

		auto UI = CSLoader::createNode("res/startScene.csb");
		this->addChild(UI);

		// Ìí¼Ó°´Å¥ ºÍ ¼àÌý
		auto start_btn = (Button*)UI->getChildByName("startBtn");
		auto quit_btn = (Button*)UI->getChildByName("Button_2");
		start_btn->addTouchEventListener(this, toucheventselector(StartScene::start_game));
		quit_btn->addTouchEventListener(this, toucheventselector(StartScene::quit_game));
		SimpleAudioEngine::getInstance()->preloadBackgroundMusic("music/back.mp3");
		SimpleAudioEngine::getInstance()->playBackgroundMusic("music/back.mp3", true);
		return true;
	}
	void start_game(Ref*, TouchEventType type)
	{
		switch (type)
		{
		case TouchEventType::TOUCH_EVENT_ENDED:
			Director::getInstance()->replaceScene(
				TransitionFadeTR::create(3.0f, TollgateScene::createScene()));
			// Director::getInstance()->replaceScene( \
				TransitionSlideInT::create(3.0f, TollgateScene::createScene()));
			
			break;
		}
	}

	void quit_game(Ref*, TouchEventType type)
	{
		switch (type)
		{
		case TouchEventType::TOUCH_EVENT_ENDED:
			Director::getInstance()->end();
			break;
		}
	}
	CREATE_FUNC(StartScene);
private:
	Sprite* start;
};

#endif
