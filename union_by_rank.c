#include<stdio.h>

int parent[100005];
int rank[100005];

void newSet(int a)
{
	if(rank[a]!=-1)
	{
		printf("Element already exists\n");
		return ;
	}

	parent[a]=a;
	rank[a]=0;
}

int findset(int a)
{
	if(rank[a]==-1)
	{
		printf("Element does not exist\n");
		return -1 ;
	}

	if(parent[a]==a)
	{
		printf("Belongs to set represented by %d\n",a);
		return a;
	}

	parent[a] = findset(parent[a]);
	return parent[a];
}

void unite(int a,int b)
{
	int t1 = findset(a);
	int t2 = findset(b);

	if(t1*t2 < 0)
	{
		printf("One of the element does not exist\n");
		return ;
	}

	if(t1==t2)
	{
		printf("Already in the same set\n");
		return ;
	}

	if(rank[t1]>=rank[t2])
	{
		parent[t2]=t1;
		if(rank[t1]==rank[t2])
			rank[t1]++;
		return;
	}

	parent[t1]=t2;
	return;
}


int main()
{
	int i;
	for(i=0;i<100005;i++)
	{
		parent[i]=-1;
		rank[i]=-1;
	}

	int t;
	printf("Enter the no. of operations : ");
	scanf("%d",&t);

	while(t--)
	{
		int op;
		printf("1.Make a new set 2.Join two existing sets(Union) 3.Find the set where a element belongs\n");
		scanf("%d",&op);

		if(op==1)
		{
			int a;
			scanf("%d",&a);
			newSet(a);
		}

		if(op==2)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			unite(a,b);
		}

		if(op==3)
		{
			int a;
			scanf("%d",&a);
			findset(a);
		}
	}

	return 0;
}

