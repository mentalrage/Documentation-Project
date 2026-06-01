*** UID:0000CX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SelfSaveOKPane

## Status

- Likely source file: [UID:0000NN][SelfSaveOKPane](by-file/SelfSaveOKPane.md)
- Confirmed local range: [UID:0001B0][0x005147d0-0x00514914.SelfSaveOKPane](by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md)
- Current generated file: `source-3/simroot_v2/class_SelfSaveOKPane.cpp`
- Confidence: strong for the small class/vtable island, medium for final original source placement, and strong that broader generated ownership is polluted.

## Class Purpose

`SelfSaveOKPane` is a small `TextBoxPane`-derived confirmation/status pane. The constructor builds a fixed-size text box, loads localized string id `61`, writes it into the pane, places the pane on `g_pScreenPane` / `g_pRenderLayer0`, and schedules a one-second timer that dismisses the pane.

IDA now shows the SelfSaveOKPane construction sequence in three places: the standalone constructor at `0x005147d0`, an inline block in [UID:0000L3][MapPane](by-file/MapPane.md) packet case `0x21`, and a factory-like helper at [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md).

The current generated file is not a safe source-ownership guide. It also emits [UID:0000DK][SpelledPane](by-class/SpelledPane.md) entry-list methods and broad text-edit control methods that have many non-SelfSave callers.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x005147d0-0x005148d5` | Constructs the text-box pane, sets localized caption text, and attaches a frame rect. |
| `OnTimerExpired` | `0x005148e0-0x00514913` | Timer-handler facet method; vtable slot `0x0061e850` points here and the body dismisses/releases the owner when timer state is zero. |
| factory/helper | [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md) | Allocates and constructs the same pane sequence; no direct xrefs currently reported. |

## Excluded Generated Ownership

Do not migrate the following ranges as `SelfSaveOKPane` source solely because they appear in `class_SelfSaveOKPane.cpp`:

- `0x0056bca0-0x0056c0da`: entry add/remove/rebuild/parse helpers. IDA callers and the `SpelledPane::UpdateEntriesAndScheduleRefresh` offset adjustment tie these to [UID:0000DK][SpelledPane](by-class/SpelledPane.md) entry storage.
- `0x00572fd0-0x00573231` and `0x00573900-0x00573961`: vector insert/erase machinery for the same SpelledPane entry records. Keep these non-source-facing helpers.
- `0x0058e270-0x005905f0`: broad text-edit/text-box methods with many callers across UI controls. These belong with [UID:0000EO][TextEditPane](by-class/TextEditPane.md), [UID:0000EI][TextBoxPane](by-class/TextBoxPane.md), or a shared text-control source family, not with this class.

## Evidence Notes

- IDA MCP on 2026-05-26 confirms `0x005147d0` and `0x005148e0` as real functions, and still reports no direct executable callers for either in the current database.
- IDA `list_globals` and `xrefs_to` identify [UID:0001YV][SelfSaveOKPane_vtables](by-type/by-vtable/SelfSaveOKPane_vtables.md) at `0x0061e7a4`, `0x0061e81c`, and `0x0061e84c`.
- IDA `xrefs_to 0x005148e0` reports a vtable data reference at `0x0061e850`, matching the timer-handler facet installed at object offset `+0xa4`.
- IDA `xrefs_to` for the SelfSaveOKPane vtable bases reports construction writes from the standalone constructor, [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md), and [UID:0000L3][MapPane](by-file/MapPane.md) packet case `0x21` inline construction.
- 2026-05-26 IDA `py_eval` recheck confirms `0x00508516` is inside `MapPane::HandlePacket` (`0x00507c90`), and the inline block writes vtables at `0x0050855b`, `0x00508561`, and `0x0050856b` before setting localized string id `61`.
- `0x005147d0` calls the [UID:0000EI][TextBoxPane](by-class/TextBoxPane.md) constructor, localized string lookup at `0x004f0350`, and shared text-set helpers.
- IDA caller checks show `0x0056bca0`, `0x0056be20`, and `0x0056c0e0` are called from self-look and system-message paths that use [UID:0000DK][SpelledPane](by-class/SpelledPane.md), not from the `0x005147d0` constructor island.
- 2026-05-26 IDA `py_eval` recheck shows `0x0056bca0` has seven non-SelfSave caller refs and `0x0058e270` has broad UI caller fanout across at least 18 refs, so their current `SelfSaveOKPane` owner is a generated-data artifact.

## Cross-References

- [UID:0000NN][SelfSaveOKPane](by-file/SelfSaveOKPane.md)
- [UID:0001B0][0x005147d0-0x00514914.SelfSaveOKPane](by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md)
- [UID:0000DK][SpelledPane](by-class/SpelledPane.md)
- [UID:0000EI][TextBoxPane](by-class/TextBoxPane.md)
- [UID:0000EO][TextEditPane](by-class/TextEditPane.md)
- [UID:0001YV][SelfSaveOKPane_vtables](by-type/by-vtable/SelfSaveOKPane_vtables.md)
- [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md)
- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `80`.
- Evidence: the page documents the narrow constructor/timer/factory island, inline construction evidence, vtable references, and polluted generated ownership exclusions; confidence remains medium-high because final source placement is still provisional.
