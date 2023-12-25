#pragma once
#include <iostream>

template <typename T>
class Stack {
private:
    T* array;
    int capacity; // Вместимость стека
protected:
    int top;
public:
    Stack();
    ~Stack();

    void push(const T& item);
    T pop();
    Stack<T>& operator=(const Stack<T>& other);
    bool operator<(const Stack<T>& other) const;
    bool operator==(const Stack<T>& other) const;
    T& operator[](int index);

    bool empty() {
        return false;
    }

    int size() {
        return 0;
    }
};