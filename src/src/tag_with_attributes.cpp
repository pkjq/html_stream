#include <html/details/tag_with_attributes.h>


namespace html
{
namespace details
{
std::wstring TagWithAttributes::openTag() const
{
	std::wstring resultTag = tagOpen;

	const auto attributes = GetAttributes();
	if (!attributes.empty())
	{
		resultTag += L' ';
		resultTag += attributes;
	}

	return resultTag;
}
}
}
