*** UID:0000SO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
VirusChecker *g_pVirusChecker;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pVirusChecker

## Status

- Confidence: very strong for address, size, zero-filled storage, `Singleton<VirusChecker>` specialization role, compiler/template lifecycle lowering, definition placement, and file owner; live activation remains unproven.
- Address: [UID:0001Q3][0x0069bf94-0x0069bf98.g_pVirusChecker](by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md)
- Likely owner file: [UID:0000P5][VirusChecker](by-file/VirusChecker.md)

## Purpose

`g_pVirusChecker` is the source definition for the `Singleton<VirusChecker>` specialization's retained complete-object pointer. Current RTTI proves [UID:0000FW][VirusChecker](by-class/VirusChecker.md) directly and publicly inherits the non-virtual Singleton specialization at PMD `+0x04`. Constructor publication and ordinary/EH/scalar-destructor clears are inlined template/compiler lowering; authored `VirusChecker` methods must not duplicate those assignments.

Current MCP session `e63ee655` found the expected constructor/destructor/clear/scalar-destructor lifecycle writes, zero-filled storage, `u32le == 0`, no interior-byte refs, the separate successor ref at `0x0069bf98`, and no external read/consumer route or unrelated pointer-pattern route for `g_pVirusChecker`. That no-consumer state supports the retained optional/disabled scanner inference and caps confidence; it does not invalidate [UID:0000P5][VirusChecker](by-file/VirusChecker.md) ownership. The older `86fb854e` cleanup remains useful historical support, but is no longer the active proof source.

## Storage

| Range | Segment | IDA name | Proposed symbol | Type | Current bytes | Current value | Meaning |
| --- | --- | --- | --- | --- | --- | --- | --- |
| `0x0069bf94-0x0069bf98` | `.data` | `dword_69BF94` | `g_pVirusChecker` | `VirusChecker *` | `00 00 00 00` | `0x00000000` | Active retained V3 scanner singleton pointer. |

## Evidence Notes

- 2026-07-03 B004 accepted current MCP session `e63ee655` reports active IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, healthy server state, imagebase `0x400000`, ready auto-analysis/Hex-Rays/string cache, `get_bytes 0x0069bf7c size 28` as all zero bytes across the adjacent V3 globals plus this slot, and `get_int u32le 0x0069bf94 == 0`. The older `86fb854e` and A001 session evidence remains historical support; older `0xffffffff` sampled-value wording is superseded.
- `xrefs_to` / `xref_query` in MCP session `e63ee655` reports all five data refs inside the local `VirusChecker` lifecycle: constructor publish/null-clear refs at `0x005c0496` and `0x005c049d`, ordinary destructor clear at `0x005c0582`, clear helper write at `0x005c0eb0`, and scalar deleting destructor clear at `0x005c0f63`.
- Decompilation of `0x005c0460-0x005c04e0` publishes `this` to `dword_69BF94` unless the adjusted pointer is null, installs the `VirusChecker` vtable, initializes the embedded tree header/count fields, and allocates the sentinel through `sub_5796D0`.
- Decompilation of `0x005c04e0-0x005c059d` restores the `VirusChecker` vtable, frees the V3 module handles when present, clears the V3 function pointers, destroys the embedded path tree, frees the sentinel, and clears `dword_69BF94` at `0x005c0582`.
- `0x005c0eb0-0x005c0ebb` is a tiny clear helper that stores zero to `dword_69BF94`; current `disasm 0x005c0eb0` shows exactly `mov dword ptr unk_69BF94, 0` and `retn`, and `xref_query 0x005c0eb0` reports the only code edge as the EH cleanup thunk at `0x0060bc76`.
- Decompilation of `0x005c0ec0-0x005c0f94` is the scalar deleting destructor path. It repeats the V3/tree teardown, clears `dword_69BF94` at `0x005c0f63`, and conditionally frees the object; `xrefs_to 0x005c0ec0` reports the vtable data ref at `0x006310e0`.
- Current `get_bytes 0x006310dc size 8` reports `08 3f 65 00 c0 0e 5c 00`; `xrefs_to 0x006310e0` reports the constructor/destructor/scalar-deleting-destructor vptr stores at `0x005c04a7`, `0x005c050c`, and `0x005c0eed`.
- Current `xrefs_to 0x0069bf95` reports no interior refs; `xrefs_to 0x0069bf98` reports one separate successor ref from `0x005c21f1` in `sub_5C20E0`, proving [UID:0001Q3][0x0069bf94-0x0069bf98.g_pVirusChecker](by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md) is exactly four bytes.
- Current `xrefs_to` reports no refs to constructor `0x005c0460`, ordinary destructor `0x005c04e0`, V3 loader `0x005c05a0`, raw reset helper `0x005c0770`, scanner `0x005c07b0`, or insert helper `0x005c0940`. Current `find_bytes` finds no little-endian pointer patterns for starts `0x005c0460`, `0x005c04e0`, `0x005c05a0`, `0x005c0770`, `0x005c07b0`, `0x005c0940`, or `0x005c0eb0`; it finds only expected local operand/vtable patterns for `0x0069bf94`, `0x005c0ec0`, and `0x006310e0`. Normal runtime activation remains unproven.
- B005 current MCP session `7be8cc9f` supersedes prior sessions for the Singleton source-shape inference. VirusChecker RTTI contains exactly self plus `Singleton<VirusChecker>`; the base PMD is `{4,-1,0}`, constructor lowering uses `this+4/-4`, and the scalar wrapper frees the 12-byte complete object. These facts identify this slot as template-specialization storage rather than an unrelated project global.
- The same B005 pass found no local `VirusChecker` IDA type and retained raw `dword_69BF94` state, yielding a concrete supervisor Gate 2B rename/type handoff. B005 did not mutate IDA.
- 2026-06-14 A003 live IDA MCP refresh reconfirmed `0x0069bf94` has exactly five xrefs and all remain confined to the `VirusChecker` lifecycle. Function sizes are constructor `0x80` / `128` bytes, ordinary destructor `0xbd` / `189` bytes, singleton clear helper `0xb` / `11` bytes, and scalar deleting destructor `0xd4` / `212` bytes (all conversions Verified with int_convert.py).
- 2026-06-14 decompilation confirms constructor publish/fallback clear, `VirusChecker` vtable install, embedded tree sentinel allocation through `sub_5796D0`, ordinary/scalar destructor `FreeLibrary` cleanup for the V3 module handles, V3 function-pointer zeroing, tree teardown, and final singleton clear.
- 2026-06-14 `xrefs_to 0x005c0eb0` still reports only the EH cleanup edge at `0x0060bc76`, and `xrefs_to 0x005c0ec0` still reports the vtable data ref at `0x006310e0`. No normal startup constructor caller was found in this focused pass.

## Autogen And Score Rationale

- Owner/emitter route remains [UID:0000P5][VirusChecker](by-file/VirusChecker.md), which surfaces to `auto-generated/NexusTK/security/VirusChecker.cpp` without a dead end.
- The formal source definition is `VirusChecker *g_pVirusChecker;`. The class page keeps the header/class-facing `extern VirusChecker *g_pVirusChecker;` declaration, while this by-global page owns the definition that emits through [UID:0000P5][VirusChecker](by-file/VirusChecker.md).
- The source definition remains explicit because the binary has one real zero-initialized storage slot. The writes/clears are not explicit authored lifecycle code: `Singleton<VirusChecker>` template construction/destruction and MSVC EH/scalar lowering generate them.
- Completion is `90` because the page records exact storage, all five lifecycle refs, direct Singleton RTTI/PMD/EBO evidence, compiler/template lowering, owner route, one-definition/one-extern placement, and the current IDA handoff.
- Confidence is `93` for singleton identity, specialization-storage role, source definition placement, and ownership because RTTI, constructor adjustment, xrefs, object size, and linked exact memory page agree. Normal runtime activation and an external consumer remain broader execution-path uncertainties only.

## Cross-References

- [UID:0000P5][VirusChecker](by-file/VirusChecker.md)
- [UID:0000FW][VirusChecker](by-class/VirusChecker.md)
- [UID:0001NU][0x005c0460-0x005c0fe1.VirusChecker](by-memory/0x005c0460-0x005c0fe1.VirusChecker.md)
- [UID:0001Q3][0x0069bf94-0x0069bf98.g_pVirusChecker](by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md)
- [UID:0001Q7][client_anticheat](by-meta/client_anticheat.md)

## Changes

- 2026-05-31: Updated reconstruction metadata and scores from live IDA evidence.
  - Before: completion/confidence were `0/0`, reconstructable state was blank, and no parent file UID was assigned.
  - After: `COMPLETION:74`, `CONFIDENCE:82`, `RECONSTRUCTABLE:TRUE`, and owner/emitter route `0000P5` for [UID:0000P5][VirusChecker](by-file/VirusChecker.md). `RECONSTRUCTION_CPP CODE` remains blank because source-quality declaration and activation evidence were not final.
  - Evidence: IDA MCP rechecked `0x0069bf94` as a 4-byte singleton pointer with 5 local VirusChecker lifecycle xrefs. Confidence remains below the other singleton pass because IDA still has no proven normal startup constructor caller.
- 2026-06-05: Raised completion/confidence from `74/82` to `82/88` and expanded the evidence around the exact singleton storage and local lifecycle refs. The score now clears the parent gate for the memory page, but remains below the higher singleton score used for globals with proven startup/consumer paths because IDA still reports no direct normal constructor caller.
- 2026-06-14 A003 goal2 score pass: raised `82/88` to `86/90`.
  - Evidence: live IDA MCP reconfirmed the exact five-ref lifecycle map, constructor/destructor/clear-helper/scalar-destructor sizes and decompilation, EH cleanup edge to the clear helper, and vtable data ref to the scalar deleting destructor.
  - Code-entry decision: no reconstruction C++ was added; the emitter route and score gate are present, but normal activation and final source declaration details remain below source-quality evidence.
- 2026-06-14 A001 Goal 2 global score pass: score remains `86/90`.
  - Evidence: live IDA MCP and raw section-offset sanity checks supersede the earlier `0xffffffff` storage note; the exact memory page now records current zero-filled bytes while preserving the five-ref VirusChecker lifecycle and no-normal-startup-caller caveat.
- 2026-06-20 B004 Rule 26 support sync, updated 2026-06-29 by B004 then-current MCP cleanup: recorded the no external singleton consumer/read route from then-current MCP session `86fb854e` and kept the retained optional-scanner activation caveat. Earlier local PE/Capstone wording is historical only.
- 2026-07-03 B004 accepted report implementation:
  - Raised completion/confidence from `86/90` to `88/91` and added the formal source definition `VirusChecker *g_pVirusChecker;`.
  - Summary/evidence: current MCP session `e63ee655` supersedes `86fb854e` as active proof source, reconfirming zero-filled storage, `u32le == 0`, exact five lifecycle refs, no interior refs, separate successor `0x0069bf98` ref from `0x005c21f1`, constructor publish/fallback clear, ordinary/helper/scalar destructor clears, EH cleanup edge, vtable/scalar deleting destructor refs, and no activation xref or pointer-pattern route. The no external consumer/no normal startup activation caveat remains the confidence cap.
- 2026-07-23 B005 UID0002OT accepted support implementation:
  - Raised completion/confidence from `88/91` to `90/93`; preserved file owner/emitter, reconstructable state, and sole formal definition.
  - Added the direct `Singleton<VirusChecker>` RTTI/PMD/EBO chain and clarified that all five local writes are template/compiler lifecycle lowering, not assignments to duplicate in authored `VirusChecker` bodies.
  - Historicalized the older generic-lifecycle interpretation while preserving zero-filled storage, exact xrefs/boundaries, no-external-consumer evidence, and optional-activation caveat.
