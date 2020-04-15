#pragma once

#include "../rdao_global.h"
#include "../entity/machine.h"
#include <rcore/result.h>

class RDAO_EXPORT MachineDao
{
public:
	result_t addMachine(const Machine &machine);

	result_t getMachine(int id, Machine *machine);

	result_t getAllMachines(QList<Machine> *machines,bool excludeForbidden = true);

	result_t stopMachine(int id);

	result_t getProgramsForMachine(int id, QList<Program> *programs);

	result_t getAllPrograms(QList<Program> *programs);

	result_t setStatus(int id, const Rt::Status &status);
	result_t getStatus(int id, Rt::Status *status);

private:
	result_t startMachine(int id);
};