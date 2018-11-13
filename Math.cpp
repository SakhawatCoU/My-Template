/*
    Implementation of prime number generation Sieve of Eratosthenes
    Running time:
        O(sqrt(n))
    Usage:
        only one function BuildSeive() generates the primes.
    Input:
       n, having prime number (1 to n).
    Output:
       all primes are stored in vector<prime>.
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
                    for(int j=i*i; j<=n; j=j+i*2)
                    {
                        marked[j]=1;
                    }
                }
            }
        }
    }
};
