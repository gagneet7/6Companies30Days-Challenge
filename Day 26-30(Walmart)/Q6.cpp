#define mod 1000000007
    //o(n) then 1st way is we can multiple with n for r times
    //o(logn) 2nd ways is if r is even we can calculate (n^2)^r/2 if we make n=n^2 then we will make r=r/2
    //and if r is odd then find n*n(r-1)
    long long power(long long int N,long long int R)
    {
       //Your code here
       if(R==0)return 1;

       if(R%2==0){
           N=((N%mod)*(N%mod))%mod;
           R=R/2;
           return power(N,R)%mod;
       }
       else
       {
           return ((N%mod)*(power(N,R-1)%mod))%mod;
       }

    }
