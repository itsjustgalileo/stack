#ifndef STACK_H_
#define STACK_H_

typedef struct Stack Stack;

Stack *stack_init(size_t size, size_t count);
void stack_cleanup(Stack *s);

bool stack_push(Stack *s, void *elem);
bool stack_pop(Stack *s, void *out_elem);

size_t stack_size(Stack *s);
bool stack_is_empty(Stack *s);
bool stack_reset(Stack *s);
void *stack_top(Stack *s);

#endif /* STACK_H_ */
