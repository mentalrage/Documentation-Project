** TARGET-REPORT-UID:00015G **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00015G FpsPaneOnPaint Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00015G] as source-bearing `FpsPane::OnPaint`, not no-code/compiler glue.
- Final disposition: source-authored virtual paint method owned by [UID:00005F] `FpsPane`, emitted through [UID:00005F] to [UID:0000JK] `NexusTK/ui/diagnostics/FpsPane.cpp`.
- Required action: update the target page metadata and prose, replace stale 95/95 no-code wording with the active C++ gate, resolve generated `sub_*` helper labels to documented support names, and populate a first-draft C++ body if the supervisor accepts this report.
- Confidence: strong for body, boundary, owner/emitter route, field usage, string formatting, and draw sequence; medium for final original spellings of the GrafPort text-color helper and pointer-backed string facade.

Recommended target metadata:

| Field | Recommendation |
| --- | --- |
| `COMPLETION` | `88` |
| `CONFIDENCE` | `91` |
| `CANONICAL_OWNER` | keep `00005F` |
| `RECONSTRUCTABLE` | keep `TRUE` |
| `EMITTER_UIDS` | keep `00005F` |
| Formal C++ | populate first draft after supervisor implementation callback |

## Target

- Target UID: [UID:00015G]
- Target path: `source-3/project-documentation/by-memory/0x004b67b0-0x004b68ab.FpsPaneOnPaint.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B007/research/00015G-FpsPaneOnPaint-source-quality.md`
- Current target score/state: `84/90`, `CANONICAL_OWNER:00005F`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00005F`, blank C++.
- Source queue/report row: `by-memory/-coverage-report.md` currently says `84% : strong`, live IDA confirms vtable-only paint slot, final field/declaration caveat, and final C++ blank.
- Generated state: `auto-generated/-ag-memory-coverage.md` says this page emits through `00005F` to `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp`, but the generated file currently contains only an empty emitter marker for UID `00015G`.

## Supervisor Active Recheck

- User assigned a B-agent source-quality / heuristic research pass for [UID:00015G] `FpsPaneOnPaint`.
- Report-only pass: no target/support by-* docs were edited, no generated/project-level files were edited, and `by-memory/-coverage-report.md` was not edited.
- Split repair is not required. The existing half-open range `0x004b67b0-0x004b68ab` is exact and bounded by `0xcc` padding before `FpsPane::UpdateStatistics`.
- Prior B007 reports were preserved. This report file did not already exist before creation.

## Evidence Standards Used

- Direct binary-derived evidence: existing live IDA notes in the target/support docs, local IDA export `.lst`, `.c`, and `.map` files under `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS`.
- Documentation evidence: target page, FpsPane class/file/layout/vtable docs, FpsPane diagnostics aggregate, string-data page, GrafPort helper docs, StringBase helper docs, and generated coverage/source outputs.
- Inference guidance: `by-structure.md` active C++ gate requires `RECONSTRUCTABLE:TRUE`, valid nonblank emitters, and `(COMPLETION + CONFIDENCE) / 2 > 85`; old `95/95` wording is stale. `inference_research.md` supports source-owner inference from vtables, constructors/destructors, xrefs, caller/callee families, and negative evidence rather than requiring impossible original source proof.
- IDA MCP status: fresh MCP connection was attempted at `http://127.0.0.1:13337/mcp` and failed with `Unable to connect to the remote server`. This report therefore relies on existing live-IDA documentation and local IDA exports.

## IDA / Export Facts

- Existing live IDA target notes confirm `sub_4B67B0` size `0xfb`, range `0x004b67b0-0x004b68ab`; `0x004b68ab-0x004b68b0` is five bytes of `0xcc` padding before [UID:00015H] `FpsPane::UpdateStatistics`.
- `xrefs_to 0x004b67b0` reports only the FpsPane primary vtable data ref at `0x0061a664`; `callers` is empty, which is expected for a virtual paint method.
- Local IDA C export gives the exact prototype shape: `void __thiscall sub_4B67B0(int this)`.
- Local IDA decompilation confirms:
  - reads `*(float *)(this + 0x100)`;
  - increments `*(DWORD *)(this + 0xf8)`;
  - formats with `sub_583280(&local, L"%5.1f FPS", m_currentFps)`;
  - reads bounds through `sub_4B8E00(this, &bounds)`;
  - calls `sub_4B9660(this, 0)` then `dword_69B3FC(this, &bounds)`;
  - draws the formatted text through `sub_4B9680` / `sub_4B9600` / `sub_4BAB70` twice;
  - releases the temporary wide string with `sub_582B70`.
- Local IDA assembly confirms exact draw arguments:
  - first text pass: `sub_4B9680(this, 0x80)`, `sub_4B9600(this, 1, 13)`, `sub_4BAB70(this, text, length)`;
  - second text pass: `sub_4B9680(this, 0x0e)`, `sub_4B9600(this, 0, 12)`, `sub_4BAB70(this, text, length)`.
- Local IDA map confirms `sub_4B67B0` and the adjacent `sub_4B68B0`, plus `const FpsPane::vftable` symbols at `0x0061a620`, `0x0061a66c`, and `0x0061a69c`.

## Heuristic / Inference Reanalysis And Validation

### Source-Bearing Versus No-Code

- Best inference: source-bearing `FpsPane::OnPaint`.
- Evidence: modeled function body, vtable slot at `0x0061a664`, FpsPane-owned fields, FPS overlay literal, normal paint helper callees, and exact padding boundaries.
- Rejected: compiler scalar-deleting glue, adjustor thunk, padding, or generated-only function. The nearby actual glue is [UID:00015K] adjustor thunks and [UID:00015L] scalar deleting destructor, not this range.
- Impact: keep `RECONSTRUCTABLE:TRUE`, owner/emitter route, and populate C++ when accepted.

### Name And Signature

- Recommended source name/signature: `void FpsPane::OnPaint()`.
- Evidence: IDA C export is `void __thiscall sub_4B67B0(int this)`, no explicit stack arguments, and the vtable primary slot `+0x44` is documented as the FpsPane paint slot.
- Rejected: `FpsPaneOnPaint` as source spelling. Keep it only as the documentation/file slug if needed; use `FpsPane::OnPaint` in prose and coverage.

### FPS Fields

- `+0xf8`: `m_frameCount`, incremented on every paint, reset/read by `UpdateStatistics` after `+0xa4` timer-subobject normalization.
- `+0x100`: `m_currentFps`, a `float`, written by `UpdateStatistics` and formatted by `OnPaint`.
- Rejected: `m_tickCounter` for `+0xf8`; paint increments make `m_frameCount` the better source-facing name.
- Open: exact original member spellings remain descriptive, but the field roles are strong enough for draft C++.

### GrafPort / Text / String Helpers

Recommended helper labels for this target:

| Address/name | Best source-quality role | Owner evidence |
| --- | --- | --- |
| `sub_4B8E00` | `GetBounds(RectBounds*)` / inherited root-pane bounds accessor | [UID:000161] documents the exact `BackPane::GetBounds` leaf copying bounds at `+0x44`; FpsPane consumes it as an inherited pane helper. |
| `sub_4B9660` | `GrafPort::SetDrawColor` / fill-color state setter | [UID:000162] documents `this+0x74` draw/fill color accessor. |
| `dword_69B3FC` | Surface callback slot 7, invalidation/fill/presentation callback | [UID:0000TN]/[UID:0001PI] document broad slot-7 callback-table ownership; do not call it `g_pfnLockSurface` here. |
| `sub_4B9680` | `GrafPort::SetTextColor` / primary text palette-color state for this paint path | [UID:000162]/[UID:00016C] document the `+0x7c` text/draw color role; final public name still has `SetBkColor` alias pollution. |
| `sub_4B9600` | `GrafPort::MoveTo(int x, int y)` | [UID:000162] documents the draw cursor setter at `+0x6c/+0x68`. |
| `sub_4BAB70` | `GrafPort::DrawWideText(const wchar_t*, int)` | [UID:00016C] documents the wide-text renderer, internally using `StringIter` and `FontImageLib`. |
| `sub_583280` | `StringBaseWideFormatCtor` / UTF-16 varargs format initializer | [UID:0002LK]. |
| `sub_584CF0` | `StringBase` length accessor | [UID:0003NM]. |
| `sub_584540` | string data pointer / `c_str()` accessor | [UID:0002RS]. |
| `sub_582B70` | wide string release/destructor wrapper | [UID:0002RN]. |

Final open naming issue: the exact public string facade may be `mystr::StringBase<wchar_t>` or a `SimpleUString` wrapper. Use `StringBase<wchar_t>` or a project-local wide-string typedef in the accepted C++ draft, and keep this as a score cap, not a blocker.

### Owner / Emitter / Source-File Route

- Accepted direct owner: [UID:00005F] `FpsPane`.
- Accepted source root: [UID:0000JK] `FpsPane`, path `NexusTK/ui/diagnostics/FpsPane.cpp`.
- Evidence: FpsPane vtable slot, FpsPane layout fields, FpsPane diagnostic string data, diagnostics aggregate, and existing generated route all align.
- Rejected owners:
  - `GrafPort`: owns draw helper callees, not the FpsPane method body.
  - `StringBase` / `StringUtil`: own temporary string helpers, not the paint method.
  - `SurfaceRenderCallbackTable`: owns callback slot `dword_69B3FC`, not the caller.
  - `ParcelPane`, `MapPane`, `ObjectList`, or `MainUiGraph`: no FpsPane OnPaint ownership evidence.

### Stale No-Code / Generated-Name Issues

- The target's "Final C++ is blank below 95/95" note is stale under the active policy.
- This page already clears the active code gate: `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00005F`, generated route to `FpsPane.cpp`, and current average `87.0`.
- The reason C++ is missing is policy/documentation lag, not a real no-code proof.
- Replace `sub_*` labels in target prose with the helper roles above while preserving exact addresses as evidence.

## First-Draft C++ Recommendation

Populate the target C++ block after supervisor acceptance. This draft intentionally uses source-facing names and leaves exact final string-facade/helper typedef spelling to the implementation pass.

```cpp
void FpsPane::OnPaint()
{
    ++m_frameCount;

    mystr::StringBase<wchar_t> fpsText(L"%5.1f FPS",
                                       static_cast<double>(m_currentFps));

    RectBounds bounds;
    GetBounds(&bounds);

    SetDrawColor(0);
    g_pfnSurfaceFillOrInvalidate(this, &bounds);

    SetTextColor(128);
    MoveTo(1, 13);
    DrawWideText(fpsText.c_str(), fpsText.length());

    SetTextColor(14);
    MoveTo(0, 12);
    DrawWideText(fpsText.c_str(), fpsText.length());
}
```

Implementation notes:

- If the accepted project string wrapper uses `SimpleUString` rather than `mystr::StringBase<wchar_t>`, adapt only the type/API spelling; keep the `L"%5.1f FPS"` varargs format semantics.
- If the accepted callback table name remains unresolved, use a descriptive placeholder tied to [UID:0000TN] slot 7 and document it. Do not use generated `g_pfnLockSurface` as if proven.
- If final GrafPort naming keeps `SetBkColor` for `0x004b9680`, add a local note that this paint path uses it as the active text palette/color state before `DrawWideText`.

## Documentation Evidence And IDA Status

- [UID:00015G] target page supports the exact range, virtual dispatch, FPS fields, literal, two-pass draw sequence, and stale C++ blocker.
- [UID:00005F] `FpsPane` class and [UID:0000JK] `FpsPane` file support owner/source route and standardize `m_frameCount` / `m_currentFps`.
- [UID:0001UO] `FpsPaneLayout` confirms `+0xf8` and `+0x100`, with `UpdateStatistics` normalized by the `+0xa4` timer subobject.
- [UID:0001XN] and [UID:0002MJ] confirm primary vtable slot `0x0061a664 -> 0x004b67b0`.
- [UID:0003BJ] confirms UTF-16 overlay literal `%5.1f FPS` at `0x0061a7c8` with one xref from `0x004b67f7`.
- [UID:00016C], [UID:000162], [UID:000161], and StringBase helper pages support the callee names used in the draft.
- Prior executed B001/B002/B007 research search found no report directly for UID `00015G`; two B001 incidental matches only mention FpsPane as neighboring/global context. A B003 FpsPane diagnostics report covers sibling constructor/logging helpers and explicitly left [UID:00015G] unchanged except for stale wording context.

## Ranked Ownership Analysis

### 1. [UID:00005F] FpsPane - Accepted

- Evidence for: direct vtable slot, FpsPane field offsets, FpsPane overlay literal, diagnostics cluster adjacency, class/file/layout docs, and generated route.
- Evidence against: no direct callers, but virtual paint dispatch explains that absence.
- Decision: keep as direct owner/emitter.

### 2. [UID:0000JK] FpsPane File - Source Root Only

- Evidence for: validated `NexusTK/ui/diagnostics/` source root and all FpsPane diagnostics content.
- Evidence against: method belongs semantically to the class, not file root.
- Decision: keep as source root via class emitter chain.

### 3. GrafPort / Surface / StringBase Support Owners - Dependencies Only

- Evidence for: all own important callees used by this body.
- Evidence against: none owns FpsPane fields, vtable slot, or overlay behavior.
- Decision: cite as helper owners/dependencies only.

### 4. ParcelPane / MapPane / ObjectList / MainUiGraph - Rejected

- Evidence for: none for this paint body.
- Evidence against: no ParcelPane state, no MapPane/ObjectList reads, no MainUiGraph-owned state except unrelated FpsPane session parent slot in sibling methods.
- Decision: reject.

## Exact Recommended Target-Doc Changes

Recommended metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended status/prose changes:

- Replace source name text with `FpsPane::OnPaint`.
- Replace "Final C++ is intentionally blank because the page is below the 95/95 reconstruction-code threshold" with: "This page clears the active reconstruction-code gate. Formal C++ should be populated after source-quality review; remaining caveats are final string facade, GrafPort helper names, and callback typedef spelling."
- Add local IDA export evidence for exact helper order and draw arguments:
  - `SetDrawColor(0)` then `dword_69B3FC(this, &bounds)`;
  - `SetTextColor(128)`, `MoveTo(1, 13)`, `DrawWideText`;
  - `SetTextColor(14)`, `MoveTo(0, 12)`, `DrawWideText`.
- Add helper-name table from this report.
- Add the first-draft C++ body above, adapted only for final project helper/type spelling.
- Add a change-log entry noting B007 source-quality pass, score recommendation `88/91`, stale C++ policy repair, and local IDA export verification.

## Validator Needs

- No validator was run because no by-* docs were edited in this report-only pass.
- Implementation callback should run a UID-targeted validation for [UID:00015G] after editing the target, then run/inspect generated autogen output for `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp` to confirm the empty marker is replaced by the method body and the emitter route has no dead end.
- Validator should also flag unresolved generated names if the target prose still contains `sub_4B67B0`, `sub_4B8E00`, `sub_4B9600`, `sub_4B9660`, `sub_4B9680`, `sub_4BAB70`, `sub_583280`, `sub_584CF0`, `sub_584540`, or `sub_582B70` without descriptive names.

## Exact Pending Coverage Text

Replace the existing [UID:00015G] row in `by-memory/-coverage-report.md` with:

```text
        - [UID:00015G][0x004b67b0-0x004b68ab.FpsPaneOnPaint](by-memory/0x004b67b0-0x004b68ab.FpsPaneOnPaint.md) 0x004b67b0-0x004b68ab | method | FpsPaneOnPaint : reconstructable : 88% : strong : B007 source-quality pass keeps this as source-bearing FpsPane::OnPaint under [UID:00005F] with emitter route to [UID:0000JK]; local IDA export and existing live IDA notes confirm void __thiscall primary-vtable paint slot at 0x0061a664, exact 0xfb body/padding, frame counter +0xf8 increment, current FPS +0x100 formatted via UTF-16 StringBase as L"%5.1f FPS", bounds fill/invalidation through inherited bounds/GrafPort helpers and Surface callback slot dword_69B3FC, two DrawWideText passes at (1,13)/color 128 and (0,12)/color 14, temp wide-string cleanup, generated sub_* names resolved to support helper pages, stale 95/95 no-code wording removed, and first-draft C++ ready with final GrafPort palette/typedef names still descriptive.
```

## Follow-Up Actions

- Supervisor: review/accept this report, then send B007 an implementation callback if the target page should be edited.
- Implementation pass: update [UID:00015G] metadata/prose/C++, run validation, inspect generated `FpsPane.cpp`, and leave `by-memory/-coverage-report.md` for supervisor-owned application unless the ban is lifted.
- Future research: a focused GrafPort naming pass should resolve whether `0x004b9680` should be called `SetTextColor`, `SetBkColor`, or a more general primary palette-color setter in final project declarations.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B007/research/00015G-FpsPaneOnPaint-source-quality.md`
- Modified: none.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/00015G-FpsPaneOnPaint-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"00015G"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
