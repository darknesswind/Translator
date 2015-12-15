#pragma once
#include "FileFilterBase.h"

class TextFilter : public FileFilterBase
{
public:
	using FileFilterBase::FileFilterBase;
	~TextFilter();

public:
	virtual QString formatName() override;

};

