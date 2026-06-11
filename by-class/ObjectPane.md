*** UID:00009R | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000M5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ObjectPane

## Status

- Confidence: strong for base-class role and method anchors.
- Source file: [UID:0000M5][ObjectPane](by-file/ObjectPane.md)
- Evidence basis: live IDA MCP confirms the core method boundaries, constructor/destructor subclass reachability, scattered rect-helper vtable slots, and object-data/position virtual slots.
- Rebuild handling: source-authored class; C++ block remains blank because final layout, virtual slot names, and source declaration/body shape are not final-audit quality.

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

- Live IDA confirms all listed method starts and ranges, including the two scattered rect-helper virtuals at `0x00469050` and `0x00469080`.
- The constructor has subclass construction callers across the static, item/flying, attached, effect, living, lighting, and sound object-pane families; the destructor is reached from the corresponding wrapper/destructor paths.
- `SetObjectData` at `0x00537800-0x0053787a` is a real executable virtual-slot body: it invalidates before and after updating the 16-byte object-data block and conditionally recomputes attached-state geometry.
- `GetObjectData` and `SetPosition` are vtable-referenced across the ObjectPane family; `SetPosition` updates the stored map coordinates only when they change.

## Cross-References

- [UID:0000M5][ObjectPane](by-file/ObjectPane.md)
- [UID:0001D5][0x005372d0-0x005378fa.ObjectPane](by-memory/0x005372d0-0x005378fa.ObjectPane.md)
- [UID:00020R][0x00469050-0x0046907a.ObjectPaneClearOutputRects](by-memory/0x00469050-0x0046907a.ObjectPaneClearOutputRects.md)
- [UID:00020S][0x00469080-0x004690a5.ObjectPaneGetEmptyRect](by-memory/0x00469080-0x004690a5.ObjectPaneGetEmptyRect.md)
- [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)

## Changes

- 2026-06-06 A002 autogen parent sync:
  - What existed before: the class page identified [UID:0000M5][ObjectPane](by-file/ObjectPane.md) as the likely source file, but `AUTOGEN_PARENT_UID` was blank, leaving child memory pages attached to an unassigned parent in generated coverage.
  - What changed: set `AUTOGEN_PARENT_UID:0000M5` and promoted the status wording from likely source file to source file.
  - Summary/evidence: the file page already has `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`, this class is `84/86`, the file page is `88/86`, and all three ObjectPane memory children are above the 80/80 attachment gate; final C++ remains blank under the 95/95 gate.

- 2026-06-05 live IDA refresh:
  - What existed before: the page mixed source-facing ObjectPane notes with stale recovery-output status and a lower confidence cap.
  - What changed: raised completion/confidence to `84/86`, removed stale recovery-output references, and added live IDA evidence for method boundaries, subclass caller families, and the object-data/position virtual slots.
  - Summary/evidence: live IDA confirms the ObjectPane core range, scattered rect helpers, constructor/destructor reachability, and vtable/data references for the object-data and position methods.

- Before: completion/confidence metadata were `0/0` even though the page already covered base-class purpose, object state, and method anchors.
- Changed to: `COMPLETION:82` and `CONFIDENCE:80`.
- Evidence: the page documents constructor/destructor, attach/detach, bounds, object-data, position, helper virtuals, and derived-class relationships; confidence remains below final because several field and slot names are still provisional.
- 2026-06-02 reconstructable marker update:
  - What existed before: the class page described a reconstructable ObjectPane base class but left `RECONSTRUCTABLE` blank.
  - What it was changed to: marked `RECONSTRUCTABLE:TRUE` while keeping the C++ block blank.
  - Summary/evidence: ObjectPane owns confirmed constructor/destructor, attach/detach, bounds, object-data, position, and virtual rect helper methods; final class declaration/body shape still waits on layout and virtual-slot naming.
