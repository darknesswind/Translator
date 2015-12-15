#pragma once

class QFileInfo;
class QTextCodec;

class FileFilterBase
{
public:
	FileFilterBase(QString sPattern, const QByteArray& inputCodec, const QByteArray& outputCodec);
	virtual ~FileFilterBase() = default;

	virtual QString formatName() = 0;


	bool isSupportFormat(const QFileInfo& info);
	QString codecName() const;
	QTextCodec* inputCodec() const { return m_pInCodec; }
	QTextCodec* outputCodec() const { return m_pOutCodec; }

public:
	static void InitBuildInFilter();
	static bool RegisterFilter(FilterPtr spFilter);
	static FilterPtr GetFilter(QString name);

private:
	static QMap<QString, FilterPtr> s_filterMap;

private:
	QRegExp m_patten;
	QTextCodec* m_pInCodec;
	QTextCodec* m_pOutCodec;
};
