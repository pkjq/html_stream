#ifndef GE68C2935_DE39_462C_8519_5844EE4FF411
#define GE68C2935_DE39_462C_8519_5844EE4FF411


#include <html/details/block_data.h>


namespace html
{
namespace head
{
class Meta final: public details::BlockData
{
public:
	explicit Meta(std::wstring rawMeta);
	explicit Meta(const wchar_t *name, const wchar_t *content);
};
}
}


#endif//GE68C2935_DE39_462C_8519_5844EE4FF411
