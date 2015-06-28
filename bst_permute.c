//all possible binary search tree when the number of nodes is specified
#include<stdio.h>
#include<stdlib.h>
int val;
struct node{
int info;
struct node *llink,*rlink,*pptr;
};
typedef struct node * NODE;
NODE root=NULL;
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
//insertion of elements to binary search tree
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
//preorder tree traversal of the nodes
void preorder(NODE root)
{
if(root==NULL)
return;
printf("%d\t",root->info);
preorder(root->llink);
preorder(root->rlink);
}

//function to find all the permutation of the tree elements
void swap(int *x,int *y)
{
int temp;
temp=*x;
*x=*y;
*y=temp;
}
//function to display the tree nodes in preorder
void printarray(int *a,int n)
{
int i;
	for(i=0;i<=n;i++)
	 {
		//printf("%d\t",a[i]);
		root=insert(a[i],root);
	 }	
printf("\n");
preorder(root);
free(root);
}

void permute(int *a,int i,int n)
 {
int j; 
  if (i == n)
{

     printarray(a,n);
     
  }
  else
{
  for (j = i; j <= n; j++) { 
     swap(a+i,a+j);
     permute(a,i+1,n);
     swap(a+i,a+j);
  }
  
}}
int main()
{
int a[]={1,2,3};
int n=3;
permute(a,0,n-1);
}
