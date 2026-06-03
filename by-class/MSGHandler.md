*** UID:00008S | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MSGHandler

## Summary

`MSGHandler` is a tiny application message-handler swap object. Construction registers the object with `Application::ExchangeMSGHandler`, destruction restores the previous target, and virtual dispatch forwards to the target object's dispatch slot.

## Likely Original Placement

- Source: [UID:0000LM][MSGHandler](by-file/MSGHandler.md), with a remaining possibility that the original declaration was private in [UID:0000HG][Application](by-file/Application.md)
- Proposed path: `NexusTK/app/MSGHandler.cpp` for current generated staging, or private `Application` helper after final source-layout audit.
- Confidence: medium-high for class identity, method set, vtable, and app ownership; medium for final standalone-vs-private source split.

## Methods

- `0x00528d60` constructor - sets vtable and swaps itself into `Application`.
- `0x00528d80` destructor - restores the previous handler target.
- `0x00528dd0` `DispatchMessage` - forwards through target virtual slot 1.
- `0x00528df0` scalar deleting destructor - unregisters and optionally deletes.
- `0x0061fbf8-0x0061fc04` read-only vtable tail - exact `.rdata` split for the `MSGHandler` virtual table.

## Evidence

- IDA MCP confirms all four functions and shows constructor/destructor call `Application::ExchangeMSGHandler` at `0x00465650`.
- IDA MCP confirms `??_7MSGHandler@@6B@` at `0x0061fbf8` and xrefs from the constructor/destructor/deleting-destructor vtable writes.
- Generated source shows `Application` embeds or owns a `MSGHandler` subobject during construction/destruction.
- The source-root page [UID:0000LM][MSGHandler](by-file/MSGHandler.md) is already `84/82` and stages under `NexusTK/app/`, so the class parent attachment is valid. The exact executable aggregate [UID:0001CN][0x00528d60-0x00528e55.MSGHandler](by-memory/0x00528d60-0x00528e55.MSGHandler.md) and vtable data [UID:0002GL][0x0061fbf8-0x0061fc04.MSGHandlerReadOnlyData](by-memory/0x0061fbf8-0x0061fc04.MSGHandlerReadOnlyData.md) provide the current authoritative method/data evidence.

## Reconstruction Gate

Keep `RECONSTRUCTABLE:TRUE` and the parent assignment to [UID:0000LM][MSGHandler](by-file/MSGHandler.md), but keep the C++ block empty. The class is simple, yet final-source C++ is still below the 95+ gate because the exact source split from `Application.cpp`, final declaration visibility, and field naming have not had a near-final audit.

## Open Questions

- Decide whether this was a private class in `Application.h` or a standalone `MSGHandler.cpp`.

## Cross-References

- File: [UID:0000LM][MSGHandler](by-file/MSGHandler.md)
- Caller/module context: [UID:0000HG][Application](by-file/Application.md)
- Related class: [UID:00000D][Application](by-class/Application.md)
- Memory: [UID:0001CN][0x00528d60-0x00528e55.MSGHandler](by-memory/0x00528d60-0x00528e55.MSGHandler.md), [UID:0002GL][0x0061fbf8-0x0061fc04.MSGHandlerReadOnlyData](by-memory/0x0061fbf8-0x0061fc04.MSGHandlerReadOnlyData.md)

## Changes

- Before: the memory cross-reference pointed to an endpoint ending at `0x00528e54`.
- Changed to: the memory cross-reference points to `0x00528d60-0x00528e55`.
- Summary/evidence: 2026-05-28 IDA MCP confirms the scalar deleting destructor includes the `retn 4` operand byte at `0x00528e54`, so the exclusive end is `0x00528e55`.
- Completion/confidence score update: existed before as `0/0`; changed to `70/74`. Summary: the tiny message-handler swap object has purpose, likely placement, method list, and IDA evidence documented, but the original standalone-vs-private declaration remains unresolved. Evidence: constructor/destructor calls to `Application::ExchangeMSGHandler`, forwarding dispatch slot, and corrected memory range.
- 2026-06-03 score and code-gate correction:
  - What existed before: the class was scored `70/74` but already contained final-looking C++ despite being below the project reconstruction-code threshold.
  - Changed to: scores `82/86`; `RECONSTRUCTION_CPP CODE` is empty while the reconstructable flag and parent UID stay in place.
  - Summary/evidence: linked source, executable-range, and vtable pages now document enough class identity, method set, app ownership, and staging evidence for medium-high confidence. Final C++ remains gated by the unresolved standalone-vs-private source split and the 95+ policy.
