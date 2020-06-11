#pragma once

#include "mreader_global.h"
#include <QtCore>
#include <QString>

class MREADER_EXPORT MReader : public QObject
{
	Q_OBJECT
public:
	MReader(QObject *parent = nullptr);
	void getIPList(const int msc = 2000);
Q_SIGNALS:
	void sendData(const int address, const QString &data);
	void sendIPList(const QStringList& ips);

private slots:
	void receiveData();
	void getIPTimeout();
private:
	QTimer *m_timer = nullptr;
	void processData(char * data);
};
