*** UID:00009V | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000M7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# OptionPane

## Status

- Confidence: strong for old `OptionPane` behavior, method ranges, and file ownership; medium for final grouping with `NewOptionPane`.
- Likely source file: [UID:0000M7][OptionPane](by-file/OptionPane.md)
- Main address doc: [UID:0001DO][0x0053d820-0x0053e520.OptionPane](by-memory/0x0053d820-0x0053e520.OptionPane.md)
- Current recovered file: `source-3/simroot_v2/class_OptionPane.cpp`

## Functionality

`OptionPane` is the older client option dialog. It builds a dialog over the shared option/control infrastructure, initializes option controls from config/game state, reacts to option commands, and sends opcode `0x11b` option updates.

## Method Map

| Method | Address | Notes |
| --- | --- | --- |
| constructor | `0x0053d820-0x0053dd4e` | Builds the older options UI and sends the open/request packet. |
| non-deleting destructor helper | `0x0053dd50-0x0053dd6e` | IDA-confirmed helper that resets vtables and calls base teardown; not currently listed by Wave3 as a method. |
| `OnOptionCommand` | `0x0053ddb0-0x0053e190` | Handles option command ids and updates config/server state. |
| server option response helper | [UID:0001DP][0x0053e1e0-0x0053e377.OptionPaneServerOptionResponse](by-memory/0x0053e1e0-0x0053e377.OptionPaneServerOptionResponse.md) | Handles old option-pane server response bytes `0x21`/`0x23`; currently unmodeled by Wave3. |
| local `SendOptionPacket11B` copy | [UID:0001DQ][0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B](by-memory/0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B.md) | Sends three-byte opcode `0x011b` option updates; same packet layout as shared `0x00540e50`, but old-pane-local callers only. |
| server option update helpers | [UID:00023I][0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers](by-memory/0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers.md) | Sends the old five-byte `0x011b`/`0x63` packet and applies five server-provided option availability bytes to child controls. |
| scalar deleting destructor | `0x00542940-0x00542994` | Deleting destructor wrapper in the shared thunk/destructor island. |

## Notes

Wave3 reports no missing refs for `OptionPane`, but IDA shows additional local helper starts that are not represented as methods/globals. Treat the generated class file as useful behavior evidence, not a complete original source file.

## IDA Evidence

- 2026-06-01 `lookup_funcs` confirms modeled functions at `0x0053d820-0x0053dd4f`, `0x0053dd50-0x0053dd6f`, `0x0053ddb0-0x0053e191`, `0x0053e1e0-0x0053e377`, and `0x0053e380-0x0053e3c1`.
- Vtable/data refs tie the class to read-only data at `0x00620c74`: constructor write at `0x0053d861`, non-deleting destructor write at `0x0053dd50`, and scalar deleting destructor write at `0x00542946`.
- The server response helper and command handler are vtable-referenced through `0x00620ce4` and `0x00620cbc` respectively, while the local sender has four code callers inside `OnOptionCommand`.
- Raw helper bodies at `0x0053e3d0` and `0x0053e420` remain old `OptionPane` source-shaped bytes but are not IDA functions; keep their exact evidence on [UID:00023I][0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers](by-memory/0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers.md).
- Reconstructable: true. C++ is intentionally blank because old option-control field names, child-control names, and final helper placement are not final-source quality.

## Cross References

- [UID:0000M7][OptionPane](by-file/OptionPane.md)
- [UID:000097][NewOptionPane](by-class/NewOptionPane.md)
- [UID:0001DO][0x0053d820-0x0053e520.OptionPane](by-memory/0x0053d820-0x0053e520.OptionPane.md)
- [UID:0001DP][0x0053e1e0-0x0053e377.OptionPaneServerOptionResponse](by-memory/0x0053e1e0-0x0053e377.OptionPaneServerOptionResponse.md)
- [UID:0001DQ][0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B](by-memory/0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B.md)
- [UID:00023I][0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers](by-memory/0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers.md)

## Changes

- 2026-05-28: Expanded the class map for the older `OptionPane` tail from `0x0053e3c0` to `0x0053e520`.
  - Before: only the local three-byte packet sender was listed after `OnOptionCommand`.
  - After: the local sender has corrected end `0x0053e3c1`, and the server-option update helper island at `0x0053e3d0-0x0053e520` is listed as `OptionPane` code.
  - Evidence: IDA MCP byte/function review shows padding at `0x0053e3c1-0x0053e3d0`, helper starts at `0x0053e3d0` and `0x0053e420`, and `MacroDialogs` beginning at `0x0053e520`.
- Before: completion/confidence metadata were `0/0` despite detailed behavior, method-map, packet-helper, server-response, and tail-helper documentation.
- Changed to: `COMPLETION:82` and `CONFIDENCE:76`.
- Evidence: constructor, command handling, local packet sender, server option response/update helpers, destructor island, and IDA-confirmed tail expansion are documented; confidence remains medium because final grouping with `NewOptionPane` and several generated-method omissions remain unresolved.
- 2026-06-01 completion/confidence update:
  - Before: `COMPLETION:82`, `CONFIDENCE:76`, no reconstructable/parent metadata.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:82`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000M7][OptionPane](by-file/OptionPane.md).
  - Evidence: IDA MCP rechecked modeled function ranges, vtable/data refs, local sender callers, raw helper boundaries, and the file parent now has a valid projected path.
