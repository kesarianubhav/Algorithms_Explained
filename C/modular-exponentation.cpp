int modularExponentiation(int x,int n,int M)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)       
        return modularExponentiation((x*x)%M,n/2,M);
    else return (x*modularExponentiation((x*x)%M,(n-1)/2,M))%M;
}

int inverse_modulo(int c ,int M)
{
  return modularExponentation(c,M-2,M);
}
