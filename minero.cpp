#include "./include/sha256/sha256.h"
#include "./include/minero.h"

int NONCE=0;
bool PROOF_STATUS;
std::string HASH;
std::string COMPUTED_HASH;

/**
 * Example of a Block :
 *   {
 *     "index": 1,
 *     "transactions": [
 *       {
 *         "from": "string",
 *         "to": "string",
 *         "type": "string",
 *         "content": "value",
 *         "timestamp": 1582301090.8854582,
 *         "tx_previous_hash": "99ae4e4b32f8b29fba5277e30180f3d75436b9756d1ec075f5aa5519aa15c9c0",
 *         "tx_nonce": 183
 *       },
 *       {
 *         "from": "string",
 *         "to": "string",
 *         "type": "string",
 *         "content": "qqvalue",
 *         "timestamp": 1582301834.1500485,
 *         "tx_previous_hash": "9cfd783ddabdb228bd70357446c49ed2b2d98df0cf5d315f4eb69eb5d3148f40",
 *         "tx_nonce": 20
 *       },
 *       .....
 *     ],
 *     "timestamp": 1582301860.202116,
 *     "previous_hash": "19de66af7e186f2eeba3598e625548366237b7a99389de89f06a641ecf319e7e",
 *     "nonce": 136557,
 *     "hash": "0000c486d8a306f6d51628266a85a8d8e20cf39ccd0f9f6e3aeb30718314c7d9"
 *   }
 */


std::string operator*(const std::string& str, size_t times)
{
    std::stringstream stream;
    for (size_t i = 0; i < times; i++) stream << str;
    return stream.str();
}


bool endsWith(const std::string& str, const std::string& suffix)
{
    return str.size() >= suffix.size() && 0 == str.compare(str.size()-suffix.size(), suffix.size(), suffix);
}

bool startsWith(const std::string& str, const std::string& prefix)
{
    return str.size() >= prefix.size() && 0 == str.compare(0, prefix.size(), prefix);
}

/**
 * difficulty_compute decide the appropriate difficulty in a hash
 */ 
bool difficulty_compute(std::string value, int difficulty)
{

    std::string magic_character = "0";
    std::string should_start_with = magic_character * difficulty;

    if (startsWith(value, should_start_with))
        return true;        
    // else
    //     std::cout << "Please Specify the 'difficulty' from 0 to +infini" << std::endl;

    return false;
 }


/**
 * mine is the loop who try to generate the appropriate nonce for a valid hash from
 * difficulty and the string of the block
 * - string_block : the json_string of the block you want to hash (shoud be have a nonce parameter)
 * - hash_block : the hash of the block we want to check
 */ 
std::string mine(std::string string_block, std::string nonce_attribute, int difficulty, bool debug)
{
    COMPUTED_HASH = compute_hash(string_block);
    auto string_block_to_get = json::parse(string_block);
    std::string new_string_block = "";

    if (debug)
    {
        std::cout << "[+] <-------------------------------------------------" << std::endl;
        std::cout << "[+] <> mine \n[+] -> string_block: " << string_block << std::endl;
        std::cout << "[+] -> difficulty: " << difficulty << std::endl;
    }
    
    while (!difficulty_compute(COMPUTED_HASH, difficulty)) // in this loop we just check the validation of the computed hash
    {
        // We incremented the nonce until we had a good nonce for a valid hash
        NONCE += 1;
        
        // We change the value in the json by the new nonce incremented
        string_block_to_get[nonce_attribute] = NONCE;
        
        // We tranform the json to json_string
        new_string_block = string_block_to_get.dump();

        // We generate the computed-hash      
        COMPUTED_HASH = compute_hash(new_string_block);

        if (debug)
        {
            std::cout << "[+] -> COMPUTED_HASH: " << COMPUTED_HASH << " | NONCE: " << NONCE << std::endl;
        }
    }

    std::string result = "{";
    result +=               "\"hash\" : \""+COMPUTED_HASH+"\",";
    result +=               "\"nonce\": "+std::to_string(NONCE);
    result +=           "}";

    return result;
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

void help()
{
    std::cout << "[+] <>----------------------------------------------" << std::endl;
    std::cout << "[+] Welcome to Minero, a customizable C++ miner for your Blockchain !" << std::endl;
    std::cout << "[+] By S4nix-darker !" << std::endl;
    std::cout << "[+] <>----------------------------------------------" << std::endl;

}

int main() {

    help();
    return 0;
}
