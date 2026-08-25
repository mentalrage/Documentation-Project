*** UID:0000QM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000II | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000II | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
Crasher *g_pCrasher = 0;

template <>
Singleton<Crasher>::Singleton()
{
    g_pCrasher = static_cast<Crasher *>(this);
}

template <>
Singleton<Crasher>::~Singleton()
{
    g_pCrasher = 0;
}

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pCrasher

## Status

- Confidence: very strong for storage, owner, zero initializer, direct Singleton base, and class-specific publication/clear source shape.
- Address: `0x0067ab38`
- Likely source module: [UID:0000II][Crasher](by-file/Crasher.md)
- Type hypothesis: `Crasher*`
- Evidence basis: IDA MCP xrefs and decompilation.

## Role

`g_pCrasher` is the sole external zero-initialized pointer for the [UID:00003A][Crasher](by-class/Crasher.md) pane/diagnostic singleton. Application startup and cleanup order the complete object's lifetime; this global page owns the definition and class-specific `Singleton<Crasher>` constructor/destructor specializations.

The direct Singleton RTTI base has PMD `{0xf8,-1,0}` while the complete allocation is exactly `0xf8`, proving empty-base optimization. Constructor lowering converts the empty-base facet at `+0xf8` back to the complete `Crasher *` before publication; reverse base destruction clears the cell. The derived constructor/destructor therefore remain empty apart from `Pane(0)` base construction and compiler-generated teardown.

## Known Accesses

| Address | Access | Notes |
| --- | --- | --- |
| `0x004646ec` | constructor call path | `Application::Initialize` constructs a `0xf8` byte `Crasher` object. |
| `0x00464c4e` | cleanup path | `Application::CleanupResources` destroys the singleton if present. |
| `0x0049bb04` | write | `Crasher::Crasher` stores `this`. |
| `0x0049bb4a` | clear | `Crasher::~Crasher` clears the singleton. |
| `0x0049bbb0` | clear | `Crasher::ScalarDeletingDestructor` clears the singleton. |

## Live Evidence

- Current raw PE and IDB bytes at `0x0067ab38` are `00 00 00 00` (raw offset `0x278738`, SHA-256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`). The earlier `0xffffffff` reading is disproved historical evidence, not a source initializer.
- The same pass rechecked all four xrefs: Application cleanup reads the slot at `0x00464c4e`, `Crasher::Crasher` writes it at `0x0049bb04`, the ordinary destructor clears it at `0x0049bb4a`, and the scalar deleting destructor clears it at `0x0049bbb0`.
- Neighboring slot review distinguishes this from [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md) at `0x0067ab34` and the following unrelated singleton at `0x0067ab3c`; `g_pCrasher` is exactly the half-open `0x0067ab38-0x0067ab3c` storage documented by [UID:000298][0x0067ab38-0x0067ab3c.g_pCrasher](by-memory/0x0067ab38-0x0067ab3c.g_pCrasher.md).
- Source order is deterministic: [UID:00003A][Crasher](by-class/Crasher.md) contributes the include preamble and class declaration at file position `0`; this global contributes the sole definition and explicit specializations at position `1`; [UID:000129][0x0049bae0-0x0049bbef.Crasher](by-memory/0x0049bae0-0x0049bbef.Crasher.md) contributes source-authored methods at position `2`.
- Formal H is intentionally blank because UID00003A owns the single `extern Crasher *g_pCrasher;` declaration. Exact storage UID000298 is covered-by only and cannot emit a duplicate definition.

## Source-Shape Decision

The explicit specializations are the source-level cause of all three local publication/clear writes. This matches the established storage-free primary-template policy on [UID:0004ZK][Singleton](by-file/Singleton.md) and [UID:0004ZL][SingletonTemplate](by-type/by-template/SingletonTemplate.md). Rejected alternatives are a generic `Singleton<T>` static member, one universal publication body, a `Crasher` member pointer, a raw integer object, duplicate physical-page storage, and handwritten publication/clear statements in the derived methods.

The zero definition belongs here rather than Application.cpp: Application has only construction/cleanup consumers, while the two writes and one clear in Crasher lifecycle lowering express this module's class-specific singleton policy.

## Score Rationale

Completion is `93` because exact storage bytes, all lifecycle xrefs, adjacent boundaries, class/file ownership, direct Singleton RTTI/PMD, EBO complete-pointer adjustment, one-definition route, formal source, and source order are closed. Confidence is `95` because raw PE, current IDB, RTTI, lifecycle lowering, and the shared Singleton policy independently agree; missing original symbols limit historical spelling but do not leave a behavior/source-placement blocker.

## Cross-References

- [UID:00003A][Crasher](by-class/Crasher.md)
- [UID:0000II][Crasher](by-file/Crasher.md)
- [UID:000129][0x0049bae0-0x0049bbef.Crasher](by-memory/0x0049bae0-0x0049bbef.Crasher.md)
- [UID:000298][0x0067ab38-0x0067ab3c.g_pCrasher](by-memory/0x0067ab38-0x0067ab3c.g_pCrasher.md)
- [UID:0000HG][Application](by-file/Application.md)

## Changes

- 2026-08-06 B005 UID000298 source-quality implementation:
  - Raised `86/88 -> 93/95`, retained owner/emitter UID0000II, and set emitter position `1`.
  - Added the sole zero definition, exact `Singleton<Crasher>` constructor/destructor specializations, and `[[CHILDREN]]`; H remains blank because UID00003A owns the sole extern.
  - Incorporated exact zero bytes, four-xref lifecycle, direct Singleton PMD/EBO adjustment, legal source order, and rejected generic-static/member/raw/duplicate/handwritten-derived alternatives.
  - Historical `0xffffffff` and derived-body publication assumptions remain below as dated superseded evidence.

- 2026-06-22 B015 class source-quality incorporation:
  - Score unchanged at `86/88`.
  - Preserved [UID:0000II][Crasher](by-file/Crasher.md) ownership and added the draft declaration policy: use `Crasher *g_pCrasher;`, not a source initializer for the `0xffffffff` image value until the singleton sentinel convention is settled.
- 2026-06-17 B001 source-quality sync:
  - Score unchanged at `86/88`.
  - Added the singleton initializer/sentinel convention as the remaining final-source blocker while preserving [UID:0000II][Crasher](by-file/Crasher.md) ownership.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `84/84`. Summary/evidence: the page documents address, owner, singleton role, application construction/cleanup paths, constructor/destructor clear sites, and class/file/memory refs.
- 2026-06-05: Marked reconstructable under [UID:0000II][Crasher](by-file/Crasher.md). Evidence: live IDA MCP reports four xrefs to `0x0067ab38`; decompilation confirms `0x0049bae0` writes `dword_67AB38`, `0x0049bb30` clears it in non-deleting teardown, and `0x0049bb90` clears it in the deleting destructor path.
- 2026-06-07 A006 parent-gate refresh:
  - Before: `COMPLETION:84`, `CONFIDENCE:84`; memory child assignment was blocked by the stricter `85/85` parent gate.
  - After: `COMPLETION:86`, `CONFIDENCE:88`; the page now clears the direct-parent gate for [UID:000298][0x0067ab38-0x0067ab3c.g_pCrasher](by-memory/0x0067ab38-0x0067ab3c.g_pCrasher.md).
  - Evidence: live IDA MCP rechecked the initialized storage dword, exact four-xref lifecycle set, adjacent slot boundaries, and owner file/class linkage.
