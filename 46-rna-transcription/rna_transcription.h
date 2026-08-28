#pragma once
#include <map>
#include <string>

namespace rna_transcription {

// TODO: add your solution here
inline const std::map<char, char> conversion_map{{'G','C'}, {'C','G'}, {'T','A'}, {'A','U'}};

char to_rna(char allele);
std::string to_rna(std::string sequence);

}  // namespace rna_transcription
