#include<stdio.h>
#include<stdlib.h>

/*Creating a struct for the adjaceny list*/

typedef struct adj{				
	int vertex;
	struct adj *next;
}adj ;

adj *list[100]={NULL} ;   //defining a adjacency list for all the vertices ; initially NULL ;

/*To add an edge from first to second (directed) - to maintain the adjacency list */
/*Adj List maintains a list of all children of a given vertex*/

void add(int first, int second)
{
	adj *tmp = (adj*)malloc(sizeof(adj));
	tmp->vertex = second ;
	tmp->next = list[first] ;
	list[first]=tmp;
	return ;
}

/*To print the adjacency list*/

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

void dfs(int lev,int ver)
{
	if(level[ver]!=-1)
		return;

	printf("lev : %d vertex : %d\n",lev,ver);

	level[ver]=lev;
	adj * current = list[ver];

	while(current!=NULL)
	{
		dfs(lev+1,current->vertex);
		current = current->next ;
	}

	return ;
}

int main()
{
	int n;
	scanf("%d",&n);
	
	int i;
	for(i=0;i<=n;i++)
		level[i]=-1;
		


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

	dfs(0,11);

	for(int i=0; i<=n-1 ; i++)
		printf("level :  %d \t vertex : %d\n",level[i],i);

	return 0;
}






