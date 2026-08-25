*** UID:0003JE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000020 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CheatDetector Vtable

## Summary

- Entity kind: source-local vtable layout.
- Owner class: [UID:000020][CheatDetector](by-class/CheatDetector.md)
- Source file context: [UID:0000I6][CheatDetector](by-file/CheatDetector.md)
- Backing data: [UID:00024Y][0x00615560-0x00615570.CheatDetectorVtableData](by-memory/0x00615560-0x00615570.CheatDetectorVtableData.md)
- Object vptr: `0x00615564`
- Rebuild handling: `source-declared/generated-binary`

This page owns the source-level `CheatDetector` vtable layout that was previously documented only inside the mixed [UID:0001YU][SecuritySingletonVtables](by-type/by-vtable/SecuritySingletonVtables.md) inventory. The compiler regenerates the RTTI/vtable bytes from direct `Singleton<CheatDetector>, TimerHandler` inheritance, inline `virtual ~CheatDetector() {}`, and `virtual bool OnTimer(int timerId, int arg0, int arg1)`. This page is false/non-emitting and must not hand-copy a table, ABI body, proof comment, or marker.

## Layout

| Slot | Target | Interpretation |
| --- | --- | --- |
| `+0x00` | [UID:0004UR][0x00484000-0x0048402d.CheatDetectorScalarDeletingDestructor](by-memory/0x00484000-0x0048402d.CheatDetectorScalarDeletingDestructor.md) | Source semantic inline `CheatDetector::~CheatDetector`; compiler deleting wrapper over TimerHandler teardown, Singleton clear, and optional free. |
| `+0x04` | [UID:0004UP][0x00483fe0-0x00483fe5.CheatDetectorOnTimer](by-memory/0x00483fe0-0x00483fe5.CheatDetectorOnTimer.md) | Source `OnTimer(timerId,arg0,arg1)` override returning true. |

## Evidence

- `0x00615560` is the RTTI-adjacent complete-object-locator word for `CheatDetector`.
- `0x00615564` is named `??_7CheatDetector@@6B@` and is stored by the constructor at `0x00483f52`.
- `0x00615568` points to `0x00483fe0`, the five-byte true-return virtual method.
- 2026-06-19 B012 source-quality reanalysis resolves slot `+0x04` as the `TimerHandler` callback override because the body returns true and consumes three explicit callback arguments with `retn 0x0c`; `virtual check slot` is now treated as stale descriptive wording. Slot `+0x00` remains compiler deleting-destructor glue, not a source-authored virtual method body.
- `0x0061556c` is the RTTI-adjacent word for the next `ClanStatusPane` vtable, so it is the exclusive boundary for this table.
- A004 Batch 341 live IDA MCP rechecked `entity_query`, `trace_data_flow`, `lookup_funcs`, and `make_signature_for_range`; the unique raw table signature is `6C 48 64 00 00 40 48 00 E0 3F 48 00 54 4B 64 00`.

## Assignment Decision

`AUTOGEN_PARENT_UID` is [UID:000020][CheatDetector](by-class/CheatDetector.md). The vtable child is `88/93`, the direct class parent is `85/86`, and the file parent [UID:0000I6][CheatDetector](by-file/CheatDetector.md) is `86/85`, so the strict child/direct-parent gate is satisfied.

## Cross-References

- [UID:000020][CheatDetector](by-class/CheatDetector.md)
- [UID:0000I6][CheatDetector](by-file/CheatDetector.md)
- [UID:00024Y][0x00615560-0x00615570.CheatDetectorVtableData](by-memory/0x00615560-0x00615570.CheatDetectorVtableData.md)
- [UID:000108][0x00483f00-0x0048402d.CheatDetector](by-memory/0x00483f00-0x0048402d.CheatDetector.md)
- [UID:000109][0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor](by-memory/0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor.md)
- [UID:0001YU][SecuritySingletonVtables](by-type/by-vtable/SecuritySingletonVtables.md)

## B004 Source-Declared/Generated-Binary Closure

- The exact 16-byte backing signature is SHA256 `08BC006D367DA560B15DF2DE83AC55496E95388ECE6891BFD7172AE141D374F2`; object vptr is `0x00615564`, with the two slots above and ClanStatusPane's COL beginning at `0x0061556c`.
- Constructor UID0004UO installs this vptr, while no handwritten source references the table address.
- RTTI proves direct Singleton and TimerHandler bases; vtable layout belongs to the TimerHandler polymorphic subobject at offset zero. Singleton EBO at PMD `+4` does not create a second vtable.
- Source declarations fully regenerate the table, COL, RTTI, scalar wrapper, and callback slot. `RECONSTRUCTABLE:FALSE` means this documentation page emits no C++ of its own, not that the class lacks virtual source semantics.

## Changes

- 2026-06-12 A004 Batch 341: Created exact source-local vtable page from the mixed security singleton vtable inventory. Evidence: live IDA MCP reconfirmed the decorated vtable base, constructor vptr store, slot target function bounds, successor `ClanStatusPane` boundary, and unique raw table signature.
- 2026-06-19 B012 source-quality incorporation: no score change; updated slot interpretations to `CheatDetectorScalarDeletingDestructor` and `CheatDetector::OnTimer`, recorded the `TimerHandler` callback signature inference, and retained compiler-regenerated vtable/deleting-destructor handling.
- 2026-06-20 B002 Rule 26 incorporation: no score change; tied the vtable regeneration policy to the ready [UID:000020][CheatDetector](by-class/CheatDetector.md) declaration with `virtual ~CheatDetector()` and `OnTimer(eventId,arg0,arg1)`.
