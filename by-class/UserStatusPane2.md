*** UID:0000FT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
struct RectBounds;

class UserStatusPane2 : public Pane
{
public:
    UserStatusPane2();
    virtual ~UserStatusPane2();

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
    int m_positionX;
    int m_positionY;
    unsigned int m_statusRow0PartialValue;
    unsigned int m_statusRow0FullValue;
    unsigned int m_statusRow1PartialValue;
    unsigned int m_statusRow1FullValue;
    unsigned int m_statusRow2Value;
    unsigned char m_statusRow2Percent;
    unsigned int m_statusRow3Value;
};

extern UserStatusPane2 *g_pUserStatusPane2;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# UserStatusPane2

## Status

- Current score: `93/94`; exact class size/layout, all virtual/private APIs, twelve source children, source/compiler split, singleton/resource dependencies, and generated emission order are documented.
- Likely source file: [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- Main address range: [UID:0001NO][0x005bab00-0x005bc60c.UserStatusPane2](by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md)
- Shared destructor/thunk tail: [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md)
- Singleton: [UID:0000SN][g_pUserStatusPane2](by-global/g_pUserStatusPane2.md) at `0x0069b4e4`
- Historical generated source `source-3/simroot_v2/class_UserStatusPane2.cpp` is discovery evidence only; the current human source declaration is the managed block above.

## Class Purpose

`UserStatusPane2` is the newer compact status-meter pane. It draws `BAR.EPF`/`BAR.PAL` progress bars, comma-separated large numeric values, small fixed-width counters, and uses the same `9X11FONT.BIN` glyph table as the larger status pane.

## Method Map

| UID / exact range | Source member | Role |
| --- | --- | --- |
| [UID:0004TG][0x005bab00-0x005babf7.UserStatusPane2Constructor](by-memory/0x005bab00-0x005babf7.UserStatusPane2Constructor.md) `[0x005bab00,0x005babf7)` | `UserStatusPane2()` | Constructs `Pane(1)`, publishes singleton, initializes fields, loads `9X11FONT.BIN`. |
| [UID:0004TH][0x005bac00-0x005bac7d.UserStatusPane2Destructor](by-memory/0x005bac00-0x005bac7d.UserStatusPane2Destructor.md) `[0x005bac00,0x005bac7d)` | `~UserStatusPane2()` | Frees glyph storage and clears singleton; compiler teardown excluded. |
| [UID:0004TI][0x005bac80-0x005baf64.UserStatusPane2HandlePacketEvent](by-memory/0x005bac80-0x005baf64.UserStatusPane2HandlePacketEvent.md) `[0x005bac80,0x005baf64)` | `HandlePacketEvent(Event *)` | Packet at Event `+0x0c`; opcodes `4/8/0x0b/0x26`; owned switch data. |
| [UID:0004TJ][0x005baf70-0x005baf75.UserStatusPane2HandlePointerOrMouseEvent](by-memory/0x005baf70-0x005baf75.UserStatusPane2HandlePointerOrMouseEvent.md) `[0x005baf70,0x005baf75)` | `HandlePointerOrMouseEvent(Event *)` | Exact false-return pointer/mouse virtual. |
| [UID:0004TK][0x005baf80-0x005bbe15.UserStatusPane2OnPaint](by-memory/0x005baf80-0x005bbe15.UserStatusPane2OnPaint.md) `[0x005baf80,0x005bbe15)` | `OnPaint()` | Three BAR tracks, four grouped numbers, commas, two coordinates, clipping and glyph calls. |
| [UID:0004TL][0x005bbe20-0x005bbe5b.UserStatusPane2InvalidateStatusFieldRect](by-memory/0x005bbe20-0x005bbe5b.UserStatusPane2InvalidateStatusFieldRect.md) `[0x005bbe20,0x005bbe5b)` | `InvalidateStatusFieldRect(int)` | Retained no-entry private invalidator. |
| [UID:0004TM][0x005bbe60-0x005bc008.UserStatusPane2GetStatusFieldRect](by-memory/0x005bbe60-0x005bc008.UserStatusPane2GetStatusFieldRect.md) `[0x005bbe60,0x005bc008)` | `GetStatusFieldRect(int, RectBounds *) const` | Cases 0-8/default plus owned table. |
| [UID:0004TN][0x005bc010-0x005bc0e1.UserStatusPane2DrawNumberGlyphString](by-memory/0x005bc010-0x005bc0e1.UserStatusPane2DrawNumberGlyphString.md) `[0x005bc010,0x005bc0e1)` | `DrawNumberGlyphString(...)` | Exact 9x11 number-glyph loop and index formula. |
| [UID:0004TO][0x005bc0f0-0x005bc177.UserStatusPane2ApplyLegacyPositionPacket](by-memory/0x005bc0f0-0x005bc177.UserStatusPane2ApplyLegacyPositionPacket.md) `[0x005bc0f0,0x005bc177)` | `ApplyLegacyPositionPacket(...)` | Retained signed BE position helper and changed-only field-6 invalidation. |
| [UID:0004TP][0x005bc180-0x005bc2cc.UserStatusPane2ApplyLegacyMovementStep](by-memory/0x005bc180-0x005bc2cc.UserStatusPane2ApplyLegacyMovementStep.md) `[0x005bc180,0x005bc2cc)` | `ApplyLegacyMovementStep(...)` | Retained signed movement/config/map/clamp helper and table. |
| [UID:0004TQ][0x005bc2d0-0x005bc41c.UserStatusPane2ApplyLegacyMovementStepAlt](by-memory/0x005bc2d0-0x005bc41c.UserStatusPane2ApplyLegacyMovementStepAlt.md) `[0x005bc2d0,0x005bc41c)` | `ApplyLegacyMovementStepAlt(...)` | Independent retained alternate movement helper and table. |
| [UID:0004TR][0x005bc420-0x005bc60c.UserStatusPane2ApplyStatusPayload](by-memory/0x005bc420-0x005bc60c.UserStatusPane2ApplyStatusPayload.md) `[0x005bc420,0x005bc60c)` | `ApplyStatusPayload(...)` | Live flag/cursor/BE read/store/invalidation member. |
| `0x005bfbf0`, `0x005bfc4d`, `0x005bfc58`, `0x005bfe60` | compiler family | Singleton-clear sharing, destructor adjustors, scalar wrapper; never handwritten source bodies. |

## Exact Layout

| Offset | Type / member | Evidence and source treatment |
| --- | --- | --- |
| `+0x000-+0x0f7` | inherited `Pane` subobject | Allocation and all derived accesses place the first member at `+0xf8`. |
| `+0x0f8` | `unsigned char *m_numberGlyphs` | `9X11FONT.BIN` load, glyph rendering, destructor free. |
| `+0x0fc/+0x100` | `int m_positionX`, `int m_positionY` | Signed BE packet reads, movement/clamp logic, `%03u` display. |
| `+0x104/+0x108` | `unsigned int m_statusRow0PartialValue`, `m_statusRow0FullValue` | Payload flags and first status bar/grouped value. |
| `+0x10c/+0x110` | `unsigned int m_statusRow1PartialValue`, `m_statusRow1FullValue` | Payload flags and second status bar/grouped value. |
| `+0x114` | `unsigned int m_statusRow2Value` | Third grouped value and flag-`0x10` payload. |
| `+0x118` | `unsigned char m_statusRow2Percent` | Percent bar; unconditional payload write, no byte-only invalidation. |
| `+0x119-+0x11b` | natural compiler alignment | No source padding member is required. |
| `+0x11c` | `unsigned int m_statusRow3Value` | Fourth grouped value and flag-`0x10` payload. |

The declaration closes naturally at exact allocation size `0x120`. It uses Pane-only inheritance and keeps `[[CHILDREN]]` after the complete class closing `};`, so every qualified body emits at namespace scope.

## Evidence Notes

- IDA callers show construction from `InitializeMainUiGraph` at `0x004f83ea`.
- IDA confirms `0x005bc610` starts [UID:000081][MenuVarietyPane](by-class/MenuVarietyPane.md), so `UserStatusPane2` must end at `0x005bc60c` and must not absorb the adjacent menu code.
- Historical pre-callback generated output omitted all exact `UserStatusPane2::` child definitions and used stale declarations. Current emission is validator-verified after UID0004TG-UID0004TR and this complete class declaration are validated.
- Primary vtable cell `0x00630cf8` proves `OnPaint`; secondary `0x00630d04` proves `HandlePointerOrMouseEvent(Event *)`; secondary `0x00630d10` proves `HandlePacketEvent(Event *)`. The source declaration does not expose adjusted receiver parameters.
- Exact constructor allocation `0x120` and every field access validate the layout table and natural `+0x119-+0x11b` alignment.
- Zero entry xrefs on UID0004TL and UID0004TO-UID0004TQ are retained-source optimization/inlining evidence because complete bodies and matching live factorized/inline sequences exist.

## Source / Compiler Emission Decision

Historical B009 work established the class route but intentionally stopped at an incomplete shell and excluded exact splits in that earlier callback. The current accepted UID0001NO callback supersedes only that limitation: R13 is now the complete source-era declaration, UID0001NO is a blank-formal non-emitting index, and UID0004TG-UID0004TR provide all twelve ordered source bodies. Vtables, RTTI, vptr writes, destructor adjustors, deleting flags, storage deletion, base teardown, cookie and EH forms remain compiler-generated and must not appear as handwritten C++.

Stale `PaneEvent`, `HandleStatusPacketEvent`, `AlwaysFalse`, `DrawGlyphText`, opaque `void *`, and generic `m_value*` names are historicalized because Event ABI, vtable slots, glyph lifecycle, packet behavior, and exact offsets support the declaration above. `Legacy` on the retained packet/movement helpers matches accepted UserStatusPane and OldUserStatusPane sibling family naming.

## Cross-References

- [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- [UID:0001NO][0x005bab00-0x005bc60c.UserStatusPane2](by-memory/0x005bab00-0x005bc60c.UserStatusPane2.md)
- [UID:0001RS][user-status-resources](by-resource/user-status-resources.md)
- [UID:000081][MenuVarietyPane](by-class/MenuVarietyPane.md)
- [UID:0002Z0][0x00630cb4-0x00630d3c.UserStatusPane2VtableData](by-memory/0x00630cb4-0x00630d3c.UserStatusPane2VtableData.md)
- [UID:0004TG][0x005bab00-0x005babf7.UserStatusPane2Constructor](by-memory/0x005bab00-0x005babf7.UserStatusPane2Constructor.md) through [UID:0004TR][0x005bc420-0x005bc60c.UserStatusPane2ApplyStatusPayload](by-memory/0x005bc420-0x005bc60c.UserStatusPane2ApplyStatusPayload.md), the twelve exact source children listed above.

## Changes

- 2026-07-20 B003 UID0001NO accepted callback: raised `86/88` to `93/94`; replaced the incomplete B009 shell with exact R13; closed the `0x120` layout, Event ABI, access model, twelve declarations, singleton extern, child order, source/compiler split, source placement, rejected names, and historical correction. The class closes before `[[CHILDREN]]` and emits UID0004TG-UID0004TR at namespace scope.

- 2026-06-30 B009 implementation callback:
  - Added formal class-shell C++ with `[[CHILDREN]]`.
  - Summary/evidence: accepted B009 report preserves the compact status ownership, `0x005bc610` MenuVariety boundary, singleton/resource ties, and raw-helper uncertainty while making the class declaration route explicit.
- 2026-06-05 autogen metadata classification:
  - What existed before: reconstruction autogen metadata was unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with parent [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md).
  - Summary/evidence: live IDA MCP against `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` confirmed the compact status constructor, cleanup, router, paint, rect/glyph/payload helpers, singleton tail helper, adjustor thunks, and scalar deleting destructor starts from `0x005bab00` through `0x005bfe60`; the class and parent both passed the older 80/80 parent gate. No reconstruction C++ was emitted at that time under the older 95/95 wording; B009 later superseded this with a formal class-shell block.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:88`.
  - Summary/evidence: scored from the compact-status constructor/cleanup/router/paint/rect/glyph/payload method map, singleton evidence, resource links, boundary with `MenuVarietyPane`, and generated-output omission notes.
