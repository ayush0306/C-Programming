#include<stdio.h>


long long int Q[2][100000];

void printQ(int r, int f)
{
	printf("r: %d f: %d\n",r,f);
	int i;
	for(i=f;i<r;i++)
		printf("%d ",Q[0][i]);
	printf("\n");
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int r=0,f=0;
		int n,k;
		long long int arr[100000];
		scanf("%d %d",&n,&k);
		int i;
		for(i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		for(i=0;i<k;i++)
		{
			while(r!=f && arr[i]>=Q[0][(r-1)%n])
				(r--)%n;
			Q[0][r]=arr[i];
			Q[1][r]=i;
			(r++)%n;
	//		printQ(r,f);
		}
		printf("%lld ",Q[0][f]);
		
		for(i=k;i<n;i++)
		{
			if(Q[1][f]<=i-k)
				(f++)%n;
			while(r!=f && arr[i]>=Q[0][(r-1)%n])
				(r--)%n;
			Q[0][r]=arr[i];
			Q[1][r]=i;
			(r++)%n;
		//	printQ(r,f);
			printf("%lld ",Q[0][f]);
		}

		printf("\n");

	}
	return 0;
}

