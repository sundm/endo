#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_flowdash.h"

class flowdash : public QMainWindow
{
	Q_OBJECT

public:
	flowdash(QWidget *parent = Q_NULLPTR);

private:
	Ui::flowdashClass ui;
};
