** TARGET-REPORT-UID:0002D9 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# 0002D9 FittingRoomScrollPane UpdatePositionFromCursor Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation implemented by B001: the misleading `FittingRoomScrollPane::UpdateThumbDragScroll(int localX, int localY)` reconstruction is replaced with source-ready `void FittingRoomScrollPane::UpdatePositionFromCursor(int localY, int localX)`.
- Final disposition implemented: [UID:0002D9] remains a reconstructable exact method owned and emitted by [UID:000054] `FittingRoomScrollPane`, routed through [UID:0000JE] `FittingRoom` to `NexusTK/cashshop/FittingRoom.cpp`.
- Completed callback work: applied the exact target arithmetic and callback source shape, repaired the Y/X contract in the immediate caller/input/hit-test support, added compile-visible declarations for [UID:000053] `FittingRoomListPane` and [UID:000054] `FittingRoomScrollPane`, corrected the callback's first parameter to orientation, nested the scroll declaration as the first list-class child, granted narrow list friendship for private scroll state, normalized every emitted list/scroll child to the sole current `m_scrollPosition` / `m_scrollRange` vocabulary, and preserved the exact range without split or merge.
- Current target metadata: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:000054`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000054`, `EMITTER_POSITION_OPTIONAL:80`.
- Current support metadata: [UID:000053] is `88/90`, retains canonical owner/emitter [UID:0000JE], and emits at source position `10`; [UID:000054] is `90/92`, retains canonical owner [UID:0000JE], physically emits through [UID:000053], and uses child position `10`.
- Supervisor-owned manual reconciliation is complete: every exact accepted class/file/memory row below was applied and serially validated by the supervisor under commands16777-command16779; B001 did not edit manual coverage.
- Confidence: very strong for binary behavior, ABI, formula, range, class owner, callback inlining, legal access, declaration order, and source route; strong for stripped source spellings and the two otherwise-unreferenced bytes surrounding the packed list selection index.

## Supporting Research

- Lifecycle/status: accepted implementation callback and the bounded Gate 2 vocabulary repair are complete by B001. Supervisor-owned independent Gate 2 for report SHA256 `D9FEBCA48DFDDC260760C5EAC56A5D654DDF4D5C8F20074CB5609C72879FA51A` historically verified D1-D10, all seven managed blocks, layouts, ordering, target/callback bodies, validators, generated command16722 shape, marker removal, and zero leases, but failed because four already-emitting list children still used undeclared historical field aliases and current support prose retained superseded method/accessor labels. The later supervisor-owned Gate 2 audit for SHA256 `43E62A837480CDDADEFFC020636DD08B08730E0288E1ED472185808890ACCB98` records that D1-D16 and all seven formal blocks passed independent serial scoped validation and that its final `by-file/FittingRoom.md --wait-generated` check exited `0` with `ok:1`; the audit does not publish a command ID or timestamp, so none is attributed here. That later Gate 2 failed only because the then-current manual plan omitted UID0002DI/UID0002DN/UID0002DS. Those technical and report-plan defects are repaired, and the supervisor has now applied and validated the complete manual handoff. Only fresh exact-artifact Gate 1, independent Gate 2, and supervisor report execution remain.
- Healthy live IDA MCP was mandatory and remained available throughout the pass. Evidence-time endpoint was `http://127.0.0.1:13337/mcp`, database id `9b0396a3`, session `c7c1c893-ff33-4337-a146-6bed07176452`, with Hex-Rays and analysis ready.
- Gate 1 repair MCP recheck remained healthy on session `2d6016ec-7727-469e-9076-1b846e726bbd`: `server_health` returned `status:ok`, the same IDB/input/image base, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`. The repair used fresh read-only constructor/list-update/callback/reset/input/raw-helper disassembly and decompilation; no fallback-only conclusion was added.
- Current IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; input executable reported by MCP: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`; image base `0x00400000`.
- The prior executed B002 cluster report was read as historical lead material. It explicitly lacked live MCP, got the coordinate order and target formula wrong, invented guards absent from the binary, and treated primary vtable slot `+0x1c` as an owner-specific accessor. Those conclusions are not reused as authority.
- Historical report-preparation generated checkpoint was validator command `000000016699`, refreshed `2026-07-23T00:15:34-04:00`, SHA256 `FB86CE4488047FAD0BB5F008C2DD135BA6BBF405FACEEC5FCAE2559B4D260F53`, with stale target source and UID000053/UID000054 Empty Emitter Markers.
- Historical first-callback generated checkpoint is command `000000016722`, refreshed `2026-07-23T01:08:28-04:00`, source `deferred-generated-refresh`, SHA256 `987A1973C1EA97D51FCC710E5160493B00F11FCDD8E56A7B1A5034A36AF1F14E`, `89,341` bytes / `2,568` lines. It closed the class markers and declaration order but exposed undeclared historical field aliases in four list-child definitions.
- Historical bounded vocabulary-repair callback checkpoint G2 is B001 command `000000016738`, refreshed `2026-07-23T01:37:33-04:00`, source `deferred-generated-refresh`, SHA256 `77F61321FDFD17411B5F4D5731BA65F1EB753DB69F73D7F43150953615937B01`, `89,331` bytes / `2,568` lines. It first demonstrated closure of the undeclared member/accessor vocabulary defect after the B001 callback.
- Historical post-repair generated checkpoint G3 is command `000000016762`, refreshed `2026-07-23T02:01:00-04:00`, source `foreground-generated-refresh`, SHA256 `CBAC3BAD71F16100DD5A4AE7788867759CA3288BE5CF8C3AF99ECD15DF44C9B7`, `89,333` bytes / `2,568` lines.
- Supervisor wait-generated checkpoint G4 is command `000000016779`, refreshed `2026-07-23T02:26:03-04:00`, source `foreground-generated-refresh`, SHA256 `A50D45B359DB5F78334A62D5E4837E1C3D0D89E6C9930DE67D67BB97930FD517`, `89,333` bytes / `2,568` lines. The latest live header advanced without body drift to current checkpoint G5 command `000000016780`, refreshed `2026-07-23T02:26:09-04:00`, source `foreground-generated-refresh`, with the same SHA256 and metrics. Current code has zero `m_currentPosition`, `m_maxPosition`, `m_maxScrollPosition`, `GetOwnerListPane`, or `GetOwnerPane` occurrences; `m_scrollPosition` occurs `32` times, `m_scrollRange` occurs `18` times, and `UpdatePositionFromCursor` occurs `4` times. It retains one friend declaration, one target body, one callback body, and no UID000053/UID000054 Empty Emitter Marker. `UpdateThumbDragScroll` survives only in the immutable by-memory filename comment, not as current source vocabulary; unrelated Empty Emitter Markers elsewhere in the generated file are outside this target's accepted scope.

## Target

- Target UID: `0002D9`.
- Additional target UIDs: none.
- Declared-target inventory: [UID:0002D9] `by-memory/0x0041e970-0x0041eb24.FittingRoomScrollPaneUpdateThumbDragScroll.md`, exact source-authored class method body.
- Target path: `by-memory/0x0041e970-0x0041eb24.FittingRoomScrollPaneUpdateThumbDragScroll.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md`, `## by-memory` / `### Not-Covered Files - Reconstructable`.
- Historical tracker assignment checkpoint: command `000000016699`, row `87/89`, average `88.0`, reconstructable `true`, zero direct/additional/total reports.
- Current supervisor classification: callback and bounded Gate 2 vocabulary repair implemented; awaiting fresh exact-artifact Gate 1 and independent Gate 2 before supervisor lifecycle execution.
- Current scores and parent state: `92/94`, owner/emitter [UID:000054], reconstructable true, emitter position `80`.

## Current Target State

- Current metadata: `COMPLETION:92`, `CONFIDENCE:94`, `CANONICAL_OWNER:000054`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000054`, `EMITTER_POSITION_OPTIONAL:80`.
- Current C++/emitter state: the exact formal emits through [UID:000054] and preserves localY/localX order, both cursor/origin passes, signed branch-specific formulas, observed clamp asymmetry, no invented guards, inherited `GetParentPane`, and source callback shape.
- Current target identity D1: SHA256 `9E94030BA815BD9B1EA430D328A811E2E8C82651D883E9F8C4F268573BDD3152`, `17,788` bytes, `201` physical lines.
- Current callback-owner class identity D2: `by-class/FittingRoomListPane.md`, SHA256 `4E8898647C2C46A0818C550C2DCE7C83A49078C2BA68B2825708D1B4458D2E2A`, `64,113` bytes, `239` lines. It is `88/90`, owned/emitted by [UID:0000JE] at position `10`, supplies the complete `0x12c` declaration/callback/children route, and uses only the current scroll-state vocabulary.
- Current owner class identity D3: `by-class/FittingRoomScrollPane.md`, SHA256 `0259B2BA2A0157D3C5E0985612EAFD70AA87BD6FB82ED1F18C0B22CE6632C077`, `37,504` bytes, `245` lines. It is `90/92`, canonically owned by [UID:0000JE], physically emitted through [UID:000053] at position `10`, supplies the complete `0x110` declaration/friend/children route, and presents only `GetParentPane`, `UpdatePositionFromCursor`, `m_scrollPosition`, and `m_scrollRange` as current source vocabulary.
- Current process identity D4: UID0002D5 SHA256 `F6764DDFF7E4934F3DC4282B83D4791AC35C07EBE814F226E4363123286B9ED0`, `14,815` bytes / `145` lines.
- Current mouse identity D5: UID0002D2 SHA256 `FE43AFD78CE69F205E663AC33A13885BE3685258152E479C2F751DF6AAF59D0F`, `18,176` bytes / `221` lines.
- Current hit-test identity D6: UID0002D8 SHA256 `BA15FBB6E2CB985031337DC954C832724E4CF11C1C0DA0EDDC4334FB358F9798`, `17,523` bytes / `223` lines.
- Current callback identity D7: UID0002DH SHA256 `73AE36F9D3A26BFF011BD65D0A62FD02EC6647570C8CE419ED3254BC0A2125F2`, `11,436` bytes / `114` lines.
- Current reset identity D8: UID0002DB SHA256 `C9837859EEC5ED436B18610A99AF328D30CEE196B0642C3A8A1A253E6DA56C48`, `14,210` bytes / `126` lines.
- Current source-file identity D9: `by-file/FittingRoom.md`, SHA256 `0FB4E694BA6A62079403D2A7001227BA978BE95438B3EF1724EFFF3FBBC0F9DC`, `159,946` bytes / `337` lines, score `88/90`, projected folder `NexusTK/cashshop/`.
- Current aggregate identity D10: [UID:0000WR], SHA256 `3A5499C6CF659C39AEB495A211CC5286D5878A189AEA0CA3EDB39599E7E251B3`, `71,830` bytes / `253` lines, score `88/89`, blank aggregate C++.
- Current UID0002DF identity D11: `by-memory/0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar.md`, SHA256 `CF47467967DEE7F33D3BB94E4760A2CB09B2CDB7B7FEC9D0607204E929BE7454`, `16,702` bytes / `185` lines.
- Current UID0002DI identity D12: `by-memory/0x0041f100-0x0041f219.FittingRoomListPaneResetScrollPosition.md`, SHA256 `8784FC883BFDFC69AE5AB730B0778312715779BB110722B6D19299983DB480DE`, `17,974` bytes / `149` lines.
- Current UID0002DN identity D13: `by-memory/0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md`, SHA256 `1642A41692D412E98079CE7AA937A61347294C3E56397B761A8577ABBC8F21DA`, `35,047` bytes / `256` lines.
- Current UID0002DS identity D14: `by-memory/0x00420840-0x00420949.FittingRoomListPaneOnScrollStep.md`, SHA256 `779FE30399760CB4E229055D358983877DD46231A89832C95CC0FC7E2CCA0950`, `13,445` bytes / `128` lines.
- Current supervisor-owned manual state for D12-D14: the supervisor applied and validated the exact UID0002DI `88%`, UID0002DN `88%`, and UID0002DS `88%` no-loss rows under command16779. The rows now preserve their current `88/91`, `88/90`, and `88/91` ordinary metadata/formal state, current member vocabulary, and complete owner/emitter route. B001 did not edit the manual file.
- Current UID000494 identity D15: `by-memory/0x0041e7f0-0x0041e8af.FittingRoomScrollPaneBeginPartPressRaw.md`, SHA256 `50F1723A26320EA3C7798F6EBC9E54197299CFF8B5EB0AFDF80F57EC6E165F28`, `11,533` bytes / `123` lines.
- Current UID0002D7 identity D16: `by-memory/0x0041e4f0-0x0041e777.FittingRoomScrollPaneGetPartRect.md`, SHA256 `9169002838BA495EFD730337172DC9C82221BAD3DAC9F93583095000427DD8F2`, `17,491` bytes / `254` lines.
- Historical first-callback generated checkpoint G1 is command `000000016722`, SHA256 `987A1973C1EA97D51FCC710E5160493B00F11FCDD8E56A7B1A5034A36AF1F14E`, `89,341` bytes / `2,568` lines.
- Historical repaired callback checkpoint G2 is `auto-generated/NexusTK/cashshop/FittingRoom.cpp` command `000000016738`, refreshed `2026-07-23T01:37:33-04:00`, source `deferred-generated-refresh`, SHA256 `77F61321FDFD17411B5F4D5731BA65F1EB753DB69F73D7F43150953615937B01`, `89,331` bytes / `2,568` lines; it is retained as bounded B001 callback evidence.
- Historical generated checkpoint G3 is `auto-generated/NexusTK/cashshop/FittingRoom.cpp` command `000000016762`, refreshed `2026-07-23T02:01:00-04:00`, source `foreground-generated-refresh`, SHA256 `CBAC3BAD71F16100DD5A4AE7788867759CA3288BE5CF8C3AF99ECD15DF44C9B7`, `89,333` bytes / `2,568` lines.
- Supervisor wait-generated checkpoint G4 is command `000000016779`, refreshed `2026-07-23T02:26:03-04:00`, SHA256 `A50D45B359DB5F78334A62D5E4837E1C3D0D89E6C9930DE67D67BB97930FD517`, `89,333` bytes / `2,568` lines. Current generated checkpoint G5 is command `000000016780`, refreshed `2026-07-23T02:26:09-04:00`, source `foreground-generated-refresh`, with the same SHA256 and metrics. It contains one complete list declaration before one complete scroll declaration, one friend declaration, one target body, one callback body, zero UID000053/UID000054 Empty Emitter Markers, and zero current-code occurrences of the superseded field/accessor vocabulary. Current counts are `m_scrollPosition=32`, `m_scrollRange=18`, and `UpdatePositionFromCursor=4`. `UpdateThumbDragScroll` appears only in the immutable source-page filename comment, not as a source declaration/call; unrelated Empty Emitter Markers are not target failures.
- Current manual roots after supervisor validation are: `by-class/-coverage-report.md` SHA256 `4141F8751FEDA5524D90BEBBD04DAC38B4EE6EEB292DC911CC7F69BEB86C9DA3`, `257,954` bytes / `624` lines; `by-file/-coverage-report.md` SHA256 `0373F1963A562013ECC49FCBA17CDFA63661311CA38BDA37E2D31F7A1B8F72C0`, `154,908` bytes / `317` lines; and `by-memory/-coverage-report.md` SHA256 `620E7433D9758A4D63E77BCC68A9A8DBF2EC55A000FB0F4B5B29770EADFABDB8`, `1,991,305` bytes / `4,574` lines. Every exact row retained below occurs once in its intended root, including inserted UID000493/UID000494 and UID0002DI/UID0002DN/UID0002DS.
- Callback blockers resolved in ordinary docs: actual Y/X argument order, signed arithmetic, clamp asymmetry, zero/negative-span behavior, return type, owner virtual identity, callback source shape, callback first parameter, child nullability, source method name, both class declarations, legal cross-class access, compile-visible source ordering, owner/emitter nesting, exact positions, and one declaration/body/prose vocabulary for current/range/accessor/method names across every associated emitter.
- Current report artifact/lifecycle status: active post-callback, post-repair, post-supervisor-manual-reconciliation report. B001 ran only scoped ordinary file validators; no B001 report lifecycle command, archive move, IDA mutation, manual coverage edit, or generated-file edit occurred. Only fresh Gate 1, independent Gate 2, and supervisor lifecycle execution remain.

## Executive Recommendation

- Implemented direct semantic owner and emitter [UID:000054] `FittingRoomScrollPane`; source root remains [UID:0000JE] `FittingRoom`.
- Implemented source-facing `UpdatePositionFromCursor`. The method runs for thumb and non-thumb active parts, so historical `UpdateThumbDragScroll` remains rejected as too narrow.
- Implemented ABI `(int localY, int localX)`. The first stack argument is the Y component and pairs with `Point +0x00` / object `+0x108`; the second is X and pairs with `Point +0x04` / object `+0x10c`.
- Implemented the tail as a source call to `FittingRoomListPane::OnScrollPositionChanged(unsigned char orientation, short oldPosition, short newPosition)` through inherited `Pane::GetParentPane()`. Compiler-inlined cross-class writes remain binary evidence rather than handwritten source.
- Implemented a complete [UID:000053] `ControlPane`-derived declaration at file position `10`, including the callback, exact fields, size guard, and `[[CHILDREN]]`.
- Implemented [UID:000054] as the first [UID:000053] child at position `10`, with its complete declaration and `friend class FittingRoomListPane`. The list type is complete for UID0002D9, and the scroll type is complete for later list child definitions.
- Implemented [UID:0002D5] position `70`, [UID:0002D9] position `80`, and [UID:0002DB] position `90` beneath the nested scroll declaration.
- No split, merge, reclassification, new file, new UID, or IDA mutation is warranted.

## Supervisor Active Recheck

- Trigger: the supervisor assigned UID0002D9 specifically to resolve arithmetic, argument, source-name, C++, and ownership blockers rather than restating the current `87/89` page.
- Split repair: not required. MCP proves one modeled function at `0x0041e970` of size `0x1b4`, exclusive end `0x0041eb24`.
- Source-bearing support readiness: the target, immediate dispatcher, mouse input bridge, hit-test signature, owner callback, [UID:000053] list declaration, and [UID:000054] scroll declaration are implemented and validator-accepted. The raw helper split remains [UID:000493]/[UID:000494] beneath non-emitting [UID:0002DA].
- UID000053 recheck: historical blank formal and no-declaration generated output are resolved. Its complete declaration, constructor-owned `0x110` scroll child at `+0x11c`, and UID000054 friendship now support the direct `+0xfe/+0x100/+0x102` accesses and UID0002D9 callback call legally.
- No blocker is forwarded as "future investigation." Remaining uncertainty is limited to stripped spellings and the semantic names of the otherwise-unreferenced list bytes at `+0x120/+0x123`; the formal uses source-facing selection-state names and an exact local packed state band rather than raw offsets or IDA labels.

## Inference Research Guidance Check

- `by-structure.md` requires exact by-memory bodies to contain only their own range and class pages to carry class responsibility/declaration with `[[CHILDREN]]`. The recommendation therefore places only the method body on UID0002D9 and only the declaration/field layout on UID000054.
- Existing documentation was treated as fallible. The historical managed target C++, B002 formula, x-first event prose, `GetOwnerListPane`, sender-pointer callback, and blank-class policy were rechecked, rejected where contradicted, and replaced or historicalized in D1-D10.
- Direct IDA facts, current-document evidence, and source-shape inference are labeled separately. Exact instructions/bytes/offsets/calls are direct facts; accepted `Point` ordering and Pane vtable names are current-document corroboration; final source spellings are inference.
- Historical Wave2/Wave3 material was not used. Any such terminology found in old documentation is stale under the current skill.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence and reanalysis | Resolution |
| --- | --- | --- |
| Return type | IDA guesses `int`, but the function ends in `retn 8`; both callers discard EAX, and EAX only contains arithmetic/virtual-call residue. | Source return is `void`; reject an observable integer return contract. |
| Argument order | `ProcessActivePart` stores the Y-first `Point` components, subtracts origin in matching order, pushes X then Y under x86 cdecl stack order, and target reads first arg with `+0x108`, second with `+0x10c`. | `int localY, int localX`; repair caller, mouse bridge, and hit-test signatures. |
| Method name | Both target calls occur inside `ProcessActivePart`; one direct thumb branch and one non-thumb branch after hit-test equality. | `UpdatePositionFromCursor` is selected. `UpdateScrollPositionFromCursor` ranks second; `UpdateFromDrag` third; `UpdateThumbDragScroll` is rejected as too narrow. |
| Rect setup | Target calls `GetCursorPosition` and `GetScreenOffset` twice. Each valid-origin branch copies `m_bounds` and collapses one edge according to orientation. | Preserve both observable calls and two conditional assignments; do not initialize edge rects or add fallback behavior. |
| Sentinel | Each branch tests both origin components against `-1000`; only both equal means invalid. | Use `origin.y != -1000 || origin.x != -1000`. |
| Horizontal arithmetic | Direct instructions use second arg X, `+0x10c`, `+1`, leading right edge, trailing left plus thumb left minus thumb right, signed `m_scrollRange`, and signed `idiv`. | Preserve exact formula and pre-division min/max order; no generic final range clamp. |
| Vertical arithmetic | Direct instructions use first arg Y, `+0x108`, `+1`, leading bottom, trailing top plus thumb top minus thumb bottom, signed `(m_scrollRange + 1)`, signed `idiv`, then only an upper cap to range. | Preserve exact vertical-only final cap and 16-bit result conversion. |
| Zero/negative track | No range-positive or denominator-zero branch precedes either `idiv`. | Do not invent guards. The source relies on caller/layout invariants and would fault for a zero divisor just like the binary. |
| Lower clamp | Candidate is clamped to track start before the upper bound, but the resulting signed short is not generically clamped to zero. | Preserve only observed geometry clamps. |
| Parent virtual `+0x1c` | Pane documentation identifies the primary vtable slot as inherited `Pane::GetParentPane()`. | Reject `GetOwnerListPane`; cast the returned parent to `FittingRoomListPane*`. |
| Tail source shape | Instructions after `0x0041eaca` are instruction-equivalent to `0x0041f0b0` callback body: old/new test, owner `+0x108`, child `+0xfe`, optional child invalidation, `UpdateScrollBar`, owner invalidation. | Model this as compiler-inlined `OnScrollPositionChanged`, not manually duplicated cross-class access. |
| Callback first parameter | Standalone callback body ignores arg1. Its two live callers push literal `0`; accepted scroll-pane homologs use `unsigned char orientation` and pass the pane orientation. | Correct current unsupported `FittingRoomScrollPane* sender` to `unsigned char orientation`; `(void)orientation` in body. |
| Child nullability | Target and standalone callback dereference owner `+0x11c` without a null check. Constructor evidence creates/owns the `0x110` child. | Preserve non-null ownership invariant; reject defensive null branch in target C++. |
| Fields | Target directly proves `+0xfc`, `+0xfe`, `+0x100`, `+0x108`, and `+0x10c`; sibling family and class evidence resolve the complete natural tail. | Use `m_orientation`, `m_scrollPosition`, `m_scrollRange`, `m_thumbDragOffset.y/.x`; class declaration also uses the established FittingRoom aliases `m_scrollSkinIndex`, `m_scrollStyle`, `m_thumbDragActive`, `m_scrollEnabled`, `m_hotPart`, and `m_activePart`. |
| Member vocabulary closure | Gate 2 proved the first callback generated source still mixed the current class fields `m_scrollPosition` / `m_scrollRange` with undeclared child-body aliases `m_currentPosition` / `m_maxPosition`; class/support prose also retained `GetOwnerListPane`, `GetOwnerPane`, and `UpdateThumbDragScroll` as current labels. The binary proves one signed position word at `+0xfe`, one signed range word at `+0x100`, inherited parent slot `GetParentPane`, and the broad cursor-position behavior. | Use `m_scrollPosition`, `m_scrollRange`, `GetParentPane`, and `UpdatePositionFromCursor` everywhere current. Preserve old labels only in explicit historical/rejected-alternative text and the immutable documentation filename. |
| Callback-owner declaration | Historical pre-callback state: UID000053 owned UID0002DH but had a blank formal, and command16699 generated list methods without a class declaration. Constructor/destructor and method pages establish a `ControlPane`-derived `0x12c` class, exact public/protected/private method inventory, `m_scrollPosition +0x108`, `m_scrollPane +0x11c`, and remaining tail fields. | Applied: complete UID000053 declaration with `OnScrollPositionChanged(unsigned char, short, short)`, exact `0x12c` size guard, `[[CHILDREN]]`, and score `88/90`. |
| Cross-class access | Live UID0002DF, UID0002DH, UID0002DI, UID0002DN, and UID0002DS source bodies directly read/write the owned scroll pane's current/range/visibility state; UID0002D9 calls back into the list. Public scroll fields would weaken existing encapsulation, while a new setter/interface would not explain the repeatedly inlined/direct accesses. | Keep scroll state private, declare `friend class FittingRoomListPane` in UID000054, and expose the list callback as a normal public callback declaration. |
| Compile-visible source order | A scroll declaration emitted directly before the list declaration leaves UID0002D9 with an incomplete list type; a list declaration followed immediately by list child bodies leaves constructor/list children with an incomplete scroll type. Existing class-to-class emitter precedent permits canonical ownership and physical emission to differ. | Emit UID000053 at UID0000JE position `10`; emit UID000054 as UID000053 child position `10`; expand scroll children before later list children. Both classes and every existing child definition then see complete dependencies. |
| Source route | Receiver/class-local helper graph, FittingRoomListPane allocation and synchronization, FittingRoom vtable/resource suffix, and current file root all converge. | Keep `NexusTK/cashshop/FittingRoom.cpp`; reject generic ScrollBar/UI-core relocation. |
| Class C++ | UID000053 and UID000054 are reconstructable and all exact method bodies already emit through them, but both formal blocks are blank. | Add the complete ControlPane-derived list declaration and nested Pane-derived scroll declaration, exact size guards, friendship, callback declaration, and one `[[CHILDREN]]` route per class. |
| Score blockers | Every named blocker was rechecked with live target/caller/callback/list-constructor/list-update disassembly, generated ordering, peer emitter precedent, and current docs. | Scores can rise; only original symbol/header spellings and two unused list selection-state byte names remain inferential, keeping emitting items below `95/95`. |

## Evidence Standards Used

- Direct evidence: live MCP function lookup, analysis, decompile, full disassembly, xrefs, exact byte reads, function-boundary lookup, and callback callsite inspection.
- Structural evidence: primary vtable slots, receiver field offsets, constructor-owned child pointer, exact class size, caller ABI, adjacent function boundaries, and padding.
- Corroboration: current `Pane`, `ControlPane`, FittingRoom, FittingRoomListPane, ScrollSpellInventoryPane, ScrollCollectionPane, Event/Point, layout, callback, and class-to-class emitter documentation.
- Negative evidence: no third caller, no data/immediate/pointer route to target start beyond code calls, no endpoint xref, no zero-divisor guard, no lower-result clamp, no child null check, no target-owned fixed-extent table read, and no separate owner callback call because it was inlined.
- Confidence is below final/audit maximum only because original symbols, exact historical header split, and two unused list selection-state byte spellings are stripped, not because behavior, ownership, legal access, or declaration order remains unresolved.

## Evidence Checked

- Live MCP: health/IDB readiness; `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `xrefs_to`, and byte reads for `0x0041e8b0`, `0x0041e970`, `0x0041eb24`, `0x0041eb30`, list constructor `0x0041eb90`, list update `0x0041ee10`, callback `0x0041f0b0`, reset `0x0041f100`, input `0x0041fcd0`, raw timer cleanup `0x00420d50`, and callback callsites `0x0041fd74`/`0x0041fd8f`.
- Repair-specific MCP session: `2d6016ec-7727-469e-9076-1b846e726bbd`; healthy database `9b0396a3`. A bounded modeled-function scan over `0x0041eb90-0x00421477` found the constructor's only `+0x120..+0x129` stores at `+0x121/+0x124/+0x128`; the raw `0x00420d50` helper independently reads/clears `+0x124`.
- Exact target evidence: 436 bytes, SHA256 `BFBE33AD933E949349A5E3B5469A5D769E8E35862DD394238B0CBCA0E4EC0548`, 140 instructions, 21 basic blocks, cyclomatic complexity 11.
- Boundary evidence: predecessor `sub_41E8B0` ends exactly at `0x0041e970`; target ends exactly at `0x0041eb24`; `0x0041eb24-0x0041eb30` is twelve `0xcc` bytes, SHA256 `A0D08A155AA4E9AADD5DA959565DE99ACC8DC9DBDA96EC3852DDE76C97330902`; raw reset starts at `0x0041eb30`.
- by-* documents: UID0002D9 target; UID000053 and UID000054 classes; UID0000JE file; UID0000WR aggregate; UID0002D2/D3/D4/D6/D7/D8/000493/000494/0002D5/0002DB interaction family; UID0002DC/2DF/2DH/2DI/2DN/2DS owner-list support; Pane, ControlPane, Event/Point/layout, and peer class-to-class emitter documentation.
- Peer evidence: UID0001GN `ScrollSpellInventoryPane::UpdateFromDrag`, ScrollCollection and ScrollNewGroup cursor-update helpers, and `NewSpellInventoryPane::OnScrollPositionChanged(unsigned char, short, short)`.
- Historical search terms: `UID:0002D9`, `0x0041e970`, `UpdateThumbDragScroll`, `FittingRoomScrollPane`. Matching executed B002 report was treated only as a lead and explicitly superseded where wrong.
- Generated/read-only state: `auto-generated/NexusTK/cashshop/FittingRoom.cpp`, `auto-generated/-ag-research-tracker.md`, and current manual class/file/memory coverage rows.
- Failed/unavailable checks: none. MCP remained healthy. No write-capable IDA operation was attempted.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C2D9-01 | 0002D9 | Exact modeled range is `0x0041e970-0x0041eb24`, 436 bytes, target byte SHA256 `BFBE...0548`. | direct | MCP lookup/bytes | target Raw Code Evidence | incorporate | applied |
| C2D9-02 | 0002D9 | Exactly two callers exist, both in UID0002D5 at `0x41e90b` and `0x41e934`. | direct | MCP xrefs/disasm | target caller inventory | incorporate | applied |
| C2D9-03 | 0002D9 | Source return type is `void`; IDA's integer return is residue and callers discard EAX. | very strong | caller disasm and `retn 8` | target signature/C++ | incorporate | applied |
| C2D9-04 | 0002D9 | ABI parameters are `(localY, localX)`, not `(localX, localY)`. | direct | caller stack flow, target arg use, Point layout | target/process/input docs | incorporate | applied |
| C2D9-05 | 0002D9 | Both cursor/origin call pairs are observable and must remain in source order. | direct | target calls at `41e9a4/af/f1/fc` | target behavior/C++ | incorporate | applied |
| C2D9-06 | 0002D9 | Invalid origin skips edge-rect assignment; source must not initialize or synthesize fallback rects. | direct | branch/write analysis | target negative evidence/C++ | incorporate | applied |
| C2D9-07 | 0002D9 | `+0x108` is Y and `+0x10c` is X; orientation zero is vertical. | very strong | target reads plus project Point order | target/class docs | incorporate | applied |
| C2D9-08 | 0002D9 | Horizontal formula uses signed range and no final cap. | direct | `movsx`, `imul`, `idiv` path | target formula/C++ | incorporate | applied |
| C2D9-09 | 0002D9 | Vertical formula uses signed `(range + 1)` and only a final upper cap to range. | direct | `inc`, `imul`, `idiv`, signed compare | target formula/C++ | incorporate | applied |
| C2D9-10 | 0002D9 | No zero-span, positive-range, generic lower, or child-null guard exists. | direct negative | full 140-instruction disassembly | target negative evidence/C++ | reject-invalid | excluded-with-reason |
| C2D9-11 | 0002D9 | Primary vslot `+0x1c` is `Pane::GetParentPane()`. | very strong | Pane docs and target virtual call | target/class source names | incorporate | applied |
| C2D9-12 | 0002D9 | Tail is compiler-inlined UID0002DH behavior. | very strong | instruction-equivalent target/callback bodies | target behavior/source shape | incorporate | applied |
| C2D9-13 | 0002D9 | Callback first argument is orientation, not sender pointer. | strong | zero direct call args plus accepted scroll homolog | UID0002DH signature/C++ | incorporate | applied |
| C2D9-14 | 0002D9 | Change order is owner position write, optional child write/invalidate, `UpdateScrollBar`, owner invalidate. | direct | target and callback disassembly | target/callback behavior | incorporate | applied |
| C2D9-15 | 0002D9 | Owner child pointer is treated non-null by executable and constructor invariant. | direct/structural | no branch; list constructor ownership | target negative evidence | incorporate | applied |
| C2D9-16 | 0002D9 | Best source method name is `UpdatePositionFromCursor`. | strong inference | non-thumb caller path and peer naming | target/class/process docs | incorporate | applied |
| C2D9-17 | 0002D9 | Direct owner/emitter remains UID000054. | very strong | receiver, fields, helpers, current route | target metadata | already-present | already-present |
| C2D9-18 | 0002D9 | Source file remains UID0000JE `NexusTK/cashshop/FittingRoom.cpp`. | very strong | constructor/resource/list synchronization | target/file docs | already-present | already-present |
| C2D9-19 | 0002D9 | No split/merge; twelve-byte post-padding remains excluded. | direct | lookup/bytes/no endpoint xrefs | target range section | incorporate | applied |
| C2D9-20 | 0002D9 | Natural class tail is exact `0x110`, including Y/X Point order. | very strong | constructor allocation, sibling layout, target offsets | UID000054 class layout | incorporate | applied |
| C2D9-21 | 0002D9 | UID000054 needs a formal Pane-derived class declaration with `[[CHILDREN]]`, physically nested beneath the complete UID000053 declaration. | strong | blank marker, ready children, complete-type dependency | UID000054 formal C++ | incorporate | applied |
| C2D9-22 | 0002D9 | UID0002D5 C++ must call target and hit-test with `(localY, localX)`. | direct | caller disassembly | UID0002D5 formal C++ | incorporate | applied |
| C2D9-23 | 0002D9 | UID0002D2 event coordinates are Y at `+8`, X at `+0xc`; drag offset assignments must follow that order. | very strong | Event/Point docs and call chain | UID0002D2 formal C++ | incorporate | applied |
| C2D9-24 | 0002D9 | UID0002D8 signature and containment call must use `(localY, localX)`. | very strong | Process caller and event chain | UID0002D8 formal C++ | incorporate | applied |
| C2D9-25 | 0002D9 | UID0002DH keeps three ABI args but renames arg1 to `unsigned char orientation`. | strong | direct zero calls and homolog contract | UID0002DH formal C++ | incorporate | applied |
| C2D9-26 | 0002D9 | Target should be `92/94`, position `80`, route unchanged. | strong | all blockers resolved | target metadata | incorporate | applied |
| C2D9-27 | 000054 | Scroll class should be `90/92`, retain canonical owner UID0000JE, emit through UID000053 at child position `10`. | strong | declaration/layout/dependency-safe source route | UID000054 metadata | incorporate | applied |
| C2D9-28 | 0002D9 | UID0002D2/D5/D8/DH should be `90/92`; method/aggregate/file supports not separately changed below remain current, while UID000053 has the explicit C2D9-43 promotion. | strong | repaired ABI/source contracts | support metadata | incorporate | applied |
| C2D9-29 | 0002D9 | UID0002DB remains `88/90` and should be source position `90`. | strong | existing exact reset body/order | UID0002DB metadata | incorporate | applied |
| C2D9-30 | 0002D9 | UID0000WR remains reconstructable aggregate `88/89`, blank C++, UID0000JE route. | strong | aggregate policy/current docs | aggregate support | already-present | already-present |
| C2D9-31 | 0002D9 | UID0000JE remains `88/90`; add exact class child ordering/source note only. | strong | current file root | file support | incorporate | applied |
| C2D9-32 | 0002D9 | Prior x-first/fixed-extent/guarded B002 target draft is historical and invalid for current C++. | direct contradiction | live MCP versus old report/current body | target historical assumptions | historicalize | applied |
| C2D9-33 | 0002D9 | Current target formal body must be replaced, not incrementally patched. | direct contradiction | complete formula/source-shape mismatch | target formal C++ | reject-stale | excluded-with-reason |
| C2D9-34 | 0002D9 | Current generated Empty Emitter Markers for UID000053/UID000054 are resolved by complete declarations and nesting, not by duplicating child bodies. | structural | command16699 generated readback | class/generated verification | incorporate | applied |
| C2D9-35 | 0002D9 | Historical manual class row UID000054 was stale at `82%`; the supervisor applied and validated the exact no-loss `90%` replacement under command16777. | direct doc comparison / supervisor readback | current by-class root and exact row occurrence | by-class coverage handoff | incorporate | applied |
| C2D9-36 | 0002D9 | Historical manual file row UID0000JE was stale at `85%`; the supervisor applied and validated the exact no-loss `88%` replacement under command16778. | direct doc comparison / supervisor readback | current by-file root and exact row occurrence | by-file coverage handoff | incorporate | applied |
| C2D9-37 | 0002D9 | Historical manual memory rows were stale or missing; the supervisor applied and validated every exact replacement/insertion below under command16779, including UID000493/UID000494. | direct doc comparison / supervisor readback | current by-memory root and exact row occurrences | by-memory coverage handoff | incorporate | applied |
| C2D9-38 | 0002D9 | No IDA mutation, third-party import, lifecycle action, or report-only validator is applicable. | assignment boundary | goal/skill | report/checklist | not-applicable | excluded-with-reason |
| C2D9-39 | 000053 | UID000053 requires a complete compile-visible `ControlPane`-derived `FittingRoomListPane` declaration containing the accepted callback and current child method/field contract. | very strong | historical blank formal/generated missing declaration plus constructor/destructor/method docs | `by-class/FittingRoomListPane.md` formal/status/layout | incorporate | applied |
| C2D9-40 | 000054 | `FittingRoomListPane` must be a friend of `FittingRoomScrollPane`; direct private-state writes recur in UID0002DF/DH/DI/DN/DS and are not explained by a proven setter. | direct/structural | live decompile/disasm and current child bodies | `by-class/FittingRoomScrollPane.md` formal/access rationale | incorporate | applied |
| C2D9-41 | 000053 | UID000053 must emit at UID0000JE position `10`, with `[[CHILDREN]]`; UID000054 must retain canonical owner UID0000JE but emit as first UID000053 child at position `10`. | strong structural | dependency graph, generator shape, class-to-class emitter precedent | both class metadata/source-placement sections | incorporate | applied |
| C2D9-42 | 000053 | List class layout is exact `0x12c`: ControlPane base `0x108`, scroll/count words, display/state dwords, child pointer `+0x11c`, packed four-byte selection state at `+0x120`, timer id `+0x124`, byte flags `+0x128`, and natural tail alignment. | strong | constructor stores, destructor size, raw timer helper, current docs | UID000053 formal/layout evidence | incorporate | applied |
| C2D9-43 | 000053 | Raise UID000053 from `86/88` to `88/90`; retain canonical owner/emitter UID0000JE and reconstructable true; set position `10`. | strong | resolved declaration/order/access blocker with residual tail-name caps | UID000053 metadata/manual row | incorporate | applied |
| C2D9-44 | 000054 | Raise UID000054 to `90/92`, retain canonical owner UID0000JE, change physical emitter to UID000053, and retain child position `10`. | strong | exact declaration plus dependency-safe nesting | UID000054 metadata/manual row | incorporate | applied |
| C2D9-45 | 0002D9 | All seven accepted managed blocks remain behaviorally valid after dependency re-audit, provided the new UID000053 declaration precedes UID000054 and UID000054 grants friendship. | strong | signature/dependency/access audit of each block | report formal set and callback generated test | already-present | applied |
| C2D9-46 | 000053 | The generated callback must compile against the full list declaration and private scroll fields without public-field exposure, raw offsets, reduced duplicate declarations, or invented setters. | strong | source-contract audit | UID000053/000054 docs and generated acceptance test | incorporate | applied |
| C2D9-47 | 000053 | Historical manual UID000053 was stale at `85%`; the supervisor applied and validated the exact no-loss `88%` replacement under command16777 while preserving B001's no-manual-edit boundary. | direct doc comparison / supervisor readback | current by-class root and exact row occurrence | class manual handoff/checklist/validator plan | incorporate | applied |
| C2D9-48 | 000054 | `m_scrollPosition` and `m_scrollRange` are the sole current human source names for scroll fields `+0xfe/+0x100`; `m_currentPosition`, `m_maxPosition`, and `m_maxScrollPosition` are historical aliases only. | very strong | exact offsets, accepted declaration, Gate 2 generated compile audit | UID000054/UID000053/current child docs | incorporate | applied |
| C2D9-49 | 0002DF | `UpdateScrollBar` must read/write the owned scroll child through `m_scrollPosition` / `m_scrollRange`. | very strong | existing exact body offsets and class declaration contract | UID0002DF formal/prose | incorporate | applied |
| C2D9-50 | 0002DI | `ResetScrollPosition` must write the owned child through `m_scrollPosition`. | very strong | existing exact body offset and class declaration contract | UID0002DI formal/prose | incorporate | applied |
| C2D9-51 | 0002DN | `OnInputEvent` must compare/update the owned child through `m_scrollPosition` / `m_scrollRange`. | very strong | existing exact body offsets and class declaration contract | UID0002DN formal/prose | incorporate | applied |
| C2D9-52 | 0002DS | `OnScrollStep` must read/update the owned child through `m_scrollPosition` / `m_scrollRange`. | very strong | existing exact body offsets and class declaration contract | UID0002DS formal/prose | incorporate | applied |
| C2D9-53 | 000053 | Current class/file prose and method tables must use inherited `GetParentPane`, `UpdatePositionFromCursor`, `m_scrollPosition`, and `m_scrollRange`; superseded aliases remain labeled history only. | strong | Pane slot evidence, broad target behavior, generated compile audit | both classes and by-file support | incorporate | applied |
| C2D9-54 | 000494 | BeginPartPress and GetPartRect support must name the current target `UpdatePositionFromCursor`; the immutable target-page filename may retain the historical slug. | strong | accepted target source name and direct interaction graph | UID000494/UID0002D7 prose | incorporate | applied |
| C2D9-55 | 0002D9 | Current generated command16780 must have zero undeclared old field/accessor vocabulary and preserve the accepted declaration/order/target/callback shape with zero UID000053/UID000054 Empty Emitter Markers. | direct generated | generated source readback and occurrence counts | G5 current generated acceptance evidence; G1/G2/G3 and supervisor G4 retained as historical checkpoints | incorporate | applied |
| C2D9-56 | 0002D9 | The bounded Gate 2 repair required no B001 score, ownership, range, manual coverage, IDA, generated-file, or lifecycle mutation; fresh report Gate 1/Gate 2 and lifecycle remain supervisor-owned. | assignment boundary | verified repair scope and goal | report/checklist | not-applicable | excluded-with-reason |
| C2D9-57 | 0002DI | Historical manual UID0002DI was stale at `82%` and used obsolete "scroll-pane current-value reset" wording; the supervisor applied and validated the exact no-loss `88%` / very-strong replacement recording source-ready `ResetScrollPosition()` C++, current `m_scrollPosition` vocabulary, and preserved caller/category/vector/refresh/padding evidence. | direct doc comparison / supervisor readback | D12 `88/91`, current by-memory root, exact row occurrence | by-memory coverage handoff/checklist | incorporate | applied |
| C2D9-58 | 0002DN | Historical manual UID0002DN was stale at `84%` and omitted the source-ready `OnInputEvent()` formal and `88/90` source-quality state; the supervisor applied and validated the exact no-loss `88%` / very-strong replacement preserving boundary, vtable, event, singleton/global, switch-tail, callee, side-effect, and child/base delegation facts. | direct doc comparison / supervisor readback | D13 `88/90`, current by-memory root, exact row occurrence | by-memory coverage handoff/checklist | incorporate | applied |
| C2D9-59 | 0002DS | Historical manual UID0002DS was stale at `84%`, used obsolete "child current/range reads" wording, and falsely described a blank/below-threshold parent; the supervisor applied and validated the exact no-loss `88%` / very-strong replacement recording source-ready `OnScrollStep()` C++, current member vocabulary, complete FittingRoomListPane route, and preserved callback/clamp/invalidation/timer evidence. | direct doc comparison / supervisor readback | D14 `88/91`, current by-memory root, exact row occurrence | by-memory coverage handoff/checklist | incorporate | applied |

## Positive Evidence Summary

- Exact target boundary, bytes, hash, instruction count, basic blocks, callers, callee set, fields, arithmetic, and post-padding were freshly confirmed through healthy MCP.
- Target parameter consumption matches the accepted project `Point` Y/X layout and the immediate caller's stack order.
- The target tail and standalone owner callback share the same field writes, comparisons, update call, and invalidation order, establishing compiler inlining rather than hand-authored duplicate cross-class access.
- Parent slot `+0x1c` is already resolved project-wide as `GetParentPane`; slot `+0x20` is `InvalidateRect`.
- FittingRoomListPane construction owns the `0x110` child and stores it at `+0x11c`; target-specific class/file ownership is stronger than generic scrollbar similarity.
- Live list `UpdateScrollBar`, standalone callback, reset, input, and scroll-step bodies repeatedly access the owned child at `+0xfe/+0x100/+0x102`, making class-level friendship a direct source-contract explanation rather than an isolated convenience for UID0002DH.
- Historical command16699 `FittingRoom.cpp` had definitions for both classes but no declaration for either. Historical B001 callback checkpoint G2 first proved the implemented UID000053-first / nested-UID000054 route closes both directions of the compile dependency without a reduced duplicate declaration; historical G3 and supervisor G4/current G5 reconfirm that semantic shape without drift.
- ScrollSpellInventoryPane and ScrollCollectionPane provide independent source-shape corroboration for method naming, Y/X parameters, exact formulas, and orientation callback ABI.

## IDA MCP Facts

- `sub_41E970`: start `0x0041e970`, size `0x1b4`, exclusive end `0x0041eb24`, 140 instructions, 21 blocks, cyclomatic complexity 11.
- Existing IDA prototype `int __thiscall(int this, int, int)` is provisional. Binary calling convention is thiscall with two 32-bit arguments and `retn 8`.
- Calls: `0x0041e4f0` `GetPartRect`, `0x004a9090` cursor read twice, `0x005447c0` screen offset twice, `0x0041ee10` `UpdateScrollBar`, security-cookie check, plus primary virtual slots `+0x1c` and `+0x20`.
- Callers/xrefs: only `0x0041e90b` and `0x0041e934`, both in `sub_41E8B0`.
- Field accesses: child `+0xfc`, `+0xfe`, `+0x100`, `+0x108`, `+0x10c`; parent/list `+0x108`, `+0x11c`; embedded child `+0xfe`; inherited bounds `+0x44`.
- `sub_41F0B0`: size `0x4d`, `retn 0xc`, two xrefs at `0x0041fd74` and `0x0041fd8f`; both callsites push literal zero for arg1.
- `sub_41EB90`: size `0x12d`; initializes list `+0x108/+0x10c/+0x110/+0x114/+0x118/+0x121/+0x124/+0x128`, allocates `0x110` bytes for the scroll child, stores it at list `+0x11c`, and establishes the non-null ownership invariant.
- `sub_41EE10` and `sub_41F0B0` directly read/write child `+0xfe/+0x100/+0x102`; `sub_41F100`, `sub_41FCD0`, and `sub_420840` corroborate the same list-owned synchronization family. A public scroll state band or invented setter is not evidenced.
- List complete-object size is `0x12c` from UID0002DX. Constructor writes a word at unaligned `+0x121`; no modeled list method reads `+0x120..+0x123`, so the source-ready declaration preserves that exact compact state band under local packing while keeping the surrounding class naturally aligned.
- Negative IDA facts: no target data xrefs, no third caller, no branch into the middle, no xref to `0x0041eb24` or `0x0041eb30`, no zero-divisor guard, no child-null guard, and no source-visible callback call in target because the body is inlined.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| list class declaration | UID000053 `by-class/FittingRoomListPane.md` | callback owner/layout/declaration and physical parent for scroll declaration | true | UID0000JE | 86/88 -> 88/90 | full formal, file position 10, `[[CHILDREN]]` |
| scroll class declaration | UID000054 `by-class/FittingRoomScrollPane.md` | target owner/layout/declaration | true | canonical UID0000JE; physical emitter UID000053 | 88/90 -> 90/92 | formal plus friendship, child position 10 |
| `0x0041d870-0x0041da51` | UID0002D2 | mouse/event bridge | true | UID000054 | 88/90 -> 90/92 | Y/X formal repair |
| `0x0041da60-0x0041da65` | UID0002D3 | false virtual | true | UID000054 | 91/92 retained | already source-ready |
| `0x0041da70-0x0041daa3` | UID0002D4 | repeat timer | true | UID000054 | 89/91 retained | already source-ready |
| `0x0041dab0-0x0041e1c6` | UID0002D6 | paint | true | UID000054 | 88/90 retained | already source-ready |
| `0x0041e1d0-0x0041e4ed` | UID0002D8 | part hit-test | true | UID000054 | 88/90 -> 90/92 | Y/X formal repair |
| `0x0041e4f0-0x0041e777` | UID0002D7 | part rectangle | true | UID000054 | 88/90 retained | geometry support |
| `0x0041e780-0x0041e8af` | UID0002DA | non-emitting split index | false | none | 90/91 retained | exact children below |
| `0x0041e780-0x0041e7f0` | UID000493 | `SetHotPart` raw body | true | UID000054 | 89/91 retained | position 50 |
| `0x0041e7f0-0x0041e8af` | UID000494 | `BeginPartPress` raw body | true | UID000054 | 89/91 retained | position 60 |
| `0x0041e8b0-0x0041e970` | UID0002D5 | immediate dispatcher/caller | true | UID000054 | 87/90 -> 90/92 | position 70, Y/X repair |
| `0x0041e970-0x0041eb24` | UID0002D9 | cursor-to-position update | true | UID000054 | 87/89 -> 92/94 | position 80, replace C++ |
| `0x0041eb24-0x0041eb30` | no page | alignment padding | false | none | n/a | excluded twelve `0xcc` bytes |
| `0x0041eb30-0x0041eb8c` | UID0002DB | reset state raw body | true | UID000054 | 88/90 retained | position 90 |
| `0x0041ee10-0x0041f0b0` | UID0002DF | owner scrollbar refresh | true | UID000053 | 87/90 retained | support |
| `0x0041f0b0-0x0041f0fd` | UID0002DH | owner callback | true | UID000053 | 87/90 -> 90/92 | orientation ABI repair |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0041e90b` | UID0002D5 -> UID0002D9 | direct thumb-active update; passes local Y then X |
| `0x0041e934` | UID0002D5 -> UID0002D9 | non-thumb active update after hit-test still matches active part |
| `0x0041e995` | UID0002D9 -> UID0002D7 | requests part id 2 thumb rectangle |
| `0x0041e9a4`, `0x0041e9f1` | UID0002D9 -> cursor helper | two observable cursor samples |
| `0x0041e9af`, `0x0041e9fc` | UID0002D9 -> `GetScreenOffset` | two origin/sentinel checks |
| `0x0041ead4` | UID0002D9 -> primary virtual `+0x1c` | inherited `Pane::GetParentPane()` |
| `0x0041eafc` | UID0002D9 -> child virtual `+0x20` | child `InvalidateRect` after changed mirror value |
| `0x0041eb01` | UID0002D9 -> UID0002DF | owner scroll-bar/layout refresh |
| `0x0041eb0e` | UID0002D9 -> owner virtual `+0x20` | owner `InvalidateRect` last |
| `0x0041fd74`, `0x0041fd8f` | UID0002DN -> UID0002DH | standalone callback calls with arg1 literal zero |

## Documentation Evidence And IDA Status

- Current docs correctly establish UID000054 target ownership, UID000053 callback ownership, UID0000JE source routing, exact target boundary, two caller sites, orientation, position/range fields, list object size, constructor-owned child, and list/child synchronization.
- Historical pre-callback docs were stale or contradicted for target signature, method name, fixed-extent use, generic guards/clamps, parent accessor, callback source shape, event/hit-test coordinate order, callback arg1 type, both class formal declarations, legal cross-class access, emitter dependency order, positions, and manual coverage rows. The first callback ordinary-document issues were applied at D1-D10. The subsequent Gate 2 vocabulary defect is repaired at current D2/D3/D9 and D11-D16, and the supervisor-owned manual rows are now applied and validated at the exact current roots recorded above.
- The prior B002 report is useful history for FittingRoom-local ownership and field-family discovery, but its MCP outage and incorrect target draft make it unsuitable as current arithmetic evidence.
- Historical command16699 generated output contained the stale target body, child definitions without class declarations, and UID000053/UID000054 Empty Emitter Markers. Historical first-callback G1 command16722 closed those declaration/marker defects but exposed undeclared historical names in four child definitions. Historical B001 bounded-repair G2 command16738 eliminated the old field/accessor vocabulary. Historical G3 command16762 and supervisor G4/current G5 retain one complete list declaration before one complete scroll declaration, one target body, one callback body, one friend declaration, zero markers for UID000053/UID000054, and zero current-code occurrences of the superseded aliases.
- IDA database state was read-only. No rename, type application, function creation, comment, or database write was requested or performed.

## Ranked Ownership Analysis

### 1. UID000054 FittingRoomScrollPane through UID0000JE FittingRoom

- Evidence for: exact `this` field family, class-local callers/helpers, list constructor allocation, FittingRoom-specific owner synchronization, vtable/resource adjacency, and current emitter chain.
- Evidence against: none material. The class shares a scrollbar design with other UI panes, but reuse/copy similarity is not source ownership.
- Decision: retain direct owner/emitter UID000054 and file root UID0000JE.

### 2. UID000053 FittingRoomListPane

- Evidence for: target retrieves the parent list, writes list state, and inlines the list callback body.
- Evidence against: target receiver and geometry fields are unequivocally `FittingRoomScrollPane`; source callback call can be inlined by the compiler without changing method ownership.
- Decision: support owner for the callback and compile-visible declaration parent for UID000054, not target semantic owner. Retain canonical file owner UID0000JE and use class-to-class physical emission only to close source dependencies.

### 3. Generic ScrollBar or shared UI-core module

- Evidence for: layout and algorithm homologs exist across ScrollSpellInventoryPane, ScrollCollectionPane, ScrollNewGroupPane, and ranking scroll panes.
- Evidence against: no generic constructor/caller/vtable/source route reaches this receiver; resource and parent interactions are FittingRoom-specific.
- Decision: reject direct generic ownership and file relocation.

### Proposed new file/grouping, if applicable

- Not applicable. No new file or grouping is needed.
- Current generated source root `NexusTK/cashshop/FittingRoom.cpp` contains the FittingRoomListPane declaration, nested FittingRoomScrollPane declaration/method sequence, and later FittingRoomListPane method definitions through the dependency-safe emitter chain below.

## Source Placement

- Recommended placement: [UID:000053] emits to [UID:0000JE] `NexusTK/cashshop/FittingRoom.cpp` at position `10`; [UID:000054] retains canonical owner UID0000JE but physically emits as the first UID000053 child at position `10`.
- Recommended source order relevant to this pass: complete `FittingRoomListPane` declaration and `[[CHILDREN]]`; complete nested `FittingRoomScrollPane` declaration and its `[[CHILDREN]]`; existing raw exact scroll children `SetHotPart` at `50`, `BeginPartPress` at `60`; `ProcessActivePart` at `70`; `UpdatePositionFromCursor` at `80`; `ResetScrollState` at `90`; then later list child definitions, including UID0002DH.
- This preserves canonical class/file ownership and address-order behavior while making the list type complete for UID0002D9 and the scroll type complete for list constructor/method definitions. The class-to-class emitter route is physical source ordering, not semantic ownership transfer.
- Rejected placements: UID000053 as target owner, generic `ScrollBar.cpp`, shared UI core, or a new one-method file.
- Rejected ordering: two independent direct-to-file blank class markers, a reduced local list declaration, public scroll fields, or an invented setter interface.
- Remaining placement uncertainty: exact historical header/source split is stripped, but the selected existing source root and dependency-safe declaration order are implementation-ready.

## Range / Split / Padding / Reclassification Analysis

- Exact target range: `[0x0041e970,0x0041eb24)`.
- Predecessor UID0002D5 ends exactly at target start; no pre-padding belongs to target.
- Post-range `[0x0041eb24,0x0041eb30)` is twelve `0xcc` bytes and must remain outside target C++.
- UID0002DB begins at raw start `0x0041eb30`; no target endpoint/start xref justifies merging it into UID0002D9.
- Existing UID0002DA split index and exact UID000493/UID000494 children remain correct.
- No duplicate coverage, new child, merge, range extension, or reclassification is recommended.

## Negative Evidence Summary

- No third target caller or callback-like data reference exists.
- No evidence supports a target-owned fixed-extent table read; the current target C++ imports geometry not executed here.
- No target branch tests `m_scrollRange > 0`, track span, or child pointer.
- No generic final lower clamp or horizontal final upper cap exists.
- No binary evidence supports `GetOwnerListPane`; current Pane evidence identifies the slot as `GetParentPane`.
- No binary evidence supports a sender pointer as callback arg1; actual standalone callsites push zero and homolog contracts use orientation.
- No reason exists to move target ownership to the consumer list pane merely because callback code was inlined.
- No evidence supports making scroll state public: all direct accesses are confined to the owning list class, which is exactly the narrow relationship represented by friendship.
- No evidence supports a new setter or callback adapter; the compiler repeatedly exposes direct list-to-child field access, and adding an interface would alter source shape without explaining those bodies.
- No reduced `FittingRoomListPane` declaration can satisfy no-loss source closure because the current file already contains its constructor, lifecycle, paint/input, geometry, timer, and helper definitions.
- No need exists to emit vtable arrays, raw vtable stores, or a duplicate callback body on the target page.

## IDA Rename / Type / Comment Recommendations

- Safe future source-facing function type/name if an explicitly authorized IDA pass occurs: `void __thiscall FittingRoomScrollPane::UpdatePositionFromCursor(int localY, int localX)`.
- Safe future callback type/name: `void __thiscall FittingRoomListPane::OnScrollPositionChanged(unsigned char orientation, short oldPosition, short newPosition)`.
- Safe source field names: `m_scrollSkinIndex`, `m_scrollStyle`, `m_thumbDragActive`, `m_orientation`, `m_scrollPosition`, `m_scrollRange`, `m_scrollEnabled`, `m_hotPart`, `m_activePart`, `m_thumbDragOffset`.
- Safe source helper names: `GetParentPane`, `GetPartRect`, `UpdateScrollBar`, `UpdatePositionFromCursor`, `ProcessActivePart`, `OnScrollPositionChanged`.
- Names are implementation-ready inference, not recovered original symbols. Raw IDA labels must not appear in final source.
- IDA edits were outside both the report-only and callback scopes and were not performed.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. Target and affected support emitters are above the active gate, and the repaired declaration/access/order plan resolves the compile-source blocker found by Gate 1.
- Third-party import directive: not applicable.
- The following seven complete formal blocks are the accepted and applied C++ for this report. UID000053 emits before the six preserved/re-audited blocks through the dependency-safe nested route.

Callback-owner class [UID:000053]:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
class FittingRoomScrollPane;
class Layer;
struct PaneKeyEvent;
struct Point;
struct RectBounds;

typedef short FittingRoomSlotIndex;

enum FittingRoomListDisplayMode
{
    FittingRoomListDisplayMode_Rows = 0,
    FittingRoomListDisplayMode_Grid = 1
};

static const FittingRoomSlotIndex kInvalidFittingRoomSlot = -1;

class FittingRoomListPane : public ControlPane
{
public:
    explicit FittingRoomListPane(const RectBounds *bounds);
    virtual ~FittingRoomListPane();

    void OnScrollPositionChanged(unsigned char orientation,
                                 short oldPosition,
                                 short newPosition);

protected:
    virtual void OnResize(const RectBounds *bounds);
    virtual void SetBounds(const RectBounds *bounds,
                           const RectBounds *oldBounds);
    virtual void OnInsertPane(const RectBounds *bounds,
                              int order,
                              Pane *previousPane,
                              Layer *layerOrContext);
    virtual void OnDetachPane();
    virtual void OnPaint();
    virtual bool OnKeyScroll(PaneKeyEvent *event);
    virtual bool OnInputEvent(Event *event);
    virtual bool OnScrollStep(int direction, int arg0, int arg1);

private:
    void UpdateScrollBar();
    void ResetScrollPosition();
    void GetItemSlotRect(FittingRoomSlotIndex slotIndex,
                         RectBounds *rect);
    FittingRoomSlotIndex HitTestSlot(int localX, int localY);
    FittingRoomSlotIndex ValidateFittingSelectionIndex(
        FittingRoomSlotIndex candidate) const;
    void GetItemSlotOrigin(Point *point,
                           FittingRoomSlotIndex slotIndex);
    void CancelPendingSlotTimer();

    short m_scrollPosition;
    short m_enabledItemCount;
    FittingRoomListDisplayMode m_displayMode;
    int m_listState0;
    int m_listState1;
    int m_listState2;
    FittingRoomScrollPane *m_scrollPane;

#pragma pack(push, 1)
    struct
    {
        unsigned char m_selectionState;
        short m_selectedItemIndex;
        unsigned char m_selectionFlags;
    };
#pragma pack(pop)

    unsigned int m_pendingSlotTimer;
    unsigned char m_stateFlags;
};

typedef char FittingRoomListPaneSizeMustBe300[
    sizeof(FittingRoomListPane) == 0x12c ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- The locally packed four-byte selection band is the narrowest source-shaped layout that preserves the constructor's direct word store at unaligned `+0x121` while retaining natural alignment for `m_pendingSlotTimer +0x124` and the class's `0x12c` size. Only `m_selectedItemIndex` has a current semantic name; `m_selectionState` and `m_selectionFlags` are conservative human-facing names for the surrounding bytes because exhaustive modeled-method scans found no read that would justify a narrower semantic claim.
- UID000053 emits at UID0000JE position `10`. Its `[[CHILDREN]]` expands UID000054 first at child position `10`, so the complete list declaration is visible to UID0002D9 and the complete scroll declaration is visible to later list definitions.

Target [UID:0002D9]:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void FittingRoomScrollPane::UpdatePositionFromCursor(int localY, int localX)
{
    Point cursor;
    Point origin;
    RectBounds thumbRect;
    RectBounds leadingRect;
    RectBounds trailingRect;
    short oldPosition;
    short newPosition;
    int thumbStart;
    int maxThumbStart;
    int trackStart;
    int trackSpan;

    oldPosition = m_scrollPosition;
    GetPartRect(kFittingRoomScrollPartThumb, &thumbRect);

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);
    if (origin.y != -1000 || origin.x != -1000) {
        leadingRect = m_bounds;
        if (m_orientation != 0) {
            leadingRect.right = leadingRect.left;
        } else {
            leadingRect.bottom = leadingRect.top;
        }
    }

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);
    if (origin.y != -1000 || origin.x != -1000) {
        trailingRect = m_bounds;
        if (m_orientation != 0) {
            trailingRect.left = trailingRect.right;
        } else {
            trailingRect.top = trailingRect.bottom;
        }
    }

    if (m_orientation != 0) {
        thumbStart = localX - m_thumbDragOffset.x + 1;
        trackStart = leadingRect.right;
        if (thumbStart < trackStart) {
            thumbStart = trackStart;
        }

        maxThumbStart = trailingRect.left + thumbRect.left - thumbRect.right;
        if (thumbStart > maxThumbStart) {
            thumbStart = maxThumbStart;
        }

        trackSpan = trailingRect.left + thumbRect.left -
                    thumbRect.right - leadingRect.right;
        newPosition = static_cast<short>(
            (m_scrollRange * (thumbStart - leadingRect.right)) / trackSpan);
    } else {
        thumbStart = localY - m_thumbDragOffset.y + 1;
        trackStart = leadingRect.bottom;
        if (thumbStart < trackStart) {
            thumbStart = trackStart;
        }

        maxThumbStart = trailingRect.top + thumbRect.top - thumbRect.bottom;
        if (thumbStart > maxThumbStart) {
            thumbStart = maxThumbStart;
        }

        trackSpan = trailingRect.top + thumbRect.top -
                    thumbRect.bottom - leadingRect.bottom;
        newPosition = static_cast<short>(
            ((m_scrollRange + 1) *
             (thumbStart - leadingRect.bottom)) / trackSpan);

        if (newPosition > m_scrollRange) {
            newPosition = m_scrollRange;
        }
    }

    if (oldPosition != newPosition) {
        static_cast<FittingRoomListPane *>(GetParentPane())
            ->OnScrollPositionChanged(m_orientation,
                                      oldPosition,
                                      newPosition);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Class [UID:000054]:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct PaneMouseEvent;
class FittingRoomListPane;

enum FittingRoomScrollPart {
    kFittingRoomScrollPartLeading = 0,
    kFittingRoomScrollPartPageBeforeThumb = 1,
    kFittingRoomScrollPartThumb = 2,
    kFittingRoomScrollPartPageAfterThumb = 3,
    kFittingRoomScrollPartTrailing = 4,
    kFittingRoomScrollPartNone = -1
};

class FittingRoomScrollPane : public Pane
{
public:
    explicit FittingRoomScrollPane(unsigned char orientation);

protected:
    virtual bool OnMouseEvent(const PaneMouseEvent& event);
    virtual bool DefaultVirtualFalse(int value);
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual void OnDraw();

private:
    friend class FittingRoomListPane;

    FittingRoomScrollPart HitTestPart(int localY, int localX);
    void GetPartRect(FittingRoomScrollPart part, RectBounds *rect);
    void SetHotPart(FittingRoomScrollPart part);
    void BeginPartPress(FittingRoomScrollPart part,
                        int localY,
                        int localX);
    void ProcessActivePart();
    void UpdatePositionFromCursor(int localY, int localX);
    void ResetScrollState();

    unsigned short m_scrollSkinIndex;
    unsigned char m_scrollStyle;
    bool m_thumbDragActive;
    unsigned char m_orientation;
    short m_scrollPosition;
    short m_scrollRange;
    bool m_scrollEnabled;
    signed char m_hotPart;
    signed char m_activePart;
    Point m_thumbDragOffset;
};

typedef char FittingRoomScrollPaneSizeMustBe272[
    sizeof(FittingRoomScrollPane) == 0x110 ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Immediate caller [UID:0002D5]:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void FittingRoomScrollPane::ProcessActivePart()
{
    Point cursor;
    Point origin;
    RectBounds rect;

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);

    if (origin.y == -1000 && origin.x == -1000) {
        return;
    }

    cursor.y -= origin.y;
    cursor.x -= origin.x;

    if (m_activePart == kFittingRoomScrollPartThumb) {
        UpdatePositionFromCursor(cursor.y, cursor.x);
        return;
    }

    const FittingRoomScrollPart hitPart =
        HitTestPart(cursor.y, cursor.x);
    if (hitPart == m_activePart) {
        UpdatePositionFromCursor(cursor.y, cursor.x);
    }

    if (m_hotPart != kFittingRoomScrollPartNone) {
        GetPartRect(static_cast<FittingRoomScrollPart>(m_hotPart),
                    &rect);
        InvalidateRect(&rect);
        m_hotPart = kFittingRoomScrollPartNone;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Mouse bridge [UID:0002D2]:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool FittingRoomScrollPane::OnMouseEvent(const PaneMouseEvent& event)
{
    bool handled = false;
    RectBounds partRect;

    switch (event.type) {
    case kPaneMouseMove:
        if (m_activePart != kFittingRoomScrollPartNone) {
            InvalidateRect(&m_bounds);
            handled = true;
        }
        break;

    case kPaneMouseDown:
        if (!PointInRect(event.y, event.x, &m_bounds)) {
            return false;
        }
        if (!m_scrollEnabled || m_scrollRange <= 0) {
            return false;
        }

        if (m_activePart == kFittingRoomScrollPartNone) {
            const FittingRoomScrollPart part =
                HitTestPart(event.y, event.x);

            if (part != kFittingRoomScrollPartNone) {
                CaptureMouse();

                if (part == kFittingRoomScrollPartThumb) {
                    if (m_hotPart != kFittingRoomScrollPartThumb) {
                        if (m_hotPart != kFittingRoomScrollPartNone) {
                            GetPartRect(
                                static_cast<FittingRoomScrollPart>(
                                    m_hotPart),
                                &partRect);
                            InvalidateRect(&partRect);
                        }

                        GetPartRect(kFittingRoomScrollPartThumb, &partRect);
                        InvalidateRect(&partRect);
                        m_hotPart = kFittingRoomScrollPartThumb;
                    }

                    GetPartRect(kFittingRoomScrollPartThumb, &partRect);
                    m_thumbDragOffset.y = event.y - partRect.top;
                    m_thumbDragOffset.x = event.x - partRect.left;
                }

                m_activePart = static_cast<signed char>(part);
                ProcessActivePart();
                m_repeatTimer.ScheduleTimer(0, 200, 0, 0);
                InvalidateRect(&m_bounds);
            }
        }

        m_thumbDragActive = true;
        handled = true;
        break;

    case kPaneMouseUp:
        if (m_activePart != kFittingRoomScrollPartNone) {
            ReleaseMouseCapture();
            m_repeatTimer.RemovePendingTimers();

            const signed char oldHotPart = m_hotPart;
            m_activePart = kFittingRoomScrollPartNone;
            if (oldHotPart != kFittingRoomScrollPartNone) {
                GetPartRect(
                    static_cast<FittingRoomScrollPart>(oldHotPart),
                    &partRect);
                InvalidateRect(&partRect);
                m_hotPart = kFittingRoomScrollPartNone;
            }

            handled = true;
        }

        m_thumbDragActive = false;
        InvalidateRect(&m_bounds);
        break;

    default:
        break;
    }

    return handled;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Hit-test support [UID:0002D8]:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
FittingRoomScrollPart FittingRoomScrollPane::HitTestPart(int localY,
                                                         int localX)
{
    Point cursor;
    Point origin;

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);

    if (origin.y == -1000 && origin.x == -1000) {
        return kFittingRoomScrollPartNone;
    }

    cursor.y -= origin.y;
    cursor.x -= origin.x;

    const bool horizontal = (m_orientation != 0);
    const int fixedExtent = horizontal
        ? (m_bounds.bottom - m_bounds.top)
        : kFittingRoomScrollPartExtentBySkin[m_scrollSkinIndex];

    const int trackStart = horizontal ? m_bounds.left + fixedExtent
                                      : m_bounds.top + fixedExtent;
    const int trackEnd = horizontal ? m_bounds.right - fixedExtent
                                    : m_bounds.bottom - fixedExtent;
    const int trackSize = trackEnd - trackStart;

    int thumbStart = trackStart;
    int thumbEnd = trackEnd;

    if (m_scrollEnabled && m_scrollRange > 0 && trackSize > 0) {
        const int thumbLimit = trackEnd - fixedExtent;
        if (m_thumbDragActive) {
            thumbStart = horizontal
                ? cursor.x - m_thumbDragOffset.x
                : cursor.y - m_thumbDragOffset.y;
            if (thumbStart < trackStart) {
                thumbStart = trackStart;
            }
            if (thumbStart > thumbLimit) {
                thumbStart = thumbLimit;
            }
        } else {
            thumbStart = trackStart + (m_scrollPosition * (thumbLimit - trackStart)) / m_scrollRange;
        }
        thumbEnd = thumbStart + fixedExtent;
    }

    for (int partIndex = kFittingRoomScrollPartLeading;
         partIndex <= kFittingRoomScrollPartTrailing;
         ++partIndex) {
        RectBounds rect = m_bounds;
        const FittingRoomScrollPart part = static_cast<FittingRoomScrollPart>(partIndex);

        if (horizontal) {
            switch (part) {
            case kFittingRoomScrollPartLeading:
                rect.right = m_bounds.left + fixedExtent;
                break;
            case kFittingRoomScrollPartPageBeforeThumb:
                rect.left = trackStart;
                rect.right = thumbStart;
                break;
            case kFittingRoomScrollPartThumb:
                rect.left = thumbStart;
                rect.right = thumbEnd;
                break;
            case kFittingRoomScrollPartPageAfterThumb:
                rect.left = thumbEnd;
                rect.right = trackEnd;
                break;
            case kFittingRoomScrollPartTrailing:
                rect.left = m_bounds.right - fixedExtent;
                break;
            default:
                break;
            }
        } else {
            switch (part) {
            case kFittingRoomScrollPartLeading:
                rect.bottom = m_bounds.top + fixedExtent;
                break;
            case kFittingRoomScrollPartPageBeforeThumb:
                rect.top = trackStart;
                rect.bottom = thumbStart;
                break;
            case kFittingRoomScrollPartThumb:
                rect.top = thumbStart;
                rect.bottom = thumbEnd;
                break;
            case kFittingRoomScrollPartPageAfterThumb:
                rect.top = thumbEnd;
                rect.bottom = trackEnd;
                break;
            case kFittingRoomScrollPartTrailing:
                rect.top = m_bounds.bottom - fixedExtent;
                break;
            default:
                break;
            }
        }

        if (PointInRect(localY, localX, &rect)) {
            return part;
        }
    }

    return kFittingRoomScrollPartNone;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Owner callback [UID:0002DH]:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void FittingRoomListPane::OnScrollPositionChanged(
    unsigned char orientation,
    short oldPosition,
    short newPosition)
{
    (void)orientation;

    if (oldPosition == newPosition) {
        return;
    }

    m_scrollPosition = newPosition;

    FittingRoomScrollPane* scrollPane = m_scrollPane;
    if (scrollPane->m_scrollPosition != newPosition) {
        scrollPane->m_scrollPosition = newPosition;
        scrollPane->Invalidate();
    }

    UpdateScrollBar();
    Invalidate();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact behavior preservation: these blocks retain both cursor/origin calls, uninitialized-invalid-origin behavior, signed `idiv`, branch-specific range handling, short truncation, no extra guards, exact invalidation order, and three-argument callback ABI.
- Compile/source closure: UID000053 provides the complete callback-owner type before UID000054; UID000054 declares the list as a friend; the callback stays public for the child notification contract; and the nested emitter order prevents incomplete-type failures in both the target call and later list constructor/method bodies.
- Seven-block re-audit: UID0002D9 now sees a complete `FittingRoomListPane`; UID000054 has the required friendship; UID0002D5/UID0002D2/UID0002D8 use only declarations present in UID000054; UID0002DH sees both complete classes and may legally write private scroll state; and the UID000053 declaration is the single compile-visible field contract. No accepted body or behavioral conclusion changes.
- Human-source shape: class methods, enum constants, exact-size source fields, inherited Pane accessor, friendship, and a source callback expression replace decompiler temporaries, raw virtual slots, public raw state, invented setters, and inlined cross-class field writes.
- Naming convention: mirrors accepted scroll-pane family names and Y-first `Point` convention while retaining FittingRoom-specific type names.

## Final Recommendation

- Applied C2D9-01 through C2D9-37, C2D9-39 through C2D9-55, and C2D9-57 through C2D9-59 exactly. B001 applied the ordinary-document claims; the supervisor separately applied and validated C2D9-35/36/37/47/57/58/59 in manual coverage. C2D9-38 and C2D9-56 remain excluded assignment-boundary statements. No declared additional targets exist.
- Replaced UID0002D9 formal C++, title/source name, summary, behavior/formula, evidence, negative evidence, history, score, and position.
- Added the complete UID000053 formal declaration at file position `10`, preserved its complete method/evidence history, and retained canonical owner/emitter UID0000JE.
- Added UID000054 formal declaration with `friend class FittingRoomListPane`, preserved constructor/vtable/layout/history evidence, and routed its physical emitter through UID000053 at child position `10` while retaining canonical owner UID0000JE.
- Repaired UID0002D5, UID0002D2, UID0002D8, and UID0002DH formal signatures/bodies and explanatory text without losing existing evidence; then normalized UID0002DF, UID0002DI, UID0002DN, and UID0002DS to the same compile-visible scroll-state vocabulary after Gate 2 exposed the old aliases.
- Retain UID0000JE semantic ownership and UID0000WR aggregate disposition; the UID000053 -> UID000054 emitter edge is source ordering, not ownership transfer.
- Keep UID0002DA non-reconstructable/non-emitting, keep UID000493/UID000494 exact children, and set only the accepted interaction source positions.
- No item remains no-owner because of this report; no new file/UID is required.
- Future work outside scope: a project-wide final symbol-spelling audit may standardize FittingRoom's `m_hotPart` / `m_scrollSkinIndex` aliases and the two unused list selection-state byte names, but current names/layout are implementation-ready, match direct field widths/offsets and existing exact children, and must not be replaced by raw labels. `m_scrollPosition` / `m_scrollRange`, `GetParentPane`, and `UpdatePositionFromCursor` are already closed current vocabulary, not open candidates.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0041e970-0x0041eb24.FittingRoomScrollPaneUpdateThumbDragScroll.md`.
- Current callback verification: applied at D1, SHA256 `9E94030BA815BD9B1EA430D328A811E2E8C82651D883E9F8C4F268573BDD3152`, validator command16713 exit `0` / `ok:1`.
- Rename source-facing title/method to `FittingRoomScrollPane::UpdatePositionFromCursor`.
- Set `92/94`, retain owner/emitter `000054`, reconstructable true, set position `80`.
- Replace formal block with the exact target block above.
- Replace Item Summary with a no-duplication summary covering exact 436-byte body/hash, two caller sites, Y/X ABI, two origin passes, exact horizontal/vertical formulas, inlined orientation callback, owner/child update order, and twelve-byte post-padding.
- Incorporate exact formula derivation, signedness, conversion/clamp asymmetry, callback inlining, parent-slot identity, non-null invariant, caller inventory, bytes/hash, and negative checks.
- Historicalize the x-first signature, thumb-only name, fixed-extent formulation, added guards/clamps, `GetOwnerListPane`, sender-pointer callback, and direct cross-class source body.

## Recommended Support Doc Changes

- Historical B001 callback verification: the ten first-callback ordinary destinations are applied and reread at D1-D10, and the bounded Gate 2 repair destinations are reflected in current D2/D3/D9 plus D11-D16. Serial scoped validators command16713-command16722 and command16730-command16738 each exited `0` with `ok:1`; only the pre-existing missing UID0003AM warning appeared on UID000054 and UID0000JE. Supervisor G4/current G5 independently retain the same accepted declaration/order/target/callback semantics.
- `by-class/FittingRoomListPane.md`: set `88/90`, retain canonical owner/emitter `0000JE`, set position `10`, insert the exact formal class declaration, exact `0x12c` layout and method inventory, public orientation callback declaration, `[[CHILDREN]]`, nested UID000054 order, legal-access rationale, and current generated-marker evidence while preserving every constructor/cleanup/lifecycle/paint/input/geometry/vector-helper/destructor fact and historical correction.
- `by-class/FittingRoomScrollPane.md`: set `90/92`, retain canonical owner `0000JE`, change physical emitter to `000053`, retain position `10`, insert the exact formal class declaration with `friend class FittingRoomListPane`, record Y/X layout, method/callback contract, dependency-safe source order, and superseded aliases while preserving all existing constructor/vtable/layout evidence.
- `by-memory/0x0041e8b0-0x0041e970.FittingRoomScrollPaneProcessActivePart.md`: set `90/92`, position `70`, replace formal block with exact Y/X caller block, rename target references, preserve all caller/callee/padding/hot-state evidence.
- `by-memory/0x0041d870-0x0041da51.FittingRoomScrollPaneOnMouseEvent.md`: set `90/92`; replace only coordinate/field naming defects in the formal and prose; preserve complete event-kind, capture, timer, and invalidation behavior.
- `by-memory/0x0041e1d0-0x0041e4ed.FittingRoomScrollPaneHitTestPart.md`: set `90/92`; change signature/PointInRect contract to `(localY, localX)` and use accepted source aliases without deleting current geometry/caller evidence.
- `by-memory/0x0041f0b0-0x0041f0fd.FittingRoomListPaneOnScrollPositionChanged.md`: set `90/92`; replace sender parameter with orientation, preserve both direct zero-argument callsites, exact body, non-null child invariant, and target-inline identity.
- `by-memory/0x0041eb30-0x0041eb8c.FittingRoomScrollPaneResetScrollStateRaw.md`: retain `88/90`, owner/emitter `000054`, set position `90`; preserve raw/no-direct-route evidence.
- `by-memory/0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar.md`, `by-memory/0x0041f100-0x0041f219.FittingRoomListPaneResetScrollPosition.md`, `by-memory/0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md`, and `by-memory/0x00420840-0x00420949.FittingRoomListPaneOnScrollStep.md`: preserve exact behavior/scores/routes while using `m_scrollPosition` / `m_scrollRange` consistently in every formal and current explanation; retain old aliases only as explicit history.
- `by-memory/0x0041e7f0-0x0041e8af.FittingRoomScrollPaneBeginPartPressRaw.md` and `by-memory/0x0041e4f0-0x0041e777.FittingRoomScrollPaneGetPartRect.md`: preserve all behavior/scores/routes and use `UpdatePositionFromCursor` as the current target label.
- `by-file/FittingRoom.md`: retain `88/90`; add UID000053-first/UID000054-nested declaration order, friendship, exact callback-inline/Y-X note, and the sole current position/range/accessor/method vocabulary while preserving its complete module inventory.
- `by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md`: retain `88/89`, owner/emitter `0000JE`, blank aggregate C++; refresh the FittingRoomScrollPane child summary only if needed for no-loss consistency.
- Read-only generated verification after callback and repair: `auto-generated/NexusTK/cashshop/FittingRoom.cpp` must contain exactly one complete `FittingRoomListPane` declaration before exactly one complete `FittingRoomScrollPane` declaration, one corrected target method, corrected support bodies, zero UID000053/UID000054 Empty Emitter Markers, no incomplete-type/private-access/undeclared-field defect, no current old accessor vocabulary, and no duplicate callback body introduced by UID0002D9.

## Score And Metadata Recommendation

| Item | Before callback | Applied current | Metadata disposition |
| --- | --- | --- | --- |
| UID0002D9 target | 87/89 | 92/94 | retain owner/emitter 000054, true; position 80 |
| UID000053 list class | 86/88 | 88/90 | retain canonical owner/emitter 0000JE, true; position 10 |
| UID000054 scroll class | 88/90 | 90/92 | retain canonical owner 0000JE, change emitter to 000053, true; child position 10 |
| UID0002D2 mouse | 88/90 | 90/92 | retain owner/emitter 000054, true |
| UID0002D8 hit-test | 88/90 | 90/92 | retain owner/emitter 000054, true |
| UID0002D5 dispatcher | 87/90 | 90/92 | retain owner/emitter 000054, true; position 70 |
| UID0002DH callback | 87/90 | 90/92 | retain owner/emitter 000053, true |
| UID0002DB reset | 88/90 | retain | retain owner/emitter 000054, true; position 90 |
| UID0000JE file | 88/90 | retain | source root unchanged |
| UID0000WR aggregate | 88/89 | retain | aggregate route/no-body unchanged |

- Reason target is higher: every current behavior/C++ blocker was directly resolved, including exact arithmetic, source callback shape, callback-owner declaration, legal private access, and complete-type source order.
- Reason target is not `95/95`: stripped original symbol spellings, two otherwise-unreferenced list selection-state byte names, and exact historical header/source naming are inferred, not recovered.
- Reason target is not lower: bounds, bytes, caller set, ABI, formulas, field widths, owner route, callback equivalence, and range are direct or independently corroborated.
- UID000053 rises only to `88/90`: the blank-class/compiler-closure blocker is resolved with an exact-size declaration and source order, while broad item/preview field spellings and the two unused selection-state byte names remain inferential.
- Score-improvement attempt: named blockers were not merely cataloged; target/caller/callback/list-constructor/list-update disassembly, endpoint bytes, peer methods, class/layout docs, vtable semantics, generated dependency order, class-to-class emitter precedent, and current manual rows were all checked and converted to implementation-ready recommendations.

## Open Questions With Attempted Resolution

- Exact original target name: no symbol survives. Calls for both thumb and non-thumb active parts reject `UpdateThumbDragScroll`; peer method naming and behavior select `UpdatePositionFromCursor` with high probability.
- Exact callback arg1 name/type: body does not consume it, but direct callers pass zero and homolog scroll callbacks use orientation. Select `unsigned char orientation`; sender pointer is rejected.
- Exact member spellings: no PDB exists. Usage plus established FittingRoom child formals select `m_scrollSkinIndex`, `m_scrollStyle`, `m_thumbDragActive`, `m_orientation`, `m_scrollPosition`, `m_scrollRange`, `m_scrollEnabled`, `m_hotPart`, `m_activePart`, and `m_thumbDragOffset`.
- Current/range vocabulary: Gate 2 exposed simultaneous current aliases in emitted child definitions. Exact offsets and the accepted class declaration select `m_scrollPosition` / `m_scrollRange` for all current source; `m_currentPosition`, `m_maxPosition`, and `m_maxScrollPosition` are preserved only as historical names and no longer block compilation.
- Exact invalid-origin intent: both rect locals can remain uninitialized if origin is invalid. This is direct binary/source-shape behavior, not a license to add fallback initialization.
- Zero/negative denominator behavior: exhaustive full-function disassembly proves no guard. Preserve signed division and caller invariant; do not "fix" it.
- Owner access: Pane slot map proves `GetParentPane`; no unresolved owner accessor remains.
- Callback-owner declaration: UID000053 is not optional support. Its full `ControlPane`-derived declaration is selected from the current constructor/destructor/method inventory and exact `0x12c` layout; a reduced declaration is rejected because the file already contains the complete class method family.
- Cross-class access: recurring direct list-to-scroll field accesses select `friend class FittingRoomListPane` in UID000054. Public fields and invented setters are rejected as less source-faithful.
- Source placement/order: direct class/file evidence selects current FittingRoom route. UID000053 emits at file position `10`; UID000054 emits as its first child at position `10`; this closes both complete-type dependencies without changing canonical ownership.
- List selection-state band: constructor proves an unaligned word store at `+0x121`, object size `0x12c`, timer id `+0x124`, and state byte `+0x128`; exhaustive modeled-method scans find no semantic read of surrounding `+0x120/+0x123`. The local packed state band is the strongest exact layout, with conservative source-facing byte names and no raw-offset access.
- No unresolved question blocks implementation. Remaining original-spelling/header uncertainty is reflected in sub-95 confidence rather than blank or uncompilable source.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Historical B001 handoff: B001 inspected `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, and `by-memory/-coverage-report.md` read-only and supplied the exact no-loss row actions below without editing those roots.
- Current supervisor readback: the supervisor applied every exact row below, including inserted UID000493/UID000494 and UID0002DI/UID0002DN/UID0002DS, then validated the roots serially under commands16777-command16779. Each exact row occurs once in its intended current root.
- Current identities: by-class SHA256 `4141F8751FEDA5524D90BEBBD04DAC38B4EE6EEB292DC911CC7F69BEB86C9DA3`, `257,954` bytes / `624` lines; by-file SHA256 `0373F1963A562013ECC49FCBA17CDFA63661311CA38BDA37E2D31F7A1B8F72C0`, `154,908` bytes / `317` lines; by-memory SHA256 `620E7433D9758A4D63E77BCC68A9A8DBF2EC55A000FB0F4B5B29770EADFABDB8`, `1,991,305` bytes / `4,574` lines.
- The `File/placement: replace` labels below are preserved historical accepted-handoff instructions; their actions are complete and the literal row bodies are retained as current application evidence.
- Generated tracker rows are validator-owned and must not be edited manually.

File/placement: replace UID000054 in `by-class/-coverage-report.md`:

```text
- [UID:000054][FittingRoomScrollPane](by-class/FittingRoomScrollPane.md) : reconstructable : 90% : very strong : FittingRoom-local Pane-derived scrollbar declaration with exact 0x110 natural tail, Y-first Point drag offsets, orientation/current/range/enabled/highlight/active fields, mouse/timer/draw/hit-test/geometry/raw-state/process/cursor-update/reset method inventory, exact child source order, FittingRoomListPane parent-callback contract and narrow friend access for repeated direct child-state synchronization, vtable/resource and inline-construction evidence, compiler-generated [[CHILDREN]] route physically nested beneath UID000053 while canonical ownership remains FittingRoom, and no generic ScrollBar ownership.
```

File/placement: replace UID000053 in `by-class/-coverage-report.md`:

```text
- [UID:000053][FittingRoomListPane](by-class/FittingRoomListPane.md) : reconstructable : 88% : very strong : Fitting-room ControlPane-derived list owner with a complete compile-visible 0x12c declaration, exact constructor and owned 0x110 FittingRoomScrollPane child at +0x11c, resize/move/scroll-management/callback/reset/layer/paint/keyboard/input/timer/slot-geometry/hit-test/selection-index/timer-cleanup/destructor inventory, orientation/old/new OnScrollPositionChanged contract, dependency-safe UID000054-first child emission, selected-entry vector children UID00030R/UID00030T and 0xb4 entry evidence, raw cleanup and compiler-wrapper exclusions, and preserved source-name caps for broader item/preview and unused selection-state bytes.
```

File/placement: replace UID0000JE in `by-file/-coverage-report.md`:

```text
- [UID:0000JE][FittingRoom](by-file/FittingRoom.md) : reconstructable : 88% : strong : Fitting-room cash-shop module covering dialog, list-pane, local scroll-pane, catalog/item-state, download-progress, controls, selection/vector helpers, read-only data, and mixed islands; the interaction tail now has exact Y/X input contracts, behavior-exact cursor-to-position arithmetic, an orientation callback, a complete FittingRoomListPane declaration followed by nested FittingRoomScrollPane declaration/children, narrow friend access for observed direct synchronization, and dependency-safe source order while unrelated mixed aggregates retain their existing routes.
```

File/placement: replace UID0000WR in `by-memory/-coverage-report.md`:

```text
    - [UID:0000WR][0x0041ba40-0x004245f5.FittingRoomUiCore](by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md) 0x0041ba40-0x004245f5 | aggregate | FittingRoomUiCore : reconstructable : 88% : strong : Fitting-room dialog/list/scroll/state/control class cluster with exact FittingRoomDialog, FittingRoomScrollPane, FittingRoomListPane, text-button/control children, item/catalog helpers, mixed-island ownership boundaries, and a non-monolithic aggregate policy; exact children carry source bodies and route through FittingRoom.
```

File/placement: replace the interaction rows in `by-memory/-coverage-report.md`:

```text
        - [UID:0002D2][0x0041d870-0x0041da51.FittingRoomScrollPaneOnMouseEvent](by-memory/0x0041d870-0x0041da51.FittingRoomScrollPaneOnMouseEvent.md) 0x0041d870-0x0041da51 | method | FittingRoomScrollPaneOnMouseEvent : reconstructable : 90% : very strong : Exact EventHandler-view mouse method with vtable-only reachability, event-kind move/down/up flow, Y-at-+8/X-at-+0xc point contract, bounds/range gates, hit-test, capture/release, thumb Y/X drag-offset setup, active/highlight state, 200 ms repeat timer, ProcessActivePart dispatch, reset cleanup, invalidations, and source-ready formal C++.
        - [UID:0002D3][0x0041da60-0x0041da65.FittingRoomScrollPaneDefaultFalseVirtual](by-memory/0x0041da60-0x0041da65.FittingRoomScrollPaneDefaultFalseVirtual.md) 0x0041da60-0x0041da65 | virtual stub | FittingRoomScrollPaneDefaultFalseVirtual : reconstructable : 91% : very strong : Exact vtable-referenced source-authored false-return virtual with bounded six-byte body and class declaration route; descriptive slot name remains inferred without affecting behavior.
        - [UID:0002D4][0x0041da70-0x0041daa3.FittingRoomScrollPaneOnTimer](by-memory/0x0041da70-0x0041daa3.FittingRoomScrollPaneOnTimer.md) 0x0041da70-0x0041daa3 | method | FittingRoomScrollPaneOnTimer : reconstructable : 89% : very strong : Exact TimerHandler-view repeat callback checking timer id zero and active-part sentinel, calling ProcessActivePart, rescheduling 30 ms repeat work, preserving adjusted inherited receiver semantics, and emitting source-ready C++ through FittingRoomScrollPane.
        - [UID:0002D6][0x0041dab0-0x0041e1c6.FittingRoomScrollPaneOnDraw](by-memory/0x0041dab0-0x0041e1c6.FittingRoomScrollPaneOnDraw.md) 0x0041dab0-0x0041e1c6 | method | FittingRoomScrollPaneOnDraw : reconstructable : 88% : strong : Exact 0x716-byte primary-vtable draw method with FittingRoom EPF/palette resources, orientation/style/state fields, part rectangles, frame selection, padding, field/resource refs, draw-helper callees, and formal source C++.
        - [UID:0002D8][0x0041e1d0-0x0041e4ed.FittingRoomScrollPaneHitTestPart](by-memory/0x0041e1d0-0x0041e4ed.FittingRoomScrollPaneHitTestPart.md) 0x0041e1d0-0x0041e4ed | helper method | FittingRoomScrollPaneHitTestPart : reconstructable : 90% : very strong : Exact bounded part hit-test with two callers, localY/localX ABI, cursor/origin conversion, horizontal/vertical inline geometry, enabled/range/drag fields, five-part enum loop, Y-first PointInRect contract, padding, and source-ready formal C++ through FittingRoomScrollPane.
        - [UID:0002D7][0x0041e4f0-0x0041e777.FittingRoomScrollPaneGetPartRect](by-memory/0x0041e4f0-0x0041e777.FittingRoomScrollPaneGetPartRect.md) 0x0041e4f0-0x0041e777 | helper method | FittingRoomScrollPaneGetPartRect : reconstructable : 88% : strong : Exact bounded rectangle helper with modeled and raw-child callers, output writes, sentinel behavior, orientation/current/range/drag geometry, three-entry size table, disabled page-area behavior, five-part enum, padding, and FittingRoomScrollPane source route.
        - [UID:0002DA][0x0041e780-0x0041e8af.FittingRoomScrollPaneRawPartStateHelpers](by-memory/0x0041e780-0x0041e8af.FittingRoomScrollPaneRawPartStateHelpers.md) 0x0041e780-0x0041e8af | raw helper pair split index | FittingRoomScrollPaneRawPartStateHelpers : non-reconstructable : 90% : very strong : Non-emitting split index over exact reconstructable SetHotPart and BeginPartPress children; live evidence preserves raw starts, no direct raw-start route, exact boundaries/padding, highlight/active state, rectangle invalidation, Y/X thumb offset setup, ProcessActivePart call, and repeat-timer scheduling without duplicating child C++.
            - [UID:000493][0x0041e780-0x0041e7f0.FittingRoomScrollPaneSetHotPartRaw](by-memory/0x0041e780-0x0041e7f0.FittingRoomScrollPaneSetHotPartRaw.md) 0x0041e780-0x0041e7f0 | raw helper | FittingRoomScrollPaneSetHotPartRaw : reconstructable : 89% : very strong : Exact raw SetHotPart source body with no modeled function/direct raw-start route, highlight byte +0x103, none sentinel, old/new GetPartRect invalidations, FittingRoomScrollPane owner/emitter, formal C++, and source position 50.
            - [UID:000494][0x0041e7f0-0x0041e8af.FittingRoomScrollPaneBeginPartPressRaw](by-memory/0x0041e7f0-0x0041e8af.FittingRoomScrollPaneBeginPartPressRaw.md) 0x0041e7f0-0x0041e8af | raw helper | FittingRoomScrollPaneBeginPartPressRaw : reconstructable : 89% : very strong : Exact raw BeginPartPress(part, mouseY, mouseX) source body with no modeled function/direct raw-start route, active byte +0x104, Y/X thumb drag offset, ProcessActivePart dispatch, repeat timer setup, FittingRoomScrollPane owner/emitter, formal C++, and source position 60.
        - [UID:0002D5][0x0041e8b0-0x0041e970.FittingRoomScrollPaneProcessActivePart](by-memory/0x0041e8b0-0x0041e970.FittingRoomScrollPaneProcessActivePart.md) 0x0041e8b0-0x0041e970 | helper method | FittingRoomScrollPaneProcessActivePart : reconstructable : 90% : very strong : Exact dispatcher with mouse/timer/raw callers, cursor and screen-origin conversion, Y/X local ABI, thumb direct path, non-thumb hit-test equality gate, UpdatePositionFromCursor calls, stale-highlight rectangle invalidation/clear, adjacent boundary, formal C++, and source position 70.
        - [UID:0002D9][0x0041e970-0x0041eb24.FittingRoomScrollPaneUpdateThumbDragScroll](by-memory/0x0041e970-0x0041eb24.FittingRoomScrollPaneUpdateThumbDragScroll.md) 0x0041e970-0x0041eb24 | helper method | FittingRoomScrollPaneUpdatePositionFromCursor : reconstructable : 92% : very strong : Exact 436-byte/hash-confirmed cursor-to-position method with two ProcessActivePart callers, localY/localX ABI, two cursor/origin passes, Y/X drag offsets, exact horizontal signed-range and vertical range-plus-one formulas, observed clamp asymmetry and no invented guards, GetParentPane orientation callback source shape, inlined list/child synchronization, invalidation order, twelve-byte post-padding exclusion, formal C++, and source position 80.
        - [UID:0002DB][0x0041eb30-0x0041eb8c.FittingRoomScrollPaneResetScrollStateRaw](by-memory/0x0041eb30-0x0041eb8c.FittingRoomScrollPaneResetScrollStateRaw.md) 0x0041eb30-0x0041eb8c | raw helper | FittingRoomScrollPaneResetScrollStateRaw : reconstructable : 88% : strong : Exact raw reset body with no outside incoming route, repeat-timer removal, active/highlight sentinel clears, old-highlight rectangle invalidation, inherited redraw dispatch, adjacent padding, formal C++, FittingRoomScrollPane route, and source position 90.
        - [UID:0002DF][0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar](by-memory/0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar.md) 0x0041ee10-0x0041f0b0 | method | FittingRoomListPaneUpdateScrollBar : reconstructable : 87% : very strong : Exact list scrollbar refresh with nine callers, catalog/category inputs, visible-entry and page-size math, range/current clamps, owned child visibility/state synchronization, invalidations, adjacent boundaries, FittingRoomListPane owner/emitter, and formal C++.
        - [UID:0002DH][0x0041f0b0-0x0041f0fd.FittingRoomListPaneOnScrollPositionChanged](by-memory/0x0041f0b0-0x0041f0fd.FittingRoomListPaneOnScrollPositionChanged.md) 0x0041f0b0-0x0041f0fd | callback | FittingRoomListPaneOnScrollPositionChanged : reconstructable : 90% : very strong : Exact three-argument orientation/old/new callback with two OnInputEvent callsites passing vertical orientation zero, equal-value no-op, list +0x108 and owned child +0xfe synchronization, optional child invalidation, UpdateScrollBar, final owner invalidation, non-null child invariant, UID0002D9 inline identity, and source-ready formal C++.
```

File/placement: replace UID0002DI in `by-memory/-coverage-report.md` immediately after the `0x0041f0fd-0x0041f100` alignment-padding row and before the `0x0041f219-0x0041f220` alignment-padding row:

```text
        - [UID:0002DI][0x0041f100-0x0041f219.FittingRoomListPaneResetScrollPosition](by-memory/0x0041f100-0x0041f219.FittingRoomListPaneResetScrollPosition.md) 0x0041f100-0x0041f219 | method | FittingRoomListPaneResetScrollPosition : reconstructable : 88% : very strong : Exact source-ready FittingRoomListPane::ResetScrollPosition method with modeled 0x119 bounds, sole FittingRoomDialogOnCommand caller, category-3 selected-entry scan at 0xb4 stride, special-preview byte handling, list and owned-child m_scrollPosition reset, conditional child invalidation, UpdateScrollBar, preserved duplicate list invalidation, vector-subscript throw support, no pointer route, adjacent padding, FittingRoomListPane/FittingRoom source route, and formal C++.
```

File/placement: replace UID0002DN in `by-memory/-coverage-report.md` immediately after the `0x0041fcc5-0x0041fcd0` alignment-padding row and before UID0002DO `FittingRoomListPaneOnInputEventJumpTables`:

```text
        - [UID:0002DN][0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent](by-memory/0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md) 0x0041fcd0-0x004207ce | method | FittingRoomListPaneOnInputEvent : reconstructable : 88% : very strong : Exact source-ready virtual FittingRoomListPane::OnInputEvent method with 0xafe boundary, vtable-only reachability and no ordinary direct callers, event type 3 selection/cart flow, event type 7 scroll flow, singleton/global dependencies, visible-slot and catalog-index validation, 0xb4 selected-entry layout, item-part preview/equipment side effects, current m_scrollPosition/m_scrollRange callback path, delegated child/base event handling, unique callee/helper set, adjacent compiler jump-table tail UID0002DO, FittingRoomListPane/FittingRoom source route, and formal C++.
```

File/placement: replace UID0002DS in `by-memory/-coverage-report.md` immediately after UID0002DO `FittingRoomListPaneOnInputEventJumpTables` and before the `0x00420949-0x00420950` alignment-padding row:

```text
        - [UID:0002DS][0x00420840-0x00420949.FittingRoomListPaneOnScrollStep](by-memory/0x00420840-0x00420949.FittingRoomListPaneOnScrollStep.md) 0x00420840-0x00420949 | method | FittingRoomListPaneOnScrollStep : reconstructable : 88% : very strong : Exact source-ready FittingRoomListPane::OnScrollStep TimerHandler-facet callback with 0x109 bounds, vtable-only ownership and adjusted binary receiver, direction 1/2 dispatch, current child m_scrollPosition/m_scrollRange reads, zero/range clamps, child/list state writes and invalidations, two UpdateScrollBar callsites, repeat scheduling with direction and interval 50, adjacent jump-table/padding boundaries, complete nonblank FittingRoomListPane/FittingRoom owner-emitter route, and formal C++.
```

- Actor distinction: B001 did not apply these rows because all `-coverage-report.md` files are supervisor-owned collision points under the skill and assignment; the supervisor applied and validated them.

## Follow-Up Actions

- Supervisor actions: perform fresh literal Gate 1 on this exact post-reconciliation report, independently verify C2D9-01..59, D1-D16, the applied manual roots, and current generated G5 for Gate 2, then execute only through the supervisor lifecycle.
- A-agent actions: none.
- B001 actions: callback implementation and report reconciliation are complete. No technical or manual-handoff blocker remains; B001 must not run report lifecycle commands.

## Confidence

- Recommendation confidence: very strong (`94`) for target behavior, route, callback ABI, friendship, and declaration order.
- Score confidence: strong; `92/94` reflects resolved implementation blockers while respecting stripped-symbol/header uncertainty and the two unused list selection-state byte names.
- Remaining uncertainty is lexical, not structural. It does not justify IDA-style names, blank C++, public raw state, invented setters, extra guards, or incomplete declarations.

## Validator Results

- Shared command workdir: `E:\NTK\GhidraBridge\source-3\project-documentation`.
- All commands were run serially by B001 under the accepted callback. Every command used `--mode file --apply --queue-timeout 240`, exited `0`, reported `ok:1`, updated projected stats, reported target stats as not present in generated stats lists, and deferred its generated refresh to the validator background queue.

| Command | Timestamp | Exact command | Result | Relevant changes / warnings |
| --- | --- | --- | --- | --- |
| `000000016713` | `2026-07-23T01:01:20-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x0041e970-0x0041eb24.FittingRoomScrollPaneUpdateThumbDragScroll.md --apply --queue-timeout 240` | exit `0`; `ok:1`; generated refresh deferred | UID0002D9 completion `92`, confidence `94`, position `80`, formal registry hash changed, reference-index add UID0002DH; no warning. |
| `000000016714` | `2026-07-23T01:02:30-04:00` | `python .\tools\validator.py --mode file --file by-class/FittingRoomListPane.md --apply --queue-timeout 240` | exit `0`; `ok:1`; generated refresh deferred | UID000053 completion `88`, confidence `90`, position `10`, blank-to-block formal, reference-index add UID0002D9; no warning. |
| `000000016715` | `2026-07-23T01:03:40-04:00` | `python .\tools\validator.py --mode file --file by-class/FittingRoomScrollPane.md --apply --queue-timeout 240` | exit `0`; `ok:1`; generated refresh deferred | UID000054 completion `90`, confidence `92`, emitter UID0000JE -> UID000053, position `10`, blank-to-block formal; one pre-existing `missing_ref_uid 0003AM` warning. |
| `000000016716` | `2026-07-23T01:04:29-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x0041e8b0-0x0041e970.FittingRoomScrollPaneProcessActivePart.md --apply --queue-timeout 240` | exit `0`; `ok:1`; generated refresh deferred | UID0002D5 completion `90`, confidence `92`, position `70`, formal registry hash changed; no warning. |
| `000000016717` | `2026-07-23T01:05:12-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x0041d870-0x0041da51.FittingRoomScrollPaneOnMouseEvent.md --apply --queue-timeout 240` | exit `0`; `ok:1`; generated refresh deferred | UID0002D2 completion `90`, confidence `92`, formal registry hash changed; no warning. |
| `000000016718` | `2026-07-23T01:05:51-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x0041e1d0-0x0041e4ed.FittingRoomScrollPaneHitTestPart.md --apply --queue-timeout 240` | exit `0`; `ok:1`; generated refresh deferred | UID0002D8 completion `90`, confidence `92`, formal registry hash changed; no warning. |
| `000000016719` | `2026-07-23T01:06:43-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x0041f0b0-0x0041f0fd.FittingRoomListPaneOnScrollPositionChanged.md --apply --queue-timeout 240` | exit `0`; `ok:1`; generated refresh deferred | UID0002DH completion `90`, confidence `92`, formal registry hash changed; no warning. |
| `000000016720` | `2026-07-23T01:07:12-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x0041eb30-0x0041eb8c.FittingRoomScrollPaneResetScrollStateRaw.md --apply --queue-timeout 240` | exit `0`; `ok:1`; generated refresh deferred | UID0002DB position `90`; no score/formal change and no warning. |
| `000000016721` | `2026-07-23T01:07:44-04:00` | `python .\tools\validator.py --mode file --file by-file/FittingRoom.md --apply --queue-timeout 240` | exit `0`; `ok:1`; generated refresh deferred | UID0000JE score/path retained; four occurrences of the same pre-existing `missing_ref_uid 0003AM` warning. |
| `000000016722` | `2026-07-23T01:08:28-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md --apply --queue-timeout 240` | exit `0`; `ok:1`; generated refresh deferred | UID0000WR score/owner/emitter/blank formal retained; no warning. This deferred refresh produced historical first-callback G1. |

- Bounded Gate 2 vocabulary closure used the same workdir and serial scoped-file pattern. All nine commands exited `0`, reported `ok:1`, updated projected stats, and deferred generated refresh.

| Command | Timestamp | Exact command | Result | Relevant changes / warnings |
| --- | --- | --- | --- | --- |
| `000000016730` | `2026-07-23T01:31:54-04:00` | `python .\tools\validator.py --mode file --file by-class/FittingRoomScrollPane.md --apply --queue-timeout 240` | exit `0`; `ok:1`; generated refresh deferred | Sole current member/accessor/method vocabulary applied; one pre-existing `missing_ref_uid 0003AM` warning; `reference_index_add 0002DN`. |
| `000000016731` | `2026-07-23T01:32:49-04:00` | `python .\tools\validator.py --mode file --file by-class/FittingRoomListPane.md --apply --queue-timeout 240` | exit `0`; `ok:1`; generated refresh deferred | List method table/direct-access prose normalized; no warning. |
| `000000016732` | `2026-07-23T01:33:34-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar.md --apply --queue-timeout 240` | exit `0`; `ok:1`; generated refresh deferred | UID0002DF formal/prose normalized; generated registry hash changed; no warning. |
| `000000016733` | `2026-07-23T01:33:59-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x0041f100-0x0041f219.FittingRoomListPaneResetScrollPosition.md --apply --queue-timeout 240` | exit `0`; `ok:1`; generated refresh deferred | UID0002DI formal/prose normalized; generated registry hash changed; no warning. |
| `000000016734` | `2026-07-23T01:34:32-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md --apply --queue-timeout 240` | exit `0`; `ok:1`; generated refresh deferred | UID0002DN formal/prose normalized; generated registry hash changed; no warning. |
| `000000016735` | `2026-07-23T01:35:15-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x00420840-0x00420949.FittingRoomListPaneOnScrollStep.md --apply --queue-timeout 240` | exit `0`; `ok:1`; generated refresh deferred | UID0002DS formal/prose normalized; generated registry hash changed; no warning. |
| `000000016736` | `2026-07-23T01:36:35-04:00` | `python .\tools\validator.py --mode file --file by-file/FittingRoom.md --apply --queue-timeout 240` | exit `0`; `ok:1`; generated refresh deferred | File-level current vocabulary/source-shape note added; four occurrences of the same pre-existing `missing_ref_uid 0003AM` warning. |
| `000000016737` | `2026-07-23T01:37:00-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x0041e7f0-0x0041e8af.FittingRoomScrollPaneBeginPartPressRaw.md --apply --queue-timeout 240` | exit `0`; `ok:1`; generated refresh deferred | UID000494 current target label normalized; no warning. |
| `000000016738` | `2026-07-23T01:37:33-04:00` | `python .\tools\validator.py --mode file --file by-memory/0x0041e4f0-0x0041e777.FittingRoomScrollPaneGetPartRect.md --apply --queue-timeout 240` | exit `0`; `ok:1`; generated refresh deferred | UID0002D7 current target label normalized; no warning. This historical B001 command produced bounded vocabulary-repair checkpoint G2. |

- Supervisor-owned manual coverage application and validation used the same workdir and ran serially after the complete no-loss handoff was accepted. These commands were supervisor actions, not B001 actions.

| Command | Timestamp | Exact command | Result | Relevant changes / warnings |
| --- | --- | --- | --- | --- |
| `000000016777` | `2026-07-23T02:25:46-04:00` | `python .\tools\validator.py --mode file --file by-class/-coverage-report.md --apply --queue-timeout 240` | exit `0`; `ok:1`; foreground generated refresh deferred | Applied and validated the exact UID000054 and UID000053 class rows. Background result: `tools/validator_queue/generated_refresh_results/zz-generated-refresh-000000016777-06eea8f21635.result.json`; unrelated existing generator diagnostics do not affect the accepted rows. |
| `000000016778` | `2026-07-23T02:25:53-04:00` | `python .\tools\validator.py --mode file --file by-file/-coverage-report.md --apply --queue-timeout 240` | exit `0`; `ok:1`; foreground generated refresh deferred | Applied and validated the exact UID0000JE file row. Background result: `tools/validator_queue/generated_refresh_results/zz-generated-refresh-000000016778-a5fe073f6344.result.json`; unrelated existing generator diagnostics do not affect the accepted row. |
| `000000016779` | `2026-07-23T02:26:03-04:00` | `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --queue-timeout 240 --wait-generated` | exit `0`; `ok:1`; foreground generated refresh completed | Applied and validated every exact memory row, including inserted UID000493/UID000494 and UID0002DI/UID0002DN/UID0002DS. Unrelated pre-existing `missing_ref_uid` warnings remain for UID0003MT, UID0003VS, UID00039L, and UID0003T6; existing generator diagnostics are unrelated and the target rows validated. This command produced supervisor wait-generated checkpoint G4. |

- Historical generated readback G1: command `000000016722`, timestamp `2026-07-23T01:08:28-04:00`, source `deferred-generated-refresh`, SHA256 `987A1973C1EA97D51FCC710E5160493B00F11FCDD8E56A7B1A5034A36AF1F14E`, `89,341` bytes / `2,568` lines. Gate 2 found undeclared old member aliases in four emitted list-child definitions.
- Historical generated readback G2: B001 command `000000016738`, timestamp `2026-07-23T01:37:33-04:00`, source `deferred-generated-refresh`, SHA256 `77F61321FDFD17411B5F4D5731BA65F1EB753DB69F73D7F43150953615937B01`, `89,331` bytes / `2,568` lines.
- Historical generated readback G3: command `000000016762`, timestamp `2026-07-23T02:01:00-04:00`, source `foreground-generated-refresh`, SHA256 `CBAC3BAD71F16100DD5A4AE7788867759CA3288BE5CF8C3AF99ECD15DF44C9B7`, `89,333` bytes / `2,568` lines.
- Supervisor wait-generated readback G4: command `000000016779`, timestamp `2026-07-23T02:26:03-04:00`, source `foreground-generated-refresh`, SHA256 `A50D45B359DB5F78334A62D5E4837E1C3D0D89E6C9930DE67D67BB97930FD517`, `89,333` bytes / `2,568` lines.
- Current generated readback G5: the live generated header advanced to command `000000016780`, timestamp `2026-07-23T02:26:09-04:00`, source `foreground-generated-refresh`, while retaining G4 SHA256 `A50D45B359DB5F78334A62D5E4837E1C3D0D89E6C9930DE67D67BB97930FD517` and `89,333` bytes / `2,568` lines. No initiating command details beyond the validator-owned header are attributed here.
- Current G5 shape counts: one `class FittingRoomListPane : public ControlPane`, one later `class FittingRoomScrollPane : public Pane`, one `friend class FittingRoomListPane`, one `FittingRoomScrollPane::UpdatePositionFromCursor` body, one `FittingRoomListPane::OnScrollPositionChanged` body, zero UID000053 Empty Emitter Markers, and zero UID000054 Empty Emitter Markers.
- Current G5 vocabulary counts: `m_currentPosition` `0`, `m_maxPosition` `0`, `m_maxScrollPosition` `0`, `GetOwnerListPane` `0`, `GetOwnerPane` `0`, `m_scrollPosition` `32`, `m_scrollRange` `18`, and `UpdatePositionFromCursor` `4`.
- `UpdateThumbDragScroll` remains once only inside the immutable by-memory filename in the generated UID comment. It is absent from declarations, calls, and source bodies. Other unrelated FittingRoom empty markers remain outside this report's accepted scope.
- No target-specific validator error remains. UID0003AM is a pre-existing missing-reference issue and was not used to excuse any callback defect.

## Changed Files

- Callback-modified ordinary documents and current identities are D1-D16 in `Current Target State`. The bounded Gate 2 vocabulary repair changed D2, D3, D9, and D11-D16; D1/D4-D8/D10 remained byte-identical.
- Same report updated in place: `tools/leaser/Agents/Agent-B001/research/0002D9-FittingRoomScrollPaneUpdateThumbDragScroll-source-quality.md`.
- Read-only generated result: current G5 `auto-generated/NexusTK/cashshop/FittingRoom.cpp` at command16780, SHA256 `A50D45B359DB5F78334A62D5E4837E1C3D0D89E6C9930DE67D67BB97930FD517`, `89,333` bytes / `2,568` lines; B001 did not edit it. G1/G2/G3 and supervisor wait-generated G4 remain historical checkpoints.
- Renamed filesystem paths: none. The target source method changed without renaming its by-memory documentation path.
- Leases: one short B001 lease per ordinary file immediately before its edit/validator; each was released immediately after that file's validator. Final shared lease readback reports zero active leases.
- Manual coverage files modified by B001: none. The supervisor applied and validated all exact C2D9-35/36/37/47/57/58/59 rows under commands16777-command16779. Current roots are by-class `4141F8751FEDA5524D90BEBBD04DAC38B4EE6EEB292DC911CC7F69BEB86C9DA3`, by-file `0373F1963A562013ECC49FCBA17CDFA63661311CA38BDA37E2D31F7A1B8F72C0`, and by-memory `620E7433D9758A4D63E77BCC68A9A8DBF2EC55A000FB0F4B5B29770EADFABDB8`; every exact handoff row occurs once.
- IDA changes: none.
- Report execution: not run. No lifecycle command was run, probed, simulated, or moved.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor Gate 1 accepted exact pre-callback SHA `F83DE2067C87B308D947050A9B63DCE7C14FBBECC052080C599AABEDACC6219A`.
- [x] Updated `by-memory/0x0041e970-0x0041eb24.FittingRoomScrollPaneUpdateThumbDragScroll.md`; D1/command16713.
- [x] Updated `by-class/FittingRoomListPane.md` with the exact UID000053 formal, `88/90`, retained owner/emitter `0000JE`, file position `10`, layout/access/source-order evidence, and `[[CHILDREN]]`; D2/command16714.
- [x] Updated `by-class/FittingRoomScrollPane.md`; D3/command16715.
- [x] Updated `by-memory/0x0041e8b0-0x0041e970.FittingRoomScrollPaneProcessActivePart.md`; D4/command16716.
- [x] Updated `by-memory/0x0041d870-0x0041da51.FittingRoomScrollPaneOnMouseEvent.md`; D5/command16717.
- [x] Updated `by-memory/0x0041e1d0-0x0041e4ed.FittingRoomScrollPaneHitTestPart.md`; D6/command16718.
- [x] Updated `by-memory/0x0041f0b0-0x0041f0fd.FittingRoomListPaneOnScrollPositionChanged.md`; D7/command16719.
- [x] Updated source position only plus source-order evidence in `by-memory/0x0041eb30-0x0041eb8c.FittingRoomScrollPaneResetScrollStateRaw.md`; D8/command16720.
- [x] Updated source-placement/support detail in `by-file/FittingRoom.md`; D9/command16721.
- [x] Refreshed no-loss aggregate context in `by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md`; D10/command16722.
- [x] Read-only verified G1 `auto-generated/NexusTK/cashshop/FittingRoom.cpp`: one list declaration before one scroll declaration, one friend declaration, one target body, one callback body, and zero UID000053/UID000054 Empty Emitter Markers.
- [x] Gate 2 retained every verified D1-D10 hash/formal/layout/order/body/validator/marker result but rejected the callback because four existing list-child formals still emitted undeclared historical member aliases.
- [x] Repaired `by-class/FittingRoomScrollPane.md`; current D3/command16730.
- [x] Repaired `by-class/FittingRoomListPane.md`; current D2/command16731.
- [x] Repaired `by-memory/0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar.md`; D11/command16732.
- [x] Repaired `by-memory/0x0041f100-0x0041f219.FittingRoomListPaneResetScrollPosition.md`; D12/command16733.
- [x] Repaired `by-memory/0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md`; D13/command16734.
- [x] Repaired `by-memory/0x00420840-0x00420949.FittingRoomListPaneOnScrollStep.md`; D14/command16735.
- [x] Repaired `by-file/FittingRoom.md`; current D9/command16736.
- [x] Repaired current target naming in `by-memory/0x0041e7f0-0x0041e8af.FittingRoomScrollPaneBeginPartPressRaw.md`; D15/command16737.
- [x] Repaired current target naming in `by-memory/0x0041e4f0-0x0041e777.FittingRoomScrollPaneGetPartRect.md`; D16/command16738.
- [x] Read-only verified historical B001 bounded-repair G2 command16738: no undeclared old member/accessor vocabulary, only the immutable historical target filename slug, accepted class/order/target/callback shape, and zero UID000053/UID000054 Empty Emitter Markers.
- [x] Read-only verified historical G3 command16762 preserves that semantic shape; unrelated Empty Emitter Markers are not target failures.
- [x] Recorded supervisor wait-generated G4 command16779 and read-only verified current G5 command16780 retains the G4 hash/metrics and accepted semantic counts.
- [x] Updated this same report with current hashes, claim states, validator commands, generated readback, and terminal evidence.
- [x] Every declared additional UID has target-specific evidence, recommendation, ledger rows, destination docs, and planned validation: not applicable; no additional UID declared.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger records actual callback and bounded repair states for C2D9-01..C2D9-59.
- [x] Applied target `92/94`, class/support scores, and positions exactly as recommended.
- [x] Resolved score-limiting arithmetic, argument, source-name, C++, callback, both class declarations, legal access, complete-type order, and ownership blockers.
- [x] Retained canonical owners and changed only UID000054 physical emitter to UID000053 for dependency-safe source order.
- [x] Renamed the source method only; no path/UID/range split or filesystem rename.
- [x] Applied source-placement/range/padding/reclassification decisions.
- [x] Applied all seven exact formal C++ blocks; no report-side/example C++ remains outside formal blocks.
- [x] Preserved all seven accepted report-managed formal blocks and normalized the four associated pre-existing list-child formals to the same compile-visible field vocabulary.
- [x] Confirmed UID000053 callback declaration is compile-visible to UID0002D9 and UID000054 is complete before all list child definitions.
- [x] Confirmed `friend class FittingRoomListPane` legally covers retained direct list-to-scroll private-state access without public fields or invented setters.
- [x] Third-party import directive: not applicable.
- [x] Incorporated target/support facts at report-level detail without summarizing away evidence.
- [x] Preserved historical/stale assumptions, rejected alternatives, and negative evidence.
- [x] Preserved the explicit Wave2/Wave3 rejection.
- [x] Open questions remain closed; no "future investigation" blocker remains.
- [x] Ran scoped serial validators for every changed ordinary by-* file.
- [x] Supervisor applied and validated the exact UID000053/UID000054 class, UID0000JE file, and memory manual rows under commands16777-command16779; B001 did not edit those reports; C2D9-35/36/37/47.
- [x] Supervisor replaced and validated UID0002DI in `by-memory/-coverage-report.md` with the exact `88%` / very-strong `ResetScrollPosition()` row and placement context above; C2D9-57/command16779.
- [x] Supervisor replaced and validated UID0002DN in `by-memory/-coverage-report.md` with the exact `88%` / very-strong `OnInputEvent()` row and placement context above; C2D9-58/command16779.
- [x] Supervisor replaced and validated UID0002DS in `by-memory/-coverage-report.md` with the exact `88%` / very-strong `OnScrollStep()` row and placement context above; C2D9-59/command16779.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All B001-owned accepted target/support details incorporated at report-level detail.
- [x] Primary UID0002D9 reread against ledger and D1.
- [x] C2D9-01..C2D9-59 states record actual verification/exclusion/blocker status.
- [x] Metadata/score/owner/emitter/position/C++ changes applied or explicitly excluded with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions remain resolved with no new technical blocker.
- [x] Scoped validators ran serially and complete provenance is recorded.
- [x] Generated FittingRoom.cpp historical G1/G2/G3, supervisor wait-generated G4, and current G5 readbacks recorded.
- [x] Supervisor-owned manual coverage application/validation is complete; every exact handoff row remains preserved and occurs once in the current roots.
- [x] Final lease readback reports zero active leases.
- [ ] Supervisor performs fresh exact-artifact Gate 1 on this reconciled report.
- [ ] Supervisor performs fresh independent claim-by-claim Gate 2 against D1-D16, current manual roots, and generated G5.
- [ ] Supervisor executes the report through the validator-owned lifecycle only after both fresh gates pass.

READY_FOR_SUPERVISOR_GATE1_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000016781","destination_path":"executed-b-agent-research/B001/0002D9-FittingRoomScrollPaneUpdateThumbDragScroll-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0002D9-FittingRoomScrollPaneUpdateThumbDragScroll-source-quality.md","timestamp":"2026-07-23T02:35:52-04:00","uid":"0002D9"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
