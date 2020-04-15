#pragma once

#include "enums.h"
#include <QString>

struct Reader
{
	QString udi;
	QString name;
	QString sn;
	
	Rt::Status status;
	Rt::ReaderCategory category;
	QString remark;
	Reader() : category(Rt::ReaderCategory::Flow), status(Rt::Status::Normal) {}
};