# CheckBoxTextControlPane Vtable Data Empty-Emitter Source-Quality Report
** TARGET-REPORT-UID:0002OX **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **


Report date: 2026-08-17. This report supports preservation of the unsupported NexusTK client through behaviorally faithful source reconstruction. It began as report-only research and now records the accepted ordinary-document callback. Manual coverage, generated files, validator state, IDA, and lifecycle state remained read-only; generated output was physically reread but never edited. The current report path and validator-owned status/history metadata are authoritative for lifecycle state; this body makes no execute/archive assertion.

## Finalized Report / Current Recommendation

[UID:0002OX] is exact compiler-generated RTTI/vtable data, not a handwritten source array. The accepted ordinary callback changed the target from historical `RECONSTRUCTABLE:TRUE`, owner/emitter `000022`, and blank emitting channels to `RECONSTRUCTABLE:FALSE`, canonical semantic owner `000022`, no emitter, and blank formal CPP/H with a target-specific compiler-output rationale. Its score is now `94/96` from historical `86/92`. This removes the invalid target-level empty marker without inventing `.rdata` dwords.

The source cause is a complete `CheckBoxTextControlPane : public ControlPane` declaration in [UID:000022] formal H plus six source definitions routed through its exact children in [UID:0000NY] `NexusTK/ui/controls/SpecializedButtonPanes.cpp`: constructor, ordinary destructor, `OnPaint`, `SetChecked`, `GetChecked`, and terminal `HitTestPart(int,int)`. The scalar deleting destructor and the two adjusted deleting-wrapper thunks remain compiler output. The three physical vtable views are inherited primary, `EventHandler`, and `TimerHandler` facets at complete-object offsets `0`, `0xa0`, and `0xa4`; RTTI proves only one direct source base, `ControlPane`.

The prior `GetControlType()` interpretation of [UID:0002DZ] is invalid. The body at `0x004214c0` returns byte `22` in `AL`, executes `retn 8`, and is referenced by twelve terminal `ControlPane`-family primary-vtable slots. It is the linker-folded implementation of `unsigned char HitTestPart(int,int)`, including the CheckBox cell at `0x0062e9fc`. A zero-argument `int` method cannot explain either stack cleanup or return width.

## Supporting Research

- Primary target: `by-memory/0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData.md`, [UID:0002OX].
- Required owner/file/type support: [UID:000022] `by-class/CheckBoxTextControlPane.md`, [UID:0000NY] `by-file/SpecializedButtonPanes.md`, [UID:0001YW] `by-type/by-vtable/SpecializedButtonPaneVtables.md`, and [UID:0001W7] `by-type/by-struct/SpecializedButtonPaneLayouts.md`.
- Executable support: [UID:0001KJ], [UID:0002DZ], [UID:0003FE], [UID:0003FF], [UID:0003FG], [UID:0003FH], [UID:0003FI], and [UID:0003FJ].
- Containing/boundary support: [UID:00026U] user-list read-only-data aggregate, [UID:0003E7] PartySearch successor vtable data, [UID:0000VN] compiler-thunk ledger.
- Same-UID path-propagation support physically reconciled after the UID0002DZ rename: [UID:0000WT] early mixed helper island, [UID:0000WR] FittingRoom UI aggregate, [UID:0002E0] following tail-vector release boundary, and [UID:0000VN] ignored compiler-thunk ledger. UID0000WT's active `GetControlType`/old-score wording was historicalized and replaced with the exact HitTestPart ABI/xref truth; the other three received only validator-propagated path-link correction and scoped verification.
- Shared dependencies inspected without ownership transfer: [UID:000038]/[UID:0000IG] `ControlPane`, [UID:00004I]/[UID:0000J4] `EPFTileContext`, [UID:0000QU] `g_pEPFLib`, [UID:0000TN] surface callback table, and [UID:0000BU]/[UID:0000N2] `RectBounds`.
- Dated generated snapshot: validator command `000000025399`, refreshed `2026-08-17T10:27:15-04:00`; `SpecializedButtonPanes.cpp` contained the UID0002OX empty marker, a CheckBox class declaration incorrectly emitted in CPP, only two CheckBox definitions, and no CheckBox declaration in `SpecializedButtonPanes.h`.
- Dated tracker snapshot: `auto-generated/-ag-research-tracker.md` row 1781 recorded `86/92`, reconstructable true, and zero direct/additional reports.

## Target

- UID: `0002OX`.
- Exact half-open range: `[0x0062e998,0x0062ea3c)`.
- Length: `0xa4` / 164 bytes.
- SHA256: `8BD30D00387434A481D86CF072EEECC7A964DF2519C042067A16AB0A87E9B3C7`, independently computed from the live MCP byte read.
- Historical pre-callback metadata snapshot: `86/92`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:000022`, `EMITTER_UIDS:000022`, blank CPP/H.
- Implemented metadata: `94/96`, `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:000022`, empty `EMITTER_UIDS`, blank CPP/H.
- Exact successor: `[0x0062ea3c,0x0062ea40)` is the PartySearch primary COL pointer; `0x0062ea40` is `??_7PartySearchEditPane@@6B@`.

## Current Target State

The target is 41 consecutive four-byte data items: three COL-pointer cells and `25/11/2` vtable slots. Types are absent on all items. Only the three table bases are named: `??_7CheckBoxTextControlPane@@6B@` at `0x0062e99c`, `_0` at `0x0062ea04`, and `_1` at `0x0062ea34`. All target address comments are absent. No target cell has an inbound code xref. Only the three table heads have inbound data xrefs, six each; the other 38 cells have zero inbound xrefs to the cell address.

The historical target-level empty marker was a routing defect, not missing `.rdata` source. The accepted callback now treats UID0002OX as false/non-emitting compiler data and routes source through the owner and method pages. At the dated pre-callback generated readback, the owner declaration was in CPP rather than H; constructor, ordinary destructor, paint, getter, and the correct terminal virtual were absent; and the emitted terminal virtual had the wrong `GetControlType()` declaration/body. At the dated callback readback from validator command `000000025544`, those defects were absent: H contained one complete class declaration and CPP contained the six semantic definitions in accepted order, with no UID0002OX marker, no stale `GetControlType`, no duplicate, and no hand-authored vtable data. Latest generated authority is always established by dynamic reread during Gate 2A or later lifecycle work.

A prior pre-repair revision passed Gate 1 and Gate 2A for the accepted ordinary implementation; this exact repaired report revision still requires fresh Gate 1, and its dated Gate 2A receipts remain evidence rather than current authority. Dated supervisor Gate 2B then applied I01-I04 on rollback-copy session `supervisor_uid0002ox_gate2b_20260817`, but the old I05 untagged owner-type request returned exact error `Not a function type`; immediate readback retained the I04 name, old `Pane *` declaration, and sole frame row. The transaction hard-stopped and was not saved. Dated disposable follow-up on that unsaved rollback worker proved the corrected explicit-`class` requests for I05/I07/I09 and their complete poststates. A fresh canonical-session reread still showed `sub_59DF30` / `void __thiscall(Pane *this)`, `sub_59DF50` / `void __thiscall(int this)`, and `sub_59E0C0` / `char __thiscall(_BYTE *this)`; canonical disk identity remained SHA256 `18A166C6A506EC68B893E14EBC258F88A66E1F0D74065317532102B6AFED4965`, 143,209,361 bytes. Thus the report records parser research, not a saved Gate 2B result.

## Executive Recommendation

The accepted ordinary documentation plan is implemented. UID0002OX is false/non-emitting; UID000022 H is complete; the exact child CPP definitions are populated; UID0002DZ is corrected from historical `GetControlType()` to `HitTestPart(int,int)`; UID0001YW/UID0001W7/UID0001KJ/UID00026U carry the complete CheckBox maps; the compiler-only scalar wrapper and adjustors remain non-emitting; and the file-root dependencies are complete. Every changed ordinary page passed serial scoped validation. The dated callback generated readback proves one class declaration, six semantic definitions, correct order, no UID0002OX marker, no stale `GetControlType`, and no hand-authored vtable data. Gate 2B retry must use the now-proven explicit `class CheckBoxTextControlPane *` request spelling for I05/I07 and `const class CheckBoxTextControlPane *` for I09; IDA normalizes those semantic owner pointers to `struct` spelling in displayed prototypes.

## Supervisor Active Recheck

Supervisor Gate 1 should mechanically recheck this exact repaired post-callback artifact, all 33 headings, the 75-row ledger/checklist twin, 55 checked / 20 unchecked allocation, seven formal CPP blocks, one formal H block, zero executable-language fences, exactly one terminal readiness marker, and lifecycle-neutral prose. Gate 2A receipts remain preserved. Manual coverage remains supervisor-owned under C055-C058, and Gate 2B owns a fresh ordered I01-I12 transaction under C059-C074. B001 did not edit coverage, mutate or save canonical IDA, or alter disk authority; only the explicitly named rollback worker received unsaved disposable parser tests.

## Inference Research Guidance Check

The investigation did not stop at compiler-generated naming. It resolved the source declaration and ownership route, direct versus inherited-base layout, every table slot, constructor/destructor stores, ordinary versus scalar destructor semantics, raw helper liveness, field layout, terminal virtual ABI, file placement, formal CPP/H ownership, dependencies, and the target's non-emitting disposition. Remaining lexical uncertainty is limited to the literal historical source filename and original private member spellings; neither blocks a faithful source draft.

## Heuristic / Inference Reanalysis And Validation

| Question | Evidence | Resolution |
| --- | --- | --- |
| Handwritten vtable array or compiler output? | COLs, MSVC names, three inherited facets, constructor/destructor vptr stores, and no independent data consumer | Compiler output; never author raw dwords. |
| Multiple direct bases? | RTTI base list has CheckBox, ControlPane, Pane, GrafPort, LObject, EventHandler, TimerHandler; PMDs are 0, 0, 0, 0, 0, `0xa0`, `0xa4` | One direct source base, `ControlPane`; EventHandler/TimerHandler are inherited Pane facets. |
| Raw constructor dead? | Exact method-shaped body, `retn 0x0c`, base construction, fields, three vptr stores, and three independent inline copies in live callers | Retained source constructor whose calls were inlined; zero direct xrefs is a liveness cap, not no-code proof. |
| Raw setter dead? | Exact 16-byte `this+0x108 = arg` body between paint/getter; constructor, paint, getter, and consumers share the field | Retained source setter; no implicit invalidation. |
| Teardown helper source? | Vptr restoration followed by tail transfer to `Pane__Destructor`; scalar wrapper performs delete-flag logic separately | Ordinary empty destructor source body; compiler emits base teardown/vptr mechanics. |
| `GetControlType()`? | `mov al,0x16; retn 8`, terminal slot parity with `ControlPane::HitTestPart(int,int)`, twelve vtable xrefs | Rejected. Correct source identity is `unsigned char HitTestPart(int,int)`. |
| CheckBox-specific IDA rename at `0x004214c0`? | Twelve unrelated class vtables share the physical body | Rejected. Preserve shared name/type and add only a semantic regular address comment. |
| Source file | Existing owner graph, established generated route, sibling specialized controls, and reusable-control behavior | `NexusTK/ui/controls/SpecializedButtonPanes.cpp/.h` is highest probability; a standalone historical CheckBox file remains lower-ranked. |
| Explicit padding members? | `ControlPane` size `0x108`, bool at `+0x108`, naturally aligned `wchar_t[256]` at `+0x10a`, object allocation `0x30c` | Use natural compiler padding, not named padding fields. |

## Evidence Standards Used

- Live canonical IDA MCP only for executable facts; session was enumerated before calls.
- Exact half-open ranges, item heads/ends, names, types, comments, bytes, hashes, functions, frames, xrefs, and collisions.
- Independent source-shape corroboration from RTTI, vtable parity, callers, decompilation, raw disassembly, field offsets, and physically reread class/base formal declarations.
- Dated generated/tracker/coverage snapshots are evidence, not continuing lifecycle authority.
- Compiler ABI artifacts are separated from human source.
- Source snippets appear only in Section 22 formal CPP/H blocks.

## Evidence Checked

- MCP session `supervisor_uid0000n5_persistverify_20260817`, canonical IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- `server_health`: status `ok`, image base `0x00400000`, Hex-Rays ready, strings cache ready with 2068 entries; `auto_analysis_ready:false` was nonblocking because bounded IDB queries succeeded.
- Runtime attestation at `2026-08-17T15:22:57.046239+00:00`: listener and worker healthy, expected session/path matched, implementation manifests attested.
- Target raw bytes, all 41 item boundaries, comments, table names, complete xrefs to every target cell, table targets, RTTI records, source methods, raw methods, thunks, and successor items.
- Pre-callback ordinary target/support pages, dated manual coverage rows, dated generated `SpecializedButtonPanes.cpp/.h`, physically reread `ControlPane`/render dependency headers, and the dated tracker row.
- Desired IDA names `CheckBoxTextControlPane__Destructor`, `CheckBoxTextControlPane__OnPaint`, and `CheckBoxTextControlPane__GetChecked` were absent in the live IDB.
- Dated failed Gate 2B I05 response, immediate no-change readback, public parser implementation, local-type presence/absence, three successful explicit-`class` set-type responses, complete disposable poststates, no-save status, canonical-session original-state reread, and canonical disk hash/size.

## Claim And Incorporation Ledger

Ordinary claims C001-C054 are applied or physically verified, and mechanical report claim C075 is verified. Supervisor-owned manual coverage C055-C058 and IDA C059-C074 remain proposed and unchecked. Allocation is exactly 55 checked / 20 unchecked.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C001 | 0002OX | Exact target is `[0x0062e998,0x0062ea3c)`, 164 bytes, SHA256 `8BD30D00387434A481D86CF072EEECC7A964DF2519C042067A16AB0A87E9B3C7`. | Very high | Live MCP bytes/items plus independent SHA256 | UID0002OX range/evidence | incorporate | applied |
| C002 | 0002OX | Target contains exactly 41 four-byte data items: three COL pointers and `25/11/2` slots. | Very high | Complete item manifest | UID0002OX contents | incorporate | applied |
| C003 | 0002OX | RTTI proves one direct `ControlPane` base and inherited EventHandler/TimerHandler facets at `+0xa0/+0xa4`. | Very high | Three COLs, CHD, seven base descriptors/PMDs | UID0002OX inheritance | incorporate | applied |
| C004 | 0002OX | Primary table `[0x0062e99c,0x0062ea00)` has the exact 25-slot map in Section 14. | Very high | Live dwords/function lookups | UID0002OX primary map | incorporate | applied |
| C005 | 0002OX | Secondary table `[0x0062ea04,0x0062ea30)` has the exact 11-slot map in Section 14. | Very high | Live dwords/function lookups | UID0002OX secondary map | incorporate | applied |
| C006 | 0002OX | Tertiary table `[0x0062ea34,0x0062ea3c)` has the exact two-slot map in Section 14. | Very high | Live dwords/function lookups | UID0002OX tertiary map | incorporate | applied |
| C007 | 0002OX | Each table head has six exact data xrefs; all other target cells have zero inbound cell xrefs and no target cell has a code xref. | Very high | Complete xrefs-to query for all 41 cells | UID0002OX xrefs | incorporate | applied |
| C008 | 0002OX | `0x0062ea3c` is the PartySearch primary COL pointer and `0x0062ea40` its primary vtable base. | Very high | Live item/name/dword boundary | UID0002OX boundary | incorporate | applied |
| C009 | 0002OX | Change target to `94/96`, false/non-emitting, semantic owner 000022, empty emitter list, and blank formal CPP/H with compiler-output rationale. | Very high | Source-cause and ABI evidence | UID0002OX metadata/formals | incorporate | applied |
| C010 | 000022 | Exact class layout is `ControlPane` size `0x108`, `bool m_checked` at `+0x108`, natural pad at `+0x109`, `wchar_t m_label[256]` at `+0x10a`, total `0x30c`. | Very high | Constructor/paint/getter/allocation/RTTI | UID000022 layout | incorporate | applied |
| C011 | 0000NY | Canonical route remains `NexusTK/ui/controls/SpecializedButtonPanes.cpp/.h`; standalone CheckBox file remains lower-ranked historical alternative. | High | Existing owner graph and sibling route | UID0000NY placement | incorporate | applied |
| C012 | 0003FE | Raw constructor is retained source with signature `(bool,const wchar_t *,const RectBounds *)`, base type 8, checked store, bounded label copy, and exact vptr stores. | Very high | Exact 87 bytes and three live inline copies | UID0003FE behavior | incorporate | applied |
| C013 | 0003FF | `[0x0059df30,0x0059df4f)` is the ordinary empty destructor source route; vptr restoration/base call are compiler mechanics. | Very high | Decompile, stores, scalar-wrapper comparison | UID0003FF behavior | incorporate | applied |
| C014 | 0003FG | OnPaint loads `ON` frames 0/1, configures draw/text/font state, draws the label at x+28/x+29, and renders selected frame into `(4,3,24,23)` with `BU`. | Very high | Complete 348-byte decompile/disassembly | UID0003FG behavior | incorporate | applied |
| C015 | 0003FH | SetChecked performs only `m_checked = checked`; preserve exact existing formal CPP and no-invalidation evidence. | Very high | Exact 16-byte raw body | UID0003FH no-loss update | incorporate | applied |
| C016 | 0003FI | GetChecked is `bool GetChecked() const` and returns only `m_checked`. | Very high | Exact seven-byte modeled body | UID0003FI behavior/formal CPP | incorporate | applied |
| C017 | 0003FJ | Scalar deleting destructor is compiler output generated from the ordinary virtual destructor and emits no handwritten source. | Very high | Delete flags, base teardown, vtable/thunk refs | UID0003FJ disposition | incorporate | applied |
| C018 | 0000VN | Thunks `[0x0059efeb,0x0059eff6)` and `[0x0059eff6,0x0059f001)` adjust `this` by `0xa0/0xa4` into the scalar wrapper and remain compiler-only. | Very high | Exact bytes, jumps, vtable xrefs | ignored thunk record | already-present | already-present |
| C019 | 0002DZ | Historical `GetControlType()` is invalid; source ABI is `unsigned char HitTestPart(int,int)` returning 22. | Very high | `AL` return, `retn 8`, base terminal slot parity | UID0002DZ identity/history | historicalize | applied |
| C020 | 0002DZ | Physical body has twelve exact primary-vtable xrefs and must be documented as linker-folded shared ControlPane-family code, not assigned a CheckBox-specific IDA name. | Very high | Complete live xref/table-base map | UID0002DZ shared evidence | incorporate | applied |
| C021 | 000022 | Replace CPP-hosted class declaration with the complete formal H declaration in Section 22. | Very high | Generated defect and layout closure | UID000022 formal H | incorporate | applied |
| C022 | 00005P | Extend the shared CPP root dependencies for wide copy, ImageLib, Surface callbacks, and `IsLegacyAssetMode`; preserve all Gender/Direction content. | High | Compile-closure audit | UID00005P formal CPP preamble | incorporate | applied |
| C023 | 0003FE | Populate exact constructor formal CPP from Section 22. | Very high | Constructor bytes/ABI | UID0003FE formal CPP | incorporate | applied |
| C024 | 0003FF | Populate exact empty destructor formal CPP from Section 22. | Very high | Ordinary/scalar destructor split | UID0003FF formal CPP | incorporate | applied |
| C025 | 0003FG | Populate complete OnPaint formal CPP from Section 22. | High | Complete behavior and dependency map | UID0003FG formal CPP | incorporate | applied |
| C026 | 0003FH | Preserve the existing exact SetChecked formal CPP. | Very high | Exact raw body | UID0003FH formal CPP | already-present | already-present |
| C027 | 0003FI | Populate exact GetChecked formal CPP from Section 22. | Very high | Exact modeled body | UID0003FI formal CPP | incorporate | applied |
| C028 | 0002DZ | Replace wrong formal CPP with exact HitTestPart formal CPP from Section 22. | Very high | ABI and slot parity | UID0002DZ formal CPP | incorporate | applied |
| C029 | 0000NY | Source order is class H then constructor, destructor, paint, setter, getter, HitTestPart; compiler vtable/scalar/thunks emit nowhere. | High | Address/source dependency order | UID0000NY child order | incorporate | applied |
| C030 | 0002OX | Target score changes `86/92 -> 94/96`. | High | Complete target closure | UID0002OX score | incorporate | applied |
| C031 | 000022 | Owner score changes `90/92 -> 95/96`. | High | Complete declaration/method/layout closure | UID000022 score | incorporate | applied |
| C032 | 0000NY | File score changes `92/94 -> 94/95`; filename uncertainty remains the confidence cap. | High | Complete CheckBox route | UID0000NY score | incorporate | applied |
| C033 | 0001YW | Keep `94/96` false/non-emitting but replace stale CheckBox `+0x68` claim with complete `25/11/2` map. | Very high | Live table endpoints/slots | UID0001YW CheckBox section | incorporate | applied |
| C034 | 0001KJ | Raise `88/89 -> 92/94` and complete the exact source/compiler child map without making the mixed span emit. | High | Exact child closure | UID0001KJ map/score | incorporate | applied |
| C035 | 0002DZ | Rename the same-UID page/title to CheckBoxTextControlPaneHitTestPart, raise `91/94 -> 94/96`, preserve owner/emitter 000022 and reconstructable true. | High | Shared-body/source projection evidence | UID0002DZ path/metadata | incorporate | applied |
| C036 | 00026U | Raise `88/92 -> 92/95` and replace stale reconstructable target wording with exact false/non-emitting child/source-cause detail. | High | Complete child audit | UID00026U map/score | incorporate | applied |
| C037 | 0003FE | Raise constructor `85/88 -> 93/95`; raw/no-xref status remains explicit. | High | Exact body plus three inlines | UID0003FE score | incorporate | applied |
| C038 | 0003FF | Raise ordinary destructor `86/90 -> 93/95`. | Very high | Complete destructor split | UID0003FF score | incorporate | applied |
| C039 | 0003FG | Raise OnPaint `87/91 -> 93/95`. | High | Complete body/dependencies | UID0003FG score | incorporate | applied |
| C040 | 0003FH | Raise setter `87/88 -> 92/94`; preserve no-xref cap. | High | Exact raw body/source route | UID0003FH score | incorporate | applied |
| C041 | 0003FI | Raise getter `86/88 -> 92/94`; preserve no-xref cap. | High | Exact body/source route | UID0003FI score | incorporate | applied |
| C042 | 0003FJ | Raise `87/91 -> 93/95`, change to false/non-emitting, preserve semantic owner 000022, blank formals. | Very high | Compiler scalar-wrapper proof | UID0003FJ metadata/score | incorporate | applied |
| C043 | 0001W7 | Raise `93/95 -> 95/97` and add exact CheckBox direct-base/field/size/facet layout. | Very high | RTTI, fields, allocation | UID0001W7 CheckBox layout | incorporate | applied |
| C044 | 0000QU | `g_pEPFLib` remains shared ImageLib ownership; CheckBox consumes but does not own it. | Very high | OnPaint reads and existing owner route | UID0000QU no-change | already-present | already-present |
| C045 | 0000TN | `g_pfnFillRect` remains shared Surface ownership with exact two-argument thiscall ABI. | Very high | Indirect call at `0x0059dfb0` and callback physical formal-H reread | UID0000TN no-change | already-present | already-present |
| C046 | 00004I | EPFTileContext remains a shared by-value dependency; CheckBox locals do not transfer ownership. | Very high | Two 0x28-byte locals and callback physical type reread | UID00004I no-change | already-present | already-present |
| C047 | 000038 | Preserve direct `ControlPane` inheritance and terminal `HitTestPart(int,int)` contract; no base edit is required. | Very high | RTTI and callback physical formal-H reread | UID000038 no-change | already-present | already-present |
| C048 | 0000BU | RectBounds remains the exact 16-byte bounds dependency and `InitRectBounds` owner. | Very high | OnPaint/constructor and callback physical H reread | UID0000BU no-change | already-present | already-present |
| C049 | 0000VN | Existing CheckBox adjustor-thunk ignored record is complete and needs no ordinary edit. | Very high | Callback physical record plus live MCP recheck | by-memory/-ignored.md no-change | already-present | already-present |
| C050 | 00026U | Keep the mixed parent false/non-emitting and ownerless; physical interleave does not transfer CheckBox source to UserList. | Very high | Exact child boundaries/owners | UID00026U ownership | incorporate | applied |
| C051 | 0003E7 | PartySearch successor remains unchanged; only its boundary is cited. | Very high | Live successor items plus callback physical page reread | UID0003E7 no-change | already-present | already-present |
| C052 | 0000NY | Dated callback generated readback proves one CheckBox H declaration, six semantic definitions, correct order, no UID0002OX marker, no stale GetControlType, and no raw vtable body. | Very high | Formal route and dated defect | Generated readback | incorporate | applied |
| C053 | 0002OX | Implementation callback ran serial scoped validators for every changed ordinary page and recorded exact dated receipts. | Very high | Project workflow | Validator plan | incorporate | applied |
| C054 | 0000NY | Implementation callback physically reread generated CPP/H after validator metadata reached command `000000025544`. | Very high | Generated authority rule | Generated verification | incorporate | applied |
| C055 | 0002OX | Supervisor replaces the exact target manual by-memory coverage row with the Section 28 payload. | High | Dated pre-callback row and complete closure | by-memory/-coverage-report.md | incorporate | proposed |
| C056 | 000022 | Supervisor replaces exact owner and file coverage rows with Section 28 payloads. | High | Dated pre-callback rows and source closure | by-class/by-file coverage | incorporate | proposed |
| C057 | 0001YW | Supervisor replaces exact vtable/layout coverage rows with Section 28 payloads. | High | Dated pre-callback incomplete CheckBox rows | by-type coverage | incorporate | proposed |
| C058 | 0001KJ | Supervisor replaces/inserts the exact executable-map, child, UID0002DZ, and aggregate coverage rows in Section 28. | High | Dated pre-callback stale/missing rows | by-memory coverage | incorporate | proposed |
| C059 | 0002DZ | I01 applies the exact shared-body regular address comment at `0x004214c0`. | Very high | Twelve-vtable ABI proof | Section 21 I01 | incorporate | proposed |
| C060 | 0003FE | I02 applies the exact raw-constructor regular address comment at `0x0059ded0`. | High | Exact raw body/inlines | Section 21 I02 | incorporate | proposed |
| C061 | 0003FH | I03 applies the exact raw-setter regular address comment at `0x0059e0b0`. | High | Exact raw body/field users | Section 21 I03 | incorporate | proposed |
| C062 | 0003FF | I04 pure-renames `sub_59DF30` to `CheckBoxTextControlPane__Destructor`. | Very high | Destructor behavior/collision absence | Section 21 I04 | incorporate | proposed |
| C063 | 0003FF | I05 uses parser-accepted `void __thiscall CheckBoxTextControlPane__Destructor(class CheckBoxTextControlPane *this)` and expects normalized `void __thiscall(struct CheckBoxTextControlPane *this)` while preserving the sole frame row, all comment channels, range/hash, and xrefs. | Very high | Public `set_type` success plus complete disposable poststate | Section 21 I05 | incorporate | proposed |
| C064 | 0003FG | I06 pure-renames `sub_59DF50` to `CheckBoxTextControlPane__OnPaint`. | Very high | Primary slot/body/collision absence | Section 21 I06 | incorporate | proposed |
| C065 | 0003FG | I07 uses parser-accepted `void __thiscall CheckBoxTextControlPane__OnPaint(class CheckBoxTextControlPane *this)` and expects normalized `void __thiscall(struct CheckBoxTextControlPane *this)` while preserving all seven frame rows, all comment channels, range/hash, and xrefs. | Very high | Public `set_type` success plus complete disposable poststate | Section 21 I07 | incorporate | proposed |
| C066 | 0003FI | I08 pure-renames `sub_59E0C0` to `CheckBoxTextControlPane__GetChecked`. | Very high | Getter body/collision absence | Section 21 I08 | incorporate | proposed |
| C067 | 0003FI | I09 uses parser-accepted `bool __thiscall CheckBoxTextControlPane__GetChecked(const class CheckBoxTextControlPane *this)` and expects normalized `bool __thiscall(const struct CheckBoxTextControlPane *this)` while preserving the sole frame row, all comment channels, range/hash, and xrefs. | Very high | Public `set_type` success plus complete disposable poststate | Section 21 I09 | incorporate | proposed |
| C068 | 0002OX | I10 applies the exact primary-COL regular address comment at `0x0062e998`. | Very high | Table/RTTI map | Section 21 I10 | incorporate | proposed |
| C069 | 0002OX | I11 applies the exact EventHandler-COL regular address comment at `0x0062ea00`. | Very high | Table/RTTI map | Section 21 I11 | incorporate | proposed |
| C070 | 0002OX | I12 applies the exact TimerHandler-COL regular address comment at `0x0062ea30`. | Very high | Table/RTTI map | Section 21 I12 | incorporate | proposed |
| C071 | 0003FJ | P01 protects scalar deleting destructor name/type/frame/comments/range/hash/xrefs as no-change. | Very high | Live complete prestate | Section 21 P01 | already-present | proposed |
| C072 | 0000VN | P02/P03 protect both adjustor thunks, including exact AR `Block`, as no-change. | Very high | Live complete prestates | Section 21 P02/P03 | already-present | proposed |
| C073 | 0002OX | P04 supplies literal manifest rows M01-M41 with each four-byte range, entity kind, name, type, dword/semantic target, four comment channels, complete inbound/outbound xrefs, permitted delta, and expected post-readback; only M01, M27, and M39 permit exact AR changes. | Very high | Literal 41-cell target manifest | Section 21 P04 | already-present | proposed |
| C074 | 0002OX | Gate 2B must execute I01-I12 in order; I05/I07/I09 use the explicit-`class` requests and normalized displays proven by dated rollback-copy tests; I10-I12 bind literal M01/M27/M39 states; any mismatch hard-stops without further mutation/save; final reread proves only three names, three declarations, and six AR comments changed. | Very high | Deterministic transaction contract plus public parser tests | Section 21 final readback | incorporate | proposed |
| C075 | 0002OX | Report has 33 exact headings, 75/75 twin parity, seven formal CPP blocks, one formal H block, zero executable-language fences, lifecycle-neutral post-callback prose, one terminal READY_FOR_SUPERVISOR_EXECUTE marker, and dated implementation/parser-test receipts. | Very high | Mechanical report audit | Report artifact | already-present | already-present |

## Positive Evidence Summary

- Exact 164-byte compiler-data range and hash are closed.
- All three COLs share the CheckBox type descriptor/hierarchy.
- The primary/secondary/tertiary slot counts and endpoints are exact.
- Eighteen store/reset xrefs bind constructors, ordinary teardown, PartySearch setup, UserList setup, and scalar deletion to all three views.
- Exact class allocation and field accesses close the `0x30c` layout.
- Raw constructor and setter have coherent source method bodies and independent inline/field corroboration.
- Ordinary destructor, scalar wrapper, and two adjustors are separated correctly.
- Paint behavior and dependencies are complete.
- Terminal virtual ABI is resolved as `HitTestPart(int,int)`.
- Existing owner/file routing provides a complete CPP/H path without raw table source.
- Public `set_type` syntax is closed: explicit `class CheckBoxTextControlPane *` requests succeed without a separate local-type declaration and normalize to equivalent `struct` owner pointers in IDA display.

## IDA MCP Facts

- Session: `supervisor_uid0000n5_persistverify_20260817`; canonical IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Target bytes: `44 1d 65 00 50 f0 59 00 10 4b 4f 00 c0 b6 41 00 20 8e 4b 00 80 d6 41 00 30 47 54 00 50 47 54 00 a0 47 54 00 00 48 54 00 20 4a 54 00 80 4b 54 00 d0 4b 54 00 70 4c 54 00 b0 4c 54 00 e0 4c 54 00 30 4d 54 00 70 4d 54 00 50 df 59 00 80 4b 49 00 b0 4b 49 00 d0 4b 49 00 00 4c 49 00 10 4c 49 00 30 4c 49 00 c0 14 42 00 a4 1d 65 00 eb ef 59 00 b0 4d 54 00 b0 d6 41 00 b0 d6 41 00 e0 4d 54 00 f0 4d 54 00 00 4e 54 00 f0 89 4a 00 10 4e 54 00 30 4e 54 00 70 4e 54 00 b8 1d 65 00 f6 ef 59 00 90 4e 54 00`.
- Primary COL `0x00651d44`: signature 0, offset 0, cdOffset 0, TypeDescriptor `0x00679b08`, CHD `0x00651d58`.
- Secondary COL `0x00651da4`: signature 0, offset `0xa0`, cdOffset 0, same type/CHD.
- Tertiary COL `0x00651db8`: signature 0, offset `0xa4`, cdOffset 0, same type/CHD.
- CHD: signature 0, attributes 1, seven bases via array `0x00651d68`.
- Type string: `.?AVCheckBoxTextControlPane@@`.
- Exact executable hashes: constructor `CA72EFD3F224DD91E9B9FCF303830CFD51D10A7ACDFC54678E216E49A740FEFF`; ordinary destructor `A0A578B55DAF30413CC1E57083CF91358553811D35B8B04EA5A378629D0C5B44`; paint `18C32BAD02E02C95BC5F68D91BDAD5473046A4B98FD6F94161F8F5AB4F7D747E`; setter `8F26D94DD5FBA8FDE27FA8C1A280CC83A6E93B2E5CB971150B567A287B677495`; getter `52F1855AE3D4D03E5FD70F6EBB3FEE20E96CD9F277FF988FFE395E4FCB5C5159`; thunks `6FA2AA41938D27F30B22F117243C446CD8607E13578C67FBD316936E555C0DE3` and `347A3B833AFD9F3A001F5B038F0E7FA247546CEE03DF2D1936D004C85065419C`; scalar wrapper `884AC7B77C3568598EDEEFFABB848B233E94F5046FFA7A4CC03375B179FD202F`; shared HitTest body `8DF7E6927E0D5D40AFDAE258140DCDE9E90C49665C9335100ED72236A97B6F94`.
- Dated parser-test session `supervisor_uid0002ox_gate2b_20260817` was runtime-attested against the exact rollback-copy path. Its explicit-`class` I05/I07/I09 requests each returned `kind:function, ok:true`; complete immediate readbacks produced the exact normalized declarations and unchanged frames/comments/ranges/hashes/xrefs specified in Section 21. No save was invoked. Canonical reread remained at all three original names/types; canonical disk was SHA256 `18A166C6A506EC68B893E14EBC258F88A66E1F0D74065317532102B6AFED4965`, 143,209,361 bytes.

## Function / Child Inventory

RTTI bases:

| Order | Base | PMD mdisp | pdisp | vdisp | Source disposition |
| ---: | --- | ---: | ---: | ---: | --- |
| 0 | CheckBoxTextControlPane | `0` | `-1` | `0` | complete object, six contained descendants |
| 1 | ControlPane | `0` | `-1` | `0` | sole direct source base |
| 2 | Pane | `0` | `-1` | `0` | inherited |
| 3 | GrafPort | `0` | `-1` | `0` | inherited |
| 4 | LObject | `0` | `-1` | `0` | inherited |
| 5 | EventHandler | `0xa0` | `-1` | `0` | inherited adjusted facet |
| 6 | TimerHandler | `0xa4` | `-1` | `0` | inherited adjusted facet |

Primary table `[0x0062e99c,0x0062ea00)`:

| Slot/cell | Target | Source role |
| --- | --- | --- |
| 0 / `0x0062e99c` | `0x0059f050` | compiler scalar deleting destructor |
| 1 / `0x0062e9a0` | `0x004f4b10` | inherited `LObject::GetRuntimeClass` |
| 2 / `0x0062e9a4` | `0x0041b6c0` | inherited `LObject::OnChangeMessage` |
| 3 / `0x0062e9a8` | `0x004b8e20` | inherited `Pane::UpdateRenderRegion` |
| 4 / `0x0062e9ac` | `0x0041d680` | inherited `Pane::DrawOnTarget` |
| 5 / `0x0062e9b0` | `0x00544730` | inherited `Pane::Show` |
| 6 / `0x0062e9b4` | `0x00544750` | inherited `Pane::Hide` |
| 7 / `0x0062e9b8` | `0x005447a0` | inherited `Pane::GetParentPane` |
| 8 / `0x0062e9bc` | `0x00544800` | inherited `Pane::InvalidateRect` |
| 9 / `0x0062e9c0` | `0x00544a20` | inherited `Pane::GetDescription` |
| 10 / `0x0062e9c4` | `0x00544b80` | inherited `Pane::GetScreenBounds` |
| 11 / `0x0062e9c8` | `0x00544bd0` | inherited `Pane::SetBounds` |
| 12 / `0x0062e9cc` | `0x00544c70` | inherited `Pane::AddToLayer` |
| 13 / `0x0062e9d0` | `0x00544cb0` | inherited `Pane::InsertInLayer` |
| 14 / `0x0062e9d4` | `0x00544ce0` | inherited `Pane::RemoveFromLayer` |
| 15 / `0x0062e9d8` | `0x00544d30` | inherited `Pane::SetPaneOrder` |
| 16 / `0x0062e9dc` | `0x00544d70` | inherited `Pane::UnregisterEventHandler` |
| 17 / `0x0062e9e0` | `0x0059df50` | `CheckBoxTextControlPane::OnPaint` |
| 18 / `0x0062e9e4` | `0x00494b80` | inherited `ControlPane::SetVisualState` |
| 19 / `0x0062e9e8` | `0x00494bb0` | inherited `ControlPane::Enable` |
| 20 / `0x0062e9ec` | `0x00494bd0` | inherited `ControlPane::Disable` |
| 21 / `0x0062e9f0` | `0x00494c00` | inherited `ControlPane::SetIgnoreHitTesting` |
| 22 / `0x0062e9f4` | `0x00494c10` | inherited `ControlPane::Deactivate` |
| 23 / `0x0062e9f8` | `0x00494c30` | inherited `ControlPane::Activate` |
| 24 / `0x0062e9fc` | `0x004214c0` | `CheckBoxTextControlPane::HitTestPart(int,int)`, folded shared constant 22 body |

Secondary EventHandler table `[0x0062ea04,0x0062ea30)`:

| Slot/cell | Target | Source role |
| --- | --- | --- |
| 0 / `0x0062ea04` | `0x0059efeb` | compiler `this -= 0xa0` deleting-wrapper adjustor |
| 1 / `0x0062ea08` | `0x00544db0` | inherited pointer/mouse default |
| 2 / `0x0062ea0c` | `0x0041d6b0` | inherited key/text false default |
| 3 / `0x0062ea10` | `0x0041d6b0` | inherited IME false default, same folded body |
| 4 / `0x0062ea14` | `0x00544de0` | inherited packet-event default |
| 5 / `0x0062ea18` | `0x00544df0` | inherited system/control-event default |
| 6 / `0x0062ea1c` | `0x00544e00` | inherited type-19 default |
| 7 / `0x0062ea20` | `0x004a89f0` | inherited `EventHandler::ForwardHandlerOrder` |
| 8 / `0x0062ea24` | `0x00544e10` | inherited local-event pair |
| 9 / `0x0062ea28` | `0x00544e30` | inherited screen-event pair |
| 10 / `0x0062ea2c` | `0x00544e70` | inherited acceptance predicate |

Tertiary TimerHandler table `[0x0062ea34,0x0062ea3c)`:

| Slot/cell | Target | Source role |
| --- | --- | --- |
| 0 / `0x0062ea34` | `0x0059eff6` | compiler `this -= 0xa4` deleting-wrapper adjustor |
| 1 / `0x0062ea38` | `0x00544e90` | inherited `Pane::OnTimer` default |

Executable/source children:

| UID | Range | Current status | Final disposition |
| --- | --- | --- | --- |
| 0003FE | `[0x0059ded0,0x0059df27)` | raw code, no function/xrefs | retained constructor CPP |
| 0003FF | `[0x0059df30,0x0059df4f)` | `sub_59DF30` | ordinary empty destructor CPP |
| 0003FG | `[0x0059df50,0x0059e0ac)` | `sub_59DF50` | complete OnPaint CPP |
| 0003FH | `[0x0059e0b0,0x0059e0c0)` | raw code, existing CPP | retain SetChecked CPP |
| 0003FI | `[0x0059e0c0,0x0059e0c7)` | `sub_59E0C0` | GetChecked CPP |
| 0000VN | `[0x0059efeb,0x0059f001)` | two adjustor thunks | compiler-only, no source |
| 0003FJ | `[0x0059f050,0x0059f0a5)` | scalar deleting wrapper | false/non-emitting compiler output |
| 0002DZ | `[0x004214c0,0x004214c5)` | shared `char __stdcall(int,int)` | semantic CheckBox HitTestPart CPP plus shared-physical evidence |

## Direct Xref / Caller Inventory

Vtable head store/reset xrefs are complete:

| Table | Exact six inbound data xrefs |
| --- | --- |
| primary `0x0062e99c` | `0x0059c789`, `0x0059c81f`, `0x0059defc`, `0x0059df30`, `0x0059e23f`, `0x0059f056` |
| secondary `0x0062ea04` | `0x0059c795`, `0x0059c82b`, `0x0059df02`, `0x0059df36`, `0x0059e24b`, `0x0059f05c` |
| tertiary `0x0062ea34` | `0x0059c79f`, `0x0059c835`, `0x0059df0c`, `0x0059df40`, `0x0059e255`, `0x0059f066` |

`UserListDialogPane_UserListDialogPane` contains two inlined allocations of size `0x30c`, base construction with type 8, checked-value reads, label copies, and all three vptr stores. `PartySearchEditPane_PartySearchEditPane` contains a third equivalent inline construction for `L"Put me on the hunters list"`. The standalone raw constructor has zero inbound xrefs but exactly matches those inlines. Ordinary destructor and getter also have zero inbound xrefs; paint has the sole data xref `0x0062e9e0`; scalar wrapper has code refs from both adjustors and the primary slot data ref.

The shared HitTest body has twelve exact data xrefs at `0x0060dd70`, `0x00610b34`, `0x00610d30`, `0x0061d520`, `0x0061d5c4`, `0x0061d668`, `0x0061dddc`, `0x0061de80`, `0x0062d244`, `0x0062d2e8`, `0x0062d38c`, and `0x0062e9fc`. Their primary table bases are FittingRoomListPane, RankingEventListPane, RankingUserListPane, SelectBoxControlPane, UserShapeSelectControlPane, NewUserShapeSelectControlPane, UserHairSelectControlPane, UserFaceSelectControlPane, SpellMacroEditControlPane, NewMacroEditControlPane, IntegrateMacroEditControlPane, and CheckBoxTextControlPane.

## Documentation Evidence And IDA Status

Historical pre-callback ordinary documentation preserved much of the range, xref, and class evidence but carried three source-quality defects: UID0002OX was reconstructable/emitting despite compiler-only data; UID000022 placed its class declaration in CPP and left H blank; UID0002DZ declared a zero-argument `int GetControlType()` contrary to the physical ABI. The accepted ordinary callback resolved all three at report-level detail. The dated callback generated snapshot from command `000000025544` mirrored the corrected formal route; latest generated authority remains a dynamic Gate 2A/lifecycle reread rather than this dated receipt.

Canonical IDA and disk authority remained read-only. Names/types/comments in Section 21 remain recommendations for a fresh supervisor Gate 2B transaction. The explicitly named rollback-copy worker received only unsaved disposable parser tests required by this repair; no `idb_save` call occurred, and the canonical session reread retained all original names/types.

## Ranked Ownership Analysis

1. [UID:000022] `CheckBoxTextControlPane` is the semantic owner. All class-specific fields, methods, RTTI, and vptr stores converge here.
2. [UID:0000NY] `SpecializedButtonPanes` is the best current source-file route. It already owns two related reusable control classes and the project emitter graph.
3. [UID:0000OZ] `UserListDialogPane` is a consumer and inline-construction site, not the reusable class owner.
4. [UID:0000A7] `PartySearchEditPane` is another consumer and does not own the generic checkbox class.
5. [UID:00026U] and [UID:0001KJ] are mixed physical aggregates; neither emits.
6. [UID:0002OX] is compiler data with semantic owner 000022 but no emitter.

## Source Placement

Use `NexusTK/ui/controls/SpecializedButtonPanes.h` for the complete class declaration and `SpecializedButtonPanes.cpp` for exact child definitions. Preserve the current Gender and Direction source. Place CheckBox after Direction at class position 40; order child definitions constructor 10, destructor 20, paint 30, setter 40, getter 50, and HitTestPart 60. A literal original `CheckBoxTextControlPane.cpp` remains plausible but has less evidence than the established project bucket and does not justify a duplicate route.

## Range / Split / Padding / Reclassification Analysis

- UID0002OX range and filename remain exact; no split or extension is needed.
- `[0x0062e998,0x0062e99c)` primary COL pointer; `[0x0062e99c,0x0062ea00)` 25 primary slots.
- `[0x0062ea00,0x0062ea04)` secondary COL pointer; `[0x0062ea04,0x0062ea30)` 11 secondary slots.
- `[0x0062ea30,0x0062ea34)` tertiary COL pointer; `[0x0062ea34,0x0062ea3c)` two tertiary slots.
- No target padding exists; all 164 bytes are typed-by-role data cells even though IDA item types are absent.
- The end remains before PartySearch COL cell `0x0062ea3c`.
- Reclassification is metadata/source disposition only: reconstructable emitting data becomes false/non-emitting compiler evidence.
- UID0002DZ requires a same-UID semantic filename/title correction, not a byte-range change.

## Negative Evidence Summary

- No ordinary source references raw vtable/COL arrays; do not emit them.
- No evidence supports three direct bases.
- No direct xrefs to raw constructor/setter do not prove padding or dead data.
- Setter contains no invalidation or paint call.
- Getter contains no argument or side effect.
- Ordinary destructor contains no class-specific resource cleanup.
- Scalar wrapper and adjustors are not source methods.
- `0x004214c0` is not a zero-argument method and must not receive a CheckBox-specific IDA name.
- Physical interleave with UserList/PartySearch does not transfer ownership.
- Original literal source filename is not proven; the selected project route is evidence-ranked, not asserted as debug-symbol fact.

## IDA Rename / Type / Comment Recommendations

All actions are classified `apply`, supervisor-owned, and ordered I01 through I12. Every action requires exact literal preflight, destination collision check where applicable, successful mutation response, and immediate literal poststate readback. If any prestate, collision result, response, or poststate differs, hard-stop: perform no further mutation and do not save. Historical database values preserve the request evidence that produced this report; every retry must freshly enumerate and runtime-attest its actual rollback session, then substitute that exact returned session ID in each request without changing any other field.

Dated failure/parser receipt: on rollback-copy session `supervisor_uid0002ox_gate2b_20260817` backed by `NexusTK.exe.uid0002OX-prechange-20260817_192037365.i64`, I01-I04 passed and the old literal I05 request `edits:{addr:"0x0059df30",kind:"function",signature:"void __thiscall CheckBoxTextControlPane__Destructor(CheckBoxTextControlPane *this)"}` returned `[{"edit":{"addr":"0x0059df30","kind":"function","signature":"void __thiscall CheckBoxTextControlPane__Destructor(CheckBoxTextControlPane *this)"},"error":"Not a function type: void __thiscall CheckBoxTextControlPane__Destructor(CheckBoxTextControlPane *this)"}]`; immediate name/type/frame readback was unchanged and the transaction stopped without save. Read-only inspection of the loaded endpoint implementation showed function parsing through `PT_SIL | PT_TYP`; live `type_inspect` proved `CheckBoxTextControlPane` absent while `Pane` and `ControlPane` existed. Untagged and abstract `struct` trials failed, while full declarations using explicit `class CheckBoxTextControlPane *` succeeded. IDA normalized `class` to `struct` in displayed prototypes, and a final `type_inspect` still reported no standalone `CheckBoxTextControlPane` local type, so no separate `declare_type` action is introduced.

Channel legend: `AR` is the regular address-comment channel written by `set_address_comments`; `AP` is the repeatable address-comment channel written by `set_address_repeatable_comments`; `FR` is the function regular-comment channel; `FP` is the function repeatable-comment channel. For a non-function item, FR/FP absence is recorded as not applicable because no function-comment channel exists at that item.

**I01 - shared HitTest body AR regular address comment.** Classification: apply. Prestate: item/function `[0x004214c0,0x004214c5)`, name `sub_4214C0`, declaration `char __stdcall(int, int)`, frame exactly `__return_address@0x0/0x4/_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; body `b0 16 c2 08 00`, SHA256 `8DF7E6927E0D5D40AFDAE258140DCDE9E90C49665C9335100ED72236A97B6F94`; twelve inbound data xrefs exactly as Section 15 and zero code xrefs. Request: endpoint `set_address_comments`, `database:"supervisor_uid0000n5_persistverify_20260817"`, `items:{addr:"0x004214c0",comment:"Shared linker-folded ControlPane-family HitTestPart(int,int) body returning 22; twelve primary vtables reference it, including CheckBoxTextControlPane slot 0x0062e9fc. Preserve a non-class-specific function name."}`. Expected poststate: only AR becomes that exact text; AP remains absent; FR remains absent; FP remains absent; name, declaration, frame, range, bytes/hash, and xrefs remain exact. Immediate readback: inspect item/function, frame, all four comment channels, bytes/hash, and xrefs.

**I02 - raw constructor AR regular address comment.** Classification: apply. Prestate: raw code range `[0x0059ded0,0x0059df27)`, no function, first item `[0x0059ded0,0x0059ded1)`, name absent, type absent, frame absent; AR absent; AP absent; FR absent/not applicable because no function exists; FP absent/not applicable because no function exists; 87-byte SHA256 `CA72EFD3F224DD91E9B9FCF303830CFD51D10A7ACDFC54678E216E49A740FEFF`; zero inbound xrefs; exact successor padding `[0x0059df27,0x0059df30)`. Request: endpoint `set_address_comments`, `database:"supervisor_uid0000n5_persistverify_20260817"`, `items:{addr:"0x0059ded0",comment:"Raw retained CheckBoxTextControlPane constructor: ControlPane(8,bounds), m_checked initialization, wcscpy_s label copy with capacity 256, and primary/EventHandler/TimerHandler vptr stores; equivalent setup is inlined at three live callers."}`. Expected poststate: only AR becomes that exact text; AP remains absent; FR remains absent/not applicable because no function is created; FP remains absent/not applicable because no function is created; no function is created; name, type, frame absence, full bytes/hash, range, padding, and xrefs remain exact. Immediate readback covers item/function absence, all four comment-channel dispositions, full bytes/hash, range, padding, and xrefs.

**I03 - raw setter AR regular address comment.** Classification: apply. Prestate: raw code range `[0x0059e0b0,0x0059e0c0)`, no function, first item `[0x0059e0b0,0x0059e0b1)`, name absent, type absent, frame absent; AR absent; AP absent; FR absent/not applicable because no function exists; FP absent/not applicable because no function exists; bytes `55 8b ec 8a 45 08 88 81 08 01 00 00 5d c2 04 00`, SHA256 `8F26D94DD5FBA8FDE27FA8C1A280CC83A6E93B2E5CB971150B567A287B677495`; zero inbound xrefs; predecessor padding `[0x0059e0ac,0x0059e0b0)` and successor getter at `0x0059e0c0`. Request: endpoint `set_address_comments`, `database:"supervisor_uid0000n5_persistverify_20260817"`, `items:{addr:"0x0059e0b0",comment:"Raw retained CheckBoxTextControlPane::SetChecked(bool): stores the byte argument to m_checked at +0x108 and returns; no invalidation side effect."}`. Expected poststate: only AR becomes that exact text; AP remains absent; FR remains absent/not applicable because no function is created; FP remains absent/not applicable because no function is created; no function is created; name, type, frame absence, bytes/hash, range, predecessor padding, successor, and xrefs remain exact. Immediate readback covers item/function absence, all four comment-channel dispositions, bytes/hash, range, boundaries, and xrefs.

**I04 - ordinary destructor pure rename.** Classification: apply. Prestate: function `[0x0059df30,0x0059df4f)`, name `sub_59DF30`, declaration `void __thiscall(Pane *this)`, frame exactly `__return_address@0x0/0x4/_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; SHA256 `A0A578B55DAF30413CC1E57083CF91358553811D35B8B04EA5A378629D0C5B44`; zero inbound xrefs; desired name absent. Request: endpoint `rename`, `database:"supervisor_uid0000n5_persistverify_20260817"`, `batch:{func:{addr:"0x0059df30",name:"CheckBoxTextControlPane__Destructor"},pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`. Expected poststate: only name changes to `CheckBoxTextControlPane__Destructor`; declaration/frame/comments/range/hash/xrefs remain exact. Immediate readback is complete.

**I05 - ordinary destructor type.** Classification: apply. Literal prestate produced by I04: function `[0x0059df30,0x0059df4f)`, name `CheckBoxTextControlPane__Destructor`, declaration `void __thiscall(Pane *this)`, frame exactly `__return_address@0x0/0x4/_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; SHA256 `A0A578B55DAF30413CC1E57083CF91358553811D35B8B04EA5A378629D0C5B44`; zero inbound xrefs; entry-query outbound code xref `0x0059df30 -> 0x0059df36` and outbound data xref `0x0059df30 -> 0x0062e99c`. Corrected request: endpoint `set_type`, `database:"<fresh runtime-attested Gate 2B session ID>"`, `edits:{addr:"0x0059df30",kind:"function",signature:"void __thiscall CheckBoxTextControlPane__Destructor(class CheckBoxTextControlPane *this)"}`. Dated disposable literal request used `database:"supervisor_uid0002ox_gate2b_20260817"` with those exact `edits` and returned `[{"edit":{"addr":"0x0059df30","kind":"function","signature":"void __thiscall CheckBoxTextControlPane__Destructor(class CheckBoxTextControlPane *this)"},"kind":"function","ok":true}]`. Exact expected/read-back IDA poststate: name `CheckBoxTextControlPane__Destructor`; displayed declaration `void __thiscall(struct CheckBoxTextControlPane *this)`, semantically the formal C++ `CheckBoxTextControlPane *this`; frame exactly `__return_address@0x0/0x4/_UNKNOWN *` with zero additions/removals/renames/retypes; AR absent; AP absent; FR absent; FP absent; range `[0x0059df30,0x0059df4f)` and SHA256 `A0A578B55DAF30413CC1E57083CF91358553811D35B8B04EA5A378629D0C5B44`; zero inbound xrefs; the same two exact outbound xrefs. Evidence/confidence: very high, from the successful public response and complete disposable immediate reread. Hard stop: any literal prestate, response, normalized declaration, frame/comment/range/hash/xref poststate mismatch requires no further mutation and no save.

**I06 - OnPaint pure rename.** Classification: apply. Prestate: function `[0x0059df50,0x0059e0ac)`, name `sub_59DF50`, declaration `void __thiscall(int this)`, frame exactly `y@0xc/0x4/int`, `outContext@0x10/0x28/EPFTileContext`, `var_3C@0x38/0x28/EPFTileContext`, `bounds@0x60/0x10/struct RectBounds`, `var_4@0x70/0x4/_DWORD`, `__saved_registers@0x74/0x4/_DWORD`, `__return_address@0x78/0x4/_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; SHA256 `18C32BAD02E02C95BC5F68D91BDAD5473046A4B98FD6F94161F8F5AB4F7D747E`; sole inbound data xref `0x0062e9e0`, zero code xrefs; desired name absent. Request: endpoint `rename`, `database:"supervisor_uid0000n5_persistverify_20260817"`, `batch:{func:{addr:"0x0059df50",name:"CheckBoxTextControlPane__OnPaint"},pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`. Expected poststate: only name changes; declaration, all seven frame rows, comments, range/hash, and xrefs remain exact. Immediate readback is complete.

**I07 - OnPaint type.** Classification: apply. Literal prestate produced by I06: function `[0x0059df50,0x0059e0ac)`, name `CheckBoxTextControlPane__OnPaint`, declaration `void __thiscall(int this)`, frame exactly `y@0xc/0x4/int`, `outContext@0x10/0x28/EPFTileContext`, `var_3C@0x38/0x28/EPFTileContext`, `bounds@0x60/0x10/struct RectBounds`, `var_4@0x70/0x4/_DWORD`, `__saved_registers@0x74/0x4/_DWORD`, `__return_address@0x78/0x4/_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; range `[0x0059df50,0x0059e0ac)`, SHA256 `18C32BAD02E02C95BC5F68D91BDAD5473046A4B98FD6F94161F8F5AB4F7D747E`; sole inbound data xref `0x0062e9e0`, zero inbound code xrefs, and entry-query outbound flow xref `0x0059df50 -> 0x0059df51`. Corrected request: endpoint `set_type`, `database:"<fresh runtime-attested Gate 2B session ID>"`, `edits:{addr:"0x0059df50",kind:"function",signature:"void __thiscall CheckBoxTextControlPane__OnPaint(class CheckBoxTextControlPane *this)"}`. Dated disposable literal request used `database:"supervisor_uid0002ox_gate2b_20260817"` with those exact `edits` and returned `[{"edit":{"addr":"0x0059df50","kind":"function","signature":"void __thiscall CheckBoxTextControlPane__OnPaint(class CheckBoxTextControlPane *this)"},"kind":"function","ok":true}]`. Exact expected/read-back IDA poststate: name `CheckBoxTextControlPane__OnPaint`; displayed declaration `void __thiscall(struct CheckBoxTextControlPane *this)`, semantically the formal C++ `CheckBoxTextControlPane *this`; all seven frame rows remain exactly as listed with zero additions/removals/renames/retypes; AR absent; AP absent; FR absent; FP absent; same exact range/hash and xrefs. Evidence/confidence: very high, from the successful public response and complete disposable immediate reread. Hard stop: any literal prestate, response, normalized declaration, frame/comment/range/hash/xref poststate mismatch requires no further mutation and no save.

**I08 - GetChecked pure rename.** Classification: apply. Prestate: function `[0x0059e0c0,0x0059e0c7)`, name `sub_59E0C0`, declaration `char __thiscall(_BYTE *this)`, frame exactly `__return_address@0x0/0x4/_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; bytes `8a 81 08 01 00 00 c3`, SHA256 `52F1855AE3D4D03E5FD70F6EBB3FEE20E96CD9F277FF988FFE395E4FCB5C5159`; zero inbound xrefs; desired name absent. Request: endpoint `rename`, `database:"supervisor_uid0000n5_persistverify_20260817"`, `batch:{func:{addr:"0x0059e0c0",name:"CheckBoxTextControlPane__GetChecked"},pure:true,allow_overwrite:false,dry_run:false,stop_on_error:true}`. Expected poststate: only name changes; all protected fields remain exact. Immediate readback is complete.

**I09 - GetChecked type.** Classification: apply. Literal prestate produced by I08: function `[0x0059e0c0,0x0059e0c7)`, name `CheckBoxTextControlPane__GetChecked`, declaration `char __thiscall(_BYTE *this)`, frame exactly `__return_address@0x0/0x4/_UNKNOWN *`; AR absent; AP absent; FR absent; FP absent; bytes `8a 81 08 01 00 00 c3`, SHA256 `52F1855AE3D4D03E5FD70F6EBB3FEE20E96CD9F277FF988FFE395E4FCB5C5159`; zero inbound xrefs and entry-query outbound flow xref `0x0059e0c0 -> 0x0059e0c6`. Corrected request: endpoint `set_type`, `database:"<fresh runtime-attested Gate 2B session ID>"`, `edits:{addr:"0x0059e0c0",kind:"function",signature:"bool __thiscall CheckBoxTextControlPane__GetChecked(const class CheckBoxTextControlPane *this)"}`. Dated disposable literal request used `database:"supervisor_uid0002ox_gate2b_20260817"` with those exact `edits` and returned `[{"edit":{"addr":"0x0059e0c0","kind":"function","signature":"bool __thiscall CheckBoxTextControlPane__GetChecked(const class CheckBoxTextControlPane *this)"},"kind":"function","ok":true}]`. Exact expected/read-back IDA poststate: name `CheckBoxTextControlPane__GetChecked`; displayed declaration `bool __thiscall(const struct CheckBoxTextControlPane *this)`, semantically the formal C++ `const CheckBoxTextControlPane *this`; frame exactly `__return_address@0x0/0x4/_UNKNOWN *` with zero additions/removals/renames/retypes; AR absent; AP absent; FR absent; FP absent; same exact range/bytes/hash/xrefs. Evidence/confidence: very high, from the successful public response and complete disposable immediate reread. Hard stop: any literal prestate, response, normalized declaration, frame/comment/range/hash/xref poststate mismatch requires no further mutation and no save.

**I10 - primary COL AR comment, manifest row M01.** Classification: apply.

- Literal prestate: item `[0x0062e998,0x0062e99c)`, primary complete-object-locator pointer data, name absent, type absent, dword `0x00651d44` targeting the CheckBoxTextControlPane primary COL at `0x00651d44`; AR absent; AP absent; FR not applicable; FP not applicable; inbound data xrefs none; inbound code xrefs none; outbound data xref exactly `0x0062e998 -> 0x00651d44`; outbound code xrefs none. Target aggregate is `[0x0062e998,0x0062ea3c)`, 164 bytes, SHA256 `8BD30D00387434A481D86CF072EEECC7A964DF2519C042067A16AB0A87E9B3C7`; successor `[0x0062ea3c,0x0062ea40)` remains the PartySearch primary COL pointer.
- Request: endpoint `set_address_comments`, `database:"supervisor_uid0000n5_persistverify_20260817"`, `items:{addr:"0x0062e998",comment:"CheckBoxTextControlPane primary complete-object-locator pointer; primary vtable is [0x0062e99c,0x0062ea00) with 25 slots."}`.
- Exact expected poststate: item `[0x0062e998,0x0062e99c)`, primary complete-object-locator pointer data, name absent, type absent, dword `0x00651d44` targeting the CheckBoxTextControlPane primary COL at `0x00651d44`; AR exact `CheckBoxTextControlPane primary complete-object-locator pointer; primary vtable is [0x0062e99c,0x0062ea00) with 25 slots.`; AP absent; FR not applicable; FP not applicable; inbound data xrefs none; inbound code xrefs none; outbound data xref exactly `0x0062e998 -> 0x00651d44`; outbound code xrefs none. Target aggregate remains `[0x0062e998,0x0062ea3c)`, 164 bytes, SHA256 `8BD30D00387434A481D86CF072EEECC7A964DF2519C042067A16AB0A87E9B3C7`; successor remains `[0x0062ea3c,0x0062ea40)`.
- Channel protection: only AR changes. AP remains absent; FR remains absent/not applicable because M01 is data; FP remains absent/not applicable because M01 is data.
- Immediate readback and hard stop: read this literal range/kind/name/type/value/semantic target, all four channels, all inbound/outbound xrefs, aggregate bytes/hash, and successor. If the literal prestate, mutation response, or exact poststate differs, perform no further mutation and do not save.

**I11 - EventHandler COL AR comment, manifest row M27.** Classification: apply.

- Literal prestate produced by I10: item `[0x0062ea00,0x0062ea04)`, inherited EventHandler complete-object-locator pointer data, name absent, type absent, dword `0x00651da4` targeting the CheckBoxTextControlPane EventHandler COL at `0x00651da4`; AR absent; AP absent; FR not applicable; FP not applicable; inbound data xrefs none; inbound code xrefs none; outbound data xref exactly `0x0062ea00 -> 0x00651da4`; outbound code xrefs none. The I10 item `[0x0062e998,0x0062e99c)` is primary complete-object-locator pointer data; name absent; type absent; dword `0x00651d44` targeting the CheckBoxTextControlPane primary COL at `0x00651d44`; AR exact `CheckBoxTextControlPane primary complete-object-locator pointer; primary vtable is [0x0062e99c,0x0062ea00) with 25 slots.`; AP absent; FR not applicable; FP not applicable; inbound data xrefs none; inbound code xrefs none; outbound data xref exactly `0x0062e998 -> 0x00651d44`; outbound code xrefs none. Target aggregate is `[0x0062e998,0x0062ea3c)`, 164 bytes, SHA256 `8BD30D00387434A481D86CF072EEECC7A964DF2519C042067A16AB0A87E9B3C7`; successor `[0x0062ea3c,0x0062ea40)` remains the PartySearch primary COL pointer.
- Request: endpoint `set_address_comments`, `database:"supervisor_uid0000n5_persistverify_20260817"`, `items:{addr:"0x0062ea00",comment:"CheckBoxTextControlPane inherited EventHandler complete-object-locator pointer at complete-object offset +0xa0; adjusted vtable is [0x0062ea04,0x0062ea30) with 11 slots."}`.
- Exact expected poststate: item `[0x0062ea00,0x0062ea04)`, inherited EventHandler complete-object-locator pointer data, name absent, type absent, dword `0x00651da4` targeting the CheckBoxTextControlPane EventHandler COL at `0x00651da4`; AR exact `CheckBoxTextControlPane inherited EventHandler complete-object-locator pointer at complete-object offset +0xa0; adjusted vtable is [0x0062ea04,0x0062ea30) with 11 slots.`; AP absent; FR not applicable; FP not applicable; inbound data xrefs none; inbound code xrefs none; outbound data xref exactly `0x0062ea00 -> 0x00651da4`; outbound code xrefs none. The I10 item `[0x0062e998,0x0062e99c)` is primary complete-object-locator pointer data; name absent; type absent; dword `0x00651d44` targeting the CheckBoxTextControlPane primary COL at `0x00651d44`; AR exact `CheckBoxTextControlPane primary complete-object-locator pointer; primary vtable is [0x0062e99c,0x0062ea00) with 25 slots.`; AP absent; FR not applicable; FP not applicable; inbound data xrefs none; inbound code xrefs none; outbound data xref exactly `0x0062e998 -> 0x00651d44`; outbound code xrefs none. Target aggregate remains `[0x0062e998,0x0062ea3c)`, 164 bytes, SHA256 `8BD30D00387434A481D86CF072EEECC7A964DF2519C042067A16AB0A87E9B3C7`; successor remains `[0x0062ea3c,0x0062ea40)`.
- Channel protection: only M27 AR changes at I11. M27 AP remains absent; M27 FR remains absent/not applicable because M27 is data; M27 FP remains absent/not applicable because M27 is data. M01 retains only its exact I10 AR delta, while M01 AP remains absent and M01 FR/FP remain absent/not applicable.
- Immediate readback and hard stop: read both literal COL-pointer item states, each four-channel state, every listed inbound/outbound xref, aggregate bytes/hash, and successor. If the literal prestate, mutation response, or exact poststate differs, perform no further mutation and do not save.

**I12 - TimerHandler COL AR comment, manifest row M39.** Classification: apply.

- Literal prestate produced by I11: item `[0x0062ea30,0x0062ea34)`, inherited TimerHandler complete-object-locator pointer data, name absent, type absent, dword `0x00651db8` targeting the CheckBoxTextControlPane TimerHandler COL at `0x00651db8`; AR absent; AP absent; FR not applicable; FP not applicable; inbound data xrefs none; inbound code xrefs none; outbound data xref exactly `0x0062ea30 -> 0x00651db8`; outbound code xrefs none. The I10 item `[0x0062e998,0x0062e99c)` is primary complete-object-locator pointer data; name absent; type absent; dword `0x00651d44` targeting the CheckBoxTextControlPane primary COL at `0x00651d44`; AR exact `CheckBoxTextControlPane primary complete-object-locator pointer; primary vtable is [0x0062e99c,0x0062ea00) with 25 slots.`; AP absent; FR not applicable; FP not applicable; inbound data xrefs none; inbound code xrefs none; outbound data xref exactly `0x0062e998 -> 0x00651d44`; outbound code xrefs none. The I11 item `[0x0062ea00,0x0062ea04)` is inherited EventHandler complete-object-locator pointer data; name absent; type absent; dword `0x00651da4` targeting the CheckBoxTextControlPane EventHandler COL at `0x00651da4`; AR exact `CheckBoxTextControlPane inherited EventHandler complete-object-locator pointer at complete-object offset +0xa0; adjusted vtable is [0x0062ea04,0x0062ea30) with 11 slots.`; AP absent; FR not applicable; FP not applicable; inbound data xrefs none; inbound code xrefs none; outbound data xref exactly `0x0062ea00 -> 0x00651da4`; outbound code xrefs none. Target aggregate is `[0x0062e998,0x0062ea3c)`, 164 bytes, SHA256 `8BD30D00387434A481D86CF072EEECC7A964DF2519C042067A16AB0A87E9B3C7`; successor `[0x0062ea3c,0x0062ea40)` remains the PartySearch primary COL pointer.
- Request: endpoint `set_address_comments`, `database:"supervisor_uid0000n5_persistverify_20260817"`, `items:{addr:"0x0062ea30",comment:"CheckBoxTextControlPane inherited TimerHandler complete-object-locator pointer at complete-object offset +0xa4; adjusted vtable is [0x0062ea34,0x0062ea3c) with 2 slots."}`.
- Exact expected poststate: item `[0x0062ea30,0x0062ea34)`, inherited TimerHandler complete-object-locator pointer data, name absent, type absent, dword `0x00651db8` targeting the CheckBoxTextControlPane TimerHandler COL at `0x00651db8`; AR exact `CheckBoxTextControlPane inherited TimerHandler complete-object-locator pointer at complete-object offset +0xa4; adjusted vtable is [0x0062ea34,0x0062ea3c) with 2 slots.`; AP absent; FR not applicable; FP not applicable; inbound data xrefs none; inbound code xrefs none; outbound data xref exactly `0x0062ea30 -> 0x00651db8`; outbound code xrefs none. The I10 item `[0x0062e998,0x0062e99c)` is primary complete-object-locator pointer data; name absent; type absent; dword `0x00651d44` targeting the CheckBoxTextControlPane primary COL at `0x00651d44`; AR exact `CheckBoxTextControlPane primary complete-object-locator pointer; primary vtable is [0x0062e99c,0x0062ea00) with 25 slots.`; AP absent; FR not applicable; FP not applicable; inbound data xrefs none; inbound code xrefs none; outbound data xref exactly `0x0062e998 -> 0x00651d44`; outbound code xrefs none. The I11 item `[0x0062ea00,0x0062ea04)` is inherited EventHandler complete-object-locator pointer data; name absent; type absent; dword `0x00651da4` targeting the CheckBoxTextControlPane EventHandler COL at `0x00651da4`; AR exact `CheckBoxTextControlPane inherited EventHandler complete-object-locator pointer at complete-object offset +0xa0; adjusted vtable is [0x0062ea04,0x0062ea30) with 11 slots.`; AP absent; FR not applicable; FP not applicable; inbound data xrefs none; inbound code xrefs none; outbound data xref exactly `0x0062ea00 -> 0x00651da4`; outbound code xrefs none. Target aggregate remains `[0x0062e998,0x0062ea3c)`, 164 bytes, SHA256 `8BD30D00387434A481D86CF072EEECC7A964DF2519C042067A16AB0A87E9B3C7`; successor remains `[0x0062ea3c,0x0062ea40)`.
- Channel protection: only M39 AR changes at I12. M39 AP remains absent; M39 FR remains absent/not applicable because M39 is data; M39 FP remains absent/not applicable because M39 is data. M01 and M27 retain only their exact prior AR deltas, while their AP channels remain absent and their FR/FP channels remain absent/not applicable.
- Immediate readback and hard stop: read all three literal COL-pointer item states, each four-channel state, every listed inbound/outbound xref, aggregate bytes/hash, and successor. If the literal prestate, mutation response, or exact poststate differs, perform no further mutation and do not save.

**P01 - protected scalar wrapper.** `[0x0059f050,0x0059f0a5)`, name `sub_59F050`, declaration `Pane *__thiscall(Pane *Block, char)`, frame exactly `__saved_registers@0x4/0x4/_DWORD`, `__return_address@0x8/0x4/_UNKNOWN *`, `arg_0@0xc/0x4/int`; AR/AP/FR/FP absent; SHA256 `884AC7B77C3568598EDEEFFABB848B233E94F5046FFA7A4CC03375B179FD202F`; inbound code xrefs `0x0059eff1`, `0x0059effc`, data xref `0x0062e99c`. No change.

**P02 - protected EventHandler adjustor.** `[0x0059efeb,0x0059eff6)`, name `sub_59EFEB`, declaration `_DWORD *__thiscall(_DWORD *this, char)`, frame exactly `__return_address@0x0/0x4/_UNKNOWN *`; AR exact `Block`; AP absent; FR absent; FP absent; SHA256 `6FA2AA41938D27F30B22F117243C446CD8607E13578C67FBD316936E555C0DE3`; sole inbound data xref `0x0062ea04`; code jump to `0x0059f050`. No change.

**P03 - protected TimerHandler adjustor.** `[0x0059eff6,0x0059f001)`, name `sub_59EFF6`, declaration `_DWORD *__thiscall(_DWORD *this, char)`, frame exactly `__return_address@0x0/0x4/_UNKNOWN *`; AR exact `Block`; AP absent; FR absent; FP absent; SHA256 `347A3B833AFD9F3A001F5B038F0E7FA247546CEE03DF2D1936D004C85065419C`; sole inbound data xref `0x0062ea34`; code jump to `0x0059f050`. No change.

**P04 - literal protected target-cell manifest.** The protected target aggregate is exactly `[0x0062e998,0x0062ea3c)`, 164 bytes, 41 four-byte data items, SHA256 `8BD30D00387434A481D86CF072EEECC7A964DF2519C042067A16AB0A87E9B3C7`; its exact successor `[0x0062ea3c,0x0062ea40)` is the PartySearch primary COL-pointer cell. Rows M01-M41 are the complete target-cell prestate and expected-poststate contract. External RTTI records at `0x00651d44`, `0x00651da4`, `0x00651db8`, `0x00651d58`, `0x00651d68`, and `0x00679b08` remain research evidence in Sections 13-14, but no action targets them and they are not part of the Gate 2B mutation-protection contract.

| Row | Exact item | Entity kind | Current name | Current type | Exact dword and semantic target | Current channels | Complete inbound xrefs | Complete outbound xrefs | Permitted delta | Exact expected post-readback |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| M01 | `[0x0062e998,0x0062e99c)` | primary COL-pointer data | absent | absent | `0x00651d44` -> CheckBoxTextControlPane primary COL | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062e998 -> 0x00651d44`; code none | AR becomes exact `CheckBoxTextControlPane primary complete-object-locator pointer; primary vtable is [0x0062e99c,0x0062ea00) with 25 slots.` | `[0x0062e998,0x0062e99c)` primary COL-pointer data; name absent; type absent; dword `0x00651d44` -> CheckBoxTextControlPane primary COL; AR exact `CheckBoxTextControlPane primary complete-object-locator pointer; primary vtable is [0x0062e99c,0x0062ea00) with 25 slots.`; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062e998 -> 0x00651d44`; outbound code none. |
| M02 | `[0x0062e99c,0x0062e9a0)` | primary slot 0 data | `??_7CheckBoxTextControlPane@@6B@` | absent | `0x0059f050` -> compiler scalar deleting destructor | AR absent; AP absent; FR not applicable; FP not applicable | data `0x0059c789`, `0x0059c81f`, `0x0059defc`, `0x0059df30`, `0x0059e23f`, `0x0059f056`; code none | data `0x0062e99c -> 0x0059f050`; code none | none | `[0x0062e99c,0x0062e9a0)` primary slot 0 data; name `??_7CheckBoxTextControlPane@@6B@`; type absent; dword `0x0059f050` -> compiler scalar deleting destructor; AR absent; AP absent; FR not applicable; FP not applicable; inbound data `0x0059c789`, `0x0059c81f`, `0x0059defc`, `0x0059df30`, `0x0059e23f`, `0x0059f056`; inbound code none; outbound data `0x0062e99c -> 0x0059f050`; outbound code none. |
| M03 | `[0x0062e9a0,0x0062e9a4)` | primary slot 1 data | absent | absent | `0x004f4b10` -> inherited `LObject::GetRuntimeClass` | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062e9a0 -> 0x004f4b10`; code none | none | `[0x0062e9a0,0x0062e9a4)` primary slot 1 data; name absent; type absent; dword `0x004f4b10` -> inherited `LObject::GetRuntimeClass`; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062e9a0 -> 0x004f4b10`; outbound code none. |
| M04 | `[0x0062e9a4,0x0062e9a8)` | primary slot 2 data | absent | absent | `0x0041b6c0` -> inherited `LObject::OnChangeMessage` | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062e9a4 -> 0x0041b6c0`; code none | none | `[0x0062e9a4,0x0062e9a8)` primary slot 2 data; name absent; type absent; dword `0x0041b6c0` -> inherited `LObject::OnChangeMessage`; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062e9a4 -> 0x0041b6c0`; outbound code none. |
| M05 | `[0x0062e9a8,0x0062e9ac)` | primary slot 3 data | absent | absent | `0x004b8e20` -> inherited `Pane::UpdateRenderRegion` | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062e9a8 -> 0x004b8e20`; code none | none | `[0x0062e9a8,0x0062e9ac)` primary slot 3 data; name absent; type absent; dword `0x004b8e20` -> inherited `Pane::UpdateRenderRegion`; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062e9a8 -> 0x004b8e20`; outbound code none. |
| M06 | `[0x0062e9ac,0x0062e9b0)` | primary slot 4 data | absent | absent | `0x0041d680` -> inherited `Pane::DrawOnTarget` | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062e9ac -> 0x0041d680`; code none | none | `[0x0062e9ac,0x0062e9b0)` primary slot 4 data; name absent; type absent; dword `0x0041d680` -> inherited `Pane::DrawOnTarget`; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062e9ac -> 0x0041d680`; outbound code none. |
| M07 | `[0x0062e9b0,0x0062e9b4)` | primary slot 5 data | absent | absent | `0x00544730` -> inherited `Pane::Show` | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062e9b0 -> 0x00544730`; code none | none | `[0x0062e9b0,0x0062e9b4)` primary slot 5 data; name absent; type absent; dword `0x00544730` -> inherited `Pane::Show`; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062e9b0 -> 0x00544730`; outbound code none. |
| M08 | `[0x0062e9b4,0x0062e9b8)` | primary slot 6 data | absent | absent | `0x00544750` -> inherited `Pane::Hide` | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062e9b4 -> 0x00544750`; code none | none | `[0x0062e9b4,0x0062e9b8)` primary slot 6 data; name absent; type absent; dword `0x00544750` -> inherited `Pane::Hide`; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062e9b4 -> 0x00544750`; outbound code none. |
| M09 | `[0x0062e9b8,0x0062e9bc)` | primary slot 7 data | absent | absent | `0x005447a0` -> inherited `Pane::GetParentPane` | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062e9b8 -> 0x005447a0`; code none | none | `[0x0062e9b8,0x0062e9bc)` primary slot 7 data; name absent; type absent; dword `0x005447a0` -> inherited `Pane::GetParentPane`; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062e9b8 -> 0x005447a0`; outbound code none. |
| M10 | `[0x0062e9bc,0x0062e9c0)` | primary slot 8 data | absent | absent | `0x00544800` -> inherited `Pane::InvalidateRect` | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062e9bc -> 0x00544800`; code none | none | `[0x0062e9bc,0x0062e9c0)` primary slot 8 data; name absent; type absent; dword `0x00544800` -> inherited `Pane::InvalidateRect`; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062e9bc -> 0x00544800`; outbound code none. |
| M11 | `[0x0062e9c0,0x0062e9c4)` | primary slot 9 data | absent | absent | `0x00544a20` -> inherited `Pane::GetDescription` | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062e9c0 -> 0x00544a20`; code none | none | `[0x0062e9c0,0x0062e9c4)` primary slot 9 data; name absent; type absent; dword `0x00544a20` -> inherited `Pane::GetDescription`; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062e9c0 -> 0x00544a20`; outbound code none. |
| M12 | `[0x0062e9c4,0x0062e9c8)` | primary slot 10 data | absent | absent | `0x00544b80` -> inherited `Pane::GetScreenBounds` | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062e9c4 -> 0x00544b80`; code none | none | `[0x0062e9c4,0x0062e9c8)` primary slot 10 data; name absent; type absent; dword `0x00544b80` -> inherited `Pane::GetScreenBounds`; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062e9c4 -> 0x00544b80`; outbound code none. |
| M13 | `[0x0062e9c8,0x0062e9cc)` | primary slot 11 data | absent | absent | `0x00544bd0` -> inherited `Pane::SetBounds` | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062e9c8 -> 0x00544bd0`; code none | none | `[0x0062e9c8,0x0062e9cc)` primary slot 11 data; name absent; type absent; dword `0x00544bd0` -> inherited `Pane::SetBounds`; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062e9c8 -> 0x00544bd0`; outbound code none. |
| M14 | `[0x0062e9cc,0x0062e9d0)` | primary slot 12 data | absent | absent | `0x00544c70` -> inherited `Pane::AddToLayer` | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062e9cc -> 0x00544c70`; code none | none | `[0x0062e9cc,0x0062e9d0)` primary slot 12 data; name absent; type absent; dword `0x00544c70` -> inherited `Pane::AddToLayer`; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062e9cc -> 0x00544c70`; outbound code none. |
| M15 | `[0x0062e9d0,0x0062e9d4)` | primary slot 13 data | absent | absent | `0x00544cb0` -> inherited `Pane::InsertInLayer` | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062e9d0 -> 0x00544cb0`; code none | none | `[0x0062e9d0,0x0062e9d4)` primary slot 13 data; name absent; type absent; dword `0x00544cb0` -> inherited `Pane::InsertInLayer`; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062e9d0 -> 0x00544cb0`; outbound code none. |
| M16 | `[0x0062e9d4,0x0062e9d8)` | primary slot 14 data | absent | absent | `0x00544ce0` -> inherited `Pane::RemoveFromLayer` | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062e9d4 -> 0x00544ce0`; code none | none | `[0x0062e9d4,0x0062e9d8)` primary slot 14 data; name absent; type absent; dword `0x00544ce0` -> inherited `Pane::RemoveFromLayer`; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062e9d4 -> 0x00544ce0`; outbound code none. |
| M17 | `[0x0062e9d8,0x0062e9dc)` | primary slot 15 data | absent | absent | `0x00544d30` -> inherited `Pane::SetPaneOrder` | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062e9d8 -> 0x00544d30`; code none | none | `[0x0062e9d8,0x0062e9dc)` primary slot 15 data; name absent; type absent; dword `0x00544d30` -> inherited `Pane::SetPaneOrder`; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062e9d8 -> 0x00544d30`; outbound code none. |
| M18 | `[0x0062e9dc,0x0062e9e0)` | primary slot 16 data | absent | absent | `0x00544d70` -> inherited `Pane::UnregisterEventHandler` | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062e9dc -> 0x00544d70`; code none | none | `[0x0062e9dc,0x0062e9e0)` primary slot 16 data; name absent; type absent; dword `0x00544d70` -> inherited `Pane::UnregisterEventHandler`; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062e9dc -> 0x00544d70`; outbound code none. |
| M19 | `[0x0062e9e0,0x0062e9e4)` | primary slot 17 data | absent | absent | `0x0059df50` -> `CheckBoxTextControlPane::OnPaint` | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062e9e0 -> 0x0059df50`; code none | none | `[0x0062e9e0,0x0062e9e4)` primary slot 17 data; name absent; type absent; dword `0x0059df50` -> `CheckBoxTextControlPane::OnPaint`; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062e9e0 -> 0x0059df50`; outbound code none. |
| M20 | `[0x0062e9e4,0x0062e9e8)` | primary slot 18 data | absent | absent | `0x00494b80` -> inherited `ControlPane::SetVisualState` | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062e9e4 -> 0x00494b80`; code none | none | `[0x0062e9e4,0x0062e9e8)` primary slot 18 data; name absent; type absent; dword `0x00494b80` -> inherited `ControlPane::SetVisualState`; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062e9e4 -> 0x00494b80`; outbound code none. |
| M21 | `[0x0062e9e8,0x0062e9ec)` | primary slot 19 data | absent | absent | `0x00494bb0` -> inherited `ControlPane::Enable` | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062e9e8 -> 0x00494bb0`; code none | none | `[0x0062e9e8,0x0062e9ec)` primary slot 19 data; name absent; type absent; dword `0x00494bb0` -> inherited `ControlPane::Enable`; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062e9e8 -> 0x00494bb0`; outbound code none. |
| M22 | `[0x0062e9ec,0x0062e9f0)` | primary slot 20 data | absent | absent | `0x00494bd0` -> inherited `ControlPane::Disable` | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062e9ec -> 0x00494bd0`; code none | none | `[0x0062e9ec,0x0062e9f0)` primary slot 20 data; name absent; type absent; dword `0x00494bd0` -> inherited `ControlPane::Disable`; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062e9ec -> 0x00494bd0`; outbound code none. |
| M23 | `[0x0062e9f0,0x0062e9f4)` | primary slot 21 data | absent | absent | `0x00494c00` -> inherited `ControlPane::SetIgnoreHitTesting` | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062e9f0 -> 0x00494c00`; code none | none | `[0x0062e9f0,0x0062e9f4)` primary slot 21 data; name absent; type absent; dword `0x00494c00` -> inherited `ControlPane::SetIgnoreHitTesting`; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062e9f0 -> 0x00494c00`; outbound code none. |
| M24 | `[0x0062e9f4,0x0062e9f8)` | primary slot 22 data | absent | absent | `0x00494c10` -> inherited `ControlPane::Deactivate` | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062e9f4 -> 0x00494c10`; code none | none | `[0x0062e9f4,0x0062e9f8)` primary slot 22 data; name absent; type absent; dword `0x00494c10` -> inherited `ControlPane::Deactivate`; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062e9f4 -> 0x00494c10`; outbound code none. |
| M25 | `[0x0062e9f8,0x0062e9fc)` | primary slot 23 data | absent | absent | `0x00494c30` -> inherited `ControlPane::Activate` | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062e9f8 -> 0x00494c30`; code none | none | `[0x0062e9f8,0x0062e9fc)` primary slot 23 data; name absent; type absent; dword `0x00494c30` -> inherited `ControlPane::Activate`; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062e9f8 -> 0x00494c30`; outbound code none. |
| M26 | `[0x0062e9fc,0x0062ea00)` | primary slot 24 data | absent | absent | `0x004214c0` -> `CheckBoxTextControlPane::HitTestPart(int,int)` shared constant-22 body | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062e9fc -> 0x004214c0`; code none | none | `[0x0062e9fc,0x0062ea00)` primary slot 24 data; name absent; type absent; dword `0x004214c0` -> `CheckBoxTextControlPane::HitTestPart(int,int)` shared constant-22 body; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062e9fc -> 0x004214c0`; outbound code none. |
| M27 | `[0x0062ea00,0x0062ea04)` | EventHandler COL-pointer data | absent | absent | `0x00651da4` -> CheckBoxTextControlPane EventHandler COL | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062ea00 -> 0x00651da4`; code none | AR becomes exact `CheckBoxTextControlPane inherited EventHandler complete-object-locator pointer at complete-object offset +0xa0; adjusted vtable is [0x0062ea04,0x0062ea30) with 11 slots.` | `[0x0062ea00,0x0062ea04)` EventHandler COL-pointer data; name absent; type absent; dword `0x00651da4` -> CheckBoxTextControlPane EventHandler COL; AR exact `CheckBoxTextControlPane inherited EventHandler complete-object-locator pointer at complete-object offset +0xa0; adjusted vtable is [0x0062ea04,0x0062ea30) with 11 slots.`; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062ea00 -> 0x00651da4`; outbound code none. |
| M28 | `[0x0062ea04,0x0062ea08)` | EventHandler slot 0 data | `??_7CheckBoxTextControlPane@@6B@_0` | absent | `0x0059efeb` -> compiler `this -= 0xa0` deleting-wrapper adjustor | AR absent; AP absent; FR not applicable; FP not applicable | data `0x0059c795`, `0x0059c82b`, `0x0059df02`, `0x0059df36`, `0x0059e24b`, `0x0059f05c`; code none | data `0x0062ea04 -> 0x0059efeb`; code none | none | `[0x0062ea04,0x0062ea08)` EventHandler slot 0 data; name `??_7CheckBoxTextControlPane@@6B@_0`; type absent; dword `0x0059efeb` -> compiler `this -= 0xa0` deleting-wrapper adjustor; AR absent; AP absent; FR not applicable; FP not applicable; inbound data `0x0059c795`, `0x0059c82b`, `0x0059df02`, `0x0059df36`, `0x0059e24b`, `0x0059f05c`; inbound code none; outbound data `0x0062ea04 -> 0x0059efeb`; outbound code none. |
| M29 | `[0x0062ea08,0x0062ea0c)` | EventHandler slot 1 data | absent | absent | `0x00544db0` -> inherited pointer/mouse default | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062ea08 -> 0x00544db0`; code none | none | `[0x0062ea08,0x0062ea0c)` EventHandler slot 1 data; name absent; type absent; dword `0x00544db0` -> inherited pointer/mouse default; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062ea08 -> 0x00544db0`; outbound code none. |
| M30 | `[0x0062ea0c,0x0062ea10)` | EventHandler slot 2 data | absent | absent | `0x0041d6b0` -> inherited key/text false default | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062ea0c -> 0x0041d6b0`; code none | none | `[0x0062ea0c,0x0062ea10)` EventHandler slot 2 data; name absent; type absent; dword `0x0041d6b0` -> inherited key/text false default; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062ea0c -> 0x0041d6b0`; outbound code none. |
| M31 | `[0x0062ea10,0x0062ea14)` | EventHandler slot 3 data | absent | absent | `0x0041d6b0` -> inherited IME false default | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062ea10 -> 0x0041d6b0`; code none | none | `[0x0062ea10,0x0062ea14)` EventHandler slot 3 data; name absent; type absent; dword `0x0041d6b0` -> inherited IME false default; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062ea10 -> 0x0041d6b0`; outbound code none. |
| M32 | `[0x0062ea14,0x0062ea18)` | EventHandler slot 4 data | absent | absent | `0x00544de0` -> inherited packet-event default | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062ea14 -> 0x00544de0`; code none | none | `[0x0062ea14,0x0062ea18)` EventHandler slot 4 data; name absent; type absent; dword `0x00544de0` -> inherited packet-event default; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062ea14 -> 0x00544de0`; outbound code none. |
| M33 | `[0x0062ea18,0x0062ea1c)` | EventHandler slot 5 data | absent | absent | `0x00544df0` -> inherited system/control-event default | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062ea18 -> 0x00544df0`; code none | none | `[0x0062ea18,0x0062ea1c)` EventHandler slot 5 data; name absent; type absent; dword `0x00544df0` -> inherited system/control-event default; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062ea18 -> 0x00544df0`; outbound code none. |
| M34 | `[0x0062ea1c,0x0062ea20)` | EventHandler slot 6 data | absent | absent | `0x00544e00` -> inherited type-19 default | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062ea1c -> 0x00544e00`; code none | none | `[0x0062ea1c,0x0062ea20)` EventHandler slot 6 data; name absent; type absent; dword `0x00544e00` -> inherited type-19 default; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062ea1c -> 0x00544e00`; outbound code none. |
| M35 | `[0x0062ea20,0x0062ea24)` | EventHandler slot 7 data | absent | absent | `0x004a89f0` -> inherited `EventHandler::ForwardHandlerOrder` | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062ea20 -> 0x004a89f0`; code none | none | `[0x0062ea20,0x0062ea24)` EventHandler slot 7 data; name absent; type absent; dword `0x004a89f0` -> inherited `EventHandler::ForwardHandlerOrder`; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062ea20 -> 0x004a89f0`; outbound code none. |
| M36 | `[0x0062ea24,0x0062ea28)` | EventHandler slot 8 data | absent | absent | `0x00544e10` -> inherited local-event pair | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062ea24 -> 0x00544e10`; code none | none | `[0x0062ea24,0x0062ea28)` EventHandler slot 8 data; name absent; type absent; dword `0x00544e10` -> inherited local-event pair; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062ea24 -> 0x00544e10`; outbound code none. |
| M37 | `[0x0062ea28,0x0062ea2c)` | EventHandler slot 9 data | absent | absent | `0x00544e30` -> inherited screen-event pair | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062ea28 -> 0x00544e30`; code none | none | `[0x0062ea28,0x0062ea2c)` EventHandler slot 9 data; name absent; type absent; dword `0x00544e30` -> inherited screen-event pair; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062ea28 -> 0x00544e30`; outbound code none. |
| M38 | `[0x0062ea2c,0x0062ea30)` | EventHandler slot 10 data | absent | absent | `0x00544e70` -> inherited acceptance predicate | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062ea2c -> 0x00544e70`; code none | none | `[0x0062ea2c,0x0062ea30)` EventHandler slot 10 data; name absent; type absent; dword `0x00544e70` -> inherited acceptance predicate; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062ea2c -> 0x00544e70`; outbound code none. |
| M39 | `[0x0062ea30,0x0062ea34)` | TimerHandler COL-pointer data | absent | absent | `0x00651db8` -> CheckBoxTextControlPane TimerHandler COL | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062ea30 -> 0x00651db8`; code none | AR becomes exact `CheckBoxTextControlPane inherited TimerHandler complete-object-locator pointer at complete-object offset +0xa4; adjusted vtable is [0x0062ea34,0x0062ea3c) with 2 slots.` | `[0x0062ea30,0x0062ea34)` TimerHandler COL-pointer data; name absent; type absent; dword `0x00651db8` -> CheckBoxTextControlPane TimerHandler COL; AR exact `CheckBoxTextControlPane inherited TimerHandler complete-object-locator pointer at complete-object offset +0xa4; adjusted vtable is [0x0062ea34,0x0062ea3c) with 2 slots.`; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062ea30 -> 0x00651db8`; outbound code none. |
| M40 | `[0x0062ea34,0x0062ea38)` | TimerHandler slot 0 data | `??_7CheckBoxTextControlPane@@6B@_1` | absent | `0x0059eff6` -> compiler `this -= 0xa4` deleting-wrapper adjustor | AR absent; AP absent; FR not applicable; FP not applicable | data `0x0059c79f`, `0x0059c835`, `0x0059df0c`, `0x0059df40`, `0x0059e255`, `0x0059f066`; code none | data `0x0062ea34 -> 0x0059eff6`; code none | none | `[0x0062ea34,0x0062ea38)` TimerHandler slot 0 data; name `??_7CheckBoxTextControlPane@@6B@_1`; type absent; dword `0x0059eff6` -> compiler `this -= 0xa4` deleting-wrapper adjustor; AR absent; AP absent; FR not applicable; FP not applicable; inbound data `0x0059c79f`, `0x0059c835`, `0x0059df0c`, `0x0059df40`, `0x0059e255`, `0x0059f066`; inbound code none; outbound data `0x0062ea34 -> 0x0059eff6`; outbound code none. |
| M41 | `[0x0062ea38,0x0062ea3c)` | TimerHandler slot 1 data | absent | absent | `0x00544e90` -> inherited `Pane::OnTimer` default | AR absent; AP absent; FR not applicable; FP not applicable | data none; code none | data `0x0062ea38 -> 0x00544e90`; code none | none | `[0x0062ea38,0x0062ea3c)` TimerHandler slot 1 data; name absent; type absent; dword `0x00544e90` -> inherited `Pane::OnTimer` default; AR absent; AP absent; FR not applicable; FP not applicable; inbound data none; inbound code none; outbound data `0x0062ea38 -> 0x00544e90`; outbound code none. |

Final readback must inspect M01 through M41 individually and match every literal field in each row's Exact expected post-readback column; no row may be inferred from another row or accepted through an aggregate substitute. It must also prove only these changes outside and within P04: six AR comments at `0x004214c0`, `0x0059ded0`, `0x0059e0b0`, `0x0062e998`, `0x0062ea00`, `0x0062ea30`; three function names at `0x0059df30`, `0x0059df50`, `0x0059e0c0`; and three function declarations at those same modeled starts. The declaration readbacks must be exactly `void __thiscall(struct CheckBoxTextControlPane *this)`, `void __thiscall(struct CheckBoxTextControlPane *this)`, and `bool __thiscall(const struct CheckBoxTextControlPane *this)` respectively; those are IDA-normalized displays of the explicit-`class` request forms and preserve the intended formal C++ owner-pointer semantics. No standalone local type declaration is added. No target item boundary, target dword, target table name/type, target AP/FR/FP channel, target inbound/outbound xref, frame row, executable byte/hash, raw-function status, compiler-function state, aggregate hash, or PartySearch successor may change. No save is permitted until the complete item-by-item reread passes; any mismatch requires no further mutation and no save.

## First-Draft C++ Recommendation

All blocks below are the accepted formal payloads implemented in the named ordinary page/channel during this callback and retained verbatim as source evidence.

Formal UID00005P CPP root replacement, preserving `[[CHILDREN]]`:

```cpp
#include "SpecializedButtonPanes.h"

#include <cwchar>

#include "../../app/StartupWindow.h"
#include "../../render/EPFTileContext.h"
#include "../../render/ImageLib.h"
#include "../../render/Surface.h"

[[CHILDREN]]
```

Formal UID000022 H block:

```h
class CheckBoxTextControlPane : public ControlPane
{
public:
    CheckBoxTextControlPane(bool checked,
                            const wchar_t *label,
                            const RectBounds *bounds);
    virtual ~CheckBoxTextControlPane();

    void SetChecked(bool checked);
    bool GetChecked() const;

protected:
    virtual void OnPaint();
    virtual unsigned char HitTestPart(int x, int y);

private:
    bool m_checked;
    wchar_t m_label[256];
};

typedef char CheckBoxTextControlPaneSizeMustBe780[
    sizeof(CheckBoxTextControlPane) == 0x30c ? 1 : -1];

[[CHILDREN]]
```

Formal UID0003FE CPP block at child position 10:

```cpp
CheckBoxTextControlPane::CheckBoxTextControlPane(
    bool checked,
    const wchar_t *label,
    const RectBounds *bounds)
    : ControlPane(8, bounds),
      m_checked(checked)
{
    wcscpy_s(m_label, 256, label);
}
```

Formal UID0003FF CPP block at child position 20:

```cpp
CheckBoxTextControlPane::~CheckBoxTextControlPane()
{
}
```

Formal UID0003FG CPP block at child position 30:

```cpp
void CheckBoxTextControlPane::OnPaint()
{
    EPFTileContext uncheckedFrame;
    EPFTileContext checkedFrame;
    uncheckedFrame.Initialize();
    checkedFrame.Initialize();

    g_pEPFLib->LookupLayoutEntry(L"ON", 0, &uncheckedFrame);
    g_pEPFLib->LookupLayoutEntry(L"ON", 1, &checkedFrame);

    SetDrawColor(0);
    g_pfnFillRect(this, &m_visibleBounds);
    SetTextColor(128);
    SetTextBackColor(128);
    m_textDrawMode = 1;
    SetFontId(static_cast<unsigned short>(IsLegacyAssetMode()));

    const int textLength = static_cast<int>(wcslen(m_label));
    const int textY = m_visibleBounds.top + 16;
    MoveTo(m_visibleBounds.left + 28, textY);
    DrawWideText(m_label, textLength);
    MoveTo(m_visibleBounds.left + 29, textY);
    DrawWideText(m_label, textLength);

    RectBounds destinationBounds;
    InitRectBounds(&destinationBounds, 4, 3, 24, 23);

    const EPFTileContext *frame =
        m_checked ? &checkedFrame : &uncheckedFrame;
    RenderTileFrame(frame,
                    &frame->bounds,
                    &destinationBounds,
                    0,
                    L"BU",
                    0);
}
```

Formal UID0003FH CPP block at child position 40, preserved exactly:

```cpp
void CheckBoxTextControlPane::SetChecked(bool checked)
{
    m_checked = checked;
}
```

Formal UID0003FI CPP block at child position 50:

```cpp
bool CheckBoxTextControlPane::GetChecked() const
{
    return m_checked;
}
```

Formal UID0002DZ CPP block at child position 60:

```cpp
unsigned char CheckBoxTextControlPane::HitTestPart(int, int)
{
    return 22;
}
```

UID0002OX, UID0003FJ, UID0001KJ, UID00026U, UID0001YW, UID0001W7, and the adjustor-thunk record keep both formal channels blank because they are compiler data/wrappers, evidence-only types, or non-emitting aggregates. UID0003FE/FF/FG/FH/FI/2DZ H remains blank because UID000022 centralizes all declarations.

## Final Recommendation

The ordinary implementation is complete and source-ready at high confidence: one complete owner declaration, six semantic definitions, exact natural layout, and compiler-only treatment for tables/wrappers. The only unresolved historical question is whether the original project used a standalone CheckBox source file; the implemented shared source-family route is the strongest project-level reconstruction and does not alter behavior. The failed old I05 syntax is now replaced by evidence-backed explicit-`class` requests for all three type stages, with deterministic normalized displays and unchanged-frame contracts. After this exact repaired artifact passes fresh Gate 1, the supervisor may perform a fresh Gate 2B preflight and ordered retry. Manual coverage, Gate 2A/2B decisions, and execution/archive authority remain supervisor-owned roles whose state is established from the exact report path and validator-owned lifecycle metadata.

## Recommended Target Doc Changes

Implemented for UID0002OX:

- Metadata is exactly `COMPLETION:94`, `CONFIDENCE:96`, `CANONICAL_OWNER:000022`, `RECONSTRUCTABLE:FALSE`, empty `EMITTER_UIDS`, empty optional position.
- The exact same path/range and blank formal CPP/H are preserved.
- The empty-emitter rationale is replaced by the complete range/hash/items, all table/RTTI/slot/xref/store/source-cause/compiler-output evidence from this report.
- Explicit history preserves the former reconstructable/owner-emitter state and explains why it generated an empty marker.
- The page states that declaration/method source regenerates the tables and no direct `.rdata` source is valid.

## Recommended Support Doc Changes

| UID/path | Implemented or verified disposition |
| --- | --- |
| 000022 `by-class/CheckBoxTextControlPane.md` | Complete class declaration moved from CPP to formal H with `[[CHILDREN]]`; terminal virtual, layout/method/compiler maps, and 95/96 score implemented. CPP is blank. |
| 00005P `by-class/GenderButtonControlPane.md` | All Gender content preserved; shared CPP preamble replaced with the Section 22 include-closed root. |
| 0000NY `by-file/SpecializedButtonPanes.md` | Complete CheckBox route/order implemented; old GetControlType/blank-child state historicalized; score is 94/95. |
| 0001YW `by-type/by-vtable/SpecializedButtonPaneVtables.md` | Stale CheckBox `+0x68` pseudo-slot replaced by exact 25/11/2 tables, RTTI/PMDs, stores, source children, and terminal HitTestPart; score unchanged. |
| 0001W7 `by-type/by-struct/SpecializedButtonPaneLayouts.md` | Exact CheckBox `0x30c` layout and inherited facets implemented; score is 95/97. |
| 0001KJ executable map | All exact CheckBox children/compiler routes and source status implemented; false/non-emitting retained; score is 92/94. |
| 0002DZ corrected page | Same UID moved to `0x004214c0-0x004214c5.CheckBoxTextControlPaneHitTestPart.md`; ABI/12-xref/history/formal CPP implemented; score is 94/96. |
| 00026U read-only aggregate | All other children preserved; UID0002OX corrected to false/non-emitting complete data/source cause; score is 92/95. |
| 0003FE | Constructor CPP and complete evidence/history implemented; score is 93/95. |
| 0003FF | Empty ordinary destructor CPP and compiler-mechanics rationale implemented; score is 93/95. |
| 0003FG | Complete OnPaint CPP and dependencies implemented; score is 93/95. |
| 0003FH | Exact CPP preserved; report evidence/source order implemented; score is 92/94. |
| 0003FI | Getter CPP and centralized-H rationale implemented; score is 92/94. |
| 0003FJ | False/non-emitting, blank formals, and complete wrapper evidence implemented; score is 93/95. |
| 0000VN | Physically verified: existing exact adjustor record remains sufficient. |
| 0000WT `by-memory/0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland.md` | Validator-propagated same-UID path retained; stale active `GetControlType` and old UID0002DZ/owner scores were historicalized and replaced by exact HitTestPart byte-return/`retn 8`/twelve-xref evidence. |
| 0000WR `by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md` | Validator-propagated UID0002DZ path link verified; the page continues to treat this body as a reusable non-fitting-room checkbox helper. |
| 0002E0 `by-memory/0x004214d0-0x004214f7.FittingRoomEntryTailVectorRangeRelease.md` | Validator-propagated preceding-boundary link verified; exact target/gap/boundary evidence remained unchanged. |
| 0000VN `by-memory/-ignored.md` | Validator-propagated UID0002DZ owner-doc path link verified while preserving the complete CheckBox adjustor-thunk record. |
| 0000QU/0000TN/00004I/000038/0000BU | Physically verified dependency ownership; no edits or score changes. |
| 0003E7 | Physically verified successor boundary; no edit. |

## Score And Metadata Recommendation

| UID | Historical pre-callback | Current implemented | Metadata disposition |
| --- | --- | --- | --- |
| 0002OX | 86/92 true owner/emitter 000022 | 94/96 false, owner 000022, no emitter | complete compiler data |
| 000022 | 90/92 | 95/96 | true, file-owned/emitting |
| 0000NY | 92/94 | 94/95 | file root unchanged |
| 0001YW | 94/96 | 94/96 | false/non-emitting unchanged |
| 0001W7 | 93/95 | 95/97 | false/non-emitting unchanged |
| 0001KJ | 88/89 | 92/94 | false/non-emitting unchanged |
| 0002DZ | 91/94 | 94/96 | true owner/emitter 000022; corrected semantic path |
| 00026U | 88/92 | 92/95 | false/non-emitting unchanged |
| 0003FE | 85/88 | 93/95 | true owner/emitter 000022 |
| 0003FF | 86/90 | 93/95 | true owner/emitter 000022 |
| 0003FG | 87/91 | 93/95 | true owner/emitter 000022 |
| 0003FH | 87/88 | 92/94 | true owner/emitter 000022 |
| 0003FI | 86/88 | 92/94 | true owner/emitter 000022 |
| 0003FJ | 87/91 true/emitting | 93/95 false, owner 000022, no emitter | compiler scalar wrapper |

Unchanged scores are exceptional here only for UID0001YW and verify-only dependencies. UID0001YW is already 94/96 and its remaining lexical compiler names justify the cap; dependency pages are not incomplete because of CheckBox consumption.

## Open Questions With Attempted Resolution

| Question | Attempt | Disposition |
| --- | --- | --- |
| Original literal filename? | Compared current project route, sibling controls, generated history, physical address locality, and consumer ownership. | Highest probability is current shared `SpecializedButtonPanes`; standalone CheckBox file remains a nonblocking lower-ranked alternative. |
| Original field spelling? | Compared constructor/getter/setter/paint semantics and existing project naming. | `m_checked` and `m_label` are high-probability source names; ABI/layout is exact even if lexical spelling differed. |
| OnPaint helper names? | Mapped every callee to current ImageLib/GrafPort/Surface/RectBounds source APIs and exact literals. | Closed at first-draft source quality. |
| HitTestPart or GetControlType? | Checked base virtual order, byte return, `retn 8`, and all twelve vtable xrefs. | Closed: HitTestPart(int,int). |
| Raw methods live? | Checked bytes, boundaries, xrefs, inlined copies, neighboring source children, and field users. | Retained source methods; no future investigation blocker. |
| Exact public owner-pointer type syntax? | Reproduced the old I05 failure, inspected parser flags/local types, tested explicit tags on the unsaved rollback copy, and reread all three complete poststates plus canonical state. | Closed: full declarations require `class CheckBoxTextControlPane *` (`const class` for getter); IDA displays equivalent `struct` pointers; no separate local-type declaration. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Manual coverage remains supervisor-owned and was not edited by B001. These exact payloads are retained for dynamic supervisor comparison after ordinary callback verification.

Replace `by-memory/-coverage-report.md` UID0002OX row in place with:

`        - [UID:0002OX][0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData](by-memory/0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData.md) 0x0062e998-0x0062ea3c | compiler RTTI/vtable data | CheckBoxTextControlPaneVtableData : ignored : 94% : very-strong : Exact 164-byte, SHA256 8BD30D00387434A481D86CF072EEECC7A964DF2519C042067A16AB0A87E9B3C7, false/non-emitting CheckBoxTextControlPane primary/EventHandler/TimerHandler COL and 25/11/2-slot vtable cluster; RTTI proves one direct ControlPane base with inherited +0xa0/+0xa4 facets, all eighteen head-store xrefs and every slot are complete, and normal class/method source through UID000022/UID0000NY regenerates the compiler data without raw arrays or an empty marker.`

Replace the exact owner/file/type rows with:

`- [UID:000022][CheckBoxTextControlPane](by-class/CheckBoxTextControlPane.md) : reconstructable : 95% : very-strong : Complete 0x30c ControlPane-derived checkbox-text class with bool +0x108, natural padding, wchar_t[256] +0x10a, complete H declaration, constructor/destructor/paint/set/get/HitTestPart source route, exact three-view vtables, compiler-wrapper exclusions, and SpecializedButtonPanes ownership.`

`- [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) : reconstructable : 94% : very-strong : Current NexusTK/ui/controls/SpecializedButtonPanes.cpp/.h route for Gender, Direction, and CheckBoxTextControlPane; CheckBox now has one complete H declaration, six semantic definitions, exact dependencies/order, compiler-only vtable/scalar/adjustor exclusions, and no UID0002OX empty marker, while the literal historical shared filename remains inferred.`

`- [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md) : ignored : 94% : very-strong : Exact non-emitting compiler RTTI/vtable evidence for Gender, Direction, and CheckBoxTextControlPane; CheckBox has complete 25/11/2 primary/EventHandler/TimerHandler slots, one direct ControlPane source base, inherited +0xa0/+0xa4 facets, exact stores, and no historical +0x68 pseudo-slot.`

`- [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md) : ignored : 95% : very-strong : Exact evidence-only specialized-button layouts including CheckBoxTextControlPane size 0x30c, ControlPane base 0x108, bool +0x108, natural pad +0x109, wchar_t[256] +0x10a, and inherited EventHandler/TimerHandler facets +0xa0/+0xa4; human declarations emit through class H pages.`

Replace UID0002DZ row and use the corrected same-UID path:

`            - [UID:0002DZ][0x004214c0-0x004214c5.CheckBoxTextControlPaneHitTestPart](by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneHitTestPart.md) 0x004214c0-0x004214c5 | folded terminal virtual | CheckBoxTextControlPaneHitTestPart : reconstructable : 94% : very-strong : Exact mov-al-22/retn-8 ControlPane-family HitTestPart(int,int) body with twelve primary-vtable xrefs, including CheckBox slot 0x0062e9fc; UID000022 emits the normal unsigned-byte two-coordinate override, while the physical IDA body retains non-class-specific folded identity.`

Replace UID0001KJ and UID00026U rows with:

`    - [UID:0001KJ][0x0059ded0-0x0059f0a5.CheckBoxTextControlPaneExecutableMap](by-memory/0x0059ded0-0x0059f0a5.CheckBoxTextControlPaneExecutableMap.md) 0x0059ded0-0x0059f0a4 | mixed executable map | CheckBoxTextControlPane : ignored : 92% : very-strong : Complete non-emitting sparse map over retained constructor, ordinary destructor, OnPaint, SetChecked, GetChecked, shared HitTestPart projection, two compiler adjustors, scalar deleting wrapper, exact hashes/boundaries, and foreign user-list/party-search spans; source emits only through exact children and UID000022.`

`    - [UID:00026U][0x0062e8fc-0x0062eccc.UserListReadOnlyData](by-memory/0x0062e8fc-0x0062eccc.UserListReadOnlyData.md) 0x0062e8fc-0x0062eccc | mixed read-only-data aggregate | UserListReadOnlyData : ignored : 92% : very-strong : Exact false/non-emitting aggregate with complete UserListDialogPane, CheckBoxTextControlPane, PartySearchEditPane, UserListPane, and resource children; UID0002OX is exact compiler data regenerated by reusable UID000022/UID0000NY source and does not transfer ownership to social user-list code.`

Insert these exact rows immediately after UID0001KJ in address order, except UID0002DZ remains at its physical `0x004214c0` location:

`        - [UID:0003FE][0x0059ded0-0x0059df27.CheckBoxTextControlPaneConstructorRaw](by-memory/0x0059ded0-0x0059df27.CheckBoxTextControlPaneConstructorRaw.md) 0x0059ded0-0x0059df27 | retained raw constructor | CheckBoxTextControlPaneConstructor : reconstructable : 93% : very-strong : Exact 87-byte constructor with ControlPane type 8, checked byte, 256-wide label copy, three vptr stores, zero direct xrefs, and three independently inlined live copies.`

`        - [UID:0003FF][0x0059df30-0x0059df4f.CheckBoxTextControlPaneTeardownHelper](by-memory/0x0059df30-0x0059df4f.CheckBoxTextControlPaneTeardownHelper.md) 0x0059df30-0x0059df4f | ordinary destructor | CheckBoxTextControlPaneDestructor : reconstructable : 93% : very-strong : Exact empty source destructor whose observed vptr restoration and Pane teardown are compiler mechanics, separate from scalar deletion.`

`        - [UID:0003FG][0x0059df50-0x0059e0ac.CheckBoxTextControlPaneOnPaint](by-memory/0x0059df50-0x0059e0ac.CheckBoxTextControlPaneOnPaint.md) 0x0059df50-0x0059e0ac | virtual paint | CheckBoxTextControlPaneOnPaint : reconstructable : 93% : very-strong : Complete ON frame 0/1 lookup, draw/text/font state, twice-drawn label, checked selection, exact 4,3,24,23 destination, BU palette/resource literal, and shared dependency route.`

`        - [UID:0003FH][0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw](by-memory/0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md) 0x0059e0b0-0x0059e0c0 | retained raw setter | CheckBoxTextControlPaneSetChecked : reconstructable : 92% : very-strong : Exact 16-byte m_checked assignment with no invalidation, bounded by paint/getter and corroborated by constructor/paint/consumer field use despite zero direct xrefs.`

`        - [UID:0003FI][0x0059e0c0-0x0059e0c7.CheckBoxTextControlPaneGetChecked](by-memory/0x0059e0c0-0x0059e0c7.CheckBoxTextControlPaneGetChecked.md) 0x0059e0c0-0x0059e0c7 | checked getter | CheckBoxTextControlPaneGetChecked : reconstructable : 92% : very-strong : Exact seven-byte const bool getter returning m_checked at +0x108, with centralized class-H declaration and no side effects.`

`        - [UID:0003FJ][0x0059f050-0x0059f0a5.CheckBoxTextControlPaneScalarDeletingDestructor](by-memory/0x0059f050-0x0059f0a5.CheckBoxTextControlPaneScalarDeletingDestructor.md) 0x0059f050-0x0059f0a5 | compiler scalar deleting destructor | CheckBoxTextControlPaneScalarDeletingDestructor : ignored : 93% : very-strong : Exact false/non-emitting delete-flag wrapper with three vptr resets, Pane teardown, conditional delete, and two +0xa0/+0xa4 adjustor routes; generated from the normal virtual destructor and never handwritten.`

The tracker row is validator-owned and must not be manually edited. Dynamic generated/tracker authority must be reread after callback validation.

## Follow-Up Actions

Role/disposition facts:

1. B001 applied accepted ordinary claims C001-C054 under short leases, ran serial scoped validators, recorded dated receipts, and released every lease.
2. B001 physically reread validator-generated CPP/H and checked only applied or independently verified rows.
3. Supervisor owns manual coverage reconciliation under C055-C058 and a fresh Gate 2B transaction under C059-C074; this repair made no coverage or canonical/saved IDA change, and its disposable parser tests are dated evidence only.
4. Gate 2A and any later generated-output decision use a fresh dynamic reread rather than treating the dated callback snapshot as continuing authority.
5. Report execution/archive authority belongs only to the supervisor and validator-owned lifecycle metadata; this report makes no assertion about a future lifecycle state or reassignment.

## Confidence

Overall confidence is `very high` for range, hash, contents, inheritance, slots, xrefs, source/compiler split, layout, behavior, ABI, and the corrected public `set_type` forms/poststates. Confidence is `high` for exact human source spellings and shared source filename. No unresolved question blocks implementation-ready C++ or the deterministic Gate 2B retry.

## Validator Results

No validator ran during this additive Gate 2B report-text repair. The accepted Gate 2A-era receipts below are preserved unchanged: all commands ran from exact cwd `E:\NTK\GhidraBridge\source-3\project-documentation` with the exact single-line form `python .\tools\validator.py --mode file --file '<relative-path>' --apply --queue-timeout 240`; every command exited `0` with `ok:1`, generated refresh was deferred, and no generated file was edited directly.

| Command ID | Timestamp | Exact relative `--file` argument | Literal warnings/errors and side effects |
| --- | --- | --- | --- |
| `000000025503` | `2026-08-17T14:32:29-04:00` | `by-memory/0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData.md` | No error; target score/reconstructable/emitter/formal metadata applied. Before UID0002DZ path registration, generated cross-link normalization still named the historical path. |
| `000000025505` | `2026-08-17T14:33:42-04:00` | `by-class/CheckBoxTextControlPane.md` | No error; CPP became blank, H became populated, and scores changed. Missing-reference warnings named the not-yet-registered new child UIDs; these were resolved by later child validation. |
| `000000025506` | `2026-08-17T14:34:02-04:00` | `by-class/GenderButtonControlPane.md` | No error; shared formal CPP root updated. |
| `000000025507` | `2026-08-17T14:35:38-04:00` | `by-file/SpecializedButtonPanes.md` | No error; file route/order/detail and score applied. |
| `000000025509` | `2026-08-17T14:36:52-04:00` | `by-type/by-vtable/SpecializedButtonPaneVtables.md` | No error; complete CheckBox vtable detail applied. |
| `000000025510` | `2026-08-17T14:37:37-04:00` | `by-type/by-struct/SpecializedButtonPaneLayouts.md` | No error; exact CheckBox layout and score applied. |
| `000000025511` | `2026-08-17T14:38:42-04:00` | `by-memory/0x0059ded0-0x0059f0a5.CheckBoxTextControlPaneExecutableMap.md` | No error; executable/source/compiler map and score applied. |
| `000000025513` | `2026-08-17T14:39:50-04:00` | `by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneHitTestPart.md` | No error; same-UID path update applied from the historical GetControlType filename. Validator reported 194 `missing_ref_uid` warnings while traversing broad pre-existing references, 21 UID-link updates, and five reference-source path updates. |
| `000000025515` | `2026-08-17T14:40:53-04:00` | `by-memory/0x0062e8fc-0x0062eccc.UserListReadOnlyData.md` | No error; aggregate child/source-cause detail and score applied. |
| `000000025517` | `2026-08-17T14:41:41-04:00` | `by-memory/0x0059ded0-0x0059df27.CheckBoxTextControlPaneConstructorRaw.md` | No error; new child mapping, position 10, formal CPP, evidence, and score registered. |
| `000000025519` | `2026-08-17T14:42:19-04:00` | `by-memory/0x0059df30-0x0059df4f.CheckBoxTextControlPaneTeardownHelper.md` | No error; new child mapping, position 20, formal CPP, evidence, and score registered. |
| `000000025531` | `2026-08-17T14:43:04-04:00` | `by-memory/0x0059df50-0x0059e0ac.CheckBoxTextControlPaneOnPaint.md` | No error; new child mapping, position 30, complete formal CPP, dependencies, and score registered. |
| `000000025535` | `2026-08-17T14:44:13-04:00` | `by-memory/0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md` | No error; existing formal CPP preserved; position 40, evidence, and score applied. |
| `000000025539` | `2026-08-17T14:45:12-04:00` | `by-memory/0x0059e0c0-0x0059e0c7.CheckBoxTextControlPaneGetChecked.md` | No error; new child mapping, position 50, formal CPP, evidence, and score registered. |
| `000000025540` | `2026-08-17T14:46:33-04:00` | `by-memory/0x0059f050-0x0059f0a5.CheckBoxTextControlPaneScalarDeletingDestructor.md` | No error; new compiler-child mapping and false/non-emitting metadata registered. |
| `000000025541` | `2026-08-17T14:47:16-04:00` | `by-file/SpecializedButtonPanes.md` | No error; owning file route revalidated after child registration. |
| `000000025542` | `2026-08-17T14:48:48-04:00` | `by-memory/0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData.md` | No error; target revalidated after same-UID path and child propagation. |
| `000000025543` | `2026-08-17T14:48:55-04:00` | `by-class/CheckBoxTextControlPane.md` | No error; owner revalidated after all children were registered. |
| `000000025544` | `2026-08-17T14:49:08-04:00` | `by-file/SpecializedButtonPanes.md` | No error; final owning-file revalidation. This became the dated generated snapshot command. |
| `000000025545` | `2026-08-17T14:49:21-04:00` | `by-memory/0x0059ded0-0x0059f0a5.CheckBoxTextControlPaneExecutableMap.md` | No error; executable map revalidated after all child registration. |
| `000000025548` | `2026-08-17T15:00:32-04:00` | `by-memory/0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland.md` | No warning/error; stale active UID0002DZ semantics/scores corrected, `ok:1`; validator updated three UID0000WT projected-stat rows and the projected path-completion section. |
| `000000025549` | `2026-08-17T15:00:49-04:00` | `by-memory/-ignored.md` | `ok:1`; 146 literal `missing_ref_uid` warnings were pre-existing in the aggregate (`0003J2`, `0003J3`, `0003BR`, `0003II`, `0003IJ`, `0003IK`, `0003WI`, `0003WJ`, `0003WK`, `0003WL`, plus 136 suppressed rows). Validator added the UID0003FJ reference index; UID0000VN stats were a no-op because the file is absent from generated stats lists; projected path completion refreshed. No error. |
| `000000025550` | `2026-08-17T15:01:04-04:00` | `by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md` | No warning/error; `ok:1`; UID0000WR stats were a no-op because the file is absent from generated stats lists; projected path completion refreshed. |
| `000000025551` | `2026-08-17T15:01:20-04:00` | `by-memory/0x004214d0-0x004214f7.FittingRoomEntryTailVectorRangeRelease.md` | No warning/error; `ok:1`; UID0002E0 stats were a no-op because the file is absent from generated stats lists; projected path completion refreshed. |

Dated callback generated readback after metadata reached command `000000025544` (`validator-refreshed-at: 2026-08-17T14:49:08-04:00`, `validator-refresh-source: deferred-generated-refresh`): `auto-generated/NexusTK/ui/controls/SpecializedButtonPanes.cpp` is SHA256 `9ECA830A38E11C90EEBA4C62D305C053CB120B2FE0C6737A343E7A19D70C6808`, 6,079 bytes / 171 physical lines; `.h` is SHA256 `CE2D6C37C4EE9039A2E0E1270E9B33F27DEA44949E53A2D5A224C73915F620BD`, 3,475 bytes / 104 physical lines. CPP has the accepted include root and exactly one constructor, destructor, OnPaint, SetChecked, GetChecked, and HitTestPart in positions 10/20/30/40/50/60. H has exactly one complete CheckBox declaration with terminal HitTestPart, both fields, and the size assertion. Across both files there is no UID0002OX empty marker, no stale `GetControlType`, no duplicate CheckBox definition/declaration, and no raw vtable/COL/RTTI body. All emitted identifiers are declared through UID000022, UID0000QU, UID0000TN, UID00004I, UID000038, and UID0000BU. This is a dated callback receipt; Gate 2A or later lifecycle work must reread dynamic generated authority.

## Changed Files

The ordinary destination inventory below preserves exact accepted post-validation identities; no ordinary page changed during this repair. Only this report was updated in place, and its final identity is supplied with the return because embedding its own hash would be self-referential. Manual coverage, generated/tracker, audit/catalog, goal/notes, canonical IDA, and lifecycle files were not edited. Disposable rollback-copy parser tests were unsaved and are not disk/lifecycle changes.

| Destination | Implemented sections | SHA256 | Bytes / physical lines |
| --- | --- | --- | ---: |
| `by-memory/0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData.md` | metadata, summary, compiler-data rationale, physical/RTTI/vtable/xref/source/history evidence, blank formals | `34274221A41BBA0AFA1EE812423C2C398112F75BFAEF51BF6AC507B8F4A56AE3` | 14,423 / 160 |
| `by-class/CheckBoxTextControlPane.md` | metadata, complete layout/source/compiler maps, formal H, blank CPP, history | `869AFADB25BBA7D23D4E0735135099F460C6D19441D7FA8C8F285C6C8533ADC1` | 24,410 / 164 |
| `by-class/GenderButtonControlPane.md` | shared formal CPP include root; all Gender source preserved | `E99531ADE1442ABDFFADC703634A35A63ABFA8AC82B11BD9E6B200A7A033AC89` | 24,334 / 188 |
| `by-file/SpecializedButtonPanes.md` | CheckBox route/order/dependencies/generated expectation/history/score | `565264BDFF959DFAA2B4C408BDABAF4D833CA2A3A0FB13DCF72470FBF0E2D65B` | 35,950 / 149 |
| `by-type/by-vtable/SpecializedButtonPaneVtables.md` | complete 25/11/2 CheckBox maps, RTTI/PMD/stores/source route/history | `472D7BAB3372D0F0BF51118870020308E368E8AF141B160295D273F9C8FDE3B6` | 23,047 / 210 |
| `by-type/by-struct/SpecializedButtonPaneLayouts.md` | complete 0x30c CheckBox layout, inherited facets, history, score | `68D2C30D206DA3A101863071C3E32D703D9D6E7D1121AD1D8CC44CCF0D284A35` | 20,917 / 128 |
| `by-memory/0x0059ded0-0x0059f0a5.CheckBoxTextControlPaneExecutableMap.md` | complete source/compiler child map, hashes, placement, history, score | `6A8EF8450D3EF2EC0750DEE7B597EE3E3EA87DD824C413B83179ED1AF580BAB1` | 14,263 / 111 |
| `by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneHitTestPart.md` | same-UID path/title correction, ABI, twelve xrefs, formal CPP, history, score | `DFE1E74C2EE0FB4C7D1911F8A3B0D7D7D4AFD627D7EDED89F703500EE9447A96` | 7,484 / 80 |
| `by-memory/0x0062e8fc-0x0062eccc.UserListReadOnlyData.md` | target child/source-cause/ownership/history and score; all other children preserved | `5EF70A3DAD2C536B2F3080807CF3CB416B58A9F863AEAB26BEB34550FEBDC4C5` | 24,520 / 164 |
| `by-memory/0x0059ded0-0x0059df27.CheckBoxTextControlPaneConstructorRaw.md` | source position 10, exact constructor formal CPP, ABI/hash/liveness/history, score | `A1C0916C543491C1935DB4023BE0852646A8C7A9EBCE0F752070A0F564D200C9` | 9,210 / 98 |
| `by-memory/0x0059df30-0x0059df4f.CheckBoxTextControlPaneTeardownHelper.md` | source position 20, exact destructor formal CPP, compiler-lowering/history, score | `B3FCFAADD3C29DA17CE87FBFDD5F6C0AA48151F45320F7D6376A90FDCCFB5EF6` | 5,623 / 80 |
| `by-memory/0x0059df50-0x0059e0ac.CheckBoxTextControlPaneOnPaint.md` | source position 30, complete OnPaint formal CPP, behavior/dependencies/hash/history, score | `5213EB819786064C5057E3CF14762BC3CD6592F58E8372C8C873C3856B69EBF9` | 8,911 / 126 |
| `by-memory/0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md` | source position 40, exact formal CPP preserved, no-invalidation/liveness/history, score | `F3058AF595E8701A15CFB6A7E0D9EE96CF7DD08704071E87CBDFD4BA37DAABAD` | 11,207 / 135 |
| `by-memory/0x0059e0c0-0x0059e0c7.CheckBoxTextControlPaneGetChecked.md` | source position 50, exact getter formal CPP, ABI/hash/history, score | `5DDE9B23BFED98A91C9EB3618AD4973D9412B9DAFDA75004E91E41EBE831D59C` | 6,101 / 89 |
| `by-memory/0x0059f050-0x0059f0a5.CheckBoxTextControlPaneScalarDeletingDestructor.md` | compiler-only false/non-emitting disposition, wrapper/thunk evidence, blank formals, score | `EA7C709A0E9E491353C1A5992D6E2FDEFC3F0C31D6AFF2174263FD09F8EA81F9` | 6,008 / 78 |
| `by-memory/0x00421310-0x004216cb.EarlySimpleUStringAndAdjacentHelperIsland.md` | validator-propagated UID0002DZ path plus corrected HitTestPart ABI/xrefs/history/current scores | `5BA64CC8DD1EBC0FF86FCFC56D22E6BEA2D2358735F8D2D47E1610F79ED01684` | 34,612 / 170 |
| `by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md` | validator-propagated UID0002DZ path link; reusable-helper ownership preserved | `51DD89972B4B890EA5CFA42985B8F7839695901106DAE7B1F49060D2A6E09DE8` | 73,532 / 257 |
| `by-memory/0x004214d0-0x004214f7.FittingRoomEntryTailVectorRangeRelease.md` | validator-propagated UID0002DZ preceding-boundary link; range/gap evidence preserved | `B4A86D15B1F0EA92289F31116269F65E987D440CF8B31DF30D6FDD9B46FB8904` | 20,235 / 184 |
| `by-memory/-ignored.md` | validator-propagated UID0002DZ owner-doc path plus verified complete CheckBox adjustor-thunk record | `8466B24C40C5C447119CD8283FFF2174FC2BB0F910C4076F2782D8FA25B207DE` | 1,144,783 / 5,484 |

The historical path `by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType.md` is absent after validator command `000000025513` moved same UID0002DZ to the corrected HitTestPart path. Verify-only ordinary evidence for C018/C044-C049/C051 was physically reread and remained unchanged. Every ordinary-file lease was released immediately after its edit/validator batch; the final lease report contains zero active B001 leases.

## Implementation Tracking Checklist

The following 75 rows mirror Section 11 exactly. Allocation is 55 checked / 20 unchecked: C001-C054 are applied or physically verified, C055-C074 remain proposed for their supervisor-owned actors, and C075 is mechanically verified.

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C001 | 0002OX | Exact target is `[0x0062e998,0x0062ea3c)`, 164 bytes, SHA256 `8BD30D00387434A481D86CF072EEECC7A964DF2519C042067A16AB0A87E9B3C7`. | Very high | Live MCP bytes/items plus independent SHA256 | UID0002OX range/evidence | incorporate | applied |
| [x] | C002 | 0002OX | Target contains exactly 41 four-byte data items: three COL pointers and `25/11/2` slots. | Very high | Complete item manifest | UID0002OX contents | incorporate | applied |
| [x] | C003 | 0002OX | RTTI proves one direct `ControlPane` base and inherited EventHandler/TimerHandler facets at `+0xa0/+0xa4`. | Very high | Three COLs, CHD, seven base descriptors/PMDs | UID0002OX inheritance | incorporate | applied |
| [x] | C004 | 0002OX | Primary table `[0x0062e99c,0x0062ea00)` has the exact 25-slot map in Section 14. | Very high | Live dwords/function lookups | UID0002OX primary map | incorporate | applied |
| [x] | C005 | 0002OX | Secondary table `[0x0062ea04,0x0062ea30)` has the exact 11-slot map in Section 14. | Very high | Live dwords/function lookups | UID0002OX secondary map | incorporate | applied |
| [x] | C006 | 0002OX | Tertiary table `[0x0062ea34,0x0062ea3c)` has the exact two-slot map in Section 14. | Very high | Live dwords/function lookups | UID0002OX tertiary map | incorporate | applied |
| [x] | C007 | 0002OX | Each table head has six exact data xrefs; all other target cells have zero inbound cell xrefs and no target cell has a code xref. | Very high | Complete xrefs-to query for all 41 cells | UID0002OX xrefs | incorporate | applied |
| [x] | C008 | 0002OX | `0x0062ea3c` is the PartySearch primary COL pointer and `0x0062ea40` its primary vtable base. | Very high | Live item/name/dword boundary | UID0002OX boundary | incorporate | applied |
| [x] | C009 | 0002OX | Change target to `94/96`, false/non-emitting, semantic owner 000022, empty emitter list, and blank formal CPP/H with compiler-output rationale. | Very high | Source-cause and ABI evidence | UID0002OX metadata/formals | incorporate | applied |
| [x] | C010 | 000022 | Exact class layout is `ControlPane` size `0x108`, `bool m_checked` at `+0x108`, natural pad at `+0x109`, `wchar_t m_label[256]` at `+0x10a`, total `0x30c`. | Very high | Constructor/paint/getter/allocation/RTTI | UID000022 layout | incorporate | applied |
| [x] | C011 | 0000NY | Canonical route remains `NexusTK/ui/controls/SpecializedButtonPanes.cpp/.h`; standalone CheckBox file remains lower-ranked historical alternative. | High | Existing owner graph and sibling route | UID0000NY placement | incorporate | applied |
| [x] | C012 | 0003FE | Raw constructor is retained source with signature `(bool,const wchar_t *,const RectBounds *)`, base type 8, checked store, bounded label copy, and exact vptr stores. | Very high | Exact 87 bytes and three live inline copies | UID0003FE behavior | incorporate | applied |
| [x] | C013 | 0003FF | `[0x0059df30,0x0059df4f)` is the ordinary empty destructor source route; vptr restoration/base call are compiler mechanics. | Very high | Decompile, stores, scalar-wrapper comparison | UID0003FF behavior | incorporate | applied |
| [x] | C014 | 0003FG | OnPaint loads `ON` frames 0/1, configures draw/text/font state, draws the label at x+28/x+29, and renders selected frame into `(4,3,24,23)` with `BU`. | Very high | Complete 348-byte decompile/disassembly | UID0003FG behavior | incorporate | applied |
| [x] | C015 | 0003FH | SetChecked performs only `m_checked = checked`; preserve exact existing formal CPP and no-invalidation evidence. | Very high | Exact 16-byte raw body | UID0003FH no-loss update | incorporate | applied |
| [x] | C016 | 0003FI | GetChecked is `bool GetChecked() const` and returns only `m_checked`. | Very high | Exact seven-byte modeled body | UID0003FI behavior/formal CPP | incorporate | applied |
| [x] | C017 | 0003FJ | Scalar deleting destructor is compiler output generated from the ordinary virtual destructor and emits no handwritten source. | Very high | Delete flags, base teardown, vtable/thunk refs | UID0003FJ disposition | incorporate | applied |
| [x] | C018 | 0000VN | Thunks `[0x0059efeb,0x0059eff6)` and `[0x0059eff6,0x0059f001)` adjust `this` by `0xa0/0xa4` into the scalar wrapper and remain compiler-only. | Very high | Exact bytes, jumps, vtable xrefs | ignored thunk record | already-present | already-present |
| [x] | C019 | 0002DZ | Historical `GetControlType()` is invalid; source ABI is `unsigned char HitTestPart(int,int)` returning 22. | Very high | `AL` return, `retn 8`, base terminal slot parity | UID0002DZ identity/history | historicalize | applied |
| [x] | C020 | 0002DZ | Physical body has twelve exact primary-vtable xrefs and must be documented as linker-folded shared ControlPane-family code, not assigned a CheckBox-specific IDA name. | Very high | Complete live xref/table-base map | UID0002DZ shared evidence | incorporate | applied |
| [x] | C021 | 000022 | Replace CPP-hosted class declaration with the complete formal H declaration in Section 22. | Very high | Generated defect and layout closure | UID000022 formal H | incorporate | applied |
| [x] | C022 | 00005P | Extend the shared CPP root dependencies for wide copy, ImageLib, Surface callbacks, and `IsLegacyAssetMode`; preserve all Gender/Direction content. | High | Compile-closure audit | UID00005P formal CPP preamble | incorporate | applied |
| [x] | C023 | 0003FE | Populate exact constructor formal CPP from Section 22. | Very high | Constructor bytes/ABI | UID0003FE formal CPP | incorporate | applied |
| [x] | C024 | 0003FF | Populate exact empty destructor formal CPP from Section 22. | Very high | Ordinary/scalar destructor split | UID0003FF formal CPP | incorporate | applied |
| [x] | C025 | 0003FG | Populate complete OnPaint formal CPP from Section 22. | High | Complete behavior and dependency map | UID0003FG formal CPP | incorporate | applied |
| [x] | C026 | 0003FH | Preserve the existing exact SetChecked formal CPP. | Very high | Exact raw body | UID0003FH formal CPP | already-present | already-present |
| [x] | C027 | 0003FI | Populate exact GetChecked formal CPP from Section 22. | Very high | Exact modeled body | UID0003FI formal CPP | incorporate | applied |
| [x] | C028 | 0002DZ | Replace wrong formal CPP with exact HitTestPart formal CPP from Section 22. | Very high | ABI and slot parity | UID0002DZ formal CPP | incorporate | applied |
| [x] | C029 | 0000NY | Source order is class H then constructor, destructor, paint, setter, getter, HitTestPart; compiler vtable/scalar/thunks emit nowhere. | High | Address/source dependency order | UID0000NY child order | incorporate | applied |
| [x] | C030 | 0002OX | Target score changes `86/92 -> 94/96`. | High | Complete target closure | UID0002OX score | incorporate | applied |
| [x] | C031 | 000022 | Owner score changes `90/92 -> 95/96`. | High | Complete declaration/method/layout closure | UID000022 score | incorporate | applied |
| [x] | C032 | 0000NY | File score changes `92/94 -> 94/95`; filename uncertainty remains the confidence cap. | High | Complete CheckBox route | UID0000NY score | incorporate | applied |
| [x] | C033 | 0001YW | Keep `94/96` false/non-emitting but replace stale CheckBox `+0x68` claim with complete `25/11/2` map. | Very high | Live table endpoints/slots | UID0001YW CheckBox section | incorporate | applied |
| [x] | C034 | 0001KJ | Raise `88/89 -> 92/94` and complete the exact source/compiler child map without making the mixed span emit. | High | Exact child closure | UID0001KJ map/score | incorporate | applied |
| [x] | C035 | 0002DZ | Rename the same-UID page/title to CheckBoxTextControlPaneHitTestPart, raise `91/94 -> 94/96`, preserve owner/emitter 000022 and reconstructable true. | High | Shared-body/source projection evidence | UID0002DZ path/metadata | incorporate | applied |
| [x] | C036 | 00026U | Raise `88/92 -> 92/95` and replace stale reconstructable target wording with exact false/non-emitting child/source-cause detail. | High | Complete child audit | UID00026U map/score | incorporate | applied |
| [x] | C037 | 0003FE | Raise constructor `85/88 -> 93/95`; raw/no-xref status remains explicit. | High | Exact body plus three inlines | UID0003FE score | incorporate | applied |
| [x] | C038 | 0003FF | Raise ordinary destructor `86/90 -> 93/95`. | Very high | Complete destructor split | UID0003FF score | incorporate | applied |
| [x] | C039 | 0003FG | Raise OnPaint `87/91 -> 93/95`. | High | Complete body/dependencies | UID0003FG score | incorporate | applied |
| [x] | C040 | 0003FH | Raise setter `87/88 -> 92/94`; preserve no-xref cap. | High | Exact raw body/source route | UID0003FH score | incorporate | applied |
| [x] | C041 | 0003FI | Raise getter `86/88 -> 92/94`; preserve no-xref cap. | High | Exact body/source route | UID0003FI score | incorporate | applied |
| [x] | C042 | 0003FJ | Raise `87/91 -> 93/95`, change to false/non-emitting, preserve semantic owner 000022, blank formals. | Very high | Compiler scalar-wrapper proof | UID0003FJ metadata/score | incorporate | applied |
| [x] | C043 | 0001W7 | Raise `93/95 -> 95/97` and add exact CheckBox direct-base/field/size/facet layout. | Very high | RTTI, fields, allocation | UID0001W7 CheckBox layout | incorporate | applied |
| [x] | C044 | 0000QU | `g_pEPFLib` remains shared ImageLib ownership; CheckBox consumes but does not own it. | Very high | OnPaint reads and existing owner route | UID0000QU no-change | already-present | already-present |
| [x] | C045 | 0000TN | `g_pfnFillRect` remains shared Surface ownership with exact two-argument thiscall ABI. | Very high | Indirect call at `0x0059dfb0` and callback physical formal-H reread | UID0000TN no-change | already-present | already-present |
| [x] | C046 | 00004I | EPFTileContext remains a shared by-value dependency; CheckBox locals do not transfer ownership. | Very high | Two 0x28-byte locals and callback physical type reread | UID00004I no-change | already-present | already-present |
| [x] | C047 | 000038 | Preserve direct `ControlPane` inheritance and terminal `HitTestPart(int,int)` contract; no base edit is required. | Very high | RTTI and callback physical formal-H reread | UID000038 no-change | already-present | already-present |
| [x] | C048 | 0000BU | RectBounds remains the exact 16-byte bounds dependency and `InitRectBounds` owner. | Very high | OnPaint/constructor and callback physical H reread | UID0000BU no-change | already-present | already-present |
| [x] | C049 | 0000VN | Existing CheckBox adjustor-thunk ignored record is complete and needs no ordinary edit. | Very high | Callback physical record plus live MCP recheck | by-memory/-ignored.md no-change | already-present | already-present |
| [x] | C050 | 00026U | Keep the mixed parent false/non-emitting and ownerless; physical interleave does not transfer CheckBox source to UserList. | Very high | Exact child boundaries/owners | UID00026U ownership | incorporate | applied |
| [x] | C051 | 0003E7 | PartySearch successor remains unchanged; only its boundary is cited. | Very high | Live successor items plus callback physical page reread | UID0003E7 no-change | already-present | already-present |
| [x] | C052 | 0000NY | Dated callback generated readback proves one CheckBox H declaration, six semantic definitions, correct order, no UID0002OX marker, no stale GetControlType, and no raw vtable body. | Very high | Formal route and dated defect | Generated readback | incorporate | applied |
| [x] | C053 | 0002OX | Implementation callback ran serial scoped validators for every changed ordinary page and recorded exact dated receipts. | Very high | Project workflow | Validator plan | incorporate | applied |
| [x] | C054 | 0000NY | Implementation callback physically reread generated CPP/H after validator metadata reached command `000000025544`. | Very high | Generated authority rule | Generated verification | incorporate | applied |
| [ ] | C055 | 0002OX | Supervisor replaces the exact target manual by-memory coverage row with the Section 28 payload. | High | Dated pre-callback row and complete closure | by-memory/-coverage-report.md | incorporate | proposed |
| [ ] | C056 | 000022 | Supervisor replaces exact owner and file coverage rows with Section 28 payloads. | High | Dated pre-callback rows and source closure | by-class/by-file coverage | incorporate | proposed |
| [ ] | C057 | 0001YW | Supervisor replaces exact vtable/layout coverage rows with Section 28 payloads. | High | Dated pre-callback incomplete CheckBox rows | by-type coverage | incorporate | proposed |
| [ ] | C058 | 0001KJ | Supervisor replaces/inserts the exact executable-map, child, UID0002DZ, and aggregate coverage rows in Section 28. | High | Dated pre-callback stale/missing rows | by-memory coverage | incorporate | proposed |
| [ ] | C059 | 0002DZ | I01 applies the exact shared-body regular address comment at `0x004214c0`. | Very high | Twelve-vtable ABI proof | Section 21 I01 | incorporate | proposed |
| [ ] | C060 | 0003FE | I02 applies the exact raw-constructor regular address comment at `0x0059ded0`. | High | Exact raw body/inlines | Section 21 I02 | incorporate | proposed |
| [ ] | C061 | 0003FH | I03 applies the exact raw-setter regular address comment at `0x0059e0b0`. | High | Exact raw body/field users | Section 21 I03 | incorporate | proposed |
| [ ] | C062 | 0003FF | I04 pure-renames `sub_59DF30` to `CheckBoxTextControlPane__Destructor`. | Very high | Destructor behavior/collision absence | Section 21 I04 | incorporate | proposed |
| [ ] | C063 | 0003FF | I05 uses parser-accepted `void __thiscall CheckBoxTextControlPane__Destructor(class CheckBoxTextControlPane *this)` and expects normalized `void __thiscall(struct CheckBoxTextControlPane *this)` while preserving the sole frame row, all comment channels, range/hash, and xrefs. | Very high | Public `set_type` success plus complete disposable poststate | Section 21 I05 | incorporate | proposed |
| [ ] | C064 | 0003FG | I06 pure-renames `sub_59DF50` to `CheckBoxTextControlPane__OnPaint`. | Very high | Primary slot/body/collision absence | Section 21 I06 | incorporate | proposed |
| [ ] | C065 | 0003FG | I07 uses parser-accepted `void __thiscall CheckBoxTextControlPane__OnPaint(class CheckBoxTextControlPane *this)` and expects normalized `void __thiscall(struct CheckBoxTextControlPane *this)` while preserving all seven frame rows, all comment channels, range/hash, and xrefs. | Very high | Public `set_type` success plus complete disposable poststate | Section 21 I07 | incorporate | proposed |
| [ ] | C066 | 0003FI | I08 pure-renames `sub_59E0C0` to `CheckBoxTextControlPane__GetChecked`. | Very high | Getter body/collision absence | Section 21 I08 | incorporate | proposed |
| [ ] | C067 | 0003FI | I09 uses parser-accepted `bool __thiscall CheckBoxTextControlPane__GetChecked(const class CheckBoxTextControlPane *this)` and expects normalized `bool __thiscall(const struct CheckBoxTextControlPane *this)` while preserving the sole frame row, all comment channels, range/hash, and xrefs. | Very high | Public `set_type` success plus complete disposable poststate | Section 21 I09 | incorporate | proposed |
| [ ] | C068 | 0002OX | I10 applies the exact primary-COL regular address comment at `0x0062e998`. | Very high | Table/RTTI map | Section 21 I10 | incorporate | proposed |
| [ ] | C069 | 0002OX | I11 applies the exact EventHandler-COL regular address comment at `0x0062ea00`. | Very high | Table/RTTI map | Section 21 I11 | incorporate | proposed |
| [ ] | C070 | 0002OX | I12 applies the exact TimerHandler-COL regular address comment at `0x0062ea30`. | Very high | Table/RTTI map | Section 21 I12 | incorporate | proposed |
| [ ] | C071 | 0003FJ | P01 protects scalar deleting destructor name/type/frame/comments/range/hash/xrefs as no-change. | Very high | Live complete prestate | Section 21 P01 | already-present | proposed |
| [ ] | C072 | 0000VN | P02/P03 protect both adjustor thunks, including exact AR `Block`, as no-change. | Very high | Live complete prestates | Section 21 P02/P03 | already-present | proposed |
| [ ] | C073 | 0002OX | P04 supplies literal manifest rows M01-M41 with each four-byte range, entity kind, name, type, dword/semantic target, four comment channels, complete inbound/outbound xrefs, permitted delta, and expected post-readback; only M01, M27, and M39 permit exact AR changes. | Very high | Literal 41-cell target manifest | Section 21 P04 | already-present | proposed |
| [ ] | C074 | 0002OX | Gate 2B must execute I01-I12 in order; I05/I07/I09 use the explicit-`class` requests and normalized displays proven by dated rollback-copy tests; I10-I12 bind literal M01/M27/M39 states; any mismatch hard-stops without further mutation/save; final reread proves only three names, three declarations, and six AR comments changed. | Very high | Deterministic transaction contract plus public parser tests | Section 21 final readback | incorporate | proposed |
| [x] | C075 | 0002OX | Report has 33 exact headings, 75/75 twin parity, seven formal CPP blocks, one formal H block, zero executable-language fences, lifecycle-neutral post-callback prose, one terminal READY_FOR_SUPERVISOR_EXECUTE marker, and dated implementation/parser-test receipts. | Very high | Mechanical report audit | Report artifact | already-present | already-present |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000025646","destination_path":"executed-b-agent-research/B001/0002OX-CheckBoxTextControlPaneVtableData-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0002OX-CheckBoxTextControlPaneVtableData-empty-emitter-source-quality.md","timestamp":"2026-08-17T17:23:49-04:00","uid":"0002OX"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
