#include "sublist.h"

namespace sublist {

// TODO: add your solution here
List_comparison sublist(std::vector<int> list_a, std::vector<int> list_b) {
    std::vector<int> A;
    std::vector<int> B;
    auto _assign_A_B = [&A, &B, &list_a, &list_b]() {
        A = (list_a.size() >= list_b.size()) ? list_a : list_b;
        B = (list_a.size() >= list_b.size()) ? list_b : list_a;  
    };
    _assign_A_B();
    for (size_t i{0}; i < A.size(); ++i) {
        if (A.empty() || B.empty()) { break; }
        while (!A.empty() && !B.empty()) {         
            if (i < A.size() && A.at(i) == B.at(0)) {            
                A.erase(A.begin() + i);
                B.erase(B.begin());
            } else {
                _assign_A_B();
                break;
            }
        }
    }
    if (A.empty() && B.empty()) {
        return List_comparison::equal;
    } else if (!A.empty() && !B.empty()) {
        return List_comparison::unequal;
    } else if (list_a.size() < list_b.size()) {
        return List_comparison::sublist;
    } else {
        return List_comparison::superlist;
    }
}

}  // namespace sublist
