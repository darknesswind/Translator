#pragma once
#include "core/TransProject.h"

class ProjectIOAdapter
{
public:
	explicit ProjectIOAdapter(TransProject& proj)
		: m_proj(proj)
	{
	}

public:
	QString name() const { return m_proj.m_name; }
	QString path() const { return m_proj.m_path; }
	QString fullPath() const { return m_proj.fullPath(); }

	void setName(QString name) { m_proj.m_name = name; }
	void setPath(QString path) { m_proj.m_path = path; }

private:
	TransProject& m_proj;
};

