#include<stdio.h>

void foo(int arr[],int count,int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(arr[i]!=-1)
		{	printf("%d",i);
			if(count==n)
			{
				printf("\n");
			/*	int j;
				for(j=0;j<n;j++)
					arr[j]=0;
						*/
				return ;
			}

			arr[i]=-1;
			foo(arr,count+1,n);
		}
	}

	return ;
}


int main()
{
	int n;
	scanf("%d",&n);
		
	int flag[100]={0};

	foo(flag,1,n);

	return 0;
}

	

