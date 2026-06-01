*** UID:0001UI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FittingRoomDownloadProgressState

## Status

- Entity kind: inferred private POD-style progress state.
- Likely owner: [UID:0000JE][FittingRoom](by-file/FittingRoom.md), near [UID:000050][FittingRoomDialog](by-class/FittingRoomDialog.md) and [UID:000052][FittingRoomDownloadControlPane](by-class/FittingRoomDownloadControlPane.md).
- Memory evidence: [UID:0000WG][0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers](by-memory/0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers.md).
- Confidence: strong for the 12-byte helper layout; medium for final type name and containing request-record boundary.
- Reconstructable: true, because IDA confirms this is NexusTK fitting-room request/progress state rather than external/runtime code. Parent/code autogen is intentionally blank until the full request-record owner and final source shape are better proven.

## Layout Hypothesis

| Offset | Size | Meaning |
| --- | --- | --- |
| `+0x00` | 1 | active/valid byte tested by `FittingRoomDialog::HandleFittingAction` before loading the completed state buffer. |
| `+0x04` | 4 | total/denominator value for progress percentage. |
| `+0x08` | 4 | current/numerator value for progress percentage. |

The helpers clear offsets `+0x00`, `+0x04`, and `+0x08`. `GetUsagePercent` returns `0` when the denominator is zero; otherwise it returns `(current * 100) / total` truncated to a byte.

## Evidence

- IDA MCP decompilation of `0x0041a550` and `0x0041a5a0` shows identical initializer/reset bodies over byte `+0x00`, dword `+0x04`, and dword `+0x08`.
- IDA MCP decompilation of `0x0041a580` shows the percentage calculation.
- IDA MCP caller evidence places the percentage helper in `FittingRoomDialog::HandleFittingAction` at `0x0041cbbc`, using a request/state pointer plus `4` as the receiver.
- `HandleFittingAction` compares the returned byte with a progress/region-code byte in the avatar/progress child and refreshes the child when it changes.
- Current generated `class_Region.cpp` ownership is polluted: the `0x0041a580` helper is not the UI dirty-rectangle [UID:0000BV][Region](by-class/Region.md) documented at `0x00554680-0x00554b38`.
- 2026-05-31 IDA MCP recheck confirms exact helper starts and sizes: `0x0041a550` size `0x14`, `0x0041a570` size `0x1`, `0x0041a580` size `0x12`, `0x0041a5a0` size `0x14`, and `0x0041a5c0` size `0x1`.
- 2026-05-31 IDA MCP xrefs confirm `0x0041a580` has one direct code xref, from `0x0041cbbc` inside `0x0041cb70-0x0041cd38`. The sibling reset/null helpers currently have no direct xrefs, so the containing request-record constructor/destructor boundary remains below final-source confidence.
- 2026-05-31 IDA MCP disassembly of `0x0041cb70` shows `this + 0x704` as the request pointer, `add ecx, 4`, `call 0x0041a580`, storing the returned byte to the child control byte at `+0x108`, and treating values `>= 100` as completion.

## Cross-References

- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:000050][FittingRoomDialog](by-class/FittingRoomDialog.md)
- [UID:000052][FittingRoomDownloadControlPane](by-class/FittingRoomDownloadControlPane.md)
- [UID:0000WG][0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers](by-memory/0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers.md)
- [UID:0000BV][Region](by-class/Region.md)

## Changes

- 2026-05-31:
  - What existed before: the page had useful evidence but was still scored `0/0` with `RECONSTRUCTABLE` blank.
  - Changed to: scored `74/87`, marked reconstructable, and added a fresh IDA MCP recheck of helper starts, xrefs, decompilation, and caller disassembly.
  - Summary/evidence: IDA confirms the 12-byte state shape and the fitting-room caller context. The final request-record owner, source-facing type name, and reset/null helper ownership are still not strong enough for `95+` scoring or autogen C++ attachment.
