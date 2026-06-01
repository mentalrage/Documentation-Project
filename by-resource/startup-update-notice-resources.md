*** UID:0001RO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:75 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

## IDA MCP Evidence

- ASCII PCX literals were verified at `0x0062d530` (`brm_main.pcx`), `0x0062d540` (`brm_st_a.pcx`), `0x0062d550` (`brm_st_b.pcx`), `0x0062d560` (`brm_st_c.pcx`), `0x0062d570` (`brm_ex_a.pcx`), and `0x0062d580` (`brm_ex_b.pcx`).
- Those PCX literals have xrefs from `0x00581100-0x005815aa`, matching the update-notice window procedure, plus adjacent unmodeled asset-load references around `0x005818d0-0x005819c9`.
- ASCII `https://s3.amazonaws.com/kru-downloads/tk/update/nexustk.ver` was verified at `0x0062d4a8` and is referenced from `0x00580c49` inside `StartupWindow__RunUpdateCheck` at `0x00580870-0x005810fd`.
- ASCII `https://s3.amazonaws.com/kru-downloads/tk/minimaps/HashList.txt` was verified at `0x0062d4f0` and is referenced from `0x00580ed5` inside the same update-check function.
- ASCII `http://www.nexustk.com/news/news.asp` at `0x0062d474` is referenced from `0x00580b3e` in `StartupWindow__RunUpdateCheck`; ASCII `http://www.nexustk.com` at `0x0062d590` is referenced from `0x00581583` in the update-notice WndProc.

## Cross-References

- [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- [UID:0001QM][client_s1-startup](by-meta/client_s1-startup.md)
- [UID:0001QE][client_libraries](by-meta/client_libraries.md)
- [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)

## Changes

- What existed before: the page listed resources but was scored unevaluated and contained generated-source wording in the PCX loading note.
- Changed to: scored `COMPLETION:75` / `CONFIDENCE:88`, removed generated-source dependency wording, and added IDA MCP literal/xref evidence for local PCX assets and remote URLs.
- Summary and evidence: IDA xrefs connect the PCX assets to the update-notice WndProc and the URLs to `StartupWindow__RunUpdateCheck`; score remains below final because registry/update structure fields and all helper internals are not exhaustively documented here.
