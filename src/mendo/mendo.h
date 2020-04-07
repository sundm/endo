#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mendo.h"

class mendo : public QMainWindow
{
	Q_OBJECT

public:
	mendo(QWidget *parent = Q_NULLPTR);

private:
	Ui::mendoClass ui;
};
