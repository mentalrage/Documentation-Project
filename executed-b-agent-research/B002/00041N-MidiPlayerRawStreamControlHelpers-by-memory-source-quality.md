** TARGET-REPORT-UID:00041N **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B002 Research Report: [UID:00041N] MidiPlayerRawStreamControlHelpers

Assignment: `B002-report-00041N-MidiPlayerRawStreamControlHelpers-by-memory-20260701`  
Target path: `by-memory/0x00526350-0x00526452.MidiPlayerRawStreamControlHelpers.md`  
Requested mode: report-only research; no target/support/generated/coverage/tool-state edits.  
MCP status: available and used. No subagents used.

## Executive Recommendation

Keep the target as a reconstructable private `MidiPlayer.cpp` helper cluster owned and emitted by [UID:0000LD][MidiPlayer]. The existing formal C++ is behaviorally consistent with current MCP disassembly and should be preserved with no code changes.

Recommended metadata for the target:

| Field | Current | Recommended | Rationale |
| --- | ---: | ---: | --- |
| `COMPLETION` | 85 | 87 | Current MCP confirms exact raw-body boundaries, no-function status, no direct/pointer route to raw starts, padding, and C++ behavior. |
| `CONFIDENCE` | 86 | 88 | Confidence improves from fresh byte/disassembly evidence and generated-output parity, but should stay below 90 because the helpers have no IDA functions, no original symbols, no xrefs to their starts, and some state/global names remain descriptive reconstructions. |
| `CANONICAL_OWNER` | `0000LD` | `0000LD` | Private file-scope `MidiPlayer.cpp` helper bodies; not class methods and not global-data ownership. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | The bodies are source-shaped and already have formal C++ that matches the raw bytes. |
| `EMITTER_UIDS` | `0000LD` | `0000LD` | Emitted in `auto-generated/NexusTK/audio/MidiPlayer.cpp`; no separate implementation owner is supported. |
| `EMITTER_POSITION_OPTIONAL` | blank | blank | No ordering override needed beyond current file placement. |

Implementation callback scope, if accepted: update only the target documentation evidence/metadata unless the supervisor separately accepts the duplicate-UID/support-link cleanup described below. Do not change the formal C++ block for this target.

## MCP Evidence Used

IDA MCP database/session:

- `idb_list`: active session `supervisor_resume_20260629`; input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; worker PID `14860`; `is_analyzing:false`.
- `server_health`: status `ok`; module `NexusTK.exe`; IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`; imagebase `0x400000`; auto-analysis ready `true`; Hex-Rays ready `true`; strings cache ready `true`.

Function/range evidence:

- `lookup_funcs`:
  - `0x00526340`: `sub_526340`, size `0x10`.
  - `0x00526350`: not a function.
  - `0x0052639a`: not a function.
  - `0x005263a0`: not a function.
  - `0x005263dc`: not a function.
  - `0x005263e0`: not a function.
  - `0x00526451`: not a function.
  - `0x00526452`: not a function.
  - `0x00526460`: `sub_526460`, size `0x109`.
- `entity_query` for functions in `0x00526330-0x00526470`: only neighboring `sub_526340` at `0x526340` and `sub_526460` at `0x526460`; no functions at the three target raw starts.
- `get_bytes 0x00526332 size 14`: all `0xcc`, confirming padding before `sub_526340`.
- `get_bytes 0x00526350 size 258`: bytes decode as the three helper bodies ending at `0x00526451`.
- `get_bytes 0x00526452 size 14`: all `0xcc`, confirming padding before reset helper `sub_526460`.

Route/xref evidence:

- `xrefs_to` and `xref_query direction=to`:
  - `0x00526350`: zero xrefs.
  - `0x005263a0`: zero xrefs.
  - `0x005263e0`: zero xrefs.
  - `0x00526460`: eleven xrefs, including raw target calls at `0x526376` and `0x526411`.
- `find_bytes` for VA pointers `50 63 52 00`, `A0 63 52 00`, `E0 63 52 00`: zero matches.
- `find_bytes` for RVA pointers `50 63 12 00`, `A0 63 12 00`, `E0 63 12 00`: zero matches.

WinMM/import evidence:

- `imports_query`:
  - `midiStreamRestart` imported from `WINMM` at `0x60d4f4`.
  - `midiStreamPause` imported from `WINMM` at `0x60d4f8`.
  - `midiStreamStop` imported from `WINMM` at `0x60d4f0`.
  - `midiOutReset` imported from `WINMM` at `0x60d4d8`.

Reset-helper context:

- `decompile 0x00526460` confirms reset helper behavior: clears pending/running state, manages stream-state transitions, calls `midiStreamStop`, `midiOutReset`, waits on the stream event, releases document/buffers, closes the stream, clears document-loaded state, and conditionally reopens/prime-buffers unless `a1 & 0x10000`.
- `decompile 0x00526350` failed because the target start is not an IDA function, which is expected for this raw helper cluster.

## Raw Disassembly Findings

Current MCP `disasm 0x00526350` confirms the target consists of three source-shaped raw helpers separated by compiler alignment.

### `0x00526350-0x0052639a`: `OpenSelectedMidiFileNoRestart`

Important instructions:

```asm
00526350  push    ebp
00526351  mov     ebp, esp
00526353  push    dword ptr [ebp+8]
00526356  push    104h
0052635b  push    69B618h
00526360  call    _wcscpy_s
00526368  cmp     dword ptr unk_69B514, 0
0052636f  jz      short 0052637e
00526371  push    10000h
00526376  call    sub_526460
0052637e  call    sub_525920
00526383  mov     ecx, dword ptr unk_69B514
00526389  test    eax, eax
0052638b  mov     edx, 1
00526390  cmovz   ecx, edx
00526393  mov     dword ptr unk_69B514, ecx
0052639a  retn    4
```

Interpretation:

- Copies the selected path into `0x0069b618` with `_wcscpy_s(dest, 0x104, path)`, matching `g_midiCurrentPath`.
- If `g_midiDocumentLoaded` is already nonzero, calls reset helper `sub_526460(0x10000)` before opening.
- Calls `MidiStreamOpenAndPrimeBuffers` at `0x00525920`.
- Sets `g_midiDocumentLoaded` to `1` only when open/prime returns `0`; otherwise preserves the existing value.
- Existing C++ for `OpenSelectedMidiFileNoRestart(const wchar_t *path)` matches this behavior.

### `0x005263a0-0x005263dc`: `ToggleMidiStreamPause`

Important instructions:

```asm
005263a0  cmp     dword ptr unk_69B50C, 0
005263a7  push    dword ptr ds:69B500h
005263ad  jz      short 005263c6
005263af  call    ds:midiStreamRestart
005263b5  xor     eax, eax
005263b7  cmp     dword ptr unk_69B50C, eax
005263bd  setz    al
005263c0  mov     dword ptr unk_69B50C, eax
005263c5  retn
005263c6  call    ds:midiStreamPause
005263cc  xor     eax, eax
005263ce  cmp     dword ptr unk_69B50C, eax
005263d4  setz    al
005263d7  mov     dword ptr unk_69B50C, eax
005263dc  retn
```

Interpretation:

- If `g_midiRestartPending` is nonzero, calls `midiStreamRestart(g_hMidiStream)` and clears the flag to `0`.
- If it is zero, calls `midiStreamPause(g_hMidiStream)` and sets the flag to `1`.
- The binary uses `setz` against the old global value after the WinMM call; because the imported WinMM call does not write this global, the existing source-shaped direct assignments are behaviorally equivalent.
- Existing C++ for `ToggleMidiStreamPause()` matches this behavior.

### `0x005263e0-0x00526451`: `RestartSelectedMidiStream`

Important instructions:

```asm
005263e0  cmp     dword ptr unk_69B50C, 0
005263e7  jz      short 00526406
005263e9  push    dword ptr ds:69B500h
005263ef  call    ds:midiStreamRestart
005263f5  xor     eax, eax
005263f7  cmp     dword ptr unk_69B50C, eax
005263fd  setz    al
00526400  mov     dword ptr unk_69B50C, eax
00526405  retn
00526406  cmp     dword ptr unk_69B518, 0
0052640d  jz      short 00526419
0052640f  push    0
00526411  call    sub_526460
00526419  cmp     dword ptr unk_69B514, 0
00526420  jz      short 00526447
00526422  push    dword ptr ds:69B500h
00526428  mov     dword ptr unk_69B508, 0
00526432  call    ds:midiStreamRestart
00526438  test    eax, eax
0052643a  jnz     short 00526451
0052643c  mov     dword ptr unk_69B518, 1
00526446  retn
00526447  mov     dword ptr unk_69B518, 0
00526451  retn
```

Interpretation:

- If `g_midiRestartPending` is set, restarts the stream and clears the pending flag.
- If not pending and `g_midiStreamRunning` is set, calls reset helper `sub_526460(0)`.
- If `g_midiDocumentLoaded` is set, clears `g_midiStreamState`, calls `midiStreamRestart(g_hMidiStream)`, and sets `g_midiStreamRunning = 1` only on success.
- If no document is loaded, sets `g_midiStreamRunning = 0`.
- It does not call `ApplyMidiVolume`, which distinguishes it from `StartSelectedMidiFile` in [UID:0001CH].
- Existing C++ for `RestartSelectedMidiStream()` matches this behavior.

Alignment/boundaries:

- `0x0052639d`: `align 10h` before `0x005263a0`.
- `0x005263dd`: `align 10h` before `0x005263e0`.
- `0x00526452-0x0052645f`: `0xcc` padding before `sub_526460`.
- Neighbor before target: `sub_526340` is exactly `0x00526340-0x0052634f`.
- Neighbor after target: reset helper `sub_526460` starts at `0x00526460`.

## Existing Documentation/Generated Evidence

Target document:

- `by-memory/0x00526350-0x00526452.MidiPlayerRawStreamControlHelpers.md` currently has `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000LD`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LD`, and a populated formal C++ block.
- Its current covered-body boundaries match MCP evidence: three raw helper bodies plus padding before reset helper.

Generated output:

- `auto-generated/NexusTK/audio/MidiPlayer.cpp` already emits the three UID00041N helper functions with the same source-shaped behavior.
- `auto-generated/-ag-memory-coverage.md` lists UID00041N as `coded`, owner/emitter `0000LD`, generated path `auto-generated/NexusTK/audio/MidiPlayer.cpp`.
- `auto-generated/-ag-coverage-report-by-memory.md` lists UID00041N as code-emitting/reconstructable at the current 85/86 level.
- These generated/coverage files were read only; they should not be edited directly during target implementation.

Support docs:

- `by-file/MidiPlayer.md` already places UID00041N under `NexusTK/audio/MidiPlayer.cpp` and distinguishes these raw stream-control helpers from `StartSelectedMidiFile`.
- `by-class/MidiPlayer.md` treats these as related free helpers rather than class methods.
- `by-global/MidiPlayerWinMMState.md` and `by-memory/0x0069b500-0x0069b870.MidiPlayerWinMMStateGlobals.md` contain the relevant WinMM global/state names and support the current naming scheme.
- `by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md` confirms `StartSelectedMidiFile` is a different helper that resets/opens/restarts and applies volume.
- `by-memory/0x00526460-0x00526569.MidiPlayerResetStream.md` confirms reset helper semantics and matches the two target calls at `0x526376` and `0x526411`.
- `by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md` covers the open/prime helper called by `OpenSelectedMidiFileNoRestart`.
- `by-memory/0x00525f40-0x0052609a.MidiPlayerRawVolumeAndStreamLocalHelpers.md` provides the nearby volume-helper contrast.
- `by-memory/0x00526340-0x00526350.MidiPlayerStopPlayback.md` confirms the immediate preceding method is a separate modeled function ending before this raw range.
- `by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md` already inventories this raw cluster inside the broader MidiPlayer/WinMM helper aggregate.

Prior reports:

- `executed-b-agent-research/B011/0001CF-MidiPlayerAndWinMMHelpers-source-quality.md` created the current raw-helper split and recorded the original no-route evidence for the raw starts.
- `executed-b-agent-research/B006/0001CH-MidiPlayerTrackSelectionHelpers-source-quality.md` supports the distinction between track-selection/start behavior and this no-restart stream-control cluster.
- `executed-b-agent-research/B013/0000LD-MidiPlayer-empty-emitter-family-source-quality.md` confirms the current generated MidiPlayer family state and that UID00041N already emits C++.
- `executed-b-agent-research/B007/0000W2-ZlibPublicCompressChecksum-source-quality.md` contains historical UID collision evidence involving `00041N` and zlib deflate-tree helper documentation.

## Ownership and Split Disposition

Recommended owner/emitter remains [UID:0000LD][MidiPlayer].

Rationale:

- The bodies are private helper code in the `MidiPlayer.cpp`/WinMM helper cluster.
- The helpers do not use `this`/`ecx` object state and should not be promoted to `MidiPlayer` class methods.
- The state globals are owned/described by the WinMM-state documentation, but the helper bodies are executable file-scope behavior and should remain under the `MidiPlayer.cpp` emitter.
- There is no evidence for `SoundManager` ownership in this range.
- There is no evidence for zlib ownership of this range; the zlib relationship described below is a UID/documentation collision, not code ownership.

Recommended split: no further split.

Rationale:

- The target contains three small raw helper bodies separated by alignment/padding, all in the same stream-control family.
- All three share the same no-function/no-route evidence, owner/emitter, global state, imported WinMM operations, and reset/open helper dependencies.
- Splitting into three separate by-memory targets would add UID/registry churn and duplicate the same caveat-heavy evidence without improving source placement.
- The target should instead make the three subranges explicit in the covered-body table and evidence sections.

## C++ / No-Code Disposition

Recommendation: keep formal C++ populated and unchanged.

The current target is not a no-code owner, aggregate-only page, thunk-only page, or data-only page. It covers executable raw helper bodies, and the existing C++ is suitable for emission through [UID:0000LD].

No changes are recommended to the current formal helper names:

- `OpenSelectedMidiFileNoRestart(const wchar_t *path)`
- `ToggleMidiStreamPause()`
- `RestartSelectedMidiStream()`

No changes are recommended to the current state/global helper names for this target:

- `g_midiCurrentPath`
- `g_midiDocumentLoaded`
- `g_midiRestartPending`
- `g_midiStreamRunning`
- `g_midiStreamState`
- `g_hMidiStream`
- `MidiPlayerResetStream`
- `MidiStreamOpenAndPrimeBuffers`

These are reconstructed names, not original-symbol claims. The target implementation should keep that distinction clear.

## Active Duplicate-UID / Stale-Link Issue

This pass found an active global UID conflict that is outside the allowed report-only edit scope.

Evidence:

- Target assignment path `by-memory/0x00526350-0x00526452.MidiPlayerRawStreamControlHelpers.md` uses [UID:00041N].
- Local read of `by-memory/0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md` shows its header also starts with `*** UID:00041N | DO NOT MODIFY OR REMOVE!!! ***`.
- `by-meta/client_libraries.md` contains a zlib `trees.c` support reference using `[UID:00041N][0x00526350-0x00526452.MidiPlayerRawStreamControlHelpers]`, mixing zlib evidence with the MIDI target path.
- `by-memory/0x004142c0-0x00419e56.ZlibCore.md` contains the same mixed zlib/MIDI child reference.
- `by-memory/-ignored.md` also contains a zlib-span reference that points at `[UID:00041N][0x00526350-0x00526452.MidiPlayerRawStreamControlHelpers]`.

Impact:

- UID-only searches for `00041N` are ambiguous between the MIDI raw stream-control target and the zlib deflate-tree helper target.
- The implementation callback for this assignment should be path-scoped to `by-memory/0x00526350-0x00526452.MidiPlayerRawStreamControlHelpers.md` until the supervisor allocates a UID repair/support cleanup.
- If the supervisor accepts stale-link cleanup as part of a later callback, the zlib support docs should be updated to reference the actual zlib target path and whichever UID the supervisor assigns after resolving the duplicate. Do not guess a new UID during this report.

## Callback Reconciliation Verification

2026-07-01 callback reconciliation verified the accepted path-scoped MIDI target changes already present in `by-memory/0x00526350-0x00526452.MidiPlayerRawStreamControlHelpers.md`. No target edit was needed. Live MCP was available and rechecked through `initialize`, `tools/list`, `idb_list`, and narrow exact-address `tools/call` requests against database `supervisor_resume_20260629`; `server_health` returned `status:"ok"`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.

Live callback MCP proof used JSON-RPC ids 30-40: `lookup_funcs`, `entity_query`, `xrefs_to`, `xref_query`, `find_bytes`, `get_bytes`, `insn_query`, `decompile`, and `imports_query`. The checks reconfirmed no IDA functions at `0x00526350`, `0x005263a0`, or `0x005263e0`; no xrefs or VA/RVA pointer-byte hits to those raw starts; raw instruction coverage across `0x00526350-0x00526460`; all-`0xcc` padding at `0x00526332-0x00526340` and `0x00526452-0x00526460`; reset-helper calls at `0x00526376` and `0x00526411`; `decompile 0x00526350` failure because the raw start is not a function; `decompile 0x00526460` reset-helper behavior; and WINMM imports for `midiStreamRestart`, `midiStreamPause`, `midiStreamStop`, and `midiOutReset`.

## Claim and Incorporation Ledger

| Claim | Accepted action | Destination/proof | Verification state |
| --- | --- | --- | --- |
| C1: The target raw starts are not IDA functions. | Add current MCP no-function proof to target evidence. | Already present in target `## Function And Route Evidence`; live callback MCP ids 31-32 reconfirmed only neighboring `sub_526340` and `sub_526460` are modeled in `0x00526330-0x00526470`. | already-present |
| C2: The target has no direct external route to raw starts. | Keep no-route caveat; do not claim callable entrypoints or pointer table ownership. | Already present in target `## Function And Route Evidence`; live callback MCP ids 33-35 reconfirmed zero `xrefs_to`, zero `xref_query direction=to`, and zero VA/RVA pointer-byte hits for all three raw starts. | already-present |
| C3: Range boundaries are correct. | Preserve current target range and covered-body table, with clearer padding notes. | Already present in target `## Covered Bodies` and `## Boundary And Padding Evidence`; live callback MCP ids 31, 36, and 37 reconfirmed `sub_526340` size `0x10`, raw body bytes, return/alignment points, all-`0xcc` post-padding, and reset helper start at `0x00526460`. | already-present |
| C4: `OpenSelectedMidiFileNoRestart` C++ matches bytes. | Preserve formal C++; add byte-to-source proof. | Already present in target formal C++ and `## Disassembly-To-Source Proof`; live callback MCP id 37 reconfirmed `_wcscpy_s`, optional `sub_526460(0x10000)`, `sub_525920`, and conditional `g_midiDocumentLoaded` update. | already-present |
| C5: `ToggleMidiStreamPause` C++ matches bytes. | Preserve formal C++; explain `setz` source equivalence. | Already present in target formal C++ and `## Disassembly-To-Source Proof`; live callback MCP id 37 reconfirmed pending restart versus pause branches and the `setz`-based flag toggle. | already-present |
| C6: `RestartSelectedMidiStream` C++ matches bytes. | Preserve formal C++; highlight difference from `StartSelectedMidiFile`. | Already present in target formal C++ plus `## Disassembly-To-Source Proof` and `## Source Placement, Naming, And Split Rationale`; live callback MCP id 37 reconfirmed pending restart, optional reset, document-loaded check, state clear, restart, and running flag update. | already-present |
| C7: Reset helper dependency is real and bounded. | Keep dependency references to [UID:00041O]. | Already present in target `## WinMM And Helper Dependencies` and support page [UID:00041O][0x00526460-0x00526569.MidiPlayerResetStream](by-memory/0x00526460-0x00526569.MidiPlayerResetStream.md); live callback MCP ids 33 and 39 reconfirmed raw calls at `0x00526376`/`0x00526411` and reset-helper behavior. | already-present |
| C8: Open/prime dependency is real. | Keep dependency references to [UID:0001CE]. | Already present in target `## WinMM And Helper Dependencies` and support page [UID:0001CE][0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers](by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md); live callback MCP id 37 reconfirmed the `sub_525920` call at `0x0052637e`. | already-present |
| C9: Owner/emitter is `MidiPlayer.cpp`. | Keep owner/emitter `0000LD`. | Already present in target metadata, `## Status`, and `## Source Placement, Naming, And Split Rationale`; support pages [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md), [UID:0001CF][0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers](by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md), and [UID:00008A][MidiPlayer](by-class/MidiPlayer.md) keep the helper family under `NexusTK/audio/MidiPlayer.cpp`. | already-present |
| C10: No further split is warranted. | Preserve single page; document subranges. | Already present in target `## Covered Bodies` and `## Source Placement, Naming, And Split Rationale`; aggregate support page [UID:0001CF] also inventories the three helper subranges under the same child page. | already-present |
| C11: Score can increase modestly. | Raise to 87/88, not above 90. | Already present in target metadata (`COMPLETION:87`, `CONFIDENCE:88`) and `## Score Rationale`; scoped validator command id `000000004139` returned `ok: 1`. | already-present |
| C12: UID collision blocks UID-only confidence. | Escalate to supervisor; keep this callback path-scoped. | Already present in target `## Duplicate-UID Follow-Up`; zlib duplicate-UID/support cleanup remains excluded by the current goal and supervisor override, so no zlib docs, validator state, generated files, or coverage reports were edited. | already-present for target note; excluded-with-reason for support cleanup |

## Accepted-Implementation Checklist

Accepted path-scoped items:

- [x] Already present: `by-memory/0x00526350-0x00526452.MidiPlayerRawStreamControlHelpers.md` metadata is `COMPLETION:87` and `CONFIDENCE:88`; validator command id `000000004139`, timestamp `2026-07-01T18:23:34-04:00`, exit code `0`, `ok: 1`.
- [x] Already present: `CANONICAL_OWNER:0000LD`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LD`, and blank `EMITTER_POSITION_OPTIONAL` are present in the target header; owner/emitter route is also supported by [UID:0000LD], [UID:0001CF], and [UID:00008A].
- [x] Already present: the formal C++ block is populated and unchanged for `OpenSelectedMidiFileNoRestart`, `ToggleMidiStreamPause`, and `RestartSelectedMidiStream`; live callback MCP id 37 reconfirmed byte-to-source parity.
- [x] Already present: target evidence includes MCP session provenance, raw disassembly proof, no-function/no-route proof, padding/boundary proof, helper dependencies, and C++ equivalence notes; live callback MCP ids 30-40 reconfirmed those claims.
- [x] Already present: target `## Source Placement, Naming, And Split Rationale` records the no-further-split disposition and the reconstructed/source-shaped name caveat.
- [x] Already present: target `## Duplicate-UID Follow-Up` records the duplicate-UID/stale-link issue as a supervisor/tool-state follow-up while keeping this page scoped to the MIDI range.
- [x] Excluded with reason: zlib/MIDI mixed-reference support cleanup in `by-meta/client_libraries.md`, `by-memory/0x004142c0-0x00419e56.ZlibCore.md`, and `by-memory/-ignored.md` was not accepted in this callback and was explicitly excluded by the current goal/supervisor override.
- [x] Applied: ran scoped target validator from `E:\NTK\GhidraBridge\source-3\project-documentation`: `python .\tools\validator.py --mode file --file by-memory/0x00526350-0x00526452.MidiPlayerRawStreamControlHelpers.md --apply --queue-timeout 240`; command id `000000004139`, timestamp `2026-07-01T18:23:34-04:00`, exit code `0`, `ok: 1`.
- [x] Excluded with reason: support cleanup validators were not run because support cleanup remains outside this callback scope.
- [x] Applied: no generated files, coverage reports, queue files, archives, lock files, validator state, IDA DB, zlib support docs, or manual `-coverage-report.md` files were manually edited during this reconciliation.

## Validators

Report-only pass: no validators were run because no target/support docs were edited.

Callback reconciliation validator:

> Executable block R001 was removed from this report and preserved verbatim in [00041N-MidiPlayerRawStreamControlHelpers-by-memory-source-quality-removed.md](00041N-MidiPlayerRawStreamControlHelpers-by-memory-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result: command id `000000004139`, command timestamp `2026-07-01T18:23:34-04:00`, exit code `0`, `ok: 1`. Validator side effects reported by the command: `projected_stats_update: 1`, `stats_incremental_noop: 1`, `project-level/-auto-completion-stats.md updated projected path completion section`, `generated_refresh: deferred`, generated refresh command id `000000004139`, generated refresh timestamp `2026-07-01T18:23:34-04:00`.

Queue status check:

> Executable block R002 was removed from this report and preserved verbatim in [00041N-MidiPlayerRawStreamControlHelpers-by-memory-source-quality-removed.md](00041N-MidiPlayerRawStreamControlHelpers-by-memory-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result: command id `000000004147`, command timestamp `2026-07-01T18:26:54-04:00`, worker running `True`, queued jobs `0`, processing jobs `0`, queued generated refresh jobs `0`, processing generated refresh jobs `0`, generated refresh results `4313`. Generated output was not used as proof for this callback; source target and live MCP checks were the verification basis.

Support cleanup validators remain excluded unless a later callback explicitly accepts zlib UID/support repair:

> Executable block R003 was removed from this report and preserved verbatim in [00041N-MidiPlayerRawStreamControlHelpers-by-memory-source-quality-removed.md](00041N-MidiPlayerRawStreamControlHelpers-by-memory-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Unresolved Issues

1. Active duplicate UID: both the assigned MIDI target and `by-memory/0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md` currently use `UID:00041N`. This must be resolved by supervisor/registry policy before UID-only references can be considered reliable.
2. Mixed zlib/MIDI support links exist in `by-meta/client_libraries.md`, `by-memory/0x004142c0-0x00419e56.ZlibCore.md`, and `by-memory/-ignored.md`. These should not be repaired in the MIDI target implementation unless explicitly accepted by the supervisor.
3. The target raw starts still have no xrefs or pointer-table route. This justifies keeping the no-route caveat and limiting the score to 87/88.
4. Helper/global names are source-shaped reconstructions supported by adjacent docs and generated output, but they are not original-symbol recoveries.

## Report-Only And Callback Compliance

- Report-only pass wrote only this report file in `tools/leaser/Agents/Agent-B002/research/` and did not edit target/support/generated/coverage/tool-state files.
- Callback reconciliation edited only this report's ledger/checklist/validator proof because the accepted MIDI target details were already present at report-level detail.
- No target/support by-* files were manually edited during callback reconciliation, so no target lease was needed or taken.
- Live MCP was available and used read-only; no MCP, IDA, or Python process was started, stopped, restarted, or killed.
- Scoped target validator was run as required; generated/project-state effects, if any, were validator-owned and are recorded above.
- Zlib duplicate-UID/support cleanup remained excluded by the current callback.
- Did not spawn subagents.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00041N-MidiPlayerRawStreamControlHelpers-by-memory-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/00041N-MidiPlayerRawStreamControlHelpers-by-memory-source-quality.md","timestamp":"2026-07-01T18:28:01","uid":"00041N"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00041N-MidiPlayerRawStreamControlHelpers-by-memory-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00041N-MidiPlayerRawStreamControlHelpers-by-memory-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00041N"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
