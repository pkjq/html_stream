#ifndef GD0CD8FFE_5B3E_4A8F_913E_9DE9413B5950
#define GD0CD8FFE_5B3E_4A8F_913E_9DE9413B5950


#include <html/details/push_pop_iface.h>
#include <ctti/type_id.hpp>


namespace html
{
namespace details
{
template <typename Type>
struct PushImpl final: public IPush
{
	template <typename ... Args>
	explicit PushImpl(Args ... args): obj(std::forward<Args>(args) ...)
	{
	}

	explicit PushImpl(Type obj) : obj(std::move(obj))
	{
	}

public:
	inline explicit constexpr operator ctti::unnamed_type_id_t() const
	{
		return GetType<Type>();
	}

	template <typename Rtype>
	inline auto& operator % (Rtype &&r)
	{
		obj % r;
		return *this;
	}

private:
	template <typename Type2, class = typename std::enable_if_t<std::is_class_v<Type2>>>
	inline constexpr ctti::unnamed_type_id_t GetType() const
	{
		return ctti::unnamed_type_id<Type2>();
	}

public:
	Type obj;
};


//////////////////////////////////////////////////////////////////////////
template <typename Type>
struct PopImpl final: public IPop
{
	inline explicit constexpr operator ctti::unnamed_type_id_t() const
	{
		return GetType<Type>();
	}

private:
	template <typename Type2, class = typename std::enable_if_t<std::is_class_v<Type2>>>
	inline constexpr ctti::unnamed_type_id_t GetType() const
	{
		return ctti::unnamed_type_id<Type2>();
	}
};
}
}


#endif//GD0CD8FFE_5B3E_4A8F_913E_9DE9413B5950
