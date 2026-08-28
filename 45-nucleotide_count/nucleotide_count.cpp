#include "nucleotide_count.h"

namespace nucleotide_count {

// TODO: add your solution here
std::map<char, int> count(std::string sequence) {
    std::map<char, int> gene_count{{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};
    for (char c : sequence) {
        c = toupper(c);
        if (gene_count.find(c) != gene_count.end()) {
            ++gene_count[c];
        } else {
            throw std::invalid_argument("");
        }
    }
    return gene_count;
}

}  // namespace nucleotide_count
