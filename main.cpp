#include <iostream>
#include "sha256.h"
#include "Blockchain.h"
#include <ctime>
#include <unistd.h>
#include <algorithm>
#include <chrono>

using std::string;
using std::cout;
using std::endl;

string gen_random_str(const int length) {
    auto randchar = []() -> char
    {
        const char charset[] =
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    string str(length,0);
    generate_n( str.begin(), length, randchar );
    return str;

}

int main(int argc, char *argv[])
{
    int k = rand()%1;
    Blockchain bChain = Blockchain();
    int nbBlocks =3;
    int i = 1;
    while (i<=nbBlocks)
    {

        /* block init */
        string r = gen_random_str(5);
        string rr = sha256(gen_random_str(5));
        cout << "sha256('"<< r << "'):" << rr << endl;

        cout << "Mining block "<<i<< "…" << endl;
        chrono::steady_clock::time_point begin = chrono::steady_clock::now();
        bChain.AddBlock(Block(i, rr));
        chrono::steady_clock::time_point end = chrono::steady_clock::now();
        cout << "operation time = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
        i++;
    }


    return 0;
}

