*** UID:00009R | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ObjectPane

## Status

- Confidence: strong for base-class role and method anchors.
- Likely source file: [UID:0000M5][ObjectPane](by-file/ObjectPane.md)
- Current recovered file: `source-3/simroot_v2/class_ObjectPane.cpp`
- Current Wave3 grade: `96.4`
- Current Wave3 coverage: 12 modeled methods, zero missing target refs.
- Rebuild handling: source-authored class; C++ block remains blank because final layout, virtual slot names, and emitted source are not final-audit quality.

## Class Purpose

`ObjectPane` is the base class for renderable game-world objects. It layers object-specific state on top of `Pane`: object type, sprite/frame/palette ids, attached object imagery, current bounds, packed object data, and map position.

Classes such as [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md), item object panes, and object-info/overlay panes build on this base. `ObjectPane` should be treated as map-object infrastructure rather than generic UI control code.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ClearBounds` | `0x00469050-0x0046907a` | Virtual helper that clears two output rectangles. |
| `GetEmptyRect` | `0x00469080-0x004690a5` | Virtual helper that returns an empty rectangle. |
| constructor | `0x005372d0-0x00537395` | Constructs `Pane`, installs `ObjectPane` vtables, initializes object type/sprite/frame/palette and empty bounds. |
| destructor | `0x005373a0-0x005374cb` | Resets vtables, releases attached light/object image entry, detaches object, and calls `Pane` cleanup. |
| `AttachObject` | `0x005374f0-0x005375e1` | Replaces current attached object, updates payload/height, dispatches map payload when active, and refreshes bounds. |
| `DetachObject` | `0x005375f0-0x005376b5` | Removes attached object payload and clears attachment pointer. |
| `ReleaseFromContainer` | `0x00537720-0x00537739` | Asks the parcel/map pane to release this object's state from its container. |
| `SetBounds` | `0x00537740-0x00537751` | Stores current bounds. |
| `UpdateBounds` | `0x00537760-0x005377f2` | Repositions the pane and updates clip/dirty bounds when object bounds change. |
| `SetObjectData` | `0x00537800-0x0053787a` | Copies a 16-byte object data record and invalidates/recomputes attached state when the linked object changes. |
| `GetObjectData` | `0x00537880-0x00537894` | Copies the packed 16-byte object data record out. |
| `SetPosition` | `0x005378a0-0x005378fa` | Moves the object through `MapPane::UpdateObjectPosition` and refreshes bounds before/after the coordinate update. |

## Evidence Notes

- Wave3 reports grade `96.4`, 12 methods, and zero missing target refs.
- IDA confirms all listed method starts and ranges.
- `SetObjectData` is valid in IDA, but Wave3's emitted `class_ObjectPane.cpp` currently omits its executable body and emits only local struct scaffolding. Treat the IDA decompilation as the current behavioral source of truth for that method until Wave3 materialization is fixed.

## Cross-References

- [UID:0000M5][ObjectPane](by-file/ObjectPane.md)
- [UID:0001D5][0x005372d0-0x005378fa.ObjectPane](by-memory/0x005372d0-0x005378fa.ObjectPane.md)
- [UID:00020R][0x00469050-0x0046907a.ObjectPaneClearOutputRects](by-memory/0x00469050-0x0046907a.ObjectPaneClearOutputRects.md)
- [UID:00020S][0x00469080-0x004690a5.ObjectPaneGetEmptyRect](by-memory/0x00469080-0x004690a5.ObjectPaneGetEmptyRect.md)
- [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)

## Changes

- Before: completion/confidence metadata were `0/0` even though the page already covered base-class purpose, object state, method anchors, and a Wave3 materialization caveat.
- Changed to: `COMPLETION:82` and `CONFIDENCE:80`.
- Evidence: the page documents constructor/destructor, attach/detach, bounds, object-data, position, helper virtuals, derived-class relationships, and the `SetObjectData` emitted-source omission; confidence remains medium-high because one important method still depends on IDA decompilation rather than current generated output.
- 2026-06-02 reconstructable marker update:
  - What existed before: the class page described a reconstructable ObjectPane base class but left `RECONSTRUCTABLE` blank.
  - What it was changed to: marked `RECONSTRUCTABLE:TRUE` while keeping the C++ block blank.
  - Summary/evidence: ObjectPane owns confirmed constructor/destructor, attach/detach, bounds, object-data, position, and virtual rect helper methods; final emitted class source still waits on layout and virtual-slot naming.
