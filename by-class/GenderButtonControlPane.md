*** UID:00005P | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# GenderButtonControlPane

## Status

- Confidence: strong for class role, vtable identity, layout fields, owner-pollution exclusion, and virtual methods; medium-high for the raw constructor start because IDA still does not model `0x00500640` as a function object.
- Likely source file: [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md)
- Memory range: [UID:0001A4][0x00500640-0x00502754.SpecializedButtonPanes](by-memory/0x00500640-0x00502754.SpecializedButtonPanes.md)
- Current recovered file: `source-3/simroot_v2/class_GenderButtonControlPane.cpp`
- Type docs: [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md), [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md)

## Class Purpose

`GenderButtonControlPane` is a gender-selection button control. It has constructor-shaped setup, state override behavior for disabled/pressed states, sprite painting based on gender, and scalar deleting destruction.

## Rebuild Handling

- Reconstructability: true for the class declaration, gender/visual-state/default fields, recognized virtual methods, and destructor behavior.
- Parent handling: attach to [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) at autogen position `20`. The file page is now a `76/82` provisional `NexusTK/ui/controls/` source root, so the child and parent meet the 80+ confidence attachment rule. This is class-level attachment only; method C++ remains blank.
- C++ handling: leave final C++ blank. The class shape is well supported, but the constructor start at `0x00500640` remains raw/non-IDA-function and the final source split for the account-creation control family is not settled.
- Ownership guard: keep `0x004fb630-0x004fbfcf` assigned to [UID:00009F][NewUserMiscDialogPane](by-class/NewUserMiscDialogPane.md), not this class. That range only explains inline child-control setup.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| generated owner-polluted row | `0x004fb630-0x004fbfcf` | Not a `GenderButtonControlPane` method; IDA confirms this as `NewUserMiscDialogPane::NewUserMiscDialogPane`, which allocates and initializes gender-button child controls. Raw pointer scan found no untyped pointers to this generated owner row. |
| `GenderButtonControlPane` | `0x00500640-0x0050068f` | Wave3 constructor range; not an IDA-recognized function start, with no direct callers/xrefs or raw pointer hits observed. |
| `SetState` | `0x005006d0`, size `0x2f` | Updates button state and gender override; vtable data xref at `0x0061dbd8`. |
| `OnPaint` | `0x00500700`, size `0x97` | Paints gender selection button sprite; vtable data xref at `0x0061dbd4`. |
| Destructor/thunks | `0x005024a0`, `0x005024ab`, `0x00502700` size `0x55` | This-adjustors and scalar deleting destructor; deleting-destructor data xref at `0x0061db90`. |

## Field Evidence

| Offset | Field hypothesis | Evidence |
| ---: | --- | --- |
| `0x10c` | gender index | `NewUserMiscDialogPane` inline setup writes one option as `0` and the other as `1`. [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md) records `OnPaint` using this value as `3 * genderIndex` for the `GENDERBT.EPF` frame index. |
| `0x110` | visual-state frame offset | Inline setup initializes this differently per option. `SetState` writes this field when incoming state/key `0x0b` arrives, and `OnPaint` adds it to the gender sprite frame index. |
| `0x114` | selected/default flag | Inline setup writes the initial selected/default byte. The small accessor at `0x00500690` returns this byte, while the current state/paint methods do not consume it directly. |

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

## Reconstruction Notes

- Model this as a concrete button-control subclass with gender-index, visual-state, and selected/default fields layered over the inherited button/control layout.
- The gender index and visual-state offset should select frames from `GENDERBT.EPF`; the state handler updates the visual offset before delegating through the base button/control path.
- Treat `0x005024a0` and `0x005024ab` as compiler-generated adjustor thunks, not source methods.
- Keep the constructor source provisional until the raw start/no-xref issue is resolved or accepted as an inlined/unreferenced constructor artifact.

## Cross-References

- [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md)
- [UID:0001A4][0x00500640-0x00502754.SpecializedButtonPanes](by-memory/0x00500640-0x00502754.SpecializedButtonPanes.md)
- [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md)
- [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md)
- [UID:0002OV][0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData](by-memory/0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData.md)
- [UID:00009F][NewUserMiscDialogPane](by-class/NewUserMiscDialogPane.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `70/64`. Summary: role, vtable-backed state/paint/destructor methods, inline child setup evidence, and owner-pollution warnings are documented, but confidence remains limited because `0x00500640` is still a projected standalone constructor boundary with no xrefs. Evidence: `SpecializedButtonPanes` memory range, vtable refs at `0x0061db90`/`0x0061dbd4`/`0x0061dbd8`, `NewUserMiscDialogPane` caller evidence, and repeated IDA `NOFUNC`/no-pointer checks for `0x00500640`.
- 2026-06-02:
  - Before: the page stayed in the low-confidence queue even though adjacent IDA-backed aggregate, layout, vtable, and exact vtable-data pages had been raised.
  - After: raised to `74/82` and marked `RECONSTRUCTABLE:TRUE`; parent and C++ remain blank.
  - Summary/evidence: exact vtable child [UID:0002OV][0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData](by-memory/0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData.md), aggregate method map [UID:0001A4][0x00500640-0x00502754.SpecializedButtonPanes](by-memory/0x00500640-0x00502754.SpecializedButtonPanes.md), layout fields [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md), and `NewUserMiscDialogPane` owner-pollution evidence support the class role and rebuild shape while preserving the `0x00500640` raw-constructor caveat.
- 2026-06-03 parent attachment update:
  - Before: `AUTOGEN_PARENT_UID` was blank because the likely file parent was below the 80+ confidence threshold and had no projected path.
  - Changed to: `AUTOGEN_PARENT_UID:0000NY` and position `20`; reconstruction C++ remains blank.
  - Summary/evidence: [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) is now a `76/82` provisional `NexusTK/ui/controls/` parent after a fresh IDA MCP recheck reconfirmed gender-button vtable/function evidence and the `NewUserMiscDialogPane` ownership guard while preserving the raw constructor caveat.
- 2026-06-06 live IDA refresh:
  - Before: the class page had strong older evidence but had not recorded the current IDA state after several adjacent button/control updates.
  - Changed to: score `80/84`, retaining `RECONSTRUCTABLE:TRUE`, parent attachment, and blank final C++.
  - Summary/evidence: live IDA MCP reconfirmed `0x00500640` as `NOFUNC` with no entry xrefs/callers, confirmed the accessor/state/paint/destructor function objects and sizes, confirmed vtable data refs and inline setup stores, and confirmed the state/paint/destructor callee families. Confidence stays below high-final because the constructor remains raw/non-IDA-function and final inherited slot names are not source quality.
