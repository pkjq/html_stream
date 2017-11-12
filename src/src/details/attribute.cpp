#include <html/attribute.h>


namespace html
{
Attribute::Attribute(std::wstring attribute, const wchar_t *value):
	Attribute(attribute, std::wstring(value))
{
}

Attribute::Attribute(std::wstring attribute, std::wstring attrValue):
	attribute(std::move(attribute)),
	value(std::move(attrValue))
{}

Attribute::Attribute(std::wstring attribute, bool boolValue) :
	attribute(std::move(attribute)),
	value(boolValue ? L"true" : L"false")
{}
}
