#include "qtapplication.h"
#include <QCloseEvent>
#include "qfiledialog.h"
#include "qmessagebox.h"
#include "HelloWorldScene.h"
#include "Databind.h"
#include "AboutDialog.h"
#include "TextureDialog.h"
#include "qsettings.h"
#include <QColorDialog>
#include <QStandardPaths>

QtApplication::QtApplication(QWidget *parent)
	: QMainWindow(parent)
	, _glWidget(nullptr)
	, _isUpdate(false)
	, _lastSaveMode(false)
{
	ui.setupUi(this);
	ui.frame_01->setVisible(false);
	this->bindSignalSlot();

	_applicationName = this->windowTitle();

	_dataBind = new (std::nothrow) Databind(this, &ui);
	_dataBind->bindExample();
}

void QtApplication::initScene()
{
	this->_dataBind->setPlistFile("plists/BurstPipe.plist", true, true);	
	this->setWindowTitle(_applicationName + "- example/BurstPipe.plist");
	this->_isUpdate = false;
}

void QtApplication::setSaveMode(bool mode)
{
	this->_lastSaveMode = mode;
}

void QtApplication::setUpdateState(bool isUpdate)
{
	this->_isUpdate = isUpdate;
}

void QtApplication::bindSignalSlot()
{
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(processColorEvent()));
	connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(processColorEvent()));
	connect(ui.pushButton_5, SIGNAL(clicked()), this, SLOT(processColorEvent()));
	connect(ui.pushButton_6, SIGNAL(clicked()), this, SLOT(processColorEvent()));
	connect(ui.pushButton_7, SIGNAL(clicked()), this, SLOT(processColorEvent()));

	connect(ui.choose_texture, SIGNAL(clicked()), this, SLOT(processBtnEvent()));
	connect(ui.btn_normal, SIGNAL(clicked()), this, SLOT(processBtnEvent()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(processBtnEvent()));
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(processBtnEvent()));
	
	connect(ui.comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(processComboBoxEvent(int)));
	connect(ui.comboBox_2, SIGNAL(currentIndexChanged(int)), this, SLOT(processComboBoxEvent(int)));
	connect(ui.comboBox_4, SIGNAL(currentIndexChanged(int)), this, SLOT(processComboBoxEvent(int)));

	connect(ui.checkBox, SIGNAL(stateChanged(int)), this, SLOT(processComboBoxEvent(int)));
	connect(ui.checkBox_2, SIGNAL(stateChanged(int)), this, SLOT(processComboBoxEvent(int)));
	//menu tool
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(processBtnEvent()));
	connect(ui.action_Open, SIGNAL(triggered()), this, SLOT(processBtnEvent()));
	connect(ui.action_Save, SIGNAL(triggered()), this, SLOT(processBtnEvent()));
	connect(ui.actionSave, SIGNAL(triggered()), this, SLOT(processBtnEvent()));
	connect(ui.actionSave_As, SIGNAL(triggered()), this, SLOT(processBtnEvent()));
	connect(ui.actionSave_as, SIGNAL(triggered()), this, SLOT(processBtnEvent()));
	connect(ui.action_Reset, SIGNAL(triggered()), this, SLOT(processBtnEvent()));
	connect(ui.action_Play, SIGNAL(triggered()), this, SLOT(processBtnEvent()));
	connect(ui.action_About, SIGNAL(triggered()), this, SLOT(processBtnEvent())); 
	connect(ui.action_About_2, SIGNAL(triggered()), this, SLOT(processBtnEvent()));
	connect(ui.action_Quit, SIGNAL(triggered()), this, SLOT(processBtnEvent())); 
	connect(ui.action_ToolBar, SIGNAL(triggered()), this, SLOT(processBtnEvent()));
	connect(ui.actionMaximum, SIGNAL(triggered()), this, SLOT(processBtnEvent()));
	connect(ui.actionMinimum, SIGNAL(triggered()), this, SLOT(processBtnEvent()));
	connect(ui.actionFull_Screen, SIGNAL(triggered()), this, SLOT(processBtnEvent()));

	connect(ui.horizontalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(processBarEvent(int)));
	connect(ui.horizontalScrollBar_2, SIGNAL(valueChanged(int)), this, SLOT(processBarEvent(int)));
	connect(ui.horizontalScrollBar_3, SIGNAL(valueChanged(int)), this, SLOT(processBarEvent(int)));
	connect(ui.horizontalScrollBar_4, SIGNAL(valueChanged(int)), this, SLOT(processBarEvent(int)));

	connect(ui.horizontalScrollBar_9, SIGNAL(valueChanged(int)), this, SLOT(processBarEvent(int)));
	connect(ui.horizontalScrollBar_10, SIGNAL(valueChanged(int)), this, SLOT(processBarEvent(int)));
	connect(ui.horizontalScrollBar_11, SIGNAL(valueChanged(int)), this, SLOT(processBarEvent(int)));
	connect(ui.horizontalScrollBar_12, SIGNAL(valueChanged(int)), this, SLOT(processBarEvent(int)));

	connect(ui.horizontalScrollBar_13, SIGNAL(valueChanged(int)), this, SLOT(processBarEvent(int)));
	connect(ui.horizontalScrollBar_14, SIGNAL(valueChanged(int)), this, SLOT(processBarEvent(int)));
	connect(ui.horizontalScrollBar_15, SIGNAL(valueChanged(int)), this, SLOT(processBarEvent(int)));
	connect(ui.horizontalScrollBar_16, SIGNAL(valueChanged(int)), this, SLOT(processBarEvent(int)));

	connect(ui.horizontalScrollBar_17, SIGNAL(valueChanged(int)), this, SLOT(processBarEvent(int)));
	connect(ui.horizontalScrollBar_18, SIGNAL(valueChanged(int)), this, SLOT(processBarEvent(int)));
	connect(ui.horizontalScrollBar_19, SIGNAL(valueChanged(int)), this, SLOT(processBarEvent(int)));
	connect(ui.horizontalScrollBar_20, SIGNAL(valueChanged(int)), this, SLOT(processBarEvent(int)));

	connect(ui.horizontalScrollBar_21, SIGNAL(valueChanged(int)), this, SLOT(processBarEvent(int)));
	connect(ui.horizontalScrollBar_22, SIGNAL(valueChanged(int)), this, SLOT(processBarEvent(int)));
	connect(ui.horizontalScrollBar_23, SIGNAL(valueChanged(int)), this, SLOT(processBarEvent(int)));
	connect(ui.horizontalScrollBar_24, SIGNAL(valueChanged(int)), this, SLOT(processBarEvent(int)));

	connect(ui.dial, SIGNAL(valueChanged(int)), this, SLOT(processDialEvent(int)));
	connect(ui.doubleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(processBoxEvent(double)));
	
	connect(ui.dial_2, SIGNAL(valueChanged(int)), this, SLOT(processDialEvent(int)));
	connect(ui.doubleSpinBox_2, SIGNAL(valueChanged(double)), this, SLOT(processBoxEvent(double)));

	connect(ui.dial_3, SIGNAL(valueChanged(int)), this, SLOT(processDialEvent(int)));
	connect(ui.doubleSpinBox_3, SIGNAL(valueChanged(double)), this, SLOT(processBoxEvent(double)));

	connect(ui.dial_4, SIGNAL(valueChanged(int)), this, SLOT(processDialEvent(int)));
	connect(ui.doubleSpinBox_4, SIGNAL(valueChanged(double)), this, SLOT(processBoxEvent(double)));

	connect(ui.dial_5, SIGNAL(valueChanged(int)), this, SLOT(processDialEvent(int)));
	connect(ui.doubleSpinBox_5, SIGNAL(valueChanged(double)), this, SLOT(processBoxEvent(double)));

	connect(ui.dial_6, SIGNAL(valueChanged(int)), this, SLOT(processDialEvent(int)));
	connect(ui.doubleSpinBox_6, SIGNAL(valueChanged(double)), this, SLOT(processBoxEvent(double)));

	connect(ui.dial_7, SIGNAL(valueChanged(int)), this, SLOT(processDialEvent(int)));
	connect(ui.doubleSpinBox_7, SIGNAL(valueChanged(double)), this, SLOT(processBoxEvent(double)));

	connect(ui.dial_8, SIGNAL(valueChanged(int)), this, SLOT(processDialEvent(int)));
	connect(ui.doubleSpinBox_8, SIGNAL(valueChanged(double)), this, SLOT(processBoxEvent(double)));

	connect(ui.dial_14, SIGNAL(valueChanged(int)), this, SLOT(processDialEvent(int)));
	connect(ui.doubleSpinBox_14, SIGNAL(valueChanged(double)), this, SLOT(processBoxEvent(double)));

	connect(ui.dial_15, SIGNAL(valueChanged(int)), this, SLOT(processDialEvent(int)));
	connect(ui.doubleSpinBox_15, SIGNAL(valueChanged(double)), this, SLOT(processBoxEvent(double)));

	connect(ui.dial_16, SIGNAL(valueChanged(int)), this, SLOT(processDialEvent(int)));
	connect(ui.doubleSpinBox_16, SIGNAL(valueChanged(double)), this, SLOT(processBoxEvent(double)));

	connect(ui.dial_17, SIGNAL(valueChanged(int)), this, SLOT(processDialEvent(int)));
	connect(ui.doubleSpinBox_17, SIGNAL(valueChanged(double)), this, SLOT(processBoxEvent(double)));

	connect(ui.dial_18, SIGNAL(valueChanged(int)), this, SLOT(processDialEvent(int)));
	connect(ui.doubleSpinBox_18, SIGNAL(valueChanged(double)), this, SLOT(processBoxEvent(double)));

	connect(ui.dial_19, SIGNAL(valueChanged(int)), this, SLOT(processDialEvent(int)));
	connect(ui.doubleSpinBox_19, SIGNAL(valueChanged(double)), this, SLOT(processBoxEvent(double)));

	connect(ui.dial_maxr, SIGNAL(valueChanged(int)), this, SLOT(processDialEvent(int)));
	connect(ui.doubleSpinBox_maxr, SIGNAL(valueChanged(double)), this, SLOT(processBoxEvent(double)));

	connect(ui.dial_maxrv, SIGNAL(valueChanged(int)), this, SLOT(processDialEvent(int)));
	connect(ui.doubleSpinBox_maxrv, SIGNAL(valueChanged(double)), this, SLOT(processBoxEvent(double)));
	
	connect(ui.dial_minr, SIGNAL(valueChanged(int)), this, SLOT(processDialEvent(int)));
	connect(ui.doubleSpinBox_minr, SIGNAL(valueChanged(double)), this, SLOT(processBoxEvent(double)));

	connect(ui.dial_rotate, SIGNAL(valueChanged(int)), this, SLOT(processDialEvent(int))); 
	connect(ui.doubleSpinBox_rotate, SIGNAL(valueChanged(double)), this, SLOT(processBoxEvent(double)));

	connect(ui.dial_rotatevar, SIGNAL(valueChanged(int)), this, SLOT(processDialEvent(int)));
	connect(ui.doubleSpinBox_rotatevar, SIGNAL(valueChanged(double)), this, SLOT(processBoxEvent(double)));

	connect(ui.dial_speed, SIGNAL(valueChanged(int)), this, SLOT(processDialEvent(int)));
	connect(ui.doubleSpinBox_speed, SIGNAL(valueChanged(double)), this, SLOT(processBoxEvent(double)));

	connect(ui.dial_speedVar, SIGNAL(valueChanged(int)), this, SLOT(processDialEvent(int)));
	connect(ui.doubleSpinBox_speedVar, SIGNAL(valueChanged(double)), this, SLOT(processBoxEvent(double)));

	connect(ui.dial_gravityx, SIGNAL(valueChanged(int)), this, SLOT(processDialEvent(int)));
	connect(ui.doubleSpinBox_gravityx, SIGNAL(valueChanged(double)), this, SLOT(processBoxEvent(double)));

	connect(ui.dial_gravityy, SIGNAL(valueChanged(int)), this, SLOT(processDialEvent(int)));
	connect(ui.doubleSpinBox_gravityy, SIGNAL(valueChanged(double)), this, SLOT(processBoxEvent(double)));

	connect(ui.dial_radial, SIGNAL(valueChanged(int)), this, SLOT(processDialEvent(int)));
	connect(ui.doubleSpinBox_radial, SIGNAL(valueChanged(double)), this, SLOT(processBoxEvent(double)));

	connect(ui.dial_radialvar, SIGNAL(valueChanged(int)), this, SLOT(processDialEvent(int)));
	connect(ui.doubleSpinBox_radialvar, SIGNAL(valueChanged(double)), this, SLOT(processBoxEvent(double)));

	connect(ui.dial_tangential, SIGNAL(valueChanged(int)), this, SLOT(processDialEvent(int)));
	connect(ui.doubleSpinBox_tangential, SIGNAL(valueChanged(double)), this, SLOT(processBoxEvent(double)));

	connect(ui.dial_tangvar, SIGNAL(valueChanged(int)), this, SLOT(processDialEvent(int)));
	connect(ui.doubleSpinBox_tangvar, SIGNAL(valueChanged(double)), this, SLOT(processBoxEvent(double)));

	connect(ui.dial_x, SIGNAL(valueChanged(int)), this, SLOT(processDialEvent(int)));
	connect(ui.doubleSpinBox_x, SIGNAL(valueChanged(double)), this, SLOT(processBoxEvent(double)));

	connect(ui.dial_y, SIGNAL(valueChanged(int)), this, SLOT(processDialEvent(int)));
	connect(ui.doubleSpinBox_y, SIGNAL(valueChanged(double)), this, SLOT(processBoxEvent(double)));
}

LayerColor* QtApplication::getLayer() const
{
	auto scene = Director::getInstance()->getRunningScene();
	auto layer = scene->getChildByTag(PARTICLESYSTEMTAG);
	return (LayerColor*)layer;
}

ParticleSystem* QtApplication::getParticle() const
{
	auto scene = Director::getInstance()->getRunningScene();
	if (scene == nullptr) return nullptr;
	auto layer = scene->getChildByTag(PARTICLESYSTEMTAG);
	if (layer == nullptr) return nullptr;
	return ((HelloWorld*)layer)->getParticleSystem();
}

QtApplication::~QtApplication()
{
	if (_dataBind != nullptr)
	{
		delete _dataBind;
	}
}

bool QtApplication::showExitDialog()
{
	if (!_isUpdate)
	{
		this->closeWindow();
		return true;
	}
	QMessageBox::StandardButton reply;
	reply = QMessageBox::question(this, tr("Exit"), "Change the file is saved ?", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
	if (reply == QMessageBox::Yes)
	{
		this->showSaveFileDialog(2);
		return false;
	}
	else if (reply == QMessageBox::No){
		this->closeWindow();
		return true;
	}
	else if (reply == QMessageBox::Cancel)
	{
		return false;
	}
	return false;
}

void QtApplication::closeEvent(QCloseEvent *event)
{
	bool result = this->showExitDialog();
	if (result)
	{
		if (event != nullptr)event->accept();
	}
	else
	{
		if (event != nullptr)event->ignore();
	}
		
}

void QtApplication::closeWindow()
{
	QMainWindow::close();
	cocos2d::Director::getInstance()->end();
	qApp->quit();
}

void QtApplication::setGLView(QWidget *glWidget)
{
	_glWidget = glWidget;

	if (_glWidget)
	{
		ui.verticalLayout_3->addWidget(_glWidget);
	}
}

void QtApplication::processHistory()
{
	QAction *action = (QAction*)sender();
	QVariant variant = action->data();
	QString path = variant.toString();
	if (path.isEmpty()){
		QSettings settings("ParticleEdit.ini", QSettings::IniFormat);
		settings.beginGroup("history");
		settings.remove("openPaths");
		settings.endGroup();
		_dataBind->showHistoryMenu();
	}
	else{
		_dataBind->setPlistFile(path, false, true);
		this->_isUpdate = false;
		this->setWindowTitle(_applicationName + " - " + path);
	}
}

void QtApplication::processExample()
{
	QAction *action = (QAction*)sender();
	QString text = action->text();
	_dataBind->selectExample(text);
	this->setWindowTitle(_applicationName + " - example/" + text);
	this->_isUpdate = false;
}

void QtApplication::processBarEvent(int val)
{
	if (getParticle() == nullptr) return;
	GLubyte r, g, b, a;
	QString style = QString("background-color: rgb(%1,%2,%3);border:1px solid rgb(124,124,124);");
	if (sender() == ui.horizontalScrollBar_17 || 
		sender() == ui.horizontalScrollBar_18 || 
		sender() == ui.horizontalScrollBar_19 || 
		sender() == ui.horizontalScrollBar_20)
	{
		r = (GLubyte)ui.horizontalScrollBar_17->value();
		g = (GLubyte)ui.horizontalScrollBar_18->value();
		b = (GLubyte)ui.horizontalScrollBar_19->value();
		a = (GLubyte)ui.horizontalScrollBar_20->value();
		getParticle()->setStartColor(Color4F(Color4B(r,g,b,a)));
		ui.pushButton_3->setStyleSheet(style.arg(QString::number(r), QString::number(g), QString::number(b)));
		_isUpdate = true;
	}
	else if (sender() == ui.horizontalScrollBar_21 || 
			 sender() == ui.horizontalScrollBar_22 || 
			 sender() == ui.horizontalScrollBar_23 || 
			 sender() == ui.horizontalScrollBar_24)
	{
		r = (GLubyte)ui.horizontalScrollBar_21->value();
		g = (GLubyte)ui.horizontalScrollBar_22->value();
		b = (GLubyte)ui.horizontalScrollBar_23->value();
		a = (GLubyte)ui.horizontalScrollBar_24->value();
		ui.pushButton_4->setStyleSheet(style.arg(QString::number(r), QString::number(g), QString::number(b)));
		getParticle()->setStartColorVar(Color4F(Color4B(r, g, b, a)));
		_isUpdate = true;
	}
	else if (sender() == ui.horizontalScrollBar_9 || 
			 sender() == ui.horizontalScrollBar_10 || 
			 sender() == ui.horizontalScrollBar_11 || 
			 sender() == ui.horizontalScrollBar_12)
	{
		r = (GLubyte)ui.horizontalScrollBar_9->value();
		g = (GLubyte)ui.horizontalScrollBar_10->value();
		b = (GLubyte)ui.horizontalScrollBar_11->value();
		a = (GLubyte)ui.horizontalScrollBar_12->value();
		ui.pushButton_5->setStyleSheet(style.arg(QString::number(r), QString::number(g), QString::number(b)));
		getParticle()->setEndColor(Color4F(Color4B(r, g, b, a)));
		_isUpdate = true;
	}
	else if (sender() == ui.horizontalScrollBar_13 ||
		sender() == ui.horizontalScrollBar_14 ||
		sender() == ui.horizontalScrollBar_15 ||
		sender() == ui.horizontalScrollBar_16)
	{
		r = (GLubyte)ui.horizontalScrollBar_13->value();
		g = (GLubyte)ui.horizontalScrollBar_14->value();
		b = (GLubyte)ui.horizontalScrollBar_15->value();
		a = (GLubyte)ui.horizontalScrollBar_16->value();
		ui.pushButton_6->setStyleSheet(style.arg(QString::number(r), QString::number(g), QString::number(b)));
		getParticle()->setEndColorVar(Color4F(Color4B(r, g, b, a)));
		_isUpdate = true;
	}
	else if (sender() == ui.horizontalScrollBar ||
		sender() == ui.horizontalScrollBar_2 ||
		sender() == ui.horizontalScrollBar_3 ||
		sender() == ui.horizontalScrollBar_4)
	{
		r = (GLubyte)ui.horizontalScrollBar->value();
		g = (GLubyte)ui.horizontalScrollBar_2->value();
		b = (GLubyte)ui.horizontalScrollBar_3->value();
		a = (GLubyte)ui.horizontalScrollBar_4->value();
		ui.pushButton_7->setStyleSheet(style.arg(QString::number(r), QString::number(g), QString::number(b)));
		getLayer()->setColor(Color3B(r,g,b));
		getLayer()->setOpacity(a);
	}
}

void QtApplication::processComboBoxEvent(int val)
{
	if (getParticle() == nullptr) return;
	if (sender() == ui.comboBox){
		int dstIdx = ui.comboBox_2->currentIndex();
		BlendFunc blendFunc = { _gBlendFuncs[val], _gBlendFuncs[dstIdx] };
		getParticle()->setBlendFunc(blendFunc);
		_isUpdate = true;
	}else if (sender() == ui.comboBox_2){
		int srcIdx = ui.comboBox->currentIndex();
		BlendFunc blendFunc = {_gBlendFuncs[srcIdx], _gBlendFuncs[val]};
		getParticle()->setBlendFunc(blendFunc);
		_isUpdate = true;
	}else if (sender() == ui.comboBox_4){
		_isUpdate = true;
		if (val == 0){
			ui.frame_01->setVisible(false);
			ui.frame_2->setVisible(true);
			getParticle()->setEmitterMode(ParticleSystem::Mode::GRAVITY);
			_dataBind->setParticleEmitter(ParticleSystem::Mode::GRAVITY);
		}else if (val == 1){
			ui.frame_01->setVisible(true);
			ui.frame_2->setVisible(false);
			getParticle()->setEmitterMode(ParticleSystem::Mode::RADIUS);
			_dataBind->setParticleEmitter(ParticleSystem::Mode::RADIUS);
		}
	}
	else if (sender() == ui.checkBox)
	{
		HelloWorld *layer = (HelloWorld*)getLayer();
		layer->isShowBackground(val);
	}
	else if (sender() == ui.checkBox_2)
	{
		HelloWorld *layer = (HelloWorld*)getLayer();
		layer->setBackgroundMoved(val);
	}
}

void QtApplication::processDialEvent(int val)
{
	if (getParticle() == nullptr) return;
	double newVal = (double)val;
	Vec2 posVar = getParticle()->getPosVar();
	Vec2 gravity;
	if (getParticle()->getEmitterMode() == ParticleSystem::Mode::GRAVITY)
		gravity = getParticle()->getGravity();
	if (sender() == ui.dial){ ui.doubleSpinBox->setValue(newVal); getParticle()->setDuration(newVal); }
	else if (sender() == ui.dial_2){ ui.doubleSpinBox_2->setValue(newVal); getParticle()->setTotalParticles(val); }
	else if (sender() == ui.dial_3){ ui.doubleSpinBox_3->setValue(newVal); getParticle()->setLife(newVal); }
	else if (sender() == ui.dial_4){ ui.doubleSpinBox_4->setValue(newVal); getParticle()->setLifeVar(newVal); }
	else if (sender() == ui.dial_5){ ui.doubleSpinBox_5->setValue(newVal); getParticle()->setStartSize(newVal); }
	else if (sender() == ui.dial_6){ ui.doubleSpinBox_6->setValue(newVal); getParticle()->setStartSizeVar(newVal); }
	else if (sender() == ui.dial_7){ ui.doubleSpinBox_7->setValue(newVal); getParticle()->setEndSize(newVal); }
	else if (sender() == ui.dial_8){ ui.doubleSpinBox_8->setValue(newVal); getParticle()->setEndSizeVar(newVal); }
	else if (sender() == ui.dial_14){ ui.doubleSpinBox_14->setValue(newVal); getParticle()->setAngle(newVal); }
	else if (sender() == ui.dial_15){ ui.doubleSpinBox_15->setValue(newVal); getParticle()->setAngleVar(newVal); }
	else if (sender() == ui.dial_16){ ui.doubleSpinBox_16->setValue(newVal); getParticle()->setStartSpin(newVal); }
	else if (sender() == ui.dial_17){ ui.doubleSpinBox_17->setValue(newVal); getParticle()->setStartSpinVar(newVal); }
	else if (sender() == ui.dial_18){ ui.doubleSpinBox_18->setValue(newVal); getParticle()->setEndSpin(newVal); }
	else if (sender() == ui.dial_19){ ui.doubleSpinBox_19->setValue(newVal); getParticle()->setEndSpinVar(newVal); }
	else if (sender() == ui.dial_maxr){ ui.doubleSpinBox_maxr->setValue(newVal); getParticle()->setStartRadius(newVal); }
	else if (sender() == ui.dial_maxrv){ ui.doubleSpinBox_maxrv->setValue(newVal); getParticle()->setStartRadiusVar(newVal); }
	else if (sender() == ui.dial_minr){ ui.doubleSpinBox_minr->setValue(newVal); getParticle()->setEndRadius(newVal); }
	else if (sender() == ui.dial_rotate){ ui.doubleSpinBox_rotate->setValue(newVal); getParticle()->setRotatePerSecond(newVal); }
	else if (sender() == ui.dial_rotatevar){ ui.doubleSpinBox_rotatevar->setValue(newVal); getParticle()->setRotatePerSecondVar(newVal); }
	else if (sender() == ui.dial_speed){ ui.doubleSpinBox_speed->setValue(newVal); getParticle()->setSpeed(newVal); }
	else if (sender() == ui.dial_speedVar){ ui.doubleSpinBox_speedVar->setValue(newVal); getParticle()->setSpeedVar(newVal); }
	else if (sender() == ui.dial_gravityx){ ui.doubleSpinBox_gravityx->setValue(newVal); getParticle()->setGravity(Vec2(newVal, gravity.y)); }
	else if (sender() == ui.dial_gravityy){ ui.doubleSpinBox_gravityy->setValue(newVal); getParticle()->setGravity(Vec2(gravity.y, newVal)); }
	else if (sender() == ui.dial_radial){ ui.doubleSpinBox_radial->setValue(newVal); getParticle()->setRadialAccel(newVal); }
	else if (sender() == ui.dial_radialvar){ ui.doubleSpinBox_radialvar->setValue(newVal); getParticle()->setRadialAccelVar(newVal); }
	else if (sender() == ui.dial_tangential){ ui.doubleSpinBox_tangential->setValue(newVal); getParticle()->setTangentialAccel(newVal); }
	else if (sender() == ui.dial_tangvar){ ui.doubleSpinBox_tangvar->setValue(newVal); getParticle()->setTangentialAccelVar(newVal); }
	else if (sender() == ui.dial_x){ ui.doubleSpinBox_x->setValue(newVal); getParticle()->setPosVar(Vec2(newVal, posVar.y)); }
	else if (sender() == ui.dial_y){ ui.doubleSpinBox_y->setValue(newVal); getParticle()->setPosVar(Vec2(posVar.x, newVal)); }
	_isUpdate = true;
}

void QtApplication::processBoxEvent(double val)
{
	if (getParticle() == nullptr) return;
	Vec2 gravity;
	Vec2 posVar = getParticle()->getPosVar();
	if (getParticle()->getEmitterMode() == ParticleSystem::Mode::GRAVITY)
		gravity = getParticle()->getGravity();
	if (sender() == ui.doubleSpinBox){ ui.dial->setValue((int)val); getParticle()->setDuration(val); }
	else if (sender() == ui.doubleSpinBox_2){ ui.dial_2->setValue((int)val); getParticle()->setTotalParticles((int)val); }
	else if (sender() == ui.doubleSpinBox_3){ ui.dial_3->setValue((int)val); getParticle()->setLife(val); }
	else if (sender() == ui.doubleSpinBox_4){ ui.dial_4->setValue((int)val); getParticle()->setLifeVar(val); }
	else if (sender() == ui.doubleSpinBox_5){ ui.dial_5->setValue((int)val); getParticle()->setStartSize(val); }
	else if (sender() == ui.doubleSpinBox_6){ ui.dial_6->setValue((int)val); getParticle()->setStartSizeVar(val); }
	else if (sender() == ui.doubleSpinBox_7){ ui.dial_7->setValue((int)val); getParticle()->setEndSize(val); }
	else if (sender() == ui.doubleSpinBox_8){ ui.dial_8->setValue((int)val); getParticle()->setEndSizeVar(val); }
	else if (sender() == ui.doubleSpinBox_14){ ui.dial_14->setValue((int)val); getParticle()->setAngle(val); }
	else if (sender() == ui.doubleSpinBox_15){ ui.dial_15->setValue((int)val); getParticle()->setAngleVar(val); }
	else if (sender() == ui.doubleSpinBox_16){ ui.dial_16->setValue((int)val); getParticle()->setStartSpin(val); }
	else if (sender() == ui.doubleSpinBox_17){ ui.dial_17->setValue((int)val); getParticle()->setStartSpinVar(val); }
	else if (sender() == ui.doubleSpinBox_18){ ui.dial_18->setValue((int)val); getParticle()->setEndSpin(val); }
	else if (sender() == ui.doubleSpinBox_19){ ui.dial_19->setValue((int)val); getParticle()->setEndSpinVar(val); }
	else if (sender() == ui.doubleSpinBox_maxr){ ui.dial_maxr->setValue((int)val); getParticle()->setStartRadius(val); }
	else if (sender() == ui.doubleSpinBox_maxrv){ ui.dial_maxrv->setValue((int)val); getParticle()->setStartRadiusVar(val); }
	else if (sender() == ui.doubleSpinBox_minr){ ui.dial_minr->setValue((int)val); getParticle()->setEndRadius(val); }
	else if (sender() == ui.doubleSpinBox_rotate){ ui.dial_rotate->setValue((int)val); getParticle()->setRotatePerSecond(val); }
	else if (sender() == ui.doubleSpinBox_rotatevar){ ui.dial_rotatevar->setValue((int)val); getParticle()->setRotatePerSecondVar(val); }
	else if (sender() == ui.doubleSpinBox_speed){ ui.dial_speed->setValue((int)val); getParticle()->setSpeed(val); }
	else if (sender() == ui.doubleSpinBox_speedVar){ ui.dial_speedVar->setValue((int)val); getParticle()->setSpeedVar(val); }
	else if (sender() == ui.doubleSpinBox_gravityx){ ui.dial_gravityx->setValue((int)val); getParticle()->setGravity(Vec2(val, gravity.y)); }
	else if (sender() == ui.doubleSpinBox_gravityy){ ui.dial_gravityy->setValue((int)val); getParticle()->setGravity(Vec2(gravity.x, val)); }
	else if (sender() == ui.doubleSpinBox_radial){ ui.dial_radial->setValue((int)val); getParticle()->setRadialAccel(val); }
	else if (sender() == ui.doubleSpinBox_radialvar){ ui.dial_radialvar->setValue((int)val); getParticle()->setRadialAccelVar(val); }
	else if (sender() == ui.doubleSpinBox_tangential){ ui.dial_tangential->setValue((int)val); getParticle()->setTangentialAccel(val); }
	else if (sender() == ui.doubleSpinBox_tangvar){ ui.dial_tangvar->setValue((int)val); getParticle()->setTangentialAccelVar(val); }
	else if (sender() == ui.doubleSpinBox_x){ ui.dial_x->setValue((int)val); getParticle()->setPosVar(Vec2(val, posVar.y)); }
	else if (sender() == ui.doubleSpinBox_y){ ui.dial_y->setValue((int)val); getParticle()->setPosVar(Vec2(posVar.x, val)); }
	_isUpdate = true;
}

void QtApplication::showSaveFileDialog(int tag)
{
	if (!this->_dataBind->isSaved() || tag == 1)
	{
		QString plistPath = "";
		QString title = (tag == 1) ? tr("Save as") : tr("Save");
		QSettings settings("ParticleEdit.ini", QSettings::IniFormat);
		QString savePath = settings.value("path/savePath").toString();
		if (savePath.isEmpty()) savePath = "D:/";
		plistPath = QFileDialog::getSaveFileName(this, title, savePath, tr("Particle File(*.plist)"));
		if (!plistPath.isEmpty())
		{
			_lastSaveFileName = plistPath;
			QFileInfo fInfo(plistPath);
			QString absolutePath = fInfo.absolutePath();
			QString plistFileName = fInfo.fileName();
			QString textureFileName = plistFileName.mid(0, plistFileName.lastIndexOf(".")) + ".png";
			TextureDialog *textureDialog = new TextureDialog(this);
			textureDialog->setPlistInfo(absolutePath, plistFileName);
			textureDialog->setTextureName(textureFileName);
			textureDialog->setCloseMainTag(tag == 2);
			textureDialog->show();
		}
	}
	else if (this->_dataBind->isSaved() && !this->_lastSaveFileName.isEmpty())
	{
		QFileInfo fInfo(_lastSaveFileName);
		QString absolutePath = fInfo.absolutePath();
		QString plistFileName = fInfo.fileName();
		QString textureFileName = plistFileName.mid(0, plistFileName.lastIndexOf(".")) + ".png";
		_dataBind->savePlist(absolutePath, plistFileName, textureFileName, _lastSaveMode);
		_isUpdate = false;
	}
}

void QtApplication::processColorEvent()
{
	QColor color;
	if (sender() == ui.pushButton_3)
	{
		color.setRed(ui.horizontalScrollBar_17->value());
		color.setGreen(ui.horizontalScrollBar_18->value());
		color.setBlue(ui.horizontalScrollBar_19->value());
	}
	else if (sender() == ui.pushButton_4)
	{
		color.setRed(ui.horizontalScrollBar_21->value());
		color.setGreen(ui.horizontalScrollBar_22->value());
		color.setBlue(ui.horizontalScrollBar_23->value());
	}
	else if (sender() == ui.pushButton_5)
	{
		color.setRed(ui.horizontalScrollBar_9->value());
		color.setGreen(ui.horizontalScrollBar_10->value());
		color.setBlue(ui.horizontalScrollBar_11->value());
	}
	else if (sender() == ui.pushButton_6)
	{
		color.setRed(ui.horizontalScrollBar_13->value());
		color.setGreen(ui.horizontalScrollBar_14->value());
		color.setBlue(ui.horizontalScrollBar_15->value());
	}
	else if (sender() == ui.pushButton_7)
	{
		color.setRed(ui.horizontalScrollBar->value());
		color.setGreen(ui.horizontalScrollBar_2->value());
		color.setBlue(ui.horizontalScrollBar_3->value());
	}
	color = QColorDialog::getColor(color, this);
	QString msg = QString("background-color: rgb(%1,%2,%3);border:1px solid rgb(124,124,124);").
		arg(QString::number(color.red()),QString::number(color.green()), QString::number(color.blue()));
	if (sender() == ui.pushButton_3)
	{
		ui.horizontalScrollBar_17->setValue(color.red());
		ui.horizontalScrollBar_18->setValue(color.green());
		ui.horizontalScrollBar_19->setValue(color.blue());
		ui.pushButton_3->setStyleSheet(msg);
	}
	else if (sender() == ui.pushButton_4)
	{
		ui.horizontalScrollBar_21->setValue(color.red());
		ui.horizontalScrollBar_22->setValue(color.green());
		ui.horizontalScrollBar_23->setValue(color.blue());
		ui.pushButton_4->setStyleSheet(msg);
	}
	else if (sender() == ui.pushButton_5)
	{
		ui.horizontalScrollBar_9->setValue(color.red());
		ui.horizontalScrollBar_10->setValue(color.green());
		ui.horizontalScrollBar_11->setValue(color.blue());
		ui.pushButton_5->setStyleSheet(msg);
	}
	else if (sender() == ui.pushButton_6)
	{
		ui.horizontalScrollBar_13->setValue(color.red());
		ui.horizontalScrollBar_14->setValue(color.green());
		ui.horizontalScrollBar_15->setValue(color.blue());
		ui.pushButton_6->setStyleSheet(msg);
	}
	else if (sender() == ui.pushButton_7)
	{
		ui.horizontalScrollBar->setValue(color.red());
		ui.horizontalScrollBar_2->setValue(color.green());
		ui.horizontalScrollBar_3->setValue(color.blue());
		ui.pushButton_7->setStyleSheet(msg);
	}
/*	QString msg = QString("r: %1, g: %2, b: %3").arg(QString::number(color.red()), 
		QString::number(color.green()), QString::number(color.blue()));
	QMessageBox::information(this, "Selected color", msg);*/

}

void QtApplication::processBtnEvent()
{
	if (getParticle() == nullptr) return;
	QSettings settings("ParticleEdit.ini", QSettings::IniFormat);
	QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
	if (sender() == ui.choose_texture)
	{
		ui.choose_texture->setEnabled(false);
		QString textureFilePath = settings.value("path/openTextureFile").toString();
		if (textureFilePath.isEmpty())textureFilePath = desktopPath;
		QString path = QFileDialog::getOpenFileName(this, tr("Open Texture File"), textureFilePath, tr("Image Files(*.png)"));
		if(!path.isEmpty()) {
			this->_dataBind->setTextureByPath(path);
			settings.beginGroup("path");
			settings.setValue("openTextureFile", QFileInfo(path).absolutePath());
			settings.endGroup();
		}
		ui.choose_texture->setEnabled(true);
	}
	else if (sender() == ui.pushButton)
	{
		QString backgroundFilePath = settings.value("path/openBackgroundFile").toString();
		if (backgroundFilePath.isEmpty())backgroundFilePath = desktopPath;
		QString path = QFileDialog::getOpenFileName(this, tr("Open Background Image"), backgroundFilePath, tr("Image Files(*.png *.jpg)"));
		if (path.length() > 0)
		{
			HelloWorld *layer = (HelloWorld*)this->getLayer();
			std::string backPath = (const char*)path.toUtf8();
			layer->setBackground(backPath);
			ui.checkBox->setChecked(true);
			QImage *image = new QImage();
			if (!image->load(path)){ delete image; return; }
			QRect rect = ui.label_87->geometry();
			if (image->width() > rect.width() || image->height() > rect.height())
				*image = image->scaled(rect.width(), rect.height(), Qt::KeepAspectRatio);
			ui.label_87->setPixmap(QPixmap::fromImage(*image));
			delete image;
			settings.beginGroup("path");
			settings.setValue("openBackgroundFile", QFileInfo(path).absolutePath());
			settings.endGroup();
		}
	}
	else if (sender() == ui.actionOpen || sender() == ui.action_Open)
	{
		QString particleFilePath = settings.value("path/openParticleFile").toString();
		if (particleFilePath.isEmpty())particleFilePath = desktopPath;
		QString path = QFileDialog::getOpenFileName(this, tr("Choose Particle File"), particleFilePath, tr("Particle Files(*.plist)"));
		if (!path.isEmpty())
		{
			this->_dataBind->setPlistFile(path, false, true);
			this->_isUpdate = false;
			this->setWindowTitle(_applicationName + "- " + path);
			settings.beginGroup("path");
			settings.setValue("openParticleFile", QFileInfo(path).absolutePath());
			settings.endGroup();
		}
	}
	else if (sender() == ui.actionSave || sender() == ui.action_Save)
	{
		this->showSaveFileDialog(0);
	}
	else if (sender() == ui.actionSave_As || sender() == ui.actionSave_as)
	{
		this->showSaveFileDialog(1);
	}
	else if (sender() == ui.btn_normal)
	{
		_isUpdate = true;
		ui.comboBox->setCurrentText("GL_SRC_ALPHA");
		ui.comboBox_2->setCurrentText("GL_ONE_MINUS_SRC_ALPHA");
		getParticle()->setBlendFunc({GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA});
	}
	else if (sender() == ui.pushButton_2)
	{
		_isUpdate = true;
		ui.comboBox->setCurrentText("GL_SRC_ALPHA");
		ui.comboBox_2->setCurrentText("GL_ONE");
		getParticle()->setBlendFunc({GL_SRC_ALPHA, GL_ONE});
	}
	else if (sender() == ui.action_Reset)
	{
		this->_dataBind->reset();
		getParticle()->resetSystem();
		auto layer = ((HelloWorld*)getLayer());
		layer->setScale(1.0f);
	}
	else if (sender() == ui.action_Play)
	{
		getParticle()->resetSystem();
	}
	else if (sender() == ui.action_About || sender() == ui.action_About_2)
	{
		AboutDialog *aboutDialog = new AboutDialog(this);
		aboutDialog->show();
	}
	else if (sender() == ui.action_Quit)
	{
		this->showExitDialog();
	}
	else if (sender() == ui.action_ToolBar)
	{
		if (ui.action_ToolBar->isChecked())
			ui.mainToolBar->setVisible(true);
		else
			ui.mainToolBar->setVisible(false);
	}
	else if (sender() == ui.actionMaximum)
	{
		this->showMaximized();
	}
	else if (sender() == ui.actionMinimum)
	{
		this->showMinimized();
	}
	else if (sender() == ui.actionFull_Screen)
	{
		if (this->isFullScreen())
		{
			this->showNormal();
			ui.actionFull_Screen->setText("Full Screen");
		}
		else
		{
			this->showFullScreen();
			ui.actionFull_Screen->setText("Exit Full Screen");
		}
	}
}

void QtApplication::keyPressEvent(QKeyEvent *event)
{
	switch (event->key())
	{
	case Qt::Key_Plus:
	{
		auto layer = ((HelloWorld*)getLayer());
		layer->setScale(layer->getScale() + 0.1f);
		break;
	}
	case Qt::Key_Minus:
	{
		auto layer = ((HelloWorld*)getLayer());
		layer->setScale(layer->getScale() - 0.1f);
		break;
	}
	default:
		QMainWindow::keyPressEvent(event);
		break;
	}
}

void QtApplication::wheelEvent(QWheelEvent *event)
{
	QMainWindow::wheelEvent(event);
	int delta = event->delta();
	auto layer = ((HelloWorld*)getLayer());
	layer->setScale(layer->getScale() + (delta / 1000.0f));
}

