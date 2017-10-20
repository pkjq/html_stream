#ifndef G1FE00853_ABB5_41C5_953A_8FBA5369300E
#define G1FE00853_ABB5_41C5_953A_8FBA5369300E


#include <stdint.h>
#include <sstream>
#include <iomanip>


namespace html
{
namespace fmt
{
struct Hex
{
	constexpr Hex(bool printPrefix = true):
		printPrefix(printPrefix)
	{}

	constexpr Hex(uint32_t width, bool printPrefix = true):
		width(width),
		printPrefix(printPrefix)
	{}

	template <typename Type>
	inline std::wstring operator % (Type data) const
	{
		std::wstringstream buffer;
		buffer << (printPrefix ? L"0x" : L"") << std::hex << std::setw(width ? width : sizeof(Type) * 2) << std::setfill(L'0') << data;

		return buffer.str();
	}

private:
	const uint32_t width = 0;
	const bool printPrefix;
};
}
}



#endif//G1FE00853_ABB5_41C5_953A_8FBA5369300E
