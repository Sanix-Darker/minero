#ifndef MINERO_H
#define MINERO_H

#include <iostream>

std::string HASH;

void hello();
std::string compute_hash(std::string string_block, std::string secret_string="D3f4ult_s3cr3t-Str1nG", bool debug=false);
bool is_valid_proof(std::string string_block, std::string hash_block, int difficulty=10);

#endif // End of MINERO_H
