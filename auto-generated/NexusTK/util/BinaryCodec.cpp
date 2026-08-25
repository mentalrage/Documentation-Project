// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HQ
// Source by-file doc: by-file/BinaryCodec.md
// UID:00004F | by-class/Encoder.md | Completion:94 | Confidence:93
#include "BinaryCodec.h"
#include "MemoryMan.h"
#include "../third_party/zlib/zlib.h"
#include <windows.h>
#include <memory.h>
#include <wchar.h>

// UID:00013C | by-memory/0x004a4e70-0x004a4e94.EncoderConstructor.md | Completion:93 | Confidence:94
Encoder::Encoder()
    : m_outputBuffer(NULL),
      m_capacity(0),
      m_writePos(0),
      m_useBigEndian(true),
      m_isWritable(true)
{
}

// UID:00013E | by-memory/0x004a4ea0-0x004a4ea7.EncoderDestructor.md | Completion:93 | Confidence:94
Encoder::~Encoder()
{
}

// UID:000512 | by-memory/0x004a4eb0-0x004a4ebd.EncoderSetByteOrder.md | Completion:91 | Confidence:92
void Encoder::SetByteOrder(bool useBigEndian)
{
    m_useBigEndian = useBigEndian;
}

// UID:00013F | by-memory/0x004a4ec0-0x004a4ef1.EncoderWriteByte.md | Completion:93 | Confidence:94
void Encoder::WriteByte(unsigned char value)
{
    if (!m_isWritable)
        return;

    int writePos = m_writePos;
    if (m_capacity < writePos + 2)
    {
        m_isWritable = false;
        return;
    }

    m_outputBuffer[writePos] = value;
    m_writePos = writePos + 1;
}

// UID:00013G | by-memory/0x004a4f00-0x004a4f59.EncoderWriteShort.md | Completion:93 | Confidence:94
void Encoder::WriteShort(unsigned short value)
{
    if (!m_isWritable)
        return;

    if (m_capacity < m_writePos + 3)
    {
        m_isWritable = false;
        return;
    }

    if (m_useBigEndian)
    {
        m_outputBuffer[m_writePos++] = (unsigned char)(value >> 8);
        m_outputBuffer[m_writePos++] = (unsigned char)value;
    }
    else
    {
        *(unsigned short *)(m_outputBuffer + m_writePos) = value;
        m_writePos += 2;
    }
}

// UID:000514 | by-memory/0x004a4f60-0x004a4fe3.EncoderWriteTriByte.md | Completion:91 | Confidence:92
void Encoder::WriteTriByte(unsigned int value)
{
    if (!m_isWritable)
        return;

    if (m_capacity < m_writePos + 4)
    {
        m_isWritable = false;
        return;
    }

    if (m_useBigEndian)
    {
        m_outputBuffer[m_writePos++] = (unsigned char)(value >> 16);
        m_outputBuffer[m_writePos++] = (unsigned char)(value >> 8);
        m_outputBuffer[m_writePos++] = (unsigned char)value;
    }
    else
    {
        m_outputBuffer[m_writePos++] = (unsigned char)value;
        m_outputBuffer[m_writePos++] = (unsigned char)(value >> 8);
        m_outputBuffer[m_writePos++] = (unsigned char)(value >> 16);
    }
}

// UID:00013H | by-memory/0x004a4ff0-0x004a506b.EncoderWriteInt.md | Completion:93 | Confidence:94
void Encoder::WriteInt(unsigned int value)
{
    if (!m_isWritable)
        return;

    if (m_capacity < m_writePos + 5)
    {
        m_isWritable = false;
        return;
    }

    if (m_useBigEndian)
    {
        m_outputBuffer[m_writePos++] = (unsigned char)(value >> 24);
        m_outputBuffer[m_writePos++] = (unsigned char)(value >> 16);
        m_outputBuffer[m_writePos++] = (unsigned char)(value >> 8);
        m_outputBuffer[m_writePos++] = (unsigned char)value;
    }
    else
    {
        *(unsigned int *)(m_outputBuffer + m_writePos) = value;
        m_writePos += 4;
    }
}

// UID:000513 | by-memory/0x004a5070-0x004a50e3.EncoderWriteWideString8.md | Completion:91 | Confidence:92
void Encoder::WriteWideString8(const wchar_t *text, int charCount)
{
    if (!m_isWritable)
        return;

    if (charCount == -1)
        charCount = (int)wcslen(text);

    int byteCount = charCount + charCount;
    if (m_capacity < m_writePos + byteCount + 2)
    {
        m_isWritable = false;
        return;
    }

    m_outputBuffer[m_writePos++] = (unsigned char)charCount;
    GetMemoryMan()->MemmoveWrapper(
        m_outputBuffer + m_writePos,
        text,
        byteCount);
    m_writePos += byteCount;
}

// UID:000515 | by-memory/0x004a50f0-0x004a5189.EncoderWriteWideString16.md | Completion:91 | Confidence:92
void Encoder::WriteWideString16(const wchar_t *text, int charCount)
{
    if (!m_isWritable)
        return;

    if (charCount == -1)
        charCount = (int)wcslen(text);

    int byteCount = charCount + charCount;
    if (m_capacity < m_writePos + byteCount + 3)
    {
        m_isWritable = false;
        return;
    }

    if (m_useBigEndian)
    {
        m_outputBuffer[m_writePos++] = (unsigned char)(charCount >> 8);
        m_outputBuffer[m_writePos++] = (unsigned char)charCount;
    }
    else
    {
        *(unsigned short *)(m_outputBuffer + m_writePos) =
            (unsigned short)charCount;
        m_writePos += 2;
    }

    GetMemoryMan()->MemmoveWrapper(
        m_outputBuffer + m_writePos,
        text,
        byteCount);
    m_writePos += byteCount;
}

// UID:000516 | by-memory/0x004a5190-0x004a5293.EncoderWriteAnsiString8.md | Completion:91 | Confidence:92
void Encoder::WriteAnsiString8(const wchar_t *text, int charCount)
{
    char scratch[0x100];

    if (!m_isWritable)
        return;

    int actualChars = (int)wcslen(text);
    if (charCount == -1 || actualChars < charCount)
        charCount = actualChars;

    int byteCount = WideCharToMultiByte(
        CP_ACP,
        0,
        text,
        charCount,
        scratch,
        0x100,
        NULL,
        NULL);

    if (0xFF < byteCount)
        byteCount = 0xFF;
    scratch[byteCount] = 0;

    if (m_capacity < m_writePos + byteCount + 2)
    {
        m_isWritable = false;
        return;
    }

    m_outputBuffer[m_writePos++] = (unsigned char)byteCount;
    GetMemoryMan()->MemmoveWrapper(
        m_outputBuffer + m_writePos,
        scratch,
        byteCount);
    m_writePos += byteCount;
}

// UID:000517 | by-memory/0x004a52a0-0x004a53ca.EncoderWriteAnsiString16.md | Completion:91 | Confidence:92
void Encoder::WriteAnsiString16(const wchar_t *text, int charCount)
{
    char scratch[0x10000];

    if (!m_isWritable)
        return;

    int actualChars = (int)wcslen(text);
    if (charCount == -1 || actualChars < charCount)
        charCount = actualChars;

    int byteCount = WideCharToMultiByte(
        CP_ACP,
        0,
        text,
        charCount,
        scratch,
        0x10000,
        NULL,
        NULL);

    if (0xFFFF < byteCount)
        byteCount = 0xFFFF;
    scratch[byteCount] = 0;

    if (m_capacity < m_writePos + byteCount + 3)
    {
        m_isWritable = false;
        return;
    }

    if (m_useBigEndian)
    {
        m_outputBuffer[m_writePos++] = (unsigned char)(byteCount >> 8);
        m_outputBuffer[m_writePos++] = (unsigned char)byteCount;
    }
    else
    {
        *(unsigned short *)(m_outputBuffer + m_writePos) =
            (unsigned short)byteCount;
        m_writePos += 2;
    }

    GetMemoryMan()->MemmoveWrapper(
        m_outputBuffer + m_writePos,
        scratch,
        byteCount);
    m_writePos += byteCount;
}

// UID:00051A | by-memory/0x004a53d0-0x004a5472.EncoderWriteCString.md | Completion:91 | Confidence:92
void Encoder::WriteCString(const wchar_t *text, int charCount)
{
    if (!m_isWritable)
        return;

    if (charCount == -1)
        charCount = (int)wcslen(text);

    char *scratch = new char[charCount + charCount + 1];
    int byteCount = WideCharToMultiByte(
        CP_ACP,
        0,
        text,
        charCount,
        scratch,
        charCount + charCount,
        NULL,
        NULL);
    scratch[byteCount] = 0;

    if (m_capacity < m_writePos + byteCount + 1)
    {
        m_isWritable = false;
        return;
    }

    GetMemoryMan()->MemmoveWrapper(
        m_outputBuffer + m_writePos,
        scratch,
        byteCount);
    m_writePos += byteCount;
    m_outputBuffer[m_writePos++] = 0;
}

// UID:00013I | by-memory/0x004a5480-0x004a54c6.EncoderWriteBytes.md | Completion:93 | Confidence:94
void Encoder::WriteBytes(const void *data, int byteCount)
{
    if (!m_isWritable)
        return;

    int writePos = m_writePos;
    if (m_capacity < writePos + byteCount + 1)
    {
        m_isWritable = false;
        return;
    }

    GetMemoryMan()->MemmoveWrapper(
        m_outputBuffer + writePos,
        data,
        byteCount);
    m_writePos = writePos + byteCount;
}

// UID:000518 | by-memory/0x004a54d0-0x004a558d.EncoderWriteCompressedBytes.md | Completion:91 | Confidence:92
void Encoder::WriteCompressedBytes(const void *data, int byteCount)
{
    if (!m_isWritable)
        return;

    int bufferSize = ((byteCount + 12) * 11) / 10;
    unsigned char *compressed = new unsigned char[bufferSize];
    unsigned long compressedSize = bufferSize;
    compress(compressed, &compressedSize, (const unsigned char *)data, byteCount);

    if (m_capacity < m_writePos + (int)compressedSize + 3)
    {
        m_isWritable = false;
        return;
    }

    if (m_useBigEndian)
    {
        m_outputBuffer[m_writePos++] = (unsigned char)(compressedSize >> 8);
        m_outputBuffer[m_writePos++] = (unsigned char)compressedSize;
    }
    else
    {
        *(unsigned short *)(m_outputBuffer + m_writePos) =
            (unsigned short)compressedSize;
        m_writePos += 2;
    }

    GetMemoryMan()->MemmoveWrapper(
        m_outputBuffer + m_writePos,
        compressed,
        compressedSize);
    m_writePos += compressedSize;
    delete[] compressed;
}

// UID:000519 | by-memory/0x004a5590-0x004a55b6.EncoderSkipBytes.md | Completion:91 | Confidence:92
void Encoder::SkipBytes(int byteCount)
{
    if (!m_isWritable)
        return;

    int nextWritePos = m_writePos + byteCount;
    if (m_capacity < nextWritePos + 1)
    {
        m_isWritable = false;
        return;
    }

    m_writePos = nextWritePos;
}

// UID:00013J | by-memory/0x004a55c0-0x004a55de.EncoderInitialize.md | Completion:93 | Confidence:94
void Encoder::Initialize(unsigned char *buffer, int capacity)
{
    m_outputBuffer = buffer;
    m_capacity = capacity;
    m_writePos = 0;
    m_isWritable = true;
}

// UID:00013K | by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md | Completion:93 | Confidence:94
bool Encoder::Finalize(unsigned int *outBytesWritten)
{
    bool wasWritable = m_isWritable;

    if (outBytesWritten != NULL)
        *outBytesWritten = m_writePos;

    m_outputBuffer[m_writePos] = 0;
    m_outputBuffer = NULL;
    m_capacity = 0;
    m_writePos = 0;
    m_isWritable = true;
    return wasWritable;
}

// UID:00013L | by-memory/0x004a5630-0x004a5631.EncoderNoopVirtual.md | Completion:93 | Confidence:94
void Encoder::NoopVirtual()
{
}

// UID:00003M | by-class/Decoder.md | Completion:94 | Confidence:93
// UID:00013N | by-memory/0x004a5640-0x004a5664.DecoderConstructor.md | Completion:93 | Confidence:94
Decoder::Decoder()
    : m_inputBuffer(NULL),
      m_inputSize(0),
      m_readPos(0),
      m_useBigEndian(true),
      m_isValid(true)
{
}

// UID:00013O | by-memory/0x004a5670-0x004a5677.DecoderDestructor.md | Completion:93 | Confidence:94
Decoder::~Decoder()
{
}

// UID:0003K8 | by-memory/0x004a5680-0x004a568d.DecoderSetByteOrder.md | Completion:93 | Confidence:94
void Decoder::SetByteOrder(bool useBigEndian)
{
    m_useBigEndian = useBigEndian;
}

// UID:0003K9 | by-memory/0x004a5690-0x004a56b8.DecoderReadByte.md | Completion:93 | Confidence:94
unsigned char Decoder::ReadByte()
{
    if (!m_isValid)
        return 0;

    int readPos = m_readPos;
    int nextReadPos = readPos + 1;
    if (m_inputSize < nextReadPos)
    {
        m_isValid = false;
        return 0;
    }

    unsigned char value = m_inputBuffer[readPos];
    m_readPos = nextReadPos;
    return value;
}

// UID:0003KA | by-memory/0x004a56c0-0x004a570f.DecoderReadShort.md | Completion:93 | Confidence:94
unsigned short Decoder::ReadShort()
{
    if (!m_isValid)
        return 0;

    int readPos = m_readPos;
    int nextReadPos = readPos + 2;
    if (m_inputSize < nextReadPos)
    {
        m_isValid = false;
        return 0;
    }

    const unsigned char *src = m_inputBuffer + readPos;
    if (m_useBigEndian)
    {
        unsigned char high = *src++;
        m_readPos = ++readPos;
        unsigned char low = *src;
        m_readPos = nextReadPos;
        return (unsigned short)(((unsigned short)high << 8) | low);
    }

    m_readPos = nextReadPos;
    return *(const unsigned short *)src;
}

// UID:0003KB | by-memory/0x004a5710-0x004a576f.DecoderReadTriByte.md | Completion:93 | Confidence:94
unsigned int Decoder::ReadTriByte()
{
    if (!m_isValid)
        return 0;

    int readPos = m_readPos;
    int nextReadPos = readPos + 3;
    if (m_inputSize < nextReadPos)
    {
        m_isValid = false;
        return 0;
    }

    const unsigned char *src = m_inputBuffer + readPos;
    unsigned int b0 = *src++;
    m_readPos = ++readPos;
    unsigned int b1 = *src++;
    m_readPos = ++readPos;
    unsigned int b2 = *src;
    m_readPos = nextReadPos;

    if (m_useBigEndian)
        return (b0 << 16) | (b1 << 8) | b2;
    return b0 | (b1 << 8) | (b2 << 16);
}

// UID:0003KC | by-memory/0x004a5770-0x004a57dc.DecoderReadInt.md | Completion:93 | Confidence:94
unsigned int Decoder::ReadInt()
{
    if (!m_isValid)
        return 0;

    int readPos = m_readPos;
    int nextReadPos = readPos + 4;
    if (m_inputSize < nextReadPos)
    {
        m_isValid = false;
        return 0;
    }

    const unsigned char *src = m_inputBuffer + readPos;
    if (m_useBigEndian)
    {
        unsigned int b0 = *src++;
        m_readPos = ++readPos;
        unsigned int b1 = *src++;
        m_readPos = ++readPos;
        unsigned int b2 = *src++;
        m_readPos = ++readPos;
        unsigned int b3 = *src;
        m_readPos = nextReadPos;
        return (b0 << 24) | (b1 << 16) | (b2 << 8) | b3;
    }

    m_readPos = nextReadPos;
    return *(const unsigned int *)src;
}

// UID:0003L6 | by-memory/0x004a57e0-0x004a5861.DecoderReadWideString8.md | Completion:93 | Confidence:94
void Decoder::ReadWideString8(wchar_t *out, int capacityChars, int *outChars)
{
    out[0] = 0;
    if (outChars != NULL)
        *outChars = 0;

    if (!m_isValid)
        return;

    int readPos = m_readPos;
    int nextReadPos = readPos + 1;
    if (m_inputSize < nextReadPos)
    {
        m_isValid = false;
        return;
    }

    int charCount = m_inputBuffer[readPos];
    m_readPos = nextReadPos;
    int byteCount = charCount + charCount;
    if (m_inputSize < nextReadPos + byteCount || capacityChars < charCount)
    {
        m_isValid = false;
        return;
    }

    if (outChars != NULL)
        *outChars = charCount;
    memmove(out, m_inputBuffer + m_readPos, byteCount);
    m_readPos += byteCount;
    out[charCount] = 0;
}

// UID:0003L7 | by-memory/0x004a5870-0x004a5925.DecoderReadWideString16.md | Completion:93 | Confidence:94
void Decoder::ReadWideString16(wchar_t *out, int capacityChars, int *outChars)
{
    out[0] = 0;
    if (outChars != NULL)
        *outChars = 0;

    if (!m_isValid)
        return;

    int readPos = m_readPos;
    int nextReadPos = readPos + 2;
    if (m_inputSize < nextReadPos)
    {
        m_isValid = false;
        return;
    }

    const unsigned char *src = m_inputBuffer + readPos;
    int charCount;
    if (m_useBigEndian)
    {
        unsigned char high = *src++;
        m_readPos = ++readPos;
        unsigned char low = *src;
        charCount = ((int)high << 8) | low;
        m_readPos = nextReadPos;
    }
    else
    {
        charCount = *(const unsigned short *)src;
        m_readPos = nextReadPos;
    }

    int byteCount = charCount + charCount;
    if (m_inputSize < nextReadPos + byteCount || capacityChars < charCount)
    {
        m_isValid = false;
        return;
    }

    if (outChars != NULL)
        *outChars = charCount;
    memmove(out, m_inputBuffer + m_readPos, byteCount);
    m_readPos += byteCount;
    out[charCount] = 0;
}

// UID:0003L8 | by-memory/0x004a5930-0x004a5a3a.DecoderReadAnsiString8.md | Completion:93 | Confidence:94
void Decoder::ReadAnsiString8(wchar_t *out, int capacityChars, int *outChars)
{
    char scratch[0x100];

    out[0] = 0;
    if (outChars != NULL)
        *outChars = 0;
    if (!m_isValid)
        return;

    int readPos = m_readPos;
    int nextReadPos = readPos + 1;
    if (m_inputSize < nextReadPos)
    {
        m_isValid = false;
        return;
    }

    int byteCount = m_inputBuffer[readPos];
    m_readPos = nextReadPos;
    if (m_inputSize < nextReadPos + byteCount)
    {
        m_isValid = false;
        return;
    }

    memmove(scratch, m_inputBuffer + m_readPos, byteCount);
    m_readPos += byteCount;
    scratch[byteCount] = 0;

    int convertedChars = MultiByteToWideChar(
        CP_ACP, 0, scratch, byteCount, out, capacityChars + 1);
    if (capacityChars < convertedChars)
    {
        out[0] = 0;
        m_isValid = false;
        return;
    }

    out[convertedChars] = 0;
    if (outChars != NULL)
        *outChars = convertedChars;
}

// UID:0003L9 | by-memory/0x004a5a40-0x004a5ba7.DecoderReadAnsiString16.md | Completion:93 | Confidence:94
void Decoder::ReadAnsiString16(wchar_t *out, int capacityChars, int *outChars)
{
    char scratch[0x10000];

    out[0] = 0;
    if (outChars != NULL)
        *outChars = 0;
    if (!m_isValid)
        return;

    int readPos = m_readPos;
    int nextReadPos = readPos + 2;
    if (m_inputSize < nextReadPos)
    {
        m_isValid = false;
        return;
    }

    const unsigned char *src = m_inputBuffer + readPos;
    int byteCount;
    if (m_useBigEndian)
    {
        unsigned char high = *src++;
        m_readPos = ++readPos;
        unsigned char low = *src;
        byteCount = ((int)high << 8) | low;
        m_readPos = nextReadPos;
    }
    else
    {
        byteCount = *(const unsigned short *)src;
        m_readPos = nextReadPos;
    }

    if (m_inputSize < nextReadPos + byteCount)
    {
        m_isValid = false;
        return;
    }

    memmove(scratch, m_inputBuffer + m_readPos, byteCount);
    m_readPos += byteCount;
    scratch[byteCount] = 0;

    int convertedChars = MultiByteToWideChar(
        CP_ACP, 0, scratch, byteCount, out, capacityChars + 1);
    if (capacityChars < convertedChars)
    {
        out[0] = 0;
        m_isValid = false;
        return;
    }

    out[convertedChars] = 0;
    if (outChars != NULL)
        *outChars = convertedChars;
}

// UID:0003LA | by-memory/0x004a5bb0-0x004a5c7e.DecoderReadCString.md | Completion:93 | Confidence:94
void Decoder::ReadCString(wchar_t *out, int capacityChars, int *outChars)
{
    out[0] = 0;
    if (outChars != NULL)
        *outChars = 0;
    if (!m_isValid)
        return;

    int readPos = m_readPos;
    int inputSize = m_inputSize;
    if (inputSize < readPos)
    {
        m_isValid = false;
        return;
    }

    const unsigned char *src = m_inputBuffer + readPos;
    int byteCount = 0;
    while (src[byteCount] != 0)
    {
        ++byteCount;
        if (inputSize < readPos + byteCount)
        {
            m_isValid = false;
            return;
        }
    }

    char *scratch = new char[byteCount + 1];
    memmove(scratch, src, byteCount);
    m_readPos += byteCount + 1;
    scratch[byteCount] = 0;

    int convertedChars = MultiByteToWideChar(
        CP_ACP, 0, scratch, byteCount, out, capacityChars + 1);
    delete[] scratch;

    if (capacityChars < convertedChars)
    {
        out[0] = 0;
        m_isValid = false;
        return;
    }

    out[convertedChars] = 0;
    if (outChars != NULL)
        *outChars = convertedChars;
}

// UID:0003LB | by-memory/0x004a5c80-0x004a5cc4.DecoderReadBytes.md | Completion:93 | Confidence:94
void Decoder::ReadBytes(void *out, int byteCount)
{
    if (!m_isValid)
        return;

    int readPos = m_readPos;
    int nextReadPos = readPos + byteCount;
    if (m_inputSize < nextReadPos)
    {
        m_isValid = false;
        return;
    }

    memmove(out, m_inputBuffer + readPos, byteCount);
    m_readPos = nextReadPos;
}

// UID:0003LC | by-memory/0x004a5cd0-0x004a5d79.DecoderReadCompressedBytes.md | Completion:93 | Confidence:94
void Decoder::ReadCompressedBytes(
    void *out,
    unsigned int outCapacity,
    unsigned int *outBytes)
{
    if (outBytes != NULL)
        *outBytes = 0;
    if (!m_isValid)
        return;

    int readPos = m_readPos;
    int nextReadPos = readPos + 2;
    if (m_inputSize < nextReadPos)
    {
        m_isValid = false;
        return;
    }

    const unsigned char *src = m_inputBuffer + readPos;
    unsigned int compressedLength;
    if (m_useBigEndian)
    {
        unsigned char high = *src++;
        m_readPos = ++readPos;
        unsigned char low = *src;
        compressedLength = ((unsigned int)high << 8) | low;
        m_readPos = nextReadPos;
    }
    else
    {
        compressedLength = *(const unsigned short *)src;
        m_readPos = nextReadPos;
    }

    if (m_inputSize < nextReadPos + (int)compressedLength)
    {
        m_isValid = false;
        return;
    }

    unsigned long producedSize = outCapacity;
    uncompress(
        (unsigned char *)out,
        &producedSize,
        m_inputBuffer + m_readPos,
        compressedLength);
    m_readPos += compressedLength;

    if (outCapacity < producedSize)
    {
        m_isValid = false;
        return;
    }

    if (outBytes != NULL)
        *outBytes = (unsigned int)producedSize;
}

// UID:0003LD | by-memory/0x004a5d80-0x004a5da6.DecoderSkipBytes.md | Completion:93 | Confidence:94
void Decoder::SkipBytes(int byteCount)
{
    if (!m_isValid)
        return;

    int nextReadPos = m_readPos + byteCount;
    if (m_inputSize < nextReadPos + 1)
    {
        m_isValid = false;
        return;
    }

    m_readPos = nextReadPos;
}

// UID:0003LE | by-memory/0x004a5db0-0x004a5dce.DecoderInitialize.md | Completion:93 | Confidence:94
void Decoder::Initialize(const unsigned char *buffer, int size)
{
    m_inputBuffer = buffer;
    m_inputSize = size;
    m_readPos = 0;
    m_isValid = true;
}

// UID:00013S | by-memory/0x004a5dd0-0x004a5ded.DecoderFinalize.md | Completion:93 | Confidence:94
bool Decoder::Finalize()
{
    bool wasValid = m_isValid;
    m_inputBuffer = NULL;
    m_inputSize = 0;
    m_readPos = 0;
    m_isValid = true;
    return wasValid;
}

// UID:00013T | by-memory/0x004a5df0-0x004a5df1.DecoderNoopVirtual.md | Completion:93 | Confidence:94
void Decoder::NoopVirtual()
{
}
