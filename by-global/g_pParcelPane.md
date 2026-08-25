*** UID:0000RY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:50 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ParcelPane *g_pParcelPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pParcelPane

## B001 UID0002ZO Accepted Callback - 2026-07-21

- This page is the sole semantic source definition: `ParcelPane *g_pParcelPane = NULL;`, emitted once through [UID:0000MF][ParcelPane](by-file/ParcelPane.md) at position 50. Physical page [UID:0002ZO][0x0069ba28-0x0069ba2c.g_pParcelPane](by-memory/0x0069ba28-0x0069ba2c.g_pParcelPane.md) is loader/linker storage evidence only and is now non-emitting.
- The exact physical dword is loader-zeroed virtual-tail `.data` storage, SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`, not a raw `0xffffffff` initializer.
- All nine references are closed: constructor publish/fallback pairs `0x545f03/0x545f0a` and `0x5462e1/0x5462e8`, ordinary-destructor clear `0x54648d`, FlyingParcelPane reads `0x546dbc/0x546dd2`, EH clear `0x546e80`, and scalar-wrapper clear `0x547054`.
- ParcelPane directly derives `Singleton<ParcelPane>`. Publication, null fallback on unwind, and reverse-order destruction clear are compiler lowering of that direct base; handwritten constructor/destructor bodies do not assign this global.
- Exact neighbors are the separate BowGauge physical slot ending at `0x0069ba28` and PatchPane2 physical slot beginning at `0x0069ba2c`. No aggregate declaration, duplicate definition, manual clear helper, or second source owner is justified.
- Source placement is the coherent `NexusTK/ui/panels/ParcelPane.cpp` union. The score is `92/94`: type, one-definition route, storage, lifetime, consumers, and placement are closed; missing original symbols keep confidence below 95.

## Status

- Address: `0x0069ba28`
- Primary memory doc: [UID:0002ZO][0x0069ba28-0x0069ba2c.g_pParcelPane](by-memory/0x0069ba28-0x0069ba2c.g_pParcelPane.md)
- Likely type: `ParcelPane*`
- Likely owner file: [UID:0000MF][ParcelPane](by-file/ParcelPane.md)
- Autogen parent: [UID:0000MF][ParcelPane](by-file/ParcelPane.md)
- Confidence: strong

## Purpose

`g_pParcelPane` stores the active parcel alert child pane. Parcel icon construction allocates and initializes it, `ParcelPane` construction/destruction paths set or clear it, and `FlyingParcelPane` uses it to update parcel slot state after delivery animation. This is separate from [UID:0000RX][g_pParcelIconPane](by-global/g_pParcelIconPane.md), which stores the outer parcel notification icon pane.

## Evidence

- 2026-05-25 IDA MCP xrefs to `0x0069ba28` include writes in `ParcelIconPane` constructor `0x00545e40`, writes in `ParcelPane` constructor `0x00546290`, clears in non-deleting destructor `0x00546440`, reads/writes in `FlyingParcelPane::AnimateStep` `0x00546d70`, non-emitting constructor/EH cleanup funclet clear at `0x00546e80`, and clear in `ParcelPane` scalar deleting destructor `0x00547000`.
- The `0x005461c0` parcel packet/update callback does not reference the global directly; IDA places it in `ParcelIconPane`'s secondary vtable and it forwards to the associated child `ParcelPane` pointer at the icon-pane layout.
- Existing `DialogPane`-side focus drawing uses `g_pParcelPane` to clear an object highlight target, making this a global UI/HUD singleton rather than a local stack pointer.

## 2026-05-30 Review Notes

- IDA MCP `py_eval` on 2026-05-30 confirms `0x0069ba28` is `dword_69BA28`, size `4`, in `.data`, with 9 data xrefs.
- Live IDA xrefs confirm parcel-icon construction writes at `0x00545f03` and `0x00545f0a` in `sub_545E40`, parcel-pane construction writes at `0x005462e1` and `0x005462e8` in `sub_546290`, destructor clear at `0x0054648d` in `sub_546440`, flying-parcel animation use at `0x00546dbc` and `0x00546dd2` in `sub_546D70`, singleton clear at `0x00546e80` in `sub_546E80`, and scalar deleting destructor clear at `0x00547054` in `sub_547000`.
- Live IDA MCP also confirms adjacent `0x0069ba2c` is `dword_69BA2C`, `.data` size `4`, with 5 xrefs belonging to the PatchPane2 singleton, matching [UID:0002A0][0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots](by-memory/0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots.md).
- Live IDA decompilation on 2026-06-05 confirms both the parcel-icon constructor path at `0x00545e40` and the standalone `ParcelPane` constructor at `0x00546290` store into `dword_69BA28`; `0x00546440`, `0x00546e80`, and `0x00547000` clear the singleton, and `0x00546d70` uses it during flying-parcel animation.
- Completion now reaches the corrected assignment gate because the parcel/patch singleton cluster has been split into exact child storage pages. Remaining uncertainty is final source declaration spelling and the precise source placement for the broader parcel file.
- 2026-06-14 B003 IDA/PE recheck supersedes the earlier initializer wording: `0x0069ba28` is a `.data` item `dword_69BA28`, size `4`, bytes/value `00 00 00 00` / `0`, with the same nine refs in `sub_545E40`, `sub_546290`, `sub_546440`, `sub_546D70`, `sub_546E80`, and `sub_547000`.

## Lifecycle Evidence

| Site | Access | Meaning |
| --- | --- | --- |
| `0x00545f03` in `0x00545e40-0x0054606a` | write child pointer | `ParcelIconPane` construction publishes the owned child `ParcelPane` singleton after allocating/initializing it. |
| `0x00545f0a` in `0x00545e40-0x0054606a` | write `0` | Constructor-family fallback clears the child-pane singleton slot. |
| `0x005462e1` in `0x00546290-0x00546436` | write `this` | Standalone `ParcelPane` constructor publishes itself in the same singleton slot. |
| `0x005462e8` in `0x00546290-0x00546436` | write `0` | Constructor-family fallback clears the singleton after the `ParcelPane` vtable setup path. |
| `0x0054648d` in `0x00546440-0x005464ac` | write `0` | Non-deleting `ParcelPane` destructor clears the child singleton during pane teardown. |
| `0x00546dbc` and `0x00546dd2` in `0x00546d70-0x00546dee` | read/write through pointer | `FlyingParcelPane` animation completion forwards slot counts into the active child pane and invalidates it. |
| `0x00546e80-0x00546e8b` | write `0` | [UID:0002KN][0x00546e80-0x00546e8b.ClearParcelPaneSingleton](by-memory/0x00546e80-0x00546e8b.ClearParcelPaneSingleton.md) is a non-emitting constructor/EH cleanup funclet that clears this slot from the ParcelIconPane inline child-construction unwind path and the standalone ParcelPane constructor unwind path; it is not a handwritten file-scope helper. |
| `0x00547054` in `0x00547000-0x005470ad` | write `0` | Scalar deleting destructor clears the child singleton before optional object free. |

The adjacent data slot at `0x0069ba2c` is the [UID:0000AA][PatchPane2](by-class/PatchPane2.md) singleton, not additional `ParcelPane` state. Keep `g_pParcelPane` declared as one pointer-sized global at `0x0069ba28`.

## 2026-06-07 A001 Gate Review

- Live IDA MCP reconfirmed the exact storage as `dword_69BA28`, four bytes in `.data`, loader-zeroed in the virtual `.data` tail, with nine data xrefs.
- The former mixed memory aggregate [UID:0002A0][0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots](by-memory/0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots.md) has been split; the exact child storage page is [UID:0002ZO][0x0069ba28-0x0069ba2c.g_pParcelPane](by-memory/0x0069ba28-0x0069ba2c.g_pParcelPane.md).
- A001 left this page unassigned when [UID:0000MF][ParcelPane](by-file/ParcelPane.md) was still `86/80`, below the corrected `85/85` confidence gate.
- A002 Batch 078 restores `AUTOGEN_PARENT_UID:0000MF` after the ParcelPane file page reached `86/85`; the relationship is direct because the file owns the parcel notification classes and singleton lifecycle users. The exact memory child [UID:0002ZO][0x0069ba28-0x0069ba2c.g_pParcelPane](by-memory/0x0069ba28-0x0069ba2c.g_pParcelPane.md) also routes to the same source-file parent because generated memory coverage rejects by-global parent UIDs.

## Ownership Decision

Declare this with the parcel notification module. Other UI classes may read or clear state through it, but the storage is owned by `ParcelPane.cpp`. B005 resolves the previous blank global-declaration state with formal source `ParcelPane *g_pParcelPane = NULL;`; exact storage children should reference this declaration rather than emit duplicate definitions.

## 2026-06-30 B005 Empty-Emitter Implementation

B005 raises this page to `88/91` and populates the formal source declaration `ParcelPane *g_pParcelPane = NULL;`. The exact storage page [UID:0002ZO][0x0069ba28-0x0069ba2c.g_pParcelPane](by-memory/0x0069ba28-0x0069ba2c.g_pParcelPane.md) now carries only a covered-by-global no-code marker so the rebuilt source has one declaration, not duplicate definitions.

## Cross-References

- [UID:0000MF][ParcelPane](by-file/ParcelPane.md)
- [UID:0000A6][ParcelPane](by-class/ParcelPane.md)
- [UID:0000A5][ParcelIconPane](by-class/ParcelIconPane.md)
- [UID:0002ZO][0x0069ba28-0x0069ba2c.g_pParcelPane](by-memory/0x0069ba28-0x0069ba2c.g_pParcelPane.md)
- [UID:0001EH][0x00545e40-0x005470ad.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md)
- [UID:0002A0][0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots](by-memory/0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots.md)
- [UID:0001EK][0x00546440-0x005464ac.ParcelPaneDestructor](by-memory/0x00546440-0x005464ac.ParcelPaneDestructor.md)
- [UID:0002KK][0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep](by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md)
- [UID:0002KN][0x00546e80-0x00546e8b.ClearParcelPaneSingleton](by-memory/0x00546e80-0x00546e8b.ClearParcelPaneSingleton.md)
- [UID:0001EP][0x00547000-0x005470ad.ParcelPaneScalarDeletingDestructor](by-memory/0x00547000-0x005470ad.ParcelPaneScalarDeletingDestructor.md)
- [UID:0000RX][g_pParcelIconPane](by-global/g_pParcelIconPane.md)

## Changes

- 2026-06-26 B007 accepted ParcelNotificationPanes support sync:
  - Updated the lifecycle table and evidence wording for `0x00546e80-0x00546e8b` from compact file-scope clear helper to non-emitting constructor/EH cleanup funclet clearing `g_pParcelPane`.
  - Preserved the normal lifecycle refs: `ParcelIconPane` child construction publishes/fallback-clears the singleton, standalone `ParcelPane` construction publishes/fallback-clears it, `ParcelPane` destructor and scalar deleting destructor clear it, and `FlyingParcelPane::AnimateStep` uses it to forward slot data and invalidate the parcel pane.
  - This page remains the parcel module global declaration support page; no formal C++ body was added.
- Before: completion/confidence were ungraded at `0/0`, and Evidence included weak placement wording.
- Changed to: completion `80`, confidence `86`; weak placement wording was removed from Evidence.
- Summary/evidence: live IDA MCP on 2026-05-30 verified exact storage, size, segment, 9 xrefs, parcel icon/pane constructor writes, destructor/clear-helper clears, and FlyingParcelPane animation use. Completion remains below full until the DialogPane-side consumer and parcel/patch data cluster are fully split/named.

- 2026-06-05 autogen classification:
  - What existed before: autogen metadata was blank, so the singleton was reported as unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with `AUTOGEN_PARENT_UID:0000MF`; `RECONSTRUCTION_CPP CODE` remains empty.
  - Summary/evidence: live IDA MCP `xrefs_to 0x0069ba28` and decompilation of `0x00545e40`, `0x00546290`, `0x00546440`, `0x00546d70`, `0x00546e80`, and `0x00547000` proved NexusTK-owned `ParcelPane` singleton storage owned by [UID:0000MF][ParcelPane](by-file/ParcelPane.md). No final C++ body was added at that time because the page was below the then-current code-entry gate; B005 supersedes this with the accepted global declaration.
- 2026-06-06: Raised grading from `80/86` to `82/88`.
  - Before: the page had the main singleton role and xref list, but its evidence was less explicit than the newer parcel child/destructor pages and the adjacent `g_pParcelIconPane` singleton page.
  - After: added a lifecycle evidence table for constructor publish/fallback clears, non-deleting destructor clear, flying parcel animation consumer, clear helper, scalar deleting destructor clear, and the `0x0069ba2c` PatchPane2 boundary.
  - Evidence: existing IDA-backed by-memory docs for [UID:0002A0][0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots](by-memory/0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots.md), [UID:0001EK][0x00546440-0x005464ac.ParcelPaneDestructor](by-memory/0x00546440-0x005464ac.ParcelPaneDestructor.md), [UID:0002KK][0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep](by-memory/0x00546d70-0x00546dee.FlyingParcelPaneAnimateStep.md), [UID:0002KN][0x00546e80-0x00546e8b.ClearParcelPaneSingleton](by-memory/0x00546e80-0x00546e8b.ClearParcelPaneSingleton.md), and [UID:0001EP][0x00547000-0x005470ad.ParcelPaneScalarDeletingDestructor](by-memory/0x00547000-0x005470ad.ParcelPaneScalarDeletingDestructor.md) corroborated the storage, lifetime, and pointer-sized boundary. The historical blank C++ state is superseded by the B005 global declaration.
- 2026-06-07 A001 Batch 054 parent-gate refresh:
  - Before: score `82/88`; `AUTOGEN_PARENT_UID` pointed to [UID:0000MF][ParcelPane](by-file/ParcelPane.md), whose confidence is below the corrected `85/85` gate.
  - Changed to: score `85/90`, `AUTOGEN_PARENT_UID` blank, explicit primary exact memory child, and an assignment-gate note.
  - Summary/evidence: live IDA reconfirmed the exact four-byte storage, nine xrefs, constructor publish/fallback clears, destructor/helper clears, animation consumer references, and the new split child. The direct by-file parent was not raised because its broader source-unit confidence remains below gate.
- 2026-06-07 A002 Batch 078 parent-chain repair:
  - Changed to: `AUTOGEN_PARENT_UID:0000MF`; score unchanged at `85/90`.
  - Summary/evidence: live IDA recheck reconfirmed exact storage and refs, and the direct file parent [UID:0000MF][ParcelPane](by-file/ParcelPane.md) now clears `86/85`. The exact memory child [UID:0002ZO][0x0069ba28-0x0069ba2c.g_pParcelPane](by-memory/0x0069ba28-0x0069ba2c.g_pParcelPane.md) was routed to the same file parent to repair generated memory `autogen_parent_unknown` without weakening the global evidence anchor.
