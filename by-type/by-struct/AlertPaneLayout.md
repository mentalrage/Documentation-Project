*** UID:0001TO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# AlertPane Layout

## Status

- Entity kind: class layout / derived-layout notes.
- Covered classes: [UID:00000B][AlertPane](by-class/AlertPane.md), [UID:00003O][DeleteReplyAlert](by-class/DeleteReplyAlert.md), [UID:0000FU][VersatileAlertPane](by-class/VersatileAlertPane.md), [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md), and [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md).
- Likely owner header/source: [UID:0000HE][AlertPanes](by-file/AlertPanes.md).
- Confidence: very strong for listed offsets, vtable stores, constructor/destructor anchors, `AlertPane` size `0x270`, `VersatileAlertPane` size `0x274`, its callback type/ownership, and shared file ownership. Remaining uncertainty is limited to unrelated inherited control-field names and other derived-class tails.
- Reconstructable: no standalone item. This is a reviewed cross-class layout audit; field declarations live on the owning class pages and the compiler derives layout from them.
- Canonical owner: [UID:0000HE][AlertPanes](by-file/AlertPanes.md). The page has no emitter, position, or formal C++ because the shared layout audit is not a source declaration unit.

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
| `+0x26c` | `m_layoutReference` / layout-anchor reference pointer | `AlertPane` and `BlueAlertPane` | `AlertPane::AlertPane` and `BlueAlertPane::BlueAlertPane` store the caller layout reference here after showing and animating the dialog. B002 2026-06-17 prefers `m_layoutReference` over owner/parent names because the pointer is consumed as a layout anchor/reference, not proven ownership. |
| `+0x270` | `ConfirmDeleteAlert::m_multiDelete` | `ConfirmDeleteAlert` derived tail | B002 2026-06-25 confirms [UID:0002US][0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor](by-memory/0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor.md) copies constructor argument `bool multiDelete` into `this+0x270`; [UID:0002SE][0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest](by-memory/0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest.md) consumes nonzero as the selected-list/multi-delete branch. This is derived `ConfirmDeleteAlert` state, not base `AlertPane` state. |
| `+0x270` | `DeleteReplyAlert::m_multiDelete` | `DeleteReplyAlert` derived tail | [UID:0004WC][0x0047e2f0-0x0047e34b.DeleteReplyAlertConstructor](by-memory/0x0047e2f0-0x0047e34b.DeleteReplyAlertConstructor.md) stores the fourth bool; [UID:0004WF][0x0047e390-0x0047e4a6.DeleteReplyAlertOnPrimaryButton](by-memory/0x0047e390-0x0047e4a6.DeleteReplyAlertOnPrimaryButton.md) selects selected-row versus single-ID reconciliation. `m_multiDelete` is preferred over historical `deleteAllReplies` because the true branch removes only selected rows. |
| `+0x271` | `DeleteReplyAlert::m_deleteSucceeded` | `DeleteReplyAlert` derived tail | UID0004WC normalizes/stores the packet-derived first argument independently; UID0004WF reads it before every local list mutation and returns immediately when false. The separate store/read chain proves a bool-like result gate rather than padding or a second mode. |
| `+0x270` | `MailDeleteReplyAlert::m_deleteAllReplies` | `MailDeleteReplyAlert` derived tail | B009 2026-06-19 confirms [UID:00007J][MailDeleteReplyAlert](by-class/MailDeleteReplyAlert.md) uses inherited `AlertPane::m_layoutReference` at `+0x26c` as the current `MailDialog *`, then adds a derived byte at `+0x270`. The byte selects bulk selected-reply deletion versus single-reply deletion. Do not treat it as base `AlertPane` state or copy unrelated `DeleteReplyAlert` extra mode bytes into this class. |
| `+0x270` | `FunctionObjectT<unsigned long> *VersatileAlertPane::m_resultCallback` | `VersatileAlertPane` | Two constructor sites transfer owned 24-byte concrete member-function callback objects; primary/secondary paths invoke slot `+0x0c` with result `1/0`, and both destructor copies delete the pointer through slot 0 with flag `1`. |
| `+0x270` | `UrlAlertPane::m_url` | `UrlAlertPane` | Constructor zeroes then stores an allocated `urlLength + 1` ANSI byte buffer, copies the packet-provided URL bytes, writes a NUL terminator, destructor frees the pointer, and `OnPrimaryButton` passes it to `ShellExecuteA`. Reject wide-string, borrowed-pointer, and `StringBase` interpretations. |
| `+0x274` | `UrlAlertPane::m_exitAfterOpen` | `UrlAlertPane` | Constructor stores the first argument byte; `OnPrimaryButton` tests it and calls `Application::RequestExit` only when nonzero. Reject URL-length storage or a multi-case mode enum because only zero/nonzero behavior is observed. |

The Versatile scalar deleting wrapper's exact guarded-size path passes `0x274` / 628, and both construction sites allocate 628 bytes. Because its only derived field is the four-byte callback at `+0x270`, `sizeof(VersatileAlertPane)==0x274`. The derived-tail start independently fixes `sizeof(AlertPane)==0x270` for this layout. These exact facts do not force sizes for `BlueAlertPane` or `UrlAlertPane`; the latter still has observed `0x278` direction from its separate evidence.

## IDA Evidence

Checked on 2026-05-26:

- `AlertPane::AlertPane` at `0x0049feb0` stores vtables at `+0x00`, `+0xa0`, and `+0xa4`, and stores the layout reference at `+0x26c`.
- `AlertPane::DismissDialog` at `0x004a0580` dispatches primary-table slots `+0x5c` and `+0x60` for the two alert button callbacks. B002's 2026-06-17 source-quality recheck resolves its ABI as `DismissDialog(int buttonId, int unused)` and names the no-argument slots `OnPrimaryButton` and `OnSecondaryButton`.
- `VersatileAlertPane::VersatileAlertPane` at `0x004a0690` stores `m_resultCallback` at `+0x270`, then installs the three `VersatileAlertPane` vtables.
- Raw `VersatileAlertPane` cleanup at `0x004a06e0` reads `+0x270`, reinstalls the same three vtables, releases `m_resultCallback` through the shared `FunctionObject` cleanup slot, and jumps to base alert teardown.
- `BlueAlertPane::BlueAlertPane` at `0x005008c0` stores the same three-view vtable set and stores the layout reference at `+0x26c`.
- `UrlAlertPane::UrlAlertPane` at `0x00599a40` stores the three vtables, initializes/stores `m_url` at `+0x270`, stores `m_exitAfterOpen` at `+0x274`, and sets [UID:0000SM][g_pUrlAlertPane](by-global/g_pUrlAlertPane.md).
- `UrlAlertPane::~UrlAlertPane`, `UrlAlertPane::OnPrimaryButton` / confirm handler, and `UrlAlertPane` scalar deleting destructor read `+0x270`; the handler also checks byte `+0x274`.
- 2026-05-31 IDA MCP recheck of `0x0049feb0` confirms the three `AlertPane` vptr stores at `+0x00`, `+0xa0`, and `+0xa4`.
- 2026-06-25 B002 source-quality pass confirms `ConfirmDeleteAlert` uses inherited `AlertPane::m_layoutReference` as the constructor's `Pane *layoutReference` parameter and adds derived byte `m_multiDelete` at `+0x270`; modeled construction mirrors write `1` from board/list delete paths and `0` from article-dialog paths.
- 2026-07-22 B005 UID0003Q0 source-closure pass confirms DeleteReplyAlert uses the inherited layout reference and adds two independent derived bytes: `m_multiDelete` at `+0x270` and `m_deleteSucceeded` at `+0x271`. Constructor caller modes, separate stores, ordered action reads, and selected/single behavior provide strong semantic evidence; exact original spellings remain high-probability inference.
- 2026-05-31 IDA MCP recheck of `0x004a0690` confirms `VersatileAlertPane` calls the base alert constructor, writes the callback/control pointer at dword index `156` (`+0x270`), and installs the three `VersatileAlertPane` vptrs.
- 2026-07-14 B004 phase-two recheck resolves the `VersatileAlertPane` `+0x270` field as owned `FunctionObjectT<unsigned long> *m_resultCallback`: decorated 24-byte concrete callback objects, generic invoke slot `+0x0c`, source handlers with unsigned-long values `1/0`, and destructor slot-0 deletion reject conservative untyped, bool, borrowed, flag/control-word, and pane-local-interface alternatives.
- The same recheck confirms scalar-wrapper deleting flags, return-this behavior, three vtable restores, ordinary DialogPane teardown, optional free, and exact guarded size `0x274`; paired caller allocations independently confirm the class size.
- 2026-05-31 IDA MCP recheck of `0x00599a40` confirms `UrlAlertPane` installs the three vptrs, initializes/stores the URL pointer at dword index `156` (`+0x270`), and writes the exit flag byte at offset `+0x274`.
- 2026-06-21 B011 source-quality recheck names the `UrlAlertPane` tail fields as `m_url` and `m_exitAfterOpen`, rejects wide-string/borrowed/StringBase and length/mode interpretations, confirms `ShellExecuteA` consumes the ANSI URL pointer directly, and records the observed `0x278` object-size direction while keeping final `sizeof` spelling open.
- 2026-06-11 A003 live IDA MCP recheck against `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515` reconfirmed core bounds for `AlertPane` constructor/dismiss (`0x0049feb0-0x004a0575`, `0x004a0580-0x004a0686`), `VersatileAlertPane` constructor (`0x004a0690-0x004a06d7`) with raw cleanup still not modeled as a function at `0x004a06e0`, `BlueAlertPane` constructor (`0x005008c0-0x00500c24`), `UrlAlertPane` constructor (`0x00599a40-0x00599b19`), and shared scalar destructor (`0x0048c550-0x0048c58b`). The same pass reconfirmed vtable stores for AlertPane at `0x0049ff1e/0x0049ff24/0x0049ff2e`, Versatile at `0x004a06b6/0x004a06bc/0x004a06c6` plus cleanup/destructor refs, Blue at `0x00500920/0x00500926/0x00500930`, and Url at `0x00599aac/0x00599ab2/0x00599abc`, with constructor xrefs to `AlertPane::AlertPane` across shared UI call sites and Url constructor callers at `0x00503034`, `0x00513f7e`, and `0x0051402f`.

## Generated-Data Caveat

Current `simroot_v2` metadata still reports `vtable_count: 0` for the alert-family classes despite IDA-confirmed vtable bases. Generated class sources also contain provisional field names such as `m_vtable2`, `m_vtable3`, `m_selectedControlIndex`, and `m_defaultControlIndex`; use those only as hints and keep derived alert-tail fields separate from base `DialogPane` state.

## Non-Emitting Layout Disposition

This family layout is `91/95` and canonically owned by [UID:0000HE][AlertPanes](by-file/AlertPanes.md), whose broader score and source content remain unchanged. The page intentionally spans `AlertPane`, `VersatileAlertPane`, `BlueAlertPane`, and `UrlAlertPane`, so a single class parent would be too narrow. It is nevertheless false/non-emitting: no original standalone `AlertPaneLayout` struct is evidenced, and emitting fields here would duplicate the owning class declarations.

The formal C++ block is exactly blank. A comment marker would retain a false emitter; a synthetic aggregate struct would merge unrelated derived tails and expose compiler offsets as source.

Rejected alternatives include treating `+0x270` as base `AlertPane` state, using a bool or pane-local callback type, treating the callback as borrowed, claiming `0x274` is the callback field offset rather than total size, copying `UrlAlertPane` tail fields into Versatile, and asserting one shared final size for every alert-family class.

## Open Questions

- Final source-facing names for inherited control-list/default-index fields remain provisional until the base `DialogPane` layout is fully audited.
- Final size/tail padding remains open only for the unrelated `BlueAlertPane` and `UrlAlertPane` branches; `AlertPane==0x270` and `VersatileAlertPane==0x274` are resolved for this layout. `UrlAlertPane` retains its separate high-probability observed `0x278` direction.

## Cross-References

- [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md)
- [UID:00000B][AlertPane](by-class/AlertPane.md)
- [UID:0000FU][VersatileAlertPane](by-class/VersatileAlertPane.md)
- [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md)
- [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md)
- [UID:000033][ConfirmDeleteAlert](by-class/ConfirmDeleteAlert.md)
- [UID:0002US][0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor](by-memory/0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor.md)
- [UID:0002SE][0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest](by-memory/0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest.md)
- [UID:00012W][0x0049feb0-0x004a0686.AlertPaneCore](by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md)
- [UID:00012X][0x004a0690-0x004a0752.VersatileAlertPaneMethodIsland](by-memory/0x004a0690-0x004a0752.VersatileAlertPaneMethodIsland.md)
- [UID:00012Y][0x004a06e0-0x004a0715.VersatileAlertPaneDestructor](by-memory/0x004a06e0-0x004a0715.VersatileAlertPaneDestructor.md)
- [UID:000130][0x004a0cb0-0x004a0d37.VersatileAlertPaneDeletingDestructorAbiIsland](by-memory/0x004a0cb0-0x004a0d37.VersatileAlertPaneDeletingDestructorAbiIsland.md)
- [UID:0004NE][0x004a0cb0-0x004a0cbb.VersatileAlertPaneDestructorAdjustorThunkA0](by-memory/0x004a0cb0-0x004a0cbb.VersatileAlertPaneDestructorAdjustorThunkA0.md)
- [UID:0004NF][0x004a0cbb-0x004a0cc6.VersatileAlertPaneDestructorAdjustorThunkA4](by-memory/0x004a0cbb-0x004a0cc6.VersatileAlertPaneDestructorAdjustorThunkA4.md)
- [UID:0004NG][0x004a0cd0-0x004a0d37.VersatileAlertPaneScalarDeletingDestructor](by-memory/0x004a0cd0-0x004a0d37.VersatileAlertPaneScalarDeletingDestructor.md)
- [UID:0001A5][0x005008c0-0x0050114d.BlueAlertPaneCore](by-memory/0x005008c0-0x0050114d.BlueAlertPaneCore.md)
- [UID:0001KF][0x00599a40-0x00599cb3.UrlAlertPane](by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md)
- [UID:0001WZ][AlertPaneVtables](by-type/by-vtable/AlertPaneVtables.md)
- [UID:0001Z0][VersatileAlertPaneVtables](by-type/by-vtable/VersatileAlertPaneVtables.md)
- [UID:0001X3][BlueAlertPaneVtables](by-type/by-vtable/BlueAlertPaneVtables.md)
- [UID:0001YZ][UrlAlertPaneVtables](by-type/by-vtable/UrlAlertPaneVtables.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-07-22 B005 UID0003Q0 callback: retained `91/95` false/no-emitter layout disposition; added exact DeleteReplyAlert `+0x270/+0x271` derived bytes, constructor/action evidence, inference strength, and rejection of the stale all-replies interpretation.
- 2026-06-25 B002 ConfirmDeleteAlert constructor support incorporation: no score change. Added `ConfirmDeleteAlert::m_multiDelete` as a derived-tail use of `+0x270`, clarified it is not base `AlertPane` state, and linked the constructor/action evidence that selects multi-delete versus single-delete behavior.
- 2026-06-11 A003 supervisor-row pass:
  - Changed from: `78/87`, reconstructable, parent blank.
  - Changed to: `85/89`, parent [UID:0000HE][AlertPanes](by-file/AlertPanes.md), C++ still blank.
  - Evidence: live IDA reconfirmed AlertPane, VersatileAlertPane, BlueAlertPane, UrlAlertPane, and shared destructor bounds; three-view vtable stores and data refs; raw Versatile cleanup non-function status; broad AlertPane constructor fan-in; Url constructor callers; and the direct file parent reaching the strict gate.
- 2026-06-17 B002 source-quality execution:
  - Score unchanged at `85/89`.
  - Clarified the `VersatileAlertPane` `+0x270` derived-tail field as `m_resultCallback`, with unsigned-long `FunctionObject` callback direction, accept/cancel result values `1/0`, and cleanup/destructor release behavior.
- 2026-06-17 B002 AlertPane source-quality execution:
  - Score unchanged at `85/89`.
  - Clarified the base `AlertPane` `+0x26c` field as `m_layoutReference`, recorded `DismissDialog(int buttonId, int unused)`, and named the primary/secondary callback slots `OnPrimaryButton` / `OnSecondaryButton`.
- 2026-06-21 B009 Rule 26 support incorporation: no score change. Added `MailDeleteReplyAlert::m_deleteAllReplies` as a derived-tail use of `+0x270` and clarified that inherited `m_layoutReference` at `+0x26c` is used as the current mail dialog pointer in that class.
- 2026-06-21 B011 UrlAlertPane source-quality incorporation: no score change. Replaced generic `heap-owned URL buffer` / `exit-after-open flag` wording with `UrlAlertPane::m_url` and `UrlAlertPane::m_exitAfterOpen`, documented rejected alternate interpretations, and recorded the observed `0x278` object-size direction while leaving final class-size spelling open.
- 2026-06-30 B011 empty-emitter implementation:
  - Score and metadata unchanged at `85/89`, owner/emitter [UID:0000HE][AlertPanes](by-file/AlertPanes.md).
  - Added the formal layout-audit no-code marker. It preserves the three vptr offsets `+0x00`, `+0xa0`, `+0xa4`, base layout reference `+0x26c`, class-specific `+0x270` uses, `UrlAlertPane::m_exitAfterOpen` at `+0x274`, derived-tail ownership rules, and the no standalone struct policy pending final DialogPane layout and class-size audit.
- 2026-07-14 B004 phase-two callback:
  - Raised `85/89 -> 91/95`, retained canonical owner UID0000HE, and reclassified the cross-family audit false/non-emitting with blank emitter, position, and formal C++.
  - Resolved exact `sizeof(AlertPane)==0x270`, `sizeof(VersatileAlertPane)==0x274`, and owned `FunctionObjectT<unsigned long> *m_resultCallback` at `+0x270` from constructor allocation, scalar-wrapper size, decorated callback, invoke, and destructor evidence.
  - Preserved all unrelated ConfirmDelete/MailDelete/Blue/Url fields, scores, open questions, and historical evidence without extending the Versatile result to unsupported family sizes.
