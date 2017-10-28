#include <html/details/symetric_tag_with_attributes.h>


namespace html
{
namespace details
{
std::wstring SymetricTagWithAttributes::openTag() const
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
}
}