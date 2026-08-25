// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000IN
// Source by-file doc: by-file/DATFile.md
// UID:00003G | by-class/DATFile.md | Completion:94 | Confidence:95
#include "DATFile.h"
#include "DATFileMgr.h"
#include "../util/Error.h"
#include "../util/MemoryMan.h"
#include <string.h>

// UID:00055G | by-memory/0x0049c130-0x0049c15a.DATFileConstructor.md | Completion:92 | Confidence:95
DATFile::DATFile()
    : m_archive(0), m_entry(0)
{
}

// UID:00055H | by-memory/0x0049c160-0x0049c179.DATFileDestructor.md | Completion:92 | Confidence:95
DATFile::~DATFile()
{
    m_entry = 0;
    m_archive = 0;
}

// UID:00055I | by-memory/0x0049c180-0x0049c23b.DATFileOpen.md | Completion:92 | Confidence:95
void DATFile::Open(const wchar_t *path)
{
    DATEntryLocation location;
    if (!g_pDATFileMgr->FindEntryByName(path, &location)) {
        throw new FileError(path);
    }

    m_archive = location.archive;
    m_entry = m_archive->m_entries + location.index;
    m_position = m_entry->startOffset;
    m_size = (m_entry + 1)->startOffset - m_entry->startOffset;
}

// UID:00055J | by-memory/0x0049c240-0x0049c260.DATFileClose.md | Completion:92 | Confidence:95
bool DATFile::Close()
{
    if (m_archive == 0 || m_entry == 0) {
        return false;
    }
    m_entry = 0;
    m_archive = 0;
    return true;
}

// UID:00055K | by-memory/0x0049c260-0x0049c2cc.DATFileSeek.md | Completion:92 | Confidence:95
bool DATFile::Seek(int offset, int origin)
{
    if (m_archive == 0 || m_entry == 0) {
        return false;
    }

    int position;
    if (origin == 0) {
        if (offset < 0 || offset >= m_size) return false;
        position = m_entry->startOffset + offset;
    } else if (origin == 1) {
        position = m_position + offset;
        if (position < static_cast<int>(m_entry->startOffset) ||
            position >= static_cast<int>((m_entry + 1)->startOffset)) return false;
    } else if (origin == 2) {
        if (offset < 0 || offset >= m_size) return false;
        position = (m_entry + 1)->startOffset - offset;
    } else {
        return false;
    }

    m_position = position;
    return true;
}

// UID:00055L | by-memory/0x0049c2d0-0x0049c2e7.DATFileGetPosition.md | Completion:92 | Confidence:95
int DATFile::GetPosition()
{
    return m_archive != 0 && m_entry != 0
        ? m_position - m_entry->startOffset : -1;
}

// UID:00055M | by-memory/0x0049c2f0-0x0049c304.DATFileGetSize.md | Completion:92 | Confidence:95
int DATFile::GetSize()
{
    return m_archive != 0 && m_entry != 0 ? m_size : -1;
}

// UID:00055N | by-memory/0x0049c310-0x0049c362.DATFileRead.md | Completion:92 | Confidence:95
size_t DATFile::Read(void *buffer, int count)
{
    if (m_archive == 0 || m_entry == 0) return 0;
    size_t readSize = count < 0 ? m_size : static_cast<size_t>(count);
    if (m_position + readSize > (m_entry + 1)->startOffset) return 0;
    memmove(buffer,
            static_cast<unsigned char *>(m_archive->m_mappedView) + m_position,
            readSize);
    m_position += readSize;
    return readSize;
}

// UID:00055O | by-memory/0x0049c370-0x0049c3df.DATFileReadLineChars.md | Completion:92 | Confidence:95
int DATFile::ReadLineChars(char *buffer, int limit)
{
    if (m_archive == 0 || m_entry == 0) return -1;
    int scan = m_position;
    const int end = (m_entry + 1)->startOffset;
    if (scan < end) {
        while (true) {
            const char current = static_cast<const char *>(m_archive->m_mappedView)[scan];
            if (current == '\r') { ++scan; break; }
            if (current == '\n') break;
            if (++scan >= end) break;
        }
    }
    const int count = scan - m_position + 1;
    if (count <= 0 || count > limit) return -1;
    memmove(buffer, static_cast<const char *>(m_archive->m_mappedView) + m_position, count);
    m_position += count;
    return count;
}

// UID:00055P | by-memory/0x0049c3e0-0x0049c499.DATFileReadLine.md | Completion:92 | Confidence:95
bool DATFile::ReadLine(StringBaseA &line)
{
    StringBaseA result;
    if (m_archive == 0 || m_entry == 0) return false;
    const int end = (m_entry + 1)->startOffset;
    if (m_position >= end) return false;
    int scan = m_position;
    while (true) {
        const char current = static_cast<const char *>(m_archive->m_mappedView)[scan];
        if (current == '\r') { ++scan; break; }
        if (current == '\n') break;
        result.append(1, current);
        if (++scan >= end) break;
    }
    const int count = scan - m_position + 1;
    if (count <= 0) return false;
    m_position += count;
    line = result;
    return true;
}

// UID:0004IY | by-memory/0x0049c4a0-0x0049c4ef.DATFileReadEncodedTableInt.md | Completion:90 | Confidence:93
int DATFile::ReadEncodedTableInt(int *outValue)
{
    unsigned char encodedBytes[8];
    const unsigned int validationKey =
        static_cast<unsigned int>(GetSize()) >> 1;

    Read(encodedBytes, sizeof(encodedBytes));
    return DecodeTableValue(encodedBytes, validationKey, outValue);
}

// UID:0004IZ | by-memory/0x0049c4f0-0x0049c53f.DATFileReadEncodedTableFloat.md | Completion:90 | Confidence:93
int DATFile::ReadEncodedTableFloat(float *outValue)
{
    unsigned char encodedBytes[8];
    const unsigned int validationKey =
        static_cast<unsigned int>(GetSize()) >> 1;

    Read(encodedBytes, sizeof(encodedBytes));
    return DecodeTableValue(encodedBytes, validationKey, outValue);
}

// UID:00055Q | by-memory/0x0049c540-0x0049c548.DATFileIsOpen.md | Completion:92 | Confidence:95
bool DATFile::IsOpen() const
{
    return m_entry != 0;
}

// UID:00055R | by-memory/0x0049c550-0x0049c567.DATFileGetDataPointer.md | Completion:92 | Confidence:95
void *DATFile::GetDataPointer() const
{
    if (m_archive == 0 || m_entry == 0) return 0;
    return static_cast<unsigned char *>(m_archive->m_mappedView) + m_position;
}

// UID:00055T | by-memory/0x0049c600-0x0049c6f2.DATFileReadAllLines.md | Completion:92 | Confidence:95
void DATFile::ReadAllLines(std::vector<StringBaseW> &lines)
{
    lines.clear();
    StringBaseW line;
    while (File::ReadLine(line)) {
        lines.push_back(line);
    }
}

// UID:00055U | by-memory/0x0049c720-0x0049c74b.DATFileOpenByIndex.md | Completion:92 | Confidence:95
int DATFile::OpenByIndex(DATFileContainer *archive, int index)
{
    m_archive = archive;
    m_entry = archive->m_entries + index;
    m_position = m_entry->startOffset;
    m_size = (m_entry + 1)->startOffset - m_entry->startOffset;
    return m_size;
}

// UID:0003B7 | by-memory/0x00618920-0x00618950.DATFileVtableData.md | Completion:87 | Confidence:93
// This compiler-emitted RTTI/vtable record is covered by the DATFile class declaration and virtual method definitions.

// UID:00013W | by-memory/0x004a5e60-0x004a609f.ParseEntries.md | Completion:92 | Confidence:94
static int DecodeTableValue(unsigned char *encodedBytes,
                            unsigned int validationKey,
                            void *outValue)
{
    unsigned int decodeTable[27] = {
        75, 25, 31, 29,
        26, 9, 12, 12,
        83, 73, 19, 17,
        29, 23, 6, 29,
        9, 6, 8, 27,
        28, 1, 30, 29,
        3, 5, 9
    };

    for (int tableIndex = 1; tableIndex < 27; tableIndex += 2) {
        decodeTable[tableIndex] ^= decodeTable[tableIndex - 1];
        decodeTable[tableIndex + 1] ^= decodeTable[tableIndex];
    }

    unsigned int decodeIndex = (0xFEDCBA98u - validationKey) % 27u;
    for (int byteIndex = 0; byteIndex < 8; ++byteIndex) {
        encodedBytes[byteIndex] ^=
            static_cast<unsigned char>(decodeTable[decodeIndex]);
        decodeIndex = (decodeIndex + 26u) % 27u;
    }

    const unsigned int firstWord =
        (static_cast<unsigned int>(encodedBytes[0]) << 24) |
        (static_cast<unsigned int>(encodedBytes[1]) << 16) |
        (static_cast<unsigned int>(encodedBytes[2]) << 8) |
        static_cast<unsigned int>(encodedBytes[3]);
    const unsigned int secondWord =
        (static_cast<unsigned int>(encodedBytes[4]) << 24) |
        (static_cast<unsigned int>(encodedBytes[5]) << 16) |
        (static_cast<unsigned int>(encodedBytes[6]) << 8) |
        static_cast<unsigned int>(encodedBytes[7]);
    const unsigned int interleavedBits =
        (firstWord ^ secondWord) & 0x55555555u;

    if ((secondWord ^ interleavedBits) != validationKey) {
        return 0;
    }

    *static_cast<unsigned int *>(outValue) = firstWord ^ interleavedBits;
    return 1;
}

// UID:0000T4 | by-global/LoadDatFileBuffer_4BB120.md | Completion:88 | Confidence:92
// Emitted implementation for this LoadDatFileBuffer alias is covered by [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md) LoadDatFileBuffer.

// UID:0000TH | by-global/ParseEntries_004A5E60.md | Completion:90 | Confidence:93
// Emitted implementation for this historical ParseEntries alias is covered by [UID:00013W][0x004a5e60-0x004a609f.ParseEntries](by-memory/0x004a5e60-0x004a609f.ParseEntries.md) DecodeTableValue.

// UID:0000UW | by-item/LoadDatFileBuffer_004BB120.md | Completion:88 | Confidence:92
// Emitted implementation for this LoadDatFileBuffer alias is covered by [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md) LoadDatFileBuffer.

// UID:0000V5 | by-item/ParseEntries_004A5E60.md | Completion:89 | Confidence:92
// Emitted implementation for this historical ParseEntries item alias is covered by [UID:00013W][0x004a5e60-0x004a609f.ParseEntries](by-memory/0x004a5e60-0x004a609f.ParseEntries.md) DecodeTableValue.

// UID:00016G | by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md | Completion:88 | Confidence:92
char *__stdcall LoadDatFileBuffer(const wchar_t *path, int prefixSize, int *outSize)
{
    DATFile file;
    file.Open(path);

    int payloadSize = file.GetSize();
    int totalSize = payloadSize + prefixSize;
    char *buffer = static_cast<char *>(GetMemoryMan()->AllocateBufferMemory(totalSize));

    if (outSize != NULL) {
        *outSize = totalSize;
    }

    if (prefixSize > 0) {
        memset(buffer, 0, prefixSize);
    }

    file.Read(buffer + prefixSize, payloadSize);
    file.Close();

    return buffer;
}
