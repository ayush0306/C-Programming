#include<stdio.h>
#include<limits.h>

int arr[100005];
int seg[500005];

int min(int a,int b)
{
	if(a<b)
		return a;
	return b;
}

int max(int a,int b)
{
	if(a>b)
		return a;
	return b;
}

int sum(int a,int b)
{
	return a+b;
}

int build(int l,int r,int i)
{
	if(l==r)
	{
		if(arr[l]%2==0)
			seg[i] = 1;
		else
			seg[i] = 0;
		return seg[i];
	}
	int mid = (l+r)/2 ;
	seg[i] = sum(build(l,mid,2*i+1),build(mid+1,r,2*i+2));
	return seg[i];
}

void print(int l, int r, int i)
{
	int mid = (l+r)/2;
	if(l!=r)
	{
		print(l,mid,2*i+1);
		print(mid+1,r,2*i+2);
	}
	printf("For range from %d to %d the no. of even elements is %d\n",l,r,seg[i]);
	return ;
}

int query(int l, int r, int i, int a, int b)
{
	if(b < l || a > r)
		return 0 ;
	if(l==a && r==b)
		return seg[i];

	int mid = (l+r)/2;
	int a1,b1;
	b1=min(mid,b);
	a1=max(a,mid+1);
	return sum(query(l,mid,2*i+1,a,b1),query(mid+1,r,2*i+2,a1,b));
}

int update(int l,int r,int i,int x,int v)
{
	if(l==r && l==x)
	{
		if(v%2==0)
			seg[i] = 1;
		else
			seg[i] = 0;
		return seg[i];
	}

	int mid = (l+r)/2 ;

	if(x>mid)
		seg[i] = sum(seg[2*i+1],update(mid+1,r,2*i+2,x,v));
	else
		seg[i] = sum(seg[2*i+2],update(l,mid,2*i+1,x,v));
	return seg[i];
}

int main()
{
	int n,q,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	build(0,n-1,0);
//	print(0,n-1,0);
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{
		int op,a,b;
		scanf("%d %d %d",&op,&a,&b);

		int ans;
		if(op==0)
		{
			update(0,n-1,0,a-1,b);
//			print(0,n-1,0);
		}
		else
			ans = query(0,n-1,0,a-1,b-1);
		if(op==1)
			printf("%d\n",ans);
		if(op==2)
			printf("%d\n",b-a+1-ans);
	}	
	return 0;
}

