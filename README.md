# STACK

---

Stack implementation in C99.

**THIS PROJECT HAS BEED MOVED TO [QUEST](https://github.com/itsjustgalileo/quest/)**

---

## PREREQUISITES

- C99 compiler.

---

## EXAMPLE

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

/* A simple struct to store in the stack */
typedef struct {
    int id;
    char name[32];
} Person;

int main(void) {
    /* Initialize a stack to hold 5 Person structs */
    Stack *stack = stack_init(5, sizeof(Person));
    if (!stack) {
        fprintf(stderr, "Failed to create stack\n");
        return EXIT_FAILURE;
    }

    /* Create some Person instances */
    Person alice = { .id = 1, .name = "Alice" };
    Person bob   = { .id = 2, .name = "Bob" };
    Person carol = { .id = 3, .name = "Carol" };

    /* Push them onto the stack */
    stack_push(stack, &alice);
    stack_push(stack, &bob);
    stack_push(stack, &carol);

    /* Inspect the top element */
    Person *top = (Person *)stack_top(stack);
    printf("Top: %s (id=%d)\n", top->name, top->id);

    /* Pop elements from the stack */
    Person p;
    while (!stack_is_empty(stack)) {
        stack_pop(stack, &p);
        printf("Popped: %s (id=%d)\n", p.name, p.id);
    }

    /* Reset stack (optional) */
    stack_reset(stack);

    /* Cleanup */
    stack_cleanup(stack);

    return 0;
}
```
