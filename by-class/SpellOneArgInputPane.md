*** UID:0000DR | DO NOT MODIFY OR REMOVE!!! ***
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
class SpellOneArgInputPane : public NumberArgsInputPane
{
public:
    explicit SpellOneArgInputPane(char spellIndex);
    virtual ~SpellOneArgInputPane();

protected:
    virtual void OnSubmitInput();

private:
    char m_spellIndex;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

## UID0001LM Signed Prompt-Class Synchronization - 2026-07-19

- The complete declaration now takes plain `char spellIndex` and stores plain `char m_spellIndex` at complete-object `+0x108`. Repeated constructor/consumer `movsx` proves signed semantics; the object remains exactly `0x10c` bytes with natural tail alignment at `+0x109..+0x10b`.
- The class closes before `[[CHILDREN]]`, so exact child definitions emit at namespace scope rather than inside the class. Inheritance and every existing method declaration/access level are unchanged.
- Metadata rises `86/88 -> 89/92` because signed type, exact natural layout, complete declaration, and generated structure are closed. Exact owner/emitter/source route, unrelated method bodies, retained or ownerless no-route raw helpers, destructor/scalar/adjustor evidence, compiler exclusions, and history remain intact.
- Constructors use the shared public inline `UserPane::GetSpellPromptText(char) const`; no private cross-TU table access, `UserSpellRecord`, `GetSpellRecord`, or raw vtable/RTTI/compiler source is introduced.

# SpellOneArgInputPane
## UID0000LU Header Placement Synchronization - 2026-08-15

The accepted complete SpellOneArgInputPane declaration was moved verbatim from CPP to H for direct construction through `SpellInputPanes.h`. Existing children and NumberArgsInputPane behavior remain unchanged.

## Status

- Confidence: very strong for complete declaration, signed field/layout, constructor/direct-destructor/submit source order, virtual routes, three-view RTTI/vtables, and compiler-wrapper separation; generated panel helpers and `__wtol` are confirmed external dependencies.
- Likely source file: [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- Address range: [UID:0001LN][0x005b0780-0x005b14e6.SpellArgumentInputPanes](by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md)
- Current recovered file: `source-3/simroot_v2/class_SpellOneArgInputPane.cpp`

## Class Purpose

`SpellOneArgInputPane` collects one numeric argument for a spell and serializes it into an opcode `0x0f` spell-use packet. It derives from [UID:00009J][NumberArgsInputPane](by-class/NumberArgsInputPane.md).

The complete object is `0x10c` bytes. Its inherited primary pane lineage occupies the first `0xa0` bytes, EventHandler and TimerHandler facets begin at `+0xa0/+0xa4`, and signed `char m_spellIndex` is stored at `+0x108`; natural tail alignment covers `+0x109..+0x10b` without a synthetic source member or packing directive.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | [UID:0001LT][0x005b1030-0x005b10bd.SpellOneArgInputPaneConstructor](by-memory/0x005b1030-0x005b10bd.SpellOneArgInputPaneConstructor.md) | Builds numeric-args base, installs vtables, loads spell prompt text, and stores spell index. |
| destructor | [UID:0004UB][0x005b10c0-0x005b1143.SpellOneArgInputPaneDestructor](by-memory/0x005b10c0-0x005b1143.SpellOneArgInputPaneDestructor.md) | Sole human virtual destructor body; clears the mode-selected panel state while implicit base teardown remains compiler-generated. |
| `OnSubmitInput` | [UID:0001LU][0x005b1150-0x005b11f5.SpellOneArgInputPaneSubmitInput](by-memory/0x005b1150-0x005b11f5.SpellOneArgInputPaneSubmitInput.md) | Parses one integer and sends a 4-byte spell packet. |
| adjacent direct packet raw island | [UID:0003VW][0x005b1200-0x005b1278.SpellOneArgDirectArgumentPacketRaw](by-memory/0x005b1200-0x005b1278.SpellOneArgDirectArgumentPacketRaw.md) | B012-reviewed no-owner/non-emitting helper-shaped clone of the one-argument packet tail; attach here only if a future caller, pointer, vtable, or runtime route is proven. |
| adjustor thunks | [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md) | Secondary/tertiary vtable thunks to `0x005b7cf0`; source reconstruction excludes them through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| scalar deleting destructor | [UID:0001NF][0x005b7cf0-0x005b7db4.SpellOneArgInputPaneScalarDeletingDestructor](by-memory/0x005b7cf0-0x005b7db4.SpellOneArgInputPaneScalarDeletingDestructor.md) | Non-emitting compiler wrapper generated from this declaration, UID0004UB's body, inheritance, and delete expressions; adds flags, vptr/base/storage/guard/return lowering. |
| vtable/RTTI data | [UID:00026W][0x0062ef0c-0x006307ec.UserPaneInputVtables](by-memory/0x0062ef0c-0x006307ec.UserPaneInputVtables.md) | Compiler data; OneArg slice `[0x0062f5e4,0x0062f670)` has three views and regenerates from this complete declaration. |

## Exact Source / Compiler Closure

- Source order is constructor UID0001LT `[0x005b1030,0x005b10bd)`, three-byte alignment, direct destructor UID0004UB `[0x005b10c0,0x005b1143)`, thirteen-byte alignment, and virtual submit UID0001LU `[0x005b1150,0x005b11f5)`.
- UID0004UB's exact body SHA256 is `1F3FA67DDEF49075D8950CA6FD679AA250FE3660A853AAFC17B675ADC9DF8A18`; UID0001NF's exact compiler-wrapper SHA256 is `27DA758737FA1FDBAFDDA72D45331E995ED85E4DEDBD9C9C8E8B7DB4AF98127B`.
- Both functions contain the same mode-selected state clear. Only UID0001NF accepts deleting flags, returns `this`, invokes storage/guard paths, and carries compiler vptr/base/EH/cookie mechanics.
- Primary vtable cell `0x0062f5e4` points to UID0001NF; EventHandler/TimerHandler view cells route through adjustors at `0x005b788e/0x005b7899`, which subtract `0xa0/0xa4` and tail-jump UID0001NF. Submit slot `0x0062f62c` points to UID0001LU.
- RTTI string `.?AVSpellOneArgInputPane@@`, three COL views at offsets `0/0xa0/0xa4`, and an eight-base hierarchy (`SpellOneArgInputPane`, `NumberArgsInputPane`, `LineInputPane`, `Pane`, `GrafPort`, `LObject`, `EventHandler`, `TimerHandler`) prove the declaration and layout.
- The declaration closes before `[[CHILDREN]]`. One virtual destructor declaration plus UID0004UB's sole body regenerates the complete/scalar/adjustor/vtable compiler artifacts without duplicate human definitions.

## Ownership Caveats

- Generated `class_SpellOneArgInputPane.cpp` currently includes [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md) child/tab helpers at `0x004b85f0`, `0x004b8620`, `0x004b8630`, and `0x004b8650`; those should not migrate with spell input panes. Exact docs: [UID:00015W][0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors](by-memory/0x004b85f0-0x004b8643.GeneralPurposePanelChildAccessors.md) and [UID:00015X][0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab](by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md).
- Generated `SpellOneArgInputPane::__wtol` at [UID:0001O5][0x005cea43-0x005cea6d.CrtWtolWrapper](by-memory/0x005cea43-0x005cea6d.CrtWtolWrapper.md) is an IDA-recognized CRT `__wtol` wrapper with broad runtime caller fanout, not a project method.
- [UID:0003VW][0x005b1200-0x005b1278.SpellOneArgDirectArgumentPacketRaw](by-memory/0x005b1200-0x005b1278.SpellOneArgDirectArgumentPacketRaw.md) mirrors this class's one-argument spell packet send from one explicit `short` argument, but it is not currently a class-owned emitting method because no caller, pointer, vtable, generated output, or runtime route to `0x005b1200` is proven. If such a route appears, attach it here as a private helper, likely `SendSpellUsePacket(short argument)`. Best current name for the stored byte at object offset `+0x108` is `m_spellIndex`; packet-tail prose should use `PacketBufferWriteUInt8`, `PacketBufferWriteUInt16BE`, `g_packetSender`, and `QueueAndSendPacket`.
- Disabled generated output marks `0x005b7899` as missing code, but IDA confirms it as a real adjustor thunk.
- 2026-05-26 IDA recheck confirms the adjustor pair forwards to `0x005b7cf0` after `this - 0xa0` and `this - 0xa4`; the pair and the CRT wrapper are tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).
- Historical B002 source emission placed the destructor payload on UID0001NF because the direct variant lacked an exact page. Validator-issued UID0004UB and exact `0x83`/`0xc4` variant proof supersede only that carrier choice; the cleanup behavior and semantic class ownership remain valid.
- Human source excludes raw vptr stores, explicit base destruction, scalar flags, object-pointer return, storage release, guarded size, SEH/EH/cookies, adjustor arithmetic, and raw vtable/RTTI arrays.

## Cross-References

- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0001LN][0x005b0780-0x005b14e6.SpellArgumentInputPanes](by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md)
- [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md)
- [UID:0000DL][SpellFourArgsInputPane](by-class/SpellFourArgsInputPane.md)
- [UID:0000DV][SpellThreeArgsInputPane](by-class/SpellThreeArgsInputPane.md)
- [UID:0000DW][SpellTwoArgsInputPane](by-class/SpellTwoArgsInputPane.md)
- [UID:0003VW][0x005b1200-0x005b1278.SpellOneArgDirectArgumentPacketRaw](by-memory/0x005b1200-0x005b1278.SpellOneArgDirectArgumentPacketRaw.md)
- [UID:0004UB][0x005b10c0-0x005b1143.SpellOneArgInputPaneDestructor](by-memory/0x005b10c0-0x005b1143.SpellOneArgInputPaneDestructor.md)
- [UID:0001NF][0x005b7cf0-0x005b7db4.SpellOneArgInputPaneScalarDeletingDestructor](by-memory/0x005b7cf0-0x005b7db4.SpellOneArgInputPaneScalarDeletingDestructor.md)
- [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md)
- [UID:00026W][0x0062ef0c-0x006307ec.UserPaneInputVtables](by-memory/0x0062ef0c-0x006307ec.UserPaneInputVtables.md)

## Changes

- 2026-07-20 Agent-B001 UID0001NF accepted callback:
  - Raised `89/92 -> 91/94`, preserving owner/emitter UID0000O0, reconstructable true, blank position, and the exact complete declaration with class closure before `[[CHILDREN]]`.
  - Added UID0004UB as the sole source destructor, reclassified UID0001NF/UID0001N9/UID00026W as compiler support, and documented exact source order, hashes, three-view RTTI/vtables, eight-base hierarchy, `0x10c` natural layout, one-definition route, compiler exclusions, and superseded B002 carrier history.
  - Preserved constructor/submit/raw-helper behavior and every unrelated B002/B003/B004/B005 class fact.
- 2026-06-30 B002 SpellInputPanes implementation callback:
  - Added the accepted declaration-only `SpellOneArgInputPane : public NumberArgsInputPane` formal C++ block with `m_spellIndex` and `[[CHILDREN]]`.
  - Exact constructor, submit handler, and destructor source bodies remain on the by-memory child pages.
- 2026-06-19 B012 source-quality sync: recorded [UID:0003VW][0x005b1200-0x005b1278.SpellOneArgDirectArgumentPacketRaw](by-memory/0x005b1200-0x005b1278.SpellOneArgDirectArgumentPacketRaw.md) as a no-owner/non-emitting adjacent direct packet raw island, not a class method yet. Future route-proven attachment should be a private helper such as `SendSpellUsePacket(short argument)`, with `m_spellIndex` for the stored `+0x108` spell byte.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `88`.
- Evidence: the page documents role, constructor/submit/destructor/thunk memory docs, packet behavior, generated ownership exclusions, CRT wrapper exclusion, and ignored thunk handling; remaining completion gap is source-ready C++ detail.
- 2026-06-05: Marked reconstructable and attached to [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md).
- Evidence: live IDA MCP `lookup_funcs` confirms the constructor, submit handler, scalar deleting destructor, and adjustor thunk anchors at `0x005b1030`, `0x005b1150`, `0x005b7cf0`, `0x005b7878`, and `0x005b7899`; both class (`86/88`) and parent file (`88/80`) meet the 80/80 gate.
