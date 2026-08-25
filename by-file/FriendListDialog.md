*** UID:0000JN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/social/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# FriendListDialog

## Status

- Confidence: strong for class behavior, IDA boundaries, direct class/file ownership, C++03 source shape, config-backed 20-slot layout, and friend-name sync linkage.
- Proposed module folder: `social/`
- Proposed source file: `social/FriendListDialog.cpp`
- Possible split files: `ui/dialogs/FriendListDialog.cpp`
- Evidence basis: IDA MCP function-boundary/xref checks, linked memory/global pages, and B001 2026-06-27 endpoint/source-readiness recheck for [UID:0001DS][0x0053f2c0-0x0053f939.FriendListDialog](by-memory/0x0053f2c0-0x0053f939.FriendListDialog.md).

## Hypothesis

`FriendListDialog` is a self-contained social dialog source file. It builds a 20-entry friend-name editor from saved config strings, supports old/new asset layouts (`FRIEND.EPF`/`FRIEND.EPD`), writes edited names back into config on OK, optionally sends the updated friend/name-list state through opcode `0x77`, unconditionally calls [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md), and then closes/removes the dialog.

The implementation uses canonical `DialogPane`, `EPFImageControlPane`, `ImageButtonControlPane`, and `TextEditControlPane` APIs, but the asset names, config table, and fixed two-column friend-name layout make this feature-specific rather than a generic dialog/control source.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `g_friendNameListSyncEnabled` | `0x0066dee0-0x0066dee1` | `social/FriendListDialog.cpp` | Sole external `bool` definition initialized `true`; declared separately in a shared header for MapPane use. |
| `FriendListDialog` | `0x0053f2c0-0x0053f939`, destructor/thunks at `0x005425b5-0x00542735` | `social/FriendListDialog.cpp` | No-field derived class, constructor/destructor, `OnControlCommand`, and protected `SetHoverControl`; compiler destructor glue is retained as no-code evidence. |

## Boundary And Data Notes

- Live IDA MCP confirms `0x0053f2c0-0x0053f801`, non-deleting destructor helper `0x0053f810-0x0053f82f`, `OnControlCommand` `0x0053f830-0x0053f921`, protected `SetHoverControl` `0x0053f930-0x0053f939`, adjustor thunks `0x005425b5` and `0x005425c0`, and scalar deleting destructor `0x005426e0-0x00542735`. Historical `OnOkButton` and `OnSetFocus` names were behavior labels superseded by primary-vtable slots `+0x48` and `+0x58` plus matching base interfaces.
- Constructor callers include `0x0053ddb0`, `0x005a5bd0`, and `0x005bd000`, suggesting the dialog can be opened from multiple UI/menu paths.
- `OnControlCommand` is vtable-referenced at `0x00620f2c` and writes 20 friend-name strings back to `g_pConfig + 2691552`; the prior `0x0053f920` endpoint was one byte short, with the live function ending at `0x0053f921` before `0xcc` padding.
- B001 2026-06-27 MCP report resolves the endpoint at report-level detail: `lookup_funcs` reports `0x0053f830` size `0xf1`, `0x0053f920` as still inside `sub_53F830`, and `0x0053f921` as not a function; byte evidence shows the `ret 8` bytes occupy `0x0053f91e-0x0053f921`, so `0x0053f920` is executable content and padding starts at `0x0053f921`.
- IDA MCP caller evidence shows `OnControlCommand` calls [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md) only when [UID:0000PG][g_friendNameListSyncEnabled](by-global/g_friendNameListSyncEnabled.md) is nonzero. The source expression is the Socket member call `g_packetSender->BuildAndSendFriendNameListSync()`. It serializes the same 20 config slots into opcode `0x77`; historical generated `InventoryData`, `g_isCashShopEnabled`, and free-style send aliases are rejected.
- The accepted source order is exact: the handler writes and trims all 20 config strings, checks `g_friendNameListSyncEnabled`, conditionally calls `g_packetSender->BuildAndSendFriendNameListSync()`, then unconditionally calls `SaveUserSettings()` and only afterward closes/removes. Older wording that placed profile save before optional sync, used a free-style send, or called it generic `SaveConfig()` is superseded.
- The constructor uses two direct `g_useEpfAssets` branches rather than aggregate layout data. The EPF branch uses `FRIEND.EPF`/`FRIEND.PAL`, `332x399`, and ten left then ten right edit controls; the fallback branch uses `FRIEND.EPD`/`NPAL8.PAL`, `407x391`, and the same left-ten/right-ten order. Both use canonical control constructors, stack-local `RectBounds`, and common create/show/slide-open calls.
- Live IDA MCP on 2026-06-16 reconfirmed constructor `0x0053f2c0` size `0x541`, non-deleting destructor helper `0x0053f810` size `0x1f`, `OnOkButton` `0x0053f830` size `0xf1`, `OnSetFocus` `0x0053f930` size `0x9`, adjustor thunks `0x005425b5`/`0x005425c0`, scalar deleting destructor `0x005426e0` size `0x55`, no function at `0x0053f939`, and [UID:0001DT][0x0053f940-0x0053fe87.ProfileDialog](by-memory/0x0053f940-0x0053fe87.ProfileDialog.md) beginning at `0x0053f940`.
- Current xrefs keep ownership and helper boundaries unchanged: constructor refs are `0x0053e115`, `0x005a7112`, and `0x005bd151`; `OnControlCommand` and `SetHoverControl` are vtable refs at `0x00620f2c` and `0x00620f3c`; the adjustor thunks are vtable refs at `0x00620f44` and `0x00620f74`; scalar deleting destructor refs include the thunks and vtable slot `0x00620ee4`.
- The decompile pass confirmed both asset branches create two columns of ten text controls from the same config table starting at `g_pConfig + 2691552`, while `OnControlCommand` loops 20 controls, writes the same table back, trims/stores through the string helpers, checks `g_friendNameListSyncEnabled`, and calls `0x00574e50` only when the flag is set.
- Packet helper ownership was rechecked rather than assumed: `xrefs_to 0x00574e50` still reports `MapPane` inbound handling at `0x00508b14`, a raw flag-gated code ref at `0x005143ad`, and this dialog's `0x0053f8ed` OK path; `xrefs_to 0x0066dee0` reports the paired flag refs at `0x00508aff`, `0x0051439c`, and `0x0053f8dc`. The serializer remains Socket-owned support, not a method of this dialog file.
- Boundary bytes remain exact: `0x0053f801-0x0053f810`, `0x0053f921-0x0053f930`, and `0x0053f939-0x0053f940` are `0xcc`; the one-byte `0x0053f82f-0x0053f830` pad is also `0xcc`.
- UTF-16 resource bytes were re-read directly: `0x00621328` decodes to `Friend List`; `0x00621340`, `0x00621358`, and `0x00621370` include `FRIEND.PAL`, `FRIEND.EPF`, and `FRIEND.EPD`; `0x0061484c` includes `NPAL8.PAL`.

## Blocker Investigation

- Source placement: checked the proposed source tree, constructor/caller evidence, adjacent ProfileDialog and macro/social boundaries, and the feature-specific asset/config behavior. `NexusTK/social/FriendListDialog.cpp` remains the strongest source root; `ui/dialogs/` remains only a possible folder-style alternative without stronger evidence.
- Helper ownership: checked call sites for [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md) and the paired sync flag. Because the helper is also called from `MapPane` and a raw flag-gated island and uses Socket queue state, it should not be folded into this dialog file.
- Field/type/helper names: the 20-slot config table, two-column layout, vtable callback slots, and asset branch are resolved behaviorally. B001's accepted first-draft C++ uses source-facing inferred names for control container, config friend-name array, layout selector, and base helper calls. These names remain descriptive rather than original-symbol-proven, but they no longer block target-level first-draft C++ on [UID:0001DS][0x0053f2c0-0x0053f939.FriendListDialog](by-memory/0x0053f2c0-0x0053f939.FriendListDialog.md); the remaining caveat is final-audit naming polish, not range, owner, or source-route readiness.

## Migration Notes

This class is safe to use as a source-layout anchor after ordinary review. Keep the initial source root as `NexusTK/social/FriendListDialog.cpp` unless later original-source evidence proves the dialog was grouped into a broader social dialogs file.

## Source-Ready Target Note

[UID:0001DS][0x0053f2c0-0x0053f939.FriendListDialog](by-memory/0x0053f2c0-0x0053f939.FriendListDialog.md) carries the complete first-draft FriendListDialog C++. That target keeps the constructor, `OnControlCommand`, and `SetHoverControl` bodies inside the exact memory range, leaves [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md) and [UID:00038A][0x005426e0-0x00542735.FriendListDialogScalarDeletingDestructor](by-memory/0x005426e0-0x00542735.FriendListDialogScalarDeletingDestructor.md) as compiler-generated support evidence, and keeps [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md) Socket-owned rather than folding it into this social dialog file.

The generated translation-unit order is source definition [UID:0001OM][0x0066dee0-0x0066dee1.FriendNameListSyncEnabled](by-memory/0x0066dee0-0x0066dee1.FriendNameListSyncEnabled.md), complete no-field class [UID:00005J][FriendListDialog](by-class/FriendListDialog.md), then aggregate method source [UID:0001DS][0x0053f2c0-0x0053f939.FriendListDialog](by-memory/0x0053f2c0-0x0053f939.FriendListDialog.md). The cross-translation-unit `extern bool g_friendNameListSyncEnabled;` belongs in a shared header and is deliberately not emitted beside the definition. No raw vtable/RTTI arrays, vptr stores, adjustor thunks, scalar flags, cookies/EH code, raw duplicate, layout objects, or C++11 syntax belong in handwritten `FriendListDialog.cpp`.

## Score Rationale

- Completion `91`: file ownership, one-definition route, complete class and method inventory, exact method ordering, direct asset branches, canonical controls, packet/config flow, header-declaration separation, and compiler exclusions are implemented. Remaining work is limited to unavailable original header and exact lexical file organization.
- Confidence `93`: ranges, xrefs, resources, vtable slots, APIs, dataflow, and generated routing converge. The cap reflects inferred source spelling rather than behavioral uncertainty.

## Cross-References

- [UID:00005J][FriendListDialog](by-class/FriendListDialog.md)
- [UID:0001DS][0x0053f2c0-0x0053f939.FriendListDialog](by-memory/0x0053f2c0-0x0053f939.FriendListDialog.md)
- [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md)
- [UID:0000PG][g_friendNameListSyncEnabled](by-global/g_friendNameListSyncEnabled.md)
- [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md)
- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- [UID:0000JS][Group](by-file/Group.md)

## Changes

- 2026-07-20 B003 source-quality implementation:
  - Raised the file from `86/88` to `91/93` and preserved `NexusTK/social/`, file ownership, all ranges, caller evidence, padding, and historical endpoint corrections.
  - Added the sole global definition/class/method source inventory, exact translation-unit order, separate shared-header declaration requirement, direct EPF/EPD source branches, canonical controls and virtual names, exact Socket/save/close order, and complete compiler/no-code exclusions.
  - Historicalized behavior-only old method names, misleading cash-shop/inventory aliases, free-style send, generic controls, synthetic layout objects, and post-era syntax without deleting their provenance.

- 2026-07-14 B005 [UID:0001AV][0x0050aba0-0x0050b078.SaveUserSettings](by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md) implementation callback support sync:
  - Score, source path, metadata, and ownership remain unchanged. Recorded exact trim/store -> optional opcode `0x77` sync -> unconditional `SaveUserSettings` -> close/remove ordering and rejected the old generic `SaveConfig()` name.

- 2026-06-12 A004 Batch 243 parent-gate repair:
  - Before: `COMPLETION:84`, `CONFIDENCE:82`, and the file still carried the stale `OnOkButton` endpoint uncertainty from the earlier live-IDA timeout.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:86`.
  - Evidence: live IDA MCP reconfirmed the constructor, non-deleting destructor helper, OK handler, focus helper, adjustor thunks, and exact scalar deleting destructor wrapper, resolving the `0x0053f920`/`0x0053f921` endpoint discrepancy and clearing the strict direct file gate for [UID:00005J][FriendListDialog](by-class/FriendListDialog.md).
- 2026-06-27 B001 source-ready endpoint refresh:
  - Before: the file page still described final source as blocked by synthetic field/helper names.
  - After: the page records that [UID:0001DS][0x0053f2c0-0x0053f939.FriendListDialog](by-memory/0x0053f2c0-0x0053f939.FriendListDialog.md) is target-level first-draft C++ ready, with source-facing inferred names and exact endpoint/order evidence.
  - Evidence: B001 accepted report `tools/leaser/Agents/Agent-B001/research/0001DS-FriendListDialog-source-quality.md` plus implementation-time MCP session `875bf182` reconfirming `0x0053f830` size `0xf1`, `0x0053f920` inside the handler, and `0x0053f921` outside any function.
- 2026-06-16 A002 file-completion refresh:
  - Before: scores were `85/86`, while the by-file coverage row still lagged at `84%` and the remaining helper/source-placement blockers were not explicitly investigated on the file page.
  - Changed to: scores `86/88`; added current IDA function/xref/decompile/padding/string evidence and explicit source-placement, helper-owner, and final-name blocker investigation.
  - Evidence: live IDA reconfirmed the exact constructor/destructor/OK/focus/thunk boundaries, vtable refs, three constructor callers, config table layout, opcode `0x77` sync linkage, direct UTF-16 asset bytes, adjacent `ProfileDialog` boundary, and why the send helper remains Socket-owned support.
- 2026-06-05: Filled `PROPOSED_RECONSTRUCTION_PATH` with `NexusTK/social/`.
  - Reason: `by-project-structure/proposed-source-tree.md` already places `FriendListDialog.cpp` under `social/`, and this page records IDA-backed boundaries plus friend-name sync behavior that support a feature-specific social dialog source root. Completion/confidence scores were not changed.
- 2026-05-28: Changed the core `FriendListDialog` range from `0x0053f2c0-0x0053f938` to `0x0053f2c0-0x0053f939`.
  - Before: the file-level range ended before the final byte of `OnSetFocus`.
  - After: the range includes full `OnSetFocus`, with padding before `ProfileDialog`.
  - Evidence: IDA MCP reports `sub_53F930` as `0x0053f930-0x0053f939`; bytes after that end are `0xcc` until `0x0053f940`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:82`.
  - Summary/evidence: class behavior, boundaries, save/sync opcode behavior, asset-mode branch, constructor/callback evidence, and range correction are well documented; confidence is capped by exact final folder placement and the former generated `BuildAndSendInventoryData` alias.
