*** UID:00008S | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MSGHandler
{
public:
    MSGHandler();
    virtual ~MSGHandler();

    virtual int DispatchMessage();

private:
    MSGHandler* m_previousHandler;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MSGHandler

## Summary

`MSGHandler` is a tiny application message-handler swap object. Construction registers the object with `Application::ExchangeMSGHandler`, destruction restores the previous target, and virtual dispatch forwards to the target object's dispatch slot.

## Likely Original Placement

- Source: [UID:0000LM][MSGHandler](by-file/MSGHandler.md), or private code in [UID:0000HG][Application](by-file/Application.md)
- Proposed path: `app/Application.cpp` or `app/MSGHandler.cpp`
- Confidence: medium

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
