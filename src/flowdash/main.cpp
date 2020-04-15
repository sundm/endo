#include "flowdash.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	flowdash w;
	w.show();
	return a.exec();
}
