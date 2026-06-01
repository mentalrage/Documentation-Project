*** UID:00000M | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AttachedObjectPane

## Status

- Confidence: strong for base overlay role and anchors.
- Likely source file: [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- Current recovered file: `source-3/simroot_v2/class_AttachedObjectPane.cpp`
- Current Wave3 grade: `96.0`
- Current Wave3 coverage: 9 modeled methods, zero missing target refs.

## Class Purpose

`AttachedObjectPane` is the shared base for object-attached overlays. It derives through [UID:00009R][ObjectPane](by-class/ObjectPane.md), records the linked object id, attaches or detaches payload objects, adjusts depth/offset data, invalidates map regions, and synchronizes overlay placement to map/viewport coordinates.

## Class Shape

- Base family: [UID:00009R][ObjectPane](by-class/ObjectPane.md)-derived overlay pane attached to map objects.
- Primary state: linked object id, attached payload pointer, registry/owner pointer at `+0x128`, and attachment offset/depth state.
- Derived users: balloon, object-info, hit-bar, and damage-number panes share this teardown and placement machinery.
- Source placement: [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md), with registry detach helper [UID:00000N][AttachedObjectPaneHelper_53AEC0](by-class/AttachedObjectPaneHelper_53AEC0.md) probably folded into the same source or a nearby owner/registry helper rather than emitted as a real class.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x005380b0-0x005380f6` | Initializes the `ObjectPane` base and stores the linked object id. |
| destructor | `0x00538100-0x005382f8` | Releases the attached payload, invalidates its map rectangle, removes it from MapPane, calls the owner/registry detach helper at `0x0053aec0`, and calls base cleanup. |
| `AttachObject` | `0x00538300-0x0053845f` | Replaces current attachment, applies attachment-table payload deltas, and refreshes regions/back pane state. |
| `DetachObject` | `0x00538460-0x005385bc` | Removes the current attachment and reverses payload/back-pane deltas. |
| `SyncViewportToMap` | `0x00538600-0x00538692` | Converts a map-cell direction/layer offset into viewport coordinates. |
| `MaybeReleaseOwner` | `0x005386a0-0x005386bd` | Owner-release callback that optionally calls the delete thunk. |
| scalar deleting destructor | `0x0053cfa0-0x0053cfdb` | Calls the non-deleting destructor and frees memory when requested. |

## Evidence Notes

- `BalloonObjectPane::BalloonObjectPane` directly calls this constructor at `0x0046830f`.
- Derived overlay destructors for balloon, object info, hit bar, and damage number use the attached-object teardown path.
- IDA decompilation of the destructor shows `sub_53AEC0(*(this + 0x128), this)` at `0x005382b0`. Treat [UID:00000N][AttachedObjectPaneHelper_53AEC0](by-class/AttachedObjectPaneHelper_53AEC0.md) as generated helper/registry code folded into this module unless later evidence recovers a broader original manager class.
- 2026-05-25 IDA MCP recheck reconfirmed `0x0053aec0` has no callers or xrefs outside this destructor.
- 2026-05-26 IDA MCP recheck reconfirmed the same sole caller and registry-pointer call shape, with no evidence for an original standalone `AttachedObjectPaneHelper_53AEC0` class.

## Cross-References

- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- [UID:0001D8][0x005380b0-0x005387a3.AttachedObjectPane](by-memory/0x005380b0-0x005387a3.AttachedObjectPane.md)
- [UID:0001DF][0x0053aec0-0x0053b011.AttachedObjectDetachRegistry](by-memory/0x0053aec0-0x0053b011.AttachedObjectDetachRegistry.md)
- [UID:00000N][AttachedObjectPaneHelper_53AEC0](by-class/AttachedObjectPaneHelper_53AEC0.md)
- [UID:0001TR][AttachedObjectRegistryLayout](by-type/by-struct/AttachedObjectRegistryLayout.md)
- [UID:00000U][BalloonObjectPane](by-class/BalloonObjectPane.md)
- [UID:00009P][ObjectInfoObjectPane](by-class/ObjectInfoObjectPane.md)
- [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md)
- [UID:00003F][DamageNumberObjectPane](by-class/DamageNumberObjectPane.md)

## Changes

- What existed before: the page had method coverage and helper evidence but remained scored as unevaluated.
- What it was changed to: scores were set to `78/88`, and class-shape notes were added for base family, primary fields, derived users, and source placement.
- Summary and evidence: destructor decompilation, IDA sole-caller evidence for the registry detach helper, and derived overlay call sites support strong confidence; completion remains below full until member layout and final source split are completely reconstructed.
