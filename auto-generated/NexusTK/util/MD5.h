// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000L6
// Source by-file doc: by-file/MD5.md
// UID:0004X5 | by-class/MD5.md | Completion:92 | Confidence:93
#ifndef NEXUSTK_UTIL_MD5_H
#define NEXUSTK_UTIL_MD5_H

#include <stdio.h>

class MD5
{
public:
    MD5()
    {
        Init();
    }

    void Update(unsigned char *input, unsigned int inputLen);
    void Final();

private:
    void Init();
    void Transform(const unsigned char block[64]);
    void Encode(unsigned char *output, const unsigned int *input, unsigned int length);
    void Decode(unsigned int *output, const unsigned char *input, unsigned int length);

    unsigned int state[4];
    unsigned int count[2];
    unsigned char buffer[64];

public:
    unsigned char digest[16];
};

// UID:0001B6 | by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md | Completion:93 | Confidence:94
// UID:0004XC | by-memory/0x005151f0-0x00515284.Md5DigestToHexString.md | Completion:92 | Confidence:94
char *Md5DigestToHexString(const unsigned char *digest);

// UID:0004XD | by-memory/0x00515290-0x0051530a.Md5StringHex.md | Completion:93 | Confidence:94
char *Md5StringHex(const char *text);

// UID:0001B7 | by-memory/0x00515310-0x00515375.Md5BytesHex.md | Completion:91 | Confidence:92
char *Md5BytesHex(unsigned char *bytes, unsigned int byteCount);

// UID:0004XE | by-memory/0x00515380-0x005153dc.Md5BytesRaw.md | Completion:93 | Confidence:94
unsigned char *Md5BytesRaw(unsigned char *bytes, unsigned int byteCount);

// UID:0004XF | by-memory/0x005153e0-0x00515445.Md5BytesToBuffer.md | Completion:93 | Confidence:94
void Md5BytesToBuffer(unsigned char *bytes, unsigned int byteCount, unsigned char digest[16]);

// UID:0001B8 | by-memory/0x00515450-0x00515568.Md5FilePathHex.md | Completion:91 | Confidence:92
char *Md5FilePathHex(const char *path);

// UID:0004XG | by-memory/0x00515570-0x0051565b.Md5StreamHex.md | Completion:93 | Confidence:94
char *Md5StreamHex(FILE *stream);

#endif
