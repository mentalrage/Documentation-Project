*** UID:000023 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ClanAppearNameInputDialog : public ClanNameInputDialog
{
public:
    explicit ClanAppearNameInputDialog(const unsigned char *packet);

protected:
    virtual void OnSubmitText(const wchar_t *text);
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ClanAppearNameInputDialog

## Status

- Confidence: very strong for submit behavior, packet shape, vtable identity, Clan source ownership, declaration shape, and the accepted emitted raw-constructor body; the standalone raw start's absent inbound route remains a bounded entry-confidence caveat only.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Vtable anchors: primary `0x00615c18`, secondary `0x00615c7c`, tertiary `0x00615cac`
- Rebuild handling: source-authored clan appearance-name dialog. Attached to [UID:0000I8][Clan](by-file/Clan.md); class-level C++ emits the `ClanNameInputDialog`-derived shell with `[[CHILDREN]]`. Exact child [UID:0002O0][0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName](by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md) emits `OnSubmitText(const wchar_t *)`, and raw constructor child [UID:0002NZ][0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor](by-memory/0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor.md) emits the exact packet-forwarding constructor definition. Missing raw-start reachability remains a confidence caveat, not no-code proof.

## Class Purpose

`ClanAppearNameInputDialog` sends a clan appearance-name request for the submitted name.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor declaration / raw definition | [UID:0002NZ][0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor](by-memory/0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor.md) `0x004893a0-0x004893d5` | Emits the exact 53-byte packet-forwarding constructor body: it calls `ClanNameInputDialog`, stores vtables `0x00615c18`, `0x00615c7c`, and `0x00615cac`, and returns `this`. No direct start xrefs or pointer hits remain an entry-route confidence caveat only. |
| `OnSubmitText` / appearance request | [UID:0002O0][0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName](by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md) `[0x004893e0,0x004894ce)` | Exact 238-byte virtual submit hook, body SHA256 `FA4958CB9A0E703AE70D84B1A3B2BBEBCAE0C56C54F4E227E9F4417D16C82BD8`, reached only from primary vtable slot `+0x5c` / `0x00615c74`; CP_ACP-converts the submitted name, writes `{0x4b,9,1,length,name...}` with value-first writers, and queues exactly `convertedLength + 4` bytes. |

## UID0002O0 Exact Submitter Evidence

- Identity and boundaries: `[0x004893e0,0x004894ce)` is one modeled `0xee` / 238-byte function. Eleven-byte `[0x004893d5,0x004893e0)` and two-byte `[0x004894ce,0x004894d0)` `0xcc` alignments are excluded.
- Reachability and ABI: exactly one inbound data xref `0x00615c74 -> 0x004893e0` identifies the primary submit slot; zero ordinary callers are expected for virtual dispatch. `ClanNameInputDialog::OnButtonClick` passes the submitted wide string through slot `+0x5c` and consumes no return, supporting `virtual void OnSubmitText(const wchar_t *text);`.
- Frame/source shape: IDA preserves `CHAR[256]` at `+0x8`, five packet fragments at `+0x108..+0x187`, cookie/saved/return rows at `+0x188/+0x18c/+0x190`, and `LPCWCH` at `+0x194`. Human source uses `convertedName[256]`, one contiguous `packet[128]`, and argument `text` without physical row coalescence.
- API and packet: value-first `PacketBufferWriteUInt8` writes opcode `0x4b`, subtype `0x09`, action `0x01`, and the narrowed converted length at `+3`; converted payload begins at `+4`. Exact conversion is `WideCharToMultiByte(CP_ACP, 0, text, wcslen(text), convertedName, 256, NULL, NULL)`.
- Compiler/source shape: the unsigned `0x100` edge protects `convertedName[convertedLength] = 0`; payload copy occurs before the unsigned `0x80` edge protecting `packet[convertedLength + 4] = 0`. Both range-failure calls are compiler instrumentation and are omitted from the formal human-source body.
- Send ownership: caller arrays remain stack-owned and their NULs are outside protocol length. `Socket::QueueAndSendPacket` returns void, copies exactly `convertedLength + 4` bytes into Socket-owned queue storage, adds its own terminator, and posts command `8`.
- Protocol lifecycle: row request `{0x4b,9,0}` requests the appearance dialog; incoming opcode `0x43`, subtype `9`, action/result `0` opens it and nonzero action/result is accepted; UID0002O0 emits the matching subtype-9 action-1 name packet.
- Duplicate and placement: raw `[0x004860e0,0x004861ce)` has matching semantics but no modeled function or route, so it is covered by the live child and does not emit. Direct child owner is this class; file route remains UID0000I8 -> `NexusTK/social/Clan.cpp`.
- The separate raw constructor UID0002NZ remains source-emitting with its missing raw-start route documented as a bounded constructor-entry caveat. That caveat does not weaken this independently vtable-live method.

## Evidence Notes

- 2026-06-05 live IDA MCP reports no function object at `0x004893a0`; `xrefs_to(0x004893a0)` is empty and pointer-byte, immediate, and data-reference searches for `0x004893a0` found no matches.
- Direct disassembly still shows constructor-shaped bytes ending in `retn 4` at `0x004893d2`, followed by eleven `0xcc` bytes before the submitter.
- The raw constructor pushes its single argument, calls the shared `ClanNameInputDialog` base constructor at `0x004893ad`, and writes primary/secondary/tertiary `ClanAppearNameInputDialog` vtables at `0x004893b2`, `0x004893ba`, and `0x004893c4`.
- 2026-06-05 live IDA MCP reports a modeled function at `0x004893e0-0x004894ce`, with the submit callback referenced from vtable slot `0x00615c74` and no direct code callers.
- The submitter writes packet bytes through the byte writer at `0x00575380` for opcode `0x4b`, subtype `9`, action `1`, and converted-name length, converts the submitted wide string through `WideCharToMultiByte`, copies the converted name through `0x00516220`, then sends through `0x00574bb0` using packet sender storage `0x0067a7ec`.
- The packet body has two compiler-instrumented indexed-write guards: `0x100` protects the conversion terminator and post-copy `0x80` protects the packet terminator. The generated runtime calls are binary evidence, not authored source statements.
- 2026-06-17 B001 source-quality recheck maps this method to the shared base submit virtual slot `+0x5c`, inferred/descriptive `OnSubmitText(const wchar_t *text)`. The scratch NUL after the copied payload is outside the counted packet length, and the raw constructor reachability caveat remains class-level only and does not block [UID:0002O0][0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName](by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md) method-body C++.
- 2026-08-10 B006 resolves the shared return type as `void`: the base dispatch ignores a result and every current derived leaf produces no return value. The declaration now resides in formal H and the CPP channel retains child method definitions.
- Live vtable data confirms RTTI at `0x00615c14`, primary destructor slot `0x00615c18 -> 0x0048c350`, submit slot `0x00615c74 -> 0x004893e0`, secondary adjustor slot `0x00615c7c -> 0x0048c27b`, and tertiary adjustor slot `0x00615cac -> 0x0048c286`.
- Xrefs to the three vtable bases come from Clan dialog code at `0x00485284`/`0x0048528a`/`0x00485294`, from the nearby Clan dialog constructor path at `0x0048833c`/`0x00488342`/`0x0048834c`, and from the raw constructor stores at `0x004893b2`/`0x004893ba`/`0x004893c4`.
- Live IDA still reports no xrefs to the raw constructor start `0x004893a0`, so constructor reachability remains an explicit cap even though the byte body and vtable stores are coherent.
- 2026-06-20 B002 local PE recheck of `NexusTK.exe` (2679296 bytes, MD5 `4247e04e20b65d6414c7238aa8ff5515`) reconfirmed constructor bytes at `0x004893a0-0x004893d5`, the `0x35` / 53-byte body, the `0x0b` / 11-byte postpad, zero VA/RVA/raw-offset pointer hits for `0x004893a0`, no direct `.text` relative branch targets to the raw start, one pointer-value hit for submitter `0x004893e0` at vtable slot `0x00615c74`, and active inline construction sequences at `0x0048527f` and `0x00488337` that call `ClanNameInputDialog` and store the same three `ClanAppearNameInputDialog` vtables. Sizes verified with `int_convert.py`.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 93 | The page records the declaration shape, `ClanNameInputDialog` inheritance, owner/emitter route, vtable family, exact constructor/method children, current method hash/bounds/frame/API/compiler/protocol/queue evidence, raw duplicate disposition, and complete CPP/H layering. |
| Confidence | 93 | Submitter behavior, packet/API order, vtable identity, Clan ownership, source declaration, and child emission route are independently strong. The class remains below 95 because the standalone raw constructor is not IDA-modeled and has no direct inbound route, while exact original lexical/access spellings remain inferred. |
| Reconstructable | true | The class represents source-authored dialog behavior and emits through `social/Clan.cpp`; exact child method bodies remain on child pages, including the raw constructor definition. Negative entry-route evidence remains documented without suppressing that definition. |

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md)
- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:00010K][0x00488fe0-0x004895fe.ClanNameDialogSubmitters](by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md)
- [UID:0002NZ][0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor](by-memory/0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor.md)
- [UID:0002O0][0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName](by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md)
- [UID:00002J][ClanNameInputDialog](by-class/ClanNameInputDialog.md)
- [UID:0001HZ][0x00575380-0x00575abb.PacketBufferHelpers](by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md)
- [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md)
- [UID:0001P0][0x0067a7ec-0x0067a7f0.g_packetSender](by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md)

## Changes

The entries below are dated historical changes. Any older statement that the raw constructor did not emit is explicitly superseded by the current UID0002NZ constructor definition and formal H/CPP route above.

- 2026-08-15 B006 UID0002O0 accepted implementation callback:
  - Raised the class from `86/90` to `93/93` while preserving owner/emitter UID0000I8, reconstructable true, `[[CHILDREN]]`, and the C++98-compatible formal H declaration.
  - Added the exact UID0002O0 body hash/boundaries, sole vtable route, void ABI, complete physical-frame/source interpretation, value-first API, conversion and compiler shape, Socket queue ownership, protocol lifecycle, raw duplicate disposition, source route, and retained UID0002NZ constructor caveat.

- 2026-08-10 B006 UID0002NU implementation callback:
  - Changed `virtual int OnSubmitText` to `virtual void OnSubmitText` and moved the class declaration from formal CPP to formal H.
  - Kept `[[CHILDREN]]` in CPP, `86/90`, owner/emitter `0000I8`, reconstructable true, and the active `Clan.cpp` route.

- What existed before: the page documented clan appearance-name submit behavior and projected constructor caveats, but metadata was still `0/0`.
- What it was changed to: scores were set to `68/76`.
- Summary and evidence: the submitter and vtable identity are documented; constructor reachability, sender normalization, and complete layout/header details remain unresolved.
- 2026-05-31: Replaced raw constructor/submitter addresses with exact child `by-memory` pages and corrected the submitter end to exclusive `0x004894ce`. Evidence: IDA MCP `lookup_funcs`, vtable `xrefs_to`, disassembly, and byte audit confirm the raw constructor range `0x004893a0-0x004893d5`, submitter range `0x004893e0-0x004894ce`, and alignment padding around both.
- 2026-06-05 live IDA refinement:
  - What existed before: the page had `72/82` scores, no autogen parent, and only summarized the constructor caveat and submitter.
  - Changed to: scores `82/86`, `AUTOGEN_PARENT_UID:0000I8`, direct live IDA evidence for constructor-shaped bytes, vtable stores/slots, submit packet construction, conversion bounds, and send path.
  - Summary/evidence: completion increased because the page now documents the full submitter behavior, vtable identity, raw constructor body, and parent ownership. Confidence increased because live IDA MCP confirms the exact function range, vtable data refs, packet byte sequence, and Clan-family ownership while preserving the no-function/no-xref raw constructor cap. C++ remains blank because the constructor and class declaration are not 95/95 quality.
- 2026-06-05 A004 child-routing refinement:
  - What existed before: the page was `82/86`, the raw constructor child was still file-parented, the submitter was unassigned, and class evidence still used generated helper/global labels.
  - Changed to: `84/88`, both child pages attached under this class, and evidence rewritten to address/UID-based helper references.
  - Summary/evidence: live IDA reconfirmed no constructor-start xrefs or pointer/immediate/data-reference matches, exact constructor bytes and padding, exact submitter bounds and vtable-only xref, no direct callers, packet bytes `{ 0x4b, 9, 1, converted_length, name_bytes... }`, helper dependencies at `0x00575380`, `0x00516220`, `0x00574bb0`, and packet sender storage `0x0067a7ec`.
- 2026-06-17 B001 Clan submitter source-quality execution:
  - Added the shared `OnSubmitText(const wchar_t *)` submit-slot conclusion, clarified the manual CP_ACP length/payload packet construction, and recorded that class-level constructor/declaration uncertainty does not block the exact submitter child page from emitting first-draft C++.
- 2026-06-20 B002 accepted source-quality implementation:
  - Changed to: `86/90`, owner/emitter unchanged as [UID:0000I8][Clan](by-file/Clan.md), and formal C++ populated with a declaration-only `ClanAppearNameInputDialog : public ClanNameInputDialog` shell plus `[[CHILDREN]]`.
  - Historical conclusion (superseded 2026-08-14): the same bytes, postpad, no-route evidence, inline construction, vtable stores, and submitter slot were previously used to leave the raw constructor no-code. The accepted callback now emits the exact constructor through UID0002NZ and retains those facts only as confidence/corroboration evidence; UID0002O0 continues to emit `OnSubmitText(const wchar_t *)`.
