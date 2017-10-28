#ifndef G5EEEBE29_95B2_47FF_AA4C_5E61674DBD6A
#define G5EEEBE29_95B2_47FF_AA4C_5E61674DBD6A


#include <html/details/tag.h>
#include <html/details/attribute_functionality.h>


namespace html
{
namespace details
{
class TagWithAttributes :
	public Tag,
	public AttributeFunctionality
{
public:
	explicit TagWithAttributes(std::wstring tagOpen, std::wstring tagClose, bool writeWithConversion = true) :
		Tag(tagOpen, tagClose, writeWithConversion)
	{}

private: // ITag
	virtual std::wstring openTag() const override;
};
}
}


#endif//G5EEEBE29_95B2_47FF_AA4C_5E61674DBD6A
