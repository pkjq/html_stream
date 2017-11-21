#ifndef G1D932C31_E9A0_4442_92D7_DD4E57E32A4B
#define G1D932C31_E9A0_4442_92D7_DD4E57E32A4B


#include <sstream>
#include <tuple>
#include <list>
#include <type_traits>
#include <ctti/type_id.hpp>
#include <html/details/push_pop_iface.h>
#include <html/details/tag_iface.h>


namespace html
{
namespace details
{
struct BlockStreamTemplateMethod: private ITag
{
	// std stream functionality
	inline auto& operator<<(std::wostream& (*manipulator)(std::wostream&))
	{
		bufferStream << manipulator;
		return *this;
	}

	template <typename Type,
		typename = typename std::enable_if_t<
			!std::is_base_of<BlockStreamTemplateMethod,	std::decay_t<Type>>::value &&
			!std::is_base_of<IPush,						std::decay_t<Type>>::value
		>
	>
	inline auto& operator << (const Type *data)
	{
		bufferStream << data;
		return *this;
	}

	template <typename Type,
		typename = typename std::enable_if_t<
			!std::is_base_of<BlockStreamTemplateMethod,	std::decay_t<Type>>::value &&
			!std::is_base_of<IPush,						std::decay_t<Type>>::value
		>
	>
	inline auto& operator << (Type &&data)
	{
		bufferStream << data;
		return *this;
	}

public:
	template <typename Type>
	inline typename std::enable_if_t<std::is_base_of<BlockStreamTemplateMethod, std::decay_t<Type>>::value, BlockStreamTemplateMethod>& operator << (Type &&data)
	{
		copyValue(data);
		return *this;
	}

	template <typename Type>
	inline typename std::enable_if_t<std::is_base_of<IPush, std::decay_t<Type>>::value, BlockStreamTemplateMethod>& operator << (Type &&data)
	{
		pushValue(static_cast<ctti::unnamed_type_id_t>(data), data.obj);
		return *this;
	}

	template <typename Type>
	inline typename std::enable_if_t<std::is_base_of<IPop, std::decay_t<Type>>::value, BlockStreamTemplateMethod>& operator >> (Type &&data)
	{
		popValue(static_cast<ctti::unnamed_type_id_t>(data));
		return *this;
	}

public:
	inline void WriteDataToStream(std::wostream &out) const
	{
		out << openTag();
		out << getBlockBody();
		out << closeTag();
	}

protected:
	inline explicit BlockStreamTemplateMethod(bool writeWithConversion = true):
		writeWithConversion(writeWithConversion)
	{}

	BlockStreamTemplateMethod(BlockStreamTemplateMethod&&) = default;
	BlockStreamTemplateMethod(const BlockStreamTemplateMethod &me):
		writeWithConversion(me.writeWithConversion),
		closeTagStack(me.closeTagStack),
		bufferStream(me.bufferStream.str()),
		blockBody(me.blockBody)
	{}
	virtual ~BlockStreamTemplateMethod() = default;

private:
	void pushValue(ctti::unnamed_type_id_t typeIndex, const BlockStreamTemplateMethod &block);
	void copyValue(const BlockStreamTemplateMethod &block);
	void popValue(ctti::unnamed_type_id_t typeIndex);

	void flushBuffer() const;
	std::wstring getBlockBody() const;

private:
	const bool writeWithConversion;

	std::list<std::tuple<ctti::unnamed_type_id_t, std::wstring>> closeTagStack;

	mutable std::wostringstream bufferStream;
	mutable std::wstring blockBody;
};
}


//////////////////////////////////////////////////////////////////////////
inline std::wostream& operator<<(std::wostream &stream, details::BlockStreamTemplateMethod &block)
{
	block.WriteDataToStream(stream);
	return stream;
}
}


#endif//G1D932C31_E9A0_4442_92D7_DD4E57E32A4B
