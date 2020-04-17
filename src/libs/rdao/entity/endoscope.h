#pragma once

#include "enums.h"
#include <QDate>

struct Endoscope
{
	QString udi;
	int cycle;
	QString name;
	QString photo;
	QDate production_time;
	int service_year;
	QDate last_maintain_time;
	int maintain_cycle;
	Rt::EndoscopeCategory category;
	Rt::FlowStatus status;
	int lockerId;
	QString remark;
	Endoscope() : cycle(0), lockerId(0), status(Rt::FlowStatus::Unknown) {}
};
