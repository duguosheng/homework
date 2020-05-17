#include <iostream>

using std::bad_alloc;
using std::size_t;

void* operator new(size_t size) {
    if (void* mem = malloc(size))
        return mem;
    else
        throw bad_alloc();
}

void operator delete(void* mem) noexcept {
    free(mem);
}

int main(void) {
    return 0;
}
