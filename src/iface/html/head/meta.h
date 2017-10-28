#ifndef GE68C2935_DE39_462C_8519_5844EE4FF411
#define GE68C2935_DE39_462C_8519_5844EE4FF411


#include <html/details/block_data.h>


namespace html
{
namespace head
{
class Meta : public details::BlockData
{
public:
	explicit Meta(std::wstring rawMeta);
	explicit Meta(const wchar_t *name, const wchar_t *content);
};


//////////////////////////////////////////////////////////////////////////
namespace meta
{
class Author final : public Meta
{
public:
	template <typename ...Type>
	inline Author(Type ... args) : Meta(L"author", args...) {}
};

class Charset final : public Meta
{
public:
	template <typename ...Type>
	inline Charset(Type ... args) : Meta(L"charset", args...) {}
};

class Generator final : public Meta
{
public:
	template <typename ...Type>
	inline Generator(Type ... args) : Meta(L"generator", args...) {}
};
}
}
}


#endif//GE68C2935_DE39_462C_8519_5844EE4FF411
