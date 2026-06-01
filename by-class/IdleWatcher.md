*** UID:00006C | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:66 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# IdleWatcher

## Summary

`IdleWatcher` is a small pane-derived singleton that watches idle state and schedules timer callbacks. It is created during `Application::Startup` and stores itself in `g_pIdleWatcher`.

## Likely Original Placement

- Source: [UID:0000K0][IdleWatcher](by-file/IdleWatcher.md) as a startup-owned singleton, with [UID:0000HG][Application](by-file/Application.md) as constructor owner/caller
- Confidence: medium

## Methods

- `0x004cfe60` constructor - constructs the pane base, installs vtables, and sets `g_pIdleWatcher`.
- `0x004cff20` `Activate` - sets the active flag and schedules a timer.
- `0x004cff37` adjustor thunk, disabled in current active partition.
- `0x004cff42` scalar-deleting destructor adjustor thunk, disabled in current active partition.
- `0x004cff50` scalar deleting destructor - resets vtables, clears `g_pIdleWatcher`, destroys the base, and optionally frees memory.

## Evidence

- Wave3 reports three active methods and two disabled thunk methods.
- IDA MCP confirms constructor `0x004cfe60-0x004cfeba`, `Activate` `0x004cff20-0x004cff37`, and scalar deleting destructor `0x004cff50-0x004cffaf`.
- IDA MCP shows the constructor is called from `Application::Startup` at `0x004f5ffe`.

## Open Questions

- Determine the exact timer callback target for the `Activate` path at `0x005975e0`.
- Decide whether the final source file should be `app/IdleWatcher.cpp`, `ui/core/IdleWatcher.cpp`, or part of a timer/idle module.

## Cross-References

- File: [UID:0000K0][IdleWatcher](by-file/IdleWatcher.md)
- Caller/module context: [UID:0000HG][Application](by-file/Application.md)
- Related classes: [UID:00000D][Application](by-class/Application.md), [UID:0000A2][Pane](by-class/Pane.md), [UID:00004M][EventDispatcher](by-class/EventDispatcher.md)
- Memory: [UID:000171][0x004cfe60-0x004cffaf.IdleWatcher](by-memory/0x004cfe60-0x004cffaf.IdleWatcher.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `66/74`. Summary: singleton purpose, startup construction, method list, IDA-confirmed boundaries, and open timer/source-placement questions are documented, but the page is still a compact summary and timer callback semantics remain unresolved. Evidence: `0x004cfe60-0x004cffaf.IdleWatcher`, Application startup caller, Pane/EventDispatcher relationships, and open `0x005975e0` timer target.
