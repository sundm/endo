#pragma once

#include "enums.h"
#include <QDateTime>

struct EndoscopeFlow {
	struct _op_ {
		QString op;
		QDateTime startTime;
		QDateTime finishTime;
	};

	struct _machine_ {
		QString batchId;
		QString device;
		QString program;
		QString op;
		int cycleCount;
		int cycleTotal;
		
		_machine_() :cycleCount(0), cycleTotal(0) {}
	};

	struct SterilizeCheck {
		QString phyChecker;
		QString cheChecker;
		QString bioChecker;
		QDateTime phyCheckTime;
		QDateTime cheCheckTime;
		QDateTime bioCheckTime;
		Rt::SterilizeVerdict phyResult;
		Rt::SterilizeVerdict cheResult;
		Rt::SterilizeVerdict bioResult;
		SterilizeCheck() : phyResult(Rt::Unchecked), cheResult(Rt::Unchecked), bioResult(Rt::Unchecked) {}
	};

	struct Dispatch : public _optime_ {
		QString dept;
	};

	typedef struct _optime_ SurgerBind, SurgeryPreCheck, SurgeryPostCheck;

	struct Use {
		QString patientId;
		QString patientName;
		QString surgeryName;
		QDateTime surgeryTime;
		// TODO: surgeryId?
		int surgeryId = 0;
	};

	Rt::FlowStatus status = Rt::UnknownFlowStatus;
	bool isRecalled = false;
	Wash wash;
	Pack pack;
	Sterilize ster;
	SterilizeCheck sterCheck;
	Dispatch dispatch;
	SurgerBind bind;
	Use use;
	SurgeryPreCheck preCheck;
	SurgeryPostCheck postCheck;
};