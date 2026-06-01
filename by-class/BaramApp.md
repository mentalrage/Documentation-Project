*** UID:00000V | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:65 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class BaramApp : public Application
{
public:
    BaramApp();
    virtual ~BaramApp();

    virtual void OnActivate();
    virtual void OnDeactivate();
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BaramApp

## Summary

`BaramApp` is the game-client specialization of [UID:00000D][Application](by-class/Application.md). It does not appear to own broad startup/shutdown policy; its confirmed behavior is the foreground/background transition policy for the live client: event timer state, map-pane window visibility, background processing, keyboard restore, parcel-walk cancellation, and sound/music pause/resume.

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

## Behavior Notes

- `OnActivate` first checks the app inactive/transition guard byte, then resumes the event/timer owner, restores map-window visibility with `ShowWindow(..., 9)`, resumes a background worker path, and restarts sound/music if the client is not in a suppressed state.
- `OnDeactivate` clears the active byte, minimizes the map window with `ShowWindow(..., 6)`, pauses the same event/background paths, invokes keyboard/parcel-walk style cleanup helpers, and pauses current audio/music when the client is not in a suppressed state.
- The activation methods are policy glue over already-owned subsystems. Do not move map, keyboard, parcel-walk, sound, or MIDI implementation into `BaramApp` solely because these handlers call those systems.
- The `PlainMemberFunctionObject0<BaramApp>` read-only data indicates at least one source-level member callback registration involving `BaramApp`; the final callback owner/call site should be resolved from the startup/update code before assigning a source helper name.

## Evidence

- Wave3 reports five methods, one disabled or thunk-like method, and globals shared with application, audio, and map state; use this as a lead because the constructor range conflicts with IDA.
- IDA MCP `lookup_funcs` on 2026-05-30 confirms `sub_4669C0` at `0x004669c0` with size `0xa9`, `sub_466A70` at `0x00466a70` with size `0xb3`, `sub_4F66B5` at `0x004f66b5` with size `0x8`, and `sub_4F66C0` at `0x004f66c0` with size `0x3b`.
- IDA MCP `decompile` on 2026-05-30 confirms both activation handlers gate on a `this` flag, call `ShowWindow`, and call the expected map/event/background/audio helper families.
- IDA MCP reports no function containing `0x004f5f20`, but disassembly proves a complete constructor-shaped body at `0x004f5f20-0x004f5f4e`; the previous function is `_WinMain@16` at `0x004f5c80-0x004f5f17` and the next confirmed function is `0x004f5f50-0x004f5faf`.
- [UID:00025P][0x0061d118-0x0061d264.BaramAppReadOnlyData](by-memory/0x0061d118-0x0061d264.BaramAppReadOnlyData.md) records the `BaramApp` vtables and callback wrapper table in `.rdata`.

## Open Questions

- IDA still needs a function object for `0x004f5f20`, but the bytes are now documented as a real constructor-shaped body rather than padding or pure Wave3 artifact.
- Decide whether original source kept `BaramApp` in `Application.cpp` or in a small variant file.
- Resolve the final names for the `this + 2105` and `this + 2106` state bytes after the surrounding `Application` layout is fully documented.
- Resolve the exact member callback represented by `PlainMemberFunctionObject0<BaramApp>` at `0x0061d238`.

## Cross-References

- File: [UID:0000HG][Application](by-file/Application.md)
- Related class: [UID:00000D][Application](by-class/Application.md)
- Memory: [UID:0002GJ][0x004669c0-0x00466a69.BaramAppOnActivate](by-memory/0x004669c0-0x00466a69.BaramAppOnActivate.md), [UID:0002GK][0x00466a70-0x00466b23.BaramAppOnDeactivate](by-memory/0x00466a70-0x00466b23.BaramAppOnDeactivate.md), [UID:0000YR][0x00463310-0x004679be.ApplicationLifecycle](by-memory/0x00463310-0x004679be.ApplicationLifecycle.md), [UID:00019H][0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup](by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md), [UID:0002PZ][0x004f5f20-0x004f5f4e.BaramAppConstructorRaw](by-memory/0x004f5f20-0x004f5f4e.BaramAppConstructorRaw.md), [UID:0002Q0][0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory](by-memory/0x004f5f50-0x004f5faf.BaramAppTerminalPaneCallbackFactory.md), [UID:0002Q1][0x004f66b5-0x004f66bd.BaramAppDeletingDestructorThunk](by-memory/0x004f66b5-0x004f66bd.BaramAppDeletingDestructorThunk.md), [UID:0002Q2][0x004f66c0-0x004f66fb.BaramAppScalarDeletingDestructor](by-memory/0x004f66c0-0x004f66fb.BaramAppScalarDeletingDestructor.md), [UID:00025P][0x0061d118-0x0061d264.BaramAppReadOnlyData](by-memory/0x0061d118-0x0061d264.BaramAppReadOnlyData.md)

## Changes

- What existed before: the activation method inventory pointed both exact methods at the broad Application lifecycle aggregate.
- What it was changed to: `OnActivate` and `OnDeactivate` now point at exact split by-memory pages and those pages attach under this class for autogen.
- Summary/evidence: IDA MCP `lookup_funcs` confirms `0x004669c0` size `0xa9` and `0x00466a70` size `0xb3`; IDA MCP disassembly confirms the foreground/background transition behavior.
