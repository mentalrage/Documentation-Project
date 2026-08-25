*** UID:0001Y7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00008N | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00008N | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// MonsterImageLib vtable bytes are compiler-generated from the class
// declaration and virtual destructor; do not hand-emit a source vtable object.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MonsterImageLib Vtable

## Status

- Confidence: strong for address, RTTI locator, slot targets, adjacent boundary, and vptr-store xrefs.
- Owner class: [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md).
- Autogen parent: [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md), which now clears the strict `85/85` gate and routes through [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md).
- Exact memory page: [UID:0002MM][0x0061b6e0-0x0061b6f0.MonsterImageLibVtableData](by-memory/0x0061b6e0-0x0061b6f0.MonsterImageLibVtableData.md).
- Backing aggregate page: [UID:00025I][0x0061b660-0x0061c360.ImageLibraryReadOnlyData](by-memory/0x0061b660-0x0061c360.ImageLibraryReadOnlyData.md).
- RTTI pointer: `0x0061b6e0` -> `0x00648c14` (`??_R4MonsterImageLib@@6B@`).
- Primary vtable: `0x0061b6e4` (`??_7MonsterImageLib@@6B@`).
- Rebuild handling: `source-declared/generated-binary`.

## Slots

| Offset | Address | Function |
| --- | --- | --- |
| `+0x00` | `0x004e6750` | `MonsterImageLib::ScalarDeletingDestructor` |
| `+0x04` | `0x004f4b10` | inherited/shared virtual slot, currently unnamed |
| `+0x08` | `0x0041b6c0` | `nullsub_18` |

The table ends before the `RidingImageLib` RTTI pointer at `0x0061b6f0` and its vtable at `0x0061b6f4`.

## Current IDA Evidence

Live IDA MCP recheck on 2026-05-31 confirmed:

- `lookup_funcs`:
  - `0x004e6750` -> `sub_4E6750`, size `0x110`, scalar deleting destructor slot.
  - `0x004f4b10` -> `sub_4F4B10`, size `0x6`, inherited/shared virtual slot.
  - `0x0041b6c0` -> `nullsub_18`, size `0x3`.
- `py_eval` dword scan:
  - `0x0061b6d4` is the preceding `HumanImageLib` vtable.
  - `0x0061b6e0` dword `0x00648c14` -> `??_R4MonsterImageLib@@6B@`.
  - `0x0061b6e4` dword `0x004e6750` -> `sub_4E6750`, xrefs from `0x004daf16`, `0x004db036`, and `0x004e677d`.
  - `0x0061b6e8` dword `0x004f4b10` -> `sub_4F4B10`.
  - `0x0061b6ec` dword `0x0041b6c0` -> `nullsub_18`.
  - `0x0061b6f0` dword `0x00648cb4` -> `??_R4RidingImageLib@@6B@`, proving the next image-library RTTI boundary.
- IDA names in the same region include `??_7MonsterImageLib@@6B@`, `??_R4MonsterImageLib@@6B@`, and associated `Singleton<MonsterImageLib>` RTTI records at `0x00648c64-0x00648c98`.

IDA xrefs to `0x0061b6e4` land at:

- `0x004daf16` in [UID:00017C][0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster](by-memory/0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster.md)
- `0x004db036` in [UID:00017D][0x004db010-0x004db0f7.MonsterImageLibDestructor](by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md)
- `0x004e677d` in the scalar deleting destructor

Generated `class_MonsterImageLib.meta_wave3` data has previously omitted this vtable, so use the IDA-confirmed symbol and dword evidence above as the authority.

Live IDA MCP recheck on 2026-06-11 against `NexusTK.exe` (`sha256 9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`) reconfirmed:

- `lookup_funcs` still resolves the slot targets as `0x004e6750-0x004e6860`, `0x004f4b10-0x004f4b16`, and `0x0041b6c0-0x0041b6c3`.
- `lookup_funcs` also keeps the owning constructor/destructor anchors at `0x004daec0-0x004db00e` and `0x004db010-0x004db0f7`.
- `xrefs_to 0x0061b6e4` still reports exactly three vptr/data references: constructor store `0x004daf16`, ordinary destructor restore `0x004db036`, and scalar-deleting-destructor self-reference `0x004e677d`.
- A dword scan across `0x0061b6d0-0x0061b700` keeps the half-open range unchanged: `HumanImageLib` RTTI/vtable at `0x0061b6d0/0x0061b6d4`, `MonsterImageLib` RTTI/vtable at `0x0061b6e0/0x0061b6e4`, and `RidingImageLib` RTTI/vtable at `0x0061b6f0/0x0061b6f4`.

## Assignment Gate

This page is now assigned to [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md). The direct owner is the class whose RTTI names the vtable; that class is now `85/85` and already routes to the `86/86` [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md) source root. The exact vtable-data child [UID:0002MM][0x0061b6e0-0x0061b6f0.MonsterImageLibVtableData](by-memory/0x0061b6e0-0x0061b6f0.MonsterImageLibVtableData.md) should route to this by-vtable page so the compiler-emitted RTTI/vtable bytes remain attached to the slot-layout evidence while this page routes to the class.

## Rebuild Notes

This is source-declared/generated-binary data. Recreate it by preserving the `MonsterImageLib` class declaration, inherited virtual interface, scalar deleting destructor behavior, and virtual slot ordering; do not hand-port the vtable bytes as source.

The formal `RECONSTRUCTION_CPP CODE` block emits only the accepted no-standalone-vtable marker plus `[[CHILDREN]]`. Source declarations and method bodies attach through the owning class/file and exact `by-memory` method pages; the exact vtable-data child emits its own covered-by marker through this route.

B011's 2026-06-25 destructor source sync distinguishes the two destructor artifacts:

- [UID:00017D][0x004db010-0x004db0f7.MonsterImageLibDestructor](by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md) now carries the ordinary `MonsterImageLib::~MonsterImageLib()` source body: `ClearLoadedData(); delete[] m_monsters;`.
- Slot `+0x00` [UID:0003M1][0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor](by-memory/0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor.md) remains source-declared/generated-binary scalar deleting wrapper output. The class virtual destructor declaration and vtable layout should regenerate the delete-flag wrapper; do not hand-port it as source.

## Cross-References

- [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md)
- [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md)
- [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md)
- [UID:00017D][0x004db010-0x004db0f7.MonsterImageLibDestructor](by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md)
- [UID:0000RR][g_pMonsterImageLib](by-global/g_pMonsterImageLib.md)

## Changes

- 2026-06-30 B011 empty-emitter family implementation callback:
  - Score changed from `85/91` to `87/92`.
  - Evidence: inserted the formal no-standalone-vtable marker plus `[[CHILDREN]]`. Preserved RTTI pointer `0x00648c14`, vtable dwords `0x004e6750`, `0x004f4b10`, `0x0041b6c0`, constructor/destructor/scalar vptr xrefs, adjacent Riding boundary at `0x0061b6f0`, and compiler-generated vtable policy.
- 2026-06-25 B011 destructor implementation callback:
  - Score unchanged at `85/91`.
  - Evidence: synchronized destructor policy with [UID:00017D][0x004db010-0x004db0f7.MonsterImageLibDestructor](by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md) and [UID:0003M1][0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor](by-memory/0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor.md). The ordinary destructor now carries source C++; the vtable slot remains compiler-generated scalar deleting wrapper output.
- 2026-05-31 completion/confidence and reconstructable update:
  - What existed before: page had useful vtable notes but metadata was still `COMPLETION:0`, `CONFIDENCE:0`, and `RECONSTRUCTABLE:` blank.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:90`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: live IDA MCP confirmed the exact [UID:0002MM][0x0061b6e0-0x0061b6f0.MonsterImageLibVtableData](by-memory/0x0061b6e0-0x0061b6f0.MonsterImageLibVtableData.md), RTTI locator, slot targets, constructor/destructor/scalar-deleting-destructor xrefs, preceding `HumanImageLib` vtable, and next `RidingImageLib` boundary. Scores remain below `95` because final source declarations, inherited/shared virtual slot naming, and all surrounding MonsterImageLib method dependencies are not final-audited.
- 2026-06-11 A003 normal target parent routing:
  - What existed before: the vtable page was `82/90`, reconstructable, but `AUTOGEN_PARENT_UID` was blank even though the current [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md) and [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md) parents now clear the corrected `85/85` gate.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:91`, and parent [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md); final C++ remains blank.
  - Summary/evidence: 2026-06-11 live IDA MCP reconfirmed the executable hash, slot function bounds, constructor/destructor/scalar-deleting xrefs to `0x0061b6e4`, and Human/Monster/Riding neighboring RTTI/vtable dwords. The exact memory child [UID:0002MM][0x0061b6e0-0x0061b6f0.MonsterImageLibVtableData](by-memory/0x0061b6e0-0x0061b6f0.MonsterImageLibVtableData.md) now routes to this by-vtable page after the vtable/class/file chain clears the strict gate.
