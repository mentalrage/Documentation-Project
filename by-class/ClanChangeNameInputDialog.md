*** UID:000028 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanChangeNameInputDialog

## Status

- Confidence: strong for submit behavior, packet shape, vtable identity, and Clan source ownership; medium for the raw constructor start because IDA still does not model it as a function.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Vtable anchors: primary `0x00615cb8`, secondary `0x00615d1c`, tertiary `0x00615d4c`
- Rebuild handling: source-authored clan rename dialog. Attached to [UID:0000I8][Clan](by-file/Clan.md); C++ remains blank because the raw constructor has no function object or direct reachability and the exact class declaration is still below the reconstruction-code gate.

## Class Purpose

`ClanChangeNameInputDialog` sends a clan rename packet for the submitted clan name.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| raw constructor-shaped body | [UID:0002O1][0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor](by-memory/0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor.md) `0x004894d0-0x00489505` | Constructor-shaped bytes; IDA reports no function, inbound xrefs, or raw pointer hits at this start. |
| `OnSubmitName` / rename request | [UID:0002O2][0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName](by-memory/0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName.md) `0x00489510-0x004895fe` | Converts the new name and sends opcode `0x4b`, subtype `10`, action `1`, and the length-prefixed name. |

## Evidence Notes

- 2026-06-05 live IDA MCP reports no function object at `0x004894d0`; `xrefs_to(0x004894d0)` is empty and pointer-byte, immediate, and data-reference searches for `0x004894d0` found no matches.
- Direct disassembly still shows constructor-shaped bytes ending in `retn 4` at `0x00489502`, followed by eleven `0xcc` bytes before the submitter.
- The raw constructor pushes its single argument, calls the shared `ClanNameInputDialog` base constructor at `0x004894dd`, and writes primary/secondary/tertiary `ClanChangeNameInputDialog` vtables at `0x004894e2`, `0x004894ea`, and `0x004894f4`.
- 2026-06-05 live IDA MCP reports a modeled function at `0x00489510-0x004895fe`, with the submit callback referenced from vtable slot `0x00615d14` and no direct code callers.
- The submitter writes packet bytes through the byte writer at `0x00575380` for opcode `0x4b`, subtype `10`, action `1`, and converted-name length, converts the submitted wide string through `WideCharToMultiByte`, copies the converted name through `0x00516220`, then sends through `0x00574bb0` using packet sender storage `0x0067a7ec`.
- The packet body has two length guards: converted name length must stay below `0x100`, and final packet length after the four-byte prefix/name payload must stay below `0x80`; failures call `___report_rangecheckfailure`.
- Live vtable data confirms RTTI at `0x00615cb4`, primary destructor slot `0x00615cb8 -> 0x0048c350`, submit slot `0x00615d14 -> 0x00489510`, secondary adjustor slot `0x00615d1c -> 0x0048c27b`, and tertiary adjustor slot `0x00615d4c -> 0x0048c286`.
- Xrefs to the three vtable bases come from Clan dialog code at `0x00485337`/`0x0048533d`/`0x00485347`, from the nearby Clan dialog constructor path at `0x0048842e`/`0x00488434`/`0x0048843e`, and from the raw constructor stores at `0x004894e2`/`0x004894ea`/`0x004894f4`.
- This class is separate from `ClanChangeInputDialog`, which submits the multi-field attribute-change packet through helper `0x00486330`.
- Live IDA still reports no xrefs to the raw constructor start `0x004894d0`, so constructor reachability remains an explicit cap even though the byte body and vtable stores are coherent.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 84 | The page now records the raw constructor body, exact submitter range, packet bytes, conversion/send path, length guards, vtable slots, child parent routing, Clan parent ownership, and remaining constructor caveat. |
| Confidence | 88 | Confidence is strong for the submitter, packet shape, vtable identity, and Clan ownership, with live IDA xrefs tying the class to the Clan dialog family. It is capped below the reconstruction-code threshold because the constructor start is still raw/non-IDA-modeled and has no direct xrefs. |
| Reconstructable | true | The class represents source-authored clan rename behavior. C++ remains blank until the raw constructor and class declaration are final enough for the 95/95 gate. |

## Changes

- 2026-05-27: Corrected `OnSubmitText` range from `0x00489510-0x004895fd` to the exclusive range `0x00489510-0x004895fe`. Evidence: IDA MCP reports a modeled function size of `0xee` at `0x00489510` and two `0xcc` alignment bytes at `0x004895fe-0x00489600`.
- What existed before: the page documented rename submit behavior, vtable identity, range correction, and projected constructor caveat, but metadata was still `0/0`.
- What it was changed to: scores were set to `68/76`.
- Summary and evidence: the submitter and vtable references are documented; constructor reachability and full class/source layout remain unresolved.
- 2026-05-31: Replaced raw constructor/submitter addresses with exact child `by-memory` pages. Evidence: IDA MCP `lookup_funcs`, vtable `xrefs_to`, disassembly, and byte audit confirm the raw constructor range `0x004894d0-0x00489505`, submitter range `0x00489510-0x004895fe`, and alignment padding around both.
- 2026-06-05 live IDA refinement:
  - What existed before: the page had `72/82` scores, no autogen parent, and only summarized the constructor caveat and submitter.
  - Changed to: scores `82/86`, `AUTOGEN_PARENT_UID:0000I8`, direct live IDA evidence for constructor-shaped bytes, vtable stores/slots, submit packet construction, conversion bounds, and send path.
  - Summary/evidence: completion increased because the page now documents the full submitter behavior, vtable identity, raw constructor body, and parent ownership. Confidence increased because live IDA MCP confirms the exact function range, vtable data refs, packet byte sequence, and Clan-family ownership while preserving the no-function/no-xref raw constructor cap. C++ remains blank because the constructor and class declaration are not 95/95 quality.
- 2026-06-05 A004 child-routing refinement:
  - What existed before: the page was `82/86`, the raw constructor child was still file-parented, the submitter was unassigned, and class evidence still used generated helper/global labels.
  - Changed to: `84/88`, both child pages attached under this class, and evidence rewritten to address/UID-based helper references.
  - Summary/evidence: live IDA reconfirmed no constructor-start xrefs or pointer/immediate/data-reference matches, exact constructor bytes and padding, exact submitter bounds and vtable-only xref, no direct callers, packet bytes `{ 0x4b, 10, 1, converted_length, name_bytes... }`, helper dependencies at `0x00575380`, `0x00516220`, `0x00574bb0`, packet sender storage `0x0067a7ec`, and the successor boundary at `0x00489600`.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md)
- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:00010K][0x00488fe0-0x004895fe.ClanNameDialogSubmitters](by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md)
- [UID:0002O1][0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor](by-memory/0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor.md)
- [UID:0002O2][0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName](by-memory/0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName.md)
- [UID:00002J][ClanNameInputDialog](by-class/ClanNameInputDialog.md)
- [UID:000027][ClanChangeInputDialog](by-class/ClanChangeInputDialog.md)
- [UID:00010L][0x00489600-0x00489f80.ClanAttrInputDialogCore](by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md)
- [UID:0001HZ][0x00575380-0x00575abb.PacketBufferHelpers](by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md)
- [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md)
- [UID:0001P0][0x0067a7ec-0x0067a7f0.g_packetSender](by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md)
