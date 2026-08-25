** TARGET-REPORT-UID:0003FZ **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003FZ **
# 0003FZ MinimapDownloadWideLiterals Ownership Research

Revision: B001-0003FZ, 2026-06-12

## Finalized Report / Current Recommendation

- Target UID/path: [UID:0003FZ] `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md`.
- Current best action: **no by-* documentation change and no parent assignment**. Keep `COMPLETION:89`, `CONFIDENCE:93`, `RECONSTRUCTABLE:TRUE`, and blank `AUTOGEN_PARENT_UID`.
- Ownership result: this is a real, coherent, reconstructable minimap download literal group, but the physical `.rdata` bytes are shared by at least two modeled source families and one raw MiniMap-side helper body. IDA and PE evidence support "pooled/shared minimap download literals" more strongly than either `FileDownloader`-only, `MiniMap`-only, or a newly-created shared constants source owner.
- Split result: **do not split further**. Every proposed sub-split still has the same cross-family owner problem or would create smaller parent-blank literal fragments without improving source reconstruction. The half-open range `0x0060d7f4-0x0060d8b8` is byte-supported; `0x0060d8b8` starts the separate item-shop version URL child.
- Best forced owner if a future source merge demanded one: `MiniMap` / `map/MiniMapDownloader.cpp` is the strongest semantic source-family candidate because the constants are minimap-domain strings and the extra raw refs sit in the MiniMap renderer/control neighborhood. That is still not strong enough for an `AUTOGEN_PARENT_UID` today because `FileDownloader::OnMessage` message `10000` directly consumes the full group through its own modeled helper, and there is no table, writer, source metadata, shared constant declaration, or interprocedural edge proving the literals were declared under MiniMap rather than pooled from repeated local literals.
- New owner/file recommendation: **do not create a new `MinimapDownloadConstants` or `MinimapDownloadShared` parent now**. If later source reconstruction proves a shared declaration, that owner would probably contain the S3 minimap URL prefix, `.mnm` suffix, `%03d` directory format, `%s%s/%s%s` URL builder format, `Downloading : %d\n` progress text, and perhaps the duplicate WinINet minimap download helpers at `0x0041a750`, `0x00453aa0`, and raw `0x00454e30-0x00455040`. Current evidence rejects creating it because all references are direct immediates, there is no shared storage/table, the two modeled helpers have different task layouts, and the raw helper has no IDA function object or incoming entry xref.
- Confidence: `93/100` for bytes/range/xrefs, `90/100` for no-split, `86/100` for keeping the parent blank as the best source-ownership decision. The parent-blank confidence is below the byte confidence because final source literal pooling versus shared declaration cannot be decided from this binary alone.

## Target And Current State

Target page metadata at review time:

```text
*** UID:0003FZ
*** COMPLETION:89
*** CONFIDENCE:93
*** RECONSTRUCTABLE:TRUE
*** AUTOGEN_PARENT_UID:
```

The page covers `0x0060d7f4-0x0060d8b8` in `.rdata` and describes six UTF-16LE minimap download literals:

| Range | Literal | Live consumer pattern |
| --- | --- | --- |
| `0x0060d7f4-0x0060d7fc` | `000` | `sub_41A750` and `sub_453AA0` |
| `0x0060d7fc-0x0060d808` | `%03d` | `sub_41A750` and `sub_453AA0` |
| `0x0060d808-0x0060d818` | `.mnm` | `sub_41A750`, `sub_453AA0`, raw `0x00454e6f` |
| `0x0060d818-0x0060d880` | `https://s3.amazonaws.com/kru-downloads/tk/minimaps/` | `sub_41A750`, `sub_453AA0`, raw `0x00454e7b` |
| `0x0060d880-0x0060d894` | `%s%s/%s%s` | `sub_41A750` and `sub_453AA0` |
| `0x0060d894-0x0060d8b8` | `Downloading : %d\n` | `sub_41A750`, `sub_453AA0`, raw `0x00454fcc` |

The target is a child of the non-emitting split-audit container [UID:0003AL] `0x0060d7e0-0x0060d9c0.CashShopDownloaderLiterals`. That container already separates the neighboring shared user-agent literal [UID:0003FY], this minimap group [UID:0003FZ], FileDownloader-owned item-shop literals [UID:0003G0]/[UID:0003G2], and shared narrow `version` key [UID:0003G1].

## Evidence Standards Used

- IDA MCP evidence is treated as authoritative for function boundaries, direct xrefs, item names, raw helper/function status, and decoded bytes.
- Existing by-* documentation is treated as lead evidence only. I rechecked the target, adjacent split pages, FileDownloader/MiniMap owner pages, and the relevant function/class pages against IDA.
- Consumer xrefs are not declaration proof. For string literals in `.rdata`, especially repeated string constants, direct reads prove use and may support a source-family inference, but do not by themselves prove which translation unit declared the physical pooled bytes.
- This report does not use Wave2/Wave3 source output as ownership proof and does not edit `by-memory/-coverage-report.md`.

## Live IDA MCP Evidence

IDA session:

```text
session: b001_nexustk
input: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
imagebase: 0x400000
hexrays_ready: true
strings_cache_ready: true
```

Function lookup:

| Query | IDA result | Ownership meaning |
| --- | --- | --- |
| `0x0041a750` | `sub_41A750`, size `0x2ae` | FileDownloader message `10000` minimap download helper |
| `0x00453aa0` | `sub_453AA0`, size `0x2af` | MiniMapDownloader worker minimap download helper |
| `0x00454e30` | not a function | raw MiniMap-side helper body start candidate |
| `0x00455040` | not a function | raw helper return/tail boundary; only xref is previous instruction fallthrough/control |
| `0x00455050` | `sub_455050`, size `0x3` | next modeled helper after raw body |
| `0x00455060` | `sub_455060`, size `0x68` | next modeled helper after raw body |
| `0x004550d0` | `sub_4550D0`, size `0x10f` | documented support helper after raw body |

Direct `xrefs_to` results:

| Target | Direct xrefs |
| --- | --- |
| `0x0060d7f4` | `0x0041a794` in `sub_41A750`; `0x00453ae4` in `sub_453AA0` |
| `0x0060d7f8` | `0x0041a7a0` in `sub_41A750`; `0x00453aed` in `sub_453AA0` |
| `0x0060d7fc` | `0x0041a7d2` in `sub_41A750`; `0x00453b12` in `sub_453AA0` |
| `0x0060d808` | `0x0041a7e2` in `sub_41A750`; `0x00453b22` in `sub_453AA0`; raw `0x00454e6f` |
| `0x0060d818` | `0x0041a7f2` in `sub_41A750`; `0x00453b32` in `sub_453AA0`; raw `0x00454e7b` |
| `0x0060d880` | `0x0041a7f7` in `sub_41A750`; `0x00453b37` in `sub_453AA0` |
| `0x0060d894` | `0x0041a988` in `sub_41A750`; `0x00453cd7` in `sub_453AA0`; raw `0x00454fcc` |
| `0x0060d8b8` | `0x0041aa64` in `sub_41AA00` only, proving the successor belongs to the item-shop version child |

`analyze_component` over `0x0041a750` and `0x00453aa0` reports matching WinINet/file callee sets and the same shared globals:

- `szAgent` at `0x0060d7e0`
- `dword_60D7F4` at `0x0060d7f4`
- `dword_60D7F8` at `0x0060d7f8`
- `Format` at `0x0060d7fc`
- `aMnm` at `0x0060d808`
- `aHttpsS3Amazona` at `0x0060d818`
- `aSSSS` at `0x0060d880`
- `aDownloadingD` at `0x0060d894`

The same component analysis shows no internal call edge between `sub_41A750` and `sub_453AA0`. They are similar helpers, not a caller/callee pair or an obvious wrapper around a single shared implementation.

Filtered Hex-Rays comparison:

- `sub_41A750` is `void *__stdcall sub_41A750(int a1)`. It reads the map id at `a1 + 12`, opens the local output path at `a1 + 16`, and uses a later task field in the URL format. It is called by the FileDownloader message `10000` dispatcher.
- `sub_453AA0` is `char __stdcall sub_453AA0(int *a1)`. It reads the map id from `*a1`, advances the task pointer for the output path, and is called by `MiniMapDownloader::OnThreadTask`.
- Both open WinINet with `HTTPTEST`, seed the directory string with `000`, use `%03d`, build the same S3 minimap URL with `%s%s/%s%s`, open/read/write the `.mnm` payload, log `Downloading : %d\n`, and delete partial output on failure.

The differing task layouts are important negative ownership evidence: they make it plausible that the same source literals appeared in two separate helper implementations and were pooled into one `.rdata` block, rather than proving one helper owns the literals for the other.

Raw MiniMap-side helper evidence:

- `search_text` over `0x00454e30-0x00455040` finds `push offset aMnm` at `0x00454e6f`.
- The same raw range finds `push offset aHttpsS3Amazona` at `0x00454e7b`.
- The same raw range finds `push offset aDownloadingD` at `0x00454fcc`.
- `make_signature_for_range 0x00454e30-0x00455040` returns a unique stack-cookie-protected byte signature containing `push offset szAgent`, `push offset aMnm`, `push offset aHttpsS3Amazona`, WinINet/file IO calls, and `push offset aDownloadingD`.
- `xrefs_to 0x00454e30` returns no incoming references. IDA does not model this body as a function.

Inference: the raw body strengthens the MiniMap-side consumer evidence, but it does not establish a callable source owner, a table owner, or a safe new child/page route for the literal block.

IDA byte read:

`get_bytes` for `0x0060d7e0` confirms the local sequence:

```text
HTTPTEST\0\0
000\0
%03d\0\0
.mnm\0\0\0
https://s3.amazonaws.com/kru-downloads/tk/minimaps/\0
%s%s/%s%s\0
Downloading : %d\n\0
https://secure.kru.com...
```

This proves the `0003FZ` child starts after the shared user-agent tail and ends before the item-shop version URL child.

## PE / Pointer Evidence

Read-only PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

- `0x0060d7f4-0x0060d8b8` maps to `.rdata` file offsets `0x20c1f4-0x20c2b8`, length `0xc4`.
- The exact `0xc4` byte block appears once in the file, at VA `0x0060d7f4`.
- Decoded subliterals match the target page exactly:
  - `0x0060d7f4-0x0060d7fc`: `000`
  - `0x0060d7fc-0x0060d808`: `%03d`
  - `0x0060d808-0x0060d818`: `.mnm`
  - `0x0060d818-0x0060d880`: `https://s3.amazonaws.com/kru-downloads/tk/minimaps/`
  - `0x0060d880-0x0060d894`: `%s%s/%s%s`
  - `0x0060d894-0x0060d8b8`: `Downloading : %d\n`
- Absolute VA dword hits are only the known `.text` immediates:
  - `0x0060d7f4`: `0x0041a796`, `0x00453ae6`
  - `0x0060d7f8`: `0x0041a7a2`, `0x00453aef`
  - `0x0060d7fc`: `0x0041a7d3`, `0x00453b13`
  - `0x0060d808`: `0x0041a7e3`, `0x00453b23`, `0x00454e70`
  - `0x0060d818`: `0x0041a7f3`, `0x00453b33`, `0x00454e7c`
  - `0x0060d880`: `0x0041a7f8`, `0x00453b38`
  - `0x0060d894`: `0x0041a989`, `0x00453cd8`, `0x00454fcd`
  - `0x0060d8b8`: `0x0041aa65`
- No RVA dword hits were found for any target address.
- No executable `.text` rel32 candidate references were found for any target address.

Inference: there is no hidden pointer table, RVA table, registration array, or non-IDA-modeled relative code reference that would identify a single declaration owner. The known references are direct absolute pushes from the two modeled minimap helpers and the raw helper.

## Split / Range Analysis

No split is recommended.

Potential split candidates and why they do not help:

| Proposed split | Evidence for | Rejection reason |
| --- | --- | --- |
| `000` and `%03d` as directory-format child | Only the two modeled helpers reference them | Still shared by FileDownloader and MiniMapDownloader; no exclusive owner emerges. |
| `.mnm`, S3 URL, progress text as raw-MiniMap-plus-modeled child | These have the extra raw MiniMap-side refs | Still also referenced by the FileDownloader helper, so assigning to MiniMap would hide a real modeled FileDownloader consumer. |
| URL builder format `%s%s/%s%s` as separate child | It is a distinct formatting literal | It is used by both modeled helpers and has no raw ref; splitting would only make a smaller parent-blank child. |
| Progress text as separate debug/log literal | It has three refs and is semantically generic | It is specific to the minimap download loops here and still shared across FileDownloader, MiniMapDownloader, and raw MiniMap-side code. |
| Widen to include `HTTPTEST` or item-shop literals | `HTTPTEST` precedes the group; item-shop URL follows it | Existing child pages prove they have different consumer sets. `HTTPTEST` spans more downloader helpers; `0x0060d8b8` is an item-shop FileDownloader child. |

The current group is more useful as one coherent minimap-download literal set because the strings collectively implement one URL builder/download loop. Splitting would only multiply parentless string fragments and reduce context.

## Ranked Ownership Analysis

### 1. Keep `0003FZ` parent blank as pooled/shared minimap download literals

Recommendation rank: accepted.

Evidence for:

- IDA direct xrefs prove every subliteral is consumed by both `sub_41A750` and `sub_453AA0`.
- `sub_41A750` is documented and IDA-confirmed as the FileDownloader message `10000` path, with direct parent [UID:0000JC] `FileDownloader`.
- `sub_453AA0` is documented and IDA-confirmed as the MiniMapDownloader worker helper, with direct parent [UID:0000LE] `MiniMap`.
- Raw `0x00454e30-0x00455040` references only some of the group and has no modeled function object or incoming entry xref.
- PE scan found only direct immediates, no owner table, no RVA array, and no additional hidden refs.
- Adjacent split pages show this `.rdata` area is a literal pool, not one source file's clean private data block.

Evidence against:

- The strings are semantically minimap-specific, so a final source tree might place a shared declaration under `map/`.
- The raw helper is physically in the MiniMap renderer/control neighborhood, which weakly favors a MiniMap source-family explanation.

Conclusion: parent blank is the least misleading source-ownership state. The target remains reconstructable because the data bytes and literals are known; it remains unparented because source declaration ownership is not.

Confidence: `86/100` for the ownership decision, `93/100` for the supporting bytes/xrefs.

### 2. [UID:0000LE] `MiniMap` / `map/MiniMapDownloader.cpp`

Recommendation rank: strongest forced existing owner, rejected for current `AUTOGEN_PARENT_UID`.

Evidence for:

- All literals are minimap-domain literals.
- The MiniMap file root documents `MiniMapDownloader`, `MiniMapRenderer`, minimap version/cache support, and `map/` placement.
- The extra raw refs sit in the MiniMap renderer/control aggregate neighborhood.
- The MiniMap class/global chain already owns `MiniMapDownloader`, `g_pMiniMapDownloader`, and the `.mnm` download worker path.

Evidence against:

- `sub_41A750` directly consumes the entire group through the FileDownloader message `10000` path.
- FileDownloader docs explicitly list `DownloadMinimapFile_41A750` as a FileDownloader-local message helper with minimap feature context.
- There is no call edge proving FileDownloader imports these constants from MiniMap or that the raw helper is the declaration source.
- Assigning the literal block to MiniMap would hide the real FileDownloader consumer and turn semantic domain into declaration proof.

Conclusion: keep as a candidate, not an assignment.

Confidence if forced: `78/100`.

### 3. [UID:0000JC] `FileDownloader` / `network/FileDownloader.cpp`

Recommendation rank: strong consumer, rejected as exclusive owner.

Evidence for:

- `sub_41A750` consumes all literals and is directly dispatched by `FileDownloader::OnMessage` case `10000`.
- FileDownloader owns the message IDs, dispatcher, and item-shop download literal children that follow this range.
- The generic WinINet helper style and queue-posting path make `network/FileDownloader.cpp` a plausible location for one copy of the source literals.

Evidence against:

- `sub_453AA0` consumes the same full literal group inside the MiniMapDownloader worker class.
- Raw MiniMap-side refs consume three important literals outside the FileDownloader range.
- The strings are not generic downloader infrastructure; they are minimap S3 and `.mnm` literals.
- FileDownloader documentation itself says `MiniMapDownloader` is related but should stay in the MiniMap source family.

Conclusion: FileDownloader is a real consumer and possible repeated-literal origin, but not a safe direct parent for the physical pooled group.

Confidence if forced: `70/100`.

### 4. New `map/MinimapDownloadShared` or `map/MinimapDownloadConstants`

Recommendation rank: plausible future source artifact, rejected now.

What it would contain if later proven:

- This literal group [UID:0003FZ].
- Possibly the raw helper body `0x00454e30-0x00455040` if it becomes an IDA-modeled function with call evidence.
- Possibly `sub_453AA0` / `MiniMapDownloader::DownloadMinimap` and maybe `sub_41A750` only if later task-structure reconciliation proves both were compiled from a shared minimap download source or shared helper declaration.
- It should not automatically include [UID:0003FY] `HTTPTEST`, because that literal is used by item-shop FileDownloader helpers as well as minimap helpers.
- It should not include [UID:0003G0]/[UID:0003G2] item-shop literals, because those are FileDownloader item-shop children with different URL domain and consumer set.

Evidence for:

- The two modeled helpers are near-clones with the same WinINet/file API set and same minimap literal group.
- A shared constants header or helper source is a reasonable original-source possibility.

Evidence against:

- No shared table, no address-taken constant block, no pointer-to-literal owner, no debug/source metadata, and no source path string exists in the live evidence.
- The two modeled helpers have different task layouts and no internal call edge.
- The raw helper has no incoming entry xref and no IDA function object.
- Creating a new parent solely to group uncertain shared literals would violate the by-structure rule that `AUTOGEN_PARENT_UID` must be a direct semantic parent, not a routing shortcut.

Conclusion: do not create this owner unless future evidence proves a shared declaration or shared helper source.

Confidence now: `60/100`.

### 5. Parent to the split-audit container [UID:0003AL]

Recommendation rank: rejected.

The container is deliberately `RECONSTRUCTABLE:FALSE` and parent blank. It spans downloader/minimap/item-shop/fitting-room/startup literal children and exists only to document the split. It is not a source owner.

## Documentation Evidence Review

Documentation checked:

- [UID:0003FZ] target page: IDA and PE rechecks confirm its byte ranges, xrefs, raw-helper caveat, successor boundary, and current parent-blank decision.
- [UID:0003AL] `CashShopDownloaderLiterals`: IDA and adjacent child pages support the current non-emitting split container. No repair needed.
- [UID:0003FY] `SharedDownloaderUserAgentWideString`: useful boundary sibling; it has a broader downloader consumer set and should stay separate.
- [UID:0003G0] and [UID:0003G2]: useful contrast; their item-shop URL literals have FileDownloader-only direct owners and should stay assigned to FileDownloader.
- [UID:0002TR] `DownloadMinimapFile`: IDA decompile confirms it consumes the target strings through FileDownloader message `10000`.
- [UID:0000XN] `MiniMapDownloader`: IDA decompile confirms it consumes the target strings through the MiniMapDownloader worker helper.
- [UID:0000XO] `MiniMapRendererAndControls`: current raw-helper caveat is accurate. No exact child page should be created for `0x00454e30-0x00455040` until the raw entry/function question is resolved separately.
- [UID:0000JC] `FileDownloader`: current caveat that MiniMapDownloader is related but separate is supported.
- [UID:0000LE] `MiniMap`: current caveat that `DownloadMinimapFile_41A750` is a shared FileDownloader helper unless later proof says otherwise is supported.

No documentation contradiction strong enough to justify a by-* edit was found.

## Exact Recommended Actions

1. Leave `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md` unchanged.
2. Leave `by-memory/-coverage-report.md` unchanged.
3. Leave `auto-generated/-ag-memory-coverage.md` unchanged.
4. Supervisor should accept this B001 report as a no-op ownership closeout for B001-0003FZ unless a later source reconstruction pass finds direct shared-declaration evidence.
5. Future optional work, not required for this target: a separate B/A task could investigate raw `0x00454e30-0x00455040` as an exact MiniMap-side helper page. That should be scoped to the raw helper itself, not used retroactively to assign this literal group without entry/caller proof.

## Exact Coverage / Shared-File Text For Supervisor

No coverage edit is recommended. If the supervisor wants an explicit no-op row confirmation, keep the current by-memory coverage row exactly as:

```text
            - [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) 0x0060d7f4-0x0060d8b8 | string-data | MinimapDownloadWideLiterals : reconstructable : 89% : very-strong : UTF-16LE minimap `000`/`%03d`/`.mnm`/S3 URL/format/progress literals; A003 Batch320 live MCP reconfirmed shared modeled consumers in FileDownloader message `10000` and MiniMapDownloader, plus raw MiniMap-side helper refs at `0x00454e6f`, `0x00454e7b`, and `0x00454fcc`. Parent remains blank because no single direct source owner covers the whole pooled literal group.
```

Current auto-generated memory row should also remain unchanged:

```text
| [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) | unassigned |  |  | no |  | `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md` |  |
```

No replacement row is requested.

## Future Evidence That Would Change The Decision

Any of the following would justify reopening ownership:

- A PDB, linker map, or source path showing these literals were declared in a specific translation unit.
- A recovered shared constant declaration or header that both modeled helpers reference in final source.
- IDA evidence that raw `0x00454e30-0x00455040` has real callers and is the source-level shared implementation used by both other paths.
- A compiler/linker reconstruction proving this exact physical block cannot result from repeated pooled local literals.
- A task-structure reconciliation proving `sub_41A750` and `sub_453AA0` are not separate source helpers but compiler variants or wrappers around one owner.

Absent that evidence, assigning the block to `FileDownloader`, `MiniMap`, or a new owner would be less accurate than the current parent-blank state.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003FZ","source_path":"executed-b-agent-research/B001/0003FZ-MinimapDownloadWideLiterals-B001-0003FZ.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
