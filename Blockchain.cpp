#include "Blockchain.h"

Blockchain::Blockchain()
{

    _vChain.emplace_back(Block(0, "Genesis Block"));

    _nDifficulty = 5;

}




void Blockchain::AddBlock(Block bNew) {
    bNew.sPrevHash = _GetLastBlock().GetHash();
    bNew.MineBlock(_nDifficulty);
    _vChain.push_back(bNew);
}

void Blockchain::AddBlockOnly(Block bNew) {
    bNew.sPrevHash = _GetLastBlock().GetHash();
    _vChain.push_back(bNew);
}
void Blockchain::MineBlock (Block bNew)
{
    bNew.MineBlock(_nDifficulty);
}

Block Blockchain::_GetLastBlock() const {

    return _vChain.back();
}

void Blockchain::display_bckchn(int i)
{
    cout << "Block hash : " << _vChain.back().GetHash() << "\n";
}

Block Blockchain::getBlock(int position)
{
    return _vChain.at(position);
}

