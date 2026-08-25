*** UID:0000BG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "QuitDialogs.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "AlertPanes.h"

struct InputEvent;

class QuitDialog : public AlertPane
{
public:
    QuitDialog();
    virtual bool OnKeyInput(const InputEvent *event);

protected:
    virtual void OnPrimaryButton();
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# QuitDialog

## UID00037R Header Visibility And Direct Consumer - 2026-08-24

- The complete `QuitDialog` declaration now emits through `NexusTK/ui/dialogs/QuitDialogs.h`, including `AlertPanes.h` and the `InputEvent` forward declaration. `QuitDialogs.cpp` includes that header before the exact constructor/key/primary-button children.
- [UID:00037R][0x00506d20-0x00507150.MapPaneResizeCommandInputCore](by-memory/0x00506d20-0x00507150.MapPaneResizeCommandInputCore.md) is the direct Alt+X consumer at call site `0x00507068`. MapPane.cpp includes `../ui/dialogs/QuitDialogs.h` and executes ordinary `new QuitDialog`; ownership of the declaration and method definitions remains with QuitDialogs.
- This is a declaration-channel migration, not a second class definition. The former CPP-local declaration is removed, all existing children remain after `[[CHILDREN]]`, and no Singleton base, new field, wrapper, or MapPane-owned dialog body is introduced.

## Status

- Confidence: very strong for direct `AlertPane` inheritance, complete accepted declaration, role, boundaries, caller/vtable evidence, child access/signatures, and source route.
- Likely source file: [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md)
- Main address range: non-emitting split parent [UID:0001KT][0x005addf0-0x005adf2e.QuitDialogCore](by-memory/0x005addf0-0x005adf2e.QuitDialogCore.md), with exact source/no-code children listed below.
- Current recovered file: `source-3/simroot_v2/class_QuitDialog.cpp`

## Class Purpose

`QuitDialog` is the modal Yes/No confirmation shown before returning to the main menu or disconnecting. It derives directly from `AlertPane`, uses localized string id `3` for the title, and accepts both button clicks and `Y`/`N` keyboard shortcuts. Current RTTI exposes QuitDialog/AlertPane ancestry and no `Singleton<QuitDialog>` specialization, so no singleton base or derived fields are invented.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| [UID:0004GY][0x005addf0-0x005ade40.QuitDialogConstructor](by-memory/0x005addf0-0x005ade40.QuitDialogConstructor.md) | `QuitDialog::QuitDialog()` | Source-ready constructor C++; builds an `AlertPane` with localized prompt id `3`, [UID:00028J][0x0067a740-0x0067a744.g_pBackPane](by-memory/0x0067a740-0x0067a744.g_pBackPane.md), and `Yes (Y)` / `No (N)` labels. Compiler vtable stores are excluded from source statements. |
| [UID:0004GZ][0x005ade40-0x005adedb.QuitDialogOnKeyInput](by-memory/0x005ade40-0x005adedb.QuitDialogOnKeyInput.md) | `QuitDialog::OnKeyInput(const InputEvent *event)` | Source-ready key handler C++; checks event/message type `8`, narrows the input key, maps `Y/y` to primary OK, maps `N/n` to secondary/cancel, closes after handled shortcuts, and delegates default input to inherited `DialogPane` handling. |
| [UID:0004H0][0x005adedb-0x005adf20.QuitDialogOnKeyInputSwitchTable](by-memory/0x005adedb-0x005adf20.QuitDialogOnKeyInputSwitchTable.md) | key-handler switch data/alignment | Non-reconstructable compiler-lowered switch data and `0xcc` alignment for `OnKeyInput`; no emitter and no standalone source C++. |
| [UID:0004H1][0x005adf20-0x005adf2e.QuitDialogOnPrimaryButton](by-memory/0x005adf20-0x005adf2e.QuitDialogOnPrimaryButton.md) | `QuitDialog::OnPrimaryButton()` | Source-ready primary/OK handler C++; calls [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md)`->ExitToMenu(true)` through the map teardown route. |

## Evidence Notes

- IDA MCP `lookup_funcs` confirms the three source-bearing function starts and sizes. B012's accepted session `aa3930bd` reconfirmed `0x005addf0` size `0x50`, `0x005ade40` size `0x9b`, and `0x005adf20` size `0x0e`; no function starts at the switch-data child `0x005adedb`.
- IDA MCP caller checks show direct constructor references from `0x00507068` and `0x005bd202` in [UID:000082][MenuVarietySelectPane](by-class/MenuVarietySelectPane.md); the mode-gated launcher [UID:0000TD][OpenQuitPrompt_5A94B0](by-global/OpenQuitPrompt_5A94B0.md) carries a matching inline modal setup path rather than a direct call to `0x005addf0`.
- IDA MCP `xrefs_to` for `0x005ade40` and `0x005adf20` show vtable data xrefs, matching virtual event and OK-button handlers.
- The constructor uses [UID:00028J][0x0067a740-0x0067a744.g_pBackPane](by-memory/0x0067a740-0x0067a744.g_pBackPane.md) / `dword_67A740` as the alert context/parent. The generated name `g_pReconnectServer` remains provisional.
- 2026-06-16 live IDA MCP session `c001_midiplayer_rdata_20260615` reconfirmed `0x005addf0` size `0x50` / 80, `0x005ade40` size `0x9b` / 155, and `0x005adf20` size `0x0e` / 14 (Verified with `int_convert.py`).
- 2026-06-16 decompilation reconfirmed the constructor uses `dword_67A740`, localized string id `3`, `No (N)` / `Yes (Y)` labels, and three `QuitDialog` vtable stores; direct constructor calls are at `0x00507068` and `0x005bd202`. The launcher [UID:0000TD][OpenQuitPrompt_5A94B0](by-global/OpenQuitPrompt_5A94B0.md) has a matching inline modal setup path with allocation size `0x270`, but is not a direct call to `0x005addf0`.
- 2026-06-16 decompilation reconfirmed the key handler checks message type `8`, accepts `Y/y` through vtable slot `+92`, accepts `N/n` through slot `+96`, closes through `sub_49DAD0`, and otherwise delegates to inherited key handling; its only xref is vtable data at `0x0062f150`.
- 2026-06-16 live IDA `make_signature_for_range 0x005adedb-0x005adf20` produced a unique `0x45` / 69-byte range signature (Verified with `int_convert.py`) showing key-handler switch data followed by `0xcc` alignment, resolving the previous interior-gap caveat.
- 2026-06-16 decompilation of `0x005adf20` reconfirmed the OK handler calls `sub_5047F0(dword_67A764, 1)` and is reached through vtable data at `0x0062f13c`.
- 2026-07-04 B012 implementation split the former aggregate [UID:0001KT][0x005addf0-0x005adf2e.QuitDialogCore](by-memory/0x005addf0-0x005adf2e.QuitDialogCore.md) into source-bearing children [UID:0004GY][0x005addf0-0x005ade40.QuitDialogConstructor](by-memory/0x005addf0-0x005ade40.QuitDialogConstructor.md), [UID:0004GZ][0x005ade40-0x005adedb.QuitDialogOnKeyInput](by-memory/0x005ade40-0x005adedb.QuitDialogOnKeyInput.md), and [UID:0004H1][0x005adf20-0x005adf2e.QuitDialogOnPrimaryButton](by-memory/0x005adf20-0x005adf2e.QuitDialogOnPrimaryButton.md), plus non-emitting compiler-data child [UID:0004H0][0x005adedb-0x005adf20.QuitDialogOnKeyInputSwitchTable](by-memory/0x005adedb-0x005adf20.QuitDialogOnKeyInputSwitchTable.md). The aggregate parent is now an index only.
- Current QuitDialog globals/RTTI include the primary/secondary/tertiary table family and COL records; the first primary slot resolves the shared AlertPane-family scalar deleting destructor, primary slot `0x0062f13c` routes `OnPrimaryButton`, and key slot `0x0062f150` routes `OnKeyInput`. These tables are compiler products of the virtual declaration, not raw arrays to emit.
- Exact constructor has direct callers at `0x00507068` and `0x005bd202`; handlers are vtable-only. The live `OpenQuitPrompt` modal branch contains an inline setup path rather than calling the retained constructor address, matching the same retained/out-of-line versus inlined source pattern without changing class ownership.

## Reconstruction Notes

- Keep `RECONSTRUCTABLE:TRUE` and owner/emitter route through [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md); the class clears the direct-owner gate after the current boundary and support refresh.
- The formal class is now complete for all accepted source children. `InputEvent` is forward-declared; constructor and key handler are public; `OnPrimaryButton` is protected to match the accepted `AlertPane` callback access. The class closes before `[[CHILDREN]]`, so qualified child definitions emit at namespace scope.
- Exact source-bearing method bodies now live on child pages rather than the aggregate parent. [UID:0004GY][0x005addf0-0x005ade40.QuitDialogConstructor](by-memory/0x005addf0-0x005ade40.QuitDialogConstructor.md) emits the constructor, [UID:0004GZ][0x005ade40-0x005adedb.QuitDialogOnKeyInput](by-memory/0x005ade40-0x005adedb.QuitDialogOnKeyInput.md) emits `OnKeyInput`, and [UID:0004H1][0x005adf20-0x005adf2e.QuitDialogOnPrimaryButton](by-memory/0x005adf20-0x005adf2e.QuitDialogOnPrimaryButton.md) emits `OnPrimaryButton`. [UID:0004H0][0x005adedb-0x005adf20.QuitDialogOnKeyInputSwitchTable](by-memory/0x005adedb-0x005adf20.QuitDialogOnKeyInputSwitchTable.md) stays non-emitting because it is compiler-lowered switch data/alignment covered by the `OnKeyInput` source switch.
- Accepted source-facing helper/type names for this split are `g_pBackPane`, `InputEvent`, `NarrowInputKey`, `CloseDialog`, `OnPrimaryButton`, `OnSecondaryButton`, and `g_activeMapPane->ExitToMenu(true)`. These replace raw IDA labels for this class-level route while remaining documented as first-draft/inferred where broader base declarations are not final.
- Rejected declaration alternatives are a blank class emitter, `Singleton<QuitDialog>` inheritance, a synthetic secondary-button override, publicizing the protected primary callback, adding binary vptr/layout fields, or moving the class to MenuVariety/MapPane source. Each contradicts accepted child/access/RTTI/source-owner evidence or invents source not required by the exact method family.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 89 | The class page records complete source-ready declaration/child order, direct AlertPane inheritance, exact constructor/key/primary behavior, direct constructor and launcher-inline callers, vtable slots, `g_pBackPane`/resource support, exact switch data/alignment, compiler exclusions, source owner, access model, and rejected alternatives. |
| Confidence | 92 | Live IDA decompilation, xrefs, range signatures, vtable/RTTI evidence, accepted AlertPane access, exact child formals, and QuitDialogs routing agree. Original debug symbols and some helper/global spellings remain absent, so `95+` is not claimed. |

## Cross-References

- [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md)
- [UID:0000BH][QuitInputPane](by-class/QuitInputPane.md)
- [UID:0001KT][0x005addf0-0x005adf2e.QuitDialogCore](by-memory/0x005addf0-0x005adf2e.QuitDialogCore.md)
- [UID:0004GY][0x005addf0-0x005ade40.QuitDialogConstructor](by-memory/0x005addf0-0x005ade40.QuitDialogConstructor.md)
- [UID:0004GZ][0x005ade40-0x005adedb.QuitDialogOnKeyInput](by-memory/0x005ade40-0x005adedb.QuitDialogOnKeyInput.md)
- [UID:0004H0][0x005adedb-0x005adf20.QuitDialogOnKeyInputSwitchTable](by-memory/0x005adedb-0x005adf20.QuitDialogOnKeyInputSwitchTable.md)
- [UID:0004H1][0x005adf20-0x005adf2e.QuitDialogOnPrimaryButton](by-memory/0x005adf20-0x005adf2e.QuitDialogOnPrimaryButton.md)
- [UID:0000TD][OpenQuitPrompt_5A94B0](by-global/OpenQuitPrompt_5A94B0.md)
- [UID:000082][MenuVarietySelectPane](by-class/MenuVarietySelectPane.md)
- [UID:00028J][0x0067a740-0x0067a744.g_pBackPane](by-memory/0x0067a740-0x0067a744.g_pBackPane.md)

## Changes

- 2026-08-24 B006 UID00037R callback: moved the complete class declaration from the CPP channel to `QuitDialogs.h`, added the matching CPP include, and documented the direct MapPane Alt+X consumer while preserving all accepted child bodies and ownership.
- 2026-07-14 B003 UID0003ZQ callback: raised `85/88` to `89/92`; installed the complete `QuitDialog : public AlertPane` declaration with `InputEvent` forward declaration, public constructor/key handler, protected primary callback, class close, and `[[CHILDREN]]`; added no-Singleton/no-field RTTI direction, exact vtable/caller/launcher-inline/access/compiler evidence, rejected alternatives, and refreshed score rationale while preserving all exact child formals/scores/ranges.
- 2026-07-04 B012 split-first implementation:
  - Before: the class pointed at [UID:0001KT][0x005addf0-0x005adf2e.QuitDialogCore](by-memory/0x005addf0-0x005adf2e.QuitDialogCore.md) as a single blank-C++ method cluster.
  - After: the class records exact source-bearing constructor/key/primary-button children [UID:0004GY][0x005addf0-0x005ade40.QuitDialogConstructor](by-memory/0x005addf0-0x005ade40.QuitDialogConstructor.md), [UID:0004GZ][0x005ade40-0x005adedb.QuitDialogOnKeyInput](by-memory/0x005ade40-0x005adedb.QuitDialogOnKeyInput.md), and [UID:0004H1][0x005adf20-0x005adf2e.QuitDialogOnPrimaryButton](by-memory/0x005adf20-0x005adf2e.QuitDialogOnPrimaryButton.md), and non-emitting compiler switch-data/alignment child [UID:0004H0][0x005adedb-0x005adf20.QuitDialogOnKeyInputSwitchTable](by-memory/0x005adedb-0x005adf20.QuitDialogOnKeyInputSwitchTable.md). UID0001KT remains only as the split/index parent.
  - Summary/evidence: accepted B012 report and MCP session `aa3930bd` verified function sizes, constructor callers, vtable refs, switch-data/alignment bytes, source-file placement under [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md), and rejected MenuVariety/MapPane/base-dialog ownership routes.

- 2026-06-16 A001 low-confidence class refresh:
  - Before: `82/86`; the page had the right modal-dialog role but the class coverage row was stale and the exact core memory child still listed an unresolved interior gap.
  - After: `85/88`; final C++ remains blank.
  - Evidence: live IDA MCP session `c001_midiplayer_rdata_20260615` reconfirmed constructor/key/OK function sizes and decompilation, constructor calls at `0x00507068` and `0x005bd202`, launcher inline setup in [UID:0000TD][OpenQuitPrompt_5A94B0](by-global/OpenQuitPrompt_5A94B0.md), key/OK vtable data refs at `0x0062f150` and `0x0062f13c`, `g_pBackPane` parent/context usage, and a unique `0x005adedb-0x005adf20` switch-data/alignment signature.

- 2026-06-07 A005 resolved-name cleanup:
  - Before: alert parent/context evidence used only historical `dword_67A740`.
  - After: the page records canonical `g_pBackPane` beside the historical label and cross-links the global page.
  - Evidence: generated resolved-name report maps `dword_67A740` to `g_pBackPane`; existing IDA-backed evidence already ties the constructor argument to the alert parent/context.
- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `TRUE` and assigned parent `0000MX`.
  - Before: The modal quit confirmation remained unclassified in autogen coverage even though the page and parent file both met the 80/80 attach gate.
  - After: The class contributes to `QuitDialogs.cpp` as a reconstructable child without emitting final C++ yet.
  - Evidence: Live IDA MCP lookup confirms `0x005addf0`, `0x005ade40`, and `0x005adf20` as modeled functions; the parent [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md) records the same boundaries and ownership evidence.

- 2026-05-30: Changed completion/confidence from `0/0` to `82/86`.
  - Before: The page was unevaluated despite documenting role, constructor, keyboard handling, OK action, callers, and vtable refs.
  - After: Scored as high completion and strong confidence for the modal quit confirmation dialog.
  - Evidence: Existing method map and IDA MCP evidence notes confirm function boundaries, constructor callers, and virtual handler xrefs.
