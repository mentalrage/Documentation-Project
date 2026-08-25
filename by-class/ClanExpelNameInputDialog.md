*** UID:00002D | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ClanExpelNameInputDialog : public ClanNameInputDialog
{
public:
    explicit ClanExpelNameInputDialog(const unsigned char *packet);

    virtual void OnSubmitText(const wchar_t *text);
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ClanExpelNameInputDialog

## Status

- Confidence: very strong for the class declaration, submit behavior, packet shape, vtable identity, and Clan source ownership; the remaining raw-constructor no-route caveat stays scoped to [UID:0002NV][0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor](by-memory/0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor.md).
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Vtable anchors: primary `0x00615ad8`, secondary `0x00615b3c`, tertiary `0x00615b6c`
- Rebuild handling: source-authored clan expel-name dialog attached to [UID:0000I8][Clan](by-file/Clan.md). Formal H owns the class declaration and CPP routes `[[CHILDREN]]`; [UID:0002NV][0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor](by-memory/0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor.md) emits the exact delegating constructor and [UID:0002NW][0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName](by-memory/0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName.md) emits `OnSubmitText(const wchar_t *)`. The constructor start's absent direct route remains a confidence caveat, not a no-code/covered-by disposition. [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md) remains documentation-only and non-emitting.

## Class Purpose

`ClanExpelNameInputDialog` sends a clan expel request for the submitted player name.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| raw constructor-shaped body | [UID:0002NV][0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor](by-memory/0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor.md) `0x00489140-0x00489175` | Constructor-shaped executable bytes with an exact formal delegating-constructor definition; current MCP/PE checks report no function, inbound xrefs, VA/RVA pointer hits, or direct branch route at this start, which constrains entry-route confidence but not source emission. |
| `OnSubmitText` / expel request | [UID:0002NW][0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName](by-memory/0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName.md) `[0x00489180,0x0048926e)` | Exact 238-byte virtual method, SHA256 `F9B98A095B139B15F5190B630B2C9E93E4F681B55CA3F369E6AA5136B43DDDDE`; value-first byte writers build `{0x4b,7,1,length,name...}`, exact CP_ACP conversion produces the payload, indexed source writes account for both compiler guards, and the void queue helper copies the counted bytes. |

## Evidence Notes

- 2026-06-21 B011 raw PE/Capstone source-quality recheck reconfirms `0x00489140-0x00489175` as a retained constructor-shaped body: it calls [UID:00010J][0x00488b40-0x00488fa0.ClanNameInputDialogCore](by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md), stores primary/secondary/tertiary vtables `0x00615ad8`, `0x00615b3c`, and `0x00615b6c`, returns with `ret 4`, is preceded by `0x00489132-0x00489140` `cc` padding, and is followed by `0x00489175-0x00489180` `cc` padding before the submitter.
- The same B011 scan found zero loaded-VA dword references to `0x00489140`, zero RVA dword references to `0x00089140`, and zero direct relative branch/call encodings to the raw constructor start. Current IDA-backed docs also still record no function object or xrefs for `0x00489140`.
- 2026-06-29 B001 implementation callback rechecked the accepted no-code disposition against MCP session `3fa0535f` and a local PE scan: `lookup_funcs(0x00489140)` and `lookup_funcs(0x00489175)` return `Not a function`, `xrefs_to(0x00489140)` returns zero inbound xrefs, `find_bytes` finds no loaded-VA or RVA pointer encodings for `0x00489140`, local PE scanning finds no VA/RVA/direct-branch route, and vtable xrefs still pair the raw stores at `0x00489152/0x0048915a/0x00489164` with live inline stores at `0x004851cb/0x004851d1/0x004851db` and `0x004881e4/0x004881ea/0x004881f4`.
- Active construction sites at `0x004851c6` and `0x004881df` inline the source-level construction operation: call the `ClanNameInputDialog` base constructor, then install the same `ClanExpelNameInputDialog` vtables at `this+0`, `this+0xa0`, and `this+0xa4`. This proves the source class and constructor declaration even though the retained raw constructor body itself has no proven live entry route.
- The inline allocation/open path contains allocation size `0x26c`, matching inherited `ClanNameInputDialog` storage. No expel-specific persistent fields are evidenced beyond the inherited layout and the derived primary/secondary/tertiary vtable views.
- Vtable slot `0x00615b34 -> 0x00489180` identifies [UID:0002NW][0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName](by-memory/0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName.md) as the `OnSubmitText(const wchar_t *)` override. The source-facing method name should stay `OnSubmitText`; `SubmitName` is only a descriptive binary/file-name alias.
- 2026-06-05 live IDA MCP reports no function object at `0x00489140`; `xrefs_to(0x00489140)` is empty and pointer-byte, immediate, and data-reference searches for `0x00489140` found no matches.
- Direct disassembly still shows constructor-shaped bytes ending in `retn 4` at `0x00489172`, followed by eleven `0xcc` bytes before the submitter.
- The raw constructor pushes its single argument, calls the shared `ClanNameInputDialog` base constructor at `0x0048914d`, and writes primary/secondary/tertiary `ClanExpelNameInputDialog` vtables at `0x00489152`, `0x0048915a`, and `0x00489164`.
- 2026-06-05 live IDA MCP reports a modeled function at `0x00489180-0x0048926e`, with the submit callback referenced from vtable slot `0x00615b34` and no direct code callers.
- The submitter writes packet bytes through the value-first byte writer at `0x00575380` for opcode `0x4b`, subtype `7`, action `1`, and converted-name length. Current helper type/body plus cdecl push order prove `PacketBufferWriteUInt8(value, destination)`, correcting the older destination-first assumption.
- The conversion is exactly `WideCharToMultiByte(CP_ACP, 0, text, wcslen(text), convertedName, 256, NULL, NULL)`. It uses an explicit source length excluding the wide terminator, a 256-byte caller stack destination, and no default-character pointers.
- The observed unsigned `0x100` branch protects developer-source write `convertedName[convertedLength] = 0`. The converted length is then written at packet offset `+3`, and `memmove` copies the payload to offset `+4` before the second branch.
- The observed unsigned `0x80` branch occurs after the payload copy and protects developer-source write `packet[convertedLength + 4] = 0`. Both range-failure calls are compiler instrumentation regenerated from the indexed writes under matching build settings, not explicit developer-authored calls in the reconstructed method.
- The source arrays are one `char convertedName[256]` and one contiguous `unsigned char packet[128]`. IDA's one-byte packet header rows plus 124-byte payload row are physical frame fragments, not separate source buffers.
- `Socket::QueueAndSendPacket` returns `void`, copies exactly `convertedLength + 4` caller bytes into Socket-owned queue storage, appends its own NUL to the copy, and does not take ownership of either caller stack array. Historical returned-result wording is contradicted.
- 2026-06-17 B001 source-quality recheck maps this method to the shared base submit virtual slot `+0x5c`, inferred/descriptive `OnSubmitText(const wchar_t *text)`. The scratch NUL after the copied payload is outside the counted packet length, and the raw constructor reachability caveat remains class-level only and does not block [UID:0002NW][0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName](by-memory/0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName.md) method-body C++.
- The outgoing row-action request is `{0x4b,7,0}`. Incoming opcode `0x43`, subtype `7`, action/result `0` opens this dialog, while action/result `1` is the accepted path. `OnSubmitText` sends the matching action-1 packet.
- IDA's lowered `void __stdcall(LPCWCH)` presentation is an unused-`this` optimization artifact. The sole vtable slot, base virtual dispatch, sibling leaves, `retn 4`, and ignored return prove the source ABI `virtual void OnSubmitText(const wchar_t *text)` already present in the formal H declaration.
- Live vtable data confirms RTTI at `0x00615ad4`, primary destructor slot `0x00615ad8 -> 0x0048c350`, submit slot `0x00615b34 -> 0x00489180`, secondary adjustor slot `0x00615b3c -> 0x0048c27b`, and tertiary adjustor slot `0x00615b6c -> 0x0048c286`.
- Xrefs to the three vtable bases come from Clan dialog code at `0x004851cb`/`0x004851d1`/`0x004851db`, from the function range beginning at `0x00488170` at `0x004881e4`/`0x004881ea`/`0x004881f4`, and from the raw constructor stores at `0x00489152`/`0x0048915a`/`0x00489164`.
- Live IDA still reports no xrefs to the raw constructor start `0x00489140`. That remains a direct-entry confidence caveat, while the retained body, base-constructor call, three vtable stores, return-this behavior, and `ret 4` establish the exact out-of-line constructor source definition emitted by [UID:0002NV][0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor](by-memory/0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor.md).

## Source Declaration And Caveats

The best current source-facing class shape is:

```cpp
class ClanExpelNameInputDialog : public ClanNameInputDialog
{
public:
    explicit ClanExpelNameInputDialog(const unsigned char *packet);

    virtual void OnSubmitText(const wchar_t *text);
};
```

The constructor source shape is also high-confidence:

```cpp
ClanExpelNameInputDialog::ClanExpelNameInputDialog(const unsigned char *packet)
    : ClanNameInputDialog(packet)
{
}
```

The retained constructor body is an emitted child definition even though no direct caller/table route to `0x00489140` survives. The active open sites inline the equivalent construction, while the retained out-of-line bytes independently require the same source constructor. [UID:00002D] emits the declaration, [UID:0002NV][0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor](by-memory/0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor.md) emits the constructor, and [UID:0002NW][0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName](by-memory/0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName.md) emits the submitter. Remaining caveats are scoped to exact lexical spelling and the absent raw-entry route; [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md) is a non-standalone index rather than a future `ClanDialogs.cpp` source owner.

## UID0002NW Exact Method Evidence

- Body identity: exact modeled range `[0x00489180,0x0048926e)`, 238 bytes, SHA256 `F9B98A095B139B15F5190B630B2C9E93E4F681B55CA3F369E6AA5136B43DDDDE`; the two following bytes are separate `cc cc` alignment before raw UID0002NX.
- Reachability: exactly one inbound data xref, `0x00615b34 -> 0x00489180`, and zero ordinary code callers. This is expected virtual dispatch evidence, not dead-code evidence.
- Packet: value-first writes produce opcode `0x4b`, subtype `0x07`, action `0x01`, and one-byte converted length; name bytes begin at offset `+4`, and the counted send length is `convertedLength + 4`.
- Ordering: CP_ACP conversion, indexed conversion terminator, length write, payload copy, indexed packet scratch terminator, then statement-form void queue call. The binary's `0x100` and post-copy `0x80` range failures are compiler instrumentation around the two indexed writes.
- Ownership: both source buffers are stack-owned. The caller scratch NULs are outside the sent length; Socket owns only its separate queued copy and its own appended NUL.
- Protocol: outgoing action `0` requests the workflow, incoming action/result `0` opens this dialog, incoming action/result `1` accepts it, and this method emits action `1` with the submitted name.
- Placement: direct method owner remains this class and the source-file route remains [UID:0000I8][Clan](by-file/Clan.md) -> `NexusTK/social/Clan.cpp`. [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md) is a non-standalone family/index with path/owner `NONE`, so it is not a future migration destination absent new direct source artifacts.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | The page now records the class declaration, raw constructor source shape, exact submitter range, packet bytes, conversion/send path, length guards, vtable slots, live inline construction sites, child parent routing, Clan parent ownership, no-route raw constructor policy, and remaining scoped caveats. |
| Confidence | 90 | Confidence is very strong for the submitter, packet shape, vtable identity, Clan ownership, inherited layout, and class declaration. It remains below final-source quality only because the retained raw constructor start is not an IDA-modeled function and still has no VA/RVA/direct-branch route. |
| Reconstructable | true | The class represents source-authored clan expel-name behavior. The class page emits the declaration with `[[CHILDREN]]`, UID0002NV emits the exact delegating constructor, and UID0002NW emits the method body; raw-entry negative evidence is preserved without erasing source-bearing bytes. |

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md)
- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:00010K][0x00488fe0-0x004895fe.ClanNameDialogSubmitters](by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md)
- [UID:0002NV][0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor](by-memory/0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor.md)
- [UID:0002NW][0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName](by-memory/0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName.md)
- [UID:00002J][ClanNameInputDialog](by-class/ClanNameInputDialog.md)
- [UID:0001HZ][0x00575380-0x00575abb.PacketBufferHelpers](by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md)
- [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md)
- [UID:0001P0][0x0067a7ec-0x0067a7f0.g_packetSender](by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md)

## Changes

- 2026-08-10 B006 UID0002NW implementation callback:
  - Added the exact method range/hash, sole vtable route and zero-caller proof, void member ABI, value-first PacketBuffer API, exact CP_ACP arguments, contiguous source arrays, copy-before-second-guard ordering, indexed-write/compiler-instrumentation distinction, counted-send and Socket-copy ownership, and outgoing/incoming subtype-7 protocol lifecycle.
  - Kept `86/90`, owner/emitter `0000I8`, reconstructable true, the formal H declaration, `[[CHILDREN]]`, and current `Clan.cpp` route. The remaining score cap stays attached to the separate retained raw-constructor no-route evidence and broader historical file split, not to UID0002NW behavior.

- 2026-08-10 B006 UID0002NU implementation callback:
  - Changed both stale `int OnSubmitText` declaration copies to `void` from the base-call and six-leaf return proof.
  - Moved the formal class declaration from CPP to H and retained `[[CHILDREN]]` in CPP for method definitions.
  - Kept `86/90`, owner/emitter `0000I8`, reconstructable true, and the current `Clan.cpp` source route.

- What existed before: the page documented expel submit behavior, vtable identity, and projected constructor caveats, but metadata was still `0/0`.
- What it was changed to: scores were set to `68/76`.
- Summary and evidence: the submitter and vtable references are strong; projected constructor reachability and full class layout/source form remain unresolved.
- 2026-05-31: Replaced raw constructor/submitter addresses with exact child `by-memory` pages and corrected the submitter end to exclusive `0x0048926e`. Evidence: IDA MCP `lookup_funcs`, vtable `xrefs_to`, disassembly, and byte audit confirm the raw constructor range `0x00489140-0x00489175`, submitter range `0x00489180-0x0048926e`, and alignment padding around both.
- 2026-06-05 live IDA refinement:
  - What existed before: the page had `72/82` scores, no autogen parent, and only summarized the constructor caveat and submitter.
  - Changed to: scores `82/86`, `AUTOGEN_PARENT_UID:0000I8`, direct live IDA evidence for constructor-shaped bytes, vtable stores/slots, submit packet construction, conversion bounds, and send path.
  - Summary/evidence: completion increased because the page now documents the full submitter behavior, vtable identity, raw constructor body, and parent ownership. Confidence increased because live IDA MCP confirms the exact function range, vtable data refs, packet byte sequence, bounds checks, and Clan-family ownership while preserving the no-function/no-xref raw constructor cap. C++ was left unpopulated under the old 95/95 policy; this was superseded by the 2026-06-21 class declaration and 2026-06-29 UID0002NV formal no-code/covered-by marker.
- 2026-06-05 A004 child-routing refinement:
  - What existed before: the page was `82/86`, the raw constructor child was still file-parented, the submitter was unassigned, and class evidence still used generated helper/global labels.
  - Changed to: `84/88`, both child pages attached under this class, and evidence rewritten to address/UID-based helper references.
  - Summary/evidence: live IDA reconfirmed no constructor-start xrefs or pointer/immediate/data-reference matches, exact constructor bytes and padding, exact submitter bounds and vtable-only xref, no direct callers, packet bytes `{ 0x4b, 7, 1, converted_length, name_bytes... }`, helper dependencies at `0x00575380`, `0x00516220`, `0x00574bb0`, and packet sender storage `0x0067a7ec`.
- 2026-06-17 B001 Clan submitter source-quality execution:
  - Added the shared `OnSubmitText(const wchar_t *)` submit-slot conclusion, clarified the manual CP_ACP length/payload packet construction, and recorded that class-level constructor/declaration uncertainty does not block the exact submitter child page from emitting first-draft C++.
- 2026-06-21 B011 ClanExpelNameInputDialog source-quality incorporation:
  - Changed to `86/90` and added first-draft class declaration C++ with `[[CHILDREN]]`.
  - Evidence: raw PE/Capstone recheck reconfirmed the retained `0x00489140-0x00489175` constructor-shaped bytes, padding, base-constructor call, vtable stores, zero VA/RVA/direct-branch route to `0x00489140`, live inline construction sites at `0x004851c6` and `0x004881df`, vtable slot `0x00615b34 -> 0x00489180`, no expel-specific persistent fields beyond inherited `ClanNameInputDialog` storage, and current `social/Clan.cpp` owner/emitter route. That pass left the raw constructor child unpopulated at the time; the 2026-06-29 UID0002NV callback superseded it with a formal no-code/covered-by marker.
- 2026-06-29 B001 UID0002NV implementation callback:
  - Kept class metadata, owner/emitter route, and declaration C++ unchanged.
  - Updated the raw-constructor child disposition to formal no-code/covered-by marker instead of an unpopulated child block. Evidence: MCP session `3fa0535f` and local PE scan reconfirmed no function, no inbound xref, no loaded-VA/RVA pointer encoding, and no direct branch route to `0x00489140`; the same MCP pass reconfirmed raw constructor-shaped bytes, raw/live vtable-store xrefs, live inline construction at `0x004851c6`/`0x004881df`, and submit slot `0x00615b34 -> 0x00489180`.
