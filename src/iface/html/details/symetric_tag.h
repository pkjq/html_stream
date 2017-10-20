#ifndef GDF25F8C2_32B6_4449_8222_95021B2932BD
#define GDF25F8C2_32B6_4449_8222_95021B2932BD


#include <html/details/html_base.h>
#include <html/details/attribute_functionality.h>
#include <string>


namespace html
{
namespace details
{
class SymetricTag :
	public details::BlockStreamTemplateMethod,
	public details::AttributeFunctionality
{
public:
	explicit SymetricTag(std::wstring tag, bool writeWithConversion = true) :
		details::BlockStreamTemplateMethod(writeWithConversion),
		tag(std::move(tag))
	{}

	SymetricTag(const SymetricTag&) = default;

private: // ITag
	virtual std::wstring openTag() const override;
	virtual std::wstring closeTag() const override;

private:
	const std::wstring tag;
};
}
}


#endif//GDF25F8C2_32B6_4449_8222_95021B2932BD
