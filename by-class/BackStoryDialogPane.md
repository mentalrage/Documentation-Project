*** UID:00000T | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BackStoryDialogPane

## Status

- Confidence: strong for UI construction, resource selection, singleton lifecycle, and login/main-menu ownership; medium-high for direct live construction.
- Likely source file: [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md)
- Core address range: [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md)
- Current recovered file: `source-3/simroot_v2/class_BackStoryDialogPane.cpp`
- Autogen status: the file page and core memory page are assigned to `NexusTK/login/BackStoryDialogPane.cpp`; this class page stays non-reconstructable until the class declaration, field names, and helper names are final-source quality.

## Class Purpose

`BackStoryDialogPane` is a main-menu story text dialog. It displays a story art background and a scrolled text control populated from the `BACKTALE` resource, then closes when its only button is activated.

## Class Shape

- Base family: `DialogPane`-derived main-menu dialog.
- Singleton: live instance tracked by [UID:0000Q9][g_pBackStoryDialogPane](by-global/g_pBackStoryDialogPane.md).
- Resource role: uses EPF/EPD story art plus `BACKTALE` text content, with asset-mode-dependent palette/resource selection.
- Source placement: [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md) under `NexusTK/login/`; live constructor reachability remains less certain than the class layout.
- Not the active frame story/history viewer: [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md) owns the currently direct `MainMenuPane` story/history construction path, while this class is retained as the older `BACKTALE` text dialog and still participates in singleton cleanup.

## Source Placement And Reachability

The class belongs to the login/main-menu dialog family. The file-level page has the projected source folder `NexusTK/login/`, and [by-project-structure/proposed-source-tree.md](../by-project-structure/proposed-source-tree.md) lists `BackStoryDialogPane` with the main-menu story resources and singleton cleanup path.

Direct code xrefs to the constructor were still absent in the refreshed IDA pass, so this page should not claim a proven live menu-open call. The class is still real project code: its constructor writes the singleton, its destructor support clears it, its button handler is vtable-referenced, and `CloseMainMenuDialogSingletons` reads the singleton during main-menu dialog cleanup.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | `0x00500090-0x005003e3` | Constructs `DialogPane`, stores singleton, installs vtables, selects EPF/EPD layout, adds image/button/text controls, creates/shows/slides the dialog. |
| `HandleButtonClick` | `0x005003f0-0x0050040d` | Closes the dialog when control id `1` is activated. |
| singleton clear helper | `0x00502390-0x0050239b` | Clears [UID:0000Q9][g_pBackStoryDialogPane](by-global/g_pBackStoryDialogPane.md). |
| adjustor thunks | `0x0050245e-0x00502474` | Compiler-generated this-adjustor thunks to the scalar deleting destructor. |
| scalar deleting destructor | `0x00502600-0x00502645` | Clears singleton, calls base `DialogPane` teardown, optionally deletes memory. |

## Data Notes

- [UID:0000Q9][g_pBackStoryDialogPane](by-global/g_pBackStoryDialogPane.md) tracks the live singleton dialog at `0x0069b498`.
- `g_useEpfAssets` selects `STORY.EPF`/`PAL01.PAL` versus `STORY.EPD`/`NPAL8.PAL`.
- `g_pMainMenuPane` is the parent shown in the final `OnShow` call.
- `g_dialogLayoutSentinel` is passed into the `OnCreate`/dialog layout setup call.

## Layout Branches

| Branch | Background | Palette | Background rect | Button rect | Text rect | Dialog position |
| --- | --- | --- | --- | --- | --- | --- |
| EPF asset mode | `STORY.EPF` | `PAL01.PAL` | `0,0,384,341` | id `14`, `169,305,232,329` | `BACKTALE`, `25,56,361,278`, step `50` | `246,150,630,491` |
| legacy asset mode | `STORY.EPD` | `NPAL8.PAL` | `0,0,267,337` | id `14`, `98,287,170,303` | `BACKTALE`, `36,71,228,265`, step `50` | `363,150,630,487` |

## Touched State

| State/resource | Role | Evidence source |
| --- | --- | --- |
| `0x0069b498` / [UID:0000Q9][g_pBackStoryDialogPane](by-global/g_pBackStoryDialogPane.md) | Constructor writes the live singleton; clear helper and destructor clear it; main-menu cleanup reads it. | [UID:00029F][0x0069b498-0x0069b49c.g_pBackStoryDialogPane](by-memory/0x0069b498-0x0069b49c.g_pBackStoryDialogPane.md) and [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md). |
| `this+0x00`, `this+0xa0`, `this+0xa4` | Constructor installs the `BackStoryDialogPane` vtable family. | Core page records constructor vtable writes and vtable data refs around `0x0061da58`/`0x0061daa0`. |
| `byte_66DA97` | Selects EPF versus legacy resource/layout branch. | Core page branch reconstruction and resource xrefs. |
| `dword_69B36C`, `dword_67ABA4` | Dialog create/layout context and parent/show context. | Constructor tail in the core page. |
| `STORY.EPF`, `STORY.EPD`, `PAL01.PAL`, `NPAL8.PAL`, `BACKTALE` | Story background, palette, and scrolled text resources. | [UID:0001RG][main-menu-story-resources](by-resource/main-menu-story-resources.md). |

## Boundary And Support Ranges

| Range | Kind | Notes |
| --- | --- | --- |
| `0x00500090-0x005003e3` | constructor | Main construction and layout branch logic. |
| `0x005003e3-0x005003f0` | alignment | Thirteen `0xcc` bytes between constructor and button handler; recorded in [by-memory/-ignored.md](../by-memory/-ignored.md). |
| `0x005003f0-0x0050040d` | button handler | Closes the dialog only for the expected button id path. |
| `0x0050040d-0x00500410` | alignment | Three `0xcc` bytes before `NewHistoryDialogPaneCore`; recorded in [by-memory/-ignored.md](../by-memory/-ignored.md). |
| `0x00502390-0x0050239b` | singleton clear helper | Clears [UID:0000Q9][g_pBackStoryDialogPane](by-global/g_pBackStoryDialogPane.md). |
| `0x0050245e-0x00502474` | adjustor thunks | Compiler this-adjustor thunks into deleting destructor support. |
| `0x00502600-0x00502645` | scalar deleting destructor | Clears singleton, tears down the `DialogPane` base, optionally deletes memory. |

## Evidence Notes

- IDA decompilation of `0x00500090` matches the generated constructor layout and resource selection.
- IDA decompilation labels the destructor body through `boost::exception`, but the generated source and vtable context indicate this is type pollution over `DialogPane` teardown.
- IDA MCP `xrefs_to 0x0069b498` on 2026-05-25 confirms the singleton lifecycle: constructor writes it, the clear helper and destructor clear it, and `CloseMainMenuDialogSingletons` reads/closes it.
- Refreshed IDA evidence on 2026-06-01 in [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md) records exact function sizes, no direct constructor caller, vtable xrefs, singleton xrefs, branch-specific resource xrefs, callee sets, and raw `0xcc` boundary bytes.
- Direct constructor xrefs were not found in IDA during this pass; the class may be opened through an indirect path or be a retained older story dialog path.

## Open Questions

- Direct live construction remains unresolved. Treat the class as retained project code until a menu-open allocation path or dead-code proof is found.
- Final field names, helper names, and class declaration shape are not source-quality enough for reconstructed C++.
- Destructor support should stay documented as `DialogPane` teardown despite IDA's current `boost::exception` type pollution.

## Cross-References

- [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md)
- [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md)
- [UID:0000Q9][g_pBackStoryDialogPane](by-global/g_pBackStoryDialogPane.md)
- [UID:0001RG][main-menu-story-resources](by-resource/main-menu-story-resources.md)
- [UID:00007O][MainMenuPane](by-class/MainMenuPane.md)
- [UID:0000JW][HistoryViewingPane](by-file/HistoryViewingPane.md)
- [UID:00029F][0x0069b498-0x0069b49c.g_pBackStoryDialogPane](by-memory/0x0069b498-0x0069b49c.g_pBackStoryDialogPane.md)
- [UID:0001A1][0x004ffd80-0x0050008b.HistoryViewingPaneCore](by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md)
- [UID:0001A3][0x00500410-0x00500632.NewHistoryDialogPaneCore](by-memory/0x00500410-0x00500632.NewHistoryDialogPaneCore.md)

## Changes

- What existed before: the page documented UI construction, singleton data, and reachability uncertainty but had unevaluated scores.
- What it was changed to: scores were set to `66/78`, and class-shape notes were added for dialog base, singleton, resource role, and source placement.
- Summary and evidence: constructor/resource behavior is clear from IDA decompilation and singleton xrefs; confidence stays medium-high because no direct constructor xref was found in the prior pass.
- 2026-06-02: Raised the class page from `66/78` to `72/84`.
  - Before: the class page summarized the constructor and singleton but did not carry over the refreshed file/core evidence, layout tables, touched-state evidence, or boundary/support ranges.
  - After: the page records login/main-menu placement, retained reachability caveats, exact EPF/legacy layout branches, singleton/vtable/resource state, padding boundaries, destructor support ranges, and autogen rationale.
  - Evidence: existing IDA-backed [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md), [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md), [UID:00029F][0x0069b498-0x0069b49c.g_pBackStoryDialogPane](by-memory/0x0069b498-0x0069b49c.g_pBackStoryDialogPane.md), and [UID:0001RG][main-menu-story-resources](by-resource/main-menu-story-resources.md).
