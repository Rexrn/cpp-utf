#pragma once

#include "Encoding.hpp"

namespace rexrn
{

namespace cpp_utf
{

template <Encoding TEncoding>
char32_t decodeCharacter(char32_t encodedCharacter_) // = delete // TODO: <-- uncomment this, remove implementation and implement specializations.
{
	return encodedCharacter_;
}

template <Encoding TEncoding>
char32_t encodeCharacter(char32_t unicodeCharacter_) // = delete // TODO: <-- uncomment this, remove implementation and implement specializations.
{
	return unicodeCharacter_;
}

}

}