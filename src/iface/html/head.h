#ifndef GD7A7A123_0A68_4C6D_B7F7_B4CDBCED208A
#define GD7A7A123_0A68_4C6D_B7F7_B4CDBCED208A


#include <html/details/symetric_tag.h>
#include <html/head/meta.h>


namespace html
{
class Head final : public details::SymetricTag
{
public:
	Head(): SymetricTag(L"head", false) {}

public:
	inline details::BlockStreamTemplateMethod& operator << (head::Meta &&entity)
	{
		return static_cast<details::BlockStreamTemplateMethod&>(*this) << entity.GetAsString();
	}
	inline details::BlockStreamTemplateMethod& operator << (const head::Meta &entity)
	{
		return static_cast<details::BlockStreamTemplateMethod&>(*this) << entity.GetAsString();
	}

	using SymetricTag::operator<<;
};
}


#endif//GD7A7A123_0A68_4C6D_B7F7_B4CDBCED208A
