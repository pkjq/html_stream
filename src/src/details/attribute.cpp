#include <html/attribute.h>


namespace html
{
Attribute::Attribute(const wchar_t *attribute, const wchar_t *value):
	Attribute(std::wstring(attribute) + L"=\"" + value + L"\"")
{}

Attribute::Attribute(const wchar_t *attribute, bool value) :
	Attribute(attribute, value ? L"true" : L"false")
{}
}
