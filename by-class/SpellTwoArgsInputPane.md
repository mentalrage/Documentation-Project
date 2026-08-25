*** UID:0000DW | DO NOT MODIFY OR REMOVE!!! ***
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
class SpellTwoArgsInputPane : public NumberArgsInputPane
{
public:
    explicit SpellTwoArgsInputPane(char spellIndex);
    virtual ~SpellTwoArgsInputPane();

protected:
    virtual void OnConfirmInput();

private:
    char m_spellIndex;
};

#endif // NEXUSTK_UI_DIALOGS_SPELLINPUTPANES_H
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

## UID0001LM Signed Prompt-Class Synchronization - 2026-07-19

- The complete declaration now takes plain `char spellIndex` and stores plain `char m_spellIndex` at complete-object `+0x108`. Repeated constructor/consumer `movsx` proves signed semantics; the object remains exactly `0x10c` bytes with natural tail alignment at `+0x109..+0x10b`.
- The class closes before `[[CHILDREN]]`, so exact child definitions emit at namespace scope rather than inside the class. Inheritance and every existing method declaration/access level are unchanged.
- Metadata rises `86/88 -> 89/92` because signed type, exact natural layout, complete declaration, and generated structure are closed. Exact owner/emitter/source route, unrelated method bodies, retained or ownerless no-route raw helpers, destructor/scalar/adjustor evidence, compiler exclusions, and history remain intact.
- Constructors use the shared public inline `UserPane::GetSpellPromptText(char) const`; no private cross-TU table access, `UserSpellRecord`, `GetSpellRecord`, or raw vtable/RTTI/compiler source is introduced.

# SpellTwoArgsInputPane
## UID0000LU Header Placement Synchronization - 2026-08-15

The accepted complete SpellTwoArgsInputPane declaration was moved verbatim from CPP to H for direct construction through `SpellInputPanes.h`. Existing children and NumberArgsInputPane behavior remain unchanged.

## Status

- Confidence: strong for behavior and IDA boundaries.
- Likely source file: [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- Address range: [UID:0001LN][0x005b0780-0x005b14e6.SpellArgumentInputPanes](by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md)
- Current recovered file: `source-3/simroot_v2/class_SpellTwoArgsInputPane.cpp`
- Source-destructor carrier: [UID:0004UE][0x005b0e30-0x005b0eb3.SpellTwoArgsInputPaneDestructor](by-memory/0x005b0e30-0x005b0eb3.SpellTwoArgsInputPaneDestructor.md); UID0001NJ is compiler-only and non-emitting.
- Complete size/layout: `0x10c`; plain signed `char m_spellIndex` at `+0x108`, with natural tail alignment at `+0x109..+0x10b`.

## Class Purpose

`SpellTwoArgsInputPane` collects two numeric arguments for a spell and serializes them into an opcode `0x0f` spell-use packet. It derives from [UID:00009J][NumberArgsInputPane](by-class/NumberArgsInputPane.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| constructor | [UID:0001LR][0x005b0da0-0x005b0e2d.SpellTwoArgsInputPaneConstructor](by-memory/0x005b0da0-0x005b0e2d.SpellTwoArgsInputPaneConstructor.md) | Builds numeric-args base, installs vtables, loads spell prompt text, and stores spell index. |
| destructor | [UID:0004UE][0x005b0e30-0x005b0eb3.SpellTwoArgsInputPaneDestructor](by-memory/0x005b0e30-0x005b0eb3.SpellTwoArgsInputPaneDestructor.md) | Sole human source destructor; clears the mode-selected input state through child index 3. |
| `OnConfirmInput` | [UID:0001LS][0x005b0ec0-0x005b0f9e.SpellTwoArgsInputPaneConfirmInput](by-memory/0x005b0ec0-0x005b0f9e.SpellTwoArgsInputPaneConfirmInput.md) | Reads two numbers and sends a 6-byte spell packet. |
| retained direct packet helper | [UID:0003VV][0x005b0fa0-0x005b1029.SpellTwoArgsDirectArgumentPacketRaw](by-memory/0x005b0fa0-0x005b1029.SpellTwoArgsDirectArgumentPacketRaw.md) | Source-authored no-route helper that sends opcode `0x0f`, stored `m_spellIndex` / `this+0x108`, and two 16-bit spell arguments. No caller, pointer, vtable, VA/RVA/raw-offset literal, or rel32 route is proven, so formal C++ remains blocked. |
| adjustor thunks | [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md) | Secondary/tertiary vtable thunks to `0x005b8030`; source reconstruction excludes them through [UID:0000VN][-ignored](by-memory/-ignored.md). |
| scalar deleting destructor | [UID:0001NJ][0x005b8030-0x005b80f4.SpellTwoArgsInputPaneScalarDeletingDestructor](by-memory/0x005b8030-0x005b80f4.SpellTwoArgsInputPaneScalarDeletingDestructor.md) | Compiler-only `0xc4` deleting wrapper that expands UID0004UE cleanup, implicit base teardown, hidden flags, conditional storage release, guarded size, and object return; formal C++ is blank. |

## Field Notes

- `this + 0x108` is the stored spell index/slot byte written by the constructor, consumed by `OnConfirmInput`, and consumed by the retained direct packet helper. Best current source member name: `m_spellIndex`; `m_spellSlot` remains an acceptable alternate until broader spell-record naming settles the original spelling.
- [UID:0003VV][0x005b0fa0-0x005b1029.SpellTwoArgsDirectArgumentPacketRaw](by-memory/0x005b0fa0-0x005b1029.SpellTwoArgsDirectArgumentPacketRaw.md) should use generic argument names such as `firstArgument` and `secondArgument`; no spell-record evidence proves coordinate, amount, target, row, or column names for the two 16-bit values.

## Evidence Notes

- IDA confirms the constructor, confirm handler, two thunks, and scalar deleting destructor.
- Constructor callers are spell inventory cast dispatch paths at `0x0057c9b0`, `0x0057e2d0`, and `0x0057f030`.
- 2026-07-07 B004 current MCP recheck confirms [UID:0001LS][0x005b0ec0-0x005b0f9e.SpellTwoArgsInputPaneConfirmInput](by-memory/0x005b0ec0-0x005b0f9e.SpellTwoArgsInputPaneConfirmInput.md) as the active vtable-routed confirm handler: session `supervisor-nexustk-20260707`, `lookup_funcs 0x005b0ec0 -> sub_5B0EC0`, size `0xde`, vtable/data xref `0x0062f5a0`, and packet use of `m_spellIndex` / `this+0x108` in the six-byte opcode `0x0f` payload. The adjacent [UID:0003VV][0x005b0fa0-0x005b1029.SpellTwoArgsDirectArgumentPacketRaw](by-memory/0x005b0fa0-0x005b1029.SpellTwoArgsDirectArgumentPacketRaw.md) page already preserves the retained no-route helper policy and remains separate from `OnConfirmInput`.
- Disabled generated output marks `0x005b78f1` as missing code, but IDA confirms it as a real adjustor thunk.
- 2026-05-26 IDA recheck confirms the adjustor pair forwards to `0x005b8030` after `this - 0xa0` and `this - 0xa4`; the pair is tracked in [UID:0000VN][-ignored](by-memory/-ignored.md).

## Destructor Source And Compiler Graph

- UID0004UE is exact `[0x005b0e30,0x005b0eb3)`, size `0x83`, body SHA256 `D82AEBF7A41536EED910B994B0518E242B71A2A1633D61AB7CA18BEC6CB1589A`. It has ordinary `void __thiscall(this)` ABI, no hidden flags, no source-visible return, and zero recovered direct-start xrefs/pointer bytes.
- UID0001NJ is exact `[0x005b8030,0x005b80f4)`, size `0xc4`, body SHA256 `4ADF676AD350469654ED14C77F448C21AB24520AB90A8081B85F67C11EE09139`. It has the hidden flags argument, bit-1 release path, bit-4 guarded `0x10c` path, object return, compiler frame support, and blank source.
- Both variants normalize to the same class-specific state clear: read `g_useEpfAssets`, obtain GeneralPurposePanel child index `3`, and clear either `ItemWhoInputPaneState` or `SpellInputPaneState`. Raw vptr restores and implicit LineInputPane teardown are compiler-generated.
- Primary vtable cell `0x0062f558 -> 0x005b8030`; confirm cell `0x0062f5a0 -> 0x005b0ec0`; `-0xa0` and `-0xa4` adjustor thunks at `0x005b78e6` and `0x005b78f1` route to the scalar wrapper. The exact vtable slice is `[0x0062f558,0x0062f5e4)`, SHA256 `57B0765621695A416AB4FBF2DEEFEF2F6DB855871E0181F5F40CD6309CF17A7E`, with COL offsets `0/0xa0/0xa4` and RTTI `.?AVSpellTwoArgsInputPane@@`.
- Constructor, UID0004UE destructor, and UID0001LS `OnConfirmInput` are the human source order. The class closes before `[[CHILDREN]]`, so all three qualified definitions emit at namespace scope exactly once.
- FourArgs, supervisor-executed ThreeArgs, OneArg, and SpellSlot are independent local source/compiler controls; SpellString is the separate sixth file-level pair. No duplicate wrapper, adjustor, vtable, base teardown, EH/cookie, or raw-address source is permitted.

## Score Rationale

- Completion `91`: the class now closes the constructor/direct destructor/confirm source surface, exact field/layout, scalar/adjustor/vtable compiler boundary, owner/emitter route, retained-helper separation, and one-definition expectations without inventing compiler source.
- Confidence `94`: exact direct/scalar hashes, normalized sibling controls, RTTI/vtables/adjustors, accepted helpers, and current generated route converge. Missing original source symbols and the direct variant's zero recovered route keep the page below 95.

## Cross-References

- [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md)
- [UID:0001LN][0x005b0780-0x005b14e6.SpellArgumentInputPanes](by-memory/0x005b0780-0x005b14e6.SpellArgumentInputPanes.md)
- [UID:0000DL][SpellFourArgsInputPane](by-class/SpellFourArgsInputPane.md)
- [UID:0000DV][SpellThreeArgsInputPane](by-class/SpellThreeArgsInputPane.md)
- [UID:0000DR][SpellOneArgInputPane](by-class/SpellOneArgInputPane.md)
- [UID:0004UE][0x005b0e30-0x005b0eb3.SpellTwoArgsInputPaneDestructor](by-memory/0x005b0e30-0x005b0eb3.SpellTwoArgsInputPaneDestructor.md)
- [UID:0003VV][0x005b0fa0-0x005b1029.SpellTwoArgsDirectArgumentPacketRaw](by-memory/0x005b0fa0-0x005b1029.SpellTwoArgsDirectArgumentPacketRaw.md)
- [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md)

## Changes

- 2026-07-20 Agent-B004 UID0001NJ accepted callback:
  - Raised `89/92 -> 91/94`, preserving owner/emitter UID0000O0, reconstructable state, blank position, and the complete managed class block byte-for-byte with class closure before `[[CHILDREN]]`.
  - Added validator-issued UID0004UE as the sole source destructor and incorporated the complete direct/scalar/adjustor/vtable/RTTI/layout/source-order graph, exact hashes/routes, family controls, compiler exclusions, negative evidence, and one-definition expectations.
- 2026-06-30 B002 SpellInputPanes implementation callback:
  - Added the accepted declaration-only `SpellTwoArgsInputPane : public NumberArgsInputPane` formal C++ block with `m_spellIndex` and `[[CHILDREN]]`.
  - Exact constructor, confirm handler, and destructor source bodies remain on the by-memory child pages; [UID:0003VV][0x005b0fa0-0x005b1029.SpellTwoArgsDirectArgumentPacketRaw](by-memory/0x005b0fa0-0x005b1029.SpellTwoArgsDirectArgumentPacketRaw.md) remains retained no-route helper evidence.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `88`.
- Evidence: the page documents the numeric spell-input role, exact constructor/confirm/destructor/thunk memory docs, constructor callers, packet shape, and ignored adjustor-thunk handling; remaining completion gap is source-ready C++ detail.
- 2026-06-05: Marked reconstructable and attached to [UID:0000O0][SpellInputPanes](by-file/SpellInputPanes.md).
- Evidence: live IDA MCP `lookup_funcs` confirms the constructor, confirm handler, scalar deleting destructor, and adjustor thunks at `0x005b0da0`, `0x005b0ec0`, `0x005b8030`, `0x005b78e6`, and `0x005b78f1`; both class (`86/88`) and parent file (`88/80`) meet the 80/80 gate.
- 2026-06-21 B011 Rule 26 source-quality sync: Added [UID:0003VV][0x005b0fa0-0x005b1029.SpellTwoArgsDirectArgumentPacketRaw](by-memory/0x005b0fa0-0x005b1029.SpellTwoArgsDirectArgumentPacketRaw.md) as a retained direct packet helper and recorded the `this+0x108` field direction. The helper is class-owned source code with no proven caller/pointer route, so its formal C++ remains blocked even though behavior and ownership are now documented.
- 2026-07-07 B004 UID0001LS implementation callback: Added current evidence for the vtable-routed `OnConfirmInput` handler at `0x005b0ec0`, size `0xde`, with `m_spellIndex` at `+0x108`; class score and metadata unchanged.
