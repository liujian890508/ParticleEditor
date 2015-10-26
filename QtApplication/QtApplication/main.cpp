#include "qtapplication.h"
#include <QtWidgets/QApplication>
#include "cocos2d.h"
#include "AppDelegate.h"
#include "CocosQtPort\CCQGLView.h"
#include <qtranslator.h>
#include <QApplication>

int main(int argc, char *argv[])
{
	AppDelegate app(argc, argv);
	QString locale = QLocale::system().name();
	QTranslator translator;
	translator.load(QString("qtapplication_%1.qm").arg(locale));
	app.installTranslator(&translator);
	return cocos2d::CCQApplication::getInstance()->run();
}
