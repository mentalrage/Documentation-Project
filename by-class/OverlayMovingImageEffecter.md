*** UID:0000A0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# OverlayMovingImageEffecter

## Status

- Confidence: strong for role, Effects ownership, vtable identity, direction-mode update behavior, and frame-table lifetime.
- Likely source module: [UID:0000IZ][Effects](by-file/Effects.md)
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Responsibility

`OverlayMovingImageEffecter` is a scrolling/repeating image overlay subclass of [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md). It stores image/palette names, movement ranges, direction mode, and saved clip/scroll state, then updates scroll offsets before drawing the overlay image.

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055a990-0x0055aae3` | `UpdateAndRender` | IDA confirms the direction-mode switch that advances X/Y scroll and calls the overlay moving-image renderer. |
| `0x0055ab00-0x0055ac4a` | constructor | Builds `OverlayEffecter`, installs subclass vtables, resolves/registers the moving image, and snapshots scroll/clip state. |
| `0x0055ac50-0x0055acf7` | destructor | Releases the moving image and tears down the overlay base. |
| `0x0055bef0-0x0055bfc3` | scalar deleting destructor | Repeats moving-image release/base teardown and conditionally deletes storage. |

## IDA Evidence

Live IDA MCP recheck on 2026-06-05 confirms all four class bodies as modeled functions.

- `sub_55A990` is `0x0055a990-0x0055aae3` and is referenced from vtable slot `0x00623900`. Decompilation switches on direction mode word `this+0x16e`; cases `1` and `2` update horizontal scroll state around `this+0xb0` and `this+0x4c`, while cases `3` and `4` update vertical scroll state around `this+0xac` and `this+0x50`. All paths render through `sub_4B9980(this+0x140, this+0x150, this+0x44, *(byte *)(this+0x70), this+0x11c, 0)`.
- `sub_55AB00` is `0x0055ab00-0x0055ac4a`; it calls [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md) at `0x0055ab32`, installs the four `OverlayMovingImageEffecter` vtable views at `0x0055ab44`, `0x0055ab4a`, `0x0055ab51`, and `0x0055ab5b`, initializes scratch frame state through `sub_457A60`, loads the frame table via `sub_4D0F50(dword_67A744, source, 0)`, copies two 16-wide-character names into `this+0x100` and `this+0x120`, primes frame metadata through `sub_4D02F0`, stores motion parameters at `this+0x16c`, `this+0x16e`, `this+0x170`, and `this+0x172`, snapshots scroll/clip state at `this+0x174` and neighboring dword fields, and marks active byte `this+0xf9`.
- `sub_55AC50` is `0x0055ac50-0x0055acf7`; it releases the owned frame-table block at `this+0x140` through `sub_4D15D0`, resets the four `OverlayEffecter` vtable views, calls pane teardown helpers `sub_544CE0` and `sub_544580` on `this+0x04`, and resets the primary base to `ScreenEffecter`.
- `sub_55BEF0` is `0x0055bef0-0x0055bfc3`; it has code refs from the destructor jump strip `sub_55BA22` at `0x0055babb`, `0x0055bac6`, and `0x0055bad1`, plus the vtable data ref at `0x006238b0`. It performs the same release/base teardown and calls `sub_4F4AC0` only when scalar-delete flags allow object storage deletion.
- Live vtable data confirms RTTI at `0x00623894`, primary view `0x00623898`, pane/view `0x006238bc`, view `0x00623908`, and view `0x00623938`. Constructor, destructor, and scalar-deleting destructor each write all four subclass views: `0x0055ab44/4a/51/5b`, `0x0055ac7c/82/89/93`, and `0x0055bf1c/22/29/33`.
- Direct xrefs to the constructor and non-scalar destructor starts are absent in the current IDA database, so final creator/caller inventory remains open.

## Autogen Status

Attach this class to [UID:0000IZ][Effects](by-file/Effects.md) as reconstructable runtime-effecter metadata. C++ remains blank because field names, constructor call sites, and final method names are still below the 95/95 reconstruction bar.

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Changes

- 2026-06-05:
  - Before: scored `72/82`, reconstructability and parent metadata were blank, and the page only had high-level method-range notes.
  - After: scored `84/88`, marked reconstructable, attached to [UID:0000IZ][Effects](by-file/Effects.md), and kept reconstruction C++ blank.
  - Why: live IDA evidence now confirms exact modeled function ranges, constructor base call and four-view vtable stores, frame-table load/free helpers, two copied 16-wide-character names, direction-mode switch behavior, render flow through `sub_4B9980`, scalar-delete jump-strip refs, exact vtable slot targets, and the remaining lack of direct constructor/non-scalar-destructor callers. Completion remains below final-source quality because field names, creator inventory, and final method names are incomplete.
- Before: completion/confidence metadata were `0/0` while the page already documented role, method ranges, ownership, and overlay-base relationships.
- Changed to: `COMPLETION:72` and `CONFIDENCE:82`.
- Evidence: update/render direction-mode behavior, constructor, destructor, scalar deleting destructor, source-family, and vtable family are documented; completion remains below high because exact fields, callers, and reconstructed C++ are not yet exhaustive.
