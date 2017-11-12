#include <html/details/symetric_tag.h>


namespace html
{
namespace details
{
std::wstring SymetricTag::openTag() const
{
	auto result = std::wstring(L"<") + tag + L">";

	if (newLineAfterOpenTag)
		result += L'\n';

	return result;
}

std::wstring SymetricTag::closeTag() const
{
	auto result = std::wstring(L"</") + tag + L">";

	if (newLineAfterCloseTag)
		result += L'\n';

	return result;
}
}
}