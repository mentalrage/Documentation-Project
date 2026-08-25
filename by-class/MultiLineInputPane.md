*** UID:00008T | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000K7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct InputKeyEvent;

class MultiLineInputPane : public LineInputPane
{
public:
    MultiLineInputPane(const wchar_t *promptText);
    virtual bool HandleKeyInput(InputKeyEvent *event);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MultiLineInputPane

## B003 2026-07-20 Inherited Event Signature Synchronization

- The shared source signature is `bool HandleKeyOrTextEvent(Event *event)` through LineInputPane. MultiLineInputPane's independent Enter-submit/clear and Escape-or-Control+C close algorithm remains exactly as documented; it is not UID000364 behavior and receives no body or ownership rewrite.
- Historical `InputEvent`/`OnKeyInput`/raw key-handler vocabulary is superseded only at the shared signature boundary. Scores, route, formal, constructor, multiline behavior, children, vtables, and unrelated history remain unchanged.

## Status

- Confidence: strong for class role and IDA boundaries.
- Likely source file: [UID:0000K7][InputPanes](by-file/InputPanes.md)
- Main address range: [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md)
- Vtables: [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- Compiler adjustors: secondary/tertiary destructor slots reuse the LineInputPane-family entries in [UID:00018Z][0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks.md); they are ABI glue, not custom `MultiLineInputPane` destructor bodies.
- Current recovered file: `source-3/simroot_v2/class_MultiLineInputPane.cpp`
- Autogen status: reconstructable class attached to [UID:0000K7][InputPanes](by-file/InputPanes.md); formal declaration shell now emits through the active code gate. The older `95/95` blank-C++ blocker is historical only; constructor and Enter/Escape/Ctrl+C handler bodies remain on exact by-memory child pages.

## Class Purpose

`MultiLineInputPane` is a [UID:000077][LineInputPane](by-class/LineInputPane.md) variant for multi-line dialog input. Enter submits through the owner dialog and clears/rebounds the text buffer; Escape or Ctrl+C closes the dialog and clears player dialog state.

## Class Evidence

| Evidence | Meaning |
| --- | --- |
| Constructor range `0x004f2c90-0x004f2cc4` | Builds the `LineInputPane` base and installs the `MultiLineInputPane` three-vtable family. |
| Key handler range `0x004f2cd0-0x004f2dca` | Multi-line submit/close handler; handles Enter, Escape, and Ctrl+C before forwarding remaining input to the text input child. |
| Vtable bases `0x0061cda0`, `0x0061cdf0`, `0x0061ce20` | IDA-confirmed primary, secondary, and tertiary tables in [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md). |
| Vtable slot secondary `+0x08 -> 0x004f2cd0` | Confirms the multi-line key handler is the derived key-input override. |
| Vtable boundary `0x0061ce28 -> List RTTI locator` | Confirms the end of the input-pane vtable family after the `MultiLineInputPane` tertiary table. |
| Secondary/tertiary destructor slots `0x004f2e59` and `0x004f2e64` | Reuse the LineInputPane-family scalar deleting destructor adjustors from [UID:00018Z][0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks.md); no independent source destructor body is present in that range. |
| Aggregate range [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md) | Places constructor/key handler with the reusable input-pane base family. |

## Consumer Evidence

| Consumer | Evidence |
| --- | --- |
| [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md) | Multi-line text dialog workflows consume this reusable input pane while text-dialog-specific owner behavior remains in the dialog module. |

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x004f2c90-0x004f2cc4` | constructor | Builds `LineInputPane` and installs multi-line vtables. |
| `0x004f2cd0-0x004f2dca` | `OnKeyEvent` | Handles submit/close shortcuts and forwards remaining input to the text input child. |

## B001-042 Exact Split Evidence

The constructor and key handler now have exact child pages: [UID:00036B][0x004f2c90-0x004f2cc5.MultiLineInputPaneConstructor](by-memory/0x004f2c90-0x004f2cc5.MultiLineInputPaneConstructor.md) and [UID:00036C][0x004f2cd0-0x004f2dcb.MultiLineInputPaneKeyHandler](by-memory/0x004f2cd0-0x004f2dcb.MultiLineInputPaneKeyHandler.md). Live IDA checks confirm the constructor installs the `MultiLineInputPane` vtable family after `LineInputPane` construction, while the key handler handles Enter submit, Escape/Ctrl+C close, active line-input clearing, and edit-child fallback. The class now clears the `85/85` direct-parent gate for both children.

## Cross-References

- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- [UID:00018Z][0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks.md)
- [UID:000077][LineInputPane](by-class/LineInputPane.md)
- [UID:0000OP][TextMenuDialogs](by-file/TextMenuDialogs.md)

## Changes

- 2026-07-01 Agent-B011 [UID:0000K7][InputPanes](by-file/InputPanes.md) empty-emitter implementation: raised from `86/88` to `88/90` and inserted the accepted formal `MultiLineInputPane : public LineInputPane` declaration shell with `HandleKeyInput` and `[[CHILDREN]]`. Preserved Enter/Escape/Ctrl+C behavior evidence and historicalized the old `95/95` no-code text.
- 2026-06-11 Agent-B001 B001-042: raised from `82/86` to `86/88` after creating exact child pages [UID:00036B][0x004f2c90-0x004f2cc5.MultiLineInputPaneConstructor](by-memory/0x004f2c90-0x004f2cc5.MultiLineInputPaneConstructor.md) and [UID:00036C][0x004f2cd0-0x004f2dcb.MultiLineInputPaneKeyHandler](by-memory/0x004f2cd0-0x004f2dcb.MultiLineInputPaneKeyHandler.md) and rechecking constructor/key-handler ownership against live IDA vtable stores, submit/close behavior, and text-menu consumer placement.
- 2026-06-06: Raised completion/confidence and attached to [UID:0000K7][InputPanes](by-file/InputPanes.md).
  - Before: completion/confidence were `74/84`, and `AUTOGEN_PARENT_UID` was blank because the page had not cleared the child-side parent gate.
  - After: completion/confidence are `82/86`, and `AUTOGEN_PARENT_UID` is `0000K7`.
  - Evidence: added constructor/key-handler range evidence, exact vtable bases and secondary override slot from [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md), the `0x0061ce28` vtable-family boundary, aggregate ownership, and `TextMenuDialogs` consumer placement. Historical note: C++ was left blank under the then-used `95/95` final-source gate; this is superseded by the 2026-07-01 formal declaration shell.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed the multi-line constructor and key handler starts at `0x004f2c90` and `0x004f2cd0`. Parent attachment was deferred at that score and superseded by the 2026-06-06 attachment above after the page met the 80/80 gate.
- Completion/confidence score update: existed before as `0/0`; changed to `74/84`. Summary: the multi-line input variant has clear owner, purpose, constructor/key handler boundaries, vtable family, and base-class relationships documented, but it remains concise and lacks full source-level field/control detail. Evidence: linked `InputPaneBases` memory range, `LineInputPane` relationship, method address map, and text-menu dialog usage.
