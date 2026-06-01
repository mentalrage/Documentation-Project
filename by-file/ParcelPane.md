*** UID:0000MF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ParcelPane

## Status

- Proposed module: `ui/panels/ParcelPane.cpp` or original flat `ParcelPane.cpp`
- Proposed header: `ui/panels/ParcelPane.h`
- Confidence: strong for parcel notification family grouping, medium for final folder.
- Current generated sources: `class_ParcelPane.cpp`, `class_FlyingParcelPane.cpp`, `class_ParcelIconPane.cpp`
- Vtable/type evidence: [UID:0001YE][ParcelNotificationVtableFamily](by-type/by-vtable/ParcelNotificationVtableFamily.md)
- Layout evidence: [UID:0001VI][ParcelNotificationPaneLayouts](by-type/by-struct/ParcelNotificationPaneLayouts.md)
- Related generated-data caveat: `class_ParcelPane.meta_wave3` and generated ParcelPane global-data rows still reference FPS diagnostics globals/method context that should remain with [UID:0000JK][FpsPane](by-file/FpsPane.md).

## File Role

`ParcelPane.cpp` likely owned the in-game parcel notification UI: the small two-slot alert pane, the flying parcel animation helper, and the outer parcel icon pane that constructs and manages the notification child pane.

This is a HUD/panel module, not mail-dialog body UI and not the patch/update screen. IDA shows [UID:0000MH][PatchPane](by-file/PatchPane.md) begins at `0x005470b0`, immediately after the parcel pane destructor cluster, so keep patching code out of this file.

## Proposed Contents

| Entity | Current range | Current generated owner | Proposed ownership |
| --- | --- | --- | --- |
| [UID:0000A5][ParcelIconPane](by-class/ParcelIconPane.md) constructor/destructor/update helpers | `0x00545e40-0x005460e8`, `0x005461c0-0x0054628d`, `0x00546ea1-0x00546eb7`, `0x00546f40-0x00546ff9` | partial `class_ParcelIconPane.cpp`; update callback not emitted in active source | `ParcelPane.cpp` |
| [UID:0000A6][ParcelPane](by-class/ParcelPane.md) core | `0x00546290-0x00546aaa`, `0x00546e80`, `0x00546eb7-0x00546ecd`, `0x00547000-0x005470ad` | `class_ParcelPane.cpp` | `ParcelPane.cpp` |
| [UID:000058][FlyingParcelPane](by-class/FlyingParcelPane.md) | `0x00546ac0-0x00546f36`, including omitted raw bodies at `0x00546b80-0x00546d64` | partial `class_FlyingParcelPane.cpp` | `ParcelPane.cpp` |
| [UID:0000RY][g_pParcelPane](by-global/g_pParcelPane.md) | `0x0069ba28` | `class_ParcelPane.cpp` | `ParcelPane.cpp` module global |
| [UID:0000RX][g_pParcelIconPane](by-global/g_pParcelIconPane.md) | `0x0069b4d0` | `class_ParcelIconPane.cpp` | `ParcelPane.cpp` module global |

## Evidence

- IDA MCP confirms `ParcelPane` functions at `0x00546290`, `0x005464b0`, `0x005465e0`, `0x00546610`, `0x00546810`, `0x00546890`, `0x00546970`, `0x005469e0`, and `0x00547000`.
- IDA MCP confirms a non-deleting `ParcelPane` destructor body at `0x00546440`, which current active Wave3 output does not emit.
- IDA MCP and allocation evidence bound the real child `ParcelPane` object to `0x124` bytes; active generated `class_ParcelPane.cpp` also emits borrowed helpers at `0x005051c0` and `0x00544c50`, but these are shared render/pane helpers, not parcel methods.
- `ParcelIconPane` construction at `0x00545e40` allocates and initializes the embedded `ParcelPane` child and writes `g_pParcelPane`.
- IDA MCP xrefs place `0x005461c0` in the `ParcelIconPane` secondary vtable at `0x00621c10`; the callback decodes parcel packet state and forwards the derived slot counts to the child `ParcelPane`.
- IDA MCP vtable dumps confirm three vtable views for each parcel notification class and show that `FlyingParcelPane` tertiary vtable `0x00621d48` ends after slot `+0x04`; generated `0x00420054` rows come from adjacent `ALERTBTN` string data, not a virtual method.
- IDA raw disassembly confirms omitted `FlyingParcelPane` cleanup/start bodies at `0x00546b80-0x00546d64`. Current IDA does not wrap these starts as functions, but 2026-06-01 bounded IDA disassembly splits them into [UID:0002R5][0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody](by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md) and [UID:0002R6][0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation](by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md), with `0xcc` padding before, between, and after.
- `FlyingParcelPane::AnimateStep` calls back into `g_pParcelPane`, updates parcel slot data, marks the pane dirty, and invalidates the notification bounds.
- Resource strings and calls use `ALERTBTN.EPF`, `ALERTBTN.PAL`, `LETTER.EPF`, and `LETTER.PAL`, matching a parcel/letter alert UI family.

## Source-Structure Decision

Use one `ParcelPane.cpp` module for `ParcelPane`, `FlyingParcelPane`, and `ParcelIconPane` unless later source evidence proves separate original files. The three classes are adjacent, share parcel globals/resources, and represent one notification feature.

Keep [UID:0000JK][FpsPane](by-file/FpsPane.md) separate. Active `class_FpsPane.cpp` now emits the `0x004b64a0` FPS logging/session body as `FpsPane::UpdateFpsLogSession`; any remaining ParcelPane references to that range are stale generated-data pollution, not parcel alert code.

## Migration Notes

- Attach or emit `0x005461c0` under `ParcelIconPane` and `0x00546440` under `ParcelPane` before migrating parcel source.
- Keep `0x00546b80-0x00546bb5` and `0x00546bc0-0x00546d64` under `FlyingParcelPane`; they are reconstructable parcel animation/lifecycle code omitted from active simroot, but final C++ should wait for source-quality helper/scheduler/field names.
- Do not pull [UID:0000MH][PatchPane](by-file/PatchPane.md) into this file; IDA confirms the patch constructor begins at `0x005470b0`.
- Preserve `FlyingParcelPane` and `ParcelIconPane` as private/helper classes if the final header does not expose them.
- Review `class_FlyingParcelPane.meta_wave3` control-character name warnings before using generated method names verbatim.

## Cross-References

- [UID:0000A6][ParcelPane](by-class/ParcelPane.md)
- [UID:000058][FlyingParcelPane](by-class/FlyingParcelPane.md)
- [UID:0000A5][ParcelIconPane](by-class/ParcelIconPane.md)
- [UID:0001EH][0x00545e40-0x005470ac.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ac.ParcelNotificationPanes.md)
- [UID:0001YE][ParcelNotificationVtableFamily](by-type/by-vtable/ParcelNotificationVtableFamily.md)
- [UID:0001VI][ParcelNotificationPaneLayouts](by-type/by-struct/ParcelNotificationPaneLayouts.md)
- [UID:0001EG][0x00545e40-0x0054606a.ParcelIconPaneConstructor](by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md)
- [UID:0001EI][0x00546070-0x005460e8.ParcelIconPaneDestructor](by-memory/0x00546070-0x005460e8.ParcelIconPaneDestructor.md)
- [UID:0001EJ][0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback](by-memory/0x005461c0-0x0054628d.ParcelIconPaneParcelUpdateCallback.md)
- [UID:0001EO][0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor](by-memory/0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor.md)
- [UID:0001EK][0x00546440-0x005464ac.ParcelPaneDestructor](by-memory/0x00546440-0x005464ac.ParcelPaneDestructor.md)
- [UID:0001EP][0x00547000-0x005470ad.ParcelPaneScalarDeletingDestructor](by-memory/0x00547000-0x005470ad.ParcelPaneScalarDeletingDestructor.md)
- [UID:0001EL][0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart](by-memory/0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart.md)
- [UID:0002R5][0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody](by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md)
- [UID:0002R6][0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation](by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md)
- [UID:0001EN][0x00546ed0-0x00546f36.FlyingParcelPaneScalarDeletingDestructor](by-memory/0x00546ed0-0x00546f36.FlyingParcelPaneScalarDeletingDestructor.md)
- [UID:0001EM][0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks](by-memory/0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks.md)
- [UID:0000RY][g_pParcelPane](by-global/g_pParcelPane.md)
- [UID:0000RX][g_pParcelIconPane](by-global/g_pParcelIconPane.md)
- [UID:0000JK][FpsPane](by-file/FpsPane.md)
- [UID:0000MH][PatchPane](by-file/PatchPane.md)

## Changes

- 2026-05-31: Filled validator projected reconstruction path as `NexusTK/ui/panels/` and split remaining IDA-confirmed parcel method pages from the aggregate memory range.
  - Before: the file page had source-placement text but no validator-managed path, and several method ranges were only listed inside the aggregate range.
  - After: validator can stage `auto-generated/NexusTK/ui/panels/ParcelPane.cpp`; the missing ParcelPane/FlyingParcelPane methods and singleton clear helpers have exact by-memory pages.
  - Evidence: `by-project-structure/proposed-source-tree.md` places this source at `ui/panels/ParcelPane.cpp`; IDA MCP function enumeration confirmed the exact boundaries from `0x00546290` through `0x00546e8b`.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `86`, confidence `80`.
- Summary/evidence: the page documents parcel notification grouping, class/global ownership, IDA/vtable evidence, omitted raw lifecycle bodies, source-structure decision, migration notes, and cross-references; confidence remains capped by final folder and whether helper classes were separate original files.

- Before: the raw `FlyingParcelPane` lifecycle/start bodies were mentioned only as one broad `0x00546b80-0x00546d64` aggregate.
- Changed to: the file page now references exact child method pages for cleanup and start/configure bodies.
- Summary/evidence: 2026-06-01 IDA MCP bounded disassembly and byte checks prove `0x00546b80-0x00546bb5`, `0x00546bb5-0x00546bc0`, `0x00546bc0-0x00546d64`, and `0x00546d64-0x00546d70` boundaries.
