#include <stdio.h>
#include <stdlib.h>


struct node
{
	int data;
	struct node *left;
	struct node *right;

}*root=NULL;

struct node* insert(struct node* root,int data)
{
	struct node* newNode = (struct node *) malloc(sizeof(struct node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	if(root == NULL)
		root = newNode;
	else if(data > root->data)
		root->right = insert(root->right,data);
	else if(data < root->data)
		root->left = insert(root->left,data);

	return root;
	

}

struct node*  findNode(struct node* root, int data)
{
	
	 if(data == root->data)
		return root;
	else if(data > root->data)
		return findNode(root->right,data);
	else if(data < root->data)
		return findNode(root->left,data);
}

int  findMin(struct node* root)
{
	if(root->left == NULL)
		{printf(" min is %d\n",root->data );
		return  root->data;}
	else
		return findMin(root->left);
}

int  findMax(struct node* root)
{
	if(root->right == NULL)
		{
		return  root->data;}
	else
		return findMax(root->right);
}

int  GetSuccessor(int data)
{

//	printf("entered sus\n");
	struct node* current = findNode(root,data);
	//printf("\n %d find node -> ",current->data);
	//printf("entered sus2\n");
	if(current == NULL)
		return -999;   // no successsor

	if(current->right != NULL)
		return findMin(current->right);
	else 
	{
		struct node* ancestor = root;
		struct node* successsor = NULL;

		while(current != ancestor)
		{
			if(current->data < ancestor->data)
			{
				successsor = ancestor;
				ancestor = ancestor->left;
			}
			else
			{
				ancestor = ancestor->right;
			}

		}
		printf(" suss final %d\n",successsor->data );
		return successsor->data;
	}

}

int GetPredecessor(int data)
{
	struct node* current = findNode(root,data);
	//printf("\n %d find node -> ",current->data);
	//printf("entered sus2\n");
	if(current == NULL)
		return -999;   // no successsor

	if(current->left != NULL)
		return findMax(current->left);
	else 
	{
		struct node* ancestor = root;
		struct node* successsor = NULL;

		while(current != ancestor)
		{
			if(current->data > ancestor->data)
			{
				successsor = ancestor;
				ancestor = ancestor->right;
			}
			else
			{
				ancestor = ancestor->left;
			}

		}
		printf(" suss final %d\n",successsor->data );
		return successsor->data;
	}
}


void inorder(struct node* root)
{
	if(root == NULL)
		return ;

	
	inorder(root->left);
	printf(" --> %d\n",root->data );
	inorder(root->right);

}

struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL) return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = findNode(root,findMin(root->right));
 
        // Copy the inorder successor's content to this node
        root->data = temp->data;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


int findHeight(struct node* root)
{
	if(root == NULL)
		return -1;
	else
	{
		int left = findHeight(root->left);
		int right = findHeight(root->right);
		int height  = (left>=right)?left:right;
		return height+1;
	}

}

void main()
{
	char ch = 'i';
	int data;

	printf("\nMenu \n \n press \n i to insert \n d to display \n r to remove \n p to get Predecessor \n s to get successor \n q to quit\n\n");


	while(ch != 'q'){
		printf("\nCommand : "); scanf(" %c",&ch);
		
		switch(ch)
		{
			case 'i' :
				printf("\nEnter the element to be inserted  :"); 
				scanf(" %d",&data);
				root = insert(root,data);
				break;

			case 'd' :
				printf("\n\n\n");
				inorder(root);
				break;

			case 's':
				printf("\nSuccessor of what ??? : ");
				scanf(" %d",&data);
				int d = GetSuccessor(data);	
				printf("\n The successsor is %d" , d);
				break;
			case 'p':
				printf("\n Predecessor of what ??? : ");
				scanf(" %d",&data);
				 d = GetPredecessor(data);	
				printf("\n The Predecessor is %d" , d);
				break;	
			case 'r':
				printf("\n what do you want to delete: ");
				scanf(" %d",&data);
				 deleteNode(root,data);	
				
				break;	

			case 'h':
				printf("\n Height of which element  ");
				scanf(" %d",&data);
				 int h = findHeight(findNode(root,data));	
				 printf("\n The height of this node is %d ",h);
				
				break;		

			case 'q':
				exit(0);
				break;	

			default :
				printf("\n invalid entry\n");

		}
	}





}
