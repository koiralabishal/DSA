#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

class Queue
{
    int *queue;
    int front, rear, data, size;

public:
    Queue()
    {
        cout << "\nEnter the size of the queue." << endl;
        cin >> size;
        queue = new int[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        if ((front > rear) || (front == -1) && (rear == -1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if (rear == size - 1)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    void Enqueue()
    {
        if (isFull())
        {
            cout << "Queue Overflow." << endl;
        }

        else
        {
            cout << "\nEnter the data to be inserted." << endl;
            cin >> data;
            rear++;
            queue[rear] = data;
            cout << queue[rear] << " is inserted successfully." << endl;
        }

        if (front == -1)
        {
            front++;
        }
    }

    void Dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow." << endl;
        }

        else
        {
            data = queue[front];
            front++;
            cout << "Front element is " << data << "." << endl;
            cout << data << " is deleted successfully." << endl;
        }
    }

    void Display()
    {
        cout << "\nYour queue is:" << endl;
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << setw(5);
        }
        cout << endl;
    }
};

int main()
{
    Queue q;

    int opt;
    while (1)
    {
        cout << "\n*************************" << endl;
        cout << "Your Options:" << endl;
        cout << "1)Insert data" << endl;
        cout << "2)Delete data" << endl;
        cout << "3)Display data" << endl;
        cout << "4)Exit" << endl;
        cout << "Choose the options above:" << endl;
        cin >> opt;
        switch (opt)
        {
        case 1:
            q.Enqueue();
            break;

        case 2:
            q.Dequeue();
            break;

        case 3:
            q.Display();
            break;

        case 4:
            exit(0);
            break;

        default:
            cout << "Invalid Choice!!" << endl;
            break;
        }
    }
}