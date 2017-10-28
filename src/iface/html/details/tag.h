#ifndef G68F43C4F_89E4_430D_86FF_5D5E662D28B4
#define G68F43C4F_89E4_430D_86FF_5D5E662D28B4


#include <html/details/html_base.h>
#include <string>


namespace html
{
namespace details
{
class Tag : public details::BlockStreamTemplateMethod
{
public:
	explicit Tag(std::wstring tagOpen, std::wstring tagClose, bool writeWithConversion = true) :
		details::BlockStreamTemplateMethod(writeWithConversion),
		tagOpen(std::move(tagOpen)),
		tagClose(std::move(tagClose))
	{}

private: // ITag
	virtual std::wstring openTag() const override	{ return tagOpen;	}
	virtual std::wstring closeTag() const override	{ return tagClose;	}

protected:
	const std::wstring tagOpen;
	const std::wstring tagClose;
};
}
}


#endif//G68F43C4F_89E4_430D_86FF_5D5E662D28B4
