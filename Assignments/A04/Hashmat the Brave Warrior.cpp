 
#include <iostream>
 
using namespace std;

int main()
{  
    long long num1,num2;
    long long result=0;
    
    while(cin>>num1>>num2)
    {
        result=num1-num2;
        if(result<0)
        result*=-1;
        cout<<result<<endl;
    }
    return 0;
}