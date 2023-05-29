#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

class circularQueue
{
    int *crQueue;
    int front, rear, data, size;

public:
    circularQueue()
    {
        cout << "\nEnter the size of the queue." << endl;
        cin >> size;
        crQueue = new int[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
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
        if ((front == 0 && rear == size - 1) || (front == rear + 1))
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
            rear = (rear + 1) % size;
            crQueue[rear] = data;
            cout << crQueue[rear] << " is inserted successfully." << endl;
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
            data = crQueue[front];
            front = (front + 1) % size;
            cout << "Front element is " << data << "." << endl;
            cout << data << " is deleted successfully." << endl;
        }
    }

    void Display()
    {

        cout << "\nYour queue is:" << endl;

        for (int i = front; i != rear; i = (i + 1) % size)
        {
            cout << crQueue[i] << setw(5);
        }
        cout << crQueue[rear] << endl;
    }
};

int main()
{
    circularQueue q;

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
    return 0;
}