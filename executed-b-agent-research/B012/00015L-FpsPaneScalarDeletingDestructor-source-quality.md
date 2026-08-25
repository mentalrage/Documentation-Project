** TARGET-REPORT-UID:00015L **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00015L FpsPaneScalarDeletingDestructor Source-Quality Research

## Final Recommendation

- Target: [UID:00015L][0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor](../../../../by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md)
- Final disposition: source-declared/generated-binary FpsPane scalar deleting destructor glue. This page should not become a source-bearing handwritten C++ destructor body.
- Recommended metadata: keep `CANONICAL_OWNER:00005F`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00005F`; raise score from `84/90` to `86/91`.
- Recommended target C++: comment-only no-code marker, not a wrapper implementation:

```cpp
// Compiler-generated scalar deleting destructor for FpsPane; source is FpsPane::~FpsPane().
```

The ordinary source-bearing destructor belongs on [UID:00015E][0x004b6470-0x004b6499.FpsPaneDestructor](../../../../by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md), not this target. Recommended support update for `00015E`: raise to `86/91` and add first-draft source:

```cpp
FpsPane::~FpsPane()
{
    g_pFpsPane = 0;
}
```

Do not hand-write the scalar deleting wrapper body, the three vtable stores, the flag/delete checks, the guard-check path, or the adjustor thunks. Those are compiler output from the class declaration, virtual destructor, base layout, and ordinary destructor definition.

## Evidence Checked

- Current target page `00015L`, ordinary destructor page `00015E`, aggregate `00015D`, class [UID:00005F] `FpsPane`, file [UID:0000JK] `FpsPane`, layout [UID:0001UO], vtables [UID:0001XN], exact vtable data [UID:0002MJ], adjustor thunks [UID:00015K], and global [UID:0000QZ] / exact storage [UID:0002W0].
- Prior B003 FpsPane source-quality report `Agent-B003/research/executed/00015C-00015F-00015I-00015J-FpsPaneDiagnosticsSourceQuality.md`.
- Local exported function evidence:
  - `resources/exported_data/functions/0x004b6c50.json`
  - `resources/exported_data/functions/0x004b6470.json`
  - `hooks-generation/tests/function_data/ida/0x004b6c50.json`
  - `hooks-generation/tests/function_data/ida/0x004b6470.json`
- Local IDA listing `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.lst`.
- Active generated output `source-3/project-documentation/auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp`.
- Generated coverage rows in `auto-generated/-ag-memory-coverage.md`, project low-score row in `project-level/-auto-completion-stats.md`, and current `by-memory/-coverage-report.md` FpsPane block.
- Current IDA MCP check was attempted through `http://127.0.0.1:13337/mcp`; result: `MCP_ERROR: Unable to connect to the remote server`. This report therefore relies on existing live-MCP page notes plus local IDA/exported evidence.
- `tools/int_convert.py` verified constants: `0x5f = 95`, `0x29 = 41`, `0xa0 = 160`, `0xa4 = 164`, and `0x170 = 368`.

## Direct Binary Facts

`00015L` is one exact modeled function:

- IDA name: `sub_4B6C50`.
- Range/size: `0x004b6c50-0x004b6caf`, size `0x5f` / 95 bytes.
- Xrefs to target: adjustor-thunk jumps at `0x004b6c31` and `0x004b6c3c`, plus primary vtable data ref `0x0061a620`.
- No ordinary direct code callers are recorded; dispatch is vtable/thunk based.
- Callees: pane-base destructor helper `sub_544580`, delete/free wrapper `sub_4F4AC0`, and `_guard_check_icall_nop`.
- Assembly restores FpsPane vtable views at `+0x00`, `+0xa0`, and `+0xa4`, clears `dword_69B334`, calls `sub_544580`, tests scalar deleting flags, calls `sub_4F4AC0` only when `(flags & 1) != 0` and `(flags & 4) == 0`, and has a flag-4 guard path that pushes `0x170`.
- Local listing confirms the preceding adjustor thunks:
  - `0x004b6c2b`: `sub ecx, 0xa0; jmp sub_4B6C50`
  - `0x004b6c36`: `sub ecx, 0xa4; jmp sub_4B6C50`
- Boundary evidence remains exact: padding at `0x004b6c41-0x004b6c50` before the target and `0x004b6caf` before successor `0x004b6cb0`.

The ordinary destructor `00015E` is the source-bearing companion:

- IDA name: `sub_4B6470`.
- Range/size: `0x004b6470-0x004b6499`, size `0x29` / 41 bytes.
- Body restores the same three vtable views, clears `dword_69B334`, and tail-jumps to `sub_544580`.
- No direct callers/xrefs are recorded, which is normal for an ordinary destructor whose deleting wrapper carries the vtable slot.

## Source-Quality Decision

The target should become documented as no-code compiler scalar deleting destructor glue, while remaining class-owned and emitter-routed:

- Keep `RECONSTRUCTABLE:TRUE`: the rebuilt source must still declare/define `FpsPane` with a virtual destructor/inheritance shape that regenerates this ABI wrapper.
- Keep `CANONICAL_OWNER:00005F` and `EMITTER_UIDS:00005F`: the primary vtable slot, secondary/tertiary adjustor thunks, vtable restores, singleton clear, and ordinary destructor parity all identify one direct class owner.
- Do not reclassify to `RECONSTRUCTABLE:FALSE`: unlike shared ownerless generated wrappers, this is not a mixed multi-class helper and not runtime/third-party code.
- Do not emit a wrapper implementation: a handwritten `ScalarDeletingDestructor` function would duplicate compiler output and conflict with the ordinary destructor page.

The current target text is stale where it says final C++ is blank because the page is below a `95/95` threshold. The target already clears the active gate by metadata and route: `RECONSTRUCTABLE:TRUE`, nonblank `EMITTER_UIDS:00005F`, and average score `(84 + 90) / 2 = 87`, which is over 85. Blank/no-code is justified only by generated-binary policy, not by the old score gate.

## Ordinary Destructor Placement

`00015E` is the right page for first-draft source because it models the source-authored destructor semantics. The source body should express only the semantic side effect:

```cpp
FpsPane::~FpsPane()
{
    g_pFpsPane = 0;
}
```

Compiler-generated or implicit parts:

- three FpsPane vtable restores at `+0x00/+0xa0/+0xa4`;
- pane-base destructor call/tail-jump to `sub_544580`;
- scalar deleting destructor flag checks and optional `sub_4F4AC0`;
- secondary/tertiary adjustor thunks at `00015K`.

The final source declaration still needs the accepted class/base declaration context, but that is a final-audit cap, not a blocker to first-draft destructor C++.

## Globals And Singleton Behavior

`g_pFpsPane` is a real FpsPane module global, not wrapper-local storage:

- Raw constructor writes it at `0x004b6434`.
- Ordinary destructor clears it at `0x004b648a`.
- Scalar deleting destructor clears it at `0x004b6c70`.
- Local IDA export lists `.data:0069B334 dword_69B334 dd ?`, matching zero-initialized source storage `FpsPane* g_pFpsPane;`.
- The by-global page already emits `FpsPane* g_pFpsPane;`; the exact storage child remains blank to avoid duplicate output.

The scalar deleting destructor's singleton clear is the same destructor semantic side effect already represented by `FpsPane::~FpsPane()`. It is not evidence for an additional source function.

## Routing And Rejected Alternatives

Accepted:

- Direct semantic owner: [UID:00005F][FpsPane](../../../../by-class/FpsPane.md).
- Downstream file route: [UID:0000JK][FpsPane](../../../../by-file/FpsPane.md), `NexusTK/ui/diagnostics/FpsPane.cpp`.
- Rebuild classification: source-declared/generated-binary destructor ABI support.

Rejected:

- Direct file owner [UID:0000JK]: too broad. This is a class vtable/deleting-destructor artifact; class is the narrow owner.
- `CANONICAL_OWNER:NONE`: stale for this target. The primary vtable and thunk paths prove a single class owner.
- `RECONSTRUCTABLE:FALSE`: appropriate for `00015K` adjustor thunks, but not for this class-owned deleting destructor support.
- Handwritten source wrapper: would encode MSVC ABI glue and duplicate the ordinary destructor semantics.
- ParcelPane, MapPane, ObjectList, MainUiGraph: B003 already rejected these for FpsPane diagnostics; no target evidence points to those owners.

## Compiler-Generated And Raw Names

Use raw/generated names only as evidence labels:

- `sub_4B6C50`, `virt_deldtor_0x4b6c50`, and `ScalarDeletingDestructor` are binary/documentation names, not source method names.
- Source should use `FpsPane::~FpsPane()` on `00015E`; the compiler emits the deleting destructor wrapper for the vtable slot.
- `sub_544580` should remain a base-pane destructor helper until the final Pane/TextButtonExControlPane declaration is accepted.
- `sub_4F4AC0` is a shared delete/free wrapper, not FpsPane-owned logic.
- `_guard_check_icall_nop` and the `0x170` guard-size path are compiler/runtime guard behavior.

## Score And Metadata Recommendation

Recommended target `00015L` metadata:

```text
COMPLETION:86
CONFIDENCE:91
CANONICAL_OWNER:00005F
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00005F
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: comment-only no-code marker
```

Rationale: completion rises because source policy, owner/emitter routing, ordinary-destructor placement, singleton/global ownership, caller/thunk/vtable routing, and stale gate wording are now resolved. Confidence rises modestly because local exported evidence and listing lines agree with existing live IDA page notes. Do not raise near `95+` until final FpsPane declaration/base class and full source audit are complete.

Recommended support `00015E` metadata:

```text
COMPLETION:86
CONFIDENCE:91
CANONICAL_OWNER:00005F
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00005F
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE: first-draft FpsPane::~FpsPane()
```

No score change is required for `00005F`, `0000JK`, `00015K`, `0001XN`, `0002MJ`, `0000QZ`, or `0002W0`.

## Recommended Exact Doc Changes

For target `00015L`:

- Change disposition from `reconstructable NexusTK project code` to `source-declared/generated-binary FpsPane scalar deleting destructor glue`.
- Replace the stale parent score sentence with current class/file scores: class `00005F` is `87/88`, file `0000JK` is `88/87`, and routing through the class is valid.
- Replace the stale final-C++ sentence with: "Formal source is intentionally comment-only/no-code because this is compiler-generated scalar deleting destructor glue; the source-bearing destructor is [UID:00015E] `FpsPane::~FpsPane()`."
- Add the local export/listing facts for `sub_4B6C50`: size `0x5f`, xrefs from `0x004b6c31`, `0x004b6c3c`, and `0x0061a620`, vtable restores, clear at `0x004b6c70`, `sub_544580`, optional `sub_4F4AC0`, guard path with `0x170`, and padding.
- Add the comment-only C++ marker shown in this report.

For support page `00015E`:

- Replace "Final C++ is intentionally blank because the page is below the 95/95 reconstruction-code threshold" with the active gate/source-shape analysis.
- Add first-draft destructor C++:

```cpp
FpsPane::~FpsPane()
{
    g_pFpsPane = 0;
}
```

- Note that vtable stores and base destructor call are compiler/implicit output, not handwritten source statements.

For class/file docs:

- In [UID:00005F] `FpsPane`, change the scalar destructor method note to say it is class-owned generated-binary glue, while `00015E` carries the source-level destructor body.
- In [UID:0000JK] `FpsPane`, route the non-deleting destructor as the source-bearing destructor and the scalar deleting destructor as compiler-generated support.

## Open Questions / Score Caps

- Final source declaration and base-class spelling are not fully audited. Existing docs use pane-base helper wording, while Ghidra export labels the callee as `TextButtonExControlPane::~TextButtonExControlPane`.
- Final class header placement and exact `virtual` declaration shape are still inferred from vtables.
- `g_pFpsPane = 0;` vs `NULL` is a style decision for the final codebase; avoid `nullptr` if matching the project's older C++ style.
- The raw constructor/session/helper liveness questions from the broader FpsPane cluster remain outside this target, but they cap final class-level audit confidence.
- The `0x170` guard-size path should be retained as ABI evidence, not converted into source.

## Validator Needs

No validator was run in this B-agent pass because only this research report was created.

If the supervisor accepts the recommendations, validate at least:

> Executable block R001 was removed from this report and preserved verbatim in [00015L-FpsPaneScalarDeletingDestructor-source-quality-removed.md](00015L-FpsPaneScalarDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If class/file prose is updated in the same implementation callback, also validate:

> Executable block R002 was removed from this report and preserved verbatim in [00015L-FpsPaneScalarDeletingDestructor-source-quality-removed.md](00015L-FpsPaneScalarDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After applying the supervisor-owned coverage text, validate `by-memory/-coverage-report.md` through the normal supervisor flow.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` in this B-agent pass. Recommended replacements in the FpsPane block:

```text
        - [UID:00015E][0x004b6470-0x004b6499.FpsPaneDestructor](by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md) 0x004b6470-0x004b6499 | ordinary destructor | FpsPaneDestructor : reconstructable : 86% : strong : B012 source-quality review makes this the source-bearing `FpsPane::~FpsPane()` page; first-draft C++ is the singleton clear `g_pFpsPane = 0`, while the three FpsPane vtable-view restores and pane-base destructor call are compiler/implicit destructor output. Local IDA/export evidence confirms `sub_4B6470` size `0x29`, vtable restores at +0x00/+0xa0/+0xa4, `g_pFpsPane` clear at 0x004b648a, tail-call to `sub_544580`, no direct callers/xrefs, scalar-deleting destructor parity, exact padding, class owner [UID:00005F], and route to `FpsPane.cpp`.
        - [UID:00015L][0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor](by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md) 0x004b6c50-0x004b6caf | scalar deleting destructor glue | FpsPaneScalarDeletingDestructor : reconstructable : 86% : strong : B012 source-quality review classifies this as source-declared/generated-binary FpsPane scalar deleting destructor glue, not a source-bearing handwritten method. Keep direct owner/emitter [UID:00005F][FpsPane](by-class/FpsPane.md); use a comment-only no-code marker while [UID:00015E] carries `FpsPane::~FpsPane()` source. Local IDA/export evidence confirms `sub_4B6C50` size `0x5f`, primary vtable slot 0x0061a620, adjustor-thunk jumps from 0x004b6c31/0x004b6c3c, three vtable-view restores at +0x00/+0xa0/+0xa4, `g_pFpsPane` clear at 0x004b6c70, pane-base destructor call `sub_544580`, optional delete wrapper `sub_4F4AC0` only for scalar-delete flags without flag 4, guard-check flag-4 path with size 0x170, no direct callers, and exact padding before/after.
```

Expected generated-memory coverage rows after metadata/C++ marker refresh:

```text
| [UID:00015E][0x004b6470-0x004b6499.FpsPaneDestructor](by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md) | coded | `00005F` | `00005F` |  | yes | `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp` | `by-memory/0x004b6470-0x004b6499.FpsPaneDestructor.md` |  |
| [UID:00015L][0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor](by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md) | coded | `00005F` | `00005F` |  | yes | `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp` | `by-memory/0x004b6c50-0x004b6caf.FpsPaneScalarDeletingDestructor.md` |  |
```

If the supervisor decides to keep `00015L`'s formal C++ block completely blank instead of using the comment-only marker, the generated-memory row will remain `emits/no`; the no-code proof above still means no wrapper body should be written.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B012/research/00015L-FpsPaneScalarDeletingDestructor-source-quality.md`
- Modified: none.
- Moved/renamed: none.
- Preserved: `source-3/project-documentation/tools/leaser/Agents/Agent-B012/research/00013C-EncoderConstructor-source-quality.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/00015L-FpsPaneScalarDeletingDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"00015L"} -->
<!-- {"agent":"B012","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00015L-FpsPaneScalarDeletingDestructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B012/00015L-FpsPaneScalarDeletingDestructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00015L"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
