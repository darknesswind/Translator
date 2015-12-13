#include "stdafx.h"
#include "tmxReader.h"
#include <QXmlStreamReader>
#include <QFile>
#include <QTimeZone>

TmxReader::TmxReader()
{
}


TmxReader::~TmxReader()
{
}

void TmxReader::readTmx(QString sPath)
{
	QFile tmxFile(sPath);
	if (!tmxFile.open(QFile::ReadOnly))
		QMessageBox::warning(nullptr, QSTR_Error, QSTR_OpenFailed.arg(sPath));

	QXmlStreamReader xml(&tmxFile);

	while (!xml.atEnd())
	{
		QXmlStreamReader::TokenType tokenType = xml.readNext();
		switch (tokenType)
		{
		case QXmlStreamReader::StartElement:
			if (TmxElement::tmx == getElemType(xml.name()))
			handleRootElem(xml);
			break;
		case QXmlStreamReader::EndElement:
			break;
		case QXmlStreamReader::NoToken:
		case QXmlStreamReader::Invalid:
		case QXmlStreamReader::StartDocument:
		case QXmlStreamReader::EndDocument:
		case QXmlStreamReader::Characters:
		case QXmlStreamReader::Comment:
		case QXmlStreamReader::DTD:
		case QXmlStreamReader::EntityReference:
		case QXmlStreamReader::ProcessingInstruction:
		default:
			break;
		}
	}
	if (xml.hasError())
		QMessageBox::warning(nullptr, QSTR_Error, xml.errorString());
	tmxFile.close();
}

void TmxReader::handleRootElem(QXmlStreamReader& xml)
{
	while (!xml.atEnd())
	{
		QXmlStreamReader::TokenType tokenType = xml.readNext();
		switch (tokenType)
		{
		case QXmlStreamReader::StartElement:
			{
				TmxElement elemType = getElemType(xml.name());
				switch (elemType)
				{
				case TmxElement::header:
					handleHeader(xml);
					break;
				case TmxElement::body:
					handleBody(xml);
					break;
				default:
					break;
				}
			}
			break;
		case QXmlStreamReader::EndElement:
			break;
		}
	}
}

void TmxReader::handleHeader(QXmlStreamReader& xml)
{
	QXmlStreamAttributes attrs = xml.attributes();
	for (auto iter = attrs.begin(); iter != attrs.end(); ++iter)
	{
		TmxAttribute attrType = getAttrType(iter->name());
		if (attrType >= TmxAttribute::HeaderBegin && attrType <= TmxAttribute::HeaderEnd)
			m_header[attrType] = iter->value().toString();
	}

	m_translation.srcLang = QLocale(m_header[TmxAttribute::srclang]);
}

void TmxReader::handleBody(QXmlStreamReader& xml)
{
	TranslateUnit* pCurTransUnit = nullptr;
	TranslateUnitItem* pCurVal = nullptr;

	while (!xml.atEnd())
	{
		QXmlStreamReader::TokenType tokenType = xml.readNext();
		switch (tokenType)
		{
		case QXmlStreamReader::StartElement:
			{
				TmxElement elemType = getElemType(xml.name());
				switch (elemType)
				{
				case TmxElement::tu:
					m_translation.units.push_back(TranslateUnit());
					pCurTransUnit = &m_translation.units.back();
					break;
				case TmxElement::tuv:
					if (pCurTransUnit)
					{
						TranslateUnitItem item;
						handleUnitItem(xml, item);
						auto iter = pCurTransUnit->valMap.insert(makeLocaleID(item.locale), item);
						pCurVal = &iter.value();
						break;
					}
				case TmxElement::seg:
					tokenType = xml.readNext();
					if (pCurVal)
					{
						pCurVal->text = xml.text().toString();
					}
				default:
					break;
				}
				break;
			}
		case QXmlStreamReader::EndElement:
			{
				TmxElement elemType = getElemType(xml.name());
				switch (elemType)
				{
				case TmxElement::tu:
					pCurTransUnit = nullptr;
					break;
				case TmxElement::tuv:
					pCurVal = nullptr;
					break;
				default:
					break;
				}
				break;
			}
		default:
			break;
		}
	}
}

void TmxReader::handleUnitItem(QXmlStreamReader& xml, TranslateUnitItem& item)
{
	QXmlStreamAttributes attrs = xml.attributes();
	for (auto iter = attrs.begin(); iter != attrs.end(); ++iter)
	{
		TmxAttribute attrType = getAttrType(iter->name());
		switch (attrType)
		{
		case TmxAttribute::lang:
			item.locale = QLocale(iter->value().toString());
			break;
		case TmxAttribute::changeid:
			item.changeId = iter->value().toString();
			break;
		case TmxAttribute::changedate:
			item.changeDate = convertToDateTime(iter->value());
			break;
		case TmxAttribute::creationid:
			item.creationId = iter->value().toString();
			break;
		case TmxAttribute::creationdate:
			item.creationDate = convertToDateTime(iter->value());
			break;
		default:
			break;
		}
	}
}

TmxElement TmxReader::getElemType(QStringRef name)
{
	static QMap<QString, TmxElement> s_labelMap;
	if (s_labelMap.empty())
	{
		s_labelMap["tmx"] = TmxElement::tmx;
		s_labelMap["header"] = TmxElement::header;
		s_labelMap["body"] = TmxElement::body;
		s_labelMap["tu"] = TmxElement::tu;
		s_labelMap["tuv"] = TmxElement::tuv;
		s_labelMap["seg"] = TmxElement::seg;
	}
	auto iter = s_labelMap.find(name.toString().toLower());
	if (iter != s_labelMap.end())
		return iter.value();
	else
		return TmxElement::none;
}

TmxAttribute TmxReader::getAttrType(QStringRef name)
{
	QMap<QString, TmxAttribute> s_attrMap;
	if (s_attrMap.empty())
	{
		s_attrMap["creationtool"] = TmxAttribute::creationtool;
		s_attrMap["ottmf"] = TmxAttribute::o_tmf;
		s_attrMap["adminlang"] = TmxAttribute::adminlang;
		s_attrMap["datatype"] = TmxAttribute::datatype;
		s_attrMap["creationtoolversion"] = TmxAttribute::creationtoolversion;
		s_attrMap["segtype"] = TmxAttribute::segtype;
		s_attrMap["srclang"] = TmxAttribute::srclang;
		s_attrMap["lang"] = TmxAttribute::lang;
		s_attrMap["changeid"] = TmxAttribute::changeid;
		s_attrMap["changedate"] = TmxAttribute::changedate;
		s_attrMap["creationid"] = TmxAttribute::creationid;
		s_attrMap["creationdate"] = TmxAttribute::creationdate;

	}
	auto iter = s_attrMap.find(name.toString().toLower());
	if (iter != s_attrMap.end())
		return iter.value();
	else
		return TmxAttribute::none;
}

QDateTime TmxReader::convertToDateTime(QStringRef date)
{
	// 2015 01 07 T 01 57 35 Z
	// 0123 45 67 8 9A BC DE F
	enum
	{
		oYear = 0,
		nYear = 4,
		oMonth = oYear + nYear,
		nMonth = 2,
		oDay = oMonth + nMonth,
		nDay = 2,
		Magic1 = oDay + nDay,
		oHour,
		nHour = 2,
		oMinute = oHour + nHour,
		nMinute = 2,
		oSecond = oMinute + nMinute,
		nSecond = 2,
		Magic2 = oSecond + nSecond,
		nLength,
	};

	if (date.size() != nLength ||
		date.at(Magic1) != QChar('T') ||
		date.at(Magic2) != QChar('Z'))
		return QDateTime::currentDateTime();

	QDateTime result;

	int year = date.mid(oYear, nYear).toInt();
	int month = date.mid(oMonth, nMonth).toInt();
	int day = date.mid(oDay, nDay).toInt();
	result.setDate(QDate(year, month, day));

	int hour = date.mid(oHour, nHour).toInt();
	int minute = date.mid(oMinute, nMinute).toInt();
	int second = date.mid(oSecond, nSecond).toInt();

	result.setTime(QTime(hour, minute, second));

	return result;
}

LocaleID TmxReader::makeLocaleID(const QLocale& locale)
{
	return ((locale.country() << 16) | locale.language());
}
