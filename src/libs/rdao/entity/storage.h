#pragma once

#include "enums.h"
#include <QString>

struct Locker
{
	unsigned id;
	QString name;
	int max;
	Rt::Status status;
	QString remark;
	Locker() : id(0), max(5), status(Rt::Status::Normal) {}
};