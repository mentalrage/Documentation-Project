*** UID:000028 | DO NOT MODIFY OR REMOVE!!! ***
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
class ClanChangeNameInputDialog : public ClanNameInputDialog
{
public:
    explicit ClanChangeNameInputDialog(const unsigned char *packet);

protected:
    virtual void OnSubmitText(const wchar_t *text);
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ClanChangeNameInputDialog

## Status

- Confidence: very strong for submit behavior, packet shape, vtable identity, class ownership, and the current constructor evidence; capped by the raw constructor start because IDA still does not model it as a function or expose direct reachability.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Vtable anchors: primary `0x00615cb8`, secondary `0x00615d1c`, tertiary `0x00615d4c`
- Rebuild handling: source-authored clan rename dialog attached to [UID:0000I8][Clan](by-file/Clan.md). Formal H owns the class declaration and CPP routes `[[CHILDREN]]`; raw constructor child [UID:0002O1][0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor](by-memory/0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor.md) emits the exact delegating constructor, and [UID:0002O2][0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName](by-memory/0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName.md) emits `OnSubmitText(const wchar_t *)`. The absent raw-entry route remains a confidence caveat, not a no-code marker. [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md) remains documentation-only and non-emitting.

## Class Purpose

`ClanChangeNameInputDialog` sends a clan rename packet for the submitted clan name.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| raw constructor-shaped body | [UID:0002O1][0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor](by-memory/0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor.md) `0x004894d0-0x00489505` | Constructor-shaped bytes; IDA reports no function, inbound xrefs, or raw pointer hits at this start. |
| `OnSubmitText` / rename request | [UID:0002O2][0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName](by-memory/0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName.md) `0x00489510-0x004895fe` | Converts the new name to a CP_ACP multibyte payload and sends opcode `0x4b`, subtype `10`, action `1`, one-byte converted length, and payload bytes. |

## Evidence Notes

- 2026-06-05 live IDA MCP reports no function object at `0x004894d0`; `xrefs_to(0x004894d0)` is empty and pointer-byte, immediate, and data-reference searches for `0x004894d0` found no matches.
- Direct disassembly still shows constructor-shaped bytes ending in `retn 4` at `0x00489502`, followed by eleven `0xcc` bytes before the submitter.
- The raw constructor pushes its single argument, calls the shared `ClanNameInputDialog` base constructor at `0x004894dd`, and writes primary/secondary/tertiary `ClanChangeNameInputDialog` vtables at `0x004894e2`, `0x004894ea`, and `0x004894f4`.
- 2026-06-05 live IDA MCP reports a modeled function at `0x00489510-0x004895fe`, with the submit callback referenced from vtable slot `0x00615d14` and no direct code callers.
- The submitter writes packet bytes through the byte writer at `0x00575380` for opcode `0x4b`, subtype `10`, action `1`, and converted-name length, converts the submitted wide string through `WideCharToMultiByte`, copies the converted name through `0x00516220`, then sends through `0x00574bb0` using packet sender storage `0x0067a7ec`.
- The packet body has two length guards: converted name length must stay below `0x100`, and final packet length after the four-byte prefix/name payload must stay below `0x80`; failures call `___report_rangecheckfailure`.
- 2026-06-17 B001 source-quality recheck maps this method to the shared base submit virtual slot `+0x5c`, inferred/descriptive `OnSubmitText(const wchar_t *text)`. The scratch NUL after the copied payload is outside the counted packet length, and the raw constructor reachability caveat remains class-level only and does not block [UID:0002O2][0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName](by-memory/0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName.md) method-body C++.
- 2026-08-10 B006 resolves the shared return type as `void`: the base dispatch ignores a result and every current derived leaf produces no return value. The declaration now resides in formal H and the CPP channel retains child method definitions.
- Live vtable data confirms RTTI at `0x00615cb4`, primary destructor slot `0x00615cb8 -> 0x0048c350`, submit slot `0x00615d14 -> 0x00489510`, secondary adjustor slot `0x00615d1c -> 0x0048c27b`, and tertiary adjustor slot `0x00615d4c -> 0x0048c286`.
- Xrefs to the three vtable bases come from Clan dialog code at `0x00485337`/`0x0048533d`/`0x00485347`, from the nearby Clan dialog constructor path at `0x0048842e`/`0x00488434`/`0x0048843e`, and from the raw constructor stores at `0x004894e2`/`0x004894ea`/`0x004894f4`.
- This class is separate from `ClanChangeInputDialog`, which submits the multi-field attribute-change packet through helper `0x00486330`.
- Live IDA still reports no xrefs to the raw constructor start `0x004894d0`, so constructor reachability remains an explicit cap even though the byte body and vtable stores are coherent.
- 2026-06-15 Wave2 method-analysis identifies `0x004894d0` as an included `ClanChangeNameInputDialog` constructor record with size `0x35` / 53 bytes and a `0x269` / 617-byte wrapper layout (Verified with `int_convert.py`), zero callers, one callee to `0x00488b40`, and `ClanNameInputDialog` as the base at offset `0`.
- 2026-06-15 `wave2.py filter --class ClanChangeNameInputDialog --all-methods` lists only the raw constructor and `0x00489510` submitter, matching this class page's two-method surface.
- 2026-06-15 live IDA MCP recheck on database `b001_chatting_source_quality_20260615` reconfirmed no function at `0x004894d0` / `0x00489505`, no xrefs to `0x004894d0`, exact body bytes and `align 10h` padding, and vtable-store xrefs from `0x00485337`/`0x0048533d`/`0x00485347`, `0x0048842e`/`0x00488434`/`0x0048843e`, and the raw body.
- 2026-06-15 modeled opener disassembly shows `0x00485332` and `0x00488429` call the shared base constructor, then inline the same three `ClanChangeNameInputDialog` vtable stores. A local PE scan found zero absolute VA hits, zero RVA hits, and zero direct relative branch/call targets to `0x004894d0`, so the raw body remains unproven as a live entry.
- 2026-06-22 B001 Rule 26 source-placement recheck retained [UID:0002O1][0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor](by-memory/0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor.md) as source-authored constructor evidence rather than ignored, dead duplicate, or compiler glue. Current 2026-08-14 resolution keeps this class and all exact children under [UID:0000I8][Clan](by-file/Clan.md), classifies [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md) as a non-standalone index, places the declaration in formal H, and emits the exact constructor from UID0002O1 plus the submitter from UID0002O2. The old marker-only conclusion is historical.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 85 | The page records the raw constructor body, exact submitter range, packet bytes, conversion/send path, length guards, vtable slots, child routing, Clan parent ownership, Wave2 class/method evidence, inline construction sites, and remaining constructor caveat. |
| Confidence | 89 | Confidence is very strong for the submitter, packet shape, vtable identity, and Clan ownership, with live IDA and Wave2 evidence tying the class to the Clan dialog family. It remains capped because the constructor start is still raw/non-IDA-modeled and has no direct reachability. |
| Reconstructable | true | The class represents source-authored clan rename behavior. Formal H owns the declaration, CPP routes `[[CHILDREN]]`, UID0002O1 emits the exact delegating constructor, and UID0002O2 emits the submitter; raw-entry negative evidence remains documented without blocking source reconstruction. |

## Changes

- 2026-08-10 B006 UID0002NU implementation callback:
  - Changed `virtual int OnSubmitText` to `virtual void OnSubmitText` and moved the class declaration from formal CPP to formal H.
  - Kept `[[CHILDREN]]` in CPP, `85/89`, owner/emitter `0000I8`, reconstructable true, and the active `Clan.cpp` route.

- 2026-06-15 A001 Goal 2 owner/source-quality refresh:
  - What existed before: `84/88`, with older constructor caveats and class routing.
  - Changed to: `85/89`, keeping [UID:0000I8][Clan](by-file/Clan.md) as canonical owner/emitter; at that historical point final class C++ was still treated as blank before the later declaration-populated state.
  - Summary/evidence: Wave2 confirms the raw constructor and submitter are the complete local method surface for this class, with the constructor recorded as size `0x35` / 53 bytes and zero callers. Live IDA reconfirmed the no-function/no-xref raw start, exact bytes, vtable-store xrefs, and modeled open sites that inline the same construction sequence. Local PE scans found no absolute VA, RVA, or direct relative branch/call target to the raw constructor. The class remains routed through `Clan` rather than the lower-certainty `ClanDialogs` split candidate; that historical pass treated final C++ as blank because the raw standalone constructor entry and exact original source declaration were unresolved. The accepted 2026-08-14 UID0000IA state supersedes that conclusion: formal H owns the declaration, UID0002O1 emits the exact high-level delegating constructor, and UID0002O2 emits the submitter, while the no-entry evidence remains only a confidence/protection caveat.
- 2026-05-27: Corrected `OnSubmitText` range from `0x00489510-0x004895fd` to the exclusive range `0x00489510-0x004895fe`. Evidence: IDA MCP reports a modeled function size of `0xee` at `0x00489510` and two `0xcc` alignment bytes at `0x004895fe-0x00489600`.
- What existed before: the page documented rename submit behavior, vtable identity, range correction, and projected constructor caveat, but metadata was still `0/0`.
- What it was changed to: scores were set to `68/76`.
- Summary and evidence: the submitter and vtable references are documented; constructor reachability and full class/source layout remain unresolved.
- 2026-05-31: Replaced raw constructor/submitter addresses with exact child `by-memory` pages. Evidence: IDA MCP `lookup_funcs`, vtable `xrefs_to`, disassembly, and byte audit confirm the raw constructor range `0x004894d0-0x00489505`, submitter range `0x00489510-0x004895fe`, and alignment padding around both.
- 2026-06-05 live IDA refinement:
  - What existed before: the page had `72/82` scores, no autogen parent, and only summarized the constructor caveat and submitter.
  - Changed to: scores `82/86`, `AUTOGEN_PARENT_UID:0000I8`, direct live IDA evidence for constructor-shaped bytes, vtable stores/slots, submit packet construction, conversion bounds, and send path.
  - Summary/evidence: completion increased because the page now documents the full submitter behavior, vtable identity, raw constructor body, and parent ownership. Confidence increased because live IDA MCP confirms the exact function range, vtable data refs, packet byte sequence, and Clan-family ownership while preserving the no-function/no-xref raw constructor cap. At that historical point C++ remained blank because the constructor and class declaration were not 95/95 quality; current class-level C++ is declaration-populated.
- 2026-06-05 A004 child-routing refinement:
  - What existed before: the page was `82/86`, the raw constructor child was still file-parented, the submitter was unassigned, and class evidence still used generated helper/global labels.
  - Changed to: `84/88`, both child pages attached under this class, and evidence rewritten to address/UID-based helper references.
  - Summary/evidence: live IDA reconfirmed no constructor-start xrefs or pointer/immediate/data-reference matches, exact constructor bytes and padding, exact submitter bounds and vtable-only xref, no direct callers, packet bytes `{ 0x4b, 10, 1, converted_length, name_bytes... }`, helper dependencies at `0x00575380`, `0x00516220`, `0x00574bb0`, packet sender storage `0x0067a7ec`, and the successor boundary at `0x00489600`.
- 2026-06-17 B001 Clan submitter source-quality execution:
  - Added the shared `OnSubmitText(const wchar_t *)` submit-slot conclusion, clarified the manual CP_ACP length/payload packet construction, and recorded that class-level constructor/declaration uncertainty does not block the exact submitter child page from emitting first-draft C++.
- 2026-06-22 B001 Rule 26 source-placement closeout:
  - Historical pre-UID0000IA policy for [UID:0002O1][0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor](by-memory/0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor.md): keep class ownership and `social/Clan.cpp` routing, reject ignored/dead/duplicate-only classification, and keep the raw constructor child marker-only until raw-start reachability and final source placement are proven. The accepted 2026-08-14 UID0000IA callback supersedes only the marker-only conclusion: UID0002O1 now emits the exact high-level constructor, the class declaration remains in H, and UID0002O2 carries submitter behavior; the no-entry evidence remains valid as a bounded confidence/protection fact.

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
