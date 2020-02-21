#include "./include/sha256/sha256.h"
#include "./include/minero.h"

void hello() {

    std::string message = "hello world";
    std::cout << hash_sha256(message) << std::endl;
}

int main() {
    hello();
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
 */ 
std::string proof_of_work(std::string string_block, int difficulty)
{
    // block.nonce = 0
    // # gradual_nonce = block.nonce
    // # reverse_nonce_desc = 99999999999999999999999999999999999999999999999999999999999999
    // computed_hash = block.compute_hash()
    // while not self.difficulty_compute(computed_hash):
    //     block.nonce += 1
    //     computed_hash = block.compute_hash()
    //     print(block.nonce, computed_hash)
    //     # if not self.difficulty_compute(computed_hash):
    //     #     gradual_nonce = block.nonce
    //     #     reverse_nonce_desc -= 1
    //     #     block.nonce = reverse_nonce_desc
    //     #     computed_hash = block.compute_hash()
    //     #     print("Nonce Tested:", block.nonce)
    //     #     print("Hash generated:", computed_hash)
    //     #     if not self.difficulty_compute(computed_hash):
    //     #         block.nonce = gradual_nonce
    // return computed_hash

    return "";
}

/**
 * is_valid_proof will validate the hash of a block from a specific difficulty
 */
bool is_valid_proof(std::string string_block, std::string hash_block, int difficulty)
{
    // return self.difficulty_compute(block_hash) and block_hash == block.compute_hash()
    return true;
}

/**
 * compute_hash A function that return the hash of the block contents.
 * - string_block : the string of the block you want to hash
 * - secret_string
 */ 
std::string compute_hash(std::string string_block, std::string secret_string="D3f4ult_s3cr3t-Str1nG")
{
    return "";
}

