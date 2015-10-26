#ifndef __ABOUTDIALOG_H__
#define __ABOUTDIALOG_H__

#include <QtWidgets/QMainWindow>
#include <qdialog.h>
#include "ui_dialog_about.h"
#include "cocos2d.h"
using namespace cocos2d;

class AboutDialog: public QDialog
{
public:
	explicit AboutDialog(QWidget *parent = 0);
	~AboutDialog();

private:
	Ui::Dialog_About ui;
};

#endif