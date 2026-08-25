*** UID:00001P | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000077 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;

class CharInputPane : public LineInputPane
{
public:
    CharInputPane(const wchar_t *promptText);
    virtual ~CharInputPane();

    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void OnAccept() {}
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CharInputPane

## Status

- UID0000OJ dependency closure: this derived declaration/body route emits only through UID000077, after the complete LineInputPane root and its required includes. The former independent preamble is intentionally centralized at the owning root.
- Confidence: strong for class role and IDA boundaries.
- Likely source file: [UID:0000K7][InputPanes](by-file/InputPanes.md)
- Main address range: [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md)
- Compiler adjustors: [UID:00018Z][0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks.md)
- Vtables: [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- Current recovered file: `source-3/simroot_v2/class_CharInputPane.cpp`
- Autogen status: reconstructable class attached to [UID:0000K7][InputPanes](by-file/InputPanes.md); the complete declaration now emits from formal H into generated `InputPanes.h`, while formal CPP includes that header and emits exact child definitions. The older `95/95` blank-C++ blocker is historical only; printable-character acceptor and destructor bodies remain on exact by-memory child pages.

## Class Purpose

`CharInputPane` is a single-character prompt built on [UID:000077][LineInputPane](by-class/LineInputPane.md). It is constructed with a caller-provided prompt string, disables free text editing, accepts printable characters, converts them into translated character events, dismisses the prompt, clears pending player input state, forwards the accepted key to the base handler, and notifies the owner pane.

## Class Evidence

| Evidence | Meaning |
| --- | --- |
| Constructor range `0x004f28a0-0x004f2912` | Builds the `LineInputPane` base from a `const wchar_t *` prompt argument, installs the `CharInputPane` three-vtable family, and disables active edit input. |
| Character handler range `0x004f2920-0x004f29c9` | Printable-character acceptor and owner-notification path; Escape/control handling falls through the base input path. |
| Destructor adjustors `0x004f2e6f-0x004f2e85` | Compiler-generated secondary/tertiary thunks in [UID:00018Z][0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks.md). |
| Scalar deleting destructor `0x004f2f70-0x004f2fab` | Real `CharInputPane` deleting destructor body in the reusable input-pane cluster. |
| Vtable bases `0x0061cb70`, `0x0061cbc0`, `0x0061cbf0` | IDA-confirmed primary, secondary, and tertiary tables in [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md). |
| Vtable slot secondary `+0x08 -> 0x004f2920` | Confirms the printable-character acceptor is the derived key-input override. |

## Consumer Evidence

| Consumer | Evidence |
| --- | --- |
| [UID:000035][ConfirmInputPane](by-class/ConfirmInputPane.md) | Inherits the `CharInputPane` key acceptor through its secondary vtable while adding yes/no confirmation behavior. |
| [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) | Command prompt modules consume this reusable single-character base for feature-specific prompt classes. |
| [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) | Item action prompts consume the reusable base while packet/state behavior remains in item-action modules. |
| [UID:0000CW][SelfSaveInputPane](by-class/SelfSaveInputPane.md) | B005 confirms the constructor at `0x005b67c0` passes `g_pLanguageMan->GetLocalizedString(0x26)` / current text `Save profile? (Y/N) ` into `CharInputPane::CharInputPane(const wchar_t *)`. |

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x004f28a0-0x004f2912` | constructor | Builds `LineInputPane` from prompt text, installs `CharInputPane` vtables, and disables active edit input. |
| `0x004f2920-0x004f29c9` | `OnCharInput` | Accepts printable characters, handles Escape through base key input, rejects some extended keys, and notifies owner on accepted input. |
| `0x004f2e6f-0x004f2e85` | secondary/tertiary destructor adjustors | Compiler thunks that subtract `0xa0` or `0xa4` and tail-jump to the scalar deleting destructor. |
| `0x004f2f70-0x004f2fab` | scalar deleting destructor | Tears down `LineInputPane` and conditionally deletes storage. |

## B001-042 Exact Split Evidence

The source-authored `CharInputPane` methods now have exact child pages: [UID:000363][0x004f28a0-0x004f2913.CharInputPaneConstructor](by-memory/0x004f28a0-0x004f2913.CharInputPaneConstructor.md), [UID:000364][0x004f2920-0x004f29ca.CharInputPaneHandleKeyOrTextEvent](by-memory/0x004f2920-0x004f29ca.CharInputPaneHandleKeyOrTextEvent.md), and [UID:00036F][0x004f2f70-0x004f2fab.CharInputPaneScalarDeletingDestructor](by-memory/0x004f2f70-0x004f2fab.CharInputPaneScalarDeletingDestructor.md). Live IDA checks confirm class vtable stores, disabled edit input, printable-character accept/owner notification behavior, and the destructor chain to `LineInputPane`. The adjustor thunk span [UID:00018Z][0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks.md) remains non-reconstructable compiler output. The class now clears the `85/85` direct-parent gate for its source-bearing children.

B005's 2026-06-21 SelfSave constructor pass provides concrete caller evidence for the constructor signature: [UID:0003O5][0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw](by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md) pushes the return from [UID:00018U][0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers](by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md) and then calls this constructor with `ECX=this`. This supports `CharInputPane::CharInputPane(const wchar_t *promptText)` as the source-facing signature for prompt-derived classes.

## Source Placement And Header Dependency

- The complete `CharInputPane` declaration belongs in generated `NexusTK/ui/dialogs/InputPanes.h`, not in `InputPanes.cpp`. Formal H preserves the `LineInputPane` inheritance, constructor, virtual destructor, canonical `HandleKeyOrTextEvent(Event *)`, and source-defined empty `OnAccept()` override exactly.
- Formal CPP includes `InputPanes.h` and emits `[[CHILDREN]]` at namespace scope. Exact constructor/handler/destructor children remain the sole method-body emitters; no declaration or body is duplicated.
- This header placement is required by feature-derived declarations such as [UID:0000DS][SpellSlotInputPane](by-class/SpellSlotInputPane.md), whose generated `SpellInputPanes.h` needs a complete `CharInputPane` base.
- Moving the declaration changes no behavior, class layout, vtable route, inheritance, method ownership, score, or compiler-artifact disposition. Adjustor thunks, scalar-deletion lowering, raw vtables/RTTI, cookies, and adjusted-this arithmetic remain compiler output.

## Cross-References

- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:00018Z][0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks.md)
- [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- [UID:000077][LineInputPane](by-class/LineInputPane.md)
- [UID:000035][ConfirmInputPane](by-class/ConfirmInputPane.md)
- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0000CW][SelfSaveInputPane](by-class/SelfSaveInputPane.md)
- [UID:0003O5][0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw](by-memory/0x005b67c0-0x005b6800.SelfSaveInputPaneConstructorRaw.md)

## Changes

### 2026-08-01 UID0003VX Header-Channel Support Callback

- Preserved `92/94`, owner/emitter UID0000K7, reconstructable true, blank position, complete behavior/layout/vtable evidence, and all exact child ownership.
- Moved the exact complete declaration from formal CPP to formal H without semantic changes; formal CPP now includes `InputPanes.h` and emits `[[CHILDREN]]`.
- Recorded that generated `InputPanes.h` supplies the complete base required by feature-derived headers such as `SpellInputPanes.h`; no method body, compiler artifact, or unrelated source placement changed.

### 2026-07-20 UID0001MP/UID000364 callback

- Installed complete R3 with forward-declared `Event`, canonical `virtual bool HandleKeyOrTextEvent(Event *event)`, source-defined empty `virtual void OnAccept() {}`, complete class close, and namespace-scope `[[CHILDREN]]`.
- Renamed UID000364 to exact child `CharInputPaneHandleKeyOrTextEvent`, `[0x004f2920,0x004f29ca)`, `0xaa`/170 bytes, 64 instructions, body SHA256 `B8057AFAF334C2B182F3FC6A628477300DEF339F661D158A4B4097C188FFAD6C`, with thirteen-byte predecessor and six-byte successor `0xcc` padding.
- The child has fourteen code callers and six data routes. It translates before type filtering; returns true for non-key-down; returns the inherited LineInputPane result for Escape; accepts inclusive printable ASCII; rewrites one UTF-16 text unit; queues the complete pane, clears UserPane pending-target state, invokes inherited handling and OnAccept in order; returns false only for four arrows; and handles all other key-down values.
- The EventHandler `+0xa0` adjusted receiver and complete-object primary `+0x48` callback are compiler ABI routes represented as normal virtual methods. No adjusted-this arithmetic, explicit vtable call, raw offset, direct deletion, RTTI/table data, or cookie lowering belongs in source.
- Scores become `92/94`; owner/emitter UID0000K7, reconstructable true, blank optional position, inheritance, constructor/destructor/layout evidence, and unrelated children remain unchanged. Historical `InputKeyEvent`, `OnKeyInput`, blank source body, and unresolved callback wording is explicitly superseded.

- 2026-07-01 Agent-B011 [UID:0000K7][InputPanes](by-file/InputPanes.md) empty-emitter implementation: raised from `86/88` to `88/90` and inserted the accepted formal `CharInputPane : public LineInputPane` declaration shell with destructor, `OnKeyInput`, and `[[CHILDREN]]`. Preserved printable-character accept/destructor evidence and historicalized the old `95/95` no-code text.
- 2026-06-11 Agent-B001 B001-042: raised from `82/86` to `86/88` after creating exact constructor/key/destructor child pages and confirming ownership with live IDA vtable, key-accept, and destructor evidence.
- 2026-06-06: Raised completion and attached to [UID:0000K7][InputPanes](by-file/InputPanes.md).
  - Before: completion was `72` and `AUTOGEN_PARENT_UID` was blank because the page had not cleared the child-side parent gate.
  - After: completion is `82`, confidence remains `86`, and `AUTOGEN_PARENT_UID` is `0000K7`.
  - Evidence: added constructor/handler/destructor evidence, vtable bases and override-slot proof from [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md), adjustor-thunk ownership, and consumer links to confirmation/command/item prompt modules. Historical note: C++ was left blank under the then-used `95/95` final-source gate; this is superseded by the 2026-07-01 formal declaration shell.

- What existed before: the page documented constructor, char input, destructor adjustors, scalar destructor, and references, but metadata remained `0/0`.
- What it was changed to: scores were set to `72/86`.
- Summary and evidence: IDA boundaries and class role are strong; completion is limited by missing detailed field/layout notes and exact owner notification naming.
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE`. Current IDA MCP `lookup_funcs` reconfirmed the constructor, char-input handler, and scalar deleting destructor starts at `0x004f28a0`, `0x004f2920`, and `0x004f2f70`, and `callers` shows broad prompt construction use from command, item, and dialog paths. Parent attachment was deferred at that score and superseded by the 2026-06-06 attachment above after the page met the 80/80 gate.
- 2026-06-21 Rule 26 B005 incorporation: no score change; added SelfSave as a concrete `CharInputPane::CharInputPane(const wchar_t *)` consumer using `LanguageMan::GetLocalizedString(0x26)` / `Save profile? (Y/N) `.
