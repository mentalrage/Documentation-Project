// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// Source by-file UID: 0000HG
// Source by-file doc: by-file/Application.md
// UID:00000D | by-class/Application.md
// UID:0002GU | by-memory/0x00465b70-0x00465b89.ApplicationCopyWorldName.md
errno_t Application::CopyWorldName(wchar_t* destination, size_t sizeInWords) const
{
    return wcscpy_s(destination, sizeInWords, m_worldName);
}

// UID:0002GV | by-memory/0x00465b90-0x00465bac.ApplicationCopyPlayerName.md
errno_t Application::CopyPlayerName(wchar_t* destination, size_t sizeInWords) const
{
    return wcscpy_s(destination, sizeInWords, m_playerName);
}
