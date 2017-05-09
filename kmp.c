#include<stdio.h>
#include<string.h>

int main()
{
	char str1[1000];
	scanf("%s",str1);
	char mas[1000];
	scanf("%s",mas);
	int tmp[1000];
	int n = strlen(str1);
	tmp[0] = 0;
	int i=0,j=1;

	printf("%s %s\n",str1,mas);

	while(j<n)
	{
		if(str1[i]==str1[j])
			tmp[j++]=++i ;
		else
		{
			if(i==0)
				tmp[j++]=0;
			else
				i = tmp[i-1];
		}
	}

	for(i=0;i<n;i++)
		printf("%d ",tmp[i]);
	printf("\n");

	int n2 = strlen(mas);

	i=0;j=0 ;
	int ans = 0;

	while(i<n2)
	{
		printf("%d %d\n",i,j);
		if(mas[i]==str1[j])
		{
			if(j==n-1)
			{
				ans=1;
				break;
			}

			else
			{
				i++;j++;
			}
		}

		else
		{
			if(j==0)
				i++;
			else
				j = tmp[j-1];
		}

	}

	printf("%d\n",ans);

	return 0;
}






