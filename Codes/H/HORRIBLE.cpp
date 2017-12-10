#include <iostream>
using namespace std;
void buildTree(long long a[],long long curr,long long start,long long end,long long* tree)
{
	if (start > end)
		return;
	if(start == end)
	{
		tree[curr] = a[start];
		return;
	}

	else
	{
		long long mid = (start+end)/2;

		buildTree(a,2*curr+1,start,mid,tree);
		buildTree(a,2*curr+2,mid+1,end,tree);

		tree[curr] = tree[2*curr+1]+tree[2*curr+2];
	}
}

void updateRange(long long tree[],long long lazy[],long long index,long long s,long long e,long long rs,long long re,long long inc)
{
	if (lazy[index] != 0)
	{
		tree[index] += (e-s+1) * lazy[index];

		if(s!=e)
		{
			lazy[2*index+1] += lazy[index];
			lazy[2*index+2] += lazy[index];
		}

		lazy[index] = 0;
	}

	if(s>e || s > re || e < rs)
		return;

	if(s >= rs && e <= re)
	{
		tree[index] += (e-s+1) * inc;

		if(s != e)
		{
			lazy[2*index+1] += inc;
			lazy[2*index+2] += inc;
		}

		return;
	}


		long long mid = (s+e)/2;

		updateRange(tree,lazy,2*index+1,s,mid,rs,re,inc);
		updateRange(tree,lazy,2*index+2,mid+1,e,rs,re,inc);

		tree[index] = tree[2*index+1] + tree[2*index+2];

}

long long query(long long tree[],long long lazy[],long long l,long long r,long long s,long long e,long long index)
{
	if(r<s || l>e || s>e)
		return 0;

	if(lazy[index] != 0)
	{
		tree[index] += (e-s+1)* lazy[index];

		if(s != e)
		{
			lazy[2*index+1] += lazy[index];
			lazy[2*index+2] +=  lazy[index];
		}

		lazy[index] = 0;
	}

	if(l <= s && r >= e)
	{
		return tree[index];
	}



		long long mid = (e+s)/2;

		long long left = query(tree,lazy,l,r,s,mid,2*index+1);
		long long right = query(tree,lazy,l,r,mid+1,e,2*index+2);
		return(left+right);

}

int main()
{
	long long t;
	cin >> t;

	while(t--)
	{
		long long n;
		long q;
		cin >> n;
		long long a[n];

		for (long long i = 0;i<n;i++)
		{
			a[i] = 0;
		}
		long long tree[4*n+1];

		buildTree(a,0,0,n-1,tree);
		long long lazy[4*n+1];

		for (long long i =0;i<4*n+1;i++)
		{
			lazy[i] = 0;
		}
		cin >> q;

		while(q--)
		{
			long long type;
			cin >> type;

			if(type == 0)
			{
				long long l,r,v;
				cin >> l >> r >> v;

				updateRange(tree,lazy,0,0,n-1,l-1,r-1,v);
			}

			if(type == 1)
			{
				long l,r;
				cin >> l >> r;
				cout <<query(tree,lazy,l-1,r-1,0,n-1,0) << endl;
			}
		}

	}
}

