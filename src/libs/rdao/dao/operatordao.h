#pragma once

#include "../rdao_global.h"
#include <rcore/result.h>

class Operator;
class RDAO_EXPORT OperatorDao
{
public:
	result_t login(const QString &udi, const QString &pwd, Operator *op = Q_NULLPTR);
	result_t login(const QString &udi, Operator *op = Q_NULLPTR);
	void logout(const QString &udi);

	result_t addOperator(const Operator &op);
	result_t getOperator(const QString &udi, Operator *op = Q_NULLPTR);

	result_t changePassword(const QString &udi, const QString &oldPwd, const QString &newPwd);
	result_t changeStatus(const QString &udi, Rt::Status status);
};