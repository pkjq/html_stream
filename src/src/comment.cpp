#include <html/comment.h>


namespace html
{
static constexpr const wchar_t* tags[2] =
{
	L"\n<!--\n",

	L"\n-->\n"
};

//////////////////////////////////////////////////////////////////////////
Comment::Comment() : Tag(tags[0], tags[1], false) {}
}
