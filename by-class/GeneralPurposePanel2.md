*** UID:00005R | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class GeneralPurposePanel2 : public LObject, public Singleton<GeneralPurposePanel2>
{
public:
    GeneralPurposePanel2();
    virtual ~GeneralPurposePanel2();

    Pane *GetChildPaneByIndex(int index);
    Pane *GetActiveChildPane();
    void DispatchActiveChildRefresh();
    void SwitchActiveChild(
        int childIndex,
        const unsigned char *packetData);

private:
    Pane *m_childPanes[1];
    int m_activeChildIndex;
};

extern GeneralPurposePanel2 *g_pGeneralPurposePanel2;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# GeneralPurposePanel2

## Status

- Confidence: very strong for direct bases, 12-byte PMD/EBO layout, singleton ownership, vtable identity, one-element Pane child array, concrete `NewSystemMessagePane` composition, all six human method declarations/bodies, pointer activation contract, and source route.
- Likely source file: [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md)
- Main address doc: [UID:00015V][0x004b83d0-0x004b8bd3.GeneralPurposePanel](by-memory/0x004b83d0-0x004b8bd3.GeneralPurposePanel.md)

## Functionality

`GeneralPurposePanel2` is a 12-byte smaller alternate general-purpose panel shell with direct `LObject` and `Singleton<GeneralPurposePanel2>` bases. It constructs one `NewSystemMessagePane` behind `Pane *m_childPanes[1]`, tracks a signed active index, exposes child/active-child/refresh helpers, and switches the one child. Singleton publication and clear are implicit compiler/template base behavior rather than handwritten assignments.

## Direct Bases And Complete Layout

- RTTI hierarchy contains exactly `GeneralPurposePanel2`, `LObject`, and `Singleton<GeneralPurposePanel2>`; no `PanelPane` descriptor exists and construction calls no `PanelPane` constructor.
- The Singleton PMD is `{4,-1,0}`. A `0x0c` allocation plus fields at `+0x04` and `+0x08` proves MSVC empty-base optimization overlaps the empty Singleton subobject with `m_childPanes[0]`.
- Source `sizeof(GeneralPurposePanel2)` is therefore 12 bytes: compiler vptr at `+0x00`, `Pane *m_childPanes[1]` at `+0x04`, and `int m_activeChildIndex` at `+0x08`.
- `PanelPane` inheritance in the former declaration is a superseded historical assumption. Consumer/dependency relationships to panes do not establish a base class.

## Method Map

| Method | Address | Notes |
| --- | --- | --- |
| [UID:0004UU][0x004b8830-0x004b88e1.GeneralPurposePanel2Constructor](by-memory/0x004b8830-0x004b88e1.GeneralPurposePanel2Constructor.md) | `0x004b8830-0x004b88e1` | Initializes the direct Singleton/index and constructs one `NewSystemMessagePane`; publication/vptr/EH are compiler lowering. |
| [UID:0004UV][0x004b88f0-0x004b8944.GeneralPurposePanel2Destructor](by-memory/0x004b88f0-0x004b8944.GeneralPurposePanel2Destructor.md) | `0x004b88f0-0x004b8944` | Unconditionally requests child deletion; Singleton clear/LObject teardown are implicit. |
| [UID:0004UW][0x004b8950-0x004b8969.GeneralPurposePanel2GetChildPaneByIndex](by-memory/0x004b8950-0x004b8969.GeneralPurposePanel2GetChildPaneByIndex.md) | `0x004b8950-0x004b8969` | Exact upper-bound-only one-child accessor with nine calls. |
| [UID:0004UX][0x004b8970-0x004b8980.GeneralPurposePanel2GetActiveChildPane](by-memory/0x004b8970-0x004b8980.GeneralPurposePanel2GetActiveChildPane.md) | `0x004b8970-0x004b8980` | Exact retained `-1`-sentinel active-child accessor; current IDA lacks a function/xref model. |
| [UID:0004UY][0x004b8980-0x004b8994.GeneralPurposePanel2DispatchActiveChildRefresh](by-memory/0x004b8980-0x004b8994.GeneralPurposePanel2DispatchActiveChildRefresh.md) | `0x004b8980-0x004b8994` | Exact retained active-child `InvalidateRect(NULL)` dispatcher; current IDA lacks a function/xref model. |
| active switch helper | [UID:00015Y][0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild](by-memory/0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild.md) | IDA-confirmed one-child activation/layout helper. |
| [UID:0004UZ][0x004b8aa0-0x004b8b32.GeneralPurposePanel2ScalarDeletingDestructor](by-memory/0x004b8aa0-0x004b8b32.GeneralPurposePanel2ScalarDeletingDestructor.md) | `0x004b8aa0-0x004b8b32` | Compiler-only deleting wrapper; ordinary UID0004UV is sole handwritten destructor. |

## Field Layout And Draft Code Direction

The declaration-level C++ is emitted because class ownership, the one-child layout, singleton route, and file placement are strong. Exact method bodies remain on child pages. The class closes before `[[CHILDREN]]` so validator emission places those definitions outside the declaration.

| Offset | Source-facing field | Evidence |
| --- | --- | --- |
| `+0x00` | compiler vptr | Stores vtable base `0x0061a898` from constructor, destructor, and scalar deleting destructor paths; not a handwritten field. |
| `+0x04` | `m_childPanes[1]` | Switch/accessor code uses scaled `this[index+1]` addressing. Constructor element zero allocates `0x304` / 772 bytes and calls `NewSystemMessagePane::NewSystemMessagePane()` at `0x00588560`; the concrete object identity does not require a singular source field. |
| `+0x08` | `m_activeChildIndex` | Initialized to `-1`; the accessor/switch helpers accept only child index `0`. |

## IDA Evidence

Live IDA MCP recheck on 2026-06-04 used `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.

- `0x004b8830` calls the panel base constructor `0x004f4a80`, writes `dword_69B358` at `0x004b8872` / `0x004b8879`, stores `GeneralPurposePanel2::vftable` at `0x004b888c`, initializes the active index field at `this+8` to `-1`, allocates `0x304` bytes, and calls `0x00588560` for the single child.
- `0x00588560` has a single direct caller at `0x004b88ae` from this constructor. Live decompilation shows it installs `NewSystemMessagePane` vtables and maintains `g_pNewSystemMessagePane`, confirming the child identity rather than only a generic pane allocation.
- `0x0061a894` / `0x0061a898` are the adjacent RTTI/vtable records for `GeneralPurposePanel2`; vtable stores occur from constructor/destructor/scalar-destructor paths at `0x004b888c`, `0x004b8915`, and `0x004b8ac5`.
- `g_pGeneralPurposePanel2` at `0x0069b358` has writes from constructor/destructor/clear/destructor-wrapper paths at `0x004b8872`, `0x004b8879`, `0x004b8925`, `0x004b8a80`, and `0x004b8adc`, plus read-side users in the `0x005a76c0` user-pane message handler family.
- `GetChildPaneByIndex` accepts only index `0`; live xrefs include `0x0050feff`, several calls inside `0x005a76c0`, and `0x005aace2`.
- The switch helper at `0x004b89a0` has one direct caller at `0x005a771b` and uses the same `this+8` active-index field and `this+4` child slot initialized by the constructor.
- Batch 118 live IDA `py_eval` corrected the switch helper boundary to `0x004b89a0-0x004b8a7f`; the final byte at `0x004b8a7e` is part of the `retn 8` immediate, followed by `0xcc` alignment. This supports retaining the helper as a direct `GeneralPurposePanel2` method rather than a sibling free helper.

## Global Lifecycle And Consumer Boundary

- [UID:0000R1][g_pGeneralPurposePanel2](by-global/g_pGeneralPurposePanel2.md) is the sole external zero definition at source position 20; this class supplies one matching extern after the complete declaration.
- The physical slot has exactly 14 references: constructor publication/fallback, ordinary/unwind/scalar clears, and nine MapPane/UserPane reads at `0x005049ee`, `0x0050fef7`, `0x005a7711`, `0x005a792e`, `0x005a7ed5`, `0x005a7fb9`, `0x005a9143`, `0x005aac2b`, and `0x005aacda`.
- Consumers use child zero for NewSystemMessagePane teardown, stop/reset, text/update, code-to-message, and `RefreshSpelledPane` behavior. They do not own this class or its global.
- Constructor publication, ordinary/unwind/scalar clears, vptr/EH transitions, delete flags, size checks, vtable/RTTI bytes, and alignment are compiler output excluded from source.

## Assignment Decision

Canonical owner/emitter remains [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md). The class is now `92/94`, emits at source position 30, and is source-complete through six exact method children. Original spelling uncertainty caps confidence below final-audit grades but no longer leaves a source/body blocker.

## 2026-07-13 B004 Accepted Declaration Reconciliation

- [UID:00015Y][0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild](by-memory/0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild.md) now emits the behavior-complete `void SwitchActiveChild(int childIndex, const unsigned char *packetData)` definition.
- `m_childPanes[1]` is required by scaled old/new child accesses and `GetChildPaneByIndex`. `NewSystemMessagePane` remains the constructor-proven concrete type at element zero and the child feature identity in prose.
- The second argument is a nullable packet pointer because inherited `OnActivate` overrides include packet parsers; the sole UserPane initialization caller passes null. Historical `bool showChild` wording is superseded.
- `m_activeChildIndex` remains at `+0x08`, initialized to `-1` and consumed as a signed index. No additional field, ownership flag, or lower-bound guard is introduced.
- The class block closes before a blank line and `[[CHILDREN]]`. This preserves declarations inside the class and routes UID00015Y outside it in generated `GeneralPurposePanel.cpp`.
- UID0004KU `Pane::Collapse`, Pane `OnActivate`, RectBounds, layer/context globals, TotemFrame, and FrameChrome remain dependencies. Their definitions do not belong in this class block.
- Score `90/92` reflects resolved layout, declaration, exact method child, ABI, caller, vtable, singleton, and file route. Original spellings and unsplit constructor/destructor/accessor bodies remain confidence/completion caps.

## 2026-07-21 B005 Complete Source Closure

- Serially registered UID0004UU-UID0004UZ for the exact constructor, ordinary destructor, child accessor, active accessor, refresh dispatcher, and scalar wrapper ranges.
- The first five source-bearing pages plus UID00015Y emit one definition each through `[[CHILDREN]]`; UID0004UZ remains false/non-emitting compiler support.
- Replaced `PanelPane` with RTTI-proven direct `LObject` and `Singleton<GeneralPurposePanel2>` bases, added the two formerly unmodeled method declarations, and added the external global declaration after the class.
- Preserved the accepted one-child array, active index, nullable packet contract, switch body, dependency boundaries, and historical declaration evolution without handwritten compiler mechanics.

## Cross References

- [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md)
- [UID:00005Q][GeneralPurposePanel](by-class/GeneralPurposePanel.md)
- [UID:0000R1][g_pGeneralPurposePanel2](by-global/g_pGeneralPurposePanel2.md)
- [UID:00015Y][0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild](by-memory/0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild.md)
- [UID:0004UU][0x004b8830-0x004b88e1.GeneralPurposePanel2Constructor](by-memory/0x004b8830-0x004b88e1.GeneralPurposePanel2Constructor.md)
- [UID:0004UV][0x004b88f0-0x004b8944.GeneralPurposePanel2Destructor](by-memory/0x004b88f0-0x004b8944.GeneralPurposePanel2Destructor.md)
- [UID:0004UW][0x004b8950-0x004b8969.GeneralPurposePanel2GetChildPaneByIndex](by-memory/0x004b8950-0x004b8969.GeneralPurposePanel2GetChildPaneByIndex.md)
- [UID:0004UX][0x004b8970-0x004b8980.GeneralPurposePanel2GetActiveChildPane](by-memory/0x004b8970-0x004b8980.GeneralPurposePanel2GetActiveChildPane.md)
- [UID:0004UY][0x004b8980-0x004b8994.GeneralPurposePanel2DispatchActiveChildRefresh](by-memory/0x004b8980-0x004b8994.GeneralPurposePanel2DispatchActiveChildRefresh.md)
- [UID:0004UZ][0x004b8aa0-0x004b8b32.GeneralPurposePanel2ScalarDeletingDestructor](by-memory/0x004b8aa0-0x004b8b32.GeneralPurposePanel2ScalarDeletingDestructor.md)

## Changes

- 2026-07-13 B004 accepted UID00015Y callback: raised `85/90 -> 90/92`; replaced singular `m_systemMessagePane` and `bool showChild` with `Pane *m_childPanes[1]` and nullable packet data; closed the class before `[[CHILDREN]]`; preserved concrete NewSystemMessagePane construction, singleton/vtable evidence, owner/emitter, and unrelated class history.
- 2026-06-20 B003 Rule 26 source-quality incorporation: added declaration-level draft C++, switched constructor/destructor/accessor ranges to half-open boundaries, accepted `m_systemMessagePane` and `m_activeChildIndex`, and recorded that method bodies should stay on exact child pages or deferred splits until helper/caller names are final enough. Score unchanged because final public method spelling remains heuristic.
- 2026-06-08 A006 Batch 118 parent-gate repair:
  - Changed score from `84/90` to `85/90`.
  - Summary/evidence: corrected and attached [UID:00015Y][0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild](by-memory/0x004b89a0-0x004b8a7f.GeneralPurposePanel2SwitchActiveChild.md), including the final `retn` byte in the exact range. The helper's one-child bounds check, `this+8` active index, `this+4` child slot, sole `UserPane` caller, and frame-refresh dependency all match this class, while the file parent now clears the corrected gate.
- 2026-06-04: Raised completion/confidence from `72/78` to `84/90`. Summary/evidence: live IDA MCP confirmed the exact `GeneralPurposePanel2` constructor/destructor/accessor/switch/scalar-destructor family, vtable stores, singleton writes/reads, constructor caller from `InitializeMainUiGraph`, direct switch caller from the user-pane message handler, and the single child constructor at `0x00588560` as `NewSystemMessagePane`. Completion remains below final-source quality because final public method names and all higher-level user-message call semantics still need deeper reconstruction.
- Completion/confidence score update: existed before as `0/0`; changed to `72/78`. Summary: alternate one-child panel role, singleton, core methods, and missing active-switch helper are documented; exact feature meaning of the single child pane remains medium-confidence. Evidence: shared `GeneralPurposePanel` memory page, `GeneralPurposePanel2SwitchActiveChild`, and `g_pGeneralPurposePanel2`.
- 2026-06-05: Marked reconstructable and attached to [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md) because the class is `84/90` and the parent is `84/80`, satisfying the 80/80 parent gate. Live IDA MCP `lookup_funcs` confirms exact starts at `0x004b8830`, `0x004b88f0`, `0x004b8950`, `0x004b89a0`, and `0x004b8aa0`; current `callers` confirms the constructor reference from `InitializeMainUiGraph` at `0x004f8020`.
- 2026-07-21 B005 accepted UID0002VS callback: raised `90/92 -> 92/94`, set source position 30, replaced false `PanelPane` inheritance with direct `LObject` and `Singleton<GeneralPurposePanel2>`, completed the six-method declaration, added the extern, linked six exact registered splits, and documented the 12-byte PMD/EBO layout, lifecycle, consumers, compiler exclusions, negative evidence, and superseded assumptions.
