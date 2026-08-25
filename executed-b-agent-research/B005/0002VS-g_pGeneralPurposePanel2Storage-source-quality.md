** TARGET-REPORT-UID:0002VS **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

# UID0002VS g_pGeneralPurposePanel2Storage Ownership / Split Research

## Finalized Report / Current Recommendation

- Current recommendation: applied and verified. Physical storage [UID:0002VS] remains semantically owned by [UID:0000R1] and is now `92/94`, `RECONSTRUCTABLE:FALSE`, with blank emitter/position, blank formal C++, and `Nested:0`. It documents four loader-zeroed bytes, not source-initialized `0xffffffff` data and not a second C++ definition.
- Final disposition: the sole human source definition is on semantic global [UID:0000R1] in [UID:0000JQ] `NexusTK/ui/panels/GeneralPurposePanel.cpp`. [UID:00005R] now directly inherits `LObject` and `Singleton<GeneralPurposePanel2>`, not `PanelPane`; compiler lowering publishes and clears the singleton.
- Completed split: validator-issued [UID:0004UU], [UID:0004UV], [UID:0004UW], [UID:0004UX], [UID:0004UY], and [UID:0004UZ] are the exact constructor, ordinary destructor, child lookup, active-child lookup, active-child refresh dispatch, and scalar deleting destructor pages. Existing UID00015Y remains the source switch, while UID00015Z/UID0003BD remain compiler-only no-code support.
- Source-unit result: B005's waited command `000000015783` produced one GP2 pointer definition, one extern, one complete GP2 class declaration, five newly split source methods plus existing UID00015Y, and no physical-storage, helper-pair, scalar-wrapper, vtable, aggregate, or Empty Emitter Marker body. Later external command `000000015787` preserves the same structure.
- Current lifecycle status: the accepted implementation callback is complete and independently reviewable. B005 changed nineteen ordinary by-* pages through scoped validators and updated this report; manual coverage remained read-only and the generated/tracker changes are validator-owned side effects. B005 did not mutate IDA or run/probe any report execution, move, archive, registry, or lifecycle command.
- Confidence: very strong for bytes, loader state, all 14 references, physical/semantic ownership, direct bases, PMD/EBO/layout, source/compiler split, source route, and one-definition behavior; strong for inferred original method/field spelling.

## Supporting Research

- Required workflow read: canonical B005 `goal.md`, `ntk-b-agent-workflow`, `b-agent-research-and-implementation-workflow.md`, `b-agent-report-template.md`, `score-blocker-audit-standard.md`, and the relevant ownership/emitter/C++/UID rules in `by-structure.md`.
- Current docs read directly: UID0002VS, UID0000R1, UID00005R, UID0000JQ, UID00015V, UID00015Y, UID00015Z, UID0003BD, UID00029L, UID00019K, UID0002QH, UID0003TY, UID0003VB, UID0003UN, UserPane class/file, predecessor/successor storage pages, current generated GeneralPurposePanel.cpp, tracker, and manual coverage.
- Exact old-report search terms used: `0002VS`, `0x0069b358`, `0x0069b35c`, `g_pGeneralPurposePanel2Storage`, `g_pGeneralPurposePanel2`, `GeneralPurposePanel2`, `dword_69B358`, `DAT_0069b358`, `sub_4B8830`, `sub_4B88F0`, `sub_4B8950`, `sub_4B8AA0`, `GeneralPurposePanel`, `Singleton`, `NewSystemMessagePane`, `UserPane`, `MapPane`, and `GeneralPurposePanel.cpp`.
- Search roots checked: central `executed-b-agent-research`, active `tools/leaser/Agents/Agent-B001/research` through `Agent-B005/research`, legacy `tools/leaser/Agents/Older-Research`, and relevant `archived` roots. Direct target/address/storage terms matched only the five reports identified below. Broader family terms produced eleven additional relevant reports; each listed match was opened rather than accepted from a filename hit.

| Matching report opened | Classification and useful fact |
| --- | --- |
| `executed-b-agent-research/B003/00015V-GeneralPurposePanel-source-quality.md` | Incidental/family, executed. Established the mixed source-unit index but left GP2 lifecycle/accessor splits unresolved. |
| `executed-b-agent-research/B002/00029L-StartupClearedUnusedDwords-source-quality.md` | Incidental/adjacent, executed and current. Proves the same `.data` virtual-tail loader-zero mapping and explicitly supersedes old ff-byte observations. |
| `executed-b-agent-research/B002/00028X-g_pGeneralPurposePanel-source-quality.md` | Incidental/sibling, executed. Strong structural comparator for physical/semantic singleton storage, direct Singleton inheritance, EBO, one-definition, and compiler/source separation; it explicitly leaves UID0002VS independent. |
| `executed-b-agent-research/B005/0001PF-FramePartPaneSlots-source-quality.md` | Incidental/predecessor-family, executed. Confirms the exact boundary ending at `0x0069b350`; does not own the target. |
| `executed-b-agent-research/B004/00015Y-GeneralPurposePanel2SwitchActiveChild-empty-emitter-source-quality.md` | Incidental/direct class support, executed. Supplies the accepted switch body, Pane array/index types, nullable activation packet, and one UserPane caller; not a direct UID0002VS audit. |
| `executed-b-agent-research/B001/0003TY-MapPaneHandleMapTransitionPacket-source-quality.md` | Incidental consumer, executed. Confirms the transition read and child-zero NewSystemMessagePane stop route. |
| `executed-b-agent-research/B002/0002AF-g_pMainUiGraph-source-quality.md` | Incidental startup, executed. Confirms MainUiGraph allocates the complete 12-byte GP2 object. |
| `executed-b-agent-research/B003/0000YH-AboveFrame-source-quality.md` | Incidental dependency, executed. FrameChrome refresh behavior does not transfer GP2 ownership. |
| `executed-b-agent-research/B003/0003QZ-SelfLookPane2OnDraw-source-quality.md` | Incidental virtual-contract support, executed. Corroborates Pane activation/refresh contracts only. |
| `executed-b-agent-research/B004/0003UN-UserPaneHandleServerEntryPacket-source-quality.md` | Incidental consumer, executed. Confirms the `0x005aacda` child-zero refresh route. |
| `executed-b-agent-research/B004/0003UT-LivingObjectPaneHandleUIPanelSwitchPacket-source-quality.md` | Incidental panel-switch support, executed. Confirms primary/alternate panel distinction. |
| `executed-b-agent-research/B005/00015X-GeneralPurposePanelSwitchActiveTab-source-quality.md` | Incidental sibling method, executed. Supplies naming/order/Pane-call structural comparison. |
| `executed-b-agent-research/B005/0003RK-UserLookPaneParseLookPacket-source-quality.md` | Incidental virtual-contract support, executed. Does not own the global or class. |
| `executed-b-agent-research/B006/0000YH-AboveFrame-source-quality.md` | Duplicate incidental FrameChrome support, executed; no direct target conclusion imported. |
| `executed-b-agent-research/B009/00025F-FrameGrafPortReadOnlyData-source-routing.md` | Incidental RTTI/vtable evidence, executed but older. Its reconstructable-vtable disposition is superseded by current compiler-generated policy. |
| `executed-b-agent-research/B011/00015W-GeneralPurposePanelChildAccessors-source-quality.md` | Incidental primary-class comparator, executed. Byte/shape identity supports GP2 accessor names without replacing direct target analysis. |

- Search conclusion: no prior direct UID0002VS source-quality report exists in central executed, active B001-B005, legacy executed, or archived roots. Existing reports are corroborating leads only.
- Report-only lease note: the leaser rejects nonexistent paths, so the empty canonical report path was bootstrapped, immediately leased by B005 before substantive content was written, and released immediately after writing. No ordinary lease was acquired.

## Target

- Target UID: `0002VS`.
- Target path: `by-memory/0x0069b358-0x0069b35c.g_pGeneralPurposePanel2Storage.md`.
- Source queue/report row: the time-bounded current tracker at external command `15787` records the implemented UID0002VS metadata at `92/94`, reconstructable false, with this same report still unexecuted and awaiting independent callback review. The original `86/90`, average `88.0`, reconstructable-true row is historical pre-callback state.
- Current supervisor classification: Gate-1-accepted direct source-quality audit followed by the completed same-agent implementation callback for singleton backing storage and its class/source route.
- Current scores and parent state: target `92/94`, canonical owner UID0000R1, reconstructable false, blank emitter/formal/position, `Nested:0`; semantic global `92/94`; class `92/94`; file `92/94`; aggregate `92/94`.

## Current Target State

- UID0002VS now records exact loader-zero PE evidence, all fourteen references, the physical/semantic split, false/non-emitting metadata, and the blank no-code formal. The former active `0xffffffff` statement is retained only as explicitly superseded history.
- UID0000R1 now carries the sole externally linked zero definition at position 20, complete reference/ownership/source-route evidence, and evidence-time qualification of the old saved-name claim.
- UID00005R now has the direct `LObject` plus `Singleton<GeneralPurposePanel2>` declaration, exact twelve-byte layout, complete six-method surface, one external declaration, and `[[CHILDREN]]` after the class closure.
- UID00015V now inventories both complete source families, all child/compiler/padding splits, and remains a false/non-emitting aggregate. UID0003BD is false/non-emitting compiler RTTI/vtable data. UID00015Z remains byte-for-byte false/non-emitting at `92/95`.
- UID00029L's ordinary page now states loader-zero redundant startup clears and retains the prior ff observation only as superseded history. Its stale manual row remains covered by the exact supervisor-owned handoff below.
- Historical generated checkpoint command `000000015738` (SHA256 `2342419A...3F6`, 6,704 bytes/226 lines) recorded the former incomplete `PanelPane` class and two Empty Emitter Markers. It is evidence-time pre-callback provenance, not current authority.
- B005's waited generated checkpoint command `000000015783`, refreshed `2026-07-21T11:43:44-04:00`, has historical callback SHA256 `079791BA831778EB2E9781BFFA4070B6BC195B7C14F924C92743DDEA49D2968D`, 8,102 bytes, and 270 physical lines. External command `000000015787`, refreshed `2026-07-21T11:49:19-04:00`, is the time-bounded current authority with SHA256 `507A011ACC2B2D781D222690E12E91E53645C325960A03C76CEB2AD579A371DD`, the same 8,102 bytes/270 lines, and the same one-definition/source structural assertions.
- Historical tracker commands `000000015743` (SHA256 `C621A837...059B`, 1,537,888 bytes/6,225 lines) and B005 callback `000000015783` (SHA256 `D5FA07D...629A`, 1,540,198/6,233) are evidence-time snapshots. The time-bounded current read at external validator command `000000015787` has SHA256 `F75A7D2E16260165FF52D0AEE6B8C3C5AA887CD343B7D5E1BD41BF36570A7FCC`, 1,540,198 bytes, and 6,233 lines. Later unrelated validator epochs may supersede that mutable snapshot without changing the durable ordinary implementation proof.
- Current callback state: all C01-C40 claims are terminal, all thirteen managed destinations are applied or verified, the exact manual handoff remains supervisor-owned, and every B005 implementation obligation below is checked.

## Executive Recommendation

- Reclassify physical UID0002VS as reviewed false/non-emitting backing storage with semantic owner UID0000R1 and no source body.
- Emit exactly one external pointer definition from UID0000R1 at file position 20, after the complete primary family and before the GP2 class block.
- Replace UID00005R's false `PanelPane` base with direct `LObject` and `Singleton<GeneralPurposePanel2>`, add the complete six-method class surface and extern declaration, and place the class at file position 30.
- The exact source children are registered serially as UID0004UU-UID0004UY for `[0x004b8830,0x004b8994)` source intervals, with false/non-emitting scalar child UID0004UZ at `[0x004b8aa0,0x004b8b32)`.
- Preserve UID00015Y body and score while assigning position 60. Preserve UID00015Z's exact compiler no-code disposition. Convert UID0003BD to false/non-emitting source-declared/generated-binary support.
- Raise UID00015V and UID0000JQ to `92/94` because both panel families then have complete source/compiler/padding/one-definition inventories.
- No source-quality blocker remains. Original spelling uncertainty is reflected in 90-94 confidence rather than raw/decompiler names or deferred bodies.

## Supervisor Active Recheck

- The supervisor assigned UID0002VS specifically to resolve loader-zero versus historical ff state, all 14 references, physical/semantic ownership, Singleton/compiler lowering, source route, human C++/no-code disposition, support scores, and generated one-definition state.
- Split-first repair is required: the broad UID00015V aggregate must not absorb GP2 source methods, compiler wrappers, vtable bytes, or padding into monolithic C++.
- Every source-bearing child directly required by this target now has an exact range, source disposition, score, metadata plan, managed destination block, and serial UID-registration step. No decisive source body is deferred.

## Inference Research Guidance Check

- `by-structure.md` separates canonical semantic ownership from output routing. That rule requires UID0002VS to remain owned by UID0000R1 for documentation while becoming false/non-emitting, and UID0000R1 to carry the sole definition.
- Direct facts are bytes, PE section bounds, xrefs, function bodies, RTTI descriptors, PMDs, allocation size, vtable slots, and padding. Documentation evidence is current by-* and executed reports. Inference is limited to plausible source names, declaration order, and ordinary source spelling.
- Assumptions actively challenged: `0xffffffff` static initialization, `PanelPane` inheritance, explicit source assignment/clear of the singleton, singular child field, inline/no-source treatment for the two unmodeled methods, consumer ownership, and handwritten scalar/vtable/helper mechanics.
- Wave2/Wave3 artifacts were not used. Raw labels, old generated ownership, and unsupported prior initializers were rejected where current evidence contradicted them.

## Heuristic / Inference Reanalysis And Validation

| Issue / blocker | Evidence checked | Resolution |
| --- | --- | --- |
| Loader zero versus `0xffffffff` | PE `.data` virtual/raw sizes, target RVA, live bytes, UID00029L raw mapping | Target is uninitialized static storage zero-filled by the loader. Old ff wording is superseded history. |
| Physical versus semantic ownership | physical page/global page/output markers/one address | UID0002VS documents backing bytes; UID0000R1 owns the sole source definition. |
| Linkage and initializer | nine reads across MapPane/UserPane plus lifecycle writes | External module linkage and zero initializer; reject static/function-local/sentinel forms. |
| Current IDB name | fresh `list_globals`/`get_global_value` and current docs | Current session resolves `0x0069b358`/`dword_69B358` to zero but does not expose `g_pGeneralPurposePanel2` as a saved global name. Source name remains a strong project inference, not a current saved-name fact. |
| Base class | ctor calls, RTTI CHD, three BCD entries, PMDs | Direct `LObject` and `Singleton<GeneralPurposePanel2>` only; reject `PanelPane`. |
| Singleton lowering | ctor adjusted-subobject store/null fallback; dtor/helper/scalar clears | Publication/clear is compiler/template base behavior; do not handwrite global stores. |
| EBO/layout | Singleton PMD `{4,-1,0}`, allocation `0x0c`, fields `+4/+8` | Empty Singleton overlaps `m_childPanes[0]`; exact complete size 12. |
| Constructor body | exact calls/stores/EH and NewSystemMessagePane identity | Human source initializes Singleton/index and allocates one child only. |
| Destructor body | unconditional child call, then implicit clear/base teardown | Human source has one `MarkForDeletion`; no null guard or ABI mechanics. |
| Child accessor | exact 25 bytes, nine calls, upper-bound-only test | Source method returns child zero for any index below one; do not invent a lower-bound check. |
| Unmodeled `0x4b8970` | exact 16 bytes, sibling byte/shape identity, clean padding | Retain source-authored `GetActiveChildPane`; lack of an IDA function model/xrefs is not no-source proof. |
| Unmodeled `0x4b8980` | exact 20 bytes, virtual `+0x20`, sibling identity, clean padding | Retain source-authored `DispatchActiveChildRefresh` calling `InvalidateRect(NULL)`. |
| Switch method | current accepted UID00015Y, sole caller, exact class fields | Preserve body/score; assign source position 60 after accessors. |
| Clear helper pair | two 11-byte functions, unwind-table-only refs, ordinary/scalar parity | Keep UID00015Z false/non-emitting, mixed owner NONE, blank C++. |
| Scalar wrapper | exact 146-byte dtor duplication/delete ABI/vtable slot | New false/non-emitting compiler page; ordinary destructor is sole authored body. |
| Vtable/RTTI | COL/three slots/direct base descriptors/vptr stores | UID0003BD becomes false/non-emitting; source class declaration regenerates binary data. |
| Aggregate/file | exact island, both classes, padding, routed source | UID00015V stays blank false index; UID0000JQ remains sole source root and becomes complete. |
| Consumer ownership | all nine reads, no allocations/stores outside lifecycle | MapPane/UserPane/SystemMessagePanes are consumers/dependencies, not owners. |
| Generated one-definition | pre-callback command 15738 had two empty markers, incomplete class, and missing bodies | Applied formal positions produced one definition/class/source set and zero target/compiler markers at B005 command 15783 and remain intact at external command 15787. |

- Rejected alternatives: initialized `-1` pointer, `dword_69B358`/`DAT_0069b358` source, static or function-local storage, consumer-owned definition, `PanelPane` inheritance, singular `NewSystemMessagePane *` field, explicit global publication/clear, raw vptr/EH/delete-flag code, raw RTTI arrays, monolithic aggregate body, and deleting unmodeled methods merely because IDA does not model them.
- Original identifier spelling is not symbol-proven. The selected names match the accepted primary sibling and existing GP2 class/switch vocabulary; confidence caps reflect that uncertainty without blocking source-ready code.

## Evidence Standards Used

- Mandatory live MCP: direct HTTP JSON-RPC `idb_list`, `server_health`, `tools/list`, `get_bytes`, `lookup_funcs`, `xrefs_to`, bounded function/disassembly/decompile, and RTTI/data queries against session `9b0396a3`.
- Raw executable: PE section map, virtual-tail calculation, exact bytes, SHA256 range hashes, instruction/control-flow inspection, padding, and allocation size.
- Structural: constructor/destructor/scalar stores, RTTI COL/CHD/base descriptors, PMDs, EBO, vtable entries, cross-module readers, and source-order comparison.
- Documentation: current target/global/class/file/aggregate/support pages, exact generated source/tracker/manual rows, and searched executed reports.
- Negative evidence: no raw target initializer, no second source definition, no target startup initializer, no `PanelPane` RTTI/base construction, no ordinary helper callers, no independent scalar source method, and no ownership transfer from consumers.
- This evidence supports `92/94`; missing original PDB/source spelling prevents `95+` source-name confidence.

## Evidence Checked

- Fresh MCP availability: `idb_list` returned active NexusTK session `9b0396a3`; `server_health(database='9b0396a3')` returned status `ok`, auto-analysis ready, Hex-Rays ready, and strings cache ready. A bounded target read returned `00 00 00 00`.
- MCP exact functions: `0x004b8830` size `0xb1`, `0x004b88f0` size `0x54`, `0x004b8950` size `0x19`, `0x004b89a0` size `0xdf`, `0x004b8a80`/`0x004b8a90` size `0xb` each, and `0x004b8aa0` size `0x92`. `0x004b8970`/`0x004b8980` are not IDA-modeled functions, so exact bytes and surrounding boundaries were inspected directly.
- Exact SHA256: target zeros `DF3F6198...1119`; constructor `F807DB74...5CBA`; ordinary destructor `9FE98A30...BAA9`; GetChild `776C2ED1...2512`; GetActive `F4397739...D86`; DispatchRefresh `D5329704...BA0`; switch `3E97C0CF...7D24`; scalar wrapper `BDA7F0D9...CC58`; vtable `82C6C54C...D524`; executable SHA256 `9AEC210B...A632` and MD5 `4247E04E20B65D6414C7238AA8FF5515`.
- PE map: image base `0x00400000`; `.data` VA `0x0066d000`, virtual size `0x2fe24`, raw size `0xd800`, raw-backed end `0x0067a800`; target lies `0x20b58` bytes beyond the raw-backed end but within the virtual section.
- Exact xrefs: predecessor `0x0069b350` has one startup-clear ref; target has 14 refs with `more:false`; successor `0x0069b35c` has 11; `0x0069b360` has seven; `0x0069b364` has 35. The four-byte target boundary is independent.
- Current ordinary docs and hashes listed under Current Target State/Changed Files were reread. Current generated source, tracker, manual coverage, support class/file docs, and all searched old-report matches were opened.
- Negative name check: `list_globals` found GP2 RTTI/vtable names but no `*69B358*` data name, and `get_global_value` resolved `0x0069b358`/`dword_69B358` to zero while returning `g_pGeneralPurposePanel2` as not found. Old saved-name claims are retained as evidence-time history, not asserted as current MCP state.
- Failed/unavailable evidence routes: none. IDA mutation and lifecycle commands were never performed. Scoped validators `15751`-`15782` and the authorized waited refresh `15783` were performed only after exact Gate 1 acceptance; their results are recorded below.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0002VS is exactly `[0x0069b358,0x0069b35c)` and four zero bytes. | 99% | MCP bytes/hash/boundaries | Destination 1; target | incorporate | applied |
| C02 | The target is loader-zeroed `.data` virtual-tail storage with no raw initializer. | 99% | PE virtual/raw mapping | target/global/file | incorporate | applied |
| C03 | Historical `0xffffffff` target wording is false for reconstruction. | 99% | raw mapping/live bytes | target/global/manual history | reject-stale | applied |
| C04 | UID00029L's active summary/manual ff wording is likewise superseded by its own loader-zero proof. | 99% | UID00029L body/raw map | UID00029L bounded support/manual | historicalize | applied |
| C05 | Target predecessor/successor boundaries are exact and exclude all neighbor storage. | 99% | xref families/ranges | target/aggregate | incorporate | applied |
| C06 | The complete target xref count is 14: five compiler/template lifetime writes and nine reads. | 99% | MCP `xrefs_to`, `more:false` | target/global/file | incorporate | applied |
| C07 | UID0002VS is physical backing only and must be false/non-emitting with blank formal. | 99% | one-definition analysis | Destination 1 | incorporate | applied |
| C08 | UID0000R1 is the sole typed source definition with external linkage and zero initializer. | 98% | cross-module reads/lifecycle | Destination 2 | incorporate | applied |
| C09 | The semantic definition belongs at GeneralPurposePanel.cpp position 20. | 97% | source-unit order | global/file/generated plan | incorporate | applied |
| C10 | `g_pGeneralPurposePanel2` is the best source name, but current saved-IDB-name wording must be evidence-time qualified. | 93% | current lookup/docs/convention | target/global rename history | historicalize | applied |
| C11 | GP2 constructor is exact `[0x004b8830,0x004b88e1)`, size `0xb1`, hash `F807...5CBA`. | 99% | function/bytes/CFG | Destination 4/new child | incorporate | applied |
| C12 | Authored constructor source initializes Singleton/index and allocates one NewSystemMessagePane. | 97% | calls/stores/object identity | Destination 4 | incorporate | applied |
| C13 | Constructor publication/null fallback/vptr/EH are compiler lowering, not handwritten source. | 98% | adjusted base/store/EH | ctor/class/global negatives | reject-invalid | applied |
| C14 | GP2 directly inherits LObject and Singleton; PMD +4/EBO and allocation prove 12-byte layout. | 99% | RTTI/PMD/allocation | Destination 3/class | incorporate | applied |
| C15 | Ordinary destructor is exact `[0x004b88f0,0x004b8944)`, hash `9FE9...BAA9`, with one unconditional child deletion request. | 99% | function/bytes/call | Destination 5 | incorporate | applied |
| C16 | Singleton clear and LObject teardown are implicit base destruction, not destructor source lines. | 98% | ordinary/helper/scalar parity | Destination 5/support | reject-invalid | applied |
| C17 | GetChild is exact `[0x004b8950,0x004b8969)`, hash `776C...2512`, upper-bound-only, and source-bearing. | 99% | bytes/nine calls | Destination 6 | incorporate | applied |
| C18 | `[0x004b8970,0x004b8980)` is source-authored GetActiveChildPane. | 97% | exact bytes/sibling parity/padding | Destination 7 | incorporate | applied |
| C19 | `[0x004b8980,0x004b8994)` is source-authored DispatchActiveChildRefresh. | 97% | bytes/virtual slot/sibling parity | Destination 8 | incorporate | applied |
| C20 | Lack of IDA function/xref models for C18/C19 does not justify discarding complete standalone source shapes. | 98% | clean boundaries/primary identity | aggregate/class history | reject-invalid | applied |
| C21 | Existing UID00015Y exact source body/score remains valid and moves to position 60. | 99% | current formal/MCP caller | Destination 9 | already-present | applied |
| C22 | UID00015Z is exactly two compiler Singleton base-destructor instantiations and remains blank false/no-owner. | 99% | two 11-byte bodies/unwind refs | Destination 10 | already-present | already-present |
| C23 | `[0x004b8aa0,0x004b8b32)` is a compiler scalar deleting wrapper, not a second destructor source. | 99% | 146 bytes/vtable/delete flags | Destination 11/new child | incorporate | applied |
| C24 | UID0003BD is compiler RTTI/vtable data regenerated by the class declaration and becomes false/non-emitting. | 99% | COL/slots/vptr refs | Destination 12 | incorporate | applied |
| C25 | UID00015V remains a blank false split/index but becomes complete at `92/94`. | 98% | full child/padding inventory | Destination 13 | incorporate | applied |
| C26 | UID0000JQ remains sole source root and becomes `92/94` with complete primary/alternate order. | 98% | current route/full split | by-file support | incorporate | applied |
| C27 | Nine exact compiler-alignment intervals remain non-source padding. | 99% | raw bytes/function bounds | aggregate/new child prose | incorporate | applied |
| C28 | UID00019K allocates the 12-byte complete GP2 object; compiler base construction publishes the global. | 98% | startup call/allocation | UID00019K support | incorporate | applied |
| C29 | UID0002QH is a null-tested runtime reader that invokes virtual scalar deletion with flag 1; it does not own storage. | 99% | `0x5049ee` branch | UID0002QH support | incorporate | applied |
| C30 | UID0003TY reads child zero and stops NewSystemMessagePane refresh; its current source body is already exact. | 99% | `0x50fef7`/current formal | UID0003TY verify-only | already-present | already-present |
| C31 | UID0003VB first publishes child zero before dispatch and has three further exact message/update read branches. | 98% | refs `5a7711/792e/7ed5/7fb9` | UID0003VB support | incorporate | applied |
| C32 | The `0x005a9130` raw UserPane route reads child zero, emits per-record text with mode 1, and clears pending state. | 95% | bounded raw disassembly/data flow | UserPane class/file support | incorporate | applied |
| C33 | The `0x005aac10` raw UserPane route maps code 1..52 to child-zero system-message text. | 95% | bounded raw disassembly/data flow | UserPane class/file support | incorporate | applied |
| C34 | UID0003UN's `0x005aacda` child-zero RefreshSpelledPane route is already source-ready. | 99% | current formal/callee | UID0003UN verify-only | already-present | already-present |
| C35 | All nine non-lifecycle references are consumers; none publishes, clears, allocates, or owns GP2. | 99% | complete xref roles | target/global/class/file | incorporate | applied |
| C36 | Pre-callback generated command 15738's two empty markers and incomplete class were routing defects, not binary authority. | 99% | command 15738 historical readback | generated assertions/report | incorporate | applied |
| C37 | Current output is one global, one class, six authored method definitions, and zero compiler/physical markers. | 98% | formal route/order/commands 15783 and 15787 | validator/generated proof | incorporate | applied |
| C38 | Manual rows for target/global/class/file/aggregate/children/vtable/predecessor require exact no-loss supervisor updates. | 99% | current manual row comparison | manual handoff | incorporate | excluded-with-reason |
| C39 | Scores move only where exact source closure supports them; consumer/helper scores remain unchanged. | 97% | blocker audit | metadata table | incorporate | applied |
| C40 | Six child UIDs were issued serially before cross-links; no guessed UID reached ordinary docs. | 100% | by-structure UID rule/validator sequence | checklist/callback workflow | incorporate | applied |

Callback verification notes:

| Claims | Exact terminal proof |
| --- | --- |
| C01-C10 | UID0002VS validator `15761`, UID0000R1 `15763`, UID00029L `15769`, UID00015V `15771`, UID0000JQ `15773`; current pages preserve exact loader-zero, 14-ref, one-definition, boundary, no-code, and historical-name/ff facts. |
| C11-C20 | Serial validators assigned UID0004UU `15751`, UID0004UV `15752`, UID0004UW `15754`, UID0004UX `15756`, and UID0004UY `15757`; UID00005R `15764` and UID00015V `15771` carry exact ranges, bodies, bases/layout, compiler exclusions, and source-bearing unmodeled-method dispositions. |
| C21-C27 | UID00015Y validator `15766` applied only position 60 and preserved its formal/body/score; UID00015Z SHA256 `5369DA38BC4CF5F31FE0B96853483BD917C971694AE0B28DA97B1B85751C5693` is unchanged; UID0004UZ `15758`, UID0003BD `15768`, UID00015V `15771`, and UID0000JQ `15773` prove scalar/vtable/aggregate/file/padding separation. |
| C28-C35 | UID00019K `15775`, UID0002QH `15776`, UID0003VB `15779`, UserPane class `15781`, and UserPane file `15782` carry the bounded allocation/teardown/seven-UserPane-read evidence. Verify-only UID0003TY SHA256 `837666ACDEDAE3010877126711499C4F0A5C18DD023D5A26CDFAF5380FBACF43` and UID0003UN SHA256 `ABE9BBB346E300C44EDAFADC851B2807BE3212EE0969EF7F8B56E87E2A0FD326` are unchanged. |
| C36-C37 | B005 final waited command `15783` generated historical callback SHA256 `079791BA831778EB2E9781BFFA4070B6BC195B7C14F924C92743DDEA49D2968D`; external command `15787` current SHA256 `507A011ACC2B2D781D222690E12E91E53645C325960A03C76CEB2AD579A371DD` preserves one definition, one extern, one direct-base class, one each of six authored methods, zero physical/helper/scalar/vtable/aggregate markers, and zero rejected compiler/decompiler spellings. |
| Claim C38 | `excluded-with-reason`: B005 preserved the exact fifteen-action real-UID manual handoff below, but manual `-coverage-report.md` application is supervisor-owned and was not performed. Current manual hashes are recorded unchanged. |
| Claim C39 | Applied score changes are confined to UID0002VS/UID0000R1/UID00005R/UID0003BD/UID00015V/UID0000JQ and the six new pages exactly as accepted; UID00015Y, UID00015Z, UID00029L, and consumers retain their accepted scores/routes. |
| Claim C40 | Validators issued UID0004UU, UID0004UV, UID0004UW, UID0004UX, UID0004UY, and UID0004UZ serially. Each report token was replaced before the next issuance; final search finds zero brace tokens or provisional UID placeholders. |

## Positive Evidence Summary

- Four live zero bytes, PE virtual-tail placement, and no raw payload directly prove loader-zero backing storage.
- All 14 references are enumerated. Five are the exact Singleton/compiler lifetime writes; nine are runtime reads in MapPane/UserPane flows. No hidden remainder exists.
- Constructor/destructor/helper/scalar/vtable evidence forms one consistent direct-Singleton lifecycle. RTTI contains only GP2, LObject, and Singleton<GP2>; PMD +4 plus 12-byte allocation proves EBO and fields.
- The two raw method islands are byte/behavior twins of accepted primary source methods and have compiler padding boundaries. Their missing IDA models are tooling state, not source absence.
- Existing source route, accepted switch, current fields, primary sibling, and generated ordering prove the applied class/global/method source shape coherent and one-definition-safe.

## IDA MCP Facts

- Database: active session `9b0396a3`, module `NexusTK.exe`, image base `0x00400000`, analysis/Hex-Rays/strings ready.
- Target bytes: `00 00 00 00`; exact hash `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`.
- Function facts: ctor `0x4b8830+0xb1`; dtor `0x4b88f0+0x54`; GetChild `0x4b8950+0x19`; switch `0x4b89a0+0xdf`; clear helpers `0x4b8a80+0xb`/`0x4b8a90+0xb`; scalar `0x4b8aa0+0x92`.
- Unmodeled source facts: exact GetActive bytes at `[0x4b8970,0x4b8980)` and Dispatch bytes at `[0x4b8980,0x4b8994)`; lookup reports no function model at either start.
- Data facts: vtable record `[0x61a894,0x61a8a4)` is 16 bytes with COL pointer, scalar slot, and two inherited slots; target is exactly one dword between independent predecessor/successor xref families.
- RTTI facts: class hierarchy has three entries: GP2, LObject, and `Singleton<GeneralPurposePanel2>`; Singleton PMD is `{4,-1,0}`.
- Negative IDA facts: no current saved global named `g_pGeneralPurposePanel2` under `list_globals`/`get_global_value`; no target startup initializer; no second target storage; no ordinary callers to clear helpers; no PanelPane base descriptor.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004b83d0-0x004b8bd3` | UID00015V | Two-class source-unit split/index | false | UID0000JQ | `92/94` | Destination 13 applied; blank complete aggregate. |
| `0x004b8830-0x004b88e1` | UID0004UU | Source constructor | true | UID00005R | `92/94` | Serially registered; Destination 4 applied. |
| `0x004b88f0-0x004b8944` | UID0004UV | Ordinary source destructor | true | UID00005R | `92/94` | Serially registered; Destination 5 applied. |
| `0x004b8950-0x004b8969` | UID0004UW | Source child accessor | true | UID00005R | `92/94` | Serially registered; Destination 6 applied. |
| `0x004b8970-0x004b8980` | UID0004UX | Source active-child accessor | true | UID00005R | `90/92` | Serially registered; Destination 7 applied. |
| `0x004b8980-0x004b8994` | UID0004UY | Source refresh dispatcher | true | UID00005R | `90/92` | Serially registered; Destination 8 applied. |
| `0x004b89a0-0x004b8a7f` | UID00015Y | Source active-child switch | true | UID00005R | `91/93` | Preserve exact body; set position 60. |
| `0x004b8a80-0x004b8a9b` | UID00015Z | Two compiler Singleton base destructors plus padding | false | NONE | `92/95` | Preserve blank no-code disposition. |
| `0x004b8aa0-0x004b8b32` | UID0004UZ | Compiler scalar deleting destructor | false | UID00005R | `93/96` | Serially registered; Destination 11 blank applied. |
| `0x0061a894-0x0061a8a4` | UID0003BD | Compiler RTTI/vtable data | false | UID00005R | `86/93 -> 92/95` | Destination 12 blank. |
| `0x0069b358-0x0069b35c` | UID0002VS | Physical singleton backing | false | UID0000R1 | `86/90 -> 92/94` | Destination 1 blank. |
| semantic global | UID0000R1 | Sole external pointer definition | true | UID0000JQ | `88/89 -> 92/94` | Destination 2. |
| class declaration | UID00005R | Direct LObject/Singleton class | true | UID0000JQ | `90/92 -> 92/94` | Destination 3. |
| source file | UID0000JQ | GeneralPurposePanel.cpp root | n/a | FILE | `90/92 -> 92/94` | Full primary/alternate source union. |

## Direct Xref / Caller Inventory

| Address | Function / route | Exact lifecycle/runtime role |
| --- | --- | --- |
| `0x004b8872` | GP2 constructor | Compiler Singleton-base publication writes complete-object pointer. |
| `0x004b8879` | GP2 constructor | Null-adjustment fallback writes zero. |
| `0x004b8925` | GP2 ordinary destructor | Implicit Singleton-base destruction clears pointer. |
| `0x004b8a80` | UID00015Z helper | Constructor-unwind Singleton base destructor clears pointer. |
| `0x004b8adc` | GP2 scalar wrapper | Inlined implicit Singleton-base destruction clears pointer. |
| `0x005049ee` | UID0002QH MapPane::ExitToMenu | Null-tested read; invokes virtual scalar deletion with flag 1. |
| `0x0050fef7` | UID0003TY map transition | Reads child zero and calls NewSystemMessagePane stop/reset refresh behavior. |
| `0x005a7711` | UID0003VB server dispatcher | One-time pre-dispatch `SwitchActiveChild(0,NULL)` initialization. |
| `0x005a792e` | UID0003VB server dispatcher | Selects child zero and forwards a decoded text/update. |
| `0x005a7ed5` | UID0003VB opcode `0x3a` branch | Selects child zero; dispatches the resolved empty/text operation according to parsed length. |
| `0x005a7fb9` | UID0003VB opcode `0x3f` branch | Same child-zero empty/text operation for its separate packet branch. |
| `0x005a9143` | Raw UserPane source at `0x005a9130` | Sends per-record text from UserPane `+0x13a6f4` with mode 1 and clears pending state. |
| `0x005aac2b` | Raw UserPane source at `0x005aac10` | Maps code 1..52 to per-entry system-message text through child zero. |
| `0x005aacda` | UID0003UN server-entry packet | Reads child zero and calls NewSystemMessagePane RefreshSpelledPane. |

- Count proof: exactly five writes plus nine reads equals the MCP `xref_count:14`; `more:false` proves the inventory is complete.

## Documentation Evidence And IDA Status

- Correct current evidence: UID00015Y's exact body and fields; UID00015Z's compiler no-code proof; UID00029L body/raw map; UID0003TY and UID0003UN exact consumer bodies; primary GP direct-Singleton comparator.
- Pre-callback stale/incomplete evidence comprised UID0002VS/UID0000R1 ff initializer wording, UID00005R `PanelPane` inheritance and missing methods, UID00015V unresolved GP2 split table, UID0003BD reconstructable/emitting classification, UID00029L Item Summary/manual ff wording, and manual class/global/file/target rows. Ordinary defects are now corrected; only the exact supervisor-owned manual rows remain unapplied.
- Generated status at evidence-time command 15738 was primary source complete, GP2 declaration incomplete, UID00015Y present once, two GP2 Empty Emitter Markers, and no GP2 global or lifecycle/accessor methods. That checkpoint is retained as historical pre-callback evidence.
- Generated status at B005 waited command 15783 is the complete one-definition/source callback result; external command 15787 is the time-bounded current header and preserves every accepted assertion. Current tracker status at external command 15787 is validator-owned metadata evidence; it cannot substitute for manual coverage updates, and later unrelated epochs do not invalidate the ordinary changes.
- Current manual snapshots at the pre-finalization read: by-memory SHA256 `9CE3FC30E4044223E32AF350E335749165FCCF3243439E815CE1CF63ED4489C4`; by-global `642D74472052A7151C1FCC41072DF99538DB2F341B7AC3541E8648FDF9671380`; by-class `B25AD1844D78C766EBC8E18E6DE9FB93E786D399117296DE7588D639F06C4E25`; by-file `44613BF3C357A09A0005DAEFF582814184EC77D7C9A8064FFAC0DCC00184C4DE`.

## Ranked Ownership Analysis

### 1. UID0000R1 semantic global under UID0000JQ

- Evidence for: exact physical slot, one pointer meaning, cross-module readers, lifecycle writes, established module, primary sibling convention, and generated route.
- Evidence against: original header/source filename and symbol spelling are stripped.
- Decision: strongest and accepted. UID0000R1 carries the sole definition; UID00005R carries the extern declaration; UID0002VS remains physical documentation only.

### 2. UID00005R class ownership for methods/compiler support

- Evidence for: all source methods use the same 12-byte object layout; RTTI/PMD/vtable/lifecycle are class-specific; existing switch already belongs to UID00005R.
- Evidence against: unmodeled accessors lack original names and xrefs.
- Decision: class is the narrowest true owner. Exact sibling parity and clean boundaries are sufficient for descriptive source names and conservative `90/92` on the two unmodeled methods.

### 3. UID0000JQ direct ownership of the physical slot or compiler artifacts

- Evidence for: all items route to GeneralPurposePanel.cpp.
- Evidence against: file proximity is broader than the semantic global/class owners; physical and compiler pages are not independent source definitions.
- Decision: use UID0000JQ only as final source root. Do not bypass UID0000R1/UID00005R.

### 4. MapPane, UserPane, NewSystemMessagePane, FrameChrome, or PanelPane

- Evidence for: runtime reads or called dependencies.
- Evidence against: no publication/clear/allocation ownership; independent source modules; PanelPane absent from RTTI/base construction.
- Decision: consumers/dependencies only. Reject all as owners.

### Proposed new file/grouping, if applicable

- No new source file. Existing [UID:0000JQ] `NexusTK/ui/panels/GeneralPurposePanel.cpp` is correct.
- Current full contents after the completed callback: existing complete primary GP family, GP2 global/class/six source methods, compiler-only helper/scalar/vtable evidence, and split/index documentation.
- Rejected new grouping: a raw data module, Singleton template-static source file, SystemMessagePanes-owned GP2 shell, or one monolithic aggregate function.

## Source Placement

- Recommended source file: `NexusTK/ui/panels/GeneralPurposePanel.cpp` through UID0000JQ.
- Recommended declaration route: complete GP2 class plus extern declaration in UID00005R's formal class block; sole pointer definition in UID0000R1 before the class block; exact method children inserted through `[[CHILDREN]]`.
- Recommended order: existing primary global/class family, GP2 global position 20, GP2 class position 30, then GP2 child positions 10/20/30/40/50/60 within the class emitter.
- Rejected placements: SystemMessagePanes.cpp owns the concrete child, not its parent shell; UserPane/MapPane are readers; PanelPane has no base relation; raw data/global-only source would duplicate the semantic definition.
- Remaining uncertainty: exact original header split is unavailable, but the current generator's class/global declaration block provides a compile-legal, one-definition-equivalent source route.

## Range / Split / Padding / Reclassification Analysis

- Physical target remains exact `[0x0069b358,0x0069b35c)`. Predecessor UID00029L ends exactly at `0x0069b358`; successor UID0002VR starts exactly at `0x0069b35c`.
- Create six pages in address order: ctor, dtor, GetChild, GetActive, DispatchRefresh, scalar wrapper. Register each with the validator before any ordinary doc references its real UID.
- Preserve existing UID00015Y and UID00015Z page identities. UID00015Z documents function extents through exclusive `0x004b8a9b` in its body/manual row; no new helper page or duplicate C++ is needed.
- Exact compiler padding: `0x004b8823-0x004b8830` (13), `0x004b88e1-0x004b88f0` (15), `0x004b8944-0x004b8950` (12), `0x004b8969-0x004b8970` (7), `0x004b8994-0x004b89a0` (12), `0x004b8a7f-0x004b8a80` (1), `0x004b8a8b-0x004b8a90` (5), `0x004b8a9b-0x004b8aa0` (5), and `0x004b8b32-0x004b8b40` (14). None emits source.
- UID00015V retains exact `[0x004b83d0,0x004b8bd3)` and becomes a complete false/non-emitting address-sorted source-unit index. It must not duplicate child C++.
- UID0003BD retains exact `[0x0061a894,0x0061a8a4)` but changes to false/non-emitting compiler data.

## Negative Evidence Summary

- No target raw initializer exists; `0xffffffff` cannot be reconstructed from the executable image.
- No second singleton storage, AutoInit wrapper, function-local accessor, or independent global source owner was found.
- No PanelPane RTTI descriptor, PanelPane base-constructor call, or room for a PanelPane subobject exists in the 12-byte allocation.
- No ordinary callers use UID00015Z; its two refs are constructor-unwind table support.
- No source caller requires a separately named scalar deleting destructor or raw vtable array.
- No reader performs publication, clearing, or ownership transfer. Consumer count is not owner evidence.
- No-xref/unmodeled status alone was rejected as proof against GetActive/Dispatch source because the exact primary sibling methods and compiler padding establish complete standalone source shapes.
- Raw/decompiler names and explicit ABI mechanics are intentionally excluded from human C++.

## IDA Rename / Type / Comment Recommendations

- Source-facing types/names: `GeneralPurposePanel2 *g_pGeneralPurposePanel2`, direct `Singleton<GeneralPurposePanel2>`, `Pane *m_childPanes[1]`, `int m_activeChildIndex`, `GetChildPaneByIndex`, `GetActiveChildPane`, `DispatchActiveChildRefresh`, and existing `SwitchActiveChild`.
- Descriptive IDA names would be safe in a separate supervisor-authorized curation pass for `0x004b8830`, `0x004b88f0`, `0x004b8950`, `0x004b8970`, `0x004b8980`, and `0x004b8aa0`; this report does not mutate IDA.
- Do not use `dword_69B358`, `DAT_0069b358`, `sub_*`, `ClearGeneralPurposePanel2Singleton`, a raw scalar-wrapper name, or raw vtable-array names in source.
- Current docs' claim that the IDB presently saves `g_pGeneralPurposePanel2` must be qualified as an older evidence-time state because current global-list/value lookups retain only `dword_69B358` at that address.

## First-Draft C++ Recommendation

- Thirteen accepted destination blocks follow. They are the only applied C++/no-code formal changes. All source text remains confined to exact managed-header blocks.
- No third-party import applies.

### Destination 1 - UID0002VS physical storage

```text
*** UID:0002VS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000R1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact loader-zeroed four-byte physical backing storage for g_pGeneralPurposePanel2 with 14 direct refs partitioned into five compiler/Singleton lifetime writes and nine runtime reads, PE virtual-tail proof, exact predecessor/successor boundaries, semantic one-definition route through UID0000R1, historical 0xffffffff claim rejected, and intentional false/non-emitting no-code disposition. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 2 - UID0000R1 semantic global

```text
*** UID:0000R1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class GeneralPurposePanel2;

GeneralPurposePanel2 *g_pGeneralPurposePanel2 = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 3 - UID00005R class declaration

```text
*** UID:00005R | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class GeneralPurposePanel2 : public LObject, public Singleton<GeneralPurposePanel2>
{
public:
    GeneralPurposePanel2();
    virtual ~GeneralPurposePanel2();

    Pane *GetChildPaneByIndex(int index);
    Pane *GetActiveChildPane();
    void DispatchActiveChildRefresh();
    void SwitchActiveChild(
        int childIndex,
        const unsigned char *packetData);

private:
    Pane *m_childPanes[1];
    int m_activeChildIndex;
};

extern GeneralPurposePanel2 *g_pGeneralPurposePanel2;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Destination 4 - new constructor child

```text
*** UID:0004UU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005R | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005R | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
GeneralPurposePanel2::GeneralPurposePanel2()
    : Singleton<GeneralPurposePanel2>(),
      m_activeChildIndex(-1)
{
    m_childPanes[0] = new NewSystemMessagePane;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact source-authored GeneralPurposePanel2 constructor with direct LObject/Singleton hierarchy, 12-byte PMD/EBO layout, compiler-lowered singleton publication/fallback, active index -1, one NewSystemMessagePane allocation/composition, exact bytes/CFG/EH boundaries, and no handwritten vptr/global/EH mechanics. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 5 - new ordinary destructor child

```text
*** UID:0004UV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005R | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005R | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
GeneralPurposePanel2::~GeneralPurposePanel2()
{
    m_childPanes[0]->MarkForDeletion();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact source-authored GeneralPurposePanel2 ordinary destructor with one unconditional child MarkForDeletion request, implicit Singleton clear and LObject teardown, exact bytes/CFG/EH boundaries, scalar-wrapper separation, and no handwritten vptr/base/delete mechanics or invented null guard. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 6 - new child accessor

```text
*** UID:0004UW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005R | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005R | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
Pane *GeneralPurposePanel2::GetChildPaneByIndex(int index)
{
    if (index >= 1)
        return NULL;

    return m_childPanes[index];
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact 25-byte GeneralPurposePanel2 child accessor with one-child upper-bound-only behavior, Pane-array scaled access, nine callers, thiscall/retn-4 ABI, exact hash/padding, and no invented negative-index guard. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 7 - new active-child accessor

```text
*** UID:0004UX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005R | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005R | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:40 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
Pane *GeneralPurposePanel2::GetActiveChildPane()
{
    if (m_activeChildIndex == -1)
        return NULL;

    return m_childPanes[m_activeChildIndex];
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact standalone 16-byte active-child accessor with -1 sentinel, Pane-array scaled access, source-shape parity with the primary panel method, clean alignment boundaries, no current IDA function/xref model, inferred descriptive name, and retained source-bearing disposition. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 8 - new active-child refresh dispatcher

```text
*** UID:0004UY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005R | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005R | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:50 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void GeneralPurposePanel2::DispatchActiveChildRefresh()
{
    if (m_activeChildIndex != -1)
        m_childPanes[m_activeChildIndex]->InvalidateRect(NULL);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact standalone 20-byte active-child refresh dispatcher with -1 sentinel, Pane-array scaled access, Pane::InvalidateRect(NULL) virtual dispatch, primary-method parity, clean alignment boundaries, no current IDA function/xref model, inferred descriptive name, and retained source-bearing disposition. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 9 - existing UID00015Y switch

```text
*** UID:00015Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005R | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005R | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:60 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void GeneralPurposePanel2::SwitchActiveChild(
    int childIndex,
    const unsigned char *packetData)
{
    if (childIndex >= 1)
        return;

    if (g_pTotemFrame != NULL)
        g_pTotemFrame->MarkForDeletion();

    Pane *oldChild = NULL;
    if (m_activeChildIndex != -1)
        oldChild = m_childPanes[m_activeChildIndex];

    m_activeChildIndex = childIndex;

    if (oldChild != NULL) {
        oldChild->Collapse();
        oldChild->UnregisterEventHandler();
    }

    if (m_activeChildIndex != -1) {
        Pane *newChild = m_childPanes[m_activeChildIndex];
        RectBounds bounds;
        bounds.SetLTRB(832, 376, 1021, 641);
        newChild->SetBounds(&bounds, 0);
        newChild->AddToLayer(
            &bounds,
            0,
            g_pBackPane,
            g_mainUiLayerSlots.rootPaneLayerContext);
        newChild->SetPaneOrder(0, g_pBackPane);
        newChild->OnActivate(packetData);
    }

    ReleaseDynamicAboveFrame();
    RecreateDynamicAboveFrame();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact source-authored GeneralPurposePanel2::SwitchActiveChild body with 0xdf-byte boundary, retn-8 ABI, one-child upper-bound/-1 semantics, Pane child array and active index, TotemFrame deletion, Pane Collapse/unregister sequence, exact bounds/layer/activation calls, one-time UserPane caller, and FrameChrome refresh dependencies documented. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 10 - existing UID00015Z compiler helper pair

```text
*** UID:00015Z | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact compiler-emitted Singleton<GeneralPurposePanel2> and Singleton<GeneralPurposePanel> base-destructor instantiations at 0x004b8a80 and 0x004b8a90, each eleven bytes and reached only from its constructor unwind table, with direct RTTI/PMD/EBO identity, mixed semantic class ownership, ordinary/scalar inline parity, intervening padding, and no handwritten clear-helper source. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 11 - new GP2 scalar deleting destructor child

```text
*** UID:0004UZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005R | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact compiler scalar deleting destructor for GeneralPurposePanel2 over 0x004b8aa0-0x004b8b32, duplicating the ordinary child deletion request and implicit Singleton/LObject teardown before delete flags, 12-byte size guard, storage free, and scalar ABI mechanics; the ordinary destructor child is sole handwritten source and this wrapper remains false/non-emitting. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 12 - UID0003BD vtable data

```text
*** UID:0003BD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005R | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact 16-byte GeneralPurposePanel2 RTTI locator and three-slot vtable record with direct LObject/Singleton hierarchy, PMD +4 EBO, constructor/ordinary/scalar vptr stores, exact adjacent boundaries and hash, source-declared/generated-binary disposition, and intentionally blank non-emitting formal C++. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Destination 13 - UID00015V aggregate

```text
*** UID:00015V | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Non-emitting GeneralPurposePanel.cpp split/index with exact 0x004b83d0-0x004b8bd3 bounds, complete primary and alternate panel classes, source constructor/destructor/accessor/switch children, compiler Singleton base destructors/scalar wrappers, exact padding, vtable/source routes, direct Singleton RTTI/PMD/EBO evidence, one-definition globals, dependencies, consumer inventory, and historical alternatives documented without monolithic source duplication. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- Behavior preservation: authored blocks express exactly the object composition, unconditional deletion request, index/sentinel rules, virtual invalidation, and accepted switch behavior. Compiler blocks remain blank where source declarations regenerate the binary artifacts.
- Source-shape preservation: the result uses ordinary direct bases, fields, constructors/destructors/methods, one external global, and no raw address, vptr, EH, scalar flag, or RTTI scaffolding.

## Final Recommendation

- Destinations 1-13 were applied exactly after Gate 1 acceptance and serial issuance of UID0004UU-UID0004UZ.
- Only the six exact new pages listed in the inventory were created. Each issued UID replaced its provisional token throughout the report before the next registration or ordinary cross-link; no provisional token remains.
- Target/global/class/file/aggregate/vtable/predecessor and bounded consumer changes are applied at report-level detail. Primary-family, B002/B004, UserPane, MapPane, and SystemMessagePane facts remain present at same-or-greater detail.
- UID00015Y score/body and UID00015Z score/body remain unchanged; only accepted UID00015Y position/source-unit synchronization was applied.
- UID0003TY/UID0003UN formals, hashes, and all consumer scores/routes remain unchanged and are verified for C30/C34.
- Remaining B005 implementation work: none. Broader source-quality of raw UserPane functions remains independently owned, while their target-specific reader roles are fully documented here. Manual coverage application and report lifecycle remain external supervisor-owned state.

## Recommended Target Doc Changes

- Target: `by-memory/0x0069b358-0x0069b35c.g_pGeneralPurposePanel2Storage.md`.
- Destination 1, exact Item Summary, loader-zero PE proof, complete 14-ref table, physical/semantic split, one-definition route, boundaries, no-code proof, source/compiler distinction, negatives, rejected alternatives, and historical ff correction are applied and scoped-validated by command `15761`.
- Current metadata is exactly `92/94`, owner UID0000R1, false, blank emitter/position/formal, `Nested:0`; UID/path/title/range are preserved.
- The old ff observation is preserved explicitly as superseded provenance, not active behavior.

## Recommended Support Doc Changes

- `by-global/g_pGeneralPurposePanel2.md`: Destination 2 is applied at `92/94`, position 20, with external zero definition, all 14 refs, direct Singleton lifetime, current-name qualification, and one-definition/consumer/history proof; validator `15763`.
- `by-class/GeneralPurposePanel2.md`: Destination 3 is applied at `92/94`, position 30, with direct bases, exact 12-byte layout, six-method inventory, extern, complete child/compiler/vtable/consumer evidence, and rejected PanelPane history; validator `15764`.
- Six new by-memory pages: Destinations 4-8 and 11 are registered as UID0004UU-UID0004UZ and contain the accepted exact bytes/hashes/instructions/CFG/ABI/callers/callees/EH/padding/source or compiler dispositions; serial validators `15751`, `15752`, `15754`, `15756`, `15757`, and `15758`.
- `by-memory/0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild.md`: Destination 9 remains byte-for-byte, position 60 is applied, and `91/93`, owner/emitter/range/Nested/body/history are preserved; validator `15766`.
- `by-memory/0x004b8a80-0x004b8a9a.GeneralPurposePanelSingletonClearHelpers.md`: Destination 10 remains byte-for-byte; add only bounded GP2 split links if needed, preserve score/owner/range/no-code detail.
- `by-memory/0x0061a894-0x0061a8a4.GeneralPurposePanel2VtableData.md`: Destination 12 is applied at `92/95`, false, blank emitter/position/formal, with exact hash/RTTI/PMD/EBO/vptr/compiler proof; validator `15768`.
- `by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md`: Destination 13 is applied at `92/94` with the full real-UID inventory and exact padding/source/compiler/global/consumer/history detail; validator `15771`.
- `by-file/GeneralPurposePanel.md`: current `92/94` prose contains complete GP2 source order, one-definition policy, class/source/compiler split, all 14 refs, dependencies, generated assertions, and historical corrections; no by-file formal block was added; validators `15773` and final waited `15783`.
- `by-memory/0x0069b350-0x0069b358.StartupClearedUnusedDwords.md`: score/owner/emitter/formal/Nested are unchanged; only active Item Summary/current prose now states loader-zero redundant startup clears while old ff evidence is superseded history; validator `15769`.
- UID00019K records the bounded 12-byte allocation and implicit direct-Singleton publication while preserving score/formal/source route; validator `15775`.
- UID0002QH records exact null-tested read and scalar-delete-flag-1 teardown evidence while preserving score/formal/source route; validator `15776`.
- UID0003VB records all four target reads and branch roles without changing its broad blank-formal disposition or score; validator `15779`.
- UserPane class/file now record the full nine-reader partition, including raw `0x005a9130`/`0x005aac10`, with no ownership transfer; their complete concurrent union, scores, fields, and formals are preserved; validators `15781`/`15782`.
- UID0003TY and UID0003UN exact target reads/formals/hashes were verified unchanged; no ordinary edit was required.

## Score And Metadata Recommendation

| Page | Pre-callback | Applied current state | Metadata change / rationale |
| --- | --- | --- | --- |
| UID0002VS | `86/90`, true, owner/emitter UID0000R1 | `92/94`, false, owner UID0000R1, blank emitter/position/formal | Exact storage/loader/xrefs/one-definition/no-code resolved. |
| UID0000R1 | `88/89`, blank position/formal | `92/94`, true, owner/emitter UID0000JQ, position 20 | Exact type/linkage/initializer/source definition resolved. |
| UID00005R | `90/92`, false base declaration | `92/94`, true, position 30 | Direct bases/layout/full declarations/source closure resolved. |
| ctor child | absent | `92/94`, true, owner/emitter UID00005R, position 10 | Exact authored body and compiler separation. |
| dtor child | absent | `92/94`, true, owner/emitter UID00005R, position 20 | Exact authored body and scalar separation. |
| GetChild child | absent | `92/94`, true, owner/emitter UID00005R, position 30 | Exact body/ABI/nine callers. |
| GetActive child | absent | `90/92`, true, owner/emitter UID00005R, position 40 | Exact body/range; descriptive name and no xrefs cap confidence. |
| Dispatch child | absent | `90/92`, true, owner/emitter UID00005R, position 50 | Exact body/range; descriptive name and no xrefs cap confidence. |
| UID00015Y | `91/93`, blank position | unchanged score, position 60 | Existing exact source body; only deterministic order changes. |
| UID00015Z | `92/95`, false/NONE | unchanged | Compiler base-destructor proof already complete. |
| scalar child | absent | `93/96`, false, owner UID00005R | Exact compiler wrapper/no-code proof. |
| UID0003BD | `86/93`, true/emitting | `92/95`, false, owner UID00005R, blank emitter/formal | Exact compiler-generated vtable route. |
| UID00015V | `89/93`, false | `92/94`, false | Both source families and every compiler/padding split become complete. |
| UID0000JQ | `90/92` | `92/94` | Full two-class source unit and one-definition state resolved. |
| UID00029L | `88/91` | unchanged | Only stale active summary/manual polarity is corrected. |
| consumers | current scores/routes | unchanged | Target-specific evidence improves prose, not their broad method completeness. |

- Score-blocker audit: bytes, type, initializer, ownership, direct bases, fields, source placement, exact source children, caller roles, compiler artifacts, padding, generated ordering, and C++ shape were each actively researched and resolved. Only original spelling remains inferential, so no page was raised to 95+ source certainty.

## Open Questions With Attempted Resolution

- Why did old docs report `0xffffffff`? Checked raw section mapping, current bytes, UID00029L history, and startup refs. Resolution: the target has no raw payload and is loader zero; old observations are stale/tool-state history.
- Is the pointer manually assigned in source? Checked ctor adjustment/store sequence, direct Singleton RTTI/PMD, helper/scalar clears, and primary sibling. Resolution: compiler/template base lowering; no explicit source assignment.
- Is GP2 a PanelPane? Checked base descriptors, constructor calls, size, vtable, and PMD. Resolution: no; direct LObject plus Singleton only.
- Are `0x4b8970`/`0x4b8980` padding/inline/no-source? Checked exact bytes, branch/return completeness, primary sibling identities, clean padding, and neighboring functions. Resolution: retained standalone source methods; no-code would discard executable source shape.
- Are source names exact originals? No symbols prove spelling. Existing accepted project vocabulary and byte-identical sibling methods support the chosen descriptive names; this affects confidence only, not C++ eligibility.
- Does any consumer own the global? Complete 14-ref audit shows no consumer publication/clear/allocation. Resolution: no.
- Remaining unresolved questions with score/C++ impact: none. Original spelling uncertainty is already reflected in scores and does not justify raw labels or blank source bodies.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Current manual files were reread after the completed callback and were not edited. The following remains the exact no-loss supervisor-owned fifteen-action handoff with real validator-issued UID0004UU-UID0004UZ values; no brace token or provisional UID remains. Validator-owned generated tracker/coverage is not manually edited.
- Time-bounded manual snapshots reread after external command `15787`: by-memory SHA256 `9CE3FC30E4044223E32AF350E335749165FCCF3243439E815CE1CF63ED4489C4` (1,885,034 bytes/4,437 lines); by-global `642D74472052A7151C1FCC41072DF99538DB2F341B7AC3541E8648FDF9671380` (93,268/214); by-class `B25AD1844D78C766EBC8E18E6DE9FB93E786D399117296DE7588D639F06C4E25` (244,927/623); by-file `44613BF3C357A09A0005DAEFF582814184EC77D7C9A8064FFAC0DCC00184C4DE` (142,768/316). These remain unapplied for the exact target-specific rows below; unrelated later supervisor-owned coverage epochs do not alter the handoff text.

1. In `by-memory/-coverage-report.md`, replace UID00015V row with:

```text
    - [UID:00015V][0x004b83d0-0x004b8bd3.GeneralPurposePanel](by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md) 0x004b83d0-0x004b8bd3 | split/index | GeneralPurposePanel source-unit inventory : ignored : 92% : very-strong : Non-emitting two-class source-unit index with complete primary and alternate panel constructor/destructor/accessor/switch children, compiler Singleton base destructors/scalar wrappers, exact padding, vtable/source routes, direct Singleton RTTI/PMD/EBO evidence, one-definition globals, all 14 alternate-global refs, dependencies, and historical alternatives; exact children carry source.
```

2. Under UID00015V, after UID00015X and in address order, insert the five source children; after UID00015Z insert the scalar child:

```text
        - [UID:0004UU][0x004b8830-0x004b88e1.GeneralPurposePanel2Constructor](by-memory/0x004b8830-0x004b88e1.GeneralPurposePanel2Constructor.md) 0x004b8830-0x004b88e1 | constructor | GeneralPurposePanel2::GeneralPurposePanel2 : reconstructable : 92% : very-strong : Exact direct-LObject/Singleton source constructor with PMD +4 EBO publication, active index -1, one NewSystemMessagePane allocation/store, exact bytes/hash/CFG/EH/padding, and no handwritten singleton/vptr/EH lowering.
        - [UID:0004UV][0x004b88f0-0x004b8944.GeneralPurposePanel2Destructor](by-memory/0x004b88f0-0x004b8944.GeneralPurposePanel2Destructor.md) 0x004b88f0-0x004b8944 | destructor | GeneralPurposePanel2::~GeneralPurposePanel2 : reconstructable : 92% : very-strong : Exact ordinary destructor with one unconditional child MarkForDeletion call, implicit Singleton clear/LObject teardown, exact bytes/hash/CFG/EH/padding, and no handwritten vptr/base/scalar/delete ABI or invented null guard.
        - [UID:0004UW][0x004b8950-0x004b8969.GeneralPurposePanel2GetChildPaneByIndex](by-memory/0x004b8950-0x004b8969.GeneralPurposePanel2GetChildPaneByIndex.md) 0x004b8950-0x004b8969 | method | GeneralPurposePanel2::GetChildPaneByIndex : reconstructable : 92% : very-strong : Exact 25-byte one-child upper-bound-only Pane-array accessor with nine calls, thiscall/retn-4 ABI, exact hash/padding, and no invented lower-bound guard.
        - [UID:0004UX][0x004b8970-0x004b8980.GeneralPurposePanel2GetActiveChildPane](by-memory/0x004b8970-0x004b8980.GeneralPurposePanel2GetActiveChildPane.md) 0x004b8970-0x004b8980 | method | GeneralPurposePanel2::GetActiveChildPane : reconstructable : 90% : strong : Exact standalone 16-byte -1-sentinel active-child accessor with primary-method parity, clean padding boundaries, no current IDA function/xref model, and inferred descriptive source name.
        - [UID:0004UY][0x004b8980-0x004b8994.GeneralPurposePanel2DispatchActiveChildRefresh](by-memory/0x004b8980-0x004b8994.GeneralPurposePanel2DispatchActiveChildRefresh.md) 0x004b8980-0x004b8994 | method | GeneralPurposePanel2::DispatchActiveChildRefresh : reconstructable : 90% : strong : Exact standalone 20-byte -1-sentinel active-child Pane::InvalidateRect(NULL) dispatcher with primary-method parity, clean padding boundaries, no current IDA function/xref model, and inferred descriptive source name.
        - [UID:0004UZ][0x004b8aa0-0x004b8b32.GeneralPurposePanel2ScalarDeletingDestructor](by-memory/0x004b8aa0-0x004b8b32.GeneralPurposePanel2ScalarDeletingDestructor.md) 0x004b8aa0-0x004b8b32 | compiler scalar deleting destructor | GeneralPurposePanel2 scalar deleting destructor : ignored : 93% : very-strong : Exact compiler wrapper duplicating the child deletion request and implicit Singleton/LObject teardown before delete flags, 12-byte size guard, and storage free; ordinary destructor child is sole handwritten source and formal C++ stays blank.
```

3. Replace UID00015Y row with:

```text
        - [UID:00015Y][0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild](by-memory/0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild.md) 0x004b89a0-0x004b8a7f | method | GeneralPurposePanel2::SwitchActiveChild : reconstructable : 91% : very-strong : Exact one-child upper-bound/-1 switch with active-index store, old-child Collapse/unregister ordering, exact bounds/layer/order/activation behavior, TotemFrame and FrameChrome dependencies, one UserPane initialization caller, position 60, and nullable packet-data contract.
```

4. Under UID0002V4, immediately after UID0003BC and before the GrafPort child/successor, insert:

```text
        - [UID:0003BD][0x0061a894-0x0061a8a4.GeneralPurposePanel2VtableData](by-memory/0x0061a894-0x0061a8a4.GeneralPurposePanel2VtableData.md) 0x0061a894-0x0061a8a4 | compiler RTTI/vtable data | GeneralPurposePanel2 vtable data : ignored : 92% : very-strong : Exact 16-byte COL and three-slot vtable with direct LObject/Singleton hierarchy, PMD +4 EBO, constructor/ordinary/scalar vptr stores, exact boundaries/hash, source-declared/generated-binary disposition, and blank non-emitting formal C++.
```

5. Replace UID00029L row with:

```text
    - [UID:00029L][0x0069b350-0x0069b358.StartupClearedUnusedDwords](by-memory/0x0069b350-0x0069b358.StartupClearedUnusedDwords.md) 0x0069b350-0x0069b358 | loader-zero compiler residue | StartupClearedUnusedDwords : ignored : 88% : very-strong : Two loader-zero-filled `.data` virtual-tail dwords with only redundant compiler startup stores of zero, no reads, exact predecessor/target boundaries, and blank non-emitting no-code disposition; historical 0xffffffff observation is superseded.
```

6. Replace UID0002VS row with:

```text
    - [UID:0002VS][0x0069b358-0x0069b35c.g_pGeneralPurposePanel2Storage](by-memory/0x0069b358-0x0069b35c.g_pGeneralPurposePanel2Storage.md) 0x0069b358-0x0069b35c | physical singleton backing | g_pGeneralPurposePanel2Storage : ignored : 92% : very-strong : Exact loader-zeroed four-byte physical backing with 14 refs partitioned into five compiler/Singleton lifetime writes and nine runtime reads, exact neighbor boundaries, semantic one-definition route through UID0000R1, rejected historical 0xffffffff claim, and blank false/non-emitting formal C++.
```

7. Verify-only, no row change: current UID00015Z already preserves the exact `92%` compiler-base-destructor union and blank no-code disposition; UID0003TY/UID0003UN consumer pages do not have separate manual rows requiring target-only changes.

8. In `by-global/-coverage-report.md`, replace UID0000R1 row with:

```text
- [UID:0000R1][g_pGeneralPurposePanel2](by-global/g_pGeneralPurposePanel2.md) : reconstructable : 92% : very-strong : Sole externally linked zero-initialized GeneralPurposePanel2 pointer definition at position 20 in NexusTK/ui/panels/GeneralPurposePanel.cpp, matched by one extern after the complete direct LObject plus Singleton<GeneralPurposePanel2> class. Physical UID0002VS is loader-zero backing with 14 refs, five compiler/template lifetime writes, nine reads, one-definition policy, and no duplicate physical-page emission.
```

9. In `by-class/-coverage-report.md`, replace UID00005R row with:

```text
- [UID:00005R][GeneralPurposePanel2](by-class/GeneralPurposePanel2.md) : reconstructable : 92% : very-strong : Complete 12-byte one-child side-panel class with direct LObject plus Singleton<GeneralPurposePanel2> inheritance, PMD +0x04 EBO over m_childPanes[0], exact constructor/destructor/GetChild/GetActive/DispatchRefresh/Switch source children, sole external g_pGeneralPurposePanel2 definition/header declaration, one NewSystemMessagePane child, compiler-only EH/helper/scalar/vtable support, and preserved nine-reader consumer behavior.
```

10. In `by-file/-coverage-report.md`, replace UID0000JQ row with the full primary-plus-alternate union:

```text
- [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md) : reconstructable : 92% : very-strong : NexusTK/ui/panels/GeneralPurposePanel.cpp owns sole typed zero definitions and complete direct LObject plus Singleton declarations for both GeneralPurposePanel shells. Primary source preserves seven children, constructor/destructor/accessor/tab-switch order, 87-ref storage evidence, and compiler exclusions; alternate source preserves one NewSystemMessagePane child, constructor/destructor/GetChild/GetActive/DispatchRefresh/Switch order, exact 14-ref storage evidence, 12-byte PMD/EBO layout, compiler-only helper/scalar/vtable artifacts, exact padding, one-definition policy, consumer boundaries, aliases, and historical corrections without by-file reconstruction metadata.
```

- Reason B005 must not apply these rows: manual `-coverage-report.md` files are supervisor-owned. Scoped validators refresh validator-owned generated artifacts but do not authorize manual row edits.

## Follow-Up Actions

- B005's accepted implementation responsibilities are complete: six children were serially registered, Destinations 1-13 and all bounded support changes were applied, nineteen ordinary pages passed scoped validation, all leases were released, and final waited command `15783` passed generated assertions.
- Independent review, exact manual coverage application, report execution, and archival remain supervisor-owned external lifecycle state. This report neither directs nor assumes when those actions occur and remains true before or after them.
- A-agent actions: none required.
- Remaining B005 research: none blocking. Raw UserPane source-family audits remain independent tracker work, not a missing UID0002VS conclusion.

## Confidence

- Recommendation confidence: 98%.
- Score confidence: 96% for target/global/class/aggregate/file; 94% for the two inferred unmodeled method names; 99% for compiler/no-code dispositions.
- Remaining uncertainty: original symbol/header spellings only. Behavior, layout, ownership, source route, and source/compiler boundary are closed.

## Validator Results

- Every changed/new ordinary page passed one scoped validator while its one-file lease was active; the final source page additionally passed the single authorized waited refresh after all leases were clear.

| Command | Timestamp (ET) | Scoped page / role | Result and relevant side effects |
| --- | --- | --- | --- |
| `15751` | `2026-07-21 11:22:58` | UID0004UU constructor registration | exit 0; UID issued; registry/reference/projected-stats update; generated deferred. |
| `15752` | `11:24:30` | UID0004UV destructor registration | exit 0; UID issued; registry/reference/projected-stats update; generated deferred. |
| `15754` | `11:25:39` | UID0004UW GetChild registration | exit 0; UID issued; registry/reference/projected-stats update; generated deferred. |
| `15756` | `11:26:34` | UID0004UX GetActive registration | exit 0; UID issued; registry/reference/projected-stats update; generated deferred. |
| `15757` | `11:27:45` | UID0004UY DispatchRefresh registration | exit 0; UID issued; registry/reference/projected-stats update; generated deferred. |
| `15758` | `11:28:53` | UID0004UZ scalar registration | exit 0; UID issued; registry/reference/projected-stats update; generated deferred. |
| `15761`, `15763`, `15764` | `11:30:37`-`11:33:07` | target, global, GP2 class | each exit 0/`ok:1`; reference/stats updates; generated deferred. |
| `15766`, `15768`, `15769` | `11:33:40`-`11:34:55` | switch, vtable, predecessor | each exit 0/`ok:1`; UID0003BD registered by its own scoped validation; generated deferred. |
| `15771`, `15773` | `11:36:37`-`11:38:00` | aggregate and GeneralPurposePanel file | each exit 0/`ok:1`; pre-existing missing UID0003A2 warning retained; generated deferred. |
| `15775`, `15776` | `11:38:28`-`11:39:03` | startup allocation and teardown consumers | each exit 0/`ok:1`; reference/stats updates; generated deferred. |
| `15779` | `11:41:35` | UserPane server dispatcher | exit 0/`ok:1`; pre-existing missing UID0003VC warning; generated deferred. |
| `15781`, `15782` | `11:43:05`-`11:43:35` | UserPane class and file | each exit 0/`ok:1`; validator normalized links; pre-existing missing-reference warnings only; generated deferred. |
| `15783` | `11:43:44` | final `by-file/GeneralPurposePanel.md --wait-generated` | exit 0/`ok:1`; generated refresh completed; validator registry/report metadata rebuilt; pre-existing project-wide warnings and UID0003A2 warning retained. |

- Registration validators do not print a separate `ok:1` line, but each exited zero and issued the stated real UID; subsequent scoped/final validators recognize all six pages through UID0004UZ.
- Validator side effects were validator-owned registry/reference/projected-stat/generated updates. B005 did not edit validator state, generated output, tracker, or manual coverage directly.
- B005 generated callback proof is header command `000000015783`, SHA256 `079791BA831778EB2E9781BFFA4070B6BC195B7C14F924C92743DDEA49D2968D`, 8,102 bytes/270 lines. The time-bounded current readback is external header command `000000015787`, SHA256 `507A011ACC2B2D781D222690E12E91E53645C325960A03C76CEB2AD579A371DD`, with unchanged size/lines and counts: one GP2 definition, one extern, one direct `LObject`/`Singleton` class, one each ctor/dtor/GetChild/GetActive/DispatchRefresh/Switch, zero UID0002VS/UID00015Z/UID0004UZ/UID0003BD/UID00015V markers, zero `Empty Emitter Marker`, and zero raw-label/vptr/EH/delete/RTTI/decompiler spellings. The complete primary family remains before GP2 and unchanged in source shape/order.
- Current tracker readback at external command `000000015787` is SHA256 `F75A7D2E16260165FF52D0AEE6B8C3C5AA887CD343B7D5E1BD41BF36570A7FCC`, 1,540,198 bytes/6,233 lines. B005 command 15783 remains historical callback provenance; tracker state is mutable validator-owned external state, not lifecycle proof.

## Changed Files

- Updated callback artifact: `tools/leaser/Agents/Agent-B005/research/0002VS-g_pGeneralPurposePanel2Storage-source-quality.md`.
- Nineteen changed/new ordinary pages and current SHA256 values:

```text
by-memory/0x0069b358-0x0069b35c.g_pGeneralPurposePanel2Storage.md D682D296DC1CD29E4D34931F9CDDDB9EADF9541E8FB8687B3A8DD2EEC53F3C1B
by-global/g_pGeneralPurposePanel2.md 1C12B570EB7CE39F43D9641B89D518F93C7DDF74D32FEA6CCE3ADD6C14ABEE29
by-class/GeneralPurposePanel2.md 7EA779350E3EF3409494BFD0F93FC734F1B0585AA0903831E4AA3F971C6C9A5D
by-memory/0x004b8830-0x004b88e1.GeneralPurposePanel2Constructor.md 4B3D4D7556320CF5A138DD8C967AB2CCBF34E32E033B7BF17AC512FE3D6C61AC
by-memory/0x004b88f0-0x004b8944.GeneralPurposePanel2Destructor.md BF3B49FE4BC49BCF13B4B1EC4BDC18F96BE5667E0BA0417545D52BB9444CE9A3
by-memory/0x004b8950-0x004b8969.GeneralPurposePanel2GetChildPaneByIndex.md BA9A28F1EA95F80862FD46F08DF41CA7E32D09DF5603406A121D9AF7CC008343
by-memory/0x004b8970-0x004b8980.GeneralPurposePanel2GetActiveChildPane.md A7FAA40455AFE3670BCE1C803CE4028444093424CF28102A9F44D0E8D2956460
by-memory/0x004b8980-0x004b8994.GeneralPurposePanel2DispatchActiveChildRefresh.md 07D483D0103EA82209225997414CD045B87C3BE4A6ECD66081FB1D453FF737C0
by-memory/0x004b8aa0-0x004b8b32.GeneralPurposePanel2ScalarDeletingDestructor.md 3EA07B776F3C30F46923B79BFA2B37ABD670C7E3908F487D5A51748411649079
by-memory/0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild.md F85EBCE4246BCE8F8BE4461802A41016FAD45DC8EE5BDB2C53DD36C8DA073E97
by-memory/0x0061a894-0x0061a8a4.GeneralPurposePanel2VtableData.md CC2816E465B74F56B1DD99BA0B2BA1A40068D1949FEA1DC04ED2FEEFA0CF48D9
by-memory/0x0069b350-0x0069b358.StartupClearedUnusedDwords.md 341A411BC15407A680938F7CE6EB4BC2D54279C511B028192C6941795ABE50EA
by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md 4FAB31163E29ECE47C66DE33244C6F70E5DD36346503FF234400882297FCB2ED
by-file/GeneralPurposePanel.md 6606BB601BC87D8A595FB938D9E46C714ECCAE1C71965554EA4F9FCED44C542D
by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md C02202DB565E4B32E8D5213E5408606E13E5FD3CA93DA2C796D178E92B12DADB
by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md E8DF5A35733E0A9B650247EA89163CF2646AA90FB43936ADE59A11A605FE3018
by-memory/0x005a76c0-0x005a82bd.UserPaneHandleServerMessage.md 0D5DF1D0622063D9F78005DA69A0917435F59D0A055651E1B2A75E8715E1EB40
by-class/UserPane.md 6D503CC55A7E755E88F4200CB0CA755EF2E7080A0B5EF0C10DDB7239C694C2F1
by-file/UserPane.md 5DE7B8AF26AA5A5928DA71E12537AF898A180E5913F6876CC74407D7B6082BF3
```

- Verify-only unchanged pages: UID00015Z SHA256 `5369DA38BC4CF5F31FE0B96853483BD917C971694AE0B28DA97B1B85751C5693`; UID0003TY `837666ACDEDAE3010877126711499C4F0A5C18DD023D5A26CDFAF5380FBACF43`; UID0003UN `ABE9BBB346E300C44EDAFADC851B2807BE3212EE0969EF7F8B56E87E2A0FD326`.
- Restricted files manually modified by B005: none. Manual coverage remained read-only; generated/tracker/validator changes were validator-owned side effects; audit/supervisor/goal/IDA/lifecycle files were not edited.
- Lease proof: one ordinary file was leased at a time only around its edit/scoped validator and released immediately. Final current-leases reread contains no B005 entry.
- Report execution/lifecycle: not run or probed. B005 did not execute, count, move, archive, register lifecycle state, or invoke an equivalent report command.

## Implementation Tracking Checklist

Completed report-only research and implementation callback:
- [x] Supervisor validation required before implementation.
- [x] Preserve this report's CHATGPT 5.6 xHigh provenance and all research detail.
- [x] Reread every ordinary destination immediately before callback editing.
- [x] Reconfirm no competing lease/assignment before each ordinary edit.
- [x] Register constructor child serially and replace `UID0004UU` everywhere.
- [x] Register destructor child serially and replace `UID0004UV` everywhere.
- [x] Register GetChild child serially and replace `UID0004UW` everywhere.
- [x] Register GetActive child serially and replace `UID0004UX` everywhere.
- [x] Register DispatchRefresh child serially and replace `UID0004UY` everywhere.
- [x] Register scalar-wrapper child serially and replace `UID0004UZ` everywhere.
- [x] Apply C01-C40 without compression and retain destination-specific proof.
- [x] Apply Destination 1 target metadata/Item Summary/blank no-code block.
- [x] Apply Destination 2 sole global definition and position 20.
- [x] Apply Destination 3 complete direct-base class declaration and position 30.
- [x] Apply Destination 4 exact constructor body and report-level evidence.
- [x] Apply Destination 5 exact ordinary destructor body and report-level evidence.
- [x] Apply Destination 6 exact GetChild body and report-level evidence.
- [x] Apply Destination 7 exact GetActive body and report-level evidence.
- [x] Apply Destination 8 exact DispatchRefresh body and report-level evidence.
- [x] Apply Destination 9 byte-for-byte to UID00015Y and set position 60 only.
- [x] Verify Destination 10 remains byte-for-byte on UID00015Z.
- [x] Apply Destination 11 blank scalar-wrapper no-code block and evidence.
- [x] Apply Destination 12 false/non-emitting vtable block and evidence.
- [x] Apply Destination 13 blank complete aggregate block and evidence.
- [x] Correct UID00029L current Item Summary while preserving historical ff provenance.
- [x] Raise only accepted target/support scores and preserve all other scores/routes.
- [x] Update UID0000JQ complete primary/alternate source-unit union without by-file formal metadata.
- [x] Update UID00019K bounded 12-byte allocation/implicit publication evidence.
- [x] Update UID0002QH bounded null-tested scalar-delete-flag-1 evidence.
- [x] Verify UID0003TY exact read/formal unchanged absent contradiction.
- [x] Update UID0003VB complete four-read target inventory without broad-body compression.
- [x] Verify UID0003UN exact read/formal unchanged absent contradiction.
- [x] Update UserPane class target-specific consumer inventory without changing formals/scores.
- [x] Update UserPane file target-specific consumer inventory without losing concurrent detail.
- [x] Preserve all 14 xref addresses/roles and five-write/nine-read classification.
- [x] Preserve PE loader-zero proof and historical ff rejection on every affected page.
- [x] Preserve direct LObject/Singleton RTTI/PMD/EBO/12-byte layout proof.
- [x] Preserve source/compiler separation for publication, clear, EH, scalar wrapper, vtable, and padding.
- [x] Preserve exact hashes, function boundaries, ABI, CFG, calls, callers, and negatives.
- [x] Preserve primary GeneralPurposePanel family content byte-for-byte unless a current contradiction requires additive rebase.
- [x] Preserve UID00015Y source body byte-for-byte and UID00015Z no-code block byte-for-byte.
- [x] Preserve MapPane/UserPane/SystemMessagePanes ownership boundaries.
- [x] Confirm no Wave2/Wave3 artifact is incorporated.
- [x] Confirm no third-party import applies.
- [x] Lease only one ordinary page immediately around edit/scoped validation.
- [x] Release every ordinary lease immediately after its validator.
- [x] Record every validator command ID, timestamp, exit, ok, warnings, and side effects.
- [x] Confirm any validator-updated manual coverage is only a side effect; do not edit it manually.
- [x] Run final authorized waited GeneralPurposePanel generated refresh only after all ordinary leases clear.
- [x] Verify one GP2 global definition and one extern.
- [x] Verify one complete direct-base GP2 class and exact source-child order.
- [x] Verify exactly one definition each for ctor/dtor/GetChild/GetActive/DispatchRefresh/Switch.
- [x] Verify zero physical/helper/scalar/vtable/aggregate Empty Emitter Markers.
- [x] Verify primary GeneralPurposePanel source and sibling globals remain unchanged.
- [x] Verify no handwritten vptr/EH/delete flags/RTTI/raw labels/decompiler artifacts.
- [x] Record final generated command/header/hash/bytes/lines and structural counts.
- [x] Preserve exact fifteen-action supervisor-owned manual handoff with real UIDs in the completed callback artifact.
- [x] Do not edit any manual `-coverage-report.md` file.
- [x] Update C01-C40 to legal terminal callback states with separate exact proof.
- [x] Update Current State, recommendations, Validator Results, Changed Files, and Follow-Up to durable callback truth.
- [x] Check only rows actually completed; list any exclusion with exact reason.
- [x] Confirm zero provisional UID tokens remain after registration.
- [x] Confirm zero B005 leases remain.
- [x] Do not run/probe `execute_report`, lifecycle, move, or archive commands.
- [x] Return the current same-report path/SHA/metrics for independent Gate 2 review.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000015795","destination_path":"executed-b-agent-research/B005/0002VS-g_pGeneralPurposePanel2Storage-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0002VS-g_pGeneralPurposePanel2Storage-source-quality.md","timestamp":"2026-07-21T12:08:13-04:00","uid":"0002VS"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
