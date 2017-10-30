#include <html/progress.h>
#include <html/attribute.h>
#include <sstream>


namespace html
{
Progress::Progress(uint64_t topValue, uint64_t value):
	SymetricTagWithAttributes(L"progress")
{
	std::wstringstream buffer;

	buffer << topValue;
	const auto topValueStr = buffer.str();

	buffer.str({});
	buffer << value;
	const auto valueStr = buffer.str();

	*this 
		% Attribute(L"value", 	valueStr.c_str())
		% Attribute(L"max", 	topValueStr.c_str());
}
}
