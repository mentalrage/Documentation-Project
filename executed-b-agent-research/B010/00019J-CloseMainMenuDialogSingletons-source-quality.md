** TARGET-REPORT-UID:00019J **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B010 B-report: [UID:00019J] `CloseMainMenuDialogSingletons`

## Scope

- Target: `source-3/project-documentation/by-memory/0x004f69a0-0x004f6a31.CloseMainMenuDialogSingletons.md`
- Coverage row: `source-3/project-documentation/by-memory/-coverage-report.md` only; do not edit directly.
- Assignment mode: B-agent source-quality / heuristic research only. Do not edit target or support docs until supervisor implementation callback.
- Required focus: source helper shape, singleton/global slot names and ownership, caller/reachability, cleanup semantics, source C++ readiness, support-doc routing, and exact pending coverage text.

## Current Recommendation

`00019J` should move from stale "below 95/95 no-code" reasoning to first-draft source C++.

- Recommended metadata: `COMPLETION 84 -> 88`, `CONFIDENCE 90 -> 91`.
- Keep `CANONICAL_OWNER: 0000L0`.
- Keep `EMITTER_UIDS: 0000L0`.
- Keep `RECONSTRUCTABLE: TRUE`.
- Source placement: `login/MainMenuPane.cpp`.
- Source shape: file-local helper, preferably `static void CloseMainMenuDialogSingletons()`.
- Do not model this as a private `MainMenuPane` instance method.
- Reframe `CloseMainMenuDialogSingletons_4F69A0` as a generated/recovered alias for the source helper, not as an independently source-authored global with its own emitted C++ body.

The target currently clears the active code-entry gate because it is reconstructable, has a valid nonblank emitter route to `0000L0`, and `(84 + 90) / 2 = 87`, which is greater than 85. After this reanalysis, the target is source-C++ ready.

## Evidence Checked

### Direct Raw Export Evidence

Raw IDA export data is available under `hooks-generation/tests/function_data/raw_ida_export_data/functions/`.

- `0x004f69a0.json`
  - Function name in export: `sub_4F69A0`.
  - Signature: `void()`.
  - Size: `145` bytes, exact range `0x004f69a0-0x004f6a31`.
  - Direct callers:
    - `0x004f695c` from `sub_4F6910`.
    - `0x004f6aa8` from `sub_4F6A60`.
    - `0x005028a3` from `sub_502850`.
  - Direct callees:
    - `0x0049dad0`.
    - `0x00544690`.
  - Body order:
    - `dword_69AE08` virtual slot call with delete flag `1`.
    - `dword_69B484` through `sub_49DAD0`.
    - `dword_69B48C` through `sub_49DAD0`.
    - `dword_69B498` through `sub_49DAD0`.
    - `dword_69B494` through `sub_544690`.
    - `dword_69B4A0` through `sub_49DAD0`.
    - `dword_69B4AC` through `sub_49DAD0`.
    - If `byte_66DA97 == 1`, `dword_69B4A8` through `sub_49DAD0`.
    - Else, `dword_69B4A4` through `sub_49DAD0`.

- `0x004f6910.json`
  - Non-deleting `MainMenuPane` destructor-shaped body.
  - Calls `sub_4F69A0()` at `0x004f695c`.
  - Also clears `dword_67ABA4` and chains Pane/base cleanup after child/member destruction.

- `0x004f6a60.json`
  - Vtable-reached callback/body.
  - Checks `Block[4] != 22`; when state is `22`, calls `sub_4F69A0()` at `0x004f6aa8`, allocates `0x270` bytes, constructs the follow-up dialog/pane, and returns `1`.
  - It passes adjusted `this - 160` to the follow-up constructor. The cleanup helper itself receives no object pointer.

- `0x00502850.json`
  - Scalar deleting destructor-shaped wrapper.
  - Calls `sub_4F69A0()` at `0x005028a3`.
  - Has vtable-slot/data reachability from `0x0061d264`.

- `0x0049dad0.json`
  - Signature: `void __thiscall(void *this)`.
  - Body: calls `sub_469180((_DWORD *)dword_67A74C, (int)this)`.
  - This is a one-line deferred-delete/close wrapper around the application cleanup queue path, not a `MainMenuPane` helper.

- `0x00544690.json`
  - Signature: `void __thiscall(_BYTE *this)`.
  - Body guards byte `this[244]`; if unset, sets it and calls `sub_469180((_DWORD *)dword_67A74C, (int)this)`.
  - This matches `Pane::MarkForDeletion` deferred-delete semantics.

### Documentation Evidence

- Target `00019J` already records prior live IDA MCP evidence: exact `0x91` bounds, callers `0x004f695c`, `0x004f6aa8`, `0x005028a3`, direct callees `0x0049dad0` and `0x00544690`, and exact singleton cleanup order.
- `by-file/MainMenuPane.md` owns/emits the relevant login main menu file as `0000L0`.
- `by-class/MainMenuPane.md` places the destructor and teardown paths under the `MainMenuPane` class/file cluster.
- `by-memory/0x004f6700-0x004f7d10.MainMenuPaneCore.md` records the destructor, the `0x004f6a60` menu/server callback, and the helper as one contiguous MainMenuPane core cluster.
- `by-global/CloseMainMenuDialogSingletons_4F69A0.md` currently acts as a source-name/global wrapper page for the helper, but it should be treated as an alias/index page rather than a second source body.
- `by-global/g_pApplicationCleanupQueue.md` and `by-memory/0x0067a74c-0x0067a750.g_pApplicationCleanupQueue.md` support the `0x0049dad0`/`0x00544690` queue path through `BlackHole::QueuePaneForDeferredDeletion`.
- `by-class/Pane.md` and `by-memory/0x00544240-0x00544b70.PaneCore.md` support the `Pane::MarkForDeletion` interpretation for `0x00544690`.

### Live MCP Status

Attempted current IDA MCP connection to `http://127.0.0.1:13337/mcp`; it failed with `IDA_MCP_ERROR: Unable to connect to the remote server`. This report therefore relies on raw export JSON plus existing documentation evidence, including previous live-MCP notes already recorded in the target.

## Singleton Slot Resolution

Recommended names and source-facing cleanup actions:

| Slot/address | Current best name | Action in helper | Evidence/reasoning |
| --- | --- | --- | --- |
| `dword_69AE08` / `0x0069ae08` | `g_pScreenDimmer` | virtual delete/scalar-delete flag `1`, source form should be `delete g_pScreenDimmer` | Raw body calls first vtable slot with argument `1`; existing screen dimmer global docs own the slot. |
| `dword_69B484` / `0x0069b484` | `g_pLoginDialogPane` | deferred dialog close wrapper `0x0049dad0` | Existing global and memory docs identify login dialog singleton. |
| `dword_69B48C` / `0x0069b48c` | `g_pChangePasswordDialogPane` | deferred dialog close wrapper `0x0049dad0` | Account-dialog singleton aggregate identifies the change-password slot even if global-page coverage is weaker than login/create/server slots. |
| `dword_69B498` / `0x0069b498` | `g_pBackStoryDialogPane` | deferred dialog close wrapper `0x0049dad0` | Existing global docs identify the backstory singleton. |
| `dword_69B494` / `0x0069b494` | `g_pHistoryViewingPane` | `Pane::MarkForDeletion` at `0x00544690` | Raw body uses the guarded Pane deletion helper, not the simpler dialog wrapper. |
| `dword_69B4A0` / `0x0069b4a0` | `g_pForcedInformMessageDialog` | deferred dialog close wrapper `0x0049dad0` | Existing global docs identify forced-inform message dialog singleton. |
| `dword_69B4AC` / `0x0069b4ac` | `g_pServerSelectPane` | deferred dialog close wrapper `0x0049dad0` | Existing global and dialog singleton-slot docs identify server-select singleton. |
| `byte_66DA97` / `0x0066da97` | `g_useEpfAssets` | exact branch discriminator `== 1` | Raw body compares byte to `1`; other nonzero values take the old/new-user fallback path. |
| `dword_69B4A8` / `0x0069b4a8` | `g_pNewCreateUserDialogPane` | deferred dialog close wrapper when `g_useEpfAssets == 1` | Existing create-user global docs identify EPF/new create-user singleton. |
| `dword_69B4A4` / `0x0069b4a4` | `g_pNewUserDialogPane2` | deferred dialog close wrapper when `g_useEpfAssets != 1` | Existing old/new-user slot docs identify fallback singleton. |

The exact `g_useEpfAssets == 1` comparison should be preserved in the target prose and first-draft C++ because the raw export does not implement a generic nonzero bool test.

## Helper Shape And Placement

Best-supported source shape:

```cpp
static void CloseMainMenuDialogSingletons()
```

Reasons:

- The raw export signature is `void()` with no hidden object parameter.
- The helper reads only globals and calls global/inherited cleanup helpers.
- It is called from both destructor-shaped bodies and from the `0x004f6a60` menu/server callback.
- The `0x004f6a60` body separately adjusts its own `this` pointer for a later constructor call, but does not pass any `MainMenuPane` state into this helper.
- A private instance method would normally have a `this` parameter or direct class-state usage. Neither is present.
- A static class method could compile similarly, but there is no evidence that class scoping is necessary. File-local `static` in `MainMenuPane.cpp` is simpler and matches the existing file owner route.

Rejected alternatives:

- `MainMenuPane::CloseMainMenuDialogSingletons()` as a private instance method: lower probability because the function has no `this`.
- Dialog-owned helper: wrong because the body spans unrelated login, account, backstory, history, forced-inform, server-select, create-user, and screen dimmer globals.
- `BlackHole` or `Pane` owner: wrong because those are cleanup dependencies, not semantic owners of the main-menu singleton sweep.
- Standalone exported/global API: wrong for source shape; there is no export evidence and all callers are internal main-menu teardown/menu paths.

## Global Alias Recommendation

`by-global/CloseMainMenuDialogSingletons_4F69A0.md` should be reframed as an alias/index page for the generated address-bearing name, not as a second implementation-bearing source function.

Recommended direction:

- Prefer the source name `CloseMainMenuDialogSingletons`.
- Keep `_4F69A0` only as a recovered/generated alias for searchability and address provenance.
- Do not add formal C++ to the by-global alias page if the by-memory target receives the source body; otherwise the emitter can duplicate the helper.
- Keep owner routing to `0000L0` for provenance, but make the prose explicit that the source-bearing implementation is UID `00019J` in `MainMenuPane.cpp`.
- If the supervisor accepts an alias-policy cleanup later, consider renaming the global page title or file away from the address-suffixed name. That is not required to make `00019J` source-ready.

## Caller And Reachability Resolution

The helper is not dead code and is not only destructor cleanup.

- `0x004f6910` non-deleting `MainMenuPane` destructor calls it at `0x004f695c`.
- `0x00502850` scalar deleting destructor wrapper calls it at `0x005028a3`; this wrapper is reachable from the MainMenuPane vtable area.
- `0x004f6a60` menu/server callback calls it at `0x004f6aa8` before constructing the follow-up connection/server dialog when packet/message state byte `22` is observed.

This reachability supports a file-local teardown helper reused by multiple `MainMenuPane.cpp` routines. It should not be documented as an isolated destructor-only tail.

## Cleanup Helper Semantics

Recommended source-facing names:

- `CloseDialogPane(...)` for `0x0049dad0`, pending final global helper naming.
- `Pane::MarkForDeletion()` for `0x00544690`.
- `BlackHole::QueuePaneForDeferredDeletion(...)` for `0x00469180`.

`0x0049dad0` is a thin wrapper that passes its receiver to `g_pApplicationCleanupQueue` through `0x00469180`. Existing decompiler owner noise around `sub_49DAD0` should not leak into this target as a real `ChattingColorPane` or `MainMenuPane` method name.

The distinction between `0x0049dad0` and `0x00544690` is meaningful:

- Dialog singleton pointers use the thin close/deferred-delete wrapper.
- `g_pHistoryViewingPane` uses `Pane::MarkForDeletion`, which sets the deferred-delete byte at `+0xf4` before queueing.
- `g_pScreenDimmer` uses virtual delete with flag `1`; source form should be a delete expression, not the dialog close wrapper.

## First-Draft C++ Recommendation

Recommended formal C++ for target `00019J` after implementation callback:

```cpp
static void CloseMainMenuDialogSingletons()
{
    if (g_pScreenDimmer != NULL)
        delete g_pScreenDimmer;

    if (g_pLoginDialogPane != NULL)
        CloseDialogPane(g_pLoginDialogPane);

    if (g_pChangePasswordDialogPane != NULL)
        CloseDialogPane(g_pChangePasswordDialogPane);

    if (g_pBackStoryDialogPane != NULL)
        CloseDialogPane(g_pBackStoryDialogPane);

    if (g_pHistoryViewingPane != NULL)
        g_pHistoryViewingPane->MarkForDeletion();

    if (g_pForcedInformMessageDialog != NULL)
        CloseDialogPane(g_pForcedInformMessageDialog);

    if (g_pServerSelectPane != NULL)
        CloseDialogPane(g_pServerSelectPane);

    if (g_useEpfAssets == 1) {
        if (g_pNewCreateUserDialogPane != NULL)
            CloseDialogPane(g_pNewCreateUserDialogPane);
    } else {
        if (g_pNewUserDialogPane2 != NULL)
            CloseDialogPane(g_pNewUserDialogPane2);
    }
}
```

Notes for the implementation callback:

- `CloseDialogPane` is a recommended descriptive source-facing name for the `0x0049dad0` deferred-close wrapper. If a stronger project-wide name has already been accepted for that wrapper, use that accepted name instead.
- Keep the `g_useEpfAssets == 1` comparison instead of simplifying to `if (g_useEpfAssets)`.
- The source should not manually call a scalar deleting destructor for `g_pScreenDimmer`; use a delete expression and document the binary effect.
- Do not put this same C++ body on `by-global/CloseMainMenuDialogSingletons_4F69A0.md`.

## Recommended Target Changes

For `by-memory/0x004f69a0-0x004f6a31.CloseMainMenuDialogSingletons.md`:

- Change `COMPLETION: 84` to `COMPLETION: 88`.
- Change `CONFIDENCE: 90` to `CONFIDENCE: 91`.
- Keep `CANONICAL_OWNER: 0000L0`.
- Keep `EMITTER_UIDS: 0000L0`.
- Keep `RECONSTRUCTABLE: TRUE`.
- Replace stale "below 95/95 code-emission gate" wording with the current 85/85 gate analysis:
  - The target is reconstructable, owner/emitter routed to `MainMenuPane.cpp`, and clears `(completion + confidence) / 2 > 85`.
  - First-draft C++ is ready.
- State that the source helper is best modeled as file-local `static void CloseMainMenuDialogSingletons()` in `login/MainMenuPane.cpp`.
- State that `CloseMainMenuDialogSingletons_4F69A0` is an address-bearing recovered alias, not the preferred source spelling.
- Add or update the singleton table with the exact names/actions in this report.
- Add explicit caller inventory: destructor `0x004f695c`, menu/server callback `0x004f6aa8`, scalar deleting destructor `0x005028a3`.
- Add the first-draft C++ block above.
- Keep open questions narrow:
  - Final accepted project-wide name for `0x0049dad0` close wrapper.
  - Whether a dedicated by-global page should be added for `g_pChangePasswordDialogPane` if not already present.
  - Whether alias-policy cleanup should rename/reframe the by-global `CloseMainMenuDialogSingletons_4F69A0` file.

## Recommended Support-Doc Changes

### `by-global/CloseMainMenuDialogSingletons_4F69A0.md`

- Reframe as a recovered alias/index page for `CloseMainMenuDialogSingletons`.
- Do not add formal C++ here if the by-memory target gets the implementation body.
- Add note: "Source-bearing implementation is UID `00019J`; this page preserves the address-suffixed recovered/global name for cross-reference search."
- Keep owner/emitter route to `0000L0` unless the supervisor performs a broader alias metadata conversion.

### `by-file/MainMenuPane.md`

- Update the helper row from a recovered standalone file shape to source placement in `login/MainMenuPane.cpp`.
- Recommended row wording:
  - `CloseMainMenuDialogSingletons` - file-local static helper at `0x004f69a0-0x004f6a31`; closes/deletes main-menu dialog singleton slots before destructor and menu/server transition paths continue; source body belongs to UID `00019J`.
- Add note that the address-suffixed by-global page is an alias only and must not emit a duplicate body.

### `by-class/MainMenuPane.md`

- Add or update notes under destructor/teardown:
  - The cleanup helper is file-local/static in `MainMenuPane.cpp`, not an instance method.
  - Non-deleting destructor, scalar deleting destructor, and the `0x004f6a60` menu/server callback all call it.
  - It does not consume `this`; it sweeps main-menu singleton globals.

### `by-memory/0x004f6700-0x004f7d10.MainMenuPaneCore.md`

- Update the `0x004f69a0` child description to match the current source decision:
  - `static void CloseMainMenuDialogSingletons()` in `MainMenuPane.cpp`.
  - Shared by destructor, scalar deleting destructor, and menu/server callback.
  - Not blocked by old 95/95 no-code gate.

### Singleton Global/Memory Support Pages

Check these for consistency during implementation and update only if missing or contradicted:

- `by-global/g_pScreenDimmer.md`
- `by-global/g_pLoginDialogPane.md`
- `by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md`
- `by-global/g_pBackStoryDialogPane.md`
- `by-global/g_pHistoryViewingPane.md`
- `by-global/g_pForcedInformMessageDialog.md`
- `by-global/g_pServerSelectPane.md`
- `by-global/g_pNewCreateUserDialogPane.md`
- `by-global/g_pNewUserDialogPane2.md`
- `by-global/g_useEpfAssets.md`
- `by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md`

Exact support corrections if contradicted:

- `dword_69B48C` should be named `g_pChangePasswordDialogPane` or explicitly described as the change-password dialog singleton slot.
- `dword_69B4A8` should be the EPF/new create-user path when `g_useEpfAssets == 1`.
- `dword_69B4A4` should be the fallback/old new-user dialog path when `g_useEpfAssets != 1`.
- `g_pHistoryViewingPane` should use `Pane::MarkForDeletion`, not the simple dialog-close wrapper.
- `g_pScreenDimmer` should be delete/virtual deleting-destructor semantics, not cleanup-queue wrapper semantics.

### Cleanup Wrapper Support

If implementation scope allows a new support page, add an exact by-memory page for `0x0049dad0-0x0049dadd` as the deferred dialog close wrapper. Suggested source-facing title:

- `0x0049dad0-0x0049dadd.CloseDialogPaneDeferredDeleteWrapper.md`

Minimal facts:

- Thin `void __thiscall(void *this)` wrapper.
- Calls `BlackHole::QueuePaneForDeferredDeletion` through `g_pApplicationCleanupQueue`.
- Used broadly by dialog/pane singleton cleanup paths.
- Do not assign it to `MainMenuPane`; it is a generic cleanup wrapper.

This is useful but not required to make `00019J` source-ready if the target itself documents the wrapper role.

## Validator Needs After Implementation

Run from `source-3/project-documentation` after any accepted target/support edits:

> Executable block R001 was removed from this report and preserved verbatim in [00019J-CloseMainMenuDialogSingletons-source-quality-removed.md](00019J-CloseMainMenuDialogSingletons-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Also run the same validator command for any singleton/global cleanup support pages touched during implementation.

No target/support validator was run for this report-only pass because no by-memory/by-class/by-file/by-global docs were edited.

## Exact Pending Coverage Replacement Row

Do not edit `by-memory/-coverage-report.md` directly under this B-report-only assignment. If the implementation is accepted, replace the existing row for UID `00019J` with:

```markdown
    - [UID:00019J][0x004f69a0-0x004f6a31.CloseMainMenuDialogSingletons](by-memory/0x004f69a0-0x004f6a31.CloseMainMenuDialogSingletons.md) 0x004f69a0-0x004f6a31 | helper | CloseMainMenuDialogSingletons : reconstructable : 88% : strong : B010 source-quality reanalysis resolves this as a `MainMenuPane.cpp` file-local `static void CloseMainMenuDialogSingletons()` helper, not a private instance method or standalone global; raw IDA export confirms `void()` signature, exact `0x91` size, callers at `0x004f695c`/`0x004f6aa8`/`0x005028a3`, direct callees `0x0049dad0` deferred dialog close wrapper and `0x00544690` `Pane::MarkForDeletion`, screen-dimmer virtual delete flag `1`, login/change-password/backstory/history/forced-inform/server-select singleton cleanup, exact `g_useEpfAssets == 1` current create-user branch, and first-draft source C++ readiness under owner/emitter `0000L0`.
```

## Remaining Issues

1. Live IDA MCP was unavailable during this pass, so current direct verification is raw export JSON plus existing documentation that already records previous live-MCP checks.
2. The exact project-wide source name for `0x0049dad0` is not globally settled. This report recommends `CloseDialogPane` as the source-facing descriptive name and treats the uncertainty as non-blocking because the wrapper role and callee path are exact.
3. `g_pChangePasswordDialogPane` appears best supported through the account-dialog singleton aggregate; if no by-global page exists for it, implementation can either keep exact raw slot plus name in the target or add a small global support page under supervisor-approved scope.
4. Alias policy for `by-global/CloseMainMenuDialogSingletons_4F69A0.md` remains a repository-organization decision. It should not block `00019J` C++ emission as long as only the by-memory target receives the formal helper body.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/00019J-CloseMainMenuDialogSingletons-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"00019J"} -->
<!-- {"agent":"B010","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00019J-CloseMainMenuDialogSingletons-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B010/00019J-CloseMainMenuDialogSingletons-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00019J"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
