*** UID:0000UK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DrawTextRunCallback 0x00593DB0

## Status

- Confidence: strong.
- Entity: global function `DrawTextRunCallback`
- Range: `0x00593db0-0x00593ef6` in IDA end-exclusive form; last instruction is `0x00593ef5`.
- Likely source file: [UID:0000ON][TextEditPane](by-file/TextEditPane.md)

## Purpose

`DrawTextRunCallback` is the per-run callback used by `TextEditPane::IterateTextRuns`. It prepares the visible line rectangle, intersects it with the pane clip region, swaps temporary drawing state, applies run color/effect state, trims trailing whitespace for right-aligned final segments, and forwards the final UTF-16 slice into the existing text renderer.

## Evidence Notes

- Live IDA evidence shows it is address-taken as a callback, not directly called as a member method. A source-facing callback shape consistent with the stack arguments is:

```text
char __cdecl DrawTextRunCallback(TextRunLineRecord* lineRecord,
                                 TextRunStyleData* styleData,
                                 const wchar_t* text,
                                 int startOffset,
                                 unsigned short length,
                                 unsigned int flags,
                                 TextRunDrawState* drawState,
                                 TextEditPane* pane)
```

- 2026-05-30 live IDA MCP reports the function object as `sub_593DB0`, `0x00593db0-0x00593ef6`, size `326`.
- Live IDA xrefs to the callback address are two address-taking pushes: `0x005908e6` inside `sub_590810` and `0x0059168c` in the adjacent text-edit selection/invalidation region. Both use `push offset sub_593DB0`.
- Live IDA callees are [UID:000164][0x004b96c0-0x004b9767.GrafPortClipRectHelper](by-memory/0x004b96c0-0x004b9767.GrafPortClipRectHelper.md), [UID:00015S][0x004b7c30-0x004b7f87.RectGeometryHelpers](by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md) subrange `0x004b7cc0`, [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md), [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md) subranges `0x004baaa0` and `0x004baad0`, callback slot [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) `dword_69B3FC`, and lower text renderer `0x005946b0`.
- The sibling [UID:0001JQ][0x00593c20-0x00593ce4.TextRunMeasureCallback](by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md) handles row-width measurement for the same text-run iteration family.

## Ownership Decision

Treat this as a file-local/free helper in `TextEditPane.cpp`. Its only known live purpose is servicing the editor's run iterator, but the calling convention and callback shape are not a `TextEditPane` member function.

## Cross-References

- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0000EO][TextEditPane](by-class/TextEditPane.md)
- [UID:0001JQ][0x00593c20-0x00593ce4.TextRunMeasureCallback](by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md)
- [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md)
- [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md)
- [UID:000164][0x004b96c0-0x004b9767.GrafPortClipRectHelper](by-memory/0x004b96c0-0x004b9767.GrafPortClipRectHelper.md)
- [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md)
- [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md)

## Changes

- What existed before: The page had `0` completion/confidence and used generated import/recovered-file statements as evidence.
- What it was changed to: The page now records live IDA MCP function extent, address-taking callback xrefs, concrete callees, and the callback-source ownership decision.
- Summary and evidence: IDA confirms `sub_593DB0` at `0x00593db0-0x00593ef6`, two `push offset sub_593DB0` xrefs at `0x005908e6` and `0x0059168c`, and outgoing calls through `0x004b96c0`, `0x004b7cc0`, `0x004b9660`, `0x004b9680`, `0x004baaa0`, `0x004baad0`, `dword_69B3FC`, and `0x005946b0`.
