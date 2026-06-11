*** UID:0000QX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JH | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pFontImageLib

## Status

- Confidence: strong for address and owner, medium for final original symbol spelling.
- Kind: process-wide singleton pointer.
- Backing storage: [UID:0001P2][0x0067ab24-0x0067ab28.g_pFontImageLib](by-memory/0x0067ab24-0x0067ab28.g_pFontImageLib.md), IDA `dword_67AB24`.
- Canonical owner: [UID:00005B][FontImageLib](by-class/FontImageLib.md) in [UID:0000JH][FontImageLib](by-file/FontImageLib.md).
- Alias caveat: some text consumers may appear under adjacent or raw pointer names in recovered views even though IDA shows they read `dword_67AB24`.

## Meaning

`g_pFontImageLib` is the global pointer to the bitmap font/glyph image library. It is constructed during `Application::Initialize`, then read by GrafPort text helpers and UI controls that need glyph metrics, line height, per-glyph width, or decoded glyph pixels.

Keep this global with `render/FontImageLib.cpp`. Callers that only measure or draw text should not own the singleton storage.

## Write Evidence

IDA MCP on 2026-05-26 confirms these write/clear sites:

| Address | Function | Meaning |
| --- | --- | --- |
| `0x004b5f24` | `FontImageLib::FontImageLib` | Stores the constructed `FontImageLib*` singleton. |
| `0x004b5fc5` | [UID:00015B][0x004b5f60-0x004b5fe6.FontImageLibDestructor](by-memory/0x004b5f60-0x004b5fe6.FontImageLibDestructor.md) | Clears the singleton during non-deleting cleanup. |
| `0x004b63c0` | `FontImageLib::ScalarDeletingDestructor` | Clears the singleton during deleting cleanup. |

The static file image currently reads as `0xffffffff` at `0x0067ab24`; runtime constructor/destructor behavior still proves this storage is the live singleton pointer.

## Consumer Evidence

Representative readers include:

- [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md), especially `MeasureTextWidth` and `GetLineHeight`.
- [UID:00016I][0x004bb5e0-0x004bb7df.GrafPortDrawGlyph](by-memory/0x004bb5e0-0x004bb7df.GrafPortDrawGlyph.md), which calls `FontImageLib::MeasureGlyphWidth` and `GetFontMetrics`.
- `ClanItemListPane`, `TextButtonControlPane`, `TextEditPane`, fitting-room download controls, balloon text, and other UI text paths that need font metrics.
- `Application::CleanupResources` at `0x00464bd7`, which checks the pointer and dispatches the virtual deleting destructor.

## Ownership Decision

`g_pFontImageLib` is source-owned by `FontImageLib`, not by `GrafPort`, `DirectX`, `TextButtonControlPane`, or individual UI controls. Font measurement paths should be checked against the concrete storage address; only sites that read `0x0067ab24` are consumers of this singleton.

## Cross-References

- [UID:0000JH][FontImageLib](by-file/FontImageLib.md)
- [UID:00005B][FontImageLib](by-class/FontImageLib.md)
- [UID:00015A][0x004b5f00-0x004b6409.FontImageLib](by-memory/0x004b5f00-0x004b6409.FontImageLib.md)
- [UID:0001P2][0x0067ab24-0x0067ab28.g_pFontImageLib](by-memory/0x0067ab24-0x0067ab28.g_pFontImageLib.md)
- [UID:0001XM][FontImageLibVtable](by-type/by-vtable/FontImageLibVtable.md)
- [UID:0001UL][FontImageLibLayout](by-type/by-struct/FontImageLibLayout.md)
- [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/82`. Summary/evidence: the page documents backing storage, owner, bitmap-font role, constructor/destructor writes, text/render consumers, ownership decision, and alias caveat; final original symbol spelling remains medium-confidence.
- 2026-06-05: Marked reconstructable under [UID:0000JH][FontImageLib](by-file/FontImageLib.md). Evidence: live IDA MCP reports 52 xrefs to `0x0067ab24`; decompilation confirms `0x004b5f00` writes `dword_67AB24`, while `0x004b5f60` and `0x004b6350` clear it from `FontImageLib` destructor paths.
