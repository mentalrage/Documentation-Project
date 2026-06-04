*** UID:0000LL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Motion

## Status

- Proposed module: `NexusTK/render/Motion.cpp` for the timer-driven animation object.
- Split-owner guard: keep [UID:0000N3][Region](by-file/Region.md) / `NexusTK/ui/core/Region.cpp` for dirty rectangles, [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) / `NexusTK/ui/dialogs/MessageDialogs.cpp` for the dialog packet dispatcher, and [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) / `NexusTK/render/NewHumanImageLib.cpp` for `Motion.tbl` vector helpers.
- Confidence: strong for the live IDA-backed source split; medium-high for the final original filename because the animation object may have lived in a nearby render/game animation unit.

## File Role

This page records the Motion/Region ownership split. The historical `Motion` label is not a safe one-to-one original source file. It mixes:

- timer-driven animation object code;
- dirty-rectangle/region helper code;
- a message/menu-question dialog packet dispatcher;
- `NewHumanImageLib` `Motion.tbl` vector helper names in adjacent globals.

## Proposed Source Split

```text
NexusTK/render/Motion.cpp
  timer-driven Motion animation constructors
  Motion::OnTimerTick
  animation cleanup/destructor wrapper
  pool-backed allocation/delete policy

NexusTK/ui/core/Region.cpp
  Region construction/destruction
  Motion-named rectangle/dirty-region helpers
  rectangle normalization / dirty-region primitives

NexusTK/ui/dialogs/MessageDialogs.cpp
  HandleDialogPacket_54C200 and related dialog allocation wrappers

NexusTK/render/NewHumanImageLib.cpp
  VectorGrowMotion
  DestroyMotionVector
  Motion.tbl record/vector structs
```

The exact original animation filename remains open. The important reconstruction rule is not to migrate every historical `Motion`-labeled range into one original source file.

## Proposed Contents By Family

| Family | Range | Proposed owner |
| --- | --- | --- |
| Animation object | `0x00539bc0-0x0053d614` | This page / `NexusTK/render/Motion.cpp` candidate, backed by [UID:0001DD][0x00539bc0-0x0053d614.MotionAnimation](by-memory/0x00539bc0-0x0053d614.MotionAnimation.md). Exact children: [UID:0002QW][0x00539bc0-0x00539d43.MotionAnimationConstructor](by-memory/0x00539bc0-0x00539d43.MotionAnimationConstructor.md), [UID:0002QX][0x00539de0-0x00539f52.MotionAnimationAlternateConstructor](by-memory/0x00539de0-0x00539f52.MotionAnimationAlternateConstructor.md), [UID:0002QY][0x00539fe0-0x0053a10c.MotionAnimationTimerTick](by-memory/0x00539fe0-0x0053a10c.MotionAnimationTimerTick.md), [UID:0002QZ][0x0053d590-0x0053d614.MotionAnimationScalarDeletingDestructor](by-memory/0x0053d590-0x0053d614.MotionAnimationScalarDeletingDestructor.md). |
| Region and dirty rectangles | `0x00554680-0x00554b38` | [UID:0000N3][Region](by-file/Region.md) and [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md), UI core/render support. |
| Dialog packet dispatcher/wrappers | `0x0054c200-0x0054caa9` | [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md) and [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md), not Motion. |
| `Motion.tbl` vector helpers | `0x004e5240`, `0x004e5dd0` | [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md), not Motion class methods. |
| LObject destructor | `0x004f4a90` | [UID:0000KV][LObject](by-file/LObject.md), not Motion-specific. |

## Live IDA Evidence

- IDA MCP on 2026-06-04 used IDB `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- Motion animation functions are exact IDA functions: `0x00539bc0-0x00539d43`, `0x00539de0-0x00539f52`, `0x00539fe0-0x0053a10c`, and `0x0053d590-0x0053d614`.
- `0x00539bc0` has one code xref at `0x0053b5f9` inside `0x0053b3d0`. The alternate constructor has no direct entry xrefs, matching a constructor variant retained as a local entry.
- Motion vtable evidence ties the timer/destructor to the animation class: `0x00620954 -> 0x0053d590`, `0x00620964 -> 0x0053cf54`, and `0x00620968 -> 0x00539fe0`; `xrefs_to` reports the data refs at `0x00620954` and `0x00620968`.
- Animation constructor callees are `0x004f4a80` and `0x00597570`; timer callees include `0x00506980`, `0x00469120`, `0x00597910`, `0x0057a5c0`, and `0x0057a6c0`; destructor callees include `0x00597580`, `0x004f4a90`, and `0x004b14c0`.
- Region/rectangle functions remain a separate broad UI/render utility island with exact IDA ranges from `0x00554680-0x005546e1` through `0x00554b00-0x00554b38`. Representative code-ref counts are constructor `89`, normalized rect `37`, Region intersect wrapper `51`, and offset `32`; Region vtable slot `0x00622f58 -> 0x00554b00`.
- Dialog ownership is separate: `0x0054c200-0x0054c511` has callers at `0x00507e2e` and `0x0051287f`, and calls dialog/menu-question constructors and allocation wrappers including `0x0054ce10`, `0x0054fb30`, `0x0054c870`, `0x0054c8d0`, `0x0054c930`, `0x0054c990`, `0x0054c9f0`, and `0x0054ca50`.
- `Motion.tbl` vector helpers are separate render asset-table support: `0x004e5240-0x004e5415` is called at `0x004e0ff2` from `0x004e0e20`, while `0x004e5dd0-0x004e5e39` is referenced at `0x004e0547` and `0x0060025a` from the `NewHumanImageLib` constructor/destructor family.
- `0x004f4a90` is a seven-byte base destructor function with `366` code refs, so it is not Motion-specific ownership evidence.

## Cross-References

- [UID:00008R][Motion](by-class/Motion.md)
- [UID:0000N3][Region](by-file/Region.md)
- [UID:0000BV][Region](by-class/Region.md)
- [UID:0001DD][0x00539bc0-0x0053d614.MotionAnimation](by-memory/0x00539bc0-0x0053d614.MotionAnimation.md)
- [UID:0001FW][0x00554680-0x00554b38.RegionAndMotionRect](by-memory/0x00554680-0x00554b38.RegionAndMotionRect.md)
- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:0000KL][Layer](by-file/Layer.md)
- [UID:0000JR][GrafPort](by-file/GrafPort.md)

## Changes

- 2026-06-04:
  - Before: scored `82/76` with a blank proposed path and stale evidence phrasing.
  - After: scored `86/84`, set `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`, and rewrote the evidence around live IDA function, vtable, caller, callee, and source-split checks.
  - Why: the live IDA pass proves the timer-driven Motion animation class is the only Motion-owned source candidate, while Region rectangle helpers, message dialog packet dispatch, `Motion.tbl` vector helpers, and `LObject` base destruction have separate owners. Confidence remains below 90 because the exact original animation filename is still not proven.

- Before: the non-Motion dialog packet dispatcher was listed only as `0x0054c200-0x0054c510`.
- Changed to: the non-Motion dialog dispatcher/wrapper island is `0x0054c200-0x0054caa9`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows the old range stopped at the main dispatcher, while adjacent wrappers through `0x0054caa9` are the same dialog allocation source island.
- 2026-05-28: Corrected the Region/dirty-rectangle companion range from `0x00554680-0x00554b37` to `0x00554680-0x00554b38`. Evidence: IDA MCP disassembly shows `0x00554b37` is the final `Region::ScalarDeletingDestructor` `retn 4` byte.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `82`, confidence `76`.
- Summary/evidence: the page documents the mixed historical ownership, proposed source split, major range families, evidence notes, and corrected ranges; confidence is lower than adjacent file pages because this is intentionally a split/triage page rather than one clean original source file.
