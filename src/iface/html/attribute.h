#ifndef GD5420F01_CD17_4B3E_9C71_329E0F91E3CF
#define GD5420F01_CD17_4B3E_9C71_329E0F91E3CF


#include <string>


namespace html
{
class Attribute
{
public:
	explicit Attribute(std::wstring attribute, const char*) = delete;

	explicit Attribute(std::wstring attribute, const wchar_t *value);
	explicit Attribute(std::wstring attribute, std::wstring attrValue);
	explicit Attribute(std::wstring attribute, bool boolValue);

public:
	const std::wstring attribute;
	const std::wstring value;
};


//////////////////////////////////////////////////////////////////////////
namespace attribute
{
class Id final : public Attribute
{
public:
	explicit Id(std::wstring id) : Attribute(L"id", std::move(id)) {}
};

class Class final : public Attribute
{
public:
	template <typename ...Type>
	Class(Type ... args) : Attribute(L"class", args...) {}
};

class Title final : public Attribute
{
public:
	explicit Title(std::wstring title) : Attribute(L"title", std::move(title)) {}
};

class For final : public Attribute
{
public:
	template <typename ...Type>
	For(Type ... args) : Attribute(L"for", args...) {}
};

class Checked final : public Attribute
{
public:
	explicit Checked() : Attribute(L"checked", std::wstring()) {}
};

class Hidden final : public Attribute
{
public:
	explicit Hidden() : Attribute(L"hidden", std::wstring()) {}
};
}
}


#endif//GD5420F01_CD17_4B3E_9C71_329E0F91E3CF
