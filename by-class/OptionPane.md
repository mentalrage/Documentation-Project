*** UID:00009V | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000M7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000M7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# OptionPane

## Status

- Confidence: strong for old `OptionPane` behavior, method ranges, file ownership, and child routing; medium-high for final grouping with `NewOptionPane`.
- Likely source file: [UID:0000M7][OptionPane](by-file/OptionPane.md)
- Main address doc: [UID:0001DO][0x0053d820-0x0053e520.OptionPane](by-memory/0x0053d820-0x0053e520.OptionPane.md)
- Current recovered file: `source-3/simroot_v2/class_OptionPane.cpp`

## Functionality

`OptionPane` is the older client option dialog. It builds a dialog over the shared option/control infrastructure, initializes option controls from config/game state, reacts to option commands, and sends opcode `0x11b` option updates.

## 2026-06-20 B004 Source-Quality Refresh

B004 resolves the old `OptionPane` cluster as class/file-routed source code with a broad split-index parent, not one monolithic emitted body. Former `dword_67A7C8` is [UID:00028Q][0x0067a7c8-0x0067a7cc.g_pConfig](by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md), former `dword_67A7D0` is [UID:00028R][0x0067a7d0-0x0067a7d4.g_pSoundManager](by-memory/0x0067a7d0-0x0067a7d4.g_pSoundManager.md), and former `dword_69B41C` is [UID:0002XU][0x0069b41c-0x0069b420.g_pIconsPane](by-memory/0x0069b41c-0x0069b420.g_pIconsPane.md). The constructor, source destructor body, `OnOptionCommand`, server-response callback, and server-option state helpers clear the current 85/85 source gate through this class page and file parent [UID:0000M7][OptionPane](by-file/OptionPane.md). The broad [UID:0001DO][0x0053d820-0x0053e520.OptionPane](by-memory/0x0053d820-0x0053e520.OptionPane.md) range is now a split index; first-draft C++ belongs on source-bearing child pages, while compiler switch data and scalar deleting destructor wrappers remain compiler output/no-C++.

Known old `OptionPane` fields:

| Field | Meaning |
| --- | --- |
| full-object `+0x1fc` | Legacy child/control lookup list; command/state helpers call its virtual slot `+0x10` with control ids. |
| adjusted callback `+0x15c` | Same child/control lookup list when the server-response callback receives `this` adjusted by `-0xa0`. |
| full-object `+0x26c..+0x270` | `m_serverOptionState[5]`, the server-provided option availability/status bytes, in control order `5`, `4`, `7`, `8`, `3`. |
| adjusted callback `+0x1cc..+0x1d0` | Same `m_serverOptionState[5]` field viewed through adjusted `this`. |

## Method Map

| Method | Address | Notes |
| --- | --- | --- |
| constructor | `0x0053d820-0x0053dd4f` | Builds the older options UI and sends the open/request packet. |
| non-deleting destructor helper | `0x0053dd50-0x0053dd6f` | IDA-confirmed helper that resets vtables and calls base teardown; not currently listed by Wave3 as a method. |
| retained raw commit/close body | `0x0053dd70-0x0053dda6` | Exact source-shaped `this` body: conditional `g_pConfig->SaveToRegistry()`, conditional [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md) when `g_activeMapPane != NULL`, then close/remove. No IDA function, start xref, pointer/immediate route, or vtable slot was recovered, so this is support-only and not a class declaration/emitter. Ten `0xcc` bytes follow through `0x0053ddb0`. |
| `OnOptionCommand` | `0x0053ddb0-0x0053e191` | Handles option command ids and updates config/server state. |
| compiler switch dispatch data | `0x0053e191-0x0053e1e0` | Jump table, selector bytes, and alignment for `OnOptionCommand`; no source C++. |
| `OnServerOptionResponse(const PacketEvent *event)` | [UID:0001DP][0x0053e1e0-0x0053e377.OptionPaneServerOptionResponse](by-memory/0x0053e1e0-0x0053e377.OptionPaneServerOptionResponse.md) | Vtable-routed through `0x00620ce4`; payload pointer is `event+0x0c` / `Block[3]`, bytes `0x21`/`0x23` handle alert id `61` and server-option state updates, and formal C++ lives on the exact child page. |
| local `SendOptionPacket11B` copy | [UID:0001DQ][0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B](by-memory/0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B.md) | Sends three-byte opcode `0x011b` option updates; same packet layout as shared `0x00540e50`, but old-pane-local callers only. |
| server option update helper island | [UID:00023I][0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers](by-memory/0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers.md) | Non-emitting split index for file-local `OptionPaneSendOptionPacket11BSubcommand63(unsigned char optionCode, unsigned char selectedIndex)`, internal padding, and primary-this `OptionPane::ApplyServerOptionAvailability(const unsigned char *payload)`. |
| scalar deleting destructor | `0x00542940-0x00542995` | Deleting destructor wrapper in the shared thunk/destructor island. |
| [UID:00035B][0x00620c70-0x00620c74.OptionPaneRttiBoundaryData](by-memory/0x00620c70-0x00620c74.OptionPaneRttiBoundaryData.md) | `0x00620c70-0x00620c74` | Exact terminal RTTI boundary dword assigned to this class after the strict gate cleared. |

## Notes

Wave3 reports no missing refs for `OptionPane`, but IDA shows additional local helper starts that are not represented as methods/globals. Treat the generated class file as useful behavior evidence, not a complete original source file.

## IDA Evidence

- 2026-06-01 `lookup_funcs` confirms modeled functions at `0x0053d820-0x0053dd4f`, `0x0053dd50-0x0053dd6f`, `0x0053ddb0-0x0053e191`, `0x0053e1e0-0x0053e377`, and `0x0053e380-0x0053e3c1`.
- Vtable/data refs tie the class to read-only data at `0x00620c74`: constructor write at `0x0053d861`, non-deleting destructor write at `0x0053dd50`, and scalar deleting destructor write at `0x00542946`.
- The server response helper `OptionPane::OnServerOptionResponse(const PacketEvent *event)` and command handler are vtable-referenced through `0x00620ce4` and `0x00620cbc` respectively; the response payload pointer is loaded from `Block[3]` / `event+0x0c`, while the local sender has four code callers inside `OnOptionCommand`.
- Raw helper bodies at `0x0053e3d0` and `0x0053e420` remain old `OptionPane` source-shaped bytes but are not IDA functions; keep their exact evidence on [UID:00023I][0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers](by-memory/0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers.md). B010 resolves `0x0053e420` as a selected-index radio state updater through `RadioGroupControlPane::SetSelectedIndex(byte == 0)`, not a child enable/disable helper.
- The separate raw span at `0x0053dd70-0x0053dda6` has 18 instructions and preserves the registry-save, active-map-gated profile-save, close/remove sequence. B005's bounded liveness searches found no modeled function, start xref, VA/RVA pointer or immediate route, or vtable route; it remains retained behavior evidence only, followed by ignored `0xcc` alignment at `0x0053dda6-0x0053ddb0`.
- 2026-06-12 A004 live IDA MCP recheck confirms `lookup_funcs` sizes for constructor `0x52f` / decimal `1327` (Verified with int_convert.py), non-deleting destructor `0x1f`, `OnOptionCommand` `0x3e1` / decimal `993` (Verified with int_convert.py), server response `0x197`, local sender `0x41`, and scalar deleting destructor `0x55` / decimal `85` (Verified with int_convert.py). `xrefs_to(0x00620c74)` ties the class vtable to constructor, non-deleting destructor, and scalar deleting destructor stores; `lookup_funcs` still reports `0x0053e3d0` and `0x0053e420` as not IDA functions even though disassembly shows source-shaped helper bodies.
- 2026-06-12 A003 Batch 281 routes [UID:00035B][0x00620c70-0x00620c74.OptionPaneRttiBoundaryData](by-memory/0x00620c70-0x00620c74.OptionPaneRttiBoundaryData.md) to this class. A fresh `xrefs_to` check on `c001_nexustk` reconfirmed that the RTTI dword itself has no direct xrefs and the next vtable base at `0x00620c74` has constructor, non-deleting destructor, and scalar deleting destructor refs at `0x0053d861`, `0x0053dd50`, and `0x00542946`.
- Reconstructable: true. C++ is intentionally blank on this class page because exact by-memory child pages own the method bodies; [UID:0001DP][0x0053e1e0-0x0053e377.OptionPaneServerOptionResponse](by-memory/0x0053e1e0-0x0053e377.OptionPaneServerOptionResponse.md) now carries the accepted `PacketEvent` formal C++.
- Current C++ direction: the class page emits `[[CHILDREN]]` and should not inline method bodies here. Exact by-memory child pages own constructor, destructor, command handler, server-response callback, raw state applier, and file-local packet-helper C++. The no-route `0x0053dd70` body is not promoted to a child or standalone emitter.

## Cross References

- [UID:0000M7][OptionPane](by-file/OptionPane.md)
- [UID:000097][NewOptionPane](by-class/NewOptionPane.md)
- [UID:0001DO][0x0053d820-0x0053e520.OptionPane](by-memory/0x0053d820-0x0053e520.OptionPane.md)
- [UID:0001DP][0x0053e1e0-0x0053e377.OptionPaneServerOptionResponse](by-memory/0x0053e1e0-0x0053e377.OptionPaneServerOptionResponse.md)
- [UID:0001DQ][0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B](by-memory/0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B.md)
- [UID:00023I][0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers](by-memory/0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers.md)
- [UID:00035B][0x00620c70-0x00620c74.OptionPaneRttiBoundaryData](by-memory/0x00620c70-0x00620c74.OptionPaneRttiBoundaryData.md)

## Changes

- 2026-07-14 B005 [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md) implementation callback support sync:
  - Score, metadata, class formal block, and existing method declarations remain unchanged. Added the exact raw `[0x0053dd70,0x0053dda6)` commit/close sequence, active-map gate, zero-liveness disposition, following ignored padding, and explicit no-emitter/no-declaration rule.

- 2026-06-26 B001 implementation callback:
  - No score change. Updated the method map and IDA evidence for [UID:0001DP][0x0053e1e0-0x0053e377.OptionPaneServerOptionResponse](by-memory/0x0053e1e0-0x0053e377.OptionPaneServerOptionResponse.md) to `OptionPane::OnServerOptionResponse(const PacketEvent *event)`, vtable route `0x00620ce4`, payload `Block[3]` / `event+0x0c`, and exact-child formal C++ ownership.
- 2026-06-12 A004 Batch 247 strict-gate repair:
  - Before: `COMPLETION:84`, `CONFIDENCE:82`, and method rows carried one-byte-short half-open endpoints.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:87`; kept direct parent [UID:0000M7][OptionPane](by-file/OptionPane.md), which clears `91/85`.
  - Evidence: live IDA MCP reconfirmed exact function sizes for constructor/non-deleting destructor/command/server-response/local-sender/scalar-deleting destructor, verified the raw `0x0053e3d0` and `0x0053e420` helper bodies remain non-IDA functions, and rechecked vtable refs through `0x00620c74`.
- 2026-06-20 B004 Rule 26 source-quality incorporation:
  - No score change. Added the split-index model, global-name resolutions, field mapping, method/source map, and C++ routing rule for source-bearing children.
  - Evidence: B004 read-only PE/Capstone pass reconciles adjusted-this server-option fields, class/file owner routes, raw helper no-route caveats, and compiler switch/scalar-deleting-destructor no-C++ policy.
- 2026-06-21 B010 Rule 26 source-quality incorporation:
  - No score change. Updated the server-option field model to `m_serverOptionState[5]`, recorded the control order `5/4/7/8/3`, distinguished the file-static packet helper from the primary-this apply helper, and replaced stale `ApplyServerOptionStates`/enable-disable wording with `OptionPane::ApplyServerOptionAvailability` and `SetSelectedIndex(byte == 0)`.
  - Evidence: B010's local export and support-doc review confirmed the packet helper has no `this`, the apply helper consumes primary `OptionPane *this`, the response handler uses an adjusted view of the same fields/control manager, and no direct caller/pointer route was found for either raw start.
- 2026-06-12 A003 Batch 281: Kept class score at `86/87` and added the exact assigned RTTI boundary child [UID:00035B][0x00620c70-0x00620c74.OptionPaneRttiBoundaryData](by-memory/0x00620c70-0x00620c74.OptionPaneRttiBoundaryData.md). No class score increase because this pass only rechecked the narrow RTTI/vtable-boundary refs, not the full old/new option-pane source family.
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
- 2026-06-30 B007 implementation callback:
  - Changed from `86/87` to `87/88` and inserted formal `[[CHILDREN]]`.
  - Evidence: accepted B007 report confirms this class page is a container over exact old `OptionPane` method/helper children. The old class split remains child-owned and [UID:00035B][0x00620c70-0x00620c74.OptionPaneRttiBoundaryData](by-memory/0x00620c70-0x00620c74.OptionPaneRttiBoundaryData.md) is now documented as non-reconstructable compiler RTTI/vtable boundary support, so the class emits a marker rather than a blank block or duplicated method bodies.
