*** UID:0000HP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# BackStoryDialogPane

## Status

- Confidence: strong for constructor/UI behavior, singleton lifecycle, resources, and login/main-menu ownership; medium-high for direct constructor reachability.
- Proposed module folder: `login/`
- Proposed source file: `login/BackStoryDialogPane.cpp`
- Current generated source: `source-3/simroot_v2/class_BackStoryDialogPane.cpp`
- Main class: [UID:00000T][BackStoryDialogPane](by-class/BackStoryDialogPane.md)
- Main address doc: [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md)
- Related resources: [UID:0001RG][main-menu-story-resources](by-resource/main-menu-story-resources.md) and [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md)
- Evidence basis: generated `simroot_v2` source, IDA MCP decompilation/string checks, and recovered `CloseMainMenuDialogSingletons_004F69A0.cpp` on 2026-05-24. `wave3.py` was not executed for this pass.

## File Role

`BackStoryDialogPane.cpp` owns an older/main-menu story text dialog. It constructs a modal `DialogPane`, selects EPF or legacy EPD assets, adds an image background, one image button, and a scrolled `BACKTALE` text control, then opens the dialog over `MainMenuPane`.

The class is cleaned by the main-menu singleton cleanup helper alongside login, password, history, bulletin, and server-select dialogs, so it belongs under the login/main-menu source family rather than the in-game map UI.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md) | `0x00500090-0x0050040d` | Constructor, one-button close handler, internal padding, story-dialog resource/layout evidence. |
| singleton clear helper | `0x00502390-0x0050239b` | Clears [UID:0000Q9][g_pBackStoryDialogPane](by-global/g_pBackStoryDialogPane.md); likely vtable/destructor support. |
| adjustor thunks | `0x0050245e-0x00502474` | Compiler this-adjustor thunks to the deleting destructor. |
| scalar deleting destructor | `0x00502600-0x00502645` | Clears singleton, tears down `DialogPane`, optionally deletes. IDA's `boost::exception` type label is decompiler pollution. |
| globals | [UID:0000Q9][g_pBackStoryDialogPane](by-global/g_pBackStoryDialogPane.md), `g_pMainMenuPane`, `g_dialogLayoutSentinel`, `g_useEpfAssets` | Singleton and parent/layout state used during construction and cleanup. |

## Layout Details

EPF asset mode:

- Background image: `STORY.EPF` with `PAL01.PAL`
- Dialog/control rectangle: `0,0,384,341`
- Button id `14`: `169,305,232,329`
- Text control resource: `BACKTALE` at `25,56,361,278`, line/step value `50`
- Dialog position: `246,150,630,491`

Legacy asset mode:

- Background image: `STORY.EPD` with `NPAL8.PAL`
- Dialog/control rectangle: `0,0,267,337`
- Button id `14`: `98,287,170,303`
- Text control resource: `BACKTALE` at `36,71,228,265`, line/step value `50`
- Dialog position: `363,150,630,487`

## Evidence Notes

- IDA MCP confirms real functions at `0x00500090`, `0x005003f0`, `0x00502390`, `0x0050245e`, `0x00502469`, and `0x00502600`.
- IDA string checks confirm `STORY.EPF`, `STORY.EPD`, `PAL01.PAL`, `NPAL8.PAL`, and `BACKTALE` at the expected referenced addresses.
- `CloseMainMenuDialogSingletons_004F69A0.cpp` calls `g_pBackStoryDialogPane->CloseDialog()` if the singleton is live.
- `xrefs_to 0x00500090` found no direct constructor xrefs in the current IDA database. This may be an indirect/vtable allocation path, dead/older dialog path, or a generated-data gap.
- IDA MCP `xrefs_to 0x0069b498` on 2026-05-25 confirms the singleton storage behind [UID:0000Q9][g_pBackStoryDialogPane](by-global/g_pBackStoryDialogPane.md): constructor writes, the clear helper/destructor clear it, and `CloseMainMenuDialogSingletons` reads it.
- 2026-06-01 IDA MCP recheck confirms the core constructor and button handler boundaries, no direct constructor caller, button-handler vtable data at `0x0061daa0`, constructor vtable writes through `0x0061da58`, and singleton xrefs at `0x004f69ce`, `0x005000e5`, `0x005000ec`, `0x00502390`, and `0x00502606`.
- The refreshed core memory page records exact branch-specific layout coordinates, child control allocations (`332`, `276`, `476` byte allocations), resource xrefs for `STORY.EPF`, `STORY.EPD`, and `BACKTALE`, and palette xrefs for `PAL01.PAL` and `NPAL8.PAL`.

## Ownership Notes

Keep [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) as the menu dispatcher/owner of menu selection flow. `BackStoryDialogPane` is a child dialog in the same source family, not the top-level menu controller.

Do not confuse this with [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md): generated `MainMenuPane::ActivateMenuItem` and IDA both show direct construction of `HistoryViewingPane` for story/history frame-viewer branches, while `BackStoryDialogPane` is still present as an older text dialog and cleaned through the singleton helper.

## Cross-References

- [UID:00000T][BackStoryDialogPane](by-class/BackStoryDialogPane.md)
- [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md)
- [UID:0000Q9][g_pBackStoryDialogPane](by-global/g_pBackStoryDialogPane.md)
- [UID:0001RG][main-menu-story-resources](by-resource/main-menu-story-resources.md)
- [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md)
- [UID:0001RF][main-menu-history-resources](by-resource/main-menu-history-resources.md)
- [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md)
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)

## Changes

- What existed before: the page documented constructor/UI behavior, resources, singleton evidence, and reachability caveats but had unevaluated scores.
- What it was changed to: scores were set to `66/78`.
- Summary and evidence: UI construction and singleton lifecycle are well supported; standalone source placement and live constructor reachability remain medium-confidence.
- 2026-06-01: Raised documentation score to `82/84` and set the projected source folder to `NexusTK/login/`.
  - Before: the file page had a blank validator-managed projected path and confidence stayed below the parent-link threshold because current IDA evidence was only summarized.
  - After: the page has a concrete login folder, exact child UID row for the core range, and refreshed singleton/vtable/resource evidence.
  - Evidence: 2026-06-01 IDA MCP `lookup_funcs`, `callers`, `callees`, `xrefs_to`, `decompile`, `disasm`, and byte checks recorded in [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md).
