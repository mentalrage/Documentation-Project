*** UID:0000OE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/social/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# SystemMessagePanes

## Status

- Completion/confidence: `91/92`; the SystemMessage entry hierarchy, exact
  common defaults, concrete override matrix, class source order, and compiler
  exclusions are now source-ready, while unrelated pane-body partitions and
  the broader split from `social/Chatting.cpp` retain their existing caveats.
- Proposed module folder: `social/`
- Candidate file: `social/SystemMessagePanes.cpp`
- Current validator-generated source: `auto-generated/NexusTK/social/SystemMessagePanes.cpp`.
- Historical `simroot_v2` split outputs included `class_SystemMessagePane.cpp`,
  `class_OldSystemMessagePane.cpp`, `class_NewSystemMessagePane.cpp`,
  `class_NewSystemMessageModifyHeightPane.cpp`,
  `class_ColorStringSystemMessage.cpp`, `class_HeaderSystemMessage.cpp`, and
  `class_FooterSystemMessage.cpp`; those filenames are evidence-time
  partitioning artifacts, not the current validator-generated route.
- Evidence basis: Wave3 class inspection, `simroot_v2` generated source, historical Wave2 notes that called the `0x00588d50` wrapper `RefreshWorldMapPane`, targeted IDA MCP checks on 2026-05-23 and 2026-05-25, and the 2026-07-15 UID0003UN callback correction to the directly evidenced `RefreshSpelledPane` identity.
- Executable range [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md) is a non-emitting split index, not a file-level source body. This file page remains the source owner for class-level reconstruction and support-data placement.

## Hypothesis

The system-message panes form a small chat/session viewport source family. They own scrollable system-message content, high/normal-resolution rendering, help shortcut handling, old/new system-message panel variants, and the new-client wrapper that rebuilds its child message panes.

Likely structure:

```text
social/SystemMessagePanes.cpp
```

Possible compact structure:

```text
social/Chatting.cpp
```

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md) | `0x00584ea0-0x0058af3b` | no generated source | Non-emitting physical index over the SystemMessagePanes class islands, interleaved ForcedInformMessageDialog exclusions, singleton clear helpers, destructor adjustors, and successor-boundary padding. |
| `SystemMessagePane` | `0x00584ea0-0x0058783e`, `0x0058ab33-0x0058ab49`, `0x0058af00-0x0058af3b` | `class_SystemMessagePane.cpp` | Scrollable system-message viewport with high-resolution dynamic lines and normal-resolution EPF tile slots. These are class-owned spans inside the split index, not a claim that the whole index emits as this class. |
| [UID:0004SZ][SystemMessage](by-class/SystemMessage.md) | exact child [UID:000246][0x0058af40-0x0058af48.SystemMessageGetLineCount](by-memory/0x0058af40-0x0058af48.SystemMessageGetLineCount.md), plus folded defaults | this file | Fieldless abstract LObject-derived message-entry base; owns false marker defaults, pure clone contract, exact one-line count child, and no-op draw default. |
| [UID:000061][HeaderSystemMessage](by-class/HeaderSystemMessage.md) | `0x00587890-0x005878ff`, plus shared scalar/folded slots | this file | Four-byte SystemMessage-derived marker; overrides only true header predicate and clone, inheriting false footer, one-line count, and no-op draw. |
| [UID:00005D][FooterSystemMessage](by-class/FooterSystemMessage.md) | `0x00587900-0x0058796f`, plus shared scalar/folded slots | this file | Four-byte SystemMessage-derived marker; overrides only true footer predicate and clone, inheriting false header, one-line count, and no-op draw. |
| [UID:000030][ColorStringSystemMessage](by-class/ColorStringSystemMessage.md) | `0x00587970-0x00587ba4`, `0x0058ab50-0x0058abe7`, plus folded false predicates | this file | Complete 16-byte SystemMessage-derived colored entry with owned UTF-16 text, color, style, clone, measured/clamped line count, draw, and cleanup contracts; bodies remain on exact method children. |
| `NewSystemMessageModifyHeightPane` | `0x005881f0-0x0058855b`, `0x0058aaa0`, `0x0058acc0-0x0058ad1e` | `class_NewSystemMessageModifyHeightPane.cpp` | Drag handle for resizing/persisting the newer system-message panel height. |
| `NewSystemMessagePane` | `0x00588560-0x0058adab` | `class_NewSystemMessagePane.cpp` plus misfiled constructor in `class_NewSystemMessageModifyHeightPane.cpp` | New-client system-message panel wrapper that rebuilds child panes, refreshes its embedded SpelledPane through [UID:0004R2][0x00588d50-0x00588d6e.NewSystemMessagePaneRefreshSpelledPane](by-memory/0x00588d50-0x00588d6e.NewSystemMessagePaneRefreshSpelledPane.md), and draws the tiled panel background. Its constructor calls [UID:0004N5][0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries](by-memory/0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries.md) with its embedded child, zeroed fixed text buffer, and zero length. |
| new-system-message vtable data | [UID:0003GM][0x0062d7b0-0x0062d838.NewSystemMessageModifyHeightPaneVtableData](by-memory/0x0062d7b0-0x0062d838.NewSystemMessageModifyHeightPaneVtableData.md), [UID:0003GN][0x0062d838-0x0062d8c4.NewSystemMessagePaneVtableData](by-memory/0x0062d838-0x0062d8c4.NewSystemMessagePaneVtableData.md) | read-only data | Exact class-owned vtable children split from the former mixed `0x0062d7b0-0x0062d8c4` island and routed through the two direct class parents after they cleared the strict gate. |
| `OldSystemMessagePane` | `0x00588e30-0x0058af00` | `class_OldSystemMessagePane.cpp` | Legacy scrollable system-message pane with fixed 12-pixel rows, separators, clip-region drawing, and message collection destruction. |
| direct-use help resource literal | [UID:0003GP][0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString](by-memory/0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString.md) | this file | Exact UTF-16 `HELP.RES` literal plus two-byte alignment. The source tokens are direct `L"HELP.RES"` operands at both `HasDATEntry` and `DATFile::Open` calls in each current/old help loader; the compiler pools them into one observed object, and UID0003GP emits only the no-standalone disposition marker. |
| resource pointer tables | [UID:0002AP][0x0069bc18-0x0069bdf8.SystemMessageResourcePointerTables](by-memory/0x0069bc18-0x0069bdf8.SystemMessageResourcePointerTables.md) | writable data | Two `0xf0`-byte resource/string pointer tables initialized by `SystemMessagePane::LoadHelpMessages` and `OldSystemMessagePane::LoadHelpMessages`; split into [UID:0002ZV][0x0069bc18-0x0069bd08.SystemMessagePaneResourcePointerTable](by-memory/0x0069bc18-0x0069bd08.SystemMessagePaneResourcePointerTable.md) and [UID:0002ZW][0x0069bd08-0x0069bdf8.OldSystemMessagePaneResourcePointerTable](by-memory/0x0069bd08-0x0069bdf8.OldSystemMessagePaneResourcePointerTable.md). Historical labels `sub_586480` and `sub_589D30` remain evidence aliases only. |

## IDA MCP Evidence

Targeted checks on 2026-05-23 confirmed all listed function starts:

- `SystemMessagePane`: constructor/destructor, scroll metrics, keyboard help shortcut, paint, total-height helper, adjustor thunks, and scalar deleting destructor from `0x00584ea0` through `0x0058af3b`.
- `ColorStringSystemMessage` and marker messages: factories at `0x00587890` and `0x00587900`, colored string constructor/clone/line-count/draw from `0x00587970` through `0x00587ba3`, scalar cleanup at `0x0058ab50`, marker destructor `0x00514e60`, and folded boolean vtable helpers at `0x0055c1b0`/`0x0055c1c0`. B001's 2026-06-18 reanalysis gives the best descriptive marker names: slot `+0x0c` behaves like `IsHeaderMarker()` (`HeaderSystemMessage` true, `FooterSystemMessage` false, `ColorStringSystemMessage` false), and slot `+0x10` behaves like `IsFooterMarker()` (`HeaderSystemMessage` false, `FooterSystemMessage` true, `ColorStringSystemMessage` false). These names remain inferred; [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md) is still no-owner/non-emitting because the same physical bodies are folded with Effects and runtime tables.
- `NewSystemMessageModifyHeightPane`: constructor/cleanup/drag/paint at `0x005881f0`, `0x005882c0`, `0x005882f0`, and `0x00588500`, plus clear helper/destructor at `0x0058aaa0` and `0x0058acc0`.
- `NewSystemMessagePane`: constructor at `0x00588560`, `RebuildMessagePanes` at `0x00588800-0x00588c0c`, [UID:0004R2][0x00588d50-0x00588d6e.NewSystemMessagePaneRefreshSpelledPane](by-memory/0x00588d50-0x00588d6e.NewSystemMessagePaneRefreshSpelledPane.md) at `0x00588d50-0x00588d6e`, `OnPaint` at `0x00588d90-0x00588dfb`, tiny virtual helpers at `0x00588e00` and `0x00588e10`, clear helper/adjustor thunks at `0x0058aab0`, `0x0058ab07`, and `0x0058ab12`, and scalar deleting destructor at `0x0058ad20-0x0058adab`. The helper is exactly 30 bytes (SHA256 `38BE83C346986A1C95E77C59102101EDE8715EBCCBE06F7F7958A8605028EEF4`), calls the `SpelledPane` at `this+0xf8`, and has one direct UID0003UN EPF-branch caller at `0x005aace9`.
- `OldSystemMessagePane`: constructor at `0x00588e30-0x00589173`, scroll metric helpers from `0x00589540-0x005896c0`, draw/line-count helpers at `0x00589920-0x00589cea`, adjustor thunks at `0x0058ab1d` and `0x0058ab28`, and destructor at `0x0058adb0-0x0058af00`.
- 2026-05-25 IDA MCP recheck: `ColorStringSystemMessage::GetLineCount` at `0x00587ae0` calls [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md) with the entry text, text length, and width argument, then clamps the result to at least one line. `0x004bb070` itself currently returns constant `1`, so active generated output is behaviorally equivalent but structurally simplified.
- 2026-06-19 B002 accepted [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md) source-quality implementation names that helper `GetSingleLineCount` and records the precise callback interface: callers pass pane/context in `ecx` plus stack arguments `text`, UTF-16 `length`, and `width`; the helper ignores all inputs and returns one. `ColorStringSystemMessage::GetLineCount` reaches it through vtable-backed method `0x00587ae0-0x00587b53` / slot `0x0062d70c`, but this file's owner/emitter route is pragmatic generated-output routing, not proof of original `SystemMessagePanes.cpp` privacy. The same helper is also called by [UID:0002GG][0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines](by-memory/0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines.md) in the `Chatting` source family, and the helper is physically located in the GrafPort/text-helper island.
- 2026-06-21 B006 [UID:0002GG][0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines](by-memory/0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines.md) reanalysis confirms the same line-count callback signature nuance needed here: the first virtual argument should be documented as a pane/draw-context receiver forwarded in `ecx`, not as a simply unused parameter, while the second argument is the width. The helper currently ignores both inputs and returns one line, but the source-family route should preserve context/text/length/width shape for both `ColorStringSystemMessage::GetLineCount` and `ColorStringChattingMessage::MeasureLines`.
- 2026-05-25 IDA MCP recheck: `NewSystemMessagePane::NewSystemMessagePane` at `0x00588560` is directly called from `GeneralPurposePanel2` construction at `0x004b88ae`, writes `g_pNewSystemMessagePane`, creates `NewSystemMessageModifyHeightPane`, `SpelledPane`, and child `SystemMessagePane`; current `simroot_v2` still emits this constructor in `class_NewSystemMessageModifyHeightPane.cpp`.
- 2026-07-13 Agent-B001 UID000284 callback refines that constructor path: at `0x00588720`, `NewSystemMessagePane::NewSystemMessagePane` calls [UID:0004N5][0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries](by-memory/0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries.md) on the embedded `SpelledPane` at `this+0xf8`, passing the constructor-zeroed 256-wide-character buffer at `this+0x104` and length `0`. The parser clears the child vector, terminates on empty input, and rebuilds empty display text without insertion. This social-file caller remains non-owning: parser source and its function-local mutable [UID:000284][0x0066fe44-0x0066fe4a.SpelledPaneWhitespaceDelimiter](by-memory/0x0066fe44-0x0066fe4a.SpelledPaneWhitespaceDelimiter.md) stay under the SpelledPane source family.
- 2026-06-12 A002 Batch 286 vtable split: live IDA MCP reconfirmed the newer panel vtable island splits at `0x0062d838`. [UID:0003GM][0x0062d7b0-0x0062d838.NewSystemMessageModifyHeightPaneVtableData](by-memory/0x0062d7b0-0x0062d838.NewSystemMessageModifyHeightPaneVtableData.md) routes to [UID:00009B][NewSystemMessageModifyHeightPane](by-class/NewSystemMessageModifyHeightPane.md), and [UID:0003GN][0x0062d838-0x0062d8c4.NewSystemMessagePaneVtableData](by-memory/0x0062d838-0x0062d8c4.NewSystemMessagePaneVtableData.md) routes to [UID:00009C][NewSystemMessagePane](by-class/NewSystemMessagePane.md). The recheck also confirmed singleton slot refs at `0x0069bc0c`/`0x0069bc10`, delete sizes `0x114` and `0x304`, and the `OldSystemMessagePane` successor locator at `0x0062d8c4`.
- 2026-05-25 IDA MCP recheck: `OldSystemMessagePane::OldSystemMessagePane` at `0x00588e30` is directly called from the legacy main UI graph path at `0x004f8861`; current `simroot_v2/class_OldSystemMessagePane.cpp` still has only an omitted-body marker for the constructor.
- The system-message help-resource literal [UID:0003GP][0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString](by-memory/0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString.md) belongs to this file-level source family, not to either class alone. The four direct refs to `HELP.RES` split across `sub_586480` and `sub_589D30`, reached from the current and old system-message `?` help-shortcut handlers, while the `.RES` label at `0x0062d994` is only an IDA tail label with no xrefs.
- 2026-06-03 IDA MCP recheck: `HeaderSystemMessage` factory is `0x00587890-0x005878ff` and `FooterSystemMessage` factory is `0x00587900-0x0058796f`; both allocate a four-byte `LObject` shell, install their class vtable, and return null only on allocation failure. Vtable data confirms the paired true/false boolean slots, the `0x0058af40-0x0058af48` default true helper, and the factory slot for each marker class. The shared scalar deleting destructor `0x00514e60` is also reused by `MerchantDialogCreator` and `PursuitMessageDialogCreator` vtables.
- 2026-06-07 A003 Batch 055 writable-data refresh: [UID:0002AP][0x0069bc18-0x0069bdf8.SystemMessageResourcePointerTables](by-memory/0x0069bc18-0x0069bdf8.SystemMessageResourcePointerTables.md) now documents the two exact `0xf0` table children. Existing IDA evidence shows `sub_586480` fills `0x0069bc18-0x0069bd08` and `sub_589D30` fills `0x0069bd08-0x0069bdf8` from `sub_4F0350` resource lookups with empty-string fallback through `word_60DB20`.
- Historical 2026-07-04 B003 direct [UID:0002ZV][0x0069bc18-0x0069bd08.SystemMessagePaneResourcePointerTable](by-memory/0x0069bc18-0x0069bd08.SystemMessagePaneResourcePointerTable.md) pass used MCP session `cbc24146` and reconfirmed the first `0xf0` table as zero-initialized writable pointer storage owned by this file. It proved all-zero bytes, loader size `0x675`, the help-key caller route, xrefs at `0x0058668d` and `0x00586a08`, the 60-slot map ending at `0x0069bd04`, nonunique all-zero signature caveat, predecessor/sibling fences, and rejection of raw/aggregate/merged/static-literal alternatives. That pass used the then-current source name `s_systemMessagePaneResourcePointers`; the accepted B010 direct aggregate audit supersedes only that spelling with `s_systemMessageHelpMessages` and pairs it with `s_oldSystemMessageHelpMessages`. Historical IDA labels `sub_586480`, `sub_5858D0`, and `sub_589D30` remain evidence aliases only. Catalog0376 applied/read back the accepted loader identities; dated F7/1BC3/5F2679A7 checks and B010's bounded B7CC899D pass found no target-local drift, with fresh supervisor Gate 2B confirmation retained only as the later lifecycle gate.
- 2026-06-25 B006 accepted [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md) reclassification: live MCP session `80de0a67` confirmed 91 functions inside the target, successor helper `0x0058af40` outside the target, exact ForcedInformMessageDialog islands inside the physical span, zero-initialized singleton slots at `0x0069bc0c-0x0069bc18`, and clear-helper/destructor-adjustor routing. The executable page is now a non-emitting index; `social/SystemMessagePanes.cpp` remains the source placement for the exact class, global, vtable, resource-string, and singleton-slot pages.

## Ownership Notes

- This source family is chat-adjacent because `SystemMessagePane` stores `g_pChattingViewport`, but it is separate from the core `ChattingPane`/chat input/color picker source cluster.
- A008 split follow-up keeps `g_pChattingViewport` as system-message ownership: the exact storage dword at `0x0067adc4` is the first slot in the former mixed UI/chat/clan singleton run and has 16 xrefs from system-message insertion and UI paths, including the `SystemMessagePane` constructor/clear family around `0x00584ea0-0x005851e0`.
- Historical Wave2 notes called `0x00588d50` `NewSystemMessagePane::RefreshWorldMapPane`. The exact receiver offset `this+0xf8`, the accepted embedded `SpelledPane` layout, and the wrapper's remove-then-schedule `FrameHandler` behavior instead establish [UID:0004R2][0x00588d50-0x00588d6e.NewSystemMessagePaneRefreshSpelledPane](by-memory/0x00588d50-0x00588d6e.NewSystemMessagePaneRefreshSpelledPane.md) `NewSystemMessagePane::RefreshSpelledPane()`. Its only direct call is the EPF branch of [UID:0003UN][0x005aac80-0x005aafe3.UserPaneHandleServerEntryPacket](by-memory/0x005aac80-0x005aafe3.UserPaneHandleServerEntryPacket.md); source ownership remains `NewSystemMessagePane` in this file.
- [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md) occupies the neighboring `0x00587bb0-0x005881ed` gap between `ColorStringSystemMessage` and `NewSystemMessageModifyHeightPane`. Do not absorb that mandatory login/main-menu dialog into this system-message file by address locality.
- [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md) is retained only as a non-emitting executable split index. It should not be used as an aggregate source body, comment-only generated marker, or parent emitter; this file page remains the source-level owner for the SystemMessagePanes class family where individual class/support pages are ready.
- Current `simroot_v2` source is incomplete or mispartitioned for several methods: `OldSystemMessagePane` has a constructor install marker without a body; `NewSystemMessagePane` constructor `0x00588560` is emitted in `class_NewSystemMessageModifyHeightPane.cpp`; and `NewSystemMessagePane`, `NewSystemMessageModifyHeightPane`, `SystemMessagePane`, and the marker-message classes omit some tiny virtual helper/thunk bodies listed by IDA/vtable inspection. Use IDA boundaries plus Wave3 metadata for migration planning. Track constructor-body omissions with [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md).
- `ColorStringSystemMessage::GetLineCount` at `0x00587ae0` is structurally more complex than active generated source indicates, but current IDA-confirmed behavior still resolves to one line because [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md) is a constant helper.
- [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md) can continue to emit through `NexusTK/social/SystemMessagePanes.cpp` under the current project route. If a later shared text/color-string utility owner is introduced, this helper is a strong relocation candidate because it is shared with Chatting and has no system-message-specific state.
- Item/status formatting dependencies that need item names should resolve valid local inventory slots through [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md) and `LocalInventorySlotRecord::displayName` at `+0x06`; the inventory table remains owned by `LivingObjectPane`, not this social/status source file.

## SystemMessage Source Hierarchy

- Source order is [UID:0004SZ][SystemMessage](by-class/SystemMessage.md) at
  position 10, [UID:000061][HeaderSystemMessage](by-class/HeaderSystemMessage.md)
  at 20, [UID:00005D][FooterSystemMessage](by-class/FooterSystemMessage.md) at
  30, and [UID:000030][ColorStringSystemMessage](by-class/ColorStringSystemMessage.md)
  at 40. UID000246 is child position 10 under SystemMessage.
- RTTI proves a real fieldless abstract `SystemMessage` between `LObject` and
  all three concrete entries. Its source contract supplies false header/footer
  predicates, pure clone, exact one-line count, and no-op draw.
- Header and Footer are four-byte fieldless concrete entries. Each declares
  only its true marker predicate and clone difference. Color is 16 bytes with
  owned wide text at `+0x04`, color at `+0x08`, and style at `+0x0c`; it
  declares constructor, virtual destructor, clone, line count, and draw while
  inheriting both false predicates.
- Header/Footer clone/factory paths allocate four bytes, construct the LObject
  shell, and return null on allocation failure. Color's constructor copies
  UTF-16 text; clone reconstructs all three fields; count forwards context,
  text, length, and signed-short width to GetSingleLineCount before clamping to
  one; draw consumes the stored text/color/style and caller bounds.
- Exact Header/Footer/Color vtable pages UID0003GD/UID0003GE/UID0003GF are
  non-reconstructable, non-emitting compiler data with their concrete classes
  retained as semantic owners. The class declarations regenerate those
  locators, RTTI, and vtables; scalar deleting wrappers, explicit vptr stores,
  absolute arrays, folded true/false bodies, and the broad no-op body are not
  handwritten in this file.
- UID0001J6 remains the non-emitting executable index, UID00026M remains the
  non-emitting read-only index, UID0003DJ remains the mixed vtable index,
  UID0001GG remains folded physical boolean evidence, UID0000WM retains the
  broad LObject no-op route, UID0001B5 remains compiler scalar-wrapper glue,
  and UID00016F remains the separate shared line-count helper.

## B011 Empty-Emitter Family Disposition

Historical accepted B011 report
`0000OE-SystemMessagePanes-empty-emitter-family-source-quality.md` implemented
the then-current empty-emitter family without changing this file metadata. At
that evidence time it kept `COMPLETION:89`, `CONFIDENCE:86`, and rejected a
raise because seven class declarations remained comment-only after a
declaration-shell audit. The UID000246 callback supersedes only the now-resolved
SystemMessage/Header/Footer/Color portion; all unrelated B011 family evidence
and source routes remain valid.

The generated `auto-generated/NexusTK/social/SystemMessagePanes.cpp` family has 19 emitters: [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md) is already coded, while the 18 former empty markers are now resolved as six declarations and twelve formal source-disposition comments:

- Class disposition comments: [UID:000030][ColorStringSystemMessage](by-class/ColorStringSystemMessage.md), [UID:00005D][FooterSystemMessage](by-class/FooterSystemMessage.md), [UID:000061][HeaderSystemMessage](by-class/HeaderSystemMessage.md), [UID:00009B][NewSystemMessageModifyHeightPane](by-class/NewSystemMessageModifyHeightPane.md), [UID:00009C][NewSystemMessagePane](by-class/NewSystemMessagePane.md), [UID:00009T][OldSystemMessagePane](by-class/OldSystemMessagePane.md), and [UID:0000EA][SystemMessagePane](by-class/SystemMessagePane.md). These stay source-bearing under this file, but a declaration shell would currently invent base/interface ABI, adjusted-base layout, member layout, event signatures, or folded-helper treatment. The formal comments record that no `[[CHILDREN]]` shell is safe because the exact children are vtable/data pages rather than method-body pages.
- Singleton declarations: [UID:0002WV][g_pChattingViewport](by-global/g_pChattingViewport.md), [UID:0000R2][g_pHeightModifyPane](by-global/g_pHeightModifyPane.md), [UID:0000RU][g_pNewSystemMessagePane](by-global/g_pNewSystemMessagePane.md), and [UID:0003ED][g_pOldSystemMessagePane](by-global/g_pOldSystemMessagePane.md) now emit pointer declarations with C++98-era `0` initialization. Their exact storage children [UID:0002WW][0x0067adc4-0x0067adc8.g_pChattingViewport](by-memory/0x0067adc4-0x0067adc8.g_pChattingViewport.md) and [UID:0002W7][0x0069b4c8-0x0069b4cc.g_pOldSystemMessagePane](by-memory/0x0069b4c8-0x0069b4cc.g_pOldSystemMessagePane.md) use covered-by comments rather than duplicate declarations.
- Historical folded-helper disposition: B011 kept
  [UID:000246][0x0058af40-0x0058af48.SystemMessageGetLineCount](by-memory/0x0058af40-0x0058af48.SystemMessageGetLineCount.md)
  comment-only and deferred inherited-base versus duplicate overrides. Current
  RTTI and slot evidence resolves it as the one emitted SystemMessage default;
  Header/Footer inherit it and no free helper or duplicate body is emitted.
- Singleton aggregate disposition: [UID:0002AO][0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots](by-memory/0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots.md) stays a covered-by/reserved-data comment and now scores `88/92`. The live declarations are carried by [UID:0000R2][g_pHeightModifyPane](by-global/g_pHeightModifyPane.md) and [UID:0000RU][g_pNewSystemMessagePane](by-global/g_pNewSystemMessagePane.md), while `0x0069bc14` has zero current xrefs and remains reviewed zero-initialized reserved storage. B005 current MCP session `507affd6` reconfirmed the aggregate as all-zero writable support data with seven refs to `0x0069bc0c`, six refs to `0x0069bc10`, zero refs to `0x0069bc14`, and successor refs at `0x0069bc18`.
- Help-message table declarations: [UID:0002ZV][0x0069bc18-0x0069bd08.SystemMessagePaneResourcePointerTable](by-memory/0x0069bc18-0x0069bd08.SystemMessagePaneResourcePointerTable.md) emits `static const wchar_t *s_systemMessageHelpMessages[60] = { 0 };`; [UID:0002ZW][0x0069bd08-0x0069bdf8.OldSystemMessagePaneResourcePointerTable](by-memory/0x0069bd08-0x0069bdf8.OldSystemMessagePaneResourcePointerTable.md) emits `static const wchar_t *s_oldSystemMessageHelpMessages[60] = { 0 };`. Both are file-static writable arrays of pointers to constant wide characters because the exact children prove `0xf0` bytes / 60 slots, zero-initialized storage, pane-specific loader methods, complete localization/fallback maps, exact table-base refs, and common [UID:0000OE] ownership. Their H blocks remain blank because internal linkage needs no external declaration.
  - `SystemMessagePane::LoadHelpMessages` at `0x00586480` is reached only from the current pane's `?` key path at `0x0058590b`; `OldSystemMessagePane::LoadHelpMessages` at `0x00589d30` is reached only from the old pane's `?` key path at `0x005896ab`. Each loader uses `HELP.RES` when available, otherwise fills its separate 60-slot array with the same localization-ID map and `&initialText` separators at slots 14, 25, 33, 42, and 53 before appending header/color/footer entries.
  - [UID:0002AP][0x0069bc18-0x0069bdf8.SystemMessageResourcePointerTables](by-memory/0x0069bc18-0x0069bdf8.SystemMessageResourcePointerTables.md) is now a reviewed non-source index with blank CPP/H, `RECONSTRUCTABLE:FALSE`, and no emitter. It must not emit the former aggregate explanatory comment, a third declaration, wrapper, merged 120-slot table, or reverse-engineering source artifact.
  - Historical IDA labels `sub_586480`, `sub_589D30`, `sub_4F0350`, `word_60DB20`, `dword_69BC18`, and `dword_69BD08` remain address/evidence aliases only. Catalog0376 applied and verified the accepted names; dated F7/1BC3/5F2679A7 checks and B010's bounded B7CC899D pass found no target-local drift, fresh supervisor Gate 2B confirmation remains only the later lifecycle gate, and the aliases are not current source identities.

Rejected alternatives preserved from the B011 report: do not clear unrelated
`EMITTER_UIDS` merely to hide markers; do not reintroduce UID0001J6 as an
aggregate source body; do not move the root under `Chatting.cpp`; and do not
absorb `ForcedInformMessageDialog`, `TerminalPane`, shared destructor glue, or
folded boolean stubs by address locality. The historical ban on the four now-
resolved class declarations is superseded only by their exact current managed
blocks and does not authorize speculative declarations for unrelated classes.

## B009 UID0003GP Direct-Use Literal Disposition

- [UID:0003GP][0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString](by-memory/0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString.md) remains owned and solely emitted by this file. The literal is `[0x0062d98c,0x0062d99e)`, 18 bytes including its terminator, followed by separate two-byte alignment `[0x0062d99e,0x0062d9a0)`.
- Base refs are exactly `0x00586538` and `0x00586569` in `SystemMessagePane::LoadHelpMessages`, plus `0x00589d9e` and `0x00589dcf` in `OldSystemMessagePane::LoadHelpMessages`. The first call in each pair is `HasDATEntry`; the second is `DATFile::Open`.
- The source-level operands are direct `L"HELP.RES"` uses in both loader methods. Repeating the literal tokens is compatible with the one observed pooled binary object; the UID0003GP formal fragment records that source coverage without defining another object.
- The exact pattern is unique, and the current interior `LP` and `.RES` heads plus alignment have zero refs. No separate `.RES` child, raw array, address-derived name, file-static resource-name variable, class-static member, function-local array, or header declaration is warranted.
- `SystemMessagePane::LoadHelpMessages` remains `[0x00586480,0x00586af5)`, sole caller `0x0058590b`; `OldSystemMessagePane::LoadHelpMessages` remains `[0x00589d30,0x0058a230)`, sole caller `0x005896ab`. Their separate 60-slot fallback arrays and five separator slots remain unchanged.
- Source order is method-local: the literal tokens belong where each loader checks and opens the DAT entry. The UID0003GP no-standalone marker may appear as a generated documentation fragment, but it must not create a third data definition or displace either existing table declaration.
- IDA item repair remains supervisor Gate 2B work. `aHelpRes` is an IDA-only descriptive name and is forbidden in reconstructed C++.

## Cross-References

- [UID:0004SZ][SystemMessage](by-class/SystemMessage.md)
- [UID:0000EA][SystemMessagePane](by-class/SystemMessagePane.md)
- [UID:000030][ColorStringSystemMessage](by-class/ColorStringSystemMessage.md)
- [UID:000061][HeaderSystemMessage](by-class/HeaderSystemMessage.md)
- [UID:00005D][FooterSystemMessage](by-class/FooterSystemMessage.md)
- [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md)
- [UID:00009B][NewSystemMessageModifyHeightPane](by-class/NewSystemMessageModifyHeightPane.md)
- [UID:00009T][OldSystemMessagePane](by-class/OldSystemMessagePane.md)
- [UID:00009C][NewSystemMessagePane](by-class/NewSystemMessagePane.md)
- [UID:0004R2][0x00588d50-0x00588d6e.NewSystemMessagePaneRefreshSpelledPane](by-memory/0x00588d50-0x00588d6e.NewSystemMessagePaneRefreshSpelledPane.md)
- [UID:0003GM][0x0062d7b0-0x0062d838.NewSystemMessageModifyHeightPaneVtableData](by-memory/0x0062d7b0-0x0062d838.NewSystemMessageModifyHeightPaneVtableData.md)
- [UID:0003GN][0x0062d838-0x0062d8c4.NewSystemMessagePaneVtableData](by-memory/0x0062d838-0x0062d8c4.NewSystemMessagePaneVtableData.md)
- [UID:0003GP][0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString](by-memory/0x0062d98c-0x0062d9a0.SystemMessagePaneHelpResourceString.md)
- [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md)
- [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md)
- [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md)
- [UID:0001B5][0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor](by-memory/0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor.md)
- [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md)
- [UID:0000R2][g_pHeightModifyPane](by-global/g_pHeightModifyPane.md)
- [UID:0000RU][g_pNewSystemMessagePane](by-global/g_pNewSystemMessagePane.md)
- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:0002AP][0x0069bc18-0x0069bdf8.SystemMessageResourcePointerTables](by-memory/0x0069bc18-0x0069bdf8.SystemMessageResourcePointerTables.md)
- [UID:0002ZV][0x0069bc18-0x0069bd08.SystemMessagePaneResourcePointerTable](by-memory/0x0069bc18-0x0069bd08.SystemMessagePaneResourcePointerTable.md)
- [UID:0002ZW][0x0069bd08-0x0069bdf8.OldSystemMessagePaneResourcePointerTable](by-memory/0x0069bd08-0x0069bdf8.OldSystemMessagePaneResourcePointerTable.md)
- [UID:0004N5][0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries](by-memory/0x0056c0e0-0x0056c2db.SpelledPaneParseAndLoadEntries.md)
- [UID:000284][0x0066fe44-0x0066fe4a.SpelledPaneWhitespaceDelimiter](by-memory/0x0066fe44-0x0066fe4a.SpelledPaneWhitespaceDelimiter.md)

## Changes

- 2026-08-14 B009 UID0003GP accepted implementation callback:
  - Kept file metadata `91/92`, FILE ownership, and `NexusTK/social/` placement unchanged.
  - Added UID0003GP as the direct-use pooled `L"HELP.RES"` dependency, with exact literal/alignment ranges, four `HasDATEntry`/`DATFile::Open` refs, both loader/caller routes, source order, and no-standalone/no-header disposition.
  - Preserved both 60-slot table declarations, all class/source hierarchy content, historical B011 evidence, and unrelated reconstruction caveats; no new file-static resource-name object was introduced.
- 2026-07-30 B010 UID0002AP accepted pre-IDA ordinary callback:
  - Kept file metadata `91/92` and `NexusTK/social/` routing unchanged; synchronized the paired child declarations to `s_systemMessageHelpMessages` and `s_oldSystemMessageHelpMessages` and the loader methods to pane-specific `LoadHelpMessages` identities.
  - Incorporated exact sole-caller, HELP.RES/fallback, five-separator, linkage/type, split, and one-definition behavior from the direct target report without moving class, singleton, or unrelated source ownership.
  - Reclassified UID0002AP as a blank, non-source coverage index and preserved the old B011 aggregate-comment/raw-label wording strictly as historical evidence rather than desired generated source.
- 2026-07-19 B002 UID000246 accepted callback:
  - Raised `89/86` to `91/90` while retaining FILE ownership and
    `NexusTK/social/` placement; no by-file reconstruction metadata was added.
  - Added the complete SystemMessage/Header/Footer/Color source order,
    inheritance, override matrix, exact layouts, lifecycle and helper behavior,
    compiler exclusions, non-emitting vtable dispositions, index routes,
    rejected alternatives, and historicalized B011 blockers without changing
    unrelated pane/resource/singleton content.
- 2026-07-15 Agent-B004 UID0003UN callback source-identity synchronization:
  - Replaced the historical `RefreshWorldMapPane` label for `0x00588d50-0x00588d6e` with validator-registered [UID:0004R2][0x00588d50-0x00588d6e.NewSystemMessagePaneRefreshSpelledPane](by-memory/0x00588d50-0x00588d6e.NewSystemMessagePaneRefreshSpelledPane.md) `NewSystemMessagePane::RefreshSpelledPane()`.
  - Added the exact 30-byte SHA256, embedded `SpelledPane` field at `this+0xf8`, one UID0003UN EPF-branch caller at `0x005aace9`, and source-level `RefreshScrollState()` abstraction while preserving file score `89/86`, all family partitions, ForcedInform exclusions, constructor caveats, and unrelated evidence.

- 2026-07-13 Agent-B001 UID000284 callback support sync:
  - What existed before: the file page documented generic SpelledPane construction but omitted the exact initialization call and its empty-input shape.
  - Changed to: added call site `0x00588720`, embedded child offset `this+0xf8`, zeroed 256-wide-character buffer offset `this+0x104`, zero length, parser empty-input effect, and the explicit non-owning relation to UID0004N5/UID000284. File score/path, class ownership, existing generated-partition caveats, and unrelated content remain unchanged.
  - Evidence: accepted UID000284 report and live IDA MCP session `supervisor_nexustk_20260713` caller/disassembly/decompilation reads.

- 2026-07-07 B005 [UID:0002AO][0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots](by-memory/0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots.md) support sync:
  - Score unchanged at file root `89/86`; synced UID0002AO target score wording to `88/92`.
  - Added current session `507affd6` proof that UID0002AO remains a marker-only covered-by/reserved-data aggregate under this source file: all-zero storage, seven/six/zero target xrefs for `0x0069bc0c`/`0x0069bc10`/`0x0069bc14`, successor refs at `0x0069bc18`, declarations owned by [UID:0000R2][g_pHeightModifyPane](by-global/g_pHeightModifyPane.md) and [UID:0000RU][g_pNewSystemMessagePane](by-global/g_pNewSystemMessagePane.md), and preserved B011 rejected alternatives against raw labels, duplicate aggregate declarations, and broad ownership moves.
- 2026-06-30 B011 accepted empty-emitter family implementation:
  - Score remains `89/86`; projected path remains `NexusTK/social/`; `CANONICAL_OWNER:FILE` unchanged.
  - Incorporated the accepted B011 report-level disposition for the 18 former empty markers in `auto-generated/NexusTK/social/SystemMessagePanes.cpp`: seven class no-code comments after declaration-shell audits, four singleton pointer declarations, two covered-by singleton-storage comments, [UID:000246][0x0058af40-0x0058af48.SystemMessageGetLineCount](by-memory/0x0058af40-0x0058af48.SystemMessageGetLineCount.md) folded line-count virtual comment, [UID:0002AO][0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots](by-memory/0x0069bc0c-0x0069bc18.SystemMessagePaneSingletonSlots.md) covered-by/reserved-data aggregate comment, two file-static resource pointer array declarations, and [UID:0002AP][0x0069bc18-0x0069bdf8.SystemMessageResourcePointerTables](by-memory/0x0069bc18-0x0069bdf8.SystemMessageResourcePointerTables.md) aggregate comment.
  - Preserved [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md) as already coded and [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md) as a non-emitting executable split index.
- 2026-07-04 B003 [UID:0002ZV][0x0069bc18-0x0069bd08.SystemMessagePaneResourcePointerTable](by-memory/0x0069bc18-0x0069bd08.SystemMessagePaneResourcePointerTable.md) direct-target implementation:
  - Score unchanged at file root `89/86`; added current `cbc24146` proof for [UID:0002ZV][0x0069bc18-0x0069bd08.SystemMessagePaneResourcePointerTable](by-memory/0x0069bc18-0x0069bd08.SystemMessagePaneResourcePointerTable.md)'s direct source-ready table declaration, slot-map/fallback behavior, help-key caller route, split from [UID:0002ZW][0x0069bd08-0x0069bdf8.OldSystemMessagePaneResourcePointerTable](by-memory/0x0069bd08-0x0069bdf8.OldSystemMessagePaneResourcePointerTable.md), and rejected raw/aggregate/merged/literal alternatives.
- 2026-06-25 B006 accepted [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md) support sync:
  - Recorded [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md) as a non-emitting executable split index while preserving this file page as the source owner for class-level reconstruction.
  - Added the report-level routing rule that exact class/support pages, not the broad executable index, carry reconstruction for SystemMessagePane, ColorString/Header/Footer message entries, the new/old wrapper panes, singleton slots, vtables, resource strings, and ForcedInform exclusions.
- 2026-06-21 Rule 26 support sync from B006 [UID:0003U9][0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress](by-memory/0x005a3870-0x005a3889.UserPaneGetInventorySlotAddress.md):
  - Added the local inventory slot display-name dependency for item/status message formatting and preserved source ownership under `LivingObjectPane`.
- 2026-06-19 B002 accepted [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md) source-quality implementation:
  - Score unchanged at `89/86`.
  - Summary/evidence: refreshed the file-level `ColorStringSystemMessage` contents/evidence to name `0x004bb070` as `GetSingleLineCount`, preserve the current `SystemMessagePanes.cpp` emitter route, and document that the route is pragmatic generated-output placement rather than proof of original SystemMessagePanes-private ownership. The helper is shared with `ColorStringChattingMessage::MeasureLines` and physically sits in the GrafPort/text-helper island, so a future shared text utility route remains plausible.
- 2026-06-21 B006 sibling measure-call sync:
  - Score unchanged at `89/86`.
  - Summary/evidence: added the shared `ColorStringChattingMessage::MeasureLines` signature evidence so this file keeps `ColorStringSystemMessage::GetLineCount` in the same context-receiver plus width model. The first virtual argument is forwarded through `ecx`; it is only unused by the current constant helper body.
- 2026-06-18 B001 marker-slot source-name sync:
  - Score unchanged at `89/86`.
  - Evidence: incorporated the [UID:0001GG][0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs](by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md) reanalysis into the file-level marker-message model. Header/Footer/ColorString vtables support inferred `IsHeaderMarker()` and `IsFooterMarker()` slot names, but the physical folded stubs remain no-owner/non-emitting because PE pointer evidence also ties them to Effects and MSVC runtime/read-only table use.
- 2026-06-07 A003 Batch 055 parent-gate/data-table refresh:
  - Before: file score was `88/85`, and the writable system-message resource pointer tables were only linked indirectly through the executable/read-only-data pages.
  - Changed to: `COMPLETION:89`, `CONFIDENCE:86`; added the [UID:0002AP][0x0069bc18-0x0069bdf8.SystemMessageResourcePointerTables](by-memory/0x0069bc18-0x0069bdf8.SystemMessageResourcePointerTables.md) aggregate and its two exact table children to proposed contents/evidence/cross-references.
  - Evidence: existing IDA-backed docs show `sub_586480` and `sub_589D30` initialize the two `0xf0` pointer tables from `sub_4F0350` resources, and both initializers sit in the documented system-message pane source family.
- 2026-06-12 A002 Batch 286:
  - Score remains `89/86`.
  - Summary/evidence: linked exact new-system-message vtable children [UID:0003GM][0x0062d7b0-0x0062d838.NewSystemMessageModifyHeightPaneVtableData](by-memory/0x0062d7b0-0x0062d838.NewSystemMessageModifyHeightPaneVtableData.md) and [UID:0003GN][0x0062d838-0x0062d8c4.NewSystemMessagePaneVtableData](by-memory/0x0062d838-0x0062d8c4.NewSystemMessagePaneVtableData.md) and recorded live split evidence. No source-family or projected-path change was needed.
- 2026-06-01: Set projected reconstruction path to `NexusTK/social/`.
  - Evidence: this document already proposes `social/SystemMessagePanes.cpp`, and `by-project-structure/proposed-source-tree.md` places the system-message pane family under `social/`.
  - Scope: path assignment only; code remains gated by child-page confidence and final-source naming quality.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `88` and confidence to `80`.
  - Evidence: document covers the full system-message pane family, proposed contents, IDA function-boundary evidence, constructor and vtable notes, generated mispartition caveats, social/chat split, and cross-references; confidence remains capped by final split from `social/Chatting.cpp`.
- 2026-06-03: Raised confidence from `80` to `82` after fresh IDA MCP verification of the header/footer marker factories and vtable slot layout.
  - Evidence: exact half-open factory endpoints, constructor-body disassembly, header/footer vtable word maps, and shared destructor reuse outside the marker pair are now recorded.
  - Scope: documentation/attachment confidence only; reconstructed C++ remains gated by child method-name quality.
- 2026-06-07 A008 Batch 037 parent-gate refresh:
  - Raised confidence from `82` to `85`.
  - Evidence: the split of [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md) isolates the `0x0067adc4` `g_pChattingViewport` dword as system-message-owned storage with 16 xrefs and a direct `SystemMessagePane` lifecycle, clearing the direct-parent gate for its exact singleton global.

## B001 UID0003TY NewSystemMessagePane Source Integration - 2026-07-20

- [UID:00009C][NewSystemMessagePane](by-class/NewSystemMessagePane.md) now emits one complete `0x304` class declaration through `NexusTK/social/SystemMessagePanes.cpp`, preserving constructor, ordinary destructor, `OnActivate`, `OnPaint`, and existing `RefreshSpelledPane` source while closing the former comment-only declaration shell.
- Address/source order adds [UID:0004TU][0x00588d70-0x00588d81.NewSystemMessagePaneStopSpelledPaneRefresh](by-memory/0x00588d70-0x00588d81.NewSystemMessagePaneStopSpelledPaneRefresh.md) after retained [UID:0004R2][0x00588d50-0x00588d6e.NewSystemMessagePaneRefreshSpelledPane](by-memory/0x00588d50-0x00588d6e.NewSystemMessagePaneRefreshSpelledPane.md), then `OnPaint`, [UID:0004TV][0x00588e00-0x00588e05.NewSystemMessagePaneHandleKeyOrTextEvent](by-memory/0x00588e00-0x00588e05.NewSystemMessagePaneHandleKeyOrTextEvent.md), and [UID:0004TW][0x00588e10-0x00588e15.NewSystemMessagePaneHandlePointerOrMouseEvent](by-memory/0x00588e10-0x00588e15.NewSystemMessagePaneHandlePointerOrMouseEvent.md).
- The stop helper forwards only to SpelledPane stop behavior. Both five-byte EventHandler overrides return false independently and use one stack argument. Their source definitions are class members, not file-local helpers, adjustor thunks, merged stubs, or aggregate bodies.
- Exact constructor fields are SpelledPane, SystemMessagePane, height pane, and the 256-wide-character text buffer. Singleton, vtable, parser, OnActivate, paint, child cleanup, and scalar-wrapper evidence remains preserved at same-or-greater detail.
- File score becomes `91/92`; projected path `NexusTK/social/`, canonical owner FILE, all existing SystemMessage/OldSystemMessage/NewSystemMessage family content, resource tables, source order, and historical evidence remain unchanged.
- UID0003TY is only an external caller of UID0004TU. MapPane does not own this source family. Compiler vptr, EH, adjustor, scalar-delete, and base-teardown lowering remains excluded from handwritten output.
