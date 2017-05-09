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

int build(int l,int r,int i)
{
	if(l==r)
	{
		seg[i] = arr[l];
		return arr[l];
	}
	int mid = (l+r)/2 ;
	seg[i] = min(build(l,mid,2*i+1),build(mid+1,r,2*i+2));
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
	printf("For range from %d to %d the min is %d\n",l,r,seg[i]);
	return ;
}

int query(int l, int r, int i, int a, int b)
{
	if(b < l || a > r)
		return INT_MAX ;
	if(l==a && r==b)
		return seg[i];

	int mid = (l+r)/2;
	int b1=min(mid,b);
	int a1=max(a,mid+1);
	return min(query(l,mid,2*i+1,a,mid),query(mid+1,r,2*i+2,mid+1,b));
}

int update(int l,int r,int i,int x,int v)
{
	if(l==r && l==x)
	{
		seg[i] = v;
		return v;
	}

	int mid = (l+r)/2 ;

	if(x>mid)
		seg[i] = min(seg[2*i+1],update(mid+1,r,2*i+2,x,v));
	else
		seg[i] = min(seg[2*i+2],update(l,mid,2*i+1,x,v));
	return seg[i];
}

int main()
{
	int n;
	printf("Enter the no. of entries : ");
	scanf("%d",&n);

	int i;
	printf("Enter the values\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	build(0,n-1,0);

	while(1)
	{
		printf("1.Update Entry 2.Range Query 3.PrintSegTree 4.PrintArray 5.Quit\n");	
		int op;
		scanf("%d",&op);

		if(op==5)
			break;
		if(op==4)
		{
			for(i=0;i<n;i++)
				printf("%d ",arr[i]);
			printf("\n");
		}

		if(op==3)
			print(0,n-1,0);

		if(op==1)
		{
			printf("Enter the index : ");
			int ind;
			scanf("%d",&ind);
			printf("Enter the new value : ");
			int val;
			scanf("%d",&val);
			arr[ind] = val ;
			update(0,n-1,0,ind,val);
		}

		if(op==2)
		{
			printf("Enter range : ");
			int a,b;
			scanf("%d %d",&a,&b);
			int ans = query(0,n-1,0,a,b);
			printf("%d\n",ans);
		}

	}

	return 0;
}

