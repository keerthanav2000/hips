package org.vonderheidt.hips.utils

import org.vonderheidt.hips.data.Settings

object Huffman {
    private var lastInverseHuffmanCodes: MutableMap<String, Char>? = null

    fun getLastInverseHuffmanCodes(): MutableMap<String, Char> {
        return lastInverseHuffmanCodes!!
    }

    fun compress(preparedSecretMessage: String): ByteArray {
        val huffmanCoding = HuffmanCoding<Char, Int>()
        val charFrequencies = huffmanCoding.countCharFrequencies(preparedSecretMessage)
        huffmanCoding.buildHuffmanTree(charFrequencies)
        huffmanCoding.mergeHuffmanNodes()
        huffmanCoding.generateHuffmanCodes()
        lastInverseHuffmanCodes = huffmanCoding.inverseHuffmanCodes
        val plainBitString = huffmanCoding.compress(preparedSecretMessage)
        return Format.asByteArrayWithPadding(plainBitString)
    }

    fun decompress(paddedPlainBits: ByteArray, inverseHuffmanCodes: MutableMap<String, Char>): String {
        val plainBitString = Format.asBitStringWithoutPadding(paddedPlainBits)
        val huffmanCoding = HuffmanCoding<Char, Int>()
        huffmanCoding.inverseHuffmanCodes = inverseHuffmanCodes
        return huffmanCoding.decompress(plainBitString)
    }

    external fun encode(context: String, cipherBits: ByteArray, bitsPerToken: Int = Settings.bitsPerToken, seed: Int = 0, ctx: Long = LlamaCpp.getCtx()): String
    external fun decode(context: String, coverText: String, bitsPerToken: Int = Settings.bitsPerToken, seed: Int = 0, ctx: Long = LlamaCpp.getCtx()): ByteArray
}
