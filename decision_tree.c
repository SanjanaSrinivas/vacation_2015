#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//structure for table
struct table{
	char gender[2];
	char cartype[10];
	char size[15];
	int class;
};
//input table
struct table data[20];
struct table new[20];
//int i,j,k;
struct node{
	struct node *link[4];
	char label[20];
	int count;
};
struct attribute{
	char *name;
	char *att[4];
	int count;
};
//struct attribute a[3];	
typedef struct node *node;
//function to create a new node 
node create_node(){
	node n;
	int i;
	n=(node)malloc(sizeof(struct node));
	//n->count=0;
	for(i=0;i<4;i++)
	{
		n->link[i]=NULL;
	}
	return n;
}
int flag;
//function to retrieve the attribute values from the input table
void outcome(char *str,struct attribute a[],int size)
{	
	int j,k;
	//attribute-male,female
	if(strcmp(str,a[0].name)==0)
	{	
		a[0].count=0;
		for(j=0;j<size;j++)
		{	
			flag=0;
			if(a[0].count==0)
			{
				a[0].att[0]=data[j].gender;
				a[0].count++;
			}
			else
			{
				for(k=0;k<a[0].count;k++)
				{	
					
					if(strcmp(a[0].att[k],data[j].gender)==0)
						{
							flag=1;
							break;
						}	
				}
				if(flag!=1)
				{
					a[0].att[a[0].count]=data[j].gender;
					a[0].count++;
				}
			}
		}
	}
	//attribute-sports,family,luxury
	if(strcmp(str,a[1].name)==0)
	{	
		a[1].count=0;
		for(j=0;j<size;j++)
		{	
			flag=0;
			if(a[1].count==0)
			{
				a[1].att[0]=data[j].cartype;
				a[1].count++;
			}
			else
			{
				for(k=0;k<a[1].count;k++)
				{	
					
					if(strcmp(a[1].att[k],data[j].cartype)==0)
						{
							flag=1;
							break;
						}	
				}
				if(flag!=1)
				{
					a[1].att[a[1].count]=data[j].cartype;
					a[1].count++;
				}
			}
		}
	}
	//attribute-small,medium,large,extralarge
	if(strcmp(str,a[2].name)==0)
	{	
		a[2].count=0;
		for(j=0;j<size;j++)
		{	
			flag=0;
			if(a[2].count==0)
			{
				a[2].att[0]=data[j].size;
				a[2].count++;
			}
			else
			{
				for(k=0;k<a[2].count;k++)
				{
					
					if(strcmp(a[2].att[k],data[j].size)==0)
						{
							flag=1;
							break;
						}	
				}
				if(flag!=1)
				{
					a[2].att[a[2].count]=data[j].size;
					a[2].count++;
				}
			}
		}
	}							
}
//condition to check wether it's leaf with class label
int stopping_condition(struct table arr[],int size){
int c,i;
c=arr[0].class;
	for(i=1;i<size;i++)
	{
		if(arr[i].class!=c)
			return 0;
	}				
	return 1;
}
//function to calculate the gini-index value which gives the attribute condition to be checked at every internal node
float gindex[3],g1,g2,g3,g4;
int gini_index(struct table arr[],int size,struct attribute a[])
{	
	int i,j;
	float c1,c2,c3,c4,c5,c6,c7,c8,min;
	g1=g2=0;
	int v;
	//for attribute gender
	c1=c2=c3=c4=0;
	for(i=0;i<a[0].count;i++)
	{
		
		for(j=0;j<size;j++)
		{
			if((strcmp(a[0].att[i],"M")==0) && (strcmp(arr[j].gender,"M")==0))
			{
				if(arr[j].class==0)
					c1++;
				else
					c2++;
			}
			if((strcmp(a[0].att[i],"F")==0) && (strcmp(arr[j].gender,"F")==0))
			{
				if(arr[j].class==0)
					c3++;
				else
					c4++;
			}
		}
	}
	if(a[0].count!=0)
	{
		if(c1!=0 && c2!=0 )
			g1=1-pow((c1/(c1+c2)),2)-pow((c2/(c1+c2)),2);
		if(c3!=0 && c4!=0)	
			g2=1-pow((c3/(c3+c4)),2)-pow((c4/(c3+c4)),2);
		gindex[0]=g1*((c1+c2)/size)+g2*((c3+c4)/size);
	}
	//for attribute cartype
	g1=g2=g3=0;
	c1=c2=c3=c4=c5=c6=0;
	for(i=0;i<a[1].count;i++)
	{
		
		for(j=0;j<size;j++)
		{
			if((strcmp(a[1].att[i],"Family")==0) && (strcmp(arr[j].cartype,"Family")==0))
			{
				if(arr[j].class==0)
					c1++;
				else
					c2++;
			}
			if((strcmp(a[1].att[i],"Sports")==0) && (strcmp(arr[j].cartype,"Sports")==0))
			{
				if(arr[j].class==0)
					c3++;
				else
					c4++;
			}
			if((strcmp(a[1].att[i],"Luxury")==0) && (strcmp(arr[j].cartype,"Luxury")==0))
			{
				if(arr[j].class==0)
					c5++;
				else
					c6++;
			}
			
		}
	}
	if(a[1].count!=0)
	{
		if(c1!=0 && c2!=0)
			g1=1-pow((c1/(c1+c2)),2)-pow((c2/(c1+c2)),2);
		if(c3!=0 && c4!=0)	
			g2=1-pow((c3/(c3+c4)),2)-pow((c4/(c3+c4)),2);
		if(c5!=0 && c6!=0)	
			g3=1-pow((c5/(c5+c6)),2)-pow((c6/(c5+c6)),2);
		gindex[1]=g1*((c1+c2)/size)+g2*((c3+c4)/size)+g3*((c5+c6)/size);
	}
	//for attribute shirtsize
	g1=g2=g3=g4=0;
	c1=c2=c3=c4=c5=c6=c7=c8=0;
	for(i=0;i<a[2].count;i++)
	{
		
		for(j=0;j<size;j++)
		{
			if((strcmp(a[2].att[i],"Small")==0) && (strcmp(arr[j].size,"Small")==0))
			{
				if(arr[j].class==0)
					c1++;
				else
					c2++;
			}
			if((strcmp(a[2].att[i],"Medium")==0) && (strcmp(arr[j].size,"Medium")==0))
			{
				if(arr[j].class==0)
					c3++;
				else
					c4++;
			}
			if((strcmp(a[2].att[i],"Large")==0) && (strcmp(arr[j].size,"Large")==0))
			{
				if(arr[j].class==0)
					c5++;
				else
					c6++;
			}
			if((strcmp(a[2].att[i],"xLarge")==0) && (strcmp(arr[j].size,"xLarge")==0))
			{
				if(arr[j].class==0)
					c7++;
				else
					c8++;
			}
		}
	}
	if(a[2].count!=0)
	{
		if(c1!=0 && c2!=0)
			g1=1-pow((c1/(c1+c2)),2)-pow((c2/(c1+c2)),2);
		if(c3!=0 && c4!=0)	
			g2=1-pow((c3/(c3+c4)),2)-pow((c4/(c3+c4)),2);
		if(c5!=0 && c6!=0)	
			g3=1-pow((c5/(c5+c6)),2)-pow((c6/(c5+c6)),2);
		if(c7!=0 && c8!=0)	
			g4=1-pow((c7/(c7+c8)),2)-pow((c8/(c7+c8)),2);
	
		gindex[2]=g1*((c1+c2)/size)+g2*((c3+c4)/size)+g3*((c5+c6)/size)+g4*((c7+c8)/size);
	}	
	//to calculate the minimum gini-index from the array
	min=gindex[0];
	for(i=1;i<3;i++)
	{
		if(gindex[i]<min)
		{
			min=gindex[i];
			v=i;
		}
	}
	gindex[0]=gindex[1]=gindex[2]=1;					
	return v;
}

//function for decision tree induction
node tree_growth(struct table arr[],int size,struct attribute a[])
{
int x,y,i,j,k,p,q,m,n;
node temp,c,root;
x=stopping_condition(arr,size);
if(x==1)
{	
	node temp;
	temp=create_node();
	if(arr[0].class==0)
	{
		temp->label="co\0";
	}
	else
		temp->label="c1\0";
		return temp;
}
else
{
	
	root=create_node();
	c=create_node();
	y=gini_index(arr,size,a);
	root->label=a[y].name;
	if(strcmp(root->label,"gender")==0)
	{
		for(i=0;i<a[0].count;i++)
		{
			k=0;
			for(j=0;j<size;j++)
			{
				if(strcmp(a[0].att[i],arr[j].gender)==0)
				{
					strcpy(new[k].gender,arr[j].gender);
					strcpy(new[k].cartype,arr[j].cartype);
					strcpy(new[k].size,arr[j].size);
					new[k].class=arr[j].class;
					k++;
				}
			}
			//a[y].count=0;
			c=tree_growth(new,k,a);
			root->link[root->count]=c;
			root->count++;
		  }
	}				
	
	if(strcmp(root->label,"cartype")==0)
	{
		for(p=0;p<a[1].count;p++)
		{
			k=0;
			for(q=0;q<size;q++)
			{
				if(strcmp(a[1].att[p],arr[q].cartype)==0)
				{
					strcpy(new[k].gender,arr[q].gender);
					strcpy(new[k].cartype,arr[q].cartype);
					strcpy(new[k].size,arr[q].size);
					new[k].class=arr[q].class;
					k++;
				}
			}
			//a[y].count=0;
			c=tree_growth(new,k,a);
			root->link[root->count]=c;
			root->count++;
		  }
	}				
	
	if(strcmp(root->label,"size")==0)
	{
		for(m=0;m<a[2].count;m++)
		{
			k=0;
			for(n=0;n<size;n++)
			{
				if(strcmp(a[2].att[m],arr[n].size)==0)
				{
					strcpy(new[k].gender,arr[n].gender);
					strcpy(new[k].cartype,arr[n].cartype);
					strcpy(new[k].size,arr[n].size);
					new[k].class=arr[n].class;
					k++;	
				}
			}
			//a[y].count=0;
			c=tree_growth(new,k,a);
			root->link[root->count]=c;
			root->count++;
		  }
	}
	//a[y].count=0;				
	}
	return root;		
}	


void main()
{
	int i,j;
	node r=NULL;
	struct attribute a[3];
	//char at[4][10];
	
	//to read the input data
	for(i=0;i<20;i++)
	{
		scanf("%s\t\t%s\t\t%s\t\t%d\n",data[i].gender,data[i].cartype,data[i].size,&data[i].class);
	}
	//for attribute list
	//scanf("%d",&n);
	/*for(i=0;i<3;i++)
	{
		scanf("%s\n",at[i]);
		
	}*/
	a[0].name="gender";
	a[1].name="cartype";
	a[2].name="size";
	/*a[0].count=0;
	a[1].count=0;
	a[2].count=0;*/
	outcome("gender",a,20);
	outcome("cartype",a,20);
	outcome("size",a,20);
	printf("the input table is:\n");
	for(i=0;i<20;i++)
	{
		printf("%s\t\t %s\t\t %s\t\t %d\n",data[i].gender,data[i].cartype,data[i].size,data[i].class);
	}
	//attribute list
	for(i=0;i<3;i++)
	{
		for(j=0;j<a[i].count;j++)
		{
		
			printf("%s\t",a[i].att[j]);
		}
		printf("\n");	
	}
	r=tree_growth(data,20,a);
	printf("\n%s",r->label);
	printf("\n%s",(r->link[0])->label);
	printf("\n%s",r->link[0]->link[0]->label);
	printf("\n%s",r->link[0]->link[1]->label);
	printf("\n%s",r->link[0]->link[2]->label);
	printf("\n%s",r->link[0]->link[3]->label);
	printf("\n%s",(r->link[1])->label);
	printf("\n%s",(r->link[2])->label);
	printf("\n%s",r->link[2]->link[0]->label);
	printf("\n%s",r->link[2]->link[1]->label);
	printf("\n%s",r->link[2]->link[2]->label);
	printf("\n%s",r->link[2]->link[3]->label);
	
}	
		
			 
