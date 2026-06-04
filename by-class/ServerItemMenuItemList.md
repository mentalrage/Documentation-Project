*** UID:0000D0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ServerItemMenuItemList

## Status

- Confidence: strong for live vtable identity, item-menu list behavior, exact virtual/destructor boundaries, and parent source placement; medium for raw helper reachability and final private field names.
- Reconstructability: reconstructable as the server-side private item-menu list under [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md), but final C++ remains blank until the raw helper and row-field names reach the 95/95 bar.
- Parent source file: [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md)
- Main address range: [UID:0001BP][0x0051ae90-0x0051b87a.ServerItemMenuItemList](by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md)

## Class Purpose

`ServerItemMenuItemList` is the row-list widget for server-provided item action menus. It stores packet/item context, maintains selected-row description text, forwards activation into the owning menu context, and draws rows with item icon, display name, and right-aligned value.

## Method Notes

| Method or range | Address | Role |
| --- | --- | --- |
| `ServerItemMenuItemList` | `0x0051ae90-0x0051aefc` | Raw constructor-shaped code; builds a `ListPane` with server menu row geometry and installs three `ServerItemMenuItemList` vtables. |
| non-deleting destructor | `0x0051af00-0x0051af35` | Resets vtables, notifies `g_serverItemMenuObserver`, and tail-calls shared `ListPane` cleanup. |
| append row helper | `0x0051af40-0x0051afbf` | Builds a server item row record from id/style/value/name/detail strings and appends it to the list. |
| selected-name packet helper | `0x0051afd0-0x0051b0f8` | Builds opcode `0x39` payload from the selected row's wide display string. |
| `OnItemSelected` | `0x0051b100-0x0051b18d` | Updates owner text slot `7` from the selected row detail text before delegating to `ListPane`. |
| explicit-text packet helper | `0x0051b190-0x0051b2a8` | Builds opcode `0x39` payload from a caller-supplied wide string. |
| `OnItemActivated` thunk | `0x0051b2b0-0x0051b2bb` | Loads owner/context from `this + 0x158` and jumps to shared activation logic at `0x0049de70`. |
| `HandleMenuEvent` | `0x0051b2c0-0x0051b3e0` | Handles row pointer/event logic and high-resolution help-pane behavior. |
| `DrawListEntry` | `0x0051b3e0-0x0051b87a` | Draws item icon, name, and numeric value in high-resolution and legacy layouts. |
| destructor thunks | `0x00520b13`, `0x00520b1e`, `0x00520ce0` | Secondary/tertiary adjustor thunks and scalar deleting destructor. |

## Evidence Notes

- Live IDA MCP reports no function object at raw helper starts `0x0051ae90`, `0x0051af00`, `0x0051af40`, `0x0051afd0`, and `0x0051b190`, but disassembly and call/data refs identify complete out-of-line class code at those addresses.
- Live IDA MCP confirms modeled function boundaries for virtuals and destructor glue: `0x0051b100-0x0051b18d`, `0x0051b2b0-0x0051b2bb` with the shared activation chunk at `0x0049de70-0x0049df14`, `0x0051b2c0-0x0051b3e0`, `0x0051b3e0-0x0051b87a`, adjustor thunks `0x00520b13-0x00520b1e` and `0x00520b1e-0x00520b29`, and scalar deleting destructor `0x00520ce0-0x00520d47`.
- Live byte checks confirm `0xcc` padding at `0x0051ae8d-0x0051ae90`, `0x0051aefc-0x0051af00`, `0x0051b87a-0x0051b880`, and after `0x00520d47`. The byte at `0x0051b879` is the final `retn 0Ch` operand for the row draw virtual, so `0x0051b87a` remains the correct exclusive end.
- Live vtable symbols bind the class: primary `??_7ServerItemMenuItemList@@6B@` at `0x0061ef44`, secondary `??_7ServerItemMenuItemList@@6B@_0` at `0x0061efcc`, and tertiary `??_7ServerItemMenuItemList@@6B@_1` at `0x0061effc`.
- Vtable writes occur in the inline server-dialog setup (`0x0051a6ff`, `0x0051a705`, `0x0051a70f`), raw constructor (`0x0051aedb`, `0x0051aee1`, `0x0051aeeb`), raw destructor (`0x0051af03`, `0x0051af09`, `0x0051af13`), and scalar deleting destructor (`0x00520ce6`, `0x00520cec`, `0x00520cf6`).
- Key primary vtable slots are `0x0061ef44 -> 0x00520ce0`, `0x0061efa4 -> 0x0051b2c0`, `0x0061efbc -> 0x0051b100`, `0x0061efc0 -> 0x0051b2b0`, and `0x0061efc4 -> 0x0051b3e0`; secondary/tertiary slots point to `0x00520b13` and `0x00520b1e`.
- Live call refs in the raw constructor show `ListPane` construction through `0x004f3a50` followed by fixed state storage at `+0x14c`, `+0x150`, `+0x154`, and `+0x158`. The raw row append helper calls `_wcscpy_s` twice and `0x004f3c50` to append the stack row.
- Live call refs in the two packet helpers show the selected-row path through `0x004f3dc0`, allocator `0x00516030`, byte writers around `0x00575380/0x005753f0/0x005753a0`, `WideCharToMultiByte`, send path `0x00574bb0`, and shared network context `0x0067a7ec`.
- IDA decompilation of `0x0051b100` updates owner child/control slot `7` from row text at `row + 0x208` or clears it with `word_60db20`, then delegates selection to `0x004f45b0`.
- IDA decompilation of `0x0051b2c0` handles event byte `1`/`4`, hit-tests through `0x004b7e80` and `0x004f4480`, and uses observer/global `0x0069ae04` plus allocation path `0x004c82d0` for high-resolution help behavior.
- IDA decompilation of `0x0051b3e0` branches on `byte_66da97`, draws the selected background, renders item imagery through item-image helpers, clamps/truncates the wide display name with ellipsis text, and prints the right-aligned value using the `"%10u"` format.
- IDA decompilation of `0x00520ce0` resets the three class vtables, notifies observer/global `0x0069ae04`, calls `ListPane` cleanup at `0x004f3b60`, and conditionally deletes through `0x004f4ac0`.

## Score Rationale

- `COMPLETION:86`: live evidence now covers vtable identity, inline and raw constructor writes, raw helper call targets, virtual body behavior, destructor/thunk linkage, observer usage, and exact end padding. Remaining work is row-record field naming and reconstruction-quality cleanup of raw helper declarations.
- `CONFIDENCE:86`: class ownership is strong because live vtable names and writes identify `ServerItemMenuItemList`, and parent placement under [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md) matches the inline server-dialog setup. Confidence stays below final-source level because several helpers are raw unmodeled code with no direct IDA xrefs.
- `RECONSTRUCTABLE:TRUE`: the methods are source-authored UI/list behavior, but final C++ is withheld until the 95/95 threshold is met.

## Cross-References

- [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md)
- [UID:0001Y5][MerchantMenuDialogVtableFamily](by-type/by-vtable/MerchantMenuDialogVtableFamily.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:0001BP][0x0051ae90-0x0051b87a.ServerItemMenuItemList](by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md)
- [UID:0000CZ][ServerItemMenuDialog](by-class/ServerItemMenuDialog.md)
- [UID:00002Q][ClientItemMenuItemList](by-class/ClientItemMenuItemList.md)
- [UID:000083][MerchantDialogPane](by-class/MerchantDialogPane.md)
- [UID:00007A][ListPane](by-class/ListPane.md)

## Changes

- 2026-06-04: Raised completion/confidence from `82/76` to `86/86`, marked `RECONSTRUCTABLE:TRUE`, and attached the class to [UID:0000KF][ItemMenuDialogs](by-file/ItemMenuDialogs.md). The increase is justified by fresh live IDA MCP evidence for exact function/raw-code boundaries, padding bytes, vtable names and slots, inline server-dialog setup writes, raw helper call targets, modeled virtual behavior, and destructor/thunk linkage.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `82`, confidence `76`.
- Evidence: the page documented constructor-shaped code, destructor, row append, packet helpers, activation/event/draw behavior, destructor thunks, and vtable xrefs; confidence stayed medium-high because constructor and scattered helper ownership still needed final source placement.
