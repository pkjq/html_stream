#ifndef GEC4CC047_6ACA_41F1_BAB8_18225D1C522D
#define GEC4CC047_6ACA_41F1_BAB8_18225D1C522D


#include <html/details/push_pop_impl.h>


namespace html
{
template <typename Type>
inline details::PushImpl<Type> Push(Type obj)		{ return details::PushImpl<Type>(obj); }

template <typename Type, typename ... Args>
inline details::PushImpl<Type> Push(Args ... args)	{ return details::PushImpl<Type>(std::forward<Args>(args)...); }


//////////////////////////////////////////////////////////////////////////
template <typename Type>
inline details::PopImpl<Type> Pop(const Type&)		{ return details::PopImpl<Type>(); }

template <typename Type>
inline details::PopImpl<Type> Pop()					{ return details::PopImpl<Type>(); }
}


#endif//GEC4CC047_6ACA_41F1_BAB8_18225D1C522D
