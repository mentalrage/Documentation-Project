*** UID:0001Y7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MonsterImageLib Vtable

## Status

- Confidence: strong for address, RTTI locator, slot targets, adjacent boundary, and vptr-store xrefs.
- Owner class: [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md).
- Exact memory page: [UID:0002MM][0x0061b6e0-0x0061b6f0.MonsterImageLibVtableData](by-memory/0x0061b6e0-0x0061b6f0.MonsterImageLibVtableData.md).
- Backing aggregate page: [UID:00025I][0x0061b664-0x0061c364.ImageLibraryReadOnlyData](by-memory/0x0061b664-0x0061c364.ImageLibraryReadOnlyData.md).
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

- `0x004daf16` in [UID:00017C][0x004dac40-0x004e685f.MonsterImageLib](by-memory/0x004dac40-0x004e685f.MonsterImageLib.md)
- `0x004db036` in [UID:00017D][0x004db010-0x004db0f7.MonsterImageLibDestructor](by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md)
- `0x004e677d` in the scalar deleting destructor

Generated `class_MonsterImageLib.meta_wave3` data has previously omitted this vtable, so use the IDA-confirmed symbol and dword evidence above as the authority.

## Rebuild Notes

This is source-declared/generated-binary data. Recreate it by preserving the `MonsterImageLib` class declaration, inherited virtual interface, scalar deleting destructor behavior, and virtual slot ordering; do not hand-port the vtable bytes as source.

No `RECONSTRUCTION_CPP CODE` is emitted here. Source declarations and method bodies should be attached through the owning class/file and exact `by-memory` method pages only after the final-source confidence gate is satisfied.

## Cross-References

- [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md)
- [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md)
- [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md)
- [UID:00017D][0x004db010-0x004db0f7.MonsterImageLibDestructor](by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md)
- [UID:0000RR][g_pMonsterImageLib](by-global/g_pMonsterImageLib.md)

## Changes

- 2026-05-31 completion/confidence and reconstructable update:
  - What existed before: page had useful vtable notes but metadata was still `COMPLETION:0`, `CONFIDENCE:0`, and `RECONSTRUCTABLE:` blank.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:90`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: live IDA MCP confirmed the exact [UID:0002MM][0x0061b6e0-0x0061b6f0.MonsterImageLibVtableData](by-memory/0x0061b6e0-0x0061b6f0.MonsterImageLibVtableData.md), RTTI locator, slot targets, constructor/destructor/scalar-deleting-destructor xrefs, preceding `HumanImageLib` vtable, and next `RidingImageLib` boundary. Scores remain below `95` because final source declarations, inherited/shared virtual slot naming, and all surrounding MonsterImageLib method dependencies are not final-audited.
