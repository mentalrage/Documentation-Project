*** UID:0000I4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NONE" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# CharacterSummaryRecord

## Status

- Confidence: strong that this is not a standalone original source file.
- Current recovered source: `source-3/simroot_v2/class_CharacterSummaryRecord.cpp`
- Correct owner file: [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- Correct memory owner: [UID:0001NM][0x005b83b0-0x005baafe.UserStatusPane](by-memory/0x005b83b0-0x005baafe.UserStatusPane.md)
- Exact accessor island: [UID:0001NN][0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md)
- Related layout: [UID:0001WF][UserStatusPaneSummaryFields](by-type/by-struct/UserStatusPaneSummaryFields.md)

## File Decision

Do not create a separate original `CharacterSummaryRecord.cpp` file from this generated output. The emitted methods are accessors and setters for the newer [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md) object tail.

`CharacterSummaryRecord` appears to be a Wave2/Wave3 recovery abstraction over the receiver stored in `DAT_0069ae0c`. IDA confirms that address is the live `UserStatusPane` singleton `g_activeUserStatusPane`, and the surrounding constructor at `0x005b83b0` installs `UserStatusPane` vtables before initializing the exact fields used by these accessors.

B004's 2026-06-20 local PE recheck strengthens the negative file-placement decision: the methods are direct `UserStatusPane` accessors, all representative receivers are the active pointer at `0x0069ae0c`, there is no constructor/destructor/vtable/allocation/RTTI/COL/source-root evidence for a standalone record, and the generated file omits the real `0x005b8660` sibling getter.

## Emitted Methods

| Emitted method | Address | Correct owner |
| --- | --- | --- |
| `CopyNameLineA` | `0x005b85b0-0x005b85cb` | `UserStatusPane` title/name line copy helper. |
| `CopyNameLineB` | `0x005b85d0-0x005b85eb` | `UserStatusPane` secondary/status line copy helper. |
| `GetPercentStatA` | `0x005b85f0-0x005b85f6` | `UserStatusPane` byte-field getter. |
| `GetPercentStatB` | `0x005b8600-0x005b8606` | `UserStatusPane` byte-field getter. |
| `GetPercentStatC` | `0x005b8610-0x005b8616` | `UserStatusPane` byte-field getter. |
| `GetNationId` | `0x005b8620-0x005b8626` | `UserStatusPane` nation id getter. |
| `GetSpiritId` | `0x005b8630-0x005b8636` | `UserStatusPane` spirit/totem id getter. |
| `GetDisplayValueA` | `0x005b8640-0x005b8646` | `UserStatusPane` dword-field getter. |
| `GetDisplayValueB` | `0x005b8650-0x005b8656` | `UserStatusPane` dword-field getter. |
| omitted sibling | `0x005b8660-0x005b8666` | `UserStatusPane` third dword-field getter; missing from `class_CharacterSummaryRecord.cpp`. |
| `SetDisplayLineA` | `0x005b8670-0x005b8699` | `UserStatusPane` display-line setter plus invalidation callback. |
| `SetDisplayLineB` | `0x005b86a0-0x005b86c9` | `UserStatusPane` display-line setter plus invalidation callback. |

## 2026-06-20 B004 File-Placement Recheck

The report-only recheck used local PE disassembly because IDA MCP was unavailable. The checked executable was `NexusTK.exe`, size `2679296`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, image base `0x00400000`.

Constructor and singleton facts still place the code under `UserStatusPane.cpp`: `0x005b83b0-0x005b8526` stores `this` to `0x0069ae0c` at `0x005b83fa`, has a null-adjustment store at `0x005b8401`, installs `UserStatusPane` vtables at complete offsets `+0x00/+0xa0/+0xa4`, loads `9X11FONT.BIN`, copies the incoming name to `+0x0fc`, clears new-layout text lines at `+0x17c/+0x1fc`, sets summary-tail defaults through `+0x2a4`, and is called locally from `InitializeMainUiGraph` at `0x004f837a`.

Representative call sites load `g_activeUserStatusPane` as the receiver before accessor calls: `0x004a1e0a`, `0x004acb0c`, `0x00567f91`, `0x00571946`, `0x00567ca8`, `0x0059be23`, `0x0059d31c`, `0x00567dfe`, `0x00565a27`, `0x00570270`, `0x00565b28`, `0x00570371`, and `0x005aad5f`. Local scans found no record-pointer receiver setup, no embedded subobject address route, and no absolute pointer refs to `0x005b8660`.

The adjacent raw helper at `0x005b86d0-0x005b86d8` is separate from the generated file and from [UID:0001NN][0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md). It disassembles as a no-xref signed getter for `+0x27e`, surrounded by `0xcc` alignment at `0x005b86ca-0x005b86d0` and `0x005b86d8-0x005b86e0`. It is a future exact-child/split caveat for `UserStatusPane`, not a reason to create `CharacterSummaryRecord.cpp`.

## Evidence Notes

- IDA decompilation of `0x005b83b0` shows the real `UserStatusPane` constructor storing `dword_69AE0C = this`, installing three `UserStatusPane` vtables, loading `9X11FONT.BIN`, and initializing fields at `+0x0fc`, `+0x17c`, `+0x1fc`, and `+0x27c` onward.
- IDA decompilation of the generated `CharacterSummaryRecord` methods reads/writes offsets inside that same `UserStatusPane` object.
- IDA callers include `ExchangeDialog`, `SelfLookPane`, `SelfLookPane2`, `AddItemDialog`, and status-pane update paths, but the receiver is still `g_activeUserStatusPane`, not a separate record allocation.
- Existing [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md) docs already place `0x005b85b0-0x005b86ca` in `UserStatusPane.cpp`.
- B004 rejected stale assignment text mentioning [UID:00021I][0x00485780-0x00485867.ClanDepositMoneyRequestAndSubmitPacketHelpers](by-memory/0x00485780-0x00485867.ClanDepositMoneyRequestAndSubmitPacketHelpers.md): that UID is a Clan deposit-money packet helper cluster and has no relationship to this file-placement decision.

## Source-Structure Decision

Fold this generated file into `ui/panels/UserStatusPane.cpp`. If a separate type name is useful during rewrite, model it as a private field-layout helper or comment block such as `UserStatusPaneSummaryFields`, not as an independently allocated class or source module.

## Cross-References

- [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md)
- [UID:0001NM][0x005b83b0-0x005baafe.UserStatusPane](by-memory/0x005b83b0-0x005baafe.UserStatusPane.md)
- [UID:0001NN][0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md)
- [UID:0001WF][UserStatusPaneSummaryFields](by-type/by-struct/UserStatusPaneSummaryFields.md)
- [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-06-05: Marked the projected reconstruction path as `NONE`.
  - Before: the path was blank, so the validator treated this reviewed generated accessor alias as a missing by-file generated root.
  - After: the page is an explicit non-standalone disposition; the accessor island remains folded into [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md).
  - Evidence: live IDA MCP `lookup_funcs` confirms the accessor island at `0x005b85b0` (`0x1c` bytes) and the adjacent `UserStatusPane` constructor/core at `0x005b83b0` (`0x176` bytes), matching the existing `g_activeUserStatusPane` ownership notes.
- 2026-05-30: Grading changed from `0/0` to `86/90`.
  - Before: page documented that this generated file is not a standalone original source file but remained unevaluated.
  - After: score reflects strong negative placement evidence: the emitted accessors/setters are assigned to [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md), with exact memory/type/global anchors and generated-abstraction caveats.
  - Evidence: IDA decompilation ties the methods and `DAT_0069ae0c` receiver to `UserStatusPane` construction/vtables and `g_activeUserStatusPane`; the exact accessor island and layout are cross-linked.
- 2026-06-20 B004 source-routing incorporation:
  - What existed before: the page already set `PROPOSED_RECONSTRUCTION_PATH:"NONE"` but lacked the current local PE negative-source-root proof.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:92`, still `PROPOSED_RECONSTRUCTION_PATH:"NONE"` and `CANONICAL_OWNER:NONE`.
  - Summary/evidence: local PE receiver/caller scan, constructor/singleton writes, omitted `0x005b8660` getter, adjacent no-route signed `0x005b86d0` getter caveat, and no standalone type/lifetime evidence confirm the generated file must fold into [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md).
