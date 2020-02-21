#include "./include/sha256/sha256.h"
#include "./include/minero.h"

int NONCE=0;
bool PROOF_STATUS;
std::string HASH;
std::string COMPUTED_HASH;

int main() {
    return 0;
}

/**
 * difficulty_compute decide the appropriate difficulty in a hash
 */ 
bool difficulty_compute(std::string value, int difficulty)
{
    // if (
    //         (
    //                 ("b" in value or "a" in value or "r" in value or "o" in value or "n" in value)
    //         )
    //         and
    //         (
    //                 # ( "b" in value and "8" in value and "d" in value and "p" in value ) or
    //                 # ( "a" in value and "4" in value ) or
    //                 # ( "r" in value and "n" in value ) or
    //                 # ( "o" in value and "0" in value and "k" in value and "d" in value ) or
    //                 # ( "n" in value and "3" in value and "e" in value and "a" in value and "4" in value ) or

    //                 all(x in value for x in self.hash_must_contain3_prime)
    //                 # all(x in value for x in self.or1_hash_must_contain3_prime) or
    //                 # all(x in value for x in self.or2_hash_must_contain3_prime) or
    //                 # all(x in value for x in self.or3_hash_must_contain3_prime) or
    //                 # all(x in value for x in self.or4_hash_must_contain3_prime) or
    //                 # all(x in value for x in self.or5_hash_must_contain3_prime) or
    //                 # all(x in value for x in self.or6_hash_must_contain3_prime) or
    //                 # all(x in value for x in self.or7_hash_must_contain3_prime) or
    //                 # all(x in value for x in self.or8_hash_must_contain3_prime) or
    //                 # all(x in value for x in self.or9_hash_must_contain3_prime)
    //         ) and
    //         (
    //                 value.startswith(self.START_CARACTER_DIFFICULTY * self.START_DIFFICULTY_OCCURENCE)
    //                 # and value.endswith(self.END_CARACTER_DIFFICULTY * self.END_DIFFICULTY_OCCURENCE)
    //         )
    // ):
    //     return True
    // else:
    //     return False
    return true;
 }


/**
 * proof_of_work is the loop who try to generate the appropriate nonce for a valid hash from
 * difficulty and the string of the block
 * - string_block : the json_string of the block you want to hash
 * - hash_block : the hash of the block we want to check
 */ 
std::string proof_of_work(std::string string_block, std::string nonce_attribute, int difficulty, bool debug)
{
    COMPUTED_HASH = compute_hash(string_block);
    if (debug)
    {
        std::cout << "[+] <-------------------------------------------------" << std::endl;
        std::cout << "[+] <> proof_of_work \n[+] -> string_block: " << string_block << std::endl;
        std::cout << "[+] -> difficulty: " << difficulty << std::endl;
    }
    
    auto string_block_to_get = json::parse(string_block);
    std::string new_string_block = "";
    while (!difficulty_compute(COMPUTED_HASH, difficulty)) // in this loop we just check the validation of the computed hash
    {
        // We incremented the nonce
        NONCE += 1;
        
        // We change the value in the json by the new nonce incremented
        string_block_to_get[nonce_attribute] = NONCE;
        
        // We tranform the json to json_string
        new_string_block = string_block_to_get.dump();

        // We generate the computed-hash      
        COMPUTED_HASH = compute_hash(new_string_block);

        if (debug)
        {
            std::cout << "[+] -> COMPUTED_HASH: " << COMPUTED_HASH << std::endl;
        }
    }

    return COMPUTED_HASH;
}

/**
 * is_valid_proof will validate the hash of a block from a specific difficulty
 * - string_block : the string of the block you want to hash
 * - hash_block : the hash of the block we want to check
 * - difficulty :  the difficulty on the hashing process
 * - debug : The debug parameter to print what's going on
 */
bool is_valid_proof(std::string string_block, std::string hash_block, int difficulty, bool debug)
{
    PROOF_STATUS = (difficulty_compute(hash_block, difficulty) && hash_block == compute_hash(string_block));
    if (debug)
    {
        std::cout << "[+] <-------------------------------------------------" << std::endl;
        std::cout << "[+] <> is_valid_proof \n[+] -> string_block: " << string_block << std::endl;
        std::cout << "[+] -> hash_block: " << hash_block << std::endl;
        std::cout << "[+] -> difficulty: " << difficulty << std::endl;
        std::cout << "[+] -> PROOF_STATUS: " << PROOF_STATUS << std::endl;
    }
    return PROOF_STATUS;
}

/**
 * compute_hash A function that return the hash of the block contents.
 * - string_block : the string of the block you want to hash
 * - secret_string : the secret string, you will pass each time to generate your personnalize hash
 * - debug : The debug parameter to print what's going on
 */ 
std::string compute_hash(std::string string_block, std::string secret_string, bool debug)
{
    // THis variable HASH have been declared in ./include/minero.h
    HASH = hash_sha256(string_block + "-" + secret_string);
    if (debug)
    {
        std::cout << "[+] <--------------------------------------------------" << std::endl;
        std::cout << "[+] <> compute_hash \n[+] -> HASH: " << HASH << std::endl;
    }
    return HASH;
}
