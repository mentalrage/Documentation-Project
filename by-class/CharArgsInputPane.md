*** UID:00001O | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000077 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;

class CharArgsInputPane : public LineInputPane
{
public:
    CharArgsInputPane(const wchar_t *promptText);
    virtual bool HandleKeyOrTextEvent(Event *event);
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CharArgsInputPane

## Status

- UID0000OJ dependency closure: the class declaration is formal H and emits after complete LineInputPane through UID000077. This page's CPP channel is intentionally blank because no CPP children attach here; removing its empty child marker prevents a raw generated placeholder while preserving every exact method child on its own source-bearing page.
- Confidence: strong for class role and IDA boundaries.
- Likely source file: [UID:0000K7][InputPanes](by-file/InputPanes.md)
- Main address range: [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md)
- Vtables: [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- Compiler adjustors: secondary/tertiary destructor slots reuse the LineInputPane-family entries in [UID:00018Z][0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks.md); they are ABI glue, not custom `CharArgsInputPane` destructor bodies.
- Current recovered file: `source-3/simroot_v2/class_CharArgsInputPane.cpp`
- Autogen status: reconstructable class attached to [UID:0000K7][InputPanes](by-file/InputPanes.md); formal declaration shell now emits through the active code gate. The older `95/95` blank-C++ blocker is historical only; constructor and alpha/comma/space filter bodies remain on exact by-memory child pages.

## Class Purpose

`CharArgsInputPane` is a character-argument prompt derived from [UID:000077][LineInputPane](by-class/LineInputPane.md). It accepts alphabetic characters, comma, and space as translated input while passing standard control keys through to the base handler.

## Class Evidence

| Evidence | Meaning |
| --- | --- |
| Constructor range `0x004f2a60-0x004f2ad2` | Builds the `LineInputPane` base, installs the `CharArgsInputPane` three-vtable family, and disables active edit input. |
| Key filter range `0x004f2ae0-0x004f2b73` | Alphabetic-argument input handler; accepts letters, comma, space, and control keys before forwarding to the base handler. |
| Vtable bases `0x0061cc88`, `0x0061ccd8`, `0x0061cd08` | IDA-confirmed primary, secondary, and tertiary tables in [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md). |
| Vtable slot secondary `+0x08 -> 0x004f2ae0` | Confirms the alphabetic/comma/space filter is the derived key-input override. |
| Secondary/tertiary destructor slots `0x004f2e59` and `0x004f2e64` | Reuse the LineInputPane-family scalar deleting destructor adjustors from [UID:00018Z][0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks.md); no independent source destructor body is present in that range. |
| Aggregate range [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md) | Places constructor/filter with the reusable input-pane base family rather than feature-specific command or spell prompt modules. |

## Consumer Evidence

| Consumer | Evidence |
| --- | --- |
| [UID:0001M5][0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor](by-memory/0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor.md) | Raw constructor calls the `CharArgsInputPane` base constructor before installing `ChangeItemSlotInputPane` vtables. |
| [UID:0001M7][0x005b3220-0x005b3260.ChangeSpellSlotInputPaneRawConstructor](by-memory/0x005b3220-0x005b3260.ChangeSpellSlotInputPaneRawConstructor.md) | Raw constructor calls the `CharArgsInputPane` base constructor before installing `ChangeSpellSlotInputPane` vtables. |
| [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md) | Command/slot prompt modules consume this reusable character-argument base while feature-specific packet/state behavior remains outside `InputPanes.cpp`. |

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x004f2a60-0x004f2ad2` | constructor | Builds `LineInputPane`, installs character-argument vtables, and disables active edit input. |
| `0x004f2ae0-0x004f2b73` | `HandleKeyOrTextEvent` | Filters alphabetic/comma/space input using the canonical `Event *` contract and forwards accepted/control events to `LineInputPane::HandleKeyOrTextEvent`. |

## B001-042 Exact Split Evidence

The constructor and filter now have exact child pages: [UID:000367][0x004f2a60-0x004f2ad3.CharArgsInputPaneConstructor](by-memory/0x004f2a60-0x004f2ad3.CharArgsInputPaneConstructor.md) and [UID:000368][0x004f2ae0-0x004f2b74.CharArgsInputPaneKeyFilter](by-memory/0x004f2ae0-0x004f2b74.CharArgsInputPaneKeyFilter.md). Live IDA checks confirm the constructor calls the `LineInputPane` base constructor, installs `CharArgsInputPane` vtables, disables active edit input, and the key filter accepts alphabetic/comma/space/control keys before delegating to [UID:00035Y][0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput](by-memory/0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput.md). The class now clears the `85/85` direct-parent gate for both children.

## B003 2026-07-20 Event Contract Completion

- The complete declaration now uses `class Event;` and `virtual bool HandleKeyOrTextEvent(Event *event)`. Constructor behavior, accepted alphabetic/comma/space filter semantics, LineInputPane fallback, exact children, adjustor/compiler split, and InputPanes ownership remain unchanged.
- Completion/confidence rise from `88/90` to `90/92` because the shared source signature and declaration debt are closed; final private accepted-character naming remains the bounded confidence cap.

## Cross-References

- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- [UID:00018Z][0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks.md)
- [UID:000077][LineInputPane](by-class/LineInputPane.md)
- [UID:00009J][NumberArgsInputPane](by-class/NumberArgsInputPane.md)
- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0001M5][0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor](by-memory/0x005b2fd0-0x005b3010.ChangeItemSlotInputPaneRawConstructor.md)
- [UID:0001M7][0x005b3220-0x005b3260.ChangeSpellSlotInputPaneRawConstructor](by-memory/0x005b3220-0x005b3260.ChangeSpellSlotInputPaneRawConstructor.md)

## Changes

- 2026-08-22 Agent-B009 UID0000OJ Gate 2A repair: removed the empty CPP `[[CHILDREN]]` marker from this page. The H declaration route remains unchanged, and constructor/filter definitions remain on their exact child pages rather than attaching through an empty class CPP channel.
- Historical 2026-07-01 Agent-B011 [UID:0000K7][InputPanes](by-file/InputPanes.md) empty-emitter implementation: raised from `86/88` to `88/90` and inserted the then-accepted formal `CharArgsInputPane : public LineInputPane` declaration shell with `OnKeyInput` and an empty CPP child marker. The 2026-08-22 repair supersedes that marker while preserving the declaration and alpha/comma/space filter evidence.
- 2026-06-11 Agent-B001 B001-042: raised from `82/86` to `86/88` after creating exact child pages [UID:000367][0x004f2a60-0x004f2ad3.CharArgsInputPaneConstructor](by-memory/0x004f2a60-0x004f2ad3.CharArgsInputPaneConstructor.md) and [UID:000368][0x004f2ae0-0x004f2b74.CharArgsInputPaneKeyFilter](by-memory/0x004f2ae0-0x004f2b74.CharArgsInputPaneKeyFilter.md) and rechecking constructor/filter ownership against live IDA vtable stores, key-filter behavior, and reusable `InputPanes` placement.
- 2026-06-06: Raised completion and attached to [UID:0000K7][InputPanes](by-file/InputPanes.md).
  - Before: completion was `70` and `AUTOGEN_PARENT_UID` was blank because the page had not cleared the child-side parent gate.
  - After: completion is `82`, confidence remains `86`, and `AUTOGEN_PARENT_UID` is `0000K7`.
  - Evidence: added constructor/filter range evidence, exact vtable bases and secondary key-filter slot from [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md), aggregate ownership through [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md), and derived slot-prompt consumer links. Historical note: C++ was left blank under the then-used `95/95` final-source gate; this is superseded by the 2026-07-01 formal declaration shell.

- What existed before: the page documented class role, constructor, key filter, and references, but metadata remained `0/0`.
- What it was changed to: scores were set to `70/86`.
- Summary and evidence: the class is simple and IDA boundaries are strong; completion is capped because detailed field layout, accepted-key edge cases, and final header form are not fully expanded here.
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE`. Current IDA MCP `lookup_funcs` reconfirmed the constructor and key-filter starts at `0x004f2a60` and `0x004f2ae0`, and `callers` shows use from command/input prompt creation paths. Parent attachment was deferred at that score and superseded by the 2026-06-06 attachment above after the page met the 80/80 gate.
