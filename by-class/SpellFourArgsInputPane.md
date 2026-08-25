*** UID:0000DL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000O0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000O0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_DIALOGS_SPELLINPUTPANES_H
#define NEXUSTK_UI_DIALOGS_SPELLINPUTPANES_H

#include "InputPanes.h"

class SpellFourArgsInputPane : public NumberArgsInputPane
{
public:
    explicit SpellFourArgsInputPane(char spellIndex);
    virtual ~SpellFourArgsInputPane();

protected:
    virtual void OnConfirmInput();

private:
    char m_spellIndex;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SpellFourArgsInputPane
## UID0000LU Header Placement Synchronization - 2026-08-15

The accepted complete SpellFourArgsInputPane declaration was moved verbatim from CPP to H for direct construction through `SpellInputPanes.h`. Existing children and NumberArgsInputPane behavior remain unchanged.

## Status

- Confidence: very strong for behavior, exact layout, signed index semantics, source ownership, vtable/RTTI routing, and IDA boundaries; original private spelling remains inferred.
- Likely source file: [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- Address range: [UID:0001LN][0x005b0780-0x005b14e6.SpellArgumentInputPanes](by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md)
- Current recovered file: `source-3/simroot_v2/class_SpellFourArgsInputPane.cpp`

## Class Purpose

`SpellFourArgsInputPane` collects four numeric arguments for a spell and serializes them into an opcode `0x0f` spell-use packet. It derives from [UID:00009J][NumberArgsInputPane](by-class/NumberArgsInputPane.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | [UID:0001LM][0x005b0780-0x005b080d.SpellFourArgsInputPaneConstructor](by-memory/0x005b0780-0x005b080d.SpellFourArgsInputPaneConstructor.md) | Builds numeric-args base, installs vtables, loads spell prompt text, and stores spell index. |
| destructor | [UID:0004TY][0x005b0810-0x005b0893.SpellFourArgsInputPaneDestructor](by-memory/0x005b0810-0x005b0893.SpellFourArgsInputPaneDestructor.md) | Sole direct source body for `virtual ~SpellFourArgsInputPane()`; clears the active spell-input state before ordinary base cleanup lowering. |
| `OnConfirmInput` | [UID:0001LO][0x005b08a0-0x005b0a02.SpellFourArgsInputPaneConfirmInput](by-memory/0x005b08a0-0x005b0a02.SpellFourArgsInputPaneConfirmInput.md) | Reads four numbers and sends a 10-byte spell packet. |
| related no-route direct packet body | [UID:0003VT][0x005b0a10-0x005b0abb.SpellFourArgsDirectArgumentPacketRaw](by-memory/0x005b0a10-0x005b0abb.SpellFourArgsDirectArgumentPacketRaw.md) | B009-reviewed source-shaped helper body that sends opcode `0x0f`, stored `m_spellIndex` / `this+0x108`, and four 16-bit spell arguments from explicit stack parameters. It is not currently class-owned emitting code because no caller, pointer/table, vtable slot, raw-PE/rel32 route, or runtime route is proven. |
| adjustor thunks | [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md) | Secondary/tertiary vtable thunks to `0x005b7c20`; source reconstruction excludes them through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| scalar deleting destructor | [UID:0001NE][0x005b7c20-0x005b7ce4.SpellFourArgsInputPaneScalarDeletingDestructor](by-memory/0x005b7c20-0x005b7ce4.SpellFourArgsInputPaneScalarDeletingDestructor.md) | MSVC scalar-deleting wrapper covered by the direct source destructor plus ordinary allocation-site `delete`; it owns no second human destructor body. |

## Field Notes

- `SpellFourArgsInputPane` is exactly `0x10c` bytes. Its `NumberArgsInputPane` base occupies `+0x000..+0x107`; plain `char m_spellIndex` occupies `+0x108`; `+0x109..+0x10b` is natural tail alignment, not a source-declared byte array.
- `this + 0x108` is written by the constructor, consumed by `OnConfirmInput`, and consumed by the adjacent raw direct packet body. Repeated `movsx` before the `0x148` record-stride multiply proves signed plain-`char` semantics. Best current source member name remains `m_spellIndex`; exact original private spelling is not recovered.
- The public constructor takes `char spellIndex`; the source-ready prompt expression is `g_pUserPane->GetSpellPromptText(spellIndex)`. `UserSpellRecord`, `GetSpellRecord`, and `promptText` were unsupported historical draft names.
- B009 rejected stronger or less precise field names for the four-argument raw helper: `m_spellId` is possible at protocol level but less specific than the constructor's spell-record index use, `m_spellSlot` is plausible in UI language but collides with the separate spell-slot prompt family, and `m_opcode` is incorrect because opcode `0x0f` is immediate.
- If [UID:0003VT][0x005b0a10-0x005b0abb.SpellFourArgsDirectArgumentPacketRaw](by-memory/0x005b0a10-0x005b0abb.SpellFourArgsDirectArgumentPacketRaw.md) ever gains route evidence, the best descriptive method direction is `SendDirectArgumentPacket(short arg1, short arg2, short arg3, short arg4)` or `SendFourArgumentSpellPacket`. Until then it stays documented as related no-route evidence rather than a class declaration entry.

## Evidence Notes

- The constructor's three vtable views are `0x0062f440`, `0x0062f490`, and `0x0062f4c0`, corresponding to complete-object offsets `0`, `0xa0`, and `0xa4`. The primary confirm slot at `0x0062f488` points to `0x005b08a0`; RTTI has COL offsets `0`, `0xa0`, and `0xa4`, an eight-base hierarchy, and the `SpellFourArgsInputPane` class name.
- The exact constructor range is `[0x005b0780,0x005b080d)`, `0x8d`/141 bytes, body SHA256 `4DC1B7695598C04DEC5EA55CBA5F6545D6F8BF42DEE2E2524510B9DD89AB6680`. Three direct spell-inventory callers and one compiler-inlined `UserPane::UseCommandSlot` path construct the same `0x10c` object.
- Human source owns the constructor, the virtual destructor declaration and direct body at [UID:0004TY][0x005b0810-0x005b0893.SpellFourArgsInputPaneDestructor](by-memory/0x005b0810-0x005b0893.SpellFourArgsInputPaneDestructor.md), and the `OnConfirmInput` declaration/body. The direct body performs the class-specific active-input-state release; compiler-generated base cleanup, facet-vptr restoration, scalar deletion, adjustors, vtable stores, RTTI arrays, EH state, cookies, and cleanup funclets do not appear in the human declaration or method body.
- The exact direct destructor is `[0x005b0810,0x005b0893)`, `0x83` / 131 bytes, followed by thirteen parent-only `0xcc` alignment bytes at `[0x005b0893,0x005b08a0)`. Its normalized source body is emitted once through UID0000DL. The distant `[0x005b7c20,0x005b7ce4)` UID0001NE body is the compiler scalar wrapper, and the secondary/tertiary entries at `0x005b7878` and `0x005b7883` are compiler adjustors into that wrapper.
- IDA confirms the constructor, direct destructor, confirm handler, two thunks, and scalar deleting wrapper as distinct binary bodies with one source destructor declaration.
- 2026-07-06 B011 implementation callback reconfirmed [UID:0001LO][0x005b08a0-0x005b0a02.SpellFourArgsInputPaneConfirmInput](by-memory/0x005b08a0-0x005b0a02.SpellFourArgsInputPaneConfirmInput.md) as the vtable-routed active confirm handler: current MCP session `b001-0001I5` reports `sub_5B08A0`, the vtable/data xref at `0x0062f488`, and the sole target pointer bytes `a0 08 5b 00` at that slot. The handler still serializes `m_spellIndex` from `this+0x108` as packet byte `+1`; [UID:0003VT][0x005b0a10-0x005b0abb.SpellFourArgsDirectArgumentPacketRaw](by-memory/0x005b0a10-0x005b0abb.SpellFourArgsDirectArgumentPacketRaw.md) remains only related no-route direct packet evidence, not class-owned emitting code.
- Constructor callers are spell inventory cast dispatch paths at `0x0057c9b0`, `0x0057e2d0`, and `0x0057f030`.
- Disabled generated output marks `0x005b7883` as missing code, but IDA confirms it as a real adjustor thunk.
- 2026-05-26 IDA recheck confirms the adjustor pair forwards to `0x005b7c20` after `this - 0xa0` and `this - 0xa4`; the pair is tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).
- B009 rechecked the adjacent raw direct packet body at `0x005b0a10`: Ghidra/exported data recognizes a `0xab` / 171-byte `__thiscall(this, short, short, short, short)` body, but prior live IDA found no function object, no xrefs, and no pointer literal to `10 0A 5B 00`, while Ghidra reports zero callers and no data refs. This keeps the body outside the class emitter path for now.

## Cross-References

- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0001LN][0x005b0780-0x005b14e6.SpellArgumentInputPanes](by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md)
- [UID:0000DV][SpellThreeArgsInputPane](by-class/SpellThreeArgsInputPane.md)
- [UID:0000DW][SpellTwoArgsInputPane](by-class/SpellTwoArgsInputPane.md)
- [UID:0000DR][SpellOneArgInputPane](by-class/SpellOneArgInputPane.md)
- [UID:0003VT][0x005b0a10-0x005b0abb.SpellFourArgsDirectArgumentPacketRaw](by-memory/0x005b0a10-0x005b0abb.SpellFourArgsDirectArgumentPacketRaw.md)
- [UID:0004TY][0x005b0810-0x005b0893.SpellFourArgsInputPaneDestructor](by-memory/0x005b0810-0x005b0893.SpellFourArgsInputPaneDestructor.md)
- [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md)

## Changes

- 2026-07-20 Agent-B003 UID0001NE callback: raised `90/93 -> 91/94`; linked direct source destructor UID0004TY, reclassified UID0001NE as its compiler scalar-deleting wrapper, and recorded the exact direct range, parent-only alignment, source/compiler split, and one-declaration/one-source-body disposition. Preserved owner/emitter UID0000O0, reconstructable state, blank position, the complete R2 declaration byte-for-byte, exact `0x10c` natural layout, constructor/confirm/raw-helper evidence, and all unrelated history.
- 2026-07-19 Agent-B003 UID0001LM callback: raised `86/88 -> 90/93`; installed the exact complete declaration with signed `char`, exact `0x10c` natural layout, and class closure before `[[CHILDREN]]`; added exact constructor/vtable/RTTI/source/history evidence while preserving every confirm/raw/destructor/adjustor fact and source route.
- 2026-07-06 B011 UID0001LO implementation callback: added current MCP confirmation that [UID:0001LO][0x005b08a0-0x005b0a02.SpellFourArgsInputPaneConfirmInput](by-memory/0x005b08a0-0x005b0a02.SpellFourArgsInputPaneConfirmInput.md) is the vtable-routed active confirm handler through `0x0062f488`, preserved `m_spellIndex` at `this+0x108`, and kept [UID:0003VT][0x005b0a10-0x005b0abb.SpellFourArgsDirectArgumentPacketRaw](by-memory/0x005b0a10-0x005b0abb.SpellFourArgsDirectArgumentPacketRaw.md) as no-route related evidence without changing class metadata.
- 2026-06-30 B002 SpellInputPanes implementation callback:
  - Added the accepted declaration-only `SpellFourArgsInputPane : public NumberArgsInputPane` formal C++ block with `m_spellIndex` and `[[CHILDREN]]`.
  - Exact constructor, confirm handler, and destructor source bodies remain on the by-memory child pages.
- 2026-06-21 B009 Rule 26 source-quality sync: Added [UID:0003VT][0x005b0a10-0x005b0abb.SpellFourArgsDirectArgumentPacketRaw](by-memory/0x005b0a10-0x005b0abb.SpellFourArgsDirectArgumentPacketRaw.md) as related no-route direct packet evidence, recorded `this+0x108` as best current `m_spellIndex`, and preserved the no-emitter policy because no caller/pointer/vtable/raw-PE/runtime route proves liveness.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `88`.
- Evidence: the page documents the numeric spell-input role, exact constructor/confirm/destructor/thunk memory docs, callers, packet shape, and ignored adjustor-thunk handling; remaining completion gap is source-ready C++ detail.
- 2026-06-05: Marked reconstructable and attached to [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md).
- Evidence: live IDA MCP `lookup_funcs` confirms the constructor, confirm handler, scalar deleting destructor, and adjustor thunk anchors at `0x005b0780`, `0x005b08a0`, `0x005b7c20`, `0x005b7878`, and `0x005b7883`; both the class (`86/88`) and parent file (`88/80`) meet the 80/80 gate.
