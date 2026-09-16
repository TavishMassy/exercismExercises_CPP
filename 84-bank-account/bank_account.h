#pragma once
#include <mutex>
#include <stdexcept>

namespace Bankaccount {
class Bankaccount {
private:
    int _balance{0};
    bool _is_open{false};
    mutable std::mutex account_mutex;

public:
    Bankaccount() {}

    void open() {
        std::lock_guard<std::mutex> lock(account_mutex);
        if (!_is_open) {
            _is_open = true;
            return;
        }
        throw std::runtime_error("ERROR: Account alresdy opened.");
    }

    void close() {
        std::lock_guard<std::mutex> lock(account_mutex);
        if (_is_open) {
            _balance = 0;
            _is_open = false;
            return;
        }
        throw std::runtime_error("ERROR: Account already closed.");
    }

    int balance() {
        std::lock_guard<std::mutex> lock(account_mutex);
        if (_is_open) {
            return _balance;
        }
        throw std::runtime_error("ERROR: Account closed.");
    }

    void deposit(int amount) {
        std::lock_guard<std::mutex> lock(account_mutex);
        if (_is_open) {
            if (amount > 0) {
                _balance += amount;
                return;
            }
            throw std::runtime_error("ERROR: Cannot deposit negative.");
        }
        throw std::runtime_error("ERROR: Account closed.");
    }

    void withdraw(int amount) {
        std::lock_guard<std::mutex> lock(account_mutex);
        if (_is_open) {
            if (amount <= _balance) {
                if (amount > 0) {
                    _balance -= amount;
                    return;
                }
                throw std::runtime_error("ERROR: Cannot withdraw negative.");
            }
            throw std::runtime_error("ERROR: Cannot withdraw more than deposited.");
        }
        throw std::runtime_error("ERROR: Account closed.");
    }

};  // class Bankaccount

}  // namespace Bankaccount
