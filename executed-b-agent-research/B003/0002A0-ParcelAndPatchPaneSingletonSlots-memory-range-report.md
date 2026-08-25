** TARGET-REPORT-UID:0002A0 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002A0 ParcelAndPatchPaneSingletonSlots Memory-Range Advanced-Scan Report

## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:0002A0][0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots](../../../../../by-memory/0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots.md) as `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and a non-reconstructable split index.
- Final disposition: the advanced-scan line is a real scanner-visible compact-label text gap, not a stale filename, stale range, canonical-owner issue, emitter issue, or split/merge issue. The audit also found stale byte-initializer wording in the target and direct child evidence: current IDA/PE evidence shows zero-filled `.data` tail storage, not raw `0xffffffff` bytes.
- Required action: add scanner-visible `ParcelAndPatchPaneSingletonSlots` text to the target page and repair stale byte wording in the target/direct child evidence. Do not rename the file, do not assign a canonical owner to the aggregate, and do not emit the aggregate.
- Confidence: `90` for split-index disposition and owner/emitter state; `88` for the stale-byte repair because the current IDA byte read and PE section mapping agree, while older docs record a contrary historical `py_eval` result.

## Supporting Research

## Target
- Target UID: `0002A0`.
- Target path: `by-memory/0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots.md`.
- Source queue/report row: `tools/leaser/Agents/Supervisor_notes.md` assigns `B003-MR-0002A0`; `auto-generated/by-memory-tool-report.md` line 233 reports `0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots.md: missing document text for ParcelAndPatchPaneSingletonSlots`.
- Current supervisor classification: Goal 2 memory-ranges advanced-scan audit for possible scanner-visible label/title mismatch versus real documentation/range/name/owner/emitter issue.
- Current header state:
  - `UID:0002A0`
  - `COMPLETION:86`
  - `CONFIDENCE:90`
  - `CANONICAL_OWNER:NONE`
  - `RECONSTRUCTABLE:FALSE`
  - `EMITTER_UIDS:` blank
  - `RECONSTRUCTION_CPP CODE:` blank
  - Current title: `# 0x0069ba28-0x0069ba30 - Parcel And Patch Pane Singleton Split Index`

## Executive Recommendation
- The file label/range are valid. The page title and body describe a `Parcel And Patch Pane Singleton Split Index`, but the compact filename label `ParcelAndPatchPaneSingletonSlots` is absent from the non-change document text scanned by `memory_ranges.py`.
- Keep the aggregate ignored as a standalone source item. Its two source-bearing children already exist and route separately:
  - [UID:0002ZO][0x0069ba28-0x0069ba2c.g_pParcelPane](../../../../../by-memory/0x0069ba28-0x0069ba2c.g_pParcelPane.md): `CANONICAL_OWNER:0000MF`, `EMITTER_UIDS:0000MF`, generated to `auto-generated/NexusTK/ui/panels/ParcelPane.cpp`.
  - [UID:0002ZP][0x0069ba2c-0x0069ba30.g_pPatchPane2](../../../../../by-memory/0x0069ba2c-0x0069ba30.g_pPatchPane2.md): `CANONICAL_OWNER:0000RZ`, `EMITTER_UIDS:0000RZ`, generated to `auto-generated/NexusTK/patch/PatchPane.cpp` through the `g_pPatchPane2` route.
- Repair stale byte evidence from `ff ff ff ff` / `0xffffffff` to zero-filled `.data` tail storage. This is documentation text repair only; it does not change the child source declarations, boundaries, xref families, owner routes, or split-index classification.

## Supervisor Active Recheck
- Supervisor instruction: audit the current memory-ranges advanced-scan finding for `missing document text for ParcelAndPatchPaneSingletonSlots` and determine whether this is only scanner wording or a real documentation/range/name/owner/emitter issue.
- Split repair required before final report: no. The aggregate is already split into exact four-byte child pages, and the generated coverage state already treats the parent as `not_reconstructable`.
- Source-bearing children in scope: both child pages exist, clear the current 85/85 gate, and have distinct source-output routes. No new split child is required.
- Direct edits performed: none to `by-*` files or shared reports, per user instruction.

## Inference Research Guidance Check
- `by-structure.md` says mixed/container pages should be `RECONSTRUCTABLE:FALSE` when the container itself is only an audit/index range and exact children carry real source ownership. That rule fits this item.
- Current owner/emitter terminology was applied: `CANONICAL_OWNER` is semantic ownership, `EMITTER_UIDS` is output routing. The aggregate has no valid single semantic owner and no source output of its own.
- Existing documentation was treated as a lead, not authority. Live IDA xrefs confirm the split and ownership direction; live IDA byte/PE evidence contradicts the older `0xffffffff` initializer wording.

## Evidence Standards Used
- Documentation evidence: target page header/body, generated advanced-scan row, generated memory coverage rows, by-memory coverage row, direct child pages, by-global pages, by-file and by-class owner pages, and `memory_ranges.py` scanner implementation.
- IDA MCP evidence: `idb_list`, `server_health`, `get_bytes`, `get_global_value`, `xrefs_to`, `lookup_funcs`, `decompile`, and `entity_query`.
- PE/raw evidence: local PE header parse of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` to map VA/RVA to `.data` raw-backed versus virtual zero-fill storage.
- Strength: xrefs and decompilation directly prove separate `ParcelPane` and `PatchPane2` singleton lifecycles. PE mapping plus `get_bytes` directly prove current zero-filled storage at this range.

## IDA MCP Facts
- Session: `b001_0003gy`, active `NexusTK.exe`, input `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, imagebase `0x400000`; `server_health` reported `auto_analysis_ready:true` and `hexrays_ready:true`.
- Byte facts: `get_bytes` on `0x0069ba28` size `8` returned eight zero bytes. `get_bytes` on `0x0069ba24` size `24` returned zero bytes for the broader neighborhood queried.
- PE/raw facts: `.data` has VA `0x0026d000`, virtual size `0x0002fe24`, raw pointer `0x0026ac00`, and raw size `0x0000d800`. Target VA `0x0069ba28` is RVA `0x0029ba28`, inside `.data` virtual memory but past the raw-backed `.data` end at RVA `0x0027a800`; it is loader zero-fill storage, not file-backed `ff` bytes.
- Xref facts for `0x0069ba28`: nine data refs in `sub_545E40`, `sub_546290`, `sub_546440`, `sub_546D70`, `sub_546E80`, and `sub_547000`.
- Xref facts for `0x0069ba2c`: five data refs in `sub_548690`, raw address `0x00548a6d` with no enclosing function, `sub_549340`, and `sub_549370`.
- Boundary facts: predecessor `0x0069ba24` has 13 BowGaugeObjectPane refs; successor `0x0069ba30` has zero refs; successor `0x0069ba34` has five PowerDialog refs. The target's two four-byte slots are distinct from both neighbors.
- Decompilation facts:
  - `sub_545E40` and `sub_546290` assign `unk_69BA28` to either a `ParcelPane`-family `this` pointer or `0` immediately before/around `ParcelPane` vtable setup.
  - `sub_546D70` reads through `unk_69BA28` during `FlyingParcelPane` animation handoff.
  - `sub_548690` assigns `unk_69BA2C` to either `this` or `0` immediately before `PatchPane2` vtable setup.
  - `sub_549340` is a compact clear helper that sets `unk_69BA2C = 0`.
  - `sub_549370` clears `unk_69BA2C = 0` in the `PatchPane2` scalar deleting destructor path.
- Negative IDA facts: current `entity_query`/`list_globals` did not expose stable global names for the auto labels around `0x0069ba28`. The `dword_` versus `unk_` spelling is therefore not a source-level name signal and does not justify an IDA-safe rename in documentation.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0069ba28-0x0069ba30` | `0002A0` / `by-memory/0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots.md` | mixed ParcelPane/PatchPane2 singleton split index | `FALSE` | `NONE` | `86/90` | keep non-reconstructable split index |
| `0x0069ba28-0x0069ba2c` | `0002ZO` / `by-memory/0x0069ba28-0x0069ba2c.g_pParcelPane.md` | exact `g_pParcelPane` pointer slot | `TRUE` | `0000MF` | `86/90` | keep child and route to `ParcelPane.cpp`; repair stale byte text |
| `0x0069ba2c-0x0069ba30` | `0002ZP` / `by-memory/0x0069ba2c-0x0069ba30.g_pPatchPane2.md` | exact `g_pPatchPane2` pointer slot | `TRUE` | `0000RZ` | `86/90` | keep child and route through `g_pPatchPane2`; repair stale byte text |
| `0x0069ba30-0x0069ba34` | `0002A1` / `by-memory/0x0069ba30-0x0069ba34.UnreferencedInitializedDword_69BA30.md` | unreferenced successor filler/reserved dword | `FALSE` | `NONE` | `90/90` current docs | outside target; same zero-fill neighborhood caveat should be reviewed separately |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0069ba28` | refs at `0x00545f03`, `0x00545f0a`, `0x005462e1`, `0x005462e8` | `ParcelIconPane` / `ParcelPane` constructor-family publish or fallback-clear writes |
| `0x0069ba28` | refs at `0x0054648d`, `0x00546e80`, `0x00547054` | `ParcelPane` destructor/clear-helper/scalar-destructor clears |
| `0x0069ba28` | refs at `0x00546dbc`, `0x00546dd2` | `FlyingParcelPane` animation uses the active parcel pane |
| `0x0069ba2c` | refs at `0x005486f4`, `0x005486fb` | `PatchPane2` constructor-family publish or fallback-clear writes |
| `0x0069ba2c` | ref at `0x00548a6d` | raw PatchPane2 cleanup/body reference not wrapped by an IDA function |
| `0x0069ba2c` | refs at `0x00549340`, `0x005493d0` | clear helper and scalar deleting destructor clear the PatchPane2 singleton |
| `0x0069ba30` | zero xrefs | successor filler/reserved item, not part of this aggregate |

## Documentation Evidence And IDA Status
- Target page correctly says the range is physically contiguous but source-mixed, and that the two dwords have different direct owners, xref families, constructors, and cleanup paths.
- Current `auto-generated/-ag-memory-coverage.md` has the correct aggregate row: `not_reconstructable`, `CANONICAL_OWNER:NONE`, blank emitters.
- Current generated rows for the children show valid output routes:
  - `0002ZO` emits through `0000MF` to `auto-generated/NexusTK/ui/panels/ParcelPane.cpp`.
  - `0002ZP` emits through `0000RZ` to `auto-generated/NexusTK/patch/PatchPane.cpp`.
- Current `by-memory/-coverage-report.md` correctly describes the parent as an ignored split aggregate, but the child rows repeat stale `ff ff ff ff` / `0xffffffff` initializer evidence.
- Current target title/body do not include the compact scanner label `ParcelAndPatchPaneSingletonSlots` outside the filename/link URL context.
- `memory_ranges.py` line 1067 checks the normalized filename label against normalized scanned document text; line 1071 emits `missing document text for ...`. `memory_ranges.data` ignores `Changes` sections during advanced scan, so adding the compact label only in `## Changes` would not reliably clear the warning.

## Ranked Ownership Analysis

### 1. Keep aggregate as `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters
- Evidence for: the aggregate combines two independent source globals with separate owners. Live IDA xrefs split cleanly at `0x0069ba28` and `0x0069ba2c`; `by-structure.md` says reviewed mixed indexes whose exact children carry source ownership should be `RECONSTRUCTABLE:FALSE`.
- Evidence against: the two slots are adjacent and both are singleton UI pointers, but adjacency alone is weak ownership evidence and the source modules differ.
- Decision: accepted.

### 2. Assign aggregate to `ParcelPane.cpp`
- Evidence for: the first child belongs to the parcel notification family and has more xrefs than the PatchPane2 child.
- Evidence against: the second half belongs to PatchPane2 / patch update UI, with a different source file route and lifecycle. Assigning the aggregate to `ParcelPane.cpp` would mix unrelated source declarations into the wrong file.
- Decision: rejected.

### 3. Assign aggregate to `PatchPane.cpp`
- Evidence for: the second child belongs to PatchPane2 and the patch update module.
- Evidence against: the first half is a ParcelPane singleton with exclusive parcel notification xrefs. Assigning the aggregate to `PatchPane.cpp` would be equally wrong.
- Decision: rejected.

### 4. Create a new shared UI singleton owner or emit both slots through the aggregate
- Evidence for: both dwords are UI singleton pointer slots located in a broader `.data` singleton neighborhood.
- Evidence against: the existing exact child pages already model the real source declarations. A synthetic shared owner would obscure the actual source modules and produce an emitted combined declaration that the split evidence says should not exist.
- Decision: rejected.

## Negative Evidence Summary
- The advanced-scan complaint is not evidence of a stale UID, stale range, or missing body. The page has a body with status, slot inventory, xrefs, reconstruction notes, cross-references, and change history.
- Consumer/read xrefs do not make the aggregate shared-source-owned. They reinforce the two separate child lifecycles.
- The current decompiler's `unk_69BA28` / `unk_69BA2C` labels do not require an IDA-safe name repair because no stable name inventory entry exists and the source-level names are represented by the child/global docs.
- The stale `0xffffffff` byte text does not change reconstruction ownership: a source-level global pointer defaults to zero/null; constructor/destructor xrefs still prove the same slots and lifecycle.

## Exact Required Edits

### Target page `by-memory/0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots.md`
Add this bullet in `## Status` after the address-range line, outside `## Changes`, so the advanced scan sees the compact label:

```markdown
- Scanner-visible filename label: `ParcelAndPatchPaneSingletonSlots`.
```

Replace the current IDA byte evidence bullet:

```markdown
- 2026-06-07 A001 IDA MCP `py_eval` byte read reports `.data` bytes `ff ff ff ff ff ff ff ff` for `0x0069ba28-0x0069ba30`.
```

with:

```markdown
- 2026-06-14 B003 live IDA MCP `get_bytes` reports eight zero bytes for `0x0069ba28-0x0069ba30`; PE section mapping places this RVA in the virtual `.data` tail beyond the raw-backed section bytes, so the older `0xffffffff` initializer wording is stale.
```

Replace the `## Changes` summary line:

```markdown
  - Summary/evidence: live IDA confirmed two adjacent four-byte `.data` slots initialized to `0xffffffff`; `0x0069ba28` has nine ParcelPane/FlyingParcelPane references and `0x0069ba2c` has five PatchPane2 references. The mixed parent is retained only as a split index and ignored as a standalone reconstruction target.
```

with:

```markdown
  - Summary/evidence: live IDA confirmed two adjacent four-byte `.data` slots; 2026-06-14 B003 recheck corrected the initializer wording to loader-zeroed virtual `.data` tail storage. `0x0069ba28` has nine ParcelPane/FlyingParcelPane references and `0x0069ba2c` has five PatchPane2 references. The mixed parent is retained only as a split index and ignored as a standalone reconstruction target.
```

No header metadata change is recommended for `0002A0`.

### Direct child evidence text
The direct child pages are not assigned for editing in this pass, but the same stale-byte correction should be applied when a permitted repair pass touches them:

- In `by-memory/0x0069ba28-0x0069ba2c.g_pParcelPane.md`, replace `ff ff ff ff` / `0xffffffff` storage/evidence wording with `00 00 00 00` / `0`, and change historical `py_eval` claims to a corrected-note form rather than leaving them as current fact.
- In `by-memory/0x0069ba2c-0x0069ba30.g_pPatchPane2.md`, replace `ff ff ff ff` / `0xffffffff` storage/evidence wording with `00 00 00 00` / `0`, and change historical `py_eval` claims to a corrected-note form.
- In `by-global/g_pParcelPane.md` and `by-global/g_pPatchPane2.md`, update review-note bullets that say the slot bytes/value are `ff ff ff ff` / `0xffffffff`; the lifecycle and ownership text can remain.
- In `by-memory/-ignored.md`, replace line 3650 with:

```markdown
  - Evidence: 2026-06-14 B003 live IDA/PE review confirms `0x0069ba28` has nine ParcelPane/FlyingParcelPane references and `0x0069ba2c` has five PatchPane2 references. Both are loader-zeroed four-byte pointer slots in the virtual `.data` tail, not raw `0xffffffff` dwords; their constructor/destructor/clear xref families are separate.
```

### Shared coverage-report text for supervisor application
No `by-memory/-coverage-report.md` parent row replacement is required for `0002A0`; the existing parent row is still correct:

```markdown
    - [UID:0002A0][0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots](by-memory/0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots.md) 0x0069ba28-0x0069ba30 | split global-data aggregate | ParcelAndPatchPaneSingletonSplitIndex : ignored : 86% : very-strong : Mixed ParcelPane/PatchPane2 singleton aggregate split into exact child storage pages; live IDA confirms separate four-byte slots, distinct xref families, and no valid combined source declaration.
```

The two direct child rows should be corrected for initializer wording when the supervisor updates the shared report:

```markdown
        - [UID:0002ZO][0x0069ba28-0x0069ba2c.g_pParcelPane](by-memory/0x0069ba28-0x0069ba2c.g_pParcelPane.md) 0x0069ba28-0x0069ba2c | global pointer | g_pParcelPane : reconstructable : 86% : very-strong : A002 Batch078 repaired generated `autogen_parent_unknown` by routing to direct source parent [UID:0000MF][ParcelPane](by-file/ParcelPane.md), now `86/85`; [UID:0000RY][g_pParcelPane](by-global/g_pParcelPane.md) remains the `85/90` symbol evidence anchor. IDA/PE recheck confirmed `.data` zero-fill item `0x0069ba28` size `4`, bytes/value `00 00 00 00` / `0`, nine refs in `sub_545E40`, `sub_546290`, `sub_546440`, `sub_546D70`, `sub_546E80`, and `sub_547000`, with exact `g_pBowGaugeObjectPane`/`g_pPatchPane2` boundaries.
        - [UID:0002ZP][0x0069ba2c-0x0069ba30.g_pPatchPane2](by-memory/0x0069ba2c-0x0069ba30.g_pPatchPane2.md) 0x0069ba2c-0x0069ba30 | global pointer | g_pPatchPane2 : reconstructable : 86% : very-strong : Exact four-byte PatchPane2 singleton slot in loader-zeroed `.data` tail storage; Batch124 restored assignment to direct by-global evidence anchor [UID:0000RZ][g_pPatchPane2](by-global/g_pPatchPane2.md) after that page reached `86/90` and rooted under [UID:0000MH][PatchPane](by-file/PatchPane.md) at `88/85`. Live IDA confirms five xrefs, constructor publish/fallback clears, cleanup/body reference, clear-helper write, scalar deleting destructor clear, and clean ParcelPane/filler boundaries.
```

### Generated reports
- Do not manually edit `auto-generated/by-memory-tool-report.md`. After the compact label is added to the target page and the memory-ranges report is regenerated, the line for `ParcelAndPatchPaneSingletonSlots` should disappear.
- Do not manually edit `auto-generated/-ag-memory-coverage.md`; the current `0002A0` generated row is already correct:

```markdown
| [UID:0002A0][0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots](by-memory/0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots.md) | not_reconstructable | `NONE` |  |  | no |  | `by-memory/0x0069ba28-0x0069ba30.ParcelAndPatchPaneSingletonSlots.md` |  |
```

## Final Recommendation
- Rename/title repair: no file rename. Add one scanner-visible compact label line to the target page. Optional title polish is acceptable, but not required if the label line is added outside ignored sections.
- Text repair: yes. Correct stale `0xffffffff` initializer wording for the aggregate and direct child/global evidence; current evidence supports zero-filled `.data` tail storage.
- Metadata repair: no. Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `RECONSTRUCTION_CPP CODE`.
- Range repair: no. Keep `0x0069ba28-0x0069ba30`; exact children at `0x0069ba28-0x0069ba2c` and `0x0069ba2c-0x0069ba30` are correct.
- Owner/emitter repair: no for the aggregate. Existing child routes remain correct.
- Split/merge/reclassification: no additional split and no merge. Keep as a non-reconstructable split index superseded by exact child pages.

## Follow-Up Actions
- Supervisor actions: apply the exact target-page text repair and optional direct child/shared-report byte corrections above, or assign a narrow permitted repair pass. Do not edit `by-memory/-coverage-report.md` manually unless acting under supervisor-owned shared-report workflow.
- A-agent actions: none required for owner/emitter routing. If a future A-agent touches the child pages, they should repair `ff ff ff ff` initializer wording to zero-fill wording.
- B003 future research actions: none for this target unless asked to perform the text repair under a lease-enabled editing assignment.

## Confidence
- Recommendation confidence: `90`. The split-index decision is directly supported by current xrefs/decompilation and current coverage state.
- Scanner diagnosis confidence: `95`. `memory_ranges.py` checks normalized label text, and the compact label is absent from target page text outside ignored sections.
- Stale-byte repair confidence: `88`. Current IDA `get_bytes`, `get_global_value`, and PE section mapping agree on zero-filled storage. The score is below final-audit range because the older docs cite a historical `py_eval` result that should be treated as stale or tool-context-specific, not silently erased without a normal documentation edit pass.
- Remaining uncertainty: final original declaration spellings for `g_pParcelPane` and `g_pPatchPane2` remain medium-high, but they do not affect this aggregate's scanner finding or split disposition.

## Validator Results
- Commands run: none.
- Reason: this assignment explicitly prohibited direct `by-*` edits, and only this Agent-B003 research report was created.
- Dry runs: none.
- Unresolved validator warnings/errors: not evaluated in this pass.

## Lease State
- Leases acquired by B003: none.
- `current_leases.md` checked during this pass; it listed active Agent-A001 leases only, with no B003 lease entries.

## Changed Files
- Created: `tools/leaser/Agents/Agent-B003/research/0002A0-ParcelAndPatchPaneSingletonSlots-memory-range-report.md`.
- Modified: none outside this report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002A0-ParcelAndPatchPaneSingletonSlots-memory-range-report.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"0002A0"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
