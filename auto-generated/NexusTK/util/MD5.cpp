// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000L6
// Source by-file doc: by-file/MD5.md
// UID:0004X5 | by-class/MD5.md | Completion:92 | Confidence:93
#include "MD5.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MD5_F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define MD5_G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define MD5_H(x, y, z) ((x) ^ (y) ^ (z))
#define MD5_I(x, y, z) ((y) ^ ((x) | (~z)))
#define MD5_ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

#define MD5_FF(a, b, c, d, x, s, ac) \
    { (a) += MD5_F((b), (c), (d)) + (x) + (unsigned int)(ac); \
      (a) = MD5_ROTATE_LEFT((a), (s)); \
      (a) += (b); }
#define MD5_GG(a, b, c, d, x, s, ac) \
    { (a) += MD5_G((b), (c), (d)) + (x) + (unsigned int)(ac); \
      (a) = MD5_ROTATE_LEFT((a), (s)); \
      (a) += (b); }
#define MD5_HH(a, b, c, d, x, s, ac) \
    { (a) += MD5_H((b), (c), (d)) + (x) + (unsigned int)(ac); \
      (a) = MD5_ROTATE_LEFT((a), (s)); \
      (a) += (b); }
#define MD5_II(a, b, c, d, x, s, ac) \
    { (a) += MD5_I((b), (c), (d)) + (x) + (unsigned int)(ac); \
      (a) = MD5_ROTATE_LEFT((a), (s)); \
      (a) += (b); }

// UID:00027R | by-memory/0x0066ddd8-0x0066de18.Md5PaddingBlock.md | Completion:95 | Confidence:95
static unsigned char PADDING[64] = { 0x80 };

// UID:0001B6 | by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md | Completion:93 | Confidence:94
// UID:0004XC | by-memory/0x005151f0-0x00515284.Md5DigestToHexString.md | Completion:92 | Confidence:94
char *Md5DigestToHexString(const unsigned char *digest)
{
    char result[256];
    char byteText[10];

    memset(result, 0, sizeof(result));
    memset(byteText, 0, sizeof(byteText));

    for (unsigned int i = 0; i < 16; ++i)
    {
        sprintf_s(byteText, sizeof(byteText), "%02x", digest[i]);
        strncat_s(result, sizeof(result), byteText, sizeof(byteText));
    }

    return _strdup(result);
}

// UID:0004XD | by-memory/0x00515290-0x0051530a.Md5StringHex.md | Completion:93 | Confidence:94
char *Md5StringHex(const char *text)
{
    MD5 md5;

    md5.Update((unsigned char *)text, (unsigned int)strlen(text));
    md5.Final();
    return Md5DigestToHexString(md5.digest);
}

// UID:0001B7 | by-memory/0x00515310-0x00515375.Md5BytesHex.md | Completion:91 | Confidence:92
char *Md5BytesHex(unsigned char *bytes, unsigned int byteCount)
{
    MD5 md5;

    md5.Update(bytes, byteCount);
    md5.Final();
    return Md5DigestToHexString(md5.digest);
}

// UID:0004XE | by-memory/0x00515380-0x005153dc.Md5BytesRaw.md | Completion:93 | Confidence:94
unsigned char *Md5BytesRaw(unsigned char *bytes, unsigned int byteCount)
{
    MD5 md5;

    md5.Update(bytes, byteCount);
    md5.Final();
    return md5.digest;
}

// UID:0004XF | by-memory/0x005153e0-0x00515445.Md5BytesToBuffer.md | Completion:93 | Confidence:94
void Md5BytesToBuffer(unsigned char *bytes, unsigned int byteCount, unsigned char digest[16])
{
    MD5 md5;

    md5.Update(bytes, byteCount);
    md5.Final();
    memcpy(digest, md5.digest, 16);
}

// UID:0001B8 | by-memory/0x00515450-0x00515568.Md5FilePathHex.md | Completion:91 | Confidence:92
char *Md5FilePathHex(const char *path)
{
    FILE *stream;
    MD5 md5;
    unsigned char buffer[1024];
    size_t bytesRead;

    memset(buffer, 0, sizeof(buffer));
    fopen_s(&stream, path, "rb");
    if (stream == NULL)
        return "000011112222333344445555666677778888";

    bytesRead = fread(buffer, 1, sizeof(buffer), stream);
    while (bytesRead != 0)
    {
        md5.Update(buffer, (unsigned int)bytesRead);
        bytesRead = fread(buffer, 1, sizeof(buffer), stream);
    }

    md5.Final();
    fclose(stream);
    return Md5DigestToHexString(md5.digest);
}

// UID:0004XG | by-memory/0x00515570-0x0051565b.Md5StreamHex.md | Completion:93 | Confidence:94
char *Md5StreamHex(FILE *stream)
{
    MD5 md5;
    unsigned char buffer[1024];
    size_t bytesRead;

    memset(buffer, 0, sizeof(buffer));
    if (stream == NULL)
        return "000011112222333344445555666677778888";

    bytesRead = fread(buffer, 1, sizeof(buffer), stream);
    while (bytesRead != 0)
    {
        md5.Update(buffer, (unsigned int)bytesRead);
        bytesRead = fread(buffer, 1, sizeof(buffer), stream);
    }

    md5.Final();
    return Md5DigestToHexString(md5.digest);
}

// UID:0004XH | by-memory/0x00515660-0x00515684.MD5Init.md | Completion:91 | Confidence:93
void MD5::Init()
{
    count[0] = 0;
    count[1] = 0;
    state[0] = 0x67452301;
    state[1] = 0xefcdab89;
    state[2] = 0x98badcfe;
    state[3] = 0x10325476;
}

// UID:0004XI | by-memory/0x00515690-0x00515744.MD5Update.md | Completion:94 | Confidence:94
void MD5::Update(unsigned char *input, unsigned int inputLen)
{
    unsigned int i;
    unsigned int index;
    unsigned int partLen;

    index = (count[0] >> 3) & 0x3f;

    if ((count[0] += inputLen << 3) < (inputLen << 3))
        ++count[1];
    count[1] += inputLen >> 29;

    partLen = 64 - index;

    if (inputLen >= partLen)
    {
        memmove(&buffer[index], input, partLen);
        Transform(buffer);

        for (i = partLen; i + 63 < inputLen; i += 64)
            Transform(&input[i]);

        index = 0;
    }
    else
    {
        i = 0;
    }

    memmove(&buffer[index], &input[i], inputLen - i);
}

// UID:0004XJ | by-memory/0x00515750-0x00515831.MD5Final.md | Completion:94 | Confidence:94
void MD5::Final()
{
    unsigned char bits[8];
    unsigned int index;
    unsigned int padLen;

    Encode(bits, count, 8);

    index = (count[0] >> 3) & 0x3f;
    padLen = index < 56 ? 56 - index : 120 - index;
    Update(PADDING, padLen);
    Update(bits, 8);

    Encode(digest, state, 16);

    memset(state, 0, sizeof(state));
    memset(count, 0, sizeof(count));
    memset(buffer, 0, sizeof(buffer));
}

// UID:0004XK | by-memory/0x00515840-0x00515f48.MD5Transform.md | Completion:94 | Confidence:94
void MD5::Transform(const unsigned char block[64])
{
    unsigned int a = state[0];
    unsigned int b = state[1];
    unsigned int c = state[2];
    unsigned int d = state[3];
    unsigned int x[16];

    Decode(x, block, 64);

    MD5_FF(a, b, c, d, x[0], 7, 0xd76aa478);
    MD5_FF(d, a, b, c, x[1], 12, 0xe8c7b756);
    MD5_FF(c, d, a, b, x[2], 17, 0x242070db);
    MD5_FF(b, c, d, a, x[3], 22, 0xc1bdceee);
    MD5_FF(a, b, c, d, x[4], 7, 0xf57c0faf);
    MD5_FF(d, a, b, c, x[5], 12, 0x4787c62a);
    MD5_FF(c, d, a, b, x[6], 17, 0xa8304613);
    MD5_FF(b, c, d, a, x[7], 22, 0xfd469501);
    MD5_FF(a, b, c, d, x[8], 7, 0x698098d8);
    MD5_FF(d, a, b, c, x[9], 12, 0x8b44f7af);
    MD5_FF(c, d, a, b, x[10], 17, 0xffff5bb1);
    MD5_FF(b, c, d, a, x[11], 22, 0x895cd7be);
    MD5_FF(a, b, c, d, x[12], 7, 0x6b901122);
    MD5_FF(d, a, b, c, x[13], 12, 0xfd987193);
    MD5_FF(c, d, a, b, x[14], 17, 0xa679438e);
    MD5_FF(b, c, d, a, x[15], 22, 0x49b40821);

    MD5_GG(a, b, c, d, x[1], 5, 0xf61e2562);
    MD5_GG(d, a, b, c, x[6], 9, 0xc040b340);
    MD5_GG(c, d, a, b, x[11], 14, 0x265e5a51);
    MD5_GG(b, c, d, a, x[0], 20, 0xe9b6c7aa);
    MD5_GG(a, b, c, d, x[5], 5, 0xd62f105d);
    MD5_GG(d, a, b, c, x[10], 9, 0x02441453);
    MD5_GG(c, d, a, b, x[15], 14, 0xd8a1e681);
    MD5_GG(b, c, d, a, x[4], 20, 0xe7d3fbc8);
    MD5_GG(a, b, c, d, x[9], 5, 0x21e1cde6);
    MD5_GG(d, a, b, c, x[14], 9, 0xc33707d6);
    MD5_GG(c, d, a, b, x[3], 14, 0xf4d50d87);
    MD5_GG(b, c, d, a, x[8], 20, 0x455a14ed);
    MD5_GG(a, b, c, d, x[13], 5, 0xa9e3e905);
    MD5_GG(d, a, b, c, x[2], 9, 0xfcefa3f8);
    MD5_GG(c, d, a, b, x[7], 14, 0x676f02d9);
    MD5_GG(b, c, d, a, x[12], 20, 0x8d2a4c8a);

    MD5_HH(a, b, c, d, x[5], 4, 0xfffa3942);
    MD5_HH(d, a, b, c, x[8], 11, 0x8771f681);
    MD5_HH(c, d, a, b, x[11], 16, 0x6d9d6122);
    MD5_HH(b, c, d, a, x[14], 23, 0xfde5380c);
    MD5_HH(a, b, c, d, x[1], 4, 0xa4beea44);
    MD5_HH(d, a, b, c, x[4], 11, 0x4bdecfa9);
    MD5_HH(c, d, a, b, x[7], 16, 0xf6bb4b60);
    MD5_HH(b, c, d, a, x[10], 23, 0xbebfbc70);
    MD5_HH(a, b, c, d, x[13], 4, 0x289b7ec6);
    MD5_HH(d, a, b, c, x[0], 11, 0xeaa127fa);
    MD5_HH(c, d, a, b, x[3], 16, 0xd4ef3085);
    MD5_HH(b, c, d, a, x[6], 23, 0x04881d05);
    MD5_HH(a, b, c, d, x[9], 4, 0xd9d4d039);
    MD5_HH(d, a, b, c, x[12], 11, 0xe6db99e5);
    MD5_HH(c, d, a, b, x[15], 16, 0x1fa27cf8);
    MD5_HH(b, c, d, a, x[2], 23, 0xc4ac5665);

    MD5_II(a, b, c, d, x[0], 6, 0xf4292244);
    MD5_II(d, a, b, c, x[7], 10, 0x432aff97);
    MD5_II(c, d, a, b, x[14], 15, 0xab9423a7);
    MD5_II(b, c, d, a, x[5], 21, 0xfc93a039);
    MD5_II(a, b, c, d, x[12], 6, 0x655b59c3);
    MD5_II(d, a, b, c, x[3], 10, 0x8f0ccc92);
    MD5_II(c, d, a, b, x[10], 15, 0xffeff47d);
    MD5_II(b, c, d, a, x[1], 21, 0x85845dd1);
    MD5_II(a, b, c, d, x[8], 6, 0x6fa87e4f);
    MD5_II(d, a, b, c, x[15], 10, 0xfe2ce6e0);
    MD5_II(c, d, a, b, x[6], 15, 0xa3014314);
    MD5_II(b, c, d, a, x[13], 21, 0x4e0811a1);
    MD5_II(a, b, c, d, x[4], 6, 0xf7537e82);
    MD5_II(d, a, b, c, x[11], 10, 0xbd3af235);
    MD5_II(c, d, a, b, x[2], 15, 0x2ad7d2bb);
    MD5_II(b, c, d, a, x[9], 21, 0xeb86d391);

    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
}

// UID:000237 | by-memory/0x00515f50-0x00515ff2.MD5EndianEncodeDecodeHelpers.md | Completion:92 | Confidence:93
void MD5::Encode(unsigned char *output, const unsigned int *input, unsigned int length)
{
    unsigned int i;
    unsigned int j;

    for (i = 0, j = 0; j < length; ++i, j += 4)
    {
        output[j] = (unsigned char)(input[i] & 0xff);
        output[j + 1] = (unsigned char)((input[i] >> 8) & 0xff);
        output[j + 2] = (unsigned char)((input[i] >> 16) & 0xff);
        output[j + 3] = (unsigned char)((input[i] >> 24) & 0xff);
    }
}

void MD5::Decode(unsigned int *output, const unsigned char *input, unsigned int length)
{
    unsigned int i;
    unsigned int j;

    for (i = 0, j = 0; j < length; ++i, j += 4)
    {
        output[i] = ((unsigned int)input[j])
            | ((unsigned int)input[j + 1] << 8)
            | ((unsigned int)input[j + 2] << 16)
            | ((unsigned int)input[j + 3] << 24);
    }
}

// UID:0000V2 | by-item\PacketDigest_00515380.md | Completion:86 | Confidence:89 | Empty Emitter Marker

// UID:0003J1 | by-memory\0x0061ead4-0x0061eadc.Md5HexFormatString.md | Completion:87 | Confidence:93 | Empty Emitter Marker
