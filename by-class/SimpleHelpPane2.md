*** UID:0000D7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SimpleHelpPane2

## Status

- Likely source file: [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- Address range: [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md), adjacent factory [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md), raw factory helpers [UID:00022O][0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers](by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md), with destructor thunks in [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- Confidence: strong for inheritance, vtable identity, singleton ownership, factory construction, event behavior, and HelpPanes placement; medium for final private field names and source-level factory visibility because IDA still reports no direct xrefs to the constructor entry.

## Class Purpose

`SimpleHelpPane2` is a `HelpPane` subclass that adds an anchor rectangle and an auto-hide timer. It stores the active singleton, converts a parent-relative anchor rectangle into local coordinates, and hides itself on relevant input/timer events.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SimpleHelpPane2` | `0x004c74b0-0x004c75d5` | Calls `HelpPane::HelpPane`, writes [UID:0000SA][g_pSimpleHelpPane2](by-global/g_pSimpleHelpPane2.md), stores anchor rectangle, and schedules auto-hide. |
| `~SimpleHelpPane2` | `0x004c75e0-0x004c7609` | Ordinary teardown path: restores the three `SimpleHelpPane2` vtables, clears [UID:0000SA][g_pSimpleHelpPane2](by-global/g_pSimpleHelpPane2.md), then jumps to `HelpPane` teardown. |
| `OnAccept` | `0x004c7610-0x004c7620` | Dismisses through the pane close/delete path and returns handled. |
| `HandleEvent` | `0x004c7620-0x004c7668` | Cancels timer on button events and can cancel when the cursor leaves the anchor rectangle. |
| `OnCancel` | `0x004c7670-0x004c7680` | Dismisses through the pane close/delete path and returns not handled. |
| `CreateSimpleHelpPane2` / `ShowSimpleHelpPane2` | [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md) | File-local factory that replaces the active singleton, constructs the popup, stores anchor bounds, and schedules the timer. |
| factory wrappers / anchor predicate | [UID:00022O][0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers](by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md) | Raw unmodeled helpers: two wrappers around the factory and one stored-anchor/current-cursor predicate. |
| `ScalarDeletingDestructor` | `0x004ce500-0x004ce55f` | Restores vtables, clears singleton, tears down `HelpPane`, and optionally deletes storage. |

## Evidence Notes

- 2026-06-04 live IDA MCP confirms modeled function boundaries for `SimpleHelpPane2`: constructor `0x004c74b0-0x004c75d5`, ordinary teardown `0x004c75e0-0x004c7609`, `OnAccept` `0x004c7610-0x004c7620`, `HandleEvent` `0x004c7620-0x004c7668`, `OnCancel` `0x004c7670-0x004c7680`, factory `0x004c7680-0x004c77e0`, adjustor thunks `0x004ce377-0x004ce382` and `0x004ce382-0x004ce38d`, and scalar deleting destructor `0x004ce500-0x004ce55f`.
- The constructor calls [UID:000063][HelpPane](by-class/HelpPane.md) at `0x004c74ff`, writes [UID:0000SA][g_pSimpleHelpPane2](by-global/g_pSimpleHelpPane2.md) at `0x004c751b` with a null fallback at `0x004c7522`, installs vtables at `0x004c7537`, `0x004c753d`, and `0x004c7547`, copies or clears the anchor rectangle at `this+0x224`, offsets it through `0x004b7e10`, and schedules the auto-hide timer through `0x005975e0`.
- Live IDA names the three vtable views as `??_7SimpleHelpPane2@@6B@` at `0x0061ac6c`, `??_7SimpleHelpPane2@@6B@_0` at `0x0061acb8`, and `??_7SimpleHelpPane2@@6B@_1` at `0x0061ace8`. Key slots are `0x0061ac6c -> 0x004ce500`, `0x0061acbc -> 0x004c7620`, `0x0061acc0 -> 0x004c7670`, and `0x0061acec -> 0x004c7610`.
- Vtable writes/refs line up across lifecycle paths: constructor writes the three views at `0x004c7537/0x004c753d/0x004c7547`; ordinary teardown rewrites them at `0x004c75e0/0x004c75e6/0x004c75f0`; factory construction writes the primary view at `0x004c7746`; and the scalar deleting destructor rewrites them at `0x004ce506/0x004ce50c/0x004ce516`.
- [UID:0000SA][g_pSimpleHelpPane2](by-global/g_pSimpleHelpPane2.md) remains a 4-byte `.data` singleton at `0x0067a7d4` with live xrefs at `0x00451adb`, `0x004c751b`, `0x004c7522`, `0x004c75fa`, `0x004c76ad`, `0x004c772a`, `0x004c7731`, `0x004ce320`, and `0x004ce520`.
- IDA still reports no direct code xrefs to constructor entry `0x004c74b0`; the live construction surface is the adjacent factory at `0x004c7680`, which is called from `0x0045213c` and by raw wrappers at `0x004c77fe` and `0x004c783b`.
- 2026-06-04 raw helper recheck confirms IDA has no function objects at `0x004c77e0`, `0x004c7810`, or `0x004c7850`. The first two bodies forward to `0x004c7680`; the third reads `g_pEventMan`, gets cursor position, offsets the stored anchor rectangle, checks emptiness, and calls the rectangle containment helper `0x004b7e80`.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `86` | The class now has exact constructor, ordinary teardown, event, factory, raw-helper, adjustor-thunk, scalar-destructor, vtable, singleton, and parent-source evidence. Completion remains below final because the factory/helper names, field names, and source visibility are still not final-audit quality. |
| Confidence `86` | Live IDA vtable names, slot refs, lifecycle writes, singleton xrefs, factory xrefs, and disassembly agree with the HelpPanes parent and companion by-memory pages. Confidence remains capped because IDA has no direct xrefs to `0x004c74b0` and the raw helper starts are not modeled as functions. |

## Cross-References

- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md)
- [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md)
- [UID:00022O][0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers](by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md)
- [UID:0000SA][g_pSimpleHelpPane2](by-global/g_pSimpleHelpPane2.md)
- [UID:000063][HelpPane](by-class/HelpPane.md)

## Changes

- 2026-06-04 live IDA recheck:
  - Before: completion/confidence were `82/76`, `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` were blank, and the page did not document the ordinary teardown at `0x004c75e0`.
  - Changed to: completion `86`, confidence `86`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000JU`.
  - Evidence: live IDA MCP confirmed the full method map, the ordinary destructor body at `0x004c75e0-0x004c7609`, three `SimpleHelpPane2` vtable views at `0x0061ac6c`, `0x0061acb8`, and `0x0061ace8`, lifecycle vtable writes, all nine singleton xrefs to `0x0067a7d4`, factory callers at `0x0045213c`, `0x004c77fe`, and `0x004c783b`, and the raw helper bodies following the factory.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `82`, confidence `76`.
- Evidence: the page documents inheritance, singleton, anchor/timer behavior, constructor, input handlers, factory, raw helper island, scalar destructor, and IDA xref caveats; confidence is capped because the constructor has no current direct xrefs.
