** TARGET-REPORT-UID:0002AJ **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002AJ MsvcRuntimeMutableDataTail Source-Quality Reanalysis

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0002AJ] `0x0069c044-0x0069d000.MsvcRuntimeMutableDataTail` non-reconstructable, ignored, no canonical owner, blank emitters, and blank C++.
- Recommended score/metadata: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, `EMITTER_UIDS:` blank.
- Required action: update the target/support docs with the corrected byte/boundary evidence, runtime substructure names, first-byte zlib empty-string caveat, no-split/no-code proof, and supervisor-owned coverage row below. Do not edit `by-memory/-coverage-report.md` directly from this report.
- Confidence: very strong for non-NexusTK/runtime/library classification and boundaries; strong for internal family names; medium for exact original CRT/STL private symbol spellings.

## Target

- Target UID: [UID:0002AJ].
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0069c044-0x0069d000.MsvcRuntimeMutableDataTail.md`.
- Current scores and parent state: `COMPLETION:85`, `CONFIDENCE:85`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`.
- Current coverage row: `runtime | MsvcRuntimeMutableDataTail : ignored : 85% : strong : Final .data tail is dense MSVC CRT/STL/runtime mutable state, not NexusTK-authored data.`
- Assignment: `B009-goal2-msvc-runtime-mutable-data-tail-source-quality-0002AJ-20260619`, report-only. No by-* docs or `by-memory/-coverage-report.md` were edited.

## Executive Recommendation

[UID:0002AJ] should remain one ignored runtime/library tail page, not a NexusTK source object and not an emitted child of a source file. The existing high-level classification is correct, but two material documentation fixes are needed:

1. The old `all 0xff` byte claim should be corrected or qualified. Current direct PE parsing of `E:\NTK\Resources\NexusTK\NexusTK.exe` shows the whole `0x0069c044-0x0069d000` span is in the unbacked/zero-filled portion of `.data` plus the final section-alignment tail. The loaded virtual image should start as zero bytes there, not file-backed `0xff` bytes. Older IDA text that says `FF:4028` is stale for the executable available in this workspace, or reflects a non-file/runtime-mutated view rather than raw image bytes.
2. The first target address `0x0069c044` is referenced by the zlib 1.1.4 error-message pointer table as a shared empty-string target. That one-byte/one-dword zero-fill sentinel should be documented as a library/linker coalescing caveat, but it does not justify splitting the page or emitting a separate zlib data page. The reconstructable zlib source already owns the error-message table and the `""` source literal; this physical zero byte is not NexusTK-authored storage and is coalesced into the same zero-fill tail that precedes the MSVC runtime objects.

The best implementation is to keep the current filename and UID, raise the page to `88/90`, and add a detailed internal family map. If a future byte-perfect third-party audit wants to model the empty-string sentinel separately, the only plausible split would be `0x0069c044-0x0069c048` as a zero-fill empty-string/alignment head linked to zlib, with the runtime tail beginning at `0x0069c048`; I do not recommend that split now because it creates a one-byte source-use artifact whose source-level ownership is already represented by [UID:00028E] and [UID:0000PC].

## Supervisor Active Recheck

- I read the active B009 instructions in `Supervisor.md`, `.codex/AGENTS.md`, `Agent-B009\goal.md`, `Agent-B009\notes.md`, `by-structure.md`, and `inference_research.md`.
- Rule 26 applies: every valid detail found here must be available for later by-* incorporation. This report therefore includes the stale-byte correction, internal names, negative split analysis, exact support checklist, and exact coverage row.
- This assignment is report-only. The target is split-capable in principle, but the evidence does not support a required by-structure split during this pass. No by-* page was edited.

## Evidence Checked

### Direct Current Evidence

- Current IDA MCP availability check: JSON-RPC `tools/list` to `http://127.0.0.1:13337/mcp` failed with `Unable to connect to the remote server`. Therefore this report separates direct current PE/Capstone evidence from prior live IDA evidence already written into by-* docs.
- PE parsed directly from `E:\NTK\Resources\NexusTK\NexusTK.exe`; same file also exists at `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` and `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, size `2679296`, mtime `2025-12-11T11:24:42`.
- PE header facts from direct parse:
  - image base `0x00400000`.
  - section alignment `0x1000` / 4096 bytes (Verified with `int_convert.py`).
  - file alignment `0x200` / 512 bytes (Verified with `int_convert.py`).
  - `.data` section VA `0x0066d000-0x0069ce24`, virtual size `0x2fe24` / 196132 bytes (Verified with `int_convert.py`), raw file span `0x0026ac00-0x00278400`, raw size `0xd800` / 55296 bytes (Verified with `int_convert.py`), aligned memory end `0x0069d000`.
  - `.rsrc` starts at `0x0069d000`, so the target's documented end is also the next section start.
- Direct virtual/raw mapping:
  - `.data` raw-backed VA range is only `0x0066d000-0x0067a800`.
  - target `0x0069c044-0x0069d000` is entirely beyond the `.data` raw-backed file bytes.
  - target size is `0xfbc` / 4028 bytes (Verified with `int_convert.py`).
  - `0x0069c044-0x0069ce24` is inside `.data` `VirtualSize` and should be loader zero-fill.
  - `0x0069ce24-0x0069d000` is `0x2bc` / 700 bytes (Verified with `int_convert.py`) of section-alignment tail before `.rsrc`; it also has no file-backed bytes.
  - Treat the old `FF:4028` evidence as stale or non-raw. It must not be cited as raw executable evidence without a caveat.
- Raw pointer/immediate scan over all raw sections for little-endian dwords in `0x0069c044-0x0069d000`:
  - `638` total hits to `194` unique target addresses.
  - Source sections: `.text:617`, `.rdata:3`, `.data:18`.
  - This closely supports the current page's older `198 named/referenced anchors` claim, while correcting the file-byte story.
- Representative raw pointer/immediate hits:
  - `0x0069c044`: two `.data` refs at `0x00671af8` and `0x00671b14`, both from the zlib error-message table.
  - `0x0069c048`: refs at `0x0041a4ce` and `0x0060c45b`, startup/cleanup wrappers for the first `std::_Init_locks` object.
  - `0x0069c050`: refs at `0x005c5efe`, `0x005c5f38`, `0x005c5f59`, and `0x005c5f84`, inside the Dinkumware lock constructor/destructor/accessor loop.
  - `0x0069c110`: ten refs from STL/locale code including `0x00436eb4`, `0x00436eba`, `0x00438d43`, `0x00438d49`, `0x00438ebd`, `0x00438ec3`, `0x0043a79d`, `0x0043a7a3`, `0x005c5f0e`, and `0x005c5f69`.
  - `0x0069c12c`: one cleanup ref at `0x0060c46f`.
  - `0x0069c134`: one cleanup ref at `0x0060c465`.
  - `0x0069c1a0`: startup/cleanup refs at `0x0041a508` and `0x0060c483`.
  - `0x0069c1a1`: `_Init_atexit` cleanup ref at `0x0060c479`.
  - `0x0069c1d0`: API-pointer cache store at `0x005c6f75`.
  - `0x0069c2e8`: refs at `0x005c75fd`, `0x005c76f8`, and `.rdata` `0x0063506c`, matching GS/security-failure context.
  - `0x0069c604`: SCRT startup-state refs at `0x005c84f6`, `0x005c850b`, and `0x005c8548`.
  - `0x0069c668`: startup/cleanup refs at `0x0041a51e` and `0x0060c48d`.
  - `0x0069c750`: lowio/stdio/env refs at `0x005d6fb9`, `0x005d6fd3`, `0x005d6ffc`, `0x005ded39`, `0x005e77eb`, and `0x005eb222`.
  - `0x0069c754`: `17` refs around ACRT lowio allocation/cleanup paths.
  - `0x0069c75c`: `9` data-table refs from `0x0067305c-0x0067307c`, agreeing with [UID:00028F]'s pointer-cluster note.
  - `0x0069c760`: `7` data-table refs from `0x0067308c-0x006730a4`, also agreeing with [UID:00028F].
  - `0x0069ca08`: `114` refs, dominant lowio/file-handle table anchor.
  - `0x0069cc08`: `15` refs from ACRT/stdio/locale support.
  - `0x0069cd08`: timezone-family refs at `0x005ec479` and `0x005ec48e`.
  - `0x0069cde4`: multibyte/locale flag refs at `0x005efcef`, `0x005efcfe`, `0x005efd15`, `0x005efd2f`, and `0x005f0223`.
  - `0x0069ce20`: `11` refs in the final virtual-size tail.
- Capstone samples:
  - `0x0041a4cd`: `mov ecx, 0x69c048; call 0x5c5eec; push 0x60c45a; call 0x5c7ba3; ret`, proving startup construction of a runtime lock object and atexit cleanup registration.
  - `0x0060c45a`: `mov ecx, 0x69c048; jmp 0x5c5f4a`, cleanup for that same object.
  - `0x005c5efd`: `mov esi, 0x69c050`, loop calling `0x5c6c97`, `add esi, 0x18`, `cmp esi, 0x69c110`; this is an eight-entry `0x18`-stride lock array under `std::_Init_locks`-style runtime code.
  - `0x005c5f58`: destructor loop over `0x69c050` to `0x69c110` with the same `0x18` stride.
  - `0x005c6f74`: stores encoded API pointers into `0x0069c1d0+` after calls through the import at `0x0060d128`. Nearby pushed names include `FlsFree`, `FlsGetValue`, `FlsSetValue`, `InitializeCriticalSectionEx`, `InitOnceExecuteOnce`, `CreateEventExW`, `CreateSemaphoreW`, `CreateSemaphoreExW`, `CreateThreadpoolTimer`, `SetThreadpoolTimer`, `WaitForThreadpoolTimerCallbacks`, and `CloseThreadpoolTimer`.
  - `0x005c84f5`: `mov eax, [0x69c604]`, checks startup state, then `0x005c8509` stores `1` and `0x005c8546` stores `2`; this matches `__scrt_common_main_seh` native startup-state behavior.
  - `0x005d1b99` and `0x005d1bbf`: lowio/stdio code indexes `dword ptr [ecx*4 + 0x69ca08]` with `fd >> 6` and `fd & 0x3f`, plus a `0x30` stride, matching ACRT lowio file-handle table access.
  - `0x005d6fb8-0x005d70d2`: lowio/env initialization stores to `0x69c750`, allocates and stores through `0x69c754`, initializes per-entry records, later frees and clears `0x69c754`.
  - Product-address examples such as `0x00424878`, `0x00466cbd`, `0x004be8ac`, and `0x004c3506` reference `0x0069c650/0x0069c654`, but the sampled pattern uses `fs:[0x2c]` and the same CRT startup/TLS guard variables. These are compiler-emitted thread-safe local-static guard/epoch accesses, not handwritten product globals.
- String samples for `initialize_pointers`:
  - `0x00633eb0` `FlsFree`
  - `0x00633eb8` `FlsGetValue`
  - `0x00633ec4` `FlsSetValue`
  - `0x00633ed0` `InitializeCriticalSectionEx`
  - `0x00633eec` `InitOnceExecuteOnce`
  - `0x00633f00` `CreateEventExW`
  - `0x00633f10` `CreateSemaphoreW`
  - `0x00633f24` `CreateSemaphoreExW`
  - `0x00633f38` `CreateThreadpoolTimer`
  - `0x00633f50` `SetThreadpoolTimer`
  - `0x00633f64` `WaitForThreadpoolTimerCallbacks`
  - `0x00633f84` `CloseThreadpoolTimer`

### Existing Documentation Evidence Rechecked

- Target page [UID:0002AJ] already records:
  - `.data` parent `0x0066d000-0x0069d000`.
  - child span `0x0069c044-0x0069d000`, size `4028`.
  - `198` named/referenced anchors.
  - runtime-family anchors for `_Init_locks`, locale/facet/ios_base, CRT atexit, runtime API pointer initialization, GS failure context, SCRT startup/TLS/list state, stdio/file/environment locks, timezone, heap, file, locale, and multibyte runtime storage.
  - contiguous predecessor [UID:0001Q4] and `.data` end [UID:0001Z8].
- [UID:0001Z8] `DataSection` already lists [UID:0002AJ] as the final MSVC CRT/STL/runtime mutable-state tail and ignored for handwritten NexusTK source. It should be updated with the raw PE zero-fill/VirtualSize caveat.
- [UID:0001Q4] `SnowLookupDescriptorStorage` reconfirms the predecessor ends exactly at `0x0069c044`, with successor refs beginning at `0x0069c044`. It also records a current correction from stale `0xff` wording to zero-filled `.data`, which matches the correction needed here.
- [UID:00028E] `Zlib114DataMessagesAndTables` records the zlib error-message pointer table with the shared empty-string target at `0x0069c044`. This is the only non-Msvc-looking source-use evidence at the target start.
- [UID:00028F] `MsvcDinkumwareRuntimeMutableData` records adjacent earlier runtime mutable data and pointer clusters into `0x0069c75c` and `0x0069c760`, supporting the final-tail linkage.
- [UID:000273] `MsvcRuntimeReadOnlyDataTail` records runtime `.rdata` strings and security failure read-only data, including `ExceptionInfo` and `___report_gsfailure` references that pair with mutable GS context in this target.
- [UID:0000WF] `StaticRuntimeInitializerWrappersAfterUserPanePool` directly names startup wrappers that construct/register cleanup for target addresses `0x0069c048`, `0x0069c134`, `0x0069c12c`, `0x0069c1a0`, and `0x0069c668`.
- [UID:00024J] `StaticRuntimeCleanupWrappersAfterUserPanePool` names cleanup wrappers for `stru_69C050`, `dword_69C110`, `unk_69C134`, `dword_69C12C`, `unk_69C1A1`, `0x0069c668`, `stru_69C67C`, and `unk_69C694`.
- [UID:00024B] `MsvcRuntimeImportAndStlSupport` identifies the code islands around `_Init_locks`, `?initialize_pointers@@YAHXZ`, `__Init_thread_abort`, and `?__scrt_common_main_seh@@YAHXZ` as MSVC runtime/STL/SCRT support, not game source.
- [UID:00024C] `MsvcAcrtStdioLocaleMathSupport` identifies the dense later code at `0x005cea6d-0x005f66f7` as ACRT/stdio/locale/heap/startup/lowio/file-open/math/string support. The raw pointer scan places the target's largest reference clusters in this page's lowio/stdio/locale/timezone bodies.
- [UID:0001QE] `client_libraries` records statically linked MSVC CRT/STL/Dinkumware support and directs rebuild work to a compatible MSVC-era toolchain/runtime model, not NexusTK product files.
- `by-memory/-ignored.md` already has an ignored-ledger entry for `0x0069c044-0x0069d000`. It should be updated to replace the stale `all 4028 bytes initialize to 0xff` text with the direct PE zero-fill/unbacked-storage evidence and the `0x0069c044` zlib empty-string caveat.
- Existing executed B-research search found only a supporting mention in `Agent-B001\research\executed\0003GY-UnreferencedThreadDispatchWrapper-current-source-routing.md`, which cites [UID:0002AJ] as the current runtime doc for API-name strings and runtime API-pointer initialization. No prior executed report for this exact target was found in the searched B001/B002/B009 executed folders.

## Heuristic / Inference Reanalysis And Validation

### Runtime Classification

- Issue: Is the non-reconstructable/runtime classification still correct?
- Evidence: Direct PE section mapping shows the target is zero-fill/unbacked `.data` tail; raw pointer scan shows hundreds of refs from MSVC runtime/STL/ACRT code islands; Capstone confirms startup wrappers, `_Init_locks`, `initialize_pointers`, `__scrt_common_main_seh`, and ACRT lowio table behavior; existing docs tie the range to runtime initializer/cleanup wrappers and runtime support pages.
- Rejected alternative: NexusTK-owned source global cluster. Rejected because no owner-specific product constructor/destructor or subsystem-specific source file owns the span; product-address refs to `0x0069c650/654` are compiler-inserted TLS/thread-safe-static guard accesses, not source globals; the dominant code refs are runtime functions and support libraries.
- Decision: keep ignored/non-reconstructable runtime/library data.

### Raw Byte Claim

- Issue: Current target and ignored ledger say the image bytes initialize to `0xff` throughout.
- Evidence checked: Direct PE parser maps `.data` raw bytes only through VA `0x0067a800`; target starts at `0x0069c044`, so it is not file-backed. The virtual target constructed from raw-backed data plus loader zero-fill is `00:4028`, not `ff:4028`.
- Rejected alternative: Preserve old `FF:4028` as authoritative. Rejected because it contradicts the readable executable's PE section table and agrees with a sibling correction already made in [UID:0001Q4].
- Decision: implementation should say "current raw PE evidence shows zero-filled/unbacked storage; older `0xff` byte-count is stale or non-raw/runtime-view evidence."

### Boundary Against [UID:0001Q4] And `.data` End

- Issue: Does the target start/end need adjustment?
- Evidence: [UID:0001Q4] ends exactly at `0x0069c044`; pointer scan sees successor refs beginning at `0x0069c044`; PE `.rsrc` begins at `0x0069d000`; IDA/documentation `.data` aligned segment ends at `0x0069d000`.
- Rejected alternative: Expand predecessor [UID:0001Q4]. Rejected because the predecessor's SnowingLayerPane xrefs end at `0x0069c040` guard and the successor refs begin at `0x0069c044`.
- Rejected alternative: Truncate target at PE `.data` VirtualSize end `0x0069ce24`. Rejected for current documentation because IDA and coverage model the `.data` segment to aligned end `0x0069d000`, and the remaining `0x2bc` / 700 bytes are still part of the documented section tail before `.rsrc`. It should be called alignment tail, not ignored as unknown.
- Decision: keep `0x0069c044-0x0069d000`, with subrange note `0x0069c044-0x0069ce24` zero-fill runtime/library storage and `0x0069ce24-0x0069d000` zero-fill section-alignment tail.

### First-Address Zlib Empty-String Sentinel

- Issue: Two zlib table refs point to `0x0069c044`, not runtime code.
- Evidence: Raw pointer scan shows exactly two refs to `0x0069c044`, at `0x00671af8` and `0x00671b14`, both inside [UID:00028E]'s zlib error-message table. No `.text` refs to `0x0069c044` were found by the raw pointer scan. The first runtime object evidence starts at `0x0069c048`.
- Best-supported name: `zlibErrorMessageEmptyStringSentinel` or `zeroFillEmptyStringHead`, descriptive only, not recovered.
- Rejected split: Create a new `0x0069c044-0x0069c048` source-owned zlib child. Rejected for now because the source-owned construct is the zlib `z_errmsg` pointer table already represented by [UID:00028E]; the physical `0x0069c044` byte is generic zero-fill and likely linker/string-pool coalescing. A split would add one low-value child and complicate the tail without improving NexusTK reconstruction.
- Decision: do not split; add explicit caveat and cross-reference [UID:00028E]/[UID:0000PC].

### `stru_69C050` And `dword_69C110`

- Issue: IDA placeholder names are too anonymous.
- Evidence: Startup wrapper at `0x0041a4cd` passes `ecx=0x0069c048`; `_Init_locks` constructor loop starts at `0x0069c050`, increments by `0x18`, and stops at `0x0069c110`; cleanup loop uses the same range. `0x0060c45a` cleanup wrapper jumps to the destructor path with `ecx=0x0069c048`.
- Best-supported name: `stdInitLocksPrimaryStorage` for `0x0069c048-0x0069c110`; `stdInitLockArray` for `0x0069c050-0x0069c110`; `stdInitLocksPrimaryEnd` or no standalone name for `0x0069c110`.
- Rejected alternative: NexusTK critical-section array. Rejected because construction/destruction is registered by compiler runtime wrappers and uses Dinkumware `std::_Init_locks` code.
- Decision: document as MSVC/Dinkumware `_Init_locks` lock storage, not product state.

### `dword_69C12C`, `unk_69C134`, Locale/Facet/Ios State

- Issue: Exact private Dinkumware symbol names are not recovered.
- Evidence: Cleanup wrapper `0x0060c46e` passes `0x0069c12c` to `sub_43A5C0`; cleanup wrapper `0x0060c464` calls `std::_Fac_tidy_reg_t::~_Fac_tidy_reg_t(&unk_69C134)` per existing docs; target and pointer scan show `0x0069c110-0x0069c170` refs from STL locale/facet/ios_base code.
- Best-supported names: `dinkumwareLocaleFacetCleanupState`, `stdFacetTidyRegistry`, and `iosBaseLocaleRuntimeState`, all descriptive.
- Rejected alternative: Try to assign exact `std::locale::_Locimp` field names. Rejected because current evidence proves family and cleanup route, not a stable private layout spelling.
- Decision: document family names and exact cleanup refs; mark exact field spelling unresolved but non-blocking for non-reconstructable runtime data.

### `0x0069c1a0/0x0069c1a1` Static Runtime Objects

- Issue: The target's prior text describes only a tiny atexit/static-initialization range, while startup/cleanup docs show overlapping adjacent runtime objects.
- Evidence: Startup wrapper `0x0041a507` constructs a second `std::_Init_locks`-style state at `0x0069c1a0`; cleanup wrapper `0x0060c482` uses the same address. Cleanup wrapper `0x0060c478` calls `_Init_atexit::~_Init_atexit(&unk_69C1A1)`.
- Best-supported name: `secondaryStdInitLocksAndInitAtexitState`.
- Rejected alternative: Split into exact one-byte/dword children. Rejected because this is private runtime object packing and not source-owned NexusTK data.
- Decision: record both roles and avoid overclaiming exact field layout.

### `0x0069c1d0-0x0069c26c` Runtime API-Pointer Cache

- Issue: Placeholder range should have a source-quality role name.
- Evidence: `0x005c6f74` and successors store `eax ^ ___security_cookie` into `0x0069c1d0+` after resolving API names through the import at `0x0060d128`. Sample names include `FlsFree`, `FlsGetValue`, `FlsSetValue`, `InitializeCriticalSectionEx`, `InitOnceExecuteOnce`, and threadpool/semaphore/event APIs. Existing [UID:00024B] names this routine `?initialize_pointers@@YAHXZ`.
- Best-supported names: `scrtEncodedWinApiPointerCache` or `msvcRuntimeApiPointerCache`.
- Rejected alternative: Project platform dispatch table. Rejected because the routine and strings are SCRT/ACRT runtime fallback API resolution, not product code.
- Decision: document as encoded MSVC/SCRT OS API pointer cache.

### `0x0069c2e8-0x0069c400` GS Failure Context

- Issue: Placeholder range should be tied to the read-only/security docs.
- Evidence: Target docs cite `___report_gsfailure`; raw pointer scan sees refs at `0x005c75fd`, `0x005c76f8`, and `.rdata` `0x0063506c`, matching [UID:000273]'s `ExceptionInfo` and security-failure text.
- Best-supported name: `gsFailureExceptionContextStorage`.
- Rejected alternative: Product crash-report state. Rejected because the owning code is compiler security-cookie fail-fast machinery, not [UID:0000II] Crasher or application error handling.
- Decision: document as MSVC GS/security-failure context.

### `0x0069c604-0x0069c660` SCRT Startup/TLS/Thread-Safe Static State

- Issue: Product-address xrefs could be misread as game ownership.
- Evidence: `__scrt_common_main_seh` reads/writes `0x0069c604`: `0` -> `1` during initializing and `2` after startup init. Raw pointer scan shows dense refs to `0x0069c628`, `0x0069c644`, `0x0069c650`, `0x0069c654`, and `0x0069c658`. Capstone samples at product addresses that touch `0x0069c650/654` show `fs:[0x2c]` TLS access and compiler guard/epoch pattern.
- Best-supported names: `__scrt_current_native_startup_state` for `0x0069c604`; `scrtStartupLockTlsGuardAndEpochState` for the surrounding range; `threadSafeLocalStaticRuntimeEpoch` for the product-address guard refs.
- Rejected alternative: Assign `0x0069c650/654` to product functions that reference local statics. Rejected because these are shared compiler runtime guard variables, not source-authored globals.
- Decision: keep runtime-owned; document product xrefs as compiler-generated access sites only.

### `0x0069c668-0x0069c6a0` Runtime Critical-Section/Heap Cleanup State

- Issue: Current target only says runtime list state.
- Evidence: [UID:0000WF] startup wrapper initializes `0x0069c668` through `sub_5c8b0b`; [UID:00024J] cleanup wrapper `0x0060c48c` deletes `stru_69C67C`, frees `unk_69C694`, and clears companion fields.
- Best-supported name: `runtimeCriticalSectionAndHeapCleanupState`.
- Rejected alternative: Product critical-section object. Rejected because construction and cleanup are in compiler runtime wrapper islands.
- Decision: document as runtime critical-section/free-list cleanup state.

### `0x0069c750-0x0069ca08` And `0x0069ca08+` ACRT Lowio/Stdio Storage

- Issue: Current target stops the representative range before the strongest lowio anchor at `0x0069ca08`.
- Evidence: Raw pointer scan finds `0x0069ca08` has `114` refs. Capstone at `0x005d1b99` and `0x005d1bbf` indexes `dword ptr [fd_block*4 + 0x69ca08]` using `fd >> 6`, `fd & 0x3f`, and `0x30`-byte record stride. Initialization at `0x005d6fb8-0x005d70d2` writes `0x0069c750/754`, allocates tables, initializes handle records, and frees/clears `0x0069c754`.
- Best-supported names: `acrtLowioHandleTableState`, `acrtPioinfoPointerTable` for `0x0069ca08`, `acrtStdioLowioLockState` for surrounding lock records.
- Rejected alternative: NexusTK file manager storage. Rejected because access patterns are standard ACRT lowio/stdio file-descriptor internals and all writer/reader clusters live in [UID:00024C].
- Decision: document as ACRT lowio/stdio/file-handle runtime storage.

### `0x0069cd08+` Timezone/Locale/Multibyte Tail

- Issue: Current target names broad categories but not the strongest exact anchors.
- Evidence: Raw pointer scan has refs to `0x0069cd08` from timezone code at `0x005ec479` and `0x005ec48e`; old runtime report text identifies this region's callers as CRT timezone refresh and `tzset` paths. Capstone sample at `0x005efced-0x005efd2f` writes `0x0069cde4` as a multibyte/locale flag while handling sentinel code-page values.
- Best-supported names: `crtTimezoneEnvironmentState`, `crtLocaleMultibyteCodepageState`, `crtMbctypeRuntimeTail`.
- Rejected alternative: Product time/calendar state. Rejected because refs are from CRT `tzset`, time conversion, and multibyte/locale functions.
- Decision: document as CRT timezone/environment/locale/multibyte storage.

### Owner / Source Placement

- Best owner candidate if forced: [UID:0001QE] `client_libraries` as the meta-level dependency index for MSVC CRT/STL/Dinkumware, with [UID:00024B], [UID:00024C], [UID:0000WF], [UID:00024J], [UID:00028F], and [UID:000273] as exact support docs.
- Rejected canonical owner: [UID:0001QE]. Rejected because current by-memory runtime pages use `CANONICAL_OWNER:NONE` for runtime/compiler artifacts, and a by-meta dependency index is not a source owner or emitter.
- Rejected canonical owner: [UID:0001Z8] `DataSection`. Rejected because `DataSection` is a section container, not semantic ownership.
- Rejected canonical owner: [UID:0000PC] `Zlib`. Rejected for the full target because only the first zero byte/dword has zlib empty-string refs; all meaningful mutable state and all dense xrefs are MSVC runtime/ACRT/STL.
- Decision: `CANONICAL_OWNER:NONE`, blank emitters, support links to runtime/library docs.

### Split / Range Decision

- Best split candidate: `0x0069c044-0x0069c048` as a zlib empty-string/alignment head, then `0x0069c048-0x0069d000` as runtime zero-fill tail.
- Why rejected: The first subrange is a one-byte NUL plus alignment, not an independently source-authored global. The source-level `""` is already captured by the zlib error-message table in [UID:00028E]. Creating a one-byte child would not improve emitted output or ownership clarity enough to justify coverage churn.
- Runtime subrange splits rejected: all major subranges remain third-party/runtime, compiler-generated, or linker/toolchain-generated and would remain `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitters. A detailed table inside [UID:0002AJ] is the better documentation shape.
- Decision: no split now; keep one ignored tail page.

### First-Draft C++ Eligibility

- Evidence: The page is `RECONSTRUCTABLE:FALSE`; it has no source owner/emitter route; its contents are external CRT/STL/ACRT/runtime mutable storage, compiler-generated guard state, zero-fill tail, and one zlib empty-string coalescing caveat. There is no NexusTK function body, declaration, method, class, or source-authored table to emit.
- Gate result: not eligible for formal C++.
- Exact no-code proof: Any C++ such as `char byte_69C044[0xfbc];`, `static int dword_69C604;`, or CRT private struct declarations would hand-port toolchain/runtime internals into NexusTK source and fight the selected compiler/runtime. Correct rebuild behavior is obtained by compiling/linking a compatible MSVC CRT/STL/ACRT model and the zlib source that owns the `z_errmsg` table, not by emitting this target.

## Internal Runtime / Library Substructure Recommendation

| Range | Best descriptive name | Evidence / rationale | Split? |
| --- | --- | --- | --- |
| `0x0069c044-0x0069c048` | `zeroFillEmptyStringHead` / `zlibErrorMessageEmptyStringSentinel` | Two refs from zlib table entries at `0x00671af8` and `0x00671b14`; no `.text` refs found; physical zero-fill can represent `""` plus alignment. | No split; link to [UID:00028E]. |
| `0x0069c048-0x0069c110` | `stdInitLocksPrimaryStorage` | Startup wrapper constructs at `0x0069c048`; lock array loop `0x0069c050-0x0069c110`, stride `0x18`; cleanup wrapper uses same base. | No split. |
| `0x0069c110-0x0069c170` | `dinkumwareLocaleFacetIosBaseState` | STL locale/facet/ios refs; `std::_Fac_tidy_reg_t` cleanup at `0x0069c134`; `sub_43A5C0(&dword_69C12C)`. | No split. |
| `0x0069c1a0-0x0069c1a4` and nearby | `secondaryStdInitLocksAndInitAtexitState` | Startup constructs second lock state at `0x0069c1a0`; cleanup also uses `_Init_atexit::~_Init_atexit(&unk_69C1A1)`. | No split. |
| `0x0069c1d0-0x0069c26c` | `scrtEncodedWinApiPointerCache` | `?initialize_pointers@@YAHXZ` stores encoded resolved API pointers after resolving `Fls*`, critical-section, init-once, event, semaphore, and threadpool names. | No split. |
| `0x0069c2e8-0x0069c400` | `gsFailureExceptionContextStorage` | Refs from `___report_gsfailure` and `.rdata` `ExceptionInfo` at `0x0063506c`. | No split. |
| `0x0069c604-0x0069c660` | `scrtStartupTlsGuardAndEpochState` | `__scrt_common_main_seh` reads/stores startup-state values at `0x0069c604`; product-address refs to `0x0069c650/654/658` match compiler TLS/static-init guard patterns. | No split. |
| `0x0069c668-0x0069c6a0` | `runtimeCriticalSectionAndHeapCleanupState` | Startup `sub_5c8b0b(&unk_69C668)`; cleanup deletes `stru_69C67C`, frees `unk_69C694`, clears fields. | No split. |
| `0x0069c750-0x0069ca08` | `acrtLowioStdioLockAndAllocationState` | Lowio/env initialization writes count and allocation pointers at `0x0069c750/754`; ACRT code owns lifecycle. | No split. |
| `0x0069ca08-0x0069cc08` | `acrtPioinfoPointerTable` | `114` refs; fd table indexing uses `fd >> 6`, `fd & 0x3f`, `0x30` stride. | No split. |
| `0x0069cc08-0x0069ce24` | `crtTimezoneFileLocaleMultibyteTail` | Refs to timezone, heap, file, locale, and multibyte support including `0x0069cd08`, `0x0069cde4`, `0x0069ce20`. | No split. |
| `0x0069ce24-0x0069d000` | `.data` section-alignment zero tail | Beyond PE `.data` VirtualSize, before `.rsrc` start, modeled by IDA/coverage as `.data` aligned segment tail. | No split; document as alignment tail. |

## Direct Xref / Reachability Inventory

| Address / item | Evidence | Meaning |
| --- | --- | --- |
| `0x00671af8`, `0x00671b14` -> `0x0069c044` | Raw `.data` dword refs | zlib error-message table entries to shared empty string. |
| `0x0041a4cd` -> `0x0069c048`; `0x0060c45a` -> `0x0069c048` | Capstone + docs [UID:0000WF]/[UID:00024J] | startup/cleanup wrappers for first `_Init_locks` object. |
| `0x005c5efd-0x005c5f84` -> `0x0069c050`/`0x0069c110` | Capstone | Dinkumware lock array constructor/destructor/accessor loop. |
| `0x0060c464` -> `0x0069c134`; `0x0060c46e` -> `0x0069c12c` | Existing cleanup docs and raw pointer scan | facet/locale cleanup runtime state. |
| `0x0041a507`, `0x0060c482`, `0x0060c478` -> `0x0069c1a0/1a1` | Existing startup/cleanup docs and raw pointer scan | second `_Init_locks` plus `_Init_atexit` cleanup state. |
| `0x005c6f74+` -> `0x0069c1d0+` | Capstone | encoded OS API-pointer cache. |
| `0x005c75fd`, `0x005c76f8`, `0x0063506c` -> `0x0069c2e8` | Raw pointer scan + [UID:000273] | GS failure exception/security context. |
| `0x005c84f5`, `0x005c8509`, `0x005c8546` -> `0x0069c604` | Capstone | SCRT native startup-state variable. |
| `0x00424878`, `0x00466cbd`, `0x004be8ac`, `0x004c3506` -> `0x0069c650/654` | Capstone samples | compiler-emitted TLS/thread-safe local-static guard state, not product ownership. |
| `0x0041a51d`, `0x0060c48c` -> `0x0069c668` | Existing startup/cleanup docs | runtime critical-section/free-list lifecycle state. |
| `0x005d1b99`, `0x005d1bbf`, many others -> `0x0069ca08` | Capstone + raw pointer scan | ACRT lowio file-handle pointer table. |
| `0x005ec479`, `0x005ec48e` -> `0x0069cd08` | Raw pointer scan + old runtime report | CRT timezone environment state. |
| `0x005efced`, `0x005efcfc`, `0x005efd13`, `0x005efd2d` -> `0x0069cde4` | Capstone | multibyte/locale code-page flag state. |

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE`, ignored runtime/library tail

- Evidence for: Dominant refs are MSVC CRT/STL/ACRT/SCRT runtime support; direct PE mapping shows zero-fill runtime/library storage; existing runtime pages already own the code-side support; by-structure allows reviewed compiler/runtime groupings to remain non-reconstructable and non-emitting.
- Evidence against: `0x0069c044` is referenced by zlib as empty string; some product-address refs touch `0x0069c650/654`.
- Resolution of evidence against: zlib source ownership is already represented by [UID:00028E]'s pointer table; product-address refs are compiler-inserted TLS/static-guard runtime accesses.
- Decision: accepted.

### 2. Assign to [UID:0001QE] `client_libraries`

- Evidence for: This is the meta page for third-party/runtime dependencies and contains MSVC CRT/STL/Dinkumware procurement guidance.
- Evidence against: A by-meta dependency index is not an actual source owner or emitter. Sibling runtime pages keep `CANONICAL_OWNER:NONE`.
- Decision: reject as canonical owner; add/update cross-reference and support text only.

### 3. Split/assign first `0x0069c044-0x0069c048` to zlib

- Evidence for: two direct zlib pointer-table refs to `0x0069c044`, likely representing `""`.
- Evidence against: one-byte zero-fill artifact with no independent source declaration; pointer table already carries the source semantics; splitting would create a low-value child and leave same non-NexusTK status.
- Decision: reject current split; document caveat.

### 4. Assign runtime guard refs to product callers

- Evidence for: raw pointer scan has references from product-address code ranges into `0x0069c650/654`.
- Evidence against: sampled code uses `fs:[0x2c]` TLS/static-guard patterns; this is compiler instrumentation around local statics, not source-authored globals.
- Decision: reject.

## Open-Question Closure

- Is the target reconstructable after reanalysis? No. It remains runtime/library/compiler/linker zero-fill mutable state, not NexusTK source.
- Is the old `0xff` byte evidence safe? No. Correct it to current raw PE zero-fill/unbacked evidence, with note that older IDA result is stale or non-file-view.
- Does the target need a split? No. The first zlib empty-string sentinel and the internal runtime families should be documented inside the page; no source-bearing child split is recommended.
- Should the target end at `0x0069ce24` instead of `0x0069d000`? No for current coverage. `0x0069ce24-0x0069d000` is aligned section tail before `.rsrc` and should be documented as alignment zero-fill, not a separate unknown.
- Should `CANONICAL_OWNER` be [UID:0001QE], [UID:0001Z8], or [UID:0000PC]? No. Keep `NONE`; use cross-references and support docs.
- Is first-draft C++ eligible? No. Exact no-code proof above.
- What remains genuinely uncertain? Exact private CRT/STL field names under some placeholders, such as the precise private Dinkumware names for `dword_69C12C` and the exact public/private variable spellings around `0x0069c650/654/658`. This does not block score `88/90` because it is external runtime data and the source-quality requirement is satisfied by family names, xrefs, and rejected alternatives.

## Proposed Score / Metadata

- `COMPLETION:88`: The page can rise from `85` once it records current PE boundary/zero-fill facts, internal runtime-family map, stale-byte correction, zlib sentinel caveat, no-split decision, and no-code proof.
- `CONFIDENCE:90`: Very strong that this is non-NexusTK runtime/library data. Confidence should not go higher without live IDA MCP rechecking the full xref/name set in the current IDB and recovering exact private CRT/STL symbol spellings.
- `CANONICAL_OWNER:NONE`: runtime/library/compiler artifact, no source owner.
- `RECONSTRUCTABLE:FALSE`: no source object should be emitted.
- `EMITTER_UIDS:` blank.
- `RECONSTRUCTION_CPP CODE`: keep blank.

## Exact Target / Support Implementation Checklist

### Target [UID:0002AJ]

- Update scores to `COMPLETION:88`, `CONFIDENCE:90`.
- Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++.
- Add status note: "source-quality reanalysis confirms final `.data` zero-fill MSVC CRT/STL/ACRT mutable-runtime tail; no NexusTK C++; stale `0xff` byte evidence corrected."
- Replace or qualify the `FF:4028` evidence:
  - current raw PE: `.data` VA `0x0066d000-0x0069ce24`, raw-backed only through `0x0067a800`, aligned end `0x0069d000`;
  - target `0x0069c044-0x0069d000` is unbacked/zero-filled, size `0xfbc` / 4028 bytes (Verified with `int_convert.py`);
  - `0x0069ce24-0x0069d000` is alignment tail, `0x2bc` / 700 bytes (Verified with `int_convert.py`).
- Add internal substructure table from this report, including:
  - `0x0069c044-0x0069c048` zero-fill zlib empty-string sentinel caveat;
  - `0x0069c048-0x0069c110` `std::_Init_locks` primary storage;
  - `0x0069c110-0x0069c170` Dinkumware locale/facet/ios state;
  - `0x0069c1a0/1a1` secondary `_Init_locks` / `_Init_atexit` state;
  - `0x0069c1d0-0x0069c26c` encoded runtime API-pointer cache;
  - `0x0069c2e8-0x0069c400` GS failure context;
  - `0x0069c604-0x0069c660` SCRT startup/TLS/static-guard state;
  - `0x0069c668` critical-section/free cleanup state;
  - `0x0069c750/754`, `0x0069ca08` ACRT lowio/stdio/file table state;
  - `0x0069cd08+` CRT timezone/environment/locale/multibyte storage.
- Add `## Heuristic / Inference Reanalysis And Validation` with the rejected alternatives and no-code proof from this report.
- Add direct evidence summary: IDA/MCP currently unavailable; current raw PE/Capstone checks plus existing documented live IDA facts support classification.
- Add cross-references to [UID:0001Z8], [UID:0001Q4], [UID:00028E], [UID:00028F], [UID:000273], [UID:0000WF], [UID:00024J], [UID:00024B], [UID:00024C], [UID:0001QE], and [UID:0000PC].

### Support Docs

- `by-memory/-ignored.md`: update the [UID:0002AJ] ledger entry to replace `all 4028 bytes initialize to 0xff` with the current raw PE zero-fill/unbacked evidence; add the zlib empty-string sentinel caveat and the `638` raw dword/immediate hits to `194` target addresses.
- `by-memory/0x0066d000-0x0069d000.DataSection.md`: add a child-row/status note that [UID:0002AJ] is now rechecked at `88/90`, final `.data` zero-fill runtime/library tail, with `0x0069ce24-0x0069d000` section-alignment tail; remove any implication that it remains one of the lowest-quality direct children after this pass.
- `by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md`: no score/ownership change required; optionally add one successor-boundary sentence that current B009 reanalysis keeps successor [UID:0002AJ] starting exactly at `0x0069c044` and treats successor refs as zlib/runtime/library zero-fill, not snow descriptor overlap.
- `by-memory/0x00671a74-0x00672eb4.Zlib114DataMessagesAndTables.md`: add a note that the two `0x0069c044` table entries point at a zero-fill empty-string sentinel inside [UID:0002AJ]; the source ownership stays with the zlib error-message table and no separate emitted child is needed.
- `by-memory/0x00672eb4-0x006738c0.MsvcDinkumwareRuntimeMutableData.md`: add cross-reference that its pointer clusters into `0x0069c75c` and `0x0069c760` land in [UID:0002AJ]'s ACRT/lowio/runtime tail.
- `by-memory/0x00632560-0x0066d000.MsvcRuntimeReadOnlyDataTail.md`: add a support note linking `.rdata` `ExceptionInfo`/GS security-failure metadata to [UID:0002AJ]'s mutable `0x0069c2e8-0x0069c400` GS failure context and API-name strings to the encoded API-pointer cache.
- `by-memory/0x0041a4cd-0x0041a550.StaticRuntimeInitializerWrappersAfterUserPanePool.md`: add [UID:0002AJ] cross-reference in the evidence/crossrefs for target storage at `0x0069c048`, `0x0069c134`, `0x0069c12c`, `0x0069c1a0`, and `0x0069c668`.
- `by-memory/0x0060c45a-0x0060c4ac.StaticRuntimeCleanupWrappersAfterUserPanePool.md`: add [UID:0002AJ] cross-reference for the exact cleanup targets `stru_69C050`, `dword_69C110`, `unk_69C134`, `dword_69C12C`, `unk_69C1A1`, `0x0069c668`, `stru_69C67C`, and `unk_69C694`.
- `by-memory/0x005c5c87-0x005cea43.MsvcRuntimeImportAndStlSupport.md`: add support note that the `_Init_locks`, `initialize_pointers`, and `__scrt_common_main_seh` runtime code reads/writes [UID:0002AJ] addresses, including encoded API pointer cache `0x0069c1d0-0x0069c26c` and SCRT startup-state `0x0069c604`.
- `by-memory/0x005cea6d-0x005f66f7.MsvcAcrtStdioLocaleMathSupport.md`: add support note that ACRT lowio/stdio/timezone/locale/multibyte paths use [UID:0002AJ] anchors `0x0069c750`, `0x0069c754`, `0x0069ca08`, `0x0069cd08`, `0x0069cde4`, and `0x0069ce20`.
- `by-meta/client_libraries.md`: add [UID:0002AJ] to the MSVC CRT/STL/Dinkumware support row as the final mutable `.data` zero-fill runtime tail alongside [UID:00028F], [UID:000273], [UID:00024B], and [UID:00024C].
- Do not edit `by-memory/-coverage-report.md`; use the exact supervisor-owned row below.

## Exact Supervisor-Owned Coverage Row

Replace the current [UID:0002AJ] row in `by-memory/-coverage-report.md` with:

```text
    - [UID:0002AJ][0x0069c044-0x0069d000.MsvcRuntimeMutableDataTail](by-memory/0x0069c044-0x0069d000.MsvcRuntimeMutableDataTail.md) 0x0069c044-0x0069d000 | runtime mutable-data tail | MsvcRuntimeMutableDataTail : ignored : 88% : very strong : B009 2026-06-19 source-quality reanalysis keeps `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, and blank emitters; raw PE section-table check shows the span is `.data` virtual zero-fill/unbacked storage (`0x0069c044-0x0069ce24` inside `.data` VirtualSize plus `0x0069ce24-0x0069d000` section-alignment tail), not file-backed NexusTK data, and pointer/immediate scan finds 638 hits to 194 target addresses from MSVC CRT/STL/ACRT/runtime islands including `std::_Init_locks`, locale/facet/ios_base state, CRT atexit, encoded OS API-pointer cache, GS failure context, SCRT startup/TLS state, stdio/lowio/environment locks, heap/timezone/file/locale/multibyte storage; the first `0x0069c044` byte is also the zlib error-table empty-string sentinel already sourced through [UID:00028E][0x00671a74-0x00672eb4.Zlib114DataMessagesAndTables](by-memory/0x00671a74-0x00672eb4.Zlib114DataMessagesAndTables.md), so no NexusTK C++ and no child split are recommended.
```

## Validator Baseline

- Command run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0002AJ-MsvcRuntimeMutableDataTail-source-quality-removed.md](0002AJ-MsvcRuntimeMutableDataTail-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Result: exit code `0`; `apply: False`; `scanned markdown files: 1`; `ok: 1`; target `0002AJ` UID header exists; dry run only; generated reports reported noops. The validator produced unrelated autogen emitter/no-code messages during the dry run, but no target error and no write was requested.

## Changed Files

- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B009\research\0002AJ-MsvcRuntimeMutableDataTail-source-quality.md`.
- Modified: none outside this report file.
- No by-* documentation files were edited.
- `by-memory/-coverage-report.md` was not edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0002AJ-MsvcRuntimeMutableDataTail-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"0002AJ"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002AJ-MsvcRuntimeMutableDataTail-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/0002AJ-MsvcRuntimeMutableDataTail-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002AJ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
