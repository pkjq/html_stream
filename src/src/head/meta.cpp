#include <html/head/meta.h>


namespace html
{
namespace head
{
Meta::Meta(std::wstring rawMeta):
	BlockData(L"<meta " + rawMeta + L">\n")
{}

Meta::Meta(const wchar_t *name, const wchar_t *content):
	Meta(std::wstring(L"name=\"") + name + L"\" content=\"" + content + L"\"")
{}
}
}
