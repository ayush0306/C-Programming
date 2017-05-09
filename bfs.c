#include<stdio.h>
#include<stdlib.h>

typedef struct adj{
	int vertex ;
	struct adj *next;
}adj; 

adj * list[100] = {NULL} ;

void add(int first, int second)
{
	if(list[first]==NULL)
	{
		list[first] = (adj *)malloc(sizeof(adj)) ;
		list[first]->vertex = second ;
		list[first]->next = NULL ;
		return ;
	}

	adj *current = list[first] ;

	while(current->next!=NULL)
		current = current->next ;

	adj *tmp = (adj*)malloc(sizeof(adj));
	tmp->vertex = second ;
	tmp->next = NULL ;
	current->next = tmp ;
	return ;
}

void printlist(int n)
{
	for(int i=1;i<=n;i++)
	{
		printf("adj[%d]",i);
		
		adj * current = list[i] ;
		while(current!=NULL)
		{
			printf("-->%d[]",current->vertex);
			current=current->next;
		}

		printf("-->NULL\n");
	}

}

int level[100]={-1};
int vertex[100]={0};
int flag[100]={0};

/*void bfs(int n,int lev)
{
	printf("n:%d \t level :%d \n",n,lev);
	if(flag[n]==1)
	{
		printf("%d already reached at level %d\n",n,level[n]);
		return;
	}
	
	flag[n]=1;
	level[n]=lev;

	adj * current = list[n];

	while(current!=NULL)
	{
		bfs(current->vertex,lev+1);
		current = current->next;
	}

	return ;
}*/

/*void bfs(int n, int lev)
{
	if(flag[n]==1)
		return;

	flag[n]=1;
	
	adj * current = list[n] ;

	while(current!=NULL)
	{
		level[current->vertex] = lev+1 ;
		current=current->next;
	}

	current = list[n] ;

	while(current!=NULL)
	{
		bfs(current->vertex,lev+1);
		current = current->next ;
	}
	return;
}*/

int n,count=0,pos=0 ;

void bfs(int lev)
{
	if(lev>10)
		return;

	printf("level : %d\n",lev);
	while(level[count]==lev)
	{
		//mark children at lev+1
		adj * current = list[vertex[count]] ;
		while(current!=NULL)
		{
			if(flag[current->vertex] == 0)
			{
				flag[current->vertex]=1 ;
				pos++ ;
				level[pos]=lev+1 ;
				vertex[pos] = current->vertex ;
				printf("%d\n",current->vertex);
			}
			current = current->next ;
		}
		count++ ;
	}

	printf("pos : %d\n",pos);
	printf("count : %d\n",count);

	for(int i=0; i<n ; i++)
	{
		printf("%d ",level[i]);
	}
	printf("\n");

	for(int i=0; i<n ;i++)
		printf("%d ",vertex[i]);
	printf("\n");

	if(pos==n-1)
		return ;

	return bfs(lev+1);
}

int main()
{
//	int n ;
//	int edges ;
	
	scanf("%d",&n) ;

	while(1)
	{
		int a,b ;
		scanf("%d %d",&a,&b);
		if(a==-1)
			break;
		add(a,b);
		add(b,a);
	}

	printlist(n);

	
	/*for(int i=1; i<=n ; i++)
		printf("%d is at level : %d\n",i,level[i]);

	for(int i=1; i<=n ; i++)
		printf("%d is at flag : %d\n",i,flag[i]);
*/
	flag[11]=1;
	level[0]=0;
	vertex[0]=11;

	bfs(0);

	for(int i=0; i<=n-1 ; i++)
		printf("level :  %d \t vertex : %d\n",level[i],vertex[i]);

	return 0;
}
