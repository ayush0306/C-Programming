#include<stdio.h>
#include<stdlib.h>

typedef struct adj{				
	int vertex;
	struct adj *next;
}adj ;

adj *list[100]={NULL} ;   //defining a adjacency list for all the vertices ; initially NULL ;


void add(int first, int second)
{

	adj *tmp = (adj*)malloc(sizeof(adj));
	tmp->vertex = second ;
	tmp->next = list[first] ;
	list[first] = tmp ;
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

int out[100]={-1};
int check[100]={0};
int time = 0 ;

void dfs(int ver)
{
	if(check[ver]!=0)
		return;
	check[ver]=1;

//	printf("lev : %d vertex : %d\n",lev,ver);
	
	adj * current = list[ver];

	while(current!=NULL)
	{
		dfs(current->vertex);
		current = current->next ;
	}

	out[++time]=ver;
	printf("time : %d vertex_leaving : %d\n",time,ver);
	return ;
}

int main()
{
	int n;
	scanf("%d",&n);
	
	int i;
	for(i=0;i<=n;i++)
	{
		out[i]=-1;
		check[i]=0;
	}

	while(1)
	{
		int a,b ;
		scanf("%d %d",&a,&b);
		if(a==-1)
			break;
		add(a,b);
	}

	printlist(n);
	
	time = 0 ;

	for(i=1;i<=n;i++)
	{
		if(check[i]==0)
			dfs(i);
	}

	for(int i=1; i<=n ; i++)
		printf("out Time :  %d \t vertex : %d\n",i,out[i]);

	return 0;
}

