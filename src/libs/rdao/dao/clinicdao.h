#pragma once

#include "../rdao_global.h"
#include "../entity/enums.h"
#include <rcore/result.h>

struct Operator;
struct Endoscope;
struct Patient;
struct CommonResult;

class RDAO_EXPORT ClinicDao
{
public:
	result_t addClinicUse(const Endoscope &esp, const Operator &op, const Patient &patient);
	
	result_t updateUseRemark(const Endoscope &esp, const QString &remark);

	result_t addPreprocess(const Endoscope &esp, const Operator &op);

	result_t updatePreprocessResult(const Endoscope &esp, const CommonResult &result);

private:

};