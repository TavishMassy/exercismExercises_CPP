#pragma once
#include <stack>
#include <memory>

namespace binary_search_tree {

// TODO: add your solution here
template <typename T>
class binary_tree{
private:
    std::unique_ptr<binary_tree<T>> left_;
    T data_;
    std::unique_ptr<binary_tree<T>> right_;

public:
    binary_tree(const T& data) : data_(data) {}

    const T& data() {
        return this->data_;
    }

    const std::unique_ptr<binary_tree<T>>& left() const {
        return left_;
    }

    const std::unique_ptr<binary_tree<T>>& right() const {
        return right_;
    }

    void insert(const T& val) {
        if (val <= data_) {
            if (left_) {
                left_->insert(val);
            } else {
                left_ = std::make_unique<binary_tree<T>>(val);
            }
        } else {
            if (right_) {
                right_->insert(val);
            } else {
                right_ = std::make_unique<binary_tree<T>>(val);
            }
        }
    }
    class iterator {
    private:
        std::stack<binary_tree<T>*> stack_;

        void push_left(binary_tree<T>* node) {
            while (node != nullptr) {
                stack_.push(node);
                node = node->left_.get();
            }
        }

    public:
        explicit iterator(binary_tree<T>* root = nullptr) {
            push_left(root);
        }

        T& operator*() {
            return stack_.top()->data_;
        }

        iterator& operator++() {
            if (stack_.empty()) return *this;
            
            binary_tree<T>* node = stack_.top();
            stack_.pop();
            
            if (node->right_) {
                push_left(node->right_.get());
            }
            
            return *this;
        }

        bool operator!=(const iterator& other) const {
            if (stack_.empty() && other.stack_.empty()) return false;
            if (stack_.empty() || other.stack_.empty()) return true;
            return stack_.top() != other.stack_.top();
        }
    };

    iterator begin() {
        return iterator(this);
    }

    iterator end() {
        return iterator(nullptr);
    }

};

}  // namespace binary_search_tree
