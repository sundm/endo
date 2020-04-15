#pragma once

#include "../rdao_global.h"
#include "../entity/fluid.h"
#include <rcore/result.h>

class RDAO_EXPORT FluidDao
{
public:
	result_t add(const Fluid &fluid);

	result_t get(int id, Fluid *fluid);

	result_t getAllFluids(QList<Fluid> *fluids);

};