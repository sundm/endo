#include <QVariant>
#include <QSqlError>
#include <QCryptographicHash>
#include "debugsqlquery.h"
#include "operatordao.h"
#include "entity/enums.h"
#include "errors.h"
#include "entity/operator.h"

namespace {
	QString encodePwd(const QString &pwd)
	{
		QByteArray sha1 = QCryptographicHash::hash(pwd.toLocal8Bit(), QCryptographicHash::Sha1);
		return QString(sha1.toHex());
	}
}


result_t OperatorDao::login(const QString &udi, const QString &pwd, Operator *op/* = Q_NULLPTR*/)
{
	QSqlQuery query;
	query.prepare("select * from t_operator where udi = ? and pwd = ?");
	query.addBindValue(udi);
	query.addBindValue(encodePwd(pwd));
	if (!query.exec())
		return kErrorDbUnreachable;

	if (!query.first())
		return "用户UDI或密码不正确";

	if (op) {
		op->udi = udi;
		op->name = query.value(3).toString();
		op->phone = query.value(4).toString();
		op->gender = static_cast<Rt::Gender>(query.value(5).toInt());
		op->status = static_cast<Rt::Status>(query.value(6).toInt());
		op->role = static_cast<Rt::Role>(query.value(7).toInt());
	}

	return 0;
}

result_t OperatorDao::login(const QString &udi, Operator *op/* = Q_NULLPTR*/)
{
	QSqlQuery query;
	query.prepare("select * from t_operator where udi = ?");
	query.addBindValue(udi);

	if (!query.exec())
		return kErrorDbUnreachable;

	if (!query.first())
		return "用户UDI不正确";

	if (op) {
		op->udi = udi;
		op->name = query.value(3).toString();
		op->phone = query.value(4).toString();
		op->gender = static_cast<Rt::Gender>(query.value(5).toInt());
		op->status = static_cast<Rt::Status>(query.value(6).toInt());
		op->role = static_cast<Rt::Role>(query.value(7).toInt());
	}

	return 0;
}

void OperatorDao::logout(const QString &udi)
{
	// TODO
}

result_t OperatorDao::changePassword(const QString &udi, const QString &oldPwd, const QString &newPwd)
{
	QSqlQuery query;
	query.prepare("UPDATE t_operator SET pwd = ? WHERE udi = ? and pwd = ?");
	query.addBindValue(encodePwd(newPwd));
	query.addBindValue(udi);
	query.addBindValue(encodePwd(oldPwd));
	if (!query.exec())
		return kErrorDbUnreachable;
	if (1 != query.numRowsAffected())
		return "原密码不正确";

	return 0;
}

result_t OperatorDao::changeStatus(const QString &udi, Rt::Status status)
{
	QSqlQuery query;
	query.prepare("UPDATE t_operator SET status = ? WHERE udi = ?");
	query.addBindValue(status);
	query.addBindValue(udi);
	if (!query.exec())
		return kErrorDbUnreachable;
	if (1 != query.numRowsAffected())
		return "原密码不正确";

	return 0;
}