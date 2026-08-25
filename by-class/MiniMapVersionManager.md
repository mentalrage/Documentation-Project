*** UID:00008H | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_MAP_MINIMAPVERSIONMANAGER_H
#define NEXUSTK_MAP_MINIMAPVERSIONMANAGER_H

#include <hash_map>

#include "../util/Singleton.h"

class MiniMapVersionManager : public Singleton<MiniMapVersionManager>
{
public:
    MiniMapVersionManager();
    virtual ~MiniMapVersionManager();

    void LoadHashFile();
    void ClearHashList();
    void UpdateHashList(const wchar_t *versionString,
                        wchar_t *hashListText,
                        bool saveCache);
    const wchar_t *GetVersionString() const;
    const wchar_t *GetExpectedVersionForMapId(int mapId) const;

private:
    typedef stdext::hash_map<int, wchar_t *> VersionIndex;

    wchar_t m_currentVersion[33];
    VersionIndex m_versionIndex;
};

extern MiniMapVersionManager *g_pMiniMapVersionManager;

typedef char MiniMapVersionManagerSizeMustBe0x68[
    sizeof(MiniMapVersionManager) == 0x68 ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MiniMapVersionManager

## 2026-08-17 Typed Version-Index Source Correction

`m_versionIndex` is source-facing `stdext::hash_map<int, wchar_t *>`, not a project-authored `DATIndexVector`. The observed `0x20` subobject and the folded FNV/list/bucket helper family match the contemporary MSVC/Dinkumware container implementation. Map ids are the four-byte keys and each mapped value is the owned wide version string returned by `GetExpectedVersionForMapId` and released by `ClearHashList`.

The formal header now includes `<hash_map>`, defines private `VersionIndex`, and stores `VersionIndex m_versionIndex` while preserving the exact `0x68` class-size guard. Compiler-emitted bucket initialization, insertion, lookup, unwind, and destruction remain binary evidence on their exact pages; they are not authored calls or members in this human source declaration. Older `DATIndexVector`, explicit sentinel/node, `ResizeAndFill`, and custom-destruction statements below are historical recovery assumptions superseded by this typed standard-container contract.

## Status

- Confidence: very strong for class responsibility, RTTI identity/inheritance, exact size and major members, singleton lifecycle, version/hash workflow, and focused map-module placement
- Likely source module: [UID:0000LF][MiniMapVersionManager](by-file/MiniMapVersionManager.md), under the broader [UID:0000LE][MiniMap](by-file/MiniMap.md) subsystem
- Current range: `0x004563c0-0x00457547`
- Evidence basis: live IDA MCP function-boundary, caller, xref, and byte checks plus the current by-memory/by-file MiniMapVersionManager documentation.
- Singleton storage: [UID:0000RP][g_pMiniMapVersionManager](by-global/g_pMiniMapVersionManager.md) at [UID:0001OZ][0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager](by-memory/0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager.md)
- Parent gate: this class clears `91/93`, directly owns its exact method pages, and emits the accepted first-draft class/header declaration at position `10`. [UID:0001V8][MiniMapVersionNode](by-type/by-struct/MiniMapVersionNode.md) remains semantically class-owned but emits at file scope before this declaration.

## Responsibility

`MiniMapVersionManager` owns the minimap hash/version list used by startup update checks and local minimap cache validation. It initializes during process startup, stores the current minimap hash version string, loads persisted hash data, merges downloaded hash-list text, and rewrites the local hash cache when requested.

## Inheritance And RTTI

- RTTI complete-object locator `0x00641a30` and hierarchy `0x00641a44` contain exactly two class descriptors: `MiniMapVersionManager` and `Singleton<MiniMapVersionManager>`.
- The Singleton base descriptor at `0x00641a7c` has PMD `mdisp=4`, `pdisp=-1`, `vdisp=0`. This is direct, non-virtual inheritance with the empty base address at `+0x04`.
- Constructor lowering computes the `this + 4` base address, performs adjusted-null handling, subtracts four, and publishes the complete object to [UID:0000RP][g_pMiniMapVersionManager](by-global/g_pMiniMapVersionManager.md). The global therefore stores `MiniMapVersionManager *`, not a Singleton-base pointer.
- Vtable `0x006108d4` contains the scalar deleting destructor entry at `0x00457480`. The class declares a virtual destructor; the scalar wrapper, RTTI, vtable, adjusted-null publication, and EH clear helper remain compiler/template manifestations rather than handwritten source members.

## Exact First-Draft Layout

| Offset | Size | Source member / role | Evidence |
| --- | ---: | --- | --- |
| `+0x00` | `0x04` | vptr | Constructor writes class vtable; RTTI/vtable links scalar deleting destructor. |
| `+0x04` | empty base address | `Singleton<MiniMapVersionManager>` | RTTI PMD `+4`; empty-base optimization overlaps the first member address. |
| `+0x04` | `0x42` | `wchar_t m_currentVersion[33]` | `UpdateHashList` copies with `_wcscpy_s(..., 0x21, ...)`; `GetVersionString` returns `this+4`. |
| `+0x46` | `0x02` | natural alignment padding | Required to align the following four-byte subobject at `+0x48`; no explicit source field. |
| `+0x48` | `0x20` | `VersionIndex m_versionIndex` (`stdext::hash_map<int, wchar_t *>`) | Constructor, lookup, insertion, clear, and destructor lowering all operate on the exact standard-container subobject. |

- WinMain pushes `0x68` to `operator new` before the sole constructor call, proving the complete-object size is 104 bytes.
- No explicit source member is emitted for empty-base overlap, natural padding, private list nodes, node count, or bucket storage. The observed roles at `+0x4c` onward are private old-MSVC/Dinkumware `stdext::hash_map` representation inside `m_versionIndex`, not project-authored members.
- [UID:0001V8][MiniMapVersionNode](by-type/by-struct/MiniMapVersionNode.md) is a separate 16-byte file-scope support struct. It must precede this class in the header and must not be nested or duplicated by `[[CHILDREN]]` expansion.

## Header And Global Contract

- Focused [UID:0000LF][MiniMapVersionManager](by-file/MiniMapVersionManager.md) routes this declaration to `NexusTK/map/MiniMapVersionManager.h` and class methods/global storage to the companion `.cpp`.
- The class page emits `extern MiniMapVersionManager *g_pMiniMapVersionManager;`; semantic [UID:0000RP][g_pMiniMapVersionManager](by-global/g_pMiniMapVersionManager.md) emits the sole zero-initialized definition.
- Physical [UID:0001OZ][0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager](by-memory/0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager.md) emits only a no-duplicate marker. StartupWindow, MiniMapRenderer, Application, and WinMain consume the class but do not own its declaration or definition.
- The declaration is first-draft human source: no `sub_*`, `dword_*`, address-derived fields, explicit vptr, synthetic padding field, EH helper, or scalar deleting-destructor method appears in it.

## Methods

| Address | Provisional source name | Summary |
| --- | --- | --- |
| [0x004563c0-0x0045647d.MiniMapVersionManagerConstructor](by-memory/0x004563c0-0x0045647d.MiniMapVersionManagerConstructor.md) | constructor | Publishes/guard-clears the singleton, installs the vtable, and default-constructs the `VersionIndex` standard-container member. Sentinel creation, max-load initialization, and eight-bucket setup are compiler/private-library lowering rather than authored `DATIndexVector` calls. |
| [0x00456480-0x00456532.MiniMapVersionManagerDestructor](by-memory/0x00456480-0x00456532.MiniMapVersionManagerDestructor.md) | destructor | Releases owned version strings, lets the `VersionIndex` member destroy its private nodes/buckets, clears the singleton, and remains blank/no-code because the observed container teardown is compiler/private-library lowering rather than an explicit custom-member API. |
| [0x00456540-0x004566fe.MiniMapVersionManagerLoadHashFile](by-memory/0x00456540-0x004566fe.MiniMapVersionManagerLoadHashFile.md) | `LoadHashFile` | Loads persisted `mnmhs.hs` cache data from app data and forwards decoded version/list text into `UpdateHashList(..., false)`. |
| [0x00456700-0x00456791.MiniMapVersionManagerClearHashList](by-memory/0x00456700-0x00456791.MiniMapVersionManagerClearHashList.md) | `ClearHashList` | Clears payload strings, nodes, sentinel/count, and embedded index buckets before reinitializing the version hash list; current B003 evidence supports first-draft `void MiniMapVersionManager::ClearHashList()` C++ with `delete []`/`delete` as inferred source operations over observed CRT/list-helper lowering. |
| [0x004567a0-0x0045695e.MiniMapVersionManagerRawCacheLoadReplay](by-memory/0x004567a0-0x0045695e.MiniMapVersionManagerRawCacheLoadReplay.md) | retained-raw cache-load replay body | Source-shaped `mnmhs.hs` replay body with raw `0x00456939` `UpdateHashList(..., false)` call; not an IDA function and zero start xrefs, so documentation-only/no-code. |
| [0x00456960-0x00456a8e.MiniMapVersionManagerRawCacheSaveBody](by-memory/0x00456960-0x00456a8e.MiniMapVersionManagerRawCacheSaveBody.md) | retained-raw cache-save body | Source-shaped file writer with `retn 8`; not an IDA function and zero start xrefs, so documentation-only/no-code. |
| [UID:0002JL][0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList](by-memory/0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList.md) | `void UpdateHashList(const wchar_t* versionString, wchar_t* hashListText, bool saveCache)` | Updates the current hash version, optionally rewrites `mnmhs.hs`, and merges slash-delimited map-id/version entries into the owned cache. |
| [UID:0002JM][0x004570a0-0x004570a4.MiniMapVersionManagerGetVersionString](by-memory/0x004570a0-0x004570a4.MiniMapVersionManagerGetVersionString.md) | `const wchar_t* GetVersionString() const` | Returns `m_currentVersion`, the manager-owned wide string buffer storing the current minimap hash-list version. |
| [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md) | `const wchar_t* GetExpectedVersionForMapId(int mapId) const` | Looks up a map id in `m_versionIndex` and returns the stored expected `.mnm` header/version string. |
| [0x004573c0-0x004573cb.MiniMapVersionManagerClearSingletonHelper](by-memory/0x004573c0-0x004573cb.MiniMapVersionManagerClearSingletonHelper.md) | singleton clear helper | Clears the global manager pointer. |
| [0x00457480-0x00457547.MiniMapVersionManagerScalarDeletingDestructor](by-memory/0x00457480-0x00457547.MiniMapVersionManagerScalarDeletingDestructor.md) | scalar deleting destructor | Compiler-generated wrapper that invokes destructor and conditionally frees the object; non-reconstructable/no-code. |

## Class-Owned Read-Only Data

| Range | Role | Evidence |
| --- | --- | --- |
| [UID:0003FQ][0x006108d4-0x00610980.MiniMapVersionManagerReadOnlyData](by-memory/0x006108d4-0x00610980.MiniMapVersionManagerReadOnlyData.md) | Vtable, minimap cache path formats, delimiter data, and version/hash marker strings | Batch 254 live IDA MCP xrefs tie the vtable base `0x006108d4` to the constructor/destructor/scalar-deleting-destructor paths, and tie the cache path strings to cache load/save/update code in the class memory aggregate. |

## IDA MCP Evidence

- 2026-06-06 `lookup_funcs` confirms:
  - `0x004563c0` size `0xbd`
  - `0x00456480` size `0xb2`
  - `0x00456540` size `0x1be`
  - `0x00456a90` size `0x60e`
  - `0x004570a0` size `0x4`
  - `0x004570b0` size `0x30`
  - `0x004573c0` size `0x0b`
  - `0x00457480` size `0xc7`
- `xrefs_to 0x0067a7dc` confirms 12 direct singleton-slot refs: renderer version-check readers at `0x00454336` and `0x00454da0`, constructor publish/guard-clear refs at `0x004563f7` and `0x004563fe`, teardown clears at `0x00456516`, `0x004573c0`, and `0x0045751a`, Application cleanup/request-exit refs at `0x00464c89` and `0x00464e8c`, startup at `0x004f5d09`, and update-check refs at `0x00580e99` and `0x00580fc5`.
- `get_bytes 0x0067a7dc` confirms the singleton-adjacent 16-byte span is zero-initialized in the loaded image.
- Existing caller evidence confirms:
  - `0x004563c0` is called from `_WinMain@16` at `0x004f5d04`.
  - `0x004570a0` is called from `StartupWindow__RunUpdateCheck` at `0x00580ea3`.
- 2026-05-25 `callers` confirms `0x004570b0` is used by `MiniMapRenderer::PrepareMapFileAndCheckVersion` and `MiniMapRenderer::HasCurrentVersion`.
- IDA decompilation identifies the singleton storage at `0x0067a7dc`; `xrefs_to 0x0067a7dc` ties it to the manager lifetime helpers, startup, update-check code, and renderer version checks.
- `callees` for `0x004563c0` include internal helpers at `0x00457550` and `0x00423b00`, consistent with storage/list initialization.
- 2026-07-09 B001 current MCP session `supervisor_nexustk_20260709` rechecked [UID:0004D8][0x004563c0-0x0045647d.MiniMapVersionManagerConstructor](by-memory/0x004563c0-0x0045647d.MiniMapVersionManagerConstructor.md): `idb_list`/`server_health` were healthy for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `func_profile` confirmed size `0xbd` and one caller, `xrefs_to` confirmed sole `_WinMain@16 + 0x284` construction caller, singleton writes at `0x004563f7/0x004563fe`, vtable write at `0x0045640b`, and helper calls to `StdListBuyNode8` / `DATIndexVector::ResizeAndFill`.
- 2026-07-09 B003 current MCP session `supervisor_nexustk_20260709` rechecked destructor [0x00456480-0x00456532.MiniMapVersionManagerDestructor](by-memory/0x00456480-0x00456532.MiniMapVersionManagerDestructor.md): `server_health` was healthy for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `sub_456480` size was `0xb2`, padding `0x00456532-0x00456540` separated it from `LoadHashFile`, `xrefs_to` found no direct code callers to the non-scalar destructor, and `analyze_function` tied the cleanup to vtable restore, expected-version string frees, list sentinel/count reset, node frees, `DATIndexVector::ResizeAndFill(8)`, `DATIndexVector::~DATIndexVector`, and singleton clear.
- 2026-07-09 B003 current MCP session `supervisor_nexustk_20260709` rechecked [UID:0004DB][0x00456700-0x00456791.MiniMapVersionManagerClearHashList](by-memory/0x00456700-0x00456791.MiniMapVersionManagerClearHashList.md): `server_health` was healthy for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `sub_456700` size was `0x91`, `xrefs_to`/caller checks found no direct entry callers, payload frees occurred at `0x456730-0x456733`, sentinel/count reset at `0x456741-0x456755`, old-node frees at `0x45675c-0x456773`, and `DATIndexVector::ResizeAndFill(8)` at `0x456775-0x45677a`; byte evidence confirmed return at `0x00456790`, end-exclusive `0x00456791`, and `0xcc` padding through `0x0045679f` before the retained-raw cache-load replay bytes.
- 2026-05-24 IDA MCP caller checks show `0x00456a90` calls [UID:0000XS][0x00457100-0x0045730f.DATIndexVectorInsertNode](by-memory/0x00457100-0x0045730f.DATIndexVectorInsertNode.md), and construction/teardown paths call `DATIndexVector` storage helpers.
- 2026-05-25 IDA MCP checks place `0x00457550`, `0x004570e0`, and `0x00457430` in the shared [UID:0000KR][LinkedList](by-file/LinkedList.md) helper family rather than minimap-owned source.
- 2026-07-02 B004 retained-raw pass keeps `0x004567a0` and `0x00456960` under the class aggregate only as documentation children: both are source-shaped cache bodies, but neither is an IDA function start and `xrefs_to` reports zero start xrefs. The raw `0x004567a0-0x0045695e` replay body reaches `UpdateHashList(..., false)` at `0x00456939`; the raw `0x00456960-0x00456a8e` body writes the cache file and returns with `retn 8`.

## Ownership Notes

- This class belongs with minimap code rather than generic startup code. Startup constructs/uses it, but the owned data is minimap hash/version state.
- `StartupWindow::RunUpdateCheck` depends on the current version string, so `StartupWindow` should include/use the minimap version manager rather than owning the manager implementation.
- The persisted hash path and format are represented by exact child pages for modeled `LoadHashFile`, retained-raw cache-load replay, retained-raw cache-save body, and `UpdateHashList`; only final original source grouping remains open.
- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) is a binary-family documentation index, not a source dependency. The source dependency is the standard `<hash_map>` header and `stdext::hash_map<int, wchar_t *>`.
- `LinkedList` is a lower-level utility dependency for sentinel nodes and two-word payload nodes, not minimap-specific code.
- The constructor's [UID:0000XW][0x00457550-0x0045757d.StdListBuyNode8](by-memory/0x00457550-0x0045757d.StdListBuyNode8.md) and [UID:0000WW][0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill](by-memory/0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill.md) calls are non-emitting MSVC/Dinkumware standard-container construction lowering; neither is an authored MiniMapVersionManager or DATIndexVector source call.
- `ClearHashList` is class-owned despite no direct entry xrefs because its whole body operates on the class-owned version list/index fields. The formal first-draft body lives on [UID:0004DB][0x00456700-0x00456791.MiniMapVersionManagerClearHashList](by-memory/0x00456700-0x00456791.MiniMapVersionManagerClearHashList.md); its `delete []` and `delete` spellings remain inferred source-facing operations over CRT/list-helper lowering.
- The destructor's cleanup body is class-owned evidence, but its current C++ remains blank/no-code: the project-generated `MiniMapVersionManager.cpp` contains the UID0004D9 empty marker, `0x00457480` is the scalar deleting destructor wrapper/deallocation peer, and [UID:0000XU][0x004573d0-0x00457429.DATIndexVectorDestructor](by-memory/0x004573d0-0x00457429.DATIndexVectorDestructor.md) plus [UID:0000XV][0x00457430-0x00457473.StdListTidy8ByteList](by-memory/0x00457430-0x00457473.StdListTidy8ByteList.md) remain support dependencies rather than manager-emitted source.
- Shared helpers in the physical aggregate, including [UID:0000XR][0x004570e0-0x00457100.StdListBuyNodeWithPayload8](by-memory/0x004570e0-0x00457100.StdListBuyNodeWithPayload8.md), [UID:0000XS][0x00457100-0x0045730f.DATIndexVectorInsertNode](by-memory/0x00457100-0x0045730f.DATIndexVectorInsertNode.md), [UID:0000XT][0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper](by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md), [UID:0000XU][0x004573d0-0x00457429.DATIndexVectorDestructor](by-memory/0x004573d0-0x00457429.DATIndexVectorDestructor.md), and [UID:0000XV][0x00457430-0x00457473.StdListTidy8ByteList](by-memory/0x00457430-0x00457473.StdListTidy8ByteList.md), remain rejected from MiniMapVersionManager ownership.
- [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md) remains the focused method evidence page for map-id lookup semantics.
- The class-owned list/index tail is now sufficiently documented for child type ownership: `UpdateHashList` writes the node payload, manager `+0x48` is the embedded index, `+0x4c` is the list sentinel used by lookup miss handling, `+0x50` is incremented on insertion, and the destructor frees each node's `+0x0c` text pointer before list cleanup.

## Field Direction

| Offset | Preferred source name | Evidence |
| --- | --- | --- |
| `+0x04` | `m_currentVersion[0x21]` | [UID:0002JL][0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList](by-memory/0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList.md) copies the incoming version string with `_wcscpy_s(..., 0x21, ...)`; [UID:0002JM][0x004570a0-0x004570a4.MiniMapVersionManagerGetVersionString](by-memory/0x004570a0-0x004570a4.MiniMapVersionManagerGetVersionString.md) returns this address; StartupWindow compares it through `__wcsicmp`. |
| `+0x48` | `m_versionIndex` | Complete `VersionIndex` standard-container subobject; update paths insert map-id/string pairs and lookup uses `VersionIndex::find`. |
| `+0x4c` | private container sentinel (binary only) | Old-MSVC/Dinkumware private representation used by insert/find/destruction lowering; no source member is declared. |
| `+0x50` | private container count (binary only) | Private standard-container state updated by insertion lowering; no source member is declared. |

Constructor recheck note: [UID:0004D8][0x004563c0-0x0045647d.MiniMapVersionManagerConstructor](by-memory/0x004563c0-0x0045647d.MiniMapVersionManagerConstructor.md) confirms the private old-MSVC/Dinkumware representation: `+0x48` subobject max-load state, `+0x4c` sentinel, `+0x50` count, `+0x54/+0x58/+0x5c` bucket storage, then compiler-emitted eight-bucket initialization. These are binary layout facts, not custom source members or calls.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 91 | The page covers RTTI-proven Singleton inheritance, exact `0x68` layout, complete typed `VersionIndex` header declaration, extern linkage, method/helper inventory, singleton lifetime, startup/update/render/Application consumers, persisted hash-list behavior, retained-raw cache-body caveats, compiler boundaries, standard-container ownership, and focused source placement. |
| Confidence | 93 | Current byte, RTTI/PMD, allocation, instruction, caller, xref, method, and member-use evidence strongly agrees. Original PDB spellings, exact access qualifiers, and literal historical header filename remain inferred, so the class stays below 95 without retaining reverse-engineering labels. |

## Open Questions

- Exact original private/public qualifiers, lexical member spellings, include spelling, and physical filename are not PDB-proven. The first-draft declaration uses the highest-probability project-consistent human names and focused route; this bounded uncertainty affects only the below-95 score.
- The historical `MiniMapVersionManager.cpp` versus broader `MiniMap.cpp` question is resolved for current reconstruction routing in favor of focused UID0000LF. Broader MiniMap remains an umbrella, not a competing emitter.
- The raw cache-load/cache-save bodies are closed as retained-raw/no-code child evidence. Promote them only if future evidence finds real entry xrefs or function-start identity.

## Historical Assumptions Superseded

- Earlier text said class C++ had to remain blank until the full declaration/source split and internal member-construction model were final. RTTI, exact allocation size, exact major-member layout, resolved method signatures, focused route, and accepted first-draft policy now make that statement obsolete.
- Earlier field-direction prose treated `+0x4c` and `+0x50` as possible direct class members. They remain valid observed storage roles but are now understood inside the `DATIndexVector` subobject beginning at `+0x48`; the old observations are preserved rather than discarded.
- Historical saved-IDA-name claims are not current-state proof. The accepted supervisor Gate 2B handoff separately addresses the currently raw analysis names and does not alter this source declaration.

## Cross-References

- [UID:0000LF][MiniMapVersionManager](by-file/MiniMapVersionManager.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [0x004563c0-0x0045647d.MiniMapVersionManagerConstructor](by-memory/0x004563c0-0x0045647d.MiniMapVersionManagerConstructor.md)
- [0x00456480-0x00456532.MiniMapVersionManagerDestructor](by-memory/0x00456480-0x00456532.MiniMapVersionManagerDestructor.md)
- [0x00456540-0x004566fe.MiniMapVersionManagerLoadHashFile](by-memory/0x00456540-0x004566fe.MiniMapVersionManagerLoadHashFile.md)
- [0x00456700-0x00456791.MiniMapVersionManagerClearHashList](by-memory/0x00456700-0x00456791.MiniMapVersionManagerClearHashList.md)
- [0x004567a0-0x0045695e.MiniMapVersionManagerRawCacheLoadReplay](by-memory/0x004567a0-0x0045695e.MiniMapVersionManagerRawCacheLoadReplay.md)
- [0x00456960-0x00456a8e.MiniMapVersionManagerRawCacheSaveBody](by-memory/0x00456960-0x00456a8e.MiniMapVersionManagerRawCacheSaveBody.md)
- [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md)
- [0x004573c0-0x004573cb.MiniMapVersionManagerClearSingletonHelper](by-memory/0x004573c0-0x004573cb.MiniMapVersionManagerClearSingletonHelper.md)
- [0x00457480-0x00457547.MiniMapVersionManagerScalarDeletingDestructor](by-memory/0x00457480-0x00457547.MiniMapVersionManagerScalarDeletingDestructor.md)
- [UID:0003FQ][0x006108d4-0x00610980.MiniMapVersionManagerReadOnlyData](by-memory/0x006108d4-0x00610980.MiniMapVersionManagerReadOnlyData.md)
- [UID:0001V8][MiniMapVersionNode](by-type/by-struct/MiniMapVersionNode.md)
- [UID:0000RP][g_pMiniMapVersionManager](by-global/g_pMiniMapVersionManager.md)
- [UID:0001OZ][0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager](by-memory/0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager.md)
- [UID:00003K][DATIndexVector](by-class/DATIndexVector.md)
- [UID:0000KR][LinkedList](by-file/LinkedList.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-08-17 B007 UID0000PA provider-header closure:
  - Moved the exact `0x68` Singleton-derived class, 33-wide-character current-version buffer, embedded `0x20` DATIndexVector member, methods, global extern, and size assertion into a complete guarded `MiniMapVersionManager.h`.
  - The H payload includes both `DATIndexVector.h` and `Singleton.h`, which are required complete provider dependencies. The CPP class fragment now emits only exact method/global children because [UID:0001V8][MiniMapVersionNode](by-type/by-struct/MiniMapVersionNode.md) already includes the header first at position `5`.
  - The file-local node remains private implementation support rather than a public nested or header type. WinMain constructs the manager and calls `LoadHashFile()` through this provider without absorbing manager ownership.

- 2026-07-23 B002 UID0001OZ accepted implementation callback:
  - Raised the class from `85/87` to `91/93`, set source position `10`, and installed the exact first-draft `Singleton<MiniMapVersionManager>` declaration, virtual destructor/API, exact major members, header `extern`, and child expansion.
  - Added RTTI hierarchy/PMD proof, exact `0x68` layout and EBO/padding treatment, complete-object publication, compiler-boundary rules, file-scope node ordering, one-definition contract, focused header/source route, score rationale, and bounded source-name caveats.
  - Historicalized the former blank-C++/source-split blocker and clarified that observed `+0x4c/+0x50` roles live inside the embedded DATIndexVector rather than pruning earlier evidence.

- 2026-05-27: Updated current class range from `0x004563c0-0x00457546` to `0x004563c0-0x00457547`. Evidence: IDA MCP reports the scalar deleting destructor ending at `0x00457547`; the previous range omitted the final return immediate byte.
- Completion/confidence score update: existed before as `0/0`; changed to `84/82`. Summary: the minimap hash/version manager has detailed singleton, startup, persisted hash cache, version lookup, dependency, method-boundary, caller, and ownership documentation, but final method names and exact original source split still remain open. Evidence: IDA lookup/caller confirmations, `g_pMiniMapVersionManager`, version lookup by map id, and `DATIndexVector`/`LinkedList` dependency notes.
- 2026-05-31: Marked `RECONSTRUCTABLE:TRUE` and replaced raw `UpdateHashList`/`GetVersionString` address rows with exact by-memory child references. Evidence: IDA MCP rechecked both methods and the exact child pages now carry the current behavior evidence.
- 2026-06-06:
  - Before: score `84/82`, blank parent, and stale provenance/raw singleton labels in the class evidence.
  - After: score `84/86`, parent [UID:0000LF][MiniMapVersionManager](by-file/MiniMapVersionManager.md), source-facing evidence basis, refreshed live singleton xrefs, and no final C++ under the 95/95 gate.
  - Why: current IDA MCP and the existing by-memory pages are sufficient for class/file ownership and parent attachment, while final method spellings and exact original source split still cap completion.
- 2026-06-11 Agent-A005 Batch 152:
  - Before: `84/86`, which left direct child type assignment under the strict `85/85` parent gate.
  - After: `85/87`; C++ still blank.
  - Why: live IDA MCP rechecked the node payload flow across `UpdateHashList`, [UID:0000XR][0x004570e0-0x00457100.StdListBuyNodeWithPayload8](by-memory/0x004570e0-0x00457100.StdListBuyNodeWithPayload8.md), lookup, and destructor cleanup, proving that [UID:0001V8][MiniMapVersionNode](by-type/by-struct/MiniMapVersionNode.md) is a class-owned support type. Final public names and original source split still cap the scores below final-audit range.
- 2026-06-12 A004 Batch 254:
  - Score unchanged at `85/87`.
  - Added class-owned read-only-data child [UID:0003FQ][0x006108d4-0x00610980.MiniMapVersionManagerReadOnlyData](by-memory/0x006108d4-0x00610980.MiniMapVersionManagerReadOnlyData.md) after live IDA confirmed the `0x006108d4` vtable/cache-string tail belongs directly to this class.
- 2026-06-17 B002 source-quality execution:
  - Score unchanged at `85/87`.
  - Updated method signatures, field direction, and ownership notes after B002 resolved the exact class-owned method route for [UID:0002JL][0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList](by-memory/0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList.md), [UID:0002JM][0x004570a0-0x004570a4.MiniMapVersionManagerGetVersionString](by-memory/0x004570a0-0x004570a4.MiniMapVersionManagerGetVersionString.md), and [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md). The remaining class questions are now source-file grouping and raw helper promotion, not the public method names or core field roles.
- 2026-07-02 B004 implementation callback:
  - Added exact child links for constructor, destructor, `LoadHashFile`, `ClearHashList`, retained-raw cache-load replay, retained-raw cache-save body, singleton-clear helper, and scalar deleting destructor.
  - Closed raw cache-load/cache-save promotion as retained-raw/no-code for this pass because both source-shaped bodies have zero start xrefs and no IDA function identity. DATIndexVector/List helpers in the same physical aggregate remain rejected from MiniMapVersionManager ownership.
- 2026-07-09 B001 UID0004D8 implementation callback:
  - Score unchanged at `85/87`.
  - Expanded the constructor row, IDA evidence, ownership notes, and field-direction note for current MCP session `supervisor_nexustk_20260709`: singleton publish/guard-clear, vtable write, sole `_WinMain@16` caller, embedded `DATIndexVector` construction at `+0x48`, non-emitting `StdListBuyNode8`, source-owned `DATIndexVector::ResizeAndFill(8)`, and blank constructor C++ pending an accepted member-construction model.
- 2026-07-09 B003 UID0004D9 implementation callback:
  - Score unchanged at `85/87`.
  - Expanded the destructor row, IDA evidence, and ownership notes with current MCP-backed destructor details: exact range/padding, vtable restore, expected-version string cleanup, sentinel/count reset, node frees, `DATIndexVector::ResizeAndFill(8)`, `DATIndexVector::~DATIndexVector`, singleton clear, scalar deleting destructor peer, and blank/no-code generated empty-marker disposition.
- 2026-07-09 B003 UID0004DB implementation callback:
  - Score unchanged at `85/87`.
  - Expanded the `ClearHashList` row, IDA evidence, and ownership notes with current MCP-backed details: exact `0x00456700-0x00456791` range, `sub_456700` size `0x91`, no direct entry callers/xrefs, payload free anchors, sentinel/count reset, old-node free loop, `DATIndexVector::ResizeAndFill(8)`, return at `0x00456790`, `0xcc` padding through `0x0045679f`, and first-draft C++ readiness.
  - The accepted [UID:0004DB][0x00456700-0x00456791.MiniMapVersionManagerClearHashList](by-memory/0x00456700-0x00456791.MiniMapVersionManagerClearHashList.md) page now records `89/91` with formal first-draft `void MiniMapVersionManager::ClearHashList()` C++; `delete []` and `delete` remain documented as inferred source-facing operations over observed CRT/list-helper lowering.
