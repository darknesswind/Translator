#pragma once

class ProjectIOAdapter;
class QXmlStreamWriter;
class ProjectWriter
{
public:
	ProjectWriter();
	~ProjectWriter();

	enum ErrCode
	{
		NoError,
		PathError,
		OpenFileError,
	};

public:
	bool write(const ProjectIOAdapter& proj);


private:
	void writeProject(const ProjectIOAdapter& proj, QXmlStreamWriter& xml);

private:
	ErrCode m_errCode;
};

