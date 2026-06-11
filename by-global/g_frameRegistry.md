*** UID:0000Q0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_frameRegistry

## Status

- Symbol kind: singleton pointer/global data.
- Address: `0x0069ae10` in IDA as `dword_69AE10`.
- Observed aliases: `g_frameRegistry`, `g_pIdleDispatchQueue`, `dword_69AE10`.
- Likely owner: [UID:0000JM][FrameMgr](by-file/FrameMgr.md).
- Confidence: strong for role, exact storage, lifecycle writes/clears, scheduler ownership, and direct file parent; medium-high for final source-level spelling.

## Role

`g_frameRegistry` points to the process-wide [UID:00005H][FrameMgr](by-class/FrameMgr.md) instance. Frame handlers use it to insert or remove scheduled frame callbacks, and the message-loop idle worker uses it to dispatch callbacks for the current 20-tick slice.

`g_pIdleDispatchQueue` appears as a descriptive alias for the same pointer in the idle-dispatch notes. Prefer `g_frameRegistry` when documenting `FrameMgr` ownership, and treat `g_pIdleDispatchQueue` as a caller-context alias until source-line evidence proves the original spelling.

## Evidence

- IDA decompilation of `FrameMgr::FrameMgr` at `0x004b6dc0` writes `dword_69AE10 = this` after constructing the `LObject` base.
- IDA decompilation of `FrameMgr::ScalarDeletingDestructor` at `0x004b70c0` clears `dword_69AE10 = 0`.
- IDA xrefs on 2026-05-26 include [UID:000142][0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler](by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md) at `0x004a6cc9`, `FrameHandler` wrappers at `0x004b6d00`, `0x004b6d20`, `0x004b6d30`, and `FrameMgr` construction/destruction at `0x004b6dc0` and `0x004b70c0`.
- The live xref set ties the storage to `FrameMgr`, `FrameHandler`, and the application idle scheduler rather than frame-chrome drawing or world-map-only animation code.
- [UID:0002AT][0x0069ae10-0x0069ae14.g_frameRegistry](by-memory/0x0069ae10-0x0069ae14.g_frameRegistry.md) records the exact four-byte `.data` slot, static bytes `ff ff ff ff`, 13 direct xrefs, constructor publish/fallback clear, raw cleanup helper clear, one-instruction clear helper, scalar-deleting-destructor clear, and application/EventDispatcher reader paths.
- [UID:00015M][0x004b6cb0-0x004b7112.FrameScheduler](by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md) records the scheduler aggregate as `85/90`, all handler/manager method endpoints, and dispatch from [UID:000142][0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler](by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md).
- [UID:0001QU][client_timing](by-meta/client_timing.md) records the timing-model split: `FrameMgr` schedules frame-count callbacks, while `TimerMgr` dispatches time-based callbacks. This keeps the global out of visible frame-chrome or audio timing ownership.
- No fresh live IDA call was attempted for this page during the 2026-06-11 A001 pass after the previous target's MCP requests timed out. This update relies on the written live-IDA evidence already present in the exact storage, scheduler, class, file, and timing pages.

## User And Lifecycle Summary

| Evidence point | Current conclusion |
| --- | --- |
| Exact storage | `0x0069ae10-0x0069ae14`, four-byte `.data` pointer, IDA `dword_69AE10`. |
| Constructor publish | `0x004b6e03` writes the constructed [UID:00005H][FrameMgr](by-class/FrameMgr.md) instance to the singleton; `0x004b6e0a` is the constructor fallback clear. |
| Destruction/cleanup | `0x004b6e83`, `0x004b70b0`, and `0x004b70d6` clear the singleton in cleanup/destructor paths. |
| FrameHandler users | `0x004b6cd9`, `0x004b6d02`, `0x004b6d21`, `0x004b6d35`, and `0x004b6d7b` unregister or schedule handlers through the registry. |
| Application/EventDispatcher users | `0x004a6bfa`, `0x004a6cc9`, and `0x004a7e0c` read the registry during idle/cleanup work; the idle scheduler dispatches elapsed `0x14` / decimal `20` tick frame slices (Verified with `int_convert.py`). |
| Rejected owners | FrameChrome/art panes, WorldMap-only animation, and TimerMgr are consumers or neighboring timing systems, not owners of this singleton. |

## Assignment Decision

Keep `AUTOGEN_PARENT_UID:0000JM` on [UID:0000JM][FrameMgr](by-file/FrameMgr.md). This global now clears `88/86`, and the direct file parent is `85/86`, so the strict child/direct-parent `85/85` gate is satisfied.

Do not attach the global directly to the [UID:00005H][FrameMgr](by-class/FrameMgr.md) class page for this pass. The storage is module-scope singleton state for the scheduler file; class and vtable pages document the object type and method bodies, while the file owns the source-level global declaration and lifecycle wrapper policy.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 88 | Exact address, aliases, singleton role, lifecycle writes/clears, direct xref families, storage child, scheduler aggregate, timing-model separation, rejected-owner rationale, and strict parent gate are documented. |
| Confidence | 86 | Supporting pages contain live IDA evidence for storage, xrefs, constructor/destructor behavior, and scheduler ownership. Confidence stays below higher scores because this pass did not add a fresh live-IDB recheck, and final original symbol spelling versus alias wording remains unresolved. |

## Cross-References

- [UID:0000JM][FrameMgr](by-file/FrameMgr.md)
- [UID:00005H][FrameMgr](by-class/FrameMgr.md)
- [UID:00005G][FrameHandler](by-class/FrameHandler.md)
- [UID:00015M][0x004b6cb0-0x004b7112.FrameScheduler](by-memory/0x004b6cb0-0x004b7112.FrameScheduler.md)
- [UID:000142][0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler](by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md)
- [UID:0002AT][0x0069ae10-0x0069ae14.g_frameRegistry](by-memory/0x0069ae10-0x0069ae14.g_frameRegistry.md)
- [UID:0001QU][client_timing](by-meta/client_timing.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/80`. Summary/evidence: the page documents address, aliases, singleton role, constructor/destructor writes, application idle use, FrameMgr ownership, and cross refs; final source-level spelling remains provisional.
- 2026-06-05: Marked reconstructable under [UID:0000JM][FrameMgr](by-file/FrameMgr.md). Evidence: live IDA MCP xrefs to `0x0069ae10` include `FrameMgr` construction/destruction, `FrameHandler` wrappers, and `0x004a6c40` idle scheduling; decompilation confirms `0x004b6dc0` writes `dword_69AE10 = this` and `0x004b70c0` clears it.
- 2026-06-11 A001 gate and evidence refresh:
  - Changed scores from `86/80` to `88/86`.
  - Summary/evidence: added exact storage-child and scheduler aggregate links, lifecycle/user summary, timing-model separation, verified `0x14` / decimal `20` idle-slice conversion, explicit rejected-owner rationale, strict `85/85` gate decision through [UID:0000JM][FrameMgr](by-file/FrameMgr.md), and score rationale. No fresh live IDA call was attempted for this page during this pass after prior MCP requests timed out on the previous target.
