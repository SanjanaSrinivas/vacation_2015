/*program to find the frequently bought items using association anaysis concept*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
	int item,index;
	struct node *link;
};
typedef struct node *node;
node head=NULL;
node getnode()
{
	node root;
	root=(node)malloc(sizeof(struct node));
	root->index=0;
	root->item=0;
	root->link=NULL;
	return root;
}


node insert(int itop,int h,node root)
{
	node p,q,temp;
	if(root==NULL)
	{
		root=getnode();
		root->index=h;
		root->item|=(1<<(itop-1));
		root->link=NULL;
		return root;
	}
	p=root;
	q=root;
	while(p!=NULL)
	{
		if(p->index==h)
		{
			p->item|=(1<<(itop-1));
			return root;
		}
		p=p->link;
	}
	while(q->link!=NULL)
	{
		q=q->link;
	}
	temp=getnode();
	temp->item|=(1<<(itop-1));
	temp->index=h;
	q->link=temp;
	return root;

}


/*function to find the frequently bought items setting minimum support count to 3*/

int arr[100],size=0;
void support(node root)
{
	int minsup=3,j,i,sup;
	node p;
	for(i=(pow(2,6)-1);i>0;i--)
	{
		sup=0;
		p=root;
		while(p!=NULL)
		{
			int a=p->item & i;
			if(a==i)
			{
				sup++;
				if(sup>=minsup)
				{
					if(size==0)
					{
						arr[size]=i;
						size++;
						break;
					}
					for(j=0;j<size;j++)
					{
						int b=arr[j]|i;
						if(b==arr[j])
							break;
					}
					if(j==size)
					{
						arr[size]=i;
						size++;

					}
				}
			}

			p=p->link;
		}
	}
}


void main()
{
	int t,op,a,i,j,ch;
	char items[6][8]={"bread\0","milk\0","diaper\0","beer\0","eggs\0","cola\0"};

	printf("enter the number of transactions\n");
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		printf("enter the items of transcation %d\n",i);
		do
		{
			printf("enter the item you want to purchase\n1.bread\n2.milk\n3.diaper\n4.beer\n5.eggs\n6.cola\n");
			scanf("%d",&op);
			head=insert(op,i,head);
			printf("if you want to purchase more press 1\n");
			scanf("%d",&ch);
		}
		while(ch==1);
	}
	support(head);
	//displays the frequently bought items
	for(i=0;i<size;i++)
	{
		for(j=0;j<6;j++)
		{
			a=arr[i];
			if((a>>j)&0x1)
				printf("%s,\t",items[j]);
		}
		printf("\n");
	}
}
