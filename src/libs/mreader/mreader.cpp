#include "mreader.h"
#include <QtNetwork>
#include <qhash.h>
QUdpSocket *uSocket;

QStringList hostList;
const int MAX_CONNECT_COUNT = 1024;
QHash<int,int> readerMap;

QByteArray  intToByte(int i)
{
	QByteArray abyte0;
	abyte0.resize(4);
	abyte0[0] = (uchar)(0x000000ff & i);
	abyte0[1] = (uchar)((0x0000ff00 & i) >> 8);
	abyte0[2] = (uchar)((0x00ff0000 & i) >> 16);
	abyte0[3] = (uchar)((0xff000000 & i) >> 24);
	return abyte0;
}

void BcdToAscii(unsigned char *lpAscii, const unsigned char *lpBcd, int nLength)
{
	int i;

	for (i = 0; i < nLength; i++)
	{
		lpAscii[i] = '0' + ((i % 2) ? lpBcd[i / 2] % 16 : lpBcd[i / 2] / 16);
		lpAscii[i] = (lpAscii[i] > '9') ? lpAscii[i] - '9' + 'A' - 1 : lpAscii[i];
	}
	return;
}

int AsciiToBcd(const unsigned char *lpAscii, unsigned char *lpBcd, int nLength)
{
	int i;
	unsigned char cAscii;

	for (i = 0; i < nLength; i++)
	{
		if (isxdigit(lpAscii[i]) == 0)
			return -200;
		cAscii = (lpAscii[i] >= 'a') ? lpAscii[i] - 'a' + 'A' : lpAscii[i];
		cAscii = (lpAscii[i] >= 'A') ? lpAscii[i] - 'A' + '9' + 1 : lpAscii[i];
		lpBcd[i / 2] = (i % 2) ? (lpBcd[i / 2] | (cAscii - '0')) : ((cAscii - '0') << 4);
	}
	return 0;
}

MReader::MReader(QObject *parent)
{
	uSocket = new QUdpSocket();
	uSocket->bind(QHostAddress::Any, 39169);
	connect(uSocket, SIGNAL(readyRead()), this, SLOT(receiveData()));

	readerMap.clear();
}

void MReader::getIPList(const int msc /* = 2000*/)
{
	hostList.clear();

	QByteArray msg = intToByte(165);
	uSocket->writeDatagram(msg, QHostAddress("255.255.255.255"), 39169);

	if (NULL == m_timer)
		m_timer = new QTimer();

	m_timer->setSingleShot(false);

	m_timer->start(msc);

	connect(m_timer, SIGNAL(timeout()), this, SLOT(getIPTimeout()));
}

void MReader::getIPTimeout()
{
	if (m_timer->isActive())
		m_timer->stop();

	qDebug() << hostList;
	
	emit sendIPList(hostList);
}

void MReader::receiveData()
{
	QByteArray ba;
	while (uSocket->hasPendingDatagrams())
	{
		ba.resize(uSocket->pendingDatagramSize());
		QHostAddress host;
		uSocket->readDatagram(ba.data(), ba.size(), &host);
		
		processData(ba.data());
	}
}

void MReader::processData(char * data)
{
	if (data[0] == (char)0xc1)
	{
		//data[1]~data[4]为IP地址
		QString address = QString("%1.%2.%3.%4").arg((unsigned char)data[1])
			.arg((unsigned char)data[2])
			.arg((unsigned char)data[3])
			.arg((unsigned char)data[4]);

		//data[5]~data[6]为机器号]
		int readerNo = 0;
		readerNo = (unsigned char)data[5] + (unsigned char)data[6] * 256;
		
		//data[7]~data[8]为数据包序列号
		QString dataNoStr = QString("%1").arg((unsigned char)data[7] + (unsigned char)data[8] * 256);
		int dataNo = dataNoStr.toInt();
		
		if (readerMap.contains(readerNo) && readerMap.value(readerNo) >= dataNo)
			return;
		else
		{
			readerMap.remove(readerNo);
			readerMap.insert(readerNo, dataNo);
		}

		//data[10]~data[13]为数据,IC卡号.
		unsigned long cardNo;
		cardNo = (unsigned char)data[13] * 256 * 256 * 256 
				+ (unsigned char)data[12] * 256 * 256 
				+ (unsigned char)data[11] * 256
				+ (unsigned char)data[10];

		QString data = QString("%1").arg(cardNo, 10, 10, QLatin1Char('0'));

		qDebug() << "readerNo:" << readerNo;
		qDebug() << "dataNo:" << dataNo;
		qDebug() << "cardNo:" << data;

		emit sendData(readerNo, data);
	}
	else if (data[0] == (char)0xf1)
	{
		QString address = QString("%1.%2.%3.%4").arg((unsigned char)data[1])
			.arg((unsigned char)data[2])
			.arg((unsigned char)data[3])
			.arg((unsigned char)data[4]);

		hostList.append(address);
	}
	else
	{
		qDebug() << "read data error!";
	}
}

//void MReader::processData(char * data)
//{
//	int length = int(data[0]);
//	if (length != 7)
//	{
//		qDebug() << "read data length error!";
//		return;
//	}
//
//	int adr = int(data[1]);
//	qDebug() << "read address: " << adr;
//
//	int status = int(data[3]);
//	if (0 == status)
//	{
//		unsigned char data_s[2], data_d[5] = { 0 };
//		memcpy(data_s, &data[4], 2);
//		BcdToAscii(data_d, data_s, 4);
//		QString str = QString(QLatin1String((char*)data_d));
//		qDebug() << str;
//		qDebug() << "---emit---";
//		emit sendData(adr, str);
//	}
//	else
//	{
//		qDebug() << "read data error!";
//	}
//}