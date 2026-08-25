*** UID:0001TY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Clan Input Dialog Layouts

## Status

- Confidence: very strong for the documented offsets, `0x870` ClanAttr object size, function bounds, vtable stores, packet/control layout, and Clan source ownership; medium-high for final source-level field and packet-label names.
- Current entity kind: recovered layout notes for [UID:00002J][ClanNameInputDialog](by-class/ClanNameInputDialog.md), [UID:000024][ClanAttrInputDialog](by-class/ClanAttrInputDialog.md), and derived clan modal dialogs.
- Direct owner source: [UID:0000I8][Clan](by-file/Clan.md). [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md) is a non-standalone, non-emitting family/index that retains historical split analysis but is not a competing source owner.
- Evidence basis: IDA MCP lookup/decompile/caller checks on 2026-05-31, [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md), and generated `simroot_v2` source only as a search/context lead. `wave3.py` was not executed for this pass.
- Autogen parent: [UID:0000I8][Clan](by-file/Clan.md). This family layout belongs with the active Clan declarations and methods; UID0000IA has path/owner `NONE` and cannot receive emitted layout declarations.

Current 2026-08-14 source resolution: `ClanNameInputDialog` and `ClanAttrInputDialog` declare `bool HandlePointerOrMouseEvent(Event *event)` in their owning H channels, and exact by-memory children emit the method definitions in `NexusTK/social/Clan.cpp`. The nine retained modal constructor ranges likewise emit their accepted out-of-line definitions; absent modeled raw-function/inbound-start routes remain confidence evidence only. This layout page remains non-emitting, while modal vtables/COLs and destructor adjustors remain compiler-generated consequences of the class declarations rather than handwritten layout source.

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

IDA MCP `lookup_funcs` confirms `ClanAttrInputDialog` functions at `0x00489600`, `0x00489df0`, `0x00489ec0`, and `0x00489f50`. The constructor stores vtables at `+0x000/+0x0a0/+0x0a4`, decodes six sequential counted CP_ACP packet strings beginning at `packet+3`, converts the first directly into `this+0x26c`, and uses the remaining five as visible labels. `OnControlCommand` fetches controls `8`, `9`, and `10` from the inherited control host, copies ids `8` and `9` into `this+0x46c` and `this+0x66c`, parses id `10` into the 16-bit field at `this+0x86c`, dispatches the common pure-virtual `OnSubmit()` hook, then closes. `ValidateInputFields` checks controls `8`, `9`, and `10` and toggles control id `1`. Historical `OnDialogAction`, `OnSubmitEnlistment`, and `SubmitClanChange` labels are descriptive aliases superseded by the inherited/common-slot contracts.

IDA decompilation of `0x0048a030` confirms the derived clan-change submit method calls helper `0x00486330` with `this+0x26c`, `this+0x46c`, `this+0x66c`, and `*(uint16_t *)(this+0x86c)`, validating the persistent field meanings across construction, dialog action, and packet submission.

2026-06-11 A003 live IDA MCP recheck against `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515` reconfirmed exact ClanName bounds `0x00488b40-0x00488eab`, `0x00488eb0-0x00488f24`, `0x00488f30-0x00488f67`, and `0x00488f70-0x00488fa0`, exact ClanAttr bounds `0x00489600-0x00489de1`, `0x00489df0-0x00489eb7`, `0x00489ec0-0x00489f46`, and `0x00489f50-0x00489f80`, and the `ClanChangeInputDialog` submitter/helper chain `0x0048a030-0x0048a059 -> 0x00486330-0x0048652e`. The same pass reconfirmed constructor/caller fanout for `ClanNameInputDialog` and `ClanAttrInputDialog`, primary vtable stores at `0x00488b9e` and `0x00489660`, `ClanChangeInputDialog` table stores at `0x004852ee`, `0x004883ed`, and `0x0048a002`, and the primary vtable dwords showing the shared `DialogPane`/clan-dialog inheritance shape.

### DLGCLAN2 Primary Virtual Contract

The exhaustive 24-entry primary-table comparison resolves the old common-hook blocker. Base `ClanAttrInputDialog` table `0x00615d58`, Enlist table `0x00615df8`, and Change table `0x00615e98` are identical through offset `+0x58`. Their inherited `+0x48` cells at `0x00615da0`, `0x00615e40`, and `0x00615ee0` all point to UID0004HI `0x00489df0`, proving the source-facing `OnControlCommand(int,int)` identity. Only `+0x5c` differs: base cell `0x00615db4` points to `__purecall`, Enlist cell `0x00615e54` points to UID0002O3 `0x00489fc0`, and Change cell `0x00615ef4` points to UID0002O5 `0x0048a030`. The class contract is therefore pure virtual inferred `int OnSubmit()`, with identical derived overrides and no handwritten vtable array source.

## ClanNameInputDialog

No class-specific persistent storage is confirmed beyond the inherited `DialogPane` state. The constructor decodes packet prompt text into stack buffers, builds `DLGCLAN1.EPF`, then creates controls:

The prompt is a counted CP_ACP byte string, not protocol NUL-terminated text: `packet[3]` is the byte length and `packet + 4` is the payload. The constructor appends a local byte terminator but calls `MultiByteToWideChar(CP_ACP, 0, promptBytes, promptLength, promptWide, 0x8000)` with the explicit count, then terminates the wide buffer. This keeps the constructor signature source-facing as `ClanNameInputDialog::ClanNameInputDialog(const unsigned char *packet)` rather than the decompiler's raw `int`/narrow-traits artifact.

| Control id | Role | Evidence |
| --- | --- | --- |
| `1` | OK/action image button | `UpdateOkButtonState` enables or disables this control based on input text. |
| `2` | Cancel image button | `OnButtonClick` closes the dialog without submit on id `2`. |
| `4` | text edit input field | `OnButtonClick` reads this control's text and dispatches through the submit virtual at primary vtable slot `+0x5c`. |

Image/resource indices are separate from logical control ids: the OK image button uses resource index `14` and logical id `1`, while the Cancel image button uses resource index `22` and logical id `2`.

The base submit hook is now resolved at source quality for this layout family. B001's accepted submitter pass maps primary vtable slot `+0x5c` / index `23` to inferred/descriptive `OnSubmitText(const wchar_t *text)` across the six exact derived submitters. B002/B009 [UID:00010J][0x00488b40-0x00488fa0.ClanNameInputDialogCore](by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md) reanalysis closes the old submit-slot blocker for the base core while still leaving exact original symbol spelling below final confidence.

`UpdateOkButtonState` owns the OK id `1` enable/disable polarity from text id `4`: empty text calls the OK-button state slot at `+0x50`, non-empty text calls slot `+0x4c`, source-facing as `SetEnabled(!textEdit->IsEmpty())`. `HandlePointerOrMouseEvent(Event *event)` is separate; it forwards event type `3` through `g_pClanStatusPane`'s secondary view and returns the base handler result, and should not be described as directly calling the OK-state helper. Historical `OnInputEvent`/`InputEvent` naming is retained only as superseded analysis.

## ClanAttrInputDialog

`ClanAttrInputDialog` adds persistent submitted-field storage after the inherited dialog state:

| Offset | Size | Meaning | Evidence |
| --- | --- | --- | --- |
| `+0x26c` | `0x200` | `m_submittedClanName` / first submitted wide string | Constructor stores the first packet string here; both `ClanEnlistInputDialog::OnSubmit` and `ClanChangeInputDialog::OnSubmit` pass `this + 0x26c` as the first string. |
| `+0x46c` | `0x200` | `m_submittedDescriptionText` / second submitted wide string | `OnControlCommand` copies edit control id `8` into this field; both `OnSubmit` overrides pass it as the second string. |
| `+0x66c` | `0x200` | `m_submittedAttributeText` / third submitted wide string | `OnControlCommand` copies edit control id `9` into this field; both `OnSubmit` overrides pass it as the third string. `m_submittedFlagText` remains an alternate semantic label until exact UI text is recovered. |
| `+0x86c` | `2` | `m_submittedAttributeType` / submitted numeric type value | `OnControlCommand` parses edit control id `10` into this field without clamping; both `OnSubmit` overrides pass the low 16-bit value to helpers `0x00485ac0` and `0x00486330`. |

The modeled Enlist/Change opener sites allocate `0x870` bytes, making `0x870` the complete observed object size for this inherited field block. The three 256-wide-character fields end at `+0x86c`, the final 16-bit field occupies `+0x86c-0x86e`, and the remaining tail is alignment. `ClanEnlistInputDialog` and `ClanChangeInputDialog` install their own three vtable views after calling/inlining this base constructor; no additional derived persistent fields are currently observed.

### Constructor Packet Layout

The constructor's single explicit argument is source-facing `const unsigned char *packet`. Starting at `packet+3`, it consumes six consecutive records, each encoded as one unsigned-byte length followed by exactly that many CP_ACP bytes. Each record is locally byte-terminated, converted with an explicit source length and a 256-wide-character destination capacity, then wide-terminated. The first wide result persists in `m_submittedClanName`; records two through six are stack-local text for the visible controls.

The executable cannot provide literal text for the five labels because the server packet supplies it. Current descriptive roles are therefore order/geometry inferences, not missing embedded resources: heading/prompt, clan/context caption, description prompt, attribute prompt, and attribute-type prompt. This naming cap does not affect the packet layout or formal constructor behavior.

### Constructor Control Layout

Controls receive logical ids by insertion order. Image indices `14` and `22` are button resource indices and remain distinct from logical ids `1` and `2`.

| Logical id | Control / packet role | Rect `(left,top,right,bottom)` |
| --- | --- | --- |
| `0` | `EPFImageControlPane`, `DLGCLAN2.EPF` | `(0,0,259,288)` |
| `1` | OK image button, image index `14` | `(53,228,125,244)` |
| `2` | Cancel image button, image index `22` | `(130,228,202,244)` |
| `3` | packet string 2 heading/prompt | `(41,20,231,45)` |
| `4` | packet string 3 clan/context caption | `(41,49,231,74)` |
| `5` | packet string 4 description prompt | `(41,66,231,91)` |
| `6` | packet string 5 attribute prompt | `(41,116,231,141)` |
| `7` | packet string 6 attribute-type prompt | `(41,166,231,191)` |
| `8` | empty first edit control | `(41,91,218,104)` |
| `9` | empty second edit control | `(41,141,218,154)` |
| `10` | empty numeric/type edit control | `(41,191,218,204)` |

After insertion, the constructor sets hover control `8`, focused/default action `1`, pending/cancel action `2`, background `DLGCLAN2.EPF`, and pane mode `1`. It creates the dialog at bounds `(174,12,433,300)` through `g_mainUiLayerSlots.overlayPaneLayerContext`, shows it relative to `g_pBackPane`, and calls `SlideOpenHorizontal(0)`. The constructor itself does not read or write `g_pClanStatusPane`; that singleton is used by later `HandlePointerOrMouseEvent(Event *)` and submit paths.

Control ids used by the base attribute dialog:

| Control id | Role | Evidence |
| --- | --- | --- |
| `1` | OK/action image button | `ValidateInputFields` toggles this button. |
| `2` | Cancel image button | `OnControlCommand` closes the dialog without submit on id `2`. |
| `8` | first editable submitted text | Read into `+0x46c` on OK. |
| `9` | second editable submitted text | Read into `+0x66c` on OK. |
| `10` | numeric/type text field | Parsed into `+0x86c` on OK. |

## Source-Layout Impact

These layouts keep the clan modal input classes with the Clan feature source. `ClanNameInputDialog` is a reusable shell for one-field clan actions; `ClanAttrInputDialog` is the reusable shell for multi-field attribute updates. Derived classes override submit/confirm behavior without duplicating the base layout in one-class source files. UID0000IA remains useful as an exhaustive family/index and historical split record, but it is not a translation unit; UID0000I8 is the direct source owner.

The 2026-08-14 whole-family reconciliation also closes the former raw-constructor source gap. The six name/money derived constructors emit `Derived(const unsigned char *packet) : ClanNameInputDialog(packet) {}`, `ClanEnlistInputDialog` and `ClanChangeInputDialog` emit the corresponding `ClanAttrInputDialog(packet)` delegating definitions, and `ClanLeaveConfirmDialog` emits its four-argument `AlertPane` forwarding definition. Their absent inbound raw-entry routes remain confidence evidence only; the exact executable constructor ranges are source-bearing and are not comment-only or no-code records.

Current reachability preserves two distinct facts. Three modeled caller sites allocate `0x870`, run the base constructor sequence, and install Enlist/Change vtables, proving live derived construction. Separate 53-byte raw constructor starts at `0x00489f80` and `0x00489ff0` call the base and install the same derived table families, but current xref/pointer checks find no direct route to those raw starts. Their exact by-memory children emit the corresponding out-of-line delegating constructor definitions; route negatives remain confidence evidence and do not reclassify the bytes as duplicate/no-code bodies or padding.

2026-06-17 B001 rechecked the six derived `ClanNameInputDialog` submitters [UID:0002NS][0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney](by-memory/0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney.md), [UID:0002NU][0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney](by-memory/0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney.md), [UID:0002NW][0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName](by-memory/0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName.md), [UID:0002NY][0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName](by-memory/0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName.md), [UID:0002O0][0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName](by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md), and [UID:0002O2][0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName](by-memory/0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName.md). All six map to the shared base submit virtual slot at primary vtable `+0x5c`, inferred/descriptive `OnSubmitText(const wchar_t *text)`. The money variants use CRT `_wtol` and big-endian `PacketBufferWriteUInt32BE`; the name variants use CP_ACP conversion, one-byte converted length, manual payload copy, and the same queued sender. The later 2026-08-14 family reconciliation closes the then-open constructor/source-split and declaration work: all six constructors emit through exact children and all declarations use owning H channels.

2026-06-20 B002 refresh for [UID:000023][ClanAppearNameInputDialog](by-class/ClanAppearNameInputDialog.md) confirms no derived persistent fields for `ClanAppearNameInputDialog` beyond inherited `ClanNameInputDialog` state and the primary/secondary/tertiary vfptr views at `+0`, `+0xa0`, and `+0xa4`. The derived class's unique behavior is its `OnSubmitText(const wchar_t *)` override at primary slot `+0x5c`.

2026-06-20 B004 refresh for [UID:00002A][ClanDepMoneyInputDialog](by-class/ClanDepMoneyInputDialog.md) confirms the same no-unique-persistent-field model for the deposit-money dialog: it derives from `ClanNameInputDialog`, accepts the same packet pointer constructor argument, installs derived vfptr views at `+0`, `+0xa0`, and `+0xa4`, and differs by primary submit slot `+0x5c` resolving to `ClanDepMoneyInputDialog::OnSubmitText(const wchar_t *)`. Its exact raw child emits the delegating constructor definition; the missing direct raw-start route remains confidence evidence, while live inline base-constructor calls and vtable stores corroborate the class shape.

2026-06-19 B012 rechecked [UID:00002O][ClanWidMoneyInputDialog](by-class/ClanWidMoneyInputDialog.md): class source shape is a `ClanNameInputDialog` one-field dialog with no confirmed new fields, an exact source-emitting delegating constructor whose raw start has no direct route, and an active `OnSubmitText(const wchar_t *)` withdraw-money override.

2026-06-21 B011 refresh for [UID:00002D][ClanExpelNameInputDialog](by-class/ClanExpelNameInputDialog.md) confirms the same inherited-layout model for the expel-name dialog: the allocation/open path uses object size `0x26c`, the constructor argument is the packet pointer forwarded to `ClanNameInputDialog`, the derived identity is the primary/secondary/tertiary vfptr group at `+0`, `+0xa0`, and `+0xa4`, and no expel-specific persistent fields are confirmed. Its unique source behavior is primary slot `+0x5c`, vtable slot `0x00615b34 -> 0x00489180`, resolving to `ClanExpelNameInputDialog::OnSubmitText(const wchar_t *)`.

2026-06-20 B003 historical refresh for [UID:0002O3][0x00489fc0-0x00489fe9.ClanEnlistInputDialogOnSubmit](by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogOnSubmit.md) extended the DLGCLAN2 field-name direction under the then-descriptive `ClanEnlistInputDialog::OnSubmitEnlistment()` alias: the submitter forwards `+0x26c/+0x46c/+0x66c/+0x86c` to subtype `6`, action `2` `SendClanAttributePacket`, and the caller preserves `g_pClanStatusPane` context before the helper call. The current method identity is the common `OnSubmit()` override; the descriptive member names remain shared across Enlist and Change, with exact original control labels still open.

## Assignment Gate

This layout clears the strict gate at `88/92`. It attaches to [UID:0000I8][Clan](by-file/Clan.md), which remains `90/85` and directly owns the modal dialog family in its source map. No class parent is used because the page intentionally covers both `ClanNameInputDialog`, `ClanAttrInputDialog`, and their derived clan modal submitters as one shared layout family. The formal C++ block remains blank because this is cross-class layout documentation, not a standalone emitted struct.

## Cross-References

- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md)
- [UID:00010J][0x00488b40-0x00488fa0.ClanNameInputDialogCore](by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md)
- [UID:00010L][0x00489600-0x00489f80.ClanAttrInputDialogCore](by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md)
- [UID:000027][ClanChangeInputDialog](by-class/ClanChangeInputDialog.md)
- [UID:00010F][0x00486330-0x0048652d.SubmitClanChangeHelper](by-memory/0x00486330-0x0048652d.SubmitClanChangeHelper.md)

## Open Questions

- Exact historical filename/object partition remains unprovable without a PDB, map, object provenance, build manifest, or source archive. Current resolution is not to create `ClanDialogs.cpp`: UID0000IA remains a non-emitting index and all modal declarations/definitions stay under Clan. This is a bounded historical uncertainty, not an open emitter or constructor-placement question.
- Exact original member/local names and the five packet-provided label literals remain unrecovered. Accepted descriptive names preserve behavior and keep the constructor/source layout unblocked.
- The old DLGCLAN2 common-hook question is closed: exhaustive primary-table comparison proves base `__purecall` and the two derived bodies at common slot `+0x5c`. Only the inferred original lexical spelling `OnSubmit` and highest-probability `int` return remain confidence caps, not blockers.
- Constructor placement and emission are closed for this family: all nine retained modal constructor ranges emit exact out-of-line definitions through their by-memory children, while route negatives remain confidence history. Future work may refine only inferred lexical/member names or independently researched non-name/attribute confirm families; it must not reopen the accepted Clan source route or convert these constructors back to markers. The six `ClanNameInputDialog` submit overrides [UID:0002NS][0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney](by-memory/0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney.md), [UID:0002NU][0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney](by-memory/0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney.md), [UID:0002NW][0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName](by-memory/0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName.md), [UID:0002NY][0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName](by-memory/0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName.md), [UID:0002O0][0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName](by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md), and [UID:0002O2][0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName](by-memory/0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName.md) remain mapped to shared submit slot `+0x5c` / inferred `OnSubmitText(const wchar_t *)`.

## Changes

The dated entries below preserve investigation history. Older `OnInputEvent`, `InputEvent`, constructor no-code, or coordinated `ClanDialogs.cpp` caveats are superseded by the current 2026-08-14 source resolution above; they are not current emitter or naming instructions.

- 2026-07-13 B004 UID0004HI contract implementation:
  - Raised `87/91` to `88/92`, synchronized the DLGCLAN2 handler to inherited `OnControlCommand(int,int)`, and synchronized both derived submitters to common pure-virtual `OnSubmit()`.
  - Added the exhaustive 24-entry primary-table result: all three tables are identical through `+0x58`, all `+0x48` cells point to UID0004HI, base `+0x5c` is `__purecall`, and Enlist/Change `+0x5c` cells point to UID0002O3/UID0002O5.
  - Preserved non-emitting layout state, all object/field/control facts, packet buffer and constructor behavior, raw-constructor no-route evidence, Clan source route, ClanDialogs family-split caveat, and all ClanName-family content.

- 2026-07-12 B003 accepted UID0004HH layout support callback:
  - Raised `85/90` to `87/91` and added the observed `0x870` complete size, six-record packet layout, exact eleven-control insertion order/geometry, overlay-layer/`g_pBackPane` setup, and no-constructor-singleton result.
  - Preserved the four submitted-field offsets/names, non-emitting cross-class layout disposition, owner [UID:0000I8][Clan](by-file/Clan.md), raw Enlist/Change constructor no-route evidence, live inline derived construction, and rejection of a one-off ClanDialogs migration.
- 2026-06-30 B007 implementation callback: cleared `EMITTER_UIDS` and kept the formal C++ block empty because this page is a cross-class layout note for `ClanNameInputDialog` and `ClanAttrInputDialog`, not a standalone source struct. Exact field offsets and source-facing names are carried by the class and method pages.
- 2026-06-20 B003 ClanEnlistInputDialog submitter source-quality incorporation:
  - Updated the DLGCLAN2 submitted-field table with descriptive source-facing names and both submitter users: [UID:0002O3][0x00489fc0-0x00489fe9.ClanEnlistInputDialogOnSubmit](by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogOnSubmit.md) for subtype `6` action `2`, and [UID:0002O5][0x0048a030-0x0048a059.ClanChangeInputDialogOnSubmit](by-memory/0x0048a030-0x0048a059.ClanChangeInputDialogOnSubmit.md) for subtype `10`.
  - Scores remain `85/90`; this is a support-semantics refinement and keeps exact original UI labels as the remaining naming question.
- Reclassified the page from unevaluated to reconstructable layout documentation with conservative scores. Evidence: IDA MCP lookup/decompile/caller checks on 2026-05-31 verify the shared dialog vtable/control-host layout and the `ClanAttrInputDialog` persistent fields across constructor, OK handling, validation, and `0x0048a030` clan-change submission; source-file split and full derived-class inventory remain below near-final confidence.
- 2026-06-11 A003 supervisor-row pass:
  - Changed from: `76/88`, reconstructable, parent blank.
  - Changed to: `85/90`, parent [UID:0000I8][Clan](by-file/Clan.md), C++ still blank.
  - Evidence: live IDA reconfirmed exact ClanName/ClanAttr function bounds, vtable stores and dwords, constructor fanout, submitted-field offsets, `ClanChangeInputDialog` helper chain, and the strict owner decision favoring `Clan` (`90/85`) over the lower-confidence `ClanDialogs` split candidate (`86/82`).
- 2026-06-17 B001 Clan submitter source-quality execution:
  - Added the shared submit-slot mapping for the six exact derived `ClanNameInputDialog` submitters, including the `OnSubmitText(const wchar_t *)` inference, money/name packet construction distinction, and the remaining constructor/source-split scope.
- 2026-06-20 B002 ClanAppearNameInputDialog layout note:
  - Added the target-specific conclusion that `ClanAppearNameInputDialog` adds no persistent fields beyond inherited `ClanNameInputDialog` state; the relevant derived layout evidence is its three vfptr views and primary submit slot override.
- 2026-06-20 B004 ClanDepMoneyInputDialog layout note:
  - Added the target-specific conclusion that `ClanDepMoneyInputDialog` adds no persistent fields beyond inherited `ClanNameInputDialog` state; the relevant derived layout evidence is its packet-pointer constructor argument, three vfptr views, raw/no-route constructor child, and primary submit slot override.
- 2026-06-19 B012 ClanWidMoneyInputDialog layout note:
  - Added the target-specific conclusion that `ClanWidMoneyInputDialog` adds no persistent fields beyond inherited `ClanNameInputDialog` state; the relevant derived layout evidence is its packet-pointer constructor shape, three vfptr views, raw/no-route constructor child, and primary submit slot override.
- 2026-06-21 B011 ClanExpelNameInputDialog layout note:
  - Added the target-specific conclusion that `ClanExpelNameInputDialog` adds no persistent fields beyond inherited `ClanNameInputDialog` state; the relevant derived layout evidence is its packet-pointer constructor argument, allocation size `0x26c`, three vfptr views, raw/no-route constructor child, live inline construction sites, and primary submit slot override at `0x00615b34 -> 0x00489180`.
- 2026-06-20 B002/B009 ClanNameInputDialogCore source-quality incorporation:
  - Added counted CP_ACP prompt-decode detail, resource-index versus logical-control-id separation, shared `OnSubmitText(const wchar_t *)` slot resolution, OK-state slot polarity, and the clarification that `OnInputEvent` does not directly call the OK-state helper.
