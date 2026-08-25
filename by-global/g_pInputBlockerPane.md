*** UID:0003EE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class InputBlockerPane;

InputBlockerPane *g_pInputBlockerPane = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pInputBlockerPane

## UID0003ZT UserPane Header Declaration And MapPane Consumer - 2026-07-23

- This page remains the sole `InputBlockerPane *g_pInputBlockerPane` definition under [UID:0000P1][UserPane](by-file/UserPane.md); its `87/90` score, owner/emitter, exact storage, lifecycle, and xref evidence are unchanged.
- Inferred same-basename `NexusTK/ui/panels/UserPane.h` forward-declares InputBlockerPane and exports `extern InputBlockerPane *g_pInputBlockerPane;`. UserPane.cpp emits the one definition shown in the managed formal.
- MapPane.cpp includes UserPane.h and reads this pointer during timer events `6` and `8`. A non-null blocker suppresses movement/action continuation and routes through the accepted queued-state clear behavior.
- MapPane does not publish, clear, allocate, destroy, or own InputBlockerPane storage in this relationship and must not duplicate the definition.

## Status

- Address: `0x0069b4cc`.
- Kind: process-wide singleton pointer.
- Proposed type: `InputBlockerPane*`.
- Owner module: [UID:0000P1][UserPane](by-file/UserPane.md), pending a future dedicated `InputBlockerPane` class/source split.
- Exact memory child: [UID:0002W8][0x0069b4cc-0x0069b4d0.InputBlockerPaneSingleton](by-memory/0x0069b4cc-0x0069b4d0.InputBlockerPaneSingleton.md).

This global stores the modal input-blocking pane used by local-user server-message/UI state handlers. It is separated from the mixed message/status/menu singleton cluster so the exact storage can be routed through a narrow source-level global page.

## Lifecycle

| Site | Access | Meaning |
| --- | --- | --- |
| `0x005a7cf9` in `0x005a76c0` | read/test | `UserPane::OnServerMessage` checks whether an input blocker already exists. |
| `0x005a7d42` and `0x005a7d49` in `0x005a76c0` | write/test | The same server-message path creates a `0xf8` / 248-byte modal pane object (Verified with int_convert.py), installs `InputBlockerPane` vtables, and publishes it through this singleton. |
| `0x005a7dba` in `0x005a76c0` | read/destroy | The cleanup branch destroys the modal blocker through the singleton. |
| `0x00507150`, [UID:0003ZS][0x00509030-0x00509439.MapPaneMovementTimerHandler](by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md), `0x005abc70`, `0x005b7610`, and `0x005b79d0` | read/write family | Additional packet/UI handlers observe or clear the active modal blocker as local user state changes. The MapPane movement timer child reads this singleton during timer events `6` and `8` and clears queued movement/action state instead of continuing path or auto-action processing while a modal input blocker exists. |

## Evidence

- Current memory documentation and B010's 2026-07-01 live MCP byte check report `0x0069b4cc` as a `0x4` / 4-byte slot (Verified with int_convert.py in existing docs) with active zero-initialized storage and sixteen direct data xrefs. Older `ff ff ff ff` wording is stale and superseded.
- [UID:0000P1][UserPane](by-file/UserPane.md) documents `0x005a76c0-0x005a82bd` as `UserPane::OnServerMessage`, the strongest owner for this singleton's create/test/destroy family.
- [UID:00026W][0x0062ef0c-0x006307ec.UserPaneInputVtables](by-memory/0x0062ef0c-0x006307ec.UserPaneInputVtables.md) records the `InputBlockerPane` vtable band at `0x0062efcc-0x0062f184`, with the early blocker/quit prompt group separated from the main `UserPane` vtables.
- [UID:000342][0x004b0ba0-0x004b0ba5.SharedReturnTrueVirtualHelper](by-memory/0x004b0ba0-0x004b0ba5.SharedReturnTrueVirtualHelper.md) records `InputBlockerPane` secondary/tertiary vtable references at `0x0062f01c` and `0x0062f020`, confirming the named pane family independently from this data slot.
- [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md) records this dword as a distinct one-slot singleton between the old system-message pane and parcel icon pane globals.

## Ownership Decision

Use `UserPane.cpp` as the current source-level owner because the strongest observed lifecycle is inside `UserPane::OnServerMessage`, and no dedicated `InputBlockerPane` class page exists yet. B010's 2026-07-01 implementation-callback update resolves the global as source-ready despite the missing full class page: a forward declaration is sufficient for the singleton pointer definition. If a future pass splits exact constructor/destructor/vtable pages into a full `InputBlockerPane` class owner, this global can be reparented after that class clears the 85/85 gate.

## Cross-References

- [UID:0000P1][UserPane](by-file/UserPane.md)
- [UID:0002W8][0x0069b4cc-0x0069b4d0.InputBlockerPaneSingleton](by-memory/0x0069b4cc-0x0069b4d0.InputBlockerPaneSingleton.md)
- [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md)
- [UID:00026W][0x0062ef0c-0x006307ec.UserPaneInputVtables](by-memory/0x0062ef0c-0x006307ec.UserPaneInputVtables.md)
- [UID:0003ZS][0x00509030-0x00509439.MapPaneMovementTimerHandler](by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md)

## Changes

- 2026-06-19 B013 MapPane notify/timer split sync: added [UID:0003ZS][0x00509030-0x00509439.MapPaneMovementTimerHandler](by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md) as the exact `0x00509030` reader. The MapPane timer callback uses `g_pInputBlockerPane` as modal suppression evidence for timer events `6` and `8`, clearing queued movement/action state instead of continuing path or auto-action processing; ownership of this global remains with the current UserPane/InputBlockerPane lifecycle route.
- 2026-06-11 A005 Batch236: Created as the dedicated by-global parent for the modal input-blocker singleton. Evidence comes from existing IDA-backed `UserPane::OnServerMessage`, vtable-family, shared-helper, and exact singleton memory docs plus int-convert verification of the one-dword slot and `0xf8` allocation size.
