#include <html/meter.h>
#include <html/attribute.h>
#include <sstream>


namespace html
{
Meter::Meter(double min, double low, double high, double max, double optimum, double value):
	SymetricTagWithAttributes(L"meter")
{
	std::wstringstream buffer;

#define HtmlMeterWriteAttr(attr) \
	{ \
		buffer.str({}); \
		buffer << attr; \
		*this % Attribute(L#attr, buffer.str().c_str()); \
	}


	HtmlMeterWriteAttr(min);
	HtmlMeterWriteAttr(max);

	HtmlMeterWriteAttr(low);
	HtmlMeterWriteAttr(high);

	HtmlMeterWriteAttr(optimum);

	HtmlMeterWriteAttr(value);


#undef HtmlMeterWriteAttr
}
}
