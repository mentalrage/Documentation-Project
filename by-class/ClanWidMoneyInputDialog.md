*** UID:00002O | DO NOT MODIFY OR REMOVE!!! ***
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
class ClanWidMoneyInputDialog : public ClanNameInputDialog
{
public:
    explicit ClanWidMoneyInputDialog(const unsigned char *packet);

protected:
    virtual void OnSubmitText(const wchar_t *text);
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ClanWidMoneyInputDialog

## Status

- Confidence: strong for class identity, submit behavior, packet shape, vtable identity, raw-constructor negative reachability, Clan source ownership, and the accepted formal H declaration/CPP child route; exact original lexical/access spelling remains inference-backed.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Vtable anchors: primary `0x00615a38`, secondary `0x00615a9c`, tertiary `0x00615acc`
- Rebuild handling: source-authored clan-bank withdraw dialog. The exact submitter child [UID:0002NU][0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney](by-memory/0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney.md) emits `OnSubmitText(const wchar_t *)`; this class page carries the declaration/children route, while raw constructor child [UID:0002NT][0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor](by-memory/0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor.md) emits the exact packet-forwarding constructor definition. The missing raw-start function/xref/pointer/branch route remains confidence evidence only and does not suppress source emission.

## Class Purpose

`ClanWidMoneyInputDialog` is a `ClanNameInputDialog` variant that sends clan-bank withdrawal requests.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| raw constructor definition | [UID:0002NT][0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor](by-memory/0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor.md) `0x00489070-0x004890a5` | Emits the exact packet-forwarding constructor definition. IDA reports no function, inbound xrefs, pointer-byte matches, immediate matches, or data-reference matches at this start; those negatives constrain entry-route confidence but do not suppress the retained source body. |
| `OnSubmitText` / withdraw request | [UID:0002NU][0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney](by-memory/0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney.md) `0x004890b0-0x00489132` | Converts the input amount with CRT `_wtol` and sends opcode `0x4b`, subtype `0x0b`, action `1`, and a big-endian amount through `PacketBufferWriteUInt32BE`. |

## Evidence Notes

- 2026-07-05 B010 MCP refresh, session `supervisor_recovery_20260705`, reported server health OK and reconfirmed the raw constructor child has no function, no decompile, no xrefs to `0x00489070`/`0x004890a5`, zero exact VA/RVA pointer hits for those boundaries, and zero direct branch/call routes in a local PE scan. It also reconfirmed the exact body bytes, `0x0048907d` base-constructor call, primary/secondary/tertiary vtable stores at `0x00489082`/`0x0048908a`/`0x00489094`, eleven `0xcc` padding bytes, and active inline construction stores at `0x00485398`/`0x0048539e`/`0x004853a8` and `0x004884d4`/`0x004884da`/`0x004884e4`.
- Current MCP reports the adjacent withdraw submitter as IDB function `sub_4890B0`, size `0x82`, with vtable-only exact pointer route `0x00615a94 -> 0x004890b0`; keep `ClanWidMoneyInputDialogSubmitWithdrawMoney` as the stable source-facing documentation name, not a proven original symbol.
- 2026-06-05 live IDA MCP reports no function object at `0x00489070`; `xrefs_to(0x00489070)` is empty and a little-endian pointer-byte search for `0x00489070` found no matches.
- 2026-06-05 live IDA MCP reports zero immediate matches and zero data-reference matches for `0x00489070`; byte search for little-endian pointer bytes `70 90 48 00` also returns zero matches.
- Direct disassembly shows constructor-shaped bytes ending in `retn 4` at `0x004890a2`, followed by eleven `0xcc` padding bytes before the submitter.
- The raw constructor pushes its single argument, calls the shared `ClanNameInputDialog` base constructor at `0x0048907d`, and writes primary/secondary/tertiary `ClanWidMoneyInputDialog` vtables at `0x00489082`, `0x0048908a`, and `0x00489094`.
- 2026-06-05 live IDA MCP reports the submitter as a real function at `0x004890b0-0x00489132`, with the submit callback referenced from vtable slot `0x00615a94`.
- The submitter converts the submitted text with CRT `_wtol` / `__wtol` at `0x005cea43`, writes packet bytes through `0x00575380` for opcode `0x4b`, subtype `0x0b`, and action `1`, writes the big-endian four-byte amount through `0x005753f0` / `PacketBufferWriteUInt32BE`, then sends seven bytes through `0x00574bb0` using packet sender `0x0067a7ec`.
- 2026-06-17 B001 source-quality recheck maps this method to the shared base submit virtual slot `+0x5c`, inferred/descriptive `OnSubmitText(const wchar_t *text)`. The raw constructor reachability caveat remains class-level only and does not block [UID:0002NU][0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney](by-memory/0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney.md) method-body C++.
- Live vtable data confirms RTTI at `0x00615a34`, primary destructor slot `0x00615a38 -> 0x0048c350`, submit slot `0x00615a94 -> 0x004890b0`, secondary adjustor slot `0x00615a9c -> 0x0048c27b`, and tertiary adjustor slot `0x00615acc -> 0x0048c286`.
- Xrefs to the three vtable bases come from Clan dialog code at `0x00485398`/`0x0048539e`/`0x004853a8`, from the function beginning at `0x00488460` via instructions `0x004884d4`/`0x004884da`/`0x004884e4`, and from the raw constructor stores at `0x00489082`/`0x0048908a`/`0x00489094`.
- Live IDA still reports no xrefs to the raw constructor start `0x00489070`, so constructor reachability remains an explicit cap even though the byte body, submitter, packet shape, and vtable identity are coherent.
- 2026-06-19 B012 local PE recheck found zero absolute VA hits, zero RVA hits, and zero relative branch/call targets to raw constructor start `0x00489070` or endpoint `0x004890a5`.
- The same PE scan found one absolute VA hit for active submitter start `0x004890b0` at vtable slot `0x00615a94`, and found the three `ClanWidMoneyInputDialog` vtable constants at the two inline construction contexts plus the raw constructor body.
- The accepted class source shape is `ClanWidMoneyInputDialog : public ClanNameInputDialog`, with `explicit ClanWidMoneyInputDialog(const unsigned char *packet)` and `void OnSubmitText(const wchar_t *text) override` in formal H. Formal CPP contains `[[CHILDREN]]`; UID0002NT emits the constructor definition and UID0002NU emits the submit override.
- Historical 2026-06-19 caveat, now superseded: PacketBuffer support already favored value-first signatures, but the family had not yet been harmonized and compile readiness remained deferred.
- 2026-08-10 B006 closes that helper-order caveat: current helper declarations and cdecl push order prove value-first calls. The base slot `+0x5c` consumes no result and all six current submitter leaves return no value, so this class now declares `virtual void OnSubmitText(const wchar_t *text)` in formal H. The exact withdraw child uses a 128-byte local packet, sends seven bytes, and receives no QueueAndSendPacket result.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | The page records raw constructor bytes, current no-route evidence, active submitter range, vtable slots, packet bytes, conversion/send path, sibling/dialog comparisons, class source shape, owner/emitter route, and the exact emitted raw-constructor disposition. |
| Confidence | 90 | Confidence is very strong for class identity, vtable ownership, submitter behavior, packet semantics, the accepted declaration/definition split, and negative raw-constructor reachability. It remains below final audit because the exact original lexical/access spelling and raw constructor entry route are not proven. |
| Reconstructable | true | The class is source-authored Clan dialog code. Formal H owns the declaration, formal CPP routes `[[CHILDREN]]`, and the two exact child pages emit the constructor and submit definitions. |

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md)
- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:00010K][0x00488fe0-0x004895fe.ClanNameDialogSubmitters](by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md)
- [UID:0002NT][0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor](by-memory/0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor.md)
- [UID:0002NU][0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney](by-memory/0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney.md)
- [UID:00002J][ClanNameInputDialog](by-class/ClanNameInputDialog.md)

## Changes

The entries below are dated historical changes. Older unresolved declaration/source-split, blank-C++, and marker-only constructor conclusions are superseded by the accepted formal H declaration and formal CPP child route above.

- 2026-08-10 B006 UID0002NU implementation callback:
  - Changed the stale `virtual int` submit declaration to `virtual void` and moved the declaration from formal CPP to formal H; CPP retains `[[CHILDREN]]` for emitted method definitions.
  - Added current void-callback, value-first helper, 128-byte local, seven-byte send, and void sender evidence from the dedicated target recheck.
  - Kept `86/90`, owner/emitter `0000I8`, reconstructable true, and the active `Clan.cpp` route.

- 2026-07-05 B010 UID0002NT source-quality implementation sync:
  - Kept class metadata unchanged at `86/90`, owner/emitter [UID:0000I8][Clan](by-file/Clan.md).
  - Historical 2026-07 disposition (superseded 2026-08-14): class-level C++ was a declaration/children marker, UID0002NU emitted the submitter body, and UID0002NT was described as marker-only/no standalone constructor body. The accepted callback now emits the exact constructor definition through UID0002NT while preserving the no-entry evidence as a confidence caveat.
  - Evidence: MCP session `supervisor_recovery_20260705` reconfirmed raw-constructor no-function/no-decompile/no-route state, exact vtable stores, active inline construction sites, current submitter IDB name `sub_4890B0`, and vtable-only submitter route `0x00615a94 -> 0x004890b0`.
- What existed before: the page documented withdraw-money submit behavior, vtable identity, and projected constructor caveats, but metadata was still `0/0`.
- What it was changed to: scores were set to `68/76`.
- Summary and evidence: the submitter and vtable references are documented; projected constructor reachability and final layout/source placement remain unresolved.
- 2026-05-31: Replaced raw constructor/submitter addresses with exact child `by-memory` pages and corrected the submitter end to exclusive `0x00489132`. Evidence: IDA MCP `lookup_funcs`, vtable `xrefs_to`, disassembly, and byte audit confirm the raw constructor range `0x00489070-0x004890a5`, submitter range `0x004890b0-0x00489132`, and alignment padding around both.
- 2026-06-05 live IDA refinement:
  - What existed before: the page had `72/82` scores, no autogen parent, and only summarized the constructor caveat and submitter.
  - Changed to: scores `82/86`, `AUTOGEN_PARENT_UID:0000I8`, direct live IDA evidence for constructor-shaped bytes, vtable stores/slots, submit packet construction, conversion path, and send path.
  - Summary/evidence: completion increased because the page documented the full submitter behavior, vtable identity, raw constructor body, and parent ownership. Confidence increased because live IDA MCP confirmed the exact function range, vtable data refs, packet byte sequence, and Clan-family ownership while preserving the no-function/no-xref raw constructor cap. At that time class-level C++ remained blank because the constructor and class declaration were not 95/95 quality; the current page carries a declaration/children marker.
- 2026-06-05 constructor/class evidence cleanup:
  - What existed before: `82/86`, stale raw helper/global labels, no live pointer-search evidence in the class summary, stale by-class coverage at `72%`, and child pages not both routed to the class.
  - Changed to: `84/88`, address-based live IDA evidence, synced by-class coverage, and child routing that places both withdraw-money child pages under this class once all pages are above the parent gate.
  - Summary/evidence: live IDA MCP reconfirmed the constructor no-function/no-xref status, zero pointer/immediate/data-reference matches for `0x00489070`, vtable stores, submitter bounds and packet/send dependencies, and class-family vtable xrefs while preserving the then-current raw-constructor route caveat.
- 2026-06-17 B001 Clan submitter source-quality execution:
  - Added the shared `OnSubmitText(const wchar_t *)` submit-slot conclusion, corrected the amount write to big-endian `PacketBufferWriteUInt32BE`, and clarified that class-level constructor/declaration uncertainty does not block the exact submitter child page from emitting first-draft C++.
- 2026-06-19 B012 source-quality report:
  - Recommended `84/88 -> 86/90`, owner/emitter unchanged through [UID:0000I8][Clan](by-file/Clan.md), and the then-current class-level C++ state not yet populated.
  - Rechecked raw constructor reachability with current-session PE scans: no VA/RVA pointer hits and no relative branch/call targets to `0x00489070`/`0x004890a5`; vtable constants remain present only in inline construction contexts plus the raw constructor body.
  - Resolved class source shape as a `ClanNameInputDialog` withdraw-money variant with `OnSubmitText(const wchar_t *)`; packet subtype `0x0b` action `1` sends a seven-byte clan request with a big-endian `_wtol` amount.
  - Flagged PacketBuffer helper argument-order harmonization as a support-doc/validator need rather than a class ownership blocker.
