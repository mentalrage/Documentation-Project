*** UID:0000M1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# NumberInputDialog

## Status

- Confidence: strong for class boundary and behavior, medium for exact original filename.
- Proposed module: `ui/dialogs/NumberInputDialog.cpp`
- Proposed header: `ui/dialogs/NumberInputDialog.h`
- Current recovered source: `source-3/simroot_v2/class_NumberInputDialog.cpp`
- Main memory range: [UID:0001CW][0x00530640-0x00530cf7.NumberInputDialog](by-memory/0x00530640-0x00530cf7.NumberInputDialog.md)
- Related support docs: [UID:0001CV][0x00530640-0x00530b00.NumberInputDialogConstructor](by-memory/0x00530640-0x00530b00.NumberInputDialogConstructor.md), [UID:0001CY][0x00530b40-0x00530c78.NumberInputDialogActionHandler](by-memory/0x00530b40-0x00530c78.NumberInputDialogActionHandler.md), [UID:0001CX][0x00530b00-0x00530b35.NumberInputDialogRawDestructor](by-memory/0x00530b00-0x00530b35.NumberInputDialogRawDestructor.md), [UID:0001CZ][0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks](by-memory/0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks.md), [UID:0001D0][0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor](by-memory/0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor.md), [UID:0001RJ][number-input-dialog-resources](by-resource/number-input-dialog-resources.md)
- Evidence basis: generated source as a lead plus read-only IDA MCP checks through 2026-06-01. `wave3.py` was not executed for this pass.

## File Role

`NumberInputDialog` is a reusable modal numeric input dialog. It displays a prompt, OK/cancel buttons, a single text edit field, a configurable min/max range, and callback objects for confirmed and cancelled input.

Keep it as a generic `ui/dialogs/` source rather than attaching it to item/mix dialogs. Current direct constructor callers are item-mixing quantity paths, but the class itself is a standalone prompt that validates arbitrary integer input and reports through callback interfaces.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:00009K][NumberInputDialog](by-class/NumberInputDialog.md) | `0x00530640-0x00530cf7` | Modal numeric prompt with dual EPF/EPD layouts, min/max validation, callback dispatch, and destructor thunks. |
| `g_alertPaneButtonLayout` | generated global-data reference | Button layout passed to the out-of-range [UID:00000B][AlertPane](by-class/AlertPane.md). |
| `g_pGrafPort` | generated global-data reference | Dialog bounds/context setup. |
| `g_pLanguageMan` | generated global-data reference | Localized prompt/error string lookups. |
| `g_useEpfAssets` | generated global-data reference | Chooses the high-resolution EPF layout versus older EPD layout. |

## Function Map

| Range | Function | Notes |
| --- | --- | --- |
| [UID:0001CV][0x00530640-0x00530b00.NumberInputDialogConstructor](by-memory/0x00530640-0x00530b00.NumberInputDialogConstructor.md) | constructor | Builds the dialog controls, stores callbacks/min/max, sets focus/default/cancel controls, positions the dialog, and opens it. |
| [UID:0001CX][0x00530b00-0x00530b35.NumberInputDialogRawDestructor](by-memory/0x00530b00-0x00530b35.NumberInputDialogRawDestructor.md) | raw destructor body | IDA does not currently define this as a function, but disassembly confirms destructor code that resets vtables, destroys the callback target, and jumps to base cleanup. |
| [UID:0001CY][0x00530b40-0x00530c78.NumberInputDialogActionHandler](by-memory/0x00530b40-0x00530c78.NumberInputDialogActionHandler.md) | `OnConfirm` / action handler | Button `1` parses and validates edit text; button `2` cancels. |
| [UID:0001CZ][0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks](by-memory/0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks.md) | adjustor thunk | Real 0xb thunk forwarding to `0x00530c90` with `this - 160`; excluded through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| [UID:0001CZ][0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks](by-memory/0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks.md) | adjustor thunk | Real 0xb thunk forwarding to `0x00530c90` with `this - 164`; excluded through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| [UID:0001D0][0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor](by-memory/0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor.md) | scalar deleting destructor | Resets vtables, destroys the callback target, calls base cleanup, and optionally frees `this`. |

## Layout And Resource Notes

- EPF layout uses `DLGEXC3.EPF`, palette `PAL01.PAL`, outer rect `239x283`, OK button image `14`, cancel image `22`, label control `3`, and edit control `4`.
- EPD layout uses `DLGEXC3.EPD`, palette `NPAL8.PAL`, outer rect `287x277`, OK button image `14`, cancel image `22`, label control `3`, and edit control `4`; see [UID:0001RJ][number-input-dialog-resources](by-resource/number-input-dialog-resources.md).
- The active generated source currently prints the EPD palette as `L"NP"`; IDA string bytes at symbol `aNp` decode to `NPAL8.PAL`.
- The out-of-range path creates an [UID:00000B][AlertPane](by-class/AlertPane.md) using localized string id `217`.
- The item quantity prompt callers use localized string id `218` and min/max `1..itemInfo->m_maxStack`.

## Caller Evidence

- `xrefs_to 0x00530640` reports direct constructor calls from `0x004afdce` inside the mix/item add helper at `0x004afcc0` and from `0x004b03d6` inside `AddMixingItemDialog::OnConfirm`.
- Both callers allocate 636 bytes and pass callback objects that call `MixItemDialog` quantity-add logic after the user chooses a number. IDA MCP decompilation on 2026-05-25 shows the callback objects being constructed at `0x004afd62` and `0x004b0370`; the generated wrapper is documented as [UID:000041][DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d](by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md).
- Vtable data refs confirm `OnConfirm` at `0x62021c`, adjustor thunk `0x00530c78` at `0x620234`, adjustor thunk `0x00530c83` at `0x620264`, and scalar deleting destructor `0x00530c90` at `0x6201d4`.

## Ownership Notes

- This range starts immediately after [UID:0000M0][NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md), but it is not part of account registration. Treat `0x00530640` as the start of this separate dialog class.
- `ItemDialogs.cpp` and `MixItemDialog.cpp` should call this class for stack quantities; they should not own the implementation.
- IDA does not define the ordinary destructor at `0x00530b00`, but the raw bytes are documented at [UID:0001CX][0x00530b00-0x00530b35.NumberInputDialogRawDestructor](by-memory/0x00530b00-0x00530b35.NumberInputDialogRawDestructor.md).
- The generated disabled file decodes `0x00530c78` with the wrong this-adjustment and omits `0x00530c83`. Use [UID:0001CZ][0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks](by-memory/0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks.md) until generated data is fixed; the adjustor wrappers are excluded through [UID:0000VN][-ignored](by-memory/-ignored.md), while the raw destructor and scalar deleting destructor remain reconstructable.
- 2026-05-26 IDA MCP recheck confirms `0x00530b00` is still absent from the function table, the adjustor thunks forward after `this - 0xa0` / `this - 0xa4`, and the EPD branch resource should remain `NPAL8.PAL`.
- 2026-06-01 IDA MCP recheck confirms the same boundaries and ownership: `lookup_funcs` reports `0x00530640` size `0x4c0`, `0x00530b00` as `Not a function`, `0x00530b40` size `0x138`, `0x00530c78` and `0x00530c83` as 0xb thunks, and `0x00530c90` size `0x67`; raw bytes at `0x00530636-0x00530640` and `0x00530cf7-0x00530d00` are `0xcc` padding.
- 2026-06-01 IDA MCP decompilation records constructor fields at `+0x26c/+0x270/+0x274/+0x278`, vtable stores through `0x006201d4/0x00620234/0x00620264`, action-handler use of edit control `4`, localized error string `217`, confirm/cancel callback dispatch, and scalar-deleting destructor callback cleanup.

## Cross-References

- [UID:00009K][NumberInputDialog](by-class/NumberInputDialog.md)
- [UID:0001CW][0x00530640-0x00530cf7.NumberInputDialog](by-memory/0x00530640-0x00530cf7.NumberInputDialog.md)
- [UID:0001CX][0x00530b00-0x00530b35.NumberInputDialogRawDestructor](by-memory/0x00530b00-0x00530b35.NumberInputDialogRawDestructor.md)
- [UID:0001CZ][0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks](by-memory/0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks.md)
- [UID:0001D0][0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor](by-memory/0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor.md)
- [UID:0001RJ][number-input-dialog-resources](by-resource/number-input-dialog-resources.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:000009][AddMixingItemDialog](by-class/AddMixingItemDialog.md)
- [UID:00008J][MixItemDialog](by-class/MixItemDialog.md)
- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md)
- [UID:0000IT][DialogPane](by-file/DialogPane.md)
- [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md)
- [UID:0000E3][StaticTextControlPane](by-class/StaticTextControlPane.md)
- [UID:00006D][ImageButtonControlPane](by-class/ImageButtonControlPane.md)
- [UID:00004G][EPFImageControlPane](by-class/EPFImageControlPane.md)
- [UID:0000KK][LanguageMan](by-file/LanguageMan.md)
- [UID:0000HE][AlertPanes](by-file/AlertPanes.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `88`, confidence `82`.
- Summary/evidence: the page documents role, constructor/action/destructor function map, resources, callers, vtable refs, ownership notes, generated-data defects, and cross-references; confidence remains capped by exact original filename and raw destructor treatment.
- 2026-06-01 path and evidence refresh:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the page was scored `88/82`.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`, `COMPLETION:89`, and `CONFIDENCE:84`.
  - Summary/evidence: refreshed IDA MCP lookup/caller/xref/decompile/raw-byte checks confirm the range boundaries, raw destructor gap, vtable refs, callback fields, action flow, and padding; original filename remains a source-layout hypothesis rather than final proof.
