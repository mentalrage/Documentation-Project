*** UID:0000D7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SimpleHelpPane2

## Status

- Likely source file: [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- Address range: [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md), adjacent factory [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md), raw factory helpers [UID:00022O][0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers](by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md), with destructor thunks in [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- Current recovered file: `source-3/simroot_v2/class_SimpleHelpPane2.cpp`
- Confidence: strong for inheritance and behavior; medium for live construction because IDA reports no direct xrefs to the constructor.

## Class Purpose

`SimpleHelpPane2` is a `HelpPane` subclass that adds an anchor rectangle and an auto-hide timer. It stores the active singleton, converts a parent-relative anchor rectangle into local coordinates, and hides itself on relevant input/timer events.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SimpleHelpPane2` | `0x004c74b0-0x004c75d5` | Calls `HelpPane::HelpPane`, writes [UID:0000SA][g_pSimpleHelpPane2](by-global/g_pSimpleHelpPane2.md), stores anchor rectangle, and schedules auto-hide. |
| `OnAccept` | `0x004c7610-0x004c7620` | Dismisses/marks delete in current generated view. |
| `HandleEvent` | `0x004c7620-0x004c7668` | Cancels timer on button events and can cancel when the cursor leaves the anchor rectangle. |
| `OnCancel` | `0x004c7670-0x004c7680` | Dismisses/marks delete in current generated view. |
| `CreateSimpleHelpPane2` / `ShowSimpleHelpPane2` | [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md) | File-local factory that replaces the active singleton, constructs the popup, stores anchor bounds, and schedules the timer. |
| factory wrappers / anchor predicate | [UID:00022O][0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers](by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md) | Raw unmodeled helpers: two wrappers around the factory and one stored-anchor/current-cursor predicate. |
| `ScalarDeletingDestructor` | `0x004ce500-0x004ce55f` | Clears singleton, tears down `HelpPane`, and optionally deletes storage. |

## Evidence Notes

- IDA decompilation shows a direct call to [UID:000063][HelpPane](by-class/HelpPane.md) at `0x004c74ff`.
- IDA currently reports no direct xrefs to `0x004c74b0`; vtable/destructor refs still support a real class.
- 2026-05-26 IDA MCP confirms the adjacent factory at `0x004c7680` is called from `0x0045213c`, uses [UID:0001OY][0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2](by-memory/0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2.md), and is currently absent from active `simroot_v2` `.cpp` output.
- 2026-05-28 IDA MCP raw disassembly confirms [UID:00022O][0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers](by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md) immediately after the factory. IDA has no function objects/direct xrefs for those starts, but the bodies directly forward to the factory or inspect `SimpleHelpPane2` anchor state at `this + 0x224`.
- The generated file gives useful behavior but should be checked after data cleanup if this class becomes a migration target.

## Cross-References

- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md)
- [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md)
- [UID:00022O][0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers](by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md)
- [UID:0000SA][g_pSimpleHelpPane2](by-global/g_pSimpleHelpPane2.md)
- [UID:000063][HelpPane](by-class/HelpPane.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `82`, confidence `76`.
- Evidence: the page documents inheritance, singleton, anchor/timer behavior, constructor, input handlers, factory, raw helper island, scalar destructor, and IDA xref caveats; confidence is capped because the constructor has no current direct xrefs.
