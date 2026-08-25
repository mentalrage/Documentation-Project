*** UID:00006B | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// IconsPane declarations are emitted in IconsPane.h; exact child pages emit method definitions.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class PaneMouseEvent;

class IconsPane : public Pane, public Singleton<IconsPane>
{
public:
    IconsPane();
    virtual ~IconsPane();

    bool IsShowingAllIcons() const;
    void ShowAllIcons();
    void ShowReducedIcons();

protected:
    virtual bool OnMouseEvent(const PaneMouseEvent *event);
    virtual void OnPaint();

private:
    int HitTestIcon(int y, int x);
    void SetIconHighlight(bool isPressed);

    bool m_showAllIcons;
    int m_selectedIconIndex;
    bool m_isPressed;
};

extern IconsPane *g_pIconsPane;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# IconsPane

## Status

- Confidence: very strong for behavior, exact direct inheritance, seven-base RTTI, `0x104` EBO layout, constructor/destructor source shape, three-view vtable causality, singleton/resource/file ownership, complete declaration, canonical member/config names, and exact child source. Remaining uncertainty is limited to original lexical/access/include spelling and unrelated retained raw action-helper naming.
- Projected generated files: `NexusTK/ui/panels/IconsPane.h` and `NexusTK/ui/panels/IconsPane.cpp`.
- Likely source module: [UID:0000JZ][IconsPane](by-file/IconsPane.md)
- Core range: [UID:00016Z][0x004cf1f0-0x004cf8d5.IconsPaneCore](by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md)
- Retained raw action-dispatch helper: [UID:00022Q][0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody](by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md)
- Split destructor tail inventory: [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md)
- Singleton global: [UID:0000R6][g_pIconsPane](by-global/g_pIconsPane.md)
- Resource doc: [UID:0001RD][iconspane-icon-resources](by-resource/iconspane-icon-resources.md)
- Evidence basis: IDA MCP checks, current generated source, and linked exact memory pages.

## Responsibility

`IconsPane` is the old-layout icon-strip HUD pane. It paints a row of icon buttons, switches between full and reduced visibility, tracks click/pressed state, shows localized tooltips, and dispatches the corresponding game UI actions.

## Layout Evidence

- Direct source bases are `Pane` and empty `Singleton<IconsPane>`. `GrafPort`, `LObject`, `EventHandler`, and `TimerHandler` are inherited through `Pane`; they are present in the seven-entry RTTI hierarchy but must not be repeated as direct source bases.
- `Pane` occupies `[+0x00,+0xf8)`. Empty-base optimization places direct `Singleton<IconsPane>` at `+0xf8`, overlapping the first IconsPane-owned byte without increasing object size.
- Constructor writes vtables at object offsets `0x0`, `0xa0`, and `0xa4`.
- `m_showAllIcons` lives at object offset `0xf8`.
- `m_selectedIconIndex` lives at object offset `0xfc`.
- `m_isPressed` / highlight state lives at object offset `0x100`.
- `OnPaint` also clears inherited draw/blit-mode byte `this+0x70` before drawing. The exact original field spelling is not proven; current source-facing child C++ uses inferred `m_drawMode` and documents it as inherited draw state rather than an `IconsPane`-unique member.
- Icon rectangles are fixed at 20-pixel horizontal slots, `0..19`, `20..39`, and so on up to `159`, with height `14`. `HitTestIcon` passes coordinates to the shared RectBounds point test as vertical `y` first and horizontal `x` second.
- The retained no-route helper at `0x004cf7a0-0x004cf7c9` confirms the same source geometry: `{left=index*20, top=0, right=index*20+19, bottom=14}`.
- Vtable addresses observed by IDA: `0x0061b448`, `0x0061b494`, and `0x0061b4c4`.
- Exact source layout is `m_showAllIcons` at `+0xf8`, natural padding through `+0xfc`, `m_selectedIconIndex` at `+0xfc`, `m_isPressed` at `+0x100`, and total size `0x104`.

## Inheritance, RTTI, And Three-View Causality

- [UID:0003BN][0x0061b444-0x0061b4cc.IconsPaneVtableData](by-memory/0x0061b444-0x0061b4cc.IconsPaneVtableData.md) records the complete type descriptor, seven-base hierarchy, all three complete-object-locator pointers, and all 31 vtable slots.
- The primary Pane-facet table is `[0x0061b448,0x0061b490)` with 18 slots; `IconsPane::OnPaint` is the human override at cell `0x0061b48c`.
- The inherited EventHandler-facet table is `[0x0061b494,0x0061b4c0)` at complete-object offset `+0xa0` with 11 slots; `IconsPane::OnMouseEvent` is the human override at cell `0x0061b498`.
- The inherited TimerHandler-facet table is `[0x0061b4c4,0x0061b4cc)` at complete-object offset `+0xa4` with two slots; `Pane::OnTimer` remains inherited.
- Constructor, ordinary destructor, and scalar deleting wrapper each install all three views. The two secondary deleting-destructor cells use compiler adjustors for `this-0xa0` and `this-0xa4`.
- `OnPaint` and `OnMouseEvent` have exact vtable data xrefs and no direct callers, proving virtual liveness. The compiler regenerates RTTI, vtables, adjustors, deleting wrapper, and vptr stores from the class declaration and method definitions.

## Important Methods

| Range doc | Current name | Notes |
| --- | --- | --- |
| [UID:0002SW][0x004cf1f0-0x004cf25d.IconsPaneConstructor](by-memory/0x004cf1f0-0x004cf25d.IconsPaneConstructor.md) | constructor | Formal source is `IconsPane::IconsPane() : Pane(1), m_showAllIcons(!g_pConfig->m_iconPaneReducedMode), m_selectedIconIndex(-1), m_isPressed(false) {}`. Singleton publication and all three vptr stores are direct-base/compiler lowering, not handwritten constructor statements. |
| [UID:0002SX][0x004cf260-0x004cf289.IconsPaneCleanupHelper](by-memory/0x004cf260-0x004cf289.IconsPaneCleanupHelper.md) | ordinary destructor body | Formal human source is the empty `IconsPane::~IconsPane() {}` body. MCP session `73c77998` reconfirmed the exact `0x29` range, three vtable restores, singleton clear, tail transfer to `0x00544580`, no inbound xrefs, and local PE zero-route evidence; every observed instruction is compiler/direct-base/inherited-base destructor lowering rather than a called `Cleanup` method or handwritten clear. |
| [UID:0002SY][0x004cf290-0x004cf297.IconsPaneIsShowingAllIcons](by-memory/0x004cf290-0x004cf297.IconsPaneIsShowingAllIcons.md) | `IsShowingAllIcons` | Formal first-draft C++ is present in the exact child; returns `m_showAllIcons` from `this+0xf8`. |
| [UID:0002SZ][0x004cf2a0-0x004cf2c6.IconsPaneShowAllIcons](by-memory/0x004cf2a0-0x004cf2c6.IconsPaneShowAllIcons.md) | `ShowAllIcons` | Formal first-draft C++ is present in the exact child. It switches from reduced mode to all-icons mode only when `m_showAllIcons` is false, persists `g_pConfig->m_iconPaneReducedMode = 0`, sets `m_showAllIcons = true`, and invalidates `m_bounds`. |
| [UID:0002T0][0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons](by-memory/0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons.md) | `ShowReducedIcons` | Formal first-draft C++ is present in the exact child. It switches from all-icons mode to reduced mode only when `m_showAllIcons` is true, persists `g_pConfig->m_iconPaneReducedMode = 1`, clears `m_showAllIcons`, and invalidates `m_bounds`. |
| [UID:0002T1][0x004cf300-0x004cf3d3.IconsPaneOnPaint](by-memory/0x004cf300-0x004cf3d3.IconsPaneOnPaint.md) | `OnPaint` | First-draft C++ is present in the exact child. It initializes an EPF tile context, calls `SetDrawColor(0)`, clears inherited `this+0x70`/`m_drawMode`, prepares the pane region through Surface callback slot 7, draws `ICONS.EPD` frames through `NPAL7.PAL`, starts at icon `0` for full mode or `6` for reduced mode, and uses frame `index + 8` for the selected pressed icon. |
| [UID:0002T2][0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent](by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md) | `OnMouseEvent` | Formal first-draft C++ is present in the exact child. It preserves vertical-first `(y, x)` event coordinates, capture/down/up/hover flow, `m_selectedIconIndex` cleanup, `HitTestIcon`/`SetIconHighlight` helper calls, localized tooltip ids `202..209` with timeout `5000`, and the direct mouse-up action switch gated by `g_activeMapPane->m_inputLocked`. |
| `0x004cf74b-0x004cf7d0` | embedded tables/raw helper gap | `OnMouseEvent` switch-table data at `0x004cf74c-0x004cf7a0`, retained no-route icon-rectangle helper at `0x004cf7a0-0x004cf7c9`, and padding at `0x004cf7c9-0x004cf7d0`; needs exact child split rather than being folded into padding. |
| [UID:0002T3][0x004cf7d0-0x004cf862.IconsPaneHitTestIcon](by-memory/0x004cf7d0-0x004cf862.IconsPaneHitTestIcon.md) | `HitTestIcon` | Formal first-draft C++ is present in the exact child. It uses source shape `int IconsPane::HitTestIcon(int y, int x)`, preserves vertical-first/horizontal-second `PointInRect` order, tests 20-pixel slots with `{left=iconX, top=0, right=iconX+19, bottom=14}`, returns the icon index on hit, and returns signed `-1` on miss; reduced mode starts at icon `6`. |
| [UID:0002T4][0x004cf870-0x004cf8d5.IconsPaneSetIconHighlight](by-memory/0x004cf870-0x004cf8d5.IconsPaneSetIconHighlight.md) | `SetIconHighlight` | Formal first-draft C++ is present in the exact child. It compares requested pressed state with `m_isPressed`, builds the selected icon rectangle from `m_selectedIconIndex` with `{left=index*20, top=0, right=left+19, bottom=14}`, invalidates it through inherited `InvalidateRect`, and then stores the new `m_isPressed` state. |
| [UID:00022Q][0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody](by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md) | retained raw action dispatch helper | First-draft `static void __stdcall DispatchIconsPaneAction(int action)` source is present in the exact child. It is an `IconsPane.cpp` file-local helper shape with exact body/table evidence, local jump table, and no IDA function object/direct external xrefs/address-taken route. |
| [UID:00034T][0x004cfd6c-0x004cfd82.IconsPaneDestructorAdjustorThunks](by-memory/0x004cfd6c-0x004cfd82.IconsPaneDestructorAdjustorThunks.md) | adjustor thunks | Compiler-generated `this - 0xa0`/`this - 0xa4` forwards to the scalar deleting destructor; non-reconstructable and parent-blank. |
| [UID:00034V][0x004cfda0-0x004cfdff.IconsPaneScalarDeletingDestructor](by-memory/0x004cfda0-0x004cfdff.IconsPaneScalarDeletingDestructor.md) | scalar deleting destructor | Compiler wrapper support with comment-only formal C++; preserves vtable restores, singleton clear, shared cleanup, scalar-delete flags, optional free, guard path, adjustor-thunk refs, and primary vtable ref without emitting a duplicate `IconsPane::~IconsPane()` body. |

## External State

- [UID:0000R6][g_pIconsPane](by-global/g_pIconsPane.md) at `0x0069b41c`; constructor publication and destructor clearing are generated by direct `Singleton<IconsPane>` base lifecycle, not explicit statements in the human `IconsPane` bodies.
- `g_pConfig` / `dword_67A7C8`; persisted IconsPane reduced-display-mode byte at offset `0x28de32`, best named `m_iconPaneReducedMode` because stored `0` means full/all icons and stored `1` means reduced/two-icon strip. `IconsPane::m_showAllIcons` stores the inverse runtime bool. Use neutral `m_iconPaneDisplayMode` only if final `Config` naming prefers mode/value fields.
- `g_pEPFLib` / `dword_67A744`; resource manager for `ICONS.EPD`.
- `SurfaceRenderCallbackTable` slot `dword_69B3FC`; `OnPaint` uses it as pane-region preparation/fill/presentation after clearing draw state. Do not carry forward stale generated `g_pfnLockSurface` wording for this callsite.
- `g_pLanguageMan` / `dword_67A750`; localized tooltip ids `202..209`.
- `g_activeMapPane` input-lock byte at `dword_67A764 + 1008`; final source should use an active-map field/accessor such as `g_activeMapPane->isInputLocked` or `IsInputLocked()`, not a standalone `g_isInputLocked` global.
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / historical `dword_67A748` (older generated `g_pAppMan` label); passed to selected action helpers.

## Source-Quality Decisions And Remaining Caveats

- The complete human declaration lives in the formal H channel. The class CPP channel emits only the accepted topology comment because exact method children own all definitions; this is declaration ownership, not a missing-code blocker.
- `m_iconPaneReducedMode`, `m_showAllIcons`, `m_selectedIconIndex`, and `m_isPressed` are the accepted current source-facing names. They are evidence-backed human inferences rather than recovered symbols, but raw offsets/decompiler labels are rejected.
- Direct `Singleton<IconsPane>` plus empty-base optimization resolves singleton publication/clear as implicit base lifecycle. The prior blank-declaration, explicit `g_pIconsPane` lifecycle, and unresolved-config assumptions are preserved only as superseded history in `Changes`.
- No flat IDA UDT should be created as documentary source authority: it would hide direct/inherited base structure and EBO. Lack of that UDT does not block the declaration, ownership, scores, or source.
- The core range has exact modeled method children plus one known table/raw-helper gap. B003's 2026-06-19 PE/Capstone pass proved `0x004cf74b-0x004cf7d0` is not ordinary padding: it contains embedded `OnMouseEvent` event/tooltip/click switch tables, a no-route `BuildIconRectForIndex`-style helper, and seven bytes of padding. Until new exact child pages are allocated, class docs should keep this gap visible in the method/data inventory.
- [UID:0002SX][0x004cf260-0x004cf289.IconsPaneCleanupHelper](by-memory/0x004cf260-0x004cf289.IconsPaneCleanupHelper.md) is the ordinary/non-deleting `IconsPane::~IconsPane()` body: exact `0x29` range, five instructions, boundary padding, three `IconsPane` vtable stores, `g_pIconsPane` clear, tail jump to `0x00544580`, zero inbound xrefs, local PE zero-route checks, and no recovered local UDT. Direct `Singleton<IconsPane>` and Pane teardown account for the complete lowering, so the exact child emits an empty human destructor; the earlier explicit singleton-clear draft is superseded history.
- [UID:00034V][0x004cfda0-0x004cfdff.IconsPaneScalarDeletingDestructor](by-memory/0x004cfda0-0x004cfdff.IconsPaneScalarDeletingDestructor.md) is now support-only for scalar-wrapper evidence. Its formal C++ is comment-only so generated output has one `IconsPane::~IconsPane()` body sourced from UID0002SX, while the wrapper page keeps the scalar-delete flags, optional free, guard path, adjustor-thunk refs, vtable ref, vtable restores, and binary singleton clear.
- [UID:0002SY][0x004cf290-0x004cf297.IconsPaneIsShowingAllIcons](by-memory/0x004cf290-0x004cf297.IconsPaneIsShowingAllIcons.md) is no longer blocked by the old blank-C++/95+ gate wording. B001's 2026-06-26 MCP-backed implementation pass reconfirmed the exact `0x7`-byte body, bytes `8a 81 f8 00 00 00 c3`, one OptionPane constructor caller at `0x0053da83`, no callees, zero refs to padding, and no direct VA/RVA pointer route. The exact child now emits `bool IconsPane::IsShowingAllIcons() const { return m_showAllIcons; }`; the accepted source-facing field name remains `m_showAllIcons`, while raw `this[248]`, `mbr_0xf8`, `m_iconMode`, config-side `m_iconPaneReducedMode`, and inverted `IsReducedIconMode` wording are rejected for this object field/accessor.
- [UID:0002SZ][0x004cf2a0-0x004cf2c6.IconsPaneShowAllIcons](by-memory/0x004cf2a0-0x004cf2c6.IconsPaneShowAllIcons.md) is likewise no longer blocked by the old blank-C++/broader field-helper gate. B001's 2026-06-26 MCP-backed implementation pass reconfirmed `sub_4CF2A0` size `0x26`, exact bytes `80 b9 f8 00 00 00 00 75 1c a1 c8 a7 67 00 c6 80 32 de 28 00 00 8d 41 44 8b 11 50 c6 81 f8 00 00 00 01 ff 52 20 c3`, ten bytes of `0xcc` padding before [UID:0002T0][0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons](by-memory/0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons.md), one OptionPane apply caller at `0x0053ded2`, no VA/RVA pointer hits to the function start, and sibling [UID:0002SY][0x004cf290-0x004cf297.IconsPaneIsShowingAllIcons](by-memory/0x004cf290-0x004cf297.IconsPaneIsShowingAllIcons.md)/[UID:0002T0][0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons](by-memory/0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons.md) polarity evidence. The exact child now emits `void IconsPane::ShowAllIcons()` using `m_showAllIcons`, `g_pConfig->m_iconPaneReducedMode`, `m_bounds`, and inherited `InvalidateRect`; raw `dword_67A7C8`, raw `this+0xf8`, raw virtual-call syntax, and blank C++ are rejected for this target.
- [UID:0002T0][0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons](by-memory/0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons.md) is likewise no longer blocked by the old blank-C++/broader field-helper gate. B004's 2026-06-26 MCP-backed implementation pass reconfirmed `sub_4CF2D0` size `0x26`, exact bytes `80 b9 f8 00 00 00 01 75 1c a1 c8 a7 67 00 c6 80 32 de 28 00 01 8d 41 44 8b 11 50 c6 81 f8 00 00 00 00 ff 52 20 c3`, ten bytes of `0xcc` padding before [UID:0002T1][0x004cf300-0x004cf3d3.IconsPaneOnPaint](by-memory/0x004cf300-0x004cf3d3.IconsPaneOnPaint.md), one OptionPane apply caller at `0x0053dee0`, no VA/RVA pointer hits to the function start, and sibling [UID:0002SY][0x004cf290-0x004cf297.IconsPaneIsShowingAllIcons](by-memory/0x004cf290-0x004cf297.IconsPaneIsShowingAllIcons.md)/[UID:0002SZ][0x004cf2a0-0x004cf2c6.IconsPaneShowAllIcons](by-memory/0x004cf2a0-0x004cf2c6.IconsPaneShowAllIcons.md) polarity evidence. The exact child now emits `void IconsPane::ShowReducedIcons()` using `m_showAllIcons`, `g_pConfig->m_iconPaneReducedMode`, `m_bounds`, and inherited `InvalidateRect`; raw `dword_67A7C8`, raw `this+0xf8`, raw virtual-call syntax, no-argument invalidation, and blank C++ are rejected for this target.
- [UID:0002T1][0x004cf300-0x004cf3d3.IconsPaneOnPaint](by-memory/0x004cf300-0x004cf3d3.IconsPaneOnPaint.md) is no longer blocked by the old blanket 95+ or helper-name gate. The exact child clears the current code-entry rule and carries first-draft C++ using source-facing helper names. The remaining helper spelling caveats are shared support issues and should not be applied to the raw action dispatch or table/raw-helper gap.
- [UID:0002T2][0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent](by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md) now carries formal first-draft C++ after B001's 2026-07-04 callback using accepted MCP session `60724697` evidence. The child keeps the exact `0x004cf3e0-0x004cf74b` range, `IconsPane` owner/emitter route, vtable data xref `0x0061b498`, vertical-first coordinate order, direct mouse-up action switch, input-lock gate, tooltip constants, and no-route caveats for adjacent `0x004cf7a0` and `0x004cf8e0`. Event/capture/helper names remain inferred first-draft names rather than recovered original symbols.
- [UID:0002T3][0x004cf7d0-0x004cf862.IconsPaneHitTestIcon](by-memory/0x004cf7d0-0x004cf862.IconsPaneHitTestIcon.md) is likewise no longer blocked by the stale coordinate-order or blank-C++ notes. B012's accepted MCP pass resolved the helper signature as vertical-first `y`, horizontal-second `x`, matching RectBounds `PointInRect(y, x, rect)` and the `OnMouseEvent` coordinate flow. This does not change the wider `OnMouseEvent` action-dispatch and table/raw-helper caveats.
- [UID:0002T4][0x004cf870-0x004cf8d5.IconsPaneSetIconHighlight](by-memory/0x004cf870-0x004cf8d5.IconsPaneSetIconHighlight.md) is now first-draft populated in the exact child. B012's accepted MCP pass resolved the old field/invalidation blockers: `+0xfc` is `m_selectedIconIndex`, `+0x100` is `m_isPressed`, source-facing rectangle setup uses `InitRectBounds`, and the repaint route is inherited `Pane::InvalidateRect` through primary slot `+0x20`. The child preserves the binary's store-after-invalidate order and rejects raw `sub_4CF870`, `int` return, pre-store ordering, hidden `-1` guard, `m_highlightedIcon`, and merges with `OnMouseEvent`, `0x004cf7a0`, or `0x004cf8e0`.
- B002/B003 source-quality audits give behavior names for the eight click-action callees rather than final UI-label names: `SwitchGeneralPurposePanelMode2WithClickSound`, `SwitchGeneralPurposePanelMode3WithClickSound`, `SendOpcode2DAndStoreExtra(0)`, `SyncNationEntriesOrDeferredState`, `EnsureNormalBulletinSession`, `OpenInputPaneForCurrentSayMode`, `SendOpcode43MinusOneRequest`, and `OpenQuitPrompt` / `OpenQuitPromptThunk`. These are descriptive names backed by callee behavior and shared caller fan-in; icon-local labels such as `OpenArrangeDialog`, `OpenOptionsDialog`, `OpenExchangeDialog`, `OpenMailDialog`, and `OpenQuestDialog` are rejected.
- [UID:00022Q][0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody](by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md) remains executable retained raw code with no entry xrefs, no VA/RVA pointer hits, and no direct branches to `0x004cf8e0`; the only `0x004cf954` pointer is the local switch table. It now carries first-draft formal C++ as a retained file-local `DispatchIconsPaneAction(int action)` helper under `IconsPane.cpp`. Treat it as retained old-HUD action evidence mirrored by live `IconsPane::OnMouseEvent`, not as `TabPane` ownership, a new old-HUD source file, no-owner/non-emitting glue, or an address-shaped helper.
- Original physical grouping with [UID:0000EB][TabPane](by-class/TabPane.md) is still not symbol-proven. The best current source route remains [UID:0000JZ][IconsPane](by-file/IconsPane.md) because constructor vtables, `g_pIconsPane`, layout fields, resources, and exact children are IconsPane-specific; any later old-HUD grouping pass should not undo the class/source ownership without new evidence.

## Autogen Status

- Reconstructable: true, as an old-layout HUD panel class with IDA-backed constructor, methods, singleton, resources, and exact destructor evidence.
- Parent: [UID:0000JZ][IconsPane](by-file/IconsPane.md).
- Current declaration/source authority: the formal H channel emits the complete `IconsPane : Pane, Singleton<IconsPane>` declaration at source position `10`; the formal class CPP channel emits only `// IconsPane declarations are emitted in IconsPane.h; exact child pages emit method definitions.` because exact method children own definitions. [UID:0003BN][0x0061b444-0x0061b4cc.IconsPaneVtableData](by-memory/0x0061b444-0x0061b4cc.IconsPaneVtableData.md) is compiler-generated covered-by evidence at position `100`.
- Historical pre-UID0003BN callback aggregate C++ summary follows. Its explicit singleton-clear wording is retained only as historical trace and is superseded by the current empty-destructor/direct-Singleton decision.
- C++: class-level C++ is a topology comment only because the class page is an aggregate/declaration surface and exact emitting children carry source output. [UID:0002SX][0x004cf260-0x004cf289.IconsPaneCleanupHelper](by-memory/0x004cf260-0x004cf289.IconsPaneCleanupHelper.md) emits the empty human `IconsPane::~IconsPane()` source body; the binary singleton clear is direct `Singleton<IconsPane>`/compiler lifecycle lowering, not authored destructor source. [UID:00034V][0x004cfda0-0x004cfdff.IconsPaneScalarDeletingDestructor](by-memory/0x004cfda0-0x004cfdff.IconsPaneScalarDeletingDestructor.md) is comment-only scalar-wrapper support. [UID:0002SY][0x004cf290-0x004cf297.IconsPaneIsShowingAllIcons](by-memory/0x004cf290-0x004cf297.IconsPaneIsShowingAllIcons.md) has first-draft accessor C++ returning `m_showAllIcons`, [UID:0002SZ][0x004cf2a0-0x004cf2c6.IconsPaneShowAllIcons](by-memory/0x004cf2a0-0x004cf2c6.IconsPaneShowAllIcons.md) has first-draft full-mode mutator C++ persisting `g_pConfig->m_iconPaneReducedMode = 0`, setting `m_showAllIcons`, and invalidating `m_bounds`, [UID:0002T0][0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons](by-memory/0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons.md) has first-draft reduced-mode mutator C++ persisting `g_pConfig->m_iconPaneReducedMode = 1`, clearing `m_showAllIcons`, and invalidating `m_bounds`, [UID:0002T1][0x004cf300-0x004cf3d3.IconsPaneOnPaint](by-memory/0x004cf300-0x004cf3d3.IconsPaneOnPaint.md) has first-draft paint C++, [UID:0002T2][0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent](by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md) has first-draft mouse-event C++ with vertical-first coordinate order and direct action switch, [UID:0002T3][0x004cf7d0-0x004cf862.IconsPaneHitTestIcon](by-memory/0x004cf7d0-0x004cf862.IconsPaneHitTestIcon.md) has first-draft hit-test C++ with vertical-first coordinate order, [UID:0002T4][0x004cf870-0x004cf8d5.IconsPaneSetIconHighlight](by-memory/0x004cf870-0x004cf8d5.IconsPaneSetIconHighlight.md) has first-draft pressed/highlight invalidation C++, [UID:00022Q][0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody](by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md) has first-draft retained `DispatchIconsPaneAction` C++, and [UID:00016Z][0x004cf1f0-0x004cf8d5.IconsPaneCore](by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md) is marker-only as an aggregate.

## Cross-References

- [UID:0000JZ][IconsPane](by-file/IconsPane.md)
- [UID:00016Z][0x004cf1f0-0x004cf8d5.IconsPaneCore](by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md)
- [UID:00022Q][0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody](by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md)
- [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md)
- [UID:00034T][0x004cfd6c-0x004cfd82.IconsPaneDestructorAdjustorThunks](by-memory/0x004cfd6c-0x004cfd82.IconsPaneDestructorAdjustorThunks.md)
- [UID:00034V][0x004cfda0-0x004cfdff.IconsPaneScalarDeletingDestructor](by-memory/0x004cfda0-0x004cfdff.IconsPaneScalarDeletingDestructor.md)
- [UID:0000R6][g_pIconsPane](by-global/g_pIconsPane.md)
- [UID:0001RD][iconspane-icon-resources](by-resource/iconspane-icon-resources.md)
- [UID:0000EB][TabPane](by-class/TabPane.md)
- [UID:0002SW][0x004cf1f0-0x004cf25d.IconsPaneConstructor](by-memory/0x004cf1f0-0x004cf25d.IconsPaneConstructor.md)
- [UID:0002SX][0x004cf260-0x004cf289.IconsPaneCleanupHelper](by-memory/0x004cf260-0x004cf289.IconsPaneCleanupHelper.md)
- [UID:0002SY][0x004cf290-0x004cf297.IconsPaneIsShowingAllIcons](by-memory/0x004cf290-0x004cf297.IconsPaneIsShowingAllIcons.md)
- [UID:0002SZ][0x004cf2a0-0x004cf2c6.IconsPaneShowAllIcons](by-memory/0x004cf2a0-0x004cf2c6.IconsPaneShowAllIcons.md)
- [UID:0002T0][0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons](by-memory/0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons.md)
- [UID:0002T1][0x004cf300-0x004cf3d3.IconsPaneOnPaint](by-memory/0x004cf300-0x004cf3d3.IconsPaneOnPaint.md)
- [UID:0002T2][0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent](by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md)
- [UID:0002T3][0x004cf7d0-0x004cf862.IconsPaneHitTestIcon](by-memory/0x004cf7d0-0x004cf862.IconsPaneHitTestIcon.md)
- [UID:0002T4][0x004cf870-0x004cf8d5.IconsPaneSetIconHighlight](by-memory/0x004cf870-0x004cf8d5.IconsPaneSetIconHighlight.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)

## Changes

- 2026-08-17 B002 UID0002XU ordinary implementation callback:
  - Preserved completion/confidence `92/94`, owner/emitter UID0000JZ, source position `10`, reconstructable true, and the complete formal H declaration.
  - Added the exact class-CPP topology comment plus explicit `[[CHILDREN]]` aggregation directive, preserving every exact child-owned method definition after the validator's physical no-loss readback.
  - Reconciled current lifecycle source to the empty human destructor plus direct-Singleton/compiler singleton clearing; the 2026-07-04 explicit-clear source draft remains below only as dated superseded history.
- 2026-08-01 B001 UID0003BN ordinary implementation callback:
  - Changed completion/confidence from `87/89` to `92/94`, preserved owner/emitter UID0000JZ and reconstructable true, and set emitter position `10`.
  - Added the exact formal H declaration; at that dated stage kept class CPP blank because exact method children own definitions. The 2026-08-17 callback later added the topology-only class comment without moving any method definition.
  - Added direct Pane/Singleton inheritance, seven-base RTTI and inherited EventHandler/TimerHandler facets, exact `0x104` EBO layout, complete three-view source causality, vtable-only virtual liveness, implicit Singleton lifecycle, and the UID0003BN covered-by route.
  - Historicalized the former blank-declaration, explicit singleton publication/clear, unresolved config spelling, and flat-UDT assumptions. The accepted current names are `m_iconPaneReducedMode`, `m_showAllIcons`, `m_selectedIconIndex`, and `m_isPressed`; original spelling remains inferred rather than symbol-proven.
- 2026-07-04 B001 [UID:0002T2][0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent](by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md) first-draft implementation sync:
  - Score unchanged at `87/89`; class owner/emitter route through [UID:0000JZ][IconsPane](by-file/IconsPane.md) unchanged.
  - Summary/evidence: UID0002T2 now carries formal first-draft `IconsPane::OnMouseEvent` C++ after B001 MCP session `60724697` reconfirmed exact range `0x004cf3e0-0x004cf74b`, `sub_4CF3E0` size `0x36b`, vtable data xref `0x0061b498`, local event/tooltip/click switch tables, four hit-test and four highlight callsites, input-lock gate `dword_67A764 + 1008`, tooltip ids `202..209`, timeout `5000`, direct mouse-up action helper calls, and no xrefs/pointer routes to adjacent `0x004cf7a0` or `0x004cf8e0`.
  - Historical caveat scope: class-level C++ was blank at that dated stage because exact child pages emit source. Event/capture/helper names remain inferred, the `0x004cf74b-0x004cf7d0` table/raw-helper span still needs exact child allocation, and UID00022Q remains no-route retained duplicate evidence rather than a proven call target for `OnMouseEvent`. The current class CPP contains only the accepted topology comment.
- 2026-07-04 B014 UID0002SX destructor source-route sync (dated and superseded for authored destructor source by the current direct-Singleton/EBO reconstruction):
  - Score unchanged at `87/89`; class owner/emitter route through [UID:0000JZ][IconsPane](by-file/IconsPane.md) unchanged.
  - Historical summary/evidence: accepted report `0002SX-IconsPaneCleanupHelper-source-quality.md` and MCP session `73c77998` resolved [UID:0002SX][0x004cf260-0x004cf289.IconsPaneCleanupHelper](by-memory/0x004cf260-0x004cf289.IconsPaneCleanupHelper.md) as the ordinary/non-deleting `IconsPane::~IconsPane()` body and at that stage proposed formal C++ `g_pIconsPane = NULL;`. The support sync preserved exact range `0x004cf260-0x004cf289`, five-instruction body, boundary padding, vtable stores, singleton clear, tail jump to `0x00544580`, zero inbound xrefs, local PE zero-route facts, no recovered UDT, and rejected `Cleanup`/UID00034V/no-owner alternatives. Current direct-Singleton/EBO causality accounts for those instructions and UID0002SX emits an empty human destructor instead.
  - Scalar wrapper sync: [UID:00034V][0x004cfda0-0x004cfdff.IconsPaneScalarDeletingDestructor](by-memory/0x004cfda0-0x004cfdff.IconsPaneScalarDeletingDestructor.md) now carries a comment-only formal marker so it preserves wrapper evidence without emitting a duplicate destructor body.
- 2026-06-27 B012 [UID:00022Q][0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody](by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md) first-draft retained helper sync:
  - Score unchanged at `87/89`; class owner/emitter route through [UID:0000JZ][IconsPane](by-file/IconsPane.md) unchanged.
  - Summary/evidence: [UID:00022Q][0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody](by-memory/0x004cf8e0-0x004cf974.IconsPaneActionDispatchRawBody.md) now carries first-draft formal C++ as retained `static void __stdcall DispatchIconsPaneAction(int action)` under the `IconsPane.cpp` file route. The class inventory preserves no-function/no-xref/no-address-taken evidence, exact body/table bytes, local-only jump-table references, downstream helper behavior, and rejected alternatives.
  - Historical caveat scope: class-level C++ was blank at that dated stage because this page is an aggregate; exact child pages own source emission. Final action-helper labels, the no-route explanation for `0x004cf8e0`, the `0x004cf74b-0x004cf7d0` child split, and physical grouping with [UID:0000EB][TabPane](by-class/TabPane.md) remain open. The current class CPP contains only the accepted topology comment.
- 2026-06-26 B004 ShowReducedIcons first-draft implementation sync:
  - Score unchanged at `87/89`.
  - Summary/evidence: [UID:0002T0][0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons](by-memory/0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons.md) now carries formal first-draft C++ after B004 MCP session `80de0a67` reconfirmed the exact `0x26`-byte body, bytes `80 b9 f8 00 00 00 01 75 1c a1 c8 a7 67 00 c6 80 32 de 28 00 01 8d 41 44 8b 11 50 c6 81 f8 00 00 00 00 ff 52 20 c3`, ten bytes of `0xcc` padding before [UID:0002T1][0x004cf300-0x004cf3d3.IconsPaneOnPaint](by-memory/0x004cf300-0x004cf3d3.IconsPaneOnPaint.md), the single OptionPane apply caller at `0x0053dee0`, no VA/RVA pointer hits to the function start, and sibling state evidence from [UID:0002SY][0x004cf290-0x004cf297.IconsPaneIsShowingAllIcons](by-memory/0x004cf290-0x004cf297.IconsPaneIsShowingAllIcons.md) and [UID:0002SZ][0x004cf2a0-0x004cf2c6.IconsPaneShowAllIcons](by-memory/0x004cf2a0-0x004cf2c6.IconsPaneShowAllIcons.md).
  - Source-quality scope: this resolves the old blank-C++/field-helper blocker for the exact reduced-mode mutator. `m_showAllIcons`, `g_pConfig->m_iconPaneReducedMode`, `m_bounds`, and inherited `InvalidateRect` are the accepted source-facing names for this child; class-level raw-dispatch, `0x004cf74b-0x004cf7d0` gap, final action-helper naming, and `TabPane` grouping caveats remain unchanged.
- 2026-06-26 B001 ShowAllIcons first-draft implementation sync:
  - Score unchanged at `87/89`.
  - Summary/evidence: [UID:0002SZ][0x004cf2a0-0x004cf2c6.IconsPaneShowAllIcons](by-memory/0x004cf2a0-0x004cf2c6.IconsPaneShowAllIcons.md) now carries formal first-draft C++ after B001 MCP session `80de0a67` reconfirmed the exact `0x26`-byte body, bytes `80 b9 f8 00 00 00 00 75 1c a1 c8 a7 67 00 c6 80 32 de 28 00 00 8d 41 44 8b 11 50 c6 81 f8 00 00 00 01 ff 52 20 c3`, ten bytes of `0xcc` padding before [UID:0002T0][0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons](by-memory/0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons.md), the single OptionPane apply caller at `0x0053ded2`, no VA/RVA pointer hits to the function start, and sibling state evidence from [UID:0002SY][0x004cf290-0x004cf297.IconsPaneIsShowingAllIcons](by-memory/0x004cf290-0x004cf297.IconsPaneIsShowingAllIcons.md) and [UID:0002T0][0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons](by-memory/0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons.md).
  - Source-quality scope: this resolves the old blank-C++/field-helper blocker for the exact full-mode mutator. `m_showAllIcons`, `g_pConfig->m_iconPaneReducedMode`, `m_bounds`, and inherited `InvalidateRect` are the accepted source-facing names for this child; class-level raw-dispatch, `0x004cf74b-0x004cf7d0` gap, final action-helper naming, and `TabPane` grouping caveats remain unchanged.
- 2026-06-26 B001 IsShowingAllIcons first-draft implementation sync:
  - Score unchanged at `87/89`.
  - Summary/evidence: [UID:0002SY][0x004cf290-0x004cf297.IconsPaneIsShowingAllIcons](by-memory/0x004cf290-0x004cf297.IconsPaneIsShowingAllIcons.md) now carries formal first-draft C++ after B001 MCP session `80de0a67` reconfirmed the exact `0x7`-byte body, bytes `8a 81 f8 00 00 00 c3`, decompile return `this[248]`, disassembly `mov al, [ecx+0F8h]; retn`, one OptionPane constructor caller at `0x0053da83`, no callees, zero xrefs to padding, and no direct VA/RVA pointer hits.
  - Source-quality scope: this resolves the old blank-C++/gate blocker for the exact leaf accessor and reuses the accepted `m_showAllIcons` field decision from constructor/mutator/paint/hit-test evidence. It does not change class-level raw-dispatch, `0x004cf74b-0x004cf7d0` gap, final action-helper naming, or `TabPane` grouping caveats.
- 2026-06-25 B012 SetIconHighlight first-draft implementation sync:
  - Score unchanged at `87/89`.
  - Summary/evidence: [UID:0002T4][0x004cf870-0x004cf8d5.IconsPaneSetIconHighlight](by-memory/0x004cf870-0x004cf8d5.IconsPaneSetIconHighlight.md) now carries formal first-draft C++ after B012 MCP session `80de0a67` reconfirmed `sub_4CF870` size `0x65`, four [UID:0002T2][0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent](by-memory/0x004cf3e0-0x004cf74b.IconsPaneOnMouseEvent.md) call xrefs with `true`/`true`/`false`/`false` argument values, `m_selectedIconIndex` at `+0xfc`, `m_isPressed` at `+0x100`, icon rectangle `{left=index*20, top=0, right=left+19, bottom=14}`, inherited `InvalidateRect` through vtable slot `+0x20`, store-after-invalidate order, unique range signature, and successor padding.
  - Caveat scope: `OnMouseEvent`, raw action dispatch, final action-helper names, and the `0x004cf74b-0x004cf7d0` table/raw-helper gap remain class-level caveats and are not broadened by this exact child implementation.
- 2026-06-25 B012 HitTestIcon first-draft implementation sync:
  - Score unchanged at `87/89`.
  - Summary/evidence: [UID:0002T3][0x004cf7d0-0x004cf862.IconsPaneHitTestIcon](by-memory/0x004cf7d0-0x004cf862.IconsPaneHitTestIcon.md) now carries formal first-draft C++ after B012 MCP session `80de0a67` reconfirmed `sub_4CF7D0` size `0x92`, four `OnMouseEvent` call xrefs, vertical-first/horizontal-second `PointInRect` argument order, full/reduced start indexes `0` and `6`, exact 20-pixel slot geometry, signed `-1` miss result, unique range signature, and successor padding.
  - Caveat scope: `OnMouseEvent`, raw action dispatch, final action-helper names, and the `0x004cf74b-0x004cf7d0` table/raw-helper gap remain class-level caveats and are not broadened by this hit-test child implementation.
- 2026-06-25 B004 OnPaint first-draft implementation sync:
  - Before: completion/confidence `86/88`; [UID:0002T1][0x004cf300-0x004cf3d3.IconsPaneOnPaint](by-memory/0x004cf300-0x004cf3d3.IconsPaneOnPaint.md) was listed as behavior-known but its exact child C++ was still blank under stale helper/gate wording.
  - After: completion/confidence `87/89`; owner/emitter unchanged at [UID:0000JZ][IconsPane](by-file/IconsPane.md).
  - Summary/evidence: B004 live IDA MCP session `80de0a67` reconfirmed `OnPaint` size `0xd3`, vtable slot `0x0061b48c`, `ICONS.EPD` xref `0x004cf379`, `NPAL7.PAL` xref `0x004cf385`, full/reduced loop geometry, and shared helper roles. The exact child now carries first-draft C++ with `SetDrawColor(0)`, inferred inherited `m_drawMode`, slot-7 `PreparePaneRegion`, `g_pEPFLib->LookupLayoutEntry`, and `RenderTileFrame`.
  - Caveat scope: raw action-dispatch and the `0x004cf74b-0x004cf7d0` gap remain real class-level caveats, but they no longer suppress the exact `OnPaint` child.
- 2026-06-19 B003 IconsPaneCore gap/source-quality incorporation:
  - No score change.
  - Summary/evidence: added the `0x004cf74b-0x004cf7d0` embedded-table/raw-helper gap to the class inventory, recorded the no-route `0x004cf7a0` icon-rectangle helper's 20x14 slot geometry, and refined `g_pConfig+0x28de32` as the persisted reduced-display-mode byte inverse to `m_showAllIcons`. The class remains owned by [UID:0000JZ][IconsPane](by-file/IconsPane.md); exact child allocation is still pending for the gap.
- 2026-06-16 A002 class-confidence refresh:
  - Before: `COMPLETION:85`, `CONFIDENCE:85`; the by-class coverage row was stale at `82`.
  - After: `COMPLETION:86`, `CONFIDENCE:88`; owner/emitter unchanged at [UID:0000JZ][IconsPane](by-file/IconsPane.md).
  - Evidence: live IDA MCP reconfirmed exact method starts, six [UID:0000R6][g_pIconsPane](by-global/g_pIconsPane.md) refs, vtable store triads for `0x0061b448`, `0x0061b494`, and `0x0061b4c4`, and the click-action helper calls from `IconsPane::OnMouseEvent`.
  - Blockers checked: raw body `0x004cf8e0-0x004cf974` is executable and switch-shaped but still has no function object or direct caller; helper callees remain shared command helpers, so final click-action names and TabPane grouping are not source-quality yet.
- 2026-06-17 B002 constructor/action source-quality audit:
  - No score change.
  - Summary/evidence: B002 validated `IconsPane::IconsPane() : Pane(1)`, adopted `m_showAllIcons`, `m_selectedIconIndex`, and `m_isPressed` as best current field names, rechecked the display-mode config byte, replaced unsafe icon-label action names with behavior names and rejected alternatives, confirmed `g_pCollectionData` over generated `g_pAppMan`, and confirmed the raw dispatcher is retained duplicate evidence with no direct entry or pointer route.
- 2026-06-10 B001-034 split repair:
  - Before: class confidence remained `82/82`, and destructor glue was only listed as bare ranges inside the mixed [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md) page.
  - Changed to: completion/confidence `85/85`; the method inventory now links exact destructor thunk and scalar deleting destructor children [UID:00034T][0x004cfd6c-0x004cfd82.IconsPaneDestructorAdjustorThunks](by-memory/0x004cfd6c-0x004cfd82.IconsPaneDestructorAdjustorThunks.md) and [UID:00034V][0x004cfda0-0x004cfdff.IconsPaneScalarDeletingDestructor](by-memory/0x004cfda0-0x004cfdff.IconsPaneScalarDeletingDestructor.md).
  - Evidence: IDA MCP confirmed `IconsPane` vtables at `0x0061b448`, `0x0061b494`, and `0x0061b4c4`; `g_pIconsPane` writes/clears at `0x004cf215`, `0x004cf27a`, and `0x004cfdc0`; adjustor thunks at `0x004cfd6c` and `0x004cfd77`; and scalar deleting destructor body `0x004cfda0-0x004cfdff`.
- 2026-06-18 Rule 26 draft-C++ incorporation (historical, superseded for source routing by the 2026-07-04 B014 UID0002SX callback):
  - Historical changed state: [UID:00034V][0x004cfda0-0x004cfdff.IconsPaneScalarDeletingDestructor](by-memory/0x004cfda0-0x004cfdff.IconsPaneScalarDeletingDestructor.md) carried a source-visible destructor draft that cleared `g_pIconsPane`; scalar-delete flags, vtable restores, and optional free remained documented as compiler-generated wrapper behavior.
  - Superseded current state: UID0002SX now emits the ordinary destructor body, and UID00034V is comment-only scalar-wrapper support. The old 2026-06-18 draft only explains why the wrapper page previously contained the destructor body.
- 2026-06-07 A005 resolved-name cleanup:
  - Before: click-action state evidence used historical `dword_67A748` and the older generated `g_pAppMan` label.
  - After: the page records canonical `g_pCollectionData` beside the historical label and cross-links the global page.
  - Evidence: generated resolved-name report maps `dword_67A748` to `g_pCollectionData`; existing IconsPane action-dispatch evidence already ties the reference to selected client/player action helpers.
- Completion/confidence score update: existed before as `0/0`; changed to `82/80`. Summary: old-layout icon-strip behavior, layout offsets, vtables, methods, singleton, resource use, persisted config byte, click action state, raw dispatch caveat, and TabPane grouping question are documented; confidence is capped by unresolved live status of the raw action-dispatch body and final source grouping. Evidence: `IconsPaneCore`, `IconsPaneActionDispatchRawBody`, `TabPaneAndIconsPaneDestructorTail`, `g_pIconsPane`, and `iconspane-icon-resources`.
- 2026-05-30: Historical active-output status for the cleanup-helper label.
  - Historical before: The method table described the `0x004cf260-0x004cf289` cleanup helper as omitted from active generated output.
  - Historical after: The method table recorded that the then-current `class_IconsPane.cpp` lead emitted the helper as `IconsPane::Cleanup`.
  - Superseded current state: B014's 2026-07-04 callback rejects `IconsPane::Cleanup()` as the source route; UID0002SX now emits `IconsPane::~IconsPane()`.
- 2026-06-02 autogen attachment:
  - What existed before: the class was scored `82/80` with no reconstructable flag or parent attachment.
  - Changed to: confidence `82`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000JZ`.
  - Summary/evidence: the file parent now has a validated `NexusTK/ui/panels/` projected path. The old blanket "blank under the 95+ gate" note is superseded by the current exact-child draft policy when evidence supports a source-visible draft.
- 2026-06-03 exact memory split:
  - What existed before: the important-method table listed bare addresses under the broad [UID:00016Z][0x004cf1f0-0x004cf8d5.IconsPaneCore](by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md) aggregate.
  - Changed to: the table now links exact child pages [UID:0002SW][0x004cf1f0-0x004cf25d.IconsPaneConstructor](by-memory/0x004cf1f0-0x004cf25d.IconsPaneConstructor.md) through [UID:0002T4][0x004cf870-0x004cf8d5.IconsPaneSetIconHighlight](by-memory/0x004cf870-0x004cf8d5.IconsPaneSetIconHighlight.md) for constructor, cleanup, state, paint, mouse, hit-test, and highlight helpers.
  - Summary/evidence: the child pages are reconstructable source-owned `IconsPane` methods/helpers; current policy is to add exact-child draft C++ when the target has enough source-shape evidence and to document a target-specific blocker otherwise.
