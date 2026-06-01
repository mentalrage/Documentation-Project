*** UID:0000QS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pDirectX

## Status

- Symbol kind: process-wide singleton pointer / global data.
- IDA address: `0x0067ab20` (`dword_67AB20`).
- Proposed type: `DirectX*`.
- Proposed owner module: [UID:0000IW][DirectX](by-file/DirectX.md).
- Current recovered declaration: `DirectX* g_pDirectX` in `source-3/simroot_v2/class_DirectX.cpp`.
- Confidence: strong for storage, type, and owner module.

## Role

`g_pDirectX` exposes the client DirectDraw bootstrap object after application startup constructs [UID:00003Y][DirectX](by-class/DirectX.md). Render and presentation code load this pointer when they need the stored DirectDraw interface, especially while creating or managing DirectDraw surfaces.

This is not a font or text-layout singleton. Some generated UI text call sites currently name `g_pDirectX`, but IDA shows those specific sites load adjacent [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md) at `0x0067ab24`. Keep that alias issue separate from this global.

## Lifetime Evidence

- `DirectX::DirectX` writes `dword_67AB20` at `0x004a1ba2` and `0x004a1ba9`.
- `DirectX::~DirectX` clears it at `0x004a1c9d`.
- The constructor-unwind helper at `0x004a1cc0` is an 11-byte function that only writes `dword_67AB20 = 0` and returns.
- `DirectX::ScalarDeletingDestructor` clears it at `0x004a1d14`.
- IDA xrefs include later consumers in render/surface code such as `0x004b8d78`, `0x004b92bc`, `0x004b9800`, `0x004bb83f`, `0x00556b22`, `0x00556b77`, `0x005574a0`, `0x005576d0`, `0x005583d0`, `0x00558875`, and `0x00558b24`.

## Ownership Decision

Keep this global with `render/DirectX.cpp`. It is installed and cleared by `DirectX` lifetime code and then consumed by other render modules. `GrafPort`, `Surface`, screenshot presentation, and UI panes should reference it as a dependency, not own the declaration.

## Cross-References

- [UID:0000IW][DirectX](by-file/DirectX.md)
- [UID:00003Y][DirectX](by-class/DirectX.md)
- [UID:000137][0x004a1b60-0x004a1d6a.DirectX](by-memory/0x004a1b60-0x004a1d6a.DirectX.md)
- [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md)
- [UID:0001XE][DIBitmapDirectXVtables](by-type/by-vtable/DIBitmapDirectXVtables.md)
- [UID:0000JR][GrafPort](by-file/GrafPort.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/86`. Summary/evidence: the page documents address, proposed type/owner, generated declaration, DirectDraw role, lifetime writes/clears, render/surface consumers, alias warning, and file/class/memory refs.
