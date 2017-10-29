#include <html/details/html_base.h>
#include "html_converter.h"
#include <exception/condition.h>
#include <algorithm>
#include <iterator>


namespace html
{
namespace details
{
void BlockStreamTemplateMethod::flushBuffer() const
{
	if (writeWithConversion)
		blockBody += ConvertToHtmlFormat(bufferStream.str());
	else
		blockBody += bufferStream.str();

	bufferStream.str({});
	bufferStream.clear();
}

void BlockStreamTemplateMethod::pushValue(ctti::unnamed_type_id_t typeIndex, const BlockStreamTemplateMethod &block)
{
	flushBuffer();

	blockBody += block.openTag();
	blockBody += block.getBlockBody();

	closeTagStack.push_back({ typeIndex, block.closeTag() });
}

void BlockStreamTemplateMethod::copyValue(const BlockStreamTemplateMethod &block)
{
	flushBuffer();

	blockBody += block.openTag();
	blockBody += block.getBlockBody();

	blockBody += block.closeTag();
}

void BlockStreamTemplateMethod::popValue(ctti::unnamed_type_id_t typeIndex)
{
	auto it = std::find_if(std::rbegin(closeTagStack), std::rend(closeTagStack), [&typeIndex](const auto &decorator)
	{
		return std::get<ctti::unnamed_type_id_t>(decorator) == typeIndex;
	});

	DEBUG_CHECK(it != std::rend(closeTagStack)) << "this tag does not exist in stack";
	if (it != std::rend(closeTagStack))
	{
		flushBuffer();

		blockBody += std::get<std::wstring>(*it);

		std::advance(it, 1);
		closeTagStack.erase(it.base());
	}
}

std::wstring BlockStreamTemplateMethod::getBlockBody() const
{
	flushBuffer();
	std::wstring result = blockBody;

	for (const auto &decorator : closeTagStack)
		result += std::get<std::wstring>(decorator);

	return result;
}
}
}