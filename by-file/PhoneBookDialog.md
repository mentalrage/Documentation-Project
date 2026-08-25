*** UID:0000MJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# PhoneBookDialog

## Status

- Confidence: strong for phone-book/dial feature ownership and `NexusTK/login/` placement; medium-high for final split from `TerminalPane.cpp`.
- Proposed module: `login/PhoneBookDialog.cpp`
- Current source route: [UID:0004YD][0x0058d750-0x0058d9e2.DialDialogConstructor](by-memory/0x0058d750-0x0058d9e2.DialDialogConstructor.md), [UID:0004YE][0x0058d9f0-0x0058da1e.DialDialogOnControlCommand](by-memory/0x0058d9f0-0x0058da1e.DialDialogOnControlCommand.md), and [UID:0001JH][0x0058da20-0x0058db94.DialDialogModemResponseParser](by-memory/0x0058da20-0x0058db94.DialDialogModemResponseParser.md) supply the three exact DialDialog method bodies for generated `PhoneBookDialog.cpp`; [UID:00003R][DialDialog](by-class/DialDialog.md) supplies the class declaration for `PhoneBookDialog.h`. Compiler/data support pages explain binary shape without emitting duplicate source.
- Evidence basis: IDA MCP boundary checks, current documentation cross-references, and generated-source caveats. Generated source is used only as a hint where IDA-backed docs corroborate behavior.

## File Role

`PhoneBookDialog.cpp` owns the terminal phone book UI: persistent `PHONE.CFG` loading/saving, phone-book list rendering, add/edit entry dialog, and modem dialing dialog. The code is tightly tied to `TerminalPane` because `PhoneEntryDialog` and `DialDialog` are shown over `g_pTerminalPane`, and `DialDialog` sends modem command strings through the same packet sender path.

The most likely original placement is a sibling file near `TerminalPane.cpp`:

```text
login/PhoneBookDialog.cpp
login/PhoneBookDialog.h
```

An alternate original layout is one larger terminal source file containing both terminal setup and phone-book support.

The executable boundary from the terminal/setup aggregate is exact: `TerminalSetupPane::OnCommand` ends at `0x0058c350`, and `PhoneBookDialog::PhoneBookDialog` starts at `0x0058c350`. Keep this file as the owner of `0x0058c350+` phone-book code unless later source-layout evidence deliberately collapses the whole terminal/phone feature into one original source file.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `PhoneBookDialog` | `0x0058c350-0x0058cec7`, retained wrappers at `0x0058c9c0`, `0x0058ca70`, and `0x0058cb30` | Main phone-book dialog, `PHONE.CFG` load/save, add/edit/delete/dial/close command handling, button state updates, and retained no-direct-xref row add/replace/remove wrappers. `SavePhoneBook` should emit normal CRT-style wide formatted writes; [UID:0001JL][0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md) is runtime glue, not a source-owned PhoneBook method. |
| `PhoneBookListPane` | setup helper `0x0058ced0-0x0058cf1d`, append helper `0x0058cf20-0x0058cf9a`, [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md), raw helpers `0x0058cfe0-0x0058d10e`, activation/render `0x0058d110-0x0058d263` | Contact list pane setup, row append/replace/remove/save helpers, selected-entry extraction through `PhoneBookListPane::GetSelectedEntryData`, activation forwarding, and contact row rendering. |
| `PhoneEntryDialog` | `0x0058d270-0x0058d74c` | Modal add/edit dialog with name and number text fields. |
| `DialDialog` | [UID:0001JG][0x0058d750-0x0058dc5b.DialDialog](by-memory/0x0058d750-0x0058dc5b.DialDialog.md), children UID0004YD/UID0004YE/UID0001JH/UID0004YG/UID0001JJ/UID0004YH | Dial-in-progress dialog with exact `PhoneBookDialog.h` declaration and constructor/`OnControlCommand`/`ParseModemResponse` source children; queues reset/connect and `ATX3DT` modem sequence, then closes on control action, `CONNECT`, `BUSY`, or packets over 100 bytes. Compiler tail/adjustor/deleting-wrapper pages remain non-emitting. |
| Terminal singleton clear helper | [UID:0001JI][0x0058dbe0-0x0058dbeb.ClearTerminalPaneSingletonEH](by-memory/0x0058dbe0-0x0058dbeb.ClearTerminalPaneSingletonEH.md) | Constructor EH cleanup that clears `g_pTerminalPane`; recorded in the dial/terminal thunk island but ignored for source reconstruction. |

## Key Behavior

- `PhoneBookDialog` loads alternating name/number lines from `PHONE.CFG` into the list pane and writes the same format back through `SavePhoneBook`.
- `PHONE.CFG` persists contacts as alternating `name` and `phoneNumber` lines, with each field written through `L"%s\n"` formatted output. Reconstructed callers should write with normal CRT `fwprintf`-style calls rather than emitting the compiler/runtime wrapper body.
- `OnCommand` handles save/close, add, edit, delete, and dial actions. Add/edit constructs `PhoneEntryDialog`; dial saves and closes the phone book before constructing `DialDialog`.
- `PhoneEntryDialog` updates or inserts a `PhoneBookContactEntry` row, then refreshes the owner phone-book dialog.
- `DialDialog` converts the selected wide phone number to multibyte text and sends modem dialing commands through the packet sender.
- [UID:0001JE][0x0058c350-0x0058d74c.PhoneBookDialogs](by-memory/0x0058c350-0x0058d74c.PhoneBookDialogs.md) is a source-family aggregate, not an aggregate C++ body. Future code should emit through exact child pages for method-sized ranges.

## Evidence Notes

- IDA MCP confirms the phone-book block at `0x0058c350-0x0058d74c` and the dial block at `0x0058d750-0x0058dc5b`.
- 2026-06-12 A001 Batch 289 live IDA MCP reconfirmed the file split evidence: [UID:0003DQ][0x0062db48-0x0062dbe4.PhoneBookDialogVtableData](by-memory/0x0062db48-0x0062dbe4.PhoneBookDialogVtableData.md) is installed only by the `PhoneBookDialog` constructor, `PhoneBookListPane` begins at `0x0062dbe4`, the constructor loads `PHONE.CFG` in `rt` mode, `SavePhoneBook` writes it in `wt` mode, and the command/dial paths stay within the phone-book/dial feature before handing off to `DialDialog`.
- 2026-05-26 IDA recheck: [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md) has only one direct caller, `PhoneBookDialog::OnCommand` at `0x0058cd8c`; [UID:0001JL][0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md) is called from `SavePhoneBook` and two raw no-function save-helper call sites.
- Current emitted source is incomplete for `PhoneBookDialog::SavePhoneBook` and `PhoneBookListPane::RenderEntry`; use method summaries and IDA boundaries rather than the emitted bodies for those rows.
- Current `simroot_v2/class_PhoneBookListPane.cpp` now emits `0x0058cfa0` as `PhoneBookListPane::GetSelectedEntryData`, but `PhoneBookDialog::OnCommand` still calls it through a `ChattingColorListPane` cast and delete/list helpers through `ArticleListPane`. Treat those local types as owner pollution around shared `ListPane` helpers, not as real owners.
- 2026-06-17 B001 source-quality pass resolved the phone-book helper split: [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md) belongs directly to [UID:0000AE][PhoneBookListPane](by-class/PhoneBookListPane.md) with row type `PhoneBookContactEntry`, while [UID:0001JL][0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md) is a static MSVC/UCRT `fwprintf`-style wrapper and should remain a runtime dependency only.
- 2026-06-19 B007 source-quality pass expanded the file-level inventory with retained no-direct-xref helpers: `PhoneBookDialog::AppendPhoneBookEntry` at `0x0058c9c0-0x0058ca63`, `PhoneBookDialog::ReplaceSelectedPhoneBookEntry` at `0x0058ca70-0x0058cb2e`, `PhoneBookDialog::RemoveSelectedPhoneBookEntry` at `0x0058cb30-0x0058cb5d`, `PhoneBookListPane::Initialize` at `0x0058ced0-0x0058cf1d`, `PhoneBookListPane::AppendEntry` at `0x0058cf20-0x0058cf9a`, corrected `PhoneBookListPane::ReplaceSelectedEntryData` to half-open `0x0058cfe0-0x0058d075`, and confirmed the aggregate should stay blank while exact method children carry first-draft C++.
- 2026-06-27 B001 source-quality pass resolved the `DialDialog` parser child [UID:0001JH][0x0058da20-0x0058db94.DialDialogModemResponseParser](by-memory/0x0058da20-0x0058db94.DialDialogModemResponseParser.md) for this file route: current MCP session `b001_000241_20260627` confirms the `0x0062ddb4` vtable slot, packet fields at `+0x0c/+0x10`, parser state at adjusted/full offsets `+0x24c/+0x2ec`, and close callees that map to inherited `SlideCloseVertical()`/`CloseDialog()`. The file score is unchanged because this update resolves a child method, not the broader phone-book source-file split.

## Cross-References

- [UID:0000AD][PhoneBookDialog](by-class/PhoneBookDialog.md)
- [UID:0000AE][PhoneBookListPane](by-class/PhoneBookListPane.md)
- [UID:0000AF][PhoneEntryDialog](by-class/PhoneEntryDialog.md)
- [UID:00003R][DialDialog](by-class/DialDialog.md)
- [UID:0000V7][PhoneBookListHelpers_58cfa0_58dcb0](by-item/PhoneBookListHelpers_58cfa0_58dcb0.md)
- [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md)
- [UID:0001JL][0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md)
- [UID:0001JH][0x0058da20-0x0058db94.DialDialogModemResponseParser](by-memory/0x0058da20-0x0058db94.DialDialogModemResponseParser.md)
- [UID:0000SF][g_pTerminalPane](by-global/g_pTerminalPane.md)
- [UID:0001JE][0x0058c350-0x0058d74c.PhoneBookDialogs](by-memory/0x0058c350-0x0058d74c.PhoneBookDialogs.md)
- [UID:0003DQ][0x0062db48-0x0062dbe4.PhoneBookDialogVtableData](by-memory/0x0062db48-0x0062dbe4.PhoneBookDialogVtableData.md)
- [UID:0001JG][0x0058d750-0x0058dc5b.DialDialog](by-memory/0x0058d750-0x0058dc5b.DialDialog.md)
- [UID:0000OI][TerminalPane](by-file/TerminalPane.md)

## B006 DialDialog Header/Source Routing - 2026-07-29

The highest-probability original split is the shared pair `NexusTK/login/PhoneBookDialog.h` and `NexusTK/login/PhoneBookDialog.cpp`. The header owns [UID:00003R][DialDialog](by-class/DialDialog.md), a direct `DialogPane`-derived `0x2f0` declaration with `m_phoneNumber[64]` at `+0x26c`, `m_modemResponseState` at `+0x2ec`, constructor, primary `OnControlCommand(int,int)`, and EventHandler-view `ParseModemResponse(SocketPacket *)`. The source owns exact method children [UID:0004YD][0x0058d750-0x0058d9e2.DialDialogConstructor](by-memory/0x0058d750-0x0058d9e2.DialDialogConstructor.md), [UID:0004YE][0x0058d9f0-0x0058da1e.DialDialogOnControlCommand](by-memory/0x0058d9f0-0x0058da1e.DialDialogOnControlCommand.md), and [UID:0001JH][0x0058da20-0x0058db94.DialDialogModemResponseParser](by-memory/0x0058da20-0x0058db94.DialDialogModemResponseParser.md).

The non-emitting [UID:0001JG][0x0058d750-0x0058dc5b.DialDialog](by-memory/0x0058d750-0x0058dc5b.DialDialog.md) split index preserves the complete executable island. [UID:0004YG][0x0058db95-0x0058dbdf.DialDialogParserTailAndRetainedCloseWrappers](by-memory/0x0058db95-0x0058dbdf.DialDialogParserTailAndRetainedCloseWrappers.md) covers parser NOP/switch support and two exhausted-route close-wrapper copies; [UID:0001JI][0x0058dbe0-0x0058dbeb.ClearTerminalPaneSingletonEH](by-memory/0x0058dbe0-0x0058dbeb.ClearTerminalPaneSingletonEH.md) and [UID:0001JK][0x0058dc01-0x0058dc17.TerminalPaneAdjustorThunks](by-memory/0x0058dc01-0x0058dc17.TerminalPaneAdjustorThunks.md) remain TerminalPane compiler support; [UID:0001JJ][0x0058dbeb-0x0058dc01.DialDialogAdjustorThunks](by-memory/0x0058dbeb-0x0058dc01.DialDialogAdjustorThunks.md) and [UID:0004YH][0x0058dc20-0x0058dc5a.DialDialogScalarDeletingDestructor](by-memory/0x0058dc20-0x0058dc5a.DialDialogScalarDeletingDestructor.md) are DialDialog compiler deleting machinery. Vtable/RTTI [UID:0003DT][0x0062dd44-0x0062dddc.DialDialogVtableData](by-memory/0x0062dd44-0x0062dddc.DialDialogVtableData.md) and literal [UID:0003GX][0x0062df4c-0x0062df90.DialDialogResourceAndModemStrings](by-memory/0x0062df4c-0x0062df90.DialDialogResourceAndModemStrings.md) pages are class/method source-cause evidence and do not create handwritten arrays or globals.

Dialing receives the selected phone number from sole caller `PhoneBookDialog::DialSelectedEntry` (current IDA `sub_58CB60`), constructs the dialog over `g_pTerminalPane`, copies/converts at most 63 wide characters, queues reset, mode-dependent connect using startup mode and terminal baud, then `ATX3DT`, number, and LF/CR. The primary control callback queues CR and closes; the parser tracks `CONNECT`/`BUSY` state and closes on terminal response or length above 100.

Historical placement of the entire feature in a larger `TerminalPane.cpp` remains recorded as a lower-ranked alternative because the classes interact closely. It is superseded for current routing by contiguous phone-book ownership, existing project structure, and the complete child/header split; it is not deleted from history.

Score `90/92` reflects complete DialDialog header/source routing and child inventory while preserving the broader phone-book behaviors already documented. It remains below final audit because the exact historical translation-unit split cannot be proven from symbols.

## B006 DialDialog Applied IDA State - 2026-07-29

Supervisor catalog entry `0364` applied and verified the DialDialog source-quality recommendations in MCP database `1da2b2ae`, then saved `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` at SHA256 `905D1AB131C953911CD1DF5E536AF36EAECFA67486E2F800907B36C0673604C1`, 143,190,814 bytes, last write `2026-07-29T14:42:53.5091352-04:00`. The previous `296ED21C6665B7C0D8EFBC515B137101F8506FD945C6C7E14C3E6F655063CF8B` image is a dated pre-mutation checkpoint and has a byte-identical backup at `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B006-UID0001JG-20260729-1441.i64`.

A bounded read-only no-drift check through the same MCP database against current authoritative saved IDB SHA256 `412DA7E81557538D283BBFBC18875CACC6C1DBBC662E88BEC71307E0AE0519CD`, 143,191,140 bytes, saved `2026-07-29T15:00:32.0998001-04:00`, reconfirmed every DialDialog UDT, function, measured frame, comment, compiler-support, and protected RTTI/vtable state. The `905D1AB1...604C1` identity remains the application checkpoint, not the latest shared-IDB identity.

- The analysis UDT `SocketPacket` is exact size `0x14`: opaque bytes `[+0,+0x0c)`, `char *m_data` at `+0x0c`, and `int m_length` at `+0x10`. `DialDialog` is exact size `0x2f0`: unchanged `DialogPane` base at `+0`, `wchar_t m_phoneNumber[64]` at `+0x26c`, and `int m_modemResponseState` at `+0x2ec`.
- The three handwritten methods are now source-facing and typed as `DialDialog::DialDialog(const wchar_t *phoneNumber)` at `0x0058d750`, `void DialDialog::OnControlCommand(int controlIndex, int notifyCode)` at `0x0058d9f0`, and the adjusted EventHandler-view `char DialDialog::ParseModemResponse(SocketPacket *packet)` at `0x0058da20`. Their exact function-repeatable comments document constructor command order, command-1 close behavior, and `CONNECT`/`BUSY` parser behavior.
- Prototype-driven frame readback is measured rather than predicted: the constructor retains every nonargument entry and exposes `phoneNumber +0x94` as `const wchar_t *` while raw `arg_4 +0x98` remains; `OnControlCommand` exposes `controlIndex +0x0c` and `notifyCode +0x10` as `int`; the parser exposes `packet +0x14` as `SocketPacket *`.
- Compiler support is descriptive but remains non-emitting: `ClearTerminalPaneSingletonOnConstructorUnwind`, the two `DialDialog_ScalarDeletingDestructor_AdjustA0/A4` adjustors, and `DialDialog_ScalarDeletingDestructor` have exact source-facing analysis names/types/comments. Both DialDialog adjustors expose `deletingFlags +0x4 unsigned int`; the scalar wrapper exposes `deletingFlags +0x0c unsigned int`. The two retained close wrappers stay unmodeled one-byte heads with exact regular comments, and the parser jump table retains its exact ten-target extent with the accepted repeatable comment.
- The protected TerminalPane adjustors, all three DialDialog COL/vtable views, three COLs, CHD, seven-entry base-class array, self BCD/PMD, and TypeDescriptor retain their exact compiler identities, values, bytes, comments, and no-source disposition. The inline UTF-16 dialing text is now identified as `DialDialog_DialingThePhoneText` with its exact type/units and explanatory repeatable comment, but remains an inline source literal rather than a standalone source variable.
- Validator command `000000019511` inserted the registered [UID:0003GX][0x0062df4c-0x0062df90.DialDialogResourceAndModemStrings](by-memory/0x0062df4c-0x0062df90.DialDialogResourceAndModemStrings.md) link into this file-level source-family inventory. The command-owned link is preserved here; its page supplies resource/literal evidence without changing the exact handwritten CPP/H emitter route.

## Changes

- 2026-07-29 B006 UID0001JG callback: raised `88/88 -> 90/92`, expanded the DialDialog component into exact class/header and method-source children, documented compiler/data exclusions and serial-connect behavior, and preserved the larger TerminalPane.cpp hypothesis as lower-ranked history.
- 2026-07-29 B006 UID0001JG post-Gate2B reconciliation: preserved validator command `000000019511`'s UID0003GX link and documented catalog entry `0364`, exact applied UDT/function/comment state, measured argument-frame presentation, protected compiler entities, and saved-IDB checkpoint without changing file ownership, score, or emitter topology.

- 2026-06-27 B001 parser implementation callback: kept `88/88`, updated the `DialDialog` component row for implementation-ready `ParseModemResponse(SocketPacket *packet)`, and replaced stale generated-output wording so [UID:0001JH][0x0058da20-0x0058db94.DialDialogModemResponseParser](by-memory/0x0058da20-0x0058db94.DialDialogModemResponseParser.md) is no longer treated as an empty generated marker for `PhoneBookDialog.cpp`.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `86`, confidence `80`.
- Summary/evidence: the page documents phone-book/dial feature ownership, class grouping, behavior, IDA boundary evidence, current generated-source caveats, TerminalPane relationship, and cross-references; confidence remains capped by final split from `TerminalPane.cpp`.
- 2026-06-01: `PROPOSED_RECONSTRUCTION_PATH` changed from blank to `NexusTK/login/`.
  - Summary/evidence: the page already proposed `login/PhoneBookDialog.cpp`; [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) places `PhoneBookDialog.cpp` in the login family; sibling pre-login dialog files use the same projected path.
- 2026-06-12 Agent-A001 Batch 289: Raised `86/80 -> 87/86` after live IDA reconfirmed the `PhoneBookDialog` vtable child, constructor `PHONE.CFG` load, save/dial command paths, exact successor boundary before `PhoneBookListPane`, and existing proposed-source-tree placement under `NexusTK/login/`. The file now clears the strict parent gate for [UID:0000AD][PhoneBookDialog](by-class/PhoneBookDialog.md).
- 2026-06-17 B001 source-quality execution: updated helper ownership to show [UID:0001JF][0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper](by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md) as direct `PhoneBookListPane` source and [UID:0001JL][0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md) as runtime/CRT formatted-output glue. The file still owns the `PhoneBookDialog.cpp` source family; generated `ChattingColorListPane`/`ArticleListPane` casts remain documented as owner pollution.
- 2026-06-21 B006 TerminalPane boundary sync: reinforced `0x0058c350` as the exact successor boundary after [UID:0001JB][0x0058af50-0x0058c350.TerminalPaneAndSetup](by-memory/0x0058af50-0x0058c350.TerminalPaneAndSetup.md). Score unchanged.
- 2026-06-21 B007 Rule 26 incorporation: raised `87/86 -> 88/88`, added retained dialog/list helper inventory, replaced stale generated-source wording with the current empty-marker caveat, documented alternating `PHONE.CFG` name/number save format, and kept [UID:0001JL][0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper](by-memory/0x0058dcb0-0x0058dcd3.PhoneBookFormattedWriteHelper.md) as no-code CRT/runtime glue.
