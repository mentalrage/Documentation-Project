** TARGET-REPORT-UID:0002KN **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002KN ClearParcelPaneSingleton Source-Quality / Heuristic Report

Prepared: 2026-06-18

Target: [UID:0002KN][0x00546e80-0x00546e8b.ClearParcelPaneSingleton](../../../../../by-memory/0x00546e80-0x00546e8b.ClearParcelPaneSingleton.md)

## Finalized Report / Current Recommendation

- Current recommendation: reclassify [UID:0002KN] from a reconstructable [UID:0000MF][ParcelPane] file-scope helper to a non-emitting compiler/EH cleanup funclet.
- Final disposition: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++.
- Required action: update the target metadata/body, by-memory coverage row, aggregate table row, ignored ledger, and support-doc wording listed below.
- Confidence: very strong for exact binary behavior, range, global identity, and cleanup-funclet role; no recoverable source helper name/signature is proven.

Recommended target metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended documentation role/name:

```text
ParcelPaneConstructorUnwindClearSingleton
```

This is a descriptive binary documentation name, not a recovered source symbol. The current filename can remain if the supervisor prefers minimal churn, but the page title/status should stop describing the range as a source helper.

## Supporting Research

## Target

- Target UID: `0002KN`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00546e80-0x00546e8b.ClearParcelPaneSingleton.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B006\research\0002KN-ClearParcelPaneSingleton-source-quality.md`
- Current target metadata: `86/91`, `CANONICAL_OWNER:0000MF`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000MF`, blank C++.
- Current coverage row state: stale `reconstructable : 80% : strong` row under [UID:0001EH].
- Current supervisor classification: report-only B-preferred source-quality and heuristic/inference pass, follow-up from accepted [UID:0002KM] report.

## Executive Recommendation

[UID:0002KN] should not remain reconstructable under [UID:0000MF]. The range is an exact 11-byte (Verified with int_convert.py from `0x0b`) cleanup target that writes zero to [UID:0000RY][g_pParcelPane](../../../../../by-global/g_pParcelPane.md) and returns. It has no callees, no ordinary source caller route, no extra VA/RVA pointer hits, and two constructor/EH unwind xrefs:

- `0x00605be2` / `Unwind@00605bd9`, associated with [UID:0001EG][ParcelIconPaneConstructor].
- `0x00605c38` / `Unwind@00605c2f`, associated with [UID:0002KB][ParcelPaneConstructor].

The two xrefs are the target-specific difference from [UID:0002KM]. They strengthen, not weaken, the non-emitting classification: this helper is reused by both the outer `ParcelIconPane` constructor's inline child-`ParcelPane` construction unwind path and the standalone `ParcelPane` constructor unwind path. Neither constructor decompilation has an ordinary call to `sub_546E80`; both constructors write `g_pParcelPane` inline and the helper appears only through EH/unwind metadata.

Source-level replacement/procurement:

- [UID:0001EG] carries the outer `ParcelIconPane` constructor and inline child `ParcelPane` allocation/setup, including `g_pParcelPane` writes at `0x00545f03` and `0x00545f0a`.
- [UID:0002KB] carries the standalone `ParcelPane` constructor, including `g_pParcelPane` writes at `0x005462e1` and `0x005462e8`.
- [UID:0001EK] carries the non-deleting `ParcelPane` destructor clear at `0x0054648d`.
- [UID:0001EP] carries the scalar deleting destructor clear at `0x00547054`.
- [UID:0002KK] documents the `FlyingParcelPane` animation consumer that reads/writes through `g_pParcelPane`.
- [UID:0000RY] and [UID:0002ZO] carry the source-declared global storage.
- [UID:0000A6] and [UID:0000MF] carry the class/module source context.

No first-draft C++ should be populated for [UID:0002KN].

## Supervisor Active Recheck

The assigned item is already an exact child range and does not require split repair.

The report-only boundary is respected: no target, coverage, generated, project-level, or unrelated by-* files were edited. The only created file is this research report.

The accepted [UID:0002KM] report was used only as a precedent to test against. The [UID:0002KN] decision is independently supported by its own bytes, xrefs, global lifecycle, two-constructor unwind routes, and lack of ordinary caller evidence.

## Inference Research Guidance Check

Facts:

- The executable range, bytes, disassembly, global store, no-callee state, negative literal pointer search, constructor/EH-style xrefs, and `g_pParcelPane` xref family are recorded by prior live IDA evidence in the target/support docs and by prewave IDA/Ghidra JSON exports.

Documentation evidence:

- [UID:0002KN] currently calls the range a reconstructable file-scope helper.
- [UID:0000RY] and [UID:0002ZO] identify `dword_69BA28` as `g_pParcelPane`, likely `ParcelPane*`.
- [UID:0000A6] and [UID:0000MF] still list this range as a clear helper, with [UID:0000MF] explicitly saying it remains queued for review.
- [UID:0002KM] has already been reclassified as the adjacent non-emitting singleton cleanup funclet.

Inference:

- The only defensible source-quality classification is compiler-generated constructor/EH cleanup. Keeping the page as a reconstructable helper would invent a source function not supported by any ordinary call route.

Current-session IDA MCP status:

- `http://127.0.0.1:13337/mcp` refused connection.
- `Test-NetConnection 127.0.0.1 -Port 13337` returned `TcpTestSucceeded: False`.
- This report therefore uses prior live IDA records and prewave exports as evidence. The current-session limitation is not material to the recommendation because the relevant IDA facts are already written in the target/support docs and corroborated by exports.

## Heuristic / Inference Reanalysis And Validation

### H001: Exact Range, Bytes, Padding, And Split State

Evidence checked:

- Target page prior live IDA: `lookup_funcs` resolves `0x00546e80` as `sub_546E80`, size `0x0b`.
- `0x0b` is 11 decimal bytes (Verified with int_convert.py).
- Target disassembly: `mov dword ptr unk_69BA28, 0` at `0x00546e80`, `retn` at `0x00546e8a`.
- Prewave IDA/Ghidra export gives size 11 in both tools and decompiles to `dword_69BA28 = 0;` / `DAT_0069ba28 = 0; return;`.
- Raw bytes: `c7 05 28 ba 69 00 00 00 00 00 c3`.
- Prior `get_bytes 0x00546e70+0x20` records sibling [UID:0002KM] bytes, five `0xcc` bytes at `0x00546e7b-0x00546e80`, this helper's bytes, then successor thunk bytes beginning at `0x00546e8b`.
- [UID:0001EM] begins at `0x00546e8b`.

Rejected alternatives:

- Merge with [UID:0002KM]: rejected by five-byte `0xcc` padding and different global targets.
- Widen into [UID:0001EM]: rejected because this helper's `ret` is at `0x00546e8a` and the adjustor-thunk island starts immediately at `0x00546e8b`.
- Treat post-target bytes as padding: rejected; there is no after-padding for this helper. The next byte is the first byte of [UID:0001EM].

Final inference: exact standalone binary function at `0x00546e80-0x00546e8b`; no split, merge, or range edit is needed.

Impact:

- Range confidence is very strong.
- Classification can change without range churn.

### H002: Direct Caller, Ordinary Caller, And EH Reachability

Evidence checked:

- Target page: `callees 0x00546e80` is empty.
- Target page: literal byte searches for absolute VA `80 6E 54 00` and RVA `80 5E 14 00` found no extra pointer hits.
- Prewave export: Ghidra records two callers, both named `Unwind@...`.
- Prewave export: IDA `xrefs_to` records:
  - `0x00605be2`, `from_name: sub_545E40`, type `JUMP_NEAR`;
  - `0x00605c38`, `from_name: sub_546290`, type `JUMP_NEAR`.
- Prewave export for [UID:0001EG] constructor decompilation does not call `sub_546E80`; it writes `DAT_0069ba28` / `dword_69BA28` inline during child construction.
- Prewave export for [UID:0002KB] constructor decompilation does not call `sub_546E80`; it writes `DAT_0069ba28` / `dword_69BA28` inline during standalone construction.
- Both constructors have MSVC-style EH setup in the Ghidra decompilation (`ExceptionList`, local EH state, `puStack_c` pointing into the `0x00605b..` / `0x00605c..` labels).

Rejected alternatives:

- Recoverable source call: rejected because neither constructor lists the helper as a callee and the only caller names are `Unwind@...`.
- Source-level callback/table route: rejected because the negative literal VA/RVA search found no extra pointer table hits and no vtable/global table names target this address.
- Dead code: rejected because the EH/unwind metadata xrefs prove binary reachability.

Final inference: indirectly reachable constructor cleanup funclet used by EH/unwind paths, not an ordinary source-callable helper.

Impact:

- `RECONSTRUCTABLE:FALSE` is correct for this exact range.
- Source-level semantics move to the constructors/destructors/global docs.

### H003: Source-Authored Helper Or Compiler Cleanup?

Evidence checked:

- The body is exactly one absolute store plus `ret`.
- It has no callees and no ordinary direct caller evidence.
- Both references are constructor/unwind routes.
- The constructors already contain the source-level global assignment/fallback logic inline.
- Accepted [UID:0002KM] now classifies the adjacent same-shape helper as non-emitting constructor/EH cleanup.
- Same-shape precedents [UID:0001EZ][ClearPatchPane2Singleton], [UID:0001K4][ClearThreadManSingleton], and [UID:0003SY][WorldMapPaneSingletonClearCleanupThunk] use `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters, and blank C++ for one-store singleton clears reached only by cleanup metadata.

Rejected alternatives:

- `static void ClearParcelPaneSingleton()`: rejected as a fake source helper. No ordinary call route proves a handwritten function.
- `ParcelPane::ClearSingleton()`: rejected because no class method receiver exists; the function takes no `this`, uses absolute storage, and is referenced through EH metadata.
- File-owned helper in `ParcelPane.cpp`: rejected because [UID:0000MF] is source context for the lifecycle, not a proof that this compiler funclet should emit.

Final inference: compiler-generated constructor/EH cleanup funclet.

Impact:

- Recommended metadata: `NONE/FALSE/blank emitters`.
- Coverage should move to `ignored`.
- No formal C++ should be populated.

### H004: Global Identity, Type, And Ownership

Evidence checked:

- Target store address is `0x0069ba28`.
- [UID:0000RY][g_pParcelPane] records `0x0069ba28` as `dword_69BA28`, size 4, `.data`, likely type `ParcelPane*`, owner/emitter [UID:0000MF].
- [UID:0002ZO][0x0069ba28-0x0069ba2c.g_pParcelPane] verifies exact four-byte storage with bytes `00 00 00 00`, proposed symbol `g_pParcelPane`, type `ParcelPane *`, and boundary neighbors.
- `project-level/-resolved.md` maps `dword_69BA28 -> g_pParcelPane`.
- `project-level/-unresolved.md` still lists `unk_69BA28` only from the target page's older IDA wording.
- The xref family is parcel-specific: constructor writes, destructor clears, animation consumer reads/writes, this helper, and scalar deleting destructor clear.

Rejected alternatives:

- `g_pPatchPane2`: rejected because that is adjacent `0x0069ba2c`, [UID:0002ZP], not part of this four-byte slot.
- `g_pParcelIconPane`: rejected because that is [UID:0000RX] at `0x0069b4d0`.
- Generic `unk_69BA28`: rejected as stale IDA spelling superseded by [UID:0000RY]/[UID:0002ZO].

Final inference: `dword_69BA28` is source-facing `g_pParcelPane`, likely `ParcelPane*`, declared in the parcel notification source module.

Impact:

- The global docs should remain reconstructable/emitting under [UID:0000MF].
- The cleanup helper itself should not emit.
- Target text should replace/qualify `unk_69BA28` with `dword_69BA28` / `g_pParcelPane`.

### H005: ParcelPane Versus ParcelIconPane Source Context

Evidence checked:

- [UID:0001EG] is a `ParcelIconPane` constructor that allocates a 292-byte child `ParcelPane` (Verified with int_convert.py from `0x124`) and writes `g_pParcelPane`.
- [UID:0002KB] is the standalone `ParcelPane` constructor and writes the same singleton.
- [UID:0000A5] describes the outer parcel icon pane and child pointer ownership.
- [UID:0000A6] describes the child two-slot parcel alert pane and `g_pParcelPane` singleton.
- [UID:0000MF] groups `ParcelIconPane`, `ParcelPane`, `FlyingParcelPane`, both parcel globals, and parcel alert resources in one likely `ParcelPane.cpp` source module.

Rejected alternatives:

- Attach the cleanup funclet to [UID:0000A5] because one xref comes from the outer constructor: rejected because the stored global and one constructor route belong to the child `ParcelPane`, and neither route is a source method call.
- Attach the cleanup funclet to [UID:0000A6] because it clears `g_pParcelPane`: rejected because this is still compiler cleanup, not class-authored source.
- Attach it to [UID:0000MF] as a file helper: rejected because file context is correct but emission is wrong.

Final inference: source context is both `ParcelIconPane` inline child construction and `ParcelPane` construction/destruction, while the binary cleanup function has no canonical source owner.

Impact:

- The best source-facing descriptive name is `ParcelPaneConstructorUnwindClearSingleton`.
- Support docs should mention both constructor routes, not only `ParcelPane`.

### H006: Lifecycle Route Completeness

Evidence checked:

- [UID:0001EG]: `g_pParcelPane` writes at `0x00545f03` and `0x00545f0a`.
- [UID:0002KB]: `g_pParcelPane` writes at `0x005462e1` and `0x005462e8`.
- [UID:0001EK]: non-deleting destructor clears `g_pParcelPane` at `0x0054648d`.
- [UID:0002KK]: animation callback reads/writes through `g_pParcelPane` at `0x00546dbc` and `0x00546dd2`.
- [UID:0002KN]: cleanup helper clears at `0x00546e80`.
- [UID:0001EP]: scalar deleting destructor clears at `0x00547054`.
- [UID:0000RY]/[UID:0002ZO]: global storage docs carry the same nine-ref family.

Rejected alternatives:

- Treat the helper as the sole clear route: rejected by destructor and scalar-destructor pages.
- Treat the helper as ordinary teardown source: rejected because normal source teardown is already represented in destructor pages.

Final inference: source lifecycle is complete without this helper as source. This helper only represents constructor-failure cleanup.

Impact:

- No first-draft C++ for [UID:0002KN].
- [UID:0000RY] and lifecycle pages are the procurement/replacement docs.

### H007: Ownership And Emitter Ranking

1. `CANONICAL_OWNER:NONE`, non-emitting cleanup funclet.
   - Evidence for: exact one-store body, EH-only routes, no ordinary callers/callees, accepted sibling/precedents.
   - Evidence against: source context is clearly parcel-family, but context does not make a compiler funclet source-authored.
   - Decision: accepted.

2. [UID:0000A6][ParcelPane].
   - Evidence for: the stored global is `g_pParcelPane`; standalone constructor/destructor/scalar destructor carry the lifecycle.
   - Evidence against: the helper is not a `thiscall` method and is referenced through EH metadata, not vtable or ordinary class call.
   - Decision: rejected as canonical owner; retain as source context.

3. [UID:0000MF][ParcelPane].
   - Evidence for: the real source module owns parcel notification classes and globals.
   - Evidence against: file-owned emission would require inventing a handwritten helper.
   - Decision: rejected as canonical owner/emitter for this range; retained as source module context.

4. [UID:0000RY][g_pParcelPane].
   - Evidence for: exact global storage owner.
   - Evidence against: data global page owns storage declaration, not executable cleanup code.
   - Decision: rejected as executable owner; retained as data anchor.

5. [UID:0000A5][ParcelIconPane].
   - Evidence for: one EH xref is associated with the outer constructor that performs inline child construction.
   - Evidence against: the global being cleared is `g_pParcelPane`, and the helper is compiler cleanup for construction failure rather than a source method.
   - Decision: rejected as owner; retained as one constructor context.

### H008: Source-Facing Helper Name And Signature

Evidence checked:

- IDA name is `sub_546E80`.
- Ghidra name is `FUN_00546e80`.
- Prewave signature is `undefined __stdcall FUN_00546e80(void)` / IDA `void()`.
- No source symbol, embedded filename, debug type, or ordinary call site recovers a real source name.

Rejected alternatives:

- `ClearParcelPaneSingleton` as original source name: rejected; it is descriptive documentation only.
- `ParcelPane::ClearParcelPaneSingleton`: rejected; no `this` parameter and no ordinary class route.
- `static void ClearParcelPaneSingleton()`: rejected as source-shaped but unproven.

Final inference: use documentation-only `ParcelPaneConstructorUnwindClearSingleton`. If a binary signature is needed for audit text, use `void __stdcall ParcelPaneConstructorUnwindClearSingleton(void)` but do not emit it as C++.

Impact:

- Rename is optional; role change is required.
- Formal reconstruction block stays blank.

### H009: First-Draft C++ / No-Code Proof

Current stale metadata would make [UID:0002KN] appear eligible for first-draft C++ because it is `86/91`, reconstructable, and emits through [UID:0000MF]. That eligibility is stale.

Rejected draft:

```cpp
static void ClearParcelPaneSingleton()
{
    g_pParcelPane = 0;
}
```

Why rejected:

- It would add a handwritten source helper that no ordinary caller uses.
- The constructors already express source-level global assignment/cleanup semantics.
- The helper's actual reachability is EH/unwind cleanup, which the compiler should regenerate from constructor source and destructor cleanup requirements.

Final inference: after reclassification to `RECONSTRUCTABLE:FALSE`, C++ readiness is not applicable. Blank C++ is correct and no longer a blocker.

Impact:

- Supervisor should not populate `RECONSTRUCTION_CPP CODE`.
- If the supervisor refuses reclassification and leaves the target `TRUE`, the report still recommends withholding C++ because the source route is not recoverable and the helper would be fake source.

### H010: Stale Target/Support Wording

Evidence checked:

- Target status says "reconstructable NexusTK project code", "file-scope helper", and parent file [UID:0000MF].
- Target reconstruction notes say the file-scope owner/emitter remains correct.
- Target live IDA bullet still uses `unk_69BA28`.
- [UID:0000A6] method table calls it "clear global helper".
- [UID:0000MF] migration notes say [UID:0002KN] remains queued for sibling review.
- [UID:0001EH] aggregate row still gives [UID:0000A6] as owner and calls it a helper.
- `by-memory/-ignored.md` has the executed [UID:0002KM] entry but not this target.
- `by-memory/-coverage-report.md` still has the old reconstructable row at 80%.

Final inference: these are stale source-quality artifacts from the pre-0002KM reclassification state.

Impact:

- Exact replacement text is provided below.
- Scores should improve to `88/92` because the former helper-name/call-site blocker is resolved by non-emitting classification.

### H011: Comparison Against 0002KM And Precedents

Similarities to accepted [UID:0002KM]:

- 11-byte one-store-plus-ret body.
- Singleton pointer clear.
- No callees.
- No ordinary caller route.
- Constructor EH/unwind xrefs.
- Same parcel notification address neighborhood.
- Source semantics already carried by constructor/destructor/global lifecycle docs.

Differences:

- [UID:0002KN] clears `g_pParcelPane`, not `g_pParcelIconPane`.
- [UID:0002KN] has two unwind xrefs, from [UID:0001EG] and [UID:0002KB], not one.
- [UID:0002KN] has no after-padding; [UID:0001EM] starts immediately at `0x00546e8b`.
- `g_pParcelPane` has a richer nine-ref lifecycle including `FlyingParcelPane` animation reads/writes.
- The target page already records a negative literal VA/RVA pointer search.

Do these differences block same reclassification? No. The two unwind routes and negative pointer search make the cleanup-only conclusion stronger. The absence of after-padding is a boundary fact, not a source-authorship signal.

## Evidence Standards Used

Evidence types used:

- Prior live IDA function lookup, disassembly, decompilation, bytes, xrefs, callees, and literal pointer searches recorded in target/support docs.
- Prewave Ghidra/IDA exported JSON for [UID:0002KN], [UID:0002KB], [UID:0001EG], and [UID:0002KM].
- by-global and exact by-memory storage docs for `g_pParcelPane`.
- Constructor/destructor/scalar-destructor by-memory lifecycle docs.
- Class/file/source-tree docs for ParcelPane source placement.
- Accepted sibling and same-shape cleanup precedent pages.
- Generated coverage state as read-only evidence.

The evidence is strong enough because independent sources agree on the exact bytes, global target, no-callee state, EH/unwind labels, data-ref family, and source-context lifecycle. The only unavailable evidence is a fresh current-session IDA query; existing written IDA evidence is already sufficient for this report-only pass.

## IDA MCP Facts

Current session:

- MCP unavailable at `127.0.0.1:13337`; no new live IDA facts were gathered.

Prior recorded facts:

- Function/range: `sub_546E80`, `0x00546e80-0x00546e8b`, size `0x0b` / 11 bytes (Verified with int_convert.py).
- Bytes: `c7 05 28 ba 69 00 00 00 00 00 c3`.
- Disassembly: `mov dword ptr [0x0069ba28], 0`; `retn`.
- Callees: none.
- Ordinary callers: none proven.
- EH/unwind xrefs:
  - `0x00605be2`, associated with `sub_545E40`, Ghidra `Unwind@00605bd9`.
  - `0x00605c38`, associated with `sub_546290`, Ghidra `Unwind@00605c2f`.
- Negative pointer evidence: no extra absolute VA `80 6E 54 00` or RVA `80 5E 14 00` pointer hits in the target page's prior live IDA refresh.
- Global refs: nine `g_pParcelPane` refs across `sub_545E40`, `sub_546290`, `sub_546440`, `sub_546D70`, `sub_546E80`, and `sub_547000`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00546e80-0x00546e8b` | [UID:0002KN] | constructor/EH cleanup funclet clearing `g_pParcelPane` | recommend `FALSE` | recommend `NONE` | recommend `88/92` | exact range; no split |
| `0x00545e40-0x0054606a` | [UID:0001EG] | `ParcelIconPane` constructor / inline child `ParcelPane` setup | `TRUE` | [UID:0000A5] | `86/90` | source semantics route |
| `0x00546290-0x00546436` | [UID:0002KB] | standalone `ParcelPane` constructor | `TRUE` | [UID:0000A6] | `86/88` | source semantics route |
| `0x00546440-0x005464ac` | [UID:0001EK] | `ParcelPane` non-deleting destructor | `TRUE` | [UID:0000A6] | `85/89` | normal clear route |
| `0x00547000-0x005470ad` | [UID:0001EP] | `ParcelPane` scalar deleting destructor | `TRUE` | [UID:0000A6] | `85/88` | ABI wrapper/source teardown evidence |
| `0x0069ba28-0x0069ba2c` | [UID:0002ZO] | exact `g_pParcelPane` storage | `TRUE` | [UID:0000MF] | `86/90` | source-declared global data |
| `g_pParcelPane` | [UID:0000RY] | source-facing global | `TRUE` | [UID:0000MF] | `85/90` | source declaration route |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00605be2` | IDA xref to `0x00546e80`, associated with `sub_545E40`; Ghidra `Unwind@00605bd9` | outer constructor's inline child construction EH cleanup route |
| `0x00605c38` | IDA xref to `0x00546e80`, associated with `sub_546290`; Ghidra `Unwind@00605c2f` | standalone `ParcelPane` constructor EH cleanup route |
| `0x00545f03`, `0x00545f0a` | writes to `g_pParcelPane` in [UID:0001EG] | source constructor publish/fallback path |
| `0x005462e1`, `0x005462e8` | writes to `g_pParcelPane` in [UID:0002KB] | source constructor publish/fallback path |
| `0x0054648d` | clear in [UID:0001EK] | normal destructor clear |
| `0x00546dbc`, `0x00546dd2` | reads/writes in [UID:0002KK] | animation completion updates active parcel pane |
| `0x00546e80` | clear in [UID:0002KN] | constructor-failure cleanup funclet |
| `0x00547054` | clear in [UID:0001EP] | scalar deleting destructor clear |

## Documentation Evidence And IDA Status

Existing docs supporting the conclusion:

- [UID:0002KN] already records exact bytes, range, no-callee state, two constructor/EH xrefs, negative literal pointer search, and nine global refs.
- [UID:0000RY] and [UID:0002ZO] identify the global target as `g_pParcelPane`.
- [UID:0001EG], [UID:0002KB], [UID:0001EK], and [UID:0001EP] carry the source-level lifecycle.
- [UID:0002KM] and cleanup precedents show the accepted classification for same-shape singleton unwind helpers.

Stale/incomplete docs:

- [UID:0002KN] metadata and prose still call the range reconstructable and file-owned.
- [UID:0000A6] method table still calls it a clear global helper.
- [UID:0000MF] still says the range is queued for sibling review.
- [UID:0001EH] aggregate row still assigns it to [UID:0000A6].
- `by-memory/-ignored.md` lacks the `0x00546e80-0x00546e8b` ignored entry.
- `by-memory/-coverage-report.md` still has a stale reconstructable row.

Generated/coverage state:

- `auto-generated/-ag-memory-coverage.md` currently routes [UID:0002KN] as emitting through [UID:0000MF] to `auto-generated/NexusTK/ui/panels/ParcelPane.cpp`.
- That generated state is a consequence of stale metadata. It should be refreshed by validator/supervisor after metadata changes, not hand-edited.

## Ranked Ownership Analysis

### 1. No Canonical Owner / Non-Emitting Compiler Cleanup

Evidence for:

- Exact one-store body.
- EH-only xref routes.
- No callees.
- No ordinary source callers or extra pointer hits.
- Constructor bodies write the global inline rather than calling this helper.
- Accepted sibling and precedent pages use the same metadata pattern.

Evidence against:

- The source context is clearly the ParcelPane module. This is contextual only and does not prove source authorship of the funclet.

Decision: accepted.

### 2. [UID:0000A6] ParcelPane

Evidence for:

- `g_pParcelPane` is the stored global.
- The standalone `ParcelPane` constructor and destructor/scalar destructor carry the main lifecycle.

Evidence against:

- No `this` parameter or vtable route.
- The function is referenced only by cleanup metadata.

Decision: reject as canonical owner; retain as source context.

### 3. [UID:0000MF] ParcelPane Source File

Evidence for:

- Correct source module for `ParcelPane`, `ParcelIconPane`, `FlyingParcelPane`, both parcel globals, and parcel alert resources.

Evidence against:

- Emitting this range through the file would create a fake handwritten helper.

Decision: reject as owner/emitter for the target range; retain as module context.

### 4. [UID:0000RY] g_pParcelPane

Evidence for:

- Correct data storage and source-facing symbol.

Evidence against:

- Data global owns the declaration, not the cleanup funclet.

Decision: reject as executable owner; retain as global anchor.

### 5. [UID:0000A5] ParcelIconPane

Evidence for:

- One EH xref is associated with its constructor.
- The outer constructor allocates/initializes the child `ParcelPane`.

Evidence against:

- The global target is the child `ParcelPane` singleton.
- There is a second EH route from the standalone `ParcelPane` constructor.

Decision: reject as owner; retain as one source-context constructor.

## Negative Evidence Summary

Checked and rejected:

- Ordinary source callers: none proven; exported caller names are `Unwind@...`.
- Callees: none.
- VA/RVA pointer-table route: prior literal searches found no extra hits.
- Source helper name: no symbol/debug/source name proof.
- By-file ownership as emitter: correct source context but wrong for compiler cleanup.
- By-global owner as executable owner: owns storage only.
- Sibling inconsistency: [UID:0002KM] has already been reclassified; this target now needs matching cleanup classification with target-specific two-xref evidence.

## Final Recommendation

Apply these changes to [UID:0002KN] and support docs.

### 1. Target Metadata

In `source-3/project-documentation/by-memory/0x00546e80-0x00546e8b.ClearParcelPaneSingleton.md`, replace the current metadata values with:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Leave the reconstruction C++ block blank.

### 2. Target Status Replacement

Replace the current `## Status` bullet block with:

```markdown
## Status

- Disposition: non-emitting compiler/EH cleanup funclet.
- Entity kind: constructor-unwind singleton clear target for `g_pParcelPane`.
- Source context: [UID:0001EG][0x00545e40-0x0054606a.ParcelIconPaneConstructor](by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md), [UID:0002KB][0x00546290-0x00546436.ParcelPaneConstructor](by-memory/0x00546290-0x00546436.ParcelPaneConstructor.md), [UID:0001EK][0x00546440-0x005464ac.ParcelPaneDestructor](by-memory/0x00546440-0x005464ac.ParcelPaneDestructor.md), [UID:0001EP][0x00547000-0x005470ad.ParcelPaneScalarDeletingDestructor](by-memory/0x00547000-0x005470ad.ParcelPaneScalarDeletingDestructor.md), [UID:0000A6][ParcelPane](by-class/ParcelPane.md), [UID:0000MF][ParcelPane](by-file/ParcelPane.md), and [UID:0000RY][g_pParcelPane](by-global/g_pParcelPane.md).
- Aggregate range: [UID:0001EH][0x00545e40-0x005470ad.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md).
- Confidence: very strong for exact binary behavior and constructor/EH cleanup role; no recoverable source helper name/signature.
```

### 3. Target Reconstruction Notes Replacement

Replace the current `## Reconstruction Notes` section with:

```markdown
## Reconstruction Notes

This is a compiler-generated constructor/EH cleanup funclet that clears [UID:0000RY][g_pParcelPane](by-global/g_pParcelPane.md). It is referenced from the outer [UID:0001EG][ParcelIconPaneConstructor](by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md) unwind path while constructing the child `ParcelPane`, and from the standalone [UID:0002KB][ParcelPaneConstructor](by-memory/0x00546290-0x00546436.ParcelPaneConstructor.md) unwind path. It should not emit as a standalone source helper.

The source-level singleton lifetime belongs to the `ParcelPane` constructor/destructor/scalar deleting destructor pages, the `ParcelIconPane` constructor's child setup path, and the `g_pParcelPane` global declaration. The current `ClearParcelPaneSingleton` name is descriptive documentation only, not a recovered source symbol.

If the page is renamed, prefer `ParcelPaneConstructorUnwindClearSingleton`.
```

### 4. Target IDA Wording Update

In the target page's `2026-06-16 A001 IDA Refresh` section, replace the bullet that currently uses `unk_69BA28` with:

```markdown
- `disasm 0x00546e80` returns exactly two instructions: an absolute store of `0` to `0x0069ba28` at `0x00546e80` and `retn` at `0x00546e8a`. Older IDA text rendered the target as `unk_69BA28`; [UID:0000RY][g_pParcelPane](by-global/g_pParcelPane.md) and [UID:0002ZO][0x0069ba28-0x0069ba2c.g_pParcelPane](by-memory/0x0069ba28-0x0069ba2c.g_pParcelPane.md) now resolve it as `dword_69BA28` / `g_pParcelPane`.
```

### 5. Aggregate Child Table Replacement

In `source-3/project-documentation/by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md`, replace:

```markdown
| `0x00546e80-0x00546e8b` | [UID:0000A6][ParcelPane](by-class/ParcelPane.md) | Clear `g_pParcelPane` helper. See [UID:0002KN][0x00546e80-0x00546e8b.ClearParcelPaneSingleton](by-memory/0x00546e80-0x00546e8b.ClearParcelPaneSingleton.md). |
```

with:

```markdown
| `0x00546e80-0x00546e8b` | none; source context [UID:0000A6][ParcelPane](by-class/ParcelPane.md) | Compiler/EH constructor-unwind cleanup funclet that clears `g_pParcelPane`; non-emitting. It is referenced from the `ParcelIconPane` constructor's inline child-pane construction unwind path and the standalone `ParcelPane` constructor unwind path. See [UID:0002KN][0x00546e80-0x00546e8b.ClearParcelPaneSingleton](by-memory/0x00546e80-0x00546e8b.ClearParcelPaneSingleton.md). |
```

### 6. ParcelPane Class Row Replacement

In `source-3/project-documentation/by-class/ParcelPane.md`, replace the method table row:

```markdown
| `0x00546e80-0x00546e8a` | clear global helper | Clears `g_pParcelPane`. |
```

with:

```markdown
| `0x00546e80-0x00546e8b` | constructor/EH singleton-clear cleanup funclet | Non-emitting compiler cleanup target that clears `g_pParcelPane` from parcel-pane construction unwind metadata; source semantics belong to the constructor/destructor/global lifecycle. |
```

### 7. ParcelPane File Migration Note Replacement

In `source-3/project-documentation/by-file/ParcelPane.md`, replace the sentence:

```markdown
Treat [UID:0002KM][0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton](by-memory/0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton.md) as non-emitting `ParcelIconPane` constructor/EH cleanup glue. The `g_pParcelIconPane` source declaration still belongs in this module, but the one-store cleanup target should be regenerated by compiler unwind handling rather than emitted as a handwritten `ParcelPane.cpp` helper. [UID:0002KN][0x00546e80-0x00546e8b.ClearParcelPaneSingleton](by-memory/0x00546e80-0x00546e8b.ClearParcelPaneSingleton.md) remains queued for the matching sibling review.
```

with:

```markdown
Treat [UID:0002KM][0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton](by-memory/0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton.md) and [UID:0002KN][0x00546e80-0x00546e8b.ClearParcelPaneSingleton](by-memory/0x00546e80-0x00546e8b.ClearParcelPaneSingleton.md) as non-emitting constructor/EH cleanup glue. The `g_pParcelIconPane` and `g_pParcelPane` source declarations still belong in this module, and their normal constructor/destructor lifetime semantics belong to the parcel lifecycle pages, but the one-store cleanup targets should be regenerated by compiler unwind handling rather than emitted as handwritten `ParcelPane.cpp` helpers.
```

### 8. by-memory Ignored Ledger Addition

In `source-3/project-documentation/by-memory/-ignored.md`, add this entry after the existing `0x00546e70-0x00546e7b` entry and before `0x00546e8b-0x00546ecd`:

```markdown
- `0x00546e80-0x00546e8b` - `ParcelPane` constructor EH singleton-clear helper.
  - Why ignored: compiler/unwind cleanup glue that clears `g_pParcelPane` during parcel-pane construction failure paths; not a normal handwritten source method.
  - Evidence: [UID:0002KN][0x00546e80-0x00546e8b.ClearParcelPaneSingleton](by-memory/0x00546e80-0x00546e8b.ClearParcelPaneSingleton.md) records the exact two-instruction `dword_69BA28 = 0; ret` body, no callees, no ordinary caller, no extra VA/RVA pointer hits, constructor/EH-style xrefs at `0x00605be2` / `Unwind@00605bd9` associated with [UID:0001EG][0x00545e40-0x0054606a.ParcelIconPaneConstructor](by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md) and `0x00605c38` / `Unwind@00605c2f` associated with [UID:0002KB][0x00546290-0x00546436.ParcelPaneConstructor](by-memory/0x00546290-0x00546436.ParcelPaneConstructor.md), and matching lifecycle refs for [UID:0000RY][g_pParcelPane](by-global/g_pParcelPane.md).
  - Replacement/procurement: no standalone source function; reconstruct the `g_pParcelPane` lifetime through [UID:0001EG][0x00545e40-0x0054606a.ParcelIconPaneConstructor](by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md), [UID:0002KB][0x00546290-0x00546436.ParcelPaneConstructor](by-memory/0x00546290-0x00546436.ParcelPaneConstructor.md), [UID:0001EK][0x00546440-0x005464ac.ParcelPaneDestructor](by-memory/0x00546440-0x005464ac.ParcelPaneDestructor.md), [UID:0001EP][0x00547000-0x005470ad.ParcelPaneScalarDeletingDestructor](by-memory/0x00547000-0x005470ad.ParcelPaneScalarDeletingDestructor.md), [UID:0000A6][ParcelPane](by-class/ParcelPane.md), and [UID:0000MF][ParcelPane](by-file/ParcelPane.md).
  - Owner docs: [UID:0000A6][ParcelPane](by-class/ParcelPane.md), [UID:0000A5][ParcelIconPane](by-class/ParcelIconPane.md), [UID:0000MF][ParcelPane](by-file/ParcelPane.md), [UID:0000RY][g_pParcelPane](by-global/g_pParcelPane.md), [UID:0002ZO][0x0069ba28-0x0069ba2c.g_pParcelPane](by-memory/0x0069ba28-0x0069ba2c.g_pParcelPane.md), and [UID:0001EH][0x00545e40-0x005470ad.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md).
```

### 9. by-memory Coverage Row Replacement

In `source-3/project-documentation/by-memory/-coverage-report.md`, replace the current [UID:0002KN] row located immediately after [UID:0002KM] and before [UID:0001EM]:

```markdown
    - [UID:0002KN][0x00546e80-0x00546e8b.ClearParcelPaneSingleton](by-memory/0x00546e80-0x00546e8b.ClearParcelPaneSingleton.md) 0x00546e80-0x00546e8b | file-scope helper | ClearParcelPaneSingleton : reconstructable : 80% : strong : Exact parcel pane singleton clear helper reconciled against IDA-backed `g_pParcelPane` xrefs, parcel aggregate placement, adjacent icon clear helper, and class/file ownership.
```

with:

```markdown
    - [UID:0002KN][0x00546e80-0x00546e8b.ClearParcelPaneSingleton](by-memory/0x00546e80-0x00546e8b.ClearParcelPaneSingleton.md) 0x00546e80-0x00546e8b | constructor-EH cleanup funclet | ParcelPaneConstructorUnwindClearSingleton : ignored : 88% : very strong : Exact `0x0b` / 11-byte constructor-unwind helper (Verified with int_convert.py) that clears `g_pParcelPane` at `dword_69BA28`; prior live IDA and prewave exports confirm one `mov` plus `ret`, no callees, no ordinary callers, no extra VA/RVA pointer hits, constructor EH/unwind xrefs at `0x00605be2` / `Unwind@00605bd9` associated with [UID:0001EG][0x00545e40-0x0054606a.ParcelIconPaneConstructor](by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md) and `0x00605c38` / `Unwind@00605c2f` associated with [UID:0002KB][0x00546290-0x00546436.ParcelPaneConstructor](by-memory/0x00546290-0x00546436.ParcelPaneConstructor.md), five-byte pre-padding after [UID:0002KM], immediate successor adjustor-thunk start at `0x00546e8b`, lifecycle counterpart clears in the non-deleting and scalar deleting destructors, and non-emitting compiler-cleanup classification.
```

If the page is renamed, update the link label/path in this row to the renamed page.

## Follow-Up Actions

Supervisor actions:

- Apply the target metadata and wording replacements.
- Add the ignored-ledger entry.
- Replace the coverage row.
- Update aggregate/class/file support wording.
- Run the appropriate validator/autogen refresh after metadata changes so generated reports stop routing [UID:0002KN] as emitting source.

A-agent actions:

- Do not populate C++ for [UID:0002KN].
- Keep reconstructing source semantics through the constructor/destructor/global pages listed above.

B006 future research actions:

- None required for this target after the supervisor applies the recommendations.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: `88/92` is justified because exact behavior, range, reachability class, global identity, lifecycle replacement, and support-doc repairs are all known. It remains below `95+` because no new live IDA query was possible in this session and final parcel source declarations still have broader helper-name caveats outside this target.
- Remaining uncertainty: no source helper name/signature is recovered. This is resolved by non-emitting classification and does not block the recommendation.

## Validator Results

- Commands run: none. This was report-only work; the only file created is this research report.
- IDA MCP check: failed to connect to `127.0.0.1:13337`; current-session limitation recorded above.
- Local conversion checks:
  - `python source-3\project-documentation\tools\int_convert.py 0x0b` -> decimal `11`.
  - `python source-3\project-documentation\tools\int_convert.py 0x124` -> decimal `292`.

## Changed Files

- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B006\research\0002KN-ClearParcelPaneSingleton-source-quality.md`
- Modified: none outside the B006 research folder.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0002KN-ClearParcelPaneSingleton-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"0002KN"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
