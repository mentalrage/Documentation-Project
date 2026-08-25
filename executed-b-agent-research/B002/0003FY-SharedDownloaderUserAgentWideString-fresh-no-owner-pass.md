** TARGET-REPORT-UID:0003FY **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003FY **
# 0003FY SharedDownloaderUserAgentWideString Fresh No-Owner Pass

## Final Recommendation

- Keep [UID:0003FY][0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString](../../../../../by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md) as `CANONICAL_OWNER:NONE`.
- Keep `EMITTER_UIDS:0000JC,0000LE`.
- Do not split, merge, reclassify, rename, or repair the target page for this pass.
- Do not enter standalone `RECONSTRUCTION_CPP` for this memory item. The literal is source-use evidence for downloader call sites, not a proven shared declaration.
- No by-* documentation edit is required. No `by-memory/-coverage-report.md` direct edit was made or is required.

This is a pooled UTF-16LE downloader user-agent literal. Current IDA and PE evidence proves one physical `L"HTTPTEST"` instance and five direct absolute use sites: three FileDownloader helpers, one modeled MiniMapDownloader helper, and one raw MiniMap-side helper. The evidence supports the two source-use emitters but does not prove a single canonical declaration owner.

## Target And Scope

- Assigned UID: `0003FY`
- Target path: `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md`
- Target address range: `0x0060d7e0-0x0060d7f4`
- Prior report reviewed as historical evidence only: `tools/leaser/Agents/Agent-B002/research/executed/0003FY-SharedDownloaderUserAgentWideString-current-no-owner-research.md`
- Coverage source checked: `auto-generated/-ag-memory-coverage.md`
- Related source-use file roots checked:
  - [UID:0000JC][FileDownloader](../../../../../by-file/FileDownloader.md)
  - [UID:0000LE][MiniMap](../../../../../by-file/MiniMap.md)

## Metadata Before And After

| Field | Before | After | Change |
| --- | --- | --- | --- |
| `COMPLETION` | `88` | `88` | none |
| `CONFIDENCE` | `93` | `93` | none |
| `CANONICAL_OWNER` | `NONE` | `NONE` | none |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | none |
| `EMITTER_UIDS` | `0000JC,0000LE` | `0000JC,0000LE` | none |
| `RECONSTRUCTION_CPP` | blank | blank | none |

Score impact: unchanged at `88/93`. The score is still appropriate: evidence is strong for bytes, boundaries, and source-use routes, but not final-source quality for a named shared declaration or standalone C++ block.

## Current Generated State

Current `auto-generated/-ag-memory-coverage.md` row:

```text
| [UID:0003FY][0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString](by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md) | no-owner | `NONE` | `0000JC`,`0000LE` |  | no | `auto-generated/NexusTK/network/FileDownloader.cpp` | `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md` |  |
```

Current emitter-summary row lists both emitters:

```text
| [UID:0003FY][0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString](by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md) | `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md` | [UID:0000JC][FileDownloader](by-file/FileDownloader.md), [UID:0000LE][MiniMap](by-file/MiniMap.md) |  | `auto-generated/NexusTK/network/FileDownloader.cpp` |  |
```

The generated output paths for both emitter file roots exist:

- `auto-generated/NexusTK/network/FileDownloader.cpp`
- `auto-generated/NexusTK/map/MiniMap.cpp`

Both files are currently zero bytes because final reconstruction blocks are still blank. That is not a dead-end in `0003FY` routing; it means no standalone final C++ should be added for the literal in this pass.

## Evidence Standard Used

I treated prior reports and current docs as leads, not authority. The decision above is based on:

- current target metadata and generated coverage rows,
- current file-root and neighboring by-memory documentation,
- live IDA MCP xref/function/name evidence from the active `NexusTK.exe` IDB,
- raw PE byte and absolute-reference scans against `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515`.

No source-code owner is inferred from `.rdata` adjacency, IDA display names, or physical literal-pool grouping alone.

## Current Documentation Evidence

The target page already records the correct high-level facts:

- Range `0x0060d7e0-0x0060d7f4`.
- UTF-16LE `HTTPTEST` at `0x0060d7e0`.
- IDA display names `szAgent` at `0x0060d7e0` and `aTptest` at `0x0060d7e4`.
- `CANONICAL_OWNER:NONE`.
- `RECONSTRUCTABLE:TRUE`.
- `EMITTER_UIDS:0000JC,0000LE`.
- Five current use sites: `0x0041a773`, `0x0041aa3b`, `0x0041ae5b`, `0x00453ac3`, and raw `0x00454e52`.

Related documentation agrees with the same source-use split:

| Page | Current evidence relevant to `0003FY` |
| --- | --- |
| `by-file/FileDownloader.md` | File root [UID:0000JC] covers FileDownloader dispatch and downloader helpers under `NexusTK/network/`. |
| `by-file/MiniMap.md` | File root [UID:0000LE] covers MiniMap/MiniMapDownloader under `NexusTK/map/`. |
| `by-memory/0x0041a750-0x0041a9fe.DownloadMinimapFile.md` | FileDownloader helper uses `HTTPTEST` while downloading minimap `.mnm` files through WinINet. |
| `by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md` | FileDownloader helper uses `HTTPTEST` while downloading/parsing `itemshop.ver`. |
| `by-memory/0x0041ae20-0x0041b10c.DownloadCashShopCatalog.md` | FileDownloader helper uses `HTTPTEST` while downloading `itemshop.json`. |
| `by-memory/0x00453910-0x00453def.MiniMapDownloader.md` | MiniMapDownloader helper `sub_453AA0` uses the same user-agent literal for `.mnm` download. |
| `by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md` | Records the raw `0x00454e30-0x00455040` MiniMap-side WinINet helper and its `0x00454e52` `szAgent` reference. |
| `by-memory/0x0060d7e0-0x0060d9c0.CashShopDownloaderLiterals.md` | Non-emitting split-audit container; exact children carry concrete routing. |

## Live IDA MCP Evidence

IDA session evidence:

- Active IDB input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- IDB path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`
- Image base: `0x00400000`
- Auto-analysis ready: true
- Hex-Rays ready: true

Current `xrefs_to 0x0060d7e0` returned exactly five references:

| Reference | IDA function | Source-use route |
| --- | --- | --- |
| `0x0041a773` | `sub_41A750` | FileDownloader minimap message helper; supports emitter `0000JC`. |
| `0x0041aa3b` | `sub_41AA00` | FileDownloader item-shop version helper; supports emitter `0000JC`. |
| `0x0041ae5b` | `sub_41AE20` | FileDownloader item-shop catalog helper; supports emitter `0000JC`. |
| `0x00453ac3` | `sub_453AA0` | modeled MiniMapDownloader helper; supports emitter `0000LE`. |
| `0x00454e52` | no IDA function object | raw MiniMap-side WinINet helper; supports emitter `0000LE`. |

Function lookup checks:

| Address | Current IDA result |
| --- | --- |
| `0x0041a750` / `0x0041a773` | `sub_41A750`, size `0x2ae` |
| `0x0041aa00` / `0x0041aa3b` | `sub_41AA00`, size `0x41c` |
| `0x0041ae20` / `0x0041ae5b` | `sub_41AE20`, size `0x2ec` |
| `0x00453aa0` / `0x00453ac3` | `sub_453AA0`, size `0x2af` |
| `0x00454e30`, `0x00454e52`, `0x00455040` | not modeled as IDA functions |
| `0x0060d7e0`, `0x0060d7f4`, `0x0060d8b8`, `0x0060d94c`, `0x0060d958` | data, not functions |

Interior/tail and neighbor xref checks:

| Address | Current xref result | Conclusion |
| --- | ---: | --- |
| `0x0060d7e0` | 5 refs | complete target literal start |
| `0x0060d7e4` | 0 refs | IDA's `aTptest` display name is interior string typing, not an independent owner/split |
| `0x0060d7f2` | 0 refs | no tail reference |
| `0x0060d7f4` | 2 refs | successor [UID:0003FZ] starts here and is separately referenced |
| `0x0060d8b8` | 1 ref | later FileDownloader item-shop version URL child |
| `0x0060d94c` | 3 refs | separate shared `version` key child |
| `0x0060d958` | 1 ref | separate FileDownloader item-shop catalog URL child |

Rendered listing search for `szAgent` over the relevant code range returned exactly five hits: `0x0041a773`, `0x0041aa3b`, `0x0041ae5b`, `0x00453ac3`, and `0x00454e52`.

Hex-Rays/source-use checks:

- `sub_41A750` decompiles the WinINet open as `InternetOpenW(&szAgent, 0, 0, 0, 0)` at the FileDownloader minimap route.
- `sub_41AA00` uses the same user-agent before downloading `itemshop.ver`.
- `sub_41AE20` uses the same user-agent before downloading `itemshop.json`.
- `sub_453AA0` decompiles the same user-agent open in the modeled MiniMapDownloader path before building the minimap S3 URL.
- The raw `0x00454e30-0x00455040` body has no IDA function object and no incoming xrefs to its start, but `make_signature_for_range` produced a unique function-shaped byte signature containing `68 E0 D7 60 00` plus pushes of minimap suffix/URL/progress literals. It strengthens MiniMap-side source-use evidence without creating a new file-root emitter UID.

## Raw PE Evidence

Raw PE scan used `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

- File length: `0x28e200`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- Image base: `0x00400000`
- `.text`: VA `0x00401000`, raw `0x00000400`
- `.rdata`: VA `0x0060d000`, raw `0x0020ba00`
- Target VA `0x0060d7e0` maps to raw `0x0020c1e0`.
- Target bytes:

```text
48 00 54 00 54 00 50 00 54 00 45 00 53 00 54 00 00 00 00 00
```

Those bytes decode as UTF-16LE `HTTPTEST` followed by terminator/alignment.

Raw pattern results:

| Pattern | Hits | Result |
| --- | ---: | --- |
| full UTF-16LE `HTTPTEST` bytes | 1 | raw `0x20c1e0` / VA `0x0060d7e0` |
| `push 0x0060d7e0` bytes `68 e0 d7 60 00` | 5 | VAs `0x0041a773`, `0x0041aa3b`, `0x0041ae5b`, `0x00453ac3`, `0x00454e52` |
| absolute dword `e0 d7 60 00` | 5 | same five operand locations |
| RVA dword `e0 d7 20 00` | 0 | no RVA-form hidden route |
| interior absolute dword `e4 d7 60 00` | 0 | no independent interior use |
| tail absolute dword `f2 d7 60 00` | 0 | no tail use |
| successor absolute dword `f4 d7 60 00` | 2 | successor literal refs at VAs `0x0041a796`, `0x00453ae6` |

The raw scan matches current IDA xrefs and does not reveal a hidden owner, initializer, pointer table, RVA reference, or additional emitter route.

## Function And Child Inventory

| Range | UID | Role | Routing decision |
| --- | --- | --- | --- |
| `0x0060d7a4-0x0060d7e0` | `0003FT` | FileDownloader vtable data | Ends before `szAgent`; not merged backward into literal. |
| `0x0060d7e0-0x0060d7f4` | `0003FY` | target `HTTPTEST` wide literal | Keep `NONE`; emitters `0000JC,0000LE`. |
| `0x0060d7f4-0x0060d8b8` | `0003FZ` | minimap download literal group | Separate successor with own refs at `0x0041a794` and `0x00453ae4`; do not merge. |
| `0x0060d8b8-0x0060d94c` | `0003G0` | cash-shop version download literals | FileDownloader item-shop route; not part of the user-agent literal. |
| `0x0060d94c-0x0060d958` | `0003G1` | shared ASCII `version` key | Separate narrow string with different consumers. |
| `0x0060d958-0x0060d9c0` | `0003G2` | cash-shop catalog URL | Separate FileDownloader URL child. |
| `0x0060d7e0-0x0060d9c0` | `0003AL` | mixed literal pool container | Correctly non-emitting split-audit container. |

The target is already split at the only defensible boundaries. The interior `0x0060d7e4` IDA name does not justify a child split, and successor refs prove `0x0060d7f4` belongs to the next child.

## Owner And Emitter Reasoning

`CANONICAL_OWNER:NONE` is still correct because:

- FileDownloader has three modeled uses, but assigning FileDownloader as canonical owner would overclaim the MiniMapDownloader and raw MiniMap-side uses.
- MiniMap has one modeled use plus one raw helper use, but assigning MiniMap as canonical owner would overclaim the three FileDownloader uses.
- The physical literal pool is a mixed `.rdata` container, not a source declaration owner.
- No global pointer, initializer, vtable, RTTI record, named constant declaration, import thunk, or pointer table owns this literal.
- IDA's `szAgent` label is a useful display name, but label names are not source ownership evidence.
- A synthetic shared constants file is not proven by the binary or current documentation.

`EMITTER_UIDS:0000JC,0000LE` is still correct because:

- `0000JC` is proven by the three FileDownloader source-use contexts at `sub_41A750`, `sub_41AA00`, and `sub_41AE20`.
- `0000LE` is proven by modeled MiniMapDownloader `sub_453AA0` and raw MiniMap-side helper `0x00454e30-0x00455040`.
- The raw helper has no separate UID or function page today, so it should not create a new emitter. It is already documented as a MiniMap-side caveat and supports `0000LE`.
- No additional source-use route was found in IDA xrefs or raw PE scans.

## Dead-End And C++ Entry Analysis

Current active code-entry gate:

- `RECONSTRUCTABLE:TRUE`: yes.
- Confirmed nonblank `EMITTER_UIDS`: yes, `0000JC,0000LE`.
- Emitter roots surface to generated paths: yes, through FileDownloader and MiniMap file roots.
- Combined score: `(88 + 93) / 2 = 90.5`, above `85`.

That arithmetic clears the minimum routing gate, but final C++ entry is still not recommended for this memory item. The target is a pooled literal with no proven standalone declaration; final source should spell `L"HTTPTEST"` at each consuming call site when those functions are reconstructed. Adding a standalone C++ block here would imply a shared declaration that current evidence does not prove.

The current zero-byte generated `FileDownloader.cpp` and `MiniMap.cpp` files reflect blank reconstruction blocks, not a bad emitter UID or missing file root.

## Rejected Alternatives

| Alternative | Decision | Reason |
| --- | --- | --- |
| Assign canonical owner `0000JC` / FileDownloader | rejected | FileDownloader explains only three of five use sites. MiniMap routes are real and current. |
| Assign canonical owner `0000LE` / MiniMap | rejected | MiniMap explains the modeled and raw MiniMap-side routes, but not the FileDownloader item-shop/minimap-message routes. |
| Add a synthetic shared constants owner | rejected | No source declaration, pointer owner, or initializer evidence supports it. |
| Remove `0000LE` emitter | rejected | `sub_453AA0` and raw `0x00454e52` are MiniMap-side users. |
| Remove `0000JC` emitter | rejected | Three FileDownloader WinINet helpers use the literal directly. |
| Add another emitter | rejected | No additional file-root use route was found. The raw helper has no separate UID and remains MiniMap-side support. |
| Split at `0x0060d7e4` | rejected | No xrefs to the interior label; it is an IDA string-typing artifact. |
| Merge with successor `0003FZ` | rejected | Successor at `0x0060d7f4` has independent xrefs and distinct minimap suffix/URL literals. |
| Reclassify non-reconstructable | rejected | The literal is source-authored data used by reconstructable downloader helpers, even though it should not be emitted as standalone C++. |
| Rename/IDA-safe repair | rejected | The current docs already explain the `szAgent`/`aTptest` display split; no IDA or markdown repair is required. |

## Exact Required Edits

Required edits: none.

Do not edit `by-memory/-coverage-report.md` for correctness. Its current row is factually consistent with this pass. If the supervisor wants an attribution-refresh-only replacement, the exact replacement row would be:

```text
            - [UID:0003FY][0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString](by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md) 0x0060d7e0-0x0060d7f4 | string-data | SharedDownloaderUserAgentWideString : reconstructable : 88% : very-strong : UTF-16LE `HTTPTEST` pooled user-agent literal; B002 fresh no-owner pass on 2026-06-14 reconfirmed one physical instance at raw `0x0020c1e0` / VA `0x0060d7e0`, five direct absolute `push offset szAgent` refs into WinINet downloader helpers at `0x0041a773`, `0x0041aa3b`, `0x0041ae5b`, `0x00453ac3`, and raw MiniMap-side `0x00454e52`, no interior/tail/RVA refs, no declaration/global owner, and no split/merge/IDA-repair need; keep `CANONICAL_OWNER:NONE` while `EMITTER_UIDS:0000JC,0000LE` records the two proven source-use file roots.
```

This replacement is optional only; no shared-report change is required to make the current routing correct.

## Validation And Lease State

- Changed files: `tools/leaser/Agents/Agent-B002/research/0003FY-SharedDownloaderUserAgentWideString-fresh-no-owner-pass.md`
- Leases used: none. The only edited file is inside the Agent-B002 research folder.
- Validator: not run. No by-* documentation, generated coverage, or shared coverage files were edited.
- Dry runs: none.
- `by-memory/-coverage-report.md`: not edited.

## Final Confidence

- Recommendation confidence: high.
- Completion impact: no project documentation metadata change needed.
- Remaining future work: a separate MiniMap raw-helper pass may eventually define or split `0x00454e30-0x00455040`, but that is not required for `0003FY` and should not change this literal's owner/emitter routing without new declaration evidence.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003FY","source_path":"executed-b-agent-research/B002/0003FY-SharedDownloaderUserAgentWideString-fresh-no-owner-pass.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
