*** UID:0000DO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000O1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000O1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:020 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SpellInventoryPane2 : public PanelPane
{
public:
    SpellInventoryPane2();
    virtual ~SpellInventoryPane2();

    virtual void OnActivate(const unsigned char *activationData);
    virtual void OnPaint();
    virtual bool OnKeyEvent(Event *event);
    virtual bool OnMouseEvent(Event *event);
    virtual bool OnServerMessage(Event *event);

private:
    void SetSpellInputActive(bool active);
    void ActivateSpellSlot(unsigned char spellSlot);
    void SendDirectSpellPacket(unsigned char spellSlot);
    static void __stdcall BuildPageButtonRect(short button, RectBounds *bounds);
    static void __stdcall BuildSpellRowRect(short row, RectBounds *bounds);
    static short __stdcall HitTestPageButton(int y, int x);
    static short __stdcall HitTestSpellRow(int y, int x);
    static int __stdcall VisibleOrdinalToSpellSlot(short visibleOrdinal);

    unsigned char m_pageIndex;
    bool m_isLastPage;
    bool m_spellInputActive;
    unsigned char m_reservedFB[5];
};

typedef char SpellInventoryPane2_size_must_be_0x100[
    sizeof(SpellInventoryPane2) == 0x100 ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SpellInventoryPane2

## UID0000O1 Accepted Class Reconstruction - 2026-08-22

This exact `0x100` alternate class is source-ready and emits at position `020` through [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md). Its formal CPP expands `[[CHILDREN]]`; its formal H continues the guard opened by UID0000DN, declares the complete class, verifies size `0x100`, and closes the guard. Source-bearing children emit at positions `100` through `240`; UID00044H remains blank and non-emitting.

Accepted roles are `OnActivate` at `0x0057eac0`, `OnServerMessage` at `0x0057f000`, Event-based key/mouse methods, a 13-entry page stride, and exactly ten clickable rows. The corrected exact child paths/ranges are OnActivate `[0x0057eac0,0x0057ead5)`, SetSpellInputActive `[0x0057eae0,0x0057eaf0)`, SendDirectSpellPacket `[0x0057f290,0x0057f2f0)`, BuildPageButtonRect `[0x0057f2f0,0x0057f371)`, BuildSpellRowRect `[0x0057f380,0x0057f3d3)`, and HitTestPageButton `[0x0057f3e0,0x0057f488)`.

The tail layout is `m_pageIndex +0xf8`, `m_isLastPage +0xf9`, `m_spellInputActive +0xfa`, and reserved bytes `+0xfb..+0xff`. The one-byte `0x0057eaf0` nullsub has no stable declaration slot, xref, pointer hit, or side effect and remains protected no-code. Raw local helpers are retained private/static source despite zero start xrefs because their complete bodies and inlined caller behavior are byte-supported.

## Status

- Confidence: strong for alternate spell-pane behavior, source-family ownership, verified method boundaries, vtable ownership, and raw constructor/setup evidence.
- Likely source file: [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md) or `ui/inventory/SpellInventoryPane.cpp`
- Autogen handling: attached to [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md) after Batch 250 raised both this class and the file root above the strict `85/85` gate.
- Address range: non-emitting split/index parent [UID:0002RK][0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers](by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md) covers the alternate core; exact child pages [UID:00044D][0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor](by-memory/0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor.md) through [UID:00044S][0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot](by-memory/0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot.md) carry constructor, destructor, virtual methods, dispatcher, local helpers, formal C++/no-code proof, and source-bearing reconstruction metadata. Compiler scalar-wrapper refs remain in [UID:0002RL][0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors](by-memory/0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors.md). The broad [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md) parent is a non-emitting split/index.
- Current generated CPP/H: `auto-generated/NexusTK/ui/inventory/SpellInventoryPane.cpp` and `auto-generated/NexusTK/ui/inventory/SpellInventoryPane.h`; this class shares the canonical file root with legacy `SpellInventoryPane`.
- Historical path correction: `source-3/simroot_v2/class_SpellInventoryPane2.cpp` was an earlier recovered-path assertion; that file does not exist and is not current generated authority.

## Class Purpose

`SpellInventoryPane2` is an alternate grid/page spell inventory pane. It displays spell icons and names, supports page buttons and Page Up/Page Down keys, and handles spell selection/info clicks.

## Method Notes

| Method | Address | Child | Role |
| --- | --- | --- | --- |
| `SpellInventoryPane2` | `0x0057ea60-0x0057ea9f` | [UID:00044D][0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor](by-memory/0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor.md) | Raw-byte constructor/setup body; no IDA function object, but the body calls base setup, installs three vtable views, clears `m_pageIndex` and `m_spellInputActive`, and emits formal constructor C++. |
| `~SpellInventoryPane2` | `0x0057eaa0-0x0057eabf` | [UID:00044E][0x0057eaa0-0x0057eac0.SpellInventoryPane2Destructor](by-memory/0x0057eaa0-0x0057eac0.SpellInventoryPane2Destructor.md) | Non-deleting destructor body. Vtable reset/base cleanup are compiler lowering; source name is destructor, not `ResetVtablesAndCleanup`. |
| `OnActivate` | `0x0057eac0-0x0057ead4` | [UID:00044F][0x0057eac0-0x0057ead5.SpellInventoryPane2OnActivate](by-memory/0x0057eac0-0x0057ead5.SpellInventoryPane2OnActivate.md) | Primary-vtable activation clears page state and invalidates/redraws the pane. |
| `SetSpellInputActive` | `0x0057eae0-0x0057eaef` | [UID:00044G][0x0057eae0-0x0057eaf0.SpellInventoryPane2SetSpellInputActive](by-memory/0x0057eae0-0x0057eaf0.SpellInventoryPane2SetSpellInputActive.md) | Retained private raw duplicate setter; complete body includes `retn 4`. |
| source-empty virtual | `0x0057eaf0-0x0057eaf0` | [UID:00044H][0x0057eaf0-0x0057eaf1.SpellInventoryPane2SourceEmptyVirtual](by-memory/0x0057eaf0-0x0057eaf1.SpellInventoryPane2SourceEmptyVirtual.md) | One-byte no-op virtual (`retn`) with non-emitting no-code proof. |
| `OnPaint` | `0x0057eb00-0x0057eda3` | [UID:00044I][0x0057eb00-0x0057eda4.SpellInventoryPane2OnPaint](by-memory/0x0057eb00-0x0057eda4.SpellInventoryPane2OnPaint.md) | Draws `SPELLINV.EPF`, scans learned spell records, renders visible spell rows, and computes `m_isLastPage`. |
| `OnKeyEvent` | `0x0057edb0-0x0057ee2b` | [UID:00044J][0x0057edb0-0x0057ee2c.SpellInventoryPane2OnKeyEvent](by-memory/0x0057edb0-0x0057ee2c.SpellInventoryPane2OnKeyEvent.md) | Handles Page Up/Page Down while respecting IME state and `m_isLastPage`. |
| `OnMouseEvent` | `0x0057ee30-0x0057eff6` | [UID:00044K][0x0057ee30-0x0057eff7.SpellInventoryPane2OnMouseEvent](by-memory/0x0057ee30-0x0057eff7.SpellInventoryPane2OnMouseEvent.md) | Handles page buttons, local input lock, single/double-click spell activation, and `m_spellInputActive` gate. |
| `OnServerMessage` | `0x0057f000-0x0057f027` | [UID:00044L][0x0057f000-0x0057f028.SpellInventoryPane2OnServerMessage](by-memory/0x0057f000-0x0057f028.SpellInventoryPane2OnServerMessage.md) | Calls primary `OnActivate` for packet opcodes `23`/`24` and always returns false. |
| `ActivateSpellSlot` | `0x0057f030-0x0057f28b` | [UID:00044M][0x0057f030-0x0057f28c.SpellInventoryPane2ActivateSpellSlot](by-memory/0x0057f030-0x0057f28c.SpellInventoryPane2ActivateSpellSlot.md) | Validates one-based slots, reads `UserSpellRecord`, dispatches `SpellInputKind` prompt/direct routes, owns jump table at `0x0057f26c`. |
| `SendDirectSpellPacket` | `0x0057f290-0x0057f2ef` | [UID:00044N][0x0057f290-0x0057f2f0.SpellInventoryPane2SendDirectSpellPacket](by-memory/0x0057f290-0x0057f2f0.SpellInventoryPane2SendDirectSpellPacket.md) | Retained local sender; corrected exclusive end includes the `retn 4` immediate. |
| `BuildPageButtonRect` | `0x0057f2f0-0x0057f370` | [UID:00044O][0x0057f2f0-0x0057f371.SpellInventoryPane2BuildPageButtonRect](by-memory/0x0057f2f0-0x0057f371.SpellInventoryPane2BuildPageButtonRect.md) | Retained local builder; corrected exclusive end includes the `retn 8` immediate. |
| `BuildSpellRowRect` | `0x0057f380-0x0057f3d2` | [UID:00044P][0x0057f380-0x0057f3d3.SpellInventoryPane2BuildSpellRowRect](by-memory/0x0057f380-0x0057f3d3.SpellInventoryPane2BuildSpellRowRect.md) | Retained local ten-row builder; corrected exclusive end includes the `retn 8` immediate. |
| `HitTestPageButton` | `0x0057f3e0-0x0057f487` | [UID:00044Q][0x0057f3e0-0x0057f488.SpellInventoryPane2HitTestPageButton](by-memory/0x0057f3e0-0x0057f488.SpellInventoryPane2HitTestPageButton.md) | Retained local hit-test; corrected exclusive end includes the `retn 8` immediate. |
| `HitTestSpellRow` | `0x0057f490-0x0057f522` | [UID:00044R][0x0057f490-0x0057f523.SpellInventoryPane2HitTestSpellRow](by-memory/0x0057f490-0x0057f523.SpellInventoryPane2HitTestSpellRow.md) | Scans ten spell-row rectangles and returns row index or `-1`. |
| `VisibleOrdinalToSpellSlot` | `0x0057f530-0x0057f58a` | [UID:00044S][0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot](by-memory/0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot.md) | Maps one-based visible learned-spell ordinal to one-based spell-table slot. |
| scalar deleting destructor wrapper | `0x0057f640-0x0057f694` | [UID:0002RL][0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors](by-memory/0x0057f58b-0x0057f742.SpellInventoryScalarDeletingDestructors.md) | MSVC scalar deleting destructor wrapper, not an ordinary handwritten destructor body for direct C++ emission. The ordinary non-deleting destructor body is [UID:00044E][0x0057eaa0-0x0057eac0.SpellInventoryPane2Destructor](by-memory/0x0057eaa0-0x0057eac0.SpellInventoryPane2Destructor.md). |

## Field And Split Notes

- Current best field names from B008 live MCP session `80de0a67`: `+0xf8 m_pageIndex`, `+0xf9 m_isLastPage`, and `+0xfa m_spellInputActive`. `+0xf9` is not `m_hasNextPage`: paint sets it true and clears it only if a later learned spell exists, while Page Down/page-button paths advance only when it is false.
- [UID:0002RK][0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers](by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md) carries the non-emitting parent/index map. Exact child pages carry formal C++ or no-code proof; this class CPP contains `[[CHILDREN]]` so those definitions emit through the class into [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md).
- The raw helper starts lack direct xref/data/immediate/pointer routes, but current MCP evidence confirms their byte-level roles and class-local source ownership. Treat them as retained `SpellInventoryPane2` local helpers, not padding and not public entry points.
- `SpellInputKind` route names are current best source-facing names: string, target/who, four-argument, three-argument, direct, two-argument, one-argument, and spell-slot prompt. `UserSpellRecord::learned` and `UserSpellRecord::inputKind` are the fields proved by this method family; broader payload fields remain conservative.

## Evidence Notes

- IDA MCP confirms paint, key, click, dispatcher, helper, and destructor boundaries.
- B008 live MCP session `80de0a67` supersedes the older offline fallback caveat for this target: it rechecked the raw constructor, modeled methods, `0x0057f26c` jump table, raw helper bodies, negative route checks, and field offsets on the live IDB.
- [UID:0002RK][0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers](by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md) documents the alternate-pane constructor/method/helper island as non-emitting parent `94/95`; child pages [UID:00044D][0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor](by-memory/0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor.md) through [UID:00044S][0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot](by-memory/0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot.md) now hold the exact source-bearing code/no-code decisions.
- [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md) records the enclosing spell inventory aggregate at `91/94` as a non-emitting split/index, including the vtable dword review that maps `SpellInventoryPane2` slots into this executable island.
- [UID:00026J][0x0062cfd8-0x0062d418.SpellInventoryMacroReadOnlyData](by-memory/0x0062cfd8-0x0062d418.SpellInventoryMacroReadOnlyData.md) records the mixed read-only-data island containing the `SpellInventoryPane2` vtable group.
- Raw-byte review on 2026-06-12 proves `0x0057ea60-0x0057ea9f` is class-owned constructor/setup code even though IDA has no function object. It stores vtables `0x0062d0f4`, `0x0062d144`, and `0x0062d174`; those same vtables are referenced by reset and destructor code.
- B011 2026-06-21 parent split/index recheck confirms that no IDA function object and no direct/literal route to `0x0057ea60` do not block source reconstruction for the exact child: the raw constructor/setup bytes are high-confidence class-owned code. Conversely, scalar deleting destructor refs should stay compiler-wrapper evidence, not handwritten destructor C++.

## Parent Gate Analysis

`SpellInventoryPane2` is reconstructable and belongs under [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md). Batch 250 raises this class to `85/87` and the likely file root to `85/86`, so `AUTOGEN_PARENT_UID:0000O1` now clears the strict direct parent gate.

Child method pages now attach to this class: [UID:00044D][0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor](by-memory/0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor.md) through [UID:00044S][0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot](by-memory/0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot.md) all have exact ranges and metadata; reconstructable children emit through this class to [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md). [UID:0002RK][0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers](by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md) remains owner-routed to this class as the non-emitting split/index parent.

## Cross-References

- [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md)
- [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md)
- [UID:0002RK][0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers](by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md)
- [UID:00026J][0x0062cfd8-0x0062d418.SpellInventoryMacroReadOnlyData](by-memory/0x0062cfd8-0x0062d418.SpellInventoryMacroReadOnlyData.md)
- [UID:00044D][0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor](by-memory/0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor.md) through [UID:00044S][0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot](by-memory/0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot.md) exact `SpellInventoryPane2` child pages

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `76`, confidence `74`.
- Evidence: the page documents alternate spell-pane behavior, file/range ownership, paint/key/click/destructor methods, and the projected-constructor caveat; confidence remains capped because IDA does not define the generated constructor start.
- 2026-06-03 autogen attachment pass:
  - Before: the page remained unparented at `76/74` even though the parent file and exact memory island had reached the 80+ confidence gate.
  - Changed to: completion/confidence `78/82`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000O1`.
  - Evidence: [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md) was `82/82`; [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md) documented the enclosing executable island at `82/84`; [UID:0002RK][0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers](by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md), then named with an underbroad `0x0057eaa0` start, documented the class-specific alternate-pane helper island at `74/82`. The old blank-C++ rationale was superseded by the 2026-06-12/2026-06-21 evidence: the raw constructor is source-authored, but broad-island/method-split and final-name blockers still prevent class-level C++ here.
- 2026-06-10 A002 strict-gate repair:
  - Before: the class still attached to [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md) under the older 80% parent rule.
  - Changed to: completion/confidence `80/82` and blank `AUTOGEN_PARENT_UID`.
  - Evidence: the likely file root remained only `82/82`, the class was still below the corrected `85/85` gate, and [UID:0002RK][0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers](by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md), then named with an underbroad `0x0057eaa0` start, remained capped by the unresolved constructor/setup boundary.
- 2026-06-12 A001 Batch 250:
  - Changed to: completion/confidence `85/87` and `AUTOGEN_PARENT_UID:0000O1`.
  - Evidence: live IDA raw-byte review resolved the constructor/setup blocker at `0x0057ea60-0x0057ea9f`, [UID:0002RK][0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers](by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md) now documents the exact child at `86/89`, and [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md) now clears the direct parent gate at `85/86`.
- 2026-06-21 Rule 26 B011 parent split/index sync:
  - Score unchanged at `85/87`.
  - Summary/evidence: documented [UID:0001IH][0x0057c2d0-0x0057f742.SpellInventoryPanes](by-memory/0x0057c2d0-0x0057f742.SpellInventoryPanes.md) as a non-emitting split/index, kept the raw `0x0057ea60-0x0057ea9f` constructor/setup body as source-authored child code under [UID:0002RK][0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers](by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md), and reworded `0x0057f640` as scalar deleting destructor compiler-wrapper evidence rather than a normal emitted destructor body.
- 2026-06-26 B008 support sync:
  - Score unchanged at `85/87`.
  - Summary/evidence: added current live MCP confirmation from session `80de0a67`, split the local raw helper roles/ranges in method notes, recorded `+0xf9 m_hasNextPage` as distinct from `+0xf8 m_pageIndex` and `+0xfa m_spellInputActive`, and pointed future structural splitting to [UID:0002RK][0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers](by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md).
- 2026-06-26 B008 split implementation:
  - Changed score from `85/87` to `89/90`.
  - Summary/evidence: incorporated the accepted [UID:0002RK][0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers](by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md) split. Added exact child mappings [UID:00044D][0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor](by-memory/0x0057ea60-0x0057eaa0.SpellInventoryPane2Constructor.md) through [UID:00044S][0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot](by-memory/0x0057f530-0x0057f58b.SpellInventoryPane2VisibleOrdinalToSpellSlot.md), corrected `+0xf9` to `m_isLastPage`, resolved `0x0057eaa0` as destructor source, recorded `SpellInputKind`/`UserSpellRecord` naming decisions, and kept class-level formal C++ blank so method/helper code stays in child pages.
