// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JB
// Source by-file doc: by-file/File.md
// UID:00004V | by-class/File.md | Completion:92 | Confidence:93
#include "File.h"

// UID:00022C | by-memory/0x004b12a0-0x004b13ce.VirtualReadableStringHelpers.md | Completion:92 | Confidence:92
StringBaseA File::ReadString(int count)
{
    int available = GetSize() - GetPosition();
    if (count > available) {
        count = available;
    }

    StringBaseA result;
    char *buffer = result.SetLengthAnsiAndDetach(count);
    Read(buffer, count);
    result.LockAnsiBuffer();
    return result;
}

bool File::ReadLine(StringBaseW &line)
{
    StringBaseA narrowLine;
    if (!ReadLine(narrowLine)) {
        return false;
    }

    line = StringBaseW(narrowLine.c_str());
    return true;
}

// UID:0002UV | by-memory/0x006188e0-0x00618910.FileVtableData.md | Completion:92 | Confidence:94
// Emitted code for this range is covered by [UID:00004V][File](by-class/File.md).

// UID:0003H1 | by-type/by-struct/FileBaseLayout.md | Completion:92 | Confidence:94
// File storage is declared by [UID:00004V][File](by-class/File.md); this layout page emits no standalone code.

// UID:0003HZ | by-type/by-vtable/FileVtable.md | Completion:92 | Confidence:94
// Emitted code for this vtable is covered by [UID:00004V][File](by-class/File.md).

// UID:00012I | by-memory/0x0049d390-0x0049d3cd.FileBaseDestructor.md | Completion:90 | Confidence:94
// Compiler-generated scalar deleting destructor for File; source destruction is covered by [UID:00004V][File](by-class/File.md).
