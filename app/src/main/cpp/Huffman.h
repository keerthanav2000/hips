#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <jni.h>
#include <vector>
#include "llama.h"

/**
 * Class that represents steganography using Huffman encoding.
 */
class Huffman {
public:
    /**
     * Function to get the top 2^bitsPerToken probabilities for the last token of the prompt. 
     * Keeps track of the corresponding token IDs in a vector.
     *
     * @param probabilities Probabilities for the last token of the prompt.
     * @param bitsPerToken Number of bits to encode/decode per cover text token.
     * @param model Memory address of the LLM.
     * @return Vector of top probabilities and the corresponding token IDs.
     */
    static std::vector<std::pair<llama_token, float>> getTopProbabilities(float* probabilities, jint bitsPerToken, const llama_model* model);
};

#endif
