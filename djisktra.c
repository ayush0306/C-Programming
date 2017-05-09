#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct adj{				
	int vertex;
	int weight;
	struct adj *next;
}adj ;

adj *list[100]={NULL} ; 

void add(int first, int second,int weight)
{
	if(list[first]==NULL)
	{
		list[first] = (adj *)malloc(sizeof(adj)) ;
		list[first]->vertex = second ;
		list[first]->next = NULL ;
		list[first]->weight = weight ;
		return ;
	}

	adj *tmp = (adj*)malloc(sizeof(adj));
	tmp->vertex = second ;
	tmp->next = list[first] ;
	tmp->weight = weight;
	list[first]=tmp;
	return ;
}

typedef struct wght{
	int vertex;
	int value;
}wght;

int value[100];
int visited[100];
wght heap[100];
int r = 0;

void swap(int i,int j)
{
	wght tmp = heap[i];
	heap[i].value = heap[j].value;
	heap[i].vertex = heap[j].vertex;
	heap[j].value = tmp.value ;
	heap[j].vertex = tmp.vertex ;
}

void heapify(int tmp)
{
	if(tmp==1)
		return ;

	if(heap[tmp].value < heap[tmp/2].value)
	{
		swap(tmp/2,tmp);
		return heapify(tmp/2);
	}

	return;
}

int min(int a, int b, int c)
{
	if(a<=b && a<=c)
		return a;
	if(b<=c)
		return b;
	return c ;
}

void printheap(int tmp)
{
	if(tmp>r)
		return;
	printheap(2*tmp);
	printf("%d ",heap[tmp].value);
	printheap(2*tmp+1);
	return;
}


void delete(int pos)
{
	if(pos>r/2)
		return;
	int tmp = min(heap[pos].value,heap[2*pos].value,heap[2*pos+1].value);

	if(heap[pos].value==tmp)
		return ;
	if(tmp==heap[2*pos].value)
	{
		swap(pos,2*pos);
		return delete(2*pos);
	}

	swap(pos,2*pos+1);
	return delete(2*pos+1);
}


int shortest(int dest)
{
	printf("visited[%d] : %d\n",dest,visited[dest]);
	while(visited[dest]==-1)
	{
		int extract = heap[1].vertex;
		int tmp_value = heap[1].value;
		printf("Extracting %d\n",extract);
		swap(1,r);
		printheap(1);
		printf("\n");
		heap[r].vertex = 0;
		heap[r].value = INT_MAX;
		r--;
		delete(1);
		printheap(1);
		printf("\n");
		if(visited[extract]==-1)
		{
			printf("Node no. %d still not visited\n",extract);
			value[extract]=tmp_value;
			adj *current = list[extract];
			while(current!=NULL)
			{
				int tmp = current->vertex;
				if(visited[tmp]==-1)
				{
					printf("Inserting %d\n",current->weight);
					heap[++r].value = value[extract]+current->weight;
					heap[r].vertex = current->vertex;
					heapify(r);
					printheap(1);
					printf("\n");
				}

				current=current->next;
			}

			visited[extract]=1;
		}

		if(r==0)
			return -1;
	}

	return value[dest];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d %d",&n,&m);

		int i;
		for(i=0;i<=n;i++)
		{
			heap[i].vertex = 0;
			heap[i].value = INT_MAX;
			visited[i]=-1;
			value[i]=INT_MAX;
		}

		for(i=0;i<m;i++)
		{
			int a,b,c ;
			scanf("%d %d %d",&a,&b,&c);
			add(a,b,c);
		}

		int s,d;
		scanf("%d %d",&s,&d);

		printf("All scan complete\n");
		r = 0;
		heap[++r].vertex = s ;
		heap[r].value = 0;
		value[s]=0;
		printf("1\n");
		int ans = shortest(d);
		printf("%d\n",ans);
	}
	return 0;
}

