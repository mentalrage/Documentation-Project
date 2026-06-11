*** UID:0000FM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# UserInfoDialogPane

## Status

- Confidence: strong for local behavior and boundaries.
- Likely source file: [UID:0000OY][UserInfoDialogPane](by-file/UserInfoDialogPane.md)
- Current recovered file: `source-3/simroot_v2/class_UserInfoDialogPane.cpp`
- Address range: [UID:0001KG][0x00599cc0-0x0059bc8b.UserInfoDialogPane](by-memory/0x00599cc0-0x0059bc8b.UserInfoDialogPane.md)

## Class Purpose

`UserInfoDialogPane` is an account/user-information form dialog. It displays packet-supplied identity fields, requires several choice fields, validates name and resident-registration-number input, shows localized validation alerts, and sends the completed form back to the server.

## Method Notes

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

- Controls `3..6` are text fields decoded from packet data and made read-only in the generated view.
- Controls `7..10` are choice controls for the remaining user-information categories.
- Validation error indexes `0..7` map to the stored message table; success is `10`.

## Evidence Notes

- IDA MCP confirms all listed starts and sizes.
- The constructor currently has no direct IDA code xrefs, so the launch path remains unresolved.
- The adjacent `0x0059bc90` function belongs to [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md), not this class.
- IDA confirms `0x0059bc2d` and `0x0059bc38` as real 0xb adjustor thunks into `0x0059bc50`; the decompiler's temporary `boost::exception` type on `0x0059bc2d` is type pollution.
- 2026-05-26 IDA recheck confirms `0x0059bc2d` and `0x0059bc38` forward to `0x0059bc50` after `this - 0xa0` and `this - 0xa4`; both are tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).

## Cross-References

- [UID:0000OY][UserInfoDialogPane](by-file/UserInfoDialogPane.md)
- [UID:0001KG][0x00599cc0-0x0059bc8b.UserInfoDialogPane](by-memory/0x00599cc0-0x0059bc8b.UserInfoDialogPane.md)
- [UID:0001KH][0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks](by-memory/0x0059bc2d-0x0059bc43.UserInfoDialogPaneAdjustorThunks.md)
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)

## Changes

- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000OY][UserInfoDialogPane](by-file/UserInfoDialogPane.md).
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the documented constructor, command/input/key/focus handlers, OK-state updater, validation method, packet sender, adjustor thunks, and scalar deleting destructor at `0x00599cc0`, `0x0059b000`, `0x0059b0f0`, `0x0059b110`, `0x0059b130`, `0x0059b150`, `0x0059b260`, `0x0059b5c0`, `0x0059bc2d`, `0x0059bc38`, and `0x0059bc50`; this page and parent [UID:0000OY][UserInfoDialogPane](by-file/UserInfoDialogPane.md) both meet the 80/80 parent gate. No C++ was emitted because the page is below the 95/95 reconstruction-code bar.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:86`.
  - Summary/evidence: scored from the detailed constructor, validation, OK-state, packet serialization, event/focus forwarding, data notes, adjustor thunks, and adjacent-boundary evidence; confidence remains slightly capped by unresolved launch path.
