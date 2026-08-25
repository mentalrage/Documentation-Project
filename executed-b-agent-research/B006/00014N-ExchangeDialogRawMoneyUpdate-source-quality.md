** TARGET-REPORT-UID:00014N **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B006 Source-Quality Report: [UID:00014N] ExchangeDialogRawMoneyUpdate

Target assigned: `by-memory/0x004adca0-0x004add33.ExchangeDialogRawMoneyUpdate.md`

Report-only pass scope honored before supervisor callback: no by-* docs, generated files, project-level generated files, validator/tool state, IDA DB, `by-memory/-coverage-report.md`, or any `-coverage-report.md` were edited during the research/rework pass, and no leases were taken then. The checked implementation proof at the end records the later accepted callback edits, validator side effects, and lease activity.

## Executive Recommendation

[UID:00014N] is real reconstructable NexusTK `ExchangeDialog` source behavior, but the current page still has three source-quality defects:

- It is routed through the broad file owner [UID:0000J9][ExchangeDialog](../../../../../by-file/ExchangeDialog.md), while the body is a `thiscall` `ExchangeDialog` method/helper using `ecx` as the primary `ExchangeDialog` receiver and matching the class-owned sibling retained helpers [UID:00014M], [UID:00014O], and [UID:00014P].
- Its filename/end metadata are one byte short under the project half-open range convention. Current MCP bytes show the `retn 4` instruction starts at `0x004add31` and uses bytes through `0x004add33`; alignment starts at `0x004add34`. The correct exact range is `0x004adca0-0x004add34`.
- Its formal C++ disposition must be a formal covered-by comment marker, not a blank block and not a standalone helper body. Current IDA and route scans still prove no direct route to the raw helper start, while the live routed dispatcher [UID:00014L] already emits equivalent opcode `0x42` subcommand `3` logic inline.

Recommended implementation:

- Rename the target file to `by-memory/0x004adca0-0x004add34.ExchangeDialogRawMoneyUpdate.md` while preserving UID `00014N`.
- Set metadata to `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00004R`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004R`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0`.
- Replace the formal `RECONSTRUCTION_CPP CODE` marker/block with the exact formal block in the "Formal C++ Disposition" section below. It contains only a covered-by comment marker naming [UID:00014L] `by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md` case `3`; do not insert a standalone helper body.
- Update support docs to preserve the behavior, route-negative evidence, corrected half-open end, and class-owner reasoning at report-level detail.

## Current Documentation State

The target is currently `85/88`, reconstructable, owner/emitter `[UID:0000J9]`, and has blank formal C++. It documents the important behavior correctly: `packet+2` side byte, big-endian amount at `packet+3`, control `6` for local money, control `9` for remote money, `SetExchangeAmount(0)` when a local zero amount arrives, `%u` formatting through the wide formatter, text write through the control setter, and duplicate dispatcher subcommand `3`.

The remaining low-score blockers are not future work; they are now resolved as follows:

- Direct owner is [UID:00004R][ExchangeDialog](../../../../../by-class/ExchangeDialog.md), not the broad source file. The file [UID:0000J9] remains the source-file route only.
- Current exact range should be half-open `0x004adca0-0x004add34`, not `0x004adca0-0x004add33`.
- First-draft C++ is intentionally not inserted because this range is a no-route retained duplicate of the live dispatcher case, not because the body cannot be understood.

## Local Docs Checked

- Target: `by-memory/0x004adca0-0x004add33.ExchangeDialogRawMoneyUpdate.md`.
- Owner/source route: `by-class/ExchangeDialog.md`, `by-file/ExchangeDialog.md`, and aggregate `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`.
- Live routed dispatcher: `by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md`.
- Sibling retained helpers: `by-memory/0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper.md`, `by-memory/0x004add40-0x004ade5e.ExchangeDialogCancelAlertHelper.md`, and `by-memory/0x004ade60-0x004adfab.ExchangeDialogReadyAlertHelper.md`.
- Vtable evidence: `by-memory/0x00619d28-0x00619dc4.ExchangeDialogVtableData.md`.
- Control-role cross-check: `by-class/ExchangeMoneyEditControlPane.md`.
- Accepted prior research: `executed-b-agent-research/B015/00014L-ExchangeDialogPacketDispatcher-source-quality.md` plus sibling accepted B002/B003 reports where they establish the retained-helper/no-route family policy.

## Current IDA MCP Evidence

MCP was available and responsive. Successful current calls used JSON-RPC against `http://127.0.0.1:13337/mcp` with explicit `database:80de0a67`, because the active server schema requires a database/session argument.

Session and health:

- `initialize` returned `ida-pro-mcp` version `1.0.0`, protocol `2025-06-18`.
- `tools/list` returned 65 tools.
- `idb_list` reported active session `80de0a67`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, created `2026-06-24T06:15:52.461765`, last accessed during this report, active worker PID `26892`.
- `server_health(database=80de0a67)` returned status `ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, cache size `2067`.
- 2026-06-26 targeted report rework rechecked MCP availability before revising the emitter disposition: `idb_list` still reported active session `80de0a67`, `server_health(database=80de0a67)` returned status `ok`, `lookup_funcs` still reported [UID:00014L] `0x004ad320` as `sub_4AD320` size `0x493` while `0x004adca0` and `0x004add34` were not functions, `xrefs_to 0x004adca0` still returned zero references, and `xrefs_to 0x004ad320` still returned the dispatcher vtable data xref at `0x00619d9c`.

Function table and xrefs:

- `lookup_funcs` reports `0x004ad320` as `sub_4AD320`, size `0x493`; addresses `0x004ad531` and `0x004ad59e` are inside that same dispatcher.
- `lookup_funcs` reports `0x004adca0`, `0x004add31`, `0x004add33`, and `0x004add34` are not functions.
- `lookup_funcs` reports the next modeled helper `0x004add40` as `sub_4ADD40`, size `0x11f`.
- `lookup_funcs` reports callees used by the raw body: `0x004ada20` as `sub_4ADA20`, size `0x64`; `0x0041b9b0` as `sub_41B9B0`, size `0x2e`; `0x00498ca0` as `sub_498CA0`, size `0x41`; `0x005754c0` as `sub_5754C0`, size `0x26`.
- `xrefs_to 0x004adca0` reports zero cross-references.
- `xrefs_to 0x004ad320` reports one data xref at `0x00619d9c`, the ExchangeDialog vtable slot, so the live dispatcher is routed and the raw helper is not.

Raw helper body:

- `insn_query` over `0x004adca0-0x004add40` returned 58 instructions with no containing IDA function.
- The body starts at `0x004adca0` with a normal stack/security-cookie prologue, loads the packet pointer from `[ebp+8]`, and moves `ecx` into `edi`, confirming a primary `ExchangeDialog` `this` receiver.
- `0x004adcb8-0x004adcbc` reads `packet+2` through `std::_Narrow_char_traits<char,int>::to_char_type`, producing the side byte.
- `0x004adcc1-0x004adcc7` calls `sub_5754C0(packet+3)`, confirming the big-endian amount dword at `packet+3`.
- If side is nonzero, the body reads the control collection at `[edi+0x1fc]`, pushes control id `9`, and performs the virtual lookup/call through `[vtable+0x10]`.
- If side is zero, it tests the amount; a zero amount calls `sub_4ADA20` with `ecx=edi` and argument zero, then selects control id `6` from `[edi+0x1fc]`.
- The selected control's vtable is loaded, the amount is formatted with wide `"%u"` using buffer count `0x20`, and `sub_498CA0` writes the wide text.
- The epilogue validates the security cookie and returns with `retn 4` at `0x004add31`.

Boundary and bytes:

- `get_bytes` at `0x004adca0` starts `55 8b ec 83 ec 48 ...`, matching the prologue.
- `get_bytes` at `0x004add31` returns `c2 04 00 cc cc ...`; the `retn 4` instruction uses `0x004add31-0x004add33`, and `0x004add34` is the first `0xcc` alignment byte.
- Therefore the current filename ending at `0x004add33` is stale under the half-open convention. The correct exclusive end is `0x004add34`. The observed byte body length is `0x94` / 148 bytes (Verified with int_convert.py).

Dispatcher duplicate:

- `insn_query` over `0x004ad530-0x004ad5a0` returned the live dispatcher case `3` body inside `sub_4AD320`.
- That block reads the same side byte from `packet+2`, reads the same amount dword from `packet+3`, selects remote control `9` or local control `6`, calls `sub_4ADA20(..., 0)` when the local amount is zero, formats through `sub_41B9B0` with count `0x20`, writes through `sub_498CA0`, sets success, and jumps to the dispatcher epilogue.
- `decompile 0x004ad320` cross-checks the same case: secondary-view receiver adjustment `this - 160`, control holder offset `+508`, side read at `v3+2`, amount read at `v3+3`, local-zero `sub_4ADA20`, `%u` formatting into `wchar_t Buffer[32]`, and final text write through `sub_498CA0`.

Route-negative scans:

- Current `find_bytes` found zero matches for absolute start pointer `a0 dc 4a 00`, RVA start pointer `a0 dc 0a 00`, and end/alignment pointers `31 dd 4a 00`, `33 dd 4a 00`, `34 dd 4a 00`.
- Accepted B015 dispatcher research already found no rel32 branch target, VA dword, RVA dword, or end-pointer route to `0x004adca0`. The current IDA xref and pointer checks preserve that conclusion.

Numeric conversions:

- Conversion batch used for inherited values: `'["0x93","0x20","0x42","0x4A","0x1fc","0x493","0x11f","0x64","0x2e","0x41","0x26","0x274","0xa0"]' | python tools\int_convert.py --pretty`.
- Additional range/end batch: `'["0x94","0x93","0x004add34","0x004add33"]' | python tools\int_convert.py --pretty`.
- Recorded conversions include `0x94` / 148 bytes for the true raw body through exclusive end `0x004add34`, old stale `0x93` / 147, `0x20` / 32 for the wide buffer count, `0x42` / 66 server exchange opcode, `0x4A` / 74 outgoing exchange opcode family, `0x1fc` / 508 control-holder offset, `0x493` / 1171 dispatcher size, and `0xa0` / 160 secondary-view adjustment (all Verified with int_convert.py).

## Ownership And Source-Placement Reanalysis

Direct semantic owner should be [UID:00004R][ExchangeDialog](../../../../../by-class/ExchangeDialog.md).

Evidence:

- The raw body is a `thiscall` receiver body. It copies `ecx` into `edi` and uses `[edi+0x1fc]` for control access, exactly matching `ExchangeDialog` control state.
- The zero-local-money path calls `0x004ada20`, already documented as `ExchangeDialog::SetExchangeAmount`.
- The behavior is one server-packet subcommand inside the `ExchangeDialog` packet model, not a free file helper or an `ExchangeMoneyEditControlPane` method. The money edit control is only the local control target id `6`; the raw body itself selects controls through the owning dialog.
- Sibling retained exchange helpers [UID:00014M], [UID:00014O], and [UID:00014P] are already class-owned/emitted through [UID:00004R] while remaining blank no-route duplicates. Keeping [UID:00014N] file-owned is now an inconsistent stale route.
- The live dispatcher [UID:00014L] is [UID:00004R]-owned and vtable-routed at `0x00619d9c`; the raw duplicate should share that owner even though it must not share the emitted code.

Rejected alternatives:

- Keep owner/emitter `[UID:0000J9]`: too broad. The source file route is correct as the output module, but it is not the direct semantic owner under current `CANONICAL_OWNER` rules.
- Attach to `ExchangeMoneyEditControlPane`: rejected because the raw body's `this` is `ExchangeDialog`; the money control is obtained by id `6` from `[this+0x1fc]` and is not the receiver.
- Attach to dispatcher [UID:00014L] as owner: rejected because [UID:00014L] is the live routed method, not a parent object; both pages should attach to the class owner, with docs explaining that the raw body is a duplicate of dispatcher case `3`.
- Mark non-reconstructable/no-owner: rejected because the bytes are custom NexusTK UI/protocol behavior, not compiler/runtime glue, and the class owner is strong.

## Source-Facing Name Decision

Best documentation name remains page-level `ExchangeDialogRawMoneyUpdate` with method-role wording `UpdateMoneyFromPacketRaw`.

Reasoning:

- `UpdateMoneyFromPacketRaw` is already used on `by-class/ExchangeDialog.md`; keeping it avoids implying that the no-route raw body is the definitive original called method.
- The plausible source-facing role is `ExchangeDialog::UpdateMoneyFromPacket(const unsigned char *packet)` or equivalent, but no direct caller, symbol, vtable slot, table route, or decompiler source name proves the original spelling.
- Final emitted source should keep the live dispatcher case inline. [UID:00014N] should not emit a helper body; its formal block should emit only the current covered-by comment marker. If later source integration proves that the original dispatcher called a private helper, the marker can be replaced with a real helper body then without changing packet semantics.

## Split And Range Decision

The target should be renamed from:

- `by-memory/0x004adca0-0x004add33.ExchangeDialogRawMoneyUpdate.md`

to:

- `by-memory/0x004adca0-0x004add34.ExchangeDialogRawMoneyUpdate.md`

This is not a new split and does not require a new UID. It is the same [UID:00014N] item with a corrected exclusive end. The current range text that says `0x93` / 147 bytes through exclusive end `0x004add33` is now proven stale. The correct statement is: the raw body begins at `0x004adca0`, the `retn 4` bytes are `0x004add31-0x004add33`, the exclusive end is `0x004add34`, the body length is `0x94` / 148 bytes (Verified with int_convert.py), and `0x004add34-0x004add40` is alignment before [UID:00014O] at `0x004add40`.

Do not create an additional padding page in this pass. The existing parent aggregate can record the alignment span; the target rename plus boundary note is enough.

## Formal C++ Disposition

Formal `RECONSTRUCTION_CPP CODE` for [UID:00014N] must be nonblank because the target remains `RECONSTRUCTABLE:TRUE`, has confirmed `EMITTER_UIDS:00004R`, and clears the active combined score/emitter gate. The correct emitted content is not a helper body; it is a minimal covered-by comment marker identifying the live emitted behavior on [UID:00014L].

Exact formal block to insert into the target header/block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for this retained raw duplicate is covered by [UID:00014L] by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md case 3.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

This is the current implementation disposition, not a deferred retained-clone-policy question:

- Current MCP proves the raw body and its exact behavior.
- Current MCP proves no IDA function object and no xrefs to `0x004adca0`.
- Current pointer scans find no absolute/RVA/start/end route to the raw helper.
- Accepted B015 route scans found no rel32 branch target or pointer route to the retained helper starts in this family.
- The live vtable-routed dispatcher [UID:00014L] already has first-draft inline source for opcode `0x42` subcommand `3`.
- Emitting [UID:00014N] as a separate method body now would duplicate live dispatcher behavior and falsely imply a route or source call shape not present in the current binary evidence.
- Supervisor rule 28 now controls this special code-emitter case: because [UID:00014N] remains an emitting target that will not emit a body, the formal block should contain a `//` marker naming the exact covering page instead of staying blank.

Rejected disposition alternatives:

- Blank formal block with nonblank `EMITTER_UIDS`: rejected by the current supervisor correction and by the skill done criteria for eligible emitting targets.
- Clear `EMITTER_UIDS` while keeping the page reconstructable: rejected because the target has a valid class emitter route [UID:00004R], and the current project wants special non-body emitters to identify their covering source rather than disappear from generated tracking.
- Emit standalone helper C++: rejected because no direct route reaches `0x004adca0`, while [UID:00014L] case `3` already emits the live behavior inline.

## Metadata And Score Recommendation

Recommended target metadata after implementation:

- `COMPLETION:88`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:00004R`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00004R`
- blank `EMITTER_POSITION_OPTIONAL`
- `Nested:0`

Recommended `Item Summary` text:

ExchangeDialog retained raw money-update duplicate for server opcode `0x42` subcommand `3`; current MCP confirms no function object/xrefs, side byte `packet+2`, amount dword `packet+3`, controls `6`/`9`, zero local `SetExchangeAmount(0)`, 32-WCHAR `%u` text update, live dispatcher duplicate, and corrected exclusive end at `0x004add34`.

Score rationale:

- Completion rises from `85` to `88` because the report resolves the stale direct owner, fixes the end-range/length contradiction, records current MCP session facts, preserves the exact packet/control/formatting behavior, and gives an implementation-ready covered-by formal block instead of a blank emitter block.
- Confidence rises from `88` to `91` because current MCP confirms the raw instructions, bytes, lookup results, xrefs, live dispatcher duplicate, vtable route for dispatcher, and route-negative pointer patterns. It stays below final-audit range because the original helper name/call shape is not proven.
- It should not rise higher until a future evidence pass proves the original source actually called a private helper from the dispatcher instead of inlining the case body. Current implementation no longer defers the emitter disposition: [UID:00014N] emits the covered-by comment marker above.

## Support-Doc Decisions

Required support edits if accepted:

- `by-class/ExchangeDialog.md`: update the `UpdateMoneyFromPacketRaw` row and remaining caveat text to state [UID:00014N] is class-owned [UID:00004R], has corrected exclusive end `0x004add34`, emits only the formal covered-by marker naming [UID:00014L] case `3`, has no standalone helper body/no direct route, and duplicates live dispatcher subcommand `3` at report-level detail. No class score change recommended.
- `by-file/ExchangeDialog.md`: update the packet/control model and boundary note that currently says the raw helper ends at `0x004add33`; it should say final byte at `0x004add33`, exclusive end `0x004add34`, direct owner [UID:00004R], source-file route [UID:0000J9], formal covered-by marker naming [UID:00014L] case `3`, and no standalone helper body/no-route duplicate status. No file score change recommended.
- `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`: update the child row, boundary notes, cross-reference link, and changes/history so [UID:00014N] points to the renamed `0x004adca0-0x004add34` page, records the corrected body length/end, class-owner repair, current MCP evidence, covered-by formal marker, and no standalone helper body policy. No aggregate score change recommended.
- `by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md`: update references to [UID:00014N] so links point to the renamed `0x004adca0-0x004add34` path and preserve the existing inline dispatcher C++ as the covering emitted behavior for retained duplicate [UID:00014N]. No dispatcher score or C++ change recommended.

Explicit no-edit decisions unless implementation finds a contradiction:

- `by-class/ExchangeMoneyEditControlPane.md`: no edit required. It already documents control id `6` and local money edit ownership; [UID:00014N] is an `ExchangeDialog` packet helper, not a money-control method.
- `by-memory/0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper.md`, `by-memory/0x004add40-0x004ade5e.ExchangeDialogCancelAlertHelper.md`, and `by-memory/0x004ade60-0x004adfab.ExchangeDialogReadyAlertHelper.md`: no edit required unless implementation finds stale text directly asserting [UID:00014N] remains file-owned, has the old exclusive end, or must keep a blank formal block. Do not change those sibling pages' own dispositions during this [UID:00014N] callback unless the supervisor separately accepts a family-wide retained-helper policy update.
- `by-memory/0x00619d28-0x00619dc4.ExchangeDialogVtableData.md`: no edit required. It already routes ExchangeDialog vtable data through [UID:00004R] and the dispatcher vtable xref is already recorded elsewhere.
- `by-global/g_packetSender.md`: no edit required. This server-side display update does not build or send a packet.
- `by-memory/-coverage-report.md`, `auto-generated/*`, project-level generated reports, validator state/cache, and IDA DB: no manual edit. Validator-generated coverage/research tracker refresh is expected only after source by-* edits are validated and the supervisor executes the report.

## Exact Validator Commands For Accepted Edits

Run from `E:\NTK\GhidraBridge\source-3\project-documentation`.

Required after target rename/update:

- `python .\tools\validator.py --mode file --file by-memory\0x004adca0-0x004add34.ExchangeDialogRawMoneyUpdate.md --apply --queue-timeout 240`

Required after support edits:

- `python .\tools\validator.py --mode file --file by-class\ExchangeDialog.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-file\ExchangeDialog.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory\0x004ac8a0-0x004ae4b6.ExchangeDialog.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory\0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md --apply --queue-timeout 240`

Conditional validators only if those files are actually edited due implementation-discovered contradictions:

- `python .\tools\validator.py --mode file --file by-class\ExchangeMoneyEditControlPane.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory\0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory\0x004add40-0x004ade5e.ExchangeDialogCancelAlertHelper.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory\0x004ade60-0x004adfab.ExchangeDialogReadyAlertHelper.md --apply --queue-timeout 240`

If the renamed target validator reports a stale old-path registry problem, do not edit `tools/validator.ini` manually. Use the documented validator lifecycle behavior or ask the supervisor for the appropriate cleanup command.

## Implementation Tracking Checklist

- [x] Rename [UID:00014N] from `by-memory/0x004adca0-0x004add33.ExchangeDialogRawMoneyUpdate.md` to `by-memory/0x004adca0-0x004add34.ExchangeDialogRawMoneyUpdate.md`, preserving UID `00014N`.
  - Proof: file was moved with UID `00014N` intact. Validator command `python .\tools\validator.py --mode file --file by-memory\0x004adca0-0x004add34.ExchangeDialogRawMoneyUpdate.md --apply --queue-timeout 240` returned `command_id:000000002668`, `command_timestamp:2026-06-26T14:31:44-04:00`, exit code `0`, `ok:1`, and `path_update 00014N ... was by-memory/0x004adca0-0x004add33.ExchangeDialogRawMoneyUpdate.md`.
- [x] Update the target header to `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00004R`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004R`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0`.
  - Proof: target header now has `88/91`, owner/emitter `00004R`, reconstructable true, blank emitter position, and `Nested:0`. Validator `000000002668` recorded `completion_update 88`, `confidence_update 91`, `canonical_owner_update 00004R`, and autogen registry updates.
- [x] Replace the target formal `RECONSTRUCTION_CPP CODE` marker/block with the exact formal marker/block content from this report's "Formal C++ Disposition" section, including the `[[[]]]` marker line, `BEGIN`, the single covered-by comment naming [UID:00014L] `by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md` case `3`, and `END`; do not insert a standalone helper body.
  - Proof: target formal block contains the exact single comment `// Emitted code for this retained raw duplicate is covered by [UID:00014L] by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md case 3.` and no helper body. The exact validator command `000000002668` initially passed but auto-linked `[UID:00014L]` inside the formal comment; B006 restored the accepted exact comment and ran target UID-only validation `python .\tools\validator.py --mode file --file by-memory\0x004adca0-0x004add34.ExchangeDialogRawMoneyUpdate.md --uid-only --apply --queue-timeout 240`, `command_id:000000002681`, `command_timestamp:2026-06-26T14:34:07-04:00`, exit code `0`, `ok:1`, `generated_refresh: skipped` because `--uid-only`. This extra check avoided re-running the reference phase that rewrites formal-code UID text.
- [x] Replace the target `Item Summary` with the exact recommended text above, and update advanced-scan identity/title/range prose so `0x004add34` is the exclusive end while `0x004add33` is the final byte of `retn 4`.
  - Proof: target `Item Summary`, advanced-scan identity, title, boundary notes, 2026-06-15 historical correction, and B006 change entry now use exclusive end `0x004add34`, final byte `0x004add33`, and body length `0x94` / 148 bytes.
- [x] Incorporate current MCP evidence into the target: session `80de0a67`, health facts, lookup results, raw 58-instruction body, receiver/control flow, `packet+2` side, `packet+3` amount, control ids `6`/`9`, `SetExchangeAmount(0)` zero-local path, `%u`/32-WCHAR formatting, `sub_498CA0` write, `retn 4` bytes, alignment start, dispatcher case `3` duplicate, vtable xref `0x00619d9c` for dispatcher, zero raw-start xrefs, zero pointer-pattern route hits, and int_convert commands/results.
  - Proof: target section `2026-06-26 B006 Source-Quality Recheck And Disposition` records MCP session `80de0a67`, `server_health` facts, `lookup_funcs`/`xrefs_to` results, raw body details, dispatcher duplicate, pointer scans, `0x00619d9c`, and both `int_convert.py` command batches.
- [x] Incorporate owner/emitter reasoning into the target: direct class owner [UID:00004R], source file route [UID:0000J9], rejected file-only owner, rejected `ExchangeMoneyEditControlPane` owner, rejected dispatcher-as-owner, rejected no-owner/non-reconstructable, and sibling retained-helper consistency.
  - Proof: target status and B006 section record [UID:00004R] direct owner/emitter, [UID:0000J9] source-file route, thiscall/control evidence, and rejected owner alternatives.
- [x] Incorporate the covered-by/no-body proof into the target: behavior is understood, but standalone formal C++ would duplicate live dispatcher [UID:00014L] and falsely imply a route; current Rule 28 disposition is the formal covered-by comment marker, not a blank emitter block.
  - Proof: target status, B006 section, score rationale, and formal block state the no-route duplicate proof and marker-only disposition.
- [x] Update the target `## Changes` entry for the B006 implementation: before `85/88`, owner/emitter [UID:0000J9], stale `0x93`/exclusive-end wording, and blank formal block; after `88/91`, owner/emitter [UID:00004R], file renamed to exclusive end `0x004add34`, and formal C++ contains only the covered-by comment marker naming [UID:00014L] case `3`.
  - Proof: target `## Changes` has a 2026-06-26 B006 entry with the before/after metadata, rename, corrected length, and covered-by marker.
- [x] Validate the renamed target with `python .\tools\validator.py --mode file --file by-memory\0x004adca0-0x004add34.ExchangeDialogRawMoneyUpdate.md --apply --queue-timeout 240`; record command id, command timestamp, exit code, ok count, warnings, and generated refresh state.
  - Proof: exact command returned `command_id:000000002668`, `command_timestamp:2026-06-26T14:31:44-04:00`, exit code `0`, `ok:1`, `generated_refresh:deferred`, `generated_refresh_command_id:000000002668`. Warnings/side effects: `missing_ref_target:149` from existing coverage/report references, `uid_link_update` in `by-memory/-coverage-report.md`, `projected_stats_update`, `tools/validator.ini` path/autogen registry updates, and formal-code UID-link rewrite later corrected with UID-only validation `000000002681` as noted above.
- [x] Update `by-class/ExchangeDialog.md` at report-level detail: method row, raw-start evidence/caveat, owner/source-route wording, retained-helper policy, corrected exclusive end, formal covered-by marker/no standalone body disposition, and current B006 evidence. Keep score `86/88` unless implementation finds unrelated contradictions.
  - Proof: class method row now links [UID:00014N] at `0x004adca0-0x004add34`, and section `2026-06-26 B006 Money-Update Retained Duplicate Recheck` records class owner/source route, MCP facts, no-route proof, packet/control details, rejected owners, and covered-by formal disposition. Score unchanged.
- [x] Validate `by-class\ExchangeDialog.md` with `python .\tools\validator.py --mode file --file by-class\ExchangeDialog.md --apply --queue-timeout 240`; record command id, command timestamp, exit code, ok count, warnings, and generated refresh state.
  - Proof: command returned `command_id:000000002669`, `command_timestamp:2026-06-26T14:32:00-04:00`, exit code `0`, `ok:1`, no target-specific warnings, `generated_refresh:deferred`, `generated_refresh_command_id:000000002669`, `projected_stats_update`.
- [x] Update `by-file/ExchangeDialog.md` at report-level detail: server opcode `0x42` subcommand `3` money-update model, [UID:00014N] class-owner/source-file-route distinction, corrected final byte/exclusive end wording, formal covered-by marker/no standalone body disposition, and stale Wave3/generated `OnExchangePacket` caveat. Keep score `88/86`.
  - Proof: file page packet/control model and evidence bullets now record [UID:00014N] as [UID:00004R]-owned and source-routed through [UID:0000J9], with opcode `0x42` subcommand `3`, stale Wave3/generated caveat, corrected final byte/exclusive end/body length, no-route proof, and marker-only disposition. Score unchanged.
- [x] Validate `by-file\ExchangeDialog.md` with `python .\tools\validator.py --mode file --file by-file\ExchangeDialog.md --apply --queue-timeout 240`; record command id, command timestamp, exit code, ok count, warnings, and generated refresh state.
  - Proof: command returned `command_id:000000002670`, `command_timestamp:2026-06-26T14:32:09-04:00`, exit code `0`, `ok:1`, `generated_refresh:deferred`, `generated_refresh_command_id:000000002670`. Warnings: existing `missing_ref_target 00014T` twice for `by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md`; not introduced by this callback.
- [x] Update `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md` at report-level detail: child row path, boundary notes, cross-reference link, corrected range/length, class-owner repair, covered-by marker/no standalone body proof, and relationship to [UID:00014L]. Keep score unchanged.
  - Proof: aggregate child row and cross-reference now use `0x004adca0-0x004add34`; boundary notes record final byte `0x004add33`, exclusive end `0x004add34`, alignment span, `0x94` / 148-byte length, current MCP facts, class owner/source route, and [UID:00014L] case `3` covered-by disposition. Score unchanged.
- [x] Validate `by-memory\0x004ac8a0-0x004ae4b6.ExchangeDialog.md` with `python .\tools\validator.py --mode file --file by-memory\0x004ac8a0-0x004ae4b6.ExchangeDialog.md --apply --queue-timeout 240`; record command id, command timestamp, exit code, ok count, warnings, and generated refresh state.
  - Proof: command returned `command_id:000000002671`, `command_timestamp:2026-06-26T14:32:16-04:00`, exit code `0`, `ok:1`, `generated_refresh:deferred`, `generated_refresh_command_id:000000002671`. Warning: existing `missing_ref_target 00014T` for `by-memory/0x004ae4c0-0x004b0b15.ItemExchangeMixDialogs.md`; not introduced by this callback.
- [x] Update `by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md` only for UID00014N renamed-path references and any stale `0x004add33` exclusive-end wording; preserve existing inline dispatcher C++ and state, if touched, that [UID:00014L] case `3` is the exact covering emitted behavior for [UID:00014N]'s formal comment marker.
  - Proof: dispatcher status, duplicate-helper table, cross-reference, and change entry now point to [UID:00014N] at `0x004adca0-0x004add34` and state that dispatcher case `3` covers [UID:00014N]'s formal marker. Existing inline dispatcher C++ was not changed.
- [x] Validate `by-memory\0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md` with `python .\tools\validator.py --mode file --file by-memory\0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md --apply --queue-timeout 240`; record command id, command timestamp, exit code, ok count, warnings, and generated refresh state.
  - Proof: command returned `command_id:000000002672`, `command_timestamp:2026-06-26T14:32:23-04:00`, exit code `0`, `ok:1`, no target-specific warnings, `generated_refresh:deferred`, `generated_refresh_command_id:000000002672`.
- [x] Record no edit required for `by-class/ExchangeMoneyEditControlPane.md` unless implementation finds direct stale target ownership/range text there; condition for edit is an explicit contradiction that [UID:00014N] is money-control-owned or uses the old exclusive end.
  - Proof: pre-edit `Select-String` for `00014N`, `004adca0`, `004add33`, `004add34`, `RawMoney`, `ExchangeDialogRawMoneyUpdate`, and related money-update/subcommand text returned no hits. No contradiction found; no edit/validator required.
- [x] Record no edit required for sibling retained helper pages [UID:00014M], [UID:00014O], and [UID:00014P] unless implementation finds direct stale target ownership/range/formal-disposition text there; condition for edit is an explicit contradiction involving [UID:00014N], not merely their own accepted helper policy. Do not change their own formal blocks during this callback.
  - Proof: pre-edit scans of [UID:00014M]/[UID:00014O]/[UID:00014P] found no direct [UID:00014N] old range/formal-disposition contradiction. Hits were only their own source-file links, their own accepted blank dispositions, or a 00014M lookup note that later raw money-update `0x004adca0` is not a function. No edits/validators required.
- [x] Record no edit required for `by-memory/0x00619d28-0x00619dc4.ExchangeDialogVtableData.md`; it already routes ExchangeDialog vtable data through [UID:00004R] and does not need target-specific money-helper text.
  - Proof: pre-edit scan for [UID:00014N], `0x004adca0`, old/new target path, and dispatcher terms returned no target-specific contradiction. No edit/validator required.
- [x] Record no edit required for `by-global/g_packetSender.md`; [UID:00014N] displays server-provided money and does not send a packet.
  - Proof: pre-edit scan for [UID:00014N], `0x004adca0`, old/new target path, ExchangeDialog money/update terms, and opcode `0x42` returned no relevant hits. No edit/validator required.
- [x] Do not edit generated files, project-level generated files, validator/tool state/cache, IDA DB, `by-memory/-coverage-report.md`, or any `-coverage-report.md`.
  - Proof: B006 did not manually edit generated/project-level/coverage/validator files or IDA DB. Required validator `--apply` commands did update validator-owned state and projections: `tools/validator.ini` path/autogen registry updates for the rename, `project-level/-auto-completion-stats.md` projected path completion updates, and a validator-driven `by-memory/-coverage-report.md` UID-link/path update. These were tool side effects from required scoped validation, not manual edits.
- [x] Record generated-refresh expectation: source by-memory/class/file validators may refresh validator-owned generated output; do not manually edit generated reports. Supervisor-owned manual coverage note is not required.
  - Proof: exact validators `000000002668` through `000000002672` reported `generated_refresh:deferred`; target UID-only follow-up `000000002681` reported `generated_refresh:skipped` because `--uid-only`. No manual coverage note is required.
- [x] During implementation callback only, lease the smallest immediate edit batch, release leases immediately after edits/validators, and update this checklist with lease acquisition/release proof.
  - Proof: B006 leased immediate edit batch paths `by-memory\0x004adca0-0x004add33.ExchangeDialogRawMoneyUpdate.md`, `by-class\ExchangeDialog.md`, `by-file\ExchangeDialog.md`, `by-memory\0x004ac8a0-0x004ae4b6.ExchangeDialog.md`, and `by-memory\0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md`; lease report showed creation `2026-06-26T18:25:42Z` and expiration `2026-06-26T18:30:42Z`. Post-validator unlease attempt reported `Rejected[No active lease]` for those paths because the short leases had already expired. B006 then leased the renamed target for the formal-comment restoration and released it successfully with `python .\tools\leaser\leaser.py B006 unlease by-memory\0x004adca0-0x004add34.ExchangeDialogRawMoneyUpdate.md`. Final `current_leases.md` scan for `B006` returned no active leases.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/00014N-ExchangeDialogRawMoneyUpdate-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/00014N-ExchangeDialogRawMoneyUpdate-source-quality.md","timestamp":"2026-06-26T14:40:52","uid":"00014N"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
