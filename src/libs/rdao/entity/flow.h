#pragma once

#include "enums.h"
#include <QString>

struct CommonResult {
	Rt::Verdict result;
	QString remark;

	CommonResult() : result(Rt::Verdict::Default) {}
};