#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "AppDelegate.h"
USING_NS_CC;

#define PARTICLESYSTEMTAG 100

class HelloWorld : public cocos2d::LayerColor
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene(AppDelegate *delegate);

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init(AppDelegate *delegate);
	void initParticleSystem(std::string &plistFile);

	virtual void onEnterTransitionDidFinish();

	//Get ParticleSystem Layer
	cocos2d::ParticleSystem* getParticleSystem()const{ return _particleSystem; }

	//set layer background image
	void setBackground(std::string &path);
	// moved particle or moved background
	inline void setBackgroundMoved(bool enable){ this->_enableBgMoved = enable; }

	//show / hide background
	void isShowBackground(bool show);
    
    // implement the "static create()" method manually
	static HelloWorld* create(AppDelegate *delegate);

	float getScale() const { return this->_scale; }
	void setScale(float scale);

public:
	virtual bool onTouchBegan(Touch *touch, Event *unused_event);
	virtual void onTouchMoved(Touch *touch, Event *unused_event);
	virtual void onTouchEnded(Touch *touch, Event *unused_event);
	virtual void onTouchCancelled(Touch *touch, Event *unused_event);

	virtual void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	virtual void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

private:
	AppDelegate *_delegate;
	cocos2d::ParticleSystem *_particleSystem;
	cocos2d::Sprite *_bgSprite;
	Label			*_scaleLabel;
	std::string _bgPath;
	bool _enableBgMoved;
	float _scale;
	bool _isShowBackground;
};

#endif // __HELLOWORLD_SCENE_H__
