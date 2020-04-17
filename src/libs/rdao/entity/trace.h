#pragma once

#include "enums.h"
#include "patient.h"
#include <QDateTime>


struct EndoscopeFlow {
	struct _common_
	{
		QString udi;
		QString name;
		int cycle;
		int category;	//0:manual; 1:with machine
	};

	struct _op_ {
		QString op_udi;
		QString op_name;
	};

	struct _preprocess_ {
		_op_ pre_op;
		QDateTime pre_time;
		int pre_result;
		QString pre_remark;
	};

	QDateTime bindTime;

	struct _leak_
	{
		QDateTime leak_time;
		int leak_result;
		QString leak_remark;
	};

	struct _clean_
	{
		unsigned clean_id;
		QString clean_name;
		QDateTime clean_time;
		
		int clean_method;
		int clean_result;
		QString clean_remark;
	};

	struct _rinse_
	{
		QDateTime rinse_time;
		int rinse_result;
		QString rinse_remark;
	};

	struct _machine_ {
		unsigned machine_id;
		QString machine_name;
		QDateTime leamachine_timek_time;
		int machine_result;
		QString machine_remark;
	};

	struct _disinfect_
	{
		unsigned disinfect_id;
		QString disinfect_name;
		QDateTime disinfect_time;

		int disinfect_method;
		int disinfect_result;
		QString disinfect_remark;
	};

	struct _end_rinse_
	{
		QDateTime end_rinse_time;
		int end_rinse_result;
		QString end_rinse_remark;
	};

	struct _dry_
	{
		QDateTime dry_time;
		QString dry_remark;
	};

	struct _storage_
	{
		unsigned storage_id;
		QString storage_name;
		QDateTime storage_time;
		QString storage_remark;
	};

	struct _use_
	{
		_op_ use_op;
		Patient use_pt;
		QDateTime use_time;
		QString use_remark;
	};
};