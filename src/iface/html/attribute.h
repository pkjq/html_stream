#ifndef GD5420F01_CD17_4B3E_9C71_329E0F91E3CF
#define GD5420F01_CD17_4B3E_9C71_329E0F91E3CF


#include <string>


namespace html
{
class Attribute
{
public:
	explicit Attribute(std::wstring attribute):		attribute(std::move(attribute)) {}
	explicit Attribute(const wchar_t *attribute) :	attribute(attribute) {}

	explicit Attribute(const wchar_t *attribute, const wchar_t *value);
	explicit Attribute(const wchar_t *attribute, bool value);

public:
	std::wstring GetAsString() const &	{ return attribute; }
	std::wstring GetAsString() const && { return std::move(attribute); }

private:
	const std::wstring attribute;
};


//////////////////////////////////////////////////////////////////////////
namespace attribute
{
class Id : public Attribute
{
public:
	template <typename ...Type>
	Id(Type ... args) : Attribute(L"id", args...) {}
};

class Title : public Attribute
{
public:
	template <typename ...Type>
	Title(Type ... args) : Attribute(L"title", args...) {}
};
}
}


#endif//GD5420F01_CD17_4B3E_9C71_329E0F91E3CF
