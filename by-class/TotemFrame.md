*** UID:0000F4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class TotemFrame : public Pane, public Singleton<TotemFrame>
{
public:
    TotemFrame();
    virtual ~TotemFrame();
    virtual void OnPaint();
};

extern TotemFrame *g_pTotemFrame;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TotemFrame

## Status

- Confidence: very strong for class hierarchy, `0xf8` layout, source methods, singleton lifecycle, resources, and source route.
- Likely source file: [UID:0000OV][TotemFrame](by-file/TotemFrame.md)
- Address range: [UID:0001KC][0x00598cc0-0x00598ecf.TotemFrame](by-memory/0x00598cc0-0x00598ecf.TotemFrame.md)
- Current recovered file: `source-3/simroot_v2/class_TotemFrame.cpp`
- Singleton: direct `Singleton<TotemFrame>` base plus [UID:0000SK][g_pTotemFrame](by-global/g_pTotemFrame.md) at `0x0069b35c`
- Resource-string child: [UID:0003E4][0x0062e460-0x0062e47c.TotemFrameResourceStringData](by-memory/0x0062e460-0x0062e47c.TotemFrameResourceStringData.md)

## Class Purpose

`TotemFrame` is a `Pane` with a direct `Singleton<TotemFrame>` base used to display the totem/status frame. It positions itself on the right side of the screen and draws a frame from `TOTFRAME.EPD` with `NPAL7.PAL`. The frame index is read from [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md) through [UID:0000RV][g_pOldUserStatusPane](by-global/g_pOldUserStatusPane.md).

## Hierarchy And Layout

- Live RTTI provides three TotemFrame vtables at `0x0062e3dc`, `0x0062e428`, and `0x0062e458` and a seven-entry class hierarchy descriptor at `0x00651890`.
- The hierarchy includes TotemFrame, Pane, GrafPort, LObject, EventHandler, TimerHandler, and direct `Singleton<TotemFrame>`.
- The Singleton base-class descriptor at `0x006518dc` has PMD `{mdisp=0xf8, pdisp=-1, vdisp=0}` and attributes `0x40`, proving a direct non-virtual base.
- Both status constructor paths allocate `0xf8` bytes. The empty Singleton base occupies the one-past `+0xf8` address through MSVC empty-base optimization and does not add a stored member or increase allocation size.
- Primary, secondary, and tertiary vtable stores remain at object offsets `+0x00`, `+0xa0`, and `+0xa4`. These represent the established Pane/GrafPort/EventHandler/TimerHandler views, not handwritten fields.
- Source declaration order is `Pane` then `Singleton<TotemFrame>`. Construction publishes after Pane construction; reverse destruction clears the singleton before Pane teardown, matching the binary.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `TotemFrame::TotemFrame` | `0x00598cc0-0x00598d9e` | Constructs `Pane(0)` then direct `Singleton<TotemFrame>`, installs class views, and positions/registers the frame. Singleton publication is compiler-lowered base construction. |
| `~TotemFrame` / cleanup body | `0x00598da0-0x00598dc9` | Reinstalls vtables, performs implicit Singleton base clear, and runs Pane base cleanup. The human-written destructor body is empty. |
| `OnPaint` | `0x00598dd0-0x00598e3b` | Loads `TOTFRAME.EPD`, resolves frame index from old user status pane, renders with `NPAL7.PAL`. |
| constructor-unwind Singleton destructor | `0x00598e40-0x00598e4b` | Retained `Singleton<TotemFrame>` base destructor reached only through constructor EH; compiler output, not a source method. |
| adjustor thunk | `0x00598e4b-0x00598e56` | Adjusts from secondary subobject by `-0xa0` and forwards to scalar deleting destructor; compiler output. |
| adjustor thunk | `0x00598e56-0x00598e61` | Adjusts from secondary subobject by `-0xa4` and forwards to scalar deleting destructor; compiler output. |
| `ScalarDeletingDestructor` | `0x00598e70-0x00598ecf` | Clears singleton, destroys base pane, optional delete. |

## First-Draft C++ Readiness

B003's 2026-07-24 UID0002VR implementation raises this class to `92/94` and closes the hierarchy/source-lifecycle issue left by the earlier pass. Declaration-level C++ now includes direct `Singleton<TotemFrame>` inheritance and the matching global extern, with method bodies carried by [UID:0001KC][0x00598cc0-0x00598ecf.TotemFrame](by-memory/0x00598cc0-0x00598ecf.TotemFrame.md). The class block deliberately places `[[CHILDREN]]` after the class declaration so generated output emits method definitions after the class shell. The source-authored methods are the constructor, empty ordinary destructor, and `OnPaint`. Singleton publication/clear, constructor-unwind destruction, adjustor thunks, and scalar deleting destructor are compiler-generated products of the direct base/class declaration and must not be emitted as separate handwritten operations or methods.

The class remains the direct owner/emitter for [UID:0001KC][0x00598cc0-0x00598ecf.TotemFrame](by-memory/0x00598cc0-0x00598ecf.TotemFrame.md). File [UID:0000OV][TotemFrame](by-file/TotemFrame.md) remains the final `NexusTK/ui/panels/TotemFrame.cpp` route. [UID:0000SK][g_pTotemFrame](by-global/g_pTotemFrame.md) emits the sole zero definition at position 10; this class follows at position 20 with one extern. The vtable child [UID:0003E3][0x0062e3dc-0x0062e460.TotemFrameVtableData](by-memory/0x0062e3dc-0x0062e460.TotemFrameVtableData.md), resource-string child [UID:0003E4][0x0062e460-0x0062e47c.TotemFrameResourceStringData](by-memory/0x0062e460-0x0062e47c.TotemFrameResourceStringData.md), and executable cluster all attach to this class without duplicating physical storage.

## Evidence Notes

- B003 live MCP recheck found exactly 11 `g_pTotemFrame` references: five compiler/Singleton lifetime writes and six runtime consumers. Exact details are retained on UID0002VR and UID0000SK.
- PE evidence proves the physical slot is loader-zero, not initialized to `0xffffffff`; UID0002VR is now false/non-emitting while semantic UID0000SK owns the sole source definition.
- IDA MCP confirms all listed starts as real functions.
- Constructor xrefs come from old/new status update handlers at `0x005ba4a0` and `0x005bf7c0`.
- `OnPaint` reads `g_pOldUserStatusPane` at `0x0069b4ec` and calls `OldUserStatusPane::GetSpiritId` at `0x005bdc60`.
- 2026-06-12 A003 live IDA MCP reconfirmed `OnPaint` has the sole `TOTFRAME.EPD` xref at `0x00598e05`, and [UID:0003E4][0x0062e460-0x0062e47c.TotemFrameResourceStringData](by-memory/0x0062e460-0x0062e47c.TotemFrameResourceStringData.md) is now assigned to this class as the direct source owner of that filename literal.
- Panel-switch and related input/UI paths check `g_pTotemFrame` and mark the pane for deletion before changing the displayed status context.
- Active generated output omits `0x00598da0` and `0x00598e40`; disabled output marks `0x00598e4b` as missing code and emits a suspicious expression for `0x00598e56`.
- 2026-05-28 IDA MCP boundary recheck confirms the scalar deleting destructor ends at `0x00598ecf`, followed by one `0xcc` alignment byte before `TransferServerDialogPane` at `0x00598ed0`.
- 2026-06-19 B005 local PE byte audit confirms internal padding at `0x00598d9e-0x00598da0`, `0x00598dc9-0x00598dd0`, `0x00598e3b-0x00598e40`, and `0x00598e61-0x00598e70`. The pass resolves `0x00544580` as ordinary `Pane::~Pane()`, `0x004f4ac0` as MemoryMan-backed global `operator delete(void*)`, `0x005bdc60` as `OldUserStatusPane::GetSpiritId()`, `0x004d02f0` as `ResourceLayoutTable::LookupLayoutEntry`, and `0x004b9980` as shared `RenderTileFrame`.

## Source And Compiler Boundary

- Human source declares direct bases, constructor, virtual destructor, and `OnPaint`.
- Constructor source explicitly initializes `Pane(0)` and `Singleton<TotemFrame>()`, then performs bounds/layer/order work. It does not assign the global manually.
- Destructor source is an intentionally empty body. Implicit base destruction clears the singleton and tears down Pane in the observed order.
- `0x00598e40`, `0x00598e4b`, `0x00598e56`, and `0x00598e70` remain compiler-only Singleton-EH, adjustor, and deleting-wrapper artifacts.
- RTTI/vtables are source-declared/generated-binary; `TOTFRAME.EPD` remains a class-local source literal; shared `NPAL7.PAL` and render helpers remain dependencies.

## Historical Assumptions Superseded

- The former `class TotemFrame : public Pane` declaration is preserved as the earlier state but is incomplete. Live RTTI proves the additional direct `Singleton<TotemFrame>` base.
- Earlier prose modeled `g_pTotemFrame = this` and `g_pTotemFrame = 0` as handwritten constructor/destructor bodies. Direct-base RTTI, PMD, construction/EH order, and teardown order supersede that interpretation.
- Earlier storage documentation reported `0xffffffff` and reconstructable physical emission. Current PE/live evidence proves loader-zero backing and a false/non-emitting physical page.
- Existing method boundaries, vtable offsets, resources, status consumers, Pane inheritance, and source-file ownership remain valid.

## Cross-References

- [UID:0000OV][TotemFrame](by-file/TotemFrame.md)
- [UID:0001KC][0x00598cc0-0x00598ecf.TotemFrame](by-memory/0x00598cc0-0x00598ecf.TotemFrame.md)
- [UID:0000SK][g_pTotemFrame](by-global/g_pTotemFrame.md)
- [UID:0001RR][totem-frame-resources](by-resource/totem-frame-resources.md)
- [UID:0003E4][0x0062e460-0x0062e47c.TotemFrameResourceStringData](by-memory/0x0062e460-0x0062e47c.TotemFrameResourceStringData.md)
- [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md)
- [UID:0000RV][g_pOldUserStatusPane](by-global/g_pOldUserStatusPane.md)
- [UID:0000JL][FrameChrome](by-file/FrameChrome.md)
- [UID:0000MC][Pane](by-file/Pane.md)

## Changes

- 2026-07-24 B003 UID0002VR support implementation:
  - Raised `88/90` to `92/94`, kept owner/emitter UID0000OV, set position 20, added direct `Singleton<TotemFrame>` inheritance and the one global extern.
  - Incorporated the seven-entry RTTI hierarchy, PMD `+0xf8`, EBO/`0xf8` allocation proof, constructor/EH/destructor lifetime order, loader-zero storage route, and complete source/compiler boundary.
  - Replaced handwritten singleton assignments with direct-base source semantics while preserving them as explicitly superseded historical assumptions.
- 2026-07-20 B001 UID0001NM bounded support synchronization:
  - [UID:0003AB][0x005ba4a0-0x005baafe.UserStatusPaneApplyStatusPayload](by-memory/0x005ba4a0-0x005baafe.UserStatusPaneApplyStatusPayload.md) is a consumer, not an owner: in legacy mode it clamps the incoming spirit id to `[-1,3]`, invalidates status field 2, calls `g_pTotemFrame->InvalidateFrame()` when an instance exists, and otherwise constructs `new TotemFrame()`.
  - This relationship reinforces the existing constructor/lifecycle route but does not transfer TotemFrame ownership to UserStatusPane or alter this class's score, declaration, resources, ordinary destructor, or compiler-wrapper disposition.
- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000OV][TotemFrame](by-file/TotemFrame.md).
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the documented constructor, cleanup body, paint method, singleton clear helper, adjustor thunks, and scalar deleting destructor at `0x00598cc0`, `0x00598da0`, `0x00598dd0`, `0x00598e40`, `0x00598e4b`, `0x00598e56`, and `0x00598e70`; this page and parent [UID:0000OV][TotemFrame](by-file/TotemFrame.md) both meet the 80/80 parent gate. No C++ was emitted because the page is below the 95/95 reconstruction-code bar.
- 2026-05-28 boundary correction:
  - What existed before: class documentation pointed to `0x00598cc0-0x00598ece` and listed the scalar deleting destructor through `0x00598ece`.
  - Changed to: class documentation points to `0x00598cc0-0x00598ecf` and lists the destructor through `0x00598ecf`.
  - Summary/evidence: IDA MCP reports `sub_598E70` as `0x00598e70-0x00598ecf`; `0x00598ecf-0x00598ed0` is alignment before `TransferServerDialogPane`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:90`.
  - Summary/evidence: scored from the constructor/destructor/paint/thunk method map, singleton and resource references, status-pane source for frame selection, xrefs, and IDA-backed boundary correction.
- 2026-06-12 A003 Batch 295:
  - Score unchanged at `88/90`.
  - Added the exact [UID:0003E4][0x0062e460-0x0062e47c.TotemFrameResourceStringData](by-memory/0x0062e460-0x0062e47c.TotemFrameResourceStringData.md) source-literal child after live IDA MCP confirmed the sole `0x00598e05` xref from `TotemFrame::OnPaint`; this supports routing the child to this class while keeping final C++ blank below the 95/95 gate.
- 2026-06-19 B005 source-quality execution:
  - Score remains `88/90`.
  - Added declaration-level first-draft C++ for `TotemFrame`, updated method half-open ranges, and recorded the wrapper policy: constructor, ordinary destructor, and `OnPaint` are source-authored; constructor-unwind singleton clear, adjustor thunks, and scalar deleting destructor are compiler-generated.
  - Summary/evidence: B005 checked current docs, exported function data, cached vtable data, generated reports as leads, and local PE bytes. IDA MCP was unavailable during that pass, so current earlier IDA-backed docs remain the authoritative live-IDA evidence and B005's local audit supplies byte/range confirmation.
  - Historical correction: the declaration/method inventory and compiler-wrapper policy remain useful, but the Pane-only declaration and handwritten singleton-lifecycle source shape are superseded by B003's live RTTI/PMD/EH recheck.
