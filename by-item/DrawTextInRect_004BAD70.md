*** UID:0000UJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DrawTextInRect 0x004BAD70

## Status

- Promotion status: retained by-item index only.
- Canonical code-bearing documentation: [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md).
- Canonical source route: [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md) -> [UID:00005V][GrafPort](by-class/GrafPort.md) -> [UID:0000JR][GrafPort](by-file/GrafPort.md).
- Previous by-item state: `COMPLETION:80`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, parent blank.
- Current by-item state: `COMPLETION:-1`, `CONFIDENCE:-1`, `RECONSTRUCTABLE:FALSE`, parent blank, because this page no longer owns reconstruction output.
- Strict gate status: the source-owning exact child is `86/90`, the actual direct class parent is `85/87`, and the file parent is `88/85`; the gate is already satisfied on the canonical by-memory route.

## Behavior

`DrawTextInRect` renders multi-line text inside a rectangle. It saves and restores the current text position, queries font line advance, splits text into lines that fit the rectangle width, applies left/center/right alignment, and advances through wrapped lines until the vertical bounds are exceeded.

## Ownership Boundary

This by-item page is not the owner. It remains only as the historical item-coverage entry for `DrawTextInRect_004BAD70`.

The source-owning page is the exact by-memory child [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md). That page is already attached to the actual direct parent [UID:00005V][GrafPort](by-class/GrafPort.md), with [UID:0000JR][GrafPort](by-file/GrafPort.md) as the file root. Routing this by-item page too would create duplicate reconstruction ownership for the same function.

The earlier [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md) association is retained only as a historical/generated-output lead. `TextButtonControlPane::OnPaint` is one caller among a broad UI/render caller set, not the source owner.

## Evidence

- 2026-05-30 live IDA MCP reports `sub_4BAD70` at `0x004bad70-0x004baf92` with 130 direct callers across UI/message/drawing code.
- The function calls [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md), reads font/global state through `dword_67AB24`, and calls [UID:00015A][0x004b5f00-0x004b6409.FontImageLib](by-memory/0x004b5f00-0x004b6409.FontImageLib.md) subrange `0x004b5ff0` for font metrics / line advance.
- The wrapping pass calls [UID:00016B][0x004ba820-0x004ba991.TextFitAndSuffixHelpers](by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md) subrange `0x004ba8b0` to count the next fitting text slice, then copies that slice through [UID:0001BH][0x00516220-0x00516238.MemmoveWrapper](by-memory/0x00516220-0x00516238.MemmoveWrapper.md).
- The alignment pass uses [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md) subrange `0x004ba9a0` to measure rendered width, then draws each line through the same text-run helper family at `0x004bab70`.
- IDA instructions at `0x004bae79-0x004bae86` bound the copied line buffer to `0x200` bytes before null-termination, with the compiler range-check failure path at `0x004baf8d`.
- Caller samples include `0x00424247`, `0x00483837`, `0x0049a3eb`, five calls in `0x004bafa0`, and many calls from the large UI formatter at `0x004c8bd0`, supporting shared ownership rather than text-button-private ownership.
- Additional documented caller families include fitting-room text-button paint, color-string chat message rendering, radio-group option paint, simple help text effects, help-pane setup, and spell-inventory rendering. That breadth supports a shared draw-port helper while keeping the exact source file unresolved.

## Cross-References

- [UID:0000OK][TextButtonControlPane](by-file/TextButtonControlPane.md)
- [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md)
- [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md)
- [UID:0000JR][GrafPort](by-file/GrafPort.md)
- [UID:0000IG][ControlPane](by-file/ControlPane.md)
- [UID:0000JH][FontImageLib](by-file/FontImageLib.md)

## Changes

- 2026-06-12 A003 Batch 305 promotion cleanup:
  - Before: `COMPLETION:80`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, `AUTOGEN_PARENT_UID:` blank.
  - After: `COMPLETION:-1`, `CONFIDENCE:-1`, `RECONSTRUCTABLE:FALSE`, `AUTOGEN_PARENT_UID:` blank.
  - Summary/evidence: by-item guidance says to promote temporary item pages into a more specific `by-*` folder once ownership is clear. The exact code-bearing page [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md) is already the canonical reconstruction document and is assigned to [UID:00005V][GrafPort](by-class/GrafPort.md) after A004 Batch 119. The canonical child is `86/90`, direct class parent [UID:00005V][GrafPort](by-class/GrafPort.md) is `85/87`, and file parent [UID:0000JR][GrafPort](by-file/GrafPort.md) is `88/85`, so the strict gate is satisfied there. This by-item page is retained only as a non-emitting index to avoid duplicate source output.

- 2026-06-07 A009 ownership-boundary sync:
  - Changed to: `COMPLETION:80`, `CONFIDENCE:86`.
  - Summary/evidence: synchronized this item with the current `GrafPort` and `TextButtonControlPane` file pages. `GrafPort` now carries this helper as part of the shared text-drawing review family, while `TextButtonControlPane` explicitly treats its old ownership as historical/generated and caller-biased. Existing memory pages document non-button callers from chat messages, radio options, fitting-room paint, help text, help panes, and spell inventory. Parent/C++ metadata stay blank because final source split and receiver field names are not recovered to reconstruction level.

- 2026-06-03 score sync with exact memory page:
  - Before: the item page remained `68/82` with blank reconstructable metadata after the exact memory page had been revalidated.
  - After: set to `76/84` and `RECONSTRUCTABLE:TRUE`, while leaving parent metadata blank.
  - Summary/evidence: [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](by-memory/0x004bad70-0x004baf92.DrawTextInRect.md) records the restarted IDA MCP boundary check, 130 direct callers, concrete callee list, draw-state offsets, bounded stack-line copy, range-check path, and post-function padding. Parent remains blank because ownership is still a GrafPort/shared-text decision rather than a proven final source attachment.

- What existed before: The page had `0` completion/confidence and cited generated metadata plus a generated owner path as the main evidence.
- What it was changed to: The page now scores the helper from live IDA MCP evidence, records the exact range, caller fanout, concrete callees, buffer bound, and the current owner caveat.
- Summary and evidence: IDA confirms `sub_4BAD70` at `0x004bad70-0x004baf92`, 130 direct callers, calls to `0x004b5ff0`, `0x004ba8b0`, `0x004ba9a0`, `0x004bab70`, `0x00516030`, and `0x00516220`, and the bounded line-copy path around `0x004bae79`.
