*** UID:0001R6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Application Startup DAT Archives

## Status

- Confidence: very strong for resource names, startup call sites, and current-package archive presence; medium for exact original comments or helper names.
- Owner flow: [UID:0000HG][Application](by-file/Application.md) constructor and `Application::Initialize`.
- Archive API owner: [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md).
- Evidence basis: IDA MCP disassembly/string reads on 2026-05-25, a focused IDA MCP recheck on 2026-05-30, current read-only client package inventory on 2026-06-14, documented DAT entry-table parsing, and existing DAT manager wrapper docs.

## Summary

Application startup preloads the main DAT archive set before constructing most higher-level managers. The loading policy belongs to `app/Application.cpp`, but the actual archive indexing API belongs to `archive/DATFileMgr.cpp`.

The startup path uses three patterns:

- fixed required archives loaded directly through [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md);
- numbered archive families loaded through [UID:0000T5][LoadIndexedDATSeries](by-global/LoadIndexedDATSeries.md);
- hand-written loops for music archive families and the required BINT archives.

## Current Package Inventory

2026-06-14 read-only package audit of `E:\2026\Resources\Read_Only\NexusTK\Data` confirms the current client distribution contains every fixed startup archive named by the constructor/initializer path:

| Startup archive | Current package file | Size |
| --- | --- | ---: |
| `DATA/BARAMST.DAT` | `baramst.dat` | 301,540 |
| `DATA/MISC.DAT` | `misc.dat` | 23,097,985 |
| `DATA/CHAR.DAT` | `char.dat` | 8,311,319 |
| `DATA/TILE.DAT` | `tile.dat` | 1,549,757 |
| `DATA/MON.DAT` | `mon.dat` | 6,852,191 |
| `DATA/EFX.DAT` | `efx.dat` | 3,755,268 |
| `DATA/MNM.DAT` | `mnm.dat` | 12,909 |
| `DATA/SND.DAT` | `snd.dat` | 12,240,866 |
| `DATA/BARAM.DAT` | `baram.dat` | 11,276,050 |
| `DATA/BINT0.DAT` | `bint0.dat` | 10,318,248 |
| `DATA/BINT1.DAT` | `bint1.dat` | 8,743,542 |
| `DATA/BINT2.DAT` | `bint2.dat` | 17,326,190 |
| `DATA/WM.DAT` | `wm.dat` | 10,951,551 |

The same audit confirms gapless numbered families for the startup scan prefixes: `FaceDec0`, `Emotion0`, `HairDec0-6`, `Neck0-1`, `body0-14`, `sword0-3`, `spear0-1`, `fan0`, `shield0`, `tile0-23`, `tilec0-26`, `efx0-38`, `bow0-1`, `hair0-3`, `face0`, `helmet0-3`, `mantle0-4`, `shoes0-1`, `coat0-13`, and `mon0-67`. The mixed case on disk does not affect the source policy because the observed startup strings are uppercase DOS-style paths and the client runs on a case-insensitive filesystem.

Music package evidence matches the fallback loop: the package contains `mus000.dat` through `mus006.dat` and no `muh###.dat` files. That supports documenting the `MUH` attempt as a preferred variant probe and `MUS` as the available current-package fallback, without assigning a stronger product meaning to either prefix.

## Constructor Preload

`Application::Application` loads one startup archive before the main initialization block:

| Call site | Resource | Behavior |
| --- | --- | --- |
| `0x004637be` | `DATA/BARAMST.DAT` | Required; failure branches to the constructor fatal path. |

IDA MCP disassembly shows `Application__Constructor` loading [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md), pushing string literal `0x006127d4`, and calling the DAT manager wrapper at `0x0049be70`.

## Fixed Initialize Archives

`Application::Initialize` first loads fixed required archives through [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md):

| Call site | Resource | Behavior |
| --- | --- | --- |
| `0x00463e51` | `DATA/MISC.DAT` | Required; failure jumps to fatal missing-file handling. |
| `0x00463e69` | `DATA/CHAR.DAT` | Required. |
| `0x00463e81` | `DATA/TILE.DAT` | Required. |
| `0x00463e99` | `DATA/MON.DAT` | Required. |
| `0x00463eb1` | `DATA/EFX.DAT` | Required. |
| `0x00463ec9` | `DATA/MNM.DAT` | Required. |

These direct calls establish the baseline archive set before numbered resource families are scanned.

## Numbered Archive Families

The next block calls [UID:0000T5][LoadIndexedDATSeries](by-global/LoadIndexedDATSeries.md), which probes `<prefix><index>.DAT` for indexes `0..98`, stops at the first absent file, and fails fatally only when a present file cannot be indexed by the DAT manager.

| Call site | Prefix | Example files |
| --- | --- | --- |
| `0x00463edb` | `DATA/FACEDEC` | `DATA/FACEDEC0.DAT`, ... |
| `0x00463ee5` | `DATA/EMOTION` | `DATA/EMOTION0.DAT`, ... |
| `0x00463eef` | `DATA/HAIRDEC` | `DATA/HAIRDEC0.DAT`, ... |
| `0x00463ef9` | `DATA/NECK` | `DATA/NECK0.DAT`, ... |
| `0x00463f03` | `DATA/BODY` | `DATA/BODY0.DAT`, ... |
| `0x00463f0d` | `DATA/SWORD` | `DATA/SWORD0.DAT`, ... |
| `0x00463f17` | `DATA/SPEAR` | `DATA/SPEAR0.DAT`, ... |
| `0x00463f21` | `DATA/FAN` | `DATA/FAN0.DAT`, ... |
| `0x00463f2b` | `DATA/SHIELD` | `DATA/SHIELD0.DAT`, ... |
| `0x00463f35` | `DATA/TILE` | `DATA/TILE0.DAT`, ... |
| `0x00463f3f` | `DATA/TILEC` | `DATA/TILEC0.DAT`, ... |
| `0x00463f49` | `DATA/EFX` | `DATA/EFX0.DAT`, ... |
| `0x00463f53` | `DATA/BOW` | `DATA/BOW0.DAT`, ... |
| `0x00463f5d` | `DATA/HAIR` | `DATA/HAIR0.DAT`, ... |
| `0x00463f67` | `DATA/FACE` | `DATA/FACE0.DAT`, ... |
| `0x00463f71` | `DATA/HELMET` | `DATA/HELMET0.DAT`, ... |
| `0x00463f7e` | `DATA/MANTLE` | `DATA/MANTLE0.DAT`, ... |
| `0x00463f88` | `DATA/SHOES` | `DATA/SHOES0.DAT`, ... |
| `0x00463f92` | `DATA/COAT` | `DATA/COAT0.DAT`, ... |

This is source-layout evidence for keeping `LoadIndexedDATSeries` in `Application.cpp`: the helper chooses startup scan policy over resource families, while `DATFileMgr` only indexes individual archive files.

Current IDA MCP recheck on 2026-05-30 confirms that [UID:0000T5][LoadIndexedDATSeries](by-global/LoadIndexedDATSeries.md) has exactly the 19 startup callers listed above, all inside `Application::Initialize` (`sub_4639D0`) at `0x00463edb` through `0x00463f92`. The helper's own callee set is the DAT manager load wrapper, `_wfopen_s`, `_fclose`, `swprintf_s`, and the fatal missing-file reporter, matching the documented numbered-family probe/load policy.

## Sound, Music, BINT, And World Map Archives

After the numbered family scan, startup loads additional archive groups:

| Address/range | Resource pattern | Behavior |
| --- | --- | --- |
| `0x00463fa5` | `DATA/SND.DAT` | Load result is stored in `Application` field `+0x84c`; no immediate fatal branch in the observed block. |
| `0x00463fcc-0x00464059` | `DATA/MUH000.DAT` through `DATA/MUH999.DAT`, fallback `DATA/MUS000.DAT` through `DATA/MUS999.DAT` | For each index, startup first changes `DATA/MUS###.DAT` to `DATA/MUH###.DAT`; if that load fails, it changes the same character back to `S` and attempts `DATA/MUS###.DAT`. The fallback result is not checked for fatal failure. |
| `0x0046406a` | `DATA/BARAM.DAT` | Required; failure jumps to fatal missing-file handling. |
| `0x00464095-0x004640d1` | `DATA/BINT0.DAT`, `DATA/BINT1.DAT`, `DATA/BINT2.DAT` | Required; each formatted path must load successfully. |
| `0x004640de` | `DATA/WM.DAT` | Required; failure jumps to fatal missing-file handling. |

The `MUH`/`MUS` naming suggests two music archive variants, but the exact product meaning is not confirmed yet. Document the observed path mutation rather than assigning an unsupported semantic label.

## Source Layout Decision

Keep this resource policy in `app/Application.cpp` documentation. Do not move it into `archive/DATFileMgr.cpp`, [UID:0000NV][SoundManager](by-file/SoundManager.md), or render/image modules. Those systems consume entries from the archives after startup; they do not own the startup archive inventory or the order of archive registration.

`archive/DATFileMgr.cpp` should own only the generic load/index wrapper and internal archive structures.

## Cross-References

- [UID:0000HG][Application](by-file/Application.md)
- [UID:00000D][Application](by-class/Application.md)
- [UID:0000YR][0x00463310-0x004674ed.ApplicationLifecycle](by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md)
- [UID:0000T5][LoadIndexedDATSeries](by-global/LoadIndexedDATSeries.md)
- [UID:0000YX][0x00467410-0x004674ed.LoadIndexedDATSeries](by-memory/0x00467410-0x004674ed.LoadIndexedDATSeries.md)
- [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md)
- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
- [UID:0001QM][client_s1-startup](by-meta/client_s1-startup.md)
- [UID:0000UB][DATAudioResources](by-item/DATAudioResources.md)

## Changes

- 2026-05-30: Grading changed from unevaluated `0/0` to `88/90`.
  - Before: page contained the startup DAT archive inventory but had no completion/confidence score.
  - After: score reflects detailed fixed archive, numbered archive family, music/BINT/world-map archive, owner-flow, and source-layout documentation.
  - Evidence: current IDA MCP recheck confirmed the 19 numbered-family call sites to `LoadIndexedDATSeries`, all from `Application::Initialize`, and matched the helper callee pattern documented in [UID:0000T5][LoadIndexedDATSeries](by-global/LoadIndexedDATSeries.md).
- 2026-06-14 A002 Goal2 package provenance:
  - What existed before: `COMPLETION:88` / `CONFIDENCE:90`, `CANONICAL_OWNER:NONE`, and startup archive evidence based on IDA call sites without a current distribution inventory.
  - Changed to: `COMPLETION:90` / `CONFIDENCE:92` and `CANONICAL_OWNER:0000HG`.
  - Evidence: read-only package audit of `E:\2026\Resources\Read_Only\NexusTK\Data` confirms all fixed startup archives, gapless numbered families for the 19 `LoadIndexedDATSeries` prefixes, current `MUS000`-`MUS006` fallback archives, no current `MUH###` archives, and the required `BINT0`/`BINT1`/`BINT2` and `WM` files. [UID:0000HG][Application](by-file/Application.md) clears the strict owner gate and remains the semantic owner of startup load order.
