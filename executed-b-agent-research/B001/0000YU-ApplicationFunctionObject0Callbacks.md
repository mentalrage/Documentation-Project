** TARGET-REPORT-UID:0000YU **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
## Finalized Report / Current Recommendation

Target: [UID:0000YU] `by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md`

Current recommendation: keep [UID:0000YU] as a parent-blank, `RECONSTRUCTABLE:FALSE` mixed split inventory. The historical page name describes only part of the span; IDA MCP proves the range contains callback-template support, StringBase helper code, Application destructor/accessor support, PasswordError destructor code, RegistryConfig destructor support, WinMain KeySpeedMgr cleanup, and Application fatal-load cleanup helpers. No single source owner is defensible for the whole physical interval.

Recommended status/classification: reviewed non-emitting mixed by-memory container, exact children carry ownership.

Confidence: high, `88/90` for the master container decision. Every modeled function in the range now has an exact child page or preexisting exact child page, and all reconstructable exact children meet the active `85/85` child/parent gate where assigned.

Concrete next action for A-agents/supervisor: archive B001-014 as complete. Future work should use the exact child pages, not [UID:0000YU], for source-owner routing.

Report state: final.

## Exact Child Decisions

| Range | UID / page | Decision |
| --- | --- | --- |
| `0x004671a0-0x004671ad` | [UID:000324] `PlainMemberFunctionObject0ApplicationInvoke` | Assigned to [UID:0000AJ] `PlainMemberFunctionObject0<Application>` / FunctionObjects support. |
| `0x004671b0-0x004671de` | [UID:000325] `StringBaseAppendWideLiteral` | Assigned to [UID:0000OA] `StringBase`. |
| `0x004671de-0x004671e6` | [UID:000326] `ApplicationScalarDeletingDestructorThunk` | Non-emitting compiler adjustor thunk, parent blank. |
| `0x004671f0-0x0046722e` | [UID:000327] `FunctionObject0ScalarDeletingDestructorVariant24` | Assigned to [UID:00005L] `FunctionObject0`. |
| `0x00467230-0x004672b7` | [UID:000323] `ApplicationScalarDeletingDestructor` | Assigned to [UID:00000D] `Application`. |
| `0x004672c0-0x004672fe` | [UID:000328] `FunctionObject0ScalarDeletingDestructorVariant4` | Assigned to [UID:00005L] `FunctionObject0`. |
| `0x00467300-0x00467338` | [UID:0002VK] `PasswordErrorScalarDeletingDestructor` | Preexisting exact child, `PasswordError`. |
| `0x00467340-0x0046737b` | [UID:000329] `RegistryConfigScalarDeletingDestructor` | Assigned to [UID:0000BW] `RegistryConfig`. |
| `0x00467380-0x00467391` | [UID:0000YV] `DestroyDATFileMgr` | Preexisting exact child, Application fatal-load cleanup. |
| `0x004673a0-0x004673b1` | [UID:0000YW] `DestroyExceptionHandler` | Preexisting exact child, Application fatal-load cleanup. |
| `0x004673c0-0x004673d1` | [UID:00032A] `DestroyKeySpeedMgr` | Assigned to [UID:0000PA] `WinMain`; [UID:0000KJ] `KeySpeedMgr` remains object/global owner through `g_pKeySpeedMgr`. |
| `0x004673e0-0x004673e6` | [UID:00032B] `GetApplicationSingleton` | Assigned to [UID:0000HG] `Application`. |
| `0x004673f0-0x004673f6` | [UID:00032C] `PlainMemberFunctionObject0ApplicationGetObjectSize` | Assigned to [UID:0000AJ] `PlainMemberFunctionObject0<Application>` / FunctionObjects support. |

## IDA Evidence Summary

- IDA MCP function inventory found real starts at `0x004671a0`, `0x004671b0`, `0x004671de`, `0x004671f0`, `0x00467230`, `0x004672c0`, `0x00467300`, `0x00467340`, `0x00467380`, `0x004673a0`, `0x004673c0`, `0x004673e0`, and `0x004673f0`.
- `0x004671b0` measures a UTF-16 source with `wcslen` and calls shared append helper `0x00584470`, making StringBase stronger than Application for the direct source owner.
- `0x004671de` is a non-emitting Application secondary-vftable thunk: `ecx -= 4`, then tail-jump to `0x00467230`.
- `0x00467230` writes Application vtables, clears `g_pApplication`, destroys Application subobjects, and conditionally frees a `0xa74`-byte object.
- `0x00467340` calls `~RegistryConfig`, conditionally deletes, and is referenced by RegistryConfig vtable slot `0x00612614`.
- `0x004673c0` loads `dword_67AB48` (`g_pKeySpeedMgr`), null-checks it, pushes deleting flag `1`, and dispatches through the object's vtable. Its only direct caller found is `WinMain` at `0x004f5eeb`, immediately after keyboard-settings restore at `0x004f5ee6`.
- `0x004673e0` returns `g_pApplication` and is used by fatal-dialog/startup-parser paths.
- `0x004673f0` returns `0x18` and has callback vtable/data refs, matching callback object-size virtual support.

## Changed Files Summary

Master and exact child docs:
- `by-memory/0x004671a0-0x004673f6.ApplicationFunctionObject0Callbacks.md`
- exact child pages [UID:000323] through [UID:00032C], plus preexisting child routing references for [UID:0002VK], [UID:0000YV], and [UID:0000YW].

Related parent/source/global docs:
- `by-file/Application.md`
- `by-file/FunctionObjects.md`
- `by-file/KeySpeedMgr.md`
- `by-file/StringBase.md`
- `by-file/WinMain.md`
- `by-class/Application.md`
- `by-class/FunctionObject0.md`
- `by-class/PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_.md`
- `by-class/RegistryConfig.md`
- `by-global/g_pKeySpeedMgr.md`
- `by-memory/0x00463310-0x004679be.ApplicationLifecycle.md`
- `by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md`
- `by-meta/client_callback_dispatch.md`

Ledgers/reports:
- `by-memory/-coverage-report.md`
- `by-memory/-ignored.md`
- `by-file/-coverage-report.md`
- `by-class/-coverage-report.md`
- `by-global/-coverage-report.md`

Supervisor correction before final acceptance:
- Supervisor manually corrected [UID:00032A] `by-memory/0x004673c0-0x004673d1.DestroyKeySpeedMgr.md`, where two references incorrectly named `MiniMapVersionManager` as the object/global owner. The corrected page now names `KeySpeedMgr` via `g_pKeySpeedMgr`; the corrected page and related KeySpeed/global/coverage ledgers revalidated cleanly.

## Validator Result Summary

Supervisor ran the targeted validator pass after the final documentation alignment.

- Result: every targeted file returned `ok: 1`.
- Last used UID: `00032C`.
- Validated scope included the master page, all exact child pages `000323` through `00032C`, related parent/source/global docs, `by-meta/client_callback_dispatch.md`, and the updated manual coverage/ignored ledgers.
- The supervisor-corrected `DestroyKeySpeedMgr` page and related KeySpeed/global/coverage rows also revalidated cleanly with `ok: 1`.

## Final Recommendation

Accept B001-014 as complete. [UID:0000YU] should remain a non-emitting split inventory only. The actionable ownership is now carried by exact child pages, especially [UID:00032A] `DestroyKeySpeedMgr`, which is best assigned to `WinMain` early-exit cleanup while preserving `KeySpeedMgr` as the object/global owner.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0000YU-ApplicationFunctionObject0Callbacks.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:18","uid":"0000YU"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
