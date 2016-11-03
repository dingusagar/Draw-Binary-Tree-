#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


struct node{
	int data;
	struct node* left;
	struct node* right;
	
	}*root=NULL;


/*
	This functions here assume that each node in your tree is in this format 
	
	struct node
	{
		int data;
		struct node* left;
		struct node* right;
	};
	
*/

/*
	Trees with levels 7 may go out of the screen.
*/



int height(struct node *tree);
void write(int pp ,int offset, struct node* root ,char* side ,int level);
void displayTree(struct node *root);


int **A;  // our 2d array


void displayTree(struct node *root)
{
	int i,j;

	int h=height(root);
	int nn =pow(2,h+1)-1;
		
	//printf("height = %d\n  max nodes = %d\n\n\n",h,nn);	
	A=NULL;
	 

	A = (int **)malloc((h+1+1)*sizeof(int *));   // we need h+1 rows indexed at 1:h+1
	for(int i=1;i<=h+1;i++)
		A[i] = (int *)malloc((nn+1)*sizeof(int));   // we need nn columns indexed at 1:nn

	for(i = 1;i<=h+1;i++)
	for(j = 1;j<=nn;j++)
		A[i][j] = 0;

	write(nn+1,(nn+1)/2,root,"left",1);   // Writes the entire tree in a 2d matrix A
	
	// Displaying the 2d matrix
	for(i = 1;i<=h+1;i++){
	for(j = 1;j<=nn;j++)
		{
			if(A[i][j]!=0)
			printf("%d",A[i][j]);
			else
				printf(" ");
		}
		printf("\n\n\n");
	}

	for(int i = 0; i <= h+1; i++)
    	free(A[i]);
	free(A);


}



void write(int pp ,int offset, struct node *root ,char *side ,int level)
{
	
		if(root==NULL)
			return;
		
		if(strcmp(side,"left")==0)
				{
					A[level][pp-offset] = root->data;

					write(pp-offset,offset/2,root->left,"left",level+1);
					write(pp-offset,offset/2,root->right,"right",level+1);
				}
		else{
				A[level][pp+offset] = root->data;
				write(pp+offset,offset/2,root->left,"left",level+1);
				write(pp+offset,offset/2,root->right,"right",level+1);
			}
		
}


int height(struct node *tree)
{
	
	if(tree)
	{
		int lheight=height(tree->left);
		int rheight=height(tree->right);
		if(lheight>rheight)
			return lheight+1;
		else
			return rheight+1;
	}


	return -1;


}