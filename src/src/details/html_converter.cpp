#include "html_converter.h"


namespace html
{
namespace details
{
std::wstring ConvertToHtmlFormat(const std::wstring &input)
{
	std::wstring result;
	result.reserve(input.size());

	bool lastSymbolIsSpace = false;
	for (const auto chr : input)
	{
		switch (chr)
		{
		case L' ':
			result += lastSymbolIsSpace ? L"&nbsp;" : L" ";
			break;

		case L'\n':
			result += L"<br>\n";
			break;

		case L'\t':
			result += L"&nbsp;&nbsp;&nbsp;";
			break;

		case L'<':
			result += L"&lt;";
			break;
		case L'>':
			result += L"&gt;";
			break;

		case L'&':
			result += L"&amp;";
			break;

		case L'\"':
			result += L"&quot;";
			break;
		case L'\'':
			result += L"&apos;";
			break;

		case 0xA9: //'©'
			result += L"&copy;";
			break;

		case 0xAE: //'®'
			result += L"&reg;";
			break;

		default:
			result += chr;
		}

		lastSymbolIsSpace = (chr == L' ');
	}

	return result;
}
}
}
