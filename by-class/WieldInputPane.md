*** UID:0000G4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class WieldInputPane : public CharInputPane
{
public:
    WieldInputPane();
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void OnSubmitInput();

private:
    int SendWieldPacket(unsigned char itemSlot);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Complete source-facing WieldInputPane declaration with constructor, active Event handler, submit override, and one private nonvirtual packet member; registered source children [UID:0004U2][0x005b62d0-0x005b6397.WieldInputPaneConstructor](by-memory/0x005b62d0-0x005b6397.WieldInputPaneConstructor.md), [UID:0004U4][0x005b63a0-0x005b640c.WieldInputPaneHandleKeyOrTextEvent](by-memory/0x005b63a0-0x005b640c.WieldInputPaneHandleKeyOrTextEvent.md), [UID:0004U6][0x005b6410-0x005b64fa.WieldInputPaneOnSubmitInput](by-memory/0x005b6410-0x005b64fa.WieldInputPaneOnSubmitInput.md), and [UID:0001MS][0x005b6500-0x005b6560.SendWieldPacket](by-memory/0x005b6500-0x005b6560.SendWieldPacket.md) emit the definitions while the class preserves exact prompt/help/signed-selector/packet/vtable/compiler/history evidence. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# WieldInputPane

## B003 2026-07-20 Event Contract Synchronization

- The compact `0x005b63a0` help override is `bool HandleKeyOrTextEvent(Event *event)`: translate key/modifiers, require translated `?`, exact Shift `0x04`, and key-down, switch tab `2` with `NULL`, play effect `0x198` at 100, return true, otherwise use the existing CharInputPane base handler.
- Wield construction, typed slot validation, packet behavior, children, vtable/compiler evidence, scores, route, formal block, and history remain unchanged. Stale `OnKeyInput`/`InputEvent`/`NarrowInputKey`/`false` wording is superseded only.

## Status

- Confidence: strong for behavior and item-action input module placement.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address range: [UID:0001MR][0x005b62d0-0x005b64fa.WieldInputPane](by-memory/0x005b62d0-0x005b64fa.WieldInputPane.md), helper [UID:0001MS][0x005b6500-0x005b6560.SendWieldPacket](by-memory/0x005b6500-0x005b6560.SendWieldPacket.md)

## Class Purpose

`WieldInputPane` is the weapon-wield prompt. It accepts one inventory slot letter and sends the wield packet for the selected item slot. The `-` input is a confirmed zero-slot path that sends opcode `0x12` with selector `0`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `WieldInputPane` | [UID:0004U2][0x005b62d0-0x005b6397.WieldInputPaneConstructor](by-memory/0x005b62d0-0x005b6397.WieldInputPaneConstructor.md) | Calls `CharInputPane(NULL)`, obtains inventory-slot range text, formats prompt id `13`, and calls `SetPromptText`; explicit vptr stores and the cookie are compiler effects. |
| `HandleKeyOrTextEvent` | [UID:0004U4][0x005b63a0-0x005b640c.WieldInputPaneHandleKeyOrTextEvent](by-memory/0x005b63a0-0x005b640c.WieldInputPaneHandleKeyOrTextEvent.md) | Handles exact Shift-question help behavior and delegates all other input to `CharInputPane`. |
| `OnSubmitInput` | [UID:0004U6][0x005b6410-0x005b64fa.WieldInputPaneOnSubmitInput](by-memory/0x005b6410-0x005b64fa.WieldInputPaneOnSubmitInput.md) | Reads exactly one character, preserves signed slot mapping/validation, and sends wield opcode `0x12`. |
| `SendWieldPacket` | [UID:0001MS][0x005b6500-0x005b6560.SendWieldPacket](by-memory/0x005b6500-0x005b6560.SendWieldPacket.md) | Private nonvirtual member called once by `OnSubmitInput` after the caller loads the Wield receiver into `ECX`; writes opcode/selector plus local terminator and sends exactly two bytes. |

## Evidence Notes

- IDA MCP confirms all three function starts.
- IDA MCP recheck on 2026-05-26 confirms `0x005b6500-0x005b6560` has a single caller inside `WieldInputPane::OnSubmitInput`, so it belongs with this class/module rather than [UID:0000G0][WearInputPane](by-class/WearInputPane.md).
- IDA MCP recheck on 2026-05-27 confirms the constructor uses prompt id `0x0d`, calls `CharInputPane::CharInputPane`, gets the local player name from [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / historical IDA alias `dword_67A748`, formats the prompt, and installs vtables `0x006304a8`, `0x006304f8`, and `0x00630528`.
- IDA decompilation of `0x005b6410` confirms slot conversion: lowercase `a-z` becomes `1-26`, uppercase `A-Z` becomes `27-52`, and the accepted value must be between `1` and byte offset `+0x284` from [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md).
- The normal validated slot path calls [UID:0001MS][0x005b6500-0x005b6560.SendWieldPacket](by-memory/0x005b6500-0x005b6560.SendWieldPacket.md); the `-` path sends opcode `0x12`, selector `0`, and length `2` inline through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md).
- IDA MCP recheck on 2026-06-05 against `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` confirms starts and sizes for `0x005b62d0` (`0xc7`), `0x005b63a0` (`0x6c`), `0x005b6410` (`0xea`), and helper `0x005b6500` (`0x60`), with `0xcc` padding between methods and [UID:0000G0][WearInputPane](by-class/WearInputPane.md) beginning cleanly at `0x005b6560`.
- Current IDA decompilation confirms the packet opcode directly: both the inline `'-'` path and [UID:0001MS][0x005b6500-0x005b6560.SendWieldPacket](by-memory/0x005b6500-0x005b6560.SendWieldPacket.md) write opcode `0x12`, append one selector byte, and send length `2`.
- Historical helper-body-only analysis observed no `ECX` read and proposed a private/static-style helper. Target-specific caller reanalysis supersedes only the static/free ownership: the sole call at `0x005b64e6` explicitly loads `ECX` with the `WieldInputPane` receiver before pushing the one selector argument, selecting private nonvirtual member `int SendWieldPacket(unsigned char itemSlot)`; optimization explains the unused receiver in the callee body.
- 2026-06-21 B012 source-quality reanalysis correctly closed the stale blank-C++/gate issue for [UID:0001MS][0x005b6500-0x005b6560.SendWieldPacket](by-memory/0x005b6500-0x005b6560.SendWieldPacket.md). Its exact opcode `0x12`, selector byte, local-only terminator, two-byte send, `PacketBufferWriteUInt8`, and `g_packetSender->QueueAndSendPacket` evidence remains valid; only its historical static/member preference is corrected by the target caller ABI.

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001MR][0x005b62d0-0x005b64fa.WieldInputPane](by-memory/0x005b62d0-0x005b64fa.WieldInputPane.md)
- [UID:0001MS][0x005b6500-0x005b6560.SendWieldPacket](by-memory/0x005b6500-0x005b6560.SendWieldPacket.md)
- [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md)
- [UID:00028L][0x0067a754-0x0067a758.g_pEventMan](by-memory/0x0067a754-0x0067a758.g_pEventMan.md)
- [UID:0000R0][g_pGeneralPurposePanel](by-global/g_pGeneralPurposePanel.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0000G0][WearInputPane](by-class/WearInputPane.md)
- [UID:0000EC][TakeOffInputPane](by-class/TakeOffInputPane.md)

## B005 2026-06-30 Empty-Emitter Callback

- Historical callback output: the `RECONSTRUCTION_CPP CODE` block then emitted a no-standalone marker plus `[[CHILDREN]]`. Current D6 replaces that marker with the complete source-clean class declaration while retaining child assembly and non-duplicating definition ownership.
- Route proof: [UID:0001MR][0x005b62d0-0x005b64fa.WieldInputPane](by-memory/0x005b62d0-0x005b64fa.WieldInputPane.md) covers Wield constructor `0x005b62d0-0x005b6397`, key handler `0x005b63a0-0x005b640c`, and submit path `0x005b6410-0x005b64fa`. Exact packet helper source is [UID:0001MS][0x005b6500-0x005b6560.SendWieldPacket](by-memory/0x005b6500-0x005b6560.SendWieldPacket.md). [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md) records Wield vtables `0x006304a8`, `0x006304f8`, and `0x00630528` with action/input slots.
- Historical limitation: that callback lacked exact constructor/Event/submit child source. Current class-page declaration is required to cause the source and compiler vtable while exact children emit definitions once; duplicate class or method emission remains rejected.

## B004 2026-07-20 Complete Wield Source Closure

- The former B005 no-standalone class marker and aggregate-source dependency are historical. Current source emission is non-duplicating: this complete declaration owns the class route, [UID:0004U2][0x005b62d0-0x005b6397.WieldInputPaneConstructor](by-memory/0x005b62d0-0x005b6397.WieldInputPaneConstructor.md), [UID:0004U4][0x005b63a0-0x005b640c.WieldInputPaneHandleKeyOrTextEvent](by-memory/0x005b63a0-0x005b640c.WieldInputPaneHandleKeyOrTextEvent.md), [UID:0004U6][0x005b6410-0x005b64fa.WieldInputPaneOnSubmitInput](by-memory/0x005b6410-0x005b64fa.WieldInputPaneOnSubmitInput.md), and [UID:0001MS][0x005b6500-0x005b6560.SendWieldPacket](by-memory/0x005b6500-0x005b6560.SendWieldPacket.md) emit exactly one definition each, and non-emitting [UID:0001MR][0x005b62d0-0x005b64fa.WieldInputPane](by-memory/0x005b62d0-0x005b64fa.WieldInputPane.md) remains the physical split index.
- Constructor behavior is exact: `CharInputPane(NULL)`, `wchar_t slotRange[100]`, [UID:0004R7][0x005a40d0-0x005a430c.UserPaneBuildInventorySlotRangeText](by-memory/0x005a40d0-0x005a430c.UserPaneBuildInventorySlotRangeText.md) `BuildInventorySlotRangeText`, localized prompt id `13`, `wchar_t prompt[128]`, `swprintf_s` capacity `128`, and [UID:00018Y][0x004f20a0-0x004f22f4.LineInputPaneSetPromptText](by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md) `SetPromptText`. Historical player-name wording is rejected by the resolved helper call.
- `HandleKeyOrTextEvent(Event *)` is active through Wield vtable slot `0x00630500`. It translates key/modifiers through `g_pEventMan`, requires `?`, Shift `4`, and key-down `8`, switches `g_pGeneralPurposePanel` to tab `2` with `NULL`, plays effect `0x198` at volume `100`, and otherwise calls `CharInputPane::HandleKeyOrTextEvent`.
- `OnSubmitInput()` is active through Wield vtable slot `0x006304f0`. It requires `TextLength() == 1`, copies one wide character, sends `[0x12, 0]` length `2` for dash, maps lowercase to `1-26` and uppercase to `27-52` using the observed signed plain-`char` comparison/extension shape, validates against `g_activeUserStatusPane->m_inventorySlotCount` at binary offset `+0x284`, and calls the private member helper only for a valid normal selector.
- The separately retained outlined [UID:0004U0][0x005a9f00-0x005a9fd6.CreateWieldInputPane](by-memory/0x005a9f00-0x005a9fd6.CreateWieldInputPane.md) and the UserPane lower-case `w` inline construction are source-liveness evidence, not duplicate class methods. The complete source model rejects aggregate emission, `OnCharInput`, unsigned local semantics, static/free helper ownership, duplicate helper source, and handwritten vptr/cookie/padding source.

## Changes

- 2026-06-21 B012 SendWieldPacket source-quality incorporation:
  - Score unchanged at `86/90`.
  - Updated the helper row and evidence notes to state that [UID:0001MS][0x005b6500-0x005b6560.SendWieldPacket](by-memory/0x005b6500-0x005b6560.SendWieldPacket.md) is now code-ready and emits first-draft private/static helper C++ through the Wield route.
  - Preserved class-level C++ blank status while the exact helper body emits on the by-memory child; this class page remains the source/ownership parent for constructor/input/submit/private helper documentation.
- 2026-06-07 A008 alias cleanup:
  - Before: constructor evidence used bare `dword_67A748` wording for the local-player name source.
  - Changed to: canonical [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) wording while preserving `dword_67A748` as the historical IDA alias.
  - Evidence: the global page records `0x0067a748` as a broad player/client-state pointer, including item-command prompt views.
- 2026-06-05 autogen metadata classification:
  - What existed before: reconstruction autogen metadata was unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with parent [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
  - Summary/evidence: live IDA MCP against `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` confirmed the constructor, char handler, submit path, and private packet helper starts at `0x005b62d0`, `0x005b63a0`, `0x005b6410`, and `0x005b6500`; the class and parent both pass the 80/80 parent gate. No reconstruction C++ was emitted because the page is below 95/95.

- 2026-06-05 stale evidence cleanup and helper refresh:
  - What existed before: status/evidence still referenced a stale output path and non-IDA opcode evidence for `0x12`.
  - Changed to: removed stale output provenance from the class page and replaced opcode/helper support with current IDA MCP decompilation and boundary evidence.
  - Summary/evidence: current IDA MCP confirms opcode `0x12` in both the inline zero-slot path and the private helper, confirms the helper's single caller at `0x005b64e6`, and confirms `WearInputPane` starts cleanly at `0x005b6560`.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:90`.
  - Summary/evidence: scored from the constructor/input/submit/private packet-helper method map, IDA-confirmed prompt id, vtables, slot conversion bounds, zero-slot `-` path, opcode `0x12` send behavior, and helper ownership evidence.
