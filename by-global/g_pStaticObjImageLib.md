*** UID:0000SD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000O7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000O7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
StaticObjImageLib *g_pStaticObjImageLib = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pStaticObjImageLib

## Status

- Confidence: near-certain for storage address, source owner, direct Singleton lifecycle, zero definition, and the complete consumer set; the exact original identifier spelling remains inferred.
- Backing storage: [UID:0001PP][0x0069b448-0x0069b44c.g_pStaticObjImageLib](by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md), IDA `dword_69B448` / current MCP `unk_69B448`.
- Owner file: [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md).
- Alias decision: `g_pStaticObjImageLib` is the preferred canonical documentation name. `dword_69B448` is the live IDA auto-name; alias candidates such as `g_pStaticObjectManager` should be treated as aliases unless later source-level evidence proves otherwise.

## Role

`g_pStaticObjImageLib` is the process-wide pointer to the static map-object image library. Map object creation, static-object pane rendering, and photo composition read this pointer before resolving `SOBJ.TBL` object records into layered `TILEC` frame draws.

## IDA Xref Summary

Live IDA MCP on 2026-05-30 reports `0x0069b448` as a 4-byte `.data` item named `dword_69B448` with 13 data xrefs.

| Site | Role |
| --- | --- |
| `0x004dcfa3` / `0x004dcfaa` | Direct `Singleton<StaticObjImageLib>` construction publishes the complete object or restores null on the guard/fallback path in [UID:00017H][0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster](by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md). |
| `0x004dd29b` | Reverse implicit Singleton base destruction clears the slot after [UID:00017I][0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor](by-memory/0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor.md). |
| `0x004e5c00` | [UID:000184][0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor](by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonBaseDestructor.md) clears the slot during constructor state-1 unwind. |
| `0x004e6a5e` | The compiler scalar deleting destructor inlines the same reverse Singleton base clear. |
| `0x004f65e2` | `Application::Shutdown` reads the singleton for teardown. |
| `0x0050f064` / `0x0050f0b0` | Map/object creation code reads the singleton for bounds and setup. |
| `0x00530d30` | [UID:00023D][0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper](by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md) reads the singleton before resolving the requested `StaticObjEntry`. |
| `0x00537960` / `0x0053797a` / `0x005379ad` | [UID:0000O6][StaticObjectPane](by-file/StaticObjectPane.md) reads the singleton. |
| `0x0054977d` | [UID:0000MK][PhotoPane](by-file/PhotoPane.md) reads the singleton during map-photo composition. |

## Source Definition And Storage Split

This page emits the source-facing singleton definition:

```cpp
StaticObjImageLib *g_pStaticObjImageLib = 0;
```

[UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md) keeps only the class declaration-level `extern StaticObjImageLib *g_pStaticObjImageLib;`. [UID:0001PP][0x0069b448-0x0069b44c.g_pStaticObjImageLib](by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md) is exact storage support and must not emit a duplicate definition.

The UID00023D ObjectList consumer uses this same source definition, not a second map-owned global. At `0x00530d30` it reads the singleton, calls `StaticObjImageLib::GetStaticObjectEntry(unsigned short)`, and dispatches the signed `lightImageIndex` remove/update/create policy. This reinforces the existing `StaticObjImageLib.cpp` ownership while leaving MapPane, ObjectList, and StaticObjectPane as consumers.

B010's 2026-07-01 implementation callback corrected the prior stale sentinel assumption. Current storage evidence reports `0x0`, bytes `00 00 00 00`, and zeroed neighboring image-library singleton slots at `0x0069b440-0x0069b457`. UID000184 resolves the source cause: direct `Singleton<StaticObjImageLib>` construction publishes the complete object, constructor state-1 unwind calls its out-of-line base destructor, and ordinary/scalar destruction inline the same reverse base clear.

## Direct Singleton Lifecycle

- [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md) directly inherits `Singleton<StaticObjImageLib>` after `LObject`. The complete H declaration owns the one `extern StaticObjImageLib *g_pStaticObjImageLib;` contract.
- The Singleton base is empty and overlaps the derived `tileCatalog` address at `+0x04` under EBO. Its constructor still receives the complete-object relationship and publishes the derived pointer to this slot.
- Constructor EH state 1 adjusts ECX to complete `this + 4` and tail-jumps to UID000184. The ordinary and scalar destructors inline the same clear before `LObject` teardown. These are compiler-generated base-lifetime operations, not separate source definitions or helper APIs.
- Application startup explicitly constructs StaticObjImageLib and shutdown reads/deletes the singleton. No `atexit`, `_onexit`, pointer-table, or static-registration route owns this global.

## Assignment Decision

`AUTOGEN_PARENT_UID` remains [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md). This global scores `92/96`, the direct file parent scores `90/94`, and the exact storage child scores `93/97`. The relationship is source-specific: this page emits the sole definition, the class H emits the sole declaration, and the storage child is non-emitting physical evidence.

## Score Rationale

- Completion `92`: exact storage, preferred alias, direct Singleton publication/unwind/ordinary/scalar lifecycle, complete thirteen-ref table, startup/shutdown behavior, consumer-owner split, exact storage child, zero initializer, declaration/definition split, and formal source definition are documented.
- Confidence `96`: xrefs, bytes, class hierarchy, RTTI/PMD/EBO, constructor EH state, ordinary/scalar destruction, exact storage child, and source owner all agree. Confidence stays below final-audit certainty only because original source spelling is not symbol-proven.

## Ownership

`g_pStaticObjImageLib` is source-owned by `StaticObjImageLib`, not by `MapPane`, `StaticObjectPane`, or `PhotoPane`. Those classes are consumers.

## Historical Superseded Assumptions

- Earlier documentation described constructor, ordinary, helper, and scalar writes as generic source-owned clear routines. The reference addresses remain exact; UID000184 supersedes their source explanation with direct Singleton construction and compiler-generated reverse base destruction.
- Earlier storage notes reported a `0xffffffff` sentinel. Current bytes and the zero formal definition reject that initializer; the stale value is retained only as historical error context.

## Cross-References

- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md)
- [UID:00017H][0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster](by-memory/0x004dcf60-0x004ddf60.StaticObjImageLibLocalMethodCluster.md)
- [UID:0001PP][0x0069b448-0x0069b44c.g_pStaticObjImageLib](by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md)
- [UID:0001YX][StaticObjImageLibVtable](by-type/by-vtable/StaticObjImageLibVtable.md)
- [UID:0001W9][StaticObjImageLibLayout](by-type/by-struct/StaticObjImageLibLayout.md)

## Changes

- 2026-08-11 B003 UID00023D support synchronization: preserved later valid `92/96` metadata, owner/emitter `0000O7`, reconstructable true, blank position, the single nonblank CPP definition, and blank H. Replaced the generic `0x00530d30` entry with the exact ObjectList target consumer and documented the source/storage split; no duplicate definition or IDA reshape was introduced. The accepted report's earlier `88/91` snapshot was not restored over B005's later lifecycle implementation.
- 2026-08-11 B005 UID000184 lifecycle implementation: raised `88/91` to `92/96`, preserved owner/emitter UID0000O7 and the exact zero CPP definition, retained all thirteen refs, and documented direct Singleton publication, constructor-unwind clearing, implicit ordinary/scalar clearing, declaration/definition/storage separation, and rejected generic-helper/sentinel assumptions.

- 2026-06-05: Marked reconstructable and attached to [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) to resolve the global unclassified coverage row.
  - Reasoning: live IDA xrefs bind the singleton to `StaticObjImageLib` constructor/destructor writes plus shutdown and static-object/photo consumers, while the proposed source tree places the owner under `render/StaticObjImageLib.cpp`. No score change and no reconstruction C++ were added.
- What existed before: this page had a correct xref table but unevaluated completion/confidence metadata and a source-tool status line as part of the alias decision.
- What changed to: the page now uses live IDA MCP as the evidence source, includes the full 13-xref set including `0x00530d30`, and scopes alias candidates as aliases only. Completion/confidence were set to `80/88`.
- Summary and evidence: IDA MCP on 2026-05-30 verified `0x0069b448` / `dword_69B448` as a 4-byte `.data` singleton pointer with constructor assignment/fallback at `0x004dcfa3`/`0x004dcfaa`, destructor/clear helpers at `0x004dd29b`, `0x004e5c00`, and `0x004e6a5e`, shutdown read at `0x004f65e2`, map/static-object consumers at `0x0050f064`, `0x0050f0b0`, `0x00530d30`, `0x00537960`, `0x0053797a`, and `0x005379ad`, and photo composition read at `0x0054977d`.
- 2026-06-10 A001 strict gate repair:
  - Changed completion from `80` to `86`.
  - Summary/evidence: the direct StaticObjImageLib file parent scores `86/85`, and the exact storage child [UID:0001PP][0x0069b448-0x0069b44c.g_pStaticObjImageLib](by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md) scores `86/90`. The page already carried the complete 13-xref table, constructor publish/null clear, ordinary/helper/scalar destructor clears, shutdown read, static-object/map/photo consumer split, and alias decision; the new rationale documents why the strict child/direct-parent gate clears while keeping C++ blank below the 95/95 source-code threshold.
- 2026-07-01 B010 StaticObjImageLib empty-emitter family implementation:
  - Raised from `86/88` to `88/91` and populated the formal source definition.
  - Summary/evidence: B010 live MCP session `supervisor_resume_20260629` reconfirmed 13 singleton xrefs and corrected the stale initializer claim. Current `get_global_value 0x0069b448` is `0x0`; `get_bytes 0x0069b448` is `00 00 00 00`; neighboring singleton slots at `0x0069b440-0x0069b457` are also zero. This page now emits `StaticObjImageLib *g_pStaticObjImageLib = 0;`, while [UID:0001PP][0x0069b448-0x0069b44c.g_pStaticObjImageLib](by-memory/0x0069b448-0x0069b44c.g_pStaticObjImageLib.md) records exact storage support.
