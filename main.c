#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"avl.h"

#define COUNT 10
void print2D(t_node *root, int space){
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2D(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    // Process left child
    print2D(root->left, space);
}

int main(){

	t_node *root=NULL;
	char *buffer = malloc(50 * sizeof(char));

	for(;fgets(buffer,50,stdin);){

		char *code=strtok(buffer," ");	
		int key = atoi( strtok(NULL, " "));

		if(!strcmp("i",code))
			root=insertNode(root,key);
		else if (!strcmp("r",code))
			root=deleteNode(root,key);
		else{
			perror("Invalid operation code\n");
			exit(INVALID_OPCODE);
		}

	}

	inOrder(root, 0);
	printf("\n");
	print2D(root, 0);

	return 0;
}
