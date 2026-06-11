*** UID:0000QM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000II | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Evidence basis: IDA MCP xrefs and decompilation.

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

## Live Evidence

- IDA MCP `py_eval` on 2026-06-07 confirms `0x0067ab38` is named `dword_67AB38`, is initialized to `0xffffffff` in `.data`, and has exactly four direct data xrefs.
- The same pass rechecked all four xrefs: Application cleanup reads the slot at `0x00464c4e`, `Crasher::Crasher` writes it at `0x0049bb04`, the ordinary destructor clears it at `0x0049bb4a`, and the scalar deleting destructor clears it at `0x0049bbb0`.
- Neighboring slot review distinguishes this from [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md) at `0x0067ab34` and the following unrelated singleton at `0x0067ab3c`; `g_pCrasher` is exactly the half-open `0x0067ab38-0x0067ab3c` storage documented by [UID:000298][0x0067ab38-0x0067ab3c.g_pCrasher](by-memory/0x0067ab38-0x0067ab3c.g_pCrasher.md).

## Score Rationale

Completion is raised to `86` because the page now records exact storage bytes, all known lifecycle xrefs, boundary separation from adjacent singleton slots, owner file/class, and memory child evidence. Confidence is raised to `88` because live IDA confirms the full xref set and the owner file [UID:0000II][Crasher](by-file/Crasher.md) now clears the `85/85` parent gate; it remains below final audit because the source-level declaration spelling/linkage and virtual trigger caller are not fully closed.

## Cross-References

- [UID:00003A][Crasher](by-class/Crasher.md)
- [UID:0000II][Crasher](by-file/Crasher.md)
- [UID:000129][0x0049bae0-0x0049bbef.Crasher](by-memory/0x0049bae0-0x0049bbef.Crasher.md)
- [UID:000298][0x0067ab38-0x0067ab3c.g_pCrasher](by-memory/0x0067ab38-0x0067ab3c.g_pCrasher.md)
- [UID:0000HG][Application](by-file/Application.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `84/84`. Summary/evidence: the page documents address, owner, singleton role, application construction/cleanup paths, constructor/destructor clear sites, and class/file/memory refs.
- 2026-06-05: Marked reconstructable under [UID:0000II][Crasher](by-file/Crasher.md). Evidence: live IDA MCP reports four xrefs to `0x0067ab38`; decompilation confirms `0x0049bae0` writes `dword_67AB38`, `0x0049bb30` clears it in non-deleting teardown, and `0x0049bb90` clears it in the deleting destructor path.
- 2026-06-07 A006 parent-gate refresh:
  - Before: `COMPLETION:84`, `CONFIDENCE:84`; memory child assignment was blocked by the stricter `85/85` parent gate.
  - After: `COMPLETION:86`, `CONFIDENCE:88`; the page now clears the direct-parent gate for [UID:000298][0x0067ab38-0x0067ab3c.g_pCrasher](by-memory/0x0067ab38-0x0067ab3c.g_pCrasher.md).
  - Evidence: live IDA MCP rechecked the initialized storage dword, exact four-xref lifecycle set, adjacent slot boundaries, and owner file/class linkage.
