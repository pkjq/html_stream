#ifndef G9AD31562_FE35_425F_B266_592B3BEFE126
#define G9AD31562_FE35_425F_B266_592B3BEFE126


#include <string>
#include <html/details/block_data.h>


namespace html
{
class Style: public details::BlockData
{
public:
	explicit Style(std::wstring rawStyle): BlockData(std::move(rawStyle)) {}

	explicit Style(const wchar_t *style, const wchar_t *value);
	explicit Style(const wchar_t *style, bool value);
};


//////////////////////////////////////////////////////////////////////////
namespace style
{
class Color: public Style
{
public:
	template <typename ...Type>
	Color(Type ... args): Style(L"color", args...) {}
};
}
}



#endif//G9AD31562_FE35_425F_B266_592B3BEFE126
