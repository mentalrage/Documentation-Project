*** UID:0001R6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Application Startup DAT Archives

## Status

- Confidence: strong for resource names and startup call sites; medium for exact original comments or helper names.
- Owner flow: [UID:0000HG][Application](by-file/Application.md) constructor and `Application::Initialize`.
- Archive API owner: [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md).
- Evidence basis: `simroot_v2` generated Application source, IDA MCP disassembly/string reads on 2026-05-25, a focused IDA MCP recheck on 2026-05-30, and existing DAT manager wrapper docs.

## Summary

Application startup preloads the main DAT archive set before constructing most higher-level managers. The loading policy belongs to `app/Application.cpp`, but the actual archive indexing API belongs to `archive/DATFileMgr.cpp`.

The startup path uses three patterns:

- fixed required archives loaded directly through [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md);
- numbered archive families loaded through [UID:0000T5][LoadIndexedDATSeries](by-global/LoadIndexedDATSeries.md);
- hand-written loops for music archive families and the required BINT archives.

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
- [UID:0000YR][0x00463310-0x004679be.ApplicationLifecycle](by-memory/0x00463310-0x004679be.ApplicationLifecycle.md)
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
