*** UID:0000HP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# BackStoryDialogPane

## Status

- Confidence: very strong for the sole external singleton definition, complete fieldless `DialogPane`/direct-Singleton class shape, exact constructor/UI and `OnControlCommand` behavior, compiler-artifact splits, resources, login/main-menu ownership, negative active-route evidence, and retained/compatibility classification.
- Proposed module folder: `login/`
- Proposed source file: `login/BackStoryDialogPane.cpp`
- Documentation basis: IDA-confirmed constructor/button-handler/support ranges plus the class, memory, global, resource, and main-menu file docs listed below.
- Main class: [UID:00000T][BackStoryDialogPane](by-class/BackStoryDialogPane.md)
- Main address doc: [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md)
- Related resources: [UID:0001RG][main-menu-story-resources](by-resource/main-menu-story-resources.md) and [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md)
- Evidence basis: IDA MCP decompilation/string checks, the core by-memory range, singleton/global docs, and the main-menu cleanup helper documentation.

## File Role

`BackStoryDialogPane.cpp` owns retained/compatibility main-menu BackStory text-dialog code. It constructs a modal `DialogPane`, selects EPF or legacy EPD assets, adds an image background, one image button, and a scrolled `BACKTALE` text control, then opens the dialog through the main UI layer/context slot and [UID:0000RF][g_pMainMenuPane](by-global/g_pMainMenuPane.md).

The class is cleaned by the main-menu singleton cleanup helper alongside login, password, history, bulletin, and server-select dialogs, so it belongs under the login/main-menu source family rather than the in-game map UI.

This file is not the active current story/history viewer path. Active `MainMenuPane` story/history menu actions and retained story/history wrappers construct [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md). `BackStoryDialogPane.cpp` owns the older one-page `BACKTALE` text dialog and its singleton/destructor support.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:0000Q9][g_pBackStoryDialogPane](by-global/g_pBackStoryDialogPane.md) | physical slot `0x0069b498` | Sole external zero-initialized `BackStoryDialogPane *` definition at source position 0; loader-zero physical child UID00029F is non-emitting. |
| [UID:00000T][BackStoryDialogPane](by-class/BackStoryDialogPane.md) | class declaration | Fieldless `DialogPane` plus direct `Singleton<BackStoryDialogPane>` class, exact size `0x26c`, constructor, protected `OnControlCommand`, implicit destruction, and `[[CHILDREN]]` at position 10. |
| [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md) | `0x00500090-0x0050040d` | Constructor, `OnControlCommand`, internal 13-byte padding, exact hashes, full story-dialog resources/layout, and source-ready formal at position 20. |
| [UID:0003HH][0x00502390-0x0050239b.BackStoryDialogPaneSingletonBaseDestructor](by-memory/0x00502390-0x0050239b.BackStoryDialogPaneSingletonBaseDestructor.md) | `0x00502390-0x0050239b` | Compiler/template constructor-EH clear; class-owned, false/non-emitting. |
| [UID:0004W8][0x0050245e-0x00502474.BackStoryDialogPaneDestructorAdjustorThunks](by-memory/0x0050245e-0x00502474.BackStoryDialogPaneDestructorAdjustorThunks.md) | `0x0050245e-0x00502474` | Compiler `-0xa0/-0xa4` secondary/tertiary destructor routes. |
| [UID:0004W9][0x00502600-0x00502645.BackStoryDialogPaneScalarDeletingDestructor](by-memory/0x00502600-0x00502645.BackStoryDialogPaneScalarDeletingDestructor.md) | `0x00502600-0x00502645` | Direct-Singleton clear, DialogPane teardown, deleting flags, optional free; no authored destructor remainder. |
| [UID:0004WA][0x0061da54-0x0061daf0.BackStoryDialogPaneVtableData](by-memory/0x0061da54-0x0061daf0.BackStoryDialogPaneVtableData.md) | `0x0061da54-0x0061daf0` | Exact 156-byte three-view compiler backing, physically contained by UID00025Q and semantically class-owned. |
| [UID:0004WB][BackStoryDialogPaneVtables](by-type/by-vtable/BackStoryDialogPaneVtables.md) | semantic inventory | 23/11/2 slots, wrapper/thunk/`OnControlCommand` cells, eight-base RTTI, direct `+0x26c` EBO, blank compiler-data formal. |
| dependencies | [UID:0000RF][g_pMainMenuPane](by-global/g_pMainMenuPane.md), [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md), `g_useEpfAssets` | Show parent, overlay create context, and asset-mode state; dependencies remain owned by their source modules. |

## Layout Details

EPF asset mode:

- Background image: `STORY.EPF` with `PAL01.PAL`
- Dialog/control rectangle: `0,0,384,341`
- Button visual image index `14`: `169,305,232,329`
- Text control resource: `BACKTALE` at `25,56,361,278`, line/step value `50`
- Dialog position: `246,150,630,491`

Legacy asset mode:

- Background image: `STORY.EPD` with `NPAL8.PAL`
- Dialog/control rectangle: `0,0,267,337`
- Button visual image index `14`: `98,287,170,303`
- Text control resource: `BACKTALE` at `36,71,228,265`, line/step value `50`
- Dialog position: `363,150,630,487`

## Evidence Notes

- IDA MCP confirms real functions at `0x00500090`, `0x005003f0`, `0x00502390`, `0x0050245e`, `0x00502469`, and `0x00502600`.
- IDA string checks confirm `STORY.EPF`, `STORY.EPD`, `PAL01.PAL`, `NPAL8.PAL`, and `BACKTALE` at the expected referenced addresses.
- The documented `CloseMainMenuDialogSingletons` helper calls `g_pBackStoryDialogPane->CloseDialog()` if the singleton is live.
- `xrefs_to 0x00500090` found no direct constructor xrefs in the current IDA database. This may be an indirect/vtable allocation path, dead/older dialog path, or a recovered-data gap.
- IDA MCP `xrefs_to 0x0069b498` on 2026-05-25 confirms the singleton storage behind [UID:0000Q9][g_pBackStoryDialogPane](by-global/g_pBackStoryDialogPane.md): constructor writes, the clear helper/destructor clear it, and `CloseMainMenuDialogSingletons` reads it.
- 2026-06-01 IDA MCP recheck confirms the core constructor and button handler boundaries, no direct constructor caller, button-handler vtable data at `0x0061daa0`, constructor vtable writes through `0x0061da58`, and singleton xrefs at `0x004f69ce`, `0x005000e5`, `0x005000ec`, `0x00502390`, and `0x00502606`.
- The refreshed core memory page records exact branch-specific layout coordinates, child control allocations (`332`, `276`, `476` byte allocations), resource xrefs for `STORY.EPF`, `STORY.EPD`, and `BACKTALE`, and palette xrefs for `PAL01.PAL` and `NPAL8.PAL`.
- 2026-06-07 Batch 043 live IDA MCP reconfirmed [UID:0000Q9][g_pBackStoryDialogPane](by-global/g_pBackStoryDialogPane.md) as a clean four-byte `0xffffffff` singleton slot with five lifecycle xrefs and no extra neighboring storage inside [UID:00029F][0x0069b498-0x0069b49c.g_pBackStoryDialogPane](by-memory/0x0069b498-0x0069b49c.g_pBackStoryDialogPane.md). That closes the remaining parent-chain confidence issue for the global declaration while keeping direct constructor reachability as a documented caveat.
- 2026-06-14 C001 IDA MCP recheck reconfirmed constructor `0x00500090` size `0x353`, button handler `0x005003f0` size `0x1d`, singleton clear helper `0x00502390` size `0xb`, adjustor thunks `0x0050245e`/`0x00502469` size `0xb` each, and scalar deleting destructor `0x00502600` size `0x45`.
- The same C001 pass reconfirmed `xrefs_to 0x00500090` is empty, while `xrefs_to 0x0069b498` still has the five expected singleton lifecycle refs: main-menu cleanup read at `0x004f69ce`, constructor writes at `0x005000e5`/`0x005000ec`, clear-helper write at `0x00502390`, and destructor clear at `0x00502606`.
- `xrefs_to 0x0061da58` reconfirmed the constructor primary-vtable store at `0x005000f6`; `callees` reconfirmed the constructor's dialog/base, image, button, scrolled-text, resource, focus, create/show, and slide-open helper family, and the button handler's slide-close plus close-helper path.
- B014 2026-06-19 source-quality reanalysis resolves the stale "possible indirect active construction" wording as retained/compatibility code: local PE scans found no rel32 call/jump, absolute VA pointer, or RVA pointer to constructor `0x00500090`, no constructor pointer table, and no external BackStory vtable-head store. Existing active `MainMenuPane` story/history branches and retained wrappers construct [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md), not `BackStoryDialogPane`.
- The accepted source-quality pass makes exact C++ ready for [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md): `BackStoryDialogPane::BackStoryDialogPane()` and `OnControlCommand(int controlIndex, int notifyCode)`. UID0003HH/UID0004W8/UID0004W9/UID0004WA/UID0004WB preserve compiler support separately and remain blank/non-emitting.

## Complete Source Union And Compiler Exclusions

The authored `NexusTK/login/BackStoryDialogPane.cpp` union is deliberately narrow:

1. UID0000Q9 emits the sole `BackStoryDialogPane *g_pBackStoryDialogPane = 0;` definition at position 0.
2. UID00000T emits the complete fieldless `DialogPane`/`Singleton<BackStoryDialogPane>` class declaration, global extern, constructor, protected `OnControlCommand`, and `[[CHILDREN]]` at position 10.
3. UID0001A2 emits the exact constructor and command-handler bodies at position 20.
4. Resource strings, palettes, layer slot, show parent, and inherited UI/control types remain dependencies owned by their existing modules.

The source file must not handwrite singleton publication/clear, an explicit derived destructor, scalar/vector delete flags, optional free calls, vptr stores, receiver-adjustor thunks, vtables, RTTI records, EH cleanup, security-cookie code, or padding. Direct Singleton inheritance, implicit virtual destruction, and the compiler/linker regenerate those artifacts.

## Exact Layout And ABI Evidence

- Class size is `0x26c`, with no recovered authored derived fields.
- Direct Singleton PMD `{0x26c,-1,0}` and attributes `0x40` prove EBO at complete-object end.
- Vtable views are `+0x00`, `+0xa0`, and `+0xa4`; exact 156-byte backing `[0x0061da54,0x0061daf0)` has SHA256 `612C02F9BECCB97561B968979DAA3F8D743982053D8FBE8A7EBEA5CB37422771`.
- Primary slot zero routes to UID0004W9, primary `+0x48` routes to `OnControlCommand`, and adjusted slots route through UID0004W8.
- The eight-entry RTTI hierarchy independently proves `DialogPane`, inherited Pane/GrafPort/LObject/EventHandler/TimerHandler bases, and direct `Singleton<BackStoryDialogPane>`.

## Generated Output Contract

After scoped validation catches up, `auto-generated/NexusTK/login/BackStoryDialogPane.cpp` must contain exactly one semantic global definition, one class declaration, one constructor body, and one `OnControlCommand` body. It must contain no Empty Emitter Marker for UID00029F or UID0000Q9 and no emitted UID0003HH/UID0004W8/UID0004W9/UID0004WA/UID0004WB compiler artifacts. Generated files are validator-owned and are verified by readback rather than manual edits.

## Score Rationale

- Completion `92`: the complete authored source union, exact resources/layout, global/class/core ownership and order, compiler split inventory, hashes/ranges, retained routing, dependencies, one-definition handling, and generated contract are documented without loss.
- Confidence `93`: current IDA/PE evidence, RTTI/EBO, exact compiler children, semantic global lifecycle, current family APIs, and source-family placement agree. Missing original translation-unit spelling and historical launcher cap confidence below the child artifacts.

## Ownership Notes

Keep [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) as the menu dispatcher/owner of menu selection flow. `BackStoryDialogPane` is a child dialog in the same source family, not the top-level menu controller.

Do not confuse this with [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md): existing `MainMenuPane` documentation, retained wrapper evidence, and B014 route scans show direct construction of `HistoryViewingPane` for story/history frame-viewer branches, while `BackStoryDialogPane` is retained as the older `BACKTALE` text dialog and cleaned through the singleton helper if live.

Use [UID:0000RF][g_pMainMenuPane](by-global/g_pMainMenuPane.md) for historical IDA `dword_67ABA4`. [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md) resolves historical `dword_69B36C` as separate `g_mainUiLayerSlots.overlayPaneLayerContext`; never label it `g_pMainMenuPane`.

## Cross-References

- [UID:00000T][BackStoryDialogPane](by-class/BackStoryDialogPane.md)
- [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md)
- [UID:0000Q9][g_pBackStoryDialogPane](by-global/g_pBackStoryDialogPane.md)
- [UID:0001RG][main-menu-story-resources](by-resource/main-menu-story-resources.md)
- [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md)
- [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)
- [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md)
- [UID:0003HH][0x00502390-0x0050239b.BackStoryDialogPaneSingletonBaseDestructor](by-memory/0x00502390-0x0050239b.BackStoryDialogPaneSingletonBaseDestructor.md)
- [UID:0004W8][0x0050245e-0x00502474.BackStoryDialogPaneDestructorAdjustorThunks](by-memory/0x0050245e-0x00502474.BackStoryDialogPaneDestructorAdjustorThunks.md)
- [UID:0004W9][0x00502600-0x00502645.BackStoryDialogPaneScalarDeletingDestructor](by-memory/0x00502600-0x00502645.BackStoryDialogPaneScalarDeletingDestructor.md)
- [UID:0004WA][0x0061da54-0x0061daf0.BackStoryDialogPaneVtableData](by-memory/0x0061da54-0x0061daf0.BackStoryDialogPaneVtableData.md)
- [UID:0004WB][BackStoryDialogPaneVtables](by-type/by-vtable/BackStoryDialogPaneVtables.md)

## Changes

- 2026-07-22 B002 UID00029F accepted callback:
  - Raised `88/89 -> 92/93` and completed the `NexusTK/login/BackStoryDialogPane.cpp` union: sole zero global at position 0, fieldless direct-Singleton class at 10, and exact constructor/`OnControlCommand` bodies at 20.
  - Incorporated real compiler evidence UIDs 0003HH/0004W8/0004W9/0004WA/0004WB, exact size/EBO/vtable/RTTI facts, one-definition handling, generated-output expectations, and current MainUi layer/show-parent names.
  - Preserved the full EPF/EPD/PAL/BACKTALE layout evidence, active HistoryViewing replacement context, no-launcher route exhaustion, and historical raw/compiler interpretations.

- What existed before: the page documented constructor/UI behavior, resources, singleton evidence, and reachability caveats but had unevaluated scores.
- What it was changed to: scores were set to `66/78`.
- Summary and evidence: UI construction and singleton lifecycle are well supported; standalone source placement and live constructor reachability remain medium-confidence.
- 2026-06-01: Raised documentation score to `82/84` and set the projected source folder to `NexusTK/login/`.
  - Before: the file page had a blank validator-managed projected path and confidence stayed below the parent-link threshold because current IDA evidence was only summarized.
  - After: the page has a concrete login folder, exact child UID row for the core range, and refreshed singleton/vtable/resource evidence.
  - Evidence: 2026-06-01 IDA MCP `lookup_funcs`, `callers`, `callees`, `xrefs_to`, `decompile`, `disasm`, and byte checks recorded in [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md).
- 2026-06-06: Cleaned stale recovered-output provenance wording and synchronized the by-file coverage row to the already-recorded `82/84` page score.
  - Evidence: the page already cites IDA-backed [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md), [UID:0000Q9][g_pBackStoryDialogPane](by-global/g_pBackStoryDialogPane.md), resource docs, and main-menu cleanup ownership.
- 2026-06-07 Batch 043 parent-gate refresh:
  - Before: `82/84`; the page had strong constructor/resource evidence but the global parent chain was still under the corrected `85/85` gate.
  - After: `85/86`.
  - Evidence: live IDA MCP reconfirmed the exact singleton storage item and lifecycle xrefs, and the existing core/resource/main-menu docs already document source placement under `NexusTK/login/`. The score remains below final reconstruction because direct constructor reachability is still not observed in current IDA.
- 2026-06-14 C001 Goal 2 file refresh:
  - Before: `85/86`; the class/core pages had newer current-IDB evidence than the by-file page.
  - After: `86/87`; owner/emitter routing and projected path unchanged.
  - Evidence: live IDA MCP session `a001_goal2_class_batch` reconfirmed the constructor/button/destructor-support sizes, empty constructor xrefs, five singleton lifecycle refs, vtable store evidence, and constructor/button callee families. Final C++ stays blank because direct construction and source-quality field/helper names remain unresolved.
- 2026-06-22 Rule 26 incorporation of B014 report `0001A2-BackStoryDialogPaneCore-source-quality`:
  - Before: `86/87`, with direct constructor reachability still described as open/possible indirect construction.
- Historical after-state: `88/89`, retained/compatibility BackStory text-dialog conclusion, active `HistoryViewingPane` route separation, then-current `g_pMainUiGraph`/`dword_69B36C` wording, and first-draft method C++ routed to exact child [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md). The source-facing show parent is now `g_pMainMenuPane`.
  - Evidence: B014 local PE scan found no rel32, VA, or RVA constructor route and no external vtable-head store, while singleton, vtable, destructor-support, cleanup-consumer, `STORY.*`, palette, and `BACKTALE` evidence keeps this file's source ownership intact.
