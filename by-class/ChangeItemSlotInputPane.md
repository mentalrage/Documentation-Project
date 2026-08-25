*** UID:00001J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ChangeItemSlotInputPane : public CharArgsInputPane
{
public:
    ChangeItemSlotInputPane();
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void OnSubmitInput();
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ChangeItemSlotInputPane

## Status

- Confidence: strong for handler behavior, raw constructor bytes, vtable identity, first-draft constructor and method source shape, and module placement; medium for raw-constructor and retained raw-sender reachability/modeling.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address ranges: raw constructor [UID:0001M5][0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor](by-memory/0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor.md), methods [UID:0001M6][0x005b3010-0x005b3196.ChangeItemSlotInputPane](by-memory/0x005b3010-0x005b3196.ChangeItemSlotInputPane.md)
- Historical recovered-source lead: `source-3/simroot_v2/class_ChangeItemSlotInputPane.cpp`; current source-routing authority is the by-* documentation, current MCP evidence, and the [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) route.

## Class Purpose

`ChangeItemSlotInputPane` is the command prompt for moving an item from one inventory slot letter to another. It expects comma-separated slot letters, validates both against the local inventory slot count, and sends a change-slot packet.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ChangeItemSlotInputPane` | `0x005b2fd0-0x005b3010` | Raw constructor-shaped body now first-draft populated as `CharArgsInputPane(g_pLanguageMan->GetLocalizedString(46))`; IDA does not recognize this as a function start and no raw-start xrefs exist. |
| `HandleKeyOrTextEvent` | `0x005b3010-0x005b307c` | Translates Event key/modifiers, handles exact Shift-only `?` key-down by switching `g_pGeneralPurposePanel` to tab `2` and playing sound `0x198`, otherwise delegates to `CharArgsInputPane::HandleKeyOrTextEvent`; older `HandleInputEvent`/`OnKeyInput` wording is superseded. |
| `OnSubmitInput` | `0x005b3080-0x005b3196` | Parses `source,dest` slot letters, validates both against `g_activeUserStatusPane->m_inventorySlotCount`, and sends opcode `0x30` subcommand `0` with explicit length `4`; now emits first-draft method C++ through [UID:0001M6][0x005b3010-0x005b3196.ChangeItemSlotInputPane](by-memory/0x005b3010-0x005b3196.ChangeItemSlotInputPane.md). |
| `ChangeItemSlotPacketRawSender` | `0x005b31a0-0x005b3215` | Retained no-route raw packet sender page [UID:00042U][0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender](by-memory/0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender.md); associated with this class's item-slot command semantics, but now source-bearing as the [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) file-scope helper `static void __stdcall SendChangeItemSlotPacket(signed char sourceSlot, signed char destinationSlot)`. |

## Layout And Construction Anchors

- Base class: [UID:00001O][CharArgsInputPane](by-class/CharArgsInputPane.md). The raw constructor and the equivalent factory path both call [UID:000367][0x004f2a60-0x004f2ad3.CharArgsInputPaneConstructor](by-memory/0x004f2a60-0x004f2ad3.CharArgsInputPaneConstructor.md) after resolving localized prompt id `0x2e` / 46 (Verified with int_convert.py).
- Object size evidence: IDA MCP decompilation of factory `0x005a93b0` allocates `0x108` / 264 bytes (Verified with int_convert.py) before installing this class's vtables.
- Vtable views: primary `0x0062fa44`, secondary `0x0062fa94` at object offset `+0xa0` / 160, and tertiary `0x0062fac4` at `+0xa4` / 164 (offset conversions verified with int_convert.py).
- Slot anchors: live IDA MCP `get_global_value` on 2026-06-13 reports primary action slot `0x0062fa8c -> 0x005b3080`, secondary input slot `0x0062fa9c -> 0x005b3010`, secondary first slot `0x0062fa94 -> 0x005b77c8`, tertiary first slot `0x0062fac4 -> 0x005b77d3`, and tertiary default/update slot `0x0062fac8 -> 0x00544e90`.

## Evidence Notes

- IDA MCP confirms `0x005b3010` and `0x005b3080`.
- IDA reports no function at `0x005b2fd0`.
- IDA recheck on 2026-05-26 resolves preceding real function `0x005b2f70-0x005b2fcb` as the [UID:00004B][EmotionInputPane](by-class/EmotionInputPane.md) packet helper, not this class's constructor.
- 2026-05-27 raw IDA disassembly confirms the constructor-shaped bytes at `0x005b2fd0-0x005b3010`: localized prompt id `0x2e`, `CharArgsInputPane` base construction, and vtable stores to `0x0062fa44`, `0x0062fa94`, and `0x0062fac4`.
- 2026-05-27 IDA decompilation confirms `OnSubmitInput` reads text through the shared input getter, splits on comma, maps `a-z` to `1-26` and `A-Z` to `27-52`, reads max slots from [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md) at `+0x284`, and sends `[0x30, 0, source, dest]` through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md).
- 2026-06-02 IDA MCP refresh confirms `HandleInputEvent` is vtable-reached from secondary slot `0x0062fa9c`, `OnSubmitInput` is vtable-reached from primary slot `0x0062fa8c`, and the raw constructor stores are also duplicated by command/factory construction paths at `0x005a617d/0x005a6185/0x005a618f` and `0x005a9406/0x005a940c/0x005a9416`.
- IDA MCP confirms internal alignment padding at `0x005b307c-0x005b3080` and `0x005b3196-0x005b31a0`, plus the preceding Emotion-helper alignment at `0x005b2fcb-0x005b2fd0`.
- 2026-06-13 IDA MCP session `a002_batch_clear_timer` refreshed the raw constructor page: `lookup_funcs` still reports no function at `0x005b2fd0`, `get_bytes` confirms the exact `0x40` / 64-byte constructor body (Verified with int_convert.py), `insn_query` decodes the prompt lookup/base-constructor/vtable-store/return sequence, and `xrefs_to` still reports no direct xrefs to the raw start.
- The same refresh decompiled `0x005a93b0` as the inline factory path for this class: allocate `0x108` / 264 bytes (Verified with int_convert.py), call localization lookup for prompt id `46`, call `sub_4F2A60`, then store the same three `ChangeItemSlotInputPane` vtables.
- 2026-06-25 B001 source-quality implementation for [UID:0001M5][0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor](by-memory/0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor.md) uses current IDA MCP session `80de0a67`: `lookup_funcs` still reports no function at `0x005b2fd0` or `0x005b300f`, the next modeled method remains `0x005b3010`, `get_bytes` reconfirms the exact `0x40` / 64-byte raw constructor body (Verified with int_convert.py) after five predecessor `0xcc` padding bytes, `xrefs_to 0x005b2fd0` and pointer-pattern `D0 2F 5B 00` are both empty, and the raw instruction sequence still resolves prompt id `0x2e` / 46 (Verified with int_convert.py), calls [UID:000367][0x004f2a60-0x004f2ad3.CharArgsInputPaneConstructor](by-memory/0x004f2a60-0x004f2ad3.CharArgsInputPaneConstructor.md), then installs vtables `0x0062fa44`, `0x0062fa94`, and `0x0062fac4`.
- The same B001 pass confirms the source-shape rationale for constructor C++: the retained raw body, the `sub_5A5BD0` dispatcher mirror, and compact factory `sub_5A93B0` all perform the same prompt lookup/base-constructor/vtable-store operation. The class documentation should keep the no-function/no-start-xref caveat as a score limiter, but [UID:0001M5][0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor](by-memory/0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor.md) no longer depends on a blank-C++ / 95% blocker.
- 2026-06-26 B006 source-quality implementation for [UID:0001M6][0x005b3010-0x005b3196.ChangeItemSlotInputPane](by-memory/0x005b3010-0x005b3196.ChangeItemSlotInputPane.md) uses current IDA MCP session `80de0a67`: `lookup_funcs` reconfirms `sub_5B3010` and `sub_5B3080`, vtable data xrefs `0x0062fa9c` and `0x0062fa8c` remain the only routes, `OnKeyInput` handles the `?` shortcut before delegating to `CharArgsInputPane::OnKeyInput`, and `OnSubmitInput` maps slot letters, validates against `g_activeUserStatusPane + 0x284` reconstructed as `m_inventorySlotCount`, writes opcode `0x30` subcommand `0`, sends length `4`, and preserves a local-only trailing zero.
- The B006 split created adjacent retained item-slot raw sender [UID:00042U][0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender](by-memory/0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender.md). The B001 2026-06-29 callback supersedes the old class-owned blank-C++ disposition: current MCP session `d4d50b81` keeps the no-function/no-xref/no-pointer/no-rel32 route caveat, but the exact body now emits as the [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) file-scope helper `SendChangeItemSlotPacket`. [UID:0001M6][0x005b3010-0x005b3196.ChangeItemSlotInputPane](by-memory/0x005b3010-0x005b3196.ChangeItemSlotInputPane.md) still does not call it and keeps the submit packet send inline.

## Direct Parent Gate

## B003 2026-07-20 Event Contract Completion

- The complete class declaration now owns the constructor, canonical `bool HandleKeyOrTextEvent(Event *event)`, and `void OnSubmitInput()`, closes before `[[CHILDREN]]`, and lets exact constructor/method children emit at namespace scope.
- The corresponding R20 method block preserves the entire submit parser, inventory bound, packet bytes, send length, retained helper distinction, padding, raw-constructor history, and source placement. Only the proven shared Event translator/modifier/type/base vocabulary changes.
- The score rises from `85/88` to `90/92`; exact method and class source shape are complete, while raw-constructor/helper liveness and private field names remain confidence caps.

This class is the direct semantic parent for the raw constructor [UID:0001M5][0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor](by-memory/0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor.md) and the method cluster [UID:0001M6][0x005b3010-0x005b3196.ChangeItemSlotInputPane](by-memory/0x005b3010-0x005b3196.ChangeItemSlotInputPane.md). It remains semantic context for retained raw sender [UID:00042U][0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender](by-memory/0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender.md), but UID00042U's direct owner/emitter is now [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) because the helper body reads no `this`/object state and is source-shaped as a file-scope static helper. The class scores `85/88`, the accepted raw constructor child scores `87/90`, the method cluster scores `88/91`, UID00042U now scores `88/91`, and the source file parent remains `90/85`, so the class-to-file and direct file-scope helper routes clear the strict `85/85` gate.

The constructor child and method cluster each emit their own formal C++ from their exact by-memory pages. Retained raw sender [UID:00042U][0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender](by-memory/0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender.md) emits on its exact page as ItemActionInputPanes file-scope `SendChangeItemSlotPacket`; its no-route evidence remains a confidence/name cap and prevents rewriting `OnSubmitInput` to call it without future route proof.

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001M5][0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor](by-memory/0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor.md)
- [UID:0001M6][0x005b3010-0x005b3196.ChangeItemSlotInputPane](by-memory/0x005b3010-0x005b3196.ChangeItemSlotInputPane.md)
- [UID:00042U][0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender](by-memory/0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender.md)
- [UID:0000EC][TakeOffInputPane](by-class/TakeOffInputPane.md)
- [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)

## B005 2026-06-30 Empty-Emitter Callback

- Formal output: the `RECONSTRUCTION_CPP CODE` block emits the accepted no-standalone marker plus `[[CHILDREN]]` so exact constructor/method/helper children assemble under this route. This class page is a routing/ownership destination, not a separate source body beyond its exact children.
- Route proof: exact constructor source is [UID:0001M5][0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor](by-memory/0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor.md); exact virtual key/submit source is [UID:0001M6][0x005b3010-0x005b3196.ChangeItemSlotInputPane](by-memory/0x005b3010-0x005b3196.ChangeItemSlotInputPane.md); retained packet helper source is [UID:00042U][0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender](by-memory/0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender.md). [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md) records the `0x0062fa94 -> 0x005b3010` secondary input slot and `0x0062fa44 +0x48 -> 0x005b3080` primary submit slot.
- Rejected emission: a whole-class declaration/body here would duplicate the constructor/method/helper children and would require stabilizing shared input-pane inheritance, destructor/adjustor representation, virtual method spellings, and member fields across the broader family before the class page could become a source-shaped declaration target.

## Changes

- What existed before: the page documented behavior, raw constructor evidence, submit parsing, globals, and packet sender usage, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `76/82`.
- Summary and evidence: IDA-confirmed handler/submission behavior and raw constructor disassembly support the class identity; unresolved constructor reachability and final layout keep the page below complete.
- 2026-06-02 IDA MCP refresh:
  - Changed to: `COMPLETION:82`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
  - Why: exact raw constructor bytes, vtable store/call-site evidence, virtual slot refs, event shortcut behavior, submit parser, packet layout, status-pane slot-count read, and padding boundaries are documented. C++ remains blank because final helper names and source spelling are below the 95% bar.
- 2026-06-13 A002 Goal2 direct-parent gate refresh:
  - Before: `COMPLETION:82`, `CONFIDENCE:86`.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:88`.
  - Why: live IDA MCP refreshed exact raw constructor bytes, factory allocation/object-size evidence, localized prompt id, base-constructor call, vtable slot anchors, and no-start-xref caveat. This is enough for the class to own the raw constructor directly while keeping final C++ blank below the 95/95 source-emission gate.
- 2026-06-25 B001 [UID:0001M5][0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor](by-memory/0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor.md) implementation sync:
  - Score unchanged at `85/88`.
  - Updated method/evidence notes to record that the raw constructor child now emits first-draft constructor C++ through its own exact by-memory page, while preserving raw no-function/no-start-xref evidence as a reachability and score caveat.
  - Clarified that the class page itself still stays blank and that [UID:0001M6][0x005b3010-0x005b3196.ChangeItemSlotInputPane](by-memory/0x005b3010-0x005b3196.ChangeItemSlotInputPane.md) event/submit C++ remains separate from the constructor child.
- 2026-06-26 B006 [UID:0001M6][0x005b3010-0x005b3196.ChangeItemSlotInputPane](by-memory/0x005b3010-0x005b3196.ChangeItemSlotInputPane.md) implementation sync:
  - Score unchanged at `85/88`.
  - Updated method names to `OnKeyInput` and `OnSubmitInput`, recorded that [UID:0001M6][0x005b3010-0x005b3196.ChangeItemSlotInputPane](by-memory/0x005b3010-0x005b3196.ChangeItemSlotInputPane.md) now emits first-draft method C++ in its formal block, and added adjacent raw sender [UID:00042U][0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender](by-memory/0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender.md) as a separate class-owned no-route helper page with blank formal C++.
  - Evidence: current MCP session `80de0a67` reconfirmed the vtable-only routes, method bounds, `?` shortcut, slot-letter mapping, `m_inventorySlotCount` validation, opcode `0x30` subcommand `0`, send length `4`, local-only trailing zero, and no route to the retained raw sender.
- 2026-06-29 B001 [UID:00042U][0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender](by-memory/0x005b31a0-0x005b3215.ChangeItemSlotPacketRawSender.md) implementation sync:
  - Score unchanged at `85/88`.
  - Historicalized `source-3/simroot_v2/class_ChangeItemSlotInputPane.cpp` as a recovered-source lead only.
  - Updated UID00042U from class-owned blank-C++ to source-bearing ItemActionInputPanes file-scope helper `SendChangeItemSlotPacket`, while keeping this class as semantic context for the change-item-slot prompt.
  - Evidence: restored MCP session `d4d50b81` and supplemental PE route scan confirm no modeled function, xref, VA/RVA pointer, or rel32 route for UID00042U, but exact opcode `0x30`, subcommand `0`, two signed stack slot arguments, local-only terminator, send length `4`, `retn 8`, and unique padding-separated body support the retained file-scope helper. `OnSubmitInput` remains inline and must not call UID00042U without future route proof.
