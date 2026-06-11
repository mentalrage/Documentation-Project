*** UID:00009Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# OverlayImageEffecter

## Status

- Confidence: strong for role, ownership, vtable identity, constructor behavior, and static overlay render path.
- Proposed source: `render/Effects.cpp`
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Responsibility

`OverlayImageEffecter` is the static image/name overlay subclass of [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md). It resolves overlay metadata by image name, stores the lookup name pair, and applies the overlay to the current viewport bounds.

Some helper labels mention fitting-room/download panes because the shared overlay helper is also used there. Treat those labels as helper provenance, not proof that this runtime effect class belongs in fitting-room source.

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055a440-0x0055a499` | `ApplyOverlayImage` | IDA confirms it fetches viewport bounds through `0x004b8e00` and calls the overlay-by-name renderer. |
| `0x0055a4a0-0x0055a55e` | constructor | Builds `OverlayEffecter`, installs subclass vtables, initializes overlay metadata, copies both 16-wchar names, and loads catalog metadata. |
| `0x0055bd70-0x0055be0d` | scalar deleting destructor | Resets to `OverlayEffecter`/`ScreenEffecter` bases and conditionally deletes storage. |

## IDA Evidence

Live IDA MCP recheck on 2026-06-04 used `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.

- `0x0055a440` decompiles to a compact render body: it obtains viewport bounds from `dword_67A764` through [UID:000161][0x004b8e00-0x004b8e11.BackPaneGetBounds](by-memory/0x004b8e00-0x004b8e11.BackPaneGetBounds.md), then calls `0x004b9980` with name/state fields at `this+0x140`, `this+0x150`, and `this+0x11c`.
- `0x0055a4a0` calls the shared [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md) base constructor at `0x0055a2e0`, installs four `OverlayImageEffecter` vtable views at `0x00623694`, `0x006236b8`, `0x00623704`, and `0x00623734`, initializes scratch metadata through `0x00457a60`, copies two 16-wchar names into `this+0x100` and `this+0x120`, and calls `0x004d02f0` with [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) / `dword_67A744`.
- `0x0055bd70` is reached from the destructor jump strip at `0x0055ba7f`, `0x0055ba8a`, and `0x0055ba95`; it resets the four overlay-base vtable views, tears down the embedded pane through `0x00544ce0` and `0x00544580`, resets the `ScreenEffecter` base vtable, and optionally frees the object when the scalar-delete flag permits.

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- [UID:0000HO][BackPane](by-file/BackPane.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)

## Changes

- 2026-06-07 A005 resolved-name cleanup:
  - Before: constructor resource evidence used only historical `dword_67A744`.
  - After: the page records canonical `g_pEPFLib` beside the historical label and cross-links the global page.
  - Evidence: generated resolved-name report maps `dword_67A744` to `g_pEPFLib`; existing IDA-backed evidence already ties the reference to EPF resource metadata lookup.
- 2026-06-04: Raised completion/confidence from `72/78` to `84/88`, marked reconstructable, and attached to [UID:0000IZ][Effects](by-file/Effects.md). Summary/evidence: live IDA MCP verified exclusive function endpoints, constructor base call and four-view vtable stores, two copied resource names, metadata lookup through `0x004d02f0`, viewport-bound render flow through `0x004b8e00`/`0x004b9980`, and scalar-destructor teardown. Completion remains below final-source quality because final field names and all creator/caller contexts still need reconstruction.
- Before: completion/confidence metadata were `0/0` despite role, method, helper-label caveat, and overlay-family documentation.
- Changed to: `COMPLETION:72` and `CONFIDENCE:78`.
- Evidence: apply/constructor/destructor methods, static image overlay responsibility, base/subclass relationships, and helper-label pollution are documented; confidence stays medium-high because helper names and detailed field/source split still need verification.
