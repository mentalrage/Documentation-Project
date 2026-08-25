** TARGET-REPORT-UID:00018P **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00018P KeySpeedMgr Restore System Keyboard Settings Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00018P] as source-bearing `KeySpeedMgr::RestoreSystemKeyboardSettings`, not no-code compiler glue.
- Final disposition: source-authored `KeySpeedMgr` method owned by [UID:00006Z] `KeySpeedMgr`, emitted through [UID:00006Z] to [UID:0000KJ] `NexusTK/input/KeySpeedMgr.cpp`.
- Required action: update the target page metadata and stale no-code wording, add the source-quality/signature rationale, and populate first-draft C++ if the supervisor accepts this report.
- Confidence: strong for boundary, behavior, API constants, field semantics, live callers, and owner/emitter route; medium-high for final original member spellings only.

Recommended target metadata:

| Field | Recommendation |
| --- | --- |
| `COMPLETION` | `88` |
| `CONFIDENCE` | `92` |
| `CANONICAL_OWNER` | keep `00006Z` |
| `RECONSTRUCTABLE` | keep `TRUE` |
| `EMITTER_UIDS` | keep `00006Z` |
| Formal C++ | populate first draft after supervisor implementation callback |

## Target

- Target UID: [UID:00018P]
- Target path: `source-3/project-documentation/by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B007/research/00018P-KeySpeedMgrRestoreSystemKeyboardSettings-source-quality.md`
- Current target score/state: `84/90`, `CANONICAL_OWNER:00006Z`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006Z`, blank C++.
- Source queue/report row: `by-memory/-coverage-report.md` currently says `84% : strong` and summarizes saved delay/speed restore with live IDA callers, field reads, constants, and parent ownership.
- Generated state: `auto-generated/NexusTK/input/KeySpeedMgr.cpp` currently contains the accepted `KeySpeedMgr::~KeySpeedMgr()` body and an empty emitter marker for UID `00018P`; the target's code omission is therefore a stale source-quality/gate issue, not an absent emitter route.

## Supervisor Active Recheck

- User assigned a B-agent source-quality / heuristic research pass for [UID:00018P] `KeySpeedMgrRestoreSystemKeyboardSettings`.
- Report-only pass: no target/support by-* docs were edited, no generated/project-level files were edited, and `by-memory/-coverage-report.md` was not edited.
- Prior completed B007 reports `000125` and `00015G` were preserved. This report file did not already exist before creation.
- Split repair is not required. The existing half-open range `0x004eff30-0x004eff5d` is exact and bounded by `0xcc` padding before the raw two-argument keyboard-repeat helper at `0x004eff60`.

## Evidence Standards Used

- Direct binary-derived evidence: existing live IDA notes in target/support docs, local IDA export `.lst`, `.c`, and `.map` files under `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS`.
- Documentation evidence: target page, `KeySpeedMgr` class/file/layout/vtable docs, aggregate and sibling helper pages, singleton/global pages, caller pages, generated output, and current coverage row.
- Prior research evidence: executed B001/B002 reports for `DestroyKeySpeedMgr`, `ApplicationFunctionObject0Callbacks`, and application lifecycle cleanup were searched for relevant `KeySpeedMgr` restore/delete routing.
- Inference guidance: `by-structure.md`, `Supervisor.md`, `.codex/AGENTS.md`, and Agent-B007 goal instructions require resolving source-quality issues before code entry. The active C++ gate is `RECONSTRUCTABLE:TRUE`, nonblank valid `EMITTER_UIDS`, and `(COMPLETION + CONFIDENCE) / 2 > 85`; old `95/95` wording is stale.
- IDA MCP status: fresh MCP connection was attempted at `http://127.0.0.1:13337/mcp` and failed with `Unable to connect to the remote server`. This report therefore relies on existing live-IDA documentation plus local IDA exports.

## IDA / Export Facts

- Existing live IDA target notes confirm `sub_4EFF30` size `0x2d`, range `0x004eff30-0x004eff5d`; `0x004eff5d-0x004eff60` is `0xcc` alignment before [UID:0002IS] `0x004eff60-0x004eff91`.
- Local IDA `.lst` export confirms the complete target body:
  - `0x004eff30`: `mov eax, [ecx+4]`, reading saved keyboard delay.
  - `0x004eff34`: `mov esi, [ecx+8]`, reading saved keyboard speed.
  - `0x004eff37`: `cmp eax, 3`; if in range, call `SystemParametersInfoW(0x17, delay, 0, 1)`.
  - `0x004eff49`: `cmp esi, 1Fh`; if in range, call `SystemParametersInfoW(0x0b, speed, 0, 1)`.
  - `0x004eff5b-0x004eff5c`: `pop esi; retn`.
- Local IDA import evidence identifies `SystemParametersInfoW` at import pointer `0x0060d3f8`.
- Local IDA `.c` export decompiles the body as a guessed `UINT __thiscall sub_4EFF30(_DWORD *this)`, but the returned `EAX` value is not source-meaningful. If the speed branch is skipped, the function returns either the first API result or the saved delay value; all callers ignore the value.
- Local caller windows confirm the four known live caller sites:
  - `0x00464aff` in `Application::CleanupResources`, after loading `ecx = g_pKeySpeedMgr`; next use reloads `g_pKeySpeedMgr` for deletion.
  - `0x00466adb` in `BaramAppOnDeactivate`, guarded by `g_pKeySpeedMgr != 0`.
  - `0x004ab844` in `TopLevelExceptionFilter`, guarded by `g_pKeySpeedMgr != 0`.
  - `0x004f5ee6` in `_WinMain@16`, guarded by `g_pKeySpeedMgr != 0`, immediately followed by `DestroyKeySpeedMgr` at `0x004f5eeb`.
- Local `.map` export lists `sub_4EFF30` and the `KeySpeedMgr` vtable/RTTI symbols, confirming this method sits in the documented `KeySpeedMgr` executable/vtable island.
- Current generated `auto-generated/NexusTK/input/KeySpeedMgr.cpp` routes the page through `KeySpeedMgr.cpp` but emits only an empty marker for UID `00018P`.

## Heuristic / Inference Reanalysis And Validation

### Source-Bearing Versus No-Code

- Best inference: source-bearing `KeySpeedMgr::RestoreSystemKeyboardSettings`.
- Evidence: modeled function object, object field reads at `this+0x04` and `this+0x08`, four live cleanup/deactivation/exception/WinMain callers, Win32 keyboard API calls, and class/file/layout docs that all describe this as the restore half of the save/fast-repeat/restore workflow.
- Rejected: scalar deleting destructor glue. The actual scalar deleting destructor is [UID:0002IT] `0x004effc0-0x004f0008`, vtable-referenced at `0x0061c9c8`, and remains wrapper-only.
- Rejected: file-local no-`this` helper. The raw setter at [UID:0002IS] and fast-repeat helper [UID:00018Q] have no object field access. This target does read object state, so class-method ownership is stronger.
- Rejected: padding/no-code. The local `.lst` body is executable code with two guarded API calls and live callers.

### Name And Signature

- Recommended source name/signature: `void KeySpeedMgr::RestoreSystemKeyboardSettings()`.
- Evidence: saved IDA label support uses `KeySpeedMgr_RestoreSystemKeyboardSettings`; docs consistently name the source method; no explicit stack arguments exist beyond `this`.
- The local IDA C export's `UINT` return is a decompiler artifact. The body does not construct a stable source-level return value, and each caller treats the call as side-effect only.
- Rejected names: `KeySpeedMgrRestoreSystemKeyboardSettings` as a C++ function spelling, `sub_4EFF30`, and `KeySpeedMgr_RestoreSystemKeyboardSettings` as final source. Keep those only as documentation/IDA labels.

### System Keyboard API / Helper Names

- Use the Unicode Win32 API: `SystemParametersInfoW`, not `SystemParametersInfoA`.
- Use source constants:
  - `SPI_SETKEYBOARDDELAY` for action `0x17`.
  - `SPI_SETKEYBOARDSPEED` for action `0x0b`.
  - `SPIF_UPDATEINIFILE` for `fWinIni == 1`.
- Both calls pass `pvParam == 0`; there is no `SPIF_SENDCHANGE` bit in the target.
- No project helper wrapper is visible in this range; the calls go directly through the imported `SystemParametersInfoW` pointer.

### KeySpeedMgr Field Semantics

- `this + 0x04` is saved Windows keyboard delay:
  - Constructor initializes it to `0xffffffff`.
  - `LoadSystemKeyboardSettings` reads `SPI_GETKEYBOARDDELAY` (`0x16`) into it.
  - This target restores it only if `<= 3`, matching the Windows-supported keyboard delay range.
- `this + 0x08` is saved Windows keyboard speed:
  - Constructor initializes it to `0xffffffff`.
  - `LoadSystemKeyboardSettings` reads `SPI_GETKEYBOARDSPEED` (`0x0a`) into it.
  - This target restores it only if `<= 31`, matching the Windows-supported keyboard speed range.
- Recommended final field names: `m_savedKeyboardDelay` and `m_savedKeyboardSpeed`. Existing generated/disabled material uses `m_keyboardDelay` and `m_keyboardSpeed`; those are acceptable only if the final header standardizes on the shorter names consistently. The "saved" prefix is more source-quality accurate because these fields hold the original system values to restore.

### Owner / Emitter / Source-File Route

- Accepted direct owner: [UID:00006Z] `KeySpeedMgr`.
- Accepted source root: [UID:0000KJ] `KeySpeedMgr`, path `NexusTK/input/KeySpeedMgr.cpp`.
- Evidence: target reads `KeySpeedMgr` fields, sibling load method fills those fields, constructor/destructor/global pages tie the object to `g_pKeySpeedMgr`, and class/file pages already clear the source-root route.
- Rejected owners:
  - [UID:0000K6] `InputMan`: owns input/IME message handling, not system keyboard repeat settings.
  - [UID:0000PA] `WinMain`: owns `DestroyKeySpeedMgr`, but is only a restore caller/cleanup consumer here.
  - [UID:0000HG] `Application`: owns one cleanup caller, not the method body.
  - Raw/file-local helper ownership: rejected because this target uses `this`.

### Caller / Reachability And Lifecycle Routing

- The target is live, not orphaned. Existing docs and local exports agree on four caller sites: application cleanup, app deactivation, top-level exception filtering, and WinMain updater/early-exit cleanup.
- `_WinMain@16` sequence proves restore-before-delete behavior: it calls `KeySpeedMgr::RestoreSystemKeyboardSettings` at `0x004f5ee6`, then calls [UID:00032A] `DestroyKeySpeedMgr` at `0x004f5eeb`.
- `DestroyKeySpeedMgr` is a WinMain-owned delete wrapper that null-checks `g_pKeySpeedMgr` and dispatches the deleting destructor through the vtable. It should stay outside the target and outside the `KeySpeedMgr` method body.
- The ordinary destructor [UID:0002IQ] already owns source body `g_pKeySpeedMgr = 0;`; the scalar deleting destructor [UID:0002IT] remains compiler wrapper evidence. This target should not contain destructor or delete semantics.

### Stale No-Code / Generated-Name Issues

- The target's change note says final C++ remains blank because the page is below the old `95/95` reconstruction-code gate. That is stale under active policy.
- This page already clears the active code gate even at the current `84/90`: it is `RECONSTRUCTABLE:TRUE`, has `EMITTER_UIDS:00006Z`, routes through [UID:00006Z] to [UID:0000KJ] `NexusTK/input/KeySpeedMgr.cpp`, and has average score `87`.
- The recommended `88/92` score makes code entry clearer and reflects the now-resolved source-quality issues: signature, constants, field roles, caller/reachability, and no-code rejection.
- Replace generated/raw names in target prose where possible:
  - `sub_4EFF30` -> `KeySpeedMgr::RestoreSystemKeyboardSettings`.
  - `dword_67AB48` -> `g_pKeySpeedMgr`.
  - `this+0x4` -> `m_savedKeyboardDelay` or the final chosen field spelling.
  - `this+0x8` -> `m_savedKeyboardSpeed` or the final chosen field spelling.

### Open Questions

- Exact original member spellings are not recovered. The source-quality recommendation is `m_savedKeyboardDelay` / `m_savedKeyboardSpeed`; implementation may use `m_keyboardDelay` / `m_keyboardSpeed` only if the class header/source is already standardized on those names.
- Live IDA MCP was unavailable for a fresh B007 query, so no new live `lookup_funcs`, `decompile`, `xrefs_to`, or byte dump was collected in this session. Existing live-IDA notes and local exports are consistent.
- Final surrounding header ownership for Win32 constants/includes is outside this target. The draft assumes the normal `windows.h` constants are available wherever `KeySpeedMgr.cpp` is rebuilt.

## First-Draft C++ Recommendation

Populate the target C++ block after supervisor acceptance. Use final project field spelling consistently; the body below uses the recommended semantic field names.

```cpp
void KeySpeedMgr::RestoreSystemKeyboardSettings()
{
    if (m_savedKeyboardDelay <= 3) {
        ::SystemParametersInfoW(SPI_SETKEYBOARDDELAY, m_savedKeyboardDelay, 0, SPIF_UPDATEINIFILE);
    }

    if (m_savedKeyboardSpeed <= 31) {
        ::SystemParametersInfoW(SPI_SETKEYBOARDSPEED, m_savedKeyboardSpeed, 0, SPIF_UPDATEINIFILE);
    }
}
```

Implementation notes:

- If the accepted `KeySpeedMgr` class declaration uses `m_keyboardDelay` and `m_keyboardSpeed`, substitute those field names only; keep the saved-value semantics documented.
- Keep the source signature `void`. Do not preserve the local IDA C export's guessed `UINT` return.
- Do not add deletion, destructor, or `g_pKeySpeedMgr` clearing to this method. Those are handled by [UID:0002IQ], [UID:0002IT], and [UID:00032A].

## Documentation Evidence And IDA Status

- [UID:00018P] target page already supports exact range, live callers, `SystemParametersInfoW` actions, field offsets, and alignment before the raw setter.
- [UID:00006Z] `KeySpeedMgr` and [UID:0000KJ] `KeySpeedMgr` support class/file ownership, source route, and the method/helper inventory.
- [UID:0001UV] `KeySpeedMgrLayout` confirms object size `0x0c`, vptr at `+0x00`, saved keyboard delay at `+0x04`, and saved keyboard speed at `+0x08`.
- [UID:0002IR] `LoadSystemKeyboardSettings` confirms the paired getter calls into the same fields.
- [UID:0002IS] and [UID:00018Q] confirm the same set-delay/set-speed constants and range limits for raw and fast-repeat helper paths.
- [UID:0002IQ] and [UID:0002IT] confirm ordinary destructor versus scalar deleting destructor separation.
- [UID:0000RB] and [UID:0001P7] `g_pKeySpeedMgr` pages confirm singleton lifecycle, restore callers, fast-repeat callers, and the 2026-06-16 saved IDA labels.
- [UID:00032A] `DestroyKeySpeedMgr` and B001 executed research confirm WinMain ownership for the delete wrapper, not this method.
- Prior executed B001/B002/B007 search found no report directly for UID `00018P`; relevant prior reports only support caller/delete-wrapper routing and application cleanup context.

## Ranked Ownership Analysis

### 1. [UID:00006Z] KeySpeedMgr - Accepted

- Evidence for: object field reads, source method name family, paired load/restore behavior, class layout, singleton lifecycle, direct class/file docs, and current emitter route.
- Evidence against: none material. The method is called by multiple owners, but caller ownership does not override the method's class owner.
- Decision: keep as direct owner/emitter.

### 2. [UID:0000KJ] KeySpeedMgr File - Source Root Only

- Evidence for: valid `NexusTK/input/` source path, file owns `KeySpeedMgr` class, global, and file-local keyboard-repeat helpers.
- Evidence against: this exact target reads `this`, so semantic ownership belongs to the class, not just the file root.
- Decision: keep as generated source root via class emitter chain.

### 3. [UID:0000PA] WinMain / [UID:0000HG] Application - Caller Context Only

- Evidence for: both call restore during cleanup paths; WinMain also owns the adjacent delete wrapper.
- Evidence against: neither owns `this+0x04`/`this+0x08` fields or the save/restore method family.
- Decision: cite as callers/dependencies only.

### 4. Compiler Glue / No-Code - Rejected

- Evidence for: none for this exact body beyond its use in cleanup sequences.
- Evidence against: live function body, object field reads, four callers, and direct Win32 side effects. Actual compiler glue is separately documented in [UID:0002IT].
- Decision: keep `RECONSTRUCTABLE:TRUE` and enter C++ after acceptance.

## Exact Recommended Target-Doc Changes

Recommended metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006Z | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00006Z | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended C++ block:

```cpp
void KeySpeedMgr::RestoreSystemKeyboardSettings()
{
    if (m_savedKeyboardDelay <= 3) {
        ::SystemParametersInfoW(SPI_SETKEYBOARDDELAY, m_savedKeyboardDelay, 0, SPIF_UPDATEINIFILE);
    }

    if (m_savedKeyboardSpeed <= 31) {
        ::SystemParametersInfoW(SPI_SETKEYBOARDSPEED, m_savedKeyboardSpeed, 0, SPIF_UPDATEINIFILE);
    }
}
```

Recommended status/prose changes:

- Replace source name text with `KeySpeedMgr::RestoreSystemKeyboardSettings`.
- Add source signature note: recommended source signature is `void`; IDA's guessed `UINT` return is an ignored-register artifact because callers do not consume a return value.
- Replace "Final C++ remains blank because this is below the 95/95 reconstruction-code gate" with: "This page clears the active reconstruction-code gate. Formal C++ should be populated after source-quality review; remaining caveat is final field spelling consistency with the `KeySpeedMgr` class declaration."
- Add field-name note: `this+0x04` is saved keyboard delay and `this+0x08` is saved keyboard speed; prefer `m_savedKeyboardDelay` / `m_savedKeyboardSpeed`.
- Add helper/API note: direct `SystemParametersInfoW` calls use `SPI_SETKEYBOARDDELAY`, `SPI_SETKEYBOARDSPEED`, and `SPIF_UPDATEINIFILE`; no `SystemParametersInfoA`, no helper wrapper, and no `SPIF_SENDCHANGE`.
- Add lifecycle note: `DestroyKeySpeedMgr` and scalar deleting destructor behavior are separate delete/destructor wrappers; this target only restores system keyboard settings.
- Add a change-log entry noting B007 source-quality pass, score recommendation `88/92`, active-gate repair, local IDA export verification, and first-draft C++ readiness.

Support-doc recommendations if the supervisor includes them in a later implementation callback:

- [UID:00006Z] `by-class/KeySpeedMgr.md`: update the method row to mention that the restore page now owns formal C++ and that the scalar deleting destructor remains wrapper-only.
- [UID:0000KJ] `by-file/KeySpeedMgr.md`: replace any "generated output omits restore" wording after implementation with "restore now emits through UID `00018P`; raw setter remains unresolved/no-xref."
- [UID:00018O] aggregate and [UID:0002IR]/[UID:00018Q] siblings: when touched, replace inherited old `95/95` blank-C++ wording with the active combined-score/emitter gate or with specific no-code/source-quality reasons.

## Validator Needs

- No validator was run because no by-* docs were edited in this report-only pass.
- Implementation callback should run a UID-targeted validation for [UID:00018P] after editing the target, then regenerate/inspect autogen output for `auto-generated/NexusTK/input/KeySpeedMgr.cpp`.
- If support docs are edited, validate them in the same pass.

Suggested commands for the implementation callback:

> Executable block R001 was removed from this report and preserved verbatim in [00018P-KeySpeedMgrRestoreSystemKeyboardSettings-source-quality-removed.md](00018P-KeySpeedMgrRestoreSystemKeyboardSettings-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Autogen inspection should confirm:

- UID `00018P` no longer appears only as an empty emitter marker.
- `auto-generated/NexusTK/input/KeySpeedMgr.cpp` contains the restore body routed through [UID:00006Z] to [UID:0000KJ].
- The raw setter [UID:0002IS] remains an empty marker unless a separate accepted report resolves its no-xref/source-retention blocker.

## Exact Pending Coverage Text

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` directly as B007. Supervisor-owned replacement:

Replace the existing [UID:00018P] row with:

```text
        - [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md) 0x004eff30-0x004eff5d | method | KeySpeedMgr::RestoreSystemKeyboardSettings : reconstructable : 88% : strong : B007 source-quality pass keeps this as source-bearing KeySpeedMgr method under [UID:00006Z] with emitter route to [UID:0000KJ]; local IDA export and existing live IDA notes confirm exact 0x2d body, callers at 0x00464aff/0x00466adb/0x004ab844/0x004f5ee6, saved keyboard delay at +0x04 and saved keyboard speed at +0x08, range checks delay <= 3 and speed <= 31, direct SystemParametersInfoW calls with SPI_SETKEYBOARDDELAY/SPI_SETKEYBOARDSPEED and SPIF_UPDATEINIFILE, ignored decompiler return artifact supporting void source signature, destructor/delete wrappers kept separate, stale 95/95 blank-C++ wording removed, and first-draft C++ ready pending final field spelling consistency.
```

Generated `auto-generated/-ag-memory-coverage.md` should update through validator/autogen refresh, not by manual edit.

## Follow-Up Actions

- Supervisor: review/accept this report, then send B007 an implementation callback if the target page should be edited.
- Implementation pass: update [UID:00018P] metadata/prose/C++, run validation, inspect generated `KeySpeedMgr.cpp`, and leave `by-memory/-coverage-report.md` for supervisor-owned application unless the ban is lifted.
- Future research: a narrow `KeySpeedMgr` naming pass should standardize the final field names across constructor/load/restore docs and the class declaration (`m_savedKeyboardDelay`/`m_savedKeyboardSpeed` versus `m_keyboardDelay`/`m_keyboardSpeed`).

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B007/research/00018P-KeySpeedMgrRestoreSystemKeyboardSettings-source-quality.md`
- Modified: none.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/00018P-KeySpeedMgrRestoreSystemKeyboardSettings-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"00018P"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00018P-KeySpeedMgrRestoreSystemKeyboardSettings-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/00018P-KeySpeedMgrRestoreSystemKeyboardSettings-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00018P"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
