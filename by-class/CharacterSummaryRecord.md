*** UID:00001N | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CharacterSummaryRecord

## Status

- Confidence: strong that this is a generated pseudo-class, not an original class boundary.
- Generated source: `source-3/simroot_v2/class_CharacterSummaryRecord.cpp`
- Correct owner class: [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md)
- Correct owner file: [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- Exact accessor island: [UID:0001NN][0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md)

## Classification

`CharacterSummaryRecord` is a recovery label for a cluster of `UserStatusPane` accessors over `g_activeUserStatusPane` at `0x0069ae0c`. It should not become a separate migrated C++ class unless later evidence finds an independently allocated object; the current local PE recheck actively rejects that alternative.

The methods in this generated class read and write the same `UserStatusPane` offsets initialized by `UserStatusPane::UserStatusPane` at `0x005b83b0`.

## Correct Ownership

| Address | Generated name | Correct interpretation |
| --- | --- | --- |
| `0x005b85b0` | `CopyNameLineA` | `UserStatusPane` copy helper for wide string at `+0x0fc`. |
| `0x005b85d0` | `CopyNameLineB` | `UserStatusPane` copy helper for wide string at `+0x1fc`. |
| `0x005b85f0` | `GetPercentStatA` | `UserStatusPane` byte getter at `+0x281`. |
| `0x005b8600` | `GetPercentStatB` | `UserStatusPane` byte getter at `+0x282`. |
| `0x005b8610` | `GetPercentStatC` | `UserStatusPane` byte getter at `+0x283`. |
| `0x005b8620` | `GetNationId` | `UserStatusPane` nation id getter at `+0x27c`. |
| `0x005b8630` | `GetSpiritId` | `UserStatusPane` spirit/totem getter at `+0x27e`. |
| `0x005b8640` | `GetDisplayValueA` | `UserStatusPane` dword getter at `+0x28c`. |
| `0x005b8650` | `GetDisplayValueB` | `UserStatusPane` dword getter at `+0x294`. |
| `0x005b8660` | omitted | `UserStatusPane` third dword getter at `+0x298`. |
| `0x005b8670` | `SetDisplayLineA` | `UserStatusPane` setter for wide string at `+0x17c`, then invalidates via vtable slot `+0x20`. |
| `0x005b86a0` | `SetDisplayLineB` | `UserStatusPane` setter for wide string at `+0x1fc`, then invalidates via vtable slot `+0x20`. |

## 2026-06-20 B004 Source-Routing Recheck

B004 rechecked this target with local PE disassembly because IDA MCP was unavailable at `http://127.0.0.1:13337/mcp` (`Unable to connect to the remote server`). The binary identity used for the recheck was `NexusTK.exe`, size `2679296`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, image base `0x00400000`, with `.text 0x00401000-0x0060c600`, `.rdata 0x0060d000-0x0066c200`, and `.data 0x0066d000-0x0069ce24`.

The constructor evidence is still `UserStatusPane`, not a record object: `0x005b83b0-0x005b8526` calls the pane base constructor at `0x00544460`, stores `this` to `0x0069ae0c` at `0x005b83fa` with a null-adjustment store at `0x005b8401`, installs vtable pointers at complete offsets `+0x00`, `+0xa0`, and `+0xa4`, loads `9X11FONT.BIN` through `0x004bb120`, copies the incoming name into `+0x0fc`, clears EPF/new-layout text lines at `+0x17c` and `+0x1fc`, initializes `+0x27c` to `0xffff`, `+0x27e` to `0x0000ffff`, `+0x282` to `0`, `+0x284` to `52`, and zeros `+0x288` through `+0x2a4`. The only local constructor rel32 call is at `0x004f837a`, matching `InitializeMainUiGraph`.

Local PE absolute scan found 67 dword references to `0x0069ae0c`, matching [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md). Representative callers load the active `UserStatusPane` as the receiver before invoking these accessors: `0x004a1e0a` loads `ecx = [0x0069ae0c]` before `0x005b85b0`; `0x004acb0c` loads `esi = [0x0069ae0c]` and uses `ecx = esi` before `0x005b85b0` and `0x005b85d0`; `0x00567f91`, `0x00571946`, `0x00567ca8`, `0x0059be23`, `0x0059d31c`, and `0x00567dfe` load `ecx = [0x0069ae0c]` before byte getter calls; `0x00565a27` / `0x00570270` load it before `SetDisplayLineA`; `0x00565b28` / `0x00570371` load it before `SetDisplayLineB`; and `0x005aad5f` loads it before [UID:0002LP][0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId](by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md). No representative caller passes `this + fieldOffset`, an embedded-record pointer, or any separately allocated `CharacterSummaryRecord *`.

The generated pseudo-class is also incomplete as a source slice: `class_CharacterSummaryRecord.cpp` omits the real `0x005b8660` seven-byte dword getter for `+0x298`. Adjacent raw bytes show `0x005b86ca-0x005b86d0` as six `0xcc` bytes, `0x005b86d0-0x005b86d8` as `movsx eax, byte ptr [ecx+0x27e]; ret`, and `0x005b86d8-0x005b86e0` as eight `0xcc` bytes. Rel32 and absolute scans found no inbound refs to `0x005b86d0`; best current interpretation is a retained/no-route signed spirit/totem getter outside [UID:0001NN][0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md), not evidence for a real `CharacterSummaryRecord` class.

## Direct Caller Scan

| Target | Local rel32 callers |
| --- | --- |
| `0x005b85b0` | `0x004a1e18`, `0x004acb1d`, `0x00566bee`, `0x005705e7` |
| `0x005b85d0` | `0x004acb2d` |
| `0x005b85f0` | `0x00567f97`, `0x0057194c` |
| `0x005b8600` | `0x0056804a`, `0x005719ff` |
| `0x005b8610` | `0x00568103`, `0x00571abe` |
| `0x005b8620` | `0x00567cae`, `0x0059be29`, `0x0059d322` |
| `0x005b8630` | `0x00567e04` |
| `0x005b8640` | `0x00566bf5`, `0x005681be`, `0x005705ee` |
| `0x005b8650` | `0x00566c08`, `0x005683bc`, `0x005705fb` |
| `0x005b8660` | no local rel32 callers and no absolute pointer refs |
| `0x005b8670` | `0x00565a2e`, `0x00570277` |
| `0x005b86a0` | `0x00565b2f`, `0x00570378` |

This caller pattern is strong negative evidence against an embedded subobject class. If original source had called methods on an embedded record member, call sites would normally pass `this + fieldOffset` or an address stored inside the pane; instead, they pass the active `UserStatusPane` pointer and the methods use full `UserStatusPane` offsets.

## No-Code Proof

Formal target C++ must remain blank because this target is intentionally `RECONSTRUCTABLE:FALSE`, has no emitter UID, has no standalone class lifetime evidence, and has no defensible source entity. B004 checked for the usual class/source signals and found no constructor, destructor, scalar deleting destructor, vtable, allocation site, global instance, RTTI/COL block, or embedded-subobject receiver setup. The real source-bearing item is [UID:0001NN][0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md), routed through [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md) to [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md).

Adding a `class CharacterSummaryRecord` declaration or methods here would duplicate and misroute `UserStatusPane` source. A temporary rewrite helper, if needed, should be comments or private `UserStatusPane` field names such as [UID:0001WF][UserStatusPaneSummaryFields](by-type/by-struct/UserStatusPaneSummaryFields.md), not a separate allocated object.

## Rejected Alternatives

- Standalone original `CharacterSummaryRecord` class or file: rejected because the generated file contains only method bodies, omits `0x005b8660`, and has no lifecycle/type evidence.
- Embedded subobject receiver: rejected because representative call sites pass `g_activeUserStatusPane` itself as `ecx`, not `UserStatusPane + offset`.
- [UID:00021I][0x00485780-0x00485867.ClanDepositMoneyRequestAndSubmitPacketHelpers](by-memory/0x00485780-0x00485867.ClanDepositMoneyRequestAndSubmitPacketHelpers.md): rejected as stale/cross-assignment text unrelated to `CharacterSummaryRecord` or `UserStatusPane`.
- Generated aliases such as `DAT_0069ae0c`, `dword_69AE0C`, `g_pLocalPlayer`, or `g_pEffectObjImageLib`: rejected for this address unless future evidence proves separate storage; `0x0069ae0c` remains [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md).

## Evidence Notes

- IDA decompilation names the surrounding constructor and cleanup as `UserStatusPane` vtable code.
- Existing UserStatusPane memory docs already cover this method cluster in the `0x005b85b0-0x005b86ca` subrange.
- The generated pseudo-class still omits sibling getter `0x005b8660`, so it is not even a complete accessors view of the status-pane tail.

## Cross-References

- [UID:0000I4][CharacterSummaryRecord](by-file/CharacterSummaryRecord.md)
- [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md)
- [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- [UID:0001NM][0x005b83b0-0x005baafe.UserStatusPane](by-memory/0x005b83b0-0x005baafe.UserStatusPane.md)
- [UID:0001NN][0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md)
- [UID:0001WF][UserStatusPaneSummaryFields](by-type/by-struct/UserStatusPaneSummaryFields.md)

## Changes

- 2026-06-05: Changed autogen reconstructability from blank to `FALSE`.
  - Before: the page clearly documented `CharacterSummaryRecord` as a generated pseudo-class, but blank metadata left it unclassified in `-ag-class-coverage.md`.
  - After: the page is explicitly non-reconstructable as a standalone class; the accessors remain owned by [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md) and [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md).
  - Evidence: live IDA MCP on 2026-06-05 confirms `sub_5B85B0` at `0x005b85b0` and the adjacent `sub_5B83B0` constructor/core at `0x005b83b0`, matching the documented `UserStatusPane` receiver and accessor island.
- What existed before: the page clearly classified this as a generated pseudo-class over `UserStatusPane` accessors, but metadata still read `0/0`.
- What it was changed to: scores were set to `82/90`.
- Summary and evidence: the correct owner, accessor island, offset meanings, and missing sibling getter are documented; final field names belong in the UserStatusPane/layout pages rather than as a separate original class.
- 2026-06-20 B004 source-routing incorporation:
  - What existed before: the target already rejected `CharacterSummaryRecord` as a generated pseudo-class but lacked the current local PE receiver/caller scan, no-code proof, stale [UID:00021I][0x00485780-0x00485867.ClanDepositMoneyRequestAndSubmitPacketHelpers](by-memory/0x00485780-0x00485867.ClanDepositMoneyRequestAndSubmitPacketHelpers.md) rejection, and adjacent raw-helper details.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:92`, still `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank formal C++.
  - Summary/evidence: local PE recheck confirms the accessors operate directly on [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md), documents direct caller sets and receiver loads, records the generated-omitted `0x005b8660` getter and adjacent no-xref signed `0x005b86d0` getter caveat, and finds no standalone constructor/vtable/allocation/type route.
