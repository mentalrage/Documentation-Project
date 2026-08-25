*** UID:0001YU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Security Singleton Vtables

## Status

- Entity kind: vtable layout.
- Confidence: very strong for slot values, range boundaries, and owning class association.
- Disposition: reviewed non-emitting mixed-owner vtable inventory for two security singleton classes; exact source-local child pages now carry the reconstructable routes.
- Evidence basis: IDA MCP `entity_query`, `trace_data_flow`, function lookup, xref checks, and unique raw signatures refreshed by A004 on 2026-06-12.
- Assignment: `AUTOGEN_PARENT_UID` remains blank. This aggregate clears the evidence gate but has no single direct class or source-file parent because `CheatDetector` and `VirusChecker` are distinct source owners.
- Current data caveat: `class_CheatDetector.meta_wave3` and `class_VirusChecker.meta_wave3` both report `vtable_count: 0`; do not use that generated count as authority.

## CheatDetector Vtable

- Object vptr value: `0x00615564`
- RTTI complete-object locator pointer: `0x00615560` -> `??_R4CheatDetector@@6B@`
- Exact by-vtable child: [UID:0003JE][CheatDetectorVtable](by-type/by-vtable/CheatDetectorVtable.md)
- Exact by-memory child: [UID:00024Y][0x00615560-0x00615570.CheatDetectorVtableData](by-memory/0x00615560-0x00615570.CheatDetectorVtableData.md)
- Owner class: [UID:000020][CheatDetector](by-class/CheatDetector.md)
- Likely source file: [UID:0000I6][CheatDetector](by-file/CheatDetector.md)

| Slot | Target | Interpretation |
| --- | --- | --- |
| `+0x00` | [UID:0004UR][0x00484000-0x0048402d.CheatDetectorScalarDeletingDestructor](by-memory/0x00484000-0x0048402d.CheatDetectorScalarDeletingDestructor.md) | Compiler-only scalar deleting destructor; source carrier is inline empty virtual destructor. |
| `+0x04` | [UID:0004UP][0x00483fe0-0x00483fe5.CheatDetectorOnTimer](by-memory/0x00483fe0-0x00483fe5.CheatDetectorOnTimer.md) | Source `OnTimer(timerId,arg0,arg1)` returning true. |

IDA xrefs to the object vptr slot at `0x00615564` land at the constructor store `0x00483f52`. The function targets have data refs from the vtable slots: `0x00484000` from `0x00615564`, and `0x00483fe0` from `0x00615568`.

`0x0061556c` is the RTTI pointer for the next adjacent `ClanStatusPane` vtable, not a third `CheatDetector` slot. The exact two-slot table is closed. RTTI additionally proves direct `Singleton<CheatDetector>` PMD `+4,-1,0` and direct `TimerHandler` PMD `0,-1,0`; source order is Singleton then TimerHandler, with Singleton empty-base overlap and no second vtable.

## VirusChecker Vtable

- Object vptr value: `0x006310e0`
- RTTI complete-object locator pointer: `0x006310dc` -> `??_R4VirusChecker@@6B@`
- Exact by-vtable child: [UID:0003JF][VirusCheckerVtable](by-type/by-vtable/VirusCheckerVtable.md)
- Exact by-memory child: [UID:0002OT][0x006310dc-0x006310e4.VirusCheckerVtableData](by-memory/0x006310dc-0x006310e4.VirusCheckerVtableData.md)
- Owner class: [UID:0000FW][VirusChecker](by-class/VirusChecker.md)
- Likely source file: [UID:0000P5][VirusChecker](by-file/VirusChecker.md)

| Slot | Target | Interpretation |
| --- | --- | --- |
| `+0x00` | `0x005c0ec0` | scalar deleting destructor |

IDA xrefs to the object vptr slot at `0x006310e0` land at `0x005c04a7`, `0x005c050c`, and `0x005c0eed`, matching constructor, destructor, and scalar deleting destructor vptr writes.

`0x006310e4` begins adjacent string data for `V3PRO32E.DLL`, not another `VirusChecker` virtual slot. This makes `VirusChecker` a compact one-slot virtual class in the current binary.

## Boundary Evidence

- IDA MCP on 2026-06-01 shows `0x00615560 -> 0x0064486c`, `0x00615564` named `??_7CheatDetector@@6B@`, two slot targets at `0x00484000` and `0x00483fe0`, and `0x0061556c -> 0x00644b54` before `??_7ClanStatusPane@@6B@` at `0x00615570`.
- IDA MCP on 2026-06-01 shows `0x006310dc -> 0x00653f08`, `0x006310e0` named `??_7VirusChecker@@6B@`, one slot target at `0x005c0ec0`, and `0x006310e4` named `LibFileName`.
- IDA MCP `py_eval` on 2026-06-11 reconfirmed the same dwords and boundaries: `0x00615560 -> ??_R4CheatDetector@@6B@`, `0x00615564 -> sub_484000`, `0x00615568 -> sub_483FE0`, `0x0061556c -> ??_R4ClanStatusPane@@6B@`, `0x00615570 -> sub_48C590`; and `0x006310d4/0x006310d8` remain `VideoPlayerPane` tertiary slots before `0x006310dc -> ??_R4VirusChecker@@6B@`, `0x006310e0 -> sub_5C0EC0`, and `0x006310e4` remains `LibFileName` / `V3PRO32E.DLL` string data.
- The same 2026-06-11 xref audit reconfirmed the `CheatDetector` vptr store at `0x00483f52`, slot-target data refs `0x00615564 -> 0x00484000` and `0x00615568 -> 0x00483fe0`, and `VirusChecker` vptr stores at `0x005c04a7`, `0x005c050c`, and `0x005c0eed` with slot-target data ref `0x006310e0 -> 0x005c0ec0`.
- Function-boundary spot checks on 2026-06-11 also matched the documented owner methods: `0x00483f00-0x00483f86`, `0x00483fe0-0x00483fe5`, `0x00484000-0x0048402d`, `0x005c0460-0x005c04e0`, `0x005c04e0-0x005c059d`, and `0x005c0ec0-0x005c0f94`.
- A004 Batch 341 live IDA MCP on 2026-06-12 reconfirmed the named records without relying on stale metadata: `entity_query` found `??_7CheatDetector@@6B@` at `0x00615564` with `ClanStatusPane` successor `0x00615570`, and `??_7VirusChecker@@6B@` at `0x006310e0` with `LibFileName` successor `0x006310e4`.
- The same 2026-06-12 data-flow audit found the `CheatDetector` vptr store at `0x00483f52`, `VirusChecker` vptr stores at `0x005c04a7`, `0x005c050c`, and `0x005c0eed`, slot targets `0x00484000`, `0x00483fe0`, and `0x005c0ec0`, and owner function bounds matching the documented constructor/destructor/scalar-deleting-destructor ranges.
- Unique raw signatures bound both backing records exactly: `0x00615560-0x00615570` bytes `6C 48 64 00 00 40 48 00 E0 3F 48 00 54 4B 64 00`, and `0x006310dc-0x006310e4` bytes `08 3F 65 00 C0 0E 5C 00`.
- B004 current MCP session `86fb854e` rechecked the `VirusChecker` backing record with the same `0x006310dc-0x006310e4` bytes, the decorated vtable name at `0x006310e0`, and constructor/destructor/scalar-deleting-destructor vptr-store xrefs.
- Both vtable pages are compiler-emitted data that must be regenerated by rebuilding their owning classes, not hand-copied as raw arrays.

## Assignment Decision

This page is `reviewed-ignored-mixed-owner-index`. It clears the evidence gate at `89/93`, but it remains autogen-unassigned and non-reconstructable because the covered records have different direct source owners:

| Record | Exact child | Direct owner state |
| --- | --- | --- |
| `CheatDetector` RTTI/vtable at `0x00615560-0x00615570` | [UID:0003JE][CheatDetectorVtable](by-type/by-vtable/CheatDetectorVtable.md) / [UID:00024Y][0x00615560-0x00615570.CheatDetectorVtableData](by-memory/0x00615560-0x00615570.CheatDetectorVtableData.md) | Both exact children are `92/96`, false/non-emitting source-declared/generated-binary support routed to [UID:000020][CheatDetector](by-class/CheatDetector.md) `92/94`; UID0004UP owns the source callback and UID0004UR documents compiler deleting-wrapper behavior without emitting it. |
| `VirusChecker` RTTI/vtable at `0x006310dc-0x006310e4` | [UID:0003JF][VirusCheckerVtable](by-type/by-vtable/VirusCheckerVtable.md) / [UID:0002OT][0x006310dc-0x006310e4.VirusCheckerVtableData](by-memory/0x006310dc-0x006310e4.VirusCheckerVtableData.md) | The source-local type child is `88/93` and the backing memory child is `86/91`; both route to direct class parent [UID:0000FW][VirusChecker](by-class/VirusChecker.md), whose `88/89` score clears the strict gate. |

Do not assign this aggregate upward to either class/file parent. [UID:0001Q7][client_anticheat](by-meta/client_anticheat.md) is the right topical cross-reference, but it is a meta inventory with non-scored `-1/-1` status and is not a valid strict-gate source parent.

## Source-Layout Implication

The two vtables support keeping [UID:0000I6][CheatDetector](by-file/CheatDetector.md) and [UID:0000P5][VirusChecker](by-file/VirusChecker.md) as distinct `security/` source files. They do not support folding `VirusChecker` into an AhnLab library wrapper: the vtable belongs to the project-side singleton object, while the AhnLab/V3 code is dynamically loaded through DLL exports.

## Cross-References

- [UID:000020][CheatDetector](by-class/CheatDetector.md)
- [UID:0000I6][CheatDetector](by-file/CheatDetector.md)
- [UID:0003JE][CheatDetectorVtable](by-type/by-vtable/CheatDetectorVtable.md)
- [UID:000108][0x00483f00-0x0048402d.CheatDetector](by-memory/0x00483f00-0x0048402d.CheatDetector.md)
- [UID:000109][0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor](by-memory/0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor.md)
- [UID:00024Y][0x00615560-0x00615570.CheatDetectorVtableData](by-memory/0x00615560-0x00615570.CheatDetectorVtableData.md)
- [UID:0000FW][VirusChecker](by-class/VirusChecker.md)
- [UID:0000P5][VirusChecker](by-file/VirusChecker.md)
- [UID:0003JF][VirusCheckerVtable](by-type/by-vtable/VirusCheckerVtable.md)
- [UID:0001NU][0x005c0460-0x005c0fe1.VirusChecker](by-memory/0x005c0460-0x005c0fe1.VirusChecker.md)
- [UID:0002OT][0x006310dc-0x006310e4.VirusCheckerVtableData](by-memory/0x006310dc-0x006310e4.VirusCheckerVtableData.md)
- [UID:0001WG][VirusCheckerProcessTreeLayout](by-type/by-struct/VirusCheckerProcessTreeLayout.md)
- [UID:0001Q7][client_anticheat](by-meta/client_anticheat.md)

## Changes

- Previous: validator scores were `0/0`, the page relied on older IDA evidence, and the exact `VirusChecker` vtable child was not split.
- Changed to: scores raised conservatively below final-audit level, `RECONSTRUCTABLE:TRUE`, exact `CheatDetector` and `VirusChecker` child links added, and boundary evidence refreshed from IDA MCP.
- Evidence: IDA MCP `py_eval` on 2026-06-01 verified both vtable address families, slot targets, constructor/destructor store xrefs, and adjacent range boundaries. Scores remain below `95` because final C++ declarations and complete source-file emission are not final-audit complete.
- 2026-06-11 A004 normal task:
  - Before: scores were `84/90`, parent was blank, and generated type coverage listed the page as unassigned without a current ownership-split rationale.
  - After: raised to `85/91`; parent remains blank by design as a reviewed multi-owner vtable inventory.
  - Summary/evidence: live IDA MCP `py_eval` reconfirmed the exact `CheatDetector` and `VirusChecker` RTTI/vtable dwords, slot targets, store xrefs, adjacent `ClanStatusPane` / `VideoPlayerPane` / `LibFileName` boundaries, and owner-method function bounds. The page clears the child evidence gate, but no single direct source parent owns both vtable records, so final C++ and upward autogen assignment remain blank.
- 2026-06-11 A002 Batch 206 parent-gate follow-up:
  - Before: the assignment-decision table still said [UID:00024Y][0x00615560-0x00615570.CheatDetectorVtableData](by-memory/0x00615560-0x00615570.CheatDetectorVtableData.md) could not be assigned because [UID:000020][CheatDetector](by-class/CheatDetector.md) and [UID:0000I6][CheatDetector](by-file/CheatDetector.md) were below gate.
  - After: updated the table to show [UID:00024Y][0x00615560-0x00615570.CheatDetectorVtableData](by-memory/0x00615560-0x00615570.CheatDetectorVtableData.md) assigned to [UID:000020][CheatDetector](by-class/CheatDetector.md) after the class and file pages were refreshed to `85/86` and `86/85`.
  - Summary/evidence: Batch 206 live IDA MCP reconfirmed the `0x00615560-0x00615570` COL/vtable dwords, constructor store xref, slot targets, and successor boundary; this aggregate remains parent-blank because it still spans distinct `CheatDetector` and `VirusChecker` owners.
- 2026-06-12 A004 Batch 341 split/reclassification:
  - Before: scores were `85/91`, `RECONSTRUCTABLE:TRUE`, and the page was still listed as a reconstructable mixed-owner row.
  - After: raised to `89/93`, changed `RECONSTRUCTABLE:FALSE`, kept parent blank, and created exact routable children [UID:0003JE][CheatDetectorVtable](by-type/by-vtable/CheatDetectorVtable.md) and [UID:0003JF][VirusCheckerVtable](by-type/by-vtable/VirusCheckerVtable.md).
  - Summary/evidence: live IDA MCP reconfirmed both decorated vtable bases, backing ranges, store xrefs, slot targets, function bounds, unique raw signatures, and adjacent owner boundaries. The exact child pages and their direct class parents clear the strict `85/85` routing gate; this aggregate remains a non-emitting index because no single source parent owns both records.
