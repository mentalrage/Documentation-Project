*** UID:00000V | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BaramApp

## Summary

`BaramApp` is the game-client specialization of [UID:00000D][Application](by-class/Application.md). It does not appear to own broad startup/shutdown policy; its confirmed behavior is the foreground/background transition policy for the live client: event timer state, map-pane window visibility, background processing, keyboard restore, parcel-walk cancellation, and sound/music pause/resume.

The C++ reconstruction block is intentionally blank. The subclass relationship and vtable evidence are strong, but the final source split and field names are not final-source quality.

The activation/deactivation handlers, startup constructor, terminal-pane callback factory, scalar deleting destructor, and read-only vtable/string-data range are now parent-attached to this class. Final C++ remains blank because field names, helper names, non-contiguous audio-tail ownership, and the exact original source split are not final-source quality.

Autogen attaches this class to [UID:0000HG][Application](by-file/Application.md)
at position `20`, after [UID:00000D][Application](by-class/Application.md).
This reflects the current source-structure decision that `BaramApp` belongs in
the application-shell source root. Final C++ stays blank under the `95/95`
final-source gate.

## Likely Original Placement

- Source: [UID:0000HG][Application](by-file/Application.md)
- Proposed path: `app/Application.cpp` or `app/BaramApp.cpp`
- Current preference: keep `BaramApp` in the same application-shell module as `Application` unless later evidence proves a small separate `BaramApp.cpp`.
- Confidence: medium-strong for application-shell ownership, medium for the exact source-file split.

## Inheritance And Binary Shape

- `BaramApp` is documented as an `Application` variant/subclass. The startup and destructor neighborhood shares the same application shell as `Application::Startup` and `Application::Shutdown`.
- [UID:00025P][0x0061d118-0x0061d264.BaramAppReadOnlyData](by-memory/0x0061d118-0x0061d264.BaramAppReadOnlyData.md) contains the primary `BaramApp` vtable at `0x0061d118`, a secondary adjusted/base table at `0x0061d138`, and a `PlainMemberFunctionObject0<BaramApp>` callback wrapper vtable at `0x0061d238`.
- The exact source fields are not fully reconstructed here. IDA decompilation of the activation handlers observes flag bytes around `this + 2105` and `this + 2106`, which should be interpreted through the `Application`/`BaramApp` layout before assigning final field names.

## Method Inventory

| Address | Name | Documentation | Notes |
|---|---|---|---|
| `0x004669c0-0x00466a69` | `BaramApp::OnActivate` | [UID:0002GJ][0x004669c0-0x00466a69.BaramAppOnActivate](by-memory/0x004669c0-0x00466a69.BaramAppOnActivate.md) | Resumes event timer/background state, restores map pane/window visibility, and resumes sound/music state when activation is allowed. |
| `0x00466a70-0x00466b23` | `BaramApp::OnDeactivate` | [UID:0002GK][0x00466a70-0x00466b23.BaramAppOnDeactivate](by-memory/0x00466a70-0x00466b23.BaramAppOnDeactivate.md) | Clears active flags, minimizes/hides map UI, pauses event/background work, stops parcel walking, and pauses sound/music state. |
| `0x004f5f20-0x004f5f4e` | raw `BaramApp::BaramApp` body | [UID:0002PZ][0x004f5f20-0x004f5f4e.BaramAppConstructorRaw](by-memory/0x004f5f20-0x004f5f4e.BaramAppConstructorRaw.md) | Unpromoted constructor-shaped body; calls `Application__Constructor` and installs two `BaramApp` vtables. |
| `0x004f5f50-0x004f5faf` | terminal-pane callback factory | [UID:0002Q0][0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory](by-memory/0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory.md) | Startup callback target stored by `Application::Startup`; shows cursor and constructs `TerminalPane`. |
| `0x004f66b5-0x004f66bd` | adjustor thunk | [UID:0002Q1][0x004f66b5-0x004f66bd.BaramAppDeletingDestructorThunk](by-memory/0x004f66b5-0x004f66bd.BaramAppDeletingDestructorThunk.md) | Compiler-generated adjusted-base thunk; should not be hand-authored as normal source logic. |
| `0x004f66c0-0x004f66fb` | scalar deleting destructor | [UID:0002Q2][0x004f66c0-0x004f66fb.BaramAppScalarDeletingDestructor](by-memory/0x004f66c0-0x004f66fb.BaramAppScalarDeletingDestructor.md) | Real IDA function; delegates through application cleanup/destructor paths and delete handling. |

## Child Evidence Matrix

| Child | Score | Evidence status |
| --- | ---: | --- |
| [UID:0002GJ][0x004669c0-0x00466a69.BaramAppOnActivate](by-memory/0x004669c0-0x00466a69.BaramAppOnActivate.md) | `80/90` | Parent-attached activation handler; live IDA confirms exact boundary, virtual-only dispatch, foreground policy, map-window visibility, event/background resume, callee set, state writes, padding, and non-contiguous audio-tail caveat. |
| [UID:0002GK][0x00466a70-0x00466b23.BaramAppOnDeactivate](by-memory/0x00466a70-0x00466b23.BaramAppOnDeactivate.md) | `80/90` | Parent-attached deactivation handler; live IDA confirms exact boundary, virtual-only dispatch, active-state clear, window minimize/hide, event/background/input pause, parcel-walk cleanup, callee set, padding, and non-contiguous audio-tail caveat. |
| [UID:0002PZ][0x004f5f20-0x004f5f4e.BaramAppConstructorRaw](by-memory/0x004f5f20-0x004f5f4e.BaramAppConstructorRaw.md) | `80/88` | Parent-attached raw constructor-shaped body; live IDA confirms exact bytes, `Application` construction forwarding, primary/secondary `BaramApp` vtable writes, no promoted function object, and padding boundaries. |
| [UID:0002Q0][0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory](by-memory/0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory.md) | `80/88` | Parent-attached startup callback target; live IDA confirms the `PlainMemberFunctionObject0<BaramApp>` wrapper store, target slot, captured object pointer, cursor restore, allocation, and terminal-pane construction. |
| [UID:0002Q1][0x004f66b5-0x004f66bd.BaramAppDeletingDestructorThunk](by-memory/0x004f66b5-0x004f66bd.BaramAppDeletingDestructorThunk.md) | `82/90` | Ignored compiler-generated secondary-base adjusted deleting-destructor thunk tied to the secondary vtable slot. |
| [UID:0002Q2][0x004f66c0-0x004f66fb.BaramAppScalarDeletingDestructor](by-memory/0x004f66c0-0x004f66fb.BaramAppScalarDeletingDestructor.md) | `80/90` | Parent-attached scalar deleting destructor; live IDA confirms exact function boundary, no direct callers, primary/secondary vtable reachability, `ApplicationDestructor` delegation, delete-flag branches, project delete call, guard-check branch, and surrounding padding. |
| [UID:00025P][0x0061d118-0x0061d264.BaramAppReadOnlyData](by-memory/0x0061d118-0x0061d264.BaramAppReadOnlyData.md) | `80/90` | Parent-attached generated-binary data; live IDA confirms primary/secondary `BaramApp` vtable slots, `PlainMemberFunctionObject0<BaramApp>` callback vtable slots, startup/update/updater/logo literals, xrefs, and successor-boundary caveat. |

## Source-Structure Decision

Keep `BaramApp` under [UID:0000HG][Application](by-file/Application.md) for now. The activation/deactivation methods are application-shell policy, and the startup/destructor evidence is tightly interleaved with the `Application::Startup` / `Application::Shutdown` cluster. A separate `app/BaramApp.cpp` remains possible, but current evidence does not prove that original source split.

Do not use generated `BaramApp` declarations as final source until the `Application`/`BaramApp` layout resolves the observed state bytes around `this + 2105` and `this + 2106`.

## Behavior Notes

- `OnActivate` first checks the app inactive/transition guard byte, then resumes the event/timer owner, restores map-window visibility with `ShowWindow(..., 9)`, resumes a background worker path, and restarts sound/music if the client is not in a suppressed state.
- `OnDeactivate` clears the active byte, minimizes the map window with `ShowWindow(..., 6)`, pauses the same event/background paths, invokes keyboard/parcel-walk style cleanup helpers, and pauses current audio/music when the client is not in a suppressed state.
- The activation methods are policy glue over already-owned subsystems. Do not move map, keyboard, parcel-walk, sound, or MIDI implementation into `BaramApp` solely because these handlers call those systems.
- The `PlainMemberFunctionObject0<BaramApp>` read-only data indicates at least one source-level member callback registration involving `BaramApp`; the final callback owner/call site should be resolved from the startup/update code before assigning a source helper name.

## Evidence

- This A003 pass relies on live IDA MCP evidence and existing `project-documentation` cross-references only; no Wave2/Wave3 source data was used for the refresh.
- IDA MCP `lookup_funcs` on 2026-05-30 confirms `sub_4669C0` at `0x004669c0` with size `0xa9`, `sub_466A70` at `0x00466a70` with size `0xb3`, `sub_4F66B5` at `0x004f66b5` with size `0x8`, and `sub_4F66C0` at `0x004f66c0` with size `0x3b`.
- IDA MCP `decompile` on 2026-05-30 confirms both activation handlers gate on a `this` flag, call `ShowWindow`, and call the expected map/event/background/audio helper families.
- 2026-06-05 A003 IDA MCP refresh confirms the activation handlers have no direct code callers and are referenced as virtual targets by data slots `0x006125f8`/`0x006125fc` and `0x0061d12c`/`0x0061d130`. The same pass confirms `OnActivate` tail-jumps to the non-contiguous audio chunk at `0x0057a480`, while `OnDeactivate` tail-jumps to `0x0057a450`.
- 2026-06-05 A003 IDA MCP refresh also confirms the startup/destructor cluster: no function at `0x004f5f20`, a constructor-shaped byte body ending at `0x004f5f4e`, `sub_4F5F50` at `0x004f5f50-0x004f5faf`, the pure adjustor thunk at `0x004f66b5-0x004f66bd`, `sub_4F66C0` at `0x004f66c0-0x004f66fb`, and BaramApp vtable/callback data at `0x0061d118`, `0x0061d138`, and `0x0061d238`.
- 2026-06-06 A004 IDA MCP refresh confirms `sub_4F66C0` still has exact range `0x004f66c0-0x004f66fb`, no ordinary direct callers, callees `sub_463970`, `sub_4F4AC0`, and `@_guard_check_icall_nop@4`, vtable reachability from `0x0061d118`, and thunk reachability from `0x004f66b5` / `0x0061d138`.
- 2026-06-06 A004 IDA MCP `.rdata` scan confirms the `BaramApp` primary vtable entries, secondary vtable entries, `PlainMemberFunctionObject0<BaramApp>` callback vtable, title/update/updater/logo string fragments, `_WinMain@16`/`Application::Startup` xrefs, and the `MainMenuPane` successor boundary at `0x0061d260-0x0061d264`.
- 2026-06-06 A004 IDA MCP activation/deactivation refresh confirms `sub_4669C0` at `0x004669c0-0x00466a69` and `sub_466A70` at `0x00466a70-0x00466b23`; both have no ordinary direct callers and are reached through `Application`/`BaramApp` vtable data refs. The same pass confirms `OnActivate` tail-jumps to `0x0057a480`, `OnDeactivate` tail-jumps to `0x0057a450`, and both pages keep those audio chunks documented as cross-range caveats instead of final source helpers.
- IDA MCP reports no function containing `0x004f5f20`, but disassembly proves a complete constructor-shaped body at `0x004f5f20-0x004f5f4e`; the previous function is `_WinMain@16` at `0x004f5c80-0x004f5f17` and the next confirmed function is `0x004f5f50-0x004f5faf`.
- [UID:00025P][0x0061d118-0x0061d264.BaramAppReadOnlyData](by-memory/0x0061d118-0x0061d264.BaramAppReadOnlyData.md) records the `BaramApp` vtables and callback wrapper table in `.rdata`.
- Existing startup aggregate [UID:00019H][0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup](by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md) documents the constructor bytes, terminal callback factory, `Application::Startup`, `Application::Shutdown`, destructor thunk, scalar deleting destructor, and padding boundaries as one app-shell cluster.

## Open Questions

- IDA still needs a function object for `0x004f5f20`, but the bytes are now documented as a real constructor-shaped body rather than padding or a stale projected artifact.
- Decide whether original source kept `BaramApp` in `Application.cpp` or in a small variant file.
- Resolve the final names for the `this + 2105` and `this + 2106` state bytes after the surrounding `Application` layout is fully documented.
- Resolve the exact member callback represented by `PlainMemberFunctionObject0<BaramApp>` at `0x0061d238`.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `84` | The child evidence matrix, application-shell source decision, vtable/read-only-data relationship, parent-attached activation/deactivation handlers, parent-attached raw constructor body, parent-attached startup callback factory, parent-attached scalar deleting destructor, parent-attached read-only data, thunk evidence, and rewrite caveats are documented. Completion remains capped by the unpromoted constructor function object, unresolved activation-handler field names, cross-range audio-tail ownership, and unresolved final source split. |
| Confidence `90` | Exact activation/deactivation pages, parent-attached constructor/callback/destructor/rdata children, startup/destructor cluster evidence, vtable/read-only-data rows, and the `86/90` Application file root agree on application-shell ownership. Confidence remains below final-source confidence because the constructor is still not an IDA function object, activation-handler field names are not finalized, and the original `Application.cpp` versus `BaramApp.cpp` split is still open. |

## Cross-References

- File: [UID:0000HG][Application](by-file/Application.md)
- Related class: [UID:00000D][Application](by-class/Application.md)
- Memory: [UID:0002GJ][0x004669c0-0x00466a69.BaramAppOnActivate](by-memory/0x004669c0-0x00466a69.BaramAppOnActivate.md), [UID:0002GK][0x00466a70-0x00466b23.BaramAppOnDeactivate](by-memory/0x00466a70-0x00466b23.BaramAppOnDeactivate.md), [UID:0000YR][0x00463310-0x004679be.ApplicationLifecycle](by-memory/0x00463310-0x004679be.ApplicationLifecycle.md), [UID:00019H][0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup](by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md), [UID:0002PZ][0x004f5f20-0x004f5f4e.BaramAppConstructorRaw](by-memory/0x004f5f20-0x004f5f4e.BaramAppConstructorRaw.md), [UID:0002Q0][0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory](by-memory/0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory.md), [UID:0002Q1][0x004f66b5-0x004f66bd.BaramAppDeletingDestructorThunk](by-memory/0x004f66b5-0x004f66bd.BaramAppDeletingDestructorThunk.md), [UID:0002Q2][0x004f66c0-0x004f66fb.BaramAppScalarDeletingDestructor](by-memory/0x004f66c0-0x004f66fb.BaramAppScalarDeletingDestructor.md), [UID:00025P][0x0061d118-0x0061d264.BaramAppReadOnlyData](by-memory/0x0061d118-0x0061d264.BaramAppReadOnlyData.md)

## Changes

- 2026-06-06 A004 activation/deactivation child sync:
  - What existed before: [UID:0002GJ][0x004669c0-0x00466a69.BaramAppOnActivate](by-memory/0x004669c0-0x00466a69.BaramAppOnActivate.md) and [UID:0002GK][0x00466a70-0x00466b23.BaramAppOnDeactivate](by-memory/0x00466a70-0x00466b23.BaramAppOnDeactivate.md) were listed as `78/88` and intentionally unassigned.
  - What it was changed to: synced both child rows to `80/90`, raised the class score to `84/90`, and documented that both transition handlers are now parent-attached while final C++ stays blank.
  - Summary/evidence: live IDA MCP reconfirmed exact function bounds, virtual-only data refs, no direct callers, state writes, callee sets, non-contiguous audio-tail jumps, tail audio callees, and adjacent padding for both handlers.
- 2026-06-06 A004 destructor/rdata child sync:
  - What existed before: [UID:0002Q2][0x004f66c0-0x004f66fb.BaramAppScalarDeletingDestructor](by-memory/0x004f66c0-0x004f66fb.BaramAppScalarDeletingDestructor.md) was listed as `76/88` and unassigned, and [UID:00025P][0x0061d118-0x0061d264.BaramAppReadOnlyData](by-memory/0x0061d118-0x0061d264.BaramAppReadOnlyData.md) was listed as `72/86` and unassigned.
  - What it was changed to: synced the child matrix to `80/90` for both pages, raised the class score to `82/88`, and documented that the destructor and read-only data are now parent-attached to this class while final C++ remains blank.
  - Summary/evidence: live IDA MCP reconfirmed the scalar deleting destructor boundary/callees/xrefs/padding and enumerated the `.rdata` vtables, callback table, startup/update literals, xrefs, and successor-boundary caveat.
- 2026-06-06 A004 callback child sync:
  - What existed before: the child matrix listed [UID:0002Q0][0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory](by-memory/0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory.md) as `74/86` and unassigned.
  - What it was changed to: synced the child matrix to `80/88` after the callback page was parent-attached to this class and updated the completion rationale to mention the parent-attached callback factory.
  - Summary/evidence: live IDA MCP on 2026-06-06 reconfirmed the `PlainMemberFunctionObject0<BaramApp>` wrapper construction, target slot at `0x004f63ec`, captured object pointer, exact callback boundary, cursor restore, allocation, and `TerminalPane` constructor call.
- 2026-06-06 A004 constructor child sync:
  - What existed before: the child matrix still listed [UID:0002PZ][0x004f5f20-0x004f5f4e.BaramAppConstructorRaw](by-memory/0x004f5f20-0x004f5f4e.BaramAppConstructorRaw.md) as `72/86` and unpromoted-only evidence.
  - What it was changed to: synced the child matrix to `80/88` after the constructor page was parent-attached to this class and added current byte/call/vtable evidence.
  - Summary/evidence: live IDA MCP on 2026-06-06 reconfirmed the raw constructor bytes, `Application__Constructor` forwarding, paired `BaramApp` vtable writes, no function object at `0x004f5f20`, and exact padding boundaries.
- 2026-06-06 parent attachment update:
  - What existed before: the page was `72/84`, reconstructable, and
    intentionally unassigned because it had not crossed the child-side parent
    gate.
  - What it was changed to: raised to `80/86`, attached to
    [UID:0000HG][Application](by-file/Application.md) at position `20`, synced
    the score rationale, and kept C++ blank under the final-source gate.
  - Summary/evidence: [UID:0000HG][Application](by-file/Application.md) is an
    `86/90` application-shell file root; [UID:00000D][Application](by-class/Application.md)
    is already attached at position `10`; the BaramApp page documents exact
    activation/deactivation pages, raw constructor bytes, startup callback
    factory, vtable/read-only-data evidence, and destructor/thunk coverage while
    keeping unresolved constructor/source-split caveats explicit.
- 2026-06-05 A003 autogen-gate correction:
  - What existed before: the class was scored `72/84` but attached to [UID:0000HG][Application](by-file/Application.md), and its activation-handler child rows still reflected older scores/attachment assumptions.
  - What it was changed to: cleared the class `AUTOGEN_PARENT_UID` and position until completion reaches the documented parent-attachment threshold, updated the activation/deactivation child matrix to `78/88`, cleared stale child autogen parents in the startup/destructor/rdata docs, and reclassified the pure secondary-base deleting-destructor thunk as ignored compiler output.
  - Summary/evidence: the class remains reconstructable and likely belongs in the application shell, but its constructor is still not an IDA function object, source-file split and field names remain open, the activation/callback/destructor/rdata children now avoid invalid autogen attachment, and final layout/global names remain unresolved.
- 2026-06-02 documentation pass:
  - What existed before: the page had method inventory and evidence, but retained a provisional C++ class declaration below the 95+ source-emission threshold.
  - What it was changed to: raised `65/80` to `72/84`, removed the provisional reconstruction block, added child evidence and source-structure tables, and documented why `BaramApp` stays in the application-shell module for now.
  - Summary/evidence: exact activation/deactivation pages, raw constructor/destructor child pages, startup callback evidence, and `.rdata` vtable documentation all support the class role; final source split and field names remain open.
- What existed before: the activation method inventory pointed both exact methods at the broad Application lifecycle aggregate.
- What it was changed to: `OnActivate` and `OnDeactivate` now point at exact split by-memory pages and those pages attach under this class for autogen.
- Summary/evidence: IDA MCP `lookup_funcs` confirms `0x004669c0` size `0xa9` and `0x00466a70` size `0xb3`; IDA MCP disassembly confirms the foreground/background transition behavior.
