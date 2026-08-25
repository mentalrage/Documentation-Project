*** UID:0000HK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NONE" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# AttachedObjectPaneHelper_53AEC0

## Status

- Confidence is very strong that `AttachedObjectPaneHelper_53AEC0` is a rejected generated one-method file identity, not an original compilation unit. The exact identifier spelling and original source-control layout remain archival uncertainties, so the score does not claim 100-percent recovery.
- Exact source-bearing body: [UID:0001DF][0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane](by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md), owned/emitted by [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md) through [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md).
- Caller context only: `AttachedObjectPane::~AttachedObjectPane` at `0x005382b0` loads `LivingObjectPane *m_livingObjectPane` from `AttachedObjectPane +0x128`, then calls the owner-side unregister method with the dying pane.
- This quarantine page intentionally remains `PROPOSED_RECONSTRUCTION_PATH:"NONE"` and `CANONICAL_OWNER:NONE`; it emits no CPP or H and has no generated source root.
- Historical generated label: `AttachedObjectPaneHelper_53AEC0`. It remains searchable provenance, not a final human source-file name.

## File Role

This page quarantines a generated one-method file split. The represented function is the owner-side `LivingObjectPane::UnregisterAttachedObjectPane(AttachedObjectPane *pane)` method. It removes a destroyed attached overlay from the exact LivingObjectPane list/singleton registry that is initialized, populated, and destroyed by adjacent LivingObjectPane methods.

The method has exactly one external code caller: `AttachedObjectPane::~AttachedObjectPane` at `0x005382b0`. The destructor reads `m_livingObjectPane` from `AttachedObjectPane +0x128` and calls the owner method with the dying pane. This is a destruction-time back-pointer callback, not evidence that AttachedObjectPane.cpp or a standalone helper file owns the registry method.

## Ownership Decision

Do not create `AttachedObjectPaneHelper_53AEC0.cpp` or a matching header. Current whole-file, UDT, xref, range, compiler-table, and generated-output evidence closes this identity as a quarantine page with zero original source items.

Do not fold the function into this generated split or into `AttachedObjectPane.cpp`. The typed receiver, registry-field lifecycle, physical method island, and current source route place the exact function in [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md); [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) is only the destructor-call context:

| Entity | Evidence | Proposed placement |
| --- | --- | --- |
| `LivingObjectPane::UnregisterAttachedObjectPane` | [UID:0001DF][0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane](by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md); typed `LivingObjectPane *` receiver; sole caller is `AttachedObjectPane::~AttachedObjectPane` | [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md); this page remains a rejected generated one-method file split. |
| registry layout | list pointers at `+0x170` and `+0x174`; singleton slots at `+0x1d8-0x1e4` | [UID:0001TR][AttachedObjectRegistryLayout](by-type/by-struct/AttachedObjectRegistryLayout.md). |
| [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` | Historical generated alias `g_attachmentModeFlag` is misleading; broad UI/render mode selector with 366 xrefs | Canonical global, not attachment-specific state. |

## Current Whole-File Inventory

Current research finds zero items belonging to an original `AttachedObjectPaneHelper_53AEC0` compilation unit. The complete accepted inventory is:

| Range / item | UID / identity | Current role and disposition |
| --- | --- | --- |
| pseudo-file identity | UID0000HK | Rejected generated one-method file split; quarantine prose only; no CPP/H. |
| pseudo-class identity | UID00000N | Rejected generated class split; non-reconstructable, ownerless, non-emitting, blank CPP/H. |
| `[0x0053aec0,0x0053b012)` | UID0001DF | Exact reconstructable `LivingObjectPane::UnregisterAttachedObjectPane`; owned/emitted by UID00007B in LivingObjectPane.cpp, not by this page. |
| `[0x0053aeb4,0x0053aec0)` | predecessor boundary | Twelve `0xCC` bytes after UID0004QO; compiler padding, no source item. |
| `[0x0053b012,0x0053b014)` | successor alignment | Two-byte `66 90` NOP alignment, no source item. |
| `[0x0053b014,0x0053b034)` | `jpt_53AEEE` | First 32-byte compiler switch table; one inbound switch reference and eight internal targets. |
| `[0x0053b034,0x0053b054)` | `jpt_53AF69` | Second 32-byte compiler switch table; one inbound switch reference and seven unique internal targets. |
| `[0x0053b054,0x0053b060)` | post-table boundary | Twelve `0xCC` bytes before the next function; compiler padding. |
| `[0x00538100,0x005382f8)` | UID0001D8 | AttachedObjectPane non-deleting destructor; sole caller context, not method ownership. |
| AttachedObjectPane `+0x128` | UID00000M / UID0001D8 | `LivingObjectPane *m_livingObjectPane`, the receiver source used by the destructor callback. |
| `[0x0053a110,0x0053a35d)` | UID0002R0 | First LivingObjectPane constructor variant; initializes the same registry fields. |
| `[0x0053a360,0x0053a59d)` | UID0002R0 | Second LivingObjectPane constructor variant; initializes the same registry fields. |
| `[0x0053aaf0,0x0053ab1a)` | UID0004QF | Adjacent LivingObjectPane sprite method; physical source-island context. |
| `[0x0053ab20,0x0053ab3a)` | UID0004QG | Adjacent moving-state setter; physical source-island context. |
| `[0x0053ab40,0x0053ad03)` | UID0004QH | Full linked-object teardown; destroys and clears the same registry field group. |
| `[0x0053ad10,0x0053ad9f)` | UID0004QI | Retained attached-object teardown; same-file lifecycle evidence. |
| `[0x0053ada0,0x0053adb0)` | UID0004QJ | Balloon singleton setter for `m_balloonObjectPane`. |
| `[0x0053adb0,0x0053ae06)` | UID0004QK | Primary Effect list add/replace for `m_primaryEffectObjectPanes`. |
| `[0x0053ae10,0x0053ae66)` | UID0004QL | Secondary Effect list add/replace for `m_secondaryEffectObjectPanes`. |
| `[0x0053ae70,0x0053ae80)` | UID0004QM | HitBar singleton setter for `m_hitBarObjectPane`. |
| `[0x0053ae80,0x0053ae90)` | UID0004QN | DamageNumber singleton setter for `m_damageNumberObjectPane`. |
| `[0x0053ae90,0x0053aeb4)` | UID0004QO | ObjectInfo singleton replacement for `m_objectInfoObjectPane`. |
| registry layout | UID0001TR | Exact typed offsets and roles; declaration support already exists under LivingObjectPane. |
| mode global | UID0000SW | Process-wide `bool g_useEpfAssets`; dependency only, with one definition elsewhere. |
| actual class | UID00007B | Complete LivingObjectPane type and unregister declaration; actual class owner. |
| actual file | UID0000KU | `NexusTK/map/LivingObjectPane.cpp`; actual compilation unit. |
| generated actual source | `auto-generated/NexusTK/map/LivingObjectPane.cpp` | One complete UID0001DF declaration and definition, no placeholder or duplicate. |
| pseudo generated source/header | absent | No target `.cpp` or `.h`; absence is required to avoid duplicate source. |

Every source-bearing item has an existing destination. No function, data definition, declaration, include, forward declaration, child order, or header belongs to this pseudo-file.

## Exact Method Behavior And Types

- Current IDA identity: `LivingObjectPane_UnregisterAttachedObjectPane` at `[0x0053aec0,0x0053b012)`, size `0x152`, type `void __thiscall(LivingObjectPane *this, AttachedObjectPane *pane)`, 29 basic blocks, cyclomatic complexity 19, and zero direct ordinary callees.
- The source method first rejects a null pane and object types outside the accepted `2..9` dispatch range. Unsupported/default cases return without changing registry state.
- Types `2` and `4` select `m_primaryEffectObjectPanes` and `m_secondaryEffectObjectPanes`. The method scans forward, removes only the first pointer-equal element with `RemoveAt(index, 1)`, and returns immediately.
- Type `6` clears `m_balloonObjectPane`; type `7` clears `m_hitBarObjectPane`; type `9` clears `m_objectInfoObjectPane`.
- Type `8` clears `m_damageNumberObjectPane` only while `g_useEpfAssets` is true. The legacy-mode switch deliberately performs no type-8 clear.
- The accepted public `ObjectPaneType` names are `kObjectPaneTypePrimaryEffect`, `kObjectPaneTypeSecondaryEffect`, `kObjectPaneTypeBalloon`, `kObjectPaneTypeHitBar`, `kObjectPaneTypeDamageNumber`, and `kObjectPaneTypeObjectInfo` for values `2`, `4`, `6`, `7`, `8`, and `9`.

## Caller, Range, And Compiler-Support Evidence

- The sole external code xref to `0x0053aec0` is the call at `0x005382b0` inside the AttachedObjectPane non-deleting destructor. The destructor has twelve known inbound destructor/wrapper refs, but none transfers ownership of the callee into AttachedObjectPane.cpp.
- The call loads `LivingObjectPane *` from `AttachedObjectPane +0x128` and passes the dying pane separately. This matches the typed `LivingObjectPane` receiver and `AttachedObjectPane *` parameter.
- Both jump tables are outside the exact function range. `jpt_53AEEE` has one inbound data xref from `0x0053aeee`; `jpt_53AF69` has one from `0x0053af69`. Every table target is an internal label in UID0001DF.
- Exhaustive current searches found no standalone constructor, allocation, vtable, RTTI, class-sized storage, helper-local global/static/string/resource/import cluster, callback/export, function-pointer table, encoded VA/RVA pointer route, second method, or generated root for the pseudo identity.

## Generated Source And No-Code / No-Header Proof

- Dated pre-callback physical readback on 2026-08-14: `auto-generated/NexusTK/map/LivingObjectPane.cpp`, validator command `000000023592`, 35,754 bytes, 1,156 lines, SHA256 `26AD636D9F63CF00092CDEF4EEC4C3059AF93F82DC9DB567F6FA791B8ECA33DF`.
- That generated file contains exactly one `void UnregisterAttachedObjectPane(AttachedObjectPane *pane);` declaration and one complete `void LivingObjectPane::UnregisterAttachedObjectPane(AttachedObjectPane *pane)` definition under UID0001DF.
- No `AttachedObjectPaneHelper_53AEC0.cpp` or `.h` exists. No such output is required: all 338 function bytes are already represented once by UID0001DF, adjacent bytes are compiler alignment/tables/padding, and the pseudo identity has no source-level interface.
- Formal CPP and H therefore remain absent for UID0000HK. Adding either channel would duplicate accepted source and create a non-human generated file split.

## Evidence Notes

- 2026-08-14 B003 live read-only IDA MCP session `supervisor-uid0000IW-recovery-20260814` passed canonical runtime attestation and reconfirmed the exact current method name/type/range, one caller, typed UDTs, registry fields, broad mode global, table items/xrefs, and surrounding bytes summarized above.
- The same pass measured `LivingObjectPane` as `0x20c` bytes and `AttachedObjectPane` as `0x12c` bytes; it reconfirmed `m_livingObjectPane` at `+0x128`, lists at `+0x170/+0x174`, and singleton slots at `+0x1d8/+0x1dc/+0x1e0/+0x1e4`.
- Current `g_useEpfAssets` evidence is a one-byte `bool` at `0x0066da97` with 366 xrefs. It is process-wide asset-layout state, not helper-local storage.

- 2026-06-14 A002 live IDA refresh against session `a001_goal2_class_batch`: `server_health` reported `NexusTK.exe` ready at image base `0x400000`; `lookup_funcs` reconfirmed `sub_53AEC0` at `0x0053aec0` size `0x152` / 338 bytes (Verified with int_convert.py) and `sub_538100` at `0x00538100` size `0x1f8` / 504 bytes (Verified with int_convert.py).
- 2026-06-14 `analyze_component` on `0x0053aec0` and `0x00538100` found a single internal edge, `0x00538100 -> 0x0053aec0`, with `sub_53AEC0` internal-only, zero ordinary callees, 29 basic blocks, and cyclomatic complexity 19. This supports the quarantine decision: the helper is real cleanup logic, but it is not evidence for an original `AttachedObjectPaneHelper_53AEC0.cpp` source root.
- 2026-06-14 `xrefs_to 0x0053aec0` returned exactly one code xref, `0x005382b0` inside `sub_538100`; no peer callers or constructor/setup users were found in the live xref query.
- The supporting [UID:0001TR][AttachedObjectRegistryLayout](by-type/by-struct/AttachedObjectRegistryLayout.md) now records the same live offset evidence for `AttachedObjectPane + 0x128` / 296, registry list offsets `+0x170` / 368 and `+0x174` / 372, singleton offsets `+0x1d8` / 472, `+0x1dc` / 476, `+0x1e0` / 480, and `+0x1e4` / 484 (Verified with int_convert.py). B001 later resolved the registry constructor/setup owner to [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md); that strengthens this page's quarantine state because the exact body belongs to an existing owner rather than a real standalone helper file.
- 2026-05-25 IDA MCP recheck: the helper still appeared in historical generated output as standalone `AttachedObjectPaneHelper_53AEC0::DetachAttachedObject` and carried the misleading `g_attachmentModeFlag` alias for canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97`.
- 2026-05-26 IDA MCP recheck: the helper remains a one-method split candidate, and IDA caller/xref evidence is unchanged.
- IDA MCP `lookup_funcs` confirms `sub_53AEC0` at `0x0053aec0` with size `0x152`.
- IDA MCP `callers` and `xrefs_to` report a single code caller at `0x005382b0` inside `sub_538100`, the `AttachedObjectPane` non-deleting destructor.
- IDA decompilation of `0x00538100` shows the call shape `sub_53AEC0(*(this + 0x128), this)`.
- IDA decompilation of `0x0053aec0` confirms registry offsets `+0x170`, `+0x174`, `+0x1d8`, `+0x1dc`, `+0x1e0`, and `+0x1e4`.
- The helper reads the attached object's type byte at `attachedObject + 0xf8`.
- The helper removes type `2` and type `4` objects from registry lists and clears type `6`, `7`, `8`, and `9` singleton slots. Type `8` clears only when [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` is `1`.
- IDA MCP `py_eval` on 2026-05-26 reconfirmed 366 xrefs to [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97`, so the recovered alias remains a broad UI/render mode byte rather than attachment-specific state.

## Non-Standalone File State

- `PROPOSED_RECONSTRUCTION_PATH:"NONE"` and `CANONICAL_OWNER:NONE` are intentional. This page is a quarantine record for a rejected generated file split, not a source root or ownership container.
- The only represented implementation is [UID:0001DF][0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane](by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md), already owned/emitted by [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md).
- Keep this page ignored/non-standalone and non-emitting. There is no class, external interface, helper-local state, missing source body, or header obligation that could justify target CPP/H.

## Score Rationale

- Completion is `94` because the page now closes the complete pseudo-file inventory, exact method/caller behavior, typed receiver and fields, owner/source placement, code/data boundaries, compiler-table exclusions, rejected alternatives, generated-source completeness, and target-specific no-code/no-header disposition.
- Confidence is `95` because live IDA, raw PE, accepted UDT/source documentation, and generated output independently agree on the LivingObjectPane route and reject the pseudo-file identity. The remaining cap reflects unavailable original debug symbols and source-control history, not unresolved method/field/type names.

## Cross-References

- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md)
- [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md)
- [UID:00000N][AttachedObjectPaneHelper_53AEC0](by-class/AttachedObjectPaneHelper_53AEC0.md)
- [UID:0001DF][0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane](by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md)
- [UID:0001TR][AttachedObjectRegistryLayout](by-type/by-struct/AttachedObjectRegistryLayout.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)

## Changes

- 2026-08-14 B003 UID0000HK whole-file implementation callback:
  - Raised scores from `85/89` to `94/95` while preserving `PROPOSED_RECONSTRUCTION_PATH:"NONE"` and `CANONICAL_OWNER:NONE`.
  - Added the complete zero-item pseudo-file inventory, exact UID0001DF range and dispatch behavior, sole destructor caller, typed owner-pointer route, adjacent LivingObjectPane lifecycle family, exact padding/NOP/jump-table boundaries, generated-source readback, and explicit no-code/no-header proof.
  - Resolved the previously active method/field/type-name blocker to the accepted source-facing `LivingObjectPane::UnregisterAttachedObjectPane`, typed registry fields, public object-type names, and `g_useEpfAssets`. Older raw/generated names and the former AttachedObjectPane placement remain below as dated superseded provenance.

- 2026-06-16 B001 source-shape execution:
  - Scores unchanged at `85/89`, with `PROPOSED_RECONSTRUCTION_PATH:"NONE"` and `CANONICAL_OWNER:NONE` retained.
  - Changed the disposition from an `AttachedObjectPane.cpp` private-helper hypothesis to a rejected generated file split whose exact helper body is now routed to [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md).
  - Evidence: B001 live IDA and raw PE checks reconfirmed the sole destructor call, zero hidden pointer encodings, LivingObjectPane field initialization and cleanup/replacement methods, and compiler switch-table support for the method body.

- 2026-06-14 A002 Goal2 by-file refresh:
  - Before: `COMPLETION:80`, `CONFIDENCE:88`; the page relied on older single-caller notes and did not reflect the newer registry-layout support page.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:89`, with fresh live IDA component/xref evidence and explicit score rationale.
  - Evidence: `server_health`, `lookup_funcs`, `analyze_component`, `xrefs_to`, and `int_convert` in IDA MCP session `a001_goal2_class_batch` reconfirmed the `0x0053aec0` helper, sole destructor edge from `0x005382b0`, no peer callers, the `0x152` / 338-byte size, the `0x1f8` / 504-byte destructor size, and the registry-offset evidence already carried by [UID:0001TR][AttachedObjectRegistryLayout](by-type/by-struct/AttachedObjectRegistryLayout.md).
- 2026-06-07 A008 alias cleanup:
  - Before: the ownership table and evidence notes still foregrounded the misleading generated `g_attachmentModeFlag` name and bare `byte_66DA97` alias.
  - Changed to: canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) wording while preserving `byte_66DA97` as the IDA lookup alias.
  - Evidence: the documented 366-xref global usage remains broad UI/render mode state, not attachment-specific state.
- 2026-06-06 non-standalone coverage cleanup:
  - Before: the page had `NONE` path and rejected standalone ownership but still scored `74/88`, and the manual file-coverage row still listed it as reconstructable.
  - Changed to: `80/88`, explicit non-standalone file state, exact memory helper ownership, and historical generated-label wording.
  - Evidence at that time: single caller from `AttachedObjectPane::~AttachedObjectPane`, exact helper page [UID:0001DF][0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane](by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md), and then-current source root [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md). B001's 2026-06-16 source-shape pass supersedes that route for the exact helper body and assigns it to [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md), while this file page remains an ignored/quarantine split.
- 2026-06-05: Marked the projected reconstruction path as `NONE`.
  - Before: the path was blank, which left this reviewed helper quarantine in file-coverage error state.
  - After: the page is explicitly classified as a non-standalone by-file page; no `AttachedObjectPaneHelper_53AEC0.cpp` should be emitted.
  - Evidence: live IDA MCP `lookup_funcs` confirms `sub_53AEC0` at `0x0053aec0` (`0x152` bytes), and `callers` again reports the single direct caller at `0x005382b0` inside `sub_538100`, matching the documented `AttachedObjectPane` destructor ownership.
- What existed before: the page quarantined the recovered helper split but had unevaluated scores.
- What it was changed to: scores were set to `74/88`.
- Summary and evidence: the code behavior and non-standalone ownership decision are strongly supported by IDA caller/xref evidence; completion is lower because this should likely be folded into `AttachedObjectPane.cpp` after migration.
- 2026-06-06: Replaced stale recovered-source provenance wording without changing score or path.
  - Before: status, file role, ownership evidence, and scoring notes described the quarantine in terms of stale recovered-source ownership.
  - After: kept `74/88` and `PROPOSED_RECONSTRUCTION_PATH:"NONE"`, but framed the page as a recovered one-method split rejected by IDA caller/xref evidence.
  - Evidence: `0x0053aec0` still has a single direct caller from `AttachedObjectPane::~AttachedObjectPane`, the registry offsets are documented by IDA decompilation, and the broad [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97` xref set keeps the mode byte out of attachment-specific ownership.
