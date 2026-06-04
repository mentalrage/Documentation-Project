*** UID:0000FQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000P1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# UserPane

## Status

- Confidence: strong for IDA-confirmed method boundaries, vtable slots, singleton/global lifetime, and source parent; medium-high for final field names and the exact split from adjacent social and movement helpers.
- Likely source file: [UID:0000P1][UserPane](by-file/UserPane.md)
- Address range: [UID:0001KL][0x005a2530-0x005b8395.UserPane](by-memory/0x005a2530-0x005b8395.UserPane.md)
- Evidence basis: live IDA MCP inspection on 2026-06-04 against `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- Reconstruction status: reconstructable under [UID:0000P1][UserPane](by-file/UserPane.md), with C++ intentionally blank because the largest handlers and fields remain below the `95/95` code-emission bar.

## Class Purpose

`UserPane` is the local player/user display pane. It constructs the main local-user pane object, stores large per-user state arrays, routes key and server-message input, updates animation and clipping, tracks visible slot labels, and manages the floating local name label.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| constructor | `0x005a2530-0x005a2c5b` | Constructs the pane, installs all three `UserPane` vtables, stores `this` in `dword_67A748`, vector-constructs 128 large records at stride `0x2604`, initializes child/state fields, and constructs the BowGauge child at `0x005a2956`. |
| non-deleting destructor | `0x005a2c60-0x005a2d74` | Restores `UserPane` vtables, deletes/releases the `+0x13eb04/+0x13eb08/+0x13eb0c` children, frees dynamic buffers, runs BowGauge timer/show cleanup, vector-destroys the 128 records, clears `dword_67A748`, and calls base cleanup. |
| selected/user name helper | `0x005a2d80-0x005a2d97` | Bounded `wcscpy_s` into the 32-wide-character local-player name buffer at `word_69BEE0`; called from UI initialization at `0x004f84ad` and `0x004f8a14`. |
| `BuildInventorySlotLabelString` | `0x005a40d0-0x005a430c` | Builds compact inventory slot label/range strings; IDA callers include repeated dispatch sites inside `OnKeyEvent` plus nearby command-row helpers. |
| `BuildSpellSlotLabelString` | `0x005a4310-0x005a4523` | Builds compact spell slot label/range strings; IDA callers include `OnKeyEvent` and helper sites at `0x005a9e9d` and `0x005b618f`. |
| `OnBoundsChanged` | `0x005a5b80-0x005a5bc7` | Updates cached bounds and invalidates child geometry. |
| `OnKeyEvent` | `0x005a5bd0-0x005a7422` | Handles local-player keyboard commands and dispatches related panes/packets. |
| `OnServerMessage` | `0x005a76c0-0x005a82bd` | Parses server payloads routed to the local user pane. |
| `OnAnimationStep` | `0x005a83b0-0x005a87ad` | Handles animation/update ticks. |
| `OnClipBounds` | `0x005a8840-0x005a88cf` | Applies local clipping behavior. |
| `ShowNameLabel` | `0x005a8e70-0x005a8f5a` | Sets the visible/name-label flag, computes the pane rectangle from the current bounds, drives [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md) virtual show/position calls, and calls BowGauge helper `0x00538c10`. |
| `HideNameLabel` | `0x005a8f60-0x005a8f8c` | Clears the visible/name-label flag, removes pending timers from [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md) through [UID:0001DC][0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers](by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md), and caches `dword_67AB80+0x18` into `this+0x13eb38`. |
| scalar deleting destructor | `0x005b8230-0x005b8395` | Full destructor body plus conditional pool return through `byte_69BF34`; vtable xrefs and thunks at `0x005b792e`/`0x005b7939` point here. |
| virtual dword `+0x1340f8` accessor | `0x005b83a0-0x005b83a7` | Tiny vtable accessor returning `this+0x1340f8`; semantic field name still provisional. |

## Live IDA Evidence

- IDB identity: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, checked through IDA MCP on 2026-06-04.
- Function boundaries confirmed by `lookup_funcs`: constructor `0x005a2530-0x005a2c5b`, cleanup `0x005a2c60-0x005a2d74`, name setter `0x005a2d80-0x005a2d97`, inventory/spell label builders `0x005a40d0-0x005a430c` and `0x005a4310-0x005a4523`, virtual handlers `0x005a5b80-0x005a5bc7`, `0x005a5bd0-0x005a7422`, `0x005a76c0-0x005a82bd`, `0x005a83b0-0x005a87ad`, `0x005a8840-0x005a88cf`, name-label methods `0x005a8e70-0x005a8f5a` and `0x005a8f60-0x005a8f8c`, scalar destructor `0x005b8230-0x005b8395`, and adjacent accessor `0x005b83a0-0x005b83a7`.
- Constructor direct callers are `0x004f84e2` and `0x004f8a49`, both inside the UI initialization function at `0x004f7d10`; the local-name setter is called from the same function at `0x004f84ad` and `0x004f8a14`.
- Constructor setup: `0x005a2587` stores `this` into `dword_67A748`; `0x005a25b7`, `0x005a25bd`, and `0x005a25c7` install the three `UserPane` vtables; `0x005a2598-0x005a25d1` vector-constructs 128 records of size `0x2604`; `0x005a277b` initializes the `+0x1340f8` accessor field to zero.
- Destructor setup: both cleanup bodies restore the same three vtables, release child pointers at `+0x13eb04`, `+0x13eb08`, and `+0x13eb0c`, free `+0x13eb14` and `+0x13eb20`, call BowGauge cleanup through `dword_69BA24`, vector-destroy the 128 records, and clear `dword_67A748` at `0x005a2d55` or `0x005b832c`.
- Vtable slots confirmed in `.rdata`: `0x0062ef0c -> 0x005b8230`, `0x0062ef18 -> 0x005a5b80`, `0x0062ef28 -> 0x005b83a0`, `0x0062ef5c -> 0x005a8840`, `0x0062ef80 -> 0x005a8e70`, `0x0062ef84 -> 0x005a8f60`, `0x0062ef98 -> 0x005a5bd0`, `0x0062efa0 -> 0x005a76c0`, and `0x0062efc4 -> 0x005a83b0`.
- Global/data xrefs: `dword_67A748` is written by the constructor at `0x005a2587` and cleared by cleanup at `0x005a258e`, `0x005a2d55`, and `0x005b832c`; `word_69BEE0` is used by the setter/getter/conversion helpers at `0x005a2d88`, `0x005a2da3`, `0x005a2dc6`, and block-list validation at `0x005b6df4`; the `byte_69BF34` pool is referenced by static construction `0x0041a4b7`, unwind cleanup `0x00502445`, scalar return-to-pool `0x005b834e`, and static cleanup `0x0060c450`.
- BowGauge relationship: IDA xrefs show the BowGauge constructor `0x00538bc0` is called only from `UserPane` at `0x005a2956`; BowGauge timer cleanup `0x00538c40` is called from `0x005a2d28`, `0x005a8f7b`, and `0x005b82ff`; BowGauge update helper `0x00538c10` is called from `ShowNameLabel` at `0x005a8f46`.
- Boundary padding is confirmed as `0xcc`: `0x005a2523-0x005a2530`, `0x005a2c5b-0x005a2c60`, `0x005a2d74-0x005a2d80`, `0x005b8395-0x005b83a0`, and `0x005b83a7-0x005b83b0`.

## Boundary Notes

- Keep `0x005a4930-0x005a5791` with chat/history/say-input documentation unless later caller evidence proves the original source intentionally grouped those helpers with `UserPane`.
- Keep neighboring movement/combat/local-object helpers such as `0x005a2de0`, `0x005a2e00`, `0x005a4530`, `0x005a5a90`, `0x005a87e0`, `0x005a88d0`, and `0x005a8cf0` with [UID:0001KM][0x005a2de0-0x005ad440.LivingObjectPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad440.LivingObjectPaneLocalPlayerExtensions.md) or the appropriate movement/object-pane owner.
- Keep [UID:0000FP][UserLookPane](by-class/UserLookPane.md), [UID:0000CU][SelfLookPane](by-class/SelfLookPane.md), and [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md) separate. The adjacent `0x005b83a0-0x005b83a7` accessor is `UserPane`-owned by vtable slot, but `0x005b83b0` starts the separate `UserStatusPane` range.

## Evidence Notes

- The class is reconstructable enough to attach to [UID:0000P1][UserPane](by-file/UserPane.md) because the constructor/destructor, virtual slots, source path, singleton/pool lifetime, and related child/global docs are all IDA-backed and the parent confidence is above the attachment threshold.
- C++ remains blank because `OnKeyEvent`, `OnServerMessage`, `OnAnimationStep`, and the large record layout still contain provisional field/helper names. The page should guide reconstruction, not freeze speculative source names.
- The broad address neighborhood still requires exclusions: nearby social/history helpers and `LivingObjectPane` movement helpers are real code, but they are not proven `UserPane` class methods.

## Cross-References

- [UID:0000P1][UserPane](by-file/UserPane.md)
- [UID:0001KL][0x005a2530-0x005b8395.UserPane](by-memory/0x005a2530-0x005b8395.UserPane.md)
- [UID:0000FP][UserLookPane](by-class/UserLookPane.md)
- [UID:0000CU][SelfLookPane](by-class/SelfLookPane.md)
- [UID:000011][BowGaugeObjectPane](by-class/BowGaugeObjectPane.md)
- [UID:0000QA][g_pBowGaugeObjectPane](by-global/g_pBowGaugeObjectPane.md)
- [UID:00024A][0x005b83a0-0x005b83a7.UserPaneVirtualDword1340F8Accessor](by-memory/0x005b83a0-0x005b83a7.UserPaneVirtualDword1340F8Accessor.md)
- [UID:00026W][0x0062ef0c-0x006307f4.UserPaneInputVtables](by-memory/0x0062ef0c-0x006307f4.UserPaneInputVtables.md)
- [UID:0002AA][0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer](by-memory/0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer.md)
- [UID:0002AC][0x0069bf34-0x0069bf5c.UserPanePoolStaticStorage](by-memory/0x0069bf34-0x0069bf5c.UserPanePoolStaticStorage.md)
- [UID:0001KM][0x005a2de0-0x005ad440.LivingObjectPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad440.LivingObjectPaneLocalPlayerExtensions.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:76`.
  - Summary/evidence: scored from the broad method map, constructor/destructor evidence, local-user input/message/animation/name-label roles, BowGauge owner-pollution correction, and accessor boundary note; confidence is capped because the broad address neighborhood still contains LivingObjectPane/social-helper ownership caveats and some helper names remain provisional.
- 2026-06-04 live IDA rescore and parent attachment:
  - What existed before: `COMPLETION:82`, `CONFIDENCE:76`, blank reconstructable/parent metadata, older external-lead wording, and only sparse IDA evidence.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000P1`.
  - Summary/evidence: live IDA MCP now records the IDB identity, exact function ranges, constructor/name-helper callers, constructor vtable/global setup, destructor cleanup behavior, vtable slots, `dword_67A748`/`word_69BEE0`/`byte_69BF34`/BowGauge xrefs, and surrounding `0xcc` padding. Scores stay below final-source quality because large handler field names and adjacent social/movement source ownership still need final layout proof.
