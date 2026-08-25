** TARGET-REPORT-UID:0003HU **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003HU ItemObjectPane RenderFrame Ownership / Source-Quality Research


## Finalized Report / Current Recommendation

- Implemented technical result: UID0003HU is the source-authored `void ItemObjectPane::RenderFrame(GrafPort *target, const RectBounds *bounds)` override, not a generic `ProcessItemAction` helper.
- Final disposition is applied: UID0003HU remains the same validator UID, owner/emitter UID00006V, `RECONSTRUCTABLE:TRUE`, blank emitter position, and `Nested:0`; its current path is `by-memory/0x00537c70-0x00537ca2.ItemObjectPaneRenderFrame.md`, score is `92/94`, and Destination 1 is installed exactly.
- The accepted implementation callback synchronized all authorized ItemObjectPane, FlyingObjectPane, vtable, aggregate, and ItemObjImageLib declaration routes at report-level detail. No B001 implementation item remains.
- Source/compiler boundary: the body is one ordinary virtual source method. The `int` shown by Hex-Rays is incidental preservation of `DrawItemImage`'s `EAX`; the established ObjectPane slot is `void`, all live MapPane virtual calls cast it as `void`, and the source ignores the draw status.
- FlyingObjectPane reuse: current RTTI proves `FlyingObjectPane` derives through `ItemObjectPane`; the flying primary vtable inherits the same `+0x5c` entry. Generated output contains exactly one `ItemObjectPane::RenderFrame` body and no FlyingObjectPane duplicate.
- Helper closure: `0x004dee50` is existing UID00041R `ItemObjImageLib::DrawItemImage`. Its first explicit argument receives the target `GrafPort *` as the render receiver, its bounds argument is read-only in the complete helper body, and its return is ignored by UID0003HU. The source-safe declaration now uses `const RectBounds *dstRect` for this one method.
- Recommendation confidence: very strong for range, bytes, ABI, vtable slot, method name, fields, helper/global route, direct inheritance, body, source file, and duplicate exclusion; strong for the inferred `const` spelling and exact original lexical identifiers.
- B001 callback-completion record: B001 completed the accepted technical callback, left all 52 claims and 48 checklist rows terminal, recorded the ordinary validator/generated assertions, released every lease, did not edit manual coverage, and ran no report lifecycle command. Gate 2, coverage application, execution/revalidation/invalidation, count, report path, move, and archive state are authoritative only in current validator-owned headers/footers, registry, audit, and files; this report neither asserts nor directs any such external state.

Callback-return marker retained as immutable B001 handoff evidence only; it is not current lifecycle authority:
READY_FOR_SUPERVISOR_GATE2_REVIEW

## Supporting Research

- Canonical assignment and workflow:
  - `tools/leaser/Agents/Agent-B001/goal.md`
  - project skill `ntk-b-agent-workflow`
  - `references/b-agent-research-and-implementation-workflow.md`
  - `references/b-agent-report-template.md`
  - `references/score-blocker-audit-standard.md`
  - current `by-structure.md` ownership/emitter/source-generated rules.
- Evidence-time target/support documents opened:
  - UID0003HU target;
  - UID00006V ItemObjectPane class;
  - UID0000KG ItemObjectPane file;
  - UID0001D7 Item/Flying split index;
  - UID0003HQ/HR/HS/HT and UID0003HV/HW sibling pages;
  - UID00034Y and UID00034Z vtable pages;
  - UID00009R ObjectPane and UID0002SK ObjectPane vtable support;
  - UID000057 FlyingObjectPane;
  - UID00041R DrawItemImage;
  - UID00006W/UID0000KH/UID0001UU/UID0000RA ItemObjImageLib class/file/layout/global;
  - then-current MapPane render source;
  - callback-time generated ItemObjectPane.cpp;
  - callback-time manual by-memory/by-class/by-file/by-struct coverage snapshots;
  - callback-time research tracker.
- Historical pre-callback concurrent-union rebase during report drafting:
  - Agent-B005's accepted UID0003TT callback advanced UID0003HS from blank `86/90` to source-ready `92/94`, synchronized UID0001D7, and refreshed ItemObjectPane.cpp.
  - B001 reread the durable UID0003HS page, UID0001D7 aggregate, ItemObjectPane class/file roots, and generated ItemObjectPane.cpp after that change. Those evidence-time artifacts, not B005's mutable active report hash, were the pre-callback authority.
  - UID0003HS evidence-time SHA256 was `7166198D63C8C7212B19EC9EF41056CFC31B99BDF674C09E32997BD69CB4882F`, `7,873` bytes / `82` lines.
  - UID0001D7 evidence-time SHA256 was `751FA2F965564A8BC2464F80297854EF740E21E925E8DCA09E1F450E1F9F622F`, `20,220` bytes / `138` lines.
  - UID00006V ItemObjectPane class evidence-time SHA256 was `16D9889298ECD983726F2EBB434A561BCD977A57B4A6AEC658ECC3DA3210CB5D`, `23,672` bytes / `181` lines.
  - UID0000KG ItemObjectPane file evidence-time SHA256 was `BCCD9E18A738B7CEA7F041BF4DA24B9C0DB1456DCEE59BFD3861E1575976EEC5`, `32,088` bytes / `203` lines.
  - This report preserves the complete new UID0003HS body/evidence and does not overwrite or compress B005's accepted union.
- Historical and coordination search roots checked explicitly:
  - active `tools/leaser/Agents/Agent-B001/research`;
  - active `tools/leaser/Agents/Agent-B002/research`;
  - active `tools/leaser/Agents/Agent-B003/research`;
  - active `tools/leaser/Agents/Agent-B004/research`;
  - active `tools/leaser/Agents/Agent-B005/research`;
  - central `executed-b-agent-research/**`;
  - `tools/leaser/Agents/Older-Research/**`;
  - `tools/leaser/Agents/SpecialReports/**`.
- Exact historical search terms:
  - `UID0003HU`;
  - `0x00537c70`;
  - `ItemObjectPaneProcessItemAction`;
  - `ItemObjectPane::RenderFrame`;
  - `ProcessItemAction`;
  - `sub_537C70`;
  - `ItemObjImageLib::DrawItemImage`;
  - `g_pItemObjImageLib`;
  - `ItemObjectPane`;
  - `FlyingObjectPane`.
- Active B001-B005 research roots returned no dedicated target match.
- Older-Research and SpecialReports returned no relevant target match.
- Relevant executed reports opened and classified:
  - `executed-b-agent-research/B002/0003TX-MapPaneHandleObjectInfoPacket-source-quality.md`: direct class/declaration and virtual-name support. It established `RenderFrame` as the inherited slot name and completed ItemObjectPane's declaration, but it did not reconstruct UID0003HU's body.
  - `executed-b-agent-research/B001/0003HR-ItemObjectPaneNonDeletingDestructor-source-quality.md`: direct current ItemObjectPane class/file/aggregate/generated baseline and adjacent source-order support; UID0003HU was verify-only.
  - `executed-b-agent-research/B013/00034Y-ItemObjectPaneVtableData-empty-emitter-source-quality.md`: direct ItemObjectPane primary-slot and vtable ownership support.
  - `executed-b-agent-research/B006/00034Z-FlyingObjectPaneVtableData-source-quality.md`: direct flying vtable reuse support; it did not decode the full current RTTI base array or provide the target body.
  - `executed-b-agent-research/B003/00041R-ItemObjImageLibDrawItemImage-by-memory-source-quality.md`: direct helper owner/name/ABI/behavior and no-code support.
  - `executed-b-agent-research/B007/0000KH-ItemObjImageLib-empty-emitter-family-source-quality.md`: ItemObjImageLib file/layout/global route support.
  - `executed-b-agent-research/B008/00006W-ItemObjImageLib-class-source-quality.md`: ItemObjImageLib class/layout support.
  - `executed-b-agent-research/B002/0001DJ-SoundObjectPaneCore-empty-emitter-source-quality.md`: direct ObjectPane `RenderFrame` slot/default support.
  - `executed-b-agent-research/B005/00037V-MapPaneRenderViewCore-source-quality.md`: direct virtual caller support; all render return values are ignored.
  - `executed-b-agent-research/B004/0002WS-ItemObjectPanePoolStaticStorage-source-quality.md`: incidental source-module and allocation support only.
- Explicit no-direct-report conclusion: none of the searched active, executed, archived, Older-Research, or SpecialReports artifacts is a dedicated complete current UID0003HU body/source-quality report. The listed reports are evidence leads and support, not substitutes for this report.
- Wave2/Wave3 material appeared in stale `by-memory/-report.old.md` and old report prose. It was used only as a search lead and was not accepted as authority. Every current conclusion below was independently checked against current docs and live IDA MCP.

## Target

- Target UID: `0003HU`.
- Technical target path established by the callback: `by-memory/0x00537c70-0x00537ca2.ItemObjectPaneRenderFrame.md`.
- Historical pre-callback path: `by-memory/0x00537c70-0x00537ca2.ItemObjectPaneProcessItemAction.md`.
- B001 callback-return artifact path: `tools/leaser/Agents/Agent-B001/research/0003HU-ItemObjectPaneRenderFrame-source-quality.md`; any later validator-owned move/archive path is external lifecycle state.
- Historical queue basis: pre-callback `auto-generated/-ag-research-tracker.md`, by-memory Not-Covered Files - Reconstructable, target `85/90`, reconstructable true, zero registered dedicated reports, owner/emitter UID00006V, blank formal C++.
- Current source root: UID0000KG `NexusTK/map/ItemObjectPane.cpp`.
- Current direct class owner/emitter: UID00006V ItemObjectPane.
- Current target metadata:
  - `COMPLETION:92`
  - `CONFIDENCE:94`
  - `CANONICAL_OWNER:00006V`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:00006V`
  - blank `EMITTER_POSITION_OPTIONAL`
  - exact Destination 1 formal C++
  - `Nested:0`.

## Current Target State

- Technical applied state recorded at B001 callback completion:
  - exact half-open range `[0x00537c70,0x00537ca2)`;
  - exact class owner/emitter UID00006V;
  - exact `RenderFrame(GrafPort *, const RectBounds *)` declaration in the complete ItemObjectPane class;
  - exact Destination 1 body and Item Summary;
  - exact direct call to UID00041R `DrawItemImage`;
  - exact item/palette fields at `+0x128/+0x12a`;
  - exact primary/flying vtable refs at `0x0062044c` and `0x006204f8`;
  - source root UID0000KG;
  - direct eight-entry Flying RTTI inheritance proof;
  - const-correct UID00041R declaration route;
  - target score `92/94`.
- Historical pre-callback contradictions are closed:
  - old physical path/title and current-facing `ProcessItemAction` alias;
  - blank body/summary and helper-name-pending wording;
  - missing source-void/EAX, exact-argument, direct-inheritance, and const-integration evidence;
  - stale aggregate/vtable/class/file support prose.
- Generated evidence-time baseline observed during B001 callback reconciliation:
  - `auto-generated/NexusTK/map/ItemObjectPane.cpp`
  - later external validator header command observed at evidence time `000000013768`
  - refreshed `2026-07-16T10:13:39-04:00`
  - refresh source `foreground-generated-refresh`
  - SHA256 `1C0029CBEF84F63BEBA6012B86DF39651AE9D093C94E4AFBF61C869727E5488B`
  - `3,935` bytes / `93` lines
  - B001's final waited callback command was `000000013759` at `2026-07-16T10:03:01-04:00`; the later command `000000013768` was not run by B001 and changed only the generated command/timestamp header, proven by substituting the earlier two header values and reproducing the exact prior SHA256 `02636B43DD18B364B41D006E0C71BFADCC71D436656B5E766E5594CA07C7D97A`;
  - one UID0003HU marker and one `ItemObjectPane::RenderFrame` definition;
  - zero UID0003HU Empty Emitter Markers;
  - zero old `ProcessItemAction` generated tokens;
  - one complete ItemObjectPane declaration;
  - one exact UID0003HS `UpdateItemStatus` definition and zero UID0003HS Empty Emitter Markers;
  - one source destructor definition plus one compiler-coverage destructor reference;
  - zero `FlyingObjectPane::RenderFrame` definitions;
  - the existing UID000057 FlyingObjectPane Empty Emitter Marker remains.
- B001 callback state: B001 performed the accepted ordinary edits, short leases, scoped validators, and final waited generated refresh enumerated later, then released every lease. B001 did not edit manual coverage/generated output directly, mutate IDA, run execute_report, or run any report lifecycle/probe/count/move/archive command. Any later review, coverage, execution, revalidation, invalidation, path, move, archive, or count state is external validator/supervisor authority and is not asserted here.

## Executive Recommendation

- Applied result: UID0003HU was validator-aware renamed in place to `ItemObjectPaneRenderFrame`.
- Applied target score is `92/94`.
- Owner/emitter UID00006V, reconstructable true, blank emitter position, and `Nested:0` are retained.
- The exact formal method is populated:
  - `void ItemObjectPane::RenderFrame(GrafPort *target, const RectBounds *bounds)`;
  - call `g_pItemObjImageLib->DrawItemImage`;
  - pass `target`, `bounds`, `m_itemId`, `m_paletteFlags`, `0`, and `0.0f`;
  - ignore the helper return;
  - add no guard, cast, local rectangle, overlay object, or duplicate flying definition.
- ItemObjectPane's existing complete declaration is preserved; its return type remains void.
- The one source-facing general `ItemObjImageLib::DrawItemImage` declaration now uses `const RectBounds *dstRect`, with matching signature prose and no `const_cast`.
- FlyingObjectPane's RTTI-proven direct ItemObjectPane base relationship and inherited `RenderFrame` slot are synchronized without a FlyingObjectPane override.
- All ABI data, vtables, RTTI, adjusted views, pools, startup/cleanup wrappers, and scalar deleting wrappers remain existing compiler/generated support.
- No split, new child, new owner, new source file, new global, IDA mutation, or padding change is required.

## Supervisor Active Recheck

- The supervisor passed exact report SHA `B6C149D0C5AE282AE49D668DC523161FFE85B07455B6440F8554368203693E35` through Gate 1 and authorized the bounded callback.
- The target does not require a split before a master report. IDA models exactly one 50-byte function and current adjacent spans are already registered as ignored padding.
- Every source-bearing page required for a compilable first draft now has its accepted disposition:
  - UID0003HU contains the exact body;
  - UID00006V preserves the exact ItemObjectPane declaration;
  - UID0001UU contains the bounded const-correct DrawItemImage declaration;
  - UID0000RA already supplies the singleton definition;
  - UID00041R remains body-blank for its independent kind-3 options-record no-code proof.
- Every shared/generated artifact has a precise exclusion:
  - UID00034Y/UID00034Z remain compiler vtable markers;
  - UID0001D7 remains a non-emitting index;
  - FlyingObjectPane gets no duplicate body;
  - ObjectPane and MapPane remain verify-only support.

## Inference Research Guidance Check

- Narrowest-owner rule: the target reads ItemObjectPane fields and occupies ItemObjectPane's primary virtual slot. UID00006V remains the direct owner; UID0000KG remains the source root.
- Owner versus emitter: UID00006V is both target owner and emitter route. ItemObjImageLib is a dependency, not target owner.
- Source versus compiler: the helper call is human source. Vtable slot addresses, Flying RTTI, inherited slot reuse, adjusted views, and incidental `EAX` are evidence for source shape, not source statements.
- Existing names were treated as hypotheses:
  - `ProcessItemAction` was rejected after base-slot comparison;
  - `RenderFrame` was independently revalidated;
  - `m_itemId` and `m_paletteFlags` were checked against constructor, status update, and helper consumption;
  - `DrawItemImage` was independently checked against current UID00041R and live IDA.
- Existing generated output was treated as state evidence, not source authority.
- Wave2/Wave3 artifacts were ignored as stale after providing search aliases.
- Inference grades used below:
  - direct IDA fact;
  - current documentation fact independently corroborated by IDA;
  - high-probability source inference;
  - rejected stale/invalid alternative.

## Heuristic / Inference Reanalysis And Validation

1. Function identity:
   - Direct IDA fact: `sub_537C70` is exactly `[0x00537c70,0x00537ca2)`, size `0x32`.
   - Direct vtable fact: ItemObjectPane primary `+0x5c` at `0x0062044c` and FlyingObjectPane primary `+0x5c` at `0x006204f8` both contain `0x00537c70`.
   - Current ObjectPane fact: primary `+0x5c` is the concrete two-argument `RenderFrame` default.
   - Decision: `ItemObjectPane::RenderFrame`, not `ProcessItemAction`.
2. Source return type:
   - Hex-Rays reports `int` because the function ends immediately after an `int` helper call and leaves `EAX` unchanged.
   - ObjectPane's base `+0x5c` target is `nullsub_18`, typed `void`, one instruction `retn 8`.
   - Live MapPane decompile contains sixteen `+92` virtual calls typed `void (__thiscall *)(receiver, target, bounds)` and ignores every return.
   - Decision: source return type is `void`; do not write `return g_pItemObjImageLib->DrawItemImage(...)`.
3. Explicit parameters:
   - `retn 8` proves two four-byte stack parameters.
   - Existing base declaration and callers prove `GrafPort *target` and `const RectBounds *bounds`.
   - The function forwards the exact two arguments unchanged to UID00041R.
4. Receiver fields:
   - `movzx eax, word ptr [ecx+128h]` proves a two-byte value.
   - Constructor and status-update pages store the accepted item appearance id there.
   - UID00041R consumes the low 16 bits as signed-source `short itemId`, then computes the item frame through unsigned 16-bit `itemId + 0x4000`.
   - Best name/type: `short m_itemId`.
   - `movzx eax, byte ptr [ecx+12Ah]` proves an unsigned byte.
   - UID00041R shifts it right by five for palette variant selection and uses nonzero values for options setup.
   - Best name/type: `unsigned char m_paletteFlags`.
5. Helper identity:
   - Direct IDA fact: sole callee `0x004dee50`.
   - Current exact page: UID00041R, `ItemObjImageLib::DrawItemImage`.
   - Current global: `dword_67A758` / source-facing `g_pItemObjImageLib`.
   - Decision: no raw `sub_4DEE50`, generic item-action helper, or pane-owned helper remains.
6. Exact call:
   - target's stack setup supplies float `0.0f`, null overlay, zero-extended palette byte, zero-extended item word, caller bounds, and caller GrafPort in right-to-left order.
   - helper receiver is loaded directly from `g_pItemObjImageLib`.
   - no singleton null check, item-id guard, bounds guard, return test, or overlay path exists in UID0003HU.
7. Helper bounds constness:
   - Complete UID00041R decompile never writes through `a3`.
   - It passes the rectangle to the accepted const Surface callback route and reads only `a3[1]`/`a3[3]` for the optional overlay path.
   - UID0003HU passes the established `const RectBounds *bounds`.
   - Best source declaration: change only `DrawItemImage` to `const RectBounds *dstRect`.
   - Rejected alternative: a target-local `const_cast<RectBounds *>(bounds)` is source-legal but decompiler-shaped and unnecessary.
8. Helper return behavior:
   - UID00041R returns the slot-2 blit status or overlay helper result depending on its path; with load-error guard it can return the overlay pointer value, which is zero for UID0003HU.
   - UID0003HU and its virtual callers ignore that status.
   - Decision: preserve helper `int` return but make UID0003HU `void`.
9. FlyingObjectPane inheritance:
   - Current Flying RTTI class hierarchy descriptor at `0x0064cff0` reports eight bases.
   - Base-class array at `0x0064d000` is:
     1. FlyingObjectPane;
     2. ItemObjectPane;
     3. ObjectPane;
     4. Pane;
     5. GrafPort;
     6. LObject;
     7. EventHandler;
     8. TimerHandler.
   - ItemObjectPane's corresponding hierarchy has seven bases.
   - Flying constructor initializes ItemObjectPane-compatible fields at `+0x128/+0x12a`.
   - Flying ordinary destructor restores all three ItemObjectPane vtable views before ObjectPane cleanup.
   - Decision: ordinary direct inheritance through ItemObjectPane, not sibling override folding or unrelated identical code.
10. Flying slot reuse:
    - Flying primary `+0x5c` directly points to UID0003HU.
    - No second function body, adjustor, thunk, or explicit Flying RenderFrame override exists.
    - Decision: inherited method; one emitted base body.
11. Source file:
    - target, class, vtables, item/flying pools, and companion methods all route to UID0000KG `NexusTK/map/ItemObjectPane.cpp`.
    - MapPane is the render caller and factory, not the target owner.
    - ItemObjImageLib owns the callee and singleton, not this wrapper.
12. Source order and emitter position:
    - address/logical order is UID0003HQ constructor, UID0003HR destructor, current source-ready UID0003HS status update, UID0003HT bounds override, UID0003HU render override, then FlyingObjectPane children.
    - Current generator groups still-empty markers separately; that diagnostic placement is not source-order evidence.
    - Retain blank target position. Address-sorted child expansion under UID00006V is the least artificial and preserves current ItemObjectPane class position `10`.
13. Range and padding:
    - pre-padding `[0x00537c65,0x00537c70)` is eleven `0xcc` bytes;
    - post-padding `[0x00537ca2,0x00537cb0)` is fourteen `0xcc` bytes;
    - both are already present in `by-memory/-ignored.md`;
    - no split or ignored edit is required.
14. Original lexical uncertainty:
    - no PDB proves exact parameter names, repeated `virtual`, exact header filename, or the original spelling of `g_pItemObjImageLib`.
    - Current project-wide names are coherent and behavior-safe.
    - This caps confidence below 95 but does not block body, metadata, owner, source placement, or C++.

Rejected alternatives:

- `ProcessItemAction`: rejected because the exact slot is ObjectPane `RenderFrame +0x5c`, all calls pass GrafPort/bounds, and the body only draws.
- `int ItemObjectPane::RenderFrame`: rejected because base slot and callers are void; helper `EAX` is incidental.
- `return DrawItemImage(...)`: rejected because it changes source signature and contradicts the established virtual contract.
- target-local `const_cast`: rejected because the helper rectangle is read-only and its declaration can be corrected.
- `Pane *target`: rejected as weaker than the established shared slot's `GrafPort *`.
- `RectBounds *bounds` on the target: rejected because the complete ObjectPane hierarchy already uses `const RectBounds *`.
- `unsigned short m_itemId`: retained as an ABI-compatible alternative only; current accepted constructor/helper declarations consistently use `short`.
- `m_variant`, `m_style`, or generic state byte: rejected as primary names because the helper directly consumes the byte as palette/tint option flags.
- MapPane ownership: rejected as caller-only.
- ItemObjImageLib ownership of UID0003HU: rejected as callee-only.
- FlyingObjectPane duplicate override: rejected by RTTI inheritance, one function address, and direct slot reuse.
- vtable/thunk body: rejected as compiler-generated ABI data.
- new source file: rejected because the current ItemObjectPane.cpp grouping is exact.

## Evidence Standards Used

- Highest-weight evidence:
  - live IDA MCP function lookup, decompile, disassembly, bytes, xrefs, integer reads, entity-name queries, caller decompile, and RTTI table reads;
  - exact class/vtable/source pages already accepted and independently consistent;
  - exact generated and manual state read at report time.
- Corroborating evidence:
  - constructor/status field producers;
  - helper body consumer semantics;
  - ObjectPane slot map;
  - Flying constructor/destructor/vtable behavior;
  - MapPane virtual caller behavior;
  - source-file grouping and current generated output.
- Negative evidence:
  - no direct code xref to UID0003HU, as expected for a vtable-only virtual;
  - no second Flying render body;
  - no branches or guards in target;
  - no target write through parameters;
  - no helper rectangle writes;
  - no target path in active B001-B005 reports;
  - no direct historical target report.
- Confidence limitation:
  - binary and project context prove behavior/source shape, but no original symbol/header source proves every lexical identifier or `const` token.

## Evidence Checked

- Live MCP discovery/health:
  - initial successful transport session `cadd2744-cdfe-42ed-b79c-b819679254ec`;
  - `idb_list` returned one active database `64c11373`, worker PID `21508`, not analyzing;
  - evidence transports included `4af44cfc-56b5-4af0-90dc-453fd9aa0114` and `2e69c27c-6912-4d6c-912c-0479f7981aec`;
  - `server_health` at evidence time returned `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, cache size `2067`.
  - final freshness transport `8dc1739a-7ddc-440f-b74c-3a47b9c6e0b3` rediscovered the same sole active database `64c11373` and worker PID `21508`; at `2026-07-16T09:45:31-04:00`, `server_health` again returned `status:ok` with analysis, Hex-Rays, and strings ready, and a schema-current bounded `get_bytes` read returned the accepted first 16 target bytes `55 8b ec 0f b6 81 2a 01 00 00 51 c7 04 24 00 00`.
- Target MCP checks:
  - `lookup_funcs 0x00537c70`: `sub_537C70`, size `0x32`;
  - `get_bytes 0x00537c70 size 50`;
  - `decompile 0x00537c70`;
  - `disasm 0x00537c70`, 15 instructions;
  - `analyze_function 0x00537c70`;
  - `xrefs_to 0x00537c70`: exactly two data refs;
  - `callees 0x00537c70`: exactly UID00041R.
- Vtable/caller checks:
  - `get_int` at ObjectPane primary `+0x5c/+0x64`;
  - `get_int` at Item/Flying primary `+0x5c`;
  - `disasm nullsub_18` at `0x0041b6c0`;
  - live MapPane render decompile at `0x005094b0`, with sixteen `+92` virtual calls typed void.
- Helper checks:
  - `lookup_funcs 0x004dee50`: size `0x16a`;
  - complete helper decompile;
  - function profile with 12 recognized caller functions / 29 direct code xrefs;
  - helper argument use, return paths, resource/palette/callback/overlay calls.
- Flying inheritance checks:
  - Flying constructor decompile/disassembly;
  - Flying ordinary destructor decompile;
  - RTTI entity names around `0x0064cf00-0x0064d100`;
  - Flying complete object locator and class hierarchy bytes;
  - eight base-array pointer reads and exact decorated names.
- Byte hashes:
  - target `[0x00537c70,0x00537ca2)`: SHA256 `A1A0DFB737AB5432DFA986E7966BC214B96AA3024F963DDEC83E7B6A711AB58E`;
  - pre-padding `[0x00537c65,0x00537c70)`: SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`;
  - post-padding `[0x00537ca2,0x00537cb0)`: SHA256 `1E875C76536C8496BED8C8760B539327F24ACFFBCF0A4B941877B4BFB4C44356`.
- Documentation/generated/manual checks:
  - all accepted ordinary destinations and verify-only support listed in this report;
  - callback-time generated ItemObjectPane.cpp snapshot;
  - callback-time manual by-memory/by-class/by-file/by-struct coverage snapshots;
  - callback-time tracker snapshot;
  - active/executed/Older-Research/SpecialReports search roots.
- Tool-call limitations recorded honestly:
  - the first local `Invoke-WebRequest` attempt failed before MCP initialization because Windows PowerShell required `-UseBasicParsing`; retry succeeded immediately.
  - one `search_text` call used the wrong request shape and returned missing `pattern`; the same bounded RTTI evidence was then obtained through valid `entity_query`, `get_bytes`, and `get_int` calls.
  - the first final-checkpoint `get_bytes` request used the obsolete `address`/`size` shape and returned missing `regions`; B001 read the live `tools/list` schema and immediately repeated the bounded read with `regions:{addr,size}`, which succeeded against database `64c11373`.
  - no valid bounded IDB-backed call failed, timed out, or reported a missing worker.
- During the historical initial report-only evidence pass, the following were intentionally not performed:
  - ordinary edits;
  - leases;
  - validators;
  - generated/manual coverage edits;
  - IDA mutation;
  - execute_report or report lifecycle/probe/count/move/archive commands.
- During the accepted implementation callback, the ordinary edits, short leases, scoped validators, and final waited generated refresh were performed as enumerated later. Manual coverage/generated-file direct edits, IDA mutation, execute_report, and report lifecycle/probe/count/move/archive commands remained unperformed by B001.

## Claim And Incorporation Ledger

The 52 rows preserve the accepted callback claims and terminal dispositions. References to "current" in evidence or claim C3HU-051 are explicitly scoped to B001's callback-time read-only snapshot and do not assert later manual-coverage or lifecycle state.

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C3HU-001 | UID0003HU is exactly `[0x00537c70,0x00537ca2)`, size `0x32`. | Very strong | lookup, bytes, disasm | D1 target Range/Evidence | incorporate | applied |
| C3HU-002 | Target byte SHA256 is `A1A0...B58E`. | Very strong | bounded bytes/hash | D1 target Evidence | incorporate | applied |
| C3HU-003 | The source method name is `ItemObjectPane::RenderFrame`, not `ProcessItemAction`. | Very strong | ObjectPane +0x5c slot and callers | D1-D5 | incorporate | applied |
| C3HU-004 | Preserve `ProcessItemAction` only as a rejected historical alias. | Strong | stale title versus slot contract | D1-D4 history | historicalize | applied |
| C3HU-005 | UID0003HU must be validator-aware renamed in place to ItemObjectPaneRenderFrame. | Very strong | source-facing identity/path search | D1 plus link destinations | incorporate | applied |
| C3HU-006 | Machine ABI is MSVC `__thiscall` with two explicit four-byte arguments and `retn 8`. | Very strong | 15-instruction disassembly | D1 ABI | incorporate | applied |
| C3HU-007 | Source return type is `void`. | Very strong | base nullsub, MapPane callers | D1/D2 | incorporate | applied |
| C3HU-008 | Hex-Rays `int` is incidental helper EAX propagation, not the virtual source contract. | Very strong | final call plus void slot/callers | D1 history/negative | incorporate | applied |
| C3HU-009 | First explicit parameter is `GrafPort *target`. | Very strong | base declaration/callers/forwarding | D1/D2 | already-present | already-present |
| C3HU-010 | Second explicit parameter is `const RectBounds *bounds`. | Strong | base declaration/callers/no writes | D1/D2 | already-present | already-present |
| C3HU-011 | Receiver `+0x128` is `short m_itemId`. | Very strong | constructor/status/helper consumer | D1-D4 | already-present | already-present |
| C3HU-012 | Receiver `+0x12a` is `unsigned char m_paletteFlags`. | Very strong | constructor/status/helper shifts/options | D1-D4 | already-present | already-present |
| C3HU-013 | Sole callee is UID00041R `ItemObjImageLib::DrawItemImage`. | Very strong | callees/current exact page | D1/D8-D12 | incorporate | applied |
| C3HU-014 | Helper receiver is source-facing `g_pItemObjImageLib`. | Very strong | global operand/current global page | D1 | already-present | already-present |
| C3HU-015 | Target passes `target` as DrawItemImage's render receiver. | Very strong | exact push order | D1 | incorporate | applied |
| C3HU-016 | Target passes `bounds` unchanged as the destination rectangle. | Very strong | exact push order | D1 | incorporate | applied |
| C3HU-017 | Target passes `m_itemId` zero-extended from the stored word. | Very strong | exact instruction | D1 | incorporate | applied |
| C3HU-018 | Target passes `m_paletteFlags` zero-extended from the stored byte. | Very strong | exact instruction | D1 | incorporate | applied |
| C3HU-019 | Target passes null overlay and `0.0f` overlay strength. | Very strong | exact stack setup | D1 | incorporate | applied |
| C3HU-020 | Target does not inspect DrawItemImage's `int` return. | Very strong | call/epilogue and callers | D1 | incorporate | applied |
| C3HU-021 | Target has no singleton null guard. | Very strong | complete disassembly | D1 negative evidence | incorporate | applied |
| C3HU-022 | Target has no item, bounds, overlay, or return-status branch. | Very strong | one basic block/15 instructions | D1 negative evidence | incorporate | applied |
| C3HU-023 | DrawItemImage's rectangle parameter is read-only in the complete helper body. | Strong | helper decompile/callback route | D8-D12 | incorporate | applied |
| C3HU-024 | DrawItemImage's declaration should use `const RectBounds *dstRect`. | Strong | read-only body plus target const input | D8-D12 and D3 formal | incorporate | applied |
| C3HU-025 | A target-local `const_cast` is rejected. | Strong | bounded const correction is cleaner/exact | D1 negative/history | reject-invalid | excluded-with-reason |
| C3HU-026 | DrawItemImage remains `int`; only UID0003HU ignores its result. | Very strong | helper control flow and shared callers | D8-D12 | incorporate | applied |
| C3HU-027 | UID00041R's independent kind-3 options-record no-code proof remains unchanged. | Very strong | current helper page/body | D8/D10-D12 | already-present | already-present |
| C3HU-028 | FlyingObjectPane RTTI has eight bases and directly includes ItemObjectPane before ObjectPane. | Very strong | CHD/base array | D6/D7 | incorporate | applied |
| C3HU-029 | Flying constructor initializes inherited item/palette fields. | Very strong | constructor decompile | D7 | incorporate | applied |
| C3HU-030 | Flying ordinary destructor restores ItemObjectPane vtables before ObjectPane cleanup. | Very strong | destructor decompile | D6/D7 | incorporate | applied |
| C3HU-031 | Flying primary `+0x5c` directly reuses UID0003HU. | Very strong | vtable integer/xref | D6/D7 | incorporate | applied |
| C3HU-032 | Flying reuse is ordinary inherited behavior, not an explicit duplicate override. | Very strong | RTTI plus one function address | D6/D7 | incorporate | applied |
| C3HU-033 | Emit exactly one ItemObjectPane RenderFrame definition and no Flying definition. | Very strong | inheritance/source model | D1-D7 | incorporate | applied |
| C3HU-034 | UID00006V remains the narrow target owner/emitter. | Very strong | fields/vtable/source route | D1/D2 | already-present | already-present |
| C3HU-035 | UID0000KG remains the exact source root. | Very strong | class/file/generated grouping | D3 | already-present | already-present |
| C3HU-036 | MapPane remains caller only. | Very strong | virtual render loop | D1/D3 | reject-stale | excluded-with-reason |
| C3HU-037 | ItemObjImageLib remains callee owner only. | Very strong | helper class/global | D1/D8-D12 | reject-stale | excluded-with-reason |
| C3HU-038 | Target keeps blank emitter position. | Strong | address-sorted child route/marker grouping | D1 | incorporate | applied |
| C3HU-039 | Logical source order is HQ, HR, current source-ready HS, HT, HU, then Flying children. | Very strong | exact address/source inventory/current B005 union | D1-D4 | incorporate | applied |
| C3HU-040 | Target keeps `Nested:0`. | Very strong | current balanced hierarchy | D1 | already-present | already-present |
| C3HU-041 | Pre-padding is eleven `0xcc` bytes and already ignored. | Very strong | bytes/current ignored ledger | D1 verify-only ignored | already-present | already-present |
| C3HU-042 | Post-padding is fourteen `0xcc` bytes and already ignored. | Very strong | bytes/current ignored ledger | D1 verify-only ignored | already-present | already-present |
| C3HU-043 | No split/new child/new file is required. | Very strong | exact single function/range | D1-D4 | not-applicable | excluded-with-reason |
| C3HU-044 | Target score should become `92/94`. | Strong | all body/source blockers closed | D1 | incorporate | applied |
| C3HU-045 | ItemObjectPane class remains `92/94`; preserve the complete declaration and current UID0003HS source-ready union while synchronizing target prose/links. | Strong | complete current declaration/B005 union | D2 | already-present | already-present |
| C3HU-046 | ItemObjectPane file remains `91/93`; preserve current UID0003HS source and all unrelated Flying/empty-child limits. | Strong | current file/generated state | D3 | already-present | already-present |
| C3HU-047 | UID0001D7 remains `90/93`, false/non-emitting, preserving current UID0003HS synchronization while updating the target row/path. | Strong | exact split index role/current aggregate | D4 | incorporate | applied |
| C3HU-048 | UID00034Y keeps `90/94` marker state while naming primary `+0x5c` RenderFrame. | Strong | current vtable marker | D5 | incorporate | applied |
| C3HU-049 | UID00034Z keeps `88/92` marker state while adding direct-inheritance/RenderFrame reuse proof. | Strong | current vtable plus RTTI | D6 | incorporate | applied |
| C3HU-050 | Historical helper-pending/blank-body/action-name wording must be explicitly superseded. | Strong | current contradictions | D1-D12 | historicalize | applied |
| C3HU-051 | At B001 callback-time readback, manual coverage needed the exact target addition and bounded stale support-row replacements supplied below. | Very strong | read-only manual comparison | supervisor coverage handoff | incorporate | applied |
| C3HU-052 | The accepted callback required scoped validation of each changed ordinary page and a final waited refresh of the renamed target, followed by one-body/no-duplicate/no-marker verification. | Very strong | workflow/generated baseline | checklist/validator plan | incorporate | applied |

## Callback Claim Verification Notes

Proof keys `001` through `052` map one-to-one to ledger claims `C3HU-001` through `C3HU-052`.

| Proof key | Terminal proof |
| --- | --- |
| 001 | Renamed target Range/source-ready section records exact `[0x00537c70,0x00537ca2)` / `0x32`; validator `000000013730` returned exit `0`, `ok:1`. |
| 002 | Target records full bytes and SHA256 `A1A0DFB737AB5432DFA986E7966BC214B96AA3024F963DDEC83E7B6A711AB58E`. |
| 003 | Target title/body, ItemObjectPane class/file, aggregate, both vtables, and generated source now use `ItemObjectPane::RenderFrame`. |
| 004 | Target and support history retain `ProcessItemAction` only as a superseded split-era alias; no current link/marker uses it. |
| 005 | Validator `000000013730` reported `path_update 0003HU` from the old path to `ItemObjectPaneRenderFrame.md`; old file is absent and UID is unchanged. |
| 006 | Target source-ready section records 15 instructions, `this` in `ECX`, two stack parameters, and `retn 8`. |
| 007 | Target, class/file, UID00034Y, and generated definition all use source return `void`. |
| 008 | Target documents incidental helper `EAX`; generated body contains no return statement or result variable. |
| 009 | Destination 2 already declared `GrafPort *target` and was preserved byte-for-byte. |
| 010 | Destination 2 already declared `const RectBounds *bounds` and was preserved byte-for-byte. |
| 011 | Target/class/file preserve `short m_itemId` at `+0x128`; generated class remains exact. |
| 012 | Target/class/file preserve `unsigned char m_paletteFlags` at `+0x12a`; generated class remains exact. |
| 013 | Target and UID00041R support identify the sole call to `ItemObjImageLib::DrawItemImage`. |
| 014 | Target body uses existing `g_pItemObjImageLib`; UID0000RA remained verify-only. |
| 015 | Target managed body and generated readback pass `target` first. |
| 016 | Target managed body and generated readback pass `bounds` second without a cast or mutation. |
| 017 | Target evidence records the word load/zero extension and passes `m_itemId`. |
| 018 | Target evidence records the byte load/zero extension and passes `m_paletteFlags`. |
| 019 | Target managed body and generated readback pass `0` and `0.0f`. |
| 020 | Target/generator contain a bare helper call; UID00041R remains `int` and no status is inspected. |
| 021 | Target negative evidence and generated body contain no singleton null guard. |
| 022 | Target negative evidence and generated body contain no item/bounds/overlay/status branch. |
| 023 | UID00041R now records complete read-only rectangle use; validator `000000013741` returned exit `0`, `ok:1`. |
| 024 | UID00041R, UID00017N, UID0001UU, UID00006W, and UID0000KH now use the bounded const general signature; their scoped validators passed. |
| 025 | No `const_cast` was inserted in any destination or generated source; rejected as behavior-neutral but decompiler-shaped. |
| 026 | UID00041R remains `int`; target/class/file support and generated body record that only UID0003HU ignores it. |
| 027 | UID00041R formal body remains blank with the full kind-3 `+0x1c` no-code proof preserved. |
| 028 | UID00034Z/Flying class record the complete eight-entry RTTI base array; validators `000000013737` and `000000013739` passed. |
| 029 | Flying class/vtable support records inherited item/palette initialization without changing constructor content. |
| 030 | UID00034Z/Flying class record ItemObjectPane vtable restoration before ObjectPane cleanup. |
| 031 | UID00034Z identifies primary `0x006204f8 -> 0x00537c70`; UID00034Y identifies Item slot `0x0062044c`. |
| 032 | Flying support explicitly classifies reuse as ordinary inheritance and rejects an explicit duplicate override. |
| 033 | Generated ItemObjectPane.cpp has one ItemObjectPane definition and zero FlyingObjectPane definitions. |
| 034 | Target retains owner/emitter UID00006V; ItemObjectPane class remains the narrow owner. |
| 035 | ItemObjectPane file remains UID0000KG at `91/93` and is the generated source root. |
| 036 | Target/file support retains MapPane as caller only; no MapPane-owned implementation was added. |
| 037 | ItemObjImageLib support retains callee ownership only; no target migration into ItemObjImageLib.cpp occurred. |
| 038 | Target header keeps blank `EMITTER_POSITION_OPTIONAL`. |
| 039 | Target/class/file/aggregate record logical HQ/HR/HS/HT/HU/Flying order; generated filled children preserve the current union. |
| 040 | Target header keeps `Nested:0`. |
| 041 | Read-only `by-memory/-ignored.md` still contains `[0x00537c65,0x00537c70)`; no edit was made. |
| 042 | Read-only `by-memory/-ignored.md` still contains `[0x00537ca2,0x00537cb0)`; no edit was made. |
| 043 | UID0003HU was renamed in place; no split, new UID, child, file root, global, or source module was created. |
| 044 | Target header is `92/94`; validator `000000013730` recorded both score updates. |
| 045 | ItemObjectPane class remains `92/94`; Destination 2 and UID0003HS content were preserved, validator `000000013731` passed. |
| 046 | ItemObjectPane file remains `91/93`; UID0003HS/Flying/destructor/pool union was preserved, validator `000000013733` passed. |
| 047 | UID0001D7 remains `90/93`, false/non-emitting/no-owner/no-emitter/blank formal; validator `000000013735` passed. |
| 048 | UID00034Y remains `90/94` marker-only and now names the primary RenderFrame slot; validator `000000013736` passed. |
| 049 | UID00034Z remains `88/92` marker-only and now records direct inheritance/reuse; validator `000000013737` passed. |
| 050 | Target and all support pages explicitly supersede helper-pending, blank-body, action-name, and generic inheritance wording without deleting historical provenance. |
| 051 | B001's callback-time readback found the row differences documented below and retained exact supervisor-owned handoff text with evidence-time hashes. B001 did not edit coverage, and this proof does not assert whether later supervisor coverage application occurred. |
| 052 | Twelve ordinary destinations validated and B001 final waited command `000000013759` completed; later external command `000000013768`, as observed during evidence-time reconciliation, was proven metadata-only with unchanged generated hash/count/body assertions, and no B001 lease remained. |

## Positive Evidence Summary

- Exact target bytes implement one direct singleton call with six explicit arguments and no branch.
- Exact primary slot mapping:
  - ObjectPane `0x006202f4` / `+0x5c` -> `0x0041b6c0` `nullsub_18`, `void`, `retn 8`;
  - ItemObjectPane `0x0062044c` / `+0x5c` -> `0x00537c70`;
  - FlyingObjectPane `0x006204f8` / `+0x5c` -> `0x00537c70`.
- Exact target xrefs are the two Item/Flying data cells and no direct code refs.
- MapPane's current render body invokes the slot as void at sixteen sites and ignores return state.
- Constructor and status-update siblings independently establish `m_itemId` and `m_paletteFlags`.
- UID00041R independently establishes helper owner, name, global, argument family, and `int` return.
- Flying RTTI and destructor establish direct ItemObjectPane inheritance and one inherited implementation.
- Existing source root, class declaration, singleton definition, and helper declaration route make the target body implementation-ready after one bounded const correction.

## IDA MCP Facts

- Evidence-time database: `64c11373`.
- Evidence-time worker PID: `21508`.
- Health: `ok`; auto-analysis, Hex-Rays, and strings ready.
- Target:
  - start `0x00537c70`;
  - size `0x32`;
  - 15 instructions;
  - `retn 8`;
  - one internal callee;
  - two data xrefs;
  - no branch.
- Exact instruction flow:

| Address | Instruction | Source meaning |
| --- | --- | --- |
| `0x00537c70` | `push ebp` | frame prologue |
| `0x00537c71` | `mov ebp, esp` | frame prologue |
| `0x00537c73` | `movzx eax, byte ptr [ecx+12Ah]` | load `m_paletteFlags` |
| `0x00537c7a` | `push ecx` | allocate final float argument |
| `0x00537c7b` | `mov dword ptr [esp], 0` | `0.0f` |
| `0x00537c82` | `push 0` | null overlay |
| `0x00537c84` | `push eax` | palette flags |
| `0x00537c85` | `movzx eax, word ptr [ecx+128h]` | load `m_itemId` |
| `0x00537c8c` | `mov ecx, dword_67A758` | helper receiver `g_pItemObjImageLib` |
| `0x00537c92` | `push eax` | item id |
| `0x00537c93` | `push [ebp+arg_4]` | bounds |
| `0x00537c96` | `push [ebp+arg_0]` | GrafPort target |
| `0x00537c99` | `call sub_4DEE50` | `DrawItemImage` |
| `0x00537c9e` | `pop ebp` | epilogue |
| `0x00537c9f` | `retn 8` | two explicit arguments |

- Target bytes:
  - `55 8b ec 0f b6 81 2a 01 00 00 51 c7 04 24 00 00 00 00 6a 00 50 0f b7 81 28 01 00 00 8b 0d 58 a7 67 00 50 ff 75 0c ff 75 08 e8 b2 71 fa ff 5d c2 08 00`
- Helper:
  - `sub_4DEE50`;
  - size `0x16a`;
  - `ret 0x18`;
  - 12 recognized caller functions / 29 direct call xrefs;
  - six explicit arguments after `this`;
  - complete body reads but does not write the destination rectangle.
- Flying RTTI:
  - complete-object locator `0x0064cfdc`;
  - class hierarchy descriptor `0x0064cff0`;
  - base count `8`;
  - base-class array `0x0064d000`;
  - ordered entries `FlyingObjectPane`, `ItemObjectPane`, `ObjectPane`, `Pane`, `GrafPort`, `LObject`, `EventHandler`, `TimerHandler`.
- Negative IDA facts:
  - no target direct caller;
  - no second Flying RenderFrame body;
  - no target branch;
  - no target parameter mutation;
  - no helper destination-rectangle write;
  - no target-local vtable/thunk/compiler wrapper.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00537b40-0x00537b91` | UID0003HQ constructor | source constructor | true | UID00006V | `86/90` | verify-only sibling |
| `0x00537ba0-0x00537bbf` | UID0003HR destructor | source empty ordinary destructor | true | UID00006V | `92/94` | already emitted |
| `0x00537bc0-0x00537be9` | UID0003HS update | source-ready UpdateItemStatus | true | UID00006V | current `92/94` | emitted current sibling; preserve exactly |
| `0x00537bf0-0x00537c65` | UID0003HT bounds | source ClearOutputRects override | true | UID00006V | `86/90` | verify-only sibling |
| `0x00537c70-0x00537ca2` | UID0003HU target | source RenderFrame override | true | UID00006V | current `92/94` | validator-renamed, implemented, validated, and generated once |
| `0x00537cb0-0x00537d60` | UID0003HV | Flying constructor | true | UID000057 | `86/90` | inheritance support |
| `0x00537d60-0x00537d7f` | UID0003HW | Flying ordinary destructor | true | UID000057 | `85/90` | inheritance support |
| `0x004dee50-0x004defba` | UID00041R | ItemObjImageLib::DrawItemImage | true | UID00006W | `88/91` | body blank for independent no-code proof; declaration const sync |
| `0x006203ec-0x00620498` | UID00034Y | ItemObjectPane RTTI/vtables | generated-binary | UID00006V | `90/94` | marker retained |
| `0x00620498-0x00620544` | UID00034Z | FlyingObjectPane RTTI/vtables | generated-binary | UID000057 | `88/92` | marker retained; inheritance proof added |
| `0x00537b40-0x005380af` | UID0001D7 | non-emitting split index | false | none | `90/93` | path/row synchronization only |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0062044c` | data -> `0x00537c70` | ItemObjectPane primary `RenderFrame` slot at `+0x5c` |
| `0x006204f8` | data -> `0x00537c70` | FlyingObjectPane inherited ItemObjectPane `RenderFrame` slot |
| `0x006202f4` | data -> `0x0041b6c0` | ObjectPane concrete empty `RenderFrame` default |
| `0x00537c99` | call -> `0x004dee50` | sole target callee, DrawItemImage |
| `0x005094b0-0x0050a4fd` | sixteen indirect calls through `vtable+92` | MapPane render passes call the void RenderFrame slot and ignore return |
| `0x00537cb0` | constructor writes fields and Flying vtables | inherited ItemObjectPane layout support |
| `0x00537d60` | restores ItemObjectPane vtables | direct base destruction support |
| `0x0064d000` | RTTI base-class array | direct inheritance chain |

## Documentation Evidence And IDA Status

- Documents read at callback evidence time that support the conclusion:
  - UID00009R/UID0002SK establish the `void RenderFrame(GrafPort *, const RectBounds *)` base slot.
  - UID00006V already declares the exact override and fields.
  - UID0003HQ and current source-ready UID0003HS independently produce the two fields.
  - UID00034Y/UID00034Z establish the exact slot cells.
  - UID00041R/UID0001UU/UID0000RA establish helper and singleton routes.
  - UID0004QY MapPane render source establishes void callers.
- Historical pre-callback stale/incomplete docs are repaired:
  - UID0003HU path/title/body/score and helper-pending wording;
  - ItemObjectPane class method row;
  - ItemObjectPane file/aggregate path links;
  - Item vtable action alias;
  - Flying vtable/class inheritance wording;
  - mutable general DrawItemImage destination declaration in UID00041R, UID00017N, UID0001UU, UID00006W, and UID0000KH.
- Generated evidence-time snapshot:
  - later external header command observed during callback reconciliation `13768`, refreshed `2026-07-16T10:13:39-04:00`;
  - B001 callback command `13759` remains the historical implementation-validation checkpoint;
  - target marker once;
  - target definition once;
  - target Empty Emitter Marker zero;
  - old alias token zero;
  - UID0003HS definition once with no UID0003HS marker;
  - class and existing destructor/pool/vtable blocks preserved;
  - no Flying RenderFrame duplicate.
- Callback-time read-only manual coverage hashes:
  - by-memory `E90E7EEAF4DB75AC4DE036F78F5A33BD24814857498C469720E9693862DA794B`, `1,751,703` bytes / `4,219` lines;
  - by-class `A988F0AC3B0330D56BF30A0FD6838B4606DD987C78404BB0C6BE3A6F3B6868BE`, `226,576` / `622`;
  - by-file `E711C3FD4A7EEE11D913439FFD38379884DC440780B4F76AFCCE90B234EE3BC1`, `130,206` / `316`;
  - by-struct `1CF4BE88435275FFEF80180E56425FFE5159AF89DF4E311991DE2B54EECD61F9`, `57,345` / `137`.

## Ranked Ownership Analysis

### 1. UID00006V ItemObjectPane / UID0000KG ItemObjectPane.cpp

- Evidence for:
  - target reads ItemObjectPane's exact tail fields;
  - target occupies ItemObjectPane's primary vtable;
  - complete ItemObjectPane declaration already declares RenderFrame;
  - target sits in the exact ItemObjectPane method cluster;
  - source root already groups Item/Flying classes and pools.
- Evidence against:
  - no material ownership conflict.
- Decision:
  - canonical owner/emitter UID00006V;
  - source root UID0000KG;
  - exact target body in ItemObjectPane.cpp.

### 2. UID000057 FlyingObjectPane

- Evidence for:
  - flying vtable reuses UID0003HU;
  - flying RTTI derives through ItemObjectPane;
  - flying object uses inherited item fields.
- Evidence against:
  - no independent function body;
  - no explicit override entry;
  - base-class RTTI and destructor prove inherited ItemObjectPane behavior.
- Decision:
  - support/inheritor only;
  - no duplicate target owner or body.

### 3. UID00006W / UID0000KH ItemObjImageLib

- Evidence for:
  - owns `DrawItemImage` and `g_pItemObjImageLib`;
  - target directly calls its method.
- Evidence against:
  - target receiver is ItemObjectPane;
  - vtable and fields are ItemObjectPane-owned;
  - helper module owns draw policy, not the virtual wrapper.
- Decision:
  - dependency/support owner only.

### 4. UID00007Q / UID0000L3 MapPane

- Evidence for:
  - MapPane invokes RenderFrame during object render passes.
- Evidence against:
  - callers do not own target vtable, fields, or body;
  - virtual dispatch is generic across ObjectPane families.
- Decision:
  - caller-only support; rejected as owner/source.

### Proposed new file/grouping, if applicable

- Not applicable.
- Existing `NexusTK/map/ItemObjectPane.cpp` is exact.
- Do not create `ItemObjectPaneRender.cpp`, `ObjectPaneRender.cpp`, or an item-image caller helper file.

## Source Placement

- Recommended class declaration route:
  - UID00006V ItemObjectPane declaration in the ItemObjectPane header context.
- Recommended source definition:
  - UID0003HU in `NexusTK/map/ItemObjectPane.cpp`.
- Required source-visible dependencies:
  - ItemObjectPane's own declaration;
  - ItemObjImageLib complete declaration;
  - source-visible `g_pItemObjImageLib` declaration;
  - forward/complete pointer types for GrafPort, RectBounds, and AlphaMaskSurface as already represented by current support.
- Required include direction:
  - ItemObjectPane.cpp must see the ItemObjImageLib declaration/global route before compiling the target definition.
  - No implementation include is needed for FlyingObjectPane solely to inherit this method.
- Rejected placements:
  - MapPane.cpp: caller-only;
  - ItemObjImageLib.cpp: callee-only;
  - ObjectPane.cpp: base default only;
  - FlyingObjectPane-only file: no duplicate override;
  - new standalone helper file: unnecessary.
- Remaining placement uncertainty:
  - exact original header filenames/include order are not preserved;
  - current class/file routes are sufficient and behavior-safe.

## Range / Split / Padding / Reclassification Analysis

- Target range remains `[0x00537c70,0x00537ca2)`.
- No internal branch, secondary entry, thunk, table, literal island, or child split exists.
- Rename is semantic/path correction only; UID must be preserved.
- Predecessor padding `[0x00537c65,0x00537c70)`:
  - 11 bytes;
  - all `0xcc`;
  - already present in `by-memory/-ignored.md`.
- Successor padding `[0x00537ca2,0x00537cb0)`:
  - 14 bytes;
  - all `0xcc`;
  - already present in `by-memory/-ignored.md`.
- Parent UID0001D7 remains a false/non-emitting split index.
- No child creation, merge, padding edit, or aggregate emission was required or performed.

## Negative Evidence Summary

- No direct code callers: expected for a vtable-only override.
- No second FlyingObjectPane RenderFrame function or thunk.
- No target branch or conditional.
- No null checks.
- No target field writes.
- No target rectangle writes.
- No target overlay allocation or alpha-mask behavior.
- No target status-result consumer.
- No evidence for action/interaction/packet semantics despite the old alias.
- No evidence that MapPane or ItemObjImageLib owns the wrapper.
- No evidence for raw vtable source.
- No evidence for a target-specific new source file.
- No active or historical dedicated report that supersedes this work.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing function name:
  - `ItemObjectPane::RenderFrame`.
- Proposed target path:
  - `0x00537c70-0x00537ca2.ItemObjectPaneRenderFrame.md`.
- Proposed source signature:
  - `void ItemObjectPane::RenderFrame(GrafPort *target, const RectBounds *bounds)`.
- Proposed helper declaration refinement:
  - `int ItemObjImageLib::DrawItemImage(void *drawOwner, const RectBounds *dstRect, short itemId, unsigned char paletteFlags, AlphaMaskSurface *overlayMask, float overlayStrength)`.
- Retained field names/types:
  - `short m_itemId`;
  - `unsigned char m_paletteFlags`.
- Comments/prose to preserve:
  - machine `EAX` carries ignored helper status;
  - Flying inherits the same body;
  - no duplicate override or ABI source.
- Items intentionally not renamed:
  - UID00041R physical path already has correct DrawItemImage name;
  - `g_pItemObjImageLib` remains the current project source-facing global;
  - no IDA DB rename/type/comment write is requested or permitted.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes.
- The target is source-authored, reconstructable, owned/emitted, fully typed, and behavior-complete.
- Exactly three destination-specific managed blocks establish the target source closure. No body-only sample is used.

Destination 1: current renamed UID0003HU target, applied exactly.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ItemObjectPane::RenderFrame(
    GrafPort *target,
    const RectBounds *bounds)
{
    g_pItemObjImageLib->DrawItemImage(
        target,
        bounds,
        m_itemId,
        m_paletteFlags,
        0,
        0.0f);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 2: UID00006V ItemObjectPane class declaration, preserved exactly.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ObjectStatusBlob;

class ItemObjectPane : public ObjectPane
{
public:
    ItemObjectPane(
        int objectId,
        int mapX,
        int mapY,
        short itemId,
        unsigned char paletteFlags);
    virtual ~ItemObjectPane();

    void UpdateItemStatus(const ObjectStatusBlob *status);
    virtual void ClearOutputRects(
        RectBounds *firstBounds,
        RectBounds *secondBounds);
    virtual void RenderFrame(
        GrafPort *target,
        const RectBounds *bounds);

protected:
    short m_itemId;                          // +0x128
    unsigned char m_paletteFlags;            // +0x12a
};

typedef char ItemObjectPaneSizeMustBe300[
    sizeof(ItemObjectPane) == 0x12c ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

Destination 3: UID0001UU ItemObjImageLib layout declaration with the bounded const correction applied and all unrelated current content preserved.

*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ItemObjImageLib : public LObject
{
public:
    ItemObjImageLib();
    virtual ~ItemObjImageLib();

    int DrawItemImage(void *drawOwner, const RectBounds *dstRect, short itemId, unsigned char paletteFlags, AlphaMaskSurface *overlayMask, float overlayStrength);
    int DrawItemImageIn43x43Slot(void *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags, AlphaMaskSurface *overlayMask, float overlayStrength);
    int DrawItemImageUnscaled(void *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags);
    int DrawItemImageScaled(void *drawOwner, RectBounds *dstRect, short itemId, unsigned char paletteFlags);

private:
    friend class MapPane;

    void RefreshItemFrameAvailability();

    ProtectedArray<ItemInfo> m_itemInfos;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

- Reason Destination 1 preserves exact behavior:
  - same helper receiver;
  - same two caller arguments;
  - same fields;
  - same null/zero overlay arguments;
  - no branch;
  - no return use.
- Reason source return is void:
  - matches the base virtual contract and every caller;
  - a final ignored `int` call naturally leaves `EAX` unchanged in optimized x86 output.
- Reason Destination 3 is needed:
  - permits the exact target body without a cast;
  - matches UID00041R's read-only use;
  - changes no ABI.
- C++03 compatibility:
  - uses `0`, not `nullptr`;
  - uses ordinary virtual definition syntax;
  - introduces no C++11 construct.
- Exact no-code exclusions:
  - UID00041R body remains blank for its separate partially initialized options-record issue;
  - UID00034Y/UID00034Z remain marker-only;
  - UID0001D7 remains blank/non-emitting;
  - no Flying RenderFrame body is emitted.

## Final Recommendation

- UID0003HU is renamed in place to ItemObjectPaneRenderFrame.
- Target `92/94`, exact Item Summary, exact body, complete evidence, history, and negative evidence are applied.
- UID00006V declaration/score/owner/emitter/position/formal block is preserved.
- UID0000KG remains `91/93` with its source path and synchronized target closure.
- UID0001D7 remains `90/93`, false/no-owner/no-emitter/blank formal.
- UID00034Y remains `90/94` and UID00034Z remains `88/92`, both marker-only.
- UID000057 remains `85/88` with only direct inheritance and inherited body proof added.
- Only the general `DrawItemImage` destination rectangle declaration/prose is const-corrected across UID00041R, UID00017N, UID0001UU, UID00006W, and UID0000KH.
- UID00041R's blank formal body and independent no-code proof are preserved.
- Do not change g_pItemObjImageLib, ObjectPane, MapPane, ignored padding, pools, scalar wrappers, generated output, or manual coverage directly.
- No target-specific blocker remains.

## Recommended Target Doc Changes

- Current callback state: every target change below is applied and validated.
- Target path:
  - historical pre-callback: `by-memory/0x00537c70-0x00537ca2.ItemObjectPaneProcessItemAction.md`;
  - current applied: `by-memory/0x00537c70-0x00537ca2.ItemObjectPaneRenderFrame.md`.
- Metadata:
  - `COMPLETION:92`;
  - `CONFIDENCE:94`;
  - preserve owner/emitter UID00006V;
  - preserve reconstructable true;
  - preserve blank position;
  - preserve `Nested:0`.
- Exact Item Summary:
  - `Source-authored void ItemObjectPane::RenderFrame override that delegates current m_itemId/m_paletteFlags to g_pItemObjImageLib->DrawItemImage with null overlay and zero strength; exact ObjectPane +0x5c slot, FlyingObjectPane inheritance reuse, ignored draw status, and no duplicate flying body.`
- Formal C++:
  - Destination 1 exactly.
- Complete evidence applied:
  - target bytes/hash/instructions;
  - source void versus machine EAX;
  - exact argument order;
  - helper/global identity;
  - field types/names;
  - vtable slots;
  - MapPane caller behavior;
  - Flying RTTI base array;
  - source placement/order/blank-position rationale;
  - padding;
  - negative evidence.
- History preserved:
  - A002 split creation;
  - earlier `ProcessItemAction` alias as superseded;
  - earlier helper-name-pending/body-blank state as superseded.

## Recommended Support Doc Changes

- Current callback state: all listed ordinary support changes are applied and scoped-validated; verify-only pages remained unedited.
1. `by-class/ItemObjectPane.md`
   - preserve `92/94`, owner/emitter/path/position, and Destination 2 exactly;
   - replace stale `ProcessItemAction` method row/link with renamed `RenderFrame`;
   - add exact body/helper/void-return/Flying inheritance/no-duplicate evidence;
   - preserve all unrelated current declaration/destructor/UID0003HS/pool/vtable content.
2. `by-file/ItemObjectPane.md`
   - preserve `91/93` and `NexusTK/map/`;
   - update old path links and source-method inventory;
   - record one RenderFrame definition, helper call, direct inheritance reuse, source order, and no duplicate flying body;
   - preserve the complete current Item/Flying/pool union, including UID0003HS at `92/94` with its exact body.
3. `by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md`
   - preserve `90/93`, false/no-owner/no-emitter/blank formal;
   - update UID0003HU path/title/inventory/evidence;
   - record target `92/94` and one-body inherited reuse;
   - preserve every child, current UID0003HS source-ready synchronization, padding span, and unrelated Flying behavior.
4. `by-memory/0x006203ec-0x00620498.ItemObjectPaneVtableData.md`
   - preserve `90/94` and formal marker;
   - rename primary `0x0062044c` slot to `ItemObjectPane::RenderFrame`;
   - update target link and record source `void` contract.
5. `by-memory/0x00620498-0x00620544.FlyingObjectPaneVtableData.md`
   - preserve `88/92` and formal marker;
   - identify `0x006204f8` as inherited `ItemObjectPane::RenderFrame`;
   - add current eight-entry RTTI base array and no-duplicate proof.
6. `by-class/FlyingObjectPane.md`
   - preserve `85/88`, owner/emitter, blank formal, and all motion/pool evidence;
   - add direct ItemObjectPane inheritance proof;
   - record inherited fields and RenderFrame reuse;
   - do not add a partial class declaration or duplicate body.
7. `by-memory/0x004dee50-0x004defba.ItemObjImageLibDrawItemImage.md`
   - preserve `88/91`, owner/emitter, blank formal, behavior, and kind-3 no-code proof;
   - change signature prose only to `const RectBounds *dstRect`;
   - add UID0003HU caller-specific evidence that target is GrafPort and return is ignored.
8. `by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md`
   - preserve metadata/container disposition;
   - synchronize the UID00041R signature row to const destination bounds;
   - add UID0003HU caller evidence without changing other methods.
9. `by-type/by-struct/ItemObjImageLibLayout.md`
   - preserve `89/92`, owner/emitter, position, fields, friendship, helper, and every unrelated declaration;
   - apply Destination 3 exactly.
10. `by-class/ItemObjImageLib.md`
    - preserve `88/89`, owner/emitter, formal marker, and all unrelated content;
    - synchronize only the UID00041R method signature/prose and target caller evidence.
11. `by-file/ItemObjImageLib.md`
     - preserve current validator-backed `90/88`, path, and all unrelated content;
     - synchronize only the UID00041R method signature/prose and target caller evidence.
     - bounded accepted-report correction: the pre-callback `90/92` support-score sentence conflicted with the executed B007 `90/88` disposition and current header, so B001 preserved `90/88` rather than inflating unrelated confidence.
12. Verify-only, no edit unless current drift contradicts accepted facts:
    - UID0000RA g_pItemObjImageLib;
    - UID00009R ObjectPane;
    - UID0002SK ObjectPane vtable;
    - UID0004QY MapPane render;
    - `by-memory/-ignored.md`;
    - UID0003HQ/HR/HS/HT/HV/HW;
    - pools/scalar wrappers/generated files.

## Score And Metadata Recommendation

- UID0003HU historical pre-callback:
  - `85/90`;
  - owner/emitter UID00006V;
  - reconstructable true;
  - blank position/formal;
  - blank summary.
- UID0003HU current applied:
  - `92/94`;
  - same owner/emitter/reconstructable/position/Nested;
  - exact formal body;
  - exact summary;
  - renamed path/title.
- Completion rationale:
  - exact range/bytes/hash/instructions;
  - exact ABI and parameters;
  - exact source return;
  - exact method name;
  - exact helper/global;
  - exact fields;
  - exact call arguments;
  - exact owner/source/order;
  - exact inherited reuse;
  - exact body;
  - exact negative evidence;
  - exact manual handoff.
- Confidence rationale:
  - current live MCP directly confirms every binary fact;
  - current declarations/callers independently agree;
  - confidence remains below 95 only because exact original lexical spellings, `const` token, and header include order are inferred.
- Score-improvement attempt:
  - helper name: resolved to UID00041R;
  - helper owner/file: resolved to ItemObjImageLib.cpp;
  - first parameter: resolved to target GrafPort forwarded as generic render receiver;
  - bounds type: resolved to const source direction;
  - return type: resolved as source void / helper int ignored;
  - fields: resolved to short item id and unsigned palette flags;
  - caller route: resolved through MapPane render;
  - vtable route: resolved exact +0x5c;
  - Flying reuse: resolved with RTTI base array;
  - body: complete;
  - source placement: complete;
  - split/padding: complete;
  - no blocker remains.
- Support scores:
  - preserve UID00006V `92/94`;
  - preserve UID0000KG `91/93`;
  - preserve UID0001D7 `90/93`;
  - preserve UID00034Y `90/94`;
  - preserve UID00034Z `88/92`;
  - preserve UID000057 `85/88`;
  - preserve UID00041R `88/91`;
  - preserve UID0001UU `89/92`;
  - preserve UID00006W `88/89`;
  - preserve authoritative UID0000KH `90/88`; historical report-only `90/92` wording was stale and was excluded from implementation for exact executed-baseline preservation.

## Open Questions With Attempted Resolution

| Question | Evidence checked | Resolution |
| --- | --- | --- |
| Is the target an action helper or render override? | ObjectPane slot, Item/Flying cells, MapPane callers | RenderFrame override; action alias rejected. |
| Is source return int or void? | nullsub type, vtable contract, callers, final helper call | void; EAX is incidental ignored helper status. |
| What are the two arguments? | ret 8, call sites, current base declaration | GrafPort pointer and const RectBounds pointer. |
| What are +0x128/+0x12a? | constructor, status update, helper consumption | short m_itemId and unsigned char m_paletteFlags. |
| What is 0x004dee50? | current exact page plus live helper body | ItemObjImageLib::DrawItemImage. |
| Does helper mutate bounds? | complete helper body/callback support | no; const destination declaration applied. |
| Why does Flying share the address? | vtable ints, RTTI base array, constructor/destructor | ordinary inheritance through ItemObjectPane. |
| Is a Flying body required? | one address, inherited slot, no second function | no; duplicate forbidden. |
| Is a target emitter position needed? | address order and marker grouping | no; retain blank. |
| Is a split or new source file needed? | exact one-function range/current file route | no. |
| Does UID00041R become source-ready because of this target? | helper options kind-3 proof | no; only its declaration constness changes, body remains blank. |
| What remains uncertain? | PDB/header/source search unavailable | exact original lexical parameter/global/header spellings only; no score/body blocker. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- B001 read the manual coverage files at callback evidence time and did not edit them.
- Callback-time read-only manual hashes were by-memory `E90E7EEAF4DB75AC4DE036F78F5A33BD24814857498C469720E9693862DA794B`, by-class `A988F0AC3B0330D56BF30A0FD6838B4606DD987C78404BB0C6BE3A6F3B6868BE`, by-file `E711C3FD4A7EEE11D913439FFD38379884DC440780B4F76AFCCE90B234EE3BC1`, and by-struct `1CF4BE88435275FFEF80180E56425FFE5159AF89DF4E311991DE2B54EECD61F9`.
- The missing/stale-row observations below are immutable callback-time evidence only. They do not assert whether the supervisor later applied, replaced, revalidated, invalidated, or otherwise synchronized any row.
- Callback-time by-memory target-row observation:
  - no UID0003HU row existed in the snapshot;
  - because the target had been renamed and rescored, B001 supplied the exact addition below.
- Callback-time related-row observations:
  - UID0001D7 manual coverage reflected the UID0003HS source body but omitted the applied UID0003HU source body and inherited one-body reuse;
  - UID00034Y did not name `ItemObjectPane::RenderFrame` in its primary `+0x5c` slot;
  - UID00034Z remained at `86%` and lacked the direct-inheritance proof present in the ordinary target page;
  - ItemObjectPane/FlyingObjectPane class and ItemObjectPane file rows mentioned RenderFrame identity or inheritance but did not preserve the complete source-ready target body and exact one-body reuse at the detail supplied below;
  - ItemObjImageLib class/file/layout rows did not mention the const destination contract.
- Immutable supervisor-owned by-memory handoff additions/replacements:

Placement: under UID0001D7, in address order after UID0003HR and before later Item/Flying rows, add:

```text
        - [UID:0003HU][0x00537c70-0x00537ca2.ItemObjectPaneRenderFrame](by-memory/0x00537c70-0x00537ca2.ItemObjectPaneRenderFrame.md) 0x00537c70-0x00537ca2 | source render override | ItemObjectPaneRenderFrame : reconstructable : 92% : very-strong : Exact void ItemObjectPane::RenderFrame(GrafPort *, const RectBounds *) override that dispatches g_pItemObjImageLib->DrawItemImage with m_itemId, m_paletteFlags, null overlay, and 0.0f strength; direct primary/flying +0x5c vtable reuse, RTTI-proven FlyingObjectPane inheritance, ignored helper status, exact padding, and one source body without duplicate flying override.
```

Replace the UID0001D7 row with:

```text
    - [UID:0001D7][0x00537b40-0x005380af.ItemAndFlyingObjectPanes](by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md) 0x00537b40-0x005380af | non-emitting class-method split index | ItemAndFlyingObjectPanes : not_reconstructable : 90% : very-strong : Address-sorted ItemObjectPane/FlyingObjectPane split index with exact constructor/destructor/status/bounds/render/flying children and confirmed alignment; UID0003HR emits the explicit empty ordinary ItemObjectPane destructor, UID0003HS emits exact source-ready UpdateItemStatus, UID0003HU emits the exact void RenderFrame item-image dispatch once and is inherited by FlyingObjectPane, scalar/vtable/pool lowering remains separate, and all exact children retain direct class/file routes without aggregate duplicate source.
```

Replace the UID00034Y row with:

```text
        - [UID:00034Y][0x006203ec-0x00620498.ItemObjectPaneVtableData](by-memory/0x006203ec-0x00620498.ItemObjectPaneVtableData.md) 0x006203ec-0x00620498 | source-declared/generated-binary RTTI/vtable data | ItemObjectPaneVtableData : reconstructable : 90% : very-strong : Exact ItemObjectPane RTTI plus primary/EventHandler/TimerHandler vtable views, constructor/ordinary/scalar/Flying-base vptr-store routes, primary +0x5c ItemObjectPane::RenderFrame slot, scalar deleting slot, two adjusted deleting thunks, exact Static/Flying boundaries, and formal compiler-generated coverage from the complete ItemObjectPane declaration and source methods.
```

Replace the UID00034Z row with:

```text
        - [UID:00034Z][0x00620498-0x00620544.FlyingObjectPaneVtableData](by-memory/0x00620498-0x00620544.FlyingObjectPaneVtableData.md) 0x00620498-0x00620544 | source-declared/generated-binary RTTI/vtable data | FlyingObjectPaneVtableData : reconstructable : 88% : very-strong : Exact FlyingObjectPane RTTI/vtables with primary/EventHandler/TimerHandler views, constructor/scalar/adjustor routes, eight-entry RTTI base array proving direct ItemObjectPane inheritance, inherited +0x5c ItemObjectPane::RenderFrame reuse, exact Item/Attached boundaries, and formal compiler-generated coverage without a duplicate flying render body.
```

- Immutable supervisor-owned by-class handoff replacements:

Replace UID00006V:

```text
- [UID:00006V][ItemObjectPane](by-class/ItemObjectPane.md) : reconstructable : 92% : very-strong : Complete natural 0x12c ObjectPane-derived ground-item declaration with exact constructor fields and methods, explicit empty ordinary destructor, source-ready UpdateItemStatus, exact void RenderFrame source dispatch through g_pItemObjImageLib with m_itemId/m_paletteFlags, primary/EventHandler/TimerHandler vtable family, scalar deleting/compiler separation, file-static 0x12c/8 pool definition, MapPane factory route, FlyingObjectPane inherited render reuse, exact child inventory, and ItemObjectPane.cpp ownership.
```

Replace UID000057:

```text
- [UID:000057][FlyingObjectPane](by-class/FlyingObjectPane.md) : reconstructable : 85% : strong : Assigned to [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md); current RTTI base-array, constructor, ordinary-destructor, and vtable evidence prove direct ItemObjectPane inheritance and inherited reuse of the single UID0003HU RenderFrame body, while exact Flying vtables, pool storage, MapPane construction, animation behavior, and remaining motion-field/source-name caveats are preserved.
```

Replace UID00006W:

```text
- [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md) : reconstructable : 88% : strong : Item sprite image-library singleton attached to NexusTK/render/ItemObjImageLib.cpp, with corrected method bounds, layout parent chain, vtable/global anchors, ItemInfo table/resource/draw/reload/destructor support, source-facing lightImageIndex semantics, MapPane friendship, const destination-rectangle contract for general DrawItemImage, UID0003HU GrafPort caller evidence, helper ownership, and child-owned method bodies.
```

- Immutable supervisor-owned by-file handoff replacements:

Replace UID0000KG:

```text
- [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md) : reconstructable : 91% : very-strong : NexusTK/map/ItemObjectPane.cpp source root with complete ItemObjectPane declaration, explicit empty ordinary destructor, source-ready UpdateItemStatus, exact constructor/bounds routes, one source-ready void RenderFrame item-image dispatch inherited by FlyingObjectPane, class-generated vtable/scalar-wrapper coverage, separate Item/Flying static pools, preserved companion union, MapPane caller boundary, and no handwritten vptr/delete/pool-wrapper/RTTI duplication.
```

Replace UID0000KH:

```text
- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md) : reconstructable : 90% : strong : NexusTK/render/ItemObjImageLib.cpp source root with corrected method bounds, singleton/vtable/layout anchors, ItemInfo table/resource/draw/reload/destructor support, protected-array layout, MapPane friendship, const destination-rectangle contract for general DrawItemImage, UID0003HU GrafPort caller evidence, resource inputs, legacy remapping policy, helper ownership, destructor/singleton clear, and child-owned method bodies.
```

- Immutable supervisor-owned by-struct handoff replacement:

Replace UID0001UU:

```text
- [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md) : reconstructable : 89% : very-strong : Exact ItemObjImageLib/ProtectedArray<ItemInfo> layout with embedded default row, count/entry/default-capacity fields, constructor/reload/destructor agreement, vtable/singleton anchors, fallback-row behavior, MapPane friendship, const destination RectBounds contract for general DrawItemImage as used by UID0003HU, remaining draw declarations, and no synthetic runtime accessor.
```

- No manual tracker row is authored. `auto-generated/-ag-research-tracker.md` is validator-owned.
- B001 boundary: manual `-coverage-report.md` synchronization was not performed by B001. The exact text above remains supplied handoff material without asserting its later application state.

## Follow-Up Actions

- B001 technical callback work was completed and no B001 target/support/validator/lease action remained at callback return.
- Durable supervisor-owned boundaries:
  - exact manual-coverage handoff text and callback-time read-only hashes are preserved above without asserting whether later application occurred;
  - Gate 2, coverage application, execution/revalidation/invalidation, count, path, move, archive, and lifecycle state are authoritative only in current supervisor/validator-owned records and files, not in this artifact.
- A-agent actions: none.
- Historical accepted B001 callback actions are all applied: validator-aware rename, target body/score/evidence, support synchronization, scoped validators, final waited refresh, generated readback, and same-report reconciliation.
- Out-of-scope independent research:
  - UID00041R's options-record no-code blocker remains its own target;
  - remaining FlyingObjectPane motion fields/method bodies remain separate targets.

## Confidence

- Recommendation confidence: `94/100`.
- Score confidence: high.
- Strongest facts:
  - exact bytes/instructions;
  - exact base/item/flying slot cells;
  - exact void caller casts;
  - exact helper call/arguments;
  - exact fields;
  - exact RTTI base array;
  - exact source root.
- Remaining uncertainty:
  - original lexical parameter/global/header spellings;
  - whether the original declaration explicitly repeated `virtual`;
  - exact include order.
- Remaining uncertainty does not affect runtime behavior, ABI, target owner/emitter, body, score, source file, or duplicate exclusion.

## Validator Results

- Historical report-only phase: no ordinary validator, report lifecycle command, or execute_report/probe/count/revalidation command was run.
- Callback command results:

| Command ID | Timestamp | Scope | Exit / ok | Result and side effects |
| --- | --- | --- | --- | --- |
| `000000013729` | `2026-07-16T09:53:12-04:00` | validator CLI help/schema discovery | `0` | Confirmed no dedicated rename flag; no ordinary file mutation. |
| `000000013730` | `2026-07-16T09:54:28-04:00` | renamed UID0003HU target | `0 / 1` | UID-preserving `path_update`, `92/94`, block registry update, four known link updates, deferred generation; nine pre-existing UID0003HV-HY aggregate reference warnings. |
| `000000013731` | `2026-07-16T09:55:12-04:00` | UID00006V ItemObjectPane | `0 / 1` | Clean scoped pass; deferred generation. |
| `000000013733` | `2026-07-16T09:55:39-04:00` | UID0000KG ItemObjectPane file | `0 / 1` | Added UID0003HU reference index; two pre-existing UID0003HV warnings; deferred generation. |
| `000000013735` | `2026-07-16T09:56:22-04:00` | UID0001D7 aggregate | `0 / 1` | Scoped pass; nine pre-existing UID0003HV-HY warnings; deferred generation. |
| `000000013736` | `2026-07-16T09:56:58-04:00` | UID00034Y Item vtable | `0 / 1` | Added UID0003HU reference index; deferred generation. |
| `000000013737` | `2026-07-16T09:57:36-04:00` | UID00034Z Flying vtable | `0 / 1` | Added UID0003HU reference index; deferred generation. |
| `000000013739` | `2026-07-16T09:58:12-04:00` | UID000057 Flying class | `0 / 1` | Added UID0003HU reference index; nine pre-existing UID0003HV-HY warnings; deferred generation. |
| `000000013741` | `2026-07-16T09:58:45-04:00` | UID00041R DrawItemImage | `0 / 1` | Added UID0003HU reference index; deferred generation. |
| `000000013742` | `2026-07-16T09:59:21-04:00` | UID00017N method cluster | `0 / 1` | Added UID0003HU reference; validator expanded four existing UID0003ND links; pre-existing UID0003LZ/ZN warnings; deferred generation. |
| `000000013744` | `2026-07-16T09:59:53-04:00` | UID0001UU layout | `0 / 1` | Updated formal-block registry hash, added UID0003HU reference; deferred generation. |
| `000000013751` | `2026-07-16T10:00:29-04:00` | UID00006W ItemObjImageLib class | `0 / 1` | Added UID0003HU reference; four pre-existing UID0003LZ warnings; deferred generation. |
| `000000013755` | `2026-07-16T10:02:07-04:00` | UID0000KH initial file pass | `0 / 1` | Exposed accidental UID0000YO reference loss; pre-existing UID0003LZ/ZN warnings; deferred generation. |
| `000000013758` | `2026-07-16T10:02:27-04:00` | UID0000KH no-loss revalidation | `0 / 1` | Restored UID0000YO reference and passed; pre-existing UID0003LZ/ZN warnings; deferred generation. |
| `000000013759` | `2026-07-16T10:03:01-04:00` | final renamed target `--wait-generated` | `0 / 1` | Generated refresh completed; broad autogen reported only pre-existing project-wide marker/no-code warnings. |

- Generated ItemObjectPane.cpp evidence-time snapshot:
  - later external command/header observed during callback reconciliation `000000013768`, refreshed `2026-07-16T10:13:39-04:00`, foreground refresh;
  - observed SHA256 `1C0029CBEF84F63BEBA6012B86DF39651AE9D093C94E4AFBF61C869727E5488B`;
  - `3,935` bytes / `93` lines;
  - B001's command `000000013759` snapshot had SHA256 `02636B43DD18B364B41D006E0C71BFADCC71D436656B5E766E5594CA07C7D97A`; replacing only the observed `000000013768` command/timestamp header values with the earlier values reproduces that exact hash, proving the later external refresh was metadata-only;
  - one UID0003HU marker and one `void ItemObjectPane::RenderFrame` definition;
  - exact call arguments `target`, `bounds`, `m_itemId`, `m_paletteFlags`, `0`, `0.0f`;
  - zero UID0003HU Empty Emitter Markers, zero `ProcessItemAction` tokens, zero FlyingObjectPane RenderFrame definitions, one class shell, and preserved UID0003HR/HS, pools, scalar/vtable markers, and Flying marker.
- Generated ItemObjImageLib.cpp evidence-time snapshot:
  - later external command/header observed during callback reconciliation `000000013768`, refreshed `2026-07-16T10:13:39-04:00`;
  - observed SHA256 `59BFCA6647C2BB54DE87ABF47E389C327BC1DB10C64AB8F1B91C30915D36A03A`;
  - `7,533` bytes / `169` lines;
  - B001's command `000000013759` snapshot had SHA256 `49288B626EBD3B87618575AD243A863C68AB04C7BC671AC2E2D370E086FA1CE4`; replacing only the observed `000000013768` command/timestamp header values with the earlier values reproduces that exact hash, proving the later external refresh was metadata-only;
  - one const general DrawItemImage declaration and zero mutable general declarations.
- Managed formal-block parity:
  - Destination 1 report/target body exact, normalized SHA256 `2C8A4D5967594A0D3CF6DBE25E1512217A9B5FEFBF63D1C0B432011EADA8D32C`;
  - Destination 2 report/class body exact, normalized SHA256 `9B3CE357305B71160AB1AF3199B4F35C3ED91FE0A376AF1957231C7F6F01283A`;
  - Destination 3 report/layout body exact, normalized SHA256 `560ADB3DA7EB0D78B2C84F079034D10D7E9AB7EA1857454292ED2B8DB6FE5009`.
- No report validator, execute_report, report lifecycle/probe/count/revalidation, move, or archive command was run.

## Changed Files

- UID-preserving rename:
  - historical `by-memory/0x00537c70-0x00537ca2.ItemObjectPaneProcessItemAction.md` no longer exists;
  - callback-completion `by-memory/0x00537c70-0x00537ca2.ItemObjectPaneRenderFrame.md`: SHA256 `9039E02FDA62737B5B839471D68C787F8B7300DCD9177A7B314E771D4296A145`, `9,976` bytes / `102` lines.
- Modified ordinary destinations at B001 callback completion:
  - `by-class/ItemObjectPane.md`: `FFA75774B39AC6A7E73699CC2EE85FDD7ECE812B3CA86695203C518C99555C6E`, `26,442` / `196`;
  - `by-file/ItemObjectPane.md`: `A461AF021C7B6CB84ED82E2CEDA67FDE0856B7A563444736F5268244798CD0EA`, `34,669` / `217`;
  - `by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md`: `56BE4D3856CC9A20FFF5D01556CB55391B43EA22AD5D548984E694E0F9312684`, `22,215` / `150`;
  - `by-memory/0x006203ec-0x00620498.ItemObjectPaneVtableData.md`: `5C27527BF462B92E83F8670A435619CD7A159B3E6611F0E6A3B2980E811E1C34`, `18,233` / `149`;
  - `by-memory/0x00620498-0x00620544.FlyingObjectPaneVtableData.md`: `1A23EA50ED332625E91E599C99480D332A2C790B50E1FF9D858CD6EC430AF5D4`, `15,889` / `138`;
  - `by-class/FlyingObjectPane.md`: `21D0FF3FB58A0C257CAE0FC367043591B04A2205DBBA8FD595FA13612BAE0675`, `17,428` / `114`;
  - `by-memory/0x004dee50-0x004defba.ItemObjImageLibDrawItemImage.md`: `9B3B7E5582F4FF18483F490FCF16A043A653D4E8AE568E5D7396764E29F6B6A6`, `18,711` / `164`;
  - `by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md`: `C514F9BB8E7C0221C6FE8E9124C0BE4D3C08050866E94C503C8725B55037B8F6`, `42,162` / `230`;
  - `by-type/by-struct/ItemObjImageLibLayout.md`: `924DCFFD204AF8E2930B8D7E4D4C4681ADEC75FE0EDAE4435B8D5A6CAFB4796C`, `13,891` / `124`;
  - `by-class/ItemObjImageLib.md`: `F66BD379F43CEB492A29517E18229E7FE246407B1F89675DE272433D139C0FCF`, `41,509` / `193`;
  - `by-file/ItemObjImageLib.md`: `05B1A16C96332A58BF9ABB733C05E1142BD816CA363E83F40BBAC921348CF89A`, `40,366` / `195`.
- Validator-owned generated outputs changed through authorized validation only; B001 did not edit them manually.
- Generated evidence-time readback after the later external command `000000013768`:
  - `auto-generated/NexusTK/map/ItemObjectPane.cpp`: `1C0029CBEF84F63BEBA6012B86DF39651AE9D093C94E4AFBF61C869727E5488B`, `3,935` / `93`;
  - `auto-generated/NexusTK/render/ItemObjImageLib.cpp`: `59BFCA6647C2BB54DE87ABF47E389C327BC1DB10C64AB8F1B91C30915D36A03A`, `7,533` / `169`;
  - both are exact command/timestamp-header-only successors to B001 command `000000013759`, with unchanged semantic assertions.
- Manual coverage files were read only at callback evidence time: by-memory `E90E7EEAF4DB75AC4DE036F78F5A33BD24814857498C469720E9693862DA794B`, by-class `A988F0AC3B0330D56BF30A0FD6838B4606DD987C78404BB0C6BE3A6F3B6868BE`, by-file `E711C3FD4A7EEE11D913439FFD38379884DC440780B4F76AFCCE90B234EE3BC1`, and by-struct `1CF4BE88435275FFEF80180E56425FFE5159AF89DF4E311991DE2B54EECD61F9`.
- Manual coverage, tracker, audit, supervisor, validator-state, lifecycle, archive, and IDA files were not edited by B001.
- The only non-ordinary file edited by B001 is this same report.
- No B001 lease remains.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor Gate 1 passed exact SHA `B6C149D0C5AE282AE49D668DC523161FFE85B07455B6440F8554368203693E35`.
- [x] Target validator-aware UID-preserving rename from ItemObjectPaneProcessItemAction to ItemObjectPaneRenderFrame completed by command `000000013730`.
- [x] UID0003HU metadata is `92/94` with owner/emitter/reconstructable/blank-position/Nested preserved.
- [x] UID0003HU exact Item Summary inserted.
- [x] Destination 1 exact managed target body inserted.
- [x] UID00006V Destination 2 exact complete declaration preserved byte-for-byte.
- [x] Current UID0003HS `92/94` body/evidence and B005 union preserved.
- [x] UID0001UU Destination 3 exact declaration applied with only general DrawItemImage destination const correction.
- [x] Target exact range/bytes/hash/instructions/ABI documented.
- [x] Source `void` versus incidental helper `EAX` documented.
- [x] Exact target argument order and no-guard/no-branch behavior documented.
- [x] `m_itemId` and `m_paletteFlags` types/names synchronized.
- [x] UID00041R helper/global/return/const-bounds caller contract synchronized.
- [x] Flying RTTI eight-entry base array and direct ItemObjectPane inheritance synchronized.
- [x] Single inherited RenderFrame body/no Flying duplicate synchronized.
- [x] Source placement/order/blank-position/include/declaration route synchronized.
- [x] Pre/post padding verified already present; no ignored edit.
- [x] All stale ProcessItemAction/helper-pending/blank-body current wording historicalized.
- [x] Claim And Incorporation Ledger rows C3HU-001 through C3HU-052 have legal terminal states and claim-specific proof.
- [x] Manual coverage handoff compared against callback-time files and exact supervisor text preserved without asserting later application state.
- [x] Wave2/Wave3 material retained only as rejected historical lead.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] Re-read all current destinations and confirmed no overlapping lease/conflict.
- [x] Renamed target serially and captured validator-preserved UID/path result before dependent edits.
- [x] Lease/edit/validate/release renamed UID0003HU completed.
- [x] Lease/edit/validate/release UID00006V ItemObjectPane completed.
- [x] Lease/edit/validate/release UID0000KG ItemObjectPane file completed.
- [x] Lease/edit/validate/release UID0001D7 aggregate completed.
- [x] Lease/edit/validate/release UID00034Y ItemObjectPane vtable completed.
- [x] Lease/edit/validate/release UID00034Z FlyingObjectPane vtable completed.
- [x] Lease/edit/validate/release UID000057 FlyingObjectPane completed.
- [x] Lease/edit/validate/release UID00041R DrawItemImage completed.
- [x] Lease/edit/validate/release UID00017N ItemObjImageLib method cluster completed.
- [x] Lease/edit/validate/release UID0001UU ItemObjImageLib layout completed.
- [x] Lease/edit/validate/release UID00006W ItemObjImageLib class completed.
- [x] Lease/edit/validate/release UID0000KH ItemObjImageLib file completed, including no-loss revalidation `000000013758`.
- [x] UID0000RA/ObjectPane/MapPane/ignored/pools/scalar/sibling verify-only pages preserved; only validator-owned rename link propagation occurred where applicable.
- [x] Final renamed UID0003HU `--wait-generated` refresh completed by B001 as `000000013759`; later external generated headers observed at evidence time were `000000013768` with metadata-only refresh proof and unchanged semantic assertions.
- [x] Generated ItemObjectPane.cpp has one UID0003HU marker and one `ItemObjectPane::RenderFrame` definition.
- [x] Exact target body has target, bounds, m_itemId, m_paletteFlags, `0`, and `0.0f`.
- [x] Generated target has no UID0003HU Empty Emitter Marker, old ProcessItemAction token, return statement, const_cast, guard, or duplicate Flying body.
- [x] Callback-completion ItemObjectPane declaration/destructor/pools/vtable markers/Flying marker were intact.
- [x] Callback-completion UID0003HS definition was exact and unique with no Empty Emitter Marker.
- [x] Re-read manual coverage without editing it; callback-time hashes and exact immutable handoff text are recorded without asserting later application state.
- [x] Every C3HU ledger row has a legal terminal callback state with claim-specific proof.
- [x] Exact callback-completion paths/hashes, validator IDs/timestamps/exits/ok/side effects, B001 command `000000013759` plus later evidence-time external command `000000013768` generated hash/count assertions, callback-time manual hashes, and zero leases are recorded.
- [x] Every callback item is terminal; rejected/no-code/no-split claims carry exact reasons and no claim is blocked.
- [x] B001 ran no execute_report, lifecycle/probe/count/move/archive command.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000013793","destination_path":"executed-b-agent-research/B001/0003HU-ItemObjectPaneRenderFrame-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0003HU-ItemObjectPaneRenderFrame-source-quality.md","timestamp":"2026-07-16T10:54:30-04:00","uid":"0003HU"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
