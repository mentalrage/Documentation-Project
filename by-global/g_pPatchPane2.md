*** UID:0000RZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pPatchPane2

## Status

- Address: `0x0069ba2c`
- Likely type: `PatchPane2*`
- Likely owner file: [UID:0000MH][PatchPane](by-file/PatchPane.md)
- Confidence: strong

## Purpose

`g_pPatchPane2` stores the active alternate patch dialog singleton. `PatchPane2::PatchPane2` sets it, the clear helper at `0x00549340` and scalar deleting destructor at `0x00549370` clear it, and work-thread/download callbacks can use it as the active patch target.

## Evidence

- IDA MCP decompilation of `0x00548690` writes `dword_69BA2C = this`.
- IDA MCP decompilation of `0x00549340` and `0x00549370` clears `dword_69BA2C`.
- IDA MCP `xrefs_to 0x0069ba2c` on 2026-05-25 reports constructor writes at `0x005486f4` and `0x005486fb`, a nearby cleanup reference at `0x00548a6d`, the clear-helper write at `0x00549340`, and the scalar-destructor write at `0x005493d0`.
- [UID:0001VJ][PatchPane2Layout](by-type/by-struct/PatchPane2Layout.md) records the surrounding object fields that are live while this singleton is set.

## 2026-05-30 Review Notes

- IDA MCP `py_eval` on 2026-05-30 confirms `0x0069ba2c` is `dword_69BA2C`, size `4`, in `.data`, with 5 data xrefs.
- Live IDA xrefs confirm constructor writes at `0x005486f4` and `0x005486fb` in `sub_548690`, a cleanup/body reference at `0x00548a6d`, singleton clear helper at `0x00549340` in `sub_549340`, and scalar deleting destructor clear at `0x005493d0` in `sub_549370`.
- Live IDA MCP also confirms adjacent `0x0069ba28` as the `ParcelPane` singleton slot, matching [UID:0002A0][0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots](by-memory/0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots.md).
- Completion remains below full because the `0x00548a6d` reference needs precise source-level classification inside the PatchPane2 lifecycle.

## Ownership Decision

Declare this with the patch/update module. It is not an application-wide manager; it is lifecycle-bound to `PatchPane2`.

## Cross-References

- [UID:0000MH][PatchPane](by-file/PatchPane.md)
- [UID:0000AA][PatchPane2](by-class/PatchPane2.md)
- [UID:0001VJ][PatchPane2Layout](by-type/by-struct/PatchPane2Layout.md)
- [UID:0001EQ][0x005470b0-0x0054940f.PatchPaneAndPatchPane2](by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md)
- [UID:0001EZ][0x00549340-0x0054934b.ClearPatchPane2Singleton](by-memory/0x00549340-0x0054934b.ClearPatchPane2Singleton.md)
- [UID:0002A0][0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots](by-memory/0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`, and Evidence included generated metadata.
- Changed to: completion `80`, confidence `88`; generated metadata was removed from Evidence.
- Summary/evidence: live IDA MCP on 2026-05-30 verified exact storage, size, segment, 5 xrefs, constructor writes, clear-helper write, and scalar-deleting-destructor clear. Completion remains below full until the `0x00548a6d` lifecycle reference is precisely classified.
