#ifndef GD7A7A123_0A68_4C6D_B7F7_B4CDBCED208A
#define GD7A7A123_0A68_4C6D_B7F7_B4CDBCED208A


#include <html/details/symetric_tag.h>
#include <html/head/meta.h>
#include <html/head/title.h>
#include <html/head/css.h>


namespace html
{
class Head final : public details::SymetricTag
{
public:
	Head(): SymetricTag(L"head", false, true, true) {}

public:
	template <typename Type>
	inline typename std::enable_if_t<
			std::is_base_of_v<head::Css,		std::decay_t<Type>> |
			std::is_base_of_v<head::Title,		std::decay_t<Type>> |
			std::is_base_of_v<details::IPush,	std::decay_t<Type>>,
		Head>&
	operator << (Type &&data)
	{
		static_cast<details::BlockStreamTemplateMethod&>(*this) << data;
		return *this;
	}

	template <typename Type>
	inline typename std::enable_if_t<
			std::is_base_of_v<head::Meta,		std::decay_t<Type>>,
		Head>&
	operator << (Type &&data)
	{
		static_cast<details::BlockStreamTemplateMethod&>(*this) << data.GetAsString();
		return *this;
	}

	using details::SymetricTag::operator >> ;
};
}


#endif//GD7A7A123_0A68_4C6D_B7F7_B4CDBCED208A
