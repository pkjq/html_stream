#include <html/input.h>
#include <exception/condition.h>


namespace html
{
static const wchar_t* TypeToStr(const Input::Type type)
{
	switch (type)
	{
	case Input::Type::button:
		return L"button";
	case Input::Type::checkbox:
		return L"checkbox";
	case Input::Type::color:
		return L"color";
	case Input::Type::date:
		return L"date";
	case Input::Type::datetime_local:
		return L"datetime-local";
	case Input::Type::email:
		return L"email";
	case Input::Type::file:
		return L"file";
	case Input::Type::hidden:
		return L"hidden";
	case Input::Type::image:
		return L"image";
	case Input::Type::month:
		return L"month";
	case Input::Type::number:
		return L"number";
	case Input::Type::password:
		return L"password";
	case Input::Type::radio:
		return L"radio";
	case Input::Type::range:
		return L"range";
	case Input::Type::reset:
		return L"reset";
	case Input::Type::search:
		return L"search";
	case Input::Type::submit:
		return L"submit";
	case Input::Type::tel:
		return L"tel";
	case Input::Type::text:
		return L"text";
	case Input::Type::time:
		return L"time";
	case Input::Type::url:
		return L"url";
	case Input::Type::week:
		return L"week";

	default:
		EXPECT(false) << "unsupported type";
	}
}

Input::Input(Type type) : TagWithAttributes(L"<input", L">")
{
	(*this) % html::Attribute(L"type", TypeToStr(type));
}
}
