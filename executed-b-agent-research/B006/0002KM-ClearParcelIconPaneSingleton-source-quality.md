** TARGET-REPORT-UID:0002KM **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B006 Source-Quality Report: 0002KM ClearParcelIconPaneSingleton

Prepared: 2026-06-18

Target: [UID:0002KM][0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton](../../../../../by-memory/0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton.md)

Required disposition: report-only. No by-memory, coverage, generated, or unrelated by-* docs were edited.

## Executive Recommendation

Reclassify [UID:0002KM] from a reconstructable file-scope source helper to a non-emitting compiler/EH cleanup funclet.

Recommended target metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Do not populate first-draft C++ for this range. The exact binary action is known, but the only proven reachability is constructor/unwind cleanup metadata, not a normal source call. The source-facing lifecycle should be reconstructed through `ParcelIconPane` construction/destruction and the `g_pParcelIconPane` global, not through a standalone helper.

Recommended documentation role/name:

```text
0x00546e70-0x00546e7b ParcelIconPaneConstructorUnwindClearSingleton
```

If the supervisor does not want a filename/title rename, keep the existing page name but change its role, owner, reconstructability, and coverage text to the same non-emitting constructor/EH cleanup classification.

## Session Limits And Evidence Base

Current-session IDA MCP was unavailable: `127.0.0.1:13337` refused the MCP/SSE/config connection and `Test-NetConnection` failed. This report therefore uses:

- The target page's prior live IDA MCP refresh.
- The adjacent sibling page's prior live IDA MCP refresh.
- Prewave Ghidra/IDA JSON exports under `core/data/readonly/prewave/exported-functions/`.
- Existing by-global, by-memory, by-class, by-file, aggregate, coverage, ignored-ledger, and precedent pages.

The unavailable MCP endpoint does not weaken the boundary/body conclusion because multiple prior live IDA records and the generated exports agree on the bytes, range, global xrefs, and EH metadata. It does limit this report to a no-new-live-query confirmation pass.

## Boundary, Padding, And Bytes

Boundary is exact and should not be split or expanded:

- Start: `0x00546e70`
- End exclusive: `0x00546e7b`
- Size: `0x0b` / 11 bytes
- Raw bytes: `c7 05 d0 b4 69 00 00 00 00 00 c3`
- Disassembly:

```asm
00546e70  mov     dword_69B4D0, 0
00546e7a  retn
```

Neighborhood:

- Predecessor [UID:0002KL] ends at `0x00546e6b`.
- `0x00546e6b-0x00546e70` is five bytes of `0xcc` alignment padding.
- This target occupies exactly `0x00546e70-0x00546e7b`.
- `0x00546e7b-0x00546e80` is five bytes of `0xcc` alignment padding.
- Sibling [UID:0002KN] occupies exactly `0x00546e80-0x00546e8b`.
- Successor thunk aggregate [UID:0001EM] begins at `0x00546e8b`.

No split is warranted. The function is already an exact child. The only required range decision is classification as a non-emitting funclet instead of a reconstructable source helper.

## Reachability And EH Cleanup Metadata

Direct call evidence is absent:

- `callees(0x00546e70)` is empty.
- Normal caller enumeration is empty in the target page.
- Prewave Ghidra/IDA exports report one caller/xref, but it is unwind metadata, not a normal source call.

Indirect reachability is proven through constructor/EH cleanup metadata:

- Target page: `xrefs_to(0x00546e70)` reports a code reference at `0x00605bc1` associated with `sub_545E40`.
- Prewave Ghidra export labels the route as `Unwind@00605bb8`.
- Prewave IDA export records the xref from `0x00605bc1`, associated with `sub_545E40`, type `JUMP_NEAR`.
- [UID:0001EG][ParcelIconPaneConstructor] contains the matching constructor EH scaffold, including `ExceptionList` setup and a cleanup-state sequence around the constructor's global publish/fallback writes.

Best interpretation: this is a compiler-emitted cleanup target used by the `ParcelIconPane` constructor's unwind path to clear the singleton if construction fails after publication. It is reachable in the binary, but not as a recoverable source-authored helper.

## Global Slot Evidence: dword_69B4D0 / g_pParcelIconPane

The store target is `0x0069b4d0`, named `dword_69B4D0` by IDA and resolved source-facing as [UID:0000RX][g_pParcelIconPane](../../../../../by-global/g_pParcelIconPane.md).

Evidence checked:

- [UID:0000RX] records the global as `g_pParcelIconPane`, likely type `ParcelIconPane*`, owner/emitter [UID:0000MF][ParcelPane].
- [UID:0002W9][0x0069b4d0-0x0069b4d4.g_pParcelIconPane] verifies the exact four-byte storage child and current bytes `00 00 00 00`.
- The target page records six data refs to `0x0069b4d0`:
  - read at `0x005048d5`;
  - constructor publish/fallback writes at `0x00545e91` and `0x00545e98`;
  - non-deleting destructor clear at `0x005460c9`;
  - this helper clear at `0x00546e70`;
  - scalar deleting destructor clear at `0x00546fa0`.
- `project-level/-resolved.md` maps `dword_69B4D0` to `g_pParcelIconPane`.
- `wave2/metadata/rename_registry.json` contains a supporting `DAT_0069b4d0 -> g_pParcelIconPane` entry and a stale conflicting `DAT_0069b4d0 -> g_pDialogListPane` entry. The conflict is rejected because all source docs, memory docs, and xref routes in this parcel cluster identify the slot as the parcel icon pane singleton.

Important correction: the target page still says the initial data bytes at `0x0069b4d0` are `ff ff ff ff`. The exact memory child supersedes that with current loader/runtime memory bytes `00 00 00 00`. The stale byte claim should be replaced or qualified; it is not needed for the helper classification.

`g_pParcelIconPane` is distinct from [UID:0000RY][g_pParcelPane]. The parcel pane singleton is at `0x0069ba28`, not adjacent to `0x0069b4d0`. The next dword after `g_pParcelIconPane`, `dword_69B4D4`, is documented as `g_pSoundStatusPane`, not `g_pParcelPane`.

## Constructor, Destructor, And Scalar Deleting Destructor Routes

The source-facing singleton lifetime is already represented by normal class lifecycle pages:

- [UID:0001EG][0x00545e40-0x0054606a.ParcelIconPaneConstructor]
  - Publishes `this` to `g_pParcelIconPane` at `0x00545e91`.
  - Writes `0` fallback at `0x00545e98` for the special/null-adjusted path.
  - Sets up EH state and is the function associated with the target's unwind metadata xref.
- [UID:0001EI][0x00546070-0x005460e8.ParcelIconPaneDestructor]
  - Clears `g_pParcelIconPane` at `0x005460c9`.
- [UID:0001EO][0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor]
  - Clears `g_pParcelIconPane` at `0x00546fa0`.

The helper at `0x00546e70` is not needed as a separate source construct once those lifecycle routes are reconstructed. Its binary behavior is an unwind-only safety clear parallel to the constructor/destructor/global storage documentation.

## Sibling Helper At 0x00546e80

[UID:0002KN][0x00546e80-0x00546e8b.ClearParcelPaneSingleton] has the same form:

```asm
00546e80  mov     dword_69BA28, 0
00546e8a  retn
```

The sibling page currently remains reconstructable under [UID:0000MF], but its own evidence is stronger for EH-cleanup classification than for a source helper:

- Exact 11-byte one-store-plus-ret body.
- No callees.
- No literal VA/RVA pointer hits beyond IDA code xrefs.
- Constructor/EH-style xrefs at `0x00605be2` associated with `sub_545E40` and `0x00605c38` associated with `sub_546290`.
- Ghidra prewave labels the caller routes as `Unwind@00605bd9` and `Unwind@00605c2f`.
- Its global target [UID:0000RY][g_pParcelPane] has normal constructor/destructor/scalar-destructor lifecycle refs.

Recommendation: schedule [UID:0002KN] for the same source-quality reclassification after this target:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
role: constructor/EH singleton-clear cleanup funclet
```

This sibling should not block [UID:0002KM], but leaving the two adjacent helpers with different source classifications will keep the ParcelPane cluster internally inconsistent.

## ParcelPane Source Placement Ranking

Placement ranking after reanalysis:

1. `NONE` canonical owner, non-emitting compiler/EH cleanup funclet; source context is [UID:0001EG], [UID:0000A5], [UID:0000MF], and [UID:0000RX]. This is the best fit.
2. [UID:0001EG][ParcelIconPaneConstructor] as semantic source context. Rejected as canonical owner because the range is a separate compiler cleanup funclet, not a source function body or recoverable method.
3. [UID:0000A5][ParcelIconPane] as class context. Rejected as canonical owner for the same reason; the class owns the lifecycle semantics, not this unwind target as source code.
4. [UID:0000MF][ParcelPane] as file/module context. Correct for source module placement of the lifecycle and global, but too broad and misleading as an emitter for this function.
5. [UID:0000RX][g_pParcelIconPane] as storage owner. Correct for the data slot; rejected as executable owner because it does not own cleanup code.
6. Standalone source helper such as `ClearParcelIconPaneSingleton`. Rejected because no normal call path, no recovered source name, no source signature, and strong EH metadata route.

The source module context remains `NexusTK/ui/panels/ParcelPane.cpp`. The target range itself should not emit into that file.

## Source-Facing Helper Name And Signature

No source-facing helper name or signature is defensible.

Documentation-only binary name if retained:

```cpp
void __stdcall ParcelIconPaneConstructorUnwindClearSingleton(void);
```

This should not be entered as final reconstruction C++. It is a binary/documentation label for an EH cleanup target. A tempting source helper such as:

```cpp
static void ClearParcelIconPaneSingleton()
{
    g_pParcelIconPane = 0;
}
```

is intentionally rejected because the evidence proves only an unwind cleanup target, not a handwritten static helper or a normal source call site.

## First-Draft C++ Readiness

With the current stale metadata (`RECONSTRUCTABLE:TRUE`, owner/emitter [UID:0000MF]) the page looks eligible for a first-draft C++ attempt, but that eligibility is an artifact of the old classification.

Final recommendation:

- Leave the reconstruction block blank.
- Change `RECONSTRUCTABLE` to `FALSE`.
- Clear `EMITTER_UIDS`.
- Treat any pseudocode as explanatory evidence only.

C++ readiness after reclassification: no first-draft C++ is required or wanted. Source reconstruction readiness belongs to:

- [UID:0001EG] constructor;
- [UID:0001EI] destructor;
- [UID:0001EO] scalar deleting destructor;
- [UID:0000A5] class doc;
- [UID:0000RX] global doc;
- [UID:0000MF] source file doc.

## Heuristic / Inference Reanalysis And Validation

### H001: Is this a source-authored helper?

Evidence checked:

- Exact body is one absolute global store plus `ret`.
- No callees.
- No normal caller enumeration.
- One code xref from `0x00605bc1`, associated with `sub_545E40`.
- Prewave Ghidra calls the route `Unwind@00605bb8`.
- Prewave IDA xref type is `JUMP_NEAR`.
- Constructor page records EH scaffolding and the matching global publish/fallback writes.
- Precedents [UID:0001EZ], [UID:0001K4], and [UID:0003SY] classify same-shape singleton clear EH helpers as non-emitting cleanup glue.

Rejected alternatives:

- Handwritten `static ClearParcelIconPaneSingleton`: rejected due no ordinary caller or recovered source name.
- Destructor helper: rejected as primary classification because normal destructor clears are already at `0x005460c9` and `0x00546fa0`; this xref is constructor unwind metadata.
- File-scope helper emitted from `ParcelPane.cpp`: rejected because source module placement does not make compiler cleanup a source function.

Final inference: compiler-generated constructor/EH cleanup funclet.

Effect:

- Score can rise to `88/92` because the ambiguity is resolved.
- Owner/emitter should become `NONE` / blank.
- Source placement remains contextual only.
- C++ should be withheld.

### H002: Is the target range exact?

Evidence checked:

- Prior live IDA function lookup: `sub_546E70`, size `0x0b`.
- Disassembly and bytes match exactly.
- Predecessor, following padding, sibling, and successor boundaries are documented.
- by-memory ignored ledger already accounts for padding around this helper.

Rejected alternatives:

- Merge with preceding FlyingParcelPane draw helper: rejected by exact predecessor end and padding.
- Merge with sibling `0x00546e80`: rejected by intervening padding and distinct global target.
- Merge with successor adjustor thunks: rejected by exact sibling end and thunk start.

Final inference: keep `0x00546e70-0x00546e7b` as exact standalone binary function.

Effect:

- No split/range correction.
- Only classification and documentation changes are needed.

### H003: Is `dword_69B4D0` really `g_pParcelIconPane`?

Evidence checked:

- by-global [UID:0000RX] maps the slot to `g_pParcelIconPane`.
- exact memory child [UID:0002W9] maps `0x0069b4d0-0x0069b4d4` to `g_pParcelIconPane`.
- data xref fan-in is parcel-icon constructor/destructor/scalar-destructor plus one external read.
- class [UID:0000A5] and file [UID:0000MF] both describe the same outer parcel icon pane singleton.
- `project-level/-resolved.md` confirms the mapping.

Rejected alternatives:

- `g_pDialogListPane`: rejected as stale generated rename-registry pollution.
- `g_pParcelPane`: rejected because that global is [UID:0000RY] at `0x0069ba28`.
- Neighbor `dword_69B4D4`: rejected because docs identify it as `g_pSoundStatusPane`.

Final inference: `dword_69B4D0` should be source-facing `g_pParcelIconPane`, likely `ParcelIconPane*`.

Effect:

- Global naming/type confidence is strong enough for support docs.
- It does not imply source-helper emission.

### H004: Are the target's stale initial bytes relevant?

Evidence checked:

- Target page states `ff ff ff ff`.
- exact memory child [UID:0002W9] states current bytes `00 00 00 00`.
- nearby global docs for loader-zeroed singleton storage use current zero bytes as exact memory evidence.

Rejected alternatives:

- Use `ff ff ff ff` as singleton sentinel proof: rejected because exact memory child supersedes it.
- Let byte mismatch block classification: rejected because executable bytes and xrefs determine this helper's behavior.

Final inference: update or qualify the stale target text; current slot bytes are zero. The helper classification does not depend on initial data bytes.

Effect:

- Support-doc cleanup recommended.
- No score penalty after correction; stale text is a page-quality issue, not a range/body issue.

### H005: Should [UID:0000MF] remain canonical owner?

Evidence checked:

- Target metadata currently names [UID:0000MF].
- [UID:0000MF] is the correct source module for parcel notification panes and globals.
- Existing precedence pages changed same-pattern cleanup helpers to `CANONICAL_OWNER:NONE`.
- Generated `auto-generated/NexusTK/ui/panels/ParcelPane.cpp` is zero bytes, supporting that no source body is currently emitted.

Rejected alternatives:

- Keep [UID:0000MF] as emitter: rejected because it implies a source helper should be generated.
- Move owner to [UID:0000A5]: rejected because class context is semantic, not a source-emitting owner for the EH funclet.
- Move owner to [UID:0000RX]: rejected because data storage is not executable cleanup ownership.

Final inference: canonical owner should be `NONE`; source context should still cite [UID:0000MF], [UID:0000A5], [UID:0001EG], and [UID:0000RX].

Effect:

- Coverage row should change from `reconstructable` to `ignored`.
- Emitters should be blank.
- Aggregate child table should mark the range as compiler/EH cleanup rather than class-owned helper.

### H006: Does the sibling helper change this target's decision?

Evidence checked:

- Sibling body, size, padding, and no-callee state match.
- Sibling has constructor/EH xrefs from two constructors.
- Sibling's target global has full lifecycle refs.

Rejected alternatives:

- Treat this target as source-authored because sibling is still reconstructable: rejected because sibling metadata appears stale under the same heuristic.
- Reclassify this target only and ignore sibling: accepted only as a report-scope limitation, not as the final desired cluster state.

Final inference: sibling strengthens EH-cleanup classification and should be scheduled for equivalent reanalysis.

Effect:

- [UID:0002KM] can be reclassified now.
- Supervisor should queue or authorize [UID:0002KN] metadata/coverage cleanup.

### H007: Can final C++ be populated despite no source name?

Evidence checked:

- Exact decompilation is trivial.
- Existing target reconstruction block is blank.
- Prior target notes say final C++ is blank because source spelling and call-site form are unproven.
- Stronger current inference says there is no source-authored helper at all.

Rejected alternatives:

- Populate a descriptive `static void ClearParcelIconPaneSingleton()` implementation: rejected as creating a fake source helper.
- Populate compiler-style `__stdcall` cleanup function: rejected because generated EH funclets should not be source-emitted.

Final inference: blank C++ is correct and should stop being a blocker once `RECONSTRUCTABLE:FALSE` is applied.

Effect:

- C++ readiness: not applicable for this range.
- Source reconstruction should absorb the singleton clear through constructor/destructor/global docs.

## Exact Supervisor Actions Recommended

### 1. Target Metadata

In `source-3/project-documentation/by-memory/0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton.md`, replace the current metadata values with:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Leave the reconstruction C++ block blank.

### 2. Target Status Replacement

In the same target page, replace the current `## Status` bullet block with:

```markdown
## Status

- Disposition: non-emitting compiler/EH cleanup funclet.
- Entity kind: constructor-unwind singleton clear target.
- Source context: [UID:0001EG][0x00545e40-0x0054606a.ParcelIconPaneConstructor](by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md), [UID:0000A5][ParcelIconPane](by-class/ParcelIconPane.md), [UID:0000MF][ParcelPane](by-file/ParcelPane.md), and [UID:0000RX][g_pParcelIconPane](by-global/g_pParcelIconPane.md).
- Aggregate range: [UID:0001EH][0x00545e40-0x005470ad.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md).
- Confidence: very strong for exact binary behavior and EH-cleanup role; no recoverable source helper name/signature.
```

### 3. Target Reconstruction Notes Replacement

Replace the current `## Reconstruction Notes` section with:

```markdown
## Reconstruction Notes

This is a compiler-generated constructor/EH cleanup funclet that clears [UID:0000RX][g_pParcelIconPane](by-global/g_pParcelIconPane.md) during `ParcelIconPane` construction unwind. It should not emit as a standalone source helper.

The source-level singleton lifetime belongs to the `ParcelIconPane` constructor/destructor/scalar deleting destructor pages and the `g_pParcelIconPane` global declaration. The current `ClearParcelIconPaneSingleton` name is descriptive documentation only, not a recovered source symbol.

If the page is renamed, prefer `ParcelIconPaneConstructorUnwindClearSingleton`.
```

### 4. Target Stale Byte Text

In the target page's `2026-06-06 Live IDA Refresh` list, replace:

```markdown
- The initial data bytes at `0x0069b4d0` are `ff ff ff ff`, consistent with a singleton pointer/storage slot initialized to an invalid sentinel before runtime writes.
```

with:

```markdown
- The exact memory child [UID:0002W9][0x0069b4d0-0x0069b4d4.g_pParcelIconPane](by-memory/0x0069b4d0-0x0069b4d4.g_pParcelIconPane.md) supersedes older initial-byte notes and records current bytes `00 00 00 00`; the helper classification relies on executable bytes and xrefs, not on a sentinel initializer.
```

### 5. Aggregate Child Table Replacement

In `source-3/project-documentation/by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md`, replace the current row:

```markdown
| `0x00546e70-0x00546e7b` | [UID:0000A5][ParcelIconPane](by-class/ParcelIconPane.md) | Clear icon singleton helper. See [UID:0002KM][0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton](by-memory/0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton.md). |
```

with:

```markdown
| `0x00546e70-0x00546e7b` | none; source context [UID:0000A5][ParcelIconPane](by-class/ParcelIconPane.md) | Compiler/EH constructor-unwind cleanup funclet that clears `g_pParcelIconPane`; non-emitting. See [UID:0002KM][0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton](by-memory/0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton.md). |
```

After [UID:0002KN] is reclassified, apply the same pattern to the `0x00546e80-0x00546e8b` row.

### 6. by-memory Coverage Row Replacement

In `source-3/project-documentation/by-memory/-coverage-report.md`, replace the current [UID:0002KM] row located after [UID:0002KL] and before [UID:0002KN]:

```markdown
    - [UID:0002KM][0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton](by-memory/0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton.md) 0x00546e70-0x00546e7b | file-scope helper | ClearParcelIconPaneSingleton : reconstructable : 82% : strong : Exact two-instruction parcel icon singleton clear helper; live IDA confirms boundary, padding, sibling helper, no callees, no ordinary caller, singleton-slot xrefs, and constructor/EH code-xref caveat.
```

with:

```markdown
    - [UID:0002KM][0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton](by-memory/0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton.md) 0x00546e70-0x00546e7b | constructor-EH cleanup funclet | ParcelIconPaneConstructorUnwindClearSingleton : ignored : 88% : very strong : Exact `0x0b` constructor-unwind helper that clears `g_pParcelIconPane` at `dword_69B4D0`; prior live IDA and prewave exports confirm one `mov` plus `ret`, no callees, no ordinary callers, one constructor EH/unwind xref at `0x00605bc1` / `Unwind@00605bb8` associated with [UID:0001EG][0x00545e40-0x0054606a.ParcelIconPaneConstructor](by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md), paired padding/sibling helper boundaries, lifecycle counterpart clears in the non-deleting and scalar deleting destructors, and non-emitting compiler-cleanup classification.
```

If the page is renamed, update the link label/path in this row to the renamed page.

### 7. by-memory Ignored Ledger Addition

In `source-3/project-documentation/by-memory/-ignored.md`, add the following entries near the existing parcel notification cleanup/adjustor entries, preferably before the current `0x00546e8b-0x00546ecd` adjustor-thunk entry:

```markdown
- `0x00546e70-0x00546e7b` - `ParcelIconPane` constructor EH singleton-clear helper.
  - Why ignored: compiler/unwind cleanup glue that clears `g_pParcelIconPane` during `ParcelIconPane` constructor failure paths; not a normal handwritten source method.
  - Evidence: [UID:0002KM][0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton](by-memory/0x00546e70-0x00546e7b.ClearParcelIconPaneSingleton.md) records the exact two-instruction `dword_69B4D0 = 0; ret` body, no callees, no ordinary caller, one constructor-context unwind/EH xref at `0x00605bc1` / `Unwind@00605bb8` associated with [UID:0001EG][0x00545e40-0x0054606a.ParcelIconPaneConstructor](by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md), and matching constructor/destructor/scalar-destructor lifecycle refs for [UID:0000RX][g_pParcelIconPane](by-global/g_pParcelIconPane.md).
  - Replacement/procurement: no standalone source function; reconstruct the `ParcelIconPane` singleton lifetime through [UID:0001EG][0x00545e40-0x0054606a.ParcelIconPaneConstructor](by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md), [UID:0001EI][0x00546070-0x005460e8.ParcelIconPaneDestructor](by-memory/0x00546070-0x005460e8.ParcelIconPaneDestructor.md), [UID:0001EO][0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor](by-memory/0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor.md), [UID:0000A5][ParcelIconPane](by-class/ParcelIconPane.md), and [UID:0000MF][ParcelPane](by-file/ParcelPane.md).
  - Owner docs: [UID:0000A5][ParcelIconPane](by-class/ParcelIconPane.md), [UID:0000MF][ParcelPane](by-file/ParcelPane.md), [UID:0000RX][g_pParcelIconPane](by-global/g_pParcelIconPane.md), [UID:0001EH][0x00545e40-0x005470ad.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md).

- `0x00546e80-0x00546e8b` - `ParcelPane` constructor EH singleton-clear helper.
  - Why ignored: compiler/unwind cleanup glue that clears `g_pParcelPane` during parcel-pane construction failure paths; not a normal handwritten source method.
  - Evidence: [UID:0002KN][0x00546e80-0x00546e8b.ClearParcelPaneSingleton](by-memory/0x00546e80-0x00546e8b.ClearParcelPaneSingleton.md) records the exact two-instruction `dword_69BA28 = 0; ret` body, no callees, constructor/EH-style xrefs at `0x00605be2` associated with `sub_545E40` and `0x00605c38` associated with `sub_546290`, no extra literal pointer hits, and matching lifecycle refs for [UID:0000RY][g_pParcelPane](by-global/g_pParcelPane.md).
  - Replacement/procurement: no standalone source function; reconstruct the `ParcelPane` singleton lifetime through the parcel pane constructor/destructor/scalar deleting destructor pages, [UID:0000A6][ParcelPane](by-class/ParcelPane.md), [UID:0000RY][g_pParcelPane](by-global/g_pParcelPane.md), and [UID:0000MF][ParcelPane](by-file/ParcelPane.md).
  - Owner docs: [UID:0000A6][ParcelPane](by-class/ParcelPane.md), [UID:0000MF][ParcelPane](by-file/ParcelPane.md), [UID:0000RY][g_pParcelPane](by-global/g_pParcelPane.md), [UID:0001EH][0x00545e40-0x005470ad.ParcelNotificationPanes](by-memory/0x00545e40-0x005470ad.ParcelNotificationPanes.md).
```

The second entry should be added only when the supervisor authorizes or queues the [UID:0002KN] sibling classification, but the evidence already supports it.

## Remaining Blockers And Their Resolutions

- Compiler-generated name blocker: resolved by treating `ClearParcelIconPaneSingleton` as a documentation name only. Recommended binary doc name is `ParcelIconPaneConstructorUnwindClearSingleton`; no source helper name is recovered.
- Source-placement blocker: resolved as contextual placement in `NexusTK/ui/panels/ParcelPane.cpp`, but no emitter for this range.
- Ownership blocker: resolved to `CANONICAL_OWNER:NONE`; class/file/global docs are evidence anchors only.
- C++ blocker: resolved by `RECONSTRUCTABLE:FALSE`; blank C++ is correct and not a missing draft.
- Global/type blocker: resolved to `g_pParcelIconPane`, likely `ParcelIconPane*`; stale `g_pDialogListPane` rename lead is rejected.
- Byte/data-slot blocker: target's `ff ff ff ff` statement is stale; use exact memory child current bytes `00 00 00 00` and do not use data initializer bytes for helper classification.
- Sibling consistency blocker: [UID:0002KN] remains stale if left reconstructable; queue matching reclassification.
- Aggregate/coverage blocker: target row and aggregate child table currently imply source ownership; replace with non-emitting EH cleanup language above.

## Final Disposition

[UID:0002KM] should be treated like the already reclassified singleton EH cleanup precedents, not like a source-level helper. Its exact bytes and reachability are well documented, its data target is confidently `g_pParcelIconPane`, and its source semantics are covered by the `ParcelIconPane` constructor/destructor/global lifecycle. The correct final-C++ action is to withhold code and mark the range ignored/non-emitting.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0002KM-ClearParcelIconPaneSingleton-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"0002KM"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
