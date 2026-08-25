*** UID:00003Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class DescPane;
extern DescPane *g_pDescPane;

class DescPane : public Pane
{
public:
    DescPane();
    virtual ~DescPane();

    static DescPane *GetSingleton();
    void SetSourceAndIndex(Pane *source, int selectedIndex);

protected:
    virtual void OnPaint();

private:
    Pane *m_pDescriptionSource;
    int m_selectedDescriptionIndex;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DescPane

## Status

- Confidence: very strong for the complete source declaration, direct Pane
  inheritance, singleton ownership, three-view vtable cause, borrowed
  Pane/index tail, five source methods, and compiler/source boundary.
- Likely source file: [UID:0000IS][DescPane](by-file/DescPane.md)
- Address range: [UID:00012K][0x0049d6f0-0x0049d89f.DescPane](by-memory/0x0049d6f0-0x0049d89f.DescPane.md)
- Vtables: [UID:0001XC][DescPaneVtables](by-type/by-vtable/DescPaneVtables.md), exact data [UID:0002NA][0x006189dc-0x00618a60.DescPaneVtableData](by-memory/0x006189dc-0x00618a60.DescPaneVtableData.md), bases `0x006189dc`, `0x00618a28`, and `0x00618a58`
- Likely original source file: `DescPane.cpp`
- Declaration emission: this page supplies the complete class declaration and
  the `extern g_pDescPane` declaration. Its closing `};` precedes
  `[[CHILDREN]]`, so constructor, destructor, getter, setter, and `OnPaint`
  definitions emit outside the class body. UID00012K is a non-emitting
  split/index and no longer supplies an aggregate insertion marker.

## Class Purpose

`DescPane` is a singleton-backed description pane. Its stable class-local tail is borrowed `Pane *m_pDescriptionSource` at `+0xf8` and `int m_selectedDescriptionIndex` at `+0xfc`; no destructor path releases the Pane pointer and no persistent description text field exists. `OnPaint` unconditionally calls `SetDrawColor(0)`, clears inherited draw-mode byte `+0x70`, and calls `FillRect(&m_bounds)`, then conditionally delegates to inherited Pane slot `+0x24` / [UID:0004IX][0x00544a20-0x00544a35.PaneGetDescription](by-memory/0x00544a20-0x00544a35.PaneGetDescription.md) with an uninitialized `wchar_t[1024]` scratch buffer.

The target does not read, draw, cache, measure, free, or persist the scratch after the call. Null source and selected index `-1` skip only the description dispatch, not the preceding clear/fill work. No custom provider UDT/vtable, direct target caller, fallback string, error branch, retry, or ownership transfer is evidenced.

The class is a reusable UI control, not a feature-dialog owner. The selected entry can represent item/object/list data supplied by another pane.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| split/index island | [UID:00012K][0x0049d6f0-0x0049d89f.DescPane](by-memory/0x0049d6f0-0x0049d89f.DescPane.md) | `92/93` non-reconstructable, non-emitting exact index over the five source methods and compiler destructor glue; formal C++ is blank. |
| constructor | [UID:00012J][0x0049d6f0-0x0049d73c.DescPaneConstructorRaw](by-memory/0x0049d6f0-0x0049d73c.DescPaneConstructorRaw.md) | Constructs the `Pane` base with style `1`, installs three compiler-emitted `DescPane` vtables, clears `m_pDescriptionSource`, sets `m_selectedDescriptionIndex` to `-1`, registers `g_pDescPane`, and now carries first-draft `DescPane::DescPane()` C++. IDA currently reports this start as `Not a function`. |
| non-deleting destructor | [UID:00012L][0x0049d740-0x0049d769.DescPaneDestructor](by-memory/0x0049d740-0x0049d769.DescPaneDestructor.md) | Source-authored `DescPane::~DescPane()` body: clears `g_pDescPane`; compiler lowering restores vtables and runs `Pane` base cleanup. |
| singleton getter | [UID:00012M][0x0049d770-0x0049d776.DescPaneGetSingleton](by-memory/0x0049d770-0x0049d776.DescPaneGetSingleton.md) | Static class-style accessor returning `g_pDescPane` from `0x0069adf8`; now carries first-draft `DescPane::GetSingleton()` C++ on the child page. |
| source/index setter | [UID:00012N][0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw](by-memory/0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw.md) | Emits exact first-draft `DescPane::SetSourceAndIndex(Pane *source, int selectedIndex)`: compares/stores the borrowed Pane/index pair and calls inherited `InvalidateRect(&m_bounds)` via primary slot `+0x20` only on change. Original setter spelling and direct reachability remain caps. |
| `OnPaint` | [UID:00012O][0x0049d7c0-0x0049d81e.DescPaneOnPaint](by-memory/0x0049d7c0-0x0049d81e.DescPaneOnPaint.md) | Exact primary `+0x44` override at `92/94`; clears/fills inherited pane state, then guards the borrowed Pane/index and calls `GetDescription` with a `wchar_t[1024]` scratch. Exact managed C++ is child-owned. |
| destructor adjustor thunks | [UID:00012P][0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks](by-memory/0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks.md) | Non-emitting compiler-generated secondary/tertiary adjusted-this thunks. |
| scalar deleting destructor | [UID:00012Q][0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor](by-memory/0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor.md) | Non-emitting MSVC deleting-destructor wrapper generated from `DescPane::~DescPane()`; documents vtable/thunk route, singleton-clear duplication, base cleanup, and optional delete behavior. |

## Layout Notes

See [UID:0001U3][DescPaneLayout](by-type/by-struct/DescPaneLayout.md). The stable class-local tail is:

- `+0xf8`: borrowed `Pane *m_pDescriptionSource`.
- `+0xfc`: selected description index, initialized to `-1`.

The source type is now concrete `Pane *`, not a standalone provider interface. Pane primary slot `+0x24` is exact [UID:0004IX][0x00544a20-0x00544a35.PaneGetDescription](by-memory/0x00544a20-0x00544a35.PaneGetDescription.md), and DescPane primary slot `+0x44` is exact `OnPaint`. The historical `DescPaneDescriptionSource` and `char *` declarations are superseded. Constructor initialization remains `m_pDescriptionSource(NULL)` / `m_selectedDescriptionIndex(-1)`; borrowed lifetime and no persistent text remain explicit.

## Live IDA Evidence

- B008's 2026-07-04 implementation callback incorporates current live MCP session `73c77998` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`: `server_health` was OK; `lookup_funcs` reconfirmed raw/non-function starts `0x0049d6f0` and `0x0049d780`, modeled child sizes `0x29`, `0x6`, `0x5e`, `0xb`, `0xb`, and `0x5f`, and successor `0x0049d8a0`; `get_bytes`/`insn_query` reconfirmed the padding and raw constructor/setter instructions; `xrefs_to` reconfirmed no direct xrefs to raw starts, four local refs to `g_pDescPane`, vtable slot `0x00618a20 -> 0x0049d7c0`, adjustor slots `0x00618a28`/`0x00618a58`, and primary scalar wrapper slot `0x006189dc`; `search_structs`/`type_query` found no local `DescPane` or provider UDT.
- IDA MCP reports no function at the constructor-shaped `0x0049d6f0` block. The previous modeled function is `sub_49D5E0` at `0x0049d5e0-0x0049d6ed`, and the next modeled function is `sub_49D740` at `0x0049d740-0x0049d769`.
- Raw disassembly at `0x0049d6f0-0x0049d73b` calls `sub_544460(1)`, installs DescPane vtable views at `this+0x00 -> 0x006189dc`, `this+0xa0 -> 0x00618a28`, and `this+0xa4 -> 0x00618a58`, clears `this+0xf8`, sets `this+0xfc` to `-1`, and stores `this` to `dword_69ADF8` / [UID:0000QR][g_pDescPane](by-global/g_pDescPane.md).
- IDA MCP reports no function at the source/index setter-shaped `0x0049d780` block. Current B006 implementation evidence from session `46666bf7` confirms the complete raw body is `0x0049d780-0x0049d7b2`: it compares arguments against `this+0xf8` and `this+0xfc`; when either differs, it stores both values and calls primary-vtable slot `+0x20` with bounds at `this+0x44`. [UID:0002V7][0x005446b0-0x005446d4.PaneSetMode](by-memory/0x005446b0-0x005446d4.PaneSetMode.md) resolves the same slot pattern to `Pane::InvalidateRect`, so the setter's source-facing call is `InvalidateRect(&m_bounds)`.
- `sub_49D740` at `0x0049d740-0x0049d769` restores all three DescPane vtable views, clears `dword_69ADF8`, and calls pane cleanup `sub_544580`.
- `sub_49D770` at `0x0049d770-0x0049d776` returns `dword_69ADF8`.
- Complete accepted analysis of `sub_49D7C0` resolves it as `OnPaint`: `sub_4B9660(this,0)` is `SetDrawColor(0)`, byte `this+0x70` is `m_drawMode`, `dword_69B3FC(this,this+0x44)` is `FillRect(&m_bounds)`, and the guarded primary `+0x24` call is Pane `GetDescription` with a `wchar_t[1024]` local. Historical invalidation/narrow-buffer interpretation is superseded.
- `sub_49D81E` and `sub_49D829` are 11-byte adjustor thunks that subtract `0xa0` and `0xa4` from secondary-base `this` pointers before forwarding to `sub_49D840`.
- `sub_49D840` at `0x0049d840-0x0049d89f` is the scalar deleting destructor: it restores all three DescPane vtable views, clears `dword_69ADF8`, calls `sub_544580`, and conditionally frees through `sub_4F4AC0` when `(flags & 1) != 0 && (flags & 4) == 0`.
- IDA xrefs to `0x0069adf8` are limited to the DescPane island: constructor store at `0x0049d731`, non-deleting destructor clear at `0x0049d75a`, singleton getter read at `0x0049d770`, and scalar deleting destructor clear at `0x0049d860`.
- Vtable data places the scalar deleting destructor at `0x006189dc`, `OnPaint` at primary `+0x44` / `0x00618a20`, adjustor thunks at `0x00618a28`/`0x00618a58`, and the next DialogPane RTTI at `0x00618a60`. Inherited primary `+0x24` resolves to Pane `GetDescription`; constructor/destructor paths still xref all three vtable bases.
- IDA reports no direct callers or vtable pointer slots for raw starts `0x0049d6f0` and `0x0049d780`, so current naming relies on raw disassembly, singleton/vtable ownership, and the contiguous class island.
- 2026-06-18 B005 raw-memory recheck found no raw pointer or rel32 call/jump target to raw constructor start `0x0049d6f0`, and no raw pointer or rel32 route to raw setter start `0x0049d780`. Positive controls still found `RefreshDescription` at vtable slot `0x00618a20`, the scalar deleting destructor at primary vtable slot `0x006189dc`, and adjustor-thunk rel32 jumps to the scalar destructor at `0x0049d824` and `0x0049d82f`.
- B005's immediate scan confirmed the constructor/destructor/scalar-destructor stores for vtable bases `0x006189dc`, `0x00618a28`, and `0x00618a58`, plus singleton refs to `0x0069adf8` in the constructor, destructor, getter, and scalar destructor. This supports `DescPane` ownership but keeps raw-start reachability as a confidence cap.

## Source-Quality Decisions

| Issue | Current decision | Notes |
| --- | --- | --- |
| Declaration and child route | This page emits the complete declaration followed by `[[CHILDREN]]`; [UID:00012K][0x0049d6f0-0x0049d89f.DescPane](by-memory/0x0049d6f0-0x0049d89f.DescPane.md) is a blank non-emitting index. | Constructor/destructor/getter/setter/OnPaint bodies stay child-owned; compiler thunks/wrappers stay no-code. |
| Constructor C++ | [UID:00012J][0x0049d6f0-0x0049d73c.DescPaneConstructorRaw](by-memory/0x0049d6f0-0x0049d73c.DescPaneConstructorRaw.md) emits first-draft `DescPane::DescPane()`. | `Pane(1)`, `m_pDescriptionSource(NULL)`, `m_selectedDescriptionIndex(-1)`, and `g_pDescPane = this;` are source-shaped enough for staged reconstruction. |
| Singleton getter C++ | [UID:00012M][0x0049d770-0x0049d776.DescPaneGetSingleton](by-memory/0x0049d770-0x0049d776.DescPaneGetSingleton.md) emits first-draft `DescPane *DescPane::GetSingleton()`. | The body is exactly `return g_pDescPane;`; raw `dword_69ADF8` is only an IDA storage alias, and no-direct-caller evidence caps final audit rather than blocking the child method body. |
| Vtable writes | Do not hand-emit in source. | Constructor/destructor vtable stores are compiler output from the source-declared polymorphic class. |
| Description source | Use borrowed `Pane *` and inherited [UID:0004IX][0x00544a20-0x00544a35.PaneGetDescription](by-memory/0x00544a20-0x00544a35.PaneGetDescription.md). | Exact Pane vtable/signature evidence supersedes the provisional custom interface; original field/method spellings remain inferred. |
| Setter/helper name | [UID:00012N][0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw](by-memory/0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw.md) now uses first-draft `SetSourceAndIndex`. | The name is descriptive, not proven original spelling. Missing direct route and exact provider-interface spelling cap confidence, but they no longer block this child method's formal C++ body. |
| Source placement | Keep [UID:0000IS][DescPane](by-file/DescPane.md) `NexusTK/ui/controls/DescPane.cpp`. | B005 rejected `Pane.cpp`, `DialogPane.cpp`, feature-dialog owners, and generic UI core as less specific or unsupported. |
| Destructor source/glue split | [UID:00012L][0x0049d740-0x0049d769.DescPaneDestructor](by-memory/0x0049d740-0x0049d769.DescPaneDestructor.md) owns/emits `DescPane::~DescPane()`, while [UID:00012P][0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks](by-memory/0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks.md) and [UID:00012Q][0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor](by-memory/0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor.md) stay non-emitting compiler glue. | Source C++ clears `g_pDescPane`; vtable restores, adjusted-this dispatch, scalar-delete flags, optional free, and base teardown are compiler lowering. |

## 2026-06-16 A001 Evidence Refresh

- Live IDA MCP session `b001_mappane_0001AW_20260616` was queried read-only. `server_health` reported module `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready, and the read-only input path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- `lookup_funcs` reconfirmed the raw/non-function blockers: `0x0049d6f0`, `0x0049d780`, and the half-open end `0x0049d89f` are not modeled functions. The modeled children remain `sub_49D740` size `0x29`, `sub_49D770` size `0x6`, `sub_49D7C0` size `0x5e`, `sub_49D81E`/`sub_49D829` size `0xb`, and `sub_49D840` size `0x5f`.
- `xrefs_to` reconfirmed exact singleton/vtable ownership: `0x0069adf8` has four refs, all inside the DescPane island; vtable bases `0x006189dc`, `0x00618a28`, and `0x00618a58` are written/restored by constructor/destructor paths; refresh `0x0049d7c0` is referenced only from the vtable slot at `0x00618a20`.
- `func_profile 0x0049d7c0` shows no code callers, callees `sub_4B9660`, self, and `__security_check_cookie`, and constant `0x804`/decimal `2052`, matching the stack-buffer plus cookie shape documented by the memory page. `func_profile 0x0049d840` reconfirmed the scalar deleting destructor vtable constants and conditional delete flags.
- `search_structs`/`type_query` found no IDA UDT for `DescPane`, and `entity_query names *DescPane*` only returned decorated vtable/RTTI names. The provider interface name and source-facing setter name therefore remain unsafe to finalize even though behavior and ownership are stable.

## Score Rationale

Completion/confidence are `92/94`: the complete declaration now captures the
single direct Pane base, virtual destructor, static singleton accessor,
Pane-typed setter, protected `OnPaint` override, exact `+0xf8/+0xfc` tail,
five source-method children, singleton declaration, and compiler-only table,
thunk, deleting-wrapper, and base-teardown boundaries. Original stripped
spellings, the symbolic name for `Pane(1)`, and raw constructor/setter
reachability keep the page below a 95+ final-audit score without leaving a
source integration blocker.

## Cross-References

- [UID:0000IS][DescPane](by-file/DescPane.md)
- [UID:00012K][0x0049d6f0-0x0049d89f.DescPane](by-memory/0x0049d6f0-0x0049d89f.DescPane.md)
- [UID:0001U3][DescPaneLayout](by-type/by-struct/DescPaneLayout.md)
- [UID:0001XC][DescPaneVtables](by-type/by-vtable/DescPaneVtables.md)
- [UID:0002NA][0x006189dc-0x00618a60.DescPaneVtableData](by-memory/0x006189dc-0x00618a60.DescPaneVtableData.md)
- [UID:0000QR][g_pDescPane](by-global/g_pDescPane.md)
- [UID:0001PB][0x0069adf8-0x0069adfc.g_pDescPane](by-memory/0x0069adf8-0x0069adfc.g_pDescPane.md)
- [UID:0000A2][Pane](by-class/Pane.md)

## 2026-07-16 B001 UID0002NA Accepted Callback

- Applied `92/94`, file owner/emitter UID0000IS, source position 10, and the
  complete Destination 1 declaration.
- RTTI proves the only direct source base is Pane. GrafPort, LObject,
  EventHandler, and TimerHandler occur through Pane; the `+0xa0/+0xa4`
  facets must not be repeated as direct bases or explicit vptr members.
- The `0x100` object has no additional DescPane-local state beyond borrowed
  `Pane *m_pDescriptionSource` at `+0xf8` and
  `int m_selectedDescriptionIndex` at `+0xfc`.
- Source order is constructor 10, destructor 20, singleton getter 30,
  source/index setter 40, `OnPaint` 50, layout coverage 60, and vtable
  coverage 70. `g_pDescPane` is the one file-level global definition at
  position 20.
- The primary vtable contains inherited Pane behavior through `+0x40` and the
  exact DescPane `OnPaint` override at `+0x44`; EventHandler and TimerHandler
  views are inherited without source overrides.
- Constructor vptr stores, destructor restores, `this-0xa0/this-0xa4`
  adjustors, scalar delete flags, optional storage free, RTTI objects, and
  literal table dwords are compiler output. Source C++ contains no explicit
  vptr assignment, adjustor body, scalar-wrapper body, base-destructor call,
  or handwritten table.
- The source pointer is borrowed: no destructor path releases it. `OnPaint`
  clears/fills before its guards, uses `wchar_t[1024]`, performs one
  `Pane::GetDescription` dispatch, and does not read, draw, cache, measure,
  free, or persist the scratch afterward.
- Historical class-level blank-formal, UID00012K aggregate-emitter,
  standalone provider-interface, narrow-buffer, RefreshDescription, and
  current-facing incomplete-header claims are superseded. The older evidence
  remains useful only as dated reconstruction history.

## Changes

- 2026-07-16 B001 UID0002NA accepted callback:
  - Raised `88/91 -> 92/94`, set source position 10, and installed the
    complete no-loss DescPane declaration.
  - Preserved the five exact child method bodies and all current Pane,
    singleton, layout, vtable, raw-start, negative, and historical evidence.
  - Reclassified UID00012K as a blank non-emitting split/index and ensured the
    class-closing `};` appears before `[[CHILDREN]]`.
- 2026-07-12 B003 UID00012O accepted callback: raised `86/88 -> 88/91`; replaced current custom-interface/narrow-buffer/RefreshDescription prose with borrowed `Pane *`, `wchar_t[1024]`, exact `GetDescription`, and primary `+0x44` `OnPaint`; preserved singleton/vtables, raw-start negatives, compiler glue, class/file routes, and unrelated methods. Historical custom-provider claims below remain labeled prior states.
- 2026-07-04 B008 aggregate marker implementation callback:
  - Before: [UID:00012K][0x0049d6f0-0x0049d89f.DescPane](by-memory/0x0049d6f0-0x0049d89f.DescPane.md) was an `86/88` aggregate with a blank formal block, causing generated `DescPane.cpp` to show a bare empty marker for the aggregate even though source-bearing children already emitted.
  - Changed to: records UID00012K as `88/90` with a formal `[[CHILDREN]]` marker. This is an aggregate insertion point only; it does not authorize a pasted class declaration or duplicate child method bodies in this class page.
  - Summary/evidence: B008 MCP session `73c77998` confirms exact range, padding, raw constructor/setter non-function starts and no-xref caps, modeled child sizes, singleton refs, vtable refs/slots, provider/index fields, no local type evidence, generated empty-marker defect, child-source/no-code split, and rejected `Pane`/`DialogPane`/feature-dialog/generic-UI/no-owner/range-extension alternatives.
- 2026-06-29 B006 setter implementation callback:
  - Before: the method table and source-quality table kept [UID:00012N][0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw](by-memory/0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw.md) provisional and treated setter/helper naming as a blocker for all emission.
  - Changed to: [UID:00012N][0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw](by-memory/0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw.md) is documented as first-draft `DescPane::SetSourceAndIndex(DescPaneDescriptionSource *source, int selectedIndex)` emission, using `m_pDescriptionSource`, `m_selectedDescriptionIndex`, and inherited `InvalidateRect(&m_bounds)`.
  - Summary/evidence: B006 current MCP session `46666bf7` proves the corrected `0x0049d780-0x0049d7b2` range, no external xrefs or pointer encodings to the raw start, the `+0xf8/+0xfc` compare/store pair, primary slot `+0x20` invalidation with `this+0x44`, and refresh-side consumption of the stored provider/index pair.
- 2026-06-19 B010 getter source-quality incorporation:
  - Before: the class method table only said the getter returns `g_pDescPane`, without recording first-draft C++ readiness or the raw-name/source-name decision.
  - Changed to: the getter row and source-quality table now state that [UID:00012M][0x0049d770-0x0049d776.DescPaneGetSingleton](by-memory/0x0049d770-0x0049d776.DescPaneGetSingleton.md) owns a first-draft static class accessor returning `g_pDescPane`; the no-direct-caller caveat remains a final-audit cap.
  - Summary/evidence: B010 verified exact getter bytes, raw `dword_69ADF8` aliasing, [UID:0000QR][g_pDescPane](by-global/g_pDescPane.md) naming, and unchanged class/file owner route.
- 2026-06-19 B011 destructor implementation callback:
  - Before: the method table treated [UID:00012Q][0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor](by-memory/0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor.md) as a source-bearing scalar deleting destructor and did not state that [UID:00012L][0x0049d740-0x0049d769.DescPaneDestructor](by-memory/0x0049d740-0x0049d769.DescPaneDestructor.md) owns the ordinary destructor source body.
  - Changed to: [UID:00012L][0x0049d740-0x0049d769.DescPaneDestructor](by-memory/0x0049d740-0x0049d769.DescPaneDestructor.md) is documented as the source-authored `DescPane::~DescPane()` body, while [UID:00012P][0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks](by-memory/0x0049d81e-0x0049d834.DescPaneDestructorAdjustorThunks.md) adjustor thunks and [UID:00012Q][0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor](by-memory/0x0049d840-0x0049d89f.DescPaneScalarDeletingDestructor.md) scalar deleting destructor are compiler-generated non-emitting destructor dispatch/delete glue.
  - Summary/evidence: B011 accepted source-quality implementation confirms singleton clear source body, compiler vtable/base lowering, adjusted-this thunk jumps, primary vtable deleting-destructor slot, scalar-delete flag tests, and optional object free behavior.
- 2026-06-18 B005 constructor source-quality incorporation:
  - Before: the class page implied constructor C++ should remain blank until provider/interface names were finalized.
  - Changed to: constructor row and class notes now record first-draft `DescPane::DescPane()` readiness, `m_pDescriptionSource`/`m_selectedDescriptionIndex` as best current field names, provisional `DescPaneDescriptionSource`, negative pointer/rel32 route checks, and explicit generated-vtable/adjustor-thunk policy.
  - Summary/evidence: B005 verified the exact constructor body, `Pane(1)` call, vtable stores, singleton publish, raw-start no-route checks, provider slot `+0x24` semantics, and source-placement ranking under `ui/controls/DescPane.cpp`.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `74/80`.
  - Summary/evidence: singleton role, provider/index layout, constructor/destructor/getter/update/refresh/destructor glue, vtables, and global xrefs were documented; remaining uncertainty was raw helper naming and lack of direct caller xrefs.
- 2026-05-31 reconstructability:
  - Before: `RECONSTRUCTABLE` was blank.
  - After: `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP reconfirms this as NexusTK-owned UI control code through the singleton global, DescPane vtable stores, and DescPane method island. Parent/code autogen remains blank because provider-interface names and raw helper names are not final.
- 2026-06-01 child evidence refresh:
  - Before: the class parent metadata was blank while child pages were still low-scored.
  - After: attached to [UID:0000IS][DescPane](by-file/DescPane.md); child constructor/setter/refresh pages now carry refreshed IDA MCP boundary, vtable, singleton, and provider-call evidence.
  - Summary/evidence: the raw constructor installs all three vtables and stores `g_pDescPane`; the raw setter updates `+0xf8/+0xfc` and invalidates; the modeled refresh reads the same fields and calls provider slot `+0x24`.
- 2026-06-04 live IDA refresh:
  - Before: the page was scored `74/80` and still mixed current IDA facts with stale source/cache phrasing.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:86`, with C++ reconstruction still blank.
  - Summary/evidence: live IDA confirms the raw constructor-shaped block at `0x0049d6f0-0x0049d73b`, raw source/index setter block at `0x0049d780-0x0049d7af`, modeled lifecycle/getter/refresh/destructor functions, exact singleton xrefs to `0x0069adf8`, and vtable rows at `0x006189dc`, `0x00618a20`, `0x00618a28`, and `0x00618a58`. The score remains below the final reconstruction gate because the constructor and setter are still raw non-function starts with no direct callers, and the provider interface remains behaviorally understood but not named with source-level confidence.
- 2026-06-16 A001 source-quality refresh:
  - Before: `COMPLETION:84`, `CONFIDENCE:86`.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`.
  - Summary/evidence: current IDA MCP rechecked the active IDB, raw constructor/setter non-function status, modeled child sizes, singleton/vtable xrefs, refresh/destructor profiles, and absence of IDA UDT/provider type evidence. Ownership/emitter remain [UID:0000IS][DescPane](by-file/DescPane.md); at that checkpoint class-level C++ stayed blank pending raw-start modeling and source-facing provider/helper names. [UID:00012J][0x0049d6f0-0x0049d73c.DescPaneConstructorRaw](by-memory/0x0049d6f0-0x0049d73c.DescPaneConstructorRaw.md) now carries staged constructor C++ while class/header finalization remains pending.
