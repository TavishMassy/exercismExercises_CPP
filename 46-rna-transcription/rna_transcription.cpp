#include "rna_transcription.h"

namespace rna_transcription {

// TODO: add your solution here

char to_rna(char allele) {
    if (conversion_map.find(allele) != conversion_map.end()) {
        allele = conversion_map.at(allele);
    }
    return allele;
}

std::string to_rna(std::string sequence) {
    for (char &c : sequence) {
        c = toupper(c);
        if (conversion_map.find(c) != conversion_map.end()) {
            c = conversion_map.at(c);
        }
    }
    return sequence;
}

}  // namespace rna_transcription
