#include <html/html.h>


namespace html
{
static constexpr const wchar_t* tags[2] =
{
	L"<!DOCTYPE html>\n"
	L"<html>\n",

	L"\n</html>"
};

//////////////////////////////////////////////////////////////////////////
Html::Html() : Tag(tags[0], tags[1], false) {}
}