#ifndef __TEXTUREDIALOG_H__
#define __TEXTUREDIALOG_H__

#include <QtWidgets/QMainWindow>
#include "ui_qtapplication.h"
#include <qdialog.h>
#include "ui_dialog_texture.h"
#include "cocos2d.h"
using namespace cocos2d;

class QtApplication;
class TextureDialog: public QDialog
{
	Q_OBJECT
public:
	explicit TextureDialog(QtApplication *parent = 0);
	~TextureDialog();

public:
	void setTextureName(QString name);
	void setPlistInfo(QString path, QString plist);
	void setCloseMainTag(bool isClose);

public slots:
	void processBtnEvent();

private:
	QtApplication *_mainWin;
	Ui::Dialog ui;
	QString _path;
	QString _plistFileName;
	QString _textureFileName;
	bool	_mode;
	bool	_isCloseMain;
};

#endif