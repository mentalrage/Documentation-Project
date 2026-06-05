*** UID:000023 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanAppearNameInputDialog

## Status

- Confidence: strong for submit behavior, packet shape, vtable identity, and Clan source ownership; medium for the raw constructor start because IDA still does not model it as a function.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Vtable anchors: primary `0x00615c18`, secondary `0x00615c7c`, tertiary `0x00615cac`
- Rebuild handling: source-authored clan name-input dialog. Attached to [UID:0000I8][Clan](by-file/Clan.md); C++ remains blank because the raw constructor is not an IDA function and the exact class declaration is still below the reconstruction-code gate.

## Class Purpose

`ClanAppearNameInputDialog` sends a clan appearance-name request for the submitted name.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| raw/projected constructor | [UID:0002NZ][0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor](by-memory/0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor.md) `0x004893a0-0x004893d5` | Constructor-shaped bytes; IDA reports no function or inbound xrefs at this start. |
| `OnConfirmInput` | [UID:0002O0][0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName](by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md) `0x004893e0-0x004894ce` | Converts the wide name and sends opcode `0x4b`, subtype `9`, action `1`, length-prefixed name. |

## Evidence Notes

- 2026-06-05 live IDA MCP reports no function object at `0x004893a0`; direct disassembly still shows constructor-shaped bytes ending in `retn 4` at `0x004893d2`.
- The raw constructor pushes its single argument, calls the shared `ClanNameInputDialog` base constructor at `0x004893ad`, and writes primary/secondary/tertiary `ClanAppearNameInputDialog` vtables at `0x004893b2`, `0x004893ba`, and `0x004893c4`.
- 2026-06-05 live IDA MCP reports `sub_4893E0` as a real function at `0x004893e0-0x004894ce`, with the submit callback referenced from vtable slot `0x00615c74`.
- The submitter builds a packet with byte writes for opcode `0x4b`, subtype `9`, and action `1`, converts the submitted wide string through `WideCharToMultiByte`, writes a one-byte name length, copies the converted name through `sub_516220`, then sends through `dword_67A7EC` and `sub_574BB0`.
- The packet body has two length guards: converted name length must stay below `0x100`, and final packet length after the four-byte prefix/name payload must stay below `0x80`; failures call `___report_rangecheckfailure`.
- Live vtable data confirms RTTI at `0x00615c14`, primary destructor slot `0x00615c18 -> sub_48C350`, submit slot `0x00615c74 -> sub_4893E0`, secondary adjustor slot `0x00615c7c -> sub_48C27B`, and tertiary adjustor slot `0x00615cac -> sub_48C286`.
- Xrefs to the three vtable bases come from Clan dialog code at `0x00485284`/`0x0048528a`/`0x00485294`, from `sub_4882D0` at `0x0048833c`/`0x00488342`/`0x0048834c`, and from the raw constructor stores at `0x004893b2`/`0x004893ba`/`0x004893c4`.
- Live IDA still reports no xrefs to the raw constructor start `0x004893a0`, so constructor reachability remains an explicit cap even though the byte body and vtable stores are coherent.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 82 | The page now records the raw constructor body, exact submitter range, packet bytes, conversion/send path, vtable slots, Clan parent ownership, and remaining constructor caveat. |
| Confidence | 86 | Confidence is strong for the submitter, vtable identity, and Clan ownership, with live IDA xrefs tying the class to the Clan dialog family. It is capped below the reconstruction-code threshold because the constructor start is still raw/non-IDA-modeled and has no direct xrefs. |
| Reconstructable | true | The class represents source-authored dialog behavior. C++ remains blank until the raw constructor and class declaration are final enough for the 95/95 gate. |

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md)
- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:00010K][0x00488fe0-0x004895fe.ClanNameDialogSubmitters](by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md)
- [UID:0002NZ][0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor](by-memory/0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor.md)
- [UID:0002O0][0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName](by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md)
- [UID:00002J][ClanNameInputDialog](by-class/ClanNameInputDialog.md)

## Changes

- What existed before: the page documented clan appearance-name submit behavior and projected constructor caveats, but metadata was still `0/0`.
- What it was changed to: scores were set to `68/76`.
- Summary and evidence: the submitter and vtable identity are documented; constructor reachability, sender normalization, and complete layout/header details remain unresolved.
- 2026-05-31: Replaced raw constructor/submitter addresses with exact child `by-memory` pages and corrected the submitter end to exclusive `0x004894ce`. Evidence: IDA MCP `lookup_funcs`, vtable `xrefs_to`, disassembly, and byte audit confirm the raw constructor range `0x004893a0-0x004893d5`, submitter range `0x004893e0-0x004894ce`, and alignment padding around both.
- 2026-06-05 live IDA refinement:
  - What existed before: the page had `72/82` scores, no autogen parent, and only summarized the constructor caveat and submitter.
  - Changed to: scores `82/86`, `AUTOGEN_PARENT_UID:0000I8`, direct live IDA evidence for constructor-shaped bytes, vtable stores/slots, submit packet construction, conversion bounds, and send path.
  - Summary/evidence: completion increased because the page now documents the full submitter behavior, vtable identity, raw constructor body, and parent ownership. Confidence increased because live IDA MCP confirms the exact function range, vtable data refs, packet byte sequence, and Clan-family ownership while preserving the no-function/no-xref raw constructor cap. C++ remains blank because the constructor and class declaration are not 95/95 quality.
