#include"listnode.hpp"

template<typename T>
class linkedListStack
{
private:
    ListNode<T> *stackTop;

public:
    linkedListStack()
    {
        stackTop=nullptr;
    }
    void push(T value)
    {
        ListNode<T> *stackSecond = new ListNode<T>(value);
        stackSecond->next=stackTop;
        stackSecond->val=value;
        stackTop=stackSecond;
    }
    void pop()
    {
        if(stackTop==nullptr)
        {
            ListNode<T>* oldTop = stackTop;
            stackTop=stackTop->next;
            delete oldTop;
        }
    }
    T peek()
    {
        return stackTop->val;
    }

};