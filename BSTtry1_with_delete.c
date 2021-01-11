#include<stdio.h>
#include<stdlib.h>

#define FALSE  0
#define TRUE   1


struct node {
	struct node *left;
	int data;
	struct node *right;
};

void insert(struct node **, int);
void preOrderDisplay(struct node *);
void inOrderDisplay(struct node *);
void postOrderDisplay(struct node *);
void delete ( struct node **, int ) ;
void search ( struct node **, int, struct node **,
				struct node **, int * ) ;

int main(){
	struct node *root=NULL;
	int choice, ele;
	while(1){
	printf("enter the choice \n");
	printf("insert-1   preOrder-2    ");
	printf("inOrder-3   postOrder-4     ");
	printf("delete-5 exit-6\n");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			printf("enter a ele\n");
			scanf("%d", &ele);
			insert(&root, ele);
			break;
		case 2:
			printf("*** Pre Order Display ***\n");
			preOrderDisplay(root);
			printf("\n");
			break;
		case 3:
			printf("*** In Order Display ***\n");
			inOrderDisplay(root);
			printf("\n");
			break;
		case 4:
			printf("*** Post Order Display ***\n");
			postOrderDisplay(root);
			printf("\n");
			break;
		
		case 5:
			printf("enter a ele to delete\n");
			scanf("%d", &ele);
			delete(&root, ele);
			break;
		case 6:	
			exit(0);
		default:
			printf("enter a right choice");
			break;
	}
	}	
}

void insert(struct node **p, int ele){
	if(*p==NULL){
		*p=(struct node *)malloc(sizeof(struct node));
		(*p)->left=NULL;
		(*p)->right=NULL;
		(*p)->data=ele;
	} else {
		if( ele < (*p)->data){
			insert( &((*p)->left), ele);
		}else{
			insert( &((*p)->right), ele);
		}

	}
}

void preOrderDisplay(struct node *p){
	if(p!=NULL)
	{
		printf("%d \t", p->data);
		preOrderDisplay(p->left);
		preOrderDisplay(p->right);
	} 
}	
void inOrderDisplay(struct node *p){
	if(p!=NULL)
	{
		inOrderDisplay(p->left);
		printf("%d \t", p->data);
		inOrderDisplay(p->right);
	} 
}	
void postOrderDisplay(struct node *p){

	if(p!=NULL)
	{
		postOrderDisplay(p->left);
		postOrderDisplay(p->right);
		printf("%d \t", p->data);
	} 
}	


/* deletes a node from the binary search tree */
void delete ( struct node **p, int num )
{
	int found ;
	struct node *parent, *x, *xsucc ;

	/* if tree is empty */
	if ( *p == NULL )
	{
		printf ( "\nTree is empty" ) ;
		return ;
	}

	parent = x = NULL ;

	/* call to search function to find the node to be deleted */
	search ( p, num, &parent, &x, &found ) ;

	/* if the node to deleted is not found */
	if ( found == FALSE )
	{
		printf ( "\nData to be deleted, not found" ) ;
		return ;
	}

	/* if the node to be deleted has two children */
	if ( x -> left != NULL && x -> right != NULL )
	{
		parent = x ;
		xsucc = x -> right ;

		while ( xsucc -> left != NULL )
		{
			parent = xsucc ;
			xsucc = xsucc -> left ;
		}

		x -> data = xsucc -> data ;
		x = xsucc ;
	}

	/* if the node to be deleted has no child */
	if ( x -> left == NULL && x -> right == NULL )
	{
		if ( parent -> right == x )
			parent -> right = NULL ;
		else
			parent -> left = NULL ;

		free ( x ) ;
		return ;
	}

	/* if the node to be deleted has only rightchild */
	if ( x -> left == NULL && x -> right != NULL )
	{
		if ( parent -> left == x )
			parent -> left = x -> right ;
		else
			parent -> right = x -> right ;

		free ( x ) ;
		return ;
	}

	/* if the node to be deleted has only left child */
	if ( x -> left != NULL && x -> right == NULL )
	{
		if ( parent -> left == x )
			parent -> left = x -> left ;
		else
			parent -> right = x -> left ;

		free ( x ) ;
		return ;
	}
}

/*returns the address of the node to be deleted, address of its parent and
   whether the node is found or not */
void search ( struct node **p, int num, struct node **par, struct
		node **x, int *found )
{
	struct node *q ;

	q = *p ;
	*found = FALSE ;
	*par = NULL ;

	while ( q != NULL )
	{
		/* if the node to be deleted is found */
		if ( q -> data == num )
		{
			*found = TRUE ;
			*x = q ;
			return ;
		}

		*par = q ;

		if ( q -> data > num )
			q = q -> left ;
		else
			q = q -> right ;
	}
}

