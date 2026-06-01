*** UID:0000Q0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_frameRegistry

## Status

- Symbol kind: singleton pointer/global data.
- Address: `0x0069ae10` in IDA as `dword_69AE10`.
- Current generated names: `g_frameRegistry`, `g_pIdleDispatchQueue`, `dword_69AE10`.
- Likely owner: [UID:0000JM][FrameMgr](by-file/FrameMgr.md).
- Confidence: strong for role, medium for final source-level spelling.

## Role

`g_frameRegistry` points to the process-wide [UID:00005H][FrameMgr](by-class/FrameMgr.md) instance. Frame handlers use it to insert or remove scheduled frame callbacks, and the message-loop idle worker uses it to dispatch callbacks for the current 20-tick slice.

`g_pIdleDispatchQueue` appears in active `ApplicationHelper_4A6C40` output as a descriptive alias for the same pointer. Prefer `g_frameRegistry` when documenting `FrameMgr` ownership, and treat `g_pIdleDispatchQueue` as a caller-context alias until source-line evidence proves the original spelling.

## Evidence

- IDA decompilation of `FrameMgr::FrameMgr` at `0x004b6dc0` writes `dword_69AE10 = this` after constructing the `LObject` base.
- IDA decompilation of `FrameMgr::ScalarDeletingDestructor` at `0x004b70c0` clears `dword_69AE10 = 0`.
- IDA xrefs on 2026-05-26 include [UID:000142][0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler](by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md) at `0x004a6cc9`, `FrameHandler` wrappers at `0x004b6d00`, `0x004b6d20`, `0x004b6d30`, and `FrameMgr` construction/destruction at `0x004b6dc0` and `0x004b70c0`.
- Active `class_FrameMgr.cpp` and `class_FrameHandler.cpp` use `g_frameRegistry`; active `class_ApplicationHelper_4A6C40.cpp` uses `g_pIdleDispatchQueue`.

## Cross-References

- [UID:0000JM][FrameMgr](by-file/FrameMgr.md)
- [UID:00005H][FrameMgr](by-class/FrameMgr.md)
- [UID:00005G][FrameHandler](by-class/FrameHandler.md)
- [UID:00015M][0x004b6cb0-0x004b7112.FrameScheduler](by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md)
- [UID:000142][0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler](by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/80`. Summary/evidence: the page documents address, generated aliases, singleton role, constructor/destructor writes, application idle use, FrameMgr ownership, and cross refs; final source-level spelling remains provisional.
