#pragma once

#include "enums.h"
#include <QString>
#include <QDateTime>
#include "endoscope.h"

struct Program {
	int id;
	Rt::MachineProgramCategory category;
	QString name;
	QString remark;

	Program() : category(Rt::MachineProgramCategory::Unknown) {}
};

struct Machine {
	unsigned id;
	QString name;
	Rt::MachineCategory category;
	Rt::MachineStatus status;
	int cycleToday;
	int cycleTotal;
	QDate productionDate;
	QDateTime lastMaintainTime;
	unsigned maintainCycle;
	QList<Program> programs;

	Machine() :
		id(0),
		category(Rt::MachineCategory::Unknown),
		status(Rt::Idle),
		cycleToday(-1),
		cycleTotal(-1),
		maintainCycle(0)
	{}
};