//program to randomly generate the tree elements given it's number of nodes
#include<stdio.h>
#include<stdlib.h>
int val;
struct node{
int info;
struct node *llink,*rlink,*pptr;
};
typedef struct node * NODE;
NODE getnode()
{
	NODE x;
	
	x=(NODE)malloc(sizeof(struct node));

	if(x==NULL)
	{
		printf("out 0f memory\n");
		exit(0);
	}
	
	return x;
}

//program to randomly insert elements to the binary search tree
NODE insert(int item,NODE root)
{
	NODE temp,cur,prev;

	temp=getnode();

	temp->info=item;
	temp->llink=NULL;
	temp->rlink=NULL;
	temp->pptr=NULL;

	if(root==NULL)
		return temp;

	prev=NULL;
	cur=root;		

	while(cur!=NULL)
	{
		prev=cur;
		//No duplicate elements allowed
		if(item==cur->info)
		{
			val++;				
			return root;
					
		}

		if(item < cur->info)
			cur=cur->llink;

		else
			cur=cur->rlink;

	}

	if(item < prev->info)
		prev->llink=temp;
		
	
	else
		prev->rlink=temp;
		
		temp->pptr=prev;	
	return root;
}

//preorder tree traversal		
void preorder(NODE root)
{
if(root==NULL)
return;
printf("%d\t",root->info);
preorder(root->llink);
preorder(root->rlink);
}

//inorder tree traversal
void inorder(NODE root)
{
if(root==NULL)
return;
inorder(root->llink);
printf("%d\t",root->info);
inorder(root->rlink);
}

//postorder tree traversal
void postorder(NODE root)
{
if(root==NULL)
return;
postorder(root->llink);
postorder(root->rlink);
printf("%d\t",root->info);
}

int main()
{
NODE root,temp;
int i,item,n;
root=NULL;
printf("enter the number of nodes");
scanf("%d",&n);
for(i=0;i<n;i++)
{
item=random()%10;
printf("%d\t",item);
root=insert(item,root);
}
printf("\n");

printf("preorder\t");
preorder(root);
printf("\n");
printf("inorder\t");
inorder(root);
printf("\n");
printf("postorder\t");
postorder(root);
}



