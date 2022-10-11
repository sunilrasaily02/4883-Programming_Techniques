#include <iostream>
#include <string> 
using namespace std;
 

int main()
{ 
    string str;
    string modifiedStr;
    bool openBracket=true;
    while(getline(cin,str))
    {
        modifiedStr="";
        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='"')
            {
                 
                if(openBracket)
                {
                    openBracket=false;
                    modifiedStr+='`';
                    modifiedStr+='`';
                }else
                {
                    openBracket=true;
                    modifiedStr+='\'';
                    modifiedStr+='\'';
                }
            }
            else
            {
                modifiedStr+=str[i];
            }
        }
        cout<<modifiedStr<<endl;
    }
     
    return 0;
}