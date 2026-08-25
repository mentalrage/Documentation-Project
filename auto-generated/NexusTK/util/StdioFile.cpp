// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000O9
// Source by-file doc: by-file/StdioFile.md
// UID:0000E6 | by-class/StdioFile.md | Completion:91 | Confidence:92
typedef mystr::StringBase<char, mystr::mychar_traits<char> > StringBaseA;
typedef mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > StringBaseW;

class StdioFile : public File
{
public:
    StdioFile();
    virtual ~StdioFile();

    virtual void Open(const wchar_t *path);
    virtual bool Close();
    virtual int GetPosition();
    virtual bool Seek(int offset, int origin);
    virtual int GetSize();
    virtual size_t Read(void *buffer, int count);
    virtual bool ReadLine(StringBaseA &line);
    virtual int ReadLineChars(char *buffer, int limit);

    bool ReadLine(StringBaseW &line);
    int ReadRemaining(_AUTOBUF<unsigned char> &buffer);

private:
    FILE *m_fileHandle;
    int m_fileSize;
};

// UID:0001IQ | by-memory/0x00582070-0x0058209a.StdioFileConstructor.md | Completion:90 | Confidence:93
StdioFile::StdioFile()
{
    m_fileHandle = NULL;
    m_fileSize = 0;
}

// UID:0003H2 | by-type/by-struct/StdioFileLayout.md | Completion:90 | Confidence:93
// StdioFile storage layout is declared by the StdioFile class; no standalone emitted code for this layout page.

// UID:0003I1 | by-type/by-vtable/StdioFileVtable.md | Completion:88 | Confidence:93
// StdioFile vtable is compiler-generated from the StdioFile class declaration and virtual method definitions.

// UID:0001IR | by-memory/0x00582070-0x005824f6.StdioFile.md | Completion:89 | Confidence:91
// StdioFile aggregate emits through exact child method pages; this range has no separate source body.

// UID:00019F | by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md | Completion:90 | Confidence:94
int StdioFile::GetSize()
{
    return m_fileSize;
}

// UID:0001IS | by-memory/0x005820a0-0x005820c7.StdioFileDestructor.md | Completion:89 | Confidence:92
StdioFile::~StdioFile()
{
    if (m_fileHandle != NULL) {
        fclose(m_fileHandle);
    }
}

// UID:0001IT | by-memory/0x005820d0-0x005821c9.StdioFileOpen.md | Completion:90 | Confidence:92
void StdioFile::Open(const wchar_t *path)
{
    struct _stat64i32 statBuffer;

    if (g_pfnWideStat(path, &statBuffer) == -1) {
        throw new FileError(path);
    }

    m_fileHandle = g_pfnWideOpenFile(path, L"rb");
    m_fileSize = statBuffer.st_size;

    if (m_fileHandle == NULL) {
        throw new FileError(path);
    }
}

// UID:0001IU | by-memory/0x005821d0-0x005821f7.StdioFileClose.md | Completion:89 | Confidence:92
bool StdioFile::Close()
{
    if (m_fileHandle == NULL) {
        return false;
    }

    bool result = fclose(m_fileHandle) == 0;
    m_fileSize = 0;
    return result;
}

// UID:0001IV | by-memory/0x00582200-0x0058224a.StdioFileVirtualPositionReadMethods.md | Completion:91 | Confidence:93
int StdioFile::GetPosition()
{
    return ftell(m_fileHandle);
}

bool StdioFile::Seek(int offset, int origin)
{
    return fseek(m_fileHandle, offset, origin) == 0;
}

size_t StdioFile::Read(void *buffer, int count)
{
    return fread(buffer, 1, count, m_fileHandle);
}

// UID:0001IW | by-memory/0x00582250-0x005822c1.StdioFileReadLineChars.md | Completion:90 | Confidence:92
int StdioFile::ReadLineChars(char *buffer, int limit)
{
    int bytesRead = 0;
    bool firstRead = true;

    if (limit > 0) {
        for (;;) {
            unsigned char ch = static_cast<unsigned char>(getc(m_fileHandle));

            if (firstRead && ch == 0xff) {
                return -1;
            }

            firstRead = false;

            if (ch == '\r') {
                getc(m_fileHandle);
                break;
            }

            if (ch == '\n' || ch == 0xff) {
                break;
            }

            buffer[bytesRead++] = static_cast<char>(ch);
            if (bytesRead >= limit) {
                break;
            }
        }
    }

    if (bytesRead == limit) {
        return -1;
    }

    return bytesRead;
}

// UID:0001IX | by-memory/0x005822d0-0x00582379.StdioFileReadLine.md | Completion:90 | Confidence:91
bool StdioFile::ReadLine(StringBaseA &line)
{
    StringBaseA temp;
    bool firstRead = true;

    for (;;) {
        unsigned char ch = static_cast<unsigned char>(fgetc(m_fileHandle));

        if (firstRead && ch == 0xff) {
            return false;
        }

        firstRead = false;

        if (ch == '\r') {
            fgetc(m_fileHandle);
            break;
        }

        if (ch == '\n') {
            break;
        }

        char appended = static_cast<char>(ch);
        temp.Append(&appended, 1);
    }

    line = temp;
    return true;
}

// UID:0002RH | by-memory/0x00582380-0x00582405.StdioFileReadLineWideHelper.md | Completion:88 | Confidence:91
bool StdioFile::ReadLine(StringBaseW &line)
{
    StringBaseA temp;
    bool result = ReadLine(temp);

    line = StringBaseW(temp);
    return result;
}

// UID:0001IY | by-memory/0x00582410-0x00582459.StdioFileReadRemaining.md | Completion:90 | Confidence:92
int StdioFile::ReadRemaining(_AUTOBUF<unsigned char> &buffer)
{
    delete [] buffer.m_data;

    int remaining = m_fileSize - GetPosition();

    delete [] buffer.m_data;
    buffer.m_data = new unsigned char[remaining];
    buffer.m_count = remaining;

    return Read(buffer.m_data, remaining);
}

// UID:0001J0 | by-memory/0x005824a0-0x005824f6.StdioFileScalarDeletingDestructor.md | Completion:90 | Confidence:93
// Compiler-generated scalar deleting destructor for StdioFile; source destructor code is emitted by [UID:0001IS][0x005820a0-0x005820c7.StdioFileDestructor](by-memory/0x005820a0-0x005820c7.StdioFileDestructor.md).
