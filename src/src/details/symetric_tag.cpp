#include <html/details/symetric_tag.h>


namespace html
{
namespace details
{
std::wstring SymetricTag::openTag() const
{
	std::wstring resultTag = L"<";
	resultTag += tag;

	const auto attributes = GetAttributes();
	if (!attributes.empty())
	{
		resultTag += L' ';
		resultTag += attributes;
	}
	resultTag += L">";

	return resultTag;
}

std::wstring SymetricTag::closeTag() const
{
	return std::wstring(L"</") + tag + L">\n";
}
}
}