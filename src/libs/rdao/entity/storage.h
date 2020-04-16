#pragma once

#include "enums.h"
#include <QString>

struct Locker
{
	int id;
	QString name;
	int max;
	int stored;
	Rt::Status status;
	QString remark;
	Locker() : max(5), stored(0), status(Rt::Status::Normal) {}
};