*** UID:0000CU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SelfLookPane : public PanelPane
{
public:
    enum ViewMode
    {
        ViewMode_Default = 0,
        ViewMode_Spelled = 1,
        ViewMode_Legend = 2
    };

    enum SlotId
    {
        SelfLookSlot_Face = 0,
        SelfLookSlot_Body = 1,
        SelfLookSlot_Stats = 2,
        SelfLookSlot_Previous = 3,
        SelfLookSlot_Next = 4,
        SelfLookSlot_TopOption = 5,
        SelfLookSlot_BottomOption = 6,
        SelfLookEquipmentSlot_FaceAccessory1 = 7,
        SelfLookEquipmentSlot_Head = 8,
        SelfLookEquipmentSlot_HeadAccessory2 = 9,
        SelfLookEquipmentSlot_RightHand = 10,
        SelfLookEquipmentSlot_Body = 11,
        SelfLookEquipmentSlot_LeftHand = 12,
        SelfLookEquipmentSlot_RightAccessory = 13,
        SelfLookEquipmentSlot_Mantle = 14,
        SelfLookEquipmentSlot_LeftAccessory = 15,
        SelfLookEquipmentSlot_LeftSubAccessory = 16,
        SelfLookEquipmentSlot_Coat = 17,
        SelfLookEquipmentSlot_RightSubAccessory = 18,
        SelfLookEquipmentSlot_Necklace = 19,
        SelfLookEquipmentSlot_Foot = 20
    };

    enum ButtonVisualState
    {
        ButtonVisualState_Disabled = 0xff
    };

    SelfLookPane();
    virtual ~SelfLookPane();

    virtual void OnReceiveCharacterData(const unsigned char *packet);
    virtual void OnPaint();
    virtual bool OnMouseClick(const PanelMouseEvent *event);
    virtual bool OnKeyPress(Event *event);
    virtual bool OnPacketEvent(const PanelPacketEvent *event);
    virtual bool OnShowHelp(void *helpContext, int x, int y);
    virtual void OnGetRect(RectBounds *bounds);
    virtual int OnTransformRect(RectBounds *bounds, int transformMode);

    void AddOrUpdateSpelledEntry(const wchar_t *text, int value);
    void RefreshSpelledPane();
    void StopSpelledPaneRefresh();
    void ResetAndRefresh();
    void ActivateView();
    void ShowSpelledView();
    void DeactivateView();

    void DrawNumberString(const wchar_t *text,
                          int x,
                          int y,
                          unsigned char glyphSet);
    void GetSlotRect(short slotId, RectBounds *bounds) const;
    unsigned short HitTestSlot(int x, int y) const;

    void SendToggleLook();
    void SendToggleEquip();
    void SendToggleStats();
    bool SendSelfLookOptionRequest(unsigned char optionSubtype);
    void SendSelfLookOption02Raw();
    void SendSelfLookOption08Raw();
    void SendSelfLookOption0bRaw();

    bool ApplySelfLookRectRecord(const unsigned char *packet);
    bool ApplySelfLookRectStateRecord(const unsigned char *packet);
    bool ApplyEquipmentSlotRecord(const unsigned char *packet);
    bool ClearEquipmentSlotRecord(const unsigned char *packet);
    bool ApplySelfLookSummaryRecord(const unsigned char *packet);
    bool DispatchSpelledText(const unsigned char *packet);
    void ToggleSelfLookViewCache();

private:
    unsigned char *m_statDigitFrames;
    SpelledPane *m_spelledPane;
    ProfilePane *m_profilePane;
    LegendPane *m_legendPane;
    ObjectStatusBlob m_selfLookObjectStatus;

    unsigned short m_equipmentSlotItemIds[21];
    unsigned char m_equipmentSlotRecordStates[21];
    wchar_t m_equipmentSlotNames[21][64];
    wchar_t m_equipmentSlotDescriptions[21][64];
    unsigned int m_equipmentSlotValues[21];
    unsigned char m_equipmentSlotValueFlags[21];
    unsigned char m_equipmentSlotHoverStates[21];

    wchar_t m_identityLine1[256];
    wchar_t m_identityLine2[256];
    wchar_t m_statusLineA[256];
    wchar_t m_statusLineB[128];
    wchar_t m_statusName[128];
    unsigned int m_summaryCompareKey0;
    unsigned int m_summaryCompareKey1;
    unsigned char m_summaryTailByte0;
    unsigned char m_summaryTailByte1;
    unsigned char m_summaryTailByte2;
    unsigned int m_summaryTailValue;
    unsigned int m_lastSelfLookOptionTick;
    unsigned int m_selfLookOptionRepeatDelay;
    unsigned char m_bodyToggleState;
    unsigned char m_faceToggleState;
    unsigned char m_statsToggleState;
    wchar_t m_auxiliaryText[256];
    wchar_t m_spelledSourceText[256];
    int m_activeViewMode;
    int m_serverRequestedViewMode;
    int m_reservedViewState;
    int m_pendingMouseAction;
    int m_pendingMouseView;
    unsigned char m_viewCacheToggle;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SelfLookPane

## Status

- Confidence: very strong for class purpose, exact `0x2340` natural layout, method boundaries, source-ready paint/helper union, class/file ownership, and exact main-span child split; lexical names and unrecovered access grouping remain bounded uncertainty.
- Likely source file: [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md)
- Main address index: [UID:0001H7][0x00565610-0x0056a373.SelfLookPane](by-memory/0x00565610-0x0056a373.SelfLookPane.md)
- Autogen handling: attached to [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md). The main `0x00565610-0x0056a373` span is now a non-emitting split index; exact child pages carry the method-level reconstruction evidence. Child [UID:0002RC][0x0056a640-0x0056b5c0.SelfLookPaneEquipmentRecordParser](by-memory/0x0056a640-0x0056b5c0.SelfLookPaneEquipmentRecordParser.md) now has formal first-draft method C++ for `SelfLookPane::ApplyEquipmentSlotRecord`, child [UID:0002RE][0x0056b7c0-0x0056b946.SelfLookPaneSummaryStatUpdate](by-memory/0x0056b7c0-0x0056b946.SelfLookPaneSummaryStatUpdate.md) now has formal first-draft method C++ for `SelfLookPane::ApplySelfLookSummaryRecord`, and child [UID:0002RF][0x0056b950-0x0056b9ef.SelfLookPaneSpelledTextDispatch](by-memory/0x0056b950-0x0056b9ef.SelfLookPaneSpelledTextDispatch.md) now has formal first-draft method C++ for `SelfLookPane::DispatchSpelledText`.
- 2026-07-16 B002 UID0003QN callback replaces the partial B011 skeleton with the complete accepted source-safe class union. The class-closing `};` now precedes `[[CHILDREN]]`, so exact child method definitions emit after a complete declaration.
- 2026-07-16 B002 UID0003QE callback completes the three-member SelfLookPane toggle surface: live UID0003QC `SendToggleLook`, live UID0003QD `SendToggleEquip`, and retained source UID0003QE `SendToggleStats` now have exact declarations and child-owned formal definitions.
- 2026-08-24 B001 UID0003QF callback adds retained nonvirtual `AddOrUpdateSpelledEntry(const wchar_t *, int)` exactly once immediately before `RefreshSpelledPane()` in this existing formal CPP class declaration. UID0003QF owns the definition; the class formal H remains blank and no generated `SelfLookPane.h` is introduced.

## Complete Declaration And Layout Union

- The accepted declaration preserves every previously accepted B004/B005/B006/B007/B011 method and field while carrying the exact paint/helper surface required by UID0003QN/QU/QV/QW/QP, all three source-ready UID0003QC/QD/QE toggle declarations, and retained UID0003QF `AddOrUpdateSpelledEntry`.
- Source-visible enums define view modes `0/1/2`, control slots `0..6`, equipment slots `7..20`, and disabled button state `0xff`.
- The virtual surface preserves character-data, paint, mouse, key, packet, help, rectangle, and transform methods. Helper surface preserves the three `SendToggle*` members, `AddOrUpdateSpelledEntry`, all packet/update children, raw option sends, view methods, number drawing, slot geometry, hit testing, and view-cache toggle behavior; exact original access grouping remains unrecovered.
- Exact accepted natural layout size is `0x2340`. The declaration includes:
  - `m_statDigitFrames`;
  - `SpelledPane`, `ProfilePane`, and `LegendPane` pointers;
  - 68-byte `ObjectStatusBlob m_selfLookObjectStatus`;
  - sparse equipment item/state/name/description/value/flag/hover arrays indexed by slot id;
  - identity/status/name buffers;
  - summary compare/tail fields;
  - option tick/repeat and three toggle bytes;
  - auxiliary/spelled text;
  - active/server/reserved view state, pending mouse state, and view-cache toggle.
- UID0002RG's mode-zero raw dword writes are represented by clearing `m_equipmentSlotHoverStates[7..20]` and `m_identityLine1[0]`; the artificial `m_cachedLookState0..3` members are rejected.
- Compiler-owned vtable/RTTI arrays, adjustor/deleting wrappers, switch tables, security cookies, exception scaffolding, and alignment are not declared as handwritten class members.
- `[[CHILDREN]]` is intentionally outside the class declaration and after `};`. Parent/index pages remain non-emitting; exact child pages own method bodies.

## Class Purpose

`SelfLookPane` is the player's own look/status panel. It owns character-data parsing, equipment slot rendering, stat/legend view switching, retained SpelledPane entry update forwarding, SpelledPane scroll-state refresh bridging, body/equipment/stat visibility toggles, input handling, item-slot hit testing, and the large self-look paint path.

## Toggle Method Source Closure

- [UID:0003QC][0x00566f40-0x00566ffa.SelfLookPaneSendToggleLook](by-memory/0x00566f40-0x00566ffa.SelfLookPaneSendToggleLook.md), [UID:0003QD][0x00567000-0x005670ba.SelfLookPaneSendToggleEquip](by-memory/0x00567000-0x005670ba.SelfLookPaneSendToggleEquip.md), and [UID:0003QE][0x005670c0-0x0056717a.SelfLookPaneSendToggleStatsRaw](by-memory/0x005670c0-0x0056717a.SelfLookPaneSendToggleStatsRaw.md) are exact 186-byte/55-instruction no-argument void members.
- Each uses unsigned `currentTick <= lastTick + repeatDelay`, toggles its class state byte, writes `1b/01/subtype/00` with value-first `PacketBufferWriteUInt8`, explicitly zeros packet byte 4, sends only four bytes, performs a non-null but unused `GetSlotRect` query, then reloads and stores the current tick.
- The exact state/subtype/slot triples are face/`0x08`/`SelfLookSlot_Face`, body/`0x02`/`SelfLookSlot_Body`, and stats/`0x0b`/`SelfLookSlot_Stats`.
- UID0003QC and UID0003QD each have a current external call through `g_pGeneralPurposePanel` and the active-child accessor. That route proves liveness while preserving SelfLookPane ownership. UID0003QE has no current call/xref/pointer/inline-copy route, but its exact source shape and six-body family justify retained private source.
- The local `RectBounds` results are dead. Historical slot-color, redraw/invalidation, and stats-to-Spelled-view transition interpretations are rejected. No method has a null guard, send-result branch, retry, or explicit view transition.
- `SendSelfLookOptionRequest` and the `SendSelfLookOption02Raw`/`08Raw`/`0bRaw` packet-only family remain separate accepted source; they are not owners or covered-by replacements for these inline serialization bodies.

## Add-Or-Update Spelled Entry Source Closure

- [UID:0003QF][0x00567180-0x0056719a.SelfLookPaneSpelledEntryUpdateForwarderRaw](by-memory/0x00567180-0x0056719a.SelfLookPaneSpelledEntryUpdateForwarderRaw.md) is retained source method `void SelfLookPane::AddOrUpdateSpelledEntry(const wchar_t *text, int value)`. It is exactly `[0x00567180,0x0056719a)`, size `0x1a`, 26 bytes, 9 instructions, body SHA256 `92872630859B8B8928D16092909CCD7E704E696DBFBFEEB507EFF2BFA36507DB`, with separate six-byte `cc` alignment spans on both sides.
- The ABI is exact: class `this` arrives in `ECX`; text is `[ebp+8]`; value is `[ebp+0xc]`; literal zero supplies group; `retn 8` removes the two explicit arguments. The body has one child call, no null guard, no branch, and no return value.
- Constructor `0x00565610` creates the child stored at `SelfLookPane+0xfc`; the accepted `0x2340` layout types that field as `SpelledPane *m_spelledPane`. Source therefore uses `m_spelledPane->AddOrUpdateEntry(text, value, 0)` and does not preserve raw offsets, casts, calling-convention scaffolding, or decompiler temporaries.
- Callee `[0x0056bca0,0x0056be17)` is current `SpelledPane__AddOrUpdateEntry`, typed `void __thiscall(SpelledPane *this, const wchar_t *text, int value, int group)`, with update-or-append behavior and exactly seven incoming callers: `0x00567191`, `0x00569793`, `0x0056b9ce`, `0x00570b91`, `0x005725cb`, `0x00572fae`, and `0x00588c2a`.
- The class-parallel SelfLookPane2 body `[0x00570b80,0x00570b9a)` has SHA256 `FCEF2A7EEC4A6CF9495FE164DD6ED8636292E0E5C65F403DF6A92731C0F77D28`; wildcarding only its call displacement yields exactly two executable matches. That separate UID0003R4 page is corroboration only and is not source-closed here.
- Exhaustive dated checks found zero incoming IDA xrefs and zero immediate, code, data, VA, RVA, raw-offset, physical pointer, or `.text` relative-call/jump routes to `0x00567180`. No current route and no recovered original symbol cap exact spelling/access confidence; they do not make this complete ordinary body padding, a thunk, an adjustor, a compiler helper, inline-covered output, or no-code.
- The exact formal definition remains child-owned by UID0003QF and emits through [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md). This class page supplies only the declaration in its existing formal CPP class body, so there is one definition route and no duplicate class/file body.

## Main Method Split

| Method or helper | Evidence page | Role |
| --- | --- | --- |
| constructor | [UID:0003Q8][0x00565610-0x005657d2.SelfLookPaneConstructor](by-memory/0x00565610-0x005657d2.SelfLookPaneConstructor.md) | Initializes `PanelPane`, DAT-backed resources, child `SpelledPane` and `LegendPane`, vtables, and self-look state fields. |
| non-deleting destructor | [UID:0003Q9][0x005657e0-0x00565887.SelfLookPaneNonDeletingDestructor](by-memory/0x005657e0-0x00565887.SelfLookPaneNonDeletingDestructor.md) | Cleanup helper with `SelfLookPane` vtable restore evidence. |
| `OnReceiveCharacterData` | [UID:0003QA][0x00565890-0x00566f24.SelfLookPaneOnReceiveCharacterData](by-memory/0x00565890-0x00566f24.SelfLookPaneOnReceiveCharacterData.md) | Parses character data and updates look/stat/equipment fields. |
| no-op stub | [UID:0003QB][0x00566f30-0x00566f31.SelfLookPaneNullStub](by-memory/0x00566f30-0x00566f31.SelfLookPaneNullStub.md) | Non-emitting one-byte code stub retained for range accounting. |
| `SendToggleLook` | [UID:0003QC][0x00566f40-0x00566ffa.SelfLookPaneSendToggleLook](by-memory/0x00566f40-0x00566ffa.SelfLookPaneSendToggleLook.md) | Live source method; face state, subtype `0x08`, face slot, active-child caller. |
| `SendToggleEquip` | [UID:0003QD][0x00567000-0x005670ba.SelfLookPaneSendToggleEquip](by-memory/0x00567000-0x005670ba.SelfLookPaneSendToggleEquip.md) | Live source method; body state, subtype `0x02`, body slot, active-child caller. |
| `SendToggleStats` | [UID:0003QE][0x005670c0-0x0056717a.SelfLookPaneSendToggleStatsRaw](by-memory/0x005670c0-0x0056717a.SelfLookPaneSendToggleStatsRaw.md) | Retained source method; stats state, subtype `0x0b`, stats slot, exhaustive no-current-route evidence. |
| `AddOrUpdateSpelledEntry` | [UID:0003QF][0x00567180-0x0056719a.SelfLookPaneSpelledEntryUpdateForwarderRaw](by-memory/0x00567180-0x0056719a.SelfLookPaneSpelledEntryUpdateForwarderRaw.md) | Retained nonvirtual source method; forwards text/value through typed `m_spelledPane` to `SpelledPane::AddOrUpdateEntry` with group 0; exact duplicate and exhaustive no-current-route evidence. |
| raw spelled remove forwarder | [UID:0003QG][0x005671a0-0x005671b7.SelfLookPaneSpelledEntryRemoveForwarderRaw](by-memory/0x005671a0-0x005671b7.SelfLookPaneSpelledEntryRemoveForwarderRaw.md) | Forwards through `this+0xfc` to the `SpelledPane` remove/clear helper. |
| `RefreshSpelledPane` | [UID:0003QH][0x005671c0-0x005671de.SelfLookPaneRefreshSpelledPane](by-memory/0x005671c0-0x005671de.SelfLookPaneRefreshSpelledPane.md) | Exact 30-byte wrapper that refreshes the embedded SpelledPane scroll-handler state; called from both UID0003UN server-entry branches. |
| `StopSpelledPaneRefresh` | [UID:0004TT][0x005671e0-0x005671f1.SelfLookPaneStopSpelledPaneRefresh](by-memory/0x005671e0-0x005671f1.SelfLookPaneStopSpelledPaneRefresh.md) | Sole canonical 17-byte stop-only method; loads typed `m_spelledPane`, adjusts to `FrameHandler`, and directly removes the existing frame. [UID:0003QI][0x005671e0-0x005671f1.SelfLookPaneRefreshSpelledChild](by-memory/0x005671e0-0x005671f1.SelfLookPaneRefreshSpelledChild.md) is retained ownerless/non-emitting duplicate inventory, not a second class method. |
| `ResetAndRefresh` | [UID:0003QJ][0x00567200-0x00567280.SelfLookPaneResetAndRefresh](by-memory/0x00567200-0x00567280.SelfLookPaneResetAndRefresh.md) | Resets state and refreshes visible child panes. |
| `ActivateView` | [UID:0003QK][0x00567280-0x005672b0.SelfLookPaneActivateView](by-memory/0x00567280-0x005672b0.SelfLookPaneActivateView.md) | Shows/activates the current view. |
| raw deactivate/reset helper | [UID:0003QL][0x005672b0-0x0056737f.SelfLookPaneDeactivateResetRaw](by-memory/0x005672b0-0x0056737f.SelfLookPaneDeactivateResetRaw.md) | Raw body that hides/shows child panes, formats a rect, posts a resource, and invalidates. |
| `DeactivateView` | [UID:0003QM][0x00567380-0x00567472.SelfLookPaneDeactivateView](by-memory/0x00567380-0x00567472.SelfLookPaneDeactivateView.md) | Hides/deactivates child view panes. |
| `OnPaint` | [UID:0003QN][0x00567480-0x00568bd0.SelfLookPaneOnPaint](by-memory/0x00567480-0x00568bd0.SelfLookPaneOnPaint.md) | Main self-look/equipment/stat rendering path plus owned switch table. |
| `OnKeyPress` | [UID:0003QO][0x00568bd0-0x00568ca9.SelfLookPaneOnKeyPress](by-memory/0x00568bd0-0x00568ca9.SelfLookPaneOnKeyPress.md) | Keyboard navigation/actions. |
| `OnMouseClick` | [UID:0003QP][0x00568cb0-0x005693d0.SelfLookPaneOnMouseClick](by-memory/0x00568cb0-0x005693d0.SelfLookPaneOnMouseClick.md) | Mouse hit testing, hover-slot state, packet branches, action dispatch, and fourteen equipment-click calls to shared [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md), plus owned switch data. |
| packet/event handler | [UID:0003QQ][0x005693d0-0x00569860.SelfLookPanePacketEventHandler](by-memory/0x005693d0-0x00569860.SelfLookPanePacketEventHandler.md) | Packet/event handler that calls adjacent packet/update helpers. |
| `OnShowHelp` | [UID:0003QR][0x00569860-0x00569c80.SelfLookPaneOnShowHelp](by-memory/0x00569860-0x00569c80.SelfLookPaneOnShowHelp.md) | Help display for self-look controls/slots plus owned switch data. |
| `OnGetRect` | [UID:0003QS][0x00569c80-0x00569cce.SelfLookPaneOnGetRect](by-memory/0x00569c80-0x00569cce.SelfLookPaneOnGetRect.md) | Returns class-specific rectangle geometry. |
| `OnTransformRect` | [UID:0003QT][0x00569cd0-0x00569d75.SelfLookPaneOnTransformRect](by-memory/0x00569cd0-0x00569d75.SelfLookPaneOnTransformRect.md) | Transforms local/child rectangles. |
| `DrawNumberString` | [UID:0003QU][0x00569d80-0x00569ec1.SelfLookPaneDrawNumberString](by-memory/0x00569d80-0x00569ec1.SelfLookPaneDrawNumberString.md) | Draws numeric stat labels. |
| `GetSlotRect` | [UID:0003QV][0x00569ed0-0x0056a300.SelfLookPaneGetSlotRect](by-memory/0x00569ed0-0x0056a300.SelfLookPaneGetSlotRect.md) | Computes the exact mode/slot rectangle map plus owned compiler switch/alignment; performs no color work and requires a non-null output. |
| `HitTestSlot` | [UID:0003QW][0x0056a300-0x0056a373.SelfLookPaneHitTestSlot](by-memory/0x0056a300-0x0056a373.SelfLookPaneHitTestSlot.md) | Maps mouse coordinates to equipment slots. |
| packet/update helper island | [UID:00023V][0x0056a380-0x0056ba99.SelfLookPanePacketUpdateHelpers](by-memory/0x0056a380-0x0056ba99.SelfLookPanePacketUpdateHelpers.md) | Adjacent non-emitting helper index already split into exact child pages, including accepted first-draft method emitters `SelfLookPane::ApplyEquipmentSlotRecord`, `SelfLookPane::ApplySelfLookSummaryRecord`, and `SelfLookPane::DispatchSpelledText`. |
| scalar deleting destructor | [UID:00039F][0x00573730-0x00573818.SelfLookPaneScalarDeletingDestructor](by-memory/0x00573730-0x00573818.SelfLookPaneScalarDeletingDestructor.md) | Full class destructor plus conditional delete. |

## Accepted Child Method C++

[UID:0002RC][0x0056a640-0x0056b5c0.SelfLookPaneEquipmentRecordParser](by-memory/0x0056a640-0x0056b5c0.SelfLookPaneEquipmentRecordParser.md) is now accepted as first-draft formal method C++ under this class. The method is documented as `SelfLookPane::ApplyEquipmentSlotRecord`: packet/event handler opcode `0x37` calls it at `0x00569588`, it reads selector `packet+1`, item id `packet+2`, state byte `packet+4`, two length-prefixed multibyte strings, a trailing big-endian dword, and a trailing byte, then writes the selected slot's item id, record state, wide name, wide description/detail text, dword metadata, and trailing flag before invalidating inherited `m_bounds`. The selector names, slot ids, and fields `m_equipmentSlotItemIds`, `m_equipmentSlotRecordStates`, `m_equipmentSlotNames`, `m_equipmentSlotDescriptions`, `m_equipmentSlotValues`, and `m_equipmentSlotValueFlags` are source-facing inferred names rather than recovered original symbols. The inference is grounded in [UID:0002RC][0x0056a640-0x0056b5c0.SelfLookPaneEquipmentRecordParser](by-memory/0x0056a640-0x0056b5c0.SelfLookPaneEquipmentRecordParser.md) parser offsets, [UID:0002RD][0x0056b5c0-0x0056b7c0.SelfLookPaneClearSlotSwitchRaw](by-memory/0x0056b5c0-0x0056b7c0.SelfLookPaneClearSlotSwitchRaw.md) clear-switch fields, [UID:0003QP][0x00568cb0-0x005693d0.SelfLookPaneOnMouseClick](by-memory/0x00568cb0-0x005693d0.SelfLookPaneOnMouseClick.md) mouse-click take-off selectors, and [UID:0003EY][0x006248e0-0x00624a50.SelfLookPaneEquipmentSlotLabelStrings](by-memory/0x006248e0-0x00624a50.SelfLookPaneEquipmentSlotLabelStrings.md) decoded help labels.

[UID:0002RE][0x0056b7c0-0x0056b946.SelfLookPaneSummaryStatUpdate](by-memory/0x0056b7c0-0x0056b946.SelfLookPaneSummaryStatUpdate.md) is now accepted as first-draft formal method C++ under this class. The method is documented as `SelfLookPane::ApplySelfLookSummaryRecord`: packet/event handler case `8` calls it at `0x0056972f`, it applies a masked summary record, compares `m_summaryCompareKey0` and `m_summaryCompareKey1`, updates `m_summaryTailValue` plus `m_summaryTailByte0` through `m_summaryTailByte2` only on change, and invalidates inherited `m_bounds` when state changes. Those member names are descriptive first-draft identifiers rather than recovered original source names; the exact behavior and address range are accepted, while the broader class declaration block remains intentionally blank for separate declaration and field-name policy.

[UID:0002RF][0x0056b950-0x0056b9ef.SelfLookPaneSpelledTextDispatch](by-memory/0x0056b950-0x0056b9ef.SelfLookPaneSpelledTextDispatch.md) is now accepted as first-draft formal method C++ under this class. The method is documented as `SelfLookPane::DispatchSpelledText`: it starts the packet cursor at `1`, reads the temporary text with the packet string helper at `0x00575a10`, reads the optional big-endian value with `0x00575790`, loads the embedded `SpelledPane` child at `this+0xfc`, sends zero/absent values to `SpelledPane::RemoveEntry` (`0x0056be20`), sends nonzero values to `SpelledPane::AddOrUpdateEntry` (`0x0056bca0`), cleans the temporary string through `0x00582b70`, and returns false. `m_spelledPane`, `DispatchSpelledText`, `AddOrUpdateEntry`, and `RemoveEntry` are source-facing inferred names rather than recovered originals; the no-direct-start-xref result and inferred names cap the child score but do not block the first-draft child C++.

## Equipment Slot Layout Support

The accepted [UID:0002RC][0x0056a640-0x0056b5c0.SelfLookPaneEquipmentRecordParser](by-memory/0x0056a640-0x0056b5c0.SelfLookPaneEquipmentRecordParser.md) report resolves the equipment selector domain for this class:

| Selector | Visible slot id | Source-facing slot | Label/source evidence |
| ---: | ---: | --- | --- |
| `1` | `10` | `RightHand` | `Righthand(w)` |
| `2` | `11` | `Body` | `Body(a)` |
| `3` | `12` | `LeftHand` | `Lefthand(s)` |
| `4` | `8` | `Head` | `Head(h)` |
| `6` | `19` | `Necklace` | `Necklace(n)` |
| `7` | `15` | `LeftAccessory` | `Leftaccessory(l)` |
| `8` | `13` | `RightAccessory` | `Rightaccessory(r)` |
| `13` | `20` | `Foot` | `Foot(f)` |
| `14` | `14` | `Mantle` | `Mantle(m)` |
| `16` | `17` | `Coat` | `Coat(c)` |
| `20` | `16` | `LeftSubAccessory` | `Subaccessory([)` |
| `21` | `18` | `RightSubAccessory` | second subaccessory slot; direct label bytes decode as `Subaccessory(r)`, while selector-key evidence uses `]` |
| `22` | `7` | `FaceAccessory1` | `Faceaccessory(1)` |
| `23` | `9` | `HeadAccessory2` | `Headaccessory(2)` |

The slot storage should be treated as sparse arrays keyed by the visible slot id: `m_equipmentSlotItemIds[slot]` at `this+0x14c + 2*slot`, `m_equipmentSlotRecordStates[slot]` at `this+0x176 + slot`, `m_equipmentSlotNames[slot]` at `this+0x18c + 0x80*slot`, `m_equipmentSlotDescriptions[slot]` at `this+0xc0c + 0x80*slot`, `m_equipmentSlotValues[slot]` at `this+0x168c + 4*slot`, and `m_equipmentSlotValueFlags[slot]` at `this+0x16e0 + slot`. These names are accepted for method-level C++ and class-layout documentation, but exact original member spellings remain unrecovered.

## Child Panes

- [UID:0000DK][SpelledPane](by-class/SpelledPane.md) is constructed at `0x005656cc` and stored at `this+0xfc`; [UID:0002RF][0x0056b950-0x0056b9ef.SelfLookPaneSpelledTextDispatch](by-memory/0x0056b950-0x0056b9ef.SelfLookPaneSpelledTextDispatch.md) supports the source-facing inferred field name `m_spelledPane` for that child pointer in method-level C++.
- UID0003QF independently confirms the same typed child at `+0xfc` in a complete retained wrapper: it forwards `const wchar_t *text`, `int value`, and fixed group `0` to `SpelledPane::AddOrUpdateEntry` with no guard or return value.
- [UID:0003QH][0x005671c0-0x005671de.SelfLookPaneRefreshSpelledPane](by-memory/0x005671c0-0x005671de.SelfLookPaneRefreshSpelledPane.md) independently confirms `m_spelledPane` at `this+0xfc`: exact SHA256 `8A6D7C4F31908097F9F7579236303740DEBF5B44FE030C47E882DDB204B3841C`, two direct calls from [UID:0003UN][0x005aac80-0x005aafe3.UserPaneHandleServerEntryPacket](by-memory/0x005aac80-0x005aafe3.UserPaneHandleServerEntryPacket.md), and accepted human source `m_spelledPane->RefreshScrollState()`. The old world-map label is rejected because the wrapper has no MapPane dependency.

## Server-Entry SpelledPane Refresh Contract

- The class declaration includes `void RefreshSpelledPane();` exactly once. Its body remains on UID0003QH and is emitted through [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md).
- UID0003UN retrieves GeneralPurposePanel child index zero as `SelfLookPane` and invokes the wrapper once in each EPF/legacy branch, at `0x005aacd5` and `0x005aae5c`.
- The exact 30-byte member loads `m_spelledPane` at `+0xfc` and performs the accepted FrameHandler remove-then-schedule operation represented by `SpelledPane::RefreshScrollState()`.
- `RefreshWorldMapPane` is retained only as superseded Wave2/B001 naming history. No MapPane receiver, field, global, or call appears in the wrapper.
- Class score remains `89/91`: the helper identity/body blocker is closed, but unrelated declaration-shell and broader field/name confidence caps remain. No unrelated class method, field, enum, owner/emitter, score, or formal content is changed.

## Stop-Only SpelledPane Refresh And Duplicate Reconciliation

- The class declaration retains exactly one `void StopSpelledPaneRefresh();` immediately after `RefreshSpelledPane()`. UID0004TT supplies the sole definition through [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md); UID0003QI supplies no declaration or definition.
- Exact method range is `[0x005671e0,0x005671f1)`, 17 bytes, SHA256 `880D30FF40EACEC7B49ED5D6B89E13D1FEBF9EA41EC4325E1A99631ECADC0227`. Its three instructions load `SpelledPane *m_spelledPane` at `SelfLookPane+0xfc`, add the `FrameHandler` base offset `0x174`, and directly tail-jump to nonvirtual `FrameHandler::RemoveFrame()` at `0x004b6d20`.
- Constructor `0x00565610` allocates and constructs the `0x184`-byte SpelledPane, then stores it at `+0xfc`. The current `0x2340` class layout and formal field `SpelledPane *m_spelledPane` therefore remain unchanged.
- The sole direct caller is UID0003TY at `0x0050fef2`. MapPane is caller context, while the typed SelfLookPane receiver and child field preserve this class and file route.
- UID0003QH remains the distinct remove-and-reschedule `RefreshSpelledPane()` member. UID0004TU is the NewSystemMessagePane stop-only twin, and raw SelfLookPane2 `[0x00570be0,0x00570bf1)` is no-xref structural evidence rather than another SelfLookPane member claim.
- Exact adjacent alignment is two `0xcc` bytes before the stop method and fifteen `0xcc` bytes after it. No vtable slot, data xref, VA/RVA pointer, indirect call, second caller, null guard, reschedule, return value, or separate target child exists.
- UID0003QI and UID0004TT cover the same range/hash and one IDA function. UID0004TT remains `92/94`, owner/emitter UID0000CU, reconstructable true; UID0003QI is `94/94`, owner `NONE`, reconstructable false, blank emitter/CPP/H. The former active `child refresh helper` row and unresolved virtual/member interpretation are retained only as superseded history.
- Class metadata remains `93/94`, owner/emitter UID0000NL, reconstructable true, with one declaration and no new header route. No unrelated method, enum, field, layout, vtable, source order, or formal source changes.

## ObjectStatusBlob state

- Destination 8 appends `m_selfLookObjectStatus` to the existing intentionally partial source-facing declaration skeleton. Raw update helpers and modeled packet-handler mirrors establish its binary backing at `SelfLookPane+0x108..+0x14b`, exactly 68 bytes. This source skeleton does not claim that omitted earlier binary fields are represented in declaration order.
- Raw starts `0x0056a500` and `0x0056a5c0` have zero direct xrefs and no modeled function objects, but bounded raw bytes contain exact full/partial calls at `0x0056a55d/0x0056a56f` and `0x0056a600/0x0056a627`. Modeled handler `0x005693d0` independently mirrors both update cases at `0x0056949b/0x005694b1` and `0x00569540/0x0056956b` against the same member storage.
- UID0002RB formal methods now use ObjectStatusBlob full/partial member calls instead of the historical `SelfLookRectState` and `DecodeSelfLookRectStateA/B` placeholders. Parser return lengths are intentionally ignored because both packet cases have fixed layouts and only the decoded 68-byte value is needed.
- ObjectStatusBlob remains owned by UID00009S/file UID0000M6. SelfLookPane is a consumer; class score `89/91`, owner/emitter UID0000NL, and every unrelated declaration/evidence item remain unchanged.
- [UID:000074][LegendPane](by-class/LegendPane.md) is constructed at `0x0056571c` and stored near `this+0x104`.
- Raw forwarders through `this+0xfc` remain `SelfLookPane` glue and do not transfer ownership to `SpelledPane`.

## Static State

- [UID:0002CG][g_selfLookLastHoverEquipmentSlotId](by-global/g_selfLookLastHoverEquipmentSlotId.md) at `0x0066fe40` caches the last hovered equipment slot id for the `OnMouseClick` / mouse-event timer path. It is initialized to `0xffff`, accepts only slot ids `7..20`, and is compared/updated inside [UID:0003QP][0x00568cb0-0x005693d0.SelfLookPaneOnMouseClick](by-memory/0x00568cb0-0x005693d0.SelfLookPaneOnMouseClick.md).

## Pending Server-Requested View Field

[UID:0003UT][0x005abda0-0x005abee8.UserPaneHandleUIPanelSwitchPacket](by-memory/0x005abda0-0x005abee8.UserPaneHandleUIPanelSwitchPacket.md) proves an external write into the SelfLookPane child at offset `+0x232c`. The packet handler reaches the self-look child through [UID:00015W][0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors](by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md) index `0` after sending private ACK helper `0x005acfe0`. It writes values `0`, `1`, `2`, or `3` depending on opcode `0x3e` `payload[1]` action byte and [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) mode: EPF action `4` writes `0`, legacy action `4` writes `1`, EPF action `7` writes `1`, legacy action `7` writes `3`, and action `8` writes `2` in both modes.

Keep the field name provisional. The best current documentation aliases are `m_serverRequestedViewMode` or `m_pendingServerViewMode`, because adjacent SelfLookPane docs already track view/cache state near `+0x2328` and `+0x233c`, but this pass did not prove the exact original member name or why legacy action `7` maps to `3`. Do not conflate `+0x232c` with GeneralPurposePanel `m_activeChildIndex` or with the opcode/action byte.

## Evidence Map

| Evidence page | Score | Role |
| --- | ---: | --- |
| [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md) | `87/90` | Source-file owner with `NexusTK/ui/panels/` placement, SelfLookPane/SelfLookPane2 grouping notes, child-pane caveats, static-state ownership, exact main-span child split summary, and accepted first-draft child emitters including [UID:0002RC][0x0056a640-0x0056b5c0.SelfLookPaneEquipmentRecordParser](by-memory/0x0056a640-0x0056b5c0.SelfLookPaneEquipmentRecordParser.md). |
| [UID:0001H7][0x00565610-0x0056a373.SelfLookPane](by-memory/0x00565610-0x0056a373.SelfLookPane.md) | `88/91` | Non-emitting main-span split index for the exact constructor/destructor/parser/toggle/view/paint/input/event/help/geometry/slot children. |
| [UID:00023V][0x0056a380-0x0056ba99.SelfLookPanePacketUpdateHelpers](by-memory/0x0056a380-0x0056ba99.SelfLookPanePacketUpdateHelpers.md) | `88/89` | Adjacent packet/update helper island split into exact child pages and attached to the same SelfLookPane class/file route. |
| [UID:00038M][SelfLookPaneFamilyVtables](by-type/by-vtable/SelfLookPaneFamilyVtables.md) | `87/91` | Source-local `SelfLookPane`/`SelfLookPane2` vtable layout parent for exact vtable-data children. |
| [UID:0002UY][0x00624188-0x00624210.SelfLookPaneVtableData](by-memory/0x00624188-0x00624210.SelfLookPaneVtableData.md) | `89/92` | Exact `SelfLookPane` vtable data with current source-local parent routing. |
| [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md) | `88/91` | Broad non-emitting cross-source look-pane vtable inventory retained for audit context only. |
| [UID:0002CG][g_selfLookLastHoverEquipmentSlotId](by-global/g_selfLookLastHoverEquipmentSlotId.md) | linked | File/static state tied by xrefs only to the SelfLookPane hover-slot branch. |

## Evidence Notes

- 2026-06-16 B001 source-split audit created exact child pages for the entire `0x00565610-0x0056a373` main span and reclassified [UID:0001H7][0x00565610-0x0056a373.SelfLookPane](by-memory/0x00565610-0x0056a373.SelfLookPane.md) as the non-emitting split index.
- The external `0x005a5bd0` callsites to `SendToggleLook` and `SendToggleEquip` first load [UID:0000R0][g_pGeneralPurposePanel](by-global/g_pGeneralPurposePanel.md), call [UID:00015W][0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors](by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md), and dispatch through the returned active child. This supports `SelfLookPane` reachability and rejects `UserPane` ownership.
- Live IDA confirms the constructor xref from `GeneralPurposePanel` at `0x004b844e`, child constructor xrefs at `0x005656cc`/`0x0056571c`, vtable refs to `0x00624188`, and the two `0x0066fe40` hover-slot refs in [UID:0003QP][0x00568cb0-0x005693d0.SelfLookPaneOnMouseClick](by-memory/0x00568cb0-0x005693d0.SelfLookPaneOnMouseClick.md).
- B006 2026-06-21 source-quality recheck of [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md) confirms `SelfLookPane::OnMouseClick` calls the item-action equipment helper fourteen times for equipment-click unequip selectors `4,2,3,1,22,7,8,20,21,23,14,6,13,16` at callsites `0x005690b0` through `0x0056918e`. This is a dependency on the file-level ItemActionInputPanes helper, not ownership transfer to SelfLookPane.
- 2026-06-20 B004 decoded [UID:0003UT][0x005abda0-0x005abee8.UserPaneHandleUIPanelSwitchPacket](by-memory/0x005abda0-0x005abee8.UserPaneHandleUIPanelSwitchPacket.md) as the only live opcode `0x3e` route that writes SelfLookPane `+0x232c` after retrieving the GeneralPurposePanel child index `0`; this supports a server-requested or pending self-look view-mode field but not a final field name.
- B006 2026-06-25 source-quality callback of [UID:0002RF][0x0056b950-0x0056b9ef.SelfLookPaneSpelledTextDispatch](by-memory/0x0056b950-0x0056b9ef.SelfLookPaneSpelledTextDispatch.md) supports inferred `m_spelledPane` at `this+0xfc` and first-draft `SelfLookPane::DispatchSpelledText`. Current MCP evidence reports a `__thiscall` receiver shape, text read at `0x00575a10`, value read at `0x00575790`, `SpelledPane` zero path `0x0056be20`, nonzero path `0x0056bca0`, string cleanup through `0x00582b70`, and an inline-equivalent event-handler case at `0x00569747-0x005697b2`.
- B006 2026-06-25 source-quality callback of [UID:0002RC][0x0056a640-0x0056b5c0.SelfLookPaneEquipmentRecordParser](by-memory/0x0056a640-0x0056b5c0.SelfLookPaneEquipmentRecordParser.md) supports first-draft `SelfLookPane::ApplyEquipmentSlotRecord`, the equipment selector enum, visible slot ids, the slot field family listed above, and the source-switch ownership of `0x0056b562-0x0056b5c0`. Current MCP evidence confirms opcode `0x37` dispatch, opcode `0x38` clear-switch sibling, no function at `0x0056b562` or `0x0056b5c0`, local-only switch-tail refs, decoded label bytes, and mouse-click selector triangulation.
- Dated IDA did not model functions at `0x00567180`, `0x005671a0`, or `0x005672b0`, but all remain reconstructable child evidence because their bytes and class-local behavior are source-shaped. Raw-start UID0003QE at `0x005670c0` and UID0003QF at `0x00567180` are now source-closed retained members; each missing current route remains only a bounded liveness cap. UID0003QG and UID0003QL retain their separate dispositions.
- The one-byte `0x00566f30-0x00566f31` `nullsub_51` remains non-emitting because no caller, vtable slot, pointer hit, or relative branch route was found.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 93 | The page carries the complete `0x2340` declaration/layout union, full paint/helper method surface including retained AddOrUpdateSpelledEntry, exact enums and field families, all prior packet/update methods, exact children, compiler exclusions, destructor/vtable/child/static evidence, and file route. |
| Confidence | 94 | Constructor/parser/paint/raw-helper offsets, vtables, callers, child construction, current support docs, and complete formal union agree. Exact original private lexical spellings and access grouping remain bounded uncertainty. |
| Reconstructable | true | The source-authored class now has a complete source-safe declaration; exact child pages continue to own method bodies. |

## Cross-References

- [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md)
- [UID:0001H7][0x00565610-0x0056a373.SelfLookPane](by-memory/0x00565610-0x0056a373.SelfLookPane.md)
- [UID:0003QF][0x00567180-0x0056719a.SelfLookPaneSpelledEntryUpdateForwarderRaw](by-memory/0x00567180-0x0056719a.SelfLookPaneSpelledEntryUpdateForwarderRaw.md)
- [UID:0004TT][0x005671e0-0x005671f1.SelfLookPaneStopSpelledPaneRefresh](by-memory/0x005671e0-0x005671f1.SelfLookPaneStopSpelledPaneRefresh.md)
- [UID:0003QI][0x005671e0-0x005671f1.SelfLookPaneRefreshSpelledChild](by-memory/0x005671e0-0x005671f1.SelfLookPaneRefreshSpelledChild.md)
- [UID:00023V][0x0056a380-0x0056ba99.SelfLookPanePacketUpdateHelpers](by-memory/0x0056a380-0x0056ba99.SelfLookPanePacketUpdateHelpers.md)
- [UID:00039F][0x00573730-0x00573818.SelfLookPaneScalarDeletingDestructor](by-memory/0x00573730-0x00573818.SelfLookPaneScalarDeletingDestructor.md)
- [UID:00038M][SelfLookPaneFamilyVtables](by-type/by-vtable/SelfLookPaneFamilyVtables.md)
- [UID:0002UY][0x00624188-0x00624210.SelfLookPaneVtableData](by-memory/0x00624188-0x00624210.SelfLookPaneVtableData.md)
- [UID:0002CG][g_selfLookLastHoverEquipmentSlotId](by-global/g_selfLookLastHoverEquipmentSlotId.md)
- [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md)
- [UID:0000CV][SelfLookPane2](by-class/SelfLookPane2.md)
- [UID:0000DK][SpelledPane](by-class/SpelledPane.md)
- [UID:000074][LegendPane](by-class/LegendPane.md)

## Changes

- 2026-08-24 B002 UID0003QI accepted callback: preserved `93/94`, UID0000NL ownership/emission, the complete `0x2340` declaration/layout, and every unrelated method/evidence item; replaced the active generic UID0003QI method-map row with sole canonical UID0004TT `StopSpelledPaneRefresh`, retained UID0003QI as ownerless/non-emitting duplicate inventory, and added exact range/hash/field/layout/caller/nonvirtual/sibling/padding/negative/one-declaration evidence without altering the existing declaration.
- 2026-08-24 B001 UID0003QF accepted callback: preserved `93/94`, UID0000NL owner/emitter, blank optional position, complete `0x2340` layout, class closure, blank formal H, and all unrelated declarations/evidence; inserted exactly `void AddOrUpdateSpelledEntry(const wchar_t *text, int value);` in the existing formal CPP class body immediately before `RefreshSpelledPane`; replaced the raw method-map identity and added exact range/hash/ABI/field/callee/duplicate/no-route/source and one-definition evidence. This supersedes only the old UID0003QF blank/provisional conclusion; exact original spelling/access remains a confidence cap.
- 2026-07-16 B002 UID0003QE callback: retained `93/94`, owner/emitter UID0000NL, blank position, complete `0x2340` layout, class closure, and every prior union member; added exact `SendToggleLook`, `SendToggleEquip`, and `SendToggleStats` declarations plus complete family identity, timer/state/packet/slot/final-tick, live-versus-retained route, negative, compiler-boundary, separate packet-helper, and historical-correction evidence.
- 2026-07-16 B002 UID0003QN callback: raised `89/91 -> 93/94`; replaced the partial skeleton with the complete accepted `0x2340` class/layout union; preserved all B004/B005/B006/B007/B011 methods and evidence; added exact view/slot/button enums, OnPaint/DrawNumberString/GetSlotRect/HitTestSlot declarations, complete field families, compiler exclusions, and class closure before `[[CHILDREN]]`; rejected invented `m_cachedLookState0..3` members.
- 2026-07-15 B004 UID0003UN callback: preserved the complete class declaration and all prior B001/B002/B004/B005 content, added `RefreshSpelledPane()` exactly, replaced the stale UID0003QH world-map method-map row, and incorporated exact wrapper hash/field/callers/FrameHandler/source/negative evidence without changing `89/91` or unrelated declarations.

- 2026-07-13 B005 UID000179 support callback: applied Destination 8 by preserving the complete prior class block and appending the resolved ObjectStatusBlob member. Added exact `this+0x108..+0x14b`, raw-start liveness, modeled-handler mirror, fixed-layout ignored-return, ownership, and placeholder-supersession evidence; scores and unrelated class surface are unchanged.

- 2026-07-01 B011 empty-emitter family implementation: Raised from `88/90` to `89/91`.
  - Inserted first-draft formal `SelfLookPane` declaration skeleton into the formal C++ block.
  - Historicalized the old class-level blank-C++ rationale: unresolved original field/helper names remain score caps, not empty-emitter blockers.
  - Linked the class skeleton to accepted child method/global/resource outputs for [UID:0003QP][0x00568cb0-0x005693d0.SelfLookPaneOnMouseClick](by-memory/0x00568cb0-0x005693d0.SelfLookPaneOnMouseClick.md), [UID:0003QQ][0x005693d0-0x00569860.SelfLookPanePacketEventHandler](by-memory/0x005693d0-0x00569860.SelfLookPanePacketEventHandler.md), [UID:0002RA][0x0056a380-0x0056a4f4.SelfLookPanePacketSendRawHelpers](by-memory/0x0056a380-0x0056a4f4.SelfLookPanePacketSendRawHelpers.md), [UID:0002RB][0x0056a500-0x0056a63e.SelfLookPaneRectUpdateRawHelpers](by-memory/0x0056a500-0x0056a63e.SelfLookPaneRectUpdateRawHelpers.md), [UID:0002RD][0x0056b5c0-0x0056b7c0.SelfLookPaneClearSlotSwitchRaw](by-memory/0x0056b5c0-0x0056b7c0.SelfLookPaneClearSlotSwitchRaw.md), [UID:0002RG][0x0056b9f0-0x0056ba99.SelfLookPaneViewToggleRaw](by-memory/0x0056b9f0-0x0056ba99.SelfLookPaneViewToggleRaw.md), [UID:0002CG][g_selfLookLastHoverEquipmentSlotId](by-global/g_selfLookLastHoverEquipmentSlotId.md), [UID:0003EY][0x006248e0-0x00624a50.SelfLookPaneEquipmentSlotLabelStrings](by-memory/0x006248e0-0x00624a50.SelfLookPaneEquipmentSlotLabelStrings.md), and [UID:000283][0x0066fe40-0x0066fe44.SelfLookPaneLastHoverEquipmentSlotId](by-memory/0x0066fe40-0x0066fe44.SelfLookPaneLastHoverEquipmentSlotId.md).

- 2026-06-25 B006 [UID:0002RC][0x0056a640-0x0056b5c0.SelfLookPaneEquipmentRecordParser](by-memory/0x0056a640-0x0056b5c0.SelfLookPaneEquipmentRecordParser.md) implementation support sync:
  - Score unchanged at `88/90`.
  - Added the accepted first-draft `SelfLookPane::ApplyEquipmentSlotRecord` method disposition, the inferred equipment selector/slot enum support, the sparse equipment slot field layout (`m_equipmentSlotItemIds`, `m_equipmentSlotRecordStates`, `m_equipmentSlotNames`, `m_equipmentSlotDescriptions`, `m_equipmentSlotValues`, and `m_equipmentSlotValueFlags`), current MCP caller/switch-tail evidence, and the reason this class-level formal declaration block remains blank.

- 2026-06-25 B006 [UID:0002RF][0x0056b950-0x0056b9ef.SelfLookPaneSpelledTextDispatch](by-memory/0x0056b950-0x0056b9ef.SelfLookPaneSpelledTextDispatch.md) implementation support sync:
  - Score unchanged at `88/90`.
  - Added the accepted first-draft `SelfLookPane::DispatchSpelledText` method disposition, the inferred `m_spelledPane` field support at `this+0xfc`, current MCP `__thiscall` receiver evidence, zero/nonzero `SpelledPane` callee roles, string cleanup, and inline packet-handler corroboration while preserving the class-level blank-C++ rationale.

- 2026-06-25 B007 [UID:0002RE][0x0056b7c0-0x0056b946.SelfLookPaneSummaryStatUpdate](by-memory/0x0056b7c0-0x0056b946.SelfLookPaneSummaryStatUpdate.md) source-quality support sync:
  - Score unchanged at `88/90`.
  - Added that [UID:0002RE][0x0056b7c0-0x0056b946.SelfLookPaneSummaryStatUpdate](by-memory/0x0056b7c0-0x0056b946.SelfLookPaneSummaryStatUpdate.md) now carries formal first-draft C++ as `SelfLookPane::ApplySelfLookSummaryRecord`, while this class-level formal block remains blank for broader declaration, field-name, packet-enum, and helper-name policy.

- 2026-06-16 B001 SelfLookPane split execution: Raised from `85/88` to `88/90` after creating exact main-span children [UID:0003Q8][0x00565610-0x005657d2.SelfLookPaneConstructor](by-memory/0x00565610-0x005657d2.SelfLookPaneConstructor.md)-[UID:0003QW][0x0056a300-0x0056a373.SelfLookPaneHitTestSlot](by-memory/0x0056a300-0x0056a373.SelfLookPaneHitTestSlot.md), reclassifying [UID:0001H7][0x00565610-0x0056a373.SelfLookPane](by-memory/0x00565610-0x0056a373.SelfLookPane.md) as a non-emitting split index, refreshing [UID:00023V][0x0056a380-0x0056ba99.SelfLookPanePacketUpdateHelpers](by-memory/0x0056a380-0x0056ba99.SelfLookPanePacketUpdateHelpers.md) support score from stale `76/84` to `88/89`, and documenting the active-child `UserPane` caller caveat.
  - Evidence: B001 report `tools/leaser/Agents/Agent-B001/research/0001H7-selflookpane-source-split-audit.md`, live IDA function/xref/vtable/global evidence, raw PE no-hidden-route scans, and existing SelfLookPane/SelfLookPane2/child-pane docs.

- 2026-06-20 B004 [UID:0003UT][0x005abda0-0x005abee8.UserPaneHandleUIPanelSwitchPacket](by-memory/0x005abda0-0x005abee8.UserPaneHandleUIPanelSwitchPacket.md) support sync:
  - Added provisional SelfLookPane `+0x232c` server-requested/pending view-mode field evidence, including the GeneralPurposePanel child-index `0` route, ACK-before-write behavior, exact values written for action bytes `4`, `7`, and `8`, and the reason this remains a formal C++ blocker for [UID:0003UT][0x005abda0-0x005abee8.UserPaneHandleUIPanelSwitchPacket](by-memory/0x005abda0-0x005abee8.UserPaneHandleUIPanelSwitchPacket.md).

- 2026-06-21 B006 SendTakeOffPacket support sync:
  - Score unchanged at `88/90`.
  - Added exact [UID:0001M2][0x005b27c0-0x005b2827.SendTakeOffPacket](by-memory/0x005b27c0-0x005b2827.SendTakeOffPacket.md) dependency evidence for `OnMouseClick` equipment-click unequip branches and explicitly rejected SelfLookPane ownership for that helper.

- 2026-06-12 A004 Batch 247: Score unchanged at `85/88`.
  - What changed: updated the scalar deleting destructor method row and cross-reference to exact child [UID:00039F][0x00573730-0x00573818.SelfLookPaneScalarDeletingDestructor](by-memory/0x00573730-0x00573818.SelfLookPaneScalarDeletingDestructor.md), which is now assigned here after reaching `88/92`.
  - Evidence: live IDA MCP reconfirmed the destructor wrapper boundary, vtable/thunk refs, `SelfLookPane` vtable stores, child cleanup offsets, and shared cleanup/delete calls.

- 2026-06-11 Agent-A001 Batch 232: Raised from `80/86` to `85/88`.
  - Before: the page had strong class evidence but stale file/vtable-family scores and did not clear the strict parent gate for source-local vtable routing.
  - After: updated file and vtable-family evidence, added the exact [UID:0002UY][0x00624188-0x00624210.SelfLookPaneVtableData](by-memory/0x00624188-0x00624210.SelfLookPaneVtableData.md) child evidence, and documented the live IDA Batch 232 store/boundary refresh.
  - Evidence: live IDA MCP reconfirmed the three `SelfLookPane` vtable bases, constructor/cleanup/scalar-destructor store refs, and the `GroupListPane` boundary; [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md) is `85/89` and [UID:00038M][SelfLookPaneFamilyVtables](by-type/by-vtable/SelfLookPaneFamilyVtables.md) is `87/91`.

- 2026-06-04: Raised from `76/84` to `80/86` after refreshing the class against live IDA and removing stale non-IDA provenance notes.
  - Evidence: IDA MCP confirmed function starts in `0x00565610-0x0056a373`, raw bodies, padding, child constructor xrefs, vtable refs, and hover-slot refs.

- 2026-05-28: Added `0x0056a380-0x0056ba99` as a SelfLookPane packet/update helper island.
- 2026-05-30: Added the `g_selfLookLastHoverEquipmentSlotId` static/global state owned by the hover-slot timer path.
- 2026-06-02: Raised from `55/70` to `76/84`, marked reconstructable, and attached to [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md) after consolidating the validated file, memory, vtable, and hover-slot evidence.

## B001 UID0003TY Stop-Refresh Declaration Synchronization - 2026-07-20

- The complete managed class declaration adds only `void StopSpelledPaneRefresh();` immediately after the existing `RefreshSpelledPane()` declaration. [UID:0004TT][0x005671e0-0x005671f1.SelfLookPaneStopSpelledPaneRefresh](by-memory/0x005671e0-0x005671f1.SelfLookPaneStopSpelledPaneRefresh.md) supplies the exact source definition.
- The helper is `[0x005671e0,0x005671f1)`, hashes to `880D30FF40EACEC7B49ED5D6B89E13D1FEBF9EA41EC4325E1A99631ECADC0227`, reads `m_spelledPane` at `+0xfc`, and tail-calls SpelledPane stop behavior. Its sole recovered caller is UID0003TY.
- [UID:0003QH][0x005671c0-0x005671de.SelfLookPaneRefreshSpelledPane](by-memory/0x005671c0-0x005671de.SelfLookPaneRefreshSpelledPane.md) remains the distinct remove-and-reschedule refresh method. The new declaration does not merge the two policies or duplicate the existing body.
- Class metadata remains `93/94`, canonical owner UID0000NL, reconstructable true, and blank position. The full current declaration, exact fields and layout, vtable surface, all unrelated children/content, class closure, and `[[CHILDREN]]` placement are preserved.
- Historical no-route/raw-helper or generic disable-refresh interpretations are superseded for this exact range. No timer removal, reschedule, null guard, compiler adjustor, or cross-class owner transfer is introduced.
