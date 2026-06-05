*** UID:00002O | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanWidMoneyInputDialog

## Status

- Confidence: strong for submit behavior, packet shape, vtable identity, and Clan source ownership; medium for the raw constructor start because IDA still does not model it as a function.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Vtable anchors: primary `0x00615a38`, secondary `0x00615a9c`, tertiary `0x00615acc`
- Rebuild handling: source-authored clan-bank withdraw dialog. Attached to [UID:0000I8][Clan](by-file/Clan.md); C++ remains blank because the raw constructor has no function object or direct reachability and the class declaration is still below the reconstruction-code gate.

## Class Purpose

`ClanWidMoneyInputDialog` is a `ClanNameInputDialog` variant that sends clan-bank withdrawal requests.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| raw/projected constructor | [UID:0002NT][0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor](by-memory/0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor.md) `0x00489070-0x004890a5` | Constructor-shaped bytes; IDA reports no function, inbound xrefs, or raw pointer hits at this start. |
| `OnSubmitText` / withdraw request | [UID:0002NU][0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney](by-memory/0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney.md) `0x004890b0-0x00489132` | Converts the input amount and sends opcode `0x4b`, subtype `0x0b`, action `1`, and the amount. |

## Evidence Notes

- 2026-06-05 live IDA MCP reports no function object at `0x00489070`; `xrefs_to(0x00489070)` is empty and a little-endian pointer-byte search for `0x00489070` found no matches.
- Direct disassembly still shows constructor-shaped bytes ending in `retn 4` at `0x004890a2`.
- The raw constructor pushes its single argument, calls the shared `ClanNameInputDialog` base constructor `sub_488B40` at `0x0048907d`, and writes primary/secondary/tertiary `ClanWidMoneyInputDialog` vtables at `0x00489082`, `0x0048908a`, and `0x00489094`.
- 2026-06-05 live IDA MCP reports `sub_4890B0` as a real function at `0x004890b0-0x00489132`, with the submit callback referenced from vtable slot `0x00615a94`.
- The submitter converts the submitted text with the CRT conversion helper that IDA labels `unknown_libname_24`, writes packet bytes through `sub_575380` for opcode `0x4b`, subtype `0x0b`, and action `1`, writes the four-byte amount through `sub_5753F0`, then sends seven bytes through `dword_67A7EC` and `sub_574BB0`.
- Live vtable data confirms RTTI at `0x00615a34`, primary destructor slot `0x00615a38 -> sub_48C350`, submit slot `0x00615a94 -> sub_4890B0`, secondary adjustor slot `0x00615a9c -> sub_48C27B`, and tertiary adjustor slot `0x00615acc -> sub_48C286`.
- Xrefs to the three vtable bases come from Clan dialog code at `0x00485398`/`0x0048539e`/`0x004853a8`, from `sub_488460` at `0x004884d4`/`0x004884da`/`0x004884e4`, and from the raw constructor stores at `0x00489082`/`0x0048908a`/`0x00489094`.
- Live IDA still reports no xrefs to the raw constructor start `0x00489070`, so constructor reachability remains an explicit cap even though the byte body, submitter, packet shape, and vtable identity are coherent.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 82 | The page now records the raw constructor body, exact submitter range, packet bytes, conversion/send path, vtable slots, Clan parent ownership, and remaining constructor caveat. |
| Confidence | 86 | Confidence is strong for the submitter, packet shape, vtable identity, and Clan ownership, with live IDA xrefs tying the class to the Clan dialog family. It is capped below the reconstruction-code threshold because the constructor start is still raw/non-IDA-modeled and has no direct xrefs. |
| Reconstructable | true | The class represents source-authored clan-bank withdraw behavior. C++ remains blank until the raw constructor and class declaration are final enough for the 95/95 gate. |

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md)
- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:00010K][0x00488fe0-0x004895fe.ClanNameDialogSubmitters](by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md)
- [UID:0002NT][0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor](by-memory/0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor.md)
- [UID:0002NU][0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney](by-memory/0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney.md)
- [UID:00002J][ClanNameInputDialog](by-class/ClanNameInputDialog.md)

## Changes

- What existed before: the page documented withdraw-money submit behavior, vtable identity, and projected constructor caveats, but metadata was still `0/0`.
- What it was changed to: scores were set to `68/76`.
- Summary and evidence: the submitter and vtable references are documented; projected constructor reachability and final layout/source placement remain unresolved.
- 2026-05-31: Replaced raw constructor/submitter addresses with exact child `by-memory` pages and corrected the submitter end to exclusive `0x00489132`. Evidence: IDA MCP `lookup_funcs`, vtable `xrefs_to`, disassembly, and byte audit confirm the raw constructor range `0x00489070-0x004890a5`, submitter range `0x004890b0-0x00489132`, and alignment padding around both.
- 2026-06-05 live IDA refinement:
  - What existed before: the page had `72/82` scores, no autogen parent, and only summarized the constructor caveat and submitter.
  - Changed to: scores `82/86`, `AUTOGEN_PARENT_UID:0000I8`, direct live IDA evidence for constructor-shaped bytes, vtable stores/slots, submit packet construction, conversion path, and send path.
  - Summary/evidence: completion increased because the page now documents the full submitter behavior, vtable identity, raw constructor body, and parent ownership. Confidence increased because live IDA MCP confirms the exact function range, vtable data refs, packet byte sequence, and Clan-family ownership while preserving the no-function/no-xref raw constructor cap. C++ remains blank because the constructor and class declaration are not 95/95 quality.
