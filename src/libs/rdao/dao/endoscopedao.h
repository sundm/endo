#pragma once

#include "../rdao_global.h"
#include "../entity/endoscope.h"
#include <rcore/result.h>

class RDAO_EXPORT EndoscopeDao
{
public:

	result_t getEndoscope(const QString &udi,Endoscope* endoscope);

	/**
	 * Add a fresh endoscope.
	 * @param Endoscope: the endoscope to be added
	 * @return a result_t object
	 */
	result_t addEndoscope(const Endoscope &endoscope);

	/**
	 * Update endoscope maintain date.
	 * @param maintainDate: the date to be updated
	 * @return a result_t object
	 */
	result_t updateMaintainDate(const QDate &maintainDate);

	result_t setPhoto(const QString& udi, const QString& photo);
	result_t getPhoto(const QString& udi, QString *photo);

	result_t setStatus(const QString& udi, const Rt::Status &status);
	result_t getStatus(const QString& udi, Rt::Status *status);
};