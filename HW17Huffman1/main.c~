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
	//Node * temp1 = NULL;
	//TreeNode * temp_right = NULL;
	//TreeNode * temp_left = NULL;
	_occurances_file(argv[1], "occurances.txt");
	_pq_file("occurances.txt", "pq.txt", &head);
	//post_order((head)->tree,argv[2]);
	//printf("head asci= %c, amount= %ld\n",head->tree->ascii,head->tree->amount);
	//temp1 = head->next;
	//while(temp1 != NULL)
	//{
	//  printf("head asci= %c, amount= %ld\n",temp1->tree->ascii,temp1->tree->amount);
	//  temp1 = temp1->next;
	//}
	//temp_right = temp1->right;
	//temp_left = temp1->left;
	//printf("right asci= %c, amount= %ld\n",temp_right->ascii,temp_right->amount);
	//printf("left asci= %c, amount= %ld\n",temp_left->ascii,temp_left->amount);
	output_1(&head);
	//output_file_1(&head, argv[2]);
	//output_file_2(&head, argv[3]);	
	//output_file_3(argv[3], argv[4]);	
	Node* temp = head;
	while(temp != NULL)
	{
		_destroy_tree_node(temp -> tree);
		temp = temp -> next;
	}
	_destroy_node(head);

	return EXIT_SUCCESS;
}
