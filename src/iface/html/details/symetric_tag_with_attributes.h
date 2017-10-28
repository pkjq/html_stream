#ifndef GD1FF9E3F_6D4F_4A90_8477_2C17EB25D59A
#define GD1FF9E3F_6D4F_4A90_8477_2C17EB25D59A


#include <html/details/symetric_tag.h>
#include <html/details/attribute_functionality.h>
#include <string>


namespace html
{
namespace details
{
class SymetricTagWithAttributes :
	public SymetricTag,
	public AttributeFunctionality
{
public:
	explicit SymetricTagWithAttributes(std::wstring tag, bool writeWithConversion = true) :
		SymetricTag(tag, writeWithConversion)
	{}

	SymetricTagWithAttributes(const SymetricTagWithAttributes&) = default;

private: // ITag
	virtual std::wstring openTag() const override;
};
}
}


#endif//GD1FF9E3F_6D4F_4A90_8477_2C17EB25D59A
