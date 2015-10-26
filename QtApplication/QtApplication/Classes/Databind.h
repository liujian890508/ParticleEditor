#ifndef __PLISTUTIL_H__
#define __PLISTUTIL_H__

#include <QtWidgets/QMainWindow>
#include "ui_qtapplication.h"
#include "cocos2d.h"
using namespace cocos2d;

static GLenum _gBlendFuncs[] =
{
	GL_ZERO,
	GL_ONE,
	GL_SRC_COLOR,
	GL_ONE_MINUS_SRC_COLOR,
	GL_SRC_ALPHA,
	GL_ONE_MINUS_SRC_ALPHA,
	GL_DST_COLOR,
	GL_ONE_MINUS_DST_COLOR,
	GL_DST_ALPHA,
	GL_ONE_MINUS_DST_ALPHA,
	GL_SRC_ALPHA_SATURATE
};

class QtApplication;
class Databind
{
public:
	Databind(QtApplication *app, Ui::QtApplicationClass *ui);
	~Databind();

	void setPlistFile(QString plistFile, bool isExample, bool isClearSave);

	int getBlendFunIdx(GLenum blend);

	void reset();

	void setTextureByPath(QString &path);
	void setTextureByData(unsigned char *data, ssize_t dataLen);

	inline bool isSaved() const { return _isSaved; }

	void savePlist(QString &path, QString &plist, QString &texture, bool mode);

	bool copyFile(QString source, QString target, bool isExist);

	void setParticleEmitter(ParticleSystem::Mode mode);

	void bindExample();

	void selectExample(QString fileName);

	void showHistoryMenu();

private:
	void setParticleProperties(ValueMap &dictionary);
	void setBlendFunc(ValueMap &dictionary);
	void setParticleColor(ValueMap &dictionary);
	void setParticleTexture(ValueMap &dictionary);
	void addHistoryPath(QString path);

private:
	QtApplication *app;
	Ui::QtApplicationClass *ui;
	ValueMap _dictionary;
	QString _plistFile;
	QString _dirname;
	QString _textureKey;
	bool _isSaved;

	QString _savePlistPath;
	QString _plistFileName;
	QString _textureFileName;
	bool _mode;

	Image		*_currentImage;
	QStringList  _history;
};

#endif