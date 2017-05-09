#include<stdio.h>

long long int max(long long int a, long long int b)
{
	if(a>b)
		return a;
	return b;
}

void printStk(long long int *store,long long int top)
{
	long long int i;
	for(i=0;i<=top;i++)
		printf("%lld ",store[i]);
	printf("\n");

	return;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int store[100005];
		long long int top=0;

		long long int arr[100005];
		long long int n;
		scanf("%lld",&n);
		long long int i;
		long long int gauche[100005];
		long long int droit[100005];	
		long long int final[100005];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&arr[i]);
			gauche[i] = -1;
			droit[i] = n;
			final[i] = 0;
		}
		final[n]=0;

		for(i=0;i<n;i++)
		{
			while(top!=0 && arr[store[top]]>=arr[i])
				top--;
			if(top!=0)
				gauche[i]=store[top];
			top++;
			store[top]=i;

		//	printStk(store,top);
		}

		//printf("gauche : ");
		//printStk(gauche,n);
		
		top=0;
		
		for(i=n-1;i>=0;i--)
		{
			while(top!=0 && arr[store[top]]>=arr[i])
				top--;
			if(top!=0)
				droit[i]=store[top];
			top++;
			store[top]=i;
		//	printStk(store,top);
		}
		//printf("droit : ");
		//printStk(droit,n);

		for(i=0;i<n;i++)
		{
			long long int len = droit[i] - gauche[i] -1 ;
			final[len] = max(final[len],arr[i]);
		}

		//printStk(final,n+1);

		for(i=n-1;i>=1;i--)
			final[i] = max(final[i],final[i+1]);

		for(i=1;i<n;i++)
			printf("%lld ",final[i]);
		printf("%lld\n",final[n]);
	}
	return 0;
}

		


		
			

