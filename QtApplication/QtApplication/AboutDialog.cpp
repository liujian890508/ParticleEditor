#include "AboutDialog.h"


AboutDialog::AboutDialog(QWidget *parent)
:QDialog(parent)
{
	ui.setupUi(this);
	this->setModal(true);
}


AboutDialog::~AboutDialog()
{
}
