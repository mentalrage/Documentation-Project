*** UID:00009T | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# OldSystemMessagePane

## Status

- Confidence: strong for class role and IDA boundaries; generated constructor source is incomplete.
- Likely source file: [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- Main address range: [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md)
- Current recovered file: `source-3/simroot_v2/class_OldSystemMessagePane.cpp`

## Class Purpose

`OldSystemMessagePane` is the legacy scrollable system-message pane. It manages a message collection, fixed 12-pixel line metrics, separator/header drawing, help shortcut handling, and destruction of message entries plus ten tile contexts.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x00588e30-0x00589173` | `OldSystemMessagePane::OldSystemMessagePane()` | Constructor. Wave3 lists it, and IDA confirms it, but current emitted source omits the body. |
| `0x00589540-0x00589668` | Scroll metric helpers | Max line, visible line count, page step, line pixel offset, total/content size, and scroll delta helpers. |
| `0x00589670-0x005896c0` | `HandleHelpShortcut` | Handles the `?` help shortcut. |
| `0x00589920-0x00589c0c` | `OnDraw` | Paints message entries, separators, and clipped text rows. |
| `0x00589c80-0x00589cea` | `GetTotalLineCount` | Sums message-entry line counts. |
| `0x0058ab1d-0x0058ab33` | Adjustor/thunk helpers | Vtable-referenced tiny helpers omitted from current emitted source. |
| `0x0058adb0-0x0058af00` | `~OldSystemMessagePane(int deleteFlags)` | Destroys message collection, tile contexts, and base scrollable pane state. |

## Evidence Notes

- Wave3 grades the class at effective `97.0`.
- IDA MCP confirms all listed starts as exact functions.
- Current generated source begins with the constructor install marker and a local struct, then jumps directly to later methods; do not treat the constructor as source-recovered.
- 2026-05-25 IDA recheck: the constructor at `0x00588e30` is directly called from the legacy main UI graph path at `0x004f8861`, writes the `OldSystemMessagePane` vtables, initializes ten tile contexts, constructs starter `ColorStringSystemMessage` rows, and sets the legacy singleton/global at `0x0069b4c8`.
- Current `simroot_v2/class_OldSystemMessagePane.cpp` still emits only `WAVE3 OMITTED METHOD BODY` for the constructor, so the method needs reconstruction or a generation fix before source migration. Track this with [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md).

## Cross-References

- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:0000EA][SystemMessagePane](by-class/SystemMessagePane.md)
- [UID:000030][ColorStringSystemMessage](by-class/ColorStringSystemMessage.md)
- [UID:000061][HeaderSystemMessage](by-class/HeaderSystemMessage.md)
- [UID:00005D][FooterSystemMessage](by-class/FooterSystemMessage.md)
- [UID:00009C][NewSystemMessagePane](by-class/NewSystemMessagePane.md)
- [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md)

## Changes

- Before: completion/confidence metadata were `0/0` despite method-map, constructor evidence, singleton notes, destructor behavior, and generated-output caveats.
- Changed to: `COMPLETION:78` and `CONFIDENCE:76`.
- Evidence: IDA-confirmed constructor, scroll metric helpers, help shortcut, draw, line-count, thunk, and destructor ranges are documented, along with constructor caller/global behavior; confidence remains medium because the current simroot constructor body is omitted and needs reconstruction or a generation fix.
