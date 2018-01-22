//recommendation system-collaborative filtering
#include<stdio.h>
#include<stdlib.h>
int r[5][5],u,ind,flag;
float ja[5];
int search()
{
 int i,j,v,diff,max;
 //float max;
 flag=0;
 max=0;
 for(i=0;i<5;i++)
 {
 	if(ja[i]>max)
 	{
 		max=ja[i];
 		v=i;
 	}	
 }
 for(j=0;j<5;j++)
 {
  if((r[u][j]!=0)&&(r[v][j]!=0))
  {
  	diff=r[u][j]-r[v][j];
  }
  if((diff>1)||(diff<-1))
  {
  	flag++;
  }		
 }
 return v;
}
void jacquad(int u)
{
 int i,j,k;
 float js,intr,uni,un,in;
 for(i=0;i<5;i++)//for users
 {
 	in=un=0;
 	ja[u]=0;
 	if(i==u)
 	{
 	//ja[u]=0;
 	continue;
 	}
 	for(j=0;j<5;j++)//for films
 	{
 		if((r[u][j]!=0)&&(r[i][j]!=0))
 			intr=++in;
 		if((r[u][j]!=0)||(r[i][j]!=0))
 			uni=++un;
 	}
 	js=intr/uni;
 	//printf("%f\n",js);
 	ja[i]=js;
 	//ja[u]=0;
 	
 }	
 printf("jacquadian similarities with respect to user %d\n",u);	
 for(k=0;k<5;k++)
 {
 	printf("%f\t",ja[k]);
 }
 //v=search();
 //printf("\n%d\n",v);
}
void main()
{
 int i,j;
 for(i=0;i<5;i++)
 {
 	for(j=0;j<5;j++)
 	{
 		scanf("%d",&r[i][j]);
 		printf("%d\t",r[i][j]);
 	}
 	printf("\n");
 }
 //printf("enter the user number[0-4] for whom you want to recommend\n");
 scanf("%d",&u);
 jacquad(u);
 ind=search();
 while(flag>1)
 {
 	ja[ind]=0;
 	ind=search();
 }	
 printf("\n similar user %d\n",ind);
 for(j=0;j<5;j++)
 {
 	if((r[ind][j]!=0)&&(r[u][j]==0))
 	{
 		printf("we recommend user %d to watch movie %d with rating %d\n",u,j,r[ind][j]);
 	
 	}
 }		
 }
 
 

