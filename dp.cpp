// https://uva.onlinejudge.org/external/111/p11137.pdf
/** 

Input : Coin change when 1 coin can take infinity time.
Ex. Given array of coin and a value to form it using the array

Output: how many way to form the value using array 

**/
#include<bits/stdc++.h>
#define lli long long int
#define scf(n) scanf("%lld",&n)
#define rep1(n) for(int i=1;i<=n;i++)
#define prf(n) printf("%lld",n)
#define sci(n) scanf("%d",&n)
#define pri(n) printf("%d",n)
#define prl(n) printf("%lld",n)
#define scl(n) scanf("%lld",&n)
#define nl printf("\n")
#define spc printf(" ")
#define file freopen("in.txt","rt",stdin)
#define pii pair<int,int>
#define piii pair<int,string>
#define LL long long
using namespace std;

bool sortBySec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}
lli arr[]= {1,8,27,64,125,216,343,512,729,1000,1331,1728,2197,2744,3375,4096,4913,5832,6859,8000,9261};

lli dp[30][10009];
lli visited[30][10009];

lli x;

lli fun(lli pos,lli curr,lli caseno)
{
    if(pos == 21)
    {
        if(x == curr)
            return 1;
        return 0;
    }
    lli ret = 0;

    if(visited[pos][curr]==caseno)
        return dp[pos][curr];
    if(curr+arr[pos]<=x)
    {
        ret+=fun(pos,curr+arr[pos],caseno);
    }
    ret+=fun(pos+1,curr,caseno);

    visited[pos][curr] = caseno;

    return dp[pos][curr] = ret;
}

int main()
{
    int cnt = 1;
    while(scanf("%lld",&x)==1)
    {
        lli res = fun(0,0,cnt);
        prl(res),nl;
        cnt++;
    }

    return 0;
}

// alternative abd more efficient than before 
// without passing extra caseno parametre 

#include<bits/stdc++.h>
#define lli long long int
#define scf(n) scanf("%lld",&n)
#define rep1(n) for(int i=1;i<=n;i++)
#define prf(n) printf("%lld",n)
#define sci(n) scanf("%d",&n)
#define pri(n) printf("%d",n)
#define prl(n) printf("%lld",n)
#define scl(n) scanf("%lld",&n)
#define nl printf("\n")
#define spc printf(" ")
#define file freopen("in.txt","rt",stdin)
#define pii pair<int,int>
#define piii pair<int,string>
#define LL long long
using namespace std;

bool sortBySec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}
lli arr[]= {1,8,27,64,125,216,343,512,729,1000,1331,1728,2197,2744,3375,4096,4913,5832,6859,8000,9261};

lli dp[25][30009];

lli x;

lli fun(lli pos,lli curr)
{

    if(pos == 21)
    {
        if(0 == curr)
            return 1;
        return 0;
    }
    lli ret = 0;

    if(dp[pos][curr]!=-1)

        return dp[pos][curr];

    if(curr-arr[pos]>=0)
    {
        ret+=fun(pos,curr-arr[pos]);
    }
    ret+=fun(pos+1,curr);
    // dp[pos][curr] = 1;
    return dp[pos][curr] = ret;
}

int main()
{
    memset(dp,-1,sizeof dp);
    while(scanf("%lld",&x)==1)
    {
        lli res = fun(0,x);

       prl(res),nl;

    }

    return 0;
}


