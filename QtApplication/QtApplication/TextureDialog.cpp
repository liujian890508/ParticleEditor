#include "TextureDialog.h"
#include "qmessagebox.h"
#include "qtapplication.h"
#include "Databind.h"
#include <QSettings>

TextureDialog::TextureDialog(QtApplication *parent)
: QDialog(parent)
, _mainWin(parent)
, _isCloseMain(false)
{
	ui.setupUi(this);
	this->setModal(true);

	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(processBtnEvent()));
}

 
TextureDialog::~TextureDialog()
{
}

void TextureDialog::setTextureName(QString name)
{
	_textureFileName = name;
	ui.lineEdit->setText(name);
}

void TextureDialog::setPlistInfo(QString path, QString plist)
{
	_path = path;
	_plistFileName = plist;
}

void TextureDialog::setCloseMainTag(bool isClose)
{
	this->_isCloseMain = isClose;
}

void TextureDialog::processBtnEvent()
{
	_mode = ui.radioButton->isChecked();
	_mainWin->setSaveMode(_mode);
	_mainWin->setUpdateState(false);
	_textureFileName = ui.lineEdit->text();
	_mainWin->getDataBind()->savePlist(_path, _plistFileName, _textureFileName, _mode);
	this->hide();
	QSettings settings("ParticleEdit.ini", QSettings::IniFormat);
	settings.beginGroup("path");
	settings.setValue("savePath", _path);
	settings.endGroup();
	if (this->_isCloseMain)
	{
		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, tr("Exit"), "Has saved, is closed?", QMessageBox::Yes | QMessageBox::No);
		if (reply == QMessageBox::Yes)
		{
			_mainWin->close();
		}
	}
}
