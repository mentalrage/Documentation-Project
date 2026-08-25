*** UID:0000FM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "UserInfoDialogPane.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_LOGIN_USERINFODIALOGPANE_H
#define NEXUSTK_LOGIN_USERINFODIALOGPANE_H

#include "../ui/core/DialogPane.h"

class Event;

enum UserInfoControlId
{
    kUserInfoBackground = 0,
    kUserInfoOkButton = 1,
    kUserInfoCancelButton = 2,
    kUserInfoNameEdit = 3,
    kUserInfoResidentIdPrefixEdit = 4,
    kUserInfoResidentIdSuffixEdit = 5,
    kUserInfoParentNameEdit = 6,
    kUserInfoBloodTypeMenu = 7,
    kUserInfoResidenceMenu = 8,
    kUserInfoPrimaryAccessMethodMenu = 9,
    kUserInfoDiscoveryReasonMenu = 10
};

enum UserInfoValidationResult
{
    kUserInfoNameInvalid = 0,
    kUserInfoResidentIdPrefixInvalid = 1,
    kUserInfoResidentIdSuffixInvalid = 2,
    kUserInfoParentNameInvalid = 3,
    kUserInfoBloodTypeRequired = 4,
    kUserInfoResidenceRequired = 5,
    kUserInfoPrimaryAccessMethodRequired = 6,
    kUserInfoDiscoveryReasonRequired = 7,
    kUserInfoValidationSucceeded = 10
};

class UserInfoDialogPane : public DialogPane
{
public:
    explicit UserInfoDialogPane(const unsigned char *packet);

    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual void UpdateActionButton();

protected:
    virtual void SetHoverControl(int controlId);

private:
    UserInfoValidationResult ValidateInput();
    void SendUserInfo();
    wchar_t m_validationMessages[8][128];
};

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# UserInfoDialogPane

## Current Authority

The guarded H declaration and exact child-backed CPP route are current. Current authored names are `OnControlCommand`, `HandlePointerOrMouseEvent`, `HandleKeyOrTextEvent`, `SetHoverControl`, and `UpdateActionButton`. [UID:000575][0x00651b54-0x00651bdc.UserInfoDialogPaneRttiData](by-memory/0x00651b54-0x00651bdc.UserInfoDialogPaneRttiData.md) is the exact local RTTI child owner; [UID:00026T][0x0062e624-0x0062e8fc.UserInfoReadOnlyData](by-memory/0x0062e624-0x0062e8fc.UserInfoReadOnlyData.md) is only the vtable/literal split index and owns no aggregate RTTI, source, or literal emission. Older method spellings, broad-page blockers, and aggregate ownership statements below are historical where explicitly labeled.

## Status

- Confidence: current `95/94`; strong for exact class behavior, guarded declaration, authored-child source, boundaries, compiler-data ownership, validation/packet semantics, and current source-facing names. The cap is stripped private spelling plus constructor non-liveness, not a missing broad method-body block.
- Likely source file: [UID:0000OY][UserInfoDialogPane](by-file/UserInfoDialogPane.md)
- Historical recovered lead: `source-3/simroot_v2/class_UserInfoDialogPane.cpp`; current generated authority is validator-owned `auto-generated/NexusTK/login/UserInfoDialogPane.cpp` and `.h`.
- Address range: [UID:0001KG][0x00599cc0-0x0059bc8b.UserInfoDialogPane](by-memory/0x00599cc0-0x0059bc8b.UserInfoDialogPane.md)

## Class Purpose

`UserInfoDialogPane` is an account/user-information form dialog. It displays packet-supplied identity fields, requires several choice fields, validates name and resident-registration-number input, shows localized validation alerts, and sends the completed form back to the server.

## Historical Superseded Method Notes

The table below preserves pre-completion spellings and is not current naming authority. The exact child pages and accepted completion section use `OnControlCommand`, `HandlePointerOrMouseEvent`, `HandleKeyOrTextEvent`, `SetHoverControl`, and `UpdateActionButton`.

| Method | Address | Role |
| --- | --- | --- |
| `UserInfoDialogPane` | `0x00599cc0-0x0059aff0` | Builds the dialog, installs vtables, stores validation messages, decodes packet fields, fills controls `3..10`, and updates OK-button state. |
| `OnButtonCommand` | `0x0059b000-0x0059b0ed` | OK validates and sends; validation failure opens an alert and focuses the failing control; cancel closes the dialog. |
| `OnInputEvent` | `0x0059b0f0-0x0059b110` | Adjustor-style input forwarding with focus refresh. |
| `OnKeyEvent` | `0x0059b110-0x0059b130` | Adjustor-style key forwarding with focus refresh. |
| `OnFocusChanged` | `0x0059b130-0x0059b14a` | Updates hover/focus state and refreshes the dialog. |
| `UpdateOkButtonState` | `0x0059b150-0x0059b253` | Enables OK only when required text fields and choice controls are populated. |
| `ValidateInput` | `0x0059b260-0x0059b5b4` | Validates name/parent fields, numeric resident-registration fields, checksum digit, and required selections; returns `10` for success. |
| `SendUserInfo` | `0x0059b5c0-0x0059bc2c` | Serializes four text fields and four selected option labels into packet `0x53` subtype `1`. |
| Adjustor thunks | [UID:0001KH][0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks](by-memory/0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks.md) | Compiler thunks into the deleting destructor; excluded through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| `ScalarDeletingDestructor` | `0x0059bc50-0x0059bc8b` | Tears down dialog state and conditionally frees memory. |

## Data Notes

- Controls `3..6` are text fields decoded from packet data and made read-only in the generated view: `m_nameEdit`, `m_residentIdPrefixEdit`, `m_residentIdSuffixEdit`, and `m_parentNameEdit`.
- Controls `7..10` are choice controls for the remaining user-information categories: `m_bloodTypeCombo`, `m_residenceCombo`, `m_primaryAccessMethodCombo`, and `m_discoveryReasonCombo`.
- Inherited [UID:0001U4][DialogPaneLayout](by-type/by-struct/DialogPaneLayout.md) supplies the child-control lookup field as `DialogPane::m_controlManager` at `+0x1fc` / decimal `508`, superseding older `m_controlHost` / `m_controls` wording. It is not a UserInfo-local field.
- Validation error indexes `0..7` map to the stored message table and focus control `error + 3`; success is `10`.
- [UID:00026T][0x0062e624-0x0062e8fc.UserInfoReadOnlyData](by-memory/0x0062e624-0x0062e8fc.UserInfoReadOnlyData.md) is a non-emitting split index over exact vtable child [UID:000573][0x0062e624-0x0062e6c0.UserInfoDialogPaneVtableData](by-memory/0x0062e624-0x0062e6c0.UserInfoDialogPaneVtableData.md) and exact source-literal child [UID:000574][0x0062e6c0-0x0062e8fc.UserInfoDialogPaneLiteralData](by-memory/0x0062e6c0-0x0062e8fc.UserInfoDialogPaneLiteralData.md). Separate [UID:000575][0x00651b54-0x00651bdc.UserInfoDialogPaneRttiData](by-memory/0x00651b54-0x00651bdc.UserInfoDialogPaneRttiData.md) owns the exact local RTTI graph. The successor `UserListDialogPane` primary COL begins at `0x0062e8fc`; no UserInfo ownership extends into that tail.
- The validation-message storage is the constructor-copied table at `this+0x26c`, modeled as `m_validationMessages[8][128]`. `OnControlCommand` indexes it by validation result and focuses control `error + 3`, tying validation results `0..7` directly to controls `3..10`.
- Preferred field/control names after the B004 2026-06-23 MCP-backed recheck are `m_nameEdit`, `m_residentIdPrefixEdit`, `m_residentIdSuffixEdit`, `m_parentNameEdit`, `m_bloodTypeCombo`, `m_residenceCombo`, `m_primaryAccessMethodCombo`, `m_discoveryReasonCombo`, and `m_validationMessages[8][128]`. `m_regionCombo` and `m_referralSourceCombo` remain historical/secondary prose only.
- Treat `ERINFO.EPF`, `aUs_1`, `off_62E7EC`, `aCd`, and `off_62E8F0` as IDA/data-definition artifacts. The source literals are the full `USERINFO.EPF` asset name and the full localized option strings documented on [UID:00026T][0x0062e624-0x0062e8fc.UserInfoReadOnlyData](by-memory/0x0062e624-0x0062e8fc.UserInfoReadOnlyData.md).
- Helper roles are resolved and incorporated by the exact authored child bodies: `sub_498C10` is the text-control get/copy text helper, `sub_498C60` is the text-control empty check, `sub_4981A0` is the choice selected-index getter, `sub_498180` is the choice item getter, `sub_498220` is the selected-index setter, and `sub_517070` is the bounded selected-label copy helper. The historical aggregate support-API blocker no longer limits formal child C++.
- `SendUserInfo` serializes fields in source order as name, resident-id prefix, resident-id suffix, parent name, blood type label, residence label, primary access method label, and discovery reason label, then sends opcode `0x53` / decimal `83` / ASCII `S` subtype `1` through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md).

## Evidence Notes

- IDA MCP confirms all listed starts and sizes.
- 2026-06-23 B004 MCP-backed recheck used endpoint `http://127.0.0.1:13337/mcp`, database session `80de0a67`, active `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, executable input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, and SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`. It reconfirmed the target range hash `6d7ee091250689b5545a601de50e4ed202deef8f5b65363243412a2aed9902e2`, range size `0x1fcb` / decimal `8139`, and function inventory from constructor `0x00599cc0-0x0059aff0` through scalar deleting destructor `0x0059bc50-0x0059bc8b`.
- The dated 2026-06-23 MCP/PE pass found zero constructor xrefs/transfers/pointer materializations and positive controls for `0x0059b058 -> ValidateInput`, `0x0059b066 -> SendUserInfo`, vtable dword `0x0062e670 ->` the function now named `OnControlCommand`, and destructor/vtable routes to `0x0059bc50`. The accepted exhaustive pass classifies the constructor as unreachable/dead; no factory route is inferred.
- The adjacent `0x0059bc90` function belongs to [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md), not this class.
- IDA confirms `0x0059bc2d` and `0x0059bc38` as real 0xb adjustor thunks into `0x0059bc50`; the decompiler's temporary `boost::exception` type on `0x0059bc2d` is type pollution.
- 2026-05-26 IDA recheck confirms `0x0059bc2d` and `0x0059bc38` forward to `0x0059bc50` after `this - 0xa0` and `this - 0xa4`; both are tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).

## Cross-References

- [UID:0000OY][UserInfoDialogPane](by-file/UserInfoDialogPane.md)
- [UID:0001KG][0x00599cc0-0x0059bc8b.UserInfoDialogPane](by-memory/0x00599cc0-0x0059bc8b.UserInfoDialogPane.md)
- [UID:0001KH][0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks](by-memory/0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks.md)
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)

## Changes

This section is dated chronology only. Its older method names, scores, aggregate source/RTTI ownership, and broad method-body blockers are superseded by `Current Authority` and the accepted class/header completion below.

- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000OY][UserInfoDialogPane](by-file/UserInfoDialogPane.md).
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the documented constructor, command/input/key/focus handlers, OK-state updater, validation method, packet sender, adjustor thunks, and scalar deleting destructor at `0x00599cc0`, `0x0059b000`, `0x0059b0f0`, `0x0059b110`, `0x0059b130`, `0x0059b150`, `0x0059b260`, `0x0059b5c0`, `0x0059bc2d`, `0x0059bc38`, and `0x0059bc50`; this page and parent [UID:0000OY][UserInfoDialogPane](by-file/UserInfoDialogPane.md) both meet the parent gate. The old `95/95` code-bar note is superseded by the active code-entry rule and the [UID:0001KG][0x00599cc0-0x0059bc8b.UserInfoDialogPane](by-memory/0x00599cc0-0x0059bc8b.UserInfoDialogPane.md) broad-target no-code proof.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:86`.
  - Summary/evidence: scored from the detailed constructor, validation, OK-state, packet serialization, event/focus forwarding, data notes, adjustor thunks, and adjacent-boundary evidence; confidence remains slightly capped by unresolved launch path.
- 2026-06-21 B007 Rule 26 source-quality incorporation:
  - Added first-draft class/control/validation declarations and support notes for the corrected [UID:00026T][0x0062e624-0x0062e8fc.UserInfoReadOnlyData](by-memory/0x0062e624-0x0062e8fc.UserInfoReadOnlyData.md) boundary, decoded resource/option ownership, helper-name recommendations, validation-message storage, and rejected IDA substring artifacts.
  - Historical remaining limits superseded by B004: the constructor route remains absent after bounded MCP and PE checks; helper API/callback support signatures remain a method-body C++ cap; private/control names are now documented as `m_controlManager`, `m_nameEdit`, `m_residentIdPrefixEdit`, `m_residentIdSuffixEdit`, `m_parentNameEdit`, `m_bloodTypeCombo`, `m_residenceCombo`, `m_primaryAccessMethodCombo`, and `m_discoveryReasonCombo`.
- 2026-06-23 B004 MCP-backed source-quality implementation:
  - Before: `88/86`, with older support wording treating `m_controlHost` / `m_controls`, residence/referral alternates, and generic field/helper uncertainty as active blockers.
  - Changed to: `90/88`; owner/emitter [UID:0000OY][UserInfoDialogPane](by-file/UserInfoDialogPane.md) unchanged and the existing formal class declaration preserved.
  - Summary/evidence: incorporated session `80de0a67` function/xref/route-scan evidence, inherited `DialogPane::m_controlManager`, preferred control/validation/message/packet names, no direct constructor route proof with positive controls, rejected generated labels and owner alternatives, and the accepted rule that [UID:0001KG][0x00599cc0-0x0059bc8b.UserInfoDialogPane](by-memory/0x00599cc0-0x0059bc8b.UserInfoDialogPane.md) keeps method-body C++ blank under its broad-island no-code proof.

## 2026-08-24 UID0000OY Class And Header Completion

The formal declaration now lives only in `UserInfoDialogPane.h`; the CPP channel includes that self-header and expands exact source children. The current DialogPane virtual contract replaces stale `OnButtonCommand`, `OnInputEvent`, `OnKeyEvent`, `OnFocusChanged`, and `UpdateOkButtonState` spellings with `OnControlCommand`, `HandlePointerOrMouseEvent`, `HandleKeyOrTextEvent`, `SetHoverControl`, and `UpdateActionButton`.

| Method/compiler item | Exact documentation | Class disposition |
| --- | --- | --- |
| Constructor | [UID:00056U][0x00599cc0-0x0059aff0.UserInfoDialogPaneConstructor](by-memory/0x00599cc0-0x0059aff0.UserInfoDialogPaneConstructor.md) | Authored, retained but unreachable; complete source. |
| OnControlCommand | [UID:00056V][0x0059b000-0x0059b0ed.UserInfoDialogPaneOnControlCommand](by-memory/0x0059b000-0x0059b0ed.UserInfoDialogPaneOnControlCommand.md) | Primary `+0x48` override. |
| Event callbacks | [UID:00056W][0x0059b0f0-0x0059b110.UserInfoDialogPaneHandlePointerOrMouseEvent](by-memory/0x0059b0f0-0x0059b110.UserInfoDialogPaneHandlePointerOrMouseEvent.md), [UID:00056X][0x0059b110-0x0059b130.UserInfoDialogPaneHandleKeyOrTextEvent](by-memory/0x0059b110-0x0059b130.UserInfoDialogPaneHandleKeyOrTextEvent.md) | Source overrides received through the `+0xa0` EventHandler view. |
| Hover/action | [UID:00056Y][0x0059b130-0x0059b14a.UserInfoDialogPaneSetHoverControl](by-memory/0x0059b130-0x0059b14a.UserInfoDialogPaneSetHoverControl.md), [UID:00056Z][0x0059b150-0x0059b253.UserInfoDialogPaneUpdateActionButton](by-memory/0x0059b150-0x0059b253.UserInfoDialogPaneUpdateActionButton.md) | Primary `+0x58/+0x4c` overrides. |
| Private helpers | [UID:000570][0x0059b260-0x0059b5b4.UserInfoDialogPaneValidateInput](by-memory/0x0059b260-0x0059b5b4.UserInfoDialogPaneValidateInput.md), [UID:000571][0x0059b5c0-0x0059bc2c.UserInfoDialogPaneSendUserInfo](by-memory/0x0059b5c0-0x0059bc2c.UserInfoDialogPaneSendUserInfo.md) | Nonvirtual authored methods. |
| Destruction | [UID:0001KH][0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks](by-memory/0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks.md), [UID:000572][0x0059bc50-0x0059bc8b.UserInfoDialogPaneScalarDeletingDestructor](by-memory/0x0059bc50-0x0059bc8b.UserInfoDialogPaneScalarDeletingDestructor.md) | Compiler output; implicit source destruction only. |
| ABI data | [UID:000573][0x0062e624-0x0062e6c0.UserInfoDialogPaneVtableData](by-memory/0x0062e624-0x0062e6c0.UserInfoDialogPaneVtableData.md), [UID:000575][0x00651b54-0x00651bdc.UserInfoDialogPaneRttiData](by-memory/0x00651b54-0x00651bdc.UserInfoDialogPaneRttiData.md) | Three vtable views at complete offsets `0/+0xa0/+0xa4`; seven-base RTTI graph; no raw source. |
| Literals | [UID:000574][0x0062e6c0-0x0062e8fc.UserInfoDialogPaneLiteralData](by-memory/0x0062e6c0-0x0062e8fc.UserInfoDialogPaneLiteralData.md) | Source-authored translation-unit-local literals/helpers. |

Inherited `DialogPane` contributes the complete `0x26c` prefix, including control-manager storage. No `m_nameEdit`, resident edit, parent edit, or popup pointer member is justified. The only derived field is `m_validationMessages[8][128]` at `+0x26c`, occupying `0x800` bytes and yielding exact `sizeof(UserInfoDialogPane)==0xa6c`. The scalar wrapper's guarded `0xa6c` delete independently confirms the size. No ordinary destructor cleanup exists because the tail is a plain wchar array.

The RTTI hierarchy is UserInfoDialogPane -> DialogPane -> Pane with primary GrafPort/LObject chain, EventHandler at `+0xa0`, and TimerHandler at `+0xa4`. [UID:000575][0x00651b54-0x00651bdc.UserInfoDialogPaneRttiData](by-memory/0x00651b54-0x00651bdc.UserInfoDialogPaneRttiData.md) owns only the local three COLs, CHD, seven-entry base array, self BCD, and zero pad. Its graph reaches the noncontiguous self TypeDescriptor `[0x00679a74,0x00679a98)` and external DialogPane/Pane/GrafPort/LObject/EventHandler/TimerHandler BCDs without transferring ownership.

Completion/confidence is `95/94`, based on exact layout, method inventory, virtual slots, header/source routing, data/compiler children, destruction, and dependency graph. Stripped original private spellings and constructor liveness cap confidence below final certainty.
