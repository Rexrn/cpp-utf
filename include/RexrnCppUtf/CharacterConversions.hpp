#pragma once

#include "Encoding.hpp"
#include "Endianness.hpp"

#include <utility> // std::pair

namespace rexrn
{

namespace cpp_utf
{

template <Encoding TSourceEncoding, Endianness TSourceEndianness = NativeEndianness>
char32_t decodeCharacter(char32_t encodedCharacter_) // = delete // TODO: <-- uncomment this, remove implementation and implement specializations.
{
	return encodedCharacter_;
}

template <Encoding TTargetEncoding, Endianness TTargetEndianness = NativeEndianness>
std::pair<char32_t, int> encodeCharacter(char32_t unicodeCharacter_) // = delete // TODO: <-- uncomment this, remove implementation and implement specializations.
{
	return std::make_pair(unicodeCharacter_, sizeof(unicodeCharacter_));
}

}

}