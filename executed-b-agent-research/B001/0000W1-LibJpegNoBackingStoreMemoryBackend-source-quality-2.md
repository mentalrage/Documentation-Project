** TARGET-REPORT-UID:0000W1 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000W1 LibJpegNoBackingStoreMemoryBackend Source-Quality Research

## Import-Directive Repair

2026-06-27 supervisor override `B001-report-third-party-embed-import-inventory-20260627` supersedes the earlier legacy marker implementation language in this active report. This report now recommends the validator-supported inline import directive as the implementation form. Do not implement or preserve legacy static marker comments as final reconstruction code for this target.

Required formal inline `RECONSTRUCTION_CPP CODE` header for [UID:0000W1][0x00406e50-0x00406ed1.LibJpegNoBackingStoreMemoryBackend](../../../../../by-memory/0x00406e50-0x00406ed1.LibJpegNoBackingStoreMemoryBackend.md):

```markdown
*** RECONSTRUCTION_CPP CODE:[[[<import-from-start>"third_party_embeds/libjpeg/jmemnobs.c","third_party_embeds/libjpeg/jinclude.h","third_party_embeds/libjpeg/jpeglib.h","third_party_embeds/libjpeg/jconfig.h","third_party_embeds/libjpeg/jmorecfg.h","third_party_embeds/libjpeg/jpegint.h","third_party_embeds/libjpeg/jerror.h","third_party_embeds/libjpeg/jmemsys.h"</import-from-end>]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

The multiline `RECONSTRUCTION_CPP CODE:BEGIN` / `END` block must stay blank when this inline import directive is used.

## Current Recommendation

- Keep [UID:0000W1](../../../../../by-memory/0x00406e50-0x00406ed1.LibJpegNoBackingStoreMemoryBackend.md) owned and emitted by [UID:0000KN][LibJPEG](../../../../../by-file/LibJPEG.md).
- Keep `RECONSTRUCTABLE:TRUE`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0`.
- Keep the accepted target score `COMPLETION:89`, `CONFIDENCE:92`.
- Replace the current target's legacy marker implementation form with the inline import directive above.
- Keep [UID:0000VW][LibJpegMemoryManager](../../../../../by-memory/0x00405060-0x00405c77.LibJpegMemoryManager.md) as the system-independent `jmemmgr.c` caller/support page; do not merge the no-backing-store backend into it.
- Keep [UID:0000KN][LibJPEG](../../../../../by-file/LibJPEG.md) and [UID:0000VP][LibJpeg6bCore](../../../../../by-memory/0x00401000-0x00414283.LibJpeg6bCore.md) as support context; update their wording to validator import directive policy in a later implementation callback.

## Evidence Retained From The Accepted Pass

- IDA MCP session/database `80de0a67` was responsive in the original evidence pass and in the current inventory repair pass. Current repair pass observed `server_health status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and 2067 cached strings.
- The exact target range `0x00406e50-0x00406ed1` contains the eight IJG libjpeg 6b no-backing-store memory backend hooks:
  - `0x00406e50-0x00406e5d`: `jpeg_get_small`, returns `malloc(size)`.
  - `0x00406e60-0x00406e6b`: `jpeg_free_small`, calls CRT free wrapper.
  - `0x00406e70-0x00406e7d`: `jpeg_get_large`, returns `malloc(size)`.
  - `0x00406e80-0x00406e8b`: `jpeg_free_large`, calls CRT free wrapper.
  - `0x00406e90-0x00406e94`: `jpeg_mem_available`, returns `max_bytes_needed`.
  - `0x00406ea0-0x00406eb3`: `jpeg_open_backing_store`, raises `JERR_NO_BACKING_STORE` selector `49`.
  - `0x00406ec0-0x00406ec2`: `jpeg_mem_init`, returns `0`.
  - `0x00406ed0`: `jpeg_mem_term`, no-op cleanup.
- No function exists at `0x00406ed1`; `0x00406ed1-0x00406ee0` is padding before successor [UID:00045N][0x00406ee0-0x004075b7.LibJpegDecompressCoefficientController](../../../../../by-memory/0x00406ee0-0x004075b7.LibJpegDecompressCoefficientController.md).
- All target xrefs are backend-hook users from `jmemmgr.c`; product image/screenshot wrappers are consumers of public libjpeg APIs elsewhere and do not own this backend.
- Staged source `third_party_embeds/libjpeg/jmemnobs.c` has SHA256 `0605c64556d298071473fc245fa9d83cf10b60022d5c5d2821a846b94aa1a9fb`.
- `jmemnobs.c` directly includes `jinclude.h`, `jpeglib.h`, and `jmemsys.h`. The recommended directive includes those direct headers plus transitive public/private headers `jconfig.h`, `jmorecfg.h`, `jpegint.h`, and `jerror.h` so the generated import carries the vetted backend source surface instead of a lone C file.

## Rejected Alternatives

- Leaving the formal C++ blank is rejected because the target is reconstructable, has a valid emitting route to [UID:0000KN][LibJPEG](../../../../../by-file/LibJPEG.md), and has exact staged source.
- Hand-writing eight backend functions from decompiler output is rejected because the source-faithful representation is the IJG `jmemnobs.c` source file.
- Treating the target as file-backed temporary storage is rejected; the target raises no-backing-store error selector `49`.
- Merging this backend into [UID:0000VW][LibJpegMemoryManager](../../../../../by-memory/0x00405060-0x00405c77.LibJpegMemoryManager.md) is rejected because IJG separates `jmemmgr.c` from system-dependent `jmemnobs.c`.
- Product ownership through image loader/writer/screenshot callers is rejected; target-local callers are libjpeg memory-manager hooks.

## Implementation Callback Checklist

Implementation callback proof recorded 2026-06-27 for `B001-implement-third-party-embed-import-directives-20260627`.

- [x] Leased only the editable LibJPEG by-* files immediately before the edit batch: `python .\tools\leaser\leaser.py B001 lease by-memory\0x00406e50-0x00406ed1.LibJpegNoBackingStoreMemoryBackend.md by-file\LibJPEG.md by-memory\0x00401000-0x00414283.LibJpeg6bCore.md by-memory\0x00405060-0x00405c77.LibJpegMemoryManager.md` returned success for all four paths.
- [x] In `by-memory/0x00406e50-0x00406ed1.LibJpegNoBackingStoreMemoryBackend.md`, replaced the inline `RECONSTRUCTION_CPP CODE` value with:

```markdown
*** RECONSTRUCTION_CPP CODE:[[[<import-from-start>"third_party_embeds/libjpeg/jmemnobs.c","third_party_embeds/libjpeg/jinclude.h","third_party_embeds/libjpeg/jpeglib.h","third_party_embeds/libjpeg/jconfig.h","third_party_embeds/libjpeg/jmorecfg.h","third_party_embeds/libjpeg/jpegint.h","third_party_embeds/libjpeg/jerror.h","third_party_embeds/libjpeg/jmemsys.h"</import-from-end>]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- [x] Ensured the target multiline `RECONSTRUCTION_CPP CODE` block is blank.
- [x] Preserved `89/92`, `0000KN` owner/emitter route, exact eight-function inventory, padding and successor proof, backend-hook xrefs, staged source hash, no-file-backed-backend rejection, no-product-owner rejection, and no-merge-with-`jmemmgr.c` rejection.
- [x] Updated `by-memory/0x00405060-0x00405c77.LibJpegMemoryManager.md` with the formal `jmemmgr.c` inline import directive and blank multiline block as the paired memory-manager slice in this coherent LibJPEG chunk.
- [x] Updated `by-file/LibJPEG.md`, `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md`, and `by-memory/0x00405060-0x00405c77.LibJpegMemoryManager.md` support wording from legacy marker policy to validator import directive policy for W1/VW without changing unrelated source claims.
- [x] Ran scoped validators from `source-3/project-documentation` with generated output current:

> Executable block R001 was removed from this report and preserved verbatim in [0000W1-LibJpegNoBackingStoreMemoryBackend-source-quality-2-removed.md](0000W1-LibJpegNoBackingStoreMemoryBackend-source-quality-2-removed.md). The archived block is non-authoritative and must not be executed.

- [x] Confirmed generated `auto-generated/NexusTK/third_party/libjpeg/LibJPEG.cpp` is current to validator command `000000003759` / `2026-06-27T04:02:55-04:00`; UIDs `0000W1` and `0000VW` import through `<import-from-start>` validator separators for `jmemnobs.c` and `jmemmgr.c` plus the accepted IJG header set. Remaining LibJPEG children still have legacy markers and are listed in `000TP` for continuation.
- [x] Release verification: the explicit post-validator command `python .\tools\leaser\leaser.py B001 unlease by-memory\0x00406e50-0x00406ed1.LibJpegNoBackingStoreMemoryBackend.md by-file\LibJPEG.md by-memory\0x00401000-0x00414283.LibJpeg6bCore.md by-memory\0x00405060-0x00405c77.LibJpegMemoryManager.md` returned `Rejected[No active lease]` for all four paths because no active lease remained; `tools/leaser/lease.json` then showed `"leases": {}` and `tools/leaser/Agents/current_leases.md` said `No active leases.`
- [ ] Supervisor-owned only: after verification, execute this report with `python .\tools\validator.py execute_report B001 0000W1-LibJpegNoBackingStoreMemoryBackend-source-quality.md 0000W1 --apply`.

## Implementation State

This callback edited the accepted by-* LibJPEG target/support files for the W1 backend and paired VW memory-manager chunk, then let scoped validators refresh generated output. Generated C++ and generated reports were not edited manually. Known unrelated validator diagnostics included existing `autogen_registry_stale` and `memory_coverage_metadata_missing_file` entries; remaining legacy LibJPEG marker pages are continuation work under `000TP`, not blockers for the accepted W1/VW conversion.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0000W1-LibJpegNoBackingStoreMemoryBackend-source-quality-2.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0000W1-LibJpegNoBackingStoreMemoryBackend-source-quality.md","timestamp":"2026-06-27T04:18:10","uid":"0000W1"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000W1-LibJpegNoBackingStoreMemoryBackend-source-quality-2-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0000W1-LibJpegNoBackingStoreMemoryBackend-source-quality-2.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000W1"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
