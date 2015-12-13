#pragma once

enum class TmxElement
{
	none,

	tmx,
	header,
	body,

	tu,
	tuv,

	seg,
};

enum class TmxAttribute
{
	none,

	version,

	HeaderBegin,
	creationtool = HeaderBegin,
	o_tmf,
	adminlang,
	datatype,
	creationtoolversion,
	segtype,
	srclang,
	HeaderEnd = srclang,

	UnitItemBegin,
	lang = UnitItemBegin,
	changeid,
	changedate,
	creationid,
	creationdate,
	UnitItemEnd = creationdate,
};
