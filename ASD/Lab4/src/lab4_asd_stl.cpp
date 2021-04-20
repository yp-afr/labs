#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Stack
{
private:
    vector<int> vec;
public:
    bool isEmpty()
    {
        return vec.empty();
    }
    Stack();
    void push(int value);
    int top();
    void pop();
    void status();
};

Stack::Stack()
{
    vec.clear();
}

void Stack::push(int value)
{
    vec.push_back(value);
}

void Stack::pop()
{
    vec.pop_back();
}

int Stack::top()
{
    if(isEmpty())
    {
        cout << "Stack is empty!\n";
        
    }else
    {
        return vec.back();
    }
}

void Stack::status()
{
    for(int i = vec.size()-1; i >= 0; i--)
    {
        cout << vec[i] << endl;
    }
}

class Queue
{
private:
    deque<int> deq;
public:
    bool isEmpty()
    {
        return deq.size() == 0;
    } 
    void enQueue(int value);
    void deQueue();
    void status();
};



void Queue::enQueue(int value)
{
    deq.push_back(value);
}

void Queue::deQueue()
{
    deq.pop_front();
}

void Queue::status()
{
    for(int i = 0; i < deq.size(); i++)
    {
        cout << deq[i] << " ";
    }
cout << endl;
}


int main()
{
    cout << "stack: \n";
    Stack st;
    st.push(3);
    st.push(4);
    st.push(5);
    st.status();
    st.pop();
    cout << "----\n";
    st.status();
    cout << "Top: " << st.top() << endl;
    cout << "--------------\n\nQueue: \n";
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.deQueue();
    q.enQueue(5);
    q.deQueue();
    q.status();
    return 0;
}
