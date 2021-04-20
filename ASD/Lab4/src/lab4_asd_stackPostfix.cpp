#include <iostream>
#include <string>

using namespace std;

struct Node
{
    char ch;
    Node* next;
};

class Stack
{
private:
    int size;
    Node* head;
public:
    Stack();
    void push(char ch_);
    char pop();
    void display();
    bool isEmpty()
    {
        return size == 0;
    }
    char top()
    {
        return head->ch;
    }
};

Stack::Stack()
{
    size = 0;
    head = NULL;
}

void Stack::push(char ch_)
{
    Node* tempNode = new Node;
    tempNode->ch = ch_;
    if(head != NULL)
    {
        tempNode->next = head;
        head = tempNode;
        size++;
    }else
    {
        tempNode->next = NULL;
        head = tempNode;
        size++;
    }
}

char Stack::pop()
{
    char ch_;
    if(head != NULL)
    {
        if(size > 1)
        {
            ch_ = head->ch;
            Node* tempNode = head->next;
            delete head;
            head = tempNode;
            size--;
        }else
        {
            ch_ = head->ch;
            delete head;
            head = NULL;
            size--;
        }
        return ch_;
    }

    return 0;
}

void Stack::display()
{
    Node* tempNode = head;
    while(tempNode != NULL)
    {
        cout << tempNode->ch << endl;
        tempNode = tempNode->next;
    }
}


bool isOperand(char ch_)
{
    if(ch_ >= 'A' && ch_ <= 'Z' || ch_ >= 'a' && ch_ <= 'z') return true;

    return false;
}

bool isOperator(char ch_)
{
    if(ch_ == '+' || ch_ == '-' || ch_ == '/' || ch_ == '*') return true;

    return false;
}

int getPriority(char ch_)
{
    if(ch_ == '+' || ch_ == '-') return 1;
    if(ch_ == '*' || ch_ == '/') return 2;
    
    return -1;
}



string infxToPostfx(string infix)
{
    string postfix = "";
    Stack st;
    
    for(int i = 0; i < infix.length(); i++)
    {
        
        if(isOperator(infix[i]))
        {
            while(!st.isEmpty() && getPriority(infix[i]) <= getPriority(st.top()))
            {
                postfix += st.pop();
            }
            st.push(infix[i]);
        }
        else if(isOperand(infix[i]))
        {
            postfix += infix[i];
        }
        else if(infix[i] == '(')
        {
            st.push(infix[i]);
        }
        else if(infix[i] == ')')
        {
            while(!st.isEmpty() && st.top() != '(')
            {
                postfix += st.pop();
            }
            st.pop(); 
        }
        


    }
    while(!st.isEmpty())
    {
        postfix += st.pop();
    }
    
    st.display();
    return postfix;
}

int main()
{
    cout << infxToPostfx("(A-B-C)/D-E*F") << endl;
    cout << infxToPostfx("(A+B)*C-(D+E)/F") << endl;
    cout << infxToPostfx("A/(B-C)+D*(E-F)") << endl;
    cout << infxToPostfx("(A*B+C)/D-F/E") << endl;


    return 0;
}
