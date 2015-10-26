#ifndef QTAPPLICATION_H
#define QTAPPLICATION_H

#include <QtWidgets/QMainWindow>
#include "ui_qtapplication.h"
#include "cocos2d.h"
using namespace cocos2d;

class Databind;
class QtApplication : public QMainWindow
{
	Q_OBJECT

public:
	QtApplication(QWidget *parent = 0);
	~QtApplication();

	void initScene();
	void setGLView(QWidget *glWidget);
	ParticleSystem* getParticle() const;
	LayerColor* getLayer() const;
	Databind* getDataBind()const{ return _dataBind; };
	void closeWindow();
	bool showExitDialog();
	void setSaveMode(bool mode);
	void setUpdateState(bool isUpdate);

public slots:
	void processBtnEvent();
	void processDialEvent(int val);
	void processBoxEvent(double val);
	void processComboBoxEvent(int val);
	void processBarEvent(int val);
	void processExample();
	void processHistory();
	void processColorEvent();

protected:
	void closeEvent(QCloseEvent *event);
	virtual void keyPressEvent(QKeyEvent *);
	virtual void wheelEvent(QWheelEvent *);

	void bindSignalSlot();
	void showSaveFileDialog(int tag);

private:
	Ui::QtApplicationClass ui;
	QWidget			*_glWidget;
	Databind		*_dataBind;
	bool			_isUpdate;
	QString			_applicationName;
	QString			_lastSaveFileName;
	bool			_lastSaveMode;
};

#endif // QTAPPLICATION_H
