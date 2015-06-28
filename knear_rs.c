//program to find k-nearest neighbour for movie recommendation system
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
int head;//user
int array[10];
int count;
struct node *next;
};
typedef struct node *node;
node root;
//root=(node)malloc(sizeof(struct node));
float cosine[10],cosfu,min,d1;
int i,j,k,eq1,eq2,sum,r[943][1682],p,v;
node getnode(int u)
{
	node n;
	n=(node)malloc(sizeof(struct node));
	n->head=u;
	n->next=NULL;
	n->count=0;
	return n;
}
node insert(node n,node root)
{
	node p;
	if(root==NULL)
		return n;
	p=root;
	while(p->next!=NULL)
		p=p->next;
	p->next=n;
	return root;
}			
node knn(node root)
{
node temp;
for(i=0;i<943;i++)//for user
{
	temp=getnode(i);
	for(j=0;j<943;j++)//with other users
	{
		if(i==j)
		continue;
		eq1=eq2=sum=0;
		for(k=0;k<1682;k++)//for movies
		{
			if(r[i][k]!=0)//if user rated
				eq1+=pow(r[i][k],2);
			if(r[j][k]!=0)//if compared user rated
				eq2+=pow(r[j][k],2);
			if((r[i][k]!=0)&&(r[j][k]!=0))//intersection(both rated)
				sum+=r[i][k]*r[j][k];
		}
	d1=(sqrt(eq1)*sqrt(eq2));
	cosfu=sum/d1;
	if(temp->count<10)
	{
		temp->array[temp->count]=j;
		cosine[temp->count]=cosfu;
		temp->count++;
		continue;					
	}
	min=1;
	for(p=0;p<10;p++)//to get least value in the array
	{
		if(cosine[p]<min)
		{
			min=cosine[p];
			v=p;
		}
	}
	if(cosine[v]<cosfu)
	{
		temp->array[v]=j;
		cosine[v]=cosfu;
	}
	}
	root=insert(temp,root);
	}
	return root;
}
void display()
{
	node d;
	d=root;
	while(d!=NULL)
	{	
		printf("k(10) nearest neighbours of %d is : ",d->head);
		for(i=0;i<10;i++)
		{	
			printf("%d\t",d->array[i]);
		}
		printf("\n");	
		d=d->next;
	}
}
			
void main()
{
int movie,rating,ex,usr,user,cnt,ind;

 	for(i=0;i<100000;i++)
 	{
 		scanf("%d%d%d%d",&usr,&movie,&rating,&ex);
 		r[usr-1][movie-1]=rating;
 	}
 root=knn(root);
 //display();
 node ptr;
 ptr=root;

 
 user=2;
 printf("the recommended items for %d are:\n",user);
 
 while(1)
 {
 	if(ptr->head==user)
 		break;
 	ptr=ptr->next;
 }
 for(j=0;j<1682;j++)
 {
 	cnt=0;
 	for(k=0;k<10;k++)
 	{
 		ind=ptr->array[k];
 		if((r[ind][j]!=0)&&(r[user][j]==0))
		{
		cnt++;
		}	 		
 	}
 	if(cnt>6)
 		printf("%d\t",j);
 	}	
} 	
