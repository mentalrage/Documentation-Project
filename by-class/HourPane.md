*** UID:000068 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class HourPane : public Pane, public Singleton<HourPane>
{
public:
    HourPane();
    virtual ~HourPane();

    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual void OnPaint();

private:
    bool UpdateHour(const unsigned char *packetData);

    signed char m_currentHour;
};

extern HourPane *g_pHourPane;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# HourPane

## Status

- Confidence: very strong for source behavior, direct inheritance, complete class surface, layout, singleton/vtable/resource evidence, and source-file ownership.
- Likely source module: [UID:0000JX][HourPane](by-file/HourPane.md)
- Emitter parent: [UID:0000JX][HourPane](by-file/HourPane.md), source position 10.
- Main range: [UID:00016Y][0x004cee60-0x004cf1ef.HourPane](by-memory/0x004cee60-0x004cf1ef.HourPane.md)
- Singleton global: [UID:0000R4][g_pHourPane](by-global/g_pHourPane.md)
- Resource doc: [UID:0001RC][hourpane-time-resources](by-resource/hourpane-time-resources.md)
- Evidence basis: `simroot_v2` and IDA MCP checks through 2026-06-16.

## Responsibility

`HourPane` is the in-game hour/clock HUD pane. It receives a server/message hour update, stores the current hour byte, paints an hour icon from `TIME.EPF` or `TIME.EPD`, and shows a localized tooltip for the current hour.

## Layout Evidence

- Constructor writes vtables at object offsets `0x0`, `0xa0`, and `0xa4`, matching a primary pane object plus two adjustor subobjects.
- Current hour lives at object offset `0xf8`; constructor initializes it to `-1`.
- Paint and update paths invalidate the draw region beginning at object offset `0x44`.
- Mouse/help and packet/update methods receive subobject `this` pointers and recover the owner by subtracting `0xa0`.
- Vtable addresses observed by IDA: `0x0061b370`, `0x0061b3bc`, and `0x0061b3ec`.

## Complete Method And Child Inventory

| Address | Current name | Notes |
| --- | --- | --- |
| `0x004cee60-0x004ceeaf` | [UID:0004NJ][0x004cee60-0x004ceeaf.HourPaneConstructor](by-memory/0x004cee60-0x004ceeaf.HourPaneConstructor.md) | Human constructor; Pane(1), implicit Singleton publication, `m_currentHour=-1`. |
| `0x004ceeb0-0x004ceed9` | [UID:0004NK][0x004ceeb0-0x004ceed9.HourPaneDestructor](by-memory/0x004ceeb0-0x004ceed9.HourPaneDestructor.md) | Empty human virtual destructor; compiler/base teardown consequences stay out of source. |
| `0x004ceee0-0x004cef25` | [UID:0004NL][0x004ceee0-0x004cef25.HourPaneHandlePacketEvent](by-memory/0x004ceee0-0x004cef25.HourPaneHandlePacketEvent.md) | EventHandler packet override for discriminator `0x20`, signed byte 1, update/invalidate, false return. |
| `0x004cef30-0x004cf009` | [UID:0004NM][0x004cef30-0x004cf009.HourPaneHandlePointerOrMouseEvent](by-memory/0x004cef30-0x004cf009.HourPaneHandlePointerOrMouseEvent.md) | Right-button pointer override with exact prior-help deletion, hit test, string 77, formatting, allocation, and 5000-ms lifetime. |
| `0x004cf010-0x004cf139` | [UID:0004NN][0x004cf010-0x004cf139.HourPaneOnPaint](by-memory/0x004cf010-0x004cf139.HourPaneOnPaint.md) | Paint override with exact EPF/EPD asset branches and rendering callbacks. |
| `0x004cf140-0x004cf173` | [UID:0004NO][0x004cf140-0x004cf173.HourPaneUpdateHourRaw](by-memory/0x004cf140-0x004cf173.HourPaneUpdateHourRaw.md) | Retained/inlined private helper with exact signed update semantics and descriptive-name confidence cap. |
| `0x004cf173-0x004cf189` | [UID:0004NP][0x004cf173-0x004cf189.HourPaneDestructorAdjustorThunks](by-memory/0x004cf173-0x004cf189.HourPaneDestructorAdjustorThunks.md) | Compiler-only `+0xa0`/`+0xa4` wrappers; non-emitting. |
| `0x004cf190-0x004cf1ef` | [UID:0004NQ][0x004cf190-0x004cf1ef.HourPaneScalarDeletingDestructor](by-memory/0x004cf190-0x004cf1ef.HourPaneScalarDeletingDestructor.md) | Compiler-only flag/delete wrapper; non-emitting. |

## External State

- [UID:0000R4][g_pHourPane](by-global/g_pHourPane.md) at `0x0069b418`; generated alias `g_pItemShopPane` is wrong for this owner.
- `g_pLanguageMan` at `0x0067a750`; text id `0x4d` is used as the tooltip label.
- [UID:0000S9][g_pSimpleHelpPane](by-global/g_pSimpleHelpPane.md) at `0x0069ae00`; an existing help pane is deleted before the branch-local hit test. The former `g_pSecurityCallback` interpretation is rejected and retained only as historical provenance.
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97`; selects new/current EPF drawing versus old EPD drawing.
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) / historical `dword_67A744`; image/resource manager used to load `TIME.EPF` and `TIME.EPD`.
- [UID:0002ZE][g_hourFrameTable](by-global/g_hourFrameTable.md) / [UID:00027K][0x0066db04-0x0066db1c.HourPaneFrameTable](by-memory/0x0066db04-0x0066db1c.HourPaneFrameTable.md); twelve-entry frame table used as `(hour / 2) % 12`.
- `dword_69B3FC` and `dword_69B3E8`; invalidation/draw callback globals used by the paint path.

## Source-Complete Class Rationale

The declaration is source-complete at `92/94`. RTTI proves direct `Pane` and `Singleton<HourPane>` inheritance and inherited EventHandler/TimerHandler views. Allocation size `0xfc`, Singleton displacement `+0xf8`, and every target field reference leave exactly one source field, signed `m_currentHour`, at `+0xf8`; inherited storage occupies the preceding bytes, so no synthetic padding member is needed. The six human methods are independently emitted through UID0004NJ-UID0004NO. UID0004NP and UID0004NQ are compiler consequences and intentionally do not appear as declarations or emitted bodies.

## Vtable And Layout Resolution

- Primary vtable `0x0061b370` has 18 slots. Target-owned entries are deleting destructor slot 0 and `OnPaint` slot 17; all other slots are inherited.
- EventHandler view `0x0061b3bc` has 11 slots. Target-owned entries are adjusted destructor slot 0, `HandlePointerOrMouseEvent` slot 1, and `HandlePacketEvent` slot 4; the remaining entries are inherited.
- TimerHandler view `0x0061b3ec` contributes only the adjusted destructor at slot 0; timer slot 1 is inherited.
- RTTI entries enumerate `HourPane`, `Pane`, `GrafPort`, `LObject`, `EventHandler`, `TimerHandler`, and `Singleton<HourPane>`. Complete-object-locator offsets `+0xa0` and `+0xa4` exactly match the destructor thunks.
- Constructor allocation and both UI graph call sites prove a `0xfc` complete object. `m_currentHour` is read/written as a signed byte at `+0xf8`; `-1` is the unset sentinel. No independent target field or tail array is evidenced.
- Bounds at `+0x44` are inherited Pane state, not a new HourPane member. Source methods use the inherited `m_bounds` declaration.

## Current Evidence Refresh

- 2026-06-16 A002 live IDA MCP on `b001_mappane_0001AW_20260616` reconfirmed exact function objects for constructor `0x004cee60`, cleanup `0x004ceeb0`, update handler `0x004ceee0`, mouse handler `0x004cef30`, paint `0x004cf010`, and scalar deleting destructor `0x004cf190`; the adjustor thunk bytes remain compiler glue between the main bodies.
- `xrefs_to 0x0069b418` reports exactly four singleton refs: constructor publish `0x004cee85`, cleanup clear `0x004ceeca`, scalar-destructor clear `0x004cf1b0`, and UI cleanup consumer `0x00504a18`. `xrefs_to` the three vtable bases `0x0061b370`, `0x0061b3bc`, and `0x0061b3ec` reports the constructor, cleanup, and scalar-destructor store triads.
- `analyze_function 0x004ceee0` shows the update handler is reached through the vtable slot data at `0x0061b3cc`, reads `*(a2 + 12)`, filters command byte `0x20`, copies the next byte to `this[0xf8]`, and invalidates `this + 0x44` only when the hour changes. `analyze_function 0x004cf010` reconfirmed the `TIME.EPF`/`TIME.PAL` versus `TIME.EPD` branch and `(currentHour / 2) % 12` lookup through `word_66DB04`.
- The 2026-07-14 source-quality pass resolved the former blockers. `0x00544580` is a Pane/base destructor consequence rather than a source-visible HourPane helper; the EventHandler inventory supplies canonical `HandlePacketEvent` and `HandlePointerOrMouseEvent`; `+0x44` is inherited `m_bounds`; and the sole source field is signed `m_currentHour` at `+0xf8`.

## Resolved Questions And Remaining Lexical Cap

- Base cleanup is not a separate HourPane declaration: the ordinary destructor and compiler wrapper invoke inherited Pane teardown.
- The two EventHandler overrides use current canonical interface names `HandlePointerOrMouseEvent(Event *)` and `HandlePacketEvent(Event *)`; exact vtable slots and sibling interface documentation support them.
- `m_bounds` is inherited and `m_currentHour` is the sole direct field at `+0xf8`; object size is `0xfc`.
- Only the original private-helper spelling is unavailable. `UpdateHour` is descriptive, behavior-complete, private, and explicitly confidence-capped; that lexical uncertainty does not reduce class shape, ownership, layout, or source behavior below the accepted scores.

## Negative And Historical Evidence

- Reject `g_pItemShopPane`, `g_pSecurityCallback`, `OnMouseEvent`, generic cleanup-helper, explicit Singleton assignment/clear, handwritten owner subtraction, and handwritten scalar-wrapper mechanics as current source claims.
- The source class does not declare three vptrs, secondary-base adjustment fields, delete flags, padding arrays, resource caches, frame-table storage, or a custom deallocator. Those are inherited, global, or compiler-generated concerns.
- The old blank class block and `86/88` score reflected unresolved names rather than contradictory evidence. This complete declaration supersedes that state while retaining its live-analysis history below.

## Cross-References

- [UID:0000JX][HourPane](by-file/HourPane.md)
- [UID:00016Y][0x004cee60-0x004cf1ef.HourPane](by-memory/0x004cee60-0x004cf1ef.HourPane.md)
- [UID:0000R4][g_pHourPane](by-global/g_pHourPane.md)
- [UID:0002ZE][g_hourFrameTable](by-global/g_hourFrameTable.md)
- [UID:00027K][0x0066db04-0x0066db1c.HourPaneFrameTable](by-memory/0x0066db04-0x0066db1c.HourPaneFrameTable.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)
- [UID:0001RC][hourpane-time-resources](by-resource/hourpane-time-resources.md)
- [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md)
- [UID:0000IF][ConnStatusPane](by-file/ConnStatusPane.md)

## Changes

- 2026-07-14 B005 callback: raised `86/88 -> 92/94`, set source position 10, applied the complete Pane/Singleton declaration and six-method surface, linked eight exact children, resolved the inherited bounds/current-hour layout and EventHandler names, and historicalized stale alias/security/helper/compiler-body assumptions.
- 2026-06-16 A002 class-confidence refresh:
  - Before: `COMPLETION:85`, `CONFIDENCE:85`.
  - After: `COMPLETION:86`, `CONFIDENCE:88`; owner/emitter unchanged at [UID:0000JX][HourPane](by-file/HourPane.md).
  - Evidence: live IDA MCP reconfirmed exact method starts, singleton refs, vtable store triads, server-hour packet/update behavior, paint resource branches, and frame-table usage.
  - Blockers checked: inherited base cleanup name, update-interface name, and final field names remain unsafe because current IDA symbols and direct docs provide behavior/xref evidence but no source-quality names.
- 2026-06-11 A001 strict-gate repair:
  - Before: `COMPLETION:82`, `CONFIDENCE:80`, `AUTOGEN_PARENT_UID:` blank because the class and direct file parent did not clear the corrected `85/85` assignment gate.
  - After: `COMPLETION:85`, `CONFIDENCE:85`, `AUTOGEN_PARENT_UID:0000JX`.
  - Summary/evidence: accepted the class-to-file parent after [UID:0000JX][HourPane](by-file/HourPane.md) reached `88/85` and the class page now records the evidence chain through exact method island [UID:00016Y][0x004cee60-0x004cf1ef.HourPane](by-memory/0x004cee60-0x004cf1ef.HourPane.md), singleton [UID:0000R4][g_pHourPane](by-global/g_pHourPane.md), exact frame-table child [UID:00027K][0x0066db04-0x0066db1c.HourPaneFrameTable](by-memory/0x0066db04-0x0066db1c.HourPaneFrameTable.md), and resource page [UID:0001RC][hourpane-time-resources](by-resource/hourpane-time-resources.md). Remaining uncertainty is limited to inherited base/interface and field names, so final C++ stays blank.
- 2026-06-07 A005 resolved-name cleanup:
  - Before: HourPane resource-manager evidence used only historical `dword_67A744`.
  - After: the page records canonical `g_pEPFLib` beside the historical label and cross-links the global page.
  - Evidence: generated resolved-name report maps `dword_67A744` to `g_pEPFLib`; existing page evidence already ties the reference to `TIME.EPF`/`TIME.EPD` resource loading.
- 2026-06-07 A008 alias cleanup: normalized `byte_66DA97` / `g_isEPFMode` to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), preserving `byte_66DA97` as the IDA lookup alias.
- Completion/confidence score update: existed before as `0/0`; changed to `82/80`. Summary: HUD clock responsibility, layout offsets, vtables, methods, globals, resource usage, wrong generated alias, and open base/interface questions are documented; confidence remains limited by inherited base naming and update-interface naming. Evidence: `HourPane` memory range, `g_pHourPane`, `hourpane-time-resources`, IDA vtable addresses, and external-state notes.
- 2026-06-05: Marked reconstructable and attached to [UID:0000JX][HourPane](by-file/HourPane.md).
  - Before: `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` were blank, leaving the HUD clock pane unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE` and `AUTOGEN_PARENT_UID:0000JX`; left the C++ block blank because the page is below the final reconstruction bar.
  - Summary/evidence: live IDA MCP reconfirms real starts at `0x004cee60`, `0x004ceeb0`, `0x004ceee0`, `0x004cef30`, `0x004cf010`, and `0x004cf190`, with constructor callers from `0x004f7d10`. The class score `82/80` and parent score `88/82` meet the 80/80 attachment gate.
- 2026-06-10 A002 strict-gate repair:
  - Before: `AUTOGEN_PARENT_UID:0000JX` attached this class to [UID:0000JX][HourPane](by-file/HourPane.md), and the status still referenced a generated file name.
  - After: `AUTOGEN_PARENT_UID:` is blank and status records the strict `85/85` gate; score remains `82/80`.
  - Summary/evidence: the likely source file is still correct evidence, but the direct parent is only `88/82` and this child is only `82/80`, so neither side clears the current gate. The source-owner link remains informational until inherited base/update-interface naming and parent confidence are improved.
