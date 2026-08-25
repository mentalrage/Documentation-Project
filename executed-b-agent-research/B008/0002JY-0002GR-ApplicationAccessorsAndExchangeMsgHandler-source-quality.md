** TARGET-REPORT-UID:0002JY **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B008 Source-Quality Report

Assignment: [UID:0002JY] `ApplicationCopyProcessorName` and [UID:0002GR] `ApplicationExchangeMSGHandler`

Targets:
- `by-memory/0x004652e0-0x004652fc.ApplicationCopyProcessorName.md`
- `by-memory/0x00465650-0x00465686.ApplicationExchangeMSGHandler.md`

Report scope: B-preferred source-quality and heuristic/inference pass from refreshed completion stats. This report does not directly edit target docs or `by-memory/-coverage-report.md`.

## Supervisor Active Recheck

- Current active code gate from `Supervisor.md`: `RECONSTRUCTABLE:TRUE`, confirmed nonblank `EMITTER_UIDS` that route to source, and `(completion + confidence) / 2 > 85`.
- Both target functions are reconstructable and route through emitter `00000D` / `Application`.
- Both current averages are `87.0` in `project-level/-auto-completion-stats.md`; therefore both already clear the active gate. The old "no code until 90/95" language in the target docs is stale.
- Direct `by-memory/-coverage-report.md` edits remain temporarily banned. Exact replacement rows are provided below.
- I did not acquire a lease because this is a new report inside `tools/leaser/Agents/Agent-B008/research`, which the goal file allows without a lease.

## Evidence Sources Checked

- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Agent-B008/goal.md`
- `project-documentation/by-memory/0x004652e0-0x004652fc.ApplicationCopyProcessorName.md`
- `project-documentation/by-memory/0x00465650-0x00465686.ApplicationExchangeMSGHandler.md`
- `project-documentation/by-class/Application.md`
- `project-documentation/by-file/Application.md`
- `project-documentation/by-memory/0x00463310-0x0046396e.ApplicationConstructor.md`
- `project-documentation/by-memory/0x00465130-0x004651b8.ApplicationReadProcessorName.md`
- `project-documentation/by-memory/0x00465b70-0x00465b86.ApplicationCopyWorldName.md`
- `project-documentation/by-memory/0x00465b90-0x00465ba6.ApplicationCopyPlayerName.md`
- `project-documentation/by-class/MainMenuPane.md`
- `project-documentation/by-file/MainMenuPane.md`
- `project-documentation/by-memory/0x004f6700-0x004f7d10.MainMenuPaneCore.md`
- `project-documentation/by-memory/0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md`
- `project-documentation/by-memory/0x00528d60-0x00528e55.MSGHandler.md`
- `project-documentation/by-class/MSGHandler.md`
- `project-documentation/by-file/MSGHandler.md`
- `project-documentation/by-memory/0x00464cd0-0x00464e1f.ApplicationRunMessageLoop.md`
- `project-documentation/by-memory/0x0067a998-0x0067a9c0.ApplicationErrorAndCriticalSectionStatics.md`
- `project-documentation/by-memory/0x0049bcf0-0x0049bd19.CriticalSectionLock.md`
- `project-documentation/project-level/-auto-completion-stats.md`
- `project-documentation/auto-generated/-ag-memory-coverage.md`
- `project-documentation/by-memory/-coverage-report.md`
- Local IDA/Ghidra export cache: `resources/exported_data/functions/0x00463310.json`, `0x004652e0.json`, `0x00465650.json`, `0x004f6d80.json`

Live IDA MCP was attempted at `127.0.0.1:13337/mcp` and was unavailable. The report therefore uses existing project documentation plus local IDA/Ghidra export JSON as IDA-derived corroboration, and does not claim a fresh live MCP recheck.

## Summary Recommendation

### UID 0002JY

Current name `ApplicationCopyProcessorName` is wrong for the actual field. The function should be renamed/reframed as:

- Preferred function name: `ApplicationCopyDatFileName`
- Preferred C++ method name: `Application::CopyDatFileName`
- Preferred field name: `m_datFileName`
- Recommended score: `90/92`
- Recommended source placement: `NexusTK/app/Application.cpp` with declaration in the Application class/header

This is first-draft C++ ready after the rename. It should not be emitted under the current `CopyProcessorName` name because that name conflates two different Application members.

### UID 0002GR

Current name `ApplicationExchangeMSGHandler` is acceptable and source-meaningful. The exact source spelling may have used `Msg` rather than `MSG`, but the semantic operation is an exchange/swap, not a plain setter.

- Preferred C++ method name: `Application::ExchangeMSGHandler`
- Preferred field name: `m_activeMessageHandler`
- Preferred lock/global name: `s_messageHandlerCriticalSection`
- Recommended score: `88/92`
- Recommended source placement: `NexusTK/app/Application.cpp` with declaration in the Application class/header

This is first-draft C++ ready now.

## Function / Child Inventory

| UID | Range | Classification | Split Needed | Recommendation |
| --- | --- | --- | --- | --- |
| 0002JY | `0x004652e0-0x004652fc` | Application fixed-buffer copy accessor | No | Rename to DAT filename copy helper; keep Application ownership. |
| 0002GR | `0x00465650-0x00465686` | Application active message-handler exchange helper | No | Keep name/ownership; add first-draft C++. |

No child split is required for either target. Both ranges are single small methods with direct callees only.

## Heuristic / Inference Reanalysis And Validation

### 1. `Application + 0x428` Is Not Processor-Name State

Existing uncertainty in the 0002JY doc treated `Application + 0x428` as related to processor-name state. That inference is rejected.

Checked evidence:
- `ApplicationConstructor` reads registry `ProcessorNameString` into a SimpleUString-like member at `Application + 0x1c`.
- The same constructor writes constructor argument `a4` into `Application + 0x428` and immediately appends `.DAT`.
- The constructor writes the sibling fixed buffers as:
  - `Application + 0x28`: copied from `Source`
  - `Application + 0x228`: copied from `a4`
  - `Application + 0x428`: copied from `a4`, then `.DAT` appended
  - `Application + 0x628`: copied from `a4`, then `.SND` appended
- `ApplicationCopyWorldName` copies `Application + 0x28`.
- `ApplicationCopyPlayerName` copies `Application + 0x228`.
- The 0002JY target copies `Application + 0x428` through `_wcscpy_s` with the same fixed-buffer accessor shape.

Rejected alternatives:
- `CopyProcessorName`: rejected because CPU processor-name state is at `+0x1c`, not `+0x428`.
- `CopyPlayerName`: rejected because `+0x228` already has the dedicated player-name copy helper.
- `CopyWorldName`: rejected because `+0x28` already has the dedicated world-name copy helper.
- `CopyDatPath` or `CopyDataArchivePath`: plausible but weaker. The constructor proves a `.DAT` filename string, not a directory path or archive abstraction. `CopyDatFileName` is the narrowest supported source-facing name.

Validation result: `Application + 0x428` should be documented as a fixed 256-wide-character DAT filename buffer, not as processor-name state.

### 2. Caller Role At `0x004f72f7`

The single 0002JY caller at `0x004f72f7` is inside `0x004f6d80`, documented as `MainMenuPane::OnServerMessage`.

Checked callsite evidence:
- The handler is in pre-login server-message processing, not in-game session dispatch.
- The surrounding branch handles patch/version/update data.
- The local decompile/exported evidence shows the caller collecting:
  - application version via the Application version accessor,
  - executable path through the normalized executable path helper,
  - command-line data,
  - DAT filename through the 0002JY helper,
  - patch metadata written to `Patch/Info`,
  - construction of `PatchPane` or `PatchPane2`.

Rejected alternatives:
- MainMenuPane ownership: rejected because MainMenuPane is a consumer of Application state, not the owner of the field.
- PatchPane ownership: rejected because PatchPane consumes patch/update artifacts after the server-message branch builds them.
- Startup-only role: too broad. The immediate caller is specifically the pre-login server-message patch/update path.

Validation result: the caller role supports `CopyDatFileName`, because the DAT filename is part of patch/update information assembly.

### 3. `ExchangeMSGHandler` Meaning And Message Path

The 0002GR function:
- saves the previous pointer from `Application + 0x844`,
- constructs `CriticalSectionLock` on critical-section storage at `0x0067a9a4`,
- writes the incoming handler pointer into `Application + 0x844`,
- destroys the lock,
- returns the saved previous pointer.

Checked caller evidence:
- `MSGHandler` constructor calls `Application::ExchangeMSGHandler(this)` and stores the returned previous handler.
- `MSGHandler` destructor restores that saved previous handler.
- The scalar deleting destructor participates in the same restore path.
- `ApplicationRunMessageLoop` dispatches through the same active handler field under the same critical section.

Rejected alternatives:
- Plain `SetMSGHandler`: rejected because the return value is semantically required and used as the previous handler.
- MSGHandler-owned method: rejected because the mutated storage is inside `Application`, and the message loop reads it from `Application`.
- Independent global dispatcher owner: rejected because the only persistent owner field is `Application + 0x844`.

Validation result: `ExchangeMSGHandler` is source-quality enough and means "replace active Application message handler and return the previous one".

### 4. Field And Global Names

Recommended names:
- `Application + 0x1c`: `m_processorName`
- `Application + 0x28`: `m_worldName` or current project-equivalent existing field name
- `Application + 0x228`: `m_playerName` or current project-equivalent existing field name
- `Application + 0x428`: `m_datFileName`
- `Application + 0x628`: `m_sndFileName`
- `Application + 0x844`: `m_activeMessageHandler`
- `0x0067a9a4`: `s_messageHandlerCriticalSection`

The exact original member spellings are not proven. The semantic field identities are sufficiently proven for first-draft C++ and should not remain as generated names.

Rejected names:
- `m_processorName` at `+0x428`: contradicted by constructor writes.
- `m_patchDatName`: too consumer-specific; the field is initialized as core Application DAT filename state before the patch caller consumes it.
- `g_messageHandler`: rejected for `+0x844`; the storage is an Application member, not a standalone global.
- `MSGHandler::s_criticalSection`: rejected because the critical section is used by Application message-loop dispatch and Application exchange logic.

### 5. Ownership / Source Placement

0002JY:
- Direct owner: `Application`
- Direct emitter: `Application` / UID `00000D`
- Source placement: `NexusTK/app/Application.cpp`
- Consumers: `MainMenuPane::OnServerMessage`, then patch/update pane construction path

0002GR:
- Direct owner: `Application`
- Direct emitter: `Application` / UID `00000D`
- Source placement: `NexusTK/app/Application.cpp`
- Caller-side RAII owner: `MSGHandler`
- Utility dependency: `CriticalSectionLock`

No evidence supports moving either target out of Application source ownership.

### 6. First-Draft C++ Readiness

The old C++ blockers in the two target docs are no longer valid:
- Both have nonblank emitters.
- Both exceed the active combined-score gate.
- Both have exact small bodies with stable callees and callers.
- 0002JY's only material blocker was name/field identity, now resolved by constructor and caller evidence.
- 0002GR's only material blocker was source naming/lock meaning, now resolved enough for first-draft C++.

## Recommended First-Draft C++

### UID 0002JY After Rename

```cpp
errno_t Application::CopyDatFileName(wchar_t* destination, size_t sizeInWords) const
{
    return wcscpy_s(destination, sizeInWords, m_datFileName);
}
```

Notes:
- Populate this only after renaming away from `CopyProcessorName`.
- `m_datFileName` is a 256-wide-character fixed buffer initialized as `a4 + L".DAT"` in the constructor.
- The signature follows the `_wcscpy_s(destination, sizeInWords, source)` wrapper shape used by sibling Application copy helpers.

### UID 0002GR

```cpp
MSGHandler* Application::ExchangeMSGHandler(MSGHandler* nextHandler)
{
    MSGHandler* previous = m_activeMessageHandler;
    CriticalSectionLock lock(&s_messageHandlerCriticalSection);
    m_activeMessageHandler = nextHandler;
    return previous;
}
```

Notes:
- Keep the read of `m_activeMessageHandler` before constructing `CriticalSectionLock`; the binary reads the previous pointer before entering the lock.
- If the existing class style uses `Msg` spelling, `ExchangeMsgHandler` is acceptable, but the current `ExchangeMSGHandler` name is semantically correct enough to keep.

## Recommended Target Doc Changes

### `0x004652e0-0x004652fc.ApplicationCopyProcessorName.md`

Recommended document-level change:
- Rename to `0x004652e0-0x004652fc.ApplicationCopyDatFileName.md`.
- Change title/name from `ApplicationCopyProcessorName` to `ApplicationCopyDatFileName`.
- Change summary from processor-name copy helper to DAT filename copy helper.
- Update field description from `Application + 0x428` unresolved processor-related state to `Application + 0x428` fixed DAT filename buffer.
- Add constructor evidence: `+0x428 = a4 + L".DAT"`.
- Add caller evidence: `0x004f72f7` in `MainMenuPane::OnServerMessage` patch/update info assembly.
- Update score from `84/90` to `90/92`.
- Add the first-draft C++ block above after renaming.

### `0x00465650-0x00465686.ApplicationExchangeMSGHandler.md`

Recommended document-level change:
- Keep current file/name unless the project standardizes on `Msg`.
- Update score from `84/90` to `88/92`.
- Replace stale C++ gate text with the active gate result.
- Add first-draft C++ block above.
- Name `Application + 0x844` as `m_activeMessageHandler`.
- Name `0x0067a9a4` as `s_messageHandlerCriticalSection`.
- Document the caller chain through `MSGHandler` constructor/destructor and the same-field dispatch in `ApplicationRunMessageLoop`.

## Recommended Support Doc Touches

These should be handled by the follow-up editor, not by this report-only pass.

- `by-class/Application.md`: change `+0x428` from unresolved processor-name-related copy state to DAT filename buffer. Keep `+0x1c` as processor name.
- `by-file/Application.md`: keep source placement under `NexusTK/app/Application.cpp`; add the resolved DAT filename accessor.
- `by-memory/0x00465130-0x004651b8.ApplicationReadProcessorName.md`: remove the implication that `CopyProcessorName` proves `+0x428` processor-name state. The read helper/constructor duplicate relates to `+0x1c`.
- `by-memory/0x004f6700-0x004f7d10.MainMenuPaneCore.md`: if touched later, mention that the patch/update branch reads the Application DAT filename helper.
- `by-memory/0x00528d60-0x00528e55.MSGHandler.md`: if touched later, keep the constructor/destructor restore semantics and link the exchange method to Application ownership.

## Metadata And Generated Report Expectations

Expected `project-level/-auto-completion-stats.md` rows after accepted edits:

```text
| 0002JY | 90 | 92 | 91.0 | by-memory/0x004652e0-0x004652fc.ApplicationCopyDatFileName.md |
| 0002GR | 88 | 92 | 90.0 | by-memory/0x00465650-0x00465686.ApplicationExchangeMSGHandler.md |
```

Expected generated memory coverage status:
- Both rows should remain `emits` through `auto-generated/NexusTK/app/Application.cpp`.
- Both rows should switch from no-code/blank formal C++ status to code-present after the target docs receive the recommended C++ blocks.

## Exact Coverage Replacement Rows

Do not manually edit `by-memory/-coverage-report.md` during the temporary ban. These are the exact rows to use when coverage replacement is authorized.

### UID 0002JY

```text
        - [UID:0002JY][0x004652e0-0x004652fc.ApplicationCopyDatFileName](by-memory/0x004652e0-0x004652fc.ApplicationCopyDatFileName.md) 0x004652e0-0x004652fc | class method | ApplicationCopyDatFileName : reconstructable : 90% : strong : Reanalyzed as the Application DAT filename copy helper, not processor-name state: constructor writes CPU `ProcessorNameString` into the SimpleUString owner at `Application+0x1c`, but writes `a4 + ".DAT"` into the fixed 256-wide-character buffer at `Application+0x428`; this exact 0x1c-byte helper copies `+0x428` with `_wcscpy_s`, has one caller at `0x004f72f7` inside `MainMenuPane::OnServerMessage` patch/update info assembly, keeps owner/emitter `Application`, and is first-draft C++ ready after renaming.
```

### UID 0002GR

```text
        - [UID:0002GR][0x00465650-0x00465686.ApplicationExchangeMSGHandler](by-memory/0x00465650-0x00465686.ApplicationExchangeMSGHandler.md) 0x00465650-0x00465686 | class method | ApplicationExchangeMSGHandler : reconstructable : 88% : strong : Exact Application active-message-handler swap method: reads previous `Application+0x844` `MSGHandler*`, enters the Application message-handler critical section at `0x0067a9a4` through `CriticalSectionLock`, writes the incoming handler pointer, leaves the lock, and returns the saved previous handler; the only callers are the `MSGHandler` constructor/destructor/scalar deleting destructor restore path, while `RunMessageLoop` dispatches through the same field under the same lock. Owner/emitter remain `Application`; first-draft C++ is ready under the current combined-score gate.
```

## Negative Evidence Summary

- No evidence supports `Application + 0x428` as processor-name storage.
- No evidence supports MainMenuPane or PatchPane ownership of the 0002JY method.
- No evidence supports moving 0002GR to MSGHandler ownership; MSGHandler is the caller-side RAII wrapper and previous-handler owner, not the Application field owner.
- No evidence supports leaving either target code blank under the current active gate.
- No split is justified for either target.

## Validator Results

No target docs were edited, so no target-doc validator was run. This report is a research artifact only.

## Changed Files

- Created `tools/leaser/Agents/Agent-B008/research/0002JY-0002GR-ApplicationAccessorsAndExchangeMsgHandler-source-quality.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0002JY-0002GR-ApplicationAccessorsAndExchangeMsgHandler-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"0002JY"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
