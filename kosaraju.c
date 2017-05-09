#include<stdio.h>
#include<stdlib.h>

typedef struct adj{				
	int vertex;
	struct adj *next;
}adj ;

adj *Graph[100]={NULL} ;	//defining a adjacency list for all the vertices ; initially NULL ;
adj *Transpose[100]={NULL};

void add_in_list(adj* list[],int first, int second)
{

	adj *tmp = (adj*)malloc(sizeof(adj));
	tmp->vertex = second ;
	tmp->next = list[first] ;
	list[first] = tmp ;
	return ;
}

void printlist(adj* list[],int n)
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

	adj * current = Graph[ver];

	while(current!=NULL)
	{
		dfs(current->vertex);
		current = current->next ;
	}

	out[++time]=ver;
	printf("time : %d vertex_leaving : %d\n",time,ver);
	return ;
}

int stack[100];
int top = 0;

void stackprint()
{
	if(top==0)
		return;
	int i;
	for(i=0;i<top;i++)
		printf("%d ",stack[i]);
	printf("\n");
	return ;
}

void dfs2(int ver)
{
//	printf("ver : %d\n",ver);
//	stackprint() ;

	if(check[ver]!=0)
		return;
	check[ver] = 1;
	stack[top++] = ver;

	adj * current = Transpose[ver];

	while(current!=NULL)
	{
		dfs2(current->vertex);
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
		add_in_list(Graph,a,b);
		add_in_list(Transpose,b,a);
	}

	printlist(Graph,n);
	printlist(Transpose,n);

	time = 0 ;

	for(i=1;i<=n;i++)
	{
		if(check[i]==0)
			dfs(i);
	}

	for(i=1; i<=n ; i++)
		printf("out Time :  %d \t vertex : %d\n",i,out[i]);

	for(i=0;i<=n;i++)
		check[i]=0;

	for(i=n;i>=1;i--)
	{
		dfs2(out[i]);
		stackprint();
		top = 0;
	}


	return 0;
}

