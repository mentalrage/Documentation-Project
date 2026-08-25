** TARGET-REPORT-UID:0002GL **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B006 Source-Quality Report: [UID:0002GL] MSGHandlerReadOnlyData

Date: 2026-06-19

Assignment target:

- Primary doc: `source-3/project-documentation/by-memory/0x0061fbf8-0x0061fc04.MSGHandlerReadOnlyData.md`
- Required report: `source-3/project-documentation/tools/leaser/Agents/Agent-B006/research/0002GL-MSGHandlerReadOnlyData-source-quality.md`

This is a report-only B-agent pass. I did not edit the target, support docs, generated output, or `by-memory/-coverage-report.md`.

## Executive Recommendation

The current target is behaviorally well understood but physically mixed. It covers two logical `MSGHandler` vtable entries plus the next class's `MusicControlDialog` complete-object-locator pointer:

- `0x0061fbf8-0x0061fc00`: logical `MSGHandler` vtable data.
- `0x0061fc00-0x0061fc04`: `MusicControlDialog` `vftable[-1]` RTTI locator pointer.

Recommended implementation after supervisor acceptance:

1. Rename/narrow [UID:0002GL] to `by-memory/0x0061fbf8-0x0061fc00.MSGHandlerVtableData.md`.
2. Create a new exact child `by-memory/0x0061fc00-0x0061fc04.MusicControlDialogRttiLocatorPointer.md` with a new UID assigned by the validator workflow.
3. Keep both C++ blocks blank. Both ranges are source-declared/generated-binary data regenerated from class declarations, not hand-authored source bytes.

Recommended [UID:0002GL] metadata after the split:

```yaml
COMPLETION:88
CONFIDENCE:92
CANONICAL_OWNER:00008S
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00008S
```

Recommended new `MusicControlDialogRttiLocatorPointer` metadata:

```yaml
COMPLETION:86
CONFIDENCE:91
CANONICAL_OWNER:00008U
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00008U
```

If the supervisor chooses not to split this pass, the current `0x0061fbf8-0x0061fc04.MSGHandlerReadOnlyData.md` page can still be raised to `86/91` with the existing boundary caveat. That is a valid minimal cleanup, but it leaves `0x0061fc00` routed through `MSGHandler` even though project precedent now splits successor RTTI locator pointers.

## Evidence Checked

Instructions and project rules:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B006/goal.md`
- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/inference_research.md`
- `source-3/project-documentation/by-project-structure/proposed-source-tree.md`

Target and direct support docs:

- `by-memory/0x0061fbf8-0x0061fc04.MSGHandlerReadOnlyData.md`
- `by-memory/0x00528d60-0x00528e55.MSGHandler.md`
- `by-class/MSGHandler.md`
- `by-file/MSGHandler.md`
- `by-memory/0x00465650-0x00465686.ApplicationExchangeMSGHandler.md`
- `by-memory/0x00464cd0-0x00464e1f.ApplicationRunMessageLoop.md`
- `by-class/Application.md`
- `by-file/Application.md`
- `by-memory/0x00528de0-0x00528dec.BrowserControlPaneOldDispatch.md`
- `by-memory/0x0061fb74-0x0061fc04.WorkThreadNotificationReadOnlyData.md`
- `by-memory/0x0061fc04-0x0061fd04.MusicControlDialogReadOnlyData.md`
- `by-class/MusicControlDialog.md`
- `by-file/MusicControlDialog.md`
- `by-memory/-coverage-report.md`

Related reports and generated state:

- B009 pending report `Agent-B009/research/0001CN-MSGHandler-source-quality.md`
- B008 executed report `0002JY-0002GR-ApplicationAccessorsAndExchangeMsgHandler-source-quality.md`
- B001 executed report `0001CO-browsercontrolpaneold-dispatch-range-audit.md`
- B002 executed report `0002H0-0002JV-application-lifecycle-source-quality.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-class-coverage.md`
- `auto-generated/NexusTK/app/MSGHandler.cpp`
- `auto-generated/NexusTK/app/Application.cpp`
- `auto-generated/NexusTK/ui/dialogs/MusicControlDialog.cpp`

Local exported function records:

- `resources/exported_data/functions/0x00528d60.json`
- `resources/exported_data/functions/0x00528d80.json`
- `resources/exported_data/functions/0x00528dd0.json`
- `resources/exported_data/functions/0x00528df0.json`
- `resources/exported_data/functions/0x00464cd0.json`

I attempted to query the live MCP endpoint at `http://127.0.0.1:13337/mcp`; it was unavailable with `Unable to connect to the remote server`. This report relies on current project docs, prior recorded live-IDA evidence, current generated coverage, and local exported function JSON.

Number conversions checked with `source-3/project-documentation/tools/int_convert.py`:

- `0x0c` = 12 decimal bytes.
- `0x65` = 101 decimal bytes.
- `0x4` = 4 decimal bytes.
- `0x8` = 8 decimal bytes.

## Current Target Facts

| Range | Value / symbol | Classification | Source-quality meaning |
| --- | --- | --- | --- |
| `0x0061fbf4-0x0061fbf8` | `0x0064c5fc -> ??_R4MSGHandler@@6B@` | preceding RTTI locator pointer, outside target | Confirms the `MSGHandler` vtable start context. |
| `0x0061fbf8-0x0061fbfc` | `0x00528df0 -> sub_528DF0` | `MSGHandler` vtable slot 0 | MSVC scalar deleting destructor generated from `virtual ~MSGHandler()`. |
| `0x0061fbfc-0x0061fc00` | `0x00528dd0 -> sub_528DD0` | `MSGHandler` vtable slot 1 | Generic `MSGHandler::DispatchMessage(MSG*)` forwarder. |
| `0x0061fc00-0x0061fc04` | `0x0064c65c -> ??_R4MusicControlDialog@@6B@` | successor RTTI locator pointer | `MusicControlDialog` `vftable[-1]`, not a third `MSGHandler` slot. |
| `0x0061fc04` | `??_7MusicControlDialog@@6B@` | successor vtable base | Exclusive end of the current physical target range. |

Raw target bytes are `f0 8d 52 00 d0 8d 52 00 5c c6 64 00`, decoded as `0x00528df0`, `0x00528dd0`, and `0x0064c65c`.

Recorded IDA evidence in the target/support docs:

- `0x0061fbf8` is named `??_7MSGHandler@@6B@`.
- Xrefs to `0x0061fbf8` come from `0x00528d64`, `0x00528da5`, and `0x00528e18`, matching constructor/destructor/scalar-deleting-destructor vtable writes.
- No direct xrefs are recorded to `0x0061fbfc` or `0x0061fc00`.
- `0x0061fc04` is named `??_7MusicControlDialog@@6B@`, with successor vtable refs from `0x00528eae`, `0x00529770`, and `0x0052a4e6`.

Local exported function evidence:

- `0x00528dd0` has a 12-byte body and one IDA data xref from `0x0061fbfc`.
- `0x00528df0` has a 101-byte body, one IDA data xref from `0x0061fbf8`, calls `0x00465650` and `0x005c7526`, and matches scalar deleting destructor behavior.
- `ApplicationRunMessageLoop` reads `Application+0x844` and calls vtable slot `+4` as `(*(void (__thiscall **)(int, MSG *))(*(_DWORD *)v5 + 4))(v5, &Msg);`, proving the virtual dispatch argument is `MSG*`.

## Heuristic / Inference Reanalysis And Validation

### 1. Generated Data Versus Source-Authored Code

The target range should not receive hand-written C++ bytes. The source-authored parts are the `MSGHandler` class declaration and methods in [UID:0001CN], plus the `MusicControlDialog` declaration for the successor RTTI locator. The vtable entries and complete-object-locator pointers are compiler output.

Target-specific no-code proof:

- `0x0061fbf8` is a vtable entry for a compiler-generated scalar deleting destructor. The source cause is `virtual ~MSGHandler();`.
- `0x0061fbfc` is a vtable entry for source-authored `MSGHandler::DispatchMessage(MSG*)`, but the entry itself is generated table data.
- `0x0061fc00` is the `MusicControlDialog` RTTI locator pointer at `vftable[-1]`; it is generated from `MusicControlDialog`, not `MSGHandler`.

### 2. Split Policy

Recommended split is stronger than the current physical page. Existing project practice already splits successor-owner `RttiLocatorPointer` cells out of predecessor aggregates:

- [UID:0003PF] `0x0061faf8-0x0061fafc.MidiPlayerRttiLocatorPointer`
- [UID:0003P6] `0x0061d260-0x0061d264.MainMenuPaneRttiLocatorPointer`
- [UID:0003PA] `0x0061a458-0x0061a45c.FolderSelectDialogRttiLocatorPointer`
- [UID:0003GS] `0x0062da0c-0x0062da10.TerminalPaneRttiLocatorPointer`

The current [UID:0002GL] shape is the same boundary pattern: a predecessor class's vtable body followed by a successor class's `vftable[-1]` locator pointer. Leaving the final dword in `MSGHandler` is understandable as a physical historical split, but it is not the best final source-quality ownership route.

Rejected split alternatives:

- Keep `0x0061fc00` as a `MSGHandler` third slot: rejected because the value points to `??_R4MusicControlDialog@@6B@`, no code/data evidence routes it to `MSGHandler`, and the next named vtable starts at `0x0061fc04`.
- Mark the whole current page `CANONICAL_OWNER:NONE`: rejected because the logical two-slot `MSGHandler` range is exact and has a strong owner/emitter route.
- Extend `MusicControlDialogReadOnlyData` backward to `0x0061fc00`: plausible, but less consistent with current exact `RttiLocatorPointer` child precedent. A four-byte exact child gives cleaner coverage and keeps [UID:00025Y] stable.
- Merge with [UID:00025X] `WorkThreadNotificationReadOnlyData`: rejected because that parent is deliberately mixed and non-source-specific.

### 3. Vtable Slot Names And Signatures

Best-supported names:

- `sub_528DF0`: `MSGHandler` scalar deleting destructor, compiler-generated. Do not model as an ordinary source method. The ordinary destructor is `0x00528d80`.
- `sub_528DD0`: `MSGHandler::DispatchMessage(MSG* message)`. `LRESULT` is preferred if the reconstructed environment has Win32 typedefs; `int` is an acceptable 32-bit fallback.
- `MSGHandler+0x4`: `MSGHandler* m_previousHandler`.

Reasoning for `DispatchMessage(MSG*)`:

- The tiny forwarder decompiler view drops the stack argument, but it forwards to saved target vtable slot `+4`.
- `ApplicationRunMessageLoop` dispatches queued Win32 `MSG` objects through `Application+0x844` slot `+4` with `&Msg`.
- Current docs and B009's source-quality report already converge on `DispatchMessage`.

Rejected names:

- `HandleMessage` / `OnMessage`: plausible generic UI names, but less supported than `DispatchMessage`, which matches the Application message-loop operation and current documentation.
- `DispatchToBrowser`: rejected for generic `MSGHandler`; B001 proved the Browser object pointer is separate, and `0x00528de0` is the BrowserControlPaneOld bridge, not the generic vtable slot.
- `m_handlerTarget`: behaviorally possible, but weaker than `m_previousHandler` because `Application::ExchangeMSGHandler` returns the previous active handler and the destructor restores it.
- `m_browserObject`: rejected for generic `MSGHandler`; Browser object state is a separate BrowserControlPaneOld field.

### 4. Owner / Emitter / Source Placement

For the logical `MSGHandler` vtable:

- Canonical owner: [UID:00008S] `MSGHandler`
- Emitter: [UID:00008S] through [UID:0000LM] `NexusTK/app/MSGHandler.cpp`
- Source route: small Application-adjacent helper class with a declaration visible to `Application` and `BrowserControlPaneOld`

For the `0x0061fc00` boundary locator:

- Canonical owner: [UID:00008U] `MusicControlDialog`
- Emitter: [UID:00008U] through [UID:0000LN] `NexusTK/ui/dialogs/MusicControlDialog.cpp`
- Source route: generated RTTI support data from the `MusicControlDialog` class declaration

Rejected owners:

- `Application`: owns `Application+0x844` and [UID:0002GR] `Application::ExchangeMSGHandler`, but not the `MSGHandler` vtable bytes.
- `BrowserControlPaneOld`: owns `0x00528de0` fallback bridge and old-browser override/subobject behavior, but not the generic `MSGHandler` vtable at `0x0061fbf8`.
- `MusicControlDialog` for the entire current target: owns only `0x0061fc00-0x0061fc04`, not the two preceding `MSGHandler` slots.

### 5. First-Draft C++ Readiness

Target-specific C++ recommendation: keep [UID:0002GL] blank. If split, keep both [UID:0002GL] and the new `MusicControlDialogRttiLocatorPointer` C++ blocks blank.

Support-level class declaration recommended for [UID:00008S] and [UID:0001CN] after supervisor acceptance of the related B009 report:

```cpp
class MSGHandler
{
public:
    MSGHandler();
    virtual ~MSGHandler();

    virtual LRESULT DispatchMessage(MSG* message);

private:
    MSGHandler* m_previousHandler;
};
```

If `LRESULT` is unavailable in the generated source environment, use `int` for the return type and retain a type-normalization note:

```cpp
virtual int DispatchMessage(MSG* message);
```

Support-level method bodies from B009 are first-draft ready for [UID:0001CN], not for this read-only-data target:

```cpp
MSGHandler::MSGHandler()
    : m_previousHandler(g_pApplication->ExchangeMSGHandler(this))
{
}

MSGHandler::~MSGHandler()
{
    g_pApplication->ExchangeMSGHandler(m_previousHandler);
}

LRESULT MSGHandler::DispatchMessage(MSG* message)
{
    return m_previousHandler->DispatchMessage(message);
}
```

## Recommended Target Changes

### Preferred Split Implementation

Rename/narrow [UID:0002GL]:

- Old path: `by-memory/0x0061fbf8-0x0061fc04.MSGHandlerReadOnlyData.md`
- New path: `by-memory/0x0061fbf8-0x0061fc00.MSGHandlerVtableData.md`
- Header: `# 0x0061fbf8-0x0061fc00 MSGHandler Vtable Data`
- Address range: `0x0061fbf8-0x0061fc00`
- Entity kind: `vtable-data`
- Disposition: `source-declared/generated-binary`
- Rebuild handling: generated from the `MSGHandler` class declaration and virtual method set
- Metadata: `88/92`, owner/emitter [UID:00008S], reconstructable true, C++ blank

Suggested summary text:

```text
This exact child covers the two logical `MSGHandler` vtable slots at `0x0061fbf8-0x0061fc00`. The former physical target range included the successor `MusicControlDialog` RTTI locator pointer at `0x0061fc00`; that dword should be split into `0x0061fc00-0x0061fc04.MusicControlDialogRttiLocatorPointer.md` and routed through [UID:00008U][MusicControlDialog](by-class/MusicControlDialog.md).
```

Suggested observed contents:

```markdown
| Range | Current IDA item/value | Notes |
| --- | --- | --- |
| `0x0061fbf4-0x0061fbf8` | `0x0064c5fc -> ??_R4MSGHandler@@6B@` | Preceding `MSGHandler` complete-object-locator pointer, outside this exact child but confirms the vtable start context. |
| `0x0061fbf8-0x0061fbfc` | `0x00528df0 -> sub_528DF0` | `MSGHandler` scalar deleting destructor slot generated from `virtual ~MSGHandler()`. |
| `0x0061fbfc-0x0061fc00` | `0x00528dd0 -> sub_528DD0` | `MSGHandler::DispatchMessage(MSG*)` virtual forwarder slot. |
| `0x0061fc00-0x0061fc04` | `0x0064c65c -> ??_R4MusicControlDialog@@6B@` | Successor `MusicControlDialog` RTTI locator pointer, split out and not part of the logical `MSGHandler` vtable child. |
```

Suggested no-code note:

```text
Do not hand-port these dwords. Rebuild them from the `MSGHandler` declaration: `virtual ~MSGHandler()` produces the scalar deleting destructor slot, and `virtual DispatchMessage(MSG*)` produces the dispatch slot. The executable method bodies belong to [UID:0001CN]; this page remains blank because it documents generated table data.
```

### New `MusicControlDialogRttiLocatorPointer` Child

Create a new exact child after supervisor acceptance:

- Path: `by-memory/0x0061fc00-0x0061fc04.MusicControlDialogRttiLocatorPointer.md`
- Header: `# 0x0061fc00-0x0061fc04 MusicControlDialog RTTI Locator Pointer`
- Address range: `0x0061fc00-0x0061fc04`
- Entity kind: `RTTI locator pointer`
- Disposition: `source-declared/generated-binary`
- Metadata: `86/91`, owner/emitter [UID:00008U], reconstructable true, C++ blank

Suggested summary:

```text
This four-byte child is the primary `MusicControlDialog` complete-object-locator pointer at `vftable[-1]`, immediately before the `MusicControlDialog` primary vtable base at `0x0061fc04`. It was formerly carried as the final boundary dword in [UID:0002GL][MSGHandlerReadOnlyData], but source ownership belongs to [UID:00008U][MusicControlDialog](by-class/MusicControlDialog.md).
```

Suggested evidence:

```markdown
- Existing target evidence records raw value `0x0061fc00 -> 0x0064c65c`.
- Existing target and parent evidence identify `0x0064c65c` as `??_R4MusicControlDialog@@6B@`.
- Existing target evidence records no direct xrefs to `0x0061fc00`, which is expected for a `vftable[-1]` locator pointer.
- [UID:00025Y][0x0061fc04-0x0061fd04.MusicControlDialogReadOnlyData](by-memory/0x0061fc04-0x0061fd04.MusicControlDialogReadOnlyData.md) starts at the following `MusicControlDialog` vtable base.
- Existing target evidence records `0x0061fc04` vtable refs from `0x00528eae`, `0x00529770`, and `0x0052a4e6`.
```

Suggested reconstruction note:

```text
Do not emit this pointer as hand-written source. The compiler regenerates the `vftable[-1]` RTTI locator from the `MusicControlDialog` class declaration and RTTI/vtable settings.
```

### Fallback No-Split Target Update

If no split is accepted, keep current path and update metadata to `86/91` with final C++ blank. Replace stale gate text with:

```text
The current physical range intentionally straddles a source ownership boundary. The logical `MSGHandler` data is only `0x0061fbf8-0x0061fc00`; `0x0061fc00-0x0061fc04` is the adjacent `MusicControlDialog` RTTI locator pointer. This page remains no-code because both the vtable slots and RTTI locator are compiler-generated from class declarations.
```

## Recommended Support-Doc Changes

### `by-memory/0x0061fb74-0x0061fc04.WorkThreadNotificationReadOnlyData.md`

- Replace the child row for `0x0061fbf8-0x0061fc04` with two rows:
  - [UID:0002GL] `0x0061fbf8-0x0061fc00.MSGHandlerVtableData`
  - new `0x0061fc00-0x0061fc04.MusicControlDialogRttiLocatorPointer`
- Keep the parent non-emitting/mixed-owner classification.
- Update the reconstruction note that previously described [UID:0002GL] as intentionally straddling the boundary.

### `by-memory/0x0061fc04-0x0061fd04.MusicControlDialogReadOnlyData.md`

- Change the predecessor/boundary wording to reference the new `0x0061fc00-0x0061fc04.MusicControlDialogRttiLocatorPointer.md` child.
- Keep the page's own range starting at `0x0061fc04`; do not extend it backward if the new exact child is created.

### `by-class/MSGHandler.md`

- Change read-only data reference from `0x0061fbf8-0x0061fc04` to `0x0061fbf8-0x0061fc00`.
- State vtable slots:
  - slot 0: scalar deleting destructor generated from `virtual ~MSGHandler()`
  - slot 1: `DispatchMessage(MSG*)`
- Add or align with B009's class declaration and field name `MSGHandler* m_previousHandler` at object slot `+0x4`.
- Recommended support score after accepted B009 and this split: `88/90`.

### `by-file/MSGHandler.md`

- Change read-only data range to `0x0061fbf8-0x0061fc00`.
- State that `NexusTK/app/MSGHandler.cpp` is the current reconstruction route for the helper class, with a declaration/header visible to `Application` and `BrowserControlPaneOld`.
- Remove wording that treats the adjacent `MusicControlDialog` locator as part of MSGHandler-owned read-only data.
- Recommended support score after accepted B009 and this split: `88/89`.

### `by-memory/0x00528d60-0x00528e55.MSGHandler.md`

- Update vtable-data cross-reference to the narrowed [UID:0002GL] path.
- Keep B009's recommendation that the constructor, ordinary destructor, and `DispatchMessage(MSG*)` are first-draft source-ready.
- Keep `0x00528df0` scalar deleting destructor no-code/generated.

### `by-class/MusicControlDialog.md` and `by-file/MusicControlDialog.md`

- Add cross-reference to the new `0x0061fc00-0x0061fc04.MusicControlDialogRttiLocatorPointer.md` as the primary RTTI locator pointer before the existing `0x0061fc04` vtable data.
- No score change is required from this split alone.

### Generated Coverage Expectations

After accepted implementation and validator/autogen refresh:

- [UID:0002GL] should route to `auto-generated/NexusTK/app/MSGHandler.cpp`, no code.
- The new `MusicControlDialogRttiLocatorPointer` child should route to `auto-generated/NexusTK/ui/dialogs/MusicControlDialog.cpp`, no code.
- The current `auto-generated/-ag-memory-coverage.md` row that routes the full `0x0061fbf8-0x0061fc04` range through `MSGHandler` should disappear after the split.

## Exact Pending Coverage Text

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` in the B pass.

Preferred split replacement for the current [UID:0002GL] row:

```text
        - [UID:0002GL][0x0061fbf8-0x0061fc00.MSGHandlerVtableData](by-memory/0x0061fbf8-0x0061fc00.MSGHandlerVtableData.md) 0x0061fbf8-0x0061fc00 | vtable-data | MSGHandlerVtableData : reconstructable : 88% : strong : B006 2026-06-19 source-quality pass narrows the former physical MSGHandlerReadOnlyData range to the two logical `MSGHandler` slots: `0x0061fbf8 -> 0x00528df0` MSVC scalar deleting destructor generated from `virtual ~MSGHandler()` and `0x0061fbfc -> 0x00528dd0` `MSGHandler::DispatchMessage(MSG*)` forwarder; vtable writes from `0x00528d64`, `0x00528da5`, and `0x00528e18` tie the slots to the MSGHandler constructor/destructor/scalar wrapper; the successor `0x0061fc00` MusicControlDialog RTTI locator pointer is split out, and final C++ stays blank because the table is source-declared/generated-binary output from the class declaration.
        - [UID:<NEW_UID>][0x0061fc00-0x0061fc04.MusicControlDialogRttiLocatorPointer](by-memory/0x0061fc00-0x0061fc04.MusicControlDialogRttiLocatorPointer.md) 0x0061fc00-0x0061fc04 | rtti-locator-pointer | MusicControlDialogRttiLocatorPointer : reconstructable : 86% : strong : B006 2026-06-19 source-quality pass splits the boundary dword formerly carried by [UID:0002GL]; raw value `0x0064c65c` points to `??_R4MusicControlDialog@@6B@`, no direct xrefs to the cell are expected for `vftable[-1]` RTTI data, and the successor vtable at `0x0061fc04` has constructor/destructor refs from `0x00528eae`, `0x00529770`, and `0x0052a4e6`. Owner/emitter route to [UID:00008U] `MusicControlDialog`; final C++ stays blank because this is compiler-emitted RTTI support data from the class declaration.
```

Replace `<NEW_UID>` with the validator-assigned UID for the new `MusicControlDialogRttiLocatorPointer` page.

Fallback no-split replacement if the supervisor keeps the physical target page:

```text
        - [UID:0002GL][0x0061fbf8-0x0061fc04.MSGHandlerReadOnlyData](by-memory/0x0061fbf8-0x0061fc04.MSGHandlerReadOnlyData.md) 0x0061fbf8-0x0061fc04 | vtable/generated-binary-data | MSGHandlerReadOnlyData : reconstructable : 86% : strong : B006 2026-06-19 source-quality pass confirms this physical child straddles a logical ownership boundary: `0x0061fbf8 -> 0x00528df0` is the `MSGHandler` scalar deleting destructor slot generated from `virtual ~MSGHandler()`, `0x0061fbfc -> 0x00528dd0` is the `MSGHandler::DispatchMessage(MSG*)` forwarder slot, and `0x0061fc00 -> 0x0064c65c` is adjacent `MusicControlDialog` RTTI locator data rather than a third MSGHandler slot; vtable writes from `0x00528d64/0x00528da5/0x00528e18` tie only the first two slots to MSGHandler, and final C++ stays blank because the bytes are regenerated from class declarations.
```

## IDA Rename / Type / Comment Recommendations

| Item | Recommendation | Confidence | Notes |
| --- | --- | ---: | --- |
| `sub_528DD0` | Rename/type as `MSGHandler::DispatchMessage(MSG* message)`, return `LRESULT` preferred or `int` fallback | High | Application loop passes `MSG*` through slot `+4`; target vtable xref is `0x0061fbfc`. |
| `sub_528DF0` | Comment/name as `MSGHandler` scalar deleting destructor, optional compiler label `MSGHandler::scalar_deleting_destructor` | High for role, medium for exact decorated spelling | Do not model as ordinary source method; ordinary destructor is `0x00528d80`. |
| `0x0061fbf8` | Keep/name as `MSGHandler::vftable` with two logical slots in [UID:0002GL] after split | High | Constructor/destructor/scalar wrapper write refs prove the route. |
| `MSGHandler+0x4` | Type/name as `MSGHandler* m_previousHandler` | High | Constructor stores `Application::ExchangeMSGHandler(this)` return; destructor restores it. |
| `Application+0x844` | Keep/type as `MSGHandler* m_activeMessageHandler` | High | B008/B002 evidence and current `ApplicationExchangeMSGHandler` doc support this. |
| `0x0061fc00` | Split/name as `MusicControlDialogRttiLocatorPointer`, `dd offset ??_R4MusicControlDialog@@6B@` | High | Boundary value and successor vtable identity are already recorded. |
| `0x0061fc04` | Keep as `MusicControlDialog::vftable` successor, not part of [UID:0002GL] | High | Constructor/destructor refs route to `MusicControlDialog`. |

## Open Questions With Attempted Resolution

| Question | Attempted resolution | Status |
| --- | --- | --- |
| Was original `MSGHandler` text in `Application.cpp` or a separate `MSGHandler.cpp`? | Checked Application, MSGHandler, proposed tree, and B009. BrowserControlPaneOld also constructs/uses a MSGHandler subobject, so a reconstruction-visible helper declaration/module is needed. | Use `NexusTK/app/MSGHandler.cpp` route; historical textual placement remains nonblocking. |
| Is slot 1 `DispatchMessage`, `HandleMessage`, or `OnMessage`? | Checked ApplicationRunMessageLoop and current support docs. The call dispatches Win32 `MSG*` through the active handler slot. | Use `DispatchMessage(MSG*)`; note `LRESULT` vs `int` typedef caveat. |
| Does `0x0061fc00` need a split? | Compared with existing `RttiLocatorPointer` exact children and current boundary evidence. | Yes, recommended split. Fallback no-split cleanup is provided. |
| Is `0x00528df0` source-authored C++? | Checked local export and target docs. It repeats destructor restore and conditionally frees based on delete flags. | No. It is compiler-generated scalar deleting destructor glue. |
| Are direct xrefs required for `0x0061fc00`? | Checked existing target evidence and exact RTTI locator pointer precedent. | No. Lack of direct xrefs is expected for a `vftable[-1]` locator pointer cell. |

## Validation Commands Needed After Accepted Implementation

Preferred split validation:

> Executable block R001 was removed from this report and preserved verbatim in [0002GL-MSGHandlerReadOnlyData-source-quality-removed.md](0002GL-MSGHandlerReadOnlyData-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Fallback no-split validation:

> Executable block R002 was removed from this report and preserved verbatim in [0002GL-MSGHandlerReadOnlyData-source-quality-removed.md](0002GL-MSGHandlerReadOnlyData-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Implementation Readiness

Ready for supervisor review.

Preferred implementation should be a coordinated split, not a single-page score bump. The exact source behavior and ownership are understood well enough to raise confidence, but no C++ should be emitted directly by this read-only-data target. The source-bearing C++ belongs to [UID:0001CN]/[UID:00008S] `MSGHandler`, while [UID:0002GL] and the proposed `MusicControlDialogRttiLocatorPointer` page remain generated-binary no-code documentation.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0002GL-MSGHandlerReadOnlyData-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"0002GL"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002GL-MSGHandlerReadOnlyData-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/0002GL-MSGHandlerReadOnlyData-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002GL"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
