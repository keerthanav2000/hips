#ifndef STATISTICS_H
#define STATISTICS_H

#include <cstdint>
#include "llama.h"

class Statistics {
public:
    static float logSumExp(const float* logits, int32_t n_vocab);
    static float* softmax(float* logits, const llama_model* model);
    static float calculateEntropy(const float* probabilities, int32_t n_vocab);
};

#endif
