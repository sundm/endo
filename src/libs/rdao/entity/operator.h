#pragma once

#include "enums.h"
#include <QDateTime>

struct Operator
{
	int id;
	QString name;
	QString phone;
	Rt::Gender gender;
	Rt::Status status;
	Rt::Role role;

	Operator() :
		id(-1),
		gender(Rt::Gender::Unknown),
		status(Rt::Status::Normal),
		role(Rt::Role::Unknown),
	{ }
};
