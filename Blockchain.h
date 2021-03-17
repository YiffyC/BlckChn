//
// Created by lxdie on 17/03/2021.
//

#ifndef BLCKCHN_BLOCKCHAIN_H
#define BLCKCHN_BLOCKCHAIN_H
#include <cstdint>
#include <vector>
#include "Block.h"
using namespace std;
#endif //BLCKCHN_BLOCKCHAIN_H

class Blockchain
{
    public:
        Blockchain();
        void AddBlock(Block bNew);

    private:
        uint32_t _nDifficulty;
        vector<Block> _vChain;
        Block _GetLastBlock() const;
};
