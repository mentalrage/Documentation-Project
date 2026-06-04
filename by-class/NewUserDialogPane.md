*** UID:00009D | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewUserDialogPane

## Status

- Confidence: strong for account-registration behavior, vtable binding, packet flow, and lifecycle ownership; medium for final source-level field/control names.
- Likely source file: [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md), with [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md) as the broader account/login family
- Address range: [UID:0002Q3][0x004f9d30-0x004fa7a0.NewUserDialogPaneCoreAndPacketHelpers](by-memory/0x004f9d30-0x004fa7a0.NewUserDialogPaneCoreAndPacketHelpers.md), inside [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md)
- Reconstruction status: reconstructable class attached to [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md); C++ remains blank because field/control names and the cleanup-fragment source shape are still below the final 95/95 bar.

## Class Purpose

`NewUserDialogPane` is the older account-registration dialog. It collects username, password, and confirmation text, validates that the password contains a digit and matches confirmation, shows alerts for validation failures, and sends a new-user request.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `NewUserDialogPane` | `0x004f9d30-0x004fa0a9` | Builds the `DLGNEW01.EPF` registration dialog, two command controls, three account/password fields, and registers the singleton. |
| constructor cleanup fragment | `0x004fa0b0-0x004fa0ef` | Restores the three class vtables, closes the screen dimmer when present, clears the singleton, and tail-calls the inherited cleanup target. |
| packet event adapter | `0x004fa0f0-0x004fa116` | Handles packet opcode `2` from the secondary interface and forwards to the reply handler with the primary pointer adjustment. |
| command handler | `0x004fa120-0x004fa14e` | Action `1` submits; action `2` closes/dismisses the dialog. |
| focus/default updater | `0x004fa150-0x004fa1c9` | Queries child controls `1`, `3`, `4`, and `5` and toggles default/active behavior based on text presence. |
| validate and submit | `0x004fa1d0-0x004fa39c` | Reads the three fields, requires a digit in the password, checks confirmation match, shows validation alerts, creates the dimmer, and calls the request encoder. |
| request encoder | `0x004fa3a0-0x004fa5a5` | Converts the three wide strings to bounded multibyte fields, writes opcode `2`, length-prefixes the fields, enforces the `0x100` buffer cap, and sends through the packet queue. |
| reply handler | `0x004fa5b0-0x004fa773` | Routes nonzero reply codes into dialog modes/alerts, and on success closes the dialog, copies the account field to config, and opens the next account dialog. |
| singleton clear helper | `0x005023f0-0x005023fb` | Clears `dword_69B480`. |
| destructor family | `0x0050250e`, `0x00502519`, `0x00502970-0x005029e1` | Adjustor thunks and scalar deleting destructor; restores vtables, closes dimmer state, clears the singleton, and conditionally frees. |

## Evidence Notes

- Live IDA MCP on 2026-06-05 reports normal function starts at `0x004f9d30`, `0x004fa0f0`, `0x004fa120`, `0x004fa150`, `0x004fa1d0`, `0x004fa3a0`, `0x004fa5b0`, `0x005023f0`, `0x0050250e`, `0x00502519`, and `0x00502970`; `0x004fa0b0` remains an unregistered cleanup fragment with code heads.
- RTTI/vtable data names `??_7NewUserDialogPane@@6B@`, `??_7NewUserDialogPane@@6B@_0`, and `??_7NewUserDialogPane@@6B@_1` bind the primary command/default handlers and secondary packet adapter. Slots include `0x0061d334 -> 0x004fa120`, `0x0061d338 -> 0x004fa150`, `0x0061d35c -> 0x004fa0f0`, and `0x0061d2ec -> 0x00502970`.
- `dword_69B480` xrefs tie singleton setup to the constructor, cleanup clearing to the hidden fragment, the explicit clear helper at `0x005023f0`, and destructor clearing at `0x005029a2`.
- Raw-byte checks confirm the internal alignment ranges are `0xcc` padding and that the reply handler is followed by local switch/table bytes through `0x004fa793` before padding to the next `LoginDialogPane` constructor at `0x004fa7a0`.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `86` | The page now covers the constructor, cleanup fragment, packet adapter, command/default handlers, submit path, request encoder, reply handler, singleton clear helper, destructor thunks, vtable bindings, singleton xrefs, file parent, and exact memory anchor. Completion remains capped by unresolved source-level field names and the final cleanup-fragment declaration shape. |
| Confidence `90` | Confidence is backed by current live IDA function enumeration, decompilation/callee checks, RTTI/vtable slot data, singleton xrefs, and raw padding/table bytes. It remains below final reconstruction confidence because the class declaration and member names are not proven at source quality. |

## Cross-References

- [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md)
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)
- [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md)

## Changes

- 2026-06-05: Raised completion/confidence from `72/80` to `86/90` after a live IDA MCP refresh verified the full method island, hidden cleanup fragment, request/reply helpers, singleton clear helper, adjustor/deleting destructor family, exact vtable slots, singleton xrefs, and padding/table bytes. C++ remains blank because source-level member names and the cleanup-fragment declaration are still below the 95/95 reconstruction threshold.
- 2026-06-02: Raised completion/confidence from `68/64` to `72/80`, marked reconstructable, and attached to [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md). Evidence: exact NewUser core memory page records corrected boundaries, packet sender/reply helper coverage, and login-family placement.
- Before: completion/confidence metadata were `0/0` despite basic method, validation, and file/memory ownership notes.
- Changed to: `COMPLETION:68` and `CONFIDENCE:64`.
- Evidence: the page covers purpose, local method roles, destructor family, and validation behavior; confidence stays medium because the page lacks detailed layout/state-field documentation.
