#include "HuffmanCoding.h"

HuffmanCoding::HuffmanCoding() { }

HuffmanCoding::~HuffmanCoding() {
    // Run delete until Huffman tree is empty
    while(!huffmanTree.empty()) {
        HuffmanNode* huffmanNode = huffmanTree.top();
        huffmanTree.pop();
        deleteHuffmanNode(huffmanNode);
    }
}

void HuffmanCoding::deleteHuffmanNode(HuffmanNode *huffmanNode) {
    if (huffmanNode == nullptr) {
        return;
    }
    deleteHuffmanNode(huffmanNode->left);
    deleteHuffmanNode(huffmanNode->right);
    delete huffmanNode;
}

void HuffmanCoding::buildHuffmanTree(const std::vector<std::pair<llama_token, float>>& tokenProbabilities) {
    for (const auto& [token, probability] : tokenProbabilities) {
        auto huffmanNode = new HuffmanNode(token, (double)probability, nullptr, nullptr);
        huffmanTree.push(huffmanNode);
    }
}

void HuffmanCoding::mergeHuffmanNodes() {
    while (huffmanTree.size() > 1) {
        HuffmanNode* left = huffmanTree.top();
        huffmanTree.pop();

        HuffmanNode* right = huffmanTree.top();
        huffmanTree.pop();

        auto mergedHuffmanNode = new HuffmanNode(-1, left->probability + right->probability, left, right);
        huffmanTree.push(mergedHuffmanNode);
    }
}

HuffmanNode* HuffmanCoding::generateHuffmanCodes() {
    if (huffmanTree.empty()) return nullptr;
    HuffmanNode* root = huffmanTree.top();
    huffmanTree.pop();
    std::vector<bool> currentHuffmanCode;
    generateHuffmanCodesRecursively(root, currentHuffmanCode);
    return root;
}

void HuffmanCoding::generateHuffmanCodesRecursively(HuffmanNode* currentHuffmanNode, std::vector<bool> currentHuffmanCode) {
    if (currentHuffmanNode == nullptr) {
        return;
    }
    if (currentHuffmanNode->token != -1) {
        huffmanCodes[currentHuffmanNode->token] = currentHuffmanCode;
        return;
    }
    currentHuffmanCode.push_back(false);
    generateHuffmanCodesRecursively(currentHuffmanNode->left, currentHuffmanCode);
    currentHuffmanCode.pop_back();

    currentHuffmanCode.push_back(true);
    generateHuffmanCodesRecursively(currentHuffmanNode->right, currentHuffmanCode);
    currentHuffmanCode.pop_back();
}
