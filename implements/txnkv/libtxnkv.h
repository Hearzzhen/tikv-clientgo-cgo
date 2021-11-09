/* Code generated by cmd/cgo; DO NOT EDIT. */

/* package txnkv */


#line 1 "cgo-builtin-export-prolog"

#include <stddef.h> /* for ptrdiff_t below */

#ifndef GO_CGO_EXPORT_PROLOGUE_H
#define GO_CGO_EXPORT_PROLOGUE_H

#ifndef GO_CGO_GOSTRING_TYPEDEF
typedef struct { const char *p; ptrdiff_t n; } _GoString_;
#endif

#endif

/* Start of preamble from import "C" comments.  */


#line 17 "txnkv.go"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char* k;
	char* v;
} KV_return;

extern char* mallocChar(int size);
extern void copyChar(char* str, const char* v);
extern KV_return** mallocKVStruct(int limit);
extern void copyKVStruct(KV_return** kv_return, const char* k, const char* v, int index);
extern void FreeKVStruct(KV_return** kv_return, int limit);
extern char* getKVStructKey(KV_return** kv, int index);
extern char* getKVStructVal(KV_return** kv, int index);
extern char* getKeys(char** keys, int index);

#line 1 "cgo-generated-wrapper"


/* End of preamble from import "C" comments.  */


/* Start of boilerplate cgo prologue.  */
#line 1 "cgo-gcc-export-header-prolog"

#ifndef GO_CGO_PROLOGUE_H
#define GO_CGO_PROLOGUE_H

typedef signed char GoInt8;
typedef unsigned char GoUint8;
typedef short GoInt16;
typedef unsigned short GoUint16;
typedef int GoInt32;
typedef unsigned int GoUint32;
typedef long long GoInt64;
typedef unsigned long long GoUint64;
typedef GoInt64 GoInt;
typedef GoUint64 GoUint;
typedef __SIZE_TYPE__ GoUintptr;
typedef float GoFloat32;
typedef double GoFloat64;
typedef float _Complex GoComplex64;
typedef double _Complex GoComplex128;

/*
  static assertion to make sure the file is being used on architecture
  at least with matching size of GoInt.
*/
typedef char _check_for_64_bit_pointer_matching_GoInt[sizeof(void*)==64/8 ? 1:-1];

#ifndef GO_CGO_GOSTRING_TYPEDEF
typedef _GoString_ GoString;
#endif
typedef void *GoMap;
typedef void *GoChan;
typedef struct { void *t; void *v; } GoInterface;
typedef struct { void *data; GoInt len; GoInt cap; } GoSlice;

#endif

/* End of boilerplate cgo prologue.  */

#ifdef __cplusplus
extern "C" {
#endif


// Init initializes information.
extern void initStore(GoString ip_address);

// key1 val1 key2 val2 ...
extern GoInt putsKV(GoString key, GoString value);
extern GoInt putsKVMap(KV_return** kv, GoInt size);

/* Return type for getKV */
struct getKV_return {
	char* r0; /* value */
	GoInt r1; /* e */
};
extern struct getKV_return getKV(GoString k);
extern void freeCBytes(char* ptr);
extern GoInt delKey(GoString key);
extern GoInt delKeys(char** keys, GoInt size);

/* Return type for scanKV */
struct scanKV_return {
	KV_return** r0; /* ret */
	GoInt r1; /* e */
};
extern struct scanKV_return scanKV(GoString keyPrefix, GoInt limit);
extern void FreeKV(KV_return** ret, GoInt limit);

#ifdef __cplusplus
}
#endif
