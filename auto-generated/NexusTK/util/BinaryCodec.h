// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HQ
// Source by-file doc: by-file/BinaryCodec.md
// UID:00004F | by-class/Encoder.md | Completion:94 | Confidence:93
#pragma once

class Encoder
{
public:
    Encoder();
    virtual ~Encoder();

    void SetByteOrder(bool useBigEndian);
    void WriteByte(unsigned char value);
    void WriteShort(unsigned short value);
    void WriteTriByte(unsigned int value);
    void WriteInt(unsigned int value);
    void WriteWideString8(const wchar_t *text, int charCount = -1);
    void WriteWideString16(const wchar_t *text, int charCount = -1);
    void WriteAnsiString8(const wchar_t *text, int charCount = -1);
    void WriteAnsiString16(const wchar_t *text, int charCount = -1);
    void WriteCString(const wchar_t *text, int charCount = -1);
    void WriteBytes(const void *data, int byteCount);
    void WriteCompressedBytes(const void *data, int byteCount);
    void SkipBytes(int byteCount);
    void Initialize(unsigned char *buffer, int capacity);
    bool Finalize(unsigned int *outBytesWritten);
    virtual void NoopVirtual();

private:
    unsigned char *m_outputBuffer;
    int m_capacity;
    int m_writePos;
    bool m_useBigEndian;
    bool m_isWritable;
};

typedef char EncoderSizeMustBe20[(sizeof(Encoder) == 20) ? 1 : -1];

// UID:00003M | by-class/Decoder.md | Completion:94 | Confidence:93
class Decoder
{
public:
    Decoder();
    virtual ~Decoder();

    void SetByteOrder(bool useBigEndian);
    unsigned char ReadByte();
    unsigned short ReadShort();
    unsigned int ReadTriByte();
    unsigned int ReadInt();
    void ReadWideString8(wchar_t *out, int capacityChars, int *outChars);
    void ReadWideString16(wchar_t *out, int capacityChars, int *outChars);
    void ReadAnsiString8(wchar_t *out, int capacityChars, int *outChars);
    void ReadAnsiString16(wchar_t *out, int capacityChars, int *outChars);
    void ReadCString(wchar_t *out, int capacityChars, int *outChars);
    void ReadBytes(void *out, int byteCount);
    void ReadCompressedBytes(
        void *out,
        unsigned int outCapacity,
        unsigned int *outBytes);
    void SkipBytes(int byteCount);
    void Initialize(const unsigned char *buffer, int size);
    bool Finalize();
    virtual void NoopVirtual();

private:
    const unsigned char *m_inputBuffer;
    int m_inputSize;
    int m_readPos;
    bool m_useBigEndian;
    bool m_isValid;
};

typedef char DecoderSizeMustBe20[(sizeof(Decoder) == 20) ? 1 : -1];
