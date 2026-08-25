** TARGET-REPORT-UID:0002Q7 **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# UID0002Q7 NewUserMiscDialogPane Core And Packet Helpers Source-Quality Report


**Agent:** Agent-B013
**Target UID:** 0002Q7
**Target path:** `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md`
**Assignment type:** Report-only B-agent research
**MCP session used:** `3a33af0b`
**Report status:** Implementation callback complete; ready for supervisor Gate 2 verification and supervisor-only execute

## Finalized Report / Current Recommendation

UID0002Q7 has been implemented as a non-emitting `NewUserMiscDialogPane` nested index. It does not receive a single broad `RECONSTRUCTION_CPP CODE` body. The by-memory page spans several independently observed function bodies, raw no-function islands, a switch table, and padding; exact child pages now carry the future source-body work.

Implemented target metadata:

| Field | Recommended value | Reason |
| --- | --- | --- |
| `COMPLETION` | `88` | Current MCP confirms every function/raw/padding boundary and the inline packet path. Completion remains below final because child-level C++ is not yet incorporated. |
| `CONFIDENCE` | `91` | Ownership, range boundaries, raw no-xref caveats, virtual-entry xrefs, singleton/vtable refs, and inline packet behavior are current MCP-backed. Confidence is still capped by source-level naming/layout inference. |
| `CANONICAL_OWNER` | `0000LX` | The whole covered cluster belongs semantically to the `NewUserMiscDialogPane` source family. |
| `RECONSTRUCTABLE` | `FALSE` | The page is a mixed internal index over multiple source bodies and non-source padding/table spans, not one source-level emitted body. |
| `EMITTER_UIDS` | blank | The parent/index must not emit source directly. Exact child pages carry future emitters. |
| `RECONSTRUCTION_CPP CODE` | blank | Broad C++ would either paste child bodies into a parent page or invent unobserved helper/function routes. |

Implementation callback completed: child by-memory pages were created, target/support docs were updated at report-level detail, broad UID0002Q7 formal C++ remains blank, and scoped validators were run.

## Supporting Research

This is the current post-callback artifact. The accepted by-* target/support docs were edited, exact child by-memory pages were created, scoped validators were run, and validator-owned generated outputs refreshed during the final wait-generated validation. No coverage report, report lifecycle/archive file, supervisor ledger, or manual generated file edit was performed, and no `execute_report` or lifecycle command was run.

Mandatory MCP evidence was collected after the supervisor restart from current active session `3a33af0b`; stale session IDs were not used. MCP `idb_list` reported one active session for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` returned `status: ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready: true`, and `hexrays_ready: true`.

## Target

Target: `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md`, UID0002Q7.

Implemented metadata:

| Field | Current value |
| --- | --- |
| `COMPLETION` | `88` |
| `CONFIDENCE` | `91` |
| `CANONICAL_OWNER` | `0000LX` |
| `RECONSTRUCTABLE` | `FALSE` |
| `EMITTER_UIDS` | blank |
| Formal C++ | blank |

Current classification: the former reconstructable empty emitter is now a non-emitting nested index. The exact range includes a constructor, several vtable-dispatched handlers, a reply wrapper, a reply handler, raw no-function packet/helper islands, a switch table, and padding. Exact child pages now carry those spans without forcing unsafe broad parent C++.

## Current Target State

The target page now records the right owner family and treats the whole range as a non-emitting nested index. Current MCP confirms the implemented interpretation:

- `0x004fb630` is one constructor function, size `0x99f`, reached from `0x004fa74e` in `sub_4FA5B0`.
- `0x004fc010` is one virtual command handler, size `0x56e`, with only vtable data xref `0x0061d46c`.
- `0x004fc5c0` is one small reply wrapper, size `0x26`, with only vtable data xref `0x0061d494`.
- `0x004fc5f0` is one key/help path, size `0x18c`, with only vtable data xref `0x0061d48c`.
- `0x004fc780` is one help/description handler, size `0x267`, with only vtable data xref `0x0061d488`.
- `0x004fcb10` is one reply handler, size `0x1de`, reached by code xref `0x004fc5e1` from the reply wrapper.
- `0x004fbfd0`, `0x004fca20`, and `0x004fcac0` are not IDA function starts and have zero direct xrefs.
- `0x004fbfcf`, `0x004fcab8`, `0x004fcb04`, and `0x004fccee` are padding/boundary spans.

The implemented `88/91` target score reflects the current split/no-parent-C++ proof. The exact child pages created during callback use validator-assigned UIDs `0004GL` through `0004GX`.

## Executive Recommendation

Convert UID0002Q7 into a non-emitting child inventory page and split exact child pages before C++. Do not paste constructor, command, reply, raw helper, or destructor-shaped source into the current broad page. Do not add synthetic shared packet-builder helpers to hide the range problem. Do not treat the raw packet islands as ordinary callable helpers until a source-level route is established or they are separately documented as retained no-xref source-shaped bodies.

## Supervisor Active Recheck

Supervisor reported MCP recovered with session `3a33af0b`. I performed my own read-only recheck:

- `idb_list`: active session `3a33af0b`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active `true`, analyzing `false`.
- `server_health`: `ok`, `hexrays_ready: true`, `auto_analysis_ready: true`.
- Bounded MCP calls only: `lookup_funcs`, `xrefs_to`, `get_bytes`, `callees`, and selected `decompile` calls for exact target functions.

## Inference Research Guidance Check

The target is source-quality work because it has a blank C++ block despite `RECONSTRUCTABLE:TRUE` and nonblank `EMITTER_UIDS`. The relevant by-structure rule is that by-memory C++ content is limited to the page's own memory range and a parent/container page must not paste child function bodies into the parent. UID0002Q7 is narrower than the parent aggregate UID00019U, but it is still broad internally. Therefore the correct repair is structural split, not broad C++.

Generated names were treated as leads, not source names. The source-facing names below are inferred from class role, vtable placement, packet behavior, and surrounding docs; exact original spelling remains unproven and should cap confidence below final audit.

## Heuristic / Inference Reanalysis And Validation

The main blocker was whether the broad page could legitimately be emitted as one source chunk. Current evidence rejects that route.

Observed facts:

- Multiple IDA function objects exist inside the range, not one function.
- The raw starts at `0x004fbfd0`, `0x004fca20`, and `0x004fcac0` are byte-real source-shaped islands, but MCP reports them as not functions and xrefs-to reports no references.
- The opcode `4` and opcode `21` packet behavior is already inlined in the virtual command handler at `0x004fc010`; therefore adding callable packet helpers for the raw starts would invent an observed route unless those islands are split and documented as raw retained bodies.
- The destructor-shaped raw island overlaps source semantics already also present in scalar deleting destructor `0x005029f0`; it should not be pasted into the broad target as a second normal destructor body without a separate child/no-route explanation.
- The constructor contains inline setup for `GenderButtonControlPane`, `DirectionButtonControlPane`, and `SelectBoxControlPane` instances. Those are consumer construction facts, not ownership of reusable control methods.

Inference outcome: source ownership by `NewUserMiscDialogPane` is strong, but source emission must be per exact observed child, not by the current UID0002Q7 aggregate.

## Evidence Standards Used

- MCP facts are marked as current session `3a33af0b`.
- Current by-* docs were read as documentation evidence, not authority where they conflict with MCP.
- Old executed reports were search-gated and used only when directly relevant to UID0002Q7 or constructor inline control setup.
- No generated files were edited; generated output was used only as lead evidence that UID0002Q7 is currently an empty marker.
- Source names are inferred unless explicitly symbol-proven.

## Evidence Checked

Read current docs:

- `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md`
- `by-file/NewUserMiscDialogPane.md`
- `by-class/NewUserMiscDialogPane.md`
- `by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md`
- `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` lead output showing UID0002Q7 as an empty generated marker.
- `auto-generated/-ag-memory-coverage.md` and `auto-generated/-ag-coverage-report-by-memory.md` lead rows showing UID0002Q7 not covered.

Search terms used with `rg`: `0002Q7`, `0x004fb630`, `0x004fccee`, `NewUserMiscDialogPaneCoreAndPacketHelpers`, `NewUserMisc`, `4fb630`, `4fccee`.

Relevant executed reports opened:

- `executed-b-agent-research/B001/B001-MEMTOOL-004FB630-NewUserMiscShapeAndPasswordDialogs.md`: confirms the broader physical aggregate is mixed-owner and not direct source ownership for UID0002Q7.
- `executed-b-agent-research/B002/00005P-GenderButtonControlPane-class-source-quality.md`: confirms gender button constructor inline setup in UID0002Q7 is consumer evidence only.

MCP evidence from session `3a33af0b`:

- `lookup_funcs` for exact boundary/function starts.
- `xrefs_to` for function starts, raw starts, vtables, singleton, and scalar deleting destructor.
- `get_bytes` for predecessor padding, constructor/raw transitions, switch table/raw helper transition, helper padding, and final padding.
- `callees` for constructor, command handler, key/help handler, description handler, reply handler, and destructor.
- `decompile` for `0x004fb630`, `0x004fc010`, `0x004fc5c0`, `0x004fcb10`, and `0x005029f0`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0002Q7-001 | UID0002Q7 is a `NewUserMiscDialogPane` source-family cluster, but not one emitted source body. | 91 | MCP function inventory plus vtable/singleton refs; current target/support docs. | Target Status, Reconstruction Notes, Score Rationale | incorporate | applied |
| C-0002Q7-002 | Target should become a non-emitting nested index/container with `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank C++ block. | 90 | by-structure parent/child C++ rule; multiple internal function bodies and padding spans. | Target metadata and Reconstruction Notes | incorporate | applied |
| C-0002Q7-003 | Current internal function inventory is `0x004fb630`, `0x004fc010`, `0x004fc5c0`, `0x004fc5f0`, `0x004fc780`, and `0x004fcb10`, with scalar deleting destructor support at `0x005029f0`. | 92 | MCP `lookup_funcs`, `xrefs_to`, `callees`, selected decompile. | Target Covered Ranges and child inventory | incorporate | applied |
| C-0002Q7-004 | Raw starts `0x004fbfd0`, `0x004fca20`, and `0x004fcac0` are not IDA functions and have zero direct xrefs in current MCP. | 92 | MCP `lookup_funcs` and `xrefs_to`. | Target raw-island notes and child pages | incorporate | applied |
| C-0002Q7-005 | Opcode `4` create/misc and opcode `21` cancel packet send behavior is observed inline in `0x004fc010`; raw packet helper bodies must not be represented as called helpers from this target without separate proof. | 90 | MCP decompile of `0x004fc010` shows `sub_575380` writes and `sub_574BB0(dword_67A7EC, ..., 5/1)`. | Target Reconstruction Notes and C++ no-code proof | incorporate | applied |
| C-0002Q7-006 | Constructor `0x004fb630` builds `DLGNEW02.EPD`, publishes `g_pNewUserMiscDialogPane`, writes `NewUserMiscDialogPane` vtables, creates child controls, seeds/randomizes initial shape/style state, and opens the pane. | 90 | MCP decompile of `0x004fb630`; current file/class docs; UID0002XL singleton evidence as existing support. | New child constructor page, by-file/by-class method notes | incorporate | applied |
| C-0002Q7-007 | Reply wrapper `0x004fc5c0` dispatches only packet type/result marker `2` to `0x004fcb10`; reply handler parses result byte and ANSI message, converts with `MultiByteToWideChar`, shows alert, and dismisses on success. | 91 | MCP decompile of `0x004fc5c0` and `0x004fcb10`. | Reply wrapper/reply handler child pages and class method notes | incorporate | applied |
| C-0002Q7-008 | Destructor-shaped raw island shares vtable/singleton cleanup semantics with scalar deleting destructor `0x005029f0`; keep it as raw/no-route evidence until split review resolves final source representation. | 88 | MCP bytes at `0x004fbfc0`; xrefs to vtables/singleton; decompile of `0x005029f0`. | Raw cleanup child page and target caveat | incorporate | applied |
| C-0002Q7-009 | `GenderButtonControlPane`, `DirectionButtonControlPane`, and `SelectBoxControlPane` setup inside the constructor is consumer inline construction, not reusable-control source ownership. | 89 | Current by-class/by-file support docs and B002/B004 executed reports; constructor decompile refs. | by-file/by-class notes and target ownership alternatives | already-present | already-present |
| C-0002Q7-010 | `CashShopRequest`/packet queue is a dependency only, not owner/emitter for UID0002Q7. | 89 | Packet send uses `dword_67A7EC` and `sub_574BB0`, but class vtable/constructor/singleton refs bind to NewUserMisc. | Ranked Ownership Analysis and support docs | incorporate | applied |
| C-0002Q7-011 | `CreateUserDialogs` is an umbrella/source-family relationship, not a proven replacement direct owner for this class page. | 86 | Current file docs and constructor caller path from NewUser dialog flow. | Source Placement and by-file notes | incorporate | applied |
| C-0002Q7-012 | Exact source-facing child names should be descriptive/inferred, not raw `sub_` labels, with confidence cap because exact original names are not symbol-proven. | 87 | No durable source symbols for these methods in current docs/MCP; behavior-based naming. | Child creation plan and rename recommendations | incorporate | applied |

## Positive Evidence Summary

- Strong class ownership: constructor and scalar deleting destructor both write `NewUserMiscDialogPane` vtables `0x0061d424`, `0x0061d484`, and `0x0061d4b4`; constructor and teardown paths touch singleton `0x0069b488`.
- Strong internal range map: current MCP separates six IDA functions from raw no-function islands, switch table, and padding.
- Strong source-family placement: constructor loads `DLGNEW02.EPD`, initializes create-user customization controls, and is reached from the new-user dialog flow.
- Strong packet facts: command handler creates five-byte opcode `4` and one-byte opcode `21` sends through `dword_67A7EC`/`sub_574BB0`.
- Strong no-broad-C++ proof: by-memory source code cannot mix child function bodies and padding into one parent source block.

## IDA MCP Facts

Current session: `3a33af0b`.

`lookup_funcs`:

| Address | Result |
| --- | --- |
| `0x004fb62a` | not a function; preceding bytes are padding |
| `0x004fb630` | `sub_4FB630`, size `0x99f` |
| `0x004fbfd0` | not a function |
| `0x004fc010` | `sub_4FC010`, size `0x56e` |
| `0x004fc5c0` | `sub_4FC5C0`, size `0x26` |
| `0x004fc5f0` | `sub_4FC5F0`, size `0x18c` |
| `0x004fc780` | `sub_4FC780`, size `0x267` |
| `0x004fca20` | not a function |
| `0x004fcac0` | not a function |
| `0x004fcb10` | `sub_4FCB10`, size `0x1de` |
| `0x004fccee` | not a function |
| `0x005029f0` | `sub_5029F0`, size `0x71` |

`xrefs_to`:

- `0x004fb630`: one code xref at `0x004fa74e` in `sub_4FA5B0`.
- `0x004fbfd0`: zero xrefs.
- `0x004fc010`: data xref `0x0061d46c`.
- `0x004fc5c0`: data xref `0x0061d494`.
- `0x004fc5f0`: data xref `0x0061d48c`.
- `0x004fc780`: data xref `0x0061d488`.
- `0x004fca20`: zero xrefs.
- `0x004fcac0`: zero xrefs.
- `0x004fcb10`: code xref `0x004fc5e1` in `sub_4FC5C0`.
- `0x005029f0`: code xrefs `0x0050252a`, `0x00502535`, and data xref `0x0061d424`.
- `0x0061d424`, `0x0061d484`, `0x0061d4b4`: refs from constructor, raw cleanup island, and scalar deleting destructor.
- `0x0069b488`: refs from constructor publish/fallback, raw cleanup clear, support helper `0x00502400`, and scalar deleting destructor clear.

`get_bytes`:

- `0x004fb62a` size 6: six `0xcc` bytes before constructor.
- `0x004fbfc0` size 32: constructor epilogue, one `0xcc`, then raw cleanup begins with `56 8b f1 c7 06 24 d4 61 00`.
- `0x004fca10` size 48: switch table dwords precede raw opcode `4` helper prologue at `0x004fca20`.
- `0x004fcab0` size 24: raw helper epilogue, `c2 0c 00`, eight `0xcc` bytes, then raw helper prologue at `0x004fcac0`.
- `0x004fcb00` size 24: helper epilogue, `0xcc` padding, then `0x004fcb10` function prologue.
- `0x004fccee` size 2: two `0xcc` bytes after reply handler.

Selected decompile facts:

- `0x004fb630`: constructor calls base setup, stores singleton `unk_69B488`, writes `NewUserMiscDialogPane` vtables, loads `L"DLGNEW02.EPD"`, creates child controls, sets gender fields, randomizes shape/style, and calls pane-open helpers.
- `0x004fc010`: case `1` builds opcode `4`, selected shape/style/gender bytes, sends length `5`, then allocates a waiting pane; case `2` builds opcode `21`, sends length `1`, and dismisses.
- `0x004fc5c0`: checks `**(a2 + 12) == 2`, then calls `sub_4FCB10(this - 40, *(a2 + 12))`.
- `0x004fcb10`: reads result byte at `payload + 1`, reads message length at `payload + 2`, copies ANSI bytes from `payload + 3`, converts with `MultiByteToWideChar`, shows alert via `sub_49FEB0`, and on failure/done path calls `sub_49EB90` and `sub_49DAD0`.
- `0x005029f0`: writes `NewUserMiscDialogPane` vtables, optionally pops/clears active UI state through `unk_69AE08`, clears `unk_69B488`, calls base destructor, and frees when delete flags allow.

## Function / Child Inventory

Recommended split inventory:

| Proposed child range | Proposed source-facing name | Kind | Emission disposition |
| --- | --- | --- | --- |
| `0x004fb630-0x004fbfcf` | `NewUserMiscDialogPane::NewUserMiscDialogPane` | constructor | exact child emitter candidate after child page creation; no parent C++ |
| `0x004fbfcf-0x004fbfd0` | `NewUserMiscDialogPaneConstructorPadding` | padding | non-reconstructable child or documented padding row |
| `0x004fbfd0-0x004fc00f` | `NewUserMiscDialogPaneRawCleanupIsland` | raw no-function cleanup island | exact child, blank C++/no-route proof until destructor representation resolved |
| `0x004fc010-0x004fc57e` | `NewUserMiscDialogPane::HandleCommand` | virtual command handler | exact child emitter candidate |
| `0x004fc5c0-0x004fc5e6` | `NewUserMiscDialogPane::HandlePacket` or `OnPacket` wrapper | virtual reply wrapper | exact child emitter candidate |
| `0x004fc5f0-0x004fc77c` | `NewUserMiscDialogPane::OnKeyDown` | virtual keyboard/help path | exact child emitter candidate |
| `0x004fc780-0x004fc9e7` | `NewUserMiscDialogPane::ShowControlHelp` | virtual help/description handler | exact child emitter candidate |
| `0x004fc9e8-0x004fca18` | `NewUserMiscDialogPaneHelpSwitchTable` | switch table | compiler-generated/data child, no source body |
| `0x004fca20-0x004fcab8` | `NewUserMiscDialogPaneRawCreateRequestSender` | raw no-function opcode `4` sender | exact child, blank C++ unless route/source representation is separately proven |
| `0x004fcab8-0x004fcac0` | `NewUserMiscDialogPanePacketHelperPadding` | padding | non-reconstructable child or documented padding row |
| `0x004fcac0-0x004fcb04` | `NewUserMiscDialogPaneRawCancelRequestSender` | raw no-function opcode `0x15` sender | exact child, blank C++ unless route/source representation is separately proven |
| `0x004fcb04-0x004fcb10` | `NewUserMiscDialogPaneReplyPadding` | padding | non-reconstructable child or documented padding row |
| `0x004fcb10-0x004fccee` | `NewUserMiscDialogPane::HandleCreateCharacterReply` | reply handler | exact child emitter candidate |

## Direct Xref / Caller Inventory

| Address | Direct reachability |
| --- | --- |
| `0x004fb630` | one code xref from `0x004fa74e` in `sub_4FA5B0` |
| `0x004fbfd0` | zero direct xrefs |
| `0x004fc010` | vtable/data xref only at `0x0061d46c` |
| `0x004fc5c0` | vtable/data xref only at `0x0061d494` |
| `0x004fc5f0` | vtable/data xref only at `0x0061d48c` |
| `0x004fc780` | vtable/data xref only at `0x0061d488` |
| `0x004fca20` | zero direct xrefs |
| `0x004fcac0` | zero direct xrefs |
| `0x004fcb10` | code xref from wrapper `0x004fc5e1` |
| `0x005029f0` | adjustor-thunk code xrefs plus vtable data xref |

## Documentation Evidence And IDA Status

Current target/support docs already contain much of the historic evidence, including previous live MCP sessions and raw no-xref scans. The necessary correction is current-state/source route:

- Target currently says "Keep this as source-bearing project code, but do not emit final C++ yet." Replace with a split-first non-emitting target disposition.
- `by-file/NewUserMiscDialogPane.md` currently says file-level C++ remains withheld due raw destructor boundary, packet helper naming, and standalone-vs-umbrella split. Update to clarify that UID0002Q7 should not be the direct C++ body and that exact child pages are needed.
- `by-class/NewUserMiscDialogPane.md` method inventory is accurate but should distinguish broad UID0002Q7 from future child method pages.
- Parent aggregate UID00019U already correctly treats itself as mixed-owner/non-emitting; update only if needed to note UID0002Q7 also needs an internal split.

## Ranked Ownership Analysis

| Candidate owner | Evidence for | Evidence against | Decision |
| --- | --- | --- | --- |
| `NewUserMiscDialogPane` / UID0000LX | Constructor writes class vtables, publishes singleton, uses `DLGNEW02.EPD`, owns command/key/help/reply behavior. | Standalone vs `CreateUserDialogs` file grouping remains inferred. | Best canonical owner/source family. |
| `CreateUserDialogs` / UID0000IK | Caller path is create-user flow and source tree likely has an umbrella. | Does not own class singleton/vtables directly; current by-file keeps this as umbrella only. | Umbrella only, not direct owner replacement. |
| `NewUserDialogPane` | Constructor is reached from new-user dialog reply path. | Different dialog class and responsibility. | Related caller, reject as owner. |
| `CashShopRequest` or packet queue | Packet sends use shared send queue `dword_67A7EC`/`sub_574BB0`. | Dependency only; no vtable/singleton/resource ownership. | Reject as owner. |
| Specialized controls | Constructor inlines Gender/Direction/SelectBox control setup. | Reusable control methods and vtables belong to their own pages; this is consumer construction. | Reject as owner. |
| Broad parent UID00019U | Contains UID0002Q7 physically. | Mixed owner aggregate already reviewed as non-emitting. | Parent/container only. |

## Source Placement

Keep the source-family placement as `NexusTK/login/` under `NewUserMiscDialogPane.cpp`, with `CreateUserDialogs` as umbrella. Do not move UID0002Q7 into `CashShopRequest`, `NewUserDialogPane`, `SpecializedButtonPanes`, or the mixed physical aggregate.

The source file split remains slightly below final audit because the original project could have folded this class into a broader create-user file. That uncertainty does not block the internal by-memory split or the no-parent-C++ decision.

## Range / Split / Padding / Reclassification Analysis

Recommended reclassification:

- UID0002Q7 becomes non-emitting nested index, not a reconstructable direct emitter.
- Exact child pages should be created for each function/raw/data/padding range.
- Padding spans should be explicit so no child function absorbs alignment bytes.
- Raw no-function islands must be split as raw/no-route child pages before any source shape is assigned.
- Switch table `0x004fc9e8-0x004fca18` should be documented as generated data for the help/description handler, not hand-written C++ in the parent block.

This split explains the current empty-emitter problem without downgrading the owner: the owner is correct, the emitter granularity is wrong.

## Negative Evidence Summary

- No current MCP function object exists at `0x004fbfd0`, `0x004fca20`, or `0x004fcac0`.
- No current direct xrefs exist to the three raw starts.
- The opcode send behavior observed in decompile is inline in `0x004fc010`, not routed through the raw helper starts.
- No evidence supports adding namespace-local helper functions in the broad target to represent packet writes.
- No evidence supports making `CashShopRequest`, `NewUserDialogPane`, `GenderButtonControlPane`, `DirectionButtonControlPane`, or `SelectBoxControlPane` the owner of UID0002Q7.
- No evidence supports pasting all child method bodies into UID0002Q7's current formal C++ block.

## IDA Rename / Type / Comment Recommendations

Proposed source-facing names, all inferred:

- `NewUserMiscDialogPane::NewUserMiscDialogPane` for `0x004fb630`.
- `NewUserMiscDialogPane::HandleCommand` for `0x004fc010`.
- `NewUserMiscDialogPane::HandlePacket` or `NewUserMiscDialogPane::OnPacket` for `0x004fc5c0`.
- `NewUserMiscDialogPane::OnKeyDown` for `0x004fc5f0`.
- `NewUserMiscDialogPane::ShowControlHelp` for `0x004fc780`.
- `NewUserMiscDialogPane::HandleCreateCharacterReply` for `0x004fcb10`.
- `g_pNewUserMiscDialogPane` for singleton `0x0069b488`, already supported by UID0002XL.
- `WritePacketByte` / `PacketBufferWriteUInt8` and `QueuePacket` style names should be documented as inferred wrappers for `sub_575380` and `sub_574BB0` unless current support docs provide canonical names.

Do not rename raw starts as ordinary callable functions in target prose without preserving the no-function/no-xref caveat.

## First-Draft C++ Recommendation

No broad UID0002Q7 C++ should be inserted.

Exact no-code proof:

1. UID0002Q7's range contains multiple observed child functions and non-source spans.
2. Current MCP reports raw packet/helper starts are not functions and have zero direct xrefs.
3. Packet send behavior is already observed inline inside the command handler.
4. A broad formal C++ block would misrepresent by-memory ownership by containing child bodies, switch data, padding, and raw islands.
5. A synthetic helper abstraction would add unobserved source bodies/routes unless separately proven as inline compile-away source, which is not proven here.

The correct first-draft C++ route is deferred to exact child pages. During callback, leave UID0002Q7's C++ block blank and document this no-code proof in the target. Child pages can receive formal C++ only after each child range has its own metadata and source-quality review.

## Final Recommendation

Accept the split-first repair. UID0002Q7 is strong NewUserMiscDialogPane evidence but a bad direct emitter. Set the target to a reviewed non-emitting nested index at `88/91`, blank its emitter route, preserve the owner as UID0000LX, and create exact child pages for the internal function/raw/table/padding spans. Update support docs so they no longer describe UID0002Q7 as merely "C++ withheld" but as "internal split required before C++."

## Recommended Target Doc Changes

For `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md`:

- Set `COMPLETION:88`, `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:0000LX`.
- Set `RECONSTRUCTABLE:FALSE`.
- Clear `EMITTER_UIDS`.
- Keep `RECONSTRUCTION_CPP CODE` blank.
- Update item summary/status to say this is a reviewed non-emitting nested index for NewUserMiscDialogPane internals.
- Replace "source-bearing project code, but do not emit final C++ yet" with the explicit no-parent-C++ proof.
- Add current MCP session `3a33af0b` evidence for function sizes, raw no-function starts, xrefs, bytes, packet inline behavior, wrapper/reply path, vtables, and singleton refs.
- Add the proposed child inventory and mark raw starts as no-function/no-xref source-shaped islands.

## Recommended Support Doc Changes

For `by-file/NewUserMiscDialogPane.md`:

- Update UID0002Q7 row/status to say it is internally overbroad and should become a non-emitting nested index with exact child method/raw/table/padding pages.
- Preserve `NexusTK/login/` source placement and `CreateUserDialogs` umbrella caveat.
- State that singleton UID0002XL remains the already-emitting exception; this report does not change its declaration.
- Preserve dependency rejections for `CashShopRequest`, `NewUserDialogPane`, and specialized controls.

For `by-class/NewUserMiscDialogPane.md`:

- Update method notes to refer to future exact child pages for constructor/handlers/reply/raw islands rather than treating UID0002Q7 as the final C++ source block.
- Add current session `3a33af0b` decompile facts for command inline packets and reply handler parsing.
- Preserve control inline setup as consumer evidence only.

For `by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md`:

- Update the UID0002Q7 child row only if callback creates child pages or if wording remains stale. Parent aggregate should remain `RECONSTRUCTABLE:FALSE`.
- Mention UID0002Q7 now also has an internal split requirement; do not make the broader aggregate an emitter.

Consumer/control docs need no edits unless stale wording claims UID0002Q7 owns reusable specialized-control methods.

## Score And Metadata Recommendation

| Document | Completion | Confidence | Metadata/action |
| --- | ---: | ---: | --- |
| UID0002Q7 target | 88 | 91 | `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++; keep owner UID0000LX |
| `by-file/NewUserMiscDialogPane.md` | 86 | 89 | Optional small raise only if split/no-emitter route and current MCP facts are incorporated |
| `by-class/NewUserMiscDialogPane.md` | 86 | 90 | Optional small raise only if method inventory and no-parent-C++ proof are incorporated |
| UID00019U parent aggregate | unchanged or 86/89 | unchanged or 89 | Only update wording if child inventory is stale; keep non-emitting |

The target confidence can rise above 90 because the no-code/split proof is stronger than the old "C++ withheld" blocker. Completion remains below 90 because exact child pages and child-level source code still need callback implementation.

## Open Questions With Attempted Resolution

| Question | Research attempted | Current resolution |
| --- | --- | --- |
| Is UID0002Q7 one source emitter? | MCP function lookup, xrefs, bytes, decompile, by-structure C++ rule. | No. It is an internal index over multiple child spans. |
| Are raw packet starts callable helpers? | MCP `lookup_funcs` and `xrefs_to`; command-handler decompile. | No current route. They are raw no-function/no-xref source-shaped islands. |
| Does packet behavior require `CashShopRequest` ownership? | Command decompile and class/vtable/singleton refs. | No. Packet queue is dependency only. |
| Is the destructor-shaped island a normal destructor body? | Raw bytes, vtable/singleton refs, scalar deleting destructor decompile. | Unresolved source representation; split it as raw/no-route child and keep parent blank. |
| Are exact child source names proven? | Current docs/MCP symbols and decompile names checked. | Names are inferred/descriptive, not symbol-proven. |
| Standalone file vs `CreateUserDialogs` umbrella? | Current file docs and caller/source family reviewed. | Keep `NewUserMiscDialogPane.cpp` as canonical file candidate, umbrella caveat remains. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No generated coverage-report or tracker file should be manually edited by B013. If the callback creates child pages and validates them, generated reports should be refreshed by scoped validator/autogen behavior. If the supervisor needs manual review text, use:

```text
UID0002Q7 reviewed by B013: reclassify broad NewUserMiscDialogPane core range as non-emitting nested index; split exact child function/raw/table/padding pages before formal C++.
```

## Follow-Up Actions

1. Supervisor Gate 2 verification of the implemented target/support docs, exact child pages, validator output, and this updated ledger/checklist.
2. Supervisor only: run `execute_report` after Gate 2 passes. B013 must not run lifecycle/archive/execute commands.
3. No further B013 action is pending unless supervisor finds a Gate 2 defect.

## Confidence

Overall report confidence: high for owner/range/no-parent-C++ recommendation; medium-high for final source-facing child names.

Remaining blocker after callback: child-level formal C++ is intentionally not inserted. Exact child pages now exist with UIDs `0004GL` through `0004GX`, but method-body source still requires separate child-level source-quality review before emitter/C++ fields are populated.

## Validator Results

Scoped validators were run from `source-3/project-documentation` for every changed or created by-* file. All exited `0`.

| File | Command ID | Timestamp | Exit | Result |
| --- | --- | --- | ---: | --- |
| `by-memory/0x004fb630-0x004fbfcf.NewUserMiscDialogPaneConstructor.md` | `000000005880` | `2026-07-03T23:44:00-04:00` | 0 | UID assigned `0004GL`; generated refresh deferred. |
| `by-memory/0x004fbfcf-0x004fbfd0.NewUserMiscDialogPaneConstructorPadding.md` | `000000005881` | `2026-07-03T23:44:02-04:00` | 0 | UID assigned `0004GM`; generated refresh deferred. |
| `by-memory/0x004fbfd0-0x004fc00f.NewUserMiscDialogPaneRawCleanupIsland.md` | `000000005882` | `2026-07-03T23:44:04-04:00` | 0 | UID assigned `0004GN`; generated refresh deferred. |
| `by-memory/0x004fc010-0x004fc57e.NewUserMiscDialogPaneHandleCommand.md` | `000000005883` | `2026-07-03T23:44:06-04:00` | 0 | UID assigned `0004GO`; generated refresh deferred. |
| `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacket.md` | `000000005884` | `2026-07-03T23:44:08-04:00` | 0 | UID assigned `0004GP`; generated refresh deferred. |
| `by-memory/0x004fc5f0-0x004fc77c.NewUserMiscDialogPaneOnKeyDown.md` | `000000005885` | `2026-07-03T23:44:10-04:00` | 0 | UID assigned `0004GQ`; generated refresh deferred. |
| `by-memory/0x004fc780-0x004fc9e7.NewUserMiscDialogPaneShowControlHelp.md` | `000000005886` | `2026-07-03T23:44:12-04:00` | 0 | UID assigned `0004GR`; generated refresh deferred. |
| `by-memory/0x004fc9e8-0x004fca18.NewUserMiscDialogPaneHelpSwitchTable.md` | `000000005887` | `2026-07-03T23:44:14-04:00` | 0 | UID assigned `0004GS`; generated refresh deferred. |
| `by-memory/0x004fca20-0x004fcab8.NewUserMiscDialogPaneRawCreateRequestSender.md` | `000000005888` | `2026-07-03T23:44:16-04:00` | 0 | UID assigned `0004GT`; generated refresh deferred. |
| `by-memory/0x004fcab8-0x004fcac0.NewUserMiscDialogPanePacketHelperPadding.md` | `000000005889` | `2026-07-03T23:44:18-04:00` | 0 | UID assigned `0004GU`; generated refresh deferred. |
| `by-memory/0x004fcac0-0x004fcb04.NewUserMiscDialogPaneRawCancelRequestSender.md` | `000000005890` | `2026-07-03T23:44:20-04:00` | 0 | UID assigned `0004GV`; generated refresh deferred. |
| `by-memory/0x004fcb04-0x004fcb10.NewUserMiscDialogPaneReplyPadding.md` | `000000005891` | `2026-07-03T23:44:22-04:00` | 0 | UID assigned `0004GW`; generated refresh deferred. |
| `by-memory/0x004fcb10-0x004fccee.NewUserMiscDialogPaneHandleCreateCharacterReply.md` | `000000005892` | `2026-07-03T23:44:24-04:00` | 0 | UID assigned `0004GX`; generated refresh deferred. |
| `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md` | `000000005893` | `2026-07-03T23:44:26-04:00` | 0 | Target metadata updated; TMP child references resolved; generated refresh deferred. |
| `by-file/NewUserMiscDialogPane.md` | `000000005894` | `2026-07-03T23:44:28-04:00` | 0 | `ok:14`; TMP child references resolved; generated refresh deferred. |
| `by-class/NewUserMiscDialogPane.md` | `000000005895` | `2026-07-03T23:44:31-04:00` | 0 | `ok:14`; TMP child references resolved; generated refresh deferred. |
| `by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md` | `000000005896` | `2026-07-03T23:44:33-04:00` | 0 | `ok:1`; aggregate row updated; generated refresh deferred. |
| `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md --wait-generated` | `000000005897` | `2026-07-03T23:45:00-04:00` | 0 | `ok:1`; generated refresh completed. |

Generated refresh effects from command `000000005897`: `generated_refresh: completed`, generated refresh command/timestamp matched `000000005897` / `2026-07-03T23:45:00-04:00`; validator-owned generated reports refreshed; `auto-generated/NexusTK/login/NewUserMiscDialogPane.cpp` updated; `auto-generated/-ag-research-tracker.md` updated; validator-created autogen backups under `tools/validator_autogen_backup/20260703-234507`, `20260703-234511`, and `20260703-234513`. Warnings about unrelated `autogen_children_marker_missing` and `autogen_emitter_has_no_code` rows were emitted by the global generated refresh and were not target-specific failures.

## Changed Files

Changed in this pass:

- `tools/leaser/Agents/Agent-B013/research/0002Q7-NewUserMiscDialogPaneCoreAndPacketHelpers-source-quality.md`
- `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md`
- `by-memory/0x004fb630-0x004fbfcf.NewUserMiscDialogPaneConstructor.md` (`UID:0004GL`)
- `by-memory/0x004fbfcf-0x004fbfd0.NewUserMiscDialogPaneConstructorPadding.md` (`UID:0004GM`)
- `by-memory/0x004fbfd0-0x004fc00f.NewUserMiscDialogPaneRawCleanupIsland.md` (`UID:0004GN`)
- `by-memory/0x004fc010-0x004fc57e.NewUserMiscDialogPaneHandleCommand.md` (`UID:0004GO`)
- `by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacket.md` (`UID:0004GP`)
- `by-memory/0x004fc5f0-0x004fc77c.NewUserMiscDialogPaneOnKeyDown.md` (`UID:0004GQ`)
- `by-memory/0x004fc780-0x004fc9e7.NewUserMiscDialogPaneShowControlHelp.md` (`UID:0004GR`)
- `by-memory/0x004fc9e8-0x004fca18.NewUserMiscDialogPaneHelpSwitchTable.md` (`UID:0004GS`)
- `by-memory/0x004fca20-0x004fcab8.NewUserMiscDialogPaneRawCreateRequestSender.md` (`UID:0004GT`)
- `by-memory/0x004fcab8-0x004fcac0.NewUserMiscDialogPanePacketHelperPadding.md` (`UID:0004GU`)
- `by-memory/0x004fcac0-0x004fcb04.NewUserMiscDialogPaneRawCancelRequestSender.md` (`UID:0004GV`)
- `by-memory/0x004fcb04-0x004fcb10.NewUserMiscDialogPaneReplyPadding.md` (`UID:0004GW`)
- `by-memory/0x004fcb10-0x004fccee.NewUserMiscDialogPaneHandleCreateCharacterReply.md` (`UID:0004GX`)
- `by-file/NewUserMiscDialogPane.md`
- `by-class/NewUserMiscDialogPane.md`
- `by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md`

Validator-owned generated outputs refreshed after `--wait-generated`; no generated, coverage, validator-state, lifecycle/archive, or supervisor-ledger files were manually edited.

## Implementation Tracking Checklist

- [x] Target metadata: updated `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md` to `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000LX`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++.
- [x] Target status/reconstruction notes: replaced broad empty-emitter wording with explicit non-emitting nested-index/no-parent-C++ proof.
- [x] Target evidence: incorporated MCP session `3a33af0b` function inventory, xrefs, bytes, decompile facts, vtable/singleton refs, raw no-function/no-xref caveats, inline packet behavior, and rejected owner/helper-route alternatives.
- [x] Child split: created exact by-memory child pages for constructor, padding, raw cleanup, command handler, reply wrapper, key/help path, help handler, switch table, raw opcode `4` sender, helper padding, raw opcode `0x15` sender, reply padding, and reply handler.
- [x] Child metadata: validator assigned UIDs `0004GL` through `0004GX`; source-facing names and reconstructable/emitter dispositions were recorded; raw no-xref helper routes were not invented.
- [x] Support `by-file/NewUserMiscDialogPane.md`: updated UID0002Q7 row/status and source-placement notes at report-level detail.
- [x] Support `by-class/NewUserMiscDialogPane.md`: updated method inventory, no-parent-C++ explanation, command inline packet facts, reply parsing facts, and control-consumer caveats at report-level detail.
- [x] Support parent aggregate `by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md`: updated UID0002Q7 child row while preserving aggregate non-emitting status.
- [x] Preserve already-present facts: specialized controls remain consumer construction evidence only; `CashShopRequest` remains dependency only; `CreateUserDialogs` remains umbrella only.
- [x] Validators after callback: ran scoped validator for every changed by-* doc from `source-3/project-documentation` using `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`; all exited `0`.
- [x] Generated freshness after callback: ran focused `--wait-generated` validation on the target; command `000000005897` completed generated refresh at `2026-07-03T23:45:00-04:00`.
- [x] Report update after callback: updated ledger/checklist with applied/already-present states and validator command ids/timestamps/exit/ok details.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000005922","destination_path":"executed-b-agent-research/B013/0002Q7-NewUserMiscDialogPaneCoreAndPacketHelpers-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B013/research/0002Q7-NewUserMiscDialogPaneCoreAndPacketHelpers-source-quality.md","timestamp":"2026-07-03T23:53:34-04:00","uid":"0002Q7"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
