#ifndef GED0A1FF4_AB28_46D3_ADC3_9409F141C23C
#define GED0A1FF4_AB28_46D3_ADC3_9409F141C23C


#include <html/details/tag_with_attributes.h>


namespace html
{
class Input final : public details::TagWithAttributes
{
public:
	enum class Type
	{
		button,
		checkbox,
		color,
		date,
		datetime_local,
		email,
		file,
		hidden,
		image,
		month,
		number,
		password,
		radio,
		range,
		reset,
		search,
		submit,
		tel,
		text,
		time,
		url,
		week,
	};

public:
	explicit Input(Type type);
};
}


#endif//GED0A1FF4_AB28_46D3_ADC3_9409F141C23C
