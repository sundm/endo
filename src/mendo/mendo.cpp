#include "mendo.h"
#include "mreader/mreader.h"

mendo::mendo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	MReader *reader = new MReader();
	reader->getIPList();
}
