#pragma once

#include "Encoding.hpp"

#include "Utf8ConstIterator.hpp"
#include "Utf16ConstIterator.hpp"
#include "Utf32ConstIterator.hpp"
#include "CharacterConversions.hpp"

#include <string>

namespace rexrn
{
namespace cpp_utf
{
namespace impl
{

template <typename TForwardIterator, Encoding TSourceEncoding, Encoding TTargetEncoding>
std::string convert( char const* begin_, char const* end_ )
{
	std::string result;
	result.reserve((end_ - begin_) * 4); // optimization
	for( TForwardIterator it = begin_; it != end_; ++it )
	{
		char32_t character = decodeCharacter<TSourceEncoding>(*it);

		auto encoded = encodeCharacter<TTargetEncoding>(character);

		for(auto i = 0; i < encoded.second; i++)
			result.push_back((encoded.first >> 8*i) & 0xFF); // Extract nth byte.
	}
	result.shrink_to_fit();
	return result;
}

template <Encoding>
struct EncodingConstIterator{ using Type = const char*; };

template <>
struct EncodingConstIterator<Ascii>{ using Type = const char*; };

template <>
struct EncodingConstIterator<Utf8>{ using Type = Utf8ConstIterator; };

template <>
struct EncodingConstIterator<Utf16>{ using Type = Utf16ConstIterator; };

template <>
struct EncodingConstIterator<Utf32>{ using Type = Utf32ConstIterator; };

}

template <Encoding TSourceEncoding, Encoding TTargetEncoding>
std::string convert( char const* begin_, char const* end_ )
{
	return impl::convert< impl::EncodingConstIterator<TSourceEncoding>::Type, TSourceEncoding, TTargetEncoding >( begin_, end_ );  
}

template <Encoding TSourceEncoding, Encoding TTargetEncoding>
std::string convert( std::string const & string_ )
{
	return convert<TSourceEncoding, TTargetEncoding>(string_.begin(), string_.end());
}

}

}