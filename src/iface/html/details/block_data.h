#ifndef G5C0D3F35_F15E_4CA1_8A01_CAFE47697E15
#define G5C0D3F35_F15E_4CA1_8A01_CAFE47697E15


#include <string>


namespace html
{
namespace details
{
class BlockData
{
public:
	BlockData(std::wstring data): data(std::move(data)) {}

public:
	std::wstring GetAsString() const &	{ return data; }
	std::wstring GetAsString() const && { return std::move(data); }

private:
	const std::wstring data;
};
}
}


#endif//G5C0D3F35_F15E_4CA1_8A01_CAFE47697E15
