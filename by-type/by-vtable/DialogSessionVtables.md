*** UID:0001XD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DialogSession Vtables

## Status

- Entity kind: vtable cluster.
- Covered classes: [UID:00003U][DialogSession](by-class/DialogSession.md) and [UID:00003S][DialogInSession](by-class/DialogInSession.md).
- Likely source file: [UID:0000IU][DialogSession](by-file/DialogSession.md).
- Layout docs: [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md).
- Exact vtable-data page: [UID:0002NB][0x00618d30-0x00618e50.DialogSessionVtableData](by-memory/0x00618d30-0x00618e50.DialogSessionVtableData.md).
- Autogen status: attached under the file-level [UID:0000IU][DialogSession](by-file/DialogSession.md) parent because this vtable cluster spans both session classes; final C++ remains blank under the `95/95` gate.
- Confidence: strong for vtable bases, constructor/destructor stores, thunk slots, and table extents.
- Verification: IDA MCP `list_globals`, `py_eval`, `xrefs_to`, `lookup_funcs`, and `disasm` checks on 2026-05-26. `wave3.py` was not executed for this pass.

## Vtable Bases

| Class | View | Base | Constructor store | Destructor stores | Object offset |
| --- | --- | --- | --- | --- | --- |
| `DialogSession` | primary | `0x00618d30` | `0x004a0dc1` | `0x004a0e9e`, `0x004a152e` | `+0x00` |
| `DialogSession` | secondary | `0x00618d7c` | `0x004a0dc7` | `0x004a0ea4`, `0x004a1534` | `+0xa0` |
| `DialogSession` | tertiary | `0x00618dac` | `0x004a0dd1` | `0x004a0eae`, `0x004a153e` | `+0xa4` |
| `DialogInSession` | primary | `0x00618db8` | `0x004a142d` | `0x004a1450`, `0x004a14a6` | `+0x00` |
| `DialogInSession` | secondary | `0x00618e18` | `0x004a1433` | `0x004a1456`, `0x004a14ac` | `+0xa0` |
| `DialogInSession` | tertiary | `0x00618e48` | `0x004a143d` | `0x004a1460`, `0x004a14b6` | `+0xa4` |

## Notable Slots

| Vtable | Slot | Target | Notes |
| --- | --- | --- | --- |
| `DialogSession` primary `0x00618d30` | `+0x00` | `0x004a1500` | `DialogSession` scalar deleting destructor. |
| `DialogSession` primary `0x00618d30` | `+0x30` | `0x00544c70` | Pane/session bounds setup slot used by the constructor path. |
| `DialogSession` primary `0x00618d30` | `+0x3c` | `0x00544d30` | Pane interaction/attachment slot used by the constructor path. |
| `DialogSession` secondary `0x00618d7c` | `+0x00` | `0x004a1485` | Secondary destructor adjustor thunk, subtracts `0xa0` then jumps to `0x004a1500`. |
| `DialogSession` secondary `0x00618d7c` | `+0x1c` | `0x004a89f0` | Shared dialog/event-support slot inherited from nearby pane infrastructure. |
| `DialogSession` tertiary `0x00618dac` | `+0x00` | `0x004a1490` | Tertiary destructor adjustor thunk, subtracts `0xa4` then jumps to `0x004a1500`. |
| `DialogSession` tertiary `0x00618dac` | `+0x04` | `0x00544e90` | Base/default event-update slot. |
| `DialogInSession` primary `0x00618db8` | `+0x00` | `0x004a14a0` | `DialogInSession` scalar deleting destructor. |
| `DialogInSession` primary `0x00618db8` | `+0x30` | `0x0049dfd0` | Inherited `DialogPane` bounds/layout initialization virtual. |
| `DialogInSession` primary `0x00618db8` | `+0x44` | `0x0049f090` | Inherited `DialogPane` focus/selection drawing virtual. |
| `DialogInSession` primary `0x00618db8` | `+0x58` | `0x0049fc00` | Inherited `DialogPane` hover/update virtual. |
| `DialogInSession` secondary `0x00618e18` | `+0x00` | `0x004a146f` | Secondary destructor adjustor thunk, subtracts `0xa0` then jumps to `0x004a14a0`. |
| `DialogInSession` secondary `0x00618e18` | `+0x04` | `0x0049e240` | Inherited dialog secondary-view slot. |
| `DialogInSession` secondary `0x00618e18` | `+0x08` | `0x0049e6e0` | Inherited dialog secondary-view slot. |
| `DialogInSession` secondary `0x00618e18` | `+0x0c` | `0x0049ea60` | Inherited dialog secondary-view slot. |
| `DialogInSession` tertiary `0x00618e48` | `+0x00` | `0x004a147a` | Tertiary destructor adjustor thunk, subtracts `0xa4` then jumps to `0x004a14a0`. |
| `DialogInSession` tertiary `0x00618e48` | `+0x04` | `0x00544e90` | Base/default event-update slot. |

## Extent Notes

- `DialogSession` primary table `0x00618d30` ends before secondary RTTI at `0x00618d78`.
- `DialogSession` secondary table `0x00618d7c` ends before tertiary RTTI at `0x00618da8`.
- `DialogSession` tertiary table `0x00618dac` has two slots and ends before `DialogInSession` RTTI at `0x00618db4`.
- `DialogInSession` primary table `0x00618db8` ends before secondary RTTI at `0x00618e14`.
- `DialogInSession` secondary table `0x00618e18` ends before tertiary RTTI at `0x00618e44`.
- `DialogInSession` tertiary table `0x00618e48` has two slots and ends before `DIBitmap` RTTI at `0x00618e50`.

## IDA MCP Evidence

- `list_globals *DialogSession*` reports vtable bases at `0x00618d30`, `0x00618d7c`, and `0x00618dac`, plus RTTI records at `0x00646794`, `0x006467a8`, and `0x006467bc`.
- `list_globals *DialogInSession*` reports vtable bases at `0x00618db8`, `0x00618e18`, and `0x00618e48`, plus RTTI records at `0x00646758`, `0x0064676c`, and `0x00646780`.
- `xrefs_to` the `DialogSession` table bases reports stores from constructor `0x004a0d80`, non-deleting destructor `0x004a0e70`, and scalar deleting destructor `0x004a1500`.
- `xrefs_to` the `DialogInSession` table bases reports stores from constructor `0x004a1400`, non-deleting destructor `0x004a1450`, and scalar deleting destructor `0x004a14a0`.
- `disasm` confirms the four adjustor thunks at `0x004a146f`, `0x004a147a`, `0x004a1485`, and `0x004a1490`; each subtracts the secondary/tertiary subobject offset and jumps to the owning scalar deleting destructor.
- Current Wave3 metadata for both `class_DialogSession.meta_wave3` and `class_DialogInSession.meta_wave3` reports `vtable_count: 0`, so generated vtable inventory is incomplete.

## Reconstruction Notes

Keep `DialogSession` and `DialogInSession` in one source module unless later historical source evidence proves a split. `DialogSession` is a `Pane`-derived session stack owner, while `DialogInSession` is a `DialogPane`-derived base for dialogs stored inside that stack. Their concrete state offsets are recorded in [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md). The four adjustor thunks are compiler ABI glue and should remain documented with [UID:000134][0x004a146f-0x004a149b.DialogSessionAdjustorThunks](by-memory/0x004a146f-0x004a149b.DialogSessionAdjustorThunks.md), not rewritten as handwritten methods.

## Parent Rationale

Attach the cluster to [UID:0000IU][DialogSession](by-file/DialogSession.md), not to a single class page. The six-view vtable range covers both [UID:00003U][DialogSession](by-class/DialogSession.md) and [UID:00003S][DialogInSession](by-class/DialogInSession.md), the file page already owns both classes and clears the `80/80` attachment gate, and the `DialogInSession` class page is still below the completion gate. Keeping the autogen parent at file scope preserves the documented one-module relationship while avoiding a misleading single-class ownership claim.

## Cross-References

- [UID:0000IU][DialogSession](by-file/DialogSession.md)
- [UID:00003U][DialogSession](by-class/DialogSession.md)
- [UID:00003S][DialogInSession](by-class/DialogInSession.md)
- [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md)
- [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md)
- [UID:000134][0x004a146f-0x004a149b.DialogSessionAdjustorThunks](by-memory/0x004a146f-0x004a149b.DialogSessionAdjustorThunks.md)
- [UID:0002NB][0x00618d30-0x00618e50.DialogSessionVtableData](by-memory/0x00618d30-0x00618e50.DialogSessionVtableData.md)

## Changes

- 2026-06-07 parent attachment update:
  - What existed before: the page had strong vtable evidence and an exact by-memory child, but no autogen parent, so generated output left the cluster unassigned.
  - Changed to: `COMPLETION:86` and `AUTOGEN_PARENT_UID:0000IU`, with an explicit file-level parent rationale.
  - Summary/evidence: the cluster spans both `DialogSession` and `DialogInSession`, while [UID:0000IU][DialogSession](by-file/DialogSession.md) documents that shared source module and clears the attachment gate; final C++ remains blank because the vtable page is below the `95/95` reconstruction threshold.
- 2026-05-31 exact child split:
  - What existed before: the page had `COMPLETION:0`, `CONFIDENCE:0`, blank reconstructability metadata, and no exact `by-memory` vtable-data child.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:90`, `RECONSTRUCTABLE:TRUE`, and the exact [UID:0002NB][0x00618d30-0x00618e50.DialogSessionVtableData](by-memory/0x00618d30-0x00618e50.DialogSessionVtableData.md) child page.
  - Summary/evidence: 2026-05-31 IDA MCP `list_globals`, `lookup_funcs`, `xrefs_to`, and dword reads reconfirm the six table bases, constructor/destructor store xrefs, destructor-adjustor thunk targets, key slots, and `0x00618e50` boundary before `DIBitmap` RTTI; score remains below `95+` because final source declarations and session helper names still need a broader final-source audit.
