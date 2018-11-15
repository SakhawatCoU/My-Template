/*
    Implementation of prime number generation Sieve of Eratosthenes
    Running time:
        O(sqrt(n))
    Usage:
    (200000 or 2 x 10^5 ) porjonto prime ber kora jabe.
        only one function BuildSeive() generates the primes.
    Input:
       n, having prime number (1 to n).
    Output:
       all primes are stored in vector prime.
    Tested Problems:
*/


struct SeiveMethod
{

    long long int n;
    vector<long long int> prime;
    SeiveMethod (long long int n): n(n) {}

    void BuildSeive()
    {
        long long int marked[n+10];
        memset(marked,0,sizeof marked);
        prime.clear();
        long long int limit = sqrt(n+1);
        marked[0] = 1;
        marked[1] = 1;
        prime.push_back(2);

        for(long long int i=4; i<=n; i+=2)
            marked[i]=1;

        for(long long int i=3; i<=n; i+=2)
        {
            if(!marked[i])
            {
                prime.push_back(i);

                if(i<=limit)
                {
                    for(long long int j=i*i; j<=n; j=j+i*2)
                    {
                        marked[j]=1;
                    }
                }
            }
        }
    }
};


/*
    Implementation of Prime Factorization of long long int type
    Running time:
        O(sqrt(n))
    Usage:
        only one function generatePrimeFactor() generates the primes.
    Input:
       n, whose prime factors we need.
    Output:
       all primes are stored in vector primeFactors.
    Tested Problems:
*/

struct PrimeFact
{
    long long int n;
    vector<long long int> primeFactors;
    PrimeFact (long long int n) : n(n) {}
    void generatePrimeFactor()
    {
        primeFactors.clear();
        while(n%2==0)
        {
            primeFactors.push_back(2);
            n/=2;
        }
        for(long long int i=3; i<=sqrt(n); i+=2)
        {
            while(n%i==0)
            {
                primeFactors.push_back(i);
                n/=i;
            }
        }
        if(n>2)
            primeFactors.push_back(n);
    }
};

//total number of Reltively prime number of a Given number 
// 12 --->>> 1,3,5,7 = total 4
// 6 ---->>> 1,5 = total 2
int Singlephi(int n)
{
    int ret = n;

    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n/=i;
            }
            ret-=(ret/i);
        }
    }
    if(n>1)
    {
        ret-=(ret/n);
    }
    return ret;
}

/**

Prime factorization Using Generation of Prime 

***/
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
using namespace std;

struct SeiveMethod
{

    long long int n;
    vector<long long int> prime;
    SeiveMethod (long long int n): n(n) {}

    void BuildSeive()
    {
        long long int marked[n+10];
        memset(marked,0,sizeof marked);
        prime.clear();
        long long int limit = sqrt(n+1);
        marked[0] = 1;
        marked[1] = 1;
        prime.push_back(2);

        for(long long int i=4; i<=n; i+=2)
            marked[i]=1;

        for(long long int i=3; i<=n; i+=2)
        {
            if(!marked[i])
            {
                prime.push_back(i);

                if(i<=limit)
                {
                    for(int j=i*i; j<=n; j=j+i*2)
                    {
                        marked[j]=1;
                    }
                }
            }
        }
    }
};



vector<int>factors;

int main()
{
    int n = 12;
    SeiveMethod T(n);
    T.BuildSeive();
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < T.prime.size() && T.prime[i] <= sqrtn; i++ )
    {
        if ( n % T.prime[i] == 0 )
        {
            while ( n % T.prime[i] == 0 )
            {
                n /= T.prime[i];
                factors.push_back(T.prime[i]);
            }
            sqrtn = sqrt ( n );
        }
    }
    if ( n != 1 )
    {
        factors.push_back(n);
    }
    for(int i=0;i<factors.size();i++)
    {
        cout<<factors[i]<< " ";
    }

    return 0;
}


/** Number of Divisor NOD(n) Using Prime Factorization 

Upto array size we can find number of divisor NOD(n)

Global: 1 * 10^6

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
using namespace std;

int mark[1000000],prime[1000000],nprime =1;
int limit,n;
void PrimeNumber() /** Seive Method **/
{
    mark[1]=1;
    mark[0] =1;
    prime[nprime++]=2;

    for(int i=4; i<=n; i+=2)
        mark[i]=1;

    for(int i=3; i<=n; i+=2)
    {
        if(!mark[i])
        {
            prime[nprime++]=i;

            if(i<=limit)
            {
                for(int j=i*i; j<=n; j=j+i*2)
                {
                    mark[j]=1;
                }
            }
        }
    }

}


vector<int>factors;

int main()
{
    sci(n);
    limit = sqrt(n+1);
    PrimeNumber();
    int sqrtn = sqrt ( n );
    int res = 1;
    for ( int i = 1; i < nprime && prime[i] <= sqrtn; i++ )
    {
        if(mark[n]==0) break;
        if ( n % prime[i] == 0 )
        {
            int p = 0; // Counter for power of prime
            while ( n % prime[i] == 0 )
            {
                n /= prime[i];
                p++;
            }
            sqrtn = sqrt ( n );
            p++; // Increase it by one at end
            res *= p; // Multiply with answer
        }
    }
    if ( n != 1 )
    {
        res *= 2; // Remaining prime has power p^1. So multiply with 2/
    }
    pri(res),nl;

    return 0;
}


/** Number of Divisor NOD(n) Using Prime Factorization 

Using SeiveMethod Template 

Template size: 2 x 10^5

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
using namespace std;

struct SeiveMethod
{

    long long int n;
    vector<long long int> prime;
    SeiveMethod (long long int n): n(n) {}

    void BuildSeive()
    {
        long long int marked[n+10];
        memset(marked,0,sizeof marked);
        prime.clear();
        long long int limit = sqrt(n+1);
        marked[0] = 1;
        marked[1] = 1;
        prime.push_back(2);

        for(long long int i=4; i<=n; i+=2)
            marked[i]=1;

        for(long long int i=3; i<=n; i+=2)
        {
            if(!marked[i])
            {
                prime.push_back(i);

                if(i<=limit)
                {
                    for(int j=i*i; j<=n; j=j+i*2)
                    {
                        marked[j]=1;
                    }
                }
            }
        }
    }
};



vector<int>factors;

int main()
{
    int n;
    sci(n);
    SeiveMethod T(n);
    T.BuildSeive();

    int sqrtn = sqrt ( n );
    int res = 1;
    for ( int i = 0; i < T.prime.size() && T.prime[i] <= sqrtn; i++ ) {
        if ( n % T.prime[i] == 0 ) {
            int p = 0; // Counter for power of prime
            while ( n % T.prime[i] == 0 ) {
                n /= T.prime[i];
                p++;
            }
            sqrtn = sqrt ( n );
            p++; // Increase it by one at end
            res *= p; // Multiply with answer
        }
    }
    if ( n != 1 ) {
        res *= 2; // Remaining prime has power p^1. So multiply with 2/
    }
    pri(res),nl;

    return 0;
}


