#include<stdio.h>

int A[10];
int count = 0;

int merge(int l1,int l2, int r1, int r2)
{														//sort and return l1 ;
	int i ;
	int tmp1 = l1 ;
	int tmp2 = l2 ;
	int t3 = l1 ;

	int sortA[10] ;

	while(tmp1<=r1 && tmp2<=r2)
	{
		if (A[tmp1] >  A[tmp2])
		{
			sortA[t3] = A[tmp2] ;
			tmp2++ ;
			t3++ ;
			printf("no. %d\n",A[tmp2-1]);
			count+=r1-tmp1+1;
		}

		else
		{
			sortA[t3] = A[tmp1] ;
			tmp1++ ;
			t3++ ;
		}

	}

	if (tmp1==r1+1)
	{	
		while(tmp2<=r2)
		{
			sortA[t3] = A[tmp2] ;
			tmp2++ ;
			t3++ ;
		}

	}


	if (tmp2==r2+1)
	{	
		while(tmp1<=r1)
		{
			sortA[t3] = A[tmp1] ;
			tmp1++ ;
			t3++ ;
		}
	}

	for (i=l1 ; i<=r2 ; i++)
		A[i] = sortA[i] ;

	return l1 ;
}

int sort(int l, int r)
{
	if (l==r)
		return l;

	else
	{
		int mid = l + (r-l)/2 ;
//		printf("%d %d %d\nA[l]=%d A[mid]=%d A[r]=%d\n",l,mid,r,A[l],A[mid],A[r]);
		return merge(sort(l,mid),sort(mid+1,r),mid,r) ;
	}

}

int main()
{

	int i ;
	int n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&A[i]) ;

	int ans = sort(0,n-1) ;

	for(i=0 ; i<n ; i++)
		printf("%d ",A[i]) ;
	printf("\n");
	printf("count : %d\n",count);
	return 0 ;

}

