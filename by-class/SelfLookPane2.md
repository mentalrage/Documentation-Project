*** UID:0000CV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:15 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SelfLookPane2

## Status

- Confidence: strong for class purpose; medium for several projected method starts around `0x00570940-0x00570ac0`.
- Likely source file: [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md)
- Main address range: [UID:0001HK][0x0056fe80-0x005729c3.SelfLookPane2](by-memory/0x0056fe80-0x005729c3.SelfLookPane2.md)
- Current recovered file: `source-3/simroot_v2/class_SelfLookPane2.cpp`

## Class Purpose

`SelfLookPane2` is a sibling self-look panel with three modes: default appearance/equipment, spelled/stat text, and legend text. It handles view switching, toggle-button hit testing, key/mouse input, character/stat rendering, and destructor cleanup for the same child-pane pattern used by `SelfLookPane`.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | `0x0056fe80-0x0057002c` | Initializes `PanelPane`, DAT-backed resource pointer, child `SpelledPane` and `LegendPane`, and compact self-look state. |
| non-deleting destructor | `0x00570030-0x005700d7` | IDA-confirmed cleanup body; currently unknown to Wave3. |
| `OnDraw` | `0x005700e0-0x0057092c` | Main default/spelled/legend draw path. |
| projected toggle helpers | `0x00570940`, `0x00570a00`, `0x00570ac0` | Wave3 models body/face/hair toggle packet helpers here, but IDA does not define function records at these starts. |
| `ShowDefaultView` | `0x00570c00-0x00570c80` | Activates default look view. |
| `ShowSpelledView` | `0x00570c80-0x00570e17` | Activates spelled/stat text view. |
| `ShowLegendView` | `0x00570ef0-0x00570fb3` | Activates legend child view. |
| `OnPaint` | `0x00570fc0-0x00571c05` | Paints panel contents and active child view. |
| `HandleKeyEvent` | `0x00571c10-0x00571cb2` | Handles keyboard navigation/actions. |
| `HandleEvent` | `0x00571cc0-0x005720ff` | Handles mouse/button input. |
| unmodeled event handler | `0x00572120-0x005725ed` | IDA-confirmed packet/event handler similar to `SelfLookPane::0x005693d0`; currently unknown to Wave3. |
| `DrawStatText` | `0x005726a0-0x00572771` | Draws stat labels/values. |
| `GetButtonRect` | `0x00572780-0x00572885` | Computes toggle/action button rectangles. |
| `HitTestButton` | `0x005728a0-0x005729c3` | Maps mouse coordinates to self-look button ids. |
| packet/update helper island | `0x005729e0-0x00572f1f` | [UID:00023X][0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers](by-memory/0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers.md) covers raw packet sends and update parsing immediately after the button hit-test code. |
| text/update helper | `0x00572f30-0x00572fcf` | IDA-confirmed helper updating child text; documented in [UID:00023X][0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers](by-memory/0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers.md). |
| SpelledPane entry-vector helper | `0x00572fd0-0x00573232` | IDA-confirmed helper called from `0x0056bdbc` and `0x0056c26d`; current evidence places it with [UID:0000DK][SpelledPane](by-class/SpelledPane.md) entry storage rather than SelfLookPane2. |
| adjustor thunk | `0x005732c0` | Mixed destructor/thunk island entry. |
| scalar deleting destructor | `0x00573640-0x00573728` | Full class destructor plus conditional delete; documented in [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md). |

## Evidence Notes

- Wave3 reports `SelfLookPane2` grade `97.8` and zero missing refs.
- IDA confirms the constructor, draw/view/input/stat/button functions listed above.
- IDA confirms bytes at `0x00570940`, `0x00570a00`, and `0x00570ac0` look function-prologue-shaped, but no IDA function records or xrefs currently exist at those starts.
- 2026-06-01 IDA MCP recheck confirms the modeled function map through `0x005728a0`, constructor child-pane calls to `SpelledPane` and `LegendPane`, cleanup in `0x00570030`, input-handler calls to the button hit-test helper, view switches, packet builder, and packet sender.
- The current confidence remains below maximum because `0x00570940`, `0x00570a00`, `0x00570ac0`, and the post-range `0x005729e0` helper island are still raw/unmodeled rather than clean IDA function objects.

## Cross-References

- [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md)
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)
- [UID:0001HK][0x0056fe80-0x005729c3.SelfLookPane2](by-memory/0x0056fe80-0x005729c3.SelfLookPane2.md)
- [UID:00023X][0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers](by-memory/0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers.md)
- [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md)
- [UID:0000CU][SelfLookPane](by-class/SelfLookPane.md)
- [UID:0000DK][SpelledPane](by-class/SpelledPane.md)
- [UID:000074][LegendPane](by-class/LegendPane.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Evidence: the page documents the panel purpose, mode-switching behavior, main constructor/destructor/draw/input/stat/button ranges, helper islands, and cross-references; confidence remains capped by projected method starts around `0x00570940-0x00570ac0` that IDA does not currently model as functions.
- Before: the post-`SelfLookPane2` helper area was listed only as loose `0x00572f30` / `0x00572fd0` notes while the coverage report still treated `0x005729c3-0x00573240` as unknown.
- Changed to: the helper island is documented as [UID:00023X][0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers](by-memory/0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers.md), with the destructor body linked through [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md).
- Evidence: 2026-05-28 IDA MCP disassembly showed raw packet/update helper starts at `0x005729e0`, `0x00572a60`, `0x00572ae0`, and `0x00572b60`, plus IDA functions at `0x00572f30`, `0x00572fd0`, and `0x00573640`.
- 2026-06-01: Raised from `84/78` to `86/82`, marked reconstructable, and attached to [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md).
  - C++ remains blank because final helper/field names are not source-quality and the raw helper starts still need later boundary normalization.
