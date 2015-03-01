#ifndef __MysqlUtils__
#define __MysqlUtils__
#include <QtCore>
#include <QtSql>

#define _sqlUT MysqlUtils::getInstance()

class MysqlUtils{
public:
	static MysqlUtils* getInstance();
	MysqlUtils();

	//������Ϣ���
public:
	void PrintAllSql(QSqlQuery);

	//���ݿ�����ӿ�
public:
	void openDB();
	bool close();

	//ִ�нӿ�
public:
	QSqlQuery excuteCall(const char* format, ...);
	int excuteFunc(const char* format, ...);
	QSqlQuery excute(const char* format,...);
private:
	QSqlQuery excuteCall(QString);
	int excuteFunc(QString);
	QSqlQuery excute(QString);

	//��ʼ��
private:
	void init(QString);
	void initDatabase(QString _file);

	//���ݿ�����
private:
	static MysqlUtils* _instance;
	QSqlDatabase db;
	QString _database;
	QString _databaseName;
	QString _hostName;
	QString _username;
	QString _password;
};
#endif
