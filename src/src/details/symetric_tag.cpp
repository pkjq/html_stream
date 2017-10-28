#include <html/details/symetric_tag.h>


namespace html
{
namespace details
{
std::wstring SymetricTag::openTag() const
{
	return std::wstring(L"<") + tag + L">\n";
}

std::wstring SymetricTag::closeTag() const
{
	return std::wstring(L"</") + tag + L">\n";
}
}
}