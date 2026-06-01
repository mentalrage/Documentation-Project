*** UID:00000T | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:66 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BackStoryDialogPane

## Status

- Confidence: strong for UI construction; medium for live reachability.
- Likely source file: [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md)
- Core address range: [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md)
- Current recovered file: `source-3/simroot_v2/class_BackStoryDialogPane.cpp`

## Class Purpose

`BackStoryDialogPane` is a main-menu story text dialog. It displays a story art background and a scrolled text control populated from the `BACKTALE` resource, then closes when its only button is activated.

## Class Shape

- Base family: `DialogPane`-derived main-menu dialog.
- Singleton: live instance tracked by [UID:0000Q9][g_pBackStoryDialogPane](by-global/g_pBackStoryDialogPane.md).
- Resource role: uses EPF/EPD story art plus `BACKTALE` text content, with asset-mode-dependent palette/resource selection.
- Source placement: [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md); live constructor reachability remains less certain than the class layout.

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

## Evidence Notes

- IDA decompilation of `0x00500090` matches the generated constructor layout and resource selection.
- IDA decompilation labels the destructor body through `boost::exception`, but the generated source and vtable context indicate this is type pollution over `DialogPane` teardown.
- IDA MCP `xrefs_to 0x0069b498` on 2026-05-25 confirms the singleton lifecycle: constructor writes it, the clear helper and destructor clear it, and `CloseMainMenuDialogSingletons` reads/closes it.
- Direct constructor xrefs were not found in IDA during this pass; the class may be opened through an indirect path or be a retained older story dialog path.

## Cross-References

- [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md)
- [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md)
- [UID:0000Q9][g_pBackStoryDialogPane](by-global/g_pBackStoryDialogPane.md)
- [UID:0001RG][main-menu-story-resources](by-resource/main-menu-story-resources.md)
- [UID:00007O][MainMenuPane](by-class/MainMenuPane.md)

## Changes

- What existed before: the page documented UI construction, singleton data, and reachability uncertainty but had unevaluated scores.
- What it was changed to: scores were set to `66/78`, and class-shape notes were added for dialog base, singleton, resource role, and source placement.
- Summary and evidence: constructor/resource behavior is clear from IDA decompilation and singleton xrefs; confidence stays medium-high because no direct constructor xref was found in the prior pass.
