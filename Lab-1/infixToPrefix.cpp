#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int prece(char c)
{
    if(c=='^'|| c=='$')
    {
        return 3;
    }
    else if(c=='*'||c=='/')
    {
        return 2;
    }
    else if(c=='+'||c=='-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}


string infixToPostfix(string str)
{
    reverse(str.begin(),str.end());
    stack<char> stck;
    string res;


    for (int i = 0; i < str.length(); i++)
    {
        if (str[i]>='a'&& str[i]<='z'||str[i]>='A'&& str[i]<='Z')//isalnum()
        {
            res+=str[i];
        }

        else if (str[i]==')')
        {
            stck.push(str[i]);
        }

        else if(str[i]=='(')
        {
            while (!stck.empty()&&stck.top()!=')')
            {
                res+=stck.top();
                stck.pop();
            }
            if (!stck.empty())
            {
                stck.pop();
            }
        }


        else
        {
            while(!stck.empty() && prece(stck.top())>= prece(str[i])) 
            {
                res+=stck.top();
                stck.pop();
            }
            stck.push(str[i]);
        }
    }


    while (!stck.empty())
    {
        res+=stck.top();
        stck.pop();
    }
        
    reverse(res.begin(),res.end());
    return res;

}

int main()
{
    string s;
    cout<<"Enter any infix expression"<<endl;
    cin>>s;
    cout<<"Prefix expression is:"<<endl;
    cout<<infixToPostfix(s);
}