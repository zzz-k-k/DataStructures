#include<stack>
#include<iostream>


int main()
{
    std::stack<int> stack;
    stack.push(1);
    std::cout<<stack.top()<<std::endl;
    stack.pop();
    int size=stack.size();
    bool empty=stack.empty();
    return 0;
}