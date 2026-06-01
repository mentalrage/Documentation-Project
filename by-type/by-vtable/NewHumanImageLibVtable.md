*** UID:0001Y9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewHumanImageLib Vtable

## Status

- Confidence: strong for address and slots.
- Owner class: [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md).
- RTTI pointer: `0x0061b768` -> `0x006490f4`.
- Primary vtable: `0x0061b76c`.

## Current IDA Recheck

IDA MCP `py_eval` on 2026-06-01 rechecked the current IDB names, slot values, and xrefs. `0x0061b76c` is still `??_7NewHumanImageLib@@6B@`, its locator pointer at `0x0061b768` still resolves to `??_R4NewHumanImageLib@@6B@` at `0x006490f4`, and the three table entries are `0x004e6870`, `0x004f4b10`, and `0x0041b6c0`.

The table has exactly three slots and ends at `0x0061b778`, where the next named item is `off_61B778` / nearby `aAd` and `aAdsp` string/data material. There is no additional `NewHumanImageLib` secondary/tertiary table in this neighborhood. The prior `LightObjImageLib` table begins at `0x0061b754`, so the `NewHumanImageLib` vtable should stay as the narrow `0x0061b76c-0x0061b778` source-declared/generated-binary island inside the broader image-library read-only data range.

Current IDA data xrefs to the vtable base are still the constructor store at `0x004dfd78` and the ordinary destructor restore/store at `0x004e027e`. The scalar deleting destructor at `0x004e6870` has its vtable data reference at `0x0061b76c`.

## Slots

| Offset | Address | Function |
| --- | --- | --- |
| `+0x00` | `0x004e6870` | `NewHumanImageLib::ScalarDeletingDestructor` |
| `+0x04` | `0x004f4b10` | inherited/shared virtual slot, currently unnamed |
| `+0x08` | `0x0041b6c0` | `nullsub_18` |

The table follows the [UID:0001XY][LightObjImageLibVtable](by-type/by-vtable/LightObjImageLibVtable.md) and two non-vtable function pointers at `0x0061b760`/`0x0061b764`. It ends before `off_61B778` and nearby string/data material.

## Evidence

IDA xrefs to `0x0061b76c` land at:

- `0x004dfd78` in [UID:00017R][0x004dfd10-0x004e68a7.NewHumanImageLib](by-memory/0x004dfd10-0x004e68a7.NewHumanImageLib.md)
- `0x004e027e` in [UID:00017S][0x004e0250-0x004e05c4.NewHumanImageLibDestructor](by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md)

IDA xrefs to the scalar deleting destructor at `0x004e6870` include the vtable slot at `0x0061b76c`.

Active `class_NewHumanImageLib.meta_wave3` currently reports `vtable_count: 0`, so this page is the IDA-confirmed vtable anchor until generated metadata catches up.

## Cross-References

- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md)
- [UID:0001VF][NewHumanImageLibLayout](by-type/by-struct/NewHumanImageLibLayout.md)
- [UID:00017S][0x004e0250-0x004e05c4.NewHumanImageLibDestructor](by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md)
- [UID:00025I][0x0061b664-0x0061c364.ImageLibraryReadOnlyData](by-memory/0x0061b664-0x0061c364.ImageLibraryReadOnlyData.md)
- [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md)

## Changes

- 2026-06-01: The page previously had unevaluated validator scores (`COMPLETION:0`, `CONFIDENCE:0`) and a blank reconstructability flag. It is now marked `RECONSTRUCTABLE:TRUE` with `COMPLETION:86` and `CONFIDENCE:90` after IDA MCP rechecked the decorated vtable global, RTTI locator, three slot values, constructor/destructor data xrefs, scalar deleting destructor slot reference, and the exact end boundary before `off_61B778`. The score remains below the 95+ final-audit gate because the page documents vtable evidence only, not the complete final source declarations and all `NewHumanImageLib` method bodies.
