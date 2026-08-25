** TARGET-REPORT-UID:0002JL **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002 source-quality report: MiniMapVersionManager update/access/lookup cluster

Assignment: `B002-goal2-minimap-version-manager-source-quality-0002JL-0002JM-0000XQ-20260617`

Primary targets:

- [UID:0002JL] `by-memory/0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList.md`
- [UID:0002JM] `by-memory/0x004570a0-0x004570a4.MiniMapVersionManagerGetVersionString.md`
- [UID:0000XQ] `by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md`

This was report-only B-agent work. I did not edit by-* docs, generated reports, generated source, source files, IDA DB, or `by-memory/-coverage-report.md`.

## Executive Recommendation

Raise all three primary targets above the current 82/90 state, but do not treat them identically for formal C++:

- [UID:0002JL] should be raised to `87/91`, owner/emitter should move from file ownership to class ownership (`00008H`), and formal C++ should remain blank for now. The method body is well understood, but it overlaps policy questions with the raw cache-load/cache-save sibling bodies at `0x004567a0` and `0x00456960`; entering a full formal source body before those split pages and shared helper declarations are finalized would force low-quality local declarations into an otherwise good method.
- [UID:0002JM] should be raised to `89/93`, owner/emitter should be `00008H`, and formal C++ should be populated. It is the exact four-byte accessor for the current minimap hash/version string buffer.
- [UID:0000XQ] should be raised to `88/92`, owner/emitter should be `00008H`, and formal C++ should be populated. It is the exact map-id to expected minimap-version lookup used by MiniMapRenderer.

Recommended class/source route:

- `CANONICAL_OWNER:00008H` for all three primary methods.
- `EMITTER_UIDS:00008H` for all three primary methods.
- Generated route remains `NexusTK/map/MiniMapVersionManager.cpp` through the `MiniMapVersionManager` class and file docs.

This class-owned route is more source-authentic than the current file-owned metadata. The by-class page is already above the direct-ownership threshold, and [UID:0003FQ] read-only data already demonstrates class-to-file routing into the same generated output path.

## Evidence Checked

Current docs and generated state checked:

- Primary target docs for [UID:0002JL], [UID:0002JM], and [UID:0000XQ].
- Support docs for [UID:00008H] `MiniMapVersionManager`, [UID:0000LF] file, [UID:0000XP] aggregate, [UID:0003FQ] read-only data, [UID:0001OZ]/[UID:0000RP] singleton, [UID:0001V8] `MiniMapVersionNode`, [UID:0001IO] StartupWindow update-check, [UID:0000XO] MiniMapRenderer and controls, DATIndexVector/List helper docs, and current `by-memory/-coverage-report.md` rows.
- Existing B-agent executed reports for these UIDs or sibling minimap targets. No executed report directly covers [UID:0002JL], [UID:0002JM], or [UID:0000XQ]. The StartupWindow rdata report supports keeping remote URL/update-check ownership in StartupWindow rather than in MiniMapVersionManager.
- Generated output: `auto-generated/NexusTK/map/MiniMapVersionManager.cpp` currently exists but is empty; generated coverage rows show `code no` for these targets.

Live IDA/binary evidence checked:

- IDB `NexusTK.exe.i64`, imagebase `0x400000`, auto-analysis and Hex-Rays ready.
- `lookup_funcs` confirms exact modeled functions:
  - `0x00456a90`: `sub_456A90`, size `0x60e`.
  - `0x004570a0`: `sub_4570A0`, size `0x4`.
  - `0x004570b0`: `sub_4570B0`, size `0x30`.
  - `0x004567a0`, `0x00456939`, and `0x00456960` are not IDA function starts.
- `xrefs_to` confirms:
  - [UID:0002JL] callers at `0x004566d9` in `sub_456540`, raw call at `0x00456939`, and StartupWindow caller at `0x00580fdd`.
  - [UID:0002JM] sole caller at `0x00580ea3` in StartupWindow update-check.
  - [UID:0000XQ] renderer callers at `0x0045433c` and `0x00454dad`.
- PE-aware raw pointer checks found no VA/RVA pointer-table references to raw sibling starts `0x004567a0` or `0x00456960`; direct-call bytes to [UID:0002JL] include the raw cache-load call at `0x00456939`.
- Bytes around target boundaries confirm:
  - [UID:0002JL] ends at `0x0045709e`, followed by `0x0045709e-0x004570a0` two-byte `0xcc` padding.
  - [UID:0002JM] body is `8d 41 04 c3` and is followed by `0x004570a4-0x004570b0` `0xcc` padding.
  - [UID:0000XQ] starts at `0x004570b0` and ends at `0x004570e0`.

## Primary Method Findings

### [UID:0002JL] UpdateHashList

Best source-facing signature:

```cpp
void MiniMapVersionManager::UpdateHashList(const wchar_t* versionString,
                                           wchar_t* hashListText,
                                           bool saveCache);
```

Evidence:

- The first argument is copied into `this+0x04` with `_wcscpy_s(..., 0x21, ...)`, so it is the current minimap hash/version string and should be const at the source level.
- The second argument is tokenized with `_wcstok(..., L"/", ...)`, so it must be mutable input text. Source name `hashListText` is better than a generic `String`.
- The third argument controls the optional persistence path. StartupWindow passes `1` after a remote HashList fetch; local cache-load code passes `0` when replaying a cached list. Source name `saveCache` or `persistToDisk` is defensible; I recommend `saveCache` because the branch writes `%APPDATA%\NexusTK\MiniMap\mnmhs.hs`.
- Slash tokens are records. Comma separates the decimal map id from the expected minimap header/version string.
- Existing-node handling updates the payload string. New-node handling allocates a `0x42` byte, 33-wide-character payload buffer, creates a list node, increments the count field at `+0x50`, links through the sentinel at `+0x4c`, and inserts into the embedded DATIndexVector at `+0x48`.

Recommended field/type names:

- `this+0x04`: `wchar_t m_currentVersion[0x21]`.
- `this+0x48`: `DATIndexVector m_versionIndex`.
- `this+0x4c`: `MiniMapVersionNode* m_versionListHead` or `m_versionListSentinel`.
- `this+0x50`: `int m_versionNodeCount`.
- `MiniMapVersionNode +0x08`: `int mapId`.
- `MiniMapVersionNode +0x0c`: `wchar_t* expectedVersionString`.

The existing `hashKey` name for the node key should be retired or downgraded to a historical alias. The renderer passes the current map id from offset `+0x25c`; no hash value is passed at the call sites. The cached file and remote text are hash-list resources, but the in-memory key is a map id.

Formal C++ policy:

- Do not populate [UID:0002JL]'s formal `RECONSTRUCTION_CPP CODE` block yet.
- This target clears the score gate, but source-quality C++ would require exact source declarations for the raw cache-load/cache-save siblings, the shared list and DATIndexVector helper APIs, the wide dispatch-table wrappers, and the string/token helper conventions. Entering a large body now would likely hard-code interim helper names and obscure the separate split work.

### [UID:0002JM] GetVersionString

Best source-facing signature:

```cpp
const wchar_t* MiniMapVersionManager::GetVersionString() const;
```

Evidence:

- Exact body is `lea eax, [ecx+4]; ret`.
- Sole live caller is StartupWindow update-check at `0x00580ea3`; StartupWindow compares the result with the server-side current version through `__wcsicmp`.
- The returned buffer is the same `this+0x04` buffer updated by [UID:0002JL].

Rejected alternatives:

- `GetCurrentVersionString` is semantically clear, but the current target and class docs already use `GetVersionString`. The short accessor name is source-plausible and should not be churned unless another source string or symbol proves otherwise.
- Returning mutable `wchar_t*` is binary-compatible, but the source-facing accessor should be `const wchar_t*` because callers compare/read the buffer.

Formal C++ should be populated.

### [UID:0000XQ] Map-id lookup

Best source-facing signature:

```cpp
const wchar_t* MiniMapVersionManager::GetExpectedVersionForMapId(int mapId) const;
```

Evidence:

- Renderer call sites pass a dword field at `MiniMapRenderer +0x25c`.
- Both renderer callers read `0x21` UTF-16 characters from a `.mnm` file and compare that header string with the lookup result via `wcscmp`.
- Body calls `DATIndexVectorFindNodeByKey` with the embedded index at `this+0x48`, compares the result against the sentinel at `this+0x4c`, returns `NULL` on miss, and returns node payload at `+0x0c` on hit.

Rejected alternatives:

- `MiniMapVersionLookupByMapId` is an acceptable documentation label but less source-like as a class method.
- `GetVersionForHash` or `FindHashByMapId` is not supported by the callers. The argument is the renderer's map id, and the return is a version/header string, not a hash object.
- Placing this under MiniMapRenderer is wrong because both renderer callers load the global `g_pMiniMapVersionManager` and call into the manager; renderer owns the comparison decision, not the version table.

Formal C++ should be populated.

## Raw Cache-Load/Cache-Save Sibling Policy

The raw bodies inside [UID:0000XP] are real source-shaped code, but they should not block raising the three primary targets.

Evidence:

- `0x004567a0-0x0045695e` is a raw cache-load shaped body. It builds the same `%APPDATA%\NexusTK\MiniMap\mnmhs.hs` path, opens the file, reads a one-byte version-string length, reads the version string, reads the remaining hash-list text, and calls [UID:0002JL] at `0x00456939` with `saveCache == 0`.
- `0x00456960-0x00456a8e` is a raw cache-save shaped body. It builds directories/path, opens the same cache file, writes the one-byte version length, writes the version string, writes the hash-list text, closes, and returns with `retn 8`.
- The aggregate doc currently describes the cache-save shaped body as ending near `0x00456a89`; live disassembly shows the epilogue/return extends through `0x00456a8d`, so the end-exclusive range should be `0x00456a8e`, followed by `0x00456a8e-0x00456a90` alignment padding.
- No direct xrefs or VA/RVA pointer-table hits target raw starts `0x004567a0` or `0x00456960`. The cache-load body has an internal call to [UID:0002JL] but no modeled entry point.

Recommendation:

- Do not force these raw bodies into [UID:0002JL].
- Add follow-up exact child/split tasks for:
  - `0x004567a0-0x0045695e` as a cache-load-and-update helper candidate.
  - `0x00456960-0x00456a8e` as a cache-save helper candidate.
  - `0x00456a8e-0x00456a90` as padding if the split is applied.
- Treat them as retained source-authored or compiler-retained helper bodies until exact reachability is resolved. They are not DATIndexVector/List helpers and should remain in MiniMapVersionManager context.

## DATIndexVector/List Ownership

Keep generic helpers out of MiniMapVersionManager.

Evidence:

- `DATIndexVectorFindNodeByKey` and `DATIndexVectorInsertNode` are documented as shared DATIndexVector helpers with caller spread outside minimap, including archive/image-library users.
- `CreateListNodeWithPayload` and `CreateListNode` are shared list/node allocation utilities.
- [UID:0002JL] and [UID:0000XQ] should reference those helpers through source-quality names, but their bodies and formal declarations belong to the existing shared helper/class docs.

No DATIndexVector/List support row should be absorbed into `MiniMapVersionManager.cpp` unless a later helper-specific task proves otherwise.

## Support Docs To Update

Recommended support-doc content updates:

- `by-class/MiniMapVersionManager.md`
  - Update method list to use:
    - `void UpdateHashList(const wchar_t* versionString, wchar_t* hashListText, bool saveCache);`
    - `const wchar_t* GetVersionString() const;`
    - `const wchar_t* GetExpectedVersionForMapId(int mapId) const;`
  - Update field names to `m_currentVersion`, `m_versionIndex`, `m_versionListHead`/`m_versionListSentinel`, and `m_versionNodeCount`.
  - Record that class-owned method pages should emit through this class to `NexusTK/map/MiniMapVersionManager.cpp`.
- `by-file/MiniMapVersionManager.md`
  - Keep the dedicated file route. Do not move these methods into StartupWindow, MiniMapRenderer, MiniMap.cpp umbrella docs, or DATIndexVector helper docs.
- `by-memory/0x004563c0-0x00457547.MiniMapVersionManager.md`
  - Update raw cache-save range to `0x00456960-0x00456a8e`.
  - Add padding `0x00456a8e-0x00456a90` if the aggregate is split later.
  - Record no VA/RVA pointer-table hits to raw starts and no IDA functions at the raw starts.
- `by-type/by-struct/MiniMapVersionNode.md`
  - Prefer `mapId` at `+0x08` over `hashKey`.
  - Prefer `expectedVersionString` at `+0x0c` over the broader `versionText`.
  - Keep the `0x21` wide-character payload capacity note.
- `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`
  - Cross-reference the resolved `GetVersionString` and `UpdateHashList(..., saveCache=true)` call shape.
- `by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md`
  - Cross-reference `GetExpectedVersionForMapId(mapId)` and note the `.mnm` header comparison against 33 UTF-16 characters.

No support score change is required for this assignment unless the supervisor wants to rescore the class/struct pages after applying field-name updates.

## Exact Score And Metadata Recommendations

[UID:0002JL] `MiniMapVersionManagerUpdateHashList`

- `COMPLETION_SCORE:87`
- `CONFIDENCE_SCORE:91`
- `RECONSTRUCTABLE:TRUE`
- `CANONICAL_OWNER:00008H`
- `EMITTER_UIDS:00008H`
- Keep generated route through `NexusTK/map/MiniMapVersionManager.cpp`.
- Keep formal C++ blank for now.

[UID:0002JM] `MiniMapVersionManagerGetVersionString`

- `COMPLETION_SCORE:89`
- `CONFIDENCE_SCORE:93`
- `RECONSTRUCTABLE:TRUE`
- `CANONICAL_OWNER:00008H`
- `EMITTER_UIDS:00008H`
- Populate formal C++.

[UID:0000XQ] `MiniMapVersionLookupByMapId`

- `COMPLETION_SCORE:88`
- `CONFIDENCE_SCORE:92`
- `RECONSTRUCTABLE:TRUE`
- `CANONICAL_OWNER:00008H`
- `EMITTER_UIDS:00008H`
- Populate formal C++.

## Supervisor-Owned Coverage Row Replacements

Placement context: replace the three existing rows for [UID:0002JL], [UID:0002JM], and [UID:0000XQ] under the [UID:0000XP] `MiniMapVersionManager` aggregate block in `by-memory/-coverage-report.md`. Leave the two existing ignored padding rows in place.

Replacement row for [UID:0002JL]:

```md
        - [UID:0002JL][0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList](by-memory/0x00456a90-0x0045709e.MiniMapVersionManagerUpdateHashList.md) 0x00456a90-0x0045709e | method | MiniMapVersionManager::UpdateHashList : reconstructable : 87% : very strong : B002 2026-06-17 source-quality recheck resolves the method as `void UpdateHashList(const wchar_t* versionString, wchar_t* hashListText, bool saveCache)`: live IDA confirms exact bounds, two-byte successor padding, current-version copy into `+0x04`, optional `_wfopen`/directory-dispatch persistence to `%APPDATA%\\NexusTK\\MiniMap\\mnmhs.hs`, slash record and comma field tokenization, dword map-id parse, expected-version payload updates/allocation, shared LinkedList/DATIndexVector dependency calls, modeled load/startup callers plus raw cache-load caller at `0x00456939`; formal C++ remains blank pending exact raw cache-load/save child split and shared helper declaration finalization.
```

Replacement row for [UID:0002JM]:

```md
        - [UID:0002JM][0x004570a0-0x004570a4.MiniMapVersionManagerGetVersionString](by-memory/0x004570a0-0x004570a4.MiniMapVersionManagerGetVersionString.md) 0x004570a0-0x004570a4 | accessor | MiniMapVersionManager::GetVersionString : reconstructable : 89% : very strong : B002 2026-06-17 source-quality recheck resolves the source accessor as `const wchar_t* GetVersionString() const` returning `m_currentVersion` at `+0x04`; live IDA confirms the exact four-byte `lea eax,[ecx+4]; ret` body, no callees, sole StartupWindow `__wcsicmp` caller, padding before/after, and valid class/file emitter route; formal C++ should be populated.
```

Replacement row for [UID:0000XQ]:

```md
        - [UID:0000XQ][0x004570b0-0x004570e0.MiniMapVersionLookupByMapId](by-memory/0x004570b0-0x004570e0.MiniMapVersionLookupByMapId.md) 0x004570b0-0x004570e0 | method | MiniMapVersionManager::GetExpectedVersionForMapId : reconstructable : 88% : very strong : B002 2026-06-17 source-quality recheck resolves the source method as `const wchar_t* GetExpectedVersionForMapId(int mapId) const`: live IDA confirms exact body, dword map-id callers from renderer `+0x25c`, `DATIndexVectorFindNodeByKey` over `m_versionIndex` at `+0x48`, miss sentinel `m_versionListHead` at `+0x4c`, return of node `expectedVersionString` at `+0x0c`, and renderer comparisons against `0x21`-wide `.mnm` header strings; formal C++ should be populated.
```

No padding row replacement is required for `0x0045709e-0x004570a0` or `0x004570a4-0x004570b0`.

## Heuristic / Inference Reanalysis And Validation

Best defensible source names and types:

- `MiniMapVersionManager::UpdateHashList` remains the best method name for [UID:0002JL]. It updates the in-memory map-id/version table and, when requested, persists the same text to the hash cache. `LoadHashList` was rejected because local cache-load already calls it, and StartupWindow uses it for a freshly downloaded list. `SaveHashList` was rejected because saving is only the optional first branch.
- `MiniMapVersionManager::GetVersionString` is the best low-churn accessor name for [UID:0002JM]. `GetCurrentVersionString` is semantically clear but not enough better to justify renaming absent source proof.
- `MiniMapVersionManager::GetExpectedVersionForMapId` is the best method name for [UID:0000XQ]. `FindMapHash`, `LookupHash`, and `MiniMapVersionLookupByMapId` were rejected because callers compare the returned string to a `.mnm` version/header string, not to a hash object.
- `m_currentVersion[0x21]` at `+0x04` is validated by `_wcscpy_s(..., 0x21, ...)`, the four-byte accessor, and StartupWindow comparison.
- `m_versionIndex` at `+0x48`, `m_versionListHead` at `+0x4c`, and `m_versionNodeCount` at `+0x50` are validated by insertion, lookup, sentinel comparison, and count increment paths.
- `MiniMapVersionNode::mapId` at `+0x08` is validated by renderer dword map-id callers. `hashKey` was an understandable earlier name from the hash-list file, but it is not the source-facing in-memory key.
- `MiniMapVersionNode::expectedVersionString` at `+0x0c` is validated by [UID:0000XQ] return and renderer `.mnm` header comparisons.

Evidence checked and existing-doc validation:

- The existing target docs correctly captured the broad behaviors, function bounds, callers, and padding for the three primaries.
- The existing docs' "final names remain open" language should be replaced for [UID:0002JM] and [UID:0000XQ]. The caller evidence is strong enough to resolve those names.
- The existing docs' uncertainty around [UID:0002JL]'s final field/source names can be narrowed to helper/API declarations and raw-sibling split, not the main method purpose or parameter meanings.
- The aggregate doc correctly identifies raw cache-load/cache-save shaped code, but should correct the cache-save end-exclusive range to `0x00456a8e`.
- The class/file route is valid, but method ownership should be class-level now that [UID:00008H] is a stable class doc.

Rejected alternatives:

- StartupWindow ownership was rejected. StartupWindow owns remote HTTP/update-check orchestration and passes the downloaded hash-list text to the manager; it does not own the table update or cache format.
- MiniMapRenderer ownership was rejected. Renderer owns file-header comparison and missing/outdated minimap behavior; it calls the manager to obtain the expected version.
- DATIndexVector/List ownership was rejected for the primary targets. Their helpers are shared generic dependencies and should stay in their existing utility/class docs.
- Treating raw `0x004567a0` and `0x00456960` as dead compiler artifacts was rejected as too strong. They are source-shaped, cookie-protected bodies that use meaningful minimap cache logic. However, no direct-entry evidence currently proves they should receive formal C++ or be folded into [UID:0002JL].
- Treating raw cache-save as an implementation detail inside [UID:0002JL] was rejected because [UID:0002JL] already contains its own optional save branch and the raw body has a separate prologue/epilogue.

Score/source-placement/final-C++ impact:

- [UID:0002JL] can rise to `87/91` because parameter names, field names, token semantics, cache path, callers, and dependency ownership are resolved. It should not get formal C++ yet because the raw cache sibling split and helper declarations would otherwise be baked into a large draft.
- [UID:0002JM] can rise to `89/93` and receive formal C++. There is no remaining source-quality blocker.
- [UID:0000XQ] can rise to `88/92` and receive formal C++. The only mild uncertainty is exact DATIndexVector source API spelling, not method behavior.
- All three should shift to class owner/emitter [UID:00008H], with output still routed to [UID:0000LF] `NexusTK/map/MiniMapVersionManager.cpp`.

## First-Draft C++ Recommendation

[UID:0002JL] `MiniMapVersionManager::UpdateHashList`

Do not populate the formal C++ block for [UID:0002JL] in this pass. The report supplies source names and behavior, but not an accepted exact formal body.

[UID:0002JM] `MiniMapVersionManager::GetVersionString`

Populate formal C++ with:

```cpp
const wchar_t* MiniMapVersionManager::GetVersionString() const
{
    return m_currentVersion;
}
```

[UID:0000XQ] `MiniMapVersionManager::GetExpectedVersionForMapId`

Populate formal C++ with:

```cpp
const wchar_t* MiniMapVersionManager::GetExpectedVersionForMapId(int mapId) const
{
    MiniMapVersionNode* node = m_versionIndex.FindNodeByKey(mapId);
    if (node == m_versionListHead) {
        return NULL;
    }

    return node->expectedVersionString;
}
```

If the accepted DATIndexVector class API uses an out-parameter wrapper instead of returning a node directly, adjust only the helper call spelling. The control flow, sentinel test, argument type, and returned payload should remain as above.

## Validation Commands

After supervisor applies the accepted doc/metadata/C++ changes:

> Executable block R001 was removed from this report and preserved verbatim in [0002JL-0002JM-0000XQ-minimap-version-manager-source-quality-removed.md](0002JL-0002JM-0000XQ-minimap-version-manager-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the repository uses the project-documentation working directory for these commands, run them from `source-3/project-documentation`.

## Follow-Up Work

- Create exact child pages for the raw cache-load and cache-save shaped bodies inside [UID:0000XP], or document why they remain aggregate-only after a deeper entry-point scan.
- Audit `CreateListNodeWithPayload` and DATIndexVector source API spelling before entering [UID:0002JL] formal C++.
- Revisit `MiniMapVersionNode` field names after the struct doc is updated; `mapId` and `expectedVersionString` should become the preferred source names.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002JL-0002JM-0000XQ-minimap-version-manager-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:25","uid":"0002JL"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002JL-0002JM-0000XQ-minimap-version-manager-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0002JL-0002JM-0000XQ-minimap-version-manager-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002JL"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
