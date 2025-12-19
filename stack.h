/**
 * @file stack.h
 * @author itsjustgalileo
 * @version 1.2
 */
#ifndef STACK_H_
#define STACK_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

    /**
     * @brief Opaque type representing a generic stack.
     */
    typedef struct Stack Stack;

    /**
     * @brief Initialize a stack capable of holding a fixed number of elements.
     *
     * @param count Number of elements the stack can hold.
     * @param size Size of each element in bytes.
     * @return Pointer to a newly allocated Stack, or NULL on failure.
     */
    extern Stack *stack_init(size_t count, size_t size);

    /**
     * @brief Free all resources associated with a stack.
     *
     * @param s Pointer to the stack to clean up.
     */
    extern void stack_cleanup(Stack *s);

    /**
     * @brief Push a new element onto the stack.
     *
     * @param s Pointer to the stack.
     * @param elem Pointer to the element to push.
     * @return true if the push was successful, false if the stack is full.
     */
    extern bool stack_push(Stack *s, void *elem);

    /**
     * @brief Pop the top element from the stack.
     *
     * @param s Pointer to the stack.
     * @param out_elem Pointer to memory where the popped element will be copied.
     * @return true if the pop was successful, false if the stack was empty.
     */
    extern bool stack_pop(Stack *s, void *out_elem);

    /**
     * @brief Get the current number of elements in the stack.
     *
     * @param s Pointer to the stack.
     * @return Number of elements currently stored.
     */
    extern size_t stack_size(Stack *s);

    /**
     * @brief Check whether the stack is empty.
     *
     * @param s Pointer to the stack.
     * @return true if the stack is empty, false otherwise.
     */
    extern bool stack_is_empty(Stack *s);

    /**
     * @brief Reset the stack to empty without deallocating memory.
     *
     * @param s Pointer to the stack.
     * @return true on success.
     */
    extern bool stack_reset(Stack *s);

    /**
     * @brief Get a pointer to the top element of the stack without removing it.
     *
     * @param s Pointer to the stack.
     * @return Pointer to the top element.
     */
    extern void *stack_top(Stack *s);
    
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* STACK_H_ */
