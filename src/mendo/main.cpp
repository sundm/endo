#include "mendo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	mendo w;
	w.show();
	return a.exec();
}
