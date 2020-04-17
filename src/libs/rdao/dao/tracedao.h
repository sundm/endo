#pragma once

#include "../rdao_global.h"
#include <rcore/result.h>

struct EndoscopeFlow;

class RDAO_EXPORT TraceDao
{
public:
	result_t getEndoscopeFlow(const QString & udi, int cycle, EndoscopeFlow *espflow);

	result_t getPatients(int patientId, QList<EndoscopeFlow> *espflows);


};