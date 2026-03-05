package org.vonderheidt.hips.utils

import org.vonderheidt.hips.data.Settings

object Arithmetic {
    fun compress(preparedSecretMessage: String): ByteArray {
        return decode(context = "", coverText = preparedSecretMessage, temperature = 1.0f, topK = LlamaCpp.getVocabSize(), precision = 40, seed = 0)
    }

    fun decompress(paddedPlainBits: ByteArray): String {
        return encode(context = "", cipherBits = paddedPlainBits, temperature = 1.0f, topK = LlamaCpp.getVocabSize(), precision = 40, seed = 0)
    }

    external fun encode(context: String, cipherBits: ByteArray, temperature: Float = Settings.temperature, topK: Int = Settings.topK, precision: Int = Settings.precision, seed: Int = 0, ctx: Long = LlamaCpp.getCtx()): String
    external fun decode(context: String, coverText: String, temperature: Float = Settings.temperature, topK: Int = Settings.topK, precision: Int = Settings.precision, seed: Int = 0, ctx: Long = LlamaCpp.getCtx()): ByteArray
}
