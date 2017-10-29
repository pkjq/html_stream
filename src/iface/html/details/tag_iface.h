#ifndef GF71109AC_743D_4178_9931_44676C43CFBE
#define GF71109AC_743D_4178_9931_44676C43CFBE


#include <string>


namespace html
{
namespace details
{
struct ITag
{
	virtual std::wstring openTag() const = 0;
	virtual std::wstring closeTag() const = 0;

public:
	virtual ~ITag() = default;
};
}
}


#endif//GF71109AC_743D_4178_9931_44676C43CFBE
