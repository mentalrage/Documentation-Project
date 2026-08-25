
# UID0000NN SelfSaveOKPane File Source Quality Report
** TARGET-REPORT-UID:0000NN **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

## Finalized Report / Current Recommendation

- Report state: accepted ordinary-document implementation callback complete. Claims C0000NN-001..020 and C0000NN-028..040 were applied or physically verified; supervisor-owned manual coverage C0000NN-021..027 and IDA I0000NN-001..008 remain proposed and unchecked. Report lifecycle state remains supervisor-owned.
- Agent provenance: `B007 | CHATGPT | 5.6 | xHigh`.
- Assignment authority: `tools/leaser/Agents/Agent-B007/goal.md`, SHA256 `DD8A0C0F88E4A772309E04C6FFB7E856A322BE8BD046D9320FEFCC2963E4ED12` when accepted for this report.
- Primary target: [UID:0000NN] `by-file/SelfSaveOKPane.md`.
- Recommended source route: retain `NexusTK/ui/dialogs/SelfSaveOKPane.cpp` and the existing `SelfSaveOKPane.h`; retain `CANONICAL_OWNER:FILE` for UID0000NN.
- Whole-file source conclusion: `SelfSaveOKPane.cpp` owns one retained file-local factory, the class constructor, the sole source-authored virtual override, and use-site spelling of one pooled spacer literal. The three vtable facets and their physical RTTI/vtable bytes are compiler products covered by the class declaration. MapPane opcode `0x21` owns its own inline duplicate construction bytes and consumes the same class; those bytes do not move into SelfSaveOKPane.cpp.
- Current score: UID0000NN is `94/94`. The route is source-ready and no reasonable current whole-file blocker remains. The remaining cap records the absent original factory registration route/spelling and unavoidable inference in local variable names, not missing research.
- Formal source disposition: ordinary docs now contain the exact `InsertText`/semantic-global source, the complete class header, and covered-by markers for all three compiler/data emitters. Waited generated readback confirms those channels assemble without an empty emitter.
- Gate state: 33 ordinary/validation/generated claims are checked `applied_verified`; seven manual-coverage and eight IDA claims remain proposed/unchecked. Exactly one terminal workflow marker is present for fresh supervisor Gate 2A; it does not assert execution or archival.

## Supporting Research

At the report-only baseline, documentation identified the correct family but stopped short of complete source-quality closure: [UID:0001YV], [UID:0002OU], and [UID:0003JL] had blank formal C++, and the constructor projected stale `SetText`/array-index syntax. The accepted callback has repaired those exact defects without discarding the baseline evidence: all three compiler/data children now carry explicit covered-by markers, and current ordinary source uses `InsertText` plus `g_mainUiLayerSlots.rootPaneLayerContext`.

This pass rechecked the full file family rather than sampling one function. It covered the standalone factory, constructor, timer facet, MapPane inline duplicate, three vtable/COL views, pooled UTF-16 literal, exact padding, adjacent functions/data, generated CPP/H, provider headers, manual coverage, current support docs, and matching archived reports as leads. It also resolved the factory's formerly vague successor boundary: `[0x00513920,0x005139a4)` is an unrelated raw opcode-`0x45` packet sender; `[0x005139b0,0x00513a1a)` is an unrelated UI active-tab/sound helper; their padding and the next modeled function at `0x00513a20` are not SelfSaveOKPane source.

The project objective is behavioral identity with the unsupported original executable and a source tree that resembles plausible mid-2000s developer C++, not decompiler output. The proposed source preserves allocation, construction, text insertion order, localized string id, rectangle, layer route, timer schedule, self-removal, and deletion exactly while replacing raw symbols and guessed array indexing with the best-supported project-wide source names.

## Target

- [UID:0000NN] `by-file/SelfSaveOKPane.md`.
- Current metadata: `COMPLETION:94`, `CONFIDENCE:94`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`, `CANONICAL_OWNER:FILE`.
- Current direct source children:
  - [UID:0000CX] `by-class/SelfSaveOKPane.md`, current `94/95`, file child at position `1`.
  - [UID:0001AY] `by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md`, current `93/92`, direct file emitter.
  - [UID:0001B0] `by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md`, current `94/95`, direct file emitter.
- Current class-owned compiler/data children:
  - [UID:0001YV] `by-type/by-vtable/SelfSaveOKPane_vtables.md`, current `94/95`.
  - [UID:0002OU] `by-memory/0x0061e7a0-0x0061e854.SelfSaveOKPaneVtableData.md`, current `94/95`.
  - [UID:0003JL] `by-memory/0x0061ea8c-0x0061eaa8.SelfSaveOKPaneSpacerString.md`, current `94/95`.
- Related non-owned consumer: [UID:0000L3] `by-file/MapPane.md`, whose packet handler contains the inline opcode-`0x21` duplicate.
- Expected generated products: `auto-generated/NexusTK/ui/dialogs/SelfSaveOKPane.cpp` and `SelfSaveOKPane.h`.

## Current Target State

- The by-file page now carries the complete whole-file inventory, exact source order, source/compiler boundaries, provider ownership, rejected alternatives, generated contract, and `94/94` rationale.
- The class page retains the complete compile-visible `SelfSaveOKPane.h`: one `TextBoxPane` base, constructor, protected `OnTimer` override, no added fields, and a `0x174` size assertion. Its formal CPP now owns the exact four-include provider prologue and child route.
- The factory formal body now uses `new SelfSaveOKPane;` followed by `return true`, with exact function bounds, frame/hash evidence, duplicate relation, and unrelated successor exclusions recorded.
- The constructor/timer formal body now uses `TextEditPane::InsertText(const wchar_t *, int)` and `g_mainUiLayerSlots.rootPaneLayerContext`; it preserves insertion order, bounds, layer route, timer schedule, facet lowering, self-removal, and deletion behavior.
- The vtable group, physical vtable page, and spacer page now emit narrow comment-only covered-by markers rather than raw arrays. Their exact facets/bytes/xrefs/literal/alignment evidence is retained at report-level detail.
- Dated generated snapshot on `2026-08-17`: `SelfSaveOKPane.cpp` SHA256 `4AC799BBE1F73217154982E1A3F190E65E699677BA403C0BAAB8204DA27C7A7D`, 1,762 bytes, 53 physical lines; `SelfSaveOKPane.h` SHA256 `D9A5809DE9D689F9BD50CFF2C693316884FCA1303345DD23AE797292DC0A4CC8`, 754 bytes, 25 physical lines. This snapshot contains the class include, factory, constructor/timer, and empty emitter markers; it is dated evidence, not permanent gate authority.
- Post-callback generated snapshot after waited command `000000025534` and deferred-queue stabilization: `SelfSaveOKPane.cpp` SHA256 `687FCD2FDD63D339DE96915C146F99D4C9D75C414C71E41872DB3AD63A211B39`, 2,198 bytes, 61 physical lines; `SelfSaveOKPane.h` SHA256 `F5319A29E9870076BD52745289B4D7CC4C8A24C2E184AD5DA4AE5AF7C9337643`, 752 bytes, 25 physical lines. The generated headers cite deferred-refresh command `000000025532`; these identities are dated callback readbacks, not permanent authority.

## Executive Recommendation

1. Retain the implemented source/header pair under `NexusTK/ui/dialogs/` and the existing class/file owner route.
2. Accept the implemented file/child scores and exact human-written factory, constructor, and timer source after independent Gate 2A comparison.
3. Accept the implemented compiler-vtable, physical-vtable, and pooled-literal covered-by markers; generated readback contains all three and no empty emitter.
4. Accept MapPane's clarified inline-byte ownership while preserving reusable SelfSaveOKPane class/method ownership.
5. Supervisor freshly rereads and applies C0000NN-021..027 manual coverage text, including the UID0003IV anchor requirement; B007 did not edit coverage.
6. Supervisor performs the structured I0000NN-001..008 IDA plan only after fresh attestation and literal prestate verification. No IDA action is needed to justify the implemented formal source itself.

## Supervisor Active Recheck

- Fresh live `idb_list`, `runtime_attestation`, and `server_health` on `2026-08-17T16:17:32Z` confirmed active canonical session `supervisor_uid0000n5_persistverify_20260817`, canonical IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker port `65423`, module `NexusTK.exe`, image base `0x00400000`, Hex-Rays ready, and status `ok`.
- `auto_analysis_ready:false` is the expected saved-database state; bounded lookup, item, bytes, xref, frame, and decompile queries all succeeded. No mutation was attempted.
- The dated canonical IDB snapshot used by this report was SHA256 `96C943501D1A88D1E3CB67E634B7B568D3562FF6ECC6487C08C1CF574DEB2575`, 143,209,580 bytes. Both checked input executable copies were 2,679,296 bytes with SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- Future Gate 2B must re-attest and reread all mutable IDA state; this dated session/hash is evidence, not permanent authority.

## Inference Research Guidance Check

- Wave2/Wave3 material was ignored as instructed.
- Raw names `sub_513800`, `sub_5147D0`, `sub_5148E0`, `asc_61EA8C`, and blank COL-cell names were treated as analysis labels, not final source spellings.
- The source names were selected from current behavior, class/header conventions, current provider docs, neighboring file patterns, and binary lowering. No raw IDA symbol appears in final source.
- Zero direct callers to the factory and constructor were investigated rather than used as a stopping excuse. Exact construction equivalence, vtable stores, support calls, boundaries, and file grouping establish their source roles; the absent factory registration route only caps confidence in the original helper spelling.
- Compiler-generated vtables/RTTI and pooled literal storage were investigated and receive explicit no-standalone-source dispositions rather than being ignored.
- The class has no inferred data members because vtable equivalence, constructor allocation size, and base layout all support a fieldless derived type. Adding speculative fields would reduce fidelity.

## Heuristic / Inference Reanalysis And Validation

### Factory source shape

The standalone `0x00513800` body allocates exactly `0x174`, invokes the same TextBoxPane construction and three facet stores as the named constructor and MapPane duplicate, performs the same text/layer/timer setup, ignores its one stack argument, and returns true even if allocation returns null. A file-local `static bool __stdcall CreateSelfSaveOKPane(int unusedPacket)` is the highest-probability source shape. The callback name remains inferred, but the current project name is concise, human-readable, and behavior-specific. The body must not be folded into the class constructor because it contains the allocation/callback return contract.

### Constructor and timer source shape

The exact constructor duplicates the post-allocation portion of the factory. Current TextEditPane documentation resolves the three `sub_58E270` calls as `InsertText(text, 0)`, not a four-argument `SetText`. Current MainUiGraph documentation resolves the layer argument as `g_mainUiLayerSlots.rootPaneLayerContext`. The timer function is reached from only the timer-facet vtable slot. Its machine receiver is the TimerHandler facet, so the body subtracts `0xa4` before calling the primary `RemoveFromLayer` slot and scalar deletion. Source-level multiple-inheritance lowering is simply `SelfSaveOKPane::OnTimer`; it should not expose the adjustment.

### Vtables and layout

The primary, secondary, and timer vtable target sequences match `TextBoxPane` exactly except for the timer facet's second slot, which points to `0x005148e0` rather than the inherited TextBoxPane timer handler. This proves one source-authored override and no other override. The three constructor-store groups assign the same facet bases at the expected subobject offsets. The `0x174` allocation and current base size agree, so no derived fields are supported.

### Literal source shape

The 12-space UTF-16 payload has six true use-site xrefs: two in MapPane, two in the factory, and two in the constructor. Human source most plausibly used `L"            "` at each construction sequence or a local pointer to that literal; compiler pooling explains one physical object. A raw exported array would falsely elevate compiler pooling into source architecture. The formal code therefore uses a local `padding` pointer and the data page emits only a covered-by marker.

### Source placement

The source path `ui/dialogs/SelfSaveOKPane.cpp` is supported by the class role, current header, sibling dialog organization, and complete child family. The inline MapPane packet consumer remains in MapPane.cpp because it is embedded in the packet switch and has no call to the standalone helper. The factory remains local to SelfSaveOKPane.cpp because it constructs no other type and shares its entire behavior with this family.

## Evidence Standards Used

- Positive evidence: exact bytes and SHA256, modeled function boundaries, full stack frames, vtable/COL items, vtable slot equality, construction stores, direct xrefs, decompilation, disassembly, literals, support-doc formal declarations, generated output, and current manual coverage.
- Negative evidence: zero external direct factory/constructor xrefs, no original source symbols, no extra derived fields, no additional SelfSaveOKPane-owned function between exact boundaries, no reusable declaration outside the existing header, and no reason to emit raw vtable/literal arrays.
- Inference is explicitly labeled. It selects a source spelling/shape only after exact runtime behavior and ownership are fixed.
- Archived B-agent reports were used as dated leads and independently rechecked against current docs and live MCP before adoption.
- Mutable generated/coverage hashes are dated snapshots only. Fresh supervisor gates must reread current files.

## Evidence Checked

- Primary/support docs: UID0000NN, UID0000CX, UID0001AY, UID0001B0, UID0001YV, UID0002OU, UID0003JL, UID0000L3 MapPane, UID0000EI TextBoxPane, UID0000ON TextEditPane, TimerHandler support, `g_pLanguageMan`, `g_pBackPane`, and `MainUiLayerSlots`.
- Current generated `SelfSaveOKPane.cpp/.h` and required provider headers `LanguageMan.h`, `BackPane.h`, and `MainUiGraph.h`.
- Current manual coverage rows and omissions in by-file, by-class, by-memory, and by-type/by-vtable reports.
- Dated leads: central executed reports for UID0001AY and UID0001B0 plus current target history. All conclusions were revalidated.
- Live read-only MCP endpoints: `idb_list`, `runtime_attestation`, `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `inspect_items`, `get_bytes`, `get_comments`, `stack_frame`, `xref_query`, and `type_query`.
- Search terms included `0000NN`, `0000CX`, `0001AY`, `0001B0`, `0001YV`, `0002OU`, `0003JL`, `SelfSaveOKPane`, `sub_513800`, `sub_5147D0`, `sub_5148E0`, `asc_61EA8C`, `0x61e7a4`, and `opcode 0x21`.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C0000NN-001 | 0000NN | Whole-file inventory is one local factory, constructor, timer override, three compiler vtable facets, one pooled spacer literal, and one MapPane-owned inline duplicate. | high | Live ranges, vtable stores, xrefs, and complete support inventory. | by-file/SelfSaveOKPane.md / Proposed Contents | incorporate | applied_verified |
| C0000NN-002 | 0000NN | Raise file metadata to 94/94 while retaining path NexusTK/ui/dialogs/ and owner FILE. | high | Exhaustive source and boundary closure. | by-file/SelfSaveOKPane.md / metadata and Status | incorporate | applied_verified |
| C0000NN-003 | 0000CX | Raise class metadata to 94/95 and preserve owner/emitter 0000NN and position 1. | high | Exact fieldless layout and sole override proof. | by-class/SelfSaveOKPane.md / metadata and Status | incorporate | applied_verified |
| C0000NN-004 | 0000CX | Preserve the complete existing SelfSaveOKPane H declaration and include route exactly. | high | Base declaration, vtable comparison, allocation size, and generated H. | by-class/SelfSaveOKPane.md / formal H | already-present | applied_verified |
| C0000NN-005 | 0000CX | Replace class CPP prologue with the exact four provider includes and children route below. | high | Formal source dependencies and generated provider headers. | by-class/SelfSaveOKPane.md / formal CPP | incorporate | applied_verified |
| C0000NN-006 | 0001AY | Raise factory metadata to 93/92 and retain owner/emitter 0000NN. | high | Exact body and source route; original registration/name remains inferred. | UID0001AY metadata | incorporate | applied_verified |
| C0000NN-007 | 0001AY | Replace factory formal CPP with the exact allocation callback below. | high | Exact 0x120 body and duplicated construction behavior. | UID0001AY formal CPP | incorporate | applied_verified |
| C0000NN-008 | 0001AY | Record unrelated successor functions and exact boundary so they are excluded from SelfSaveOKPane. | high | Bounded disassembly through 0x00513a20 and padding. | UID0001AY range/history | incorporate | applied_verified |
| C0000NN-009 | 0001B0 | Raise constructor/timer metadata to 94/95 and retain owner/emitter 0000NN. | high | Exact two-function island and source-ready semantics. | UID0001B0 metadata | incorporate | applied_verified |
| C0000NN-010 | 0001B0 | Replace stale SetText calls with exact InsertText calls and preserve the three-text insertion order. | high | Current TextEditPane helper closure and exact call sequence. | UID0001B0 formal CPP and behavior | incorporate | applied_verified |
| C0000NN-011 | 0001B0 | Replace g_mainUiLayerSlots[1] with rootPaneLayerContext and preserve all rectangle/layer arguments. | high | Semantic global layout and exact operand address. | UID0001B0 formal CPP and dependencies | incorporate | applied_verified |
| C0000NN-012 | 0001B0 | Emit OnTimer as source-level multiple-inheritance C++ with removal and self-delete only for timer id zero. | high | Sole timer-vtable route and exact facet adjustment lowering. | UID0001B0 formal CPP and behavior | incorporate | applied_verified |
| C0000NN-013 | 0001YV | Raise vtable-group metadata to 94/95 and replace blank CPP with the covered-by marker below. | high | Complete three-facet comparison and compiler-generation proof. | UID0001YV metadata and formal CPP | incorporate | applied_verified |
| C0000NN-014 | 0002OU | Raise physical vtable-data metadata to 94/95 and replace blank CPP with the covered-by marker below. | high | Exact 180-byte region, COL cells, slots, and construction refs. | UID0002OU metadata and formal CPP | incorporate | applied_verified |
| C0000NN-015 | 0003JL | Raise spacer metadata to 94/95, fill Item Summary, and replace blank CPP with the pooled-literal covered-by marker below. | high | Exact 28-byte range and six use-site refs. | UID0003JL metadata, Item Summary, formal CPP | incorporate | applied_verified |
| C0000NN-016 | 0000L3 | Clarify that opcode 0x21 owns an inline duplicate in MapPane.cpp while the reusable class/method source remains SelfSaveOKPane-owned. | high | Exact 222-byte inline block and no helper call. | by-file/MapPane.md / SelfSave evidence | incorporate | applied_verified |
| C0000NN-017 | 0000NN | Preserve rejected SpelledPane, TextBoxPane, MapPane-child-class, raw-vtable-array, raw-literal-array, and aggregate-owner theories as superseded history. | high | Current owner graph and exact source-shape evidence. | target/support historical assumptions | historicalize | applied_verified |
| C0000NN-018 | 0000NN | Generated CPP must contain provider includes, factory, constructor, timer, and three no-code markers with no empty emitter. | high | Post-C038 physical generated CPP readback. | generated readback after callback | incorporate | applied_verified |
| C0000NN-019 | 0000NN | Generated H must remain the complete current 0x174 fieldless class declaration. | high | Current valid formal H and physical generated H. | generated readback after callback | already-present | applied_verified |
| C0000NN-020 | 0000NN | Do not create another header, split the file, or use a third-party import directive. | high | Existing complete provider and custom game source. | by-file/SelfSaveOKPane.md / Source Placement | already-present | applied_verified |
| C0000NN-021 | 0000NN | Replace the manual by-file coverage row with the exact 94 percent row below. | high | Dated current row at line 251. | by-file/-coverage-report.md | incorporate | proposed |
| C0000NN-022 | 0000CX | Replace the manual by-class coverage row with the exact 94 percent row below. | high | Dated current row at line 491. | by-class/-coverage-report.md | incorporate | proposed |
| C0000NN-023 | 0001AY | Replace the manual by-memory factory row with the exact 93 percent row below. | high | Dated current row at line 2640. | by-memory/-coverage-report.md | incorporate | proposed |
| C0000NN-024 | 0001B0 | Replace the manual by-memory constructor/timer row with the exact 94 percent row below. | high | Dated current row at line 2642. | by-memory/-coverage-report.md | incorporate | proposed |
| C0000NN-025 | 0001YV | Replace the manual by-vtable row with the exact 94 percent row below. | high | Dated current row at line 123. | by-type/by-vtable/-coverage-report.md | incorporate | proposed |
| C0000NN-026 | 0002OU | Replace the manual by-memory vtable-data row with the exact 94 percent row below. | high | Dated current row at line 4650. | by-memory/-coverage-report.md | incorporate | proposed |
| C0000NN-027 | 0003JL | Insert the exact 94 percent spacer row immediately after UID0003IV and before UID00025T, nested beneath UID00025S. | high | The dated 2026-08-17 read-only by-memory snapshot places UID0003IV at `0x0061e964-0x0061e9fc` beneath UID00025S and the next row UID00025T at `0x0061eb08-0x0061ec10`; UID0003JL `0x0061ea8c-0x0061eaa8` belongs between those literal existing anchors. | by-memory/-coverage-report.md / after UID0003IV and before UID00025T | incorporate | proposed |
| C0000NN-028 | 0000NN | Incorporate all behavior, interactions, boundaries, negative evidence, and support dependencies without summary loss. | high | Rule 26 no-loss standard and complete report evidence. | all named ordinary docs | incorporate | applied_verified |
| C0000NN-029 | 0000NN | Run `python .\tools\validator.py --mode file --file by-file/SelfSaveOKPane.md --apply --queue-timeout 240`. | high | Literal scoped validator command for the primary file page. | by-file/SelfSaveOKPane.md / validator receipt | validate | applied_verified |
| C0000NN-030 | 0000NN | Keep g_pLanguageMan, g_pBackPane, MainUiLayerSlots, InsertText, AddToLayer, RemoveFromLayer, and ScheduleTimer in their existing source owners. | high | Current formal provider docs and exact call targets. | target dependency evidence | already-present | applied_verified |
| C0000NN-031 | 0000CX | Run `python .\tools\validator.py --mode file --file by-class/SelfSaveOKPane.md --apply --queue-timeout 240`. | high | Literal scoped validator command for the class page. | by-class/SelfSaveOKPane.md / validator receipt | validate | applied_verified |
| C0000NN-032 | 0001AY | Run `python .\tools\validator.py --mode file --file by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md --apply --queue-timeout 240`. | high | Literal scoped validator command for the factory page. | UID0001AY / validator receipt | validate | applied_verified |
| C0000NN-033 | 0001B0 | Run `python .\tools\validator.py --mode file --file by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md --apply --queue-timeout 240`. | high | Literal scoped validator command for the constructor/timer page. | UID0001B0 / validator receipt | validate | applied_verified |
| C0000NN-034 | 0001YV | Run `python .\tools\validator.py --mode file --file by-type/by-vtable/SelfSaveOKPane_vtables.md --apply --queue-timeout 240`. | high | Literal scoped validator command for the vtable-type page. | UID0001YV / validator receipt | validate | applied_verified |
| C0000NN-035 | 0002OU | Run `python .\tools\validator.py --mode file --file by-memory/0x0061e7a0-0x0061e854.SelfSaveOKPaneVtableData.md --apply --queue-timeout 240`. | high | Literal scoped validator command for the physical vtable page. | UID0002OU / validator receipt | validate | applied_verified |
| C0000NN-036 | 0003JL | Run `python .\tools\validator.py --mode file --file by-memory/0x0061ea8c-0x0061eaa8.SelfSaveOKPaneSpacerString.md --apply --queue-timeout 240`. | high | Literal scoped validator command for the spacer page. | UID0003JL / validator receipt | validate | applied_verified |
| C0000NN-037 | 0000L3 | Run `python .\tools\validator.py --mode file --file by-file/MapPane.md --apply --queue-timeout 240`. | high | Literal scoped validator command for the MapPane support page. | by-file/MapPane.md / validator receipt | validate | applied_verified |
| C0000NN-038 | 0000NN | Run final owning refresh `python .\tools\validator.py --mode file --file by-file/SelfSaveOKPane.md --apply --queue-timeout 240 --wait-generated`. | high | Literal final wait command after all scoped passes. | by-file/SelfSaveOKPane.md / final owner receipt | validate-wait | applied_verified |
| C0000NN-039 | 0000NN | Physically reread `auto-generated/NexusTK/ui/dialogs/SelfSaveOKPane.cpp` after C038 and prove the provider prologue, factory, constructor, timer override, three no-code markers, no empty emitter, and no raw placeholder names. | high | Required generated CPP physical reconciliation. | generated SelfSaveOKPane.cpp readback | verify-generated | applied_verified |
| C0000NN-040 | 0000CX | Physically reread `auto-generated/NexusTK/ui/dialogs/SelfSaveOKPane.h` after C038 and prove the complete guarded fieldless 0x174 class declaration with constructor and protected OnTimer override. | high | Required generated H physical reconciliation. | generated SelfSaveOKPane.h readback | verify-generated | applied_verified |
| I0000NN-001 | 0000CX | Declare an opaque SelfSaveOKPane type before applying function signatures. | high | Current type query returns no SelfSaveOKPane type. | IDA local type catalog | incorporate | proposed |
| I0000NN-002 | 0001AY | Pure-rename/type/comment the factory with the exact permitted addition of `unusedPacket +0x38 size 0x04 int`, preserving all eight original frame rows including `arg_4 +0x3c size 0x04 _DWORD`. | high | Exact body/bounds/bytes/xrefs plus disposable public-endpoint proof of the complete nine-row final frame and its sole permitted frame addition. | IDA 0x00513800 | incorporate | proposed |
| I0000NN-003 | 0001B0 | Pure-rename and type the constructor, then add exact function and repeatable source comments. | high | Exact body, bounds, frame, bytes, and three construction-site equivalence. | IDA 0x005147d0 | incorporate | proposed |
| I0000NN-004 | 0001B0 | Pure-rename/type/comment the timer override with exact `arg_0` to `timerId` rename/retype and exact `unused1 +0x0c` and `unused2 +0x10` integer-row additions. | high | Sole timer slot, exact body and multiple-inheritance adjustment, plus disposable public-endpoint proof of the complete five-row final frame. | IDA 0x005148e0 | incorporate | proposed |
| I0000NN-005 | 0001YV | Add exact regular comments to the primary COL cell and vtable base without changing data. | high | Exact cells, names, bytes, and three construction refs. | IDA 0x0061e7a0 and 0x0061e7a4 | incorporate | proposed |
| I0000NN-006 | 0001YV | Add exact regular comments to the secondary COL cell and vtable base without changing data. | high | Exact cells, names, bytes, and three construction refs. | IDA 0x0061e818 and 0x0061e81c | incorporate | proposed |
| I0000NN-007 | 0001YV | Add exact regular comments to the timer COL, vtable base, and OnTimer slot without changing data. | high | Exact cells, timer target, bytes, and xrefs. | IDA 0x0061e848 through 0x0061e850 | incorporate | proposed |
| I0000NN-008 | 0003JL | Recreate the named 26-byte literal item, immediately apply its global `const wchar_t[13]` type with `set_type`, and add exact address comments while preserving alignment and refs. | high | Disposable public-endpoint proof: `make_data` yields the correct named item with blank displayed type, and mandatory `set_type` yields the exact array-type readback; exact bytes, alignment, and six inbound refs remain protected. | IDA 0x0061ea8c | incorporate | proposed |

## Positive Evidence Summary

- The three construction sequences agree on allocation size `0x174`, TextBoxPane arguments `(408, 12, false, 143, 1, NULL)`, three facet stores, three text insertions, localized id `61`, bounds `(14,456,422,468)`, BackPane/root-layer routing, and one-second timer id `0`.
- Vtable bases have three construction-store refs each: MapPane at `0x0050855b/61/6b`, factory at `0x00513871/77/81`, and constructor at `0x00514829/2f/39`.
- Spacer literal has exactly six true refs at `0x00508550`, `0x00508593`, `0x00513866`, `0x005138a9`, `0x0051481b`, and `0x00514861`.
- Timer slot `0x0061e850` points only to `0x005148e0`; the function has no independent caller route.
- SelfSave and TextBox vtables are target-identical except for that one timer slot, proving the fieldless derived class and sole override.
- Exact padding cleanly separates all source bodies and adjacent unrelated functions.
- Current provider docs already supply all declarations needed by the proposed source and generated headers exist at the expected paths.

## IDA MCP Facts

### Function facts

| Address | Current name/type | Exact range and byte SHA256 | Complete current stack-frame inventory | Reachability |
| --- | --- | --- | --- | --- |
| `0x00513800` | `sub_513800`; `char __stdcall(int)` | `[0x00513800,0x00513920)`, 288 bytes, `150CE4080002D08330522FECA02C181192AFB423766F8AA785378D327F0AC151` | `Block +0x0c/4 void *`; `bounds +0x10/0x10 RectBounds`; `var_10 +0x20/4`; `var_C +0x24/4`; `var_4 +0x2c/4`; saved registers `+0x30/4`; return address `+0x34/4`; `arg_4 +0x3c/4` | no external inbound code/data/pointer route; ordinary internal flow only |
| `0x005147d0` | `sub_5147D0`; `TimerHandler *__thiscall(TimerHandler *this)` | `[0x005147d0,0x005148d6)`, 262 bytes, `AE290E92245D415756A550A0671630670956BEE9FD57A1BBF002E952B00B0FF5` | `var_28 +0x0c/4 _DWORD *`; `var_24 +0x10/4`; `bounds +0x14/0x10 RectBounds`; `var_10 +0x24/4`; `var_C +0x28/4`; `var_4 +0x30/4`; saved registers `+0x34/4`; return address `+0x38/4`; `arg_4 +0x40/4` | no external inbound code/data/pointer route; ordinary internal flow only |
| `0x005148e0` | `sub_5148E0`; `char __thiscall(_DWORD *this, int, int, int)` | `[0x005148e0,0x00514914)`, 52 bytes, `0822F38CBBDAF7A51559F3C230B3184409A687DFAD79F35785EC3460850FB0BA` | saved registers `+0x00/4`; return address `+0x04/4`; `arg_0 +0x08/4` | one true inbound data xref from timer slot `0x0061e850` |

All three function entry address comments and function comments are currently absent. `lookup_funcs` reports exact sizes `0x120`, `0x106`, and `0x34`.

### Data facts

- Vtable/COL range `[0x0061e7a0,0x0061e854)` is 180 bytes, SHA256 `2894048A9A4AE2A43C30267310E79B9EB409094DD400BBA006A2DB91714259E1`.
- Primary COL cell `[0x61e7a0,0x61e7a4)` is unnamed/untyped and points to named RTTI; primary base `[0x61e7a4,0x61e7a8)` is `??_7SelfSaveOKPane@@6B@`.
- Secondary COL cell `[0x61e818,0x61e81c)` is unnamed/untyped; secondary base is `??_7SelfSaveOKPane@@6B@_0`.
- Timer COL cell `[0x61e848,0x61e84c)` is unnamed/untyped; timer base is `??_7SelfSaveOKPane@@6B@_1`; slot `[0x61e850,0x61e854)` is unnamed/untyped and points to `0x5148e0`.
- All checked vtable/COL regular and repeatable comments are absent.
- Spacer range `[0x0061ea8c,0x0061eaa8)` is 28 bytes, SHA256 `7BFD4FD7B73DC4D088FDBE4DAF35D8FC569C512344735C90C298FA162428EFFB`. Literal item `[0x61ea8c,0x61eaa6)` is size 26, name `asc_61EA8C`, type absent; alignment item `[0x61eaa6,0x61eaa8)` is size 2, unnamed/untyped. Comments are absent.
- `type_query` returns no current `SelfSaveOKPane` local type.

## Function / Child Inventory

| Source/data item | Exact binary range | Source disposition | Documentation owner |
| --- | --- | --- | --- |
| file-local factory | `0x00513800-0x00513920` | emit `static bool __stdcall CreateSelfSaveOKPane(int)` | UID0001AY -> UID0000NN |
| unrelated packet sender | `0x00513920-0x005139a4` | exclude from SelfSaveOKPane; separate unresolved family | not UID0000NN |
| padding | `0x005139a4-0x005139b0` | compiler/linker alignment | ignored ledger |
| unrelated UI/sound helper | `0x005139b0-0x00513a1a` | exclude from SelfSaveOKPane | not UID0000NN |
| padding | `0x00513a1a-0x00513a20` | compiler/linker alignment | ignored ledger |
| constructor | `0x005147d0-0x005148d6` | emit `SelfSaveOKPane::SelfSaveOKPane()` | UID0001B0 -> UID0000NN |
| padding | `0x005148d6-0x005148e0` | ten `0xcc` bytes | ignored ledger |
| timer override | `0x005148e0-0x00514914` | emit `SelfSaveOKPane::OnTimer` | UID0001B0 -> UID0000NN |
| padding | `0x00514914-0x00514920` | twelve `0xcc` bytes | ignored ledger |
| primary/secondary/timer vtables and COL cells | `0x0061e7a0-0x0061e854` | compiler-generated; emit covered-by comments only | UID0001YV and UID0002OU -> UID0000CX |
| 12-space pooled UTF-16 literal plus alignment | `0x0061ea8c-0x0061eaa8` | literal emitted at use sites; covered-by comment only | UID0003JL -> UID0000CX |
| MapPane opcode-0x21 duplicate | inline block beginning `0x00508511`; exact researched slice 222 bytes | remain inline in `MapPane::HandlePacket` | UID0000L3/MapPane handler |

Inventory totals: three source-authored SelfSaveOKPane file bodies, one pooled source literal object, three compiler vtable facets over one physical page, three exact alignment spans around source bodies, two unrelated successor helpers excluded, and one MapPane-owned inline duplicate. There is no omitted SelfSaveOKPane destructor body, data member, standalone global, resource, or second header.

## Direct Xref / Caller Inventory

- Factory `0x00513800`: no external inbound code or data xref. This does not make the coherent body dead or non-source; it indicates a registration route no longer represented by a direct IDA xref.
- Constructor `0x005147d0`: no external inbound xref. Construction is also inlined twice, and the standalone body remains exact source evidence.
- Timer override `0x005148e0`: sole inbound from timer vtable slot `0x0061e850`.
- Primary vtable base `0x0061e7a4`: inbound stores `0x50855b`, `0x513871`, `0x514829`; first-slot outbound `0x48c4d0`.
- Secondary base `0x0061e81c`: inbound stores `0x508561`, `0x513877`, `0x51482f`; first-slot outbound `0x48c2e9`.
- Timer base `0x0061e84c`: inbound stores `0x50856b`, `0x513881`, `0x514839`; first-slot outbound `0x48c2f4`.
- Timer slot `0x0061e850`: sole outbound target `0x5148e0`.
- Spacer literal: exactly the six refs listed in Positive Evidence Summary, two from each construction site.
- `InsertText`, localized-string lookup, rectangle initialization, layer attachment/removal, and timer scheduling calls resolve to existing support owners; none should be re-owned by UID0000NN.

## Documentation Evidence And IDA Status

- UID0000NN and UID0000CX agree on source path and class owner and now contain the complete whole-file/class closure at `94/94` and `94/95`.
- UID0001AY and UID0001B0 emit through UID0000NN with the accepted exact source, scores, frames, hashes, padding, and boundary prose.
- UID0001YV, UID0002OU, and UID0003JL point to UID0000CX, are `94/95`, and carry exact formal covered-by markers plus full compiler/data evidence.
- MapPane records opcode `0x21` as an inline byte-owned duplicate while preserving SelfSaveOKPane class and reusable-method ownership.
- TextEditPane current formal behavior resolves `sub_58E270` as `InsertText(const wchar_t *, int)`.
- MainUiGraph current formal layout resolves the raw `[1]` slot as `rootPaneLayerContext`.
- IDA still has useful compiler-decorated vtable names but raw function/literal labels and no SelfSaveOKPane local type. I0000NN-001..008 remain unchecked supervisor-owned proposals; no callback mutation occurred.
- No current IDA comment/type/rename is a prerequisite for the documentation scores or formal source.

## Ranked Ownership Analysis

1. **UID0000NN SelfSaveOKPane file, accepted.** It owns the factory and class method definitions, has an existing complete header, and matches source organization.
2. **UID0000CX SelfSaveOKPane class, accepted as direct type owner.** It owns declarations and compiler-generated vtable/literal evidence, while emitting through UID0000NN.
3. **UID0000L3 MapPane, accepted only for the inline opcode-0x21 duplicate.** The packet handler owns those inline bytes; it does not own the SelfSaveOKPane class or standalone functions.
4. **TextBoxPane/TextEditPane, rejected as direct owners.** They provide inherited behavior and the InsertText implementation but do not own the derived constructor/timer/factory.
5. **SpelledPane and broad generated-owner candidates, rejected.** No class layout, vtable, call, or source relation supports them.
6. **No-owner/non-emitting, rejected.** Exact custom source bodies and a coherent file/header route are present.

## Source Placement

- Keep `NexusTK/ui/dialogs/SelfSaveOKPane.cpp` and `SelfSaveOKPane.h`.
- Keep the file-local factory in the CPP only; do not expose it in the header.
- Keep the class declaration in the existing H channel through UID0000CX.
- Keep the constructor and OnTimer definitions in the CPP through UID0001B0.
- Keep vtables/RTTI compiler-generated from the class declaration; do not emit raw arrays.
- Keep the spacer literal at use sites; do not expose an extern/global array.
- Keep MapPane's inline duplicate in MapPane.cpp.
- No source split, merge, new header, or third-party import is justified.

## Range / Split / Padding / Reclassification Analysis

- UID0001AY's `[0x513800,0x513920)` range is exact. The `ret 4` terminates at `0x513920`; predecessor byte `0x5137ff` and successors are outside the function.
- The two raw successor helpers have coherent independent behavior and exact separator padding. They must not inflate the factory range or block its score.
- UID0001B0 contains two exact modeled functions with ten bytes of inter-function `0xcc` padding and twelve trailing `0xcc` bytes before MapRefreshDimmer at `0x514920`. Existing ignored-ledger entries remain correct.
- UID0002OU is exactly bounded by MapPane data before `0x61e7a0` and MapRefreshDimmer data after `0x61e854`.
- UID0003JL is exactly 13 UTF-16 code units including NUL plus one zero alignment word. The typed literal should cover only `[0x61ea8c,0x61eaa6)`; `[0x61eaa6,0x61eaa8)` remains a separate alignment item.
- No document split is needed. Exact source/no-code children already exist.

## Negative Evidence Summary

- No direct external xref identifies the factory's original registration site or exact original helper spelling.
- No original PDB/source symbol names the factory, constructor, timer, local `padding`, or callback argument.
- No evidence supports a derived data member, explicit destructor, additional override, raw vtable array, raw spacer global, or second source file.
- No call from MapPane opcode `0x21` reaches the standalone factory or constructor; its construction is genuinely inline.
- No vtable slot beyond OnTimer differs from TextBoxPane.
- No SelfSaveOKPane-owned function exists in the resolved successor bytes after `0x513920` or after `0x514914`.
- These negatives cap naming confidence but do not block implementation-ready source.

## IDA Rename / Type / Comment Recommendations

All actions are supervisor-owned Gate 2B proposals and remain unchecked. Gate 2B must begin with fresh `runtime_attestation` against the current canonical path/session. If a session must be opened, use public `idb_open` with `run_auto_analysis:false`. Every prestate is literal and fail-closed. Every mutation stage requires exact immediate readback before the next stage. No action may alter bytes, function boundaries, item boundaries except the explicitly authorized spacer recreation, xrefs, padding, neighboring items, or protected comments/names/types.

Endpoint binding is exact: use `declare_type` with `decls`; use `rename` with `batch.func`, `pure:true`, `allow_overwrite:false`, `stop_on_error:true`, first `dry_run:true` then identical `dry_run:false`; use `set_type` with `edits:{addr,signature}` for I02-I04 function signatures; use `set_function_comments` for regular function comments; use `set_address_repeatable_comments` for repeatable entry-address comments; use `set_address_comments` for regular data comments; and use `make_data` only for I08 with `delete_existing:true`. I08 then immediately requires a separate `set_type` call at `0x0061ea8c` with `kind:"global"` and `ty:"const wchar_t[13]"`; the declaration accepted by `make_data` is not a substitute for that call. Read back through `type_query`, `lookup_funcs`, `stack_frame`, `inspect_items`, `get_comments`, `get_bytes`, and directional `xref_query`.

`AR`, `AP`, `FR`, and `FP` below mean address-regular, address-repeatable, function-regular, and function-repeatable comment channels. `N/A` is literal for channels that do not exist for that entity class. Each entity row is independently gated; a mismatch stops before its mutation and does not authorize adaptation.

| Entity row | Literal current prestate including full hashes, frames, comments, xrefs, and values | Exact action and classification | Permitted delta | Exact required poststate and hard stop |
| --- | --- | --- | --- | --- |
| I01 | Local type query `filter=SelfSaveOKPane`, `kind=any`, `count=50` returns `total:0`, empty data. Name/type/item/value/xrefs are absent. AR/AP/FR/FP are `N/A`. | `TYPE_DECLARE`: call `declare_type` with exact declaration `struct SelfSaveOKPane;`. | Add exactly one opaque forward declaration; no size, members, base, typedef, or function type. | `type_query` returns exactly one opaque `SelfSaveOKPane` declaration with no members and no invented size. Any existing non-opaque type, collision, parse drift, or extra declaration stops I02-I04. |
| I02 | Function entry item `[0x00513800,0x00513801)`, size 1, code, first byte `55`; function range `[0x00513800,0x00513920)`, 288 bytes, SHA256 `150CE4080002D08330522FECA02C181192AFB423766F8AA785378D327F0AC151`; name `sub_513800`; type `char __stdcall(int)`; AR absent, AP absent, FR absent, FP absent. Complete eight-row prestate frame: `Block +0x0c size 0x04 void *`; `bounds +0x10 size 0x10 struct RectBounds`; `var_10 +0x20 size 0x04 _DWORD`; `var_C +0x24 size 0x04 _DWORD`; `var_4 +0x2c size 0x04 _DWORD`; `__saved_registers +0x30 size 0x04 _DWORD`; `__return_address +0x34 size 0x04 _UNKNOWN *`; `arg_4 +0x3c size 0x04 _DWORD`. Entry directional xrefs: inbound zero; outbound one ordinary code-flow edge `0x00513800 -> 0x00513801`. Predecessor item ends `0x00513800`; successor raw item begins `0x00513920`. | `FUNCTION_RENAME_TYPE_COMMENT`: pure rename dry-run/apply to `CreateSelfSaveOKPane`; `set_type` exact `bool __stdcall CreateSelfSaveOKPane(int unusedPacket)`; `set_function_comments` FR exact `Allocates and initializes the transient SelfSaveOKPane status pane, then reports success.`; `set_address_repeatable_comments` AP exact `Source reconstruction: static bool __stdcall CreateSelfSaveOKPane(int).` | Change name, prototype, FR, and AP exactly; AR and FP stay absent. The only permitted frame delta is addition of `unusedPacket +0x38 size 0x04 int`. Zero rows may be removed. None of the eight original rows may be renamed, retyped, moved, or resized; in particular `arg_4 +0x3c size 0x04 _DWORD` remains protected and distinct from the new row. | Exact new name/type/FR/AP; AR and FP absent. Complete nine-row final frame: `Block +0x0c size 0x04 void *`; `bounds +0x10 size 0x10 struct RectBounds`; `var_10 +0x20 size 0x04 _DWORD`; `var_C +0x24 size 0x04 _DWORD`; `var_4 +0x2c size 0x04 _DWORD`; `__saved_registers +0x30 size 0x04 _DWORD`; `__return_address +0x34 size 0x04 _UNKNOWN *`; `unusedPacket +0x38 size 0x04 int`; `arg_4 +0x3c size 0x04 _DWORD`. Range hash, item, bytes, zero inbound, one entry outbound, predecessor/successor items, function bounds, and all body xrefs remain unchanged. Any other frame delta, collision, hash/xref/item drift, or extra planned rename stops. |
| I03 | Function entry item `[0x005147d0,0x005147d1)`, size 1, code, first byte `55`; function range `[0x005147d0,0x005148d6)`, 262 bytes, SHA256 `AE290E92245D415756A550A0671630670956BEE9FD57A1BBF002E952B00B0FF5`; name `sub_5147D0`; type `TimerHandler *__thiscall(TimerHandler *this)`; AR absent, AP absent, FR absent, FP absent. Complete frame: `var_28 +0x0c size 0x04 _DWORD *`; `var_24 +0x10 size 0x04 _DWORD`; `bounds +0x14 size 0x10 struct RectBounds`; `var_10 +0x24 size 0x04 _DWORD`; `var_C +0x28 size 0x04 _DWORD`; `var_4 +0x30 size 0x04 _DWORD`; `__saved_registers +0x34 size 0x04 _DWORD`; `__return_address +0x38 size 0x04 _UNKNOWN *`; `arg_4 +0x40 size 0x04 _DWORD`. Entry directional xrefs: inbound zero; outbound one ordinary code-flow edge `0x005147d0 -> 0x005147d1`. Predecessor padding ends `0x005147d0`; ten-byte padding begins `0x005148d6`. | `FUNCTION_RENAME_TYPE_COMMENT`: pure rename dry-run/apply to `SelfSaveOKPane__SelfSaveOKPane`; `set_type` exact `SelfSaveOKPane *__thiscall SelfSaveOKPane__SelfSaveOKPane(SelfSaveOKPane *this)`; FR exact `Constructs the fieldless text-box status pane, inserts padding/caption text, attaches it to the root pane layer, and schedules timer zero.`; AP exact `Source reconstruction: SelfSaveOKPane::SelfSaveOKPane().` | Name, prototype, FR, and AP only. AR/FP stay absent. No frame delta of any kind. | Exact new name/type/FR/AP; AR/FP absent; complete nine-row frame exactly as stated; hash, bounds, entry item, zero inbound, one entry outbound, vtable stores, calls, and adjacent padding unchanged. Any mismatch stops before a later stage. |
| I04 | Function entry item `[0x005148e0,0x005148e1)`, size 1, code, first byte `55`; function range `[0x005148e0,0x00514914)`, 52 bytes, SHA256 `0822F38CBBDAF7A51559F3C230B3184409A687DFAD79F35785EC3460850FB0BA`; name `sub_5148E0`; type `char __thiscall(_DWORD *this, int, int, int)`; AR absent, AP absent, FR absent, FP absent. Complete three-row prestate frame: `__saved_registers +0x00 size 0x04 _DWORD`; `__return_address +0x04 size 0x04 _UNKNOWN *`; `arg_0 +0x08 size 0x04 _DWORD`. Directional xrefs: one inbound data xref `0x0061e850 -> 0x005148e0`; one entry outbound ordinary code-flow edge `0x005148e0 -> 0x005148e1`. Twelve-byte padding begins `0x00514914`. | `FUNCTION_RENAME_TYPE_COMMENT`: pure rename dry-run/apply to `SelfSaveOKPane__OnTimer`; `set_type` exact `bool __thiscall SelfSaveOKPane__OnTimer(TimerHandler *this, int timerId, int unused1, int unused2)`; FR exact `Timer-facet override: timer zero removes and deletes the owning SelfSaveOKPane; every timer notification returns true.`; AP exact `Source reconstruction: bool SelfSaveOKPane::OnTimer(int, int, int).` | Change name, prototype, FR, and AP exactly; AR/FP remain absent. Rename/retype only `arg_0 +0x08 size 0x04 _DWORD` to `timerId +0x08 size 0x04 int`; add exactly `unused1 +0x0c size 0x04 int` and `unused2 +0x10 size 0x04 int`; remove zero rows. Preserve `__saved_registers +0x00 size 0x04 _DWORD` and `__return_address +0x04 size 0x04 _UNKNOWN *` without rename, type, offset, or width changes. | Exact name/type/FR/AP; AR/FP absent. Complete five-row final frame: `__saved_registers +0x00 size 0x04 _DWORD`; `__return_address +0x04 size 0x04 _UNKNOWN *`; `timerId +0x08 size 0x04 int`; `unused1 +0x0c size 0x04 int`; `unused2 +0x10 size 0x04 int`. Hash, range, entry item, one inbound and one entry outbound xref, owner adjustment, removal/deletion body, and trailing padding remain unchanged. Any other frame delta or protected-state drift stops. |
| I05.1 | Primary COL cell item `[0x0061e7a0,0x0061e7a4)`, size 4, data, name absent, type absent, value `0x0064b31c`, bytes `1c b3 64 00`, SHA256 `6B7880E4EB91D9292211261BF18FC7E0C6E9FB0D4BCF01F222F61A5118260D96`; AR absent, AP absent, FR/FP `N/A`; inbound xrefs zero; outbound data xref `0x0061e7a0 -> 0x0064b31c`. | `COMMENT_ONLY`: `set_address_comments` AR exact `SelfSaveOKPane primary vftable[-1] complete-object-locator pointer.` | AR only. | AR exact; AP absent; item/name/type/value/bytes/hash, zero inbound, sole outbound, and neighbors unchanged. |
| I05.2 | Primary vtable-base item `[0x0061e7a4,0x0061e7a8)`, size 4, data, name `??_7SelfSaveOKPane@@6B@`, type absent, value `0x0048c4d0`, bytes `d0 c4 48 00`, SHA256 `8BFB84435B32DD204CD43A2FE5BF27A81BE65EF3343CC16B11D9756728699249`; AR absent, AP absent, FR/FP `N/A`; inbound data xrefs `0x0050855b`, `0x00513871`, `0x00514829`; outbound data xref `0x0061e7a4 -> 0x0048c4d0`. | `COMMENT_ONLY`: AR exact `SelfSaveOKPane primary TextBoxPane facet vftable; compiler-generated from the class declaration.` | AR only. | AR exact; AP absent; item/name/type/value/bytes/hash, three inbound xrefs, sole outbound, all later slots, and neighbors unchanged. |
| I06.1 | Secondary COL cell `[0x0061e818,0x0061e81c)`, size 4, data, name absent, type absent, value `0x0064b3d4`, bytes `d4 b3 64 00`, SHA256 `7378C388F0AA76AC32445DD8703DADD006315A7B400E5F839C471B6F536BDB52`; AR/AP absent, FR/FP `N/A`; inbound zero; outbound data xref `0x0061e818 -> 0x0064b3d4`. | `COMMENT_ONLY`: AR exact `SelfSaveOKPane secondary vftable[-1] complete-object-locator pointer.` | AR only. | AR exact; AP absent; every other literal prestate field and neighbor unchanged. |
| I06.2 | Secondary vtable-base item `[0x0061e81c,0x0061e820)`, size 4, data, name `??_7SelfSaveOKPane@@6B@_0`, type absent, value `0x0048c2e9`, bytes `e9 c2 48 00`, SHA256 `3EE9D384CB98820D2CE9999E6DEDA15279F10B1E783A36C7383A45E1865F7A91`; AR/AP absent, FR/FP `N/A`; inbound data xrefs `0x00508561`, `0x00513877`, `0x0051482f`; outbound data xref `0x0061e81c -> 0x0048c2e9`. | `COMMENT_ONLY`: AR exact `SelfSaveOKPane secondary facet vftable; inherited targets match TextBoxPane.` | AR only. | AR exact; AP absent; item/name/type/value/bytes/hash, three inbound xrefs, sole outbound, all later slots, and neighbors unchanged. |
| I07.1 | Timer COL cell `[0x0061e848,0x0061e84c)`, size 4, data, name absent, type absent, value `0x0064b3e8`, bytes `e8 b3 64 00`, SHA256 `C667D906F03AC8045116BA600A725E57FD721FE6123E8521EC26031C7720E6B5`; AR/AP absent, FR/FP `N/A`; inbound zero; outbound data xref `0x0061e848 -> 0x0064b3e8`. | `COMMENT_ONLY`: AR exact `SelfSaveOKPane TimerHandler-facet vftable[-1] complete-object-locator pointer.` | AR only. | AR exact; AP absent; all item/value/hash/xref/neighbor state unchanged. |
| I07.2 | Timer vtable-base item `[0x0061e84c,0x0061e850)`, size 4, data, name `??_7SelfSaveOKPane@@6B@_1`, type absent, value `0x0048c2f4`, bytes `f4 c2 48 00`, SHA256 `8BADDBFD098116F7CC6E70E78187C9AD14603A1C028C64D6BA1EC3846FB346AC`; AR/AP absent, FR/FP `N/A`; inbound data xrefs `0x0050856b`, `0x00513881`, `0x00514839`; outbound data xref `0x0061e84c -> 0x0048c2f4`. | `COMMENT_ONLY`: AR exact `SelfSaveOKPane TimerHandler facet vftable.` | AR only. | AR exact; AP absent; item/name/type/value/bytes/hash, three inbound xrefs, sole outbound, and neighbors unchanged. |
| I07.3 | OnTimer slot item `[0x0061e850,0x0061e854)`, size 4, data, name absent, type absent, value `0x005148e0`, bytes `e0 48 51 00`, SHA256 `229FBA5F998E0BD00EAA551F47396CBC806D9CEFA3D5935BD7D2C7C57B250620`; AR/AP absent, FR/FP `N/A`; inbound zero; outbound data xref `0x0061e850 -> 0x005148e0`. | `COMMENT_ONLY`: AR exact `SelfSaveOKPane::OnTimer slot; the source override owns the timer-facet this adjustment.` | AR only. | AR exact; AP absent; item/name/type/value/bytes/hash, zero inbound, sole outbound, and strict `0x0061e854` boundary unchanged. |
| I08 | Literal item `[0x0061ea8c,0x0061eaa6)`, size 26, data, name `asc_61EA8C`, type absent, decoded value twelve spaces plus NUL, bytes `20 00 20 00 20 00 20 00 20 00 20 00 20 00 20 00 20 00 20 00 20 00 20 00 00 00`, item SHA256 `3B999D57F7E8F2F1F112B49D7B571E2E2E2479CA4FE965A66E79D9A3EAAAAAEF`; full `[0x0061ea8c,0x0061eaa8)` literal-plus-alignment SHA256 `7BFD4FD7B73DC4D088FDBE4DAF35D8FC569C512344735C90C298FA162428EFFB`; AR/AP absent, FR/FP `N/A`; inbound data xrefs exactly `0x00508550`, `0x00508593`, `0x00513866`, `0x005138a9`, `0x0051481b`, `0x00514861`; outbound zero; separate alignment item `[0x0061eaa6,0x0061eaa8)`, size 2, bytes `00 00`, unnamed/untyped. | `DATA_RECREATE_RENAME_TYPE_COMMENT`, exact ordered sequence: (1) call `make_data` at `0x0061ea8c` with `delete_existing:true`, declaration `const wchar_t SelfSaveOKPane_SpacerText[13]`, and name `SelfSaveOKPane_SpacerText`; (2) immediately require `inspect_items` to show head `0x0061ea8c`, end `0x0061eaa6`, size 26, name `SelfSaveOKPane_SpacerText`, blank displayed type, `is_data:true`, and `is_code:false`; (3) immediately call `set_type` at `0x0061ea8c` with `kind:"global"` and `ty:"const wchar_t[13]"`; (4) immediately require the same item with displayed type `const wchar_t[13]`; (5) set AR exact `Pooled twelve-space UTF-16 literal used before and after the localized SelfSaveOKPane caption.` and AP exact `Source uses L\"            \" at the three construction sites; storage pooling is compiler-owned.` | Recreate only the same 26-byte item; change its name, final type, AR, and AP exactly. The blank displayed type is permitted only in the mandatory immediate post-`make_data` intermediate readback; it is not an acceptable final state. No byte, bound, alignment, xref, neighbor, decoded-value, or other comment-channel delta is permitted. | Final `inspect_items` must show exactly one item with head `0x0061ea8c`, end `0x0061eaa6`, size 26, name `SelfSaveOKPane_SpacerText`, type `const wchar_t[13]`, `is_data:true`, and `is_code:false`; AR/AP are exact and FR/FP remain `N/A`. Both hashes, decoded value, all six inbound/zero outbound xrefs, the separate `[0x0061eaa6,0x0061eaa8)` alignment item, bounds, bytes, and adjacent data remain exact. Disposable endpoint proof establishes that `make_data` alone succeeds but leaves the displayed type blank, so the second `set_type` call is mandatory. If either call or any immediate/final literal readback differs, stop without save. |

The I03/I04 IDA names are navigation names, not claims of original mangled spelling. Formal source remains the C++ member syntax below. I08's named data item and mandatory second-call global array type are IDA navigation improvements only; no standalone C++ array is emitted. The tested blank-type intermediate state after successful `make_data` is expected only long enough to perform and verify the immediate `set_type`; it must never be accepted or saved as the final I08 state.

## First-Draft C++ Recommendation

The following is exact formal source for accepted insertion, not illustrative pseudocode.

**UID0000CX formal CPP replacement: exact class prologue and child route**

```cpp
#include "SelfSaveOKPane.h"

#include "../../localization/LanguageMan.h"
#include "../../map/BackPane.h"
#include "../MainUiGraph.h"

[[CHILDREN]]
```

This block belongs only in [UID:0000CX] `by-class/SelfSaveOKPane.md` `RECONSTRUCTION_CPP CODE`. It provides the complete CPP prologue and insertion point; it does not duplicate child definitions.

**UID0001AY formal CPP replacement: exact file-local factory**

```cpp
static bool __stdcall CreateSelfSaveOKPane(int unusedPacket)
{
    (void)unusedPacket;

    new SelfSaveOKPane;
    return true;
}
```

This block belongs only in [UID:0001AY] `by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md` `RECONSTRUCTION_CPP CODE`.

**UID0001B0 formal CPP replacement: exact constructor and timer override**

```cpp
SelfSaveOKPane::SelfSaveOKPane()
    : TextBoxPane(408, 12, false, 143, 1, NULL)
{
    const wchar_t *padding = L"            ";

    InsertText(padding, 0);
    InsertText(g_pLanguageMan->GetLocalizedString(61), 0);
    InsertText(padding, 0);

    RectBounds bounds;
    InitRectBounds(&bounds, 14, 456, 422, 468);
    AddToLayer(&bounds, 0, g_pBackPane,
               g_mainUiLayerSlots.rootPaneLayerContext);

    ScheduleTimer(0, 1000, 0, 0);
}

bool SelfSaveOKPane::OnTimer(int timerId, int, int)
{
    if (timerId == 0) {
        RemoveFromLayer();
        delete this;
    }

    return true;
}
```

This block belongs only in [UID:0001B0] `by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md` `RECONSTRUCTION_CPP CODE`.

**UID0000CX formal H, preserved exactly**

```h
#ifndef NEXUSTK_UI_DIALOGS_SELFSAVEOKPANE_H
#define NEXUSTK_UI_DIALOGS_SELFSAVEOKPANE_H

#include "../controls/TextEditPane.h"

class SelfSaveOKPane : public TextBoxPane
{
public:
    SelfSaveOKPane();

protected:
    virtual bool OnTimer(int timerId, int, int);
};

typedef char SelfSaveOKPaneSizeMustBe174[
    (sizeof(SelfSaveOKPane) == 0x174) ? 1 : -1];

#endif
```

**UID0001YV formal CPP marker**

```cpp
// SelfSaveOKPane vtables are compiler-generated from SelfSaveOKPane.h;
// no hand-authored vtable array belongs in SelfSaveOKPane.cpp.
```

**UID0002OU formal CPP marker**

```cpp
// The physical SelfSaveOKPane RTTI/COL/vtable bytes are covered by the
// SelfSaveOKPane class declaration and its virtual OnTimer override.
```

**UID0003JL formal CPP marker**

```cpp
// The pooled twelve-space UTF-16 literal is covered by L"            "
// at the SelfSaveOKPane construction use sites; no standalone array emits.
```

No additional H payload belongs to UID0001AY, UID0001B0, UID0001YV, UID0002OU, or UID0003JL.

## Final Recommendation

Submit this callback-current artifact for fresh supervisor Gate 2A. Its file family is fully inventoried, source ownership is stable, exact formal CPP/H is implemented, compiler/data emitters have non-empty no-code dispositions, the factory successor ambiguity is resolved, the public-endpoint I02/I04 frame deltas remain literal and fail-closed, all planned ordinary validators passed, and generated CPP/H were physically reread. Coverage C0000NN-021..027 and IDA I0000NN-001..008 remain separate unchecked supervisor gates.

The only residual uncertainty is original spelling: no surviving route proves whether the local callback was literally named `CreateSelfSaveOKPane` or what its unused parameter was called. The chosen spelling is the highest-probability current project convention and is preferable to a raw label. It justifies a confidence cap, not blank code or deferred investigation.

## Recommended Target Doc Changes

- Applied and verified UID0000NN metadata `94/94` with the path and owner retained.
- Applied the complete inventory, exact source order, inline-duplicate distinction, compiler/no-code dispositions, provider list, generated expectations, score rationale, and superseded-history record without pruning prior evidence.
- Applied the two unrelated post-factory raw-helper/padding exclusions through UID0001AY and verified the target's generated CPP/H contract through waited physical readback.

## Recommended Support Doc Changes

- Applied and verified UID0000CX `94/95`, unchanged complete H, exact four-include CPP prologue, and sole-override/fieldless/vtable closure.
- Applied and verified UID0001AY `93/92` with exact formal body, frame/hash evidence, duplicate/no-route analysis, and successor exclusions.
- Applied and verified UID0001B0 `94/95` with InsertText/root-layer semantics, exact frames/bytes/padding, and timer-facet lowering.
- Applied and verified UID0001YV, UID0002OU, and UID0003JL at `94/95` with complete facet/physical/literal evidence and exact covered-by markers; UID0003JL also has the required Item Summary.
- Applied and verified the UID0000L3 MapPane inline source-byte ownership clarification without transferring the reusable class route.
- Provider docs need no ownership/code change; cite them as accepted dependencies and avoid duplication.

## Score And Metadata Recommendation

| UID | Current | Recommended | Owner/emitter disposition | Reason not higher | Reason not lower |
| --- | --- | --- | --- | --- | --- |
| 0000NN | 94/94 | 94/94 | keep `FILE`, path `NexusTK/ui/dialogs/` | exact original local factory registration/name and local spellings are unavailable | exhaustive whole-file inventory, exact source, providers, compiler-data dispositions, boundaries, validators, and generated readback are complete |
| 0000CX | 94/95 | 94/95 | keep owner/emitter 0000NN, position 1 | final binary-equivalence compilation is not yet available | inheritance, size, sole override, header, all facets, and generated H are exact |
| 0001AY | 93/92 | 93/92 | keep owner/emitter 0000NN | zero direct route leaves callback spelling/registration inferred | body, source role, duplicate relation, frame, bounds, successors, and generated CPP are exact |
| 0001B0 | 94/95 | 94/95 | keep owner/emitter 0000NN | exact original local names/formatting remain inferred | both bodies, semantics, frame, padding, facet behavior, and generated CPP are exact |
| 0001YV | 94/95 | 94/95 | keep owner/emitter 0000CX | final binary-equivalence compilation is not yet available | all facets/slots/refs, source-generation cause, and marker are exact |
| 0002OU | 94/95 | 94/95 | keep owner/emitter 0000CX | final binary-equivalence compilation is not yet available | exact bytes/items/bounds/COLs/slots/refs and marker are complete |
| 0003JL | 94/95 | 94/95 | keep owner/emitter 0000CX | compiler pooling/local spelling remains inferred | payload, item boundary, refs, alignment, source pooling, and marker are exact |

The left column is the callback-current score and now matches the accepted recommendation. No score exceeds the 95/95 source-quality barrier.

## Open Questions With Attempted Resolution

- **Factory caller/registration:** all direct code/data/pointer routes remain absent. Exact body equivalence and file ownership solve source placement; original registration mechanism is not recoverable from current static routes. Decision: retain a file-local callback and cap factory confidence at 92.
- **Factory name:** no source symbol survives. Decision: retain project-consistent `CreateSelfSaveOKPane`, document inference, and do not emit `sub_513800`.
- **Unused parameter meaning:** the stack argument is never read. Decision: use `int unusedPacket`, preserving ABI without inventing semantics.
- **Text helper:** current support evidence resolves `sub_58E270`; decision is `InsertText(text, 0)`, not deferred.
- **Layer slot:** current support evidence resolves offset `0x0069b368`; decision is `rootPaneLayerContext`, not array syntax.
- **Explicit destructor:** no distinct slot/body/layout evidence supports one. Decision: use implicit destruction and `delete this`.
- **Spacer global versus literal:** six refs and compiler pooling support use-site literal syntax. Decision: no standalone global.
- **Vtable emission:** all data is compiler-derived from the exact class. Decision: comment-only covered-by markers.
- **MapPane duplicate:** no call route exists and exact inline bytes construct the type. Decision: retain inline in MapPane source and avoid duplicate helper ownership.
- No reasonable source-quality blocker remains open. Each residual naming uncertainty has a high-probability decision and explicit score cap.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

These are exact supervisor-owned replacements/inserts. They are dated against the `2026-08-17` snapshots and must be applied only after fresh row/path reread.

**by-file replacement for UID0000NN**

`- [UID:0000NN][SelfSaveOKPane](by-file/SelfSaveOKPane.md) : reconstructable : 94% : very-strong : Complete SelfSaveOKPane.cpp/.h source family with exact retained factory, fieldless TextBoxPane-derived constructor, sole timer override, MapPane opcode-0x21 inline-duplicate boundary, semantic InsertText/root-layer dependencies, compiler-generated vtable/RTTI covered-by handling, pooled spacer-literal disposition, and implementation-ready human-written C++.`

**by-class replacement for UID0000CX**

`- [UID:0000CX][SelfSaveOKPane](by-class/SelfSaveOKPane.md) : reconstructable : 94% : very-strong : Exact fieldless 0x174 TextBoxPane-derived class with complete header, constructor, sole OnTimer override, three vtable facets matching TextBoxPane except the timer slot, three construction-store groups, pooled spacer-literal use, and complete SelfSaveOKPane.cpp source route.`

**by-memory replacement for UID0001AY**

`        - [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md) 0x00513800-0x00513920 | file-local factory | SelfSaveOKPaneFactory : reconstructable : 93% : very-strong : Exact retained file-local callback that allocates and fully initializes SelfSaveOKPane, duplicates the standalone constructor and MapPane packet case, preserves its unused stdcall parameter and unconditional true result, and is bounded from two unrelated raw successor helpers despite no surviving direct registration xref.`

**by-memory replacement for UID0001B0**

`        - [UID:0001B0][0x005147d0-0x00514914.SelfSaveOKPane](by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md) 0x005147d0-0x00514914 | class method island | SelfSaveOKPane : reconstructable : 94% : very-strong : Exact fieldless constructor and TimerHandler-facet OnTimer override with complete frames, padding, vtable stores, InsertText/localized-caption order, semantic BackPane/root-layer attachment, one-second timer schedule, owner adjustment, removal, self-delete, and implementation-ready C++.`

**by-vtable replacement for UID0001YV**

`- [UID:0001YV][SelfSaveOKPane_vtables](by-type/by-vtable/SelfSaveOKPane_vtables.md) : reconstructable : 94% : very-strong : Exact primary, secondary, and TimerHandler vtable facets with all targets compared to TextBoxPane, sole differing OnTimer slot, three construction-store groups, precise COL/physical-data child boundaries, and compiler-generated covered-by source disposition.`

**by-memory replacement for UID0002OU**

`        - [UID:0002OU][0x0061e7a0-0x0061e854.SelfSaveOKPaneVtableData](by-memory/0x0061e7a0-0x0061e854.SelfSaveOKPaneVtableData.md) 0x0061e7a0-0x0061e854 | compiler-generated vtable data | SelfSaveOKPaneVtableData : reconstructable : 94% : very-strong : Exact 180-byte primary/secondary/timer COL and vtable region with complete items, targets, bytes, three construction-store groups, sole OnTimer slot, strict MapPane/MapRefreshDimmer boundaries, and nonduplicating class-declaration covered-by emission.`

**by-memory insert for UID0003JL under UID00025S immediately after UID0003IV and before UID00025T**

The dated 2026-08-17 read-only snapshot shows parent UID00025S at line 4647, existing predecessor UID0003IV `[0x0061e964,0x0061e9fc)` at line 4655, and following UID00025T `[0x0061eb08,0x0061ec10)` at line 4656. UID0003JL `[0x0061ea8c,0x0061eaa8)` belongs between those literal existing anchors. Because coverage is mutable supervisor-owned state, Gate 2 must freshly reread and confirm the same address-order context before insertion.

`        - [UID:0003JL][0x0061ea8c-0x0061eaa8.SelfSaveOKPaneSpacerString](by-memory/0x0061ea8c-0x0061eaa8.SelfSaveOKPaneSpacerString.md) 0x0061ea8c-0x0061eaa8 | pooled UTF-16 literal and alignment | SelfSaveOKPaneSpacerString : reconstructable : 94% : very-strong : Exact twelve-space UTF-16 literal plus two-byte alignment with six refs across MapPane inline construction, retained factory, and standalone constructor; source uses L\"            \" at use sites and emits only a compiler-pooling covered-by marker.`

No shared research tracker row is manually edited by B007. Generated tracker state should refresh through validator-owned workflows after accepted implementation.

## Follow-Up Actions

1. Supervisor performs fresh exact-artifact Gate 1/currentness and Gate 2A claim-by-claim verification against this callback revision and the named ordinary destinations.
2. Supervisor freshly rereads and applies exact manual coverage claims C0000NN-021..027, preserving the UID0003IV predecessor anchor and current address order.
3. Supervisor performs fail-closed Gate 2B I0000NN-001..008 against fresh attested state, preserving the exact I02 nine-row and I04 five-row final frame contracts.
4. If any ordinary, coverage, IDA, or report-currentness check fails, return this same report additively with the exact defect; do not adapt silently.
5. Lifecycle execution/archive remains supervisor-only. B007 does not run or probe `execute_report`.

## Confidence

- Whole-file ownership and source placement: very strong.
- Constructor/timer behavior and formal source: very strong.
- Class layout/inheritance/vtable disposition: very strong.
- Spacer payload/pooling/source disposition: very strong.
- Factory behavior/bounds/source family: very strong.
- Exact original factory name/registration mechanism: medium-high; resolved by explicit best-supported naming and a score cap.
- Recommended UID0000NN score: `94/94`; no unresolved issue justifies a lower code-eligibility state.

## Validator Results

- C0000NN-029: scoped `by-file/SelfSaveOKPane.md` command `000000025518`, timestamp `2026-08-17T14:42:18-04:00`, exit `0`, `ok: 1`; metadata read back `94/94`.
- C0000NN-031: scoped `by-class/SelfSaveOKPane.md` command `000000025520`, timestamp `2026-08-17T14:42:21-04:00`, exit `0`, `ok: 1`; metadata read back `94/95`.
- C0000NN-032: scoped factory command `000000025522`, timestamp `2026-08-17T14:42:26-04:00`, exit `0`, `ok: 1`; metadata read back `93/92`.
- C0000NN-033: scoped constructor/timer command `000000025524`, timestamp `2026-08-17T14:42:30-04:00`, exit `0`, `ok: 1`; metadata read back `94/95`.
- C0000NN-034: scoped vtable-type command `000000025527`, timestamp `2026-08-17T14:42:47-04:00`, exit `0`, `ok: 1`; metadata read back `94/95` and formal CPP changed from blank to block.
- C0000NN-035: scoped physical-vtable command `000000025530`, timestamp `2026-08-17T14:42:52-04:00`, exit `0`, `ok: 1`; metadata read back `94/95` and formal CPP changed from blank to block.
- C0000NN-036: scoped spacer command `000000025532`, timestamp `2026-08-17T14:43:28-04:00`, exit `0`, `ok: 1`; registered UID0003JL, read back `94/95`, owner `0000CX`, and formal CPP block.
- C0000NN-037: scoped `by-file/MapPane.md` command `000000025533`, timestamp `2026-08-17T14:43:33-04:00`, exit `0`, `ok: 1`; validator normalized two UID link labels but did not alter the accepted ownership meaning.
- C0000NN-038: final owning wait command `000000025534`, timestamp `2026-08-17T14:43:55-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`. The command rebuilt validator registry and refreshed validator-owned generated metadata/reports; B007 did not edit generated or coverage files manually.
- C0000NN-039 dated physical readback after C038 and deferred-queue stabilization: generated CPP SHA256 `687FCD2FDD63D339DE96915C146F99D4C9D75C414C71E41872DB3AD63A211B39`, 2,198 bytes, 61 physical lines, generated header command `000000025532`. It contains the exact four-include provider prologue, `CreateSelfSaveOKPane`, constructor, `OnTimer`, all three no-code markers, zero `Empty Emitter Marker` text, and zero source-body `sub_`/`dword_`/`unk_`/`asc_` placeholders.
- C0000NN-040 dated physical readback after C038 and deferred-queue stabilization: generated H SHA256 `F5319A29E9870076BD52745289B4D7CC4C8A24C2E184AD5DA4AE5AF7C9337643`, 752 bytes, 25 physical lines, generated header command `000000025532`. It contains the exact guard, TextEditPane include, fieldless TextBoxPane-derived class, constructor, protected virtual `OnTimer`, and `sizeof(SelfSaveOKPane) == 0x174` assertion.
- Generated identities are mutable validator-owned snapshots; fresh supervisor gates must reread them rather than treating these hashes as permanent authority.
- No report lifecycle/status/probe command was run. Manual coverage and IDA claims remain unchecked.

## Changed Files

- Agent-applied ordinary docs, each edited under a short B007 lease and released before the next file: `by-file/SelfSaveOKPane.md` SHA256 `8CE9BA3651B75CFE71B3D72FCA650A78761B5CDBDE8008D82E72ED6DF907C99D`, 20,031 bytes, 135 physical lines; `by-class/SelfSaveOKPane.md` SHA256 `2AF7E5ACF98E8ED29BC682970691AD15EA4B42A92D0AE5D19DAA08922B566442`, 18,677 bytes, 159 lines.
- Agent-applied exact source children: `by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md` SHA256 `AFE14C55315A5102875B93A5EEE21DCE1387D89E6A7E191E6C617E11F61402FB`, 19,133 bytes, 205 lines; `by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md` SHA256 `28857AB6AF3D0B8F605EA727481C80D2BCD391887626FD3EC47A94228F1FC9DF`, 15,723 bytes, 141 lines.
- Agent-applied compiler/data children: `by-type/by-vtable/SelfSaveOKPane_vtables.md` SHA256 `796FEB33ED1171A729D71E999D2E2625669C6BD2302462FD131CAB0210927597`, 9,283 bytes, 104 lines; `by-memory/0x0061e7a0-0x0061e854.SelfSaveOKPaneVtableData.md` SHA256 `CFE5E60F84AA1394AB7EED2E7753230E30A55D7363AD55A9D03BF79FF13E2C92`, 11,830 bytes, 102 lines; `by-memory/0x0061ea8c-0x0061eaa8.SelfSaveOKPaneSpacerString.md` SHA256 `1816E31762000B12E9D82C3267B300821B4EED28B6B52EEB44B79B96E5535E63`, 7,922 bytes, 78 lines.
- Agent-applied support clarification: `by-file/MapPane.md` SHA256 `1745BC0F670DD69744EBBAA7FF6DB70424180AE0B89E815A67BC84421E7BB451`, 211,559 bytes, 866 lines; validator command 000000025533 normalized two link labels in the new section.
- Validator-owned generated snapshots were physically reread but never edited by B007: `SelfSaveOKPane.cpp` and `.h` have the identities in Validator Results. The validator also refreshed project-level/generated metadata and reports as command-owned side effects.
- B007 did not edit any manual `-coverage-report.md`, IDA database, goal/notes file, shared tracker/audit/catalog, or lifecycle state. C0000NN-021..027 and I0000NN-001..008 remain proposed.

## Implementation Tracking Checklist

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C0000NN-001 | 0000NN | Whole-file inventory is one local factory, constructor, timer override, three compiler vtable facets, one pooled spacer literal, and one MapPane-owned inline duplicate. | high | Live ranges, vtable stores, xrefs, and complete support inventory. | by-file/SelfSaveOKPane.md / Proposed Contents | incorporate | applied_verified |
| [x] | C0000NN-002 | 0000NN | Raise file metadata to 94/94 while retaining path NexusTK/ui/dialogs/ and owner FILE. | high | Exhaustive source and boundary closure. | by-file/SelfSaveOKPane.md / metadata and Status | incorporate | applied_verified |
| [x] | C0000NN-003 | 0000CX | Raise class metadata to 94/95 and preserve owner/emitter 0000NN and position 1. | high | Exact fieldless layout and sole override proof. | by-class/SelfSaveOKPane.md / metadata and Status | incorporate | applied_verified |
| [x] | C0000NN-004 | 0000CX | Preserve the complete existing SelfSaveOKPane H declaration and include route exactly. | high | Base declaration, vtable comparison, allocation size, and generated H. | by-class/SelfSaveOKPane.md / formal H | already-present | applied_verified |
| [x] | C0000NN-005 | 0000CX | Replace class CPP prologue with the exact four provider includes and children route below. | high | Formal source dependencies and generated provider headers. | by-class/SelfSaveOKPane.md / formal CPP | incorporate | applied_verified |
| [x] | C0000NN-006 | 0001AY | Raise factory metadata to 93/92 and retain owner/emitter 0000NN. | high | Exact body and source route; original registration/name remains inferred. | UID0001AY metadata | incorporate | applied_verified |
| [x] | C0000NN-007 | 0001AY | Replace factory formal CPP with the exact allocation callback below. | high | Exact 0x120 body and duplicated construction behavior. | UID0001AY formal CPP | incorporate | applied_verified |
| [x] | C0000NN-008 | 0001AY | Record unrelated successor functions and exact boundary so they are excluded from SelfSaveOKPane. | high | Bounded disassembly through 0x00513a20 and padding. | UID0001AY range/history | incorporate | applied_verified |
| [x] | C0000NN-009 | 0001B0 | Raise constructor/timer metadata to 94/95 and retain owner/emitter 0000NN. | high | Exact two-function island and source-ready semantics. | UID0001B0 metadata | incorporate | applied_verified |
| [x] | C0000NN-010 | 0001B0 | Replace stale SetText calls with exact InsertText calls and preserve the three-text insertion order. | high | Current TextEditPane helper closure and exact call sequence. | UID0001B0 formal CPP and behavior | incorporate | applied_verified |
| [x] | C0000NN-011 | 0001B0 | Replace g_mainUiLayerSlots[1] with rootPaneLayerContext and preserve all rectangle/layer arguments. | high | Semantic global layout and exact operand address. | UID0001B0 formal CPP and dependencies | incorporate | applied_verified |
| [x] | C0000NN-012 | 0001B0 | Emit OnTimer as source-level multiple-inheritance C++ with removal and self-delete only for timer id zero. | high | Sole timer-vtable route and exact facet adjustment lowering. | UID0001B0 formal CPP and behavior | incorporate | applied_verified |
| [x] | C0000NN-013 | 0001YV | Raise vtable-group metadata to 94/95 and replace blank CPP with the covered-by marker below. | high | Complete three-facet comparison and compiler-generation proof. | UID0001YV metadata and formal CPP | incorporate | applied_verified |
| [x] | C0000NN-014 | 0002OU | Raise physical vtable-data metadata to 94/95 and replace blank CPP with the covered-by marker below. | high | Exact 180-byte region, COL cells, slots, and construction refs. | UID0002OU metadata and formal CPP | incorporate | applied_verified |
| [x] | C0000NN-015 | 0003JL | Raise spacer metadata to 94/95, fill Item Summary, and replace blank CPP with the pooled-literal covered-by marker below. | high | Exact 28-byte range and six use-site refs. | UID0003JL metadata, Item Summary, formal CPP | incorporate | applied_verified |
| [x] | C0000NN-016 | 0000L3 | Clarify that opcode 0x21 owns an inline duplicate in MapPane.cpp while the reusable class/method source remains SelfSaveOKPane-owned. | high | Exact 222-byte inline block and no helper call. | by-file/MapPane.md / SelfSave evidence | incorporate | applied_verified |
| [x] | C0000NN-017 | 0000NN | Preserve rejected SpelledPane, TextBoxPane, MapPane-child-class, raw-vtable-array, raw-literal-array, and aggregate-owner theories as superseded history. | high | Current owner graph and exact source-shape evidence. | target/support historical assumptions | historicalize | applied_verified |
| [x] | C0000NN-018 | 0000NN | Generated CPP must contain provider includes, factory, constructor, timer, and three no-code markers with no empty emitter. | high | Post-C038 physical generated CPP readback. | generated readback after callback | incorporate | applied_verified |
| [x] | C0000NN-019 | 0000NN | Generated H must remain the complete current 0x174 fieldless class declaration. | high | Current valid formal H and physical generated H. | generated readback after callback | already-present | applied_verified |
| [x] | C0000NN-020 | 0000NN | Do not create another header, split the file, or use a third-party import directive. | high | Existing complete provider and custom game source. | by-file/SelfSaveOKPane.md / Source Placement | already-present | applied_verified |
| [ ] | C0000NN-021 | 0000NN | Replace the manual by-file coverage row with the exact 94 percent row below. | high | Dated current row at line 251. | by-file/-coverage-report.md | incorporate | proposed |
| [ ] | C0000NN-022 | 0000CX | Replace the manual by-class coverage row with the exact 94 percent row below. | high | Dated current row at line 491. | by-class/-coverage-report.md | incorporate | proposed |
| [ ] | C0000NN-023 | 0001AY | Replace the manual by-memory factory row with the exact 93 percent row below. | high | Dated current row at line 2640. | by-memory/-coverage-report.md | incorporate | proposed |
| [ ] | C0000NN-024 | 0001B0 | Replace the manual by-memory constructor/timer row with the exact 94 percent row below. | high | Dated current row at line 2642. | by-memory/-coverage-report.md | incorporate | proposed |
| [ ] | C0000NN-025 | 0001YV | Replace the manual by-vtable row with the exact 94 percent row below. | high | Dated current row at line 123. | by-type/by-vtable/-coverage-report.md | incorporate | proposed |
| [ ] | C0000NN-026 | 0002OU | Replace the manual by-memory vtable-data row with the exact 94 percent row below. | high | Dated current row at line 4650. | by-memory/-coverage-report.md | incorporate | proposed |
| [ ] | C0000NN-027 | 0003JL | Insert the exact 94 percent spacer row immediately after UID0003IV and before UID00025T, nested beneath UID00025S. | high | The dated 2026-08-17 read-only by-memory snapshot places UID0003IV at `0x0061e964-0x0061e9fc` beneath UID00025S and the next row UID00025T at `0x0061eb08-0x0061ec10`; UID0003JL `0x0061ea8c-0x0061eaa8` belongs between those literal existing anchors. | by-memory/-coverage-report.md / after UID0003IV and before UID00025T | incorporate | proposed |
| [x] | C0000NN-028 | 0000NN | Incorporate all behavior, interactions, boundaries, negative evidence, and support dependencies without summary loss. | high | Rule 26 no-loss standard and complete report evidence. | all named ordinary docs | incorporate | applied_verified |
| [x] | C0000NN-029 | 0000NN | Run `python .\tools\validator.py --mode file --file by-file/SelfSaveOKPane.md --apply --queue-timeout 240`. | high | Literal scoped validator command for the primary file page. | by-file/SelfSaveOKPane.md / validator receipt | validate | applied_verified |
| [x] | C0000NN-030 | 0000NN | Keep g_pLanguageMan, g_pBackPane, MainUiLayerSlots, InsertText, AddToLayer, RemoveFromLayer, and ScheduleTimer in their existing source owners. | high | Current formal provider docs and exact call targets. | target dependency evidence | already-present | applied_verified |
| [x] | C0000NN-031 | 0000CX | Run `python .\tools\validator.py --mode file --file by-class/SelfSaveOKPane.md --apply --queue-timeout 240`. | high | Literal scoped validator command for the class page. | by-class/SelfSaveOKPane.md / validator receipt | validate | applied_verified |
| [x] | C0000NN-032 | 0001AY | Run `python .\tools\validator.py --mode file --file by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md --apply --queue-timeout 240`. | high | Literal scoped validator command for the factory page. | UID0001AY / validator receipt | validate | applied_verified |
| [x] | C0000NN-033 | 0001B0 | Run `python .\tools\validator.py --mode file --file by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md --apply --queue-timeout 240`. | high | Literal scoped validator command for the constructor/timer page. | UID0001B0 / validator receipt | validate | applied_verified |
| [x] | C0000NN-034 | 0001YV | Run `python .\tools\validator.py --mode file --file by-type/by-vtable/SelfSaveOKPane_vtables.md --apply --queue-timeout 240`. | high | Literal scoped validator command for the vtable-type page. | UID0001YV / validator receipt | validate | applied_verified |
| [x] | C0000NN-035 | 0002OU | Run `python .\tools\validator.py --mode file --file by-memory/0x0061e7a0-0x0061e854.SelfSaveOKPaneVtableData.md --apply --queue-timeout 240`. | high | Literal scoped validator command for the physical vtable page. | UID0002OU / validator receipt | validate | applied_verified |
| [x] | C0000NN-036 | 0003JL | Run `python .\tools\validator.py --mode file --file by-memory/0x0061ea8c-0x0061eaa8.SelfSaveOKPaneSpacerString.md --apply --queue-timeout 240`. | high | Literal scoped validator command for the spacer page. | UID0003JL / validator receipt | validate | applied_verified |
| [x] | C0000NN-037 | 0000L3 | Run `python .\tools\validator.py --mode file --file by-file/MapPane.md --apply --queue-timeout 240`. | high | Literal scoped validator command for the MapPane support page. | by-file/MapPane.md / validator receipt | validate | applied_verified |
| [x] | C0000NN-038 | 0000NN | Run final owning refresh `python .\tools\validator.py --mode file --file by-file/SelfSaveOKPane.md --apply --queue-timeout 240 --wait-generated`. | high | Literal final wait command after all scoped passes. | by-file/SelfSaveOKPane.md / final owner receipt | validate-wait | applied_verified |
| [x] | C0000NN-039 | 0000NN | Physically reread `auto-generated/NexusTK/ui/dialogs/SelfSaveOKPane.cpp` after C038 and prove the provider prologue, factory, constructor, timer override, three no-code markers, no empty emitter, and no raw placeholder names. | high | Required generated CPP physical reconciliation. | generated SelfSaveOKPane.cpp readback | verify-generated | applied_verified |
| [x] | C0000NN-040 | 0000CX | Physically reread `auto-generated/NexusTK/ui/dialogs/SelfSaveOKPane.h` after C038 and prove the complete guarded fieldless 0x174 class declaration with constructor and protected OnTimer override. | high | Required generated H physical reconciliation. | generated SelfSaveOKPane.h readback | verify-generated | applied_verified |
| [ ] | I0000NN-001 | 0000CX | Declare an opaque SelfSaveOKPane type before applying function signatures. | high | Current type query returns no SelfSaveOKPane type. | IDA local type catalog | incorporate | proposed |
| [ ] | I0000NN-002 | 0001AY | Pure-rename/type/comment the factory with the exact permitted addition of `unusedPacket +0x38 size 0x04 int`, preserving all eight original frame rows including `arg_4 +0x3c size 0x04 _DWORD`. | high | Exact body/bounds/bytes/xrefs plus disposable public-endpoint proof of the complete nine-row final frame and its sole permitted frame addition. | IDA 0x00513800 | incorporate | proposed |
| [ ] | I0000NN-003 | 0001B0 | Pure-rename and type the constructor, then add exact function and repeatable source comments. | high | Exact body, bounds, frame, bytes, and three construction-site equivalence. | IDA 0x005147d0 | incorporate | proposed |
| [ ] | I0000NN-004 | 0001B0 | Pure-rename/type/comment the timer override with exact `arg_0` to `timerId` rename/retype and exact `unused1 +0x0c` and `unused2 +0x10` integer-row additions. | high | Sole timer slot, exact body and multiple-inheritance adjustment, plus disposable public-endpoint proof of the complete five-row final frame. | IDA 0x005148e0 | incorporate | proposed |
| [ ] | I0000NN-005 | 0001YV | Add exact regular comments to the primary COL cell and vtable base without changing data. | high | Exact cells, names, bytes, and three construction refs. | IDA 0x0061e7a0 and 0x0061e7a4 | incorporate | proposed |
| [ ] | I0000NN-006 | 0001YV | Add exact regular comments to the secondary COL cell and vtable base without changing data. | high | Exact cells, names, bytes, and three construction refs. | IDA 0x0061e818 and 0x0061e81c | incorporate | proposed |
| [ ] | I0000NN-007 | 0001YV | Add exact regular comments to the timer COL, vtable base, and OnTimer slot without changing data. | high | Exact cells, timer target, bytes, and xrefs. | IDA 0x0061e848 through 0x0061e850 | incorporate | proposed |
| [ ] | I0000NN-008 | 0003JL | Recreate the named 26-byte literal item, immediately apply its global `const wchar_t[13]` type with `set_type`, and add exact address comments while preserving alignment and refs. | high | Disposable public-endpoint proof: `make_data` yields the correct named item with blank displayed type, and mandatory `set_type` yields the exact array-type readback; exact bytes, alignment, and six inbound refs remain protected. | IDA 0x0061ea8c | incorporate | proposed |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000025742","destination_path":"executed-b-agent-research/B007/0000NN-SelfSaveOKPane-file-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0000NN-SelfSaveOKPane-file-source-quality.md","timestamp":"2026-08-17T18:37:31-04:00","uid":"0000NN"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
