#ifndef HUFFMAN_CODING_H
#define HUFFMAN_CODING_H

#include <queue>
#include <unordered_map>
#include <vector>
#include "HuffmanNode.h"

struct Compare {
    bool operator()(HuffmanNode* left, HuffmanNode* right) {
        return left->probability < right->probability;
    }
};

class HuffmanCoding {
private:
    std::priority_queue<HuffmanNode*, std::vector<HuffmanNode*>, Compare> huffmanTree;
    void generateHuffmanCodesRecursively(HuffmanNode* currentHuffmanNode, std::vector<bool> currentHuffmanCode);

public:
    std::unordered_map<llama_token, std::vector<bool>> huffmanCodes;
    HuffmanCoding();
    ~HuffmanCoding();
    void buildHuffmanTree(const std::vector<std::pair<llama_token, float>>& tokenProbabilities);
    void mergeHuffmanNodes();
    HuffmanNode* generateHuffmanCodes();
};

#endif
