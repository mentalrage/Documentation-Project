*** UID:0000F3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TimerPane

## Status

- Confidence: strong for class behavior and IDA boundaries.
- Likely source file: [UID:0000OU][TimerPane](by-file/TimerPane.md)
- Address range: [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md)
- Current recovered file: `source-3/simroot_v2/class_TimerPane.cpp`
- Singleton: [UID:0000SJ][g_pTimerPane](by-global/g_pTimerPane.md) at `0x0069b4d8`
- Autogen parent: [UID:0000OU][TimerPane](by-file/TimerPane.md). The class remains `88/90`, and the direct file parent is `87/86` after the Batch 058 parent-chain repair.

## Class Purpose

`TimerPane` is a server-controlled timer display pane for the live map UI. It supports static display, count-up, countdown, and delete modes, and draws the timer as sprite digits from `NUMBER.EPF` or `NUMBER.EPD`.

The class has multiple vtable/subobject entries. The timer callback uses the subobject at `this + 0xa4` and adjusts back to the base pane by subtracting `0xa4`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `TimerPane` | `0x005986e0-0x00598841` | Constructs a 288-byte pane, stores the singleton, chooses digit-slot width, sets bounds, records the display format, and schedules repaint callbacks. |
| `~TimerPane` / cleanup body | `0x00598850-0x00598878` | Reinstalls vtables, clears `g_pTimerPane`, and runs pane base cleanup. Omitted from active generated source. |
| `SetTimer` / configure timer | `0x00598880-0x005988f6` | Sets timer mode and value, refreshes start time, and computes expiration time. Omitted from active generated source. |
| `OnTimerTick` | `0x00598900-0x00598959` | Destroys the pane after expiration; otherwise invalidates and schedules the next 100 ms callback. |
| `OnDraw` | `0x00598960-0x00598ae3` | Computes current elapsed/remaining seconds and draws the formatted timer string. |
| `DrawDigit` | `0x00598b40-0x00598bd4` | Loads one digit or colon frame from `NUMBER.EPF`/`NUMBER.EPD` and draws it at the requested offset. |
| `ClearTimerPaneSingleton` | `0x00598c30-0x00598c3a` | Clears the singleton pointer. |
| adjustor thunk | `0x00598c3b-0x00598c45` | Adjusts from secondary subobject by `-0xa0` and forwards to the scalar deleting destructor. |
| adjustor thunk | `0x00598c46-0x00598c50` | Adjusts from timer subobject by `-0xa4` and forwards to the scalar deleting destructor. |
| `ScalarDeletingDestructor` | `0x00598c60-0x00598cbe` | Clears the singleton, runs pane cleanup, and optionally frees storage. |

## Timer Modes

| Mode | Behavior |
| --- | --- |
| `0` | Static value mode. Map packet handling ignores this mode if no timer pane exists. |
| `1` | Count-up display. Draw computes `now - startTime`. |
| `2` | Countdown display. Draw computes `endTime - now`. |
| `3` | Initial/delete mode. Constructor initializes to `3`; map packet mode `3` marks the pane for deletion. |

## Layout Notes

See [UID:0001WE][TimerPaneLayout](by-type/by-struct/TimerPaneLayout.md). The currently important offsets are:

- `+0x000`: primary pane vtable;
- `+0x0a0`: secondary vtable;
- `+0x0a4`: timer callback subobject vtable;
- `+0x0f8`: `__time64_t startTime`;
- `+0x100`: `__time64_t endTime`;
- `+0x108`: display format;
- `+0x10c` and `+0x110`: screen position;
- `+0x114`: timer mode;
- `+0x118`: displayed seconds.

## Evidence Notes

- IDA MCP confirms all listed starts as real functions.
- Constructor callers are from `MapPane::HandlePacket` case `0x67` and the related helper at `0x005140a0`.
- `DrawDigit` branches on [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97`: EPF mode uses `NUMBER.EPF`, legacy mode uses `NUMBER.EPD`.
- `0x00598cc0` is the next class (`TotemFrame`), not part of `TimerPane`.

## Cross-References

- [UID:0000OU][TimerPane](by-file/TimerPane.md)
- [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md)
- [UID:0000SJ][g_pTimerPane](by-global/g_pTimerPane.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0001RQ][timerpane-number-resources](by-resource/timerpane-number-resources.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)

## Changes

- 2026-06-07 Batch 058 parent-chain repair:
  - Before: `AUTOGEN_PARENT_UID:` blank, so [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md) reported `autogen_parent_unknown` for direct parent `0000F3`.
  - After: `AUTOGEN_PARENT_UID:0000OU`.
  - Evidence: [UID:0000OU][TimerPane](by-file/TimerPane.md) was refreshed to `87/86` with exact TimerPane memory, singleton, resource, packet, and boundary evidence, satisfying the corrected 85/85 child-and-parent gate for this class route.
- 2026-06-07 A008 alias cleanup: normalized the `DrawDigit` `byte_66DA97` branch to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), preserving `byte_66DA97` as the IDA lookup alias.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:90`.
  - Summary/evidence: scored from IDA-confirmed method starts, timer modes, layout offsets, singleton behavior, resource references, packet-handling construction evidence, and exact next-class boundary note.
- 2026-05-31: Reconstructable metadata was blank and the memory range reference still used the one-past-end address.
  - Before: `RECONSTRUCTABLE:` and `0x005986e0-0x00598cbf`.
  - After: `RECONSTRUCTABLE:TRUE` and [UID:0001KB][0x005986e0-0x00598cbe.TimerPane](by-memory/0x005986e0-0x00598cbe.TimerPane.md).
  - Summary/evidence: IDA MCP rechecked the complete TimerPane function set and confirmed the scalar deleting destructor ends at `0x00598cbe`, with `0x00598cbf` belonging to alignment padding before `TotemFrame`.
