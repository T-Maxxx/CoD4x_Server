FLAGS="-m32 -Wall -Os -s -c -I. -DLTC_NO_ROLC -DLTC_SOURCE"
MATHFLAGS="-m32 -Wall -Os -s -c -I. -Imath -DLTC_NO_ROLC -DLTC_SOURCE"
gcc $FLAGS ciphers/aes/aes.c
gcc $FLAGS hashes/*.c
gcc $FLAGS misc/crypt/*.c
gcc $FLAGS misc/base64/*.c
gcc $FLAGS misc/*.c
gcc $FLAGS misc/pkcs5/*.c
gcc $FLAGS mac/hmac/*.c
gcc $FLAGS pk/asn1/der/sequence/*.c
gcc $FLAGS pk/asn1/der/bit/*.c
gcc $FLAGS pk/asn1/der/boolean/*.c
gcc $FLAGS pk/asn1/der/choice/*.c
gcc $FLAGS pk/asn1/der/ia5/*.c
gcc $FLAGS pk/asn1/der/integer/*.c
gcc $FLAGS pk/asn1/der/object_identifier/*.c
gcc $FLAGS pk/asn1/der/octet/*.c
gcc $FLAGS pk/asn1/der/printable_string/*.c
gcc $FLAGS pk/asn1/der/sequence/*.c
gcc $FLAGS pk/asn1/der/short_integer/*.c
gcc $FLAGS pk/asn1/der/utctime/*.c
gcc $FLAGS pk/asn1/der/utf8/*.c
gcc $FLAGS pk/asn1/der/set/*.c
gcc $FLAGS pk/rsa/*.c
gcc $FLAGS pk/pkcs1/*.c
gcc $MATHFLAGS math/*.c

ar cr ../../lib/libtomcrypt_linux.a *.o

rm *.o
