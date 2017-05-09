#include<stdio.h>
#include<limits.h>

int arr[100005];
int seg[500005];
int lazy[500005];

int min(int a,int b)
{
	if(a<b)
		return a;
	return b;
}

int max(int a, int b)
{
	if(a>b)
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
	if(lazy[i]!=0)
	{
		seg[i]+=lazy[i];
		if(l!=r)
		{
			lazy[2*i+1]+=lazy[i];
			lazy[2*i+2]+=lazy[i];
		}
		lazy[i]=0;
	}

	if(b < l || a > r)
		return INT_MAX ;
	if(l==a && r==b)
		return seg[i];
	
	int mid = (l+r)/2;
	int b1=min(mid,b);
	int a1=max(a,mid+1);
	return min(query(l,mid,2*i+1,a,b1),query(mid+1,r,2*i+2,a1,b));
}

void update(int l,int r,int i,int a,int b,int v)
{
	if(l>r)
		return;
	
	if(lazy[i]!=0)
	{
		seg[i]+=lazy[i];
		if(l!=r)
		{
			lazy[2*i+1]+=lazy[i];
			lazy[2*i+2]+=lazy[i];
		}
		lazy[i]=0;
	}
	
	if(b < l || a > r)
		return ;
	
	if(l==a && r==b)
	{
		seg[i] += v ;
		if(l!=r)
		{
			lazy[2*i+1]+=v;
			lazy[2*i+2]+=v;
		}
		return ;
	}
	
	int mid = (l+r)/2 ;
	int b1=min(mid,b);
	int a1=max(a,mid+1);
	update(l,mid,2*i+1,a,b1,v);
	update(mid+1,r,2*i+2,a1,b,v);
	seg[i] = min(seg[2*i+1],seg[2*i+2]);	
	return;
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
	for(i=0;i<500005;i++)
		lazy[i]=0;

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
		
		if(op==2)
		{
			printf("Enter range : ");
			int a,b;
			scanf("%d %d",&a,&b);
			if(a>b)
				a = a + b - (b=a);
			int ans = query(0,n-1,0,a,b);
			printf("%d\n",ans);
		}
		
		if(op==1)
		{
			printf("Enter the indeces : ");
			int ind1,ind2;
			scanf("%d %d",&ind1,&ind2);
			if(ind1>ind2)
				ind1 = ind1 + ind2 - (ind2=ind1);
			printf("Increase by : ");
			int val;
			scanf("%d",&val);
			for(i=ind1;i<=ind2;i++)
				arr[i] += val ;
			update(0,n-1,0,ind1,ind2,val);
		}



	}

	return 0;
}
			
