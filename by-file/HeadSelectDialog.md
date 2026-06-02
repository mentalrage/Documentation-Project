*** UID:0000JT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# HeadSelectDialog

## Status

- Confidence: strong for `HeadSelectDialog` core behavior, medium for final owner of the shared category-switch helper.
- Proposed module: `ui/dialogs/HeadSelectDialog.cpp`
- Proposed header: `ui/dialogs/HeadSelectDialog.h`
- Current recovered source: `source-3/simroot_v2/class_HeadSelectDialog.cpp`
- Main address clusters: `0x00551030-0x005520e5`, destructor/thunk support at [UID:0001FL][0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks](by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md), and shared category helper [UID:00012T][0x0049dd00-0x0049dd17.DialogCategorySwitch](by-memory/0x0049dd00-0x0049dd17.DialogCategorySwitch.md)

## File Role

This module owns the in-game head/appearance selection dialog. It parses a server packet containing NPC/object/price/text data, creates a dialog background and control set, displays the current character/object preview, populates a paged 5 by 2 grid of selectable head previews, and updates the preview when the user changes pages or selects a head.

Keep this separate from [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md). Both areas use human/head-count image data, but `HeadSelectDialog` is a packet-driven in-game dialog with price/NPC fields and paged head buttons; the create-user dialogs own login/account character creation UI.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `HeadSelectDialog` | `0x00551030-0x005520e5`, [UID:0001FL][0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks](by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md) | Packet-driven head selection dialog, preview refresh, page navigation, button population, action handling, destructor support. |
| Dialog category switch helper | [UID:00012T][0x0049dd00-0x0049dd17.DialogCategorySwitch](by-memory/0x0049dd00-0x0049dd17.DialogCategorySwitch.md) | Currently emitted under `HeadSelectDialog`, but caller evidence crosses fitting-room and other dialog code; likely a generic dialog/control-list helper. |

## Function Map

| Range | Function | Notes |
| --- | --- | --- |
| `0x00551030-0x005511fd` | `RefreshHeadPreview` | Recomputes preview offsets for high/normal resolution, replaces the current [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md), deletes the old pane, and invalidates the dialog. |
| `0x00551200-0x0055124d` | `UpdatePageButtonStates` | Enables/disables previous/next page buttons from current page and head-count state. |
| `0x00551350-0x00551510` | `PopulateHeadButtons` | Optionally switches to category `7`, deletes old head buttons, creates up to ten [UID:00009N][ObjectImageButtonPane](by-class/ObjectImageButtonPane.md) entries, and highlights the selected head. |
| `0x00551520-0x00551f25` | `HeadSelectDialog::HeadSelectDialog` | Parses packet fields, configures high/normal layout tables, creates EPF background, image buttons, object preview, static text, and initial head page. |
| `0x00551f30-0x00551f91` | `~HeadSelectDialog` | Resets vtables and chains through dialog unregister/cleanup behavior. |
| `0x00551fa0-0x005520e5` | `OnAction` | Handles close, page previous/next, and head-slot selection actions, then refreshes preview/buttons. |
| `0x005538fe-0x00553914` | [UID:0001FL][0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks](by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md) | IDA-confirmed disabled companion thunks; one disabled generated body is missing. |
| `0x00553920-0x005539c3` | [UID:0001FL][0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks](by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md) | Deleting-destructor wrapper around `~HeadSelectDialog`. |

## Ownership Decision

Place the main class under `ui/dialogs/HeadSelectDialog.cpp`. It is a user-facing packet dialog rather than a generic image control, and it composes existing controls such as [UID:0000J2][EPFImageControlPane](by-file/EPFImageControlPane.md), [UID:00006D][ImageButtonControlPane](by-class/ImageButtonControlPane.md), [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md), and [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md).

Do not pull adjacent `0x00552110+` functions into this file by address locality. IDA decompilation shows `0x00552110` installs [UID:0000OL][TextDialog](by-file/TextDialog.md) vtables and `0x00553610` installs an anonymous [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md) vtable; those are adjacent dialog implementations, not `HeadSelectDialog` methods.

## Evidence Notes

- Wave3 metadata imports this class from `HeadSelectDialog.cpp`, reports grade `96.9`, and lists eight active methods plus two disabled thunks.
- IDA MCP confirms real function starts for all active methods and disabled thunks.
- IDA caller evidence shows the constructor at `0x00551520` is reached from a small allocation wrapper at `0x0054ca50`, which allocates `0x304` bytes before calling the constructor.
- `PopulateHeadButtons` and `OnAction` call `ObjectImageButtonPane` highlight/constructor paths, matching the paged grid interpretation; IDA confirms `SetButtonHighlight` callers at `0x0055149a`, `0x0055209a`, and `0x005520c3`.
- The constructor calls packet readers, `DialogPane` setup, EPF image control construction, image button construction, object-image preview construction, static text construction, and `NewHumanImageLib` head-count behavior.

## Current Caveats

- `0x0049dd00-0x0049dd17` is still emitted as `HeadSelectDialog::SwitchCategory`, but direct callers include fitting-room and other dialog code. Treat it as a shared dialog/control-list helper until final owner is resolved.
- 2026-05-24 recheck: current `class_HeadSelectDialog.cpp` starts with ASCII comment bytes and no longer shows visible mojibake before method install comments. Its autograder header still reports an `encoding BOM or mojibake artifact` penalty, so treat that as stale/noisy generated diagnostics rather than source text to preserve.
- 2026-05-25 recheck: disabled `class_HeadSelectDialog.cpp.disabled` still reports missing code for `0x00553909`, but IDA models it as an 11-byte `this -= 0xa4` adjustor thunk jumping to `0x00553920`; see the exact thunk page.
- The packet/dispatcher path around `0x0054ca50` is now documented as part of [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md).

## Cross-References

- [UID:000062][HeadSelectDialog](by-class/HeadSelectDialog.md)
- [UID:0001FI][0x00551030-0x005520e5.HeadSelectDialogCore](by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md)
- [UID:00012T][0x0049dd00-0x0049dd17.DialogCategorySwitch](by-memory/0x0049dd00-0x0049dd17.DialogCategorySwitch.md)
- [UID:0001FL][0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks](by-memory/0x005538fe-0x005539c3.HeadSelectDialogDestructorThunks.md)
- [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md)
- [UID:0000J2][EPFImageControlPane](by-file/EPFImageControlPane.md)
- [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md)
- [UID:0000O8][StaticTextControlPane](by-file/StaticTextControlPane.md)
- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:0000OL][TextDialog](by-file/TextDialog.md)
- [UID:0000LZ][NexonclubProxyDialog](by-file/NexonclubProxyDialog.md)
- [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md)

## Changes

- 2026-06-02: Set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/ui/dialogs/` so reviewed `HeadSelectDialog` data/memory pages can attach without projected-path errors.
  - Evidence: the page already proposes `ui/dialogs/HeadSelectDialog.cpp`, and its ownership decision keeps the class under packet-driven UI dialogs rather than create-user or generic image-control modules.
- Before: `HeadSelectDialog` core and `OnAction` ended at `0x005520e4`, and the `0x0054ca50` wrapper path was unnamed.
- Changed to: the core/action range ends at `0x005520e5`, and the `0x0054ca50` wrapper is part of the message-dialog dispatcher/wrapper island.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows the old endpoint omitted the final `retn 8` operand byte, and the wrapper at `0x0054ca50-0x0054caa9` allocates `0x304` bytes before calling the `HeadSelectDialog` constructor.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:80`.
  - Summary/evidence: core dialog behavior, function map, packet-driven preview/page/action handling, destructor support, wrapper path, and resource/control dependencies are documented; confidence is capped by the shared category-switch helper owner and generated-data caveats.
