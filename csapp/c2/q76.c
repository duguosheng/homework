#include <assert.h>
#include <inttypes.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

void* my_calloc(size_t nmemb, size_t size) {
    if (nmemb == 0 || size == 0) return NULL;

    size_t wantsize = nmemb * size;
    if (wantsize / nmemb != size) return NULL;

    void* mem = malloc(wantsize);
    if (mem) memset(mem, 0, wantsize);
    return mem;
}

int main(void) {
    assert(my_calloc(2, SIZE_MAX) == NULL);
    assert(my_calloc(200, sizeof(int)) != NULL);
    return 0;
}
