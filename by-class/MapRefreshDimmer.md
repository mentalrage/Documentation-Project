*** UID:00007S | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MapRefreshDimmer

## Status

- Confidence: strong for behavior, medium for file split.
- Likely source file: [UID:0000L4][MapRefreshDimmer](by-file/MapRefreshDimmer.md), or private code in [UID:0000L3][MapPane](by-file/MapPane.md)
- Address range: [UID:0001B1][0x00514920-0x00514e5b.MapRefreshDimmer](by-memory/0x00514920-0x00514e5b.MapRefreshDimmer.md)
- Current recovered file: `source-3/simroot_v2/class_MapRefreshDimmer.cpp`

## Class Purpose

`MapRefreshDimmer` is a short-lived timer-based dimming helper used during map refresh or loading transitions. It builds on generic [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md) overlay behavior, owns a fade timer, and destroys itself when the fade-out period completes.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MapRefreshDimmer` | `0x00514920-0x0051499a` | Constructs the dimmer and installs a two-second timer. |
| `OnTimerExpired` | `0x005149f0-0x00514a0c` | Destroys the dimmer when fade-out completes. |
| `ScalarDeletingDestructor` | `0x00514e20-0x00514e5b` | Resets vtables, destroys the base, and optionally frees memory. |

## Evidence Notes

- IDA MCP confirms `0x00514920-0x0051499b` as a real constructor-like function.
- The class is map-transition specific, so it should stay near `MapPane` until evidence proves it is a generic fade control.
- The generic dim overlay family is now tracked under [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md); this page should only own the map-specific timer wrapper.

## Cross-References

- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000L4][MapRefreshDimmer](by-file/MapRefreshDimmer.md)
- [UID:0001B1][0x00514920-0x00514e5b.MapRefreshDimmer](by-memory/0x00514920-0x00514e5b.MapRefreshDimmer.md)
- [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md)

## Changes

- 2026-05-28: Corrected the scalar deleting destructor endpoint from `0x00514e5a` to `0x00514e5b`. Evidence: IDA MCP reports `sub_514e20` as `0x00514e20-0x00514e5b`.
- Completion/confidence score update: existed before as `0/0`; changed to `74/78`. Summary: the map-specific dimmer timer wrapper has clear purpose, method boundaries, base relationship, and file-split caveat, but it is still a small partial class page rather than exhaustive source reconstruction. Evidence: linked `MapRefreshDimmer` memory page, IDA-confirmed constructor/destructor bounds, `ScreenDimmer` relationship, and map-transition ownership note.
