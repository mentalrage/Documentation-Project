** TARGET-REPORT-UID:000477 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID000477 UserListDialogPane HandlePacketEvent Source-Quality Report

## Finalized Report / Current Recommendation

UID000477 is implemented as the source-authored virtual override
`bool UserListDialogPane::HandlePacketEvent(Event *event)` in
`NexusTK/social/UserListDialogPane.cpp`. The validator-aware UID-preserving
workflow renamed the target to
`by-memory/0x0059d620-0x0059d8f5.UserListDialogPaneHandlePacketEvent.md`, set
it to `92/94`, retained owner UID0000FN, assigned emitter UID0000OZ, retained
blank optional position and `Nested:0`, and installed Destination R1 exactly.

The target is one 725-byte function, not a mixed range. It handles two
UserListDialogPane-private packet submessages. Submessage `0x83` synchronizes
the local player's hunters-list flag, the first checkbox, the matching master
record, and then always refreshes category page zero. Submessage `0x84` parses
two counted ACP strings, performs the binary's intentionally count-unbounded
name search, updates cached source text, synchronizes the selected bucket, and
adds a chat line. Every path returns `false`, including recognized messages.

The implementation also closes associated declaration debt rather than leaving
the target behind a synthetic packet type or global helper surface. The
secondary EventHandler vtable fixes the method name and mutable `Event *`
signature. UID00047N is a `UserListPane` member and compares names with
case-sensitive `wcscmp`; UID00047C is a `UserListDialogPane` member whose body
happens not to read `this`. The local-player storage at UserPane `+0x3cb1` and
`+0x3cb2` is split into a flag and a 256-wide source-text buffer with inline
accessors while preserving the exact complete size. The constructor, class
declarations, helper definitions, and cached-source caller contain the complete
destination blocks below.

The bounded ordinary implementation and scoped validators are complete. B003
did not edit manual coverage or generated output directly, did not mutate IDA,
and performed no report execution, probe, count, move, archive, or lifecycle
command. Every ordinary lease was short-lived and released after the file's
scoped validation; the terminal lease readback shows zero B003 leases.

## Supporting Research

### Gate 1 evidence-time ordinary documentation

The following table preserves the exact Gate 1 evidence-time baseline. It is
historical after the callback and shows what each accepted change replaced:

| UID | Gate 1 path | Gate 1 SHA256 | Gate 1 state | Accepted bounded disposition |
| --- | --- | --- | --- | --- |
| 000477 | `by-memory/0x0059d620-0x0059d8f5.UserListDialogPaneHandleUserListPacket.md` | `2F4CC65E48760C2EE5BCFAA74CDE9A0EF28598AD2AF9B9281F9DB32F474AE5BF` | `86/90`, owner 0000FN, true, blank emitter/formal/position, `Nested:0` | UID-preserving rename, `92/94`, emitter 0000OZ, R1 |
| 0001KI | `by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md` | `05528E5546AE2A5D218E7CED0E225979BA9E4F5D0F8CB585F6F3D7EBD2262F55` | `90/91`, non-emitting index | `91/92`, R0 blank, exact child/padding corrections |
| 000470 | `by-memory/0x0059bc90-0x0059d198.UserListDialogPaneConstructor.md` | `5BD97D5937C58C94D31F8FD97B7FFAD492D86349902248C9793B0D08599FD9B9` | `93/94`, emitted constructor | score unchanged, R4 one semantic accessor correction inside complete block |
| 000478 | `by-memory/0x0059d900-0x0059da82.UserListDialogPaneOnKeyEvent.md` | `A23E2E682F0508C2DEC9821CAF8ED62273E4A998D0DDA53F90F2D22200A24034` | `86/90`, blank emitter/formal | UID-preserving rename to `...HandleKeyOrTextEvent.md`, interface/history prose only, score/formal unchanged |
| 00047B | `by-memory/0x0059dc20-0x0059de4a.UserListDialogPaneLocalSourceUpdateSendHelperRaw.md` | `5CC6D8CC465553771C3BABCEE48C641C1F9C514EF8BFB8A020A640CE16CC068E` | `87/91`, no owner/route | retain blank/no-route state; synchronize typed UserPane field/accessor evidence |
| 00047C | `by-memory/0x0059de60-0x0059decf.AddUserListSourceMessage.md` | `1707F303F0D3F692C763C3A44A763B23DEF0393FE448330C7BC153E3C65331B0` | `88/91`, mislabeled global helper | rename to `...UserListDialogPaneAddUserListSourceMessage.md`, owner 0000FN, `90/93`, R7 |
| 00047N | `by-memory/0x0059e9f0-0x0059ea8f.SyncUserListSourceTextIntoBucket.md` | `EEC6A11EBBA517A6439169678C78983E9281D4848362D40670BF9678D585ED8D` | `88/91`, mislabeled global helper and `_wcsicmp` | rename to `...UserListPaneSyncSourceText.md`, owner 0000FO, `90/93`, R6 |
| 00047R | `by-memory/0x0059ee10-0x0059efd0.UserListPaneOnDoubleClick.md` | `1606D0669CABD4A2011E9244B28CCE912B297E578623DCD498AB6BE471A3AFB9` | `87/90` | `89/92`, R8 member call, all other behavior preserved |
| 0003E6 | `by-memory/0x0062e8fc-0x0062e998.UserListDialogPaneVtableData.md` | `7C6E5B8CD3B1DC4539E7AAA4B4243FAC81F3BD205EE6F347149833B815C5D862` | `85/90`, incorrectly reconstructable/emitting compiler data | `90/94`, false, blank emitter/position/formal, R9 no-code proof |
| 00026U | `by-memory/0x0062e8fc-0x0062eccc.UserListReadOnlyData.md` | `E33F781520D9E4A2D6E0FA51085C5CD9C86312A53A3E9265A203114733953D29` | `88/92`, false/non-emitting corrected parent already current | ordinary page already present; manual parent row only is stale |
| 0000FN | `by-class/UserListDialogPane.md` | `C69DA6FD0A560D0A63802C3991A8F5F1DBE3F653BFF49A8E4FF2137545E11F92` | `93/94` | `94/95`, complete R2 |
| 0000FO | `by-class/UserListPane.md` | `08BF459CA3BE4F544B78F5275C288F4BE35550D1B9363DB478952A0B26F7FAA5` | `91/92` | `92/93`, complete R5 |
| 0000FQ | `by-class/UserPane.md` | `8D5E4BAAF5D6CECC2AA036BF7E0D6893146D4F6BEA86328F59ED7D27DD76DA5A` | `93/94`, complete 0x13eb84 shared union | `94/95`, complete R3 field/accessor closure without loss |
| 0000OZ | `by-file/UserListDialogPane.md` | `2DEE34F3662EF1E33209EB752DAB6F8A7B8F9ABB851B055F028E42034AD93ECC` | `92/93` | `93/94`, source inventory and corrected members |
| 0000P1 | `by-file/UserPane.md` | `478D6E65547465A427C87CCD0591F30A28EA5B7231DC7F9DC69DF31B2CEA8F63` | `92/93` | `93/94`, exact field/accessor source support |
| 0000QK | `by-global/g_pCollectionData.md` | `2E60EF425792EA54F5D171759AA9F9FB2D7D082E9E2DBE93A1ABDC040A111F4A` | `89/90` | score/formal unchanged; replace opaque +0x3cb1/+0x3cb2 wording with typed fields |
| 0001OR | `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md` | `C17A3DD7623A288DA1D5143724C5B6104436F8A5BABFC0DC3E1CFA161052061F` | `89/90` | score/formal unchanged; typed-field link only |
| 0002ZX | `by-global/g_bShowHuntersListOnly.md` | `E25D60FA243D4F61AB65B6986336B0A71A39623A994E6D86ECBCD5F2BD5DFA25` | `88/90` | verify-only; distinct module filter remains exact |
| 0000A7 | `by-class/PartySearchEditPane.md` | `E998ED49CB567B2C61F7E40632F7B718A345BCCD0D0EF6D733EACF96252A065B` | `85/89`, separate class debt | prose-only field/accessor synchronization, score/formal unchanged |

Callback-current ordinary state is established by the destination hash table
under **Changed Files**. The key terminal metadata are UID000477 `92/94`,
UID0001KI `91/92`, UID0000FN `94/95`, UID0000OZ `93/94`, UID0000FO `92/93`,
UID00047N/UID00047C `90/93`, UID00047R `89/92`, UID0003E6 `90/94` and
non-emitting, UID0000FQ `94/95`, and UID0000P1 `93/94`. All four former paths
named in C04/C13/C14 are absent after their UID-preserving renames.

Current specialized support also confirms that
`CheckBoxTextControlPane::SetChecked(bool)` stores only `m_checked` at
`+0x108`; it does not invalidate. Consequently R1 must retain the separate
`Invalidate()` call. Event UID00004L and EventHandler UID00004N already carry
the exact packet payload and secondary virtual interface and are verify-only.

### Historical-report search

Exact terms `000477`, `0x0059d620`,
`UserListDialogPaneHandleUserListPacket`, `HandleUserListPacket`,
`SyncUserListSourceTextIntoBucket`, `AddUserListSourceMessage`, and
`PacketEventContext` were searched under every required root:

| Root | Result and classification |
| --- | --- |
| `source-3/project-documentation/archived/**` | No match for any exact term. |
| `tools/leaser/Agents/Older-Research/**` | No match for any exact term. |
| `tools/leaser/Agents/SpecialReports/**` | No match for any exact term. |
| `executed-b-agent-research/**` | B004 UID000475 supplies valid RefreshCategoryView range/caller support; B004 UID00047B supplies valid no-route raw-helper and local-state offsets; B001 UID0000FN supplies class/layout history but its `PacketEventContext`/global-helper shape is stale; B002 UID0001KI supplies the split/index and exact padding inventory but its blank target formal is now superseded; B001 UID0003US/UID0003VB concerns the separate UserPane opcode-0x36 staging path and is not the direct target. No executed report is direct UID000477 coverage. |
| `tools/leaser/Agents/**` | Current goal/audit/tracker references only; no competing direct report. Substring-only command/UID hits were rejected as unrelated. |

No Wave2/Wave3 assertion is used as authority. Every historical lead was
checked against current ordinary pages and session `9b0396a3`.

## Target

- UID: `000477`.
- Historical Gate 1 path:
  `by-memory/0x0059d620-0x0059d8f5.UserListDialogPaneHandleUserListPacket.md`.
- Implemented path:
  `by-memory/0x0059d620-0x0059d8f5.UserListDialogPaneHandlePacketEvent.md`.
- Exact range: `[0x0059d620,0x0059d8f5)`.
- Exact size: `0x2d5`, decimal `725`.
- SHA256 of the exact 725 target bytes:
  `8AE29BCB809B18D2F3DCAC4CE347292B259953E9655BE0612F4879FDA6CCCDAD`.
- PE mapping: module image base `0x00400000`, `.text` RVA `0x0019d620`,
  file offset `0x0019ca20`.
- First 16 bytes:
  `55 8b ec 6a ff 68 0b a1 60 00 64 a1 00 00 00 00`.
- Modeled function: `sub_59D620`, 223 instructions, 39 basic blocks.
- Current IDA prototype: `char __thiscall(int this, int event)`; source
  correction: `bool UserListDialogPane::HandlePacketEvent(Event *event)`.
- ABI: adjusted EventHandler receiver, one stack argument, `retn 4`; `this`
  is complete `UserListDialogPane + 0xa0`, so adjusted `+0x1e8` is complete
  `+0x288` and calls on the complete object subtract `0xa0`.
- Return: every path reaches `xor al,al`; recognized packets do not report
  handled status.
- Stack/compiler shape: `0x418` local bytes, two 256-wide local arrays,
  temporary wide-string construction/destruction, VC-era SEH and security
  cookie scaffolding, and compiler range-check failure support.
- Direct xrefs: exactly one data xref, vtable cell `0x0062e970`; no direct
  code caller and no separate function-pointer route.

## Current Target State

The implemented page is `92/94`, owner UID0000FN, reconstructable true,
emitter UID0000OZ, blank optional position, exact R1 managed C++, and
`Nested:0`. Its path/title/signature are source-facing, and the accepted
helper/API blockers are resolved in the bounded support destinations.

The following is explicitly historical pre-callback generated evidence.
Report-only finalization observed external validator command `000000014558`, refreshed
`2026-07-19T18:21:27-04:00`. It advances the earlier command-14538 header
without changing any target semantic count:

- `auto-generated/NexusTK/social/UserListDialogPane.cpp` SHA256
  `6D09FA8A0E6E9EAF1375D83152D5E54DBCC46E002757FE2570DEF27773BD5D7E`,
  25,696 bytes, 719 lines.
- It contains zero UID000477 body/marker occurrences, one stale
  `HandleUserListPacket`, two `PacketEventContext` tokens, zero
  `HandlePacketEvent`, global rather than member Sync/Add declarations and
  definitions, one `m_preCollectionState[0]`, two `_wcsicmp` tokens, and only
  one `wcscmp` token.
- Its two Empty Emitter Markers were UID0000A7 PartySearchEditPane and
  UID0003EI Singleton backing-storage history; neither is UID000477 or
  UID0003E6. This implementation does not claim those independent markers as
  work owned by R1-R9.
- `auto-generated/NexusTK/ui/panels/UserPane.cpp` at the same command has
  SHA256
  `1114AF90CAC595B476AEDDA7B52DAC3A6F012DB7DA7AF2F420932229701D495E`,
  91,409 bytes, 2,737 lines. It contains one opaque
  `m_preCollectionState`, zero typed hunters/source fields, and zero new
  accessors.

Current generated proof is recorded under **Validator Results**: B003's waited
command 14632 completed after all ordinary validators, and later read-only
validator-owned command 14635 retained all accepted semantic assertions.
Supervisor-owned manual coverage is also current: commands 14639-14641 applied
and validated the exact accepted memory/class/file handoff after address-order
rebasing. Those external coverage actions changed no ordinary page, formal, or
generated semantic assertion.

## Executive Recommendation

The target rename/body and bounded class/helper/field corrections were applied
in one serialized callback. The implemented source factorization is class-member
code, not decompiler expansion and not free helpers. Preserve the binary's
unsafe protocol assumptions exactly. Do not add bounds, null, conversion,
bucket, or packet-size guards; do not normalize the always-false return; do
not fold checkbox invalidation into `SetChecked`; and do not emit raw
vtable/RTTI/EH/cookie/range-check source.

## Supervisor Active Recheck

At the final report-only evidence checkpoint, `current_leases.md` contained no
active leases. During implementation, B003 reread the ledger and each
destination after each short lease acquisition, including the complete shared
UID0000FQ/UID0000P1 union. Every lease was released immediately after scoped
validation. Terminal `tools/leaser/Agents/Agent-B003/current_leases.md`
readback again states `No active leases.`

## Inference Research Guidance Check

The report does not preserve unknown names merely because symbols are stripped.
Each inferred name is selected from role, vtable slot, current project
vocabulary, and caller/callee behavior. Descriptive subtype names and the two
UserPane private field names remain lexical inferences, so confidence is
capped below certainty. Binary-exact types, widths, branch order, range,
ownership, source file, and member-versus-free linkage are not speculative.

## Heuristic / Inference Reanalysis And Validation

### Method name, event type, and return

The only xref is secondary vtable `0x0062e970`. EventHandler UID00004N fixes
secondary slot `+0x10` as `HandlePacketEvent`, after pointer/mouse `+0x04`,
key/text `+0x08`, and IME `+0x0c`. Event UID00004L fixes mutable
`Event *` and packet data at `event+0x0c`; the body never consumes a
target-specific wrapper. `HandleUserListPacket(PacketEventContext *)` is
therefore historical descriptive provenance, not source shape. `bool` is
selected because AL is the sole return and is always zero.

The same table proves UID000478 is secondary slot `+0x08` and should be named
`HandleKeyOrTextEvent(Event *)`. This report only corrects that interface and
link; its 0x182-byte body remains outside the direct target and its blank
formal/score stay unchanged.

### Submessage 0x83

`packet[1]` is loaded through Dinkumware
`std::_Narrow_char_traits::to_char_type` at `0x00575470`. Its 975 broad refs
and one-byte behavior prove compiler/runtime lowering; human source is a
direct unsigned-byte read. The byte is stored at `g_pUserPane+0x3cb1`, then
written as the checked state of child index `0x14`. Constructor ordering proves
this is the first hunters-list participation checkbox, not the separate
`g_bShowHuntersListOnly` filter checkbox created afterward. The setter only
stores `m_checked`, so the following invalidation remains explicit.

The master-list count is captured once. Each bounded iteration fetches a
`UserListRecord`, constructs a temporary wide string from the global local
player name using `0x005a2dc0`, compares case-sensitively, destroys the
temporary, and on the first match stores the raw flag byte at record `+0x20e`.
`RefreshCategoryView(0)` occurs after the loop even when the list is empty or
no row matches.

### Submessage 0x84

The first counted ACP string uses unsigned byte length `packet[1]`, bytes at
`packet+2`, a 256-wide destination, and `MultiByteToWideChar(CP_ACP,0,...)`.
The return is narrowed through signed 16-bit before termination. The next
length is at `packet[targetNameLength+2]`, and the source bytes begin at
`packet+targetNameLength+3`; conversion and termination repeat exactly.
Compiler range-check failure support is not source-authored.

If the list count is zero, the path returns false. Otherwise the search starts
at zero, fetches a record, compares `wcscmp(targetName, record->name)`, and on
mismatch increments the index. Counterintuitively, the loop condition reloads
only `GetCount()!=0`; it never compares index to count. The immutable nonempty
list therefore makes a missing target run beyond valid records. This protocol
assumption is preserved, not repaired.

The match sets `hasSourceText=1`, copies exactly 256 wide characters, maps
nonzero bucket `n` to `m_bucketPanes[n-1]` and zero to bucket four, invokes the
pane member SyncSourceText, then the dialog member AddUserListSourceMessage.
It does not refresh categories.

### Helper and local-state closure

At `0x0059e9f0`, caller ECX is the selected `UserListPane *`; the helper scans
its list and uses case-sensitive `wcscmp`. Current free helper linkage and
`_wcsicmp` are contradicted. At `0x0059de60`, both callers seed ECX with a
`UserListDialogPane *` and the function returns with `retn 4`. It is a
nonstatic member even though the optimized body does not read ECX. Making it a
member also gives `UserListPane::OnDoubleClick` a coherent source call through
`g_pUserListDialogPane`.

UserPane layout arithmetic closes the local state without changing class size:

| Complete-object offset | Source type/name | Evidence |
| --- | --- | --- |
| `+0x218` | `GroupMemberRecord m_groupMembers[50]` | Existing exact 50 x 0x12c layout. |
| `+0x3cb0` | `signed char m_groupMemberCount` | Existing signed count. |
| `+0x3cb1` | `unsigned char m_huntersListFlag` | Incoming 0x83 store, constructor checkbox read, outbound raw helper read, PartySearch write. |
| `+0x3cb2..+0x3eb1` | `wchar_t m_partySearchSourceText[256]` | Raw source-update helper copies exactly 256 wchar values; PartySearch owns the text. |
| `+0x3eb2..+0x3eb3` | `unsigned char m_preCollectionState[2]` | Remaining opaque bytes preserve the old aggregate extent. |
| `+0x3eb4` | `int m_currentSayMode` | Existing independently proven field and unchanged alignment. |

Public inline accessors are preferred over public raw fields, friends, or
offset overlays because target, constructor, PartySearch, and retained raw
helper span multiple source contexts. Inline accessors create no new binary
entry point and compile to the observed direct accesses. Exact private names
are descriptive, hence the 95 confidence cap.

## Evidence Standards Used

- Live IDA MCP facts are used for bytes, modeled boundaries, CFG, ABI,
  xrefs, vtable cells, decompilation, calls, and field displacements.
- Current ordinary docs are used only after direct readback and hash capture.
- Generated and manual coverage files are read-only state snapshots, not
  primary binary evidence.
- Historical reports are leads; target-specific conclusions require current
  MCP/doc agreement.
- Exact instruction behavior outranks safety improvements or stylistic
  normalization.
- Compiler lowering is excluded from human source only when the source cause
  is identified.

## Evidence Checked

Fresh MCP availability check on 2026-07-19 used streamable JSON-RPC session
`9b0396a3`. `idb_list` returned exactly one active/owned/adopted NexusTK IDB
worker (PID 15732). `server_health` returned `status=ok`, image base
`0x00400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, and
2,067 cached strings. Bounded `lookup_funcs(0x0059d620)` returned
`sub_59D620`, size `0x2d5`; bounded `get_bytes` returned the exact first 16
bytes above. The previously retained decompile/disassembly/xref pass was then
accepted only where it matched these fresh bounded facts.

Checked target/callee evidence includes the complete target decompile and
disassembly, 223-instruction/39-block function metadata, target bytes/hash,
PE mapping, xrefs to the function and vtable, vtable bytes at
`0x0062e960..0x0062e974`, Event/EventHandler declarations, predecessor and
successor bytes, and decompilation/call contexts for `0x00575470`,
`0x0059e9f0`, `0x0059de60`, `0x005a2dc0`, `0x00584540`, `0x00582b70`,
`0x0059d2b0`, List count/get-element calls, `_wcscpy_s`, `wcscmp`,
`MultiByteToWideChar`, and checkbox state/invalidation.

Checked documentation includes every destination table row above, Event,
EventHandler, CheckBoxTextControlPane and its layout, List/ListPane,
UserListRecord layout, globals, UserPane layout, generated UserListDialogPane
and UserPane outputs, all four applicable manual coverage roots, current
lease ledger, and every historical search root listed above.

## Claim And Incorporation Ledger

All C01-C20 rows are terminal. Actions retain the accepted enum; verification
states use only callback-terminal values. Detailed proof remains claim-specific
rather than being reduced to validator success alone.

| Claim | Atomic claim | Confidence | Evidence | Destination(s) | Action | Verification state | Implementation proof |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | Healthy mandatory MCP evidence was captured under session 9b0396a3 with live IDB, health, target lookup, bytes, decompile/disassembly/xrefs. | very high | MCP facts above | target/support evidence | incorporate | applied | UID000477, UID0001KI, UID0000FN, UID0000OZ, and UID0003E6 carry the accepted live-evidence facts; scoped commands 14599, 14606-14608, and 14603 all exited 0/ok 1. |
| C02 | Target is exact `[0x0059d620,0x0059d8f5)`, 0x2d5/725 bytes, SHA256 8AE29B..., one 223-instruction/39-block function. | very high | bytes/hash/function metadata | UID000477, UID0001KI | incorporate | applied | UID000477 and parent UID0001KI preserve the exact range, size in hexadecimal/decimal, target-byte hash, PE mapping, instruction/block counts, and boundaries; commands 14599/14606 passed. |
| C03 | ABI is adjusted EventHandler thiscall, one Event pointer, `retn 4`, bool result always false, complete object adjustment -0xa0. | very high | prologue/epilogue/vtable/decompile | UID000477, UID0000FN | incorporate | applied | Target prose/R1 and R2 document the adjusted receiver, mutable Event pointer, callee cleanup, complete-object adjustment, and always-false result; commands 14599/14607 passed. |
| C04 | Secondary slot +0x10 proves source name `HandlePacketEvent(Event *)`; old title/type are superseded. | very high | UID00004N, vtable 0x62e970 | UID000477, UID000478, UID0000FN, UID0003E6 | historicalize | applied | Validator-aware commands 14599/14600 preserved UIDs while renaming target and UID000478; R2 and UID0003E6 table prose carry slots +0x08/+0x10; all old paths are absent. |
| C05 | Opcode 0x83 directly reads raw byte packet[1], stores UserPane hunters flag, checkbox state, and separately invalidates. | very high | disassembly/helper/control order | UID000477, UID000470, UID0000FQ | incorporate | applied | R1, R4, and R3 preserve direct byte order, typed accessor, SetChecked, and separate Invalidate; commands 14599/14609/14620 passed. |
| C06 | Opcode 0x83 captures count once, builds/destroys local-name WideString per iteration, case-sensitively matches, writes row +0x20e, breaks. | very high | target CFG/calls/record layout | UID000477, UID0000FN, UID0000OZ | incorporate | applied | R1 and class/file evidence preserve captured count, per-iteration temporary, `wcscmp`, row write, and break; commands 14599/14607/14608 passed. |
| C07 | `RefreshCategoryView(0)` always follows the 0x83 scan, including empty/no-match paths, and is absent from 0x84. | very high | branch/call order | UID000477, UID000475 | incorporate | applied | R1 contains the unconditional post-scan call only in 0x83; validator-propagated UID000475 link was reread and scoped-validated by command 14630 with its score/formal/body unchanged. |
| C08 | Opcode 0x84 parses two unsigned-byte-counted ACP strings at exact cursor positions into two wchar_t[256] buffers with signed-short termination indices. | very high | target disassembly/decompile | UID000477 | incorporate | applied | UID000477 prose and R1 retain both counted parses, cursor movement, 256-wide buffers, and signed-short termination stores; command 14599 passed. |
| C09 | Compiler range-check, cookie, and EH support are excluded; conversion results/indices remain unchecked in human source. | very high | compiler edge/call taxonomy | UID000477 | reject-invalid | excluded-with-reason | UID000477 documents compiler lowering but R1 omits helper calls and added guards; generated command-14635 readback has zero RTTI/cookie/EH/range-check tokens. |
| C10 | Nonempty 0x84 search is intentionally not bounded by index; only list nonemptiness is retested. | very high | exact loop CFG | UID000477, UID0000OZ | incorporate | applied | R1 preserves the protocol-assumed loop and file prose records the negative bound evidence; commands 14599/14608 passed. |
| C11 | Matching row writes hasSourceText/sourceText, maps bucket 0 to pane 4 and n to n-1, then SyncSourceText and AddUserListSourceMessage. | very high | target calls/offsets | UID000477, UID00047N, UID00047C | incorporate | applied | R1/R6/R7 preserve row writes, mapping, and exact call order; UID-preserving commands 14601/14602 and target command 14599 passed. |
| C12 | Unknown and recognized submessages all return false; no event/data/size/null/conversion/record/bucket guards exist. | very high | complete CFG | UID000477 | incorporate | applied | R1 and target negatives preserve the default and recognized false returns and intentionally omit every rejected guard; command 14599 passed. |
| C13 | UID00047N is `UserListPane::SyncSourceText` and uses `wcscmp`, not a free helper or `_wcsicmp`. | very high | ECX caller and callee disassembly | UID00047N, UID0000FO, UID0000OZ | reject-stale | applied | Command 14602 performed the UID-preserving member rename; R6/R5/file inventory are exact. Current generated line 747 emits the member once and line 755 uses `wcscmp`; the sole `_wcsicmp` is unrelated UID00047K comparator history. |
| C14 | UID00047C is `UserListDialogPane::AddUserListSourceMessage`; optimized body ignores this, but both callers and retn 4 prove member ABI. | very high | both call sites/callee epilogue | UID00047C, UID00047R, UID0000FN, UID0000OZ | reject-stale | applied | Command 14601 performed the UID-preserving member rename; R7/R8/R2/file evidence preserve both ECX-seeded callers and optimized-body caveat; generated definitions occur once. |
| C15 | UserPane +0x3cb1/+0x3cb2 are typed hunters flag and 256-wide party-search source text; two residual bytes preserve +0x3eb4 alignment and 0x13eb84 size. | high | all readers/writers/layout arithmetic | UID0000FQ, UID0000P1, UID000470, UID00047B, UID0000QK, UID0001OR, PartySearch support | incorporate | applied | R3 plus class/file/global/raw-helper/PartySearch prose apply the exact split and residual bytes; commands 14609-14613, 14616-14618, 14620, 14624/14626 passed. |
| C16 | Public inline UserPane accessors are the strongest source-safe cross-context model and introduce no callable binary entries. | high | access/use graph and inlining | UID0000FQ, UID000470, UID000477 | incorporate | applied | R3 exposes four inline accessors and R1/R4 consume them; current UserPane.cpp has accessor token counts 1/1/2, old 0x203 field zero, and the size guard once. |
| C17 | Owner UID0000FN and source/emitter UID0000OZ are exact; target is source-authored and eligible, position blank, Nested 0. | very high | class/vtable/file/aggregate | UID000477, UID0000FN, UID0000OZ | incorporate | applied | Current metadata is owner 0000FN, emitter 0000OZ, true, blank position, Nested 0; class/file routing commands 14607/14608 and target 14599 passed. |
| C18 | No split: predecessor UID000476 switch table/padding and successor 11-byte alignment remain parent-owned; vtable data is compiler-generated false/non-emitting. | very high | boundary bytes/hashes | UID000477, UID0001KI, UID0003E6 | incorporate | applied | Parent R0/prose preserves both adjacent dispositions; UID0003E6 is 90/94 false with blank emitter/R9. Commands 14606/14603 passed. |
| C19 | R0-R9 are complete destination-specific formal dispositions; raw vtable/RTTI/EH/cookie/range-check arrays/code remain absent. | very high | formal parity/source-cause analysis | all formal destinations | incorporate | applied | Post-validation byte-for-byte managed-body comparison reports R0-R9 all equal to the accepted report; hashes and lengths are recorded under Validator Results. Current generated output has zero raw compiler artifacts. |
| C20 | Scores, historical corrections, exact manual coverage handoff, expected validators/generated assertions, and unchecked callback checklist are destination-complete. | high | current docs/generated/manual roots | report and listed destinations | incorporate | applied | Current ordinary hashes/scores, commands 14599-14632, read-only command-14635 output, externally applied supervisor coverage commands 14639-14641, terminal checklist, zero leases, and durable lifecycle boundary are recorded below. |

## Positive Evidence Summary

- Exact vtable position proves a virtual packet event override and the mutable
  Event contract.
- Exact adjusted-this arithmetic agrees with UserListDialogPane's complete
  `0x28c` layout and master list at `+0x288`.
- Both packet branches use established UserListRecord fields and existing
  category/list APIs without raw-offset source.
- Constructor control order and checkbox implementation jointly identify child
  index `0x14` and require separate invalidation.
- Member ABI at both helper sites resolves global/private access contradictions.
- All four known accesses to local hunters/source state fit one exact natural
  UserPane field split without changing any downstream offset or class size.
- Owner, source route, aggregate, vtable, globals, and generated source all
  converge on `NexusTK/social/UserListDialogPane.cpp`.

## IDA MCP Facts

| Fact | Result |
| --- | --- |
| Database | `9b0396a3`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` |
| Health | `ok`; analysis, Hex-Rays, strings ready; 2,067 strings |
| Function | `sub_59D620`, `0x2d5` bytes |
| Instructions / blocks | 223 / 39 |
| First bytes | `55 8b ec 6a ff 68 0b a1 60 00 64 a1 00 00 00 00` |
| Exact target hash | `8AE29BCB809B18D2F3DCAC4CE347292B259953E9655BE0612F4879FDA6CCCDAD` |
| Xrefs | one data xref at `0x0062e970`; no code xref |
| Return | `xor al,al`, `retn 4` on all exits |
| Stack | `0x418`, two 256-wide buffers plus temporary/string/compiler scaffolding |

## Function / Child Inventory

| Range | UID | Role | Implemented state |
| --- | --- | --- | --- |
| `0x0059d5fe-0x0059d620` | 000476 | RefreshCategoryView switch table plus trailing alignment | unchanged separate parent-owned child |
| `0x0059d620-0x0059d8f5` | 000477 | HandlePacketEvent | UID-preserving rename complete, `92/94`, R1 exact |
| `0x0059d8f5-0x0059d900` | parent UID0001KI | eleven `0xcc` alignment bytes | remain parent-only padding |
| `0x0059d900-0x0059da82` | 000478 | HandleKeyOrTextEvent | rename/interface sync complete; score/formal unchanged |

The predecessor exact bytes are
`66 90 1c d3 59 00 2b d3 59 00 33 d3 59 00 3a d3 59 00 41 d3 59 00 48 d3 59 00 cc cc cc cc cc cc cc cc`,
SHA256
`8836AD98BF808653ED57793D3B3362CCDAA1DE3AAEB4BC754FA071F9A14649C9`.
The successor pad is eleven `cc` bytes, SHA256
`3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`.

## Direct Xref / Caller Inventory

| Site | Route | Conclusion |
| --- | --- | --- |
| `0x0062e970` | UserListDialogPane secondary EventHandler vtable +0x10 | sole target xref; HandlePacketEvent override |
| target `0x83` | direct `RefreshCategoryView(0)` | member call on complete object after adjusted-this normalization |
| target `0x84` | ECX = selected UserListPane, call `0x0059e9f0` | SyncSourceText is UserListPane member |
| target `0x84` | ECX = complete UserListDialogPane, call `0x0059de60` | AddUserListSourceMessage is dialog member |
| UID00047R cached path | ECX = `g_pUserListDialogPane`, call `0x0059de60` | second member-ABI proof |
| direct code callers | none | virtual dispatch only; absence is expected, not no-route proof |

## Documentation Evidence And IDA Status

The Gate 1 docs correctly preserved most row layout, opcode behavior,
RefreshCategoryView placement, owner, and source family. Their blocker
statements are now explicitly historical: Event/EventHandler resolve the
signature; List/ListPane and UserListRecord resolve container APIs; current
checkbox docs resolve state versus invalidation; helper caller ABI resolves
member access; and UserPane consumers resolve the local fields.

Commands 14538 and 14558 are explicitly historical pre-callback generated
evidence; command 14558 was the report-finalization readback, not a B003
validator command. Commands 14599-14632 implemented and validated R0-R9.
Current read-only command 14635 emits R1/R6/R7/R8 and both class declarations,
with no target marker, global-helper shape, opaque 0x203 field, or stale event
type.

## Ranked Ownership Analysis

1. **UID0000FN UserListDialogPane / UID0000OZ UserListDialogPane.cpp**:
   selected. Vtable slot, receiver layout, fields, sibling methods, resources,
   file aggregate, and both helper calls agree.
2. **UID0000FO UserListPane**: selected only for UID00047N and UID00047R.
   The target invokes a UserListPane member but is not owned by that class.
3. **UID0000FQ UserPane**: dependency only. It owns local-player state but not
   the social dialog event handler.
4. **PartySearchEditPane**: rejected as target owner. It writes/sends related
   state, but target ECX and vtable are UserListDialogPane.
5. **Generic Event/packet utility**: rejected. Event supplies ABI and packet
   storage; all semantics and state are user-list specific.
6. **Compiler/runtime**: rejected for target ownership. Only char-traits,
   EH, cookie, and range-check fragments are compiler/runtime lowering.

## Source Placement

The implementation places all UserListDialogPane/UserListPane source additions
under existing `NexusTK/social/UserListDialogPane.cpp` (UID0000OZ) and the
UserPane field/inline-accessor declaration additions under existing
`NexusTK/ui/panels/UserPane.cpp` (UID0000P1). It creates no packet utility,
helper source file, vtable source, raw-data source, or PartySearch-only source.

## Range / Split / Padding / Reclassification Analysis

UID000477 remains one child and `Nested:0`. UID000476 keeps the preceding table
and alignment. UID0001KI keeps the eleven-byte successor alignment and all
unrelated children. No target byte moves to UID000478. UID0003E6 is
reclassified from reconstructable/emitting compiler data to false/blank
source-declared/generated-binary support; its exact tables and RTTI remain
documented, but source is R2 virtual declarations rather than raw arrays.

## Negative Evidence Summary

- No direct code caller exists; virtual dispatch explains this and does not
  support a no-route disposition.
- No packet-size or pointer guard, subtype default action, conversion-success
  check, record null check, target-search upper bound, or bucket-range guard
  exists.
- No 0x84 category refresh exists.
- `0x00575470` is not a user-list packet-byte helper.
- UID00047N is not free/file-local and is not case-insensitive.
- UID00047C is not a free helper merely because its optimized body ignores ECX.
- `g_bShowHuntersListOnly` is not the `+0x3cb1` local participation byte; the
  two checkboxes and storage are distinct.
- No evidence supports public raw UserPane fields, a friend web, a union
  overlay, a synthetic packet reader, or a new source file.
- No raw vtable/RTTI arrays, explicit this adjustment, destructor/EH cleanup,
  cookie checks, or `__report_rangecheckfailure` belong in human C++.

## IDA Rename / Type / Comment Recommendations

- Rename function `sub_59D620` to
  `UserListDialogPane__HandlePacketEvent` and apply
  `bool __thiscall(UserListDialogPane_EventHandlerFacet *, Event *)` or the
  closest IDA-adjusted type without changing database state in this report.
- Type `event+0x0c` as packet data pointer through current Event payload.
- Comment secondary vtable `0x0062e970` as HandlePacketEvent slot.
- Comment `+0x1e8` adjusted receiver field as complete `m_allUserRecords`
  `+0x288` and calls using `this-0xa0` as complete-object normalization.
- Rename `sub_59E9F0` to `UserListPane__SyncSourceText` and type ECX as
  UserListPane.
- Rename `sub_59DE60` to
  `UserListDialogPane__AddUserListSourceMessage` and retain member ABI.
- Name UserPane bytes `m_huntersListFlag` and
  `m_partySearchSourceText`; retain residual two-byte state separately.
- Preserve subtype constants as inferred/descriptive enum names, not protocol
  claims of recovered original spelling.

## First-Draft C++ Recommendation

Every C++ destination below is complete for that destination. No example C++
exists outside managed blocks.

### R0 - UID0001KI aggregate, blank non-emitting formal

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R1 - UID000477 UserListDialogPane::HandlePacketEvent

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool UserListDialogPane::HandlePacketEvent(Event *event)
{
    const char *packet =
        static_cast<const char *>(event->m_payload.m_packet.m_data);

    switch (static_cast<unsigned char>(packet[0]))
    {
    case kUserListHuntersListStateUpdate:
    {
        const unsigned char huntersListFlag =
            static_cast<unsigned char>(packet[1]);

        g_pUserPane->SetHuntersListFlag(huntersListFlag);

        CheckBoxTextControlPane *checkBox =
            GetChild<CheckBoxTextControlPane>(kHuntersListParticipationControl);
        checkBox->SetChecked(huntersListFlag != 0);
        checkBox->Invalidate();

        const int recordCount = m_allUserRecords->GetCount();
        for (int index = 0; index < recordCount; ++index)
        {
            UserListRecord *record = static_cast<UserListRecord *>(
                m_allUserRecords->GetElementAt(index));

            WideString localPlayerName;
            GetLocalPlayerNameString(localPlayerName);
            if (wcscmp(record->name, localPlayerName.c_str()) == 0)
            {
                record->huntersListFlag = huntersListFlag;
                break;
            }
        }

        RefreshCategoryView(0);
        break;
    }

    case kUserListSourceTextUpdate:
    {
        const unsigned char targetNameLength =
            static_cast<unsigned char>(packet[1]);
        wchar_t targetName[256];
        const short targetNameCharacters = static_cast<short>(
            MultiByteToWideChar(CP_ACP, 0, packet + 2, targetNameLength,
                                targetName, 256));
        targetName[targetNameCharacters] = L'\0';

        const unsigned char sourceTextLength =
            static_cast<unsigned char>(packet[targetNameLength + 2]);
        wchar_t sourceText[256];
        const short sourceTextCharacters = static_cast<short>(
            MultiByteToWideChar(CP_ACP, 0,
                                packet + targetNameLength + 3,
                                sourceTextLength, sourceText, 256));
        sourceText[sourceTextCharacters] = L'\0';

        int index = 0;
        if (m_allUserRecords->GetCount() != 0)
        {
            UserListRecord *record;
            do
            {
                record = static_cast<UserListRecord *>(
                    m_allUserRecords->GetElementAt(index));
                if (wcscmp(targetName, record->name) == 0)
                    break;
                ++index;
            }
            while (m_allUserRecords->GetCount() != 0);

            record->hasSourceText = 1;
            wcscpy_s(record->sourceText, 256, sourceText);

            UserListPane *pane = record->bucketIndex != 0
                ? m_bucketPanes[record->bucketIndex - 1]
                : m_bucketPanes[4];
            pane->SyncSourceText(record);
            AddUserListSourceMessage(record);
        }
        break;
    }
    }

    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R2 - UID0000FN complete UserListDialogPane declaration

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
template <class T> class Singleton;
class DialogPane;
class Event;
class List;
class PartySearchEditPane;
class UserListDialogPane;
class UserListPane;
class WideString;

extern UserListDialogPane *g_pUserListDialogPane;
void GetLocalPlayerNameString(WideString &outName);

#pragma pack(push, 1)
struct UserListRecord
{
    unsigned char careerId;
    unsigned char bucketIndex;
    unsigned char reserved2;
    unsigned char badgeIconId;
    unsigned char displayColor;
    unsigned char reserved5[3];
    long arrivalSortKey;
    unsigned char statusIconId;
    unsigned char reservedD;
    wchar_t name[256];
    unsigned char huntersListFlag;
    unsigned char hasSourceText;
    wchar_t sourceText[256];
    unsigned char careerVariant;
    unsigned char reserved411[3];
};
#pragma pack(pop)

int __cdecl CompareUserListRecordsByStatus(const UserListRecord *left,
                                           const UserListRecord *right);
int __cdecl CompareUserListRecordsByName(const UserListRecord *left,
                                         const UserListRecord *right);

class UserListDialogPane : public Singleton<UserListDialogPane>, public DialogPane
{
public:
    enum UserListMessage
    {
        kUserListHuntersListStateUpdate = 0x83,
        kUserListSourceTextUpdate = 0x84
    };

    enum UserListControlIndex
    {
        kHuntersListParticipationControl = 0x14
    };

    explicit UserListDialogPane(const unsigned char *packet);
    virtual ~UserListDialogPane();

    void SortListsByStatus();
    void SortListsByName();
    void RefreshCategoryView(char step);
    virtual bool HandlePacketEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void OnControlCommand(int controlIndex, int notifyCode);

    void AddUserListSourceMessage(const UserListRecord *record);

private:
    short m_selectedNationId;
    short m_categoryPage;
    short m_selectedCareerVariant;
    UserListPane *m_bucketPanes[5];
    List *m_allUserRecords;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R4 - UID000470 complete UserListDialogPane constructor

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
UserListDialogPane::UserListDialogPane(const unsigned char *packet)
    : Singleton<UserListDialogPane>(),
      DialogPane(L"Users Dialog Pane", 8, 1)
{
    wchar_t localPlayerName[128];
    GetMemoryMan();
    GetLocalPlayerName(localPlayerName, 128);

    const unsigned char playerSettingsFlag = g_pUserPane->m_playerSettingsState[0];
    RectBounds bounds;
    wchar_t countText[12];
    char narrowName[256];
    int filteredCount = 0;
    int visibleCount = 0;

    if (g_useEpfAssets == 1)
    {
        InitRectBounds(&bounds, 0, 0, 709, 452);
        AddControl(new EPFImageControlPane(L"USERLIST.EPF", 0, true, &bounds,
                                           L"USERLIST.PAL"));

        InitRectBounds(&bounds, 608, 412, 671, 436);
        AddControl(new ImageButtonControlPane(15, &bounds));

        g_pUserStatusPane->GetNationId();
        m_selectedNationId = static_cast<short>(
            g_gameServerNationTable->GetNationEntryCount() - 1);
        m_categoryPage = 1;

        const GameServerConfig::NationEntry *nationEntry =
            g_gameServerNationTable->GetNationEntryAtOrDefault(m_selectedNationId);
        const unsigned short selectedNationId = nationEntry->nationId;

        InitRectBounds(&bounds, 82, 391, 154, 403);
        AddControl(new StaticTextControlPane(nationEntry->label, 1, 37, 0,
                                             &bounds, false, false));

        const unsigned short reportedCount = PacketBufferReadUInt16BE(packet + 1);
        const unsigned short entryCount = PacketBufferReadUInt16BE(packet + 3);
        const unsigned char initialSort = packet[5];
        const unsigned char *cursor = packet + 6;

        InitRectBounds(&bounds, 379, 388, 469, 432);
        RadioGroupControlPane *sortControl = new RadioGroupControlPane(&bounds);
        AddControl(sortControl);
        InitRectBounds(&bounds, 0, 1, 88, 15);
        sortControl->AddOption(L"", &bounds);
        InitRectBounds(&bounds, 0, 29, 88, 43);
        sortControl->AddOption(L"", &bounds);
        sortControl->SetSelectedIndex(initialSort);

        int left = 16;
        for (int index = 0; index < 5; ++index)
        {
            m_bucketPanes[index] = new UserListPane(sizeof(UserListRecord), 100,
                                                    m_bucketPanes, 5);
            InitRectBounds(&bounds, left, 95, left + 121, 331);
            AddControl(new ScrollableControlPane(&bounds, m_bucketPanes[index],
                                                 0, 0, 0));
            left += 135;
        }

        m_allUserRecords = new List(sizeof(UserListRecord), 100);

        for (unsigned int ordinal = 0; ordinal < entryCount; ++ordinal)
        {
            UserListRecord record;

            unsigned char encoded = *cursor++;
            record.careerId = encoded >> 4;
            record.bucketIndex = encoded & 7;

            encoded = *cursor++;
            record.statusIconId = encoded >> 4;
            record.badgeIconId = encoded & 7;

            encoded = *cursor++;
            record.careerVariant = encoded >> 4;
            record.huntersListFlag = encoded & 7;

            record.displayColor = *cursor++;
            record.arrivalSortKey = 100000 - ordinal;
            record.reserved2 = 0;

            const unsigned char nameLength = *cursor++;
            memmove(narrowName, cursor, nameLength);
            cursor += nameLength;
            narrowName[nameLength] = '\0';

            const int convertedLength = MultiByteToWideChar(
                CP_ACP, 0, narrowName, nameLength, record.name, 256);
            record.name[convertedLength] = L'\0';
            record.hasSourceText = 0;

            if (wcscmp(record.name, localPlayerName) == 0)
            {
                record.displayColor = 0x80;
                m_selectedCareerVariant = record.careerVariant;
            }

            if (record.reserved2 == 0 || playerSettingsFlag == 1)
                m_allUserRecords->Append(1, &record);
            else
                ++filteredCount;
        }

        for (int index = 0; index < m_allUserRecords->GetCount(); ++index)
        {
            UserListRecord *record = static_cast<UserListRecord *>(
                m_allUserRecords->GetElementAt(index));

            if ((g_bShowHuntersListOnly != 1 || record->huntersListFlag != 0) &&
                ((selectedNationId == 10 &&
                  record->careerVariant == m_selectedCareerVariant) ||
                 record->careerId == selectedNationId))
            {
                UserListPane *pane = record->bucketIndex != 0
                    ? m_bucketPanes[record->bucketIndex - 1]
                    : m_bucketPanes[4];
                pane->AddEntry(record);
            }
        }

        left = 89;
        for (int index = 0; index < 5; ++index)
        {
            if (initialSort == 0)
                m_bucketPanes[index]->SortRecords(CompareUserListRecordsByStatus);
            else if (initialSort == 1)
                m_bucketPanes[index]->SortRecords(CompareUserListRecordsByName);

            InitRectBounds(&bounds, left, 344, left + 24, 356);
            swprintf_s(countText, 12, L"%d", m_bucketPanes[index]->GetRecordCount());
            AddControl(new StaticTextControlPane(countText, 1, 37, 0,
                                                 &bounds, false, false));
            visibleCount += m_bucketPanes[index]->GetRecordCount();
            left += 135;
        }

        swprintf_s(countText, 12, L"%d",
                   static_cast<unsigned short>(reportedCount - filteredCount));
        InitRectBounds(&bounds, 176, 419, 248, 431);
        AddControl(new StaticTextControlPane(countText, 1, 37, 0,
                                             &bounds, false, false));

        swprintf_s(countText, 12, L"%d", static_cast<unsigned short>(visibleCount));
        InitRectBounds(&bounds, 176, 391, 248, 403);
        AddControl(new StaticTextControlPane(countText, 1, 37, 0,
                                             &bounds, false, false));

        InitRectBounds(&bounds, 270, 386, 333, 410);
        AddControl(new ImageButtonControlPane(45, &bounds));

        SimpleUString emptyText;
        InitRectBounds(&bounds, 288, 424, 374, 436);
        AddControl(new StaticTextControlPane(emptyText.c_str(), 1, 128, 0,
                                             &bounds, false, false));

        nationEntry = g_gameServerNationTable->GetNationEntryAtOrDefault(
            m_selectedNationId);
        InitRectBounds(&bounds, 83, 391, 155, 403);
        AddControl(new StaticTextControlPane(nationEntry->label, 1, 37, 0,
                                             &bounds, false, false));

        InitRectBounds(&bounds, 7, 386, 70, 410);
        AddControl(new ImageButtonControlPane(44, &bounds));

        InitRectBounds(&bounds, 530, 385, 680, 409);
        AddControl(new CheckBoxTextControlPane(
            g_pUserPane->GetHuntersListFlag() != 0, L"", &bounds));

        InitRectBounds(&bounds, 514, 13, 642, 37);
        AddControl(new CheckBoxTextControlPane(g_bShowHuntersListOnly, L"", &bounds));

        SetBackgroundResource(L"US", 0);
        SetHoverControl(1);
        SetFocusedControl(1);
        SetPendingControl(1);
        SetMode(1);
        InitRectBounds(&bounds, 0, 0, 709, 452);
        OnCreate(&bounds, 0, NULL, g_mainUiLayerSlots.overlayPaneLayerContext);
        OnShow(NULL, NULL);
        SlideOpenVertical();
    }
    else
    {
        InitRectBounds(&bounds, 0, 0, 635, 390);
        AddControl(new EPFImageControlPane(L"USERLIST.EPD", 0, true, &bounds,
                                           L"USERLIST.PAD"));

        InitRectBounds(&bounds, 529, 302, 601, 318);
        AddControl(new ImageButtonControlPane(15, &bounds));

        g_pOldUserStatusPane->GetNationId();
        m_selectedNationId = static_cast<short>(
            g_gameServerNationTable->GetNationEntryCount() - 1);
        m_categoryPage = 1;

        const GameServerConfig::NationEntry *nationEntry =
            g_gameServerNationTable->GetNationEntryAtOrDefault(m_selectedNationId);
        const unsigned short selectedNationId = nationEntry->nationId;

        InitRectBounds(&bounds, 36, 304, 107, 316);
        AddControl(new StaticTextControlPane(nationEntry->label, 1, 37, 0,
                                             &bounds, false, false));

        const unsigned short reportedCount = PacketBufferReadUInt16BE(packet + 1);
        const unsigned short entryCount = PacketBufferReadUInt16BE(packet + 3);
        const unsigned char initialSort = packet[5];
        const unsigned char *cursor = packet + 6;

        InitRectBounds(&bounds, 506, 37, 568, 63);
        RadioGroupControlPane *sortControl = new RadioGroupControlPane(&bounds);
        AddControl(sortControl);
        InitRectBounds(&bounds, 0, 0, 59, 11);
        sortControl->AddOption(L"", &bounds);
        InitRectBounds(&bounds, 0, 16, 59, 26);
        sortControl->AddOption(L"", &bounds);
        sortControl->SetSelectedIndex(initialSort);

        int left = 36;
        for (int index = 0; index < 5; ++index)
        {
            m_bucketPanes[index] = new UserListPane(sizeof(UserListRecord), 100,
                                                    m_bucketPanes, 5);
            InitRectBounds(&bounds, left, 102, left + 110, 282);
            AddControl(new ScrollableControlPane(&bounds, m_bucketPanes[index],
                                                 0, 0, 0));
            left += 113;
        }

        m_allUserRecords = new List(sizeof(UserListRecord), 100);

        for (unsigned int ordinal = 0; ordinal < entryCount; ++ordinal)
        {
            UserListRecord record;

            unsigned char encoded = *cursor++;
            record.careerId = encoded >> 4;
            record.bucketIndex = encoded & 7;

            encoded = *cursor++;
            record.statusIconId = encoded >> 4;
            record.badgeIconId = encoded & 7;

            record.displayColor = *cursor++;
            record.reserved2 = 0;
            record.arrivalSortKey = 100000 - ordinal;

            const unsigned char nameLength = *cursor++;
            memmove(narrowName, cursor, nameLength);
            cursor += nameLength;
            narrowName[nameLength] = '\0';

            const int convertedLength = MultiByteToWideChar(
                CP_ACP, 0, narrowName, nameLength, record.name, 256);
            record.name[convertedLength] = L'\0';

            if (record.reserved2 == 0 || playerSettingsFlag == 1)
            {
                m_allUserRecords->Append(1, &record);

                if (((selectedNationId == 10 &&
                      record.careerVariant == m_selectedCareerVariant) ||
                     record.careerId == selectedNationId) &&
                    record.bucketIndex != 0)
                {
                    m_bucketPanes[record.bucketIndex - 1]->AddEntry(&record);
                }
            }
            else
            {
                ++filteredCount;
            }
        }

        left = 36;
        for (int index = 0; index < 5; ++index)
        {
            if (initialSort == 0)
                m_bucketPanes[index]->SortRecords(CompareUserListRecordsByStatus);
            else if (initialSort == 1)
                m_bucketPanes[index]->SortRecords(CompareUserListRecordsByName);

            InitRectBounds(&bounds, left, 285, left + 110, 297);
            swprintf_s(countText, 12, L"%d", m_bucketPanes[index]->GetRecordCount());
            AddControl(new StaticTextControlPane(countText, 1, 37, 0,
                                                 &bounds, false, false));
            visibleCount += m_bucketPanes[index]->GetRecordCount();
            left += 113;
        }

        swprintf_s(countText, 12, L"%d",
                   static_cast<unsigned short>(reportedCount - filteredCount));
        InitRectBounds(&bounds, 111, 323, 183, 335);
        AddControl(new StaticTextControlPane(countText, 1, 37, 0,
                                             &bounds, false, false));

        swprintf_s(countText, 12, L"%d", static_cast<unsigned short>(visibleCount));
        InitRectBounds(&bounds, 111, 304, 183, 316);
        AddControl(new StaticTextControlPane(countText, 1, 37, 0,
                                             &bounds, false, false));

        InitRectBounds(&bounds, 190, 321, 262, 337);
        AddControl(new ImageButtonControlPane(45, &bounds));

        SimpleUString emptyText;
        InitRectBounds(&bounds, 111, 341, 261, 353);
        AddControl(new StaticTextControlPane(emptyText.c_str(), 1, 128, 0,
                                             &bounds, false, false));

        InitRectBounds(&bounds, 190, 302, 262, 318);
        AddControl(new ImageButtonControlPane(44, &bounds));

        SetBackgroundResource(L"US", 0);
        SetHoverControl(1);
        SetFocusedControl(1);
        SetPendingControl(1);
        SetMode(1);
        InitRectBounds(&bounds, 0, 50, 635, 440);
        OnCreate(&bounds, 0, NULL, g_mainUiLayerSlots.overlayPaneLayerContext);
        OnShow(NULL, NULL);
        SlideOpenVertical();
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R3 - UID0000FQ complete UserPane declaration

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class MapPane;
class SelectObjectWithKeyboardPane;
class UserPane;
struct MapPoint;
struct ServerMessageEvent;

MapPoint *DirectionToTileOffset(
    MapPoint *outOffset, unsigned char direction);
void __stdcall DispatchCopiedEventPayload(
    const void *data, size_t size);

void ToggleTargetSelectionPane(bool alternateMode);
void NavigateTargetSelection(bool previous, bool chooseLocalPlayer);
void ReverseTargetSelectionDirection();
extern bool g_selectObjectTargetModeActive;
extern bool g_targetObjectTargetModeActive;
extern SelectObjectWithKeyboardPane *g_activeSelectObjectWithKeyboardPane;

static bool __stdcall HandleUIPanelSwitchPacket(
    const unsigned char *packet);
static void __stdcall SendDirectionPacket(unsigned char direction);
static void SendOpcode7Command(unsigned char command);
void RefreshGroupMemberMarkers(UserPane *userPane);
void ClearGroupMemberMarkers(UserPane *userPane);

struct GroupMemberRecord
{
    unsigned int memberId;                      // +0x000
    wchar_t name[128];                          // +0x004
    bool active;                                // +0x104
    unsigned short faceId;                      // +0x106
    unsigned char hairId;                       // +0x108
    unsigned char faceColor;                    // +0x109
    unsigned char hairColor;                    // +0x10a
    unsigned char skinColor;                    // +0x10b
    unsigned char bodyColor;                    // +0x10c
    unsigned char helmetId;                     // +0x10d
    unsigned char helmetColor;                  // +0x10e
    unsigned short faceDecorationId;            // +0x110
    unsigned char faceDecorationColor;          // +0x112
    unsigned short hairDecorationId;            // +0x114
    unsigned char hairDecorationColor;          // +0x116
    unsigned short secondFaceDecorationId;      // +0x118
    unsigned char secondFaceDecorationColor;    // +0x11a
    unsigned int maximumHitPoints;              // +0x11c
    unsigned int currentHitPoints;              // +0x120
    unsigned int maximumManaPoints;             // +0x124
    unsigned int currentManaPoints;              // +0x128
};

struct LocalInventorySlotRecord
{
    unsigned char active;
    unsigned char reserved001;
    unsigned short itemId;
    unsigned char iconStyle;
    unsigned char reserved005;
    wchar_t displayName[80];
    wchar_t itemMetaKey[80];
    wchar_t ownerName[80];
    unsigned char reserved1e6[2];
    unsigned int quantityOrCount;
    unsigned char quantityPromptFlag;
    unsigned char reserved1ed[3];
    unsigned int currentDurability;
    unsigned int protectionCount;
    unsigned char targetMode;
    unsigned char reserved1f9[3];
};

struct MovementWaypointSegment
{
    int startX;
    int startY;
    int endX;
    int endY;
};

struct SpellCommandSlotRecord
{
    unsigned char active;
    unsigned char reserved001[3];
    int inputKind;
    unsigned char reserved008[0xa0];
    wchar_t prompt[80];
};

struct LocalMovementHistoryRecord
{
    unsigned char active;
    unsigned char reserved01[3];
    int tileY;
    int tileX;
    unsigned char direction;
    unsigned char reserved0d[3];
};

class UserPane : public LivingObjectPane
{
public:
    enum UserTimerMessage
    {
        kUserPaneMovementStep = 20
    };

    UserPane();
    virtual ~UserPane();

    virtual void OnBoundsChanged(const RectBounds *bounds);
    virtual void OnClipBounds(RectBounds *clip, RectBounds *out);
    virtual void ShowNameLabel();
    virtual void HideNameLabel();
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnServerMessage(const ServerMessageEvent *event);
    virtual bool OnAnimationStep(int message, int frameOrDirection, int aux);
    virtual MapPane *GetMapPane();

    void SendGiveItemPacket(signed char slot, bool allItems);
    void SendDropItemPacket(signed char slot, bool allItems);
    CollectionPlayerDataView &GetCollectionData();
    const CollectionPlayerDataView &GetCollectionData() const;

    unsigned char GetHuntersListFlag() const
    {
        return m_huntersListFlag;
    }

    void SetHuntersListFlag(unsigned char flag)
    {
        m_huntersListFlag = flag;
    }

    wchar_t *GetPartySearchSourceText()
    {
        return m_partySearchSourceText;
    }

    const wchar_t *GetPartySearchSourceText() const
    {
        return m_partySearchSourceText;
    }

    MapPoint *GetViewportPosition(MapPoint *outPosition) const;
    void ProcessMovement(unsigned char direction);
    void InitializeWalkAnimation(unsigned char direction);
    void StartDirectionalAnimation(char direction);
    LocalInventorySlotRecord *GetInventorySlotAddress(char inventorySlot);
    void DispatchConfiguredShortcutHotkey(short hotkeyNumber, int unused);
    void ExecuteHotkeyAction(short hotkey);
    void UseInventorySlot(unsigned char slot);
    void UseCommandSlot(unsigned char slot);
    void TryPerformAction();
    bool WarpToPosition(int x, int y, int viewportColumn, int viewportRow);
    LocalMovementHistoryRecord *GetActiveMovementHistoryRecordByIndex(
        unsigned char recordIndex);
    void ClearAllMovementHistoryRecords();
    void ClearMovementHistoryRecordByIndex(int recordIndex);
    void UpdateScreenPosition();
    void SendMovementPacket(unsigned char direction);
    void TryDispatchFunctionKeyShortcut(
        short functionKeyOrdinal, unsigned int currentTick);
    void CopyDeferredUserListPacket(
        const unsigned char *packetData, size_t packetSize);
    bool ParsePlayerSettingsPacket(const unsigned char *packet);
    bool ParseInventorySlotUpdatePacket(const unsigned char *packet);
    bool HandleServerEntryPacket(const unsigned char *packet);
    bool HandleWarpPacket(const unsigned char *packet);
    bool HandleMovementReplyPacket(const unsigned char *packet);
    bool HandleExtendedMovementReplyPacket(const unsigned char *packet);
    bool HandleChatMessagePacket(const unsigned char *packet);
    bool HandleUserListPacket(const ServerMessageEvent *event);
    bool HandlePositionSyncPacket(const unsigned char *packet);
    bool ParseGroupListPacket(const unsigned char *packet);
    void SendMovementWaypointPacket(
        unsigned char direction, unsigned short token,
        const MovementWaypointSegment *segment);
    void SendFaceDirectionPacket(unsigned char direction);
    void SendAutoFaceDirectionPacket();
    void SendActionPacketWithAutoFace();
    void SendAttackTargetPacket(char direction);
    void BuildInventorySlotRangeText(wchar_t *outText) const;
    void BuildSpellSlotRangeText(wchar_t *outText) const;

private:
    friend class MapPane;
    friend void RefreshGroupMemberMarkers(UserPane *userPane);
    friend void ClearGroupMemberMarkers(UserPane *userPane);

    bool IsGroupMember(unsigned int memberId) const;
    GroupMemberRecord *FindGroupMemberById(unsigned int memberId);
    void AdvanceMovementSendTick();

    SpellCommandSlotRecord *GetSpellCommandSlotRecord(unsigned char slot)
    {
        return &m_spellCommandSlots[slot - 1];
    }

    void ClearMovementHistoryToken()
    {
        m_movementState[2] = 0;
        m_movementState[3] = 0;
    }

    void SetMovementReplyState()
    {
        m_movementState[1] = 1;
        m_movementState[2] = 1;
    }

    bool IsDirectionDelayActive() const
    {
        return m_movementState[4] != 0;
    }

    void SetDirectionDelayActive(bool active)
    {
        m_movementState[4] = active ? 1 : 0;
    }

    unsigned char m_userPaneBaseTail[0x0c];
    GroupMemberRecord m_groupMembers[50];
    signed char m_groupMemberCount;
    unsigned char m_huntersListFlag;
    wchar_t m_partySearchSourceText[256];
    unsigned char m_preCollectionState[2];
    int m_currentSayMode;
    unsigned char m_preCollectionCommandState[2];
    bool m_collectionPanelSoundEnabled;
    unsigned char m_postCollectionCommandState[9];
    int m_localPlayerHitRadius;
    CollectionPlayerDataView m_collectionData;
    int m_screenX;
    int m_screenY;
    unsigned int m_screenState;
    RectBounds m_screenHitBounds;
    RectBounds m_screenLowerHitBounds;
    MapPane *m_mapPane;
    unsigned char m_playerSettingsState[8];
    LocalInventorySlotRecord m_inventorySlots[52];
    SpellCommandSlotRecord m_spellCommandSlots[52];
    bool m_spellCommandSlotsReady;
    unsigned char m_preViewportState[3];
    int m_viewportColumn;
    int m_viewportRow;
    int m_viewportHalfColumns;
    int m_viewportHalfRows;
    int m_viewportRemainingColumns;
    int m_viewportRemainingRows;
    unsigned char m_movementState[5];
    unsigned char m_preActionTickState[3];
    unsigned int m_lastActionTick;
    unsigned int m_lastMapCommandTick;
    unsigned int m_lastGroundItemCommandTick;
    List *m_whisperHistoryOther;
    List *m_outgoingWhisperRecipientHistory;
    List *m_incomingWhisperSenderHistory;
    unsigned char m_whisperHistorySource;
    unsigned char m_preMovementHistory[3];
    LocalMovementHistoryRecord *m_movementHistoryRecords;
    int m_movementHistoryCapacity;
    unsigned char m_movementHistoryWriteIndex;
    bool m_inputLocked;
    unsigned char m_movementHistoryState[2];
    unsigned char *m_deferredUserListPacket;
    size_t m_deferredUserListPacketSize;
    int m_deferredUserListCount;
    unsigned int m_deferredUserListDeadline;
    bool m_deferredUserListActive;
    unsigned char m_preMovementTicks[3];
    unsigned int m_lastMovementSendTick;
    unsigned int m_lastMovementInputTick;
    unsigned char m_actionMode;
    unsigned char m_userPaneTrailingState0;
    bool m_includeAdjacentMovementTargets;
    unsigned char m_userPaneTrailingState2;
    ObjectStatusBlob m_currentAppearance;
};

typedef char GroupMemberRecordSizeMustBe300[
    sizeof(GroupMemberRecord) == 0x12c ? 1 : -1];
typedef char LocalInventorySlotRecordSizeMustBe508[
    sizeof(LocalInventorySlotRecord) == 0x1fc ? 1 : -1];
typedef char SpellCommandSlotRecordSizeMustBe328[
    sizeof(SpellCommandSlotRecord) == 0x148 ? 1 : -1];
typedef char LocalMovementHistoryRecordSizeMustBe16[
    sizeof(LocalMovementHistoryRecord) == 0x10 ? 1 : -1];
typedef char UserPaneSizeMustBe1305476[
    sizeof(UserPane) == 0x13eb84 ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R5 - UID0000FO complete UserListPane declaration

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MouseEvent;
class UserListRecord;

class UserListPane : public ListPane
{
public:
    UserListPane(int recordSize,
                 int pageSize,
                 UserListPane **siblingPanes,
                 int siblingPaneCount);
    virtual ~UserListPane();

    void SortRecords(ListCompareFunction compare);
    int GetRecordCount() const;
    UserListRecord *GetRecordAt(int index);
    UserListRecord *GetSelectedRecord();
    void AddEntry(const UserListRecord *record);
    void SyncSourceText(const UserListRecord *sourceRecord);

    virtual void DrawUserEntry(int itemIndex, const RectBounds *bounds);
    virtual void OnItemSelected(int itemIndex);
    void OpenSayToUserMessageInputPane();
    virtual bool OnDoubleClick(const MouseEvent &event);

private:
    EPFTileContext m_statusIconFrames[4];
    EPFTileContext m_badgeIconFrames[16];
    EPFTileContext m_selectionFrame;
    UserListPane **m_siblingPanes;
    int m_siblingPaneCount;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R6 - UID00047N UserListPane::SyncSourceText

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void UserListPane::SyncSourceText(const UserListRecord *sourceRecord)
{
    const int count = GetRecordCount();

    for (int index = 0; index < count; ++index)
    {
        UserListRecord *record = GetRecordAt(index);

        if (wcscmp(record->name, sourceRecord->name) != 0)
            continue;

        record->hasSourceText = 1;
        wcscpy_s(record->sourceText, 256, sourceRecord->sourceText);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R7 - UID00047C UserListDialogPane::AddUserListSourceMessage

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void UserListDialogPane::AddUserListSourceMessage(const UserListRecord *record)
{
    if (g_pChattingDisplayPane == 0)
        return;

    wchar_t message[256];
    swprintf_s(message, L"%s > %s", record->name, record->sourceText);
    g_pChattingDisplayPane->AddChattingMessage(message, 143, 128, 0, 0, 0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R8 - UID00047R UserListPane::OnDoubleClick

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool UserListPane::OnDoubleClick(const MouseEvent &event)
{
    if (!event.IsLeftDoubleClick() || !ContainsPoint(event.x, event.y))
        return ListPane::OnMouseEvent(event);

    const int itemIndex = HitTestItem(event.x, event.y);
    if (itemIndex < 0)
        return false;

    UserListRecord *record = GetRecordAt(itemIndex);
    if (record == 0 || record->huntersListFlag == 0)
        return false;

    if (record->hasSourceText && g_pUserListDialogPane != 0)
    {
        g_pUserListDialogPane->AddUserListSourceMessage(record);
        return true;
    }

    char name[256];
    const int nameLength = WideCharToMultiByte(CP_ACP, 0, record->name, -1, name, sizeof(name), 0, 0);
    if (nameLength <= 0)
        return true;

    unsigned char packet[258];
    packet[0] = 0x85;
    packet[1] = static_cast<unsigned char>(nameLength - 1);
    memcpy(&packet[2], name, nameLength - 1);
    SendMapPacket(packet, nameLength + 1);
    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

### R9 - UID0003E6 compiler-generated vtable/RTTI data

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

R9 is intentionally blank because R2's inheritance and virtual declarations
are the source cause. Raw COL, RTTI, vtable dwords, adjustors, and destructor
wrappers are compiler output.

## Final Recommendation

C01-C20 and R0-R9 are applied as one report-level callback. The target is
source-ready with no unresolved signature, packet, container, control,
record, helper-linkage, access, local-field, owner, source-route, range, or
formal-C++ blocker. Remaining uncertainty is limited to original private
spellings and protocol enum labels; those caps justify `92/94` rather than
perfect confidence and do not block emission.

## Recommended Target Doc Changes

For UID000477, the accepted changes are implemented:

- Validator-aware UID-preserving rename completed to
  `by-memory/0x0059d620-0x0059d8f5.UserListDialogPaneHandlePacketEvent.md`.
- Current metadata is `COMPLETION:92`, `CONFIDENCE:94`,
  `CANONICAL_OWNER:0000FN`, `RECONSTRUCTABLE:TRUE`, blank optional position,
  `Nested:0`, and `EMITTER_UIDS:0000OZ`.
- Item Summary:
  `Source-authored UserListDialogPane::HandlePacketEvent(Event *) at [0x0059d620,0x0059d8f5): handles 0x83 hunters-list flag/checkbox/local-row synchronization with unconditional RefreshCategoryView(0), handles 0x84 counted ACP target/source text parsing with the protocol-assumed nonempty-list search, cached-row/bucket/chat synchronization, preserves all unchecked malformed-packet behavior, and returns false on every path.`
- R1 is installed exactly, with every C01-C20 target fact incorporated,
  including
  byte/hash/PE/CFG/ABI/vtable/range/padding/negative/historical evidence.

## Recommended Support Doc Changes

### UserListDialogPane source family

- UID0001KI: implemented `90/91 -> 91/92`; retained owner UID0000OZ, false,
  blank emitter/position/R0, and `Nested:0`. Added the renamed target and
  UID000478 links, exact predecessor/successor padding, member-helper
  corrections, vtable no-code disposition, and preserved every unrelated
  child/table/raw/compiler fact.
- UID0000FN: implemented `93/94 -> 94/95`; installed R2 exactly, closed before
  `[[CHILDREN]]`, retained exact 0x28c layout/Singleton EBO, and historicalized
  PacketEventContext, HandleUserListPacket, OnKeyEvent, and free helper
  declarations.
- UID0000OZ: implemented `92/93 -> 93/94`; replaced target/helper inventory and
  source order with the corrected members, preserved reusable checkbox,
  PartySearch, no-route raw, compiler, resource, and all unrelated source
  facts.
- UID000478: validator-aware UID-preserving rename completed to
  `by-memory/0x0059d900-0x0059da82.UserListDialogPaneHandleKeyOrTextEvent.md`;
  retained `86/90`, owner UID0000FN, true, blank emitter/position/formal and
  `Nested:0`; replaced stale signature/title/interface prose without claiming
  its separate body is reconstructed.
- UID00047C: validator-aware UID-preserving rename completed to
  `by-memory/0x0059de60-0x0059decf.UserListDialogPaneAddUserListSourceMessage.md`;
  current metadata is `90/93`, owner UID0000FN, emitter UID0000OZ, true,
  blank position, `Nested:0`, and R7; exact chat/format/compiler-wrapper
  evidence is preserved.
- UID00047N: validator-aware UID-preserving rename completed to
  `by-memory/0x0059e9f0-0x0059ea8f.UserListPaneSyncSourceText.md`; current
  metadata is `90/93`, owner UID0000FO, emitter UID0000OZ, true, blank
  position, `Nested:0`, and R6; free linkage and `_wcsicmp` are historicalized.
- UID00047R: implemented `87/90 -> 89/92`, retained metadata/range/route, installed R8
  exactly, and preserved all double-click/request behavior.
- UID0000FO: implemented `91/92 -> 92/93`, retained owner/emitter UID0000OZ and
  layout, installed R5 exactly, and preserved all unrelated methods/fields.
- UID0003E6: current state is `90/94`, owner UID0000FN,
  `RECONSTRUCTABLE:FALSE`, blank emitter/position/R9, `Nested:0`, complete
  Item Summary and table/RTTI/slot/source-cause evidence; the exact
  range and CheckBox successor.
- UID00026U: ordinary page remained unchanged at same-or-greater detail,
  `88/92`, NONE owner, false/non-emitting with blank formal. Its read-only
  manual row remains stale and the exact corrected handoff is retained below.

### UserPane local-state support

- UID0000FQ: implemented `93/94 -> 94/95`; rebased R3 on the complete current
  shared union with only four inline accessors and the exact three-field split.
  Every existing B001/B002/B003/B004/B005 method, field, friend,
  record, declaration, class closure, `[[CHILDREN]]`, position 10, owner,
  emitter, and `sizeof(UserPane)==0x13eb84` guard.
- UID0000P1: implemented `92/93 -> 93/94`; added exact local-state/accessor and
  UserListDialogPane consumer/source-route prose without pruning its complete
  current shared union.
- UID000470: retained `93/94` and all current metadata/evidence; installed R4
  exactly, changing only the first-checkbox source expression from opaque
  `m_preCollectionState[0]` to `GetHuntersListFlag()`.
- UID00047B: retained `87/91`, NONE owner, blank emitter/position/formal and
  no-route conclusion. Replaced only opaque offset wording with the typed flag,
  source-text buffer, and accessor source model while preserving every route
  negative and raw behavior.
- UID0000QK and UID0001OR: scores/formals/routes unchanged; documented exact
  typed `m_huntersListFlag` and `m_partySearchSourceText[256]` fields and
  historical aliases without changing singleton storage.
- PartySearch UID0000A7, UID00047D, and UID00047G: scores/formals/routes
  unchanged; synchronized reads/writes to the typed UserPane accessors in prose
  and preserved their independent incomplete class/body debt.

### Verify-only dependencies

UID00004L Event (`D18D26AB...F95B`), UID00004N EventHandler
(`38033240...9EB1`), UID0002ZX g_bShowHuntersListOnly
(`E25D60FA...FA25`), UID00026U UserListReadOnlyData
(`E33F7815...53D29`), CheckBoxTextControlPane (`687F5307...E62`), ListPane
(`89C81412...19A`), and List source support (`0C951825...118C`) were reread
without contradiction and remain unchanged. UID000475 RefreshCategoryView
retains its score/formal/body and current hash `A5ACA15A...5231`; only the
validator-owned rename-link propagation was accepted and scoped-validated by
command 14630. WideString, packet send/conversion APIs, chatting display,
UserListRecord fields, compiler helpers, resource pages, and unrelated
UserList/UserPane children were also reread with no scope-broadening
contradiction.

### Exact support Item Summaries

- UID0001KI:
  `MCP-reviewed non-emitting social user-list split index over exact UserListDialogPane/UserListPane source methods, reusable checkbox overlap, corrected member helpers/comparators, switch tables, parent-owned padding, no-route raw/wrapper code, globals, Singleton support, and compiler destructor/adjustor artifacts; exact child ranges and aggregate no-code proof preserved.`
- UID000478:
  `UserListDialogPane::HandleKeyOrTextEvent(Event *) at [0x0059d900,0x0059da82) handles PageUp/PageDown category navigation and Ctrl+C selected-name copy across five UserListPane children, otherwise forwarding to the inherited key/text handler; secondary slot +0x08 corrects the stale OnKeyEvent/KeyEvent interface while formal C++ remains blank.`
- UID00047C:
  `Source-authored UserListDialogPane::AddUserListSourceMessage member at [0x0059de60,0x0059decf): checks the chatting display, formats one 256-wide "name > sourceText" line from UserListRecord, and emits it with exact 143/128 style constants; member ABI is proved by both ECX-seeded callers despite an optimized body that does not read this.`
- UID00047N:
  `Source-authored UserListPane::SyncSourceText member at [0x0059e9f0,0x0059ea8f): scans the pane records with case-sensitive wcscmp, marks every matching row as having source text, and securely copies the 256-wide source text from the source UserListRecord.`
- UID00047R:
  `UserListPane::OnDoubleClick handles exact left-double-click, bounds, row, and hunters-list gates; cached source text is dispatched through g_pUserListDialogPane->AddUserListSourceMessage, otherwise the selected name becomes outbound opcode 0x85 source-request payload.`
- UID0003E6:
  `Exact compiler-generated UserListDialogPane primary/secondary/tertiary COL and vtable lead-in at [0x0062e8fc,0x0062e998), including secondary HandlePacketEvent slot +0x10, constructor/destructor stores, and CheckBoxTextControlPane successor; R2 is the source cause and raw arrays remain non-emitting.`

## Score And Metadata Recommendation

| Destination | Gate 1 baseline | Implemented | Rationale and cap |
| --- | --- | --- | --- |
| UID000477 | 86/90 | 92/94 | exact body/signature/owner/route/range complete; enum/private spelling caps |
| UID0001KI | 90/91 | 91/92 | index gains exact source/helper/padding/vtable dispositions; broad mixed range caps |
| UID0000FN | 93/94 | 94/95 | complete coherent class interface; private spelling cap |
| UID0000OZ | 92/93 | 93/94 | complete emitting family/source order; original packaging cap |
| UID0000FO | 91/92 | 92/93 | exact member helper declaration closes class surface; local naming cap |
| UID00047N | 88/91 | 90/93 | member ABI and case sensitivity resolved; original name cap |
| UID00047C | 88/91 | 90/93 | member ABI and exact body/callers resolved; original name/access cap |
| UID00047R | 87/90 | 89/92 | cached member call corrected; broader mouse API naming cap |
| UID0003E6 | 85/90 | 90/94 | exact table/RTTI/slot/compiler source cause; no human data source |
| UID0000FQ | 93/94 | 94/95 | exact local-state layout/access closure with size preserved; private names cap |
| UID0000P1 | 92/93 | 93/94 | source route now names exact fields/accessors; broad file history cap |

UID000470, UID000478, UID00047B, UID0000QK, UID0001OR, PartySearch support,
Event/EventHandler, checkbox, globals, and unrelated pages retain current
scores. A higher target completion would require recovered original enum/private
spellings; a lower score would ignore exact body and interface closure.

## Open Questions With Attempted Resolution

| Question | Routes checked | Resolution and impact |
| --- | --- | --- |
| Is the target a direct packet helper or virtual event method? | sole xref, EventHandler secondary table, ABI | virtual `HandlePacketEvent(Event *)`; closed |
| Does recognized input return true? | all CFG exits/epilogue | no, every path returns false; closed |
| Is control 0x14 the hunters-only filter? | constructor creation order, control 0x15 command, checkbox docs | no; it is local participation checkbox; closed |
| Should SetChecked absorb invalidation? | exact setter body | no; separate invalidation is required; closed |
| Is `0x00575470` a packet helper? | body and 975 refs | no; char-traits lowering, direct byte source; closed |
| Is 0x84 search safely count-bounded? | exact loop CFG | no; protocol assumes target exists; preserve unsafe loop; closed |
| Are Sync/Add free helpers? | ECX setup, both Add callers, retn widths | both are members; closed |
| Is Sync case-insensitive? | callee import/call target | no, exact `wcscmp`; closed |
| What are UserPane +0x3cb1/+0x3cb2? | all readers/writers, extents, downstream offset | flag plus wchar_t[256], two residual bytes; closed |
| How can private state be accessed across files? | caller/source graph and no out-of-line xrefs | public inline accessors are strongest source model; lexical access cap remains |
| Should target split or absorb padding/table? | exact bytes/hashes/boundaries | no split; predecessor/successor dispositions preserved |
| Should vtable bytes emit? | compiler source cause/R2 | no; false/blank no-code support; closed |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

B003 does not edit manual coverage. Supervisor commands 14639-14641 externally
applied and validated the exact accepted handoff, address-order rebased with
current neighbors. Post-application read-only snapshots are:

- `by-memory/-coverage-report.md`: SHA256
  `A5CA20135DA4A42D86CB731DF82707EFF8A3DEFDED9DA6ABB586ADEB8C776A44`,
  1,799,251 bytes, 4,295 lines, validated externally by command 14639.
  UID0001KI is line 3398; UID000477/UID000478 are lines 3401/3402;
  UID00047C/UID00047N/UID00047R are lines 3404/3405/3406. UID00026U and
  UID0003E6 are current at lines 3962/3963. The earlier absent-row/current-delta
  wording is historical pre-command-14639 state.
- `by-class/-coverage-report.md`: SHA256
  `63AD4E29536BBFB5445517DB7DA3C4E9CB844102F25D9143379F70975F0051D6`,
  233,032 bytes, 623 lines, validated externally by command 14640.
  UID0000FN/FO/FQ remain at lines 584/585/587 and now carry the exact accepted
  `94/92/94` completion rows. The former pre-callback/current-delta wording is
  historical.
- `by-file/-coverage-report.md`: SHA256
  `0D039B7BAC0625BEB91C743FA72C5AA74EC5B06C6EB82267908DFA2B91734B06`,
  133,275 bytes, 316 lines, validated externally by command 14641.
  UID0000OZ/P1 remain at lines 295/297 and now carry the exact accepted
  `93/93` completion rows. The former pre-callback/current-delta wording is
  historical.
- `by-global/-coverage-report.md`: SHA256
  `0C8B5B0120EB85CCAF20FC91D2D133199A56ED757CC414F98F114198F7141238`,
  90,135 bytes, 212 lines. Read-only comparison found the existing UID0002ZX
  row already exact and no score/path delta applies to UID0000QK or
  UID0001OR; no B003 replacement is required there.
- `by-type/by-struct/-coverage-report.md`: SHA256
  `3B602846F676F11D8211BF0E95A1F30D64EF7480FB74C5DA4E57502FBC29E87E`,
  57,065 bytes, 137 lines. No manual structure row is changed; the layout
  change is within UserPane's complete class declaration rather than the
  CollectionPlayerDataView type.

The exact text blocks below are retained verbatim as the historical B003
handoff that the supervisor applied through commands 14639-14641. Current
readback confirms each row is present without loss; B003 neither performed nor
claims the coverage edits:

```text
    - [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md) 0x0059bc90-0x0059f25b | non-emitting split index | UserListDialogPaneAndUserListPane : ignored : 91% : very-strong : Exact mixed social user-list index over source-ready UserListDialogPane/UserListPane methods, reusable checkbox overlap, member helpers/comparators, switch tables, parent-owned padding, no-route wrappers, Singleton/compiler artifacts, globals, and deleting/adjustor support; UID000477 is exact HandlePacketEvent(Event *), UID000478 is HandleKeyOrTextEvent(Event *), and source emits only from exact children/classes.
        - [UID:000477][0x0059d620-0x0059d8f5.UserListDialogPaneHandlePacketEvent](by-memory/0x0059d620-0x0059d8f5.UserListDialogPaneHandlePacketEvent.md) 0x0059d620-0x0059d8f5 | virtual method | UserListDialogPane::HandlePacketEvent : reconstructable : 92% : very-strong : Exact 725-byte EventHandler packet override with adjusted-this ABI, always-false return, 0x83 hunters-list flag/checkbox/local-row synchronization and unconditional RefreshCategoryView(0), 0x84 counted ACP target/source parsing with the exact protocol-assumed search, row/bucket/chat synchronization, complete human C++, exact padding/table exclusions, and UserListDialogPane.cpp emission.
        - [UID:000478][0x0059d900-0x0059da82.UserListDialogPaneHandleKeyOrTextEvent](by-memory/0x0059d900-0x0059da82.UserListDialogPaneHandleKeyOrTextEvent.md) 0x0059d900-0x0059da82 | virtual method | UserListDialogPane::HandleKeyOrTextEvent : reconstructable : 86% : strong : Secondary EventHandler slot +0x08 proves mutable Event * key/text override; PageUp/PageDown category navigation, Ctrl+C selected-name behavior, and base forwarding remain documented while exact standalone body C++ stays blank.
        - [UID:00047C][0x0059de60-0x0059decf.UserListDialogPaneAddUserListSourceMessage](by-memory/0x0059de60-0x0059decf.UserListDialogPaneAddUserListSourceMessage.md) 0x0059de60-0x0059decf | member method | UserListDialogPane::AddUserListSourceMessage : reconstructable : 90% : very-strong : Both callers and retn 4 prove a UserListDialogPane member whose optimized body checks chatting display, formats one 256-wide `name > sourceText` line, and emits exact 143/128 style constants.
        - [UID:00047N][0x0059e9f0-0x0059ea8f.UserListPaneSyncSourceText](by-memory/0x0059e9f0-0x0059ea8f.UserListPaneSyncSourceText.md) 0x0059e9f0-0x0059ea8f | member method | UserListPane::SyncSourceText : reconstructable : 90% : very-strong : Exact UserListPane member scans its records with case-sensitive wcscmp, marks matching rows as having source text, and securely copies the 256-wide source text.
        - [UID:00047R][0x0059ee10-0x0059efd0.UserListPaneOnDoubleClick](by-memory/0x0059ee10-0x0059efd0.UserListPaneOnDoubleClick.md) 0x0059ee10-0x0059efd0 | virtual method | UserListPane::OnDoubleClick : reconstructable : 89% : very-strong : Exact left-double-click/inside/hit/row gates, cached source-text dispatch through g_pUserListDialogPane member API, otherwise ACP name conversion and outbound 0x85 source request, with complete human C++.
```

The following historical address-order handoff is now applied: UID00026U and
UID0003E6 are current at lines 3962/3963 immediately before UID0002OX:

```text
    - [UID:00026U][0x0062e8fc-0x0062eccc.UserListReadOnlyData](by-memory/0x0062e8fc-0x0062eccc.UserListReadOnlyData.md) 0x0062e8fc-0x0062eccc | mixed vtable/string-data aggregate | UserListReadOnlyData : ignored : 88% : very-strong : Exact non-emitting user-list read-only-data parent beginning at the UserListDialogPane primary COL/vtable, with exact UserListDialogPane, CheckBoxTextControlPane, PartySearchEditPane, UserListPane, and resource-string children before the UserLook boundary; declarations and resource references regenerate source, so the mixed parent remains false with blank formal.
        - [UID:0003E6][0x0062e8fc-0x0062e998.UserListDialogPaneVtableData](by-memory/0x0062e8fc-0x0062e998.UserListDialogPaneVtableData.md) 0x0062e8fc-0x0062e998 | compiler vtable/RTTI data | UserListDialogPaneVtableData : ignored : 90% : very-strong : Exact primary/secondary/tertiary COL and vtable lead-in with HandlePacketEvent at secondary +0x10, constructor/destructor stores, CheckBoxTextControlPane successor boundary, and source-declared/generated-binary blank-formal disposition; raw arrays do not emit.
```

Historical class handoff, now externally applied exactly:

```text
- [UID:0000FN][UserListDialogPane](by-class/UserListDialogPane.md) : reconstructable : 94% : very-strong : Complete Singleton<UserListDialogPane> plus DialogPane social user-list class with exact 0x28c layout, packed UserListRecord, source-ready constructor/RefreshCategoryView/HandlePacketEvent, exact mutable Event overrides, five UserListPane buckets, member AddUserListSourceMessage, packet/filter/resource/category/sort/count behavior, compiler singleton/vtable separation, and UserListDialogPane.cpp ownership.
- [UID:0000FO][UserListPane](by-class/UserListPane.md) : reconstructable : 92% : very-strong : Complete 0x49c UserListPane declaration over ListPane with exact frame banks, sibling pane state, list APIs, case-sensitive SyncSourceText member, rendering/selection/double-click methods, exact children, and retained no-route/compiler exclusions.
- [UID:0000FQ][UserPane](by-class/UserPane.md) : reconstructable : 94% : very-strong : Complete 0x13eb84 local-player UserPane declaration with exact movement/packet/server inventory, external ProcessMovement and event helper declarations, corrected viewport half/remaining column/row fields, movement-history records, corrected opcode-0x13 movement-target sender, signed plain-char StartDirectionalAnimation(char direction) with signed-short frame-duration/MonsterObject image-table and signed non-monster scaled-delay contracts, 52 exact 508-byte inventory records with displayName/itemMetaKey/ownerName, quantityOrCount, quantityPromptFlag, currentDurability, protectionCount, and targetMode fields, MapPane friendship, action mode, exact +0x13eb3e adjacent-target bool split, exact player-settings semantics comprising state[0] feature/UI mode, state[2] viewport-threshold mode, state[3] direction mode, state[4] MapPane-render blindness with bounds invalidation, and state[5]/[6] chat display/send restriction levels, the distinct movement-state index-3 pending-reply flag versus index-4 direction-delay state, source-ready opcode-0x05 HandleServerEntryPacket declaration, exact EventHandler HandleKeyOrTextEvent(Event *) override, six resolved B003 target/helper declarations, preserved current B002 UID0004R9 child, int say-mode/collection-panel-sound/three-debounce/input-lock field splits, exact 0x20c base boundary, class closure before child definitions, exact records/size guards, preserved full unrelated field/record/layout/source surface, exact final-byte plus 68-byte m_currentAppearance tail used by MapPane local-player status updates, and UID0003UB's retained ExecuteHotkeyAction(short) declaration plus exact three-page 30-row Text/Spell/Item runtime behavior; the complete Config declaration exposes direct macro and compact tables; UID0003UA emits exact retained compact-shortcut source while UID0003UB's earlier blank-formal artifact remains separate historical debt rather than a current Config blocker; retains exact private IsGroupMember(unsigned int) const and AdvanceMovementSendTick() declarations over the existing signed group count, GroupMemberRecord table, movement tick, TimerMgr, and BowGauge state; adds exact +0x3cb1 hunters-list flag, +0x3cb2 wchar_t[256] party-search source text, two residual bytes, and four inline cross-source accessors in place of only the former opaque 0x203-byte slice.
```

Historical file handoff, now externally applied exactly:

```text
- [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md) : reconstructable : 93% : very-strong : Source-ready social UserListDialogPane.cpp family with complete dialog/list declarations, exact constructor/category refresh/HandlePacketEvent, corrected Event interface, member source-text synchronization/chat helpers, packed row and hunters/source protocol behavior, resources, Singleton backing lifecycle, exact split/padding inventory, and retained no-route/compiler/reusable-control exclusions.
- [UID:0000P1][UserPane](by-file/UserPane.md) : reconstructable : 93% : very-strong : NexusTK/ui/panels/UserPane.cpp source root with complete UserPane class/method families, exact ProcessMovement direction/effect/packet/history/event behavior, retained waypoint/facing inline-equivalent helpers, corrected helper declarations, signed plain-char StartDirectionalAnimation(char direction) with signed-short MonsterObject frame-duration image-table/group/frame path, signed non-monster scaled-delay arithmetic, event-20 scheduling, branch-specific ordering, and branch-local MapPane refresh, corrected opcode-0x13 movement-target sender using MapPane collect/sort with exact count-versus-nine cap/local terminator behavior, preserved action/adjacent-target fields, packet ABI, movement-history, server, target, and caller evidence, source-ready opcode-0x0f ParseInventorySlotUpdatePacket using signed one-based slots, three explicit ACP text conversions, the exact 508-byte inventory record with displayName/itemMetaKey/ownerName, quantityOrCount, quantityPromptFlag, currentDurability, protectionCount, and targetMode fields, active UserStatusPane slot-count bound, exact write order, and preserved invalid-slot/always-false behavior, source-ready opcode-0x08 settings parsing with exact state indices, 2/31 offset arithmetic, packet cursor/store order, blindness invalidation, movement-state/TryStepForward order, ten ordered direct config stores, SoundManager enable/mirror order, active GeneralPurposePanel child-6 OnActivate refresh, and adjacent movement-reply index-3 versus index-4 corrections, source-ready opcode-0x05 HandleServerEntryPacket with duplicated EPF/legacy SpelledPane refresh, sender re-enable, transfer-overlay deferred deletion, object/facing/status-icon application, MapPane bounds refresh, and block/listen replay, plus exact HandleKeyOrTextEvent(Event *) entry gates/modifier and key switches/handled returns/packet order and source body, two slot-range methods, opcode-7 sender, current B002 UID0004R9 preservation, target-selection cross-TU declarations, compiler switch/vtable exclusions, retained raw/inline-equivalent history, exact source order, no UID0003V9 empty emitter or duplicate body, UID0003UB's exact source position, three-page caller route, 30-row Text/Spell/Item behavior, helper/packet dependencies, retained UID0000FQ emitter route, complete Config table declarations, exact retained UID0003UA compact-shortcut source, and exact final-byte plus 68-byte m_currentAppearance tail used by MapPane; UID0003UB's earlier blank-formal artifact remains separate historical debt rather than a current Config blocker; retains exact private IsGroupMember and AdvanceMovementSendTick definitions with class closure, source order, and compiler exclusions; adds typed +0x3cb1 hunters-list flag, +0x3cb2 wchar_t[256] party-search source text, two residual bytes, and inline accessors without changing the 0x13eb84 layout or any prior source union fact.
```

No exact manual row for UID000470, UID00047B, UID0000QK, UID0001OR,
UID0002ZX, PartySearch, Event/EventHandler, or checkbox support needs a score,
path, reconstructability, or source-description replacement beyond the
ordinary prose changes above.

## Follow-Up Actions

The bounded C01-C20/R0-R9 ordinary implementation, scoped validation, formal
parity check, generated readback, supervisor-applied manual-row readback,
checklist reconciliation, and lease release are complete. No B003
implementation item remains. Commands 14639-14641 are external supervisor
coverage actions, not B003 work. Report validation/execution/count/path and any
move/archive state remain external supervisor/validator-owned facts; this
artifact neither asserts nor directs a future lifecycle result. B003 itself
ran no execute, report probe/count, move, archive, or lifecycle command.

## Confidence

Overall recommendation confidence is **94/100**. Range, bytes, ABI, return,
vtable slot, branch order, record/control fields, helper member linkage,
source route, and compiler exclusions are direct. The residual six points are
the absence of original symbols for packet enum names, UserPane private field
spellings, and access labels; the selected descriptive forms are coherent and
do not alter behavior or layout.

## Validator Results

Every changed ordinary page received a scoped validator from canonical
`source-3/project-documentation` while that page alone was leased. All commands
exited `0` with `ok:1`; all leases were released immediately. Validator
warnings were the pre-existing `missing_ref_uid`/project projected-stat
warnings where emitted. Scoped runs deferred generated refresh until the final
authorized waited command.

| Command | Timestamp EDT | Scoped destination | Exit/ok | Side effects and result |
| --- | --- | --- | --- | --- |
| 14599 | 2026-07-19T19:08:21-04:00 | UID000477 renamed target | 0/1 | UID path/score/emitter/formal registry updated; six ordinary references propagated; generated refresh deferred. |
| 14600 | 2026-07-19T19:09:17-04:00 | UID000478 renamed target | 0/1 | UID path and dependent references updated; score/formal retained; refresh deferred. |
| 14601 | 2026-07-19T19:09:58-04:00 | UID00047C renamed member | 0/1 | UID path/owner/score/emitter/R7 and links updated; refresh deferred. |
| 14602 | 2026-07-19T19:10:39-04:00 | UID00047N renamed member | 0/1 | UID path/owner/score/emitter/R6 and links updated; refresh deferred. |
| 14603 | 2026-07-19T19:11:29-04:00 | UID0003E6 vtable data | 0/1 | Previously missing UID mapping registered; 90/94 false/blank no-code disposition accepted. |
| 14604 | 2026-07-19T19:11:57-04:00 | UID00047R OnDoubleClick | 0/1 | 89/92 and exact R8 accepted; refresh deferred. |
| 14605 | 2026-07-19T19:12:33-04:00 | `by-class/UserListPane.md` | 0/1 | 92/93 and exact R5 accepted; refresh deferred. |
| 14606 | 2026-07-19T19:13:37-04:00 | UID0001KI parent | 0/1 | 91/92, blank R0, renamed inventory and padding/no-code evidence accepted. |
| 14607 | 2026-07-19T19:14:58-04:00 | `by-class/UserListDialogPane.md` | 0/1 | 94/95 and exact R2 accepted; class closure preserved before children. |
| 14608 | 2026-07-19T19:16:13-04:00 | `by-file/UserListDialogPane.md` | 0/1 | 93/94 corrected source inventory accepted; refresh deferred. |
| 14609 | 2026-07-19T19:16:42-04:00 | UID000470 constructor | 0/1 | Exact R4 accessor correction accepted with 93/94 unchanged. |
| 14610 | 2026-07-19T19:17:16-04:00 | UID00047B raw helper | 0/1 | Typed-state prose accepted; 87/91 NONE/no-route/blank formal retained. |
| 14611 | 2026-07-19T19:18:21-04:00 | `by-global/g_pCollectionData.md` | 0/1 | Typed +0x3cb1/+0x3cb2 support accepted; score/formal retained. |
| 14612, 14613 | 2026-07-19T19:18:54/19:19:19-04:00 | UID0001OR memory global | 0/1 each | Typed support accepted; second scoped pass restored the explicit UID00047B reverse reference; final page is no-loss. |
| 14616 | 2026-07-19T19:20:43-04:00 | `by-class/PartySearchEditPane.md` | 0/1 | Typed accessor prose accepted; independent class debt and score/formal retained. |
| 14617 | 2026-07-19T19:21:14-04:00 | UID00047D constructor | 0/1 | Typed accessor support accepted; score/formal/body unchanged. |
| 14618 | 2026-07-19T19:21:38-04:00 | UID00047G action | 0/1 | Typed accessor support accepted; score/formal/body unchanged. |
| 14620 | 2026-07-19T19:22:29-04:00 | `by-class/UserPane.md` | 0/1 | 94/95 exact R3 accepted over complete shared union; size guard retained. |
| 14624, 14626 | 2026-07-19T19:24:23/19:24:52-04:00 | `by-file/UserPane.md` | 0/1 each | 93/94 source support accepted; second scoped pass corrected two residual stale current-score statements without union loss. |
| 14630 | 2026-07-19T19:27:43-04:00 | UID000475 RefreshCategoryView | 0/1 | Validator-propagated renamed-target link accepted; score/formal/body unchanged. |
| 14631 | 2026-07-19T19:27:51-04:00 | UID0000L4 WideFormatWrapper256 | 0/1 | Validator-propagated UID00047C member link accepted; score/formal/body unchanged. |
| 14632 | 2026-07-19T19:28:17-04:00 | final waited `by-file/UserListDialogPane.md` | 0/1 | `generated_refresh: completed`; registry rebuild 5,098 nodes/4,091 edges and 280 metadata refreshes. Existing global warnings were 13 fallback inserts, 85 missing child markers, and 142 emitters without code; none is a UID000477 failure. |

No validator was run by B003 during this report-only reconciliation. The
supervisor separately applied and validated manual coverage as follows:

| External command | Current read-only root | Exit/ok | Current SHA256 |
| --- | --- | --- | --- |
| 14639 | `by-memory/-coverage-report.md` | supervisor-confirmed pass | `A5CA20135DA4A42D86CB731DF82707EFF8A3DEFDED9DA6ABB586ADEB8C776A44` |
| 14640 | `by-class/-coverage-report.md` | supervisor-confirmed pass | `63AD4E29536BBFB5445517DB7DA3C4E9CB844102F25D9143379F70975F0051D6` |
| 14641 | `by-file/-coverage-report.md` | supervisor-confirmed pass | `0D039B7BAC0625BEB91C743FA72C5AA74EC5B06C6EB82267908DFA2B91734B06` |

These external commands changed no ordinary destination hash or R0-R9 body.
Generated UserListDialogPane/UserPane readback remains the command-14635 epoch
and hashes recorded below.

### Formal parity

Managed bodies were extracted after all validators and compared byte-for-byte
with the accepted report. Lengths exclude marker lines and the final line
separator.

| Formal | Equal | Length | SHA256 of managed body |
| --- | --- | ---: | --- |
| R0 | yes | 0 | `E3B0C44298FC1C149AFBF4C8996FB92427AE41E4649B934CA495991B7852B855` |
| R1 | yes | 2906 | `99F301D20558A93F4018056C484A665ED8F20E317DBEC00430E76A5970468325` |
| R2 | yes | 2012 | `CF8CA41CB23C6BE26E69AC65B973E9A457B432FAA6F8FBAC6D402D108C0C458E` |
| R3 | yes | 10200 | `42E4477AF91EE6443DAAD9B342D879476209DFA2748037659FA3575655120487` |
| R4 | yes | 13179 | `5F45A15471F5C7A325F66EB28207874D91C2CC8ECB16C82AF3BBA21DD2509E95` |
| R5 | yes | 977 | `49BD93BABFF5B373F01226402D0E5B4F05C5046C89BF0E830D215BAB506790EC` |
| R6 | yes | 414 | `4257CA016A81B8EB364D9A58F76C754AFB476E4D1685583B4F56E6A2ADF85F66` |
| R7 | yes | 310 | `29C9EDDFB04E4593EFEA5347F325B2C82639A953FFAB6D5E5AA91518A8F2FA81` |
| R8 | yes | 961 | `F70F59912831DE4DE67D3D370B229E50602EDB2E2E2AB876A343C231FC397EDB` |
| R9 | yes | 0 | `E3B0C44298FC1C149AFBF4C8996FB92427AE41E4649B934CA495991B7852B855` |

### Generated readback

B003's waited command 14632 was followed by read-only validator-owned command
14635 at `2026-07-19T19:29:41-04:00`; the later header is an external epoch,
not a B003 lifecycle assertion. At that checkpoint:

- `auto-generated/NexusTK/social/UserListDialogPane.cpp` is SHA256
  `BED42F020622CFCF06508A44E2FBF9F4566ADB8D0A75CDE67049D9EB3A32754E`,
  29,013 bytes, 822 lines. UserListDialogPane closes at line 78,
  UserListPane closes at line 113, and definitions begin at line 122. R1/R7/R6/R8
  occur exactly once at lines 582/718/747/788, each with one matching UID
  provenance row. The exact target path/address occurs once; the four former
  path/title names, `PacketEventContext`, and the old long Sync name occur zero
  times. UID000477 and UID0003E6 Empty Emitter Markers are zero. Raw vtable,
  RTTI, cookie, EH, and range-check artifacts are zero. R6 uses exact
  case-sensitive `wcscmp`; the one `_wcsicmp` belongs only to unrelated
  UID00047K `CompareUserListRecordsByName`. The two remaining Empty Emitter
  Markers are unrelated UID0000A7 PartySearchEditPane and UID0003EI Singleton
  backing-storage debt.
- `auto-generated/NexusTK/ui/panels/UserPane.cpp` is SHA256
  `E2573B71A3816CCE65EC1EFEC0EC67AFF7288ECE4499B1B4D8B46323B4B58F4D`,
  91,869 bytes, 2,759 lines. The class opens at line 135, closes at line 314,
  and qualified definitions begin at line 328. `GetHuntersListFlag`,
  `SetHuntersListFlag`, and the mutable/const `GetPartySearchSourceText`
  declarations occur 1/1/2 times. `m_huntersListFlag`,
  `m_partySearchSourceText`, `m_preCollectionState[2]`, and the exact
  `sizeof(UserPane) == 0x13eb84` guard are present; the old
  `m_preCollectionState[0x203]` is absent. The sole remaining Empty Emitter
  Marker is unrelated UID0003UB and is not claimed by this callback.

## Changed Files

The following ordinary pages are the exact callback-time changed set. Hashes
are terminal readbacks after their scoped validation; automatic rename-link
propagation pages are labeled.

| Current path | SHA256 | Bytes/lines | Proof |
| --- | --- | ---: | --- |
| `by-memory/0x0059d620-0x0059d8f5.UserListDialogPaneHandlePacketEvent.md` | `D301D0FA10987C9CF927B7490FF9E737156FFE456777462F2D4DF5753D6E0AAC` | 10,745/165 | 14599 |
| `by-memory/0x0059d900-0x0059da82.UserListDialogPaneHandleKeyOrTextEvent.md` | `07921F5E793512202644BF93E277499E6B2B0AC64161947857A85E1FEA248646` | 3,333/42 | 14600 |
| `by-memory/0x0059de60-0x0059decf.UserListDialogPaneAddUserListSourceMessage.md` | `069B615269EEA87E6F490B9C722E8C00757C9EC9D2C48A5BD2C620476D008080` | 4,776/57 | 14601 |
| `by-memory/0x0059e9f0-0x0059ea8f.UserListPaneSyncSourceText.md` | `4C292F4035AC604E97F1369A39B823F43EE8BA9EC3440A72700A9F4B79704157` | 3,341/56 | 14602 |
| `by-memory/0x0062e8fc-0x0062e998.UserListDialogPaneVtableData.md` | `2BDC1CD36424B8C073922A4583B09C9EFE192FBA3969D311E0168C8E616E1595` | 7,611/73 | 14603 |
| `by-memory/0x0059ee10-0x0059efd0.UserListPaneOnDoubleClick.md` | `D5105E925F8805C71599EE403D8B8981A3A1B5343672913A0F4DA4FF4129C134` | 4,159/78 | 14604 |
| `by-class/UserListPane.md` | `51E733CC40E8FD6387DBA150E9E1A58B1859CC9185A0BBF11DAFC617238E4541` | 13,121/123 | 14605 |
| `by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md` | `EAAE33E16A2407EC92B748D40776A931896A89E2D6CAEACF3602DA1E3D21D6AC` | 47,805/279 | 14606 |
| `by-class/UserListDialogPane.md` | `C0AB2E8E4DE4C0645BCB66E40EF962FAFEADA3B4341035AB1897E32243027FD4` | 32,625/276 | 14607 |
| `by-file/UserListDialogPane.md` | `29A234C10CBF09E8AE78FEB1E5FFD33FA605FD2485B9AA10F458EF99D5321D11` | 30,304/155 | 14608 and waited 14632 |
| `by-memory/0x0059bc90-0x0059d198.UserListDialogPaneConstructor.md` | `1A5E90289EEC807601F898D6975F86BF9BD27D2AB352D304CF05CD044F8B1644` | 21,638/402 | 14609 |
| `by-memory/0x0059dc20-0x0059de4a.UserListDialogPaneLocalSourceUpdateSendHelperRaw.md` | `D20FA79F3ADFB64864298436D911577B6D217FD94A9B06A009BEA68A349D6276` | 10,157/89 | 14610 |
| `by-global/g_pCollectionData.md` | `FAE7836E8909304EFEDF9AF8C84B10C34D2DBE458E458CA077DE459276124607` | 25,545/177 | 14611 |
| `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md` | `CB10BD11D3336A9E520271CCB47391B067FCE95B0A4F57A87E6BF0607469A321` | 31,054/273 | 14612/14613 |
| `by-class/PartySearchEditPane.md` | `2F9344CD8A9A17095F64DF6C05C08669D081BEB730BBE4E186089B7DCC76EB20` | 12,292/84 | 14616 |
| `by-memory/0x0059e0d0-0x0059e393.PartySearchEditPaneConstructor.md` | `4DC46EDD67E6C065DBC36CF2E747BBCC7B29067783C8292AB6A164A3BEB47BA7` | 3,292/41 | 14617 |
| `by-memory/0x0059e3d0-0x0059e707.PartySearchEditPaneOnAction.md` | `7259A57BF7DB4B1D4A59C45A21A06A804228C8359A28447E9E53127B3C1E8940` | 3,601/48 | 14618 |
| `by-class/UserPane.md` | `DCF54C6D782D0EB1428FA7D678FA082D7E624FBF57C7517C2468F12AFEA84525` | 88,951/658 | 14620 |
| `by-file/UserPane.md` | `B250082C8EE067FB89BCDE991982732F6C1A00EC6E30B2B187A390267313423C` | 102,016/413 | 14624/14626 |
| `by-memory/0x0059d2b0-0x0059d5fe.UserListDialogPaneRefreshCategoryView.md` | `A5ACA15A35FC661724B2CCC5A5160FDE4CEA4BEEB4F72F9272B63BA1A5385231` | 14,652/236 | validator rename-link propagation only; 14630 |
| `by-memory/0x0045ef20-0x0045ef50.WideFormatWrapper256.md` | `951B1B63842B4528B38D92C3772D7E158FEEC2AC09B15FDC4DBDB4C5C0FDB80F` | 13,467/120 | validator rename-link propagation only; 14631 |

The report itself is the only artifact B003 changed during this final
report-only reconciliation. Manual coverage changed externally through
supervisor commands 14639-14641; B003 manually changed no ordinary, generated,
manual coverage, tracker, stats, audit/supervisor, validator
registry/queue/lock, IDA, lifecycle, or archive file. Generated C++ remains
the read-only command-14635 checkpoint. Zero B003 leases remain.

## Implementation Tracking Checklist

- [x] Rechecked the accepted report hash, lease ledger, ordinary destination hashes, generated headers, and manual coverage roots before callback edits.
- [x] Determined callback-time MCP revalidation was not required because the accepted mandatory evidence remained coherent and no valid bounded-call failure occurred.
- [x] Applied C01 with exact healthy-session evidence to target/support docs.
- [x] Applied C02 exact target range/size/hash/PE/function metadata.
- [x] Applied C03 adjusted-this ABI, Event pointer, return, stack, and compiler-shape evidence.
- [x] Applied C04 validator-aware target and UID000478 renames plus EventHandler interface history.
- [x] Applied C05 exact 0x83 byte/global/control/setter/invalidation sequence.
- [x] Applied C06 exact bounded row loop and per-iteration local-name temporary behavior.
- [x] Applied C07 exact RefreshCategoryView placement and 0x84 exclusion.
- [x] Applied C08 exact two counted ACP string parses and signed-short termination behavior.
- [x] Applied C09 compiler range/cookie/EH exclusions without adding guards.
- [x] Applied C10 exact protocol-assumed nonempty-list search with no index bound.
- [x] Applied C11 exact row update, bucket mapping, member Sync/Add order.
- [x] Applied C12 always-false return and complete negative-guard inventory.
- [x] Applied C13 UID00047N member/case-sensitive rename, R6, class/file links, and score.
- [x] Applied C14 UID00047C member rename, R7/R8, class/file links, and score.
- [x] Applied C15 exact UserPane field split and every ordinary support reference.
- [x] Applied C16 four inline accessors, R3/R4/R1 use, exact class size, and no-loss shared union.
- [x] Applied C17 owner/emitter/source route/position/Nested metadata.
- [x] Applied C18 no-split padding/table ownership and UID0003E6 compiler-data reclassification.
- [x] Applied C19 R0-R9 exactly with no C++ outside managed blocks or raw compiler artifacts.
- [x] Applied C20 all score/history/manual/generated/checklist/lifecycle detail.
- [x] Leased, reread, edited, scoped-validated, and immediately released the UID000477 rename destination.
- [x] Leased, reread, edited, scoped-validated, and immediately released UID0001KI.
- [x] Leased, reread, edited, scoped-validated, and immediately released UID0000FN.
- [x] Leased, reread, edited, scoped-validated, and immediately released UID0000OZ.
- [x] Leased, reread, edited, scoped-validated, and immediately released the UID000478 rename destination.
- [x] Leased, reread, edited, scoped-validated, and immediately released the UID00047C rename destination.
- [x] Leased, reread, edited, scoped-validated, and immediately released the UID00047N rename destination.
- [x] Leased, reread, edited, scoped-validated, and immediately released UID00047R.
- [x] Leased, reread, edited, scoped-validated, and immediately released UID0000FO.
- [x] Leased, reread, edited, scoped-validated, and immediately released UID0003E6.
- [x] Leased, reread, rebased the complete shared union, edited, scoped-validated, and immediately released UID0000FQ.
- [x] Leased, reread, rebased the complete shared union, edited, scoped-validated, and immediately released UID0000P1.
- [x] Leased, reread, edited, scoped-validated, and immediately released UID000470.
- [x] Applied bounded prose-only synchronization to UID00047B, UID0000QK, UID0001OR, and PartySearch support and validated every changed page.
- [x] Reread all verify-only dependencies; UID000475 had only validator-owned rename-link propagation and no direct contradiction broadened scope.
- [x] Ran the accepted final waited generated refresh after all ordinary validators and lease releases.
- [x] Proved current UserListDialogPane.cpp target/member/name/count/ordering/no-marker/no-raw-compiler assertions.
- [x] Proved current UserPane.cpp exact field/accessor/size/no-loss assertions.
- [x] Recorded every validator command ID, timestamp, exit, ok count, warnings, side effects, generated header freshness, file hash, and lease release.
- [x] Updated C01-C20 to legal terminal callback states with destination-specific proof.
- [x] Reread the exact supervisor-applied manual coverage rows and commands 14639-14641, reconciled their current hashes/positions, and made no B003 coverage edit.
- [x] Checked every checklist row after independent truth, recorded changed/verify-only/forbidden sets, and confirmed zero B003 leases.
- [x] Reconciled Current State, recommendations, Validator Results, Changed Files, generated proof, and durable external lifecycle wording in this same report.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000014643","destination_path":"executed-b-agent-research/B003/000477-UserListDialogPaneHandleUserListPacket-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/000477-UserListDialogPaneHandleUserListPacket-source-quality.md","timestamp":"2026-07-19T19:58:43-04:00","uid":"000477"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
