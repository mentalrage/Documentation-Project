*** UID:0001UI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FittingRoomDownloadProgressState

## Status

- Entity kind: inferred private POD-style progress state.
- Likely owner: [UID:0000JE][FittingRoom](by-file/FittingRoom.md), near [UID:000050][FittingRoomDialog](by-class/FittingRoomDialog.md) and [UID:000052][FittingRoomDownloadControlPane](by-class/FittingRoomDownloadControlPane.md).
- Memory evidence: split/index parent [UID:0000WG][0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers](by-memory/0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers.md), reset children [UID:0004G9][0x0041a550-0x0041a564.FittingRoomDownloadProgressStateResetPrimary](by-memory/0x0041a550-0x0041a564.FittingRoomDownloadProgressStateResetPrimary.md) and [UID:0004GC][0x0041a5a0-0x0041a5b4.FittingRoomDownloadProgressStateResetSecondary](by-memory/0x0041a5a0-0x0041a5b4.FittingRoomDownloadProgressStateResetSecondary.md), no-op children [UID:0004GA][0x0041a570-0x0041a571.FittingRoomDownloadProgressStateNullPrimary](by-memory/0x0041a570-0x0041a571.FittingRoomDownloadProgressStateNullPrimary.md) and [UID:0004GD][0x0041a5c0-0x0041a5c1.FittingRoomDownloadProgressStateNullSecondary](by-memory/0x0041a5c0-0x0041a5c1.FittingRoomDownloadProgressStateNullSecondary.md), and source-ready percent child [UID:0004GB][0x0041a580-0x0041a592.FittingRoomDownloadProgressStateCalculatePercent](by-memory/0x0041a580-0x0041a592.FittingRoomDownloadProgressStateCalculatePercent.md).
- Confidence: strong for the 12-byte helper layout and direct fitting-room owner; medium for final type name inside the larger request record.
- Reconstructable: true, because IDA confirms this is NexusTK fitting-room request/progress state rather than external/runtime code. The type attaches directly to [UID:0000JE][FittingRoom](by-file/FittingRoom.md) after this child reaches `85/90` and the file parent already clears the strict gate at `85/87`. C++ remains blank because the containing request-record declaration and final member names are not final-source quality; the isolated percent method body is now carried by child [UID:0004GB][0x0041a580-0x0041a592.FittingRoomDownloadProgressStateCalculatePercent](by-memory/0x0041a580-0x0041a592.FittingRoomDownloadProgressStateCalculatePercent.md).

## Layout Hypothesis

| Offset | Size | Meaning |
| --- | --- | --- |
| `+0x00` | 1 | active/valid byte tested by `FittingRoomDialog::HandleFittingAction` before loading the completed state buffer. |
| `+0x04` | 4 | total/denominator value for progress percentage. |
| `+0x08` | 4 | current/numerator value for progress percentage. |

The reset children [UID:0004G9][0x0041a550-0x0041a564.FittingRoomDownloadProgressStateResetPrimary](by-memory/0x0041a550-0x0041a564.FittingRoomDownloadProgressStateResetPrimary.md) and [UID:0004GC][0x0041a5a0-0x0041a5b4.FittingRoomDownloadProgressStateResetSecondary](by-memory/0x0041a5a0-0x0041a5b4.FittingRoomDownloadProgressStateResetSecondary.md) clear offsets `+0x00`, `+0x04`, and `+0x08` but remain non-emitting no-route helpers. [UID:0004GB][0x0041a580-0x0041a592.FittingRoomDownloadProgressStateCalculatePercent](by-memory/0x0041a580-0x0041a592.FittingRoomDownloadProgressStateCalculatePercent.md) returns `0` when the denominator is zero; otherwise it returns `(current * 100) / total` truncated to a byte and emits the source-facing `FittingRoomDownloadProgressState::GetPercent()` body through [UID:0000JE][FittingRoom](by-file/FittingRoom.md).

In the observed request object, [UID:0002CT][0x0041cb70-0x0041cd38.FittingRoomDialogHandleFittingAction](by-memory/0x0041cb70-0x0041cd38.FittingRoomDialogHandleFittingAction.md) passes request offset `+0x04` as this struct's receiver. That places this exact `0x0c` state at request offsets `+0x04..+0x10`, with the encoded state buffer/string reference beginning at request offset `+0x10` and therefore outside this type.

## Evidence

- IDA MCP decompilation of `0x0041a550` and `0x0041a5a0` shows identical initializer/reset bodies over byte `+0x00`, dword `+0x04`, and dword `+0x08`.
- IDA MCP decompilation of `0x0041a580` shows the percentage calculation.
- IDA MCP caller evidence places the percentage helper in `FittingRoomDialog::HandleFittingAction` at `0x0041cbbc`, using a request/state pointer plus `4` as the receiver.
- `HandleFittingAction` compares the returned byte with a progress/region-code byte in the avatar/progress child and refreshes the child when it changes.
- Current generated `class_Region.cpp` ownership is polluted: the `0x0041a580` helper is not the UI dirty-rectangle [UID:0000BV][Region](by-class/Region.md) documented at `0x00554680-0x00554b38`.
- 2026-05-31 IDA MCP recheck confirms exact helper starts and sizes: `0x0041a550` size `0x14`, `0x0041a570` size `0x1`, `0x0041a580` size `0x12`, `0x0041a5a0` size `0x14`, and `0x0041a5c0` size `0x1`.
- 2026-05-31 IDA MCP xrefs confirm `0x0041a580` has one direct code xref, from `0x0041cbbc` inside `0x0041cb70-0x0041cd38`. The sibling reset/null helpers currently have no direct xrefs, so the containing request-record constructor/destructor boundary remains below final-source confidence.
- 2026-05-31 IDA MCP disassembly of `0x0041cb70` shows `this + 0x704` as the request pointer, `add ecx, 4`, `call 0x0041a580`, storing the returned byte to the child control byte at `+0x108`, and treating values `>= 100` as completion.
- 2026-06-11 IDA MCP recheck reconfirmed the same five helper records: `0x0041a550` size `0x14`, `0x0041a570` size `0x1`, `0x0041a580` size `0x12`, `0x0041a5a0` size `0x14`, and `0x0041a5c0` size `0x1`.
- 2026-06-11 decompilation again shows both reset helpers clearing byte `+0x00`, dword `+0x04`, and dword `+0x08`, while `0x0041a580` divides `100 * this[2]` by `this[1]` and returns zero when the denominator is zero.
- 2026-06-11 callers/xrefs/callees checks report no callees for all five helpers, no direct callers or xrefs for the two reset helpers and two null helpers, and exactly one direct caller/xref for `0x0041a580`: `0x0041cbbc` inside [UID:0002CT][0x0041cb70-0x0041cd38.FittingRoomDialogHandleFittingAction](by-memory/0x0041cb70-0x0041cd38.FittingRoomDialogHandleFittingAction.md).
- 2026-06-11 `HandleFittingAction` decompilation confirms the caller obtains child control id `7`, calls the percent helper with `request + 4`, stores the returned byte into the child at `+0x108` when changed, invalidates the child through virtual slot `+0x20`, tests the active byte at request `+0x04`, and copies the completed request buffer from request `+0x10`.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `85` | The page now records the exact 12-byte layout, duplicate reset helpers, percent helper arithmetic, no-callee/no-xref status for sibling helpers, the sole percent-helper caller, the request-record embedding offset, and the strict-gate parent assignment to [UID:0000JE][FittingRoom](by-file/FittingRoom.md). Completion remains capped because the containing request-record type and final source-facing field names are still provisional. |
| Confidence `90` | Confidence is strong because live IDA lookup, decompilation, caller/xref, and callee evidence agree with [UID:0000WG][0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers](by-memory/0x0041a550-0x0041a5c1.FittingRoomDownloadProgressStateHelpers.md) and [UID:0002CT][0x0041cb70-0x0041cd38.FittingRoomDialogHandleFittingAction](by-memory/0x0041cb70-0x0041cd38.FittingRoomDialogHandleFittingAction.md). It is not higher because final request-record naming and the two unreferenced reset/null helper source roles remain unresolved. |

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
- 2026-06-11 A005 Batch145:
  - What existed before: the struct remained at `74/87` and unassigned even though the related helper and fitting-room file parent had since cleared the strict gate.
  - Changed to: raised to `85/90`, assigned to [UID:0000JE][FittingRoom](by-file/FittingRoom.md), documented the request offset `+0x04..+0x10` embedding, added current IDA MCP lookup/decompile/caller/xref/callee evidence, and added an explicit score rationale.
  - Summary/evidence: live IDA reconfirmed the five helper starts, zero-callee helper island, only one percent-helper xref at `0x0041cbbc`, and `HandleFittingAction` use of request `+0x04` for progress and request `+0x10` for the completed buffer. C++ remains blank because the surrounding request record is still not final-source quality.
- 2026-07-03 B006 split-first implementation callback:
  - What changed: UID0000WG is now a non-emitting split/index parent with exact child pages [UID:0004G9][0x0041a550-0x0041a564.FittingRoomDownloadProgressStateResetPrimary](by-memory/0x0041a550-0x0041a564.FittingRoomDownloadProgressStateResetPrimary.md), [UID:0004GA][0x0041a570-0x0041a571.FittingRoomDownloadProgressStateNullPrimary](by-memory/0x0041a570-0x0041a571.FittingRoomDownloadProgressStateNullPrimary.md), [UID:0004GB][0x0041a580-0x0041a592.FittingRoomDownloadProgressStateCalculatePercent](by-memory/0x0041a580-0x0041a592.FittingRoomDownloadProgressStateCalculatePercent.md), [UID:0004GC][0x0041a5a0-0x0041a5b4.FittingRoomDownloadProgressStateResetSecondary](by-memory/0x0041a5a0-0x0041a5b4.FittingRoomDownloadProgressStateResetSecondary.md), and [UID:0004GD][0x0041a5c0-0x0041a5c1.FittingRoomDownloadProgressStateNullSecondary](by-memory/0x0041a5c0-0x0041a5c1.FittingRoomDownloadProgressStateNullSecondary.md). The type page now names [UID:0004GB][0x0041a580-0x0041a592.FittingRoomDownloadProgressStateCalculatePercent](by-memory/0x0041a580-0x0041a592.FittingRoomDownloadProgressStateCalculatePercent.md) as the source-ready percent method and keeps the reset/no-op children as no-route/non-emitting evidence.
  - Summary/evidence: B006 MCP session `c9b60f19` confirms the same field layout, exact reset/null/percent child ranges, sole percent xref at `0x0041cbbc`, request `+0x04` receiver, child `+0x108` progress write, and reset/no-op no-route proof.
