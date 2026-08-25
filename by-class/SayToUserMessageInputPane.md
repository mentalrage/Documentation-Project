*** UID:0000C6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000N9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SayToUserMessageInputPane : public LineInputPane
{
public:
    explicit SayToUserMessageInputPane(const wchar_t *recipientName);

protected:
    virtual void OnSubmitInput();

private:
    wchar_t m_recipientName[128];
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

## UID0000N9 Whole-File Topology Synchronization - 2026-08-25

- Deterministic emitter position is `20`. Formal CPP remains only `[[CHILDREN]]`; formal H remains the complete `SayToUserMessageInputPane` declaration with no explicit derived destructor.
- UID000401 continues to own the exact constructor and `OnSubmitInput` definitions. UID000402 remains a no-route packet clone with no emitted source.

# SayToUserMessageInputPane

## Status

- Confidence: very strong for behavior, boundaries, exact `0x208` layout, three-view vtables, caller and inline-construction flow, inherited input lifecycle, compiler-generated destructor route, and legacy-vs-modern direct-message relationship; remaining uncertainty is lexical.
- Likely source file: [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- Address range: exact child [UID:000401][0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods](by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md), indexed by [UID:0001LY][0x005b1570-0x005b2562.SayTargetMessageInputPanes](by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md)
- Autogen parent: [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md) as the shared social input-pane owner.
- C++ reconstruction: the complete class declaration is in the formal H channel for `SayInputPanes.h`; formal CPP contains only `[[CHILDREN]]`, so UID000401 constructor/submit definitions emit at namespace scope in `SayInputPanes.cpp`. No explicit derived destructor is declared because the inherited virtual destructor is the narrow source cause of the observed shared/folded compiler wrapper.

## Class Purpose

`SayToUserMessageInputPane` is the legacy direct-message input pane for a selected recipient. It stores the recipient name, formats a prompt like `-> name: `, validates/sanitizes entered text, converts recipient and message text to multibyte strings, and sends opcode `0x19`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SayToUserMessageInputPane` | `0x005b1570-0x005b1631` | Initializes line input, stores recipient name in `m_recipientName[128]` at `+0x108`, and sets the `-> %s: ` prompt. |
| `OnSubmitInput` | `0x005b1640-0x005b1812` | Primary `+0x48` override; sends opcode `0x19` with recipient and message payload. Historical `OnSubmit` is retained only as alias history. |
| adjustor thunks | `0x005b7820`, `0x005b782b` | Secondary/tertiary interface destructor adjustors shared by the target-message input family. |
| scalar deleting destructor | `0x005b7af0-0x005b7b2b` | Shared/folded compiler wrapper regenerated from the implicit derived destructor plus inherited virtual destruction; no handwritten target declaration/body. |

## Evidence Notes

- 2026-06-04 live IDA MCP identity: `NexusTK.exe` at base `0x400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- Function lookup confirms exact starts and sizes for the constructor `0x005b1570` size `0xc1`, submit handler `0x005b1640` size `0x1d2`, adjustor thunks `0x005b7820` and `0x005b782b` size `0xb` each, and scalar deleting destructor `0x005b7af0` size `0x3b`; `0x005b1812` is not a function start.
- 2026-06-19 B001 PE/Capstone reanalysis corrects the constructor half-open endpoint to `0x005b1631`: the `ret 4` is at `0x005b162e` and the byte at `0x005b1630` is the `ret` immediate, not padding.
- The constructor calls the base line-input initializer, writes `SayToUserMessageInputPane` vtables at offsets `0`, `0xa0`, and `0xa4`, copies the recipient into the `+0x108` buffer, and formats the prompt string `-> %s: `.
- Exact `LineInputPane` size `0x108` followed by `wchar_t m_recipientName[128]` at `+0x108` closes the complete class at `0x208`. The constructor's `0x80` wchar copy bound and the independent inline construction at `0x005b419b-0x005b41f9` corroborate the field width and full layout.
- The submit method checks for positive input length, copies at most 255 wide characters, validates and sanitizes the message, reuses one `CHAR[256]` buffer for recipient and message conversion, serializes into one `unsigned char[300]` packet, writes opcode `0x19` plus both one-byte lengths, stores only local safety terminators, and sends through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md).
- `OnSubmitInput()` is the source-facing primary `+0x48` override. `LineInputPane::HandleKeyOrTextEvent(Event *)` invokes that slot on Enter and owns Escape, Tab, deferred deletion, owner notification, and child forwarding; the class needs no local key/cancel method.
- Vtable data confirms primary table `??_7SayToUserMessageInputPane@@6B@` at `0x0062f6fc`, secondary table `0x0062f74c`, and tertiary table `0x0062f77c`; the submit override is the primary-table slot `0x0062f744 -> 0x005b1640`.
- The combined 136-byte three-vtable window SHA256 is `DF86A1948CB1C9D5A748945E4B49442DAAF8E04459C878FFD225222A827A9B84`. Shared adjustors `0x005b7820`/`0x005b782b` and scalar deleting wrapper `0x005b7af0` are compiler-generated and must not be duplicated as source methods.
- Direct construction evidence includes a code caller at `0x0059edf7` in `sub_59ED60` and an inline legacy construction branch in `SayToUserNameInputPane::OnRecipientNameConfirmed` at `0x005b419b-0x005b41f9`; the latter runs when [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97` is false, while the modern branch calls [UID:000099][NewSayToUserMessageInputPane](by-class/NewSayToUserMessageInputPane.md) at `0x005b4128`.
- The legacy and modern direct-message panes share opcode `0x19`, packet-helper calls, two text conversions, and send path; their class distinction is the constructor/vtable/prompt/key-flow family, not a different network protocol.
- The sibling no-route helper [UID:000402][0x005b1820-0x005b1983.SayTargetMessagePacketHelperNoRouteA](by-memory/0x005b1820-0x005b1983.SayTargetMessagePacketHelperNoRouteA.md) is not part of this class. It has two stack wchar arguments, `ret 8`, no `this` receiver, no rel32 callers, and no pointer hits.

## Source Shape And Placement

- UID000401 owns the constructor and submit definitions; this class page owns their declarations and `m_recipientName` layout. UID0000N9 routes H to `NexusTK/social/SayInputPanes.h` and namespace-scope child definitions to `NexusTK/social/SayInputPanes.cpp`.
- The formal CPP/H split is intentional: `[[CHILDREN]]` only in class CPP, complete declaration only in class H, and blank H on UID000401. This avoids the historical generated topology where qualified child definitions were nested inside a CPP-resident class declaration.
- No explicit derived destructor, fixed vtable table, UID000402 helper, or target-local key handler belongs in source. Compiler lowering regenerates destructor wrappers, adjustors, vtables, EH, and checked-array instrumentation.

## Score Rationale

- Completion `93`: exact methods, layout, vtables, liveness routes, inherited input lifecycle, packet/source behavior, compiler-artifact separation, complete H declaration, children-only CPP route, and helper exclusion are resolved.
- Confidence `94`: body, caller, inline construction, vtable, layout, frame, prompt, and protocol evidence converge. Original private symbol spelling and exact source formatting remain unavailable.

## Cross-References

- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- [UID:000401][0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods](by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md)
- [UID:000402][0x005b1820-0x005b1983.SayTargetMessagePacketHelperNoRouteA](by-memory/0x005b1820-0x005b1983.SayTargetMessagePacketHelperNoRouteA.md)
- [UID:0001LY][0x005b1570-0x005b2562.SayTargetMessageInputPanes](by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md)
- [UID:0000C7][SayToUserNameInputPane](by-class/SayToUserNameInputPane.md)
- [UID:000099][NewSayToUserMessageInputPane](by-class/NewSayToUserMessageInputPane.md)

## Changes

- 2026-08-13 B006 accepted UID000401 ordinary implementation callback:
  - Raised `87/90 -> 93/94` while preserving UID0000N9 owner/emitter, reconstructable true, and blank optional position.
  - Moved the exact class declaration from formal CPP to formal H, reduced class CPP to `[[CHILDREN]]`, and omitted the explicit derived destructor so UID000401 definitions emit at namespace scope and the compiler regenerates the shared destructor route.
  - Added the exact `0x208` layout, `+0x108` recipient array, direct and inline construction evidence, primary `+0x48` submit identity, inherited input lifecycle, packet-local shape, vtable-window hash, compiler-artifact policy, source placement, and score rationale.
  - Historicalized the B013 CPP-resident declaration, explicit destructor, two conversion buffers, `0x230` packet, zero initialization, and silent source-level bounds returns; its valid class-role/layout/vtable/route evidence remains preserved.

- 2026-05-30: Changed completion/confidence from `0/0` to `74/78`.
  - Before: The page was unevaluated despite documenting legacy direct-message construction, prompt behavior, and opcode `0x19` payload.
  - After: Scored as moderate-high completion and confidence because behavior is clear while legacy-vs-modern placement remains a source-layout caveat.
  - Evidence: Existing method notes, IDA MCP start evidence, modern/legacy flow note, and cross-references to recipient-name and modern direct-message panes support the score.
- 2026-06-04:
  - Before: scored as `74/78`, with no reconstructable flag, no autogen parent, stale source-output wording, and only summarized start evidence.
  - After: scored as `84/88`, marked `RECONSTRUCTABLE:TRUE`, and parented to [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md).
  - Summary/evidence: live IDA MCP rechecked executable identity, exact constructor/submit/destructor-thunk boundaries, constructor body, prompt formatting, opcode `0x19` submit packet shape, packet helper callees, direct open caller, inline legacy construction branch from `SayToUserNameInputPane`, vtable/RTTI anchors, and modern-pane comparison; remaining uncertainty is source split and final private method names, so no final reconstruction C++ is emitted.
- 2026-06-20 supervisor Rule 26 incorporation of B001 `0001LY-SayTargetMessageInputPanes-source-quality.md`:
  - Before: `84/88`, no formal class C++, constructor endpoint still used older `0x005b1630` wording, and the sibling no-route helper was not excluded at class level.
  - After: `87/90`, declaration-only class C++ with `m_recipientName[128]` at `+0x108`, exact child [UID:000401][0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods](by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md) carries first-draft constructor/submit C++, constructor endpoint corrected to `0x005b1631`, and helper [UID:000402][0x005b1820-0x005b1983.SayTargetMessagePacketHelperNoRouteA](by-memory/0x005b1820-0x005b1983.SayTargetMessagePacketHelperNoRouteA.md) is explicitly excluded from class ownership.
  - Evidence: B001 PE/Capstone route and boundary pass confirmed direct constructor route `0x0059edf7`, submit vtable slot `0x0062f744`, prompt literal refs, opcode `0x19` packet shape, and negative route/pointer evidence for the sibling helper.
- 2026-06-20 B003 [UID:0000C7][SayToUserNameInputPane](by-class/SayToUserNameInputPane.md) source-quality sync:
  - Normalized the legacy inline construction branch selector from local "modern whisper-flow" wording to [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), and kept the branch documented as inline source-equivalent construction rather than a direct call to this class's standalone constructor.
- 2026-06-21 B013 `0000C6-SayToUserMessageInputPane-class-source-quality.md` sync:
  - Kept `87/90`, owner/emitter [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md), reconstructable status, declaration-only class C++, corrected constructor endpoint, and sibling helper exclusion.
  - Refined the exact child [UID:000401][0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods](by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md) so its first-draft submit body models the observed inline opcode `0x19` packet serialization instead of inventing a routed `SendTargetMessagePacket` call.
