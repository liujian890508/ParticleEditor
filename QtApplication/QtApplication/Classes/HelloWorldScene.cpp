#include "HelloWorldScene.h"

Scene* HelloWorld::createScene(AppDelegate *delegate)
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create(delegate);

    // add layer as a child to scene
	scene->addChild(layer, 100, PARTICLESYSTEMTAG);

    // return the scene
    return scene;
}

HelloWorld* HelloWorld::create(AppDelegate *delegate)
{
	auto layer = new (std::nothrow) HelloWorld();
	if (layer && layer->init(delegate))
	{
		layer->autorelease();
		return layer;
	}
	CC_SAFE_RELEASE(layer);
	return nullptr;
}

// on "init" you need to initialize your instance
bool HelloWorld::init(AppDelegate *delegate)
{
    //////////////////////////////
    // 1. super init first
	if (!LayerColor::initWithColor(Color4B(0,0,0,255)))
    {
        return false;
    }

	this->_delegate = delegate;
	this->_scale = 1.0f;

	this->_bgSprite = nullptr;
	this->_particleSystem = nullptr;
	this->_enableBgMoved = false;

	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
	this->setTouchEnabled(true);

	this->setKeyboardEnabled(true);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	
	this->_scaleLabel = Label::createWithSystemFont("", "", 25);
	this->addChild(this->_scaleLabel);
	this->_scaleLabel->setPosition(Vec2(50, visibleSize.height-30));
	this->_scaleLabel->setVisible(false);
    return true;
}

void HelloWorld::setScale(float scale)
{
	if (scale <= 0.0f) return;
	_scale = scale;
	if (_particleSystem != nullptr)
	{
		_particleSystem->setScale(scale);
	}
	if (_bgSprite != nullptr)
	{
		_bgSprite->setScale(scale);
	}
	if (_scale != 1.0f)
	{
		char buffer[1024];
		sprintf(buffer, "%.0f%%%", _scale * 100);
		_scaleLabel->setString(buffer);
		_scaleLabel->setVisible(true);
	}
	else
	{
		_scaleLabel->setVisible(false);
	}
}

void HelloWorld::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{

}

void HelloWorld::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{

}

void HelloWorld::initParticleSystem(std::string &plistFile)
{
	if (this->_particleSystem != nullptr)
	{
		this->_particleSystem->removeFromParent();
		this->_particleSystem = nullptr;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	_particleSystem = ParticleSystemQuad::create(plistFile);
	this->addChild(_particleSystem, 1);
	_particleSystem->setAnchorPoint(Point(.5, .5));
	_particleSystem->setPosition(_particleSystem->getPosition() + Vec2(180, 100));
	_particleSystem->setScale(_scale);
}

void HelloWorld::onEnterTransitionDidFinish()
{
	LayerColor::onEnterTransitionDidFinish();

	this->_delegate->startRender();
}

void HelloWorld::setBackground(std::string &path)
{
	if (_bgSprite == nullptr)
	{
		this->_bgSprite = Sprite::create();
		this->addChild(_bgSprite, 0);
		_bgSprite->setScale(_scale);
	}
	auto spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(path);
	if (spriteFrame == nullptr)
	{
		auto tex = Director::getInstance()->getTextureCache()->addImage(path);
		Size size = tex->getContentSize();
		spriteFrame = SpriteFrame::createWithTexture(tex, Rect(0, 0, size.width, size.height));
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	this->_bgSprite->setPosition(visibleSize / 2);
	this->_bgSprite->setSpriteFrame(spriteFrame);
}

bool HelloWorld::onTouchBegan(Touch *touch, Event *unused_event)
{
	return true;
}

void HelloWorld::onTouchMoved(Touch *touch, Event *unused_event)
{
	Point point = touch->getLocation();
	if (_enableBgMoved)
		_bgSprite->setPosition(point);
	else
		_particleSystem->setPosition(point);
}

void HelloWorld::onTouchEnded(Touch *touch, Event *unused_event)
{
	Point point = touch->getLocation();
	if (_enableBgMoved)
		_bgSprite->setPosition(point);
	else{
		_particleSystem->setPosition(point);
		if (!_particleSystem->isActive())
			_particleSystem->resetSystem(); 
	}
}

void HelloWorld::onTouchCancelled(Touch *touch, Event *unused_event)
{
	
}

void HelloWorld::isShowBackground(bool isShow)
{
	this->_bgSprite->setVisible(isShow);
}
