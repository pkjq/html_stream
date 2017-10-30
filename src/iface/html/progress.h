#ifndef G106BC218_3128_4BE0_9CB0_2A477382CF10
#define G106BC218_3128_4BE0_9CB0_2A477382CF10


#include <html/details/symetric_tag_with_attributes.h>
#include <stdint.h>


namespace html
{
class Progress final : public details::SymetricTagWithAttributes
{
public:
	explicit Progress(uint64_t topValue, uint64_t value);
};
}


#endif//G106BC218_3128_4BE0_9CB0_2A477382CF10
