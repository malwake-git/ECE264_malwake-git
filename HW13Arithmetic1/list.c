// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "calculate.h"

#ifdef TEST_READLIST
// read line by line from the input file
// each line shorter than WORDLENGTH (including '\n' and '\0')
// arithlist should have memory to store head and tail
// If arithlist is NULL, return false
// If fopen fails, return false
// If a line is too long,
//    free memory of the list
//    fclose
//    return false
// If everything is fine
//    fclose
//    arithlist points to the head and tail of the list
//    return true
bool readList(char * filename, List * arithlist)
{
  
  if(arithlist == NULL)
    {
      return false;
    }
  FILE *fptr = fopen(filename,"r");
  if(fptr == NULL)
    {
      return false;
    }

  ListNode * str = malloc(sizeof(ListNode));
  char *pch;

  while ((fgets((str->word),WORDLENGTH, fptr)) != NULL)
    {
      pch = strchr((str->word),'\n');
      if((pch-(str -> word)) > (WORDLENGTH-1))
	{
	  deleteList(arithlist);
	  free(str);
	  fclose(fptr);
	  return false;
	}
      addNode(arithlist, (str->word));

    }
  free(str);
  fclose(fptr);
  return true;
}
#endif

#ifdef TEST_DELETELIST
// If arithlist is NULL, do nothing
// release the memory of every node in the list
// release the memory of the list 
void deleteList(List * arithlist)
{
  if(arithlist == NULL)
    {
      return;
    }
  ListNode * head = arithlist -> head;
  ListNode * p = NULL;
  while(head != NULL)
    {
      p = head -> next;
      free(head);
      head = p;
    }
  free(head);
  free(p);
  free(arithlist);
  return;
}
#endif

#ifdef TEST_ADDNODE
ListNode * constructNode(char * word_l)
{
  ListNode * n = malloc(sizeof(ListNode));
  strcpy(n->word,word_l);
  //(n -> word) = word_l;
  ListNode * p = n;
  p -> next = NULL;
  //p -> prev = NULL;
  return n;
}
// Input: 
// arithlist stores the addresses of head and tail
// If arithlist is NULL, do nothing
// word is the word to be added
//
// Output:
// a ListNode is added to the end (become tail)
//
// allocate memory for a new ListNode
// copy word to the word attribute of the new ListNode
// insert the ListNode to the list
void addNode(List * arithlist, char * word)
{
  if(arithlist == NULL)
    {
      return;
    }
  ListNode * last = NULL;
  ListNode * newNode = constructNode(word);
  last = arithlist ->head;
  if(arithlist -> head == NULL)
    {
      newNode -> prev = NULL;
      arithlist -> head = newNode;
      arithlist -> tail = newNode;
      return;
    }
  while(last -> next != NULL)
    {
      last = last-> next;
    }

      arithlist -> tail = newNode;
    
  last->next = newNode;

  newNode -> prev = last;

  return;
}
#endif

#ifdef TEST_DELETENODE
//  Input:
// arithlist stores the addresses of head and tail
// If arithlist is NULL, return false
// If the list is empty (head and tail are NULL), return false
// ln is the node to be deleted
// If ln is not in the list, return false
// 
// Output:
// arithlist stores the addresses of head and tail
//   after ln is deleted
// return true.
//
// Be careful about delete the first or the last node
bool deleteNode(List * arithlist, ListNode * ln)
{
  if(arithlist == NULL || ln == NULL)
    {
      return false;
    }
  if(((arithlist -> head) == NULL) && ((arithlist -> tail) == NULL))
    {
      return false;
    }

  if(arithlist->head == ln)
    {
      arithlist->head = ln->next;
    }

  if(ln->next != NULL)
    {
      ln ->next->prev = ln->prev;
    }
  if (ln->prev != NULL)
    {
      ln->prev->next = ln->next;
    }
  free(ln);

  return true;
}
#endif

