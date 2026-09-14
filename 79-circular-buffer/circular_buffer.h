#pragma once
#include <memory>
#include <stdexcept>

namespace circular_buffer {

// TODO: add your solution here
template <typename T>
struct node {
    T value;
    node<T>* next;
};

template <typename T>
class circular_buffer {
private:
    node<T>* _head = nullptr;
    node<T>* _reader = nullptr;
    int _size;
    int _occupied{0};
public: 
    circular_buffer(int size) : _size(size) {
        if (size < 1) {
            throw std::domain_error("INVALID: Size less than 1.");
        }
        _head = new node<T>{T{}, nullptr};
        node<T>* curr = _head;
        for (int i{1}; i < size; ++i) {
            curr->next = new node<T>{T{}, nullptr};
            curr = curr->next;
        }
        curr->next = _head;
        _head = _head;
        _reader = _head;
    }

    T read() {
        if (_occupied == 0) {
            throw std::domain_error("ERROR: Reading empty buffer.");
        }
        --_occupied;
        T value{_reader->value};
        _reader = _reader->next;
        return value;
    }

    void write(T value) {
        if (_occupied >= _size) {
            throw std::domain_error("ERROR: Out of range.");
        }
        ++_occupied;
        _head->value = value;
        _head = _head->next; 
    }

    void overwrite(T value) {
        _head->value = value;
        if (_occupied < _size) {
            ++_occupied;
        }
        if (_head->next != nullptr) {
            _head = _head->next; 
            _reader = _head;
        } 
    }

    void clear() {
        while (_occupied != 0) {
            _head->value = T{};
            _head = _head->next;
            --_occupied;
        }
        _reader = _head;
    }
};

}  // namespace circular_buffer
