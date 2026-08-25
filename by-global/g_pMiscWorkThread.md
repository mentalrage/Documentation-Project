*** UID:0000RQ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// UID:0000RQ | MiscWorkThread singleton pointer and Singleton specializations.

MiscWorkThread* g_pMiscWorkThread = 0;

template <>
Singleton<MiscWorkThread>::Singleton()
{
    g_pMiscWorkThread = static_cast<MiscWorkThread *>(this);
}

template <>
Singleton<MiscWorkThread>::~Singleton()
{
    g_pMiscWorkThread = 0;
}

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pMiscWorkThread

## Status

- Confidence: strong for storage, owner, lifecycle writes, and feature consumers.
- Address: `0x0067ab50`
- Memory doc: [UID:0001P8][0x0067ab50-0x0067ab54.g_pMiscWorkThread](by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md)
- Likely source module: [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)
- Type hypothesis: `MiscWorkThread*`
- Evidence basis: IDA MCP xrefs and linked by-memory documentation.

## Role

`g_pMiscWorkThread` is the sole external zero-initialized `MiscWorkThread*` storage cell. Application startup constructs the complete object, feature modules use the complete pointer to queue background work, and class-specific `Singleton<MiscWorkThread>` specializations publish and clear the cell during base construction/destruction.

## Known Accesses

| Address | Access | Notes |
| --- | --- | --- |
| `0x00464715` | constructor call path | `Application::Initialize` constructs the `MiscWorkThread` object. |
| `0x00464a88` | cleanup path | `Application::CleanupResources` destroys the singleton if present. |
| `0x005281f1` / `0x005281f8` | write | Inlined `Singleton<MiscWorkThread>::Singleton()` specialization lowering converts the empty base at `+0x68` to the complete object and publishes it, preserving null conversion behavior. |
| `0x00528262` | clear | Inlined `Singleton<MiscWorkThread>::~Singleton()` specialization lowering clears the global during reverse base destruction. |
| `0x005283e0` | unwind clear | Compiler-retained 11-byte EH action for the same destructor specialization; no second source helper. |
| `0x00528429` | scalar-wrapper clear | Compiler scalar-deleting path reuses ordinary destruction and therefore the same specialization lowering. |
| `0x00530141` | read/use | Registration/NCA request path queues work through the singleton. |
| `0x00549295` | read/use | PatchPane2/download path queues HTTP work through the singleton. |

## Ownership Notes

- This global belongs with [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md), not [UID:00001H][CashShopRequest](by-class/CashShopRequest.md).
- Request wrappers at `0x00528290` and `0x00528310` are live `MiscWorkThread` submission helpers whose callers first read this singleton. Raw `0x005283b0` is the retained no-route sibling `MiscWorkThread::RequestBrowseDirectory(const char*)`; it queues `0x42446972` through the same [UID:0000EV][Thread](by-class/Thread.md) dispatch helper even though no direct static caller/reference has been found.
- Consumers require a complete `MiscWorkThread*`, not a pointer to the empty Singleton base facet. The direct Singleton PMD `{0x68,-1,0}` and exact 0x68 object size explain the compiler's `-0x68` complete-object adjustment in the constructor specialization.
- The exact source route is one global definition plus two explicit specializations in this page, ordered before `[[CHILDREN]]`. [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md) owns the sole `extern MiscWorkThread*` declaration in guarded H.
- Rejected alternatives are a generic `Singleton<T>` static field, a member pointer, a raw dword definition in the physical child, duplicate storage, handwritten assignments in the derived constructor/destructor, and one universal primary-template publication body.

## Live Evidence

- IDA MCP on 2026-06-16 confirms `0x0067ab50` is a four-byte `.data` slot in a zeroed singleton-adjacent window, with 8 direct data xrefs. This supersedes older notes that described the slot as initialized to `0xffffffff`.
- Live IDA xrefs confirm the documented lifecycle writes: `0x005281f1` and `0x005281f8` in the constructor, `0x00528262` in the non-deleting destructor, `0x005283e0` in the singleton-clear helper, and `0x00528429` in the scalar deleting destructor.
- Live IDA xrefs also confirm the documented consumers at `0x00464a88` in Application cleanup, `0x00530141` in the registration/NCA request path, and `0x00549295` in the patch/download path.
- Live IDA decompilation confirms `0x005281b0` publishes the current object or zero fallback into the singleton slot and installs the `MiscWorkThread` vtable; `0x00528230`, `0x005283e0`, and `0x005283f0` clear the singleton during cleanup/destruction.
- Historical C001 notes said the IDA names `g_pMiscWorkThread`, `MiscWorkThread_Constructor`, `MiscWorkThread_Destructor`, `MiscWorkThread_ClearSingletonHelper`, and `MiscWorkThread_ScalarDeletingDestructor` were saved. A later pre-catalog readback found the lifecycle entries still raw, so the C001 already-saved assertion remains superseded history. Supervisor catalog0382 subsequently applied only the evidence-backed lifecycle/RTTI subset: `MiscWorkThread_Constructor`, `MiscWorkThread_Destructor`, and `MiscWorkThread_ScalarDeletingDestructor`, with pointer-safe prototypes and exact function-repeatable comments. Catalog0382 did not rename or retype the `0x0067ab50` storage cell and did not create a `MiscWorkThread_ClearSingletonHelper` source entity.
- Catalog0382 exact saved state is MCP database `f608d7c2`, IDB SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, 143,192,751 bytes, saved `2026-07-31T06:21:13.3464834-04:00`; the prestate backup `NexusTK.exe.pre-B004-UID0004HM-20260731_061621.i64` is SHA256 `5F2679A7C6BFF2CD3E91FE59BDCBD298C1A233EB7988D838C34C05508FC79A21`.
- The applied lifecycle prototypes are `MiscWorkThread *__thiscall MiscWorkThread_Constructor(MiscWorkThread *this)`, `void __thiscall MiscWorkThread_Destructor(MiscWorkThread *this)`, and `MiscWorkThread *__thiscall MiscWorkThread_ScalarDeletingDestructor(MiscWorkThread *this, unsigned int flags)`. Their exact comments record Thread(100)/Singleton publication/vtable/start, vtable restore/stop/Singleton clear/Thread teardown, and ordinary destruction plus conditional project operator-delete. IDA local type ordinal `964` is deliberately incomplete, pointer-usable, unknown-size, and memberless; it does not claim the source layout.
- All eight direct refs to this storage, zero bytes, constructor publication, destructor/EH/scalar clears, consumers, target/lifecycle byte hashes, and runtime behavior were read back unchanged. The `0x005283e0` EH action remains raw compiler-retained lowering rather than a renamed standalone source helper.
- [UID:0001CK][0x00528290-0x005283d5.CashShopRequestAuthDirectory](by-memory/0x00528290-0x005283d5.CashShopRequestAuthDirectory.md) documents why the request wrappers are stale `CashShopRequest` ownership and should remain under `MiscWorkThread`.
- [UID:0001P8][0x0067ab50-0x0067ab54.g_pMiscWorkThread](by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md) remains the canonical memory page for this slot and matches the live IDA check.
- B011 2026-06-19 raw PE reanalysis resolves the raw browse wrapper shape: `0x005283b0-0x005283d5` duplicates the caller title via `0x005deb99`, queues `BDir`/`0x42446972` through `0x00596960`, has no direct `call`/`jmp`/VA/RVA start route, and belongs to the same `MiscWorkThread` source island as the live `ProcessWorkItem` BDir producer.

## Formal Source Definition

This page is the single source definition for the worker singleton pointer and the class-specific lifetime policy. Formal CPP emits `MiscWorkThread* g_pMiscWorkThread = 0;`, then explicit `Singleton<MiscWorkThread>` constructor/destructor specializations, then `[[CHILDREN]]`. The constructor specialization uses `static_cast<MiscWorkThread *>(this)` so standard base-to-derived conversion reproduces the observed PMD-adjusted, null-preserving complete-pointer publication. The destructor specialization clears the same cell before Thread teardown.

[UID:0001P8][0x0067ab50-0x0067ab54.g_pMiscWorkThread](by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md) remains the exact storage/no-duplicate child. Formal H remains blank because [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md) owns the external declaration. The generic storage-free template declaration is [UID:0004ZL][SingletonTemplate](by-type/by-template/SingletonTemplate.md), owned by [UID:0004ZK][Singleton](by-file/Singleton.md).

## Cross-References

- [UID:00008I][MiscWorkThread](by-class/MiscWorkThread.md)
- [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md)
- [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md)
- [UID:0001P8][0x0067ab50-0x0067ab54.g_pMiscWorkThread](by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:0000MH][PatchPane](by-file/PatchPane.md)
- [UID:0004ZK][Singleton](by-file/Singleton.md)
- [UID:0004ZL][SingletonTemplate](by-type/by-template/SingletonTemplate.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `84`, confidence `88`.
- Summary/evidence: the page now consolidates exact storage, owner, constructor/destructor writes, consumer reads, and stale `CashShopRequest` correction evidence verified against live IDA MCP xrefs. Confidence remains below fully settled because final wrapper names are still provisional.

- 2026-06-05 autogen classification:
  - What existed before: autogen metadata was blank, so the singleton was reported as unclassified.
  - Changed to: `RECONSTRUCTABLE:TRUE` with `AUTOGEN_PARENT_UID:0000LG`; `RECONSTRUCTION_CPP CODE` remains empty.
  - Summary/evidence: live IDA MCP `xrefs_to 0x0067ab50` and decompilation of `0x005281b0`, `0x00528230`, `0x005283e0`, and `0x005283f0` prove NexusTK-owned `MiscWorkThread` singleton storage owned by [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md). No final C++ body was added because the page is below the 95/95 reconstruction gate.
- 2026-06-06 source-facing cleanup:
  - What existed before: score `76/82`, thin source-facing summary, and raw IDA labels in the evidence.
  - Changed to: score `84/88`, refreshed live xref/byte evidence, source-facing singleton wording, and synced the manual by-global coverage row.
  - Summary/evidence: current IDA MCP confirms initialized storage, constructor publish/fallback clear, destructor/helper/deleting-destructor clears, Application cleanup read, registration/NCA and patch/download consumers, and file-parent ownership through [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md). C++ remains blank under the final-code gate.
- 2026-06-16 C001 global/source-quality refresh:
  - What existed before: score `84/88`, exact singleton evidence was documented, but IDA still used generated names and older byte evidence described the slot as `0xffffffff`.
  - Changed to: score `85/89`; IDA names were saved for the global and four lifecycle helpers, and the byte evidence now records the current zeroed singleton-adjacent window.
  - Summary/evidence: live IDA reconfirmed 8 direct xrefs, constructor publish/fallback clear, destructor/helper/scalar-deleting clears, Application cleanup, registration/NCA, and patch/download consumers, plus direct owner/emitter route through [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md). Final C++ remains blank because wrapper names, the raw `0x005283b0` browse-directory helper shape, notification class layout spelling, and `app/MiscWorkThread.cpp` versus alternate source path remain provisional.
- 2026-06-21 Rule 26 incorporation of B011 brdir notification source-quality report:
  - Score unchanged at `85/89`.
  - Summary/evidence: updated support wording after B011 resolved raw `0x005283b0` as retained no-route `MiscWorkThread::RequestBrowseDirectory(const char*)`, tied the wrapper to the live BDir branch and [UID:000012][brdir__Notification](by-class/brdir__Notification.md), and preserved this singleton's owner/emitter route through [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md).
- 2026-07-01 B008 empty-emitter family implementation:
  - Changed from `COMPLETION:85`, `CONFIDENCE:89`, blank formal C++.
  - Changed to `COMPLETION:87`, `CONFIDENCE:91`, `EMITTER_POSITION_OPTIONAL:4`, with formal singleton pointer definition C++ and `[[CHILDREN]]`.
  - Summary/evidence: B008 live IDA MCP confirmed zero image bytes at `0x0067ab50` and the same eight direct xrefs. [UID:0001P8][0x0067ab50-0x0067ab54.g_pMiscWorkThread](by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md) remains an exact storage child and must not emit a second pointer definition.
- 2026-07-31 B004 UID0004HM implementation:
  - Changed score from `87/91` to `90/94`; owner/emitter and position remain unchanged.
  - Kept the sole zero-initialized complete-object pointer definition, then added exact out-of-line `Singleton<MiscWorkThread>` constructor/destructor specializations before `[[CHILDREN]]`; H remains blank because UID00008I owns the one extern declaration.
  - Documented PMD `+0x68` base-to-complete publication, reverse-order clear, exact storage/eight refs, compiler EH/scalar reuse, ordering, and rejection of generic static/member/raw/duplicate/derived-body alternatives.
  - Historicalized the stale C001 assertion that raw lifecycle names had already been saved without deleting the otherwise valid evidence from that pass.
- 2026-07-31 supervisor catalog0382 saved-state reconciliation:
  - Recorded the applied/read-back lifecycle names, pointer-safe prototypes, exact function-repeatable comments, minimal incomplete IDA type, protected zero storage/eight-ref state, prestate backup, and saved B7CC IDB identity above.
  - Preserved the older C001 and raw-readback sequence as superseded history. Catalog0382 did not mutate or duplicate the global storage definition and did not convert compiler EH action `0x005283e0` into source.
