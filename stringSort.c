#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define ll long long int
#define m 1000000007

int cmpfunc(const void * a,const void * b)
{
	return ( strcmp( *(char **)a , *(char **)b) ) ;
}


int main()
{
	char *arr[100];
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		char *tmp = (char *)malloc(100*sizeof(char));
		scanf("%s",tmp);
		arr[i]=tmp;
	}
	qsort(arr,n,sizeof(char *),cmpfunc);
	for(i=0;i<n;i++)
		printf("%s\n",arr[i]);
	return 0;
}


