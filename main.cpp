#include <iostream>
#include "sha256.h"
#include "Blockchain.h"
#include <ctime>
#include <unistd.h>
#include <algorithm>
#include <chrono>
#include <sstream>
#include <random>
#include "effolkronium/random.hpp"

using std::string;
using std::cout;
using std::endl;
using Random = effolkronium::random_static;

/* Functions */
string gen_random_str(const int length) {
    auto randchar = []() -> char
    {
        const char charset[] =
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ Random::get(1,999999999) % max_index ];
    };
    string str(length,0);
    generate_n( str.begin(), length, randchar );
    return str;

}

/* end functions */


int main(int argc, char *argv[])
{
    //blockchain init
    Blockchain bChain = Blockchain();

    //nb Blocks
    int nbBlocks =10;

    int i = 1;
    while (i<=nbBlocks)
    {

        /* block init */
        string r = gen_random_str(5);
        string rr = sha256(gen_random_str(5));
        cout << "sha256('"<< r << "'):" << rr << endl;

        cout << "Mining block "<<i<< "…" << endl;
        auto begin = chrono::steady_clock::now();
        bChain.AddBlock(Block(i, rr));
        auto end = chrono::steady_clock::now();
        cout << "operation time = " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() << "[s]" << std::endl;
        i++;
    }


    return 0;
}

