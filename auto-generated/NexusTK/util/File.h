// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JB
// Source by-file doc: by-file/File.md
// UID:00004V | by-class/File.md | Completion:92 | Confidence:93
#ifndef NEXUSTK_UTIL_FILE_H
#define NEXUSTK_UTIL_FILE_H

#include "LObject.h"
#include "StringBase.h"
#include <stddef.h>

typedef mystr::StringBase<char, mystr::mychar_traits<char> > StringBaseA;
typedef mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > StringBaseW;

class File : public LObject
{
public:
    virtual ~File() {}

    virtual void Open(const wchar_t *path) = 0;
    virtual bool Close() = 0;
    virtual int GetPosition() = 0;
    virtual bool Seek(int offset, int origin) = 0;
    virtual int GetSize() = 0;
    virtual size_t Read(void *buffer, int count) = 0;
    virtual bool ReadLine(StringBaseA &line) = 0;
    virtual int ReadLineChars(char *buffer, int limit) = 0;

    StringBaseA ReadString(int count);
    bool ReadLine(StringBaseW &line);
};

#endif
