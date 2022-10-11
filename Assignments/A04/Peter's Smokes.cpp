 
#include <iostream>
 
using namespace std;

int main()
{  
    long long n,k;
    long result=0;
    
    while(cin>>n>>k)
    {
         result=n;
         while(n>=k)
         {
             result++;
             n-=k;
             n++;
         }
         cout<<result<<endl;
    }
    return 0;
}