#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huffman.h"


int main(int argc, char* argv[]) 
{
	if(argc != 3)
	{
		return EXIT_FAILURE;
	}
	Node* head = NULL;

	readInput(&head);
	output_file_1(&head,)
	
	Node* temp = head;
	while(temp != NULL)
	{
		_destroy_tree_node(temp -> tree);
		temp = temp -> next;
	}
	_destroy_node(head);

	return EXIT_SUCCESS;
}
