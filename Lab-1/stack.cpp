#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;

class Stack
{
    int data,size;
    int* stck;
    int top;
    public:
   
    Stack()
    {
        cout<<endl<<"Enter the size of the stack."<<endl;
        cin>>size;
        stck= new int[size];
        top = -1;
    }
     
    bool isFull()
    {
        if (top == size-1)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }

    bool isEmpty()
    {
        if (top == -1)
        {
           return true;
        }

        else
        {
           return false;
        }
        
        
    }
    void Push()
    {
        if(isFull())
        {
            cout<<"Stack Overflow"<<endl;
        }
        else
        {
            cout<<endl<<"Enter the data to be pushed."<<endl;
            cin>>data;
            top++;
            stck[top]=data;
            cout<<stck[top]<<" is pushed in your stack."<<endl;
        }

        
    }

    void Pop()
    {
        if (isEmpty())
        {
           cout<<"Stack Underflow."<<endl;
        }
        else
        {
            data=stck[top];
            top--;
            cout<<"Top element is: "<<data<<endl;
            cout<<data<<" is popped from your stack."<<endl;
        }
        
    }
    

    void displayStack()
    {
        cout<<endl<<"Your Stack is:"<<endl;
        for (int i=0; i<=top; i++)
        {
            cout<<stck[i]<<setw(5);
        }
        
        cout<<endl;
    }

};
int main()
{

    Stack s;

    int opt;
    while(1)
    {
        cout<<endl<<endl;
        cout<<"************************"<<endl;
        cout<<"Your Options:"<<endl;
        cout<<"1)Push"<<endl;
        cout<<"2)Pop"<<endl;
        cout<<"3)Display"<<endl;
        cout<<"4)Exit"<<endl<<endl;
        cout<<"Choose the option above:"<<endl;
      
        cin>>opt;
        switch(opt)
        {
            case 1:
            s.Push();
            break;
            
            
            case 2:
            s.Pop();
            break;
            
            

            case 3:
            s.displayStack();
            break;

            case 4:
            exit(0);
            break;
            

            default:
            cout<<"Invalid choice!";
        }
    }
}