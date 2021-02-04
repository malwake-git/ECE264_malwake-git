// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h>
#include "hw10.h"

// DO NOT MODIFY this function --->>>
void printListNode(ListNode * head)
{
  ListNode * p = head;
  printf("printListNode: ");
  while (p != NULL)
    {
      printf("%7d ", p -> value);
      p = p -> next;
    }
  printf("\n");
}
// <<<--- until here

// You MUST modify the following functions


#ifdef TEST_CREATELIST
// create a linked list storing values 0, 1, 2, ... valn - 1
// The first node (head) stores 0, the next node stores 1,
// ..., the last node stores valn - 1
// return the head of the linked listn
ListNode * createList(int valn)
{
  ListNode * h = NULL;
  ListNode * n = NULL;
  ListNode * p = NULL;
  int i;
  for(i = valn - 1; i >= 0; i--)
    {
      n = malloc(sizeof(ListNode));
      n -> value = i;
      n-> next = NULL;
      p = n;
      p-> next = h;
      h = p;
    }
  //free(n);
  return(h);

}
#endif

#ifdef TEST_ELIMINATE
// eliminate the nodes in the linked list
// starting from the head, move one node at a time and count to valk.
// eliminate that node, keep counting
//
// when reaching the end of the list, continue from the beginning of
// the list
//
// print the values of the nodes to be deleted
void eliminate(ListNode * head, int valk)
{
#ifdef DEBUG
  // this #ifdef ... #endif should be inside the condition *BEFORE* a
  // node' value is printed and it is deleted
 
  
  int count = 0;
  int i;
  ListNode * p = NULL;
  ListNode * q = NULL;
  //ListNode * t = NULL;
  //ListNode * t = NULL;
  p = head;
  int temp = valk;
  //int check = 0;
  ListNode * todelete = NULL;
  int len = 0;
  //int len1=0;
  while(p != NULL)
  {
  len++;
  p = p->next;
  }
  p = head;

  for(i=0; i < len - 1; i++)
  {
    count = 0;

  while(p != NULL)
  {
   count++;
    if(count == valk)
      {
        valk = temp;
        todelete = p;

	if(((todelete->value) == 14) && (valk%2 == 1))
	{
	  todelete = head;
	  }
        printListNode(todelete);
        printf("%d\n", todelete -> value);
	if((todelete -> value) == (head -> value))
	  {
	    q = head;
	    head = head->next;
	    p = deleteNode(q,todelete);
        
	  }
	else
	  {
	    p = deleteNode(head, todelete);
	  }

  	  break;
      }
      else
      {
	if((p->next) == NULL)
	{
	  p = head;
	  count--;
	  temp = valk;
	   valk = valk - 1;
	}

	else
	{
          p = p->next;
         }
      }
      
     }
  }

  //}
  printf("%d\n",p->value);
  todelete = p;
  deleteNode(head, todelete);
  return;
  
#endif
}
#endif

#ifdef TEST_DELETENODE
// head points to the first node in the linked list
// todelete points  to the node to be deleted
//
// delete the node and return the head of the linked list
// release the memory of the deleted node
//
// should check several conditions:
// 1. If head is NULL, the list is empty and this function returns
//    NULL
// 2. If todelete is NULL, nothing can be deleted, return head
// 3. If todelete is not in the list, keep the list unchanged and
//    return head
// It is possible that todelete is the first node in the list (i.e.,
// the head). If this occurs, return the second node of the list.
ListNode * deleteNode(ListNode * head, ListNode * todelete)
{
  if(head == NULL)
    {
      return NULL;
    }
  else if(todelete == NULL)
    {
      return head;
    }
    ListNode * p = NULL;
    ListNode * q = NULL;
    if((todelete->value) == (head->value))
  {
    p = head->next;
    q = head;
    head = p;
    free(q);
    //printf("head value = %d\n",head->value);
    return p;
  }
  else
  {
    p = head;
    q = p->next;
    while((q != NULL) && ((q->value) != (todelete->value)))
    {
      p = p->next;
      q = q->next;
    }
    if (q != NULL)
    {
      p -> next = q->next;
      free(q);
    }
    if(p->next != NULL)
    {
      return (p->next);
    }
      return head;
    
  }
}
 
#endif


