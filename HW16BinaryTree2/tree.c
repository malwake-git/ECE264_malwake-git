// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tree.h"

// DO NOT MODIFY FROM HERE --->>>
Tree * newTree(void)
{
  Tree * t = malloc(sizeof(Tree));
  t -> root = NULL;
  return t;
}

void deleteTreeNode(TreeNode * tr)
{
  if (tr == NULL)
    {
      return;
    }
  deleteTreeNode (tr -> left);
  deleteTreeNode (tr -> right);
  free (tr);
}

void freeTree(Tree * tr)
{
  if (tr == NULL)
    {
      // nothing to delete
      return;
    }
  deleteTreeNode (tr -> root);
  free (tr);
}


// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***
#ifdef TEST_BUILDTREE
TreeNode* newNode(int data) 
{ 
    TreeNode * node = malloc(sizeof(TreeNode)); 
    node->value = data; 
    node->left = node->right = NULL; 
    return (node); 
}

int search(int * arr, int strt, int end, int value) 
{ 
    int i; 
    for (i = strt; i <= end; i++) { 
        if (arr[i] == value) 
            break; 
    } 
    return i; 
}

TreeNode* buildUtil(int * in, int * post, int inStrt, int inEnd, int * pIndex) 
{ 
    // Base case 
    if (inStrt > inEnd) 
        return NULL; 
  
    /* Pick current node from Postorder traversal using 
       postIndex and decrement postIndex */
    TreeNode* node = NULL;
    node = newNode(post[*pIndex]);
    
    (*pIndex)--; 
  
    /* If this node has no children then return */
    if (inStrt == inEnd) 
        return node; 
  
    /* Else find the index of this node in Inorder 
       traversal */
    int iIndex = search(in, inStrt, inEnd, node->value); 
  
    /* Using index in Inorder traversal, construct left and 
       right subtress */
    node->right = buildUtil(in, post, iIndex + 1, inEnd, pIndex); 
    node->left = buildUtil(in, post, inStrt, iIndex - 1, pIndex);
    return node; 
}
Tree * buildTree(int * inArray, int * postArray, int size)
{
  Tree * tree = malloc(sizeof(Tree));
  int pIndex = size - 1;
  tree->root = buildUtil(inArray, postArray, 0, size - 1, &pIndex);
  return tree; 
}
#endif

#ifdef TEST_PRINTPATH
bool orderNode(TreeNode * tn, int val)
{
  if (tn == NULL)
    {
      return false;
    }

      if(tn->value == val)
	{
	  printf("%d\n",tn->value);
	  return true;
	}
      //}
    if(orderNode(tn->left,val) || orderNode(tn->right,val))
    {
      printf("%d\n",tn->value);
      return true;
    }
  
  return false;
}

void printPath(Tree * tr, int val)
{
  if(tr == NULL)
    {
      return;
    }

  orderNode(tr->root,val);

}
#endif
