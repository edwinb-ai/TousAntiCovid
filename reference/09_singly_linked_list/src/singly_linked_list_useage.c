/*
 * Examples for the useage of a
 * singly linked list, as defined in
 * 'singly_linked_list.c' and
 * 'singly_linked_list.h'.
 *
 * M. Heinen, August 2017
 * marco@marco-heinen.de
 *
 */

#include "libraries.h"

#define LIST_LENGTH 8
#define DIGITS 3
#define DIGITS_STRING "3"



int main(void)
{
int i = 0, element = 0, list_content = 0;
struct singly_linked_list *sll;


/* Singly linked list initialization: */
printf("\n\nInitializing a singly linked list...");
allocate_and_initialize_sll(&sll);
printf(" Done.\n\n");
printf("\nContent of the singly linked list:\n");
print_sll(sll);
printf("The singly linked list has %d entries\n", sll_list_length(sll));


/* Filling the singly linked list with square numbers: */
printf("\n\nFilling the singly linked list...");
for(element = 1; element <= LIST_LENGTH; element++)
  {
  list_content = element * element;
  extend_sll(sll, list_content);
  } 
printf(" Done.\n\n");
printf("\nContent of singly linked list:\n");
print_sll(sll);
printf("The singly linked list has %d entries\n", sll_list_length(sll));


/* Querying the list for content: */
printf("\n\nTabloid of numbers that are contained in the singly linked list:\n\n");
for(list_content = 1; list_content <= LIST_LENGTH * LIST_LENGTH; list_content++)
  {
  if(is_in_sll(sll, list_content))
    {
    printf("%"DIGITS_STRING"d ", list_content);
    }
  else
    {
    for(i = 0; i < DIGITS; i++)
      {
      printf("_");
      }
    printf(" ");
    }
  if(0 == (list_content % LIST_LENGTH))
    {
    printf("\n");
    }
  }
printf("\n\n");


/* Removing content from the singly linked list: */
printf("\nTrying to remove entry %"DIGITS_STRING"d from the linked list...",\
       (LIST_LENGTH/2) * (LIST_LENGTH/2));
if( remove_content_from_sll(sll, (LIST_LENGTH/2) * (LIST_LENGTH/2)) )
  {
  printf(" Success.\n");
  }
else
  {
  printf(" List has no such entry.\n");
  }
printf("\nContent of singly linked list:\n");
print_sll(sll);
printf("The singly linked list has %d entries\n\n\n", sll_list_length(sll));


/* Trying to remove content from the singly linked list which is not present: */
printf("\nTrying to remove entry %"DIGITS_STRING"d from the linked list...",\
       (LIST_LENGTH+1) * (LIST_LENGTH+1));
if( remove_content_from_sll(sll, (LIST_LENGTH+1) * (LIST_LENGTH+1)) )
  {
  printf(" Success.\n");
  }
else
  {
  printf(" List has no such entry.\n");
  }
printf("\nContent of singly linked list:\n");
print_sll(sll);
printf("The singly linked list has %d entries\n\n\n", sll_list_length(sll));


/* Remove the last node from the singly linked list: */
printf("\nRemoving the last node from the linked list...");
if( remove_last_node_from_sll(sll) )
  {
  printf(" Success.\n");
  }
else
  {
  printf(" ERROR.\n");
  }
printf("\nContent of singly linked list:\n");
print_sll(sll);
printf("The singly linked list has %d entries\n\n\n", sll_list_length(sll));


/* Remove the last node from the singly linked list: */
printf("\nRemoving the last node from the linked list...");
if( remove_last_node_from_sll(sll) )
  {
  printf(" Success.\n");
  }
else
  {
  printf(" ERROR.\n");
  }
printf("\nContent of singly linked list:\n");
print_sll(sll);
printf("The singly linked list has %d entries\n\n\n", sll_list_length(sll));


/* Add content to the head of the singly linked list: */
printf("\nAdding content '12345' to the head of the linked list...");
extend_sll_at_head(&sll, 12345);
printf("\nContent of singly linked list:\n");
print_sll(sll);
printf("The singly linked list has %d entries\n\n\n", sll_list_length(sll));


/* Empty the singly linked list: */
printf("\nEmptying the linked list...");
empty_sll(sll);
printf(" Done.\n");
printf("\nContent of singly linked list:\n");
print_sll(sll);
printf("The singly linked list has %d entries\n\n\n", sll_list_length(sll));

return(1);
}



