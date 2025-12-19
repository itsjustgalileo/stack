#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "./stack.h"


struct Stack {
    void *elems;
    size_t elem_size;
    size_t capacity; /* Stack size */
    size_t offset; /* technically, this is a Stack pointer */
    /* bool dynamic; just a thought for later */
};

Stack *stack_init(size_t nmemb, size_t size) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (NULL == s) {
        fprintf(stderr, "[stack_init]: Failed to allocate memory for stack\n");
        return NULL;
    }
    s->elem_size = size;
    s->capacity = nmemb;
    s->elems = malloc(s->capacity * s->elem_size);
    if (NULL == s->elems) {
        fprintf(stderr, "[stack_init]: Failed to allocate memory for stack elements\n");
        free(s);
        return NULL;
    }
    s->offset = 0;
#ifndef NDEBUG
    memset(s->elems, 0xAD, s->elem_size * s->capacity);
#endif /* NDEBUG */
    return s;
}

void stack_cleanup(Stack *s) {
    assert(s);
    free(s->elems);
    free(s);
}

bool stack_push(Stack *s, void *elem) {
    assert(s && elem);
    if (s->offset >= s->capacity) {
        /*
        if (false == s->dynamic) {
            return false;
        }
        size_t new_cap = s->capacity ? s->capacity * 2 : 1;
        void *new_elems = realloc(s->elems, new_cap * s->elem_size);
        if (NULL == new_elems) return false;
        
        s->elems = new_elems;
        s->capacity = new_cap;
        */
        fprintf(stderr, "[stack_push]: stack overflow\n");
        return false;
    }

    void *dest = (char *)s->elems + s->offset * s->elem_size;
    memcpy(dest, elem, s->elem_size);
    ++s->offset;
    return true;
}

bool stack_pop(Stack *s, void *out_elem) {
    assert(s && s->offset > 0 && out_elem);
    --s->offset;
    void *src = (char *)s->elems + s->offset * s->elem_size;
    memcpy(out_elem, src, s->elem_size);
    return true;
}

size_t stack_size(Stack *s) {
    assert(s);
    return s->offset;
}

bool stack_is_empty(Stack *s) {
    assert(s);
    return s->offset == 0;
}

bool stack_reset(Stack *s) {
    assert(s);
#ifndef NDEBUG
    memset(s->elems, 0xDE, s->elem_size * s->capacity);
#endif /* NDEBUG */
    s->offset = 0;
    return true;
}

void *stack_top(Stack *s) {
    assert(s && s->offset > 0);
    return (char *)s->elems + (s->offset - 1) * s->elem_size;
}
