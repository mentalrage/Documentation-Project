# UID00043P NewUserDialogPane2 SelectTotem Source-Quality Reanalysis
** TARGET-REPORT-UID:00043P **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **


## Finalized Report / Current Recommendation

- Current recommendation: retain the callback-applied exact signed-short `NewUserDialogPane2::SelectTotem` source method proven by the 194-byte body at `[0x0052b3a0,0x0052b462)`.
- Final disposition: [UID:00043P] remains reconstructable and emitted through [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md), retains source placement in `NexusTK/login/NewUserDialogPane2.cpp`, now records `96/96`, and keeps the target H channel blank because the class page owns the declaration.
- Accepted ordinary implementation preserves the exact four-child lookup, clear-old/select-new/store/update order, signed `short` ABI, caller-enforced `0..3` domain, child `19` text update, and packet relationship. The invented clamp, `SetChildButtonChecked`, `SetCreateUserDescriptionText`, and `LanguageMan::GetString` spellings are retained only as rejected history.
- Confidence: very strong for behavior, range, ABI, callers, field, child IDs/types, localization IDs, packet relation, owner, and source placement; strong for inferred local spelling and original formatting.

## Supporting Research

- Live read-only IDA MCP research used canonical path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `runtime_attestation` returned schema `1`, `ok:true`, and no errors, and bounded IDB-backed queries succeeded.
- The report rechecked the target, its predecessor/successor, constructor and command callers, all four resolved callees, the `NewUserDialogPane2` UDT, current source-owner docs, generated CPP/H, packet child, inherited child-access API, selected-state setter, text setter, localization lookup, current STR.RES payload, and manual coverage rows.
- A bounded read-only continuity checkpoint on `2026-08-13` established that each alignment span is one unnamed IDA data item: `[0x52b395,0x52b3a0)` is an 11-byte data item and `[0x52b462,0x52b470)` is a 14-byte data item. Both have blank name/type, absent address regular/repeatable comments, exact `CC` bytes, and zero xrefs. The earlier no-code/data/function-item observation is retained only as dated disproven history and has no current protection authority.
- Earlier UID00043P prose and formal C++ are retained as historical evidence only where still correct. Their range, owner, `m_selectedTotem` meaning, controls `14-17`, localization IDs `212-215`, and packet relationship survive; clamp and helper abstractions do not.
- Lifecycle status is not asserted in ordinary prose. The artifact's actual path together with validator-owned status/history metadata is authoritative.

## Target

- Target UID: `00043P`.
- Additional target UIDs: none.
- Declared-target inventory: [UID:00043P] `by-memory/0x0052b3a0-0x0052b462.NewUserDialogPane2SelectTotem.md`, one source-authored class method child.
- Target path: `source-3/project-documentation/by-memory/0x0052b3a0-0x0052b462.NewUserDialogPane2SelectTotem.md`.
- Assignment-time source queue/report row: `auto-generated/-ag-research-tracker.md`, `by-memory` / `Not-Covered Files - Reconstructable`, then `88/90`, with zero prior dedicated reports.
- Current supervisor classification: reconstructable source method with direct class owner/emitter [UID:00009E].
- Current callback-read scores and parent state: target `96/96`; class [UID:00009E] `93/95`; file [UID:0000LW] `93/95`; aggregate [UID:0002QR] `91/94`, non-emitting split/index.

## Current Target State

- Pre-callback metadata was `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00009E`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009E`, blank optional position, `Nested:0`. The callback changed only the target scores to `96/96`; owner, emitter, reconstructable, optional-position, and nested state remain unchanged.
- The exact child owns its CPP body; the class page owns its H declaration and the by-file page owns compilation-unit placement.
- Pre-callback C++ was nonempty but behaviorally stale: it clamped to `0..3`, stored the field before button updates, looped through an invented helper, and called an invented description helper plus the obsolete `GetString` spelling. The callback replaced it with the exact formal Section 22 body and preserved a blank target H channel.
- Pre-callback target SHA256 was `67B602AED1C4ED5038FCC56917D7B89821814D108670CB374129141860881528` at 2,084 bytes. Callback validation command `000000023055` read back the dated post-callback SHA256 `1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF`, 8,792 bytes. Gate 2A repair validation command `000000023110` at `2026-08-13T08:30:41-04:00` read back the current target SHA256 `86664B8C47F294A893C4463B82BDA992C66B0EDE23CAEF127A8957506D860585`, 9,396 bytes, 89 lines, exit `0` / `ok:1`, with generated refresh skipped.
- Existing open questions are resolved in this report: source ABI is signed `short`; the method has no clamp; child lookup is inherited `GetChild<T>`; checked-state mutation is `PrettyButtonControlPane::SetSelected`; description update is `GetChild<TextEditControlPane>(19)->SetText`; localization is `GetLocalizedString`; the four resource IDs are decoded; owner and source file remain unchanged.
- Related target/support docs checked: UIDs `00009E`, `0000LW`, `0002QR`, `00043K`, `00043O`, `00043Q`, `00043V`, `000443`, `00003T`, `0004E5`, `0004K9`, `00040P`, and `0001RP`, plus generated `NewUserDialogPane2.cpp/.h` and the three relevant manual coverage reports.
- Current IDA padding state is literal and non-source-bearing: one unnamed 11-byte data item at `[0x52b395,0x52b3a0)` and one unnamed 14-byte data item at `[0x52b462,0x52b470)`, each with blank type/name, absent address comments, exact `CC` payload, and no xrefs.
- Current artifact/lifecycle status: this document records research and the accepted ordinary callback implementation evidence. Execution/archive truth is authoritative only from its actual path and validator-owned status/history metadata.

## Executive Recommendation

- Keep [UID:00009E] as direct owner/emitter and [UID:0000LW] as the source-file route. No split, new owner, new file, or no-owner disposition is justified.
- Retain the callback-applied exact target CPP, signed-`short` class declaration, blank target H, and no-loss target/class/file/aggregate/constructor/resource documentation. Gate 2A reconfirmed all twelve ordinary destination hashes against the retained receipts.
- Retain the exact manual rows recorded by supervisor commands `000000023073` and `000000023074`. Treat command `000000023075` and its generated/tracker identities only as dated closure evidence; each gate dynamically rereads the physical generated and tracker files as current authority.
- Retain the dated supervisor Gate 2B evidence: declarative pure rename, exact receiver/short signature, exact regular function comment, and every protected bound/frame/padding/successor/dependency/UDT/comment invariant. The later bounded continuity checkpoint corrects only the two padding item classifications to one unnamed data item per exact span; bytes, hashes, bounds, comments, and zero-xref protections remain unchanged. Execution, archive, moved-artifact-audit, and reassignment state is authoritative only from the report's actual path plus validator-owned status/history metadata.

## Supervisor Active Recheck

- Supervisor assignment explicitly required exact bounds/ABI/callers/xrefs, clamp behavior, field semantics, controls `14-17`, checked-state mechanism, IDs `212-215`, description path, packet relation, class/header placement, formal CPP/H, and blocker resolution.
- No split repair is required: IDA models one function of size `0xc2`, and the following 14-byte unnamed data item contains only `0xCC` alignment before the clean successor at `0x0052b470`.
- The sole source-bearing target is complete in this report. Adjacent selector pages remain separate source children; both unnamed padding data items remain compiler alignment with no source emission.
- The old helper names were tested against the current project API surface and rejected rather than deferred.

## Inference Research Guidance Check

- Direct IDA facts, existing documentation, resource/package evidence, and source-shape inference are labeled separately throughout.
- Existing docs were treated as potentially stale. The method name/domain and owner survived reanalysis; clamp, helper calls, update order, parameter type, and constructor call expression did not.
- `by-structure.md` rules keep the body on the exact by-memory child, the declaration on the class H owner, and source ordering through the by-file page. Generated CPP/H are readback only and are never edited directly.
- Human source removes raw `sub_`, `arg_0`, `var_*`, raw vtable calls, offsets, and security-cookie lowering while retaining exact behavior.
- No Wave2/Wave3 evidence was used. Any such historical labels encountered in surrounding docs are stale and ignored absent an explicit current override.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Resolution | Classification |
| --- | --- | --- | --- |
| Clamp behavior | Complete 65-instruction disassembly, one-basic-block profile, raw bytes, five callers | No compare, branch, clamp, guard, null check, or range check exists. Constructor and command dispatch supply `0..3`; source must not add a clamp. | Direct fact |
| Parameter type | Pre-Gate-2B function type `void __thiscall(int this, __int16)`, `arg_0` size 2, `movzx` load followed by `movsx edi,si`, sibling selector ABI; persisted poststate `void __thiscall(NewUserDialogPane2 *this, __int16 totem)` with `totem` size 2 | Source parameter is signed `short`, not `int` or unsigned byte/word. | Direct fact plus source spelling inference, confirmed by persisted supervisor readback |
| Child access | Four virtual `+0x10` lookups through inherited `this+0x1fc`, each returned slot dereferenced once; current DialogPane declaration | Use inherited `GetChild<PrettyButtonControlPane>(14..17)`, not a new `SetChildButtonChecked` helper or derived `m_childControls` member. | Direct fact plus established API |
| Checked state | Two direct calls to `0x0054b700`, whose exact contract is `PrettyButtonControlPane::SetSelected(bool)` | Clear old indexed button, then select new indexed button. No loop updates all four. | Direct fact |
| Field | Reads and later writes `this+0x270`; UDT names it `m_selectedTotem`; packet sender serializes it | Preserve `int m_selectedTotem`; argument is sign-extended before assignment. | Direct fact |
| Description path | Child `19` lookup, dereference, direct `TextEditControlPane_SetText` call | Use `GetChild<TextEditControlPane>(19)->SetText(...)`; no `SetCreateUserDescriptionText` helper exists. | Direct fact plus established API |
| Localization API | Direct `g_pLanguageMan` load and call to `0x004f0350`, current exact child/API | Use `g_pLanguageMan->GetLocalizedString(totem + 212)`, not `GetString`. | Direct fact |
| Resource meaning | Read-only parse of `baram.dat` entry 9 / STR.RES at offset 11,268,984, size 7,058 | IDs 212-215 are Ju Jak, Baekho, Hyun Moo, and Chung Ryong descriptions. Keep runtime lookup, not hard-coded English. | Package evidence |
| Local source shape | Four consecutive stack pointer slots, security cookie, literal lookup sequence | A four-element `PrettyButtonControlPane *totemButtons[4]` local best reproduces the emitted stack and straight-line initialization. | Strong inference |
| Source order | Disassembly order at `0x52b3fc-0x52b44a` | Clear old, select new, store new field, then update description. | Direct fact |
| Constructor relation | `0x52afed` fresh `_rand`, `%4` normalization, call at `0x52b001` | Constructor passes a fresh `rand() % 4`; current support formal using the already-stored field is stale. | Direct fact |
| Command relation | Cases `14..17` call target at four sites with literals `0..3` | Caller domain proves valid indexes but does not authorize an internal clamp. | Direct fact |
| Ownership/placement | ECX receiver, `+0x270`, class UDT, two class-local callers, exact siblings, class/file routes | `NewUserDialogPane2` method in `NexusTK/login/NewUserDialogPane2.cpp`. | Direct fact plus source-tree inference |

Rejected alternatives: `int totem` conflicts with the 16-bit ABI; `unsigned short` conflicts with signed extension; a clamp changes execution; a four-iteration loop changes call count/order; `SetChildButtonChecked` and `SetCreateUserDescriptionText` have no accepted declaration/body; `LanguageMan::GetString` is the obsolete spelling; a direct raw manager/vtable expression is decompiler-shaped; `CreateUserDialogPane` and `NewCreateUserDialogPane` are comparison consumers, not owners.

No practical source-quality blocker remains. Original private local spelling and formatting are unrecoverable without symbols, but `totemButtons` is the narrow human name supported by role and neighboring project style; this affects confidence, not implementation readiness.

## Evidence Standards Used

- Primary evidence: canonical live IDA MCP `runtime_attestation`, `lookup_funcs`, `disasm`, `get_bytes`, `inspect_items`, `stack_frame`, `xrefs_to`, `xref_query`, `callees`, `func_profile`, `type_query`, `get_comments`, and bounded instruction queries.
- Corroboration: current by-memory/class/file/resource docs, generated CPP/H readback, manual coverage rows, direct package extraction, and sibling selector/caller patterns.
- Negative evidence: complete body contains no conditional branch or range guard; no data/vtable route exists to the nonvirtual method; each unnamed padding data item has zero xrefs; no accepted declarations or implementations exist for the two stale helper names. Zero padding xrefs do not imply undefined/no-item state.
- The evidence ladder is sufficient because exact bytes, instruction order, stack ABI, UDT layout, all callers, all callees, resources, and source APIs agree. Confidence remains below 100 only for original private naming/formatting.

## Evidence Checked

- IDA MCP: target lookup, 194 bytes, SHA256 `42B16816F675604474E03F0A6B526202023B24EA9FA2605F01630798A8EAD406`, 65 instructions, one basic block, exact frame, comments, item boundaries, five incoming code xrefs, three resolved semantic callees plus the compiler cookie, predecessor/successor functions, and both padding spans. Fresh `inspect_items`, `get_bytes`, `get_comments`, and `xrefs_to` readback established one unnamed data item per padding span, blank type/name, absent address comments, exact `CC` bytes/hashes, and zero xrefs.
- Gate 2A repair receipt: scoped validator command `000000023110` at `2026-08-13T08:30:41-04:00`, exit `0` / `ok:1`, scanned one target file, reported `projected_stats_update:1` and `stats_incremental_noop:1`, skipped generated refresh, and produced current target SHA256 `86664B8C47F294A893C4463B82BDA992C66B0EDE23CAEF127A8957506D860585`; physical reread confirmed the omitted pre-padding fact and exact persisted IDA-status prose.
- Callers: constructor `sub_52A540` at `0x52b001`; `NewUserDialogPane2__OnControlCommand` calls at `0x52b814`, `0x52b820`, `0x52b82c`, and `0x52b838`.
- Dependencies: `PrettyButtonControlPane_SetSelected` `0x54b700`, `LanguageMan__GetLocalizedString` `0x4f0350`, `TextEditControlPane_SetText` `0x498ca0`, and compiler cookie `0x5c772f`.
- Docs: target, owner class/file, aggregate, constructor, nation/shape siblings, OnControlCommand, packet sender, DialogPane, PrettyButtonControlPane, TextEditControlPane, LanguageMan, and STR.RES resource pages.
- Historical generated readback: command `000000023008`, refreshed `2026-08-12T22:25:26-04:00`, produced `NewUserDialogPane2.cpp` SHA256 `4AF8E24DD898CDDA2BDAA805EFF392FEAC94F7CD37EE8A86A9A346DDDAF432C5` and `NewUserDialogPane2.h` SHA256 `658FBB6878A63E46E07D0C5B5EEF25BD5C3C7A6D0839CF478BBE4BAA8A33B99B`. Those superseded files reflected the stale target CPP/int declaration and are retained only as dated historical evidence, not current authority.
- Dated Gate 1 generated snapshot after physical reread: `auto-generated/NexusTK/login/NewUserDialogPane2.cpp` SHA256 `0D12F59803BE58927D36063C604363317A3AAF2115F5E4B0FC82AAA638872888`, 14,817 bytes, and `auto-generated/NexusTK/login/NewUserDialogPane2.h` SHA256 `7DF09EC7FD5C2ECBC408FF061F98350330F18340FF91A866030EF703F53D0980`, 1,855 bytes. Both headers record command `000000023042`, timestamp `2026-08-13T01:06:08-04:00`, source `foreground-generated-refresh`. This is a dated observation only; every later gate must reread the exact paths and header metadata dynamically.
- Resource check: current STR.RES lines 212-215 decoded read-only under code page 949; source recommendation preserves numeric runtime lookup.
- Failed/unavailable checks: none. No decompiler/export endpoint was required; disassembly, bytes, types, and callers directly close the method.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C43P-001 | 00043P | Exact source body is `[0x0052b3a0,0x0052b462)`, 194 bytes, SHA256 `42B16816F675604474E03F0A6B526202023B24EA9FA2605F01630798A8EAD406`, 65 instructions, one basic block. | 99 | Actor B004; live lookup/disasm/bytes/profile.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | `by-memory/0x0052b3a0-0x0052b462.NewUserDialogPane2SelectTotem.md` / Exact Binary Identity | incorporate | applied |
| C43P-002 | 00043P | Predecessor ends at `0x52b395`; `[0x52b395,0x52b3a0)` is an 11-byte no-source alignment span with SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`. `[0x52b462,0x52b470)` is a 14-byte no-source alignment span with SHA256 `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`; successor starts cleanly at `0x52b470`. | 99 | Actor B004; inspect_items/get_bytes/xrefs_to; repair command `000000023110` at `2026-08-13T08:30:41-04:00`, exit `0` / `ok:1`, generated skipped; current SHA256 `86664B8C47F294A893C4463B82BDA992C66B0EDE23CAEF127A8957506D860585`; physical reread confirms both exact spans/hashes and zero-xref no-source disposition. | target / Range And Padding | incorporate | applied |
| C43P-003 | 00043P | Source ABI is `void NewUserDialogPane2::SelectTotem(short totem)`; current stack argument is size 2 and signed-extended. | 98 | Actor B004; type/frame/disasm and sibling ABI.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / ABI And Source Signature | incorporate | applied |
| C43P-004 | 00043P | Pre-Gate-2B IDA state was `sub_52B3A0`, `void __thiscall(int this, __int16)`, exact eight-row frame, and four absent comment channels; Section 21 records the dated stable poststate. | 99 | Actor B004; inspect_items/stack_frame/get_comments established prestate; dated independent supervisor evidence established the exact poststate; repair command `000000023110` at `2026-08-13T08:30:41-04:00`, exit `0` / `ok:1`, generated skipped; current SHA256 `86664B8C47F294A893C4463B82BDA992C66B0EDE23CAEF127A8957506D860585`; physical reread contains the exact current name/type/frame/comment and historical prechange paragraph. | target / IDA Prechange And Persisted State | incorporate | applied |
| C43P-005 | 00043P | The method performs four inherited child lookups for selectors 14, 15, 16, and 17 and dereferences each returned slot as a PrettyButton control. | 99 | Actor B004; instructions `0x52b3b9-0x52b3fc`.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / Exact Behavior | incorporate | applied |
| C43P-006 | 00043P | Human source uses one four-element `PrettyButtonControlPane *totemButtons[4]` local; it accounts for the four consecutive pointer slots and cookie without decompiler locals. | 94 | Actor B004; frame/straight-line lookup/source style.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / Source Shape | incorporate | applied |
| C43P-007 | 00043P | The control indexed by current `m_selectedTotem` is cleared first with `SetSelected(false)`. | 99 | Actor B004; `0x52b3fc-0x52b412`.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / Exact Behavior | incorporate | applied |
| C43P-008 | 00043P | The control indexed by signed-short argument is selected next with `SetSelected(true)`. | 99 | Actor B004; `0x52b412-0x52b420`.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / Exact Behavior | incorporate | applied |
| C43P-009 | 00043P | Only after both state calls, the sign-extended argument is stored to `m_selectedTotem` at `+0x270`. | 99 | Actor B004; `0x52b420-0x52b42c`, UDT.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / Exact Behavior | incorporate | applied |
| C43P-010 | 00043P | The method has no clamp, guard, null check, loop, or conditional branch; caller domain supplies 0-3. | 99 | Actor B004; complete one-block disassembly and caller literals.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / Negative Evidence | reject-stale | applied |
| C43P-011 | 00043P | Child selector 19 resolves to the TextEdit control receiving `SetText`. | 98 | Actor B004; `0x52b420-0x52b44f`, callee type.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / Description Update | incorporate | applied |
| C43P-012 | 00043P | Description text is `g_pLanguageMan->GetLocalizedString(totem + 212)`, producing IDs 212-215. | 99 | Actor B004; global/callee/LEA evidence.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / Localization | incorporate | applied |
| C43P-013 | 0001RP | Current STR.RES IDs 212-215 decode to Ju Jak, Baekho, Hyun Moo, and Chung Ryong descriptions; source keeps lookup IDs. | 97 | Actor B004; read-only package parse and parser contract.; callback command 000000023063; SHA256 265E6B6C1764614887F6137E0B764CEAE47A44EAA6681BD5D7BC9612F9CDDBBF | `by-resource/str-res-localized-strings.md` / Confirmed High-Value String IDs | incorporate | applied |
| C43P-014 | 00043K | Constructor makes one direct call at `0x52b001` with a fresh normalized `_rand() % 4` value. | 99 | Actor B004; bounded instruction query `0x52afed-0x52b001`.; callback command 000000023059; SHA256 1FD3E834A3071B8C0697D1FC518AA63E12B67BAF128E47475401CF4A995AD893 | `by-memory/0x0052a540-0x0052b047.NewUserDialogPane2Constructor.md` / initialization and calls | incorporate | applied |
| C43P-015 | 00043V | OnControlCommand cases 14-17 call the method with literal 0,1,2,3 and return. | 99 | Actor B004; live disasm at four call sites.; physical callback reread; SHA256 97CAEB14516765A928D255FAF9808DA57B22005362AB437D711CD6BC6F81CDD7 | `by-memory/0x0052b760-0x0052b88c.NewUserDialogPane2OnControlCommand.md` / command cases | already-present | already-present |
| C43P-016 | 00043P | Five direct code xrefs exist, contained by exactly two caller functions; there are no data/vtable xrefs. | 99 | Actor B004; xrefs_to/profile.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / Caller Inventory | incorporate | applied |
| C43P-017 | 00043P | Semantic callees are PrettyButton `SetSelected`, LanguageMan `GetLocalizedString`, TextEdit `SetText`; the cookie check is compiler lowering. | 99 | Actor B004; callees/disasm/profiles.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / Callee Inventory | incorporate | applied |
| C43P-018 | 000443 | SendCreateCharacterRequest serializes `m_selectedTotem` directly after one-based nation and before account text. | 98 | Actor B004; current exact packet child and field route.; physical callback reread; SHA256 7D1C20FDDDE153146E204EDA306F42717333398A6BA171ABBF7DFFD8EDD8C5B8 | `by-memory/0x0052bdd0-0x0052bfc2.NewUserDialogPane2SendCreateCharacterRequest.md` / Evidence And Behavior | already-present | already-present |
| C43P-019 | 00009E | NewUserDialogPane2 is the sole direct class owner/emitter; class UDT places `m_selectedTotem` at `+0x270`. | 99 | Actor B004; receiver/UDT/callers/class route.; callback command 000000023056; SHA256 AF9082E2ACA681AFC675E254217AA0508B597656CBDA47D99913371E23A270D8 | `by-class/NewUserDialogPane2.md` / method and layout evidence | incorporate | applied |
| C43P-020 | 0000LW | Source placement is `NexusTK/login/NewUserDialogPane2.cpp` with declaration in its generated class H route. | 97 | Actor B004; by-file route and siblings.; callback command 000000023057; SHA256 9D52C68736B07916AF5C81424F1D567BA23F99A5074BA301454869530AB91472 | `by-file/NewUserDialogPane2.md` / Proposed Contents and source placement | incorporate | applied |
| C43P-021 | 00043P | Metadata becomes 96/96; owner 00009E, reconstructable true, emitter 00009E, blank position, and Nested 0 remain. | 96 | Actor B004; blocker closure and source readiness.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / metadata headers and Score Rationale | incorporate | applied |
| C43P-022 | 00043P | Item Summary becomes the exact no-metadata behavior summary stated in Section 24. | 97 | Actor B004; generated-summary policy.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / Item Summary | incorporate | applied |
| C43P-023 | 00043P | Target CPP is replaced exactly by the formal body in Section 22. | 97 | Actor B004; full binary/source reconstruction.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / RECONSTRUCTION_CPP CODE | incorporate | applied |
| C43P-024 | 00043P | Target H remains blank because the class owner emits the declaration. | 99 | Actor B004; source-channel ownership.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / RECONSTRUCTION_H CODE | already-present | already-present |
| C43P-025 | 00043P | `SetChildButtonChecked`, `SetCreateUserDescriptionText`, and `GetString` are historical stale abstractions, not emitted APIs. | 98 | Actor B004; project API search plus live callees.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / Historical Corrections | historicalize | applied |
| C43P-026 | 00043P | Clamp, loop, store-first order, and broad helper draft are rejected because they change exact call count/order and out-of-domain behavior. | 99 | Actor B004; complete CFG and bytes.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / Historical Corrections and Negative Evidence | reject-stale | applied |
| C43P-027 | 00009E | Class H declaration changes only `SelectTotem(int)` to `SelectTotem(short)`. | 98 | Actor B004; exact ABI.; callback command 000000023056; SHA256 AF9082E2ACA681AFC675E254217AA0508B597656CBDA47D99913371E23A270D8 | `by-class/NewUserDialogPane2.md` / RECONSTRUCTION_H CODE | incorporate | applied |
| C43P-028 | 00009E | Class method table gains exact selectors, update order, child 19/localization, no-clamp caller contract, and packet relation. | 97 | Actor B004; target and support evidence.; callback command 000000023056; SHA256 AF9082E2ACA681AFC675E254217AA0508B597656CBDA47D99913371E23A270D8 | class / Exact Totem Selection Contract | incorporate | applied |
| C43P-029 | 0000LW | File inventory/source notes gain the exact UID00043P behavior and stale-helper correction. | 97 | Actor B004; compilation-unit route.; callback command 000000023057; SHA256 9D52C68736B07916AF5C81424F1D567BA23F99A5074BA301454869530AB91472 | `by-file/NewUserDialogPane2.md` / Proposed Contents and exact selector section | incorporate | applied |
| C43P-030 | 0002QR | Aggregate UID00043P row and naming/source-shape prose gain full exact behavior and API decisions without emitting duplicate CPP. | 97 | Actor B004; split-index policy.; callback command 000000023058; SHA256 2452285618EE2583A1F3569BB63F48EF33A74DC1A8043AFCCC116186AF244453 | `by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md` / child inventory and naming | incorporate | applied |
| C43P-031 | 00043K | Exact owning-constructor formal CPP replacement preserves the complete current constructor source and changes only its final selector call from `SelectTotem(m_selectedTotem);` to `SelectTotem(rand() % 4);`; the literal full replacement payload is mirrored in Sections 22 and 25. | 96 | Actor B004; direct call at `0x52b001` passes fresh `_rand() % 4`; current UID00043K formal CPP physical reread.; callback command 000000023059; SHA256 1FD3E834A3071B8C0697D1FC518AA63E12B67BAF128E47475401CF4A995AD893 | `by-memory/0x0052a540-0x0052b047.NewUserDialogPane2Constructor.md` / `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| C43P-032 | 00043V | Existing command cases 14-17 already express `controlIndex - 14`; preserve unchanged and add no target clamp. | 99 | Actor B004; physical doc and live disasm.; physical callback reread; SHA256 97CAEB14516765A928D255FAF9808DA57B22005362AB437D711CD6BC6F81CDD7 | OnControlCommand / formal CPP and evidence | already-present | already-present |
| C43P-033 | 000443 | Existing direct totem-byte serialization is correct and remains unchanged. | 99 | Actor B004; physical support doc.; physical callback reread; SHA256 7D1C20FDDDE153146E204EDA306F42717333398A6BA171ABBF7DFFD8EDD8C5B8 | packet child / formal CPP and behavior | already-present | already-present |
| C43P-034 | 00003T | Existing protected `GetChild<T>(int) const` API is the exact source-facing replacement for inherited `+0x1fc` lookup lowering. | 98 | Actor B004; current DialogPane declaration.; physical callback reread; SHA256 86BF78FF08827147CBB1FD71849670B21E282DAB54E13FFABF25273265C3D64C | `by-class/DialogPane.md` / protected child-access contract | already-present | already-present |
| C43P-035 | 0004E5 | Existing `PrettyButtonControlPane::SetSelected(bool)` contract exactly owns state byte and invalidation. | 99 | Actor B004; exact child and live callee.; physical callback reread; SHA256 B5B7428B67A254050EDC426DD694B5C8424E883E3E10AB18659E394F5A3DC127 | PrettyButton SetSelected child / Evidence | already-present | already-present |
| C43P-036 | 0004K9 | Existing `TextEditControlPane::SetText(const wchar_t *)` contract exactly owns description replacement. | 99 | Actor B004; exact child and live callee.; physical callback reread; SHA256 7BA5479E5F2317648B4F409B4CA046591D47BC90BCBE6FC050275805E4E824AB | TextEdit SetText child / Exact Evidence | already-present | already-present |
| C43P-037 | 00040P | Existing `LanguageMan::GetLocalizedString(int) const` contract and canonical spelling are correct. | 99 | Actor B004; exact child and live callee.; physical callback reread; SHA256 E049B5819BAC227EBF50EE25A4BCFE6BCF059968C5A7E2294F9871738D4A0FCF | LanguageMan lookup child / Status and Behavior | already-present | already-present |
| C43P-038 | 0001RP | Resource page adds exact IDs 212-215, decoded text, UID00043P consumer, and runtime-lookup policy. | 97 | Actor B004; direct payload extraction and call.; callback command 000000023063; SHA256 265E6B6C1764614887F6137E0B764CEAE47A44EAA6681BD5D7BC9612F9CDDBBF | `by-resource/str-res-localized-strings.md` / Confirmed High-Value String IDs | incorporate | applied |
| C43P-039 | 00043P | Supervisor IDA action I43P-01 is declarative operation `rename` at `0x0052b3a0` to `NewUserDialogPane2__SelectTotem` with literal `pure:true`. | 98 | Actor supervisor; dated independent evidence records the exact prestate and stable direct readback in Section 21. | Supervisor IDA action I43P-01 | incorporate | applied |
| C43P-040 | 00043P | Supervisor IDA action I43P-02 has applied the exact receiver/short signature and verified literal normalized frame readback. | 98 | Actor supervisor; persisted readback is `void __thiscall(NewUserDialogPane2 *this, __int16 totem)`, with `totem@+0x28/2` and all seven nonargument rows unchanged. | Supervisor IDA action I43P-02 | incorporate | applied |
| C43P-041 | 00043P | Supervisor IDA action I43P-03 has added the exact regular function comment while preserving three other comment channels absent. | 96 | Actor supervisor; dated independent evidence records the exact regular function comment and three absent channels. | Supervisor IDA action I43P-03 | incorporate | applied |
| C43P-042 | 00043P | Supervisor Gate 2B and the later bounded continuity checkpoint preserve body bytes/bounds/frame locals, both exact unnamed padding data items, successor, UDT layout, callees, xrefs, globals, and all protected comments. | 99 | Actor supervisor for persisted Gate 2B state; B004 read-only continuity evidence. Body SHA `42B16816F675604474E03F0A6B526202023B24EA9FA2605F01630798A8EAD406`, pre-pad SHA `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`, post-pad SHA `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`, five xrefs, four callees, successor/dependencies, UDT and comments match; earlier no-item padding classification is dated disproven history only. | Supervisor IDA protection P43P-01 | incorporate | applied |
| C43P-042A | 00043P | P43P-01a target body remains `[0x52b3a0,0x52b462)`, 194 bytes, 65 instructions, SHA256 `42B16816F675604474E03F0A6B526202023B24EA9FA2605F01630798A8EAD406`, with five exact incoming code xrefs and four exact callees. | 99 | Actor supervisor for persisted protection; B004 bounded read-only continuity checkpoint used lookup_funcs, get_bytes, disasm, xrefs_to, and callees. | Supervisor IDA protection P43P-01a | incorporate | applied |
| C43P-042B | 00043P | P43P-01b pre-pad is exactly one unnamed data item `[0x52b395,0x52b3a0)`, size 11, blank name/type, `is_data:true`, `is_code:false`, 11 `CC` bytes, SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`, absent address comments, and zero xrefs. | 99 | Actor supervisor for persisted protection; B004 bounded read-only inspect_items/get_bytes/get_comments/xrefs_to continuity readback. Earlier no-item observation is dated disproven history only. | Supervisor IDA protection P43P-01b | incorporate | applied |
| C43P-042C | 00043P | P43P-01c post-pad is exactly one unnamed data item `[0x52b462,0x52b470)`, size 14, blank name/type, `is_data:true`, `is_code:false`, 14 `CC` bytes, SHA256 `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`, absent address comments, and zero xrefs. | 99 | Actor supervisor for persisted protection; B004 bounded read-only inspect_items/get_bytes/get_comments/xrefs_to continuity readback. Earlier no-item observation is dated disproven history only. | Supervisor IDA protection P43P-01c | incorporate | applied |
| C43P-042D | 00043P | P43P-01d successor remains `[0x52b470,0x52b52c)`, size `0xbc`, entry `[0x52b470,0x52b471)` code, name `sub_52B470`, type `int __thiscall(int this, __int16)`, with all four comment channels absent. | 99 | Actor supervisor for persisted protection; B004 bounded read-only lookup_funcs/inspect_items/get_comments continuity readback. | Supervisor IDA protection P43P-01d | incorporate | applied |
| C43P-042E | 00043P | P43P-01e dependency `0x54b700` retains exact bounds/item/name/type and its exact function-regular `SetSelected(bool)` contract; the other three comment channels remain absent. | 99 | Actor supervisor for persisted protection; B004 bounded read-only lookup_funcs/inspect_items/get_comments continuity readback. | Supervisor IDA protection P43P-01e | incorporate | applied |
| C43P-042F | 00043P | P43P-01f dependency `0x4f0350` retains exact bounds/item/name/type and its exact function-regular `GetLocalizedString(int)` contract; the other three comment channels remain absent. | 99 | Actor supervisor for persisted protection; B004 bounded read-only lookup_funcs/inspect_items/get_comments continuity readback. | Supervisor IDA protection P43P-01f | incorporate | applied |
| C43P-042G | 00043P | P43P-01g dependency `0x498ca0` retains exact bounds/item/name/type and its exact function-regular null-preserving `SetText` contract; the other three comment channels remain absent. | 99 | Actor supervisor for persisted protection; B004 bounded read-only lookup_funcs/inspect_items/get_comments continuity readback. | Supervisor IDA protection P43P-01g | incorporate | applied |
| C43P-042H | 00043P | P43P-01h compiler dependency `0x5c772f` retains exact bounds, six-byte entry item, name `@__security_check_cookie@4`, type `void __fastcall(uintptr_t StackCookie)`, and four absent comment channels. | 99 | Actor supervisor for persisted protection; B004 bounded read-only lookup_funcs/inspect_items/get_comments continuity readback. | Supervisor IDA protection P43P-01h | incorporate | applied |
| C43P-042I | 00043P | P43P-01i UDT `NewUserDialogPane2` remains size `0x280` with exactly seven unchanged members and literal names/offsets/widths/types. | 99 | Actor supervisor for persisted protection; B004 bounded read-only type_inspect continuity readback. | Supervisor IDA protection P43P-01i | incorporate | applied |
| C43P-042J | 00043P | P43P-01j target frame retains all seven nonargument rows with literal names, offsets, widths, and types; `totem@+0x28/2/__int16` remains the sole argument row. | 99 | Actor supervisor for persisted protection; B004 bounded read-only stack_frame/disasm continuity readback. | Supervisor IDA protection P43P-01j | incorporate | applied |
| C43P-043 | 00043P | Manual by-memory coverage contains the exact UID00043P row in Section 28. | 97 | Actor supervisor; command `000000023073` exit `0`/`ok:1` inserted the exact row and produced dated post-command SHA `D563B2D2DF4833B322D448CCC65BBE3421FE687E2B37D865A435AEAE1112F215`; current read-only manual coverage SHA `44C693D1EDF4824D8207D5444B478A9C4A1AA6835C3D69E6F859E999D1FCE681`, with the exact UID00043P row present once. | `by-memory/-coverage-report.md` / UID00043P row | incorporate | applied |
| C43P-044 | 0001RP | Manual by-resource coverage contains the exact resource/consumer replacement wording in Section 28. | 96 | Actor supervisor; command `000000023074` exit `0`/`ok:1` replaced the exact row; current manual coverage SHA `629335DCF598ED77C08CF0B1557E871AC2F2D4163A736D2DE2BBFE38F2B03A7D`. | `by-resource/-coverage-report.md` / UID0001RP row | incorporate | applied |
| C43P-045 | 00043P | Every changed ordinary destination has scoped file validation with generated refresh disabled and retained receipts. | 99 | Actor B004; V43P-01 commands `000000023055`-`000000023059` and `000000023063` all exit `0`/`ok:1` with generated skipped; target repair command `000000023110` exit `0`/`ok:1` with generated skipped binds current target SHA256 `86664B8C47F294A893C4463B82BDA992C66B0EDE23CAEF127A8957506D860585`; all destinations were physically reread. | Validation receipt set V43P-01 / Section 31 exact paths | incorporate | applied |
| C43P-046 | 0000LW | A coherent generated CPP/H refresh and physical readback completed after ordinary docs and supervisor manual/IDA work. | 99 | Actor supervisor; dated command `000000023075` exit `0`/`ok:1` produced CPP SHA `BB36BADF5CF3A70012FDB3D413C1D36EF35034A271D759390AB8B0CA15DAEC01` and H SHA `7C8F32DC38B48EA6F188ED0FB9A28E4AF3A3606A4A1854ED6EEA80C93CCD77FD`, with exact body/declaration and no target empty marker; later gates dynamically reread current authority. | Supervisor generated action G43P-01 | incorporate | applied |
Current allocation: all 56 substantive claims are checked/current: the original `C43P-001` through `C43P-046` plus itemized protection rows `C43P-042A` through `C43P-042J`. They comprise 39 B004 ordinary/validation claims and 17 supervisor-owned IDA/manual/generated/protection claims. Lifecycle operations are not represented as research/incorporation claims.

## Positive Evidence Summary

- Exact modeled function, body hash, instruction order, frame, direct calls, field access, constants, and caller fan-in agree on a compact source-authored selector.
- Constructor and command callers prove the accepted index domain. Packet serialization proves the `+0x270` field's totem meaning beyond UI appearance.
- Exact dependency children close every source-facing call: inherited typed lookup, PrettyButton selection, TextEdit replacement, and LanguageMan localization.
- Resource IDs 212-215 independently name four Nexus totems, corroborating the field/method name.
- Class UDT, source siblings, generated routing, and by-file ownership all converge on NewUserDialogPane2 with no ownership competition.

## IDA MCP Facts

- Prechange function state was `sub_52B3A0`, `[0x52b3a0,0x52b462)`, size `0xc2`, type `void __thiscall(int this, __int16)`, return `void`, 65 instructions, one basic block. Persisted poststate is `NewUserDialogPane2__SelectTotem` with exact type `void __thiscall(NewUserDialogPane2 *this, __int16 totem)`.
- Raw body SHA256: `42B16816F675604474E03F0A6B526202023B24EA9FA2605F01630798A8EAD406`.
- Persisted frame: `var_14@+0xc size4 PrettyButtonControlPane *`; `var_10@+0x10 size4 _DWORD`; `var_C@+0x14 size4 _DWORD`; `var_8@+0x18 size4 _DWORD`; `var_4@+0x1c size4 _DWORD`; `__saved_registers@+0x20`; `__return_address@+0x24`; `totem@+0x28 size2 __int16`. The seven nonargument rows are unchanged from prestate.
- Persisted comments at entry: address regular absent; address repeatable absent; function regular equals `Selects totem index 0..3 supplied by constructor or controls 14..17: clears the previous PrettyButton selection, selects the new control, stores m_selectedTotem, and updates TextEdit child 19 from STR.RES[212 + totem]. This method performs no clamp.`; function repeatable absent.
- UDT `NewUserDialogPane2`: size `0x280`; DialogPane base `0x26c`; `m_selectedNation+0x26c`; `m_selectedTotem+0x270`; `m_selectedShapeSlot+0x274`; `m_waitingForCharacterReply+0x278`; alignment; `m_nexonclubAccountName+0x27c`.
- Incoming xrefs: `0x52b001`, `0x52b814`, `0x52b820`, `0x52b82c`, `0x52b838`; all code, no truncation.
- Complete direct callee set: three semantic callees at `0x54b700`, `0x4f0350`, and `0x498ca0`, plus compiler cookie check `0x5c772f`; bounded `callees` returned `more:false` and no unresolved semantic callee.
- Constants include controls `14-17`, booleans `0/1`, child `19`, local stack size `0x14`, and return pop `4`.
- Boundary: predecessor function ends at `0x52b395`; the pre-pad is one unnamed data item `[0x52b395,0x52b3a0)`, size 11, blank name/type, `is_data:true`, `is_code:false`, exact `CC` payload SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`, absent address regular/repeatable comments, and zero xrefs. The post-pad is one unnamed data item `[0x52b462,0x52b470)`, size 14, blank name/type, `is_data:true`, `is_code:false`, exact `CC` payload SHA256 `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`, absent address regular/repeatable comments, and zero xrefs. Successor `sub_52B470` starts at `0x52b470`.
- Dated supervisor Gate 2B evidence from `2026-08-13` is bound to canonical path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; runtime attestation reported schema `1`, `ok:true`, and no errors. A later bounded continuity checkpoint reconfirmed every target/dependency/UDT/frame/global fact and corrected the two padding classifications from the earlier no-item observation to the literal unnamed data-item states above. The old no-item result is retained only as dated disproven history.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[0x52b395,0x52b3a0)` | compiler alignment | one unnamed 11-byte IDA data item containing only CC alignment between UID00043O and target | no source | UID0002QR | N/A | protect exact item/bounds/bytes/comments; no emission |
| `[0x52b3a0,0x52b462)` | UID00043P / target | `NewUserDialogPane2::SelectTotem(short)` | yes | UID00009E | `88/90 -> 96/96` | exact CPP replacement ready |
| `[0x52b462,0x52b470)` | compiler alignment | one unnamed 14-byte IDA data item containing only CC alignment after target | no source | UID0002QR | N/A | protect exact item/bounds/bytes/comments; no emission |
| `[0x52b470,0x52b52c)` | UID00043Q / SelectShapeSlot | clean successor method | yes | UID00009E | 88/90 | separate target; no bytes absorbed |
| `NewUserDialogPane2` H | UID00009E / by-class | owns method declaration and `+0x270` field | yes | UID0000LW | 93/95 | one declaration-type repair |
| `NewUserDialogPane2.cpp` route | UID0000LW / by-file | owns compilation unit/source order | yes | project tree | 93/95 | target detail sync |
| target cluster index | UID0002QR / aggregate | non-emitting child index | no duplicate source | UID0000LW | 91/94 | row/detail sync |
| STR.RES | UID0001RP / by-resource | owns localized payload IDs 212-215 | resource data | UID0000KK | 90/94 | consumer rows to add |

Inventory counts: one source target, one class declaration owner, one file route, one non-emitting aggregate route, one resource dependency, two adjacent padding spans, and one protected successor. Every item has an explicit CPP/H/no-code and destination disposition.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x52b001` | constructor `sub_52A540` | Fresh `_rand() % 4` initial UI-selection call. |
| `0x52b814` | OnControlCommand case 14 | Calls with `0`. |
| `0x52b820` | OnControlCommand case 15 | Calls with `1`. |
| `0x52b82c` | OnControlCommand case 16 | Calls with `2`. |
| `0x52b838` | OnControlCommand case 17 | Calls with `3`. |
| `0x54b700` | PrettyButton `SetSelected(bool)` | Called false on old indexed child, true on new indexed child. |
| `0x4f0350` | LanguageMan `GetLocalizedString(int)` | Reads ID `totem + 212`. |
| `0x498ca0` | TextEditControlPane `SetText` | Replaces child 19 description text. |
| `0x5c772f` | security-cookie check | Compiler-generated consequence of local array/frame; omit from source. |
| `0x52bdd0` packet method | reads `+0x270` | Serializes selected totem directly as one byte. |

## Documentation Evidence And IDA Status

- Gate 2A reconfirmed all twelve ordinary destinations at the exact hashes retained in Sections 11, 31, and 33. The target/support docs now carry the exact signed-short body, source order, historicalized stale abstractions, constructor fresh-random call, and STR.RES IDs 212-215 mapping.
- The former `int` signature, clamp, store-first order, synthesized loop, `SetChildButtonChecked`, `SetCreateUserDescriptionText`, `GetString`, shallow support rows, saved-field constructor call, and missing resource mappings remain documented only as superseded pre-callback history.
- Manual coverage is applied: command `000000023073` inserted the exact UID00043P by-memory row and command `000000023074` replaced the exact UID0001RP by-resource row, both exit `0` / `ok:1`.
- Dated command `000000023075` generated evidence recorded CPP SHA256 `BB36BADF5CF3A70012FDB3D413C1D36EF35034A271D759390AB8B0CA15DAEC01` and H SHA256 `7C8F32DC38B48EA6F188ED0FB9A28E4AF3A3606A4A1854ED6EEA80C93CCD77FD`, with the exact constructor call, exact UID00043P body once, exact short declaration, and no target empty marker. It is historical closure evidence, not permanent current authority; every gate rereads the physical generated files and headers dynamically.
- Dated IDA evidence records `NewUserDialogPane2__SelectTotem`, exact receiver/short type and `totem` frame row, and the exact regular function comment. The bounded continuity checkpoint reconfirmed all protected bytes, hashes, xrefs, callees, successor/dependencies, UDT/frame rows, globals, and comment channels; it corrected only the padding classification to one unnamed data item per exact span. The earlier no-item observation is historical and disproven.

## Ranked Ownership Analysis

### 1. NewUserDialogPane2

- Evidence for: ECX receiver, exact `+0x270` class field, class-local constructor/command callers, sibling selector range, class UDT, owner/emitter docs, generated route, packet consumer.
- Evidence against: no private retail symbol for the method/local names.
- Decision: sole direct owner and emitter, very strong.

### 2. NewUserDialogPane2 source file

- Evidence for: all callers/siblings and class declaration route through `NexusTK/login/NewUserDialogPane2.cpp/.h` under UID0000LW.
- Evidence against: filename is inferred from recovered class/source grouping rather than debug symbols.
- Decision: direct compilation-unit route; no new file.

### 3. CreateUserDialogPane, LanguageMan, or control classes

- Evidence for: symmetric create-user selectors and shared dependency methods provide comparison behavior.
- Evidence against: none receive the target ECX, own `+0x270`, or contain the target callers; dependencies own only reusable APIs/resources.
- Decision: reject as owners. Retain as evidence/support only.

### Proposed new file/grouping, if applicable

- Not applicable. A new selector/helper module would fragment an established class method and duplicate the existing file route.

## Source Placement

- Recommended definition: exact target child emits one qualified method into `NexusTK/login/NewUserDialogPane2.cpp` under by-file UID0000LW ordering.
- Recommended declaration: [UID:00009E] class H changes the one declaration to signed `short`; target H remains blank.
- This placement fits receiver, fields, callers, sibling methods, constructor, packet builder, and current generated routing.
- Rejected: DialogPane (owns generic lookup), PrettyButton/TextEdit/LanguageMan (own callees), CreateUserDialogPane variants (comparison classes), resource source (owns text only), or a new helper file.
- Remaining placement uncertainty: none material. Exact historical filesystem spelling cannot be independently symbol-proven, but the current source tree is coherent and complete.

## Range / Split / Padding / Reclassification Analysis

- Exact source range is the modeled `0xc2` body `[0x52b3a0,0x52b462)`; no split or merge is warranted.
- `[0x52b395,0x52b3a0)` is one unnamed 11-byte IDA data item after UID00043O, with blank name/type, absent address comments, exact `0xCC` payload SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`, and zero xrefs; target does not absorb or emit it.
- `[0x52b462,0x52b470)` is one unnamed 14-byte IDA data item, with blank name/type, absent address comments, exact `0xCC` payload SHA256 `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`, and zero xrefs; target does not absorb or emit it.
- Successor starts at `0x52b470`; no target byte overlaps UID00043Q.
- The earlier observation that no code/data/function item consumed either padding span is dated disproven history. Current protection preserves each complete unnamed data item and does not reinterpret its alignment payload as source data.
- Security-cookie instructions remain compiler output within the function body and are regenerated by the four-pointer local; they do not justify a source child.
- Parent UID0002QR remains a non-emitting split/index. Target remains one reconstructable class-method child.

## Negative Evidence Summary

- No target instruction clamps, compares, branches, validates, or null-checks the argument or child pointers.
- No loop exists; four lookups are unrolled and only two selected-state calls occur.
- No `SetChildButtonChecked` or `SetCreateUserDescriptionText` source/API declaration or call target was found; exact callees disprove them.
- No target data/vtable xref exists; this is a nonvirtual private/protected-style helper reached only by two class functions.
- No packet write occurs in this body; packet relationship is downstream through `m_selectedTotem`.
- No language text is hard-coded; the runtime resource lookup must remain.
- Consumer/callee ownership does not transfer target ownership to control, language, packet, or resource modules.
- Padding has zero xrefs and no source role; adjacent methods remain independent.

## IDA Rename / Type / Comment Recommendations

The B agent made no IDA mutation. Dated independent supervisor evidence from `2026-08-13`, bound to canonical path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, records the declarative actions and stable direct readbacks below. This report contains no operational syntax or automation.

| Action ID | Entity | Literal prechange state | Applied supervisor action | Evidence and safety constraints | Persisted direct readback | Disposition |
| --- | --- | --- | --- | --- | --- | --- |
| I43P-01 | function entry `0x0052b3a0` | Name `sub_52B3A0`; type `void __thiscall(int this, __int16)`; item `[0x52b3a0,0x52b3a1)` code head inside function `[0x52b3a0,0x52b462)`; address regular absent; address repeatable absent; function regular absent; function repeatable absent. | Operation `rename`; address `0x0052b3a0`; new name `NewUserDialogPane2__SelectTotem`; `pure:true`. | Five exact calls, receiver/field/class route, established sibling naming. Rename only; collision, overwrite requirement, or prestate mismatch rejects the action. | `lookup_funcs(0x52b3a0)` and `inspect_items(0x52b3a0)` return name `NewUserDialogPane2__SelectTotem`; the same `0xc2` function, bytes, hash, bounds, comments, xrefs and dependencies remain unchanged. | applied |
| I43P-02 | function type/frame at `0x0052b3a0` | Declaration `void __thiscall(int this, __int16)`; frame rows exactly `var_14@+0xc/4/PrettyButtonControlPane *`, `var_10@+0x10/4/_DWORD`, `var_C@+0x14/4/_DWORD`, `var_8@+0x18/4/_DWORD`, `var_4@+0x1c/4/_DWORD`, saved registers `+0x20`, return address `+0x24`, `arg_0@+0x28/2/_WORD`; all four entry comment channels as in I43P-01. | Operation `set function type`; address `0x0052b3a0`; exact source signature `void __thiscall NewUserDialogPane2__SelectTotem(NewUserDialogPane2 *this, short totem)`; no separate local rename or declaration. | Signed 16-bit load/sign-extension and exact class UDT. The source local array is not forced into the stack schema. | `inspect_items(0x52b3a0)` returns exactly `void __thiscall(NewUserDialogPane2 *this, __int16 totem)`; `stack_frame(0x52b3a0)` returns `totem` at `+0x28`, size `0x2`, type `__int16`; all seven nonargument rows, bounds, bytes, xrefs and comments remain unchanged. | applied |
| I43P-03 | regular function comment at `0x0052b3a0` | Address regular absent; address repeatable absent; function regular absent; function repeatable absent. | Operation `set function-regular comment`; address `0x0052b3a0`; exact text `Selects totem index 0..3 supplied by constructor or controls 14..17: clears the previous PrettyButton selection, selects the new control, stores m_selectedTotem, and updates TextEdit child 19 from STR.RES[212 + totem]. This method performs no clamp.` | Exact behavior/callers/resource mapping. Address and repeatable comment channels are protected no-change channels. | Function regular equals the literal action text; address regular absent; address repeatable absent; function repeatable absent. | applied |

Protection/readback contract:

| Protection ID | Protected invariant | Persisted readback requirement |
| --- | --- | --- |
| P43P-01a | Target body `[0x52b3a0,0x52b462)`, 194 bytes, SHA256 `42B16816F675604474E03F0A6B526202023B24EA9FA2605F01630798A8EAD406`, 65 instructions, five incoming code xrefs, exactly three semantic callees plus cookie. | Byte hash, bounds, instruction count, five xrefs, and exact four-entry direct-callee set unchanged after all three actions. |
| P43P-01b | Pre-pad is exactly one unnamed data item `[0x52b395,0x52b3a0)`, size 11, data classification (`is_data:true`, `is_code:false`), blank name, blank type, 11 `CC` bytes, SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`, address regular absent, address repeatable absent, and zero xrefs. | One item with exact head/end/size/classification, blank name/type, exact bytes/hash, absent address comments, and zero xrefs; no function or neighboring item consumes any byte. |
| P43P-01c | Post-pad is exactly one unnamed data item `[0x52b462,0x52b470)`, size 14, data classification (`is_data:true`, `is_code:false`), blank name, blank type, 14 `CC` bytes, SHA256 `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`, address regular absent, address repeatable absent, and zero xrefs. | One item with exact head/end/size/classification, blank name/type, exact bytes/hash, absent address comments, and zero xrefs; no function or neighboring item consumes any byte. |
| P43P-01d | Successor function is exactly `[0x52b470,0x52b52c)`, size `0xbc`; entry item `[0x52b470,0x52b471)`, size 1, code; name `sub_52B470`; type `int __thiscall(int this, __int16)`; address regular absent; address repeatable absent; function regular absent; function repeatable absent. | Function/entry bounds, size, code classification, name, and type remain literal matches; address regular absent; address repeatable absent; function regular absent; function repeatable absent. |
| P43P-01e | Dependency `0x54b700`: function `[0x54b700,0x54b719)`, size `0x19`; entry item `[0x54b700,0x54b701)`, size 1, code; name `PrettyButtonControlPane_SetSelected`; type `void __thiscall(PrettyButtonControlPane *this, bool selected)`; address regular absent; address repeatable absent; function regular `Source SetSelected(bool): writes m_selected at +0x118, then invalidates the full pane bounds. Selection caller pairs establish selected semantics; this is not a hover flag.`; function repeatable absent. | Every bound/item/name/type field remains literal; address regular absent; address repeatable absent; function regular equals the literal prestate; function repeatable absent. |
| P43P-01f | Dependency `0x4f0350`: function `[0x4f0350,0x4f0372)`, size `0x22`; entry item `[0x4f0350,0x4f0351)`, size 1, code; name `LanguageMan__GetLocalizedString`; type `const wchar_t *__thiscall(LanguageMan *this, int stringId)`; address regular absent; address repeatable absent; function regular `Source LanguageMan::GetLocalizedString(int stringId). Returns the stored wide string for an in-range id or the static Invalid String ID fallback.`; function repeatable absent. | Every bound/item/name/type field remains literal; address regular absent; address repeatable absent; function regular equals the literal prestate; function repeatable absent. |
| P43P-01g | Dependency `0x498ca0`: function `[0x498ca0,0x498ce1)`, size `0x41`; entry item `[0x498ca0,0x498ca1)`, size 1, code; name `TextEditControlPane_SetText`; type `void __thiscall(TextEditControlPane *this, const wchar_t *text)`; address regular absent; address repeatable absent; function regular `Null-preserving SetText: selects current text then inserts the replacement in mode zero.`; function repeatable absent. | Every bound/item/name/type field remains literal; address regular absent; address repeatable absent; function regular equals the literal prestate; function repeatable absent. |
| P43P-01h | Compiler dependency `0x5c772f`: function `[0x5c772f,0x5c7740)`, size `0x11`; entry item `[0x5c772f,0x5c7735)`, size 6, code; name `@__security_check_cookie@4`; type `void __fastcall(uintptr_t StackCookie)`; address regular absent; address repeatable absent; function regular absent; function repeatable absent. | Every bound/item/name/type field remains literal; address regular absent; address repeatable absent; function regular absent; function repeatable absent. |
| P43P-01i | UDT `NewUserDialogPane2`, size `0x280`, exactly seven members: `base@+0x0`, width `0x26c`, type `DialogPane`; `m_selectedNation@+0x26c`, width 4, type `int`; `m_selectedTotem@+0x270`, width 4, type `int`; `m_selectedShapeSlot@+0x274`, width 4, type `int`; `m_waitingForCharacterReply@+0x278`, width 1, type `bool`; `alignment279@+0x279`, width 3, type `unsigned __int8[3]`; `m_nexonclubAccountName@+0x27c`, width 4, type `SimpleUString`. | UDT name/size/member count and every member name, offset, width, and type remain literal matches; no member is added, removed, renamed, moved, or retyped. |
| P43P-01j | Target nonargument frame rows: `var_14@+0xc/4/PrettyButtonControlPane *`, `var_10@+0x10/4/_DWORD`, `var_C@+0x14/4/_DWORD`, `var_8@+0x18/4/_DWORD`, `var_4@+0x1c/4/_DWORD`, `__saved_registers@+0x20/4`, and `__return_address@+0x24/4`. | All seven nonargument rows retain literal names, offsets, widths, and types; no local declaration/rename, dependency mutation, comment spill, decompilation/export, analysis-boundary change, or source-byte patch. |

Bounded live `callees` returned only `0x54b700`, `0x4f0350`, `0x498ca0`, and `0x5c772f` with `more:false`. Protection is therefore limited to those four literal address dependencies; inferred source API `GetChild<T>` is not falsely asserted as a separate resolved IDA callee.

Dated supervisor evidence records runtime attestation schema `1`, `ok:true`, no errors, and exact action readbacks. The subsequent bounded continuity checkpoint matched P43P-01a and P43P-01d through P43P-01j and established the corrected current P43P-01b/P43P-01c unnamed-data-item prestates/readbacks. The superseded no-item observation receives no current evidentiary or protection credit. Operational lifecycle mechanics are supervisor-governed outside this report.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes; exact behavior and source APIs are closed.
- Target CPP block disposition: replace the current block exactly with:

```cpp
void NewUserDialogPane2::SelectTotem(short totem)
{
    PrettyButtonControlPane *totemButtons[4];

    totemButtons[0] = GetChild<PrettyButtonControlPane>(14);
    totemButtons[1] = GetChild<PrettyButtonControlPane>(15);
    totemButtons[2] = GetChild<PrettyButtonControlPane>(16);
    totemButtons[3] = GetChild<PrettyButtonControlPane>(17);

    totemButtons[m_selectedTotem]->SetSelected(false);
    totemButtons[totem]->SetSelected(true);
    m_selectedTotem = totem;

    GetChild<TextEditControlPane>(19)->SetText(
        g_pLanguageMan->GetLocalizedString(totem + 212));
}
```

- Target H block disposition: remain empty because [UID:00009E] owns the class declaration.
- Owning class H formal replacement is exactly:

```cpp
void SelectTotem(short totem);
```

- Owning constructor [UID:00043K] formal CPP replacement at `by-memory/0x0052a540-0x0052b047.NewUserDialogPane2Constructor.md` is exactly:

```cpp
NewUserDialogPane2::NewUserDialogPane2()
    : DialogPane(L"NE", -1, true),
      Singleton<NewUserDialogPane2>(),
      m_selectedNation(0),
      m_selectedTotem(0),
      m_selectedShapeSlot(0),
      m_waitingForCharacterReply(false)
{
    m_nexonclubAccountName.clear();

    srand((unsigned)_time64(0));

    LoadDialogBackground(L"DLGNEW02.EPD");
    CreateAccountEditControls();
    CreateShapeSelectControls(L"DIREC.EPD");
    CreateNationButtons(L"NNATION.EPD");
    CreateTotemButtons(L"NNATION.EPD", L"NPAL3.PAL");
    CreateCreateUserCommandButtons();

    m_selectedShapeSlot = rand() % 4;
    m_selectedNation = rand() % 2;
    m_selectedTotem = rand() % 4;

    if ((rand() & 1) != 0) {
        SelectFemaleMode();
    } else {
        SelectMaleMode();
    }

    SelectShapeSlot(m_selectedShapeSlot);
    SelectNation(m_selectedNation);
    SelectTotem(rand() % 4);
}
```

- The UID00043K payload retains every current formal constructor line except the final selector argument. The replacement is required because call site `0x52b001` computes and passes a fresh `_rand() % 4`; the earlier `m_selectedTotem = rand() % 4` value remains the old selection that `SelectTotem` clears first.

- Third-party import directive: not applicable; this is first-party NexusTK dialog source.
- Behavior preservation: four exact lookups, old-index clear, new-index select, signed-short store, child 19 update, and ID calculation are in binary order. No new guard, loop, helper, null behavior, or packet action is introduced.
- Historical source shape: explicit fixed local array and straight-line assignments match old MSVC stack layout/security-cookie generation and neighboring recovered C++03 style better than modern containers, lambdas, `auto`, range loops, or raw vtable syntax.
- Names/types: `totem`, `totemButtons`, `m_selectedTotem`, `GetChild`, `SetSelected`, `SetText`, and `GetLocalizedString` are behavior-specific human source names supported by current project APIs. No IDA/decompiler label appears.
- Style: C++03-compatible declarations, `NULL`-era project APIs by dependency, braces/spacing consistent with recovered class methods; behavior takes priority over stylistic regularity.

## Final Recommendation

- The accepted ordinary callback applied C43P-001 through C43P-038 and C43P-045: target/support documentation, formal CPP/H ownership, score metadata, resource mapping, physical readbacks, and scoped validation are complete at report-level depth.
- Owner/emitter/reconstructable routing remains unchanged; the target now records 96/96 with exact CPP and blank target H, while the class declaration and support prose/resource mapping carry the accepted detail.
- Dependency pages that were already exact remain unchanged and were physically reread; their bodies were not duplicated on the target.
- Dated evidence records successful Gate 2A, I43P-01 through I43P-03 under P43P-01, both manual coverage rows, and generated refresh/readback. The later bounded continuity checkpoint reconfirmed all action/protection facts except that P43P-01b/P43P-01c are literally one unnamed data item each, not no-item spans. These facts remain implementation evidence without asserting a current report lifecycle stage.
- Execution, archive, moved-artifact-audit, and reassignment state is supervisor/validator-owned and authoritative only from the report's actual path plus validator-owned status/history metadata.
- No source item remains no-owner. Both padding spans are current unnamed IDA data items containing compiler-only alignment and remain non-emitting.
- Future work outside scope: adjacent UID00043O/UID00043Q stale formal drafts deserve separate dedicated reports; their issues do not block exact UID00043P source.

## Recommended Target Doc Changes

Accepted/applied callback specification retained as the exact implementation record:

- Target path: `by-memory/0x0052b3a0-0x0052b462.NewUserDialogPane2SelectTotem.md`.
- Metadata: `88/90 -> 96/96`; retain owner `00009E`, reconstructable true, emitter `00009E`, blank optional position, `Nested:0`.
- Item Summary exact replacement: `Exact source-authored NewUserDialogPane2::SelectTotem(short) method: retrieves PrettyButton children 14-17, clears the previously selected index, selects the caller-provided 0-3 index without an internal clamp, stores m_selectedTotem at +0x270, updates TextEdit child 19 from STR.RES id 212+totem, and feeds the create-character packet's direct totem byte.`
- The callback replaced CPP with the Section 22 target block and left target H blank.
- The callback added exact binary identity, ABI/frame, caller/callee, field/order, localization/resource, packet, owner/source-placement, range/padding, score, and IDA-status sections at report-level depth. This report repair corrects the active IDA padding readback to one unnamed data item per exact span without changing source ownership or emission.
- The callback preserved old correct field/domain/owner facts and historicalized the clamp/helper/loop/store-first/GetString draft explicitly rather than silently deleting it.

## Recommended Support Doc Changes

| Support path | Exact facts incorporated or verified | Metadata/CPP/H disposition |
| --- | --- | --- |
| `by-class/NewUserDialogPane2.md` UID00009E | Exact 194-byte selector, signed-short declaration, controls 14-17, clear-old/select-new/store/update order, no internal clamp, child 19, IDs 212-215, packet relation, stale-helper rejection. | Preserved 93/95; replaced only declaration line per Section 22; no duplicate body. |
| `by-file/NewUserDialogPane2.md` UID0000LW | Expanded selector row and source notes with exact target contract and API names. | Preserved 93/95 and source route; no formal body on file page. |
| `by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md` UID0002QR | Expanded UID00043P inventory/naming lines; kept parent non-emitting. | Preserved 91/94, ignored/non-emitting split-index state, blank C++. |
| `by-memory/0x0052a540-0x0052b047.NewUserDialogPane2Constructor.md` UID00043K | Recorded direct call `0x52b001` and fresh random value; replaced the complete formal CPP block with the literal payload below so only final `SelectTotem(m_selectedTotem);` became `SelectTotem(rand() % 4);`. | Preserved scores/owner/H disposition; applied the exact full `RECONSTRUCTION_CPP CODE` payload below. |
| `by-memory/0x0052b760-0x0052b88c.NewUserDialogPane2OnControlCommand.md` UID00043V | Cases 14-17 already call selector with 0-3. | No content/metadata change unless callback reread finds drift. |
| `by-memory/0x0052bdd0-0x0052bfc2.NewUserDialogPane2SendCreateCharacterRequest.md` UID000443 | Direct totem-byte serialization already exact. | No change. |
| `by-class/DialogPane.md` UID00003T | `GetChild<T>` already exact. | No change. |
| `by-memory/0x0054b700-0x0054b719.PrettyButtonControlPaneStateByteVirtualForwarder.md` UID0004E5 | `SetSelected(bool)` already exact. | No change. |
| `by-memory/0x00498ca0-0x00498ce1.TextEditControlPaneSetText.md` UID0004K9 | `SetText(const wchar_t *)` already exact. | No change. |
| `by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md` UID00040P | Canonical lookup spelling already exact. | No change. |
| `by-resource/str-res-localized-strings.md` UID0001RP | Added IDs 212-215 decoded descriptions and UID00043P consumer/runtime-lookup rule. | Preserved 90/94 and owner 0000KK. |

UID00043K exact formal CPP replacement payload, mirrored literally from Section 22:

```cpp
NewUserDialogPane2::NewUserDialogPane2()
    : DialogPane(L"NE", -1, true),
      Singleton<NewUserDialogPane2>(),
      m_selectedNation(0),
      m_selectedTotem(0),
      m_selectedShapeSlot(0),
      m_waitingForCharacterReply(false)
{
    m_nexonclubAccountName.clear();

    srand((unsigned)_time64(0));

    LoadDialogBackground(L"DLGNEW02.EPD");
    CreateAccountEditControls();
    CreateShapeSelectControls(L"DIREC.EPD");
    CreateNationButtons(L"NNATION.EPD");
    CreateTotemButtons(L"NNATION.EPD", L"NPAL3.PAL");
    CreateCreateUserCommandButtons();

    m_selectedShapeSlot = rand() % 4;
    m_selectedNation = rand() % 2;
    m_selectedTotem = rand() % 4;

    if ((rand() & 1) != 0) {
        SelectFemaleMode();
    } else {
        SelectMaleMode();
    }

    SelectShapeSlot(m_selectedShapeSlot);
    SelectNation(m_selectedNation);
    SelectTotem(rand() % 4);
}
```

## Score And Metadata Recommendation

- Pre-callback target: `88/90`, owner/emitter `00009E`, reconstructable true, nonempty stale CPP, blank H.
- Callback-applied target: `96/96`, same owner/emitter/reconstructable/position/Nested state, exact CPP, blank target H.
- Completion rises because exact body/hash/bounds, ABI, frame, operation order, APIs, callers, resources, packet relationship, source placement, formal code, support plan, manual row, and IDA handoff are all closed.
- Confidence rises because live canonical evidence and package/resource meaning converge. It is not 100 because retail private symbols, original local spelling, and exact historical formatting are absent.
- Reason not lower: all practical blockers were researched directly rather than deferred; no unresolved behavior, range, ownership, source API, or formal-code issue remains.
- Metadata unchanged: `CANONICAL_OWNER:00009E`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00009E`, blank optional position, `Nested:0`.

Score-improvement attempts:

| Former blocker | Research performed | Result |
| --- | --- | --- |
| Clamp uncertainty | Complete CFG/disassembly/bytes and caller audit | Resolved: no clamp; callers supply 0-3. |
| Helper/API uncertainty | Live callee resolution and project declaration search | Resolved to GetChild/SetSelected/SetText/GetLocalizedString. |
| Parameter width/sign | Current type, frame, movzx/movsx, sibling ABI | Resolved to signed short. |
| Description control | Exact child 19 lookup and typed callee | Resolved to TextEditControlPane. |
| Resource semantics | Direct current STR.RES parse | Resolved all four IDs/texts. |
| Ownership/placement | UDT, callers, siblings, class/file/generated routes | Resolved to existing owner/file. |
| Formal source | Exact operation/frame/source-style reconstruction | Complete CPP and class declaration ready. |

## Open Questions With Attempted Resolution

- Original parameter/local spelling: no retail symbols exist. Binary role, class field vocabulary, existing `SelectTotem` convention, and neighboring C++03 source make `short totem` and `totemButtons` the best human names. This is resolved for implementation; only original lexical proof is unavailable.
- Whether the source used a local array or four named pointers: exact consecutive stack slots, literal initialization, indexed old/new access, and cookie strongly favor one four-element array. Four independent named pointers would not naturally support both indexed accesses without a second array/alias. Resolved to array.
- Whether localization constants had enum names: no enum/symbol survives. Source uses numeric `212` exactly, matching current project practice and avoiding a fabricated constant name.
- Whether child 19 had a derived static type: exact direct callee contract requires at least TextEditControlPane; constructor/support provides no stronger source subtype. Use the narrow established base type.
- Padding item classification: a fresh bounded continuity checkpoint found one unnamed data item over each complete CC span. The older no-code/data/function-item observation is disproven dated history; exact bytes/hashes, zero xrefs, no-source classification, and protected boundaries remain unchanged. Resolved to the literal current data-item readback.
- No question remains that blocks score, CPP/H, owner/emitter, source placement, or Gate 1.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The report-only manual by-memory coverage snapshot had no UID00043P row. Supervisor command `000000023073` inserted the following exact row, exit `0` / `ok:1`, producing dated post-command SHA256 `D563B2D2DF4833B322D448CCC65BBE3421FE687E2B37D865A435AEAE1112F215`. Current read-only `by-memory/-coverage-report.md` SHA256 is `44C693D1EDF4824D8207D5444B478A9C4A1AA6835C3D69E6F859E999D1FCE681`, and the exact UID00043P row remains present once:

`            - [UID:00043P][0x0052b3a0-0x0052b462.NewUserDialogPane2SelectTotem](by-memory/0x0052b3a0-0x0052b462.NewUserDialogPane2SelectTotem.md) 0x0052b3a0-0x0052b462 | class method | NewUserDialogPane2::SelectTotem : reconstructable : 96% : very-strong : Exact 194-byte signed-short totem selector with SHA256 42B16816F675604474E03F0A6B526202023B24EA9FA2605F01630798A8EAD406, constructor and control-id 14-17 callers, inherited GetChild<PrettyButtonControlPane> lookup for four controls, clear-old/select-new/store/update order without an internal clamp, m_selectedTotem +0x270, TextEdit child 19 update from STR.RES ids 212-215, direct create-character packet relationship, exact padding/compiler-cookie exclusion, and formal human C++ source.`

The report-only manual by-resource snapshot contained a UID0001RP row that omitted the newly proven totem mapping. Supervisor command `000000023074` replaced it with the following exact row, exit `0` / `ok:1`; current `by-resource/-coverage-report.md` SHA256 is `629335DCF598ED77C08CF0B1557E871AC2F2D4163A736D2DE2BBFE38F2B03A7D`:

`- [UID:0001RP][str-res-localized-strings](by-resource/str-res-localized-strings.md) : reconstructable : 90% : very strong : DAT-backed STR.RES parser/resource contract with current package provenance and confirmed high-value ids, including zero-based ids 212-215 for the Ju Jak, Baekho, Hyun Moo, and Chung Ryong descriptions consumed by NewUserDialogPane2::SelectTotem and id 227 text Please input nexon.com ID and password. consumed by NewUserDialogPane2's Nexonclub registration gate and the three create-user variant helpers; callers preserve LanguageMan lookup ids rather than hard-coded English.`

No by-class or by-file manual row required replacement: their broad descriptions remained true after the detail repair. The B agent did not edit manual coverage; the supervisor applied the two exact rows after ordinary and IDA verification. Auto-generated tracker/coverage text remains validator-owned; command `000000023075` is dated refresh evidence only, never a permanent current authority.

## Follow-Up Actions

- B004 ordinary callback scope C43P-001 through C43P-038 and C43P-045 is implemented, physically reread, hashed, and scoped-validated under commands `000000023055` through `000000023059` and `000000023063`; all ordinary leases were released.
- Dated evidence records that Gate 2A reconfirmed all twelve ordinary destination hashes, Gate 2B completed I43P-01 through I43P-03 under P43P-01, commands `000000023073` and `000000023074` applied the manual rows, and command `000000023075` completed one generated CPP/H and tracker refresh/readback. A later read-only continuity checkpoint itemized P43P-01a through P43P-01j and corrected the two padding item classifications without mutation.
- No B004 implementation follow-up remains. Execution, archive, moved-artifact-audit, and reassignment state is not asserted here; the actual report path and validator-owned status/history metadata are authoritative.
- Generated/tracker identities recorded here are dated observations. Each gate dynamically rereads exact physical files and header metadata; no command ID, including `000000023075` or `000000023099`, is permanent current authority.
- No A-agent work is required.
- Separate future reports may repair UID00043O and UID00043Q; B004 must not expand this callback into those targets without assignment.

## Confidence

- Recommendation confidence: `96/100`.
- Score confidence: `96/100`.
- Binary behavior/range/call confidence: `99/100`.
- Source shape/API confidence: `96/100`.
- Original lexical/formatting confidence: `84/100`, intentionally not allowed to leak IDA names into final source.
- Remaining uncertainty is nonbehavioral and does not block exact runtime reconstruction.

## Validator Results

- Callback validation receipt set V43P-01 used scoped file mode with `--apply --queue-timeout 240 --no-generated-refresh`; every command exited `0`, reported `ok:1`, scanned exactly one file, and skipped generated refresh.

| Command | Timestamp | Exact destination | Resulting SHA256 | Result |
| --- | --- | --- | --- | --- |
| `000000023055` | `2026-08-13T04:21:19-04:00` | `by-memory/0x0052b3a0-0x0052b462.NewUserDialogPane2SelectTotem.md` | `1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF` | exit `0`; `ok:1`; six canonical UID links normalized; generated skipped |
| `000000023110` | `2026-08-13T08:30:41-04:00` | `by-memory/0x0052b3a0-0x0052b462.NewUserDialogPane2SelectTotem.md` | `86664B8C47F294A893C4463B82BDA992C66B0EDE23CAEF127A8957506D860585` | exit `0`; `ok:1`; one scanned file; `projected_stats_update:1`; `stats_incremental_noop:1`; generated skipped by `--no-generated-refresh` |
| `000000023056` | `2026-08-13T04:22:08-04:00` | `by-class/NewUserDialogPane2.md` | `AF9082E2ACA681AFC675E254217AA0508B597656CBDA47D99913371E23A270D8` | exit `0`; `ok:1`; generated skipped |
| `000000023057` | `2026-08-13T04:22:45-04:00` | `by-file/NewUserDialogPane2.md` | `9D52C68736B07916AF5C81424F1D567BA23F99A5074BA301454869530AB91472` | exit `0`; `ok:1`; generated skipped |
| `000000023058` | `2026-08-13T04:23:26-04:00` | `by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md` | `2452285618EE2583A1F3569BB63F48EF33A74DC1A8043AFCCC116186AF244453` | exit `0`; `ok:1`; generated skipped |
| `000000023059` | `2026-08-13T04:23:58-04:00` | `by-memory/0x0052a540-0x0052b047.NewUserDialogPane2Constructor.md` | `1FD3E834A3071B8C0697D1FC518AA63E12B67BAF128E47475401CF4A995AD893` | exit `0`; `ok:1`; generated skipped |
| `000000023063` | `2026-08-13T04:26:59-04:00` | `by-resource/str-res-localized-strings.md` | `265E6B6C1764614887F6137E0B764CEAE47A44EAA6681BD5D7BC9612F9CDDBBF` | exit `0`; `ok:1`; reference-index add and UID0001RP stats-row update; generated skipped |

- Callback physical reread also retained the already-present support identities: UID00043V `97CAEB14516765A928D255FAF9808DA57B22005362AB437D711CD6BC6F81CDD7`; UID000443 `7D1C20FDDDE153146E204EDA306F42717333398A6BA171ABBF7DFFD8EDD8C5B8`; UID00003T `86BF78FF08827147CBB1FD71849670B21E282DAB54E13FFABF25273265C3D64C`; UID0004E5 `B5B7428B67A254050EDC426DD694B5C8424E883E3E10AB18659E394F5A3DC127`; UID0004K9 `7BA5479E5F2317648B4F409B4CA046591D47BC90BCBE6FC050275805E4E824AB`; UID00040P `E049B5819BAC227EBF50EE25A4BCFE6BCF059968C5A7E2294F9871738D4A0FCF`. None changed, so no validator was run merely to churn identity.
- Independent Gate 2A continuity found the target prose omission while the other eleven ordinary destination identities retained their callback evidence. Repair command `000000023110` validated and physically rebound the corrected current target identity above.
- Dated bounded IDA continuity evidence reconfirmed I43P-01 through I43P-03 and P43P-01a/P43P-01d through P43P-01j. It established P43P-01b and P43P-01c as complete unnamed data items with exact bounds/bytes/hashes, blank name/type, absent address comments, and zero xrefs; the previous no-item classification is superseded history.
- Supervisor closure receipts: command `000000023073` applied the exact UID00043P by-memory manual row, exit `0` / `ok:1`, producing dated post-command SHA256 `D563B2D2DF4833B322D448CCC65BBE3421FE687E2B37D865A435AEAE1112F215`; current read-only by-memory coverage SHA256 is `44C693D1EDF4824D8207D5444B478A9C4A1AA6835C3D69E6F859E999D1FCE681` and the row remains present once. Command `000000023074` applied the exact UID0001RP by-resource replacement row, exit `0` / `ok:1`, producing SHA256 `629335DCF598ED77C08CF0B1557E871AC2F2D4163A736D2DE2BBFE38F2B03A7D`.
- Historical command `000000023075` validated the target with `--wait-generated`, exit `0` / `ok:1`, and produced a dated generation snapshot: `auto-generated/NexusTK/login/NewUserDialogPane2.cpp` SHA256 `BB36BADF5CF3A70012FDB3D413C1D36EF35034A271D759390AB8B0CA15DAEC01` and `NewUserDialogPane2.h` SHA256 `7C8F32DC38B48EA6F188ED0FB9A28E4AF3A3606A4A1854ED6EEA80C93CCD77FD`. Physical readback at that time found the exact constructor call, exactly one UID00043P body, the exact short declaration, and no target empty marker.
- The dated tracker snapshot associated with command `000000023075` has SHA256 `D162CD421E59E000157E5681514EF75923EC636E9E8031096C339142E3D9F93C` and listed UID00043P as covered/reconstructable at `96/96`.
- Command `000000023008` and generated CPP/H hashes `4AF8E24DD898CDDA2BDAA805EFF392FEAC94F7CD37EE8A86A9A346DDDAF432C5` / `658FBB6878A63E46E07D0C5B5EEF25BD5C3C7A6D0839CF478BBE4BAA8A33B99B` are superseded historical pre-callback evidence only; they are not current authority.
- Dated Gate 1 generated snapshot from physical reread: `auto-generated/NexusTK/login/NewUserDialogPane2.cpp` SHA256 `0D12F59803BE58927D36063C604363317A3AAF2115F5E4B0FC82AAA638872888`, 14,817 bytes, and `auto-generated/NexusTK/login/NewUserDialogPane2.h` SHA256 `7DF09EC7FD5C2ECBC408FF061F98350330F18340FF91A866030EF703F53D0980`, 1,855 bytes; both headers record command `000000023042`, timestamp `2026-08-13T01:06:08-04:00`, source `foreground-generated-refresh`.
- Dated tracker snapshot from physical reread: `auto-generated/-ag-research-tracker.md` SHA256 `6794C5420667408D376DD55098F05BD3649191D62F18D4C567F2D4613953DFFC`, 1,721,219 bytes; its header records command `000000023045`, timestamp `2026-08-13T01:12:15-04:00`, source `foreground-generated-refresh`.
- Dated post-callback generated read-only snapshot: `auto-generated/NexusTK/login/NewUserDialogPane2.cpp` SHA256 `F501B137422DA63C10A816F58170066B312A703C376D50FF81EFB20B735037DC`, 14,817 bytes, and `auto-generated/NexusTK/login/NewUserDialogPane2.h` SHA256 `B8E792EA04C9744ADA86499F6B831B59D9263B852228D0502F4434EBCF929C19`, 1,855 bytes; both headers record command `000000023051`, timestamp `2026-08-13T02:45:23-04:00`, source `foreground-generated-refresh`. This predates the six callback validators, which explicitly skipped generation, so it is read-only history rather than callback-closure proof.
- All generated and tracker identities are dated snapshots only. Every later gate must reread the exact physical paths and bind its decision to newly observed hashes and header metadata; no report snapshot is permanent current authority.
- Commands `000000023076` and `000000023077` are dated validator-owned lifecycle history retained by the immutable footer; current lifecycle state is derived only from the report's actual path and validator-owned status/history metadata.
- Unresolved validator warnings/errors: none for V43P-01, repair command `000000023110`, or supervisor commands `000000023073` through `000000023075`.

## Changed Files

- Created: this report artifact was created during the report-only phase; its actual current path and validator-owned lifecycle history remain authoritative.
- Modified during the accepted ordinary callback: `by-memory/0x0052b3a0-0x0052b462.NewUserDialogPane2SelectTotem.md`, `by-class/NewUserDialogPane2.md`, `by-file/NewUserDialogPane2.md`, `by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md`, `by-memory/0x0052a540-0x0052b047.NewUserDialogPane2Constructor.md`, `by-resource/str-res-localized-strings.md`, and this same report.
- Renamed/moved lifecycle history: command `000000023076` moved the report to `executed-b-agent-research/B004/00043P-NewUserDialogPane2SelectTotem-source-quality.md`; command `000000023077` returned it to the active research path after the moved-artifact audit found stale prose. No ordinary destination was renamed.
- Pre-callback ordinary identities were target `67B602AED1C4ED5038FCC56917D7B89821814D108670CB374129141860881528`, class `9AEEB586A85310248C67D545DB1EA6D2CE42A93CFF22D5F920645E5379C9E7A9`, file `B7EDAD5ED486D2A50D67196735D3E7A6F1A88452C26D590FCB17A797BBC83BCA`, aggregate `2404675919949BA2580DAE41E18DDB48AAC4E0CA31124399E69C068CEA1E3266`, constructor `3DB23749A36F499FEAC2D4A0A98A39A2DACE416982AF16F2D9A25DFBED0C0732`, and resource `CFD6923D80412E486FE734DBDC1769D1A1AEF95FBC29E5D82CF1A9593C37AEC5`.
- Dated post-callback validated identities were target `1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF`, class `AF9082E2ACA681AFC675E254217AA0508B597656CBDA47D99913371E23A270D8`, file `9D52C68736B07916AF5C81424F1D567BA23F99A5074BA301454869530AB91472`, aggregate `2452285618EE2583A1F3569BB63F48EF33A74DC1A8043AFCCC116186AF244453`, constructor `1FD3E834A3071B8C0697D1FC518AA63E12B67BAF128E47475401CF4A995AD893`, and resource `265E6B6C1764614887F6137E0B764CEAE47A44EAA6681BD5D7BC9612F9CDDBBF`. Gate 2A repair command `000000023110` establishes the current target identity as `86664B8C47F294A893C4463B82BDA992C66B0EDE23CAEF127A8957506D860585`; the other ordinary identities remain as listed.
- Verified unchanged support paths and hashes are recorded in Section 31; no unrelated ordinary file changed.
- Modified by supervisor after Gate 2A: `by-memory/-coverage-report.md` under command `000000023073` and `by-resource/-coverage-report.md` under command `000000023074`. The by-memory dated post-command hash and current read-only SHA256 `44C693D1EDF4824D8207D5444B478A9C4A1AA6835C3D69E6F859E999D1FCE681`, plus the unchanged by-resource identity, are recorded in Sections 28 and 31.
- Dated validator-generated snapshot under command `000000023075`: `auto-generated/NexusTK/login/NewUserDialogPane2.cpp`, `auto-generated/NexusTK/login/NewUserDialogPane2.h`, and `auto-generated/-ag-research-tracker.md`, with exact historical hashes in Section 31. These files were not edited by B004; later gates dynamically reread them.
- External IDA state was modified only by the primary supervisor; Section 21 records declarative actions and stable direct readbacks. B004 did not mutate IDA. The later B004 continuity checkpoint was bounded and read-only and corrected only the report's two padding item classifications.
- Superseded command `000000023008` generated identities `4AF8E24DD898CDDA2BDAA805EFF392FEAC94F7CD37EE8A86A9A346DDDAF432C5` / `658FBB6878A63E46E07D0C5B5EEF25BD5C3C7A6D0839CF478BBE4BAA8A33B99B` are dated history only. The dated Gate 1 physical snapshot observed generated CPP `0D12F59803BE58927D36063C604363317A3AAF2115F5E4B0FC82AAA638872888` and H `7DF09EC7FD5C2ECBC408FF061F98350330F18340FF91A866030EF703F53D0980` under command `000000023042`, plus tracker `6794C5420667408D376DD55098F05BD3649191D62F18D4C567F2D4613953DFFC` under command `000000023045`; later gates must reread all three exact paths dynamically.
- Report lifecycle boundary: execution/archive status is supervisor-owned and authoritative only from the current report path plus validator-owned status/history metadata. The validator-owned footer preserves commands `000000023076` and `000000023077` verbatim; B004 does not execute, move, or archive reports.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor Gate 1 accepted exact report SHA `FDE72CA36081DB5966C1002C33D0442BB5F8DBBE8136270EDC6B5F55AC95B590` before implementation.
- [x] For a by-file target, exhaustive whole-file inventory completed and reconciled against IDA, all related by-* pages, generated output, and matching reports; every function and every other code/data/type/resource/range item has an evidence-backed disposition rather than a sampled-subset or generic future-work entry: not applicable, target is one by-memory method.
- [x] For a by-file target, every file-owned inventory item has explicit behavior/role, ownership/emitter/source placement, CPP/H or no-code, metadata/score, destination doc, Claim And Incorporation Ledger, and Implementation Tracking Checklist coverage as applicable; excluded candidates have evidence-backed reasons: not applicable.
- [x] For a by-file target, current generated `.cpp`/`.h` audited against the inventory and every missing/incomplete function, code path, data definition, declaration/type/include/forward declaration, child route/order defect, stub/placeholder/empty marker, and required-but-missing header has an exact formal CPP/H repair or evidence-backed no-code/no-header disposition: not applicable as a by-file gate; target-generated impact is documented.
- [x] Target/support callback docs completed: target, UID00009E, UID0000LW, UID0002QR, UID00043K, UID0001RP.
- [x] Every declared additional UID has target-specific evidence, recommendation, ledger rows, destination docs, and planned validation: none declared.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger updated with destination, callback evidence, and verification state for every accepted claim.
- [x] Metadata/score change applied: target 88/90 to 96/96 only.
- [x] Score-limiting blockers researched to resolution and carried into the callback implementation.
- [x] Owner/emitter/reconstructable state verified unchanged; exact existing route retained.
- [x] No split or new child was required; the supervisor IDA rename/type/comment closure is recorded separately below.
- [x] Ordinary source placement, range/split/padding, and reclassification dispositions were applied or verified; supervisor IDA rename/type/comment work was independently applied and persisted.
- [x] Dated independent supervisor evidence records the exact I43P-01 through I43P-03 actions under P43P-01 and every stable target/protection readback.
- [x] Exact target CPP, blank target H proof, class H declaration, and constructor CPP replacement applied through formal channels.
- [x] Third-party import directive confirmed not applicable: first-party source, with no third-party import payload.
- [x] Exact target/support facts incorporated at report-level detail.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Wave2/Wave3 artifacts were not used and remain rejected as stale absent override.
- [x] Open questions closed or retained only as evidence-backed nonbehavioral uncertainty.
- [x] Scoped validators completed as receipt set V43P-01 in Section 31.
- [x] Supervisor commands `000000023073` and `000000023074` are retained manual-coverage receipts; command `000000023075` is dated generated/tracker closure evidence, while each gate dynamically rereads current authority.

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C43P-001 | 00043P | Exact source body is `[0x0052b3a0,0x0052b462)`, 194 bytes, SHA256 `42B16816F675604474E03F0A6B526202023B24EA9FA2605F01630798A8EAD406`, 65 instructions, one basic block. | 99 | Actor B004; live lookup/disasm/bytes/profile.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | `by-memory/0x0052b3a0-0x0052b462.NewUserDialogPane2SelectTotem.md` / Exact Binary Identity | incorporate | applied |
| [x] | C43P-002 | 00043P | Predecessor ends at `0x52b395`; `[0x52b395,0x52b3a0)` is an 11-byte no-source alignment span with SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`. `[0x52b462,0x52b470)` is a 14-byte no-source alignment span with SHA256 `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`; successor starts cleanly at `0x52b470`. | 99 | Actor B004; inspect_items/get_bytes/xrefs_to; repair command `000000023110` at `2026-08-13T08:30:41-04:00`, exit `0` / `ok:1`, generated skipped; current SHA256 `86664B8C47F294A893C4463B82BDA992C66B0EDE23CAEF127A8957506D860585`; physical reread confirms both exact spans/hashes and zero-xref no-source disposition. | target / Range And Padding | incorporate | applied |
| [x] | C43P-003 | 00043P | Source ABI is `void NewUserDialogPane2::SelectTotem(short totem)`; current stack argument is size 2 and signed-extended. | 98 | Actor B004; type/frame/disasm and sibling ABI.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / ABI And Source Signature | incorporate | applied |
| [x] | C43P-004 | 00043P | Pre-Gate-2B IDA state was `sub_52B3A0`, `void __thiscall(int this, __int16)`, exact eight-row frame, and four absent comment channels; Section 21 records the dated stable poststate. | 99 | Actor B004; inspect_items/stack_frame/get_comments established prestate; dated independent supervisor evidence established the exact poststate; repair command `000000023110` at `2026-08-13T08:30:41-04:00`, exit `0` / `ok:1`, generated skipped; current SHA256 `86664B8C47F294A893C4463B82BDA992C66B0EDE23CAEF127A8957506D860585`; physical reread contains the exact current name/type/frame/comment and historical prechange paragraph. | target / IDA Prechange And Persisted State | incorporate | applied |
| [x] | C43P-005 | 00043P | The method performs four inherited child lookups for selectors 14, 15, 16, and 17 and dereferences each returned slot as a PrettyButton control. | 99 | Actor B004; instructions `0x52b3b9-0x52b3fc`.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / Exact Behavior | incorporate | applied |
| [x] | C43P-006 | 00043P | Human source uses one four-element `PrettyButtonControlPane *totemButtons[4]` local; it accounts for the four consecutive pointer slots and cookie without decompiler locals. | 94 | Actor B004; frame/straight-line lookup/source style.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / Source Shape | incorporate | applied |
| [x] | C43P-007 | 00043P | The control indexed by current `m_selectedTotem` is cleared first with `SetSelected(false)`. | 99 | Actor B004; `0x52b3fc-0x52b412`.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / Exact Behavior | incorporate | applied |
| [x] | C43P-008 | 00043P | The control indexed by signed-short argument is selected next with `SetSelected(true)`. | 99 | Actor B004; `0x52b412-0x52b420`.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / Exact Behavior | incorporate | applied |
| [x] | C43P-009 | 00043P | Only after both state calls, the sign-extended argument is stored to `m_selectedTotem` at `+0x270`. | 99 | Actor B004; `0x52b420-0x52b42c`, UDT.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / Exact Behavior | incorporate | applied |
| [x] | C43P-010 | 00043P | The method has no clamp, guard, null check, loop, or conditional branch; caller domain supplies 0-3. | 99 | Actor B004; complete one-block disassembly and caller literals.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / Negative Evidence | reject-stale | applied |
| [x] | C43P-011 | 00043P | Child selector 19 resolves to the TextEdit control receiving `SetText`. | 98 | Actor B004; `0x52b420-0x52b44f`, callee type.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / Description Update | incorporate | applied |
| [x] | C43P-012 | 00043P | Description text is `g_pLanguageMan->GetLocalizedString(totem + 212)`, producing IDs 212-215. | 99 | Actor B004; global/callee/LEA evidence.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / Localization | incorporate | applied |
| [x] | C43P-013 | 0001RP | Current STR.RES IDs 212-215 decode to Ju Jak, Baekho, Hyun Moo, and Chung Ryong descriptions; source keeps lookup IDs. | 97 | Actor B004; read-only package parse and parser contract.; callback command 000000023063; SHA256 265E6B6C1764614887F6137E0B764CEAE47A44EAA6681BD5D7BC9612F9CDDBBF | `by-resource/str-res-localized-strings.md` / Confirmed High-Value String IDs | incorporate | applied |
| [x] | C43P-014 | 00043K | Constructor makes one direct call at `0x52b001` with a fresh normalized `_rand() % 4` value. | 99 | Actor B004; bounded instruction query `0x52afed-0x52b001`.; callback command 000000023059; SHA256 1FD3E834A3071B8C0697D1FC518AA63E12B67BAF128E47475401CF4A995AD893 | `by-memory/0x0052a540-0x0052b047.NewUserDialogPane2Constructor.md` / initialization and calls | incorporate | applied |
| [x] | C43P-015 | 00043V | OnControlCommand cases 14-17 call the method with literal 0,1,2,3 and return. | 99 | Actor B004; live disasm at four call sites.; physical callback reread; SHA256 97CAEB14516765A928D255FAF9808DA57B22005362AB437D711CD6BC6F81CDD7 | `by-memory/0x0052b760-0x0052b88c.NewUserDialogPane2OnControlCommand.md` / command cases | already-present | already-present |
| [x] | C43P-016 | 00043P | Five direct code xrefs exist, contained by exactly two caller functions; there are no data/vtable xrefs. | 99 | Actor B004; xrefs_to/profile.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / Caller Inventory | incorporate | applied |
| [x] | C43P-017 | 00043P | Semantic callees are PrettyButton `SetSelected`, LanguageMan `GetLocalizedString`, TextEdit `SetText`; the cookie check is compiler lowering. | 99 | Actor B004; callees/disasm/profiles.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / Callee Inventory | incorporate | applied |
| [x] | C43P-018 | 000443 | SendCreateCharacterRequest serializes `m_selectedTotem` directly after one-based nation and before account text. | 98 | Actor B004; current exact packet child and field route.; physical callback reread; SHA256 7D1C20FDDDE153146E204EDA306F42717333398A6BA171ABBF7DFFD8EDD8C5B8 | `by-memory/0x0052bdd0-0x0052bfc2.NewUserDialogPane2SendCreateCharacterRequest.md` / Evidence And Behavior | already-present | already-present |
| [x] | C43P-019 | 00009E | NewUserDialogPane2 is the sole direct class owner/emitter; class UDT places `m_selectedTotem` at `+0x270`. | 99 | Actor B004; receiver/UDT/callers/class route.; callback command 000000023056; SHA256 AF9082E2ACA681AFC675E254217AA0508B597656CBDA47D99913371E23A270D8 | `by-class/NewUserDialogPane2.md` / method and layout evidence | incorporate | applied |
| [x] | C43P-020 | 0000LW | Source placement is `NexusTK/login/NewUserDialogPane2.cpp` with declaration in its generated class H route. | 97 | Actor B004; by-file route and siblings.; callback command 000000023057; SHA256 9D52C68736B07916AF5C81424F1D567BA23F99A5074BA301454869530AB91472 | `by-file/NewUserDialogPane2.md` / Proposed Contents and source placement | incorporate | applied |
| [x] | C43P-021 | 00043P | Metadata becomes 96/96; owner 00009E, reconstructable true, emitter 00009E, blank position, and Nested 0 remain. | 96 | Actor B004; blocker closure and source readiness.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / metadata headers and Score Rationale | incorporate | applied |
| [x] | C43P-022 | 00043P | Item Summary becomes the exact no-metadata behavior summary stated in Section 24. | 97 | Actor B004; generated-summary policy.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / Item Summary | incorporate | applied |
| [x] | C43P-023 | 00043P | Target CPP is replaced exactly by the formal body in Section 22. | 97 | Actor B004; full binary/source reconstruction.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / RECONSTRUCTION_CPP CODE | incorporate | applied |
| [x] | C43P-024 | 00043P | Target H remains blank because the class owner emits the declaration. | 99 | Actor B004; source-channel ownership.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / RECONSTRUCTION_H CODE | already-present | already-present |
| [x] | C43P-025 | 00043P | `SetChildButtonChecked`, `SetCreateUserDescriptionText`, and `GetString` are historical stale abstractions, not emitted APIs. | 98 | Actor B004; project API search plus live callees.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / Historical Corrections | historicalize | applied |
| [x] | C43P-026 | 00043P | Clamp, loop, store-first order, and broad helper draft are rejected because they change exact call count/order and out-of-domain behavior. | 99 | Actor B004; complete CFG and bytes.; callback command 000000023055; SHA256 1960A3A7B408054BE5AC2D517AA95A4A8F342856C040367E2D01FA2C192A35FF | target / Historical Corrections and Negative Evidence | reject-stale | applied |
| [x] | C43P-027 | 00009E | Class H declaration changes only `SelectTotem(int)` to `SelectTotem(short)`. | 98 | Actor B004; exact ABI.; callback command 000000023056; SHA256 AF9082E2ACA681AFC675E254217AA0508B597656CBDA47D99913371E23A270D8 | `by-class/NewUserDialogPane2.md` / RECONSTRUCTION_H CODE | incorporate | applied |
| [x] | C43P-028 | 00009E | Class method table gains exact selectors, update order, child 19/localization, no-clamp caller contract, and packet relation. | 97 | Actor B004; target and support evidence.; callback command 000000023056; SHA256 AF9082E2ACA681AFC675E254217AA0508B597656CBDA47D99913371E23A270D8 | class / Exact Totem Selection Contract | incorporate | applied |
| [x] | C43P-029 | 0000LW | File inventory/source notes gain the exact UID00043P behavior and stale-helper correction. | 97 | Actor B004; compilation-unit route.; callback command 000000023057; SHA256 9D52C68736B07916AF5C81424F1D567BA23F99A5074BA301454869530AB91472 | `by-file/NewUserDialogPane2.md` / Proposed Contents and exact selector section | incorporate | applied |
| [x] | C43P-030 | 0002QR | Aggregate UID00043P row and naming/source-shape prose gain full exact behavior and API decisions without emitting duplicate CPP. | 97 | Actor B004; split-index policy.; callback command 000000023058; SHA256 2452285618EE2583A1F3569BB63F48EF33A74DC1A8043AFCCC116186AF244453 | `by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md` / child inventory and naming | incorporate | applied |
| [x] | C43P-031 | 00043K | Exact owning-constructor formal CPP replacement preserves the complete current constructor source and changes only its final selector call from `SelectTotem(m_selectedTotem);` to `SelectTotem(rand() % 4);`; the literal full replacement payload is mirrored in Sections 22 and 25. | 96 | Actor B004; direct call at `0x52b001` passes fresh `_rand() % 4`; current UID00043K formal CPP physical reread.; callback command 000000023059; SHA256 1FD3E834A3071B8C0697D1FC518AA63E12B67BAF128E47475401CF4A995AD893 | `by-memory/0x0052a540-0x0052b047.NewUserDialogPane2Constructor.md` / `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| [x] | C43P-032 | 00043V | Existing command cases 14-17 already express `controlIndex - 14`; preserve unchanged and add no target clamp. | 99 | Actor B004; physical doc and live disasm.; physical callback reread; SHA256 97CAEB14516765A928D255FAF9808DA57B22005362AB437D711CD6BC6F81CDD7 | OnControlCommand / formal CPP and evidence | already-present | already-present |
| [x] | C43P-033 | 000443 | Existing direct totem-byte serialization is correct and remains unchanged. | 99 | Actor B004; physical support doc.; physical callback reread; SHA256 7D1C20FDDDE153146E204EDA306F42717333398A6BA171ABBF7DFFD8EDD8C5B8 | packet child / formal CPP and behavior | already-present | already-present |
| [x] | C43P-034 | 00003T | Existing protected `GetChild<T>(int) const` API is the exact source-facing replacement for inherited `+0x1fc` lookup lowering. | 98 | Actor B004; current DialogPane declaration.; physical callback reread; SHA256 86BF78FF08827147CBB1FD71849670B21E282DAB54E13FFABF25273265C3D64C | `by-class/DialogPane.md` / protected child-access contract | already-present | already-present |
| [x] | C43P-035 | 0004E5 | Existing `PrettyButtonControlPane::SetSelected(bool)` contract exactly owns state byte and invalidation. | 99 | Actor B004; exact child and live callee.; physical callback reread; SHA256 B5B7428B67A254050EDC426DD694B5C8424E883E3E10AB18659E394F5A3DC127 | PrettyButton SetSelected child / Evidence | already-present | already-present |
| [x] | C43P-036 | 0004K9 | Existing `TextEditControlPane::SetText(const wchar_t *)` contract exactly owns description replacement. | 99 | Actor B004; exact child and live callee.; physical callback reread; SHA256 7BA5479E5F2317648B4F409B4CA046591D47BC90BCBE6FC050275805E4E824AB | TextEdit SetText child / Exact Evidence | already-present | already-present |
| [x] | C43P-037 | 00040P | Existing `LanguageMan::GetLocalizedString(int) const` contract and canonical spelling are correct. | 99 | Actor B004; exact child and live callee.; physical callback reread; SHA256 E049B5819BAC227EBF50EE25A4BCFE6BCF059968C5A7E2294F9871738D4A0FCF | LanguageMan lookup child / Status and Behavior | already-present | already-present |
| [x] | C43P-038 | 0001RP | Resource page adds exact IDs 212-215, decoded text, UID00043P consumer, and runtime-lookup policy. | 97 | Actor B004; direct payload extraction and call.; callback command 000000023063; SHA256 265E6B6C1764614887F6137E0B764CEAE47A44EAA6681BD5D7BC9612F9CDDBBF | `by-resource/str-res-localized-strings.md` / Confirmed High-Value String IDs | incorporate | applied |
| [x] | C43P-039 | 00043P | Supervisor IDA action I43P-01 is declarative operation `rename` at `0x0052b3a0` to `NewUserDialogPane2__SelectTotem` with literal `pure:true`. | 98 | Actor supervisor; dated independent evidence records the exact prestate and stable direct readback in Section 21. | Supervisor IDA action I43P-01 | incorporate | applied |
| [x] | C43P-040 | 00043P | Supervisor IDA action I43P-02 has applied the exact receiver/short signature and verified literal normalized frame readback. | 98 | Actor supervisor; persisted readback is `void __thiscall(NewUserDialogPane2 *this, __int16 totem)`, with `totem@+0x28/2` and all seven nonargument rows unchanged. | Supervisor IDA action I43P-02 | incorporate | applied |
| [x] | C43P-041 | 00043P | Supervisor IDA action I43P-03 has added the exact regular function comment while preserving three other comment channels absent. | 96 | Actor supervisor; dated independent evidence records the exact regular function comment and three absent channels. | Supervisor IDA action I43P-03 | incorporate | applied |
| [x] | C43P-042 | 00043P | Supervisor Gate 2B and the later bounded continuity checkpoint preserve body bytes/bounds/frame locals, both exact unnamed padding data items, successor, UDT layout, callees, xrefs, globals, and all protected comments. | 99 | Actor supervisor for persisted Gate 2B state; B004 read-only continuity evidence. Body SHA `42B16816F675604474E03F0A6B526202023B24EA9FA2605F01630798A8EAD406`, pre-pad SHA `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`, post-pad SHA `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`, five xrefs, four callees, successor/dependencies, UDT and comments match; earlier no-item padding classification is dated disproven history only. | Supervisor IDA protection P43P-01 | incorporate | applied |
| [x] | C43P-042A | 00043P | P43P-01a target body remains `[0x52b3a0,0x52b462)`, 194 bytes, 65 instructions, SHA256 `42B16816F675604474E03F0A6B526202023B24EA9FA2605F01630798A8EAD406`, with five exact incoming code xrefs and four exact callees. | 99 | Actor supervisor for persisted protection; B004 bounded read-only continuity checkpoint used lookup_funcs, get_bytes, disasm, xrefs_to, and callees. | Supervisor IDA protection P43P-01a | incorporate | applied |
| [x] | C43P-042B | 00043P | P43P-01b pre-pad is exactly one unnamed data item `[0x52b395,0x52b3a0)`, size 11, blank name/type, `is_data:true`, `is_code:false`, 11 `CC` bytes, SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`, absent address comments, and zero xrefs. | 99 | Actor supervisor for persisted protection; B004 bounded read-only inspect_items/get_bytes/get_comments/xrefs_to continuity readback. Earlier no-item observation is dated disproven history only. | Supervisor IDA protection P43P-01b | incorporate | applied |
| [x] | C43P-042C | 00043P | P43P-01c post-pad is exactly one unnamed data item `[0x52b462,0x52b470)`, size 14, blank name/type, `is_data:true`, `is_code:false`, 14 `CC` bytes, SHA256 `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`, absent address comments, and zero xrefs. | 99 | Actor supervisor for persisted protection; B004 bounded read-only inspect_items/get_bytes/get_comments/xrefs_to continuity readback. Earlier no-item observation is dated disproven history only. | Supervisor IDA protection P43P-01c | incorporate | applied |
| [x] | C43P-042D | 00043P | P43P-01d successor remains `[0x52b470,0x52b52c)`, size `0xbc`, entry `[0x52b470,0x52b471)` code, name `sub_52B470`, type `int __thiscall(int this, __int16)`, with all four comment channels absent. | 99 | Actor supervisor for persisted protection; B004 bounded read-only lookup_funcs/inspect_items/get_comments continuity readback. | Supervisor IDA protection P43P-01d | incorporate | applied |
| [x] | C43P-042E | 00043P | P43P-01e dependency `0x54b700` retains exact bounds/item/name/type and its exact function-regular `SetSelected(bool)` contract; the other three comment channels remain absent. | 99 | Actor supervisor for persisted protection; B004 bounded read-only lookup_funcs/inspect_items/get_comments continuity readback. | Supervisor IDA protection P43P-01e | incorporate | applied |
| [x] | C43P-042F | 00043P | P43P-01f dependency `0x4f0350` retains exact bounds/item/name/type and its exact function-regular `GetLocalizedString(int)` contract; the other three comment channels remain absent. | 99 | Actor supervisor for persisted protection; B004 bounded read-only lookup_funcs/inspect_items/get_comments continuity readback. | Supervisor IDA protection P43P-01f | incorporate | applied |
| [x] | C43P-042G | 00043P | P43P-01g dependency `0x498ca0` retains exact bounds/item/name/type and its exact function-regular null-preserving `SetText` contract; the other three comment channels remain absent. | 99 | Actor supervisor for persisted protection; B004 bounded read-only lookup_funcs/inspect_items/get_comments continuity readback. | Supervisor IDA protection P43P-01g | incorporate | applied |
| [x] | C43P-042H | 00043P | P43P-01h compiler dependency `0x5c772f` retains exact bounds, six-byte entry item, name `@__security_check_cookie@4`, type `void __fastcall(uintptr_t StackCookie)`, and four absent comment channels. | 99 | Actor supervisor for persisted protection; B004 bounded read-only lookup_funcs/inspect_items/get_comments continuity readback. | Supervisor IDA protection P43P-01h | incorporate | applied |
| [x] | C43P-042I | 00043P | P43P-01i UDT `NewUserDialogPane2` remains size `0x280` with exactly seven unchanged members and literal names/offsets/widths/types. | 99 | Actor supervisor for persisted protection; B004 bounded read-only type_inspect continuity readback. | Supervisor IDA protection P43P-01i | incorporate | applied |
| [x] | C43P-042J | 00043P | P43P-01j target frame retains all seven nonargument rows with literal names, offsets, widths, and types; `totem@+0x28/2/__int16` remains the sole argument row. | 99 | Actor supervisor for persisted protection; B004 bounded read-only stack_frame/disasm continuity readback. | Supervisor IDA protection P43P-01j | incorporate | applied |
| [x] | C43P-043 | 00043P | Manual by-memory coverage contains the exact UID00043P row in Section 28. | 97 | Actor supervisor; command `000000023073` exit `0`/`ok:1` inserted the exact row and produced dated post-command SHA `D563B2D2DF4833B322D448CCC65BBE3421FE687E2B37D865A435AEAE1112F215`; current read-only manual coverage SHA `44C693D1EDF4824D8207D5444B478A9C4A1AA6835C3D69E6F859E999D1FCE681`, with the exact UID00043P row present once. | `by-memory/-coverage-report.md` / UID00043P row | incorporate | applied |
| [x] | C43P-044 | 0001RP | Manual by-resource coverage contains the exact resource/consumer replacement wording in Section 28. | 96 | Actor supervisor; command `000000023074` exit `0`/`ok:1` replaced the exact row; current manual coverage SHA `629335DCF598ED77C08CF0B1557E871AC2F2D4163A736D2DE2BBFE38F2B03A7D`. | `by-resource/-coverage-report.md` / UID0001RP row | incorporate | applied |
| [x] | C43P-045 | 00043P | Every changed ordinary destination has scoped file validation with generated refresh disabled and retained receipts. | 99 | Actor B004; V43P-01 commands `000000023055`-`000000023059` and `000000023063` all exit `0`/`ok:1` with generated skipped; target repair command `000000023110` exit `0`/`ok:1` with generated skipped binds current target SHA256 `86664B8C47F294A893C4463B82BDA992C66B0EDE23CAEF127A8957506D860585`; all destinations were physically reread. | Validation receipt set V43P-01 / Section 31 exact paths | incorporate | applied |
| [x] | C43P-046 | 0000LW | A coherent generated CPP/H refresh and physical readback completed after ordinary docs and supervisor manual/IDA work. | 99 | Actor supervisor; dated command `000000023075` exit `0`/`ok:1` produced CPP SHA `BB36BADF5CF3A70012FDB3D413C1D36EF35034A271D759390AB8B0CA15DAEC01` and H SHA `7C8F32DC38B48EA6F188ED0FB9A28E4AF3A3606A4A1854ED6EEA80C93CCD77FD`, with exact body/declaration and no target empty marker; later gates dynamically reread current authority. | Supervisor generated action G43P-01 | incorporate | applied |
Implementation callback pass:
- [x] Dated independent evidence records the supervisor-owned IDA changes and stable direct readbacks; the later B004 read-only continuity checkpoint corrected only P43P-01b/P43P-01c to one unnamed data item each and did not apply or claim any IDA mutation.
- [x] For a by-file target, all accepted whole-file inventory claims were incorporated and verified across the by-file page and every affected support page; no function or other file-owned code/data/type/resource item was silently omitted: not applicable, target is by-memory.
- [x] For a by-file target, every accepted missing/incomplete function/code/data/declaration/header/routing repair was applied through owning formal CPP/H channels and generated output reread: not applicable as a by-file gate; dated command `000000023075` records the separate target generated refresh.
- [x] Report accepted by supervisor for implementation at exact SHA `FDE72CA36081DB5966C1002C33D0442BB5F8DBBE8136270EDC6B5F55AC95B590`.
- [x] All accepted B004-owned target/support details incorporated at report-level depth.
- [x] Primary UID00043P and every support destination were independently reread against the ledger; no additional target UID was declared.
- [x] Claim And Incorporation Ledger updated with exact callback destination identities and verification states.
- [x] Metadata/score/owner/emitter/split/rename/CPP/H changes applied or explicitly preserved with reason; the IDA rename/type/comment changes remain correctly attributed to the supervisor.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed nonbehavioral uncertainty.
- [x] Six scoped validators ran successfully and receipt set V43P-01 is recorded.
- [x] Dated command `000000023075` records generated CPP/H/tracker refresh and readback; commands `000000023073` and `000000023074` record the exact supervisor-owned manual coverage rows; each later gate rereads dynamic current authority.
- [x] No implementation item remains unapplied.
- [x] Report body is lifecycle-neutral: current execution/archive truth is deferred to the current path and validator-owned status/history metadata, and no body/checklist sentence will become false merely because the supervisor executes or invalidates the report.
- [x] Same-report repair self-audit confirms all 33 canonical headings in order, exact 56/56 full-field ledger/checklist parity, all 56 rows checked/current, four formal C++ fences, zero executable automation fences, and one terminal readiness marker.

Current allocation: `56` claims checked/current (`47` applied, `9` already-present); no claim row is unchecked or pending.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000023076","destination_path":"executed-b-agent-research/B004/00043P-NewUserDialogPane2SelectTotem-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/00043P-NewUserDialogPane2SelectTotem-source-quality.md","timestamp":"2026-08-13T06:03:13-04:00","uid":"00043P"} -->
<!-- {"agent":"B004","command_id":"000000023077","destination_path":"tools/leaser/Agents/Agent-B004/research/00043P-NewUserDialogPane2SelectTotem-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B004/00043P-NewUserDialogPane2SelectTotem-source-quality.md","timestamp":"2026-08-13T06:05:17-04:00","uid":"00043P"} -->
<!-- {"agent":"B004","command_id":"000000023114","destination_path":"executed-b-agent-research/B004/00043P-NewUserDialogPane2SelectTotem-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/00043P-NewUserDialogPane2SelectTotem-source-quality.md","timestamp":"2026-08-13T09:03:58-04:00","uid":"00043P"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
