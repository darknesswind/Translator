#pragma once
#include <QDir>
#include "TransFile.h"

typedef std::vector<TransFile> TranslateFiles;

class FileFilterBase;
class TransProject
{
public:
	TransProject();
	~TransProject();

	bool create(const QString& name, const QString& path);
	bool open(const QString& filePath);
	bool save();

	void refreshFilter();
	void refreshSource();

public:
	QString projectName() const { return m_name; }
	QString projctPath() const { return m_path; }
	QDir sourceDir() const;
	QString fullPath() const;
	const TranslateFiles& transFiles() const { return m_transFiles; }

public:
	void installFilter(FilterPtr spFilter);

private:
	friend class ProjectIOAdapter;

private:
	QString m_name;
	QString m_path;
	QString m_srcRelPath;
	QString m_dstRelPath;

	std::vector<FilterPtr> m_filters;
	TranslateFiles m_transFiles;

	bool m_bInited;
};
