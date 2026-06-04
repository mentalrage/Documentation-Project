*** UID:00009Z | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# OverlayImageOnPointEffecter

## Status

- Confidence: strong for role, ownership, vtable identity, point-overlay fields, resource lifetime, and render helper flow.
- Proposed source: `render/Effects.cpp`
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Responsibility

`OverlayImageOnPointEffecter` is an [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md) subclass that draws an overlay image at a fixed pane point. It stores primary/secondary resource names, an overlay resource id, a render handle, and point coordinates.

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055a7a0-0x0055a7c6` | `RenderOverlayImageAtPoint` | IDA confirms a compact virtual renderer that passes resource id, scratch state, point, flags, and text to the draw helper. |
| `0x0055a7d0-0x0055a8da` | constructor | Builds `OverlayEffecter`, initializes render handle/resource id, copies names, loads the overlay resource, and stores point/lifetime state. |
| `0x0055a8e0-0x0055a987` | destructor | Releases the overlay resource and tears down visual/pane state. |
| `0x0055be10-0x0055bee3` | scalar deleting destructor | Calls the destructor and conditionally deletes storage. |

## IDA Evidence

Live IDA MCP recheck on 2026-06-04 used `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.

- `0x0055a7a0` decompiles to a direct `0x004b9980` call using fields at `this+0x140`, `this+0x150`, `this+0x44`, byte flag `this+0x70`, and label/name field `this+0x11c`.
- `0x0055a7d0` calls the shared [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md) base constructor at `0x0055a2e0`, installs four `OverlayImageOnPointEffecter` vtable views at `0x006237ec`, `0x00623810`, `0x0062385c`, and `0x0062388c`, initializes scratch metadata through `0x00457a60`, loads a resource handle through `0x004d0f50`, copies two 16-wchar names, calls `0x004d02f0` with `dword_67A744`, stores point coordinates into both word and dword fields, and seeds two 300-tick/state fields.
- `0x0055a8e0` and `0x0055be10` both release the stored resource handle through `0x004d15d0`, reset to the four overlay-base vtable views, tear down the embedded pane through `0x00544ce0` and `0x00544580`, and reset the `ScreenEffecter` base vtable. The scalar deleting destructor is reached from the destructor jump strip at `0x0055ba9d`, `0x0055baa8`, and `0x0055bab3`.

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Changes

- 2026-06-04: Raised completion/confidence from `72/78` to `84/90`, marked reconstructable, and attached to [UID:0000IZ][Effects](by-file/Effects.md). Summary/evidence: live IDA MCP verified exclusive function endpoints, constructor base call and four-view vtable stores, resource load/free helpers, two copied names, point-coordinate storage, render helper arguments, and destructor/scalar-destructor ownership. Completion remains below final-source quality because final public method/field names and all creator/caller contexts still need reconstruction.
- Before: completion/confidence metadata were `0/0` even though the page already documented responsibility, method boundaries, owner, and provisional field-layout caveats.
- Changed to: `COMPLETION:72` and `CONFIDENCE:78`.
- Evidence: fixed-point overlay rendering, constructor, destructor, scalar deleting destructor, base relationship, and vtable family are documented; confidence remains medium-high because final field names and reconstructed C++ are incomplete.
