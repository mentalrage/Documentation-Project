*** UID:00009U | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class OldUserStatusPane : public Pane
{
public:
    explicit OldUserStatusPane(const wchar_t *displayName);
    virtual ~OldUserStatusPane();

    unsigned char GetNationId() const;
    signed char GetSpiritId() const;
    void SetStatusIconId(unsigned char iconId);

    void InvalidateStatusFieldRect(int fieldId);
    void GetStatusFieldRect(int fieldId, RectBounds *bounds);
    void DrawNumberGlyphString(const wchar_t *text, int x, int y, int glyphRow);
    bool ApplyLegacyPositionPacket(const unsigned char *packet);
    bool ApplyLegacyMovementStep(const unsigned char *packet);
    bool ApplyLegacyMovementStepAlt(const unsigned char *packet);
    bool ApplyLegacyStatusPayload(const unsigned char *packet);

private:
    void *m_numberGlyphs;
    wchar_t m_displayName[16];
    unsigned short m_nationId;
    signed char m_spiritId;
    unsigned char m_statusIconId;
    unsigned char m_classId;
    unsigned char m_attributeLeft;
    unsigned char m_attributeCenter;
    unsigned char m_attributeRight;
    unsigned int m_statusRow8PartialValue;
    unsigned int m_statusRow8FullValue;
    unsigned int m_statusRow9PartialValue;
    unsigned int m_statusRow9FullValue;
    unsigned int m_statusRow10Value;
    unsigned int m_statusRow11Value;
    int m_positionX;
    int m_positionY;
    unsigned short m_legacyStatusTailWord0;
    unsigned short m_legacyStatusTailWord1;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# OldUserStatusPane

## Status

- Confidence: strong for role, method boundaries, singleton lifecycle, vtable identity, status-resource ownership, retained helper disposition, and source route.
- Likely source file: [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- Main aggregate: [UID:0001NR][0x005bda40-0x005bfbc1.OldUserStatusPane](by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md)
- Shared destructor/thunk tail: [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md)
- Vtable data: [UID:0002Z3][0x00630e58-0x00630edc.OldUserStatusPaneVtableData](by-memory/0x00630e58-0x00630edc.OldUserStatusPaneVtableData.md)
- Singleton: [UID:0000RV][g_pOldUserStatusPane](by-global/g_pOldUserStatusPane.md) at `0x0069b4ec`
- Current generated output: before the B004 UID00049B callback, `auto-generated/NexusTK/ui/panels/UserStatusPane.cpp` header `validator-command-id: 000000007773` still contained the stale UID00049B status-payload body; scoped callback validation refreshed the generated source to emit the UID00049B bool body. Treat generated output as lead material.

## Class Purpose

`OldUserStatusPane` is the legacy local player status pane used by the older UI layout. It paints the `USERSTAT.EPD` panel, draws nation/totem/class icons and bars, provides legacy hover help zones, and applies the old status-packet payload format. It belongs in [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md) with the newer `UserStatusPane` variants because all three share UI construction, status resources, glyph-table usage, singleton state, packet-update patterns, and status HUD ownership.

## Method Map

| Address | Method / family | Role |
| --- | --- | --- |
| `0x005bda40-0x005bdb63` | `OldUserStatusPane::OldUserStatusPane` | Constructs the pane, stores the singleton, installs vtables, loads `9X11FONT.BIN`, copies the display name, and initializes legacy display fields. |
| `0x005bdb70-0x005bdbed` | cleanup body | Frees the glyph table, clears the singleton, and calls pane-base cleanup. |
| `0x005bdc30-0x005bdc88` | accessors and `SetStatusIconId` | Returns nation/spirit fields and writes the top-row status icon id at offset `+0x13f`. |
| `0x005bdcb0-0x005bdf3c` | packet/movement router | Handles legacy position, status payload, and movement packet opcodes. |
| `0x005bdfa0-0x005be51e` | `OnMouseMove` | Handles legacy status hover zones and creates help panes with localized ids. |
| `0x005be520-0x005bf10d` | `OnPaint` | Draws `USERSTAT.EPD`, `NATION.EPD`, `TOTEM.EPD`, `CLASS.EPD`, bars, numbers, and status text. |
| `0x005bf110-0x005bf14b` | `InvalidateStatusFieldRect` | Retained no-entry wrapper that looks up and invalidates a status field rectangle. |
| `0x005bf150-0x005bf3b0` | `GetStatusFieldRect` | Maps legacy field ids to dirty/help rectangles; owns the `0x005bf374-0x005bf3b0` switch jump-table tail. |
| `0x005bf3b0-0x005bf481` | `DrawNumberGlyphString` | Draws numbers with the loaded 9x11 font table. |
| `0x005bf490-0x005bf51a` | `ApplyLegacyPositionPacket` | Exact 138-byte retained private helper: reads signed BE16 x/y at packet `+1/+3`, updates `m_positionX/m_positionY` only on change, invalidates field `12`, and returns `false`; its live router call is inlined. |
| `0x005bf520-0x005bf670` | `ApplyLegacyMovementStep` | Retained no-entry movement helper; owns the internal `0x005bf660-0x005bf670` jump table. |
| `0x005bf670-0x005bf7c0` | `ApplyLegacyMovementStepAlt` | Retained no-entry movement helper variant; owns the internal `0x005bf7b0-0x005bf7c0` jump table. |
| `0x005bf7c0-0x005bfbc1` | `ApplyLegacyStatusPayload` | Parses bitflagged status payloads, returns `false` to router case `8`, updates legacy fields with cursor-based packet offsets, invalidates rectangles, and creates/invalidates `TotemFrame` when spirit changes. |
| `0x005bfbe0`, `0x005bfc37`, `0x005bfc42`, `0x005bfda0` | shared tail helpers | Singleton clear helper, destructor adjustor thunks, and scalar deleting destructor in [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md). |

## Field Evidence

| Field / offset | Source-facing role | Evidence |
| --- | --- | --- |
| `+0xf8` | `m_numberGlyphs` | Constructor loads `9X11FONT.BIN`; cleanup frees it; `DrawNumberGlyphString` indexes it. |
| `+0xfc` | `m_displayName[16]` | Constructor copies a 16-wide-character display label; paint draws the title/name area. |
| `+0x13c` | `m_nationId` | Stored as an unsigned 16-bit field by UID00049B, while accessor `0x005bdc30` returns the low byte with `mov al,[ecx+13Ch]`; UserListDialog caller and nation resource painting still consume the low-byte view. |
| `+0x13e` | `m_spiritId` | Accessor `0x005bdc60`, `TotemFrame::OnPaint` caller, and `TOTEM.EPD`/`TOTFRAME.EPD` frame selection. |
| `+0x13f` | `m_statusIconId` | Setter `0x005bdc70`, LivingObjectPane caller, and top status-icon invalidation. |
| `+0x140` | `m_classId` | Payload updates this byte and invalidates `(160,3,190,15)`. |
| `+0x141`, `+0x142`, `+0x143` | `m_attributeLeft`, `m_attributeCenter`, `m_attributeRight` | Payload updates three compact old-status attribute/icon bytes and invalidates the three small status rectangles. |
| `+0x144`, `+0x148`, `+0x14c`, `+0x150`, `+0x154`, `+0x158` | descriptive/inferred status rows: `m_statusRow8PartialValue`, `m_statusRow8FullValue`, `m_statusRow9PartialValue`, `m_statusRow9FullValue`, `m_statusRow10Value`, `m_statusRow11Value` | UID00049B current MCP proves the order: `flags & 0x20` cursor reads update `+0x144` and `+0x14c`; `flags & 0x40` full-status reads update `+0x148` and `+0x150`; `flags & 0x10` cursor reads update `+0x154` and `+0x158`. Names are descriptive/inferred, not original-name proof. |
| `+0x15c`, `+0x160` | `m_positionX`, `m_positionY` | Router and raw helpers update big-endian packet coordinates and invalidate status field id `12`. |
| `+0x164`, `+0x166` | `m_legacyStatusTailWord0`, `m_legacyStatusTailWord1` | UID00049B full-status path stores `PacketBufferReadUInt16BE(packet+26)` and `PacketBufferReadUInt16BE(packet+28)` here before setting cursor `31`. Constructor/paint/hover field filters did not find a stronger semantic name, so these names remain descriptive/inferred. |

Field order and packing in the declaration-level formal C++ are inferred from offsets and accepted report evidence. The page should not be scored above final-audit thresholds until inherited layout and all old-status row names are fully reconciled.

## Source Split And Emission Notes

The class page emits only declaration-level C++ with `[[CHILDREN]]`. It should not contain method/helper bodies. Exact bodies are emitted through child by-memory pages under [UID:0001NR][0x005bda40-0x005bfbc1.OldUserStatusPane](by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md). The accepted B002 split creates or routes:

- [UID:000495][0x005bf110-0x005bf14b.OldUserStatusPaneInvalidateStatusFieldRect](by-memory/0x005bf110-0x005bf14b.OldUserStatusPaneInvalidateStatusFieldRect.md) `InvalidateStatusFieldRect`
- [UID:000496][0x005bf150-0x005bf3b0.OldUserStatusPaneStatusFieldRectLookup](by-memory/0x005bf150-0x005bf3b0.OldUserStatusPaneStatusFieldRectLookup.md) `GetStatusFieldRect`
- [UID:000497][0x005bf3b0-0x005bf481.OldUserStatusPaneDrawNumberGlyphString](by-memory/0x005bf3b0-0x005bf481.OldUserStatusPaneDrawNumberGlyphString.md) `DrawNumberGlyphString`
- [UID:000498][0x005bf490-0x005bf51a.OldUserStatusPaneApplyLegacyPositionPacket](by-memory/0x005bf490-0x005bf51a.OldUserStatusPaneApplyLegacyPositionPacket.md) `ApplyLegacyPositionPacket`
- [UID:000499][0x005bf520-0x005bf670.OldUserStatusPaneApplyLegacyMovementStep](by-memory/0x005bf520-0x005bf670.OldUserStatusPaneApplyLegacyMovementStep.md) `ApplyLegacyMovementStep`
- [UID:00049A][0x005bf670-0x005bf7c0.OldUserStatusPaneApplyLegacyMovementStepAlt](by-memory/0x005bf670-0x005bf7c0.OldUserStatusPaneApplyLegacyMovementStepAlt.md) `ApplyLegacyMovementStepAlt`
- [UID:00049B][0x005bf7c0-0x005bfbc1.OldUserStatusPaneApplyLegacyStatusPayload](by-memory/0x005bf7c0-0x005bfbc1.OldUserStatusPaneApplyLegacyStatusPayload.md) `ApplyLegacyStatusPayload`

The support names used by those body blocks are source-facing inferred names: `RectBounds`, `InitRectBounds`, `ReadPacketInt16BE`, `ReadPacketUInt32BE`, `PacketBufferReadUInt16BE`, `PacketBufferReadUInt32BE`, `RenderTileFrame`, `GetLegacyMovementBounds`, `ShouldMaskLegacyMovementDirection`, `g_pTotemFrame`, `g_activeMapPane`, and `g_pConfig`. Use the `PacketBufferReadUInt16BE`/`PacketBufferReadUInt32BE` names for UID00049B unsigned status-payload scalar reads; the signed coordinate aliases remain local to position/movement helpers. IDA labels remain evidence only.

## Evidence Notes

- IDA callers show construction from `InitializeMainUiGraph` at `0x004f8951`.
- `TotemFrame::OnPaint` reads [UID:0000RV][g_pOldUserStatusPane](by-global/g_pOldUserStatusPane.md) and calls `OldUserStatusPane::GetSpiritId` at `0x005bdc60`.
- `LivingObjectPane::HandleServerEntryPacket` calls `OldUserStatusPane::SetStatusIconId` at `0x005aaed8`.
- Accepted B002 MCP pass rechecked modeled and raw ranges through session `b001_000241_20260627`, including raw no-entry helpers at `0x005bf110`, `0x005bf490`, `0x005bf520`, and `0x005bf670`.
- The raw helper entries have no external code/data refs, but are valid source-shaped OldUserStatusPane helper bodies and no longer remain unnamed blockers.
- B007 current MCP session `supervisor-nexustk-20260707` rechecked UID000499/UID00049A movement helpers: their formal C++ uses current config pointer name `g_pConfig`, the active-map/config high-bit gate returns `false` for nonnegative directions when active and clears the high bit for negative directions, and field id `12` position invalidation remains supported by UID000496 rectangle `(101,82,192,94)`.
- B004 UID00049B current MCP session `supervisor-nexustk-20260707` rechecked `ApplyLegacyStatusPayload`: `0x005bf7c0` is modeled `sub_5BF7C0` size `0x401`, router case `8` calls/returns it from `0x005bdf24`, target tail returns `false`, `0x005bfbc1-0x005bfbd0` is padding, and the full-status path stores `packet+26/+28` into `+0x164/+0x166`.
- Active generated output was stale for UID00049B before this callback. The old malformed constructor text with literal `` `n`n`` is historical generated pollution, not source evidence.
- The corrected vtable child [UID:0002Z3][0x00630e58-0x00630edc.OldUserStatusPaneVtableData](by-memory/0x00630e58-0x00630edc.OldUserStatusPaneVtableData.md) ends at `0x00630edc`; full UTF-16 `USERSTAT.EPF` starts there.

## UID000498 Direct Method Evidence

- B005 bounded direct reanalysis fixes [UID:000498][0x005bf490-0x005bf51a.OldUserStatusPaneApplyLegacyPositionPacket](by-memory/0x005bf490-0x005bf51a.OldUserStatusPaneApplyLegacyPositionPacket.md) at `[0x005bf490,0x005bf51a)`, 138 bytes, SHA256 `9827B350A771D2CFFFBCF86FDD7A9C7F2661CA0B36DEA51DAE971570E02DC7BD`; the exact end follows `retn 4`, with adjacent `0xcc` pads excluded.
- ABI and field evidence agree with the declaration already emitted here: x86 `thiscall`, one const unsigned-byte packet pointer, bool result, signed coordinate widening, and int fields `m_positionX/m_positionY` at `+0x15c/+0x160`.
- Changed-only behavior stores both coordinates when either differs, maps field id `12` through UID000496 to exact rectangle `(101,82,192,94)`, invokes inherited invalidation, and returns `false` on every path. No packet-length, null, coordinate-range, or malformed-input guard exists.
- Entry/code/data/immediate/full-PE VA/RVA searches are all negative for the raw start. Source retention is nevertheless strongly positive: live Old router opcode `0x04` contains the exact behavior inline, UID000495 independently retains the field-id invalidation wrapper, and the `UserStatusPane`/`UserStatusPane2` classes each retain an analogous no-entry emitted position helper.
- The best source disposition is a private source-authored member whose router call was optimizer-inlined, not padding, compiler output, a free helper, a vtable method, or a covered-by marker. The child can therefore rise to `92/94` without changing this class's `89/91`, inheritance, field layout, method inventory, source route, or declaration-level formal.
- Historical clarification: B002's `86/90` child creation and no-entry evidence remain valid aggregate-split history. This later direct audit supersedes only the earlier evidentiary/score limit; original private spelling remains inferred and continues to cap class confidence.

## Assignment Gate

This class clears the strict direct-parent gate at `89/91` and remains attached to current [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md) at `93/94`. The latest class increase was justified by the accepted B004 UID00049B report repairing the status-payload signature, field widths, status-row order, and tail-word layout in the class declaration. The UID000498 direct audit closes that method's body/liveness evidence without raising the class. The class remains below final-source audit because the full inherited layout and exact historical old-status row labels are still inferred.

## Cross-References

- [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- [UID:0001NR][0x005bda40-0x005bfbc1.OldUserStatusPane](by-memory/0x005bda40-0x005bfbc1.OldUserStatusPane.md)
- [UID:0002Z3][0x00630e58-0x00630edc.OldUserStatusPaneVtableData](by-memory/0x00630e58-0x00630edc.OldUserStatusPaneVtableData.md)
- [UID:0001RS][user-status-resources](by-resource/user-status-resources.md)
- [UID:0000F4][TotemFrame](by-class/TotemFrame.md)

## Changes

- 2026-07-20 B005 UID000498 implementation callback:
  - Scores remain `89/91`; the complete declaration, fields, methods, inheritance, and `[[CHILDREN]]` placement are unchanged byte-for-byte.
  - Added exact UID000498 range/hash, ABI, signed packet reads, changed-only position lifecycle, field-12 rectangle, false return, negative route searches, live-router inline parity, sibling analogs, source disposition, and historical score clarification.
- 2026-07-07 B004 UID00049B implementation callback:
  - Changed scores from `88/90` to `89/91`.
  - Changed `ApplyLegacyStatusPayload` declaration to return `bool`, widened `m_nationId` storage to `unsigned short` while preserving low-byte getter semantics, replaced generic primary/secondary/tertiary row names with descriptive status-row fields in the current MCP-proven order, and added descriptive inferred tail fields `m_legacyStatusTailWord0` / `m_legacyStatusTailWord1`.
  - Summary/evidence: accepted B004 report and current MCP session `supervisor-nexustk-20260707` confirmed router case `8` returns the target result, target returns `false`, full-status `packet+26/+28` stores to `+0x164/+0x166`, `+0x13c` is word-stored by UID00049B but low-byte returned by `GetNationId`, and the UID00049B generated body was stale before callback validation.
- 2026-06-28 B002 accepted implementation callback:
  - What existed before: `85/86`, class route to [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md), blank formal C++, stale generated-output caveat, and unresolved helper/field naming.
  - Changed to: `88/90`, same owner/emitter, declaration-level formal C++ with `[[CHILDREN]]`, complete helper signature list, expanded method map, field roles, raw helper disposition, and stale-generated-output correction.
  - Summary/evidence: accepted B002 report `0001NR-OldUserStatusPane-source-quality.md` used live MCP evidence and current support docs to resolve retained helper, split, field, source-route, and body-emission issues.
- 2026-07-07 B007 accepted implementation callback:
  - Scores remain `88/90`.
  - Summary/evidence: updated OldUserStatusPane support naming and evidence for UID000499/UID00049A movement helpers to use `g_pConfig`, preserve the raw high-bit gate early false return, and tie position invalidation to UID000496 field id `12` rectangle evidence.
- 2026-06-11 A001 Batch 229 parent-gate repair:
  - What existed before: `COMPLETION:82`, `CONFIDENCE:80`; the page had strong class evidence but was below the strict gate for the exact old-status vtable child.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:86`; parent remains [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md), which clears `88/85`.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md) after IDA MCP confirmed the class method/tail starts.
