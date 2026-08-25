*** UID:0000L8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/menu/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# MenuVarietyPanes

## Status

- Confidence: strong for menu-variety pane/select-pane ownership, singleton lifecycle, exact raw-helper splits, and selector label-vector reachability; medium-high for final folder name and helper source names.
- Proposed module folder: `ui/menu/`
- Candidate file: `ui/menu/MenuVarietyPanes.cpp`
- Evidence basis: live IDA MCP xrefs/decompilation for the two singleton slots and targeted IDA boundary checks for the pane bodies.

## Hypothesis

`MenuVarietyPane` is the in-game menu button. It opens `MenuVarietySelectPane`, which displays a SUBWIN-framed selector with Userlook, Board, Mail, UserList, Friends, Target, Hotkey, Profile, Ranking, and Quit actions.

Likely structure:

```text
ui/menu/MenuVarietyPanes.cpp
```

Possible placement:

```text
social/MenuVarietyPanes.cpp
```

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `MenuVarietyPane` | `0x005bc610-0x005bc88a`, [UID:0003AH][0x005bc890-0x005bc96a.MenuVarietyPaneButtonRectHelpers](by-memory/0x005bc890-0x005bc96a.MenuVarietyPaneButtonRectHelpers.md), plus tail entries | `class_MenuVarietyPane.cpp` | Menu button pane that opens/closes the variety selector, draws `MENUVAR.EPF`, and owns fixed menu-button rectangle helpers. |
| `MenuVarietySelectPane` | `0x005bc970-0x005bd952`, [UID:0003AI][0x005bd960-0x005bd9ad.MenuVarietySelectPaneRowRectHelper](by-memory/0x005bd960-0x005bd9ad.MenuVarietySelectPaneRowRectHelper.md), [UID:0001NQ][0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest](by-memory/0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest.md), [UID:0003AJ][0x005bffe0-0x005c0034.MenuVarietyLabelVectorAppendMoveHelper](by-memory/0x005bffe0-0x005c0034.MenuVarietyLabelVectorAppendMoveHelper.md), plus tail entries | `class_MenuVarietySelectPane.cpp` | Selector pane that builds menu labels, handles action clicks, hit-tests ten rows, draws entries/frame/borders, appends label-vector entries, and destroys label storage. |
| [UID:0003JD][0x00630f8c-0x0063104c.MenuVarietyResourceAndLabelStrings](by-memory/0x00630f8c-0x0063104c.MenuVarietyResourceAndLabelStrings.md) | `0x00630f8c-0x0063104c` | `.rdata` literal child | Shared menu artwork names and selector labels split from the former user-status/menu string tail. |
| [UID:0000RI][g_pMenuVarietyPane](by-global/g_pMenuVarietyPane.md) | `0x0069b4e8` | global | Active menu button singleton. |
| [UID:0000RJ][g_pMenuVarietySelectPane](by-global/g_pMenuVarietySelectPane.md) | `0x0069bf78` | global | Active selector singleton. |

## Source Split And Empty-Emitter Disposition

The 2026-06-29 B003 implementation callback resolves the current empty-emitter family without changing this file page's `87/86` score. The accepted source shape keeps [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md) as the source route for `NexusTK/ui/menu/MenuVarietyPanes.cpp` and splits output as follows:

| Source piece | Owning doc | C++ policy |
| --- | --- | --- |
| `MenuVarietyPane` declaration/prototype layer, singleton declarations, button-rect helper prototype, and `[[CHILDREN]]` placement | [UID:000081][MenuVarietyPane](by-class/MenuVarietyPane.md) | Formal declaration-only C++ before exact child bodies. |
| `MenuVarietySelectPane` declaration/prototype layer, row constants, confirmed tail fields, selector helper prototypes, and `[[CHILDREN]]` placement | [UID:000082][MenuVarietySelectPane](by-class/MenuVarietySelectPane.md) | Formal declaration-only C++ before exact child bodies. |
| `g_pMenuVarietyPane` definition | [UID:0000RI][g_pMenuVarietyPane](by-global/g_pMenuVarietyPane.md) | `MenuVarietyPane *g_pMenuVarietyPane = NULL;` |
| `g_pMenuVarietySelectPane` definition | [UID:0000RJ][g_pMenuVarietySelectPane](by-global/g_pMenuVarietySelectPane.md) | `MenuVarietySelectPane *g_pMenuVarietySelectPane = NULL;` |
| `MenuVarietyPane` and `MenuVarietySelectPane` vtable data | [UID:0002Z1][0x00630d3c-0x00630dc8.MenuVarietyPaneVtableData](by-memory/0x00630d3c-0x00630dc8.MenuVarietyPaneVtableData.md), [UID:0002Z2][0x00630dc8-0x00630e58.MenuVarietySelectPaneVtableData](by-memory/0x00630dc8-0x00630e58.MenuVarietySelectPaneVtableData.md) | Marker-only formal output because compiler vtable bytes are regenerated from the class declarations and virtual method set. |
| exact singleton storage slots | [UID:0002WF][0x0069b4e8-0x0069b4ec.g_pMenuVarietyPane](by-memory/0x0069b4e8-0x0069b4ec.g_pMenuVarietyPane.md), [UID:0002A4][0x0069bf78-0x0069bf7c.MenuVarietySelectPaneSingleton](by-memory/0x0069bf78-0x0069bf7c.MenuVarietySelectPaneSingleton.md) | Marker-only formal output because the by-global pages emit the source declarations/definitions. |
| selector hit-test helper | [UID:0001NQ][0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest](by-memory/0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest.md) | Formal `static int HitTestMenuVarietyItem(int x, int y)` body. |

The marker-only rows are not no-improvement blockers: they resolve generated empty output while avoiding raw vtable dword arrays or duplicate singleton definitions.

## IDA MCP Evidence

Targeted checks on 2026-05-23 confirmed:

- `MenuVarietyPane`: `0x005bc610-0x005bc65f`, `0x005bc660-0x005bc688`, `0x005bc690-0x005bc7f9`, `0x005bc800-0x005bc874`, `0x005bc880-0x005bc88a`, `0x005bfc0b-0x005bfc16`, `0x005bfc16-0x005bfc21`, and `0x005bfc80-0x005bfcdf`.
- `MenuVarietySelectPane`: `0x005bc970-0x005bcf7a`, `0x005bcf80-0x005bcff7`, `0x005bd000-0x005bd372`, `0x005bd3a0-0x005bd3bf`, `0x005bd3c0-0x005bd5ac`, `0x005bd5b0-0x005bd621`, `0x005bd630-0x005bd952`, `0x005bfbd0-0x005bfbdb`, `0x005bfc21-0x005bfc2c`, `0x005bfc2c-0x005bfc37`, and `0x005bfce0-0x005bfd98`.

2026-06-07 A006 targeted recheck for the selector singleton parent gate confirmed:

- IDA MCP `xrefs_to 0x0069bf78` reports the complete seven-reference lifecycle for [UID:0000RJ][g_pMenuVarietySelectPane](by-global/g_pMenuVarietySelectPane.md): menu click/draw consumers, constructor publish/null-fallback, ordinary destructor clear, standalone clear helper, and scalar deleting destructor clear.
- IDA MCP `callers 0x005bc970` reports the selector constructor called from `0x005bc765` inside `MenuVarietyPane` click handling.
- IDA MCP `callees` for the selector constructor/destructor family confirms only pane/vector/string helpers in the menu selector lifecycle, while [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md) remains a separate physical neighbor rather than a menu-owned child.

2026-06-11 A002 Batch 199 split recheck confirmed:

- [UID:0003AH][0x005bc890-0x005bc96a.MenuVarietyPaneButtonRectHelpers](by-memory/0x005bc890-0x005bc96a.MenuVarietyPaneButtonRectHelpers.md) is the raw helper pair between the modeled menu-button methods and selector constructor; it builds the fixed `0..0x3d` by `0..0x18` menu-button rectangle and tests it through `sub_4B7E80`, with `0xcc` padding at both ends.
- [UID:0003AI][0x005bd960-0x005bd9ad.MenuVarietySelectPaneRowRectHelper](by-memory/0x005bd960-0x005bd9ad.MenuVarietySelectPaneRowRectHelper.md) is the raw selector-row rectangle helper after frame drawing and before the ten-row hit-test child; it uses `index * 16 + 6..22`, width `0..79`, and `sub_4B7C50`.
- [UID:0003AJ][0x005bffe0-0x005c0034.MenuVarietyLabelVectorAppendMoveHelper](by-memory/0x005bffe0-0x005c0034.MenuVarietyLabelVectorAppendMoveHelper.md) is the 24-byte label-vector append/move helper called from `MenuVarietySelectPane` construction at `0x005bceef` and `0x005bcf2d`; it stays file-parented here because the helper exists in the shared tail but all direct callers are selector label setup.

2026-06-16 A001 file-confidence refresh confirmed:

- Live IDA MCP still reports modeled menu starts at `0x005bc610`, `0x005bc660`, `0x005bc690`, `0x005bc800`, `0x005bc880`, `0x005bc970`, `0x005bcf80`, `0x005bd000`, `0x005bd3a0`, `0x005bd3c0`, `0x005bd5b0`, `0x005bd630`, `0x005bd9b0`, tail helpers/destructors, and the next `VideoPlayerPane` function at `0x005c0040`; raw helper starts `0x005bc890` and `0x005bd960` remain non-functions.
- IDA xrefs reconfirm `MenuVarietyPane` construction from main UI graph setup at `0x004f82fc`, selector construction from menu click handling at `0x005bc765`, hit-test calls at `0x005bd089` and `0x005bd338`, and label-vector helper calls at `0x005bceef` and `0x005bcf2d`.
- Singleton storage xrefs remain bounded to this menu family: nine refs to `g_pMenuVarietyPane` at `0x0069b4e8` and seven refs to `g_pMenuVarietySelectPane` at `0x0069bf78`, with ranking and quit actions staying cross-file dispatch targets rather than owned dialog implementations.
- A read-only PE scan found no direct call/branch or VA/RVA pointer references to raw rectangle helper starts `0x005bc890` or `0x005bd960`, but found the same two direct calls to the selector label-vector helper `0x005bffe0`; range signatures reconfirm the raw helper bytes are unique and `0x005c0034-0x005c0040` is `0xcc` padding before `VideoPlayerPane`.

2026-06-29 B003 accepted empty-emitter implementation recheck used current MCP session `3fa0535f`:

- `server_health` was ok for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; Hex-Rays and strings cache were ready.
- `lookup_funcs` reconfirmed modeled starts for the menu button, selector, hit-test, destructor thunks, scalar deleting destructors, and label-vector helper; `0x005bc890`, `0x005bd960`, `0x005bda3b`, and `0x005c0034` are not modeled function starts.
- `get_bytes` / `get_int` read `00 00 00 00` for both singleton slots at `0x0069b4e8` and `0x0069bf78`, superseding older `0xffffffff` wording on the global/storage docs.
- Vtable slot reads matched the documented destructor/thunk starts: `0x00630d3c -> 0x005bfc80`, `0x00630d8c -> 0x005bfc0b`, `0x00630dbc -> 0x005bfc16`, `0x00630dc8 -> 0x005bfce0`, `0x00630e1c -> 0x005bfc21`, and `0x00630e4c -> 0x005bfc2c`.
- `xrefs_to 0x005bd9b0` returned only the two selector mouse-handler refs at `0x005bd089` and `0x005bd338`; `xrefs_to 0x005bd960` returned zero refs, so the hit-test body should materialize its row rectangles directly rather than call that adjacent raw helper.
- `decompile` / `disasm` for `0x005bd9b0` confirmed the ten-row loop, row rectangle formula `(0, row * 16 + 6, 79, row * 16 + 22)`, row return on hit, and `-1` on miss.

## Ownership Notes

- The constructor's vector growth helper at `0x00455350` remains reusable small-wide-string vector support. The exact in-tail append/move helper at `0x005bffe0-0x005c0034` is now split as [UID:0003AJ][0x005bffe0-0x005c0034.MenuVarietyLabelVectorAppendMoveHelper](by-memory/0x005bffe0-0x005c0034.MenuVarietyLabelVectorAppendMoveHelper.md) because live IDA MCP confirms direct use from selector label construction.
- This should stay separate from `PopupMenuControls.cpp`. It is a concrete gameplay menu selector, not the reusable popup menu item framework.
- The Ranking selector entry opens [UID:0000MZ][RankingDialog](by-file/RankingDialog.md); ranking opcode `0x7d`, ranking board resources, reward info, and ranking row containers belong to that dialog source, not this menu source.
- The Quit selector entry opens [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md); quit confirmation implementation should live in that dialog source, not in the menu selector source.
- Source migration should use IDA-confirmed boundaries, including tiny helper/thunk bodies around the main pane clusters.
- The singleton at `0x0069bf78` was previously left unresolved in the shared destructor tail; refreshed IDA xrefs resolve it as [UID:0000RJ][g_pMenuVarietySelectPane](by-global/g_pMenuVarietySelectPane.md).
- IDA MCP on 2026-05-26 resolves `0x005bd9b0-0x005bda3b` as the `MenuVarietySelectPane` ten-row hit-test helper.
- [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md) code sits between the menu body and the shared destructor/vector-helper tail in memory. Do not treat the broad `0x005bc610-0x005c0034` span as one contiguous menu-owned source range.
- 2026-06-29 B003 source-quality implementation preserves rejected alternatives: [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md) is a physical neighbor only; [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md) is a reusable framework only; [UID:0000MZ][RankingDialog](by-file/RankingDialog.md), [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md), and other opened dialogs are downstream dispatch targets; and [UID:0000HX][BulletinSession](by-file/BulletinSession.md) does not own the selector hit-test helper. [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md) is style precedent for class shells, globals, and static hit-test helpers, not ownership evidence for this file.

## Assignment Gate

This file page now clears the corrected parent gate for [UID:0000RJ][g_pMenuVarietySelectPane](by-global/g_pMenuVarietySelectPane.md). Confidence is raised to `86` because the selector singleton storage, selector constructor caller, destructor/clear-helper tail, old-status-pane boundary, raw helper non-reachability, and label-vector helper direct callers were rechecked directly; it remains below final-audit confidence because the exact final folder name and helper/source declarations remain unresolved.

## Cross-References

- [UID:000081][MenuVarietyPane](by-class/MenuVarietyPane.md)
- [UID:000082][MenuVarietySelectPane](by-class/MenuVarietySelectPane.md)
- [UID:0000RI][g_pMenuVarietyPane](by-global/g_pMenuVarietyPane.md)
- [UID:0000RJ][g_pMenuVarietySelectPane](by-global/g_pMenuVarietySelectPane.md)
- [UID:0003AH][0x005bc890-0x005bc96a.MenuVarietyPaneButtonRectHelpers](by-memory/0x005bc890-0x005bc96a.MenuVarietyPaneButtonRectHelpers.md)
- [UID:0003AI][0x005bd960-0x005bd9ad.MenuVarietySelectPaneRowRectHelper](by-memory/0x005bd960-0x005bd9ad.MenuVarietySelectPaneRowRectHelper.md)
- [UID:0001NQ][0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest](by-memory/0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest.md)
- [UID:0003AJ][0x005bffe0-0x005c0034.MenuVarietyLabelVectorAppendMoveHelper](by-memory/0x005bffe0-0x005c0034.MenuVarietyLabelVectorAppendMoveHelper.md)
- [UID:0003JD][0x00630f8c-0x0063104c.MenuVarietyResourceAndLabelStrings](by-memory/0x00630f8c-0x0063104c.MenuVarietyResourceAndLabelStrings.md)
- [UID:0001NP][0x005bc610-0x005c0034.MenuVarietyPanes](by-memory/0x005bc610-0x005c0034.MenuVarietyPanes.md)
- [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md)
- [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md)
- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md)

## Changes

- 2026-06-29 B003 implementation callback for the accepted empty-emitter family:
  - Scores remain `87/86`.
  - Summary/evidence: incorporated the accepted source split for the nine current `MenuVarietyPanes.cpp` empty emitters. Class pages now own declaration/prototype blocks with `[[CHILDREN]]`, global pages emit zero-initialized singleton definitions, exact vtable/storage children carry marker-only covered-by formal output, and [UID:0001NQ][0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest](by-memory/0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest.md) emits the ten-row helper body. Current MCP session `3fa0535f` confirmed zero singleton bytes, vtable slot dwords, hit-test callers, no refs to the adjacent raw row-rect helper, and the row rectangle formula. Rejected owner alternatives remain OldUserStatusPane, PopupMenuControls, downstream Ranking/Quit/dialog owners, and BulletinSession.
- 2026-06-12 C001 Batch C001-019 related split update:
  - Scores remain `86/85`.
  - Summary/evidence: added [UID:0003JD][0x00630f8c-0x0063104c.MenuVarietyResourceAndLabelStrings](by-memory/0x00630f8c-0x0063104c.MenuVarietyResourceAndLabelStrings.md) as the exact menu-variety literal child after live IDA MCP confirmed `MENUVAR.*` and selector-label xrefs from menu draw/constructor paths only. The file already clears the direct parent gate for shared menu-module literals.
- 2026-06-16 A001 file-confidence refresh:
  - What existed before: `86/85`, with strong menu family grouping but no current file-root PE reachability check for raw rectangle helpers and the label-vector helper.
  - Changed to: `87/86`.
  - Summary/evidence: live IDA MCP reconfirmed modeled menu/select functions, raw `0x005bc890`/`0x005bd960` non-function status, singleton refs, selector constructor/hit-test/vector-helper calls, and the `0x005c0034-0x005c0040` padding before `VideoPlayerPane`; a read-only PE scan found no direct calls/branches or VA/RVA pointer hits for the raw rectangle helper starts and exactly two direct calls to `0x005bffe0`. Ranking/Quit remain dispatch targets, not owned implementations.
- 2026-06-11 A002 Batch 199 split refresh:
  - What existed before: the file page already cleared the parent gate at `86/85`, but the raw menu-button/selector rectangle helpers were still only described as broad-range follow-up candidates and the `0x005bffe0` append/move helper was not linked as an exact child.
  - Changed to: scores remain `86/85`; added [UID:0003AH][0x005bc890-0x005bc96a.MenuVarietyPaneButtonRectHelpers](by-memory/0x005bc890-0x005bc96a.MenuVarietyPaneButtonRectHelpers.md), [UID:0003AI][0x005bd960-0x005bd9ad.MenuVarietySelectPaneRowRectHelper](by-memory/0x005bd960-0x005bd9ad.MenuVarietySelectPaneRowRectHelper.md), and [UID:0003AJ][0x005bffe0-0x005c0034.MenuVarietyLabelVectorAppendMoveHelper](by-memory/0x005bffe0-0x005c0034.MenuVarietyLabelVectorAppendMoveHelper.md) to proposed contents, evidence, ownership notes, and cross-references.
  - Summary/evidence: live IDA MCP raw disassembly and xref checks confirmed helper boundaries, rectangle constants, vector-helper callers, and surrounding `0xcc` padding while preserving [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md) as a separate physical neighbor.

- 2026-06-07 A006 Batch 060 parent-gate refresh:
  - What existed before: `COMPLETION:86`, `CONFIDENCE:82`, with strong menu selector docs but below the corrected parent gate for [UID:0000RJ][g_pMenuVarietySelectPane](by-global/g_pMenuVarietySelectPane.md).
  - Changed to: confidence `85`; completion remains `86`.
  - Summary/evidence: live IDA MCP reconfirmed the selector singleton's full seven-xref lifecycle, the constructor caller from `MenuVarietyPane` click handling, selector destructor/clear-helper ownership, and the boundary excluding adjacent [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md) code.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:82`.
  - Summary/evidence: menu button/select-pane ownership, proposed contents, IDA ranges, singleton globals, hit-test helper, old-user-status boundary, and ranking/quit/popup split are documented; confidence is capped by final folder name and compact-source uncertainty.

- 2026-06-05 projected path assignment:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, so the by-file root remained an autogen file-path error.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/menu/"`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` places `MenuVarietyPanes.cpp` under `NexusTK/ui/menu/`, and live IDA MCP xrefs on `0x0069b4e8` / `0x0069bf78` confirm the menu button and selector singleton ownership for this file.
