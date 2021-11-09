#include "_cgo_export.h"

char* mallocChar(int size) {
	char* str = (char*)malloc(sizeof(char) * size);
	memset(str, 0, sizeof(char) * size);
	return str;
}

void copyChar(char* str, const char* v) {
	memcpy(str, v, strlen(v));
}

KV_return** mallocKVStruct(int limit) {
        KV_return** result = (KV_return**)malloc(sizeof(KV_return*) * limit);
        int i;
        for (i = 0; i < limit; ++i) {
                result[i] = (KV_return*)malloc(sizeof(KV_return));
                result[i]->k = (char*)malloc(sizeof(char) * 1024);
                result[i]->v = (char*)malloc(sizeof(char) * 102400);
		memset(result[i]->k, 0, sizeof(char) * 1024);
		memset(result[i]->v, 0, sizeof(char) * 102400);
        }
        return result;
}

void copyKVStruct(KV_return** kv_return, const char* k, const char* v, int index) {
	printf("XXXXXX: k: %s v: %s\n", k, v);
        memcpy(kv_return[index]->k, k, strlen(k));
        memcpy(kv_return[index]->v, v, strlen(v));
	printf("XXXXXX: kv_return->k: %s kv_return->v: %s\n", kv_return[index]->k, kv_return[index]->v);
}

void FreeKVStruct(KV_return** kv_return, int limit){
        if(kv_return != 0){
                int i;
                for (i = 0; i < limit; ++i) {
                        if(kv_return[i]->k != 0) {
                                free(kv_return[i]->k);
                                printf("free %i k\n", i);
                        }                                    
                        if(kv_return[i]->v != 0) {
                                free(kv_return[i]->v);
                                printf("free %i v\n", i);
                        }
                        free(kv_return[i]);
                        printf("free kv_retrun\n");
                }
        }
}

char* getKVStructKey(KV_return** kv, int index) {
	return kv[index]->k;
}

char* getKVStructVal(KV_return** kv, int index) {
	return kv[index]->v;
}

char* getKeys(char** keys, int index) {
	return keys[index];
}
