#include <html/details.h>
#include <html/attribute.h>


namespace html
{
Details::Details(const wchar_t *summary, bool opened):
	SymetricTagWithAttributes(L"details")
{
	auto &me = *this;

	me << (html::details::SymetricTag(L"summary") << summary);
	if (opened)
		me % html::Attribute(L"open", L"open");
}
}
