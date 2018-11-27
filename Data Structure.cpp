/**
Sparse Table for Range Minimum Query 

Complexity: Each query in O(log(N)) (N is the size of Arr), with initial O(N * log(N)) preprocessing.

**/
#include<bits/stdc++.h>
#define lli  long long int
#define scf(n) scanf("%lld",&n)
#define rep1(n) for(int i=1;i<=n;i++)
#define prf(n) printf("%lld",n)
#define sci(n) scanf("%d",&n)
#define pri(n) printf("%d",n)
#define prl(n) printf("%lld",n)
#define scl(n) scanf("%lld",&n)
#define inf  1000000000
#define nl printf("\n")
#define spc printf(" ")
#define N 1000000
#define pii pair<lli,lli>
using namespace std;

int Prstbl[100000][25];
int arr[] = {1,3,7,2,1,5,6,13,9};
int k,sz;
void BuildTable()
{
    for(int i=0;i<sz;i++)
    {
        Prstbl[i][0] = arr[i];
    }

    for(int j=1;j<=k;j++)
    {
        for(int i=0;i<=sz - (1 << j);i++)
        {
            Prstbl[i][j] = min(Prstbl[i][j-1],Prstbl[i+(1 << (j-1))][j-1]);
        }
    }
}

int Query(int L,int R)
{
    int ans = 1000009;

    for(int j=k;j>=0;j--)
    {
        if(L + (1 << j)-1<=R)
        {
            ans = min(ans,Prstbl[L][j]);
            L+=(1 << j);
        }
    }
    return ans;
}


int main()
{

   sz = sizeof(arr)/sizeof(arr[0]);
   k = floor(log2(sz));
   BuildTable();
   int q;
   int l,r;
   cin>>q;

   while(q--)
   {
       sci(l);
       sci(r);
       int answer = Query(l,r);
       cout<<answer<<endl;
   }



    return 0;
}

