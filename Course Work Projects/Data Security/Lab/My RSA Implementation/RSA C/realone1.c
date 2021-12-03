#include<stdio.h>
#include<math.h>

//To find gcd
int gcd(int a, int b) //EA
{
    int r;
    a=abs(a);
    b=abs(b);
    while (b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
//
//for calculating d
int calc_d(int e, int phy_n) //EEA
{
    int a=e;
    int b=phy_n;
    int r,gcd,x,y,q,n=0; //n represents count
    int tmpx,tmpy;
    int X[2]= {1 , 0};
    int Y[2]= {0,  1};
    a=abs(a);
    b=abs(b);
    while (b!=0){
        q=a/b; //quotient
        r=a%b; //remainder
        a=b;
        b=r;
        tmpx = X[1] * q + X[0];
        tmpy = Y[1] *q + Y[0];
        X[0]=X[1];
        Y[0]=Y[1];
        X[1]= tmpx;
        Y[1]= tmpy;
        n++;
    }
    x= pow(-1, n) * X[0];
    y= pow(-1,n+1) * Y[0];

    int d=x;
    while (d<=1){
        d= d+phy_n;
    }
    if (1<d && d<phy_n) return d;
}
/*
 * Fast modular exponentiation, gives us base ^ exponent % mod //For Miller Rabin
 */
long long modulo(long long base, long long exponent, long long mod)
{
    long long x = 1;
    long long y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}
/*
 * calculates (a * b) % mod taking into account that a * b might overflow //For Miller Rabin
 */
long long mulmod(long long a, long long b, long long mod)
{
    long long x = 0,y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}
/*
 * Miller-Rabin Primality test, "it" signifies the accuracy
 */
long long int Miller(long long int p,long long int  it){
    if(p<2){    //if number less than 2, it's not a prime
        return 0;
    }
    if(p!=2 && p%2==0){ 	//if it is an even number, it's not a prime
        return 0;
    }
    long long d=p-1;		// we start the checking from the last number before p if our number is 13 we start from 12 that is the s
    while(d%2==0){
        d/=2;
    }
    long long int  i;
    for(i=0;i<it;i++){
        long long int a=rand()%(p-1)+1,tt=d; 	// generating the random number by random generating function : a=rand()%(p-1)+1
        long long int  md=modulo(a,tt,p);
        while(tt!=p-1 && md!=1 && md!=p-1){
            md=mulmod(md, md, p);           //calculates (a * b) % mod taking into account that a * b might overflow
            tt *= 2;                        // tt multiplied by 2, after sometime we get back p-1, so we stop the while loop when tt==p-1
        }
        if(md!=p-1 && tt%2==0){          //if this happens its not prime otherwise it is
            return 0;
        }
    }
    return 1;
}
//
int main()
{
    //2 random prime numbers
    srand(time(NULL));
    double p;
    double q;
    while(1)
    {
        p=rand()%100 +1;		//1.generate
        if(Miller(p,20))
            break;
    }

    while(1)
    {
        q=rand()%100 +1;
        if(Miller(q,20) && p != q)
            break;
    }
    p=11;q=13;
    double n=p*q;
    double temp;
    double phy_n = (p-1)*(q-1);

    //public key
    //e stands for encryption exponent
    double e=2; //We start from 2

    //for checking co-prime which satisfies e>1
    while(e<phy_n){
    temp = gcd(e,phy_n);
    if(temp==1)
        break;
    else
        e++;
    }
    //private key
    //d stands for decryption exponent
    double d;
    d=calc_d(e,phy_n); //We get back the value of d
    //
    double msg = 71;
    double c = modulo(msg,e,n); //Using fast modular exponentiation
    double m = modulo(c,d, n);
    //
    printf("Message data = %.0lf",msg);
    printf("\np = %.0lf",p);
    printf("\nq = %.0lf",q);
    printf("\nn = pq = %.0lf",n);
    printf("\nphy_n = %.0lf",phy_n);
    printf("\ne = %.0lf",e);
    printf("\nd = %.0lf",d);
    printf("\nEncrypted data = %.0lf",c);
    printf("\nOriginal Message Sent = %.0lf",m);

    return 0;
}
