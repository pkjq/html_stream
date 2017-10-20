#include <html/style.h>


namespace html
{
Style::Style(const wchar_t *style, const wchar_t *value):
	Style(std::wstring(style) + L":" + value)
{}

Style::Style(const wchar_t *style, bool value) :
	Style(style, value ? L"true" : L"false")
{}
}
