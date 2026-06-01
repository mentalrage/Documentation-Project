*** UID:0000HJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# AttachedObjectPane

## Status

- Confidence: strong for `AttachedObjectPane` as the shared overlay base; medium-high for grouping the derived overlay classes in the same original source area.
- Proposed module: `map/AttachedObjectPane.cpp`
- Current generated sources: `class_AttachedObjectPane.cpp`, `class_AttachedObjectPaneHelper_53AEC0.cpp`, `class_AttachmentAnchorResolver.cpp`, `class_BalloonObjectPane.cpp`, `class_ObjectInfoObjectPane.cpp`, `class_DamageNumberObjectPane.cpp`, `class_HitBarObjectPane.cpp`
- Main address docs: [UID:0001D8][0x005380b0-0x005387a3.AttachedObjectPane](by-memory/0x005380b0-0x005387a3.AttachedObjectPane.md), [UID:0001DF][0x0053aec0-0x0053b011.AttachedObjectDetachRegistry](by-memory/0x0053aec0-0x0053b011.AttachedObjectDetachRegistry.md), [UID:0001DH][0x0053c700-0x0053c92e.AttachmentAnchorResolver](by-memory/0x0053c700-0x0053c92e.AttachmentAnchorResolver.md), [UID:0000YZ][0x00467b30-0x0046904e.BalloonObjectPane](by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md), [UID:0001DB][0x00538bc0-0x00539bb2.ObjectOverlayPanes](by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md), and [UID:0001DL][0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors](by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md)

## File Role

`AttachedObjectPane.cpp` likely owns temporary or dependent map-object overlays anchored to another object. It includes the shared attach/detach base plus speech balloons, name/object-info labels, hit bars, and floating damage numbers.

The grouping is stronger than a one-class split because these classes share `ObjectPane`/`AttachedObjectPane` construction, derive through attached-object teardown, are constructed from [UID:0000L3][MapPane](by-file/MapPane.md) packet/action handlers, and share helper behavior such as attached screen-position lookup.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `AttachedObjectPane` | `0x005380b0-0x005386bd`, destructor at `0x0053cfa0` | Base attached overlay object with attach/detach payload lifecycle and viewport synchronization. |
| `AttachedObjectPaneHelper_53AEC0` / detach registry helper | `0x0053aec0-0x0053b011`, only caller at `0x005382b0` | Private owner/registry cleanup helper for destroyed attached overlays; not a final standalone file candidate yet. |
| `AttachmentAnchorResolver` | `0x0053c700-0x0053c92e` | Shared anchor point/bounds helper for attached overlay placement; may be a private helper class in this source. |
| `BalloonObjectPane` | `0x00467b30-0x0046904e`, constructor callers from MapPane speech packet handlers | Speech balloon drawing, text wrapping, off-screen bubble surface refresh, and owner-relative placement. |
| `ObjectInfoObjectPane` | `0x005395b0-0x00539bb2`, destructor at `0x0053d620` | Floating name/object tooltip anchored to a map object. |
| `HitBarObjectPane` | `0x00538d50-0x0053922b`, destructor at `0x0053d240` | Health/hit bar overlay with single and dual bar rendering. |
| `DamageNumberObjectPane` | `0x00539230-0x005395a7`, destructor at `0x0053d060` | Floating damage/healing number overlay using `DMGNUM.EPF`. |

## Method Families

| Area | Representative anchors | Notes |
| --- | --- | --- |
| Attached lifecycle | `0x005380b0`, `0x00538100`, `0x00538300`, `0x00538460` | Owns attachment replacement, release, payload depth changes, and map invalidation. |
| Registry cleanup | `0x0053aec0` | Removes destroyed attached overlays from type-specific registry lists/slots through the owner pointer stored at `AttachedObjectPane + 0x128`. |
| Attached positioning | `0x00538600`, `0x005386c0`, `0x0053c700`, `0x0053c810` | Converts attached object/map offsets into viewport/screen points and rectangles. |
| Speech balloon surface | `0x00467b30`, `0x00468250`, `0x004682c0`, `0x00468b90` | Draws the balloon frame/text, refreshes the cached GrafPort, constructs/wraps text, and computes layout. |
| Combat overlays | `0x00538d50`, `0x00539030`, `0x00539230`, `0x005394d0` | Builds hit bars and damage number overlays from combat packet/action paths. |
| Object labels | `0x005395b0`, `0x00539760`, `0x005398e0`, `0x00539b20` | Builds and draws floating object labels using object sprite anchor information and config display options. |

## Boundary Notes

- `BalloonObjectPane::RefreshBubbleSurface` is modeled by Wave3/Ghidra at `0x00468250-0x004682bb`, but IDA currently has no function record at `0x00468250`. Treat the Wave3 range as recovered code with an IDA-boundary caveat until IDA is repaired or Wave3 marks the difference.
- `class_AttachedObjectPaneHelper_53AEC0.cpp` is a generated one-method split imported from Wave2 recovered output. IDA shows `0x0053aec0` is only called by `AttachedObjectPane::~AttachedObjectPane`, so fold it here unless later constructor/setup evidence identifies a real named owner class.
- The helper's generated `g_attachmentModeFlag` alias is [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97`, the broad new/legacy UI asset selector. Do not treat it as attachment-specific.
- [UID:0000HL][AttachmentAnchorResolver](by-file/AttachmentAnchorResolver.md) may ultimately fold into this original source file rather than stay as a separate `.cpp`; current docs keep it separate because `simroot_v2` imports a named `AttachmentAnchorResolver.cpp` and the helper has a clear class-like layout.
- Several constructor callers in the MapPane packet cluster are IDA-confirmed but currently unknown to Wave3, including `0x0050e100`, `0x0050e690`, and `0x0050ef00`.
- [UID:0000HU][BowGaugeObjectPane](by-file/BowGaugeObjectPane.md) is excluded from this file despite the name. It derives from `Pane`, is constructed by [UID:0000P1][UserPane](by-file/UserPane.md), and behaves like a local-player HUD gauge rather than a map-object attachment.

## IDA MCP Evidence

Targeted checks on 2026-05-23 confirmed exact starts/ranges for all listed `AttachedObjectPane`, `BalloonObjectPane`, `ObjectInfoObjectPane`, `HitBarObjectPane`, and `DamageNumberObjectPane` anchors except `0x00468250`, where Wave3/Ghidra recovered a function but IDA has no function record.

Constructor xrefs observed:

- `ItemObjectPane` and overlay constructors are mainly reached from [UID:0000L3][MapPane](by-file/MapPane.md) object, speech, hit/damage, and object-label packet handlers.
- `BalloonObjectPane` constructor at `0x004682c0` calls `AttachedObjectPane::AttachedObjectPane` at `0x005380b0`.
- `AttachedObjectPane::~AttachedObjectPane` at `0x00538100` calls `sub_53AEC0` at `0x005382b0`; IDA reports no other callers for `0x0053aec0`.
- 2026-05-25 IDA MCP recheck found the current `simroot_v2` output still emits `class_AttachedObjectPaneHelper_53AEC0.cpp` as a standalone one-method split, but IDA caller/xref evidence is unchanged.
- 2026-05-26 IDA MCP recheck reconfirmed `sub_53AEC0` size `0x152`, the sole `0x005382b0` destructor call, and the `AttachedObjectPane + 0x128` registry-pointer call shape. Keep the helper folded here unless later setup evidence recovers a real manager class.
- 2026-05-26 IDA static-pool review identifies [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md) for `BalloonObjectPane` at `0x0069b9fc`, `DamageNumberObjectPane` at `0x0069b95c`, and `HitBarObjectPane` at `0x0069b934`.

## Cross-References

- [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md)
- [UID:0000HK][AttachedObjectPaneHelper_53AEC0](by-file/AttachedObjectPaneHelper_53AEC0.md)
- [UID:00000O][AttachmentAnchorResolver](by-class/AttachmentAnchorResolver.md)
- [UID:00000U][BalloonObjectPane](by-class/BalloonObjectPane.md)
- [UID:00009P][ObjectInfoObjectPane](by-class/ObjectInfoObjectPane.md)
- [UID:000067][HitBarObjectPane](by-class/HitBarObjectPane.md)
- [UID:00003F][DamageNumberObjectPane](by-class/DamageNumberObjectPane.md)
- [UID:0000M5][ObjectPane](by-file/ObjectPane.md)
- [UID:0000HL][AttachmentAnchorResolver](by-file/AttachmentAnchorResolver.md)
- [UID:0001TR][AttachedObjectRegistryLayout](by-type/by-struct/AttachedObjectRegistryLayout.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md)

## Changes

- What existed before: the page had a strong attached-overlay source hypothesis and detailed boundary notes but remained scored as unevaluated.
- What it was changed to: scores were set to `78/84`.
- Summary and evidence: class grouping, MapPane construction paths, shared teardown, registry helper, and static-pool evidence support the module; completion/confidence are limited by one IDA boundary caveat and final folding of anchor/helper pages.
