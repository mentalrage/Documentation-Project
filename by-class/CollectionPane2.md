*** UID:00002Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../core/PanelPane.h"

class Event;

class CollectionPane2 : public PanelPane
{
public:
    CollectionPane2();
    virtual ~CollectionPane2();

    virtual void OnActivate(const unsigned char *packetData);
    virtual void OnPaint();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);
};

typedef char CollectionPane2SizeMustBe0xF8[
    sizeof(CollectionPane2) == 0xF8 ? 1 : -1];
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CollectionPane2

## Status

- Likely source file: [UID:0000IC][CollectionPane](by-file/CollectionPane.md)
- Address range: [UID:0001HD][0x0056e940-0x0056fe75.CollectionPane](by-memory/0x0056e940-0x0056fe75.CollectionPane.md), vtable data [UID:00038V][0x00624668-0x006246f4.CollectionPane2VtableData](by-memory/0x00624668-0x006246f4.CollectionPane2VtableData.md), raw constructor [UID:0001HG][0x0056fd70-0x0056fda0.CollectionPane2RawConstructor](by-memory/0x0056fd70-0x0056fda0.CollectionPane2RawConstructor.md), plus destructor [UID:00038Y][0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor](by-memory/0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor.md)
- Confidence: very strong for the complete virtual contract, no-new-fields `0xF8` layout, three vtable facets, constructor/destructor source cause, render resources, EventHandler stubs, and compiler-artifact child dispositions. The raw constructor's missing IDA function object remains documented evidence but no longer blocks the class declaration.
- Evidence basis: prior dated MCP passes plus B003 live read-only session `0ca5b429-c8c4-442c-b509-192c5807abf5` / IDB session `5a570ede`, which rechecked exact class methods, vtable/COL cells, adjustors, destructor chains, object size, comments/types, and neighboring-family cleanup.

## Class Purpose

`CollectionPane2` is a small alternate collection inventory frame pane. It initializes a `PanelPane` base, installs three vtable views, renders the `CLTINV.EPF` frame with the shared `ITEMINV.PAL` palette, and exposes mostly false/stub query virtuals.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `CollectionPane2::CollectionPane2()` | `0x0056fd70-0x0056fda0` | [UID:0001HG][0x0056fd70-0x0056fda0.CollectionPane2RawConstructor](by-memory/0x0056fd70-0x0056fda0.CollectionPane2RawConstructor.md) raw constructor bytes; now emits first-draft `CollectionPane2::CollectionPane2() : PanelPane() {}` through the exact child, while raw no-function/no-route evidence remains a confidence cap. |
| `~CollectionPane2` body | `0x0056fda0-0x0056fdbf` | [UID:0001HH][0x0056fda0-0x0056fdbf.CollectionPane2Destructor](by-memory/0x0056fda0-0x0056fdbf.CollectionPane2Destructor.md); now emits first-draft empty `CollectionPane2::~CollectionPane2()` source. MCP session `b001_000241_20260627` confirms the binary body is only compiler-generated `CollectionPane2` vptr restores at `+0`, `+0xa0`, and `+0xa4`, followed by implicit `PanelPane::~PanelPane()` base teardown. |
| `OnActivate(const unsigned char *packetData)` | `0x0056fdc0-0x0056fdcc` | [UID:0001HI][0x0056fdc0-0x0056fdcc.CollectionPane2ForwardingThunk](by-memory/0x0056fdc0-0x0056fdcc.CollectionPane2ForwardingThunk.md); primary vtable slot `0x006246b4` / `+0x48` is the `PanelPane::OnActivate` contract. The body intentionally ignores packet data and passes `this+0x44` / `m_bounds` to inherited primary slot `+0x20` `Pane::InvalidateRect`. |
| `OnPaint` / `DrawCollectionInventoryFrame` | [UID:0003YG][0x0056fdd0-0x0056fe41.CollectionPane2OnPaint](by-memory/0x0056fdd0-0x0056fe41.CollectionPane2OnPaint.md) | Vtable slot `0x006246b0`; loads `ITEMINV.PAL` from `0x0061c964`, uses pooled UID0003F1 `CLTINV.EPF` at `0x0056fe0d`, draws frame zero, then blits through `dword_69B3E8`. |
| `HandleKeyOrTextEvent(Event *event)` | [UID:0003YH][0x0056fe50-0x0056fe55.CollectionPane2FalseStubC4](by-memory/0x0056fe50-0x0056fe55.CollectionPane2FalseStubC4.md) | Exact false-return secondary `EventHandler` vtable slot `0x006246c4` / offset `+0x08`; ignores the event and returns false. |
| `HandlePointerOrMouseEvent(Event *event)` | [UID:0003YI][0x0056fe60-0x0056fe65.CollectionPane2FalseStubC0](by-memory/0x0056fe60-0x0056fe65.CollectionPane2FalseStubC0.md) | Exact false-return secondary `EventHandler` vtable slot `0x006246c0` / offset `+0x04`; ignores the event and returns false. |
| `HandlePacketEvent` | `0x0056fe70-0x0056fe75` | [UID:0001HJ][0x0056fe70-0x0056fe75.CollectionPane2FalseStub](by-memory/0x0056fe70-0x0056fe75.CollectionPane2FalseStub.md), secondary `EventHandler` packet-event false-return override at vtable slot `0x006246cc` / offset `+0x10`; returns false, ignores `Event *`, and now owns first-draft source in the exact child. |
| compiler scalar-deleting destructor | [UID:00038Y][0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor](by-memory/0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor.md) | Primary vtable slot `0x0062466c`; non-reconstructable/non-emitting ABI artifact generated from the explicit virtual destructor declaration and ordinary destructor definition. Secondary/tertiary adjustors are likewise compiler artifacts in [UID:00023Y][0x00573247-0x00573273.CollectionPaneAdjustorThunks](by-memory/0x00573247-0x00573273.CollectionPaneAdjustorThunks.md). |

## Class-Owned Read-Only Data

| Range | Role | Evidence |
| --- | --- | --- |
| [UID:00038V][0x00624668-0x006246f4.CollectionPane2VtableData](by-memory/0x00624668-0x006246f4.CollectionPane2VtableData.md) | Complete-object-locator and three-view vtable group for this class. | Live IDA sees primary, secondary, and tertiary table bases at `0x0062466c`, `0x006246bc`, and `0x006246ec`; raw constructor stores occur at `0x0056fd7f`, `0x0056fd87`, and `0x0056fd91`, with matching destructor-body stores at `0x0056fda0`, `0x0056fda6`, and `0x0056fdb0` and scalar deleting destructor stores at `0x00573316`, `0x0057331c`, and `0x00573326`. |

## Live IDA Evidence

- 2026-06-04 IDA confirms modeled functions at `0x0056fda0-0x0056fdbf`, `0x0056fdc0-0x0056fdcc`, `0x0056fdd0-0x0056fe41`, `0x0056fe50-0x0056fe55`, `0x0056fe60-0x0056fe65`, `0x0056fe70-0x0056fe75`, and `0x00573310-0x00573365`; the next modeled class body starts at `0x0056fe80`.
- Raw disassembly at `0x0056fd70-0x0056fda0` shows a complete constructor shape: base constructor call `0x00545090`, three `CollectionPane2` vtable stores, `eax=this`, and `retn`; there are still no xrefs to the raw start.
- The `CollectionPane2` vtable island `0x00624668-0x006246f4` contains RTTI plus primary/secondary/tertiary tables. Slots `0x006246b0`, `0x006246b4`, `0x006246c0`, `0x006246c4`, and `0x006246cc` target the render, forwarding thunk, and three false-return helpers.
- The destructor path is tied by data xrefs from primary/secondary/tertiary vtable slots to `0x00573310`, `0x00573247`, and `0x00573252`; the adjustor thunks jump into `0x00573310`.
- Render resource xrefs show `0x0056fdf9` pushing `ITEMINV.PAL` at `0x0061c964` and `0x0056fe0d` pushing `CLTINV.EPF` at `0x00624ac8`.
- 2026-06-11 live IDA MCP reconfirmed `0x0056fd70` is still raw no-function constructor bytes, modeled destructor/render/stub bodies remain stable, and scalar deleting destructor [UID:00038Y][0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor](by-memory/0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor.md) has thunk refs at `0x0057324d`/`0x00573258` plus vtable data ref `0x0062466c`.
- 2026-06-12 Agent-A004 live IDA MCP reconfirmed [UID:00038V][0x00624668-0x006246f4.CollectionPane2VtableData](by-memory/0x00624668-0x006246f4.CollectionPane2VtableData.md): `0x00624668 -> ??_R4CollectionPane2@@6B@`, `0x0062466c -> 0x00573310`, `0x006246bc -> 0x00573247`, `0x006246ec -> 0x00573252`, render/forwarding/false-return slots at `0x006246b0`, `0x006246b4`, `0x006246c0`, `0x006246c4`, and `0x006246cc`, and the `SelfLookPane2` successor boundary at `0x006246f4`.
- 2026-06-26 Agent-B002 MCP session `80de0a67` decoded the `CollectionPane2 +0xa0` secondary `EventHandler` table: `0x006246c0 -> 0x0056fe60` at offset `+0x04`, `0x006246c4 -> 0x0056fe50` at `+0x08`, inherited `0x006246c8 -> 0x00544dd0` at `+0x0c`, target [UID:0001HJ][0x0056fe70-0x0056fe75.CollectionPane2FalseStub](by-memory/0x0056fe70-0x0056fe75.CollectionPane2FalseStub.md) at `0x006246cc` / `+0x10`, and inherited/default slots through `+0x28`.
- The same B002 pass compared this table to `EventDispatcher::CallHandler`: packet events, exact type `0x12` / 18 decimal (Verified with `tools/int_convert.py`), dispatch to handler offset `+0x10`. [UID:0001HJ][0x0056fe70-0x0056fe75.CollectionPane2FalseStub](by-memory/0x0056fe70-0x0056fe75.CollectionPane2FalseStub.md) is therefore `CollectionPane2::HandlePacketEvent(Event *event)`, the packet-event false-return override.
- `tools/int_convert.py` verified the vtable span and offset values used by the Batch 266 route: `0x8c` / 140 decimal, `0x50` / 80 decimal, `0x30` / 48 decimal, `0x0c` / 12 decimal, `0xa0` / 160 decimal, `0xa4` / 164 decimal, and destructor size `0x55` / 85 decimal.
- Historical 2026-06-26 interpretation: Agent-B010 named primary `+0x48` `InvalidateOwnBounds(int flags)` from behavior alone. B003's 2026-07-29 contract recheck supersedes that source name: current `PanelPane` primary-vtable documentation identifies `+0x48` as `OnActivate(const unsigned char *packetData)`. The same bytes still prove `InvalidateRect(&m_bounds)` behavior, but the stack argument is ignored packet data and the source return type is `void`.
- 2026-06-26 Agent-B010 MCP session `80de0a67` resolved [UID:0001HG][0x0056fd70-0x0056fda0.CollectionPane2RawConstructor](by-memory/0x0056fd70-0x0056fda0.CollectionPane2RawConstructor.md) as first-draft `CollectionPane2::CollectionPane2()`: the exact 48-byte raw body calls `PanelPane::PanelPane()` at `0x0056fd7a`, writes the three `CollectionPane2` vtable views at `0x0056fd7f`, `0x0056fd87`, and `0x0056fd91`, returns `this`, and has no IDA function object, no direct raw-start xrefs, no pointer-route hits, and no direct rel32 call/jump route.

### 2026-07-29 Supervisor Gate 2B Analysis Poststate

Supervisor catalog entry `0349` applied and read back the complete source-quality analysis layer without changing function boundaries, bytes, xrefs, padding, or compiler-decorated vtable/data identities. The saved IDB is SHA256 `B46BEB1B347B569129E0B9F9BB53C51E4560EF6249081256D31EAC53A95F1A41`, size `143190134` bytes, last write `2026-07-29T02:03:25.4572488-04:00`; the prestate backup is `NexusTK.exe.i64.bak-UID00038Y-prestate-20260729-015926`.

| Address | Applied analysis identity and declaration | Applied function-regular comment / channel disposition |
| --- | --- | --- |
| `0x00573310` | `CollectionPane2__ScalarDeletingDestructor`; `CollectionPane2 *__thiscall CollectionPane2__ScalarDeletingDestructor(CollectionPane2 *this, unsigned int deletingFlags)` | Compiler-generated scalar deleting destructor; restores all three class vptrs, runs `PanelPane` teardown, applies deleting-flags bits `1`/`4`, uses size `0xF8`, and identifies `CollectionPane2::~CollectionPane2()` as the human source. FP/ER/EP remain blank; internal comments at `0x00573313` and `0x00573340` remain preserved. |
| `0x00573247` | `CollectionPane2__ScalarDeletingDestructorAdjustorA0`; `CollectionPane2 *__thiscall CollectionPane2__ScalarDeletingDestructorAdjustorA0(EventHandler *this, unsigned int deletingFlags)` | EventHandler-facet adjustor subtracting `0xA0` and tail-jumping to the scalar wrapper. FP/ER/EP are blank; stale entry comment `Block` was removed. |
| `0x00573252` | `CollectionPane2__ScalarDeletingDestructorAdjustorA4`; `CollectionPane2 *__thiscall CollectionPane2__ScalarDeletingDestructorAdjustorA4(TimerHandler *this, unsigned int deletingFlags)` | TimerHandler-facet adjustor subtracting `0xA4` and tail-jumping to the scalar wrapper. FP/ER/EP are blank; stale entry comment `Block` was removed. |
| `0x0056FDA0` | `CollectionPane2__Destructor`; `void __thiscall CollectionPane2__Destructor(CollectionPane2 *this)` | Out-of-line destructor body whose compiler vptr restoration precedes implicit `PanelPane` teardown; the human source body is empty. FP/ER/EP remain blank. |
| `0x0056FDC0` | `CollectionPane2__OnActivate`; `void __thiscall CollectionPane2__OnActivate(CollectionPane2 *this, const unsigned __int8 *packetData)` | `OnActivate` override with intentionally unused packet data; invalidates inherited bounds through `Pane::InvalidateRect`. FP/ER/EP remain blank. IDA normalized source-equivalent `unsigned char` to `unsigned __int8`. |
| `0x0056FDD0` | `CollectionPane2__OnPaint`; `void __thiscall CollectionPane2__OnPaint(CollectionPane2 *this)` | Paints with `ITEMINV.PAL` and `CLTINV.EPF` frame `0` through the EPF tile/blit path and visible bounds. FP/ER/EP remain blank. |
| `0x0056FE60` | `CollectionPane2__HandlePointerOrMouseEvent`; `bool __thiscall CollectionPane2__HandlePointerOrMouseEvent(EventHandler *this, void *event)` | Pointer/mouse callback returning false without consuming the event. FP/ER/EP remain blank. |
| `0x0056FE50` | `CollectionPane2__HandleKeyOrTextEvent`; `bool __thiscall CollectionPane2__HandleKeyOrTextEvent(EventHandler *this, void *event)` | Key/text callback returning false without consuming the event. FP/ER/EP remain blank. |
| `0x0056FE70` | `CollectionPane2__HandlePacketEvent`; `bool __thiscall CollectionPane2__HandlePacketEvent(EventHandler *this, void *event)` | Packet callback returning false without consuming the event. FP/ER/EP remain blank. |
| `0x005450D0` | `PanelPane__Destructor`; `void __thiscall PanelPane__Destructor(PanelPane *this)` | Ordinary `PanelPane` destructor restoring its three vptr views and tail-jumping to `Pane` teardown. FP/ER/EP remain blank. |

The applied analysis UDT is exactly `CollectionPane2`, size `0xF8`, with one member `_base` of type `PanelPane` at offset `0` and no additional members. Existing `PanelPane`, `EventHandler`, and `TimerHandler` dependency types were preserved. These names/types/comments are IDA analysis state; they do not change the human-source ownership, formal CPP/H split, or compiler-artifact non-emission decisions below.

## Source-Quality Findings

- [UID:0001HG][0x0056fd70-0x0056fda0.CollectionPane2RawConstructor](by-memory/0x0056fd70-0x0056fda0.CollectionPane2RawConstructor.md) now emits first-draft `CollectionPane2::CollectionPane2()` source in the exact child. `0x0056fd70` remains raw/no-function and no-direct-xref, but that is now a confidence cap rather than a constructor C++ blocker: the bytes call `PanelPane::PanelPane()`, install the three `CollectionPane2` vtable views, return `this`, and match the destructor/scalar-destructor vtable lifecycle.
- [UID:0001HH][0x0056fda0-0x0056fdbf.CollectionPane2Destructor](by-memory/0x0056fda0-0x0056fdbf.CollectionPane2Destructor.md) now emits first-draft empty `CollectionPane2::~CollectionPane2()` source in the exact child. The `0x0056fda0-0x0056fdbf` body has no explicit member cleanup or source statements; MCP session `b001_000241_20260627` proves only compiler-generated vptr restores, a tail jump to `PanelPane::~PanelPane()`, zero ordinary-entry xrefs, and matching vtable lifecycle refs with the constructor and scalar deleting wrapper. The scalar/delete flag wrapper remains [UID:00038Y][0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor](by-memory/0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor.md) and stays no-code.
- The false-return slots at `0x006246c0`, `0x006246c4`, and `0x006246cc` are exact `CollectionPane2` `EventHandler` targets. Current slot contracts resolve them as pointer/mouse `+0x04`, key/text `+0x08`, and packet `+0x10`; all three source methods ignore `Event *` and return false.
- [UID:0001HI][0x0056fdc0-0x0056fdcc.CollectionPane2ForwardingThunk](by-memory/0x0056fdc0-0x0056fdcc.CollectionPane2ForwardingThunk.md) emits `void CollectionPane2::OnActivate(const unsigned char *packetData)`. The argument is intentionally unused, and the body invalidates inherited bounds. The former `InvalidateOwnBounds(int flags)` interpretation is retained only as dated history.
- Class CPP now contains `[[CHILDREN]]` and H contains the complete declaration. Exact children own method bodies; compiler wrapper [UID:00038Y][0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor](by-memory/0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor.md), adjustors, and vtable data remain non-emitting artifacts generated from this class shape.

## Layout And Source Representation

- `CollectionPane2` derives from `PanelPane` and introduces no observed data members. The scalar wrapper's exact delete size is `0xF8`, equal to the documented `PanelPane` size.
- Primary, `EventHandler`, and `TimerHandler` facets begin at `+0`, `+0xA0`, and `+0xA4`. These offsets explain the three vtable stores and two deleting-destructor adjustors without requiring handwritten layout glue.
- The explicit `virtual ~CollectionPane2();` declaration and out-of-line empty definition in [UID:0001HH][0x0056fda0-0x0056fdbf.CollectionPane2Destructor](by-memory/0x0056fda0-0x0056fdbf.CollectionPane2Destructor.md) are the human source cause of scalar wrapper [UID:00038Y][0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor](by-memory/0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor.md).
- The size typedef in the formal H block is a reconstruction invariant, not a field declaration. It guards the exact no-new-fields layout while keeping final code human-authored rather than decompiler-shaped.
- Vtable/COL symbols in [UID:00038V][0x00624668-0x006246f4.CollectionPane2VtableData](by-memory/0x00624668-0x006246f4.CollectionPane2VtableData.md) are compiler output and do not belong in the formal class declaration.

## UID0003F1 Shared Literal

- `CollectionPane2::OnPaint` has exactly one operand into [UID:0003F1][0x00624a98-0x00624b30.CollectionPanePanelResourceStrings](by-memory/0x00624a98-0x00624b30.CollectionPanePanelResourceStrings.md): `L"CLTINV.EPF"` at `0x0056fe0d`. It is used with `ITEMINV.PAL` and frame zero in exact body `[0x0056fdd0,0x0056fe41)`, SHA256 `C2703E85D0B14BF8A62E25E5FB93C553D04B292E77CA5C5C19B2E5C114C6105A`.
- The same physical literal has main-class paint use `0x0056ee4c`. This cross-class pooling keeps UID0003F1 owned/emitted by file UID0000IC. It does not create a `CollectionPane2` member, static object, duplicate literal object, or H declaration; the existing complete class declaration and `[[CHILDREN]]` topology remain unchanged.

## Score Rationale

- Completion `92`: complete class declaration, child insertion route, virtual inventory, no-new-fields layout, source/header ownership, ordinary-destructor source cause, and compiler-artifact dispositions are documented.
- Confidence `94`: exact vtable slots, class size, method bodies, resource refs, constructor/destructor stores, and adjustors agree. Original private symbol spelling is inferred through stable interface contracts rather than PDB proof.

## Cross-References

- [UID:0000IC][CollectionPane](by-file/CollectionPane.md)
- [UID:00002X][CollectionPane](by-class/CollectionPane.md)
- [UID:0001HD][0x0056e940-0x0056fe75.CollectionPane](by-memory/0x0056e940-0x0056fe75.CollectionPane.md)
- [UID:0001HG][0x0056fd70-0x0056fda0.CollectionPane2RawConstructor](by-memory/0x0056fd70-0x0056fda0.CollectionPane2RawConstructor.md)
- [UID:0003YG][0x0056fdd0-0x0056fe41.CollectionPane2OnPaint](by-memory/0x0056fdd0-0x0056fe41.CollectionPane2OnPaint.md)
- [UID:0003YH][0x0056fe50-0x0056fe55.CollectionPane2FalseStubC4](by-memory/0x0056fe50-0x0056fe55.CollectionPane2FalseStubC4.md)
- [UID:0003YI][0x0056fe60-0x0056fe65.CollectionPane2FalseStubC0](by-memory/0x0056fe60-0x0056fe65.CollectionPane2FalseStubC0.md)
- [UID:00023Y][0x00573247-0x00573273.CollectionPaneAdjustorThunks](by-memory/0x00573247-0x00573273.CollectionPaneAdjustorThunks.md)
- [UID:00023Z][0x00573310-0x0057353d.CollectionAndGroupPaneDestructors](by-memory/0x00573310-0x0057353d.CollectionAndGroupPaneDestructors.md)
- [UID:00038V][0x00624668-0x006246f4.CollectionPane2VtableData](by-memory/0x00624668-0x006246f4.CollectionPane2VtableData.md)
- [UID:00038Y][0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor](by-memory/0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor.md)
- [UID:0003F1][0x00624a98-0x00624b30.CollectionPanePanelResourceStrings](by-memory/0x00624a98-0x00624b30.CollectionPanePanelResourceStrings.md)

## Changes

- 2026-08-16 Agent-B008 UID0003FA coordinated accepted callback: raised `92/94 -> 94/95`, preserved the children-only CPP and complete no-new-fields `0xF8` declaration, and added the exact `../core/PanelPane.h` base preamble. All lifecycle/paint/activation/EventHandler contracts remain source-visible while vtables, adjustors, and scalar wrappers remain compiler-only.
- 2026-08-15 Agent-B002 UID0003F1 accepted callback: linked the exact pooled `CLTINV.EPF` operand and file-owned no-object route while preserving the complete formal declaration, child insertion topology, and `92/94` score.
- 2026-07-29 B003 UID00038Y implementation callback:
  - Raised from `88/91` to `92/94`; added formal CPP child insertion and the complete `CollectionPane2 : public PanelPane` H declaration with `0xF8` size invariant.
  - Corrected primary slot `+0x48` from historical behavior-name `InvalidateOwnBounds(int flags)` to the inherited contract `OnActivate(const unsigned char *packetData)`, and resolved secondary slots `+0x04`/`+0x08` as pointer/mouse and key/text false-return overrides.
  - Reclassified scalar destructor, adjustors, and vtable storage as compiler artifacts whose human source cause is this class declaration plus ordinary destructor. Older interpretations below remain historical evidence only.

- 2026-06-12 Agent-A004 Batch 266: Raised from `85/88` to `87/90`.
  - Before: the class cleared the strict gate through destructor/raw-constructor evidence but did not explicitly own the exact `CollectionPane2` vtable child, and the raw constructor child still routed directly to the file parent.
  - After: added class-owned read-only data for [UID:00038V][0x00624668-0x006246f4.CollectionPane2VtableData](by-memory/0x00624668-0x006246f4.CollectionPane2VtableData.md), refreshed raw-constructor/destructor/vtable-slot evidence, and kept direct file parent [UID:0000IC][CollectionPane](by-file/CollectionPane.md).
  - Evidence: live IDA MCP `py_eval` against NexusTK.exe md5 `4247e04e20b65d6414c7238aa8ff5515`; `tools/int_convert.py` verified cited vtable sizes, destructor size, and thunk offsets.
- 2026-06-17 B001 report execution:
  - Added exact `CollectionPane2` render and false-stub children [UID:0003YG][0x0056fdd0-0x0056fe41.CollectionPane2OnPaint](by-memory/0x0056fdd0-0x0056fe41.CollectionPane2OnPaint.md), [UID:0003YH][0x0056fe50-0x0056fe55.CollectionPane2FalseStubC4](by-memory/0x0056fe50-0x0056fe55.CollectionPane2FalseStubC4.md), and [UID:0003YI][0x0056fe60-0x0056fe65.CollectionPane2FalseStubC0](by-memory/0x0056fe60-0x0056fe65.CollectionPane2FalseStubC0.md).
  - Replaced open-question wording with the current high-probability raw-constructor and slot-based virtual-name findings; the remaining uncertainty now affects final C++ naming, not ownership or split routing.
- 2026-06-11 Agent-A001 Batch 186 continuation: Raised from `82/88` to `85/89`.
  - What changed: linked exact child [UID:00038Y][0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor](by-memory/0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor.md), recorded the fresh raw-constructor/destructor evidence, and kept direct file parent [UID:0000IC][CollectionPane](by-file/CollectionPane.md), now `87/86`.
  - Reason for score increase: the class now has exact constructor/body/destructor coverage strong enough to clear the strict child-parent gate, while the raw no-function constructor keeps final C++ below threshold.
- Before: the scalar deleting destructor was listed as `0x00573310-0x00573364`, and the adjustor thunks were not covered by class references.
- Changed to: the destructor endpoint is corrected to `0x00573365`, with the adjacent adjustor thunks and destructor island linked.
- Evidence: 2026-05-28 IDA MCP reports `sub_573310` as `0x00573310-0x00573365`, with `0x00573247` and `0x00573252` as `-0xa0`/`-0xa4` adjustor thunks into it.
- What existed before: the page documented the alternate collection inventory frame pane and raw constructor/destructor boundaries, but metadata was still `0/0`.
- What it was changed to: scores were set to `72/78`.
- Summary and evidence: raw constructor, destructor body, forwarding thunk, render method, false stubs, and scalar destructor are covered; IDA lacks a function object for the constructor.
- 2026-06-04: Raised from `72/78` to `82/88`.
  - What existed before: the page had the broad method list but still relied on stale external caveats, had non-exclusive endpoints for two false-return helpers, and did not tie the class methods to the live `CollectionPane2` vtable island or render resource xrefs.
  - Changed to: documented the current IDA binary identity, raw constructor disassembly facts, exact modeled function ranges, vtable slots, destructor/adjustor linkage, and `ITEMINV.PAL`/`CLTINV.EPF` resource xrefs; removed stale external-output reliance.
  - Reason for score increase: live IDA evidence now proves the alternate pane's class shape, destructor paths, render helper, and vtable ownership strongly enough for an `82/88` class page, while the raw constructor's lack of an IDA function object and direct caller keeps C++ reconstruction below the final bar.
- 2026-06-05: Marked reconstructable and attached to [UID:0000IC][CollectionPane](by-file/CollectionPane.md).
  - Before: `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` were blank, leaving the class coverage row unclassified.
  - After: `RECONSTRUCTABLE:TRUE` and `AUTOGEN_PARENT_UID:0000IC`.
  - Evidence: live IDA MCP reconfirms `0x0056fd70` is not modeled as a function but confirms modeled class methods/destructor at `0x0056fda0`, `0x0056fdd0`, `0x0056fe50`, and `0x00573310`; this class and the parent file both meet the 80% completion/confidence attachment gate, while final C++ remains gated by the raw constructor caveat.
- 2026-06-26 Agent-B002 implementation callback: Raised from `87/90` to `88/91`.
  - Updated [UID:0001HJ][0x0056fe70-0x0056fe75.CollectionPane2FalseStub](by-memory/0x0056fe70-0x0056fe75.CollectionPane2FalseStub.md) from an address-only false-return row to `HandlePacketEvent`, the secondary `EventHandler` packet-event false-return override at `0x006246cc` / offset `+0x10`.
  - Evidence: current MCP session `80de0a67` decoded the `CollectionPane2 +0xa0` slot map and proved `EventDispatcher::CallHandler` routes packet events, exact type `18`, to offset `+0x10`. The exact child now emits first-draft `CollectionPane2::HandlePacketEvent(Event *event)` while this class page remains a declaration/overview route.
- 2026-06-26 Agent-B010 implementation callback:
  - Score unchanged at `88/91`.
  - Updated [UID:0001HI][0x0056fdc0-0x0056fdcc.CollectionPane2ForwardingThunk](by-memory/0x0056fdc0-0x0056fdcc.CollectionPane2ForwardingThunk.md) from `adjustor/dispatcher` wording to `InvalidateOwnBounds(int flags)`, the primary `+0x48` bounds-invalidation method.
  - Evidence: MCP session `80de0a67` reconfirmed `0x006246b4 -> 0x0056fdc0`, inherited `Pane::InvalidateRect` at `0x0062468c` / primary `+0x20`, `this+0x44` as `m_bounds`, and the exact sibling pattern at `0x004ea280` and `0x004ee6d0`. The exact child now emits first-draft `int CollectionPane2::InvalidateOwnBounds(int flags)` while this class page remains the class-level overview route.
- 2026-06-26 Agent-B010 implementation callback for [UID:0001HG][0x0056fd70-0x0056fda0.CollectionPane2RawConstructor](by-memory/0x0056fd70-0x0056fda0.CollectionPane2RawConstructor.md):
  - Score unchanged at `88/91`.
  - Updated the constructor row/source-quality note to state that the exact child now emits first-draft `CollectionPane2::CollectionPane2() : PanelPane() {}` while this class page keeps formal C++ blank.
  - Evidence: MCP session `80de0a67` proved the exact raw bytes, `PanelPane::PanelPane()` call, three `CollectionPane2` vptr stores, destructor/scalar-destructor lifecycle, and route-negative confidence cap.
- 2026-06-27 B003 implementation callback for [UID:0001HH][0x0056fda0-0x0056fdbf.CollectionPane2Destructor](by-memory/0x0056fda0-0x0056fdbf.CollectionPane2Destructor.md):
  - Score unchanged at `88/91`.
  - Updated the destructor row/source-quality note to state that the exact child now emits first-draft empty `CollectionPane2::~CollectionPane2()` source while this class page keeps formal C++ blank.
  - Evidence: MCP session `b001_000241_20260627` confirmed the exact `0x1f` / 31-byte ordinary destructor body, unique bytes, zero direct xrefs, three compiler-generated `CollectionPane2` vptr restores, implicit `PanelPane::~PanelPane()` base teardown, and scalar/delete flag glue isolated in [UID:00038Y][0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor](by-memory/0x00573310-0x00573365.CollectionPane2ScalarDeletingDestructor.md).
