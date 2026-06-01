*** UID:0001TY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Clan Input Dialog Layouts

## Status

- Confidence: strong for the documented offsets, medium for final source-level field names.
- Current entity kind: recovered layout notes for [UID:00002J][ClanNameInputDialog](by-class/ClanNameInputDialog.md), [UID:000024][ClanAttrInputDialog](by-class/ClanAttrInputDialog.md), and derived clan modal dialogs.
- Likely owner source: [UID:0000I8][Clan](by-file/Clan.md), with [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md) as a possible split.
- Evidence basis: IDA MCP lookup/decompile/caller checks on 2026-05-31, [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md), and generated `simroot_v2` source only as a search/context lead. `wave3.py` was not executed for this pass.

## Shared Dialog Shape

The clan input dialogs follow the common `DialogPane` inheritance shape used by other modal panes:

| Offset | Meaning | Evidence |
| --- | --- | --- |
| `+0x00` | primary vtable pointer | Constructors write class primary vtable bases here. |
| `+0xa0` | secondary vtable/subobject view | Constructors write the secondary vtable base at `this + 0xa0`. |
| `+0xa4` | tertiary vtable/subobject view | Constructors write the tertiary vtable base at `this + 0xa4`. |
| `+0x1fc` | inherited control-host/control-list pointer | `ClanNameInputDialog::OnButtonClick` and `UpdateOkButtonState` use `this[127]` to fetch controls by id. |

Use the vtable-family page as the durable source for exact vtable addresses. The projected derived constructor starts in current generated output are not reliable function-boundary anchors.

## IDA Evidence

IDA MCP `lookup_funcs` confirms `ClanNameInputDialog` functions at `0x00488b40`, `0x00488eb0`, `0x00488f30`, and `0x00488f70`. The constructor decompilation writes the primary vtable at `+0x000` and the secondary/tertiary vtable views at `+0x0a0/+0x0a4`, then builds the `DLGCLAN1.EPF` dialog. `OnButtonClick` uses the inherited control host pointer at `this[127]` (`+0x1fc`) to fetch text control id `4`, reads up to 255 wide characters, dispatches through primary vtable slot `+0x5c`, then closes for OK id `1` or cancel id `2`. `UpdateOkButtonState` fetches ids `1` and `4` through the same control host and enables/disables the OK button based on whether the input is empty.

IDA MCP `lookup_funcs` confirms `ClanAttrInputDialog` functions at `0x00489600`, `0x00489df0`, `0x00489ec0`, and `0x00489f50`. The constructor stores vtables at `+0x000/+0x0a0/+0x0a4`, converts the first packet string directly into `this+0x26c`, and populates stack buffers for the prompt/default text used to create the visible controls. `OnDialogAction` fetches controls `8`, `9`, and `10` from the inherited control host, copies ids `8` and `9` into `this+0x46c` and `this+0x66c`, parses id `10` into the 16-bit field at `this+0x86c`, then dispatches the confirmation hook before closing. `ValidateInputFields` checks controls `8`, `9`, and `10` and toggles control id `1`.

IDA decompilation of `0x0048a030` confirms the derived clan-change submit method calls helper `0x00486330` with `this+0x26c`, `this+0x46c`, `this+0x66c`, and `*(uint16_t *)(this+0x86c)`, validating the persistent field meanings across construction, dialog action, and packet submission.

## ClanNameInputDialog

No class-specific persistent storage is confirmed beyond the inherited `DialogPane` state. The constructor decodes packet prompt text into stack buffers, builds `DLGCLAN1.EPF`, then creates controls:

| Control id | Role | Evidence |
| --- | --- | --- |
| `1` | OK/action image button | `UpdateOkButtonState` enables or disables this control based on input text. |
| `2` | Cancel image button | `OnButtonClick` closes the dialog without submit on id `2`. |
| `4` | text edit input field | `OnButtonClick` reads this control's text and dispatches through the submit virtual at primary vtable slot `+0x5c`. |

## ClanAttrInputDialog

`ClanAttrInputDialog` adds persistent submitted-field storage after the inherited dialog state:

| Offset | Size | Meaning | Evidence |
| --- | --- | --- | --- |
| `+0x26c` | `0x200` | first submitted wide string / initial clan name field | Constructor stores the first packet string here; `ClanChangeInputDialog::SubmitClanChange` passes `this + 0x26c` as the first string. |
| `+0x46c` | `0x200` | second submitted wide string | `OnDialogAction` copies edit control id `8` into this field; `SubmitClanChange` passes it as the second string. |
| `+0x66c` | `0x200` | third submitted wide string | `OnDialogAction` copies edit control id `9` into this field; `SubmitClanChange` passes it as the third string. |
| `+0x86c` | `2` | submitted numeric/type value | `OnDialogAction` parses edit control id `10` into this field; `SubmitClanChange` passes the 16-bit value to helper `0x00486330`. |

Control ids used by the base attribute dialog:

| Control id | Role | Evidence |
| --- | --- | --- |
| `1` | OK/action image button | `ValidateInputFields` toggles this button. |
| `2` | Cancel image button | `OnDialogAction` closes the dialog without submit on id `2`. |
| `8` | first editable submitted text | Read into `+0x46c` on OK. |
| `9` | second editable submitted text | Read into `+0x66c` on OK. |
| `10` | numeric/type text field | Parsed into `+0x86c` on OK. |

## Source-Layout Impact

These layouts support keeping the clan modal input classes with the Clan feature source. `ClanNameInputDialog` is a reusable shell for one-field clan actions; `ClanAttrInputDialog` is the reusable shell for multi-field attribute updates. Derived classes should override submit/confirm behavior but should not duplicate the base layout in separate one-class source files.

## Cross-References

- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md)
- [UID:00010J][0x00488b40-0x00488fa0.ClanNameInputDialogCore](by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md)
- [UID:00010L][0x00489600-0x00489f80.ClanAttrInputDialogCore](by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md)
- [UID:000027][ClanChangeInputDialog](by-class/ClanChangeInputDialog.md)
- [UID:00010F][0x00486330-0x0048652d.SubmitClanChangeHelper](by-memory/0x00486330-0x0048652d.SubmitClanChangeHelper.md)

## Open Questions

- Confirm the final original source-file split between the general Clan module and a possible `ClanDialogs` module.
- Audit the derived clan dialog family so each derived submit/confirm override is mapped to this shared base layout without duplicating fields.

## Changes

- Reclassified the page from unevaluated to reconstructable layout documentation with conservative scores. Evidence: IDA MCP lookup/decompile/caller checks on 2026-05-31 verify the shared dialog vtable/control-host layout and the `ClanAttrInputDialog` persistent fields across constructor, OK handling, validation, and `0x0048a030` clan-change submission; source-file split and full derived-class inventory remain below near-final confidence.
