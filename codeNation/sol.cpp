#include<bits/stdc++.h>
#define ll long long int
using namespace std;

typedef struct
{
ll val;
ll r;
ll c;
ll ans;
}node;

bool cmp(node a, node b)
{
return a.val < b.val;
}

int main()
{
int n,m;
cin>>n>>m;
int ele = n*m;
node dp[ele];
ll row[n] = {-1};
ll col[m] = {-1};
ll ans[n][m];
ll trow[n] = {-1};
ll tcol[m] = {-1};
for(int j = 0 ; j < ele ; j++)
{
cin>>dp[j].val;
dp[j].r = j/m;
dp[j].c = j%m;
dp[j].ans = -1;
}

sort(dp, dp + ele , cmp);


for(int i = 0 ; i < ele ; i++)
{
	if(i == 0)
	{
		ll v = dp[0].val;
		while(dp[i].val == v)
		{
			row[dp[i].r] = 1;
			col[dp[i].c] = 1;
			dp[i].ans = 1;
			i++;
		}
		i--;
	}
	else
	{
		ll v = dp[i].val;
		int j = i;
		int k = i;
		while(dp[i].val == v)
		{
			int ma = max(row[dp[i].r],col[dp[i].c]);

			if(ma == -1) {
				dp[i].ans = 1;
				trow[dp[i].r] = max(trow[dp[i].r],dp[i].ans);
				tcol[dp[i].c] = max(tcol[dp[i].c],dp[i].ans);
				trow[dp[i].r] = max(trow[dp[i].r],tcol[dp[i].c]);
				tcol[dp[i].c] = trow[dp[i].r];
			}
			else
			{
				dp[i].ans = ma + 1;
				trow[dp[i].r] = max(trow[dp[i].r],dp[i].ans);
				tcol[dp[i].c] = max(tcol[dp[i].c],dp[i].ans);
				trow[dp[i].r] = max(trow[dp[i].r],tcol[dp[i].c]);
				tcol[dp[i].c] = trow[dp[i].r];
			}
			i++;
		}
		i--;

		while(dp[j].val == v)
		{
			dp[j].ans = max(dp[j].ans,max(trow[dp[j].r],tcol[dp[j].c]));
			j++;
		}	

		while(dp[k].val == v)
		{
			row[dp[k].r] = max(row[dp[k].r],dp[k].ans);
			col[dp[k].c] = max(col[dp[k].c],dp[k].ans);
			trow[dp[k].r] = -1;
			tcol[dp[k].c] = -1;
			k++;
		}	
	}
}

for(int i = 0 ; i < ele ; i++)
{
	ans[dp[i].r][dp[i].c] = dp[i].ans;
}

for(int i = 0 ; i < n ; i++)
{
	for(int j = 0 ; j < m ; j++)
		cout<<ans[i][j]<<" ";
	cout<<endl;
}
}