** TARGET-REPORT-UID:0003VR **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# 0003VR TextDialog OnControlCommand Source Quality Research


## Finalized Report / Current Recommendation

[UID:0003VR] is an exact source-authored `TextDialog::OnControlCommand(int controlIndex, int notifyCode)` body, not a generic free helper named `HandleDialogAction`. The method is stored in the `TextDialog` primary vtable at slot `+0x48`, the same slot documented as `DialogPane::OnControlCommand`, and it uses the inherited `PursuitMessageDialogPane` packet fields and navigation methods without adding `TextDialog` instance fields.

The former empty-emitter state was not justified. The accepted implementation now places insertion-ready first-draft C++ in the target `CPP` channel while keeping the target `H` channel blank because the exact declaration belongs once in the class parent [UID:0000EL]. The class parent emits the `TextDialog` declaration and source includes; [UID:0003VR] emits only its own method definition. Implemented metadata is `COMPLETION:93`, `CONFIDENCE:94`, with owner/emitter routing preserved.

The initial Gate 1 artifact was report-only. Under the accepted same-agent implementation callback, B009 applied and scoped-validated the ordinary by-* changes and verified the protected raw island without changing it. The supervisor subsequently completed Gate 2B, manual coverage, and generated closure, including IDA catalog item `0398`, saved-IDB evidence, manual validators `000000020704` through `000000020706`, and generated refresh `000000020707`. B009 did not perform those supervisor-owned actions. Lifecycle/archive authority remains solely the report's current path plus validator-owned status/history metadata; commands `000000020708` and `000000020709` are retained below only as historical incident facts.

## Supporting Research

This pass combines the current target, owner/support documents, current generated output, current research tracker and manual coverage rows, executed TextDialog/Pursuit research, and a live read-only IDA MCP pass against the NexusTK IDB.

The central reconstruction is constrained by four independent evidence families:

1. vtable identity: `0x006229a0` is primary-vtable slot `+0x48` and contains `0x00553180`;
2. class contract: `DialogPane` documents slot `+0x48` as `OnControlCommand(int,int)` and exposes `CloseDialog()` plus child-control access;
3. body behavior: the function switches on the first integer argument, handles control indices 1 through 4, and never reads the second integer argument;
4. packet/class state: the submit branch consumes inherited offsets `+0x26c`, `+0x270`, `+0x274`, and `+0x276`, matching the exact `PursuitMessageDialogPane` layout.

No Wave2/Wave3 framing is used. Any old references to those labels are historical workflow residue and do not affect the current source-quality conclusion.

## Target

- UID: `0003VR`
- Primary document: `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md`
- Exact range: `[0x00553180, 0x00553338)`
- Current IDA function: `TextDialog_OnControlCommand`; historical B009 prestate name: `sub_553180`
- Resolved source identity: `TextDialog::OnControlCommand(int controlIndex, int notifyCode)`
- Canonical owner: [UID:0000EL] `by-class/TextDialog.md`
- Emitter: [UID:0000EL]
- Source root: [UID:0000OL] `by-file/TextDialog.md`
- Non-emitting aggregate index: [UID:0001FJ] `TextDialogCore`
- Adjacent raw island: [UID:0003VS] `[0x00553350,0x00553495)`, outside this target and protected from reclassification here

## Current Target State

### Accepted Gate 1 pre-implementation snapshot (historical)

- Target metadata was `87/92`, owner/emitter `0000EL`, reconstructable true, with blank formal CPP/H.
- Class support was `88/92` with blank formal CPP/H.
- File support was `89/90`.
- The tracker showed direct/additional/total report coverage `0/0/0`, and generated TextDialog output contained an empty-emitter marker.
- The target prose still used historical `HandleDialogAction` terminology and treated resolved lexical questions as formal-code blockers.
- IDA lacked a `TextDialog` UDT and retained `sub_553180` and `sub_49DAD0`; these are historical prestates, not current IDA names.

### Reconciled ordinary-document and supervisor closure state

- [UID:0003VR] is `93/94`, preserves owner/emitter `0000EL`, contains the accepted formal CPP, and keeps H blank with exact class-owned proof.
- [UID:0000EL] is `90/93` and contains the accepted class CPP/H declaration, inheritance, layout, and dependency surface.
- [UID:0000OL] is `90/92` and records the source-ready method and source-placement inventory.
- [UID:0001FJ] remains an `88/90` non-emitting split index with exact child dispositions.
- [UID:0003VS] remains `88/90`, no owner, nonreconstructable, and non-emitting; its boundary/no-route claims and protected IDA state were preserved.
- Supervisor Gate 2B catalog item `0398` records `TextDialog` UDT ordinal `970`, direct base `PursuitMessageDialogPane` ordinal `736`, size `632`/`0x278`, and zero own members.
- IDA now names/types/comments `0x00553180` as `TextDialog_OnControlCommand` and `0x0049dad0` as `DialogPane_CloseDialog` with the exact accepted signatures/comments. Accepted table, alignment, vtable-slot, and four case comments were applied; raw-island, parent-vtable, and range-failure-tail protections were verified unchanged.
- The supervisor saved the IDB at SHA-256 `4C7FC9741A1D11FB3DB28F8B29B13ED952C5817A7F6418B6B8E05EDC839CAB85`, 143193448 bytes, last write `2026-08-01 10:19:57`.
- Manual coverage claims C3VR-077 through C3VR-080 were supervisor-applied; validators `000000020704`, `000000020705`, and `000000020706` each exited 0 with `ok: 1`.
- Generated refresh `000000020707` at `2026-08-01 10:21:37` produced one UID0003VR definition, one declaration, zero target empty markers, and tracker/coverage state matching target `93/94`, class `90/93`, file `90/92`, aggregate `88/90`.
- Lifecycle commands `000000020708` and `000000020709` are historical execution/de-execution-for-rework incident facts only. Current execution/archive truth is authoritative solely from the report's path and validator-owned history.
## Executive Recommendation

1. The source identity is implemented in ordinary documentation and current IDA as `TextDialog::OnControlCommand` / `TextDialog_OnControlCommand`; `sub_553180` is retained only as historical prestate provenance.
2. [UID:0003VR] contains the accepted insertion-ready formal `CPP` and deliberately blank `H`.
3. [UID:0000EL] contains the exact class declaration, inheritance, includes, layout constraints, and child insertion point; IDA catalog item `0398` records the matching ordinal-970 UDT.
4. [UID:0000OL] and [UID:0001FJ] record the resolved source placement, method role, and emitted-child disposition.
5. [UID:0003VS] and all protected IDA artifacts remain unchanged.
6. Implemented scores are [UID:0003VR] `93/94`, [UID:0000EL] `90/93`, [UID:0000OL] `90/92`, and [UID:0001FJ] `88/90`.
7. The supervisor completed the accepted IDA, manual coverage, and generated operations. B009's role in this reconciliation is limited to making the report body accurately describe those verified supervisor facts.
8. Report lifecycle authority remains supervisor/validator-owned and is not inferred from ordinary prose.
## Supervisor Active Recheck

The exact SHA `B72EB508CA36ADD9E29E4CB8C82BB0CE777A2FAC964D804BDA701622786FE505` passed the supervisor's fresh full Gate 1 audit at `33/33` before the ordinary callback. B009 then applied the accepted ordinary documentation, after which the supervisor completed Gate 2B, manual coverage, and generated verification with the exact evidence recorded in this repaired report.

Supervisor Gate 2B closure is catalog item `0398`; the saved IDB is SHA-256 `4C7FC9741A1D11FB3DB28F8B29B13ED952C5817A7F6418B6B8E05EDC839CAB85`, 143193448 bytes, last write `2026-08-01 10:19:57`. Manual validators are `000000020704` through `000000020706`; generated refresh is `000000020707` at `10:21:37`.

Historical lifecycle incident: the supervisor used command `000000020708` once, then the mandatory postarchive audit detected stale pending/current-state wording and fail-closed returned the report for repair with command `000000020709`. These commands do not state current lifecycle status. The report's current path and validator-owned history are the only authority for current execution/archive truth.

Any later physical drift must be reconciled additively. A changed hash alone is not permission to discard valid research or overwrite newer supported facts.
## Inference Research Guidance Check

The inference requirement was applied to all unresolved source-facing questions instead of preserving compiler-generated labels:

- Historical `sub_553180` was replaced first in source documentation and then by the supervisor in IDA with `TextDialog_OnControlCommand`, based on the exact virtual slot and base contract.
- first parameter is `controlIndex`; second is `notifyCode`, not generic `a2/a3`, because the inherited virtual declaration fixes both semantics even though `notifyCode` is unused here.
- control 1 is the submit/edit control route; controls 2, 3, and 4 are previous, next, and current navigation routes. Numeric control indices remain because no symbolic resource identifiers were recovered.
- child index 6 is a `TextEditControlPane`, proved by the immediate `ReadText(wchar_t*,short)` call.
- source uses human names (`text`, `convertedText`, `packet`, `convertedLength`, `packetLength`) rather than stack-offset labels.
- packet fields use established inherited names and established packet-writer helper names.
- the compiler range-check helper and security-cookie machinery are not handwritten into human source; normal compiler settings must regenerate them.

The remaining uncertainty concerns exact historical lexical spellings and include order, not behavior, ABI, ownership, source placement, or draft-code eligibility.

## Heuristic / Inference Reanalysis And Validation

### Method name and ABI

`0x00553180` has no ordinary code callers. Its sole inbound reference is the `TextDialog` vtable cell at `0x006229a0`. The vtable begins at `0x00622958`; therefore the cell is slot `+0x48`. Current `DialogPane` documentation independently assigns slot `+0x48` to `virtual void OnControlCommand(int controlIndex, int notifyCode)`. The function returns with `retn 8`, switches on the first explicit argument, and does not use the second. This combination makes `TextDialog::OnControlCommand(int,int)` substantially stronger than the old descriptive `HandleDialogAction` name.

### Child control and command indices

Case 1 loads `this->m_controlManager` at `+0x1fc`, requests child index `6`, and immediately calls `TextEditControlPane::ReadText` with capacity `255`. This proves the child type and edit-input role. No resource symbol gives an original constant spelling, so the source-safe representation is `GetChild<TextEditControlPane>(6)` with the exact numeric index preserved. Cases 2, 3, and 4 directly invoke the inherited previous, next, and current packet helpers. No evidence supports invented symbolic command names.

### Text conversion

The function reads up to 255 wide characters into a 256-element buffer, scans to the wide terminator, truncates the count to one byte, and calls `WideCharToMultiByte` with code page `0`, flags `0`, a 256-byte destination, and null default-character parameters. Because `ReadText` caps the content at 255, the one-byte source length preserves the complete accepted text. The converted count is range-checked before indexing the 256-byte array.

### Packet construction

The packet is 512 bytes. The exact transmitted shape is:

| Offset | Width | Meaning |
|---:|---:|---|
| `+0` | 1 | opcode `0x3a` |
| `+1` | 1 | inherited `m_dialogType` |
| `+2` | 4 | inherited `m_dialogId`, big endian |
| `+6` | 2 | inherited `m_dialogState`, big endian |
| `+8` | 2 | inherited `m_dialogPageIndex + 1`, big endian |
| `+10` | 1 | text-submit subtype `2` |
| `+11` | 1 | converted byte length |
| `+12` | N | converted bytes |

The sent length is `convertedLength + 12`. The function writes local terminators after both converted text and assembled packet, but neither terminator is included in the transmitted length. The 512-byte packet index is range-checked before the local terminator store.

### Close behavior

At the historical B009 prestate, case 1 sent then called `sub_49DAD0`; cases 2 through 4 called their navigation helper and converged on the same close routine. Live decompilation showed `0x0049dad0` queues the pane to `g_pApplicationCleanupQueue` through `BlackHole__QueuePaneForDeferredDeletion`, and current `DialogPane` documentation exposes this source operation as `CloseDialog()`. Supervisor Gate 2B renamed and typed the function as `DialogPane_CloseDialog`. Default performs no operation and returns without closing.

### Adjacent raw island

The target ends exactly at the four-entry jump table boundary `0x00553338`. The jump table occupies `[0x00553338,0x00553348)`, followed by eight `0xcc` bytes through `0x00553350`. The separate raw island starts at `0x00553350`. It is not a tail block of this virtual method and must not be absorbed into this emitter.

## Evidence Standards Used

- Exact machine-code behavior outranks existing prose when they differ.
- Independent vtable/class-contract evidence is required before replacing a compiler-generated function name.
- Source-facing inference must choose the most probable human name and shape; uncertainty is documented rather than leaked as `sub_`, `dword_`, or stack-offset names into final source.
- Draft C++ must preserve every observed branch, field width, endian conversion, length rule, conversion argument, send length, and close/no-close route.
- Compiler-generated security/range machinery is modeled through source constructs and expected build settings, not copied as reverse-engineered helper calls.
- Ownership, emitter placement, and header/source placement are evaluated independently.
- Negative evidence may cap confidence but does not erase positive body/vtable/layout evidence.
- The historical report-only phase did not mutate ordinary destinations; the accepted callback changed only the named ordinary by-* files and this report, while lifecycle state remained supervisor-owned.

## Evidence Checked

### Accepted Gate 1 pre-implementation documentation identities (historical snapshot)

| File | SHA-256 | Bytes | Lines | Relevant state |
|---|---|---:|---:|---|
| `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` | `72322B718E9BE998D031323B7B5F8E902DAE82729B438D336C61A45AEDCDC12A` | 5092 | 57 | target `87/92`, blank CPP/H |
| `by-class/TextDialog.md` | `EA557B22B31DA485C9A1E1CEC24FD84DC50C569E592AD9520C494F804FC72093` | 8516 | 80 | owner `88/92`, blank CPP/H |
| `by-file/TextDialog.md` | `EEE194AB2D17B1631A937C7ED04ED8208C930413C525BED12FD1102F3B88CD1B` | 11470 | 88 | source root `89/90` |
| `by-memory/0x00552110-0x005534a0.TextDialogCore.md` | `AA9BC5895385D3B7742C1A0EFC2CF57143A4CBBE0A66CF37F76AD72B62AEC479` | 7346 | 65 | non-emitting split index `88/90` |
| `by-memory/0x00553350-0x00553495.TextDialogUnreferencedSubmitPacketRaw.md` | `41D1245FB75974874B60D3A3CEDE552CDA7CADADC7215742DDCF1270A9C7652A` | 13095 | 130 | separate no-route raw island `88/90` |
| `by-memory/0x00622954-0x006229f0.TextDialogVtableData.md` | `C91F98CD9A1B406D7F5A527277CC80F40784FE4D4F8993C3640C0A8622787AB6` | 2142 | 37 | exact TextDialog vtable data |
| `by-memory/-coverage-report.md` | `8498F2C5BBEF65FDC6C845CA9677A660C9B70E6A8967077C745568F26F1221BA` | 2152540 | 4839 | physical parent/target rows 3087/3089 |
| `by-class/-coverage-report.md` | `7CD0EB799663BFEC9BFE97CAB1EF97E5471FA1C6DF0550ADE441C4C6E277B657` | 275271 | 625 | physical class row 549 |
| `by-file/-coverage-report.md` | `AD149A2E365381FF8A7AA47F5D84DA8AB94951352A5D559D332C184796798CE6` | 166568 | 319 | physical file row 284 |

### Callback-reconciled physical identities (2026-08-01)

| File | SHA-256 | Bytes | Lines | Verified callback state |
|---|---|---:|---:|---|
| `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` | `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE` | 13131 | 180 | applied `93/94`, owner/emitter `0000EL`, accepted CPP, blank class-owned H |
| `by-class/TextDialog.md` | `AB94E00C3C10D0BF89DB0F03217A40AAC9CAD48E4002EDD53A92C9A3D7249E7B` | 12001 | 122 | applied `90/93`, accepted class CPP/H |
| `by-file/TextDialog.md` | `D2404230BD80EF207AB6FEE7A655CBE97719DAF71B0DD2A785F66F459ECA3F4F` | 14429 | 106 | applied `90/92`, source-ready method/dependency inventory |
| `by-memory/0x00552110-0x005534a0.TextDialogCore.md` | `75F46C453A4EDC6CA459236BDF514B59327A2D3E1500422B459C446DD0FCFC3A` | 9838 | 72 | applied child-disposition wording; preserved `88/90` non-emitting aggregate |
| `by-memory/0x00553350-0x00553495.TextDialogUnreferencedSubmitPacketRaw.md` | `41D1245FB75974874B60D3A3CEDE552CDA7CADADC7215742DDCF1270A9C7652A` | 13095 | 130 | already present; byte-identical protected no-route/non-emitting state |

### Additional support read

- `by-class/DialogPane.md`: virtual slot and child/close API.
- `by-class/PursuitMessageDialogPane.md`: exact inherited field layout and navigation declaration.
- `by-class/TextEditControlPane.md`: exact `ReadText` contract.
- `by-memory/0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md`: exact previous/next/current bodies.
- `by-memory/0x00552110-0x0055317a.TextDialogConstructor.md`: exact constructor body and four wrapper boolean combinations.
- current command `000000020714` generated output: `auto-generated/NexusTK/ui/dialogs/TextDialog.cpp` contains one emitted [UID:0003VR] `TextDialog::OnControlCommand` definition and zero UID0003VR target empty markers; `TextDialog.h` contains the class declaration; only [UID:0003VQ] retains an empty-emitter marker.
- current `auto-generated/-ag-research-tracker.md`: confirms [UID:0003VR] direct/additional/total coverage all zero.
- executed TextDialog-family reports from B001, B004, B007, B010, and B012: retained as provenance and cross-checks, not treated as a substitute for fresh reads.

### Live IDA MCP evidence

- Endpoint: `http://127.0.0.1:13337/mcp`
- MCP protocol/server: current `ida-pro-mcp` tool set was checked before use.
- Active database session: `b3b2bf88`
- IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Worker PID observed: `18860`
- Analysis state: active and not analyzing
- One broad `tools/list` attempt exceeded its bounded timeout while the service was busy; a short wait and bounded retry succeeded. Subsequent IDB-backed calls completed, so this was busy-service evidence, not an offline-MCP fallback.
- Read-only tools used: `lookup_funcs`, `inspect_items`, `get_comments`, `analyze_function`, `decompile`, xref/caller data, disassembly, byte reads, vtable/type queries, and bounded item inspection.
- No IDA mutation or database save was performed.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C3VR-001 | 0003VR | Range is exactly `[0x00553180,0x00553338)`. | exact | Target metadata, function boundary bytes, and MCP function range agree. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Target / range analysis | incorporate | applied |
| C3VR-002 | 0003VR | IDA models one function at `0x00553180`, size `0x1b8`. | exact | Fresh `lookup_funcs`/`analyze_function` on session `b3b2bf88`. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: IDA facts | incorporate | applied |
| C3VR-003 | 0003VR | `sub_553180` was the historical B009 IDA prestate, not final/current source identity. | exact | Historical prestate named `sub_553180`; supervisor Gate 2B catalog item `0398` renamed it to `TextDialog_OnControlCommand` with the exact accepted signature/comment. | B009 callback and supervisor Gate 2B -> target historical IDA provenance/current IDA disposition | historicalize | applied |
| C3VR-004 | 0003VR | Source identity is `TextDialog::OnControlCommand(int,int)`. | very strong | TextDialog primary-vtable cell `+0x48` points to the target; DialogPane documents slot `+0x48` as `OnControlCommand`. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Behavior / source identity | incorporate | applied |
| C3VR-005 | 0003VR | The TextDialog primary vtable begins at `0x00622958`. | exact | Current RTTI/vtable page and MCP item/xref readback agree. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Vtable evidence | incorporate | applied |
| C3VR-006 | 0003VR | Cell `0x006229a0` is vtable offset `+0x48` and stores `0x00553180`. | exact | Fresh 4-byte vtable-cell item/xref readback. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Vtable evidence | incorporate | applied |
| C3VR-007 | 0003VR | `DialogPane` slot `+0x48` is `OnControlCommand`. | very strong | Current `by-class/DialogPane.md` virtual contract. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Source identity rationale | incorporate | applied |
| C3VR-008 | 0003VR | The ABI is `__thiscall` with two explicit `int` arguments and `retn 8`. | exact | Fresh prototype, frame, decompile, and disassembly. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: ABI | incorporate | applied |
| C3VR-009 | 0003VR | The first explicit argument is `controlIndex`. | very strong | The function switches exclusively on current decompiler argument `a2`; inherited declaration supplies the semantic name. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Signature / behavior | incorporate | applied |
| C3VR-010 | 0003VR | The second explicit argument is unused `notifyCode`. | very strong | Current decompile declares `a3` but has no use; inherited declaration supplies the semantic name. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Signature / behavior | incorporate | applied |
| C3VR-011 | 0003VR | Control index 1 is the text-submit route. | exact | Switch case 1 enters at `0x005531be` and performs ReadText, conversion, packet build, send, and close. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Control inventory | incorporate | applied |
| C3VR-012 | 0003VR | Control index 2 sends the previous-dialog packet. | exact | Case entry `0x005531aa` directly calls `PursuitMessageDialogPane_SendPreviousDialogPacket`. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Control inventory | incorporate | applied |
| C3VR-013 | 0003VR | Control index 3 sends the next-dialog packet. | exact | Case entry `0x005531b4` directly calls `PursuitMessageDialogPane_SendNextDialogPacket`. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Control inventory | incorporate | applied |
| C3VR-014 | 0003VR | Control index 4 sends the current-dialog packet. | exact | Case entry `0x00553316` directly calls `PursuitMessageDialogPane_SendCurrentDialogPacket`. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Control inventory | incorporate | applied |
| C3VR-015 | 0003VR | The default switch route performs no work and returns without closing. | exact | Fresh CFG/decompile and return blocks. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Control inventory | incorporate | applied |
| C3VR-016 | 0003VR | `m_controlManager` is read at inherited offset `+0x1fc`. | exact | Instruction at submit path reads `this+508`; DialogPane UDT ordinal 471 places `m_controlManager` at `0x1fc`. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Object layout | incorporate | applied |
| C3VR-017 | 0003VR | Child index 6 is fetched from the control manager. | exact | Immediate 6 at `0x005531c6` before child lookup. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Child-control behavior | incorporate | applied |
| C3VR-018 | 0003VR | Child 6 is used as `TextEditControlPane`. | very strong | Immediate result is passed to exact `TextEditControlPane_ReadText`. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Child-control behavior | incorporate | applied |
| C3VR-019 | 0003VR | `ReadText` receives capacity 255. | exact | Literal call argument in disassembly/decompile. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Text acquisition | incorporate | applied |
| C3VR-020 | 0003VR | The wide input buffer contains 256 `wchar_t` elements. | exact | Fresh stack frame and decompiler local `WCHAR WideCharStr[256]`. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Local-buffer model | incorporate | applied |
| C3VR-021 | 0003VR | The converted buffer contains 256 bytes. | exact | Fresh stack frame and decompiler local `CHAR MultiByteStr[256]`. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Local-buffer model | incorporate | applied |
| C3VR-022 | 0003VR | The packet aggregate contains 512 bytes. | very strong | Contiguous packet locals span 512 bytes and are guarded against index `>=0x200`. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Local-buffer model | incorporate | applied |
| C3VR-023 | 0003VR | Wide input is scanned to its null terminator. | exact | Fresh decompile/disassembly shows `wcslen`-equivalent scan. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Text conversion | incorporate | applied |
| C3VR-024 | 0003VR | Wide length is passed to conversion as an unsigned byte. | exact | `movzx eax, bl` at `0x00553281` and decompiler `unsigned __int8 v5`. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Text conversion | incorporate | applied |
| C3VR-025 | 0003VR | `WideCharToMultiByte` uses code page `CP_ACP`/0. | exact | Literal first call argument 0. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Text conversion | incorporate | applied |
| C3VR-026 | 0003VR | `WideCharToMultiByte` uses flags 0. | exact | Literal second call argument 0. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Text conversion | incorporate | applied |
| C3VR-027 | 0003VR | Conversion destination capacity is 256. | exact | Literal `cbMultiByte` argument 256. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Text conversion | incorporate | applied |
| C3VR-028 | 0003VR | Default-character and used-default-character pointers are null. | exact | Final two API call arguments are zero. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Text conversion | incorporate | applied |
| C3VR-029 | 0003VR | Converted length is checked below 256 before local terminator indexing. | exact | Branch to range-failure tail when result is `>=0x100`. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Compiler protections | incorporate | applied |
| C3VR-030 | 0003VR | Packet length is checked below 512 before local terminator indexing. | exact | Branch to range-failure tail when `convertedLength+12 >=0x200`. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Compiler protections | incorporate | applied |
| C3VR-031 | 0003VR | Packet offset `+0` is opcode `0x3a`. | exact | Literal PacketBufferWriteUInt8 call. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Packet layout | incorporate | applied |
| C3VR-032 | 0003VR | Packet offset `+1` is inherited `m_dialogType`. | exact | Read from `this+0x26c`; Pursuit UDT names the byte. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Packet layout | incorporate | applied |
| C3VR-033 | 0003VR | Packet offsets `+2..+5` are big-endian `m_dialogId`. | exact | Read from `this+0x270` into UInt32BE writer. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Packet layout | incorporate | applied |
| C3VR-034 | 0003VR | Packet offsets `+6..+7` are big-endian `m_dialogState`. | exact | Read from `this+0x274` into UInt16BE writer. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Packet layout | incorporate | applied |
| C3VR-035 | 0003VR | Packet offsets `+8..+9` are big-endian `m_dialogPageIndex + 1`. | exact | Read from `this+0x276`, add 1, then UInt16BE writer. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Packet layout | incorporate | applied |
| C3VR-036 | 0003VR | Packet offset `+10` is subtype 2. | exact | Literal PacketBufferWriteUInt8 call. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Packet layout | incorporate | applied |
| C3VR-037 | 0003VR | Packet offset `+11` is converted byte length. | exact | Conversion result is narrowed into UInt8 writer at packet byte 11. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Packet layout | incorporate | applied |
| C3VR-038 | 0003VR | Packet offset `+12` begins converted bytes. | exact | MemmoveWrapper destination begins at packet aggregate byte 12. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Packet layout | incorporate | applied |
| C3VR-039 | 0003VR | Payload copy uses the project `MemoryMan::MemmoveWrapper` route. | exact | Fresh decompile resolves GetMemoryMan then MemoryMan_MemmoveWrapper. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Packet assembly | incorporate | applied |
| C3VR-040 | 0003VR | Sent length is `convertedLength + 12`. | exact | Exact queue call argument after add 12. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Packet send | incorporate | applied |
| C3VR-041 | 0003VR | The converted-text local terminator is not transmitted. | exact | Terminator is local; transmitted source begins at packet and length excludes it. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Length semantics | incorporate | applied |
| C3VR-042 | 0003VR | The packet local terminator is not transmitted. | exact | Terminator is written at index packetLength while queue receives packetLength. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Length semantics | incorporate | applied |
| C3VR-043 | 0003VR | Send route is `g_packetSender->QueueAndSendPacket`. | exact | Fresh global/callee decompile references `g_packetSender` and Socket_QueueAndSendPacket. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Packet send | incorporate | applied |
| C3VR-044 | 0003VR | Submit sends before closing. | exact | Instruction order `0x005532f7` send then `0x005532fe` close. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Control sequencing | incorporate | applied |
| C3VR-045 | 0003VR | Previous navigation closes after the helper call. | exact | Case 2 helper flows to shared close. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Control sequencing | incorporate | applied |
| C3VR-046 | 0003VR | Next navigation closes after the helper call. | exact | Case 3 helper flows to shared close. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Control sequencing | incorporate | applied |
| C3VR-047 | 0003VR | Current navigation closes after the helper call. | exact | Case 4 helper flows to shared close. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Control sequencing | incorporate | applied |
| C3VR-048 | 0003VR | `0x0049dad0` is source-facing `DialogPane::CloseDialog`. | very strong | DialogPane API plus 132 inbound close-site xrefs and live one-call deferred-deletion body. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Close route | incorporate | applied |
| C3VR-049 | 0003VR | Close queues the pane for deferred deletion through the application cleanup queue. | exact | Historical `sub_49DAD0` decompile proved the body; supervisor Gate 2B catalog item `0398` renamed/typed/commented it as `DialogPane_CloseDialog` with behavior unchanged. | B009 callback and supervisor Gate 2B -> target close behavior/current IDA disposition | incorporate | applied |
| C3VR-050 | 0003VR | Security-cookie lowering is compiler-generated and omitted from human source. | very strong | Observed prologue/epilogue protection has no source-authored semantic branch. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Compiler/source split | incorporate | applied |
| C3VR-051 | 0003VR | The range-check-failure call is compiler-generated and omitted from human source. | very strong | Tail `0x00553333` is reached only by two compiler array-index checks and calls `___report_rangecheckfailure`. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Compiler/source split | incorporate | applied |
| C3VR-052 | 0003VR | Compiler settings must regenerate the observed protection semantics. | strong | Human local arrays and checked indexes explain the emitted runtime helpers. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Build fidelity note | incorporate | applied |
| C3VR-053 | 0003VR | Formal `CPP` should contain the full method body. | very strong | Target is reconstructable, source-authored, above code gate, and behavior/source placement are resolved. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: RECONSTRUCTION_CPP CODE | incorporate | applied |
| C3VR-054 | 0003VR | Formal `H` should remain blank to avoid duplicate declaration. | very strong | The class parent owns the single class declaration under by-structure rules. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: RECONSTRUCTION_H CODE disposition | incorporate | applied |
| C3VR-055 | 0000EL | The class parent owns the `TextDialog` declaration. | very strong | Canonical owner/emitter route and class/header structure. | B009 callback -> `by-class/TextDialog.md` :: RECONSTRUCTION_H CODE | incorporate | applied |
| C3VR-056 | 0000EL | `TextDialog` directly derives from `PursuitMessageDialogPane`. | exact | Current RTTI hierarchy and equal-size class evidence. | B009 callback -> `by-class/TextDialog.md` :: Inheritance | already-present | already-present |
| C3VR-057 | 0000EL | `TextDialog` adds no source-proven instance fields. | very strong | TextDialog size equals Pursuit base size `0x278`; constructor accesses no added tail. | B009 callback -> `by-class/TextDialog.md` :: Layout | incorporate | applied |
| C3VR-058 | 0000EL | Class size remains `0x278`. | exact | RTTI/constructor and Pursuit UDT size 632. | B009 callback -> `by-class/TextDialog.md` :: Layout | already-present | already-present |
| C3VR-059 | 0000EL | Header declares the constructor and `OnControlCommand`. | very strong | Exact constructor child plus vtable-resolved action override. | B009 callback -> `by-class/TextDialog.md` :: RECONSTRUCTION_H CODE | incorporate | applied |
| C3VR-060 | 0000EL | The class header must not invent a TextDialog destructor. | strong | No source-proven TextDialog-specific destructor body or declaration evidence. | B009 callback -> `by-class/TextDialog.md` :: Header negative constraints | incorporate | applied |
| C3VR-061 | 0000EL | Source includes MemoryMan, PacketBuffer, Socket, TextEditControlPane, Windows, and wchar support. | strong | Exact method calls/types/API dependencies plus current project include conventions. | B009 callback -> `by-class/TextDialog.md` :: RECONSTRUCTION_CPP CODE includes | incorporate | applied |
| C3VR-062 | 0000OL | Source route remains `NexusTK/ui/dialogs/TextDialog.cpp`. | very strong | Current by-file route and TextDialog family ownership. | B009 callback -> `by-file/TextDialog.md` :: Source placement | already-present | already-present |
| C3VR-063 | 0000OL | File documentation should record the action method as source-ready. | very strong | Accepted formal body and child emitter route. | B009 callback -> `by-file/TextDialog.md` :: Method/source inventory | incorporate | applied |
| C3VR-064 | 0001FJ | The aggregate remains a non-emitting split index. | exact | Current range decomposition and child ownership. | B009 callback -> `by-memory/0x00552110-0x005534a0.TextDialogCore.md` :: Metadata/disposition | already-present | already-present |
| C3VR-065 | 0001FJ | The aggregate should distinguish the source-ready action child from constructor and raw-child dispositions. | very strong | Child-specific evidence differs and must not be flattened. | B009 callback -> `by-memory/0x00552110-0x005534a0.TextDialogCore.md` :: Child inventory | incorporate | applied |
| C3VR-066 | 0003VS | The raw island starts at `0x00553350`, outside the target. | exact | Jump table ends at `0x00553348`; eight `0xcc` bytes precede raw start. | B009 callback verification -> `by-memory/0x00553350-0x00553495.TextDialogUnreferencedSubmitPacketRaw.md` :: Range/protected boundary | already-present | already-present |
| C3VR-067 | 0003VS | The raw island remains nonreconstructable with no emitter. | very strong | Existing no-route research plus fresh no-function boundary state; this report found no contrary route. | B009 callback verification -> `by-memory/0x00553350-0x00553495.TextDialogUnreferencedSubmitPacketRaw.md` :: Protected metadata | already-present | already-present |
| C3VR-068 | 0003VR | The jump table is `[0x00553338,0x00553348)`. | exact | Fresh 16-byte data-item prestate. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Boundary artifacts | incorporate | applied |
| C3VR-069 | 0003VR | Jump-table entries are `0x5531be`, `0x5531aa`, `0x5531b4`, and `0x553316`. | exact | Fresh table xrefs/bytes and switch dispatch. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Boundary artifacts | incorporate | applied |
| C3VR-070 | 0003VR | Eight `0xcc` bytes separate the jump table and raw island. | exact | Fresh padding item `[0x00553348,0x00553350)`. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Boundary artifacts | incorporate | applied |
| C3VR-071 | 0003VR | No ordinary function caller exists; the vtable data xref is the inbound route. | exact | Fresh xref query: one inbound data xref from `0x006229a0`, no inbound code xref. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Reachability | incorporate | applied |
| C3VR-072 | 0003VR | Absence of an ordinary caller does not negate virtual reachability. | very strong | Primary-vtable slot is an exact dispatch route. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Reachability conclusion | incorporate | applied |
| C3VR-073 | 0003VR | Recommended target score is `93/94`. | strong | All behavioral/formal blockers resolved; only historical lexical/build uncertainty remains. | B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Metadata | incorporate | applied |
| C3VR-074 | 0000EL | Recommended class score is `90/93`. | strong | Class declaration/layout/child integration become source-ready. | B009 callback -> `by-class/TextDialog.md` :: Metadata | incorporate | applied |
| C3VR-075 | 0000OL | Recommended file score is `90/92`. | strong | Source route and method/dependency inventory become exact. | B009 callback -> `by-file/TextDialog.md` :: Metadata | incorporate | applied |
| C3VR-076 | 0001FJ | Aggregate score remains `88/90`. | strong | It remains intentionally non-emitting and only needs child-disposition wording. | B009 callback -> `by-memory/0x00552110-0x005534a0.TextDialogCore.md` :: Metadata | already-present | already-present |
| C3VR-077 | 0003VR | The target manual coverage row carries the exact `93%` source-ready payload. | strong | Supervisor applied the recorded payload; by-memory validator `000000020704` exited 0 with `ok: 1`. | Supervisor manual -> `by-memory/-coverage-report.md` :: UID0003VR row | incorporate | applied |
| C3VR-078 | 0000EL | The class manual coverage row carries the exact `90%` source-ready payload. | strong | Supervisor applied the recorded payload; by-class validator `000000020706` exited 0 with `ok: 1`. | Supervisor manual -> `by-class/-coverage-report.md` :: UID0000EL row | incorporate | applied |
| C3VR-079 | 0000OL | The file manual coverage row carries the exact `90%` source-ready payload. | strong | Supervisor applied the recorded payload; by-file validator `000000020705` exited 0 with `ok: 1`. | Supervisor manual -> `by-file/-coverage-report.md` :: UID0000OL row | incorporate | applied |
| C3VR-080 | 0001FJ | The parent split-index manual row carries the refreshed exact `88%` payload. | strong | Supervisor applied the recorded payload; by-memory validator `000000020704` exited 0 with `ok: 1`. | Supervisor manual -> `by-memory/-coverage-report.md` :: UID0001FJ row | incorporate | applied |

## Positive Evidence Summary

- Exact vtable-cell identity and inherited slot contract resolve the method name and ABI.
- Exact inherited UDT layouts resolve every object field used by the body.
- Exact child index and immediate virtual call resolve the text child type.
- Exact switch destinations resolve all four command behaviors and default no-op.
- Exact packet writers, offsets, conversion call, copy, send call, and send length resolve wire behavior.
- Exact close helper decompilation plus established class API resolves the close route.
- Exact boundary bytes separate function, jump table, padding, and raw island.
- Existing source tree and owner/emitter route resolve destination placement.
- The remaining lexical uncertainty is narrow enough to infer human names without retaining IDA syntax.

## IDA MCP Facts

The table separates the historical B009 read-only research prestate from the supervisor's verified Gate 2B poststate.

| Item | Historical B009 fact | Supervisor Gate 2B poststate |
|---|---|---|
| `TextDialog` UDT | absent | catalog item `0398`: ordinal `970`, direct base `PursuitMessageDialogPane` ordinal `736`, size 632/`0x278`, zero own members |
| `0x00553180` | `sub_553180`, size `0x1b8`, prototype `void __thiscall(int this, int, int)` | `TextDialog_OnControlCommand`; exact type `void __thiscall TextDialog_OnControlCommand(TextDialog *this, int controlIndex, int notifyCode)`; function-repeatable comment `TextDialog::OnControlCommand; control 1 submits opcode 0x3a text, controls 2/3/4 navigate, handled actions close.` |
| Function metrics | 126 instructions, 13 basic blocks, cyclomatic complexity 6 | preserved |
| Inbound route | one data xref from `0x006229a0`; no ordinary code callers | preserved |
| Switch | values 1..4 after decrement/range check; default return | preserved |
| `0x00622958` | primary vtable `??_7TextDialog@@6B@` | protected name/type/comments/xrefs preserved |
| `0x006229a0` | vtable cell `+0x48`, value `0x00553180` | accepted repeatable slot comment applied; value/xref/parent vtable preserved |
| `0x00553338` | 16-byte jump table `jpt_5531A3` | accepted repeatable table comment applied; bytes/name/type/xrefs preserved |
| `0x00553348` | eight `0xcc` padding bytes | accepted regular alignment comment applied; bytes/name/type/xrefs preserved |
| cases 1..4 | compiler switch comments | accepted source-quality comments applied at `0x005531be`, `0x005531aa`, `0x005531b4`, and `0x00553316` |
| `0x00553350` | code-like raw byte, not a modeled function | protected raw-island start preserved with no new name/type/comment/function/inbound route |
| `0x00553333` | compiler range-failure tail | protected label/type/comments and two-inbound/one-outbound xref shape preserved |
| `0x0049dad0` | `sub_49DAD0`, size `0xd` | `DialogPane_CloseDialog`; exact type `void __thiscall DialogPane_CloseDialog(DialogPane *this)`; function-repeatable comment `DialogPane::CloseDialog; queues this pane for deferred deletion.`; address-regular `pane` preserved |
| `PursuitMessageDialogPane` | ordinal `736`, size `0x278`, fields at `+0x26c/+0x270/+0x274/+0x276` | unchanged dependency of ordinal-970 `TextDialog` |
| IDB save | no B009 mutation/save | supervisor-saved SHA-256 `4C7FC9741A1D11FB3DB28F8B29B13ED952C5817A7F6418B6B8E05EDC839CAB85`, 143193448 bytes, last write `2026-08-01 10:19:57` |

Key instruction anchors retained from the research pass:

- `0x00553196`: normalize command index for four-entry switch.
- `0x005531be`: submit-case entry.
- `0x005531c6`: push child index 6.
- `0x005531db`: call `TextEditControlPane::ReadText`.
- `0x00553281`: zero-extend low byte of wide length.
- `0x00553290`: call `WideCharToMultiByte`.
- `0x005532d1`: copy converted payload with memory manager.
- `0x005532f7`: queue/send assembled packet.
- `0x005532fe`: submit close call.
- `0x0055331d`: shared navigation close call.
- `0x00553333`: compiler range-check-failure tail.
## Function / Child Inventory

| Range/item | Source role | Disposition |
|---|---|---|
| `[0x00553180,0x00553338)` | `TextDialog::OnControlCommand` body | target emits CPP |
| `[0x00553338,0x00553348)` | compiler jump table for control switch | documented data, no source emitter |
| `[0x00553348,0x00553350)` | alignment/padding | documented padding, no source emitter |
| `[0x00553350,0x00553495)` | separate unreferenced submit-packet raw island | preserve [UID:0003VS] no-route disposition |
| `TextDialog` vtable `+0x48` | virtual dispatch slot | names target method |
| child control index 6 | `TextEditControlPane` input field | source uses inherited child accessor |
| inherited previous helper | `PursuitMessageDialogPane::SendPreviousDialogPacket` | call from control 2 |
| inherited next helper | `PursuitMessageDialogPane::SendNextDialogPacket` | call from control 3 |
| inherited current helper | `PursuitMessageDialogPane::SendCurrentDialogPacket` | call from control 4 |
| close helper `0x0049dad0` | `DialogPane::CloseDialog` | call after each handled action |

## Direct Xref / Caller Inventory

- `xrefs_to(0x00553180)` yields the TextDialog vtable data reference at `0x006229a0`.
- No ordinary direct code caller targets `0x00553180`, which is expected for a virtual callback reached through the primary vtable.
- The target directly calls:
  - `TextEditControlPane::ReadText`;
  - packet byte/BE16/BE32 writers;
  - `WideCharToMultiByte`;
  - `GetMemoryMan` and `MemoryMan::MemmoveWrapper`;
  - `g_packetSender->QueueAndSendPacket`;
  - three inherited Pursuit navigation methods;
  - `DialogPane::CloseDialog`;
  - compiler-generated range/security helpers.
- `0x0049dad0` has a broad dialog-pane caller set, including this target at `0x005532fe` and `0x0055331d`, corroborating its shared close role.

## Documentation Evidence And IDA Status

| Topic | Documentation evidence | Live IDA status | Resolution |
|---|---|---|---|
| class identity | RTTI proves direct Pursuit-derived TextDialog | exact primary vtable present | resolved |
| virtual method name | DialogPane slot `+0x48` is OnControlCommand | target stored at TextDialog slot `+0x48` | resolved |
| object layout | TextDialog adds no fields; size `0x278` | Pursuit UDT size/offsets exact | resolved |
| child type | target prose says edit control | immediate ReadText call on child 6 | resolved as TextEditControlPane |
| navigation | support docs provide three exact inherited helpers | direct callees match | resolved |
| close | DialogPane exposes CloseDialog | helper queues deferred deletion | resolved |
| source route | owner/file docs route TextDialog.cpp | no conflicting source owner | resolved |
| raw island | separate [UID:0003VS] no-route page | starts after jump table/padding | preserve separate |
| original lexical spellings | no symbol/resource constant names | human IDA names now applied; historical compiler labels retained only as provenance | infer human names; confidence cap |

## Ranked Ownership Analysis

1. **[UID:0000EL] TextDialog class - accepted canonical owner.** The method is physically installed in the TextDialog primary vtable, consumes only TextDialog/Pursuit/DialogPane state, and represents a virtual class behavior.
2. **[UID:0000OL] TextDialog file - accepted source root.** Constructor, action handler, RTTI/vtable, and nearby family records all route to the same dialog source module.
3. **[UID:0000BE] PursuitMessageDialogPane - support owner only.** It owns inherited packet fields and navigation methods but not the override body.
4. **[UID:0001FJ] TextDialogCore - rejected as emitter.** It is a non-emitting physical split index that should index exact children.
5. **[UID:0003VS] raw submit island - rejected as owner or continuation.** It is separated by jump-table data and padding and has its own no-route evidence.

No owner/emitter route change is recommended.

## Source Placement

The method definition belongs in `NexusTK/ui/dialogs/TextDialog.cpp` through [UID:0003VR] as an emitter child of [UID:0000EL]. The class declaration belongs in `TextDialog.h` through [UID:0000EL]. The target's `H` channel stays blank because a second method declaration in the child would duplicate the class-level declaration.

The implementation requires the established TextDialog/Pursuit/DialogPane types plus `MemoryMan`, packet-buffer writers, packet sender/socket declarations, `TextEditControlPane`, `WideCharToMultiByte`, and wide-string length support. It does not belong in `PursuitMessageDialogPane.cpp` because the four-way control policy and opcode `0x3a` text-submit branch are TextDialog-specific.

## Range / Split / Padding / Reclassification Analysis

- Six `0xcc` bytes precede the target start at `0x00553180`, confirming an independent function boundary.
- The modeled function occupies exactly `[0x00553180,0x00553338)`.
- The switch jump table occupies exactly `[0x00553338,0x00553348)` and contains four target addresses.
- Eight `0xcc` bytes occupy `[0x00553348,0x00553350)`.
- [UID:0003VS] begins at `0x00553350` and remains outside the target.
- No split of [UID:0003VR] is needed: the executable function body is one coherent source method.
- No merge with [UID:0003VS] is valid.
- The jump table and padding are compiler artifacts generated from the switch and should be documented, not emitted as handwritten C++ data.

## Negative Evidence Summary

- No original PDB/source symbol reveals the historical method-local names.
- No symbolic resource identifier resolves command indices 1 through 4 or child index 6.
- The exact original include order and constructor boolean spellings are not preserved in the binary.
- At the historical B009 research prestate, IDA lacked a `TextDialog` UDT and retained `sub_553180`/`sub_49DAD0`; supervisor Gate 2B later created ordinal-970 `TextDialog` and applied the accepted function names/types/comments.
- The target has no ordinary direct code caller; reachability is virtual through its vtable.
- The adjacent raw island remains unexplained as historical compiler/source duplication, but it has no route into this method.

These negatives cap final-audit confidence below 95. They do not block a human first-draft body because behavior, ABI, class, fields, branches, packet bytes, call order, source owner, and boundaries are exact.

## IDA Rename / Type / Comment Recommendations

All rows below are preserved historical read-only prestates and accepted action plans from MCP session `b3b2bf88`. Within this table, words such as `current`, `proposed`, `must`, and `Supervisor Gate 2B` describe the historical handoff state, not unfinished current work. B009 performed no mutation. The supervisor completed and read back I3VR-01 through I3VR-10, verified protected no-action rows P01 through P03, recorded catalog item `0398`, and saved the IDB with the exact identity below. The detailed prestates, rollback conditions, and expected readbacks remain intact as audit evidence.

| ID | Entity and literal fresh prestate | Frame/local inventory, xrefs, and body identity | Dependencies and collision checks | Historical accepted action or protected no-action | Stop / rollback conditions | Exact expected readback |

Supervisor closure disposition:

| Row(s) | Supervisor-attributed result |
|---|---|
| UDT closure | applied and verified from handoff row I3VR-01: `TextDialog` ordinal `970`, direct base ordinal `736`, size 632, zero own members |
| target-function closure | applied and verified from handoff row I3VR-02: `TextDialog_OnControlCommand` exact accepted type/comment |
| close-function closure | applied and verified from handoff row I3VR-03: `DialogPane_CloseDialog` exact accepted type/comment; address comment `pane` preserved |
| comment-row closure | accepted I3VR-04 through I3VR-10 table/alignment/slot/case comments applied and exact protected state preserved |
| protection closure | I3VR-P01 through I3VR-P03 protected no-actions verified for raw start, parent vtable, and range-failure tail |
| Save/catalog | catalog item `0398`; IDB SHA-256 `4C7FC9741A1D11FB3DB28F8B29B13ED952C5817A7F6418B6B8E05EDC839CAB85`, 143193448 bytes, last write `2026-08-01 10:19:57` |

Historical prestate/action/readback matrix:

| ID | Entity and literal fresh prestate | Frame/local inventory, xrefs, and body identity | Dependencies and collision checks | Historical accepted action or protected no-action | Stop / rollback conditions | Exact expected readback |
| --- | --- | --- | --- | --- | --- | --- |
| I3VR-01 | Type entity `TextDialog`: fresh `type_query(filter=TextDialog)` returns zero exact or partial matches, so current kind/width/range/name/type are all absent. Address regular: absent/not applicable; address repeatable: absent/not applicable; function regular: absent/not applicable; function repeatable: absent/not applicable. | No function frame, locals, xrefs, or body apply. Intended identity is a fieldless direct derived class whose complete object size equals its base, `0x278`/632. | Dependency is exact current `PursuitMessageDialogPane` ordinal 736, kind `struct`, size 632, members `_dialogPaneBase[620]`, `m_dialogType +0x26c`, alignment `+0x26d[3]`, `m_dialogId +0x270`, `m_dialogState +0x274`, `m_dialogPageIndex +0x276`. Exact collision checks: `type_query(TextDialog)` total 0; proposed parser declaration is exactly `class TextDialog : public PursuitMessageDialogPane {};`. Do not use `PursuitMessageDialogPane base;` or any base-as-member pseudo-source. | Supervisor Gate 2B: declare exactly `class TextDialog : public PursuitMessageDialogPane {};`; create no own members, padding, vtable member, or duplicated inherited fields. | Stop before mutation if any `TextDialog` type appears, if ordinal 736/name/size/dependency changes, or if the current parser cannot represent the direct base. After tentative declaration, stop before save and remove only the newly created type if readback shows a base member, missing base relation, duplicate type, own members, or size other than 632; restore the absent prestate. | Exact readback: one collision-free UDT named `TextDialog`, direct public base `PursuitMessageDialogPane`, size 632/`0x278`, zero own members, no fabricated base member/padding/vtable fields, and `PursuitMessageDialogPane` unchanged. |
| I3VR-02 | Function/code `[0x00553180,0x00553338)`, size `0x1b8`; entry item `[0x00553180,0x00553181)`, width 1. Exact name `sub_553180`; exact type `void __thiscall(int this, int, int)`. Address regular: absent; address repeatable: absent; function regular: absent; function repeatable: absent. | Fresh stack frame: `var_508` `MemoryMan *` off `0x4` size 4; `WideCharStr` `WCHAR` off `0x8` item size 2, decompiler array `WCHAR[256]`; `MultiByteStr` `CHAR[256]` off `0x208` size `0x100`; `Src` `_BYTE` off `0x308` size 1; `destination` `unsigned __int8` off `0x309` size 1; `var_202` `unsigned __int8[4]` off `0x30a`; `var_1FE` `unsigned __int8[2]` off `0x30e`; `var_1FC` `unsigned __int8[2]` off `0x310`; `var_1FA` byte off `0x312`; `var_1F9` byte off `0x313`; `var_1F8` `_BYTE[500]` off `0x314`; `var_4` `_DWORD` off `0x508`; `__saved_registers` off `0x50c`; `__return_address` off `0x510`; `arg_0` `_DWORD` off `0x514`. Decompiler register locals: `v4 const TextEditControlPane **`, `v5 unsigned __int8`, `v6 int`, `v7/v8 unsigned int`, `v9 Socket *`; arguments `this/a2/a3` are current `int`. Xrefs total 2: one inbound data xref from `0x006229a0`, one internal fallthrough xref to `0x00553181`; no inbound code caller. Body identity: 126 instructions, 13 blocks, complexity 6, four control cases, exact text-packet/navigation behavior. | Dependencies: I3VR-01 exact `TextDialog`; current `DialogPane`, `PursuitMessageDialogPane`, `TextEditControlPane`, `MemoryMan`, Socket and packet helpers must remain present. Collision checks: `lookup_funcs(TextDialog_OnControlCommand)` not found and `entity_query(names,TextDialog_OnControlCommand)` total 0; current `sub_553180` resolves only here. | Supervisor Gate 2B: in one transaction rename to `TextDialog_OnControlCommand`, apply exact signature `void __thiscall TextDialog_OnControlCommand(TextDialog *this, int controlIndex, int notifyCode)`, and set function-repeatable comment `TextDialog::OnControlCommand; control 1 submits opcode 0x3a text, controls 2/3/4 navigate, handled actions close.` Preserve address regular/repeatable and function-regular channels as absent. | Stop if range/size/body hash, vtable xref, old name/type, any comment channel, proposed-name collision, or required UDT dependency differs. Stop if typed decompile changes calling convention, `retn 8`, switch, packet fields, callees, or stack extent. On partial failure restore name `sub_553180`, original type, all four absent comment channels, and do not save. | Exact readback: same `[0x553180,0x553338)` body/xrefs/126 instructions/13 blocks; exact new name and signature; address regular absent, address repeatable absent, function regular absent, exact function-repeatable comment; decompile receiver `TextDialog *`, named `controlIndex/notifyCode`, unchanged local-buffer/call/control behavior. |
| I3VR-03 | Function/code `[0x0049dad0,0x0049dadd)`, size `0xd`; entry item `[0x0049dad0,0x0049dad1)`, width 1. Exact name `sub_49DAD0`; exact type `void __thiscall(Pane *this)`. Address regular: exact `pane`; address repeatable: absent; function regular: absent; function repeatable: absent. | Fresh stack frame has only `__return_address` at offset `0x0`, size 4, type `_UNKNOWN *`; no stack locals. Decompiler has only `Pane *this`, no register locals, and calls `BlackHole__QueuePaneForDeferredDeletion(g_pApplicationCleanupQueue, this)`. Xrefs total 133: 132 inbound code xrefs and one internal fallthrough; UID0003VR calls it at `0x005532fe` and `0x0055331d`. | Dependency: exact current `DialogPane` ordinal 471, kind struct, size 620, including `m_controlManager +0x1fc`; queue helper and `g_pApplicationCleanupQueue` names/body must remain. Collision checks: `lookup_funcs(DialogPane_CloseDialog)` not found and exact-name entity query total 0. | Supervisor Gate 2B: rename to `DialogPane_CloseDialog`, apply exact signature `void __thiscall DialogPane_CloseDialog(DialogPane *this)`, and set function-repeatable comment `DialogPane::CloseDialog; queues this pane for deferred deletion.` Preserve address-regular `pane`, address-repeatable absent, and function-regular absent. | Stop if function range/body, 132 inbound xrefs, exact prestate name/type/comments, DialogPane size, queue helper/global, or name collision differs. Stop if typed decompile no longer passes `this` unchanged. On partial failure restore `sub_49DAD0`, `void __thiscall(Pane *this)`, exact `pane` address comment, other channels absent, and do not save. | Exact readback: same `[0x49dad0,0x49dadd)` one-call body and 133 total xrefs; name `DialogPane_CloseDialog`; exact DialogPane signature; address regular `pane`, address repeatable absent, function regular absent, exact function-repeatable comment. |
| I3VR-04 | Data item `[0x00553338,0x00553348)`, width 16. Exact name `jpt_5531A3`; exact type absent/blank. Address regular: exact `jump table for switch statement`; address repeatable: absent; function regular: absent (not a function entry; containing function channel at `0x553180` is absent); function repeatable: absent before I3VR-02. | No independent function frame/locals. Xrefs total 5: inbound from switch at `0x005531a3`; outbound table entries to `0x005531aa`, `0x005531b4`, `0x005531be`, `0x00553316`. Body identity is the four-entry compiler switch table for controls 1..4. | Dependency is unchanged target CFG/range and exact four entry values. No name collision action is proposed; preserve existing `jpt_5531A3`. | Supervisor Gate 2B: retain item kind/range/name/blank type and regular comment; set address-repeatable comment `TextDialog::OnControlCommand cases 1 through 4.` Do not create a source global or function. | Stop if any byte/entry/xref/range/name/type/comment differs or if the table is no longer owned by the target switch. On failure restore repeatable absent and do not save. | Exact readback: same 16-byte data item, name/type/regular comment and five xrefs; exact new repeatable comment; no function/type/global created. |
| I3VR-05 | Data item `[0x00553348,0x00553350)`, width 8. Exact name absent; exact type absent/blank. Address regular: absent; address repeatable: absent; function regular: absent/not a function entry; function repeatable: absent/not a function entry. | No function frame/locals. Xrefs total 0. Body identity is eight `0xcc` alignment bytes between switch table and separate raw island. | Dependencies are exact neighboring end/start `0x553348`/`0x553350`; no proposed name or type and therefore no collision. | Supervisor Gate 2B: add address-regular comment `Alignment between TextDialog action switch table and separate raw island.` Preserve repeatable absent and all name/type/data state. | Stop if bytes are not eight `0xcc`, range/item kind changes, any xref appears, or either neighbor boundary changes. On failure restore address-regular absent and do not save. | Exact readback: unnamed/untyped 8-byte data item, zero xrefs, exact regular comment, repeatable absent, no function channels/entity creation. |
| I3VR-06 | Data item `[0x006229a0,0x006229a4)`, width 4, inside the vtable beginning `0x00622958`. Exact name absent; exact type absent/blank. Address regular: absent; address repeatable: absent; function regular: absent/not a function; function repeatable: absent/not a function. | No function frame/locals. Xrefs total 1, outbound data xref/value to `0x00553180`; slot identity is primary-vtable offset `+0x48`. | Dependency: parent vtable exact name `??_7TextDialog@@6B@` at `0x00622958`; target function and slot offset/value must match. No proposed name/type, so collision is not applicable. | Supervisor Gate 2B: set address-repeatable comment `TextDialog::OnControlCommand virtual slot +0x48.` Preserve item name/type/address-regular absent and parent vtable name/type. | Stop if parent vtable start/name, cell range/value/xref, or any comment/name/type prestate differs. On failure restore repeatable absent and do not save. | Exact readback: unchanged unnamed/untyped 4-byte data cell at `0x6229a0`, one outbound xref to renamed target, address regular absent, exact repeatable comment, parent vtable unchanged. |
| I3VR-07 | Interior code item `[0x005531be,0x005531c4)`, width 6. Exact name `loc_5531BE`; exact type absent/blank. Address regular: absent; address repeatable: exact `jumptable 005531A3 case 1`; containing-function regular: absent; containing-function repeatable: absent before I3VR-02. | No independent frame/locals; containing function inventory is I3VR-02. Xrefs total 3: inbound code from `0x005531a3`, inbound data from `0x00553338`, outbound fallthrough to `0x005531c4`. Body identity is control 1 submit entry, beginning with inherited control-manager load. | Dependency is exact target CFG/table and I3VR-02. No rename/type collision; preserve `loc_5531BE`. | Supervisor Gate 2B: replace only the address-repeatable comment with `TextDialog::OnControlCommand control 1: submit converted text packet 0x3a.` Preserve address regular absent, label/type, and containing-function channels except I3VR-02's accepted function-repeatable comment. | Stop if item range/name/type, exact old repeatable comment, three xrefs, or submit-body identity differs. On failure restore the exact old repeatable comment and do not save. | Exact readback: same 6-byte code item/label/type/xrefs; address regular absent; exact source-quality repeatable comment; containing-function comments match I3VR-02. |
| I3VR-08 | Interior code item `[0x005531aa,0x005531af)`, width 5. Exact name `loc_5531AA`; exact type absent/blank. Address regular: absent; address repeatable: exact `jumptable 005531A3 case 2`; containing-function regular: absent; containing-function repeatable: absent before I3VR-02. | No independent frame/locals; containing function inventory is I3VR-02. Xrefs total 4: inbound code from `0x005531a3`, inbound data from `0x00553338`, outbound call to `0x0054cc30`, outbound fallthrough to `0x005531af`. Body identity is previous-dialog navigation. | Dependency is exact helper `PursuitMessageDialogPane_SendPreviousDialogPacket` at `0x0054cc30` and target CFG/table. No rename/type collision; preserve `loc_5531AA`. | Supervisor Gate 2B: replace only address-repeatable comment with `TextDialog::OnControlCommand control 2: send previous dialog packet.` Preserve address regular absent, label/type, and containing-function channels except I3VR-02. | Stop if item/name/type/comment, four xrefs, helper identity, or CFG differs. On failure restore exact old repeatable comment and do not save. | Exact readback: same 5-byte item/label/type/four xrefs; address regular absent; exact new repeatable comment; helper/cfg unchanged. |
| I3VR-09 | Interior code item `[0x005531b4,0x005531b9)`, width 5. Exact name `loc_5531B4`; exact type absent/blank. Address regular: absent; address repeatable: exact `jumptable 005531A3 case 3`; containing-function regular: absent; containing-function repeatable: absent before I3VR-02. | No independent frame/locals; containing function inventory is I3VR-02. Xrefs total 4: inbound code from `0x005531a3`, inbound data from `0x00553338`, outbound call to `0x0054ccd0`, outbound fallthrough to `0x005531b9`. Body identity is next-dialog navigation. | Dependency is exact helper `PursuitMessageDialogPane_SendNextDialogPacket` at `0x0054ccd0` and target CFG/table. No rename/type collision; preserve `loc_5531B4`. | Supervisor Gate 2B: replace only address-repeatable comment with `TextDialog::OnControlCommand control 3: send next dialog packet.` Preserve address regular absent, label/type, and containing-function channels except I3VR-02. | Stop if item/name/type/comment, four xrefs, helper identity, or CFG differs. On failure restore exact old repeatable comment and do not save. | Exact readback: same 5-byte item/label/type/four xrefs; address regular absent; exact new repeatable comment; helper/cfg unchanged. |
| I3VR-10 | Interior code item `[0x00553316,0x0055331b)`, width 5. Exact name `loc_553316`; exact type absent/blank. Address regular: absent; address repeatable: exact `jumptable 005531A3 case 4`; containing-function regular: absent; containing-function repeatable: absent before I3VR-02. | No independent frame/locals; containing function inventory is I3VR-02. Xrefs total 4: inbound code from `0x005531a3`, inbound data from `0x00553338`, outbound call to `0x0054cd70`, outbound fallthrough to `0x0055331b`. Body identity is current-dialog navigation. | Dependency is exact helper `PursuitMessageDialogPane_SendCurrentDialogPacket` at `0x0054cd70` and target CFG/table. No rename/type collision; preserve `loc_553316`. | Supervisor Gate 2B: replace only address-repeatable comment with `TextDialog::OnControlCommand control 4: send current dialog packet.` Preserve address regular absent, label/type, and containing-function channels except I3VR-02. | Stop if item/name/type/comment, four xrefs, helper identity, or CFG differs. On failure restore exact old repeatable comment and do not save. | Exact readback: same 5-byte item/label/type/four xrefs; address regular absent; exact new repeatable comment; helper/cfg unchanged. |
| I3VR-P01 | Protected code item `[0x00553350,0x00553351)`, width 1; not a modeled function. Exact name absent; exact type absent/blank. Address regular: absent; address repeatable: absent; function regular: absent; function repeatable: absent. | No independent frame/locals or function body. Xrefs total 1: one outbound sequential code xref to `0x00553351`, zero inbound xrefs. Identity is the separate [UID:0003VS] raw-island start after eight-byte padding. | Dependency/protection: [UID:0003VS] current no-route disposition and exact boundary. No proposed name/type/comment/function, so collision is not applicable. | Supervisor Gate 2B protected no-action: do not create a function, name, type, comment, or merge from this report. | Stop the entire action batch and return for report repair if an inbound route/new owner is discovered or any planned action touches this item. If accidentally changed, restore exact unnamed/untyped/nonfunction/comment-absent prestate before save. | Exact readback remains one-byte code item, no modeled function/name/type/comments, zero inbound xrefs, separate raw-island boundary unchanged. |
| I3VR-P02 | Protected data item `[0x00622958,0x0062295c)`, width 4, first cell of primary vtable. Exact name `??_7TextDialog@@6B@`; exact type absent/blank. Address regular: absent; address repeatable: absent; function regular: absent; function repeatable: absent. | No frame/locals. Xrefs total 2: inbound data xref from constructor at `0x00552161`; outbound cell/value xref to `0x00520b70`. Identity is the TextDialog primary-vtable start, not a source global to rename. | Dependency/protection: current RTTI/vtable page and I3VR-06 offset calculation. Existing compiler name must remain; no proposed collision. | Supervisor Gate 2B protected no-action: do not rename, retype, recomment, resize, or reconstruct the parent vtable item. | Stop if any accepted action would overwrite the compiler name/type/data or move the vtable boundary. If accidentally changed, restore exact compiler name, blank type, and four absent comment channels before save. | Exact readback remains 4-byte data item named `??_7TextDialog@@6B@`, blank type/comments, same two xrefs; only child cell I3VR-06 may gain its repeatable comment. |
| I3VR-P03 | Protected interior code item `[0x00553333,0x00553338)`, width 5. Exact name `loc_553333`; exact type absent/blank. Address regular: absent; address repeatable: absent; containing-function regular: absent; containing-function repeatable: absent before I3VR-02. | No independent frame/locals; containing frame is I3VR-02. Xrefs total 3: inbound branches from `0x0055329e` and `0x005532df`, outbound call to `___report_rangecheckfailure` at `0x005c7655`. Identity is compiler-generated local-array range-failure tail. | Dependency/protection: exact two guarded index sites and compiler runtime helper. No proposed rename/type/comment and no collision. | Supervisor Gate 2B protected no-action: preserve local label, blank type/comments, branches, and runtime-helper call; model protections through source/build settings only. | Stop if action planning attempts to expose this tail as a source method/helper or changes its label/type/comments. If accidentally changed, restore exact prestate before save. | Exact readback remains same 5-byte interior code item, `loc_553333`, blank type/comments, two inbound branches and one runtime-helper outbound xref; containing function comment follows only I3VR-02. |

## First-Draft C++ Recommendation

### [UID:0003VR] formal `CPP`

```cpp
void TextDialog::OnControlCommand(int controlIndex, int /*notifyCode*/)
{
    switch (controlIndex)
    {
    case 1:
        {
            wchar_t text[256];
            char convertedText[256];
            unsigned char packet[512];

            GetChild<TextEditControlPane>(6)->ReadText(text, 255);

            MemoryMan *memoryMan = GetMemoryMan();
            const unsigned char textLength =
                static_cast<unsigned char>(wcslen(text));

            PacketBufferWriteUInt8(0x3a, packet);
            PacketBufferWriteUInt8(m_dialogType, packet + 1);
            PacketBufferWriteUInt32BE(m_dialogId, packet + 2);
            PacketBufferWriteUInt16BE(m_dialogState, packet + 6);
            PacketBufferWriteUInt16BE(
                static_cast<unsigned short>(m_dialogPageIndex + 1),
                packet + 8);
            PacketBufferWriteUInt8(2, packet + 10);

            const int convertedLength = WideCharToMultiByte(
                CP_ACP,
                0,
                text,
                textLength,
                convertedText,
                sizeof(convertedText),
                NULL,
                NULL);

            convertedText[convertedLength] = '\0';
            PacketBufferWriteUInt8(
                static_cast<unsigned char>(convertedLength),
                packet + 11);
            memoryMan->MemmoveWrapper(
                packet + 12,
                convertedText,
                convertedLength);

            const int packetLength = convertedLength + 12;
            packet[packetLength] = 0;
            g_packetSender->QueueAndSendPacket(
                packet,
                static_cast<short>(packetLength));
            CloseDialog();
        }
        break;

    case 2:
        SendPreviousDialogPacket();
        CloseDialog();
        break;

    case 3:
        SendNextDialogPacket();
        CloseDialog();
        break;

    case 4:
        SendCurrentDialogPacket();
        CloseDialog();
        break;
    }
}
```

This is source-shaped rather than decompiler-shaped. Numeric control/child values remain where no original resource constant is recoverable. The source intentionally omits direct calls to `__report_rangecheckfailure` and security-cookie helpers; the observed checked local-array accesses and compiler configuration must reproduce those safeguards.

### [UID:0003VR] formal `H`

Leave blank. The exact declaration is emitted once by [UID:0000EL] inside the `TextDialog` class.

### [UID:0000EL] class-parent formal `CPP`

```cpp
#include "TextDialog.h"

#include "MemoryMan.h"
#include "PacketBuffer.h"
#include "Socket.h"
#include "TextEditControlPane.h"

#include <windows.h>
#include <wchar.h>

[[CHILDREN]]
```

### [UID:0000EL] class-parent formal `H`

```cpp
#include "PursuitMessageDialogPane.h"

class TextDialog : public PursuitMessageDialogPane
{
public:
    TextDialog(const unsigned char *payload,
               bool showObjectImage,
               bool useLargeLayout);
    virtual void OnControlCommand(int controlIndex, int notifyCode);
};
```

`showObjectImage` and `useLargeLayout` are the strongest current human names from the four wrapper combinations and constructor behavior. They are class-parent support changes, not additions to this method's range.

## Final Recommendation

The accepted recommendation is implemented in the ordinary documentation: [UID:0003VR] is a source-ready method child, the class and source owner remain unchanged, the target emits the method body, the class parent emits the declaration/includes, and the target header remains blank to avoid duplication.

The recommended draft preserves exact runtime behavior while replacing reverse-engineering labels with plausible mid-2000s human source. Confidence remains below final-audit 95 because original lexical spellings and resource constant names are not recoverable, not because any control-flow, packet, ABI, ownership, or source-placement issue remains unresolved.

## Recommended Target Doc Changes

For `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md`:

1. Change title/source-facing method terminology from `HandleDialogAction` to `TextDialog::OnControlCommand`; retain `sub_553180` only in a historical IDA-provenance note.
2. Replace old blocker wording with the resolved vtable/ABI/control/child/conversion/packet/close analysis from C3VR-001 through C3VR-054 and C3VR-068 through C3VR-072.
3. Add exact boundary/jump-table/padding analysis.
4. Add the formal `CPP` body exactly as recommended above.
5. Keep formal `H` blank and document class-parent declaration ownership.
6. Set `COMPLETION:93`, `CONFIDENCE:94`.
7. Preserve `CANONICAL_OWNER:0000EL`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000EL`.
8. Add current MCP provenance and distinguish current facts from historical labels.
9. Preserve the adjacent [UID:0003VS] raw island as separate and non-emitting.

Callback result: all nine target operations were applied and verified in post-validation target SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`.

## Recommended Support Doc Changes

### `by-class/TextDialog.md` [UID:0000EL]

- Incorporate C3VR-004 through C3VR-010, C3VR-053 through C3VR-061, and C3VR-071 through C3VR-075.
- Add the formal class-parent `CPP` and `H` blocks above.
- Record no added fields and exact `0x278` class size.
- Explain that the action override is source-ready while the child by-memory page owns the method body.
- Set `COMPLETION:90`, `CONFIDENCE:93`; preserve owner/emitter route.

Callback result: applied and verified in class SHA-256 `AB94E00C3C10D0BF89DB0F03217A40AAC9CAD48E4002EDD53A92C9A3D7249E7B`.

### `by-file/TextDialog.md` [UID:0000OL]

- Incorporate the exact source placement, method role, dependency/include surface, and separate raw-island disposition.
- Record [UID:0003VR] as the emitting child for `TextDialog::OnControlCommand`.
- Set `COMPLETION:90`, `CONFIDENCE:92`; preserve file route.

Callback result: applied and verified in file SHA-256 `D2404230BD80EF207AB6FEE7A655CBE97719DAF71B0DD2A785F66F459ECA3F4F`.

### `by-memory/0x00552110-0x005534a0.TextDialogCore.md` [UID:0001FJ]

- Preserve non-emitting split-index status and `88/90`.
- Update child disposition so [UID:0003VR] is explicitly source-ready/formal-CPP, while constructor and raw child retain their separate current dispositions.
- Preserve proxy callback boundary at `0x005534a0`.

Callback result: applied and verified in split-index SHA-256 `75F46C453A4EDC6CA459236BDF514B59327A2D3E1500422B459C446DD0FCFC3A`.

### Protected support

- Do not change [UID:0003VS] metadata, owner/emitter, or no-route conclusion from this report.
- Do not duplicate inherited navigation helper bodies in TextDialog.
- Do not insert target-specific method body into class-level formal `H`.

Callback result: all protected constraints were verified. [UID:0003VS] remained byte-identical at SHA-256 `41D1245FB75974874B60D3A3CEDE552CDA7CADADC7215742DDCF1270A9C7652A`.

## Score And Metadata Recommendation

| UID | Current | Recommended | Metadata/routing | Justification |
|---|---:|---:|---|---|
| `0003VR` | `87/92` | `93/94` | preserve owner `0000EL`, reconstructable true, emitter `0000EL`; add CPP, blank H | exact body/ABI/vtable/packet/source ready; lexical uncertainty only |
| `0000EL` | `88/92` | `90/93` | preserve owner/emitter `0000OL`; add class CPP/H | exact class API/layout and child integration |
| `0000OL` | `89/90` | `90/92` | preserve source route | exact action source placement and dependencies |
| `0001FJ` | `88/90` | `88/90` | preserve non-emitting split index | wording update only; aggregate intentionally does not emit |
| `0003VS` | `88/90` | `88/90` | preserve no owner, nonreconstructable, no emitter | protected separate raw island |

Reason not 95+: no original symbol/resource names establish the historical command constants, child constant, local names, include order, or exact constructor-boolean spellings; compiler settings must be validated when generated code is compiled. Reason not lower: all executable semantics, ABI, virtual identity, object fields, packet bytes, conversion arguments, length behavior, close routes, physical boundaries, owner, emitter, and source root are resolved.

## Open Questions With Attempted Resolution

1. **Original control constant names.** Resource/symbol searches and current docs do not expose historical identifiers. Resolution: use exact numeric control indices rather than inventing unsupported constants. This is a lexical confidence cap, not a body blocker.
2. **Child index 6 symbolic name.** The binary proves type and role but not resource identifier. Resolution: `GetChild<TextEditControlPane>(6)` is exact and human-readable without false certainty.
3. **Method name.** Resolved, not open: vtable slot `+0x48` plus base declaration proves `OnControlCommand`.
4. **Second argument.** Resolved as `notifyCode` by inherited declaration; deliberately unnamed in the definition because unused.
5. **Close helper.** Resolved as `DialogPane::CloseDialog` by class contract, broad caller pattern, and live decompile showing deferred deletion.
6. **Packet field names.** Resolved through exact Pursuit UDT and established project naming.
7. **Text conversion source shape.** Resolved as `WideCharToMultiByte(CP_ACP,...)` with one-byte wide length and 256-byte destination. A hand-written call to the range-failure helper is rejected as compiler-shaped source.
8. **Raw island relation.** Resolved for this target: it is physically separate and cannot be merged. Its historical origin remains a protected [UID:0003VS] question and does not block this method.
9. **Header ownership.** Resolved: class parent emits the declaration; method child emits CPP only.
10. **Score/formal blocker.** Resolved: the existing empty emitter is stale and should be replaced by draft source.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The exact payloads below are retained as historical supervisor-applied evidence. B009 did not edit any `-coverage-report.md` or generated tracker file. The supervisor applied C3VR-077 through C3VR-080 and validated the resulting manual reports with `000000020704` (by-memory), `000000020705` (by-file), and `000000020706` (by-class), each exit 0/`ok: 1`. Physical line numbers and identities below are historical pre-application anchors, not current lifecycle or pending-work claims.

### `by-memory/-coverage-report.md`

Historical pre-application identity: SHA-256 `8498F2C5BBEF65FDC6C845CA9677A660C9B70E6A8967077C745568F26F1221BA`, 2152540 bytes, 4839 lines.

Historical [UID:0001FJ] replacement applied by the supervisor:

```text
    - [UID:0001FJ][0x00552110-0x005534a0.TextDialogCore](by-memory/0x00552110-0x005534a0.TextDialogCore.md) 0x00552110-0x005534a0 | split-index | TextDialogCore : ignored/non-emitting : 88% : very-strong : Non-emitting exact TextDialog constructor/action/raw-island index; current RTTI proves TextDialog directly derives from PursuitMessageDialogPane, [UID:0003VR] now carries source-ready OnControlCommand C++, and the constructor/raw children retain their separate current dispositions before the proxy callback at 0x005534a0.
```

Historical [UID:0003VR] replacement applied by the supervisor:

```text
            - [UID:0003VR][0x00553180-0x00553338.TextDialogHandleDialogAction](by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md) 0x00553180-0x00553338 | virtual handler | TextDialogHandleDialogAction : reconstructable : 93% : very-strong : Exact TextDialog::OnControlCommand override; vtable slot +0x48 proves the ABI, control 1 submits opcode 0x3a converted text with inherited dialog fields, controls 2/3/4 navigate, and every handled action closes while the default is a no-op.
```

Validator `000000020704`: exit 0, `ok: 1`.

### `by-class/-coverage-report.md`

Historical pre-application identity: SHA-256 `7CD0EB799663BFEC9BFE97CAB1EF97E5471FA1C6DF0550ADE441C4C6E277B657`, 275271 bytes, 625 lines.

Historical [UID:0000EL] replacement applied by the supervisor:

```text
- [UID:0000EL][TextDialog](by-class/TextDialog.md) : reconstructable : 90% : very strong : RTTI-proven PursuitMessageDialogPane-derived text/input dialog with exact 0x278 layout, inherited packet/navigation state, class declaration, and source-ready OnControlCommand child; constructor and separate raw-island evidence retain their own documented dispositions.
```

Validator `000000020706`: exit 0, `ok: 1`.

### `by-file/-coverage-report.md`

Historical pre-application identity: SHA-256 `AD149A2E365381FF8A7AA47F5D84DA8AB94951352A5D559D332C184796798CE6`, 166568 bytes, 319 lines.

Historical [UID:0000OL] replacement applied by the supervisor:

```text
- [UID:0000OL][TextDialog](by-file/TextDialog.md) : reconstructable : 90% : very-strong : TextDialog source module with RTTI-proven PursuitMessageDialogPane inheritance, exact constructor/action/raw-island ownership, class header route, and source-ready TextDialog::OnControlCommand implementation using inherited dialog packet fields and navigation helpers.
```

Validator `000000020705`: exit 0, `ok: 1`.

Generated refresh `000000020707` at `2026-08-01 10:21:37` produced one UID0003VR definition/declaration, zero target empty markers, and current tracker/coverage values `93/94` target, `90/93` class, `90/92` file, and `88/90` aggregate.
## Follow-Up Actions

All accepted ordinary-document, Gate 2B, manual coverage, and generated operations recorded by this report have closure evidence. The supervisor performed Gate 2B, manual validators `000000020704` through `000000020706`, and generated refresh `000000020707`; B009 only reconciled their verified outcomes into this report.

Historical lifecycle incident: command `000000020708` executed the report once, and command `000000020709` fail-closed returned it for wording repair after the mandatory postarchive audit. These historical facts do not assert current executed, pending, or archived status.

For any later lifecycle decision, the supervisor must use the report's current path and validator-owned status/history metadata as the sole current authority. No report-body wording overrides that authority.
## Confidence

- Method identity and ABI: very strong (`96`).
- Switch/control behavior: very strong (`98`).
- Packet wire layout and send length: very strong (`98`).
- Object field layout and inheritance: very strong (`97`).
- Child type and text conversion behavior: very strong (`96`).
- Source owner/emitter/file placement: very strong (`95`).
- Exact historical local/resource/include spellings: moderate (`75`).
- Overall recommended target confidence: `94`.

The recommendation intentionally distinguishes exact runtime facts from inferred human lexical choices. No finalized source-facing identifier retains IDA-style syntax merely because an original spelling is unavailable.

## Validator Results

### Historical B009 ordinary-document validators

| Destination | Command ID | Command timestamp | Exit | ok | Result |
|---|---:|---|---:|---:|---|
| `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` | `000000020652` | `2026-08-01T09:17:09-04:00` | 0 | 1 | target `93/94`; UID links normalized; generated refresh skipped |
| `by-class/TextDialog.md` | `000000020653` | `2026-08-01T09:17:19-04:00` | 0 | 1 | class `90/93`; UID links normalized; generated refresh skipped |
| `by-file/TextDialog.md` | `000000020654` | `2026-08-01T09:17:24-04:00` | 0 | 1 | file `90/92`; generated refresh skipped |
| `by-memory/0x00552110-0x005534a0.TextDialogCore.md` | `000000020655` | `2026-08-01T09:17:31-04:00` | 0 | 1 | aggregate `88/90`; UID links normalized; generated refresh skipped |

The target validator reported `missing_ref_uid 0003DC` while still returning `ok: 1`. B009 did not hand-edit validator state.

### Supervisor manual/generated closure

| Scope | Command | Result |
|---|---:|---|
| `by-memory/-coverage-report.md` | `000000020704` | exit 0, `ok: 1`; C3VR-077 and C3VR-080 applied |
| `by-file/-coverage-report.md` | `000000020705` | exit 0, `ok: 1`; C3VR-079 applied |
| `by-class/-coverage-report.md` | `000000020706` | exit 0, `ok: 1`; C3VR-078 applied |
| generated output/tracker | `000000020707` at `2026-08-01 10:21:37` | one UID0003VR definition/declaration, zero target empty markers; scores `93/94`, `90/93`, `90/92`, `88/90` reconciled |

### Historical lifecycle incident facts

- `000000020708`: supervisor execution occurred once.
- `000000020709`: mandatory postarchive audit found stale current-state/pending wording and fail-closed returned the report for rework.
- Neither command states current lifecycle truth. Current path and validator-owned history are authoritative.

No validator, generated, or lifecycle command was run by B009 during this report-only reconciliation repair.
## Changed Files

Historical ordinary callback changes remain fully documented:

- `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md`: accepted target metadata, formal CPP/blank-H disposition, behavior, ABI/vtable, packet, boundary, negative, and historical detail.
- `by-class/TextDialog.md`: accepted `90/93` class CPP/H, direct Pursuit inheritance, exact layout, method contract, dependencies, and negative constraints.
- `by-file/TextDialog.md`: accepted `90/92` source-ready method/source-placement/dependency inventory.
- `by-memory/0x00552110-0x005534a0.TextDialogCore.md`: preserved `88/90` non-emitting aggregate metadata with exact child dispositions.
- Protected `by-memory/0x00553350-0x00553495.TextDialogUnreferencedSubmitPacketRaw.md` remained unchanged.

Supervisor-attributed closure, not B009 edits: IDA catalog/save changes; manual coverage C3VR-077 through C3VR-080; manual validators `000000020704` through `000000020706`; generated refresh `000000020707`; validator-owned lifecycle history `000000020708`/`000000020709`.

This reconciliation repair edits only `tools/leaser/Agents/Agent-B009/research/0003VR-TextDialogHandleDialogAction-empty-emitter-source-quality.md`. B009 did not redo ordinary docs, IDA, manual coverage, generated output, validators, audit/catalog files, or lifecycle commands.
## Implementation Tracking Checklist

This is the fully reconciled one-to-one checklist. Claims C3VR-001 through C3VR-080 are checked exactly once: B009 ordinary-document work is attributed to B009, while Gate 2B, manual coverage, generated refresh, and lifecycle policy closure are attributed to the supervisor. Historical prestate/action text remains in the report as audit evidence, not pending work. Current execution/archive truth remains authoritative only from the report's current path plus validator-owned status/history metadata.

### One-to-one claim callback map

- [x] C3VR-001 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Target / range analysis; incorporate the claim "Range is exactly `[0x00553180,0x00553338)`." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-002 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: IDA facts; incorporate the claim "IDA models one function at `0x00553180`, size `0x1b8`." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-003 - B009 callback and supervisor Gate 2B -> target historical IDA provenance/current disposition; historical `sub_553180` was documented, then supervisor catalog item `0398` verified current `TextDialog_OnControlCommand` exact type/comment. Ledger state remains `applied`.
- [x] C3VR-004 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Behavior / source identity; incorporate the claim "Source identity is `TextDialog::OnControlCommand(int,int)`." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-005 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Vtable evidence; incorporate the claim "The TextDialog primary vtable begins at `0x00622958`." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-006 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Vtable evidence; incorporate the claim "Cell `0x006229a0` is vtable offset `+0x48` and stores `0x00553180`." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-007 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Source identity rationale; incorporate the claim "`DialogPane` slot `+0x48` is `OnControlCommand`." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-008 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: ABI; incorporate the claim "The ABI is `__thiscall` with two explicit `int` arguments and `retn 8`." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-009 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Signature / behavior; incorporate the claim "The first explicit argument is `controlIndex`." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-010 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Signature / behavior; incorporate the claim "The second explicit argument is unused `notifyCode`." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-011 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Control inventory; incorporate the claim "Control index 1 is the text-submit route." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-012 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Control inventory; incorporate the claim "Control index 2 sends the previous-dialog packet." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-013 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Control inventory; incorporate the claim "Control index 3 sends the next-dialog packet." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-014 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Control inventory; incorporate the claim "Control index 4 sends the current-dialog packet." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-015 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Control inventory; incorporate the claim "The default switch route performs no work and returns without closing." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-016 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Object layout; incorporate the claim "`m_controlManager` is read at inherited offset `+0x1fc`." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-017 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Child-control behavior; incorporate the claim "Child index 6 is fetched from the control manager." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-018 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Child-control behavior; incorporate the claim "Child 6 is used as `TextEditControlPane`." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-019 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Text acquisition; incorporate the claim "`ReadText` receives capacity 255." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-020 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Local-buffer model; incorporate the claim "The wide input buffer contains 256 `wchar_t` elements." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-021 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Local-buffer model; incorporate the claim "The converted buffer contains 256 bytes." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-022 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Local-buffer model; incorporate the claim "The packet aggregate contains 512 bytes." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-023 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Text conversion; incorporate the claim "Wide input is scanned to its null terminator." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-024 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Text conversion; incorporate the claim "Wide length is passed to conversion as an unsigned byte." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-025 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Text conversion; incorporate the claim "`WideCharToMultiByte` uses code page `CP_ACP`/0." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-026 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Text conversion; incorporate the claim "`WideCharToMultiByte` uses flags 0." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-027 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Text conversion; incorporate the claim "Conversion destination capacity is 256." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-028 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Text conversion; incorporate the claim "Default-character and used-default-character pointers are null." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-029 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Compiler protections; incorporate the claim "Converted length is checked below 256 before local terminator indexing." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-030 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Compiler protections; incorporate the claim "Packet length is checked below 512 before local terminator indexing." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-031 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Packet layout; incorporate the claim "Packet offset `+0` is opcode `0x3a`." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-032 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Packet layout; incorporate the claim "Packet offset `+1` is inherited `m_dialogType`." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-033 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Packet layout; incorporate the claim "Packet offsets `+2..+5` are big-endian `m_dialogId`." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-034 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Packet layout; incorporate the claim "Packet offsets `+6..+7` are big-endian `m_dialogState`." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-035 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Packet layout; incorporate the claim "Packet offsets `+8..+9` are big-endian `m_dialogPageIndex + 1`." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-036 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Packet layout; incorporate the claim "Packet offset `+10` is subtype 2." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-037 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Packet layout; incorporate the claim "Packet offset `+11` is converted byte length." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-038 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Packet layout; incorporate the claim "Packet offset `+12` begins converted bytes." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-039 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Packet assembly; incorporate the claim "Payload copy uses the project `MemoryMan::MemmoveWrapper` route." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-040 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Packet send; incorporate the claim "Sent length is `convertedLength + 12`." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-041 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Length semantics; incorporate the claim "The converted-text local terminator is not transmitted." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-042 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Length semantics; incorporate the claim "The packet local terminator is not transmitted." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-043 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Packet send; incorporate the claim "Send route is `g_packetSender->QueueAndSendPacket`." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-044 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Control sequencing; incorporate the claim "Submit sends before closing." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-045 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Control sequencing; incorporate the claim "Previous navigation closes after the helper call." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-046 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Control sequencing; incorporate the claim "Next navigation closes after the helper call." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-047 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Control sequencing; incorporate the claim "Current navigation closes after the helper call." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-048 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Close route; incorporate the claim "`0x0049dad0` is source-facing `DialogPane::CloseDialog`." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-049 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Close behavior; incorporate the claim "Close queues the pane for deferred deletion through the application cleanup queue." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-050 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Compiler/source split; incorporate the claim "Security-cookie lowering is compiler-generated and omitted from human source." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-051 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Compiler/source split; incorporate the claim "The range-check-failure call is compiler-generated and omitted from human source." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-052 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Build fidelity note; incorporate the claim "Compiler settings must regenerate the observed protection semantics." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-053 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: RECONSTRUCTION_CPP CODE; incorporate the claim "Formal `CPP` should contain the full method body." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-054 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: RECONSTRUCTION_H CODE disposition; incorporate the claim "Formal `H` should remain blank to avoid duplicate declaration." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-055 - B009 callback -> `by-class/TextDialog.md` :: RECONSTRUCTION_H CODE; incorporate the claim "The class parent owns the `TextDialog` declaration." Callback verification: `applied` in exact destination SHA-256 `AB94E00C3C10D0BF89DB0F03217A40AAC9CAD48E4002EDD53A92C9A3D7249E7B`; ledger state reconciled to `applied`.
- [x] C3VR-056 - B009 callback -> `by-class/TextDialog.md` :: Inheritance; already-present the claim "`TextDialog` directly derives from `PursuitMessageDialogPane`." Callback verification: `already-present` in exact destination SHA-256 `AB94E00C3C10D0BF89DB0F03217A40AAC9CAD48E4002EDD53A92C9A3D7249E7B`; ledger state reconciled to `already-present`.
- [x] C3VR-057 - B009 callback -> `by-class/TextDialog.md` :: Layout; incorporate the claim "`TextDialog` adds no source-proven instance fields." Callback verification: `applied` in exact destination SHA-256 `AB94E00C3C10D0BF89DB0F03217A40AAC9CAD48E4002EDD53A92C9A3D7249E7B`; ledger state reconciled to `applied`.
- [x] C3VR-058 - B009 callback -> `by-class/TextDialog.md` :: Layout; already-present the claim "Class size remains `0x278`." Callback verification: `already-present` in exact destination SHA-256 `AB94E00C3C10D0BF89DB0F03217A40AAC9CAD48E4002EDD53A92C9A3D7249E7B`; ledger state reconciled to `already-present`.
- [x] C3VR-059 - B009 callback -> `by-class/TextDialog.md` :: RECONSTRUCTION_H CODE; incorporate the claim "Header declares the constructor and `OnControlCommand`." Callback verification: `applied` in exact destination SHA-256 `AB94E00C3C10D0BF89DB0F03217A40AAC9CAD48E4002EDD53A92C9A3D7249E7B`; ledger state reconciled to `applied`.
- [x] C3VR-060 - B009 callback -> `by-class/TextDialog.md` :: Header negative constraints; incorporate the claim "The class header must not invent a TextDialog destructor." Callback verification: `applied` in exact destination SHA-256 `AB94E00C3C10D0BF89DB0F03217A40AAC9CAD48E4002EDD53A92C9A3D7249E7B`; ledger state reconciled to `applied`.
- [x] C3VR-061 - B009 callback -> `by-class/TextDialog.md` :: RECONSTRUCTION_CPP CODE includes; incorporate the claim "Source includes MemoryMan, PacketBuffer, Socket, TextEditControlPane, Windows, and wchar support." Callback verification: `applied` in exact destination SHA-256 `AB94E00C3C10D0BF89DB0F03217A40AAC9CAD48E4002EDD53A92C9A3D7249E7B`; ledger state reconciled to `applied`.
- [x] C3VR-062 - B009 callback -> `by-file/TextDialog.md` :: Source placement; already-present the claim "Source route remains `NexusTK/ui/dialogs/TextDialog.cpp`." Callback verification: `already-present` in exact destination SHA-256 `D2404230BD80EF207AB6FEE7A655CBE97719DAF71B0DD2A785F66F459ECA3F4F`; ledger state reconciled to `already-present`.
- [x] C3VR-063 - B009 callback -> `by-file/TextDialog.md` :: Method/source inventory; incorporate the claim "File documentation should record the action method as source-ready." Callback verification: `applied` in exact destination SHA-256 `D2404230BD80EF207AB6FEE7A655CBE97719DAF71B0DD2A785F66F459ECA3F4F`; ledger state reconciled to `applied`.
- [x] C3VR-064 - B009 callback -> `by-memory/0x00552110-0x005534a0.TextDialogCore.md` :: Metadata/disposition; already-present the claim "The aggregate remains a non-emitting split index." Callback verification: `already-present` in exact destination SHA-256 `75F46C453A4EDC6CA459236BDF514B59327A2D3E1500422B459C446DD0FCFC3A`; ledger state reconciled to `already-present`.
- [x] C3VR-065 - B009 callback -> `by-memory/0x00552110-0x005534a0.TextDialogCore.md` :: Child inventory; incorporate the claim "The aggregate should distinguish the source-ready action child from constructor and raw-child dispositions." Callback verification: `applied` in exact destination SHA-256 `75F46C453A4EDC6CA459236BDF514B59327A2D3E1500422B459C446DD0FCFC3A`; ledger state reconciled to `applied`.
- [x] C3VR-066 - B009 callback verification -> `by-memory/0x00553350-0x00553495.TextDialogUnreferencedSubmitPacketRaw.md` :: Range/protected boundary; already-present the claim "The raw island starts at `0x00553350`, outside the target." Callback verification: `already-present` in exact destination SHA-256 `41D1245FB75974874B60D3A3CEDE552CDA7CADADC7215742DDCF1270A9C7652A`; ledger state reconciled to `already-present`.
- [x] C3VR-067 - B009 callback verification -> `by-memory/0x00553350-0x00553495.TextDialogUnreferencedSubmitPacketRaw.md` :: Protected metadata; already-present the claim "The raw island remains nonreconstructable with no emitter." Callback verification: `already-present` in exact destination SHA-256 `41D1245FB75974874B60D3A3CEDE552CDA7CADADC7215742DDCF1270A9C7652A`; ledger state reconciled to `already-present`.
- [x] C3VR-068 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Boundary artifacts; incorporate the claim "The jump table is `[0x00553338,0x00553348)`." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-069 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Boundary artifacts; incorporate the claim "Jump-table entries are `0x5531be`, `0x5531aa`, `0x5531b4`, and `0x553316`." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-070 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Boundary artifacts; incorporate the claim "Eight `0xcc` bytes separate the jump table and raw island." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-071 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Reachability; incorporate the claim "No ordinary function caller exists; the vtable data xref is the inbound route." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-072 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Reachability conclusion; incorporate the claim "Absence of an ordinary caller does not negate virtual reachability." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-073 - B009 callback -> `by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md` :: Metadata; incorporate the claim "Recommended target score is `93/94`." Callback verification: `applied` in exact destination SHA-256 `7F2F184C5CBF68E5B0C3E6CAC7AF2273E676A2CEE583B975F1A42E5626CCF0EE`; ledger state reconciled to `applied`.
- [x] C3VR-074 - B009 callback -> `by-class/TextDialog.md` :: Metadata; incorporate the claim "Recommended class score is `90/93`." Callback verification: `applied` in exact destination SHA-256 `AB94E00C3C10D0BF89DB0F03217A40AAC9CAD48E4002EDD53A92C9A3D7249E7B`; ledger state reconciled to `applied`.
- [x] C3VR-075 - B009 callback -> `by-file/TextDialog.md` :: Metadata; incorporate the claim "Recommended file score is `90/92`." Callback verification: `applied` in exact destination SHA-256 `D2404230BD80EF207AB6FEE7A655CBE97719DAF71B0DD2A785F66F459ECA3F4F`; ledger state reconciled to `applied`.
- [x] C3VR-076 - B009 callback -> `by-memory/0x00552110-0x005534a0.TextDialogCore.md` :: Metadata; already-present the claim "Aggregate score remains `88/90`." Callback verification: `already-present` in exact destination SHA-256 `75F46C453A4EDC6CA459236BDF514B59327A2D3E1500422B459C446DD0FCFC3A`; ledger state reconciled to `already-present`.
- [x] C3VR-077 - Supervisor manual -> `by-memory/-coverage-report.md` :: UID0003VR row; exact `93%` payload supervisor-applied and verified by command `000000020704`, exit 0, `ok: 1`; ledger state `applied`.
- [x] C3VR-078 - Supervisor manual -> `by-class/-coverage-report.md` :: UID0000EL row; exact `90%` payload supervisor-applied and verified by command `000000020706`, exit 0, `ok: 1`; ledger state `applied`.
- [x] C3VR-079 - Supervisor manual -> `by-file/-coverage-report.md` :: UID0000OL row; exact `90%` payload supervisor-applied and verified by command `000000020705`, exit 0, `ok: 1`; ledger state `applied`.
- [x] C3VR-080 - Supervisor manual -> `by-memory/-coverage-report.md` :: UID0001FJ row; exact refreshed `88%` payload supervisor-applied and verified by command `000000020704`, exit 0, `ok: 1`; ledger state `applied`.

### Granular supervisor and callback operations

- [x] I3VR-01 - Supervisor Gate 2B catalog item `0398`: created `TextDialog` ordinal `970`, direct base `PursuitMessageDialogPane` ordinal `736`, size 632/`0x278`, zero own members; exact dependency/protection readback passed.
- [x] I3VR-02 - Supervisor Gate 2B: `0x00553180` is `TextDialog_OnControlCommand` with exact accepted `TextDialog *this, int controlIndex, int notifyCode` signature/comment and preserved body/xrefs/frame behavior.
- [x] I3VR-03 - Supervisor Gate 2B: `0x0049dad0` is `DialogPane_CloseDialog` with exact accepted `DialogPane *this` signature/comment; address-regular `pane` and body/xrefs preserved.
- [x] I3VR-04 - Supervisor Gate 2B applied the accepted jump-table repeatable comment and preserved the 16-byte item, name/type, regular comment, entries, and xrefs.
- [x] I3VR-05 - Supervisor Gate 2B applied the accepted alignment regular comment and preserved eight `0xcc` bytes, unnamed/untyped state, zero xrefs, and absent repeatable comment.
- [x] I3VR-06 - Supervisor Gate 2B applied the accepted vtable-slot repeatable comment and preserved cell value/xref plus parent compiler vtable identity.
- [x] I3VR-07 - Supervisor Gate 2B applied the accepted control-1 repeatable comment and preserved item/label/type/xrefs/body.
- [x] I3VR-08 - Supervisor Gate 2B applied the accepted control-2 repeatable comment and preserved item/label/type/helper/xrefs/body.
- [x] I3VR-09 - Supervisor Gate 2B applied the accepted control-3 repeatable comment and preserved item/label/type/helper/xrefs/body.
- [x] I3VR-10 - Supervisor Gate 2B applied the accepted control-4 repeatable comment and preserved item/label/type/helper/xrefs/body.
- [x] I3VR-P01 - Supervisor Gate 2B protected readback passed: raw-island start remains nonfunction, unnamed/untyped/comment-absent with zero inbound xrefs.
- [x] I3VR-P02 - Supervisor Gate 2B protected readback passed: parent vtable `??_7TextDialog@@6B@` retains exact name/type/comments/xrefs.
- [x] I3VR-P03 - Supervisor Gate 2B protected readback passed: range-failure tail retains exact label/type/comments and two-inbound/one-outbound xrefs.
- [x] Manual coverage operation - Supervisor applied UID0003VR exact target row and validated by-memory with `000000020704`, exit 0, `ok: 1`.
- [x] Manual coverage operation - Supervisor applied UID0001FJ exact parent row and validated by-memory with `000000020704`, exit 0, `ok: 1`.
- [x] Manual coverage operation - Supervisor applied UID0000EL exact class row and validated by-class with `000000020706`, exit 0, `ok: 1`.
- [x] Manual coverage operation - Supervisor applied UID0000OL exact file row and validated by-file with `000000020705`, exit 0, `ok: 1`.
- [x] Generated output - Supervisor command `000000020707` at `2026-08-01 10:21:37` produced one UID0003VR definition/declaration and zero target empty markers.
- [x] Generated tracker - Supervisor command `000000020707` reconciled tracker/coverage to target `93/94`, class `90/93`, file `90/92`, aggregate `88/90`.
- [x] Scoped validator - B009 ran `python .\tools\validator.py --mode file --file by-memory\0x00553180-0x00553338.TextDialogHandleDialogAction.md --apply --queue-timeout 240 --no-generated-refresh`; command `000000020652`, `2026-08-01T09:17:09-04:00`, exit 0, `ok: 1`.
- [x] Scoped validator - B009 ran `python .\tools\validator.py --mode file --file by-class\TextDialog.md --apply --queue-timeout 240 --no-generated-refresh`; command `000000020653`, `2026-08-01T09:17:19-04:00`, exit 0, `ok: 1`.
- [x] Scoped validator - B009 ran `python .\tools\validator.py --mode file --file by-file\TextDialog.md --apply --queue-timeout 240 --no-generated-refresh`; command `000000020654`, `2026-08-01T09:17:24-04:00`, exit 0, `ok: 1`.
- [x] Scoped validator - B009 ran `python .\tools\validator.py --mode file --file by-memory\0x00552110-0x005534a0.TextDialogCore.md --apply --queue-timeout 240 --no-generated-refresh`; command `000000020655`, `2026-08-01T09:17:31-04:00`, exit 0, `ok: 1`.
- [x] Scoped validator - Supervisor validated `by-memory/-coverage-report.md` with command `000000020704`, exit 0, `ok: 1`.
- [x] Scoped validator - Supervisor validated `by-class/-coverage-report.md` with command `000000020706`, exit 0, `ok: 1`.
- [x] Scoped validator - Supervisor validated `by-file/-coverage-report.md` with command `000000020705`, exit 0, `ok: 1`.
- [x] Callback reconciliation - B009 ordinary claims plus supervisor Gate 2B/manual/generated outcomes are reconciled without deleting accepted research; ledger states are `applied` or `already-present` only.
- [x] Lifecycle authority policy acknowledgment - B009 did not run or probe lifecycle commands. Historical supervisor commands `000000020708`/`000000020709` are recorded only as incident facts; current execution/archive truth is authoritative solely from path and validator-owned history.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000020708","destination_path":"executed-b-agent-research/B009/0003VR-TextDialogHandleDialogAction-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0003VR-TextDialogHandleDialogAction-empty-emitter-source-quality.md","timestamp":"2026-08-01T10:28:40-04:00","uid":"0003VR"} -->
<!-- {"agent":"B009","command_id":"000000020709","destination_path":"tools/leaser/Agents/Agent-B009/research/0003VR-TextDialogHandleDialogAction-empty-emitter-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B009/0003VR-TextDialogHandleDialogAction-empty-emitter-source-quality.md","timestamp":"2026-08-01T10:30:21-04:00","uid":"0003VR"} -->
<!-- {"agent":"B009","command_id":"000000020721","destination_path":"executed-b-agent-research/B009/0003VR-TextDialogHandleDialogAction-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0003VR-TextDialogHandleDialogAction-empty-emitter-source-quality.md","timestamp":"2026-08-02T20:20:00-04:00","uid":"0003VR"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
