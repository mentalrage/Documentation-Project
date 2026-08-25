** TARGET-REPORT-UID:0002S4 **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002S4 ItemWhoInputPane Scalar Deleting Destructor Empty-Emitter Source-Quality Report

## Finalized Report / Current Recommendation

- Target: [UID:0002S4] `by-memory/0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor.md`.
- Current recommendation: keep [UID:00006X] `ItemWhoInputPane` as the direct semantic owner, keep the formal C++ block blank, and repair the empty-emitter defect by reclassifying this page as non-emitting compiler scalar-delete support.
- Final disposition: compiler-generated scalar deleting destructor wrapper / rebuild recognition page. The source-authored destructor C++ belongs on [UID:0001L5] `by-memory/0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor.md`; UID0002S4 should not emit a function body or a covered-by marker.
- Required action if accepted: set UID0002S4 `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, keep `CANONICAL_OWNER:00006X`, keep `EMITTER_POSITION_OPTIONAL:` blank, keep formal `RECONSTRUCTION_CPP` empty, and update target/class/file/ordinary-destructor support prose with the current MCP session `279422f0` proof and no-code rationale.
- Confidence: high. Current IDA MCP session `279422f0` confirms the exact function body, vtable/thunk route, duplicated ordinary destructor cleanup, scalar delete flags, operator-delete/guard path, and post-range padding.

## Target

- Target UID: `0002S4`.
- Target path: `by-memory/0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor.md`.
- Assignment ID: `B008-report-0002S4-ItemWhoInputPaneScalarDeletingDestructor-empty-emitter-20260629`.
- Queue source: `auto-generated/-ag-research-tracker.md` Files With Empty Emitters.
- Current generated marker: `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`, validator-command-id `000000000776`, refreshed `2026-06-29T13:18:59-04:00`, has `// UID:0002S4 ... Empty Emitter Marker`.

## Current Target State

- Current metadata in target doc: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00006X`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006X`, blank optional emitter position, blank formal C++ block, `Nested:0`.
- Current prose already says the reconstruction block intentionally remains empty and that ordinary source destructor C++ belongs on [UID:0001L5], not on this scalar deleting wrapper.
- Current contradiction: the prose says no source C++ should emit here, but the metadata still makes UID0002S4 an eligible class-routed emitter through [UID:00006X] to [UID:0000OH] `TargetSelectionInputPanes.cpp`. That metadata/prose mismatch is the immediate generated empty-marker cause.
- Related support docs checked: `by-class/ItemWhoInputPane.md`, `by-file/TargetSelectionInputPanes.md`, [UID:0001L4] ItemWho aggregate, [UID:0002S1] constructor, [UID:0001L5] ordinary destructor, [UID:0002S2] key handler, [UID:0002S3] mouse handler, [UID:0001IJ] state helper, [UID:0002AB] saved-target globals, scalar-deleting siblings [UID:0001NK], [UID:0001ND], and [UID:0001NL].

## Evidence Checked

- Skill/project rules: `ntk-b-agent-workflow` skill, `b-agent-research-and-implementation-workflow.md`, `score-blocker-audit-standard.md`, and `by-structure.md` IDA MCP output discipline.
- Current MCP availability: `idb_list` with session `279422f0` returned active worker PID `16380`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` returned `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, strings cache size `2067`.
- MCP target checks in session `279422f0`: `lookup_funcs`, `decompile`, bounded `disasm`, `xrefs_to`, `xref_query`, `callees`, and `get_bytes` for `0x005b7a20`, adjacent boundaries, vtable cells, adjustor thunks, ordinary destructor sibling, state helper, saved-target globals, and base/delete helpers.
- Numeric conversions: `tools/int_convert.py` JSON batch verified `0xcc` is `204` decimal, `0x10c` is `268` decimal, `0xa0` is `160` decimal, `0xa4` is `164` decimal, `0xfa` is `250` decimal, `0x28de6c` is `2678380` decimal, `0x69bf20` is `6930208` decimal, and `0x69bf24` is `6930212` decimal.
- Generated/read-only evidence: `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` and `auto-generated/-ag-research-tracker.md`.
- Old report search terms: `0002S4`, `005b7a20`, `005b7aec`, `ItemWhoInputPaneScalarDeletingDestructor`, `ItemWhoInputPane`, `00006X`, and `TargetSelectionInputPanes`.
- Relevant old reports opened/used as leads: `executed-b-agent-research/B013/0001L4-ItemWhoInputPane-source-quality.md` and `executed-b-agent-research/B001/0001IJ-ItemWhoInputPaneStateSetFlag-source-quality.md`. B013 already placed source destructor C++ on UID0001L5 and called UID0002S4 a scalar wrapper/no-source-C++ support page. B001 already recorded UID0002S4 as an item state-clear caller of UID0001IJ.

## Positive Evidence Summary

- `lookup_funcs` in session `279422f0` reports `0x005b7a20` as `sub_5B7A20`, size `0xcc` (`204` decimal, Verified with `int_convert.py`), ending at `0x005b7aec`; `0x005b7aec` is not a function and `0x005b7af0` starts the next function `sub_5B7AF0`.
- `get_bytes 0x005b7a20 size 204` returns the exact wrapper bytes beginning `55 8b ec 6a ff 68 00 68 5f 00 ...` and ending `... 59 5e 8b e5 5d c2 04 00`; `get_bytes 0x005b7aec size 4` returns `cc cc cc cc`.
- Decompilation shows three `ItemWhoInputPane` vtable restores, saved-target reconciliation, item state clear, base cleanup, and scalar delete flag dispatch:
  - primary vtable at `0x005b7a45` writes `0x0062f29c`;
  - secondary vtable at `0x005b7a4b` writes `0x0062f2ec`;
  - tertiary vtable at `0x005b7a55` writes `0x0062f31c`;
  - `unk_69BF20` is read at `0x005b7a64`, optionally replaced by `unk_69BF24` when config byte `+0x28de6c` equals `1`, and written back at `0x005b7a89`;
  - `sub_4B85F0(unk_67A874, 3)` at `0x005b7a8f` fetches state slot `3`;
  - `sub_57D0A0(state, 0)` at `0x005b7a96` clears `ItemWhoInputPaneState::SetInputModeFlag(false)`;
  - `sub_4F2010(Block)` at `0x005b7a9d` performs shared `LineInputPane`/base cleanup;
  - scalar-delete tests at `0x005b7aa5-0x005b7aab` route ordinary bit-1 delete to `sub_4F4AC0(Block)` at `0x005b7aae` and the bit-4 guarded path to `push 0x10c; push esi; call @_guard_check_icall_nop@4` at `0x005b7aca-0x005b7ad0`.
- `callees` reports UID0002S4 calls `sub_4B85F0`, `sub_57D0A0`, `sub_4F2010`, `sub_4F4AC0`, and `@_guard_check_icall_nop@4`. The ordinary destructor [UID:0001L5] calls only `sub_4B85F0`, `sub_57D0A0`, and `sub_4F2010`.
- `xrefs_to 0x005b7a20` returns exactly three refs: code jumps from adjustor thunks at `0x005b7810` and `0x005b781b`, plus the primary vtable data ref at `0x0062f29c`. No direct static caller was found.
- `get_bytes 0x005b780a size 22` returns the two thunk bodies: `81 e9 a0 00 00 00 e9 0b 02 00 00` and `81 e9 a4 00 00 00 e9 00 02 00 00`, i.e. subtract `0xa0` (`160` decimal, Verified with `int_convert.py`) or `0xa4` (`164` decimal, Verified with `int_convert.py`) from `ecx` and jump to `0x005b7a20`.
- Vtable cell bytes confirm routes: `get_bytes 0x0062f29c size 4` is `20 7a 5b 00` -> `0x005b7a20`; `0x0062f2ec` is `0a 78 5b 00` -> `0x005b780a`; `0x0062f31c` is `15 78 5b 00` -> `0x005b7815`.
- Ordinary destructor [UID:0001L5] already emits first-draft source C++ for `ItemWhoInputPane::~ItemWhoInputPane()` with the target-save copy and `ItemWhoInputPaneState::SetInputModeFlag(false)`. UID0002S4 duplicates that source cleanup and adds compiler delete wrapper behavior.

## Negative Evidence Summary

- No ordinary source-level caller reaches `0x005b7a20`; current refs are vtable data and adjustor-thunk jumps.
- No unique handwritten ItemWho semantics exist in UID0002S4 beyond the ordinary destructor body already emitted on UID0001L5. The remaining branches are scalar deleting destructor ABI, runtime delete/free behavior, and guarded size/object support.
- A formal covered-by marker is not the best repair. Covered-by markers are appropriate for retained source-authored raw helper islands whose behavior is intentionally emitted by an active source function. UID0002S4 is not a retained source helper; it is compiler-generated destructor wrapper glue. Emitting even a marker would keep compiler glue in the generated source file as if it were a source-authored range.
- Direct file emission through [UID:0000OH] is rejected for UID0002S4. `TargetSelectionInputPanes.cpp` should contain source constructor/destructor/handler bodies and source-declared static data, not compiler scalar-deleting wrappers.
- Explicit source calls to `sub_4F2010`, explicit vtable stores, explicit `operator delete`, explicit guarded-delete helper calls, scalar-delete flag checks, or size `0x10c` should not be copied into source C++ for UID0002S4. The C++ class destructor and C++ delete expression/compiler should regenerate the wrapper.
- `ItemActionInputPanes`, `LineInputPane`, `MapPane`, `UserPane`, `ItemWhoInputPaneState`, saved-target global pages, and IDA DB edits are rejected as direct ownership/repair routes. They are dependencies or documentation evidence, not the source owner/emitter fix.

## Heuristic / Inference Reanalysis And Validation

- Source-shape inference: scalar deleting destructors are compiler/runtime ABI support generated from class destructor declarations and delete expressions. The wrapper is important for binary reconstruction evidence, but it is not a distinct handwritten NexusTK source routine.
- Validation against current evidence: the body begins by duplicating the ordinary destructor cleanup already represented on UID0001L5, then diverges only into scalar-delete bit handling, free call, guarded size path, and `retn 4`. That is exactly compiler wrapper shape, not source-authored game logic.
- Existing documentation assumption validated: B013's source-quality report correctly placed ordinary source destructor C++ on UID0001L5 and kept UID0002S4 as wrapper documentation. The current empty-emitter queue shows B013 did not fully close the metadata route, not that UID0002S4 needs code.
- Existing sibling caveat: scalar sibling pages [UID:0001NK], [UID:0001ND], and [UID:0001NL] still show `RECONSTRUCTABLE:TRUE` with blank formal C++ in their current docs. That is a broader scalar-wrapper policy cleanup opportunity, but this assignment is target-specific. Their current metadata should not force UID0002S4 to keep an invalid emitter route after current MCP proves a no-source wrapper disposition.
- Rejected alternative `RECONSTRUCTABLE:TRUE` plus blank C++: this is the current defect. It leaves UID0002S4 as an empty emitter in `TargetSelectionInputPanes.cpp`.
- Rejected alternative `RECONSTRUCTABLE:TRUE` plus covered-by marker to UID0001L5: this would remove the empty marker but still emit compiler-wrapper coverage into source output. The stronger source-quality fix is to make UID0002S4 non-emitting and leave source destructor coverage on UID0001L5.
- Rejected alternative body C++ on UID0002S4: duplicates `ItemWhoInputPane::~ItemWhoInputPane()` and adds decompiler/compiler details that a mid-2000s developer would not hand-write.

## IDA MCP Facts

| Fact | Current evidence |
| --- | --- |
| Active session | `idb_list` session `279422f0`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `16380`, active worker backend. |
| Health | `server_health` `status:ok`, imagebase `0x400000`, auto-analysis/Hex-Rays/strings cache ready. |
| Function bounds | `0x005b7a20` `sub_5B7A20`, size `0xcc`; exclusive end `0x005b7aec`; next function `0x005b7af0`. |
| Bytes/padding | Function bytes read for all `204` bytes; `0x005b7aec-0x005b7af0` is four `0xcc` bytes. |
| Decompile | vtable restores, target-save copy, state clear, base cleanup, scalar delete branch, delete/free call, guarded size path. |
| Disassembly | 66 instructions; vtable writes at `0x005b7a45`, `0x005b7a4b`, `0x005b7a55`; state clear at `0x005b7a96`; base cleanup at `0x005b7a9d`; scalar-delete flag tests at `0x005b7aa5-0x005b7aab`; `sub_4F4AC0` at `0x005b7aae`; guarded `0x10c` path at `0x005b7aca-0x005b7ad0`. |
| Xrefs to wrapper | `0x005b7810` thunk jump, `0x005b781b` thunk jump, `0x0062f29c` vtable data cell; total `3`. |
| Thunks | `0x005b780a` subtracts `0xa0` and jumps to `0x005b7a20`; `0x005b7815` subtracts `0xa4` and jumps to `0x005b7a20`. |
| Vtable cells | `0x0062f29c -> 0x005b7a20`, `0x0062f2ec -> 0x005b780a`, `0x0062f31c -> 0x005b7815`. |
| Globals | `dword_69BF20` refs at `0x005b7a64`/`0x005b7a89`; `dword_69BF24` ref at `0x005b7a7b`; current docs name these `s_spellWhoTargetId` and `s_itemWhoTargetId`. |
| Callees | UID0002S4 calls `sub_4B85F0`, `sub_57D0A0`, `sub_4F2010`, `sub_4F4AC0`, and `@_guard_check_icall_nop@4`; ordinary destructor calls only the first three. |

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x005aec60-0x005aed3d` | [UID:0002S1] constructor | Source constructor `ItemWhoInputPane::ItemWhoInputPane(unsigned char itemSlot)` | TRUE | [UID:00006X] | `88/90` | Source C++ present. |
| `0x005aed40-0x005aedcb` | [UID:0001L5] ordinary destructor | Source destructor `ItemWhoInputPane::~ItemWhoInputPane()` | TRUE | [UID:00006X] | `88/90` | Source C++ present; covers destructor semantics duplicated by UID0002S4. |
| `0x005aedd0-0x005aefaf` | [UID:0002S2] key handler | Source key virtual | TRUE | [UID:00006X] | `88/90` | Source C++ present. |
| `0x005af050-0x005af2e7` | [UID:0002S3] mouse handler | Source mouse virtual | TRUE | [UID:00006X] | `88/90` | Source C++ present. |
| `0x005b780a-0x005b7820` | by-memory ignored thunk row / aggregate notes | Two adjustor thunks to UID0002S4 | FALSE / ignored | ItemWho vtable facets | ignored | Compiler-generated thunks, not source C++. |
| `0x005b7a20-0x005b7aec` | [UID:0002S4] target | Scalar deleting destructor wrapper | Recommend FALSE | [UID:00006X] | recommend `89/91` | Keep as documentation, remove emitter route. |
| `0x005b7aec-0x005b7af0` | padding | Four `0xcc` bytes | FALSE | none | not applicable | Alignment before next scalar destructor. |

## Ranked Ownership Analysis

### 1. [UID:00006X] ItemWhoInputPane

- Evidence for: vtable writes are `ItemWhoInputPane` vtable cells; thunks are ItemWho non-primary destructor adjustors; the wrapper duplicates `ItemWhoInputPane` ordinary destructor state cleanup; saved target globals and state helper match the ItemWho class cluster.
- Evidence against: the scalar deleting wrapper itself is compiler-generated, not source-authored class method C++.
- Decision: keep `CANONICAL_OWNER:00006X` for documentation/review, but clear reconstructable/emitter metadata.

### 2. [UID:0000OH] TargetSelectionInputPanes

- Evidence for: this is the source-file route for ItemWho source methods and shared target-selection globals.
- Evidence against: direct file ownership/emission would place compiler ABI glue into `TargetSelectionInputPanes.cpp`; the source file should receive UID0001L5's destructor body, not UID0002S4.
- Decision: keep as indirect source-route context only; do not use as direct emitter for UID0002S4.

### 3. [UID:0001L5] Ordinary Destructor

- Evidence for: UID0001L5 contains the source-authored destructor cleanup duplicated by UID0002S4.
- Evidence against: UID0001L5 is a by-memory method page, not the owner of the compiler wrapper. A covered-by marker from UID0002S4 to UID0001L5 would still emit wrapper coverage into source output.
- Decision: link UID0001L5 as the source destructor home and no-code proof, not as an emitter target for UID0002S4.

### Rejected Owners

- `LineInputPane`: owns base cleanup reached by `sub_4F2010`, not ItemWho destructor wrapper ownership.
- `ItemWhoInputPaneState`: owns `sub_57D0A0`, not the destructor wrapper.
- `TargetSelectionSavedTargetGlobals`: owns `dword_69BF20`/`dword_69BF24`, not the wrapper.
- `ItemActionInputPanes` / inventory dispatch: launches ItemWho flow but does not own target-selection class destructor ABI.
- `CANONICAL_OWNER:NONE`: rejected because semantic class ownership is strong even though emission is not applicable.

## Source Placement

- Recommended source placement for actual handwritten C++ remains `NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` through [UID:0000OH] for [UID:0001L5] and other source-bearing ItemWho pages.
- UID0002S4 should have no generated source placement. It is compiler/runtime output regenerated from the class destructor and delete semantics.
- The generated file should no longer include a UID0002S4 empty marker after metadata repair and target validation with `--wait-generated`. Other unrelated empty markers in `TargetSelectionInputPanes.cpp` are outside this assignment.

## Range / Split / Padding / Reclassification Analysis

- No split is required. The exact function range is `0x005b7a20-0x005b7aec`, and the following `0x005b7aec-0x005b7af0` bytes are four `0xcc` alignment bytes.
- The two non-contiguous adjustor thunks at `0x005b780a-0x005b7820` remain compiler thunk/ignored evidence, not children to emit.
- Reclassification is required: UID0002S4 should become non-emitting compiler-wrapper documentation while preserving class ownership and detailed behavior evidence.

## First-Draft C++ Recommendation / No-Code Proof

- Eligible for draft C++: no.
- Recommended formal `RECONSTRUCTION_CPP CODE` content: keep both inline and multiline formal C++ blocks blank.
- Exact no-code proof: UID0002S4 is a compiler scalar deleting destructor wrapper. Current MCP session `279422f0` proves the body duplicates UID0001L5 source destructor cleanup, then performs scalar-delete flag tests, `operator delete`/free dispatch, guarded size `0x10c` (`268` decimal, Verified with `int_convert.py`) support, SEH/security-cookie wrapper mechanics, and `retn 4`. Those are compiler/runtime ABI details, not source-authored NexusTK C++.
- Reason a covered-by marker should not be emitted: UID0002S4 is not a retained raw helper whose source behavior is intentionally covered by an active source function. The correct source home is UID0001L5; UID0002S4 should be documentation-only.

## Score And Metadata Recommendation

- Current target metadata: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00006X`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006X`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
- Recommended target metadata: `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:00006X`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++, `Nested:0`.
- Rationale for score movement: current MCP evidence closes the named empty-emitter blocker, refreshes exact bytes/padding/vtable/thunk/callee facts, and resolves the no-code disposition as metadata reclassification rather than missing C++. Completion should rise modestly because the implementation path is now fully specified; confidence should rise because current IDA session `279422f0` independently reconfirms the wrapper-only interpretation.
- Reason not higher: original source symbols and exact class declaration are not recovered, and scalar-wrapper policy has similar unaddressed sibling pages outside this assignment. `95+` is not justified.

## Recommended Target Doc Changes

Target path: `by-memory/0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor.md`

- Change metadata to `COMPLETION:89`, `CONFIDENCE:91`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`; keep `CANONICAL_OWNER:00006X`, blank optional emitter position, blank formal C++, `Nested:0`.
- Update status/disposition from "reconstructable compiler scalar deleting destructor wrapper" to documentation-only/non-emitting compiler scalar deleting destructor wrapper.
- Replace any stale "reconstructable project code" or final-threshold rationale with the current no-source-C++ proof: source destructor C++ belongs on UID0001L5, and UID0002S4's remaining logic is compiler scalar-delete/free/guard support.
- Add current MCP session `279422f0` evidence: `server_health` OK, exact function range, `0xcc` size (`204` decimal, Verified with `int_convert.py`), bytes and four-byte `0xcc` padding, decompile, 66-instruction disassembly, xrefs, vtable cells, thunk bytes, callee set, ordinary destructor comparison, and `int_convert.py` conversions.
- Preserve rejected alternatives and negative evidence: no direct static callers, do not emit ordinary destructor C++, do not emit a covered-by marker, do not write explicit vtable stores/base cleanup/free/delete flag C++, do not reparent to file/global/state/helper owners, and do not edit the IDA DB.

## Recommended Support Doc Changes

Support path: `by-class/ItemWhoInputPane.md`

- Update the UID0002S4 method row and emission policy to say the scalar deleting destructor is compiler-generated wrapper documentation, directly owned by `ItemWhoInputPane` for review, non-emitting, and source destructor C++ remains on UID0001L5.
- Leave class score unchanged unless the implementer finds the page needs a narrowly justified score note. Current class already documents the source-ready child method policy at `88/90`.

Support path: `by-file/TargetSelectionInputPanes.md`

- Update the ItemWho proposed-contents/source-route row to state UID0002S4 is non-emitting compiler scalar-delete support and should disappear from generated `TargetSelectionInputPanes.cpp` after validator refresh. Preserve the file route for source-bearing ItemWho constructor/destructor/key/mouse/object-list/clear/helper pages.
- Leave file score unchanged; this is a routing cleanup for one compiler wrapper, not a whole-file audit.

Support path: `by-memory/0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor.md`

- Add a short scalar-wrapper separation note if not already present at accepted detail: UID0001L5 is the source-authored destructor body; UID0002S4 duplicates this cleanup in compiler-generated scalar delete glue and should be non-emitting.
- No metadata change needed unless the implementer finds direct contradiction.

Support paths already sufficient unless contradictions are found:

- `by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md` already records UID0002S4 as a clear-to-`0` caller.
- `by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md` already records `s_spellWhoTargetId`/`s_itemWhoTargetId`.
- [UID:0001L4] aggregate already says UID0002S4 remains support/no-formal-C++.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | Current MCP session is `279422f0`, health OK for `NexusTK.exe.i64`, imagebase `0x400000`, Hex-Rays and strings cache ready. | High | `idb_list`, `server_health`. | UID0002S4 Evidence Notes | applied | UID0002S4 Evidence Notes now cite session `279422f0` and `server_health` OK. |
| C2 | UID0002S4 exact function is `0x005b7a20-0x005b7aec`, `sub_5B7A20`, size `0xcc` / `204` decimal; `0x005b7aec` is not a function and `0x005b7af0` starts next function. | High | MCP `lookup_funcs`, `get_bytes`, `int_convert.py`. | UID0002S4 Status / Evidence Notes | applied | UID0002S4 Status/Evidence now records exact range, function name, `0xcc`/`204`, and next-prologue padding; target validator `000000000827` returned `ok: 1`. |
| C3 | `0x005b7aec-0x005b7af0` is four `0xcc` padding bytes. | High | MCP `get_bytes 0x005b7aec size 4`. | UID0002S4 Range/Padding | applied | UID0002S4 Evidence Notes records `cc cc cc cc` post-function padding. |
| C4 | The wrapper restores three ItemWho vtable facets at `0x005b7a45`, `0x005b7a4b`, `0x005b7a55`; vtable cells are `0x0062f29c -> 0x005b7a20`, `0x0062f2ec -> 0x005b780a`, and `0x0062f31c -> 0x005b7815`. | High | MCP decompile/disasm/get_bytes/xrefs. | UID0002S4 Evidence / Access sites | applied | UID0002S4 Evidence and Access sites record the three stores and vtable-cell refresh. |
| C5 | The target reconciles `s_spellWhoTargetId`/`s_itemWhoTargetId` via config byte `+0x28de6c`, clears ItemWho state slot `3` through `sub_57D0A0(state,0)`, and calls base cleanup `sub_4F2010`. | High | MCP decompile/disasm/callees/xrefs; support docs UID0001IJ and UID0002AB. | UID0002S4 Evidence; class/file support | applied | UID0002S4 Evidence records saved-target reconciliation, state clear, and base cleanup; class/file support preserves source route. |
| C6 | The only UID0002S4 behavior not already source-covered by UID0001L5 is compiler scalar delete/free/guard support: bit tests, `sub_4F4AC0`, guarded size `0x10c` / `268` decimal. | High | MCP decompile/disasm/callees; UID0001L5 comparison; `int_convert.py`. | UID0002S4 Reconstruction / No-code proof | applied | UID0002S4 Reconstruction/Evidence and UID0001L5 support note record scalar-delete separation and `0x10c`/`268`. |
| C7 | `xrefs_to 0x005b7a20` has exactly two thunk jumps (`0x005b7810`, `0x005b781b`) and one vtable data ref (`0x0062f29c`); no ordinary static caller route exists. | High | MCP `xrefs_to` and `xref_query`. | UID0002S4 Evidence / Negative evidence | applied | UID0002S4 Evidence records thunk jumps, vtable data ref, and no ordinary source caller route. |
| C8 | Formal C++ for UID0002S4 must remain blank; do not insert destructor C++ or a covered-by marker. | High | Wrapper-only evidence, B013 source-quality decision, current generated empty marker cause. | UID0002S4 Reconstruction / metadata | applied | UID0002S4 metadata is `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++ block; Reconstruction rejects body and covered-by marker. |
| C9 | The source-authored destructor body belongs on UID0001L5 and is already present as `ItemWhoInputPane::~ItemWhoInputPane()`. | High | UID0001L5 target doc; MCP ordinary destructor comparison. | UID0002S4 Reconstruction; UID0001L5 support note | applied / already-present | UID0001L5 already had destructor C++; callback added scalar-wrapper separation wording there and in UID0002S4. |
| C10 | Empty emitter cause is metadata/prose mismatch: UID0002S4 says no source C++ but still has `RECONSTRUCTABLE:TRUE` and `EMITTER_UIDS:00006X`. | High | Target metadata; generated `TargetSelectionInputPanes.cpp` marker. | UID0002S4 Score/Metadata; by-file support | applied | UID0002S4 metadata now non-reconstructable/no emitter; by-file records the prior marker cause; generated `TargetSelectionInputPanes.cpp` refreshed at `2026-06-29 13:48:44` and UID0002S4 is absent. |
| C11 | Recommended metadata is `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:00006X`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank optional position, blank formal C++. | High | Score/source-quality reanalysis and current MCP proof. | UID0002S4 metadata | applied | UID0002S4 header now exactly matches the recommendation, with `Nested:0` preserved. |
| C12 | Class/file support should preserve ItemWho ownership/source route while stating UID0002S4 is non-emitting compiler wrapper support and should disappear from generated source after validator refresh. | High | by-class/by-file docs, generated output, current MCP. | `by-class/ItemWhoInputPane.md`; `by-file/TargetSelectionInputPanes.md` | applied | by-class UID0002S4 row/emission policy and by-file ItemWho route/proposed contents now state non-emitting wrapper support and expected generated marker removal; scores unchanged. |
| C13 | Rejected alternatives include direct file emission, covered-by marker, explicit base cleanup/vtable/free source code, LineInputPane/ItemWhoState/global ownership, and IDA DB edits. | High | Current evidence and by-structure source-shape rules. | UID0002S4 negative evidence; support docs as needed | applied | UID0002S4 Reconstruction/Changes preserve rejected alternatives; no IDA/generated/tool/coverage edits were made. |

## Open Questions With Attempted Resolution

- Exact original source spelling for destructor declaration/class fields: not recovered. This does not block the recommendation because UID0002S4 should not emit source C++; UID0001L5 already carries the source destructor draft with descriptive names.
- Project-wide scalar deleting destructor metadata policy: sibling pages still have reconstructable/blank-emitter states. This is outside the target-specific callback, but current UID0002S4 evidence supports a non-emitting repair now.
- Exact IDA type names: no IDA DB rename/type edit is requested. Source-facing names should remain in docs/generated C++ only.

## Validator / Generated Expectations

- Report-only pass: no validators run and no generated files edited.
- Implementation callback should run:
  - `python .\tools\validator.py --mode file --file by-memory\0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor.md --apply --queue-timeout 240 --wait-generated`
  - `python .\tools\validator.py --mode file --file by-class\ItemWhoInputPane.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-file\TargetSelectionInputPanes.md --apply --queue-timeout 240`
  - `python .\tools\validator.py --mode file --file by-memory\0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor.md --apply --queue-timeout 240`
- After the target validator with `--wait-generated`, inspect `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` read-only. UID0002S4 should no longer be an `Empty Emitter Marker` and should not appear as emitted source or a covered-by marker. Other unrelated empty markers may remain.

## Changed Files

- Created/modified in this report-only pass: `tools/leaser/Agents/Agent-B008/research/0002S4-ItemWhoInputPaneScalarDeletingDestructor-empty-emitter-source-quality.md`.
- No target/support by-* docs edited.
- No generated files edited.
- No leases taken.

## Implementation Tracking Checklist

- [x] Supervisor validation required before implementation. Proof: callback approved by supervisor for accepted UID0002S4 report on 2026-06-29.
- [x] Lease only files immediately before editing during callback; no leases were taken during report-only research. Proof: `leaser.py Agent-B008 lease ...` returned Success for the four edited by-* docs and this report before patching; release attempt after validators returned `No active lease` for each callback file, and `current_leases.md` showed `No active leases`.
- [x] Update `by-memory/0x005b7a20-0x005b7aec.ItemWhoInputPaneScalarDeletingDestructor.md` metadata to `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:00006X`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++ block, `Nested:0`. Proof: target header patched.
- [x] Update UID0002S4 status/reconstruction/evidence/range sections with current MCP session `279422f0`, health, exact range, `0xcc` size and bytes, four-byte padding, decompile, 66-instruction disassembly, xrefs, vtable cells, thunk bytes, callee comparison, and `int_convert.py` conversions. Proof: target Status, Reconstruction, Evidence Notes, Access sites, and Changes updated at report-level detail.
- [x] Preserve UID0002S4 no-source-C++ proof: source destructor C++ belongs on UID0001L5; UID0002S4 is compiler scalar-delete/free/guard wrapper support, not an emitted body and not a covered-by marker. Proof: target Reconstruction and class/file/UID0001L5 support text updated.
- [x] Preserve rejected alternatives and negative evidence: no direct static callers, no direct file emission, no explicit vtable/base cleanup/free/delete-flag source C++, no LineInputPane/ItemWhoInputPaneState/global/ItemActionInputPanes ownership, and no IDA DB edits. Proof: target Reconstruction/Changes explicitly reject these alternatives; no forbidden files edited.
- [x] Update `by-class/ItemWhoInputPane.md` UID0002S4 row/evidence/emission policy to call it non-emitting compiler scalar-delete support while keeping direct semantic owner [UID:00006X] and source destructor body on UID0001L5. Leave class score unchanged unless a concrete implementation-time contradiction requires a justified note. Proof: class score unchanged at `88/90`; row/evidence/emission policy patched.
- [x] Update `by-file/TargetSelectionInputPanes.md` ItemWho proposed contents/source-route text to say UID0002S4 is non-emitting scalar wrapper documentation and should disappear from generated `TargetSelectionInputPanes.cpp` after target validation; preserve source route for source-bearing ItemWho children. Leave file score unchanged. Proof: file score unchanged at `89/85`; File Role, Proposed Contents, and Changes patched.
- [x] Update `by-memory/0x005aed40-0x005aedcb.ItemWhoInputPaneDestructor.md` only as needed with scalar-wrapper separation wording: UID0001L5 is the source-authored destructor body; UID0002S4 duplicates cleanup inside compiler scalar-delete glue and should be non-emitting. No planned metadata change. Proof: Reconstruction, Evidence Notes, and Changes patched; metadata unchanged.
- [x] Confirm support docs `by-memory/0x0057d0a0-0x0057d0af.ItemWhoInputPaneStateSetFlag.md`, `by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md`, and [UID:0001L4] aggregate have no contradiction; no planned edits unless implementation-time contradiction is found. Proof: inspected these docs before editing; no contradiction found and no edits made.
- [x] Run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation`: target with `--wait-generated`, class page, file page, and ordinary destructor page. Proof: target validator command `000000000827` at `2026-06-29T13:47:59-04:00` returned `ok: 1` and `generated_refresh: completed`; class validator command `000000000829` at `2026-06-29T13:48:20-04:00` returned `ok: 1`; file validator command `000000000830` at `2026-06-29T13:48:30-04:00` returned `ok: 1`; UID0001L5 validator command `000000000831` at `2026-06-29T13:48:37-04:00` returned `ok: 1`.
- [x] Inspect generated `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` read-only after target `--wait-generated`: UID0002S4 should no longer be an Empty Emitter Marker and should not emit a marker/body. Proof: file LastWriteTime `2026-06-29 13:48:44`, length `32966`; read-only search for `0002S4|ItemWhoInputPaneScalarDeletingDestructor|sub_5B7A20|005b7a20` returned `UID0002S4_absent_from_generated_TargetSelectionInputPanes_cpp`.
- [x] Update this report's Claim And Incorporation Ledger during implementation callback with `applied`, `already-present`, `excluded-with-reason`, or `blocked` proof for every accepted claim. Proof: C1-C13 ledger rows updated with applied/already-present proof before validator batch.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0002S4-ItemWhoInputPaneScalarDeletingDestructor-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0002S4-ItemWhoInputPaneScalarDeletingDestructor-empty-emitter-source-quality.md","timestamp":"2026-06-29T13:52:12","uid":"0002S4"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
