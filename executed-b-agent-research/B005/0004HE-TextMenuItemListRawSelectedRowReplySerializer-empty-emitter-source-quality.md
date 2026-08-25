# UID0004HE TextMenuItemList Raw Selected-Row Reply Serializer Source-Quality Report
** TARGET-REPORT-UID:0004HE **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **


## Finalized Report / Current Recommendation

- Current recommendation: retain the now-applied reclassification of `[0x005195f0,0x0051971d)` from a blank-emitter no-route raw body to source method `void TextMenuItemList::SendSelectedTextMenuReply()`. Its complete behavior is compiler-inlined into the vtable-routed large-list branch of `TextMenuDialog::OnDialogAction` at `0x0051938f-0x00519492`.
- Current ordinary-document state: `CANONICAL_OWNER:0000ET`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000ET`, and UID0004HE `93/94`; the exact definition is in the target CPP channel, while target H remains blank because UID0000ET's file-local class declaration owns the declaration.
- Applied support repair: UID0000ET contains the public method declaration and is `91/91`; UID0000ES contains `friend class TextMenuItemList;` and remains `86/86`; UID0004HC calls `list->SendSelectedTextMenuReply()` before closing and is `91/93`; UID0001BN and UID0000OP contain the complete inventory/source-order/history update and retain `90/92` and `90/86`.
- IDA disposition: a passing applicable exact-artifact Gate 1 audit is a prerequisite for the supervisor to define the exact function, declare one incomplete receiver tag, apply a collision-free name/prototype, or add five bounded comments. This is a timeless prerequisite, not a current gate-status statement. No IDA mutation was performed by B005.
- Confidence: very strong for range, ABI, behavior, owner, source placement, retained-source classification, and emitter route; strong rather than symbol-proven for the lexical method name, access-control spelling, and exact pre-optimization source factoring.

## Supporting Research

- Assignment authority: B005 `goal.md`, SHA256 `5ADF706CDC65F75DB7F0FDB89DCD344C7D245BB1CF5566391C8E1352FD50F53B`, explicitly assigns UID0004HE as report-only research.
- Historical callback authority: the supervisor passed exact-artifact Gate 1 for report SHA256 `06766765B30CFBEDAAFB463C2869134047720275708EEE10693DB3A1217B1043` and authorized the six ordinary-document paths listed in this report. UID0004HF, IDA, coverage, generated-file mutation, tracker/state mutation, and report lifecycle were excluded from that callback.
- Report-time target identity: `by-memory/0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer.md`, SHA256 `8D6284D280244AA92D72A963805132BF65C7678B7017AB932646A503D715FF45`, 2,507 bytes, 38 physical lines.
- Report-time support identities:
  - `by-class/TextMenuItemList.md`: SHA256 `C2AFC09E3E1BA7D422FD9492B763530F2EC2AE5F53DD4975E51E58825EBBAD26`, 27,889 bytes, 257 lines.
  - `by-memory/0x00519210-0x005194b1.TextMenuDialogOnDialogAction.md`: SHA256 `60441FB96469502E35B6B69631E0AEBE3A512CFA94DA92A3EA881724B7695D91`, 4,323 bytes, 81 lines.
  - `by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md`: SHA256 `6C834ED91A103D93855EAD84AD4F89A3BBF40AE6004669A70E229A6E21FF50DD`, 31,071 bytes, 173 lines.
  - `by-file/TextMenuDialogs.md`: SHA256 `E9FB9EEAE801316CDB499C16EE41DB41F87C09C9682B3E31FF3F531130D885F9`, 31,742 bytes, 177 lines.
  - `by-class/TextMenuDialog.md`: SHA256 `DECEFD0044D53969A15CFEDB360A9D84976765120B562EF041250C2CC460C3F9`, 16,097 bytes, 132 lines.
  - sibling `by-memory/0x00519720-0x0051983a.TextMenuItemListRawExplicitIdReplySerializer.md`: SHA256 `BAC9E131BE6C0CE3FB5E48F0D7FDC18AADC9157654916BE411B4EF7C3D1DAEA5`, 2,376 bytes, 38 lines.
- Historical reports checked claim-by-claim rather than copied:
  - B009 UID0001BN family report: SHA256 `EE6EFAC23C5260EADE0A6F7599D819F57FCFCE701DD3CFE0580114B042E2A0F0`, 74,038 bytes, 786 lines.
  - B012 UID0000ET class report: SHA256 `3F7CCDDCDAE803958FF575EFDC5298C115476820DBC5B2B165AD6EC86263F24C`, 40,463 bytes, 688 lines.
  - B006 analogous UID0004HB retained-helper report: SHA256 `85333FAFC5E11C812A8EA7D2679FCA1924530A1567CBF1DFF468EB012FA5B873`, 96,545 bytes, 672 lines.
- Live IDA evidence was collected read-only on 2026-08-14 from session `supervisor-uid0000KZ-gate2b-20260814`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `15932`. `server_health` returned `status:ok`, Hex-Rays ready, strings cache ready, and bounded queries succeeded; `auto_analysis_ready:false` did not prevent stable reads.
- Binary identity: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`, 2,679,296 bytes, image base `0x00400000`.
- Dated generated snapshot, read-only and non-authoritative: validator command `000000023592`, refreshed `2026-08-14T16:39:03-04:00`; `TextMenuDialogs.cpp` SHA256 `23D0DA1F0DF1BF2614E72E64F311E7BD314C539E933376E230EE1861C00B024F`, 18,020 bytes, 579 lines; `TextMenuDialogs.h` SHA256 `EABC0090B9C33348AC9F73DC0B69EDC544125F495AFB0913833B071E1C4A549E`, 1,596 bytes, 45 lines.
- Dated tracker snapshot: `auto-generated/-ag-research-tracker.md` SHA256 `0C095CAA40249A283E156EBE6FDA86CE0F8000D6DBCD5A163FBCFF58100DED4C`; UID0004HE at line 1689 is `86/91`, reconstructable true, zero issue counts, and uncovered.

## Target

- Target UID: `0004HE`.
- Additional target UIDs: none. UID0000ET, UID0000ES, UID0004HC, UID0001BN, UID0000OP, UID0004HF, UID0003YJ, UID0003YO, and UID0001HU are support evidence or destinations, not additional scored targets.
- Declared-target inventory: one retained raw selected-row reply serializer at `[0x005195f0,0x0051971d)`.
- Target path: `source-3/project-documentation/by-memory/0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer.md`.
- Source queue row: `auto-generated/-ag-research-tracker.md:1689`, report-time `86/91`, combined `88.5`, reconstructable, not covered.
- Pre-callback supervisor classification: reconstructable by-memory empty emitter whose historical no-route conclusion required recheck rather than acceptance as a no-code veto. Current ordinary-document classification is retained source-emitting by-memory child through UID0000ET.
- Current post-callback scores and parent state: target `93/94`; direct class owner UID0000ET `91/91`, emitting through file UID0000OP `90/86`; support UID0004HC `91/93`; aggregate UID0001BN `90/92`; UID0000ES remains `86/86`.

## Current Target State

- Current metadata: `COMPLETION:93`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000ET`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000ET`, exact CPP, blank H, `Nested:0`.
- Current owner/source state: owner and emitter are UID0000ET; the target owns the retained definition and UID0000ET owns the declaration through UID0000OP `TextMenuDialogs.cpp`.
- Current behavior prose and source use explicit-index `ListPane::GetItem(m_selectedIndex)`; stale `GetSelectedEntry` is preserved only as a corrected historical assumption.
- Residual evidence limitations: the retained body has zero direct/all-head xrefs, no pointer/vtable route, no original lexical symbol, and no direct source archive; exact pre-optimization factoring and access-control spelling are inferred. Those facts cap confidence but no longer imply blank source. IDA application/readback is a supervisor-only action governed by the applicable exact-artifact gates, not a mutable report-body status.
- Dated callback-generated snapshot from command `000000023733`: one UID0004HE definition and declaration, the UID0000ES friend, and the UID0004HC list-method call; physical order is `AddTextEntry`, UID0004HE `SendSelectedTextMenuReply`, `ForwardOwnerSelectionState`, then `DrawListItem`, with no UID0004HE empty marker or UID0004HF emission. If a newer command exists, its physical headers and metadata determine generated truth.
- Artifact/lifecycle authority: execution/archive truth is authoritative only from the report's current path and validator-owned status/history metadata; this report body makes no mutable current execution/archive assertion.

## Executive Recommendation

- Keep UID0004HE under direct semantic owner UID0000ET `TextMenuItemList` and physical source owner UID0000OP `TextMenuDialogs.cpp`.
- Set target emitter UID0000ET and emit an ordinary private-helper-class method definition named `SendSelectedTextMenuReply`.
- Preserve the exact child range. Do not merge it into UID0004HC: the out-of-line retained body and the inlined active expansion are distinct compiler manifestations of one source method.
- Do not reclassify as dead/compiler-generated code. It has complete application packet behavior, list/owner fields, a normal thiscall prologue/epilogue, and a live semantic expansion.
- Keep UID0004HF independently unresolved for its own target pass; use it as strong overload/body corroboration but do not silently claim or rescore it here.
- Role and prerequisite boundary: the dated receipts below record the ordinary-document edits, scoped validation, and generated readback performed by B005. B005 never owns IDA mutation, manual coverage, validator `execute_report`, or archive movement; the supervisor/validator may perform those actions only after the applicable exact-artifact gates pass. This statement does not assert the report's current gate or lifecycle status.

## Supervisor Active Recheck

- Trigger: the supervisor assigned UID0004HE and explicitly required the empty-emitter/no-route/source-quality questions to be resolved rather than restated.
- Split repair: no new split is needed. Exact predecessor and successor padding already isolate the child.
- Source-bearing child disposition: the accepted ordinary-document callback established UID0004HE as the source-bearing child and applied the exact formal CPP, class declaration route, action-handler call route, source placement, and score. The structured IDA handoff is declarative supervisor-only material whose use depends on applicable exact-artifact gates; this sentence makes no assertion about current Gate 2B status.
- Gate 2B frame contract: the declarative handoff now requires all four action-time frame rows in order (`var_100 +0x0c`, `var_FC +0x10`, `__saved_registers +0x10c`, `__return_address +0x110`) and rejects the superseded partial two-entry observations as current authority.
- Sibling control: UID0004HF was fully compared as evidence, but remains a separate target because it has a distinct ABI/range and no explicit assignment in this report.
- No score blocker is passed forward as `needs investigation`. Lexical uncertainties receive best-probability source-facing resolutions and bounded score caps.

## Inference Research Guidance Check

- Current `by-structure.md`/skill discipline allows a source-shaped retained helper to emit when behavior, owner, range, source placement, and source form are resolved; direct xrefs are one liveness signal, not a universal source-existence requirement.
- Existing assumptions treated as uncertain: blank emitter, no-route equals no source, `GetSelectedEntry` as the ListPane helper name, the three-argument dialog overload as the only large-list source form, and the raw helper as duplicate dead code.
- IDA fact: target and sibling have no direct route. Documentation fact: both are class-owned serializers. Inference: the active optimizer inlined UID0004HE into UID0004HC and retained the standalone method body.
- The exact original identifier is not present in symbols. `SendSelectedTextMenuReply` is the best descriptive project-consistent spelling already proposed by UID0000ET and now supported by live source-liveness evidence.
- Wave2/Wave3 material was encountered in historical class prose and ignored as stale planning provenance. No conclusion relies on it.

## Heuristic / Inference Reanalysis And Validation

| Issue | Research performed | Resolution | Classification |
| --- | --- | --- | --- |
| Raw helper liveness | Read all 80 instruction heads, exact bytes/boundaries, start and every-interior xref state, pointer encodings, vtables, sibling, and active handler | No direct route exists, but UID0004HC contains the complete active expansion | Direct fact plus strong compiler inference |
| Selected-row role | Traced inherited offset `+0x134`, explicit `ListPane_GetItem`, and row word load | Method sends the currently selected `TextMenuItemListEntry::itemId`; negative selection returns without sending | Direct fact |
| Packet protocol | Traced numeric writers, string writer, cursor updates, guard, terminator, and socket call | Opcode `0x39`, list menu type, big-endian menu id, big-endian row id, optional owner ANSI text, non-sent zero, send | Direct fact |
| Source-facing name | Compared UID0000ET candidate vocabulary, TextMenuDialog `SendMenuReply`, sibling ABI, and function role | `SendSelectedTextMenuReply()` is preferred; raw/IDA names are rejected | Descriptive inference |
| Pre-optimization factoring | Compared target, sibling, and inlined expansion | Original source may have delegated to the explicit-id overload or a dialog helper, but no call survives; emit one self-contained method to avoid inventing an unresolved dependency | Bounded source-shape inference |
| Access control | Checked direct loads from owner `+0x279/+0x27c` and current private TextMenuDialog fields | Add `friend class TextMenuItemList;`; no accessor call is present to justify an invented accessor API | Strong inference |
| List accessor name | Checked live `0x004f3dc0` type and current ListPane docs | Use `GetItem(m_selectedIndex)`, not caller-biased `GetSelectedEntry` | Direct type/documentation fact |
| Packet helper source shape | Compared raw calls with accepted PacketBuffer formal APIs | Use human-facing cursor append helpers; do not expose raw `sub_` names or manual decompiler labels | Supported source inference |
| Range-check tail | Traced `<0x100`, indexed local write, and `__report_rangecheckfailure` | Express `packet[cursor] = 0`; do not write compiler failure calls in source | Direct fact plus compiler-source mapping |
| `GetMemoryMan` call | Disassembled the two-instruction accessor; return is immediately overwritten and has no target-visible use | Preserve as binary evidence but omit the unused accessor call from human source; it has no runtime state mutation | Direct fact and behavior-preserving source cleanup |
| Owner/emitter/source placement | Checked receiver fields, constructor callers, physical family, class/file docs, and generated source | UID0000ET owner/emitter, UID0000OP final file | Very strong |
| Score blocker | Rechecked all previously named blockers instead of carrying them forward | Blank C++/emitter and no-route veto are resolved; only lexical/source-factoring uncertainty remains | Resolved |

Rejected alternatives:

- Preserve blank CPP because xrefs are zero: rejected by the complete vtable-routed inline expansion.
- Merge target bytes into UID0004HC: rejected by independent padded range and standalone prologue/epilogue.
- Assign to `TextMenuDialog`, PacketBuffer, Socket, or ListPane: rejected because the receiver and list context fields belong to `TextMenuItemList`; those entities are owner/dependency/callee support only.
- Emit a raw `sub_5195F0`, manual security cookie, `__report_rangecheckfailure`, or decompiler local names: rejected as compiler/reverse-engineering residue.
- Call UID0004HF from formal target C++: plausible historical factoring, but rejected for this target-only callback because UID0004HF remains an unapproved blank emitter and no surviving call proves that exact source factoring.
- Invent owner getters: rejected because no accessor calls survive and a narrow friend relation explains direct private-field access without adding unbacked runtime calls.

No behavior, ownership, source-placement, emitter, range, or code question remains unanswered. Exact original lexical spelling and whether an optimizer inlined a sibling overload remain inherently unrecoverable from this binary; they cap confidence but are resolved to the highest-probability source form rather than left as blockers.

## Evidence Standards Used

- Direct evidence: current live IDA MCP item/type/comment/function/xref/instruction queries; exact PE bytes and SHA256 range hashes; function ABI; vtable cells; global type; packet helper types; predecessor/successor padding.
- Corroboration: UID0004HC active vtable route and inline body, UID0004HF sibling overload shape, UID0004HB retained-helper precedent, current ListPane/PacketBuffer/Socket support docs, owner constructor/vtable evidence, generated-source omissions.
- Negative evidence: zero start/interior xrefs, zero code/data/immediate refs, zero VA/RVA/raw-offset pointer patterns, absence from TextMenuItemList vtables, absent original symbols/types/comments.
- Evidence ladder: binary behavior and exact range facts outrank historical prose; repeated semantic expansion plus owner-local fields supports source inference; descriptive naming is accepted where source symbols are irretrievably lost.
- Tool limitation: `auto_analysis_ready:false` is recorded, but bounded IDB queries were stable and Hex-Rays ready. No unavailable MCP evidence was silently substituted with documentation.

## Evidence Checked

- IDA MCP: `idb_list`, `server_health`, `survey_binary`, `lookup_funcs`, `analyze_function`, expected `decompile` failure at raw start, `inspect_items`, `get_comments`, `get_bytes`, `insn_query`, `xref_query`, `xrefs_to`, `find_bytes`, `entity_query`, `type_inspect`, and global readback.
- Raw PE: section mapping, target/sibling file offsets, exact body and padding hashes, unique target/sibling prologue signatures, VA/RVA/raw-offset pointer scans.
- Documentation: target, class owner, file owner, aggregate, action handler, sibling, TextMenuDialog, ListPane, PacketBuffer scalar/cursor/string helpers, Socket/global sender, manual coverage rows, generated coverage/tracker, generated CPP/H, and historical B006/B009/B012 reports.
- Negative checks: function object absent; target decompile unavailable as expected; target/sibling direct references absent; target not in primary/secondary/tertiary vtables; proposed IDA name collision absent; target/type/comments absent.
- Dated actor history: initial report-only work skipped ordinary edits, validators, generated refresh, IDA writes/save, and lifecycle work. The accepted callback later applied only the six authorized ordinary documents and scoped validators. Across both phases, B005 performed no IDA mutation/save and no coverage, tracker, generated-file, or report-lifecycle edit.

## Claim And Incorporation Ledger

- Fixed verification-state allocation in each twin table: `applied` 37, `proposed` 15, `already-present` 0, `excluded-with-reason` 0, `blocked` 0, and forbidden states 0. C4HE-001 through C4HE-037 use the `applied` classification; C4HE-038 through C4HE-052 use the `proposed` classification to encode supervisor-only actor allocation and prerequisites, not mutable gate or lifecycle status.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C4HE-001 | 0004HE | Preserve exact half-open target range `[0x005195f0,0x0051971d)` and body SHA256 `94B5D776499D730276233ECDDBD03FCAC7CD73258CF8B0FEC82868A2EDD16C8A` | High | PE bytes and live item model | target Status/Boundary Evidence | incorporate | applied |
| C4HE-002 | 0004HE | Record eight-byte leading and three-byte trailing `0xcc` padding with exact hashes | High | PE bytes, live get_bytes/items | target Boundary Evidence | incorporate | applied |
| C4HE-003 | 0004HE | Record ordinary void thiscall ABI with ECX receiver and no logical stack parameter | High | prologue, receiver save, plain `retn` | target ABI | incorporate | applied |
| C4HE-004 | 0004HE | Record signed negative `m_selectedIndex` early return | High | 0x519606-0x519614 | target Behavior | incorporate | applied |
| C4HE-005 | 0004HE | Use explicit-index `GetItem(m_selectedIndex)` rather than stale `GetSelectedEntry` | High | ListPane_GetItem type and ListPane docs | target Behavior/formal CPP | historicalize | applied |
| C4HE-006 | 0004HE | Record selected row `TextMenuItemListEntry::itemId` as zero-extended word at row offset zero | High | 0x51961b and row layout | target Behavior | incorporate | applied |
| C4HE-007 | 0004HE | Record opcode `0x39` and exact packet field order | High | 0x51961e-0x51969d | target Packet Semantics | incorporate | applied |
| C4HE-008 | 0004HE | Record `m_menuType` byte at list offset `+0x14c` | High | 0x519651 | target Layout/Packet Semantics | incorporate | applied |
| C4HE-009 | 0004HE | Record `m_menuId` dword at list offset `+0x150` serialized big-endian | High | 0x519674-0x51967a | target Layout/Packet Semantics | incorporate | applied |
| C4HE-010 | 0004HE | Record non-owning owner at `+0x154`, extra-string guard `+0x279`, and string object `+0x27c` | High | 0x5196a6-0x5196d9 | target Layout/Packet Semantics | incorporate | applied |
| C4HE-011 | 0004HE | Record cursor `<0x100` check and local non-sent trailing zero | High | 0x5196e7-0x5196fd | target Length Semantics | incorporate | applied |
| C4HE-012 | 0004HE | Record `g_packetSender` / Socket queue-and-send route with pre-terminator length | High | 0x5196ee-0x519704 and typed global | target Packet Semantics | incorporate | applied |
| C4HE-013 | 0004HE | Exclude security cookie, range-failure call, raw labels, and unused GetMemoryMan accessor from human source while preserving them as binary evidence | High | exact disassembly and helper body | target Source Draft/Compiler Exclusions | incorporate | applied |
| C4HE-014 | 0004HE | Preserve zero direct start-xref fact as negative liveness evidence, not a no-code veto | High | xrefs_to/xref_query | target Route Analysis/Historical Assumptions | historicalize | applied |
| C4HE-015 | 0004HE | Record zero external references to every target instruction head | High | bounded all-head xref query | target Route Analysis | incorporate | applied |
| C4HE-016 | 0004HE | Record zero VA, RVA, raw-offset, code, data, and immediate pointer routes | High | find/find_bytes/xref queries | target Route Analysis | incorporate | applied |
| C4HE-017 | 0004HE | Record absence from all TextMenuItemList vtable views while preserving vtable identity | High | vtable bytes and refs | target Route Analysis | incorporate | applied |
| C4HE-018 | 0004HE | Record exact live semantic expansion at `0x0051938f-0x00519492` | High | paired instruction inventory and inline hash | target Inline Duplicate Evidence | incorporate | applied |
| C4HE-019 | 0004HE | Record UID0004HC's live vtable route through cell `0x0061ecf4 -> 0x00519210` | High | xref/data readback | target Inline Duplicate Evidence | incorporate | applied |
| C4HE-020 | 0004HE | Reclassify target as a retained ordinary source method whose active call was compiler-inlined | High | complete body, inline expansion, owner locality | target Status/Source Classification | historicalize | applied |
| C4HE-021 | 0004HE | Use source name `TextMenuItemList::SendSelectedTextMenuReply()` and collision-free IDA name `TextMenuItemList__SendSelectedTextMenuReply` | Medium-high | role, class vocabulary, no collision | target Status/formal CPP and IDA handoff | incorporate | applied |
| C4HE-022 | 0004HE | Keep canonical owner UID0000ET TextMenuItemList | High | receiver fields/layout and class family | target metadata/Status | already-present | applied |
| C4HE-023 | 0004HE | Set emitter UID0000ET | High | class-owned method definition route | target metadata/Status | incorporate | applied |
| C4HE-024 | 0004HE | Place source under UID0000OP TextMenuDialogs.cpp after TextMenuItemList::AddTextEntry | High | physical order and file ownership | target Source Placement; file inventory | incorporate | applied |
| C4HE-025 | 0004HE | Raise target from 86/91 to 93/94 | High | resolved emitter/code/liveness/source blockers | target metadata/Score Rationale | incorporate | applied |
| C4HE-026 | 0004HE | Insert exact self-contained formal target CPP body | High | full reconstruction and support API contracts | target RECONSTRUCTION_CPP CODE | incorporate | applied |
| C4HE-027 | 0004HE | Keep target H blank because declaration is class-owned | High | emitter structure | target RECONSTRUCTION_H CODE | already-present | applied |
| C4HE-028 | 0000ET | Add public `void SendSelectedTextMenuReply();` declaration to the file-local TextMenuItemList class | High | call route and class access | TextMenuItemList formal CPP class declaration | incorporate | applied |
| C4HE-029 | 0000ET | Replace raw-no-route prose with retained-source/inline-expansion evidence and preserve historical negative evidence | High | current MCP versus old reports | TextMenuItemList method map/evidence/history | historicalize | applied |
| C4HE-030 | 0000ET | Raise class score from 89/88 to 91/91 | Medium-high | one raw helper resolved; explicit-id sibling remains capped | TextMenuItemList metadata/Changes | incorporate | applied |
| C4HE-031 | 0004HC | Replace manual large-list selected-row serialization with `list->SendSelectedTextMenuReply()` and then close | High | exact inline expansion and source factoring | OnDialogAction formal CPP/evidence | historicalize | applied |
| C4HE-032 | 0004HC | Raise action-handler support score from 90/92 to 91/93 | Medium-high | stale private-field/accessor source repaired | OnDialogAction metadata/Changes | incorporate | applied |
| C4HE-033 | 0000ES | Add `friend class TextMenuItemList;` to permit direct owner extra-string access without invented getters | Medium-high | direct field loads and no accessor calls | TextMenuDialog formal H/evidence | incorporate | applied |
| C4HE-034 | 0001BN | Reclassify UID0004HE inventory entry as retained source-emitting child and preserve UID0004HF as separate unresolved sibling | High | target/sibling audit | aggregate inventory/history | historicalize | applied |
| C4HE-035 | 0000OP | Update file inventory/source order and generated expectations for UID0004HE | High | owner route and current generated omission | TextMenuDialogs file inventory/history | incorporate | applied |
| C4HE-036 | 0004HF | Preserve sibling 86/91, owner UID0000ET, blank emitter/CPP, exact independent range, and future target-specific review | High | distinct ABI/range and no assignment | sibling page and aggregate references | already-present | applied |
| C4HE-037 | 0003YJ | Preserve current value-first scalar writer evidence and use established human-facing cursor append wrappers in formal source | High | helper types/docs and analogous emitted code | target Source Draft/support references | already-present | applied |
| C4HE-038 | 0004HE | Supervisor uses public `define_func` for exact `[0x005195f0,0x0051971d)` and requires literal name `sub_5195F0`, empty persisted item type, `analyze_function` prototype `null`, decompiler declaration `void __thiscall sub_5195F0(int *this)`, four-row frame `var_100 +0x0c/4 _DWORD`, `var_FC +0x10/4 _DWORD`, `__saved_registers +0x10c/4 _DWORD`, and `__return_address +0x110/4 _UNKNOWN *`, `AR` absent, `AP` absent, `FR` absent, `FP` absent, and 4/0/0 added/removed/replaced intermediate before any dependent action | High | current canonical fail-closed I01 reproduction plus exact prologue/ret/padding/body hash and UID0004HB/current-schema raw-function precedent | canonical IDB target function item | incorporate | proposed |
| C4HE-039 | 0004HE | Supervisor uses public `declare_type` to declare only incomplete `struct TextMenuItemList` after the exact four-row I01 intermediate passes and before applying the prototype | High | type_inspect absent; no safe full UDT; four-row target frame reproduced | canonical IDB local type | incorporate | proposed |
| C4HE-040 | 0004HE | Supervisor uses public `rename` with `pure:true`, no overwrite, to apply `TextMenuItemList__SendSelectedTextMenuReply` only after the exact I01 empty-persisted-type, null-prototype, decompiler-`int *this`, four-row-frame intermediate and collision check pass | Medium-high | no collision, exact reproduced four-row intermediate, and source role | canonical IDB target name | incorporate | proposed |
| C4HE-041 | 0004HE | Supervisor uses public `set_type` to replace the empty persisted type/null analysis prototype and decompiler `int *this` presentation with the exact final void thiscall `TextMenuItemList *this` prototype while preserving all four physical frame rows | High | ECX receiver, plain retn, and current canonical deterministic four-row I01/I03 intermediate | canonical IDB target type | incorporate | proposed |
| C4HE-042 | 0004HE | Supervisor uses public `set_function_comments` for the exact regular function comment linking retained body and inline expansion only while all four target frame rows remain unchanged | High | target/inline comparison and four-row frame protection | canonical IDB function comment | incorporate | proposed |
| C4HE-043 | 0004HE | Supervisor uses public `set_address_comments` for the exact regular comment at `0x00519606` describing selected-index/GetItem semantics only while all four containing-function frame rows remain unchanged | High | direct instructions and four-row containing-function readback | canonical IDB address comment | incorporate | proposed |
| C4HE-044 | 0004HE | Supervisor uses public `set_address_comments` for the exact regular comment at `0x005196a6` describing owner extra-string semantics only while all four containing-function frame rows remain unchanged | High | direct instructions and four-row containing-function readback | canonical IDB address comment | incorporate | proposed |
| C4HE-045 | 0004HE | Supervisor uses public `set_address_comments` for the exact regular comment at `0x005196f5` describing checked non-sent terminator semantics only while all four containing-function frame rows remain unchanged | High | direct instructions and four-row containing-function readback | canonical IDB address comment | incorporate | proposed |
| C4HE-046 | 0004HC | Supervisor uses public `set_address_comments` for the exact regular comment at `0x0051938f` linking the active inline expansion to UID0004HE only after the UID0004HE four-row dependency frame remains unchanged | High | exact paired behavior and four-row target dependency readback | canonical IDB inline address comment | incorporate | proposed |
| C4HE-047 | 0004HE | Preserve P01's literal leading SHA256 `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3`, target SHA256 `94B5D776499D730276233ECDDBD03FCAC7CD73258CF8B0FEC82868A2EDD16C8A`, trailing SHA256 `E668F0A1B72560CED14C54488A25335D11336448950BB6485267EBC5EB3FECEE`, zero start/all-head xrefs, and empty code/data/immediate/VA/RVA/raw-offset/vtable route sets outside bounded I01-I08 metadata actions | High | hashes/items/xrefs | canonical IDB protected state | already-present | proposed |
| C4HE-048 | 0004HF | Preserve P02's sibling body SHA256 `CB928A0115A74BA12B714758CA0A23D6D26C83C7480E418894371E8746C4C65A`, trailing-padding SHA256 `33CC4A00A0F04735602819132DA3E3FAC4CDEB8EC7AEE92551DC79BA8488E722`, absent function, absent entry name, absent entry type, absent entry `AR`, absent entry `AP`, not-applicable entry `FR`, and not-applicable entry `FP` | High | sibling hash/items/comments | canonical IDB protected state | already-present | proposed |
| C4HE-049 | 0004HC | Preserve every literal P03 function/cell range, hash, xref, vtable-value, and independent channel field plus every address-indexed P04 vtable/g_packetSender byte, name, type, value, comment, and channel field; I09 remains the sole address-item `AR` exception | High | live readback | canonical IDB protected state | already-present | proposed |
| C4HE-050 | 0004HE | Insert exact manual by-memory coverage row after UID0004HB | High | absent current row and proposed target state | by-memory/-coverage-report.md | incorporate | proposed |
| C4HE-051 | 0000ET | Replace stale class coverage row and stale aggregate coverage row with exact proposed/current state | High | physical manual-row readback | by-class/-coverage-report.md and by-memory/-coverage-report.md | incorporate | proposed |
| C4HE-052 | 0004HE | Supervisor owns action-time generated CPP/H and research-tracker reread, manual coverage application/validation, Gate 2B application/readback/persistence, and validator lifecycle execution/archive | High | supervisor-only workflow and actor boundaries | supervisor-owned generated/tracker/coverage/IDA/lifecycle outputs | incorporate | proposed |

## Positive Evidence Summary

- The target is a complete 301-byte ordinary thiscall body with application-specific list fields and opcode `0x39` packet semantics, not padding, thunk glue, or an orphaned fragment.
- UID0004HC's active large-list branch repeats the target's selected-index read, `GetItem`, row-id load, numeric field order, optional owner string, cursor guard, terminator, and socket send before closing the dialog.
- UID0004HC is live through vtable cell `0x0061ecf4`; this gives the target source behavior an active route even though the retained standalone copy has no direct xref.
- UID0004HF independently repeats the serializer body with an explicit item-id parameter, corroborating a TextMenuItemList method family rather than accidental byte similarity.
- Target fields align exactly with documented UID0000ET layout: inherited selection `+0x134`, `m_menuType +0x14c`, `m_menuId +0x150`, and owner pointer `+0x154`.
- Physical placement between `AddTextEntry` and the explicit-id sibling within the TextMenuItemList cluster supports class ownership and source order.
- The analogous UID0004HB report already established that no-start-xref retained source can emit when a complete active inline expansion resolves liveness. This is corroboration, not substitute evidence.

## IDA MCP Facts

- Function/range: `lookup_funcs(0x005195f0)` returns `Not a function`; `analyze_function` reports no function; decompilation fails as expected; the exact range contains 80 instruction heads and ends in normal `retn` plus compiler range-failure tail.
- ABI: `ECX` is saved as receiver; there are no logical stack arguments; normal exit is plain `retn`.
- Boundaries: `0x005195e8-0x005195f0` is eight `0xcc` bytes; target is 0x12d bytes; `0x0051971d-0x00519720` is three `0xcc` bytes.
- Hashes: lead `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3`; target `94B5D776499D730276233ECDDBD03FCAC7CD73258CF8B0FEC82868A2EDD16C8A`; trail `E668F0A1B72560CED14C54488A25335D11336448950BB6485267EBC5EB3FECEE`.
- Active inline expansion: `[0x0051938f,0x00519492)` is 0x103 bytes, SHA256 `23788D4E9028044606F1B0BBF9C19F80E34F4EEBF966B09B474A57ED4813734C`; containing OnDialogAction body SHA256 is `5A392B4E39A6AB238D3B14D9761719AA7D100BF6549FDFE197F3D40B8796F860`.
- Sibling: `[0x00519720,0x0051983a)` is 0x11a bytes, SHA256 `CB928A0115A74BA12B714758CA0A23D6D26C83C7480E418894371E8746C4C65A`, explicit unsigned-short logical argument, `retn 4`, no function object.
- Xrefs: target start has zero; every target instruction head has zero external inbound refs; no target/sibling code/data/immediate or VA/RVA/raw-offset pointer patterns were found.
- Vtables: TextMenuItemList primary vtable begins `0x0061ed48`; target/sibling are absent. The active handler is referenced from `0x0061ecf4 -> 0x00519210`.
- Types: `TextMenuItemList` is absent; `TextMenuDialog` and `ListPane` exist only as incomplete opaque declarations. `ListPane_GetItem` is typed `void *__thiscall(ListPane *this, int index)`.
- Global: `g_packetSender` at `0x0067a7ec` is typed `Socket *`; `Socket_QueueAndSendPacket` is typed `void __thiscall(Socket *this, const void *packetData, __int16 packetSize)`.
- Current target and planned comment addresses have absent regular and repeatable comments. Proposed name `TextMenuItemList__SendSelectedTextMenuReply` has no collision.
- Dated action-time I01 evidence: current canonical reproduction returned four physical rows in order (`var_100 +0x0c/4 _DWORD`, `var_FC +0x10/4 _DWORD`, `__saved_registers +0x10c/4 _DWORD`, `__return_address +0x110/4 _UNKNOWN *`), then fail-closed rollback restored the canonical no-function state without save.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005195e8-0x005195f0` | UID0000VN `-ignored.md` | leading alignment | false/ignored | UID0001BN | 100 | exact `0xcc` padding; preserve |
| `0x005195f0-0x0051971d` | UID0004HE target | selected-row reply source method | true | UID0000ET | 86/91 -> 93/94 applied | exact CPP emits through UID0000ET |
| `0x0051971d-0x00519720` | UID0000VN `-ignored.md` | alignment before overload | false/ignored | UID0001BN | 100 | exact `0xcc` padding; preserve |
| `0x00519720-0x0051983a` | UID0004HF | explicit-id serializer sibling | true | UID0000ET | 86/91 | evidence only; separate target review |
| `0x0051983a-0x00519840` | UID0000VN `-ignored.md` | alignment before virtual | false/ignored | UID0001BN | 100 | exact `0xcc` padding; preserve |
| `0x0051938f-0x00519492` | inside UID0004HC | active compiler-inlined expansion | compiler-covered by UID0004HE source call | UID0000ES | 90/92 -> 91/93 applied | manual source replaced by method call |
| `0x0061ed48` primary vtable | UID00031Y support | TextMenuItemList virtual routing | compiler data | UID0000OP | support | excludes target/sibling; preserve |

- Inventory total: one assigned source body, one source sibling used only as corroboration, one active inline expansion, three padding ranges, and one vtable support item.
- No new child or range split is required.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005195f0` | zero inbound xrefs | retained out-of-line copy has no direct current route |
| every target instruction head | zero external inbound xrefs | no hidden interior entry was found |
| target bytes/pointers | zero code/data/immediate and VA/RVA/raw-offset patterns | no pointer-table or relocation route |
| `0x00519616` | calls `ListPane_GetItem` | explicit selected-index row lookup |
| `0x00519636/0x00519659/0x0051967a/0x00519698` | calls scalar packet writers | exact numeric field order |
| `0x005196d3/0x005196d9` | calls StringBase data access then ANSI string append | optional owner extra text |
| `0x00519704` | calls `Socket_QueueAndSendPacket` | final send route |
| `0x0061ecf4` | data xref to `0x00519210` | active OnDialogAction vtable route |
| `0x0051938f-0x00519492` | inside live OnDialogAction | complete inlined source call expansion |
| `0x0061ed48` vtable family | no cell targets UID0004HE/UID0004HF | helper is nonvirtual |

## Documentation Evidence And IDA Status

- Supporting current docs: UID0000ET already owns the range and proposes `SendSelectedTextMenuReply`; UID0000OP places the class in TextMenuDialogs.cpp; UID0004HC documents the active large-list action; ListPane rejects `GetSelectedEntry` as a reusable name; PacketBuffer/Socket docs establish source-facing APIs.
- Historical pre-callback contradiction: target, UID0000ET, UID0001BN, and UID0000OP described UID0004HE as blank-C++/no-route, while UID0004HC manually reached into list-private fields and used stale `GetSelectedEntry`. The accepted callback corrected all five destinations while preserving the prior state as history.
- Dated IDA pre-action snapshot (`2026-08-14`): target/sibling were code items but not functions, and target type/name/comments were absent. That snapshot supports the bounded supervisor function/type/name/comment recommendation; the supervisor must establish action-time canonical truth by fresh readback under the applicable exact-artifact gates.
- Generated snapshots are dated evidence, not permanent current authority: command `000000023592` recorded the pre-callback omission and stale UID0004HC branch, while command `000000023733` recorded the callback-generated definition/declaration/caller/header result documented under Current Target State and Validator Results. If a newer validator command exists, its physical headers and metadata determine generated truth.
- Ordinary destination frame-offset scan (read-only, `2026-08-14T22:59:31.4166303-04:00`): checked `by-memory/0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer.md`, `by-class/TextMenuItemList.md`, `by-class/TextMenuDialog.md`, `by-memory/0x00519210-0x005194b1.TextMenuDialogOnDialogAction.md`, `by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md`, and `by-file/TextMenuDialogs.md`. No occurrence of either frame-row name or any target-frame offset contract was present, so no ordinary destination requires a frame-offset callback repair; no ordinary document was edited.
- Dated manual-coverage snapshot from the callback review: by-memory coverage lacked UID0004HE, class coverage showed 84%, and the aggregate manual row showed 86% against UID0001BN metadata 90%. Manual coverage is supervisor-owned collision-sensitive state and must be reread when an authorized action is considered.

## Ranked Ownership Analysis

### 1. UID0000ET TextMenuItemList

- Evidence for: ECX receiver layout, inherited selection field, list context fields, owner pointer, sibling method family, physical placement, and existing class inventory all agree.
- Evidence against: no original symbol and no direct retained-body caller.
- Decision: canonical owner and emitter. Negative route evidence affects confidence, not ownership or source existence.

### 2. UID0000ES TextMenuDialog

- Evidence for: owner extra-string fields are read and OnDialogAction contains the active expansion.
- Evidence against: target receiver is the list, list fields supply packet context, and target starts inside the TextMenuItemList physical cluster.
- Decision: support/friend/caller owner only; not target owner.

### 3. PacketBuffer / Socket / ListPane

- Evidence for: they supply serialization, send, and row-access dependencies.
- Evidence against: none owns menu context, owner pointer, selected-row policy, or source locality.
- Decision: reject as canonical/source owners.

### Proposed new file/grouping, if applicable

- No new file. Keep the private helper class and method in UID0000OP `TextMenuDialogs.cpp`.
- Do not create a standalone `TextMenuItemList.cpp`; constructor callers, owner relation, and file family reject it.

## Source Placement

- Recommended placement: `TextMenuItemList::SendSelectedTextMenuReply()` in UID0000OP `TextMenuDialogs.cpp`, after `AddTextEntry` and before the eventual explicit-id sibling definition.
- The by-memory target owns the method body; UID0000ET owns the file-local class declaration and emits the child through its `[[CHILDREN]]` route; UID0000OP owns final compilation-unit placement.
- UID0000ES H owns the friend declaration because TextMenuItemList directly reads private TextMenuDialog fields.
- UID0004HC owns only the caller-shaped action-handler body and now calls the method rather than duplicating it in reconstructed source.
- Rejected placements: TextMenuDialog body ownership, standalone list file, generic PacketBuffer/Socket helper file, or ListPane base class.

## Range / Split / Padding / Reclassification Analysis

- Exact target range is half-open `[0x005195f0,0x0051971d)`, 0x12d/301 bytes.
- Predecessor alignment `[0x005195e8,0x005195f0)` is eight `0xcc` bytes; successor alignment `[0x0051971d,0x00519720)` is three `0xcc` bytes.
- The target has its own prologue, stack cookie, normal return, and range-failure tail. It is not an interior slice of UID0004HC or UID0004HF.
- No merge/split/new child is required. The only reclassification is blank no-route raw helper -> retained ordinary source method.
- The inline region in UID0004HC is compiler-covered by the source call; it remains inside the action-handler byte range and must not become a second by-memory child.
- UID0004HF remains a distinct neighboring raw body with one logical stack parameter and `retn 4`.

## Negative Evidence Summary

- No function object, direct start xref, external interior xref, pointer encoding, immediate reference, relocation-like route, or vtable entry reaches UID0004HE.
- No original source symbol proves `SendSelectedTextMenuReply`, friend placement, or exact local variable spellings.
- The dated `2026-08-14` IDA pre-action snapshot found no `TextMenuItemList` UDT, so this report recommends only an incomplete declaration and rejects a fabricated complete structure. Action-time type state is supervisor-readback authority.
- No surviving call proves whether the original method delegated to UID0004HF or an inline TextMenuDialog helper. The report therefore does not claim that factoring as binary fact.
- Zero direct xrefs do not prove dead code here: the exact behavior is active inside a vtable-routed method, and the target is ordinary application code rather than compiler-only glue.
- Nearby UID0004HF similarity alone would not prove UID0004HE liveness; the decisive evidence is the full active inline expansion in UID0004HC.

## IDA Rename / Type / Comment Recommendations

All rows are declarative supervisor handoff only. B005 did not mutate or save IDA. The supervisor exclusively owns any application and may act only when the applicable exact-artifact gates authorize it; immediately before each action, the supervisor must reread the literal prestate, fail closed on drift, preserve dependency order, and leave every protected row unchanged. This role boundary does not assert current gate status. Public comment channels are abbreviated below as address regular (`AR`), address repeatable (`AP`), function regular (`FR`), and function repeatable (`FP`); `absent` means that exact channel is empty.

| ID | Classification | Public endpoint | Exact entity | Literal current pre-state | Exact proposed state | Evidence / safety constraints | Expected readback |
| --- | --- | --- | --- | --- | --- | --- | --- |
| I01 | apply | `define_func` | function range `[0x005195f0,0x0051971d)` | function: absent; entry item: code `[0x005195f0,0x005195f1)`; name: absent; type: absent; `AR`: absent; `AP`: absent; `FR`: not applicable because no function exists; `FP`: not applicable because no function exists; `stack_frame`: no function and no rows; boundary: data padding begins at `0x0051971d` | define exactly one function with start `0x005195f0` and exclusive end `0x0051971d` | target hash and padding must match C4HE-001/002; do not absorb padding or sibling; no later endpoint is permitted until every independently stated intermediate field passes in full | exactly one 0x12d function `[0x005195f0,0x0051971d)` named `sub_5195F0`; persisted/item type absent with empty `inspect_items` type; `analyze_function` prototype `null`; decompiler declaration exactly `void __thiscall sub_5195F0(int *this)`; frame row 1: `var_100 +0x0c/4 _DWORD`; frame row 2: `var_FC +0x10/4 _DWORD`; frame row 3: `__saved_registers +0x10c/4 _DWORD`; frame row 4: `__return_address +0x110/4 _UNKNOWN *`; frame exclusions: no additional local rows, no explicit argument rows, no physical `this` row, and no other rows; `AR`, `AP`, `FR`, and `FP` absent; frame delta added `4`, removed `0`, replaced `0`; body SHA256 and zero start/all-head xref sets unchanged; every literal intermediate-table field below matches |
| I02 | apply | `declare_type` | local type `TextMenuItemList` | `type_inspect`: `exists:false`, error `Type not found: TextMenuItemList` | declare incomplete `struct TextMenuItemList;` only | required receiver tag; do not invent size/members/inheritance | type exists as one incomplete declaration with no fabricated size, members, or inheritance |
| I03 | apply | `rename` with `pure:true` | target function name | function item: exactly one function `[0x005195f0,0x0051971d)`, size `0x12d`; current name: `sub_5195F0`; persisted/item type from `inspect_items`: absent, rendered as an empty type field; `analyze_function` prototype: `null`; decompiler declaration: exactly `void __thiscall sub_5195F0(int *this)`; frame row 1: `var_100`, offset `+0x0c`, size `0x04`, type `_DWORD`; frame row 2: `var_FC`, offset `+0x10`, size `0x04`, type `_DWORD`; frame row 3: `__saved_registers`, offset `+0x10c`, size `0x04`, type `_DWORD`; frame row 4: `__return_address`, offset `+0x110`, size `0x04`, type `_UNKNOWN *`; frame exclusions: no additional local rows, no explicit arguments, no physical `this`, and no other rows; frame delta from no-function state: added `4`, removed `0`, replaced `0`; `AR`: absent; `AP`: absent; `FR`: absent; `FP`: absent; body SHA256: `94B5D776499D730276233ECDDBD03FCAC7CD73258CF8B0FEC82868A2EDD16C8A`; start inbound xref count: `0`, exact set `{}`; external inbound xrefs to all 80 instruction heads: count `0`, exact set `{}`; proposed-name lookup for `TextMenuItemList__SendSelectedTextMenuReply`: `Not found`; I02 dependency state: exactly one incomplete `struct TextMenuItemList` declaration exists with no fabricated size, members, or inheritance | rename only the function at `0x005195f0` to `TextMenuItemList__SendSelectedTextMenuReply` with `pure:true`, no overwrite, and no directory side effect | before rename, stop if any independently stated range/name/persisted-type/prototype/decompiler/frame/channel/hash/xref/type-dependency/collision field differs; do not rename any neighbor; after rename, reread every poststate field and stop before I04 if any field differs | function item: exactly one function `[0x005195f0,0x0051971d)`, size `0x12d`; name: `TextMenuItemList__SendSelectedTextMenuReply`; persisted/item type from `inspect_items`: absent, rendered as an empty type field; `analyze_function` prototype: `null`; decompiler declaration: exactly `void __thiscall TextMenuItemList__SendSelectedTextMenuReply(int *this)`; frame row 1: `var_100`, offset `+0x0c`, size `0x04`, type `_DWORD`; frame row 2: `var_FC`, offset `+0x10`, size `0x04`, type `_DWORD`; frame row 3: `__saved_registers`, offset `+0x10c`, size `0x04`, type `_DWORD`; frame row 4: `__return_address`, offset `+0x110`, size `0x04`, type `_UNKNOWN *`; frame exclusions: no additional local rows, no explicit arguments, no physical `this`, and no other rows; frame delta from no-function state: added `4`, removed `0`, replaced `0`; `AR`: absent; `AP`: absent; `FR`: absent; `FP`: absent; body SHA256: `94B5D776499D730276233ECDDBD03FCAC7CD73258CF8B0FEC82868A2EDD16C8A`; start inbound xref count: `0`, exact set `{}`; external inbound xrefs to all 80 instruction heads: count `0`, exact set `{}`; lookup for `TextMenuItemList__SendSelectedTextMenuReply`: resolves uniquely to `0x005195f0`; no duplicate/collision; I02 incomplete declaration remains unchanged |
| I04 | apply | `set_type` | target function type | function item: exactly one function `[0x005195f0,0x0051971d)`, size `0x12d`; current name after I03: `TextMenuItemList__SendSelectedTextMenuReply`; persisted/item pre-type from `inspect_items`: absent, rendered as an empty type field; `analyze_function` pre-prototype: `null`; decompiler pre-declaration: exactly `void __thiscall TextMenuItemList__SendSelectedTextMenuReply(int *this)`; frame row 1: `var_100`, offset `+0x0c`, size `0x04`, type `_DWORD`; frame row 2: `var_FC`, offset `+0x10`, size `0x04`, type `_DWORD`; frame row 3: `__saved_registers`, offset `+0x10c`, size `0x04`, type `_DWORD`; frame row 4: `__return_address`, offset `+0x110`, size `0x04`, type `_UNKNOWN *`; frame exclusions: no additional local rows, no explicit arguments, no physical `this`, and no other rows; `AR`: absent; `AP`: absent; `FR`: absent; `FP`: absent; body SHA256: `94B5D776499D730276233ECDDBD03FCAC7CD73258CF8B0FEC82868A2EDD16C8A`; start inbound xref count: `0`, exact set `{}`; external inbound xrefs to all 80 instruction heads: count `0`, exact set `{}`; I02 dependency state: exactly one incomplete `struct TextMenuItemList` declaration exists with no fabricated size, members, or inheritance; I03 dependency state: the collision-free pure rename resolves uniquely to `0x005195f0`, no old-name target remains, persisted type remains absent, analysis prototype remains `null`, the decompiler declaration uses `int *this`, and all four frame rows remain unchanged | set only the function type to `void __thiscall TextMenuItemList__SendSelectedTextMenuReply(TextMenuItemList *this)` | ECX receiver and plain `retn`; before type application, stop if any independently stated I02/I03/range/name/persisted-type/prototype/decompiler/frame/channel/hash/xref field differs; do not define stack arguments, a physical `this` frame row, a full UDT, or alter either local/frame row; after application, reread every poststate field and stop before I05 if any field differs | function item: exactly one function `[0x005195f0,0x0051971d)`, size `0x12d`; name: `TextMenuItemList__SendSelectedTextMenuReply`; persisted/item type from `inspect_items`: exactly `void __thiscall TextMenuItemList__SendSelectedTextMenuReply(TextMenuItemList *this)`; `analyze_function` prototype: exactly `void __thiscall TextMenuItemList__SendSelectedTextMenuReply(TextMenuItemList *this)`; decompiler declaration: exactly `void __thiscall TextMenuItemList__SendSelectedTextMenuReply(TextMenuItemList *this)`; frame row 1: `var_100`, offset `+0x0c`, size `0x04`, type `_DWORD`; frame row 2: `var_FC`, offset `+0x10`, size `0x04`, type `_DWORD`; frame row 3: `__saved_registers`, offset `+0x10c`, size `0x04`, type `_DWORD`; frame row 4: `__return_address`, offset `+0x110`, size `0x04`, type `_UNKNOWN *`; frame exclusions: no additional local rows, no explicit arguments, no physical `this`, and no other rows; frame delta from I03 state: added `0`, removed `0`, replaced `0`; `AR`: absent; `AP`: absent; `FR`: absent; `FP`: absent; body SHA256: `94B5D776499D730276233ECDDBD03FCAC7CD73258CF8B0FEC82868A2EDD16C8A`; start inbound xref count: `0`, exact set `{}`; external inbound xrefs to all 80 instruction heads: count `0`, exact set `{}`; I02 incomplete declaration and I03 unique name resolution remain unchanged |
| I05 | apply | `set_function_comments` | target function regular comment | function item: exactly one function `[0x005195f0,0x0051971d)`, size `0x12d`; current name after I04: `TextMenuItemList__SendSelectedTextMenuReply`; persisted/item type from `inspect_items`: exactly `void __thiscall TextMenuItemList__SendSelectedTextMenuReply(TextMenuItemList *this)`; `analyze_function` prototype: exactly `void __thiscall TextMenuItemList__SendSelectedTextMenuReply(TextMenuItemList *this)`; decompiler declaration: exactly `void __thiscall TextMenuItemList__SendSelectedTextMenuReply(TextMenuItemList *this)`; frame row 1: `var_100`, offset `+0x0c`, size `0x04`, type `_DWORD`; frame row 2: `var_FC`, offset `+0x10`, size `0x04`, type `_DWORD`; frame row 3: `__saved_registers`, offset `+0x10c`, size `0x04`, type `_DWORD`; frame row 4: `__return_address`, offset `+0x110`, size `0x04`, type `_UNKNOWN *`; frame exclusions: no additional local rows, no explicit arguments, no physical `this`, and no other rows; `AR`: absent; `AP`: absent; `FR`: absent; `FP`: absent; body SHA256: `94B5D776499D730276233ECDDBD03FCAC7CD73258CF8B0FEC82868A2EDD16C8A`; start inbound xref count: `0`, exact set `{}`; external inbound xrefs to all 80 instruction heads: count `0`, exact set `{}` | set only `FR` to `Retained TextMenuItemList::SendSelectedTextMenuReply() helper; its complete selected-row opcode 0x39 body is compiler-inlined into TextMenuDialog::OnDialogAction at 0x0051938f-0x00519492. No current direct route reaches this retained copy.` | exact liveness/source relation; before comment application, stop if any independently stated range/name/persisted-type/prototype/decompiler/frame/channel/hash/xref field differs; leave `AR`, `AP`, and `FP` absent; preserve all four frame rows; after application, reread every poststate field and stop before I06 if any field differs | function item: exactly one function `[0x005195f0,0x0051971d)`, size `0x12d`; name: `TextMenuItemList__SendSelectedTextMenuReply`; persisted/item type from `inspect_items`: exactly `void __thiscall TextMenuItemList__SendSelectedTextMenuReply(TextMenuItemList *this)`; `analyze_function` prototype: exactly `void __thiscall TextMenuItemList__SendSelectedTextMenuReply(TextMenuItemList *this)`; decompiler declaration: exactly `void __thiscall TextMenuItemList__SendSelectedTextMenuReply(TextMenuItemList *this)`; frame row 1: `var_100`, offset `+0x0c`, size `0x04`, type `_DWORD`; frame row 2: `var_FC`, offset `+0x10`, size `0x04`, type `_DWORD`; frame row 3: `__saved_registers`, offset `+0x10c`, size `0x04`, type `_DWORD`; frame row 4: `__return_address`, offset `+0x110`, size `0x04`, type `_UNKNOWN *`; frame exclusions: no additional local rows, no explicit arguments, no physical `this`, and no other rows; frame delta from I04 state: added `0`, removed `0`, replaced `0`; `AR`: absent; `AP`: absent; `FR`: `Retained TextMenuItemList::SendSelectedTextMenuReply() helper; its complete selected-row opcode 0x39 body is compiler-inlined into TextMenuDialog::OnDialogAction at 0x0051938f-0x00519492. No current direct route reaches this retained copy.`; `FP`: absent; body SHA256: `94B5D776499D730276233ECDDBD03FCAC7CD73258CF8B0FEC82868A2EDD16C8A`; start inbound xref count: `0`, exact set `{}`; external inbound xrefs to all 80 instruction heads: count `0`, exact set `{}` |
| I06 | apply | `set_address_comments` | address `0x00519606` regular comment | address item: code `[0x00519606,0x0051960c)`; address-item name: absent; address-item type: absent; address-item `AR`: absent; address-item `AP`: absent; address-item `FR`: not applicable; address-item `FP`: not applicable; containing-function name: `TextMenuItemList__SendSelectedTextMenuReply`; containing-function type: `void __thiscall TextMenuItemList__SendSelectedTextMenuReply(TextMenuItemList *this)`; containing-function frame row 1: `var_100 +0x0c/4 _DWORD`; row 2: `var_FC +0x10/4 _DWORD`; row 3: `__saved_registers +0x10c/4 _DWORD`; row 4: `__return_address +0x110/4 _UNKNOWN *`; containing-function frame exclusions: no additional locals, no explicit arguments, no physical `this`, and no other rows; containing-function `AR`: absent; containing-function `AP`: absent; containing-function `FR`: `Retained TextMenuItemList::SendSelectedTextMenuReply() helper; its complete selected-row opcode 0x39 body is compiler-inlined into TextMenuDialog::OnDialogAction at 0x0051938f-0x00519492. No current direct route reaches this retained copy.`; containing-function `FP`: absent | set only address-item `AR` to `Read inherited m_selectedIndex at +0x134; a negative value returns without sending, otherwise GetItem(index) supplies the TextMenuItemListEntry.` | direct instruction semantics; address must remain inside I01; containing-function range/type/four-row frame/channels/hash/xrefs must match before and after | address item kind: code; address item head: `0x00519606`; address item range: `[0x00519606,0x0051960c)`; address-item name: absent; address-item type: absent; address-item `AR`: `Read inherited m_selectedIndex at +0x134; a negative value returns without sending, otherwise GetItem(index) supplies the TextMenuItemListEntry.`; address-item `AP`: absent; address-item `FR`: not applicable; address-item `FP`: not applicable; containing-function name: `TextMenuItemList__SendSelectedTextMenuReply`; containing-function type: `void __thiscall TextMenuItemList__SendSelectedTextMenuReply(TextMenuItemList *this)`; containing-function frame row 1: `var_100 +0x0c/4 _DWORD`; row 2: `var_FC +0x10/4 _DWORD`; row 3: `__saved_registers +0x10c/4 _DWORD`; row 4: `__return_address +0x110/4 _UNKNOWN *`; containing-function frame exclusions: no additional locals, no explicit arguments, no physical `this`, and no other rows; containing-function frame delta from I05: added `0`, removed `0`, replaced `0`; containing-function `AR`: absent; containing-function `AP`: absent; containing-function `FR`: `Retained TextMenuItemList::SendSelectedTextMenuReply() helper; its complete selected-row opcode 0x39 body is compiler-inlined into TextMenuDialog::OnDialogAction at 0x0051938f-0x00519492. No current direct route reaches this retained copy.`; containing-function `FP`: absent; containing-function range: `[0x005195f0,0x0051971d)`; containing-function body SHA256: `94B5D776499D730276233ECDDBD03FCAC7CD73258CF8B0FEC82868A2EDD16C8A`; containing-function start inbound xref count: `0`, exact set `{}`; containing-function external inbound instruction-head xref count: `0`, exact set `{}`; containing-function vtable target-cell count: `0`, exact set `{}` |
| I07 | apply | `set_address_comments` | address `0x005196a6` regular comment | address item: code `[0x005196a6,0x005196ac)`; address-item name: absent; address-item type: absent; address-item `AR`: absent; address-item `AP`: absent; address-item `FR`: not applicable; address-item `FP`: not applicable; containing-function name: `TextMenuItemList__SendSelectedTextMenuReply`; containing-function type: `void __thiscall TextMenuItemList__SendSelectedTextMenuReply(TextMenuItemList *this)`; containing-function frame row 1: `var_100 +0x0c/4 _DWORD`; row 2: `var_FC +0x10/4 _DWORD`; row 3: `__saved_registers +0x10c/4 _DWORD`; row 4: `__return_address +0x110/4 _UNKNOWN *`; containing-function frame exclusions: no additional locals, no explicit arguments, no physical `this`, and no other rows; containing-function `AR`: absent; containing-function `AP`: absent; containing-function `FR`: `Retained TextMenuItemList::SendSelectedTextMenuReply() helper; its complete selected-row opcode 0x39 body is compiler-inlined into TextMenuDialog::OnDialogAction at 0x0051938f-0x00519492. No current direct route reaches this retained copy.`; containing-function `FP`: absent | set only address-item `AR` to `Load non-owning m_ownerDialog at +0x154; owner +0x279 gates ANSI length-8 m_extraString at +0x27c.` | direct field/helper sequence; containing-function range/type/four-row frame/channels/hash/xrefs must match before and after | address item kind: code; address item head: `0x005196a6`; address item range: `[0x005196a6,0x005196ac)`; address-item name: absent; address-item type: absent; address-item `AR`: `Load non-owning m_ownerDialog at +0x154; owner +0x279 gates ANSI length-8 m_extraString at +0x27c.`; address-item `AP`: absent; address-item `FR`: not applicable; address-item `FP`: not applicable; containing-function name: `TextMenuItemList__SendSelectedTextMenuReply`; containing-function type: `void __thiscall TextMenuItemList__SendSelectedTextMenuReply(TextMenuItemList *this)`; containing-function frame row 1: `var_100 +0x0c/4 _DWORD`; row 2: `var_FC +0x10/4 _DWORD`; row 3: `__saved_registers +0x10c/4 _DWORD`; row 4: `__return_address +0x110/4 _UNKNOWN *`; containing-function frame exclusions: no additional locals, no explicit arguments, no physical `this`, and no other rows; containing-function frame delta from I06: added `0`, removed `0`, replaced `0`; containing-function `AR`: absent; containing-function `AP`: absent; containing-function `FR`: `Retained TextMenuItemList::SendSelectedTextMenuReply() helper; its complete selected-row opcode 0x39 body is compiler-inlined into TextMenuDialog::OnDialogAction at 0x0051938f-0x00519492. No current direct route reaches this retained copy.`; containing-function `FP`: absent; containing-function range: `[0x005195f0,0x0051971d)`; containing-function body SHA256: `94B5D776499D730276233ECDDBD03FCAC7CD73258CF8B0FEC82868A2EDD16C8A`; containing-function start inbound xref count: `0`, exact set `{}`; containing-function external inbound instruction-head xref count: `0`, exact set `{}`; containing-function vtable target-cell count: `0`, exact set `{}` |
| I08 | apply | `set_address_comments` | address `0x005196f5` regular comment | address item: code `[0x005196f5,0x005196fd)`; address-item name: absent; address-item type: absent; address-item `AR`: absent; address-item `AP`: absent; address-item `FR`: not applicable; address-item `FP`: not applicable; containing-function name: `TextMenuItemList__SendSelectedTextMenuReply`; containing-function type: `void __thiscall TextMenuItemList__SendSelectedTextMenuReply(TextMenuItemList *this)`; containing-function frame row 1: `var_100 +0x0c/4 _DWORD`; row 2: `var_FC +0x10/4 _DWORD`; row 3: `__saved_registers +0x10c/4 _DWORD`; row 4: `__return_address +0x110/4 _UNKNOWN *`; containing-function frame exclusions: no additional locals, no explicit arguments, no physical `this`, and no other rows; containing-function `AR`: absent; containing-function `AP`: absent; containing-function `FR`: `Retained TextMenuItemList::SendSelectedTextMenuReply() helper; its complete selected-row opcode 0x39 body is compiler-inlined into TextMenuDialog::OnDialogAction at 0x0051938f-0x00519492. No current direct route reaches this retained copy.`; containing-function `FP`: absent | set only address-item `AR` to `After checked cursor < 0x100, write a local trailing zero; QueueAndSendPacket receives the pre-terminator cursor length.` | direct guard/write/send semantics; containing-function range/type/four-row frame/channels/hash/xrefs must match before and after | address item kind: code; address item head: `0x005196f5`; address item range: `[0x005196f5,0x005196fd)`; address-item name: absent; address-item type: absent; address-item `AR`: `After checked cursor < 0x100, write a local trailing zero; QueueAndSendPacket receives the pre-terminator cursor length.`; address-item `AP`: absent; address-item `FR`: not applicable; address-item `FP`: not applicable; containing-function name: `TextMenuItemList__SendSelectedTextMenuReply`; containing-function type: `void __thiscall TextMenuItemList__SendSelectedTextMenuReply(TextMenuItemList *this)`; containing-function frame row 1: `var_100 +0x0c/4 _DWORD`; row 2: `var_FC +0x10/4 _DWORD`; row 3: `__saved_registers +0x10c/4 _DWORD`; row 4: `__return_address +0x110/4 _UNKNOWN *`; containing-function frame exclusions: no additional locals, no explicit arguments, no physical `this`, and no other rows; containing-function frame delta from I07: added `0`, removed `0`, replaced `0`; containing-function `AR`: absent; containing-function `AP`: absent; containing-function `FR`: `Retained TextMenuItemList::SendSelectedTextMenuReply() helper; its complete selected-row opcode 0x39 body is compiler-inlined into TextMenuDialog::OnDialogAction at 0x0051938f-0x00519492. No current direct route reaches this retained copy.`; containing-function `FP`: absent; containing-function range: `[0x005195f0,0x0051971d)`; containing-function body SHA256: `94B5D776499D730276233ECDDBD03FCAC7CD73258CF8B0FEC82868A2EDD16C8A`; containing-function start inbound xref count: `0`, exact set `{}`; containing-function external inbound instruction-head xref count: `0`, exact set `{}`; containing-function vtable target-cell count: `0`, exact set `{}` |
| I09 | apply | `set_address_comments` | address `0x0051938f` regular comment inside UID0004HC | address item: code `[0x0051938f,0x00519395)`; address-item name: absent; address-item type: absent; address-item `AR`: absent; address-item `AP`: absent; address-item `FR`: not applicable; address-item `FP`: not applicable; containing-function name: `sub_519210`; containing-function type: `void __userpurge(int@<ecx>, int@<ebx>, int, int)`; containing-function `AR`: absent; containing-function `AP`: absent; containing-function `FR`: absent; containing-function `FP`: absent; prior UID0004HE dependency frame row 1: `var_100 +0x0c/4 _DWORD`; row 2: `var_FC +0x10/4 _DWORD`; row 3: `__saved_registers +0x10c/4 _DWORD`; row 4: `__return_address +0x110/4 _UNKNOWN *`; dependency frame exclusions: no additional locals, no explicit arguments, no physical `this`, and no other rows | set only address-item `AR` to `Compiler-inlined TextMenuItemList::SendSelectedTextMenuReply() expansion: selected-index lookup and opcode 0x39 send; retained out-of-line body is 0x005195f0-0x0051971d.` | comment only; do not rename/retype the UID0004HC containing function; stop if the prior UID0004HE four-row dependency frame or any containing-function/address-item field differs | address item kind: code; address item head: `0x0051938f`; address item range: `[0x0051938f,0x00519395)`; address-item name: absent; address-item type: absent; address-item `AR`: `Compiler-inlined TextMenuItemList::SendSelectedTextMenuReply() expansion: selected-index lookup and opcode 0x39 send; retained out-of-line body is 0x005195f0-0x0051971d.`; address-item `AP`: absent; address-item `FR`: not applicable; address-item `FP`: not applicable; containing-function name: `sub_519210`; containing-function type: `void __userpurge(int@<ecx>, int@<ebx>, int, int)`; containing-function `AR`: absent; containing-function `AP`: absent; containing-function `FR`: absent; containing-function `FP`: absent; containing-function range: `[0x00519210,0x005194b1)`; containing-function body SHA256: `5A392B4E39A6AB238D3B14D9761719AA7D100BF6549FDFE197F3D40B8796F860`; containing-function inbound xref count: `1`, exact set `{0x0061ecf4 data -> 0x00519210}`; containing-function vtable-route count: `1`, exact set `{0x0061ecf4 -> 0x00519210}`; UID0004HE dependency frame row 1: `var_100 +0x0c/4 _DWORD`; row 2: `var_FC +0x10/4 _DWORD`; row 3: `__saved_registers +0x10c/4 _DWORD`; row 4: `__return_address +0x110/4 _UNKNOWN *`; dependency frame exclusions: no additional locals, no explicit arguments, no physical `this`, and no other rows; dependency frame delta from I08: added `0`, removed `0`, replaced `0` |
| P01 | no change recommended | none | target bytes/bounds/padding/xrefs | leading padding range: `[0x005195e8,0x005195f0)`; leading padding SHA256: `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3`; target range: `[0x005195f0,0x0051971d)`; target body SHA256: `94B5D776499D730276233ECDDBD03FCAC7CD73258CF8B0FEC82868A2EDD16C8A`; trailing padding range: `[0x0051971d,0x00519720)`; trailing padding SHA256: `E668F0A1B72560CED14C54488A25335D11336448950BB6485267EBC5EB3FECEE`; target-start inbound xref count: `0`, exact set `{}`; all-80-instruction-head external inbound xref union: count `0`, exact set `{}`; code-reference set: `{}`; data-reference set: `{}`; immediate-reference set: `{}`; VA pointer-pattern set: `{}`; RVA pointer-pattern set: `{}`; raw-offset pointer-pattern set: `{}`; TextMenuItemList vtable target-cell set: `{}` | preserve each independently stated field exactly | function metadata only; no byte, code-definition, padding, or xref alteration beyond I01-I08 | leading range: `[0x005195e8,0x005195f0)`; leading SHA256: `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3`; target range: `[0x005195f0,0x0051971d)`; target SHA256: `94B5D776499D730276233ECDDBD03FCAC7CD73258CF8B0FEC82868A2EDD16C8A`; trailing range: `[0x0051971d,0x00519720)`; trailing SHA256: `E668F0A1B72560CED14C54488A25335D11336448950BB6485267EBC5EB3FECEE`; target-start inbound xref count: `0`, exact set `{}`; all-80-instruction-head external inbound xref count: `0`, exact set `{}`; code-reference set: `{}`; data-reference set: `{}`; immediate-reference set: `{}`; VA pointer-pattern set: `{}`; RVA pointer-pattern set: `{}`; raw-offset pointer-pattern set: `{}`; TextMenuItemList vtable target-cell set: `{}` |
| P02 | no change recommended | none | sibling `[0x00519720,0x0051983a)` | function: absent; entry name: absent; entry type: absent; entry `AR`: absent; entry `AP`: absent; entry `FR`: not applicable because no function exists; entry `FP`: not applicable because no function exists; body hash: `CB928A0115A74BA12B714758CA0A23D6D26C83C7480E418894371E8746C4C65A`; trailing six-byte padding hash: `33CC4A00A0F04735602819132DA3E3FAC4CDEB8EC7AEE92551DC79BA8488E722` | preserve exactly | sibling needs independent report; do not define/name/type/comment it here | function: absent; entry name: absent; entry type: absent; entry `AR`: absent; entry `AP`: absent; entry `FR`: not applicable; entry `FP`: not applicable; body SHA256: `CB928A0115A74BA12B714758CA0A23D6D26C83C7480E418894371E8746C4C65A`; trailing six-byte padding SHA256: `33CC4A00A0F04735602819132DA3E3FAC4CDEB8EC7AEE92551DC79BA8488E722` |
| P03 | no change recommended | none | UID0004HC function `0x00519210` and vtable cell `0x0061ecf4` | function name: `sub_519210`; function type: `void __userpurge(int@<ecx>, int@<ebx>, int, int)`; function range: `[0x00519210,0x005194b1)`; function body SHA256: `5A392B4E39A6AB238D3B14D9761719AA7D100BF6549FDFE197F3D40B8796F860`; function inbound xref count: `1`, exact set `{0x0061ecf4 data -> 0x00519210}`; function `AR`: absent; function `AP`: absent; function `FR`: absent; function `FP`: absent; cell item: data `[0x0061ecf4,0x0061ecf8)`; cell bytes: `10 92 51 00`; cell name: absent; cell type: absent; cell value: `0x00519210`; cell outgoing xref count: `1`, exact set `{0x0061ecf4 data -> 0x00519210}`; cell `AR`: absent; cell `AP`: absent; cell `FR`: not applicable because the cell is data; cell `FP`: not applicable because the cell is data | preserve every independently stated function and cell field; I09 independently owns the sole address-item `AR` change at `0x0051938f` | target report does not own handler typing or vtable metadata; this protection row authorizes no action | function name: `sub_519210`; function type: `void __userpurge(int@<ecx>, int@<ebx>, int, int)`; function range: `[0x00519210,0x005194b1)`; function body SHA256: `5A392B4E39A6AB238D3B14D9761719AA7D100BF6549FDFE197F3D40B8796F860`; function inbound xref count: `1`, exact set `{0x0061ecf4 data -> 0x00519210}`; function `AR`: absent; function `AP`: absent; function `FR`: absent; function `FP`: absent; cell item: data `[0x0061ecf4,0x0061ecf8)`; cell bytes: `10 92 51 00`; cell name: absent; cell type: absent; cell value: `0x00519210`; cell outgoing xref count: `1`, exact set `{0x0061ecf4 data -> 0x00519210}`; cell `AR`: absent; cell `AP`: absent; cell `FR`: not applicable; cell `FP`: not applicable; address-item `AR` at `0x0051938f`: exact I09 proposed text |
| P04 | no change recommended | none | TextMenuItemList vtable and `g_packetSender` | every prestate is enumerated independently in the literal P04 address-indexed pre/post map below | preserve every mapped field exactly | target/sibling are nonvirtual; sender identity already source-quality; P04 authorizes no action | every poststate must equal the corresponding literal `post` row in the P04 map below |

Literal deterministic P04 address-indexed pre/post map. In the sender `AR` field, the two characters `\n` represent exactly one LF separator in the IDA comment and are not literal IDA comment characters.

| Address | State | Item kind and exact range | Bytes | Name | Type | Value | `AR` | `AP` | `FR` | `FP` |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| `0x0061ed48` | pre | data `[0x0061ed48,0x0061ed4c)` | `f0 0d 52 00` | `??_7TextMenuItemList@@6B@` | absent | `0x00520df0` | absent | absent | not applicable | not applicable |
| `0x0061ed48` | post | data `[0x0061ed48,0x0061ed4c)` | `f0 0d 52 00` | `??_7TextMenuItemList@@6B@` | absent | `0x00520df0` | absent | absent | not applicable | not applicable |
| `0x0061edc4` | pre | data `[0x0061edc4,0x0061edc8)` | `40 98 51 00` | absent | absent | `0x00519840` | absent | absent | not applicable | not applicable |
| `0x0061edc4` | post | data `[0x0061edc4,0x0061edc8)` | `40 98 51 00` | absent | absent | `0x00519840` | absent | absent | not applicable | not applicable |
| `0x0061edc8` | pre | data `[0x0061edc8,0x0061edcc)` | `50 98 51 00` | absent | absent | `0x00519850` | absent | absent | not applicable | not applicable |
| `0x0061edc8` | post | data `[0x0061edc8,0x0061edcc)` | `50 98 51 00` | absent | absent | `0x00519850` | absent | absent | not applicable | not applicable |
| `0x0067a7ec` | pre | data `[0x0067a7ec,0x0067a7f0)` | `00 00 00 00` | `g_packetSender` | `Socket *` | `0x00000000` | `Active packet-sender Socket singleton used by UserPane.cpp retained packet helpers.\nCanonical Socket *g_packetSender singleton used by packet serializer methods.` | absent | not applicable | not applicable |
| `0x0067a7ec` | post | data `[0x0067a7ec,0x0067a7f0)` | `00 00 00 00` | `g_packetSender` | `Socket *` | `0x00000000` | `Active packet-sender Socket singleton used by UserPane.cpp retained packet helpers.\nCanonical Socket *g_packetSender singleton used by packet serializer methods.` | absent | not applicable | not applicable |

Literal deterministic I01 state immediately after public `define_func` and before I03-I05:

| Field | Required intermediate state |
| --- | --- |
| Function item | exactly one function `[0x005195f0,0x0051971d)`, size `0x12d`; predecessor/successor padding remains outside the function |
| Generated name | exactly `sub_5195F0` |
| Persisted/item type | `inspect_items` type field is empty/absent |
| Analysis prototype | `analyze_function` returns `prototype:null` |
| Decompiler presentation | exactly `void __thiscall sub_5195F0(int *this)`; this inferred presentation is not a persisted item type and does not replace I04's explicit final type action |
| Complete physical frame row 1 | `var_100`, offset `+0x0c`, size `0x04`, type `_DWORD` |
| Complete physical frame row 2 | `var_FC`, offset `+0x10`, size `0x04`, type `_DWORD` |
| Complete physical frame row 3 | `__saved_registers`, offset `+0x10c`, size `0x04`, type `_DWORD` |
| Complete physical frame row 4 | `__return_address`, offset `+0x110`, size `0x04`, type `_UNKNOWN *` |
| Complete frame exclusions | no additional local rows, no explicit argument rows, no physical `this` row, and no other rows |
| Comment channels | `AR` absent; `AP` absent; `FR` absent; `FP` absent |
| Frame delta from no-function prestate | added rows `4`; removed rows `0`; replaced rows `0` |
| Body SHA256 | `94B5D776499D730276233ECDDBD03FCAC7CD73258CF8B0FEC82868A2EDD16C8A` |
| Start inbound xrefs | count `0`; exact set `{}` |
| External inbound xrefs to all 80 instruction heads | count `0`; exact set `{}` |
| Proposed-name collision state | lookup for `TextMenuItemList__SendSelectedTextMenuReply` returns `Not found` |
| Protected state | every independently enumerated P01 leading/target/trailing range, SHA256, xref count/set, pointer-pattern set, and vtable target-cell set above must match exactly; no item outside `[0x005195f0,0x0051971d)` may change grouping or bytes |

Dated failed Gate 2B test and rollback (`2026-08-14`; supervisor-reported historical evidence, not current authority): a canonical worker applied I01 `define_func` only for `[0x005195f0,0x0051971d)`. Its then-observed `stack_frame` response exposed `__saved_registers` at `+0x10c`, size `0x04`, type `_DWORD`, and `__return_address` at `+0x110`, size `0x04`, type `_UNKNOWN *`. The mismatch against the former report expectation triggered fail-closed handling before I02-I09; no later action ran and no IDB save occurred. The unsaved worker was discarded. Canonical reopen restored the literal I01 prestate. This earlier observation is retained as dated history but is superseded for current action-time expectations by the later canonical four-row reproduction below.

Dated failed Gate 2B retest and rollback (`2026-08-15`; supervisor-reported historical evidence, not current authority): a freshly opened unsaved worker applied public I01 `define_func` only for `[0x005195f0,0x0051971d)`. Function range, name `sub_5195F0`, size `0x12d`, and the two then-observed nonlocal frame rows matched. `inspect_items` returned an empty persisted type, `analyze_function` returned `prototype:null`, and the decompiler declaration was exactly `void __thiscall sub_5195F0(int *this)`. That deterministic mismatch against the former incorrect persisted/inferred receiver-type requirement triggered fail-closed handling before I02-I09; no later action or IDB save ran. The worker was discarded and canonical rollback was verified. This retest remains evidence for the persisted-type/prototype/decompiler split, but its partial frame observation is superseded for current action-time expectations by the complete four-row reproduction below.

Dated current-contract Gate 2B test and rollback (`2026-08-15`; supervisor-reported historical evidence, not current authority): unsaved session `supervisor-uid0003D7-rollback-20260815` applied only public I01 `define_func` for `[0x005195f0,0x0051971d)`. Name `sub_5195F0`, size `0x12d`, empty persisted `inspect_items` type, `analyze_function` prototype `null`, decompiler declaration `void __thiscall sub_5195F0(int *this)`, and absent comments matched. Canonical `stack_frame` returned exactly four rows in order: `var_100 +0x0c/4 _DWORD`; `var_FC +0x10/4 _DWORD`; `__saved_registers +0x10c/4 _DWORD`; `__return_address +0x110/4 _UNKNOWN *`. The extra two local rows contradicted the former partial frame contract, so the supervisor stopped before I02-I09; no rename, type, comment, later action, or IDB save ran. The worker was discarded. Fresh canonical session `supervisor-uid0004HE-rollback-20260815` restored `Not a function`, absent destination name/type/comments, and unchanged disk SHA256 `B16863A05EA9E22E4911EC228FE7BD0C25D6DBE1639E791A400D0E311CFA143B`, verifying full rollback. This latest reproduction is the current action-time frame authority encoded in I01 and I03-I09.

Dependency/readback order: I01 `define_func` -> immediate full intermediate-state readback -> I02 `declare_type` -> I03 `rename` with `pure:true` -> I04 `set_type` -> I05 `set_function_comments` -> I06-I09 `set_address_comments` -> P01-P04 verification. If any I01 range, generated name, persisted/item type, analysis prototype, decompiler declaration, complete frame row/name/offset/size/type, added/removed/replaced count, AR/AP/FR/FP channel, hash, xref, or boundary differs from the literal table, stop before I02-I09; do not discover or adapt a different state inside Gate 2B. Any later range/hash/name/persisted-type/prototype/decompiler/frame/comment drift, collision, overlap, unexpected stack parameter, or protected-state change likewise stops all later actions. Do not apply a full TextMenuItemList UDT, local-variable renames, sibling metadata, vtable changes, packet-helper renames, or any save operation under B005 authority.

## First-Draft C++ Recommendation

- Eligible: yes. Owner, range, ABI, behavior, source placement, and active source liveness are resolved.
- Applied target CPP disposition: blank target CPP was replaced with this exact formal insertion text:

```cpp
void TextMenuItemList::SendSelectedTextMenuReply()
{
    if (m_selectedIndex < 0)
        return;

    const TextMenuItemListEntry *entry =
        static_cast<const TextMenuItemListEntry *>(GetItem(m_selectedIndex));

    unsigned char packet[0x100];
    int cursor = 0;

    PacketBufferAppendUInt8(0x39, packet, &cursor);
    PacketBufferAppendUInt8(m_menuType, packet, &cursor);
    PacketBufferAppendUInt32BE(m_menuId, packet, &cursor);
    PacketBufferAppendUInt16BE(entry->itemId, packet, &cursor);

    if (m_ownerDialog->m_hasExtraString) {
        PacketBufferAppendAnsiString8(
            m_ownerDialog->m_extraString.c_str(),
            packet,
            &cursor);
    }

    packet[cursor] = 0;
    QueueAndSendPacket(g_packetSender,
                       packet,
                       static_cast<short>(cursor));
}
```

- Applied target H disposition: remains blank. UID0004HE owns the definition; UID0000ET's file-local class declaration owns the declaration.
- Applied UID0000ET formal CPP class-declaration insertion, in the public method list after `AddTextEntry`:

```cpp
    void SendSelectedTextMenuReply();
```

- Applied UID0000ES formal H insertion, in `TextMenuDialog`'s private section before private methods/fields:

```h
    friend class TextMenuItemList;
```

- Applied UID0004HC exact formal CPP replacement:

```cpp
void TextMenuDialog::OnDialogAction(int controlId, unsigned int actionId)
{
    if (m_itemCount <= 6 && !g_useHighResolutionTextMenuLayout) {
        if (actionId == 0) {
            SendMenuRequestPacket();
            return;
        }

        if (actionId == 1)
            return;

        if (actionId < 4)
            return;

        SendMenuReply(static_cast<unsigned short>(actionId - 4));
        Close();
        return;
    }

    if (actionId == 1) {
        TextMenuItemList *list =
            static_cast<TextMenuItemList *>(GetControlById(6));
        list->SendSelectedTextMenuReply();
        Close();
        return;
    }

    if (actionId == 2) {
        SendMenuRequestPacket();
        return;
    }

    if (actionId == 3)
        Close();
}
```

- Behavior preservation: negative selection returns from the helper but UID0004HC still closes; valid selection serializes the same fields and optional text, writes the same non-sent zero, and sends the same cursor length.
- Human-source shape: uses class fields, typed row data, established PacketBuffer cursor helpers, normal method calls, and no IDA/compiler labels. It resembles maintainable MSVC-era C++03 rather than a literal disassembly transcription.
- Compiler exclusions: security-cookie code, range-failure call, raw `sub_` names, explicit stack offsets, and the unused `GetMemoryMan` return are documented but not written as developer source.
- Source-factoring caveat: a no-argument wrapper calling the explicit-id sibling is plausible, but no surviving call proves it. The self-contained formal body is chosen because it is exact, compilable, and does not depend on unapproved UID0004HF emission.
- Third-party import: not applicable; this is first-party NexusTK UI/network code.

## Final Recommendation

- Retain the applied promotion of only UID0004HE from blank empty emitter to source-emitting retained class method at `93/94`.
- Keep owner/emitter UID0000ET, reconstructable true, and the exact target range.
- Retain the applied exact target CPP, UID0000ET declaration, UID0000ES friend line, and UID0004HC caller replacement.
- Keep the applied UID0000ET `91/91` and UID0004HC `91/93`; keep UID0001BN `90/92`, UID0000OP `90/86`, UID0000ES `86/86`, and UID0004HF `86/91`.
- Preserve no-route evidence as historical/negative evidence while replacing the false implication that it prohibits source emission.
- I01-I09 application and P01-P04 verification are supervisor-only Gate 2B recommendations governed by the applicable exact-artifact prerequisites; this recommendation makes no assertion about current Gate 2B status.
- Future work outside this target: UID0004HF deserves its own full target-specific report; no UID0004HF change is prerequisite for UID0004HE's self-contained code.

## Recommended Target Doc Changes

- Path: `by-memory/0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer.md`.
- Applied metadata: `86/91 -> 93/94`; owner remains `0000ET`; reconstructable remains true; emitter blank -> `0000ET`; Nested remains 0; H remains blank; CPP is the exact Section 22 target body.
- Applied retained-source classification, exact owner/emitter/file route, ABI, behavior, packet semantics, inline-expansion liveness, range/padding hashes, source rationale, negative evidence, and historical supersession.
- Applied `GetSelectedEntry` -> `GetItem(m_selectedIndex)` correction.
- Preserved historical B009 split creation and the valid zero-route result, explicitly marking only the blank-emitter inference as superseded.
- Item Summary now describes the retained selected-row opcode `0x39` method and inline counterpart without duplicating metadata.

## Recommended Support Doc Changes

- `by-class/TextMenuItemList.md` UID0000ET: public declaration, exact behavior/inline route/ABI/negative evidence, method map, raw-helper distinction, historical correction, and `89/88 -> 91/91` are applied.
- `by-class/TextMenuDialog.md` UID0000ES: `friend class TextMenuItemList;` and direct-field-access rationale are applied; score remains `86/86`.
- `by-memory/0x00519210-0x005194b1.TextMenuDialogOnDialogAction.md` UID0004HC: exact Section 22 body, method call, compiler-inline relation, and `90/92 -> 91/93` are applied.
- `by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md` UID0001BN: inventory/reclassification/history are applied; aggregate remains `90/92` and UID0004HF remains separately unresolved.
- `by-file/TextMenuDialogs.md` UID0000OP: TextMenuItemList inventory, source order, generated expectations, and history are applied; score remains `90/86`.
- `by-memory/0x00519720-0x0051983a.TextMenuItemListRawExplicitIdReplySerializer.md` UID0004HF: no ordinary edit required by this report; keep exact current metadata/code until its own review.
- PacketBuffer/ListPane/Socket support docs: no edits required; current source-facing API/type evidence is sufficient and should be cited, not duplicated or rescored.

## Score And Metadata Recommendation

- UID0004HE pre-callback: `86/91`, owner `0000ET`, reconstructable true, blank emitter, blank CPP/H.
- UID0004HE current applied state: `93/94`, owner `0000ET`, reconstructable true, emitter `0000ET`, exact CPP, blank H, Nested 0.
- Completion gain: exact method source, emitter route, class declaration, caller repair, support incorporation, coverage text, and IDA handoff remove the former blank/no-route/source-form gaps.
- Confidence gain: exact live inline expansion, exact sibling/body comparison, exhaustive negative route audit, range hashes, ABI, helper types, owner layout, and source placement independently agree.
- Reason not higher: no original symbol proves the lexical name; exact pre-optimization factoring among the target, UID0004HF, and dialog helper is lost; access-control spelling is inferred; the retained body has no surviving direct/all-head xref, pointer, relocation-like, or vtable route; and no direct source archive resolves the remaining lexical/binary uncertainty.
- Reason not lower: runtime behavior, field offsets, protocol order, list-row role, active source liveness, class/file ownership, and full source body are direct or multiply corroborated.
- UID0000ET applied `89/88 -> 91/91`; one of two raw serializer blockers is resolved, but UID0004HF and unrelated GrafPort lexical uncertainty remain.
- UID0004HC applied `90/92 -> 91/93`; the source branch now matches the recovered class method and removes stale private-field/accessor pollution.
- UID0001BN remains `90/92`; UID0000OP remains `90/86`; UID0000ES remains `86/86`; UID0004HF remains `86/91`.

Score-blocker audit:

| Former blocker | Concrete research | Result |
| --- | --- | --- |
| no direct caller | all-head xrefs, pointer patterns, vtables, active handler | direct route remains absent; complete active inline expansion resolves source liveness |
| no function object | item/boundary/disassembly/hash audit | exact safe function bounds and ABI established |
| blank source form | target/sibling/inline comparison and support APIs | exact compilable human CPP supplied |
| source name | class vocabulary and role comparison | best descriptive `SendSelectedTextMenuReply` selected |
| ownership/emitter | receiver layout, physical file, class/file docs | UID0000ET owner/emitter and UID0000OP file resolved |
| private owner fields | direct loads versus accessor-call search | narrow friend declaration selected |
| stale ListPane helper | live type and current ListPane docs | `GetItem(m_selectedIndex)` resolved |
| sibling dependency | compared exact sibling ABI/body | self-contained target avoids unresolved sibling emission |

## Open Questions With Attempted Resolution

- Original method spelling: no symbol survives. Existing UID0000ET already proposed `SendSelectedTextMenuReply`; behavior and project naming support it. Adopt it as descriptive, medium-high confidence.
- Did the source call UID0004HF or a TextMenuDialog serializer helper? Target/sibling/inline code is compatible with aggressive inlining, but no surviving call distinguishes factoring. Adopt a self-contained target body because it preserves runtime behavior and compiles without promoting an unassigned sibling.
- Friend versus getter API: direct owner-field loads survive and no getter call survives. Adopt `friend class TextMenuItemList` as the least-invented C++03 source relation.
- `GetMemoryMan` source expression: live call returns a global pointer that is immediately discarded. It may be optimization residue from an inlined helper; omitting the unused read preserves observable runtime behavior and matches established human-source policy.
- Exact local names: `packet`, `cursor`, and `entry` are descriptive project-consistent names. Raw stack names are rejected.
- Remaining unresolved questions: none that block behavior, code, owner, emitter, range, source placement, callback, or the declarative IDA handoff. I01 and I03-I08 independently enumerate the complete four-row action-time frame, including `var_100` and `var_FC`; I09 independently preserves that prior UID0004HE dependency frame while keeping its UID0004HC address-item and containing-function channels separate. I03-I05 also enumerate the literal range, name, persisted/item type, analysis prototype, decompiler declaration, four comment channels, body hash, xref sets, action, poststate, and fail-closed readback conditions, and I04 keeps the exact final `TextMenuItemList *this` type action separate from its I02/I03 dependency prestate. Lost lexical/factoring proof is bounded in score rather than deferred as investigation.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Inspected `by-memory/-coverage-report.md`: UID0004HE is absent; UID0001BN is stale at 86%; UID0004HB is the preceding exact child row.
- Inspected `by-class/-coverage-report.md`: UID0000ET is stale at 84% and does not describe the selected-row source method.
- Inspected `by-file/-coverage-report.md`: UID0000OP is present at 90%; no replacement is required by this target.
- Do not manually edit validator-owned auto-generated tracker/coverage files.

Insert after the UID0004HB row in `by-memory/-coverage-report.md`:

`    - [UID:0004HE][0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer](by-memory/0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer.md) 0x005195f0-0x0051971d | retained raw class helper | TextMenuItemListRawSelectedRowReplySerializer : reconstructable : 93% : very-strong : Source-ready retained TextMenuItemList SendSelectedTextMenuReply() method with exact padded body, selected-index/GetItem row lookup, opcode 0x39 reply field order, optional owner ANSI text, cursor guard, non-sent terminator, exhaustive no-route history, live compiler-inlined OnDialogAction counterpart, class owner/emitter UID0000ET, and complete formal C++.`

Replace the current UID0001BN row in `by-memory/-coverage-report.md` with:

`    - [UID:0001BN][0x00517ec0-0x0051a417.TextMenuDialogs](by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md) 0x00517ec0-0x0051a417 | class-method/raw-helper aggregate | TextMenuDialogs : reconstructable : 90% : very-strong : Text-menu dialog aggregate with exact request/constructor/paint/action/update children, source-emitting retained TextMenuDialog and TextMenuItemList selected-row opcode 0x39 serializers, separate unresolved TextMenuItemList explicit-id sibling, TextInputMenuDialog methods, factory callers, vtable-family evidence, source order, and adjacent text-input reply helper documented.`

Replace the current UID0000ET row in `by-class/-coverage-report.md` with:

`- [UID:0000ET][TextMenuItemList](by-class/TextMenuItemList.md) : reconstructable : 91% : very-strong : Private TextMenuDialogs.cpp list class with exact 0x202 row layout, constructor/add/forward/draw methods, recovered retained SendSelectedTextMenuReply source method and OnDialogAction inline route, three-view vtable/destructor policy, owner context fields, formal C++, and independently unresolved explicit-id serializer sibling documented.`

Reason B005 must not apply these rows: every manual `-coverage-report.md` is supervisor-owned collision-sensitive state. Only the supervisor may apply and validate them, and only when the applicable exact-artifact gates authorize that action; this is a role/prerequisite boundary rather than a current status assertion.

## Follow-Up Actions

- Dated ordinary implementation record: B005 applied the accepted changes to UID0004HE, UID0000ET, UID0000ES, UID0004HC, UID0001BN, and UID0000OP, ran the scoped validators recorded below, and released all six leases.
- Exact-artifact audit prerequisite: any supervisor action that depends on Gate 1 requires a passing audit for the exact artifact revision before that action; this report does not assert whether such an audit currently exists.
- IDA authority boundary: B005 never owns I01-I09 application, P01-P04 verification, persistence, or readback. The supervisor may perform those actions only under applicable exact-artifact gates and fail-closed prestate checks, including exact preservation of all four UID0004HE frame rows through every dependent action.
- Manual-coverage authority boundary: B005 never owns the collision-sensitive coverage rows. The supervisor may apply and validate the exact supplied text only under applicable exact-artifact gates.
- Dated generated readback: command `000000023733` produced the CPP/H snapshot recorded in Validator Results. If any newer command exists when generated truth matters, the supervisor must use the physical headers and metadata from that newer state.
- Lifecycle authority boundary: B005 never owns validator `execute_report` or archive movement. The supervisor/validator may perform lifecycle actions only after every applicable exact-artifact report, implementation, IDA, coverage, and readback gate passes; this report does not assert current lifecycle state.
- Future B-agent work: give UID0004HF its own target-specific report; it is not a blocker for this self-contained UID0004HE result.
- A-agent actions: none.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: high for 93/94 target and medium-high for support score increments.
- Exact facts at high confidence: boundaries, hashes, ABI, selected-index path, row layout, packet protocol, optional string, guard/terminator/send, zero direct routes, sibling shape, inline expansion, vtable route, owner/file placement.
- Inferred at medium-high confidence: method lexical spelling, friend relation, and self-contained pre-optimization body factoring.
- Remaining uncertainty is lexical/structural only and does not require raw labels, blank code, blank emitter, or deferred investigation.

## Validator Results

- Validator cwd for every scoped callback command: `E:\NTK\GhidraBridge\source-3\project-documentation` (validator reports canonical root `C:\FastStorage\NTK_Sources\source-3\project-documentation`).

| Relative file | Exact inline command | Command ID | Command timestamp | Exit / ok | Warnings | Side effects |
| --- | --- | --- | --- | --- | --- | --- |
| `by-memory\0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer.md` | `python .\tools\validator.py --mode file --file 'by-memory\0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer.md' --apply --queue-timeout 240` | `000000023659` | `2026-08-14T19:11:28-04:00` | `0 / 1` | none | metadata/emitter/source registry, UID links/references, projected stats; generated refresh deferred |
| `by-class\TextMenuItemList.md` | `python .\tools\validator.py --mode file --file 'by-class\TextMenuItemList.md' --apply --queue-timeout 240` | `000000023660` | `2026-08-14T19:12:51-04:00` | `0 / 1` | two existing `missing_ref_uid 0003KO` notices | score/source registry, UID link/reference, projected stats; generated refresh deferred |
| `by-class\TextMenuDialog.md` | `python .\tools\validator.py --mode file --file 'by-class\TextMenuDialog.md' --apply --queue-timeout 240` | `000000023661` | `2026-08-14T19:13:30-04:00` | `0 / 1` | eight existing `missing_ref_uid 00037E/00037F` notices | source registry/stats rows/projected stats; generated refresh deferred |
| `by-memory\0x00519210-0x005194b1.TextMenuDialogOnDialogAction.md` | `python .\tools\validator.py --mode file --file 'by-memory\0x00519210-0x005194b1.TextMenuDialogOnDialogAction.md' --apply --queue-timeout 240` | `000000023662` | `2026-08-14T19:14:24-04:00` | `0 / 1` | none | score/source registry, UID link/reference, projected stats; generated refresh deferred |
| `by-memory\0x00517ec0-0x0051a417.TextMenuDialogs.md` | `python .\tools\validator.py --mode file --file 'by-memory\0x00517ec0-0x0051a417.TextMenuDialogs.md' --apply --queue-timeout 240` | `000000023663` | `2026-08-14T19:15:42-04:00` | `0 / 1` | five existing missing-reference notices: `0003KO`, `00037C`, `00037D`, `0003YO` | reference-index maintenance/projected stats; generated refresh deferred |
| `by-file\TextMenuDialogs.md` | `python .\tools\validator.py --mode file --file 'by-file\TextMenuDialogs.md' --apply --queue-timeout 240` | `000000023664` | `2026-08-14T19:17:16-04:00` | `0 / 1` | eight existing missing-reference notices: `0003IP`, `00037E`, `00037F`, `00037D`, `00037C` | projected stats; generated refresh deferred and then completed |
| `by-class\TextMenuItemList.md` | `python .\tools\validator.py --mode file --file 'by-class\TextMenuItemList.md' --apply --queue-timeout 240` | `000000023732` | `2026-08-14T20:48:49-04:00` | `0 / 1` | two existing `missing_ref_uid 0003KO` notices | Gate 2A repair registry/source-order update and projected stats; generated refresh deferred |
| `by-file\TextMenuDialogs.md` | `python .\tools\validator.py --mode file --file 'by-file\TextMenuDialogs.md' --apply --queue-timeout 240` | `000000023733` | `2026-08-14T20:48:54-04:00` | `0 / 1` | eight existing missing-reference notices: `0003IP`, `00037E`, `00037F`, `00037D`, `00037C` | Gate 2A inventory repair and projected stats; generated refresh deferred and then completed |

- Historical initial-callback queue readback: `python .\tools\validator.py --queue-status`, command `000000023665`, timestamp `2026-08-14T19:17:27-04:00`, exit `0`; queued/processing ordinary jobs `0/0`, queued/processing generated refresh jobs `0/0`. The Gate 2A repair used one coherent physical-header wait instead of a second queue-status command.
- Dated callback-generated CPP snapshot: `auto-generated/NexusTK/ui/dialogs/TextMenuDialogs.cpp`, command header `000000023733`, refreshed `2026-08-14T20:48:54-04:00`, filesystem write `2026-08-14T20:49:08.3599318-04:00`, SHA256 `622A414866A62688C578B8C5AFFBF38AAE86F952859F0BEC17B362851BC7712B`, 18,812 bytes, 603 lines. Physical readback confirmed the UID0000ET declaration at line 105, `AddTextEntry` at line 133, UID0004HE marker/definition at lines 142-171, `ForwardOwnerSelectionState` at line 172, `DrawListItem` at line 177, the UID0004HC call at line 572, and no UID0004HE empty marker or UID0004HF emission.
- Dated callback-generated H snapshot: `auto-generated/NexusTK/ui/dialogs/TextMenuDialogs.h`, command header `000000023733`, refreshed `2026-08-14T20:48:54-04:00`, filesystem write `2026-08-14T20:49:08.4002246-04:00`, SHA256 `93D8C7A85BE65F592773B33CD9A6B3A6AF9537D44AD6FF3497162D8173F6C2FB`, 1,630 bytes, 47 lines. Physical readback confirmed `friend class TextMenuItemList;` at line 21. At that dated snapshot, the generated directory contained the `TextMenuDialogs.cpp`/`.h` pair and none of the superseded named class-per-file outputs. Newer physical headers and metadata supersede this snapshot for action-time generated truth.
- As dated receipts, all initial callback and Gate 2A repair scoped validator commands returned `ok:1`. Missing-reference notices pre-existed in support prose and were not failures of the accepted UID0004HE callback. Manual coverage validation is supervisor-owned; this sentence makes no assertion about its current status.

## Changed Files

- Modified ordinary docs:
  - `by-memory/0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer.md`: SHA256 `6DAB2485E0BB49D71BF96F0EFF43A7B0C42C2D84D05BB5555D57060A66A18CDD`, 11,092 bytes, 122 lines.
  - `by-class/TextMenuItemList.md`: SHA256 `15ABF57395AC80F52E65954C55A56BDE70DF231BB2045AB68D26E558DD1EDDB3`, 29,696 bytes, 264 lines.
  - `by-class/TextMenuDialog.md`: SHA256 `B2DA45BB0934EA4C358C8A53C4EA53347DDD55361D6DFA63E059531D8EDC231A`, 16,837 bytes, 138 lines.
  - `by-memory/0x00519210-0x005194b1.TextMenuDialogOnDialogAction.md`: SHA256 `4C28C641A86877EE9020F7EECD174C1492E6DDEC8794DD3680C9686FC4B392CD`, 6,787 bytes, 93 lines.
  - `by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md`: SHA256 `13ECB6F489514ED4345C45D94CE4CA105B90966235C77DF63E63D9C2C15E4FE3`, 32,424 bytes, 179 lines.
  - `by-file/TextMenuDialogs.md`: SHA256 `52FF662378E43131789FAD540B49E85392B173E4BEC5408F0C1F0EC7A75019C8`, 33,759 bytes, 183 lines.
- Validator-owned side effects: projected completion stats, source/UID/reference registry state, and generated `TextMenuDialogs.cpp/.h` refreshed through command `000000023733`; B005 did not hand-edit any generated, tracker, registry, or project-state file.
- Renamed/moved: none. UID0004HF and its page were not edited.
- IDA: read-only; no mutation/save/start/stop/restart.
- Leases: B005 acquired each of the original six ordinary file leases only immediately before its edit/validator batch and successfully released each immediately afterward. For the Gate 2A repair, B005 acquired only `by-class/TextMenuItemList.md` and `by-file/TextMenuDialogs.md` at `2026-08-15T00:48:15Z`, released both successfully after command `000000023733` and physical generated readback, and confirmed the lease report at `2026-08-15T00:49:40.5233984Z` contained no matching active lease. No lease was needed for this report in B005's own research folder.
- Report lifecycle role boundary: B005 never owns validator `execute_report` or manual archive movement. Authoritative lifecycle truth is external to this report body and comes from the artifact's path plus validator-owned status/history metadata. Dated actor history: B005 issued no report-lifecycle command during research or callback repair.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validated exact pre-callback report SHA256 `06766765B30CFBEDAAFB463C2869134047720275708EEE10693DB3A1217B1043` before implementation.
- [x] By-file exhaustive whole-file control is target-specific not applicable; this is one exact by-memory target with affected support inventory enumerated.
- [x] By-file per-item closure control is target-specific not applicable; every target/support item in this report has a disposition.
- [x] By-file generated whole-file audit control is target-specific not applicable; target-specific generated omissions and exact expected repairs are recorded.
- [x] Target/support docs to update are enumerated with exact paths and sections.
- [x] Additional-UID control satisfied: none declared; support UIDs are not additional targets.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger contains every proposed claim with exact destination/action/state.
- [x] Metadata and score changes specified.
- [x] Score-limiting blockers researched to implementation-ready resolution; rare no-improvement exception is not used.
- [x] Owner/emitter/reconstructable changes specified.
- [x] Split/rename/new-child disposition specified: preserve exact child, no new split, reclassify retained source.
- [x] Source placement, range/padding/reclassification, and IDA actions specified.
- [x] Supervisor Gate 2B handoff lists exact addresses/entities, literal prestates, actions, dependencies, safety constraints, protected state, expected readback, and all four UID0004HE physical frame rows through I01/I03-I09.
- [x] Exact formal target CPP, target no-H reason, UID0000ET declaration, UID0000ES H friend, and UID0004HC replacement supplied.
- [x] Third-party import confirmed not applicable.
- [x] Exact target/support facts supplied at report-level detail.
- [x] Historical stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Wave2/Wave3 mentions encountered and ignored as stale.
- [x] Open questions exhausted to best-probability resolutions with bounded lexical uncertainty.
- [x] Callback validators and generated/manual supervisor work identified.
- [x] Exact supervisor-owned manual coverage text supplied.

Implementation callback pass:

- [ ] Supervisor alone owns application and exact readback of every accepted Section 21 IDA recommendation; B005 claims no IDA mutation or persistence authority.
- [x] By-file whole-file incorporation control remains target-specific not applicable.
- [x] By-file full generated inventory closure control is target-specific not applicable; the callback-specific generated CPP/H readback is recorded as a dated receipt under Validator Results.
- [x] Report accepted by supervisor for implementation at exact pre-callback SHA256 `06766765B30CFBEDAAFB463C2869134047720275708EEE10693DB3A1217B1043`.
- [x] All accepted target/support ordinary-document details incorporated at report-level detail.
- [x] Primary UID0004HE verified independently against its ledger and destination docs.
- [x] Ledger/checklist states updated after physical implementation.
- [x] Metadata, score, owner, emitter, CPP/H, source-placement, and support changes applied.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved in destinations.
- [x] Open questions remain resolved or truthfully bounded.
- [x] Scoped validators passed and exact receipts recorded for every changed ordinary doc.
- [x] Callback-fresh generated CPP/H physical readback completed at validator command `000000023733`.
- [ ] Supervisor-only action allocation: IDA application/readback, manual coverage/tracker validation, generated readback required by any newer command, and validator lifecycle operations may occur only under supervisor/validator authority after the applicable exact-artifact gates pass. This unchecked control records actor allocation, not mutable completion status.
- [x] Supervisor-only claim allocation is enumerated exactly: C4HE-038 through C4HE-049 cover IDA, C4HE-050/C4HE-051 cover manual coverage, and C4HE-052 covers the cross-gate workflow. This list records responsibility and prerequisites without asserting that an action is pending, complete, or currently scheduled.
- [x] Lifecycle-neutrality control: execution/archive truth is external to the report body and authoritative only from artifact path plus validator-owned status/history metadata; the body records timeless role boundaries and dated actor/implementation history.

- Twin checklist allocation: 37 checked `applied` rows and 15 unchecked `proposed` rows; no checked row is proposed and no unchecked row is applied.

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C4HE-001 | 0004HE | Preserve exact half-open target range `[0x005195f0,0x0051971d)` and body SHA256 `94B5D776499D730276233ECDDBD03FCAC7CD73258CF8B0FEC82868A2EDD16C8A` | High | PE bytes and live item model | target Status/Boundary Evidence | incorporate | applied |
| [x] | C4HE-002 | 0004HE | Record eight-byte leading and three-byte trailing `0xcc` padding with exact hashes | High | PE bytes, live get_bytes/items | target Boundary Evidence | incorporate | applied |
| [x] | C4HE-003 | 0004HE | Record ordinary void thiscall ABI with ECX receiver and no logical stack parameter | High | prologue, receiver save, plain `retn` | target ABI | incorporate | applied |
| [x] | C4HE-004 | 0004HE | Record signed negative `m_selectedIndex` early return | High | 0x519606-0x519614 | target Behavior | incorporate | applied |
| [x] | C4HE-005 | 0004HE | Use explicit-index `GetItem(m_selectedIndex)` rather than stale `GetSelectedEntry` | High | ListPane_GetItem type and ListPane docs | target Behavior/formal CPP | historicalize | applied |
| [x] | C4HE-006 | 0004HE | Record selected row `TextMenuItemListEntry::itemId` as zero-extended word at row offset zero | High | 0x51961b and row layout | target Behavior | incorporate | applied |
| [x] | C4HE-007 | 0004HE | Record opcode `0x39` and exact packet field order | High | 0x51961e-0x51969d | target Packet Semantics | incorporate | applied |
| [x] | C4HE-008 | 0004HE | Record `m_menuType` byte at list offset `+0x14c` | High | 0x519651 | target Layout/Packet Semantics | incorporate | applied |
| [x] | C4HE-009 | 0004HE | Record `m_menuId` dword at list offset `+0x150` serialized big-endian | High | 0x519674-0x51967a | target Layout/Packet Semantics | incorporate | applied |
| [x] | C4HE-010 | 0004HE | Record non-owning owner at `+0x154`, extra-string guard `+0x279`, and string object `+0x27c` | High | 0x5196a6-0x5196d9 | target Layout/Packet Semantics | incorporate | applied |
| [x] | C4HE-011 | 0004HE | Record cursor `<0x100` check and local non-sent trailing zero | High | 0x5196e7-0x5196fd | target Length Semantics | incorporate | applied |
| [x] | C4HE-012 | 0004HE | Record `g_packetSender` / Socket queue-and-send route with pre-terminator length | High | 0x5196ee-0x519704 and typed global | target Packet Semantics | incorporate | applied |
| [x] | C4HE-013 | 0004HE | Exclude security cookie, range-failure call, raw labels, and unused GetMemoryMan accessor from human source while preserving them as binary evidence | High | exact disassembly and helper body | target Source Draft/Compiler Exclusions | incorporate | applied |
| [x] | C4HE-014 | 0004HE | Preserve zero direct start-xref fact as negative liveness evidence, not a no-code veto | High | xrefs_to/xref_query | target Route Analysis/Historical Assumptions | historicalize | applied |
| [x] | C4HE-015 | 0004HE | Record zero external references to every target instruction head | High | bounded all-head xref query | target Route Analysis | incorporate | applied |
| [x] | C4HE-016 | 0004HE | Record zero VA, RVA, raw-offset, code, data, and immediate pointer routes | High | find/find_bytes/xref queries | target Route Analysis | incorporate | applied |
| [x] | C4HE-017 | 0004HE | Record absence from all TextMenuItemList vtable views while preserving vtable identity | High | vtable bytes and refs | target Route Analysis | incorporate | applied |
| [x] | C4HE-018 | 0004HE | Record exact live semantic expansion at `0x0051938f-0x00519492` | High | paired instruction inventory and inline hash | target Inline Duplicate Evidence | incorporate | applied |
| [x] | C4HE-019 | 0004HE | Record UID0004HC's live vtable route through cell `0x0061ecf4 -> 0x00519210` | High | xref/data readback | target Inline Duplicate Evidence | incorporate | applied |
| [x] | C4HE-020 | 0004HE | Reclassify target as a retained ordinary source method whose active call was compiler-inlined | High | complete body, inline expansion, owner locality | target Status/Source Classification | historicalize | applied |
| [x] | C4HE-021 | 0004HE | Use source name `TextMenuItemList::SendSelectedTextMenuReply()` and collision-free IDA name `TextMenuItemList__SendSelectedTextMenuReply` | Medium-high | role, class vocabulary, no collision | target Status/formal CPP and IDA handoff | incorporate | applied |
| [x] | C4HE-022 | 0004HE | Keep canonical owner UID0000ET TextMenuItemList | High | receiver fields/layout and class family | target metadata/Status | already-present | applied |
| [x] | C4HE-023 | 0004HE | Set emitter UID0000ET | High | class-owned method definition route | target metadata/Status | incorporate | applied |
| [x] | C4HE-024 | 0004HE | Place source under UID0000OP TextMenuDialogs.cpp after TextMenuItemList::AddTextEntry | High | physical order and file ownership | target Source Placement; file inventory | incorporate | applied |
| [x] | C4HE-025 | 0004HE | Raise target from 86/91 to 93/94 | High | resolved emitter/code/liveness/source blockers | target metadata/Score Rationale | incorporate | applied |
| [x] | C4HE-026 | 0004HE | Insert exact self-contained formal target CPP body | High | full reconstruction and support API contracts | target RECONSTRUCTION_CPP CODE | incorporate | applied |
| [x] | C4HE-027 | 0004HE | Keep target H blank because declaration is class-owned | High | emitter structure | target RECONSTRUCTION_H CODE | already-present | applied |
| [x] | C4HE-028 | 0000ET | Add public `void SendSelectedTextMenuReply();` declaration to the file-local TextMenuItemList class | High | call route and class access | TextMenuItemList formal CPP class declaration | incorporate | applied |
| [x] | C4HE-029 | 0000ET | Replace raw-no-route prose with retained-source/inline-expansion evidence and preserve historical negative evidence | High | current MCP versus old reports | TextMenuItemList method map/evidence/history | historicalize | applied |
| [x] | C4HE-030 | 0000ET | Raise class score from 89/88 to 91/91 | Medium-high | one raw helper resolved; explicit-id sibling remains capped | TextMenuItemList metadata/Changes | incorporate | applied |
| [x] | C4HE-031 | 0004HC | Replace manual large-list selected-row serialization with `list->SendSelectedTextMenuReply()` and then close | High | exact inline expansion and source factoring | OnDialogAction formal CPP/evidence | historicalize | applied |
| [x] | C4HE-032 | 0004HC | Raise action-handler support score from 90/92 to 91/93 | Medium-high | stale private-field/accessor source repaired | OnDialogAction metadata/Changes | incorporate | applied |
| [x] | C4HE-033 | 0000ES | Add `friend class TextMenuItemList;` to permit direct owner extra-string access without invented getters | Medium-high | direct field loads and no accessor calls | TextMenuDialog formal H/evidence | incorporate | applied |
| [x] | C4HE-034 | 0001BN | Reclassify UID0004HE inventory entry as retained source-emitting child and preserve UID0004HF as separate unresolved sibling | High | target/sibling audit | aggregate inventory/history | historicalize | applied |
| [x] | C4HE-035 | 0000OP | Update file inventory/source order and generated expectations for UID0004HE | High | owner route and current generated omission | TextMenuDialogs file inventory/history | incorporate | applied |
| [x] | C4HE-036 | 0004HF | Preserve sibling 86/91, owner UID0000ET, blank emitter/CPP, exact independent range, and future target-specific review | High | distinct ABI/range and no assignment | sibling page and aggregate references | already-present | applied |
| [x] | C4HE-037 | 0003YJ | Preserve current value-first scalar writer evidence and use established human-facing cursor append wrappers in formal source | High | helper types/docs and analogous emitted code | target Source Draft/support references | already-present | applied |
| [ ] | C4HE-038 | 0004HE | Supervisor uses public `define_func` for exact `[0x005195f0,0x0051971d)` and requires literal name `sub_5195F0`, empty persisted item type, `analyze_function` prototype `null`, decompiler declaration `void __thiscall sub_5195F0(int *this)`, four-row frame `var_100 +0x0c/4 _DWORD`, `var_FC +0x10/4 _DWORD`, `__saved_registers +0x10c/4 _DWORD`, and `__return_address +0x110/4 _UNKNOWN *`, `AR` absent, `AP` absent, `FR` absent, `FP` absent, and 4/0/0 added/removed/replaced intermediate before any dependent action | High | current canonical fail-closed I01 reproduction plus exact prologue/ret/padding/body hash and UID0004HB/current-schema raw-function precedent | canonical IDB target function item | incorporate | proposed |
| [ ] | C4HE-039 | 0004HE | Supervisor uses public `declare_type` to declare only incomplete `struct TextMenuItemList` after the exact four-row I01 intermediate passes and before applying the prototype | High | type_inspect absent; no safe full UDT; four-row target frame reproduced | canonical IDB local type | incorporate | proposed |
| [ ] | C4HE-040 | 0004HE | Supervisor uses public `rename` with `pure:true`, no overwrite, to apply `TextMenuItemList__SendSelectedTextMenuReply` only after the exact I01 empty-persisted-type, null-prototype, decompiler-`int *this`, four-row-frame intermediate and collision check pass | Medium-high | no collision, exact reproduced four-row intermediate, and source role | canonical IDB target name | incorporate | proposed |
| [ ] | C4HE-041 | 0004HE | Supervisor uses public `set_type` to replace the empty persisted type/null analysis prototype and decompiler `int *this` presentation with the exact final void thiscall `TextMenuItemList *this` prototype while preserving all four physical frame rows | High | ECX receiver, plain retn, and current canonical deterministic four-row I01/I03 intermediate | canonical IDB target type | incorporate | proposed |
| [ ] | C4HE-042 | 0004HE | Supervisor uses public `set_function_comments` for the exact regular function comment linking retained body and inline expansion only while all four target frame rows remain unchanged | High | target/inline comparison and four-row frame protection | canonical IDB function comment | incorporate | proposed |
| [ ] | C4HE-043 | 0004HE | Supervisor uses public `set_address_comments` for the exact regular comment at `0x00519606` describing selected-index/GetItem semantics only while all four containing-function frame rows remain unchanged | High | direct instructions and four-row containing-function readback | canonical IDB address comment | incorporate | proposed |
| [ ] | C4HE-044 | 0004HE | Supervisor uses public `set_address_comments` for the exact regular comment at `0x005196a6` describing owner extra-string semantics only while all four containing-function frame rows remain unchanged | High | direct instructions and four-row containing-function readback | canonical IDB address comment | incorporate | proposed |
| [ ] | C4HE-045 | 0004HE | Supervisor uses public `set_address_comments` for the exact regular comment at `0x005196f5` describing checked non-sent terminator semantics only while all four containing-function frame rows remain unchanged | High | direct instructions and four-row containing-function readback | canonical IDB address comment | incorporate | proposed |
| [ ] | C4HE-046 | 0004HC | Supervisor uses public `set_address_comments` for the exact regular comment at `0x0051938f` linking the active inline expansion to UID0004HE only after the UID0004HE four-row dependency frame remains unchanged | High | exact paired behavior and four-row target dependency readback | canonical IDB inline address comment | incorporate | proposed |
| [ ] | C4HE-047 | 0004HE | Preserve P01's literal leading SHA256 `3D2F424783DF5853C8D7121B1371650C04241F318E1B0CD46BEDBC805B9164C3`, target SHA256 `94B5D776499D730276233ECDDBD03FCAC7CD73258CF8B0FEC82868A2EDD16C8A`, trailing SHA256 `E668F0A1B72560CED14C54488A25335D11336448950BB6485267EBC5EB3FECEE`, zero start/all-head xrefs, and empty code/data/immediate/VA/RVA/raw-offset/vtable route sets outside bounded I01-I08 metadata actions | High | hashes/items/xrefs | canonical IDB protected state | already-present | proposed |
| [ ] | C4HE-048 | 0004HF | Preserve P02's sibling body SHA256 `CB928A0115A74BA12B714758CA0A23D6D26C83C7480E418894371E8746C4C65A`, trailing-padding SHA256 `33CC4A00A0F04735602819132DA3E3FAC4CDEB8EC7AEE92551DC79BA8488E722`, absent function, absent entry name, absent entry type, absent entry `AR`, absent entry `AP`, not-applicable entry `FR`, and not-applicable entry `FP` | High | sibling hash/items/comments | canonical IDB protected state | already-present | proposed |
| [ ] | C4HE-049 | 0004HC | Preserve every literal P03 function/cell range, hash, xref, vtable-value, and independent channel field plus every address-indexed P04 vtable/g_packetSender byte, name, type, value, comment, and channel field; I09 remains the sole address-item `AR` exception | High | live readback | canonical IDB protected state | already-present | proposed |
| [ ] | C4HE-050 | 0004HE | Insert exact manual by-memory coverage row after UID0004HB | High | absent current row and proposed target state | by-memory/-coverage-report.md | incorporate | proposed |
| [ ] | C4HE-051 | 0000ET | Replace stale class coverage row and stale aggregate coverage row with exact proposed/current state | High | physical manual-row readback | by-class/-coverage-report.md and by-memory/-coverage-report.md | incorporate | proposed |
| [ ] | C4HE-052 | 0004HE | Supervisor owns action-time generated CPP/H and research-tracker reread, manual coverage application/validation, Gate 2B application/readback/persistence, and validator lifecycle execution/archive | High | supervisor-only workflow and actor boundaries | supervisor-owned generated/tracker/coverage/IDA/lifecycle outputs | incorporate | proposed |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000023839","destination_path":"executed-b-agent-research/B005/0004HE-TextMenuItemListRawSelectedRowReplySerializer-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0004HE-TextMenuItemListRawSelectedRowReplySerializer-empty-emitter-source-quality.md","timestamp":"2026-08-15T02:23:07-04:00","uid":"0004HE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
