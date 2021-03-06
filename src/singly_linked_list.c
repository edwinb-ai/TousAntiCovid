/*
 * The singly linked list which is implemented here
 * will always end with a node called 'end cap'.
 * The end cap has 'id' = 0 and 'next' = NULL.
 * The 0 'id' of the end cap is not counted as
 * a id of the list.
 *
 * NOTE: The singly linked list must be allocated
 * by the function 'allocate_and_initialize_sll()'.
 * Otherwise, the 'remove_id_from_sll()'
 * function may cause a runtime error by calling
 * free() on a non previously allocated sll. 
 *
 */

#include "libraries.h"


struct singly_linked_list *allocate_and_initialize_sll(
  struct singly_linked_list **sll
){
  *sll = (struct singly_linked_list *)malloc(sizeof(struct singly_linked_list));
  if(NULL == *sll)
  {
    printf("\n\nAllocation error in function"\
           " 'allocate_and_initialize_sll()'\n\n");
    exit(0);
  }

  (*sll)->p = NULL;  /* This is equivalent to (*(*sll)).id */
  (*sll)->next =NULL;
  return(*sll);
}



int sll_list_length(struct singly_linked_list *sll)
{
  if(NULL != sll->next){
    return(1 + sll_list_length(sll->next));
  }
  else {
    return(0);
  }
}



int print_sll(struct singly_linked_list *sll)
{
  if(NULL == sll->next){
    printf("End of list.\n");
  }
  else{
    printf("%p \n", (void *)(sll->p));
    print_sll(sll->next);
  }

  return(1);
}



int extend_sll(struct singly_linked_list *sll, Person *p)
{
/*
 * Example behaviors for p = 0x00ff:
 *   [NULL]->NULL
 *     becomes 
 *      [0x00f]->[NULL]->NULL
 *  
 *   [0x0001]->[0x0002]->[0x0003]->[NULL]->NULL 
 *      becomes
 *      [0x0001]->[0x0002]->[0x0003]->[0x00ff]->[NULL]->NULL 
 *
 */
  if(NULL != sll->next){
    extend_sll(sll->next, p);
  }
  else {
    sll->next = (struct singly_linked_list *)malloc(sizeof(struct singly_linked_list));
    if(NULL == sll->next){
      printf("\n\nAllocation error in function 'extend_sll()'\n\n");
      exit(EXIT_FAILURE);
    }
    sll->p = p;
    sll->next->p = NULL;
    sll->next->next =NULL;
  }
  return(1);
}



struct singly_linked_list *extend_sll_return_lastnode(
  struct singly_linked_list *sll, 
  Person *p
){
/*
 * Same as 'extend_sll', but also returns a pointer
 * to the last node of the sll before the end cap node.
 *
 */
  if(NULL != sll->next){
    return(extend_sll_return_lastnode(sll->next, p));
  }
  else{
    sll->next = (struct singly_linked_list *)malloc(sizeof(struct singly_linked_list));
    if(NULL == sll->next){
      printf("\n\nAllocation error in function 'extend_sll()'\n\n");
      exit(EXIT_FAILURE);
    }
    sll->p = p;
    sll->next->p = NULL;
    sll->next->next =NULL;
  return(sll);
  }
}
  


Person *extend_sll_at_head(
  struct singly_linked_list **sll, 
  Person *p
){
/*
 * Example behaviors for 'id' = 17:
 * [0]->NULL  is changed to  [17]->[0]->NULL 
 * [3]->[0]->[1]->[0]->NULL is changed to [17]->[3]->[0]->[1]->[0]->NULL
 * The return value is 'id'.
 *
 */
  struct singly_linked_list *tmp_listptr;
  Person *tmp_p;
  
  tmp_p = (*sll)->p;
  tmp_listptr = (*sll)->next;

  free(*sll);
  allocate_and_initialize_sll(sll);
  
  extend_sll(*sll, p);
  extend_sll(*sll, tmp_p);

  free((*sll)->next->next->next);
  free((*sll)->next->next);
  (*sll)->next->next = tmp_listptr;

  return(p);
}



int is_in_sll(struct singly_linked_list *sll, Person *p)
{/* O(n) search */
  if(NULL != sll->next){
    if(p == sll->p){
      return(TRUE);
    }
    else{
      return(is_in_sll(sll->next, p));
    }
  }

  return(FALSE);
}



int remove_person_from_sll(struct singly_linked_list *sll, Person *p)
{
  Person *bufferper;
  struct singly_linked_list *bufferptr;

  /* Test that sll is not the end cap node of the list */ 
  if(NULL != sll->next) {
    if(p == sll->p){
      bufferper = sll->next->p;
      bufferptr = sll->next->next;
      free(sll->next);
      /* Avoid memory leaks : */
      free(p);
      p = NULL;
      sll->p = bufferper;
      sll->next = bufferptr;
      return(TRUE);
    }
    else{
      return( remove_person_from_sll(sll->next, p) );
    }
  }

  return(FALSE);
}



int empty_sll(struct singly_linked_list *sll)
{
  Person *p;
  while(NULL != sll->next){
    p = pop_last_node_from_sll(sll);
    free(p);
  }
  return(TRUE);
}



Person *pop_last_node_from_sll(struct singly_linked_list *sll)
{
/*
 * Removes the last node with actual id (not the cap node)
 * and returns the id that was stored in that node before
 * it got removed.
 *
 */
  Person *id = NULL;

  if(NULL == sll->next){
    return(sll->p);
  }

  if(NULL == sll->next->next){
    /* save id : */
    id = sll->p;
    /* call free(NULL) */
    free(sll->next->next);
    /* call free on next node */
    /* SHOULD CALL FREE ON `next_node->p` FIRST ! */
    free(sll->next);
    sll->p = NULL;
    sll->next = NULL;
    return(id);
  }

  if(NULL != sll->next->next){
    return(pop_last_node_from_sll(sll->next));
  }

  return(NULL); /* This return() should never be reached. */
}
