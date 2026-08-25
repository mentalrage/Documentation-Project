*** UID:00005P | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "SpecializedButtonPanes.h"

#include <cwchar>

#include "../../app/StartupWindow.h"
#include "../../render/EPFTileContext.h"
#include "../../render/ImageLib.h"
#include "../../render/Surface.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "ButtonControlPane.h"

class GenderButtonControlPane : public ButtonControlPane
{
public:
    GenderButtonControlPane(int genderIndex,
                            int stateFrameOffset,
                            bool selected,
                            const RectBounds &bounds)
        : ButtonControlPane(bounds),
          m_genderIndex(genderIndex),
          m_stateFrameOffset(stateFrameOffset),
          m_selected(selected)
    {
    }

    bool IsSelected() const
    {
        return m_selected;
    }

    void SetSelected(bool selected)
    {
        m_selected = selected;
        m_stateFrameOffset = selected ? 2 : 0;
        InvalidateRect(&m_visibleBounds);
    }

protected:
    virtual void OnPaint();
    virtual void SetVisualState(unsigned char visualState);

private:
    int m_genderIndex;
    int m_stateFrameOffset;
    bool m_selected;
};

[[CHILDREN]]
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# GenderButtonControlPane

## Status

- Confidence: very strong for the exact class role, single public `ButtonControlPane` base, inherited EventHandler/TimerHandler facets, `0x118` size, three subclass fields, five source methods, compiler-generated destructor machinery, owner-pollution exclusion, and [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) route. The constructor/getter/setter have no direct branch/pointer route because they are retained inline copies; exact live inlined consumers resolve their source liveness.
- Likely source file: [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md)
- Memory range: [UID:0001A4][0x00500640-0x00502755.SpecializedButtonPanes](by-memory/0x00500640-0x00502755.SpecializedButtonPanes.md), with exact method/destructor children [UID:00036V][0x00500640-0x005008c0.GenderDirectionButtonControlPaneMethods](by-memory/0x00500640-0x005008c0.GenderDirectionButtonControlPaneMethods.md) and [UID:00036X][0x00502700-0x00502755.GenderButtonControlPaneScalarDeletingDestructor](by-memory/0x00502700-0x00502755.GenderButtonControlPaneScalarDeletingDestructor.md)
- Current recovered file: `source-3/simroot_v2/class_GenderButtonControlPane.cpp`
- Type docs: [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md), [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md)

## Class Purpose

`GenderButtonControlPane` is a concrete gender-selection button derived only from `ButtonControlPane`. It stores a gender frame-group index, mutable state-frame offset, and mutable selection flag; its inline API constructs, reads, and changes selection, while its out-of-line virtuals handle state-transition framing and `GENDER.EPF` painting. EventHandler and TimerHandler views are inherited through Pane, not repeated as direct source bases. Its deleting destructor and receiver adjustors are compiler consequences of the inherited virtual destructor, not handwritten methods.

## Rebuild Handling

- Reconstructability: true for the complete human declaration and five source methods. The class has size `0x118`, a `ButtonControlPane` base at offset zero, inherited EventHandler and TimerHandler facets at complete-object offsets `+0xa0` and `+0xa4`, and fields at `+0x10c/+0x110/+0x114`.
- Parent handling: emit through [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) at position `20`. The shared source/header route is strongest from class adjacency and domain; a standalone historical file remains plausible but weaker and does not change current ownership.
- C++ handling: the formal H owns the one human class declaration plus inline constructor, `IsSelected`, and `SetSelected`. The formal CPP supplies includes and `[[CHILDREN]]`; exact children [UID:0004ZY][0x005006d0-0x005006ff.GenderButtonControlPaneSetVisualState](by-memory/0x005006d0-0x005006ff.GenderButtonControlPaneSetVisualState.md) and [UID:0004ZZ][0x00500700-0x00500797.GenderButtonControlPaneOnPaint](by-memory/0x00500700-0x00500797.GenderButtonControlPaneOnPaint.md) emit the two out-of-line virtual bodies. Constructor/accessor/setter children use covered-by H markers so no duplicate source is emitted.
- Destructor handling: do not write an explicit derived destructor body. The inherited virtual destructor produces the physical scalar-deleting wrapper and two receiver adjustors documented elsewhere.
- Ownership guard: keep `0x004fb630-0x004fbfcf` assigned to [UID:00009F][NewUserMiscDialogPane](by-class/NewUserMiscDialogPane.md), not this class. That range only explains inline child-control setup.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| generated owner-polluted row | `0x004fb630-0x004fbfcf` | Not a `GenderButtonControlPane` method; IDA confirms this as `NewUserMiscDialogPane::NewUserMiscDialogPane`, which allocates and initializes gender-button child controls. Raw pointer scan found no untyped pointers to this generated owner row. |
| `GenderButtonControlPane` | `0x00500640-0x00500690` | [UID:0004ZV][0x00500640-0x00500690.GenderButtonControlPaneConstructor](by-memory/0x00500640-0x00500690.GenderButtonControlPaneConstructor.md): exact retained inline constructor, four-argument `thiscall`, `ButtonControlPane` base call `0x00494eb0`, field stores to `+0x10c/+0x110/+0x114`, three vptr installs, and `ret 0x10`. Two live NewUser inlines duplicate the setup, resolving the former no-route ambiguity. |
| `IsSelected` | `0x00500690-0x00500697` | [UID:0004ZW][0x00500690-0x00500697.GenderButtonControlPaneIsSelected](by-memory/0x00500690-0x00500697.GenderButtonControlPaneIsSelected.md): exact seven-byte const accessor returning mutable `m_selected` at `+0x114`. |
| `SetSelected` | `0x005006a0-0x005006cc` | [UID:0004ZX][0x005006a0-0x005006cc.GenderButtonControlPaneSetSelected](by-memory/0x005006a0-0x005006cc.GenderButtonControlPaneSetSelected.md): writes `m_selected`, maps true/false to frame offsets `2/0`, and invalidates `m_visibleBounds`; command cases 3/4 inline the same operations. |
| `SetState` / `SetVisualState` | `0x005006d0`, size `0x2f` | Updates `m_stateFrameOffset` when incoming state byte is `0x0b` before delegating through base button/control handling; vtable data xref at `0x0061dbd8`. Avoid boolean-only `SetEnabled` wording. |
| `OnPaint` | `0x00500700`, size `0x97` | Paints gender-selection button sprite from UTF-16 resource `GENDER.EPF` at `0x0061e528`; vtable data xref at `0x0061dbd4`. Previous `GENDERBT.EPF` wording is stale for the checked binary. |
| Destructor/thunks | `0x005024a0`, `0x005024ab`, `0x00502700-0x00502755` | This-adjustor thunks plus exact scalar deleting destructor child [UID:00036X][0x00502700-0x00502755.GenderButtonControlPaneScalarDeletingDestructor](by-memory/0x00502700-0x00502755.GenderButtonControlPaneScalarDeletingDestructor.md); deleting-destructor data xref at `0x0061db90`. |

## Field Evidence

| Offset | Field hypothesis | Evidence |
| ---: | --- | --- |
| `0x10c` | `m_genderIndex` | `NewUserMiscDialogPane` inline setup writes one option as `0` and the other as `1`; raw constructor stores its first argument here. `OnPaint` uses this value as `3 * m_genderIndex` for the `GENDER.EPF` frame group. Prefer this name over generic `m_gender` because the value is a frame-group index. |
| `0x110` | `m_stateFrameOffset` / `m_visualStateFrameOffset` | Inline setup writes `2` for the first/default option and `0` for the second; raw constructor stores its second argument here. `SetState` writes `1` when incoming state/key `0x0b` arrives, and `OnPaint` adds it to `3 * m_genderIndex`. Prefer `m_stateFrameOffset`; keep `m_visualStateFrameOffset` as an acceptable prose alias. |
| `0x114` | `m_selected` | Constructor and two live inline consumers initialize it, `IsSelected` returns it, and `SetSelected` plus command cases 3/4 mutate it repeatedly. The former `m_defaultSelected`/`m_initiallySelected` interpretation described only initial constructor values and is superseded by the exact setter behavior. |

## Vtable Evidence

- [UID:0002OV][0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData](by-memory/0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData.md) records exact primary, secondary, and tertiary vtable data for this class.
- Primary vtable `0x0061db90` has store xrefs from inline setup at `0x004fb7e8` and `0x004fb869`, the raw constructor body at `0x0050066f`, and destructor reset at `0x00502706`.
- Secondary vtable `0x0061dbf8` has store xrefs at `0x004fb7ee`, `0x004fb86f`, `0x00500675`, and `0x0050270c`.
- Tertiary vtable `0x0061dc28` has store xrefs at `0x004fb7f8`, `0x004fb879`, `0x0050067f`, and `0x00502716`.
- Key slots tie `0x00500700` to paint at primary `+0x44`, `0x005006d0` to state/update at primary `+0x48`, and `0x00502700` to the scalar deleting destructor at primary `+0x00`.

## Evidence Notes

- Wave3 effective grade is 97.5.
- 2026-05-24 IDA MCP confirms `0x004fb630` is a `0x99f`-byte `NewUserMiscDialogPane` constructor called from `0x004fa74e`; remove it from `GenderButtonControlPane` ownership despite generated vtable-name pollution.
- 2026-05-24 IDA MCP reports no function, callers, or xrefs at `0x00500640`; the previous recognized function is `0x00500610-0x00500632`, and the next recognized function is `0x00500690-0x00500697`.
- 2026-05-24 IDA MCP recognizes `0x005006d0`, `0x00500700`, and `0x00502700`, all reached by vtable data rather than direct code callers.
- The `NewUserMiscDialogPane` constructor inlines gender-button child setup at `0x004fb7e3-0x004fb816` and `0x004fb864-0x004fb897`, which explains the child-control vtable writes without proving a standalone constructor body.
- 2026-05-26 IDA MCP confirmed primary vtable `0x0061db90`, secondary vtable `0x0061dbf8`, and tertiary vtable `0x0061dc28`. Inline setup allocates `0x118` bytes and writes subclass fields at `+0x10c`, `+0x110`, and `+0x114`.
- 2026-05-27 IDA MCP recheck still reports `0x00500640` as `NOFUNC` with no xrefs, and a raw dword scan across loaded segments found no pointers to `0x00500640`. The same scan found no raw pointer hits for `0x004fb630`; that range remains confirmed by its direct caller at `0x004fa74e`, not by gender-button ownership.
- 2026-06-01 aggregate and vtable-data pages add exact raw-constructor stores, vtable child boundaries, slot targets, owner-pollution boundaries, and field-layout evidence for `+0x10c`, `+0x110`, and `+0x114`.
- 2026-06-03 IDA MCP recheck again reports `0x00500640` as `NOFUNC` with no xrefs or raw pointer hits. It reconfirmed `0x005006d0`, `0x00500700`, and `0x00502700` as real functions, primary vtable slots `0x0061db90+0x44 -> 0x00500700`, `+0x48 -> 0x005006d0`, and `+0x00 -> 0x00502700`, plus constructor/inline/destructor vtable store refs at `0x004fb7e8`, `0x004fb869`, `0x0050066f`, and `0x00502706`. The polluted `0x004fb630` row still has a direct caller at `0x004fa74e` and remains `NewUserMiscDialogPane` ownership.
- 2026-06-06 live IDA MCP recheck reconfirmed the current class boundary: `0x00500640` is still not an IDA function and has no xrefs/callers, while `0x00500690`, `0x005006d0`, `0x00500700`, and `0x00502700` remain modeled functions. `xrefs_to` still ties state/paint/destruction through vtable data at `0x0061dbd8`, `0x0061dbd4`, and `0x0061db90`; primary-vtable store refs remain split between inline setup in `NewUserMiscDialogPane` at `0x004fb7e8`/`0x004fb869`, raw constructor-shaped bytes at `0x0050066f`, and destructor reset at `0x00502706`. `callees` confirms the state method delegates through `0x00494b80`, the paint method uses the resource/render helper family, and the scalar deleting destructor chains to pane cleanup plus operator delete.
- 2026-06-11 A007 Batch 161 live IDA MCP refresh reconfirmed `0x00500640` as a raw `NOFUNC` constructor-shaped start with no xrefs or raw pointer hits, and reconfirmed `0x00500690-0x00500697`, `0x005006d0-0x005006ff`, `0x00500700-0x00500797`, and `0x00502700-0x00502755` as exact modeled functions. The destructor body has thunk callers at `0x005024a6`/`0x005024b1`, primary vtable ref `0x0061db90`, vtable reset stores at `this+0x00/+0xa0/+0xa4`, base teardown through `0x00544580`, and guarded delete through `0x004f4ac0`. This also proves the executable aggregate's corrected half-open end at `0x00502755`.
- 2026-06-20 B002 local PE reanalysis used `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` (size `2679296`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`) because live MCP was unavailable. The image base is `0x00400000`; relevant sections are `.text 0x00401000-0x0060c4ac`, `.rdata 0x0060d000-0x0066c0be`, `.data 0x0066d000-0x0069ce24`, and `.rsrc 0x0069d000-0x006b2c38`.
- B002 pointer/branch scan facts: `0x00500640` and `0x00500690` have zero absolute-VA hits, zero RVA hits, and no direct `E8`/`E9` branches; `0x005006d0` has one meaningful absolute hit at vtable slot `0x0061dbd8`; `0x00500700` has one meaningful absolute hit at vtable slot `0x0061dbd4` plus two incidental RVA-pattern hits that are not caller proof; `0x00502700` has primary vtable hit `0x0061db90` plus adjustor-thunk jumps at `0x005024a6` and `0x005024b1`; `0x004fb630` has direct caller `0x004fa74e` and remains `NewUserMiscDialogPane`, not this class.
- B002 string/resource scan facts: no ASCII or UTF-16 `GENDERBT.EPF` string exists in the checked binary; UTF-16 `GENDER.EPF` exists at `0x0061e528`, with relevant pointer use at `0x00500742` inside `GenderButtonControlPane::OnPaint` and additional create-user related hits at `0x0052c612`, `0x0052c673`, `0x0052dfdf`, and `0x0052e03e`. `DIREC.EPD` at `0x0061e540` remains sibling Direction evidence only.
- B002 vtable-store scan facts: primary `0x0061db90`, secondary `0x0061dbf8`, and tertiary `0x0061dc28` each have four immediate-store sites: first inline `NewUserMiscDialogPane` setup, second inline setup, raw constructor, and destructor reset. These stores prove class layout and inline setup behavior but do not make `NewUserMiscDialogPane` the owner of `GenderButtonControlPane` methods.
- Inline setup value facts: the first gender button setup around `0x004fb7d0` writes `+0x10c = 0`, `+0x110 = 2`, `+0x114 = 1`; the second setup around `0x004fb850` writes `+0x10c = 1`, `+0x110 = 0`, `+0x114 = 0`. These are consumer setup values for the two new-user gender choices.
- 2026-08-01 B005 live read-only MCP and exact-byte reanalysis identified the previously omitted complete setter `[0x005006a0,0x005006cc)`. NewUser command cases 3/4 reproduce its selected-byte write, `2/0` frame mapping, and inherited invalidation, proving `+0x114` is mutable `m_selected` and resolving the constructor/accessor no-route result as retained-inline behavior.
- The RTTI hierarchy contains eight linear descriptors: GenderButtonControlPane, ButtonControlPane, ControlPane, Pane, GrafPort, LObject, EventHandler, and TimerHandler. PMDs place the Gender primary view at `0`, EventHandler at `+0xa0`, and TimerHandler at `+0xa4`; source inheritance remains only `public ButtonControlPane` because the latter facets are inherited through Pane.

## Reconstruction Notes

- Model this as a concrete `ButtonControlPane` subclass with `m_genderIndex`, `m_stateFrameOffset`, and mutable `m_selected` layered over the inherited layout.
- The gender index and visual-state offset select frames from `GENDER.EPF`; previous `GENDERBT.EPF` references are historical/stale for the checked client. The state handler updates the visual offset before delegating through the base button/control path.
- Treat `0x005024a0` and `0x005024ab` as compiler-generated adjustor thunks, not source methods.
- The former provisional constructor/default-selection interpretation is retained above as historical evidence but is resolved. Exact children are [UID:0004ZV][0x00500640-0x00500690.GenderButtonControlPaneConstructor](by-memory/0x00500640-0x00500690.GenderButtonControlPaneConstructor.md) constructor, [UID:0004ZW][0x00500690-0x00500697.GenderButtonControlPaneIsSelected](by-memory/0x00500690-0x00500697.GenderButtonControlPaneIsSelected.md) `IsSelected`, [UID:0004ZX][0x005006a0-0x005006cc.GenderButtonControlPaneSetSelected](by-memory/0x005006a0-0x005006cc.GenderButtonControlPaneSetSelected.md) `SetSelected`, [UID:0004ZY][0x005006d0-0x005006ff.GenderButtonControlPaneSetVisualState](by-memory/0x005006d0-0x005006ff.GenderButtonControlPaneSetVisualState.md) `SetVisualState`, and [UID:0004ZZ][0x00500700-0x00500797.GenderButtonControlPaneOnPaint](by-memory/0x00500700-0x00500797.GenderButtonControlPaneOnPaint.md) `OnPaint`; alignment remains non-emitting.
- Emit one declaration through this class H. Do not emit RTTI arrays, vtable dwords, adjustors, deleting flags, raw offsets, or duplicate inline method definitions.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 94 | Exact inheritance/facets, size, fields, five source methods, retained-inline liveness, vtable slots, compiler destructor cause, owner boundary, source route, exact child split, and formal CPP/H are documented. |
| Confidence | 95 | Bytes, RTTI PMDs, slots, stores, consumer inlines, and resource behavior strongly establish the source shape. Human lexical spellings and the shared historical filename remain evidence-ranked inferences. |
| Reconstructable | true | This is project-owned UI-control code with a valid owner/emitter route; blank formal C++ is a source-quality defer, not a non-reconstructable classification. |

## Cross-References

- [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md)
- [UID:0001A4][0x00500640-0x00502755.SpecializedButtonPanes](by-memory/0x00500640-0x00502755.SpecializedButtonPanes.md)
- [UID:00036V][0x00500640-0x005008c0.GenderDirectionButtonControlPaneMethods](by-memory/0x00500640-0x005008c0.GenderDirectionButtonControlPaneMethods.md)
- [UID:00036X][0x00502700-0x00502755.GenderButtonControlPaneScalarDeletingDestructor](by-memory/0x00502700-0x00502755.GenderButtonControlPaneScalarDeletingDestructor.md)
- [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md)
- [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md)
- [UID:0002OV][0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData](by-memory/0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData.md)
- [UID:00009F][NewUserMiscDialogPane](by-class/NewUserMiscDialogPane.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-08-17 B001 UID0002OX accepted support update: preserved every Gender declaration, inline method, child route, score, and evidence item; expanded only the shared `SpecializedButtonPanes.cpp` formal root to include `<cwchar>`, `StartupWindow.h`, `ImageLib.h`, and `Surface.h` alongside `EPFTileContext.h`. These dependencies close the later CheckBox constructor/paint children without moving ownership from their established pages.

- 2026-08-01 B005 UID0002OV accepted callback: raised to `94/95`, installed the exact source-facing class CPP/H at position `20`, corrected `m_defaultSelected` to mutable `m_selected`, added the omitted setter and all five allocated children, resolved retained-inline liveness and single-base inheritance, and kept deleting wrappers/vtables compiler-only while preserving prior no-route/default-name assumptions as superseded history.

- Completion/confidence score update: existed before as `0/0`; changed to `70/64`. Summary: role, vtable-backed state/paint/destructor methods, inline child setup evidence, and owner-pollution warnings are documented, but confidence remains limited because `0x00500640` is still a projected standalone constructor boundary with no xrefs. Evidence: `SpecializedButtonPanes` memory range, vtable refs at `0x0061db90`/`0x0061dbd4`/`0x0061dbd8`, `NewUserMiscDialogPane` caller evidence, and repeated IDA `NOFUNC`/no-pointer checks for `0x00500640`.
- 2026-06-02:
  - Before: the page stayed in the low-confidence queue even though adjacent IDA-backed aggregate, layout, vtable, and exact vtable-data pages had been raised.
  - After: raised to `74/82` and marked `RECONSTRUCTABLE:TRUE`; parent and C++ remain blank.
  - Summary/evidence: exact vtable child [UID:0002OV][0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData](by-memory/0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData.md), aggregate method map [UID:0001A4][0x00500640-0x00502755.SpecializedButtonPanes](by-memory/0x00500640-0x00502755.SpecializedButtonPanes.md), layout fields [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md), and `NewUserMiscDialogPane` owner-pollution evidence support the class role and rebuild shape while preserving the `0x00500640` raw-constructor caveat.
- 2026-06-03 parent attachment update:
  - Before: `AUTOGEN_PARENT_UID` was blank because the likely file parent was below the 80+ confidence threshold and had no projected path.
  - Changed to: `AUTOGEN_PARENT_UID:0000NY` and position `20`; reconstruction C++ remains blank.
  - Summary/evidence: [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) is now a `76/82` provisional `NexusTK/ui/controls/` parent after a fresh IDA MCP recheck reconfirmed gender-button vtable/function evidence and the `NewUserMiscDialogPane` ownership guard while preserving the raw constructor caveat.
- 2026-06-06 live IDA refresh:
  - Before: the class page had strong older evidence but had not recorded the current IDA state after several adjacent button/control updates.
  - Changed to: score `80/84`, retaining `RECONSTRUCTABLE:TRUE`, parent attachment, and blank final C++.
  - Summary/evidence: live IDA MCP reconfirmed `0x00500640` as `NOFUNC` with no entry xrefs/callers, confirmed the accessor/state/paint/destructor function objects and sizes, confirmed vtable data refs and inline setup stores, and confirmed the state/paint/destructor callee families. Confidence stays below high-final because the constructor remains raw/non-IDA-function and final inherited slot names are not source quality.
- 2026-06-11 A007 Batch 161:
  - Changed to: raised scores from `80/84` to `85/86`, retained parent [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) at position `20`, and linked exact method/destructor child pages.
  - Summary/evidence: live IDA MCP reconfirmed the raw constructor caveat, modeled accessor/state/paint/destructor extents, vtable refs, destructor thunk callers, corrected `0x00502755` endpoint, and delete-flag behavior. The class and file parent now satisfy the strict `85/85` gate.
- 2026-06-20 B002 Rule 26 incorporation:
  - Changed to: `COMPLETION:88`, `CONFIDENCE:89`.
  - Summary/evidence: incorporated B002's source-quality report, corrected `GENDERBT.EPF` to proven UTF-16 `GENDER.EPF`, upgraded fields to `m_genderIndex`, `m_stateFrameOffset`, and inferred `m_defaultSelected`, added local PE no-route evidence for `0x00500640` and `0x00500690`, recorded inline `NewUserMiscDialogPane` setup values, preserved owner/emitter [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md), rejected `0x004fb630` owner pollution, kept formal C++ blank with target-specific source-quality blockers, and recorded exact future split guidance for the mixed Gender/Direction method child.
