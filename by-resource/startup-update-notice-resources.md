*** UID:0001RO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Startup Update Notice Resources

## Status

- Confidence: very strong for resource names, startup owner, local PCX use, URL roles, registry/minimap routing, and current `baramst.dat` payload provenance.
- Owner module: [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- Main memory evidence: [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md)

## Local PCX Assets

| Resource | Use |
| --- | --- |
| `brm_main.pcx` | Background for the pre-game update/news notice window. |
| `brm_st_a.pcx` | Start/update button default image. |
| `brm_st_b.pcx` | Start/update button hover image. |
| `brm_st_c.pcx` | Start/update button pressed image. |
| `brm_ex_a.pcx` | Close/exit button default image. |
| `brm_ex_b.pcx` | Close/exit button pressed image. |

`StartupWindow::UpdateCheckWindowProc` loads these with [UID:0000UZ][LoadPcxImage_004A17B0](by-item/LoadPcxImage_004A17B0.md) on first paint. Raw disassembly/local PE reanalysis also shows an unmodeled helper at `0x005818d0-0x005819cc` that performs the same lazy asset load and button-bound initialization; the corrected half-open range includes the final `ret 4`.

## Remote Update Data

| URL | Use |
| --- | --- |
| `https://s3.amazonaws.com/kru-downloads/tk/update/nexustk.ver` | Update metadata containing at least `version` and `minimap` keys. |
| `https://s3.amazonaws.com/kru-downloads/tk/minimaps/HashList.txt` | Minimap hash-list data fetched when the remote minimap version differs from the local manager version. |
| `http://www.nexustk.com/news/news.asp` | Browser-hosted news panel shown inside the notice window. |
| `http://www.nexustk.com` | Clickable top banner/link rectangle in the notice WndProc. |

## Registry State

`StartupWindow::RunUpdateCheck` reads `HKEY_CURRENT_USER\Software\KRU\NexusTK`, value `updvr`, as a `REG_DWORD`. The value string lives at `0x0062d49c` in [UID:00026K][0x0062d418-0x0062d5a8.StartupWindowReadOnlyData](by-memory/0x0062d418-0x0062d5a8.StartupWindowReadOnlyData.md), and the value is compared against the remote `version` field to decide whether the updater is required.

## Package Provenance

2026-06-14 A002 parsed the documented DAT entry table format across `E:\2026\Resources\Read_Only\NexusTK\Data` and checked the read-only client tree for loose duplicates. The six local notice PCX assets are current `baramst.dat` entries; the URL and registry strings remain source/runtime inputs rather than DAT payloads.

| Resource | Package evidence | Payload evidence |
| --- | --- | --- |
| `brm_ex_a.pcx` | `baramst.dat`, entry index `0`, offset `191`, size `1,538`; no loose duplicate found in the read-only tree. | PCX-like header begins `0a 05 01 08`. |
| `brm_ex_b.pcx` | `baramst.dat`, entry index `1`, offset `1,729`, size `1,546`; no loose duplicate found in the read-only tree. | PCX-like header begins `0a 05 01 08`. |
| `brm_main.pcx` | `baramst.dat`, entry index `2`, offset `3,275`, size `262,537`; no loose duplicate found in the read-only tree. | PCX-like header begins `0a 05 01 08` with max-coordinate bytes consistent with the large notice background. |
| `brm_st_a.pcx` | `baramst.dat`, entry index `7`, offset `275,604`, size `8,821`; no loose duplicate found in the read-only tree. | PCX-like header begins `0a 05 01 08`. |
| `brm_st_b.pcx` | `baramst.dat`, entry index `8`, offset `284,425`, size `8,602`; no loose duplicate found in the read-only tree. | PCX-like header begins `0a 05 01 08`. |
| `brm_st_c.pcx` | `baramst.dat`, entry index `9`, offset `293,027`, size `8,505`; no loose duplicate found in the read-only tree. | PCX-like header begins `0a 05 01 08`. |

`baramst.dat` also contains adjacent `brm_n_a/b` and `brm_o_a/b` entries at indexes `3` through `6`; those are not promoted into this page's resource set because the documented WndProc evidence only proves the six `brm_main`, `brm_st_*`, and `brm_ex_*` loads.

## Resource Role Matrix

| Resource group | Consumer path | Rebuild handling |
| --- | --- | --- |
| Notice window PCX art | `StartupWindow::UpdateCheckWindowProc` and raw notice asset loader `0x005818d0-0x005819cc` | Package the six `brm_*.pcx` files as local startup notice art loaded through [UID:0000UZ][LoadPcxImage_004A17B0](by-item/LoadPcxImage_004A17B0.md). |
| Embedded news/browser URL | `StartupWindow::RunUpdateCheck` constructs a browser panel for `http://www.nexustk.com/news/news.asp` | Preserve as startup source string/configuration; browser hosting remains [UID:0000HV][Browser](by-file/Browser.md) behavior. |
| Remote update metadata URL | `StartupWindow::RunUpdateCheck` fetches `nexustk.ver` with libcurl and parses `version` / `minimap` fields | Preserve the URL and parser keys in startup source; curl callback glue remains StartupWindow-owned, while libcurl stays external. |
| Remote minimap hash URL | `StartupWindow::RunUpdateCheck` fetches `HashList.txt` when the remote minimap value differs | Treat as startup/minimap synchronization input; persisted hash-list ownership remains [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md). |
| Registry update version | `HKCU\Software\KRU\NexusTK\updvr` | Preserve the key/value names and `REG_DWORD` comparison logic as startup source behavior, not DAT/resource packaging. |
| Top banner URL | `StartupWindow::UpdateCheckWindowProc` opens `http://www.nexustk.com` for the clickable notice rectangle | Preserve as a startup notice link string; link launch/browser mechanics stay outside the resource page. |

## Rebuild Packaging Boundary

- Ship the six PCX files as local startup notice assets and keep PCX decoding in [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md).
- Keep the four URL strings and the registry key/value as source-level constants or equivalent configuration in `StartupWindow.cpp`.
- Keep libcurl response buffering in [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md), not in third-party libcurl source.
- Keep minimap hash-list parsing and persistence with [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md); this page only records the startup fetch trigger and remote resource.
- Do not treat the raw notice helper island as final source shape. [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) still records raw helper boundary debt.

## Scope Boundaries

- This page covers startup notice assets and remote/local update inputs. It does not cover application DAT preload archives, startup logo media, or normal login/main-menu resources.
- The PCX assets are startup-window local art, not part of the later EPF/EPD resource layout table.
- The URLs are historically observed client endpoints. Their current network availability or server behavior is outside this reconstruction page.

## Open Questions

- Original source spelling for button rectangle/state fields and any adjacent notice-state art beyond the six proven PCX loads. Exact helper pages now carry the promoted behavior, including UID0004D1 for the asset loader, but resource-level naming remains a confidence cap.
- Whether the remote `nexustk.ver` payload has fields beyond `version` and `minimap` that affect behavior.
- Whether adjacent `baramst.dat` entries `brm_n_a/b` and `brm_o_a/b` belong to another startup/update-notice state; current exact helper pages prove only the six `brm_main`, `brm_st_*`, and `brm_ex_*` loads.

## IDA MCP Evidence

- ASCII PCX literals were verified at `0x0062d530` (`brm_main.pcx`), `0x0062d540` (`brm_st_a.pcx`), `0x0062d550` (`brm_st_b.pcx`), `0x0062d560` (`brm_st_c.pcx`), `0x0062d570` (`brm_ex_a.pcx`), and `0x0062d580` (`brm_ex_b.pcx`).
- Those PCX literals have xrefs from `0x00581100-0x005815aa`, matching the update-notice window procedure, plus adjacent unmodeled asset-load references around corrected raw helper range `0x005818d0-0x005819cc`.
- ASCII `https://s3.amazonaws.com/kru-downloads/tk/update/nexustk.ver` was verified at `0x0062d4a8` and is referenced from `0x00580c49` inside `StartupWindow__RunUpdateCheck` at `0x00580870-0x005810fd`.
- ASCII `https://s3.amazonaws.com/kru-downloads/tk/minimaps/HashList.txt` was verified at `0x0062d4f0` and is referenced from `0x00580ed5` inside the same update-check function.
- ASCII `http://www.nexustk.com/news/news.asp` at `0x0062d474` is referenced from `0x00580b3e` in `StartupWindow__RunUpdateCheck`; ASCII `http://www.nexustk.com` at `0x0062d590` is referenced from `0x00581583` in the update-notice WndProc.
- Wide string `L"updvr"` was verified at `0x0062d49c` in [UID:00026K][0x0062d418-0x0062d5a8.StartupWindowReadOnlyData](by-memory/0x0062d418-0x0062d5a8.StartupWindowReadOnlyData.md) and is referenced from `0x00580bde` in `StartupWindow__RunUpdateCheck`.
- 2026-06-14 IDA MCP refresh in IDB `a001_goal2_class_batch` confirmed function bounds for `0x00580870` (`sub_580870`, update-check orchestration), `0x00581100` (`sub_581100`, update notice WndProc), `0x00581b80` (`sub_581B80`, curl write callback), and `0x005807d0` (`sub_5807D0`, nearby startup helper). Address `0x005818d0` is still not an IDA function, so the raw helper-island caveat remains.
- Decompilation of `0x00580870` confirms the startup update window class uses `sub_581100` as WndProc, creates a `500x430` notice window, constructs the embedded browser panel from `http://www.nexustk.com/news/news.asp`, reads `HKCU\Software\KRU\NexusTK\updvr`, fetches `nexustk.ver` through libcurl, parses `version` and `minimap`, and conditionally fetches `HashList.txt` for minimap synchronization.
- Decompilation of `0x00581100` confirms the lazy first-paint load of `brm_main.pcx`, `brm_st_a.pcx`, `brm_st_b.pcx`, `brm_st_c.pcx`, `brm_ex_a.pcx`, and `brm_ex_b.pcx` through [UID:0000UZ][LoadPcxImage_004A17B0](by-item/LoadPcxImage_004A17B0.md), plus button-state drawing and `ShellExecuteA` launch of `http://www.nexustk.com`.
- 2026-06-21 B010 local PE/Capstone reanalysis corrected the raw asset-loader endpoint from `0x005819c9` to `0x005819cc` and records `0x005819cc-0x005819d0` as padding before the raw alternate notice setup helper. The same pass keeps adjacent `brm_n_*`/`brm_o_*` assets excluded because no StartupWindow helper ref proves them today.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `88` | The page separates local PCX notice assets, embedded browser/news URL, remote update metadata, minimap hash-list fetch, registry state, top-banner URL roles, rebuild packaging boundaries, scope caveats, and raw helper debt, with refreshed decompilation for the WndProc/update-check orchestration plus exact `baramst.dat` package rows for all six local PCX payloads. Completion remains capped because exact raw-helper promotion, button rectangle naming, full remote payload schema, and adjacent `baramst.dat` state-art ownership are still open. |
| Confidence `92` | Current IDA string/xref checks, decompilation, and DAT payload inspection strongly identify the local assets, remote URLs, registry key/value, libcurl/minimap route, package location, PCX payload type, and StartupWindow/ImageLoaders/Browser ownership split. Confidence is capped by the unpromoted raw helper island and server-payload schema uncertainty. |

## Cross-References

- [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- [UID:0001QM][client_s1-startup](by-meta/client_s1-startup.md)
- [UID:0001QE][client_libraries](by-meta/client_libraries.md)
- [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)

## Changes

- 2026-07-04 B004 UID0004D1 support sync:
  - Scores unchanged at `88/92`.
  - Historicalized the stale open-question wording that waited for raw helper promotion: [UID:0004D1][0x005818d0-0x005819cc.StartupNoticeLoadAssets](by-memory/0x005818d0-0x005819cc.StartupNoticeLoadAssets.md) now carries direct `88/91` source-quality evidence for the six proven PCX loads and button-bound initialization, while resource-level exact original field/art-state naming remains the remaining caveat.
- What existed before: the page listed resources but was scored unevaluated and contained generated-source wording in the PCX loading note.
- Changed to: scored `COMPLETION:75` / `CONFIDENCE:88`, removed generated-source dependency wording, and added IDA MCP literal/xref evidence for local PCX assets and remote URLs.
- Summary and evidence: IDA xrefs connect the PCX assets to the update-notice WndProc and the URLs to `StartupWindow__RunUpdateCheck`; score remains below final because registry/update structure fields and all helper internals are not exhaustively documented here.
- 2026-06-07 A002 resource-boundary pass: Raised completion from `75/88` to `78/88`.
  - Before: the page listed PCX assets, URLs, and registry state but did not separate local art, browser content, remote update/minimap metadata, registry comparison, and raw-helper boundaries.
  - After: it records a resource role matrix, rebuild packaging boundary, scope boundaries, open questions, and the current-session IDA availability caveat.
- 2026-06-14 A002 Goal2 by-resource score pass:
  - What existed before: `COMPLETION:78` / `CONFIDENCE:88` included a stale note that IDA MCP was unavailable during the prior pass.
  - Changed to: `COMPLETION:85` / `CONFIDENCE:90` after live IDA MCP rechecked the PCX and URL xrefs, update-check function bounds, WndProc lazy asset loading, registry/libcurl/minimap route, and top-banner link launch.
  - Remaining below gate: exact raw helper promotion, button rectangle naming, full remote metadata schema, and installer/package provenance remain open.
- 2026-06-14 A002 package provenance pass:
  - Before: `COMPLETION:85`, `CONFIDENCE:90`, with PCX runtime identity proven but local payload packaging unresolved.
  - After: raised to `COMPLETION:88`, `CONFIDENCE:92`, with exact `baramst.dat` entries for the six documented PCX assets, payload sizes/offsets, PCX header evidence, no loose duplicates in the read-only tree, and adjacent `brm_n_*`/`brm_o_*` package entries left out until a future helper-state audit proves ownership.
- 2026-06-17 B001 read-only-data sync:
  - Scores unchanged at `88/92`.
  - Added the exact `0x0062d49c` [UID:00026K][0x0062d418-0x0062d5a8.StartupWindowReadOnlyData](by-memory/0x0062d418-0x0062d5a8.StartupWindowReadOnlyData.md) address for the `updvr` registry value string.
- 2026-06-21 B010 source-quality sync:
  - Scores unchanged at `88/92`.
  - Corrected the raw notice asset-loader range to `0x005818d0-0x005819cc`, preserving the PCX ownership boundary and excluding adjacent unproven `brm_n_*`/`brm_o_*` package entries.
