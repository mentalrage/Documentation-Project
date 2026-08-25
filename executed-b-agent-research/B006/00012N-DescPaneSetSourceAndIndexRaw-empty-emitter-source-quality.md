** TARGET-REPORT-UID:00012N **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00012N DescPaneSetSourceAndIndexRaw Empty-Emitter Source-Quality Report

Agent: Agent-B006  
Assignment: `B006-report-00012N-DescPaneSetSourceAndIndexRaw-empty-emitter-20260629`  
Target: [UID:00012N] `by-memory/0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw.md` (moved from original pre-callback path `by-memory/0x0049d780-0x0049d7b0.DescPaneSetSourceAndIndexRaw.md`)  
Report date: 2026-06-29  
Report type: accepted implementation callback update for the supervisor-accepted B-agent source-quality / empty-emitter research report

## Executive Recommendation

Repair the target range/filename and populate [UID:00012N] with first-draft source C++ instead of leaving the formal block blank. The current filename `0x0049d780-0x0049d7b0` is two bytes short under the project's half-open range convention because the `retn 8` instruction starts at `0x0049d7af` and its immediate bytes occupy `0x0049d7b0-0x0049d7b1`. The exact source body is `0x0049d780-0x0049d7b2`; the successor alignment is `0x0049d7b2-0x0049d7c0`.

Recommended target path after implementation:

```text
by-memory/0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw.md
```

Keep the existing owner/emitter route through [UID:00003Q][DescPane](by-class/DescPane.md) and [UID:0000IS][DescPane](by-file/DescPane.md). Do not clear emitters or reclassify the range.

Recommended metadata:

```text
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00003Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00003Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended formal `RECONSTRUCTION_CPP CODE` for the target:

```cpp
void DescPane::SetSourceAndIndex(DescPaneDescriptionSource *source, int selectedIndex)
{
    if (m_pDescriptionSource == source && m_selectedDescriptionIndex == selectedIndex)
        return;

    m_pDescriptionSource = source;
    m_selectedDescriptionIndex = selectedIndex;
    InvalidateRect(&m_bounds);
}
```

This is a first-draft reconstruction, not proof of original symbol spelling. `SetSourceAndIndex`, `DescPaneDescriptionSource`, `m_pDescriptionSource`, and `m_selectedDescriptionIndex` are the best current source-facing names from the surrounding class/file/layout reports and live IDA evidence. The exact original method/interface spellings remain final-audit caveats, but they no longer justify an empty emitted marker: the behavior, owner route, field meanings, and invalidation call are now source-shaped enough for staged code, matching the already accepted DescPane constructor/getter/destructor policy.

## Pre-Implementation Target State

Pre-implementation target metadata:

```text
UID:00012N
COMPLETION:85
CONFIDENCE:89
CANONICAL_OWNER:00003Q
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00003Q
RECONSTRUCTION_CPP: blank
```

Pre-implementation generated-output state, checked read-only during the original report pass:

- `auto-generated/NexusTK/ui/controls/DescPane.cpp` header: `validator-command-id: 000000000781`, `validator-refreshed-at: 2026-06-29T13:23:40-04:00`.
- The generated file currently contains an empty-emitter marker for [UID:00012N] and still shows stale generated scores `Completion:82 | Confidence:86` for this UID.
- The same generated file already emits the accepted constructor, destructor, and getter snippets for [UID:00012J], [UID:00012L], and [UID:00012M], proving the target route reaches a real source file.

Pre-implementation tracker state checked read-only during the original report pass:

- `auto-generated/-ag-research-tracker.md` row for [UID:00012N] currently reports `82/86`, `RECONSTRUCTABLE:TRUE`, no registered B-report coverage, and path `by-memory/0x0049d780-0x0049d7b0.DescPaneSetSourceAndIndexRaw.md`.
- The row is stale relative to the live target header `85/89` and should refresh through validator execution after implementation. Do not edit the tracker manually.

## Evidence Checked

### Mandatory workflow and structure

- `Agent-B006/goal.md`
- Project skill `ntk-b-agent-workflow/SKILL.md`
- `references/b-agent-research-and-implementation-workflow.md`
- `references/score-blocker-audit-standard.md`
- `by-structure.md` IDA MCP and source-quality sections

### Target and direct DescPane support docs

- `by-memory/0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw.md` (moved from `by-memory/0x0049d780-0x0049d7b0.DescPaneSetSourceAndIndexRaw.md`)
- `by-class/DescPane.md`
- `by-file/DescPane.md`
- `by-memory/0x0049d6f0-0x0049d89f.DescPane.md`
- `by-memory/0x0049d7c0-0x0049d81e.DescPaneRefreshDescription.md`
- `by-type/by-struct/DescPaneLayout.md`
- `by-type/by-vtable/DescPaneVtables.md`
- `by-memory/0x006189dc-0x00618a60.DescPaneVtableData.md`
- `by-global/g_pDescPane.md`
- `by-memory/0x0069adf8-0x0069adfc.g_pDescPane.md`
- `auto-generated/NexusTK/ui/controls/DescPane.cpp`
- `auto-generated/-ag-research-tracker.md`

### Related support docs for inherited invalidation

- `by-class/Pane.md`
- `by-file/Pane.md`
- `by-memory/0x005446b0-0x005446d4.PaneSetMode.md`

### Existing B-agent reports searched/opened

Search terms included `00012N`, `0x0049d780`, `DescPaneSetSourceAndIndexRaw`, `SetSourceAndIndex`, `m_pDescriptionSource`, `DescPaneDescriptionSource`, and `DescPane`.

Opened matching central executed reports:

- `executed-b-agent-research/B005/00012J-DescPaneConstructorRaw-source-quality.md`
- `executed-b-agent-research/B009/00012L-DescPaneDestructor-source-quality.md`
- `executed-b-agent-research/B010/00012M-DescPaneGetSingleton-source-quality.md`
- `executed-b-agent-research/B011/00012Q-DescPaneScalarDeletingDestructor-source-quality.md`

Relevant prior findings used as leads and rechecked against current target/support evidence:

- B005 established `m_pDescriptionSource`, `m_selectedDescriptionIndex`, provisional `DescPaneDescriptionSource`, `GetDescription(int, char *)`-style provider slot semantics, `Pane::InvalidateRect` at primary slot `+0x20`, and no raw pointer/rel32 route to the raw setter start.
- B005 also explicitly rejected suppressing constructor C++ merely because provider/interface spelling was provisional.
- B010 accepted a descriptive accessor name and source-facing `g_pDescPane` despite no direct caller proof.
- B009/B011 established the project policy that compiler-generated lowering should be separated from ordinary source bodies; for UID00012N the target is not compiler glue and has no deleting-wrapper/no-code proof.

## Live IDA MCP Evidence

Implementation callback evidence update, 2026-06-29:

- Supervisor recovered MCP with current IDA session `46666bf7` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `20688`; B006 used this session for the implementation evidence pass and did not use stale sessions for callback proof.
- `server_health(database=46666bf7)` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.
- Bounded `lookup_funcs`, `get_bytes`, `insn_query`, `xrefs_to`, `xref_query`, `find_bytes`, `analyze_function`, `decompile`, `search_structs`, `type_query`, and `int_convert` calls on session `46666bf7` reconfirmed the report findings and were incorporated into the by-* docs. Session-specific report-only evidence below is historical and superseded for the callback by the `46666bf7` proof.

Fresh MCP session check:

- `idb_list` on 2026-06-29 returned active session `279422f0`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `16380`.
- `server_health(database=279422f0)` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.

Function and boundary checks:

- `lookup_funcs(database=279422f0, queries=[0x0049d776,0x0049d780,0x0049d7b0,0x0049d7c0,0x0049d81e,0x0049d840,0x00544800,0x00618a20])`:
  - `0x0049d776`: `Not a function`.
  - `0x0049d780`: `Not a function`.
  - `0x0049d7b0`: `Not a function`.
  - `0x0049d7c0`: `sub_49D7C0`, size `0x5e`.
  - `0x0049d81e`: `sub_49D81E`, size `0xb`.
  - `0x0049d840`: `sub_49D840`, size `0x5f`.
  - `0x00544800`: `sub_544800`, size `0xac`.
  - `0x00618a20`: `Not a function`, matching a vtable cell rather than code.

Raw bytes:

- `get_bytes 0x0049d776 size 10`: ten `0xcc` bytes before the setter.
- `get_bytes 0x0049d780 size 48`: exact setter body bytes:

```text
55 8b ec 8b 55 08 8b 45 0c 39 91 f8 00 00 00
75 08 39 81 fc 00 00 00 74 15 89 91 f8 00 00
00 8b 11 89 81 fc 00 00 00 8d 41 44 50 ff 52
20 5d c2
```

- `get_bytes 0x0049d7b0 size 16`: starts with the remaining `retn 8` immediate bytes `08 00`, then fourteen `0xcc` bytes. This proves the current half-open filename range `0x0049d780-0x0049d7b0` is too short: a correct half-open body range must include the immediate bytes and end at `0x0049d7b2`.

Disassembly of `0x0049d780`:

- Prologue and arguments: `push ebp; mov ebp, esp; mov edx, [ebp+8]; mov eax, [ebp+0Ch]`.
- No-change tests:
  - `cmp [ecx+0F8h], edx`
  - `jnz loc_49D799`
  - `cmp [ecx+0FCh], eax`
  - `jz loc_49D7AE`
- Changed path:
  - `mov [ecx+0F8h], edx`
  - `mov edx, [ecx]`
  - `mov [ecx+0FCh], eax`
  - `lea eax, [ecx+44h]`
  - `push eax`
  - `call dword ptr [edx+20h]`
  - `pop ebp; retn 8`

Xrefs and pointer-encoding checks:

- `xrefs_to 0x0049d780`: no cross-references.
- `xref_query 0x0049d780 direction both`: only a self/internal code-flow artifact at `0x49d781`; no external incoming code/data xrefs.
- `xrefs_to 0x0049d7c0`: one data xref at `0x00618a20`, the primary `DescPane::RefreshDescription` vtable cell.
- `xrefs_to 0x0069adf8`: four refs confined to the DescPane island:
  - raw constructor store at `0x0049d731`;
  - non-deleting destructor clear at `0x0049d75a`;
  - singleton getter read at `0x0049d770`;
  - scalar deleting destructor clear at `0x0049d860`.
- `find_bytes` exact encodings for setter start:
  - VA little-endian `80 d7 49 00`: 0 hits.
  - RVA little-endian `80 d7 09 00`: 0 hits.
  - raw file-offset encoding `80 cb 09 00`: 0 hits.

Refresh consumer check:

- `analyze_function 0x0049d7c0`: `sub_49D7C0`, size `94`, callers empty, xref-to only `0x00618a20` data.
- `decompile 0x0049d7c0`: clears text state through `sub_4B9660(this, 0)`, clears byte `this + 112` (`+0x70`), invalidates using `unk_69B3FC(this, this + 68)` (`+0x44`), reads provider pointer at `this + 248` (`+0xf8`), reads selected index at `this + 252` (`+0xfc`), rejects index `-1`, and calls provider vtable offset `+36` (`+0x24`) with `(provider, selectedIndex, local2048ByteBuffer)`.

Type/name checks:

- `search_structs DescPane`: no local IDA struct.
- `type_query *DescPane*` and `*Description*`: no project UDT or provider type hits.
- Numeric conversions from MCP `int_convert`:
  - `0x30` = decimal `48`.
  - `0xf8` = decimal `248`.
  - `0xfc` = decimal `252`.
  - `0x20` = decimal `32`.
  - `0x24` = decimal `36`.
  - `0x44` = decimal `68`.
  - `0x800` = decimal `2048`.
  - `0x10` = decimal `16`.
  - `0x9d780` = decimal `644992`, bytes `80 d7 09 00`.
  - `0x9cb80` = decimal `641920`, bytes `80 cb 09 00`.

## Positive Evidence

- The exact target body is a complete `thiscall` method-shaped setter over `DescPane` state: it uses `ecx` as `this`, takes two stack arguments, compares both against class-local fields, conditionally stores both, dispatches an invalidation virtual, and returns with `retn 8`.
- The surrounding padding is clean after range repair: ten `0xcc` bytes before `0x0049d780`, no `0xcc` in the 50-byte body, and fourteen `0xcc` bytes of successor padding before modeled `RefreshDescription`.
- The fields are not generic unknowns anymore:
  - `+0xf8` is constructor-cleared, setter-updated, refresh-read as an object pointer, and used for a provider virtual call.
  - `+0xfc` is constructor-initialized to `-1`, setter-updated, refresh-checked against `-1`, and passed as the provider's selected index.
- Support docs already name the fields `m_pDescriptionSource` and `m_selectedDescriptionIndex` and reject text-buffer, flags, count, pane-owner, cached-length, and feature-dialog interpretations.
- `Pane` support resolves the inherited vtable slot: `by-memory/0x005446b0-0x005446d4.PaneSetMode.md` uses the same primary slot `+0x20` / `0x00544800` with `this+0x44` and emits `InvalidateRect(&m_bounds)`.
- `DescPaneRefreshDescription` consumes exactly the state written here, and the provider call shape supports a provider/source interface named provisionally as `DescPaneDescriptionSource`.
- The target has a valid generated-output route through [UID:00003Q] to `auto-generated/NexusTK/ui/controls/DescPane.cpp`.
- The generated file currently contains an empty marker for this UID, proving the issue is not missing routing but missing formal source content.

## Negative Evidence

- IDA still does not model `0x0049d780` as a function.
- No direct caller, vtable entry, VA pointer, RVA pointer, or raw-offset pointer encoding to the raw setter start is currently proven.
- No local IDA `DescPane` struct or `DescPaneDescriptionSource` UDT exists.
- No caller evidence proves the original method name, argument names, or provider interface spelling.
- The target does not call `RefreshDescription` directly; it invalidates bounds via the inherited `Pane::InvalidateRect` slot. A method name centered on immediate refresh behavior would be too strong.
- No evidence ties the helper to `Pane`, `DialogPane`, a feature-dialog module, or a generic UI-core owner.

These negative facts cap final-audit confidence and must be preserved. They do not prove no-code: the body is source-authored project code, not compiler glue, padding, data, or a duplicate of another source body.

## Heuristic / Inference Reanalysis And Validation

### Source identity and method name

Best current source-facing name: `DescPane::SetSourceAndIndex`.

Evidence for:

- The two arguments are exactly a source/provider pointer and an index.
- The helper updates both as a pair and invalidates only when at least one changed.
- Existing target/file/class naming already uses `SetSourceAndIndexRaw`; dropping `Raw` yields a source-facing name that preserves both side effects without overclaiming original symbol recovery.

Rejected names:

- `SetDescriptionSource`: hides the selected-index argument and would make the second stored field look incidental.
- `SetSelectedIndex`: hides the provider/source pointer and would mislead about the first argument.
- `RefreshDescription`: wrong immediate behavior; this helper does not clear text state, call the provider, or run the refresh override.
- `InvalidateDescription`: overemphasizes the invalidation side effect and misses the state update.
- `SetProvider`: too generic and loses the selected-index contract.

Decision: use `SetSourceAndIndex` as a descriptive first-draft method name. Record that original spelling is inferred.

### Provider/interface type

Best current source-facing type name: `DescPaneDescriptionSource`.

Evidence for:

- `DescPane` is a description display pane.
- `RefreshDescription` treats `+0xf8` as an object pointer and calls provider slot `+0x24` with selected index and a local description buffer.
- B005 and current support docs already use `DescPaneDescriptionSource` as the provisional interface direction.

Rejected alternatives:

- `void *`: too weak for source output because the consumer virtual-call shape is known.
- Feature-dialog provider types: no feature-dialog xrefs or source ownership evidence.
- `Pane *` or UI owner pointer: refresh calls provider slot `+0x24` with text-buffer semantics, not pane bounds/layer methods.
- Full interface declaration in this target: unsafe because slots before `+0x24` are not named from current evidence.

Decision: first-draft method signature can use `DescPaneDescriptionSource *source` with the report noting the type is provisional. Final header/interface layout remains a broader class task.

### Field names

Best current field names:

- `+0xf8`: `m_pDescriptionSource`
- `+0xfc`: `m_selectedDescriptionIndex`

Evidence for:

- Constructor clears `+0xf8` and initializes `+0xfc` to `-1`.
- Setter compares/stores both fields.
- Refresh reads them and calls the provider only when both are valid.
- Existing class/file/layout/global pages and B005 report already incorporated these names.

Decision: use the existing field names in target C++. The exact original spellings remain inferred, but using them is more source-quality than raw offsets or anonymous members.

### Invalidation call

Best current call name: `InvalidateRect(&m_bounds)`.

Evidence for:

- Setter dispatches primary vtable slot `+0x20` with `this+0x44`.
- `Pane::SetMode` uses the same slot and emits `InvalidateRect(&m_bounds)`.
- Pane class/file docs resolve `0x00544800` as `Pane::InvalidateRect`; `+0x44` is the inherited bounds/local rectangle.

Rejected alternatives:

- `RefreshDescription()`: not what the code calls.
- `UpdateRenderRegion()`: primary slot `+0x0c` is the render-region support target, not the slot used here.
- Raw `(*(vtable+0x20))(this+0x44)`: decompiler-shaped and lower quality than the resolved Pane call.

Decision: use `InvalidateRect(&m_bounds)`.

### C++ readiness

The prior blank-C++ rationale named unresolved provider/interface names and setter names as blockers. That is no longer a sufficient report conclusion after current research:

- The field names, provider direction, and invalidation call are already validated in support docs and live MCP.
- B005/B010 precedent shows descriptive names can be used for self-contained DescPane method bodies when exact original spelling is unrecovered.
- Leaving this target blank produces generated-output pollution: `DescPane.cpp` already emits an empty marker even though the method body is reconstructable source code.

Decision: formal first-draft C++ is ready. Keep final-audit caveats in prose and score caps rather than suppressing code.

## Ranked Ownership Analysis

| Rank | Candidate | Decision | Evidence |
| ---: | --- | --- | --- |
| 1 | [UID:00003Q] `DescPane` class | Keep as direct owner/emitter | Uses `DescPane` tail fields `+0xf8/+0xfc`, sits inside the contiguous DescPane method island, and shares state with constructor/refresh/layout docs. |
| 2 | [UID:0000IS] `DescPane` by-file | Keep as source-file route only | Existing route emits to `NexusTK/ui/controls/DescPane.cpp`; by-structure prefers the class as direct owner for class methods. |
| 3 | [UID:0000A2] `Pane` | Reject as direct owner | Pane supplies inherited bounds and `InvalidateRect`; the state being set is DescPane-local. |
| 4 | `DialogPane` / feature-dialog modules | Reject | No caller/xref fanout or field behavior ties this helper to a dialog feature; `DialogPane` RTTI starts after the DescPane vtable range. |
| 5 | `CANONICAL_OWNER:NONE` / non-emitting | Reject | The body is source-authored class code with a valid class/file emitter route. Missing direct xrefs are a confidence cap, not no-owner proof. |

## Range, Split, And Reclassification Decision

Range repair is recommended. No semantic split is needed, but the by-memory filename/header range should change from `0x0049d780-0x0049d7b0` to `0x0049d780-0x0049d7b2` so the half-open range contains the complete `retn 8` instruction.

| Range | Disposition |
| --- | --- |
| `0x0049d776-0x0049d780` | Ten-byte pre-padding after singleton getter. |
| `0x0049d780-0x0049d7b2` | Exact 50-byte setter body including all bytes of `retn 8`. |
| `0x0049d7b2-0x0049d7c0` | Fourteen-byte `0xcc` alignment before `RefreshDescription`. |
| `0x0049d7c0-0x0049d81e` | Next modeled `DescPane::RefreshDescription`. |

The target is not compiler-generated glue. It is not padding, data, an adjustor thunk, a deleting destructor wrapper, or a duplicate body already emitted elsewhere.

## Allowed Disposition Comparison

| Disposition | Decision | Reason |
| --- | --- | --- |
| Full/partial first-draft body | Select | The complete body is known, source-owned, side-effect small, and all formerly generic blockers now have best current names: `SetSourceAndIndex`, `DescPaneDescriptionSource`, `m_pDescriptionSource`, `m_selectedDescriptionIndex`, and `InvalidateRect(&m_bounds)`. |
| Comment-only formal marker | Reject | Unlike accepted rare no-code cases, this target is not too large, not an unknown dispatcher, not compiler glue, and not dependent on an unresolved function body. A comment marker would keep generated `DescPane.cpp` non-source even though the executable behavior is directly recoverable. |
| Clear `EMITTER_UIDS` / non-emitting metadata | Reject | Owner/emitter route is already correct and generated output reaches `DescPane.cpp`; clearing emitters would hide source-authored DescPane code and reduce reconstruction fidelity. |
| Keep blank formal C++ with nonblank emitter | Reject | This is the current bad state: generated output contains an empty marker for source-owned code. The remaining uncertainties are name exactness and static reachability, both score caps rather than no-code proof. |
| Split/range repair | Select narrowly | The source body is not mixed and should not be split, but the filename/range end must move from `0x0049d7b0` to `0x0049d7b2` to include the complete `retn 8` instruction. |

## Score And Metadata Recommendation

Recommended target score: `COMPLETION:90`, `CONFIDENCE:91`.

Rationale:

- Completion rises from `85` to `90` because the report resolves the named blank-C++ blockers, confirms the live MCP boundary/xref/byte/generator state, selects source-facing method/type/field/call names, supplies formal first-draft C++, rejects non-code dispositions, and lists exact support-doc incorporation requirements.
- Confidence rises from `89` to `91` because live MCP reconfirms the behavior and no-pointer/no-xref state, Pane support resolves the invalidation slot, and prior executed reports validate the naming policy for staged DescPane methods.
- Do not score `95+`: the raw start still has no proven direct caller, IDA still does not model it as a function, no original method/interface spelling is recovered, no local provider UDT exists, and `RefreshDescription` itself still needs a future full provider-interface/header pass.

Metadata:

- Keep `CANONICAL_OWNER:00003Q`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:00003Q`.
- Leave `EMITTER_POSITION_OPTIONAL:` unchanged.

## Recommended Target And Support Doc Changes

### Target: `by-memory/0x0049d780-0x0049d7b0.DescPaneSetSourceAndIndexRaw.md`

Implement all of the following if the supervisor accepts this report:

- Rename/move the target to `by-memory/0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw.md` under normal validator/lease rules so UID00012N's half-open range includes the full body.
- Change completion/confidence to `90/91`.
- Keep owner/emitter/reconstructable metadata unchanged.
- Insert the formal C++ block from this report.
- Update Status to say first-draft C++ is ready; exact original method/interface spellings and missing direct xrefs remain final-audit caveats.
- Update Behavior to use `m_pDescriptionSource`, `m_selectedDescriptionIndex`, `DescPaneDescriptionSource *source`, `selectedIndex`, and `InvalidateRect(&m_bounds)`.
- Preserve callback live MCP evidence from session `46666bf7`, including health OK, lookup results, exact byte ranges, no external xrefs to `0x0049d780`, no VA/RVA/raw-offset pointer encodings, refresh consumer decompile, and no local UDT/type hits. The earlier report-only session `279422f0` is historical only.
- Add a source-quality decision section that rejects `SetDescriptionSource`, `SetSelectedIndex`, `RefreshDescription`, clearing emitters, comment-only markers, and blank emitter output.
- Add a Changes entry for the accepted B006 report.

### Support: `by-class/DescPane.md`

- Update the method table row for [UID:00012N] to say it emits first-draft `DescPane::SetSourceAndIndex(DescPaneDescriptionSource *source, int selectedIndex)` and calls `InvalidateRect(&m_bounds)` when either stored value changes.
- Update the source-quality table so setter/helper name is no longer a blank-C++ blocker; instead, `SetSourceAndIndex` is the current descriptive reconstruction name and exact original spelling remains a final-audit caveat.
- Preserve that `DescPaneDescriptionSource` remains provisional and full interface declaration waits for more consumer evidence.

### Support: `by-file/DescPane.md`

- Add [UID:00012N] to the C++ staging section as a child-owned first-draft method body.
- Replace wording that says the raw setter helper source name blocks emission with wording that first-draft setter C++ is ready while final header/interface polish remains pending.
- Preserve source placement under `NexusTK/ui/controls/DescPane.cpp`.
- Preserve rejected owner alternatives from B005.

### Support: `by-memory/0x0049d6f0-0x0049d89f.DescPane.md`

- Update the covered row and reconstruction notes for [UID:00012N] to say the setter now owns/should emit first-draft `SetSourceAndIndex` C++.
- Keep aggregate formal C++ blank because child pages own method bodies.
- Preserve the raw-start/no-route caveat as a confidence cap.

### Support: `by-type/by-struct/DescPaneLayout.md`

- Update the layout/provider notes to say `m_pDescriptionSource` and `m_selectedDescriptionIndex` are sufficient for UID00012N first-draft setter C++.
- Preserve that `DescPaneDescriptionSource` remains provisional and no local IDA UDT exists.

### Support: `by-type/by-vtable/DescPaneVtables.md`

- Already mostly present: primary slot `+0x20` is inherited `Pane::InvalidateRect`, and primary slot `+0x44` is `DescPane::RefreshDescription`.
- Add or verify a sentence that UID00012N uses inherited primary slot `+0x20` for invalidation and should not be described as directly calling `RefreshDescription`.

### Support: `by-memory/0x0049d7c0-0x0049d81e.DescPaneRefreshDescription.md`

- Add or verify a producer/consumer note: UID00012N stores the provider/index pair that `RefreshDescription` later consumes.
- Preserve that `RefreshDescription` formal C++ remains blank until the provider buffer contract and interface declaration are final-source quality.

### Already-present support, no required edits unless stale wording is encountered during implementation

- `by-class/Pane.md`, `by-file/Pane.md`, and `by-memory/0x005446b0-0x005446d4.PaneSetMode.md` already prove `Pane::InvalidateRect` and the source style `InvalidateRect(&m_bounds)`.
- `by-global/g_pDescPane.md` and `by-memory/0x0069adf8-0x0069adfc.g_pDescPane.md` already prove singleton confinement and are not direct destinations for this setter's facts.
- `by-memory/0x006189dc-0x00618a60.DescPaneVtableData.md` already proves the vtable route and should not emit dword tables manually.

## Claim And Incorporation Ledger

| Claim ID | Claim | Destination / action | Verification state |
| --- | --- | --- | --- |
| C1 | UID00012N's current filename range is two bytes short; exact body is `0x0049d780-0x0049d7b2`, with ten-byte pre-padding and fourteen-byte successor alignment before `0x0049d7c0`. | Target moved to `by-memory/0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw.md`; target and aggregate docs record `get_bytes` proof and padding rows. | applied |
| C2 | Current callback MCP session `46666bf7` is healthy and confirms `0x0049d780` is not a function while `0x0049d7c0` is `sub_49D7C0` size `0x5e`. | Target evidence section and changes entry use session `46666bf7`; validator target command `000000000897` accepted the moved target. | applied |
| C3 | Setter compares `[ebp+8]` against `this+0xf8` and `[ebp+0xc]` against `this+0xfc`; unchanged pair returns without invalidation. | Target behavior/evidence and class/file/aggregate summaries document the compare and early return. | applied |
| C4 | Changed path stores both fields and dispatches primary vtable slot `+0x20` with `this+0x44`. | Target behavior/evidence, vtable support, and refresh support document the store and inherited invalidation dispatch. | applied |
| C5 | `+0xf8` best field name is `m_pDescriptionSource`; `+0xfc` best field name is `m_selectedDescriptionIndex`. | Target, class, file, layout, aggregate, and generated C++ use these names. | applied |
| C6 | Best provisional provider/interface type is `DescPaneDescriptionSource`; full interface declaration remains blocked by unnamed earlier slots/no UDT. | Target, class, file, and layout docs use provisional `DescPaneDescriptionSource` for setter C++ and keep full interface declaration caveats. | applied |
| C7 | Best source-facing method name is `SetSourceAndIndex`; original spelling is inferred/descriptive. | Target formal C++ and class/file/aggregate docs use `SetSourceAndIndex` while preserving original-spelling caveats. | applied |
| C8 | Invalidation call should be source-written as `InvalidateRect(&m_bounds)`, based on Pane slot `+0x20` / `0x00544800` and PaneSetMode precedent. | Target formal C++, class/file/layout/vtable docs apply `InvalidateRect(&m_bounds)`; Pane support was confirmed already present. | applied |
| C9 | No external xrefs, VA/RVA/raw-offset pointer encodings, or direct caller route to `0x0049d780` are proven. | Target and aggregate docs preserve the no-xref/no-pointer/no-direct-route evidence as a confidence cap. | applied |
| C10 | Missing direct route and exact original names do not justify blank C++ because the body is source-authored, self-contained DescPane code. | Target source-quality decision, class/file/aggregate notes, and generated output prove the formal block is populated. | applied |
| C11 | Owner/emitter stay [UID:00003Q] `DescPane`, routing to [UID:0000IS] `DescPane.cpp`; the only structural change is the filename/range-end repair to `0x0049d7b2`. | Target metadata remains `CANONICAL_OWNER:00003Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00003Q`; support docs preserve the route. | applied |
| C12 | Generated `auto-generated/NexusTK/ui/controls/DescPane.cpp` currently has an empty marker for UID00012N and should emit the setter after accepted implementation validation. | Read-only generated check shows header `validator-command-id: 000000000905`, newer than target validator `000000000897`, and UID00012N emits `DescPane::SetSourceAndIndex`; no UID00012N empty marker remains. | applied |
| C13 | Non-selected dispositions are rejected: comment-only marker, clearing emitter, keeping blank emitter, semantic split, and no-owner/non-emitting. The selected structural disposition is a narrow range-end repair only. | Target source-quality decision records rejected alternatives and selected range-end repair only. | applied |
| C14 | Recommended score is `90/91`, below `95+` because no direct caller, IDA no-function state, provisional original names, and no provider UDT remain. | Target metadata and score rationale are `90/91`; caveats remain documented. | applied |

## Validator And Generated Output Status

The original report-only pass created this file without validators. The accepted implementation callback ran these scoped validators from `source-3/project-documentation`; all exited `0` with `ok: 1`.

| File | command id | timestamp | exit | ok | Result |
| --- | --- | --- | --- | --- | --- |
| `by-memory\0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw.md` | `000000000897` | `2026-06-29T16:08:29-04:00` | `0` | `1` | Accepted UID00012N path update, `COMPLETION:90`, `CONFIDENCE:91`, and nonblank generated block registration. |
| `by-class\DescPane.md` | `000000000898` | `2026-06-29T16:08:32-04:00` | `0` | `1` | Accepted class support update. |
| `by-file\DescPane.md` | `000000000899` | `2026-06-29T16:08:33-04:00` | `0` | `1` | Accepted file support update and reference-index addition for UID00012N. |
| `by-memory\0x0049d6f0-0x0049d89f.DescPane.md` | `000000000900` | `2026-06-29T16:08:43-04:00` | `0` | `1` | Accepted aggregate support update. |
| `by-type\by-struct\DescPaneLayout.md` | `000000000901` | `2026-06-29T16:08:45-04:00` | `0` | `1` | Accepted layout support update. |
| `by-type\by-vtable\DescPaneVtables.md` | `000000000902` | `2026-06-29T16:08:51-04:00` | `0` | `1` | Accepted vtable support update. |
| `by-memory\0x0049d7c0-0x0049d81e.DescPaneRefreshDescription.md` | `000000000903` | `2026-06-29T16:08:53-04:00` | `0` | `1` | Accepted refresh producer/consumer support update. |
| `by-memory\0x0049d770-0x0049d776.DescPaneGetSingleton.md` | `000000000904` | `2026-06-29T16:09:00-04:00` | `0` | `1` | Accepted direct stale-link repair after the range-end move. |
| `by-memory\0x0049d6f0-0x0049d73c.DescPaneConstructorRaw.md` | `000000000905` | `2026-06-29T16:09:09-04:00` | `0` | `1` | Accepted direct constructor support wording/link repair after the setter emission decision. |

Generated output was inspected read-only after validation:

- `auto-generated/NexusTK/ui/controls/DescPane.cpp` header shows `validator-command-id: 000000000905`, `validator-refreshed-at: 2026-06-29T16:09:09-04:00`, and `validator-refresh-source: deferred-generated-refresh`. This is newer than the UID00012N target edit command `000000000897`.
- UID00012N now emits `void DescPane::SetSourceAndIndex(DescPaneDescriptionSource *source, int selectedIndex)` with the accepted early-return, stores, and `InvalidateRect(&m_bounds)` body. UID00012N is no longer an empty-emitter marker.
- `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-coverage-report-by-memory.md` were checked read-only and now carry the `0x0049d780-0x0049d7b2` path, `90/91`, and `emits_code:true` for UID00012N.

No generated files, project-level generated reports, manual `-coverage-report.md` files, validator/tool state, IDA DB files, executed archives, or supervisor ledgers were hand-edited by B006. Validator-owned generated/tool-state updates occurred only through the validator commands above.

## Implementation Tracking Checklist

Accepted implementation callback status:

- [x] Rename/move target `by-memory/0x0049d780-0x0049d7b0.DescPaneSetSourceAndIndexRaw.md` to `by-memory/0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw.md` so UID00012N includes the complete `retn 8` instruction. Proof: validator command `000000000897` accepted the path update.
- [x] Update target `by-memory/0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw.md`: metadata `85/89 -> 90/91`; owner/emitter/reconstructable unchanged; insert formal first-draft C++; add live MCP boundary/xref/byte/type/generated-output evidence; add source-quality disposition analysis and rejected alternatives. Proof: target doc and command `000000000897`.
- [x] Update support `by-class/DescPane.md`: method table/source-quality table reflect UID00012N first-draft `SetSourceAndIndex` C++ readiness, provisional provider type, and final-audit caveats. Proof: command `000000000898`.
- [x] Update support `by-file/DescPane.md`: C++ staging and reconstruction caveats list UID00012N as child-owned first-draft method emission; preserve `NexusTK/ui/controls/DescPane.cpp` route. Proof: command `000000000899`.
- [x] Update support `by-memory/0x0049d6f0-0x0049d89f.DescPane.md`: child row/reconstruction notes say UID00012N emits first-draft setter body; aggregate C++ remains blank. Proof: command `000000000900`.
- [x] Update support `by-type/by-struct/DescPaneLayout.md`: field/provider notes state UID00012N can use `m_pDescriptionSource`, `m_selectedDescriptionIndex`, and provisional `DescPaneDescriptionSource` in first-draft C++. Proof: command `000000000901`.
- [x] Update support `by-type/by-vtable/DescPaneVtables.md`: preserve/verify slot distinction that UID00012N uses inherited primary slot `+0x20` / `Pane::InvalidateRect`, not the `RefreshDescription` slot. Proof: command `000000000902`.
- [x] Update support `by-memory/0x0049d7c0-0x0049d81e.DescPaneRefreshDescription.md`: add/verify producer-consumer note linking UID00012N setter to refresh's provider/index reads; keep refresh C++ blank unless separately accepted. Proof: command `000000000903`.
- [x] Repair directly affected inbound/support links in `by-memory/0x0049d770-0x0049d776.DescPaneGetSingleton.md` and `by-memory/0x0049d6f0-0x0049d73c.DescPaneConstructorRaw.md`. Proof: commands `000000000904` and `000000000905`.
- [x] Confirm already-present support without unnecessary edits: `by-class/Pane.md`, `by-file/Pane.md`, `by-memory/0x005446b0-0x005446d4.PaneSetMode.md`, `by-global/g_pDescPane.md`, `by-memory/0x0069adf8-0x0069adfc.g_pDescPane.md`, and `by-memory/0x006189dc-0x00618a60.DescPaneVtableData.md`. Proof: no edits were needed; target/support docs cite the existing Pane/global/vtable support.
- [x] Update this report's Claim And Incorporation Ledger after callback: each accepted claim C1-C14 marked `applied`, `already-present`, or `excluded-with-reason` with exact file/path proof. Proof: C1-C14 are marked `applied` in the ledger above.
- [x] Run validator: `python .\tools\validator.py --mode file --file by-memory\0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw.md --apply --queue-timeout 240`. Proof: command `000000000897`, timestamp `2026-06-29T16:08:29-04:00`, exit `0`, ok `1`.
- [x] Run validator: `python .\tools\validator.py --mode file --file by-class\DescPane.md --apply --queue-timeout 240`. Proof: command `000000000898`, timestamp `2026-06-29T16:08:32-04:00`, exit `0`, ok `1`.
- [x] Run validator: `python .\tools\validator.py --mode file --file by-file\DescPane.md --apply --queue-timeout 240`. Proof: command `000000000899`, timestamp `2026-06-29T16:08:33-04:00`, exit `0`, ok `1`.
- [x] Run validator: `python .\tools\validator.py --mode file --file by-memory\0x0049d6f0-0x0049d89f.DescPane.md --apply --queue-timeout 240`. Proof: command `000000000900`, timestamp `2026-06-29T16:08:43-04:00`, exit `0`, ok `1`.
- [x] Run validator: `python .\tools\validator.py --mode file --file by-type\by-struct\DescPaneLayout.md --apply --queue-timeout 240`. Proof: command `000000000901`, timestamp `2026-06-29T16:08:45-04:00`, exit `0`, ok `1`.
- [x] Run validator: `python .\tools\validator.py --mode file --file by-type\by-vtable\DescPaneVtables.md --apply --queue-timeout 240`. Proof: command `000000000902`, timestamp `2026-06-29T16:08:51-04:00`, exit `0`, ok `1`.
- [x] Run validator: `python .\tools\validator.py --mode file --file by-memory\0x0049d7c0-0x0049d81e.DescPaneRefreshDescription.md --apply --queue-timeout 240`. Proof: command `000000000903`, timestamp `2026-06-29T16:08:53-04:00`, exit `0`, ok `1`.
- [x] Inspect generated output read-only: `auto-generated/NexusTK/ui/controls/DescPane.cpp`; confirm UID00012N emits `DescPane::SetSourceAndIndex` and header refresh metadata is equal/newer than the validator command that applied the target edit. Proof: header command `000000000905` at `2026-06-29T16:09:09-04:00`, newer than target command `000000000897`.
- [x] Confirm no generated files, project-level generated reports, manual `-coverage-report.md` files, validator/tool state, IDA DB, executed archives, or supervisor ledgers were hand-edited by B006. Proof: all generated/tool-state changes came from validator commands; generated C++ and tracker/coverage were inspected read-only.
- [x] During implementation callback only: lease exactly the target/support docs being edited, run the validators within the edit batch, then release leases immediately and report lease release/expiry proof. Proof: by-* support leases were released after validation; final lease state reported no active leases before this report-bookkeeping lease.

## Files Changed By Callback

```text
by-memory/0x0049d780-0x0049d7b0.DescPaneSetSourceAndIndexRaw.md -> by-memory/0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw.md
by-class/DescPane.md
by-file/DescPane.md
by-memory/0x0049d6f0-0x0049d89f.DescPane.md
by-type/by-struct/DescPaneLayout.md
by-type/by-vtable/DescPaneVtables.md
by-memory/0x0049d7c0-0x0049d81e.DescPaneRefreshDescription.md
by-memory/0x0049d770-0x0049d776.DescPaneGetSingleton.md
by-memory/0x0049d6f0-0x0049d73c.DescPaneConstructorRaw.md
tools/leaser/Agents/Agent-B006/research/00012N-DescPaneSetSourceAndIndexRaw-empty-emitter-source-quality.md
```

Validator-owned/generated refreshes updated generated output, reports, indices, projected stats, and tool state as normal validator side effects. B006 did not hand-edit generated files, project-level generated reports, manual `-coverage-report.md` files, validator/tool state, IDA DB files, executed archives, or supervisor ledgers.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/00012N-DescPaneSetSourceAndIndexRaw-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/00012N-DescPaneSetSourceAndIndexRaw-empty-emitter-source-quality.md","timestamp":"2026-06-29T16:18:41","uid":"00012N"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
