#ifndef G5CE3EAA9_FF04_4AD5_A094_36CDA501005D
#define G5CE3EAA9_FF04_4AD5_A094_36CDA501005D


#include <html/attribute.h>
#include <html/style.h>
#include <string>
#include <unordered_map>
#include <type_traits>


namespace html
{
namespace details
{
class AttributeFunctionality
{
public:
	void operator % (const Attribute &attribute);

	void operator % (const Style &style)
	{
		addTo(style.GetAsString(), inlineStyle);
	}

protected:
	std::wstring GetAttributes() const;

private:
	static void addTo(const std::wstring &what, std::wstring &to)
	{
		if (!to.empty())
			to += L"; ";
		to += what;
	}

	std::wstring getAttributesAsString() const;

private:
	std::unordered_map<std::wstring, std::wstring> attributes;
	std::wstring inlineStyle;
};


//////////////////////////////////////////////////////////////////////////
template <
	typename Type,
	class = typename std::enable_if<std::is_base_of<AttributeFunctionality, std::remove_reference_t<Type>>::value>::type,
	class = typename std::enable_if<!std::is_const<Type>::value>::type
	>
Type&& operator % (Type &&t, const Attribute &attr)
{
	static_cast<AttributeFunctionality&>(t) % attr;
	return std::forward<Type>(t);
}

template <
	typename Type,
	class = typename std::enable_if<std::is_base_of<AttributeFunctionality, std::remove_reference_t<Type>>::value>::type,
	class = typename std::enable_if<!std::is_const<Type>::value>::type
	>
Type&& operator % (Type &&t, const Style &style)
{
	static_cast<AttributeFunctionality&>(t) % style;
	return std::forward<Type>(t);
}
}
}


#endif//G5CE3EAA9_FF04_4AD5_A094_36CDA501005D
