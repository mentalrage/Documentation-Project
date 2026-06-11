*** UID:00002J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanNameInputDialog

## Status

- Confidence: strong.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Core memory: [UID:00010J][0x00488b40-0x00488fa0.ClanNameInputDialogCore](by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md)
- Layout docs: [UID:0001TY][ClanInputDialogLayouts](by-type/by-struct/ClanInputDialogLayouts.md)
- Current recovered file: `source-3/simroot_v2/class_ClanNameInputDialog.cpp`
- Autogen status: attached to direct file parent [UID:0000I8][Clan](by-file/Clan.md), which is currently `90/85`; final C++ remains blank because field names, inherited subobject declaration, and derived submit hooks are not final-source quality.

## Class Purpose

`ClanNameInputDialog` is the shared `DLGCLAN1.EPF` modal dialog used by several clan name, money, and text-entry flows. It builds the background, OK/Cancel buttons, prompt text, and text edit control, then delegates final submission through a virtual submit hook.

The base dialog uses inherited control-host state at `+0x1fc`. Control id `1` is OK, `2` is Cancel, and `4` is the text edit field read on OK.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ClanNameInputDialog` | `0x00488b40-0x00488eab` | Builds the modal input dialog from packet-provided prompt text, installs the base dialog vtables, lays out `DLGCLAN1.EPF`, and creates the OK/Cancel/text controls. |
| `OnButtonClick` | `0x00488eb0-0x00488f24` | On OK, gets control id `4` text and calls the submit hook; OK and Cancel both close the dialog. |
| `UpdateOkButtonState` | `0x00488f30-0x00488f67` | Enables or disables OK depending on whether input text is empty. |
| `OnInputEvent` | `0x00488f70-0x00488fa0` | Forwards edit events, refreshes OK state, and notifies the clan status pane secondary view for event type `3`. |

## Ownership And Layout Evidence

| Evidence area | Source | Meaning |
| --- | --- | --- |
| source module | [UID:0000I8][Clan](by-file/Clan.md) | The direct parent file documents this dialog as part of the `social/Clan.cpp` status/dialog/packet core, and already clears the strict `85/85` gate. |
| exact executable range | [UID:00010J][0x00488b40-0x00488fa0.ClanNameInputDialogCore](by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md) | Confirms the four method ranges, padding gaps, control ids, packet prompt decode, submit hook, and input-event behavior. |
| vtable family | [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md) | Ties the base dialog shell to the derived clan money/name/text dialogs that override submit behavior. |
| layout/type support | [UID:0001TY][ClanInputDialogLayouts](by-type/by-struct/ClanInputDialogLayouts.md) | Documents the shared modal input layout used by `DLGCLAN1.EPF` and related clan input dialogs. |

## Behavioral Evidence

- The constructor stores the primary, secondary, and tertiary base-dialog vtable views at `+0`, `+0xa0`, and `+0xa4`, then derived dialogs overwrite the relevant views for their own submit behavior.
- The packet prompt is read from `packet + 3` length and `packet + 4` bytes, converted through `MultiByteToWideChar`, and displayed in the modal body.
- The inherited control host at `+0x1fc` owns OK id `1`, Cancel id `2`, and text-edit id `4`; the OK handler reads id `4` text before dispatching the virtual submit hook at primary vtable slot `+0x5c`.
- `UpdateOkButtonState` uses the text edit contents to enable or disable OK, while `OnInputEvent` calls the refresh helper and forwards event type `3` through `g_pClanStatusPane`'s secondary view.
- The function group is bounded by padding gaps `0x00488eab-0x00488eb0`, `0x00488f24-0x00488f30`, and `0x00488f67-0x00488f70`; the next raw derived constructor starts at `0x00488fa0`.

## Evidence Notes

- IDA confirms all four function starts and sizes.
- Derived dialogs install new primary/secondary vtables on top of this base shell, but many of their constructor starts are projected non-IDA records.
- 2026-05-26 IDA decompilation confirms `OnButtonClick` fetches control id `4` through the inherited control host at `this + 0x1fc`, then dispatches the submitted text through the primary vtable submit hook at slot `+0x5c`.
- 2026-06-07 A001 Batch081 live IDA recheck reconfirmed function sizes `0x36b`, `0x74`, `0x37`, and `0x30` for the constructor, button handler, OK-state refresh, and input event handler.
- 2026-06-07 `xrefs_to 0x00488b40` reports six packet-dispatcher construction sites at `0x0048511b`, `0x004851c6`, `0x00485227`, `0x0048527f`, `0x00485332`, and `0x00485393`; six modeled derived constructor callers at `0x00487ddf`, `0x004881df`, `0x0048828f`, `0x00488337`, `0x00488429`, and `0x004884cf`; and six raw no-function derived-constructor xrefs at `0x00488fad`, `0x0048907d`, `0x0048914d`, `0x0048927d`, `0x004893ad`, and `0x004894dd`.
- 2026-06-07 vtable xrefs show the three virtual methods are shared across seven clan dialog vtable rows: `OnButtonClick` data refs at `0x00615940`, `0x006159e0`, `0x00615a80`, `0x00615b20`, `0x00615bc0`, `0x00615c60`, and `0x00615d00`; `UpdateOkButtonState` at the matching `+4` slots; and `OnInputEvent` at the matching input-event slots.
- 2026-06-07 parent-gate check: [UID:0000I8][Clan](by-file/Clan.md) is `90/85` and directly lists `ClanNameInputDialog` in the social clan core, so this class now clears the corrected child-and-parent `85/85` assignment gate.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:0001TY][ClanInputDialogLayouts](by-type/by-struct/ClanInputDialogLayouts.md)
- [UID:00010J][0x00488b40-0x00488fa0.ClanNameInputDialogCore](by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md)
- [UID:00002A][ClanDepMoneyInputDialog](by-class/ClanDepMoneyInputDialog.md)
- [UID:00002O][ClanWidMoneyInputDialog](by-class/ClanWidMoneyInputDialog.md)
- [UID:00002D][ClanExpelNameInputDialog](by-class/ClanExpelNameInputDialog.md)
- [UID:00002M][ClanSummonNameInputDialog](by-class/ClanSummonNameInputDialog.md)
- [UID:000023][ClanAppearNameInputDialog](by-class/ClanAppearNameInputDialog.md)
- [UID:000028][ClanChangeNameInputDialog](by-class/ClanChangeNameInputDialog.md)

## Changes

- What existed before: the page documented the shared clan input dialog shell, control ids, base storage, methods, derived classes, and layout references, but metadata was still `0/0`.
- What it was changed to: scores were set to `78/86`.
- Summary and evidence: constructor, button action, OK-state refresh, input refresh, derived submit hook, and layout docs are covered; exact member names and final header/source split remain below exhaustive.
- 2026-06-05: Marked reconstructable, but left `AUTOGEN_PARENT_UID` blank because the class is `78/86`, below the 80/80 parent-attachment gate, even though [UID:0000I8][Clan](by-file/Clan.md) remains the likely owner. Live IDA MCP `lookup_funcs` confirms exact starts at `0x00488b40`, `0x00488eb0`, `0x00488f30`, and `0x00488f70`; current `callers` confirms constructor references from clan packet/dialog handlers.
- 2026-06-07 A001 Batch081 strict parent-gate update:
  - What existed before: `78/86`, reconstructable, but unassigned with compact evidence on the class page.
  - Changed to: `85/88` and `AUTOGEN_PARENT_UID:0000I8`.
  - Summary/evidence: expanded the class-level method ranges to exact half-open bounds, added control-host/control-id behavior, packet prompt conversion, submit-hook, input-event forwarding, vtable fan-out, constructor caller/xref sets, and the direct parent gate. Final C++ remains blank until inherited fields and derived submit hooks are source-quality.
