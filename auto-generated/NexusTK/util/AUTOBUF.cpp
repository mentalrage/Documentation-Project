// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HM
// Source by-file doc: by-file/AUTOBUF.md
// UID:00000P | by-class/AUTOBUF_unsigned_char.md | Completion:92 | Confidence:94
template <class T>
class _AUTOBUF : public LObject
{
public:
    _AUTOBUF();
    virtual ~_AUTOBUF();

    T *Resize(unsigned int count);

private:
    T *m_data;
    unsigned int m_count;
};

// UID:00019E | by-memory/0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor.md | Completion:90 | Confidence:92
template <>
_AUTOBUF<unsigned char>::_AUTOBUF()
    : LObject(),
      m_data(0),
      m_count(0)
{
}

// UID:0004TA | by-memory/0x004e5c10-0x004e5c2c.AUTOBUFUnsignedCharDestructor.md | Completion:92 | Confidence:94
template <>
_AUTOBUF<unsigned char>::~_AUTOBUF()
{
    delete [] m_data;
}

// UID:000188 | by-memory/0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize.md | Completion:90 | Confidence:91
template <>
unsigned char *_AUTOBUF<unsigned char>::Resize(unsigned int byteCount)
{
    delete [] m_data;

    unsigned char *data = new unsigned char[byteCount];
    m_count = byteCount;
    m_data = data;
    return data;
}
