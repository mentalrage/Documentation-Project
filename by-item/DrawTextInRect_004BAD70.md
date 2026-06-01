*** UID:0000UJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DrawTextInRect 0x004BAD70

## Status

- Confidence: strong for behavior, medium for final owner.
- Entity kind: shared UI text helper.
- Likely source module: [UID:0000JR][GrafPort](by-file/GrafPort.md) / generic text-render helper. The earlier [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md) assignment should be treated as caller-biased until a source-file split is proven.
- Exact range: `0x004bad70-0x004baf92`

## Behavior

`DrawTextInRect` renders multi-line text inside a rectangle. It saves and restores the current text position, queries font line advance, splits text into lines that fit the rectangle width, applies left/center/right alignment, and advances through wrapped lines until the vertical bounds are exceeded.

## Evidence

- 2026-05-30 live IDA MCP reports `sub_4BAD70` at `0x004bad70-0x004baf92` with 130 direct callers across UI/message/drawing code.
- The function calls [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md), reads font/global state through `dword_67AB24`, and calls [UID:00015A][0x004b5f00-0x004b6409.FontImageLib](by-memory/0x004b5f00-0x004b6409.FontImageLib.md) subrange `0x004b5ff0` for font metrics / line advance.
- The wrapping pass calls [UID:00016B][0x004ba820-0x004ba991.TextFitAndSuffixHelpers](by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md) subrange `0x004ba8b0` to count the next fitting text slice, then copies that slice through [UID:0001BH][0x00516220-0x00516238.MemmoveWrapper](by-memory/0x00516220-0x00516238.MemmoveWrapper.md).
- The alignment pass uses [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md) subrange `0x004ba9a0` to measure rendered width, then draws each line through the same text-run helper family at `0x004bab70`.
- IDA instructions at `0x004bae79-0x004bae86` bound the copied line buffer to `0x200` bytes before null-termination, with the compiler range-check failure path at `0x004baf8d`.
- Caller samples include `0x00424247`, `0x00483837`, `0x0049a3eb`, five calls in `0x004bafa0`, and many calls from the large UI formatter at `0x004c8bd0`, supporting shared ownership rather than text-button-private ownership.

## Cross-References

- [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md)
- [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md)
- [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md)
- [UID:0000JR][GrafPort](by-file/GrafPort.md)
- [UID:0000IG][ControlPane](by-file/ControlPane.md)
- [UID:0000JH][FontImageLib](by-file/FontImageLib.md)

## Changes

- What existed before: The page had `0` completion/confidence and cited generated metadata plus a generated owner path as the main evidence.
- What it was changed to: The page now scores the helper from live IDA MCP evidence, records the exact range, caller fanout, concrete callees, buffer bound, and the current owner caveat.
- Summary and evidence: IDA confirms `sub_4BAD70` at `0x004bad70-0x004baf92`, 130 direct callers, calls to `0x004b5ff0`, `0x004ba8b0`, `0x004ba9a0`, `0x004bab70`, `0x00516030`, and `0x00516220`, and the bounded line-copy path around `0x004bae79`.
