#ifndef G760AE60F_CEC9_4DBD_B6CC_2459A83CA1BB
#define G760AE60F_CEC9_4DBD_B6CC_2459A83CA1BB


#include <html/details/symetric_tag.h>


namespace html
{
namespace head
{
class Css final : public details::SymetricTag
{
public:
	Css(): SymetricTag(L"style", false) {}

public:
	// std stream functionality
	inline auto& operator<<(std::wostream& (*manipulator)(std::wostream&))
	{
		static_cast<details::BlockStreamTemplateMethod&>(*this) << manipulator;
		return *this;
	}

	template <typename Type,
		typename = typename std::enable_if_t<!std::is_base_of_v<BlockStreamTemplateMethod, Type>>
	>
		inline auto& operator << (const Type *data)
	{
		static_cast<details::BlockStreamTemplateMethod&>(*this) << data;
		return *this;
	}

	template <typename Type,
		typename = typename std::enable_if_t<!std::is_base_of_v<BlockStreamTemplateMethod, Type>>
	>
		inline auto& operator << (Type &&data)
	{
		static_cast<details::BlockStreamTemplateMethod&>(*this) << std::forward<Type>(data);
		return *this;
	}
};
}
}


#endif//G760AE60F_CEC9_4DBD_B6CC_2459A83CA1BB
