*** UID:0000CV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SelfLookPane2 : public PanelPane
{
public:
    enum ViewMode
    {
        ViewMode_Default = 0,
        ViewMode_Spelled = 1,
        ViewMode_Legend = 2
    };

    enum ButtonId
    {
        ButtonId_Look = 0,
        ButtonId_Equipment = 1,
        ButtonId_Stats = 2,
        ButtonId_Previous = 3,
        ButtonId_Next = 4
    };

    enum ButtonVisualState
    {
        ButtonVisualState_Disabled = 0xff
    };

    enum ButtonFrame
    {
        ButtonFrame_Normal = 0,
        ButtonFrame_Hover = 1,
        ButtonFrame_Pressed = 2
    };

    SelfLookPane2();
    virtual ~SelfLookPane2();

    virtual void OnActivate(const unsigned char *packetData);
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);

    void SendToggleLook();
    void SendToggleEquip();
    void SendToggleStats();
    void ShowDefaultView();
    void ShowSpelledView();
    void ShowProfileView();
    void ShowLegendView();
    void DrawStatText(const wchar_t *text,
                      int x,
                      int y,
                      bool alternateSet);
    void GetButtonRect(short buttonId, RectBounds *bounds) const;
    short HitTestButton(int y, int x) const;

    bool ApplySelfLookRectRecord(const unsigned char *packet);
    bool ApplySelfLookRectStateRecord(const unsigned char *packet);
    bool ApplyEquipmentSlotRecord(const unsigned char *packet);
    bool ClearEquipmentSlotRecord(const unsigned char *packet);
    bool ApplySelfLookSummaryRecord(const unsigned char *packet);
    bool DispatchSpelledText(const unsigned char *packet);

private:
    unsigned char *m_statDigitFrames;
    SpelledPane *m_spelledPane;
    ProfilePane *m_profilePane;
    LegendPane *m_legendPane;
    ObjectStatusBlob m_objectStatus;

    unsigned short m_headId;
    unsigned char m_headPalette;
    unsigned short m_leftAccessoryId;
    unsigned char m_leftAccessoryPalette;
    unsigned short m_rightAccessoryId;
    unsigned char m_rightAccessoryPalette;
    unsigned short m_leftSubAccessoryId;
    unsigned short m_rightSubAccessoryId;
    unsigned char m_leftSubAccessoryPalette;
    unsigned char m_rightSubAccessoryPalette;

    wchar_t m_identityLine1[256];
    wchar_t m_identityLine2[256];
    wchar_t m_statusLineA[256];
    wchar_t m_statusLineB[128];
    wchar_t m_statusName[128];
    unsigned int m_displayValueA;
    unsigned int m_displayValueB;
    unsigned char m_activationState0;
    unsigned char m_activationState1;
    unsigned char m_activationState2;
    unsigned int m_activationValue;
    unsigned int m_lastToggleTick;
    unsigned int m_toggleRepeatDelay;
    unsigned char m_equipmentToggleState;
    unsigned char m_lookToggleState;
    unsigned char m_statsToggleState;
    wchar_t m_auxiliaryText[256];
    wchar_t m_spelledSourceText[256];
    int m_viewMode;
    int m_profileState;
    int m_reservedViewState;
    ButtonFrame m_nextButtonFrame;
    ButtonFrame m_previousButtonFrame;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Complete PanelPane-derived 0xd90 SelfLookPane2 declaration with exact natural layout, ObjectStatusBlob m_objectStatus, primary +0x44 void OnPaint and +0x48 OnActivate, secondary EventHandler pointer/key/packet contracts, retained toggle helpers, source-ready paint/stat/button/view/input methods, signed y/x hit testing, typed next/previous button frames, five packet-update helpers plus DispatchSpelledText, complete class closure before children, and compiler/raw-liveness/lexical confidence caps. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# SelfLookPane2

## Status

- Confidence: very strong for class purpose, exact `0xd90` natural layout, primary `+0x48` OnActivate and secondary EventHandler `+0x04` HandlePointerOrMouseEvent, `+0x08` HandleKeyOrTextEvent, and `+0x10` HandlePacketEvent contracts, vtable/destructor ownership, exact main-span and post-core splits, ObjectStatusBlob field identity, five update helpers, and retained raw-helper liveness.
- Likely source file: [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md)
- Main address range: [UID:0001HK][0x0056fe80-0x005729c3.SelfLookPane2](by-memory/0x0056fe80-0x005729c3.SelfLookPane2.md)
- Current recovered file: `source-3/simroot_v2/class_SelfLookPane2.cpp`
- The accepted declaration is complete enough for source emission: exact inheritance, virtual contract, method inventory, natural field order/extent, and source-facing helper names are resolved. Descriptive names for opaque packet state and button fields remain explicit confidence caps rather than blockers.
- `[[CHILDREN]]` follows the complete class-closing `};`, so exact child definitions emit at namespace scope.

## Class Purpose

`SelfLookPane2` is a sibling self-look panel with three evidenced active mode values: default appearance/equipment (`0`), spelled/stat text (`1`), and legend text (`2`). It handles activation and packet decoding, ObjectStatusBlob updates, equipment slot apply/clear records, compare-only display-summary redraws, Spelled text dispatch, view switching, toggle-button hit testing, key/mouse input, character/stat rendering, and destructor cleanup for the same child-pane pattern used by `SelfLookPane`. UID0004NA preserves a complete raw ProfilePane view body, but no active mode value `3`, constructor initialization, or live call route is invented.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | `0x0056fe80-0x0057002c` | Initializes `PanelPane`, DAT-backed resource pointer, child `SpelledPane` and `LegendPane`, and compact self-look state. |
| non-deleting destructor | `0x00570030-0x005700d7` | IDA-confirmed cleanup body; currently unknown to Wave3. |
| `OnActivate(const unsigned char *)` | [UID:0003QZ][0x005700e0-0x0057092c.SelfLookPane2OnActivate](by-memory/0x005700e0-0x0057092c.SelfLookPane2OnActivate.md) `0x005700e0-0x0057092c` | Primary-vtable `+0x48` activation override; decodes packet state/text/equipment, synchronizes UserStatus, rebuilds Spelled/Legend children, detaches handlers, refreshes scroll state, and restores modes 1/2. Historical `OnDraw` title was rejected because the body performs no drawing. |
| `SendToggleLook` | [UID:0003R1][0x00570940-0x005709fa.SelfLookPane2SendToggleLookRaw](by-memory/0x00570940-0x005709fa.SelfLookPane2SendToggleLookRaw.md) | Retained private subtype-`0x08` helper; zero direct-entry xrefs, exact inline-copy liveness in UID0003RD. |
| `SendToggleEquip` | [UID:0003R2][0x00570a00-0x00570aba.SelfLookPane2SendToggleEquipRaw](by-memory/0x00570a00-0x00570aba.SelfLookPane2SendToggleEquipRaw.md) | Retained private subtype-`0x02` helper; zero direct-entry xrefs, exact inline-copy liveness in UID0003RD. |
| `SendToggleStats` | [UID:0003R3][0x00570ac0-0x00570b7a.SelfLookPane2SendToggleStatsRaw](by-memory/0x00570ac0-0x00570b7a.SelfLookPane2SendToggleStatsRaw.md) | Retained private subtype-`0x0b` helper; exhaustive no-current-route evidence retained as the confidence cap. |
| `ShowDefaultView` | [UID:0003R8][0x00570c00-0x00570c80.SelfLookPane2ShowDefaultView](by-memory/0x00570c00-0x00570c80.SelfLookPane2ShowDefaultView.md) `0x00570c00-0x00570c80` | Source-ready `void` mode-0 method with two class-internal callers: removes/unregisters Legend then Spelled, retains the `(17,192,174,251)` dead-local bounds initialization, and invalidates inherited bounds without attaching, scrolling, or touching ProfilePane. |
| `ShowSpelledView` | [UID:0003R9][0x00570c80-0x00570e17.SelfLookPane2ShowSpelledView](by-memory/0x00570c80-0x00570e17.SelfLookPane2ShowSpelledView.md) `0x00570c80-0x00570e17` | Source-ready `void` mode-1 method with four direct calls in three class methods: removes/unregisters Legend then Spelled, resets vertical Spelled scroll from current to zero in `(3,162,183,245)` bounds, attaches/orders on the root layer, trims and reinserts wide text, syncs scrollbars, recenters text-area bounds, and invalidates inherited bounds. |
| `ShowProfileView` raw | [UID:0004NA][0x00570e20-0x00570eef.SelfLookPane2ShowProfileViewRaw](by-memory/0x00570e20-0x00570eef.SelfLookPane2ShowProfileViewRaw.md) `0x00570e20-0x00570eef` | Retained complete source-shaped ProfilePane detach/reset/attach helper with no modeled function, direct xref, mode-3 store, or constructor initialization. |
| `ShowLegendView` | [UID:0003RA][0x00570ef0-0x00570fb3.SelfLookPane2ShowLegendView](by-memory/0x00570ef0-0x00570fb3.SelfLookPane2ShowLegendView.md) `0x00570ef0-0x00570fb3` | Source-ready `void` mode-2 method with three class-internal callers: removes/unregisters Spelled then Legend, resets vertical Legend scroll from current to zero in `(3,10,183,239)` bounds, attaches to the root pane layer, applies pane order, and invalidates inherited bounds. |
| `OnPaint` | `0x00570fc0-0x00571c05` | Paints panel contents and active child view. |
| `HandleKeyOrTextEvent(Event *)` | [UID:0003RC][0x00571c10-0x00571cb2.SelfLookPane2HandleKeyOrTextEvent](by-memory/0x00571c10-0x00571cb2.SelfLookPane2HandleKeyOrTextEvent.md) `0x00571c10-0x00571cb2` | Secondary EventHandler-vtable `+0x08` override. Translates key/modifier input before requiring key-down, consumes only unmodified Page Up/Page Down, and follows the exact Default/Spelled/Legend transition matrix, including recognized no-call boundary states. |
| `HandlePointerOrMouseEvent(Event *)` | [UID:0003RD][0x00571cc0-0x005720ff.SelfLookPane2HandlePointerOrMouseEvent](by-memory/0x00571cc0-0x005720ff.SelfLookPane2HandlePointerOrMouseEvent.md) | Secondary EventHandler-facet vtable `+0x04` override; exact cursor-move, left-button-down, and left-button-up state machine with help-pane and toggle/view action handling. |
| `HandlePacketEvent(Event *)` | [UID:0003RE][0x00572120-0x005725ed.SelfLookPane2HandlePacketEvent](by-memory/0x00572120-0x005725ed.SelfLookPane2HandlePacketEvent.md) | Secondary EventHandler-facet vtable `+0x10` override at cell `0x00624758`; packet payload is Event `+0x0c`; dispatches opcodes `0x08/0x1d/0x33/0x37/0x38/0x39/0x3a` to the five update methods, OnActivate, and DispatchSpelledText. |
| `DrawStatText` | `0x005726a0-0x00572771` | Draws stat labels/values. |
| `GetButtonRect` | `0x00572780-0x00572885` | Computes toggle/action button rectangles. |
| `HitTestButton` | [UID:0003RH][0x005728a0-0x005729c3.SelfLookPane2HitTestButton](by-memory/0x005728a0-0x005729c3.SelfLookPane2HitTestButton.md) | Exact `short HitTestButton(int y, int x) const` helper; tests all five button ids in order and returns signed `-1` when no bounds contain the point. |
| packet-send helper group | [UID:00039L][0x005729e0-0x00572b54.SelfLookPane2PacketSendRawHelpers](by-memory/0x005729e0-0x00572b54.SelfLookPane2PacketSendRawHelpers.md) | Three raw no-function four-byte packet send helpers for subtypes `0x02`, `0x08`, and `0x0b`; attached here after the parent gate repair. |
| look/update split index | [UID:00039M][0x00572b60-0x00572f25.SelfLookPane2LookUpdateRawHelpers](by-memory/0x00572b60-0x00572f25.SelfLookPane2LookUpdateRawHelpers.md) | Non-emitting exact index over five retained source methods, two compiler jump tables, two selector maps, and alignment; child-only emission. |
| `ApplySelfLookRectRecord` | [UID:0004Q0][0x00572b60-0x00572c1e.SelfLookPane2ApplySelfLookRectRecord](by-memory/0x00572b60-0x00572c1e.SelfLookPane2ApplySelfLookRectRecord.md) | Object-id-gated temporary full/partial ObjectStatusBlob decode/copy, invalidation, false. |
| `ApplySelfLookRectStateRecord` | [UID:0004Q1][0x00572c20-0x00572ca0.SelfLookPane2ApplySelfLookRectStateRecord](by-memory/0x00572c20-0x00572ca0.SelfLookPane2ApplySelfLookRectStateRecord.md) | Object-id-gated direct full/partial ObjectStatusBlob member parse, invalidation, false. |
| `ApplyEquipmentSlotRecord` | [UID:0004Q2][0x00572ca0-0x00572da4.SelfLookPane2ApplyEquipmentSlotRecord](by-memory/0x00572ca0-0x00572da4.SelfLookPane2ApplyEquipmentSlotRecord.md) | Selectors 4/7/8/20/21 write id/palette pairs; all paths invalidate and return true. |
| `ClearEquipmentSlotRecord` | [UID:0004Q3][0x00572dd0-0x00572e88.SelfLookPane2ClearEquipmentSlotRecord](by-memory/0x00572dd0-0x00572e88.SelfLookPane2ClearEquipmentSlotRecord.md) | Selectors 4/7/8/20/21 clear ids only and retain palettes; all paths invalidate and return true. |
| `ApplySelfLookSummaryRecord` | [UID:0004Q4][0x00572ec0-0x00572f25.SelfLookPane2ApplySelfLookSummaryRecord](by-memory/0x00572ec0-0x00572f25.SelfLookPane2ApplySelfLookSummaryRecord.md) | Mask-`0x40` optional BE32 display-value comparison, no stores, conditional invalidation, false. |
| `DispatchSpelledText` | [UID:00039N][0x00572f30-0x00572fcf.SelfLookPane2SpelledEntryDispatch](by-memory/0x00572f30-0x00572fcf.SelfLookPane2SpelledEntryDispatch.md) | ANSI StringBase/cursor decode and BE32 value dispatch to embedded SpelledPane remove/add-or-update; true. |
| SpelledPane entry-vector helper | `0x00572fd0-0x00573232` | IDA-confirmed helper called from `0x0056bdbc` and `0x0056c26d`; current evidence places it with [UID:0000DK][SpelledPane](by-class/SpelledPane.md) entry storage rather than SelfLookPane2. |
| adjustor thunk | `0x005732c0` | Mixed destructor/thunk island entry. |
| scalar deleting destructor | [UID:00039E][0x00573640-0x00573728.SelfLookPane2ScalarDeletingDestructor](by-memory/0x00573640-0x00573728.SelfLookPane2ScalarDeletingDestructor.md) | Full class destructor plus conditional delete; exact child assigned here after the Batch 247 parent-gate recheck. |

## UID00039M Packet Update Split And Liveness

- UID00039M is `92/94`, false/non-emitting, and retains semantic ownership here only as a split index. UID0004Q0-UID0004Q4 are exact one-argument source methods with complete formal bodies; UID0003RE and UID00039N provide the live virtual dispatcher and Spelled route.
- All five raw starts have zero IDA xrefs and zero PE VA/RVA/raw/rel32 routes. This negative evidence does not make them dead: UID0003RE is anchored by vtable cell `0x00624758` and contains exact inline mirrors for opcodes `0x33`, `0x1d`, `0x37`, `0x38`, and `0x08`. Retained out-of-line source copies are the strongest explanation.
- Compiler-only spans `0x00572da4-0x00572dce` and `0x00572e88-0x00572eb2` are jump-table/selector-map lowering for the two source switches. Padding at `0x00572c1e-0x00572c20`, `0x00572dce-0x00572dd0`, `0x00572eb2-0x00572ec0`, and `0x00572f25-0x00572f30` is excluded from source.
- The update methods use `g_pUserPane->GetObjectId()` rather than stale collection-private/raw-offset syntax. `std::to_char_type`, explicit tables/maps, SEH/EH cleanup, and inlined copies are compiler details rather than class APIs.
- Rejected alternatives preserved: aggregate UID00039M body, blank/no-code due to zero xrefs, hand-emitted compiler data, `LivingSpriteConfig`, duplicate struct/byte array, foreign ObjectStatusBlob/UserPane/SpelledPane ownership, direct raw offsets/casts, and invented semantics for `m_displayValueA/B`.
- Public declaration placement follows the established helper surface. Original access control and method/member lexical names do not survive, so descriptive names and source-file placement remain confidence caps without changing exact `0xd90` layout or behavior.

## Main Span Split Summary

- [UID:0001HK][0x0056fe80-0x005729c3.SelfLookPane2](by-memory/0x0056fe80-0x005729c3.SelfLookPane2.md) is now a non-emitting class-method split index, not a reconstructable aggregate.
- Exact children [UID:0003QX][0x0056fe80-0x0057002c.SelfLookPane2Constructor](by-memory/0x0056fe80-0x0057002c.SelfLookPane2Constructor.md)-[UID:0003RH][0x005728a0-0x005729c3.SelfLookPane2HitTestButton](by-memory/0x005728a0-0x005729c3.SelfLookPane2HitTestButton.md), plus serially registered [UID:0004NA][0x00570e20-0x00570eef.SelfLookPane2ShowProfileViewRaw](by-memory/0x00570e20-0x00570eef.SelfLookPane2ShowProfileViewRaw.md), cover the constructor/destructor, OnActivate, null stub, raw packet toggles, raw `SpelledPane` forwarders, child refresh helpers, all four source-shaped view helpers, paint/key/input/packet handling, stat drawing, button geometry, and hit-test helper.
- Raw no-function bodies at `0x00570940`, `0x00570a00`, `0x00570ac0`, `0x00570b80`, `0x00570ba0`, `0x00570bc0`, and `0x00570be0` remain `SelfLookPane2` child evidence because raw bytes and behavior are source-shaped, while PE scans found no hidden pointer/branch routes.
- The one-byte [UID:0003R0][0x00570930-0x00570931.SelfLookPane2NullStub](by-memory/0x00570930-0x00570931.SelfLookPane2NullStub.md) is non-emitting.
- The tail `0x005729c3-0x005729e0` remains ignored compiler switch/jump-table data plus alignment after [UID:0003RH][0x005728a0-0x005729c3.SelfLookPane2HitTestButton](by-memory/0x005728a0-0x005729c3.SelfLookPane2HitTestButton.md), before [UID:00023X][0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers](by-memory/0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers.md).

## Exact Class Layout

| Offset | Size | Source-facing field/type | Exact evidence and caveat |
| --- | ---: | --- | --- |
| inherited `+0x000..+0x0f7` | `0xf8` | `PanelPane` | Constructor/base/vtable family. |
| `+0x0f8` | 4 | `unsigned char *m_statDigitFrames` | Resource lookup id 99; OnPaint/stat use; destructor frees. Exact lexical type is descriptive. |
| `+0x0fc` | 4 | `SpelledPane *m_spelledPane` | Constructor, parser, view helpers, destructor. |
| `+0x100` | 4 | `ProfilePane *m_profilePane` | Raw ShowProfile helper only; constructor omission/no-route caveat retained. |
| `+0x104` | 4 | `LegendPane *m_legendPane` | Constructor, target rich text, view helpers, destructor. |
| `+0x108` | `0x44` | `ObjectStatusBlob m_objectStatus` | Exact 68-byte full/partial parser and copy contract; ends at `+0x14c`. Historical `LivingSpriteConfig` is superseded. |
| `+0x14c/+0x14e` | 2/1 | head id/palette | Selector 4; natural pad at `+0x14f`. |
| `+0x150/+0x152` | 2/1 | left accessory id/palette | Selector 7; natural pad at `+0x153`. |
| `+0x154/+0x156` | 2/1 | right accessory id/palette | Selector 8; natural pad at `+0x157`. |
| `+0x158/+0x15a/+0x15c/+0x15d` | 2/2/1/1 | left/right sub ids and palettes | Selectors 20/21; packed exact order. |
| `+0x15e` | `0x200` | `wchar_t m_identityLine1[256]` | First packet text. |
| `+0x35e` | `0x200` | `wchar_t m_identityLine2[256]` | Second packet text converted directly into member. |
| `+0x55e` | `0x200` | `wchar_t m_statusLineA[256]` | First UserStatus display text snapshot. |
| `+0x75e` | `0x100` | `wchar_t m_statusLineB[128]` | Second display text snapshot. |
| `+0x85e` | `0x100` | `wchar_t m_statusName[128]` | `CopyNameLineA` destination. |
| `+0x95e` | 2 | natural alignment | No explicit source field. |
| `+0x960/+0x964` | 4/4 | display values A/B | UserStatus dword getters. |
| `+0x968..+0x96a` | 3 | activation state bytes | packet[1..3], descriptive names. |
| `+0x96b` | 1 | natural alignment | No explicit source field. |
| `+0x96c` | 4 | activation value | BE32 packet field. |
| `+0x970/+0x974` | 4/4 | last toggle tick/repeat delay | Constructor/toggle helper consumers; delay initialized 1000. |
| `+0x978..+0x97a` | 3 | equipment/look/stats toggle states | Raw subtype 02/08/0B helpers prove mapping. |
| `+0x97b` | 1 | natural alignment | No explicit source field. |
| `+0x97c` | `0x200` | auxiliary text[256] | Fourth text sequence. |
| `+0xb7c` | `0x200` | spelled source text[256] | TAB-to-LF conversion and UID0004N5 source. |
| `+0xd7c` | 4 | view mode | Exact active values 0/1/2. |
| `+0xd80` | 4 | profile state | Constructor/target clear. Exact lexical meaning capped. |
| `+0xd84` | 4 | reserved view state | No observed read/write in checked family; retained to close exact extent. |
| `+0xd88/+0xd8c` | 4/4 | button frame state A/B | Constructor/OnPaint consumers. Descriptive names. |
| extent `+0xd90` |  | complete natural size | Highest field end; decimal 3472. |

Source access control: activation/paint/event methods remain virtual and callable through the Pane interface. View/draw/geometry helpers are public in the first draft because existing generated child definitions and current project convention expose them; data fields remain private. No external source directly accesses the new fields. No explicit padding member is emitted: old 32-bit MSVC natural alignment supplies the holes after the first three palette bytes, the three activation bytes, and the three toggle bytes.

The direct UID0003RA pass reinforces this access decision without claiming it is the original lexical spelling. UID0003RA has only three class-internal direct calls and no vtable/data/pointer route, so private is stylistically possible, but binary evidence cannot prove C++ access control. The existing public `void ShowLegendView();` declaration remains implementation-safe and avoids a speculative class-formal rewrite.

The same source-access policy applies to UID0003R9: all four call sites are class-internal, so private source access is plausible, but binary evidence cannot encode access control. The existing public `void ShowSpelledView();` declaration is implementation-safe and leaves the exact `0xd90` field layout unchanged.

The EventHandler override also remains public in the first draft, matching the base event-family virtual interface and the existing public virtual section. Binary evidence cannot encode lexical access control, but public access is implementation-safe and does not alter the `0xd90` data layout.

## UID0003R8 ShowDefaultView Evidence

- UID0003R8 is one exact nonvirtual member at `[0x00570c00,0x00570c80)`, `0x80`/128 bytes, SHA-256 `1A063ADD166FC8B8876C107CC6D6D6EBE4C7CBB4BB9497D2EA7CBFB270A3251E`, with 41 instructions, one block, no branch, thiscall `ECX`, no stack arguments, and plain `retn`. Its 15-byte predecessor `cc` span remains parent-only and UID0003R9 begins immediately at `0x00570c80`.
- Exact source signature is `void ShowDefaultView()`. IDA's integer inference is final `InvalidateRect` EAX propagation and both callers ignore it. The existing public declaration is implementation-safe; private source access is plausible but not encoded by the binary.
- The method writes `m_viewMode = ViewMode_Default` before any virtual call; removes then unregisters `m_legendPane`; removes then unregisters `m_spelledPane`; initializes retained local `RectBounds defaultBounds` with `(17,192,174,251)` even though no later instruction reads it; and finally calls `InvalidateRect(&m_bounds)`.
- Exact layout relations are `m_spelledPane +0xfc`, untouched `m_profilePane +0x100`, `m_legendPane +0x104`, `m_viewMode +0xd7c`, and inherited `m_bounds +0x44`. Pane slots `+0x38/+0x40/+0x20` prove `RemoveFromLayer`, `UnregisterEventHandler`, and `InvalidateRect` respectively; helper `0x004b7c50` proves left/top/right/bottom argument order.
- Exact direct callers are UID0003RC unmodified PageUp from Spelled mode at `0x00571c5b` and UID0003RD previous-view case 3 from Spelled mode at `0x00571f97`. Both ignore EAX. UID0003RD owns its subsequent `m_nextButtonFrame = ButtonFrame_Normal`, `m_previousButtonFrame = ButtonFrame_Pressed`, inherited-bounds invalidation, and true return.
- Exhaustive code/data/immediate/VA/RVA/vtable checks found no route beyond those two calls and no interior entry. The target has no attach/register, scroll, ProfilePane, mode-3, branch, null, packet, draw, allocation, global/table, secondary-facet, or manual vtable/RTTI behavior.
- `ShowDefaultView`, local `defaultBounds`, public access, and `SelfLookPane.cpp` are source-quality best-current names/placement rather than symbol-proven lexical facts. Those caps and the unrecoverable historical reason for the dead local preserve class `93/94`; they do not change the exact `0xd90` declaration or formal class block.

## UID0003R9 ShowSpelledView Evidence

- UID0003R9 is one exact nonvirtual member at `[0x00570c80,0x00570e17)`, `0x197` / 407 bytes, SHA256 `A7C857FA236C9A00672E1A02BC8AF37E40DC04184D86FACF0A2F58F87D6544A4`. Its 118 in-range instructions form one branchless block; twelve external analyzer nodes are compiler EH/cookie support. UID0003R8 ends at the target start, and the nine `cc` bytes `[0x00570e17,0x00570e20)` remain parent-only before UID0004NA.
- Exact source signature is `void ShowSpelledView()`. ECX is the complete object, there are no source arguments, every caller ignores EAX, and the formal class declaration already carries the implementation-safe public member exactly once.
- The method stores `m_viewMode = ViewMode_Spelled`; removes then unregisters `m_legendPane`; removes then unregisters `m_spelledPane`; initializes `(3,162,183,245)` bounds; applies axis-0 scroll from observed current position to target zero; attaches Spelled through `g_mainUiLayerSlots.rootPaneLayerContext`; sets pane order `0` relative to `this`; obtains a wide StringBase by hidden-result return; trims `L" \t\n\r"` left then right; clears/reinserts text with signed-short length and zero selection arguments; sets selection `(0,0)`; synchronizes scrollbars; recenters text-area bounds by `-top`; and invalidates inherited `m_bounds`.
- Exact layout relations are `m_spelledPane +0xfc`, untouched `m_profilePane +0x100`, `m_legendPane +0x104`, `m_viewMode +0xd7c`, and inherited `m_bounds +0x44`. This reinforces the existing natural declaration and requires no padding field, new storage, or altered inheritance.
- Exact direct calls are UID0003QZ mode-1 activation restore, UID0003RC's common PageUp-from-Legend/PageDown-from-Default path, and UID0003RD previous-from-Legend/next-from-Default paths. Those callers retain their own parsing, key translation, consumed-return, button-frame, and redraw effects.
- Exhaustive code/data/immediate/VA/RVA/pointer/vtable/interior checks found no additional route. No Profile, branch, null guard, packet, draw, allocation, mode 3, second/maximum scroll, caller frame state, manual vtable/RTTI, or explicit compiler support belongs in the method.
- `ShowSpelledView`, inferred local names, public access, and `SelfLookPane.cpp` are best-current human source choices rather than symbol-proven spellings. These lexical/physical-file caps preserve class `93/94` without weakening exact behavior, owner/emitter routing, or formal completeness.

## UID0003RC Key/Text Override Evidence

- The secondary SelfLookPane2 vtable locator is `0x00624744`, its base is `0x00624748`, and cell `+0x08` at `0x00624750` points solely to UID0003RC. There is no ordinary code caller, duplicate data pointer, immediate route, or RVA pointer.
- The override receives the EventHandler facet at complete-object offset `+0xa0`. Its mode read at facet `+0xcdc` is the established complete-object `m_viewMode` at `+0xd7c`; each view-helper call lowers as `lea ecx,[facet-0xa0]`. This is receiver adjustment, not a separate subobject field or raw-layout member.
- The exact source signature is `bool HandleKeyOrTextEvent(Event *event)`: Event `m_type` is read at `+4`, key at `+8`, and modifiers at `+0x10a`; the function returns truth-valued `AL` and uses `retn 4`. Historical `HandleKeyEvent(const PanelKeyEvent *)`, raw-byte, integer-return, const-event, and free-function forms conflict with the current EventHandler slot and ABI.
- `g_pEventMan->TranslateEventKey(event->m_payload.m_key.m_key, event->m_payload.m_key.m_modifiers)` executes before the `kEventKeyDown` (`8`) test. The exact machine push order is modifiers then key, yielding source argument order key then modifiers. IDA's stale CRT label for the ten-byte helper is rejected by the global receiver and 81 keyboard-handler callers.
- Translated `0x93` (`kPaneKeyPageUp`) with zero modifiers maps Legend (`2`) to `ShowSpelledView`, Spelled (`1`) to `ShowDefaultView`, and Default (`0`) or any other mode to a consumed no-call. Translated `0x94` (`kPaneKeyPageDown`) with zero modifiers maps Spelled (`1`) to `ShowLegendView`, Default (`0`) to `ShowSpelledView`, and Legend (`2`) or any other nonzero mode to a consumed no-call. Every recognized unmodified route returns `true`.
- Non-key-down input, any other translated key, and either recognized key with nonzero modifiers return `false`. There is no base fallback, direct mode write, Profile-mode route, packet/drawing/allocation call, text-payload read, or tested helper result.
- Exact target size is `0xa2` / 162 bytes with SHA256 `1CB7A6B49D3183AAFC55DF0F84CA0C247CAE7F444466ABA66B557FF93B3B6ADA`. The eleven-byte predecessor and fourteen-byte successor `cc` spans remain parent-only under UID0001HK; the class declaration adds no padding or storage for them.

## Evidence Notes

- 2026-06-16 B001 SelfLookPane2 source-split audit used live IDA session `b001_selflookpane_0001H7_20260616`, existing SelfLookPane/SelfLookPane2/vtable/helper docs, and local PE scans to split [UID:0001HK][0x0056fe80-0x005729c3.SelfLookPane2](by-memory/0x0056fe80-0x005729c3.SelfLookPane2.md) into exact child pages [UID:0003QX][0x0056fe80-0x0057002c.SelfLookPane2Constructor](by-memory/0x0056fe80-0x0057002c.SelfLookPane2Constructor.md)-[UID:0003RH][0x005728a0-0x005729c3.SelfLookPane2HitTestButton](by-memory/0x005728a0-0x005729c3.SelfLookPane2HitTestButton.md) and reclassify the parent as non-emitting.
- Wave3 reports `SelfLookPane2` grade `97.8` and zero missing refs.
- IDA confirms the constructor, draw/view/input/stat/button functions listed above.
- IDA confirms bytes at `0x00570940`, `0x00570a00`, and `0x00570ac0` look function-prologue-shaped, but no IDA function records or xrefs currently exist at those starts.
- 2026-06-01 IDA MCP recheck confirms the modeled function map through `0x005728a0`, constructor child-pane calls to `SpelledPane` and `LegendPane`, cleanup in `0x00570030`, input-handler calls to the button hit-test helper, view switches, packet builder, and packet sender.
- 2026-06-11 Agent-A001 Batch 186 follow-up live IDA MCP recheck against `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` reconfirmed the modeled core function map, raw `Not a function` status for `0x00570940`, `0x00570a00`, `0x00570ac0`, `0x005729e0`, `0x00572a60`, `0x00572ae0`, and `0x00572b60`, no direct start xrefs for the raw helper starts, `SelfLookPane2` vtable store refs at `0x0056feb3`, `0x0057005b`, and `0x00573672`, and scalar deleting destructor refs from adjustor thunks plus the primary vtable.
- 2026-07-14 UID0003QZ research proved the primary cell `0x00624740` is `OnActivate`, mapped every target access into the natural `0xd90` declaration, and established exact UID0004NA raw ProfilePane bytes/hash/body. Raw no-route and descriptive-name caveats cap the score but do not block source emission.
- 2026-07-14 UID0003RA direct research proves `ShowLegendView` is a modeled 195-byte nonvirtual source method with SHA256 `95E0FFBABDFA83E9DAB9677A153E61D7A3B14F5F1A5954A580CC600B52A7B040`. It writes `m_viewMode = ViewMode_Legend`, touches only `m_spelledPane` and `m_legendPane`, preserves remove-before-unregister order, uses accepted Pane/ScrollablePane APIs, and is called exactly from UID0003QZ mode-2 restore, UID0003RC unmodified PageDown from mode 1, and UID0003RD next-view case 4 from mode 1.
- 2026-07-14 UID0003RC direct research proves the secondary EventHandler `+0x08` cell targets one exact 162-byte source method. Exact Event offsets, translator-first call order, raw `0x93/0x94` key compares, both modifier gates, all true/false exits, complete-object adjustment, and all three view-helper calls close the former signature/body blocker without altering the accepted natural layout.
- UID0003RA's exact geometry is `(3,10,183,239)`; it applies axis-0 scroll from observed current position to target zero, attaches through `g_mainUiLayerSlots.rootPaneLayerContext`, calls `SetPaneOrder(0,this)`, and invalidates inherited `m_bounds`. It does not access `m_profilePane`, null-check, read a scroll maximum, perform a second scroll, register after attachment, or return the invalidation result.
- No evidence supports a `ViewMode_Profile = 3`, explicit padding fields, manual vtable/RTTI arrays, direct parser ownership, or moving this class to ProfilePane/SpelledPane/UserLookPane source.

## Paint, Stat, And Button Closure

- Primary vtable slot `+0x44` is [UID:0003RB][0x00570fc0-0x00571c05.SelfLookPane2OnPaint](by-memory/0x00570fc0-0x00571c05.SelfLookPane2OnPaint.md), exact source ABI `virtual void OnPaint()`. The 3,141-byte body has 918 instructions, 68 blocks, complexity 29, one vtable data route, no direct code caller, and complete source for background, body, equipment, buttons, labels, and percent stats.
- `ButtonId` is the five-value selector used by thirteen geometry calls: Look 0, Equipment 1, Stats 2, Previous 3, and Next 4. `ButtonVisualState_Disabled` is exact byte value `0xff`. These source-facing enums remove repeated magic values without changing layout.
- [UID:0003RF][0x005726a0-0x00572771.SelfLookPane2DrawStatText](by-memory/0x005726a0-0x00572771.SelfLookPane2DrawStatText.md) is `void DrawStatText(const wchar_t *, int, int, bool)`: exact 9x11 cells, row stride 9, 99-byte frame calculation, space/slash skip with unconditional advance, and three OnPaint callers.
- [UID:0003RG][0x00572780-0x00572885.SelfLookPane2GetButtonRect](by-memory/0x00572780-0x00572885.SelfLookPane2GetButtonRect.md) is `void GetButtonRect(short, RectBounds *) const`: exact five-button/three-mode matrix, all-minus-one invalid bounds, thirteen callers, and compiler-generated local switch table.
- `ObjectStatusBlob m_objectStatus` remains the exact 68-byte field at `+0x108..+0x14b`. B004's six declarations and seven packet-source methods remain intact: UID0003RE `HandlePacketEvent`, UID0004Q0-UID0004Q4 update methods, and UID00039N `DispatchSpelledText`.
- Resource literals remain use-site expressions in `NexusTK/ui/panels/SelfLookPane.cpp`: `SELFLOOK.EPF`, `SELFLOOK.PAL`, `STATBUT.EPF`, `BUTTON.PAL`, the two exact escaped labels, and `%u`. No class-static resource globals are introduced.
- Exact natural layout and total size `0xd90` are unchanged. Source signatures correct stale bool OnPaint, zero-argument DrawStatText, and int-id GetButtonRect declarations without changing vtable order, fields, inheritance, or B004 packet behavior.
- Security cookies, UID0003RG's local switch table, vtable/RTTI arrays, adjustors, scalar deleting wrappers, and padding remain compiler-generated. No manual ABI declaration or duplicate method body is added.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 93 | Exact inheritance, virtual/member inventory, natural `0xd90` declaration, OnActivate, EventHandler key/text override, raw-profile, and source-ready ShowDefaultView/ShowSpelledView/ShowLegendView routes, split ownership, child definitions, and source/compiler dispositions are documented and emitted. |
| Confidence | 94 | Primary and secondary vtable cells, constructor/destructor/method offsets, exact Event ABI and transition callgraph, all three source-ready view bodies/calls/fields/helpers, target packet accesses, hidden-result text lifecycle, sibling methods, and raw helper bytes corroborate the model. Original lexical names, ProfilePane liveness, and direct allocation-size proof remain confidence caps. |

## Cross-References

- [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md)
- [UID:0001Y0][LookPaneVtableFamily](by-type/by-vtable/LookPaneVtableFamily.md)
- [UID:0001HK][0x0056fe80-0x005729c3.SelfLookPane2](by-memory/0x0056fe80-0x005729c3.SelfLookPane2.md)
- [UID:0003QX][0x0056fe80-0x0057002c.SelfLookPane2Constructor](by-memory/0x0056fe80-0x0057002c.SelfLookPane2Constructor.md)-[UID:0003RH][0x005728a0-0x005729c3.SelfLookPane2HitTestButton](by-memory/0x005728a0-0x005729c3.SelfLookPane2HitTestButton.md)
- [UID:00023X][0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers](by-memory/0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers.md)
- [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md)
- [UID:00039E][0x00573640-0x00573728.SelfLookPane2ScalarDeletingDestructor](by-memory/0x00573640-0x00573728.SelfLookPane2ScalarDeletingDestructor.md)
- [UID:0000CU][SelfLookPane](by-class/SelfLookPane.md)
- [UID:0000DK][SpelledPane](by-class/SpelledPane.md)
- [UID:000074][LegendPane](by-class/LegendPane.md)

## Changes

- 2026-07-16 Agent-B004 UID0003RD callback: retained `94/94` and the complete B001/B002/B003/B004/B005/B011 class union; added the `ButtonFrame` enum, exact `HandlePointerOrMouseEvent(Event *)` and `HandlePacketEvent(Event *)` virtual identities, three retained toggle-helper declarations, signed `short HitTestButton(int y, int x) const`, and typed next/previous frame fields. Preserved the exact `0xd90` natural layout, every unrelated method and field, and the class-closing `};` before `[[CHILDREN]]`.

- 2026-07-14 Agent-B002 UID0003RB callback: preserved the complete executed B004 union, added `ButtonId` and `ButtonVisualState`, corrected OnPaint/DrawStatText/GetButtonRect declarations to the exact void/argument contracts, and synchronized the full paint/stat/button/resource/vtable/compiler-exclusion evidence without changing the `0xd90` layout or packet source.

- 2026-07-14 Agent-B004 UID00039M callback: raised `93/94 -> 94/94`; preserved the complete `0xd90` layout and class-closing `};` before `[[CHILDREN]]`; added the five update-helper and DispatchSpelledText declarations; replaced stale `LivingSpriteConfig m_spriteConfig` with exact `ObjectStatusBlob m_objectStatus`; synchronized UID0003RE/UID00039M/UID0004Q0-UID0004Q4/UID00039N behavior, liveness, compiler exclusions, source route, negative evidence, rejected alternatives, and lexical confidence caps without altering unrelated methods or fields.

- 2026-07-14 Agent-B003 UID0003R9 callback: preserved `93/94`, owner/emitter UID0000NL, reconstructable state, blank position, complete managed `0xd90` class declaration, every unrelated declaration/evidence/history item, and the class-closing `};` before `[[CHILDREN]]`. Expanded only the ShowSpelledView summary/method/evidence with exact range/hash/void ABI, mode/field/detach/geometry/scroll/layer/order/wide-text/selection/sync/recenter/invalidation behavior, four calls in three class methods, hidden-result TextEdit dependency, exhaustive negatives, source/name/access caps, and child-only emission; no duplicate body or declaration was added.

- 2026-07-14 Agent-B003 UID0003R8 callback: preserved `93/94`, owner/emitter UID0000NL, reconstructable state, blank position, complete managed class declaration, exact `0xd90` layout, public first-draft access convention, and class closure before `[[CHILDREN]]`. Expanded only the ShowDefaultView method/evidence/summary with the exact void ABI, mode-0 write, Legend-then-Spelled detach/unregister order, retained `(17,192,174,251)` dead-local initialization, final inherited-bounds invalidation, two direct callers, formal-child route, exhaustive negatives, source/name/access caps, and unchanged score rationale; no duplicate declaration or method body was added.

- 2026-07-14 Agent-B003 UID0003RC callback: raised `92/93` to `93/94`; replaced only the stale `HandleKeyEvent(const PanelKeyEvent *)` virtual with exact R2 `HandleKeyOrTextEvent(Event *)`, preserving the complete `0xd90` declaration byte-for-byte otherwise and keeping the class closing `};` before `[[CHILDREN]]`. Added the secondary `+0x08` vtable route, Event offsets/type, bool/retn4 ABI, facet-to-complete lowering, EventMan translator order, raw key values/source names, exact transition/consumed-no-call matrix, negative evidence, source/access rationale, range/hash/padding context, and historical name rejection. Owner/emitter UID0000NL, blank position, reconstructable state, every unrelated method/raw helper, and source/compiler history remain unchanged.

- 2026-07-14 Agent-B003 UID0003RA callback: preserved `92/93`, owner/emitter UID0000NL, reconstructable state, blank position, complete managed class declaration, exact `0xd90` layout, public first-draft access convention, and class closure before `[[CHILDREN]]`. Expanded only the ShowLegendView method/evidence/summary with the exact void ABI, mode/field/detach/geometry/scroll/layer/order/invalidation contract, three direct callers, formal-child route, lexical-access cap, and negative evidence; no duplicate declaration or method body was added.

- 2026-07-14 Agent-B003 UID0003QZ callback: raised `89/91` to `92/93`; replaced the partial B011 skeleton with exact R2, including `OnActivate`, `ViewMode`, complete `0xd90` natural field layout, ProfilePane pointer and retained raw helper, exact access model, and class closure before `[[CHILDREN]]`. Historicalized the OnDraw/blank-blocker model while preserving all existing children, helper islands, raw/no-route evidence, destructor links, source route, and compiler exclusions.

- 2026-07-01 B011 empty-emitter family implementation: Raised from `88/90` to `89/91`.
  - Inserted first-draft formal `SelfLookPane2` declaration skeleton into the formal C++ block.
  - Preserved exact child split and raw-helper caveats while historicalizing the old blank-C++ rationale: unresolved original field/helper names remain score caps, not empty-emitter blockers.

- 2026-06-16 B001 SelfLookPane2 split execution: Raised from `87/85` to `88/90`.
  - What changed: added exact main-span split summary for [UID:0001HK][0x0056fe80-0x005729c3.SelfLookPane2](by-memory/0x0056fe80-0x005729c3.SelfLookPane2.md), linked child pages [UID:0003QX][0x0056fe80-0x0057002c.SelfLookPane2Constructor](by-memory/0x0056fe80-0x0057002c.SelfLookPane2Constructor.md)-[UID:0003RH][0x005728a0-0x005729c3.SelfLookPane2HitTestButton](by-memory/0x005728a0-0x005729c3.SelfLookPane2HitTestButton.md), recorded the non-emitting parent disposition, and updated the ignored hit-test tail boundary.
  - Evidence: B001 source-split report `tools/leaser/Agents/Agent-B001/research/0001HK-selflookpane2-source-split-audit.md`, live IDA method/xref/vtable evidence, raw-byte checks, local PE scans, and existing SelfLookPane/SelfLookPane2/child-pane documentation.

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Evidence: the page documents the panel purpose, mode-switching behavior, main constructor/destructor/draw/input/stat/button ranges, helper islands, and cross-references; confidence remains capped by projected method starts around `0x00570940-0x00570ac0` that IDA does not currently model as functions.
- Before: the post-`SelfLookPane2` helper area was listed only as loose `0x00572f30` / `0x00572fd0` notes while the coverage report still treated `0x005729c3-0x00573240` as unknown.
- Changed to: the helper island is documented as [UID:00023X][0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers](by-memory/0x005729e0-0x00573232.LookPanePacketAndEntryVectorHelpers.md), with the destructor body linked through [UID:000240][0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers](by-memory/0x00573570-0x0057399e.LookGroupSpelledDestructorVectorHelpers.md).
- Evidence: 2026-05-28 IDA MCP disassembly showed raw packet/update helper starts at `0x005729e0`, `0x00572a60`, `0x00572ae0`, and `0x00572b60`, plus IDA functions at `0x00572f30`, `0x00572fd0`, and `0x00573640`.
- 2026-06-01: Raised from `84/78` to `86/82`, marked reconstructable, and attached to [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md).
  - Historical note superseded by B011 on 2026-07-01: final helper/field names and raw helper boundary normalization remain score caps, but the class page now carries a first-draft formal declaration skeleton.
- 2026-06-11 Agent-A001 Batch 186 follow-up: Raised from `86/82` to `87/85`.
  - What changed: propagated the exact [UID:00039L][0x005729e0-0x00572b54.SelfLookPane2PacketSendRawHelpers](by-memory/0x005729e0-0x00572b54.SelfLookPane2PacketSendRawHelpers.md), [UID:00039M][0x00572b60-0x00572f25.SelfLookPane2LookUpdateRawHelpers](by-memory/0x00572b60-0x00572f25.SelfLookPane2LookUpdateRawHelpers.md), and [UID:00039N][0x00572f30-0x00572fcf.SelfLookPane2SpelledEntryDispatch](by-memory/0x00572f30-0x00572fcf.SelfLookPane2SpelledEntryDispatch.md) children into the class page and rechecked the live IDA function/xref/vtable/destructor evidence.
  - Evidence: live IDA MCP `lookup_funcs`, `xrefs_to`, `callers`, `callees`, `disasm`, and `decompile`; [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md) is now `85/89`, so this class and its direct file parent both clear the strict gate.
- 2026-06-12 A004 Batch 247: Score unchanged at `87/85`.
  - What changed: updated the scalar deleting destructor method row and cross-reference to exact child [UID:00039E][0x00573640-0x00573728.SelfLookPane2ScalarDeletingDestructor](by-memory/0x00573640-0x00573728.SelfLookPane2ScalarDeletingDestructor.md), which is now assigned here after reaching `88/92`.
  - Evidence: live IDA MCP reconfirmed the destructor wrapper boundary, vtable/thunk refs, `SelfLookPane2` vtable stores, child cleanup offsets, and shared cleanup/delete calls.
