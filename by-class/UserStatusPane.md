*** UID:0000FS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
struct RectBounds;

class UserStatusPane : public Pane
{
public:
    explicit UserStatusPane(const wchar_t *displayName);
    virtual ~UserStatusPane();

    errno_t CopyNameLineA(wchar_t *destination, size_t capacity) const;
    errno_t CopyNameLineB(wchar_t *destination, size_t capacity) const;
    unsigned char GetPercentStatA() const;
    unsigned char GetPercentStatB() const;
    unsigned char GetPercentStatC() const;
    unsigned char GetNationId() const;
    signed char GetSpiritId() const;
    int GetSpiritIdValue() const;
    unsigned int GetDisplayValueA() const;
    unsigned int GetDisplayValueB() const;
    unsigned int GetDisplayValueC() const;
    void SetDisplayLineA(const wchar_t *text);
    void SetDisplayLineB(const wchar_t *text);
    void SetStatusIconId(unsigned char iconId);

protected:
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual void OnPaint();

private:
    void InvalidateStatusFieldRect(int fieldId);
    void GetStatusFieldRect(int fieldId, RectBounds *bounds) const;
    void DrawNumberGlyphString(const wchar_t *text, int x, int y, int glyphRow);
    bool ApplyLegacyPositionPacket(const unsigned char *packet);
    bool ApplyLegacyMovementStep(const unsigned char *packet);
    bool ApplyLegacyMovementStepAlt(const unsigned char *packet);
    bool ApplyStatusPayload(const unsigned char *packet);

    unsigned char *m_numberGlyphs;
    wchar_t m_nameLine[64];
    wchar_t m_displayLineA[64];
    wchar_t m_secondaryLine[64];
    unsigned short m_nationId;
    signed char m_spiritId;
    unsigned char m_statusIconId;
    unsigned char m_classId;
    unsigned char m_percentStatA;
    unsigned char m_percentStatB;
    unsigned char m_percentStatC;
    unsigned char m_inventorySlotCount;
    unsigned char m_padding285[3];
    unsigned int m_statusRow8PartialValue;
    unsigned int m_statusRow8FullValue;
    unsigned int m_statusRow9PartialValue;
    unsigned int m_statusRow9FullValue;
    unsigned int m_statusRow10Value;
    unsigned int m_statusRow11Value;
    int m_positionX;
    int m_positionY;
    unsigned short m_epfStatusTailWord0;
    unsigned short m_epfStatusTailWord1;
};

extern UserStatusPane *g_activeUserStatusPane;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# UserStatusPane

## Status

- Current source-quality state: `92/94`; complete `0x2ac` layout, virtual/private API, source route, child ownership, singleton lifecycle, and destination-ready declaration.
- Likely source file: [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- Autogen parent: [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md). Assignment gate is met after the A005 Batch 059 parent refresh: this class is `88/88`, the direct file parent is `88/85`, and the file page directly lists this class as the newer status summary pane.
- Main address range: [UID:0001NM][0x005b83b0-0x005baafe.UserStatusPane](by-memory/0x005b83b0-0x005baafe.UserStatusPane.md)
- Shared destructor/thunk tail: [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md)
- Singleton: [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md) at `0x0069ae0c`
- Current recovered source: `source-3/simroot_v2/class_UserStatusPane.cpp`

## Class Purpose

`UserStatusPane` is the newer local player status summary pane. It displays the character name/title text, nation/totem/class icons, selected status icon, level/stat values, bar values, pair values, and tooltip help zones. It is constructed by `InitializeMainUiGraph` in the newer UI layout.

## Method Map

| Address | Method / family | Role |
| --- | --- | --- |
| [UID:0003A8][0x005b83b0-0x005b8526.UserStatusPaneConstructor](by-memory/0x005b83b0-0x005b8526.UserStatusPaneConstructor.md) | `UserStatusPane::UserStatusPane` | Constructs the pane, stores the singleton, installs vtables, loads `9X11FONT.BIN`, and initializes display fields. |
| [UID:0003A9][0x005b8530-0x005b85ad.UserStatusPaneDestructor](by-memory/0x005b8530-0x005b85ad.UserStatusPaneDestructor.md) | `~UserStatusPane` | Frees the font table and clears the singleton; compiler lowering performs base teardown and wrappers. |
| [UID:0001NN][0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md) | text/status accessors and setters | Copies title/secondary strings, returns status-byte fields, sets text fields, and invalidates. Active output only emits part of this family. |
| [UID:0002LP][0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId](by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md) | `SetStatusIconId` | Writes byte offset `+0x27f` and calls the summary refresh sink at subobject offset `+0x44`. |
| [UID:0004T3][0x005b86d0-0x005b86d8.UserStatusPaneGetSpiritIdValue](by-memory/0x005b86d0-0x005b86d8.UserStatusPaneGetSpiritIdValue.md) | `GetSpiritIdValue` | Retained no-route signed getter at position 40. |
| [UID:0003AA][0x005b8700-0x005b8a0c.UserStatusPaneHandlePacketEvent](by-memory/0x005b8700-0x005b8a0c.UserStatusPaneHandlePacketEvent.md) | `HandlePacketEvent` | Routes EPF and legacy status/position/movement packets. |
| [UID:0003AC][0x005b8a10-0x005b8c6b.UserStatusPaneHandlePointerOrMouseEvent](by-memory/0x005b8a10-0x005b8c6b.UserStatusPaneHandlePointerOrMouseEvent.md) | `HandlePointerOrMouseEvent` | Shows localized help for exact status regions. |
| [UID:0003AE][0x005b8c70-0x005b9d6a.UserStatusPaneOnPaint](by-memory/0x005b8c70-0x005b9d6a.UserStatusPaneOnPaint.md) | `OnPaint` | Draws EPF/legacy backgrounds, text, icons, bars, and numeric values. |
| [UID:0004T4][0x005b9d70-0x005b9dab.UserStatusPaneInvalidateStatusFieldRect](by-memory/0x005b9d70-0x005b9dab.UserStatusPaneInvalidateStatusFieldRect.md) | `InvalidateStatusFieldRect` | Private field-geometry invalidation wrapper. |
| [UID:0003AD][0x005b9db0-0x005ba017.UserStatusPaneGetStatusFieldRect](by-memory/0x005b9db0-0x005ba017.UserStatusPaneGetStatusFieldRect.md) | `GetStatusFieldRect` | Maps exact EPF/legacy field ids to rectangles. |
| [UID:0003AF][0x005ba020-0x005ba0f1.UserStatusPaneDrawNumberGlyphString](by-memory/0x005ba020-0x005ba0f1.UserStatusPaneDrawNumberGlyphString.md) | `DrawNumberGlyphString` | Draws 9x11 bitmap-font text. |
| [UID:0004T5][0x005ba100-0x005ba19c.UserStatusPaneApplyLegacyPositionPacket](by-memory/0x005ba100-0x005ba19c.UserStatusPaneApplyLegacyPositionPacket.md) | `ApplyLegacyPositionPacket` | Retained legacy position helper. |
| [UID:0004T6][0x005ba1a0-0x005ba31c.UserStatusPaneApplyLegacyMovementStep](by-memory/0x005ba1a0-0x005ba31c.UserStatusPaneApplyLegacyMovementStep.md) | `ApplyLegacyMovementStep` | Retained legacy direction-step helper. |
| [UID:0004T7][0x005ba320-0x005ba49c.UserStatusPaneApplyLegacyMovementStepAlt](by-memory/0x005ba320-0x005ba49c.UserStatusPaneApplyLegacyMovementStepAlt.md) | `ApplyLegacyMovementStepAlt` | Independent retained alternate movement helper. |
| [UID:0003AB][0x005ba4a0-0x005baafe.UserStatusPaneApplyStatusPayload](by-memory/0x005ba4a0-0x005baafe.UserStatusPaneApplyStatusPayload.md) | `ApplyStatusPayload` | Applies exact EPF/legacy status fields and external pane effects. |
| `0x005bfc00`, `0x005bfc63`, `0x005bfc6e`, `0x005bff20` | shared tail helpers | Singleton clear helper, destructor adjustor thunks, and scalar deleting destructor. |

## Field Evidence

- `0x005b8620` returns byte offset `+0x27c`, the newer nation id.
- `0x005b8630` returns byte offset `+0x27e`, the newer spirit/totem id.
- `+0x284` is initialized to `52` in the constructor and is read by inventory/item command panes as the maximum valid item-slot selector for the active local user.
- `0x005b8640`, `0x005b8650`, and `0x005b8660` return 32-bit values at offsets `+0x28c`, `+0x294`, and `+0x298`.
- `0x005ba4a0` uses bit flags in the status packet to decide which fields are present and which rectangles to invalidate.
- See [UID:0001WF][UserStatusPaneSummaryFields](by-type/by-struct/UserStatusPaneSummaryFields.md) for the full field slice currently emitted as generated [UID:00001N][CharacterSummaryRecord](by-class/CharacterSummaryRecord.md).

## Evidence Notes

- IDA callers show construction from `InitializeMainUiGraph` at `0x004f837a`.
- IDA xrefs show constructor writes and cleanup/scalar destructor clears [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md).
- The update handler at `0x005ba4a0` references [UID:0000SK][g_pTotemFrame](by-global/g_pTotemFrame.md): it invalidates an existing frame or constructs [UID:0000F4][TotemFrame](by-class/TotemFrame.md).
- Active generated output omits `0x005b8700`, `0x005b9db0`, `0x005ba4a0`, and the shared tail helpers.
- Active generated output also splits `0x005b85b0-0x005b86ca` into `class_CharacterSummaryRecord.cpp`; this is a generated pseudo-class over the `UserStatusPane` object tail.
- 2026-06-20 B004 local PE recheck confirms [UID:00001N][CharacterSummaryRecord](by-class/CharacterSummaryRecord.md) is a non-standalone generated alias: accessor callers pass [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md) itself as `ecx`, the generated pseudo-class omits real getter `0x005b8660`, adjacent raw `0x005b86d0` is only a no-xref signed `+0x27e` getter caveat, and there is no constructor/vtable/allocation/type route for a separate class.
- 2026-05-31 IDA MCP recheck of the constructor, summary accessor island, status-icon setter, status-payload updater, and final boundary before `UserStatusPane2` supports treating the class as NexusTK-owned reconstructable source.
- 2026-06-07 A005 Batch 059 parent-gate repair attached this class to [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md) after the file parent reached `88/85`.
- 2026-06-30 B009 adds a formal class-shell C++ block with `[[CHILDREN]]`. The class shell is a source reconstruction scaffold: field and helper names such as `m_nameLine`, `m_secondaryLine`, `m_displayLineA`, `m_inventorySlotCount`, `HandleStatusPacketEvent`, and `InvalidateSummaryText` are source-facing inference, while exact method bodies remain on child pages.
- 2026-06-11 A001 Batch198 split the main memory aggregate's previously summarized constructor, cleanup, router, hover help, paint, status-rect lookup, glyph draw, and payload apply methods into exact child pages and raised [UID:0001NM][0x005b83b0-0x005baafe.UserStatusPane](by-memory/0x005b83b0-0x005baafe.UserStatusPane.md) to `86/90` under this `88/88` class parent.

## B009 Source-Emission Decision

The accepted B009 callback converts this class from a blank emitter into the declaration shell for the newer status pane. The formal block intentionally contains declarations, inferred field names, the `g_activeUserStatusPane` extern, and `[[CHILDREN]]`; it does not paste broad child method bodies into the class page. Exact body pages [UID:0003A8][0x005b83b0-0x005b8526.UserStatusPaneConstructor](by-memory/0x005b83b0-0x005b8526.UserStatusPaneConstructor.md)-[UID:0003AF][0x005ba020-0x005ba0f1.UserStatusPaneDrawNumberGlyphString](by-memory/0x005ba020-0x005ba0f1.UserStatusPaneDrawNumberGlyphString.md), [UID:0001NN][0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md), and [UID:0002LP][0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId](by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md) remain responsible for method-body emission.

`UserStatusPaneSummaryFields` is layout support only after B009, not a standalone `CharacterSummaryRecord` type. The layout offsets remain evidence for this class's fields, but the type page does not emit source C++.

## Cross-References

- [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- [UID:0001NM][0x005b83b0-0x005baafe.UserStatusPane](by-memory/0x005b83b0-0x005baafe.UserStatusPane.md)
- [UID:0003A8][0x005b83b0-0x005b8526.UserStatusPaneConstructor](by-memory/0x005b83b0-0x005b8526.UserStatusPaneConstructor.md)
- [UID:0003A9][0x005b8530-0x005b85ad.UserStatusPaneDestructor](by-memory/0x005b8530-0x005b85ad.UserStatusPaneDestructor.md)
- [UID:0001NN][0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md)
- [UID:0002LP][0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId](by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md)
- [UID:0003AA][0x005b8700-0x005b8a0c.UserStatusPaneHandlePacketEvent](by-memory/0x005b8700-0x005b8a0c.UserStatusPaneHandlePacketEvent.md)
- [UID:0003AC][0x005b8a10-0x005b8c6b.UserStatusPaneHandlePointerOrMouseEvent](by-memory/0x005b8a10-0x005b8c6b.UserStatusPaneHandlePointerOrMouseEvent.md)
- [UID:0003AE][0x005b8c70-0x005b9d6a.UserStatusPaneOnPaint](by-memory/0x005b8c70-0x005b9d6a.UserStatusPaneOnPaint.md)
- [UID:0003AD][0x005b9db0-0x005ba017.UserStatusPaneGetStatusFieldRect](by-memory/0x005b9db0-0x005ba017.UserStatusPaneGetStatusFieldRect.md)
- [UID:0003AF][0x005ba020-0x005ba0f1.UserStatusPaneDrawNumberGlyphString](by-memory/0x005ba020-0x005ba0f1.UserStatusPaneDrawNumberGlyphString.md)
- [UID:0003AB][0x005ba4a0-0x005baafe.UserStatusPaneApplyStatusPayload](by-memory/0x005ba4a0-0x005baafe.UserStatusPaneApplyStatusPayload.md)
- [UID:0001WF][UserStatusPaneSummaryFields](by-type/by-struct/UserStatusPaneSummaryFields.md)
- [UID:0001RS][user-status-resources](by-resource/user-status-resources.md)
- [UID:0000F4][TotemFrame](by-class/TotemFrame.md)

## Changes

- 2026-07-20 B001 UID0001NM callback:
  - Raised to `92/94` and replaced the prior provisional declaration with the accepted complete `0x2ac` UserStatusPane source shape, exact virtual/private API, final field types/names, singleton extern, and preserved `[[CHILDREN]]` insertion point.
  - Incorporated all fifteen ordered children including real validator UIDs 0004T3-0004T7, rejected standalone CharacterSummaryRecord ownership, and historicalized phantom helper/provisional field aliases without deleting earlier provenance.
- 2026-06-30 B009 implementation callback:
  - Added formal class-shell C++ with `[[CHILDREN]]`.
  - Summary/evidence: accepted B009 empty-emitter report supplied MCP-backed class/source-file disposition, B004 `CharacterSummaryRecord` rejection, inferred field/helper names, and child-body routing. This class emits the declaration scaffold while exact child pages own method bodies.
- 2026-06-11 A001 Batch198 class-map child split:
  - What existed before: this class page listed several large UserStatusPane methods only as bare address ranges while [UID:0001NM][0x005b83b0-0x005baafe.UserStatusPane](by-memory/0x005b83b0-0x005baafe.UserStatusPane.md) remained below the child side of the corrected gate.
  - Changed to: linked exact child pages for constructor, cleanup, packet/movement router, hover help, paint, status-rect lookup, glyph draw, and status-payload apply.
  - Summary/evidence: live IDA MCP reconfirmed boundaries, virtual/data refs, glyph helper callsites, and payload updater caller; the main aggregate is now `86/90` and assigned to this `88/88` class parent.
- 2026-06-07 A005 Batch 059 parent-gate repair:
  - What existed before: `AUTOGEN_PARENT_UID` was blank, so class-owned memory children routed to `0000FS` produced generated memory coverage `autogen_parent_unknown` rows.
  - Changed to: `AUTOGEN_PARENT_UID:0000P2`.
  - Summary/evidence: [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md) was refreshed to `88/85`; this class is `88/88`; the file page directly owns the newer status summary pane alongside `UserStatusPane2` and legacy status variants. At that time final C++ remained blank because the broad class, large child methods, and high-fanout field names still needed source-quality integration; B009 later superseded this with a formal class-shell block while preserving the generated `CharacterSummaryRecord` rejection.
- 2026-06-07 A006 Batch 060 validator-state repair:
  - What existed before: generated memory autogen coverage reported `AUTOGEN_PARENT_UID:0000FS` as unknown for the exact [UID:0002LP][0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId](by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md) child, even though this class page already has UID `0000FS` and scores `88/88`.
  - Changed to: no score or ownership change; this page was revalidated as the direct parent for the status-icon setter.
  - Summary/evidence: the class method map and field evidence already include the `SetStatusIconId` child, so the repair is validator-state registration rather than a parent reroute.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:88`.
  - Summary/evidence: scored from the constructor/cleanup/accessor/router/paint/rect/glyph/status-payload method map, singleton/global evidence, field offsets, resource links, TotemFrame interaction, and generated-output caveats.
- 2026-05-31 reconstructable flag:
  - What existed before: blank `RECONSTRUCTABLE`.
  - Changed to: `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP confirms the class constructor, methods, singleton storage, field accessors, payload updater, and neighboring `UserStatusPane2` boundary as source-owned NexusTK UI code.
