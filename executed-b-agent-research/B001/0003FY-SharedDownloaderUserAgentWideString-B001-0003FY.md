** TARGET-REPORT-UID:0003FY **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003FY **
# 0003FY SharedDownloaderUserAgentWideString Ownership / Split Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003FY][0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString](../../../../../by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md) reconstructable, parent-blank, and unsplit.
- Final disposition: confirmed source string-literal bytes, but no defensible single direct source parent. The best forced existing parent is [UID:0000JC][FileDownloader](../../../../../by-file/FileDownloader.md), but that assignment would hide real [UID:0000LE][MiniMap](../../../../../by-file/MiniMap.md) source-family consumers and overstate declaration ownership.
- Required action: no by-* documentation edits and no `by-memory/-coverage-report.md` edit are recommended. Preserve current `AUTOGEN_PARENT_UID:` blank and current `88/93` scores.
- Confidence: high for the no-assignment decision. IDA and PE scans prove the physical bytes and reference fan-out; the remaining uncertainty is source-level declaration style, specifically pooled repeated literals versus a shared constant declaration.

## Supporting Research

## Target

- Target UID: `0003FY`
- Target path: `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md`
- Source queue/report row: active `Supervisor_notes.md` row `B001-0003FY`, sourced from `auto-generated/-ag-memory-coverage.md`.
- Current supervisor classification: `reviewed-85-but-ownership-unknown-under-review`.
- Current scores and parent state: `COMPLETION:88`, `CONFIDENCE:93`, `RECONSTRUCTABLE:TRUE`, `AUTOGEN_PARENT_UID:` blank.

## Executive Recommendation

Keep the exact child parent-blank. The item is a source-declared/generated-binary UTF-16LE string literal, not a vtable, not writable storage, and not a proven named global constant. Its exact address is referenced by:

- three [UID:0000JC][FileDownloader](../../../../../by-file/FileDownloader.md) helpers: minimap, item-shop version, and item-shop catalog download;
- one [UID:0000LE][MiniMap](../../../../../by-file/MiniMap.md) helper: `MiniMapDownloader` direct minimap download;
- one raw unmodeled MiniMap-side WinINet helper at `0x00454e30-0x00455040`.

No split is needed. The range is exactly the `HTTPTEST` UTF-16LE string plus null/alignment; the successor at `0x0060d7f4` is the separate minimap literal child [UID:0003FZ][0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals](../../../../../by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md).

The exact condition that would change this recommendation is new source-level evidence proving a shared declaration, for example a PDB/linker map/object-file record, an original source reference, or a separate named/static pointer/global object that every consumer uses. Current IDA/PE evidence shows only direct `push offset szAgent` immediates to a pooled literal address.

## Supervisor Active Recheck

The supervisor asked B001 to perform deeper ownership/source-family and split-inference research for [UID:0003FY] after C001 raised the child to `88/93` but left the parent blank. This report rechecked the live IDA session `b001_nexustk`, the raw PE bytes, the coverage rows, the exact child page, sibling literal children, FileDownloader and MiniMap owner pages, and shared-literal documentation patterns.

The assigned item did not require split repair before final recommendation. The existing split is correct:

- previous exact child [UID:0003FT][FileDownloaderVtableData](../../../../../by-memory/0x0060d7a4-0x0060d7e0.FileDownloaderVtableData.md) ends at `0x0060d7e0`;
- this child covers `0x0060d7e0-0x0060d7f4`;
- sibling [UID:0003FZ][MinimapDownloadWideLiterals](../../../../../by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) starts at `0x0060d7f4`.

## Inference Research Guidance Check

`by-structure.md` requires `AUTOGEN_PARENT_UID` to point to the correct direct semantic parent, not a routing shortcut. It also allows confirmed NexusTK source data to remain `RECONSTRUCTABLE:TRUE` and unassigned when the exact source owner is not ready. `inference_research.md` warns that `.rdata` adjacency and read xrefs are insufficient to prove source-file ownership, especially when string pooling or linker deduplication can merge literals.

I treated existing documentation as hypotheses. The current docs were mostly confirmed, but I did not use their parent-blank conclusion as proof. The independent checks below revalidated byte boundaries, xrefs, raw-helper context, and absence of hidden pointer/table evidence.

## Evidence Standards Used

- IDA MCP: `idb_list`, `server_health`, `get_bytes`, `get_string`, `xrefs_to`, `lookup_funcs`, `find_bytes`, `find_xref_signatures`, `analyze_component`, `search_text`, and `insn_query`.
- Raw PE inspection: direct read-only parse of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, including PE section mapping, exact byte scan, absolute VA dword scan, RVA dword scan, and relative `.text` dword scan.
- Documentation evidence: target page, [UID:0003AL][CashShopDownloaderLiterals](../../../../../by-memory/0x0060d7e0-0x0060d9c0.CashShopDownloaderLiterals.md), sibling literal children, FileDownloader and MiniMap by-file/by-class pages, FileDownloader dispatch aggregate, and proposed source tree.
- Negative evidence: no xrefs to interior/tail labels, no hidden absolute/RVA/relative references, no separate by-global storage, no single function/class/file that semantically owns every observed use.

## IDA MCP Facts

Function/range facts:

- Active session: `b001_nexustk` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- `lookup_funcs` maps `0x0041a773` to `sub_41A750` (`0x0041a750-0x0041a9fe`), `0x0041aa3b` to `sub_41AA00` (`0x0041aa00-0x0041ae1c`), `0x0041ae5b` to `sub_41AE20` (`0x0041ae20-0x0041b10c`), and `0x00453ac3` to `sub_453AA0` (`0x00453aa0-0x00453d4f`).
- `lookup_funcs` reports `0x00454e52`, `0x00454e30`, and `0x00455040` are not IDA functions. The following modeled functions start at `0x00455050`, `0x00455060`, and `0x004550d0`.

Data/table/padding facts:

- `get_bytes` over `0x0060d7d0-0x0060d8d0` shows the previous vtable tail through `0x0060d7df`, then UTF-16LE bytes for `HTTPTEST`, four zero bytes, and the successor minimap strings.
- IDA `get_string` at `0x0060d7e0` returns only `H` because IDA split the string head as `szAgent` and `aTptest`; direct bytes and PE scan prove the full UTF-16LE `HTTPTEST` sequence begins at `0x0060d7e0`.
- `xrefs_to 0x0060d7e4` and `xrefs_to 0x0060d7f2` return zero xrefs. These are interior/tail artifacts, not independent literals.
- `xrefs_to 0x0060d7f4` returns only `0x0041a794` and `0x00453ae4`, both minimap download consumers, proving the successor child begins separately.

Xref facts:

| Target | Xrefs | Meaning |
| --- | --- | --- |
| `0x0060d7e0` | `0x0041a773`, `0x0041aa3b`, `0x0041ae5b`, `0x00453ac3`, raw `0x00454e52` | Five user-agent refs across FileDownloader, MiniMapDownloader, and raw MiniMap-side code. |
| `0x0060d7e4` | none | Interior `aTptest` label is not independently referenced. |
| `0x0060d7f2` | none | Terminator/alignment tail is not independently referenced. |
| `0x0060d7f4` | `0x0041a794`, `0x00453ae4` | Successor minimap literal child, not part of `HTTPTEST`. |
| `0x0060d8b8` | `0x0041aa64` | Separate item-shop version URL child. |

Raw MiniMap-side facts:

- `search_text` over `0x00454e30-0x00455040` finds `.text:00454E52 push offset szAgent`.
- The same raw range contains `.text:00454E6F push offset aMnm`, `.text:00454E7B push offset aHttpsS3Amazona`, and `.text:00454FCC push offset aDownloadingD`.
- The same raw range calls `InternetOpenW` at `0x00454e5d`, `InternetOpenUrlW` at `0x00454ea9`, and `WriteFile` at `0x00454fb5`.
- `insn_query` confirms the raw helper returns at `0x00455040` and aligns at `0x00455041`.
- `xrefs_to 0x00454e30` reports no incoming references. This keeps the raw helper as a MiniMap-side consumer caveat rather than a currently callable, parentable source child.

Component facts:

`analyze_component` over `0x0041a750`, `0x0041aa00`, `0x0041ae20`, and `0x00453aa0` reports shared global/string use of `szAgent` by all four modeled downloader helpers. It reports the minimap successor literals (`0x0060d7f4`, `0x0060d7f8`, `0x0060d7fc`, `0x0060d808`, `0x0060d818`, `0x0060d880`, `0x0060d894`) as shared only by `sub_41A750` and `sub_453AA0`, and reports item-shop progress/global state separately. That pattern supports the current split: `HTTPTEST` is broader than the minimap literals and broader than the FileDownloader-only item-shop URL literals.

PE byte/pointer facts:

- PE identity: md5 `4247e04e20b65d6414c7238aa8ff5515`, sha256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`, image base `0x00400000`.
- Sections: `.text` at `0x00401000`, `.rdata` at `0x0060d000`, `.data` at `0x0066d000`, `.rsrc` at `0x0069d000`.
- Exact UTF-16LE `HTTPTEST` plus terminator/alignment pattern appears once, at file offset `0x20c1e0` / VA `0x0060d7e0`.
- Absolute VA dword hits for `0x0060d7e0` appear only at file offsets/addresses corresponding to the five IDA xref immediates: `0x0041a774`, `0x0041aa3c`, `0x0041ae5c`, `0x00453ac4`, and `0x00454e53`.
- Absolute VA dword hits for `0x0060d7e4` and `0x0060d7f2` are empty.
- RVA dword hits for all checked target/sibling addresses are empty.
- Relative `.text` dword hits for `0x0060d7e0`, `0x0060d7f4`, and `0x0060d8b8` are empty.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0060d7e0-0x0060d7f4` | [UID:0003FY](../../../../../by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md) | Shared UTF-16LE `HTTPTEST` user-agent literal | TRUE | blank | `88/93` | Keep parent blank. |
| `0x0060d7e0-0x0060d9c0` | [UID:0003AL](../../../../../by-memory/0x0060d7e0-0x0060d9c0.CashShopDownloaderLiterals.md) | Non-emitting mixed literal split-audit container | FALSE | blank | `89/92` | Correct container; not a direct source owner. |
| `0x0060d7f4-0x0060d8b8` | [UID:0003FZ](../../../../../by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md) | Minimap URL/suffix/progress literals | TRUE | blank | `89/93` | Shared FileDownloader/MiniMap literals. |
| `0x0060d8b8-0x0060d94c` | [UID:0003G0](../../../../../by-memory/0x0060d8b8-0x0060d94c.CashShopVersionDownloadWideLiterals.md) | Item-shop version URL/progress literals | TRUE | `0000JC` | `86/91` | FileDownloader-only enough to assign. |
| `0x0060d94c-0x0060d958` | [UID:0003G1](../../../../../by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md) | Shared narrow `version` key | TRUE | blank | `88/93` | Shared FileDownloader/FittingRoom/StartupWindow literal. |
| `0x0060d958-0x0060d9c0` | [UID:0003G2](../../../../../by-memory/0x0060d958-0x0060d9c0.CashShopCatalogDownloadWideUrl.md) | Item-shop catalog URL | TRUE | `0000JC` | `86/92` | FileDownloader-only enough to assign. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0041a773` | `sub_41A750` / [UID:0002TR][DownloadMinimapFile](../../../../../by-memory/0x0041a750-0x0041a9fe.DownloadMinimapFile.md) | FileDownloader-dispatched minimap download helper opens WinINet with `HTTPTEST`. |
| `0x0041aa3b` | `sub_41AA00` / [UID:0002TS][DownloadCashShopVersion](../../../../../by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md) | FileDownloader-dispatched item-shop version helper opens WinINet with `HTTPTEST`. |
| `0x0041ae5b` | `sub_41AE20` / [UID:0002TT][DownloadCashShopCatalog](../../../../../by-memory/0x0041ae20-0x0041b10c.DownloadCashShopCatalog.md) | FileDownloader-dispatched item-shop catalog helper opens WinINet with `HTTPTEST`. |
| `0x00453ac3` | `sub_453AA0` inside [UID:0000XN][MiniMapDownloader](../../../../../by-memory/0x00453910-0x00453def.MiniMapDownloader.md) | MiniMapDownloader direct worker helper opens WinINet with the same `HTTPTEST` literal. |
| `0x00454e52` | Raw body `0x00454e30-0x00455040` inside [UID:0000XO][MiniMapRendererAndControls](../../../../../by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md) caveat | Unmodeled MiniMap-side WinINet/file-download helper also pushes `szAgent`. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:0003FY] already records the correct bytes, xref set, raw MiniMap-side helper context, and parent-blank rationale. Live IDA/PE checks confirm those claims.
- [UID:0003AL] records this area as a non-emitting split-audit literal pool. Live IDA confirms the exact child split and mixed consumer families.
- [UID:0003FZ] mirrors the same shared-literal blocker for minimap successor strings. Live IDA confirms its xrefs are a narrower FileDownloader/MiniMap subset plus raw MiniMap refs.
- [UID:0003G1] documents another shared pooled literal (`version`) left parent-blank because three source families consume the same physical bytes. This is a directly relevant local documentation pattern.
- [UID:0000JC][FileDownloader] is a strong owner for FileDownloader dispatch code and FileDownloader-only item-shop literal children, but it explicitly cross-links the `HTTPTEST` child as unassigned.
- [UID:0000LE][MiniMap] and [UID:00008D][MiniMapDownloader] confirm the MiniMap direct worker helper is real minimap source-family code, not FileDownloader code.

Existing docs that are stale, incomplete, or contradicted:

- No material contradiction found for this target.
- The IDA split label `aTptest` is a misleading interior label. The target page already documents it as an IDA artifact and live xrefs/PE scan confirm no independent pointer to `0x0060d7e4`.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` currently reports [UID:0003FY] as `unassigned`, which is correct.
- `by-memory/-coverage-report.md` currently nests [UID:0003FY] under [UID:0003AL] with parent-blank rationale, which is correct.

## Ranked Ownership Analysis

### 1. Keep parent blank as a pooled/shared source literal

Evidence for:

- One physical string instance has five refs across two source families.
- No hidden absolute/RVA/relative references, no pointer table, and no separate storage object were found.
- The observed instructions are immediate pushes of the literal address, not loads through a named constant pointer/global.
- Existing shared-literal precedents in this project keep parent blank when real consumers cross source-family boundaries and no single declaration owner is proven.

Evidence against:

- A real original project could have had one shared constant declaration such as `static const wchar_t *kUserAgent = L"HTTPTEST";` in a common downloader header or source file.
- FileDownloader has the majority of modeled xrefs and is the network/downloader owner for three of the four modeled helper functions.

Decision:

Accepted. This is the only recommendation that does not overclaim source declaration ownership. It preserves reconstructability while avoiding a false parent relationship.

### 2. [UID:0000JC] FileDownloader / `network/FileDownloader.cpp`

Evidence for:

- Three modeled xrefs are FileDownloader-dispatched helper bodies.
- The FileDownloader source page owns the dispatcher, message IDs, request singleton lifetime, and FileDownloader-only item-shop literal children.
- The `HTTPTEST` literal immediately follows FileDownloader vtable data at `0x0060d7a4-0x0060d7e0`.
- If forced to pick an existing by-file parent, FileDownloader is the strongest candidate.

Evidence against:

- `0x00453ac3` is in `MiniMapDownloader` source-family code attached to [UID:0000LE][MiniMap].
- `0x00454e52` is a raw MiniMap-side WinINet helper near MiniMap renderer/control code.
- The sibling [UID:0003FZ] minimap literal child shows the same FileDownloader/MiniMap split with raw MiniMap refs.
- `.rdata` adjacency to the FileDownloader vtable is weak evidence because the same literal pool immediately contains mixed-owner minimap, item-shop, and shared `version` literals.
- Assigning this exact physical string to FileDownloader would claim FileDownloader authored the source declaration for every use, which is not supported.

Decision:

Rejected for actual parent assignment. Record as the best forced candidate only.

### 3. [UID:0000LE] MiniMap / `map/MiniMap.cpp` or `map/MiniMapDownloader.cpp`

Evidence for:

- One modeled xref is in [UID:0000XN][MiniMapDownloader].
- One raw xref is in a MiniMap-side WinINet helper body.
- The successor minimap literal child has MiniMap-specific URLs/suffix/progress strings and raw MiniMap refs.

Evidence against:

- Three modeled refs are FileDownloader-dispatched helpers, including non-minimap cash-shop version/catalog download helpers.
- `HTTPTEST` is broader than the minimap URL/suffix/progress group.
- MiniMap ownership would hide FileDownloader item-shop helper use even more than FileDownloader ownership hides MiniMap use.

Decision:

Rejected.

### 4. [UID:0003AL] CashShopDownloaderLiterals mixed container

Evidence for:

- [UID:0003FY] is nested physically under this split-audit container.
- The container covers the exact literal neighborhood.

Evidence against:

- [UID:0003AL] is explicitly `RECONSTRUCTABLE:FALSE` and parent-blank because it is a mixed non-emitting literal inventory.
- It has no source-level owner semantics. Its exact children carry real reconstruction routing.

Decision:

Rejected as a direct parent.

### 5. New shared owner, such as `DownloaderHttpConstants` or `network/DownloaderSharedLiterals`

Evidence for:

- A shared `HTTPTEST` user-agent constant is plausible source design.
- A future reconstruction might prefer one constant to avoid repeated string spellings.

Evidence against:

- There is no separate storage object, pointer global, relocation table, initialization site, destructor, or named source symbol beyond IDA's `szAgent` label.
- The byte pattern appears once and every reference is a direct immediate operand, which is also exactly what compiler/linker string pooling produces.
- A broad new constants file would need to consider `HTTPTEST`, minimap literals, item-shop URLs, progress strings, and the `version` key. Those adjacent items have different proven or blocked owners: FileDownloader-only children `0003G0`/`0003G2`, shared minimap child `0003FZ`, and shared FileDownloader/FittingRoom/StartupWindow key `0003G1`.
- Creating a new source owner now would make a documentation fiction out of a linker-pooling artifact unless later source evidence proves the shared declaration.

Decision:

Rejected for now. If future final-source work chooses a convenience constant, that should be a source-reconstruction design decision, not an `AUTOGEN_PARENT_UID` claim for this physical by-memory child.

## Proposed New File/Grouping, If It Were Later Proven

Proposed owner/name/path if future evidence appears:

- Possible file/header: `NexusTK/network/DownloaderHttpConstants.h` or private constants inside `NexusTK/network/FileDownloader.cpp`.
- Narrow possible contents: a `HTTPTEST` user-agent constant used by FileDownloader and MiniMap download helpers.
- Broader candidate contents to evaluate: minimap `.mnm` suffix/S3 URL/progress literals, item-shop version/catalog URLs, item-shop progress format, and maybe the `version` key.

Candidate related items that would need re-evaluation before creating such a file:

- [UID:0003FZ][MinimapDownloadWideLiterals](../../../../../by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md): shared FileDownloader/MiniMap minimap constants; plausible if a shared downloader-minimap source exists.
- [UID:0003G0][CashShopVersionDownloadWideLiterals](../../../../../by-memory/0x0060d8b8-0x0060d94c.CashShopVersionDownloadWideLiterals.md): currently FileDownloader-owned; should not move unless source evidence shows a broad constants file.
- [UID:0003G1][SharedVersionJsonKey](../../../../../by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md): broader than downloader, because it also spans FittingRoom and StartupWindow.
- [UID:0003G2][CashShopCatalogDownloadWideUrl](../../../../../by-memory/0x0060d958-0x0060d9c0.CashShopCatalogDownloadWideUrl.md): currently FileDownloader-owned; no evidence of shared declaration.

Current inference:

Do not create this file/grouping. The candidate owner would be broad and artificial without proof that the original source used a shared constants module rather than repeated literals pooled by MSVC/linker behavior.

## Negative Evidence Summary

- No xrefs to `0x0060d7e4` or `0x0060d7f2`.
- No extra absolute VA dword references to `0x0060d7e0` beyond the five IDA xrefs.
- No RVA dword references for the checked target and sibling addresses.
- No relative `.text` dword references to `0x0060d7e0`, `0x0060d7f4`, or `0x0060d8b8`.
- No by-global page or documented storage slot for a user-agent constant.
- No function owns all use sites.
- No caller chain folds MiniMapDownloader into FileDownloader.
- No caller/xref to raw helper start `0x00454e30`; the raw body strengthens MiniMap-side consumer evidence but cannot establish a shared declaration owner.
- IDA's `szAgent` name is useful for locating xrefs, but it is not original source proof.
- Address adjacency to FileDownloader vtable data is weaker than the cross-family xrefs and the known mixed-literal pool around it.

## Final Recommendation

Exact changes applied or recommended:

- Created this B001 research report only.
- No by-memory page edit is recommended.
- No split, rename, reclassification, or score change is recommended.

Exact parent assignments applied or recommended:

- Keep `AUTOGEN_PARENT_UID:` blank in [UID:0003FY].
- Do not assign to [UID:0000JC][FileDownloader], [UID:0000LE][MiniMap], [UID:0003AL][CashShopDownloaderLiterals], or a new shared constants owner.

Exact items left unassigned and why:

- [UID:0003FY] remains unassigned because its physical string bytes are shared by FileDownloader and MiniMap source families, and current evidence cannot distinguish a source-level shared constant from compiler/linker pooled repeated local literals.

Exact future work outside this assignment:

- If a later pass defines the raw `0x00454e30-0x00455040` helper as a function, document it separately under MiniMap-side support, but do not use that alone to assign [UID:0003FY].
- If source/debug/linker-map evidence appears, re-evaluate whether a real shared user-agent constant declaration existed.
- During final reconstruction, repeated local `L"HTTPTEST"` source literals are safer than a synthetic global until shared-declaration evidence exists. A shared constant can be introduced as an engineering cleanup only after documenting that it is a reconstruction choice rather than proven original ownership.

## Coverage / Supervisor Rows

No coverage-report replacement is required. If the supervisor wants an explicit no-op row, leave the current `by-memory/-coverage-report.md` row exactly as:

```text
            - [UID:0003FY][0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString](by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md) 0x0060d7e0-0x0060d7f4 | string-data | SharedDownloaderUserAgentWideString : reconstructable : 88% : very-strong : UTF-16LE `HTTPTEST` user-agent literal; C001-013 live IDA reconfirmed xrefs from FileDownloader minimap/version/catalog helpers, MiniMapDownloader, and raw MiniMap-side helper body `0x00454e30-0x00455040`; parent blank because no single direct source owner covers every use.
```

No `auto-generated/-ag-memory-coverage.md` edit is recommended. The current generated row is correct:

```text
| [UID:0003FY][0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString](by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md) | unassigned |  |  | no |  | `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md` |  |
```

## Follow-Up Actions

Supervisor actions:

- Mark B001-0003FY reviewed/no-op if this recommendation is accepted.
- Do not edit `by-memory/-coverage-report.md` for this target.

A-agent actions:

- None needed for the target page.

B001 future research actions:

- None for this target unless new source/debug evidence appears or the supervisor assigns the raw `0x00454e30-0x00455040` MiniMap-side helper as a separate split/owner target.

## Confidence

- Recommendation confidence: high. The no-parent decision is strongly supported by live IDA xrefs, raw-helper evidence, PE pointer scans, and local shared-literal documentation rules.
- Score confidence: current `88/93` is justified. I do not recommend raising above `93` because original declaration placement remains unresolved.
- Remaining uncertainty: original source could have used a shared constant declaration, but the binary evidence cannot prove it.

## Validator Results

- Command run:

> Executable block R001 was removed from this report and preserved verbatim in [0003FY-SharedDownloaderUserAgentWideString-B001-0003FY-removed.md](0003FY-SharedDownloaderUserAgentWideString-B001-0003FY-removed.md). The archived block is non-authoritative and must not be executed.

- Result: exit `0`, `ok: 1`, target UID header exists. Dry run only; no files were changed. Autogen reports were `noop`.
- Any unresolved validator warnings/errors: none material to this target. The dry run printed one existing `autogen_parent_has_no_code 00000D by-class/Application.md` line outside this target.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0003FY-SharedDownloaderUserAgentWideString-B001-0003FY.md`
- Modified: none outside the report file.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003FY","source_path":"executed-b-agent-research/B001/0003FY-SharedDownloaderUserAgentWideString-B001-0003FY.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
