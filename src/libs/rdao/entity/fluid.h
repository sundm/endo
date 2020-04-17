#pragma once

#include "enums.h"
#include <QString>

struct Fluid
{
	unsigned id;
	QString name;

	Rt::FluidCategory type;
	Rt::DisinfectCategory category;
	int ratedCount;

	QString desc;
	Fluid() : id(0), type(Rt::FluidCategory::Clean), ratedCount(0), category(Rt::DisinfectCategory::Unknown) {}
};