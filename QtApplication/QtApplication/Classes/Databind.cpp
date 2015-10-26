#include "Databind.h"
#include "qtapplication.h"
#include "qmessagebox.h"
#include <qfile.h>
#include <qdir.h>
#include "HelloWorldScene.h"
#include <QSettings>

Databind::Databind(QtApplication *app, Ui::QtApplicationClass *ui)
{
	this->app = app;
	this->ui = ui;
	this->_dirname = "";
	this->_plistFile = "";
	this->_isSaved = false;
	this->_savePlistPath = "";
	this->_textureKey = "";
	this->_currentImage = nullptr;
}

Databind::~Databind()
{
	if (_currentImage)
		_currentImage->release();
}

void Databind::addHistoryPath(QString path)
{
	for (int i = 0; i < _history.size(); i++)
	{
		if (_history.at(i) == path)
		{
			_history.removeAt(i);
		}
	}
	_history.push_back(path);
	if (_history.size() > 10)
	{
		_history.pop_front();
	}
	QSettings settings("ParticleEdit.ini", QSettings::IniFormat);
	settings.beginGroup("history");
	settings.setValue("openPaths", _history);
	settings.endGroup();
	this->showHistoryMenu();
}

void Databind::setPlistFile(QString plistFile, bool isExample, bool isClearSave)
{
	if (this->_plistFile == plistFile) return;
	if (isClearSave) _isSaved = false;
	if (!isExample) this->addHistoryPath(plistFile);
	std::string cppPlistFile = plistFile.toUtf8();
	ValueMap dictionary = FileUtils::getInstance()->getValueMapFromFile(cppPlistFile);
	if (dictionary.size() == 0) return;
	this->_plistFile = plistFile;
	_dictionary = dictionary;
	QString listFilePath = _plistFile;
	QFileInfo fileInfo(listFilePath);
	this->_dirname = fileInfo.absolutePath();
	ParticleSystem::Mode model = (ParticleSystem::Mode)dictionary["emitterType"].asInt();
	this->setParticleProperties(dictionary);
	this->setBlendFunc(dictionary);
	this->setParticleColor(dictionary);
	this->setParticleTexture(dictionary);
	this->setParticleEmitter(model);
	((HelloWorld*)app->getLayer())->initParticleSystem(plistFile.toStdString());
}

void Databind::reset()
{
	QString newPath = this->_plistFile;
	this->_plistFile = "";
	this->setPlistFile(newPath, true, false);
}

void Databind::setParticleProperties(ValueMap &dictionary)
{
	ui->dial->setValue(dictionary["duration"].asDouble());
	ui->doubleSpinBox->setValue(dictionary["duration"].asDouble());
	ui->dial_2->setValue(dictionary["maxParticles"].asDouble());
	ui->doubleSpinBox_2->setValue(dictionary["maxParticles"].asDouble());
	ui->dial_3->setValue(dictionary["particleLifespan"].asDouble());
	ui->doubleSpinBox_3->setValue(dictionary["particleLifespan"].asDouble());
	ui->dial_4->setValue(dictionary["particleLifespanVariance"].asDouble());
	ui->doubleSpinBox_4->setValue(dictionary["particleLifespanVariance"].asDouble());
	ui->dial_5->setValue(dictionary["startParticleSize"].asDouble());
	ui->doubleSpinBox_5->setValue(dictionary["startParticleSize"].asDouble());
	ui->dial_6->setValue(dictionary["startParticleSizeVariance"].asDouble());
	ui->doubleSpinBox_6->setValue(dictionary["startParticleSizeVariance"].asDouble());
	ui->dial_7->setValue(dictionary["finishParticleSize"].asDouble());
	ui->doubleSpinBox_7->setValue(dictionary["finishParticleSize"].asDouble());
	ui->dial_8->setValue(dictionary["finishParticleSizeVariance"].asDouble());
	ui->doubleSpinBox_8->setValue(dictionary["finishParticleSizeVariance"].asDouble());
	ui->dial_14->setValue(dictionary["angle"].asDouble());
	ui->doubleSpinBox_14->setValue(dictionary["angle"].asDouble());
	ui->dial_15->setValue(dictionary["angleVariance"].asDouble());
	ui->doubleSpinBox_15->setValue(dictionary["angleVariance"].asDouble());
	ui->dial_16->setValue(dictionary["rotationStart"].asDouble());
	ui->doubleSpinBox_16->setValue(dictionary["rotationStart"].asDouble());
	ui->dial_17->setValue(dictionary["rotationStartVariance"].asDouble());
	ui->doubleSpinBox_17->setValue(dictionary["rotationStartVariance"].asDouble());
	ui->dial_18->setValue(dictionary["rotationEnd"].asDouble());
	ui->doubleSpinBox_18->setValue(dictionary["rotationEnd"].asDouble());
	ui->dial_19->setValue(dictionary["rotationEndVariance"].asDouble());
	ui->doubleSpinBox_19->setValue(dictionary["rotationEndVariance"].asDouble());
	ui->dial_x->setValue(dictionary["sourcePositionVariancex"].asDouble());
	ui->doubleSpinBox_x->setValue(dictionary["sourcePositionVariancex"].asDouble());
	ui->dial_y->setValue(dictionary["sourcePositionVariancey"].asDouble());
	ui->doubleSpinBox_y->setValue(dictionary["sourcePositionVariancey"].asDouble());
}

void Databind::setBlendFunc(ValueMap &dictionary)
{
	GLenum src = dictionary["blendFuncSource"].asInt();
	GLenum dst = dictionary["blendFuncDestination"].asInt();
	ui->comboBox->setCurrentIndex(getBlendFunIdx(src));
	ui->comboBox_2->setCurrentIndex(getBlendFunIdx(dst));
}

void Databind::setParticleColor(ValueMap &dictionary)
{
	QString style = QString("background-color: rgb(%1,%2,%3);border:1px solid rgb(124,124,124);");
	ui->horizontalScrollBar_17->setValue(dictionary["startColorRed"].asFloat() * 255);
	ui->horizontalScrollBar_18->setValue(dictionary["startColorGreen"].asFloat() * 255);
	ui->horizontalScrollBar_19->setValue(dictionary["startColorBlue"].asFloat() * 255);
	ui->horizontalScrollBar_20->setValue(dictionary["startColorAlpha"].asFloat() * 255);
	ui->pushButton_3->setStyleSheet(style.arg(QString::number(ui->horizontalScrollBar_17->value()), 
		QString::number(ui->horizontalScrollBar_18->value()), 
		QString::number(ui->horizontalScrollBar_19->value())));

	ui->horizontalScrollBar_21->setValue(dictionary["startColorVarianceRed"].asFloat() * 255);
	ui->horizontalScrollBar_22->setValue(dictionary["startColorVarianceGreen"].asFloat() * 255);
	ui->horizontalScrollBar_23->setValue(dictionary["startColorVarianceBlue"].asFloat() * 255);
	ui->horizontalScrollBar_24->setValue(dictionary["startColorVarianceAlpha"].asFloat() * 255);
	ui->pushButton_4->setStyleSheet(style.arg(QString::number(ui->horizontalScrollBar_21->value()),
		QString::number(ui->horizontalScrollBar_22->value()),
		QString::number(ui->horizontalScrollBar_23->value())));

	ui->horizontalScrollBar_9->setValue(dictionary["finishColorRed"].asFloat() * 255);
	ui->horizontalScrollBar_10->setValue(dictionary["finishColorGreen"].asFloat() * 255);
	ui->horizontalScrollBar_11->setValue(dictionary["finishColorBlue"].asFloat() * 255);
	ui->horizontalScrollBar_12->setValue(dictionary["finishColorAlpha"].asFloat() * 255);
	ui->pushButton_5->setStyleSheet(style.arg(QString::number(ui->horizontalScrollBar_9->value()),
		QString::number(ui->horizontalScrollBar_10->value()),
		QString::number(ui->horizontalScrollBar_11->value())));

	ui->horizontalScrollBar_13->setValue(dictionary["finishColorVarianceRed"].asFloat() * 255);
	ui->horizontalScrollBar_14->setValue(dictionary["finishColorVarianceGreen"].asFloat() * 255);
	ui->horizontalScrollBar_15->setValue(dictionary["finishColorVarianceBlue"].asFloat() * 255);
	ui->horizontalScrollBar_16->setValue(dictionary["finishColorVarianceAlpha"].asFloat() * 255);
	ui->pushButton_6->setStyleSheet(style.arg(QString::number(ui->horizontalScrollBar_13->value()),
		QString::number(ui->horizontalScrollBar_14->value()),
		QString::number(ui->horizontalScrollBar_15->value())));

	ui->horizontalScrollBar->setValue(0);
	ui->horizontalScrollBar_2->setValue(0);
	ui->horizontalScrollBar_3->setValue(0);
	ui->horizontalScrollBar_4->setValue(255);
	ui->pushButton_7->setStyleSheet(style.arg(QString::number(0),QString::number(0),QString::number(0)));
}

void Databind::setParticleEmitter(ParticleSystem::Mode mode)
{
	if (mode == ParticleSystem::Mode::RADIUS)
	{
		ui->frame_01->setVisible(true);
		ui->frame_2->setVisible(false);
		ui->comboBox_4->setCurrentIndex(1);

		ui->dial_maxr->setValue(_dictionary["maxRadius"].asDouble());
		ui->doubleSpinBox_maxr->setValue(_dictionary["maxRadius"].asDouble());
		ui->dial_maxrv->setValue(_dictionary["maxRadiusVariance"].asDouble());
		ui->doubleSpinBox_maxrv->setValue(_dictionary["maxRadiusVariance"].asDouble());
		ui->dial_minr->setValue(_dictionary["minRadius"].asDouble());
		ui->doubleSpinBox_minr->setValue(_dictionary["minRadius"].asDouble());
		ui->dial_rotate->setValue(_dictionary["rotatePerSecond"].asDouble());
		ui->doubleSpinBox_rotate->setValue(_dictionary["rotatePerSecond"].asDouble());
		ui->dial_rotatevar->setValue(_dictionary["rotatePerSecondVariance"].asDouble());
		ui->doubleSpinBox_rotatevar->setValue(_dictionary["rotatePerSecondVariance"].asDouble());
		
		if (app->getParticle() != nullptr)
		{
			app->getParticle()->setStartRadius(_dictionary["maxRadius"].asDouble());
			app->getParticle()->setStartRadiusVar(_dictionary["maxRadiusVariance"].asDouble());
			app->getParticle()->setEndRadius(_dictionary["minRadius"].asDouble());
			app->getParticle()->setRotatePerSecond(_dictionary["rotatePerSecond"].asDouble());
			app->getParticle()->setRotatePerSecondVar(_dictionary["rotatePerSecondVariance"].asDouble());
		}
	}
	else
	{
		ui->frame_01->setVisible(false);
		ui->frame_2->setVisible(true);
		ui->comboBox_4->setCurrentIndex(0);

		ui->dial_speed->setValue(_dictionary["speed"].asDouble());
		ui->doubleSpinBox_speed->setValue(_dictionary["speed"].asDouble());
		ui->dial_speedVar->setValue(_dictionary["speedVariance"].asDouble());
		ui->doubleSpinBox_speedVar->setValue(_dictionary["speedVariance"].asDouble());
		ui->dial_gravityx->setValue(_dictionary["gravityx"].asDouble());
		ui->doubleSpinBox_gravityx->setValue(_dictionary["gravityx"].asDouble());
		ui->dial_gravityy->setValue(_dictionary["gravityy"].asDouble());
		ui->doubleSpinBox_gravityy->setValue(_dictionary["gravityy"].asDouble());
		ui->dial_radial->setValue(_dictionary["radialAcceleration"].asDouble());
		ui->doubleSpinBox_radial->setValue(_dictionary["radialAcceleration"].asDouble());
		ui->dial_radialvar->setValue(_dictionary["radialAccelVariance"].asDouble());
		ui->doubleSpinBox_radialvar->setValue(_dictionary["radialAccelVariance"].asDouble());
		ui->dial_tangential->setValue(_dictionary["tangentialAcceleration"].asDouble());
		ui->doubleSpinBox_tangential->setValue(_dictionary["tangentialAcceleration"].asDouble());
		ui->dial_tangvar->setValue(_dictionary["tangentialAccelVariance"].asDouble());
		ui->doubleSpinBox_tangvar->setValue(_dictionary["tangentialAccelVariance"].asDouble());
		
		if (app->getParticle() != nullptr)
		{
			app->getParticle()->setSpeed(_dictionary["speed"].asDouble());
			app->getParticle()->setSpeedVar(_dictionary["speedVariance"].asDouble());
			app->getParticle()->setGravity(Vec2(_dictionary["gravityx"].asDouble(), _dictionary["gravityy"].asDouble()));
			app->getParticle()->setRadialAccel(_dictionary["radialAcceleration"].asDouble());
			app->getParticle()->setRadialAccelVar(_dictionary["radialAccelVariance"].asDouble());
			app->getParticle()->setTangentialAccel(_dictionary["tangentialAcceleration"].asDouble());
			app->getParticle()->setTangentialAccelVar(_dictionary["tangentialAccelVariance"].asDouble());
		}
	}
}

void Databind::setParticleTexture(ValueMap &dictionary)
{
	std::string dirname = _dirname.toStdString();
	std::string textureName = dictionary["textureFileName"].asString();
	size_t rPos = textureName.rfind('/');
	if (rPos != std::string::npos)
	{
		std::string textureDir = textureName.substr(0, rPos + 1);

		if (!dirname.empty() && textureDir != dirname)
		{
			textureName = textureName.substr(rPos + 1);
			textureName = dirname + textureName;
		}
	}
	else if (!dirname.empty() && !textureName.empty())
	{
		textureName = dirname + textureName;
	}
	Texture2D *tex = nullptr;
	_textureKey = QString::fromStdString(textureName);
	if (dictionary.find("textureImageData") != dictionary.end())
	{
		unsigned char *buffer = nullptr;
		unsigned char *deflated = nullptr;
		std::string textureData = dictionary.at("textureImageData").asString();
		if (textureData.empty()) return;
		auto dataLen = textureData.size();
		int decodeLen = base64Decode((unsigned char*)textureData.c_str(), (unsigned int)dataLen, &buffer);
		if (buffer == nullptr) return;
		ssize_t deflatedLen = ZipUtils::inflateMemory(buffer, decodeLen, &deflated);
		this->setTextureByData(deflated, deflatedLen);
	}
	else if ( textureName.length() > 0)
	{
		Director::getInstance()->getTextureCache()->removeTextureForKey(textureName);
		// set not pop-up message box when load image failed
		bool notify = FileUtils::getInstance()->isPopupNotify();
		FileUtils::getInstance()->setPopupNotify(false);
		tex = Director::getInstance()->getTextureCache()->addImage(textureName);
		// reset the value of UIImage notify
		FileUtils::getInstance()->setPopupNotify(notify);
		this->setTextureByPath(_textureKey);
	}
}

void Databind::setTextureByData(unsigned char *data, ssize_t dataLen)
{
	QImage *qimage = new QImage();
	if (!qimage->loadFromData(data, dataLen))
	{
		delete qimage;
		return;
	}
	QRect rect = ui->label_86->geometry();
	if (qimage->width() > rect.width() || qimage->height() > rect.height())
		*qimage = qimage->scaled(rect.width(), rect.height(), Qt::KeepAspectRatio);
	ui->label_86->setPixmap(QPixmap::fromImage(*qimage));
	delete qimage;
	auto image = new (std::nothrow) Image();
	bool isOK = image->initWithImageData(data, dataLen);
	auto texture = Director::getInstance()->getTextureCache()->addImage(image, _textureKey.toStdString());
	_currentImage = image;
	ParticleSystemQuad *particle = (ParticleSystemQuad*)app->getParticle();
	if (particle == nullptr) return;
	particle->setTexture(texture);
}

void Databind::setTextureByPath(QString &path)
{
	if (_textureKey == path)return;
	_textureKey = path;
	QImage *image = new QImage();
	if (!image->load(path)){ delete image; return; }
	QRect rect = ui->label_86->geometry();
	if (image->width() > rect.width() || image->height() > rect.height())
		*image = image->scaled(rect.width(), rect.height(), Qt::KeepAspectRatio);
	ui->label_86->setPixmap(QPixmap::fromImage(*image));
	delete image;
	ParticleSystemQuad *particle = (ParticleSystemQuad*)app->getParticle();
	if (particle == nullptr) return;
	auto tex = Director::getInstance()->getTextureCache()->addImage(path.toStdString());
	particle->setTexture(tex);
	if (_currentImage != nullptr)
	{
		_currentImage->release();
		_currentImage = nullptr;
	}
}


int Databind::getBlendFunIdx(GLenum blend)
{
	for (int i = 0; i < sizeof(_gBlendFuncs) / sizeof(GLenum); i++)
	{
		if (_gBlendFuncs[i] == blend)
		{
			return i;
		}
	}
	return 0;
}

void Databind::savePlist(QString &path, QString &plist, QString &texture, bool mode)
{
	_savePlistPath = path;
	_plistFileName = plist;
	_textureFileName = texture;
	_mode = mode;
	
	ValueMap dictionary;
	dictionary["angle"] = (float)ui->doubleSpinBox_14->value();
	dictionary["angleVariance"] = (float)ui->doubleSpinBox_15->value();
	dictionary["blendFuncDestination"] = (int)_gBlendFuncs[ui->comboBox_2->currentIndex()];
	dictionary["blendFuncSource"] = (int)_gBlendFuncs[ui->comboBox->currentIndex()];
	dictionary["duration"] = (float)ui->doubleSpinBox->value();
	dictionary["emitterType"] = (float)ui->comboBox_4->currentIndex();

	dictionary["finishColorAlpha"] = (float)(ui->horizontalScrollBar_12->value() / 255.0);
	dictionary["finishColorBlue"] = (float)(ui->horizontalScrollBar_11->value() / 255.0);
	dictionary["finishColorGreen"] = (float)(ui->horizontalScrollBar_10->value() / 255.0);
	dictionary["finishColorRed"] = (float)(ui->horizontalScrollBar_9->value() / 255.0);

	dictionary["finishColorVarianceAlpha"] = (float)(ui->horizontalScrollBar_16->value() / 255.0);
	dictionary["finishColorVarianceBlue"] = (float)(ui->horizontalScrollBar_15->value() / 255.0);
	dictionary["finishColorVarianceGreen"] = (float)(ui->horizontalScrollBar_14->value() / 255.0);
	dictionary["finishColorVarianceRed"] = (float)(ui->horizontalScrollBar_13->value() / 255.0);

	dictionary["finishParticleSize"] = (float)ui->doubleSpinBox_7->value();
	dictionary["finishParticleSizeVariance"] = (float)ui->doubleSpinBox_8->value();

	dictionary["gravityx"] = (float)ui->doubleSpinBox_gravityx->value();
	dictionary["gravityy"] = (float)ui->doubleSpinBox_gravityy->value();

	dictionary["maxParticles"] = (float)ui->doubleSpinBox_2->value();
	dictionary["maxRadius"] = (float)ui->doubleSpinBox_maxr->value();
	dictionary["maxRadiusVariance"] = (float)ui->doubleSpinBox_maxrv->value();
	dictionary["minRadius"] = (float)ui->doubleSpinBox_minr->value();
	dictionary["particleLifespan"] = (float)ui->doubleSpinBox_3->value();
	dictionary["particleLifespanVariance"] = (float)ui->doubleSpinBox_4->value();
	dictionary["radialAccelVariance"] = (float)ui->doubleSpinBox_radialvar->value();
	dictionary["radialAcceleration"] = (float)ui->doubleSpinBox_radial->value();
	dictionary["rotatePerSecond"] = (float)ui->doubleSpinBox_rotate->value();
	dictionary["rotatePerSecondVariance"] = (float)ui->doubleSpinBox_rotatevar->value();
	dictionary["sourcePositionVariancex"] = (float)ui->doubleSpinBox_x->value();
	dictionary["sourcePositionVariancey"] = (float)ui->doubleSpinBox_y->value();
	dictionary["sourcePositionx"] = (float)app->getParticle()->getPositionX() - 180;
	dictionary["sourcePositiony"] = (float)app->getParticle()->getPositionY() - 100;
	dictionary["speed"] = (float)ui->doubleSpinBox_speed->value();
	dictionary["speedVariance"] = (float)ui->doubleSpinBox_speedVar->value();

	dictionary["startColorAlpha"] = (float)(ui->horizontalScrollBar_20->value() / 255.0);
	dictionary["startColorBlue"] = (float)(ui->horizontalScrollBar_19->value() / 255.0);
	dictionary["startColorGreen"] = (float)(ui->horizontalScrollBar_18->value() / 255.0);
	dictionary["startColorRed"] = (float)(ui->horizontalScrollBar_17->value() / 255.0);

	dictionary["startColorVarianceAlpha"] = (float)(ui->horizontalScrollBar_24->value() / 255.0);
	dictionary["startColorVarianceBlue"] = (float)(ui->horizontalScrollBar_23->value() / 255.0);
	dictionary["startColorVarianceGreen"] = (float)(ui->horizontalScrollBar_22->value() / 255.0);
	dictionary["startColorVarianceRed"] = (float)(ui->horizontalScrollBar_21->value() / 255.0);

	dictionary["startParticleSize"] = (float)ui->doubleSpinBox_5->value();
	dictionary["startParticleSizeVariance"] = (float)ui->doubleSpinBox_6->value();
	dictionary["tangentialAccelVariance"] = (float)ui->doubleSpinBox_tangvar->value();
	dictionary["tangentialAcceleration"] = (float)ui->doubleSpinBox_tangential->value();
	dictionary["textureFileName"] = std::string(texture.toUtf8());

	dictionary["rotationStart"] = (float)ui->doubleSpinBox_16->value();
	dictionary["rotationEndVariance"] = (float)ui->doubleSpinBox_19->value();
	dictionary["rotationStartVariance"] = (float)ui->doubleSpinBox_17->value();
	dictionary["rotationEnd"] = (float)ui->doubleSpinBox_18->value();
	if (!mode)
	{
		if (_currentImage)
		{
			std::string fullPath = (path + "/" + texture).toUtf8();
			_currentImage->saveToFile(fullPath, false);
		}
		else
		{
			this->copyFile(_textureKey,  path + "/" + texture, true);
		}
	}
	else
	{
		if (_currentImage)
		{
			dictionary["textureImageData"] = this->_dictionary["textureImageData"];
		}
		else
		{
			unsigned char *buffer;
			char *result;
			std::string texturePath = _textureKey.toUtf8();
			Data fileData = FileUtils::getInstance()->getDataFromFile(texturePath);
			unsigned char *data = fileData.getBytes();
			ssize_t size = fileData.getSize();
			ssize_t bufferLen = ZipUtils::deflateMemory(data, size, &buffer);
			ssize_t resultLen = base64Encode(buffer, bufferLen, &result);
			if (buffer != nullptr)
			{
				free(buffer);
				buffer = nullptr;
			}
			dictionary["textureImageData"] = result;
			if (result != nullptr)
			{
				free(result);
				result = nullptr;
			}
			
		}
	}
	std::string plistPath = (const char*)((_savePlistPath + "/" + _plistFileName).toLocal8Bit());
	FileUtils::getInstance()->writeToFile(dictionary, plistPath);
	_isSaved = true;
}

bool Databind::copyFile(QString source, QString target, bool isExist)
{
	target.replace("\\", "/");
	if (source == target){
		return true;
	}
	if (!QFile::exists(source)){
		return false;
	}
	QDir *createfile = new QDir;
	bool exist = createfile->exists(target);
	if (exist){
		if (isExist){
			createfile->remove(target);
		}
	}//end if  

	if (!QFile::copy(source, target))
	{
		return false;
	}
	return true;
}

void Databind::selectExample(QString fileName)
{
	QDir dir("./plists");
	QString path = dir.absolutePath();
	QString filePath = path + "/" + fileName;
	this->setPlistFile(filePath, true, true);
}

void Databind::bindExample()
{
	QDir dir("./plists");
	QString path = dir.absolutePath();
	dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
	dir.setSorting(QDir::Name);
	QFileInfoList list = dir.entryInfoList();
	for (int i = 0; i < list.size(); i++)
	{
		QFileInfo fileInfo = list.at(i);
		QString fileName = fileInfo.fileName();
		QAction *action = new QAction(fileName, ui->menu_Example);
		ui->menu_Example->addAction(action);
		QObject::connect(action, SIGNAL(triggered()), app, SLOT(processExample()));
	}
	this->showHistoryMenu();
}

void Databind::showHistoryMenu()
{
	//history
	_history.clear();
	ui->menu_History->clear();
	QSettings settings("ParticleEdit.ini", QSettings::IniFormat);
	QStringList stringList = settings.value("history/openPaths").toStringList();
	for (int i = stringList.size() - 1; i >= 0; i--)
	{
		QString historyPath = stringList.at(i);
		QFileInfo fileInfo(historyPath);
		QString fileName = fileInfo.fileName();
		QAction *action = new QAction(fileName, ui->menu_History);
		action->setData(historyPath);
		ui->menu_History->addAction(action);
		_history.push_front(historyPath);
		QObject::connect(action, SIGNAL(triggered()), app, SLOT(processHistory()));
	}
	if (stringList.size() > 0)
	{
		ui->menu_History->addSeparator();
		QAction *action = new QAction(QObject::tr("Clear &Menu"), ui->menu_History);
		ui->menu_History->addAction(action);
		ui->menu_History->menuAction()->setVisible(true);
		QObject::connect(action, SIGNAL(triggered()), app, SLOT(processHistory()));
	}
	else
	{
		ui->menu_History->menuAction()->setVisible(false);
	}
}