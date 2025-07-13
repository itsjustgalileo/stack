#ifndef QUEST_STACK_H_
#define QUEST_STACK_H_

#include <quest/quest_common.h>

#include <quest/quest_header.h>
 
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

    typedef struct quest_stack quest_stack_t;

    extern QUEST_API quest_stack_t *QUEST_DECL quest_stack_init(size_t size, size_t count);
    extern QUEST_API void QUEST_DECL quest_stack_cleanup(quest_stack_t *s);

    extern QUEST_API bool QUEST_DECL quest_stack_push(quest_stack_t *s, void *elem);
    extern QUEST_API bool QUEST_DECL quest_stack_pop(quest_stack_t *s, void *out_elem);

    extern QUEST_API size_t QUEST_DECL quest_stack_size(quest_stack_t *s);
    extern QUEST_API bool QUEST_DECL quest_stack_is_empty(quest_stack_t *s);
    extern QUEST_API bool QUEST_DECL quest_stack_reset(quest_stack_t *s);
    extern QUEST_API void *QUEST_DECL quest_stack_top(quest_stack_t *s);
    
#ifdef __cplusplus
}
#endif /* __cplusplus */

#include <quest/quest_footer.h>

#endif /* QUEST_STACK_H_ */
