** TARGET-REPORT-UID:0003HT **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# 0003HT ItemObjectPaneClearOutputRects Source-Quality Research


## Finalized Report / Current Recommendation

- B005 implemented the accepted callback. [UID:0003HT] is now `by-memory/0x00537bf0-0x00537c65.ItemObjectPaneClearOutputRects.md` at `92/94`, with owner/emitter [UID:00006V], reconstructable true, blank position, `Nested:0`, exact Item Summary, and Destination 1's complete source-era virtual body.
- Final technical disposition: ordinary source-authored `ItemObjectPane::ClearOutputRects` override in `NexusTK/map/ItemObjectPane.cpp`; exact machine range `[0x00537bf0,0x00537c65)`, one primary-vtable route, no ordinary direct caller, no split, and no compiler/no-source disposition.
- UID0000UQ is now the public nonvirtual `ItemObjImageLib::GetItemGlyphBounds` member at `92/94`, owner/emitter [UID:00006W]. All 48 direct calls supply `g_pItemObjImageLib` in `ECX`, none consumes the machine `EAX` result, and Destinations 3 and 4 now provide the declaration and qualified definition.
- `firstBounds`/`secondBounds` and current clip/dirty claims were superseded by source-facing `paneBounds` and `objectDataBounds`. UID00020R is now `92/94` with Destination 6; UID0003XX and UID0004DS retain blank formals under their narrowed independent blockers.
- Confidence: very strong for target range, body, ABI, virtual identity, two output roles, helper receiver/return contract, tile/global/rectangle dependencies, source placement, and complete first-draft source. Original lexical spelling is not symbol-proven, so scores remain below 95.
- The immutable callback-return marker is recorded under Follow-Up Actions. External Gate 2, coverage, execution, archive, revalidation, tracker, path, and lifecycle state remain authoritative only in current validator/supervisor-owned artifacts.

## Supporting Research

- Canonical workspace: `E:\NTK\GhidraBridge\source-3\project-documentation`.
- Assigned report path: `tools/leaser/Agents/Agent-B005/research/0003HT-ItemObjectPaneClearOutputRects-source-quality.md`.
- Assignment source at the research pass: `tools/leaser/Agents/Agent-B005/goal.md`, report-first mode, provenance `CHATGPT | 5.6 | xHigh`.
- Project workflow read in full:
  - `E:\NTK\GhidraBridge\.codex\skills\ntk-b-agent-workflow\SKILL.md`;
  - `references/b-agent-research-and-implementation-workflow.md`;
  - `references/b-agent-report-template.md`;
  - `references/score-blocker-audit-standard.md`;
  - relevant `by-structure.md` ownership, emitter, C++ gate, rename, and by-memory range rules.
- Fresh MCP discovery returned one active adopted database session, `64c11373`, for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `21508`, `is_analyzing:false`.
- Schema-current `server_health(database="64c11373")` returned `status:"ok"`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready with 2067 entries. A first client call used the obsolete argument spelling and returned the expected schema error; it was corrected after `tools/list`. This was not an MCP outage.
- All IDA work was read-only. No IDA rename, type application, comment edit, patch, save, or database mutation was performed.
- Initial evidence-time generated checkpoint read-only:
  - validator command `000000013784`;
  - refreshed `2026-07-16T10:42:04-04:00`;
  - `auto-generated/NexusTK/map/ItemObjectPane.cpp` SHA256 `72234EDA0223F577004200B742F0ADA2780840EA651AB500FD96C9DB9114DCE6`;
  - `auto-generated/NexusTK/render/ItemObjImageLib.cpp` SHA256 `D821906C193A403AF2BC888725DAC4A3DE8099658B6E144B06509DA443F59F5B`;
  - `auto-generated/NexusTK/map/ObjectPane.cpp` SHA256 `0DEA93F2CF0968746F301FA476B7143185DE086FFC3D1C300A5A47A013296CCB`;
  - `auto-generated/NexusTK/map/MapPane.cpp` SHA256 `FA22D3F67860BB302CED446C8F4EC07CCF5E80759D869D71095427B99362074B`.
- Final report-only generated recheck:
  - validator command `000000013791`;
  - refreshed `2026-07-16T10:53:06-04:00`;
  - `auto-generated/NexusTK/map/ItemObjectPane.cpp` SHA256 `7D3FAAB519E2FBBBF2700DA920F5C8240CE981A8D6FBABB7C7AF20DE056020B3`;
  - `auto-generated/NexusTK/render/ItemObjImageLib.cpp` SHA256 `CA2272FDE5AF022AE995A90F4A03CDADABC9D0E910893645299BDA6211CB53C9`;
  - `auto-generated/NexusTK/map/ObjectPane.cpp` SHA256 `EEDEF92CF1F81C8D6865B9AE75C6DAD3BB806D3868CAE84A31766D4B7CF479B8`;
  - `auto-generated/NexusTK/map/MapPane.cpp` SHA256 `FB36170FB52BD16A260CA0EDF9EC98CB198FBFB27B44C96534A8457943C25861`.
- Command `13784` remains labeled historical initial evidence; command `13791` is the final read-only generated checkpoint for this artifact. Validator-owned headers, current files, registry/audit state, and executed archives remain authoritative for later external lifecycle state.
- Callback validation/generated checkpoint:
  - fifteen changed ordinary pages each passed a scoped validator under a short one-file lease; UID0000UQ and UID00017N received bounded second scoped passes `13821`/`13822` after the final contradiction scan historicalized two stale source-shape sentences;
  - initial waited refresh `13820` remains historical callback proof; final waited target refresh command `000000013823`, timestamp `2026-07-16T11:35:44-04:00`, exit `0`, `ok:1`, generated refresh completed;
  - current generated hashes at the final callback checkpoint are ItemObjectPane.cpp `4F414AFA1BBD102D375D142127FE2480AC256F4B977C9B40C0D36ED651BF80AF`, ItemObjImageLib.cpp `5B89682E0F9550BC450609D0389E7C6FDDE8E918DA27FEEC43F6671DA8DCA8A0`, ObjectPane.cpp `E759763C90CC14DA942A063A4ABCDEE844F8E9348972EB62D539DD6B0444DC28`, MapPane.cpp `B30F08ADE4A77135B6447B7ADB37F08F7CDD85E6BAF682C5A669C682CE9BA67D`, and RectBounds.cpp `CFC45D14012EE3B3C2805908B34B76142369097E18F16ECFA7F9B593BFB9E48B`;
  - commands `13784` and `13791` remain historical report-only checkpoints; commands `13820` and `13823` are callback-time generated evidence, not permanent external lifecycle assertions.

### Old-report search record

Exact terms searched:

`0003HT`, `0x00537bf0`, `0x00537c65`, `ItemObjectPaneBuildCenteredItemRect`, `ItemObjectPaneClearOutputRects`, `BuildCenteredItemRect`, `ClearOutputRects`, `sub_537BF0`, `ItemObjectPane`, `GetItemGlyphBounds`, `sub_4DF460`, `g_pItemObjImageLib`, `MapTilePixelDimensions`, `ItemObjImageLib`, `ObjectPane`, `MapPane`, `ItemObjectPane.cpp`, and `ItemObjImageLib.cpp`.

Roots searched:

- central `executed-b-agent-research`;
- every existing `tools/leaser/Agents/Agent-B*/research` directory;
- legacy per-agent `research/executed` roots, of which none currently exists;
- `tools/leaser/Agents/Older-Research`;
- `tools/leaser/Agents/SpecialReports`.

No match was found in `Older-Research` or `SpecialReports`. No artifact with `TARGET-REPORT-UID:0003HT` exists. Matching reports opened and classified:

| Report path | Match | Classification and useful fact |
| --- | --- | --- |
| `executed-b-agent-research/B001/0003HU-ItemObjectPaneRenderFrame-source-quality.md` | incidental target-family | The initial search encountered B001's then-active path; the authoritative artifact is now this executed archive, SHA256 `D8F23D253316C63DAB5478264DA0F6CCDF1B582CA139E21F1AA3872624B15F0C`. It establishes current RenderFrame source order, fields, singleton draw route, and UID0003HT as the separate bounds override. It does not research the UID0003HT body. |
| `executed-b-agent-research/B004/0003HQ-ItemObjectPaneConstructor-source-quality.md` | incidental target-family | The initial search encountered B004's then-active path; the authoritative artifact is now this executed archive, SHA256 `B85F1B9F78BD453AB6C2D35A4E830505F5C292444B66A6F4BA4092AD6C7D2087`. It preserves UID0003HT as separate work and confirms class/file order and the implemented constructor union. It is not direct target research. |
| `tools/leaser/Agents/Agent-B008/research/0002WS-ItemObjectPanePoolStaticStorage-source-quality.md` | incidental legacy nonterminal path | Old nonterminal pool artifact containing target start inventory. Current by-* docs and the executed B004 pool artifact supersede it as authority. |
| `tools/leaser/Agents/Agent-B009/research/0002WT-FlyingObjectPanePoolStaticStorage-source-quality.md` | incidental legacy nonterminal path | Old nonterminal flying-pool support only. It does not resolve UID0003HT. |
| `executed-b-agent-research/B013/00034Y-ItemObjectPaneVtableData-empty-emitter-source-quality.md` | incidental direct vtable evidence | Confirms cell `0x00620440 -> 0x00537bf0`; its `BuildCenteredItemRect` slot label is descriptive and superseded by the inherited `ClearOutputRects` contract. |
| `executed-b-agent-research/B001/0003HR-ItemObjectPaneNonDeletingDestructor-source-quality.md` | incidental source-order evidence | Confirms the ItemObjectPane source sequence and target as a separate verify-only bounds override. |
| `executed-b-agent-research/B002/0003TX-MapPaneHandleObjectInfoPacket-source-quality.md` | incidental naming/class evidence | Correctly supersedes `BuildCenteredItemRect` with inherited `ClearOutputRects`, but does not resolve the two rectangle roles, target body, or helper receiver. |
| `executed-b-agent-research/B004/0002WS-ItemObjectPanePoolStaticStorage-source-quality.md` | incidental pool/source-file evidence | Confirms ItemObjectPane.cpp ownership and compiler pool separation; no target-body conclusion. |
| `executed-b-agent-research/B003/0000UQ-GetItemGlyphBounds-source-quality.md` | direct helper evidence | Strong behavior/range/remap/void-result evidence. Its free-`__stdcall` and rejected-member conclusion is superseded by the current exhaustive 48-call receiver audit. |
| `executed-b-agent-research/B005/0004DS-MapPaneUpdateObjectPaneScreenBounds-source-quality.md` | direct downstream-role evidence | Establishes the MapPane consumer and its prior unresolved `+0x50/+0x2c` slot blockers. Current target/ObjectPane evidence resolves those two slots while leaving other UID0004DS blockers intact. |
| `executed-b-agent-research/B001/0001D5-objectpane-core-source-quality.md` | direct base-contract evidence | Establishes ObjectPane split children, `m_objectDataRect`, and default two-output virtual behavior. Current evidence closes exact parameter roles and base helper source. |
| `executed-b-agent-research/B008/00006W-ItemObjImageLib-class-source-quality.md` | direct helper-owner history | Preserves the historical free-helper rationale. Current all-caller `ECX` evidence disproves that route without changing the item-image module. |
| `executed-b-agent-research/B005/00017N-ItemObjImageLibLocalMethodCluster-source-quality.md` | direct helper-container history | Confirms range/padding and the old free-helper split. Current member classification changes only UID0000UQ's narrow class owner/emitter and declaration shape. |

Evidence-based conclusion: no prior direct UID0003HT report exists. Prior target mentions are incidental family, vtable, caller, or class-declaration evidence; prior UID0000UQ work is direct helper research but contains a now-disproved ownership/ABI interpretation.

## Target

- Target UID: `0003HT`.
- Current target path: `by-memory/0x00537bf0-0x00537c65.ItemObjectPaneClearOutputRects.md`.
- Historical pre-callback path: `by-memory/0x00537bf0-0x00537c65.ItemObjectPaneBuildCenteredItemRect.md`; it no longer exists.
- Current title: `ItemObjectPane ClearOutputRects`.
- Historical pre-callback title: `ItemObjectPane Build Centered Item Rect`.
- Source queue row: command `13772`, `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Current metadata: `92/94`, owner/emitter `00006V`, reconstructable true, blank optional position, complete formal C++, exact Item Summary, `Nested:0`.
- Direct class/file route: [UID:00006V] `ItemObjectPane` at `92/94`, emitted through [UID:0000KG] `NexusTK/map/ItemObjectPane.cpp` at `91/93`.
- Exact executable range: `[0x00537bf0,0x00537c65)`, size `0x75` / 117 bytes (Verified with `int_convert.py`).

## Current Target State

- The target page now contains the accepted path/title, `92/94` metadata, exact formal block, Item Summary, bytes/hash/CFG/ABI/vtable/xref/padding/helper/global/output-role/geometry/compiler evidence, and historical `BuildCenteredItemRect` correction.
- Generated `ItemObjectPane.cpp` at final callback command `13823` contains the complete class, exactly one UID0003HT definition, zero UID0003HT empty markers, and one `g_pItemObjImageLib->GetItemGlyphBounds` member call.
- The ItemObjectPane and ObjectPane declarations now use `paneBounds` and `objectDataBounds`. UID0003XX documents optional object-data-bounds fallback to `SetObjectData`; clip/dirty wording remains only as superseded history.
- UID0000UQ now emits exactly one qualified `ItemObjImageLib::GetItemGlyphBounds` definition and one class declaration, with zero unqualified definitions and zero UID0000UQ empty markers.
- UID00020R now emits exactly one source-ready `ObjectPane::ClearOutputRects` definition and zero UID00020R empty markers.
- UID0004DS remains intentionally no-code for unresolved movement fields and additional virtuals, while slots `+0x50` and `+0x2c` are now documented as `ClearOutputRects` and `SetBounds`.
- Current padding is already represented in `by-memory/-ignored.md`: `[0x00537be9,0x00537bf0)` and `[0x00537c65,0x00537c70)` are included in the object-pane alignment entry. No padding page or ignored-file edit is required.
- B005 changed the fifteen accepted ordinary destinations and this report. B005 did not manually edit generated, manual coverage, tracker, registry, audit, supervisor, or lifecycle state; validator-owned generated/projected metadata side effects are recorded below.

## Executive Recommendation

- The accepted callback emits the target as `void ItemObjectPane::ClearOutputRects(RectBounds *paneBounds, RectBounds *objectDataBounds)`.
- Use the existing ItemObjectPane fields exactly: `m_itemId` is the signed/16-bit item id at `+0x128`; `m_paletteFlags` is unrelated and not read here.
- Call `g_pItemObjImageLib->GetItemGlyphBounds(m_itemId, paneBounds)`.
- Normalize the returned rectangle by offsetting `-left` and `-top`.
- Center the normalized rectangle using `g_mapTilePixelWidth / 2 - paneBounds->right / 2` and `g_mapTilePixelHeight / 2 - paneBounds->bottom / 2`. Do not rewrite this as `(right-left)` or `(bottom-top)`: the binary reads only `right` and `bottom` after the prior normalization call.
- Copy the centered pane rectangle to `*objectDataBounds` last.
- Add no null checks, singleton checks, resource-result checks, empty-rect handling, clamping, local temporary, return expression, handwritten vtable dispatch, SSE intrinsic, or ABI wrapper.
- UID0000UQ is reclassified to narrow class owner/emitter [UID:00006W], its existing body is qualified as an ItemObjImageLib member, and the declaration is present in the formal ItemObjImageLib layout class.
- UID00020R now has its source body and ObjectPane uses the semantic declaration names. UID0003XX and UID0004DS formal blocks remain blank with corrected pane/object-data semantics and narrowed no-code proof.

## Supervisor Active Recheck

- The supervisor assigned a new direct UID0003HT report rather than accepting prior family mentions as coverage.
- The target did not require a split. It is already an exact modeled function with exact predecessor/successor padding and a single vtable pointer route.
- All source-bearing dependencies needed for the target have a concrete disposition:
  - ItemObjectPane declaration and fields are complete;
  - RectBounds layout and `OffsetRect` are source-ready;
  - tile globals are source-ready signed shorts;
  - UID0000UQ is resolved as a member with a complete body;
  - base UID00020R is resolved with a complete body;
  - downstream UID0003XX/UID0004DS roles are resolved enough for exact prose and parameter names without inventing their remaining source.
- Executed UID0003HQ and UID0003HU archives were read only. This report does not overwrite their target-specific work.

## Inference Research Guidance Check

- Direct IDA facts were kept separate from documentation evidence and source inference.
- Existing names were not copied as authority:
  - `BuildCenteredItemRect` was tested against the vtable/base contract and rejected as the accepted source name;
  - `firstBounds`/`secondBounds` and `clipBounds` were tested against the downstream copy/update flow;
  - `GetItemGlyphBounds` free-helper ownership was tested against every direct caller's receiver setup;
  - raw `word_66DA9C`, `word_66DAA0`, `dword_67A758`, and `sub_4B7E10` names were mapped only after current support and binary use agreed.
- Generated C++ was treated as a lead and freshness snapshot, not source authority.
- The member-helper conclusion is inferred source shape, but it is based on exhaustive machine receiver setup and the ABI-compatible unused-`this` pattern, not on generated call syntax alone.
- No Wave2/Wave3 material was used as authority. Any stale generated or old-report alias was retained only as historical/search provenance.

## Heuristic / Inference Reanalysis And Validation

1. Target identity:
   - Direct fact: `0x00620440` is the sole pointer to `0x00537bf0` and is ItemObjectPane primary-vtable base `0x006203f0` plus `0x50`.
   - Documentation fact: ObjectPane's accepted slot `+0x50` is `ClearOutputRects(RectBounds *, RectBounds *)`.
   - Decision: inherited override identity is `ItemObjectPane::ClearOutputRects`, not an unrelated helper named only by its centering effect.

2. ABI and return:
   - Direct fact: target is a `thiscall` body, receives two stack pointers, and ends `retn 8`.
   - Direct fact: the final assignment loads the second pointer into `EAX` and performs a 16-byte copy.
   - Decision: source return is `void`; the output-pointer value in `EAX` is incidental lowering from the final assignment. No caller receives it because reachability is virtual and the inherited contract is void.

3. First output role:
   - Direct fact: MapPane calls slot `+0x50` into local rectangle `v13`, offsets `v13` by movement-interpolated screen coordinates, and passes it as the first argument to object slot `+0x2c`.
   - Direct fact: ObjectPane slot `+0x2c` compares its first argument with current inherited visible bounds, updates pane origin from its top/left, stores it into inherited bounds, and normalizes the local bounds.
   - Decision: `paneBounds`.

4. Second output role:
   - Direct fact: MapPane offsets `v14` by the non-interpolated base tile coordinate and passes it as the second argument to slot `+0x2c`.
   - Direct fact: ObjectPane slot `+0x2c` selects the second argument when non-null and forwards it to virtual slot `+0x54`, the accepted `SetObjectData` method that stores `m_objectDataRect`.
   - Decision: `objectDataBounds`; historical `clipBounds`, `dirtyBounds`, and generic `secondBounds` are superseded for this contract.

5. Item field:
   - Direct fact: `movzx eax, word ptr [ecx+128h]`.
   - Documentation fact: ItemObjectPane complete layout has `short m_itemId` at `+0x128` and `unsigned char m_paletteFlags` at `+0x12a`.
   - Decision: helper receives `m_itemId`.

6. Item-image helper owner:
   - Direct target fact: `mov ecx, dword_67A758` immediately precedes the UID0000UQ call.
   - Exhaustive caller fact: 48 direct call sites across 23 functions were audited from MCP bytes. All supply the same singleton in `ECX`.
   - Branch-sensitive closure:
     - `0x004c7db6` receives `ECX` from `mov ecx, dword_67A758` at `0x004c7bdb` before the branch to `0x004c7d99`;
     - the fourteen calls `0x005a0d28-0x005a13ad` use the singleton loaded to `ESI` at `0x005a065a`, stored at `[ebp-0x70]` at `0x005a0675`, reached for the first call by branch `0x005a071d -> 0x005a0d0c`, and restored between repeated blocks.
   - ABI fact: a nonstatic thiscall member with an unused receiver and two explicit arguments also ends `retn 8`; Hex-Rays can mispresent it as `__stdcall` when `this` is optimized unused.
   - Decision: public nonvirtual `ItemObjImageLib::GetItemGlyphBounds`, not a free function.

7. Helper return:
   - Exhaustive fact: all 48 call sites were checked for `EAX` use after the call; zero reads occur before overwrite or another call.
   - Body fact: the meaningful result is the mutated `RectBounds`.
   - Decision: source return `void`.

8. Normalization:
   - Direct fact: first `OffsetRect` receives `dx = -left`, `dy = -top`.
   - Decision: top-left becomes `(0,0)` and right/bottom become width/height extents.

9. Centering:
   - Direct fact: signed-short globals are promoted, divided by two, and subtract half of normalized `bottom`/`right`.
   - Direct fact: code reads `paneBounds->right` and `paneBounds->bottom`, not left/top again.
   - Decision: preserve the exact two-stage source shape rather than combining it into width/height expressions that would normally emit extra loads/subtractions.

10. Copy/order:
    - Direct fact: final `movups` copies the first output to the second only after both offsets.
    - Decision: `*objectDataBounds = *paneBounds;` is the source statement. SIMD is compiler lowering.

11. Guards and edge behavior:
    - Direct fact: one basic block, complexity 1, no conditional branch.
    - Decision: no null guard, no singleton guard, no helper-result check, no dimension check, no empty-rect branch, and no alternate output order.

12. Base default:
    - Direct fact: UID00020R calls `InitRectBounds` twice with four zero coordinates and returns `retn 8`.
    - Documentation fact: `RectBounds` and `InitRectBounds` are accepted source types/names.
    - Decision: source-ready base virtual body; old "name/type not final" blocker is superseded.

13. Downstream support:
    - UID0003XX exact semantics are now `paneBounds` plus optional `objectDataBounds`; its body remains independently blank because inherited GrafPort/Pane field-expression source shape is outside this target's required output and is not needed to compile the accepted class surface.
    - UID0004DS slots `+0x50` and `+0x2c` are resolved, but movement fields, MapPane slots `+0x20/+0x28`, and the full helper body still retain an exact target-specific no-code proof. No false claim that all UID0004DS blockers are closed is made.

Rejected alternatives:

- MapPane-owned target body: rejected because MapPane is the virtual caller and coordinate consumer, while the method receiver, vtable, fields, and file route are ItemObjectPane.
- ItemObjImageLib-owned target body: rejected because it owns the glyph lookup dependency, not the ItemObjectPane virtual.
- RectBounds-owned target body: rejected because `OffsetRect` is a dependency only.
- Free UID0000UQ helper: rejected by all-caller `ECX` evidence.
- Static ItemObjImageLib helper: rejected because a normal static member would not use thiscall receiver setup; an explicitly `__stdcall` static would be an unsupported, less plausible source shape.
- `RectBounds` return or pointer return: rejected by inherited void virtual contract and output mutation.
- Local temporary rectangle: rejected because the first caller output is used directly throughout the body.
- Width/height difference expression in the second offset: rejected because the binary reads only normalized right/bottom.
- Combined one-call centering helper: rejected by two direct `OffsetRect` calls.
- Compiler-generated/no-source method: rejected by ordinary body, source virtual contract, helper calls, field access, and class source placement.

## Evidence Standards Used

- Highest-weight evidence:
  - fresh IDA MCP function lookup, health, decompile, disassembly, basic blocks, xrefs, callees, bytes, globals, signatures, and pointer search;
  - exact vtable data and current class declarations;
  - exhaustive caller receiver/result audit from MCP-read bytes using local Capstone disassembly.
- Supporting evidence:
  - current by-memory/by-class/by-file/by-type/by-global pages;
  - current generated C++ headers and marker/definition counts;
  - matching executed and nonterminal agent-local B reports used as leads, with mutable coordination paths classified at evidence time.
- Negative evidence:
  - zero ordinary target callers;
  - exactly one target VA pointer and zero RVA pointer hits;
  - no target branches/guards;
  - zero UID0000UQ result consumers;
  - no counterexample caller with a non-singleton helper receiver;
  - no source reason for raw vtable/SSE/ABI code.
- Confidence limit:
  - no PDB or original header proves exact parameter spelling, public/private placement, or original `GetItemGlyphBounds` lexical spelling;
  - the behavior, ABI, class route, and proposed source are nevertheless fully reconstructable.

## Evidence Checked

- MCP initialization and schemas:
  - fresh `idb_list`;
  - schema-current `tools/list`;
  - `server_health(database="64c11373")`;
  - bounded `lookup_funcs(0x00537bf0)`.
- Target:
  - `lookup_funcs` at target, endpoints, predecessor, and successor;
  - `analyze_function`, `decompile`, `disasm`, `basic_blocks`, `callees`, and `xrefs_to`;
  - `get_bytes` for full target and both padding spans;
  - `make_signature_for_range`, unique true;
  - `find_bytes` for VA `f0 7b 53 00` and RVA `f0 7b 13 00`;
  - `get_int` for target vtable cell and tile globals.
- Output roles:
  - fresh `decompile` of UID0004DS at `0x00506980`;
  - fresh `decompile` of UID0003XX at `0x00537760`;
  - current ObjectPane class/file/layout and SetObjectData support.
- Helper:
  - fresh `decompile` of `0x004df460`;
  - `xrefs_to` returning all 48 calls across 23 functions;
  - bounded `insn_query` for `0x0067a758` in the large cached-receiver callers;
  - bounded `get_bytes` plus local Capstone review for all 48 receiver setups;
  - bounded branch-sensitive review for `0x004c7db6` and the fourteen `0x005a0d28-0x005a13ad` calls;
  - all 48 post-call `EAX` use paths checked, zero result reads.
- Documentation:
  - target, aggregate, class, file, vtable, ignored padding;
  - UID0000UQ, UID00017N, ItemObjImageLib class/layout/file/global;
  - UID00020R, UID0003XX, ObjectPane class/file/Pane layout;
  - UID0004DS and MapPane class/file;
  - MapTilePixelDimensions and exact storage pages;
  - RectGeometryHelpers and RectBounds support.
- Manual coverage final read-only comparison:
  - `by-memory/-coverage-report.md` SHA256 `97AF61EC2E16392FB8F0C6C378CB6FEF7F56AA25CEAFED34F84995F3216EE149`, 1,756,357 bytes / 4,224 lines;
  - `by-class/-coverage-report.md` SHA256 `2C9E9E28D60B6BC28CE81250C431005D3D88E4ECF42B7AF5AD6DDE68584E58ED`, 227,613 bytes / 622 lines;
  - `by-file/-coverage-report.md` SHA256 `ECB8A8CADC0D1083BA03B9091141E65690793057EE90157C3C0713AED2282EE7`, 130,782 bytes / 316 lines;
  - `by-type/by-struct/-coverage-report.md` SHA256 `513FCF6F71A25DC0762769F7CDF5A3265737A36B592B7C1A46AD78A9B84993F7`, 57,351 bytes / 137 lines;
  - `by-global/-coverage-report.md` SHA256 `E1F80490A2DC7FDFD3458E1F8593FF05D2FC8338F56883B762654AF50CC90A35`, 89,268 bytes / 210 lines.
- Callback implementation evidence:
  - scoped validators `13798`, `13800`, `13802`, `13803`, `13805`, `13806`, `13807`, `13809`, `13810`, `13814`, `13815`, `13816`, `13817`, `13818`, and `13819` each returned exit `0`, `ok:1` for one changed ordinary page;
  - initial waited target refresh `13820` and final post-repair waited refresh `13823` returned exit `0`, `ok:1`, and `generated_refresh: completed`;
  - every ordinary edit/validation used one short B005 lease, each released immediately after its validator, and the final lease table is empty;
  - validator side effects were limited to validator-owned UID/reference/autogen registry, projected stats, and generated refresh state. B005 did not manually edit those artifacts.
- Intentionally not run:
  - no IDA mutation, lifecycle command, report move, report archive, or `execute_report`;
  - no broad whole-image MCP text search;
  - no third-party source search because this is ordinary NexusTK class source and no import route applies.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | Target range is exactly `[0x00537bf0,0x00537c65)`, `0x75`/117 bytes. | very strong | lookup/analyze/blocks/bytes | target | incorporate | applied |
| C02 | Target bytes have SHA256 `43F9407A1A5C0C7AE554699CE331899373557B535355EBDEA6DF353B3B98DF5C`. | very strong | full MCP byte read/local hash | target | incorporate | applied |
| C03 | Target is one 117-byte basic block, 48 instructions, complexity 1. | very strong | disasm/basic_blocks/analyze | target | incorporate | applied |
| C04 | Seven predecessor `0xcc` bytes and eleven successor `0xcc` bytes remain ignored alignment. | very strong | get_bytes and current ignored page | target/aggregate/ignored verify-only | already-present | already-present |
| C05 | Target has zero ordinary callers, one data xref at `0x00620440`, one VA pointer hit, and zero RVA hits. | very strong | analyze/xrefs/find_bytes | target/vtable | incorporate | applied |
| C06 | Vtable cell `0x00620440` is ItemObjectPane primary slot `+0x50`. | very strong | vtable base and dword | target/vtable/class | incorporate | applied |
| C07 | Slot `+0x50` is the inherited `ClearOutputRects` contract. | very strong | ObjectPane class/vtables/family declarations | target/class/base helper | incorporate | applied |
| C08 | Target ABI is thiscall with two explicit RectBounds pointers and `retn 8`; source return is void. | very strong | disasm/inherited contract | target | incorporate | applied |
| C09 | `this+0x128` is `short m_itemId`; `m_paletteFlags` is not read. | very strong | target load/current layout | target/class/file | incorporate | applied |
| C10 | First output is `paneBounds`. | very strong | UID0004DS and UID0003XX flow | target/ObjectPane support | incorporate | applied |
| C11 | Second output is `objectDataBounds`, not clip/dirty state. | very strong | UID0003XX -> SetObjectData | target/ObjectPane/MapPane support | incorporate | applied |
| C12 | Target calls item glyph lookup before geometry operations. | very strong | target disasm | target | incorporate | applied |
| C13 | UID0000UQ is a nonvirtual ItemObjImageLib member, not a free helper. | very strong | all 48 receiver setups | helper/class/layout/file/cluster | incorporate | applied |
| C14 | All 48 helper calls across 23 functions supply `g_pItemObjImageLib` in ECX. | very strong | xrefs, bounded bytes, branch-sensitive audit | helper support | incorporate | applied |
| C15 | All 48 helper calls ignore/overwrite EAX before reading it; helper source return is void. | very strong | exhaustive post-call audit | helper | incorporate | applied |
| C16 | UID0000UQ's existing remap/resource/half-tile body remains behaviorally correct. | very strong | helper decompile/current docs | helper | already-present | already-present |
| C17 | First OffsetRect normalizes by `-left,-top`. | very strong | target disasm | target | incorporate | applied |
| C18 | Second OffsetRect uses half tile minus half normalized `right/bottom`. | very strong | target disasm | target | incorporate | applied |
| C19 | Tile dimensions are signed-short globals initialized to 48/48. | very strong | get_int/current global/storage docs | target; globals verify-only | already-present | already-present |
| C20 | Final operation copies pane bounds to object-data bounds. | very strong | movups/final pointer load | target | incorporate | applied |
| C21 | No branch, guard, null test, helper-result test, or alternate order exists. | very strong | one-block CFG/disasm | target | incorporate | applied |
| C22 | Final EAX pointer and movups are compiler lowering, not source return/SIMD code. | very strong | ABI/disasm | target/compiler boundary | incorporate | applied |
| C23 | Target source owner is ItemObjectPane/class UID00006V. | very strong | receiver/field/vtable | target | already-present | already-present |
| C24 | Target source file is UID0000KG `NexusTK/map/ItemObjectPane.cpp`. | very strong | class/file/source order | target/file | already-present | already-present |
| C25 | Historical `BuildCenteredItemRect` is superseded as current source/path/title vocabulary. | very strong | inherited slot/body | target/support/history | historicalize | applied |
| C26 | Target path/title is `ItemObjectPaneClearOutputRects`. | very strong | C25 and rename rules | target/references/manual row | incorporate | applied |
| C27 | Target score is `92/94`; owner/emitter/TRUE/position/Nested remain preserved. | very strong | all blockers closed | target | incorporate | applied |
| C28 | Target Item Summary describes the exact source body without repeating generated metadata. | very strong | by-structure Item Summary rule | target | incorporate | applied |
| C29 | ItemObjectPane class declaration uses `paneBounds`/`objectDataBounds`. | very strong | output-role proof | class Destination 2 | incorporate | applied |
| C30 | ItemObjImageLib layout declaration exposes public member `GetItemGlyphBounds`. | very strong | helper receiver/fanout | layout Destination 3 | incorporate | applied |
| C31 | UID0000UQ metadata is `92/94`, owner/emitter UID00006W, with qualified Destination 4. | very strong | exhaustive helper audit | helper | incorporate | applied |
| C32 | ItemObjImageLib class/file/cluster free-helper claims are superseded without losing resource/remap history. | very strong | current docs vs MCP | class/file/cluster | historicalize | applied |
| C33 | ObjectPane class uses exact pane/object-data parameter names for ClearOutputRects and SetBounds. | very strong | UID0004DS/UID0003XX | ObjectPane Destination 5 | incorporate | applied |
| C34 | UID00020R is `92/94` and emits the exact two-clear body in Destination 6. | very strong | raw body/accepted helper/type/name | UID00020R | incorporate | applied |
| C35 | UID0003XX uses pane/object-data semantics while keeping score/formal metadata unchanged. | very strong | fresh decompile | UID0003XX | incorporate | applied |
| C36 | UID0004DS marks slots `+0x50/+0x2c` resolved while retaining remaining no-code blockers and score. | very strong | fresh decompile/current report | UID0004DS | incorporate | applied |
| C37 | ItemObjectPane aggregate/file/vtable reflect source-ready UID0003HT and the renamed link. | very strong | current union | UID0001D7/UID0000KG/UID00034Y | incorporate | applied |
| C38 | ObjectPane class/file reflect the source-ready base clear helper and exact rectangle contract. | very strong | base/consumer proof | UID00009R/UID0000M5 | incorporate | applied |
| C39 | g_pItemObjImageLib, tile globals, RectGeometryHelpers, MapPane class/file, and ignored padding require read-only verification, not edits. | very strong | current same-or-greater docs | verify-only paths | already-present | already-present |
| C40 | No split, new child, range merge, padding child, new source file, or third-party import applies. | very strong | exact range/source route | target/report | not-applicable | excluded-with-reason |
| C41 | Generated output contains six accepted formal effects with no duplicate class/helper/target source. | very strong | current route and destinations | generated assertions | incorporate | applied |
| C42 | The immutable supervisor-owned manual handoff contains 15 exact no-loss rows/replacements; B005 must not edit coverage. | very strong | read-only five-file comparison | manual handoff | incorporate | applied |
| C43 | No prior direct UID0003HT report exists; prior matches are incidental or helper support. | very strong | exact report search | report/history | incorporate | already-present |
| C44 | Evidence-time MCP session `64c11373` supplied mandatory live evidence; no fallback-only conclusion was used. | very strong | idb_list/health/bounded calls | report/target evidence | incorporate | already-present |
| C45 | The callback used serial one-file leases, scoped validators, one waited generated refresh, and no lifecycle command. | very strong | workflow/goal | callback checklist | incorporate | applied |

Callback verification notes:

| Claim | Destination-specific terminal proof |
| --- | --- |
| Proof C01 | Target path header and evidence section preserve `[0x00537bf0,0x00537c65)` / `0x75`; validator `13798`, final hash `41932B8A...7159`. |
| Proof C02 | Target exact-byte SHA256 is preserved in the implemented target evidence; validator `13798`. |
| Proof C03 | Target one-block/48-instruction/complexity-1 evidence is preserved in the implemented target; validator `13798`. |
| Proof C04 | `by-memory/-ignored.md` hash `C6918322...471` is unchanged and still contains both alignment spans; no edit. |
| Proof C05 | Target and UID00034Y preserve zero ordinary callers, `0x00620440`, VA/RVA evidence; validators `13798`/`13805`. |
| Proof C06 | UID00034Y cell `0x00620440` now names/links ClearOutputRects; validator `13805`. |
| Proof C07 | Target, ItemObjectPane class, ObjectPane class, and UID00020R use the inherited ClearOutputRects contract; validators `13798`, `13800`, `13815`, `13816`. |
| Proof C08 | Destination 1 is void with two `RectBounds *` arguments and no handwritten ABI annotation; generated target definition exactly once at command `13823`. |
| Proof C09 | Target/class/file preserve `m_itemId` at `+0x128` and non-use of `m_paletteFlags`; validators `13798`, `13800`, `13802`. |
| Proof C10 | `paneBounds` is present in Destinations 1, 2, 5, 6 and UID0003XX/UID0004DS prose; relevant validators `13798`, `13800`, `13815`-`13819`. |
| Proof C11 | `objectDataBounds` and SetObjectData fallback replace current clip/dirty claims in target/ObjectPane/MapPane support; validators `13815`-`13819`. |
| Proof C12 | Destination 1 calls GetItemGlyphBounds before both OffsetRect operations; generated ItemObjectPane.cpp confirms order. |
| Proof C13 | UID0000UQ owner/emitter is UID00006W and generated definition is qualified; validators `13806`, `13807`, `13809`, `13810`, `13814`. |
| Proof C14 | Exhaustive 48-call ECX receiver evidence is preserved across UID0000UQ/class/file/cluster pages; validators `13806`, `13809`, `13810`, `13814`. |
| Proof C15 | Void source return and ignored/overwritten EAX audit are preserved; Destination 4 and generated qualified definition return void. |
| Proof C16 | UID0000UQ's remap/resource/tile body remains statement-for-statement equivalent; validator `13806`. |
| Proof C17 | First OffsetRect uses `-left/-top` in Destination 1 and generated source. |
| Proof C18 | Second OffsetRect uses half tile minus normalized `right/bottom` in Destination 1 and generated source. |
| Proof C19 | MapTilePixelDimensions hash `B5177ADF...B120` is unchanged; generated MapPane.cpp still emits signed-short globals initialized to 48. |
| Proof C20 | Destination 1 and generated source end with `*objectDataBounds = *paneBounds;`. |
| Proof C21 | Target evidence and source contain no branch/guard/result test or alternate order; generated source readback confirms. |
| Proof C22 | No `movups`, `xmm`, raw ABI, or return-expression source appears in generated ItemObjectPane.cpp. |
| Proof C23 | UID00006V owner/emitter route is preserved in target metadata and generated class source. |
| Proof C24 | UID0000KG / `NexusTK/map/ItemObjectPane.cpp` route is preserved; file validator `13802`. |
| Proof C25 | Target/class/file/aggregate/vtable label `BuildCenteredItemRect` only as superseded history; current path and generated source contain no old name. |
| Proof C26 | Validator-aware rename completed; old path is absent, new path exists, and validator `13798` propagated current references. |
| Proof C27 | Target is `92/94` with all other metadata preserved; validator `13798`. |
| Proof C28 | Exact accepted Item Summary is installed on the target; validator `13798`. |
| Proof C29 | Destination 2 is byte-for-byte present in ItemObjectPane class and generated declaration; validator `13800`. |
| Proof C30 | Destination 3 declaration is present in ItemObjImageLibLayout and generated class; validator `13807`. |
| Proof C31 | UID0000UQ is `92/94`, owner/emitter UID00006W, with exact Destination 4; validator `13806`. |
| Proof C32 | ItemObjImageLib class/file/cluster preserve full resource/remap history and label the old free-helper conclusion superseded; validators `13809`, `13810`, `13814`. |
| Proof C33 | Destination 5 is present in ObjectPane class and generated declaration; validator `13815`. |
| Proof C34 | UID00020R is `92/94` with exact Destination 6; validator `13816`; generated definition once, target marker zero. |
| Proof C35 | UID0003XX retains `85/90` and blank formal with corrected pane/object-data flow; validator `13818`. |
| Proof C36 | UID0004DS retains `88/90`/blank formal, resolves `+0x50/+0x2c`, and preserves remaining blockers; validator `13819`. |
| Proof C37 | UID0001D7, UID0000KG, and UID00034Y carry the source-ready renamed target without losing current family detail; validators `13803`, `13802`, `13805`. |
| Proof C38 | UID00009R/UID0000M5 carry source-ready base default and semantic contract; validators `13815`, `13817`. |
| Proof C39 | Verify-only hashes remain unchanged: g_pItemObjImageLib `CE6E2DB7...0B43`, MapPane class `A27987F5...CCF0`, MapPane file `97A40EB4...F9B`, MapTile dimensions `B5177ADF...B120`, RectGeometry `94449DAD...0EE`, ignored `C6918322...471`. |
| Proof C40 | Excluded: exact function/range/source route required no split, child, merge, new source/global/type/padding page, import, or IDA mutation. |
| Proof C41 | Command `13823` proves all six formal effects, one target/member/base definition each, zero target markers, no duplicate/unqualified source, and expected UID0004DS marker. |
| Proof C42 | Exact 15-row supervisor-owned handoff below is preserved; B005 made no manual coverage edit. |
| Proof C43 | Old-report search record remains complete and identifies no prior direct target report. |
| Proof C44 | Evidence-time session `64c11373` health and bounded MCP calls remain recorded; callback required no IDA mutation. |
| Proof C45 | Fifteen serial scoped validators, bounded repair passes `13821`/`13822`, and final waited command `13823` completed under short leases; no lifecycle/execute command ran and zero lease remains. |

## Positive Evidence Summary

- The function is exact, ordinary code with one coherent block, two real helper calls, one class field load, two global dimension reads, and one final rectangle copy.
- The sole target pointer is the ItemObjectPane primary vtable cell at `+0x50`.
- The base class already exposes the exact two-output virtual contract.
- MapPane and ObjectPane downstream bodies independently prove the first output becomes pane/render bounds and the second becomes object-data bounds.
- ItemObjectPane's complete class declaration proves `m_itemId` and the source file route.
- RectBounds and tile globals are already source-ready.
- UID0000UQ's class membership is supported by every direct caller, not a sample: 48/48 supply the singleton receiver and 48/48 ignore the machine return.
- The target body maps directly to simple C++03 without raw offsets, decompiler locals, ABI scaffolding, or speculative types.

## IDA MCP Facts

### Function and bytes

- Session: `64c11373`.
- Function: `sub_537BF0`.
- Range: `0x00537bf0-0x00537c65`.
- Size: `0x75` / 117 bytes (Verified with `int_convert.py`).
- Instruction count: 48.
- Basic blocks: 1.
- Cyclomatic complexity: 1.
- Target SHA256: `43F9407A1A5C0C7AE554699CE331899373557B535355EBDEA6DF353B3B98DF5C`.
- Unique wildcarded signature:
  `55 8B EC 0F B7 81 ? ? ? ? 8B 0D ? ? ? ? 56 8B 75 ? 56 50 E8 ? ? ? ? 8B 46 ? F7 D8 50 8B 06 F7 D8 50 56 E8 ? ? ? ? 0F BF 05 ? ? ? ? 99 2B C2 8B C8 8B 46 ? 99 2B C2 D1 F9 D1 F8 2B C8 0F BF 05 ? ? ? ? 99 2B C2 51 8B C8 8B 46 ? 99 2B C2 D1 F9 D1 F8 2B C8 51 56 E8 ? ? ? ? 0F 10 06 8B 45 ? 83 C4 18 0F 11 00 5E 5D C2 08 00`.

Exact bytes:

```text
55 8b ec 0f b7 81 28 01 00 00 8b 0d 58 a7 67 00
56 8b 75 08 56 50 e8 55 78 fa ff 8b 46 04 f7 d8
50 8b 06 f7 d8 50 56 e8 f4 01 f8 ff 0f bf 05 a0
da 66 00 99 2b c2 8b c8 8b 46 0c 99 2b c2 d1
f9 d1 f8 2b c8 0f bf 05 9c da 66 00 99 2b c2
51 8b c8 8b 46 08 99 2b c2 d1 f9 d1 f8 2b c8
51 56 e8 bc 01 f8 ff 0f 10 06 8b 45 0c 83 c4
18 0f 11 00 5e 5d c2 08 00
```

### Boundary and padding

- `[0x00537be9,0x00537bf0)`: seven `cc` bytes, SHA256 `F145ECA66705DE68FF53C6D80E34D8F9A5B535FFA157194AA98BDB68AEA4368D`.
- `[0x00537c65,0x00537c70)`: eleven `cc` bytes, SHA256 `3682C0A62515050101266CC639BF81F5D8C5395F49E7DA93FCC22603018E0943`.
- `0x00537be9` and `0x00537c65` are not function starts.
- Successor `0x00537c70` is separate UID0003HU, size `0x32`.

### Xrefs and virtual route

- `xrefs_to(0x00537bf0)`: exactly one data xref, `0x00620440`.
- VA byte search `f0 7b 53 00`: exactly `0x00620440`.
- RVA byte search `f0 7b 13 00`: zero matches.
- `0x00620440` is ItemObjectPane primary vtable base `0x006203f0` plus `0x50` / 80 (Verified with `int_convert.py`).
- No ordinary direct caller exists.

### Callees and globals

- `0x004df460`: item glyph bounds member candidate, size `0x99`.
- `0x004b7e10`: accepted `OffsetRect(RectBounds *, int dx, int dy)`, size `0x19`.
- `0x0067a758`: source-facing `g_pItemObjImageLib`.
- `0x0066da9c`: signed short `g_mapTilePixelWidth`, value 48.
- `0x0066daa0`: signed short `g_mapTilePixelHeight`, value 48.

### Exact target lowering

- `movzx eax, word ptr [ecx+128h]`: read `m_itemId`.
- `mov ecx, dword_67A758`: load helper receiver.
- First `OffsetRect`: `dx=-left`, `dy=-top`.
- Second `OffsetRect`: `dx=widthGlobal/2-right/2`, `dy=heightGlobal/2-bottom/2`.
- `movups xmm0,[esi]` then `movups [eax],xmm0`: copy first output to second.
- `retn 8`: pop two explicit output pointers.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Recommended status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00537b40-0x005380af` | UID0001D7 ItemAndFlyingObjectPanes | non-emitting split index | false | none | `90/93` | unchanged metadata; add source-ready target row/link |
| `0x00537bc0-0x00537be9` | UID0003HS UpdateItemStatus | prior sibling | true | UID00006V | `92/94` | verify-only |
| `0x00537be9-0x00537bf0` | ignored padding | alignment | false | ignored | `100` | verify-only |
| `0x00537bf0-0x00537c65` | UID0003HT target | ItemObjectPane ClearOutputRects | true | UID00006V | `86/90 -> 92/94` | rename and emit Destination 1 |
| `0x00537c65-0x00537c70` | ignored padding | alignment | false | ignored | `100` | verify-only |
| `0x00537c70-0x00537ca2` | UID0003HU RenderFrame | prior sibling | true | UID00006V | `92/94` | verify-only |
| `0x006203ec-0x00620498` | UID00034Y vtable data | compiler-generated class coverage | true | UID00006V | `90/94` | metadata/formal unchanged; rename slot prose/link |
| `0x004df460-0x004df4f9` | UID0000UQ helper | ItemObjImageLib member | true | UID00006W | `90/92 -> 92/94` | owner/emitter and formal correction |
| `0x00469050-0x0046907a` | UID00020R base default | ObjectPane ClearOutputRects | true | UID00009R | `86/91 -> 92/94` | emit Destination 6 |

## Direct Xref / Caller Inventory

### UID0003HT

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00620440` | sole data xref to target | ItemObjectPane primary vtable slot `+0x50`; virtual reachability |
| `0x004df460` | direct callee | item glyph bounds member after support correction |
| `0x004b7e10` | two direct calls | normalize then center the first rectangle |
| `0x00506980` | indirect virtual consumer | MapPane obtains and separately offsets pane/object-data outputs |
| `0x00537760` | downstream virtual consumer | ObjectPane applies pane bounds and forwards object-data bounds |

### UID0000UQ exhaustive caller groups

| Containing function | Direct call sites |
| --- | --- |
| `0x0041f2b0` | `0x0041f73f` |
| `0x0045b630` | `0x0045bb6d` |
| `0x0045df90` | `0x0045e803` |
| `0x0048b0a0` | `0x0048b10f` |
| `0x0048c040` | `0x0048c0dc` |
| `0x004a2560` | `0x004a287b` |
| `0x004a4570` | `0x004a45fc` |
| `0x004ae1c0` | `0x004ae21a`, `0x004ae371` |
| `0x004aec90` | `0x004aed1e`, `0x004aeed2` |
| `0x004c78e0` | `0x004c79ad` |
| `0x004c7bb0` | `0x004c7bfb`, `0x004c7db6` |
| `0x004ea2a0` | `0x004ea40e`, `0x004ea6c1` |
| `0x004ebb20` | `0x004ebd84`, `0x004ec3a8` |
| `0x004ee6f0` | `0x004ee869`, `0x004eebac` |
| `0x0051b3e0` | `0x0051b493`, `0x0051b6ae` |
| `0x0051c6c0` | `0x0051c74e`, `0x0051c8e9` |
| `0x0051f840` | `0x0051f8e6` |
| `0x005205c0` | `0x0052077a` |
| `0x00537bf0` | `0x00537c06` |
| `0x00537d80` | `0x00537e68` |
| `0x00567480` | `0x0056760a` |
| `0x00570fc0` | `0x0057123c`, `0x005712e4`, `0x00571390`, `0x00571436`, `0x005714dc` |
| `0x005a0640` | `0x005a0d28`, `0x005a0da3`, `0x005a0e24`, `0x005a0e9f`, `0x005a0f1a`, `0x005a0f95`, `0x005a1016`, `0x005a109d`, `0x005a111e`, `0x005a119f`, `0x005a1226`, `0x005a12a7`, `0x005a1328`, `0x005a13ad` |

All 48 pass the singleton as the hidden receiver; zero consume EAX.

## Documentation Evidence And IDA Status

- The target page now carries the complete bytes/hash/CFG, output roles, member-helper correction, source/compiler boundary, formal body, and accepted `92/94` metadata.
- ItemObjectPane class/file pages preserve the complete layout, source order, virtual names, fields, pools, destructor/scalar/vtable separation, and generated source root while integrating UID0003HT without structural rewrite.
- UID00034Y preserves its cell address and generated-binary disposition while the `0x00620440` source slot now names and links `ClearOutputRects`.
- UID0000UQ preserves its exact remap/resource/tile body and now has the correct class owner/emitter, public member declaration, and qualified definition.
- ItemObjImageLib class/file/local-cluster pages preserve resource/remap/draw/destructor history and label the former free-helper conclusion superseded. The layout page remains the sole declaration emitter.
- ObjectPane remains complete at `92/94`; its formal differs only in the accepted semantic parameter names. UID00020R is now source-ready at `92/94`; UID0003XX retains its metadata/blank formal under the narrower inherited-field-expression blocker.
- UID0004DS now resolves slots `+0x50/+0x2c`; remaining movement/MapPane virtual/field blockers continue to justify blank C++.
- Callback generated state at final command `13823`:
  - ItemObjectPane.cpp: one target definition, zero target empty markers;
  - ItemObjImageLib.cpp: one class declaration, one qualified UID0000UQ definition, zero unqualified definitions and zero target markers;
  - ObjectPane.cpp: one UID00020R definition and zero UID00020R markers;
  - MapPane.cpp: one expected UID0004DS empty marker and no invented body.

## Ranked Ownership Analysis

### 1. ItemObjectPane class UID00006V

- Evidence for:
  - target receiver accesses ItemObjectPane field `+0x128`;
  - sole target pointer is ItemObjectPane primary vtable slot `+0x50`;
  - inherited virtual contract is declared on ItemObjectPane;
  - source order is constructor, destructor, status update, target, RenderFrame;
  - file route is already complete and generated.
- Evidence against:
  - body delegates glyph lookup and geometry to external dependencies.
- Decision: accepted direct semantic owner/emitter.

### 2. MapPane

- Evidence for:
  - MapPane is the high-fanout virtual caller and applies screen-space offsets.
- Evidence against:
  - target receiver is not MapPane;
  - target reads no MapPane field;
  - target's vtable and source order are ItemObjectPane-specific.
- Decision: caller/consumer only.

### 3. ItemObjImageLib

- Evidence for:
  - target calls its glyph-bounds member and reads the singleton.
- Evidence against:
  - it owns only the item-image dependency;
  - it does not own ItemObjectPane vtable/layout or the two-output virtual contract.
- Decision: dependency owner only.

### 4. RectBounds module

- Evidence for:
  - target uses `OffsetRect` and RectBounds fields.
- Evidence against:
  - helper module is generic geometry and has no target receiver/vtable/source role.
- Decision: dependency only.

### 5. No-owner, compiler-generated, inline-only, or merged aggregate

- Evidence for:
  - no ordinary direct caller and incidental EAX return.
- Evidence against:
  - direct vtable route, ordinary function body, class field access, two real calls, exact source contract, and simple source-ready implementation.
- Decision: rejected.

### Helper ownership subdecision

- Best candidate: ItemObjImageLib class UID00006W.
- Rejected former candidate: file-level free helper UID0000KH.
- Decisive evidence: 48/48 callers supply the singleton in ECX; no counterexample; nonstatic thiscall with unused `this` explains `retn 8` and Hex-Rays' standalone presentation.
- Source file remains UID0000KH `NexusTK/render/ItemObjImageLib.cpp`; only the narrow semantic owner/emitter changes from file to class.

## Source Placement

- Target placement: `ItemObjectPane::ClearOutputRects` in `NexusTK/map/ItemObjectPane.cpp`.
- Declaration placement: ItemObjectPane class declaration/header route already emitted by UID00006V.
- Helper placement: `ItemObjImageLib::GetItemGlyphBounds` declaration in the UID0001UU ItemObjImageLib layout/class block and definition in `NexusTK/render/ItemObjImageLib.cpp`.
- Base placement: `ObjectPane::ClearOutputRects` in `NexusTK/map/ObjectPane.cpp`.
- MapPane remains the caller/consumer source for screen-position application.
- Tile globals remain declared through MapTilePixelDimensions under MapPane.cpp.
- RectBounds geometry remains under RectBounds.cpp.
- No new `.cpp`, `.h`, helper module, global owner, or third-party import is justified.

## Range / Split / Padding / Reclassification Analysis

- Target range is exact and requires no split or merge.
- Predecessor code UID0003HS ends at `0x00537be9`; seven ignored bytes end exactly at target start.
- Target ends at `0x00537c65`; eleven ignored bytes end exactly at UID0003HU start.
- Parent UID0001D7 remains a non-emitting false split index with `Nested:0`; target remains one direct class-owned child with `Nested:0`.
- Rename is semantic only and preserves UID/range.
- UID0000UQ range remains exact `[0x004df460,0x004df4f9)`; its reclassification is free-function to class member, not a range change.
- UID00020R range remains exact `[0x00469050,0x0046907a)`; its change is source readiness, not a split.
- No padding row, child UID, parent nesting change, raw-helper merge, or compiler/no-source reclassification applies.

## Negative Evidence Summary

- No direct target caller exists; this is expected virtual dispatch, not dead code.
- No target VA pointer exists outside `0x00620440`, and no RVA pointer was found.
- No branch exists, so no conditional source behavior is defensible.
- No target call checks the item-image singleton or helper result.
- No target access uses `m_paletteFlags`, a local status record, MapPane fields, or FlyingObjectPane-only fields.
- No target code computes width as `right-left` or height as `bottom-top` after normalization.
- No helper caller omits the singleton receiver.
- No helper caller consumes the machine return.
- No evidence supports a static member, UI-owner method, free helper, raw-offset accessor, or decompiler-style wrapper for UID0000UQ.
- No evidence supports handwritten vtable arrays, `movups` intrinsics, explicit EAX returns, stack cleanup, hidden `this`, or raw addresses in source.
- No evidence supports changing MapTilePixelDimensions, RectGeometryHelpers, g_pItemObjImageLib storage, ignored padding, MapPane class/file, or unrelated ItemObjectPane/FlyingObjectPane methods.

## IDA Rename / Type / Comment Recommendations

- Source-facing target rename:
  - `sub_537BF0` / historical `BuildCenteredItemRect` -> `ItemObjectPane::ClearOutputRects`.
- Source-facing target parameters:
  - `paneBounds`;
  - `objectDataBounds`.
- Source-facing helper:
  - `sub_4DF460` -> `ItemObjImageLib::GetItemGlyphBounds`;
  - `outBounds` output parameter.
- Existing accepted names to retain:
  - `g_pItemObjImageLib`;
  - `g_mapTilePixelWidth`;
  - `g_mapTilePixelHeight`;
  - `OffsetRect`;
  - `RectBounds::{left,top,right,bottom}`;
  - `m_itemId`.
- Historical/search aliases to retain only in prose:
  - `ItemObjectPaneBuildCenteredItemRect`;
  - `BuildCenteredItemRect`;
  - free `GetItemGlyphBounds`;
  - `__stdcall` helper;
  - `firstBounds` / `secondBounds`;
  - `clipBounds` / `clipOrNull`.
- IDA database changes are not requested and were not performed. These are documentation/source recommendations only.

## First-Draft C++ Recommendation

The six accepted destination-specific managed blocks below were applied exactly. They remain the only B005 C++ changes in this callback.

### Destination 1: `by-memory/0x00537bf0-0x00537c65.ItemObjectPaneClearOutputRects.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ItemObjectPane::ClearOutputRects(
    RectBounds *paneBounds,
    RectBounds *objectDataBounds)
{
    g_pItemObjImageLib->GetItemGlyphBounds(m_itemId, paneBounds);

    OffsetRect(
        paneBounds,
        -paneBounds->left,
        -paneBounds->top);

    OffsetRect(
        paneBounds,
        g_mapTilePixelWidth / 2 - paneBounds->right / 2,
        g_mapTilePixelHeight / 2 - paneBounds->bottom / 2);

    *objectDataBounds = *paneBounds;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 2: `by-class/ItemObjectPane.md`

```text
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
        RectBounds *paneBounds,
        RectBounds *objectDataBounds);
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
```

### Destination 3: `by-type/by-struct/ItemObjImageLibLayout.md`

```text
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
    void GetItemGlyphBounds(short itemId, RectBounds *outBounds);

private:
    friend class MapPane;

    void RefreshItemFrameAvailability();

    ProtectedArray<ItemInfo> m_itemInfos;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 4: `by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ItemObjImageLib::GetItemGlyphBounds(
    short itemId,
    RectBounds *outBounds)
{
    const bool useEpfAssets = g_useEpfAssets;
    int itemImageEntry = static_cast<unsigned short>(itemId + 0x4000);

    if (!useEpfAssets) {
        if (itemImageEntry >= g_currentItemImageRemapFirstEntry &&
            itemImageEntry <= g_currentItemImageRemapLastEntry) {
            itemImageEntry = static_cast<unsigned short>(itemImageEntry + 0xff53);
        } else if (itemImageEntry > g_legacyItemImageMaxEntry) {
            itemImageEntry = g_legacyItemImageMaxEntry;
        }
    }

    g_pEPFLib->GetEntryRect(
        useEpfAssets ? L"ITEM.EPF" : L"ITEM.EPD",
        static_cast<unsigned short>(itemImageEntry),
        outBounds);

    OffsetRect(
        outBounds,
        g_mapTilePixelWidth / 2,
        g_mapTilePixelHeight / 2);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 5: `by-class/ObjectPane.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
enum ObjectPaneType
{
    kObjectPaneTypeItem = 0,
    kObjectPaneTypeFlying = 1,
    kObjectPaneTypePrimaryEffect = 2,
    kObjectPaneTypeLiving = 3,
    kObjectPaneTypeSecondaryEffect = 4,
    kObjectPaneTypeStatic = 5,
    kObjectPaneTypeBalloon = 6,
    kObjectPaneTypeHitBar = 7,
    kObjectPaneTypeDamageNumber = 8,
    kObjectPaneTypeObjectInfo = 9,
    kObjectPaneTypeLighting = 10,
    kObjectPaneTypeSound = 11
};

class MapPane;
class ObjectList;
class SoundObjectPane;
class GrafPort;
struct MapPoint;

class ObjectPane : public Pane
{
    friend class MapPane;
    friend class ObjectList;

public:
    ObjectPane(unsigned char objectType,
               int objectId,
               int mapX,
               int mapY);
    virtual ~ObjectPane() = 0;

    MapPoint *GetMapPosition(MapPoint *outPosition) const;
    unsigned char GetObjectType() const
    {
        return m_objectType;
    }
    int GetObjectId() const
    {
        return m_objectId;
    }
    ObjectPane *GetAttachedObject() const;
    void SetSoundObjectPane(SoundObjectPane *soundObjectPane);
    void ClearSoundObjectPane();

    virtual void UpdateRenderRegion(const RectBounds *bounds);
    virtual void InvalidateRect(const RectBounds *bounds);
    virtual void SetBounds(
        const RectBounds *paneBounds,
        const RectBounds *objectDataBounds);
    virtual void AttachObject(ObjectPane *attachedObject);
    virtual void DetachObject();
    virtual void ClearOutputRects(
        RectBounds *paneBounds,
        RectBounds *objectDataBounds);
    virtual void SetObjectData(const RectBounds *objectData);
    virtual RectBounds *GetObjectData(RectBounds *outObjectData) const;
    virtual void RenderFrame(GrafPort *target,
                             const RectBounds *bounds)
    {
    }
    virtual RectBounds *GetEmptyRect(RectBounds *outBounds) const;
    virtual void DrawSpriteFrame(GrafPort *target,
                                 const RectBounds *bounds)
    {
    }
    virtual void SetMapPosition(int mapX, int mapY);

protected:
    unsigned char m_objectType;
    int m_objectId;
    int m_mapX;
    int m_mapY;
    RectBounds m_objectDataRect;
    ObjectPane *m_attachedObject;
    float m_attachmentHeightOffset;
    SoundObjectPane *m_soundObjectPane;
    unsigned char m_transientObjectFlag;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 6: `by-memory/0x00469050-0x0046907a.ObjectPaneClearOutputRects.md`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ObjectPane::ClearOutputRects(
    RectBounds *paneBounds,
    RectBounds *objectDataBounds)
{
    InitRectBounds(paneBounds, 0, 0, 0, 0);
    InitRectBounds(objectDataBounds, 0, 0, 0, 0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Behavior-preservation rationale:

- Destination 1 mirrors the exact call/order/read/write sequence and omits every absent guard.
- Destination 4 changes only source qualification/ownership and output variable spelling; the accepted body remains behavior-identical.
- Destination 6 mirrors the exact two zero-rectangle helper calls.
- Destinations 2, 3, and 5 are declaration-only, ABI-neutral source-surface corrections.
- No compiler mechanics, raw offsets, decompiler labels, modern library types, exceptions, templates beyond existing declarations, or new runtime behavior are introduced.

## Final Recommendation

- UID0003HT path/title rename, Destination 1, and `92/94` metadata are applied; all other target metadata is preserved.
- Destination 2 is applied to the complete ItemObjectPane class block.
- UID0000UQ is class-owned/emitted by ItemObjImageLib at `92/94`; Destinations 3 and 4 are applied.
- Destinations 5 and 6 are applied; only UID00020R rose to `92/94`, while ObjectPane class/file scores remain unchanged.
- UID0003XX and UID0004DS prose is corrected without adding C++ or changing their scores/routes.
- UID0001D7, UID00034Y, ItemObjectPane class/file, ItemObjImageLib class/file/local cluster, and ObjectPane class/file are synchronized at report-level detail.
- g_pItemObjImageLib, MapTilePixelDimensions, exact width/height storage, RectGeometryHelpers, MapPane class/file, ignored padding, prior siblings, pools, scalar wrappers, and generated output were verified read-only.
- Positive/negative evidence and historical assumptions remain preserved, with old free-helper and BuildCentered paths explicitly superseded.
- No new child, source file, global, type, padding row, or third-party import was created.

## Recommended Target Doc Changes

- Applied rename:
  - from `by-memory/0x00537bf0-0x00537c65.ItemObjectPaneBuildCenteredItemRect.md`;
  - to `by-memory/0x00537bf0-0x00537c65.ItemObjectPaneClearOutputRects.md`.
- Preserved UID `0003HT`, range, owner/emitter `00006V`, reconstructable true, blank optional position, and `Nested:0`.
- Applied score `86/90 -> 92/94`.
- Applied H1/title `0x00537bf0-0x00537c65 ItemObjectPane ClearOutputRects`.
- Applied Destination 1 exactly.
- Exact Item Summary:
  - `Source-ready ItemObjectPane::ClearOutputRects override that obtains m_itemId glyph bounds through g_pItemObjImageLib, normalizes them to origin, centers the glyph in the 48x48 map tile, copies the centered pane bounds to object-data bounds, performs no null/guard/result handling, and returns void despite incidental EAX/output-copy lowering.`
- Added complete evidence-time MCP provenance, bytes/hash/signature/CFG/instruction count, vtable/raw-pointer facts, ABI, output roles, helper member/void contract, globals, geometry math, copy order, no-guard behavior, source/compiler boundary, source placement, scores, rejected alternatives, generated expectation, and historical alias correction.

## Recommended Support Doc Changes

### ItemObjectPane family

- `by-class/ItemObjectPane.md`
  - Destination 2 is applied exactly.
  - A UID0003HT section records the exact body, two output roles, helper member route, tile/geometry behavior, no guards, target hash/range, compiler boundary, and renamed path.
  - `92/94`, owner/emitter/file route, constructor/destructor/status/render/pool/vtable/Flying union are preserved.
- `by-file/ItemObjectPane.md`
  - Exactly one source-ready ClearOutputRects definition/route is integrated in logical order.
  - `91/93`, path, complete ground/flying union, both pools, factory/update routes, compiler exclusions, and unrelated content are preserved.
- `by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md`
  - `90/93`, false/no-owner/no-emitter/blank formal/`Nested:0` are preserved.
  - Item Summary and UID0003HT anchor/link/title/score/body/roles are updated.
- `by-memory/0x006203ec-0x00620498.ItemObjectPaneVtableData.md`
  - `90/94`, owner/emitter, range, marker, RTTI/destructor/adjustor detail are preserved.
  - Only the `0x00620440` current source slot and target link/detail are renamed.

### ItemObjImageLib family

- `by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md`
  - Destination 4 is applied.
  - Score is `90/92 -> 92/94`.
  - Owner/emitter is `0000KH -> 00006W`.
  - True, blank position, `Nested:-4`, range, padding, remap/resource/tile behavior are preserved.
  - Free/stdcall current claims are replaced with member/unused-this evidence, while the former conclusion remains as superseded history.
- `by-type/by-struct/ItemObjImageLibLayout.md`
  - Destination 3 is applied exactly.
  - `89/92`, owner/emitter UID00006W, position 1, friendship, fields, and unrelated declarations are preserved.
- `by-class/ItemObjImageLib.md`
  - `88/89`, route marker, all current class/resource/layout/draw/destructor evidence are preserved.
  - Current free-helper/non-method statements are replaced or explicitly historicalized under the exhaustive member conclusion.
- `by-file/ItemObjImageLib.md`
  - `90/88`, path, source inventory, and no by-file formal are preserved.
  - Free-helper text and generated-output audit now describe one class member declaration/definition route.
- `by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md`
  - `86/90`, false/no-owner/no-emitter/blank formal/`Nested:0` are preserved.
  - UID0000UQ rows, receiver/ABI analysis, score rationale, and historical free-helper text are corrected.
- `by-global/g_pItemObjImageLib.md`
  - Verified only. Current global declaration/storage/lifecycle/consumer evidence is same-or-greater and required no edit.

### ObjectPane and MapPane support

- `by-class/ObjectPane.md`
  - Destination 5 is applied exactly.
  - `92/94`, owner/emitter, position, complete layout/enum/friends/default virtuals/children are preserved.
  - Exact pane/object-data contract and UID00020R source-ready relation are integrated.
- `by-memory/0x00469050-0x0046907a.ObjectPaneClearOutputRects.md`
  - Destination 6 is applied.
  - Score is `86/91 -> 92/94`.
  - Owner/emitter UID00009R, true, blank position, `Nested:0`, exact bytes/vtable/padding/no-caller evidence are preserved.
  - The old name/type blocker is superseded by the accepted source body and retained as history.
- `by-file/ObjectPane.md`
  - `91/92`, path, complete class/source union are preserved.
  - Source-ready base default and exact pane/object-data contract are integrated.
- `by-memory/0x00537760-0x005377f2.ObjectPaneUpdateBounds.md`
  - `85/90`, owner/emitter, true, blank position/formal, `Nested:0` are preserved.
  - Clip/dirty/fallback wording is replaced with exact pane bounds, optional object-data bounds, and direct SetObjectData forwarding.
  - Evidence-time decompile detail and a target-specific no-code disposition are present without claiming this target blocks UID0003HT.
- `by-memory/0x00506980-0x00506ad4.MapPaneUpdateObjectPaneScreenBounds.md`
  - `88/90`, owner/emitter UID00007Q, true, blank position/formal, `Nested:0` are preserved.
  - Slot `+0x50` is resolved as ClearOutputRects and `+0x2c` as SetBounds with pane/object-data outputs.
  - Remaining movement/MapPane virtual/field no-code blockers are retained.
- `by-class/MapPane.md` and `by-file/MapPane.md`
  - Verified only. Current ownership/source route covers UID0004DS and required no edit.

### Verify-only support

- `by-global/MapTilePixelDimensions.md`, UID0001OJ, UID0001OK: exact signed-short 48/48 declarations/storage verified unchanged.
- `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`: exact `OffsetRect` and `InitRectBounds` bodies verified unchanged.
- `by-memory/-ignored.md`: both target padding ranges verified present and unchanged.
- UID0003HQ/HR/HS/HU, UID000385, UID0002WS/WT, UID00034Z, FlyingObjectPane: no target contradiction found; the complete current union, including executed constructor/render sibling work, is preserved.

## Score And Metadata Recommendation

| Page | Historical pre-callback | Applied current | Metadata decision |
| --- | --- | --- | --- |
| UID0003HT target | `86/90` | `92/94` | preserve owner/emitter 00006V, true, blank position, `Nested:0`; rename path/title; populate formal and Item Summary |
| UID0000UQ helper | `90/92` | `92/94` | owner/emitter 0000KH -> 00006W; preserve true, blank position, `Nested:-4`; qualify formal |
| UID00020R base default | `86/91` | `92/94` | preserve owner/emitter 00009R, true, blank position, `Nested:0`; populate formal |
| UID00006V class | `92/94` | `92/94` | parameter names only; full block preserved |
| UID0000KG file | `91/93` | `91/93` | bounded source-route prose |
| UID0001D7 aggregate | `90/93` | `90/93` | false/non-emitting index preserved |
| UID00034Y vtable | `90/94` | `90/94` | slot name/link only |
| UID00006W class | `88/89` | `88/89` | helper member correction without unrelated score inflation |
| UID0001UU layout | `89/92` | `89/92` | declaration addition only |
| UID0000KH file | `90/88` | `90/88` | helper ownership/source-shape correction |
| UID00017N cluster | `86/90` | `86/90` | non-emitting container correction |
| UID00009R class | `92/94` | `92/94` | parameter names/base relation |
| UID0000M5 file | `91/92` | `91/92` | bounded source-route prose |
| UID0003XX | `85/90` | `85/90` | semantic prose correction, formal remains blank |
| UID0004DS | `88/90` | `88/90` | two slots resolved; remaining no-code blockers preserved |

Score-blocker audit:

- target range/hash/CFG: resolved;
- ABI/return: resolved;
- both output roles: resolved;
- helper name/type/owner/return: resolved exhaustively;
- globals/types/helpers: resolved from current source-ready support;
- source placement/owner/emitter: resolved;
- compiler boundary: resolved;
- range/padding/split: resolved;
- formal source: complete;
- remaining lexical uncertainty only limits the target from 95, not from source readiness.

## Open Questions With Attempted Resolution

1. Is the original target spelling definitely `ClearOutputRects`?
   - Checked: base/derived vtable alignment, complete ObjectPane and ItemObjectPane declarations, MapPane virtual call, family method inventory, prior B002 naming work.
   - Resolution: accepted source-facing identity. No PDB proves original capitalization/spelling, which is a lexical confidence cap only.

2. What do the two output rectangles mean?
   - Checked: complete MapPane caller and ObjectPane downstream body.
   - Resolution: pane bounds and object-data bounds. No unresolved role remains.

3. Is UID0000UQ free, static, or nonstatic member?
   - Checked: all 48 call sites, 23 containing functions, branch-sensitive cached-receiver paths, callee ABI/body.
   - Resolution: nonstatic member with optimized-unused `this`. Free/static routes rejected.

4. Does UID0000UQ return a useful value?
   - Checked: all 48 post-call EAX paths.
   - Resolution: no; source void.

5. Should the target use a local rectangle?
   - Checked: register/stack data flow.
   - Resolution: no; first output is the working rectangle.

6. Should center math use width/height differences?
   - Checked: exact loads after normalization.
   - Resolution: no; use normalized right/bottom exactly.

7. Does the target need null/empty/resource failure handling?
   - Checked: complete one-block body and helper call.
   - Resolution: no.

8. Can UID0003XX now emit full C++?
   - Checked: exact body, Pane/GrafPort layout, current class surface.
   - Resolution: its parameter semantics are closed, but a full body would still require a separately accepted expression route for inherited origin/visible-bounds fields. This is not a UID0003HT blocker and this report does not propose decompiler-shaped field access. Score/formal remain unchanged with an exact no-code disposition.

9. Can UID0004DS now emit full C++?
   - Checked: current target report/page and fresh decompile.
   - Resolution: two ObjectPane slots are closed; additional movement fields and MapPane virtuals remain independently unresolved. Keep blank formal with narrowed proof.

No in-scope question is left as "needs investigation."

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The manual rows were read without editing during the report-only evidence pass. The exact handoff below was preserved unchanged through the callback; external coverage application/lifecycle state is validator/supervisor owned.

### `by-memory/-coverage-report.md`

Replace UID00020R at current line 564:

`    - [UID:00020R][0x00469050-0x0046907a.ObjectPaneClearOutputRects](by-memory/0x00469050-0x0046907a.ObjectPaneClearOutputRects.md) 0x00469050-0x0046907a | class virtual method | ObjectPaneClearOutputRects : reconstructable : 92% : very-strong : Source-ready void ObjectPane::ClearOutputRects(RectBounds *paneBounds, RectBounds *objectDataBounds) default that clears both outputs through two exact InitRectBounds(...,0,0,0,0) calls; exact 0x2a-byte body, ObjectPane-family vtable-only reachability, no ordinary callers, void/unused-this ABI, accepted pane/object-data contract, and verified padding are preserved without handwritten vtable or ABI mechanics.`

Replace UID00017N at current line 1765:

`    - [UID:00017N][0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster](by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md) 0x004dec30-0x004df500 | non-emitting class-method split index | ItemObjImageLibLocalMethodCluster : not_reconstructable : 86% : very-strong : Exact non-emitting ItemObjImageLib local constructor/destructor/draw/glyph cluster with complete child ranges, padding, singleton/vtable/layout/resource/remap evidence, source-ready constructor and RefreshItemFrameAvailability children, retained draw options-record no-code proofs, exact raw ordinary/scalar/SEH cleanup separation, and corrected UID0000UQ public member ownership after all 48 call sites supply g_pItemObjImageLib in ECX and ignore the machine result; exact children retain their class/file routes without aggregate duplicate source.`

Insert after the existing ItemObjImageLib internal-alignment row and before UID0002VC:

`        - [UID:0000UQ][0x004df460-0x004df4f9.GetItemGlyphBounds](by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md) 0x004df460-0x004df4f9 | ItemObjImageLib member method | ItemObjImageLibGetItemGlyphBounds : reconstructable : 92% : very-strong : Source-ready void ItemObjImageLib::GetItemGlyphBounds(short itemId, RectBounds *outBounds) with exact 0x99-byte range/padding, ITEM.EPF/ITEM.EPD selection, legacy remap/clamp constants, ResourceLayoutTable lookup, half-tile offset, 48 direct callers across 23 functions, exhaustive g_pItemObjImageLib hidden-receiver proof, zero EAX-result consumers, class owner/emitter UID00006W, and superseded free-stdcall history.`

Insert under UID0001D5 after the existing UID0003XU row and before the ObjectPane-to-StaticObjectPane padding row:

`        - [UID:0003XX][0x00537760-0x005377f2.ObjectPaneUpdateBounds](by-memory/0x00537760-0x005377f2.ObjectPaneUpdateBounds.md) 0x00537760-0x005377f2 | ObjectPane virtual method | ObjectPaneUpdateBounds : reconstructable : 85% : strong : Exact ObjectPane pane/object-data bounds updater: compares current inherited visible bounds with paneBounds, updates pane origin/local visible bounds when changed, then forwards optional objectDataBounds or paneBounds fallback to SetObjectData; historical clip/dirty wording is superseded, while the formal body remains blank for independent inherited-field source-expression reasons.`

Insert under the broad MapPaneInputPacketRenderCore row after its parent row and before the `0x00506cdd-0x00506ce0` padding row:

`        - [UID:0004DS][0x00506980-0x00506ad4.MapPaneUpdateObjectPaneScreenBounds](by-memory/0x00506980-0x00506ad4.MapPaneUpdateObjectPaneScreenBounds.md) 0x00506980-0x00506ad4 | MapPane method | MapPaneUpdateObjectPaneScreenBounds : reconstructable : 88% : strong : Exact live MapPane object screen-bounds updater with 44 code xrefs, tile-origin/movement interpolation and RectBounds operations; ObjectPane slot +0x50 is resolved as ClearOutputRects(paneBounds,objectDataBounds) and slot +0x2c as SetBounds(paneBounds,objectDataBounds), while remaining movement fields and MapPane virtuals preserve its target-specific blank-C++ proof.`

Replace UID0001D7 at current line 2539:

`    - [UID:0001D7][0x00537b40-0x005380af.ItemAndFlyingObjectPanes](by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md) 0x00537b40-0x005380af | non-emitting class-method split index | ItemAndFlyingObjectPanes : not_reconstructable : 90% : very-strong : Exact address-sorted ItemObjectPane/FlyingObjectPane split index with constructor/destructor/status/ClearOutputRects/RenderFrame/flying children and confirmed internal alignment; UID0003HQ emits the constructor, UID0003HR the explicit empty ordinary destructor, UID0003HS UpdateItemStatus, UID0003HT source-ready pane/object-data glyph bounds, and UID0003HU RenderFrame once with Flying inheritance; scalar/vtable/pool lowering remains separate, every exact child retains its direct class/file route, and historical below-gate, LivingObjectPane-adjacency, BuildCenteredItemRect, and aggregate-duplicate-source claims are superseded while all FlyingObjectPane evidence remains preserved.`

Insert within UID0001D7 child indentation after the existing UID0003HR/UID0003HS child rows and before the following aggregate-closing padding:

`        - [UID:0003HT][0x00537bf0-0x00537c65.ItemObjectPaneClearOutputRects](by-memory/0x00537bf0-0x00537c65.ItemObjectPaneClearOutputRects.md) 0x00537bf0-0x00537c65 | ItemObjectPane virtual method | ItemObjectPaneClearOutputRects : reconstructable : 92% : very-strong : Exact source-ready void ItemObjectPane::ClearOutputRects(RectBounds *paneBounds, RectBounds *objectDataBounds): obtains m_itemId glyph bounds through g_pItemObjImageLib, normalizes to origin, centers normalized right/bottom extents in signed-short 48x48 tile dimensions, copies pane bounds to object-data bounds, has one +0x50 vtable pointer and no ordinary callers/branches/guards/result handling, and preserves exact 117-byte hash/padding plus superseded BuildCenteredItemRect history.`

Replace UID00034Y at current line 3805:

`        - [UID:00034Y][0x006203ec-0x00620498.ItemObjectPaneVtableData](by-memory/0x006203ec-0x00620498.ItemObjectPaneVtableData.md) 0x006203ec-0x00620498 | source-declared/generated-binary RTTI/vtable data | ItemObjectPaneVtableData : reconstructable : 90% : very-strong : Exact ItemObjectPane RTTI plus primary/EventHandler/TimerHandler vtable views, constructor/ordinary/scalar/Flying-base vptr-store routes, primary scalar deleting slot, two adjusted deleting thunks, exact Static/Flying boundaries, formal compiler-generated coverage from the complete ItemObjectPane declaration/method source, and primary +0x50 cell 0x00620440 resolved to source-ready UID0003HT ItemObjectPane::ClearOutputRects rather than the historical BuildCenteredItemRect alias.`

### `by-class/-coverage-report.md`

Replace UID00006V:

`- [UID:00006V][ItemObjectPane](by-class/ItemObjectPane.md) : reconstructable : 92% : very-strong : Complete natural 0x12c ObjectPane-derived ground-item declaration with exact objectId/mapX/mapY/itemId/paletteFlags constructor fields and method declarations, m_itemId and m_paletteFlags storage, explicit empty ordinary destructor source, source-ready UpdateItemStatus, source-ready ClearOutputRects(RectBounds *paneBounds, RectBounds *objectDataBounds) obtaining/normalizing/centering item glyph bounds and copying object-data bounds, source-ready RenderFrame, exact primary/EventHandler/TimerHandler vtable family, scalar-deleting/compiler separation, file-static 0x12c/8 pool definition, size guard, MapPane factory and UID0003TT update routes, ItemObjImageLib member dependency, exact child insertion/order and vtable child UID00034Y, destructor-island evidence, ItemObjectPane.cpp ownership, historical LivingObjectPane/BuildCenteredItemRect rejection, and compiler vtable/scalar/pool exclusions.`

Replace UID00006W:

`- [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md) : reconstructable : 88% : strong : Item sprite image-library singleton attached to NexusTK/render/ItemObjImageLib.cpp, with corrected IDA method bounds, layout parent chain, vtable/global anchors, ItemInfo table/resource/draw/reload/destructor support, source-facing lightImageIndex consumer semantics, resource inputs, MapPane friendship through the exact layout declaration, child-owned method bodies, and public nonvirtual GetItemGlyphBounds member ownership proven by all 48 direct callers supplying g_pItemObjImageLib in ECX while ignoring the machine result; historical free-helper/stdcall wording is superseded.`

Replace UID00009R:

`- [UID:00009R][ObjectPane](by-class/ObjectPane.md) : reconstructable : 92% : very-strong : Complete abstract 0x128 ObjectPane declaration over Pane with exact ObjectPaneType constants 0..11, inline public GetObjectType/GetObjectId accessors, ObjectList/MapPane friendship, exact map/bounds/attachment/sound/transient layout, established methods/default virtuals, exact paneBounds/objectDataBounds ClearOutputRects and SetBounds parameter contracts, source-ready base ClearOutputRects default clearing both outputs, implicit padding, and compiler-vtable coverage.`

### `by-file/-coverage-report.md`

Replace UID0000KG:

`- [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md) : reconstructable : 91% : very-strong : NexusTK/map/ItemObjectPane.cpp source root with complete 0x12c ItemObjectPane declaration, exact objectId/mapX/mapY/itemId/paletteFlags constructor fields and route, explicit empty ordinary destructor, source-ready UID0003HS UpdateItemStatus, source-ready UID0003HT ClearOutputRects obtaining m_itemId glyph bounds through the ItemObjImageLib member, normalizing and centering pane bounds in the 48x48 tile then copying object-data bounds, source-ready UID0003HU RenderFrame, exact constructor/status/bounds/render child routes and logical order, class-generated vtable/scalar-wrapper coverage, separate item/flying static pools and exact pool-storage pages, preserved FlyingObjectPane companion union, ground-item MapPane factory and UID0003TT update routes, current ItemAndFlyingObjectPanes evidence, static/item/flying/attached vtable-data links, destructor-island support, historical LivingObjectPane/BuildCenteredItemRect rejection, and compiler vtable/scalar/pool exclusions; no handwritten vptr/delete/pool-wrapper/RTTI duplication and no by-file reconstruction metadata are introduced.`

Replace UID0000KH:

`- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md) : reconstructable : 90% : strong : NexusTK/render/ItemObjImageLib.cpp source root with corrected IDA method bounds, singleton/vtable/layout anchors, ItemInfo table/resource/draw/reload/destructor support, exact lightImageIndex consumer semantics, protected-array layout, MapPane friendship, resource inputs, legacy remapping policy, public nonvirtual GetItemGlyphBounds member declaration/definition proven by exhaustive singleton-receiver callers, destructor/singleton clear, Batch 012 parent-gate evidence, direct vtable-data assignment, documented aliases, child-owned method bodies, and superseded free-helper/stdcall history.`

Replace UID0000M5:

`- [UID:0000M5][ObjectPane](by-file/ObjectPane.md) : reconstructable : 91% : very-strong : NexusTK/map/ObjectPane.cpp and reconstructed ObjectPane.h route for the complete 0x128 declaration, ObjectPaneType enum, ObjectList/MapPane friendship, exact child methods/layout/default virtuals, SoundObjectPane ownership, exact paneBounds/objectDataBounds ClearOutputRects and SetBounds contracts, source-ready base ClearOutputRects default clearing both outputs, downstream SetObjectData object-data flow, and compiler-only vtables without by-file reconstruction metadata.`

### `by-type/by-struct/-coverage-report.md`

Replace UID0001UU:

`- [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md) : reconstructable : 89% : very-strong : Exact ItemObjImageLib/ProtectedArray<ItemInfo> layout with embedded default row, count/entry/default-capacity fields, constructor/reload/destructor agreement, vtable/singleton anchors, fallback-row behavior without treating object +0x14 as a separate top-level field, complete source methods including public nonvirtual GetItemGlyphBounds(short,RectBounds *), MapPane friendship for direct GetAtOrDefault access, exhaustive singleton-receiver proof for the glyph member, and no synthetic runtime accessor.`

### `by-global/-coverage-report.md`

No replacement is required:

- The snapshot UID0000RA row does not classify UID0000UQ as free and remains a correct singleton declaration/storage/lifecycle summary.
- The snapshot UID0000T7 row remains correct for signed-short 48/48 tile dimensions.

Reason B005 must not apply this text directly: every `-coverage-report.md` file is manual supervisor-owned state excluded by the assignment and workflow. A validator-generated refresh does not substitute for these rows.

## Follow-Up Actions

- B005's accepted implementation responsibilities are complete. The immutable callback marker is `READY_FOR_SUPERVISOR_GATE2_REVIEW`.
- Supervisor-owned lifecycle, manual coverage application, Gate 2, execution, archive, revalidation, and tracker state are external to this report and are not asserted as pending, complete, or current here.
- No A-agent action is required by the research result.
- No additional UID0003HT research target is required by this callback. UID0003XX and UID0004DS retain their explicitly bounded independent no-code scopes after the applied semantic corrections.

## Confidence

- Target range/hash/CFG confidence: 99%.
- Virtual identity and owner/emitter confidence: 98%.
- Output-role confidence: 98%.
- Helper member classification confidence: 97%; all direct call sites agree, but no original symbol identifies the member.
- Source body behavior confidence: 98%.
- Exact original lexical spelling/access-level confidence: 88%.
- Applied target score confidence: high.
- Remaining uncertainty is lexical/source-header fidelity only; it does not block behavior, ABI, ownership, formal C++, or callback readiness.

## Validator Results

- All fifteen changed ordinary pages passed a scoped validator while that page alone was leased; each lease was released immediately after the command. UID0000UQ and UID00017N later passed bounded second scoped validators after the final contradiction scan.

| Command | Timestamp | Scoped path | Result / side effects |
| --- | --- | --- | --- |
| `000000013798` | `2026-07-16T11:13:05-04:00` | `by-memory/0x00537bf0-0x00537c65.ItemObjectPaneClearOutputRects.md` | exit `0`, `ok:1`; validator-aware path/reference update completed; pre-existing missing refs UID0003XX/UID0003HV-HY; projected stats updated; generated deferred. |
| `000000013800` | `2026-07-16T11:14:01-04:00` | `by-class/ItemObjectPane.md` | exit `0`, `ok:1`; autogen/reference metadata and projected stats updated; generated deferred. |
| `000000013802` | `2026-07-16T11:14:29-04:00` | `by-file/ItemObjectPane.md` | exit `0`, `ok:1`; pre-existing missing UID0003HV refs; projected stats updated; generated deferred. |
| `000000013803` | `2026-07-16T11:15:04-04:00` | `by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md` | exit `0`, `ok:1`; pre-existing missing UID0003HV-HY refs; projected stats updated; generated deferred. |
| `000000013805` | `2026-07-16T11:15:38-04:00` | `by-memory/0x006203ec-0x00620498.ItemObjectPaneVtableData.md` | exit `0`, `ok:1`; projected stats updated; generated deferred. |
| `000000013806` | `2026-07-16T11:16:57-04:00` | `by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md` | exit `0`, `ok:1`; completion/confidence/owner/autogen metadata updated; pre-existing missing UID0003ZN/UID0003LZ refs; generated deferred. |
| `000000013807` | `2026-07-16T11:17:23-04:00` | `by-type/by-struct/ItemObjImageLibLayout.md` | exit `0`, `ok:1`; autogen/reference metadata and projected stats updated; generated deferred. |
| `000000013809` | `2026-07-16T11:18:16-04:00` | `by-class/ItemObjImageLib.md` | exit `0`, `ok:1`; pre-existing missing UID0003LZ ref; projected stats updated; generated deferred. |
| `000000013810` | `2026-07-16T11:19:15-04:00` | `by-file/ItemObjImageLib.md` | exit `0`, `ok:1`; pre-existing missing UID0003LZ/UID0003ZN refs; projected stats updated; generated deferred. |
| `000000013814` | `2026-07-16T11:21:42-04:00` | `by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md` | exit `0`, `ok:1`; pre-existing missing UID0003LZ/UID0003ZN refs; projected stats updated; generated deferred. |
| `000000013815` | `2026-07-16T11:22:42-04:00` | `by-class/ObjectPane.md` | exit `0`, `ok:1`; class autogen hash/reference metadata updated; pre-existing missing split-child refs; generated deferred. |
| `000000013816` | `2026-07-16T11:23:17-04:00` | `by-memory/0x00469050-0x0046907a.ObjectPaneClearOutputRects.md` | exit `0`, `ok:1`; `86/91 -> 92/94`, blank-to-block autogen update; generated deferred. |
| `000000013817` | `2026-07-16T11:23:49-04:00` | `by-file/ObjectPane.md` | exit `0`, `ok:1`; reference metadata updated; pre-existing missing split-child refs; generated deferred. |
| `000000013818` | `2026-07-16T11:24:19-04:00` | `by-memory/0x00537760-0x005377f2.ObjectPaneUpdateBounds.md` | exit `0`, `ok:1`; validator registered existing UID metadata/references and inserted header blank; pre-existing missing UID0003XW/XY refs; generated deferred. |
| `000000013819` | `2026-07-16T11:24:58-04:00` | `by-memory/0x00506980-0x00506ad4.MapPaneUpdateObjectPaneScreenBounds.md` | exit `0`, `ok:1`; validator normalized two UID link labels; projected stats updated; generated deferred. |
| `000000013820` | `2026-07-16T11:25:27-04:00` | final target `--wait-generated` | exit `0`, `ok:1`; generated refresh completed, registry rebuilt, generated metadata refreshed; pre-existing project-wide autogen missing-marker/no-code warnings remained. |
| `000000013821` | `2026-07-16T11:34:56-04:00` | `by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md` bounded wording repair | exit `0`, `ok:1`; stale current free-helper/decompiler/generated-expectation wording historicalized; pre-existing missing UID0003ZN/UID0003LZ refs; generated deferred. |
| `000000013822` | `2026-07-16T11:35:31-04:00` | `by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md` bounded wording repair | exit `0`, `ok:1`; stale current free-helper sentence replaced by public-member/unused-this truth; pre-existing missing UID0003LZ/UID0003ZN refs; generated deferred. |
| `000000013823` | `2026-07-16T11:35:44-04:00` | final post-repair target `--wait-generated` | exit `0`, `ok:1`; generated refresh completed, registry rebuilt, generated metadata refreshed; pre-existing project-wide autogen missing-marker/no-code warnings remained. |

- Historical report-only checkpoints `13784`/`13791` and initial callback waited checkpoint `13820` remain evidence-time history. Callback command `13823` is the final waited generated checkpoint used for the assertions below.
- No scoped validator failed and no accepted item is blocked. Warnings were pre-existing missing-reference/autogen hygiene findings, not defects introduced by this callback.
- Validator-owned projected stats, registry/reference metadata, and generated files changed as command side effects; B005 did not edit them manually.

## Changed Files

- Callback artifact updated:
  - `tools/leaser/Agents/Agent-B005/research/0003HT-ItemObjectPaneClearOutputRects-source-quality.md`.
- Renamed ordinary path:
  - removed historical `by-memory/0x00537bf0-0x00537c65.ItemObjectPaneBuildCenteredItemRect.md`;
  - current `by-memory/0x00537bf0-0x00537c65.ItemObjectPaneClearOutputRects.md`.
- Fifteen changed ordinary destinations:
  - `by-memory/0x00537bf0-0x00537c65.ItemObjectPaneClearOutputRects.md`;
  - `by-class/ItemObjectPane.md`;
  - `by-file/ItemObjectPane.md`;
  - `by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md`;
  - `by-memory/0x006203ec-0x00620498.ItemObjectPaneVtableData.md`;
  - `by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md`;
  - `by-type/by-struct/ItemObjImageLibLayout.md`;
  - `by-class/ItemObjImageLib.md`;
  - `by-file/ItemObjImageLib.md`;
  - `by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md`;
  - `by-class/ObjectPane.md`;
  - `by-memory/0x00469050-0x0046907a.ObjectPaneClearOutputRects.md`;
  - `by-file/ObjectPane.md`;
  - `by-memory/0x00537760-0x005377f2.ObjectPaneUpdateBounds.md`;
  - `by-memory/0x00506980-0x00506ad4.MapPaneUpdateObjectPaneScreenBounds.md`.
- Verify-only ordinary paths were not changed: g_pItemObjImageLib, MapPane class/file, MapTilePixelDimensions and storage rows, RectGeometryHelpers, ignored padding, prior ItemObjectPane siblings/pools/vtable relatives, and all other excluded support.
- Manual coverage/generated/tracker/audit/supervisor/validator-state files were not manually edited. Generated/projected/registry/reference state changed only through authorized validator side effects.
- IDA database: unchanged.
- Leases: each changed ordinary file was leased alone immediately before edit/validation and released immediately after its scoped validator; UID0000UQ/UID00017N were separately re-leased for bounded repairs, and the target was briefly re-leased for commands `13820` and `13823`; final shared lease table has zero B005 leases.
- Report execution/lifecycle/move/archive: not run.

Historical evidence-time ordinary baselines used for no-loss callback comparison:

| Path | SHA256 |
| --- | --- |
| `by-memory/0x00537bf0-0x00537c65.ItemObjectPaneBuildCenteredItemRect.md` | `8355C6DA543ADCDB5AB1CBE4D2F9686FD6601CF0F60F948508695F47A8F5465D` |
| `by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md` | `6ED1EFDA7ED0767D8EC858B3D6ADABE806E3049E444DCE6805753C6DC00F657B` |
| `by-memory/0x006203ec-0x00620498.ItemObjectPaneVtableData.md` | `5C27527BF462B92E83F8670A435619CD7A159B3E6611F0E6A3B2980E811E1C34` |
| `by-class/ItemObjectPane.md` | `F3EF852F2349E98BF46C91EC83288F1E2368C86F4A1C89BFC13EFDACEB9D3689` |
| `by-file/ItemObjectPane.md` | `902428AC0F416D0F53A454027FD2D51BDCC36BA0ACCBA373E1216AA19CA48F1A` |
| `by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md` | `733B233453104D8E174C73662098B21FC22E0B242CD2C0F66CCD3D7B32CE7CEA` |
| `by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md` | `C514F9BB8E7C0221C6FE8E9124C0BE4D3C08050866E94C503C8725B55037B8F6` |
| `by-class/ItemObjImageLib.md` | `F66BD379F43CEB492A29517E18229E7FE246407B1F89675DE272433D139C0FCF` |
| `by-type/by-struct/ItemObjImageLibLayout.md` | `924DCFFD204AF8E2930B8D7E4D4C4681ADEC75FE0EDAE4435B8D5A6CAFB4796C` |
| `by-file/ItemObjImageLib.md` | `05B1A16C96332A58BF9ABB733C05E1142BD816CA363E83F40BBAC921348CF89A` |
| `by-memory/0x00469050-0x0046907a.ObjectPaneClearOutputRects.md` | `E91A01DD386303ACDA165ADD2D011882395AD892206C4950830A1E1B6A6119A5` |
| `by-class/ObjectPane.md` | `652BC11566A535528D3C6D20ABEBDA37C0ED40408F3863E9891E7E0D32BC4531` |
| `by-file/ObjectPane.md` | `3D9FEAF9464C1B079E75D31989EA6A43C70B250DFABEFC978AF779FC01D1A6B3` |
| `by-memory/0x00537760-0x005377f2.ObjectPaneUpdateBounds.md` | `5928284125112DB67343B9C0A781692604C079BF2C376927107ABB0C93105C0C` |
| `by-memory/0x00506980-0x00506ad4.MapPaneUpdateObjectPaneScreenBounds.md` | `A3758DFD24246F7B917495676B8A6AB60C59A160C570BFD7E0C0F5A309FB0D90` |
| `by-global/g_pItemObjImageLib.md` | `CE6E2DB74A6C65ECE6A99810388B139F88FCF25EDF3F5AF2A21BE085F9690B43` |
| `by-class/MapPane.md` | `A27987F5C31E7C8EE79AB0D397B66EE9C2FAB2BD59F766E0D841D19F8284CCF0` |
| `by-file/MapPane.md` | `97A40EB495BEC5ABA1B0402EDD6C15A5CA369721C5725D47EB1092C50ED48F9B` |
| `by-global/MapTilePixelDimensions.md` | `B5177ADF8AAD50880AE9F737424267DF512F38ED8B63C7C97F192BF541F4B120` |
| `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md` | `94449DADA6F3BF1278A7581214ADAA3026C6D71C62AD494C54B48E132A9A40EE` |
| `by-memory/-ignored.md` | `C69183222989C427BDB3A66F1AC2CC90323167A80E408349953C76B12E3ED471` |

Final changed ordinary hashes:

| Path | SHA256 |
| --- | --- |
| `by-memory/0x00537bf0-0x00537c65.ItemObjectPaneClearOutputRects.md` | `41932B8AE0439D09E7D2267528C7ACF52467E81AAF2BD862856FF53BFEFA7159` |
| `by-class/ItemObjectPane.md` | `F01CE1CE9E2BD0A75EF5062687D07A68727058AE5935E093F98AF47652CE2EF7` |
| `by-file/ItemObjectPane.md` | `334BE8DFD4BA2320E243446EDF14E00C7E0DB90D128A64476B3DD985B25B4C8A` |
| `by-memory/0x00537b40-0x005380af.ItemAndFlyingObjectPanes.md` | `5DD6948BFC9EF6820AD41FA180E9FD7221B17A58AA93E9C761D226120B368978` |
| `by-memory/0x006203ec-0x00620498.ItemObjectPaneVtableData.md` | `8E3D25F5E3EC554A490E39926255E6CD519357F642496D0FF94FAF2F9E0697CD` |
| `by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md` | `07687EE62A3E6BF5A6082ED0C9468EDA2173883D29C07622AE6E8A02DD04812F` |
| `by-type/by-struct/ItemObjImageLibLayout.md` | `EC0191F9A365911686F20A6FE1F8BD33AB1E6DF89D1089BB12755862618E08E8` |
| `by-class/ItemObjImageLib.md` | `A55CF32348F11721627314215D85DEC93DB99B608CB16B100FE16A60F3A7AD1F` |
| `by-file/ItemObjImageLib.md` | `C8029EDCF08BC14514B73FBCAC7628718F5B12885C766E50579BDC7AF49F7C81` |
| `by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md` | `9006DAE70050AAB8C189FD52E9891F052A0788F4E38B78AA7A92F44FA76E61FA` |
| `by-class/ObjectPane.md` | `3D2A9355915A847CED538C6BC3E8322DAB642430DCDC86D0B8CA197D812F3D4E` |
| `by-memory/0x00469050-0x0046907a.ObjectPaneClearOutputRects.md` | `E0527CE62C07E75AE26D287DAC5CA37AD2290B5A23675FB47C1618BD9E8C1F60` |
| `by-file/ObjectPane.md` | `4631FCDED98491D0E55FBB23B8FDDA44CD97CDDBDCB739A1CC477817529869E0` |
| `by-memory/0x00537760-0x005377f2.ObjectPaneUpdateBounds.md` | `8F1D37BA5962EFCA8892E486CDEF59670CF9615DBBAC354FBE0F795F093BDCF2` |
| `by-memory/0x00506980-0x00506ad4.MapPaneUpdateObjectPaneScreenBounds.md` | `D6401881C30586DDA61E5D77CF34763166BBA5F495212B22551341F3CA8E40C0` |

Final generated checkpoint `13823`:

| Generated path | SHA256 | Assertions |
| --- | --- | --- |
| `auto-generated/NexusTK/map/ItemObjectPane.cpp` | `4F414AFA1BBD102D375D142127FE2480AC256F4B977C9B40C0D36ED651BF80AF` | one UID0003HT definition, zero UID0003HT markers, one member glyph call, UID0003HQ/HR/HS/HU once each, zero old-name/raw-ABI/SIMD spellings |
| `auto-generated/NexusTK/render/ItemObjImageLib.cpp` | `5B89682E0F9550BC450609D0389E7C6FDDE8E918DA27FEEC43F6671DA8DCA8A0` | one class declaration, one qualified UID0000UQ definition, zero unqualified definitions, zero UID0000UQ markers |
| `auto-generated/NexusTK/map/ObjectPane.cpp` | `E759763C90CC14DA942A063A4ABCDEE844F8E9348972EB62D539DD6B0444DC28` | semantic declaration names, one UID00020R definition, zero UID00020R markers, zero handwritten ABI/vptr/delete-flag mechanics |
| `auto-generated/NexusTK/map/MapPane.cpp` | `B30F08ADE4A77135B6447B7ADB37F08F7CDD85E6BAF682C5A669C682CE9BA67D` | one expected UID0004DS empty marker, no UID0004DS body; signed-short tile globals remain `48/48` |
| `auto-generated/NexusTK/ui/core/RectBounds.cpp` | `CFC45D14012EE3B3C2805908B34B76142369097E18F16ECFA7F9B593BFB9E48B` | RectBounds layout plus `InitRectBounds` and `OffsetRect` semantics unchanged apart from validator header freshness |

## Implementation Tracking Checklist

Completed B005 report-only and implementation responsibilities:

- [x] Exact-artifact supervisor validation completed before any ordinary edit.
- [x] Re-read current goal, current leases, executed B001 UID0003HU and B004 UID0003HQ archives, and every destination immediately before editing.
- [x] Confirm no current target/support lease conflict; hold only one ordinary-file lease at a time.
- [x] Rename UID0003HT to `by-memory/0x00537bf0-0x00537c65.ItemObjectPaneClearOutputRects.md` while preserving UID/range and allowing validator-managed reference updates.
- [x] Apply UID0003HT `86/90 -> 92/94`, preserve owner/emitter/TRUE/blank-position/`Nested:0`, exact Item Summary, and Destination 1.
- [x] Incorporate target bytes/hash/signature/CFG/instruction count/ABI/vtable/xref/padding/callee/global/output-role/copy/no-guard/compiler-boundary evidence without compression.
- [x] Apply Destination 2 to `by-class/ItemObjectPane.md` while preserving the complete current class union and unrelated/concurrent content.
- [x] Update `by-file/ItemObjectPane.md` with the exact target source route and logical order.
- [x] Update UID0001D7 aggregate Item Summary, target row/link/title/score/detail, and preserve false/no-owner/no-emitter/blank-formal/`Nested:0`.
- [x] Update UID00034Y `0x00620440` slot identity/link/detail while preserving score/metadata/formal marker and all RTTI/destructor/adjustor evidence.
- [x] Apply UID0000UQ `90/92 -> 92/94`, owner/emitter `0000KH -> 00006W`, preserve true/blank-position/`Nested:-4`, exact Item Summary, and Destination 4.
- [x] Apply Destination 3 to `by-type/by-struct/ItemObjImageLibLayout.md` while preserving all current declarations/layout/friendship.
- [x] Update `by-class/ItemObjImageLib.md` with exhaustive member evidence and historicalized free-helper claims.
- [x] Update `by-file/ItemObjImageLib.md` with one class-member declaration/definition route and corrected generated expectation.
- [x] Update UID00017N local cluster rows/receiver/ABI/history while preserving `86/90`, false/no-owner/no-emitter/blank formal/`Nested:0`.
- [x] Verify `by-global/g_pItemObjImageLib.md` remains same-or-greater and make no edit absent a concrete current contradiction.
- [x] Apply Destination 5 to `by-class/ObjectPane.md` while preserving the complete current formal block except accepted parameter names.
- [x] Apply UID00020R `86/91 -> 92/94`, preserve metadata, exact Item Summary, full evidence/history, and Destination 6.
- [x] Update `by-file/ObjectPane.md` with exact pane/object-data contract and source-ready base default.
- [x] Update UID0003XX prose/Item Summary/evidence/no-code proof for pane/object-data semantics without changing score/metadata/formal.
- [x] Update UID0004DS prose/no-code proof so slots `+0x50/+0x2c` are resolved and remaining blockers are exact; preserve score/metadata/formal.
- [x] Verify `by-class/MapPane.md` and `by-file/MapPane.md` remain same-or-greater; do not edit absent a concrete contradiction.
- [x] Verify MapTilePixelDimensions, UID0001OJ, UID0001OK, RectGeometryHelpers, g_pItemObjImageLib, and ignored padding without edits.
- [x] Preserve all UID0003HQ/HR/HS/HU, UID000385, UID0002WS/WT, UID00034Z, FlyingObjectPane, pool, scalar, vtable, padding, historical, and negative evidence.
- [x] Preserve all six managed destination blocks exactly and independently; add no C++ outside formal managed blocks.
- [x] Confirm third-party import is not applicable.
- [x] Confirm no new child UID, split, range change, source file, global, type, padding page, or IDA mutation was introduced.
- [x] Scoped-validate renamed UID0003HT under its one-file lease; record command ID/timestamp/exit/ok/warnings/side effects; release immediately.
- [x] Scoped-validate each other changed ordinary by-* page once under its own short lease and release immediately after each command.
- [x] Work around any concurrent lease instead of overriding, waiting while holding another lease, or dropping accepted content.
- [x] Run one authorized final `--wait-generated` refresh only after all scoped ordinary edits pass.
- [x] Verify generated ItemObjectPane.cpp has the complete class with semantic parameter names, exactly one UID0003HT definition, zero UID0003HT empty markers, one member call to `g_pItemObjImageLib->GetItemGlyphBounds`, and no BuildCentered/raw ABI/SIMD source.
- [x] Verify generated ItemObjImageLib.cpp has one class declaration of GetItemGlyphBounds, one qualified member definition, zero unqualified free definitions, zero UID0000UQ empty markers, and no duplicate class/global/helper source.
- [x] Verify generated ObjectPane.cpp has semantic declaration names, exactly one UID00020R definition, zero UID00020R empty markers, and no handwritten vtable/ABI code.
- [x] Verify generated MapPane.cpp retains UID0004DS as the expected non-emitting empty marker with no new body from prose-only support correction.
- [x] Verify generated MapTilePixelDimensions and RectBounds output remains unchanged except external command/header freshness.
- [x] Record exact changed paths, final hashes, validator records, generated command/header/hashes/counts, side effects, and zero remaining leases in this same report.
- [x] Update every C01-C45 ledger row to a legal callback state with separate destination/validator/generated proof.
- [x] Check every completed checklist item only when true and list any excluded item with exact reason.
- [x] Preserve the exact 15-row supervisor-owned manual coverage handoff text; do not edit manual coverage.
- [x] Do not edit generated, coverage, tracker, audit, supervisor, validator-state, registry, queue, lock, or lifecycle files manually.
- [x] Do not run or probe `execute_report`, any report lifecycle/count/move/archive command, or any IDA mutation.
- [x] Confirm no B005 lease remains before returning the callback artifact.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000013891","destination_path":"executed-b-agent-research/B005/0003HT-ItemObjectPaneClearOutputRects-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0003HT-ItemObjectPaneClearOutputRects-source-quality.md","timestamp":"2026-07-16T11:58:01-04:00","uid":"0003HT"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
