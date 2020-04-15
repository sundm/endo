#pragma once

#include "../rdao_global.h"
#include <rcore/result.h>

class Operator;
class RDAO_EXPORT OperatorDao
{
public:
	result_t login(int id, const QString &pwd, Operator *op = Q_NULLPTR);
	void logout(int id);

	result_t addOperator(const Operator &op);
	result_t changePassword(int id, const QString &oldPwd, const QString &newPwd);
	result_t frozen(int id);
	result_t unfreeze(int id);
};