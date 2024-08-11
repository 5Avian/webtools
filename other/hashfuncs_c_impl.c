// A C implementation of the hash functions
// in `www/hashfuncs.html` to compare with.

#include <stdio.h>
#include <inttypes.h>

uint32_t djb2_32(uint8_t *str) {
	uint32_t hash = 5381;
	while (*str != '\0') {
		hash = ((hash << 5) + hash) + *str;
		str += 1;
	}
	return hash;
}
uint64_t djb2_64(uint8_t *str) {
	uint64_t hash = 5381;
	while (*str != '\0') {
		hash = ((hash << 5) + hash) + *str;
		str += 1;
	}
	return hash;
}
uint32_t sdbm_32(uint8_t *str) {
	uint32_t hash = 0;
	while (*str != '\0') {
		hash = *str + (hash << 6) + (hash << 16) - hash;
		str += 1;
	}
	return hash;
}
uint64_t sdbm_64(uint8_t *str) {
	uint64_t hash = 0;
	while (*str != '\0') {
		hash = *str + (hash << 6) + (hash << 16) - hash;
		str += 1;
	}
	return hash;
}
uint32_t fnv_1_32(uint8_t *str) {
	uint32_t hash = 0x811c9dc5;
	while (*str != '\0') {
		hash *= 0x1000193;
		hash ^= *str;
		str += 1;
	}
	return hash;
}
uint64_t fnv_1_64(uint8_t *str) {
	uint64_t hash = 0xcbf29ce484222325;
	while (*str != '\0') {
		hash *= 0x100000001b3;
		hash ^= *str;
		str += 1;
	}
	return hash;
}
uint32_t fnv_1a_32(uint8_t *str) {
	uint32_t hash = 0x811c9dc5;
	while (*str != '\0') {
		hash ^= *str;
		hash *= 0x1000193;
		str += 1;
	}
	return hash;
}
uint64_t fnv_1a_64(uint8_t *str) {
	uint64_t hash = 0xcbf29ce484222325;
	while (*str != '\0') {
		hash ^= *str;
		hash *= 0x100000001b3;
		str += 1;
	}
	return hash;
}
uint32_t one_at_a_time_32(uint8_t *str) {
	uint32_t hash = 0;
	while (*str != '\0') {
		hash += *str;
		hash += hash << 10;
		hash ^= hash >> 6;
		str += 1;
	}
	hash += hash << 3;
	hash ^= hash >> 11;
	hash += hash << 15;
	return hash;
}
uint64_t one_at_a_time_64(uint8_t *str) {
	uint64_t hash = 0;
	while (*str != '\0') {
		hash += *str;
		hash += hash << 10;
		hash ^= hash >> 6;
		str += 1;
	}
	hash += hash << 3;
	hash ^= hash >> 11;
	hash += hash << 15;
	return hash;
}

int main(int argc, char **argv) {
	(void) argc;
	(void) argv;
	uint8_t *str = (uint8_t *) "hash me";
	printf("str: %s\n", str);
	printf("djb2_32: %u\n", djb2_32(str));
	printf("djb2_64: %llu\n", djb2_64(str));
	printf("sdbm_32: %u\n", sdbm_32(str));
	printf("sdbm_64: %llu\n", sdbm_64(str));
	printf("fnv_1_32: %u\n", fnv_1_32(str));
	printf("fnv_1_64: %llu\n", fnv_1_64(str));
	printf("fnv_1a_32: %u\n", fnv_1a_32(str));
	printf("fnv_1a_64: %llu\n", fnv_1a_64(str));
	printf("one_at_a_time_32: %u\n", one_at_a_time_32(str));
	printf("one_at_a_time_64: %llu\n", one_at_a_time_64(str));
	return 0;
}
