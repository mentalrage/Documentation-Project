*** UID:0001RO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Startup Update Notice Resources

## Status

- Confidence: strong for resource names and startup owner.
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

`StartupWindow::UpdateCheckWindowProc` loads these with [UID:0000UZ][LoadPcxImage_004A17B0](by-item/LoadPcxImage_004A17B0.md) on first paint. IDA raw disassembly also shows an unmodeled helper at `0x005818d0-0x005819c9` that performs the same lazy asset load and button-bound initialization.

## Remote Update Data

| URL | Use |
| --- | --- |
| `https://s3.amazonaws.com/kru-downloads/tk/update/nexustk.ver` | Update metadata containing at least `version` and `minimap` keys. |
| `https://s3.amazonaws.com/kru-downloads/tk/minimaps/HashList.txt` | Minimap hash-list data fetched when the remote minimap version differs from the local manager version. |
| `http://www.nexustk.com/news/news.asp` | Browser-hosted news panel shown inside the notice window. |
| `http://www.nexustk.com` | Clickable top banner/link rectangle in the notice WndProc. |

## Registry State

`StartupWindow::RunUpdateCheck` reads `HKEY_CURRENT_USER\Software\KRU\NexusTK`, value `updvr`, as a `REG_DWORD`. The value is compared against the remote `version` field to decide whether the updater is required.

## Resource Role Matrix

| Resource group | Consumer path | Rebuild handling |
| --- | --- | --- |
| Notice window PCX art | `StartupWindow::UpdateCheckWindowProc` and raw notice asset loader `0x005818d0-0x005819c9` | Package the six `brm_*.pcx` files as local startup notice art loaded through [UID:0000UZ][LoadPcxImage_004A17B0](by-item/LoadPcxImage_004A17B0.md). |
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

- Exact button rectangles and visual-state mapping for the raw notice helper island once it is promoted into exact function pages.
- Whether the remote `nexustk.ver` payload has fields beyond `version` and `minimap` that affect behavior.
- Installer/package provenance for the six local PCX files.

## IDA MCP Evidence

- ASCII PCX literals were verified at `0x0062d530` (`brm_main.pcx`), `0x0062d540` (`brm_st_a.pcx`), `0x0062d550` (`brm_st_b.pcx`), `0x0062d560` (`brm_st_c.pcx`), `0x0062d570` (`brm_ex_a.pcx`), and `0x0062d580` (`brm_ex_b.pcx`).
- Those PCX literals have xrefs from `0x00581100-0x005815aa`, matching the update-notice window procedure, plus adjacent unmodeled asset-load references around `0x005818d0-0x005819c9`.
- ASCII `https://s3.amazonaws.com/kru-downloads/tk/update/nexustk.ver` was verified at `0x0062d4a8` and is referenced from `0x00580c49` inside `StartupWindow__RunUpdateCheck` at `0x00580870-0x005810fd`.
- ASCII `https://s3.amazonaws.com/kru-downloads/tk/minimaps/HashList.txt` was verified at `0x0062d4f0` and is referenced from `0x00580ed5` inside the same update-check function.
- ASCII `http://www.nexustk.com/news/news.asp` at `0x0062d474` is referenced from `0x00580b3e` in `StartupWindow__RunUpdateCheck`; ASCII `http://www.nexustk.com` at `0x0062d590` is referenced from `0x00581583` in the update-notice WndProc.
- Current-session note: IDA MCP was unreachable on 2026-06-07, so this pass uses existing IDA-backed StartupWindow/resource docs and does not claim a fresh string/xref pass.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `78` | The page now separates local PCX notice assets, embedded browser/news URL, remote update metadata, minimap hash-list fetch, registry state, and top-banner URL roles, with rebuild packaging boundaries, scope caveats, and open questions documented. Completion remains capped because raw notice helper boundaries, exact button state mapping, and full remote payload schema are not audited here. |
| Confidence `88` | Existing IDA-backed literal/xref evidence and StartupWindow owner docs strongly identify the strings/resources and their consumers. Confidence is unchanged because this pass did not add fresh IDA evidence. |

## Cross-References

- [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- [UID:0001QM][client_s1-startup](by-meta/client_s1-startup.md)
- [UID:0001QE][client_libraries](by-meta/client_libraries.md)
- [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)

## Changes

- What existed before: the page listed resources but was scored unevaluated and contained generated-source wording in the PCX loading note.
- Changed to: scored `COMPLETION:75` / `CONFIDENCE:88`, removed generated-source dependency wording, and added IDA MCP literal/xref evidence for local PCX assets and remote URLs.
- Summary and evidence: IDA xrefs connect the PCX assets to the update-notice WndProc and the URLs to `StartupWindow__RunUpdateCheck`; score remains below final because registry/update structure fields and all helper internals are not exhaustively documented here.
- 2026-06-07 A002 resource-boundary pass: Raised completion from `75/88` to `78/88`.
  - Before: the page listed PCX assets, URLs, and registry state but did not separate local art, browser content, remote update/minimap metadata, registry comparison, and raw-helper boundaries.
  - After: it records a resource role matrix, rebuild packaging boundary, scope boundaries, open questions, and the current-session IDA availability caveat.
