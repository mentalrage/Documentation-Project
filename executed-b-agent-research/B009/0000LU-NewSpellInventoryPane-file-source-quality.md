# 0000LU NewSpellInventoryPane Whole-File Source Quality
** TARGET-REPORT-UID:0000LU **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **


## Finalized Report / Current Recommendation

- Current recommendation: retain [UID:0000LU] `by-file/NewSpellInventoryPane.md` as canonical `FILE` route `NexusTK/ui/inventory/NewSpellInventoryPane.cpp`; retain [UID:00009A] as the direct class emitter; retain the 25 implemented exact children in source order; preserve disconnected `nullsub_54` only as an ownerless dead-code physical artifact.
- B009-owned ordinary disposition: the prior empty emitter is replaced by a complete compilation unit and sibling header. The class tail is corrected from the stale IDA/doc `0x100` projection to the allocator-proven `0x148` layout, including `m_scrollPane` at `+0x100` and `m_draggedSincePress` at `+0x145`. Six support headers are now self-contained guarded C++03 routes, and exact padding `[0x0057e18f,0x0057e190)` is explicit before the pointer-event switch table.
- Remaining authority: B009 incorporated the complete ordinary inventory, formal CPP/H, child routes, source order, support-page changes, scores, validators, and generated readback. Supervisor Gate 2B is applied, verified, and saved as the dated transaction recorded below. The Section 28 manual coverage payload is supervisor-verified already present and validated; report execution/archive remains supervisor-owned.
- Confidence: very strong for membership, boundaries, behavior, field offsets, class size, separate Scroll companion placement, and source order; strong for descriptive source-facing names. Original private spellings are unavailable and are not claimed as symbols.

## Supporting Research

- The accepted implementation callback follows goal SHA256 `692A439E5FE111618DDEC2FE11C59FEFFBFB184826F57D7856A091C97AC3F3DB` and exact Gate 1 report SHA256 `04A62F874277941D6B39F15500ED2F84CDB70D4207361E49A650198E4CDDC236`.
- A dated 2026-08-15 read-only documentation snapshot recorded the target SHA256 `E59D1A5DA56578B24B9C8D4645D30821A159A6DEE4BB9765D57F673ADF50FC5C`, class SHA256 `FE7C581F4126C0D249F1526E07085230007DC3D0E9DE391FD83D0EC458C79085`, core SHA256 `3D1F5A95CEBEF9B930424AEB03DB11884765241B6AA79ADFA664208D5EB0AE9A`, broad parent SHA256 `884A558A7DD414839138D20D947EB0CCC207BC119B4A1BC7331E3BB1402C924D`, scalar group SHA256 `5DA1AEBFEABAFB9C54327152ECCF2FE117C807726C37AFBF47056B51823C6EE8`, and macro `.rdata` SHA256 `9A93217020E9C59F8B633375B49F71A98805F77CA92F65B4924A76B1F3A04452`.
- The same dated snapshot recorded Scroll file/class/core/layout/vtable hashes `004FC4C08FDC76262566C11A804AF6207E826DA4B0445CC95784BAA83072340E`, `903B6B46E2E113492A9FAD7BC803E768D3CB773C1D15E4BA98EF3E6C6CD405BE`, `CC59CC0DD2C44254094A43182408756E3C0FD697950ECE49646A26DB93F8DA05`, `6605857495CB848B8DEBC678BBD0945B35BD8EA5A76BCDC378DAE4EF6545A0AE`, and `21EAD45362A9CD5F822682E8BA3CE89AE8808F3003E756900F2C5D5C6AE27337`.
- The 2026-08-15 resource snapshot recorded [UID:0003BX] SHA256 `36633B305E3121E9319671DD76C9279EA02D4EEA7269DFBE40249B69AF8F8F6F`; its literal and use-site map already preserves the required NewSpell resources.
- Earlier live session `1abf9793` was used only as a dated research snapshot. It was replaced during this pass. All decisive facts were rechecked read-only in the later canonical session identified under `Supervisor Active Recheck`; no earlier session is represented as current authority.
- No Wave2/Wave3 source or instruction was used. Matching archived B005/B001/B002 reports were treated as leads and independently revalidated against current docs and live IDA.
- Historical report-only coordination was limited to the report path. During the accepted callback and this additive Gate 2A repair, B009 used short per-document leases for all 65 ordinary destinations, released every lease after its scoped validator, and later updated only this same report for receipt/checklist incorporation. Coverage, generated artifacts, IDA, and lifecycle state were never manually edited.

## Target

- Target UID: `0000LU`.
- Additional target UIDs: none.
- Declared-target inventory: only [UID:0000LU] `by-file/NewSpellInventoryPane.md`, the file-route page. Every other UID/path in this report is a support destination and receives no additional-target coverage claim.
- Target path: `by-file/NewSpellInventoryPane.md`.
- Dated pre-callback queue state: uncovered by-file row at `86/88` with blank reconstructability metadata; the assignment explicitly selected it after collision checks.
- Assignment record: this same report received an accepted ordinary-document implementation callback; lifecycle authority remains outside ordinary prose.
- Implemented scores and parent state: target `94/95`, canonical owner `FILE`, route `NexusTK/ui/inventory/`; class [UID:00009A] `94/95`, owner/emitter `0000LU`; broad core [UID:0002RJ] `94/95`, `RECONSTRUCTABLE:FALSE`, owner/emitter relationship `00009A`, formal channels blank by design.
- Inferred compilation-unit boundary: source-owned code is the NewSpell code from `[0x0057cf70,0x0057ea57)` excluding foreign `[0x0057d0a0,0x0057d0b0)`, compiler tables/padding, and the scalar wrapper outside the core. The ordinary destructor and four other coherent raw bodies remain source definitions even though IDA has not made function objects for them. The adjacent `SpellInventoryPane2` constructor starts at `0x0057ea60`; ScrollSpellInventoryPane remains a separate companion file.

## Current Target State

- Implemented metadata: `COMPLETION:94`, `CONFIDENCE:95`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/inventory/"`, `CANONICAL_OWNER:FILE`.
- Implemented route: target -> class [UID:00009A] -> UID000534 layout comment at position 5 and 25 exact source children at positions `10..250`; broad core [UID:0002RJ] is the non-emitting split/index.
- The former exact-child/raw-body blockers are closed: every source body has a scoped-validated child, while all five raw bodies retain their physical no-function provenance and exact source definitions.
- Formal support headers are now self-contained and C++03-safe through owning H channels: SpellInputPanes includes `InputPanes.h` before the first `NumberArgsInputPane` derivation; SpellInputPanes, TargetSelectionInputPanes, MapPane, LivingObjectPane, BackPane, and UserPane each have exactly one assembled-header include guard. UserPane additionally includes `<stddef.h>` and the complete LivingObjectPane base. NewSpell's direct `UserPane.h` include and indirect re-entry through guarded `MapPane.h` produce no duplicate class or helper definition.
- Exact one-byte padding `[0x0057e18f,0x0057e190)` is now present in the target, class, core, broad aggregate, pointer-child, packet-child, and SpellInventoryPane support inventories. It is one of the established 27 pre/internal/post alignment spans and remains distinct from switch data `[0x0057e190,0x0057e1b0)`.
- Dated pre-callback generated evidence is command `000000024100`, SHA256 `85C62FCE1A480EFE6B82E5D5CA9C60FB65DDFC06DE0328C504D7B4501CD084AC`, with two Empty Emitter Marker rows and no H. The dated accepted-callback readback at `2026-08-15T19:27:14-04:00` was command `000000024429`: CPP SHA256 `376FA815608C5DB2C78E4CE2E47EAF24C47F2DDD720A9027502C2DBCABB2653E`, 25,229 bytes / 748 lines; H SHA256 `27CD475489D1681AE6F4F1E2ED0F3E5451028DC4753230EA54CA500E8F57D3A5`, 2,462 bytes / 67 lines. A later read-only report-repair observation at `2026-08-15T20:29:30-04:00`, command `000000024441`, observed the same complete physical semantics under refreshed generated identities; neither dated command/hash set is permanent current authority, and each later supervisor gate must physically reread the then-current generated artifacts.
- The final additive-repair generated snapshot is dated `2026-08-16T00:23:06-04:00`, command `000000024621`. Its physical hashes and sizes for all 14 affected CPP/H artifacts, including UserPane, are recorded in Validator Results only as a dated observation; supervisor Gate 2 rereads the then-current physical outputs.
- Supervisor Gate 2A independently passed all 65 report claims before the Gate 2B transaction; the accepted ordinary implementation, formal source, scores, validator receipts, and generated-readback history remain unchanged by this reconciliation.
- Supervisor manual-coverage reconciliation verified all 32 literal Section 28 rows already present across the four manual coverage files, including contiguous by-memory placement `UID0002RJ` line 3708, `UID00052F` line 3709 through `UID000533` line 3733, then `UID0001IJ` line 3734. Four scoped validations passed without changing any coverage-file content; exact receipts are in Validator Results.
- Complete code status: 22 IDA functions in the core, of which 20 are NewSpell source functions, one is the foreign `ItemWhoInputPaneState` function, and one is disconnected one-byte `nullsub_54`; five additional complete NewSpell source bodies are raw code items. Total recommended NewSpell definitions: 25. The one-byte orphan has no source child, owner, emitter, or class slot.
- Complete non-source status: two switch tables, 26 internal/post padding spans, one pre-target alignment span, one 35-dword vtable cluster, three EH/cookie records, one scalar-deleting wrapper, two adjustor thunks, external resource literals, and external singleton/global dependencies.
- Layout status: IDA `NewSpellInventoryPane` remains deliberately protected at stale size `0x100` with `m_scrollPane +0xfc`; UID000534 and the generated H now document the allocator-proven `0x148` source layout, constructor writes through `+0x145`, and child pointer at `+0x100`.
- Current lifecycle authority is intentionally not asserted in ordinary prose. Execution/archive truth belongs to the report artifact's path plus validator-owned status/history metadata.

- Dated pre-application Gate 2B repair evidence from session `supervisor_uid0003d9_rollback_20260815` refreshed all 29 I01-I25/P01-P04 rows. It corrected exactly nine protected prototypes: I02 `int __thiscall(char *this, int)`; I03 `__int16 __thiscall(_DWORD **this, struct RectBounds *)`; I07 `__int16 __thiscall(Pane *this, RectBounds *bounds, int order, Pane *previousPane, Layer *layer)`; I08 `void __thiscall(int this)`; I09 `void __thiscall(int this)`; I13 `char __thiscall(TimerHandler *this, int, int, int)`; I15 `void __stdcall(unsigned __int8)`; I16 `void __stdcall(__int16, struct RectBounds *bounds)`; I19 `void __thiscall(TimerHandler *this)`. Every other renewed name/type/range/comment/frame/byte/xref fact matched the report's accepted protection contract. No IDA mutation or save occurred during that dated B009 report-repair recheck.
- Dated supervisor Gate 2B transaction `2026-08-16`: session `supervisor_uid0000li_i37rollback2_20260816` opened canonical prestate SHA256 `D6EF0A13A878558E0C79F225439D7C2778BB86C040093EF26EEE4034FA3849EF`, 143,208,000 bytes, after creating byte-identical backup `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B009-UID0000LU-Gate2B-20260816-013557.i64`.
- That supervisor transaction applied and verified I01-I20 as 19 pure function renames plus exact regular function comments, with I06 already exact; applied and verified the five I21-I25 regular raw-head comments; verified P01-P03 already exact and unchanged; and rejected P04 as invalid with no UDT/type/frame mutation. No type endpoint was used.
- `idb_save` returned `ok:true`. The saved canonical database is SHA256 `C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B`, 143,208,000 bytes, last-write UTC `2026-08-16T05:39:50.1775844Z`; fresh post-save runtime attestation and bounded I01-I25/P01-P04 readback passed.

## Executive Recommendation

- Direct route is implemented: [UID:0000LU] is the source-file parent, [UID:00009A] is the class emitter, and [UID:0002RJ] is a non-emitting exact split/index.
- All 25 exact source children exist at positions `10..250`, with owner/emitter `00009A`, child CPP definitions, blank child H, and no child/source position for disconnected `nullsub_54`.
- [UID:000534] `by-type/by-struct/NewSpellInventoryPaneLayout.md` documents the exact `0x148` natural layout and emits only the accepted covered-by comment; class H owns storage once.
- [UID:0000NJ]/[UID:0000CN] ScrollSpellInventoryPane remains a separate private companion; its declaration is in H, CPP includes H and children, and `friend class NewSpellInventoryPane` supplies exact access.
- Preserve the repaired support-header topology: one guard per assembled header, base definitions included before derivation, and no `[[CHILDREN]]` or `[[No Children Attached]]` token in generated H. Direct and indirect UserPane inclusion is intentionally redundant at the include graph but safe under the guards.
- Preserve [UID:0001IJ] as foreign TargetSelectionInputPanes source, [UID:0002RL] wrapper/thunks as compiler-generated no-source items, and the macro `.rdata`/resource pages as non-emitting evidence.
- No research blocker remains. Exact historical private identifier spellings are unavailable, but deterministic behavior and descriptive naming are sufficient for faithful reconstruction and are explicitly labeled inferred.

## Supervisor Active Recheck

- Historical research trigger: the durable Agent-B009 assignment selected UID0000LU whole-file research and required live canonical IDA MCP, complete split/source/header resolution, and report-only boundaries.
- A dated fail-closed read-only pre-application attestation snapshot at `2026-08-16T03:06:45.478788+00:00`/`2026-08-16T03:06:45.591263+00:00` used session `supervisor_uid0003d9_rollback_20260815`, listener PID `14320`, redirector PID `26224`, worker PID `9384`, and canonical database `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- In that dated snapshot, `server_health` returned `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready, strings cache not ready with `0` entries, and `auto_analysis_ready:false`. Bounded IDB-backed queries succeeded for every I01-I25/P01-P04 endpoint, so the workflow says this flag alone is not an MCP failure.
- Split repair was required in the historical callback prestate because the broad core mixed source functions, raw bodies, foreign code, tables, and padding. The accepted callback has now given every source-bearing item an exact child path, source position, formal CPP/H disposition, and ledger/checklist row; UID0002RJ is now the non-emitting split/index.
- During that dated B009 report-repair snapshot, no IDA/MCP mutation or process control occurred and all calls were read-only.
- The later dated supervisor Gate 2B transaction used session `supervisor_uid0000li_i37rollback2_20260816`. It applied the exact I01-I05/I07-I25 actions, recognized I06 and P01-P03 as already exact, rejected P04 without mutation, saved the canonical IDB, and completed fresh post-save runtime attestation plus bounded readback. These are transaction facts, not a claim that the dated session identity remains permanently current.

## Inference Research Guidance Check

- The evidence ladder was applied as: exact bytes/boundaries and allocator/vtable/caller facts; decompile/disassembly behavior; cross-function field consistency; current docs and related exact children; then source-facing naming inference.
- Existing assumptions treated as uncertain were the `0x100` layout, `m_scrollPane +0xfc`, raw-body exclusion solely because incoming xrefs are absent, the aggregate empty-code rationale, and a possible fold of ScrollSpellInventoryPane into NewSpell.
- IDA fact, documentation evidence, and inference are separated throughout. Descriptive names such as `RebuildSpellList`, `ActivateSpellSlot`, and `m_draggedSincePress` are inferred from stable behavior; they are not claimed as recovered symbols.
- `by-structure.md` routing discipline supports one file parent, one direct class emitter, exact by-memory method bodies, and a single class H declaration. It rejects duplicate class declarations and aggregate body bundles.
- Stale Wave2/Wave3 material was ignored.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence and reanalysis | Resolution |
| --- | --- | --- |
| Dated empty generated emitter | Command `000000024100` captured blank class/core formal channels and two empty markers before callback. | Superseded by the complete class CPP/H, 25 exact child CPP bodies, non-emitting core split/index, and the dated accepted-callback plus report-repair physical generated observations; later gates require fresh physical reread. |
| Raw starts with no incoming xrefs | Each of `0x57d040`, `0x57e5a0`, `0x57e6f0`, `0x57e760`, `0x57e960` is contiguous code with a complete epilogue/tail, coherent class/file behavior, exact padding boundaries, and no overlap with a modeled function. | Retain as source definitions. Lack of a direct call is provenance evidence, not permission to discard executable source bytes. Do not create IDA functions because deterministic frame/type creation is not proven. |
| Stale class size | GeneralPurposePanel allocates exactly `0x148` before calling the constructor; constructor writes fields through `+0x145`; base size is `0xf8`; pointer write is `+0x100`. | New layout is `0x148`; reject current `0x100/+0xfc` projection. |
| Field names | Cross-body reads/writes resolve `+f8,+f9,+fa,+100,+104,+139,+13a,+13c,+140,+144,+145`. | Use descriptive names in the class H; preserve offsets and signedness. |
| Row-count asymmetry | list range uses 13 collapsed/26 expanded while row hit-test accepts index `0..12` or `0..26`. | Preserve literal binary conditions; do not normalize the expanded hit-test to 25 or 26. |
| Spell route cases | dispatcher switch table has nine entries and allocates seven prompt pane kinds or sends direct packets. | Use explicit `SpellInputKind` values `1..9`; preserve direct routes for 5 and 9 and target-aware direct route for 2. |
| Scroll source placement | one constructor caller couples Scroll to NewSpell, but Scroll has its own complete class, vtables, core, exact children, and existing standalone route. | Keep standalone private companion file; add normal header visibility/friendship instead of folding sources. |
| Vtable/source split | primary, event, and timer views are compiler tables; destructor wrapper and adjustors are compiler-generated. | Document and protect; do not emit table words, scalar wrapper, or thunks as handwritten methods. Ordinary non-deleting destructor emits from raw `0x57d040`. |
| Current IDA types | many function prototypes are decompiler approximations and the shared UDT is stale. Public parser/type replacement durability is not established for a safe whole-UDT correction. | Supervisor Gate 2B used only deterministic rename/comment actions and preserved types, frames, boundaries, and UDT. Source H carries the correct layout independently. |
| Original spelling | no symbols/debug records recover private names. | Use stable descriptive names, label them inferred, and cap confidence below original-symbol certainty. |
| Rejected monolithic core C++ | broad range includes a foreign body, an ownerless dead-code artifact, tables, and raw bodies. | Exact children only. |
| Rejected headerless module | Scroll compilation needs the owner callback declaration; other modules construct/use the class; object layout is nontrivial. | Generate a sibling H from the class H channel. |
| One-byte `nullsub_54` | Fresh `2026-08-15T13:05:34.497Z` read-only inspection found exact code item `[0x57d0b0,0x57d0b1)`, one-byte `ret`, type `void()`, zero incoming/outgoing xrefs, zero little-endian VA pointer hits, no nearby alias, and no `0x57d0b0` word in the complete NewSpell vtable cluster. The predecessor is foreign UID0001IJ and the successor is 15-byte alignment before `0x57d0c0`. | Classify as an ownerless disconnected dead-code artifact with `CANONICAL_OWNER:NONE`, blank emitter, `RECONSTRUCTABLE:FALSE`, and no CPP/H or child. Preserve its physical IDA item through P02 only; do not infer a human declaration from its `nullsub_54` analysis label. |
| Formal dependency closure | The prior draft used report-only drawing/opening/global APIs and wrong generated signatures. Accepted-callback owners and generated declarations were audited symbol by symbol. The additive repair found unguarded assembled support headers and a late `InputPanes.h` include after early NumberArgs derivations. | Inline exact paint/hotkey/button operations; construct exact pane classes; use typed globals and packet functions; route stranded class/global declarations to their owning headers; include complete bases before derivation; enclose SpellInputPanes, TargetSelectionInputPanes, MapPane, LivingObjectPane, BackPane, and UserPane in one guard each. |

No unresolved source-quality issue affects ownership, split, behavior, CPP/H, or score. The only residual is unknowable original private spelling, which does not block faithful source.

## Evidence Standards Used

- IDA MCP: `idb_list`, `runtime_attestation`, `server_health`, `lookup_funcs`, `analyze_function`, `analyze_batch`, `inspect_items`, `get_comments`, `stack_frame`, `callees`, `xref_query`, `type_inspect`, `get_bytes`, and integer reads of the complete vtable cluster.
- Binary evidence: exact PE-backed body hashes, function endpoints, raw-body endpoints, switch-table spans, padding, RTTI/vtable pointers, constructor allocation, field offsets, and packet constants.
- Documentation evidence: target/class/core/broad/scalar/macro pages, Scroll file/class/core/layout/vtable/exact children, resource page, generated CPP snapshot, manual coverage rows, and matching archived reports.
- Negative evidence: no extra modeled source function, no file-owned data object, no raw-start incoming xref, no vtable or encoded-pointer route to `nullsub_54`, no vtable route to raw helpers, no generated H, no source route through the foreign helper, and no evidence that Scroll is a generic/shared owner.
- Tool limitation: `auto_analysis_ready:false` was recorded, but live bounded queries succeeded. No mutation endpoint was used to test parser or function creation behavior.

## Evidence Checked

- In exact session `supervisor_uid0003d9_rollback_20260815`, rechecked every I01-I25/P01-P04 endpoint: all 22 function objects, all five raw source starts, all entry comments, exact stack frames, entry incoming/outgoing xrefs, all unique callees, all 28 byte spans/hashes, `NewSpellInventoryPane`, `ScrollSpellInventoryPane`, `PanelPane`, `RectBounds`, and `Event` UDTs, all 35 vtable dword heads plus successor `0x62d0f0`, constructor allocation caller, and exact core neighbors.
- Read the complete pre-callback and post-callback target/support pages; searched all by-* paths and matching reports for NewSpell/Scroll identities, resources, vtables, layout, scalar wrapper, core range, dependency owners, header fragment order, guard ownership, and the missing `[0x0057e18f,0x0057e190)` padding row.
- Read manual by-file/class/memory/type coverage rows as dated supervisor-owned inputs; physically reread the dated accepted-callback generated target/dependency CPP/H after refresh, with the later command-24441 repair observation separately bounded below.
- Negative searches rejected a separate file-owned global/static, generic ScrollBar ownership, legacy SpellInventoryPane ownership, SpellInventoryPane2 overlap, and TargetSelectionInputPanes ownership of NewSpell code.
- Callback implementation plus this repair scoped-validated every changed ordinary destination, ran a final owning-route waited refresh, and physically reread every affected generated CPP/H including UserPane. Manual coverage content remained untouched and was later supervisor-verified already present and validated; report execution/lifecycle remains untouched.
- Whole-file completeness result: 25 implemented source definitions + one ownerless disconnected one-byte item + one foreign function + compiler/table/padding/data/type/resource/dependency inventory is fully reconciled below.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C0000LU-001 | 0000LU | Retain `NexusTK/ui/inventory/NewSpellInventoryPane.cpp` and canonical owner `FILE`. | very-strong | Target route, class/core ownership, neighboring modules. | `by-file/NewSpellInventoryPane.md` Status/File Role | incorporate | implemented |
| C0000LU-002 | 0000LU | Retain UID00009A as direct class emitter and source route through UID0000LU. | very-strong | Current metadata and vtable/class evidence. | `by-class/NewSpellInventoryPane.md` ownership | incorporate | implemented |
| C0000LU-003 | 0000LU | Convert UID0002RJ to non-emitting exact split/index over children. | very-strong | Mixed 22-function/raw/foreign/table span. | UID0002RJ status/inventory | incorporate | implemented |
| C0000LU-004 | 0000LU | Create exact `0x148` NewSpell layout support; reject stale `0x100/+0xfc`. | original-proof | `0x4b84b6` allocation and constructor writes. | new by-type layout; class H | reject-stale | implemented |
| C0000LU-005 | 0000LU | Keep ScrollSpellInventoryPane as standalone private companion and repair header route. | strong | Sole ctor caller plus complete independent class/core/vtables. | UID0000NJ/UID0000CN | incorporate | implemented |
| C0000LU-006 | 0000LU | Preserve 35-dword NewSpell vtable cluster and successor boundary as compiler data. | original-proof | live reads `[0x62d064,0x62d0f0)`. | macro `.rdata`; class evidence | already-present | verified |
| C0000LU-007 | 0000LU | Resolve every target dependency through exact owner headers; make SpellInputPanes base-complete and give SpellInputPanes, TargetSelectionInputPanes, MapPane, LivingObjectPane, BackPane, and UserPane one self-contained C++03 guard each, with direct/indirect UserPane inclusion duplicate-safe. | very-strong | dated command-24621 physical declaration/include/guard audit and live callees. | target/class/core dependencies and named support formal H docs | incorporate | implemented |
| C0000LU-008 | 0000LU | Exclude foreign `ItemWhoInputPaneState::SetInputModeFlag` from this source. | original-proof | 17 external callers, existing owner/type/comment. | target/core/UID0001IJ | already-present | verified |
| C0000LU-009 | 0000LU | Scalar wrapper, adjustors, EH records, and switch tables are compiler-covered/no handwritten source. | very-strong | vtable routes, endpoints, table targets. | UID0002RL/macro/core | already-present | verified |
| C0000LU-010 | 0000LU | Preserve every exact pre/internal/post padding boundary, including literal one-byte `[0x0057e18f,0x0057e190)` before switch table `[0x0057e190,0x0057e1b0)`. | original-proof | byte audit, adjacent item heads, and 27-row alignment reconciliation. | target/class/core/broad/pointer/packet/SpellInventory inventories | incorporate | implemented |
| C0000LU-011 | 0000LU | Emit constructor `[0x57cf70,0x57d03f)` at position 10. | very-strong | allocator, vtables, field writes, child ctor. | new constructor child | incorporate | implemented |
| C0000LU-012 | 0000LU | Emit ordinary destructor raw body `[0x57d040,0x57d075)` at position 20. | strong | complete child-delete/base-dtor body and boundaries. | new destructor child | incorporate | implemented |
| C0000LU-013 | 0000LU | Emit OnActivate `[0x57d080,0x57d097)` at position 30. | very-strong | vtable and body. | new OnActivate child | incorporate | implemented |
| C0000LU-014 | 0000LU | Classify `nullsub_54 [0x57d0b0,0x57d0b1)` as an ownerless disconnected dead-code artifact with no source child or CPP/H. | original-proof | one-byte `ret`, zero directional xrefs, zero pointer hits, absent from vtable. | UID0002RJ no-code inventory | reject-invalid | implemented |
| C0000LU-015 | 0000LU | Emit UpdateRenderRegion `[0x57d0c0,0x57d148)` at position 40. | very-strong | vtable, bounds constants, child/base calls. | new child | incorporate | implemented |
| C0000LU-016 | 0000LU | Emit SetBounds `[0x57d150,0x57d1f5)` at position 50. | very-strong | vtable, fixed mode bounds. | new child | incorporate | implemented |
| C0000LU-017 | 0000LU | Emit RebuildSpellList `[0x57d200,0x57d360)` at position 60. | very-strong | complete loop/limits/scroll sync. | new child | incorporate | implemented |
| C0000LU-018 | 0000LU | Emit OnScrollPositionChanged `[0x57d360,0x57d398)` at position 70. | original-proof | accepted name/type/comment and three callers. | new child | incorporate | implemented |
| C0000LU-019 | 0000LU | Emit AddToLayer `[0x57d3a0,0x57d406)` at position 80. | very-strong | vtable and parent/child order. | new child | incorporate | implemented |
| C0000LU-020 | 0000LU | Emit RemoveFromLayer `[0x57d410,0x57d426)` at position 90. | very-strong | vtable and child/base order. | new child | incorporate | implemented |
| C0000LU-021 | 0000LU | Emit OnPaint `[0x57d430,0x57d8c4)` at position 100. | very-strong | vtable, resources, row loop, render calls. | new child | incorporate | implemented |
| C0000LU-022 | 0000LU | Emit HandleKeyOrTextEvent `[0x57d8d0,0x57d9b1)` at position 110. | very-strong | event vtable and local calls. | new child | incorporate | implemented |
| C0000LU-023 | 0000LU | Emit HandlePointerOrMouseEvent `[0x57d9c0,0x57e18f)` at position 120. | very-strong | event vtable, gesture/timer/packet flow. | new child | incorporate | implemented |
| C0000LU-024 | 0000LU | Emit HandlePacketEvent `[0x57e1b0,0x57e1d8)` at position 130. | very-strong | event vtable and packet cases 23/24. | new child | incorporate | implemented |
| C0000LU-025 | 0000LU | Emit OnTimer `[0x57e1e0,0x57e2c1)` at position 140. | very-strong | timer vtable and IDs 1/2. | new child | incorporate | implemented |
| C0000LU-026 | 0000LU | Emit ActivateSpellSlot `[0x57e2d0,0x57e56d)` at position 150. | very-strong | nine-way switch and input-pane fanout. | new child | incorporate | implemented |
| C0000LU-027 | 0000LU | Emit raw SendSwapSpellPacket `[0x57e5a0,0x57e615)` at position 160. | strong | packet opcode `0x30`, subcode 1, length 4. | new child | incorporate | implemented |
| C0000LU-028 | 0000LU | Emit SendDirectSpellPacket `[0x57e620,0x57e689)` at position 170. | very-strong | caller, opcode `0x0f`, length 2. | new child | incorporate | implemented |
| C0000LU-029 | 0000LU | Emit GetButtonRect `[0x57e690,0x57e6e7)` at position 180. | very-strong | caller and exact rectangle. | new child | incorporate | implemented |
| C0000LU-030 | 0000LU | Emit raw BuildSpellRowRect `[0x57e6f0,0x57e75a)` at position 190. | strong | coherent bounds helper and limits. | new child | incorporate | implemented |
| C0000LU-031 | 0000LU | Emit raw HitTestButton `[0x57e760,0x57e7f4)` at position 200. | strong | coherent part loop and GetButtonRect use. | new child | incorporate | implemented |
| C0000LU-032 | 0000LU | Emit HitTestSpellRow `[0x57e800,0x57e8c8)` at position 210. | very-strong | six calls and row rectangles. | new child | incorporate | implemented |
| C0000LU-033 | 0000LU | Emit ResolveVisibleSpellSlot `[0x57e8d0,0x57e955)` at position 220. | very-strong | six calls and learned/expanded mapping. | new child | incorporate | implemented |
| C0000LU-034 | 0000LU | Emit raw BuildSpellRowOrigin `[0x57e960,0x57e99a)` at position 230. | strong | coherent Point helper and row stride. | new child | incorporate | implemented |
| C0000LU-035 | 0000LU | Emit StopActiveRepeatTimer `[0x57e9a0,0x57e9c5)` at position 240. | very-strong | two calls and timer cancel. | new child | incorporate | implemented |
| C0000LU-036 | 0000LU | Emit ToggleExpandedMode `[0x57e9d0,0x57ea57)` at position 250. | very-strong | two calls and relayout/rebuild flow. | new child | incorporate | implemented |
| C0000LU-037 | 0000LU | Supervisor applied and verified I01 constructor pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I01 | incorporate | APPLIED_VERIFIED |
| C0000LU-038 | 0000LU | Supervisor applied and verified I02 OnActivate pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I02 | incorporate | APPLIED_VERIFIED |
| C0000LU-039 | 0000LU | Supervisor applied and verified I03 UpdateRenderRegion pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I03 | incorporate | APPLIED_VERIFIED |
| C0000LU-040 | 0000LU | Supervisor applied and verified I04 SetBounds pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I04 | incorporate | APPLIED_VERIFIED |
| C0000LU-041 | 0000LU | Supervisor applied and verified I05 RebuildSpellList pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I05 | incorporate | APPLIED_VERIFIED |
| C0000LU-042 | 0000LU | Supervisor verified I06 OnScrollPositionChanged already present and exact; name, prototype, regular function comment, and every protected channel remain exact after save. | original-proof | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no endpoint. | IDA Gate 2B I06 | already-present | ALREADY_PRESENT_VERIFIED |
| C0000LU-043 | 0000LU | Supervisor applied and verified I07 AddToLayer pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I07 | incorporate | APPLIED_VERIFIED |
| C0000LU-044 | 0000LU | Supervisor applied and verified I08 RemoveFromLayer pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I08 | incorporate | APPLIED_VERIFIED |
| C0000LU-045 | 0000LU | Supervisor applied and verified I09 OnPaint pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I09 | incorporate | APPLIED_VERIFIED |
| C0000LU-046 | 0000LU | Supervisor applied and verified I10 key/text input pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I10 | incorporate | APPLIED_VERIFIED |
| C0000LU-047 | 0000LU | Supervisor applied and verified I11 pointer/mouse input pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I11 | incorporate | APPLIED_VERIFIED |
| C0000LU-048 | 0000LU | Supervisor applied and verified I12 packet events pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I12 | incorporate | APPLIED_VERIFIED |
| C0000LU-049 | 0000LU | Supervisor applied and verified I13 timer events pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I13 | incorporate | APPLIED_VERIFIED |
| C0000LU-050 | 0000LU | Supervisor applied and verified I14 spell activation pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I14 | incorporate | APPLIED_VERIFIED |
| C0000LU-051 | 0000LU | Supervisor applied and verified I15 direct packet pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I15 | incorporate | APPLIED_VERIFIED |
| C0000LU-052 | 0000LU | Supervisor applied and verified I16 button bounds pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I16 | incorporate | APPLIED_VERIFIED |
| C0000LU-053 | 0000LU | Supervisor applied and verified I17 row hit-test pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I17 | incorporate | APPLIED_VERIFIED |
| C0000LU-054 | 0000LU | Supervisor applied and verified I18 visible-slot resolution pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I18 | incorporate | APPLIED_VERIFIED |
| C0000LU-055 | 0000LU | Supervisor applied and verified I19 repeat-timer stop pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I19 | incorporate | APPLIED_VERIFIED |
| C0000LU-056 | 0000LU | Supervisor applied and verified I20 expanded-mode toggle pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I20 | incorporate | APPLIED_VERIFIED |
| C0000LU-057 | 0000LU | Supervisor applied and verified I21 exact regular raw-head destructor comment; raw physical item, function absence, and every protected channel remain exact after save. | strong | dated 2026-08-16 supervisor post-save raw-head readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B. | IDA Gate 2B I21 | incorporate | APPLIED_VERIFIED |
| C0000LU-058 | 0000LU | Supervisor applied and verified I22 exact regular raw-head swap helper comment; raw physical item, function absence, and every protected channel remain exact after save. | strong | dated 2026-08-16 supervisor post-save raw-head readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B. | IDA Gate 2B I22 | incorporate | APPLIED_VERIFIED |
| C0000LU-059 | 0000LU | Supervisor applied and verified I23 exact regular raw-head row-rect helper comment; raw physical item, function absence, and every protected channel remain exact after save. | strong | dated 2026-08-16 supervisor post-save raw-head readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B. | IDA Gate 2B I23 | incorporate | APPLIED_VERIFIED |
| C0000LU-060 | 0000LU | Supervisor applied and verified I24 exact regular raw-head button-hit helper comment; raw physical item, function absence, and every protected channel remain exact after save. | strong | dated 2026-08-16 supervisor post-save raw-head readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B. | IDA Gate 2B I24 | incorporate | APPLIED_VERIFIED |
| C0000LU-061 | 0000LU | Supervisor applied and verified I25 exact regular raw-head row-origin helper comment; raw physical item, function absence, and every protected channel remain exact after save. | strong | dated 2026-08-16 supervisor post-save raw-head readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B. | IDA Gate 2B I25 | incorporate | APPLIED_VERIFIED |
| C0000LU-062 | 0000LU | Supervisor verified P01 already present: the foreign ItemWho function remains exact in every protected channel after save. | original-proof | dated 2026-08-16 supervisor post-save bounded protection readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no endpoint. | IDA Gate 2B P01 | already-present | ALREADY_PRESENT_VERIFIED |
| C0000LU-063 | 0000LU | Supervisor verified P02 already present: disconnected nullsub physical identity, bytes, alignment, and zero-edge state remain exact without source ownership. | original-proof | dated 2026-08-16 supervisor post-save bounded protection readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no endpoint. | IDA Gate 2B P02 | already-present | ALREADY_PRESENT_VERIFIED |
| C0000LU-064 | 0000LU | Supervisor verified P03 already present: all 35 vtable dwords and successor boundary remain exact after save. | original-proof | dated 2026-08-16 supervisor post-save complete integer/hash readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no endpoint. | IDA Gate 2B P03 | already-present | ALREADY_PRESENT_VERIFIED |
| C0000LU-065 | 0000LU | Supervisor rejected P04 as invalid and verified no mutation: the protected stale shared UDT, types, and frames remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save UDT/protection readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no UDT/type/frame endpoint. | IDA Gate 2B P04 | reject-invalid | REJECT_INVALID_VERIFIED/NO_MUTATION |
| C0000LU-066 | 0000LU | Apply exact dependency-closed NewSpell CPP preamble, 25 bodies, complete `0x148` H declaration, and compile-visible guarded support-header graph. | strong | complete inventory, live bodies, and dated command-24621 physical generated API/read-order audit. | UID00009A, 25 child formal CPP/H, and formal support H routes | incorporate | implemented |
| C0000LU-067 | 0000LU | Move Scroll declaration to H, keep CPP include/children, and add NewSpell friendship. | strong | separate-file callback access. | UID0000CN formal CPP/H | incorporate | implemented |
| C0000LU-068 | 0000LU | Keep by-file and aggregate/core formal blocks blank; source emits through class/children. | very-strong | routing rules and mixed parent. | UID0000LU/UID0002RJ formal channels | not-applicable | verified |
| C0000LU-069 | 0000LU | Incorporate complete inventory/behavior/evidence into target and class, including exact one-byte padding and guarded dependency/include topology. | very-strong | this report plus dated command-24621 physical readback. | target/class prose | incorporate | implemented |
| C0000LU-070 | 0000LU | Create 25 exact by-memory source children with specified metadata/order/source; create no nullsub child. | very-strong | exact boundaries and formal bodies. | new support docs | incorporate | implemented |
| C0000LU-071 | 0000LU | Update broad/core/scalar/macro plus UserPane, input-pane, HelpPanes, DialogPane, MapPane, LivingObjectPane, BackPane, pointer/packet boundaries, SpellInventoryPane, and shared-helper support without losing history; preserve all declarations while adding guards/includes/padding. | very-strong | reconciled support/dependency/header/padding inventory. | existing support docs | incorporate | implemented |
| C0000LU-072 | 0000LU | Raise target/class/core to `94/95`, `94/95`, and `94/95`; core becomes non-reconstructable split index. | strong | blocker removal and exact split. | metadata/manual rows | incorporate | implemented |
| C0000LU-073 | 0000LU | Score 25 source children `91-94/94-96` and layout `94/95`; assign no score/page to ownerless nullsub. | strong | target-specific evidence depth and blocker closure. | new metadata/manual rows | incorporate | implemented |
| C0000LU-074 | 0000LU | Apply only under supervisor authority the corrected complete literal Section 28 manual coverage payload: UID0000LU, UID00009A, UID0002RJ, all 25 child rows UID00052F-000533 immediately beneath UID0002RJ in source-position order, UID0002RL, UID000534, and the no-loss Scroll UID0000NJ/UID0000CN replacements. | very-strong | dated manual-row readback; formal-body reconciliation of UID00052H rebuild/invalidate, UID00052P translated key handling, UID00052Q event-type pointer switch, UID00052W fixed local button bounds, UID000531 local row origin, and exact Scroll declaration-in-H, CPP include/children, and NewSpell friendship. | four manual coverage files; corrected complete literal Section 28 payload | already-present | already-present-verified |
| C0000LU-075 | 0000LU | Treat command `000000024100` generated CPP only as dated empty-emitter evidence. | original-proof | physical dated readback/hash. | report/docs history | historicalize | historicalized |
| C0000LU-076 | 0000LU | Run scoped validators for every changed ordinary destination after callback and additive repair; record every correction receipt. | very-strong | commands 24591-24615 and 24618-24620; all exit 0/ok 1. | Validator Results | incorporate | validated |
| C0000LU-077 | 0000LU | Run the final owning-route waited refresh and physically reconcile target plus all affected support CPP/H, including UserPane, guards, include order, declarations, duplicates, and exact target source order. | very-strong | command 24621 physical readback. | Validator Results/generated readback | incorporate | verified |
| C0000LU-078 | 0000LU | Historicalize stale empty-emitter, raw-exclusion, old gate/layout/fold rationales and all current-tense pre-callback future-child/helper/score/blank-blocked statements in target, class, core, and aggregate. | very-strong | current contrary implementation and generated evidence. | Changes/evidence sections and four dated snapshots | reject-stale | historicalized |
| C0000LU-079 | 0000LU | Keep report prose lifecycle-neutral and leave lifecycle authority to supervisor/validator metadata. | very-strong | workflow. | report body/checklist | already-present | already-present-verified |
| C0000LU-080 | 0000LU | During the accepted report-only phase, no ordinary docs, generated files, coverage, validator state, IDA, or lifecycle state changed. | original-proof | pre-callback changed-file audit. | Changed Files | not-applicable | historical-verified |

## Positive Evidence Summary

- The sole constructor caller allocates exactly `0x148`, then calls `0x57cf70`; the constructor installs all three NewSpell vtable views and initializes every recovered tail field.
- The core has stable class-local call flow: activation/layout/paint/input/timer/toggle converge on `RebuildSpellList`; pointer input reaches hit-test/resolve/activate/packet helpers; Scroll calls the accepted owner callback.
- Vtable entries directly bind the virtual lifecycle, render, event, packet, and timer bodies to NewSpellInventoryPane.
- Five raw bodies have complete control flow and semantic roles that fill otherwise missing ordinary/helper source; exact padding cleanly separates them.
- Pointer-handler source ends exactly at `0x0057e18f`; one byte of alignment `[0x0057e18f,0x0057e190)` precedes its switch table and is independently documented by both adjacent children and all aggregate inventories.
- Resource xrefs, packet opcodes, record stride, mode bounds, row counts, and all tail offsets agree across independent functions.
- Separate Scroll source is corroborated by a complete standalone class/vtable/core route while normal header access explains the owner callback.
- Dated command-24621 physical output proves one guard per repaired assembled support header, `InputPanes.h` before the first NumberArgs derivation, complete LivingObjectPane before UserPane derivation, zero header child placeholders, and no target CPP class redeclaration despite direct plus MapPane-mediated UserPane inclusion.
- The dated full pre-application I01-I25/P01-P04 requery changed only the nine protected prototype literals listed in Current Target State; all ranges, names, comments, complete frames, byte hashes, directional xrefs, raw-item/function-absence facts, vtable words/boundary, and shared UDT facts independently matched. The later supervisor transaction preserved those channels and verified the final names/comments and all protections after save.

## IDA MCP Facts

- Dated pre-application health/session facts and B009 no-mutation attestation are in `Supervisor Active Recheck`; the literal I/P table preserves that prestate and records the supervisor-verified saved poststate.
- Recognized NewSpell functions and exact ranges are the 20 source-function rows in the inventory. The foreign function and disconnected recognized `nullsub_54` item are explicitly separate and neither is a NewSpell source definition.
- Dated pre-application `inspect_items` changed exactly nine prototype observations relative to the rejected report artifact: `57d080 int __thiscall(char *this, int)`; `57d0c0 __int16 __thiscall(_DWORD **this, struct RectBounds *)`; `57d3a0 __int16 __thiscall(Pane *this, RectBounds *bounds, int order, Pane *previousPane, Layer *layer)`; `57d410 void __thiscall(int this)`; `57d430 void __thiscall(int this)`; `57e1e0 char __thiscall(TimerHandler *this, int, int, int)`; `57e620 void __stdcall(unsigned __int8)`; `57e690 void __stdcall(__int16, struct RectBounds *bounds)`; `57e9a0 void __thiscall(TimerHandler *this)`. The other eleven I01-I20 prototypes matched. The supervisor used no type endpoint, and post-save readback preserved every one of these prototypes.
- Raw source bodies: `[0x57d040,0x57d075)`, `[0x57e5a0,0x57e615)`, `[0x57e6f0,0x57e75a)`, `[0x57e760,0x57e7f4)`, `[0x57e960,0x57e99a)`; the dated pre-application state had each entry as code, a one-byte physical item, blank name/type/comment, no incoming xref, and one outgoing fallthrough xref to the next byte. The saved poststate retains every physical/function-absence/xref fact and adds only the exact regular AR comment listed in I21-I25.
- Supervisor Gate 2B disposition is final for this report: I01-I05/I07-I20 and I21-I25 `APPLIED_VERIFIED`; I06 and P01-P03 `ALREADY_PRESENT_VERIFIED`; P04 `REJECT_INVALID_VERIFIED/NO_MUTATION`. `idb_save` and fresh post-save attestation/readback passed against saved canonical SHA256 `C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B`.
- UDT facts: `PanelPane 0xf8`; stale `NewSpellInventoryPane 0x100`; correct `ScrollSpellInventoryPane 0x110`; `RectBounds 0x10`; `Event 0x110`.
- Allocation fact: `GeneralPurposePanel__Constructor` at `0x4b84b6` allocates `0x148`, calls `sub_57CF70` at `0x4b84cb`, and stores it as child index 3.
- Vtable words: `62d064->650690, 68->57f5d0, 6c->4f4b10, 70->41b6c0, 74->57d0c0, 78->41d680, 7c->544730, 80->544750, 84->5447a0, 88->544800, 8c->544a20, 90->544b80, 94->57d150, 98->57d3a0, 9c->544cb0, a0->57d410, a4->544d30, a8->544d70, ac->57d430, b0->57d080, b4->6506f0, b8->57f58b, bc->57d9c0, c0->57d8d0, c4->544dd0, c8->57e1b0, cc->544df0, d0->544e00, d4->4a89f0, d8->544e10, dc->544e30, e0->544e70, e4->650704, e8->57f596, ec->57e1e0`; `0x62d0f0->0x650718` is the next SpellInventoryPane2 locator.
- Exact full core physical SHA256 is `C19D2185297666B6A68FC33BC73CE9067644BC3CCB7AEE0E73F121DE5DD63CB1`; vtable cluster SHA256 is `10229014E8D79730C6F31369235F111DCC181F9B8DFE2C8A1BBABA455253391A`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `[57cf70,57d03f)` | [UID:00052F][Constructor](by-memory/0x0057cf70-0x0057d03f.NewSpellInventoryPaneConstructor.md) | constructor | true | 00009A | 94/96 | implemented and scoped-validated; exact formal CPP emitted |
| `[57d03f,57d040)` | core | 1-byte `cc` pad | false | 0002RJ | n/a | parent evidence only |
| `[57d040,57d075)` | [UID:00052G][Destructor](by-memory/0x0057d040-0x0057d075.NewSpellInventoryPaneDestructor.md) | ordinary destructor raw body | true | 00009A | 92/95 | implemented and scoped-validated; exact formal CPP emitted |
| `[57d075,57d080)` | core | 11-byte pad | false | 0002RJ | n/a | parent evidence only |
| `[57d080,57d097)` | [UID:00052H][OnActivate](by-memory/0x0057d080-0x0057d097.NewSpellInventoryPaneOnActivate.md) | activation virtual | true | 00009A | 93/95 | implemented and scoped-validated; exact formal CPP emitted |
| `[57d097,57d0a0)` | core | 9-byte pad | false | 0002RJ | n/a | parent evidence only |
| `[57d0a0,57d0b0)` | UID0001IJ | foreign ItemWho setter | true | UID00006Y | existing | excluded/protected |
| `[57d0b0,57d0b1)` | no page/UID; P02 protection only | ownerless disconnected one-byte dead-code artifact, no class slot | false | NONE | n/a | no child, emitter, CPP, or H; physical item protected |
| `[57d0b1,57d0c0)` | core | 15-byte pad | false | 0002RJ | n/a | parent evidence only |
| `[57d0c0,57d148)` | [UID:00052I][UpdateRenderRegion](by-memory/0x0057d0c0-0x0057d148.NewSpellInventoryPaneUpdateRenderRegion.md) | child/base layout update | true | 00009A | 93/95 | implemented and scoped-validated; exact formal CPP emitted |
| `[57d148,57d150)` | core | 8-byte pad | false | 0002RJ | n/a | parent evidence only |
| `[57d150,57d1f5)` | [UID:00052J][SetBounds](by-memory/0x0057d150-0x0057d1f5.NewSpellInventoryPaneSetBounds.md) | fixed collapsed/expanded bounds | true | 00009A | 93/95 | implemented and scoped-validated; exact formal CPP emitted |
| `[57d1f5,57d200)` | core | 11-byte pad | false | 0002RJ | n/a | parent evidence only |
| `[57d200,57d360)` | [UID:00052K][RebuildSpellList](by-memory/0x0057d200-0x0057d360.NewSpellInventoryPaneRebuildSpellList.md) | learned list and scrollbar sync | true | 00009A | 94/96 | implemented and scoped-validated; exact formal CPP emitted |
| `[57d360,57d398)` | [UID:00052L][OnScrollPositionChanged](by-memory/0x0057d360-0x0057d398.NewSpellInventoryPaneOnScrollPositionChanged.md) | owner callback | true | 00009A | 94/96 | implemented and scoped-validated; exact formal CPP emitted; accepted IDA source name preserved |
| `[57d398,57d3a0)` | core | 8-byte pad | false | 0002RJ | n/a | parent evidence only |
| `[57d3a0,57d406)` | [UID:00052M][AddToLayer](by-memory/0x0057d3a0-0x0057d406.NewSpellInventoryPaneAddToLayer.md) | attach base then child | true | 00009A | 93/95 | implemented and scoped-validated; exact formal CPP emitted |
| `[57d406,57d410)` | core | 10-byte pad | false | 0002RJ | n/a | parent evidence only |
| `[57d410,57d426)` | [UID:00052N][RemoveFromLayer](by-memory/0x0057d410-0x0057d426.NewSpellInventoryPaneRemoveFromLayer.md) | detach child then base | true | 00009A | 93/95 | implemented and scoped-validated; exact formal CPP emitted |
| `[57d426,57d430)` | core | 10-byte pad | false | 0002RJ | n/a | parent evidence only |
| `[57d430,57d8c4)` | [UID:00052O][OnPaint](by-memory/0x0057d430-0x0057d8c4.NewSpellInventoryPaneOnPaint.md) | full background/list/button render | true | 00009A | 93/95 | implemented and scoped-validated; exact formal CPP emitted |
| `[57d8c4,57d8d0)` | core | 12-byte pad | false | 0002RJ | n/a | parent evidence only |
| `[57d8d0,57d9b1)` | [UID:00052P][HandleKeyOrTextEvent](by-memory/0x0057d8d0-0x0057d9b1.NewSpellInventoryPaneHandleKeyOrTextEvent.md) | keyboard/page/expand input | true | 00009A | 93/95 | implemented and scoped-validated; exact formal CPP emitted |
| `[57d9b1,57d9c0)` | core | 15-byte pad | false | 0002RJ | n/a | parent evidence only |
| `[57d9c0,57e18f)` | [UID:00052Q][HandlePointerOrMouseEvent](by-memory/0x0057d9c0-0x0057e18f.NewSpellInventoryPaneHandlePointerOrMouseEvent.md) | pointer/drag/swap/cast/wheel bridge | true | 00009A | 93/95 | implemented and scoped-validated; exact formal CPP emitted |
| `[57e18f,57e190)` | core | 1-byte pad | false | 0002RJ | n/a | parent evidence only |
| `[57e190,57e1b0)` | core | 8-entry pointer-event switch table | false | 0002RJ | n/a | compiler-covered |
| `[57e1b0,57e1d8)` | [UID:00052R][HandlePacketEvent](by-memory/0x0057e1b0-0x0057e1d8.NewSpellInventoryPaneHandlePacketEvent.md) | packet 23/24 activation refresh | true | 00009A | 93/95 | implemented and scoped-validated; exact formal CPP emitted |
| `[57e1d8,57e1e0)` | core | 8-byte pad | false | 0002RJ | n/a | parent evidence only |
| `[57e1e0,57e2c1)` | [UID:00052S][OnTimer](by-memory/0x0057e1e0-0x0057e2c1.NewSpellInventoryPaneOnTimer.md) | repeat scroll timer IDs 1/2 | true | 00009A | 93/95 | implemented and scoped-validated; exact formal CPP emitted |
| `[57e2c1,57e2d0)` | core | 15-byte pad | false | 0002RJ | n/a | parent evidence only |
| `[57e2d0,57e56d)` | [UID:00052T][ActivateSpellSlot](by-memory/0x0057e2d0-0x0057e56d.NewSpellInventoryPaneActivateSpellSlot.md) | nine-route cast dispatcher | true | 00009A | 94/96 | implemented and scoped-validated; exact formal CPP emitted |
| `[57e56d,57e570)` | core | 3-byte pad | false | 0002RJ | n/a | parent evidence only |
| `[57e570,57e594)` | core | 9-entry spell-route switch table | false | 0002RJ | n/a | compiler-covered by ActivateSpellSlot |
| `[57e594,57e5a0)` | core | 12-byte pad | false | 0002RJ | n/a | parent evidence only |
| `[57e5a0,57e615)` | [UID:00052U][SendSwapSpellPacket](by-memory/0x0057e5a0-0x0057e615.NewSpellInventoryPaneSendSwapSpellPacket.md) | raw file-static opcode `0x30` helper | true | 00009A | 92/95 | implemented and scoped-validated; exact formal CPP emitted |
| `[57e615,57e620)` | core | 11-byte pad | false | 0002RJ | n/a | parent evidence only |
| `[57e620,57e689)` | [UID:00052V][SendDirectSpellPacket](by-memory/0x0057e620-0x0057e689.NewSpellInventoryPaneSendDirectSpellPacket.md) | opcode `0x0f` helper | true | 00009A | 93/95 | implemented and scoped-validated; exact formal CPP emitted |
| `[57e689,57e690)` | core | 7-byte pad | false | 0002RJ | n/a | parent evidence only |
| `[57e690,57e6e7)` | [UID:00052W][GetButtonRect](by-memory/0x0057e690-0x0057e6e7.NewSpellInventoryPaneGetButtonRect.md) | file-static expand-button rectangle | true | 00009A | 93/95 | implemented and scoped-validated; exact formal CPP emitted |
| `[57e6e7,57e6f0)` | core | 9-byte pad | false | 0002RJ | n/a | parent evidence only |
| `[57e6f0,57e75a)` | [UID:00052X][BuildSpellRowRect](by-memory/0x0057e6f0-0x0057e75a.NewSpellInventoryPaneBuildSpellRowRect.md) | raw member row bounds helper | true | 00009A | 92/95 | implemented and scoped-validated; exact formal CPP emitted |
| `[57e75a,57e760)` | core | 6-byte pad | false | 0002RJ | n/a | parent evidence only |
| `[57e760,57e7f4)` | [UID:00052Y][HitTestButton](by-memory/0x0057e760-0x0057e7f4.NewSpellInventoryPaneHitTestButton.md) | raw file-static button-part hit-test | true | 00009A | 92/95 | implemented and scoped-validated; exact formal CPP emitted |
| `[57e7f4,57e800)` | core | 12-byte pad | false | 0002RJ | n/a | parent evidence only |
| `[57e800,57e8c8)` | [UID:00052Z][HitTestSpellRow](by-memory/0x0057e800-0x0057e8c8.NewSpellInventoryPaneHitTestSpellRow.md) | row hit-test | true | 00009A | 93/95 | implemented and scoped-validated; exact formal CPP emitted |
| `[57e8c8,57e8d0)` | core | 8-byte pad | false | 0002RJ | n/a | parent evidence only |
| `[57e8d0,57e955)` | [UID:000530][ResolveVisibleSpellSlot](by-memory/0x0057e8d0-0x0057e955.NewSpellInventoryPaneResolveVisibleSpellSlot.md) | row/ordinal to one-based slot | true | 00009A | 93/95 | implemented and scoped-validated; exact formal CPP emitted |
| `[57e955,57e960)` | core | 11-byte pad | false | 0002RJ | n/a | parent evidence only |
| `[57e960,57e99a)` | [UID:000531][BuildSpellRowOrigin](by-memory/0x0057e960-0x0057e99a.NewSpellInventoryPaneBuildSpellRowOrigin.md) | raw member text origin helper | true | 00009A | 92/95 | implemented and scoped-validated; exact formal CPP emitted |
| `[57e99a,57e9a0)` | core | 6-byte pad | false | 0002RJ | n/a | parent evidence only |
| `[57e9a0,57e9c5)` | [UID:000532][StopActiveRepeatTimer](by-memory/0x0057e9a0-0x0057e9c5.NewSpellInventoryPaneStopActiveRepeatTimer.md) | cancel/reset repeat timer | true | 00009A | 93/95 | implemented and scoped-validated; exact formal CPP emitted |
| `[57e9c5,57e9d0)` | core | 11-byte pad | false | 0002RJ | n/a | parent evidence only |
| `[57e9d0,57ea57)` | [UID:000533][ToggleExpandedMode](by-memory/0x0057e9d0-0x0057ea57.NewSpellInventoryPaneToggleExpandedMode.md) | relayout/rebuild/invalidate toggle | true | 00009A | 93/95 | implemented and scoped-validated; exact formal CPP emitted |
| `[57ea57,57ea60)` | broad parent | exact 9-byte post-target alignment | false | 0001IH | n/a | ends before SpellInventoryPane2 |
| `[57cf6b,57cf70)` | broad parent | 5-byte pre-target alignment | false | 0001IH | n/a | predecessor returns at `57cf68` |
| `[57f5d0,57f637)` | UID0002RL | scalar deleting wrapper | false | UID0002RL | existing 91/93 | compiler-generated; no source |
| `[57f58b,57f596)` | UID0002RL | event-view dtor adjustor | false | UID0002RL | existing | compiler-generated; no source |
| `[57f596,57f5a1)` | UID0002RL | timer-view dtor adjustor | false | UID0002RL | existing | compiler-generated; no source |
| `[62d064,62d0f0)` | macro `.rdata` | 35 dwords: RTTI + three vtable views | false | macro page | existing 87/92 | compiler data; exact words preserved |
| `608776,60879f,608814` | core/compiler | EH/cookie records | false | core | n/a | compiler-covered |
| NewSpell layout `0x148` | [UID:000534][NewSpellInventoryPaneLayout](by-type/by-struct/NewSpellInventoryPaneLayout.md) | base/tail field declaration | true | 00009A | 94/95 | implemented and scoped-validated; class H is sole declaration |
| resources | UID0003BX | `SPELLINV.EPF`, `ITEMINVE.EPF`, `ITEMINV.PAL`, `INVENBUT.EPF`, `invenbut.pal`, `%c`, `%s`, `...` | false | NONE/shared | 85/89 | exact use-site literals already present |
| globals | existing by-global owners | `g_pUserPane`, `g_pEPFLib`, `g_pEventMan`, `g_pConfig`, `g_packetSender`, `g_activeMapPane`, `g_pBackPane`, layer/gate/render callback | false here | external owners | existing | dependencies only; no file-owned storage |
| Scroll companion | UIDs 0000NJ/0000CN/0001GM/0001W1/0001YS/0001GN/0001GO | separate private child scrollbar source/header | true | 0000NJ | existing | keep separate; header route repair only |

Reconciliation totals: 20 recognized NewSpell source functions, five raw NewSpell source definitions, one ownerless disconnected recognized function item, one foreign recognized function, two switch tables, 27 listed alignment/padding spans including `[57e18f,57e190)` plus the pre/post boundaries, one scalar wrapper, two adjustors, three EH/cookie records, one 35-dword vtable cluster, one class layout, one resource family, one external-global family, and one separate companion source family. No known source-bearing item is left as a sampled or generic future row.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `57cf70` | incoming `{4b84cb code}`; outgoing entry `{57cf70->57cf71 code}`; calls `{545090 PanelPane ctor,4f4aa0 operator new,55f450 Scroll ctor,55f5f0 Scroll activate}` | sole `0x148` object construction route |
| `57d040` | incoming absent; outgoing `{57d040->57d041 code}` | raw ordinary destructor; no modeled caller/pointer |
| `57d080` | incoming `{62d0b0 data}`; outgoing `{57d080->57d081 code}`; calls `{57d200}` | primary activation virtual |
| `57d0a0` | 17 incoming code refs exactly `{5a3fda,5ae029,5ae3d9,5aedaf,5b0869,5b0ba9,5b0e89,5b1119,5b1369,5b7a96,5b7c80,5b7d50,5b7e20,5b7ef0,5b7fc0,5b8090,5b8160}` | foreign input-state setter |
| `57d0b0` | incoming absent; outgoing absent; callees absent; little-endian VA pointer search `B0 D0 57 00` has zero hits; complete NewSpell vtable map has no `57d0b0` word | ownerless disconnected dead-code artifact; no source or ABI route |
| `57d0c0` | incoming `{62d074 data}`; calls `{4b7c50,4b8e20,57d200,5c772f}` | layout virtual |
| `57d150` | incoming `{62d094 data}`; calls `{4b78d0,4b7c30,4b7e10,5c772f}` | bounds virtual |
| `57d200` | incoming `{57d083,57d131,57d383,57d3ef,57d47b,57d91d,57d96b,57e241,57e299,57ea38}`; calls `{55f560,55f5c0}` | central rebuild helper |
| `57d360` | incoming `{560885,57da5e,57da79}`; calls `{55f5c0,57d200}` | Scroll callback plus two owner-input calls |
| `57d3a0` | incoming `{62d098 data}`; calls `{544c70,57d200,5c772f}` | layer attach virtual |
| `57d410` | incoming `{62d0a0 data}`; direct virtual child/base tails | layer detach virtual |
| `57d430` | incoming `{62d0ac data}`; calls `{457a60,57d200,4d02f0,4b9980,4b9690,4b78d0,4b78f0,4b9660,69b3fc,5a4090,41b9b0,4b9680,4bad70,4ba820,4b7c50,5c772f}` | full render virtual |
| `57d8d0` | incoming `{62d0c0 data}`; calls `{4a8b10,57d200,57e9d0}` | key/text event virtual |
| `57d9c0` | incoming `{62d0bc data}`; calls `{4b7e80,57d360,57e800,57e8d0,5975e0,57e9a0,57e690,4b7c50,57e9d0,4b7c30,4f4aa0,4c7f90,575380,574bb0,57e2d0,5c772f}` | pointer/mouse event virtual |
| `57e1b0` | incoming `{62d0c8 data}`; callees absent | packet event virtual |
| `57e1e0` | incoming `{62d0ec data}`; calls `{55f5c0,57d200,5975e0}` | timer virtual |
| `57e2d0` | incoming `{57e122 code}`; calls `{4f4aa0,5adf40,5374d0,5af4f0,5ae2a0,5b0780,5b0ac0,5b0da0,5b1030,5b1280,57e620}` | cast/prompt dispatcher |
| `57e5a0` | incoming absent; outgoing `{57e5a0->57e5a1 code}` | raw swap packet helper |
| `57e620` | incoming `{57e54d code}`; calls `{575380,574bb0,5c772f}` | direct packet helper |
| `57e690` | incoming `{57dcd7 code}`; calls `{4b7c50}` | button bounds helper |
| `57e6f0` | incoming absent; outgoing `{57e6f0->57e6f1 code}` | raw row bounds helper |
| `57e760` | incoming absent; outgoing `{57e760->57e761 code}` | raw button hit-test helper |
| `57e800` | incoming `{57da9e,57dc7a,57ddd1,57df84,57e0c3}`; calls `{4b7c50,4b7e80,5c772f}` | row hit-test helper |
| `57e8d0` | incoming `{57dad4,57daf6,57dcb0,57de19,57dfd1,57e0f9}`; callees absent | visible-slot resolver |
| `57e960` | incoming absent; outgoing `{57e960->57e961 code}` | raw row origin helper |
| `57e9a0` | incoming `{57dc22,57df4c}`; calls `{597610}` | active repeat timer stop |
| `57e9d0` | incoming `{57d995,57de72}`; calls `{57d200,5c772f}` | expanded-mode toggle |
| vtable cluster | incoming constructor stores to view bases `62d068,62d0b8,62d0e8`; words route all listed virtuals and compiler wrappers | exact class identity and virtual ownership |
| resources/globals | all are reads/calls from NewSpell bodies; no defining write/storage interval in the compilation-unit core | external dependencies, not file-owned definitions |

Every recognized source function entry has one outgoing entry-head flow xref to its next instruction byte; those entry-head flows are preserved in the IDA rows. Raw entries have the same one-byte fallthrough. `nullsub_54` alone has no incoming or outgoing edge. Full internal CFG edges are unchanged and are not proposed mutation targets.

## Documentation Evidence And IDA Status

- Supporting docs now establish the complete file/class/core route, 25 exact children, UID000534 layout, foreign/null/compiler exclusions, vtables, child scrollbar, learned-list model, packets, resources, globals, and broad split boundaries.
- Historical stale statements about raw exclusion, deferred children, absent layout, blank class formal channels, old helpers, old scores, and no emitted children are preserved inside explicitly dated pre-callback snapshots on the target, class, core, and broad aggregate. The supervisor-owned manual coverage rows are now independently verified exact and scoped-validated without content changes.
- Scroll docs now preserve their rich behavior while routing the complete declaration through H, CPP through the owner include/children, and NewSpell friendship without duplicate local declarations.
- Supervisor Gate 2A passed all 65 report claims; this report preserves that accepted ordinary-document and generated-readback evidence without re-running validators or changing any destination.
- Command `000000024100` is dated empty-emitter evidence; commands `000000024420`, `000000024427`, `000000024428`, and `000000024429` plus their physical hashes establish only the dated accepted-callback implementation readback recorded below. Dated repair-time command `000000024441` is a separate observation, not permanent current authority.
- Commands `000000024591` through `000000024620` are dated additive-repair scoped receipts; final waited command `000000024621` and its 14 physical artifact hashes are a dated repair snapshot, not permanent generated authority.
- Supervisor Gate 2B is independently applied, verified, and saved. Its dated transaction changed only the accepted function names/regular comments and raw-head regular comments, left every protected type/frame/range/byte/xref/data/UDT channel exact, and produced the saved canonical identity recorded in Current Target State and Changed Files.

## Ranked Ownership Analysis

### 1. UID0000LU file route / UID00009A direct class emitter

- Evidence for: file path already selected; all owned bodies share NewSpell vtables, tail fields, resources, input/cast model, and GeneralPurposePanel construction; class route is current metadata.
- Evidence against: broad core contains one foreign body and compiler artifacts.
- Decision: accepted with exact children; mixed artifacts are excluded/protected rather than moved into source.

### 2. Standalone ScrollSpellInventoryPane companion

- Evidence for: complete separate class/core/vtable/exact children and current source route; only owner callback needs visibility.
- Evidence against: sole constructor caller and private use strongly couple it to NewSpell.
- Decision: retain separate private companion file and repair H visibility. Coupling does not prove same physical source file.

### 3. Rejected alternatives

- Broad UID0002RJ as monolithic emitter: rejected because it mixes source, foreign code, tables, raw items, and padding.
- UID0001IH broad SpellInventoryPanes: rejected because it is a non-emitting physical index over legacy/new/Pane2/compiler regions.
- Legacy SpellInventoryPane or SpellInventoryPane2 source: rejected by distinct constructor allocation, vtables, exact boundaries, and fields.
- TargetSelectionInputPanes: owns the foreign setter plus external `SpellWhoInputPane` and `SendTargetedActionPacket` dependencies, but no NewSpell body.
- Generic ScrollBar: conceptual sibling, not owner of feature-specific Scroll/NewSpell source.

### Implemented file/grouping

- Proposed owner/name/path: no new file root; complete current `NexusTK/ui/inventory/NewSpellInventoryPane.cpp` and sibling `.h`.
- Likely full contents: class preamble, 25 definitions in address/source order, private file-static packet/button helpers, exact children route.
- Candidate related items rejected: foreign setter, scalar wrapper/adjustors, vtable/EH/switch tables as handwritten source, Scroll method bodies, legacy and Pane2 code.
- Scope: one narrow feature class file with a separate private Scroll companion file.

## Source Placement

- NewSpell declarations belong in `NewSpellInventoryPane.h` generated by UID00009A H; definitions belong in exact children emitted into `NewSpellInventoryPane.cpp` through UID00009A CPP `[[CHILDREN]]`.
- File-static helpers are `SendSwapSpellPacket`, `SendDirectSpellPacket`, `GetButtonRect`, and `HitTestButton`; owner-state helpers remain private members. The slot-hotkey mapping is written inline because no current active exact page/header owns `0x5a4090`; this follows current InventoryPane source precedent and removes a report-only declaration.
- Scroll declarations belong in `ScrollSpellInventoryPane.h`; its implementations remain in its standalone CPP. `friend class NewSpellInventoryPane` permits the owner to synchronize the private range/position fields used by exact binary behavior.
- Cross-file declarations required by the formal body remain with existing owners: UID0000FQ UserPane grants NewSpell friendship for `GetSpellCommandSlotRecord`; UIDs 0000DU/0000DL/0000DV/0000DW/0000DR move their accepted declarations from SpellInputPanes CPP to H; UID0000DX supplies the complete `SpellWhoInputPane` H declaration; UID0001L9 changes its existing definition from file-static to external and supplies the exact H declaration; UID0000G6 moves `WillBeChangedSpellPane` to HelpPanes H; UID0000PQ/UID0001PH supply `extern signed char g_activeDialogCount`; UID0000PR supplies `extern MapPane *g_activeMapPane`; UID00028J supplies `extern BackPane *g_pBackPane` through a BackPane H route. UID0000T6, UID0000TN, UID0003YJ, UID0000Q5, UID00006E, UID00004O, and UID00028Q already expose the remaining exact contracts.
- Header assembly is now deterministic and C++03-safe. UID0000DL opens SpellInputPanes' guard and includes `InputPanes.h` before all NumberArgs-derived classes; UID0000DW closes it. UID0001L9/UID0000DX open/close TargetSelectionInputPanes. UID00007Q/UID0000PR, UID00007B, UID00000S/UID00028J, and UID0000FQ/UID0004YC similarly bound MapPane, LivingObjectPane, BackPane, and UserPane. UserPane includes `<stddef.h>` and `../../map/LivingObjectPane.h`; MapPane and NewSpell may include UserPane again because the guard prevents duplicate declarations.
- Rejected placements are enumerated in Ranked Ownership Analysis. No placement uncertainty remains beyond unknowable historical file organization, and the chosen structure minimizes duplicate declarations while preserving current project routing.

## Range / Split / Padding / Reclassification Analysis

- Exact source core is `[0x57cf70,0x57ea57)`. Pre-alignment `[0x57cf6b,0x57cf70)` belongs to broad parent; post-alignment `[0x57ea57,0x57ea60)` separates Pane2.
- Exact function/raw/table/padding order is the Function / Child Inventory; no interior bytes are unclassified. In particular, the pointer body `[0x57d9c0,0x57e18f)`, one-byte pad `[0x57e18f,0x57e190)`, switch table `[0x57e190,0x57e1b0)`, and packet body `[0x57e1b0,0x57e1d8)` are four independent physical partitions.
- UID0002RJ is `RECONSTRUCTABLE:FALSE`, with owner/emitter retained for relationship, blank formal channels, and 25 exact source children. It is a detailed non-emitting split/index and records ownerless `nullsub_54` as a no-code physical item, not a child.
- Raw bodies are reclassified from context-only to source children, but IDA physical state remains raw: no `define_func`, type, frame, or name mutation is recommended.
- Switch tables remain covered by their owning methods; padding, EH/cookie records, vtable data, wrapper, and thunks remain compiler-covered.

## Negative Evidence Summary

- No file-owned global/static storage exists in the core or adjacent `.rdata`; all global/resource operands resolve to shared support owners.
- Zero incoming xrefs at five raw starts do not prove dead bytes. Conversely, no static pointer/vtable route was found, so this report does not claim recovered call provenance or recommend IDA function creation.
- The current IDA UDT is contradicted by allocation/writes and must not drive source layout. The report also does not propose risky public parser/UDT mutation.
- The foreign setter's physical overlap does not prove NewSpell ownership; 17 external callers and accepted owner/type/comment prove the opposite.
- The Scroll constructor's sole NewSpell caller proves private coupling, not necessarily same-source folding; independent class/vtable/file structure is stronger placement evidence.
- `nullsub_54` has no incoming/outgoing xref, no encoded pointer, no NewSpell vtable cell, no class declaration slot, and no state access. Adjacency between foreign UID0001IJ and alignment is insufficient ownership evidence; a source-empty virtual classification is therefore rejected.
- The renewed endpoint audit found no basis to alter any prototype, frame, range, byte, xref, protected identity, vtable word, or UDT. The supervisor therefore applied only 19 pure function renames with regular function comments and five raw regular comments, recognized I06/P01-P03 as already exact, rejected P04 without mutation, and verified all constraints after save.

## IDA Rename / Type / Comment Recommendations

Public endpoint binding was exact: actionable recognized functions used `rename` with `pure:true`, then `set_function_comments`; raw code items used `set_address_comments`. No row used `define_func`, `set_type`, local/frame mutation, data mutation, UDT mutation, or type-parser installation. The supervisor owned the completed Gate 2B transaction.

The literal prestates below were renewed read-only across every I01-I25/P01-P04 endpoint in dated session `supervisor_uid0003d9_rollback_20260815`. `inspect_items`, `lookup_funcs`, `get_comments`, `stack_frame`, directional `xref_query`, exact `get_bytes` hashes, complete P03 integer reads, and P04 `type_inspect` were reconciled together. The later dated supervisor transaction in session `supervisor_uid0000li_i37rollback2_20260816` reached every listed poststate, saved it, and passed fresh bounded readback without any `set_type` action.

Frame literals used below are current full frame maps and must remain exact: F01 `{Block@+8:4 void *,var_10@+c:4 PanelPane *,var_C@+10:4 _DWORD,var_4@+18:4 _DWORD,__saved_registers@+1c:4 _DWORD,__return_address@+20:4 _UNKNOWN *,arg_4@+28:4 _DWORD}`; F02 `{__return_address@+4:4 _UNKNOWN *}`; F03 `{bounds@+8:10 struct RectBounds,var_14@+18:10 struct RectBounds,var_4@+28:4 _DWORD,__saved_registers@+2c:4 _DWORD,__return_address@+30:4 _UNKNOWN *,arg_0@+34:4 _DWORD}`; F04 `{point@+8:8 Point,bounds@+10:10 RectBounds,var_4@+20:4 _DWORD,__saved_registers@+24:4 _DWORD,__return_address@+28:4 _UNKNOWN *,arg_0@+2c:4 _DWORD}`; F05 `{var_C@+c:4 _DWORD,var_8@+10:4 _DWORD,var_4@+14:4 _DWORD,__saved_registers@+18:4 _DWORD,__return_address@+1c:4 _UNKNOWN *}`; F06 `{__saved_registers@+4:4 _DWORD,__return_address@+8:4 _UNKNOWN *,orientation@+c:1 unsigned __int8,oldPosition@+10:2 __int16,newPosition@+14:2 __int16}`; F07 `{var_14@+8:1 _BYTE,var_4@+18:4 _DWORD,__saved_registers@+1c:4 _DWORD,__return_address@+20:4 _UNKNOWN *,bounds@+24:4 RectBounds *,order@+28:4 int,previousPane@+2c:4 Pane *,layer@+30:4 Layer *}`; F08 `{__return_address@+4:4 _UNKNOWN *}`; F09 `{var_1A0@+8:4 ResourceLayoutTable *,var_19C@+c:4 _DWORD,var_198@+10:4 GrafPort *,var_194@+14:4 _DWORD,var_190@+18:4 _DWORD,var_18C@+1c:4 _DWORD,var_188@+20:4 _DWORD,tileContext@+24:28 EPFTileContext,outContext@+4c:28 EPFTileContext,var_134@+74:10 struct RectBounds,bounds@+84:10 struct RectBounds,var_114@+94:10 RectBounds,Buffer@+a4:2 wchar_t,var_4@+1a4:4 _DWORD,__saved_registers@+1a8:4 _DWORD,__return_address@+1ac:4 _UNKNOWN *}`; F10 `{__saved_registers@+8:4 _DWORD,__return_address@+c:4 _UNKNOWN *,arg_0@+10:4 _DWORD}`; F11 `{Block@+c:4 void *,var_C9@+13:1 _BYTE,var_C8@+14:4 void *,var_C1@+1b:1 _BYTE,bounds@+1c:10 struct RectBounds,var_B0@+2c:10 MapRect,var_A0@+3c:10 MapRect,Src@+4c:1 _BYTE,destination@+4d:1 unsigned __int8,var_8E@+4e:1 unsigned __int8,var_8D@+4f:1 unsigned __int8,var_8C@+50:1 _BYTE,var_10@+cc:4 _DWORD,var_C@+d0:4 _DWORD,var_4@+d8:4 _DWORD,__saved_registers@+dc:4 _DWORD,__return_address@+e0:4 _UNKNOWN *,arg_0@+e4:4 _DWORD,arg_4@+e8:4 _DWORD}`; F12 `{__saved_registers@+0:4 _DWORD,__return_address@+4:4 _UNKNOWN *,arg_0@+8:4 _DWORD}`; F13 `{__saved_registers@+c:4 _DWORD,__return_address@+10:4 _UNKNOWN *,arg_0@+14:4 _DWORD}`; F14 `{var_1C@+10:8 MapPoint,position@+18:8 MapPoint,var_C@+20:4 _DWORD,var_4@+28:4 _DWORD,__saved_registers@+2c:4 _DWORD,__return_address@+30:4 _UNKNOWN *,Block@+34:4 void *,arg_4@+38:4 _DWORD}`; F15 `{Src@+0:1 _BYTE,destination@+1:1 unsigned __int8,var_82@+2:1 _BYTE,var_4@+80:4 _DWORD,__saved_registers@+84:4 _DWORD,__return_address@+88:4 _UNKNOWN *,arg_0@+8c:1 _BYTE}`; F16 `{__saved_registers@+4:4 _DWORD,__return_address@+8:4 _UNKNOWN *,arg_0@+c:2 _WORD,bounds@+10:4 struct RectBounds *}`; F17 `{var_18@+c:4 _DWORD,bounds@+10:10 struct RectBounds,var_4@+20:4 _DWORD,__saved_registers@+24:4 _DWORD,__return_address@+28:4 _UNKNOWN *,row@+2c:4 int,column@+30:4 int}`; F18 `{__saved_registers@+0:4 _DWORD,__return_address@+4:4 _UNKNOWN *,arg_0@+8:2 _WORD}`; F19 `{__return_address@+4:4 _UNKNOWN *}`; F20 `{var_14@+4:1 _BYTE,var_4@+14:4 _DWORD,__saved_registers@+18:4 _DWORD,__return_address@+1c:4 _UNKNOWN *}`.

| ID | Final disposition / endpoint | Dated literal prestate before supervisor application | Supervisor action | Literal verified saved poststate / safety constraint |
| --- | --- | --- | --- | --- |
| I01 | APPLIED_VERIFIED; applied `rename(pure:true)` then `set_function_comments` | function `[57cf70,57d03f)`, name `sub_57CF70`, type `char *__thiscall(char *this)`; AR absent; AP absent; FR absent; FP absent; frame F01 literal above; bytes SHA `72CDC647DB67436CA8304D274B4A51A1745FCF029168215A1626732301B1E8B3`; incoming `{4b84cb code}`; outgoing entry `{57cf71 code}`; successor pad `[57d03f,57d040)`. | name `NewSpellInventoryPane__NewSpellInventoryPane`; FR `Construct NewSpellInventoryPane, initialize list/input/timer/expand state, allocate and activate its vertical ScrollSpellInventoryPane child.` | function `[57cf70,57d03f)`; name `NewSpellInventoryPane__NewSpellInventoryPane`; type `char *__thiscall(char *this)`; AR absent; AP absent; FR `Construct NewSpellInventoryPane, initialize list/input/timer/expand state, allocate and activate its vertical ScrollSpellInventoryPane child.`; FP absent; frame F01 exact; bytes SHA `72CDC647DB67436CA8304D274B4A51A1745FCF029168215A1626732301B1E8B3`; incoming `{4b84cb code}`; outgoing `{57cf71 code}`; successor pad `[57d03f,57d040)`. |
| I02 | APPLIED_VERIFIED; applied `rename(pure:true)` + `set_function_comments` | function `[57d080,57d097)`, name `sub_57D080`, type `int __thiscall(char *this, int)`; AR absent; AP absent; FR absent; FP absent; F02; SHA `EB29BD45B8FB7227B776F271CC6493EDF2ADE75997C009976EF47E5E52EEBE0C`; incoming `{62d0b0 data}`; outgoing `{57d081 code}`; pads `[57d075,57d080)`,`[57d097,57d0a0)`. | name `NewSpellInventoryPane__OnActivate`; FR `Rebuild the visible spell list and invalidate the pane when the owner activates this child.` | function `[57d080,57d097)`; name `NewSpellInventoryPane__OnActivate`; type `int __thiscall(char *this, int)`; AR absent; AP absent; FR `Rebuild the visible spell list and invalidate the pane when the owner activates this child.`; FP absent; frame F02 exact; bytes SHA `EB29BD45B8FB7227B776F271CC6493EDF2ADE75997C009976EF47E5E52EEBE0C`; incoming `{62d0b0 data}`; outgoing `{57d081 code}`; predecessor pad `[57d075,57d080)`; successor pad `[57d097,57d0a0)`. |
| I03 | APPLIED_VERIFIED; applied `rename(pure:true)` + `set_function_comments` | function `[57d0c0,57d148)`, name `sub_57D0C0`, type `__int16 __thiscall(_DWORD **this, struct RectBounds *)`; AR absent; AP absent; FR absent; FP absent; F03; SHA `433CBC2774AA6E473C75267D53AC3FE7AB196A27D9ADF2FEE466F77FE3D0BBCB`; incoming `{62d074 data}`; outgoing `{57d0c1 code}`; pads `[57d0b1,57d0c0)`,`[57d148,57d150)`. | name `NewSpellInventoryPane__UpdateRenderRegion`; FR `Update the child scrollbar bounds, delegate the pane render-region update, then rebuild visible spell rows.` | function `[57d0c0,57d148)`; name `NewSpellInventoryPane__UpdateRenderRegion`; type `__int16 __thiscall(_DWORD **this, struct RectBounds *)`; AR absent; AP absent; FR `Update the child scrollbar bounds, delegate the pane render-region update, then rebuild visible spell rows.`; FP absent; frame F03 exact; bytes SHA `433CBC2774AA6E473C75267D53AC3FE7AB196A27D9ADF2FEE466F77FE3D0BBCB`; incoming `{62d074 data}`; outgoing `{57d0c1 code}`; predecessor pad `[57d0b1,57d0c0)`; successor pad `[57d148,57d150)`. |
| I04 | APPLIED_VERIFIED; applied `rename(pure:true)` + `set_function_comments` | function `[57d150,57d1f5)`, name `sub_57D150`, type `int __thiscall(_BYTE *this, int *, int)`; AR absent; AP absent; FR absent; FP absent; F04; SHA `5621662B6C4E23553391032A72EF422CA2D554F7D5E422B21FCCAF3DCC9522E3`; incoming `{62d094 data}`; outgoing `{57d151 code}`; pads `[57d148,57d150)`,`[57d1f5,57d200)`. | name `NewSpellInventoryPane__SetBounds`; FR `Select fixed collapsed or expanded screen bounds, update the pane origin, localize the bounds, and refresh the render region.` | function `[57d150,57d1f5)`; name `NewSpellInventoryPane__SetBounds`; type `int __thiscall(_BYTE *this, int *, int)`; AR absent; AP absent; FR `Select fixed collapsed or expanded screen bounds, update the pane origin, localize the bounds, and refresh the render region.`; FP absent; frame F04 exact; bytes SHA `5621662B6C4E23553391032A72EF422CA2D554F7D5E422B21FCCAF3DCC9522E3`; incoming `{62d094 data}`; outgoing `{57d151 code}`; predecessor pad `[57d148,57d150)`; successor pad `[57d1f5,57d200)`. |
| I05 | APPLIED_VERIFIED; applied `rename(pure:true)` + `set_function_comments` | function `[57d200,57d360)`, name `sub_57D200`, type `__int16 __thiscall(int this)`; AR absent; AP absent; FR absent; FP absent; F05; SHA `BBA88B3A9C5ABCE4B957B42676FF49D8AD6556F5521F6904C5DEF7E715E6F4A9`; incoming exact `{57d083,57d131,57d383,57d3ef,57d47b,57d91d,57d96b,57e241,57e299,57ea38}`; outgoing `{57d201 code}`; predecessor pad `[57d1f5,57d200)`; next function at `57d360`. | name `NewSpellInventoryPane__RebuildSpellList`; FR `Rebuild the one-based visible spell-slot map, choose collapsed or expanded count, and clamp/synchronize the child scrollbar range and position.` | function `[57d200,57d360)`; name `NewSpellInventoryPane__RebuildSpellList`; type `__int16 __thiscall(int this)`; AR absent; AP absent; FR `Rebuild the one-based visible spell-slot map, choose collapsed or expanded count, and clamp/synchronize the child scrollbar range and position.`; FP absent; frame F05 exact; bytes SHA `BBA88B3A9C5ABCE4B957B42676FF49D8AD6556F5521F6904C5DEF7E715E6F4A9`; incoming `{57d083,57d131,57d383,57d3ef,57d47b,57d91d,57d96b,57e241,57e299,57ea38}`; outgoing `{57d201 code}`; predecessor pad `[57d1f5,57d200)`; successor function head `57d360`. |
| I06 | ALREADY_PRESENT_VERIFIED; no endpoint | function `[57d360,57d398)`, name `NewSpellInventoryPane__OnScrollPositionChanged`, type `void __thiscall(NewSpellInventoryPane *this, unsigned __int8 orientation, __int16 oldPosition, __int16 newPosition)`; AR absent; AP absent; FR `Source-authored NewSpellInventoryPane::OnScrollPositionChanged(orientation,oldPosition,newPosition). Orientation remains in the ABI although this body does not consume it.`; FP absent; F06; SHA `6B1B353B1262DAEC373BC11BB6D108FDC17CE49220CB1BB6A3DDD8857F411F62`; incoming `{560885,57da5e,57da79}`; outgoing `{57d361 code}`; successor pad `[57d398,57d3a0)`. | none. | function `[57d360,57d398)`; name `NewSpellInventoryPane__OnScrollPositionChanged`; type `void __thiscall(NewSpellInventoryPane *this, unsigned __int8 orientation, __int16 oldPosition, __int16 newPosition)`; AR absent; AP absent; FR `Source-authored NewSpellInventoryPane::OnScrollPositionChanged(orientation,oldPosition,newPosition). Orientation remains in the ABI although this body does not consume it.`; FP absent; frame F06 exact; bytes SHA `6B1B353B1262DAEC373BC11BB6D108FDC17CE49220CB1BB6A3DDD8857F411F62`; incoming `{560885,57da5e,57da79}`; outgoing `{57d361 code}`; successor pad `[57d398,57d3a0)`. |
| I07 | APPLIED_VERIFIED; applied `rename(pure:true)` + `set_function_comments` | function `[57d3a0,57d406)`, name `sub_57D3A0`, type `__int16 __thiscall(Pane *this, RectBounds *bounds, int order, Pane *previousPane, Layer *layer)`; AR absent; AP absent; FR absent; FP absent; F07; SHA `3953139BBC9F3A0B425EDD55EC06F117C17689DFE2E5AA9B175EE13613A1FFC5`; incoming `{62d098 data}`; outgoing `{57d3a1 code}`; pads `[57d398,57d3a0)`,`[57d406,57d410)`. | name `NewSpellInventoryPane__AddToLayer`; FR `Attach the owner pane, attach the child scrollbar after it using the child's bounds, then rebuild visible spell rows.` | function `[57d3a0,57d406)`; name `NewSpellInventoryPane__AddToLayer`; type `__int16 __thiscall(Pane *this, RectBounds *bounds, int order, Pane *previousPane, Layer *layer)`; AR absent; AP absent; FR `Attach the owner pane, attach the child scrollbar after it using the child's bounds, then rebuild visible spell rows.`; FP absent; frame F07 exact; bytes SHA `3953139BBC9F3A0B425EDD55EC06F117C17689DFE2E5AA9B175EE13613A1FFC5`; incoming `{62d098 data}`; outgoing `{57d3a1 code}`; predecessor pad `[57d398,57d3a0)`; successor pad `[57d406,57d410)`. |
| I08 | APPLIED_VERIFIED; applied `rename(pure:true)` + `set_function_comments` | function `[57d410,57d426)`, name `sub_57D410`, type `void __thiscall(int this)`; AR absent; AP absent; FR absent; FP absent; F08; SHA `DE08A1E6BAD3DA0D29A6D224DF1D1BC5F5426200C5FDDA0431118AB4EB78FD75`; incoming `{62d0a0 data}`; outgoing `{57d411 code}`; pads `[57d406,57d410)`,`[57d426,57d430)`. | name `NewSpellInventoryPane__RemoveFromLayer`; FR `Remove the child scrollbar from its layer before removing the owner pane.` | function `[57d410,57d426)`; name `NewSpellInventoryPane__RemoveFromLayer`; type `void __thiscall(int this)`; AR absent; AP absent; FR `Remove the child scrollbar from its layer before removing the owner pane.`; FP absent; frame F08 exact; bytes SHA `DE08A1E6BAD3DA0D29A6D224DF1D1BC5F5426200C5FDDA0431118AB4EB78FD75`; incoming `{62d0a0 data}`; outgoing `{57d411 code}`; predecessor pad `[57d406,57d410)`; successor pad `[57d426,57d430)`. |
| I09 | APPLIED_VERIFIED; applied `rename(pure:true)` + `set_function_comments` | function `[57d430,57d8c4)`, name `sub_57D430`, type `void __thiscall(int this)`; AR absent; AP absent; FR absent; FP absent; F09; SHA `AB1F8EC8E21CE72CACCA573F31282FB5F9278A3856E0FE2203A8A8C6645E328B`; incoming `{62d0ac data}`; outgoing `{57d431 code}`; pads `[57d426,57d430)`,`[57d8c4,57d8d0)`. | name `NewSpellInventoryPane__OnPaint`; FR `Draw the collapsed or expanded spell-inventory frame, visible learned spells, hotkeys, hover/selection state, and expand control.` | function `[57d430,57d8c4)`; name `NewSpellInventoryPane__OnPaint`; type `void __thiscall(int this)`; AR absent; AP absent; FR `Draw the collapsed or expanded spell-inventory frame, visible learned spells, hotkeys, hover/selection state, and expand control.`; FP absent; frame F09 exact; bytes SHA `AB1F8EC8E21CE72CACCA573F31282FB5F9278A3856E0FE2203A8A8C6645E328B`; incoming `{62d0ac data}`; outgoing `{57d431 code}`; predecessor pad `[57d426,57d430)`; successor pad `[57d8c4,57d8d0)`. |
| I10 | APPLIED_VERIFIED; applied `rename(pure:true)` + `set_function_comments` | function `[57d8d0,57d9b1)`, name `sub_57D8D0`, type `char __thiscall(_BYTE *this, _BYTE *)`; AR absent; AP absent; FR absent; FP absent; F10; SHA `2618C77C9AC875328FC8B1DD5BB7D9B052839413582006F32C1F2EEA86BF5DB8`; incoming `{62d0c0 data}`; outgoing `{57d8d1 code}`; pads `[57d8c4,57d8d0)`,`[57d9b1,57d9c0)`. | name `NewSpellInventoryPane__HandleKeyOrTextEvent`; FR `Translate key input, handle list navigation and expanded-mode commands, and refresh affected spell rows.` | function `[57d8d0,57d9b1)`; name `NewSpellInventoryPane__HandleKeyOrTextEvent`; type `char __thiscall(_BYTE *this, _BYTE *)`; AR absent; AP absent; FR `Translate key input, handle list navigation and expanded-mode commands, and refresh affected spell rows.`; FP absent; frame F10 exact; bytes SHA `2618C77C9AC875328FC8B1DD5BB7D9B052839413582006F32C1F2EEA86BF5DB8`; incoming `{62d0c0 data}`; outgoing `{57d8d1 code}`; predecessor pad `[57d8c4,57d8d0)`; successor pad `[57d9b1,57d9c0)`. |
| I11 | APPLIED_VERIFIED; applied `rename(pure:true)` + `set_function_comments` | function `[57d9c0,57e18f)`, name `sub_57D9C0`, type `char __thiscall(int this, int)`; AR absent; AP absent; FR absent; FP absent; F11; SHA `0A8B4792D19AE81E20AA729B29A00BB8459394352E3AF9480D733AFA77129F48`; incoming `{62d0bc data}`; outgoing `{57d9c1 code}`; pad `[57d9b1,57d9c0)`; switch table starts `57e190`. | name `NewSpellInventoryPane__HandlePointerOrMouseEvent`; FR `Handle hover, press, drag, swap, quick-cast, wheel, repeat-timer, expand-button, and child-scrollbar pointer flows.` | function `[57d9c0,57e18f)`; name `NewSpellInventoryPane__HandlePointerOrMouseEvent`; type `char __thiscall(int this, int)`; AR absent; AP absent; FR `Handle hover, press, drag, swap, quick-cast, wheel, repeat-timer, expand-button, and child-scrollbar pointer flows.`; FP absent; frame F11 exact; bytes SHA `0A8B4792D19AE81E20AA729B29A00BB8459394352E3AF9480D733AFA77129F48`; incoming `{62d0bc data}`; outgoing `{57d9c1 code}`; predecessor pad `[57d9b1,57d9c0)`; successor table `[57e190,57e1b0)`. |
| I12 | APPLIED_VERIFIED; applied `rename(pure:true)` + `set_function_comments` | function `[57e1b0,57e1d8)`, name `sub_57E1B0`, type `char __thiscall(_DWORD *this, int)`; AR absent; AP absent; FR absent; FP absent; F12; SHA `55362FD77407D446E3CEE60DFD20A84B99A2EE6017E8BD3CFB221059F31B6A8B`; incoming `{62d0c8 data}`; outgoing `{57e1b1 code}`; predecessor table `[57e190,57e1b0)`; successor pad `[57e1d8,57e1e0)`. | name `NewSpellInventoryPane__HandlePacketEvent`; FR `For packet payload code 23 or 24, call OnActivate(NULL) to rebuild and invalidate; return false for every packet.` | function `[57e1b0,57e1d8)`; name `NewSpellInventoryPane__HandlePacketEvent`; type `char __thiscall(_DWORD *this, int)`; AR absent; AP absent; FR `For packet payload code 23 or 24, call OnActivate(NULL) to rebuild and invalidate; return false for every packet.`; FP absent; frame F12 exact; bytes SHA `55362FD77407D446E3CEE60DFD20A84B99A2EE6017E8BD3CFB221059F31B6A8B`; incoming `{62d0c8 data}`; outgoing `{57e1b1 code}`; predecessor table `[57e190,57e1b0)`; successor pad `[57e1d8,57e1e0)`. |
| I13 | APPLIED_VERIFIED; applied `rename(pure:true)` + `set_function_comments` | function `[57e1e0,57e2c1)`, name `sub_57E1E0`, type `char __thiscall(TimerHandler *this, int, int, int)`; AR absent; AP absent; FR absent; FP absent; F13; SHA `779F55A80293AD9BF0D136D92DCAFE51827CF98043A34B650ED3E78BCB2B7B75`; incoming `{62d0ec data}`; outgoing `{57e1e1 code}`; pads `[57e1d8,57e1e0)`,`[57e2c1,57e2d0)`. | name `NewSpellInventoryPane__OnTimer`; FR `Repeat-scroll upward for timer 1 or downward for timer 2, clamp through the child scrollbar, rebuild, and reschedule after 50 milliseconds.` | function `[57e1e0,57e2c1)`; name `NewSpellInventoryPane__OnTimer`; type `char __thiscall(TimerHandler *this, int, int, int)`; AR absent; AP absent; FR `Repeat-scroll upward for timer 1 or downward for timer 2, clamp through the child scrollbar, rebuild, and reschedule after 50 milliseconds.`; FP absent; frame F13 exact; bytes SHA `779F55A80293AD9BF0D136D92DCAFE51827CF98043A34B650ED3E78BCB2B7B75`; incoming `{62d0ec data}`; outgoing `{57e1e1 code}`; predecessor pad `[57e1d8,57e1e0)`; successor pad `[57e2c1,57e2d0)`. |
| I14 | APPLIED_VERIFIED; applied `rename(pure:true)` + `set_function_comments` | function `[57e2d0,57e56d)`, name `sub_57E2D0`, type `char *__thiscall(_BYTE *this, char *Block)`; AR absent; AP absent; FR absent; FP absent; F14; SHA `5A0FB305D777DE6F59C5EED8F9A6967B82A2BB850542D141E1C75CDCDD5B1B1D`; incoming `{57e122 code}`; outgoing `{57e2d1 code}`; pad `[57e2c1,57e2d0)`; table `[57e570,57e594)`. | name `NewSpellInventoryPane__ActivateSpellSlot`; FR `Validate a one-based learned spell slot and dispatch its input kind to direct packet send or the matching spell-input pane.` | function `[57e2d0,57e56d)`; name `NewSpellInventoryPane__ActivateSpellSlot`; type `char *__thiscall(_BYTE *this, char *Block)`; AR absent; AP absent; FR `Validate a one-based learned spell slot and dispatch its input kind to direct packet send or the matching spell-input pane.`; FP absent; frame F14 exact; bytes SHA `5A0FB305D777DE6F59C5EED8F9A6967B82A2BB850542D141E1C75CDCDD5B1B1D`; incoming `{57e122 code}`; outgoing `{57e2d1 code}`; predecessor pad `[57e2c1,57e2d0)`; successor pad `[57e56d,57e570)`; switch table `[57e570,57e594)`. |
| I15 | APPLIED_VERIFIED; applied `rename(pure:true)` + `set_function_comments` | function `[57e620,57e689)`, name `sub_57E620`, type `void __stdcall(unsigned __int8)`; AR absent; AP absent; FR absent; FP absent; F15; SHA `E4C5C0BE2161745A0E2FD90853BF94FC00D9DBE90BCDEB69E8269906F1C516DB`; incoming `{57e54d code}`; outgoing `{57e621 code}`; pads `[57e615,57e620)`,`[57e689,57e690)`. | name `NewSpellInventoryPane__SendDirectSpellPacket`; FR `When signed g_activeDialogCount is not positive, send opcode 0x0f with the one-byte spell slot in a two-byte payload.` | function `[57e620,57e689)`; name `NewSpellInventoryPane__SendDirectSpellPacket`; type `void __stdcall(unsigned __int8)`; AR absent; AP absent; FR `When signed g_activeDialogCount is not positive, send opcode 0x0f with the one-byte spell slot in a two-byte payload.`; FP absent; frame F15 exact; bytes SHA `E4C5C0BE2161745A0E2FD90853BF94FC00D9DBE90BCDEB69E8269906F1C516DB`; incoming `{57e54d code}`; outgoing `{57e621 code}`; predecessor pad `[57e615,57e620)`; successor pad `[57e689,57e690)`. |
| I16 | APPLIED_VERIFIED; applied `rename(pure:true)` + `set_function_comments` | function `[57e690,57e6e7)`, name `sub_57E690`, type `void __stdcall(__int16, struct RectBounds *bounds)`; AR absent; AP absent; FR absent; FP absent; F16; SHA `324D6A9805EE19F534148BE7548956292103E98406D634E2F237B39F627957FC`; incoming `{57dcd7 code}`; outgoing `{57e691 code}`; pads `[57e689,57e690)`,`[57e6e7,57e6f0)`. | name `NewSpellInventoryPane__GetButtonRect`; FR `Return bounds [168,37,185,54] for expand-button part 2; other part indices have no rectangle.` | function `[57e690,57e6e7)`; name `NewSpellInventoryPane__GetButtonRect`; type `void __stdcall(__int16, struct RectBounds *bounds)`; AR absent; AP absent; FR `Return bounds [168,37,185,54] for expand-button part 2; other part indices have no rectangle.`; FP absent; frame F16 exact; bytes SHA `324D6A9805EE19F534148BE7548956292103E98406D634E2F237B39F627957FC`; incoming `{57dcd7 code}`; outgoing `{57e691 code}`; predecessor pad `[57e689,57e690)`; successor pad `[57e6e7,57e6f0)`. |
| I17 | APPLIED_VERIFIED; applied `rename(pure:true)` + `set_function_comments` | function `[57e800,57e8c8)`, name `sub_57E800`, type `__int16 __thiscall(_BYTE *this, int, int)`; AR absent; AP absent; FR absent; FP absent; F17; SHA `BD07F64876FABF724910E0F2EBEB1E3D4360B6D3AC5F249F98D94C9546CA1C9F`; incoming `{57da9e,57dc7a,57ddd1,57df84,57e0c3}`; outgoing `{57e801 code}`; pads `[57e7f4,57e800)`,`[57e8c8,57e8d0)`. | name `NewSpellInventoryPane__HitTestSpellRow`; FR `Return the visible spell-row index containing the local point, using collapsed or expanded row limits, or -1.` | function `[57e800,57e8c8)`; name `NewSpellInventoryPane__HitTestSpellRow`; type `__int16 __thiscall(_BYTE *this, int, int)`; AR absent; AP absent; FR `Return the visible spell-row index containing the local point, using collapsed or expanded row limits, or -1.`; FP absent; frame F17 exact; bytes SHA `BD07F64876FABF724910E0F2EBEB1E3D4360B6D3AC5F249F98D94C9546CA1C9F`; incoming `{57da9e,57dc7a,57ddd1,57df84,57e0c3}`; outgoing `{57e801 code}`; predecessor pad `[57e7f4,57e800)`; successor pad `[57e8c8,57e8d0)`. |
| I18 | APPLIED_VERIFIED; applied `rename(pure:true)` + `set_function_comments` | function `[57e8d0,57e955)`, name `sub_57E8D0`, type `char __thiscall(_BYTE *this, __int16)`; AR absent; AP absent; FR absent; FP absent; F18; SHA `45FE3F208BA64D6ADDE7AE450BDC67C0D231431E289A34E8E795E17DBBB7B7F5`; incoming `{57dad4,57daf6,57dcb0,57de19,57dfd1,57e0f9}`; outgoing `{57e8d1 code}`; pads `[57e8c8,57e8d0)`,`[57e955,57e960)`. | name `NewSpellInventoryPane__ResolveVisibleSpellSlot`; FR `Resolve a visible one-based row ordinal to a learned spell slot, or use the same slot directly in expanded mode.` | function `[57e8d0,57e955)`; name `NewSpellInventoryPane__ResolveVisibleSpellSlot`; type `char __thiscall(_BYTE *this, __int16)`; AR absent; AP absent; FR `Resolve a visible one-based row ordinal to a learned spell slot, or use the same slot directly in expanded mode.`; FP absent; frame F18 exact; bytes SHA `45FE3F208BA64D6ADDE7AE450BDC67C0D231431E289A34E8E795E17DBBB7B7F5`; incoming `{57dad4,57daf6,57dcb0,57de19,57dfd1,57e0f9}`; outgoing `{57e8d1 code}`; predecessor pad `[57e8c8,57e8d0)`; successor pad `[57e955,57e960)`. |
| I19 | APPLIED_VERIFIED; applied `rename(pure:true)` + `set_function_comments` | function `[57e9a0,57e9c5)`, name `sub_57E9A0`, type `void __thiscall(TimerHandler *this)`; AR absent; AP absent; FR absent; FP absent; F19; SHA `AF39AA016724C9B69664D179916482E1DE085F648F96D719534F433E773C0C2E`; incoming `{57dc22,57df4c}`; outgoing `{57e9a1 code}`; pads `[57e99a,57e9a0)`,`[57e9c5,57e9d0)`. | name `NewSpellInventoryPane__StopActiveRepeatTimer`; FR `Cancel the active repeat timer through the TimerHandler view and clear the stored timer identifier.` | function `[57e9a0,57e9c5)`; name `NewSpellInventoryPane__StopActiveRepeatTimer`; type `void __thiscall(TimerHandler *this)`; AR absent; AP absent; FR `Cancel the active repeat timer through the TimerHandler view and clear the stored timer identifier.`; FP absent; frame F19 exact; bytes SHA `AF39AA016724C9B69664D179916482E1DE085F648F96D719534F433E773C0C2E`; incoming `{57dc22,57df4c}`; outgoing `{57e9a1 code}`; predecessor pad `[57e99a,57e9a0)`; successor pad `[57e9c5,57e9d0)`. |
| I20 | APPLIED_VERIFIED; applied `rename(pure:true)` + `set_function_comments` | function `[57e9d0,57ea57)`, name `sub_57E9D0`, type `int __thiscall(_BYTE *this)`; AR absent; AP absent; FR absent; FP absent; F20; SHA `7B21907F7961C10095F140E64DF830FC16E61DA1FC448E5DB9EAE3EF0CF76D93`; incoming `{57d995,57de72}`; outgoing `{57e9d1 code}`; predecessor pad `[57e9c5,57e9d0)`; successor pad `[57ea57,57ea60)`. | name `NewSpellInventoryPane__ToggleExpandedMode`; FR `Toggle expanded mode, reset the top row and button state, relayout through the parent layer, rebuild rows, and invalidate.` | function `[57e9d0,57ea57)`; name `NewSpellInventoryPane__ToggleExpandedMode`; type `int __thiscall(_BYTE *this)`; AR absent; AP absent; FR `Toggle expanded mode, reset the top row and button state, relayout through the parent layer, rebuild rows, and invalidate.`; FP absent; frame F20 exact; bytes SHA `7B21907F7961C10095F140E64DF830FC16E61DA1FC448E5DB9EAE3EF0CF76D93`; incoming `{57d995,57de72}`; outgoing `{57e9d1 code}`; predecessor pad `[57e9c5,57e9d0)`; successor pad `[57ea57,57ea60)`. |
| I21 | APPLIED_VERIFIED; applied `set_address_comments` only | code item `[57d040,57d075)`, physical head `[57d040,57d041)`, name absent; type absent; AR absent; AP absent; FR not applicable; FP not applicable; no function/frame; SHA `AB1D9770CE8297963A45DB943BF467C5C65FA56CCCCB0DF696A6AF9349C7770F`; incoming absent; outgoing `{57d041 code}`; pads `[57d03f,57d040)`,`[57d075,57d080)`. | AR `Source-authored ordinary NewSpellInventoryPane destructor body; deletes m_scrollPane then performs PanelPane base destruction. Retained as a raw code item because no deterministic public function/frame creation contract is proven.` | code item `[57d040,57d075)`; physical head `[57d040,57d041)`; name absent; type absent; AR `Source-authored ordinary NewSpellInventoryPane destructor body; deletes m_scrollPane then performs PanelPane base destruction. Retained as a raw code item because no deterministic public function/frame creation contract is proven.`; AP absent; FR not applicable; FP not applicable; function absent; frame not applicable; bytes SHA `AB1D9770CE8297963A45DB943BF467C5C65FA56CCCCB0DF696A6AF9349C7770F`; incoming absent; outgoing `{57d041 code}`; predecessor pad `[57d03f,57d040)`; successor pad `[57d075,57d080)`. |
| I22 | APPLIED_VERIFIED; applied `set_address_comments` only | code item `[57e5a0,57e615)`, head `[57e5a0,57e5a1)`, name absent; type absent; AR absent; AP absent; FR not applicable; FP not applicable; no function/frame; SHA `0664FB6E9423FFE6A67C52795198028C170957F40920192EB4D85E430188728E`; incoming absent; outgoing `{57e5a1 code}`; pads `[57e594,57e5a0)`,`[57e615,57e620)`. | AR `Source-authored file-local SendSwapSpellPacket(fromSlot,toSlot); sends opcode 0x30, subcode 1, and the two one-byte slots in a four-byte payload. Raw item provenance is preserved.` | code item `[57e5a0,57e615)`; physical head `[57e5a0,57e5a1)`; name absent; type absent; AR `Source-authored file-local SendSwapSpellPacket(fromSlot,toSlot); sends opcode 0x30, subcode 1, and the two one-byte slots in a four-byte payload. Raw item provenance is preserved.`; AP absent; FR not applicable; FP not applicable; function absent; frame not applicable; bytes SHA `0664FB6E9423FFE6A67C52795198028C170957F40920192EB4D85E430188728E`; incoming absent; outgoing `{57e5a1 code}`; predecessor pad `[57e594,57e5a0)`; successor pad `[57e615,57e620)`. |
| I23 | APPLIED_VERIFIED; applied `set_address_comments` only | code item `[57e6f0,57e75a)`, head `[57e6f0,57e6f1)`, name absent; type absent; AR absent; AP absent; FR not applicable; FP not applicable; no function/frame; SHA `E6EFD6D6EEB32B741DBA54A3C3A9AE2879B8A853DAD244487DB9AC547F7265CC`; incoming absent; outgoing `{57e6f1 code}`; pads `[57e6e7,57e6f0)`,`[57e75a,57e760)`. | AR `Source-authored NewSpellInventoryPane::BuildSpellRowRect(row,outBounds); builds [2,16+20*row,170,36+20*row] within the literal mode limit. Raw item provenance is preserved.` | code item `[57e6f0,57e75a)`; physical head `[57e6f0,57e6f1)`; name absent; type absent; AR `Source-authored NewSpellInventoryPane::BuildSpellRowRect(row,outBounds); builds [2,16+20*row,170,36+20*row] within the literal mode limit. Raw item provenance is preserved.`; AP absent; FR not applicable; FP not applicable; function absent; frame not applicable; bytes SHA `E6EFD6D6EEB32B741DBA54A3C3A9AE2879B8A853DAD244487DB9AC547F7265CC`; incoming absent; outgoing `{57e6f1 code}`; predecessor pad `[57e6e7,57e6f0)`; successor pad `[57e75a,57e760)`. |
| I24 | APPLIED_VERIFIED; applied `set_address_comments` only | code item `[57e760,57e7f4)`, head `[57e760,57e761)`, name absent; type absent; AR absent; AP absent; FR not applicable; FP not applicable; no function/frame; SHA `28D59468F40A6E60CE2407EA83BC6ED03722EB1517BE3EEEC03687F23786B225`; incoming absent; outgoing `{57e761 code}`; pads `[57e75a,57e760)`,`[57e7f4,57e800)`. | AR `Source-authored file-local HitTestButton(localX,localY); scans parts 0..2 through GetButtonRect and returns the matching part or -1. Raw item provenance is preserved.` | code item `[57e760,57e7f4)`; physical head `[57e760,57e761)`; name absent; type absent; AR `Source-authored file-local HitTestButton(localX,localY); scans parts 0..2 through GetButtonRect and returns the matching part or -1. Raw item provenance is preserved.`; AP absent; FR not applicable; FP not applicable; function absent; frame not applicable; bytes SHA `28D59468F40A6E60CE2407EA83BC6ED03722EB1517BE3EEEC03687F23786B225`; incoming absent; outgoing `{57e761 code}`; predecessor pad `[57e75a,57e760)`; successor pad `[57e7f4,57e800)`. |
| I25 | APPLIED_VERIFIED; applied `set_address_comments` only | code item `[57e960,57e99a)`, head `[57e960,57e961)`, name absent; type absent; AR absent; AP absent; FR not applicable; FP not applicable; no function/frame; SHA `201787F3A37503341AFD3411CEB6A104D2AC3DAADCC4974A0D7B12F377BE634D`; incoming absent; outgoing `{57e961 code}`; pads `[57e955,57e960)`,`[57e99a,57e9a0)`. | AR `Source-authored NewSpellInventoryPane::BuildSpellRowOrigin(outPoint,row); uses Point(y=19+20*row,x=12 collapsed or 17 expanded). Raw item provenance is preserved.` | code item `[57e960,57e99a)`; physical head `[57e960,57e961)`; name absent; type absent; AR `Source-authored NewSpellInventoryPane::BuildSpellRowOrigin(outPoint,row); uses Point(y=19+20*row,x=12 collapsed or 17 expanded). Raw item provenance is preserved.`; AP absent; FR not applicable; FP not applicable; function absent; frame not applicable; bytes SHA `201787F3A37503341AFD3411CEB6A104D2AC3DAADCC4974A0D7B12F377BE634D`; incoming absent; outgoing `{57e961 code}`; predecessor pad `[57e955,57e960)`; successor pad `[57e99a,57e9a0)`. |
| P01 | ALREADY_PRESENT_VERIFIED; no endpoint | function `[57d0a0,57d0b0)`, name `ItemWhoInputPaneState__SetInputModeFlag`, type `void __thiscall(ItemWhoInputPaneState *this, bool active)`; AR absent; AP absent; FR exact `Source-facing ItemWhoInputPaneState::SetInputModeFlag(bool); stores the Boolean at state offset +0xfa. AL is assignment residue, so source return is void.`; FP absent; frame `{__saved_registers@+0:4 _DWORD,__return_address@+4:4 _UNKNOWN *,active@+8:1 bool}`; SHA `73CEDDE9AEAD9D734DD8476308B3D0785DEE5BA1B992396DE3F69348D39D0087`; incoming exact `{5a3fda,5ae029,5ae3d9,5aedaf,5b0869,5b0ba9,5b0e89,5b1119,5b1369,5b7a96,5b7c80,5b7d50,5b7e20,5b7ef0,5b7fc0,5b8090,5b8160}`; outgoing `{57d0a1 code}`. | none. | function `[57d0a0,57d0b0)`; name `ItemWhoInputPaneState__SetInputModeFlag`; type `void __thiscall(ItemWhoInputPaneState *this, bool active)`; AR absent; AP absent; FR `Source-facing ItemWhoInputPaneState::SetInputModeFlag(bool); stores the Boolean at state offset +0xfa. AL is assignment residue, so source return is void.`; FP absent; frame `{__saved_registers@+0:4 _DWORD,__return_address@+4:4 _UNKNOWN *,active@+8:1 bool}`; bytes SHA `73CEDDE9AEAD9D734DD8476308B3D0785DEE5BA1B992396DE3F69348D39D0087`; incoming `{5a3fda,5ae029,5ae3d9,5aedaf,5b0869,5b0ba9,5b0e89,5b1119,5b1369,5b7a96,5b7c80,5b7d50,5b7e20,5b7ef0,5b7fc0,5b8090,5b8160}`; outgoing `{57d0a1 code}`; ownership remains UID00006Y/UID0000OH. |
| P02 | ALREADY_PRESENT_VERIFIED; no endpoint | function `[57d0b0,57d0b1)`, name `nullsub_54`, type `void()`; AR absent; AP absent; FR absent; FP absent; frame `{__return_address@+0:4 _UNKNOWN *}`; SHA `AE3F4619B0413D70D3004B9131C3752153074E45725BE13B9A148978895E359E`; incoming absent; outgoing absent; little-endian VA pointer hits absent; NewSpell vtable entry absent; successor pad `[57d0b1,57d0c0)`. | none. | function `[57d0b0,57d0b1)`; name `nullsub_54`; type `void()`; AR absent; AP absent; FR absent; FP absent; frame `{__return_address@+0:4 _UNKNOWN *}`; bytes SHA `AE3F4619B0413D70D3004B9131C3752153074E45725BE13B9A148978895E359E`; incoming absent; outgoing absent; little-endian VA pointer hits absent; NewSpell vtable entry absent; successor pad `[57d0b1,57d0c0)`; the analysis label remains physical identity only and does not establish source ownership; ownership remains NONE, emitter absent, reconstructable false, and no source child/CPP/H exists. |
| P03 | ALREADY_PRESENT_VERIFIED; no endpoint | data dwords `[62d064,62d0f0)`, 35 physical 4-byte heads, names/types/comments absent at prefix head; exact word map in IDA facts; SHA `10229014E8D79730C6F31369235F111DCC181F9B8DFE2C8A1BBABA455253391A`; next head `62d0f0->650718`. | none. | data dwords `[62d064,62d0f0)`; 35 physical 4-byte heads; prefix name absent; prefix type absent; prefix AR absent; prefix AP absent; FR not applicable; FP not applicable; exact words `650690,57f5d0,4f4b10,41b6c0,57d0c0,41d680,544730,544750,5447a0,544800,544a20,544b80,57d150,57d3a0,544cb0,57d410,544d30,544d70,57d430,57d080,6506f0,57f58b,57d9c0,57d8d0,544dd0,57e1b0,544df0,544e00,4a89f0,544e10,544e30,544e70,650704,57f596,57e1e0`; SHA `10229014E8D79730C6F31369235F111DCC181F9B8DFE2C8A1BBABA455253391A`; successor head `62d0f0` value `650718`; xref topology unchanged. |
| P04 | REJECT_INVALID_VERIFIED/NO_MUTATION; no endpoint | named UDT `NewSpellInventoryPane`, size `0x100`, members `{_paneBase +0 size f8 unsigned char[f8],m_scrollPosition +f8 size1 unsigned char,_scrollPositionPadding +f9 size3 unsigned char[3],m_scrollPane +fc size4 ScrollSpellInventoryPane *}`. | do not call `declare_type`, `set_type`, or type mutation endpoints. | named UDT `NewSpellInventoryPane`; size `0x100`; member `_paneBase` offset `+0x0`, size `0xf8`, type `unsigned __int8[248]`; member `m_scrollPosition` offset `+0xf8`, size `1`, type `unsigned __int8`; member `_scrollPositionPadding` offset `+0xf9`, size `3`, type `unsigned __int8[3]`; member `m_scrollPane` offset `+0xfc`, size `4`, type `ScrollSpellInventoryPane *`; no declaration/type/member mutation. Corrected `0x148` source layout remains documentation/H only. |

Negative constraints for every row were satisfied: no function was created at a raw start, and no function range, frame, local name/type, prototype, byte, xref, switch table, padding, foreign identity, disconnected nullsub identity, vtable word, or shared UDT changed. B009 did not mutate/save IDA; the supervisor performed the bounded transaction and canonical save.

## First-Draft C++ Recommendation

- Eligible: UID00009A class preamble/header and the 25 source-emitting exact children. Disconnected `nullsub_54`, the broad core, compiler artifacts, vtable data, resource data, and file route have explicit no-code dispositions.
- Naming: descriptive inferred names follow existing `Pane`, `RectBounds`, `Point`, `Event`, `TimerHandler`, and packet helper conventions. The code preserves signed one-byte/short behavior and literal constants instead of laundering them into unsupported symbolic claims.
- Dependency closure is exact after the stated support-header changes:

| Former/report-only token or dependency | Resolution | Owner UID / declaration destination / target include |
| --- | --- | --- |
| `DrawSpellSelectionState` | removed; explicit `SetDrawColor(0x8a)` plus `g_pfnFillRect(this,&highlightBounds)` implements the observed selected-row fill | UID0000TN `SurfaceRenderCallbackTable`; existing `render/Surface.h`; `../../render/Surface.h` |
| `FormatHotkey` | removed; exact `1..26 -> a..z`, `27..52 -> A..Z`, otherwise space mapping is inline, matching current InventoryPane source precedent for ownerless `0x5a4090` | no new owner/API; target body only |
| `DrawInventoryButton` | removed; exact `g_pEPFLib->LookupLayoutEntry` and inherited `RenderTileFrame` draw `INVENBUT.EPF`/`invenbut.pal` with frame `7*state+3/4` | UID00006E ImageLib and UID00005V GrafPort; existing `render/ImageLib.h` and inherited class header |
| `OpenWillBeChangedSpellPane` | removed; target directly constructs `WillBeChangedSpellPane(this,slot,y,x,pointerY,pointerX)` | UID0000G6 through UID0000JU HelpPanes; move accepted class declaration from CPP to `ui/controls/HelpPanes.h`; include `../controls/HelpPanes.h` |
| `g_spellInputGate` | rejected; exact signed positive-only gate is `g_activeDialogCount <= 0` | UID0000PQ/UID0001PH; add `extern signed char g_activeDialogCount;` to `ui/core/DialogPane.h`; include `../core/DialogPane.h` |
| `g_inventoryLayer` | rejected; physical `0x69b368` is `g_mainUiLayerSlots.rootPaneLayerContext` | UID0000T6; existing `ui/MainUiGraph.h`; include `../MainUiGraph.h` |
| `UserSpell` / `GetSpell` | removed; exact record is `SpellCommandSlotRecord` and private inline `GetSpellCommandSlotRecord(unsigned char)` | UID0000FQ; add `class NewSpellInventoryPane;` plus friendship in `ui/panels/UserPane.h`; include `../panels/UserPane.h` |
| `OpenSpell*InputPane` wrappers | removed; direct `new SpellStringInputPane`, `SpellWhoInputPane`, `SpellFourArgsInputPane`, `SpellThreeArgsInputPane`, `SpellTwoArgsInputPane`, `SpellOneArgInputPane`, and `SpellSlotInputPane` | UIDs 0000DU/0000DX/0000DL/0000DV/0000DW/0000DR/0000DS; move accepted class declarations to `SpellInputPanes.h` or `TargetSelectionInputPanes.h`; include both owner headers |
| `SendTargetedSpellPacket` | rejected; exact existing helper is `SendTargetedActionPacket(unsigned char,unsigned int,unsigned short,unsigned short)` | UID0001L9 through UID0000OH; remove target-local `static` linkage and add declaration to `TargetSelectionInputPanes.h` |
| `PacketBuffer` object/member methods | removed; exact existing free writers and `Socket::QueueAndSendPacket` are used on byte arrays | UID0003YJ/UID0001HU/UID0000Q5; existing `network/PacketBuffer.h` and `network/Socket.h` |
| `HasSelectedTarget` / `SelectedTarget` | removed; target reads existing public `MapPane::m_selectedObjectActive` and `m_selectedObjectPane`, then existing `ObjectPane::GetObjectId/GetMapPosition` | UID00007Q/UID00009R; add UID0000PR `extern MapPane *g_activeMapPane;` to `map/MapPane.h`; ensure UID00007B under file UID0000KU is available from `map/LivingObjectPane.h`; include MapPane/ObjectPane/LivingObjectPane headers |
| `g_pBackPane` undeclared use | retain accepted singleton, but route its declaration through its owner header | UID00028J through UID0000HO; move BackPane declaration to `map/BackPane.h` and add `extern BackPane *g_pBackPane;`; include `../../map/BackPane.h` |
| event/config/timer draft forms | use existing `EventPayload::m_pointer/m_key/m_packet`, `g_pEventMan->TranslateEventKey(key,modifiers)`, `g_pConfig->m_doubleClickEnabled`, and four-argument `ScheduleTimer` | UIDs 00004L/00004O/00028Q/0000F0; existing Event/Config/TimerHandler headers |
- `NewSpellInventoryPane.cpp` class preamble, exact UID00009A `RECONSTRUCTION_CPP CODE` replacement:

```cpp
#include "NewSpellInventoryPane.h"
#include "ScrollSpellInventoryPane.h"
#include "../MainUiGraph.h"
#include "../controls/HelpPanes.h"
#include "../core/DialogPane.h"
#include "../core/Event.h"
#include "../dialogs/SpellInputPanes.h"
#include "../dialogs/TargetSelectionInputPanes.h"
#include "../panels/UserPane.h"
#include "../../config/Config.h"
#include "../../map/BackPane.h"
#include "../../map/LivingObjectPane.h"
#include "../../map/MapPane.h"
#include "../../map/ObjectPane.h"
#include "../../network/PacketBuffer.h"
#include "../../network/Socket.h"
#include "../../render/EPFTileContext.h"
#include "../../render/ImageLib.h"
#include "../../render/Surface.h"

#include <cwchar>

namespace
{
    const int kSpellSlotCount = 52;
    const int kCollapsedRowCount = 13;
    const int kExpandedRowCount = 26;

    void SendSwapSpellPacket(unsigned char fromSlot, unsigned char toSlot);
    void SendDirectSpellPacket(unsigned char spellSlot);
    bool GetButtonRect(short part, RectBounds *bounds);
    short HitTestButton(int localX, int localY);
}

[[CHILDREN]]
```

- `NewSpellInventoryPane.h`, exact UID00009A `RECONSTRUCTION_H CODE` replacement:

```cpp
#ifndef NEXUSTK_UI_INVENTORY_NEWSPELLINVENTORYPANE_H
#define NEXUSTK_UI_INVENTORY_NEWSPELLINVENTORYPANE_H

#include "../core/PanelPane.h"

class Event;
class Layer;
class ScrollSpellInventoryPane;

class NewSpellInventoryPane : public PanelPane
{
public:
    NewSpellInventoryPane();
    virtual ~NewSpellInventoryPane();

    virtual void UpdateRenderRegion(const RectBounds *bounds);
    virtual void SetBounds(RectBounds *bounds, const RectBounds *parentBounds);
    virtual void AddToLayer(const RectBounds *bounds, int order,
                            Pane *previousPane, Layer *layer);
    virtual void RemoveFromLayer();
    virtual void OnPaint();
    virtual void OnActivate(const unsigned char *activationData);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual bool OnTimer(int timerId, int elapsed, int userData);

    void OnScrollPositionChanged(unsigned char orientation,
                                 short oldPosition, short newPosition);

private:
    void RebuildSpellList();
    void ActivateSpellSlot(int spellSlot);
    bool BuildSpellRowRect(int row, RectBounds *bounds) const;
    int HitTestSpellRow(int localX, int localY) const;
    int ResolveVisibleSpellSlot(short visibleOrdinal) const;
    void BuildSpellRowOrigin(Point *origin, int row) const;
    void StopActiveRepeatTimer();
    void ToggleExpandedMode();

    signed char m_scrollPosition;
    unsigned char m_spellListCount;
    bool m_spellInputActive;
    unsigned char m_reservedFB[5];
    ScrollSpellInventoryPane *m_scrollPane;
    unsigned char m_visibleSpellSlots[53];
    signed char m_hoverSpellSlot;
    signed char m_selectedSpellSlot;
    unsigned char m_reserved13B;
    int m_activeRepeatTimer;
    int m_expandButtonState;
    bool m_expanded;
    bool m_draggedSincePress;
    unsigned char m_tailPadding[2];
};

typedef char NewSpellInventoryPane_size_must_be_0x148[
    sizeof(NewSpellInventoryPane) == 0x148 ? 1 : -1];

#endif
```

- NEW-LU-01 constructor child CPP; H blank because the class H declares it:

```cpp
NewSpellInventoryPane::NewSpellInventoryPane()
    : m_scrollPosition(0),
      m_spellListCount(0),
      m_spellInputActive(false),
      m_scrollPane(0),
      m_hoverSpellSlot(-1),
      m_selectedSpellSlot(-1),
      m_activeRepeatTimer(0),
      m_expandButtonState(0),
      m_expanded(false),
      m_draggedSincePress(false)
{
    m_scrollPane = new ScrollSpellInventoryPane(0);
    m_scrollPane->Activate();
}
```

- NEW-LU-02 ordinary destructor child CPP; H blank because the class H declares it:

```cpp
NewSpellInventoryPane::~NewSpellInventoryPane()
{
    delete m_scrollPane;
}
```

- NEW-LU-03 activation child CPP; H blank:

```cpp
void NewSpellInventoryPane::OnActivate(const unsigned char *)
{
    RebuildSpellList();
    InvalidateRect(&m_visibleBounds);
}
```

- No NEW-LU-04 is created. `nullsub_54` has no recoverable human declaration or definition: its one-byte `ret`, zero directional xrefs, zero encoded pointer hits, complete-vtable absence, no state access, and foreign/alignment neighbors establish an ownerless disconnected dead-code artifact. Both formal channels and emitter metadata are absent; P02 preserves the physical item, and no class/source semantics are invented from the analysis label.

- NEW-LU-05 render-region child CPP; H blank:

```cpp
void NewSpellInventoryPane::UpdateRenderRegion(const RectBounds *bounds)
{
    RectBounds scrollBounds;
    InitRectBounds(&scrollBounds, bounds->right - 20, bounds->top + 57,
                   bounds->right - 7, bounds->bottom - 21);
    m_scrollPane->SetBounds(&scrollBounds, 0);
    PanelPane::UpdateRenderRegion(bounds);
    RebuildSpellList();
}
```

- NEW-LU-06 bounds child CPP; H blank:

```cpp
void NewSpellInventoryPane::SetBounds(RectBounds *bounds,
                                      const RectBounds *)
{
    if (m_expanded)
        InitRectBounds(bounds, 827, 79, 1021, 637);
    else
        InitRectBounds(bounds, 832, 79, 1021, 367);

    InitPointPair(&m_origin, bounds->top, bounds->left);
    RectBounds localBounds = *bounds;
    OffsetRect(&localBounds, -m_origin.x, -m_origin.y);
    UpdateRenderRegion(&localBounds);
}
```

- NEW-LU-07 rebuild child CPP; H blank:

```cpp
void NewSpellInventoryPane::RebuildSpellList()
{
    unsigned char learnedCount = 0;
    int spellSlot;
    for (spellSlot = 1; spellSlot <= kSpellSlotCount; ++spellSlot)
    {
        SpellCommandSlotRecord *record =
            g_pUserPane->GetSpellCommandSlotRecord((unsigned char)spellSlot);
        if (record->active)
            m_visibleSpellSlots[++learnedCount] = (unsigned char)spellSlot;
    }

    m_spellListCount = m_expanded ? kSpellSlotCount : learnedCount;
    const int visibleRows = m_expanded ? kExpandedRowCount
                                      : kCollapsedRowCount;
    short maximum = (short)(m_spellListCount - visibleRows);
    if (maximum < 0)
        maximum = 0;
    if (maximum > 30000)
        maximum = 30000;

    if (m_scrollPane->m_scrollRange != maximum)
        m_scrollPane->SetMaxRange(maximum);

    short position = m_scrollPosition < 0 ? 0 : m_scrollPosition;
    if (position > maximum)
        position = maximum;
    if (position > 30000)
        position = 30000;
    if (m_scrollPane->m_scrollPosition != position)
        m_scrollPane->SetScrollPosition(position);
    m_scrollPosition = (signed char)position;
}
```

- NEW-LU-08 scroll callback child CPP; H blank:

```cpp
void NewSpellInventoryPane::OnScrollPositionChanged(
    unsigned char, short oldPosition, short newPosition)
{
    if (oldPosition == newPosition)
        return;

    m_scrollPosition = (signed char)newPosition;
    m_scrollPane->SetScrollPosition(newPosition);
    RebuildSpellList();
    InvalidateRect(&m_visibleBounds);
}
```

- NEW-LU-09 AddToLayer child CPP; H blank:

```cpp
void NewSpellInventoryPane::AddToLayer(const RectBounds *bounds, int order,
                                       Pane *previousPane, Layer *layer)
{
    Pane::AddToLayer(bounds, order, previousPane, layer);
    RectBounds childBounds;
    m_scrollPane->GetBounds(&childBounds);
    m_scrollPane->AddToLayer(&childBounds, 0, this, layer);
    RebuildSpellList();
}
```

- NEW-LU-10 RemoveFromLayer child CPP; H blank:

```cpp
void NewSpellInventoryPane::RemoveFromLayer()
{
    m_scrollPane->RemoveFromLayer();
    Pane::RemoveFromLayer();
}
```

- NEW-LU-11 paint child CPP; H blank. This body uses the exact current ImageLib, GrafPort, Surface callback, rectangle, and text APIs routed in the dependency table; it introduces no target-only graphics wrapper:

```cpp
void NewSpellInventoryPane::OnPaint()
{
    EPFTileContext background;
    EPFTileContext button;
    background.Initialize();
    button.Initialize();
    RebuildSpellList();

    const wchar_t *backgroundResource =
        m_expanded ? L"ITEMINVE.EPF" : L"SPELLINV.EPF";
    g_pEPFLib->LookupLayoutEntry(
        backgroundResource, m_expanded ? 2 : 0, &background);
    RenderTileFrame(&background, &background.bounds, &m_visibleBounds,
                    0, L"ITEMINV.PAL", 0);

    m_drawEnabled = true;
    SetTextBackColor(0);

    const int firstTextX = m_expanded ? 17 : 12;
    RectBounds textBounds;
    InitRectBounds(&textBounds, firstTextX, 19, firstTextX + 10, 40);

    const int rowCount = m_expanded ? kExpandedRowCount
                                    : kCollapsedRowCount;
    int row;
    for (row = 0; row < rowCount; ++row)
    {
        const int ordinal = m_scrollPosition + row + 1;
        const int spellSlot = m_expanded
            ? ordinal : m_visibleSpellSlots[ordinal];
        if (spellSlot < 1 || spellSlot > kSpellSlotCount)
            continue;

        SpellCommandSlotRecord *record =
            g_pUserPane->GetSpellCommandSlotRecord(
                (unsigned char)spellSlot);
        if (!record->active && !m_expanded)
            continue;

        if (m_hoverSpellSlot == spellSlot)
        {
            RectBounds highlightBounds;
            InitRectBounds(&highlightBounds, 29, textBounds.top - 4,
                           165, textBounds.bottom - 6);
            if (m_expanded)
                OffsetRect(&highlightBounds, 5, 0);
            SetDrawColor(0x8a);
            g_pfnFillRect(this, &highlightBounds);
        }

        wchar_t hotkey = L' ';
        if (spellSlot >= 1 && spellSlot <= 26)
            hotkey = (wchar_t)(L'a' + spellSlot - 1);
        else if (spellSlot >= 27 && spellSlot <= 52)
            hotkey = (wchar_t)(L'A' + spellSlot - 27);

        wchar_t text[128];
        swprintf_s(text, 128, L"%c", hotkey);
        SetTextColor(0x80);
        OffsetRect(&textBounds, 1, 0);
        DrawTextInRect(text, (int)wcslen(text), &textBounds);
        SetTextColor(1);
        OffsetRect(&textBounds, -1, 0);
        DrawTextInRect(text, (int)wcslen(text), &textBounds);

        textBounds.left += 25;
        textBounds.right = 160;
        swprintf_s(text, 128, L"%s", record->displayName);
        FitTextAndAppendSuffix(
            text, 128, L"...", textBounds.right - textBounds.left);
        SetTextColor(m_selectedSpellSlot == spellSlot ? 0x8a : 0x80);
        DrawTextInRect(text, (int)wcslen(text), &textBounds);

        InitRectBounds(&textBounds, firstTextX, textBounds.top + 20,
                       firstTextX + 10, textBounds.bottom + 20);
    }

    RectBounds buttonBounds;
    InitRectBounds(&buttonBounds, 168, 37, 185, 54);
    int frameIndex = 7 * m_expandButtonState;
    if (m_expanded)
    {
        OffsetRect(&buttonBounds, 5, 0);
        frameIndex += 3;
    }
    else
    {
        frameIndex += 4;
    }
    g_pEPFLib->LookupLayoutEntry(L"INVENBUT.EPF", frameIndex, &button);
    RenderTileFrame(&button, &button.bounds, &buttonBounds,
                    0, L"invenbut.pal", 0);
}
```

- NEW-LU-12 key/text child CPP; H blank:

```cpp
bool NewSpellInventoryPane::HandleKeyOrTextEvent(Event *event)
{
    if (event->m_type != kEventKeyDown)
        return false;

    const unsigned char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);
    if (event->m_payload.m_key.m_modifiers == 0 &&
        key == kPaneKeyPageUp)
    {
        short position = (short)(m_scrollPosition - kCollapsedRowCount);
        if (position < 0)
            position = 0;
        m_scrollPosition = (signed char)position;
        RebuildSpellList();
        InvalidateRect(&m_visibleBounds);
        return true;
    }
    if (event->m_payload.m_key.m_modifiers == 0 &&
        key == kPaneKeyPageDown)
    {
        short maximum = (short)(m_spellListCount - kCollapsedRowCount);
        if (maximum < 0)
            maximum = 0;
        short position = (short)(m_scrollPosition + kCollapsedRowCount);
        if (position > maximum)
            position = maximum;
        m_scrollPosition = (signed char)position;
        RebuildSpellList();
        InvalidateRect(&m_visibleBounds);
        return true;
    }
    if (key == L'+')
    {
        ToggleExpandedMode();
        return true;
    }

    m_selectedSpellSlot = -1;
    return false;
}
```

- NEW-LU-13 pointer/mouse child CPP; H blank:

```cpp
bool NewSpellInventoryPane::HandlePointerOrMouseEvent(Event *event)
{
    if (g_pUserPane->IsInputLocked())
        return false;

    const int pointerY = event->m_payload.m_pointer.m_y;
    const int pointerX = event->m_payload.m_pointer.m_x;

    switch (event->m_type)
    {
    case kEventCursorMove:
    {
        if (m_selectedSpellSlot >= 0)
        {
            const int row = HitTestSpellRow(pointerX, pointerY);
            const int ordinal = m_scrollPosition + row + 1;
            const int spellSlot = row < 0
                ? -1 : ResolveVisibleSpellSlot((short)ordinal);
            m_hoverSpellSlot =
                spellSlot == m_selectedSpellSlot ? -1 : (signed char)spellSlot;
            InvalidateRect(&m_visibleBounds);

            RectBounds upperRepeat = m_visibleBounds;
            upperRepeat.top -= 90;
            upperRepeat.bottom = m_visibleBounds.top + 20;
            RectBounds lowerRepeat = m_visibleBounds;
            lowerRepeat.top = m_visibleBounds.bottom - 20;
            lowerRepeat.bottom += m_expanded ? 140 : 400;
            if (PointInRect(pointerY, pointerX, &upperRepeat))
            {
                if (m_activeRepeatTimer == 0)
                {
                    m_activeRepeatTimer = 1;
                    ScheduleTimer(1, 50, 0, 0);
                }
            }
            else if (PointInRect(pointerY, pointerX, &lowerRepeat))
            {
                if (m_activeRepeatTimer == 0)
                {
                    m_activeRepeatTimer = 2;
                    ScheduleTimer(2, 50, 0, 0);
                }
            }
            else
            {
                StopActiveRepeatTimer();
            }
        }

        if (!PointInRect(pointerY, pointerX, &m_visibleBounds))
        {
            m_expandButtonState = 0;
            return false;
        }

        if (!g_pConfig->m_doubleClickEnabled &&
            m_selectedSpellSlot >= 0 && !m_draggedSincePress)
        {
            const int row = HitTestSpellRow(pointerX, pointerY);
            const int spellSlot = row < 0 ? -1 : ResolveVisibleSpellSlot(
                (short)(m_scrollPosition + row + 1));
            if (spellSlot >= 0 && spellSlot != m_selectedSpellSlot)
                m_draggedSincePress = true;
        }

        m_expandButtonState = HitTestButton(pointerX, pointerY) == 2 ? 1 : 0;
        if (m_expandButtonState != 0)
            InvalidateRect(&m_visibleBounds);
        break;
    }

    case kEventLeftButtonDown:
    {
        if (HitTestButton(pointerX, pointerY) == 2)
        {
            ToggleExpandedMode();
            break;
        }
        if (g_activeDialogCount <= 0 && !m_spellInputActive)
        {
            const int row = HitTestSpellRow(pointerX, pointerY);
            const int spellSlot = row < 0 ? -1 : ResolveVisibleSpellSlot(
                (short)(m_scrollPosition + row + 1));
            if (spellSlot >= 0)
            {
                m_selectedSpellSlot = (signed char)spellSlot;
                m_draggedSincePress = false;
                RectBounds screenBounds;
                GetScreenBounds(&screenBounds);
                Point rowOrigin;
                BuildSpellRowOrigin(&rowOrigin, row);
                new WillBeChangedSpellPane(
                    this, (char)spellSlot,
                    screenBounds.top + rowOrigin.y,
                    screenBounds.left + rowOrigin.x,
                    screenBounds.top + pointerY,
                    screenBounds.left + pointerX);
            }
        }
        break;
    }

    case kEventLeftButtonDoubleClick:
    {
        if (g_pConfig->m_doubleClickEnabled && !m_spellInputActive)
        {
            const int row = HitTestSpellRow(pointerX, pointerY);
            const int spellSlot = row < 0 ? -1 : ResolveVisibleSpellSlot(
                (short)(m_scrollPosition + row + 1));
            if (spellSlot >= 0)
                ActivateSpellSlot(spellSlot);
        }
        break;
    }

    case kEventLeftButtonUp:
    {
        if (m_hoverSpellSlot >= 0)
        {
            m_hoverSpellSlot = -1;
            InvalidateRect(&m_visibleBounds);
        }
        if (g_activeDialogCount <= 0)
        {
            StopActiveRepeatTimer();
            if (!PointInRect(pointerY, pointerX, &m_visibleBounds))
                m_selectedSpellSlot = -1;

            if (!m_spellInputActive)
            {
                const int row = HitTestSpellRow(pointerX, pointerY);
                int spellSlot = -1;
                if (row >= 0)
                {
                    const int ordinal = m_scrollPosition + row + 1;
                    spellSlot = m_expanded
                        ? ordinal : ResolveVisibleSpellSlot((short)ordinal);
                }
                if (spellSlot >= 0 && m_selectedSpellSlot >= 0)
                {
                    if (spellSlot == m_selectedSpellSlot)
                    {
                        if (!g_pConfig->m_doubleClickEnabled &&
                            !m_draggedSincePress)
                            ActivateSpellSlot(spellSlot);
                    }
                    else
                    {
                        SendSwapSpellPacket((unsigned char)spellSlot,
                            (unsigned char)m_selectedSpellSlot);
                    }
                }
                m_selectedSpellSlot = -1;
            }
        }
        break;
    }

    case kEventMouseWheel:
        if (PointInRect(pointerY, pointerX, &m_visibleBounds))
        {
            short position = (short)(m_scrollPane->m_scrollPosition -
                                     event->m_payload.m_pointer.m_detail);
            if (position < 0)
                position = 0;
            if (position > m_scrollPane->m_scrollRange)
                position = m_scrollPane->m_scrollRange;
            OnScrollPositionChanged(
                0, m_scrollPane->m_scrollPosition, position);
        }
        break;

    default:
        break;
    }

    RectBounds scrollBounds;
    m_scrollPane->GetBounds(&scrollBounds);
    event->m_payload.m_pointer.m_y -= scrollBounds.top;
    event->m_payload.m_pointer.m_x -= scrollBounds.left;
    const bool handled = m_scrollPane->HandlePointerOrMouseEvent(event);
    event->m_payload.m_pointer.m_y += scrollBounds.top;
    event->m_payload.m_pointer.m_x += scrollBounds.left;
    return handled;
}
```

- NEW-LU-14 packet child CPP; H blank:

```cpp
bool NewSpellInventoryPane::HandlePacketEvent(Event *event)
{
    const unsigned char *packet =
        static_cast<const unsigned char *>(event->m_payload.m_packet.m_data);
    if (packet != 0 && (unsigned char)(packet[0] - 23) <= 1)
        OnActivate(0);
    return false;
}
```

- NEW-LU-15 timer child CPP; H blank:

```cpp
bool NewSpellInventoryPane::OnTimer(int timerId, int, int)
{
    const short oldPosition = m_scrollPane->m_scrollPosition;
    short position = oldPosition;
    if (timerId == 1)
    {
        if (position > 0)
            --position;
    }
    else if (timerId == 2)
    {
        if (position < m_scrollPane->m_scrollRange)
            ++position;
    }
    else
        return false;

    if (position != oldPosition)
    {
        m_scrollPosition = (signed char)position;
        m_scrollPane->SetScrollPosition(position);
        RebuildSpellList();
        InvalidateRect(&m_visibleBounds);
    }
    ScheduleTimer(timerId, 50, 0, 0);
    return true;
}
```

- NEW-LU-16 spell activation child CPP; H blank:

```cpp
void NewSpellInventoryPane::ActivateSpellSlot(int spellSlot)
{
    if (spellSlot < 1 || spellSlot > kSpellSlotCount)
        return;

    SpellCommandSlotRecord *record =
        g_pUserPane->GetSpellCommandSlotRecord((unsigned char)spellSlot);
    if (!record->active)
        return;

    switch (record->inputKind)
    {
    case 1:
        new SpellStringInputPane((char)spellSlot);
        m_spellInputActive = true;
        break;
    case 2:
        if (g_activeMapPane != 0 &&
            g_activeMapPane->m_selectedObjectActive &&
            g_activeMapPane->m_selectedObjectPane != 0)
        {
            LivingObjectPane *target =
                g_activeMapPane->m_selectedObjectPane;
            MapPoint position;
            target->GetMapPosition(&position);
            SendTargetedActionPacket(
                (unsigned char)spellSlot,
                (unsigned int)target->GetObjectId(),
                (unsigned short)position.column,
                (unsigned short)position.row);
            m_spellInputActive = false;
        }
        else
        {
            new SpellWhoInputPane((char)spellSlot);
            m_spellInputActive = true;
        }
        break;
    case 3:
        new SpellFourArgsInputPane((char)spellSlot);
        m_spellInputActive = true;
        break;
    case 4:
        new SpellThreeArgsInputPane((char)spellSlot);
        m_spellInputActive = true;
        break;
    case 5:
    case 9:
        SendDirectSpellPacket((unsigned char)spellSlot);
        m_spellInputActive = false;
        break;
    case 6:
        new SpellTwoArgsInputPane((char)spellSlot);
        m_spellInputActive = true;
        break;
    case 7:
        new SpellOneArgInputPane((char)spellSlot);
        m_spellInputActive = true;
        break;
    case 8:
        new SpellSlotInputPane((char)spellSlot);
        m_spellInputActive = true;
        break;
    default:
        m_spellInputActive = false;
        break;
    }
}
```

- NEW-LU-17 raw swap helper child CPP; H blank because it is file-static:

```cpp
namespace
{
void SendSwapSpellPacket(unsigned char fromSlot, unsigned char toSlot)
{
    unsigned char packet[5];
    packet[0] = 0x30;
    PacketBufferWriteUInt8(1, packet + 1);
    PacketBufferWriteUInt8(fromSlot, packet + 2);
    PacketBufferWriteUInt8(toSlot, packet + 3);
    packet[4] = 0;
    g_packetSender->QueueAndSendPacket(packet, 4);
}
}
```

- NEW-LU-18 direct packet child CPP; H blank because it is file-static:

```cpp
namespace
{
void SendDirectSpellPacket(unsigned char spellSlot)
{
    if (g_activeDialogCount > 0)
        return;

    unsigned char packet[3];
    PacketBufferWriteUInt8(0x0f, packet);
    PacketBufferWriteUInt8(spellSlot, packet + 1);
    packet[2] = 0;
    g_packetSender->QueueAndSendPacket(packet, 2);
}
}
```

- NEW-LU-19 button rectangle child CPP; H blank because it is file-static:

```cpp
namespace
{
bool GetButtonRect(short part, RectBounds *bounds)
{
    if (part != 2)
        return false;
    InitRectBounds(bounds, 168, 37, 185, 54);
    return true;
}
}
```

- NEW-LU-20 row rectangle child CPP; H blank:

```cpp
bool NewSpellInventoryPane::BuildSpellRowRect(
    int row, RectBounds *bounds) const
{
    const int lastRow = m_expanded ? 26 : 12;
    if (row < 0 || row > lastRow)
        return false;
    InitRectBounds(bounds, 2, 16 + 20 * row, 170, 36 + 20 * row);
    return true;
}
```

- NEW-LU-21 button hit-test child CPP; H blank because it is file-static:

```cpp
namespace
{
short HitTestButton(int localX, int localY)
{
    short part;
    for (part = 0; part <= 2; ++part)
    {
        RectBounds bounds;
        if (GetButtonRect(part, &bounds) &&
            PointInRect(localY, localX, &bounds))
            return part;
    }
    return -1;
}
}
```

- NEW-LU-22 spell-row hit-test child CPP; H blank:

```cpp
int NewSpellInventoryPane::HitTestSpellRow(int localX, int localY) const
{
    const int lastRow = m_expanded ? 26 : 12;
    int row;
    for (row = 0; row <= lastRow; ++row)
    {
        RectBounds bounds;
        if (BuildSpellRowRect(row, &bounds) &&
            PointInRect(localY, localX, &bounds))
            return row;
    }
    return -1;
}
```

- NEW-LU-23 visible-slot child CPP; H blank:

```cpp
int NewSpellInventoryPane::ResolveVisibleSpellSlot(short visibleOrdinal) const
{
    if (m_expanded)
    {
        const char spellSlot = (char)visibleOrdinal;
        if (spellSlot < 1 || spellSlot > kSpellSlotCount)
            return -1;
        SpellCommandSlotRecord *record =
            g_pUserPane->GetSpellCommandSlotRecord(
                (unsigned char)spellSlot);
        return record->active ? spellSlot : -1;
    }

    short learnedOrdinal = 0;
    char spellSlot;
    for (spellSlot = 1; spellSlot <= kSpellSlotCount; ++spellSlot)
    {
        SpellCommandSlotRecord *record =
            g_pUserPane->GetSpellCommandSlotRecord(
                (unsigned char)spellSlot);
        if (record->active)
            ++learnedOrdinal;
        if (learnedOrdinal == visibleOrdinal)
            return spellSlot;
    }
    return -1;
}
```

- NEW-LU-24 row-origin child CPP; H blank:

```cpp
void NewSpellInventoryPane::BuildSpellRowOrigin(Point *origin, int row) const
{
    InitPointPair(origin, 19, m_expanded ? 17 : 12);
    origin->y += 20 * row;
}
```

- NEW-LU-25 stop-timer child CPP; H blank:

```cpp
void NewSpellInventoryPane::StopActiveRepeatTimer()
{
    if (!m_activeRepeatTimer)
        return;
    CancelTimer(m_activeRepeatTimer);
    m_activeRepeatTimer = 0;
}
```

- NEW-LU-26 expanded-mode child CPP; H blank:

```cpp
void NewSpellInventoryPane::ToggleExpandedMode()
{
    m_expandButtonState = 2;
    m_scrollPosition = 0;
    m_expanded = !m_expanded;

    RemoveFromLayer();
    RectBounds bounds;
    SetBounds(&bounds, 0);
    AddToLayer(&bounds, 0, g_pBackPane,
               g_mainUiLayerSlots.rootPaneLayerContext);
    RebuildSpellList();
    InvalidateRect(&m_visibleBounds);
}
```

- NEW-LU-T1 layout page CPP exact comment; H blank because UID00009A owns the declaration:

```cpp
// NewSpellInventoryPane storage is declared by UID00009A; this exact layout page documents the allocator-proven 0x148 object and emits no duplicate fields.
```

- UID0000CN Scroll class CPP replacement:

```cpp
#include "ScrollSpellInventoryPane.h"

[[CHILDREN]]
```

- UID0000CN Scroll class H replacement is its current accepted declaration moved out of CPP, with this exact relationship added before `private:`:

```cpp
#ifndef NEXUSTK_UI_INVENTORY_SCROLLSPELLINVENTORYPANE_H
#define NEXUSTK_UI_INVENTORY_SCROLLSPELLINVENTORYPANE_H

#include "../core/Pane.h"

class Event;
class NewSpellInventoryPane;

enum ScrollSpellInventoryPart {
    kScrollSpellInventoryPartLeading = 0,
    kScrollSpellInventoryPartPageBeforeThumb = 1,
    kScrollSpellInventoryPartThumb = 2,
    kScrollSpellInventoryPartPageAfterThumb = 3,
    kScrollSpellInventoryPartTrailing = 4,
    kScrollSpellInventoryPartNone = -1
};

class ScrollSpellInventoryPane : public Pane
{
public:
    explicit ScrollSpellInventoryPane(unsigned char orientation);

    void SetSizeIndex(unsigned short sizeIndex);
    void SetScrollStyle(unsigned char style);
    void SetMaxRange(short range);
    void SetScrollPosition(short position);
    void Activate();
    void Deactivate();
    bool CanScroll() const;

protected:
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual void OnPaint();

private:
    friend class NewSpellInventoryPane;

    ScrollSpellInventoryPart HitTestPart(int localY, int localX);
    void GetPartRect(ScrollSpellInventoryPart part, RectBounds *rect);
    void SetHoverPart(ScrollSpellInventoryPart part);
    void BeginInteraction(ScrollSpellInventoryPart part,
                          int localY,
                          int localX);
    void UpdateDragScroll(int localY, int localX);
    void UpdateFromDrag(int localY, int localX);
    void ResetScrollState();

    unsigned short m_sizeIndex;
    unsigned char m_scrollStyle;
    bool m_thumbDragActive;
    unsigned char m_orientation;
    short m_scrollPosition;
    short m_scrollRange;
    bool m_enabled;
    signed char m_hoverPart;
    signed char m_activePart;
    Point m_thumbDragOffset;
};

typedef char ScrollSpellInventoryPaneSizeMustBe272[
    sizeof(ScrollSpellInventoryPane) == 0x110 ? 1 : -1];

#endif
```

- No-code dispositions: UID0000LU by-file has no formal channel; UID0002RJ broad core remains blank; ownerless `nullsub_54` has no page/emitter/formal channel; UID0002RL compiler wrapper/thunks, switch tables, EH/cookie records, padding, macro vtable data, and resources emit no handwritten bodies. Their source effects are covered by ordinary destructor/class virtuals, switch statements, compiler output, or exact use-site literals. Shared globals emit only through their established owners.

## Final Recommendation

- B009-owned ordinary implementation is complete through UID00009A, 25 exact source children, UID000534 layout, and both generated CPP/H.
- Supervisor Gate 2A passed all 65 report claims, and the later supervisor Gate 2B transaction is applied, verified, and saved with fresh post-save attestation/readback.
- Owner chain `0000LU -> 00009A -> exact children` is implemented; UID0002RJ is a non-emitting split/index.
- Scroll remains separate with repaired CPP/H placement and NewSpell friendship; accepted method children and evidence remain unchanged.
- Preserve foreign UID0001IJ, ownerless disconnected `nullsub_54`, compiler UID0002RL, vtable/macro data, resources, globals, and all padding with explicit no-source dispositions; `[0x0057e18f,0x0057e190)` is the literal one-byte partition before pointer-event switch data.
- Retain the six repaired support-header guards and exact include order. They preserve every prior declaration while making each assembled header self-contained and duplicate-safe under the NewSpell/UserPane/MapPane include graph.
- Preserve every renewed prototype and all existing frames/ranges/bytes/xrefs/identities. Supervisor Gate 2B applied and verified 19 pure function renames with regular function comments and five raw regular address comments; I06 and P01-P03 were already exact, and P04 was rejected with no mutation. Post-save readback verified the complete contract.
- No in-scope future research remains. Original private spellings could only be improved by unavailable original source/debug symbols and do not block this reconstruction.

## Recommended Target Doc Changes

- Implementation result: the accepted target changes below are incorporated and scoped-validated.
- Path: `by-file/NewSpellInventoryPane.md`.
- Replace the context-only raw-body claim with the five exact source definitions and their no-route provenance; add the complete 25-definition inventory, disconnected-nullsub no-code proof, source order, packets/resources/globals, exact boundaries/padding including `[0x0057e18f,0x0057e190)`, `0x148` layout, guarded dependency-header and Scroll relationships, and generated CPP/H completion contract.
- Metadata: raise `86/88` to `94/95`; keep path and `CANONICAL_OWNER:FILE`. State reconstructability in ordinary prose because the by-file schema has no reconstructable header.
- Preserve history: old aggregate no-code, raw no-route, layout uncertainty, fold hypotheses, future-child/helper-name/score, blank/blocked C++, and no-emitted-child statements remain as explicitly dated/superseded rationale rather than being erased.

## Recommended Support Doc Changes

- Implementation result: all B009-owned support changes below are incorporated and scoped-validated; imperative wording is retained as the accepted change contract.
- `by-class/NewSpellInventoryPane.md`: now `94/95` with exact class CPP/H, field table through `+0x147`, complete method/helper inventory, children, and owner/emitter `0000LU`.
- `by-memory/0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md`: raise to `94/95`, set `RECONSTRUCTABLE:FALSE`, keep formal CPP/H blank, enumerate all 25 exact source children plus ownerless `nullsub_54` and compiler/padding/foreign items, and replace raw-context-only rationale.
- Create these 25 exact by-memory paths with callback-allocated unique UIDs, owner/emitter `00009A`, positions shown in the ledger, exact ranges/hashes/evidence/formal CPP: `0x0057cf70-0x0057d03f.NewSpellInventoryPaneConstructor.md`; `0x0057d040-0x0057d075.NewSpellInventoryPaneDestructor.md`; `0x0057d080-0x0057d097.NewSpellInventoryPaneOnActivate.md`; `0x0057d0c0-0x0057d148.NewSpellInventoryPaneUpdateRenderRegion.md`; `0x0057d150-0x0057d1f5.NewSpellInventoryPaneSetBounds.md`; `0x0057d200-0x0057d360.NewSpellInventoryPaneRebuildSpellList.md`; `0x0057d360-0x0057d398.NewSpellInventoryPaneOnScrollPositionChanged.md`; `0x0057d3a0-0x0057d406.NewSpellInventoryPaneAddToLayer.md`; `0x0057d410-0x0057d426.NewSpellInventoryPaneRemoveFromLayer.md`; `0x0057d430-0x0057d8c4.NewSpellInventoryPaneOnPaint.md`; `0x0057d8d0-0x0057d9b1.NewSpellInventoryPaneHandleKeyOrTextEvent.md`; `0x0057d9c0-0x0057e18f.NewSpellInventoryPaneHandlePointerOrMouseEvent.md`; `0x0057e1b0-0x0057e1d8.NewSpellInventoryPaneHandlePacketEvent.md`; `0x0057e1e0-0x0057e2c1.NewSpellInventoryPaneOnTimer.md`; `0x0057e2d0-0x0057e56d.NewSpellInventoryPaneActivateSpellSlot.md`; `0x0057e5a0-0x0057e615.NewSpellInventoryPaneSendSwapSpellPacket.md`; `0x0057e620-0x0057e689.NewSpellInventoryPaneSendDirectSpellPacket.md`; `0x0057e690-0x0057e6e7.NewSpellInventoryPaneGetButtonRect.md`; `0x0057e6f0-0x0057e75a.NewSpellInventoryPaneBuildSpellRowRect.md`; `0x0057e760-0x0057e7f4.NewSpellInventoryPaneHitTestButton.md`; `0x0057e800-0x0057e8c8.NewSpellInventoryPaneHitTestSpellRow.md`; `0x0057e8d0-0x0057e955.NewSpellInventoryPaneResolveVisibleSpellSlot.md`; `0x0057e960-0x0057e99a.NewSpellInventoryPaneBuildSpellRowOrigin.md`; `0x0057e9a0-0x0057e9c5.NewSpellInventoryPaneStopActiveRepeatTimer.md`; `0x0057e9d0-0x0057ea57.NewSpellInventoryPaneToggleExpandedMode.md`.
- Create `by-type/by-struct/NewSpellInventoryPaneLayout.md`, callback-allocated UID, `94/95`, reconstructable true, owner/emitter `00009A`, position `5`, exact formal covered-by comment, natural `0x148` field table, allocation/constructor proof, and stale IDA UDT warning.
- `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md`: add links to the 25 NewSpell exact children, record the disconnected-nullsub no-child disposition, and preserve legacy/Pane2/foreign/compiler split.
- `by-memory/0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors.md`: preserve `91/93` and compiler no-code; link the ordinary destructor child so wrapper versus source destructor is explicit.
- `by-memory/0x0062cfd8-0x0062d418.SpellInventoryMacroReadOnlyData.md`: preserve non-emitting state and add exact 35-dword NewSpell cluster map/hash/boundary if absent; do not emit words.
- `by-file/ScrollSpellInventoryPane.md`: retain score/path/standalone placement; document that normal sibling H is required by NewSpell and reject local reduced declarations.
- `by-class/ScrollSpellInventoryPane.md`: preserve accepted behavior/fields/children; move declaration from CPP to H and add friendship; CPP becomes include plus `[[CHILDREN]]`.
- UIDs `0001GM`, `0001W1`, `0001YS`, `0001GN`, `0001GO`: already preserve aggregate/layout/vtable/update/reset facts at equal or greater depth; add cross-link to the repaired normal header only where current text implies declaration-in-CPP.
- UID0003BX resource page: already present at equal or greater detail; no edit recommended.
- UID0001IJ foreign setter: already present at equal or greater detail; no edit recommended.
- `by-class/UserPane.md`: add forward declaration and `friend class NewSpellInventoryPane;` only; preserve the existing private inline `SpellCommandSlotRecord *GetSpellCommandSlotRecord(unsigned char)` and all record layout. This is the exact formal H access route, not a new getter API.
- UIDs 0000DU/0000DL/0000DV/0000DW/0000DR under `by-file/SpellInputPanes.md`: move each current accepted complete class declaration verbatim from its class CPP channel to H, leaving CPP as `[[CHILDREN]]`; retain current constructor/destructor/submit children. UID0000DS already resides in `SpellInputPanes.h`.
- UID0000DX/UID0000OH: add a complete `SpellWhoInputPane : public LineInputPane` H declaration carrying `explicit SpellWhoInputPane(char spellIndex);`, `virtual ~SpellWhoInputPane();`, protected overrides `virtual bool OnKeyEvent(KeyEvent *event);`, `virtual bool OnMouseEvent(MouseEvent *event);`, `virtual bool OnObjectListMessage(const PacketEvent *event);`, and private `char m_spellIndex;`; forward-declare the three event types and move no body. UID0001L9 changes only linkage from file-static to external and adds exact H declaration `int SendTargetedActionPacket(unsigned char action, unsigned int objectId, unsigned short argument1, unsigned short argument2);`.
- UID0000G6/UID0000JU: move the current complete `WillBeChangedSpellPane` declaration verbatim from HelpPanes CPP to H; leave all method children in CPP. This supplies the exact six-argument constructor used by NewSpell.
- UID0000PQ/UID0001PH/UID0000IT: resolve the signed gate caveat with one definition `signed char g_activeDialogCount;` in DialogPane CPP and one H declaration `extern signed char g_activeDialogCount;`; the target retains the exact positive-only blocking test and creates no duplicate storage.
- UID0000PR/UID0000L3: retain the existing external definition `MapPane *g_activeMapPane = NULL;` and add only `extern MapPane *g_activeMapPane;` to MapPane H. UID00007B under file UID0000KU moves its existing complete LivingObjectPane declaration to `map/LivingObjectPane.h` so NewSpell may call inherited `ObjectPane` accessors through the selected pointer without a reduced local declaration; the previously cited NewMailDialog UID is unrelated.
- UID00028J/UID0000HO: move the existing complete BackPane declaration to `map/BackPane.h` and add `extern BackPane *g_pBackPane;`; keep its existing singleton definition in BackPane CPP. NewSpell includes that owner header and creates no alias.
- Header closure repair: UID0000DL/UID0000DW now open/close `NEXUSTK_UI_DIALOGS_SPELLINPUTPANES_H` with `InputPanes.h` before all NumberArgs derivations; UID0001L9/UID0000DX similarly bound TargetSelectionInputPanes; UID00007Q/UID0000PR bound MapPane and remove the stale empty-child directive; UID00007B self-bounds LivingObjectPane; UID00000S/UID00028J bound BackPane; UID0000FQ/UID0004YC bound UserPane while including `<stddef.h>` and complete LivingObjectPane. All existing declarations remain preserved.
- Exact padding support repair: target/class/core/broad aggregate, pointer child, packet child, and SpellInventoryPane now distinguish `[0x0057e18f,0x0057e190)` padding from `[0x0057e190,0x0057e1b0)` switch data, preserving the complete 27-span alignment inventory.
- UID0000T6, UID0000TN, UID0003YJ, UID0000Q5, UID00006E, UID00004L/UID00004O, UID00028Q, UID00009R, and UID0000F0 need no formal change; their current headers already declare the exact layer, fill, packet, sender, image, event, config, object, and timer contracts consumed here.

## Score And Metadata Recommendation

| Page family | Current | Recommended | Rationale / cap |
| --- | --- | --- | --- |
| UID0000LU file | 94/95 | implemented 94/95 | complete inventory, exact source/header route, no empty marker; cap for original private spelling |
| UID00009A class | 94/95 | implemented 94/95 | complete `0x148` declaration and all children |
| UID0002RJ core | 94/95 false split/index | implemented 94/95 false split/index | complete exact split, deliberately non-emitting mixed container |
| source children | UIDs 00052F-000533 at 92-94/95-96 true | implemented | per-body boundary/behavior strength; raw bodies remain 92/95 due no caller provenance |
| disconnected `nullsub_54` | no page/score; NONE/false | preserved | exact one-byte/zero-edge/no-pointer/no-vtable proof rejects source ownership |
| NewSpell layout | UID000534 94/95 true | implemented | allocator and cross-body offsets; cap for reserved-byte semantics |
| UID0002RL scalar group | 91/93 page, manual 76 | keep page; manual 91 | compiler identity exact; no source desired |
| Scroll file/class/support | 86/88 family | retain unless validator recomputes | only declaration channel placement changes, behavior already complete |

Score-blocker audit: exact children were absent -> resolved with 25 source paths/formal dispositions; CPP/H empty -> resolved with complete dependency-closed source and header; one-byte ownership -> resolved as an ownerless disconnected dead-code artifact by zero-edge/pointer/vtable proof; layout stale -> resolved by allocation and field audit; raw helper liveness uncertain -> bounded exhaustive proof supports source retention while preserving no-route caveat; Scroll and dependency declaration placement -> resolved through exact owner H routes; source names -> descriptive names grounded in behavior. Whole-file/class/core `94/95` remains justified. Scores do not reach 100 because original private names and semantics of reserved bytes `+fb..+ff` are not recoverable.

## Open Questions With Attempted Resolution

- Are raw bodies dead? Checked entry xrefs, pointer/vtable routes, boundaries, bytes, epilogues, neighboring callers, and semantic continuity. Resolution: source-authored definitions retained; call provenance remains unknown but does not block source because dropping the bodies would lose executable behavior. IDA function creation remains unsafe and is not proposed.
- Is Scroll folded into NewSpell? Checked sole caller, complete Scroll route, class/vtables/layout/exact children, generated source, and header requirements. Resolution: standalone private companion is best supported; normal includes/friendship solve callback visibility.
- What is the class size? Checked allocator, base size, constructor high writes, all field consumers, and stale UDT. Resolution: exactly `0x148`.
- What occupies `+fb..+ff`? No live function reads or writes those five bytes. Resolution: source declares explicit reserved storage to preserve offsets; no unsupported semantics are invented. This is the sole semantic unknown and does not affect behavior.
- Are 13/26 row counts inconsistent with expanded row hit-test accepting row 26? Checked both complete bodies. Resolution: preserve each literal condition exactly; do not normalize.
- Does the source need a header? Checked cross-file Scroll callback and class construction. Resolution: yes, complete sibling H is required.
- Is `nullsub_54` a source-empty NewSpell virtual? Checked all directional xrefs, complete vtable words, little-endian VA pointers, surrounding items, declaration slots, and state access. Resolution: no; it is an ownerless disconnected dead-code artifact and receives no child or source.
- Are any formal dependencies invented? Checked every nonlocal token against accepted-callback by-* owners and the dated generated-header readback. Resolution: the six rejected names and all additional report-only wrappers are gone; every retained external is either already declared or has an exact named owner/header repair above.
- No question remains with owner/emitter/split/source/score impact. Original spelling would require unavailable original symbols/source and is only a confidence cap.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The dated manual comparison found stale rows in by-file line 184, by-class line 360, by-memory line 3662, and by-memory line 3665; no NewSpell layout/child rows existed at that historical snapshot. A fresh supervisor reread subsequently verified all 32 literal payload rows below already present exactly in the four manual coverage files and scoped-validated them without content changes. The payload remains preserved verbatim as the exact reconciliation contract and evidence.

- `by-file/-coverage-report.md`, replace the UID0000LU row with:
  `- [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md) : reconstructable : 94% : very-strong : Complete dependency-closed NewSpellInventoryPane source route with 25 exact source definitions, ownerless disconnected nullsub exclusion, allocator-proven 0x148 class layout, normal CPP/H emission through UID00009A, complete lifecycle/render/input/timer/cast/helper/resource/global/vtable inventory, exact foreign/compiler/padding exclusions, and standalone private ScrollSpellInventoryPane header relationship.`
- `by-class/-coverage-report.md`, replace the UID00009A row with:
  `- [UID:00009A][NewSpellInventoryPane](by-class/NewSpellInventoryPane.md) : reconstructable : 94% : very-strong : Complete 0x148 PanelPane-derived NewSpellInventoryPane declaration and 25-child route, preserving child scrollbar, learned/expanded row model, render/input/timer/cast/packet behavior, exact dependency headers, vtable ownership, foreign exclusion, disconnected-nullsub exclusion, and compiler-covered boundaries.`
- `by-memory/-coverage-report.md`, replace UID0002RJ row with:
  `        - [UID:0002RJ][0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers](by-memory/0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md) 0x0057cf70-0x0057ea57 | exact split/index | NewSpellInventoryPaneCoreAndHelpers : not reconstructable : 94% : very-strong : Complete non-emitting index over 25 NewSpell source definitions, ownerless disconnected nullsub_54, embedded foreign UID0001IJ, two switch tables, every padding span, and exact adjacent boundaries; all source emits through exact children owned by UID00009A.`
- `by-memory/-coverage-report.md`, replace UID0002RL row with:
  `        - [UID:0002RL][0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors](by-memory/0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors.md) 0x0057f58b-0x0057f742 | destructor/thunk-group | SpellInventoryScalarDeletingDestructors : not reconstructable : 91% : strong : Compiler-emitted vtable adjustor thunks and scalar deleting destructors for NewSpellInventoryPane, SpellInventoryPane2, and SpellInventoryPane; NewSpell ordinary source destructor is separately preserved at 0x0057d040-0x0057d075.`
- `by-type/by-struct/-coverage-report.md`, insert in alphabetical order after NewGroupPane layout rows, substituting only the callback-allocated UID token:
  `- [UID:000534][NewSpellInventoryPaneLayout](by-type/by-struct/NewSpellInventoryPaneLayout.md) : reconstructable : 94% : very-strong : Allocator-proven 0x148 NewSpellInventoryPane layout with PanelPane base 0xf8, scroll/list/input/timer/expand/drag fields through +0x145, explicit reserved storage preserving +0x100 child pointer alignment, complete constructor/read-write evidence, and one class-owned declaration in UID00009A.`
- `by-memory/-coverage-report.md`, insert these 25 literal rows immediately beneath UID0002RJ and before the existing embedded-foreign UID0001IJ row, in the exact source-position order shown; each child is reconstructable, owned/emitted by UID00009A, has its complete formal CPP body, and has blank H because UID00009A owns the declaration:
  `            - [UID:00052F][0x0057cf70-0x0057d03f.NewSpellInventoryPaneConstructor](by-memory/0x0057cf70-0x0057d03f.NewSpellInventoryPaneConstructor.md) 0x0057cf70-0x0057d03f | constructor | NewSpellInventoryPaneConstructor : reconstructable : 94% : very-strong : Exact constructor source child initializes PanelPane-derived state, the three class views, list/input/timer/expand fields, and allocates and activates the ScrollSpellInventoryPane child; owner/emitter UID00009A at position 10; place immediately beneath UID0002RJ in source-position order.`
  `            - [UID:00052G][0x0057d040-0x0057d075.NewSpellInventoryPaneDestructor](by-memory/0x0057d040-0x0057d075.NewSpellInventoryPaneDestructor.md) 0x0057d040-0x0057d075 | ordinary destructor raw body | NewSpellInventoryPaneDestructor : reconstructable : 92% : strong : Exact ordinary destructor raw source body releases the owned ScrollSpellInventoryPane child and preserves base teardown order without inventing an IDA function object; owner/emitter UID00009A at position 20; place immediately beneath UID0002RJ in source-position order.`
  `            - [UID:00052H][0x0057d080-0x0057d097.NewSpellInventoryPaneOnActivate](by-memory/0x0057d080-0x0057d097.NewSpellInventoryPaneOnActivate.md) 0x0057d080-0x0057d097 | activation virtual | NewSpellInventoryPaneOnActivate : reconstructable : 93% : very-strong : Exact activation override ignores its ABI argument, rebuilds the visible spell list, and invalidates m_visibleBounds; it does not forward activation state to ScrollSpellInventoryPane; owner/emitter UID00009A at position 30; place immediately beneath UID0002RJ in source-position order.`
  `            - [UID:00052I][0x0057d0c0-0x0057d148.NewSpellInventoryPaneUpdateRenderRegion](by-memory/0x0057d0c0-0x0057d148.NewSpellInventoryPaneUpdateRenderRegion.md) 0x0057d0c0-0x0057d148 | child/base layout update | NewSpellInventoryPaneUpdateRenderRegion : reconstructable : 93% : very-strong : Exact layout override updates the PanelPane render region and positions the private scrollbar from the pane bounds; owner/emitter UID00009A at position 40; place immediately beneath UID0002RJ in source-position order.`
  `            - [UID:00052J][0x0057d150-0x0057d1f5.NewSpellInventoryPaneSetBounds](by-memory/0x0057d150-0x0057d1f5.NewSpellInventoryPaneSetBounds.md) 0x0057d150-0x0057d1f5 | fixed collapsed/expanded bounds | NewSpellInventoryPaneSetBounds : reconstructable : 93% : very-strong : Exact bounds setter selects the literal collapsed or expanded pane geometry and propagates the resulting render-region update; owner/emitter UID00009A at position 50; place immediately beneath UID0002RJ in source-position order.`
  `            - [UID:00052K][0x0057d200-0x0057d360.NewSpellInventoryPaneRebuildSpellList](by-memory/0x0057d200-0x0057d360.NewSpellInventoryPaneRebuildSpellList.md) 0x0057d200-0x0057d360 | learned list and scrollbar sync | NewSpellInventoryPaneRebuildSpellList : reconstructable : 94% : very-strong : Exact learned-spell scan rebuilds the visible slot list, preserves literal list limits, and synchronizes scrollbar range and position; owner/emitter UID00009A at position 60; place immediately beneath UID0002RJ in source-position order.`
  `            - [UID:00052L][0x0057d360-0x0057d398.NewSpellInventoryPaneOnScrollPositionChanged](by-memory/0x0057d360-0x0057d398.NewSpellInventoryPaneOnScrollPositionChanged.md) 0x0057d360-0x0057d398 | owner callback | NewSpellInventoryPaneOnScrollPositionChanged : reconstructable : 94% : original-proof : Exact accepted callback updates the stored child position, rebuilds rows, and invalidates only when the position changes; owner/emitter UID00009A at position 70; place immediately beneath UID0002RJ in source-position order.`
  `            - [UID:00052M][0x0057d3a0-0x0057d406.NewSpellInventoryPaneAddToLayer](by-memory/0x0057d3a0-0x0057d406.NewSpellInventoryPaneAddToLayer.md) 0x0057d3a0-0x0057d406 | attach base then child | NewSpellInventoryPaneAddToLayer : reconstructable : 93% : very-strong : Exact lifecycle override attaches the base pane before attaching the owned scrollbar to the same layer; owner/emitter UID00009A at position 80; place immediately beneath UID0002RJ in source-position order.`
  `            - [UID:00052N][0x0057d410-0x0057d426.NewSpellInventoryPaneRemoveFromLayer](by-memory/0x0057d410-0x0057d426.NewSpellInventoryPaneRemoveFromLayer.md) 0x0057d410-0x0057d426 | detach child then base | NewSpellInventoryPaneRemoveFromLayer : reconstructable : 93% : very-strong : Exact lifecycle override detaches the owned scrollbar before removing the base pane from its layer; owner/emitter UID00009A at position 90; place immediately beneath UID0002RJ in source-position order.`
  `            - [UID:00052O][0x0057d430-0x0057d8c4.NewSpellInventoryPaneOnPaint](by-memory/0x0057d430-0x0057d8c4.NewSpellInventoryPaneOnPaint.md) 0x0057d430-0x0057d8c4 | full background/list/button render | NewSpellInventoryPaneOnPaint : reconstructable : 93% : very-strong : Exact paint override draws the inventory background, learned/expanded spell rows, hotkeys, selection state, and expand-button assets through the established graphics owners; owner/emitter UID00009A at position 100; place immediately beneath UID0002RJ in source-position order.`
  `            - [UID:00052P][0x0057d8d0-0x0057d9b1.NewSpellInventoryPaneHandleKeyOrTextEvent](by-memory/0x0057d8d0-0x0057d9b1.NewSpellInventoryPaneHandleKeyOrTextEvent.md) 0x0057d8d0-0x0057d9b1 | keyboard/page/expand input | NewSpellInventoryPaneHandleKeyOrTextEvent : reconstructable : 93% : very-strong : Exact key-down handler translates the event key, handles unmodified PageUp and PageDown with clamped rebuild/invalidate, handles + by toggling expanded mode, clears m_selectedSpellSlot for other keys, and preserves the exact true/false handled returns; owner/emitter UID00009A at position 110; place immediately beneath UID0002RJ in source-position order.`
  `            - [UID:00052Q][0x0057d9c0-0x0057e18f.NewSpellInventoryPaneHandlePointerOrMouseEvent](by-memory/0x0057d9c0-0x0057e18f.NewSpellInventoryPaneHandlePointerOrMouseEvent.md) 0x0057d9c0-0x0057e18f | pointer/drag/swap/cast/wheel bridge | NewSpellInventoryPaneHandlePointerOrMouseEvent : reconstructable : 93% : very-strong : Exact input-kind switch handles cursor move, left-button down, left-button double-click, left-button up, mouse wheel, and default; it preserves input-lock, hover/selection, repeat timer, expand-toggle, drag/swap/cast, coordinate translation, child-scrollbar delegation, and the delegated handled return; owner/emitter UID00009A at position 120; place immediately beneath UID0002RJ in source-position order.`
  `            - [UID:00052R][0x0057e1b0-0x0057e1d8.NewSpellInventoryPaneHandlePacketEvent](by-memory/0x0057e1b0-0x0057e1d8.NewSpellInventoryPaneHandlePacketEvent.md) 0x0057e1b0-0x0057e1d8 | packet 23/24 activation refresh | NewSpellInventoryPaneHandlePacketEvent : reconstructable : 93% : very-strong : Exact packet handler rebuilds and invalidates the spell list for packet event IDs 23 and 24 while preserving the default path; owner/emitter UID00009A at position 130; place immediately beneath UID0002RJ in source-position order.`
  `            - [UID:00052S][0x0057e1e0-0x0057e2c1.NewSpellInventoryPaneOnTimer](by-memory/0x0057e1e0-0x0057e2c1.NewSpellInventoryPaneOnTimer.md) 0x0057e1e0-0x0057e2c1 | repeat scroll timer IDs 1/2 | NewSpellInventoryPaneOnTimer : reconstructable : 93% : very-strong : Exact timer override handles the two repeat-scroll timer IDs, updates the scrollbar position, and preserves stop/reschedule behavior; owner/emitter UID00009A at position 140; place immediately beneath UID0002RJ in source-position order.`
  `            - [UID:00052T][0x0057e2d0-0x0057e56d.NewSpellInventoryPaneActivateSpellSlot](by-memory/0x0057e2d0-0x0057e56d.NewSpellInventoryPaneActivateSpellSlot.md) 0x0057e2d0-0x0057e56d | nine-route cast dispatcher | NewSpellInventoryPaneActivateSpellSlot : reconstructable : 94% : very-strong : Exact nine-way spell activation dispatcher routes direct casts and the required one-, two-, three-, four-argument, string, who, target-selection, and will-change input panes; owner/emitter UID00009A at position 150; place immediately beneath UID0002RJ in source-position order.`
  `            - [UID:00052U][0x0057e5a0-0x0057e615.NewSpellInventoryPaneSendSwapSpellPacket](by-memory/0x0057e5a0-0x0057e615.NewSpellInventoryPaneSendSwapSpellPacket.md) 0x0057e5a0-0x0057e615 | raw file-static opcode 0x30 helper | NewSpellInventoryPaneSendSwapSpellPacket : reconstructable : 92% : strong : Exact raw file-static helper emits the four-byte spell-swap packet with opcode 0x30, subcode 1, and source/destination slots without inventing an IDA function object; owner/emitter UID00009A at position 160; place immediately beneath UID0002RJ in source-position order.`
  `            - [UID:00052V][0x0057e620-0x0057e689.NewSpellInventoryPaneSendDirectSpellPacket](by-memory/0x0057e620-0x0057e689.NewSpellInventoryPaneSendDirectSpellPacket.md) 0x0057e620-0x0057e689 | opcode 0x0f helper | NewSpellInventoryPaneSendDirectSpellPacket : reconstructable : 93% : very-strong : Exact direct-cast helper emits the two-byte opcode 0x0f packet for the selected one-based spell slot through the established packet sender; owner/emitter UID00009A at position 170; place immediately beneath UID0002RJ in source-position order.`
  `            - [UID:00052W][0x0057e690-0x0057e6e7.NewSpellInventoryPaneGetButtonRect](by-memory/0x0057e690-0x0057e6e7.NewSpellInventoryPaneGetButtonRect.md) 0x0057e690-0x0057e6e7 | file-static expand-button rectangle | NewSpellInventoryPaneGetButtonRect : reconstructable : 93% : very-strong : Exact file-static helper returns the fixed local RectBounds [168,37,185,54] only for part 2 and false for every other part; it does not derive the rectangle from pane bounds; owner/emitter UID00009A at position 180; place immediately beneath UID0002RJ in source-position order.`
  `            - [UID:00052X][0x0057e6f0-0x0057e75a.NewSpellInventoryPaneBuildSpellRowRect](by-memory/0x0057e6f0-0x0057e75a.NewSpellInventoryPaneBuildSpellRowRect.md) 0x0057e6f0-0x0057e75a | raw member row bounds helper | NewSpellInventoryPaneBuildSpellRowRect : reconstructable : 92% : strong : Exact raw member helper builds a visible spell-row rectangle from literal origin, width, stride, and collapsed/expanded row limits without inventing an IDA function object; owner/emitter UID00009A at position 190; place immediately beneath UID0002RJ in source-position order.`
  `            - [UID:00052Y][0x0057e760-0x0057e7f4.NewSpellInventoryPaneHitTestButton](by-memory/0x0057e760-0x0057e7f4.NewSpellInventoryPaneHitTestButton.md) 0x0057e760-0x0057e7f4 | raw file-static button-part hit-test | NewSpellInventoryPaneHitTestButton : reconstructable : 92% : strong : Exact raw file-static hit-test checks the literal expand-button part rectangles and returns the matching part index while preserving the miss result; owner/emitter UID00009A at position 200; place immediately beneath UID0002RJ in source-position order.`
  `            - [UID:00052Z][0x0057e800-0x0057e8c8.NewSpellInventoryPaneHitTestSpellRow](by-memory/0x0057e800-0x0057e8c8.NewSpellInventoryPaneHitTestSpellRow.md) 0x0057e800-0x0057e8c8 | row hit-test | NewSpellInventoryPaneHitTestSpellRow : reconstructable : 93% : very-strong : Exact row hit-test walks the literal collapsed/expanded visible-row bounds and returns the matching row while preserving its no-hit result; owner/emitter UID00009A at position 210; place immediately beneath UID0002RJ in source-position order.`
  `            - [UID:000530][0x0057e8d0-0x0057e955.NewSpellInventoryPaneResolveVisibleSpellSlot](by-memory/0x0057e8d0-0x0057e955.NewSpellInventoryPaneResolveVisibleSpellSlot.md) 0x0057e8d0-0x0057e955 | row/ordinal to one-based slot | NewSpellInventoryPaneResolveVisibleSpellSlot : reconstructable : 93% : very-strong : Exact resolver maps a visible row or learned-spell ordinal to its one-based spell slot under the literal collapsed and expanded list rules; owner/emitter UID00009A at position 220; place immediately beneath UID0002RJ in source-position order.`
  `            - [UID:000531][0x0057e960-0x0057e99a.NewSpellInventoryPaneBuildSpellRowOrigin](by-memory/0x0057e960-0x0057e99a.NewSpellInventoryPaneBuildSpellRowOrigin.md) 0x0057e960-0x0057e99a | raw member text origin helper | NewSpellInventoryPaneBuildSpellRowOrigin : reconstructable : 92% : strong : Exact raw member helper returns local Point(y=19+20*row, x=17 when expanded or 12 when collapsed) without using pane position or inventing an IDA function object; owner/emitter UID00009A at position 230; place immediately beneath UID0002RJ in source-position order.`
  `            - [UID:000532][0x0057e9a0-0x0057e9c5.NewSpellInventoryPaneStopActiveRepeatTimer](by-memory/0x0057e9a0-0x0057e9c5.NewSpellInventoryPaneStopActiveRepeatTimer.md) 0x0057e9a0-0x0057e9c5 | cancel/reset repeat timer | NewSpellInventoryPaneStopActiveRepeatTimer : reconstructable : 93% : very-strong : Exact helper cancels the active repeat timer through EventMan and clears the retained timer state only when a timer is active; owner/emitter UID00009A at position 240; place immediately beneath UID0002RJ in source-position order.`
  `            - [UID:000533][0x0057e9d0-0x0057ea57.NewSpellInventoryPaneToggleExpandedMode](by-memory/0x0057e9d0-0x0057ea57.NewSpellInventoryPaneToggleExpandedMode.md) 0x0057e9d0-0x0057ea57 | relayout/rebuild/invalidate toggle | NewSpellInventoryPaneToggleExpandedMode : reconstructable : 93% : very-strong : Exact helper toggles expanded state, reapplies fixed bounds, rebuilds the spell list, and invalidates the pane in the original order; owner/emitter UID00009A at position 250; place immediately beneath UID0002RJ in source-position order.`
- Dated report-repair readback found the manual Scroll rows behaviorally rich but incomplete about the implemented formal topology. The fresh supervisor reread verified both corrected literal rows already present exactly; the preserved payload is:
  - `by-file/-coverage-report.md`, replace UID0000NJ with: `- [UID:0000NJ][ScrollSpellInventoryPane](by-file/ScrollSpellInventoryPane.md) : reconstructable : 86% : strong : Spell-inventory private scrollbar file parent with projected ui/inventory/ScrollSpellInventoryPane.cpp path, sole NewSpellInventoryPane constructor caller, complete range/input/repeat/paint/part-rect helper map, layout/vtable anchors, UpdateFromDrag position 80, ResetScrollState position 90, and reset-helper provenance cap; standalone placement is selected over the historical fold, the complete Pane-derived declaration emits in ScrollSpellInventoryPane.h, ScrollSpellInventoryPane.cpp contains that header include plus the CHILDREN route, and friend class NewSpellInventoryPane grants the exact private callback access.`
  - `by-class/-coverage-report.md`, replace UID0000CN with: `- [UID:0000CN][ScrollSpellInventoryPane](by-class/ScrollSpellInventoryPane.md) : reconstructable : 86% : strong : Spell-inventory private scrollbar attached to standalone ScrollSpellInventoryPane file parent; preserves NewSpellInventoryPane construction/activation, range/position helpers, drag/click/repeat lifecycle, paint/part-rect layout, hover/reset cleanup, layout/vtable anchors, shared scroll-pane read-only-data band, and raw reset-helper provenance cap; the complete 0x110 Pane-derived class declaration with EventHandler/TimerHandler virtuals emits in ScrollSpellInventoryPane.h, ScrollSpellInventoryPane.cpp contains the header include plus CHILDREN route, and friend class NewSpellInventoryPane supplies exact private callback access.`
- No validator-owned `auto-generated/-ag-*` tracker text is proposed.

## Follow-Up Actions

- Supervisor: Gate 2A passed all 65 report claims, Gate 2B is applied/verified/saved with complete post-save readback, and the 32-row Section 28 manual coverage payload is verified already present and validated. Reread the exact repaired report artifact before the remaining supervisor-owned report execution/archive lifecycle action.
- A-agent: none.
- B009 callback history: allocated UIDs 00052F-000534, applied the exact dependency-owner/header/padding repairs, used short leases, scoped-validated every changed destination, completed the final owning-route waited refresh at command 24621, physically reread all affected CPP/H including UserPane, and updated both twins truthfully.
- B009 future research: none for this assignment. Do not start another target until this lifecycle is complete and goal changes.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: strong.
- Remaining uncertainty: only original private spellings and semantics of never-accessed reserved bytes `+fb..+ff`; neither changes binary behavior, boundaries, ownership, dependency closure, or source completeness.
- IDA result confidence: very strong after complete pre-application and post-save I01-I25/P01-P04 readback; the nine corrected prototypes were preserved observations, and no type endpoint was used.

## Validator Results

- Scoped validation covers all 65 changed ordinary documents from exact cwd `E:\NTK\GhidraBridge\source-3\project-documentation`. The accepted callback covered the original 61; this additive repair added four destinations and revalidated all 24 touched destinations, including correction reruns. Every command exited `0`, reported `ok: 1`, and deferred generated refresh. No target-specific validator error occurred.
- Additive-repair diagnostics were non-fatal and exact: `missing_ref_uid` counts were MapPane class 36, g_activeMapPane 2, MapPane file 42, LivingObjectPane class 12, LivingObjectPane file 14, UserPane class 5, and UserPane file 17. Core UID0002RJ reported one preserved `emitter_inactive_has_data` `autogen_value_invalid` warning because its deliberate non-reconstructable split/index retains relationship emitter metadata; both core runs still returned `ok: 1`. All other additive scoped runs had warning count zero, every run had errors zero, and workflow forbids registry/schema repair in this callback.
- The earlier dated Gate 2B report-text-only cycle ran no validator and changed no ordinary/generated state. This later explicit implementation repair is independently itemized below and does not alter that historical fact.

### Supervisor Manual Coverage Verification Receipt

- Fresh supervisor reread matched all `32/32` literal Section 28 payload rows. The by-memory sequence is contiguous and exact: `UID0002RJ` line 3708; `UID00052F` line 3709 through `UID000533` line 3733; `UID0001IJ` line 3734. All four scoped validations exited `0` with `ok: 1`; every content identity remained unchanged.

| Manual coverage artifact | Command result | Exact unchanged content identity |
| --- | --- | --- |
| `by-file/-coverage-report.md` | `000000024683`; exit `0`; `ok: 1` | SHA256 `AAC0C842C626CD28D2815479B78D4D31C282E67E2FDA7E8B9A786E23CFA74CCA`; 173,436 bytes / 321 lines |
| `by-class/-coverage-report.md` | `000000024684`; exit `0`; `ok: 1` | SHA256 `EBAEFAF2697643968A1CD7122C9A5DE9DCAA61F298D6AB3F6D5AFECCD7DB766E`; 281,096 bytes / 628 lines |
| `by-memory/-coverage-report.md` | `000000024685`; exit `0`; `ok: 1`; preserved pre-existing `missing_ref_uid` warnings `00039L`, `0003T6` only | SHA256 `B00AD9E2381A1EFBA642B463DCDB1F3E16A99B2701E03E4873D1B52D58F2E5F8`; 2,275,475 bytes / 5,068 lines |
| `by-type/by-struct/-coverage-report.md` | `000000024686`; exit `0`; `ok: 1` | SHA256 `91F0C70B78FEDD7475C47DF90A0A08C337CF13F340BD4D15ACA3D54A88EBBBB4`; 59,754 bytes / 140 lines |

### Additive Header/Padding Repair Validator Receipts

Every receipt used exact cwd `E:\NTK\GhidraBridge\source-3\project-documentation`; each command is a single scoped file command, exited `0`, reported `ok: 1`, and returned `generated_refresh: deferred`.

| Ordinary document | Exact single-line command | Command ID / timestamp | Warnings / errors | Exact count side effects |
| --- | --- | --- | --- | --- |
| `by-class/SpellFourArgsInputPane.md` | `python .\tools\validator.py --mode file --file "by-class\SpellFourArgsInputPane.md" --apply --queue-timeout 240` | `000000024591` / `2026-08-16T00:09:23-04:00` | warnings `0`; errors `0` | `autogen_registry_update=1,ok=1,projected_stats_update=1,stats_incremental_noop=1` |
| `by-class/SpellTwoArgsInputPane.md` | `python .\tools\validator.py --mode file --file "by-class\SpellTwoArgsInputPane.md" --apply --queue-timeout 240` | `000000024592` / `2026-08-16T00:09:26-04:00` | warnings `0`; errors `0` | `autogen_registry_update=1,ok=1,projected_stats_update=1,stats_incremental_noop=1` |
| `by-file/SpellInputPanes.md` | `python .\tools\validator.py --mode file --file "by-file\SpellInputPanes.md" --apply --queue-timeout 240` | `000000024593` / `2026-08-16T00:09:28-04:00` | warnings `0`; errors `0` | `ok=1,projected_stats_update=1,stats_incremental_noop=1` |
| `by-memory/0x005af4f0-0x005af57b.SendTargetedActionPacket.md` | `python .\tools\validator.py --mode file --file "by-memory\0x005af4f0-0x005af57b.SendTargetedActionPacket.md" --apply --queue-timeout 240` | `000000024594` / `2026-08-16T00:10:11-04:00` | warnings `0`; errors `0` | `autogen_registry_update=1,ok=1,projected_stats_update=1,stats_incremental_noop=1` |
| `by-class/SpellWhoInputPane.md` | `python .\tools\validator.py --mode file --file "by-class\SpellWhoInputPane.md" --apply --queue-timeout 240` | `000000024595` / `2026-08-16T00:10:14-04:00` | warnings `0`; errors `0` | `autogen_registry_update=1,ok=1,projected_stats_update=1,stats_incremental_noop=1` |
| `by-file/TargetSelectionInputPanes.md` | `python .\tools\validator.py --mode file --file "by-file\TargetSelectionInputPanes.md" --apply --queue-timeout 240` | `000000024596` / `2026-08-16T00:10:16-04:00` | warnings `0`; errors `0` | `ok=1,projected_stats_update=1,stats_incremental_noop=1` |
| `by-class/MapPane.md` | `python .\tools\validator.py --mode file --file "by-class\MapPane.md" --apply --queue-timeout 240` | `000000024597` / `2026-08-16T00:12:53-04:00` | `missing_ref_uid=36`; errors `0` | `autogen_registry_update=1,missing_ref_uid=36,ok=1,projected_stats_update=1,stats_incremental_noop=1` |
| `by-global/g_activeMapPane.md` | `python .\tools\validator.py --mode file --file "by-global\g_activeMapPane.md" --apply --queue-timeout 240` | `000000024598` / `2026-08-16T00:12:56-04:00` | `missing_ref_uid=2`; errors `0` | `autogen_registry_update=1,missing_ref_uid=2,ok=1,projected_stats_update=1,stats_row_update=1` |
| `by-file/MapPane.md` | `python .\tools\validator.py --mode file --file "by-file\MapPane.md" --apply --queue-timeout 240` | `000000024599` / `2026-08-16T00:12:58-04:00` | `missing_ref_uid=42`; errors `0` | `missing_ref_uid=42,ok=1,projected_stats_update=1,stats_incremental_noop=1` |
| `by-class/LivingObjectPane.md` | `python .\tools\validator.py --mode file --file "by-class\LivingObjectPane.md" --apply --queue-timeout 240` | `000000024600` / `2026-08-16T00:13:28-04:00` | `missing_ref_uid=12`; errors `0` | `autogen_registry_update=1,missing_ref_uid=12,ok=1,projected_stats_update=1,stats_incremental_noop=1` |
| `by-file/LivingObjectPane.md` | `python .\tools\validator.py --mode file --file "by-file\LivingObjectPane.md" --apply --queue-timeout 240` | `000000024601` / `2026-08-16T00:13:30-04:00` | `missing_ref_uid=14`; errors `0` | `missing_ref_uid=14,ok=1,projected_stats_update=1,stats_incremental_noop=1` |
| `by-class/BackPane.md` | `python .\tools\validator.py --mode file --file "by-class\BackPane.md" --apply --queue-timeout 240` | `000000024602` / `2026-08-16T00:14:06-04:00` | warnings `0`; errors `0` | `autogen_registry_update=1,ok=1,projected_stats_update=1,stats_incremental_noop=1` |
| `by-memory/0x0067a740-0x0067a744.g_pBackPane.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0067a740-0x0067a744.g_pBackPane.md" --apply --queue-timeout 240` | `000000024603` / `2026-08-16T00:14:09-04:00` | warnings `0`; errors `0` | `autogen_registry_update=1,ok=1,projected_stats_update=1,stats_incremental_noop=1` |
| `by-file/BackPane.md` | `python .\tools\validator.py --mode file --file "by-file\BackPane.md" --apply --queue-timeout 240` | `000000024604` / `2026-08-16T00:14:11-04:00` | warnings `0`; errors `0` | `ok=1,projected_stats_update=1,stats_incremental_noop=1` |
| `by-class/UserPane.md` | `python .\tools\validator.py --mode file --file "by-class\UserPane.md" --apply --queue-timeout 240` | `000000024605` / `2026-08-16T00:14:45-04:00` | `missing_ref_uid=5`; errors `0` | `autogen_registry_update=1,missing_ref_uid=5,ok=1,projected_stats_update=1,stats_incremental_noop=1` |
| `by-memory/0x005a4f70-0x005a500f.RequestLocalPlayerStatus.md` | `python .\tools\validator.py --mode file --file "by-memory\0x005a4f70-0x005a500f.RequestLocalPlayerStatus.md" --apply --queue-timeout 240` | `000000024606` / `2026-08-16T00:14:48-04:00` | warnings `0`; errors `0` | `autogen_registry_update=1,ok=1,projected_stats_update=1,stats_incremental_noop=1` |
| `by-file/UserPane.md` | `python .\tools\validator.py --mode file --file "by-file\UserPane.md" --apply --queue-timeout 240` | `000000024607` / `2026-08-16T00:14:50-04:00` | `missing_ref_uid=17`; errors `0` | `missing_ref_uid=17,ok=1,projected_stats_update=1,stats_incremental_noop=1` |
| `by-file/NewSpellInventoryPane.md` | `python .\tools\validator.py --mode file --file "by-file\NewSpellInventoryPane.md" --apply --queue-timeout 240` | `000000024608` / `2026-08-16T00:16:45-04:00` | warnings `0`; errors `0` | `ok=1,projected_stats_update=1,stats_incremental_noop=1` |
| `by-class/NewSpellInventoryPane.md` | `python .\tools\validator.py --mode file --file "by-class\NewSpellInventoryPane.md" --apply --queue-timeout 240` | `000000024609` / `2026-08-16T00:16:47-04:00` | warnings `0`; errors `0` | `ok=1,projected_stats_update=1,stats_incremental_noop=1` |
| `by-memory/0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md" --apply --queue-timeout 240` | `000000024610` / `2026-08-16T00:16:50-04:00` | `autogen_value_invalid=1`; errors `0` | `autogen_value_invalid=1,ok=1,projected_stats_update=1,stats_incremental_noop=1` |
| `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057c2d0-0x0057f742.SpellInventoryPanes.md" --apply --queue-timeout 240` | `000000024611` / `2026-08-16T00:17:08-04:00` | warnings `0`; errors `0` | `ok=1,projected_stats_update=1,stats_incremental_noop=1` |
| `by-memory/0x0057d9c0-0x0057e18f.NewSpellInventoryPaneHandlePointerOrMouseEvent.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057d9c0-0x0057e18f.NewSpellInventoryPaneHandlePointerOrMouseEvent.md" --apply --queue-timeout 240` | `000000024612` / `2026-08-16T00:17:13-04:00` | warnings `0`; errors `0` | `ok=1,projected_stats_update=1,stats_incremental_noop=1` |
| `by-memory/0x0057e1b0-0x0057e1d8.NewSpellInventoryPaneHandlePacketEvent.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057e1b0-0x0057e1d8.NewSpellInventoryPaneHandlePacketEvent.md" --apply --queue-timeout 240` | `000000024613` / `2026-08-16T00:17:28-04:00` | warnings `0`; errors `0` | `ok=1,projected_stats_update=1,stats_incremental_noop=1` |
| `by-file/SpellInventoryPane.md` | `python .\tools\validator.py --mode file --file "by-file\SpellInventoryPane.md" --apply --queue-timeout 240` | `000000024614` / `2026-08-16T00:17:41-04:00` | warnings `0`; errors `0` | `ok=1,projected_stats_update=1,stats_incremental_noop=1` |
| `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057c2d0-0x0057f742.SpellInventoryPanes.md" --apply --queue-timeout 240` | `000000024615` / `2026-08-16T00:18:38-04:00` | warnings `0`; errors `0` | `ok=1,projected_stats_update=1,stats_incremental_noop=1` |
| `by-file/NewSpellInventoryPane.md` | `python .\tools\validator.py --mode file --file "by-file\NewSpellInventoryPane.md" --apply --queue-timeout 240` | `000000024618` / `2026-08-16T00:22:36-04:00` | warnings `0`; errors `0` | `ok=1,projected_stats_update=1,stats_incremental_noop=1` |
| `by-class/NewSpellInventoryPane.md` | `python .\tools\validator.py --mode file --file "by-class\NewSpellInventoryPane.md" --apply --queue-timeout 240` | `000000024619` / `2026-08-16T00:22:39-04:00` | warnings `0`; errors `0` | `ok=1,projected_stats_update=1,stats_incremental_noop=1` |
| `by-memory/0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md" --apply --queue-timeout 240` | `000000024620` / `2026-08-16T00:22:41-04:00` | `autogen_value_invalid=1`; errors `0` | `autogen_value_invalid=1,ok=1,projected_stats_update=1,stats_incremental_noop=1` |

### Per-Document Scoped Validator Receipts

| Ordinary document | Exact command | Command ID / timestamp | Result | Generated state and exact count side effects |
| --- | --- | --- | --- | --- |
| `by-class/BackPane.md` | `python .\tools\validator.py --mode file --file "by-class\BackPane.md" --apply --queue-timeout 240` | `000000024402` / `2026-08-15T19:17:52-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=1,ok=1,projected_stats_update=1,stats_incremental_noop=1,generated_refresh_command_id=000000024402` |
| `by-class/LivingObjectPane.md` | `python .\tools\validator.py --mode file --file "by-class\LivingObjectPane.md" --apply --queue-timeout 240` | `000000024400` / `2026-08-15T19:17:28-04:00` | exit `0`; `ok=1`; non-fatal missing_ref_uid=12; errors=0 | `deferred`; `autogen_registry_update=1,missing_ref_uid=12,ok=1,projected_stats_update=1,stats_incremental_noop=1,generated_refresh_command_id=000000024400` |
| `by-class/NewSpellInventoryPane.md` | `python .\tools\validator.py --mode file --file "by-class\NewSpellInventoryPane.md" --apply --queue-timeout 240` | `000000024427` / `2026-08-15T19:25:34-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=1,ok=1,projected_stats_update=1,stats_incremental_noop=1,generated_refresh_command_id=000000024427` |
| `by-class/ScrollSpellInventoryPane.md` | `python .\tools\validator.py --mode file --file "by-class\ScrollSpellInventoryPane.md" --apply --queue-timeout 240` | `000000024428` / `2026-08-15T19:26:02-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `ok=1,projected_stats_update=1,stats_row_update=2,generated_refresh_command_id=000000024428` |
| `by-class/SpellFourArgsInputPane.md` | `python .\tools\validator.py --mode file --file "by-class\SpellFourArgsInputPane.md" --apply --queue-timeout 240` | `000000024384` / `2026-08-15T19:10:59-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=1,ok=1,projected_stats_update=1,stats_incremental_noop=1,generated_refresh_command_id=000000024384` |
| `by-class/SpellOneArgInputPane.md` | `python .\tools\validator.py --mode file --file "by-class\SpellOneArgInputPane.md" --apply --queue-timeout 240` | `000000024387` / `2026-08-15T19:11:37-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=1,ok=1,projected_stats_update=1,stats_incremental_noop=1,generated_refresh_command_id=000000024387` |
| `by-class/SpellStringInputPane.md` | `python .\tools\validator.py --mode file --file "by-class\SpellStringInputPane.md" --apply --queue-timeout 240` | `000000024383` / `2026-08-15T19:10:47-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=1,ok=1,projected_stats_update=1,stats_incremental_noop=1,generated_refresh_command_id=000000024383` |
| `by-class/SpellThreeArgsInputPane.md` | `python .\tools\validator.py --mode file --file "by-class\SpellThreeArgsInputPane.md" --apply --queue-timeout 240` | `000000024385` / `2026-08-15T19:11:12-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=1,ok=1,projected_stats_update=1,stats_incremental_noop=1,generated_refresh_command_id=000000024385` |
| `by-class/SpellTwoArgsInputPane.md` | `python .\tools\validator.py --mode file --file "by-class\SpellTwoArgsInputPane.md" --apply --queue-timeout 240` | `000000024386` / `2026-08-15T19:11:25-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=1,ok=1,projected_stats_update=1,stats_incremental_noop=1,generated_refresh_command_id=000000024386` |
| `by-class/SpellWhoInputPane.md` | `python .\tools\validator.py --mode file --file "by-class\SpellWhoInputPane.md" --apply --queue-timeout 240` | `000000024418` / `2026-08-15T19:23:02-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `ok=1,projected_stats_update=1,stats_incremental_noop=1,generated_refresh_command_id=000000024418` |
| `by-class/UserPane.md` | `python .\tools\validator.py --mode file --file "by-class\UserPane.md" --apply --queue-timeout 240` | `000000024388` / `2026-08-15T19:13:13-04:00` | exit `0`; `ok=1`; non-fatal missing_ref_uid=5; errors=0 | `deferred`; `autogen_registry_update=1,missing_ref_uid=5,ok=1,projected_stats_update=1,stats_incremental_noop=1,generated_refresh_command_id=000000024388` |
| `by-class/WillBeChangedSpellPane.md` | `python .\tools\validator.py --mode file --file "by-class\WillBeChangedSpellPane.md" --apply --queue-timeout 240` | `000000024393` / `2026-08-15T19:15:18-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=3,ok=1,projected_stats_update=1,stats_incremental_noop=1,generated_refresh_command_id=000000024393` |
| `by-file/BackPane.md` | `python .\tools\validator.py --mode file --file "by-file\BackPane.md" --apply --queue-timeout 240` | `000000024404` / `2026-08-15T19:18:16-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `ok=1,projected_stats_update=1,stats_incremental_noop=1,generated_refresh_command_id=000000024404` |
| `by-file/DialogPane.md` | `python .\tools\validator.py --mode file --file "by-file\DialogPane.md" --apply --queue-timeout 240` | `000000024397` / `2026-08-15T19:15:57-04:00` | exit `0`; `ok=1`; non-fatal missing_ref_uid=4; errors=0 | `deferred`; `missing_ref_uid=4,ok=1,projected_stats_update=1,stats_incremental_noop=1,generated_refresh_command_id=000000024397` |
| `by-file/HelpPanes.md` | `python .\tools\validator.py --mode file --file "by-file\HelpPanes.md" --apply --queue-timeout 240` | `000000024394` / `2026-08-15T19:15:22-04:00` | exit `0`; `ok=1`; non-fatal missing_ref_uid=1; errors=0 | `deferred`; `missing_ref_uid=1,ok=1,projected_stats_update=1,stats_incremental_noop=1,generated_refresh_command_id=000000024394` |
| `by-file/LivingObjectPane.md` | `python .\tools\validator.py --mode file --file "by-file\LivingObjectPane.md" --apply --queue-timeout 240` | `000000024401` / `2026-08-15T19:17:41-04:00` | exit `0`; `ok=1`; non-fatal missing_ref_uid=14; errors=0 | `deferred`; `missing_ref_uid=14,ok=1,projected_stats_update=1,stats_incremental_noop=1,generated_refresh_command_id=000000024401` |
| `by-file/MapPane.md` | `python .\tools\validator.py --mode file --file "by-file\MapPane.md" --apply --queue-timeout 240` | `000000024399` / `2026-08-15T19:17:16-04:00` | exit `0`; `ok=1`; non-fatal missing_ref_uid=42; errors=0 | `deferred`; `missing_ref_uid=42,ok=1,projected_stats_update=1,reference_index_add=1,stats_incremental_noop=1,generated_refresh_command_id=000000024399` |
| `by-file/NewSpellInventoryPane.md` | `python .\tools\validator.py --mode file --file "by-file\NewSpellInventoryPane.md" --apply --queue-timeout 240` | `000000024405` / `2026-08-15T19:19:36-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `completion_update=1,confidence_update=1,ok=1,projected_stats_update=1,reference_index_add=25,stats_incremental_noop=1,uid_link_update=25,generated_refresh_command_id=000000024405` |
| `by-file/ScrollSpellInventoryPane.md` | `python .\tools\validator.py --mode file --file "by-file\ScrollSpellInventoryPane.md" --apply --queue-timeout 240` | `000000024411` / `2026-08-15T19:21:16-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `ok=1,projected_stats_update=1,stats_incremental_noop=1,generated_refresh_command_id=000000024411` |
| `by-file/SpellInputPanes.md` | `python .\tools\validator.py --mode file --file "by-file\SpellInputPanes.md" --apply --queue-timeout 240` | `000000024417` / `2026-08-15T19:22:59-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `ok=1,projected_stats_update=1,stats_incremental_noop=1,generated_refresh_command_id=000000024417` |
| `by-file/TargetSelectionInputPanes.md` | `python .\tools\validator.py --mode file --file "by-file\TargetSelectionInputPanes.md" --apply --queue-timeout 240` | `000000024419` / `2026-08-15T19:23:12-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `ok=1,projected_stats_update=1,stats_incremental_noop=1,generated_refresh_command_id=000000024419` |
| `by-global/g_activeDialogCount.md` | `python .\tools\validator.py --mode file --file "by-global\g_activeDialogCount.md" --apply --queue-timeout 240` | `000000024395` / `2026-08-15T19:15:34-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=2,ok=1,projected_stats_update=1,stats_row_update=2,generated_refresh_command_id=000000024395` |
| `by-global/g_activeMapPane.md` | `python .\tools\validator.py --mode file --file "by-global\g_activeMapPane.md" --apply --queue-timeout 240` | `000000024398` / `2026-08-15T19:17:13-04:00` | exit `0`; `ok=1`; non-fatal missing_ref_uid=2; errors=0 | `deferred`; `autogen_registry_update=2,missing_ref_uid=2,ok=1,projected_stats_update=1,stats_row_update=1,generated_refresh_command_id=000000024398` |
| `by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0055f450-0x005608fc.ScrollSpellInventoryPane.md" --apply --queue-timeout 240` | `000000024412` / `2026-08-15T19:21:31-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `ok=1,projected_stats_update=1,stats_row_update=1,generated_refresh_command_id=000000024412` |
| `by-memory/0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag.md` | `python .\tools\validator.py --mode file --file "by-memory\0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag.md" --apply --queue-timeout 240` | `000000024415` / `2026-08-15T19:22:09-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `ok=1,projected_stats_update=1,stats_incremental_noop=1,generated_refresh_command_id=000000024415` |
| `by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md` | `python .\tools\validator.py --mode file --file "by-memory\0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md" --apply --queue-timeout 240` | `000000024416` / `2026-08-15T19:22:20-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `ok=1,projected_stats_update=1,stats_incremental_noop=1,generated_refresh_command_id=000000024416` |
| `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057c2d0-0x0057f742.SpellInventoryPanes.md" --apply --queue-timeout 240` | `000000024408` / `2026-08-15T19:20:42-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `ok=1,projected_stats_update=1,reference_index_add=25,stats_incremental_noop=1,uid_link_update=25,generated_refresh_command_id=000000024408` |
| `by-memory/0x0057cf70-0x0057d03f.NewSpellInventoryPaneConstructor.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057cf70-0x0057d03f.NewSpellInventoryPaneConstructor.md" --apply --queue-timeout 240` | `000000024330` / `2026-08-15T18:51:24-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=5,canonical_owner_update=1,completion_update=1,confidence_update=1,ok=1,projected_stats_update=1,reference_index_add=5,stats_incremental_noop=1,uid_link_update=5,generated_refresh_command_id=000000024330` |
| `by-memory/0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md" --apply --queue-timeout 240` | `000000024407` / `2026-08-15T19:19:51-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=1,autogen_value_invalid=1,completion_update=1,confidence_update=1,ok=1,projected_stats_update=1,reference_index_add=25,stats_incremental_noop=1,uid_link_update=25,generated_refresh_command_id=000000024407` |
| `by-memory/0x0057d040-0x0057d075.NewSpellInventoryPaneDestructor.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057d040-0x0057d075.NewSpellInventoryPaneDestructor.md" --apply --queue-timeout 240` | `000000024429` / `2026-08-15T19:27:14-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `ok=1,projected_stats_update=1,stats_incremental_noop=1,generated_refresh_command_id=000000024429` |
| `by-memory/0x0057d080-0x0057d097.NewSpellInventoryPaneOnActivate.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057d080-0x0057d097.NewSpellInventoryPaneOnActivate.md" --apply --queue-timeout 240` | `000000024334` / `2026-08-15T18:55:25-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=5,canonical_owner_update=1,completion_update=1,confidence_update=1,ok=1,projected_stats_update=1,reference_index_add=4,stats_incremental_noop=1,generated_refresh_command_id=000000024334` |
| `by-memory/0x0057d0c0-0x0057d148.NewSpellInventoryPaneUpdateRenderRegion.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057d0c0-0x0057d148.NewSpellInventoryPaneUpdateRenderRegion.md" --apply --queue-timeout 240` | `000000024336` / `2026-08-15T18:55:44-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=5,canonical_owner_update=1,completion_update=1,confidence_update=1,ok=1,projected_stats_update=1,reference_index_add=4,stats_incremental_noop=1,generated_refresh_command_id=000000024336` |
| `by-memory/0x0057d150-0x0057d1f5.NewSpellInventoryPaneSetBounds.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057d150-0x0057d1f5.NewSpellInventoryPaneSetBounds.md" --apply --queue-timeout 240` | `000000024338` / `2026-08-15T18:56:03-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=5,canonical_owner_update=1,completion_update=1,confidence_update=1,ok=1,projected_stats_update=1,reference_index_add=4,stats_incremental_noop=1,generated_refresh_command_id=000000024338` |
| `by-memory/0x0057d200-0x0057d360.NewSpellInventoryPaneRebuildSpellList.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057d200-0x0057d360.NewSpellInventoryPaneRebuildSpellList.md" --apply --queue-timeout 240` | `000000024340` / `2026-08-15T18:56:23-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=5,canonical_owner_update=1,completion_update=1,confidence_update=1,ok=1,projected_stats_update=1,reference_index_add=4,stats_incremental_noop=1,generated_refresh_command_id=000000024340` |
| `by-memory/0x0057d360-0x0057d398.NewSpellInventoryPaneOnScrollPositionChanged.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057d360-0x0057d398.NewSpellInventoryPaneOnScrollPositionChanged.md" --apply --queue-timeout 240` | `000000024342` / `2026-08-15T18:56:42-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=5,canonical_owner_update=1,completion_update=1,confidence_update=1,ok=1,projected_stats_update=1,reference_index_add=4,stats_incremental_noop=1,generated_refresh_command_id=000000024342` |
| `by-memory/0x0057d3a0-0x0057d406.NewSpellInventoryPaneAddToLayer.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057d3a0-0x0057d406.NewSpellInventoryPaneAddToLayer.md" --apply --queue-timeout 240` | `000000024344` / `2026-08-15T18:57:58-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=5,canonical_owner_update=1,completion_update=1,confidence_update=1,ok=1,projected_stats_update=1,reference_index_add=4,stats_incremental_noop=1,generated_refresh_command_id=000000024344` |
| `by-memory/0x0057d410-0x0057d426.NewSpellInventoryPaneRemoveFromLayer.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057d410-0x0057d426.NewSpellInventoryPaneRemoveFromLayer.md" --apply --queue-timeout 240` | `000000024346` / `2026-08-15T18:58:17-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=5,canonical_owner_update=1,completion_update=1,confidence_update=1,ok=1,projected_stats_update=1,reference_index_add=4,stats_incremental_noop=1,generated_refresh_command_id=000000024346` |
| `by-memory/0x0057d430-0x0057d8c4.NewSpellInventoryPaneOnPaint.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057d430-0x0057d8c4.NewSpellInventoryPaneOnPaint.md" --apply --queue-timeout 240` | `000000024348` / `2026-08-15T18:58:36-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=5,canonical_owner_update=1,completion_update=1,confidence_update=1,ok=1,projected_stats_update=1,reference_index_add=4,stats_incremental_noop=1,generated_refresh_command_id=000000024348` |
| `by-memory/0x0057d8d0-0x0057d9b1.NewSpellInventoryPaneHandleKeyOrTextEvent.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057d8d0-0x0057d9b1.NewSpellInventoryPaneHandleKeyOrTextEvent.md" --apply --queue-timeout 240` | `000000024350` / `2026-08-15T18:58:56-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=5,canonical_owner_update=1,completion_update=1,confidence_update=1,ok=1,projected_stats_update=1,reference_index_add=4,stats_incremental_noop=1,generated_refresh_command_id=000000024350` |
| `by-memory/0x0057d9c0-0x0057e18f.NewSpellInventoryPaneHandlePointerOrMouseEvent.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057d9c0-0x0057e18f.NewSpellInventoryPaneHandlePointerOrMouseEvent.md" --apply --queue-timeout 240` | `000000024352` / `2026-08-15T18:59:15-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=5,canonical_owner_update=1,completion_update=1,confidence_update=1,ok=1,projected_stats_update=1,reference_index_add=4,stats_incremental_noop=1,generated_refresh_command_id=000000024352` |
| `by-memory/0x0057e1b0-0x0057e1d8.NewSpellInventoryPaneHandlePacketEvent.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057e1b0-0x0057e1d8.NewSpellInventoryPaneHandlePacketEvent.md" --apply --queue-timeout 240` | `000000024354` / `2026-08-15T18:59:35-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=5,canonical_owner_update=1,completion_update=1,confidence_update=1,ok=1,projected_stats_update=1,reference_index_add=4,stats_incremental_noop=1,generated_refresh_command_id=000000024354` |
| `by-memory/0x0057e1e0-0x0057e2c1.NewSpellInventoryPaneOnTimer.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057e1e0-0x0057e2c1.NewSpellInventoryPaneOnTimer.md" --apply --queue-timeout 240` | `000000024356` / `2026-08-15T18:59:54-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=5,canonical_owner_update=1,completion_update=1,confidence_update=1,ok=1,projected_stats_update=1,reference_index_add=4,stats_incremental_noop=1,generated_refresh_command_id=000000024356` |
| `by-memory/0x0057e2d0-0x0057e56d.NewSpellInventoryPaneActivateSpellSlot.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057e2d0-0x0057e56d.NewSpellInventoryPaneActivateSpellSlot.md" --apply --queue-timeout 240` | `000000024358` / `2026-08-15T19:00:14-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=5,canonical_owner_update=1,completion_update=1,confidence_update=1,ok=1,projected_stats_update=1,reference_index_add=4,stats_incremental_noop=1,generated_refresh_command_id=000000024358` |
| `by-memory/0x0057e5a0-0x0057e615.NewSpellInventoryPaneSendSwapSpellPacket.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057e5a0-0x0057e615.NewSpellInventoryPaneSendSwapSpellPacket.md" --apply --queue-timeout 240` | `000000024360` / `2026-08-15T19:00:33-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=5,canonical_owner_update=1,completion_update=1,confidence_update=1,ok=1,projected_stats_update=1,reference_index_add=4,stats_incremental_noop=1,generated_refresh_command_id=000000024360` |
| `by-memory/0x0057e620-0x0057e689.NewSpellInventoryPaneSendDirectSpellPacket.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057e620-0x0057e689.NewSpellInventoryPaneSendDirectSpellPacket.md" --apply --queue-timeout 240` | `000000024362` / `2026-08-15T19:01:46-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=5,canonical_owner_update=1,completion_update=1,confidence_update=1,ok=1,projected_stats_update=1,reference_index_add=3,stats_incremental_noop=1,generated_refresh_command_id=000000024362` |
| `by-memory/0x0057e690-0x0057e6e7.NewSpellInventoryPaneGetButtonRect.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057e690-0x0057e6e7.NewSpellInventoryPaneGetButtonRect.md" --apply --queue-timeout 240` | `000000024364` / `2026-08-15T19:02:06-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=5,canonical_owner_update=1,completion_update=1,confidence_update=1,ok=1,projected_stats_update=1,reference_index_add=3,stats_incremental_noop=1,generated_refresh_command_id=000000024364` |
| `by-memory/0x0057e6f0-0x0057e75a.NewSpellInventoryPaneBuildSpellRowRect.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057e6f0-0x0057e75a.NewSpellInventoryPaneBuildSpellRowRect.md" --apply --queue-timeout 240` | `000000024366` / `2026-08-15T19:02:25-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=5,canonical_owner_update=1,completion_update=1,confidence_update=1,ok=1,projected_stats_update=1,reference_index_add=3,stats_incremental_noop=1,generated_refresh_command_id=000000024366` |
| `by-memory/0x0057e760-0x0057e7f4.NewSpellInventoryPaneHitTestButton.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057e760-0x0057e7f4.NewSpellInventoryPaneHitTestButton.md" --apply --queue-timeout 240` | `000000024368` / `2026-08-15T19:02:44-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=5,canonical_owner_update=1,completion_update=1,confidence_update=1,ok=1,projected_stats_update=1,reference_index_add=3,stats_incremental_noop=1,generated_refresh_command_id=000000024368` |
| `by-memory/0x0057e800-0x0057e8c8.NewSpellInventoryPaneHitTestSpellRow.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057e800-0x0057e8c8.NewSpellInventoryPaneHitTestSpellRow.md" --apply --queue-timeout 240` | `000000024370` / `2026-08-15T19:03:03-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=5,canonical_owner_update=1,completion_update=1,confidence_update=1,ok=1,projected_stats_update=1,reference_index_add=3,stats_incremental_noop=1,generated_refresh_command_id=000000024370` |
| `by-memory/0x0057e8d0-0x0057e955.NewSpellInventoryPaneResolveVisibleSpellSlot.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057e8d0-0x0057e955.NewSpellInventoryPaneResolveVisibleSpellSlot.md" --apply --queue-timeout 240` | `000000024372` / `2026-08-15T19:03:22-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=5,canonical_owner_update=1,completion_update=1,confidence_update=1,ok=1,projected_stats_update=1,reference_index_add=3,stats_incremental_noop=1,generated_refresh_command_id=000000024372` |
| `by-memory/0x0057e960-0x0057e99a.NewSpellInventoryPaneBuildSpellRowOrigin.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057e960-0x0057e99a.NewSpellInventoryPaneBuildSpellRowOrigin.md" --apply --queue-timeout 240` | `000000024374` / `2026-08-15T19:03:42-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=5,canonical_owner_update=1,completion_update=1,confidence_update=1,ok=1,projected_stats_update=1,reference_index_add=3,stats_incremental_noop=1,generated_refresh_command_id=000000024374` |
| `by-memory/0x0057e9a0-0x0057e9c5.NewSpellInventoryPaneStopActiveRepeatTimer.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057e9a0-0x0057e9c5.NewSpellInventoryPaneStopActiveRepeatTimer.md" --apply --queue-timeout 240` | `000000024376` / `2026-08-15T19:04:01-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=5,canonical_owner_update=1,completion_update=1,confidence_update=1,ok=1,projected_stats_update=1,reference_index_add=3,stats_incremental_noop=1,generated_refresh_command_id=000000024376` |
| `by-memory/0x0057e9d0-0x0057ea57.NewSpellInventoryPaneToggleExpandedMode.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057e9d0-0x0057ea57.NewSpellInventoryPaneToggleExpandedMode.md" --apply --queue-timeout 240` | `000000024378` / `2026-08-15T19:04:21-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=5,canonical_owner_update=1,completion_update=1,confidence_update=1,ok=1,projected_stats_update=1,reference_index_add=3,stats_incremental_noop=1,generated_refresh_command_id=000000024378` |
| `by-memory/0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors.md" --apply --queue-timeout 240` | `000000024409` / `2026-08-15T19:20:45-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `ok=1,projected_stats_update=1,reference_index_add=1,stats_incremental_noop=1,uid_link_update=1,generated_refresh_command_id=000000024409` |
| `by-memory/0x005af4f0-0x005af57b.SendTargetedActionPacket.md` | `python .\tools\validator.py --mode file --file "by-memory\0x005af4f0-0x005af57b.SendTargetedActionPacket.md" --apply --queue-timeout 240` | `000000024391` / `2026-08-15T19:14:43-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=3,ok=1,projected_stats_update=1,stats_incremental_noop=1,generated_refresh_command_id=000000024391` |
| `by-memory/0x0062cfd8-0x0062d418.SpellInventoryMacroReadOnlyData.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0062cfd8-0x0062d418.SpellInventoryMacroReadOnlyData.md" --apply --queue-timeout 240` | `000000024410` / `2026-08-15T19:21:01-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `ok=1,projected_stats_update=1,stats_incremental_noop=1,generated_refresh_command_id=000000024410` |
| `by-memory/0x0067a740-0x0067a744.g_pBackPane.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0067a740-0x0067a744.g_pBackPane.md" --apply --queue-timeout 240` | `000000024403` / `2026-08-15T19:18:04-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `ok=1,projected_stats_update=1,stats_incremental_noop=1,generated_refresh_command_id=000000024403` |
| `by-memory/0x0069b380-0x0069b381.g_activeDialogCount.md` | `python .\tools\validator.py --mode file --file "by-memory\0x0069b380-0x0069b381.g_activeDialogCount.md" --apply --queue-timeout 240` | `000000024396` / `2026-08-15T19:15:46-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `ok=1,projected_stats_update=1,stats_incremental_noop=1,generated_refresh_command_id=000000024396` |
| `by-type/by-struct/NewSpellInventoryPaneLayout.md` | `python .\tools\validator.py --mode file --file "by-type\by-struct\NewSpellInventoryPaneLayout.md" --apply --queue-timeout 240` | `000000024380` / `2026-08-15T19:06:55-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `autogen_registry_update=5,canonical_owner_update=1,completion_update=1,confidence_update=1,ok=1,projected_stats_update=1,reference_index_add=4,stats_incremental_noop=1,generated_refresh_command_id=000000024380` |
| `by-type/by-struct/ScrollSpellInventoryPaneLayout.md` | `python .\tools\validator.py --mode file --file "by-type\by-struct\ScrollSpellInventoryPaneLayout.md" --apply --queue-timeout 240` | `000000024413` / `2026-08-15T19:21:43-04:00` | exit `0`; `ok=1`; diagnostics=0; errors=0 | `deferred`; `ok=1,projected_stats_update=1,stats_row_update=4,generated_refresh_command_id=000000024413` |
| `by-type/by-vtable/ScrollSpellInventoryPaneVtables.md` | `python .\tools\validator.py --mode file --file "by-type\by-vtable\ScrollSpellInventoryPaneVtables.md" --apply --queue-timeout 240` | `000000024414` / `2026-08-15T19:21:58-04:00` | exit `0`; `ok=1`; non-fatal missing_ref_uid=3; errors=0 | `deferred`; `missing_ref_uid=3,ok=1,projected_stats_update=1,stats_row_update=2,generated_refresh_command_id=000000024414` |

### Allocated UIDs

| Allocated UID | New ordinary document |
| --- | --- |
| `00052F` | `by-memory/0x0057cf70-0x0057d03f.NewSpellInventoryPaneConstructor.md` |
| `00052G` | `by-memory/0x0057d040-0x0057d075.NewSpellInventoryPaneDestructor.md` |
| `00052H` | `by-memory/0x0057d080-0x0057d097.NewSpellInventoryPaneOnActivate.md` |
| `00052I` | `by-memory/0x0057d0c0-0x0057d148.NewSpellInventoryPaneUpdateRenderRegion.md` |
| `00052J` | `by-memory/0x0057d150-0x0057d1f5.NewSpellInventoryPaneSetBounds.md` |
| `00052K` | `by-memory/0x0057d200-0x0057d360.NewSpellInventoryPaneRebuildSpellList.md` |
| `00052L` | `by-memory/0x0057d360-0x0057d398.NewSpellInventoryPaneOnScrollPositionChanged.md` |
| `00052M` | `by-memory/0x0057d3a0-0x0057d406.NewSpellInventoryPaneAddToLayer.md` |
| `00052N` | `by-memory/0x0057d410-0x0057d426.NewSpellInventoryPaneRemoveFromLayer.md` |
| `00052O` | `by-memory/0x0057d430-0x0057d8c4.NewSpellInventoryPaneOnPaint.md` |
| `00052P` | `by-memory/0x0057d8d0-0x0057d9b1.NewSpellInventoryPaneHandleKeyOrTextEvent.md` |
| `00052Q` | `by-memory/0x0057d9c0-0x0057e18f.NewSpellInventoryPaneHandlePointerOrMouseEvent.md` |
| `00052R` | `by-memory/0x0057e1b0-0x0057e1d8.NewSpellInventoryPaneHandlePacketEvent.md` |
| `00052S` | `by-memory/0x0057e1e0-0x0057e2c1.NewSpellInventoryPaneOnTimer.md` |
| `00052T` | `by-memory/0x0057e2d0-0x0057e56d.NewSpellInventoryPaneActivateSpellSlot.md` |
| `00052U` | `by-memory/0x0057e5a0-0x0057e615.NewSpellInventoryPaneSendSwapSpellPacket.md` |
| `00052V` | `by-memory/0x0057e620-0x0057e689.NewSpellInventoryPaneSendDirectSpellPacket.md` |
| `00052W` | `by-memory/0x0057e690-0x0057e6e7.NewSpellInventoryPaneGetButtonRect.md` |
| `00052X` | `by-memory/0x0057e6f0-0x0057e75a.NewSpellInventoryPaneBuildSpellRowRect.md` |
| `00052Y` | `by-memory/0x0057e760-0x0057e7f4.NewSpellInventoryPaneHitTestButton.md` |
| `00052Z` | `by-memory/0x0057e800-0x0057e8c8.NewSpellInventoryPaneHitTestSpellRow.md` |
| `000530` | `by-memory/0x0057e8d0-0x0057e955.NewSpellInventoryPaneResolveVisibleSpellSlot.md` |
| `000531` | `by-memory/0x0057e960-0x0057e99a.NewSpellInventoryPaneBuildSpellRowOrigin.md` |
| `000532` | `by-memory/0x0057e9a0-0x0057e9c5.NewSpellInventoryPaneStopActiveRepeatTimer.md` |
| `000533` | `by-memory/0x0057e9d0-0x0057ea57.NewSpellInventoryPaneToggleExpandedMode.md` |
| `000534` | `by-type/by-struct/NewSpellInventoryPaneLayout.md` |

### Coherent Refresh And Physical Readback

- Dated accepted-callback refresh receipt: cwd `E:\NTK\GhidraBridge\source-3\project-documentation`; command `python .\tools\validator.py --mode autogen --apply --wait-generated --queue-timeout 240`; command ID `000000024420`; timestamp `2026-08-15T19:23:19-04:00`; exit `0`; `generated_refresh: completed`; registry rebuild `1`; generated metadata refresh `276`; header metadata refresh `134`; CPP update `1`. That callback-time refresh also reported project-wide pre-existing informational counts `autogen_children_marker_missing=71`, `autogen_emitter_has_no_code=67`, `autogen_children_fallback_insert=7`, and `autogen_header_children_marker_missing=1`; these values are historical receipts, not current generated authority.
- Dated accepted-callback correction: two empty H-child directives produced literal `[[No Children Attached]]` in the first physical readback. B009 removed only those directives from UID00009A/UID0000CN, scoped-validated at the dated callback as commands `000000024427` and `000000024428`, and physically confirmed that callback refresh removed both markers. Dated callback command `000000024429` supplied the raw destructor's retained final scoped receipt and refreshed the target emitter without changing source content. Commands `000000024420` through `000000024429` are historical callback snapshots only.
- Dated accepted-callback physical target audit: 25 exact child UID markers, one UID000534 layout marker, definitions ordered at positions `10..250`, complete preamble, complete `0x148` H, zero foreign UID0001IJ/nullsub/UID0002RL bodies, and zero `[[CHILDREN]]`, `[[No Children Attached]]`, TODO, placeholder, stub, or empty-emitter text in target CPP/H.
- Dated accepted-callback dependency audit: Scroll H friendship=1 and CPP class declaration=0; SpellInput H expected classes=6 and moved CPP declarations=0; TargetSelection H SpellWho/helper declarations=1 each and static helper definition=0; Help H WillBeChangedSpellPane=1; Dialog CPP/H signed definition/extern=1 each; Map H extern=1; Living H class=1 and CPP duplicate=0; Back H class/extern=1 each and CPP duplicate=0. Across the 18 affected callback-read generated CPP/H files, literal `[[CHILDREN]]` count was zero.
- Dated read-only report-repair observation: command `000000024441`, refreshed `2026-08-15T20:29:30-04:00`, was observed in generated artifact metadata during this repair. Physical readback observed NewSpell CPP SHA256 `EE0E0EA08A134A4DDA16FE1A6FF2806E3116AB48BA24159D5049A52C669FD092`, 25,231 bytes / 748 lines; NewSpell H SHA256 `0341E59A7660BA525BC0F94F1575AE489D1FFCC2D188C2EBE30786A592394B9F`, 2,464 bytes / 67 lines; Scroll CPP SHA256 `F86F7E79411AD3E41E414DD1B3074CC95C117D8EE3BFE9096A35B45B38BC0D12`, 4,759 bytes / 122 lines; and Scroll H SHA256 `4F61CB946BF196535FCA48BFBC038BCE3D5E758555BB2522B09384ADE2730E8D`, 2,382 bytes / 72 lines. At that dated observation the complete target/Scroll physical semantics remained closed: 25 ordered children, one layout marker, complete declarations, header/include/children/friend topology, and no foreign/nullsub/compiler handwritten body or unresolved marker. Command `000000024441` and these hashes are not permanent current authority; every later supervisor gate must dynamically reread the then-current generated artifacts.
- Intermediate waited repair observation: exact command `python .\tools\validator.py --mode file --file "by-file\NewSpellInventoryPane.md" --apply --wait-generated --queue-timeout 240`, command `000000024616`, timestamp `2026-08-16T00:18:56-04:00`, exit `0`, `ok=1`, completed generation with `autogen_registry_rebuild=1`, `generated_metadata_refresh=277`, `autogen_header_metadata_refresh=137`, `autogen_children_fallback_insert=7`, `autogen_children_marker_missing=72`, `autogen_emitter_has_no_code=66`, `autogen_header_children_marker_missing=1`, and `autogen_header_noop=131`. Physical reread exposed only a prose alignment-count reconciliation; B009 corrected the three affected ordinary summaries and scoped-validated commands 24618-24620 before the final refresh.
- Final owning-route waited repair snapshot: same exact command, command `000000024621`, timestamp `2026-08-16T00:23:06-04:00`, exit `0`, `ok=1`, `generated_refresh: completed`, with the same exact generated count fields as command 24616. Physical reread after completion proved: all 14 artifacts carry command 24621 metadata; six repaired support headers each have `ifndef=1`, `define=1`, `endif=1`; SpellInputPanes includes `InputPanes.h` before the first NumberArgs class; UserPane includes `<stddef.h>` then complete LivingObjectPane before derivation; MapPane/UserPane/NewSpell direct and indirect includes emit no duplicate class body; MapPane H has no empty-child token; NewSpell CPP orders UID000534 then UID00052F-UID000533; all checked outputs contain zero `[[CHILDREN]]` and `[[No Children Attached]]` tokens. These are dated snapshot facts, and supervisor Gate 2 remains responsible for then-current physical reread.

| Dated additive-repair generated artifact | SHA256 observed after command 24621 | Bytes / lines | Generator command / refresh |
| --- | --- | ---: | --- |
| `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp` | `8FE4E5BCA03D4130D6B33E477BA834ADAB6DAC8FF1C825C838E014F9C09251B5` | 18670 / 512 | `000000024621` / `2026-08-16T00:23:06-04:00` |
| `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.h` | `97F086DCD6FC6A5F519B193D2724098DBD5C0A5AC3CE1A38D7FD51E95F003DE5` | 2532 / 102 | `000000024621` / `2026-08-16T00:23:06-04:00` |
| `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` | `D256BDEFCD7CF93F2374568418D7C6376D922A068DA9C0DBBD5589FEC1C3D816` | 46081 / 1274 | `000000024621` / `2026-08-16T00:23:06-04:00` |
| `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.h` | `87AD84D6346EFBF377330FABFD0C62A4FB5BDFDC46C7B8D334E2C86A0B98BAB5` | 1238 / 36 | `000000024621` / `2026-08-16T00:23:06-04:00` |
| `auto-generated/NexusTK/map/MapPane.cpp` | `4AC5686280640FF282C3CC7560E57E3747E86D20650F03D92B01AA92AA9E3C29` | 159492 / 4776 | `000000024621` / `2026-08-16T00:23:06-04:00` |
| `auto-generated/NexusTK/map/MapPane.h` | `7CA38798C9EB141B1F001D5F5CF10638B6C2D078337FD56AE4EFEDB0507A2E3E` | 13210 / 378 | `000000024621` / `2026-08-16T00:23:06-04:00` |
| `auto-generated/NexusTK/map/LivingObjectPane.cpp` | `9360C37A731E9CA23330DAE800EA79EFDFE662364B497076B537AA78FE7D4CBF` | 31226 / 1020 | `000000024621` / `2026-08-16T00:23:06-04:00` |
| `auto-generated/NexusTK/map/LivingObjectPane.h` | `F88C4DF0B71D1D6E2918ED19FD6E6DF7DA4B7D7E45BE1F04F6476EFF40FC692E` | 5129 / 152 | `000000024621` / `2026-08-16T00:23:06-04:00` |
| `auto-generated/NexusTK/map/BackPane.cpp` | `8CC9B8DA681C9326682403989B17611B163D83F86A6D8550E487AC0B4141E473` | 8955 / 295 | `000000024621` / `2026-08-16T00:23:06-04:00` |
| `auto-generated/NexusTK/map/BackPane.h` | `62E6F8181F51AF0C036C8041145822983DFEADBAEBE96A38B8B70DEA194686FF` | 1157 / 38 | `000000024621` / `2026-08-16T00:23:06-04:00` |
| `auto-generated/NexusTK/ui/panels/UserPane.cpp` | `D2886424BB381A703BC8542C6960A550EF418982FA0AC3FF002BD9A4963DA9BB` | 87893 / 2672 | `000000024621` / `2026-08-16T00:23:06-04:00` |
| `auto-generated/NexusTK/ui/panels/UserPane.h` | `BF97FC21A545B3AF8B3572A1C85C022B3D9F0CA0A857646082005FFF4A10208B` | 11595 / 347 | `000000024621` / `2026-08-16T00:23:06-04:00` |
| `auto-generated/NexusTK/ui/inventory/NewSpellInventoryPane.cpp` | `0CFA28389C6496DF709070FDE03AF4F12022F8B4956B617526A4CC2548E3EAD1` | 25231 / 748 | `000000024621` / `2026-08-16T00:23:06-04:00` |
| `auto-generated/NexusTK/ui/inventory/NewSpellInventoryPane.h` | `152F7DE810EACE5862440A83AF10A1B5575572D8D2ECF99487CB199B8C5D031C` | 2464 / 67 | `000000024621` / `2026-08-16T00:23:06-04:00` |

| Dated accepted-callback generated artifact | Dated callback SHA256 | Bytes / lines | Dated callback generator command / refresh |
| --- | --- | ---: | --- |
| `auto-generated/NexusTK/ui/inventory/NewSpellInventoryPane.cpp` | `376FA815608C5DB2C78E4CE2E47EAF24C47F2DDD720A9027502C2DBCABB2653E` | 25229 / 748 | `000000024429` / `2026-08-15T19:27:14-04:00` |
| `auto-generated/NexusTK/ui/inventory/NewSpellInventoryPane.h` | `27CD475489D1681AE6F4F1E2ED0F3E5451028DC4753230EA54CA500E8F57D3A5` | 2462 / 67 | `000000024429` / `2026-08-15T19:27:14-04:00` |
| `auto-generated/NexusTK/ui/inventory/ScrollSpellInventoryPane.cpp` | `D83F6F660461B5DA5EC354305B345849A7F625757FC9973A56B3BD69396096C5` | 4757 / 122 | `000000024428` / `2026-08-15T19:26:02-04:00` |
| `auto-generated/NexusTK/ui/inventory/ScrollSpellInventoryPane.h` | `5EF9E828C9A63B59FE3A47003F8FD77FFC0693A10429456DF8B45C30C3466305` | 2380 / 72 | `000000024428` / `2026-08-15T19:26:02-04:00` |
| `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.cpp` | `B2DD757B0CA138656220B5993F4608E7EA2EE3ED39A59AF05A1C92B59361586B` | 18670 / 512 | `000000024426` / `2026-08-15T19:25:29-04:00` |
| `auto-generated/NexusTK/ui/dialogs/SpellInputPanes.h` | `C7E1B1E521F170853F6A906245FBF916627A6EEB917CCD95E409281EFDE05728` | 2368 / 95 | `000000024426` / `2026-08-15T19:25:29-04:00` |
| `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` | `E7442BFBBECCF7B54200E15E6429FEE6A80D8051851F0C0A80B6EBB598D424F2` | 46081 / 1274 | `000000024426` / `2026-08-15T19:25:29-04:00` |
| `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.h` | `14262337FC26186A730284E8EDA572F84CDAB38020539B29A82D701D759A2D33` | 1069 / 31 | `000000024426` / `2026-08-15T19:25:29-04:00` |
| `auto-generated/NexusTK/ui/controls/HelpPanes.cpp` | `F6CF5AD1EF795865372A87A4DE08F1724FA6CBCFB276363B01A8AEFC3F5BED5F` | 51623 / 1576 | `000000024426` / `2026-08-15T19:25:29-04:00` |
| `auto-generated/NexusTK/ui/controls/HelpPanes.h` | `18E153FDA27A2F7BB39133B8B2E616D7DFC1DF055D1F440854229D217D6EE942` | 2118 / 72 | `000000024426` / `2026-08-15T19:25:29-04:00` |
| `auto-generated/NexusTK/ui/core/DialogPane.cpp` | `FF4BD351344B97BFC16CA9021F49E86E415DA4B390245537F51C5AF0DDE43B62` | 17453 / 526 | `000000024426` / `2026-08-15T19:25:29-04:00` |
| `auto-generated/NexusTK/ui/core/DialogPane.h` | `4F95BDA56240092D905891CB6E33B0FDB552447F631C89C3E2CC09720BC1F134` | 3544 / 102 | `000000024426` / `2026-08-15T19:25:29-04:00` |
| `auto-generated/NexusTK/map/MapPane.cpp` | `6DA4EE57B7303A420FB72DBE0F9E42A0915070ED79D1FA466B574BFA58B1687E` | 159492 / 4776 | `000000024426` / `2026-08-15T19:25:29-04:00` |
| `auto-generated/NexusTK/map/MapPane.h` | `5C7011870726FDD2DE015015498CBB21971F983F2B31290AD94C6839754206D8` | 13142 / 375 | `000000024426` / `2026-08-15T19:25:29-04:00` |
| `auto-generated/NexusTK/map/LivingObjectPane.cpp` | `7E05BB22E7111D683BBD5E610232C58279382772714E96620280F52FD0915B71` | 31226 / 1020 | `000000024426` / `2026-08-15T19:25:29-04:00` |
| `auto-generated/NexusTK/map/LivingObjectPane.h` | `C3FF396F4D314E89B793EF984B0F6ED3780331E19F952A171BB1AA3E05A224FA` | 5008 / 147 | `000000024426` / `2026-08-15T19:25:29-04:00` |
| `auto-generated/NexusTK/map/BackPane.cpp` | `49CC98D9682E580E1DBE18C93B05E0497381D6F7C840F6F774F757C13A711F73` | 8955 / 295 | `000000024426` / `2026-08-15T19:25:29-04:00` |
| `auto-generated/NexusTK/map/BackPane.h` | `D6207956E624F906926FBD21C2F352D63863C3ACCF809ED51DD4994D8752D2A7` | 1060 / 33 | `000000024426` / `2026-08-15T19:25:29-04:00` |

## Changed Files

- Created 26 ordinary support documents and modified 39 existing ordinary documents. The exact ordinary artifacts at B009's dated final repair snapshot are:

| Change | UID | Ordinary path | SHA256 | Bytes / lines |
| --- | --- | --- | --- | ---: |
| modified | `00000S` | `by-class/BackPane.md` | `14FF0A75487058F434BC40FC8B8AC11D9DBD690154B7023D95406025A594E52D` | 21024 / 142 |
| modified | `00007B` | `by-class/LivingObjectPane.md` | `2690E7923EDDDA84BA430F101E04B65BDA2597C062F19CF8C032933F7A06A817` | 133170 / 700 |
| modified | `00007Q` | `by-class/MapPane.md` | `0B743E3441A37A10EB509C71C186F07ACF6835C23ABD08BA383F7D9D9B77F1E7` | 198995 / 1098 |
| modified | `00009A` | `by-class/NewSpellInventoryPane.md` | `E493D103F43B0693EB44F46177350F8E0E825988D7AB8D12398BABD8A56E905E` | 35252 / 309 |
| modified | `0000CN` | `by-class/ScrollSpellInventoryPane.md` | `C2AA91A0042DEDABCCFA4C31817310E5477926FF083C63C3386395F82AF1A83F` | 27751 / 219 |
| modified | `0000DL` | `by-class/SpellFourArgsInputPane.md` | `FCD042698F2ED7BF4B06D7DBA0181D5E337AECB1BA451B52B1C7C6D38DF6C18D` | 12811 / 104 |
| modified | `0000DR` | `by-class/SpellOneArgInputPane.md` | `B28A47228C64A8D89D54FFE7D05F6522980321E373DEFF9C5190EA84C539F51E` | 12732 / 111 |
| modified | `0000DU` | `by-class/SpellStringInputPane.md` | `2D9653D08B641C63042FB5E105FF47410901415737877BF34AB2C5629E8D8E26` | 13659 / 109 |
| modified | `0000DV` | `by-class/SpellThreeArgsInputPane.md` | `545610723095FA80991FBAE80C8FFE2AE51F66F0B4B0538171EDE5422EBDFA12` | 14563 / 120 |
| modified | `0000DW` | `by-class/SpellTwoArgsInputPane.md` | `4675145D9B1023376C5AEC3E053D19D798B7C4CF2F96E569567A83493E200DD8` | 12779 / 117 |
| modified | `0000DX` | `by-class/SpellWhoInputPane.md` | `D83C1D110666F74263B25C7E826512C8BC73A37C83F32B2C5580FE6F35DBE509` | 14811 / 137 |
| modified | `0000FQ` | `by-class/UserPane.md` | `4FFFEC6BBC2F73B64407CBF038274979677CE1D71F16A6D759EFA87E08CA4839` | 115372 / 843 |
| modified | `0000G6` | `by-class/WillBeChangedSpellPane.md` | `89EEFA16A5D6C50890D2D52BC4F90E17BA14C7C0918DB14BFB77BC46B14EBA94` | 12291 / 134 |
| modified | `0000HO` | `by-file/BackPane.md` | `DC31703D1AB4D19570F7BB3CE65C3A7F891B8C00EA43DBC402F4A4E4E94E46CC` | 30411 / 142 |
| modified | `0000IT` | `by-file/DialogPane.md` | `793D1D5093F3FFF9742145613CA00410EF5DC60D9B86FAFED00E548164CB09D7` | 33773 / 195 |
| modified | `0000JU` | `by-file/HelpPanes.md` | `A6F0B80DDF139BEC94E4987A4F94FCABBF90D309E4BB7B268087A1F2351B823F` | 84914 / 354 |
| modified | `0000KU` | `by-file/LivingObjectPane.md` | `AFB90200F438522FBBFD2A5F0B45DF1641CF1A0CF04220EC2801DEBE6814E5D1` | 123260 / 453 |
| modified | `0000L3` | `by-file/MapPane.md` | `2E23B41FCD70DF53A24BE8055594C85DDD5D3AF097EE8D0B634932F08A57EB78` | 206321 / 845 |
| modified | `0000LU` | `by-file/NewSpellInventoryPane.md` | `E90567D7180BF2AFDB799BE3B581DEAF99EF7D0CFFC40A164AE66B7DF04A6694` | 25071 / 148 |
| modified | `0000NJ` | `by-file/ScrollSpellInventoryPane.md` | `149C922E55FC35304D73C70526211817624E744210FD080268A23DF9C29A4FDE` | 19388 / 135 |
| modified | `0000O0` | `by-file/SpellInputPanes.md` | `CA35734183FF5B18490E479E6AF3A2964E639AA37B1AC46ADB2EE55BBECDEF06` | 80310 / 308 |
| modified | `0000O1` | `by-file/SpellInventoryPane.md` | `F27F79EC4AC7FE03500E31F364CD9D88419008F99B1B6219C8891B05753F4C4C` | 21511 / 132 |
| modified | `0000OH` | `by-file/TargetSelectionInputPanes.md` | `F79BBCC220BC28E1DAD7694C64A7B0308CDB3B2E7F01226E4290DCEDDB2A9F0C` | 79852 / 278 |
| modified | `0000P1` | `by-file/UserPane.md` | `C7BC9F787532FA68BC61EFFAE4E6D1098E60D6C00B29448F71AB74EB9CA8CA78` | 125470 / 527 |
| modified | `0000PQ` | `by-global/g_activeDialogCount.md` | `0653422463741A110749EA2A999F243184AB64317BD782250386BF9ABB4DBFC2` | 9423 / 80 |
| modified | `0000PR` | `by-global/g_activeMapPane.md` | `B1F3307BF7694EB964B5DE2C1D4AFA6D265A0138593D78976E30883FB0949CC3` | 14378 / 125 |
| modified | `0001GM` | `by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md` | `670E2ADA5D544644B484DA8E3D03A2BD20E14288E4E390056D1474529059B19D` | 33484 / 198 |
| modified | `0001GN` | `by-memory/0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag.md` | `890526D9AA21F1F34AA5F4817EB672A7602D49DC83C357C59087C0B3EE3D8E0D` | 18171 / 202 |
| modified | `0001GO` | `by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md` | `6A3FEF899B745056B0FDCD522AFD959B42B1B804FE8C0AA1572F537C518C0321` | 17583 / 145 |
| modified | `0001IH` | `by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md` | `717D2C8A00C8CEB0D334BC52A666752F7BEF75746AE2D23CB67D068CDBEBA5EB` | 31218 / 167 |
| created | `00052F` | `by-memory/0x0057cf70-0x0057d03f.NewSpellInventoryPaneConstructor.md` | `741EF907B24C07BC4AE32AAFBBF2F7F3C66A9D92AD03A4F5D8AC647DFE447A63` | 3949 / 63 |
| modified | `0002RJ` | `by-memory/0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md` | `FF924E36E9B27AC419E1026670D692FC550BC0CF78891EBA256279F9D5962903` | 40102 / 300 |
| created | `00052G` | `by-memory/0x0057d040-0x0057d075.NewSpellInventoryPaneDestructor.md` | `0BC041801F381CE88D3608B0B16868F5D925AD69A266E6686E8A9555B2DDC240` | 3364 / 51 |
| created | `00052H` | `by-memory/0x0057d080-0x0057d097.NewSpellInventoryPaneOnActivate.md` | `524B3EFC0C789F3E45083D82254EF507C394AE716EADCCEA7FA4981271EC1905` | 3082 / 51 |
| created | `00052I` | `by-memory/0x0057d0c0-0x0057d148.NewSpellInventoryPaneUpdateRenderRegion.md` | `5DE515AB331956A028908B46A58C51821707E47BD572B3E6DDB39CC0AFF48E79` | 3411 / 55 |
| created | `00052J` | `by-memory/0x0057d150-0x0057d1f5.NewSpellInventoryPaneSetBounds.md` | `DAFFD54BC3966D5A38A2FFB656E5412518E807BABBFEA8A03A2E779444B42AE4` | 3457 / 59 |
| created | `00052K` | `by-memory/0x0057d200-0x0057d360.NewSpellInventoryPaneRebuildSpellList.md` | `6E005ACD76FDEFBD438303F53A408CB1A827C793E60E2A54A6CB3E2ECC6CAAE7` | 4345 / 79 |
| created | `00052L` | `by-memory/0x0057d360-0x0057d398.NewSpellInventoryPaneOnScrollPositionChanged.md` | `7CE139DC71BA7ED848C59F9B7B8AD48327DFF9ACDED20060836B7BC41F8843C3` | 3482 / 57 |
| created | `00052M` | `by-memory/0x0057d3a0-0x0057d406.NewSpellInventoryPaneAddToLayer.md` | `1DAB924A053B902C358E2312900B78AAE1C131392032743923F3090D312DC8EA` | 3322 / 55 |
| created | `00052N` | `by-memory/0x0057d410-0x0057d426.NewSpellInventoryPaneRemoveFromLayer.md` | `219B8F9CEEBB4D4983A21A0030C5BD22B69D69F19FCF24F7801B7F62697053F7` | 2964 / 51 |
| created | `00052O` | `by-memory/0x0057d430-0x0057d8c4.NewSpellInventoryPaneOnPaint.md` | `E11DD7E3A6561399AFBF853ED309105FECB3EEAE9A8245750B4B4D8DADB4BD22` | 6191 / 139 |
| created | `00052P` | `by-memory/0x0057d8d0-0x0057d9b1.NewSpellInventoryPaneHandleKeyOrTextEvent.md` | `89E1DB73DA377D06C3118479052D81D14782149A47F11BA25B8D22DFA4E8CABF` | 4185 / 88 |
| created | `00052Q` | `by-memory/0x0057d9c0-0x0057e18f.NewSpellInventoryPaneHandlePointerOrMouseEvent.md` | `DF4DB9997A2342B57F5BB313C79EDE3F856A6288175D04E1BA03F2612EC06681` | 9558 / 232 |
| created | `00052R` | `by-memory/0x0057e1b0-0x0057e1d8.NewSpellInventoryPaneHandlePacketEvent.md` | `8DA5F908678DCAD7752DF3355B779D4CA72F079914854A5BAD2B5D59BD3B179A` | 3307 / 54 |
| created | `00052S` | `by-memory/0x0057e1e0-0x0057e2c1.NewSpellInventoryPaneOnTimer.md` | `B46FE58D4AB9126C285A58D4F3E06255E43DD1211CE0323E64C2AE1FB8A5D21D` | 3621 / 73 |
| created | `00052T` | `by-memory/0x0057e2d0-0x0057e56d.NewSpellInventoryPaneActivateSpellSlot.md` | `D44CF7605D1C77616CBBDB77697B9B7687F4BA7F17D4511CAAB844FCCFEFA887` | 5047 / 114 |
| created | `00052U` | `by-memory/0x0057e5a0-0x0057e615.NewSpellInventoryPaneSendSwapSpellPacket.md` | `7815A0FA9560073F52CDEFAD507F349804CC13B9D4D70B32B8A2C116F4ACD35B` | 3348 / 59 |
| created | `00052V` | `by-memory/0x0057e620-0x0057e689.NewSpellInventoryPaneSendDirectSpellPacket.md` | `EF24A296CC202D3E122EAC965F71C166EF0D0EAC82742D276E97A8AE22573CA5` | 3317 / 60 |
| created | `00052W` | `by-memory/0x0057e690-0x0057e6e7.NewSpellInventoryPaneGetButtonRect.md` | `E209FE27D7C4AFAB372ECA0BBFEE0E8566AD5D4E196C1CCBEAA470B44EF2840B` | 3095 / 56 |
| created | `00052X` | `by-memory/0x0057e6f0-0x0057e75a.NewSpellInventoryPaneBuildSpellRowRect.md` | `CB0CB24B3D3931973597AD69D1C0EC0FD9E94EBD69504D31DC026F558061ED96` | 3357 / 55 |
| created | `00052Y` | `by-memory/0x0057e760-0x0057e7f4.NewSpellInventoryPaneHitTestButton.md` | `46AA406432C12B68BF485BB3A951F55F87EB7AF727F563B3151DF11BE11C97EB` | 3321 / 61 |
| created | `00052Z` | `by-memory/0x0057e800-0x0057e8c8.NewSpellInventoryPaneHitTestSpellRow.md` | `0A6C7A0E0EBE258C3DF2377BAD54B987526DEFF365ECE411C166DBBD41F036AA` | 3344 / 59 |
| created | `000530` | `by-memory/0x0057e8d0-0x0057e955.NewSpellInventoryPaneResolveVisibleSpellSlot.md` | `7CFCF5D5E40032C358772F7D7E7E37685B05F9AD30641EE5E60C24A08EBF1C1D` | 3895 / 73 |
| created | `000531` | `by-memory/0x0057e960-0x0057e99a.NewSpellInventoryPaneBuildSpellRowOrigin.md` | `7C57B4F3D990D03BD0911E48B77FAD9BEFA1252F21E87EBFBBA158BCBE8D8DD4` | 3159 / 51 |
| created | `000532` | `by-memory/0x0057e9a0-0x0057e9c5.NewSpellInventoryPaneStopActiveRepeatTimer.md` | `A756B9472F982F95DADC463018E21EDD59B21649803DC08092D69E96905AEFC8` | 3069 / 53 |
| created | `000533` | `by-memory/0x0057e9d0-0x0057ea57.NewSpellInventoryPaneToggleExpandedMode.md` | `639976F9E29757D072A1D0F2DADF61AFEEEEF594DBC3CA51D08ED69C75DF40E9` | 3387 / 60 |
| modified | `0002RL` | `by-memory/0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors.md` | `F0CEAEF9D936BE25AB45EA74BF665568B271665382309B2E8C72C4BA8F377390` | 20114 / 207 |
| modified | `0001L9` | `by-memory/0x005af4f0-0x005af57b.SendTargetedActionPacket.md` | `88E2D06E30A9861AF139089221386C6D9DF963AE1C53572B6DB60D2D6B5707C9` | 12334 / 136 |
| modified | `00026J` | `by-memory/0x0062cfd8-0x0062d418.SpellInventoryMacroReadOnlyData.md` | `0D5177CE141D56AB65A3D67E2F819FD36B0BC15B1A5743E93FF14E60026770F9` | 25394 / 179 |
| modified | `00028J` | `by-memory/0x0067a740-0x0067a744.g_pBackPane.md` | `4000B84C43A5571593FB5CDB612653E3B52B8D2205BAC793D18E177EAF64199E` | 10843 / 94 |
| modified | `0004YC` | `by-memory/0x005a4f70-0x005a500f.RequestLocalPlayerStatus.md` | `5407D609DCFDEB9BC21A64AD0581E7860E806C8136E7DEF40C7827F9BEE2250D` | 8605 / 84 |
| modified | `0001PH` | `by-memory/0x0069b380-0x0069b381.g_activeDialogCount.md` | `0224181E48035F5CFBC3DB24B558B3E7E8F8AA49D64522869AA23BBF02300FDD` | 7264 / 88 |
| created | `000534` | `by-type/by-struct/NewSpellInventoryPaneLayout.md` | `4E3BD42EA1C9DA3B41E74FFCB04D227645CF4366005BB5AE3BED581D1BCCB00C` | 4759 / 66 |
| modified | `0001W1` | `by-type/by-struct/ScrollSpellInventoryPaneLayout.md` | `C6116CE7935DB31DC105BB1356125C8EDDD579CE244CCD68F5D53141FF516216` | 13900 / 114 |
| modified | `0001YS` | `by-type/by-vtable/ScrollSpellInventoryPaneVtables.md` | `320BA37993AD2E9A6E92F3394FFE3EAE63075021138132857187ACE3841C02D3` | 14514 / 123 |

- Validator-owned generated outputs, metadata, registry, and projected statistics refreshed only through the documented validator commands; B009 did not edit any generated, tracker, registry, or validator-state artifact directly. The exact command-side counts and physical CPP/H metrics are recorded in Validator Results.
- B009 did not edit any manual `-coverage-report.md`, tracker/audit/catalog, goal/notes, IDA database, MCP process, validator lifecycle state, or report lifecycle state. The accepted manual coverage text and report lifecycle remain supervisor-owned; the supervisor-owned IDA rows have the final dispositions recorded in both twins.
- This same report is the only report artifact modified. Report execution/archive truth remains authoritative only from its path plus validator-owned status/history metadata; B009 does not execute or move it.
- Historical report-only boundary: before the accepted callback, no ordinary/generated/coverage/IDA/lifecycle change was made. The callback changes above supersede only the former ordinary/generated no-change current-state wording.
- Historical Gate 2B report repair changed only this same report's attestation, nine literal prototype prestates/poststates, evidence summaries, recommendation/bookkeeping prose, and exact C037-C065 evidence twins; that dated no-ordinary-change statement remains historical only. The later explicit Gate 2A callback repair changed the 24 listed ordinary destinations, validator-owned generated outputs through commands 24616/24621, and this same report; during that B009 additive implementation repair, the canonical IDB was not queried, mutated, or saved.
- Subsequent supervisor-owned Gate 2B changed canonical `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` from prestate SHA256 `D6EF0A13A878558E0C79F225439D7C2778BB86C040093EF26EEE4034FA3849EF`, 143,208,000 bytes, to saved SHA256 `C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B`, 143,208,000 bytes, last-write UTC `2026-08-16T05:39:50.1775844Z`; byte-identical prestate backup is `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B009-UID0000LU-Gate2B-20260816-013557.i64`. The transaction used no type endpoint and passed fresh post-save attestation/readback.

## Implementation Tracking Checklist

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C0000LU-001 | 0000LU | Retain `NexusTK/ui/inventory/NewSpellInventoryPane.cpp` and canonical owner `FILE`. | very-strong | Target route, class/core ownership, neighboring modules. | `by-file/NewSpellInventoryPane.md` Status/File Role | incorporate | implemented |
| [x] | C0000LU-002 | 0000LU | Retain UID00009A as direct class emitter and source route through UID0000LU. | very-strong | Current metadata and vtable/class evidence. | `by-class/NewSpellInventoryPane.md` ownership | incorporate | implemented |
| [x] | C0000LU-003 | 0000LU | Convert UID0002RJ to non-emitting exact split/index over children. | very-strong | Mixed 22-function/raw/foreign/table span. | UID0002RJ status/inventory | incorporate | implemented |
| [x] | C0000LU-004 | 0000LU | Create exact `0x148` NewSpell layout support; reject stale `0x100/+0xfc`. | original-proof | `0x4b84b6` allocation and constructor writes. | new by-type layout; class H | reject-stale | implemented |
| [x] | C0000LU-005 | 0000LU | Keep ScrollSpellInventoryPane as standalone private companion and repair header route. | strong | Sole ctor caller plus complete independent class/core/vtables. | UID0000NJ/UID0000CN | incorporate | implemented |
| [x] | C0000LU-006 | 0000LU | Preserve 35-dword NewSpell vtable cluster and successor boundary as compiler data. | original-proof | live reads `[0x62d064,0x62d0f0)`. | macro `.rdata`; class evidence | already-present | verified |
| [x] | C0000LU-007 | 0000LU | Resolve every target dependency through exact owner headers; make SpellInputPanes base-complete and give SpellInputPanes, TargetSelectionInputPanes, MapPane, LivingObjectPane, BackPane, and UserPane one self-contained C++03 guard each, with direct/indirect UserPane inclusion duplicate-safe. | very-strong | dated command-24621 physical declaration/include/guard audit and live callees. | target/class/core dependencies and named support formal H docs | incorporate | implemented |
| [x] | C0000LU-008 | 0000LU | Exclude foreign `ItemWhoInputPaneState::SetInputModeFlag` from this source. | original-proof | 17 external callers, existing owner/type/comment. | target/core/UID0001IJ | already-present | verified |
| [x] | C0000LU-009 | 0000LU | Scalar wrapper, adjustors, EH records, and switch tables are compiler-covered/no handwritten source. | very-strong | vtable routes, endpoints, table targets. | UID0002RL/macro/core | already-present | verified |
| [x] | C0000LU-010 | 0000LU | Preserve every exact pre/internal/post padding boundary, including literal one-byte `[0x0057e18f,0x0057e190)` before switch table `[0x0057e190,0x0057e1b0)`. | original-proof | byte audit, adjacent item heads, and 27-row alignment reconciliation. | target/class/core/broad/pointer/packet/SpellInventory inventories | incorporate | implemented |
| [x] | C0000LU-011 | 0000LU | Emit constructor `[0x57cf70,0x57d03f)` at position 10. | very-strong | allocator, vtables, field writes, child ctor. | new constructor child | incorporate | implemented |
| [x] | C0000LU-012 | 0000LU | Emit ordinary destructor raw body `[0x57d040,0x57d075)` at position 20. | strong | complete child-delete/base-dtor body and boundaries. | new destructor child | incorporate | implemented |
| [x] | C0000LU-013 | 0000LU | Emit OnActivate `[0x57d080,0x57d097)` at position 30. | very-strong | vtable and body. | new OnActivate child | incorporate | implemented |
| [x] | C0000LU-014 | 0000LU | Classify `nullsub_54 [0x57d0b0,0x57d0b1)` as an ownerless disconnected dead-code artifact with no source child or CPP/H. | original-proof | one-byte `ret`, zero directional xrefs, zero pointer hits, absent from vtable. | UID0002RJ no-code inventory | reject-invalid | implemented |
| [x] | C0000LU-015 | 0000LU | Emit UpdateRenderRegion `[0x57d0c0,0x57d148)` at position 40. | very-strong | vtable, bounds constants, child/base calls. | new child | incorporate | implemented |
| [x] | C0000LU-016 | 0000LU | Emit SetBounds `[0x57d150,0x57d1f5)` at position 50. | very-strong | vtable, fixed mode bounds. | new child | incorporate | implemented |
| [x] | C0000LU-017 | 0000LU | Emit RebuildSpellList `[0x57d200,0x57d360)` at position 60. | very-strong | complete loop/limits/scroll sync. | new child | incorporate | implemented |
| [x] | C0000LU-018 | 0000LU | Emit OnScrollPositionChanged `[0x57d360,0x57d398)` at position 70. | original-proof | accepted name/type/comment and three callers. | new child | incorporate | implemented |
| [x] | C0000LU-019 | 0000LU | Emit AddToLayer `[0x57d3a0,0x57d406)` at position 80. | very-strong | vtable and parent/child order. | new child | incorporate | implemented |
| [x] | C0000LU-020 | 0000LU | Emit RemoveFromLayer `[0x57d410,0x57d426)` at position 90. | very-strong | vtable and child/base order. | new child | incorporate | implemented |
| [x] | C0000LU-021 | 0000LU | Emit OnPaint `[0x57d430,0x57d8c4)` at position 100. | very-strong | vtable, resources, row loop, render calls. | new child | incorporate | implemented |
| [x] | C0000LU-022 | 0000LU | Emit HandleKeyOrTextEvent `[0x57d8d0,0x57d9b1)` at position 110. | very-strong | event vtable and local calls. | new child | incorporate | implemented |
| [x] | C0000LU-023 | 0000LU | Emit HandlePointerOrMouseEvent `[0x57d9c0,0x57e18f)` at position 120. | very-strong | event vtable, gesture/timer/packet flow. | new child | incorporate | implemented |
| [x] | C0000LU-024 | 0000LU | Emit HandlePacketEvent `[0x57e1b0,0x57e1d8)` at position 130. | very-strong | event vtable and packet cases 23/24. | new child | incorporate | implemented |
| [x] | C0000LU-025 | 0000LU | Emit OnTimer `[0x57e1e0,0x57e2c1)` at position 140. | very-strong | timer vtable and IDs 1/2. | new child | incorporate | implemented |
| [x] | C0000LU-026 | 0000LU | Emit ActivateSpellSlot `[0x57e2d0,0x57e56d)` at position 150. | very-strong | nine-way switch and input-pane fanout. | new child | incorporate | implemented |
| [x] | C0000LU-027 | 0000LU | Emit raw SendSwapSpellPacket `[0x57e5a0,0x57e615)` at position 160. | strong | packet opcode `0x30`, subcode 1, length 4. | new child | incorporate | implemented |
| [x] | C0000LU-028 | 0000LU | Emit SendDirectSpellPacket `[0x57e620,0x57e689)` at position 170. | very-strong | caller, opcode `0x0f`, length 2. | new child | incorporate | implemented |
| [x] | C0000LU-029 | 0000LU | Emit GetButtonRect `[0x57e690,0x57e6e7)` at position 180. | very-strong | caller and exact rectangle. | new child | incorporate | implemented |
| [x] | C0000LU-030 | 0000LU | Emit raw BuildSpellRowRect `[0x57e6f0,0x57e75a)` at position 190. | strong | coherent bounds helper and limits. | new child | incorporate | implemented |
| [x] | C0000LU-031 | 0000LU | Emit raw HitTestButton `[0x57e760,0x57e7f4)` at position 200. | strong | coherent part loop and GetButtonRect use. | new child | incorporate | implemented |
| [x] | C0000LU-032 | 0000LU | Emit HitTestSpellRow `[0x57e800,0x57e8c8)` at position 210. | very-strong | six calls and row rectangles. | new child | incorporate | implemented |
| [x] | C0000LU-033 | 0000LU | Emit ResolveVisibleSpellSlot `[0x57e8d0,0x57e955)` at position 220. | very-strong | six calls and learned/expanded mapping. | new child | incorporate | implemented |
| [x] | C0000LU-034 | 0000LU | Emit raw BuildSpellRowOrigin `[0x57e960,0x57e99a)` at position 230. | strong | coherent Point helper and row stride. | new child | incorporate | implemented |
| [x] | C0000LU-035 | 0000LU | Emit StopActiveRepeatTimer `[0x57e9a0,0x57e9c5)` at position 240. | very-strong | two calls and timer cancel. | new child | incorporate | implemented |
| [x] | C0000LU-036 | 0000LU | Emit ToggleExpandedMode `[0x57e9d0,0x57ea57)` at position 250. | very-strong | two calls and relayout/rebuild flow. | new child | incorporate | implemented |
| [x] | C0000LU-037 | 0000LU | Supervisor applied and verified I01 constructor pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I01 | incorporate | APPLIED_VERIFIED |
| [x] | C0000LU-038 | 0000LU | Supervisor applied and verified I02 OnActivate pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I02 | incorporate | APPLIED_VERIFIED |
| [x] | C0000LU-039 | 0000LU | Supervisor applied and verified I03 UpdateRenderRegion pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I03 | incorporate | APPLIED_VERIFIED |
| [x] | C0000LU-040 | 0000LU | Supervisor applied and verified I04 SetBounds pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I04 | incorporate | APPLIED_VERIFIED |
| [x] | C0000LU-041 | 0000LU | Supervisor applied and verified I05 RebuildSpellList pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I05 | incorporate | APPLIED_VERIFIED |
| [x] | C0000LU-042 | 0000LU | Supervisor verified I06 OnScrollPositionChanged already present and exact; name, prototype, regular function comment, and every protected channel remain exact after save. | original-proof | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no endpoint. | IDA Gate 2B I06 | already-present | ALREADY_PRESENT_VERIFIED |
| [x] | C0000LU-043 | 0000LU | Supervisor applied and verified I07 AddToLayer pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I07 | incorporate | APPLIED_VERIFIED |
| [x] | C0000LU-044 | 0000LU | Supervisor applied and verified I08 RemoveFromLayer pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I08 | incorporate | APPLIED_VERIFIED |
| [x] | C0000LU-045 | 0000LU | Supervisor applied and verified I09 OnPaint pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I09 | incorporate | APPLIED_VERIFIED |
| [x] | C0000LU-046 | 0000LU | Supervisor applied and verified I10 key/text input pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I10 | incorporate | APPLIED_VERIFIED |
| [x] | C0000LU-047 | 0000LU | Supervisor applied and verified I11 pointer/mouse input pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I11 | incorporate | APPLIED_VERIFIED |
| [x] | C0000LU-048 | 0000LU | Supervisor applied and verified I12 packet events pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I12 | incorporate | APPLIED_VERIFIED |
| [x] | C0000LU-049 | 0000LU | Supervisor applied and verified I13 timer events pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I13 | incorporate | APPLIED_VERIFIED |
| [x] | C0000LU-050 | 0000LU | Supervisor applied and verified I14 spell activation pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I14 | incorporate | APPLIED_VERIFIED |
| [x] | C0000LU-051 | 0000LU | Supervisor applied and verified I15 direct packet pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I15 | incorporate | APPLIED_VERIFIED |
| [x] | C0000LU-052 | 0000LU | Supervisor applied and verified I16 button bounds pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I16 | incorporate | APPLIED_VERIFIED |
| [x] | C0000LU-053 | 0000LU | Supervisor applied and verified I17 row hit-test pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I17 | incorporate | APPLIED_VERIFIED |
| [x] | C0000LU-054 | 0000LU | Supervisor applied and verified I18 visible-slot resolution pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I18 | incorporate | APPLIED_VERIFIED |
| [x] | C0000LU-055 | 0000LU | Supervisor applied and verified I19 repeat-timer stop pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I19 | incorporate | APPLIED_VERIFIED |
| [x] | C0000LU-056 | 0000LU | Supervisor applied and verified I20 expanded-mode toggle pure rename and exact regular function comment; prototype and every protected channel remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save bounded readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no type endpoint. | IDA Gate 2B I20 | incorporate | APPLIED_VERIFIED |
| [x] | C0000LU-057 | 0000LU | Supervisor applied and verified I21 exact regular raw-head destructor comment; raw physical item, function absence, and every protected channel remain exact after save. | strong | dated 2026-08-16 supervisor post-save raw-head readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B. | IDA Gate 2B I21 | incorporate | APPLIED_VERIFIED |
| [x] | C0000LU-058 | 0000LU | Supervisor applied and verified I22 exact regular raw-head swap helper comment; raw physical item, function absence, and every protected channel remain exact after save. | strong | dated 2026-08-16 supervisor post-save raw-head readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B. | IDA Gate 2B I22 | incorporate | APPLIED_VERIFIED |
| [x] | C0000LU-059 | 0000LU | Supervisor applied and verified I23 exact regular raw-head row-rect helper comment; raw physical item, function absence, and every protected channel remain exact after save. | strong | dated 2026-08-16 supervisor post-save raw-head readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B. | IDA Gate 2B I23 | incorporate | APPLIED_VERIFIED |
| [x] | C0000LU-060 | 0000LU | Supervisor applied and verified I24 exact regular raw-head button-hit helper comment; raw physical item, function absence, and every protected channel remain exact after save. | strong | dated 2026-08-16 supervisor post-save raw-head readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B. | IDA Gate 2B I24 | incorporate | APPLIED_VERIFIED |
| [x] | C0000LU-061 | 0000LU | Supervisor applied and verified I25 exact regular raw-head row-origin helper comment; raw physical item, function absence, and every protected channel remain exact after save. | strong | dated 2026-08-16 supervisor post-save raw-head readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B. | IDA Gate 2B I25 | incorporate | APPLIED_VERIFIED |
| [x] | C0000LU-062 | 0000LU | Supervisor verified P01 already present: the foreign ItemWho function remains exact in every protected channel after save. | original-proof | dated 2026-08-16 supervisor post-save bounded protection readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no endpoint. | IDA Gate 2B P01 | already-present | ALREADY_PRESENT_VERIFIED |
| [x] | C0000LU-063 | 0000LU | Supervisor verified P02 already present: disconnected nullsub physical identity, bytes, alignment, and zero-edge state remain exact without source ownership. | original-proof | dated 2026-08-16 supervisor post-save bounded protection readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no endpoint. | IDA Gate 2B P02 | already-present | ALREADY_PRESENT_VERIFIED |
| [x] | C0000LU-064 | 0000LU | Supervisor verified P03 already present: all 35 vtable dwords and successor boundary remain exact after save. | original-proof | dated 2026-08-16 supervisor post-save complete integer/hash readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no endpoint. | IDA Gate 2B P03 | already-present | ALREADY_PRESENT_VERIFIED |
| [x] | C0000LU-065 | 0000LU | Supervisor rejected P04 as invalid and verified no mutation: the protected stale shared UDT, types, and frames remain exact after save. | very-strong | dated 2026-08-16 supervisor post-save UDT/protection readback; saved canonical SHA256 C73777E5D7E945139355B6F88AE3400236AA4C305D9E3164010F24A2C16D667B; no UDT/type/frame endpoint. | IDA Gate 2B P04 | reject-invalid | REJECT_INVALID_VERIFIED/NO_MUTATION |
| [x] | C0000LU-066 | 0000LU | Apply exact dependency-closed NewSpell CPP preamble, 25 bodies, complete `0x148` H declaration, and compile-visible guarded support-header graph. | strong | complete inventory, live bodies, and dated command-24621 physical generated API/read-order audit. | UID00009A, 25 child formal CPP/H, and formal support H routes | incorporate | implemented |
| [x] | C0000LU-067 | 0000LU | Move Scroll declaration to H, keep CPP include/children, and add NewSpell friendship. | strong | separate-file callback access. | UID0000CN formal CPP/H | incorporate | implemented |
| [x] | C0000LU-068 | 0000LU | Keep by-file and aggregate/core formal blocks blank; source emits through class/children. | very-strong | routing rules and mixed parent. | UID0000LU/UID0002RJ formal channels | not-applicable | verified |
| [x] | C0000LU-069 | 0000LU | Incorporate complete inventory/behavior/evidence into target and class, including exact one-byte padding and guarded dependency/include topology. | very-strong | this report plus dated command-24621 physical readback. | target/class prose | incorporate | implemented |
| [x] | C0000LU-070 | 0000LU | Create 25 exact by-memory source children with specified metadata/order/source; create no nullsub child. | very-strong | exact boundaries and formal bodies. | new support docs | incorporate | implemented |
| [x] | C0000LU-071 | 0000LU | Update broad/core/scalar/macro plus UserPane, input-pane, HelpPanes, DialogPane, MapPane, LivingObjectPane, BackPane, pointer/packet boundaries, SpellInventoryPane, and shared-helper support without losing history; preserve all declarations while adding guards/includes/padding. | very-strong | reconciled support/dependency/header/padding inventory. | existing support docs | incorporate | implemented |
| [x] | C0000LU-072 | 0000LU | Raise target/class/core to `94/95`, `94/95`, and `94/95`; core becomes non-reconstructable split index. | strong | blocker removal and exact split. | metadata/manual rows | incorporate | implemented |
| [x] | C0000LU-073 | 0000LU | Score 25 source children `91-94/94-96` and layout `94/95`; assign no score/page to ownerless nullsub. | strong | target-specific evidence depth and blocker closure. | new metadata/manual rows | incorporate | implemented |
| [x] | C0000LU-074 | 0000LU | Apply only under supervisor authority the corrected complete literal Section 28 manual coverage payload: UID0000LU, UID00009A, UID0002RJ, all 25 child rows UID00052F-000533 immediately beneath UID0002RJ in source-position order, UID0002RL, UID000534, and the no-loss Scroll UID0000NJ/UID0000CN replacements. | very-strong | dated manual-row readback; formal-body reconciliation of UID00052H rebuild/invalidate, UID00052P translated key handling, UID00052Q event-type pointer switch, UID00052W fixed local button bounds, UID000531 local row origin, and exact Scroll declaration-in-H, CPP include/children, and NewSpell friendship. | four manual coverage files; corrected complete literal Section 28 payload | already-present | already-present-verified |
| [x] | C0000LU-075 | 0000LU | Treat command `000000024100` generated CPP only as dated empty-emitter evidence. | original-proof | physical dated readback/hash. | report/docs history | historicalize | historicalized |
| [x] | C0000LU-076 | 0000LU | Run scoped validators for every changed ordinary destination after callback and additive repair; record every correction receipt. | very-strong | commands 24591-24615 and 24618-24620; all exit 0/ok 1. | Validator Results | incorporate | validated |
| [x] | C0000LU-077 | 0000LU | Run the final owning-route waited refresh and physically reconcile target plus all affected support CPP/H, including UserPane, guards, include order, declarations, duplicates, and exact target source order. | very-strong | command 24621 physical readback. | Validator Results/generated readback | incorporate | verified |
| [x] | C0000LU-078 | 0000LU | Historicalize stale empty-emitter, raw-exclusion, old gate/layout/fold rationales and all current-tense pre-callback future-child/helper/score/blank-blocked statements in target, class, core, and aggregate. | very-strong | current contrary implementation and generated evidence. | Changes/evidence sections and four dated snapshots | reject-stale | historicalized |
| [x] | C0000LU-079 | 0000LU | Keep report prose lifecycle-neutral and leave lifecycle authority to supervisor/validator metadata. | very-strong | workflow. | report body/checklist | already-present | already-present-verified |
| [x] | C0000LU-080 | 0000LU | During the accepted report-only phase, no ordinary docs, generated files, coverage, validator state, IDA, or lifecycle state changed. | original-proof | pre-callback changed-file audit. | Changed Files | not-applicable | historical-verified |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000024687","destination_path":"executed-b-agent-research/B009/0000LU-NewSpellInventoryPane-file-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0000LU-NewSpellInventoryPane-file-source-quality.md","timestamp":"2026-08-16T02:07:21-04:00","uid":"0000LU"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
