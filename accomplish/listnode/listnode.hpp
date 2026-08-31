#pragma once
template<typename T>
struct ListNode
{
    T val;
    ListNode* next;
    ListNode(T value):val(value),next(nullptr){}
};