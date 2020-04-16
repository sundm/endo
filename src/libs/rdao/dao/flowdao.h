#pragma once

#include "../rdao_global.h"
#include "../entity/enums.h"
#include <rcore/result.h>

struct Operator;
struct Endoscope;
struct CommonResult;
struct WashResult;
struct Fluid;
struct Program;
struct MachineWashResult;
struct DisinfectResult;
struct Locker;

class RDAO_EXPORT FlowDao
{
public:

	result_t addBind(const QString &esp_udi, const QString &op_udi, Endoscope *esp, Operator *op);

	result_t addLeak(const Endoscope &esp);

	result_t updateLeakResult(const Endoscope &esp, const CommonResult &result);

	result_t addWash(const Endoscope &esp, const Fluid &fluid);

	result_t updateWashResult(const Endoscope &esp, const Fluid &fluid, const WashResult &result);

	result_t addRinse(const Endoscope &esp, Rt::RinseType rise = Rt::RinseType::Begin);

	result_t updateRinseResult(const Endoscope &esp, const CommonResult &result, Rt::RinseType rise = Rt::RinseType::Begin);

	result_t addMachineWash(int machineId, const Program &program, const Endoscope &esp);

	result_t updateMachineWashResult(const Endoscope &esp, const MachineWashResult &result);

	result_t addDisinfect(const Endoscope &esp, const Fluid &fluid);

	result_t updateDisinfectResult(const Endoscope &esp, const Fluid &fluid, const DisinfectResult &result);

	result_t addDry(const Endoscope &esp);

	result_t updateDryResult(const Endoscope &esp, const CommonResult &result);

	result_t addStorage(const Endoscope &esp, const Locker &locker);

	result_t updateStorageResult(const Endoscope &esp, const CommonResult &result);
private:

};
