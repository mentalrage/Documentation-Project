** TARGET-REPORT-UID:0002SW **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002SW IconsPaneConstructor Source-Quality Report

Assignment: `B002-goal2-iconspane-constructor-source-quality-0002SW-20260617`

Primary target: [UID:0002SW] `by-memory/0x004cf1f0-0x004cf25d.IconsPaneConstructor.md`

Report-only result: do not edit by-* docs, generated output, IDA DB, source files, or `by-memory/-coverage-report.md` directly. Supervisor-owned replacement text is included below.

## Recommendation

Raise [UID:0002SW] from `82/88` to `86/90`.

Keep:

- `CANONICAL_OWNER:00006B`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00006B`
- generated route through [UID:0000JZ] `IconsPane`, currently `NexusTK/ui/panels/IconsPane.cpp`

Do not populate the formal `RECONSTRUCTION_CPP` block yet, even though the recommended score clears the current `(completion + confidence) / 2 > 85` gate. The constructor behavior itself is source-reconstructable, but the formal block would force currently unsettled support names into a source page: the final `Config` field name for `g_pConfig + 0x28de32`, final header/member spelling, and whether the old-HUD `IconsPane`/`TabPane` controls were physically grouped in one original source file. A first-draft C++ shape is included for review below.

## Evidence Checked

- Read current target and support docs: `0002SW`, `00016Z`, `00022Q`, `00006B`, `0000JZ`, `0002SX` through `0002T4`, `00034T`, `00034V`, `0000R6`, `0000OF`, `0001EA`, `0003BN`, `00028Q`, `0001OQ`, `0001OS`, `0001OW`, `0001OR`, and `0001KO`.
- Searched existing B-agent reports for `0002SW`, `0x004cf1f0`, `IconsPaneConstructor`, `00016Z`, `00022Q`, and `IconsPane`. No prior B report directly targets `0002SW`; useful leads came from B001 `000170-TabPaneAndIconsPaneDestructorTail`, B001 `00030A-Opcode2dCommandExtraValueSlots`, and B001 `0003BM-HourPaneVtableResourceData-advanced-scan`.
- Live IDA MCP session `b002_0002sw_iconspane_ctor_20260617` on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- IDA commands used included `lookup_funcs`, `analyze_batch`, `decompile`, `insn_query`, `xrefs_to`, `xref_query`, `get_bytes`, and helper decompiles for `0x00544460` and the eight action callees.
- Independent PE-aware read-only scan of `NexusTK.exe` for VA pointers, RVA pointers, and direct branches to `0x004cf1f0`, `0x004cf8e0`, `0x004cf954`, and `0x004cf974`.
- Generated-output check for `0x004cf1f0`, `IconsPaneConstructor`, `IconsPane::IconsPane`, and `NTK_ScopedInstall(IconsPane)` under `project-documentation/auto-generated`, `simroot_v2`, and `workdir_v2`.

## Constructor Shape And Boundaries

Live IDA confirms `IconsPaneConstructor` is the exact function `0x004cf1f0-0x004cf25d`, size `0x6d`. `0x004cf25d-0x004cf260` is three bytes of `0xcc` padding before [UID:0002SX] cleanup at `0x004cf260`.

The single direct caller is `0x004f8706` inside `InitializeMainUiGraph`. The PE scan also found exactly one direct branch to `0x004cf1f0`, the same `E8 rel32` call at VA `0x004f8706`, with no VA-pointer or RVA-pointer hits.

Source-facing signature should be:

```cpp
IconsPane::IconsPane()
```

with base construction represented as:

```cpp
: Pane(1)
```

Reason: live decompile of `0x00544460` plus [UID:0001EA] `PaneCore` identify `0x00544460-0x00544578` as `Pane::Pane`. Its second argument is stored in the base pane mode byte at `Pane + 0xb5`. `IconsPane` pushes literal `1`, matching other old-layout pane constructors.

Source-authored behavior in the constructor:

- construct the base `Pane` with mode/style `1`;
- publish `g_pIconsPane = this`;
- initialize the local visibility-mode boolean from `g_pConfig + 0x28de32`;
- initialize selected icon index to `-1`;
- clear the pressed/highlight state.

Compiler/ABI behavior that should stay out of source C++:

- the three `IconsPane` vtable stores at offsets `+0x00`, `+0xa0`, and `+0xa4`;
- the decompiler's adjusted-pointer/null artifact around `this + 0xf8`, which IDA shows as a normal singleton publish path in source terms.

## Field And Global Naming Recommendations

Best defensible class fields:

| Offset | Recommended field name | Evidence |
| --- | --- | --- |
| `this + 0xf8` | `m_showAllIcons` | Constructor sets it to `g_pConfig[0x28de32] == 0`; `IsShowingAllIcons`, `ShowAllIcons`, `ShowReducedIcons`, paint, hit-test, and tooltip paths all use this as the full-strip versus reduced-strip mode. |
| `this + 0xfc` | `m_selectedIconIndex` | Constructor initializes `-1`; mouse handler, paint, hit-test, and highlight invalidation use it as the active icon index. |
| `this + 0x100` | `m_isPressed` | Constructor clears it; `OnMouseEvent`, `OnPaint`, and `SetIconHighlight` use it as the pressed/highlighted visual state for the selected icon. |

Rejected field alternatives:

- raw `mbr_0xf8`, `mbr_0xfc`, `mbr_0x100`: generated placeholders, not source-quality names.
- `m_iconMode` for `+0xf8`: too ambiguous because the field is a boolean storing "show all", not the raw config byte.
- `m_highlightState` for `+0x100`: too broad; the state is a boolean pressed/highlight rendering latch.

Best defensible global and dependency names:

- `g_pIconsPane` at `0x0069b41c`: exact singleton slot; six xrefs are constructor publish, cleanup clear, scalar destructor clear, shutdown read, and two option-pane reads.
- `g_pConfig` at `0x0067a7c8`: use the existing global name. The field at `+0x28de32` should be documented as the IconsPane display/reduced-mode byte. Best source-facing field name is `iconPaneDisplayMode` or `iconPaneReducedMode`; if `iconPaneReducedMode` is used, the constructor expression is `!g_pConfig->iconPaneReducedMode`.
- `g_pEPFLib` at `0x0067a744`: used by paint/resource children, not by the constructor.
- `g_pLanguageMan` at `0x0067a750`: tooltip/localized text dependency for child hover behavior, not by the constructor.
- `g_activeMapPane` / input-lock field at `0x0067a764 + 0x3f0`: do not model as an independent `g_isInputLocked` global in final source; use either `g_activeMapPane->isInputLocked` or a source helper such as `IsInputLocked()` until the `MapPane` layout name is finalized.
- `g_pCollectionData` at `0x0067a748`: historical generated `g_pAppMan` is not source-quality. The action dispatcher passes this context to selected shared helpers.

## Adjacent Raw Dispatcher And Action Helpers

[UID:00022Q] `0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody` is not part of the constructor range, but it matters for source-quality treatment of the IconsPane action surface.

Current evidence:

- IDA has no function object at `0x004cf8e0`, `0x004cf8ff`, `0x004cf952`, `0x004cf954`, or `0x004cf974`.
- `xrefs_to 0x004cf8e0` returns zero refs.
- `xrefs_to 0x004cf954` returns only the local switch-table data reference from `0x004cf8ff`.
- PE-aware scan found no VA pointer, RVA pointer, or direct branch to `0x004cf8e0`, and found the sole VA pointer to `0x004cf954` inside the raw body's own jump-table dispatch.
- Live `IconsPane::OnMouseEvent` at `0x004cf6d8-0x004cf712` contains the same eight-case switch and calls the same helper sequence.

Recommendation: keep `00022Q` as retained raw old-HUD dispatch evidence under `IconsPane` file ownership, but do not make it a required source-authored helper for the constructor or populate final C++ for it without a recovered caller/address-taken use. It is best treated as duplicate/retained compiler or dead-source-shaped material that mirrors live `OnMouseEvent`.

Best current source-facing action helper names:

| Icon case | Callee | Best name direction | Rejected generated/source guesses |
| ---: | --- | --- | --- |
| `0` | `0x005a4db0` | `SwitchGeneralPurposePanelMode2WithClickSound` | `OpenArrangeDialog`; icon-local names are unsafe because the helper only calls `GeneralPurposePanelSwitchActiveTab(2, 0)` and plays sound `0x198`. |
| `1` | `0x005a4e40` | `SwitchGeneralPurposePanelMode3WithClickSound` | `OpenOptionsDialog`; same reason, with mode/tab `3`. |
| `2` | `0x005a4f70(0)` | `SendOpcode2DAndStoreExtra(0)` | IconsPane-owned action name; B001 `00030A` assigns the state/helper meaning to shared local-player command state consumed by IconsPane, TabPane, MapPane, and UserPane. |
| `3` | `0x005a5010(g_pCollectionData)` | `SyncNationEntriesOrDeferredState` | `OpenExchangeDialog` and `g_pAppMan`; live body requests nation entries or sends/dequeues deferred state, and `dword_67A748` is better documented as `g_pCollectionData`. |
| `4` | `0x005a50a0()` | `EnsureNormalBulletinSession` | `OpenMailDialog` as a final name; the body lazily creates a bulletin/session pane if the global is absent. |
| `5` | `0x005a5110(g_pCollectionData)` | `OpenInputPaneForCurrentSayMode` | broader `OpenCommunityDialog`; existing child evidence supports say-mode input pane dispatch. |
| `6` | `0x005a5340()` | `SendOpcode43MinusOneRequest` | UI-label guesses; the body builds and sends opcode `0x43` with selector `1`, id `-1`, field `4`, field `0`. |
| `7` | `0x005a5a80()` | `OpenQuitPrompt` / `OpenQuitPromptThunk` | `OpenQuestDialog`; the function is a five-byte jump thunk to the quit-prompt launcher. |

These names should be recorded as behavior names, not final original source labels. The shared caller fan-in is the reason: several callees are used by `TabPane`, `UserPane`, `MapPane`, chat/say code, or raw duplicate bodies.

## IconsPane Versus TabPane Source Placement

Keep the constructor's owner/emitter at [UID:00006B] `IconsPane` and [UID:0000JZ] `IconsPane` file placement under `NexusTK/ui/panels/IconsPane.cpp`.

Rejected alternative: attach constructor or action helpers to `TabPane` or a new combined old-HUD source root. B001 `000170` correctly treated `TabPane`/`IconsPane` adjacency as a source-layout clue, not ownership proof. The constructor writes `IconsPane` vtables, publishes `g_pIconsPane`, and has `IconsPane`-specific fields; no direct evidence makes it a `TabPane` method or a mixed aggregate child.

Open but nonblocking source-layout question: the original source may have physically grouped small old-layout HUD controls near each other. That should not block this constructor's class ownership or metadata because class/vtable/global evidence is direct.

## Generated Output State

The formal output route still points through `NexusTK/ui/panels/IconsPane.cpp`, but current generated files are not reliable source authority:

- `project-documentation/auto-generated/NexusTK/ui/panels/IconsPane.cpp` exists as a zero-byte/stale file in the current tree.
- `workdir_v2/class_IconsPane.cpp` and `simroot_v2/class_IconsPane.cpp` contain a plausible generated constructor, but use generated names such as `g_pConfigData`, synthetic member names, and generated comments. Treat them as leads only.
- Narrow search for `0x004cf1f0`, `IconsPaneConstructor`, `IconsPane::IconsPane`, and `NTK_ScopedInstall(IconsPane)` found hits only in `workdir_v2/class_IconsPane.cpp` and `simroot_v2/class_IconsPane.cpp`. No current `RankingDialog.cpp` pollution for `0x004cf1f0` was found in `project-documentation/auto-generated`, `simroot_v2`, or `workdir_v2`.

Generated names to reject for final source-quality docs:

- `g_pConfigData` for `g_pConfig`;
- `g_isInputLocked` as a standalone global instead of an active-map/input-lock field or accessor;
- `g_pAppMan` for `g_pCollectionData`;
- UI-label action names that are not supported by callee bodies.

## Heuristic / Inference Reanalysis And Validation

Best defensible inferences:

- `IconsPane::IconsPane()` is the source-facing constructor signature. Evidence is the exact function range, sole main-UI constructor caller, `thiscall` form, `IconsPane` vtable triad, `g_pIconsPane` publish, and direct class parent docs.
- `Pane(1)` is the source-facing base constructor call. Evidence is `PaneCore` plus live decompile of `0x00544460`, where the second argument becomes `Pane + 0xb5`; `IconsPane` pushes literal `1`.
- `+0xf8` is `m_showAllIcons`, not the raw config byte. Evidence is constructor `setz`, `IsShowingAllIcons`, `ShowAllIcons`, `ShowReducedIcons`, `OnPaint`, and `HitTestIcon`.
- `+0xfc` is `m_selectedIconIndex`. Evidence is constructor `-1`, mouse hit-test selection, paint selection, and invalidation/highlight usage.
- `+0x100` is `m_isPressed`. Evidence is constructor clear, mouse down/up handling, pressed-frame paint behavior, and `SetIconHighlight`.
- `g_pConfig + 0x28de32` is the persisted IconsPane display/reduced-mode byte. Evidence is constructor read, `ShowAllIcons` writing `0`, `ShowReducedIcons` writing `1`, and full/reduced paint/hit-test consequences.
- The adjacent raw dispatcher is retained duplicate evidence, not a live independent source helper. Evidence is IDA no-function/no-entry-xref, PE no-pointer/no-branch scan, only local switch-table pointer, and exact semantic duplication by live `IconsPane::OnMouseEvent`.

Evidence checked:

- Live IDA function size, boundaries, bytes, caller/callee, vtable refs, global refs, constructor decompile/disassembly, `Pane::Pane` decompile, raw dispatcher disassembly, raw/OnMouse switch comparison, and action callee xrefs/decompiles.
- PE scan for direct branch and pointer evidence, including `0x004cf8e0` raw entry and `0x004cf954` switch table.
- Current by-* docs, B-agent executed reports, generated output, and project stats/coverage entries.

Rejected alternatives:

- Do not model the decompiler's `if (this == -248)` singleton branch in source. It is an artifact of the adjusted `this + 0xf8` expression before storing `this` to `g_pIconsPane`.
- Do not include vtable stores in first-draft source C++; they are compiler output.
- Do not rename the base call as an unknown `PaneConstructorHelper_00544460`; `PaneCore` and live decompile support `Pane::Pane`.
- Do not assign the constructor to `TabPane`, `RankingDialog`, or a new mixed old-HUD file. No caller/vtable/global evidence supports that.
- Do not use generated action labels as final names. Callee behavior and caller fan-in reject icon-local labels for several helpers.
- Do not treat `0x004cf8e0` as a direct live source dependency of the constructor without recovered entry/caller/address-taken evidence.

Validation of existing docs:

- The target doc's range, reconstructable state, owner/emitter, main behavior, field offsets, and raw-dispatch caveat are valid.
- The target doc understates source-quality evidence now available for `Pane(1)`, final field names, padding, raw dispatcher duplicate treatment, action callee behavior, generated-output pollution, and source-placement impact.
- [UID:00016Z] `IconsPaneCore`, [UID:00022Q] raw dispatcher, [UID:00006B] class, and [UID:0000JZ] file docs are broadly valid. They should be updated only to fold in the more specific action-helper naming/rejection table and generated-output findings.
- Generated output is useful as a lead but not valid authority for `g_pConfigData`, `g_pAppMan`, standalone `g_isInputLocked`, or icon-local action labels.

Score/source-placement/final-C++ impact:

- Completion can rise to `86` because the constructor's own source shape, exact range/padding, field names, base constructor identity, singleton/global naming, raw-dispatch duplicate status, source placement, and generated-output caveats are now resolved to source-quality documentation level.
- Confidence can rise to `90` because live IDA and PE evidence are direct and mutually consistent. It should not go higher until final `Config` field spelling/header names and old-HUD source grouping are standardized.
- Source placement remains `IconsPane.cpp`; no owner/emitter change is justified.
- Formal C++ should stay blank for now despite reconstructability and score gate because support names are not ready for an accepted final block.

## First-Draft C++ Recommendation

This is the best current first-draft source shape for supervisor review only. Do not populate the target's formal `RECONSTRUCTION_CPP` block yet unless the supervisor first standardizes the `Config` field name and class member declarations in support docs/headers.

```cpp
IconsPane::IconsPane()
    : Pane(1)
{
    g_pIconsPane = this;

    m_showAllIcons = (g_pConfig->iconPaneDisplayMode == 0);
    m_selectedIconIndex = -1;
    m_isPressed = false;
}
```

If the support docs choose the inverse config field spelling `iconPaneReducedMode`, use:

```cpp
m_showAllIcons = !g_pConfig->iconPaneReducedMode;
```

Do not use `g_pConfigData[0x28DE32]`, raw `DAT_0067a7c8`, `mbr_0xf8`, or explicit vtable stores in the formal source block.

## Support Docs To Update

Recommended target update:

- [UID:0002SW] `IconsPaneConstructor`: score `86/90`; add the live 2026-06-17 IDA/PE evidence, `Pane(1)` source-facing signature, final field-name recommendations, `0x004cf25d-0x004cf260` padding, generated-output caveats, raw-dispatch duplicate treatment, and formal-C++ blank rationale.

Recommended support updates:

- [UID:00016Z] `IconsPaneCore`: add constructor audit summary and retain the child split; note raw dispatcher remains a retained duplicate after PE scan.
- [UID:00022Q] `IconsPaneActionDispatchRawBody`: add PE no-VA/no-RVA/no-direct-branch result and action-helper behavior-name/rejected-name table.
- [UID:00006B] `IconsPane`: adopt `m_showAllIcons`, `m_selectedIconIndex`, and `m_isPressed` as best field names; replace generated `g_pAppMan`/standalone `g_isInputLocked` caveats with `g_pCollectionData` and active-map/input-lock-field wording.
- [UID:0000JZ] `IconsPane` file: note current auto-generated route file is zero-byte/stale and no current `RankingDialog` pollution for `0x004cf1f0` was found.
- [UID:0000OF] `TabPane`: no ownership change; optional cross-reference that shared action helper names remain behavior-based and are not final icon/tab labels.
- [UID:0001EA] `PaneCore`: no required score change; this report relies on its `Pane::Pane` identification.

## Supervisor-Owned Coverage Row

Placement context: replace only the existing [UID:0002SW] row in `by-memory/-coverage-report.md` inside the [UID:00016Z] `IconsPaneCore` child block. Keep surrounding rows unchanged.

```markdown
        - [UID:0002SW][0x004cf1f0-0x004cf25d.IconsPaneConstructor](by-memory/0x004cf1f0-0x004cf25d.IconsPaneConstructor.md) 0x004cf1f0-0x004cf25d | class constructor | IconsPaneConstructor : reconstructable : 86% : very-strong : B002 2026-06-17 source-quality audit confirms exact `0x004cf1f0-0x004cf25d` range, `0x6d` size, `0x004cf25d-0x004cf260` padding, sole `InitializeMainUiGraph` caller at `0x004f8706`, `Pane::Pane(1)` base construction through `0x00544460`, `g_pIconsPane` publish, three compiler-generated IconsPane vtable stores, `g_pConfig + 0x28de32` full/reduced display-mode byte, `m_showAllIcons`/`m_selectedIconIndex`/`m_isPressed` field initialization, adjacent raw dispatcher duplicate/no-direct-xref treatment, shared action-helper naming reanalysis, generated-output caveats, and retained source placement under [UID:0000JZ][IconsPane](by-file/IconsPane.md); formal C++ remains blank until final Config/member names are standardized.
```

No other coverage-row change is required for this assignment. Several support rows remain historically stale in coverage versus their current docs, but they should be handled in a separate support-sync pass unless the supervisor chooses to fold them into this execution.

## Validation Commands

Run from `source-3/project-documentation` after supervisor applies accepted doc updates:

> Executable block R001 was removed from this report and preserved verbatim in [0002SW-iconspane-constructor-source-quality-removed.md](0002SW-iconspane-constructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Report-only validation performed here:

- Confirmed assigned report path did not already exist before writing.
- Confirmed generated-output search finds constructor references only in `workdir_v2/class_IconsPane.cpp` and `simroot_v2/class_IconsPane.cpp`, not `RankingDialog.cpp`.
- Confirmed `tools/validator.py` and `tools/memory_ranges.py` exist under `project-documentation/tools`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002SW-iconspane-constructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:25","uid":"0002SW"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002SW-iconspane-constructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0002SW-iconspane-constructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002SW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
