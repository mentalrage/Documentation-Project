*** UID:00002A | DO NOT MODIFY OR REMOVE!!! ***
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
class ClanDepMoneyInputDialog : public ClanNameInputDialog
{
public:
    explicit ClanDepMoneyInputDialog(const unsigned char *packet);

protected:
    virtual void OnSubmitText(const wchar_t *text);
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ClanDepMoneyInputDialog

## Status

- Confidence: strong for submit behavior, packet shape, vtable identity, and Clan source ownership; medium for the raw constructor start because IDA still does not model it as a function.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Vtable anchors: primary `0x00615998`, secondary `0x006159fc`, tertiary `0x00615a2c`
- Rebuild handling: source-authored clan-bank deposit dialog. Attached to [UID:0000I8][Clan](by-file/Clan.md); [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md) is a non-standalone, non-emitting family/index and is not a source-owner candidate. The class page keeps the declaration in formal H and `[[CHILDREN]]` in CPP. Exact child [UID:00021V][0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor](by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md) emits the delegating constructor definition and [UID:0002NS][0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney](by-memory/0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney.md) emits the submitter definition. The raw start's absent inbound route remains a confidence caveat, not a no-code disposition.

## Class Purpose

`ClanDepMoneyInputDialog` is a `ClanNameInputDialog` variant that sends clan-bank deposit money requests. It has no proven unique persistent data fields beyond the inherited dialog state; the class identity is carried by its derived primary/secondary/tertiary vtables and its `OnSubmitText` override.

## Source-Facing Class Shape

The review-only declaration shape is:

```cpp
class ClanDepMoneyInputDialog : public ClanNameInputDialog
{
public:
    explicit ClanDepMoneyInputDialog(const unsigned char *packet);
    void OnSubmitText(const wchar_t *text) override;
};
```

The review-only constructor shape is:

```cpp
ClanDepMoneyInputDialog::ClanDepMoneyInputDialog(const unsigned char *packet)
    : ClanNameInputDialog(packet)
{
}
```

This constructor argument is packet bytes, not an integer id. The raw constructor forwards `[ebp+8]` to [UID:00010J][0x00488b40-0x00488fa0.ClanNameInputDialogCore](by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md), whose base constructor reads prompt length at `packet+3` and prompt bytes at `packet+4`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| raw constructor-shaped body | [UID:00021V][0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor](by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md) `0x00488fa0-0x00488fd5` | Constructor-shaped bytes that forward a `const unsigned char *packet` argument to `ClanNameInputDialog::ClanNameInputDialog`; IDA/PE evidence still reports no function, inbound xrefs, pointer-byte matches, immediate matches, data-reference matches, VA/RVA hits, or rel32 branch route at this raw start. |
| `OnSubmitText` / deposit request | [UID:0002NS][0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney](by-memory/0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney.md) `0x00488fe0-0x00489062` | Converts the input amount with CRT `_wtol` and sends opcode `0x4b`, subtype `4`, action `1`, and a big-endian amount through `PacketBufferWriteUInt32BE`. |

## Evidence Notes

- 2026-06-05 live IDA MCP reports no function object at `0x00488fa0`; `xrefs_to(0x00488fa0)` is empty and a little-endian pointer-byte search for `0x00488fa0` found no matches.
- 2026-06-05 live IDA MCP reports zero immediate matches and zero data-reference matches for `0x00488fa0`; byte search for little-endian pointer bytes `a0 8f 48 00` also returns zero matches.
- Direct disassembly shows constructor-shaped bytes ending in `retn 4` at `0x00488fd2`, followed by eleven `0xcc` padding bytes before the submitter.
- The raw constructor saves `this`, pushes its single packet pointer argument, calls the shared `ClanNameInputDialog` base constructor at `0x00488fad`, writes primary/secondary/tertiary `ClanDepMoneyInputDialog` vtables at `0x00488fb2`, `0x00488fba`, and `0x00488fc4`, returns `this`, and cleans one stack argument.
- 2026-06-19 B004 local PE/Capstone recheck found zero absolute VA hits, zero RVA hits, and zero rel32 `call`/`jmp`/conditional-branch hits to raw constructor start `0x00488fa0`; the same scan found zero VA/RVA/rel32 hits to the padding boundary `0x00488fd5`.
- B004 local PE/Capstone recheck found active inline construction sites that duplicate the constructor sequence without proving a live call to raw start `0x00488fa0`: `0x0048511b` calls `ClanNameInputDialog::ClanNameInputDialog`, followed by derived vtable stores at `0x00485120`/`0x00485126`/`0x00485130`; `0x00487ddf` calls the same base constructor, followed by stores at `0x00487de4`/`0x00487dea`/`0x00487df4`.
- 2026-06-05 live IDA MCP reports the submitter as a real function at `0x00488fe0-0x00489062`, with the submit callback referenced from vtable slot `0x006159f4`.
- B004 local PE/Capstone recheck found exactly one absolute reference to the active submitter: vtable slot `0x006159f4 -> 0x00488fe0`. No direct code caller is expected because [UID:00010J][0x00488b40-0x00488fa0.ClanNameInputDialogCore](by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md) dispatches primary vtable slot `+0x5c` / 92 from `OnButtonClick`.
- The submitter converts the submitted text with CRT `_wtol` / `__wtol` at `0x005cea43`, writes packet bytes through `0x00575380` for opcode `0x4b`, subtype `4`, and action `1`, writes the big-endian four-byte amount through `0x005753f0` / `PacketBufferWriteUInt32BE`, then sends seven bytes through `0x00574bb0` using `g_packetSender` at `0x0067a7ec`, best typed as `Socket *`.
- The binary reserves a `0x80` / 128-byte local packet buffer for the submitter even though only seven bytes are sent. Historical `packet[8]` was payload-size-equivalent but not source-family faithful; the accepted child formal CPP now uses `packet[128]`.
- 2026-08-10 B006 resolves the shared slot as `void OnSubmitText(const wchar_t *text)`: the base call consumes no result and every current derived leaf produces no return value. The class declaration is emitted through formal H, while CPP retains only child definitions.
- 2026-06-17 B001 source-quality recheck maps this method to the shared base submit virtual slot `+0x5c`, inferred/descriptive `OnSubmitText(const wchar_t *text)`. The raw constructor reachability caveat remains class-level only and does not block [UID:0002NS][0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney](by-memory/0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney.md) method-body C++.
- Live vtable data confirms RTTI at `0x00615994`, primary destructor slot `0x00615998 -> 0x0048c350`, submit slot `0x006159f4 -> 0x00488fe0`, secondary adjustor slot `0x006159fc -> 0x0048c27b`, and tertiary adjustor slot `0x00615a2c -> 0x0048c286`.
- Xrefs to the three vtable bases come from Clan dialog code at `0x00485120`/`0x00485126`/`0x00485130`, from the function beginning at `0x00487d70` via instructions `0x00487de4`/`0x00487dea`/`0x00487df4`, and from the raw constructor stores at `0x00488fb2`/`0x00488fba`/`0x00488fc4`.
- Live IDA still reports no xrefs to the raw constructor start `0x00488fa0`, so constructor reachability remains an explicit cap even though the byte body, submitter, packet shape, and vtable identity are coherent.
- 2026-06-16 B001 Clan opcode helper recheck: [UID:00021I][0x00485780-0x00485867.ClanDepositMoneyRequestAndSubmitPacketHelpers](by-memory/0x00485780-0x00485867.ClanDepositMoneyRequestAndSubmitPacketHelpers.md) contains retained/no-route subtype `4` action `0` dialog-request and action `1` amount-submit helpers. The action `1` raw body mirrors this class's live submitter, but it is not the class method because IDA/PE show no route to the raw start and the active submitter remains vtable-backed at `0x00488fe0`.

## Inference And Heuristic Decisions

| Issue | Best decision | Evidence | Rejected alternatives / impact |
| --- | --- | --- | --- |
| Class source owner | Keep [UID:0000I8][Clan](by-file/Clan.md) / `NexusTK/social/Clan.cpp`. | Clan owns the status pane, modal dialog family, opcode `0x4b` helper strip, modal vtables, and current generated route. | [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md) is documentation-only family/index evidence with path/owner `NONE`; it must not receive this class or generate a duplicate source file. |
| Constructor argument | `const unsigned char *packet`, or eventual clan packet wrapper. | Raw and inline construction forward the argument into `ClanNameInputDialog::ClanNameInputDialog`; the base reads prompt length at `packet+3` and prompt bytes at `packet+4`. | Reject `int clanId`, `parentPaneId`, or other id-style names for this argument. |
| Raw constructor liveness | Retained out-of-line constructor-shaped body with no proven raw-entry route. | IDA reports no function/xrefs/pointer/immediate/data-ref matches; B004 PE scan finds no VA/RVA/rel32 route hits. | Do not discard the body as padding/compiler glue; also do not claim `0x00488fa0` is the live construction entry. |
| Active construction | Inline construction sites duplicate the constructor sequence. | Base constructor calls at `0x0048511b` and `0x00487ddf` are followed by derived vtable stores. | Do not use those inline sites to prove a direct call to the raw constructor. |
| Submit virtual name | `OnSubmitText(const wchar_t *text)`. | Base slot `+0x5c`, active vtable slot `0x006159f4`, and accepted sibling submitter evidence. | `SubmitDepositMoney` remains a role/page label, not the shared virtual name. |
| Amount conversion/writer | CRT `_wtol` / `__wtol` plus `PacketBufferWriteUInt32BE`. | Calls `0x005cea43` and `0x005753f0`; money packet bytes are big-endian. | Reject product conversion helper names and stale little-endian amount wording. |
| Sender/global | `g_packetSender`, best current type `Socket *`. | [UID:0001P0][0x0067a7ec-0x0067a7f0.g_packetSender](by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md) documents shared sender storage and [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) documents queued send. | Reject generated `CashShopRequest *` aliases for this dialog. |
| Retained raw helper mirror | [UID:00021I][0x00485780-0x00485867.ClanDepositMoneyRequestAndSubmitPacketHelpers](by-memory/0x00485780-0x00485867.ClanDepositMoneyRequestAndSubmitPacketHelpers.md) is a no-route helper mirror, not the class method. | Raw helper action `1` mirrors `{0x4b,4,1,uint32 amount}` but has no route; active submitter is vtable-backed at `0x00488fe0`. | Do not move or rename the class method based on the retained helper strip. |
| Class-level C++ | Keep the class declaration in formal H and `[[CHILDREN]]` in CPP. | Exact constructor and submitter children emit their definitions under the class and UID0000I8 route. | Do not duplicate either body at class or by-file level; missing raw-start reachability does not suppress the retained constructor source definition. |

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | The page records the raw constructor body and exact emitted source definition, packet-pointer constructor shape, active inline construction stores, exact submitter range, packet bytes, conversion/send path, vtable slots, raw-start no-route PE/IDA caveat, Clan owner route, rejected standalone split, retained-helper mirror separation, and child page routing. |
| Confidence | 90 | Confidence is very strong for the constructor source shape, submitter, packet shape, vtable identity, inherited layout, and Clan ownership. It remains below final-source quality because the retained constructor start is still raw/non-IDA-modeled and has no direct entry route. |
| Reconstructable | true | The class represents source-authored clan-bank deposit behavior. Formal H owns the declaration, formal CPP routes exact child definitions, UID00021V emits the delegating constructor, and UID0002NS emits the submitter. |

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md)
- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:00010K][0x00488fe0-0x004895fe.ClanNameDialogSubmitters](by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md)
- [UID:00021V][0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor](by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md)
- [UID:0002NS][0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney](by-memory/0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney.md)
- [UID:00002J][ClanNameInputDialog](by-class/ClanNameInputDialog.md)

## Changes

- 2026-08-10 B006 UID0002NU implementation callback:
  - Changed both stale `int OnSubmitText` declaration copies to `void`, moved the formal declaration from CPP to H, and retained `[[CHILDREN]]` in CPP.
  - Closed the historical `packet[8]` caveat in favor of the observed 128-byte local family shape.
  - Kept `86/90`, owner/emitter `0000I8`, reconstructable true, and the current Clan source route.

- 2026-05-27: The constructor row previously referenced only raw `0x00488fa0`. Replaced it with [UID:00021V][0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor](by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md), the focused `0x00488fa0-0x00488fd5` raw-constructor page, and clarified that constructor shape is strong while reachability remains unresolved. Evidence: IDA MCP raw-head audit confirms the base-constructor call and vtable stores, with no function object or inbound xrefs at `0x00488fa0`.
- 2026-05-31: The submitter row previously used the raw inclusive-looking range `0x00488fe0-0x00489061`. Replaced it with exact child page [UID:0002NS][0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney](by-memory/0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney.md). Evidence: IDA MCP `lookup_funcs` reports a modeled function at `0x00488fe0`, size `0x82`, vtable xref `0x006159f4`, and padding beginning at `0x00489062`.
- What existed before: the page documented deposit-money submit behavior, raw constructor page linkage, vtable anchors, and reachability caveats, but metadata still read `0/0`.
- What it was changed to: scores were set to `68/76`.
- Summary and evidence: submitter behavior and raw constructor shape are documented; no-xref constructor reachability and final layout/header detail remain unresolved.
- 2026-06-05 live IDA refinement:
  - What existed before: the page had `72/82` scores, no autogen parent, and only summarized the constructor caveat and submitter.
  - Changed to: scores `82/86`, `AUTOGEN_PARENT_UID:0000I8`, direct live IDA evidence for constructor-shaped bytes, vtable stores/slots, submit packet construction, conversion path, and send path.
  - Summary/evidence: completion increased because the page now documents the full submitter behavior, vtable identity, raw constructor body, and parent ownership. Confidence increased because live IDA MCP confirms the exact function range, vtable data refs, packet byte sequence, and Clan-family ownership while preserving the no-function/no-xref raw constructor cap. C++ remains blank because the constructor and class declaration are not 95/95 quality.
- 2026-06-05 constructor/class evidence cleanup:
  - What existed before: `82/86`, stale raw helper/global labels, no live pointer-search evidence in the class summary, and stale by-class coverage at `72%`.
  - Changed to: `84/88`, address-based live IDA evidence, synced by-class coverage, and child routing that places the raw constructor under this class once both pages are above the parent gate.
  - Summary/evidence: live IDA MCP reconfirmed the constructor no-function/no-xref status, zero pointer/immediate/data-reference matches for `0x00488fa0`, vtable stores, submitter bounds and packet/send dependencies, and class-family vtable xrefs while preserving the no-code rationale.
- 2026-06-16 B001 Clan opcode helper source-quality cross-note:
  - Added retained-helper mirror note for [UID:00021I][0x00485780-0x00485867.ClanDepositMoneyRequestAndSubmitPacketHelpers](by-memory/0x00485780-0x00485867.ClanDepositMoneyRequestAndSubmitPacketHelpers.md). The raw helper pair remains Clan-owned and no-route; this class still owns the active vtable-backed deposit-money submitter.
- 2026-06-17 B001 Clan submitter source-quality execution:
  - Added the shared `OnSubmitText(const wchar_t *)` submit-slot conclusion, corrected the amount write to big-endian `PacketBufferWriteUInt32BE`, and clarified that class-level constructor/declaration uncertainty does not block the exact submitter child page from emitting first-draft C++.
- 2026-06-20 B004 Rule 26 source-quality incorporation:
  - Changed to: `86/90`; owner/emitter remain [UID:0000I8][Clan](by-file/Clan.md), reconstructable remains true, and formal class-level C++ remains blank under a target-specific no-code proof.
  - Evidence: B004 compared current target/support docs, rechecked local PE/Capstone evidence, kept [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md) as a split candidate only, resolved the constructor parameter as `const unsigned char *packet` forwarded to `ClanNameInputDialog`, confirmed zero VA/RVA/rel32 route hits to raw constructor start `0x00488fa0` and padding boundary `0x00488fd5`, confirmed active inline construction stores at `0x00485120`/`0x00485126`/`0x00485130` and `0x00487de4`/`0x00487dea`/`0x00487df4`, confirmed raw constructor stores at `0x00488fb2`/`0x00488fba`/`0x00488fc4`, confirmed active submitter vtable slot `0x006159f4`, and preserved [UID:00021I][0x00485780-0x00485867.ClanDepositMoneyRequestAndSubmitPacketHelpers](by-memory/0x00485780-0x00485867.ClanDepositMoneyRequestAndSubmitPacketHelpers.md) as a retained/no-route mirror rather than the class method.
