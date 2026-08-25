** TARGET-REPORT-UID:0001MG **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# Source-quality report: [UID:0001MG] DropGiveInputPanes empty emitter

## Finalized Report / Implemented Disposition

[UID:0001MG] is not one recoverable C++ function or one source-level class body. It is the broad `0x005b44b0-0x005b538a` drop/give item-action input-pane address island: six prompt classes, fourteen IDA-modeled functions, retained raw packet helper islands, retained raw gold constructors, and padding. The direct source route through [UID:0000KC] `ItemActionInputPanes` is correct, but the current blank formal C++ block is misleading because generated output still reports UID0001MG as an `Empty Emitter Marker`.

Accepted and implemented disposition: keep [UID:0001MG] as a reconstructable aggregate/index under [UID:0000KC], keep owner/emitter [UID:0000KC], raise documentation state modestly to `COMPLETION:88`, `CONFIDENCE:90`, and insert a formal comment-only aggregate marker in `RECONSTRUCTION_CPP CODE` instead of a handwritten monolithic body. This follows the by-structure rule for reconstructable items whose code is intentionally covered by more exact children/support pages: do not leave the formal block empty, but do not invent source for a mixed range.

Implemented formal marker:

```cpp
// Split/index aggregate for the Drop/Give item-action input-pane range.
// Source for this address island belongs to exact DropAll/Drop/DropGold/GiveAll/Give/GiveGold class and helper pages under [UID:0000KC].
// Do not emit a synthetic monolithic DropGiveInputPanes body for this mixed range.
```

Do not set `RECONSTRUCTABLE:FALSE` in this pass. The range is source-bearing NexusTK project code, and its exact child/method/class pages still need to remain visible as source reconstruction work. The problem is not that the range is non-reconstructable; the problem is that this aggregate page should emit only an explicit no-monolithic-body marker while exact children carry real source.

## Target

- Target path: `by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md`
- Target UID: `0001MG`
- Assignment IDs: initial report `B012-report-0001MG-DropGiveInputPanes-empty-emitter-20260629`; implementation callback `B012-implement-0001MG-DropGiveInputPanes-20260629`.
- Lifecycle status: initial report-only research completed, supervisor accepted it, implementation callback completed, target/support by-* docs were edited, scoped validators ran, generated output was checked read-only, and leases were released.
- Implemented metadata: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000KC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KC`, formal C++ block contains the accepted comment-only aggregate marker.
- Generated proof after implementation: `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` header `validator-command-id: 000000000770`, `validator-refreshed-at: 2026-06-29T13:04:54-04:00`, line for UID0001MG shows `Completion:88 | Confidence:90` followed by the accepted marker. `Select-String -Pattern "UID:0001MG.*Empty Emitter Marker"` returned no matches.

## Current MCP Session

Required MCP evidence was collected from current live IDA MCP session `b2ae72ec`.

- `idb_list`: one active session, `session_id: b2ae72ec`, path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend `worker`, worker PID `16112`, `is_analyzing:false`.
- `server_health`: `status: ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, strings cache size `2067`.
- MCP tools used: `idb_list`, `server_health`, `lookup_funcs`, `int_convert`, `analyze_component`, `decompile`, `xrefs_to`, `entity_query`, `make_signature_for_range`, `find_bytes`, and `get_bytes`.
- `py_eval` was not available in this MCP tool set (`Method 'py_eval' not found`), so this report does not rely on it.

## Evidence Checked

Current docs and generated leads:

- Target: `by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md`
- Direct source root: `by-file/ItemActionInputPanes.md`
- Direct class support: `by-class/DropAllInputPane.md`, `by-class/DropInputPane.md`, `by-class/DropGoldInputPane.md`, `by-class/GiveAllInputPane.md`, `by-class/GiveInputPane.md`, `by-class/GiveGoldInputPane.md`
- Direct raw/constructor children sampled: `by-memory/0x005b4760-0x005b47dc.SendDropAllItemPacketRaw.md`, `by-memory/0x005b4af0-0x005b4b6c.SendDropItemPacketRaw.md`, `by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md`, `by-memory/0x005b4c50-0x005b4cb9.SendDropGoldPacketRaw.md`, `by-memory/0x005b4ef0-0x005b4f6c.SendGiveAllItemPacketRaw.md`, `by-memory/0x005b5230-0x005b52ac.SendGiveItemPacketRaw.md`, `by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md`, and `by-memory/0x005b5390-0x005b53f9.SendGiveGoldPacketRaw.md`
- Vtable support: `by-type/by-vtable/ItemActionInputPaneVtableFamily.md`
- Packet/global support: `by-global/g_packetSender.md`, `by-global/g_pCollectionData.md`
- Generated output lead: `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp`
- Generated tracker leads: `auto-generated/-ag-research-tracker.md` row for UID0001MG and `auto-generated/-ag-coverage-report-by-memory.md` row for UID0001MG.

Old report search terms:

- `0001MG`, `0x005b44b0`, `0x005b538a`, `DropGiveInputPanes`, `DropGive`, `DropAllInputPane`, `GiveAllInputPane`, `ItemActionInputPanes`.
- Searched `tools/leaser/Agents` and `executed-b-agent-research`.
- Relevant executed leads included B001 `000043-DropGoldInputPane-class-source-quality.md`, B008 `0003NZ-SendUseItemSlotPacketRaw-empty-emitter-source-quality.md`, and multiple implementation logs/notes that mention `ItemActionInputPanes.cpp`. These were used as leads only; current report conclusions are based on current docs and `b2ae72ec` MCP evidence.

## Current Function And Range Evidence

UID0001MG covers `0x005b44b0-0x005b538a`; `0xeda` is `3802` decimal (Verified with MCP `int_convert`). Current MCP confirms the documented modeled function starts and half-open ends:

| Range | MCP function result | Source role |
| --- | --- | --- |
| `0x005b44b0-0x005b4577` | `sub_5B44B0`, size `0xc7` | `DropAllInputPane` constructor |
| `0x005b4580-0x005b45ec` | `sub_5B4580`, size `0x6c` | `DropAllInputPane` key handler |
| `0x005b45f0-0x005b475c` | `sub_5B45F0`, size `0x16c` | `DropAllInputPane` submit/confirm |
| `0x005b47e0-0x005b48a7` | `sub_5B47E0`, size `0xc7` | `DropInputPane` constructor |
| `0x005b48b0-0x005b491c` | `sub_5B48B0`, size `0x6c` | `DropInputPane` key handler |
| `0x005b4920-0x005b4ae4` | `sub_5B4920`, size `0x1c4` | `DropInputPane` submit/gold route |
| `0x005b4bb0-0x005b4c4a` | `sub_5B4BB0`, size `0x9a` | `DropGoldInputPane` amount submit |
| `0x005b4cc0-0x005b4d87` | `sub_5B4CC0`, size `0xc7` | `GiveAllInputPane` constructor |
| `0x005b4d90-0x005b4dfc` | `sub_5B4D90`, size `0x6c` | `GiveAllInputPane` key handler |
| `0x005b4e00-0x005b4eee` | `sub_5B4E00`, size `0xee` | `GiveAllInputPane` submit/confirm |
| `0x005b4f70-0x005b5037` | `sub_5B4F70`, size `0xc7` | `GiveInputPane` constructor |
| `0x005b5040-0x005b50ac` | `sub_5B5040`, size `0x6c` | `GiveInputPane` key handler |
| `0x005b50b0-0x005b5223` | `sub_5B50B0`, size `0x173` | `GiveInputPane` submit/gold route |
| `0x005b52f0-0x005b538a` | `sub_5B52F0`, size `0x9a` | `GiveGoldInputPane` amount submit |

Current MCP also confirms raw starts inside the aggregate remain non-functions:

- `lookup_funcs 0x005b4760`, `0x005b4af0`, `0x005b4c50`, `0x005b4ef0`, and `0x005b5230` all return `Not a function`.
- `lookup_funcs 0x005b4b70` and `0x005b52b0` return `Not a function`, while successors `0x005b4bb0` and `0x005b52f0` are modeled functions.
- `xrefs_to` for raw helper starts `0x005b4760`, `0x005b4af0`, `0x005b4c50`, `0x005b4ef0`, and `0x005b5230` returns no cross-references.
- `xrefs_to` for raw constructor starts `0x005b4b70` and `0x005b52b0` returns no cross-references.

Current `get_bytes` samples confirm the existing padding/body split model:

- `0x005b475c` sample begins with four `0xcc` bytes, then a source-shaped helper body starting `55 8b ec 81 ec 84...`, then trailing `0xcc` bytes at the documented end.
- `0x005b4ae4` sample begins with twelve `0xcc` bytes, then a source-shaped drop item raw helper body, then four `0xcc` bytes before the raw DropGold constructor.
- `0x005b5223` sample begins with thirteen `0xcc` bytes, then a source-shaped give item raw helper body, then four `0xcc` bytes before the raw GiveGold constructor.
- `0x005b538a` sample is six `0xcc` bytes, proving clean padding after the UID0001MG end and before the adjacent `0x005b5390` give-gold raw helper outside this target range.

Current `make_signature_for_range 0x005b44b0-0x005b538a` returns a range signature and reports `unique:true`. The signature is very long because the range is a multi-function island; this supports identity but is not appropriate as a concise single-function signature in the target doc.

## Behavior Evidence

`analyze_component` on the fourteen modeled functions reports no internal call-graph edges between them, which is important for source shape: these are adjacent class methods and helper islands, not one coherent function body. Shared globals observed across the modeled functions include:

- `dword_67A748` / [UID:0000QK] `g_pCollectionData` stable alias / source-facing `g_pUserPane`, used in constructors, submit methods, and busy-gate checks.
- `dword_67A750` / [UID:0000RC] `g_pLanguageMan`, used for prompt lookup.
- `dword_67A7EC` / [UID:0000Q5] `g_packetSender`, used by direct lower-slot item/gold packet paths.
- `aAreYouSureYouW` at `0x00630a90`, used by drop confirmation paths.
- `aU` at `0x006191b0`, the `%u` parse format used by both gold submit methods.

Representative decompile evidence:

- `0x005b4920` (`DropInputPane` submit) reads one character, treats backslash `0x5c`, slash `0x2f`, or dollar `0x24` as a gold shortcut, allocates `0x108` / 264 bytes (Verified with MCP `int_convert`), looks up prompt id `7`, constructs the `NumberInputPane` base, and stores `DropGoldInputPane` vtables `0x0062fea4`, `0x0062fef4`, and `0x0062ff24`. Non-gold lower slots write opcode `0x08`, selected slot, mode `0`, local terminator, and send length `3`; higher slots call `CreateUserPaneDoubleParamCallback` at `0x005b4a05` with `UserPane::SendDropItemPacket` and all-items flag `false`, then construct a confirmation pane.
- `0x005b50b0` (`GiveInputPane` submit) reads one character, treats backslash `0x5c` or slash `0x2f` as the give-gold shortcut, allocates `0x108` / 264 bytes (Verified with MCP `int_convert`), looks up prompt id `0x2b` / `43` (Verified with MCP `int_convert`), constructs the `NumberInputPane` base, and stores `GiveGoldInputPane` vtables `0x00630048`, `0x00630098`, and `0x006300c8`. Non-gold slots create the give confirmation callback at `0x005b5198` with `UserPane::SendGiveItemPacket` and all-items flag `false`.
- `0x005b4bb0` (`DropGoldInputPane` submit) copies up to 15 wide characters, parses `%u`, checks byte `g_pUserPane + 0x3ec0` (`16064`, Verified with MCP `int_convert`), writes opcode `0x24`, writes amount through `0x005753f0`, writes a local-only zero after the amount, and queues length `5`.
- `0x005b52f0` (`GiveGoldInputPane` submit) has the same shape but writes opcode `0x2a` before the amount and queues length `5`.

The directly related docs already preserve the all-items/single-item confirmation route:

- DropAll call site `0x005b46d6` binds `UserPane::SendDropItemPacket(signed char,bool)` at `0x005ad7a0`, selected slot, and `m_allItems=true`.
- Drop call site `0x005b4a05` binds the same target with `m_allItems=false`.
- GiveAll call site `0x005b4ec0` binds `UserPane::SendGiveItemPacket(signed char,bool)` at `0x005ad720`, selected slot, and `m_allItems=true`.
- Give call site `0x005b5198` binds the same target with `m_allItems=false`.

## Vtable Evidence

Current `entity_query` over `0x0062fd80-0x006300d0` lists the direct drop/give vtable family:

- `0x0062fd8c`, `0x0062fddc`, `0x0062fe0c`: `DropAllInputPane`
- `0x0062fe18`, `0x0062fe68`, `0x0062fe98`: `DropInputPane`
- `0x0062fea4`, `0x0062fef4`, `0x0062ff24`: `DropGoldInputPane`
- `0x0062ff30`, `0x0062ff80`, `0x0062ffb0`: `GiveAllInputPane`
- `0x0062ffbc`, `0x0063000c`: `GiveInputPane` listed in the queried span; the third vtable starts adjacent to the queried family and is already documented by support pages.
- `0x00630048`, `0x00630098`, `0x006300c8`: `GiveGoldInputPane`

Current `xrefs_to` confirms source routes:

- `DropAllInputPane` vtables have data refs from constructor `0x005b44b0` at `0x005b44f7`, `0x005b44fd`, `0x005b4507`, plus command factory/dispatcher refs.
- `DropInputPane` vtables have data refs from constructor `0x005b47e0` at `0x005b4827`, `0x005b482d`, `0x005b4837`, plus command factory/dispatcher refs.
- `DropGoldInputPane` vtables have data refs from live inline creator `0x005b4920` at `0x005b4aaf`, `0x005b4ab5`, `0x005b4abf`, and retained raw constructor stores at `0x005b4b8f`, `0x005b4b97`, `0x005b4ba1`.
- `GiveAllInputPane` vtables have data refs from constructor `0x005b4cc0` at `0x005b4d07`, `0x005b4d0d`, `0x005b4d17`, plus command factory/dispatcher refs.
- `GiveInputPane` vtables have data refs from constructor `0x005b4f70` at `0x005b4fb7`, `0x005b4fbd`, plus command factory/dispatcher refs.
- `GiveGoldInputPane` vtables have data refs from live inline creator `0x005b50b0` at `0x005b51f8`, `0x005b51fe`, `0x005b5208`, and retained raw constructor stores at `0x005b52cf`, `0x005b52d7`, `0x005b52e1`.

This vtable evidence proves multiple separate classes inside the aggregate. It argues against any synthetic `DropGiveInputPanes` C++ body.

## Positive Evidence Summary

- The range and source route are real: current MCP confirms the active IDB, the exact half-open range, the fourteen modeled method functions, raw non-function helper/constructor islands, and padding samples.
- [UID:0000KC] is the correct source root: all six classes and retained helper/constructor children sit inside the direct item-action prompt source family and generated output route `NexusTK/ui/dialogs/ItemActionInputPanes.cpp`.
- The aggregate is source-bearing but mixed: it includes class constructors, key handlers, submit handlers, file-scope raw packet helpers, retained raw class constructors, and padding.
- Existing exact child pages already own important subranges: raw drop/give packet helpers and raw gold constructors are split and documented; two raw constructor children already emit formal constructor C++.
- Current generated output proves the empty-emitter symptom: UID0001MG appears as `Empty Emitter Marker` despite being a deliberately mixed aggregate.
- A comment-only formal aggregate marker is source-safe: it removes the misleading empty marker while not inventing a monolithic function/class body.

## Negative Evidence And Rejected Alternatives

Rejected alternative: handwritten `DropGiveInputPanes` body.

- There is no binary function named or shaped as `DropGiveInputPanes`.
- `analyze_component` reports fourteen separate modeled functions and no internal callgraph edges between them.
- Raw helper starts and raw constructor starts are not IDA functions and have no start xrefs.
- A handwritten monolithic body would either duplicate child method/helper source, cross by-memory range boundaries, or invent an original source construct unsupported by the binary.

Rejected alternative: `RECONSTRUCTABLE:FALSE` for UID0001MG.

- The range is not padding, compiler-only glue, or unrelated runtime code. It is entirely source-bearing NexusTK item-action prompt code and support islands.
- Exact children and class pages still need to represent source reconstruction. Marking the aggregate false would hide the fact that this address island is a real source family; the safer correction is an explicit comment-only aggregate marker.

Rejected alternative: clear `EMITTER_UIDS`.

- [UID:0000KC] remains the correct output root for this item-action source island. Clearing the emitter would make the page non-emitting by omission rather than explaining why it intentionally has no monolithic body.

Rejected alternative: attach UID0001MG to one of the classes.

- DropAll, Drop, DropGold, GiveAll, Give, and GiveGold are siblings in the same file. No single class owns all methods, raw helpers, constructors, and padding inside `0x005b44b0-0x005b538a`.

Rejected alternative: direct ownership by `UserPane`, `Socket`, `PacketBuffer`, `NumberInputPane`, `CharInputPane`, or `ConfirmInputPane`.

- These are dependencies, targets, or base/support classes. They do not own the drop/give prompt source island.

Rejected alternative: raw helper/source names with `Raw` as formal C++ suffix.

- `Raw` is useful in by-memory labels because IDA does not model some helper starts as functions. Current ItemActionInputPanes precedent emits source-facing helpers without `Raw` where helper C++ is accepted, such as [UID:0003NZ] `SendUseItemSlotPacket` and [UID:00042U] `SendChangeItemSlotPacket`.

Rejected alternative: leave UID0001MG as a blank empty-emitter marker.

- The target already clears the code-entry gate: reconstructable true, nonblank emitter route to [UID:0000KC], and `(86 + 88) / 2 = 87`.
- A target-specific no-code proof now exists: the page is mixed and should not own a body, but formal output can safely be a comment-only no-monolithic-body marker.

## Heuristic / Inference Reanalysis And Validation

Best source-shape inference: [UID:0001MG] is a range inventory / split-index page for the drop/give half of `ItemActionInputPanes.cpp`. The page should document the island and route generated output through [UID:0000KC], but its formal C++ must be comment-only. Exact method/helper/constructor pages and class pages should carry any real code or declarations.

Validation against current facts:

- The source module route is supported by current and historical docs, vtable family adjacency, command factory/dispatcher xrefs, and the existing generated file root.
- The no-monolithic-body conclusion is supported by current MCP: fourteen modeled functions, raw non-function islands, multiple class vtable triads, padding gaps, and no internal call graph that would make the aggregate one function.
- The score can improve modestly because current `b2ae72ec` evidence refreshes the older function map and confirms the exact source-shape reason for the empty marker. It should not reach `95+` because final method child splits, class declarations, base virtual names, and formal method C++ remain incomplete.

## Score And Metadata Recommendation

Target metadata recommendation for `by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md`:

- `COMPLETION`: `86` -> `88`
- `CONFIDENCE`: `88` -> `90`
- `CANONICAL_OWNER`: keep `0000KC`
- `RECONSTRUCTABLE`: keep `TRUE`
- `EMITTER_UIDS`: keep `0000KC`
- `RECONSTRUCTION_CPP CODE`: insert the accepted comment-only aggregate marker in the formal block

Score rationale:

- `+1 completion`: current MCP refresh validates the full range identity, modeled functions, raw non-functions, vtable family route, generated empty marker state, and aggregate/no-body policy.
- `+1 completion`: the report provides implementation-ready marker text and support-doc update plan rather than leaving the empty marker unresolved.
- `+2 confidence`: `b2ae72ec` confirms active session health, exact function sizes, raw start non-functions/no xrefs, decompile behavior, vtable xrefs, byte/padding samples, and generated output state.
- Keep below final-audit levels because exact by-memory method children for the modeled class methods are not all split/populated, direct class pages still use blank markers, and final base/virtual/member names are not fully settled.

## First-Draft C++ Recommendation / No-Code Proof

Do not emit a handwritten C++ body for UID0001MG. Insert only the formal comment marker:

```cpp
// Split/index aggregate for the Drop/Give item-action input-pane range.
// Source for this address island belongs to exact DropAll/Drop/DropGold/GiveAll/Give/GiveGold class and helper pages under [UID:0000KC].
// Do not emit a synthetic monolithic DropGiveInputPanes body for this mixed range.
```

Reason:

- This formal marker is not a side-section sample. It belongs in the target's formal `RECONSTRUCTION_CPP CODE` block if the supervisor accepts the report.
- It is source-safe because it explicitly blocks synthetic monolithic source while explaining why the aggregate is not empty by accident.
- It keeps all real source body work on exact child pages and class pages, consistent with current by-structure range rules.

## Recommended Target And Support Doc Changes

### Target: `by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md`

- Apply metadata changes: `COMPLETION:88`, `CONFIDENCE:90`; keep `CANONICAL_OWNER:0000KC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KC`.
- Replace the blank formal C++ block with the exact comment-only aggregate marker above.
- Update the `Item Summary` to remove stale A002 wording that says the child remains `78/82`; the current target is `86/88` and recommended `88/90`.
- Add a current `b2ae72ec` evidence subsection recording:
  - active IDB path/session health;
  - exact aggregate range `0x005b44b0-0x005b538a`, size `0xeda` / 3802 bytes (Verified with MCP `int_convert`);
  - modeled function map and raw non-function starts;
  - representative decompile evidence for `0x005b4920`, `0x005b50b0`, `0x005b4bb0`, and `0x005b52f0`;
  - vtable xref proof for all six classes;
  - byte samples for padding/raw helper/constructor boundaries;
  - generated empty marker proof and expected post-validation result.
- Add a `No Monolithic Aggregate Body` or equivalent section preserving the no-code proof and rejected alternatives.
- Keep the existing child rows; do not paste child C++ into the aggregate.

### Support: `by-file/ItemActionInputPanes.md`

- Add a UID0001MG note in the Drop/Give proposed-contents/boundary area explaining that the aggregate is an intentional split/index marker and should not emit a monolithic body.
- State that exact child/class pages carry real source for constructors/helpers/methods; UID0001MG only emits the comment marker.
- Preserve [UID:0000KC] as direct owner/emitter/source root.
- Record generated-output expectation that UID0001MG should no longer appear as `Empty Emitter Marker` after accepted implementation and target validation.

### Support: `by-class/DropAllInputPane.md`, `by-class/DropInputPane.md`, `by-class/GiveAllInputPane.md`, `by-class/GiveInputPane.md`

- Replace stale old-gate wording such as "blank until 95/95" with current code-entry policy/no-code rationale: class pages remain blank because exact method/declaration strategy is not ready, not because the old `95/95` threshold still applies.
- Cross-link the UID0001MG aggregate marker as the range inventory, while preserving [UID:0000KC] as source route.
- Do not insert class C++ in this callback unless the supervisor expands scope to exact method/class declaration work.

### Support: `by-class/DropGoldInputPane.md`, `by-class/GiveGoldInputPane.md`

- Minimal update only if needed: cross-link the UID0001MG aggregate marker and reaffirm that constructor source already lives on [UID:0001MH] / [UID:0001MI], while submit bodies still need exact method children before method C++.
- Do not replace their existing class-page no-code proof.

### Support: raw helper / constructor children

- No default edit required for existing child pages in this UID0001MG empty-emitter implementation. The target can be fixed without changing child pages.
- Optional future reports should handle empty emitters on raw helper pages such as [UID:0003FK], [UID:0003FL], [UID:0003FM], [UID:0003FN], and [UID:0003FO] individually. Do not fold that work into UID0001MG unless the supervisor explicitly expands scope.

### Vtable and global support

- `by-type/by-vtable/ItemActionInputPaneVtableFamily.md`: no default edit recommended; current target/support docs already use it as the vtable anchor. Edit only if implementation discovers a direct contradiction.
- `by-global/g_packetSender.md` and `by-global/g_pCollectionData.md`: no default edit recommended. They already document item-action consumers and the relevant `g_pUserPane + 0x3ec0` / packet sender roles.

## Generated Output Expectation

After accepted implementation and target validator with `--wait-generated`, inspect `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` read-only.

Expected:

- UID0001MG no longer appears as `Empty Emitter Marker`.
- UID0001MG appears with `Completion:88 | Confidence:90` followed by the three-line comment-only aggregate marker, or equivalent validator formatting.
- Existing other class/page empty markers may remain. They are outside this target unless separately assigned.

Proof commands expected after implementation:

> Executable block R001 was removed from this report and preserved verbatim in [0001MG-DropGiveInputPanes-empty-emitter-source-quality-removed.md](0001MG-DropGiveInputPanes-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Run `DropGoldInputPane.md` / `GiveGoldInputPane.md` validators only if those support docs are edited. Run the vtable scoped validator only if the vtable doc is edited.

Generated proof commands:

> Executable block R002 was removed from this report and preserved verbatim in [0001MG-DropGiveInputPanes-empty-emitter-source-quality-removed.md](0001MG-DropGiveInputPanes-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected final proof: generated file header is current for the target validator or newer; UID0001MG search shows the comment marker; `UID:0001MG.*Empty Emitter Marker` returns no matches.

## No-Edit Boundaries

Implementation honored the no-edit boundaries. I did not manually edit generated files, generated reports, project-level generated reports, manual `-coverage-report.md` files, validator/tool state, queue JSON, lock files, IDA DB, executed archives, or supervisor ledgers. Generated output and validator-owned reports changed only through scoped validator execution.

## Claim And Incorporation Ledger

| Claim ID | Claim | Evidence / proof | Destination doc / section | Intended action | Current verification state |
| --- | --- | --- | --- | --- | --- |
| C-0001MG-01 | UID0001MG exact range is `0x005b44b0-0x005b538a`, size `0xeda` / 3802 bytes. | Current target metadata; MCP `int_convert 0xeda`; current function map ends at modeled `0x005b52f0` size `0x9a`, and `get_bytes 0x005b538a` shows successor padding. | Target status / range evidence. | Incorporate refreshed exact range and size proof. | applied: target `Status` and `B012 Current MCP Evidence And Aggregate Marker` preserve exact range/size proof; target validator `000000000770` accepted the file. |
| C-0001MG-02 | Current active MCP session is `b2ae72ec`, healthy, for `NexusTK.exe.i64`. | `idb_list` and `server_health` outputs recorded above. | Target current evidence section; report evidence. | Incorporate current-session proof; do not rely on stale session IDs. | applied: target B012 evidence records `b2ae72ec`, IDB path, PID `16112`, and healthy server state. |
| C-0001MG-03 | The aggregate contains fourteen modeled IDA functions, not one monolithic function. | `lookup_funcs` results and `analyze_component` function list with sizes. | Target function map. | Incorporate current modeled function table. | applied: existing function table retained; B012 evidence/no-body section states fourteen modeled methods and no single function body. |
| C-0001MG-04 | Raw helper starts `0x005b4760`, `0x005b4af0`, `0x005b4c50`, `0x005b4ef0`, and `0x005b5230` are not IDA functions and have no start xrefs. | MCP `lookup_funcs` and `xrefs_to` results. | Target raw helper map; no-code proof. | Preserve raw helper split evidence. | applied: target B012 evidence and raw helper map preserve no-function/no-xref proof. |
| C-0001MG-05 | Raw gold constructor starts `0x005b4b70` and `0x005b52b0` are not IDA functions and have no direct xrefs. | MCP `lookup_funcs` and `xrefs_to`; existing child pages [UID:0001MH]/[UID:0001MI]. | Target raw constructor map; support class notes if edited. | Preserve retained/no-route constructor evidence. | applied: target B012 evidence and reconstruction notes preserve retained/no-route constructor proof and exact child source route. |
| C-0001MG-06 | Byte samples confirm padding/body boundaries for representative raw gaps. | MCP `get_bytes` at `0x005b475c`, `0x005b4ae4`, `0x005b5223`, `0x005b538a`. | Target range/padding evidence. | Incorporate current byte-sample proof. | applied: target B012 evidence records the four byte-sample boundaries and successor padding. |
| C-0001MG-07 | `DropInputPane` submit at `0x005b4920` inline-constructs DropGold for `0x5c`, `0x2f`, `0x24`, and directly sends/confirm-drops normal items. | MCP `decompile 0x005b4920`. | Target behavior; `DropInputPane` support if edited. | Incorporate decompile summary. | applied: target B012 evidence records the decompile summary; `DropInputPane.md` cross-links UID0001MG as marker only. |
| C-0001MG-08 | `GiveInputPane` submit at `0x005b50b0` inline-constructs GiveGold for `0x5c`/`0x2f` and creates give confirmation for normal items. | MCP `decompile 0x005b50b0`. | Target behavior; `GiveInputPane` support if edited. | Incorporate decompile summary. | applied: target B012 evidence records the decompile summary; `GiveInputPane.md` cross-links UID0001MG as marker only. |
| C-0001MG-09 | DropGold submit `0x005b4bb0` parses `%u`, checks `g_pUserPane + 0x3ec0`, sends opcode `0x24` amount packet length `5`. | MCP `decompile 0x005b4bb0`. | Target behavior; DropGold support if edited. | Incorporate decompile summary and packet semantics. | applied: target B012 evidence records the submit semantics; DropGold class doc was not edited because no contradiction required it. |
| C-0001MG-10 | GiveGold submit `0x005b52f0` parses `%u`, checks `g_pUserPane + 0x3ec0`, sends opcode `0x2a` amount packet length `5`. | MCP `decompile 0x005b52f0`. | Target behavior; GiveGold support if edited. | Incorporate decompile summary and packet semantics. | applied: target B012 evidence records the submit semantics; GiveGold class doc was not edited because no contradiction required it. |
| C-0001MG-11 | Vtable evidence proves six distinct classes inside the range. | MCP `entity_query` and `xrefs_to` vtable addresses. | Target vtable evidence; `ItemActionInputPanes.md` support. | Incorporate vtable family proof. | applied: target B012 evidence records all six class vtable store/xref groups; by-file boundary note records marker policy. |
| C-0001MG-12 | Direct source owner/emitter remains [UID:0000KC] `ItemActionInputPanes`. | Current target metadata; by-file source root; all class/helper docs route to [UID:0000KC]. | Target metadata; `by-file/ItemActionInputPanes.md`. | Keep owner/emitter; update rationale. | applied: target metadata kept `CANONICAL_OWNER:0000KC`, `EMITTER_UIDS:0000KC`; by-file note preserves [UID:0000KC] as generated source root. |
| C-0001MG-13 | UID0001MG should not receive handwritten monolithic C++ body. | Mixed range evidence: multiple classes, raw helpers, raw constructors, padding, no single function. | Target formal C++/no-code proof. | Insert comment-only marker, not body. | applied: target formal block contains only the accepted three-line marker; no handwritten body was added. |
| C-0001MG-14 | UID0001MG should not be changed to `RECONSTRUCTABLE:FALSE` in this pass. | Range is source-bearing NexusTK code; exact children/class pages remain reconstruction surfaces. | Target metadata rationale. | Keep `RECONSTRUCTABLE:TRUE`. | applied: target remains `RECONSTRUCTABLE:TRUE`; no-body rationale rejects `FALSE`. |
| C-0001MG-15 | Blank empty-emitter state is no longer justified. | Generated output previously showed UID0001MG as `Empty Emitter Marker`; formal comment marker is target-specific no-code proof. | Target formal C++ block; generated proof. | Replace blank block with exact marker. | applied: target validator `000000000770` changed autogen registry `blank -> block`; generated C++ shows the marker and no UID0001MG empty-emitter match. |
| C-0001MG-16 | Metadata should become `COMPLETION:88`, `CONFIDENCE:90`, owner/emitter unchanged. | Current-session evidence refresh plus no-body marker resolution; remaining exact method splits prevent higher score. | Target metadata. | Apply score update only if report accepted. | applied: target metadata is `88/90`, owner/emitter unchanged; validator `000000000770` reports `completion_update 0001MG ... 88` and `confidence_update ... 90`. |
| C-0001MG-17 | `Item Summary` contains stale A002 wording saying child remained `78/82`; it must be historicalized or removed. | Current metadata is already `86/88`, and report recommends `88/90`. | Target summary/status. | Rewrite summary to current lifecycle/status. | applied: target item summary now describes B012 accepted reconstructable split/index aggregate marker under [UID:0000KC]. |
| C-0001MG-18 | `by-file/ItemActionInputPanes.md` should record UID0001MG as an intentional split/index aggregate marker. | By-file page owns source root and currently lists the same cluster; generated output route is through this file. | `by-file/ItemActionInputPanes.md` boundary/proposed contents. | Add support note. | applied: by-file boundary note and change entry added; validator `000000000765` passed. |
| C-0001MG-19 | DropAll/Drop/GiveAll/Give class pages contain stale old-gate wording and should be modernized if implementation touches support docs. | Current by-structure uses `(completion+confidence)/2 > 85`, not `95/95`; class pages still remain blank for method/declaration reasons. | Four by-class support docs. | Replace old-gate wording with current no-code rationale. | applied: DropAll and GiveAll stale gate wording replaced; Drop/Give cross-linked marker and preserved current no-code rationale; validators `000000000766` through `000000000769` passed. |
| C-0001MG-20 | DropGold/GiveGold class pages need no default edit except optional cross-link if supervisor wants support sync. | They already have modern constructor-child/source-route no-code proof. | `by-class/DropGoldInputPane.md`, `by-class/GiveGoldInputPane.md`. | Optional edit only; no default validator unless edited. | excluded-with-reason: not edited because no direct contradiction was found; existing class pages already preserve constructor-child/source-route no-code proof. |
| C-0001MG-21 | Vtable/global docs need no default edit. | Current docs already support the target; no direct contradiction found. | `by-type/by-vtable/ItemActionInputPaneVtableFamily.md`, `by-global/g_packetSender.md`, `by-global/g_pCollectionData.md`. | Do not edit unless contradiction appears. | excluded-with-reason: not edited because implementation found no direct contradiction; no scoped validators were required. |
| C-0001MG-22 | Generated proof after implementation must show UID0001MG no longer appears as an `Empty Emitter Marker`. | Target validator with `--wait-generated` refreshed `ItemActionInputPanes.cpp`. | Implementation checklist / validator proof. | Run target validator with `--wait-generated`, inspect generated output read-only. | applied: generated header `validator-command-id: 000000000770`, refreshed `2026-06-29T13:04:54-04:00`; UID0001MG appears with marker at lines 174-177; empty-emitter search returned no matches. |

## Implementation Tracking Checklist

- [x] Edit `by-memory\0x005b44b0-0x005b538a.DropGiveInputPanes.md`: set `COMPLETION:88`, `CONFIDENCE:90`; keep `CANONICAL_OWNER:0000KC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KC`. Proof: target validator `000000000770`, `2026-06-29T13:04:54-04:00`.
- [x] Edit `by-memory\0x005b44b0-0x005b538a.DropGiveInputPanes.md`: insert the accepted three-line comment-only aggregate marker in the formal `RECONSTRUCTION_CPP CODE` block. Proof: generated output shows the same marker under UID0001MG.
- [x] Edit `by-memory\0x005b44b0-0x005b538a.DropGiveInputPanes.md`: update `Item Summary` to remove stale `78/82` A002 current-state wording and state the current aggregate-marker disposition.
- [x] Edit `by-memory\0x005b44b0-0x005b538a.DropGiveInputPanes.md`: add current `b2ae72ec` evidence for session health, function map, raw non-functions/no xrefs, vtable xrefs, decompile summaries, byte samples, and generated-output state.
- [x] Edit `by-memory\0x005b44b0-0x005b538a.DropGiveInputPanes.md`: add no-monolithic-body/no-code proof and rejected alternatives.
- [x] Edit `by-file\ItemActionInputPanes.md`: add UID0001MG split/index aggregate marker policy and generated-output expectation; keep [UID:0000KC] as source root. Validator `000000000765`, `2026-06-29T13:04:20-04:00`, `ok: 1`.
- [x] Edit `by-class\DropAllInputPane.md`: replace stale old-gate blank-C++ wording with current no-code rationale and cross-link UID0001MG aggregate marker. Validator `000000000766`, `2026-06-29T13:04:26-04:00`, `ok: 1`.
- [x] Edit `by-class\DropInputPane.md`: replace stale old-gate blank-C++ wording if present and cross-link UID0001MG aggregate marker. Validator `000000000767`, `2026-06-29T13:04:34-04:00`, `ok: 1`.
- [x] Edit `by-class\GiveAllInputPane.md`: replace stale `95/95` blank-C++ wording with current no-code rationale and cross-link UID0001MG aggregate marker. Validator `000000000768`, `2026-06-29T13:04:40-04:00`, `ok: 1`.
- [x] Edit `by-class\GiveInputPane.md`: replace stale blank-C++ wording if present and cross-link UID0001MG aggregate marker. Validator `000000000769`, `2026-06-29T13:04:47-04:00`, `ok: 1`.
- [x] Optional only if touched: edit `by-class\DropGoldInputPane.md` and `by-class\GiveGoldInputPane.md` to cross-link the UID0001MG aggregate marker; otherwise leave unchanged. Excluded: not touched, no contradiction found, no validators needed.
- [x] Do not edit `by-type\by-vtable\ItemActionInputPaneVtableFamily.md` by default; run its scoped validator only if implementation discovers and fixes a direct contradiction. Excluded: not touched, no contradiction found, no validator needed.
- [x] Do not edit raw helper/constructor child pages by default during this UID0001MG callback; their own empty markers/source bodies should remain separate assignments unless supervisor expands scope. Excluded: not touched, scope preserved.
- [x] Run from `E:\NTK\GhidraBridge\source-3\project-documentation`: `python .\tools\validator.py --mode file --file "by-file\ItemActionInputPanes.md" --apply --queue-timeout 240`. Command `000000000765`, `2026-06-29T13:04:20-04:00`, `ok: 1`.
- [x] Run from `E:\NTK\GhidraBridge\source-3\project-documentation`: `python .\tools\validator.py --mode file --file "by-class\DropAllInputPane.md" --apply --queue-timeout 240`. Command `000000000766`, `2026-06-29T13:04:26-04:00`, `ok: 1`.
- [x] Run from `E:\NTK\GhidraBridge\source-3\project-documentation`: `python .\tools\validator.py --mode file --file "by-class\DropInputPane.md" --apply --queue-timeout 240`. Command `000000000767`, `2026-06-29T13:04:34-04:00`, `ok: 1`.
- [x] Run from `E:\NTK\GhidraBridge\source-3\project-documentation`: `python .\tools\validator.py --mode file --file "by-class\GiveAllInputPane.md" --apply --queue-timeout 240`. Command `000000000768`, `2026-06-29T13:04:40-04:00`, `ok: 1`.
- [x] Run from `E:\NTK\GhidraBridge\source-3\project-documentation`: `python .\tools\validator.py --mode file --file "by-class\GiveInputPane.md" --apply --queue-timeout 240`. Command `000000000769`, `2026-06-29T13:04:47-04:00`, `ok: 1`.
- [x] Run the target validator last, with generated wait: `python .\tools\validator.py --mode file --file "by-memory\0x005b44b0-0x005b538a.DropGiveInputPanes.md" --apply --queue-timeout 240 --wait-generated`. Command `000000000770`, `2026-06-29T13:04:54-04:00`, `ok: 1`, `generated_refresh: completed`.
- [x] If optional DropGold/GiveGold docs are edited, run their scoped validators. Excluded: optional docs not edited.
- [x] If vtable doc is edited, run `python .\tools\validator.py --mode file --file "by-type\by-vtable\ItemActionInputPaneVtableFamily.md" --apply --queue-timeout 240`. Excluded: vtable doc not edited.
- [x] Inspect `auto-generated\NexusTK\ui\dialogs\ItemActionInputPanes.cpp` read-only after the target validator. Confirm UID0001MG no longer matches `UID:0001MG.*Empty Emitter Marker` and shows the accepted comment-only marker. Proof: header command `000000000770`, refreshed `2026-06-29T13:04:54-04:00`; UID0001MG marker appears at lines 174-177; empty-emitter search returned no matches.
- [x] Update this report's Claim And Incorporation Ledger and checklist after callback implementation with applied/already-present/excluded proof, validator command IDs/timestamps, generated freshness, and lease release proof. Proof: this section; leases granted and released successfully for six edited by-* files, and post-release lease search returned no B012/path matches.

## Implementation Final State

Implementation callback is complete. Edited by-* docs: `by-memory\0x005b44b0-0x005b538a.DropGiveInputPanes.md`, `by-file\ItemActionInputPanes.md`, `by-class\DropAllInputPane.md`, `by-class\DropInputPane.md`, `by-class\GiveAllInputPane.md`, and `by-class\GiveInputPane.md`. Also updated this Agent-B012 report.

Leases: B012 lease command succeeded for the six edited by-* files before editing; B012 unlease command succeeded for the same six files after the edit/validator batch. Post-release current-lease search returned no B012 or edited-path matches.

Validators: commands `000000000765` through `000000000770` all returned `ok: 1`. Existing missing-ref/stale-registry warnings were reported by the validator and not introduced as blockers by this callback.

Generated output: `auto-generated\NexusTK\ui\dialogs\ItemActionInputPanes.cpp` was inspected read-only after target validation. Header shows `validator-command-id: 000000000770`, `validator-refreshed-at: 2026-06-29T13:04:54-04:00`; UID0001MG appears with `Completion:88 | Confidence:90` and the accepted comment-only marker; UID0001MG no longer matches `Empty Emitter Marker`.

No unchecked blockers remain for the accepted UID0001MG callback.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/0001MG-DropGiveInputPanes-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B012/research/0001MG-DropGiveInputPanes-empty-emitter-source-quality.md","timestamp":"2026-06-29T13:25:58","uid":"0001MG"} -->
<!-- {"agent":"B012","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001MG-DropGiveInputPanes-empty-emitter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B012/0001MG-DropGiveInputPanes-empty-emitter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001MG"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
