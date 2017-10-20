#ifndef G020D2F93_481A_4295_8A43_E097EC12EFFE
#define G020D2F93_481A_4295_8A43_E097EC12EFFE


#include <html/details/tag.h>
#include <html/body.h>
#include <html/head.h>


namespace html
{
class Html final : public details::Tag
{
public:
	Html();

	inline details::BlockStreamTemplateMethod& operator << (Body &body)
	{
		return static_cast<details::BlockStreamTemplateMethod&>(*this) << body;
	}

	inline BlockStreamTemplateMethod& operator << (Head &body)
	{
		return static_cast<BlockStreamTemplateMethod&>(*this) << body;
	}
};
}


#endif//G020D2F93_481A_4295_8A43_E097EC12EFFE
