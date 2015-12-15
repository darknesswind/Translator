#pragma once

#include <QFileInfo>
class TransProject;
class TransFile
{
public:
	TransFile(TransProject* pProject, const QFileInfo& info, FilterPtr& spFilter);
	~TransFile();

	QString relFilePath() const { return m_relPath; }
	QString formatName() const;
	QString codecName() const;

private:
	TransProject* m_pProject;
	QFileInfo m_info;
	FilterPtr m_spFilter;

	QString m_relPath;
};

