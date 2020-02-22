#ifndef MINERO_H
#define MINERO_H

    #include "./include.h"

    // for convenience
    using json = nlohmann::json;

    extern void help();

    extern bool endsWith(const std::string& str, const std::string& suffix);

    extern bool startsWith(const std::string& str, const std::string& prefix);

    extern bool difficulty_compute(std::string value, int difficulty=10, std::string magic_character="0");

    extern std::string compute_hash(std::string string_block, std::string secret_string="D3f4ult_s3cr3t-Str1nG", bool debug=false);

    extern bool is_valid_proof(std::string string_block, std::string hash_block, int difficulty=10, std::string magic_character="0");

    extern std::string mine(std::string string_block, std::string nonce_attribute="nonce", int difficulty=10, std::string magic_character="0", bool debug=false);

#endif // End of MINERO_H
