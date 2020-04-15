#pragma once

#include "enums.h"
#include <QDate>

struct Endoscope
{
	QString udi;
	QString name;
	QString photo;
	QDate production_time;
	int service_year;
	QDate last_maintain_time;
	int maintain_cycle;
	Rt::EndoscopeCategory category;
	int cycle;
	Rt::FlowStatus status;
	QString remark;
	Endoscope() : cycle(0), status(Rt::FlowStatus::Unknown) {}
};
