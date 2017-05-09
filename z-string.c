#include<stdio.h>
#include<string.h>

int arr[5005];
int count[5005];
int tmp[5005];
int contri[5005];
int final[5005];
#define m 1000000007
int c1=0;
int mult(int x,int y)
{
  long long int x1=(long long int)x;
  long long int y1=(long long int)y;
  long long int ans=x1*y1;
  ans%=m;
  return (int)ans;
}
int mod(int x1,int y)
{
	int p=1;
	x1%=m;
	while(y>0)
	{
		if(y&1 ==1)
		  p=mult(x1,p);
		x1=mult(x1,x1);
		y>>=1;
	}
	return p;
}
void z_string(char str[])
{
	int size=strlen(str);
	int i,l,r,k;
	arr[0]=size;
	l=0;r=0;
	for(i=1;i<size;i++)
	{   
		if(i>r)
		{
			l=i;r=i;
			while(r<size && str[r-l]==str[r])
				r++;
			arr[i]=r-l;
			r--;
		}
		else
		{
			k=i-l;
			if(arr[k]<r-i+1)
				arr[i]=arr[k];
			else
			{
				l=i;
				while(r<size && str[r-l]==str[r])
					r++;
				arr[i]=r-l;
				r--;
			}
		}
	}
}

void z_func(char str[])
{
	int i,l=strlen(str);
	count[0]=0;
	z_string(str);
	for(i=0;i<l;i++)
		count[arr[i]]++;
	int offset=0;

	for(i=l;i>0;i--)
	{
		count[i]+=offset;
		offset=count[i];
	}

	for(i=1;i<=l;i++)
	{
		tmp[count[i]]++;
		tmp[count[i]-1]--;
	}

	return ;
}

int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	int i;
	char string[5005];
	scanf("%s",string);

	for(i=0;i<=n;i++)
	{
		contri[i]=0;
		final[i]=0;
		tmp[i]=0;
	}
	
	int j;

	for(i=0;i<n;i++)
	{
		for(j=0;j<=n;j++)
			count[j]=0;
		z_func(string+i);

		/*	for(j=0;j<n;j++)
			printf("%d ",arr[j]);
			printf("\n");

			for(j=1;j<=n;j++)
			printf("%d ",count[j]);
			printf("\n");
			*/	
	}

//	printf("Temp array : ");
//	for(i=1;i<=n;i++)
//		printf("%d ",tmp[i]);
//	printf("\n");


	int start=n;
	int r;
	contri[start]=1;
	final[start]=tmp[start];
	//printf("%d\n",mod(3,m-2));
	int arr[5005];
	for(i=1;i<5005;i++)
	  arr[i]=mod(i,m-2);
//	printf("Mod array : ");
//	for(i=1;i<5005;i++)
//	  printf("%d ",arr[i]);
//	printf("\n");
	for(r=n;r>1;r--)
	{
	         int sum = 0;
		for(i=n;i>r-1;i--)
		{
			int t1=r;
			int t2=i-r+1;
			contri[i]=mult(contri[i],t1);
			int x=1;
			//printf("t2: %d i:%d ;r:%d\n",t2,i,r);
			x= arr[t2];
			contri[i]=mult(contri[i],x);
			sum=(sum+mult(contri[i],tmp[i]))%m;
		}
	//	if(r==n/2)
	//		break;
		contri[r-1]=1;
		final[r-1]=(sum+tmp[r-1])%m;
	}
//	printf("Final array : ");
//	for(i=1;i<=n;i++)
//		printf("%lld ",final[i]);
//	printf("\n");

	while(q--)
	{
		int x;
		scanf("%d",&x);
		if(x>n)
			printf("0\n");
		else
			printf("%d\n",final[x]);
	}

	return 0;
}
