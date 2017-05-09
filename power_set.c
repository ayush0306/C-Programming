#include<stdio.h>

char arr[100];
int flag[100],n;

void printf_arr(int *flag)
{
	int i;
	for(i=0;i<n;i++)
		if(flag[i]!=-1)
			printf("%c",arr[i]);
	printf("\n");
	return ;
}

void powerset(int *flag,int pos)
{
//	printf("pos: %d\n",pos);
	if(pos==n-1)
	{
		printf_arr(flag);
		flag[pos]=0;
		printf_arr(flag);
	}
	else
	{
		powerset(flag,pos+1);

		int i;
		for(i=pos;i<n;i++)
			flag[i]=-1;
		flag[pos]=0;
		powerset(flag,pos+1);

		for(i=pos;i<n;i++)
			flag[i]=-1;
	}

	return;
}



int main()
{
	scanf("%d",&n);
	
	scanf("%s",arr);

	int i;
	for(i=0;i<n;i++)
	{
//		scanf("%s",arr);
		flag[i]=-1 ;
	}

	powerset(flag,0);

	return 0;
}
