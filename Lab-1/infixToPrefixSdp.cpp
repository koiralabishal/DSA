#include<iostream>
#include<stack>
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
    stack<char> stck;
    string res;


    for (int i = 0; i < str.length(); i++)
    {
        if (str[i]>='a'&& str[i]<='z'||str[i]>='A'&& str[i]<='Z')//isalnum()
        {
            res+=str[i];
        }

        else if (str[i]=='(')
        {
            stck.push(str[i]);
        }

        else if(str[i]==')')
        {
            while (!stck.empty()&&stck.top()!='(')
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
        
    return res;
}
string infixToPrefix(string infix){
    char c;
    int len;
    len=infix.size();
    for (int i = 0; i < len/2; i++)
    {
        c=infix[i];
        infix[i]=infix[len-i-1];
        infix[len-i-1]=c;
    }
    for (int i = 0; i < len; i++)
    {
        if(infix[i]=='('){
            infix[i]=')';
        }
        else if(infix[i]==')'){
            infix[i]='(';
        }
    }
    string prefix=infixToPostfix(infix);
    len=prefix.size();
    for (int i = 0; i < len/2; i++)
    {
        c=prefix[i];
        prefix[i]=prefix[len-i-1];
        prefix[len-i-1]=c;
    }
    return prefix;
}

int main()
{
    string s;
    cout<<"Enter any infix expression"<<endl;
    cin>>s;
    cout<<"Prefix expression is:"<<endl;
    cout<<infixToPrefix(s);
}