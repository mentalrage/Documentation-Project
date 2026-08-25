// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000IN
// Source by-file doc: by-file/DATFile.md
// UID:00003G | by-class/DATFile.md | Completion:94 | Confidence:95
#ifndef NEXUSTK_ARCHIVE_DAT_FILE_H
#define NEXUSTK_ARCHIVE_DAT_FILE_H

#include "../util/File.h"
#include <vector>

class DATFileContainer;
struct DATEntryRecord;

class DATFile : public File
{
public:
    DATFile();
    virtual ~DATFile();

    virtual void Open(const wchar_t *path);
    virtual bool Close();
    virtual int GetPosition();
    virtual bool Seek(int offset, int origin);
    virtual int GetSize();
    virtual size_t Read(void *buffer, int count);
    virtual bool ReadLine(StringBaseA &line);
    virtual int ReadLineChars(char *buffer, int limit);

    int ReadEncodedTableInt(int *outValue);
    int ReadEncodedTableFloat(float *outValue);
    bool IsOpen() const;
    void *GetDataPointer() const;
    void ReadAllLines(std::vector<StringBaseW> &lines);
    int OpenByIndex(DATFileContainer *archive, int index);

private:
    DATFileContainer *m_archive;
    const DATEntryRecord *m_entry;
    int m_position;
    int m_size;
};

typedef char DATFileSizeMustBe0x14[
    sizeof(DATFile) == 0x14 ? 1 : -1];

char *__stdcall LoadDatFileBuffer(
    const wchar_t *path, int prefixSize, int *outSize);

#endif

// UID:00016G | by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md | Completion:88 | Confidence:92
char *__stdcall LoadDatFileBuffer(
    const wchar_t *path, int prefixSize, int *outSize);
