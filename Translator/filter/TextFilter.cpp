#include "stdafx.h"
#include "TextFilter.h"


TextFilter::~TextFilter()
{
}

QString TextFilter::formatName()
{
	static QString s_name("Text");
	return s_name;
}
