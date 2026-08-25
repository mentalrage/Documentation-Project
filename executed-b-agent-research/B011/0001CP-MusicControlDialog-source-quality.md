** TARGET-REPORT-UID:0001CP **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001CP MusicControlDialog Source-Quality Report

**Assignment:** `B011-report-0001CP-music-control-dialog-20260625`  
**Target:** [UID:0001CP] `by-memory/0x00528e60-0x0052a535.MusicControlDialog.md`  
**Mode:** report-only research first  
**IDA MCP endpoint used:** `http://127.0.0.1:13337/mcp`  
**Report date:** 2026-06-25

## Final Recommendation

Keep [UID:0001CP] as the non-emitting MusicControlDialog memory aggregate under [UID:0000LN] `by-file/MusicControlDialog.md`. The current owner, source placement, reconstruction route, and no-aggregate-C++ policy are correct:

- `CANONICAL_OWNER` stays `0000LN`.
- `RECONSTRUCTABLE` stays `TRUE`.
- `EMITTER_UIDS` stays `0000LN`.
- `RECONSTRUCTION_CPP` stays blank for the aggregate because exact child pages carry method C++ or explicit no-code proofs.
- No new split is required for `0x00528e60-0x0052a535`.

After implementation of this report, I recommend keeping [UID:0001CP] at `89/91`. The current MCP session verifies the full child/function inventory, raw helper bodies, no-entry-route negatives, vtable/callback routes, direct config/audio/control dependencies, and stale generated-row issue. This correction pass resolves the two targeted helper routes: [UID:0003MG] now documents the `BDir` string chain as raw ANSI `StringBase<char>` construction, ANSI-to-wide `StringBase<wchar_t>` conversion through `StringBaseWideFromAnsiString` / `MultiByteToWideDefaultCp`, and paired ANSI/wide release wrappers; [UID:0003MK] now documents `0x00509480` as a shared mode-zero tail block that calls [UID:0001I7] `SoundManager::PlayMusicByZone` through the audio owner route. The remaining cap below final-quality territory is evidence-backed rather than investigative: four retained raw helper starts have no caller/table/vtable/member-pointer/absolute-pointer/RVA route and therefore keep blank C++, [UID:0003MJ]/[UID:0003MQ] are formal source-shaped functions with documented no-direct-entry xrefs, and generated tracker rows remain a validator/lifecycle concern.

## Active MCP Session

MCP was available and used as required. I did not start, stop, or restart MCP, and I did not mutate the IDB.

- `idb_list` reported existing session `80de0a67` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- `server_health` for `80de0a67` returned `status: ok`, `auto_analysis_ready: true`, `hexrays_ready: true`, `strings_cache_ready: true`, module `NexusTK.exe`, imagebase `0x400000`, and input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- Read-only MCP calls used for this report included `entity_query`, `lookup_funcs`, `xrefs_to`, `xref_query`, `find_bytes`, `get_bytes`, `insn_query`, `decompile`, and `analyze_component`.

No leases were taken during the research evidence pass. During implementation/correction, B011 took leases only immediately before editing by-* files and released them after the edit/validator batch.

## Source Documents Checked

Primary target and support pages:

- `by-memory/0x00528e60-0x0052a535.MusicControlDialog.md`
- `by-file/MusicControlDialog.md`
- `by-class/MusicControlDialog.md`
- MusicControlDialog exact children [UID:0003MB] through [UID:0003MR], plus callback/template-adjacent [UID:0002N2], [UID:0002N3], and [UID:0001CQ].
- `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
- `by-memory/0x0067a7d0-0x0067a7d4.g_pSoundManager.md`
- `by-memory/0x0066debc-0x0066decc.MusicControlDriveRootBuffers.md`
- `by-memory/0x0061fc04-0x0061fd04.MusicControlDialogReadOnlyData.md`
- `by-class/SoundManager.md`
- `by-file/SoundManager.md`

Prior B-agent reports checked:

- `executed-b-agent-research/B003/0003MB-0003MD-MusicControlDialog-source-quality.md`
- `executed-b-agent-research/B003/0003ME-0003MR-MusicControlDialogHelperFamily-source-quality.md`
- `executed-b-agent-research/B002/0003ME-MusicControlDialogUnmodeledSoundEffectApply.md`

Generated/tracker state checked for consistency only:

- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `project-level/-auto-completion-stats.md`

Those generated/project-level files were not edited.

## Current Target State

The target page currently records:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000LN`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000LN`
- Blank aggregate C++ block

This is directionally correct. The target's Item Summary was stale in one important phrase: it still said "most dialog methods still need exact child pages." That is no longer accurate. The exact children now exist, the [UID:0003MG] and [UID:0003MK] helper-name issues are resolved in this correction pass, and the current score cap is the documented absence of source-entry routes for retained raw helper bodies plus generated-row refresh.

## Generated State Mismatch

Generated rows are stale relative to the source page:

- `auto-generated/-ag-research-tracker.md` still lists [UID:0001CP] around `76/82`, despite the source page being `88/90`.
- `auto-generated/-ag-coverage-report-by-memory.md` still shows the target around `76% : strong`, while carrying a newer Item Summary.
- `project-level/-auto-completion-stats.md` appears stale for at least the MusicControlDialog class/file rows.
- The research tracker reports relevant executed B002/B003 reports as present in central executed research but not registered.

This is a validator/generated-state issue, not a reason to hand-edit generated files. Implementation should update source docs first and then run scoped validators/generator refreshes. If central executed-report registry mismatch persists, supervisor should use the project report lifecycle tools/rescan path; B011 should not edit validator state or generated files.

## IDA Function Inventory

`entity_query` over `0x00528e00-0x0052a560` found the expected formal functions:

| Start | IDA name | Size | Source-quality disposition |
| --- | --- | ---: | --- |
| `0x00528e60` | `sub_528E60` | `0x90c` | [UID:0003MB] constructor, MusicControlDialog-owned |
| `0x00529770` | `sub_529770` | `0x1f` | [UID:0003MC] non-deleting destructor, compiler/source-declared support |
| `0x00529790` | `sub_529790` | `0x39e` | [UID:0003MD] command handler, MusicControlDialog-owned |
| `0x00529be0` | `sub_529BE0` | `0x7a` | [UID:0003MF] vtable-backed sound-effect packet handler |
| `0x00529c60` | `sub_529C60` | `0x98` | [UID:0003MG] vtable-backed browse-directory packet handler |
| `0x00529d00` | `sub_529D00` | `0x1d1` | [UID:0003MH] refresh/control-state method |
| `0x00529ee0` | `sub_529EE0` | `0x12c` | [UID:0003MI] folder-selection callback |
| `0x0052a010` | `sub_52A010` | `0x110` | [UID:0003MJ] modeled CD-drive popup helper, no direct entry xrefs |
| `0x0052a120` | `sub_52A120` | `0x5f` | [UID:0003MK] apply playback state |
| `0x0052a180` | `sub_52A180` | `0x69` | [UID:0003ML] toggle pause state |
| `0x0052a2d0` | `sub_52A2D0` | `0x34` | [UID:0003MP] file-local apply sound-effect flag |
| `0x0052a310` | `sub_52A310` | `0xd0` | [UID:0003MQ] modeled output-selection helper, no direct entry xrefs |
| `0x0052a3e0` | `sub_52A3E0` | `0x5e` | [UID:0002N2] function-object callback invoke, FunctionObjects-owned/emitted |
| `0x0052a43e` | `sub_52A43E` | `0xb` | ignored adjustor thunk |
| `0x0052a449` | `sub_52A449` | `0xb` | ignored adjustor thunk |
| `0x0052a460` | `sub_52A460` | `0x3e` | [UID:0001CQ] function-object string destructor |
| `0x0052a4a0` | `sub_52A4A0` | `0x3e` | [UID:0002N3] function-object callback destructor |
| `0x0052a4e0` | `sub_52A4E0` | `0x55` | [UID:0003MR] scalar deleting destructor |
| `0x0052a540` | `sub_52A540` | `0xb07` | next outside target range |

`lookup_funcs` confirmed that `0x00529b70`, `0x0052a1f0`, `0x0052a230`, and `0x0052a280` are not formal IDA functions. They are retained raw helper bodies inside the aggregate, which matches the current exact child model.

## Entry-Route and Xref Evidence

The current xref evidence supports the existing split and blank-C++ holds for raw starts:

| Address | Current route evidence |
| --- | --- |
| `0x00529b30` | Switch data xref from `0x005297d7` inside [UID:0003MD]. This is a command case label, not a function entry. |
| `0x00529b70` | No code/data xrefs. No VA/RVA pointer bytes found. |
| `0x00529be0` | Vtable data xref at `0x0061fc74`. |
| `0x00529c60` | Vtable data xref at `0x0061fc7c`. |
| `0x00529d00` | Constructor code xref at `0x00529731` plus vtable data xref at `0x0061fc50`. |
| `0x00529ee0` | Member-function/callback construction reference at `0x00529848`. |
| `0x0052a010` | No direct xrefs and no VA/RVA pointer bytes found. Modeled by IDA as a formal function with stable source-shaped body. |
| `0x0052a120` | Code xrefs from command handler `0x00529b0b` and folder callback `0x00529feb`. |
| `0x0052a180` | Code xrefs from command handler `0x005299fd`/`0x00529a46`, [UID:0003MK] at `0x0052a129`, [UID:0003MN] at `0x0052a26a`, and [UID:0003MO] at `0x0052a2c4`. |
| `0x0052a1f0` | No code/data xrefs. No VA/RVA pointer bytes found. |
| `0x0052a230` | No code/data xrefs. No VA/RVA pointer bytes found. |
| `0x0052a280` | No code/data xrefs. No VA/RVA pointer bytes found. |
| `0x0052a2d0` | Code xref from command handler `0x005299af`. |
| `0x0052a310` | No direct xrefs and no VA/RVA pointer bytes found. Modeled by IDA as a formal function with stable source-shaped body. |
| `0x0052a3e0` | Function-object vtable data xref at `0x0061fcf8`. |
| `0x0052a4a0` | Function-object vtable data xref at `0x0061fcec`. |
| `0x0052a4e0` | Adjustor thunk code refs from `0x0052a444` and `0x0052a44f`, plus vtable data xref at `0x0061fc04`. |

`find_bytes` found no little-endian absolute VA or RVA pointer route for the raw/no-direct starts checked:

- `0x00529b70`
- `0x0052a010`
- `0x0052a1f0`
- `0x0052a230`
- `0x0052a280`
- `0x0052a310`

This confirms the raw helpers should be documented with no-code proofs under current source-entry evidence.

## Boundary Evidence

`get_bytes` confirmed the important padding boundaries:

- `0x00529b68` has eight `0xcc` bytes before raw [UID:0003ME] begins at `0x00529b70`.
- `0x0052a1e9` has seven `0xcc` bytes before raw [UID:0003MM] begins at `0x0052a1f0`.
- [UID:0003MM] ends with `retn 4`, then padding continues until raw [UID:0003MN] at `0x0052a230`.
- [UID:0003MN] ends before padding and raw [UID:0003MO] begins at `0x0052a280`.
- `0x0052a304` has padding before formal [UID:0003MQ] at `0x0052a310`.
- `0x0052a535` has padding before the next outside function at `0x0052a540`.

These bytes support the existing aggregate boundary and exact child ranges.

## Raw Helper Recheck

[UID:0003ME] `0x00529b70-0x00529bda` is a retained raw sound-effect payload helper. Current MCP `lookup_funcs(0x00529b70)` reports `Not a function`, `xref_query(to 0x00529b70)` returns zero refs, and the existing child route scan records no caller/table/vtable/member-pointer/VA/RVA route. Current disassembly shows it parses the payload byte at `arg+5`, fetches control id `1` through the dialog control manager, updates UI state, writes `g_pConfig+0x28de48`, and calls either `0x0057a760` or `0x0057a770` through [UID:00028R] `g_pSoundManager`. Rejected alternatives are a live command-handler target, vtable packet handler, SoundManager-owned helper, and compiler artifact; the positive body semantics keep it MusicControlDialog-routed, while the zero-entry evidence keeps formal C++ blank at `86/88`.

[UID:0003MM] `0x0052a1f0-0x0052a227` is a retained raw folder-path control refresh helper. Current MCP `lookup_funcs(0x0052a1f0)` reports `Not a function`, `xref_query(to 0x0052a1f0)` returns zero refs, and the child proof records no caller/table/vtable/member-pointer/VA/RVA route. Current disassembly shows it fetches control id `6`, updates display text through `sub_498CA0`, then resets the embedded text edit selection through `sub_58F2A0(0, 0)`. It has no config copy and no SoundManager scan, so the rejected alternatives are `FolderPathSelected`, the local music scanner, and generated padding. Keep score `86/88` and blank C++ because the body role is known but no source-entry route exists.

[UID:0003MN] `0x0052a230-0x0052a271` is a retained raw next-track helper. Current MCP `lookup_funcs(0x0052a230)` reports `Not a function`, `xref_query(to 0x0052a230)` returns zero refs, and the child proof records no caller/table/vtable/member-pointer/VA/RVA route. Current disassembly sets SoundManager byte `+0x40`, branches on `g_pConfig+0x291908`, calls stream next `0x0057a510` or Redbook advance `0x0057b240`, and tail-jumps to [UID:0003ML] if `this+0x26c` indicates paused state. Command case 13 in [UID:0003MD] contains the live inline duplicate, so the retained raw body is not emitted separately. Keep score `86/88` and blank C++.

[UID:0003MO] `0x0052a280-0x0052a2cb` is a retained raw previous-track helper. Current MCP `lookup_funcs(0x0052a280)` reports `Not a function`, `xref_query(to 0x0052a280)` returns zero refs, and the child proof records no caller/table/vtable/member-pointer/VA/RVA route. Current disassembly branches on `g_pConfig+0x291908`, calls Redbook rewind `0x0057b2c0` or stream `PlayTrackByIndex(index - 1, 100, 1)` through `0x00579e30`, and tail-jumps to [UID:0003ML] if paused. Command case 11 in [UID:0003MD] contains the live inline duplicate, so the retained raw body is not emitted separately. Keep score `86/88` and blank C++.

## Modeled Helper Recheck

[UID:0003MJ] `0x0052a010-0x0052a120` remains a modeled function with no direct entry xrefs. Current MCP `lookup_funcs(0x0052a010)` returns `sub_52A010` size `0x110`, while `xref_query(to 0x0052a010)` returns zero refs. Hex-Rays gives a stable, source-shaped CD-drive popup population helper: it loops `A` through `Z`, uses `GetDriveTypeA`, uses drive-root buffers `0x0066debc` and `0x0066dec0`, compares against `g_pConfig+0x291910`, updates control id `8`, and appends the blank option. The rejected alternatives are FolderSelectDialog ownership, raw/no-entry blanking, and folding the body into the constructor. The constructor has equivalent enumeration, but this target is a formal IDA function with stable private-helper shape, so first-draft C++ remains appropriate at `87/91`.

[UID:0003MQ] `0x0052a310-0x0052a3e0` remains a modeled function with no direct entry xrefs. Current MCP `lookup_funcs(0x0052a310)` returns `sub_52A310` size `0xd0`, while `xref_query(to 0x0052a310)` returns zero refs. Hex-Rays gives a stable output-selection helper: selection `0` mutes music through `0x0057a3e0`; changed nonzero selections write `g_pConfig+0x291914`, allocate and show localized alert id `244` through `off_613A18`, check playback with `0x0057a3d0`, and unmute with `0x0057a400` when needed. The rejected alternatives are raw/no-entry blanking, SoundManager ownership, and leaving the behavior only in command case `3`; that command path contains an inline duplicate, but this formal function remains source-shaped enough for first-draft C++ at `87/89`.

[UID:0003MG] `0x00529c60-0x00529cf8` remains correctly owned by MusicControlDialog as a vtable-backed browse-directory packet handler. Current MCP decompilation confirms the `BDir` packet tag, payload pointer `[notification+0x0c] + 4`, and clear of `g_pApplication+0x84f`; it does not call [UID:0003MI] directly. The helper chain is now resolved by live MCP and existing StringBase support docs: `0x00582730` / `sub_582730` constructs/copies an ANSI `StringBase<char>` from raw NUL-terminated text, `0x00582830` / `sub_582830` converts that stored ANSI/default-codepage string to a wide `StringBase<wchar_t>` through `MultiByteToWideDefaultCp`, `0x00582b70` releases the wide temporary through `ReleaseWideBuffer`, and `0x00582b30` releases the ANSI temporary through `ReleaseAnsiBuffer`. The final C++ should expose two local StringBase temporaries. Keep score `87/90` because final facade typedef spelling is broader StringBase work, not because this helper role lacks evidence.

[UID:0003MK] `0x0052a120-0x0052a17f` remains correctly owned by MusicControlDialog as apply-playback-state logic. MCP decompilation reconfirms the paused-state guard, mode branches, Redbook/open-close path, and local music mode path. The resolved fallback route is: `0x0052a16a-0x0052a17a` stops stream/music through `SoundManager::StopMusicPlayback(0)`, loads `ecx = g_activeMapPane` from `0x0067a764`, and jumps to shared tail block `0x00509480`. That block rechecks `g_pConfig+0x291908 == 0`, pushes `0`, `g_activeMapPane+0x4d8`, `+0x4d4`, and `+0x4d0`, loads `ecx = g_pSoundManager`, and calls `0x0057a0b0`. Existing SoundManager docs identify `0x0057a0b0` as `SoundManager::PlayMusicByZone(int zoneId, int fallbackTrackIndex, int fadeOutMillis, int loopCount)`. `xref_query(to 0x00509480)` finds only the MusicControlDialog jump at `0x0052a17a` and the raw SoundManager audio reinit bridge at `0x0057b00c`; `xref_query(to 0x0057a0b0)` finds only this shared tail call at `0x005094a8` and the MapPane packet caller at `0x0051301c`. Keep score `88/92`; the role is resolved, while final MapPane field spelling for `+0x4d0/+0x4d4/+0x4d8` remains documented as role-based.

## Component Graph and Globals

`analyze_component` over formal functions in the target confirms the local call graph:

- Constructor [UID:0003MB] calls [UID:0003MH].
- Command handler [UID:0003MD] calls [UID:0003ML], [UID:0003MP], and [UID:0003MK].
- Folder callback [UID:0003MI] calls [UID:0003MK].
- Apply playback state [UID:0003MK] calls [UID:0003ML].

Shared globals and data refs match current docs:

- [UID:00028Q] `g_pConfig` at `0x0067a7c8` is the config root for music source/playback mode, local music path, drive letter, random/repeat flags, output selection, and sound-effect flag.
- [UID:00028R] `g_pSoundManager` at `0x0067a7d0` is the audio singleton consumed by the dialog.
- `0x0066debc` and `0x0066dec0` are the drive-root buffers used by constructor and [UID:0003MJ].
- `0x0061fc04` and nearby vtable data anchor constructor/destructor and packet-handler routes.
- `off_613A18` is the localized alert table used by command-handler/output-selection alert construction.

These are dependencies, not owner transfers.

## Ownership Analysis

### Best Owner: MusicControlDialog.cpp / [UID:0000LN]

This remains the only source-quality owner for the aggregate. The constructor, command handler, dialog control state updates, folder callback, drive popup, pause/next/previous/output logic, vtable packet handlers, and destructor paths are one cohesive UI dialog island. The data dependencies are consumed from other modules, but the policy decisions and UI wiring live in the dialog.

### Rejected: SoundManager

SoundManager owns audio state and playback helpers, not the UI dialog. MusicControlDialog only reads and calls [UID:00028R] `g_pSoundManager`. The dialog controls config bytes, updates controls, and issues audio commands as a consumer.

### Rejected: FolderSelectDialog / FunctionObjects for Whole Aggregate

The folder-selection callback uses FunctionObject glue and interacts with FolderSelectDialog. That only affects [UID:0002N2], [UID:0002N3], and [UID:0001CQ] support/glue ownership. It does not move the dialog body, command handler, or helper methods out of MusicControlDialog.

### Rejected: ChattingColorPane

Old generated/simroot pollution associated some callback artifacts with ChattingColorPane. Current by-* docs and the current MCP evidence do not support that owner. The member-function pointer at `0x00529848`, dialog control ids, MusicControlDialog vtable data, config offsets, and folder-path callback all point to MusicControlDialog.

### Rejected: no-owner / unsupported owner

The raw helper starts lack entry routes, but their bodies are still semantically and spatially part of the MusicControlDialog aggregate. Their lack of a source-entry route blocks formal C++, not ownership.

## Source Placement and Split Decision

Keep source placement:

- `NexusTK/ui/dialogs/MusicControlDialog.cpp`

No new split is needed. The aggregate should continue to serve as a source-layout index over exact child pages. The exact child layout is now sufficient:

- MusicControlDialog source-owned children: constructor, destructors, command handler, packet handlers, refresh/callback helpers, drive popup, playback/pause helpers, raw retained helper bodies, sound-effect/output helpers.
- FunctionObject-owned children: callback invoke/destructor/string destructor support pages.
- Ignored children: small adjustor thunks at `0x0052a43e` and `0x0052a449`.

## First-Draft C++ Decision

Do not add aggregate C++ to [UID:0001CP]. The aggregate passes the reconstructable average threshold, but it is a container/source-layout anchor, not the correct emitter for a monolithic source block. Adding aggregate C++ would duplicate child pages and mix code with raw no-entry bodies and compiler/function-object glue.

Child C++ policy:

- Keep first-draft C++ where it already exists for formal, source-shaped MusicControlDialog children.
- Keep [UID:0003ME], [UID:0003MM], [UID:0003MN], and [UID:0003MO] blank because no source-entry route currently exists.
- Keep compiler/generated destructor and FunctionObject glue blank under the current compiler-artifact policy.
- Keep [UID:0003MJ] and [UID:0003MQ] C++ with no-direct-entry-xref evidence because they are formal IDA functions with stable, source-shaped decompilations.

## Recommended Target Changes

Update [UID:0001CP] as follows:

- `COMPLETION:89`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:0000LN`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000LN`
- Leave `RECONSTRUCTION_CPP` blank.

Replace the Item Summary with:

```text
B011 2026-06-25 MCP recheck confirms MusicControlDialog.cpp aggregate boundaries, formal child inventory, raw helper bodies, no-entry route negatives, vtable/callback routes, config/SoundManager/control dependencies, and stale generated-row refresh need; aggregate C++ remains blank because exact children carry C++ or no-code proofs.
```

Add a short B011 evidence note to the target page:

```text
2026-06-25 B011 source-quality recheck used active IDA MCP session 80de0a67 and confirmed the exact MusicControlDialog aggregate inventory. Formal IDA functions in the range are 0x00528e60, 0x00529770, 0x00529790, 0x00529be0, 0x00529c60, 0x00529d00, 0x00529ee0, 0x0052a010, 0x0052a120, 0x0052a180, 0x0052a2d0, 0x0052a310, 0x0052a3e0, 0x0052a43e, 0x0052a449, 0x0052a460, 0x0052a4a0, and 0x0052a4e0. Raw starts 0x00529b70, 0x0052a1f0, 0x0052a230, and 0x0052a280 are still not formal functions and have no caller/table/vtable/member-pointer/absolute-pointer/RVA entry route, so their child pages retain blank C++. No aggregate C++ is emitted because this page is a layout index over exact children.
```

Remove or replace any target wording that says most dialog methods still need exact child pages. The more accurate remaining score caps are the documented no-entry route for raw helper bodies, the documented no-direct-entry route for formal retained helpers [UID:0003MJ]/[UID:0003MQ], role-based rather than final MapPane field spelling for [UID:0003MK] `+0x4d0/+0x4d4/+0x4d8`, and generated-row refresh.

## Recommended Support Changes

### by-file/MusicControlDialog.md

Recommended metadata after incorporating the current evidence:

- Raise from `87/87` to `88/88`.
- Keep owner/file path unchanged.
- Keep file-level C++ policy unchanged unless the implementation pass is explicitly producing file-level source.

Add a B011 status note:

```text
2026-06-25 B011 MCP recheck confirms MusicControlDialog.cpp as the canonical file owner for [UID:0001CP]. The active IDA session verified the full formal-function inventory, raw helper body boundaries, vtable/callback routes, no-entry-route negatives for retained raw helpers, [UID:00028Q] g_pConfig dependencies, [UID:00028R] g_pSoundManager dependencies, drive-root buffers, localized output-selection alert construction, the BDir StringBase ANSI-to-wide helper chain, and the `0x00509480` shared tail into `SoundManager::PlayMusicByZone`. Remaining source-quality caps are the raw/no-entry C++ disposition, [UID:0003MJ]/[UID:0003MQ] no-direct modeled-helper route evidence, role-based MapPane music-field spelling, and generated-row refresh; no owner split is recommended.
```

### by-class/MusicControlDialog.md

Recommended metadata after incorporating the current evidence:

- Raise from `87/87` to `88/88`.
- Keep class owner/file relationships unchanged.
- Keep class-level C++ policy unchanged unless a separate class declaration pass is approved.

Add a B011 status note:

```text
2026-06-25 B011 MCP recheck confirms the class method inventory and field/global model: `this+0x26c` is the pause-active flag, `g_pConfig+0x291908` selects music source/playback mode, `+0x29190c` stores local music path, `+0x291910` stores the CD drive letter, `+0x291912` and `+0x291913` hold shuffle/repeat flags, `+0x291914` stores output selection, and `+0x28de48` stores sound-effect enablement. The class consumes [UID:00028R] g_pSoundManager and does not own SoundManager storage or playback internals.
```

### Child Item Summary Repairs

Several child pages have blank or stale Item Summary metadata. This matters because generated coverage rows consume those summaries. Populate them during implementation. Recommended exact summaries:

| UID | Recommended Item Summary |
| --- | --- |
| `0003MB` | `MusicControlDialog constructor at 0x00528e60-0x0052976c builds dialog controls, initializes config-derived music/effect state, installs callback/function-object support, seeds drive-root buffers, calls RefreshControlStates, and belongs to MusicControlDialog.cpp.` |
| `0003MC` | `MusicControlDialog non-deleting destructor at 0x00529770-0x0052978f reseats/tears down dialog vtable state as source-declared compiler-supported destruction; formal C++ remains blank because source destructor coverage is represented by the owning dialog page and deleting-destructor support.` |
| `0003MD` | `MusicControlDialog command handler at 0x00529790-0x00529b70 dispatches music/effect controls, folder selection, playback/pause/next/previous/output commands, alert construction, callback setup, and inline duplicate paths for retained raw next/previous helpers.` |
| `0003ME` | `Raw/no-function sound-effect payload helper at 0x00529b70-0x00529bda parses the payload byte, updates control id 1, writes g_pConfig+0x28de48, and toggles SoundManager effect state; no caller/table/vtable/member-pointer/VA/RVA route exists, so formal C++ remains blank.` |
| `0003MF` | `Vtable-backed MusicControlDialog sound-effect packet handler at 0x00529be0-0x00529c5a handles the '#' payload route and synchronizes dialog/config/SoundManager sound-effect enablement through the class-owned handler path.` |
| `0003MG` | `Vtable-backed MusicControlDialog BDir browse-directory notification handler at 0x00529c60-0x00529cf8 consumes payload+4 through an ANSI StringBase construction, ANSI-to-wide StringBase conversion, and paired wide/ANSI release wrappers, clears g_pApplication+0x84f, and does not call FolderPathSelected.` |
| `0003MH` | `MusicControlDialog RefreshControlStates at 0x00529d00-0x00529ed1 enables, disables, and synchronizes dialog controls from config and SoundManager state; constructor and vtable routes confirm class ownership.` |
| `0003MI` | `MusicControlDialog folder-selection callback at 0x00529ee0-0x0052a00c receives the selected folder path, updates config/UI playback state, rejects stale ChattingColorPane ownership, and routes through the command-handler-created member-function callback.` |
| `0003MJ` | `Modeled no-direct-xref CD drive popup helper at 0x0052a010-0x0052a120 enumerates A-Z drive roots through GetDriveTypeA, uses drive-root buffers 0x0066debc/0x0066dec0, selects g_pConfig+0x291910, and keeps first-draft C++ under current no-direct-entry evidence.` |
| `0003MK` | `MusicControlDialog ApplyPlaybackState at 0x0052a120-0x0052a17f starts/stops local, Redbook, or active-map zone playback from config state, calls TogglePauseState as needed, and uses the shared 0x00509480 mode-zero tail to call SoundManager::PlayMusicByZone with g_activeMapPane+0x4d0/+0x4d4/+0x4d8.` |
| `0003ML` | `MusicControlDialog TogglePauseState at 0x0052a180-0x0052a1e9 toggles stream or Redbook pause state, updates this+0x26c, and switches control id 12 icons 37/48 from the dialog's pause state.` |
| `0003MM` | `Raw/no-function folder-path control refresh body at 0x0052a1f0-0x0052a227 fetches control id 6, updates displayed path text through sub_498CA0, resets the embedded text-edit selection through sub_58F2A0(0,0), and has no caller/table/vtable/member-pointer/VA/RVA route, so formal C++ remains blank.` |
| `0003MN` | `Raw/no-function retained next-track helper at 0x0052a230-0x0052a271 sets SoundManager +0x40, advances stream or Redbook playback by music mode, tail-jumps to TogglePauseState when paused, and remains blank-C++ because command case 13 contains the live inline duplicate and no source-entry route reaches this start.` |
| `0003MO` | `Raw/no-function retained previous-track helper at 0x0052a280-0x0052a2cb rewinds Redbook or calls stream PlayTrackByIndex(index-1,100,1), tail-jumps to TogglePauseState when paused, and remains blank-C++ because command case 11 contains the live inline duplicate and no source-entry route reaches this start.` |
| `0003MP` | `File-local ApplySoundEffectEnabled helper at 0x0052a2d0-0x0052a304 writes the sound-effect config flag and calls SoundManager enable/disable helpers from the command-handler route; it emits through MusicControlDialog.cpp, not SoundManager.` |
| `0003MQ` | `Modeled no-direct-xref ApplyOutputSelection helper at 0x0052a310-0x0052a3e0 mutes output selection 0, writes g_pConfig+0x291914 on changed nonzero selections, shows localized alert id 244, and unmutes playback when needed; first-draft C++ stays under current no-direct-entry evidence.` |
| `0003MR` | `MusicControlDialog scalar deleting destructor at 0x0052a4e0-0x0052a535 covers vtable reseat, destruction support, and optional delete; adjustor thunks jump here and formal C++ remains blank as compiler-generated destructor support.` |

Keep child scores unchanged unless implementation adds more than summary/status text:

- Raw helpers [UID:0003ME], [UID:0003MM], [UID:0003MN], [UID:0003MO] remain `86/88`.
- Modeled no-direct-xref helpers [UID:0003MJ] and [UID:0003MQ] remain `87/91` and `87/89`.
- High-confidence method children remain at their current `87-88` completion and `90-92` confidence values.

### Drive Root Buffers and Read-Only Data

No required score change. If touched for cross-reference freshness, add only a short B011 evidence note:

- Drive-root buffer refs reconfirmed from constructor and [UID:0003MJ] at `0x0066debc` and `0x0066dec0`.
- MusicControlDialog vtable/read-only data refs reconfirmed for constructor/destructor and packet handlers.

### SoundManager and Config Support Pages

No required score change. Use canonical names in MusicControlDialog docs:

- [UID:00028Q] `g_pConfig`
- [UID:00028R] `g_pSoundManager`

Avoid reintroducing historical raw labels (`dword_67A7C8`, `dword_67A7D0`) as primary source-facing names except when documenting IDA evidence.

## Score Rationale

Recommended aggregate score: `89/91`.

Why this can move up:

- MCP was available and current.
- Function inventory is complete and matches the exact child model.
- Raw helper starts were checked with function lookup, xrefs, byte-boundary inspection, instruction reads, and VA/RVA pointer scans.
- Modeled helper no-direct-entry limits were rechecked and remain well bounded.
- Ownership alternatives were re-evaluated against current evidence.
- Generated tracker staleness was identified as a process issue, not source evidence against the page.

Why this should not move higher yet:

- Four retained raw helper bodies have current zero-route proof: `lookup_funcs` reports no function at `0x00529b70`, `0x0052a1f0`, `0x0052a230`, or `0x0052a280`, `xref_query` returns zero incoming refs for all four starts, and existing child route scans found no caller/table/vtable/member-pointer/VA/RVA route. Their roles are documented, but formal C++ stays blank.
- [UID:0003MJ] and [UID:0003MQ] are formal IDA functions with stable source-shaped bodies but no direct entry xrefs. Their first-draft C++ is retained because the functions are modeled and behavior is recoverable; confidence remains below directly reached helpers because the direct route is absent.
- [UID:0003MK] uses role-based active MapPane music fields at `+0x4d0/+0x4d4/+0x4d8`; the SoundManager callee and call route are resolved, and exact original MapPane member spelling is outside the current recovered evidence.
- Generated rows and executed-report registry state remain stale until validator/report lifecycle refresh.

## Implementation Notes

Do not edit generated files, validator state/cache, coverage reports, or IDA DB. Implementation should only touch source documentation pages and then run validators.

Suggested scoped validators after implementation:

> Executable block R001 was removed from this report and preserved verbatim in [0001CP-MusicControlDialog-source-quality-removed.md](0001CP-MusicControlDialog-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If child Item Summary repairs are implemented in the same pass, run the same scoped validator mode for each edited child page. If generated tracker rows still show stale `76/82`-style values after source validation, escalate to supervisor for the project report lifecycle/rescan path rather than editing generated state by hand.

## Validator Results

B011 ran scoped validators from `source-3/project-documentation` after the accepted by-* edits.

Primary target/support validators:

| File | Command | Result |
| --- | --- | --- |
| `by-memory/0x00528e60-0x0052a535.MusicControlDialog.md` | `python .\tools\validator.py --mode file --file by-memory\0x00528e60-0x0052a535.MusicControlDialog.md --apply --queue-timeout 240` | `command_id:000000001104`, `command_timestamp:2026-06-25T03:52:31-04:00`, exit `0`, `ok:1`, `generated_refresh:deferred`. |
| `by-file/MusicControlDialog.md` | `python .\tools\validator.py --mode file --file by-file\MusicControlDialog.md --apply --queue-timeout 240` | `command_id:000000001106`, `command_timestamp:2026-06-25T03:52:32-04:00`, exit `0`, `ok:1`, `generated_refresh:deferred`. |
| `by-class/MusicControlDialog.md` | `python .\tools\validator.py --mode file --file by-class\MusicControlDialog.md --apply --queue-timeout 240` | `command_id:000000001107`, `command_timestamp:2026-06-25T03:52:34-04:00`, exit `0`, `ok:1`, `generated_refresh:deferred`. |

Child validators:

| UID | File | Final validator command result |
| --- | --- | --- |
| `0003MB` | `by-memory/0x00528e60-0x0052976c.MusicControlDialogConstructor.md` | `command_id:000000001154`, `command_timestamp:2026-06-25T03:57:10-04:00`, exit `0`, `ok:1`, `generated_refresh:skipped` via `--no-generated-refresh`. |
| `0003MC` | `by-memory/0x00529770-0x0052978f.MusicControlDialogNonDeletingDestructor.md` | `command_id:000000001156`, `command_timestamp:2026-06-25T03:57:17-04:00`, exit `0`, `ok:1`, `generated_refresh:skipped` via `--no-generated-refresh`. |
| `0003MD` | `by-memory/0x00529790-0x00529b70.MusicControlDialogHandleControlCommand.md` | `command_id:000000001157`, `command_timestamp:2026-06-25T03:57:19-04:00`, exit `0`, `ok:1`, `generated_refresh:skipped` via `--no-generated-refresh`. |
| `0003ME` | `by-memory/0x00529b70-0x00529bda.MusicControlDialogUnmodeledSoundEffectApply.md` | `command_id:000000001158`, `command_timestamp:2026-06-25T03:57:20-04:00`, exit `0`, `ok:1`, `generated_refresh:skipped` via `--no-generated-refresh`. |
| `0003MF` | `by-memory/0x00529be0-0x00529c5a.MusicControlDialogSoundEffectPacketHandler.md` | `command_id:000000001139`, `command_timestamp:2026-06-25T03:56:33-04:00`, exit `0`, `ok:1`, `generated_refresh:skipped` via `--no-generated-refresh`. |
| `0003MG` | `by-memory/0x00529c60-0x00529cf8.MusicControlDialogDirectoryPacketHandler.md` | `command_id:000000001140`, `command_timestamp:2026-06-25T03:56:34-04:00`, exit `0`, `ok:1`, `generated_refresh:skipped` via `--no-generated-refresh`. |
| `0003MH` | `by-memory/0x00529d00-0x00529ed1.MusicControlDialogRefreshControlStates.md` | `command_id:000000001141`, `command_timestamp:2026-06-25T03:56:36-04:00`, exit `0`, `ok:1`, `generated_refresh:skipped` via `--no-generated-refresh`. |
| `0003MI` | `by-memory/0x00529ee0-0x0052a00c.MusicControlDialogFolderPathSelected.md` | `command_id:000000001142`, `command_timestamp:2026-06-25T03:56:37-04:00`, exit `0`, `ok:1`, `generated_refresh:skipped` via `--no-generated-refresh`. |
| `0003MJ` | `by-memory/0x0052a010-0x0052a120.MusicControlDialogDrivePopupPopulate.md` | `command_id:000000001143`, `command_timestamp:2026-06-25T03:56:39-04:00`, exit `0`, `ok:1`, `generated_refresh:skipped` via `--no-generated-refresh`. |
| `0003MK` | `by-memory/0x0052a120-0x0052a17f.MusicControlDialogApplyPlaybackState.md` | `command_id:000000001144`, `command_timestamp:2026-06-25T03:56:41-04:00`, exit `0`, `ok:1`, `generated_refresh:skipped` via `--no-generated-refresh`. |
| `0003ML` | `by-memory/0x0052a180-0x0052a1e9.MusicControlDialogTogglePauseState.md` | `command_id:000000001145`, `command_timestamp:2026-06-25T03:56:42-04:00`, exit `0`, `ok:1`, `generated_refresh:skipped` via `--no-generated-refresh`. |
| `0003MM` | `by-memory/0x0052a1f0-0x0052a227.MusicControlDialogRefreshFolderPathControl.md` | `command_id:000000001146`, `command_timestamp:2026-06-25T03:56:44-04:00`, exit `0`, `ok:1`, `generated_refresh:skipped` via `--no-generated-refresh`. |
| `0003MN` | `by-memory/0x0052a230-0x0052a271.MusicControlDialogNextTrackHelper.md` | `command_id:000000001147`, `command_timestamp:2026-06-25T03:56:45-04:00`, exit `0`, `ok:1`, `generated_refresh:skipped` via `--no-generated-refresh`. |
| `0003MO` | `by-memory/0x0052a280-0x0052a2cb.MusicControlDialogPreviousTrackHelper.md` | `command_id:000000001148`, `command_timestamp:2026-06-25T03:56:47-04:00`, exit `0`, `ok:1`, `generated_refresh:skipped` via `--no-generated-refresh`. |
| `0003MP` | `by-memory/0x0052a2d0-0x0052a304.MusicControlDialogApplySoundEffectEnabled.md` | `command_id:000000001149`, `command_timestamp:2026-06-25T03:56:48-04:00`, exit `0`, `ok:1`, `generated_refresh:skipped` via `--no-generated-refresh`. |
| `0003MQ` | `by-memory/0x0052a310-0x0052a3e0.MusicControlDialogApplyOutputSelection.md` | `command_id:000000001150`, `command_timestamp:2026-06-25T03:56:50-04:00`, exit `0`, `ok:1`, `generated_refresh:skipped` via `--no-generated-refresh`. |
| `0003MR` | `by-memory/0x0052a4e0-0x0052a535.MusicControlDialogScalarDeletingDestructor.md` | `command_id:000000001152`, `command_timestamp:2026-06-25T03:56:51-04:00`, exit `0`, `ok:1`, `generated_refresh:skipped` via `--no-generated-refresh`. |

Validator notes:

- The first target/file/class validators returned `generated_refresh:deferred`; `python .\tools\validator.py --queue-status` then returned `command_id:000000001164`, `command_timestamp:2026-06-25T03:59:40-04:00`, with `queued generated refresh jobs:0` and `processing generated refresh jobs:0`.
- A retry with `--wait-generated` succeeded through `0003ME` and updated validator-owned generated reports, but command `000000001137` for `0003MF` failed during a generated C++ write to unrelated `auto-generated/NexusTK/ui/dialogs/BulletinReplyAlerts.cpp` with `PermissionError [WinError 5]`. B011 then reran remaining child validators with `--no-generated-refresh`, all exit `0`.
- Earlier command `000000001111` failed transiently while replacing validator-owned `tools/validator.ini` with `PermissionError [WinError 5]`; after the queue cleared, the same child validation was rerun successfully.
- Validator file scans restored the target and child `Item Summary` values from stale/blank validator state. B011 reapplied the accepted target and child `Item Summary` text after validation and verified no stale `most dialog methods` phrase or blank MusicControlDialog child summaries remained. No manual edits were made to generated files, project-level files, validator state/cache, IDA DB, or coverage reports.

## Correction Pass Validator Results

B011 ran these scoped correction validators from `source-3/project-documentation` after updating the accepted report and by-* implementation for the Rule 26 correction. All used `--no-generated-refresh`; generated refresh state is therefore `skipped`.

| File | Command id / timestamp | Exit / ok / generated refresh |
| --- | --- | --- |
| `by-memory/0x00528e60-0x0052a535.MusicControlDialog.md` | `000000001259` / `2026-06-25T04:58:41-04:00` | exit `0`, `ok:1`, `generated_refresh:skipped` |
| `by-file/MusicControlDialog.md` | `000000001260` / `2026-06-25T04:58:42-04:00` | exit `0`, `ok:1`, `generated_refresh:skipped` |
| `by-class/MusicControlDialog.md` | `000000001261` / `2026-06-25T04:58:43-04:00` | exit `0`, `ok:1`, `generated_refresh:skipped` |
| `by-memory/0x00529b70-0x00529bda.MusicControlDialogUnmodeledSoundEffectApply.md` | `000000001262` / `2026-06-25T04:58:45-04:00` | exit `0`, `ok:1`, `generated_refresh:skipped` |
| `by-memory/0x00529c60-0x00529cf8.MusicControlDialogDirectoryPacketHandler.md` | `000000001244` / `2026-06-25T04:49:35-04:00` | exit `0`, `ok:1`, `generated_refresh:skipped` |
| `by-memory/0x0052a010-0x0052a120.MusicControlDialogDrivePopupPopulate.md` | `000000001263` / `2026-06-25T04:58:46-04:00` | exit `0`, `ok:1`, `generated_refresh:skipped` |
| `by-memory/0x0052a120-0x0052a17f.MusicControlDialogApplyPlaybackState.md` | `000000001245` / `2026-06-25T04:49:41-04:00` | exit `0`, `ok:1`, `generated_refresh:skipped` |
| `by-memory/0x0052a1f0-0x0052a227.MusicControlDialogRefreshFolderPathControl.md` | `000000001264` / `2026-06-25T04:58:48-04:00` | exit `0`, `ok:1`, `generated_refresh:skipped` |
| `by-memory/0x0052a230-0x0052a271.MusicControlDialogNextTrackHelper.md` | `000000001265` / `2026-06-25T04:58:50-04:00` | exit `0`, `ok:1`, `generated_refresh:skipped` |
| `by-memory/0x0052a280-0x0052a2cb.MusicControlDialogPreviousTrackHelper.md` | `000000001266` / `2026-06-25T04:58:51-04:00` | exit `0`, `ok:1`, `generated_refresh:skipped` |
| `by-memory/0x0052a310-0x0052a3e0.MusicControlDialogApplyOutputSelection.md` | `000000001267` / `2026-06-25T04:58:52-04:00` | exit `0`, `ok:1`, `generated_refresh:skipped` |

Validator-owned side effects during the correction validators were limited to validator-managed state/reporting effects such as `projected_stats_update`, `uid_link_insert`, `reference_index_add`, `autogen_registry_update`, and validator-inserted metadata/header spacing; generated refresh was disabled for each command. `by-file/MusicControlDialog.md` and `by-class/MusicControlDialog.md` still report the pre-existing `missing_ref_uid 00040O` diagnostic. B011 did not manually edit generated files, project-level files, validator state/cache, IDA DB, or any coverage report.

Lease closeout: after the final edit/validator batch, `python .\tools\leaser\leaser.py Agent-B011 unlease` returned `Agent-B011: No active leases`, and `tools/leaser/Agents/current_leases.md` reported no active leases.

## Changed Files

Implementation changed these source docs:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B011/research/0001CP-MusicControlDialog-source-quality.md`
- `by-memory/0x00528e60-0x0052a535.MusicControlDialog.md`
- `by-file/MusicControlDialog.md`
- `by-class/MusicControlDialog.md`
- `by-memory/0x00528e60-0x0052976c.MusicControlDialogConstructor.md`
- `by-memory/0x00529770-0x0052978f.MusicControlDialogNonDeletingDestructor.md`
- `by-memory/0x00529790-0x00529b70.MusicControlDialogHandleControlCommand.md`
- `by-memory/0x00529b70-0x00529bda.MusicControlDialogUnmodeledSoundEffectApply.md`
- `by-memory/0x00529be0-0x00529c5a.MusicControlDialogSoundEffectPacketHandler.md`
- `by-memory/0x00529c60-0x00529cf8.MusicControlDialogDirectoryPacketHandler.md`
- `by-memory/0x00529d00-0x00529ed1.MusicControlDialogRefreshControlStates.md`
- `by-memory/0x00529ee0-0x0052a00c.MusicControlDialogFolderPathSelected.md`
- `by-memory/0x0052a010-0x0052a120.MusicControlDialogDrivePopupPopulate.md`
- `by-memory/0x0052a120-0x0052a17f.MusicControlDialogApplyPlaybackState.md`
- `by-memory/0x0052a180-0x0052a1e9.MusicControlDialogTogglePauseState.md`
- `by-memory/0x0052a1f0-0x0052a227.MusicControlDialogRefreshFolderPathControl.md`
- `by-memory/0x0052a230-0x0052a271.MusicControlDialogNextTrackHelper.md`
- `by-memory/0x0052a280-0x0052a2cb.MusicControlDialogPreviousTrackHelper.md`
- `by-memory/0x0052a2d0-0x0052a304.MusicControlDialogApplySoundEffectEnabled.md`
- `by-memory/0x0052a310-0x0052a3e0.MusicControlDialogApplyOutputSelection.md`
- `by-memory/0x0052a4e0-0x0052a535.MusicControlDialogScalarDeletingDestructor.md`

Correction pass changes for this callback were limited to the report plus these by-* source docs:

- `by-memory/0x00528e60-0x0052a535.MusicControlDialog.md`
- `by-file/MusicControlDialog.md`
- `by-class/MusicControlDialog.md`
- `by-memory/0x00529b70-0x00529bda.MusicControlDialogUnmodeledSoundEffectApply.md`
- `by-memory/0x00529c60-0x00529cf8.MusicControlDialogDirectoryPacketHandler.md`
- `by-memory/0x0052a010-0x0052a120.MusicControlDialogDrivePopupPopulate.md`
- `by-memory/0x0052a120-0x0052a17f.MusicControlDialogApplyPlaybackState.md`
- `by-memory/0x0052a1f0-0x0052a227.MusicControlDialogRefreshFolderPathControl.md`
- `by-memory/0x0052a230-0x0052a271.MusicControlDialogNextTrackHelper.md`
- `by-memory/0x0052a280-0x0052a2cb.MusicControlDialogPreviousTrackHelper.md`
- `by-memory/0x0052a310-0x0052a3e0.MusicControlDialogApplyOutputSelection.md`

Validator-owned side effects observed during scoped validation included `projected_stats_update`, `research_tracker_update`, `memory_auto_coverage_update`, `autogen_backup_create`, and generated refresh attempts. B011 did not manually edit generated/project-level/tool-state files.

## Implementation Tracking Checklist

- [x] Update [UID:0001CP] metadata from `88/90` to `89/91`, preserving owner `0000LN`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LN`, and blank aggregate C++. Proof: `by-memory/0x00528e60-0x0052a535.MusicControlDialog.md` header now has `COMPLETION:89`, `CONFIDENCE:91`, owner/emitter unchanged, and `RECONSTRUCTION_CPP CODE:[[[]]]`.
- [x] Replace [UID:0001CP] Item Summary with the B011 summary text supplied in this report. Proof: target header now has the B011 2026-06-25 MCP summary; validator restored the stale summary during file scan, so B011 reapplied and verified it after validation.
- [x] Add the B011 MCP evidence note to [UID:0001CP], including active session `80de0a67`, exact formal function inventory, raw start list, no-entry-route finding, and no-aggregate-C++ policy. Proof: target `## IDA MCP Evidence` has the B011 2026-06-25 session `80de0a67` inventory, raw starts, negative route evidence, component graph, and blank aggregate C++ proof.
- [x] Correction pass: replace stale [UID:0001CP] wording that still treated [UID:0003MG] string conversion and [UID:0003MK] fallback routing as open. Proof: target/report/file/class text now identifies the BDir StringBase chain and `0x00509480` -> `SoundManager::PlayMusicByZone` tail as resolved; the remaining caps are documented raw/no-entry routes, formal no-direct helpers, role-based MapPane field spelling, and generated-row refresh. Final targeted and broad stale-wording scans found no remaining called-out stale helper-route wording in the changed target/support pages.
- [x] Update `by-file/MusicControlDialog.md` to `88/88` only if the implementation incorporates the B011 status note and preserves the existing source placement. Proof: file header is `88/88`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"` is unchanged, and Evidence Notes/Changes contain the B011 status note.
- [x] Update `by-class/MusicControlDialog.md` to `88/88` only if the implementation incorporates the B011 class/field status note. Proof: class header is `88/88`, owner/emitter route unchanged, and Evidence/Data/Changes contain the B011 field/global status note.
- [x] Populate blank or stale Item Summary fields for [UID:0003MB] through [UID:0003MR] using the exact summary table in this report. Proof: all 17 child pages have nonblank accepted summaries after final reapply; validators had restored blanks, so B011 reapplied and verified no `Item Summary:  |` remains in the MusicControlDialog child set.
- [x] Correction pass: keep [UID:0003ME], [UID:0003MM], [UID:0003MN], and [UID:0003MO] blank-C++ at their current scores because current MCP and child route scans prove no function/xref/caller/table/vtable/member-pointer/VA/RVA entry route. Proof: report, target, and raw child docs spell out the current `lookup_funcs`/`xref_query` negatives, checked route classes, behavior roles, rejected alternatives, and blank-C++ disposition; final validators `000000001262`, `000000001264`, `000000001265`, and `000000001266` all exited `0` with `ok:1` and `generated_refresh:skipped`.
- [x] Correction pass: keep [UID:0003MJ] and [UID:0003MQ] first-draft C++ with exact no-direct-entry evidence rather than generic wording. Proof: report/target and child docs record current MCP `lookup_funcs` formal functions at `0x0052a010` and `0x0052a310`, zero incoming refs from `xref_query`, rejected raw/no-entry blanking alternatives, and retained source-shaped C++; scores remain `87/91` and `87/89`; validators `000000001263` and `000000001267` exited `0` with `ok:1` and `generated_refresh:skipped`.
- [x] Correction pass: update [UID:0003MG] child C++/notes to explicit source-facing ANSI and wide StringBase temporaries. Proof: child C++ now uses `StringBase<char> ansiPath(path);` and `StringBase<wchar_t> widePath(ansiPath);`, notes cite `0x582730`, `0x582830`, `0x582b70`, and `0x582b30`, and final validator `000000001244` exited `0` with `ok:1` and `generated_refresh:skipped`.
- [x] Correction pass: update [UID:0003MK] child C++/notes to `SoundManager::PlayMusicByZone` through the shared `0x00509480` mode-zero tail. Proof: child C++ now calls `g_pSoundManager->PlayMusicByZone(...)` with role-named `g_activeMapPane+0x4d0/+0x4d4/+0x4d8` fields, notes cite the only `0x00509480` xrefs and the `0x0057a0b0` SoundManager callee, and final validator `000000001245` exited `0` with `ok:1` and `generated_refresh:skipped`.
- [x] Keep [UID:0002N2], [UID:0002N3], and [UID:0001CQ] owned/emitted by their FunctionObject support route; do not move them to MusicControlDialog. Proof: verification showed `0002N2`/`0002N3` still `CANONICAL_OWNER:0000AL`, `EMITTER_UIDS:0000JO`; `0001CQ` still `CANONICAL_OWNER:0000JO`, `EMITTER_UIDS:0000JO`.
- [x] Use canonical [UID:00028Q] `g_pConfig` and [UID:00028R] `g_pSoundManager` names in MusicControlDialog text, keeping raw `dword_*` labels only as IDA evidence aliases. Proof: target/file/class docs now link [UID:00028Q] and [UID:00028R]; remaining raw labels occur only as IDA aliases in the MCP evidence bullet.
- [x] Run scoped validators for each edited source doc; do not edit generated files, validator state/cache, IDA DB, or any coverage report manually. Proof: correction validator table lists each changed by-* file: `000000001259`, `000000001260`, `000000001261`, `000000001262`, `000000001244`, `000000001263`, `000000001245`, `000000001264`, `000000001265`, `000000001266`, and `000000001267`, all exit `0`, `ok:1`, `generated_refresh:skipped`. B011 did not manually edit banned files; validator-owned side effects are recorded separately.
- [x] If generated tracker/coverage rows remain stale after validators, ask the supervisor to run the project report lifecycle/rescan path for generated state and unregistered executed B002/B003 report rows. Proof: B011 did not hand-edit generated rows; final correction validators used `--no-generated-refresh`, so generated refresh stayed skipped by design. Supervisor should use validator lifecycle/rescan/report execution if generated rows remain stale.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/0001CP-MusicControlDialog-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B011/research/0001CP-MusicControlDialog-source-quality.md","timestamp":"2026-06-25T05:03:28","uid":"0001CP"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001CP-MusicControlDialog-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/0001CP-MusicControlDialog-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001CP"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
