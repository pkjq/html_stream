#ifndef GA6C61C30_037D_49C3_A949_E3E2485F66C4
#define GA6C61C30_037D_49C3_A949_E3E2485F66C4


#include <html/details/symetric_tag.h>


namespace html
{
namespace head
{
class Title final : public details::SymetricTag
{
public:
	Title(): SymetricTag(L"title") {}

public:
	// std stream functionality
	inline auto& operator<<(std::wostream& (*manipulator)(std::wostream&))
	{
		static_cast<details::BlockStreamTemplateMethod&>(*this) << manipulator;
		return *this;
	}

	template <typename Type,
		typename = typename std::enable_if_t<!std::is_base_of_v<BlockStreamTemplateMethod, std::decay_t<Type>>>
	>
	inline auto& operator << (const Type *data)
	{
		static_cast<details::BlockStreamTemplateMethod&>(*this) << data;
		return *this;
	}

	template <typename Type,
		typename = typename std::enable_if_t<!std::is_base_of_v<BlockStreamTemplateMethod, std::decay_t<Type>>>
	>
	inline auto& operator << (Type &&data)
	{
		static_cast<details::BlockStreamTemplateMethod&>(*this) << std::forward<Type>(data);
		return *this;
	}
};
}
}


#endif//GA6C61C30_037D_49C3_A949_E3E2485F66C4
