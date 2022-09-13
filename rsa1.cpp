// This programm find c and d of rsa encrypting algorithm.
// you have to provide coprime , value of e and a value for M;


#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
    if(b==0)return a;

       return gcd(b,a%b);

}
bool  checkPrime(int num)
{
    if(num<2)
    {return false;
    }
    for(int i=2;i*i<num;i++)
    {
        if(num%i==0)
        {
            return false;
            }
    }
    return true;
}
int modinverse(int base,int number,int t1,int t2)
{
    if(base==1 && number==0)
    {
        return t1;
    }
    else
    {
        int q=base/number;
        int remainder=base%number;
        base=number;
        number=remainder;
        int t=(t1-q*t2);
        t1=t2;
        t2=t;
        return modinverse(base,number,t1,t2);
    }
    return 0;
}

int main()
{
    int p1,p2;
    do{
      cout<<"Type coprime number: "<<endl;
         cin>>p1>>p2;
    }while(!checkPrime(p1) || !checkPrime(p2) && gcd(p1,p2)!=1);

int n=p1*p2;
int nphi=(p1-1) * (p2-1);
int e;
int d;
cout<<"Type value of e: "<<endl;
cin>>e;
int inverse= modinverse(nphi,e,0,1);
if(inverse<0)
{
d = inverse+nphi;
}
else
{
    d=inverse%nphi;
}
cout<<"The value of D: "<<d<<endl;
int m;
cout<<"Type value of M:"<<endl;
cin>>m;
int praised=pow(m,e);
int c = praised%n;
cout<<"Value of C:"<<c<<endl;
cout<<"Public key:  "<<e<<" "<<n<<endl;
cout<<"Private key:  "<<d<<" "<<n<<endl;



}
