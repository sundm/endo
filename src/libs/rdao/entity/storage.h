#pragma once

#include "enums.h"
#include <QString>

struct Locker
{
	int id;
	QString name;
	int max;

	Rt::Status status;
	QString remark;
	Locker() : max(5), status(Rt::Status::Normal) {}
};