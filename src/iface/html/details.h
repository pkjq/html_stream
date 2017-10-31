#ifndef GB3587209_34E2_48BE_938C_9E34C346D07C
#define GB3587209_34E2_48BE_938C_9E34C346D07C


#include <html/details/symetric_tag_with_attributes.h>


namespace html
{
//! Collapsible block
class Details final : public details::SymetricTagWithAttributes
{
public:
	explicit Details(const wchar_t *summary, bool opened = false);
};
}


#endif//GB3587209_34E2_48BE_938C_9E34C346D07C
