#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int arr[300005];
int seg[1500005];
int first[100005];
int order[300005];
int level[100005];

typedef struct adj{
	int vertex ;
	struct adj *next;
}adj;

adj * list[100005] = {NULL} ;

void add(int first, int second)
{
	adj *tmp = (adj*)malloc(sizeof(adj));
	tmp->vertex = second ;
	tmp->next = list[first] ;
	list[first]=tmp ;
	return ;
}

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

int build(int l,int r,int i)
{
	if(l==r)
	{
		seg[i] = order[l];
		return seg[i];
	}
	int mid = (l+r)/2 ;
	int tp1=build(l,mid,2*i+1);
	int tp2=build(mid+1,r,2*i+2);
	if(level[tp1]>level[tp2])
		seg[i]=tp2;
	else
		seg[i]=tp1;
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
		return 100005 ;
	if(l==a && r==b)
		return seg[i];
	int mid = (l+r)/2;
	int b1=min(mid,b);
	int a1=max(a,mid+1);
	int tp1=query(l,mid,2*i+1,a,b1);
	//printf("for %d to %d ans is %d and level is %d\n",l,mid,tp1,level[tp1]);
	int tp2=query(mid+1,r,2*i+2,a1,b);
	//printf("for %d to %d ans is %d and level is %d\n",mid+1,r,tp2,level[tp2]);
	if(level[tp1]>level[tp2])
		return tp2;
	return tp1;
	//return min(query(l,mid,2*i+1,a,b1),query(mid+1,r,2*i+2,a1,b));
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

int p = 0;

void dfs(int ver, int lev,int par)
{
	first[ver]=p;
	order[p]=ver;
	arr[p++]=lev;
	level[ver]=lev;
	adj * current = list[ver];

	while(current!=NULL)
	{
		if(current->vertex!=par)
		{
			dfs(current->vertex,lev+1,ver);
			order[p]=ver;
			arr[p++]=lev;
		}
		current=current->next;
	}
	return;
}


int main()
{
	int n,i;
	scanf("%d",&n);

	for(i=1;i<=n;i++)
		first[i]=-1;

	for(i=1;i<n;i++)
	{
		int a,b ;
		scanf("%d %d",&a,&b);
		add(a,b);
		add(b,a);
	}

	dfs(1,1,0);

	for(i=0;i<p;i++)
		printf("%d ",order[i]);
	printf("\n");
	
	for(i=0;i<p;i++)
		printf("%d ",arr[i]);
	printf("\n");

	for(i=1;i<=n;i++)
		printf("%d ",first[i]);
	printf("\n");
	
	for(i=1;i<=n;i++)
		printf("%d ",level[i]);
	printf("\n");
	
	level[100005]=INT_MAX;
	build(0,p-1,0);
//	print(0,p-1,0);
	
	int q;
	scanf("%d",&q);

	while(q--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		int t1=min(first[a],first[b]);
		int t2=max(first[a],first[b]);
		int ans = query(0,p-1,0,t1,t2);
		printf("%d\n",ans);
	}

	return 0;
}


