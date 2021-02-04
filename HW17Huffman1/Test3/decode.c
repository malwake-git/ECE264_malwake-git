// Modify this file at said locations
#include "decode.h"
#include "list.h"
#include "utility.h"

#ifdef TEST_READHEADER
int CountNodes(ListNode * head)
{
  int nodes = 0;
  while(head != NULL)
  {  head=head->next; nodes++;  }
  return nodes;
}

ListNode * PopLList(ListNode * head)
{
  ListNode * list_pop = head;
  if (head->next != NULL) *head = *head->next;
  return list_pop;
}

TreeNode * readHeader(FILE * infptr)
{
  int done = 0;
  unsigned char whichbit = 0;
  unsigned char curbyte  = 0;
  unsigned char onebit   = 0;
  ListNode * head = NULL;
  // decreasing to ensure the list is a stack
  while (done == 0)
    {
      readBit(infptr, & onebit, & whichbit, & curbyte);
      if (onebit == 1)
	{
	  // a leaf node, get 7 move bits
	  int bitcount;
	  unsigned char value = 0;
	  for (bitcount = 0; bitcount < 7; bitcount ++)
	    {
	      value <<= 1; // shift left by one
	      readBit(infptr, & onebit, & whichbit, & curbyte);
	      value |= onebit;
	    }
	  // push a tree node into the list
	  TreeNode * tn = TreeNode_create(value, 0); 
	  ListNode * ln = ListNode_create(tn);
	  head = List_insert(head, ln, STACK);
	}
      else
	{
	  if (head == NULL)
	    {
	      printf("ERROR, head should not be NULL\n");
	    }
	  if ((head -> next) == NULL)
	    {
	      // the tree has been completely built
	      done = 1;
	    }
	  else
	    {
	      head = MergeListNode(head, DECODEMODE);
	    }
	}
    }
  // unnecessary to read the remaining unused bits
  TreeNode * root = head -> tnptr;
  // the linked list is no longer needed
  free (head);
  return root;
}
#endif


#ifdef TEST_DECODE

int decode(char * infile, char * outfile)
{
 FILE * infptr = fopen(infile, "r");
  if (infptr == NULL)
    {
      return 0;
    }
  TreeNode * root = readHeader(infptr);
  Tree_print(root, 0);
  // read the number of characters
  unsigned int numChar = 0;
  fread(& numChar, sizeof(unsigned int), 1, infptr);
  printf("numChar = %d\n", numChar);
  // read '\n'
  unsigned char newline;
  fread(& newline, sizeof(unsigned char), 1, infptr);
  if (newline != '\n')
    {
      printf("ERROR!\n");
    }
  unsigned char whichbit = 0;
  unsigned char onebit = 0;      
  unsigned char curbyte = 0;
  FILE * outfptr = fopen(outfile, "w");
  while (numChar != 0)
    {
      TreeNode * tn = root;
      while ((tn -> left) != NULL)
	{
	  // tn is not a leaf node
	  readBit(infptr, & onebit, & whichbit, & curbyte);	  
	  if (onebit == 0)
	    {
	      tn = tn -> left;
	    }
	  else
	    {
	      tn = tn -> right;
	    }	    
	}
      // tn is a leaf node
      printf("%c", tn -> value);
      fprintf(outfptr, "%c", tn -> value);
      numChar --;
    }
  Tree_destroy(root);
  fclose(infptr);
  fclose(outfptr);
  return 1;
}
#endif
