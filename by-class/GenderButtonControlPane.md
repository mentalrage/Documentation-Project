*** UID:00005P | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:64 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# GenderButtonControlPane

## Status

- Confidence: medium overall; standalone constructor boundary remains projected and unproven.
- Likely source file: [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md)
- Memory range: [UID:0001A4][0x00500640-0x00502754.SpecializedButtonPanes](by-memory/0x00500640-0x00502754.SpecializedButtonPanes.md)
- Current recovered file: `source-3/simroot_v2/class_GenderButtonControlPane.cpp`
- Type docs: [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md), [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md)

## Class Purpose

`GenderButtonControlPane` is a gender-selection button control. It has constructor-shaped setup, state override behavior for disabled/pressed states, sprite painting based on gender, and scalar deleting destruction.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| generated owner-polluted row | `0x004fb630-0x004fbfcf` | Not a `GenderButtonControlPane` method; IDA confirms this as `NewUserMiscDialogPane::NewUserMiscDialogPane`, which allocates and initializes gender-button child controls. Raw pointer scan found no untyped pointers to this generated owner row. |
| `GenderButtonControlPane` | `0x00500640-0x0050068f` | Wave3 constructor range; not an IDA-recognized function start, with no direct callers/xrefs or raw pointer hits observed. |
| `SetState` | `0x005006d0`, size `0x2f` | Updates button state and gender override; vtable data xref at `0x0061dbd8`. |
| `OnPaint` | `0x00500700`, size `0x97` | Paints gender selection button sprite; vtable data xref at `0x0061dbd4`. |
| Destructor/thunks | `0x005024a0`, `0x005024ab`, `0x00502700` size `0x55` | This-adjustors and scalar deleting destructor; deleting-destructor data xref at `0x0061db90`. |

## Evidence Notes

- Wave3 effective grade is 97.5.
- 2026-05-24 IDA MCP confirms `0x004fb630` is a `0x99f`-byte `NewUserMiscDialogPane` constructor called from `0x004fa74e`; remove it from `GenderButtonControlPane` ownership despite generated vtable-name pollution.
- 2026-05-24 IDA MCP reports no function, callers, or xrefs at `0x00500640`; the previous recognized function is `0x00500610-0x00500632`, and the next recognized function is `0x00500690-0x00500697`.
- 2026-05-24 IDA MCP recognizes `0x005006d0`, `0x00500700`, and `0x00502700`, all reached by vtable data rather than direct code callers.
- The `NewUserMiscDialogPane` constructor inlines gender-button child setup at `0x004fb7e3-0x004fb816` and `0x004fb864-0x004fb897`, which explains the child-control vtable writes without proving a standalone constructor body.
- 2026-05-26 IDA MCP confirmed primary vtable `0x0061db90`, secondary vtable `0x0061dbf8`, and tertiary vtable `0x0061dc28`. Inline setup allocates `0x118` bytes and writes subclass fields at `+0x10c`, `+0x110`, and `+0x114`.
- 2026-05-27 IDA MCP recheck still reports `0x00500640` as `NOFUNC` with no xrefs, and a raw dword scan across loaded segments found no pointers to `0x00500640`. The same scan found no raw pointer hits for `0x004fb630`; that range remains confirmed by its direct caller at `0x004fa74e`, not by gender-button ownership.

## Cross-References

- [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md)
- [UID:0001A4][0x00500640-0x00502754.SpecializedButtonPanes](by-memory/0x00500640-0x00502754.SpecializedButtonPanes.md)
- [UID:0001W7][SpecializedButtonPaneLayouts](by-type/by-struct/SpecializedButtonPaneLayouts.md)
- [UID:0001YW][SpecializedButtonPaneVtables](by-type/by-vtable/SpecializedButtonPaneVtables.md)
- [UID:00009F][NewUserMiscDialogPane](by-class/NewUserMiscDialogPane.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `70/64`. Summary: role, vtable-backed state/paint/destructor methods, inline child setup evidence, and owner-pollution warnings are documented, but confidence remains limited because `0x00500640` is still a projected standalone constructor boundary with no xrefs. Evidence: `SpecializedButtonPanes` memory range, vtable refs at `0x0061db90`/`0x0061dbd4`/`0x0061dbd8`, `NewUserMiscDialogPane` caller evidence, and repeated IDA `NOFUNC`/no-pointer checks for `0x00500640`.
