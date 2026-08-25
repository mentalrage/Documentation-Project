*** UID:00006S | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:020 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class InventoryPane2 : public PanelPane
{
public:
    InventoryPane2();
    virtual ~InventoryPane2();

    virtual void OnActivate(const unsigned char *packetData);
    virtual void OnPaint();
    virtual bool OnKeyEvent(Event *event);
    virtual bool OnMouseEvent(Event *event);
    virtual bool OnServerMessage(Event *message);

private:
    void PlayItemEffect();
    void SendUseItemSlotPacketRaw(unsigned char slot);
    void SendDragDropItemPacketRaw(unsigned char slot, unsigned char dragSource);
    void GetButtonRect(short button, RectBounds *rect) const;
    void GetSlotRect(short slot, RectBounds *rect) const;
    short HitTestButton(int y, int x) const;
    int HitTestSlot(int x, int y) const;
    static int VisibleOrdinalToInventorySlot(int ordinal);

    unsigned char m_pageIndex;
    bool m_isLastPage;
    unsigned char m_reservedFA[2];
    int m_viewMode;
    int m_unusedState;
    int m_listButtonState;
    int m_gridButtonState;
};

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# InventoryPane2

## Status

- Completion/confidence: `94/94`; complete 15-definition source route, class declaration, and inherited `GrafPort::m_visibleBounds` declaration closure with retained raw-start caveats.
- Likely source file: [UID:0000KA][InventoryPane](by-file/InventoryPane.md) / `ui/inventory/InventoryPane.cpp`
- Address range: [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md)
- Exact confirmed source-bearing and compiler-support children: assigned [UID:00031V][0x004ee650-0x004ee6a7.InventoryPane2RawConstructor](by-memory/0x004ee650-0x004ee6a7.InventoryPane2RawConstructor.md), non-emitting split parent [UID:0002SU][0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers](by-memory/0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers.md) with exact source children [UID:00048P][0x004ee6b0-0x004ee6cf.InventoryPane2Destructor](by-memory/0x004ee6b0-0x004ee6cf.InventoryPane2Destructor.md) through [UID:00048X][0x004ef460-0x004ef50b.InventoryPane2SendDragDropItemPacketRaw](by-memory/0x004ef460-0x004ef50b.InventoryPane2SendDragDropItemPacketRaw.md), and exact tail helpers/support split from non-emitting audit container [UID:0002SV][0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor](by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md). [UID:0003ER][0x004efa40-0x004efa95.InventoryPane2ScalarDeletingDestructor](by-memory/0x004efa40-0x004efa95.InventoryPane2ScalarDeletingDestructor.md) is class-owned compiler scalar-delete support, non-reconstructable and non-emitting; source destructor C++ stays with UID00048P.
- Class ownership/emission: this class is owned/emitted by [UID:0000KA][InventoryPane](by-file/InventoryPane.md) at position `020`. Its formal CPP is the sole `[[CHILDREN]]` anchor for exact source children at positions `200-340`; UID0002SU remains a non-emitting index, not a source unit.
- Vtable-data handling: [UID:0003BW][0x0061c86c-0x0061c8f8.InventoryPane2VtableData](by-memory/0x0061c86c-0x0061c8f8.InventoryPane2VtableData.md) is class-owned `InventoryPane2` RTTI/vtable support but is now non-reconstructable/non-emitting generated-binary data. Its decorated table names and constructor/destructor/scalar-deleting vptr stores prove the class relation; they do not imply a source-authored raw vtable array or an empty source marker.
- Final source route: `NexusTK/ui/inventory/InventoryPane.cpp` plus the second declaration in `InventoryPane.h`. Historical recovered/simroot output is lead material only.

## Class Purpose

`InventoryPane2` is an alternate compact item inventory pane. It renders list/grid inventory layouts, supports page navigation, hit-tests fixed item rectangles, and sends the same item use or drag-transfer style actions as the other item inventory panes.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `InventoryPane2` | `[0x004ee650,0x004ee6a7)` | A14/`200`, UID00031V raw constructor; exact hash/fences and zero-route history retained. |
| `~InventoryPane2` | `[0x004ee6b0,0x004ee6cf)` | A15/`210`, UID00048P ordinary destructor. |
| `OnActivate` | `[0x004ee6d0,0x004ee6dc)` | A16/`220`, UID00048Q; packet ignored and inherited `GrafPort::m_visibleBounds` at `+0x44` invalidated. `RefreshEmbeddedPane` and the former pane-local bounds interpretation are superseded history only. |
| `PlayItemEffect` | `[0x004ee6e0,0x004ee6e1)` | A17/`230`, UID00048R intentional real empty source method, never an empty-emitter marker. |
| `OnPaint` | `[0x004ee6f0,0x004eee5c)` | A18/`240`, UID00048S; nine-entry list/3x3 grid rendering, hotkeys and controls. |
| `OnKeyEvent` | `[0x004eee60,0x004eeedc)` | A19/`250`, UID00048T; bounded Page Up/Page Down state changes. |
| `OnMouseEvent` | `[0x004eeee0,0x004ef27a)` | A20/`260`, UID00048U; hover/button states, mode selection, item use and drag/drop. Binary contains direct id-2/id-3 hover checks and a source-equivalent four-id inlined button-hit route at `[0x004ef030,0x004ef075)`; there is no direct xref to retained UID0003EM. The following NOP/table is compiler data. |
| `OnServerMessage` | `[0x004ef290,0x004ef3fc)` | A21/`270`, UID00048V; bounded opcode `0x59` help contract. |
| `SendUseItemSlotPacketRaw` | `[0x004ef400,0x004ef460)` | A22/`280`, UID00048W; retained opcode `0x1c`, length `2` helper. |
| `SendDragDropItemPacketRaw` | `[0x004ef460,0x004ef50b)` | A23/`290`, UID00048X; retained opcode `0x66`, length `10` helper. |
| `GetButtonRect` | `[0x004ef630,0x004ef702)` | A24/`300`, UID0003EJ non-static const member; logical signed-short selector, five ECX-receiver callers, explicit four-case/default InitRectBounds construction, and exact rectangles `(59,259)-(81,277)`, `(112,259)-(134,277)`, `(168,66)-(185,83)`, `(168,84)-(185,101)`. The following table is compiler lowering, not a source array. |
| `GetSlotRect` | `[0x004ef720,0x004ef794)` | A25/`310`, UID0003EL retained 116-byte raw helper; logical `short`, unsigned nine-slot guard, exact list/3x3 geometry, and one final `InitRectBounds` call. The live UID0003EO body inlines this complete geometry. |
| `HitTestButton` | `[0x004ef7a0,0x004ef86d)` | A26/`320`, UID0003EM retained 205-byte/78-instruction raw const member, SHA256 `800405216457402D4E1558484AF61A2AA78968AF38F980EE3D4DB9EF330B9054`; y at stack `+0x08`, x at `+0x0c`, signed-short SI/AX loop/return, one local RectBounds, first-hit/`-1` behavior, zero raw-start code/data xrefs, and an inlined GetButtonRect switch successor. |
| `HitTestSlot` | `[0x004ef890,0x004ef962)` | A27/`330`, UID0003EO; compact slot hit test. |
| `VisibleOrdinalToInventorySlot` | `[0x004ef970,0x004ef9f4)` | A28/`340`, UID0003EP; active one-based inventory mapping. |

UID0003ER scalar deleting destruction, two Pane2 adjustors, five local switch-table/padding spans, and UID0003BW RTTI/vtables are compiler-covered/non-emitting. BackPane V3 remains a separate authored exclusion.

## Field Names From Core Split

| Offset | Name | Evidence-backed role |
| --- | --- | --- |
| `+0x44` | inherited `GrafPort::m_visibleBounds` | Protected `RectBounds` declared by `GrafPort`, inherited through `Pane` and `PanelPane`, and passed to activation, paint, key, and mouse invalidation/render paths. It is not an `InventoryPane2` tail field and is not redeclared in formal H. |
| `+0x70` | `m_drawState` | Draw/text state selector set during item and button rendering. |
| `+0xf8` | `m_pageIndex` | Current page index used by paint, key, and mouse paths. |
| `+0xf9` | `m_isLastPage` | True when no later non-empty item exists; do not invert this to `m_hasNextPage`. |
| `+0xfc` | `m_viewMode` | Dword-sized `int` list/grid selector; `0` is `kListView` and any nonzero value selects the grid path. Do not narrow it or replace its exact nonzero behavior with an enum-only equality test. |
| `+0x100` | `m_unusedState` | Unobserved interior dword retained to preserve proved `+0x104/+0x108` offsets; no semantics are guessed. |
| `+0x104` | `m_listButtonState` | List selector visual state; not an up/previous-page button. |
| `+0x108` | `m_gridButtonState` | Grid selector visual state; not a down/next-page button. |

Constructor source initializes `m_pageIndex`, `m_isLastPage`, `m_viewMode`, `m_listButtonState`, and `m_gridButtonState` through UID00031V. The source-facing constants `kListView`, `kGridView`, and `kButtonNormal` are accepted inferred names consistent with the file-wide formal source and the documented zero/list, nonzero/grid, and normal-button semantics. `m_viewMode` remains an `int`; these constants do not imply a recovered enum declaration. The `PanelPane` base call and `InventoryPane2` vtable stores at `+0x0`, `+0xa0`, and `+0xa4` are compiler-lowered constructor evidence; they should not be emitted as explicit source statements.

## Evidence Notes

- [UID:00031V][0x004ee650-0x004ee6a7.InventoryPane2RawConstructor](by-memory/0x004ee650-0x004ee6a7.InventoryPane2RawConstructor.md) records the exact raw constructor bytes, no-function/no-xref/no-pointer-route status at `0x004ee650`, `PanelPane` base-constructor call, three compiler-lowered `InventoryPane2` vtable stores, state clears, return, `0x004ee6a7-0x004ee6b0` padding, and formal first-draft constructor C++.
- [UID:0002SU][0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers](by-memory/0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers.md) records the repaired non-emitting core `InventoryPane2` split/index from the first modeled helper at `0x004ee6b0` through the retained raw packet helpers ending at `0x004ef50b`, with BackPane V3 excluded at `0x004ef510`.
- [UID:0002SV][0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor](by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md) is now a non-emitting split-audit container. Its exact `InventoryPane2` children are [UID:0003EJ][0x004ef630-0x004ef702.InventoryPane2ButtonRectHelper](by-memory/0x004ef630-0x004ef702.InventoryPane2ButtonRectHelper.md), [UID:0003EL][0x004ef720-0x004ef794.InventoryPane2SlotRectBuilderRaw](by-memory/0x004ef720-0x004ef794.InventoryPane2SlotRectBuilderRaw.md), [UID:0003EM][0x004ef7a0-0x004ef86d.InventoryPane2ButtonHitTestRaw](by-memory/0x004ef7a0-0x004ef86d.InventoryPane2ButtonHitTestRaw.md), [UID:0003EO][0x004ef890-0x004ef962.InventoryPane2SlotHitTest](by-memory/0x004ef890-0x004ef962.InventoryPane2SlotHitTest.md), [UID:0003EP][0x004ef970-0x004ef9f4.InventoryPane2VisibleIndexToInventorySlot](by-memory/0x004ef970-0x004ef9f4.InventoryPane2VisibleIndexToInventorySlot.md), and [UID:0003ER][0x004efa40-0x004efa95.InventoryPane2ScalarDeletingDestructor](by-memory/0x004efa40-0x004efa95.InventoryPane2ScalarDeletingDestructor.md). The interleaved [UID:00018M][0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3](by-memory/0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3.md) remains excluded from `InventoryPane2` ownership.
- 2026-08-15 B006 UID0003EL evidence closes the slot-rectangle ABI/call-shape details: `[0x004ef720,0x004ef794)` is exactly 116 bytes / 45 instruction heads, reads a low-word logical `short`, applies an unsigned `0..8` guard before signed arithmetic, reads `m_viewMode` at `+0xfc`, and converges invalid/list/grid paths on one free `InitRectBounds` call. The former valid-path `RectBounds::SetLTRB` source shape is rejected because the target calls the distinct free helper only.
- Live [UID:0003EO][0x004ef890-0x004ef962.InventoryPane2SlotHitTest](by-memory/0x004ef890-0x004ef962.InventoryPane2SlotHitTest.md) inlines the complete UID0003EL geometry and is called at `0x004ef09a`, `0x004ef165`, and `0x004ef1a4`. This resolves source liveness while preserving the retained raw copy's no-function/no-direct-xref history. The legacy UID00051B low-word/one-call body and modeled NewInventoryPane `__int16` helper independently corroborate the short declaration.
- 2026-08-15 B001 UID0003EM accepted evidence closes the adjacent button-helper declarations without weakening B006's slot correction. UID0003EJ's five callers prepare the receiver in ECX and the two-argument callee-cleanup body consumes a signed-short selector; UID0003EM's exact raw body proves y/x argument order, signed-short return, first-hit/`-1` behavior, and GetButtonRect inlining. The complete H therefore declares all three methods as non-static const members and retains `void GetSlotRect(short slot, RectBounds *rect) const;` exactly.
- UID0003EM's successor spans remain compiler-only: `[0x004ef86d,0x004ef870)` is 3-byte NOP alignment, `[0x004ef870,0x004ef884)` is the five-target table with SHA256 `6FCD267F3BE4A21003EC3BBAF2A03040E1037A54ABCA6CFBCEE4BC152738C740` and sole inbound data xref `0x004ef7c1`, and `[0x004ef884,0x004ef890)` is 12-byte CC padding. No class/static data declaration is emitted.
- [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md) records the broader inventory executable neighborhood, source-split map, and the three interleaved BackPane packet helpers that should not be treated as inventory-owned methods.
- [UID:00025L][0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData](by-memory/0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData.md) records the `InventoryPane2` primary, secondary, and tertiary vtables at `0x0061c870`, `0x0061c8c0`, and `0x0061c8f0`.
- [UID:0003BW][0x0061c86c-0x0061c8f8.InventoryPane2VtableData](by-memory/0x0061c86c-0x0061c8f8.InventoryPane2VtableData.md) records the exact non-emitting `InventoryPane2` RTTI/vtable island, including locator cells at `0x0061c86c`, `0x0061c8bc`, and `0x0061c8ec`, primary/secondary/tertiary table bases at `0x0061c870`, `0x0061c8c0`, and `0x0061c8f0`, current MCP byte/dword evidence, pointer-scan negatives, no local `InventoryPane2` UDT, and the generated-empty-marker symptom that motivated clearing the target emitter.
- [UID:0003ER][0x004efa40-0x004efa95.InventoryPane2ScalarDeletingDestructor](by-memory/0x004efa40-0x004efa95.InventoryPane2ScalarDeletingDestructor.md) records current MCP session `43ccf853` scalar-wrapper proof: exact range `0x004efa40-0x004efa95`, ten-byte predecessor padding, eleven-byte successor padding before legacy `InventoryPane` scalar delete at `0x004efaa0`, primary vtable cell `0x0061c870 -> 0x004efa40`, secondary/tertiary adjustor cells `0x0061c8c0 -> 0x004ef9f4` and `0x0061c8f0 -> 0x004ef9ff`, vtable restore stores, `sub_5450D0` cleanup, flag-gated optional `sub_4F4AC0`, and guard-check support. It is class-owned ABI documentation, not a source-emitting method.
- B004 current MCP evidence keeps the exact original `InventoryPane2` header/source split and full inherited slot signature recovery as confidence caps only. Real source behavior still emits through the constructor/destructor/core virtual method children; UID0003BW is regenerated by the compiler from those declarations and methods.
- IDA MCP confirms `OnPaint`, `OnMouseEvent`, and scalar deleting destructor boundaries in the existing aggregate evidence.
- 2026-06-10 A002 live IDA MCP rechecked the constructor boundary: IDA still reports no function or xrefs at `0x004ee650`, bytes `0x004ee643-0x004ee650` and `0x004ee6a7-0x004ee6b0` are `0xcc` padding, and the vtable data refs at `0x0061c870`, `0x0061c8c0`, and `0x0061c8f0` include stores from the raw constructor, `sub_4EE6B0`, and `sub_4EFA40`.
- 2026-06-11 A002 Batch216 live IDA MCP reconfirmed the raw constructor no-function/no-xref caveat, constructor-shaped leading bytes at `0x004ee650`, modeled method anchors at `0x004ee6b0`, `0x004ee6f0`, `0x004eeee0`, `0x004ef630`, and `0x004efa40`, and exact locator-backed vtable-data child [UID:0003BW][0x0061c86c-0x0061c8f8.InventoryPane2VtableData](by-memory/0x0061c86c-0x0061c8f8.InventoryPane2VtableData.md) ending before the `ITEMINV.EPD` string at `0x0061c8f8`.
- 2026-06-12 A003 Batch 242 live IDA MCP reconfirmed the raw constructor bytes/no-xrefs, `sub_4EE6B0`/`sub_4EE6F0`/`sub_4EEE60`/`sub_4EEEE0`/`sub_4EF290` modeled bounds, paint list/grid behavior, mouse/event handling, opcode `0x66` drag packet construction, opcode `0x59` popup packet handling, and tail helper caller/callee sets. The same refresh reconfirmed that [UID:0002SV][0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor](by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md) still contains legacy `InventoryPane` and `NewInventoryPane` adjustor thunks at `0x004efa0a-0x004efa36`, so that broad range stays unassigned.
- 2026-06-12 A003 Batch 248 live IDA MCP reconfirmed the exact tail split boundaries and ownership: `sub_4EF630`, raw no-function bodies at `0x004ef720-0x004ef794` and `0x004ef7a0-0x004ef86d`, `sub_4EF890`, `sub_4EF970`, the two `InventoryPane2` adjustor thunks, non-InventoryPane2 legacy/new adjustor thunks, and `sub_4EFA40`. The source-bearing `InventoryPane2` children now route here; compiler tables/thunks/padding stay non-emitting.

## Reconstruction Notes

- `InventoryPane2` is marked reconstructable and assigned to [UID:0000KA][InventoryPane](by-file/InventoryPane.md) because the class role, likely inventory source file, exact raw constructor, confirmed core method/helper island, and vtable data are now documented with stable UID-linked evidence and clear the strict gate.
- The exact constructor, core/helper children, retained raw packet helpers, and source-bearing tail helper/destructor memory pages now attach directly to this class. The broad core [UID:0002SU][0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers](by-memory/0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers.md) and broad tail helper page remain non-emitting index/audit pages after exact child splits; do not treat their parentless or non-emitting state as a class-parent gate failure.
- Class-level CPP is exactly `[[CHILDREN]]`; the fifteen exact child pages emit one accepted definition each at positions `200-340`. The H block supplies the second and final class declaration, including the explicit unobserved `+0x100` dword. No class-level body duplicates a child.
- UID0003EL owns the `GetSlotRect` definition at position `310`; this class owns its sole declaration with logical `short` and output parameter `rect`. The target's H channel remains blank, and UID0003EO may retain a clean source-level call even though the optimized binary inlines the same geometry.
- UID0003EJ and UID0003EM own definitions at positions `300` and `320`; this class owns their sole declarations as a signed-short-selector rectangle member and signed-short-returning y/x hit-test member. Their target H channels stay blank. Historical static/int/x-first/static-array and button-2/3 `+256` interpretations are superseded by the accepted ABI, exact geometry, and compiler-lowering evidence; they are not silently reused.
- The source-facing `m_visibleBounds` identifier is declared exactly once as protected `GrafPort::m_visibleBounds`; `Pane.h` includes `GrafPort.h`, and the public `Pane -> PanelPane -> InventoryPane2` inheritance route makes that member available to all exact child definitions. The InventoryPane2 H block intentionally has no duplicate bounds declaration.
- Do not emit [UID:0003BW][0x0061c86c-0x0061c8f8.InventoryPane2VtableData](by-memory/0x0061c86c-0x0061c8f8.InventoryPane2VtableData.md) as class-level source. The vtable/RTTI bytes are compiler-generated binary support for this class, not a human-authored C++ array; `NONE` ownership, aggregate UID00025L ownership, raw array source, and adjacent `ITEMINV.EPD` inclusion were rejected by B004's current evidence pass.
- Do not emit [UID:0003ER][0x004efa40-0x004efa95.InventoryPane2ScalarDeletingDestructor](by-memory/0x004efa40-0x004efa95.InventoryPane2ScalarDeletingDestructor.md) as a class-level source method or marker. The compiler regenerates the scalar-delete wrapper from the virtual destructor/class layout; the source destructor declaration/body is represented by UID00048P.
- Do not treat the interleaved [UID:00018K][0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1](by-memory/0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1.md), [UID:00018L][0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2](by-memory/0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2.md), or [UID:00018M][0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3](by-memory/0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3.md) helper pages as `InventoryPane2` methods.

## Cross-References

- [UID:0000KA][InventoryPane](by-file/InventoryPane.md)
- [UID:00018J][0x004ea130-0x004efbb7.InventoryPanes](by-memory/0x004ea130-0x004efbb7.InventoryPanes.md)
- [UID:00031V][0x004ee650-0x004ee6a7.InventoryPane2RawConstructor](by-memory/0x004ee650-0x004ee6a7.InventoryPane2RawConstructor.md)
- [UID:0002SU][0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers](by-memory/0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers.md)
- [UID:00048P][0x004ee6b0-0x004ee6cf.InventoryPane2Destructor](by-memory/0x004ee6b0-0x004ee6cf.InventoryPane2Destructor.md)
- [UID:00048Q][0x004ee6d0-0x004ee6dc.InventoryPane2RefreshEmbeddedPane](by-memory/0x004ee6d0-0x004ee6dc.InventoryPane2RefreshEmbeddedPane.md)
- [UID:00048R][0x004ee6e0-0x004ee6e1.InventoryPane2SourceEmptyVirtual](by-memory/0x004ee6e0-0x004ee6e1.InventoryPane2SourceEmptyVirtual.md)
- [UID:00048S][0x004ee6f0-0x004eee5c.InventoryPane2OnPaint](by-memory/0x004ee6f0-0x004eee5c.InventoryPane2OnPaint.md)
- [UID:00048T][0x004eee60-0x004eeedc.InventoryPane2OnKeyEvent](by-memory/0x004eee60-0x004eeedc.InventoryPane2OnKeyEvent.md)
- [UID:00048U][0x004eeee0-0x004ef290.InventoryPane2OnMouseEvent](by-memory/0x004eeee0-0x004ef290.InventoryPane2OnMouseEvent.md)
- [UID:00048V][0x004ef290-0x004ef3fc.InventoryPane2OnServerMessage](by-memory/0x004ef290-0x004ef3fc.InventoryPane2OnServerMessage.md)
- [UID:00048W][0x004ef400-0x004ef460.InventoryPane2SendUseItemSlotPacketRaw](by-memory/0x004ef400-0x004ef460.InventoryPane2SendUseItemSlotPacketRaw.md)
- [UID:00048X][0x004ef460-0x004ef50b.InventoryPane2SendDragDropItemPacketRaw](by-memory/0x004ef460-0x004ef50b.InventoryPane2SendDragDropItemPacketRaw.md)
- [UID:0002SV][0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor](by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md)
- [UID:0003EJ][0x004ef630-0x004ef702.InventoryPane2ButtonRectHelper](by-memory/0x004ef630-0x004ef702.InventoryPane2ButtonRectHelper.md)
- [UID:0003EL][0x004ef720-0x004ef794.InventoryPane2SlotRectBuilderRaw](by-memory/0x004ef720-0x004ef794.InventoryPane2SlotRectBuilderRaw.md)
- [UID:0003EM][0x004ef7a0-0x004ef86d.InventoryPane2ButtonHitTestRaw](by-memory/0x004ef7a0-0x004ef86d.InventoryPane2ButtonHitTestRaw.md)
- [UID:0003EO][0x004ef890-0x004ef962.InventoryPane2SlotHitTest](by-memory/0x004ef890-0x004ef962.InventoryPane2SlotHitTest.md)
- [UID:0003EP][0x004ef970-0x004ef9f4.InventoryPane2VisibleIndexToInventorySlot](by-memory/0x004ef970-0x004ef9f4.InventoryPane2VisibleIndexToInventorySlot.md)
- [UID:0003ER][0x004efa40-0x004efa95.InventoryPane2ScalarDeletingDestructor](by-memory/0x004efa40-0x004efa95.InventoryPane2ScalarDeletingDestructor.md)
- [UID:00025L][0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData](by-memory/0x0061c7a4-0x0061c9c4.InventoryPaneReadOnlyData.md)
- [UID:0003BW][0x0061c86c-0x0061c8f8.InventoryPane2VtableData](by-memory/0x0061c86c-0x0061c8f8.InventoryPane2VtableData.md)
- [UID:00006R][InventoryPane](by-class/InventoryPane.md)
- [UID:000093][NewInventoryPane](by-class/NewInventoryPane.md)

## Changes

- 2026-08-15 B001 UID0003EM accepted callback:
  - Preserved B006's short-slot/single-InitRectBounds UID0003EL evidence while applying this accepted report's required owner-H output name `rect`; corrected GetButtonRect and HitTestButton to non-static const members with signed-short selector/return and y/x order; expanded method/evidence/source-route notes with exact target hash, geometry, zero-xref inlining route, and compiler-table disposition. Score, owner/emitter, 15-definition count, fields, and all unrelated declarations remain `94/94` and unchanged.
- 2026-08-15 B006 UID0003EL accepted callback:
  - Corrected the formal H declaration to logical `short`, synchronized the A25 method map with the one-final-InitRectBounds body and live UID0003EO inlining, normalized list/grid constant prose to `kListView`/`kGridView`, and preserved `m_viewMode` as a dword-sized `int` with exact zero/nonzero behavior. Score, owner/emitter route, layout, and child-only CPP anchor remain `94/94` and unchanged.
- 2026-08-15 B001 accepted UID0000KA whole-file callback:
  - Raised `87/89 -> 94/94`, installed the complete H declaration and child-only CPP anchor, fixed exact positions `200-340`, corrected `0x004ee6d0` from stale `RefreshEmbeddedPane` to `OnActivate`, and identified `0x004ee6e0` as intentional `PlayItemEffect` source.
  - Preserved the unobserved `+0x100` field, exact raw-start caveats, BackPane/compiler exclusions, and one `InventoryPane.cpp` route.
- 2026-08-15 B001 UID0000KA inherited-bounds source-identity repair:
  - Corrected the source/member identity at `+0x44` to inherited protected `GrafPort::m_visibleBounds`, proved the declaration route through `Pane` and `PanelPane`, and retained no duplicate InventoryPane2 field.

- 2026-06-12 A003 Batch 248 tail split repair:
  - Before: score `86/88`, exact constructor/core children routed here, and the broad tail island listed as parentless due mixed thunk ownership.
  - Changed to: score `87/89`, with exact source-bearing tail children from [UID:0002SV][0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor](by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md) routed here while the broad mixed audit page remains non-emitting.
  - Evidence: live IDA MCP reconfirmed tail helper boundaries, no-function raw starts, caller/xref sets, vtable-backed destructor adjustors, compiler table/padding bytes, and the legacy/NewInventoryPane thunk split at `0x004efa0a-0x004efa36`.

- 2026-06-27 B013 accepted implementation callback, historical field-name state:
  - Changed to: added repaired [UID:0002SU][0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers](by-memory/0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers.md) as a non-emitting split/index parent, added exact core children `00048P`-`00048X`, and documented the then-provisional pane-local bounds alias plus `m_drawState`, `m_pageIndex`, `m_isLastPage`, `m_viewMode`, `m_listButtonState`, and `m_gridButtonState`. The 2026-08-15 inherited-bounds repair supersedes only that provisional alias with declared `GrafPort::m_visibleBounds`; the remaining field evidence stays valid.
  - Evidence: accepted B013 MCP report confirmed vtable-routed destructor/refresh/paint/key/mouse/message handlers, raw packet helpers at `0x004ef400` and `0x004ef460`, no direct xrefs to the raw helpers, opcode `0x1c`/`0x66` packet shapes, and BackPane V3 beginning at `0x004ef510`.
- 2026-07-05 B004 accepted implementation callback:
  - Changed to: documented [UID:0003BW][0x0061c86c-0x0061c8f8.InventoryPane2VtableData](by-memory/0x0061c86c-0x0061c8f8.InventoryPane2VtableData.md) as class-owned but non-reconstructable/non-emitting compiler-generated RTTI/vtable support. No class score or C++ change was made.
  - Evidence: current MCP session `supervisor_recovery_20260705` confirmed exact vtable dwords/bytes, constructor/destructor/scalar-deleting vptr-store xrefs, local slot mapping, adjacent `ITEMINV.EPD` boundary, pointer-scan negatives, no local `InventoryPane2` UDT, and generated `InventoryPane.cpp` empty-marker state.
- 2026-07-03 B012 accepted implementation callback:
  - Changed to: UID00031V now carries formal first-draft `InventoryPane2::InventoryPane2()` C++ and target score `88/91`; this class page records that constructor source initializes page/view/button state while preserving no direct function/xref/pointer route at `0x004ee650`.
  - Evidence: MCP session `3a33af0b` reconfirmed exact constructor body bytes/padding, `PanelPane` base call, three compiler-lowered `InventoryPane2` vtable stores, state-field clears, no raw-start function, no raw-start xrefs, and no raw-start VA/RVA pointer-byte hits.
- 2026-07-07 B004 accepted implementation callback:
  - Changed to: synchronized [UID:0003ER][0x004efa40-0x004efa95.InventoryPane2ScalarDeletingDestructor](by-memory/0x004efa40-0x004efa95.InventoryPane2ScalarDeletingDestructor.md) as class-owned but non-reconstructable/non-emitting compiler scalar-delete support. No class score, owner, emitter, or source route change was made.
  - Evidence: MCP session `43ccf853` confirmed exact wrapper range/padding/signature, primary vtable slot, secondary/tertiary adjustor route, vtable restores, cleanup/free/guard behavior, pointer-pattern negatives, and UID00048P as the ordinary source destructor body.

- 2026-06-10 A002 constructor-child/gate refresh:
  - Raised `78/82` to `82/86`, cleared the below-gate `AUTOGEN_PARENT_UID:0000KA`, added exact raw constructor child [UID:00031V][0x004ee650-0x004ee6a7.InventoryPane2RawConstructor](by-memory/0x004ee650-0x004ee6a7.InventoryPane2RawConstructor.md), and replaced the stale unresolved-constructor boundary text.
  - Evidence: live IDA MCP reconfirmed no function/xrefs at `0x004ee650`, raw constructor bytes through `0x004ee6a7`, `0xcc` padding before `0x004ee650` and before `0x004ee6b0`, and vtable stores from the raw constructor, setup helper, and scalar deleting destructor. Class/file attachment remains blank because the class and file parent do not clear the strict `85/85` gate.
- 2026-06-11 A002 Batch216 parent-gate repair:
  - Before: score `82/86`, parent blank under the strict gate.
  - Changed to: score `85/87`, `AUTOGEN_PARENT_UID:0000KA`, and exact vtable child [UID:0003BW][0x0061c86c-0x0061c8f8.InventoryPane2VtableData](by-memory/0x0061c86c-0x0061c8f8.InventoryPane2VtableData.md).
  - Evidence: live IDA MCP reconfirmed the raw constructor caveat, modeled method anchors, vtable-store xrefs from raw constructor/setup/destructor paths, and the `0x0061c86c-0x0061c8f8` locator-backed vtable island. Remaining raw-constructor reachability and final field names keep final C++ blank.
- 2026-06-12 A003 Batch 242 child-routing refresh:
  - Before: score `85/87`, with exact children listed but the class page did not reflect Batch 242 assignment of the constructor/core memory pages or the current mixed-range reason for keeping the tail island parentless.
  - Changed to: score `86/88`, with [UID:00031V][0x004ee650-0x004ee6a7.InventoryPane2RawConstructor](by-memory/0x004ee650-0x004ee6a7.InventoryPane2RawConstructor.md) and [UID:0002SU][0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers](by-memory/0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers.md) routed here, and [UID:0002SV][0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor](by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md) explicitly held parentless due mixed thunk ownership.
  - Evidence: live IDA MCP reconfirmed constructor bytes/no-xrefs, core method bounds and behavior, tail helper caller/callee sets, and the legacy/new adjustor thunk split inside the broad tail range.
- 2026-06-02: Raised `68/76` to `78/82`, marked reconstructable, and attached to [UID:0000KA][InventoryPane](by-file/InventoryPane.md). Added exact children [UID:0002SU][0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers](by-memory/0x004ee6b0-0x004ef510.InventoryPane2CoreAndHelpers.md) and [UID:0002SV][0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor](by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md), companion vtable-data evidence, source-placement evidence, and reconstruction blockers. C++ remains blank because constructor/setup and field/helper names are not final.
- Completion/confidence score update: existed before as `0/0`; changed to `68/76`. Summary: alternate compact inventory-pane behavior, core draw/key/mouse/hit-test/destructor methods, and source placement are documented, but the constructor boundary remains unresolved and tracked as a data issue. Evidence: `InventoryPanes`, IDA-confirmed method boundaries, and no-function note for `0x004ee650`.
