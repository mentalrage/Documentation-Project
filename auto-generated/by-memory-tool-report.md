# by-memory Tool Report

- Last generated: 2026-06-22 13:52:00
- Configured binary range: `0x00401000-0x0069d000` (exclusive end)
- Configured binary bytes: 2736128
- Valid 0x range files scanned: 3658
- Manual ranges loaded: 0
- Ignored support files starting with `-`: 8
- Ignored non-Markdown files: 1
- Ignored non-range Markdown files: 0

## Range-Statistics

These percentages are calculated by splitting the configured binary range at every parsed file/manual range boundary, then marking intervals with no covering range as `UNCOVERED`. This checks whether the filename/manual range map covers the configured address space, but it does not read binary bytes, query IDA/MCP, or prove byte-level documentation quality. Broad section-container pages count as coverage here, so treat the result as a cautious map-coverage estimate.

Quick reference:
- `python memory_ranges.py report`
- `python memory_ranges.py set-binary-range 0xSTART 0xEND`
- `python memory_ranges.py mark-not-reconstructable-file <file.md> <type>`
- `python memory_ranges.py mark-not-reconstructable-range 0xSTART 0xEND <type> --file <file.md> --label <label>`
- `python memory_ranges.py mark-padding-range 0xSTART 0xEND --label <label>`
- `python memory_ranges.py mark-other-range 0xSTART 0xEND --label <label>`

Built-in Not-Reconstructable types: `CRT/MSVC`, `third-party-library`, `compiler-generated`, `runtime-support`, `import-thunk`, `static-initializer-wrapper`, `aggregate-container`, `mixed-owner-container`, `duplicate-container`, `vtable-rtti-data`, `resource-data-index`, `dead-unreferenced`

- Not-Reconstructable-Coverage Total: 33.613% (919691 bytes)
  - (untyped): 100.000% of Not-Reconstructable (919691 bytes)
- Reconstructable-Coverage Total: 66.387% (1816437 bytes)
  - no-owner: 0.040% of Reconstructable (728 bytes)
  - emits: 99.948% of Reconstructable (1815491 bytes)
  - non-emits: 0.052% of Reconstructable (946 bytes)
  - multiple-emitters: 0.018% of Reconstructable (332 bytes)
    - has reconstruction code: 11.584% of emits (210306 bytes)
    - no reconstruction code yet: 88.416% of emits (1605185 bytes)
- Padding-And-Zero-Filled(Manual Command): 0.000% (0 bytes)
- Other: 0.000% (0 bytes)
- UNCOVERED(CALCULATED REMAINDER): 0.000% (0 bytes)
- Total Coverage: 100.000% (2736128 bytes)

## Manual-Ranges

These entries come from manual settings in `memory_ranges.data`. They should be treated as operator-provided hints unless the linked file/header evidence confirms them.

Quick reference:
- `python memory_ranges.py mark-not-reconstructable-file <file.md> <type>`
- `python memory_ranges.py mark-padding-file <file.md>`
- `python memory_ranges.py mark-other-file <file.md>`
- `python memory_ranges.py remove-file <file.md>`
- `python memory_ranges.py mark-not-reconstructable-range 0xSTART 0xEND <type> --file <file.md> --label <label>`
- `python memory_ranges.py mark-padding-range 0xSTART 0xEND --label <label>`
- `python memory_ranges.py mark-other-range 0xSTART 0xEND --label <label>`
- `python memory_ranges.py remove-range 0xSTART 0xEND`

- No manual ranges or file classifications are configured.

## Barrier Crossings Errors

These are possible boundary conflicts where two ranges overlap without clean containment. Some may be intentional mixed-owner aggregates, so review the paired pages before treating them as definite errors. Use `mark-as-ignored` only after review to move one justified current crossing into `Ignored-Crossings` with a 50+ character reason.

Quick reference:
- `python memory_ranges.py report`
- `python memory_ranges.py mark-as-ignored 0xPARENT_START-0xPARENT_END 0xCROSSING_START-0xCROSSING_END <50+ char reason>`
- `python memory_ranges.py mark-not-reconstructable-range 0xSTART 0xEND <type> --file <file.md> --label <label>`
- `python memory_ranges.py mark-padding-range 0xSTART 0xEND --label <label>`
- `python memory_ranges.py mark-other-range 0xSTART 0xEND --label <label>`
- `python memory_ranges.py remove-range 0xSTART 0xEND`

- Parent/barrier: `0x0057b020-0x0057b48a` `0x0057b020-0x0057b48a.SoundManagerRedbookPlayback.md` [Not-Reconstructable]
  - Crossing range: `0x0057b3f0-0x0057b48d` `0x0057b3f0-0x0057b48d.SoundManagerRotateReusableSampleSlotRaw.md` [Reconstructable]

## Ignored-Crossings

These are current barrier crossings that were intentionally suppressed with `mark-as-ignored`. The ignore is tied only to the exact numeric parent and crossing ranges. If either filename range changes, the ignore stops matching and the crossing returns to the error list. The command records the reviewed crossing here and requires a reason of at least 50 characters.

Quick reference:
- `python memory_ranges.py mark-as-ignored 0xPARENT_START-0xPARENT_END 0xCROSSING_START-0xCROSSING_END <50+ char reason>`

- Parent/barrier: `0x00591300-0x005954b3` `0x00591300-0x005954b3.TextBoxPaneNoncontiguousAuditMap.md` [Not-Reconstructable]
  - Crossing range: `0x00594e60-0x00595760` `0x00594e60-0x00595760.TextEditSupportObjects.md` [Not-Reconstructable]
  - Reason: Reviewed intentional non-emitting audit-map overlap: exact TextBoxPane and TextEdit support-object children carry source ownership.
- Parent/barrier: `0x00591300-0x005954b3` `0x00591300-0x005954b3.TextBoxPaneNoncontiguousAuditMap.md` [Not-Reconstructable]
  - Crossing range: `0x00594e60-0x005958fe` `0x00594e60-0x005958fe.TextEditSupportObjectsAndFilter.md` [Not-Reconstructable]
  - Reason: Reviewed intentional non-emitting audit-map overlap: broad support/filter map documents split owners while exact child pages carry ownership.
- Parent/barrier: `0x005039f0-0x00504521` `0x005039f0-0x00504521.GameServerNationAndMapInit.md` [Not-Reconstructable]
  - Crossing range: `0x00503ef0-0x0050637a` `0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md` [Reconstructable]
  - Reason: Reviewed intentional non-emitting mixed-owner boundary-index overlap: GameServerNationAndMapInit records the GameServerConfig-to-MapPane transition while the MapPane aggregate carries source ownership.

## General-Errors

These are rule-based validation findings from this tool. They usually indicate something worth checking, but the report cannot prove the project intent without the source page evidence.

Quick reference:
- `python memory_ranges.py report`
- `python memory_ranges.py mark-not-reconstructable-file <file.md> <type>`
- `python memory_ranges.py mark-not-reconstructable-range 0xSTART 0xEND <type> --file <file.md>`

- None.

## Filename-Errors

These are likely filename-format problems for files that looked like range files. They are based only on the naming pattern, so confirm the file purpose before renaming.

Quick reference:
- `python memory_ranges.py report`

- None.

## Largest-Ranges

These are the largest leaf spans after splitting overlapping ranges at known boundaries. They may point to overly broad pages, but large third-party/runtime/data regions can be legitimate.

Quick reference:
- `python memory_ranges.py report`
- `Edit memory_ranges.data: largest_ranges_limit`

- Showing 100 largest leaf ranges (configured limit: 100).
1. `0x00633080-0x0066d000` (237440 bytes) from `0x00632560-0x0066d000` `0x00632560-0x0066d000.MsvcRuntimeReadOnlyDataTail.md` [Not-Reconstructable]
2. `0x005cea6d-0x005f66f7` (162954 bytes) from `0x005cea6d-0x005f66f7` `0x005cea6d-0x005f66f7.MsvcAcrtStdioLocaleMathSupport.md` [Not-Reconstructable]
3. `0x0067adf0-0x0069adf0` (131072 bytes) from `0x0067adf0-0x0069adf0` `0x0067adf0-0x0069adf0.WideCharStrGlobalBuffer.md` [Reconstructable]
4. `0x005f66f7-0x0060c0a0` (88489 bytes) from `0x005f66f7-0x0060c0a0` `0x005f66f7-0x0060c0a0.MsvcSehFuncletIsland.md` [Not-Reconstructable]
5. `0x00406ed1-0x00414283` (54194 bytes) from `0x00401000-0x00414283` `0x00401000-0x00414283.LibJpeg6bCore.md` [Reconstructable]
6. `0x005c5c87-0x005cea43` (36284 bytes) from `0x005c5c87-0x005cea43` `0x005c5c87-0x005cea43.MsvcRuntimeImportAndStlSupport.md` [Not-Reconstructable]
7. `0x00625008-0x0062ce50` (32328 bytes) from `0x00625008-0x0062ce50` `0x00625008-0x0062ce50.ServerPacketNameTable.md` [Reconstructable]
8. `0x00448557-0x00450030` (31449 bytes) from `0x00443a60-0x00450c9f` `0x00443a60-0x00450c9f.LodePngHelperIslandInventory.md` [Not-Reconstructable]
9. `0x006738c0-0x0067a730` (28272 bytes) from `0x006738c0-0x0067a730` `0x006738c0-0x0067a730.CppRttiTypeDescriptorData.md` [Not-Reconstructable]
10. `0x004d4f67-0x004dac40` (23769 bytes) from `0x004d2720-0x004dac40` `0x004d2720-0x004dac40.HumanImageLibLocalMethodCluster.md` [Not-Reconstructable]
11. `0x00424630-0x00428b4b` (17691 bytes) from `0x00424630-0x00428b4b` `0x00424630-0x00428b4b.JsonCppValueCore.md` [Reconstructable]
12. `0x00439ee0-0x0043e0a3` (16835 bytes) from `0x00439ee0-0x0043e0a3` `0x00439ee0-0x0043e0a3.MsvcStlIostreamNumericSupport.md` [Not-Reconstructable]
13. `0x004c8bd0-0x004ccba0` (16336 bytes) from `0x004c8bd0-0x004ccba0` `0x004c8bd0-0x004ccba0.ItemHelpPaneOnPaintFrame.md` [Reconstructable]
14. `0x004361b0-0x00439df9` (15433 bytes) from `0x004361b0-0x00439df9` `0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport.md` [Not-Reconstructable]
15. `0x0042ae90-0x0042e850` (14784 bytes) from `0x0042ae90-0x0042e850` `0x0042ae90-0x0042e850.JsonCppReaderAndBuilderPreludeIsland.md` [Reconstructable]
16. `0x0043e250-0x004417dd` (13709 bytes) from `0x0043e250-0x004417dd` `0x0043e250-0x004417dd.MsvcStlJsonCppStringSupport.md` [Not-Reconstructable]
17. `0x004eb044-0x004ede80` (11836 bytes) from `0x004ea130-0x004efbb7` `0x004ea130-0x004efbb7.InventoryPanes.md` [Not-Reconstructable]
18. `0x00584ea0-0x00587bb0` (11536 bytes) from `0x00584ea0-0x0058af3b` `0x00584ea0-0x0058af3b.SystemMessagePanes.md` [Reconstructable]
19. `0x00532f70-0x00535b10` (11168 bytes) from `0x00532f70-0x0053728e` `0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md` [Reconstructable]
20. `0x004a8ac0-0x004ab3eb` (10539 bytes) from `0x004a8ac0-0x004ab3eb` `0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md` [Reconstructable]
21. `0x005881ed-0x0058aa90` (10403 bytes) from `0x00584ea0-0x0058af3b` `0x00584ea0-0x0058af3b.SystemMessagePanes.md` [Reconstructable]
22. `0x0050bce0-0x0050e320` (9792 bytes) from `0x0050bce0-0x0050e320` `0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md` [Reconstructable]
23. `0x00453df0-0x004563b5` (9669 bytes) from `0x00453df0-0x004563b5` `0x00453df0-0x004563b5.MiniMapRendererAndControls.md` [Reconstructable]
24. `0x00517ec0-0x0051a417` (9559 bytes) from `0x00517ec0-0x0051a417` `0x00517ec0-0x0051a417.TextMenuDialogs.md` [Reconstructable]
25. `0x0056c4c0-0x0056e939` (9337 bytes) from `0x0056c4c0-0x0056e939` `0x0056c4c0-0x0056e939.GroupPanes.md` [Not-Reconstructable]
26. `0x004d2720-0x004d4aca` (9130 bytes) from `0x004d2720-0x004d4aca` `0x004d2720-0x004d4aca.HumanImageLibConstructor.md` [Reconstructable]
27. `0x004461f6-0x00448520` (9002 bytes) from `0x00443a60-0x00450c9f` `0x00443a60-0x00450c9f.LodePngHelperIslandInventory.md` [Not-Reconstructable]
28. `0x00417ba0-0x00419e56` (8886 bytes) from `0x00417ba0-0x00419e56` `0x00417ba0-0x00419e56.ZlibInflateInternals.md` [Reconstructable]
29. `0x0059bc90-0x0059ded0` (8768 bytes) from `0x0059bc90-0x0059f25b` `0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md` [Reconstructable]
30. `0x004c0f80-0x004c3123` (8611 bytes) from `0x004c0f80-0x004c3123` `0x004c0f80-0x004c3123.SoftwareRenderRgb565SpriteBlitCallback.md` [Reconstructable]
31. `0x005bda40-0x005bfbc1` (8577 bytes) from `0x005bda40-0x005bfbc1` `0x005bda40-0x005bfbc1.OldUserStatusPane.md` [Reconstructable]
32. `0x0058e691-0x00590810` (8575 bytes) from `0x0058dce0-0x00591300` `0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane.md` [Reconstructable]
33. `0x00599cc0-0x0059bc2d` (8045 bytes) from `0x00599cc0-0x0059bc8b` `0x00599cc0-0x0059bc8b.UserInfoDialogPane.md` [Reconstructable]
34. `0x0051ca40-0x0051e998` (8024 bytes) from `0x0051ca40-0x0051e998` `0x0051ca40-0x0051e998.SpellMenuDialogs.md` [Reconstructable]
35. `0x00591d60-0x00593c20` (7872 bytes) from `0x00591d60-0x00593c20` `0x00591d60-0x00593c20.TextEditPaneFormattingRunsAndMeasureAdapters.md` [Reconstructable]
36. `0x0052a540-0x0052c325` (7653 bytes) from `0x0052a540-0x0052c325` `0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md` [Reconstructable]
37. `0x00401b00-0x004038c7` (7623 bytes) from `0x00401b00-0x004038c7` `0x00401b00-0x004038c7.LibJpegMarkerReader.md` [Reconstructable]
38. `0x00472c00-0x004748ea` (7402 bytes) from `0x00472c00-0x004748ea` `0x00472c00-0x004748ea.ArticleListDialogCore.md` [Reconstructable]
39. `0x00430092-0x00431d50` (7358 bytes) from `0x00430092-0x00431d50` `0x00430092-0x00431d50.JsonCppWriterTailAndOurReaderPrelude.md` [Reconstructable]
40. `0x0041600e-0x00417b97` (7049 bytes) from `0x00414820-0x00417b97` `0x00414820-0x00417b97.ZlibDeflateAndTrees.md` [Reconstructable]
41. `0x005bab00-0x005bc60c` (6924 bytes) from `0x005bab00-0x005bc60c` `0x005bab00-0x005bc60c.UserStatusPane2.md` [Reconstructable]
42. `0x0046b520-0x0046cfe0` (6848 bytes) from `0x0046b520-0x0046cfe0` `0x0046b520-0x0046cfe0.BrowserControlPaneCore.md` [Reconstructable]
43. `0x0047b220-0x0047cc74` (6740 bytes) from `0x0047b220-0x0047cc74` `0x0047b220-0x0047cc74.MailDialogCore.md` [Reconstructable]
44. `0x00442090-0x00443a55` (6597 bytes) from `0x00442090-0x00443a55` `0x00442090-0x00443a55.JsonCppWriterRuntimeTailSupport.md` [Not-Reconstructable]
45. `0x0052dd30-0x0052f6e5` (6581 bytes) from `0x0052dd30-0x0052f6e5` `0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore.md` [Reconstructable]
46. `0x0057d0af-0x0057ea57` (6568 bytes) from `0x0057cf70-0x0057ea57` `0x0057cf70-0x0057ea57.NewSpellInventoryPaneCoreAndHelpers.md` [Reconstructable]
47. `0x0052c360-0x0052dcf5` (6549 bytes) from `0x0052c360-0x0052dcf5` `0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md` [Reconstructable]
48. `0x00434890-0x004361ae` (6430 bytes) from `0x00434890-0x004361ae` `0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter.md` [Reconstructable]
49. `0x004bee40-0x004c069e` (6238 bytes) from `0x004bee40-0x004c069e` `0x004bee40-0x004c069e.SoftwareRenderCompatBlockTransferCallback.md` [Reconstructable]
50. `0x005a5bd0-0x005a7422` (6226 bytes) from `0x005a5bd0-0x005a7422` `0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent.md` [Reconstructable]
51. `0x004c4790-0x004c5fde` (6222 bytes) from `0x004c4790-0x004c5fde` `0x004c4790-0x004c5fde.SoftwareRenderRgb565BlockTransferCallback.md` [Reconstructable]
52. `0x004753e0-0x00476c0a` (6186 bytes) from `0x004753e0-0x00476c0a` `0x004753e0-0x00476c0a.ArticleDialogCore.md` [Reconstructable]
53. `0x00432e10-0x004345ee` (6110 bytes) from `0x00432e10-0x004345ee` `0x00432e10-0x004345ee.JsonCppSecondParserIsland.md` [Not-Reconstructable]
54. `0x004926a0-0x00493e29` (6025 bytes) from `0x004926a0-0x00493e29` `0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry.md` [Reconstructable]
55. `0x00479110-0x0047a894` (6020 bytes) from `0x00479110-0x0047a894` `0x00479110-0x0047a894.MailListDialogCore.md` [Reconstructable]
56. `0x004f0480-0x004f1bf6` (6006 bytes) from `0x004f0480-0x004f1bf6` `0x004f0480-0x004f1bf6.Layer.md` [Reconstructable]
57. `0x00567480-0x00568bd0` (5968 bytes) from `0x00567480-0x00568bd0` `0x00567480-0x00568bd0.SelfLookPaneOnPaint.md` [Reconstructable]
58. `0x004fb630-0x004fccee` (5822 bytes) from `0x004fb630-0x004fccee` `0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md` [Reconstructable]
59. `0x00565890-0x00566f24` (5780 bytes) from `0x00565890-0x00566f24` `0x00565890-0x00566f24.SelfLookPaneOnReceiveCharacterData.md` [Reconstructable]
60. `0x004b1b90-0x004b3210` (5760 bytes) from `0x004b1b90-0x004b32c9` `0x004b1b90-0x004b32c9.FolderTreePaneCore.md` [Reconstructable]
61. `0x00450ca0-0x00452260` (5568 bytes) from `0x00450ca0-0x0045381b` `0x00450ca0-0x0045381b.MiniMapDialog.md` [Reconstructable]
62. `0x00467b30-0x0046904e` (5406 bytes) from `0x00467b30-0x0046904e` `0x00467b30-0x0046904e.BalloonObjectPane.md` [Reconstructable]
63. `0x00444be0-0x004460f0` (5392 bytes) from `0x00443a60-0x00450c9f` `0x00443a60-0x00450c9f.LodePngHelperIslandInventory.md` [Not-Reconstructable]
64. `0x004ccca0-0x004ce0f6` (5206 bytes) from `0x004ccca0-0x004ce0f6` `0x004ccca0-0x004ce0f6.ItemHelpPanePopulateItemData.md` [Reconstructable]
65. `0x00671a74-0x00672eb4` (5184 bytes) from `0x00671a74-0x00672eb4` `0x00671a74-0x00672eb4.Zlib114DataMessagesAndTables.md` [Reconstructable]
66. `0x004e05c4-0x004e19d0` (5132 bytes) from `0x004dfd10-0x004e4d79` `0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md` [Not-Reconstructable]
67. `0x004298f0-0x0042acdf` (5103 bytes) from `0x004298f0-0x0042acdf` `0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds.md` [Reconstructable]
68. `0x005807d0-0x00581b80` (5040 bytes) from `0x005807d0-0x0058206e` `0x005807d0-0x0058206e.StartupWindowUpdateCheck.md` [Reconstructable]
69. `0x0057779e-0x00578b20` (4994 bytes) from `0x00575d90-0x005797ae` `0x00575d90-0x005797ae.SocketTransportCore.md` [Not-Reconstructable]
70. `0x004bc090-0x004bd3e8` (4952 bytes) from `0x004bc090-0x004bd3e8` `0x004bc090-0x004bd3e8.SoftwareRenderCompatSpriteBlitCallback.md` [Reconstructable]
71. `0x004e3a2e-0x004e4d79` (4939 bytes) from `0x004dfd10-0x004e4d79` `0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md` [Not-Reconstructable]
72. `0x0045239a-0x004536e0` (4934 bytes) from `0x00450ca0-0x0045381b` `0x00450ca0-0x0045381b.MiniMapDialog.md` [Reconstructable]
73. `0x0055c650-0x0055d957` (4871 bytes) from `0x0055c650-0x0055d957` `0x0055c650-0x0055d957.ScrollPaneOnDraw.md` [Reconstructable]
74. `0x004f6a31-0x004f7d10` (4831 bytes) from `0x004f6700-0x004f7d10` `0x004f6700-0x004f7d10.MainMenuPaneCore.md` [Reconstructable]
75. `0x00507c90-0x00508f60` (4816 bytes) from `0x00507c90-0x00508f60` `0x00507c90-0x00508f60.MapPanePacketDispatcher.md` [Reconstructable]
76. `0x004e1f27-0x004e31f0` (4809 bytes) from `0x004dfd10-0x004e4d79` `0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md` [Not-Reconstructable]
77. `0x00563260-0x00564520` (4800 bytes) from `0x00563260-0x0056470c` `0x00563260-0x0056470c.ScrollInventoryPane.md` [Reconstructable]
78. `0x0055f450-0x00560710` (4800 bytes) from `0x0055f450-0x005608fc` `0x0055f450-0x005608fc.ScrollSpellInventoryPane.md` [Reconstructable]
79. `0x006707d4-0x00671a74` (4768 bytes) from `0x006707d4-0x00671a74` `0x006707d4-0x00671a74.LibJpeg6bDataMessagesAndMemoryStrings.md` [Reconstructable]
80. `0x006112fc-0x00612574` (4728 bytes) from `0x006112fc-0x00612574` `0x006112fc-0x00612574.MsvcStlLocaleNameData.md` [Not-Reconstructable]
81. `0x0049662f-0x00497890` (4705 bytes) from `0x00494eb0-0x0049803a` `0x00494eb0-0x0049803a.ButtonChoiceControlCore.md` [Not-Reconstructable]
82. `0x00501150-0x00502383` (4659 bytes) from `0x00501150-0x00502383` `0x00501150-0x00502383.UserCreateAppearanceSelectorControls.md` [Reconstructable]
83. `0x005227d0-0x00523a00` (4656 bytes) from `0x005227d0-0x00524581` `0x005227d0-0x00524581.MetaMan.md` [Reconstructable]
84. `0x00458610-0x00459810` (4608 bytes) from `0x00458610-0x0045f9f5` `0x00458610-0x0045f9f5.RankingDialog.md` [Reconstructable]
85. `0x005b8c70-0x005b9d6a` (4346 bytes) from `0x005b8c70-0x005b9d6a` `0x005b8c70-0x005b9d6a.UserStatusPanePaint.md` [Reconstructable]
86. `0x00551030-0x005520e5` (4277 bytes) from `0x00551030-0x005520e5` `0x00551030-0x005520e5.HeadSelectDialogCore.md` [Reconstructable]
87. `0x00414820-0x004158b0` (4240 bytes) from `0x00414820-0x00417b97` `0x00414820-0x00417b97.ZlibDeflateAndTrees.md` [Reconstructable]
88. `0x00509470-0x0050a4fd` (4237 bytes) from `0x00509470-0x0050a4fd` `0x00509470-0x0050a4fd.MapPaneRenderViewCore.md` [Reconstructable]
89. `0x004639d0-0x00464a52` (4226 bytes) from `0x004639d0-0x00464a52` `0x004639d0-0x00464a52.ApplicationInitialize.md` [Reconstructable]
90. `0x00552110-0x0055317a` (4202 bytes) from `0x00552110-0x0055317a` `0x00552110-0x0055317a.TextDialogConstructor.md` [Reconstructable]
91. `0x0054a4b6-0x0054b4f0` (4154 bytes) from `0x00549c20-0x0054b5d5` `0x00549c20-0x0054b5d5.PowerDialogPane.md` [Reconstructable]
92. `0x00536270-0x0053728e` (4126 bytes) from `0x00536270-0x0053728e` `0x00536270-0x0053728e.ObjectListTierInsertRemoveHelpers.md` [Reconstructable]
93. `0x0059f610-0x005a0626` (4118 bytes) from `0x0059f610-0x005a0626` `0x0059f610-0x005a0626.UserLookPaneParseLookPacket.md` [Reconstructable]
94. `0x005bc96a-0x005bd960` (4086 bytes) from `0x005bc610-0x005c0034` `0x005bc610-0x005c0034.MenuVarietyPanes.md` [Not-Reconstructable]
95. `0x00613ce4-0x00614cd0` (4076 bytes) from `0x00613ab0-0x00614cd0` `0x00613ab0-0x00614cd0.BoardMailReadOnlyData.md` [Not-Reconstructable]
96. `0x0060f4c0-0x006104ac` (4076 bytes) from `0x0060f4c0-0x006104ac` `0x0060f4c0-0x006104ac.LodePngStaticReadOnlyData.md` [Reconstructable]
97. `0x0047d050-0x0047e033` (4067 bytes) from `0x0047d050-0x0047e033` `0x0047d050-0x0047e033.NewMailDialogCore.md` [Reconstructable]
98. `0x0054fb30-0x00550afb` (4043 bytes) from `0x0054fb30-0x00550afb` `0x0054fb30-0x00550afb.MenuQuestionDialogLargerConstructor.md` [Reconstructable]
99. `0x00403920-0x004048e2` (4034 bytes) from `0x00403920-0x004048e2` `0x00403920-0x004048e2.LibJpegCompressApiFrontEnd.md` [Reconstructable]
100. `0x0054e920-0x0054f8dd` (4029 bytes) from `0x0054e920-0x0054f8dd` `0x0054e920-0x0054f8dd.MenuQuestionDialogConstructor.md` [Reconstructable]

## Advanced-Error-Scan

These items MAY have issues such as filenames that no longer match the file contents. This scan reads Markdown text only: it checks whether the filename start/end addresses and label text appear in the document body after configured update/change sections are ignored. It also flags reconstructable filenames that appear to contain generated/decompiler symbols such as `sub_`, `func_`, `dword_`, `DAT_`, or `field_`. The checks are heuristic, so each result is only a review candidate rather than a definitive failure.

- Configured default state: enabled (`advanced_scan.run_by_default`).
- Current report run: advanced scan executed.

Quick reference:
- `python memory_ranges.py report -advanced-scan`
- `python memory_ranges.py -advanced-scan`
- `python memory_ranges.py toggle-advanced-scan-default`
- `Edit memory_ranges.data: advanced_scan.ignore_section_heading_patterns`
- `Edit memory_ranges.data: advanced_scan.generated_name_patterns`

- 0x0046a860-0x0046ad0a.BrowserPaneAndDialog.md: missing document text for BrowserPaneAndDialog
- 0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper.md: missing document text for ButtonControlPaneActiveRefreshHelper
- 0x004b44c0-0x004b451b.FolderTreeDirectoryEntryCompareSwap3.md: missing document text for FolderTreeDirectoryEntryCompareSwap3
- 0x004b5280-0x004b5510.FolderTreeDirectoryEntrySortWrapper.md: missing document text for FolderTreeDirectoryEntrySortWrapper
- 0x0053e420-0x0053e520.OptionPaneApplyServerOptionStates.md: missing document text for OptionPaneApplyServerOptionStates
- 0x00559170-0x005591fc.SurfaceRestoreLostSurfaces.md: missing document text for SurfaceRestoreLostSurfaces
- 0x005a9310-0x005a934a.LivingObjectPaneSetMovementBuffer.md: missing document text for LivingObjectPaneSetMovementBuffer
- 0x005b0290-0x005b050d.TargetObjectWithKeyboardPaneMouseEvent.md: missing document text for TargetObjectWithKeyboardPaneMouseEvent
- 0x006309dc-0x006309f4.UserPaneArrowShortageWarningString.md: missing document text for UserPaneArrowShortageWarningString
- 0x006702c4-0x006702c8.UniAPIInitVtablePointerSlot.md: missing document text for UniAPIInitVtablePointerSlot
- 0x0069b350-0x0069b358.StartupClearedUnusedDwords.md: missing document text for StartupClearedUnusedDwords
