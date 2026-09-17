#pragma once

namespace linked_list {

// TODO: add your solution here
template <typename T>
struct Node {
    Node<T>* previous;
    T element;
    Node<T>* next;
};

template <typename T>
class List {
private:
    Node<T>* _head{nullptr};
    Node<T>* _tail{nullptr};
    int _size{0};

public:
    List() {}
    void push(T element) {
        Node<T>* new_node = new Node<T>{_tail, element, nullptr};
        ++_size;
        if (_tail == nullptr) {
            _head = new_node;
            _tail = _head;
        } else {
            _tail->next = new_node;
            new_node->previous = _tail;
            _tail = new_node;
        }
    }

    T pop() {
        T element;
        if (_tail != nullptr) {
            element = _tail->element;
            if (_tail->previous != nullptr) {
                _tail = _tail->previous;    
                delete _tail->next;
                _tail->next = nullptr;
            } else {
                delete _tail;
                _head = nullptr;
                _tail = nullptr;
            }
            --_size;
        } 
        return element;
    }

    T shift() {
        T element;
        if (_head != nullptr) {
            element = _head->element;
            if (_head->next != nullptr) {
                _head = _head->next;    
                delete _head->previous;
                _head->previous = nullptr;
            } else {
                delete _head;
                _head = nullptr;
                _tail = nullptr;
            }
            --_size;
        } 
        return element;
    }

    void unshift(T element) {
        Node<T>* new_node = new Node<T>{_tail, element, nullptr};
        ++_size;
        if (_head == nullptr) {
            _head = new_node;
            _tail = _head;
        } else {
            _head->previous = new_node;
            new_node->next = _head;
            _head = new_node;
        }
    }
    
    int count() {
        return _size;
    }

    void erase(T element) {
        if (_head == nullptr) {
            return;
        }
        Node<T>* ptr = _head;
        while (ptr != nullptr) {
            if (ptr->element != element) {
                ptr = ptr->next;
                continue;
            }
            if (ptr->previous != nullptr) {
                (ptr->previous)->next = ptr->next;
            } else {
                _head = ptr->next;                
            } 
            if (ptr->next != nullptr) {
                (ptr->next)->previous = ptr->previous;
            } else {
                _tail = ptr->previous;
            }
            delete ptr;
            --_size;
            return;
        }
    }

};

}  // namespace linked_list
