*** UID:00002M | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ClanSummonNameInputDialog : public ClanNameInputDialog
{
public:
    explicit ClanSummonNameInputDialog(const unsigned char *packet);

protected:
    virtual void OnSubmitText(const wchar_t *text);
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ClanSummonNameInputDialog

## Status

- Confidence: very strong for submit behavior, packet shape, vtable identity, class ownership, and the current constructor evidence; capped by the raw constructor start because IDA still does not model it as a function or expose direct reachability.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Vtable anchors: primary `0x00615b78`, secondary `0x00615bdc`, tertiary `0x00615c0c`
- Rebuild handling: source-authored clan summon-name dialog attached to [UID:0000I8][Clan](by-file/Clan.md). Formal CPP owns `[[CHILDREN]]`; formal H is source-ready with inheritance, constructor declaration, and `virtual void OnSubmitText(const wchar_t *text);`. Exact child [UID:0002NY][0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName](by-memory/0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName.md) owns the complete method definition. The separate raw-constructor route cap does not make the class declaration or submit method blank.

## Class Purpose

`ClanSummonNameInputDialog` sends a clan summon request for the submitted name.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| raw constructor-shaped body | [UID:0002NX][0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor](by-memory/0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor.md) `0x00489270-0x004892a5` | Constructor-shaped bytes; IDA reports no function, inbound xrefs, or raw pointer hits at this start. |
| `OnSubmitText` / summon request | [UID:0002NY][0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName](by-memory/0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName.md) `0x004892b0-0x0048939e` | Complete 238-byte virtual method, SHA256 `1D266F1D3FD77EFD7D6AD7525CFE09DDDCCD0ABF4CDF52A8C4960B602AEB16A4`, reached only through vtable cell `0x00615bd4`; converts through CP_ACP, writes value-first `{0x4b,8,1,length,name...}`, preserves compiler-instrumented indexed-write order, and sends a counted void Socket queue copy. |

## UID0002NY Submit Method Source-Quality Detail

- Identity and reachability: `[0x004892b0,0x0048939e)` is one modeled 238-byte function with body SHA256 `1D266F1D3FD77EFD7D6AD7525CFE09DDDCCD0ABF4CDF52A8C4960B602AEB16A4`, sole inbound data xref `0x00615bd4 -> 0x004892b0`, and zero ordinary code callers. Primary-vtable base `0x00615b78` places the submit slot at `+0x5c`.
- Source ABI: `void ClanSummonNameInputDialog::OnSubmitText(const wchar_t *text)`. IDA's lowered `void __stdcall(LPCWCH)` and `retn 4` are compatible with an optimized virtual member whose hidden `this` is unused; the base dispatch consumes no result.
- Physical frame: conversion buffer `CHAR[256]` at `+0x8`; contiguous packet fragments at `+0x108/+0x109/+0x10a/+0x10b/+0x10c` with widths `1/1/1/1/0x7c`, forming one 128-byte source packet; cookie row `+0x188`, saved registers `+0x18c`, return address `+0x190`, and `LPCWCH` argument `+0x194` remain distinct physical rows.
- API and conversion: `PacketBufferWriteUInt8` is value first and returns void. The exact conversion is `WideCharToMultiByte(CP_ACP, 0, text, wcslen(text), convertedName, 256, NULL, NULL)`, followed by `convertedName[convertedLength] = 0`, one-byte length serialization, and `memmove(packet + 4, convertedName, convertedLength)`.
- Compiler/source distinction: the unsigned `0x100` branch protects the conversion-buffer indexed terminator. Payload copy occurs before the unsigned `0x80` branch protecting `packet[convertedLength + 4] = 0`. Both range-failure edges are compiler instrumentation, not explicit developer-source calls; source preserves the indexed writes and observed order.
- Socket ownership: `g_packetSender` is source-facing `Socket *`. `Socket::QueueAndSendPacket(const void *, short)` returns void, copies exactly `convertedLength + 4` bytes into Socket-owned queue storage, adds its own separate terminator, and dispatches command `8`.
- Protocol lifecycle: status row `9` sends `{0x4b,8,0}`; inbound opcode `0x43`, subtype `8`, action/result `0` opens this dialog and action/result `1` is accepted; this override sends matching action `1` with one-byte converted-name length and payload.
- Source placement: the method definition remains on the exact child through this class and [UID:0000I8][Clan](by-file/Clan.md) -> `social/Clan.cpp`. [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md) is a non-standalone, non-emitting family/index rather than an active coordinated split destination.

## Evidence Notes

- 2026-06-05 live IDA MCP reports no function object at `0x00489270`; `xrefs_to(0x00489270)` is empty and pointer-byte, immediate, and data-reference searches for `0x00489270` found no matches.
- Direct disassembly still shows constructor-shaped bytes ending in `retn 4` at `0x004892a2`, followed by eleven `0xcc` bytes before the submitter.
- The raw constructor pushes its single argument, calls the shared `ClanNameInputDialog` base constructor at `0x0048927d`, and writes primary/secondary/tertiary `ClanSummonNameInputDialog` vtables at `0x00489282`, `0x0048928a`, and `0x00489294`.
- 2026-08-11 live MCP revalidation reports the modeled function at `0x004892b0-0x0048939e`, body hash and frame recorded above, submit callback referenced from vtable slot `0x00615bd4`, and no direct code callers.
- The submitter writes packet bytes through value-first byte writer `0x00575380` for opcode `0x4b`, subtype `8`, action `1`, and converted-name length, converts the submitted wide string through `WideCharToMultiByte`, copies the converted name through `0x00516220`, then invokes void queue helper `0x00574bb0` through Socket-owned sender storage `0x0067a7ec`.
- Historical docs described the two range checks as authored failure branches. Current target-specific reanalysis establishes them as compiler instrumentation around `convertedName[convertedLength] = 0` and the post-copy `packet[convertedLength + 4] = 0`; formal source does not call `__report_rangecheckfailure` explicitly.
- 2026-06-17 B001 source-quality recheck maps this method to the shared base submit virtual slot `+0x5c`, inferred/descriptive `OnSubmitText(const wchar_t *text)`. The scratch NUL after the copied payload is outside the counted packet length, and the raw constructor reachability caveat remains class-level only and does not block [UID:0002NY][0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName](by-memory/0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName.md) method-body C++.
- 2026-08-10 B006 resolves the shared return type as `void`: the base dispatch ignores a result and every current derived leaf produces no return value. The declaration now resides in formal H and the CPP channel retains child method definitions.
- Live vtable data confirms RTTI at `0x00615b74`, primary destructor slot `0x00615b78 -> 0x0048c350`, submit slot `0x00615bd4 -> 0x004892b0`, secondary adjustor slot `0x00615bdc -> 0x0048c27b`, and tertiary adjustor slot `0x00615c0c -> 0x0048c286`.
- Xrefs to the three vtable bases come from Clan dialog code at `0x0048522c`/`0x00485232`/`0x0048523c`, from nearby Clan dialog constructor code at `0x00488294`/`0x0048829a`/`0x004882a4`, and from the raw constructor stores at `0x00489282`/`0x0048928a`/`0x00489294`.
- Live IDA still reports no xrefs to the raw constructor start `0x00489270`, so constructor reachability remains an explicit cap even though the byte body, submitter, packet shape, and vtable identity are coherent.
- Historical 2026-06-15 Wave2 output described `0x00489270` as a 53-byte constructor record and listed the raw constructor plus `0x004892b0` submitter. Wave2/Wave3 is no longer current authority; the retained historical result is useful only where it agrees with current raw bytes, live IDA, vtables, and current by-* documentation.
- 2026-06-15 live IDA MCP recheck on database `b001_chatting_source_quality_20260615` reconfirmed no function at `0x00489270` / `0x004892a5`, no xrefs to `0x00489270`, exact body bytes and `align 10h` padding, and vtable-store xrefs from `0x0048522c`/`0x00485232`/`0x0048523c`, `0x00488294`/`0x0048829a`/`0x004882a4`, and the raw body.
- 2026-06-15 modeled opener disassembly shows `0x00485227` and `0x0048828f` call the shared base constructor, then inline the same three `ClanSummonNameInputDialog` vtable stores. A local PE scan found zero absolute VA hits, zero RVA hits, and zero direct relative branch/call targets to `0x00489270`, so the raw body remains unproven as a live entry.
- 2026-06-22 B001 Rule 26 source-placement recheck keeps [UID:0002NX][0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor](by-memory/0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor.md) as retained source-authored constructor evidence rather than ignored, dead duplicate, or compiler-glue bytes. The direct semantic owner remains this class; [UID:0000I8][Clan](by-file/Clan.md) remains the current file route and [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md) remains only a coordinated split candidate. Its historical “class-level C++ blank” wording is superseded: current formal CPP routes `[[CHILDREN]]`, formal H owns the source-ready declaration, and only a standalone raw-constructor definition remains withheld.

- 2026-08-14 current correction: the preceding 2026-06-22 split-candidate and withheld-constructor conclusions are historical. UID0000IA now serves only as a non-standalone family/index with path/owner `NONE`; UID0000I8 remains the source owner. UID0002NX emits the exact delegating constructor, formal H owns this class declaration, formal CPP routes `[[CHILDREN]]`, and UID0002NY emits the submitter. The absent raw-entry route remains a confidence caveat without suppressing executable source bytes.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 85 | The page records the raw constructor body/caveat, source-ready class H, exact submitter range/hash/xref/ABI/frame/API/guard/Socket/protocol evidence, vtable slots, inline construction sites, child routing, and Clan source placement. |
| Confidence | 89 | Confidence is very strong for the constructor source shape, submitter, packet behavior, declaration, vtable identity, and Clan ownership from current live IDA and documentation. It remains capped because the retained raw constructor start is non-modeled and has no direct entry route. |
| Reconstructable | true | The class is source-authored. Formal H owns the class declaration, formal CPP routes exact child definitions, UID0002NX emits the delegating constructor, and UID0002NY emits the complete submit body. |

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md)
- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:00010K][0x00488fe0-0x004895fe.ClanNameDialogSubmitters](by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md)
- [UID:0002NX][0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor](by-memory/0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor.md)
- [UID:0002NY][0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName](by-memory/0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName.md)
- [UID:00002J][ClanNameInputDialog](by-class/ClanNameInputDialog.md)
- [UID:0001HZ][0x00575380-0x00575abb.PacketBufferHelpers](by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md)
- [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md)
- [UID:0001P0][0x0067a7ec-0x0067a7f0.g_packetSender](by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md)

## Changes

- 2026-08-11 B004 UID0002NY implementation callback:
  - Retained `85/89`, owner/emitter UID0000I8, reconstructable true, formal `[[CHILDREN]]`, and the class formal H declaration.
  - Corrected stale prose that called the declaration/class C++ blank and added the exact submit method range/hash/xref/ABI/frame/API/compiler-guard/Socket/protocol/source-route evidence without duplicating the child definition.
  - Historicalized Wave2 as non-authoritative legacy evidence and narrowed the remaining class cap to the separate raw-constructor route and coordinated file-split uncertainty.

- 2026-08-10 B006 UID0002NU implementation callback:
  - Changed `virtual int OnSubmitText` to `virtual void OnSubmitText` and moved the class declaration from formal CPP to formal H.
  - Kept `[[CHILDREN]]` in CPP, `85/89`, owner/emitter `0000I8`, reconstructable true, and the active `Clan.cpp` route.

- 2026-06-15 A001 Goal 2 owner/source-quality refresh:
  - What existed before: `84/88`, with older constructor caveats and class routing.
  - Changed to: `85/89`, keeping [UID:0000I8][Clan](by-file/Clan.md) as canonical owner/emitter and final C++ blank.
  - Historical summary/evidence, superseded as current authority: Wave2 then described the raw constructor and submitter as the local method surface and recorded the constructor as size `0x35` / 53 bytes with zero callers. Live IDA and local PE checks remain valid for the no-function/no-route raw start and inline construction sites. At that stage class source was described as blank; the 2026-08-10 and 2026-08-11 callbacks supersede that conclusion with source-ready formal H, `[[CHILDREN]]`, and the exact submit child definition while retaining only the standalone-constructor cap.
- What existed before: the page documented summon submit behavior, vtable identity, and projected constructor caveats, but metadata was still `0/0`.
- What it was changed to: scores were set to `68/76`.
- Summary and evidence: submitter behavior is IDA-backed and vtable-linked; projected constructor reachability and full class layout remain unresolved.
- 2026-05-31: Replaced raw constructor/submitter addresses with exact child `by-memory` pages and corrected the submitter end to exclusive `0x0048939e`. Evidence: IDA MCP `lookup_funcs`, vtable `xrefs_to`, disassembly, and byte audit confirm the raw constructor range `0x00489270-0x004892a5`, submitter range `0x004892b0-0x0048939e`, and alignment padding around both.
- 2026-06-05 live IDA refinement:
  - What existed before: the page had `72/82` scores, no autogen parent, and only summarized the constructor caveat and submitter.
  - Changed to: scores `82/86`, `AUTOGEN_PARENT_UID:0000I8`, direct live IDA evidence for constructor-shaped bytes, vtable stores/slots, submit packet construction, conversion bounds, and send path.
  - Summary/evidence: completion increased because the page now documents the full submitter behavior, vtable identity, raw constructor body, and parent ownership. Confidence increased because live IDA MCP confirms the exact function range, vtable data refs, packet byte sequence, bounds checks, and Clan-family ownership while preserving the no-function/no-xref raw constructor cap. C++ remains blank because the constructor and class declaration are not 95/95 quality.
- 2026-06-05 A004 child-routing refinement:
  - What existed before: the page was `82/86`, the raw constructor child was still file-parented, the submitter was unassigned, and class evidence still used generated helper/global labels.
  - Changed to: `84/88`, both child pages attached under this class, and evidence rewritten to address/UID-based helper references.
  - Summary/evidence: live IDA reconfirmed no constructor-start xrefs or pointer/immediate/data-reference matches, exact constructor bytes and padding, exact submitter bounds and vtable-only xref, no direct callers, packet bytes `{ 0x4b, 8, 1, converted_length, name_bytes... }`, helper dependencies at `0x00575380`, `0x00516220`, `0x00574bb0`, and packet sender storage `0x0067a7ec`.
- 2026-06-17 B001 Clan submitter source-quality execution:
  - Added the shared `OnSubmitText(const wchar_t *)` submit-slot conclusion, clarified the manual CP_ACP length/payload packet construction, and recorded that class-level constructor/declaration uncertainty does not block the exact submitter child page from emitting first-draft C++.
- 2026-06-22 B001 Rule 26 source-placement closeout:
  - Added the retained raw-constructor policy for [UID:0002NX][0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor](by-memory/0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor.md): keep class ownership and `social/Clan.cpp` routing, reject ignored/dead/duplicate-only classification, and keep class-level C++ blank until raw-start reachability and final source placement are proven.
