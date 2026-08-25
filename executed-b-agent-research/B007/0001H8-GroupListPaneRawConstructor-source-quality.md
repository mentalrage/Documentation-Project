** TARGET-REPORT-UID:0001H8 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001H8 GroupListPane Raw Constructor Source-Quality Research

## Finalized Report / Implemented Disposition

- Implemented disposition: [UID:0001H8][0x0056baa0-0x0056bafd.GroupListPaneRawConstructor](../../../../../by-memory/0x0056baa0-0x0056bafd.GroupListPaneRawConstructor.md) now carries live IDA MCP evidence, `Nested:0`, and the accepted target-level first-draft constructor body.
- Final range/ownership state: keep exact raw/manual constructor range `0x0056baa0-0x0056bafd`, keep class owner/emitter [UID:00005X][GroupListPane](../../../../../by-class/GroupListPane.md), keep `RECONSTRUCTABLE:TRUE`, and raise the target to `89/91`.
- Implementation state: supervisor implementation callback was received on 2026-06-26; accepted by-* edits are complete, scoped validators passed, and final lease/queue proof is recorded below.
- Confidence: high for constructor identity, range, vtable stores, inline parent parity, and source placement; medium-high for exact final helper spelling because `IsLegacyAssetMode()` and TextEditPane parameter names remain descriptive support names rather than final 95+ names.

## Supporting Research

## Target

- Target UID: `0001H8`
- Target path: [by-memory/0x0056baa0-0x0056bafd.GroupListPaneRawConstructor.md](../../../../../by-memory/0x0056baa0-0x0056bafd.GroupListPaneRawConstructor.md)
- Assignment id: `B007-report-0001H8-group-list-pane-raw-constructor-20260625`
- Source queue/report row: stale generated rows still reference old path `by-memory/0x0056baa0-0x0056bb00.GroupListPaneRawConstructor.md` and old `74/84` data; live by-* target is narrowed to `0x0056baa0-0x0056bafd`.
- Current supervisor classification: report-only B-agent research first; no by-* implementation until supervisor callback.
- Current scores and parent state: target `86/89`; direct owner/emitter [UID:00005X] `GroupListPane` is `87/89`; file parent [UID:0000JS] `Group` is `89/85`.

## Current Target State

Existing metadata:

- `COMPLETION:86`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:00005X`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00005X`
- `Nested:-4`
- Formal C++ block blank

Existing owner/emitter/reconstructable state is directionally correct: the page is a class-owned, source-authored raw constructor-shaped body for `GroupListPane`. The stale parts are the negative `Nested` metadata, the old blank-C++ rationale, and lack of current live MCP proof for the exact range and helper semantics.

Existing blockers and stale assumptions checked:

- The old "`sub_4B60B0` returns a resource/context pointer" model is superseded. Live IDA and [UID:0003XA][IsLegacyAssetMode](../../../../../by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md) prove it returns `byte_66DA97 != 1`.
- The old "do not emit until 95/95" style blocker is rejected. Current rules allow first-draft C++ for routed reconstructable emitters above the gate when the source shape is defensible.
- The current [UID:0000EO][TextEditPane](../../../../../by-class/TextEditPane.md) class page now contains a formal constructor declaration, so the older class-report reason that the base constructor signature is wholly unavailable is stale.
- The raw start still has no IDA function object and no inbound xrefs. That remains a score cap, but not a C++ blocker because the same constructor body is duplicated inline in both parent constructors.
- The two false virtual stubs at [UID:0001H9][0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs](../../../../../by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md) still lack final source names. That blocks class-level declaration polish, but not this target's no-argument constructor body.

Related docs checked:

- [UID:00005X][GroupListPane](../../../../../by-class/GroupListPane.md)
- [UID:0000JS][Group](../../../../../by-file/Group.md)
- [UID:0001HC][GroupPanes](../../../../../by-memory/0x0056c4c0-0x0056e939.GroupPanes.md)
- [UID:0001H9][GroupListPaneVirtualStubs](../../../../../by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md)
- [UID:0002NI][GroupListPaneVtableData](../../../../../by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md)
- [UID:0003XA][IsLegacyAssetMode](../../../../../by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md)
- [UID:0002ZY][TextEditPaneConstructor](../../../../../by-memory/0x0058dce0-0x0058e132.TextEditPaneConstructor.md)
- [UID:0000EO][TextEditPane](../../../../../by-class/TextEditPane.md)
- [UID:0002V7][PaneSetMode](../../../../../by-memory/0x005446b0-0x005446d4.PaneSetMode.md)
- [UID:0000QX][g_pFontImageLib](../../../../../by-global/g_pFontImageLib.md)
- [UID:0001XP][GroupPaneFamilyVtables](../../../../../by-type/by-vtable/GroupPaneFamilyVtables.md)
- `executed-b-agent-research/B001/00005X-GroupListPane-class-source-quality.md`
- `executed-b-agent-research/B014/00010A-ClanStatusPaneConstructor-source-quality.md`
- `executed-b-agent-research/B005/0000EO-TextEditPane-class-source-quality.md`
- Generated tracker/report rows, read-only, for stale path/state confirmation only

## Executive Recommendation

Keep the direct owner as `GroupListPane` ([UID:00005X]) and source placement under [UID:0000JS] `Group`. Do not split, merge, rename, or demote this target. Keep the exact half-open range `0x0056baa0-0x0056bafd`; keep `0x0056bafd-0x0056bb00` as padding outside the target; keep the stubs at `0x0056bb00-0x0056bb15` separate.

Add target-level constructor C++:

- `GroupListPane::GroupListPane()` with a `TextEditPane(...)` base initializer.
- Use the exact observed constants: `145, 84, 145, 84, 0x80, 0, 0, 1, 6, IsLegacyAssetMode(), 1, 0`.
- Do not emit vtable stores, `operator new`, the no-xref/raw prologue, the ignored `g_pFontImageLib` `ecx` load, `return this`, or parent-only setup calls.

Change target metadata to:

- `COMPLETION:89`
- `CONFIDENCE:91`
- `Nested:0`
- keep `CANONICAL_OWNER:00005X`
- keep `RECONSTRUCTABLE:TRUE`
- keep `EMITTER_UIDS:00005X`

## Supervisor Active Recheck

The user instructed Agent-B007 to use the project-level `ntk-b-agent-workflow` skill, read `goal.md`, produce the report-only research report first, avoid by-* edits until supervisor validation/callback, avoid subagents, and stop if IDA MCP was unavailable or busy beyond brief retry.

IDA MCP was available. Session `80de0a67` was used against `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` reported `status: ok`, image base `0x400000`, `auto_analysis_ready:true`, and `hexrays_ready:true`.

No split repair is needed. The prior split/narrowing from old `0x0056baa0-0x0056bb00` to live `0x0056baa0-0x0056bafd` remains correct; only the stale generated rows and invalid `Nested:-4` need cleanup through normal source-page edit plus validator refresh.

## Inference Research Guidance Check

The workflow requires separating IDA fact, documentation evidence, and inference. This report treats the raw bytes, instruction query, decompilation, xrefs, and signature/pointer searches as IDA-backed facts. Existing by-* pages and old B-agent reports are documentation evidence. Source names such as `IsLegacyAssetMode()` and `SetTextEditMode` remain source-facing inferences, with current support-doc backing.

Wave3 mentions in `wave3_data_issues.md` were used only as stale historical leads. The current recommendation is based on live IDA MCP and current by-* docs.

## Heuristic / Inference Reanalysis And Validation

Source-quality issues checked:

- Raw function boundary: IDA still has no function object at `0x0056baa0`, but instruction and byte evidence prove a constructor-shaped block ending with `retn` at `0x0056bafc`, followed by three `0xcc` padding bytes before the stubs.
- Start liveness: `xrefs_to 0x0056baa0` and `xrefs_to 0x0056bafd` return no refs; a little-endian pointer byte search for `a0 ba 56 00` returns no matches. This remains a reachability caveat.
- Constructor identity: the body calls the `TextEditPane` constructor helper, installs the three `GroupListPane` vtable views, returns `this`, and has byte-for-byte setup parity with inline child construction in `GroupPane` and `GroupPane2`.
- `dword_67AB24`: the constructor loads the global at `0x0067ab24` into `ecx` before `sub_4B60B0`, matching the inline parent copies. [UID:0000QX] owns this as `g_pFontImageLib`, but `sub_4B60B0` does not dereference it. Preserve the load as call-site codegen evidence, not helper semantics.
- `sub_4B60B0`: live decompile proves `BOOL sub_4B60B0() { return byte_66DA97 != 1; }`. Keep source-facing `IsLegacyAssetMode()` / `g_useEpfAssets` wording, not FontImageLib ownership.
- `sub_58DCE0`: live decompile confirms a `TextEditPane` constructor with 12 explicit source arguments after `this`. Current [UID:0000EO] has a formal constructor declaration, making target-level constructor C++ viable.
- `sub_58EA80`: not called by the raw constructor. It is parent inline setup only, called after `Pane::SetMode(1)`. Live disassembly/decompile shows it toggles `TextEditPane` flags at `+0x15c` and focus/active state from two char args; `SetTextEditMode(FALSE, FALSE)` remains the best descriptive role if parent docs need source wording.
- False virtual stubs: `0x0056bb00` and `0x0056bb10` are separate five-byte false-return vtable slots. Their final method names remain unresolved, but they are outside this target range and do not block the constructor body.
- Negative `Nested:-4`: invalid for this exact target. The raw constructor has no nested children; the following padding and stubs are outside the half-open range. Use `Nested:0`.

Rejected alternatives:

- Keep C++ blank solely because the target is not `95/95`: rejected by active workflow.
- Keep C++ blank solely because TextEditPane parameter names were once unavailable: rejected because [UID:0000EO] now has a formal constructor declaration and the exact positional call is live-confirmed.
- Treat `sub_4B60B0` as a FontImageLib method or resource-context function: rejected because the helper body reads only `byte_66DA97` and has broad UI/rendering callers.
- Merge `0x0056bafd-0x0056bb00` into the constructor or stubs: rejected by byte evidence; these are padding bytes.
- Merge the false virtual stubs into this target: rejected because IDA models `0x0056bb00` and `0x0056bb10` as separate tiny functions and vtable slots.
- Move ownership to `TextEditPane`: rejected because TextEditPane is the base constructor dependency; the vtable stores and parent fields are `GroupListPane`.
- Move ownership to `GroupPane` or `GroupPane2`: rejected because those parents inline the child setup but the child class and vtable data are distinct.
- Move ownership to `SpelledPane`: rejected because `0x0056bb20` is the next function with its own callers and class evidence.

## Evidence Standards Used

Evidence used:

- IDA MCP `server_health`, `lookup_funcs`, `entity_query`, `insn_query`, `get_bytes`, `make_signature_for_range`, `find_bytes`, `xrefs_to`, `disasm`, and `decompile`.
- Current by-* documentation for the target, class, file, vtable data, stubs, globals, and helper pages.
- Old B-agent reports only as leads; their MCP-unavailable conclusions were rechecked.
- Generated tracker/report rows only to identify stale generated state; they are not edited by this report.
- `tools/int_convert.py`, after reading its README, for decimal/hex conversions.

The evidence is strong enough for target-level constructor C++ because the exact body is short, unique, and duplicated inline in two parent constructors. Confidence stays below final-audit because of the no-function/no-inbound-xref raw start and provisional source-facing helper names.

## Evidence Checked

IDA MCP checks performed:

- `server_health` for session `80de0a67`.
- `lookup_funcs`/`entity_query` around `0x0056baa0-0x0056bb20`.
- `insn_query` over `0x0056baa0-0x0056bb00`.
- `get_bytes` at `0x0056ba99` and `0x0056bafd`.
- `make_signature_for_range 0x0056baa0-0x0056bb00`, unique.
- `find_bytes "a0 ba 56 00"`, no matches.
- `xrefs_to` for raw start/end, stubs, vtable bases, `sub_4B60B0`, `sub_58DCE0`, and support addresses.
- `disasm` and `decompile` for `0x0056c4c0`, `0x0056c770`, `0x004b60b0`, `0x0058dce0`, `0x0058ea80`, and `0x005446b0`.

Negative checks performed:

- No inbound xrefs to `0x0056baa0` or `0x0056bafd`.
- No little-endian pointer bytes to raw start.
- No child/subrange inside `0x0056baa0-0x0056bafd`.
- No `sub_58EA80` call in the raw constructor itself.
- No evidence that `g_pFontImageLib` owns or is dereferenced by `sub_4B60B0`.

No failed or unavailable MCP checks remain. Some broad xref calls produced large output, so the report relies on narrower follow-up queries and exact local disassembly windows.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| `0x0056baa0-0x0056bafd` is a `GroupListPane::GroupListPane()` body | High | Raw instructions call TextEditPane constructor and install three `GroupListPane` vtables; inline parent parity | No inbound refs, no IDA function object | Raw reachability remains a score cap, not an identity blocker |
| Direct owner/emitter is [UID:00005X] `GroupListPane` | High | Vtable names/stores, class page, parent child field `+0xf8`, vtable data page | TextEditPane, GroupPane, GroupPane2, SpelledPane alternatives rejected | None blocking |
| Source route is [UID:0000JS] `Group` | Medium-high | Group file owns GroupPane/GroupPane2 and class docs route here | A narrower `GroupPane.cpp` style file is plausible but not documented | Keep current file route until source tree proof changes |
| `sub_4B60B0` source role is `IsLegacyAssetMode()` | High behavior, medium exact spelling | Live decompile reads `byte_66DA97 != 1`; support page [UID:0003XA] | FontImageLib method rejected; helper body ignores `ecx` | Exact original spelling remains provisional |
| `sub_58DCE0` is `TextEditPane::TextEditPane(...)` | High role, medium parameter names | Live decompile signature, [UID:0000EO] declaration, 26 caller pattern | Exact parameter names still provisional | Does not block target positional constructor body |
| Target formal C++ is now first-draft ready | Medium-high | Routed reconstructable emitter above gate, exact short constructor, current TextEditPane declaration, no target-local unresolved fields | Raw no-xref start and class-level false virtual names checked | Keep score below 90+ final-audit; class block remains separate |
| `Nested` should be `0` | High | No child range inside exact half-open target | Stubs start after padding at `0x0056bb00` | Validator refresh should clear stale generated rows |

## Positive Evidence Summary

Direct facts supporting the recommendation:

- Raw instruction query shows a complete constructor-shaped body from `push ebp` at `0x0056baa0` through `retn` at `0x0056bafc`.
- Bytes at `0x0056bafd-0x0056bb00` are three `0xcc` padding bytes.
- The body calls `sub_4B60B0`, then `sub_58DCE0` with the fixed `TextEditPane` argument pattern, then writes `GroupListPane` vtable pointers at offsets `+0x0`, `+0xa0`, and `+0xa4`.
- The same constructor sequence appears inline in `GroupPane::GroupPane` at `0x0056c52c-0x0056c56e` and `GroupPane2::GroupPane2` at `0x0056c7dc-0x0056c81e`.
- The three `GroupListPane` vtable bases each have exactly three store refs: raw constructor plus the two inline parent constructors.
- The current `TextEditPane` class documentation now includes a formal constructor declaration compatible with the observed call shape.

Strongest inference chain:

The raw no-xref block is still class source, not dead unrelated bytes, because it performs the same derived construction sequence that parent source expresses as `new GroupListPane`. The source-level constructor body is the base initializer and empty body; vtable writes and return value are compiler mechanics. Therefore a first-draft constructor body is safer than leaving the formal C++ block blank under the active C++-eligible-emitter rule.

## IDA MCP Facts

Session facts:

- Active session: `80de0a67`
- IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Module: `NexusTK.exe`
- Image base: `0x400000`
- Auto-analysis ready: true
- Hex-Rays ready: true

Function/range facts:

- `0x0056baa0`: not an IDA function object.
- `0x0056bafd`: not an IDA function object.
- `0x0056bb00`: `sub_56BB00`, size `0x5`.
- `0x0056bb10`: `sub_56BB10`, size `0x5`.
- `0x0056bb15`: not a function object.
- `0x0056bb20`: `sub_56BB20`, size `0xbb`.
- `0x0056c4c0`: `sub_56C4C0`, size `0xf1`.
- `0x0056c770`: `sub_56C770`, size `0xf1`.
- `0x004b60b0`: `sub_4B60B0`, size `0x0d`.
- `0x0058dce0`: `sub_58DCE0`, size `0x452`.
- `0x0058ea80`: `sub_58EA80`, size `0xab`.
- `0x005446b0`: `sub_5446B0`, size `0x24`.

Raw constructor instruction facts:

- `0x56baa5`: `mov esi, ecx`
- `0x56baa7`: `mov ecx, dword ptr unk_67AB24`
- `0x56baad`: `push 0`
- `0x56baaf`: `push 1`
- `0x56bab4`: `call sub_4B60B0`
- `0x56bab9` through `0x56bad0`: pushes the remaining TextEditPane arguments.
- `0x56bad7`: `call sub_58DCE0`
- `0x56badc`: stores `??_7GroupListPane@@6B@`
- `0x56bae4`: stores `??_7GroupListPane@@6B@_0` at `+0xa0`
- `0x56baee`: stores `??_7GroupListPane@@6B@_1` at `+0xa4`
- `0x56bafc`: `retn`
- `0x56bafd`: `align 10h`

Data/table/padding facts:

- Bytes at `0x0056ba99` show seven `0xcc` bytes before the raw prologue.
- Bytes at `0x0056bafd` show three `0xcc` bytes, then `sub_56BB00` bytes `32 c0 c2 04 00`.
- `make_signature_for_range 0x0056baa0-0x0056bb00` returned a unique signature.
- `find_bytes "a0 ba 56 00"` returned zero matches.

Xref facts:

- `xrefs_to 0x0056baa0`: none.
- `xrefs_to 0x0056bafd`: none.
- `xrefs_to 0x00624214`: `0x56badc`, `0x56c55e`, `0x56c80e`.
- `xrefs_to 0x0062428c`: `0x56bae4`, `0x56c564`, `0x56c814`.
- `xrefs_to 0x006242bc`: `0x56baee`, `0x56c56e`, `0x56c81e`.
- `xrefs_to 0x0056bb00`: only data ref `0x00624294`.
- `xrefs_to 0x0056bb10`: only data ref `0x00624274`.
- `xrefs_to 0x004b60b0`: 33 code refs, including `0x56bab4`, `0x56c536`, and `0x56c7e6`.
- `xrefs_to 0x0058dce0`: 26 code refs, including `0x56bad7`, `0x56c559`, and `0x56c809`.

Helper facts:

- `decompile 0x004b60b0`: `return byte_66DA97 != 1`.
- `decompile 0x0058dce0`: thiscall constructor with 12 explicit arguments after `this`; relevant observed call is `sub_58DCE0(v2, 145, 84, 145, 84, 128, 0, 0, 1, 6, v3, 1, 0)`.
- `decompile 0x0058ea80`: two char args toggle `TextEditPane` flags at `this+0x15c`, focus/active state, and selection/scroll refresh. Parent calls pass `(0, 0)`.
- `disasm 0x005446b0`: one char arg sets `this+0xb5` and invalidates via vtable slot; support docs name it `Pane::SetMode`.

Numeric conversion facts from `tools/int_convert.py`:

- `0x174` = 372
- `0xf8` = 248
- `0xa0` = 160
- `0xa4` = 164
- `0x91` = 145
- `0x54` = 84
- `0x80` = 128
- `0x5d` = 93
- `0x3` = 3
- `0x15c` = 348
- `0x0d` = 13
- `0xab` = 171
- `0xbb` = 187

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0056baa0-0x0056bafd` | [UID:0001H8](../../../../../by-memory/0x0056baa0-0x0056bafd.GroupListPaneRawConstructor.md) | Raw/manual `GroupListPane` constructor | TRUE | [UID:00005X] | current `86/89`, recommend `89/91` | Keep exact range; add C++ |
| `0x0056bafd-0x0056bb00` | no by-memory child | Padding | n/a | n/a | n/a | Three `0xcc` bytes; keep outside target |
| `0x0056bb00-0x0056bb15` | [UID:0001H9](../../../../../by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md) | Two false virtual stubs plus internal padding | TRUE | [UID:00005X] | `85/90` | Keep separate |
| `0x0056bb15-0x0056bb20` | ignored padding in docs | Padding | n/a | n/a | n/a | Keep outside stubs and SpelledPane |
| `0x0056bb20-0x0056c3f1` | [UID:0001HA](../../../../../by-memory/0x0056bb20-0x0056c3f1.SpelledPane.md) | Neighbor `SpelledPane` code | TRUE | SpelledPane class | not target | Rejected as owner |
| `0x00624210-0x006242c4` | [UID:0002NI](../../../../../by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md) | GroupListPane vtable data | TRUE | [UID:0001XP] | `87/92` | Support evidence |
| `0x0056c4c0-0x0056e939` | [UID:0001HC](../../../../../by-memory/0x0056c4c0-0x0056e939.GroupPanes.md) | Parent pane aggregate | FALSE | [UID:0000JS] | `88/90` | Inline parity support only |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0056baa0` | no xrefs; no pointer bytes found | Raw constructor start is not a live entry target in IDA |
| `0x0056bafd` | no xrefs | End padding boundary is clean |
| `0x0056badc` | data ref to `0x00624214` | Raw primary vtable store |
| `0x0056bae4` | data ref to `0x0062428c` | Raw secondary vtable store at `+0xa0` |
| `0x0056baee` | data ref to `0x006242bc` | Raw tertiary vtable store at `+0xa4` |
| `0x0056c55e/0x0056c564/0x0056c56e` | stores same vtable bases | `GroupPane` inline child construction |
| `0x0056c80e/0x0056c814/0x0056c81e` | stores same vtable bases | `GroupPane2` inline child construction |
| `0x0056bb00` | data ref from `0x00624294` | False virtual stub slot |
| `0x0056bb10` | data ref from `0x00624274` | False virtual stub slot |
| `0x004b60b0` | raw and parent constructor calls | Legacy/non-EPF mode query |
| `0x0058dce0` | raw and parent constructor calls | `TextEditPane` base construction |
| `0x005446b0` | parent calls only | `Pane::SetMode(1)` after child allocation |
| `0x0058ea80` | parent calls only | TextEditPane editable/active state after `SetMode` |

## Documentation Evidence And IDA Status

Existing docs supporting the conclusion:

- Target page already records exact raw constructor behavior and parent parity.
- `GroupListPane` class page records thin `TextEditPane`-derived child shape and no class-local fields beyond inherited layout.
- `Group` file page correctly routes the class/source ownership through `social/Group.cpp`.
- Vtable data page confirms the three `GroupListPane` vtable views and slot refs.
- `TextEditPane` class page now supplies a formal constructor declaration.
- `PaneSetMode` page supplies the accepted `Pane::SetMode` name for parent setup.
- `ClanStatusPaneConstructor` precedent shows first-draft C++ can use a descriptive `SetTextEditMode(FALSE, FALSE)` style helper while exact helper spelling remains provisional; here, `sub_58EA80` is outside the target constructor body.

Stale or incomplete docs:

- Target page C++ rationale still says the constructor should not emit because `TextEditPane` parameter names and related virtual names are not final. That is now too broad for this narrow target.
- Class/file/aggregate docs still mention "TextEditPane signature" as a main blocker. They should be updated to distinguish target-level constructor readiness from class-level false-virtual/helper-name polish.
- Generated tracker/coverage rows still mention the old `0x0056baa0-0x0056bb00` path and old `74/84` score.
- Target `Nested:-4` is invalid for the current exact range.

Generated/coverage report state:

- `auto-generated/-ag-research-tracker.md` still references old path `0x0056baa0-0x0056bb00`.
- `auto-generated/-ag-coverage-report-by-memory.md` still references old path and reports file-missing stale state.
- `project-level/-auto-completion-stats.md` still has old `74/84` state.
- These are generated/project-level read-only for this assignment. Do not edit them manually; validator/supervisor refresh should update them after source-page edits.

## Ranked Ownership Analysis

### 1. GroupListPane / [UID:00005X]

- Evidence for: three decorated `GroupListPane` vtable stores, vtable data child, false stub slots, parent `GroupPane`/`GroupPane2 +0xf8` child field, exact inline construction parity, current class page above gate.
- Evidence against: raw start has no IDA function object or inbound refs; false virtual method names unresolved.
- Decision: keep as direct canonical owner and emitter.

### 2. Group file / [UID:0000JS]

- Evidence for: parent panes and child class are in Group social UI family; current proposed source tree and by-file docs route GroupListPane under `social/Group.cpp`.
- Evidence against: a narrower historical file such as `GroupPane.cpp` is plausible but not currently documented/proved.
- Decision: keep [UID:0000JS] as file/source route; do not create a new file owner.

### 3. Rejected owners

- `TextEditPane`: owns the base constructor and shared editor methods, not the derived vtables.
- `GroupPane` / `GroupPane2`: own inline parent constructors and child field storage, not the child class constructor body.
- `FontImageLib`: `g_pFontImageLib` is loaded before helper calls, but `sub_4B60B0` reads only `byte_66DA97`.
- `SpelledPane`: neighbor at `0x0056bb20`; separate class/function evidence.
- Compiler-only/no-owner: rejected because the block has source constructor semantics, class vtables, and parent source parity.

## Source Placement

Recommended placement:

- Class: [UID:00005X] `GroupListPane`
- File/source route: [UID:0000JS] `Group`, currently `NexusTK/social/Group.cpp`
- Target method: `GroupListPane::GroupListPane()`

Why this fits:

- `GroupPane` and `GroupPane2` parent constructors live in the same `Group` family and inline the same child construction.
- The child is stored at parent offset `+0xf8` as `m_groupListPane`.
- Current by-project source tree explicitly lists `GroupListPane` as a real text-list child for `GroupPane`/`GroupPane2` under `Group.cpp`.

Remaining placement uncertainty:

- A narrower original file split cannot be ruled out, but no current source-tree evidence beats [UID:0000JS]. This uncertainty is not enough to change owner/emitter or block target constructor C++.

## Range / Split / Padding / Reclassification Analysis

Exact range/boundary facts:

- Keep `0x0056baa0-0x0056bafd` as target half-open range.
- `0x0056baa0` is the first prologue byte.
- `0x0056bafc` is `retn`.
- `0x0056bafd-0x0056bb00` is three bytes of `0xcc` alignment padding.
- `0x0056bb00-0x0056bb05` is the first false-return stub.
- `0x0056bb10-0x0056bb15` is the second false-return stub.
- `0x0056bb15-0x0056bb20` is padding before the next function.
- `0x0056bb20` starts the next IDA function and is not part of this target.

Children/subranges:

- No nested children exist inside `0x0056baa0-0x0056bafd`.
- Change `Nested:-4` to `Nested:0`.
- Do not create, delete, merge, or rename by-memory children for this assignment.

Parent/container impact:

- The broad `GroupPanes` aggregate should keep its separate inline-construction notes and non-emitting status.
- The stale generated old path should be resolved through validator refresh, not by manual generated-file edits.

## Negative Evidence Summary

Checks and rejections:

- No IDA function object at the raw start: score cap, not ownership rejection.
- No xrefs or pointers to raw start: score cap and reachability caveat, not dead-code proof because parent constructors inline the same source.
- `g_pFontImageLib` load before `sub_4B60B0`: not FontImageLib ownership because helper body ignores `ecx`.
- `sub_58EA80` uncertainty: not a target-body blocker because the raw constructor does not call it.
- False virtual names unresolved: class-level declaration blocker, not constructor-body blocker.
- Stale generated tracker rows: read-only stale output, not evidence that live target file/path is wrong.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits are requested.

Source-facing names/types to use in docs:

- `GroupListPane::GroupListPane()` for the target.
- `TextEditPane::TextEditPane(...)` for `sub_58DCE0`.
- `IsLegacyAssetMode()` for `sub_4B60B0`, with a note that exact original spelling remains provisional and the helper returns `g_useEpfAssets != 1` / legacy-mode state.
- `g_pFontImageLib` for `dword_67AB24`, described as a call-site singleton load rather than helper ownership.
- `Pane::SetMode(1)` for `sub_5446B0` in parent inline setup.
- `TextEditPane` editable/active mode setter or descriptive `SetTextEditMode(FALSE, FALSE)` for `sub_58EA80` in parent inline setup, with exact spelling still provisional.
- `GroupListPane *m_groupListPane` for the parent `+0xf8` field.

Items intentionally left unresolved:

- Exact false virtual method names for [UID:0001H9].
- Exact original `IsLegacyAssetMode` spelling/source file.
- Exact enum names for TextEditPane flags and mode/style operands.

## First-Draft C++ Recommendation

Eligible for draft C++: yes.

Reason:

- Target is `RECONSTRUCTABLE:TRUE`.
- Emitter route is nonblank and above gate: [UID:00005X] `GroupListPane`.
- Target average score is already above 85, and current evidence improves it.
- The raw constructor has exact short behavior and no target-local unresolved fields.
- Current [UID:0000EO] has a formal `TextEditPane` constructor declaration.

Recommended exact formal C++ block to paste into [UID:0001H8] after supervisor approval:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
GroupListPane::GroupListPane()
    : TextEditPane(145, 84, 145, 84, 0x80, 0, 0, 1, 6,
                   IsLegacyAssetMode(), 1, 0)
{
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason it preserves original behavior:

- The initializer list is the source form of the observed `sub_58DCE0(this, 145, 84, 145, 84, 128, 0, 0, 1, 6, legacyMode, 1, 0)` call.
- The empty body is source form for "no class-local field writes after base construction"; the three `GroupListPane` vtable stores are compiler-generated derived-constructor mechanics.
- The function's return of `this`, stack frame, and `retn` are ABI/decompiler mechanics and should not be emitted.
- The `g_pFontImageLib` `ecx` load is not emitted because the accepted helper behavior is a global mode query that does not dereference the font-image singleton.

Reason it matches likely original source shape:

- Parent constructors source-shape as `new GroupListPane`, followed by parent-owned `SetMode(1)` and text-edit mode setup. The child constructor itself is naturally a no-argument derived constructor with a fixed `TextEditPane` base initializer.
- The class has no proved local fields beyond inherited `TextEditPane`/pane views.
- This matches B001's earlier source sketch, but now the target has live MCP proof and a current TextEditPane constructor declaration.

Naming/coding convention:

- Use `GroupListPane::GroupListPane()` from class/source docs.
- Use `TextEditPane(...)` base initializer from current class declaration.
- Use `IsLegacyAssetMode()` as the accepted project descriptive helper name, with score cap for exact spelling.
- Use `0x80` for the flag/color literal because docs and prior sketch preserve that operand as a bit/flag-like constant, while dimensional operands are clearer as decimals.

## Final Recommendation

Recommended target changes:

- Add the exact formal C++ block above.
- Change `COMPLETION` from `86` to `89`.
- Change `CONFIDENCE` from `89` to `91`.
- Keep `CANONICAL_OWNER:00005X`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:00005X`.
- Change `Nested:-4` to `Nested:0`.
- Update the body to distinguish target-level constructor C++ readiness from class-level false virtual name uncertainty.
- Preserve no-xref/raw-boundary negative evidence and generated-stale row warnings.

Recommended parent/support disposition:

- Keep [UID:00005X] `GroupListPane` class-level C++ blank until false virtual names and class declaration polish are accepted.
- Update class/file/aggregate wording so they no longer cite "TextEditPane signature unavailable" as the whole reason this constructor target stays blank.
- Do not change generated/project-level/coverage files manually.

## Recommended Target Doc Changes

Target path: [by-memory/0x0056baa0-0x0056bafd.GroupListPaneRawConstructor.md](../../../../../by-memory/0x0056baa0-0x0056bafd.GroupListPaneRawConstructor.md)

Exact report facts to incorporate:

- Live MCP session `80de0a67` on 2026-06-25 confirmed MCP/Hex-Rays ready.
- `0x0056baa0` and `0x0056bafd` are not IDA function objects.
- Raw instruction query confirms the full constructor-shaped body and vtable stores.
- `0x0056bafd-0x0056bb00` is three bytes of padding.
- Unique byte signature for `0x0056baa0-0x0056bb00`; no little-endian pointer bytes to start.
- No xrefs to raw start/end.
- Vtable base xrefs: raw plus two inline parent stores for each of `0x00624214`, `0x0062428c`, and `0x006242bc`.
- Parent constructors `0x0056c4c0` and `0x0056c770` decompile to identical inline child setup with `sub_58DCE0(v2, 145, 84, 145, 84, 128, 0, 0, 1, 6, sub_4B60B0(), 1, 0)`.
- `sub_4B60B0` decompiles to `byte_66DA97 != 1`.
- `sub_58EA80` is parent-only TextEditPane editable/active mode setup, not part of the raw constructor.
- `Nested` must be `0`.

Metadata/score/C++ changes:

- `COMPLETION:89`
- `CONFIDENCE:91`
- keep owner/emitter/reconstructable fields
- add formal C++ block above
- change `Nested` to `0`

Historical/stale assumptions to preserve as rejected:

- Old generated `0x0056baa0-0x0056bb00` path is stale.
- Old `sub_4B60B0` resource/context wording is wrong.
- Old "wait for 95/95 before C++" blocker is not applicable.
- No-direct-xref caveat remains true and should be preserved.

Recommended replacement item summary:

`Live IDA MCP reconfirms the raw no-function constructor island, unique byte signature, no inbound/pointer refs, exact TextEditPane base-initializer constants, three GroupListPane vptr stores, inline GroupPane/GroupPane2 parity, and first-draft constructor C++ readiness.`

## Recommended Support Doc Changes

Support path: [by-class/GroupListPane.md](../../../../../by-class/GroupListPane.md)

- Keep class owner and likely file route unchanged.
- Keep class-level C++ blank for now, but update wording: target [UID:0001H8] can carry a first-draft constructor body; class-level block remains blank because false virtual slot names, final helper spelling, and full declaration polish remain unresolved.
- Replace stale "TextEditPane constructor signature not source-ready" as a blanket blocker with a narrower cap: TextEditPane constructor declaration exists, but parameter names/enum names remain provisional.
- Preserve no-direct-raw-constructor-xref caveat and inline parent parity.

Support path: [by-file/Group.md](../../../../../by-file/Group.md)

- Update the GroupListPane row/note to mention the 2026-06-25 target-level live MCP pass and recommended [UID:0001H8] first-draft constructor body.
- Keep route under `social/Group.cpp`.
- Preserve class-level C++ caveat for false virtual names and helper spelling.

Support path: [by-memory/0x0056c4c0-0x0056e939.GroupPanes.md](../../../../../by-memory/0x0056c4c0-0x0056e939.GroupPanes.md)

- Add a short support note that live MCP reconfirmed both parent constructors inline the exact `GroupListPane` child setup.
- Clarify that this aggregate remains non-emitting; the target-level constructor body belongs to [UID:0001H8], not the aggregate.
- Optionally replace `sub_58EA80` role wording with "TextEditPane editable/active mode setter" while keeping exact spelling provisional.

Support path: [by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md](../../../../../by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md)

- Add live 2026-06-25 xref proof for vtable bases if desired: each of `0x00624214`, `0x0062428c`, and `0x006242bc` has raw plus two inline parent store refs.
- No score/owner change required.

Support path: [by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md](../../../../../by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md)

- No required metadata change.
- Optionally add current xref proof that the stubs remain vtable-only and outside [UID:0001H8].

Support path: [by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md](../../../../../by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md)

- No required metadata change.
- No C++ change requested here; the exact helper spelling/source-file pass remains out of scope.

Support path: [by-class/TextEditPane.md](../../../../../by-class/TextEditPane.md)

- No required metadata change.
- No direct edit required for this callback unless supervisor wants to add [UID:0001H8] as a constructor-call consumer using the current formal TextEditPane constructor declaration.

## Score And Metadata Recommendation

Current score/metadata:

- `86/89`
- owner/emitter [UID:00005X]
- `RECONSTRUCTABLE:TRUE`
- formal C++ blank
- `Nested:-4`

Recommended score/metadata:

- `89/91`
- owner/emitter unchanged
- `RECONSTRUCTABLE:TRUE` unchanged
- formal C++ populated with target-level constructor body
- `Nested:0`

Score rationale:

- Completion rises because the target now has live MCP-backed range proof, helper proof, vtable xrefs, inline parent parity, a fixed `Nested` recommendation, and first-draft C++.
- Confidence rises because the body is short, unique, and matches two parent inline copies.
- Not higher than `89/91` because the raw start still lacks IDA function/xrefs, helper names and enum/parameter names are still provisional, and the class-level false virtual names remain unresolved.

Score-improvement attempt:

- Raw boundary blocker: checked with `insn_query`, `get_bytes`, `lookup/entity` evidence; resolved for exact range, still a reachability caveat.
- No-xref blocker: checked with `xrefs_to` and pointer byte search; remains true, but reclassified as score cap rather than C++ blocker because inline parent parity proves source shape.
- `sub_4B60B0` blocker: resolved to `IsLegacyAssetMode()` behavior with live decompile.
- `sub_58DCE0` blocker: reduced by current TextEditPane class declaration and live call shape; parameter names remain a score cap.
- `sub_58EA80` blocker: moved out of target-body blocker because it is parent-only setup.
- Negative `Nested` blocker: exact recommendation `Nested:0`.

## Open Questions With Attempted Resolution

Open question: Is the raw constructor callable source or dead code?

- Evidence checked: no IDA function object, no xrefs, no pointer bytes, exact parent inline copies.
- Resolution: no direct callable evidence exists, but class constructor source is still proved by inline parent construction and vtable stores. Treat raw block as a retained/manual constructor body with a reachability caveat, not dead unrelated bytes.

Open question: Should `g_pFontImageLib` appear in source code?

- Evidence checked: raw/parent constructors load `dword_67AB24` into `ecx`; `sub_4B60B0` body ignores `ecx` and reads `byte_66DA97`.
- Resolution: do not emit `g_pFontImageLib` in the constructor C++ block. Preserve it as codegen/call-site evidence.

Open question: Is `IsLegacyAssetMode()` final spelling?

- Evidence checked: [UID:0003XA] support page and live decompile.
- Resolution: behavior is exact; spelling is accepted descriptive but below final-audit. Use it in first-draft C++ with score cap.

Open question: Does unresolved `sub_58EA80` block target C++?

- Evidence checked: raw constructor contains no `sub_58EA80`; parent constructors call it after storing/enabling the child.
- Resolution: no target-body block. Keep as support/class aggregate naming cap only.

Open question: Do false virtual names block target C++?

- Evidence checked: stubs start after the target/padding and are separate functions/vtable slots.
- Resolution: they block full class declaration polish, not the target constructor body.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual supervisor-owned coverage/tracker text is proposed.

Do not edit validator-owned generated reports:

- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `project-level/-auto-completion-stats.md`

Expected generated refresh: after accepted by-* edits and scoped validators, generated rows should stop pointing at old `0x0056baa0-0x0056bb00` / `74/84` state and should reflect the live target path, `Nested:0`, and updated item summary.

## Follow-Up Actions

Supervisor actions:

- Final supervisor verification can consume the implementation proof and checklist below.
- No additional B007 by-* edit is pending for this accepted callback.

A-agent actions:

- None required for this completed callback.

B007 actions:

- None for this callback unless the supervisor sends a new assignment.

## Confidence

- Recommendation confidence: high.
- Score confidence: medium-high.
- Remaining uncertainty: exact source spelling for `IsLegacyAssetMode`, TextEditPane parameter/enum names, and false virtual method names. These cap score but do not block the target constructor body.

## Validator Results

- Implementation validator batch run from `E:\NTK\GhidraBridge\source-3\project-documentation` after applying the accepted callback edits:
  - `python .\tools\validator.py --mode file --file by-memory\0x0056baa0-0x0056bafd.GroupListPaneRawConstructor.md --apply --queue-timeout 240`
    - `command_id: 000000002075`
    - `command_timestamp: 2026-06-26T01:36:12-04:00`
    - Exit code `0`, `ok: 1`.
    - Relevant updates: path update from stale `0x0056baa0-0x0056bb00` registry path, target `completion_update 89`, `confidence_update 91`, owner/emitter/autogen registry updates, C++ block changed from blank to block, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-class\GroupListPane.md --apply --queue-timeout 240`
    - `command_id: 000000002079`
    - `command_timestamp: 2026-06-26T01:36:56-04:00`
    - Exit code `0`, `ok: 1`.
    - Relevant updates: class `completion_update 87`, `confidence_update 89`, `canonical_owner_update 0000JS`, autogen registry update, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-file\Group.md --apply --queue-timeout 240`
    - `command_id: 000000002080`
    - `command_timestamp: 2026-06-26T01:37:03-04:00`
    - Exit code `0`, `ok: 1`.
    - Relevant updates: `canonical_owner_update 0000JS FILE`, projected-stats update, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-memory\0x0056c4c0-0x0056e939.GroupPanes.md --apply --queue-timeout 240`
    - `command_id: 000000002081`
    - `command_timestamp: 2026-06-26T01:37:10-04:00`
    - Exit code `0`, `ok: 1`.
    - Relevant updates: aggregate `completion_update 88`, `confidence_update 90`, `canonical_owner_update 0000JS`, `autogen_registry_update true -> false`, generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-memory\0x00624210-0x006242c4.GroupListPaneVtableData.md --apply --queue-timeout 240`
    - `command_id: 000000002082`
    - `command_timestamp: 2026-06-26T01:37:19-04:00`
    - Exit code `0`, `ok: 1`.
    - Relevant updates: vtable page `completion_update 87`, `confidence_update 92`, `canonical_owner_update 0001XP`, autogen registry update, generated refresh deferred.
  - Final target-only revalidation after removing a duplicate prose C++ code fence from the target body:
    - `python .\tools\validator.py --mode file --file by-memory\0x0056baa0-0x0056bafd.GroupListPaneRawConstructor.md --apply --queue-timeout 240`
    - `command_id: 000000002089`
    - `command_timestamp: 2026-06-26T01:40:28-04:00`
    - Exit code `0`, `ok: 1`.
    - Relevant warnings: existing `missing_ref_uid 0003XA`; generated refresh deferred.
  - Final class-only revalidation after removing a duplicate prose C++ code fence from the class page:
    - `python .\tools\validator.py --mode file --file by-class\GroupListPane.md --apply --queue-timeout 240`
    - `command_id: 000000002092`
    - `command_timestamp: 2026-06-26T01:42:01-04:00`
    - Exit code `0`, `ok: 1`.
    - Relevant warnings: existing `missing_ref_uid 0003XA`; generated refresh deferred.
  - `python .\tools\validator.py --queue-status`
    - `command_id: 000000002098`
    - `command_timestamp: 2026-06-26T01:45:27-04:00`
    - Final queue state after target and class cleanup leases were released: worker running, `queued jobs: 0`, `processing jobs: 0`, `queued generated refresh jobs: 0`, `processing generated refresh jobs: 0`.
- Validator warnings/side effects:
  - Existing missing-reference warnings remain for `0003XA` because the referenced `IsLegacyAssetMode` support UID is not currently present in `validator.ini`; the support page exists and was not edited in this callback.
  - Existing stale `00023W` references still point at old `by-memory/0x0056c4a0-0x0056c4b5.GroupPaneFalseVirtualStubs.md` in some docs while the current document target is `LegendPaneFalseVirtualStubs`; this was outside the accepted callback and not hand-repaired.
  - Single-file validators updated validator-managed metadata and projected/generated refresh state. No generated, project-level, coverage-report, tool-state, or IDA DB file was manually edited by B007.

## Changed Files

Created during report-only pass:

- `tools/leaser/Agents/Agent-B007/research/0001H8-GroupListPaneRawConstructor-source-quality.md`

Modified during implementation callback:

- `by-memory/0x0056baa0-0x0056bafd.GroupListPaneRawConstructor.md`
- `by-class/GroupListPane.md`
- `by-file/Group.md`
- `by-memory/0x0056c4c0-0x0056e939.GroupPanes.md`
- `by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md`
- `tools/leaser/Agents/Agent-B007/research/0001H8-GroupListPaneRawConstructor-source-quality.md`

Not edited:

- `by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md`: accepted outside-range/vtable-only stub facts were already present at same-or-greater detail, so no edit or validator was required.
- Generated files, project-level files, coverage reports, validator/tool state files by hand, and IDA DB.

Report execution:

- Implementation callback completed by B007. Any final supervisor-owned `execute_report` verification remains outside this B-agent edit pass.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: implementation callback approved on 2026-06-26.
- [x] Target doc to update: `by-memory/0x0056baa0-0x0056bafd.GroupListPaneRawConstructor.md`. Proof: metadata/C++/evidence/item summary/Nested updated and validator `000000002075` passed.
- [x] Support docs to update if accepted: `by-class/GroupListPane.md`, `by-file/Group.md`, `by-memory/0x0056c4c0-0x0056e939.GroupPanes.md`, and optionally `by-memory/0x00624210-0x006242c4.GroupListPaneVtableData.md` / `by-memory/0x0056bb00-0x0056bb15.GroupListPaneVirtualStubs.md`. Proof: first four required support pages plus vtable page updated; virtual-stub page already contained the accepted outside-range/vtable-only facts.
- [x] Current target state recorded: `86/89`, owner/emitter [UID:00005X], `RECONSTRUCTABLE:TRUE`, blank C++, invalid `Nested:-4`. Proof: preserved in Current Target State and implementation change notes.
- [x] Actual live MCP evidence recorded: session `80de0a67`, no IDA function at raw start/end, exact raw instruction body, unique signature, no pointer bytes to start, no xrefs to start/end, three vtable-store xref sets, parent inline parity, helper decompiles. Proof: target IDA MCP evidence section updated; vtable page also records current xref triplets.
- [x] Metadata/score changes to apply: target `89/91`, keep owner/emitter/reconstructable, set `Nested:0`. Proof: target header updated and validator `000000002075` recorded `completion_update 89` and `confidence_update 91`.
- [x] First-draft C++ to apply exactly as listed in this report. Proof: formal target C++ block now contains the accepted `GroupListPane::GroupListPane()` initializer.
- [x] Source-quality names to apply/preserve: `GroupListPane::GroupListPane`, `TextEditPane::TextEditPane`, `IsLegacyAssetMode`, `g_pFontImageLib`, `Pane::SetMode`, descriptive TextEditPane editable/active mode helper for parent-only `sub_58EA80`, and `GroupListPane *m_groupListPane`. Proof: target/class/file/aggregate text updated with those source-facing roles and caveats.
- [x] Split/range/padding decisions to apply: keep `0x0056baa0-0x0056bafd`; keep `0x0056bafd-0x0056bb00` padding outside target; keep [UID:0001H9] separate; no rename/new child. Proof: target Covered Range/Historical sections and support docs preserve this.
- [x] Historical/stale assumptions to preserve as rejected: stale old path/score generated rows, stale `sub_4B60B0` resource-context model, old blank-C++ blocker, no-direct-xref caveat. Proof: target Historical / Rejected Assumptions plus support wording.
- [x] Open questions documented with evidence-backed resolutions: raw reachability, `g_pFontImageLib` source non-emission, `IsLegacyAssetMode` spelling, parent-only `sub_58EA80`, false virtual names. Proof: target Reconstruction Notes/Source Quality Notes and class/aggregate caveats.
- [x] Wave3/stale artifacts encountered and treated as historical leads only. Proof: stale generated path and stale blank-C++ blocker are preserved as rejected assumptions; no Wave3/generated state was treated as authority.
- [x] Validators to run after implementation: target validator plus accepted support validators listed above. Proof: validators `000000002075`, `000000002079`, `000000002080`, `000000002081`, `000000002082`, final target revalidation `000000002089`, and final class revalidation `000000002092` all exited `0` with `ok: 1`; stub validator not run because no stub edit was made.
- [x] Generated report refresh expected through validators/supervisor; no manual generated/project-level/coverage edits. Proof: validators reported generated refresh deferred, final queue status `000000002098` showed no queued or processing generated refresh jobs, and no manual generated/project-level/coverage edits were performed.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: 2026-06-26 implementation callback for this exact report.
- [x] Leases taken for accepted target/support docs before edits. Proof: initial `leaser.py B007 lease` returned `Success` for the target, `GroupListPane.md`, `Group.md`, `GroupPanes.md`, and `GroupListPaneVtableData.md`; later target-only and class-only cleanup leases also returned `Success`.
- [x] Leases released or expired immediately after validation batch. Proof: the initial `leaser.py B007 unlease ...` returned `Rejected[No active lease]` for all five files because the short leases had already expired; the later target-only and class-only leases released with `Success`; `tools/leaser/Agents/current_leases.md` and `tools/leaser/Agents/Agent-B007/current_leases.md` had no B007 rows afterward.
- [x] Target metadata, C++ block, `Nested:0`, item summary, and evidence sections incorporated at report-level detail. Proof: target page updated; validator `000000002075` passed.
- [x] Support docs updated or explicitly marked already-present/not-applicable per supervisor acceptance. Proof: class/file/aggregate/vtable pages updated; stub page marked already present with no edit.
- [x] Historical/stale assumptions and negative evidence preserved. Proof: target Historical / Rejected Assumptions includes stale old path, stale helper model, old code-entry blocker, and no-direct-xref caveat; support docs keep class-level caveats.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale. Proof: target and support docs distinguish raw reachability score cap, non-emitted `g_pFontImageLib` load, inferred `IsLegacyAssetMode()` spelling, parent-only `sub_58EA80`, and false virtual name caveats.
- [x] Scoped validators run and results recorded. Proof: see Validator Results above.
- [x] Generated report refresh confirmed by validator/supervisor flow, with no manual edits to generated/project-level/coverage/tool-state files. Proof: final validator queue status `000000002098` shows no queued/processing generated refresh jobs after the batch and cleanup revalidations; generated/project-level/coverage files were not manually edited.
- [x] Remaining unapplied accepted items listed with exact blocker, if any. Proof: none remain; only intentionally unedited optional stub page was already present at same-or-greater detail.

## Implementation Proof

- MCP availability: available and used. Session `80de0a67` responded to `server_health`, `lookup_funcs`, and `xrefs_to` during implementation; no `PAUSED_MCP_UNAVAILABLE` condition occurred.
- Leases: five edit files leased successfully; cleanup found no active lease because the short leases had already expired; final target-only and class-only cleanup leases were taken and released successfully; post-check current lease reports had no B007 entries.
- Validators: five scoped validators plus final target and class revalidations run, each exit code `0`, each `ok: 1`; final queue status `000000002098` showed no pending generated refresh.
- Manual exclusions honored: no generated files, project-level files, coverage-report files, tool-state files, or IDA DB were manually edited; no subagents were spawned.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0001H8-GroupListPaneRawConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0001H8-GroupListPaneRawConstructor-source-quality.md","timestamp":"2026-06-26T01:49:10","uid":"0001H8"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
