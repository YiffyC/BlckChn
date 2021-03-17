#include <iostream>
#include "sha256.h"
#include "Blockchain.h"
#include <ctime>
#include <unistd.h>
#include <algorithm>

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
    string r = gen_random_str(5);;
    string rr = sha256(gen_random_str(5));
    string s = gen_random_str(5);
    string ss = sha256(gen_random_str(5));
    string t = gen_random_str(5);
    string tt = sha256(t);




    cout << "sha256('"<< r << "'):" << rr << endl;
    cout << "sha256('"<< s << "'):" << ss << endl;
    cout << "sha256('"<< t << "'):" << tt << endl;



    Blockchain bChain = Blockchain();

    cout << "Mining block 1…" << endl;
    bChain.AddBlock(Block(1, rr));

    cout << "Mining block 2…" << endl;
    bChain.AddBlock(Block(2, ss));

    cout << "Mining block 3…" << endl;
    bChain.AddBlock(Block(3, tt));


    return 0;
}

