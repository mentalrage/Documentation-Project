*** UID:0000C0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000N7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "RightButtonMenuPane.h"
#include "../../map/MapPane.h"

static void __stdcall GetRightButtonMenuItemRect(int itemIndex, RectBounds *bounds);
static signed char __stdcall HitTestRightButtonMenuItem(int y, int x);
static void __stdcall SendRightButtonTargetActionPacket(int targetId);
static void __stdcall SendRightButtonNameCommandPacket(const wchar_t *targetName);

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct PaneEvent;

class RightButtonMenuPane : public Pane, public Singleton<RightButtonMenuPane>
{
public:
    RightButtonMenuPane();
    virtual ~RightButtonMenuPane();

    void CloseRightClickAndVoteMenus();
    void SetTargetNameAndId(int targetId, const wchar_t *targetName);

protected:
    virtual bool OnEvent(const PaneEvent *event);
    virtual int OnCancel();
    virtual void OnPaint();
    virtual void DrawBackground();
    virtual void DrawBorder();

private:
    enum {
        kLookMenuItem = 0,
        kTradeMenuItem = 1,
        kWhisperMenuItem = 2,
        kGroupMenuItem = 3,
        kInfoMenuItem = 4,
        kNoMenuItem = -1
    };

    bool m_menuItemPressed;
    signed char m_highlightedMenuItem;
    int m_targetId;
    wchar_t m_targetName[0x21];
};

extern RightButtonMenuPane *g_pRightButtonMenuPane;
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# RightButtonMenuPane

## Status

- Confidence: strong for class role and boundaries.
- Likely source file: [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md)
- Main address ranges: [UID:0001FX][0x00554b40-0x0055577b.RightButtonMenuPaneCore](by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md), [UID:00023Q][0x00555780-0x005558c2.RightButtonMenuPacketHelpers](by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md), [UID:0001G0][0x00556212-0x00556228.RightButtonMenuPaneDestructorThunks](by-memory/0x00556212-0x00556228.RightButtonMenuPaneDestructorThunks.md), and [UID:0001G2][0x00556240-0x00556314.RightButtonMenuPaneScalarDeletingDestructor](by-memory/0x00556240-0x00556314.RightButtonMenuPaneScalarDeletingDestructor.md)
- Current source route: `NexusTK/ui/menu/RightButtonMenuPane.cpp` and `RightButtonMenuPane.h` through [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md). The class now supplies the first-draft declaration and CPP child scaffold; UID0001G2 remains compiler-generated no-code evidence rather than handwritten source.

## Class Purpose

`RightButtonMenuPane` is the right-click target context menu. It draws a SUBWIN-styled menu for a selected target and handles Look, Trade, Whisper, Group, and Info actions.

## Inheritance And Layout

- Live RTTI identifies direct `Pane` and direct empty `Singleton<RightButtonMenuPane>` source bases. The Singleton base descriptor uses PMD `+0xf8/-1/0`, overlapping the first class-owned state byte through empty-base optimization rather than consuming a separate data field.
- The allocated/full object size is `0x144`. The inherited Pane prefix reaches `+0xf8`; direct Singleton construction/destruction supplies the `g_pRightButtonMenuPane` publish/clear lifecycle as compiler lowering.
- Existing right-click state begins at the same `+0xf8` boundary: pressed/active-click byte `+0xf8`, hover/selected-row byte `+0xf9`, target id `+0xfc`, and target-name `wchar_t[33]` buffer at `+0x100`.
- Live UDT evidence identifies one `RightButtonMenuPane` ordinal (`860`) at exact size `0x144`: `Pane` occupies `[+0x000,+0x0f8)`, `m_menuItemPressed` is byte-like at `+0xf8`, `m_highlightedMenuItem` is signed-byte-like at `+0xf9`, two bytes pad `+0xfa..+0xfb`, `m_targetId` is a four-byte integer at `+0xfc`, `m_targetName` is `wchar_t[33]` at `+0x100`, and two trailing bytes pad `+0x142..+0x143`. The source names/access are high-probability human-source inference; offsets, widths, uses, and full size are exact.
- Inherited EventHandler and TimerHandler interface facets use adjusted vptrs at `+0xa0` and `+0xa4`; together with the primary vptr they correspond to table bases `0x00622f68`, `0x00622fbc`, and `0x00622fec`.
- Constructor, ordinary destructor, and scalar deleting wrapper are the only writers to each vtable base. The deleting-destructor thunks adjust `this` by `0xa0` or `0xa4` before tail-calling the primary scalar wrapper.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x00554b40-0x0055577b` | [UID:0001FX][0x00554b40-0x0055577b.RightButtonMenuPaneCore](by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md) | Reviewed non-emitting split container for the exact method/helper/jump-table child pages below. |
| `0x00554b40-0x00554b96` | [UID:0004F7][0x00554b40-0x00554b96.RightButtonMenuPaneConstructor](by-memory/0x00554b40-0x00554b96.RightButtonMenuPaneConstructor.md) | Constructs pane state, installs three `RightButtonMenuPane` vtables, sets `g_pRightButtonMenuPane`, clears pressed state, and initializes hover row to `-1`. |
| `0x00554ba0-0x00554c33` | [UID:0004F8][0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor](by-memory/0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor.md) | Emitting ordinary destructor: clears `g_activeMapPane->m_highlightedObjectPane` through `SetHighlightState(false)`, nulls the slot, then calls inherited `RemoveFromLayer()` and `UnregisterEventHandler()`; three vptr restores, direct Singleton clear, implicit Pane destruction, and EH scaffolding are compiler lowering. |
| `0x00554c40-0x00554f59` | [UID:0004F9][0x00554c40-0x00554f59.RightButtonMenuPaneOnEvent](by-memory/0x00554c40-0x00554f59.RightButtonMenuPaneOnEvent.md) | Handles hover, click, outside cancel, release/action dispatch, vote-popup dismissal, and Look/Trade/Whisper/Group/Info actions. |
| `0x00554f59-0x00554f83` | [UID:0004FA][0x00554f59-0x00554f83.RightButtonMenuPaneOnEventJumpTables](by-memory/0x00554f59-0x00554f83.RightButtonMenuPaneOnEventJumpTables.md) | Compiler-generated switch data for the event/action switches; not padding and not handwritten source. |
| `0x00554f90-0x00554fb3` | [UID:0004FB][0x00554f90-0x00554fb3.RightButtonMenuPaneOnCancel](by-memory/0x00554f90-0x00554fb3.RightButtonMenuPaneOnCancel.md) | Adjusted cancel handler that closes an active vote popup and this menu. |
| `0x00554fc0-0x00555298` | [UID:0004FC][0x00554fc0-0x00555298.RightButtonMenuPaneOnPaint](by-memory/0x00554fc0-0x00555298.RightButtonMenuPaneOnPaint.md) | Source-complete `OnPaint`: draws background/border, inset target title, direct Look/Trade/Whisper/Group/Info literals at y `37/53/69/85/117`, and pressed/highlight frame. The y=`117` Info versus five-row hit-test anomaly is preserved exactly. |
| `0x005552a0-0x005552ba` | [UID:0004FD][0x005552a0-0x005552ba.RightButtonMenuPaneCloseRightClickAndVoteMenus](by-memory/0x005552a0-0x005552ba.RightButtonMenuPaneCloseRightClickAndVoteMenus.md) | Tiny dismissal helper called by `VoteMenuPane::OnMouseEvent`; closes an active vote popup and this right-button menu. |
| `0x005552c0-0x005552e4` | [UID:0004FE][0x005552c0-0x005552e4.RightButtonMenuPaneSetTargetNameAndId](by-memory/0x005552c0-0x005552e4.RightButtonMenuPaneSetTargetNameAndId.md) | Stores target id at full-object `this+252` and copies the visible target name into the fixed `wchar_t[33]` buffer at `this+256`. |
| `0x005552f0-0x00555361` | [UID:0004FF][0x005552f0-0x00555361.RightButtonMenuPaneDrawSubwinBackground](by-memory/0x005552f0-0x00555361.RightButtonMenuPaneDrawSubwinBackground.md) | Source-complete `DrawBackground`: frame 8 of `SUBWIN.EPF`, one-pixel inset bounds, draw mode `1`, and `SUBWIN.PAL` tiled fill. |
| `0x00555370-0x00555692` | [UID:0004FG][0x00555370-0x00555692.RightButtonMenuPaneDrawSubwinBorder](by-memory/0x00555370-0x00555692.RightButtonMenuPaneDrawSubwinBorder.md) | Source-complete `DrawBorder`: one EPF context, 7x7 bounds, four edge loops, and exact frame order `1/6/3/4/0/2/5/7`. |
| `0x005556a0-0x005556ed` | [UID:0004FH][0x005556a0-0x005556ed.RightButtonMenuPaneGetMenuItemRect](by-memory/0x005556a0-0x005556ed.RightButtonMenuPaneGetMenuItemRect.md) | Receiver-free file-static `__stdcall` helper directly owned/emitted by UID0000N7; computes `-1` sentinel or fixed rectangle `(0, 22+16*row, 79, 38+16*row)`. It is not a class member. |
| `0x005556f0-0x0055577b` | [UID:0004FI][0x005556f0-0x0055577b.RightButtonMenuPaneHitTestMenuItem](by-memory/0x005556f0-0x0055577b.RightButtonMenuPaneHitTestMenuItem.md) | Receiver-free file-static signed-char `__stdcall` helper directly owned/emitted by UID0000N7; tests y/x against exactly rows `0..4` and returns `-1` on miss. Former class/BulletinSession ownership is rejected. |
| `0x00555780-0x005558c2` | packet helper island | Two private/file-local right-click menu packet helpers now first-draft C++ ready under [UID:00023Q][0x00555780-0x005558c2.RightButtonMenuPacketHelpers](by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md): `SendRightButtonTargetActionPacket(int targetId)` sends opcode `0x4a`, subcommand `0`, and a big-endian 32-bit target id; `SendRightButtonNameCommandPacket(const wchar_t *targetName)` sends a dot-prefixed, one-byte-length CP_ACP target-name packet. No direct caller xrefs are proven, so exact row names remain inferred. |
| `0x00556212-0x00556228` | Adjustor/thunk helpers | Compiler-generated vtable-referenced deleting-destructor thunks. |
| `0x00556240-0x00556314` | [UID:0001G2][0x00556240-0x00556314.RightButtonMenuPaneScalarDeletingDestructor](by-memory/0x00556240-0x00556314.RightButtonMenuPaneScalarDeletingDestructor.md) | Compiler-generated MSVC scalar deleting destructor ABI wrapper for `RightButtonMenuPane::~RightButtonMenuPane()`; keep the formal C++ block blank. Source-authored cleanup belongs to [UID:0004F8][0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor](by-memory/0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor.md). |

## Field And Action Notes

MCP session `1fc4a5a7` resolves the former UID0001FX source-quality blockers:

| Field/action | Evidence-backed class role |
| --- | --- |
| `this+248` / adjusted `this+88` | Pressed/active-click state, initialized to `0`, set on mouse press, cleared on release, and used by paint to choose selected-row outline colors. |
| `this+249` / adjusted `this+89` | Hover/selected row, initialized to `-1`, written from `HitTestMenuItem`, and consumed by `OnPaint` for row highlighting. |
| `this+252` / adjusted `this+92` | Target id, written by `SetTargetNameAndId` and used by Look/Trade/Info row actions. |
| `this+256` / adjusted `this+96` | Target name buffer copied with `wcscpy_s(..., 0x21, Source)`; used by paint, Whisper, and Group/name command paths. |
| Row 0 / Look | Opens a look/object pane and closes a target object lookup. |
| Row 1 / Trade | Builds and sends a 6-byte packet beginning with `0x4a`, zero subcommand, and target id payload. |
| Row 2 / Whisper | Constructs a `0x208` whisper/dialog object from the target name. |
| Row 3 / Group/name command | Converts target name to CP_ACP, prefixes dot `0x2e`, and sends a name command packet. |
| Row 4 / Info | Calls externally linked MapPane helper `RequestObjectInfo(m_targetId)`; this is consumed through the MapPane header declaration and remains owned/defined by UID0003TU, not by this class. Historical `sub_50F4D0` / `MapPaneSendObjectAction43Packet` are raw/search aliases only. |

## Source Declaration And Literal Model

- The exact CPP preamble includes both `RightButtonMenuPane.h` and `../../map/MapPane.h`, then declares the four direct-file static helpers before `[[CHILDREN]]`. The second include makes global `RequestObjectInfo(unsigned int)` visible to UID0004F9 without duplicating its UID0003TU definition. Class method children emit once through this class route; UID0004FH/UID0004FI and the packet helpers emit directly through UID0000N7 because receiver-free functions must not be nested as members.
- The H declaration models direct `Pane` plus empty `Singleton<RightButtonMenuPane>` inheritance. Empty-base optimization explains why singleton lowering overlaps the first class-owned byte at `+0xf8`; no singleton data member is invented.
- Virtual declarations are tied to current vtable slots and exact method pages. UID0004F9 now supplies the complete `OnEvent` body at `92/94`; constructor and compiler jump-table support remain separately documented without blocking the class header/source route.
- Row-enum and private field spellings are high-probability, project-consistent source names. Exact values, field widths/offsets, state transitions, object size, and runtime behavior are binary-backed.
- [UID:0003CZ][0x00623084-0x006230a8.RightButtonMenuCommandStrings](by-memory/0x00623084-0x006230a8.RightButtonMenuCommandStrings.md) is compiler/linker support, not an independent class data emitter. `OnPaint` contains direct `L"Look"`, `L"Trade"`, `L"Whisper"`, `L"Group"`, and `L"Info"` expressions; linker pooling explains the split physical locations.
- Runtime fidelity requires retaining `Info` at y `117` even though the geometry/hit-test loop covers only five 16-pixel rows from y `22` through `102` and `OnEvent` contains action case `4`. The documentation does not normalize this likely original quirk/defect.
- Rejected source shapes include a command-label array/resource object, member versions of the two receiver-free geometry helpers, a raw vtable declaration, and handwritten scalar-deleting/adjustor code.

## Destructor Source Lowering

- [UID:0004F8][0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor](by-memory/0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor.md) is the source-authored ordinary non-deleting destructor and now emits through this class at source position `30`.
- Its handwritten body conditionally clears `MapPane::m_highlightedObjectPane`, preserving `SetHighlightState(false)` before nulling the pointer, then explicitly calls `RemoveFromLayer()` and `UnregisterEventHandler()`.
- The source does not add a null check for `g_activeMapPane`; only the highlighted-object member is conditional in the binary.
- The three destructor-phase vptr writes, `g_pRightButtonMenuPane` clear, reverse `Pane::~Pane()` call, and SEH/security-cookie scaffolding are compiler effects of virtual inheritance layout and direct-base destruction.
- [UID:0001G2][0x00556240-0x00556314.RightButtonMenuPaneScalarDeletingDestructor](by-memory/0x00556240-0x00556314.RightButtonMenuPaneScalarDeletingDestructor.md) duplicates the ordinary cleanup before adding MSVC delete-flag/operator-delete behavior. It remains blank formal ABI glue rather than a second handwritten destructor.
- No direct xref to the ordinary destructor start was found. Vtable slots, adjustor thunks, scalar-wrapper parity, and the exact class vptr/global writes prove the destructor family despite that expected ABI-shaped reachability.

## Evidence Notes

- Wave3 grades the class at effective `97.6`.
- IDA MCP confirms all listed starts as exact functions.
- Current emitted source omits the tiny thunk bodies at `0x00556212` and `0x0055621d`.
- The neighboring [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md) starts at raw constructor boundary `0x005558d0`, so the former broad right-click memory page has been split into exact non-overlapping ranges.
- Active generated `RightButtonMenuPane` code uses `g_pBulletinSession` for some `0x0069ba38` references. Treat those as [UID:0000SP][g_pVoteMenuPane](by-global/g_pVoteMenuPane.md) [UID:0001Q0][0x0069ba38-0x0069ba3c.g_pVoteMenuPane](by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md) until the generated global owner is fixed.
- 2026-05-26 recheck: IDA callers still report the only direct `0x005556f0` calls at `0x00554c95` and `0x00554d27` inside `RightButtonMenuPane::OnEvent`; no `BulletinSession` caller evidence was found.
- 2026-06-01 recheck: raw starts `0x00555780` and `0x005557e0` have no direct caller or pointer xrefs, but their packet-building behavior and placement keep them provisionally attached to this class/file.
- 2026-06-07 A010 parent-gate refresh: live IDA xrefs to [UID:00029Z][0x0069b4f0-0x0069b4f4.RightButtonMenuPaneSingleton](by-memory/0x0069b4f0-0x0069b4f4.RightButtonMenuPaneSingleton.md) reconfirm constructor publish, destructor clear, scalar-deleting destructor clear, six menu/open-state consumers in `0x00507150`, and exact neighboring singleton boundaries.
- 2026-06-12 A005 Batch245: live IDA rechecked [UID:00023Q][0x00555780-0x005558c2.RightButtonMenuPacketHelpers](by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md), confirming raw non-function starts, no direct xrefs, no little-endian pointer-pattern hits, exact `0x142` / 322-byte island size (Verified with int_convert.py), packet-send bodies, and internal/trailing padding. The child now clears `85/86` and is assigned to this class under the strict direct-parent gate.
- 2026-06-16 A002 file-root completion refresh: live IDA `entity_query` over `0x00554b40-0x005558d0` reports eleven core functions and shows that [UID:0001FX][0x00554b40-0x0055577b.RightButtonMenuPaneCore](by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md) was missing `0x005552a0` and `0x005552c0` in its method table. `xrefs_to(0x005552a0)` reports the sole caller at `0x00555a3d` inside [UID:0002LS][0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent](by-memory/0x005559c0-0x00555ad5.VoteMenuPaneOnMouseEvent.md); `xrefs_to(0x005552c0)` reports the compact-display/menu-open caller at `0x00507707` inside `0x00507150`.
- The same pass reconfirmed `0x00555780` and `0x005557e0` are still raw no-function packet helpers with no `xrefs_to` entries and no little-endian pointer-pattern hits, so helper liveness and final helper names remain real blockers rather than stale documentation.
- 2026-06-19 B015 source-quality recheck: [UID:00023Q][0x00555780-0x005558c2.RightButtonMenuPacketHelpers](by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md) now carries first-draft C++ for the two private/file-local helpers under this class. Fresh raw PE scans found no direct rel32 or absolute refs into either helper body, so final action-row names remain inferred; however, helper signatures and packet layouts are source-quality enough for draft emission. The target-name helper likely supports the right-click `Whisper`/name-command row, while the target-id helper supports a target-object action. Do not promote these to final row-specific names until the `OnEvent` caller or an equivalent protocol table is recovered.
- 2026-07-03 B005 split implementation: [UID:0001FX][0x00554b40-0x0055577b.RightButtonMenuPaneCore](by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md) is now a non-emitting split container, with exact child pages [UID:0004F7][0x00554b40-0x00554b96.RightButtonMenuPaneConstructor](by-memory/0x00554b40-0x00554b96.RightButtonMenuPaneConstructor.md) through [UID:0004FI][0x005556f0-0x0055577b.RightButtonMenuPaneHitTestMenuItem](by-memory/0x005556f0-0x0055577b.RightButtonMenuPaneHitTestMenuItem.md) for constructor, destructor, `OnEvent`, jump tables, cancel, paint, dismissal, target setter, background, border, row rectangle, and hit-test. MCP session `1fc4a5a7` resolved row labels Look/Trade/Whisper/Group/Info, full/adjusted field offsets, action mapping, packet-helper no-xref evidence, and the `0x00554f59-0x00554f83` jump-table island.
- 2026-07-05 B008 UID0001G2 callback: live MCP session `supervisor_recovery_20260705` rechecked the scalar deleting destructor at `0x00556240-0x00556314` as one exact `0xd4` function with vtable/thunk-only reachability, no direct static callers, ordinary-destructor-equivalent cleanup, highlighted-target clear, Pane teardown helpers, `g_pRightButtonMenuPane` clear, MSVC delete flag handling, optional `OperatorDeleteWrapper`, and a flag-`4` guard/no-op size path. The scalar wrapper is compiler-generated ABI evidence for the class destructor and should not receive handwritten C++; final source cleanup belongs to [UID:0004F8][0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor](by-memory/0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor.md).
- 2026-07-22 B004 UID0004F8 source closure: live MCP ordinary/scalar destructor-family analysis, current MapPane/LivingObjectPane/Pane support, RTTI PMD `+0xf8/-1/0`, and the three vtable facets resolve the former helper/member/direct-base blockers. UID0004F8 now emits the exact ordinary destructor through this class while Singleton clear, Pane base destruction, vptr restores, EH scaffolding, and scalar-delete behavior remain compiler lowering.

## Cross-References

- [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md)
- [UID:0001FX][0x00554b40-0x0055577b.RightButtonMenuPaneCore](by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md)
- [UID:00023Q][0x00555780-0x005558c2.RightButtonMenuPacketHelpers](by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md)
- [UID:0000FX][VoteMenuPane](by-class/VoteMenuPane.md)
- [UID:0000SP][g_pVoteMenuPane](by-global/g_pVoteMenuPane.md)
- [UID:0001Q0][0x0069ba38-0x0069ba3c.g_pVoteMenuPane](by-memory/0x0069ba38-0x0069ba3c.g_pVoteMenuPane.md)
- [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md)

## Changes

- 2026-07-29 B009 accepted UID00037S support callback: added the compile-visible `../../map/MapPane.h` include, migrated the Info action from raw aliases to `RequestObjectInfo(m_targetId)`, recorded UID0004F9 as source-complete/emitting at `92/94`, and preserved the exact setter signature, layout, score `90/94`, and unrelated child/static-helper content.
- 2026-05-30: Changed completion/confidence from `0/0` to `84/86`.
  - Before: The page was unevaluated despite documenting menu behavior, exact method boundaries, destructor thunks, split ranges, and generated global-owner caveats.
  - After: Scored as high completion and strong confidence for the right-click target menu.
  - Evidence: Existing method map, Wave3 grade note, IDA exact-start evidence, caller evidence for hit testing, and global/source ownership caveats support the score.
- 2026-06-01: Added the adjacent packet helper island to the class map as provisional ownership.
  - Evidence: IDA MCP confirms packet-builder bodies at `0x00555780` and `0x005557e0`, an internal `0xcc` alignment gap, and no direct caller/pointer xrefs; ownership remains by adjacency and behavior rather than direct calls.
- 2026-06-05: Marked reconstructable and attached to [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md) because the class is `84/86` and the parent is `84/86`, satisfying the 80/80 parent gate. Live IDA MCP `lookup_funcs` confirms exact starts for the core/destructor methods at `0x00554b40`, `0x00554ba0`, `0x00554c40`, `0x00554f90`, `0x00554fc0`, `0x005552f0`, `0x005556a0`, `0x005556f0`, `0x00556212`, `0x0055621d`, and `0x00556240`; current `callers` confirms the constructor reference at `0x00507685`.
- 2026-06-07 A010 Batch044 parent-gate update: Raised `84/86` to `85/88` after adding refreshed singleton storage xrefs and boundary evidence. This supports [UID:00029Z][0x0069b4f0-0x0069b4f4.RightButtonMenuPaneSingleton](by-memory/0x0069b4f0-0x0069b4f4.RightButtonMenuPaneSingleton.md) assignment to this class under the corrected 85/85 gate; final C++ remains blank.
- 2026-06-12 A005 Batch245: Updated packet-helper row/evidence after [UID:00023Q][0x00555780-0x005558c2.RightButtonMenuPacketHelpers](by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md) reached `85/86` and attached to this class. The no-direct-caller caveat remains, so the class score is unchanged.
- 2026-06-16 A002 file-root completion pass: Raised `85/88 -> 86/89` after live IDA evidence added the omitted `0x005552a0` close/dismiss helper and `0x005552c0` target-name/id setter to the class method map, corrected [UID:0001FX][0x00554b40-0x0055577b.RightButtonMenuPaneCore](by-memory/0x00554b40-0x0055577b.RightButtonMenuPaneCore.md) and [UID:0001G2][0x00556240-0x00556314.RightButtonMenuPaneScalarDeletingDestructor](by-memory/0x00556240-0x00556314.RightButtonMenuPaneScalarDeletingDestructor.md) to direct class ownership, and retained the packet-helper raw-start blocker after fresh xref and `find_bytes` checks.
- 2026-06-19 B015 Rule 26 support sync: Updated the packet-helper method-map row and evidence notes after [UID:00023Q][0x00555780-0x005558c2.RightButtonMenuPacketHelpers](by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md) resolved source-quality helper names/signatures, packet layouts, sender/global names, and first-draft C++ policy while preserving the no-direct-liveness caveat.
- 2026-07-22 B004 accepted implementation callback:
  - Preserved class metadata at `86/89`, owner/emitter [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md), and blank class-level formal because broader child/declaration work remains incomplete.
  - Added direct Pane plus `Singleton<RightButtonMenuPane>` inheritance, PMD/facet/object-layout evidence, and exact ordinary-destructor source lowering.
  - Updated UID0004F8 from helper-name-blocked teardown evidence to an emitting ordinary destructor while preserving UID0001G2 as blank compiler ABI glue and retaining packet-helper/generated-owner caveats.
- 2026-07-03 B005 implementation callback: Updated UID0001FX from monolithic reconstructable core wording to a non-emitting split container with validator-assigned child UIDs [UID:0004F7][0x00554b40-0x00554b96.RightButtonMenuPaneConstructor](by-memory/0x00554b40-0x00554b96.RightButtonMenuPaneConstructor.md) through [UID:0004FI][0x005556f0-0x0055577b.RightButtonMenuPaneHitTestMenuItem](by-memory/0x005556f0-0x0055577b.RightButtonMenuPaneHitTestMenuItem.md), added field/action notes, and preserved rejected owner alternatives and packet-helper negative evidence from MCP session `1fc4a5a7`.
- 2026-07-05 B008 implementation callback: Updated the UID0001G2 method-map row and evidence notes to describe the scalar deleting destructor as compiler-generated MSVC ABI wrapper/no-code evidence rather than a handwritten source method. No class metadata changed; the source-authored ordinary destructor cleanup remains tracked by [UID:0004F8][0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor](by-memory/0x00554ba0-0x00554c33.RightButtonMenuPaneDestructor.md).
- 2026-07-28 B001 UID0003CZ accepted implementation callback: raised `86/89 -> 90/94`, populated the class CPP scaffold and first-draft H declaration, added the exact `0x144` layout and direct-base/EBO model, source-closed `OnPaint`/`DrawBackground`/`DrawBorder`, corrected the two receiver-free helpers to direct-file statics, documented direct literal pooling, and preserved the exact Info y=`117` versus five-row hit-test anomaly and all historical packet/destructor/vtable caveats.
