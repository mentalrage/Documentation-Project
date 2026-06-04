*** UID:00004L | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Event

## Summary

`Event` is the base event record used by the UI event dispatch system. It initializes an `LObject` base, installs the `Event` vtable, stores a default event type of `0xff` at `this + 0x04`, and provides ordinary and scalar deleting destructor behavior for stack and heap event records.

## Likely Original Placement

- Source: [UID:0000J6][Event](by-file/Event.md)
- Proposed path: `NexusTK/ui/core/Event.cpp`
- Confidence: strong for the UI-core event object/factory module; medium for the final `EventMan` split.

## Methods

| Address | Method | Role |
| --- | --- | --- |
| `0x004a8a90-0x004a8ab0` | constructor | Calls the `LObject` initializer, installs vtable `0x006196a4`, and stores default event type `0xff` at `+0x04`. |
| `0x004a8ab0-0x004a8abf` | destructor | Restores vtable `0x006196a4`, resets type byte `+0x04` to `0xff`, and tail-calls the `LObject` destructor. |
| `0x004ab3f0-0x004ab435` | scalar deleting destructor | Runs the same base teardown and handles scalar-delete flags, including the 0x110-byte sized-delete path. |

## Evidence

2026-06-04 live IDA pass:

- Binary identity: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, image base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- Function bounds are `0x004a8a90-0x004a8ab0`, `0x004a8ab0-0x004a8abf`, and `0x004ab3f0-0x004ab435`.
- Direct constructor call sites are `0x00466530` and `0x0046668b` in function `0x00465f20`, `0x00513e62` in function `0x00513da0`, `0x00588c74` in function `0x00588c40`, and `0x0058eb81` in function `0x0058eb50`.
- The constructor calls `0x004f4a80`, writes vtable `0x006196a4`, and initializes the event type byte to `0xff`.
- The ordinary destructor writes vtable `0x006196a4`, resets the event type byte to `0xff`, and tail-calls `0x004f4a90`.
- The scalar deleting destructor writes vtable `0x006196a4`, resets the event type byte, calls `0x004f4a90`, conditionally frees through `0x004f4ac0`, and uses a 0x110-byte sized-delete path when flag bit `4` is set.
- Read-only data shows `0x006196a0` is the `Event` RTTI-adjacent word, `0x006196a4` is the `Event` vtable, and `0x006196b0` begins the following `EventMan` RTTI/vtable data.
- The bytes before `0x004a8a90` and after `0x004ab435` are `0xcc` padding. The gap after `0x004a8abf` contains separate event predicate/factory helper bodies before `EventMan`, so it should not be modeled as part of the base destructor.

## Open Questions

- Final event-record payload field names and event-type constant names remain below final-source confidence.
- The broad [UID:00014B][0x004a8a90-0x004ab434.EventObjects](by-memory/0x004a8a90-0x004ab434.EventObjects.md) memory page still records the historical aggregate range; this class page uses live IDA function bounds.

## Cross-References

- File: [UID:0000J6][Event](by-file/Event.md)
- Dispatcher/module context: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- Related class: [UID:00004M][EventDispatcher](by-class/EventDispatcher.md)
- Event producer: [UID:00004O][EventMan](by-class/EventMan.md)
- Memory: [UID:00014B][0x004a8a90-0x004ab434.EventObjects](by-memory/0x004a8a90-0x004ab434.EventObjects.md)
- Read-only data: [UID:000258][0x00619344-0x006196c0.ErrorEventReadOnlyData](by-memory/0x00619344-0x006196c0.ErrorEventReadOnlyData.md)

## Changes

- 2026-06-04:
  - Before: scored `72/80`, unattached for autogen, cited stale provenance, and summarized only three method addresses.
  - After: scored `84/88`, marked `RECONSTRUCTABLE:TRUE`, attached to [UID:0000J6][Event](by-file/Event.md), and kept final C++ blank because event-record field names and constants are not 95/95.
  - Summary/evidence: live IDA MCP confirmed binary identity, exact constructor/destructor/scalar-destructor bounds, direct constructor callers, vtable writes and slots at `0x006196a0-0x006196b0`, default type-byte behavior, 0x110-byte sized-delete path, neighboring `EventMan` data boundary, and the non-owned helper bodies in the post-destructor gap.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `72/80`.
  - Summary/evidence: event base role, constructor/destructor/scalar-destructor addresses, IDA-confirmed boundaries, and dispatcher/module context are documented; remaining work is subclass inventory and event-type constant naming.
