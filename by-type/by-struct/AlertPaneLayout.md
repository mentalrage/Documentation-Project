*** UID:0001TO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AlertPane Layout

## Status

- Entity kind: class layout / derived-layout notes.
- Covered classes: [UID:00000B][AlertPane](by-class/AlertPane.md), [UID:0000FU][VersatileAlertPane](by-class/VersatileAlertPane.md), [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md), and [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md).
- Likely owner header/source: [UID:0000HE][AlertPanes](by-file/AlertPanes.md).
- Confidence: strong for listed offsets; medium for final source-facing field names and total object sizes.
- Reconstructable: yes, as source-level class layout information. Do not emit C++ from this type page until final alert class declarations and original field names are proven.

## Observed Layout

`AlertPane` is a `DialogPane`-derived object with three vtable views. Inherited state should be read through [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md); the alert-family offsets below are directly observed in IDA disassembly.

| Offset | Field hypothesis | Applies to | Evidence |
| --- | --- | --- | --- |
| `+0x00` | primary vptr | all alert-family classes | Constructors store the class primary vtable here; primary slots include alert dismissal/callback virtuals. |
| `+0xa0` | secondary base/interface vptr | all alert-family classes | Constructors store the secondary vtable here; destructor thunks adjust `this` by `-0xa0`. |
| `+0xa4` | tertiary base/interface vptr | all alert-family classes | Constructors store the tertiary vtable here; destructor thunks adjust `this` by `-0xa4`. |
| `+0x1fc` | control list pointer | inherited `DialogPane` state used by `AlertPane` | Constructor creates a `List(4, 20)` here when a scrollable text child needs manual insertion. |
| `+0x200` | selected/default control index candidate | inherited `DialogPane` state used by `AlertPane` | Constructor writes `1` after selecting the primary button. |
| `+0x204` | default/action control index candidate | inherited `DialogPane` state used by `AlertPane` | Constructor writes `1` or `2` depending on present primary/secondary buttons. |
| `+0x26c` | layout-anchor/reference pointer | `AlertPane` and `BlueAlertPane` | `AlertPane::AlertPane` and `BlueAlertPane::BlueAlertPane` store the caller layout reference here after showing and animating the dialog. |
| `+0x270` | callback object pointer | `VersatileAlertPane` | Constructor stores callback/control pointer; cleanup/destructor paths read and release it. |
| `+0x270` | heap-owned URL buffer | `UrlAlertPane` | Constructor zeroes then stores allocated URL buffer; destructor and `OnConfirm` read it. |
| `+0x274` | exit-after-open flag | `UrlAlertPane` | Constructor stores the flag byte; `OnConfirm` checks it before requesting application exit. |

The highest directly observed field is `UrlAlertPane::m_exitAfterOpen` at `+0x274`. Treat final `sizeof(AlertPane)` / `sizeof(BlueAlertPane)` / `sizeof(VersatileAlertPane)` / `sizeof(UrlAlertPane)` as open until allocation-site review proves the original declarations and tail padding.

## IDA Evidence

Checked on 2026-05-26:

- `AlertPane::AlertPane` at `0x0049feb0` stores vtables at `+0x00`, `+0xa0`, and `+0xa4`, and stores the layout reference at `+0x26c`.
- `AlertPane::DismissDialog` at `0x004a0580` dispatches primary-table slots `+0x5c` and `+0x60` for the two alert button callbacks.
- `VersatileAlertPane::VersatileAlertPane` at `0x004a0690` stores the callback pointer at `+0x270`, then installs the three `VersatileAlertPane` vtables.
- Raw `VersatileAlertPane` cleanup at `0x004a06e0` reads `+0x270`, reinstalls the same three vtables, releases the callback object, and jumps to base alert teardown.
- `BlueAlertPane::BlueAlertPane` at `0x005008c0` stores the same three-view vtable set and stores the layout reference at `+0x26c`.
- `UrlAlertPane::UrlAlertPane` at `0x00599a40` stores the three vtables, initializes/stores the URL pointer at `+0x270`, stores the exit flag byte at `+0x274`, and sets [UID:0000SM][g_pUrlAlertPane](by-global/g_pUrlAlertPane.md).
- `UrlAlertPane::~UrlAlertPane`, `UrlAlertPane::OnConfirm`, and `UrlAlertPane::ScalarDeletingDestructor` read `+0x270`; `OnConfirm` also checks byte `+0x274`.
- 2026-05-31 IDA MCP recheck of `0x0049feb0` confirms the three `AlertPane` vptr stores at `+0x00`, `+0xa0`, and `+0xa4`.
- 2026-05-31 IDA MCP recheck of `0x004a0690` confirms `VersatileAlertPane` calls the base alert constructor, writes the callback/control pointer at dword index `156` (`+0x270`), and installs the three `VersatileAlertPane` vptrs.
- 2026-05-31 IDA MCP recheck of `0x00599a40` confirms `UrlAlertPane` installs the three vptrs, initializes/stores the URL pointer at dword index `156` (`+0x270`), and writes the exit flag byte at offset `+0x274`.

## Generated-Data Caveat

Current `simroot_v2` metadata still reports `vtable_count: 0` for the alert-family classes despite IDA-confirmed vtable bases. Generated class sources also contain provisional field names such as `m_vtable2`, `m_vtable3`, `m_selectedControlIndex`, and `m_defaultControlIndex`; use those only as hints and keep derived alert-tail fields separate from base `DialogPane` state.

## Open Questions

- Final source-facing names for inherited control-list/default-index fields remain provisional until the base `DialogPane` layout is fully audited.
- Final class sizes and tail padding remain open for each alert-family class.

## Cross-References

- [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md)
- [UID:00000B][AlertPane](by-class/AlertPane.md)
- [UID:0000FU][VersatileAlertPane](by-class/VersatileAlertPane.md)
- [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md)
- [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md)
- [UID:00012W][0x0049feb0-0x004a0686.AlertPaneCore](by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md)
- [UID:00012X][0x004a0690-0x004a0752.VersatileAlertPaneCallbacks](by-memory/0x004a0690-0x004a0752.VersatileAlertPaneCallbacks.md)
- [UID:00012Y][0x004a06e0-0x004a0714.VersatileAlertPaneRawCleanup](by-memory/0x004a06e0-0x004a0714.VersatileAlertPaneRawCleanup.md)
- [UID:0001A5][0x005008c0-0x0050114d.BlueAlertPaneCore](by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md)
- [UID:0001KF][0x00599a40-0x00599cb3.UrlAlertPane](by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md)
- [UID:0001WZ][AlertPaneVtables](by-type/by-vtable/AlertPaneVtables.md)
- [UID:0001Z0][VersatileAlertPaneVtables](by-type/by-vtable/VersatileAlertPaneVtables.md)
- [UID:0001X3][BlueAlertPaneVtables](by-type/by-vtable/BlueAlertPaneVtables.md)
- [UID:0001YZ][UrlAlertPaneVtables](by-type/by-vtable/UrlAlertPaneVtables.md)
- [Wave3 data issues](../../wave3_data_issues.md)
