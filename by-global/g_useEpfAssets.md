*** UID:0000SW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000O5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000O5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool g_useEpfAssets = true;
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
extern bool g_useEpfAssets;

[[CHILDREN]]

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_useEpfAssets / byte_66DA97

## UID0000LO MyItemListPane Consumer Link - 2026-08-14

The MyItemListPane constructor and renderer compare `g_useEpfAssets` with
literal one. Constructor selects extent `170` versus `205`; renderer selects
the half-size clipped scaled-image branch versus the full-size legacy branch.
The global remains externally owned and this consumer link changes no metadata,
emitter, score, or storage disposition.

## UID0000L2 MapNamePane Source-Root Consumer - 2026-08-12

- [UID:0000L2][MapNamePane](by-file/MapNamePane.md) is a direct read-only consumer. `MapNamePane::MapNamePane()` gates the `MAPNAME.EPF` and `9X11FONT.BIN` resource path on this byte, while `MapNamePane::OnPaint()` selects the EPF-backed versus glyph-fallback render path from the same process-wide mode.
- `MapNamePane.cpp` uses the source-root declaration `extern bool g_useEpfAssets;` before its method definitions. It does not initialize, write, own, or duplicate the storage, and no evidence-backed neutral shared header is introduced by this callback.
- The sole definition `bool g_useEpfAssets = true;`, guarded declaration in `StartupWindow.h`, canonical owner/emitter UID0000O5, score `88/90`, 366-xref evidence, and one-writer startup lifecycle remain unchanged. The MapNamePane relationship is consumer visibility only.

## UID0003ZT MapPane Source-Root Declaration - 2026-07-23

- This page remains the sole `bool g_useEpfAssets` definition under [UID:0000O5][StartupWindow](by-file/StartupWindow.md); its `88/90` score, owner/emitter, storage, writer, reader, and startup lifecycle evidence are unchanged.
- No evidence-backed shared header basename owns this global. MapPane.cpp therefore uses the exact source-root declaration `extern bool g_useEpfAssets;` before its method definitions instead of inventing a guessed header or duplicating storage.
- [UID:0003ZT][0x00508f60-0x0050902b.MapPaneNotifyMessageCore](by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md) is a direct read consumer: the work-notification branch selects the default or explicit-parent `ConnectionClosedDialog` constructor according to this flag.
- MapPane neither writes nor initializes the flag. StartupWindow.cpp remains the sole definition/initialization owner, and the consumer relationship does not alter global placement.

## ObjectStatusBlob full-parser read

- Full child UID0004LL reads this accepted byte global during nonzero riding-id normalization. When the value is false/legacy mode, the packet riding appearance id at ObjectStatusBlob `+0x2a` is forced to 1 before the `RidableAnimals` metadata query; otherwise the packet id is retained.
- The resulting key drives MetaMan columns 1-3 into definition index, packed palette/render flags, and signed Y offset at `+0x2c/+0x2e/+0x30`. This is a riding/assets compatibility role, not title display gating.
- Existing global owner/emitter, score, address, alias history, and all unrelated consumers remain unchanged.

## UID0003XA External Inverse Query

[UID:0003XA][0x004b60b0-0x004b60bd.IsLegacyAssetMode](by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md) is the exact external source helper for the inverse condition. Its one-block `bool __cdecl()` body is `xor eax,eax; cmp g_useEpfAssets,1; setnz al; retn`, reconstructed as the human-written `return !g_useEpfAssets;`. The helper takes no arguments, has no locals/callees/strings/constants, and does not own or duplicate this storage.

Live B004 caller classification closes all 33 callsites: 26 pass the normalized result as the accepted `TextEditPane` constructor `legacyAssetMode` argument, while seven pass it to `GrafPort::SetFontId(unsigned short)`, where legacy mode is font id `1` and EPF/current mode is font id `0`. The result is therefore a broad asset/resource-mode query rather than a FontImageLib, GrafPort, TextEditPane, attachment, or pane-local flag.

The single external helper address and cross-family calls require one source definition plus one shared declaration. This by-global page remains the sole `g_useEpfAssets` definition and semantic owner; its CPP `[[CHILDREN]]` emits the helper body, and its complete guarded H channel now emits `extern bool g_useEpfAssets;` followed by the helper declaration through H `[[CHILDREN]]`. The exact original global/helper spelling and historical translation-unit filename remain inferred.


## Status

- Confidence: strong for address, one-byte storage, initial value, broad mode-selector role, and `StartupWindow.cpp` as the best existing source-owner inference; exact original name remains unknown.
- Address: `0x0066da97`
- Exact memory: [UID:0001OH][0x0066da97-0x0066da98.g_useEpfAssets](by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md).
- Dated 2026-08-13 IDA readback: `g_useEpfAssets`, type `bool`, at `[0x0066da97,0x0066da98)`. The former `byte_66DA97` rendering is retained below as a historical raw IDA label, not the current dated name or source spelling.
- Generated aliases observed: `g_useEpfAssets`, `g_useHighResLayout`, `g_uiLayoutMode`, `g_attachmentModeFlag`
- Best source-owner inference: [UID:0000O5][StartupWindow](by-file/StartupWindow.md), because the only write is the startup-window constructor's pre-update policy force before normal application startup. The byte remains a process-wide extern-style mode selector, not a `StartupWindow` class field or pane-local flag.

## Purpose

This byte selects between the current EPF/high-layout UI asset path and the older legacy EPD/layout path. It is widely read by UI, render, dialog, and map-overlay code.

Use `g_useEpfAssets` as a readable documentation alias until the original symbol is recovered. Treat narrow generated aliases such as `g_attachmentModeFlag` as local misnamings when the same address is used outside that subsystem.

## Evidence Notes

- Historical IDA snapshots before the accepted source-quality naming pass reported the raw symbol `byte_66DA97` at `0x0066da97`; the exact dated observations below remain evidence for address, storage, xrefs, and behavior rather than current naming authority.
- Read-only MCP snapshot `supervisor-uid0002OW-gate2b-20260813T0115Z` reported exact item `[0x0066da97,0x0066da98)`, source-facing name `g_useEpfAssets`, type `bool`, initialized true, 366 xrefs, blank regular address comment, and the existing detailed repeatable source-quality comment. This is dated evidence; fresh Gate readback controls any later IDA action.
- IDA data inspection on 2026-05-26 reports a one-byte item initialized to `1`.
- IDA MCP `py_eval` on 2026-05-24, 2026-05-25, and 2026-05-26 found 366 xrefs to this byte.
- IDA MCP decompilation of [UID:0000O5][StartupWindow](by-file/StartupWindow.md) constructor `0x005807d0` shows `byte_66DA97 = 1`.
- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md) uses the byte as the main new/legacy layout selector.
- [UID:0000JX][HourPane](by-file/HourPane.md) uses `byte_66DA97 == 1` for `TIME.EPF`/`TIME.PAL`, and the else branch for `TIME.EPD`.
- [UID:0000HO][BackPane](by-file/BackPane.md) uses the byte to choose `FRAME.PAL` versus `NPAL5.PAL`.
- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)'s detach registry helper only clears the type-8 attachment slot in `byte_66DA97 == 1` mode.
- [UID:0000DZ][StartupWindow](by-class/StartupWindow.md) currently documents the constructor as forcing this mode byte to `1`.
- 2026-05-31 IDA MCP `py_eval` recheck confirms `0x0066da97` is a one-byte `.data` item named `byte_66DA97`, initialized to `1`, with 366 data xrefs. The only exact write found is `StartupWindow__Constructor` at `0x005807f3`, while sample reads compare the byte against `1` across early UI/resource/render paths.
- 2026-06-06 IDA MCP `py_eval` reconfirms the same one-byte item, initial value `1`, and 366 data xrefs. The local neighborhood bytes at `0x0066da90-0x0066daa2` are `01 00 00 00 00 04 01 01 00 03 00 00 30 00 00 00 30 00`, keeping this byte distinct from `g_fpsDebugActive`, `g_screenWidth`, [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md), and `g_screenHeight`.
- Representative 2026-06-06 xrefs include `0x004cf020` in HourPane resource selection, `0x004f7d40` and `0x004f8aaf` in `InitializeMainUiGraph`, `0x0053aee5` in attached-object detach cleanup, `0x00574de0` in the send-position helper, `0x005807f3` in `StartupWindow__Constructor`, `0x00598b50` in TimerPane digit drawing, `0x005ae3bf` and `0x005b7c5f` in spell-input cleanup, and `0x005c12ea` in weather-layer construction.
- 2026-06-07 A004 IDA MCP `py_eval` reconfirmed bytes `01 00 00 00 00 04 01 01 00 03 00 00 30 00 00 00 30 00 00 00 68 02 00 00` at `0x0066da90-0x0066daa8`, `byte_66DA97` item size `1`, value `1`, `366` xrefs across `248` functions, predecessor boundary [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md), and successor boundary [UID:0000ST][g_screenHeight](by-global/g_screenHeight.md).
- 2026-06-11 A003 IDA MCP `py_eval` reclassified every xref operand and again found `366` xrefs across `248` functions, `0` unknown operand refs, and exactly one write: `0x005807f3` inside `StartupWindow__Constructor`, `mov byte_66DA97, 1`. The same pass found no xrefs in the documented `ApplicationLifecycle` range `0x00463310-0x004679bf`, no xrefs in the `ApplicationStartupBaram` range `0x004f5f20-0x004f66fb`, and no xrefs in the `Config`/`RegistryConfig` cluster `0x0048e310-0x004941d6`.
- 2026-06-11 decompilation shows `_WinMain@16` constructs `Application` first, then allocates/constructs `StartupWindow`, whose constructor writes this byte before `StartupWindow__RunUpdateCheck`; the constructor also stores `g_pStartupWindow` and the vtable. That makes `StartupWindow` the only observed setter, but still does not prove the source declaration lived in `StartupWindow.cpp`.
- 2026-06-11 B001-043 live IDA MCP recheck reconfirmed `.data` storage at `0x0066da97`, one-byte item size, initial byte `1`, local bytes `01 00 00 00 00 04 01 01 00 03 00 00 30 00 00 00 30 00 00 00 68 02 00 00`, `366` total xrefs, `365` reads, `1` write, and no unknown operand refs. The only write remains `0x005807f3`, `mov byte_66DA97, 1`, inside `StartupWindow__Constructor`; the recheck again found `0` hits in the documented Application lifecycle, Application startup, WinMain, and Config/Registry ranges, while `InitializeMainUiGraph` has two read refs.
- B001-043 assigns this by-global page upward to [UID:0000O5][StartupWindow](by-file/StartupWindow.md) as the best existing source-owner inference. This is an inference from the only setter and startup call order, not recovered source spelling or proof that the original declaration was class-local.
- The exact storage child [UID:0001OH][0x0066da97-0x0066da98.g_useEpfAssets](by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md) is documented here as the direct one-byte storage evidence anchor after both child and parent reached the corrected `85/85` gate.
- 2026-06-17 B001 FontImageLib source-quality research found [UID:0003XA][0x004b60b0-0x004b60bd.IsLegacyAssetMode](by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md), a short helper that returns `byte_66DA97 != 1`. It is routed here because the helper only queries this global and is not a FontImageLib, GrafPort, ImageLib, or DATArchive method.
- 2026-06-20 B004 [UID:0003UT][0x005abda0-0x005abee8.UserPaneHandleUIPanelSwitchPacket](by-memory/0x005abda0-0x005abee8.UserPaneHandleUIPanelSwitchPacket.md) source-quality sync documents another direct consumer: opcode `0x3e` UI-panel switch handling compares this byte to `1` before choosing the EPF/current action table at `0x005abee8` or the legacy action table at `0x005abf0c`. The global is a layout/asset-mode dependency for that packet handler, not `LivingObjectPane` ownership evidence for this storage.
- 2026-06-26 B006 [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md) source-quality implementation adds another direct read consumer: `EmotionInputPane::OnCharInput` compares `byte_66DA97` / `g_useEpfAssets` with `1` at `0x005b2a99`. The current branch uses [UID:0002WV][g_pChattingViewport](by-global/g_pChattingViewport.md) and SystemMessagePane helpers for the `?` emotion menu; the else branch uses [UID:0003ED][g_pOldSystemMessagePane](by-global/g_pOldSystemMessagePane.md) and OldSystemMessagePane helpers. This is read-consumer evidence for the existing broad EPF/current-vs-legacy selector role only and does not alter [UID:0000O5][StartupWindow](by-file/StartupWindow.md) owner/emitter inference.
- 2026-06-26 B002 [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md) split implementation adds user-list consumers: [UID:00047H][0x0059e710-0x0059e899.UserListPaneConstructor](by-memory/0x0059e710-0x0059e899.UserListPaneConstructor.md) selects `STAR.EPF`/`ICON.EPF` versus `STAR.EPD`/`ICON.EPD` resource paths through this byte, and [UID:00047Q][0x0059ed60-0x0059ee0c.UserListPaneOpenSayToUserMessageInputPane](by-memory/0x0059ed60-0x0059ee0c.UserListPaneOpenSayToUserMessageInputPane.md) chooses the new versus legacy direct-message input pane constructor through the same EPF/current-vs-legacy selector. These are read-consumer evidence only and do not alter [UID:0000O5][StartupWindow](by-file/StartupWindow.md) owner/emitter inference.

## Naming Rule

When a recovered source file emits a new global name for this address, normalize the documentation to this page and record the alias only as generated-source evidence.

Known misleading aliases:

| Alias | Problem |
| --- | --- |
| `g_useHighResLayout` | Common in current `simroot_v2`, but it narrows the byte to layout geometry and can mislead branch labels; the same address also selects EPF/EPD resources and render callbacks. |
| `g_attachmentModeFlag` | Observed again on 2026-05-25 in `class_AttachedObjectPaneHelper_53AEC0.cpp`; the byte has hundreds of non-attachment xrefs. |
| `g_uiLayoutMode` | Captures layout behavior but does not capture the repeated EPF/EPD asset selection branches. |

2026-05-26 recheck: `simroot_v2/class_AttachedObjectPaneHelper_53AEC0.cpp` still emits `g_attachmentModeFlag`, but IDA still reports broad cross-subsystem xrefs. Keep normalizing that alias to this page.

## Source Ownership

`CANONICAL_OWNER` and `EMITTER_UIDS` are set to [UID:0000O5][StartupWindow](by-file/StartupWindow.md). This is the best defensible existing source-owner inference under the B001-043 audit, not recovered original declaration metadata.

The decisive positive evidence is the writer and lifecycle path: the sole write among `366` xrefs is `0x005807f3` in `StartupWindow__Constructor`, and `_WinMain@16` calls `Application__Constructor`, then `StartupWindow__Constructor`, then `StartupWindow__RunUpdateCheck`, before normal `Application::Startup`. That places the hard-coded current-layout force in startup/update-window policy rather than in a later UI consumer.

2026-07-01 B008 implementation accepts `bool g_useEpfAssets = true;` as the best current source-facing declaration. This preserves the one-byte initialized value `1`, the sole constructor write, and the broad process-wide read role while keeping confidence capped for unrecovered original spelling/type.

The assignment is intentionally file-level, not class-field ownership. The read set spans startup logo, main UI graph selection, pane resource selection, attached-object cleanup, input/dialog state cleanup, packet-send side effects, and weather/map/layer construction. Those broad reads prove process-wide extern-style visibility and reject pane/render consumer ownership, but they do not outweigh the single startup policy writer. `Application.cpp` and `Config`/`RegistryConfig` remain rejected because live xref classification found no direct refs in their documented ranges; `MainUiGraph.cpp` is a major consumer with two reads, not a setter or declaration-side owner. A new `ClientAssetModeGlobals.cpp`/`DisplayModeGlobals.cpp` file is also rejected for now because the nearby initialized globals already have stronger owners and no other source items form a coherent new file with this byte.

Physical adjacency of UID0003XA to FontImageLib functions remains valid linker/object-order counter-evidence, but it does not override the helper's sole dependency on this global, the lack of FontImageLib state access, or the absence of FontImageLib calls to the helper. The current [UID:0000O5][StartupWindow](by-file/StartupWindow.md) route is the least-invented source topology because it already owns the singular definition and the only observed write; it is not asserted as recovered proof of the original declaration filename.

## Score Rationale

Completion is raised to 88 because the page now documents exact storage, initial byte value, 366-ref count, 248-function spread, neighboring global boundaries, representative cross-subsystem consumers, alias normalization, exact memory-child relationship, rejected owners, and the B001-043 `StartupWindow.cpp` owner inference.
Confidence remains 90 because fresh IDA MCP confirms the one-byte storage, strict boundary, initialization value, broad EPF/current-layout selector role, sole writer, and negative Application/Config evidence. It remains below final-source quality because the original source name and emitted declaration syntax are still unresolved, and source-file ownership is inferred from binary behavior rather than debug/source metadata.

## Cross-References

- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)
- [UID:0001QJ][client_old_redering_mode](by-meta/client_old_redering_mode.md)
- [UID:0001OH][0x0066da97-0x0066da98.g_useEpfAssets](by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md)
- [UID:0003XA][0x004b60b0-0x004b60bd.IsLegacyAssetMode](by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md)
- [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md)
- [UID:0000HO][BackPane](by-file/BackPane.md)
- [UID:0000JX][HourPane](by-file/HourPane.md)
- [UID:0001DF][0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane](by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md)

## Changes

- 2026-08-17 B007 UID0000PA StartupWindow header-tail closure:
  - Preserved the existing `bool g_useEpfAssets = true;` definition, its exact one-byte storage behavior, sole constructor write, render consumers, and StartupWindow ownership.
  - Removed only the duplicate guard opener from this later-positioned H fragment. [UID:0000DZ][StartupWindow](by-class/StartupWindow.md) now opens and supplies the complete class declaration; this global appends `extern bool g_useEpfAssets;`, preserves its helper children, and closes that same guard.
  - This avoids hiding the class behind an already-completed guard and does not move the global to Application, Config, or a display-mode globals file. Those older alternatives remain weaker because the sole write is in the StartupWindow constructor and no direct Application/Config ownership route exists.

- 2026-08-13 B001 UID00047Q accepted implementation callback:
  - Preserved `88/90`, owner/emitter UID0000O5, the sole bool definition and guarded extern/helper H route, exact one-byte initialization, 366-xref/one-write evidence, source-owner analysis, all consumers, and all prior dated raw-name history.
  - Replaced only the active stale `IDA name: byte_66DA97` status with the dated current `g_useEpfAssets` / `bool` readback; retained every older `byte_66DA97` observation as explicitly historical evidence.
  - Reconciled UID00047Q's consumer role to `UserListPane::OnItemActivated`, which selects modern versus legacy direct-message construction without transferring ownership of this process-wide global.

- 2026-08-12 B003 UID0000L2 support sync:
  - Preserved `88/90`, owner/emitter UID0000O5, the sole CPP definition, guarded StartupWindow H declaration, and all existing consumers/history.
  - Added MapNamePane constructor/paint reads and the exact source-root `extern bool g_useEpfAssets;` route without transferring ownership or creating duplicate storage.

- 2026-08-01 B004 UID0003XA accepted source-quality callback:
  - Retained `88/90`, canonical owner/emitter [UID:0000O5][StartupWindow](by-file/StartupWindow.md), singular CPP definition `bool g_useEpfAssets = true;`, and CPP child expansion.
  - Added UID0003XA's exact 13-byte inverse-query body, bool ABI, complete 33-call/26-7 TextEditPane-GrafPort semantic split, external-linkage/no-duplicate route, and FontImageLib/consumer/new-utility rejection evidence without pruning the existing 366-xref/365-read/one-write history.
  - Replaced only the formal H payload with the complete `NEXUSTK_APP_STARTUPWINDOW_H` guard, `extern bool g_useEpfAssets;`, H `[[CHILDREN]]`, and closing guard so UID0003XA's declaration emits through the same source root.

- 2026-06-12 B001-FB-002 ApplicationLifecycle endpoint sync:
  - What existed before: the negative xref evidence referenced the old `ApplicationLifecycle` aggregate range ending at `0x004679be`.
  - Changed to: updated that range mention to the corrected exclusive endpoint `0x004679bf`.
  - Summary/evidence: live IDA MCP confirms [UID:0000YR][0x00463310-0x004674ed.ApplicationLifecycle](by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md) now ends after [UID:0002GX][0x00467960-0x004679bf.ApplicationSendShutdownMessage](by-memory/0x00467960-0x004679bf.ApplicationSendShutdownMessage.md); `0x004679bf` itself is not a function byte, so the previous no-xref ownership rejection remains valid.
- 2026-06-17 B001 FontImageLib source-quality execution:
  - Score remains `88/90`.
  - Added [UID:0003XA][0x004b60b0-0x004b60bd.IsLegacyAssetMode](by-memory/0x004b60b0-0x004b60bd.IsLegacyAssetMode.md) as a helper routed through this global.
  - Summary/evidence: the helper's body is `xor eax,eax; cmp byte_66DA97,1; setnz al; retn`, with broad UI/render callers. The best source-facing name remains inferred/descriptive until the display-mode naming pass resolves original spelling.
- 2026-06-20 B004 [UID:0003UT][0x005abda0-0x005abee8.UserPaneHandleUIPanelSwitchPacket](by-memory/0x005abda0-0x005abee8.UserPaneHandleUIPanelSwitchPacket.md) support sync:
  - Added the opcode `0x3e` UI-panel switch handler as a consumer that selects EPF/current versus legacy action tables from this global while leaving owner/emitter routing unchanged.

- 2026-06-26 B006 EmotionInputPane support sync:
  - Scores remain `88/90`; owner/emitter [UID:0000O5][StartupWindow](by-file/StartupWindow.md) and blank formal C++ are preserved.
  - Added [UID:0001M3][0x005b29c0-0x005b2f68.EmotionInputPane](by-memory/0x005b29c0-0x005b2f68.EmotionInputPane.md) as a read consumer that selects the current SystemMessagePane menu path versus the legacy OldSystemMessagePane menu path.

- 2026-06-26 B002 user-list split support sync:
  - Scores remain `88/90`; owner/emitter [UID:0000O5][StartupWindow](by-file/StartupWindow.md) and blank formal C++ are preserved.
  - Added user-list read consumers [UID:00047H][0x0059e710-0x0059e899.UserListPaneConstructor](by-memory/0x0059e710-0x0059e899.UserListPaneConstructor.md) and [UID:00047Q][0x0059ed60-0x0059ee0c.UserListPaneOpenSayToUserMessageInputPane](by-memory/0x0059ed60-0x0059ee0c.UserListPaneOpenSayToUserMessageInputPane.md) for EPF/EPD resource selection and new/legacy direct-message input pane selection.

- 2026-07-01 B008 accepted StartupWindow implementation:
  - Formal C++ changed from blank to `bool g_useEpfAssets = true;` plus `[[CHILDREN]]`.
  - Evidence remains the single startup constructor write at `0x005807f3`, initialized byte value `1`, `366` total xrefs, rejected Application/Config/MainUiGraph/pane ownership, and [UID:0000O5][StartupWindow](by-file/StartupWindow.md) as best source-file owner.

- 2026-05-31 reconstruction metadata and grading:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, and blank `RECONSTRUCTABLE`.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:84`, and `RECONSTRUCTABLE:TRUE`, with parent left blank.
  - Summary/evidence: IDA MCP reconfirms the one-byte storage, initial value, wide xref set, and StartupWindow write. Parent/source-file attachment remains open because the global is a broad UI asset-mode selector rather than clear ownership by a single pane or subsystem file.
- 2026-06-06 A008 alias/source-owner refresh:
  - What existed before: the page documented the broad role but did not record current representative xrefs or an explicit source-owner decision.
  - Changed to: `84/88`, added current IDA item/neighborhood/xref evidence, and kept parent blank.
  - Summary/evidence: live IDA MCP reconfirmed 366 xrefs and representative users across startup, UI graph, HourPane, attached-object, packet-send, TimerPane, spell-input, and weather/layer paths. The broad spread supports normalizing aliases to `g_useEpfAssets` while leaving original owner/name unresolved.
- 2026-06-07 A004 Batch 027:
  - Before: score `84/88`, just below the corrected assignment gate.
  - Changed to: score `86/90`, added fresh IDA MCP neighborhood/xref/function-spread evidence, and recorded [UID:0001OH][0x0066da97-0x0066da98.g_useEpfAssets](by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md) as the exact assigned memory child.
  - Boundary: this by-global page remains unassigned upward because `StartupWindow` is only the observed writer and the read set is too broad for a source-file owner decision.
- 2026-06-07 A001 Batch070 coverage-error repair:
  - Kept score `86/90` and changed the memory-child wording from active autogen assignment to direct by-global evidence anchor.
  - Validation continued to report generated memory coverage error `autogen_parent_unknown` for `0001OH -> 0000SW`; matching neighboring one-byte global repairs, the exact memory child now leaves `AUTOGEN_PARENT_UID` blank until by-global parents are supported or a direct source-file owner is proven.
- 2026-06-11 A003 normal assignment owner audit:
  - Score remains `86/90`; `AUTOGEN_PARENT_UID` remains blank.
  - Evidence: live IDA MCP `py_eval` reclassified all `366` xrefs and found exactly one write, `0x005807f3` in `StartupWindow__Constructor`, with no direct xrefs in the documented Application lifecycle/startup ranges or the Config/RegistryConfig cluster. `_WinMain@16` constructs `Application` before `StartupWindow`, then the startup-window constructor forces this byte to `1` before update-check handling.
  - Ownership decision: the pass rejects `Application.cpp` and config as evidence-backed parents and keeps `StartupWindow` as the sole setter/consumer-context owner, not as a proven declaration owner. The global remains reviewed at `85/85+` but source-file ownership is still unknown.
- 2026-06-11 B001-043 owner inference execution:
  - Changed score from `86/90` to `88/90` and set `AUTOGEN_PARENT_UID:0000O5`.
  - Evidence: live IDA MCP reconfirmed `.data` one-byte storage, value `1`, `366` xrefs, `365` reads, one write at `0x005807f3`, and zero direct refs in the documented Application lifecycle/startup, WinMain body, and Config/Registry ranges. `_WinMain@16` calls `Application__Constructor`, then `StartupWindow__Constructor`, then `StartupWindow__RunUpdateCheck`, placing the write in pre-application-startup policy.
  - Ownership decision: [UID:0000O5][StartupWindow](by-file/StartupWindow.md) is the best existing source owner. `Application`, `Config`, `MainUiGraph`, pane/render consumers, and a new standalone display-mode globals file are weaker under current evidence.
