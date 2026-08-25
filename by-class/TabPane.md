*** UID:0000EB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;
struct RectBounds;

class TabPane : public Pane, public Singleton<TabPane>
{
public:
    TabPane();
    virtual ~TabPane();

    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void OnPaint();

private:
    void BuildTabActionRect(int actionCode, RectBounds *outRect) const;
    signed char ResolveTabActionCode(int mouseY, int mouseX) const;
};

extern TabPane *g_pTabPane;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TabPane

## Status

- Confidence: very strong for local function boundaries, three-view vtable/RTTI identity, Singleton EBO and `0xf8` layout, singleton lifecycle, the explicit empty primary `+0x44` `OnPaint` override, exact EventHandler pointer/mouse and key/text overrides, hit-test geometry, and the retained raw rectangle helper's no-route/source-shape policy; strong for the complete source-facing declaration. Final tab labels, action-helper lexical spellings, exact access tokens, and physical grouping with `IconsPane` remain bounded caps.
- Likely source module: [UID:0000OF][TabPane](by-file/TabPane.md)
- Split range inventory: [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md)
- Singleton global: [UID:0000SE][g_pTabPane](by-global/g_pTabPane.md)
- Evidence basis: live IDA MCP checks on 2026-06-04 against `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515`, B003 session `60724697` rechecking UID00034O on 2026-07-04, session `e98ecbb2` resolving UID00034N/table/RTTI/layout on 2026-07-14, and resumed database `3fc1dcef` independently rediscovered and healthy on 2026-07-14 for bounded UID00034O/34P/34R interface, bytes, CFG, call-order, and helper-ABI revalidation after the external MCP interruption.

## Responsibility

`TabPane` is an old-layout tab/action input pane. It maps mouse coordinates to a small set of tab action codes and dispatches those actions through the same broader UI helper family used by [UID:00006B][IconsPane](by-class/IconsPane.md), [UID:0000FQ][UserPane](by-class/UserPane.md), and related shortcuts. It explicitly overrides Pane's primary paint slot with an empty `OnPaint` body, suppressing base/default painting for this tab strip.

## Layout Evidence

- The constructor calls `0x00544460` at `0x004cf98c`, writes [UID:0000SE][g_pTabPane](by-global/g_pTabPane.md) at `0x004cf9a4`, and writes vtables at object offsets `0x0`, `0xa0`, and `0xa4`.
- B014's 2026-07-02 MCP recheck of [UID:00034L][0x004cf980-0x004cf9ca.TabPaneConstructor](by-memory/0x004cf980-0x004cf9ca.TabPaneConstructor.md) confirmed `sub_4CF980` as a 74-byte / `0x4a` constructor with 23 instructions, four basic blocks, callee `sub_544460`, exactly one direct caller at `0x004f812d` inside `sub_4F7D10`, and constructor-side stores to [UID:0000SE][g_pTabPane](by-global/g_pTabPane.md), `0x0061b4d0`, `0x0061b51c`, and `0x0061b54c`.
- The same B014 caller decompile shows the main UI initializer allocates `248` / `0xf8` bytes, calls the constructor, places the pane at `(808,79)-(831,365)`, and attaches it through pane virtual calls at `0x004f8173` and `0x004f817d`. This proves the complete object size used by the only constructor caller and strengthens the old-layout vertical tab-strip interpretation.
- The singleton is stored from the owner pointer adjusted from `this + 0xf8`; the live constructor's null fallback only triggers for the impossible `this == -0xf8` arithmetic case.
- The input handler receives an event-like object with event mode at `+0x4`, x/y at `+0x8`/`+0xc`, and an additional argument at `+0x10c`.
- Live IDA names the vtable views as `??_7TabPane@@6B@` at `0x0061b4d0`, `??_7TabPane@@6B@_0` at `0x0061b51c`, and `??_7TabPane@@6B@_1` at `0x0061b54c`.
- Key slots are `0x0061b4d0 -> 0x004cfe00`, `0x0061b514 -> 0x004cfa00`, `0x0061b51c -> 0x004cfd82`, `0x0061b520 -> 0x004cfa10`, `0x0061b524 -> 0x004cfb10`, and `0x0061b54c -> 0x004cfd8d`.
- RTTI complete-object locators at `0x0061b4cc`, `0x0061b518`, and `0x0061b548` resolve to class hierarchy records containing TabPane, Pane, GrafPort, LObject, EventHandler, TimerHandler, and `Singleton<TabPane>`. PMDs place the primary view at `0`, EventHandler at `+0xa0`, TimerHandler at `+0xa4`, and the Singleton empty base at `+0xf8`.
- The `Singleton<TabPane>` PMD and exact `0xf8` allocation prove empty-base optimization after the inherited Pane object. No TabPane-owned data field is required beyond Pane's complete `0xf8` layout.
- Constructor, ordinary destructor, and scalar deleting wrapper each write all three table bases. The table-write triad, RTTI hierarchy, singleton storage, and class-local method island are mutually consistent ownership evidence.

## Primary Paint Slot Comparison

| Class | Primary base | `+0x44` cell | Target | Source consequence |
| --- | ---: | ---: | ---: | --- |
| [UID:0000A2][Pane](by-class/Pane.md) | `0x006219e8` | `0x00621a2c` | `0x0041b6a0` | inherited/shared empty `OnPaint` default |
| `TabPane` | `0x0061b4d0` | `0x0061b514` | `0x004cfa00` | explicit empty [UID:00034N][0x004cfa00-0x004cfa01.TabPaneOnPaint](by-memory/0x004cfa00-0x004cfa01.TabPaneOnPaint.md) override |
| [UID:00006B][IconsPane](by-class/IconsPane.md) | `0x0061b448` | `0x0061b48c` | `0x004cf300` | independently audited full `IconsPane::OnPaint` override |

All intervening primary slots match Pane for TabPane and IconsPane; only the class-specific deleting destructor and paint slot differ. A purely inherited TabPane paint method would leave `0x0041b6a0` in `0x0061b514`, so the distinct `0x004cfa00` target proves a source declaration/body rather than inheritance, sharing, folding, or compiler glue.

## Important Methods

| Range doc | Current name | Notes |
| --- | --- | --- |
| [UID:00034L][0x004cf980-0x004cf9ca.TabPaneConstructor](by-memory/0x004cf980-0x004cf9ca.TabPaneConstructor.md) | constructor | Registers singleton and installs vtables. |
| [UID:00034M][0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper](by-memory/0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper.md) | ordinary `TabPane::~TabPane()` body | Source-bearing non-deleting destructor body. The binary restores vtables, clears singleton, then tail-jumps to `Pane::~Pane()` at `0x00544580`; source C++ should contain only `g_pTabPane = NULL;`. |
| [UID:00034N][0x004cfa00-0x004cfa01.TabPaneOnPaint](by-memory/0x004cfa00-0x004cfa01.TabPaneOnPaint.md) | `void OnPaint()` | Exact source-authored empty primary `+0x44` override: one-byte `retn`, one block, no arguments, sole vtable cell `0x0061b514`, and distinct Pane/IconsPane same-slot targets. Historical `nullsub_30`, `TabPaneNullVirtual`, and `OnNoOpVirtual` labels are superseded provenance. |
| [UID:00034O][0x004cfa10-0x004cfb0a.TabPaneHandlePointerOrMouseEvent](by-memory/0x004cfa10-0x004cfb0a.TabPaneHandlePointerOrMouseEvent.md) | `bool HandlePointerOrMouseEvent(Event *event)` | Exact EventHandler secondary `+0x04` override at `0x0061b520`; left-button-down handles `0..5`, double-click handles `0`, `1`, `2`, and `5`, with canonical pointer `m_y,m_x` resolver order and the exact action-0 `+0x10c` key-overlay read. |
| [UID:00034P][0x004cfb10-0x004cfb15.TabPaneHandleKeyOrTextEvent](by-memory/0x004cfb10-0x004cfb15.TabPaneHandleKeyOrTextEvent.md) | `bool HandleKeyOrTextEvent(Event *event)` | Exact five-byte EventHandler secondary `+0x08` override at `0x0061b524`; ignores the argument and returns false. |
| [UID:00034Q][0x004cfb20-0x004cfc5c.TabPaneRawRectangleBuilder](by-memory/0x004cfb20-0x004cfc5c.TabPaneRawRectangleBuilder.md) | retained private `BuildTabActionRect` helper | Source-shaped helper with unique body/table bytes and no rel32/rel8/VA/RVA/export route; builds the six tab rectangles through `InitRectBounds`. Keep as retained `TabPane` helper/dead or inlined duplicate, not padding or aggregate-owned data. |
| [UID:00034R][0x004cfc60-0x004cfd4d.TabPaneResolveActionCode](by-memory/0x004cfc60-0x004cfd4d.TabPaneResolveActionCode.md) | `signed char ResolveTabActionCode(int mouseY, int mouseX) const` | Hit-tests six fixed rectangles through canonical `PointInRect(y,x,bounds)` and returns signed-byte code `0..5` or `-1`; binary body duplicates/inlines the rectangle switch and does not call UID00034Q. |
| [UID:00034S][0x004cfd4d-0x004cfd6c.TabPaneResolveActionCodeJumpTable](by-memory/0x004cfd4d-0x004cfd6c.TabPaneResolveActionCodeJumpTable.md) | resolver jump table | Non-reconstructable switch/alignment bytes. |
| [UID:00034U][0x004cfd82-0x004cfd98.TabPaneDestructorAdjustorThunks](by-memory/0x004cfd82-0x004cfd98.TabPaneDestructorAdjustorThunks.md) | adjustor thunks | Compiler-generated `this - 0xa0`/`this - 0xa4` forwards to `0x004cfe00`; parent blank. |
| [UID:00034W][0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor](by-memory/0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor.md) | scalar deleting destructor glue | Compiler-generated scalar deleting wrapper regenerated from `TabPane::~TabPane()`; repeats vtable/singleton/base-cleanup/delete-flag behavior but should not emit a second handwritten destructor body. |

## Live IDA Evidence

- Function boundaries in this class span are `0x004cf980-0x004cf9ca`, `0x004cf9d0-0x004cf9f9`, `0x004cfa00-0x004cfa01`, `0x004cfa10-0x004cfb0a`, `0x004cfb10-0x004cfb15`, `0x004cfc60-0x004cfd4d`, `0x004cfd82-0x004cfd8d`, `0x004cfd8d-0x004cfd98`, and `0x004cfe00-0x004cfe5f`. B003 MCP session `60724697` reconfirmed [UID:00034O][0x004cfa10-0x004cfb0a.TabPaneHandlePointerOrMouseEvent](by-memory/0x004cfa10-0x004cfb0a.TabPaneHandlePointerOrMouseEvent.md) specifically as size `0xfa`, 92 instructions, 20 blocks, with a unique signature, six-byte post-padding to successor `0x004cfb10`, and no direct callers.
- B003 live MCP session `e98ecbb2` on 2026-07-14 reconfirmed [UID:00034N][0x004cfa00-0x004cfa01.TabPaneOnPaint](by-memory/0x004cfa00-0x004cfa01.TabPaneOnPaint.md) as byte `c3`, size 1, one `retn`, one terminal block, source-level void/no-argument ABI, no callers/callees/strings/constants, and exactly one xref from primary cell `0x0061b514`. Target-byte SHA256 is `AE3F4619B0413D70D3004B9131C3752153074E45725BE13B9A148978895E359E`.
- The constructor entry `0x004cf980` has a direct caller at `0x004f812d` inside `InitializeMainUiGraph`.
- [UID:0000SE][g_pTabPane](by-global/g_pTabPane.md) at `0x0069adfc` is read at `0x0049e5e6` and `0x00504936`, written by the constructor at `0x004cf9a4`, and cleared by cleanup/destructor paths at `0x004cf9ea` and `0x004cfe20`.
- The ordinary destructor body [UID:00034M][0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper](by-memory/0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper.md) and scalar deleting wrapper [UID:00034W][0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor](by-memory/0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor.md) both restore all three `TabPane` vtables before clearing the singleton. [UID:00034M][0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper](by-memory/0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper.md) is the source-bearing `TabPane::~TabPane()` body and emits only `g_pTabPane = NULL;`; [UID:00034W][0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor](by-memory/0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor.md) is compiler-generated scalar deleting destructor glue that calls `0x00544580`, frees via `0x004f4ac0` when `flags & 1` is set and `flags & 4` is clear, and returns the object pointer otherwise.
- `HandlePointerOrMouseEvent` is reached through the secondary `TabPane` vtable slot `0x0061b520`; the vtable bytes at `0x0061b51c` include `0x004cfd82`, `0x004cfa10`, `0x004cfb10`, and `0x00544dd0`, confirming the slot context.
- Secondary cell `0x0061b520` / offset `+0x04` is the pointer/mouse-family override [UID:00034O][0x004cfa10-0x004cfb0a.TabPaneHandlePointerOrMouseEvent](by-memory/0x004cfa10-0x004cfb0a.TabPaneHandlePointerOrMouseEvent.md); cell `0x0061b524` / `+0x08` is the separate key/text-family [UID:00034P][0x004cfb10-0x004cfb15.TabPaneHandleKeyOrTextEvent](by-memory/0x004cfb10-0x004cfb15.TabPaneHandleKeyOrTextEvent.md). Both are secondary-interface methods and neither identifies or absorbs the primary paint slot.
- `HandlePointerOrMouseEvent` reads the UserPane input-lock byte at historical `dword_67A748 + 0x13eb1d`, then consumes exact [UID:00004L][Event](by-class/Event.md) fields: `m_type +0x4`, pointer `m_y +0x8`, pointer `m_x +0xc`, and key-payload-overlay `m_messageTime +0x10c` / 268 (Verified with int_convert.py). It returns false for locked input, unsupported event types, misses, and unsupported double-click action codes.
- Both resolver calls pass `m_y,m_x`. Left-button-down (`1`) handles tab codes `0..5`; double-click (`2`) handles `0`, `1`, `2`, and `5`. UID00034R returns through `al` as a signed byte and calls canonical `PointInRect(mouseY, mouseX, &rect)`.
- Action helper calls are `0x005a4f70`, a free one-argument `__stdcall`-shape opcode `0x2d` send/store helper; free zero-argument `0x005a4db0`, `0x005a4e40`, `0x005a4e70`, and `0x005a4f40` mode/sound helpers; and true `UserPane`-receiver `0x005a4ea0` for the collection action. Source helper names remain behavior-grounded, but receiver/calling shape and required declarations are resolved.
- `0x004cfb20-0x004cfc5c` has a real prolog and local jump table at `0x004cfc40`, but live IDA has no function object, no direct xrefs to `0x004cfb20`, and no loaded-segment pointer hits to the entry. B005's direct PE scan also found no rel32 call/jump, rel8 branch, VA/RVA dword, export, or non-local table route to the entry or case labels; the body/table bytes are unique in the PE. Treat it as a retained source-shaped `TabPane::BuildTabActionRect` helper or dead/inlined duplicate.
- `ResolveTabActionCode` builds rectangles with `0x004b7c50`, tests point containment through `0x004b7e80`, returns the matching tab code `0..5`, and returns `-1` when no rectangle contains the point. The executable resolver has its own switch table at `0x004cfd50` and does not call `0x004cfb20`; generated source may call `BuildTabActionRect` only as a source-level de-duplication/inlining hypothesis.

## Tab Regions

| Code | Rect |
| --- | --- |
| `0` | `(2, 1)-(20, 46)` |
| `1` | `(2, 47)-(20, 93)` |
| `2` | `(2, 95)-(20, 140)` |
| `3` | `(2, 142)-(20, 187)` |
| `4` | `(2, 189)-(20, 234)` |
| `5` | `(2, 236)-(20, 281)` |

## External State

- [UID:0000SE][g_pTabPane](by-global/g_pTabPane.md) at `0x0069adfc`.
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) documents canonical `UserPane *g_pUserPane` / historical `dword_67A748` (older generated `g_pAppMan` label); the pointer/mouse override checks byte `+0x13eb1d` before dispatching selected action helpers.
- Action helpers around `0x005a4db0-0x005a4f70` have resolved free-function versus UserPane-member ABI classes. Exact lexical names remain inferred and are supplied by the appropriate UserPane/action-helper headers rather than fabricated as TabPane members.

## Open Questions

- The paint identity, signature, range, owner, emitter, and body are resolved. Original PDB/source would be required only to prove the exact access token and lexical spelling beyond the strongly supported `OnPaint` convention.
- Name the six tab regions and action codes from UI/resource evidence rather than only helper behavior.
- Decide whether final source keeps `TabPane.cpp` separate or folds it with [UID:0000JZ][IconsPane](by-file/IconsPane.md) into an old-HUD controls module.
- Finalize whether generated source should keep the `BuildTabActionRect` call from `ResolveTabActionCode` as a source-level factoring/inlining reconstruction or inline the six rectangle cases exactly as the resolver machine code does. The raw `0x004cfb20` helper itself is resolved as source-shaped retained `TabPane` helper/dead or inlined duplicate with no proven live entry route.
- UID00034O/34P signatures, Event fields, y/x order, UID00034R byte return, class declarations, inheritance, no-field layout, and child placement are resolved. Original source/PDB would be required only to prove exact helper/member lexical spellings and public/private tokens; those are confidence caps, not source-generation blockers.

## Draft C++ Status

The managed block now emits a complete realistic `TabPane : public Pane, public Singleton<TabPane>` declaration. Public declarations cover constructor, virtual destructor, exact pointer/mouse and key/text EventHandler overrides, and `OnPaint`; private declarations cover retained `BuildTabActionRect` and signed-byte `ResolveTabActionCode`; `g_pTabPane` is declared extern. The class closes before `[[CHILDREN]]`, so every exact child definition is emitted at namespace scope. No data member is declared because the `0xf8` allocation and Singleton PMD prove inherited Pane state plus empty-base optimization. EventHandler and TimerHandler are inherited through Pane, not repeated as direct bases; child drafts avoid explicit vptr stores, adjustors, scalar flags, raw RTTI arrays, or base-destructor calls.

## Score Rationale

Completion `93` and confidence `94` reflect the complete class declaration, exact primary/secondary/tertiary contracts, OnPaint source cause, UID00034O/34P Event signatures, UID00034R byte/y-x contract, complete RTTI hierarchy/PMDs, Singleton EBO, exact `0xf8` allocation, lifecycle stores, singleton xrefs, destructor split, six rectangles, and retained-helper no-route policy. Scores remain below `95` because no original PDB/source proves exact access tokens, tab labels, action-helper/member spellings, or final physical grouping with `IconsPane`.

## Cross-References

- [UID:0000OF][TabPane](by-file/TabPane.md)
- [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md)
- [UID:00034L][0x004cf980-0x004cf9ca.TabPaneConstructor](by-memory/0x004cf980-0x004cf9ca.TabPaneConstructor.md)
- [UID:00034M][0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper](by-memory/0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper.md)
- [UID:00034N][0x004cfa00-0x004cfa01.TabPaneOnPaint](by-memory/0x004cfa00-0x004cfa01.TabPaneOnPaint.md)
- [UID:00034O][0x004cfa10-0x004cfb0a.TabPaneHandlePointerOrMouseEvent](by-memory/0x004cfa10-0x004cfb0a.TabPaneHandlePointerOrMouseEvent.md)
- [UID:00034P][0x004cfb10-0x004cfb15.TabPaneHandleKeyOrTextEvent](by-memory/0x004cfb10-0x004cfb15.TabPaneHandleKeyOrTextEvent.md)
- [UID:00034Q][0x004cfb20-0x004cfc5c.TabPaneRawRectangleBuilder](by-memory/0x004cfb20-0x004cfc5c.TabPaneRawRectangleBuilder.md)
- [UID:00034R][0x004cfc60-0x004cfd4d.TabPaneResolveActionCode](by-memory/0x004cfc60-0x004cfd4d.TabPaneResolveActionCode.md)
- [UID:00034S][0x004cfd4d-0x004cfd6c.TabPaneResolveActionCodeJumpTable](by-memory/0x004cfd4d-0x004cfd6c.TabPaneResolveActionCodeJumpTable.md)
- [UID:00034U][0x004cfd82-0x004cfd98.TabPaneDestructorAdjustorThunks](by-memory/0x004cfd82-0x004cfd98.TabPaneDestructorAdjustorThunks.md)
- [UID:00034W][0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor](by-memory/0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor.md)
- [UID:0000SE][g_pTabPane](by-global/g_pTabPane.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:00006B][IconsPane](by-class/IconsPane.md)

## Changes

- 2026-07-14 B003 UID00034N focused class/source repair:
  - Before: `89/91`, blank class formal accepted as complete, UID00034O/34P carried provisional generic names/signatures, UID00034R carried stale int/x-y/rect-first source shape, and generated TabPane.cpp retained UID0000EB Empty Emitter Marker.
  - Changed to: `93/94` with complete managed `TabPane : Pane, Singleton<TabPane>` declaration, constructor/destructor, exact EventHandler overrides, OnPaint, private geometry helpers, extern singleton, class close before `[[CHILDREN]]`, and no fabricated data fields. UID00034O/34P/34R declarations now match their corrected destination formals.
  - Evidence: resumed live MCP database `3fc1dcef`, exact secondary slot comparison, Event layout, UID00034O/34P bytes and routes, UID00034R byte-register/y-x flow, RTTI PMDs, `0xf8` allocation, and compiler-source disposition. Public virtual/private helper access is the highest-probability source shape and remains explicitly inference-capped.

- 2026-07-14 B003 UID00034N OnPaint class sync:
  - Before: `87/87`; the class listed UID00034N as a null virtual, omitted the Pane/TabPane/IconsPane primary-slot comparison and full RTTI/Singleton layout evidence, and retained a blank class formal.
  - Changed to: `89/91`; UID00034N is the explicit empty `void TabPane::OnPaint()` primary `+0x44` override, with exact primary/secondary/tertiary roles, Pane/IconsPane comparison, RTTI hierarchy/PMDs, Singleton EBO, `0xf8` allocation, lifecycle stores, secondary pointer/mouse and key/text roles, source/compiler distinction, negative evidence, and bounded score caps. Owner/emitter UID0000OF, reconstructable true, blank position, and the accepted blank class formal remain unchanged.
  - Evidence: live MCP session `e98ecbb2` proved the one-byte body/hash/ABI, sole `0x0061b514` xref, distinct same-slot targets, all three COL/table views, hierarchy PMDs, sole caller allocation, and lifecycle writers. Historical `nullsub_30`, `TabPaneNullVirtual`, and `OnNoOpVirtual` are superseded provenance, not current method identity.
- 2026-06-07 A005 resolved-name cleanup:
  - Before: tab input-state evidence used historical `dword_67A748` and the older generated `g_pAppMan` label.
  - After: the page records canonical `g_pCollectionData` beside the historical label and cross-links the global page.
  - Evidence: generated resolved-name report maps `dword_67A748` to `g_pCollectionData`; existing page evidence already ties the checked byte at `+0x13eb1d` to client/player state gating tab action dispatch.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `82`, confidence `76`.
- Evidence: the page documents old-layout tab-pane responsibility, layout/vtable evidence, singleton, method map, external state, and open action-code/source-grouping questions; confidence remains capped by unresolved tab-region names and final grouping with `IconsPane`.
- 2026-06-04 live IDA pass:
  - Before: completion `82`, confidence `76`, reconstructable metadata blank.
  - Changed to: completion `86`, confidence `86`, `RECONSTRUCTABLE:TRUE`, and parent [UID:0000OF][TabPane](by-file/TabPane.md).
  - Evidence: live IDA verified exact function boundaries, constructor caller, singleton xrefs, vtable slots/writes, destructor flag behavior, action-helper dispatch, exact tab rectangles, and the raw unreferenced `0x004cfb20-0x004cfc5c` rectangle helper; remaining uncertainty is limited to final tab labels, helper names, and source grouping.
- 2026-06-10 B001-034 split repair:
  - Changed: replaced the broad main-range-only method inventory with exact child pages [UID:00034L][0x004cf980-0x004cf9ca.TabPaneConstructor](by-memory/0x004cf980-0x004cf9ca.TabPaneConstructor.md) through [UID:00034W][0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor](by-memory/0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor.md) for the `TabPane` constructor, cleanup, virtuals, input handler, raw rectangle helper, resolver, jump-table artifact, destructor thunks, and scalar deleting destructor.
  - Evidence: IDA MCP reconfirmed all target-range boundaries, vtable refs, singleton writes/clears, raw helper negative xrefs/pointer hits, resolver table bytes, thunk disassembly, and successor `IdleWatcher` boundary. Score remains `86/86`; the parent gate was already met.
- 2026-06-18 Rule 26 draft-C++ incorporation:
  - Changed: the exact source-emitting B001 split children now include first-draft C++ for the constructor, cleanup helper, no-op/false virtuals, input handler, raw rectangle builder, resolver, and source-visible destructor behavior.
  - Evidence: the draft code is derived from the existing IDA-backed split facts, Wave2/shared-helper behavior names for `0x005a4db0`, `0x005a4e40`, and `0x005a4f70`, the documented tab rectangles, vtable-only compiler artifact classification, and singleton lifecycle evidence. Final tab labels, exact helper names, and physical source grouping with `IconsPane` remain open but no longer block child-level draft C++.
- 2026-06-21 Rule 26 B005 raw-helper incorporation:
  - Changed to: completion `87`, confidence `87`; [UID:00034Q][0x004cfb20-0x004cfc5c.TabPaneRawRectangleBuilder](by-memory/0x004cfb20-0x004cfc5c.TabPaneRawRectangleBuilder.md) is now documented as a retained source-shaped private `TabPane::BuildTabActionRect` helper/dead or inlined duplicate with no live entry route, and [UID:00034R][0x004cfc60-0x004cfd4d.TabPaneResolveActionCode](by-memory/0x004cfc60-0x004cfd4d.TabPaneResolveActionCode.md) is documented as duplicating/inlining the rectangle switch in machine code.
  - Evidence: B005 direct PE scan found unique body/table bytes, exact local table targets, eleven-byte prepad, four-byte postpad, no rel32/rel8/VA/RVA/export route, local-only case-label references, and resolver-local table/direct `InitRectBounds`/`PointInRect` calls.
- 2026-07-02 B014 constructor source-quality support sync:
  - No class score change.
  - Summary/evidence: [UID:00034L][0x004cf980-0x004cf9ca.TabPaneConstructor](by-memory/0x004cf980-0x004cf9ca.TabPaneConstructor.md) was rechecked with current MCP evidence: exact `0x004cf980-0x004cf9ca` / `sub_4CF980` size `0x4a`, 23-instruction body, one direct caller `0x004f812d`, `g_pTabPane` write `0x004cf9a4`, and three `TabPane` vtable stores. The caller allocation/placement evidence puts the constructed pane at `(808,79)-(831,365)`, supporting the existing old-layout `TabPane` route while leaving final tab labels/source grouping open.
- 2026-07-02 B015 destructor source-shape sync:
  - No class score change.
  - Summary/evidence: [UID:00034M][0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper](by-memory/0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper.md) is now documented as the ordinary/non-deleting `TabPane::~TabPane()` source body with formal C++ `g_pTabPane = NULL;`, while [UID:00034W][0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor](by-memory/0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor.md) is scalar deleting destructor glue with comment-only C++. B015 MCP evidence reconfirmed [UID:00034M][0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper](by-memory/0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper.md) as an exact `0x29` function with no direct xrefs, three `TabPane` vtable writes, `g_pTabPane` clear at `0x004cf9ea`, tail transfer to `Pane::~Pane()` at `0x00544580`, constructor/scalar-wrapper parity, and boundary padding. This prevents duplicate generated `TabPane::~TabPane()` output without changing owner/emitter route.
- 2026-07-04 B003 UID00034O source-ready sync:
  - No class score change.
  - Historical stage: session `60724697` established UID00034O's exact range/CFG/xref/padding/dispatch facts and the child then emitted provisional `bool TabPane::HandleInputEvent(const PaneInputEvent *event)`. The 2026-07-14 focused family repair supersedes that lexical/formal shape with `HandlePointerOrMouseEvent(Event *)` while retaining the binary evidence.
