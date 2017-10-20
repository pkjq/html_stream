#include <html/details/attribute_functionality.h>


namespace html
{
namespace details
{
std::wstring AttributeFunctionality::GetAttributes() const
{
	std::wstring result = inlineStyle.empty() ? inlineStyle : (L"style=\"" + inlineStyle + L"\"");

	if (!result.empty() && !attributes.empty())
		result += L"; ";
	result += attributes;

	return result;
}
}
}
