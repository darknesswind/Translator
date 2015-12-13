#pragma once

class ProjectIOAdapter;
class QXmlStreamReader;
class ProjectReader
{
public:
	ProjectReader();
	~ProjectReader();

	bool read(ProjectIOAdapter& proj, QString filePath);

private:
	void readProject(ProjectIOAdapter& proj, QXmlStreamReader& xml);

};

