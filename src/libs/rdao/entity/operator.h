#pragma once

#include "enums.h"
#include <QString>

struct Operator
{
	QString udi;
	QString name;
	QString phone;
	Rt::Gender gender;
	Rt::Status status;
	Rt::Role role;

	Operator() :
		gender(Rt::Gender::Unknown),
		status(Rt::Status::Normal),
		role(Rt::Role::Unknown)	{ }
};
