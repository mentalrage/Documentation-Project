*** UID:00007S | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000L4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MapRefreshDimmer

## Status

- Confidence: strong for behavior, vtable anchors, and map-side construction evidence; medium for standalone file versus private `MapPane.cpp` placement.
- Likely source file: [UID:0000L4][MapRefreshDimmer](by-file/MapRefreshDimmer.md), or private code in [UID:0000L3][MapPane](by-file/MapPane.md)
- Address range: [UID:0001B1][0x00514920-0x00514e5b.MapRefreshDimmer](by-memory/0x00514920-0x00514e5b.MapRefreshDimmer.md)
- Autogen parent: [UID:0000L4][MapRefreshDimmer](by-file/MapRefreshDimmer.md) as the current map-transition helper owner.

## Class Purpose

`MapRefreshDimmer` is a short-lived timer-based dimming helper used during map refresh or loading transitions. It builds on generic [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md) overlay behavior, owns a fade timer, and destroys itself when the fade-out period completes.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MapRefreshDimmer` | `0x00514920-0x0051499a` | Constructs the dimmer and installs a two-second timer. |
| `OnTimerExpired` | `0x005149f0-0x00514a0c` | Destroys the dimmer when fade-out completes. |
| `ScalarDeletingDestructor_vtable2_adjustor` | `0x00514d34-0x00514d3e` | Adjusts from the offset-`0xa0` interface back to object base. |
| `ScalarDeletingDestructor_vtable3_adjustor` | `0x00514d3f-0x00514d49` | Adjusts from the offset-`0xa4` interface back to object base. |
| `ScalarDeletingDestructor` | `0x00514e20-0x00514e5b` | Resets vtables, destroys the base, and optionally frees memory. |

## Evidence Notes

- 2026-06-04 live IDA MCP identity: `NexusTK.exe` at base `0x400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- Function lookup confirms starts and sparse boundaries: `0x00514920` size `0x7b`, `0x005149f0` size `0x1d`, `0x00514d34` size `0xb`, `0x00514d3f` size `0xb`, and `0x00514e20` size `0x3b`; `0x00514e5b` is not a function start.
- The constructor delegates to `ScreenDimmer` at `0x00559b90` with dim level `3` and `dword_67A7CC`, writes MapRefreshDimmer vtables at object offsets `0`, `0xa0`, and `0xa4`, then starts a timer through `0x005975e0` with a `2000` ms interval.
- The timer callback at `0x005149f0` is referenced from vtable data at `0x0061e8d8`; on timer id `0`, it adjusts from the timer/interface subobject back by `0xa4` and invokes the deleting virtual.
- The scalar deleting destructor at `0x00514e20` calls `ScreenDimmer` teardown at `0x00559cf0` and frees storage through `0x004f4ac0` only when the delete flags require it.
- Vtable data confirms the primary table `??_7MapRefreshDimmer@@6B@` at `0x0061e858`, secondary table `??_7MapRefreshDimmer@@6B@_0` at `0x0061e8a4`, and tertiary table `??_7MapRefreshDimmer@@6B@_1` at `0x0061e8d4`; the constructor writes all three and the adjustor thunks target the deleting destructor.
- `sub_506DF0`, a MapPane-side input handler, has an inline construction branch that allocates `0xfc` bytes, calls the `ScreenDimmer` constructor, installs the same MapRefreshDimmer vtables, starts the `2000` ms timer, and continues map refresh work. This keeps the class in the map transition family rather than the generic dimmer module.

## Cross-References

- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000L4][MapRefreshDimmer](by-file/MapRefreshDimmer.md)
- [UID:0001B1][0x00514920-0x00514e5b.MapRefreshDimmer](by-memory/0x00514920-0x00514e5b.MapRefreshDimmer.md)
- [UID:0000C8][ScreenDimmer](by-class/ScreenDimmer.md)

## Changes

- 2026-05-28: Corrected the scalar deleting destructor endpoint from `0x00514e5a` to `0x00514e5b`. Evidence: IDA MCP reports `sub_514e20` as `0x00514e20-0x00514e5b`.
- Completion/confidence score update: existed before as `0/0`; changed to `74/78`. Summary: the map-specific dimmer timer wrapper has clear purpose, method boundaries, base relationship, and file-split caveat, but it is still a small partial class page rather than exhaustive source reconstruction. Evidence: linked `MapRefreshDimmer` memory page, IDA-confirmed constructor/destructor bounds, `ScreenDimmer` relationship, and map-transition ownership note.
- 2026-06-04:
  - Before: scored as `74/78`, with no reconstructable flag, no autogen parent, stale source-output wording, and only partial constructor/destructor evidence.
  - After: scored as `84/88`, marked `RECONSTRUCTABLE:TRUE`, and parented to [UID:0000L4][MapRefreshDimmer](by-file/MapRefreshDimmer.md).
  - Summary/evidence: live IDA MCP rechecked the executable identity, method starts/sizes, constructor delegation to `ScreenDimmer`, three vtable writes, `2000` ms timer setup, timer callback behavior, scalar deleting destructor flags, vtable/RTTI anchors, adjustor thunks, and the MapPane-side inline construction branch at `sub_506DF0`; final source split and private method names remain below the `95/95` reconstruction bar.
