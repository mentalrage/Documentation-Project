*** UID:0000DV | DO NOT MODIFY OR REMOVE!!! ***
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
class SpellThreeArgsInputPane : public NumberArgsInputPane
{
public:
    explicit SpellThreeArgsInputPane(char spellIndex);
    virtual ~SpellThreeArgsInputPane();

protected:
    virtual void OnConfirmInput();

private:
    char m_spellIndex;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

## UID0001LM Signed Prompt-Class Synchronization - 2026-07-19

- The complete declaration now takes plain `char spellIndex` and stores plain `char m_spellIndex` at complete-object `+0x108`. Repeated constructor/consumer `movsx` proves signed semantics; the object remains exactly `0x10c` bytes with natural tail alignment at `+0x109..+0x10b`.
- The class closes before `[[CHILDREN]]`, so exact child definitions emit at namespace scope rather than inside the class. Inheritance and every existing method declaration/access level are unchanged.
- Metadata rises `86/88 -> 89/92` because signed type, exact natural layout, complete declaration, and generated structure are closed. Exact owner/emitter/source route, unrelated method bodies, retained or ownerless no-route raw helpers, destructor/scalar/adjustor evidence, compiler exclusions, and history remain intact.
- Constructors use the shared public inline `UserPane::GetSpellPromptText(char) const`; no private cross-TU table access, `UserSpellRecord`, `GetSpellRecord`, or raw vtable/RTTI/compiler source is introduced.

# SpellThreeArgsInputPane
## UID0000LU Header Placement Synchronization - 2026-08-15

The accepted complete SpellThreeArgsInputPane declaration was moved verbatim from CPP to H for direct construction through `SpellInputPanes.h`. Existing children and NumberArgsInputPane behavior remain unchanged.

## Status

- Confidence: strong for behavior and IDA boundaries.
- Likely source file: [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- Address range: [UID:0001LN][0x005b0780-0x005b14e6.SpellArgumentInputPanes](by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md)
- Current source route: [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md). The former `source-3/simroot_v2/class_SpellThreeArgsInputPane.cpp` route is historical recovered-output provenance, not the current reconstruction owner.

## Class Purpose

`SpellThreeArgsInputPane` collects three numeric arguments for a spell and serializes them into an opcode `0x0f` spell-use packet. It derives from [UID:00009J][NumberArgsInputPane](by-class/NumberArgsInputPane.md).

The one-byte field at `this + 0x108` is best documented as `m_spellIndex`: the constructor stores the selected spell byte there, [UID:0001LQ][0x005b0be0-0x005b0cfd.SpellThreeArgsInputPaneConfirmInput](by-memory/0x005b0be0-0x005b0cfd.SpellThreeArgsInputPaneConfirmInput.md) serializes it as packet byte `+1`, and the retained raw direct-argument packet island [UID:0003VU][0x005b0d00-0x005b0d9a.SpellThreeArgsDirectArgumentPacketRaw](by-memory/0x005b0d00-0x005b0d9a.SpellThreeArgsDirectArgumentPacketRaw.md) uses the same byte. `m_spellIndex` is descriptive, not recovered header spelling; avoid stronger `m_spellId` or `m_spellSlot` wording unless new caller/header evidence appears.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | [UID:0001LP][0x005b0ac0-0x005b0b4d.SpellThreeArgsInputPaneConstructor](by-memory/0x005b0ac0-0x005b0b4d.SpellThreeArgsInputPaneConstructor.md) | Builds numeric-args base, installs vtables, loads spell prompt text, and stores spell index. |
| ordinary destructor | [UID:0004UD][0x005b0b50-0x005b0bd3.SpellThreeArgsInputPaneDestructor](by-memory/0x005b0b50-0x005b0bd3.SpellThreeArgsInputPaneDestructor.md) | Sole source destructor body; clears child-index-3 input mode through the EPF/non-EPF state type selected by `g_useEpfAssets`. |
| `OnConfirmInput` | [UID:0001LQ][0x005b0be0-0x005b0cfd.SpellThreeArgsInputPaneConfirmInput](by-memory/0x005b0be0-0x005b0cfd.SpellThreeArgsInputPaneConfirmInput.md) | Reads three numbers and sends an 8-byte spell packet. |
| retained raw direct-argument body | [UID:0003VU][0x005b0d00-0x005b0d9a.SpellThreeArgsDirectArgumentPacketRaw](by-memory/0x005b0d00-0x005b0d9a.SpellThreeArgsDirectArgumentPacketRaw.md) | Helper-shaped opcode `0x0f` sender from three explicit `short` arguments; current B010 route scan is negative, so this is not a proven class method or emitter. |
| adjustor thunks | [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md) | Secondary/tertiary vtable thunks to `0x005b7f60`; source reconstruction excludes them through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| scalar deleting destructor | [UID:0001NI][0x005b7f60-0x005b8024.SpellThreeArgsInputPaneScalarDeletingDestructor](by-memory/0x005b7f60-0x005b8024.SpellThreeArgsInputPaneScalarDeletingDestructor.md) | Compiler-generated deleting wrapper around the source semantics carried by UID0004UD; blank C++ and non-emitting. |

If a caller, pointer, vtable/table route, or runtime route to [UID:0003VU][0x005b0d00-0x005b0d9a.SpellThreeArgsDirectArgumentPacketRaw](by-memory/0x005b0d00-0x005b0d9a.SpellThreeArgsDirectArgumentPacketRaw.md) is later proven, the best current class-method candidate name is `SendDirectArgumentPacket(short arg0, short arg1, short arg2)`. Do not add that declaration now; current evidence supports only a retained no-route body.

## Evidence Notes

- IDA confirms the constructor, confirm handler, two thunks, and scalar deleting destructor.
- Constructor callers are spell inventory cast dispatch paths at `0x0057c9b0`, `0x0057e2d0`, and `0x0057f030`.
- 2026-07-07 B011 UID0001LQ implementation callback: current IDA MCP session `supervisor-nexustk-20260707` reconfirmed [UID:0001LQ][0x005b0be0-0x005b0cfd.SpellThreeArgsInputPaneConfirmInput](by-memory/0x005b0be0-0x005b0cfd.SpellThreeArgsInputPaneConfirmInput.md) as the active vtable-routed `OnConfirmInput` method through data xref `0x0062f514` and the sole target pointer-byte hit at `0x62f514`; the handler reads `m_spellIndex` from `this+0x108`, sends opcode `0x0f` with three 16-bit big-endian arguments and length `8`, and keeps [UID:0003VU][0x005b0d00-0x005b0d9a.SpellThreeArgsDirectArgumentPacketRaw](by-memory/0x005b0d00-0x005b0d9a.SpellThreeArgsDirectArgumentPacketRaw.md) as a related no-route/non-emitting body rather than a class declaration member.
- B010's 2026-07-05 MCP refresh for the related raw body [UID:0003VU][0x005b0d00-0x005b0d9a.SpellThreeArgsDirectArgumentPacketRaw](by-memory/0x005b0d00-0x005b0d9a.SpellThreeArgsDirectArgumentPacketRaw.md) used session `supervisor_recovery_20260705` and kept it out of this class declaration: `0x005b0d00`/`0x005b0d9a` are not functions, xrefs and target VA/RVA/file-offset pointer-byte hits are zero, and the live handler remains the positive-control routed class method at `0x0062f514`.
- Disabled generated output marks `0x005b78db` as missing code, but IDA confirms it as a real adjustor thunk.
- 2026-05-26 IDA recheck confirms the adjustor pair forwards to `0x005b7f60` after `this - 0xa0` and `this - 0xa4`; the pair is tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).

## UID0001NI Destructor, Layout, And Source Closure - 2026-07-20

- Validator-issued UID0004UD is the exact direct ordinary destructor at `[0x005b0b50,0x005b0bd3)`, size `0x83`, SHA256 `6C7D3C21F9202C324F6CCF9BA3D949DDDCF1DAAB29DFEECEA0D68FB1864EED12`. It has `void __thiscall(SpellThreeArgsInputPane *)` ABI and owns the only human destructor definition.
- UID0001NI at `[0x005b7f60,0x005b8024)` is the `0xc4` scalar deleting wrapper. Primary scalar cell `0x0062f4cc -> 0x005b7f60` routes the compiler wrapper; primary confirm slot `0x0062f514 -> 0x005b0be0` is distinct. Secondary/tertiary cells `0x0062f51c -> 0x005b78d0` and `0x0062f54c -> 0x005b78db` route the `-0xa0` / `-0xa4` adjustors to UID0001NI. Delete flags, `operator delete`, guarded size `0x10c`, return-`this`, vptr stores, base teardown, EH/cookie plumbing, and adjustors remain excluded from source C++.
- The direct body restores primary/secondary/tertiary vptrs, selects `ItemWhoInputPaneState` or `SpellInputPaneState` by `g_useEpfAssets`, gets GeneralPurposePanel child index `3`, clears that state's input-mode flag, and reaches compiler-emitted LineInputPane teardown. Source C++ retains only the state clear; neither direct nor scalar body calls the other.
- Constructor/direct/confirm source order is UID0001LP, UID0004UD, UID0001LQ. Three `0xcc` bytes precede the destructor and thirteen follow it. ThreeArgs is one of D3's four local direct/scalar pairs; the wider UID0000O0 file-level context has five confirmed pairs by also including SpellString. The complete class remains `0x10c` bytes with inherited `NumberArgsInputPane`, signed `char m_spellIndex` at `+0x108`, and natural tail alignment; no explicit reserved member is introduced.
- The formal declaration remains complete and unchanged: public constructor and virtual destructor, protected virtual `OnConfirmInput`, private signed one-byte `m_spellIndex`, class-closing brace before `[[CHILDREN]]`, and owner/emitter [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md).

## Score Rationale

| Field | Value | Rationale |
| --- | --- | --- |
| Completion | 91 | Constructor, direct source destructor, confirm handler, scalar wrapper, paired adjustors, complete vtable slice, RTTI, exact `0x10c` layout, declaration, source route, compiler exclusions, and raw-helper separation are all documented. Broader retained raw-helper liveness and original symbol spelling remain outside this class closure. |
| Confidence | 94 | Exact bytes/hashes, address order, vtable/RTTI routes, normalized direct/scalar behavior, sibling compiler pattern, and generated one-definition structure agree. The absent original symbols cap confidence below final-audit certainty. |

## Cross-References

- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0001LN][0x005b0780-0x005b14e6.SpellArgumentInputPanes](by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md)
- [UID:0004UD][0x005b0b50-0x005b0bd3.SpellThreeArgsInputPaneDestructor](by-memory/0x005b0b50-0x005b0bd3.SpellThreeArgsInputPaneDestructor.md)
- [UID:0000DL][SpellFourArgsInputPane](by-class/SpellFourArgsInputPane.md)
- [UID:0000DW][SpellTwoArgsInputPane](by-class/SpellTwoArgsInputPane.md)
- [UID:0000DR][SpellOneArgInputPane](by-class/SpellOneArgInputPane.md)
- [UID:0003VU][0x005b0d00-0x005b0d9a.SpellThreeArgsDirectArgumentPacketRaw](by-memory/0x005b0d00-0x005b0d9a.SpellThreeArgsDirectArgumentPacketRaw.md)
- [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md)

## Changes

- 2026-07-20 Agent-B001 UID0001NI accepted callback:
  - Raised `89/92 -> 91/94`, preserving UID, owner/emitter UID0000O0, reconstructable state, blank position, and the complete managed class declaration unchanged.
  - Added validator-issued UID0004UD as the sole ordinary destructor source carrier and separated UID0001NI scalar, UID0001N9 adjustors, and UID00026W vtable/RTTI as compiler support.
  - Recorded exact direct hash/range, source order, padding, `0x10c` natural layout, state-clear behavior, source/compiler exclusions, and current SpellInputPanes route while historicalizing the old recovered-file route.
- 2026-06-30 B002 SpellInputPanes implementation callback:
  - Added the accepted declaration-only `SpellThreeArgsInputPane : public NumberArgsInputPane` formal C++ block with `m_spellIndex` and `[[CHILDREN]]`.
  - Exact constructor, confirm handler, and destructor source bodies remain on the by-memory child pages.
- 2026-06-21 B010 Rule 26 source-quality incorporation:
  - Added [UID:0003VU][0x005b0d00-0x005b0d9a.SpellThreeArgsDirectArgumentPacketRaw](by-memory/0x005b0d00-0x005b0d9a.SpellThreeArgsDirectArgumentPacketRaw.md) as a retained no-route related body, not a proven method or emitter.
  - Documented `this + 0x108` as best current `m_spellIndex` and recorded the conditional future method name `SendDirectArgumentPacket(short arg0, short arg1, short arg2)` only for route-proven use.
- 2026-07-05 B010 revalidation callback:
  - Synchronized current MCP evidence for [UID:0003VU][0x005b0d00-0x005b0d9a.SpellThreeArgsDirectArgumentPacketRaw](by-memory/0x005b0d00-0x005b0d9a.SpellThreeArgsDirectArgumentPacketRaw.md) from session `supervisor_recovery_20260705`; the raw body remains a related no-route artifact, not a class declaration member, owner, or emitter.
- 2026-07-07 B011 UID0001LQ implementation callback:
  - Added the current-session `OnConfirmInput` breadcrumb for [UID:0001LQ][0x005b0be0-0x005b0cfd.SpellThreeArgsInputPaneConfirmInput](by-memory/0x005b0be0-0x005b0cfd.SpellThreeArgsInputPaneConfirmInput.md), including the vtable route, `m_spellIndex` at `+0x108`, length-`8` packet body, and unchanged [UID:0003VU][0x005b0d00-0x005b0d9a.SpellThreeArgsDirectArgumentPacketRaw](by-memory/0x005b0d00-0x005b0d9a.SpellThreeArgsDirectArgumentPacketRaw.md) no-route disposition. Class metadata and formal declaration were not changed.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `88`.
- Evidence: the page documents the numeric spell-input role, exact constructor/confirm/destructor/thunk memory docs, constructor callers, packet shape, and ignored adjustor-thunk handling; remaining completion gap is source-ready C++ detail.
- 2026-06-05: Marked reconstructable and attached to [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md).
- Evidence: live IDA MCP `lookup_funcs` confirms the constructor, confirm handler, scalar deleting destructor, and adjustor thunks at `0x005b0ac0`, `0x005b0be0`, `0x005b7f60`, `0x005b78d0`, and `0x005b78db`; both class (`86/88`) and parent file (`88/80`) meet the 80/80 gate.
