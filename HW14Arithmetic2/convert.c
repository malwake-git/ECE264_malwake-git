// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "list.h"
#include "convert.h"

// DO NOT MODIFY FROM HERE --->>>
const int Operations[] = {'+', '-', '*', '(', ')'};

// return -1 if the word is not an operator
// return 0 if the word contains '+'
//        1                      '-'
//        2                      '*'
//        3                      '('
//        4                      ')'
int isOperator(char * word)
{
  int ind;
  int numop = sizeof(Operations) / sizeof(int);
  for (ind = 0; ind < numop; ind ++)
    {
    char *loc = strchr(word, Operations[ind]);
    if (loc != NULL && !isdigit(loc[1]))
	{
	  return ind;
	}
    }
  return -1;
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the convert function
// ***

#ifdef TEST_CONVERT
int prc(char * a);

bool convert(List * arithlist)
{
  if (arithlist == NULL)
    {
      return true;
    }
  if ((arithlist -> head) == NULL)
    {
      return true;
    }
  List * stack = NULL;
  List * que = NULL;
  ListNode * op = NULL;
  ListNode * oper = NULL;
  ListNode * ln = NULL;
  ListNode * temp = NULL;
  ListNode * temp1 = NULL;
  int cmp1=0;
  int cmp2=0;
  que = malloc(sizeof(List));
  que -> head = NULL;
  que ->tail = NULL;
  stack = malloc(sizeof(List));
  stack -> head = NULL;
  stack -> tail = NULL;
  oper = arithlist->head;
  while(oper != NULL)
    {
       if((isOperator(oper->word)) != -1)
       {
	 if(prc(oper->word) == 4)
	   {
	     addNode(que,op->word);
	     ln = ln -> next;
	     temp = op;
	     op = op ->prev;
	     deleteNode(stack,temp);
	     if(oper->next == NULL)
	       {
		 oper = oper->next;
		 break;
	       }
	     oper = oper->next;
	   }
	  cmp1 = 0;
	  cmp2 = 0;
	  if(stack->head != NULL)
	    {
	       cmp2 = prc(op->word);
	       cmp1 = prc(oper->word);
	    }
	  else
	    {
	      if(prc(oper->word) != 3 && prc(oper->word) != 4)
		{
		  addNode(stack,oper->word);
		  op = stack ->head;
		}
	    }
	  if(cmp1 == 3)
	    {
	      
	      
	      while(prc(oper->word) != 4)
		{
		  oper = oper->next;		  
		  if(isOperator(oper->word) == -1)
		    {
		      addNode(que,oper->word);
		      ln = ln ->next;
		    }
		  else
		    {
		      if(prc(oper->word) != 3 && prc(oper->word) != 4)
			{
			  addNode(stack,oper->word);
			  op = op->next;
			}
		      else
			{
			  addNode(que, op->word);
			  ln = ln -> next;
			  temp = op;
			  op = op->prev;
			  deleteNode(stack,temp);
			}
		    }
		}
	      cmp1 = 0;
	      cmp2 = 0;
	       }
	  else if(cmp1 > cmp2)
	    {
	      addNode(stack,oper->word);
	      op = op->next;
	    }
	  else if(cmp1 < cmp2)
	    {
	      temp1 = op;
	      while(temp1 != NULL)
		{ 
		  addNode(que, temp1->word);
		  temp = temp1;
		  temp1 = temp1->prev;
		  deleteNode(stack,temp);
		}
	      addNode(stack, oper->word);
	      op = stack -> head;
	    }
	  	}
      else
	{
	   if(que->head == NULL)
	     {
	       addNode(que,oper->word);
	       ln = que ->head;
	     }
	   else
	     {
	       addNode(que,oper->word);
	       ln = ln ->next;
	     }
	}
       if(oper->next == NULL)
	{
	  break;
	}
	oper = oper->next;   
    }
  while(op != NULL)
    { 
      addNode(que, op->word);
      if(op->prev == NULL)
	{
	  break;
	}
      op = op->prev;
    }
  deleteList(stack);
  ln = que->head;
  oper = arithlist->head;
  temp1 = arithlist->tail;
  while(oper != NULL)
  {
    op = oper;

    oper = oper->next;
    deleteNode(arithlist,op);
  }
  while(ln != NULL)
    {
      addNode(arithlist, ln->word);
      if(ln ->next == NULL)
	{
	  break;
	}
      ln = ln ->next;
    }
  deleteList(que);
  return true;
}
#endif

#ifdef TEST_CONVERT
int prc(char* a)
{
  switch(*a){
  case'+':
    return 1;
  case'-':
    return 1;
  case'*':
    return 2;
  case'(':
    return 3;
  case')':
    return 4;
  }
  return 0;
}
#endif
