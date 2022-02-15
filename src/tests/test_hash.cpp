
#include <string_view>
#include <constexpr_crypto/hash/crc64.hpp>


using namespace constexpr_crypto;

constexpr void crc64_tests(){
	// crc64 "hello world" -> 1319870418925634090
	static_assert(digest(compress(crc64_ecma{}, std::string_view("hello world"))) == 1319870418925634090, "Digest invalid for CRC64");
}

int main(){

	crc64_tests();

	return 0;
}