#pragma once
//          Copyright 2022 Adrien Devresse.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)
#include <cstdint>
#include <string_view>

#include "detail/crc64_impl.hpp"

namespace constexpr_crypto {

// digest container
struct crc64_ecma{
	std::uint64_t data = 0;

	// definitions
	using digest_type  = std::uint64_t;
	const std::size_t digest_size = 8;
};


constexpr crc64_ecma compress(crc64_ecma && sum, std::string_view input){
	    std::uint64_t crc = sum.data;
        for (const char c : input) {
                crc = (crc << 8) ^ crc_tab64[ ((crc >> 56) ^ (uint64_t) c) & 0x00000000000000FFull ];
        }
        return crc64_ecma{ crc };
}

constexpr crc64_ecma::digest_type digest(crc64_ecma && sum){
	return sum.data;
}


} // constexpr_crypto