#ifndef LLAMACPP_H
#define LLAMACPP_H

#include <jni.h>
#include <vector>
#include <string>
#include "llama.h"
#include "common.h"

class LlamaCpp {
public:
    static std::string detokenize(const llama_tokens& tokens, const llama_context* ctx);
    static jstring detokenize(JNIEnv* env, const llama_tokens& tokens, const llama_context* ctx);
    static bool isSpecial(llama_token token, const llama_model* model);
    static bool isEndOfGeneration(llama_token token, const llama_model* model);
    static void suppressSpecialTokens(float* probabilities, const llama_model* model);
    static void suppressSpecialTokensLogits(float* logits, const llama_model* model);
    static bool isEndOfSentence(llama_token token, const llama_context* ctx);
    static llama_token getEndOfGeneration(const llama_model* model);
    static llama_token getAsciiNul(const llama_model* model, const llama_context* ctx);
    static int32_t getVocabSize(const llama_model* model);
    static llama_tokens tokenize(JNIEnv* env, jstring jString, const llama_context* ctx);
    static float* getLogits(const llama_tokens& tokens, llama_context* ctx);
};

#endif
