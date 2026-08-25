** TARGET-REPORT-UID:0002V9 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 0002V9 BoardListPaneCore Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0002V9] `by-memory/0x004729e0-0x00472bf5.BoardListPaneCore.md` assigned to [UID:000010] `BoardListPane` through [UID:0000HT] `BoardDialogs`, keep it reconstructable and emitter-routed, but keep the existing formal C++ marker-only on this aggregate page.
- Final disposition: the raw helper reachability blocker is resolved as a documented retained-no-direct-route source-shape issue, not as an ownership blocker. The aggregate is not ready for a broad partial body because it mixes three raw no-function/no-route helper bodies with two vtable-dispatched virtual methods. If source C++ is desired, split the five exact bodies into method-level children first.
- Required action: update target/support docs with current MCP evidence, source-facing names, no-code proof, and an implementation-ready exact split plan. Do not replace the marker with aggregate C++.
- Confidence: high for owner/emitter/range/vtable facts; medium-high for inferred method names and field names because no original symbols prove them.

## Supporting Research

## Target

- Target UID: `0002V9`
- Target path: `by-memory/0x004729e0-0x00472bf5.BoardListPaneCore.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `by-memory` Not-Covered Files - Reconstructable, assigned row `85/88`, reconstructable true, reports `0`.
- Current supervisor classification: report-only source-quality review for BoardListPane raw constructor/text/packet helper island, activation/draw virtuals, vtable slots, helper reachability, names, owner/emitter route, score readiness, and C++ disposition.
- Current scores and parent state: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:000010`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000010`, marker-only formal C++.

## Current Target State

- Existing metadata: `85/88`, owner/emitter [UID:000010] `BoardListPane`, reconstructable true.
- Existing owner/emitter/reconstructable state: correct. `BoardListPane` is the direct class owner and emits through [UID:0000HT] `BoardDialogs`.
- Existing C++/emitter state: formal block contains a marker comment saying the aggregate is covered through `BoardListPane`/`BoardDialogs` and no partial aggregate body is emitted until helper names/declarations are source-quality.
- Existing blockers: raw starts `0x004729e0`, `0x00472a30`, and `0x00472a90` are not IDA functions and have no direct xrefs; row item layout, selected-index field, inherited draw-mode byte, and final helper names are descriptive/inferred; aggregate body would mix method bodies and retained no-route helpers.
- Related target/support docs checked: target page, `by-class/BoardListPane.md`, `by-file/BoardDialogs.md`, `by-type/by-vtable/BoardArticleDialogVtableFamily.md`, `by-memory/0x00472070-0x004729dd.BoardListDialogCore.md` report, `by-memory/0x00472070-0x00477790.BoardArticleDialogs.md` report, `by-memory/0x004f3a50-0x004f4a77.ListPane.md`, `by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md`, `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`, `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`, `by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md`, `by-global/g_packetSender.md`, and `by-global/g_useEpfAssets.md`.

## Executive Recommendation

`0002V9` should remain the BoardListPane method/helper island and should not be reassigned, detached, or turned into a file-level helper. The raw constructor/text/packet helpers are real source-shaped bodies in the pane class neighborhood, but the current MCP pass again finds zero function objects, zero xrefs to their starts, and zero absolute pointer hits to the three raw entry addresses. Treat them as retained out-of-line/private helper bodies or recovered unreferenced overloads, not as padding and not as proof for a live packet path.

Recommended source-facing names for documentation are:

- `BoardListPane::BoardListPane` or `BoardListPane::InitializeListPane` for `0x004729e0-0x00472a27`, with a caveat that the ordinary constructor path is inlined in `BoardListDialog` and this retained body has no direct route.
- `BoardListPane::AppendBoardItem` for `0x00472a30-0x00472a88`, because it builds a row with `boardId` at offset `+0x00`, UTF-16 text at `+0x02`, and appends through `ListPane::AddEntry`.
- `BoardListPane::SendSelectedBoardRequestNoRoute` for `0x00472a90-0x00472b45`, because it sends opcode `0x3b`, subcommand `0x02`, selected board id, sentinel `0x7fff`, and EPF/legacy mode through `g_packetSender`, but has no direct route and is superseded for observed activation by `BoardListDialog::OpenSelectedBoard`.
- `BoardListPane::OnItemDoubleClick` for `0x00472b50-0x00472b63`.
- `BoardListPane::DrawItem` for `0x00472b70-0x00472bf5`.

If the supervisor wants C++ beyond the existing marker, split exact method children first:

| Proposed child | Range | Initial C++ disposition |
| --- | --- | --- |
| `BoardListPaneRawConstructor` | `0x004729e0-0x00472a27` | marker/no-route or first-draft only after class constructor policy is synchronized with inline construction in `BoardListDialog`. |
| `BoardListPaneAppendBoardItem` | `0x00472a30-0x00472a88` | candidate first-draft helper once `BoardListEntry` row declaration is placed. |
| `BoardListPaneSendSelectedBoardRequestNoRoute` | `0x00472a90-0x00472b45` | marker/no-route retained helper unless supervisor accepts an uncalled private helper body. |
| `BoardListPaneOnItemDoubleClick` | `0x00472b50-0x00472b63` | source-ready small virtual, dependent on `BoardListDialog::OpenSelectedBoard`. |
| `BoardListPaneDrawItem` | `0x00472b70-0x00472bf5` | source-ready virtual after `BoardListEntry`, `RectBounds`, GrafPort, and `SurfaceRenderCallbackTable` names are synchronized. |

## Supervisor Active Recheck

- Triggering instruction: Agent-B002 assignment `B002-report-0002V9-BoardListPaneCore-20260702`.
- Split repair required now: no report-only edits are allowed, so this report provides exact implementation-ready split recommendations rather than creating child pages.
- Source-bearing children in scope: every byte in `0x004729e0-0x00472bf5` is accounted for as raw body, modeled virtual, or `0xcc` padding. No hidden additional source-bearing body was found inside the range.

## Inference Research Guidance Check

- `by-structure.md` requires source-quality review beyond `85/85`, especially for raw helper liveness, field names, source placement, and C++ readiness.
- Existing docs were treated as leads. The current MCP pass reconfirmed the strongest facts and narrowed the unresolved raw-helper point into a no-direct-route disposition.
- IDA facts: function boundaries, xrefs, vtable slots, bytes, decompilation for modeled functions, no direct xrefs, and no pointer-pattern hits.
- Documentation evidence: BoardListPane/BoardDialogs/ListPane/GrafPort/PacketBuffer/global docs give source-facing helper names and owner rules.
- Inference: method names and row-field names are descriptive, not recovered original symbols.
- Wave2/Wave3 material was not used as authority. Stale generated names such as `g_pfnLockSurface`, `SetBkColor` for the wrong field, `g_pCashShopRequest`, and selected-entry-only wording for `0x004f3dc0` were rejected where current by-* docs supersede them.

## Heuristic / Inference Reanalysis And Validation

- Raw helper reachability: resolved as no-direct-route, not open. MCP `xref_query` finds no xrefs to `0x004729e0`, `0x00472a30`, or `0x00472a90`; `find_bytes` finds no little-endian pointers to those three starts. This is enough to document retained helper status and reject claims of proven live callers.
- Constructor source shape: `0x004729e0` calls `ListPane` construction at `0x004f3a50` with control/config id `0x202`, row height `0x0e`, flags `0/1/1`, then stores BoardListPane primary/secondary/tertiary vtables at `this+0`, `this+0xa0`, and `this+0xa4`. Inline stores in `BoardListDialog` remain the observed live construction route.
- Row helper source shape: `0x00472a30` writes a leading 16-bit board id and copies bounded UTF-16 row text into a stack row buffer before `ListPane::AddEntry` at `0x004f3c50`. Best row declaration is `struct BoardListEntry { uint16_t boardId; wchar_t text[...]; }`, with the exact array count still synchronized to the helper's stack bound.
- Packet helper source shape: `0x00472a90` reads selected index at inherited `this+0x134`, calls `ListPane::GetItem`, writes packet bytes through PacketBuffer helpers, uses [UID:0000SW] `g_useEpfAssets`, and sends 7 bytes through [UID:0000Q5] `g_packetSender`. It is semantically close to `BoardListDialog::OpenSelectedBoard` but lacks the dialog/session/screen-dimmer side effects and has no direct route.
- Activation virtual: `0x00472b50` is source-ready as `OnItemDoubleClick`: it performs two virtual `+0x1c` owner/container lookups and tail-jumps to `BoardListDialog::OpenSelectedBoard` at `0x004728a0`.
- Draw virtual: `0x00472b70` is source-ready in behavior: selection test through `ListPane::IsItemSelected`, active draw-color `0x25` for selected fill, shared surface fill/presentation through `dword_69B3FC`, text color `0x80` or `0x8f`, direct inherited draw-mode byte `this+0x70` clear/set, `MoveTo` using row rect midpoint plus 6, and wide text from row payload `entry+2`.
- Field/type names: `this+0x70` should be documented as inherited draw/blit mode byte; `this+0x134` as inherited selected index; `entry+0x00` as `boardId`; `entry+0x02` as UTF-16 display text. These are best current descriptive names and should be marked inferred.
- Rejected alternatives: no-owner/non-emitting rejected because vtable slots and constructor stores prove BoardListPane; BoardListDialog ownership rejected for the pane methods except as callback dependency; PacketBuffer/Socket/GrafPort/ListPane ownership rejected as dependency-only; aggregate C++ rejected because it would hide split/no-route facts.

## Evidence Standards Used

- MCP facts: server health, session `supervisor_resume_20260629`, `lookup_funcs`, `decompile`, `disasm`, `xref_query`, `get_bytes`, `find_bytes`, and bounded `search_text`.
- Documentation facts: current by-* support pages and executed reports.
- Negative evidence: no raw-start function objects, no raw-start xrefs, no raw-start pointer bytes, no code callers to modeled virtuals except vtable data slots.
- Evidence strength: high for binary facts; medium-high for source names because no PDB/source symbols prove exact original spellings.

## Evidence Checked

- IDA MCP session: endpoint `http://127.0.0.1:13337/mcp`, session `supervisor_resume_20260629`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, `strings_cache_size:2067`.
- MCP `lookup_funcs`: raw starts `0x004729e0`, `0x00472a30`, `0x00472a90`, boundary `0x00472bf5`, and successor `0x00472c00` are not functions; `0x00472b50` is `sub_472B50` size `0x13`; `0x00472b70` is `sub_472B70` size `0x85`.
- MCP `decompile`: `0x00472b50` climbs two virtual `+0x1c` links and calls `sub_4728A0`; `0x00472b70` tests selection, toggles byte `+0x70`, calls draw-state helpers and slot `dword_69B3FC`, moves to row midpoint, and draws UTF-16 text from `a3+2`.
- MCP `disasm`: `0x00472b50` has 7 instructions ending in `jmp sub_4728A0`; `0x00472b70` has 52 instructions and returns `retn 0Ch`.
- MCP `xref_query`: no xrefs to raw starts `0x004729e0`, `0x00472a30`, `0x00472a90`; one data xref to `0x00472b50` from vtable slot `0x00613d64`; one data xref to `0x00472b70` from vtable slot `0x00613d68`; vtable bases `0x00613ce8`, `0x00613d70`, `0x00613da0` each have stores at `0x004721d4/0x004721da/0x004721e4`, `0x00472566/0x0047256c/0x00472576`, and raw stores `0x00472a04/0x00472a0c/0x00472a16`.
- MCP `get_bytes`: `0x004729dd-0x00472c00` confirms padding and the raw/modeled body bytes documented in the target page.
- MCP `find_bytes`: little-endian pointers to raw starts `e0 29 47 00`, `30 2a 47 00`, and `90 2a 47 00` have zero matches; modeled virtual pointers `50 2b 47 00` and `70 2b 47 00` match only vtable cells `0x00613d64` and `0x00613d68`.
- MCP `search_text`: bounded listing search for `472A30` and `472A90` found only their own prologue lines in the target range, not branch/call sites.
- Existing report search terms: `0002V9`, `004729e0`, `00472bf5`, `BoardListPaneCore`, `BoardListPane Core`, `BoardListPane`, `BoardListDialog`, `BoardDialogs`, `00472a90`, `00472b70`.
- Relevant reports opened: `executed-b-agent-research/B001/0000ZK-BoardArticleDialogs.md`, `executed-b-agent-research/B004/0002EJ-BoardListDialogCore-source-quality.md`, and `executed-b-agent-research/B009/0000HT-BoardDialogs-empty-emitter-family-source-quality.md`.
- Failed/unavailable checks: first `get_bytes` call used the wrong schema before retrying with `regions`; first `find_bytes` structured call used an invalid pattern object before retrying with string patterns. No MCP outage occurred.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0002V9-001 | UID0002V9 owner/emitter route through BoardListPane and BoardDialogs is correct. | High | Vtable stores/slots, class/file docs, B001 split report. | Target status; `by-class/BoardListPane.md`; `by-file/BoardDialogs.md`. | incorporate | applied: target/class/file docs keep `0002V9 -> 000010 -> 0000HT`; validators `000000004525`, `000000004526`, `000000004534` passed. |
| C-0002V9-002 | Raw starts `0x004729e0`, `0x00472a30`, and `0x00472a90` are not IDA functions and have no direct route/pointer hits. | High | `lookup_funcs`, `xref_query`, `find_bytes`, `search_text`. | Target evidence/raw helper notes. | incorporate | applied: target evidence and class/file support now state no-function/no-xref/no-pointer/no-listing route; validators `000000004525`, `000000004526`, `000000004534` passed. |
| C-0002V9-003 | `0x004729e0` is a retained constructor/setup body installing BoardListPane vtables after shared ListPane construction. | High | Raw bytes and vtable xrefs. | Target behavior/inventory. | incorporate | applied: target covered range/behavior and class method table updated; validators `000000004525`, `000000004526` passed. |
| C-0002V9-004 | `0x00472a30` is best named `AppendBoardItem` / row append helper. | Medium-high | Raw bytes, `_wcscpy_s`, `ListPane::AddEntry`, row layout. | Target heuristic/naming notes. | incorporate | applied: target/class/file/aggregate support use `AppendBoardItem` with inferred `BoardListEntry` fields; validators `000000004525`, `000000004526`, `000000004528`, `000000004534` passed. |
| C-0002V9-005 | `0x00472a90` is best named `SendSelectedBoardRequestNoRoute`; it is not the observed activation route. | Medium-high | Packet bytes, no-route evidence, observed activation tail-jumps to BoardListDialog opener. | Target raw helper and no-code proof. | incorporate | applied: target/class/file/aggregate support use `SendSelectedBoardRequestNoRoute` and document observed activation through `BoardListDialog::OpenSelectedBoard`; validators `000000004525`, `000000004526`, `000000004528`, `000000004534` passed. |
| C-0002V9-006 | `0x00472b50` should be documented as `OnItemDoubleClick` and callback into `BoardListDialog::OpenSelectedBoard`. | High | Vtable slot `0x00613d64`, decompile/disasm, B004 report. | Target; `by-class/BoardListPane.md`. | incorporate | applied: target/class/vtable/file/aggregate support name `OnItemDoubleClick` and slot `0x00613d64`; validators `000000004525`, `000000004526`, `000000004527`, `000000004528`, `000000004534` passed. |
| C-0002V9-007 | `0x00472b70` should be documented as `DrawItem`; selected-row draw uses `SetDrawColor`, `dword_69B3FC`, `SetTextColor`, `MoveTo`, and row text at `entry+2`. | High | Decompile/disasm plus GrafPort/Surface docs. | Target; `by-class/BoardListPane.md`. | incorporate | applied: target/class/vtable/file/aggregate support name `DrawItem`, slot `0x00613d68`, row text at `entry+2`, and draw-mode caveat; validators `000000004525`, `000000004526`, `000000004527`, `000000004528`, `000000004534` passed. |
| C-0002V9-008 | Formal C++ should remain marker-only on the aggregate page unless exact method children are split first. | High | by-structure C++ rules, raw no-route helpers, mixed aggregate content, B009 marker precedent. | Target formal C++ guidance; implementation checklist. | incorporate | applied: target and class marker comments/guidance updated; no aggregate body added; validators `000000004525`, `000000004526` passed. |
| C-0002V9-009 | Exact child split is implementation-ready if supervisor wants C++ migration. | Medium-high | All subrange starts/ends/padding are verified. | Target range/split section; possible new by-memory children. | incorporate | applied as documentation only; child creation excluded per supervisor callback scope because target remained internally consistent without split. Target `Exact Split Plan` records the five children; validator `000000004525` passed. |
| C-0002V9-010 | Score can move modestly to `88/90` after current evidence is incorporated, but not higher. | Medium-high | Current MCP recheck plus unresolved original names and aggregate C++ cap. | Target metadata/score rationale. | incorporate | applied: target and class are `88/90`; aggregate child row synchronized; no higher score taken; validators `000000004525`, `000000004526`, `000000004528` passed. |

## Positive Evidence Summary

- Direct facts: BoardListPane vtable slots point to the modeled virtuals; constructor/setup bytes store all three BoardListPane vtable views; raw helper bodies are bounded by `0xcc` padding; modeled virtual decompilation matches the current page.
- Corroborating docs: `BoardListPane.md` already records class ownership and helper roles; `BoardDialogs.md` records the marker-only family disposition; ListPane/GrafPort/Surface/PacketBuffer/global docs provide source-facing dependency names.
- Strongest inference chain: the class identity comes from vtables and inline construction stores; raw helpers are source-authored because they have prologues, structured calls, and returns, but no route evidence means source docs must preserve no-direct-route caveats.

## IDA MCP Facts

- Function/range facts: `0x00472b50-0x00472b63` and `0x00472b70-0x00472bf5` are the only modeled functions in this target; raw bodies start at `0x004729e0`, `0x00472a30`, and `0x00472a90`.
- Data/table/padding facts: `0x004729dd-0x004729e0`, `0x00472a27-0x00472a30`, `0x00472a88-0x00472a90`, `0x00472b45-0x00472b50`, `0x00472b63-0x00472b70`, and `0x00472bf5-0x00472c00` are `0xcc` padding fences.
- Xref facts: only vtable data reaches the modeled virtuals; vtable-base xrefs include inline stores from `BoardListDialog` and the retained raw constructor/setup body.
- Vtable/global/type facts: BoardListPane primary table slot `0x00613d64 -> 0x00472b50`, `0x00613d68 -> 0x00472b70`; table bases `0x00613ce8`, `0x00613d70`, `0x00613da0`.
- Negative IDA facts: no direct xrefs or pointer-byte hits to the three raw starts.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004729e0-0x00472a27` | within UID0002V9 | retained BoardListPane constructor/setup body | true | BoardListPane | proposed child | no direct route; source-shaped bytes |
| `0x00472a27-0x00472a30` | within UID0002V9 | padding | false | none | n/a | `0xcc` |
| `0x00472a30-0x00472a88` | within UID0002V9 | retained row append helper | true | BoardListPane | proposed child | no direct route; best name `AppendBoardItem` |
| `0x00472a88-0x00472a90` | within UID0002V9 | padding | false | none | n/a | `0xcc` |
| `0x00472a90-0x00472b45` | within UID0002V9 | retained selected-board packet helper | true | BoardListPane | proposed child | no direct route; best name `SendSelectedBoardRequestNoRoute` |
| `0x00472b45-0x00472b50` | within UID0002V9 | padding | false | none | n/a | `0xcc` |
| `0x00472b50-0x00472b63` | within UID0002V9 | activation/double-click virtual | true | BoardListPane | proposed child | vtable slot `0x00613d64`; source-ready |
| `0x00472b63-0x00472b70` | within UID0002V9 | padding | false | none | n/a | `0xcc` |
| `0x00472b70-0x00472bf5` | within UID0002V9 | row draw virtual | true | BoardListPane | proposed child | vtable slot `0x00613d68`; source-ready behavior |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004729e0` | no xrefs; no pointer hits | retained constructor/setup body, not observed live route |
| `0x00472a30` | no xrefs; no pointer hits | retained append helper, not observed live route |
| `0x00472a90` | no xrefs; no pointer hits | retained packet helper, not observed live route |
| `0x00472b50` | `0x00613d64` data xref | BoardListPane vtable-dispatched activation/double-click method |
| `0x00472b70` | `0x00613d68` data xref | BoardListPane vtable-dispatched draw method |
| `0x00472b5e -> 0x004728a0` | tail jump | activation uses BoardListDialog selected-board opener |
| `0x00472a04/0x00472a0c/0x00472a16` | vtable base stores | retained constructor/setup installs BoardListPane views |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion: target page already records exact subranges, behavior, vtable slots, padding, no-xref caveat, owner/emitter route, and marker-only C++; `BoardListPane.md` records same method roles; `BoardDialogs.md` records UID0002V9 as a marker-only aggregate; B001/B009 accepted reports preserve the current assignment and marker.
- Existing docs that are stale/incomplete: target/class pages still describe raw helper reachability as open rather than resolved no-direct-route; method names and field names can be stronger and more source-facing; the score can rise after adding current MCP provenance and split/no-code proof.
- Generated/coverage report state: tracker row still shows `85/88`, reconstructable true, reports `0`; no generated/coverage files were edited in this report-only pass.

## Ranked Ownership Analysis

### 1. BoardListPane class under BoardDialogs

- Evidence for: BoardListPane vtable stores, BoardListPane vtable slots, `BoardListDialog` inline construction, class/file docs, B001 split report, and exact class-parent gate.
- Evidence against: final class declaration and row record are not source-final; raw helper starts lack live callers.
- Decision: accepted. Raw no-route caveats affect C++ shape and score, not ownership.

### 2. BoardListDialog

- Evidence for: `BoardListDialog` constructs/owns the pane and `OnItemDoubleClick` calls back into `BoardListDialog::OpenSelectedBoard`.
- Evidence against: the target methods install/use BoardListPane vtables and `this` is the pane. BoardListDialog is caller/owner-container, not direct method owner.
- Decision: rejected as direct owner; keep as support dependency.

### 3. BoardDialogs file-level helper

- Evidence for: board/article dialog family source bucket and file parent.
- Evidence against: exact direct class owner exists and clears the gate; file-level ownership would flatten class methods unnecessarily.
- Decision: rejected for direct owner; retained as emitter root through BoardListPane.

### 4. ListPane, GrafPort, Surface, PacketBuffer, Socket, globals

- Evidence for: target depends on those helpers/globals.
- Evidence against: each is a shared dependency with its own owner docs; dependency calls do not transfer ownership.
- Decision: rejected as owner candidates.

### 5. No-owner/non-emitting

- Evidence for: three retained raw starts have no live route.
- Evidence against: the modeled virtuals and vtable stores are unequivocally class-owned source; the raw bodies are source-shaped class helpers bounded inside the class island.
- Decision: rejected for the target. No-code marker is an aggregate-source policy, not no-owner/non-emitting metadata.

## Source Placement

- Recommended source placement: `BoardListPane` in the [UID:0000HT] `BoardDialogs` source family, likely `NexusTK/ui/dialogs/BoardDialogs.cpp` or a future split such as `BoardDialogs.cpp`/`ArticleDialogs.cpp` once file partitioning is settled.
- Why this fits: BoardListPane is constructed and consumed by BoardListDialog, uses board id rows, and is part of the board/article dialog vtable family.
- Rejected placements: `ListPane.cpp` for shared helpers only; `PacketBuffer.cpp` and `Socket.cpp` for packet serialization/transport only; `GrafPort.cpp`/`Surface.cpp` for draw dependencies only.
- Remaining uncertainty: final original source-file split and exact class header/interface names remain broad BoardDialogs-family questions.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts are listed in the Function / Child Inventory.
- Recommended split if accepted: create five exact by-memory children for the five source bodies and leave UID0002V9 as a non-emitting or marker-only split index/cluster summary, or keep UID0002V9 as the aggregate marker and add no child C++ yet.
- Do not merge `0x00472c00` into this page; successor raw ArticleListDialog/ArticleListPane family work begins after the padding at `0x00472bf5-0x00472c00`.
- Parent/container impact: no owner/emitter change is needed for the current aggregate. If children are created, each source-bearing child should route to [UID:000010] `BoardListPane`; padding remains documented in the parent/coverage context.

## Negative Evidence Summary

- Consumer ownership rejected: BoardListDialog uses/constructs the pane but does not own the pane methods.
- Raw helper live route rejected: xref, pointer-byte, and bounded listing searches do not find callers or pointer cells for `0x004729e0`, `0x00472a30`, or `0x00472a90`.
- Vtable-only dispatch is sufficient for modeled virtual method ownership but not enough to prove a source body for the three raw helpers.
- Generated aliases rejected: `g_pfnLockSurface` for `dword_69B3FC`, feature-local `SetTextColor` labels for `0x004b9660`, `g_pCashShopRequest` for `dword_67A7EC`, and selected-entry-only naming for `0x004f3dc0`.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names:
  - `sub_472B50` -> `BoardListPane::OnItemDoubleClick`
  - `sub_472B70` -> `BoardListPane::DrawItem`
  - raw `0x00472a30` -> `BoardListPane::AppendBoardItem`
  - raw `0x00472a90` -> `BoardListPane::SendSelectedBoardRequestNoRoute`
  - raw `0x004729e0` -> `BoardListPane::BoardListPane` or `BoardListPane::InitializeListPane`, with no-route/inline-constructor caveat.
- Proposed type names:
  - `BoardListEntry::boardId` at row `+0x00`.
  - `BoardListEntry::text` at row `+0x02`.
  - inherited `ListPane::m_selectedIndex` at pane `+0x134`.
  - inherited GrafPort/draw-mode byte at `+0x70`.
- IDA DB edits are not requested in this report-only phase.

## First-Draft C++ Recommendation

- Eligible for draft C++: numerically yes (`RECONSTRUCTABLE:TRUE`, nonblank emitter route, average score above 85). Source-shape wise, do not add aggregate C++ to UID0002V9 yet.
- Recommended code: keep the existing marker-only formal block on UID0002V9.
- Reason it preserves exact original behavior: no broad aggregate body is emitted that might invent live calls to no-route helpers or collapse five separate method bodies into one artificial source unit.
- Reason it matches plausible original source shape: a real source file would have class methods/private helpers, not a single method-cluster aggregate body. Exact child method pages or a synchronized class declaration pass are the correct next source shape.
- Inferred names to preserve in prose: `AppendBoardItem`, `SendSelectedBoardRequestNoRoute`, `OnItemDoubleClick`, `DrawItem`, `BoardListEntry::boardId`, `BoardListEntry::text`, `m_selectedIndex`, inherited draw-mode byte.
- Reason code should remain blank/marker-only on this page: the page is an aggregate with retained no-direct-route raw helpers and source-ready virtuals; formal C++ would either omit real bytes, fabricate routes, or mix unrelated method bodies outside an exact child split.
- Exact no-code proof: current MCP session proves no direct xrefs or pointer hits to three raw helper starts; observed activation uses the vtable virtual `0x00472b50` to call `BoardListDialog::OpenSelectedBoard`, not the raw packet helper; field/class declarations are not synchronized enough to make a final aggregate body defensible.

## Final Recommendation

- Exact changes recommended: add current MCP provenance and no-route evidence; replace "reachability remains open" wording with "no direct route found in current MCP xref/pointer/listing checks"; add source-facing helper names and field names with inferred/descriptive caveats; add exact split plan and marker-only no-code proof.
- Exact parent assignments recommended: no change, keep `CANONICAL_OWNER:000010`, `EMITTER_UIDS:000010`, `RECONSTRUCTABLE:TRUE`.
- Exact score recommended: `COMPLETION:88`, `CONFIDENCE:90` after documentation incorporation. Do not raise higher because original names/header layout/raw helper liveness remain unproven and aggregate C++ stays marker-only.
- Exact items left no-owner/non-emitting: none at target level. If split children are created, padding spans are ignored/padding and the raw packet helper should carry no-direct-route caveat.
- Future work outside this assignment: optional BoardDialogs family class declaration/source-file split; optional exact child creation for each method if supervisor chooses to move toward formal C++.

## Recommended Target Doc Changes

- Target path: `by-memory/0x004729e0-0x00472bf5.BoardListPaneCore.md`
- Incorporate:
  - MCP session `supervisor_resume_20260629` provenance and exact calls/results listed above.
  - No-route closure for raw starts, including zero xrefs and zero pointer-pattern matches.
  - Source-facing helper names and field names with inferred/descriptive caveats.
  - Function/child inventory with exact split candidates.
  - No-code proof for marker-only aggregate C++.
  - Score rationale for `88/90`.
- Metadata changes:
  - `COMPLETION:85` -> `88`
  - `CONFIDENCE:88` -> `90`
  - Keep `CANONICAL_OWNER:000010`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000010`, blank emitter position.
  - Keep formal C++ marker-only text; optionally update marker wording to mention no-direct-route raw helpers and exact split prerequisite.
- Historical/negative evidence to preserve: raw starts are real source-shaped bytes but no direct route; BoardListDialog owns the observed opener, not the pane raw packet helper; dependencies remain shared helper/global owners.

## Recommended Support Doc Changes

- Support path: `by-class/BoardListPane.md`
  - Add current no-route closure for `0x004729e0`, `0x00472a30`, and `0x00472a90`.
  - Update method table names to `AppendBoardItem`, `SendSelectedBoardRequestNoRoute`, `OnItemDoubleClick`, and `DrawItem` as inferred/descriptive names.
  - Add row layout fields `boardId` and `text`, inherited selected-index/draw-mode caveats, and no-code/split prerequisite.
  - Recommended metadata: `85/88` -> `88/90`, owner/emitter unchanged.
- Support path: `by-file/BoardDialogs.md`
  - Update the `BoardListPane` proposed-content row with the source-quality disposition: exact child/source names resolved to descriptive level, raw helpers no-direct-route, aggregate marker retained, exact split plan available.
  - Score change optional: file already at `87/88`; do not require file score movement from this narrow pane pass unless supervisor wants the BoardDialogs row synchronized.
- Support path: `by-type/by-vtable/BoardArticleDialogVtableFamily.md`
  - No metadata change required. Optional support note: BoardListPane slots `0x00613d64`/`0x00613d68` now have source-facing names `OnItemDoubleClick` and `DrawItem`.
- Support path: `by-memory/0x00472070-0x00477790.BoardArticleDialogs.md`
  - If edited in a callback, update the child row for UID0002V9 from `85/88` to `88/90` and mention raw helper no-route closure plus marker-only aggregate C++.

## Score And Metadata Recommendation

- Current score/metadata: `85/88`, owner/emitter [UID:000010], reconstructable true, marker-only C++.
- Recommended score/metadata: `88/90`, owner/emitter/reconstructable unchanged, marker-only C++ retained.
- Score rationale and reason not higher/lower:
  - Higher than current because this pass adds current MCP provenance, current no-route closure, pointer-pattern negative evidence, source-facing method names, dependency-name normalization, and exact split/no-code plan.
  - Not higher than `88/90` because raw helper original liveness remains unproven, exact original method names and class/header declarations remain inferred, row buffer bound/type is not final-source audited, and aggregate formal C++ remains marker-only.
- Score-improvement attempt:
  - Raw-helper reachability: checked function records, xrefs, pointer bytes, and bounded listing text; resolved as no-direct-route.
  - Field names: checked ListPane/GrafPort/PacketBuffer/global docs; proposed best descriptive names with caveats.
  - Method names: ranked descriptive names and rejected generated/raw labels.
  - C++ readiness: considered aggregate C++, exact split C++, and marker-only; recommended marker-only aggregate plus split plan.
- Metadata fields to leave unchanged: owner, emitter, reconstructable, emitter position.

## Open Questions With Attempted Resolution

- Raw helper callers: current result is evidence-backed unresolved/no-direct-route. Checked current MCP function model, xrefs, pointer bytes, and listing text; no direct route exists. Future evidence that would change this: a vtable/table pointer, branch/call target, or source/header proof.
- Exact original method names: no PDB/source symbols found. Best descriptive names are safe for documentation and should be marked inferred.
- `BoardListEntry` exact length: row text begins at `+0x02`; helper uses a bounded stack copy with `0x100` wide-character count. Formal C++ should wait for synchronized declaration or exact child insertion to avoid row-size mismatch.
- Inherited draw-mode byte `+0x70`: current GrafPort and pane paint docs support inherited draw/blit-mode wording. Exact original field spelling remains a confidence cap only.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual `-coverage-report.md` edit is requested during this report-only phase. If the supervisor accepts and manually updates `by-memory/-coverage-report.md`, suggested row text is:

```text
      - [UID:0002V9][0x004729e0-0x00472bf5.BoardListPaneCore](by-memory/0x004729e0-0x00472bf5.BoardListPaneCore.md) 0x004729e0-0x00472bf5 | raw constructor/helper island plus virtual methods | BoardListPaneCore : reconstructable : 88% : strong : Current MCP session supervisor_resume_20260629 reconfirms BoardListPane raw constructor/setup, AppendBoardItem, no-route selected-board packet helper, OnItemDoubleClick, DrawItem, vtable slots 0x00613d64/0x00613d68, vtable stores, internal padding, zero xrefs/pointer hits to raw starts, source-facing dependency names, and marker-only aggregate C++ with exact split plan.
```

Reason B agent must not apply it directly: `-coverage-report.md` is outside report-only write scope and is supervisor/validator-owned.

## Follow-Up Actions

- Supervisor actions: validate this report; if accepted, send an implementation callback for target/support doc updates and optional exact child split.
- A-agent actions: none required.
- B002 future research actions: only if assigned, implement accepted documentation updates or split exact children.

## Confidence

- Recommendation confidence: high for keeping owner/emitter and marker-only aggregate disposition.
- Score confidence: medium-high for `88/90`.
- Remaining uncertainty: original method/header spellings, final row declaration, and whether retained raw helpers were compiled from unused private methods or an indirect route not represented by current IDA xrefs.

## Validator Results

- Commands run from `source-3/project-documentation`:
  - `python .\tools\validator.py --mode file --file by-memory\0x004729e0-0x00472bf5.BoardListPaneCore.md --apply --queue-timeout 240` -> command `000000004525`, `ok: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-class\BoardListPane.md --apply --queue-timeout 240` -> command `000000004526`, `ok: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-type\by-vtable\BoardArticleDialogVtableFamily.md --apply --queue-timeout 240` -> command `000000004527`, `ok: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00472070-0x00477790.BoardArticleDialogs.md --apply --queue-timeout 240` -> command `000000004528`, `ok: 1`, `generated_refresh: deferred`.
  - `python .\tools\validator.py --mode file --file by-file\BoardDialogs.md --apply --queue-timeout 240` -> command `000000004534`, `ok: 1`, `generated_refresh: deferred`.
- Results: all scoped validators for changed by-* files passed.
- Unresolved validator warnings/errors: none. Generated-refresh state is deferred for all five scoped validator runs; validator also performed its normal registry/stats incremental updates.

## Changed Files

- Created:
  - `tools/leaser/Agents/Agent-B002/research/0002V9-BoardListPaneCore-source-quality.md`
- Modified:
  - `by-memory/0x004729e0-0x00472bf5.BoardListPaneCore.md`
  - `by-class/BoardListPane.md`
  - `by-file/BoardDialogs.md`
  - `by-type/by-vtable/BoardArticleDialogVtableFamily.md`
  - `by-memory/0x00472070-0x00477790.BoardArticleDialogs.md`
  - `tools/leaser/Agents/Agent-B002/research/0002V9-BoardListPaneCore-source-quality.md`
- Renamed:
  - none
- Report execution: not run. B agents must not run `tools/validator.py execute_report`, any `execute_report` variant, registry lifecycle command, manual report move, or equivalent report execution/archive command.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation: accepted for implementation callback by supervisor on 2026-07-02 with exact scope.
- [x] Target/support docs to update: `by-memory/0x004729e0-0x00472bf5.BoardListPaneCore.md`, `by-class/BoardListPane.md`, `by-file/BoardDialogs.md`, `by-type/by-vtable/BoardArticleDialogVtableFamily.md`, and `by-memory/0x00472070-0x00477790.BoardArticleDialogs.md` were updated.
- [x] Current target state and actual evidence checked recorded: MCP session provenance, `lookup_funcs`, `decompile`, `disasm`, `xref_query`, `get_bytes`, `find_bytes`, `search_text`, support docs, and old report search terms/results were recorded in the report and incorporated into target/support docs.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: ledger rows C-0002V9-001 through C-0002V9-010 now show applied or excluded-with-reason proof.
- [x] Metadata/score changes to apply: target `85/88` -> `88/90`; class `BoardListPane` `85/88` -> `88/90`; owner/emitter/reconstructable unchanged.
- [x] Score-limiting blockers researched to resolution: raw-helper reachability resolved as no-direct-route after xref/pointer/listing checks; field/method names resolved to best descriptive names with explicit inferred caveats; aggregate C++ resolved as marker-only with exact split prerequisite.
- [x] Owner/emitter/reconstructable changes to apply: none; kept `0002V9 -> 000010`, `000010 -> 0000HT`, and `RECONSTRUCTABLE:TRUE`.
- [x] Split/rename/new-child changes to apply: no child pages created in this callback per supervisor scope; exact children documented as split-first plan because target stayed internally consistent without the split.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: BoardListPane/BoardDialogs placement preserved; padding fences documented; no IDA DB edits requested or made.
- [x] First-draft C++ or no-code proof to apply: target aggregate marker-only retained; exact no-code proof and split-first C++ plan added.
- [x] Third-party import directive to apply or confirm not applicable: not applicable.
- [x] Exact target/support doc facts to incorporate at report-level detail: raw byte roles, no-route evidence, vtable slots/stores, dependency names, field/type names, rejected alternatives, score rationale, and split plan incorporated.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: raw starts are not proven live; BoardListDialog is callback dependency, not pane method owner; dependency/helper owner candidates rejected; stale generated aliases rejected.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale: generated aliases only used as rejected leads, not authority.
- [x] Open questions to close or document as evidence-backed unresolved: original method names, exact row buffer declaration, and no-route raw helper liveness documented with evidence and score/C++ impact.
- [x] Validators to run after implementation callback:
  - `python .\tools\validator.py --mode file --file by-memory\0x004729e0-0x00472bf5.BoardListPaneCore.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-class\BoardListPane.md --apply --queue-timeout 240`
  - Add scoped validators for `by-file\BoardDialogs.md`, `by-type\by-vtable\BoardArticleDialogVtableFamily.md`, and/or `by-memory\0x00472070-0x00477790.BoardArticleDialogs.md` only if edited.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: all scoped validators reported `generated_refresh: deferred`; manual `by-memory/-coverage-report.md` row remains supervisor-owned and was not applied.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded: commands `000000004525`, `000000004526`, `000000004527`, `000000004528`, and `000000004534`.
- [x] Generated report refresh state recorded: all five scoped validator runs reported `generated_refresh: deferred`; no manual coverage/tracker text applied.
- [x] Remaining unapplied accepted items listed with exact blocker: child pages excluded by supervisor scope because target stayed internally consistent; manual coverage row excluded as supervisor-owned.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004543","destination_path":"executed-b-agent-research/B002/0002V9-BoardListPaneCore-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0002V9-BoardListPaneCore-source-quality.md","timestamp":"2026-07-02T14:15:56-04:00","uid":"0002V9"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
