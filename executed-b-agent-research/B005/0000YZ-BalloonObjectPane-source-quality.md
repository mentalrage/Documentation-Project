** TARGET-REPORT-UID:0000YZ **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B005 pending report: [UID:0000YZ] BalloonObjectPane source-quality refresh

Status: pending supervisor review. This pass is report-only; no by-* target/support docs or coverage files were edited.

Target: [UID:0000YZ][0x00467b30-0x0046904e.BalloonObjectPane](../../../../../by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md)

Current target state revalidated on 2026-06-19 from current docs/generated ledgers:

- `COMPLETION:84`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000HJ`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000HJ`
- formal C++ block is blank
- current generated stats row: `| 0000YZ | 84 | 90 | 87.0 | by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md |`
- current generated memory route: `emits | 0000HJ | 0000HJ | ... | auto-generated/NexusTK/map/AttachedObjectPane.cpp`
- current generated `auto-generated/NexusTK/map/AttachedObjectPane.cpp` has empty emitter markers for [UID:00000U] `BalloonObjectPane`, [UID:000276] masks, [UID:0002WU] pool, and [UID:0000YZ] target; no source code is emitted today.

## Executive recommendation

Update [UID:0000YZ] to:

```text
COMPLETION:88
CONFIDENCE:91
CANONICAL_OWNER:00000U
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00000U
```

Keep the target's formal C++ block blank. The range is source-bearing and strongly understood, but it is a contiguous method cluster plus compiler glue, not one source function. First-draft C++ should be emitted only after method-level child pages are split or after the class page is explicitly chosen as the emitter for individual method bodies.

Direct semantic owner should be [UID:00000U][BalloonObjectPane](../../../../../by-class/BalloonObjectPane.md), not [UID:0000HJ][AttachedObjectPane](../../../../../by-file/AttachedObjectPane.md). The source file route still flows through `BalloonObjectPane -> AttachedObjectPane -> NexusTK/map/AttachedObjectPane.cpp`, matching the proposed source tree and the existing class-to-file parent. The target's direct owner/emitter should match the current static mask and pool children, both of which already use `CANONICAL_OWNER:00000U` and `EMITTER_UIDS:00000U` while still generating into `auto-generated/NexusTK/map/AttachedObjectPane.cpp`.

Recommended coverage row replacement for `by-memory/-coverage-report.md` after implementation:

```text
    - [UID:0000YZ][0x00467b30-0x0046904e.BalloonObjectPane](by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md) : reconstructable : 88% : strong : Reworked owner to [UID:00000U][BalloonObjectPane] with source route through [UID:0000HJ][AttachedObjectPane]; current evidence identifies PaintBubble, constructor/layout/update/destructor methods, vtable adjustor thunks, static mask/pool support, global names (`g_useEpfAssets`, `g_pPaletteLib`, `g_movementSubstepScale`, `g_mapTilePixelWidth`, `g_mapTilePixelHeight`), and two source-shaped raw helpers at `0x00468250`/`0x00468e00`; formal C++ remains blank until method child pages are split and orphan helper liveness is either accepted as private dead code or excluded.
```

## Evidence checked

Instructions and standards:

- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Agent-B005/goal.md`
- `by-structure.md`
- `inference_research.md`
- `by-project-structure/proposed-source-tree.md`

Current target/support docs:

- [UID:0000YZ][0x00467b30-0x0046904e.BalloonObjectPane](../../../../../by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md)
- [UID:00000U][BalloonObjectPane](../../../../../by-class/BalloonObjectPane.md)
- [UID:0000HJ][AttachedObjectPane](../../../../../by-file/AttachedObjectPane.md)
- [UID:0000YZ] current row in [by-memory/-coverage-report.md](../../../../../by-memory/-coverage-report.md)
- [project-level/-auto-completion-stats.md](../../../../../project-level/-auto-completion-stats.md)
- [auto-generated/-ag-memory-coverage.md](../../../../../auto-generated/-ag-memory-coverage.md)
- [auto-generated/-ag-class-coverage.md](../../../../../auto-generated/-ag-class-coverage.md)
- [auto-generated/NexusTK/map/AttachedObjectPane.cpp](../../../../../auto-generated/NexusTK/map/AttachedObjectPane.cpp)

Relevant owner/support docs:

- [UID:000276][0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks](../../../../../by-memory/0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks.md)
- [UID:0002WU][0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage](../../../../../by-memory/0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage.md)
- [UID:00037M][0x00612f3c-0x006131b4.BackGroundBalloonBlackHoleReadOnlyData](../../../../../by-memory/0x00612f3c-0x006131b4.BackGroundBalloonBlackHoleReadOnlyData.md)
- [UID:0002QT][0x005380b0-0x005387a3.AttachedObjectPane](../../../../../by-memory/0x005380b0-0x005387a3.AttachedObjectPane.md)
- [UID:0002J1][0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter](../../../../../by-memory/0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter.md), now documented as `GrafPort::EnableSoftwareBuffer`
- [UID:00015U][0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth](../../../../../by-memory/0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth.md)
- [UID:0001O3][0x005062f0-0x0050637a.MapPaneFindObjectIntersectingRect](../../../../../by-memory/0x005062f0-0x0050637a.MapPaneFindObjectIntersectingRect.md)
- [UID:0001X5][0x00511710-0x005119ac.MapPaneHandleMovementSpeechBalloonPacket](../../../../../by-memory/0x00511710-0x005119ac.MapPaneHandleMovementSpeechBalloonPacket.md)
- [UID:0002VQ][0x0053aaf0-0x0053aeb4.LivingObjectPaneLinkedObjectSetupHelpers](../../../../../by-memory/0x0053aaf0-0x0053aeb4.LivingObjectPaneLinkedObjectSetupHelpers.md)
- [UID:0001DA][0x0053a110-0x0053d818.LivingObjectPaneCore](../../../../../by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md)
- [UID:0000SW][g_useEpfAssets](../../../../../by-global/g_useEpfAssets.md) and [UID:0001OH][0x0066da97-0x0066da98.g_useEpfAssets](../../../../../by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md)
- [UID:0002CF][g_movementSubstepScale](../../../../../by-global/g_movementSubstepScale.md) and [UID:00027F][0x0066da96-0x0066da97.g_movementSubstepScale](../../../../../by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md)
- [UID:0000T7][MapTilePixelDimensions](../../../../../by-global/MapTilePixelDimensions.md), [UID:0001OJ][0x0066da9c-0x0066da9e.g_mapTilePixelWidth](../../../../../by-memory/0x0066da9c-0x0066da9e.g_mapTilePixelWidth.md), and [UID:0001OK][0x0066daa0-0x0066daa2.g_mapTilePixelHeight](../../../../../by-memory/0x0066daa0-0x0066daa2.g_mapTilePixelHeight.md)
- [UID:0000RW][g_pPaletteLib](../../../../../by-global/g_pPaletteLib.md), [UID:00028T][0x0067a7e0-0x0067a7e4.g_pPaletteLib](../../../../../by-memory/0x0067a7e0-0x0067a7e4.g_pPaletteLib.md), [UID:0000A1][PaletteLib](../../../../../by-class/PaletteLib.md), and [UID:0001E6][0x005431c0-0x005443ab.PaletteLibMethodCluster](../../../../../by-memory/0x005431c0-0x005443ab.PaletteLibMethodCluster.md)

Readonly binary/exported evidence:

- `core/data/readonly/prewave/exported-functions/0x00467b30.json`
- `core/data/readonly/prewave/exported-functions/0x00468250.json`
- `core/data/readonly/prewave/exported-functions/0x004682c0.json`
- `core/data/readonly/prewave/exported-functions/0x004684a0.json`
- `core/data/readonly/prewave/exported-functions/0x00468520.json`
- `core/data/readonly/prewave/exported-functions/0x00468800.json`
- `core/data/readonly/prewave/exported-functions/0x00468ab0.json`
- `core/data/readonly/prewave/exported-functions/0x00468ae0.json`
- `core/data/readonly/prewave/exported-functions/0x00468b90.json`
- `core/data/readonly/prewave/exported-functions/0x00468e00.json`
- `core/data/readonly/prewave/exported-functions/0x00468f65.json`
- `core/data/readonly/prewave/exported-functions/0x00468f70.json`
- `core/data/readonly/prewave/exported-functions/0x00468f80.json`
- `core/data/readonly/prewave/exported-functions/0x0050e100.json`

IDA availability note:

- I attempted to query the local IDA MCP endpoint at `http://127.0.0.1:13337/mcp`; it was not reachable in this session (`Unable to connect to the remote server`). This report therefore does not claim a fresh live IDA recheck on 2026-06-19. It revalidates against the current by-* docs/generated ledgers plus readonly exported-function records and a local PE branch scan.

Local PE branch scan over `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

```text
0x00468250: no direct E8/E9 branch hits
0x00468e00: no direct E8/E9 branch hits
0x00467b30: CALL@0x0046829d, CALL@0x0046846c, CALL@0x004687a3, CALL@0x00468a54
0x004682c0: CALL@0x0050e1b9, CALL@0x00511906
0x00468b90: CALL@0x00468418
0x00468f80: JMP@0x00468f6b, JMP@0x00468f76
```

Dry validator baseline for the unmodified current target:

> Executable block R001 was removed from this report and preserved verbatim in [0000YZ-BalloonObjectPane-source-quality-removed.md](0000YZ-BalloonObjectPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result: exit `0`, `ok: 1`, dry run only, current metadata unchanged.

## Ownership and source placement

Direct semantic owner:

- Use [UID:00000U][BalloonObjectPane](../../../../../by-class/BalloonObjectPane.md). The range is the class's paint, constructor/layout, update, surface, destructor, and compiler-thunk cluster.
- [UID:0000HJ][AttachedObjectPane](../../../../../by-file/AttachedObjectPane.md) remains the source file parent and generated output route, not the narrow semantic owner.
- This mirrors current already-applied routing for [UID:000276] static masks and [UID:0002WU] pool static storage: both are direct BalloonObjectPane children and still generate into `NexusTK/map/AttachedObjectPane.cpp`.

Rejected owners:

- Reject `MapPane` as direct owner. `MapPane` owns creation/packet helpers (`0x0050e100`, `0x00511710`) and collision queries (`0x005062f0`), but this target body is class implementation for the attached speech balloon pane.
- Reject `AttachedObjectPane` as direct owner. It is a base/source-file family, but the fields, vtables, static pool, masks, and methods are specific to `BalloonObjectPane`.
- Reject `GrafPort`, `FontImageLib`, `PaletteLib`, and `LivingObjectPane` as direct owners. They are service/base collaborators used by the class.

Source placement:

- Keep source route through [UID:0000HJ][AttachedObjectPane](../../../../../by-file/AttachedObjectPane.md), proposed path `NexusTK/map/AttachedObjectPane.cpp`.
- Do not move this class to a dedicated `BalloonObjectPane.cpp` unless the proposed source tree or future source evidence changes. Current support docs explicitly group `AttachedObjectPane`, `BalloonObjectPane`, `DamageNumberObjectPane`, `HitBarObjectPane`, and `ObjectInfoObjectPane` under the attached-object pane source family.

## Function and split map

The aggregate target should remain a reviewed method cluster unless/until the supervisor authorizes exact method child pages. Recommended source-facing names:

| Range | Current/raw name | Recommended source-facing role | Evidence and notes |
| --- | --- | --- | --- |
| `0x00467b30-0x00468241` | `sub_467B30` | `BalloonObjectPane::PaintBubble` | Direct calls at `0x0046829d`, `0x0046846c`, `0x004687a3`, `0x00468a54`; draws frame/tail/text using static masks, `g_useEpfAssets`, `g_pPaletteLib`, text lines, style, and colors. |
| `0x00468241-0x00468250` | padding/gap | non-source alignment | Do not create code for the gap. |
| `0x00468250-0x004682bc` | raw helper | `BalloonObjectPane::RefreshBubbleSurface` preferred; `RepaintBubbleSurface` acceptable alternate | Source-shaped method body reads `m_bubbleGrafPort`, gets bounds, begins paint, calls `PaintBubble`, ends paint. Exported records and PE branch scan show no direct branch callers, so document liveness as unresolved/possibly orphaned. |
| `0x004682bc-0x004682c0` | padding/gap | non-source alignment | Do not create code for the gap. |
| `0x004682c0-0x0046849c` | `sub_4682C0` | `BalloonObjectPane::BalloonObjectPane` | Constructor called from `0x0050e1b9` and `0x00511906`; calls `AttachedObjectPane` base constructor with type `6`, installs three Balloon vptrs, copies/clamps text, initializes style/colors, allocates `GrafPort`, calls `GrafPort::EnableSoftwareBuffer`, calculates layout, and paints if non-empty. |
| `0x0046849c-0x004684a0` | padding/gap | non-source alignment | Do not create code for the gap. |
| `0x004684a0-0x0046851d` | `sub_4684A0` | constructor EH cleanup helper; no source method | Resets vtables, releases owner-side linked state, deletes cached `GrafPort`, and calls `AttachedObjectPane` destructor during construction failure paths. Do not model as public destructor. |
| `0x00468520-0x004687fc` | `sub_468520` | `BalloonObjectPane::UpdatePositionForDirection` | Vtable xref at `0x006130d0`; uses `g_movementSubstepScale`, tile dimensions, direction conversion helpers, cached surface repaint, and `PaintBubble`. |
| `0x004687fc-0x00468800` | padding/gap | non-source alignment | Do not create code for the gap. |
| `0x00468800-0x00468aab` | `sub_468800` | `BalloonObjectPane::UpdatePosition` | Vtable xref at `0x006130d4`; calls shared attached-position helper `0x005386c0`, uses tile dimensions, moves/repaints cached surface. |
| `0x00468aab-0x00468ab0` | padding/gap | non-source alignment | Do not create code for the gap. |
| `0x00468ab0-0x00468ada` | `sub_468AB0` | provisional `BalloonObjectPane::ClearRenderBounds` | Vtable xref at `0x006130b4`; clears two Rect-like outputs. Keep name provisional until base virtual contract is named. |
| `0x00468ada-0x00468ae0` | padding/gap | non-source alignment | Do not create code for the gap. |
| `0x00468ae0-0x00468b81` | `sub_468AE0` | `BalloonObjectPane::MoveBubbleSurface` | Vtable xref at `0x006130c0`; if cached `GrafPort` exists, begins paint, computes old/new rects, and blits/moves the cached surface into the destination port. |
| `0x00468b81-0x00468b90` | padding/gap | non-source alignment | Do not create code for the gap. |
| `0x00468b90-0x00468df1` | `sub_468B90` | `BalloonObjectPane::CalculateLayout` | Single direct caller `0x00468418` from constructor; wraps text, records line offsets/count, computes bounds from owner anchor, queries `MapPane::HasObjectIntersectingRect`, selects tail side, sets bounds, and prepares cached surface dimensions. |
| `0x00468df1-0x00468e00` | padding/gap | non-source alignment | Do not create code for the gap. |
| `0x00468e00-0x00468f65` | `FUN_00468e00` / no IDA function | `BalloonObjectPane::WrapTextLines` preferred; `MeasureWrappedTextWidth` acceptable alternate | Source-shaped raw helper duplicates the text wrapping/measurement half of `CalculateLayout`, writes `m_lineCount`/line offsets, returns width plus one, and calls `FontImageLib::MeasureGlyphWidth` at `0x00468e8c`. Exported records and PE branch scan show no direct branch callers, so liveness remains unresolved. |
| `0x00468f65-0x00468f70` | `sub_468F65` | secondary-base destructor adjustor thunk | Vtable data xref at `0x006130dc`; `sub ecx, 0xa0; jmp 0x00468f80`. Compiler-generated, no source C++ method. |
| `0x00468f70-0x00468f7b` | `sub_468F70` | tertiary-base destructor adjustor thunk | Vtable data xref at `0x0061310c`; `sub ecx, 0xa4; jmp 0x00468f80`. Compiler-generated, no source C++ method. |
| `0x00468f7b-0x00468f80` | padding/gap | non-source alignment | Do not create code for the gap. |
| `0x00468f80-0x0046904e` | `sub_468F80` | `BalloonObjectPane` scalar deleting destructor wrapper around `~BalloonObjectPane` cleanup | Primary vtable xref at `0x00613064`; thunks jump here. Ordinary source destructor cleanup is real, but delete-flag handling and pool/sized-free selection are compiler/allocator artifacts. |

Split recommendation:

- Keep [UID:0000YZ] as a high-confidence aggregate index with no C++ if no child pages are created.
- If implementation later emits C++, split method children first for at least `PaintBubble`, constructor, `UpdatePositionForDirection`, `UpdatePosition`, `MoveBubbleSurface`, `CalculateLayout`, ordinary destructor cleanup, and the two raw helpers if retained.
- Do not make child pages for padding gaps or adjustor thunk source bodies. Vtable/thunk evidence belongs in class/vtable support docs or in method notes.
- Treat `0x004684a0` as constructor unwind/cleanup glue. It can be documented in the aggregate but should not be presented as a user-authored method.

## Raw helper liveness and naming

### `0x00468250-0x004682bc`

Preferred name: `BalloonObjectPane::RefreshBubbleSurface`.

Rejected names:

- Reject `DirtyFlagSetter`; [UID:0002J1] now correctly names `0x004b8be0` as `GrafPort::EnableSoftwareBuffer`, and this helper does not set that flag.
- Reject generic `raw repaint helper` as the final source-facing name. It hides the actual behavior and keeps a compiler label in the report.
- `RepaintBubbleSurface` is acceptable if the owner prefers verb consistency with existing render docs, but `RefreshBubbleSurface` better matches "cached surface is already present; repaint its current bounds."

Evidence checked:

- Exported record `0x00468250.json` shows a source-shaped `BalloonObjectPane` method, size ending before constructor padding, no Ghidra callers, no IDA function callers, and callees `0x004b8e00`, `0x004b7eb0`, `0x004b9820`, `0x00467b30`, `0x004b98c0`, and security cookie.
- Local PE scan found no direct E8/E9 branch hits to `0x00468250`.

Impact:

- This is real class code, but caller liveness is not proven. It should stay in the aggregate evidence and can be a private method child with an explicit "no direct caller recovered" note if a later implementation splits method pages.
- Do not use it as the reason to emit monolithic C++ from the aggregate.

### `0x00468e00-0x00468f65`

Preferred name: `BalloonObjectPane::WrapTextLines`.

Alternate: `BalloonObjectPane::MeasureWrappedTextWidth`.

Rejected names:

- Reject `FUN_00468e00`.
- Reject a `FontImageLib` owner: the only external behavior is glyph measurement through `FontImageLib::MeasureGlyphWidth`; the helper writes BalloonObjectPane text layout fields.
- Reject a standalone free helper unless future xref evidence proves non-member call sites. The first parameter is the Balloon object and all durable side effects are Balloon fields.

Evidence checked:

- Exported record `0x00468e00.json` has no IDA function name and no recovered callers, but a complete source-shaped body.
- It zeroes `*(uint16_t *)(this + 0x1c6)`, scans the wide text at `this + 0x12c`, calls `FontImageLib::MeasureGlyphWidth` at `0x00468e8c`, writes line offsets at `this + 0x1c6 + 2 * lineIndex`, writes `m_lineCount` at `this + 0x1c4`, and returns measured width plus one.
- Local PE scan found no direct E8/E9 branch hits to `0x00468e00`.
- `FontImageLibMeasureGlyphWidth` support currently sees caller `0x00468e8c` without a function object; that should be updated to identify this Balloon raw helper.

Impact:

- This resolves the target's missing raw helper coverage: the target should explicitly add the `0x00468e00-0x00468f65` anchor and notes.
- Liveness uncertainty caps target completion/confidence below final-source quality. It is still source-shaped enough to document with a source-facing name and alternatives.

## Field/type/global/helper names

Recommended `BalloonObjectPane` field names for target/class docs:

| Offset | Recommended name | Evidence and caveats |
| --- | --- | --- |
| `+0x128` | `m_attachedObject` or `m_ownerObject` | Constructor stores first argument after base constructor. Creation helpers pass the `LivingObjectPane`/object pane being attached to. Prefer `m_attachedObject` if aligning with AttachedObjectPane vocabulary; `m_ownerObject` is acceptable but less source-specific. |
| `+0x12c` | `m_text[70]` | Constructor copies up to `0x45` wide chars with destination capacity `0x46`; terminates at `this + 0x12c + 2 * length`; truncation path writes ellipsis and NUL at the tail of this buffer. |
| `+0x1b8` | `m_balloonStyle` | Constructor stores `a7`; packet/creation helpers map style subtypes to constants `143`, `14`, `9`, `200`, `253`; paint reads this for palette/frame/text selection and constructor copies it to inherited/state offset `+0xb8`. |
| `+0x1bc` | `m_textColor` or `m_customTextColor` | Constructor stores `a8`; custom-color packet subtype passes caller-provided values. Use `m_textColor` in first-draft C++ unless a later support doc proves it is only valid for custom subtype. |
| `+0x1c0` | `m_frameColor` or `m_customFrameColor` | Constructor stores `a9`; used by paint/color selection. Pair with `m_textColor`. |
| `+0x1c4` | `m_lineCount` | Written by `CalculateLayout` and raw wrap helper; consumed by `PaintBubble` text loop. |
| `+0x1c6` | `m_lineStartOffsets` / `m_lineBreakOffsets` | Array of 16-bit offsets into `m_text`, written by wrapping logic. Prefer `m_lineStartOffsets` if code treats entries as starts; prefer `m_lineBreakOffsets` if preserving decompiler shape. |
| `+0x1d8` | `m_tailEdge` | Layout sets `0` or `2` depending on collision/tail placement; paint reads it to draw tail direction. |
| `+0x1da` | `m_tailAnchorX` or `m_tailAnchorOffset` | Layout/update methods adjust tail anchor along the bubble edge; paint consumes it for tail geometry. |
| `+0x1dc` | `m_bubbleGrafPort` | Constructor allocates 160-byte `GrafPort`, calls `GrafPort::EnableSoftwareBuffer`, cached paint/move methods use it, destructor deletes it. |

Recommended source-facing collaborators:

| Raw/current symbol | Recommended name | Evidence |
| --- | --- | --- |
| `byte_66DA97` | `g_useEpfAssets` | Current global support docs and project alias ledger resolve this as the broad EPF/current asset selector, not an attachment-only mode flag. |
| `dword_67A7E0` / `dword_67a7e0` | `g_pPaletteLib` | Current [UID:0000RW] global page and `project-level/-resolved.md` resolve this pointer. Paint should reference `g_pPaletteLib`, not a provisional `g_paletteManager`. |
| `byte_66DA96` | `g_movementSubstepScale` | Movement/update helpers divide by `4 * byte_66DA96`; global support resolves the name. |
| `word_66DA9C` | `g_mapTilePixelWidth` | Update-position methods read the map tile width. |
| `word_66DAA0` | `g_mapTilePixelHeight` | Update-position methods read the map tile height. |
| `0x004b8be0` | `GrafPort::EnableSoftwareBuffer` | Support page now supersedes the old dirty-flag name; constructor calls this after constructing the cached `GrafPort`. |
| `0x004b6020` | `FontImageLib::MeasureGlyphWidth` | Layout/wrap helpers use it for text measurement. Final FontImageLib signature is still support-owned. |
| `0x005062f0` | `MapPane::HasObjectIntersectingRect` | Layout uses this to choose whether to offset the bubble and tail side. Do not re-own it under BalloonObjectPane. |
| `0x0053ada0` | `LivingObjectPane::SetLinkedGroundObject` | Current LivingObjectPane support names the helper and shows Balloon creation callers at `0x0050e1df` and `0x0051192c`. Target notes should use the current support name while documenting the Balloon caller role. |
| `0x0050e100` | `MapPane::CreateSpeechBalloonForObject` provisional | Exported record shows style mapping, pool allocation, constructor call, owner-side link, registration, timer/scheduler insertion, and bounds refresh. No by-memory support page was found in current docs; keep name provisional. |
| `0x00511710` | `MapPane::HandleMovementSpeechBalloonPacket` | Existing support page owns this packet handler and should consume the refreshed constructor parameter names. |

Constructor signature recommendation for documentation and future C++:

```cpp
BalloonObjectPane::BalloonObjectPane(
    LivingObjectPane *attachedObject,
    int anchorX,
    int anchorY,
    const wchar_t *text,
    uint8_t textLength,
    int balloonStyle,
    int textColor,
    int frameColor);
```

Notes:

- `textLength`, not a custom-color flag, is the `unsigned __int8` argument. The constructor clamps it to `0x45` before `_wcsncpy_s`.
- Custom color semantics are controlled by packet/creation helpers and the values passed in `textColor`/`frameColor`; do not invent `m_customPaletteMode` at `+0x1b8`.
- The base constructor call is `AttachedObjectPane(..., type 6, attachedObject, anchorX, anchorY)`.

## Vtables, adjustors, destructor, and compiler glue

Vtable evidence:

- The read-only support page records primary `BalloonObjectPane` vtable data at `0x00613064`, secondary at `0x006130dc`, and tertiary at `0x0061310c`.
- First slots are `0x00468f80`, `0x00468f65`, and `0x00468f70`.
- `0x00468f65` adjusts `ECX` by `-0xa0` and jumps to `0x00468f80`.
- `0x00468f70` adjusts `ECX` by `-0xa4` and jumps to `0x00468f80`.

Recommended handling:

- Do not emit adjustor thunk bodies as source C++.
- Document the thunks as compiler-generated multiple-inheritance destructor adjustors.
- Update [UID:00037M][BackGroundBalloonBlackHoleReadOnlyData](../../../../../by-memory/0x00612f3c-0x006131b4.BackGroundBalloonBlackHoleReadOnlyData.md) to say the Balloon vtable spans are directly owned by [UID:00000U][BalloonObjectPane], with source route through [UID:0000HJ][AttachedObjectPane]. The current wording that makes [UID:0000HJ] the direct owner is stale after masks/pool and this target are routed through the class.

Destructor handling:

- `0x00468f80` is a scalar deleting destructor wrapper. It contains ordinary destructor cleanup plus compiler delete-flag/free handling.
- The source destructor body should cover resetting vptrs as appropriate for compiled output, notifying/releasing owner-side linked overlay state as proven, deleting `m_bubbleGrafPort`, and calling the `AttachedObjectPane` destructor.
- The pool free path through `0x0069b9fc` and the sized-delete path are compiler/allocator artifacts controlled by scalar deleting destructor flags. They should be documented, but not hand-emitted as ordinary destructor source.
- `0x004684a0` is constructor cleanup/unwind helper, not a second source destructor.

LivingObjectPane caveat:

- Current LivingObjectPane support proves `0x0053ada0` stores a linked object at owner slot `+0x1d8` and names it `LivingObjectPane::SetLinkedGroundObject`.
- The exported `0x0050e100` creation helper calls an owner-side release at `a3[121]` (`+0x1e4`) before calling `SetLinkedGroundObject`; the scalar deleting destructor also checks owner `+0x1e4` and calls a virtual release callback if present.
- Therefore target/support notes should avoid claiming the destructor definitely clears the exact same `+0x1d8` slot used by `SetLinkedGroundObject`. State the exact evidence instead: Balloon creation links via `SetLinkedGroundObject`; cleanup paths also notify/release an owner-side linked overlay object through the owner-side `+0x1e4` slot. Final owner-side slot naming remains LivingObjectPane-owned.

## Static masks and pool support

[UID:000276][BalloonObjectPaneStaticMasks](../../../../../by-memory/0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks.md):

- Already correctly uses `CANONICAL_OWNER:00000U` and `EMITTER_UIDS:00000U`.
- Keep source-facing name `s_balloonFrameMasks` or `s_balloonTailMasks`.
- Exact six dwords are:
  - `0x101028C6`
  - `0xC6281010`
  - `0x80804030`
  - `0x101020C0`
  - `0x30408080`
  - `0xC0201010`
- Target/class docs should reference the support child instead of restating stale `unk_66D414` labels.

[UID:0002WU][BalloonObjectPanePoolStaticStorage](../../../../../by-memory/0x0069b9fc-0x0069ba24.BalloonObjectPanePoolStaticStorage.md):

- Already correctly uses `CANONICAL_OWNER:00000U` and `EMITTER_UIDS:00000U`.
- Keep source-facing name `s_balloonObjectPanePool` unless a future allocator support page recovers an exact pool template declaration.
- Exact evidence: storage range `0x0069b9fc-0x0069ba24`, size `0x28` bytes, block size `0x1e0`, chunk count `0x10`.
- Creation paths allocate through `0x004b1400` with pool base `0x0069b9fc`; destructor frees through pool path via `0x004b14c0` depending on scalar deleting destructor flags.

No score/owner metadata change is required for these two support children. The target should align to their already-correct class owner/emitter.

## Support-doc changes to apply after supervisor approval

Do not apply these in the current report-only pass. If implementation is authorized, apply these exact support changes:

1. `by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md`
   - Change metadata to `88/91`, `CANONICAL_OWNER:00000U`, `EMITTER_UIDS:00000U`, `RECONSTRUCTABLE:TRUE`.
   - Keep formal C++ blank.
   - Add `0x00468e00-0x00468f65` to anchors/range notes as `BalloonObjectPane::WrapTextLines` / `MeasureWrappedTextWidth`.
   - Rename `0x00468250` from raw repaint caveat to `BalloonObjectPane::RefreshBubbleSurface` with explicit no-direct-caller evidence.
   - Replace raw helper/global labels in prose with `g_useEpfAssets`, `g_pPaletteLib`, `g_movementSubstepScale`, `g_mapTilePixelWidth`, `g_mapTilePixelHeight`, `GrafPort::EnableSoftwareBuffer`, `FontImageLib::MeasureGlyphWidth`, `MapPane::HasObjectIntersectingRect`, and `LivingObjectPane::SetLinkedGroundObject`.
   - Correct constructor parameter description: `a6` is `textLength`, clamped to `0x45`; `a7/a8/a9` are style/text-color/frame-color values.
   - Add vtable/adjustor handling and destructor compiler-glue caveats.

2. `by-class/BalloonObjectPane.md`
   - Text refresh only; keep metadata `85/90`, `CANONICAL_OWNER:0000HJ`, `EMITTER_UIDS:0000HJ`, and blank C++ unless method child pages are created.
   - Update method inventory with the full split map above, including `0x00468e00`.
   - Add field table offsets `+0x128`, `+0x12c`, `+0x1b8`, `+0x1bc`, `+0x1c0`, `+0x1c4`, `+0x1c6`, `+0x1d8`, `+0x1da`, `+0x1dc`.
   - Add explicit "direct children" notes for [UID:0000YZ], [UID:000276], and [UID:0002WU].
   - Keep first-draft C++ blocked until method child pages or class-level method bodies are intentionally emitted.

3. `by-file/AttachedObjectPane.md`
   - Text refresh only; keep metadata `86/86`, `CANONICAL_OWNER:FILE`, `EMITTER_UIDS:FILE`.
   - In proposed contents/boundary notes, route Balloon source through [UID:00000U] and mention both raw helpers (`0x00468250`, `0x00468e00`) as class-specific issues.
   - Do not make the file page the direct owner of [UID:0000YZ].

4. `by-memory/0x00612f3c-0x006131b4.BackGroundBalloonBlackHoleReadOnlyData.md`
   - Text refresh only; keep mixed-data/non-emitting metadata.
   - Change the Balloon vtable ownership-split prose so `0x00613064-0x00613118` points directly to [UID:00000U][BalloonObjectPane], with source route through [UID:0000HJ][AttachedObjectPane].
   - Keep adjustor thunk handling as compiler-generated vtable data, not source bodies.

5. `by-memory/0x004b6020-0x004b60ae.FontImageLibMeasureGlyphWidth.md`
   - Text refresh only unless owner decides score changes are warranted.
   - Add caller-role note: `0x00468e8c` is inside raw `BalloonObjectPane::WrapTextLines` (`0x00468e00-0x00468f65`), not an unclassified nearby UI/text caller.

6. `by-memory/0x00511710-0x005119ac.MapPaneHandleMovementSpeechBalloonPacket.md`
   - Text refresh only.
   - Update constructor-call argument names to `attachedObject`, `anchorX`, `anchorY`, `text`, `textLength`, `balloonStyle`, `textColor`, `frameColor`.
   - Keep ownership under `MapPane`; do not move packet parsing into BalloonObjectPane.

7. `by-memory/0x0053aaf0-0x0053aeb4.LivingObjectPaneLinkedObjectSetupHelpers.md`
   - Text refresh only.
   - Add Balloon caller note for `0x0050e1df` and `0x0051192c`: creation helpers call `LivingObjectPane::SetLinkedGroundObject` with the newly constructed `BalloonObjectPane`.
   - Add caveat that Balloon destructor/creation cleanup also touches an owner-side `+0x1e4` linked overlay slot; do not collapse that into `+0x1d8` without LivingObjectPane-owned evidence.

8. `by-memory/0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter.md`
   - No required metadata change. If edited, ensure title/prose remains `GrafPort::EnableSoftwareBuffer` and target references use that name.

9. Global/support ledgers
   - If target prose removes stale generated labels, the unresolved ledger should no longer list this target for lowercase `dword_67a7e0`, `byte_66da97`, `sub_50E100`, or `sub_511710` after validator/rescore/autogen updates.
   - Do not manually edit generated project ledgers except through approved validator flow.

## Score rationale

Why raise completion from `84` to `88`:

- Direct owner/emitter can now be corrected to [UID:00000U] by matching current masks/pool support and class direct ownership rules.
- The previously missing `0x00468e00-0x00468f65` raw helper is identified, source-named, and bounded.
- The `0x00468250` repaint helper has a source-facing name and explicit liveness evidence.
- Current support docs resolve several stale raw/global names: `g_useEpfAssets`, `g_pPaletteLib`, `g_movementSubstepScale`, `g_mapTilePixelWidth`, `g_mapTilePixelHeight`, `GrafPort::EnableSoftwareBuffer`, `FontImageLib::MeasureGlyphWidth`, `MapPane::HasObjectIntersectingRect`, and `LivingObjectPane::SetLinkedGroundObject`.
- Constructor signature and fields can be documented more accurately: `a6` is `textLength`, not a style/custom-color mode.
- Vtable thunks and scalar deleting destructor compiler glue can be separated from source-authored class behavior.

Why not raise above `88/91`:

- IDA MCP was unavailable for this refresh; evidence is strong but not a fresh live IDA session.
- Both raw helpers have no recovered direct E8/E9 callers in the PE scan and no callers in exported records. They are source-shaped but liveness/orphan status remains unresolved.
- The aggregate still has no exact method child split, so emitting C++ from [UID:0000YZ] would mix source methods, padding, constructor EH cleanup, adjustor thunks, and scalar deleting destructor wrapper code.
- `ClearRenderBounds` remains provisional because the base virtual contract name is not recovered.
- The LivingObjectPane owner-side cleanup slot relationship (`+0x1d8` setter vs `+0x1e4` release path) is not fully resolved within Balloon evidence.
- Final source names for some style/color fields are inferred from behavior and packet constants, not from recovered source.

Confidence `91` is justified because the method boundaries, call graph, fields, owner, emitter route, static data children, and key collaborators all agree across current docs, exported records, and PE branch scanning. It should remain below final/audit confidence because of the unresolved raw helper liveness and the unavailable live IDA endpoint.

## First-draft C++ readiness

Aggregate [UID:0000YZ]:

- Do not emit C++ here.
- Keep the code block blank.
- The page can become a high-quality index with exact method map and implementation checklist.

Ready for method-level first-draft C++ after split:

- `BalloonObjectPane::PaintBubble`
- `BalloonObjectPane::BalloonObjectPane`
- `BalloonObjectPane::UpdatePositionForDirection`
- `BalloonObjectPane::UpdatePosition`
- `BalloonObjectPane::MoveBubbleSurface`
- `BalloonObjectPane::CalculateLayout`
- ordinary `BalloonObjectPane::~BalloonObjectPane` cleanup, excluding scalar deleting wrapper flags

Partially ready but must carry explicit caveats:

- `BalloonObjectPane::RefreshBubbleSurface`: body is clear, but direct caller liveness is not proven.
- `BalloonObjectPane::WrapTextLines`: body is clear, but direct caller liveness is not proven and it duplicates the wrapping portion of `CalculateLayout`.
- `BalloonObjectPane::ClearRenderBounds`: behavior is clear, but final virtual-contract name is not.

Never emit as source bodies:

- padding gaps
- `0x004684a0` constructor unwind helper
- `0x00468f65` and `0x00468f70` destructor adjustor thunks
- scalar deleting destructor free-flag wrapper logic, except as notes around ordinary destructor and allocator behavior

Minimal first-draft declarations after method split:

```cpp
class BalloonObjectPane : public AttachedObjectPane {
public:
    BalloonObjectPane(LivingObjectPane *attachedObject,
                      int anchorX,
                      int anchorY,
                      const wchar_t *text,
                      uint8_t textLength,
                      int balloonStyle,
                      int textColor,
                      int frameColor);
    ~BalloonObjectPane();

private:
    void PaintBubble(GrafPort *port, const Rect &bounds);
    void RefreshBubbleSurface();
    void CalculateLayout();
    int WrapTextLines();
    void MoveBubbleSurface(GrafPort *destination);
    void UpdatePositionForDirection(int direction);
    void UpdatePosition();
    void ClearRenderBounds(Rect *primary, Rect *secondary);
};
```

This declaration is only a readiness sketch. Do not paste it into [UID:0000YZ] as final C++ without exact child pages and local type/header conventions.

## Implementation checklist for a later authorized edit pass

1. Confirm scope before editing.
   - Make sure the supervisor authorized by-* edits.
   - Reopen the current target/support docs to detect intervening changes.
   - Do not revert any unrelated edits.

2. Update [UID:0000YZ] metadata.
   - Set `COMPLETION:88`.
   - Set `CONFIDENCE:91`.
   - Set `CANONICAL_OWNER:00000U`.
   - Keep `RECONSTRUCTABLE:TRUE`.
   - Set `EMITTER_UIDS:00000U`.

3. Update [UID:0000YZ] body.
   - Replace stale owner rationale with direct `BalloonObjectPane` class ownership and source route through `AttachedObjectPane`.
   - Add the full function/split map from this report.
   - Add `0x00468e00-0x00468f65` as a raw source-shaped helper.
   - Rename `0x00468250` to `RefreshBubbleSurface` with no-direct-caller evidence.
   - Replace stale raw/global names with the resolved support names.
   - Correct constructor parameter/field discussion, especially `textLength`.
   - Add vtable/thunk/destructor compiler-glue section.
   - Keep C++ blank and state why.

4. Update support docs if authorized.
   - Apply the support-doc changes listed in the previous section.
   - Keep support metadata unchanged unless the supervisor explicitly approves support score updates.
   - Do not edit `by-memory/-coverage-report.md` until the supervisor-owned row update step.

5. Update exact coverage row.
   - Replace the [UID:0000YZ] row in `by-memory/-coverage-report.md` with the exact row from this report.
   - Preserve four-space indentation before `-`.

6. Run validators after implementation.
   - Run file-mode apply on every by-* page changed.
   - Run file-mode apply on `by-memory\-coverage-report.md` if the coverage row was changed.
   - Run autogen and rescore apply after all edited docs are validated.

Recommended validator commands after implementation:

> Executable block R002 was removed from this report and preserved verbatim in [0000YZ-BalloonObjectPane-source-quality-removed.md](0000YZ-BalloonObjectPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the implementation only edits [UID:0000YZ] and the coverage row, omit the support-doc validator commands for pages not changed. If method child pages are created, run file-mode apply for each new child before validating the aggregate/class/file pages.

## Open questions to preserve

- Is `0x00468250` genuinely live through an indirect path, or is it an orphaned private repaint helper left in the binary? Current exported records and PE branch scan found no direct callers.
- Is `0x00468e00` genuinely live through an indirect path, or a previous/extracted wrap routine made unreachable after `CalculateLayout` inlined/duplicated the logic? Current exported records and PE branch scan found no direct callers.
- What is the exact source name for the `0x00468ab0` virtual that clears two Rect outputs? `ClearRenderBounds` is behaviorally accurate but not contract-proven.
- What are the exact source names for `m_balloonStyle`, `m_textColor`, and `m_frameColor`? Behavior and packet constants support these names, but exact source identifiers are not recovered.
- How should LivingObjectPane's `+0x1d8` linked-ground slot and `+0x1e4` linked-overlay release path be named relative to Balloon cleanup? The target should defer exact owner-side slot naming to LivingObjectPane docs.

These unresolved items are why the target should stop at `88/91` with blank C++ rather than being promoted to final-source or emitted code.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0000YZ-BalloonObjectPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:30","uid":"0000YZ"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000YZ-BalloonObjectPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/0000YZ-BalloonObjectPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000YZ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
