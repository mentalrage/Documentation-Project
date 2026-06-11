*** UID:0000OE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/social/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# SystemMessagePanes

## Status

- Confidence: strong for the system-message pane family, IDA function boundaries, and exact `g_pChattingViewport` storage; medium for exact final split from `social/Chatting.cpp`.
- Proposed module folder: `social/`
- Candidate file: `social/SystemMessagePanes.cpp`
- Current generated sources: `class_SystemMessagePane.cpp`, `class_OldSystemMessagePane.cpp`, `class_NewSystemMessagePane.cpp`, `class_NewSystemMessageModifyHeightPane.cpp`, `class_ColorStringSystemMessage.cpp`, `class_HeaderSystemMessage.cpp`, and `class_FooterSystemMessage.cpp`.
- Evidence basis: Wave3 class inspection, `simroot_v2` generated source, older Wave2 notes for `NewSystemMessagePane::RefreshWorldMapPane`, and targeted IDA MCP checks on 2026-05-23 plus rechecks on 2026-05-25.

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
| `SystemMessagePane` | `0x00584ea0-0x0058af3b` | `class_SystemMessagePane.cpp` | Scrollable system-message viewport with high-resolution dynamic lines and normal-resolution EPF tile slots. |
| `ColorStringSystemMessage` | `0x00587970-0x00587ba3`, `0x0058ab50-0x0058abe6`, plus tiny virtual `0x0055c1c0` | `class_ColorStringSystemMessage.cpp` | Heap-backed colored text message entry with clone, one-line-count helper shape, draw, and cleanup methods. |
| `HeaderSystemMessage` | `0x00587890-0x005878ff`, plus `0x00514e60` and tiny boolean/default slots | `class_HeaderSystemMessage.cpp` | Tiny marker entry/factory for system-message list structure. |
| `FooterSystemMessage` | `0x00587900-0x0058796f`, plus shared destructor/boolean/default slots | `class_FooterSystemMessage.cpp` | Tiny footer marker entry/factory for system-message list structure. |
| `NewSystemMessageModifyHeightPane` | `0x005881f0-0x0058855b`, `0x0058aaa0`, `0x0058acc0-0x0058ad1e` | `class_NewSystemMessageModifyHeightPane.cpp` | Drag handle for resizing/persisting the newer system-message panel height. |
| `NewSystemMessagePane` | `0x00588560-0x0058adab` | `class_NewSystemMessagePane.cpp` plus misfiled constructor in `class_NewSystemMessageModifyHeightPane.cpp` | New-client system-message panel wrapper that rebuilds child panes, refreshes world-map child state, and draws the tiled panel background. |
| `OldSystemMessagePane` | `0x00588e30-0x0058af00` | `class_OldSystemMessagePane.cpp` | Legacy scrollable system-message pane with fixed 12-pixel rows, separators, clip-region drawing, and message collection destruction. |
| resource pointer tables | [UID:0002AP][0x0069bc18-0x0069bdf8.SystemMessageResourcePointerTables](by-memory/0x0069bc18-0x0069bdf8.SystemMessageResourcePointerTables.md) | writable data | Two `0xf0`-byte resource/string pointer tables initialized by `sub_586480` and `sub_589D30`; split into [UID:0002ZV][0x0069bc18-0x0069bd08.SystemMessagePaneResourcePointerTable](by-memory/0x0069bc18-0x0069bd08.SystemMessagePaneResourcePointerTable.md) and [UID:0002ZW][0x0069bd08-0x0069bdf8.OldSystemMessagePaneResourcePointerTable](by-memory/0x0069bd08-0x0069bdf8.OldSystemMessagePaneResourcePointerTable.md). |

## IDA MCP Evidence

Targeted checks on 2026-05-23 confirmed all listed function starts:

- `SystemMessagePane`: constructor/destructor, scroll metrics, keyboard help shortcut, paint, total-height helper, adjustor thunks, and scalar deleting destructor from `0x00584ea0` through `0x0058af3b`.
- `ColorStringSystemMessage` and marker messages: factories at `0x00587890` and `0x00587900`, colored string constructor/clone/line-count/draw from `0x00587970` through `0x00587ba3`, scalar cleanup at `0x0058ab50`, marker destructor `0x00514e60`, and boolean vtable helpers at `0x0055c1b0`/`0x0055c1c0`.
- `NewSystemMessageModifyHeightPane`: constructor/cleanup/drag/paint at `0x005881f0`, `0x005882c0`, `0x005882f0`, and `0x00588500`, plus clear helper/destructor at `0x0058aaa0` and `0x0058acc0`.
- `NewSystemMessagePane`: constructor at `0x00588560`, `RebuildMessagePanes` at `0x00588800-0x00588c0c`, `RefreshWorldMapPane` at `0x00588d50-0x00588d6e`, `OnPaint` at `0x00588d90-0x00588dfb`, tiny virtual helpers at `0x00588e00` and `0x00588e10`, clear helper/adjustor thunks at `0x0058aab0`, `0x0058ab07`, and `0x0058ab12`, and scalar deleting destructor at `0x0058ad20-0x0058adab`.
- `OldSystemMessagePane`: constructor at `0x00588e30-0x00589173`, scroll metric helpers from `0x00589540-0x005896c0`, draw/line-count helpers at `0x00589920-0x00589cea`, adjustor thunks at `0x0058ab1d` and `0x0058ab28`, and destructor at `0x0058adb0-0x0058af00`.
- 2026-05-25 IDA MCP recheck: `ColorStringSystemMessage::GetLineCount` at `0x00587ae0` calls [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md) with the entry text, text length, and width argument, then clamps the result to at least one line. `0x004bb070` itself currently returns constant `1`, so active `simroot_v2` is behaviorally equivalent but structurally simplified.
- 2026-05-25 IDA MCP recheck: `NewSystemMessagePane::NewSystemMessagePane` at `0x00588560` is directly called from `GeneralPurposePanel2` construction at `0x004b88ae`, writes `g_pNewSystemMessagePane`, creates `NewSystemMessageModifyHeightPane`, `SpelledPane`, and child `SystemMessagePane`; current `simroot_v2` still emits this constructor in `class_NewSystemMessageModifyHeightPane.cpp`.
- 2026-05-25 IDA MCP recheck: `OldSystemMessagePane::OldSystemMessagePane` at `0x00588e30` is directly called from the legacy main UI graph path at `0x004f8861`; current `simroot_v2/class_OldSystemMessagePane.cpp` still has only an omitted-body marker for the constructor.
- 2026-06-03 IDA MCP recheck: `HeaderSystemMessage` factory is `0x00587890-0x005878ff` and `FooterSystemMessage` factory is `0x00587900-0x0058796f`; both allocate a four-byte `LObject` shell, install their class vtable, and return null only on allocation failure. Vtable data confirms the paired true/false boolean slots, the `0x0058af40-0x0058af48` default true helper, and the factory slot for each marker class. The shared scalar deleting destructor `0x00514e60` is also reused by `MerchantDialogCreator` and `PursuitMessageDialogCreator` vtables.
- 2026-06-07 A003 Batch 055 writable-data refresh: [UID:0002AP][0x0069bc18-0x0069bdf8.SystemMessageResourcePointerTables](by-memory/0x0069bc18-0x0069bdf8.SystemMessageResourcePointerTables.md) now documents the two exact `0xf0` table children. Existing IDA evidence shows `sub_586480` fills `0x0069bc18-0x0069bd08` and `sub_589D30` fills `0x0069bd08-0x0069bdf8` from `sub_4F0350` resource lookups with empty-string fallback through `word_60DB20`.

## Ownership Notes

- This source family is chat-adjacent because `SystemMessagePane` stores `g_pChattingViewport`, but it is separate from the core `ChattingPane`/chat input/color picker source cluster.
- A008 split follow-up keeps `g_pChattingViewport` as system-message ownership: the exact storage dword at `0x0067adc4` is the first slot in the former mixed UI/chat/clan singleton run and has 16 xrefs from system-message insertion and UI paths, including the `SystemMessagePane` constructor/clear family around `0x00584ea0-0x005851e0`.
- `NewSystemMessagePane::RefreshWorldMapPane` has older Wave2 evidence as a restored missing reference called from `LivingObjectPane::HandleServerEntryPacket`; keep it under `NewSystemMessagePane`, not a world-map file.
- [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md) occupies the neighboring `0x00587bb0-0x005881ed` gap between `ColorStringSystemMessage` and `NewSystemMessageModifyHeightPane`. Do not absorb that mandatory login/main-menu dialog into this system-message file by address locality.
- Current `simroot_v2` source is incomplete or mispartitioned for several methods: `OldSystemMessagePane` has a constructor install marker without a body; `NewSystemMessagePane` constructor `0x00588560` is emitted in `class_NewSystemMessageModifyHeightPane.cpp`; and `NewSystemMessagePane`, `NewSystemMessageModifyHeightPane`, `SystemMessagePane`, and the marker-message classes omit some tiny virtual helper/thunk bodies listed by IDA/vtable inspection. Use IDA boundaries plus Wave3 metadata for migration planning. Track constructor-body omissions with [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md).
- `ColorStringSystemMessage::GetLineCount` at `0x00587ae0` is structurally more complex than active generated source indicates, but current IDA-confirmed behavior still resolves to one line because [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md) is a constant helper.

## Cross-References

- [UID:0000EA][SystemMessagePane](by-class/SystemMessagePane.md)
- [UID:000030][ColorStringSystemMessage](by-class/ColorStringSystemMessage.md)
- [UID:000061][HeaderSystemMessage](by-class/HeaderSystemMessage.md)
- [UID:00005D][FooterSystemMessage](by-class/FooterSystemMessage.md)
- [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md)
- [UID:00009B][NewSystemMessageModifyHeightPane](by-class/NewSystemMessageModifyHeightPane.md)
- [UID:00009T][OldSystemMessagePane](by-class/OldSystemMessagePane.md)
- [UID:00009C][NewSystemMessagePane](by-class/NewSystemMessagePane.md)
- [UID:0000JJ][ForcedInformMessageDialog](by-file/ForcedInformMessageDialog.md)
- [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md)
- [UID:0001GG][0x0055c1b0-0x0055c1c2.SystemMessageBooleanVirtuals](by-memory/0x0055c1b0-0x0055c1c2.SystemMessageBooleanVirtuals.md)
- [UID:0001B5][0x00514e60-0x00514e98.SystemMessageMarkerScalarDeletingDestructor](by-memory/0x00514e60-0x00514e98.SystemMessageMarkerScalarDeletingDestructor.md)
- [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md)
- [UID:0000R2][g_pHeightModifyPane](by-global/g_pHeightModifyPane.md)
- [UID:0000RU][g_pNewSystemMessagePane](by-global/g_pNewSystemMessagePane.md)
- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:0002AP][0x0069bc18-0x0069bdf8.SystemMessageResourcePointerTables](by-memory/0x0069bc18-0x0069bdf8.SystemMessageResourcePointerTables.md)
- [UID:0002ZV][0x0069bc18-0x0069bd08.SystemMessagePaneResourcePointerTable](by-memory/0x0069bc18-0x0069bd08.SystemMessagePaneResourcePointerTable.md)
- [UID:0002ZW][0x0069bd08-0x0069bdf8.OldSystemMessagePaneResourcePointerTable](by-memory/0x0069bd08-0x0069bdf8.OldSystemMessagePaneResourcePointerTable.md)

## Changes

- 2026-06-07 A003 Batch 055 parent-gate/data-table refresh:
  - Before: file score was `88/85`, and the writable system-message resource pointer tables were only linked indirectly through the executable/read-only-data pages.
  - Changed to: `COMPLETION:89`, `CONFIDENCE:86`; added the [UID:0002AP][0x0069bc18-0x0069bdf8.SystemMessageResourcePointerTables](by-memory/0x0069bc18-0x0069bdf8.SystemMessageResourcePointerTables.md) aggregate and its two exact table children to proposed contents/evidence/cross-references.
  - Evidence: existing IDA-backed docs show `sub_586480` and `sub_589D30` initialize the two `0xf0` pointer tables from `sub_4F0350` resources, and both initializers sit in the documented system-message pane source family.
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
