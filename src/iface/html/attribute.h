#ifndef GD5420F01_CD17_4B3E_9C71_329E0F91E3CF
#define GD5420F01_CD17_4B3E_9C71_329E0F91E3CF


#include <string>
#include <html/details/block_data.h>


namespace html
{
class Attribute: public details::BlockData
{
public:
	explicit Attribute(std::wstring attribute):		BlockData(std::move(attribute)) {}
	explicit Attribute(const wchar_t *attribute):	BlockData(attribute) {}

	explicit Attribute(const wchar_t *attribute, const wchar_t *value);
	explicit Attribute(const wchar_t *attribute, bool value);
};


//////////////////////////////////////////////////////////////////////////
namespace attribute
{
class Id final : public Attribute
{
public:
	template <typename ...Type>
	Id(Type ... args) : Attribute(L"id", args...) {}
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
	template <typename ...Type>
	Title(Type ... args) : Attribute(L"title", args...) {}
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
	Checked() : Attribute(L"checked") {}
};
}
}


#endif//GD5420F01_CD17_4B3E_9C71_329E0F91E3CF
