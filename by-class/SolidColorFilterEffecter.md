*** UID:0000DE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SolidColorFilterEffecter

## Status

- Confidence: strong for role and ownership; strong that generated `g_pScreenEffecterList` is only a stale alias for shared UI layer storage.
- Proposed source: `render/Effects.cpp`
- Current recovered source: `source-3/simroot_v2/class_SolidColorFilterEffecter.cpp`
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Responsibility

`SolidColorFilterEffecter` is a [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md) subclass that fills its filter buffer with one converted 16-bit RGB color and stores opacity/active state. It attaches pane state through `g_pLayerManager2` and the shared UI layer/context slot documented under the stale [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md) alias.

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055ae00-0x0055aec2` | constructor | IDA confirms the filter-base construction, RGB-to-16-bit conversion, opacity clamp path, and pane setup call that pushes `dword_69B364` at `0x0055ae9a`. |
| `0x0055aed0-0x0055af5e` | destructor | Tears down solid-color pane state, filter base, and screen-effect base vtable state. |
| `0x0055af60-0x0055afa4` | `FillBuffer` | Fills the effect pixel buffer with the cached 16-bit color. |
| `0x0055c000-0x0055c0bd` | scalar deleting destructor | Destructor path with delete-flag handling. |

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md)
- [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `82`, confidence `86`.
- Evidence: the page documents effect role, ownership, constructor/destructor/fill/scalar-destructor ranges, base-class relationship, and stale global-alias handling; remaining completion gap is source-ready reconstruction detail.
- 2026-06-05: Marked reconstructable and attached to [UID:0000IZ][Effects](by-file/Effects.md).
- Evidence: live IDA MCP `lookup_funcs` confirms the documented NexusTK-owned method anchors at `0x0055ae00`, `0x0055aed0`, `0x0055af60`, and `0x0055c000`; both this class (`82/86`) and the parent file (`88/80`) meet the 80/80 parent gate. C++ remains blank under the final-code threshold.
