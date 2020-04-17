#pragma once

#include "../rdao_global.h"
#include <rcore/result.h>
#include <QDate>

struct FlowHistory;
struct UseHistory;

class RDAO_EXPORT HistoryDao
{
public:
	result_t getFlowHistory(const QString &esp_udi, const QString &op_udi, 
							const QDate &form_date, const QDate &end_date, 
							FlowHistory *flow_history,
							int page = 1, int count = 10);

	result_t getUseHistory(const QString &esp_udi, const QString &op_udi,
							const QDate &form_date, const QDate &end_date,
							UseHistory *use_history,
							int page = 1, int count = 10);

};