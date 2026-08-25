** TARGET-REPORT-UID:0001B8 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B005 Research Report - [UID:0001B8] Md5FilePathHex

Assignment: `B005-report-0001B8-md5-file-path-hex-20260625`  
Target: [UID:0001B8] `by-memory/0x00515450-0x00515568.Md5FilePathHex.md`  
Mode: report-only research; no leases taken; no by-* docs, generated/project-level files, validator state/cache, IDA DB, or `-coverage-report.md` files edited.

## Current Target State

The target currently has:

- `COMPLETION:86`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000L6`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000L6`
- blank formal `RECONSTRUCTION_CPP CODE`
- Item Summary: raw function-shaped MD5 file-path wrapper with fallback literal and an unchanged no-function/no-caller caveat.

The current body already documents the corrected actual half-open range `0x00515450-0x00515569` while the filename keeps the legacy final-byte suffix `0x00515568`. It also already records the seven `0xcc` padding bytes at `0x00515569-0x00515570`, the `0x474` stack frame, `0x400` file buffer, `_fopen_s("rb")`, `_fread` loop, `Md5Update`, `Md5Final`, `_fclose`, `Md5DigestToHexString`, and fallback literal. The stale part is the reconstruction disposition: it still treats "no IDA function object / no current caller" as a reason to keep formal C++ blank.

Generated context is stale relative to the source target: `auto-generated/NexusTK/util/MD5.cpp` header `validator-command-id: 000000001159`, `validator-refreshed-at: 2026-06-25T03:57:21-04:00`, still lists UID `0001B8` at `76/84` with an empty emitter marker. `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and the manual `by-memory/-coverage-report.md` row are also still rendering the older `76/84` / stale summary. These generated/manual coverage files were read only.

## Evidence Checked In This Pass

Project docs/support checked:

- Target `by-memory/0x00515450-0x00515568.Md5FilePathHex.md`.
- Owner file `by-file/MD5.md`.
- Parent aggregate `by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md`.
- Sibling raw helper `by-memory/0x00515310-0x00515375.Md5BytesHex.md`.
- Related digest item `by-item/PacketDigest_00515380.md`.
- Endian/padding/string support pages: `by-memory/0x00515f50-0x00515ff2.MD5EndianEncodeDecodeHelpers.md`, `by-memory/0x0061ead4-0x0061eadc.Md5HexFormatString.md`, `by-memory/0x0066ddd8-0x0066de18.Md5PaddingBlock.md`.
- Fallback literal container `by-memory/0x0061eadc-0x0061eb08.MapPaneDigitPatternBoundaryTailData.md`.
- Caller-side support `by-item/ScreenshotProofPacket_00558240.md`.
- Read-only generated `auto-generated/NexusTK/util/MD5.cpp`, generated research/coverage rows, and manual coverage row.

IDA MCP was responsive. `idb_list` reported active session `80de0a67` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `26892`. `server_health` for database `80de0a67` returned `status:"ok"`, module `NexusTK.exe`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and string cache ready.

Binary baseline from MCP survey/context:

- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Input binary: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- SHA256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
- `.text`: `0x00401000-0x0060d000`

## Live MCP Findings

`lookup_funcs` for the target neighborhood in session `80de0a67`:

- `0x005153e0` is modeled as `sub_5153E0`, size `0x65`.
- `0x00515445`, `0x00515450`, `0x00515568`, and `0x00515569` are not functions.
- `0x00515570` is modeled as `sub_515570`, size `0xeb`.
- `0x0051565b` is not a function.

`xrefs_to` findings:

- `xrefs_to 0x00515450`: zero xrefs.
- `xrefs_to 0x00515568`: one code xref from `0x00515567`, `fn:null`, which is the raw body's own `pop ebp` before `retn`, not an external route.
- `xrefs_to 0x00515569`: zero xrefs.
- `xrefs_to 0x00515570`: one code xref from `0x00558278` in `sub_558240`, matching `ScreenshotProofPacket` use of `Md5StreamHex`.
- `xrefs_to 0x0061eadc`: two data xrefs, `0x00515559` with `fn:null` from this raw target and `0x0051564a` in `sub_515570`.

Focused disassembly of `0x00515450` returned `<no function>` but decoded a complete source-shaped body:

- Prologue at `0x00515450`, stack allocation `sub esp, 474h`.
- File path argument loaded from `[ebp+8]` into `esi`.
- Local file buffer address `[ebp-404h]`, size `0x400`.
- Standard MD5 state constants written at context base `[ebp-470h]`: `0x67452301`, `0xefcdab89`, `0x98badcfe`, `0x10325476`.
- Bit count zeroed with `xorps/movq` at `[ebp-460h]`.
- `_memset` at `0x005154a8` zeroes the 1024-byte file buffer.
- `_fopen_s` at `0x005154ba` uses mode literal `"rb"` from `0x0060df9c`.
- Successful path loops over `_fread` at `0x005154e0` and `0x00515517`, calling `sub_515690` / `Md5Update` at `0x005154fe` for each nonzero chunk.
- Finalization path calls `sub_515750` / `Md5Final` at `0x00515529`, `_fclose` at `0x00515534`, and `sub_5151F0` / `Md5DigestToHexString` at `0x00515540`.
- Failed-open path returns fallback literal address `0x0061eadc` at `0x00515559`.
- The final `retn` is at `0x00515568`; `0x00515569` begins alignment padding before `sub_515570`.

`decompile 0x00515450` fails with `Decompilation failed at 0x515450`, which is expected because IDA has no function object at the raw start. This is a tool-modeling limitation, not a behavior uncertainty.

Sibling/helper decompilation:

- `analyze_function 0x00515570` gives `char *__cdecl(FILE *Stream)` for `sub_515570`, size `235` decimal / `0xeb`. It initializes the same MD5 context, zeroes a 1024-byte buffer, returns the same fallback literal if `Stream` is null, otherwise loops over `fread`, calls `sub_515690`, calls `sub_515750`, and returns `sub_5151F0((int)v5)`. Its only caller is `sub_558240`.
- `analyze_function 0x005151f0` gives `char *__cdecl(int)` for the hex formatter, which formats 16 digest bytes with `%02x`, appends into a 256-byte local buffer, and returns `_strdup(Source)`.
- `analyze_function 0x00515690` gives `void *__thiscall(int *this, char *Src, unsigned int)`, confirming that `Md5Update` receives the context in `ecx`.
- `analyze_function 0x00515750` gives `void *__thiscall(int *this)`, confirming that `Md5Final` also receives the context in `ecx`, writes the digest at context offset `0x58`, and clears state/count/buffer storage.
- `analyze_function 0x00515290` gives `char *__cdecl(char *Src)` for the string wrapper and shows the same inline MD5 initialization followed by `sub_515690`, `sub_515750`, and `sub_5151F0`.

`make_signature_for_range 0x00515450-0x00515569`, with operands not wildcarded, returned a unique full-body signature. `make_signature_for_range 0x00515569-0x00515570` returned `CC CC CC CC CC CC CC`, unique `false`, confirming a pure seven-byte alignment gap.

MCP `int_convert` verified:

- `0x119` = `281`
- `0x474` = `1140`
- `0x400` = `1024`
- `0xeb` = `235`
- `0x151` = `337`

## Raw PE Route Scan

I ran a read-only PE scan of `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` for absolute VA little-endian values, RVA little-endian values, and direct `E8/E9 rel32` routes.

Results:

- Target `0x00515450`: raw file offset `0x114850`; no VA pointer hits, no RVA pointer hits, and no direct relative call/jump hits.
- Control target `0x00515570`: one direct call at VA `0x00558278`, matching `ScreenshotProofPacket` -> `Md5StreamHex`.
- Control target `0x00515380`: one direct call at VA `0x00578da5`, matching the packet digest route.

This supports the no-current-route caveat for `Md5FilePathHex` while proving the scan is able to find ordinary direct routes when they exist.

## Range And Split Decision

Keep the current documentation split:

- Source body: `0x00515450-0x00515569`.
- Padding: `0x00515569-0x00515570`, seven `0xcc` bytes.
- Successor modeled helper: `0x00515570-0x0051565b`, `Md5StreamHex`.

Do not rename the Markdown file in this report. The filename suffix `0x00515568` is legacy but already explained in the target body, and changing paths would add avoidable UID/link churn. The target title/body should keep emphasizing the actual exclusive end `0x00515569`.

No merge is recommended. The target is a complete helper body with its own prologue, stack frame, return paths, and padding boundary. It should not be merged into `Md5BytesToBuffer`, `Md5StreamHex`, `ScreenshotProofPacket`, `RegistryConfig`, `Socket`, `MapPane`, or any fallback-literal data page.

## Ownership And Source Placement

Recommended owner/emitter remains:

- `CANONICAL_OWNER:0000L6`
- `EMITTER_UIDS:0000L6`
- source placement: `NexusTK/util/MD5.cpp`
- `RECONSTRUCTABLE:TRUE`

Positive evidence:

- The body is inside the documented MD5 helper island and uses the same inline MD5 initialization, update/final/final-hex chain, and fallback literal as the modeled stream wrapper.
- The helper is algorithm-specific and file/path-specific; it has no class state, no UI state, no packet layout ownership, and no registry-only behavior.
- `by-file/MD5.md` already owns the string, byte, file, stream, update, final, transform, padding, and hex formatter family as a cross-subsystem utility file.
- The sibling `Md5StreamHex` is live through screenshot proof, while the file-path wrapper is currently retained but route-less. That is plausible utility-module source shape: not every utility wrapper must have a visible current direct caller in the optimized binary or active feature set.

Rejected alternatives:

- `ScreenshotCapture` / `ScreenshotProofPacket`: those docs use `Md5StreamHex` at `0x00515570`, not the raw file-path helper. They consume MD5 but do not own MD5 implementation.
- `Socket` / `PacketTransform`: packet code uses the raw digest wrapper at `0x00515380`; it does not own this file-open helper.
- `RegistryConfig`: registry code uses the output-buffer MD5 helper at `0x005153e0`, not this file-path helper.
- `MapPane`: the fallback literal currently lives inside a mixed `.rdata` tail page whose title includes MapPane, but its only xrefs are the MD5 file and stream helpers. The literal's source owner is MD5/fallback behavior, while the mixed tail page remains a non-emitting boundary audit item.
- CRT/library: the body is custom wrapper code around CRT file I/O and the local MD5 implementation, not a CRT implementation.

## Fallback Literal

The fallback literal is exactly:

`"000011112222333344445555666677778888"`

It is not a 32-character normal MD5 hex digest; it is a 36-character sentinel-looking digit pattern. Current evidence proves use, not original intent. Its only IDA xrefs in the checked pass are:

- `0x00515559` from the raw file-path helper, `fn:null`.
- `0x0051564a` from `sub_515570` / `Md5StreamHex`.

Recommended source handling: emit the literal as the fallback return for both file-path-open failure and null stream. The exact original reason/name for the sentinel remains an uncertainty, but it is not a reason to keep `Md5FilePathHex` blank. The fallback literal container page should be synchronized to say the literal portion is MD5-owned behavior even though the combined `0x0061eadc-0x0061eb08` mixed tail item remains non-emitting as one page.

## C++ Readiness Decision

Formal first-draft C++ is safe for this target.

Why the old blank-C++ blocker should be retired:

- IDA no-function state blocks decompiler convenience, not reconstruction. The raw body has a complete prologue, two return paths, a unique `0x119`-byte signature, exact padding, and direct instruction-level behavior.
- No-current-caller/no-pointer remains real negative evidence, but it is a liveness/confidence cap, not an emitter blocker. The helper is already reconstructable, owner/emitter are already stable, and the target covers a whole function-shaped body.
- Source signature is strongly inferred from direct usage: `[ebp+8]` is passed as the `filename` argument to `_fopen_s`, never written; return values are either the heap string from `Md5DigestToHexString` or the static fallback literal; the modeled stream sibling returns `char *`.
- The local MD5 context method calls are confirmed as `__thiscall` for update/final, so formal C++ should use a source-level MD5 context object shape rather than decompiler labels or `sub_` names. The exact broader helper class/type spelling remains a support-file confidence cap, not a target-body blocker.

Exact formal `RECONSTRUCTION_CPP CODE` content recommended for insertion:

```cpp
char *Md5FilePathHex(const char *path)
{
    FILE *stream;
    MD5Context context;
    char buffer[1024];
    size_t bytesRead;

    context.state[0] = 0x67452301;
    context.state[1] = 0xefcdab89;
    context.state[2] = 0x98badcfe;
    context.state[3] = 0x10325476;
    context.count[0] = 0;
    context.count[1] = 0;
    memset(buffer, 0, sizeof(buffer));

    fopen_s(&stream, path, "rb");
    if (stream == NULL)
        return "000011112222333344445555666677778888";

    bytesRead = fread(buffer, 1, sizeof(buffer), stream);
    while (bytesRead != 0)
    {
        context.Update(buffer, bytesRead);
        bytesRead = fread(buffer, 1, sizeof(buffer), stream);
    }

    context.Final();
    fclose(stream);
    return Md5DigestToHexString(context.digest);
}
```

Notes for implementation:

- `MD5Context` is an inferred source-facing context object matching the observed layout: `state[4]`, `count[2]`, a 64-byte internal buffer, and digest bytes at offset `0x58`.
- `context.Update` and `context.Final` are chosen because live MCP confirms `sub_515690` and `sub_515750` are `__thiscall` helpers taking the context in `ecx`.
- The inline state/count initialization is kept instead of calling a hypothetical `Init` helper because the binary emits direct stores here.
- `stream` is intentionally not initialized before `fopen_s`, matching the absence of an earlier zero store. The binary tests the stored stream pointer after the call and ignores the `_fopen_s` return value.
- The literal is returned as `char *` to match the modeled sibling's `char *` return and the heap-string success path, even though a modern source rewrite might prefer `const char *`.

## Score And Metadata Recommendation

Target recommendation:

- `COMPLETION:89` from `86`
- `CONFIDENCE:91` from `90`
- `CANONICAL_OWNER:0000L6` unchanged
- `RECONSTRUCTABLE:TRUE` unchanged
- `EMITTER_UIDS:0000L6` unchanged
- `EMITTER_POSITION_OPTIONAL:` unchanged

Recommended target `Item Summary`:

`Source-ready raw MD5 file-path hex wrapper; current MCP confirms the unique 0x119-byte half-open body, 0x474 stack frame, 0x400 file buffer, _fopen_s("rb"), chunked fread/Md5Update loop, Md5Final, fclose, Md5DigestToHexString, shared fallback literal, seven-byte 0xcc padding, and no raw-start xrefs or PE call/pointer hits; formal first-draft C++ is ready with no-route/helper-spelling caveats retained.`

Why `89/91`:

- Completion rises because the target can now carry formal first-draft source for the exact body, and the old blank-C++ rationale is no longer supported by current evidence.
- Confidence rises because the no-route caveat is now backed by both IDA xrefs and a raw PE scan with positive controls, while source owner, range, bytes, fallback, and helper behavior all agree.
- Completion does not go higher because IDA still has no function object at `0x00515450`, the raw start has no direct call/pointer route, and exact original helper/type spelling remains inferred.
- Confidence does not go higher because fallback-literal intent and exact broader MD5 context source type names are not proven from original source metadata.

## Required Target/Support Doc Changes If Accepted

### Target: `by-memory/0x00515450-0x00515568.Md5FilePathHex.md`

Apply the metadata and summary above. Insert the exact formal C++ block between `RECONSTRUCTION_CPP CODE:BEGIN` and `END`. Update Status/Reconstruction Notes/Score Rationale/Changes to preserve these report facts at report-level detail:

- Current MCP session `80de0a67`, health-ready IDB, and target neighborhood function lookup.
- No function object at `0x00515450`, `0x00515568`, or `0x00515569`; modeled neighbors `0x005153e0` and `0x00515570`.
- Exact body `0x00515450-0x00515569`, `0x119` / 281 bytes, unique full-body signature.
- Seven `0xcc` bytes at `0x00515569-0x00515570`.
- `0x474` stack frame, `0x400` file buffer, MD5 constants, bit-count zeroing, `_memset`, `_fopen_s("rb")`, `_fread` loop, `Md5Update`, `Md5Final`, `_fclose`, `Md5DigestToHexString`, fallback literal path.
- `xrefs_to 0x00515450` remains empty; raw PE scan also found no VA/RVA pointer or direct rel32 route to `0x00515450`, while controls found the stream and packet digest calls.
- The no-route caveat remains, but it is now a confidence cap rather than a blank-C++ blocker.

### Support: `by-file/MD5.md`

Recommended score: `88/87` from `87/86`.

Update Contents/Evidence/Caveats/Changes to say [UID:0001B8] is now source-ready with formal first-draft C++ for `Md5FilePathHex(const char *path)` / path-to-hex behavior. Preserve that:

- `0x00515450` remains raw/no-function/no-route.
- `Md5FilePathHex` uses `_fopen_s("rb")`, chunked 1024-byte reads, `Md5Update`, `Md5Final`, `_fclose`, `Md5DigestToHexString`, and the shared fallback literal.
- No-route remains a liveness caveat for the wrapper, not evidence against MD5 utility ownership.
- Final MD5 module C++ as a whole is still capped by other unresolved helpers, especially `Md5BytesHex`, `Md5BytesRaw`, endian helper liveness, and exact context/helper class naming.

### Support: `by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md`

Recommended score: `86/89` from `85/88`.

Update the range row and reconstruction notes for `0x00515450-0x00515569` to say this child now has formal first-draft C++ and no longer waits on caller liveness for target-level emission. Preserve that aggregate C++ remains blank because broader helper signatures and stack-return behavior are still unresolved at aggregate level.

### Support: `by-memory/0x0061eadc-0x0061eb08.MapPaneDigitPatternBoundaryTailData.md`

Recommended score: unchanged `85/92`.

Update Summary/Rebuild handling/Evidence/Changes to clarify:

- The ASCII digit-pattern literal at `0x0061eadc` is the shared MD5 fallback literal referenced by `Md5FilePathHex` and `Md5StreamHex`.
- The combined child remains non-emitting because it also includes four zero bytes and the `MemoryMan` COL boundary dword.
- Do not treat the literal as MapPane-authored source; the literal portion should be emitted through MD5 helper source when those helpers are emitted.

### Check-Only Support

No edit recommended for these unless the supervisor wants extra cross-reference wording:

- `by-memory/0x00515310-0x00515375.Md5BytesHex.md`: remains a raw bytes-to-hex sibling with its own no-caller/source-signature issue.
- `by-item/PacketDigest_00515380.md`: packet digest route is only a control/check, not owner of this file-path helper.
- `by-item/ScreenshotProofPacket_00558240.md`: already correctly uses `Md5StreamHex` at `0x00515570`, not this target.
- `by-memory/0x0061ead4-0x0061eadc.Md5HexFormatString.md` and `by-memory/0x0066ddd8-0x0066de18.Md5PaddingBlock.md`: no contradiction found.

## Generated And Coverage Expectations

Do not manually edit generated files. After accepted implementation and validators, `auto-generated/NexusTK/util/MD5.cpp` should refresh from `by-file/MD5.md` and include the UID `0001B8` formal C++ block instead of the current empty marker. The generated file header should have a `validator-command-id` and `validator-refreshed-at` equal to or newer than the validator command that refreshed the target/support file.

Do not edit `auto-generated/-ag-research-tracker.md` or `auto-generated/-ag-coverage-report-by-memory.md`; they should refresh through validator/report execution flows.

The manual row in `by-memory/-coverage-report.md` is supervisor-owned. If the supervisor still wants manual coverage synchronized after accepting this report, use this replacement row for UID `0001B8`:

```markdown
    - [UID:0001B8][0x00515450-0x00515568.Md5FilePathHex](by-memory/0x00515450-0x00515568.Md5FilePathHex.md) : reconstructable : 89% : very strong : Source-ready raw MD5 file-path hex wrapper; current MCP confirms the unique 0x119-byte half-open body, 0x474 stack frame, 0x400 file buffer, _fopen_s("rb"), chunked fread/Md5Update loop, Md5Final, fclose, Md5DigestToHexString, shared fallback literal, seven-byte 0xcc padding, and no raw-start xrefs or PE call/pointer hits; formal first-draft C++ is ready with no-route/helper-spelling caveats retained.
```

B005 should not apply that manual coverage edit during a normal implementation callback unless the supervisor explicitly overrides the coverage-report exclusion.

## Remaining Uncertainty

- No direct code xref, data xref, VA pointer, RVA pointer, or direct rel32 route currently reaches `0x00515450`.
- IDA still has no function object for the raw start, so function-local type recovery remains manual.
- `Md5FilePathHex` is the best source-facing name, but exact original spelling is inferred from behavior and MD5 module style, not debug metadata.
- `MD5Context`, `Update`, and `Final` are source-facing inferred names. The `__thiscall` convention is confirmed, but exact original class/type names are not.
- The fallback literal's original semantic name/reason remains unknown. It is confirmed behavior and should be emitted literally.

These uncertainties cap score/confidence, but none blocks target-level formal first-draft C++.

## Implementation Tracking Checklist

- [x] Target metadata: update `by-memory/0x00515450-0x00515568.Md5FilePathHex.md` to `COMPLETION:89`, `CONFIDENCE:91`, with owner/emitter/reconstructable unchanged.
  - Proof: target header readback after validation shows `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000L6`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000L6`.
- [x] Target summary: replace the stale blank-C++/no-caller summary with the report's source-ready Item Summary.
  - Proof: target readback after validation shows `Item Summary: Source-ready raw MD5 file-path hex wrapper; current MCP confirms... formal first-draft C++ is ready with no-route/helper-spelling caveats retained.`
- [x] Target C++: insert the exact formal `Md5FilePathHex` code block between `RECONSTRUCTION_CPP CODE:BEGIN` and `END`.
  - Proof: target header readback after validation shows the exact accepted `char *Md5FilePathHex(const char *path)` block with `MD5Context`, 1024-byte buffer, `_fopen_s("rb")`, fallback literal, chunked `fread`, `context.Update`, `context.Final`, `fclose`, and `Md5DigestToHexString(context.digest)`.
- [x] Target evidence/body: preserve current MCP session `80de0a67`, function lookup, xrefs, disassembly facts, unique `0x119` signature, seven-byte padding, internal calls, fallback literal xrefs, and raw PE no-route scan.
  - Proof: target section `2026-06-25 B005 Source-Ready Evidence` now records MCP session `80de0a67`, health-ready IDB, lookup/xref/disassembly/decompile/signature/int_convert facts, sibling helper analysis, and the read-only PE route scan with control hits.
- [x] Target rationale: update Status/Reconstruction Notes/Score Rationale/Changes so no-function/no-current-caller remains a confidence cap rather than a blank-C++ blocker.
  - Proof: target Status says no function/no route are liveness/confidence caps rather than blank-C++ blockers; Score Rationale documents `89/91`; Reconstruction Notes say formal C++ is present and no-route no longer blocks target-level emission; Changes records the 2026-06-25 B005 accepted implementation.
- [x] `by-file/MD5.md`: update to `88/87`, add the source-ready `Md5FilePathHex` decision, preserve no-route caveat, and keep broader MD5 module C++ caveats.
  - Proof: support header readback shows `COMPLETION:88`, `CONFIDENCE:87`; Contents/Evidence/Caveats/Changes now describe UID `0001B8` as source-ready while keeping no-route as a liveness cap and broader MD5 C++ caveats for `Md5BytesHex`, `Md5BytesRaw`, endian helper liveness, and exact context/helper spelling.
- [x] `by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md`: update to `86/89`, synchronize the `Md5FilePathHex` row/reconstruction notes, and keep aggregate C++ blank pending broader helper signatures.
  - Proof: support header readback shows `COMPLETION:86`, `CONFIDENCE:89`; the range row and 2026-06-25 B005 section state that UID `0001B8` has target-level formal C++ while the aggregate C++ remains blank pending broader helper signatures and stack-return behavior.
- [x] `by-memory/0x0061eadc-0x0061eb08.MapPaneDigitPatternBoundaryTailData.md`: keep score unchanged, but clarify that the literal portion is the MD5 fallback literal while the combined mixed-tail page remains non-emitting.
  - Proof: support header readback shows score unchanged at `85/92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters; Summary/Rebuild handling/Evidence/Changes now identify the leading literal as the shared MD5 fallback while preserving mixed-tail non-emitting status because of zero padding and the `MemoryMan` COL boundary dword.
- [x] Check-only docs: confirm no edits are required for `Md5BytesHex`, `PacketDigest_00515380`, `ScreenshotProofPacket_00558240`, `Md5HexFormatString`, or `Md5PaddingBlock` unless supervisor adds cross-reference wording.
  - Proof: these docs were checked during the accepted report. No new stale contradiction appeared during implementation; they were left unchanged.
- [x] Validators after implementation, from `source-3/project-documentation`:
  - Target: `python .\tools\validator.py --mode file --file by-memory\0x00515450-0x00515568.Md5FilePathHex.md --apply --queue-timeout 240 --wait-generated`; `command_id: 000000001232`, `command_timestamp: 2026-06-25T04:42:40-04:00`, exit 0, `ok: 1`, `generated_refresh: completed`, generated command `000000001232`.
  - MD5 file: `python .\tools\validator.py --mode file --file by-file\MD5.md --apply --queue-timeout 240 --wait-generated`; `command_id: 000000001233`, `command_timestamp: 2026-06-25T04:42:58-04:00`, exit 0, `ok: 1`, `generated_refresh: completed`, generated command `000000001233`. Known unrelated warning: `missing_ref_uid 0003J1` reported four times.
  - MD5 helper aggregate: `python .\tools\validator.py --mode file --file by-memory\0x005151f0-0x00515f48.MD5HashHelpers.md --apply --queue-timeout 240 --wait-generated`; `command_id: 000000001235`, `command_timestamp: 2026-06-25T04:43:16-04:00`, exit 0, `ok: 1`, `generated_refresh: completed`, generated command `000000001235`. Known unrelated warning: `missing_ref_target 0001I1` for existing stale `SocketTransportCore` path.
  - Fallback literal tail: `python .\tools\validator.py --mode file --file by-memory\0x0061eadc-0x0061eb08.MapPaneDigitPatternBoundaryTailData.md --apply --queue-timeout 240 --wait-generated`; `command_id: 000000001237`, `command_timestamp: 2026-06-25T04:43:32-04:00`, exit 0, `ok: 1`, `generated_refresh: completed`, generated command `000000001237`.
- [x] Generated-output check: after validators, read `auto-generated/NexusTK/util/MD5.cpp` header and UID `0001B8` block; confirm generated metadata is equal/newer than the relevant validator command and the block is no longer an empty emitter marker.
  - Proof: generated readback shows `validator-command-id: 000000001237`, `validator-refreshed-at: 2026-06-25T04:43:32-04:00`, and UID `0001B8` emits the `char *Md5FilePathHex(const char *path)` block at `Completion:89 | Confidence:91`; it is no longer an empty emitter marker.
- [x] Generated reports: do not edit `auto-generated/-ag-research-tracker.md` or `auto-generated/-ag-coverage-report-by-memory.md`; expect refresh through validator/report execution.
  - Proof: no manual generated-report edits were made. Validator-owned generated refreshes updated generated outputs as side effects; `auto-generated/-ag-coverage-report-by-memory.md` was reported as `memory_auto_coverage_update` by the scoped validators.
- [x] Manual coverage: do not edit `by-memory/-coverage-report.md` unless supervisor explicitly authorizes it; if authorized, use the exact replacement row supplied in this report.
  - Proof: no manual `-coverage-report.md` file was edited.
- [x] Lease discipline for callback: lease only the target/support files immediately before editing, release leases immediately after the edit/validator batch, and report release/expiry proof.
  - Proof: leased exactly `by-memory\0x00515450-0x00515568.Md5FilePathHex.md`, `by-file\MD5.md`, `by-memory\0x005151f0-0x00515f48.MD5HashHelpers.md`, and `by-memory\0x0061eadc-0x0061eb08.MapPaneDigitPatternBoundaryTailData.md`; all four lease commands returned `Success`. After validators/readback, `python .\tools\leaser\leaser.py B005 unlease ...` returned `Success` for all four. Current lease report readback shows no active B005 lease entries; only expired 2026-06-18 Supervisor entries remain.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0001B8-Md5FilePathHex-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0001B8-Md5FilePathHex-source-quality.md","timestamp":"2026-06-25T04:50:30","uid":"0001B8"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
