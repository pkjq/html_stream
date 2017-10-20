#include <html/link.h>
#include <html/attribute.h>


namespace html
{
Link::Link(const wchar_t *href):
	SymetricTag(L"a")
{
	*this % Attribute(L"href", href);
}
}
