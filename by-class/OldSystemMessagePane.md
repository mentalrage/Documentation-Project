*** UID:00009T | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# OldSystemMessagePane

## Status

- Confidence: strong for class role, live constructor caller, method boundaries, vtable ownership, singleton lifecycle, and destructor support; medium-high for final field/helper names.
- Likely source file: [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- Main address range: [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md)
- Reconstruction disposition: document and model the class, but do not emit final C++ until the field layout and helper names meet the project bar.

## Class Purpose

`OldSystemMessagePane` is the legacy scrollable system-message pane. It manages a message collection, fixed 12-pixel line metrics, separator/header drawing, help shortcut handling, and destruction of message entries plus ten tile contexts.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x00588e30-0x00589173` | `OldSystemMessagePane::OldSystemMessagePane()` | Constructor called by the legacy main UI graph path; stores the old system-message singleton, installs three vtables, initializes tile contexts, and seeds starter message entries. |
| `0x00589180-0x0058948f` | Message-list support helpers | Clears singleton/instance state and handles message-entry insertion/update paths used by system-message and old-mode callers. |
| `0x00589540-0x00589668` | Scroll metric helpers | Six vtable-backed helpers for max line, visible line count, page step, line pixel offset, total/content size, and scroll delta behavior. |
| `0x00589670-0x005896c0` | `HandleHelpShortcut` | Handles the Ctrl+`?` help shortcut. |
| `0x005896c0-0x005898f3` | Vtable-backed input/scroll helper | Legacy system-message helper reached through the secondary vtable. |
| `0x00589920-0x00589c0c` | `OnDraw` | Paints message entries, separators, and clipped text rows. |
| `0x00589c80-0x00589cea` | `GetTotalLineCount` | Sums message-entry line counts; called by scroll metric helpers. |
| `0x0058ab1d-0x0058ab33` | Adjustor/thunk helpers | Two vtable-referenced destructor adjustor thunks to `0x0058adb0`. |
| `0x0058adb0-0x0058af00` | `~OldSystemMessagePane(int deleteFlags)` | Destroys message collection, tile contexts, and base scrollable pane state. |

## Live IDA Evidence

Checked on 2026-06-04:

- `lookup_funcs` confirms `0x00588e30-0x00589173` for the constructor, `0x00589540-0x00589668` for the six scroll metric helpers, `0x00589670-0x005896c0` for the help shortcut handler, `0x005896c0-0x005898f3` for a secondary-vtable helper, `0x00589920-0x00589c0c` for drawing, `0x00589c80-0x00589cea` for total line counting, two `0xb` destructor adjustor thunks at `0x0058ab1d` and `0x0058ab28`, and `0x0058adb0-0x0058af00` for the scalar deleting destructor body.
- `xrefs_to 0x00588e30` reports a direct constructor caller at `0x004f8861` inside [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md), immediately after a `0x26c` allocation.
- Constructor disassembly writes [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md) slot `0x0069b4c8` at `0x00588e7c` and clears it on the null-adjusted path at `0x00588e83`.
- Constructor and destructor disassembly install the `OldSystemMessagePane` primary and adjusted vtables at `this+0x00`, `this+0xa0`, and `this+0xa4`; the live vtable data refs are `0x0062d8c8`, `0x0062d93c`, and `0x0062d96c`.
- Constructor callsites include the `ScrollablePane` base constructor at `0x0055e660`, ten `EPFTileContext` constructor calls at `0x00457a60`, ten resource-layout/tile copy calls at `0x004d04d0` using `off_62D974`, and starter message-entry setup through `LObject`/system-message entry helpers around `0x00516030`, `0x00516050`, `0x00516220`, and `0x00516170`.
- The help handler narrows the key event and returns true only for key event type `8`, ASCII `?`, and modifier byte `4`, then calls `0x00589d30` on `this - 0xa0`.
- The destructor adjustor thunks subtract `0xa0` and `0xa4` from `this` and jump to `0x0058adb0`; `xrefs_to 0x0058adb0` also reports the primary vtable data ref at `0x0062d8c8`.
- Destructor disassembly clears `0x0069b4c8` at `0x0058aeb7`, walks owned message entries through virtual cleanup calls, runs ten tile-context cleanup calls at `0x00458500`, tears down the scrollable-pane base at `0x0055e780`, and optionally frees storage.
- `xrefs_to 0x0069b4c8` also reports a read from the main UI teardown path at `0x005049c4` and an old-mode read from the emotion input path at `0x005b2d5a`, confirming the singleton is part of legacy UI flow.

## Source Layout Decision

Keep this class in [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md). The direct caller is the old-mode branch of the main UI graph, but the class behavior, vtables, message-entry ownership, and scrollable system-message helpers all sit inside the system-message pane family rather than the main UI graph file.

## Score Rationale

The score is raised from `78/76` to `82/84` because the page now records current live IDA evidence for the constructor caller, method extents, vtable slots, singleton reads/writes, constructor child initialization, help shortcut conditions, destructor thunk offsets, and destructor cleanup behavior. It remains below final reconstruction quality because the exact field names and several helper method names are still provisional, and the broader owner file has unresolved split caveats.

## Cross-References

- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:0000EA][SystemMessagePane](by-class/SystemMessagePane.md)
- [UID:000030][ColorStringSystemMessage](by-class/ColorStringSystemMessage.md)
- [UID:000061][HeaderSystemMessage](by-class/HeaderSystemMessage.md)
- [UID:00005D][FooterSystemMessage](by-class/FooterSystemMessage.md)
- [UID:00009C][NewSystemMessagePane](by-class/NewSystemMessagePane.md)
- [UID:0000UV][InitializeMainUiGraph_004F7D10](by-item/InitializeMainUiGraph_004F7D10.md)

## Changes

- Before: completion/confidence metadata were `0/0` despite method-map, constructor evidence, singleton notes, destructor behavior, and source-quality caveats.
- Changed to: `COMPLETION:78` and `CONFIDENCE:76`.
- Evidence: IDA-confirmed constructor, scroll metric helpers, help shortcut, draw, line-count, thunk, and destructor ranges are documented, along with constructor caller/global behavior; confidence remains medium because final field/helper names are not source-quality yet.
- 2026-06-04: Raised the class page from `78/76` to `82/84` without parent attachment or final C++.
  - Before: the page had the right high-level role but relied on stale source-output caveats and lacked current live evidence for vtable slots, singleton xrefs, constructor callsites, help-key conditions, and destructor cleanup details.
  - After: the page records exact live function boundaries, direct old UI graph caller, singleton writes/reads, three vtable installs, tile-context/resource setup, message-entry setup, help shortcut conditions, destructor thunk offsets, and destructor cleanup behavior.
  - Evidence: 2026-06-04 live IDA MCP `lookup_funcs`, `xrefs_to`, disassembly, vtable dword reads, and constructor/destructor callsite checks for `0x00588e30`, `0x00589540-0x00589668`, `0x00589670`, `0x00589920`, `0x00589c80`, `0x0058ab1d`, `0x0058ab28`, `0x0058adb0`, `0x0062d8c8`, `0x0062d93c`, `0x0062d96c`, and `0x0069b4c8`.
