*** UID:00009X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# OverlayFrameImageEffecter

## Status

- Confidence: strong for role, Effects ownership, vtable identity, frame-table lifetime, and render helper flow.
- Likely source module: [UID:0000IZ][Effects](by-file/Effects.md)
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Responsibility

`OverlayFrameImageEffecter` is the frame-indexed overlay subclass of [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md). It resolves a frame image by index, tracks palette/image names, and renders the selected frame through the shared overlay-frame renderer.

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055a5e0-0x0055a61b` | `UpdateFrameAndRender` | IDA confirms a small virtual body that resolves a frame by index and renders it against the pane clip rect. |
| `0x0055a620-0x0055a6ea` | constructor | Builds `OverlayEffecter`, installs subclass vtables, initializes frame-table and scratch state, copies resource names, and marks the pane visible. |
| `0x0055a6f0-0x0055a797` | destructor | Releases the frame-table handle and tears down the overlay base. |
| `0x0055bc90-0x0055bd63` | scalar deleting destructor | Repeats frame-table release/base teardown and conditionally deletes storage. |

## IDA Evidence

Live IDA MCP recheck on 2026-06-05 confirms all four class bodies as modeled functions rather than raw constructor guesses.

- `sub_55A5E0` is `0x0055a5e0-0x0055a61b` and is referenced from vtable slot `0x006237a8`. Its disassembly loads frame metadata through `sub_4D02F0(dword_67A744, this+0xfc, *(word *)(this+0x168), this+0x140)`, then renders through `sub_4BA6B0(this, this+0x44, this+0x140, this+0x11c)`.
- `sub_55A620` is `0x0055a620-0x0055a6ea`; it calls [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md) at `0x0055a651`, installs the four `OverlayFrameImageEffecter` vtable views at `0x0055a663`, `0x0055a669`, `0x0055a670`, and `0x0055a67a`, initializes scratch frame state through `sub_457A60`, loads the frame table via `sub_4D0F50(dword_67A744, source, 0)`, copies two 16-wide-character names into `this+0x100` and `this+0x120`, stores a word parameter at `this+0x16c`, and sets visible/active byte `this+0xf9`.
- `sub_55A6F0` is `0x0055a6f0-0x0055a797`; it releases the owned frame-table block at `this+0x140` through `sub_4D15D0`, resets the four `OverlayEffecter` vtable views, calls pane teardown helpers `sub_544CE0` and `sub_544580` on `this+0x04`, and resets the primary base to `ScreenEffecter`.
- `sub_55BC90` is `0x0055bc90-0x0055bd63`; it has code refs from the destructor jump strip `sub_55BA22` at `0x0055ba61`, `0x0055ba6c`, and `0x0055ba77`, plus the vtable data ref at `0x00623758`. It performs the same release/base teardown and calls `sub_4F4AC0` only when scalar-delete flags allow object storage deletion.
- Live vtable data confirms RTTI at `0x0062373c`, primary view `0x00623740`, pane/view `0x00623764`, view `0x006237b0`, and view `0x006237e0`. Constructor, destructor, and scalar-deleting destructor each write all four subclass views: `0x0055a663/69/70/7a`, `0x0055a71c/22/29/33`, and `0x0055bcbc/c2/c9/d3`.
- The update/render virtual slot is `0x006237a8 -> sub_55A5E0`; the scalar-deleting destructor slot is `0x00623758 -> sub_55BC90`. Direct xrefs to the constructor and non-scalar destructor starts are absent in the current IDA database, so final creator/caller inventory remains open.

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
  - Why: live IDA evidence now confirms exact modeled function ranges, constructor base call and four-view vtable stores, frame-table load/free helpers, two copied 16-wide-character names, update/render flow through `sub_4D02F0` and `sub_4BA6B0`, scalar-delete jump-strip refs, exact vtable slot targets, and the remaining lack of direct constructor/non-scalar-destructor callers. Completion remains below final-source quality because field names, creator inventory, and final method names are incomplete.
- Before: completion/confidence metadata were `0/0` while the page already contained role, owner, method ranges, and overlay-base relationships.
- Changed to: `COMPLETION:72` and `CONFIDENCE:82`.
- Evidence: frame update/render, constructor, destructor, scalar deleting destructor, source-family, vtable family, and base class relationships are documented; completion remains below high because field names, callers, and reconstructed C++ are not fully covered.
