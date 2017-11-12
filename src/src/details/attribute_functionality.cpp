#include <html/details/attribute_functionality.h>


namespace html
{
namespace details
{
void AttributeFunctionality::operator % (const Attribute &attribute)
{
	auto &attr = attributes[attribute.attribute];

	if (attribute.attribute == L"class")
	{ // only class may be more than one value
		if (!attr.empty())
			attr += L' ';
		attr += attribute.value;
	}
	else
		attr = attribute.value;
}

std::wstring AttributeFunctionality::GetAttributes() const
{
	std::wstring result = inlineStyle.empty() ? inlineStyle : (L"style=\"" + inlineStyle + L"\"");

	const auto attributes = getAttributesAsString();
	if (!result.empty() && !attributes.empty())
		result += L"; ";

	result += attributes;

	return result;
}

std::wstring AttributeFunctionality::getAttributesAsString() const
{
	std::wstring result;

	for (const auto &attr : attributes)
	{
		if (!result.empty())
			result += L"; ";

		result += attr.first;
		if (!attr.second.empty())
			result += L"=\"" + attr.second + L"\"";
	}

	return result;
}
}
}
