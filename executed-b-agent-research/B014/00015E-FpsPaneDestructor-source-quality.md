** TARGET-REPORT-UID:00015E **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00015E FpsPaneDestructor Source-Quality Research

## Final Recommendation

- Target: [UID:00015E] `0x004b6470-0x004b6499.FpsPaneDestructor`
- Target path: `source-3/project-documentation/by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md`
- Current metadata: `84/90`, `CANONICAL_OWNER:00005F`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00005F`, blank C++
- Recommended metadata: `88/90`, keep `CANONICAL_OWNER:00005F`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:00005F`
- Source-facing name/signature: `FpsPane::~FpsPane()`
- First-draft C++ recommendation:

```cpp
FpsPane::~FpsPane()
{
    g_pFpsPane = NULL;
}
```

The binary vtable restores and the tail chain to `Pane::~Pane()` are compiler destructor lowering, not handwritten C++. The scalar deleting destructor at [UID:00015L] is likewise compiler-generated vtable/delete support and should remain a separate blank-code support page rather than a hand-authored `FpsPane::ScalarDeletingDestructor(unsigned int)` source method.

## Evidence Checked

- Read target [UID:00015E], current coverage row, autogen routing row, unresolved-name entries, and projected stats.
- Read support docs: [UID:00005F] `FpsPane`, [UID:0000JK] `FpsPane`, [UID:0000QZ] `g_pFpsPane`, [UID:0001UO] `FpsPaneLayout`, [UID:0001XN] `FpsPane_vtables`, [UID:00015C] constructor, [UID:00015D] diagnostics aggregate, [UID:00015K] adjustor thunks, and [UID:00015L] scalar deleting destructor.
- Read base support docs: [UID:0001EA] `PaneCore`, [UID:0000A2] `Pane`, [UID:0000MC] `Pane`, [UID:0003JA] `PaneVtables`, and [UID:0003CA] `PaneVtableData`.
- Read B003 executed FpsPane diagnostics source-quality report. That report intentionally did not refresh siblings [UID:00015E] and [UID:00015L].
- Checked current generated `source-3/simroot_v2/class_FpsPane.cpp` as lead evidence only. It still contains raw vtable writes and a hand-written scalar deleting wrapper shape, so it should not be treated as final source authority.
- Tried IDA MCP via `http://127.0.0.1:13337/mcp`; result was `MCP_ERROR: Unable to connect to the remote server`.
- Used local IDA export `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.lst` after MCP failed.

Local IDA export confirms the target instruction shape:

- `0x004b6470`: `sub_4B6470 proc near`
- `0x004b6470`, `0x004b6476`, `0x004b6480`: stores `FpsPane` primary, secondary, and timer/update vtables.
- `0x004b648a`: clears `dword_69B334`.
- `0x004b6494`: jumps to `sub_544580`.
- `0x004b6499`: alignment before raw body `0x004b64a0`.

The same local export confirms sibling and support facts:

- `0x004b6c50`: `sub_4B6C50` scalar deleting destructor.
- `0x004b6c56`, `0x004b6c5c`, `0x004b6c66`: same three FpsPane vtable stores in the scalar deleting wrapper.
- `0x004b6c70`: clears `dword_69B334`.
- `0x004b6c7a`: calls `sub_544580`.
- `0x0061a620`: primary FpsPane vtable first slot points to `sub_4B6C50`.
- `0x0061a66c` and `0x0061a69c`: secondary/tertiary FpsPane views point to adjustor thunks `sub_4B6C2B` and `sub_4B6C36`.
- `0x0069b334`: `dword_69B334 dd ?`, matching source declaration `FpsPane* g_pFpsPane;`.
- `0x00544580`: `sub_544580`, now documented by Pane support as ordinary `Pane::~Pane()` at `0x00544580-0x00544687`.

## Gate And Policy Recheck

The target's current blank-C++ explanation says it is below a `95/95` reconstruction-code threshold. That is stale.

Current active code-entry policy, from validator docs and supervisor guidance, is:

- `RECONSTRUCTABLE:TRUE`
- nonblank `EMITTER_UIDS` that surface to a valid by-file source root
- `(COMPLETION + CONFIDENCE) / 2 > 85`
- enough local evidence for dependencies, names, boundaries, and source placement

Current target average is already `87.0`, but completion is still `84`, and the page still carries stale gate and class-score wording. Recommended `88/90` makes the stricter current `85/85` target/support discussion unambiguous:

- target [UID:00015E]: recommended `88/90`
- direct class owner [UID:00005F] `FpsPane`: current `87/88`
- class source-file route [UID:0000JK] `FpsPane`: current `88/87`
- global [UID:0000QZ] `g_pFpsPane`: current `87/90`
- base [UID:0000A2] `Pane`: current `88/86`

The output route is already valid in `auto-generated/-ag-memory-coverage.md`: [UID:00015E] emits through `00005F` to `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp`.

## Source-Quality Reanalysis

| Issue | Evidence | Decision |
| --- | --- | --- |
| Source name/signature | Target is a modeled 0x29-byte non-deleting destructor body. Class/file pages place it in FpsPane diagnostics. | Use `FpsPane::~FpsPane()`. Keep raw `sub_4B6470` only as historical IDA name. |
| Source-authored statements | Only semantic side effect specific to FpsPane is clearing `g_pFpsPane` at `0x004b648a`. Constructor publishes the same singleton; scalar wrapper mirrors the clear. | Handwritten source body is `g_pFpsPane = NULL;` or equivalent zero assignment. |
| Vtable stores | Target and scalar wrapper both restore FpsPane vtable views at owner offsets `+0x00`, `+0xa0`, and `+0xa4`; constructor installs the same views. | Do not write vtable pointers in C++. They are compiler output from class layout/destructor lowering. |
| Base destructor | Target tail-jumps to `0x00544580`; current Pane docs identify this as ordinary `Pane::~Pane()`, not stale `TextButtonExControlPane` or `GrafPort` ownership. | Treat as implicit base destructor chaining after `FpsPane::~FpsPane()` body. Do not hand-author `Pane::~Pane()` in the C++ block. |
| Scalar-delete split | Primary FpsPane vtable slot points to `0x004b6c50`, and secondary/timer views point to adjustor thunks that jump there. The wrapper repeats the clear and optionally deletes memory based on flags. | Keep [UID:00015L] as compiler-generated scalar deleting destructor support with blank C++; source representation comes from `virtual ~FpsPane()` plus [UID:00015E]'s ordinary destructor body. |
| Singleton/global behavior | `g_pFpsPane` storage is `dword_69B334 dd ?`; constructor writes it, ordinary destructor clears it, scalar deleting destructor clears it. Global page emits `FpsPane* g_pFpsPane;`. | No new global declaration in [UID:00015E]. Link to [UID:0000QZ] and use `g_pFpsPane = NULL;` in destructor body. |
| Owner/emitter route | FpsPane class is `87/88`, file is `88/87`, global/vtable/layout docs all route to FpsPane diagnostics. | Keep direct owner/emitter [UID:00005F]. Source file remains [UID:0000JK] `NexusTK/ui/diagnostics/FpsPane.cpp`. |
| Generated/raw names | Target still exposes `sub_4B6470`; target/scalar pages expose `sub_544580` and `sub_4F4AC0`. | Replace source-facing wording with `FpsPane::~FpsPane()`, `Pane::~Pane()`, and compiler delete helper where needed. Raw names can remain in evidence sections only. |

Rejected alternatives:

- Empty destructor source body: rejected because `g_pFpsPane` clear is a source-level singleton lifecycle statement, not just ABI noise.
- Manual vtable writes: rejected as compiler-generated destructor mechanics.
- Explicit `Pane::~Pane()` call in the C++ block: rejected because normal C++ destructor chaining emits the call.
- Handwritten `FpsPane::ScalarDeletingDestructor(unsigned int flags)`: rejected because that function is compiler ABI support regenerated from the virtual destructor and class declaration.
- ParcelPane, MapPane, ObjectList, or MainUiGraph ownership: rejected. They are stale generated pollution or dependencies; the vtable/global/layout/source-route evidence is FpsPane-specific.

## Recommended Target Doc Changes

Header changes:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace the blank reconstruction block with:

```cpp
FpsPane::~FpsPane()
{
    g_pFpsPane = NULL;
}
```

Recommended status/body edits:

- Change entity kind to `ordinary/non-deleting FpsPane destructor body`.
- Change IDA function wording to: `IDA function: historical raw name sub_4B6470, size 0x29; source-facing name FpsPane::~FpsPane()`.
- Replace stale parent sentence `class is 82/80` with current gate wording: target recommended `88/90`, direct class [UID:00005F] is `87/88`, and class emits through [UID:0000JK] `FpsPane` at `88/87`.
- Replace stale `below 95/95` no-code sentence with active gate sentence: target is reconstructable, has valid emitter route, combined score clears `>85`, and source body is ready.
- In Behavior, say: the binary restores three FpsPane vtable views, clears [UID:0000QZ] `g_pFpsPane`, and tail-chains to [UID:0000A2] `Pane::~Pane()`; only the singleton clear is handwritten source.
- Add a `Resolved Source-Quality Questions` or `Reconstruction Notes` section explaining that vtable stores, base destructor chaining, scalar deleting destructor, adjustor thunks, optional delete, and guard helper are compiler output.
- Add Pane support cross-references: [UID:0001EA] `PaneCore`, [UID:0000A2] `Pane`, [UID:0000MC] `Pane`, [UID:0003JA] `PaneVtables`, and [UID:0003CA] `PaneVtableData`.
- Add a change entry dated 2026-06-19 B014 source-quality report: raised to `88/90`, resolved source identity as `FpsPane::~FpsPane()`, replaced stale 95/95 wording, and populated first-draft destructor C++.

Suggested target `Score Rationale`:

```text
Completion is 88 because the page now records exact 0x29-byte bounds, vtable-view restores, singleton lifecycle, Pane base destructor identity, scalar-delete split, owner/emitter route, active code-entry gate, and first-draft source body. Confidence remains 90 because the byte/function evidence is strong and corroborated by current FpsPane/Pane/global/vtable docs and local IDA export, but no direct callers/xrefs reach the ordinary body and final stylistic spelling of the zero assignment remains below final-audit proof.
```

## Recommended Support Doc Changes

These support edits are not required to enter target C++ but keep the docs coherent if the supervisor implements the report.

- [UID:00005F] `FpsPane`: update the method row for `0x004b6470-0x004b6499` to `FpsPane::~FpsPane()`, source body clears `g_pFpsPane`; vtable restores and `Pane::~Pane()` chain are compiler output. Keep `0x004b6c50-0x004b6caf` as scalar deleting wrapper/delete support.
- [UID:0000JK] `FpsPane`: add a short lifecycle note matching the constructor/global/scalar-delete split. The file owns `FpsPane::~FpsPane()` source under `NexusTK/ui/diagnostics/FpsPane.cpp`.
- [UID:0000QZ] `g_pFpsPane`: add that B014 resolves [UID:00015E] as the ordinary source destructor body and [UID:00015L] as compiler wrapper evidence.
- [UID:00015L] scalar deleting destructor: keep formal C++ blank, but replace stale `below 95/95` wording with target-specific no-code proof: this is compiler-generated scalar deleting wrapper/optional delete support regenerated from `virtual ~FpsPane()`. Consider `86/90` if the support page is refreshed.
- [UID:00015D] aggregate: no aggregate C++; add that [UID:00015E] now carries the ordinary destructor C++ and [UID:00015L] remains wrapper-only.
- [UID:0001UO] layout and [UID:0001XN] vtable docs: no score change required; they already support three vtable views and scalar-delete thunk split.
- `project-level/-unresolved.md` will shrink after validator/reference refresh once `sub_4B6470` and `sub_544580` are confined to evidence wording rather than status/source-facing names.

## Exact Pending Coverage Text

Replace current `by-memory/-coverage-report.md` row line for [UID:00015E] with:

```text
        - [UID:00015E][0x004b6470-0x004b6499.FpsPaneDestructor](by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md) 0x004b6470-0x004b6499 | destructor | FpsPaneDestructor : reconstructable : 88% : strong : B014 source-quality review resolves this as ordinary `FpsPane::~FpsPane()`: handwritten source clears `g_pFpsPane`, while three FpsPane vtable-view restores at `+0x00/+0xa0/+0xa4` and the tail chain to `Pane::~Pane()` at `0x00544580` are compiler destructor mechanics. Local IDA export and current docs confirm exact `0x29` body, clear at `0x004b648a`, no direct callers/xrefs, padding before/after, scalar deleting wrapper [UID:00015L] as vtable/delete support, owner/emitter route through [UID:00005F] to [UID:0000JK], active combined-score gate readiness, and first-draft C++ should be populated.
```

Optional support-row refresh if [UID:00015L] is edited in the same implementation callback:

```text
        - [UID:00015L][0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor](by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md) 0x004b6c50-0x004b6caf | scalar deleting destructor | FpsPaneScalarDeletingDestructor : reconstructable : 86% : strong : FpsPane compiler-generated scalar deleting destructor wrapper: primary vtable slot and adjustor thunks route here, the wrapper restores FpsPane vtable views, clears `g_pFpsPane`, chains to `Pane::~Pane()` at `0x00544580`, and conditionally frees through `sub_4F4AC0`; handwritten source belongs to ordinary [UID:00015E] `FpsPane::~FpsPane()`, so this page stays blank-code with compiler-wrapper no-code proof rather than stale 95/95 wording.
```

## Validator Needs If Implemented

No validator was run for this B-agent report because no by-* docs or coverage files were edited.

If the supervisor implements only the target and target coverage row:

> Executable block R001 was removed from this report and preserved verbatim in [00015E-FpsPaneDestructor-source-quality-removed.md](00015E-FpsPaneDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If [UID:00015L] or support docs are edited too, run file-mode validation for each touched by-* file before the autogen/rescore refresh.

## Open Questions And Residual Risk

- Direct callers/xrefs to ordinary `0x004b6470` remain absent. This matches nearby destructor-body patterns and is not a C++ blocker because the scalar deleting wrapper is the vtable-reachable deletion route.
- The exact source spelling of the zero assignment is not recovered. `NULL` matches recent Pane-derived singleton destructor style such as `ChattingBackPane`; `0` is equivalent if the final FpsPane source file avoids `NULL`.
- Final original class declaration spelling, inherited interface names, and complete FpsPane header shape remain broader class/file tasks, but they do not block this destructor body.
- Current generated `class_FpsPane.cpp` still has raw ABI-shaped code; the implementation should overwrite that through validator autogen after target C++ is populated, not manually preserve the generated scalar deleting wrapper.

## Changed Files

- Created this report:
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B014/research/00015E-FpsPaneDestructor-source-quality.md`
- Modified no by-* docs.
- Modified no coverage reports.
- Preserved existing `00013F-EncoderWriteByte-source-quality.md`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/00015E-FpsPaneDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"00015E"} -->
<!-- {"agent":"B014","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00015E-FpsPaneDestructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B014/00015E-FpsPaneDestructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00015E"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
