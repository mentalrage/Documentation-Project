*** UID:00004L | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Event

## Summary

`Event` is the small base event object used by the UI event dispatch system. It initializes an `LObject` base, stores a default event type of `0xff`, and provides destructor/deleting-destructor behavior.

## Likely Original Placement

- Source: [UID:0000J6][Event](by-file/Event.md), or private code in [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- Confidence: medium

## Methods

- `0x004a8a90` constructor - initializes `LObject`, installs Event vtable, and sets default event type.
- `0x004a8ab0` destructor - resets vtable/type and destroys `LObject`.
- `0x004ab3f0` scalar deleting destructor.

## Evidence

- Wave3 reports three methods and no disabled methods.
- IDA MCP confirms constructor at `0x004a8a90-0x004a8ab0`, destructor at `0x004a8ab0-0x004a8abf`, and scalar deleting destructor at `0x004ab3f0-0x004ab435`.
- Direct callers include application/event adapter paths and other event subclasses.

## Open Questions

- Identify subclasses and event-type constants before finalizing names for the event family.

## Cross-References

- File: [UID:0000J6][Event](by-file/Event.md)
- Dispatcher/module context: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- Related class: [UID:00004M][EventDispatcher](by-class/EventDispatcher.md)
- Memory: [UID:00014B][0x004a8a90-0x004ab434.EventObjects](by-memory/0x004a8a90-0x004ab434.EventObjects.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `72/80`.
  - Summary/evidence: event base role, constructor/destructor/scalar-destructor addresses, IDA-confirmed boundaries, and dispatcher/module context are documented; remaining work is subclass inventory and event-type constant naming.
