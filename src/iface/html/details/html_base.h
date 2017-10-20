#ifndef G1D932C31_E9A0_4442_92D7_DD4E57E32A4B
#define G1D932C31_E9A0_4442_92D7_DD4E57E32A4B


#include <sstream>
#include <tuple>
#include <list>
#include <type_traits>
#include <ctti/type_id.hpp>


namespace html
{
namespace details
{
struct ITag
{
	virtual std::wstring openTag() const = 0;
	virtual std::wstring closeTag() const = 0;

public:
	virtual ~ITag() = default;
};

struct IRevert {};




struct BlockStreamTemplateMethod: private ITag
{
	// std stream functionality
	inline auto& operator<<(std::wostream& (*manipulator)(std::wostream&))
	{
		bufferStream << manipulator;
		return *this;
	}

	template <typename Type>
	inline typename std::enable_if<!std::is_base_of<BlockStreamTemplateMethod, Type>::value, BlockStreamTemplateMethod>::type& operator << (const Type *data)
	{
		bufferStream << data;
		return *this;
	}

	template <typename Type>
	inline typename std::enable_if<!std::is_base_of<BlockStreamTemplateMethod, Type>::value, BlockStreamTemplateMethod>::type& operator << (Type &&data)
	{
		bufferStream << data;
		return *this;
	}

public:
	////////////////////
	// in own decorators
	template <typename Type>
	inline typename std::enable_if<std::is_base_of<BlockStreamTemplateMethod, Type>::value, BlockStreamTemplateMethod>::type& operator << (Type &data)
	{
		inLvalue(data);
		return *this;
	}
 
	template <typename Type>
	inline typename std::enable_if<std::is_base_of<BlockStreamTemplateMethod, Type>::value, BlockStreamTemplateMethod>::type& operator << (Type &&data)
	{
		inRvalue(ctti::unnamed_type_id<Type>(), data);
		return *this;
	}

	// revert own decorators
	template <typename Type>
	inline typename std::enable_if<std::is_base_of<BlockStreamTemplateMethod, Type>::value, BlockStreamTemplateMethod>::type& operator >> (Type &&data)
	{
		outRvalue(ctti::unnamed_type_id<Type>());
		return *this;
	}

	template <typename Type>
	inline typename std::enable_if<std::is_base_of<IRevert, Type>::value, BlockStreamTemplateMethod>::type& operator >> (Type &&data)
	{
		outRvalue(static_cast<ctti::unnamed_type_id_t>(data));
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
	void inRvalue(ctti::unnamed_type_id_t typeIndex, const BlockStreamTemplateMethod &block);
	void inLvalue(const BlockStreamTemplateMethod &block);
	void outRvalue(ctti::unnamed_type_id_t typeIndex);

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
template <typename Type>
struct Revert: public details::IRevert
{
	inline explicit constexpr operator ctti::unnamed_type_id_t() const
	{
		return GetType<Type>();
	}

private:
	template <typename Type2, class = typename std::enable_if<std::is_class<Type2>::value>::type>
	ctti::unnamed_type_id_t GetType() const
	{
		return ctti::unnamed_type_id<Type2>();
	}
};


//////////////////////////////////////////////////////////////////////////
inline std::wostream& operator<<(std::wostream &stream, details::BlockStreamTemplateMethod &block)
{
	block.WriteDataToStream(stream);
	return stream;
}
}



#endif//G1D932C31_E9A0_4442_92D7_DD4E57E32A4B
