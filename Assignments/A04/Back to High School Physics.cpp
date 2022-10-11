#include <iostream>
 
using namespace std;

int main()
{  
    long long num1,num2,temp;
    long long result=0;
    
    while(cin>>num1>>num2)
    {
        num2*=2;
        temp=num1*num2;
        cout<<temp<<endl;
    }
    return 0;
}
