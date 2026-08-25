// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000J5
// Source by-file doc: by-file/Error.md
// UID:00004J | by-class/Error.md | Completion:90 | Confidence:92
#ifndef NEXUSTK_UTIL_ERROR_H
#define NEXUSTK_UTIL_ERROR_H

#include "LObject.h"
#include <stddef.h>
#include <windows.h>

class Error : public LObject
{
public:
    virtual ~Error()
    {
    }

    virtual int FormatErrorMessage(
        wchar_t *destination,
        size_t destinationChars) const = 0;
    virtual const wchar_t *GetErrorName() const;
};

class MyError : public Error
{
public:
    MyError(const wchar_t *message);
    virtual ~MyError();

    virtual int FormatErrorMessage(
        wchar_t *destination,
        size_t destinationChars) const;

private:
    wchar_t *m_messageText;
};

class PasswordError : public MyError
{
public:
    PasswordError(const wchar_t *message);
    virtual const wchar_t *GetErrorName() const;
};

class Win32Error : public Error
{
public:
    Win32Error();
    virtual int FormatErrorMessage(
        wchar_t *destination,
        size_t destinationChars) const;

private:
    DWORD m_errorCode;
};

typedef char ErrorSizeMustBe0x4[
    sizeof(Error) == 0x4 ? 1 : -1];
typedef char MyErrorSizeMustBe0x8[
    sizeof(MyError) == 0x8 ? 1 : -1];
typedef char PasswordErrorSizeMustBe0x8[
    sizeof(PasswordError) == 0x8 ? 1 : -1];
typedef char Win32ErrorSizeMustBe0x8[
    sizeof(Win32Error) == 0x8 ? 1 : -1];

// UID:00003L | by-class/DDError.md | Completion:88 | Confidence:89
class DDError : public Error
{
public:
    explicit DDError(HRESULT result);
    virtual int FormatErrorMessage(wchar_t *buffer,
                                   size_t bufferChars) const;

private:
    HRESULT m_errorCode;
};

typedef char DDErrorSizeMustBe8[
    sizeof(DDError) == 0x8 ? 1 : -1];

#endif

// UID:00004X | by-class/FileError.md | Completion:87 | Confidence:91
class FileError : public Error
{
public:
    FileError(const wchar_t *path);
    virtual int FormatErrorMessage(
        wchar_t *destination,
        size_t destinationChars) const;

private:
    wchar_t m_message[80];
};

typedef char FileErrorSizeMustBe0xA4[
    sizeof(FileError) == 0xA4 ? 1 : -1];
