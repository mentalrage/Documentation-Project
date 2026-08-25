*** UID:00005Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class GeneralPurposePanel : public LObject, public Singleton<GeneralPurposePanel>
{
public:
    GeneralPurposePanel();
    virtual ~GeneralPurposePanel();

    Pane *GetChildPaneByIndex(int index);
    Pane *GetActiveChildPane();
    void DispatchActiveChildRefresh();
    void SwitchActiveTab(
        int tabIndex,
        const unsigned char *packetData);

private:
    Pane *m_childPanes[7];
    int m_activeChildIndex;
};

extern GeneralPurposePanel *g_pGeneralPurposePanel;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# GeneralPurposePanel

## Status

- Confidence: very strong for hierarchy, exact 0x24 layout, lifecycle/source split, child composition, method behavior, and owner/emitter route; final public spelling remains inferred.
- Likely source file: [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md)
- Main address doc: [UID:00015V][0x004b83d0-0x004b8bd3.GeneralPurposePanel](by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md)
- Current recovered file: `source-3/simroot_v2/class_GeneralPurposePanel.cpp`

## Functionality

`GeneralPurposePanel` is the main in-game side-panel shell. It constructs and stores seven child panes, tracks the active pane id in `m_activeChildIndex` at object offset `+0x20`, switches the visible child pane, and exposes child lookup/active-child helpers.

## Method Map

| Method | Address | Notes |
| --- | --- | --- |
| constructor | [UID:0004UL][0x004b83d0-0x004b857e.GeneralPurposePanelConstructor](by-memory/0x004b83d0-0x004b857e.GeneralPurposePanelConstructor.md) | Constructs self look, user look, inventory, spell inventory, group, collection, and option child panes; direct Singleton base lowering publishes `g_pGeneralPurposePanel`. |
| destructor | [UID:0004UM][0x004b8580-0x004b85e3.GeneralPurposePanelDestructor](by-memory/0x004b8580-0x004b85e3.GeneralPurposePanelDestructor.md) | Unconditionally marks all seven children for deletion; implicit Singleton/LObject teardown clears the singleton. |
| child lookup | [UID:00015W][0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors](by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md) | Returns child by index with EPF/legacy child-count bounds; stale generated owner was `SpellOneArgInputPane`. |
| active-child helpers | [UID:00015W][0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors](by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md) | Return the active child from the same child array and active-index slot, or dispatch that child's refresh/update virtual slot via `DispatchActiveChildRefresh()`. |
| `SwitchActiveTab` | [UID:00015X][0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab](by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md) | Hides/deactivates the old child and lays out/activates the new child; stale generated owner was `SpellOneArgInputPane`. |
| scalar deleting destructor | [UID:0004UN][0x004b8b40-0x004b8bd3.GeneralPurposePanelScalarDeletingDestructor](by-memory/0x004b8b40-0x004b8bd3.GeneralPurposePanelScalarDeletingDestructor.md) | Compiler-only deleting wrapper; `0x004b8bd2` is the final byte of `retn 4`; no handwritten body. |

## Notes

Generated constructor labels the children clearly, and live IDA evidence ties the constructor/accessor/switch/destructor island to this same seven-child layout. Documentation uses the IDA-confirmed `0x004b83d0-0x004b8822` primary-class island as the current source-layout anchor. The semantic singleton is [UID:0000R0][g_pGeneralPurposePanel](by-global/g_pGeneralPurposePanel.md), while physical backing [UID:00028X][0x0067a874-0x0067a878.g_pGeneralPurposePanel](by-memory/0x0067a874-0x0067a878.g_pGeneralPurposePanel.md) stays false/non-emitting. Exact vtable-data child [UID:0003BC][0x0061a884-0x0061a894.GeneralPurposePanelVtableData](by-memory/0x0061a884-0x0061a894.GeneralPurposePanelVtableData.md) records the constructor/destructor/scalar-destructor vptr stores for this class without emitting raw ABI data.

The declaration-level C++ is emitted because class ownership, direct base hierarchy, field layout, and source placement clear the gate. All authored method bodies now live on exact child pages: UID0004UL constructor, UID0004UM ordinary destructor, UID00015W accessors, and UID00015X tab switch. UID0004UN scalar and UID0003BC vtable data remain compiler-only/no-code. The class closes before the `extern` declaration and `[[CHILDREN]]`, so definitions are emitted at file scope. Exact original public spelling remains heuristic and caps the score below final-source quality.

## Direct Hierarchy And EBO Evidence

- Decorated RTTI/CHD entries contain `GeneralPurposePanel`, `LObject`, and `Singleton<GeneralPurposePanel>`; no `PanelPane` descriptor appears.
- The constructor calls `LObject` construction directly and does not call a `PanelPane` constructor.
- Singleton PMD `{4,-1,0}` places the empty direct Singleton base at `+0x04`, overlapping `m_childPanes[0]` through empty-base optimization.
- Callers allocate exactly `0x24` bytes. The vptr at `+0x00`, seven pointers at `+0x04..+0x1c`, and active index at `+0x20` consume the complete layout with no PanelPane state.
- Historical `PanelPane` inheritance is rejected because it contradicts RTTI, constructor calls, PMD, and object size. PanelPane remains a related pane-family dependency, not this class's base.

## 2026-07-13 B004 Accepted Declaration Reconciliation

- `SwitchActiveTab` takes nullable packet data, not `bool showChild`. MapPane caller sites pass EDI payload pointers; packet handlers may pass null.
- `m_childPanes[7]` and `m_activeChildIndex` at `+0x20` remain unchanged. Child index order and UID00015W accessor declarations are preserved.
- [UID:00015X][0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab](by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md) now owns the exact body. This class page supplies declarations and `[[CHILDREN]]` only; it does not duplicate method definitions.
- UID0004KU Collapse, Pane OnActivate, RectBounds, TotemFrame, g_pBackPane, MainUiLayerSlots, FrameChrome, and InterfaceEfx remain dependencies.
- The closing brace precedes a blank line and `[[CHILDREN]]`, correcting the generated state where UID00015W definitions were inserted inside the class.
- Historical callback-time score `89/91` reflected unresolved constructor/destructor splits. Current `92/94` incorporates real UID0004UL/UID0004UM source children, direct Singleton hierarchy, exact EBO layout, one-definition routing, and compiler exclusions; original identifier uncertainty remains the score cap.

The active-child refresh method at `0x004b8630` is now preferred as `DispatchActiveChildRefresh()` rather than the older `RefreshActiveChild()` wording. The behavior is a dispatch through the active child pane's inherited refresh/update vtable slot `+0x20` with argument `0`, and the name matches its two ScreenPane caller contexts. The exact public spelling remains inferred.

## Field Layout

| Offset | Source-facing field | Evidence |
| --- | --- | --- |
| `+0x00` | vptr | Stores vtable base `0x0061a888` from constructor, destructor, and scalar deleting destructor paths. |
| `+0x04..+0x1c` | `m_childPanes[7]` | Seven constructor child stores and `this[index + 1]` reads in child lookup/tab switch helpers. |
| `+0x20` | `m_activeChildIndex` | Read by active-child accessors, switch helper, macro/user callers, and FrameChrome's dynamic `AboveFrame` rebuild as `g_pGeneralPurposePanel->m_activeChildIndex + 5`. |

## Child Index Map

The constructor stores child panes in this order. The active child index is `m_activeChildIndex` at `+0x20` (`this[8]` in raw decompilation). It is read by macro editing, item/spell input panes, and side-panel refresh helpers:

| Index | Child |
| --- | --- |
| `0` | self-look pane |
| `1` | user-look/profile pane |
| `2` | inventory pane |
| `3` | spell inventory pane |
| `4` | group pane |
| `5` | collection pane |
| `6` | option pane |

This mapping is important for [UID:0001V1][MacroHotkeyRecord](by-type/by-struct/MacroHotkeyRecord.md): the integrated macro editor writes state `2` / `.usr` `S` from child index `3`, and state `3` / `.usr` `I` from child index `2`.

FrameChrome also consumes this member without owning it: [UID:0000YI][0x004615b0-0x00461658.AboveFrameRefreshHelpers](by-memory/0x004615b0-0x00461658.AboveFrameRefreshHelpers.md) constructs `AboveFrame(g_pGeneralPurposePanel->m_activeChildIndex + 5, 0x4f, 0x328)` after tab switches.

## Cross References

- [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md)
- [UID:00005R][GeneralPurposePanel2](by-class/GeneralPurposePanel2.md)
- [UID:0000A4][PanelPane](by-class/PanelPane.md)
- [UID:00009V][OptionPane](by-class/OptionPane.md)
- [UID:0000R0][g_pGeneralPurposePanel](by-global/g_pGeneralPurposePanel.md)
- [UID:00028X][0x0067a874-0x0067a878.g_pGeneralPurposePanel](by-memory/0x0067a874-0x0067a878.g_pGeneralPurposePanel.md)
- [UID:0004UL][0x004b83d0-0x004b857e.GeneralPurposePanelConstructor](by-memory/0x004b83d0-0x004b857e.GeneralPurposePanelConstructor.md)
- [UID:0004UM][0x004b8580-0x004b85e3.GeneralPurposePanelDestructor](by-memory/0x004b8580-0x004b85e3.GeneralPurposePanelDestructor.md)
- [UID:00015W][0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors](by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md)
- [UID:00015X][0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab](by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md)
- [UID:0004UN][0x004b8b40-0x004b8bd3.GeneralPurposePanelScalarDeletingDestructor](by-memory/0x004b8b40-0x004b8bd3.GeneralPurposePanelScalarDeletingDestructor.md)
- [UID:0003BC][0x0061a884-0x0061a894.GeneralPurposePanelVtableData](by-memory/0x0061a884-0x0061a894.GeneralPurposePanelVtableData.md)

## Changes

- 2026-07-20 B002 UID00028X accepted callback: raised `89/91 -> 92/94`; replaced rejected `PanelPane` inheritance with direct `LObject` plus `Singleton<GeneralPurposePanel>`; set source position 10; added the sole external singleton declaration after the complete class; registered and linked UID0004UL/UID0004UM/UID0004UN; incorporated exact RTTI/PMD/EBO/0x24 layout, seven-child lifecycle, one-definition route, source/compiler graph, score rationale, and historicalized prior inheritance/unsplit assumptions while preserving all accepted declarations and child bodies.
- 2026-07-20 B001 UID0001NM bounded support synchronization:
  - Current canonical IDs are this class UID00005Q and singleton UID0000R0; the accepted report's `00005M`/`0000RO` spellings are historical coordination typos, not alternate destinations.
  - In the EPF `UserStatusPane::ApplyStatusPayload` path, a changed inventory-slot-count byte at packet offset 30 updates the UserStatusPane field, obtains `GetChildPaneByIndex(2)`, and invokes that inventory child pane's `OnActivate(NULL)`. This is consumer use of the existing seven-child API and does not change GeneralPurposePanel ownership, score, declaration, or child-index mapping.
- 2026-07-13 B004 accepted UID00015Y support callback: raised `85/87 -> 89/91`; replaced bool activation with nullable packet data; closed the class before `[[CHILDREN]]`; preserved every existing declaration, child layout/index map, owner/emitter, and unrelated class evidence.
- 2026-07-08 B005 UID00015X implementation callback: score unchanged; synced class notes with the target no-code proof. The class declaration already has `SwitchActiveTab(int tabIndex, bool showChild)`, `m_childPanes[7]`, and `m_activeChildIndex`, while the exact method body remains on [UID:00015X][0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab](by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md) with blank formal C++ pending source-quality names for helper `0x00544ee0`, inherited helper slot `+0x0c`, and inherited display/activation slot `+0x48`.
- 2026-06-20 B003 Rule 26 source-quality incorporation: added declaration-level draft C++, switched constructor/destructor ranges to half-open boundaries, accepted `m_childPanes[7]` and `m_activeChildIndex`, and recorded why method bodies remain on child pages or deferred constructor/destructor splits. Score unchanged because final method spelling and helper names remain below final-source certainty.
- 2026-06-21 B007 ScreenPane palette-helper support sync: renamed the declaration-level active-child refresh helper from `RefreshActiveChild()` to preferred `DispatchActiveChildRefresh()` to match [UID:00015W][0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors](by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md) and the ScreenPane caller contexts. Score unchanged because original spelling is still heuristic.
- 2026-06-20 B003 AboveFrame source-quality implementation: accepted `m_activeChildIndex` as the source-facing name for offset `+0x20` / raw `this[8]` and recorded the FrameChrome dynamic `AboveFrame` consumer. This does not change ownership; the member belongs to `GeneralPurposePanel`, while the frame refresh helpers belong to [UID:0000JL][FrameChrome](by-file/FrameChrome.md).
- 2026-06-20 B006 Rule 26 reconciliation: score unchanged; reconfirmed the FrameChrome consumer path while keeping `m_activeChildIndex` and the singleton owner with this class/file.
- 2026-06-11 A005 Batch 214 parent-gate repair:
  - Before: `82/86`; the exact `GeneralPurposePanel` vtable record was trapped inside mixed [UID:0002V4][0x0061a884-0x0061a8b8.PanelGrafPortVtableData](by-memory/0x0061a884-0x0061a8b8.PanelGrafPortVtableData.md).
  - After: `85/87`, supporting direct ownership of [UID:0003BC][0x0061a884-0x0061a894.GeneralPurposePanelVtableData](by-memory/0x0061a884-0x0061a894.GeneralPurposePanelVtableData.md).
  - Evidence: live IDA MCP reconfirmed `0x0061a884 -> ??_R4GeneralPurposePanel@@6B@`, `0x0061a888 -> ??_7GeneralPurposePanel@@6B@`, vptr stores from constructor/destructor/scalar-destructor paths, the `0x004b8b40-0x004b8bd3` destructor slot already recorded in [UID:00015V][0x004b83d0-0x004b8bd3.GeneralPurposePanel](by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md), and the `GeneralPurposePanel2` successor RTTI boundary at `0x0061a894`.
- Completion/confidence score update: existed before as `0/0`; changed to `78/82`. Summary: side-panel shell role, seven-child layout, singleton, constructor/destructor, child accessors, active-tab switch, child index map, and macro-editor implications are documented; helper ownership cleanup remains medium-confidence. Evidence: `0x004b83d0-0x004b8bd3` memory page, child accessor/switch pages, `g_pGeneralPurposePanel`, and child index map.
- 2026-06-05: Marked reconstructable, but left `AUTOGEN_PARENT_UID` blank because the class is `78/82`, below the 80/80 parent-attachment gate, even though [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md) remains the likely owner. Live IDA MCP `lookup_funcs` confirms exact starts at `0x004b83d0`, `0x004b8580`, `0x004b85f0`, `0x004b8650`, and `0x004b8b40`; current `callers` confirms constructor references from `InitializeMainUiGraph` at `0x004f7ff7` and `0x004f8835`.
- 2026-06-06: Raised to `82/86` and attached the class to [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md). Live IDA MCP reconfirmed the constructor/destructor starts, the three child accessor helpers, `SwitchActiveTab`, broad side-panel caller sets, and the matching child-array/active-index behavior; final field names and exact source declarations remain below final-code certainty.
