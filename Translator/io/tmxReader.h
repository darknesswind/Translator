#pragma once
#include "tmxbase.h"

struct TranslateUnitItem
{
	QLocale locale;

	QString creationId;
	QDateTime creationDate;	// UTC Time

	QString changeId;
	QDateTime changeDate;	// UTC Time

	QString text;
};

typedef uint LocaleID;
struct TranslateUnit
{
// 	TranslateUnitItem* pSrcVal = nullptr;
	QMap<LocaleID, TranslateUnitItem> valMap;
};

struct Translation
{
	QLocale srcLang;
	QList<TranslateUnit> units;
};

class QXmlStreamReader;
class TmxReader
{
public:
	TmxReader();
	~TmxReader();

	void readTmx(QString sPath);

private:
	void handleRootElem(QXmlStreamReader& xml);
	void handleHeader(QXmlStreamReader& xml);
	void handleBody(QXmlStreamReader& xml);
	void handleUnitItem(QXmlStreamReader& xml, TranslateUnitItem& item);

	TmxElement getElemType(QStringRef name);
	TmxAttribute getAttrType(QStringRef name);
	QDateTime convertToDateTime(QStringRef date);
	LocaleID makeLocaleID(const QLocale& locale);

private:
	QMap<TmxAttribute, QString> m_header;
	Translation m_translation;
};

