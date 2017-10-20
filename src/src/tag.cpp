#include <html/details/tag.h>


namespace html
{
namespace details
{
std::wstring Tag::openTag()  const { return tagOpen;	}
std::wstring Tag::closeTag() const { return tagClose;	}
}
}
