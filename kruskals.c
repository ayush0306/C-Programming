#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct edge{
	int a;
	int b;
	int weight;
}edge ;

edge arr[100005];
int parent[100005];
int p ;

int cmpfnc(const void *a, const void *b)
{
	return (((edge *)a)->weight - ((edge *)b)->weight);
}

int findset(int a)
{
	if(parent[a]==a)
		return a;
	parent[a]=findset(parent[a]);
	return parent[a];
}

int unite(int a,int b)
{
	int t1 = findset(a);
	int t2 = findset(b);

	if(t1==t2)
		return -1;
	
	parent[t2]=t1;
	return 1;
}

long long int kruskals(int m)
{
	long long int sum = 0;

	int i,tmp;
	for(i=0;i<m;i++)
	{
		tmp = unite(arr[i].a,arr[i].b);
		if(tmp==1)
			sum += (long long int)arr[i].weight ;
	}

	return sum;
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

		long long int total = 0 ;
		p = 0;

		for(i=0;i<100005;i++)
			parent[i]=i;

		for(i=0;i<m;i++)
		{
			int a,b,c ;
			scanf("%d %d %d",&a,&b,&c);
			/*adda(a,b,c);
			adda(b,a,c);*/
			arr[p].a = a ;
			arr[p].b = b ;
			arr[p++].weight = c ;
			total+=(long long int)c;
		}

		qsort(arr,m,sizeof(edge),cmpfnc);

	/*	for(i=0;i<m;i++)
			printf("%d---%d--->%d\n",arr[i].a,arr[i].b,arr[i].weight);
*/
		long long int ans = total - kruskals(m);
		printf("%lld\n",ans);
	}
	return 0;
}

