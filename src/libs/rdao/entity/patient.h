#pragma once

#include "enums.h"
#include <QString>

struct Patient
{
	QString id;
	QString name;
	int age;
	Rt::Gender gender;

	Patient() :
		gender(Rt::Gender::Unknown){ }
};