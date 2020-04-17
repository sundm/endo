#pragma once

#include "enums.h"
#include <QList>
#include <QString>
#include <QDateTime>

struct FlowItem {
	QDate flow_date;
	QString esp_name;
	QString op_name;
	QString step_name;

	QDateTime start_time;
	QDateTime end_time;

	QString remark;
};

struct UseItem {
	QDate use_date;
	QDateTime use_time;
	QString esp_name;
	QString op_name;
	QString step_name;

	QString patient_name;
	QString patient_id;

	QString remark;
};

struct FlowHistory {
	int total_page;
	int current_page;
	int count;

	QList<FlowItem> flows;
};

struct UseHistory {
	int total_page;
	int current_page;
	int count;

	QList<UseItem> flows;
};

struct EspStatistics {
};

struct OpStatistics {
};