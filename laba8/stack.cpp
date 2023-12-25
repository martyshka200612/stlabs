#include "stack.h"
#include <stdexcept>

template <typename T>
Stack<T>::Stack() {
    capacity = 10;
    array = new T[capacity];
    top = -1;
}

template <typename T>
Stack<T>::~Stack() {
    delete[] array;
}

template <typename T>
void Stack<T>::push(const T& item) {
    if (top == capacity - 1) {
        // Расширение массива при достижении предела
        T* newArray = new T[2 * capacity];
        for (int i = 0; i < capacity; ++i) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        capacity *= 2;
    }
    array[++top] = item;
}

template <typename T>
T Stack<T>::pop() {
    if (top == -1) {
        throw std::out_of_range("Stack is empty");
    }
    return array[top--];
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other) {
    if (this != &other) {
        delete[] array;
        capacity = other.capacity;
        array = new T[capacity];
        top = other.top;
        for (int i = 0; i <= top; ++i) {
            array[i] = other.array[i];
        }
    }
    return *this;
}

template <typename T>
bool Stack<T>::operator<(const Stack<T>& other) const {
    return top < other.top;
}

template <typename T>
bool Stack<T>::operator==(const Stack<T>& other) const {
    if (top != other.top) {
        return false;
    }
    for (int i = 0; i <= top; ++i) {
        if (array[i] != other.array[i]) {
            return false;
        }
    }
    return true;
}

template <typename T>
T& Stack<T>::operator[](int index) {
    if (index < 0 || index > top) {
        throw std::out_of_range("Index out of range");
    }
    return array[index];
}

template class Stack<int>;