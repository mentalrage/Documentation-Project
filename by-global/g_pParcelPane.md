*** UID:0000RY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pParcelPane

## Status

- Address: `0x0069ba28`
- Likely type: `ParcelPane*`
- Likely owner file: [UID:0000MF][ParcelPane](by-file/ParcelPane.md)
- Confidence: strong

## Purpose

`g_pParcelPane` stores the active parcel alert child pane. Parcel icon construction allocates and initializes it, `ParcelPane` construction/destruction paths set or clear it, and `FlyingParcelPane` uses it to update parcel slot state after delivery animation.

## Evidence

- 2026-05-25 IDA MCP xrefs to `0x0069ba28` include writes in `ParcelIconPane` constructor `0x00545e40`, writes in `ParcelPane` constructor `0x00546290`, clears in non-deleting destructor `0x00546440`, reads/writes in `FlyingParcelPane::AnimateStep` `0x00546d70`, clear helper `0x00546e80`, and clear in `ParcelPane` scalar deleting destructor `0x00547000`.
- The `0x005461c0` parcel packet/update callback does not reference the global directly; IDA places it in `ParcelIconPane`'s secondary vtable and it forwards to the associated child `ParcelPane` pointer at the icon-pane layout.
- Existing `DialogPane`-side focus drawing uses `g_pParcelPane` to clear an object highlight target, making this a global UI/HUD singleton rather than a local stack pointer.

## 2026-05-30 Review Notes

- IDA MCP `py_eval` on 2026-05-30 confirms `0x0069ba28` is `dword_69BA28`, size `4`, in `.data`, with 9 data xrefs.
- Live IDA xrefs confirm parcel-icon construction writes at `0x00545f03` and `0x00545f0a` in `sub_545E40`, parcel-pane construction writes at `0x005462e1` and `0x005462e8` in `sub_546290`, destructor clear at `0x0054648d` in `sub_546440`, flying-parcel animation use at `0x00546dbc` and `0x00546dd2` in `sub_546D70`, singleton clear at `0x00546e80` in `sub_546E80`, and scalar deleting destructor clear at `0x00547054` in `sub_547000`.
- Live IDA MCP also confirms adjacent `0x0069ba2c` is `dword_69BA2C`, `.data` size `4`, with 5 xrefs belonging to the PatchPane2 singleton, matching [UID:0002A0][0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots](by-memory/0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots.md).
- Completion remains below full because the DialogPane-side focus/highlight consumer needs precise source-level naming and the parcel/patch singleton cluster could still use a dedicated global-data split pass.

## Ownership Decision

Declare this with the parcel notification module. Other UI classes may read or clear state through it, but the storage is owned by `ParcelPane.cpp`.

## Cross-References

- [UID:0000MF][ParcelPane](by-file/ParcelPane.md)
- [UID:0000A6][ParcelPane](by-class/ParcelPane.md)
- [UID:0000A5][ParcelIconPane](by-class/ParcelIconPane.md)
- [UID:0001EH][0x00545e40-0x005470ac.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ac.ParcelNotificationPanes.md)
- [UID:0002A0][0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots](by-memory/0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`, and Evidence included generated-data placement.
- Changed to: completion `80`, confidence `86`; generated-data placement was removed from Evidence.
- Summary/evidence: live IDA MCP on 2026-05-30 verified exact storage, size, segment, 9 xrefs, parcel icon/pane constructor writes, destructor/clear-helper clears, and FlyingParcelPane animation use. Completion remains below full until the DialogPane-side consumer and parcel/patch data cluster are fully split/named.
