*** UID:0000QM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pCrasher

## Status

- Confidence: strong for storage and owner.
- Address: `0x0067ab38`
- Likely source module: [UID:0000II][Crasher](by-file/Crasher.md)
- Type hypothesis: `Crasher*`
- Evidence basis: IDA MCP xrefs and `simroot_v2` generated source on 2026-05-24.

## Role

`g_pCrasher` stores the singleton [UID:00003A][Crasher](by-class/Crasher.md) pane/diagnostic object. Application startup constructs it, cleanup destroys it, and the class destructors clear it.

## Known Accesses

| Address | Access | Notes |
| --- | --- | --- |
| `0x004646ec` | constructor call path | `Application::Initialize` constructs a `0xf8` byte `Crasher` object. |
| `0x00464c4e` | cleanup path | `Application::CleanupResources` destroys the singleton if present. |
| `0x0049bb04` | write | `Crasher::Crasher` stores `this`. |
| `0x0049bb4a` | clear | `Crasher::~Crasher` clears the singleton. |
| `0x0049bbb0` | clear | `Crasher::ScalarDeletingDestructor` clears the singleton. |

## Cross-References

- [UID:00003A][Crasher](by-class/Crasher.md)
- [UID:0000II][Crasher](by-file/Crasher.md)
- [UID:000129][0x0049bae0-0x0049bbef.Crasher](by-memory/0x0049bae0-0x0049bbef.Crasher.md)
- [UID:0000HG][Application](by-file/Application.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `84/84`. Summary/evidence: the page documents address, owner, singleton role, application construction/cleanup paths, constructor/destructor clear sites, and class/file/memory refs.
