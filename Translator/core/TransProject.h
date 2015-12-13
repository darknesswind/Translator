#pragma once
#include <QDir>

class TransProject
{
public:
	TransProject();
	~TransProject();

	bool create(QString name, QString path);
	bool open(QString filePath);
	bool save();

public:
	QString projectName() const { return m_name; }
	QString fullPath() const;

private:
	friend class ProjectIOAdapter;

private:
	QString m_name;
	QString m_path;
	QString m_srcRelPath;
	QString m_dstRelPath;

	QDir m_dirSource;
	QDir m_dirTarget;

	bool m_bInited;
};
