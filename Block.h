//
// Created by lxdie on 17/03/2021.
//

#ifndef BLCKCHN_BLOCK_H
#define BLCKCHN_BLOCK_H
#include <cstdint>
#include <iostream>
using namespace std;
#endif //BLCKCHN_BLOCK_H


class Block
{
public:
    string sPrevHash;
    Block(uint32_t nIndexIn, const string &sDataIn);
    string GetHash();
    void MineBlock(uint32_t nDifficulty);

private:
    uint32_t _nIndex;
    int64_t _nNonce;
    string _sData;
    string _sHash;
    time_t _tTime;
    string _CalculateHash() const;
};
