*** UID:000035 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000K7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class FunctionObject0;

class ConfirmInputPane : public CharInputPane
{
public:
    ConfirmInputPane(const wchar_t *promptText, FunctionObject0 *acceptAction);
    virtual ~ConfirmInputPane();

private:
    FunctionObject0 *m_acceptAction; // +0x108; owned zero-argument accept callback.
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ConfirmInputPane

## Status

- Confidence: very strong for class role, method boundaries, callback field role, owner/emitter routing, and declaration-level C++; strong for the final `m_acceptAction` spelling and `FunctionObject0` base type.
- Likely source file: [UID:0000K7][InputPanes](by-file/InputPanes.md)
- Main address range: [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md)
- Constructor range: [UID:0001N4][0x005b75d0-0x005b760e.ConfirmInputPaneConstructor](by-memory/0x005b75d0-0x005b760e.ConfirmInputPaneConstructor.md)
- Compiler adjustors: [UID:00018Z][0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks.md)
- Vtables: [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- Reconstructable class attached to [UID:0000K7][InputPanes](by-file/InputPanes.md). The active source gate is satisfied for declaration-level C++; exact method bodies remain on the by-memory children, and compiler vtables/thunks regenerate from the declaration.

## Class Purpose

`ConfirmInputPane` is a yes/no confirmation prompt built on [UID:00001P][CharInputPane](by-class/CharInputPane.md). When the text source contains one character and that character is `y` or `Y`, it invokes the owned zero-argument accept callback stored at `+0x108` as `m_acceptAction`. Destruction releases the same callback through its delete/release virtual slot. Drop/give item confirmation panes store [UID:000040][DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528](by-class/DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528.md) action objects created by [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md).

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x004f2a10-0x004f2a57` | `OnEnterKey` | Reads the single-character response and invokes the confirmation action on `y`/`Y`. |
| `0x004f2e85-0x004f2e9b` | secondary/tertiary destructor adjustors | Compiler thunks that subtract `0xa0` or `0xa4` and tail-jump to the scalar deleting destructor. |
| `0x004f2fb0-0x004f3017` | scalar deleting destructor | Compiler-generated deleting wrapper that releases `m_acceptAction`, tears down `LineInputPane`, and conditionally deletes storage. |
| `0x005b75d0-0x005b760e` | constructor | Builds `CharInputPane`, stores `FunctionObject0 *m_acceptAction` at `this + 0x108`, and installs vtables. |

## Class Layout And Source Shape

The current source-facing declaration is:

```cpp
class ConfirmInputPane : public CharInputPane
{
public:
    ConfirmInputPane(const wchar_t *promptText, FunctionObject0 *acceptAction);
    virtual ~ConfirmInputPane();

private:
    FunctionObject0 *m_acceptAction;
};
```

`m_acceptAction` is the field at object offset `+0x108`, immediately after the `CharInputPane` base storage. It is not a raw context pointer and not a `UserPane *`; the concrete drop/give use stores a `DoubleParamMemberFunctionObject0<UserPaneItemActionCallback, UserPane, signed char, bool>` wrapper whose call-time arguments are already bound. Use `FunctionObject*` only as a temporary generated-header fallback if `FunctionObject0` is unavailable.

## B001-042 Exact Split Evidence

The source-authored methods in the `0x004f1c00-0x004f3017` aggregate now have exact child pages: [UID:000365][0x004f29d0-0x004f2a05.ConfirmInputPaneCompleteDestructor](by-memory/0x004f29d0-0x004f2a05.ConfirmInputPaneCompleteDestructor.md), [UID:000366][0x004f2a10-0x004f2a58.ConfirmInputPaneInvokeAcceptedAction](by-memory/0x004f2a10-0x004f2a58.ConfirmInputPaneInvokeAcceptedAction.md), and [UID:00036G][0x004f2fb0-0x004f3017.ConfirmInputPaneScalarDeletingDestructor](by-memory/0x004f2fb0-0x004f3017.ConfirmInputPaneScalarDeletingDestructor.md). B001-042 live IDA disassembly found the previously undocumented `0x004f29d0-0x004f2a05` complete-destructor body between `0xcc` padding bands; although IDA does not model a function object or xrefs at that start, the body stores `ConfirmInputPane` vtables, handles `m_acceptAction` at `this+0x108`, and tail-jumps to [UID:00036D][0x004f2dd0-0x004f2e59.LineInputPaneCompleteDestructor](by-memory/0x004f2dd0-0x004f2e59.LineInputPaneCompleteDestructor.md). The class now clears the `85/85` direct-parent gate for its children.

## 2026-06-05 IDA MCP Evidence

- `lookup_funcs` confirms modeled starts at `0x004f2a10`, `0x004f2fb0`, and `0x005b75d0`; the late constructor is size `0x3e` and ends at `0x005b760e`.
- `decompile 0x004f2a10` reads the current text length from `this + 0xfc`, copies one wide character when length is one, and invokes `m_acceptAction` at `this + 0x108` only for `y` (`0x79`) or `Y` (`0x59`).
- `decompile 0x004f2fb0` restores the three `ConfirmInputPane` vtable views, calls the `m_acceptAction` object's first virtual slot with argument `1` when present, calls `LineInputPane` cleanup at `0x004f2dd0`, and conditionally frees storage through `0x004f4ac0`.
- `decompile 0x005b75d0` calls `CharInputPane` constructor `0x004f28a0`, stores `FunctionObject0 *m_acceptAction` at `this + 0x108`, and installs vtables `0x0061cbfc`, `0x0061cc4c`, and `0x0061cc7c`.
- `xrefs_to 0x004f2a10` reports the primary vtable slot at `0x0061cc44`; `xrefs_to 0x004f2fb0` reports the secondary/tertiary adjustor thunks and the primary vtable slot.
- B006 source-routing recheck confirms the two `ConfirmInputPane` adjustor thunks are half-open `0x004f2e85-0x004f2e90` and `0x004f2e90-0x004f2e9b`; generated `virt_meth_*` names for those addresses are ABI-slot artifacts, not source methods.
- `callers 0x005b75d0` reports four item-action prompt construction paths: [UID:000042][DropAllInputPane](by-class/DropAllInputPane.md), [UID:000044][DropInputPane](by-class/DropInputPane.md), [UID:00005S][GiveAllInputPane](by-class/GiveAllInputPane.md), and [UID:00005U][GiveInputPane](by-class/GiveInputPane.md).
- B003 Rule 26 reanalysis resolves the stored action object for those four paths as the `UserPaneItemActionCallbackObject` created by [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md); its virtual invoke slot reaches [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md) and then `UserPane::SendDropItemPacket` or `UserPane::SendGiveItemPacket`.

## Cross-References

- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:00018Z][0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks.md)
- [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- [UID:00001P][CharInputPane](by-class/CharInputPane.md)
- [UID:000077][LineInputPane](by-class/LineInputPane.md)
- [UID:000042][DropAllInputPane](by-class/DropAllInputPane.md)
- [UID:000044][DropInputPane](by-class/DropInputPane.md)
- [UID:00005S][GiveAllInputPane](by-class/GiveAllInputPane.md)
- [UID:00005U][GiveInputPane](by-class/GiveInputPane.md)
- [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md)
- [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md)

## Changes

- 2026-06-20 B003 Rule 26 support sync:
  - Score unchanged at `86/90`.
  - Added the concrete drop/give FunctionObjects action-object route stored at `this+0x108`.
- 2026-06-21 B009 Rule 26 source-quality incorporation:
  - Changed from `86/90` to `88/91`.
  - Added declaration-level first-draft C++ with `FunctionObject0 *m_acceptAction` and `[[CHILDREN]]`, replaced raw action/context wording with the owned accept-callback field, and recorded that method bodies stay on exact by-memory children while vtables/thunks regenerate.
- 2026-06-11 Agent-B001 B001-042: raised from `82/88` to `86/90` after splitting exact `ConfirmInputPane` child pages, documenting the IDA-unmodeled complete destructor at `0x004f29d0-0x004f2a05`, and rechecking action invocation/destructor ownership.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `74/86`.
  - Summary/evidence: class role, constructor, enter-key behavior, destructor/adjustor thunks, vtable family, and base-class relationships are documented from IDA-backed ranges; remaining work is detailed member naming and final C++ body reconstruction.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the class coverage row unclassified.
  - After at that point: `RECONSTRUCTABLE:TRUE`; parent attachment was deferred because the class completion score was below the 80% attachment gate.
  - Evidence: live IDA MCP confirms modeled starts at `0x004f2a10`, `0x004f2fb0`, and `0x005b75d0`, with the late constructor called from several prompt construction paths; existing project docs place the class in [UID:0000K7][InputPanes](by-file/InputPanes.md).
- 2026-06-05: Raised from `74/86` to `82/88` and attached to [UID:0000K7][InputPanes](by-file/InputPanes.md).
  - Before: the page still had stale output provenance, a one-byte-short destructor row, no parent attachment, and only summary evidence for the late constructor callers.
  - After: removed stale provenance, corrected the destructor and constructor half-open ranges, attached the class to the input-pane source file, and documented current IDA evidence for key handler, destructor, constructor, vtables, and callers.
  - Evidence: current IDA MCP `lookup_funcs`, `decompile`, `disasm`, `callers`, and `xrefs_to` confirm the method family and ownership.
