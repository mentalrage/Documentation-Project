*** UID:0000RX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pParcelIconPane

## Status

- Address: `0x0069b4d0`
- IDA name: `dword_69B4D0`
- Likely type: `ParcelIconPane*`
- Likely owner file: [UID:0000MF][ParcelPane](by-file/ParcelPane.md)
- Confidence: strong

## Purpose

`g_pParcelIconPane` stores the active outer parcel notification icon pane. It is distinct from [UID:0000RY][g_pParcelPane](by-global/g_pParcelPane.md), which points at the embedded child pane that renders the two parcel/letter slots.

## Evidence

- 2026-05-25 IDA MCP xrefs to `0x0069b4d0` include a read in `sub_5047F0` at `0x005048d5`, writes in `ParcelIconPane` constructor `0x00545e40`, clears in non-deleting destructor `0x00546070`, clear helper `0x00546e70`, and scalar deleting destructor `0x00546f40`.
- `ParcelIconPane` destructor paths dismiss the associated child pane before clearing this singleton, matching ownership of the outer icon object rather than the child [UID:0000A6][ParcelPane](by-class/ParcelPane.md).

## Lifecycle Evidence

| Site | Access | Meaning |
| --- | --- | --- |
| `0x005048d5` in `0x005047f0` | read | Main UI shutdown/read path checks whether the outer parcel icon pane exists. |
| `0x00545e91` in `0x00545e40-0x0054606a` | write `this` | `ParcelIconPane` constructor publishes the outer notification icon singleton. |
| `0x00545e98` in `0x00545e40-0x0054606a` | write `0` | Constructor-family fallback clear for the same singleton slot. |
| `0x005460c9` in `0x00546070-0x005460e8` | write `0` | Non-deleting destructor clears the singleton after child-pane dismissal and pane cleanup. |
| `0x00546e70-0x00546e7b` | write `0` | [UID:0002KM][0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton](by-memory/0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton.md) clears the slot as compact parcel cleanup support. |
| `0x00546fa0` in `0x00546f40-0x00546ff9` | write `0` | Scalar deleting destructor clears the singleton before optional delete handling. |

## 2026-05-30 Review Notes

- IDA MCP `py_eval` on 2026-05-30 confirms `0x0069b4d0` is `dword_69B4D0`, size `4`, in `.data`, with 6 data xrefs.
- Live IDA xrefs confirm the shutdown/main-UI reader at `0x005048d5` in `0x005047f0`, constructor writes at `0x00545e91` and `0x00545e98` in `0x00545e40`, destructor clear at `0x005460c9` in `0x00546070`, singleton clear at `0x00546e70` in `ClearParcelIconPaneSingleton`, and scalar deleting destructor clear at `0x00546fa0` in `0x00546f40`.
- This slot is distinct from `0x0069b4d4`, which live IDA names `dword_69B4D4` and existing docs identify as [UID:0000SB][g_pSoundStatusPane](by-global/g_pSoundStatusPane.md), not `g_pParcelPane`.
- Live IDA decompilation on 2026-06-05 confirms `0x00545e40` stores `this` into `dword_69B4D0` and installs the `ParcelIconPane` vtable, while `0x00546070`, `0x00546e70`, and `0x00546f40` clear the singleton during cleanup/destruction.
- Completion remains below full because the shutdown/main-UI reader at `0x005048d5` still needs a precise source-level owner/name.

## Ownership Decision

Declare this with the parcel notification module. Keep it separate from `g_pParcelPane` so source migration preserves the two-object lifetime model.

## Cross-References

- [UID:0000MF][ParcelPane](by-file/ParcelPane.md)
- [UID:0000A5][ParcelIconPane](by-class/ParcelIconPane.md)
- [UID:0001EG][0x00545e40-0x0054606a.ParcelIconPaneConstructor](by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md)
- [UID:0001EI][0x00546070-0x005460e8.ParcelIconPaneDestructor](by-memory/0x00546070-0x005460e8.ParcelIconPaneDestructor.md)
- [UID:0002KM][0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton](by-memory/0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton.md)
- [UID:0001EO][0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor](by-memory/0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor.md)
- [UID:0001EH][0x00545e40-0x005470ac.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ac.ParcelNotificationPanes.md)
- [UID:0000RY][g_pParcelPane](by-global/g_pParcelPane.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`, and Evidence included weak placement wording.
- Changed to: completion `78`, confidence `86`; weak placement wording was removed from Evidence.
- Summary/evidence: live IDA MCP on 2026-05-30 verified exact storage, size, segment, 6 xrefs, constructor/destructor/clear-helper writes, and the main-UI reader. Completion remains below full until the main-UI reader source-level owner is named.

- 2026-06-05 autogen classification:
  - What existed before: autogen metadata was blank, so the singleton was reported as unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with `AUTOGEN_PARENT_UID:0000MF`; `RECONSTRUCTION_CPP CODE` remains empty.
  - Summary/evidence: live IDA MCP `xrefs_to 0x0069b4d0` and decompilation of `0x00545e40`, `0x00546070`, `0x00546e70`, and `0x00546f40` prove NexusTK-owned `ParcelIconPane` singleton storage owned by [UID:0000MF][ParcelPane](by-file/ParcelPane.md). No final C++ body was added because the page is below the 95/95 reconstruction gate.
- 2026-06-06: Raised grading from `78/86` to `82/88`.
  - Before: the page recorded the singleton role and xrefs, but lacked a lifecycle table and still carried one unresolved raw helper token.
  - After: added lifecycle evidence covering main-UI read, constructor publish/fallback clear, non-deleting destructor clear, `ClearParcelIconPaneSingleton`, and scalar deleting destructor clear; added direct cross-references to the destructor and clear-helper pages.
  - Evidence: existing parcel by-memory pages document the constructor, ordinary destructor, clear helper, scalar deleting destructor, and parcel family aggregate, while [UID:0002KM][0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton](by-memory/0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton.md) records the exact two-instruction helper at `82/91`.
