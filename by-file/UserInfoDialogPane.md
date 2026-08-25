*** UID:0000OY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# UserInfoDialogPane

## Current Authority

The 2026-08-24 accepted whole-file completion below is the current authority. The constructor is retained source but unreachable/dead in this executable, so the older likely-indirect/factory construction hypothesis is rejected. The exact authored children now supply all eight method bodies, the literal child supplies the file-local source block, and the broad executable/read-only parents are final non-emitting split indexes rather than attached source-bearing emitters. Earlier source-construction, method-body blocker, score, and generated-lead statements remain only as dated history where explicitly identified below.

## Status

- Confidence: `95/94`; strong for class behavior, source grouping, exact child partition, vtable/literal/RTTI ownership, executable/read-only boundaries, validation/packet semantics, and current source-facing control names. The remaining cap is the proved constructor non-liveness plus inferred private/original file spellings, not an unresolved factory route or broad-page method-body blocker.
- Proposed module: `login/UserInfoDialogPane.cpp`
- Historical recovered lead: `source-3/simroot_v2/class_UserInfoDialogPane.cpp`; current authority is the accepted ordinary documentation and validator-owned generated `auto-generated/NexusTK/login/UserInfoDialogPane.cpp` plus sibling H.
- Main class: [UID:0000FM][UserInfoDialogPane](by-class/UserInfoDialogPane.md)
- Main address doc: [UID:0001KG][0x00599cc0-0x0059bc8b.UserInfoDialogPane](by-memory/0x00599cc0-0x0059bc8b.UserInfoDialogPane.md)
- Support thunk doc: [UID:0001KH][0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks](by-memory/0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks.md), tracked in [UID:0000VN][-ignored](by-memory/-ignored.md)

## File Role

`UserInfoDialogPane.cpp` owns a Korean account/user-information form dialog. The constructor decodes packet-provided fields into read-only text controls, fills optional choice controls, validates the final user-entered selections, and sends packet `0x53` subtype `1` with the completed form data.

This should stay near login/account UI code rather than generic in-game dialogs. The form handles account identity fields, resident-registration-number checksum validation, parent-name validation, and demographic/preference selections.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `UserInfoDialogPane` | `0x00599cc0-0x0059bc8b`, thunks [UID:0001KH][0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks](by-memory/0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks.md) | Dialog construction, focus/input forwarding, validation, packet send, close/cancel handling, and destructor thunks. |
| `g_alertPaneButtonLayout` dependency | generated global in `class_UserInfoDialogPane.cpp` | Alert button layout consumed when validation fails; not owned by this file. |

## Evidence Notes

- IDA MCP confirms real functions at `0x00599cc0`, `0x0059b000`, `0x0059b0f0`, `0x0059b110`, `0x0059b130`, `0x0059b150`, `0x0059b260`, `0x0059b5c0`, `0x0059bc2d`, `0x0059bc38`, and `0x0059bc50`.
- 2026-06-23 B004 MCP-backed recheck used endpoint `http://127.0.0.1:13337/mcp`, database session `80de0a67`, active `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, executable input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, and PE SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`. The target bytes for `0x00599cc0-0x0059bc8b` hash to `6d7ee091250689b5545a601de50e4ed202deef8f5b65363243412a2aed9902e2`, size `0x1fcb` / decimal `8139`.
- IDA confirms the next large function starts at `0x0059bc90`, which belongs to the existing [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md) range, so the user-info dialog boundary ends at `0x0059bc8b`.
- Historical superseded construction hypothesis: the absence of direct xrefs was once treated as possible packet/dialog-factory construction. The accepted exhaustive route scan instead classifies the retained constructor as unreachable/dead; no indirect/factory liveness is claimed.
- 2026-06-02 raw IDA export and IDA MCP recheck agree on exact function sizes: constructor `0x1330`, command handler `0xed`, input/key forwarders `0x20` each, focus handler `0x1a`, OK-state updater `0x103`, validation helper `0x354`, packet sender `0x66c`, two `0xb` adjustor thunks, and scalar deleting destructor `0x3b`.
- 2026-06-02 byte checks confirm `0xcc` alignment around the executable island, including the preceding `0x00599cb3-0x00599cc0` and following `0x0059bc8b-0x0059bc90` gaps already tracked in [UID:0000VN][-ignored](by-memory/-ignored.md), plus intra-island alignment between the methods.
- [UID:00026T][0x0062e624-0x0062e8fc.UserInfoReadOnlyData](by-memory/0x0062e624-0x0062e8fc.UserInfoReadOnlyData.md) documents the matching `UserInfoDialogPane` vtables, title string, validation messages, `USERINFO.EPF`, blood-type/residence/access-method/discovery option lists, and the corrected boundary before `UserListDialogPane` at `0x0062e8fc`.
- 2026-06-14 live session-aware IDA MCP recheck (`NexusTK.exe.i64`, auto-analysis and Hex-Rays ready) reconfirmed all method starts/sizes and the adjacent boundary: constructor `0x00599cc0` size `0x1330`, command handler `0x0059b000` size `0xed`, OK-state updater `0x0059b150` size `0x103`, validation helper `0x0059b260` size `0x354`, packet sender `0x0059b5c0` size `0x66c`, scalar deleting destructor `0x0059bc50` size `0x3b`, no function at `0x0059bc8b`, and `UserListDialogPane` successor function `0x0059bc90` size `0x1508`.
- 2026-06-14 `analyze_component` confirms the internal class flow: the command handler calls only the validation helper at `0x0059b058` and the packet sender at `0x0059b066` among this component's substantial methods; the constructor, OK-state updater, validation helper, packet sender, and destructor remain internally grouped with no conflicting owner evidence.
- 2026-06-14 `xref_query` still reports no inbound xrefs to constructor `0x00599cc0`; an `insn_query` sweep over the documented main-menu/login/account range `0x004f6700-0x004fb62a` also found no operand reference to `0x00599cc0`. This preserves the launch-path caveat while strengthening the conclusion that the missing caller is not a simple direct menu constructor call in that login island.
- 2026-06-23 B004 local PE route scan found zero `E8`, `E9`, or near-conditional branch transfers to constructor `0x00599cc0`, and zero little-endian dword hits for constructor VA `0x00599cc0`, RVA `0x00199cc0`, or raw offset `0x00199280`. Positive controls in the same scan hit `0x0059b058 -> 0x0059b260`, `0x0059b066 -> 0x0059b5c0`, the `.rdata` vtable dword for `0x0059b000` at `0x0062e670`, and destructor/vtable routes for `0x0059bc50`.
- 2026-06-14 vtable xrefs tie the read-only data to the constructor: `0x0062e628`, `0x0062e688`, and `0x0062e6b8` are referenced from `0x00599d20`, `0x00599d26`, and `0x00599d30` inside the constructor; `0x0062e670` has no direct xref in the current IDB.
- 2026-06-14 byte checks reconfirmed the leading `0x00599cb3-0x00599cc0` alignment, full `0x0059aff0-0x0059b000` internal alignment, adjustor thunk bytes after `0x0059bc2c`, following `0x0059bc8b-0x0059bc90` padding, and the `0x0062e624` read-only vtable lead-in.

## Ownership Notes

- Use `login/UserInfoDialogPane.cpp` as the current source-layout hypothesis.
- Do not merge this with [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md) just because the next address block is adjacent; the behavior and controls are account-form specific.
- Disabled generated output omits code for the real `0x0059bc2d` adjustor thunk. The thunk exists in IDA, is documented at [UID:0001KH][0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks](by-memory/0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks.md), and is excluded from source reconstruction through [UID:0000VN][-ignored](by-memory/-ignored.md).
- 2026-05-26 IDA MCP recheck confirms `0x0059bc2d` and `0x0059bc38` as `this - 0xa0` / `this - 0xa4` destructor wrappers into `0x0059bc50`. Keep the scalar deleting destructor reconstructable.
- Historical superseded attachment state: the broad executable range was formerly described as attached for autogen ownership with method-body C++ withheld. It is now [UID:0001KG][0x00599cc0-0x0059bc8b.UserInfoDialogPane](by-memory/0x00599cc0-0x0059bc8b.UserInfoDialogPane.md), a final `RECONSTRUCTABLE:FALSE` non-emitting split index; exact authored children emit through the class/file route.
- Current source-quality authority: [UID:0000FM][UserInfoDialogPane](by-class/UserInfoDialogPane.md) owns the guarded H declaration and CPP self-header root, [UID:000574][0x0062e6c0-0x0062e8fc.UserInfoDialogPaneLiteralData](by-memory/0x0062e6c0-0x0062e8fc.UserInfoDialogPaneLiteralData.md) emits source literals/helpers at position 5, and UID00056U-UID000571 emit the eight authored definitions at positions 10-80. The accepted names are `DialogPane::m_controlManager`, `m_nameEdit`, `m_residentIdPrefixEdit`, `m_residentIdSuffixEdit`, `m_parentNameEdit`, `m_bloodTypeCombo`, `m_residenceCombo`, `m_primaryAccessMethodCombo`, `m_discoveryReasonCombo`, and `m_validationMessages[8][128]`; `m_controlHost` / `m_controls`, `m_regionCombo`, and `m_referralSourceCombo` are historical/secondary wording only.
- Historical superseded no-code rationale: the former broad-island/future-child/support-signature blocker explained why aggregate CPP was blank before the exact split. It is not a current blocker: aggregate CPP remains blank because duplicate emission is forbidden, while the exact child CPP and complete H are current and accepted.
- Keep `UserInfoDialogPane.cpp` separate from [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md): the UserInfo read-only data ends at `0x0062e8fc`, where the `UserListDialogPane` primary complete-object locator and primary vtable lead-in begin.

## Cross-References

- [UID:0000FM][UserInfoDialogPane](by-class/UserInfoDialogPane.md)
- [UID:0001KG][0x00599cc0-0x0059bc8b.UserInfoDialogPane](by-memory/0x00599cc0-0x0059bc8b.UserInfoDialogPane.md)
- [UID:0001KH][0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks](by-memory/0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks.md)
- [UID:00026T][0x0062e624-0x0062e8fc.UserInfoReadOnlyData](by-memory/0x0062e624-0x0062e8fc.UserInfoReadOnlyData.md)
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)

## Changes

This section is dated chronology only. Any construction, source-bearing, method-body blocker, score, or generated-lead statement here is superseded by `Current Authority` and the accepted completion section below.

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `84/78`. Summary/evidence: the page captures the account/user-info source role, likely contents, IDA-backed field/widget/resource evidence, boundaries, and unresolved launch-path caveat.
- 2026-06-02 source-placement and scoring update:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the page stayed at `84/78`, below the file-parent attachment confidence threshold.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/"`, `COMPLETION:86`, and `CONFIDENCE:82`.
  - Summary/evidence: IDA MCP/raw export rechecked exact function sizes, vtable refs, alignment bytes, adjacent boundaries, and matching read-only data, while preserving the unresolved indirect launch-path caveat.
- 2026-06-14 C001 Goal 2 refresh:
  - Before: `86/82`, with source placement and core behavior documented but confidence still based on older IDA evidence.
  - Changed to: `88/86`; projected path and file ownership unchanged.
  - Summary/evidence: live session-aware IDA MCP reconfirmed method sizes, internal validation/send call flow, constructor vtable stores into [UID:00026T][0x0062e624-0x0062e8fc.UserInfoReadOnlyData](by-memory/0x0062e624-0x0062e8fc.UserInfoReadOnlyData.md), adjacent `UserListDialogPane` boundary, alignment bytes, and the continuing absence of a direct constructor xref in the main login/account range. The old source-visible-name wording is superseded by the 2026-06-23 B004 source-quality pass.
- 2026-06-21 B007 Rule 26 source-quality incorporation:
  - Added the corrected UserInfo/UserList `.rdata` boundary, decoded literal/resource ownership, helper-name recommendations, and code-emission split: declaration/resource data can emit from the UserInfo docs. The later 2026-06-23 B004 pass supersedes the generic field/factory blocker wording with a no-direct-constructor-route proof, resolved field/control names, and the broad-target blank-C++ proof.
- 2026-06-23 B004 MCP-backed source-quality implementation:
  - Before: `88/86`, with older current-code-entry wording that still described field/helper names and constructor launch path as broad final-source blockers.
  - Changed to: `90/88`; proposed reconstruction path and file ownership unchanged.
  - Summary/evidence: incorporated current session `80de0a67`, executable/range hash provenance, no-direct-constructor-route MCP and PE evidence, positive route controls, `DialogPane::m_controlManager` replacement for `m_controlHost` / `m_controls`, preferred control/packet-field names, generated-output caveat, UserList boundary rejection, Login/CreateUser/Socket/no-owner alternative rejection, and the broad-target blank-C++ proof.

## 2026-08-24 UID0000OY Accepted Whole-File Completion

The accepted whole-file callback establishes this page as the singular `NexusTK/login/UserInfoDialogPane.cpp` root with sibling `UserInfoDialogPane.h`. The complete executable inventory is exactly eleven functions: eight source-authored bodies, two compiler this-adjustor thunks, and one compiler scalar deleting wrapper. Source-authored read-only data is separated from compiler vtable/RTTI data. No writable file-owned global or static exists; [UID:0000Q5][g_packetSender](by-global/g_packetSender.md), `g_mainUiLayerSlots`, and `g_pBackPane` remain external dependencies.

| Order | Exact child | Source disposition |
| ---: | --- | --- |
| 5 | [UID:000574][0x0062e6c0-0x0062e8fc.UserInfoDialogPaneLiteralData](by-memory/0x0062e6c0-0x0062e8fc.UserInfoDialogPaneLiteralData.md) | File-local title, seven unique validation literals filling eight entries, `USERINFO.EPF`, 4/14/4/6 menu labels, includes, and inline ACP/menu helpers. |
| 10 | [UID:00056U][0x00599cc0-0x0059aff0.UserInfoDialogPaneConstructor](by-memory/0x00599cc0-0x0059aff0.UserInfoDialogPaneConstructor.md) | Complete retained source constructor; subtype-2 eight-field ACP decode and controls 0-10. |
| 20 | [UID:00056V][0x0059b000-0x0059b0ed.UserInfoDialogPaneOnControlCommand](by-memory/0x0059b000-0x0059b0ed.UserInfoDialogPaneOnControlCommand.md) | OK/cancel callback, validation/send/alert/focus flow. |
| 30 | [UID:00056W][0x0059b0f0-0x0059b110.UserInfoDialogPaneHandlePointerOrMouseEvent](by-memory/0x0059b0f0-0x0059b110.UserInfoDialogPaneHandlePointerOrMouseEvent.md) | Pointer/mouse refresh then base forward. |
| 40 | [UID:00056X][0x0059b110-0x0059b130.UserInfoDialogPaneHandleKeyOrTextEvent](by-memory/0x0059b110-0x0059b130.UserInfoDialogPaneHandleKeyOrTextEvent.md) | Key/text refresh then base forward. |
| 50 | [UID:00056Y][0x0059b130-0x0059b14a.UserInfoDialogPaneSetHoverControl](by-memory/0x0059b130-0x0059b14a.UserInfoDialogPaneSetHoverControl.md) | Base hover then dynamic UpdateActionButton. |
| 60 | [UID:00056Z][0x0059b150-0x0059b253.UserInfoDialogPaneUpdateActionButton](by-memory/0x0059b150-0x0059b253.UserInfoDialogPaneUpdateActionButton.md) | Requires text 3-6 and menus 7-9; menu 10 omission is intentional. |
| 70 | [UID:000570][0x0059b260-0x0059b5b4.UserInfoDialogPaneValidateInput](by-memory/0x0059b260-0x0059b5b4.UserInfoDialogPaneValidateInput.md) | Digit/checksum/menu validation, results 0-7/10, and unsafe `suffix[6]` read preserved. |
| 80 | [UID:000571][0x0059b5c0-0x0059bc2c.UserInfoDialogPaneSendUserInfo](by-memory/0x0059b5c0-0x0059bc2c.UserInfoDialogPaneSendUserInfo.md) | Packet `0x53/1`, four text plus four menu ACP fields, BE payload length, full-length queue. |
| compiler | [UID:0001KH][0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks](by-memory/0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks.md), [UID:000572][0x0059bc50-0x0059bc8b.UserInfoDialogPaneScalarDeletingDestructor](by-memory/0x0059bc50-0x0059bc8b.UserInfoDialogPaneScalarDeletingDestructor.md) | Two `this-0xa0/this-0xa4` tails and scalar deleting wrapper; no handwritten source. |
| compiler | [UID:000573][0x0062e624-0x0062e6c0.UserInfoDialogPaneVtableData](by-memory/0x0062e624-0x0062e6c0.UserInfoDialogPaneVtableData.md), [UID:000575][0x00651b54-0x00651bdc.UserInfoDialogPaneRttiData](by-memory/0x00651b54-0x00651bdc.UserInfoDialogPaneRttiData.md) | Exact 23/11/2-slot vtables and seven-base RTTI graph; compiler-generated from the guarded class declaration. |

The constructor is source-authored but unreachable/dead in this executable: current evidence found zero IDA xrefs, direct transfer hits, or VA/RVA/raw-offset materializations, while positive controls found all internal method routes, vtable cells/stores, and four direct callers for the adjacent UserList constructor. Do not revive the old likely-indirect/factory claim. UserList begins separately at executable `0x0059bc90` and read-only data `0x0062e8fc`; adjacency transfers no ownership.

Controls 0-10 live in inherited `DialogPane::m_controlManager`, not UserInfo-local pointer fields. The only derived storage is `wchar_t m_validationMessages[8][128]` at `+0x26c`; exact object size is `0xa6c`. No explicit destructor is source-required. Current virtual names are `OnControlCommand`, `HandlePointerOrMouseEvent`, `HandleKeyOrTextEvent`, `SetHoverControl`, and `UpdateActionButton`.

Each exact function page carries its complete F01-F11 body-scoped call inventory; [UID:000573][0x0062e624-0x0062e6c0.UserInfoDialogPaneVtableData](by-memory/0x0062e624-0x0062e6c0.UserInfoDialogPaneVtableData.md) carries V01-V36 cell/value/TInfo/comment/xref/source dispositions; [UID:000575][0x00651b54-0x00651bdc.UserInfoDialogPaneRttiData](by-memory/0x00651b54-0x00651bdc.UserInfoDialogPaneRttiData.md) carries PR01-PR20 local/external RTTI records and protections. The class page owns the guarded H declaration and CPP self-header/`[[CHILDREN]]` root. Generated output must therefore contain all eight authored definitions in positions 10-80, literal/helper source at 5, one class declaration in the sibling H, no duplicate broad emission, and no empty-emitter marker.

Completion/confidence is `95/94`: the whole file, source/data/compiler partitions, behavior, boundaries, calls, xrefs, layouts, resources, literal groups, source order, rejected owners, and formal CPP/H routes are closed. Confidence remains capped by stripped private spellings, inferred original file spelling, and the real constructor non-liveness.
