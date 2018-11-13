/*
    Implementation of prime number generation Sieve of Eratosthenes
    Running time:
        O(sqrt(n))
    Usage:
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


 
