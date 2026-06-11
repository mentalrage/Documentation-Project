*** UID:00003Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DirectX

## Status

- Confidence: strong.
- Likely source file: [UID:0000IW][DirectX](by-file/DirectX.md)
- Address range: [UID:000137][0x004a1b60-0x004a1d6a.DirectX](by-memory/0x004a1b60-0x004a1d6a.DirectX.md)
- Current recovered file: `source-3/simroot_v2/class_DirectX.cpp`
- Primary vtable: [UID:0002MD][0x00618e60-0x00618e70.DirectXVtableData](by-memory/0x00618e60-0x00618e70.DirectXVtableData.md), summarized by [UID:0001XE][DIBitmapDirectXVtables](by-type/by-vtable/DIBitmapDirectXVtables.md)
- Direct autogen parent: [UID:0000IW][DirectX](by-file/DirectX.md)

## Class Purpose

`DirectX` is the client DirectDraw bootstrap object. It creates a DirectDraw object, queries the interface used by the rest of the renderer, stores that interface in the object, and exposes the object through `g_pDirectX`.

This is not the renderer core. It is a lifetime/COM wrapper used by surface-management code such as `GrafPort`.

## Observed State

```text
0x00  LObject base / vtable slot
0x04  IDirectDraw* m_directDraw
```

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `DirectX::DirectX` | `0x004a1b60-0x004a1c56` | Sets `g_pDirectX`, calls `DirectDrawCreate`, queries the persistent DirectDraw interface, and throws `MyError` on failure. |
| `DirectX::~DirectX` | `0x004a1c60-0x004a1cbc` | Releases the stored DirectDraw interface, clears `g_pDirectX`, and destroys `LObject`. |
| Constructor-unwind singleton clear helper | `0x004a1cc0-0x004a1ccb` | Clears `g_pDirectX`; referenced from the constructor's EH/unwind cleanup metadata. |
| `ScalarDeletingDestructor` | `0x004a1cd0-0x004a1d6a` | Runs the destructor and conditionally deletes the object. |

## Supporting Exact Evidence

- [UID:000137][0x004a1b60-0x004a1d6a.DirectX](by-memory/0x004a1b60-0x004a1d6a.DirectX.md) records exact function boundaries, alignment gaps, constructor/destructor/scalar-deleting-destructor behavior, DirectDraw call sequence, COM release, startup caller, `g_pDirectX` xrefs, and compiler EH helper caveats.
- [UID:0002MD][0x00618e60-0x00618e70.DirectXVtableData](by-memory/0x00618e60-0x00618e70.DirectXVtableData.md) records the exact DirectX RTTI/vtable range and boundary before adjacent diagnostic string data.
- [UID:0000IW][DirectX](by-file/DirectX.md) records the file-root boundary: DirectDraw object/interface lifetime belongs here, while `GrafPort`, `Surface`, and font-image behavior remain separate consumers/owners.

## Evidence Notes

- Wave3 imports all three methods with high manual/automated grades.
- IDA MCP reports the constructor is called from application startup around `0x004645aa`.
- IDA MCP confirms the constructor calls `DirectDrawCreate` and the destructor dispatches a COM-style release.
- `GrafPort::UpdateRenderRegion` uses `g_pDirectX` while creating DirectDraw surfaces.
- IDA MCP confirms a primary vtable at `0x00618e64` and a tiny `0x004a1cc0` helper that clears [UID:0000QS][g_pDirectX](by-global/g_pDirectX.md). Current Wave3 metadata still reports `vtable_count: 0` and active source omits the helper.
- 2026-05-31 IDA MCP confirms the exact vtable data span at `0x00618e60-0x00618e70`: RTTI pointer `??_R4DirectX@@6B@` at `0x00618e60`, vtable symbol `??_7DirectX@@6B@` at `0x00618e64`, three virtual slots, and DirectX diagnostic string data beginning at `0x00618e70`.

## Open Issues

- Some generated UI text call sites currently list `g_pDirectX` as the receiver for font measurement. IDA shows those specific call sites load [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md) at `0x0067ab24`, not `g_pDirectX` at `0x0067ab20`; treat them as font-singleton aliasing until Wave3 data is repaired.

## Assignment Gate

`AUTOGEN_PARENT_UID` is set to [UID:0000IW][DirectX](by-file/DirectX.md). This class is scored `85/88`, and the direct file parent is scored `85/88`, so both sides clear the corrected 85/85 gate. The relationship is direct because the file page owns the compact DirectDraw bootstrap source root, while this class page owns the object layout and method inventory for that wrapper.

## Score Rationale

- Completion is `85` because the page records the class purpose, compact layout, constructor/destructor/unwind/deleting-destructor methods, singleton ownership, exact memory/vtable support pages, startup/consumer evidence, alias caveat, and parent-gate reasoning.
- Confidence remains `88` because the DirectDraw wrapper role, singleton lifetime, vtable child, and file-root placement are well supported. It remains below final confidence because exact final C++ spelling for COM failure handling and the unresolved interface GUID symbol need final reconstruction work.

## Cross-References

- [UID:0000IW][DirectX](by-file/DirectX.md)
- [UID:000137][0x004a1b60-0x004a1d6a.DirectX](by-memory/0x004a1b60-0x004a1d6a.DirectX.md)
- [UID:0000QS][g_pDirectX](by-global/g_pDirectX.md)
- [UID:0000QX][g_pFontImageLib](by-global/g_pFontImageLib.md)
- [UID:0001XE][DIBitmapDirectXVtables](by-type/by-vtable/DIBitmapDirectXVtables.md)
- [UID:0002MD][0x00618e60-0x00618e70.DirectXVtableData](by-memory/0x00618e60-0x00618e70.DirectXVtableData.md)
- [UID:00005V][GrafPort](by-class/GrafPort.md)
- [Wave3 noticed problems](../wave3_noticed_problems.md)

## Changes

- 2026-06-07 A003 Batch 084 class parent-gate update:
  - Changed to: `COMPLETION:85`, `AUTOGEN_PARENT_UID:0000IW`; confidence remains `88`.
  - Summary/evidence: added supporting exact evidence, assignment gate, and score rationale. Assignment to [UID:0000IW][DirectX](by-file/DirectX.md) is justified because the child is `85/88`, the direct file parent is `85/88`, and [UID:000137][0x004a1b60-0x004a1d6a.DirectX](by-memory/0x004a1b60-0x004a1d6a.DirectX.md) plus [UID:0002MD][0x00618e60-0x00618e70.DirectXVtableData](by-memory/0x00618e60-0x00618e70.DirectXVtableData.md) document the exact code/vtable evidence.

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `82/88`.
  - Summary/evidence: DirectDraw bootstrap responsibility, compact layout, constructor/destructor/unwind/scalar-destructor methods, singleton ownership, startup/GrafPort evidence, and generated alias issue are documented; remaining work is minimal source-facing polish and Wave3 data cleanup for unrelated font-singleton aliasing.
- 2026-05-31 exact vtable split:
  - Before: the page linked only the combined vtable type page and `RECONSTRUCTABLE` was blank.
  - After: the page is marked `RECONSTRUCTABLE:TRUE` and links the exact `0x00618e60-0x00618e70` vtable-data child.
  - Summary/evidence: IDA MCP `list_globals`, `xrefs_to`, and dword scan verify the `DirectX` RTTI/vtable record and prove the adjacent string boundary at `0x00618e70`.
