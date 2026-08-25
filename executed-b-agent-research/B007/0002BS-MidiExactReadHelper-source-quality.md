** TARGET-REPORT-UID:0002BS **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002BS MidiExactReadHelper Source-Quality Report

Assignment: `B007-report-0002BS-MidiExactReadHelper-source-quality-20260629`

Target: [UID:0002BS] `by-memory/0x00526650-0x005266a1.MidiExactReadHelper.md`

Report path: `tools/leaser/Agents/Agent-B007/research/0002BS-MidiExactReadHelper-source-quality.md`

Initial report-only research did not edit target/support by-* docs, generated files, project-level generated files, manual `-coverage-report.md` files, validator/tool state, lock files, the IDA DB, or any generated C++ file. During the accepted 2026-06-29 implementation callback, I edited only the leased target/support by-* docs listed in the implementation checklist and this report, ran scoped validators, inspected validator-generated `auto-generated/NexusTK/audio/MidiPlayer.cpp`, released leases, and did not run `execute_report`, edit generated files manually, edit manual coverage reports, edit lock files, edit validator state by hand, touch the IDA DB, start/stop/restart MCP, or spawn subagents.

## Final Recommendation

[UID:0002BS] should stop emitting an empty marker and should carry formal first-draft C++ for the private MIDI document exact-read helper:

```text
COMPLETION:88
CONFIDENCE:91
CANONICAL_OWNER:0000LD
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000LD
EMITTER_POSITION_OPTIONAL:
```

Final disposition: formal C++ on the exact existing child page. Do not split the range, merge it into [UID:00023B], mark it covered by [UID:0002C7], convert it to metadata-only/no-code, move it to `DATFile`, attach it to the `MidiPlayer` class, or create a new `MidiSMFDocument.cpp` owner for this pass. The correct owner/emitter remains [UID:0000LD] `by-file/MidiPlayer.md` / `NexusTK/audio/MidiPlayer.cpp`.

The old blank-C++ blocker is now stale in part. Current MCP still finds no original helper/type symbol and no full by-type `MidiDocument` page, so the score should remain below final audit. But B001's accepted MIDI source-quality report and current support docs now accept `MidiReadExact`, `MidiDocument`, `MidiReadRaw`, `MidiSeekSource`, `datFileSource`, `datFile`, and `fileHandle` as descriptive draft names, and generated [UID:0002C7] draft code already calls `MidiReadExact`. Current MCP reconfirms that the target body exactly implements that helper.

Recommended target `RECONSTRUCTION_CPP CODE` content:

```cpp
static int MidiReadExact(MidiDocument* document, void* buffer, DWORD bytesToRead)
{
    DWORD bytesRead = bytesToRead;
    int readOk;

    if (document->datFileSource != 0) {
        readOk = document->datFile.Read(buffer, bytesToRead);
    } else {
        readOk = ReadFile(document->fileHandle, buffer, bytesToRead, &bytesRead, NULL);
    }

    return readOk == 0 || bytesRead != bytesToRead;
}
```

## Current Target State

Current target page state:

| Field | Current value |
| --- | --- |
| UID | `0002BS` |
| Range | `0x00526650-0x005266a1` |
| Current score | `86/90` |
| Owner/emitter | `CANONICAL_OWNER:0000LD`, `EMITTER_UIDS:0000LD` |
| Reconstructable | `TRUE` |
| Current C++ | Blank formal block |
| Current summary | "Exact-count adapter/File API read helper; short reads fail." |

Current target body summary is correct: IDA models `sub_526650` as a 0x51-byte helper that reads exactly the caller-requested byte count from the MIDI document source, chooses between the embedded DAT-backed source path and the Win32 file-handle path, and returns nonzero on failure or short read.

The stale part is the no-code rationale. The target says final C++ remains blank because source-quality names for the MIDI document reader, adapter interface, and helper declaration were unavailable in local IDA types and by-type docs. That was true for the 2026-06-16 A002 pass, but later accepted support now supplies descriptive draft names and a concrete `MidiDocument` field model for this exact source family.

## Pre-Callback Generated State And Callback Refresh

At report-only time, generated state was stale and needed validator-owned refresh during an accepted implementation callback, not manual generated-file edits:

| Source | Current observed state |
| --- | --- |
| `auto-generated/NexusTK/audio/MidiPlayer.cpp` | Line `914` still has `UID:0002BS` as `Completion:80 | Confidence:88 | Empty Emitter Marker`. |
| `auto-generated/-ag-research-tracker.md` | Row `1626` still reports `0002BS` as `80/88`, average `84.0`, reconstructable true, report count `0`. |
| `auto-generated/-ag-coverage-report-by-memory.md` | Row for `0002BS` still reports `emits_code:false`, `80%`, and old empty-emitter state. |
| Generated [UID:0002C7] body | `MidiLoadDocument` already calls `MidiReadExact(document, ...)` at generated lines around `804`, `809-812`, `849`, and `854`; the missing `MidiReadExact` body is the direct mismatch this report resolves. |

No generated file or generated report was hand-edited. Source by-* metadata/body edits plus scoped validator refresh corrected the UID0002BS generated C++ state during the implementation callback. Post-callback inspection of `auto-generated/NexusTK/audio/MidiPlayer.cpp` shows header `validator-command-id: 000000000423`, `validator-refreshed-at: 2026-06-29T06:22:13-04:00`, UID0002BS at `Completion:88 | Confidence:91`, `static int MidiReadExact(MidiDocument* document, void* buffer, DWORD bytesToRead)` present, and no UID0002BS empty-emitter marker. The generated [UID:0002C7] `MidiLoadDocument` body resolves all exact-read sites to `MidiReadExact` at lines `995`, `1000-1003`, `1040`, and `1045`. Other unrelated aggregate/support empty markers remain outside this callback.

## MCP Availability

IDA MCP was mandatory and was available.

- MCP endpoint: `http://127.0.0.1:13337/mcp`.
- JSON-RPC `initialize` succeeded; server reported `ida-pro-mcp` protocol `2025-06-18`.
- `idb_list` returned one active session: `992d23de`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, filename `NexusTK.exe.i64`, backend `worker`, owned/adopted, `pid=12076`, `worker_pid=12076`, `is_analyzing:false`.
- `server_health(database='992d23de')`: `status:ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- No IDA DB writes, comments, renames, type changes, analysis management, or MCP process management were performed.

## MCP Evidence Checked

Live MCP tools used for this report:

- `idb_list`
- `server_health`
- `lookup_funcs`
- `xrefs_to`
- `callees`
- `decompile`
- `disasm`
- `get_bytes`
- `find_regex`
- `analyze_component`
- `entity_query`

### Function Boundaries

`lookup_funcs` results in session `992d23de`:

| Query | Result |
| --- | --- |
| `0x00526650` | `sub_526650`, size `0x51` |
| `0x005266a0` | still inside `sub_526650`, size `0x51` |
| `0x005266a1` | not a function |
| `0x005266b0` | `sub_5266B0`, size `0xd4` |
| `0x00527000` | `sub_527000`, size `0x39` |
| `0x005273a0` | `sub_5273A0`, size `0x41b` |

`get_bytes` confirms alignment around the target:

- `0x0052664b size 5`: five `0xcc` bytes before the target.
- `0x005266a1 size 15`: fifteen `0xcc` bytes after the target and before [UID:0002BT] at `0x005266b0`.

`entity_query functions 0x00526640-0x005270e0` returns the modeled functions in the island as `0x00526650`, `0x005266b0`, `0x00526790`, `0x005269f0`, `0x00526bb0`, `0x00526da0`, `0x00527000`, `0x00527080`, `0x005270c0`, and `0x005270e0`. This preserves the current child split and does not require a range change for [UID:0002BS].

### Callers And Callees

`xrefs_to 0x00526650` returns four direct code xrefs, all inside [UID:0002C7] `sub_5273A0`:

| Call site | Containing function | Role |
| --- | --- | --- |
| `0x005274aa` | `sub_5273A0` size `0x41b` | Fixed-size read in the SMF loader. |
| `0x005274f0` | `sub_5273A0` size `0x41b` | Fixed-size read in the SMF loader. |
| `0x00527597` | `sub_5273A0` size `0x41b` | `MTrk` tag read path. |
| `0x005275b9` | `sub_5273A0` size `0x41b` | Track-length read path. |

Focused `disasm` at the four call sites shows the loader passes the document in `ecx`, pushes a local buffer pointer, calls `sub_526650`, then treats a nonzero return as failure via `test eax, eax` / `jnz loc_52741B`:

- `0x005274a4`: `lea eax, [ebp+arg_0]`, `mov ecx, esi`, `push eax`, `call sub_526650`, `test eax, eax`, `jnz loc_52741B`.
- `0x005274ea`: `lea eax, [ebp+var_18]`, `mov ecx, esi`, `push eax`, `call sub_526650`, `test eax, eax`, `jnz loc_52741B`.
- `0x00527591`: `lea eax, [ebp+Buffer]`, `mov ecx, esi`, `push eax`, `call sub_526650`, `test eax, eax`, `jnz loc_52741B`, then compare `MTrk` tag `0x6b72544d`.
- `0x005275b3`: `lea eax, [ebp+arg_0]`, `mov ecx, esi`, `push eax`, `call sub_526650`, `test eax, eax`, `jnz loc_52741B`.

`callees 0x00526650` returns the external `ReadFile` import at `0x60d1c4`. The DAT-backed read branch is a virtual call through the embedded object and appears in decompilation/disassembly rather than as a named callee.

### Target Decompilation

Current `decompile 0x00526650`:

```cpp
BOOL __thiscall sub_526650(int this, LPVOID lpBuffer, DWORD nNumberOfBytesToRead)
{
  int v3; // eax
  int v4; // eax
  DWORD NumberOfBytesRead; // [esp+4h] [ebp-4h] BYREF

  if ( *(_DWORD *)(this + 20) )
  {
    v3 = *(_DWORD *)(this + 24);
    NumberOfBytesRead = nNumberOfBytesToRead;
    v4 = (*(int (__thiscall **)(int, LPVOID, DWORD))(v3 + 32))(this + 24, lpBuffer, nNumberOfBytesToRead);
  }
  else
  {
    v4 = ReadFile(*(HANDLE *)(this + 44), lpBuffer, nNumberOfBytesToRead, &NumberOfBytesRead, 0);
  }
  return !v4 || NumberOfBytesRead != nNumberOfBytesToRead;
}
```

Current `disasm 0x00526650` confirms the same body:

- `0x00526654`: compares `dword ptr [ecx+14h]` with zero.
- DAT-backed branch:
  - `0x0052665e`: loads `[ecx+18h]`.
  - `0x00526661`: advances `ecx` to `this+0x18`.
  - `0x00526668`: seeds `NumberOfBytesRead` with the requested byte count.
  - `0x0052666b`: calls vtable slot `+0x20`.
- Win32 file branch:
  - `0x00526670-0x0052667d`: pushes `lpOverlapped=NULL`, local out-count pointer, requested byte count, buffer, and handle `[ecx+2Ch]`, then calls `ReadFile`.
- Return contract:
  - `0x00526683`: tests the read result.
  - `0x00526687`: compares local byte count to requested length.
  - `0x0052668c-0x00526692`: returns `0` only when read succeeded and byte count matched.
  - `0x00526695-0x0052669e`: returns `1` for failed read or short read.

This exactly matches the proposed `MidiReadExact` body: seed `bytesRead` to the requested length for the DAT path, dispatch `DATFile::Read` or `ReadFile`, and return nonzero on failed read or count mismatch.

### Adjacent Source-Helper Support

Current `decompile 0x00527000` for [UID:0002C2] confirms the same document source field model:

```cpp
int __thiscall sub_527000(int this, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, LPDWORD lpNumberOfBytesRead)
{
  if ( !*(_DWORD *)(this + 20) )
    return ReadFile(*(HANDLE *)(this + 44), lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, 0);
  *lpNumberOfBytesRead = nNumberOfBytesToRead;
  return (*(int (__thiscall **)(int, LPVOID, DWORD))(*(_DWORD *)(this + 24) + 32))(
           this + 24,
           lpBuffer,
           nNumberOfBytesToRead);
}
```

This is the raw-read sibling of exact-read:

- `this+0x14` is the DAT-backed source flag.
- `this+0x18` is the embedded `DATFile` member.
- vtable slot `+0x20` is the read slot.
- `this+0x2c` is the Win32 file handle.
- `ReadFile` is used with the caller-provided out-count pointer.

`xrefs_to 0x00527000` returns one SMF-loader caller at `0x0052763b`, so [UID:0002C2] and [UID:0002BS] are both live source primitives used by [UID:0002C7].

`analyze_component` over `0x00526650`, `0x005266b0`, `0x00526bb0`, `0x00527000`, and `0x005273a0` returns an internal call graph where `sub_5273A0` calls `sub_526650`, `sub_527000`, and `sub_526BB0`. It classifies `sub_526650` and `sub_527000` as internal-only and keeps the exact-read helper inside the MIDI reader/parser component rather than a public/generic file I/O API.

### Name And Type Evidence

Current MCP `find_regex "Midi|SMF|DATFile|Track"` returns WinMM import strings, DATFile RTTI names, and `MidiPlayer` RTTI names, but no recovered original MIDI document/source filename or helper symbol. This remains a score cap and should stay in the target rationale.

Filesystem support search shows:

- [UID:0000LD] `by-file/MidiPlayer.md` already lists accepted private helpers including `MidiReadRaw`, `MidiReadExact`, `MidiSeekSource`, `MidiOpenSource`, and `MidiReleaseDocument`.
- [UID:0000LD] also lists accepted private structs `MidiDocument`, `MidiTrackState`, `MidiEvent`, and `MidiStreamWriteContext`.
- [UID:00008A] `by-class/MidiPlayer.md` says the parser/source helpers are private file helpers under [UID:0000LD], not `MidiPlayer` object methods.
- [UID:0000T9] `by-global/MidiPlayerWinMMState.md` currently forward-declares `MidiDocument` and `MidiTrackState` and says full type pages would improve the future score ceiling, but their absence no longer blocks function-body C++.
- No `by-type` page currently defines a full `MidiDocument` or `MidiTrackState` structure. This report should not create one during the target implementation callback unless the supervisor explicitly extends scope.
- [UID:00003G] `by-class/DATFile.md` records `DATFile` as a 20-byte reader and lists `Read` at `0x0049c310`; [UID:0001XK] and [UID:0003I0] support the DATFile vtable slot model already incorporated by [UID:0002C1].

## Prior Accepted Report Evidence

B001's accepted MIDI source-quality report `executed-b-agent-research/B001/0002BU-0002BV-0002C6-0002C7-MidiSMFParserStreamSourceQuality.md` is directly relevant even though it did not implement [UID:0002BS]:

- It keeps `audio/MidiPlayer.cpp` as the best owner for MIDI parser/source helpers.
- It rejects a new `MidiSMFDocument.cpp` owner because no recovered filename, by-file page, or stronger source-tree route exists.
- It rejects attaching the parser/source helpers to [UID:00008A] `MidiPlayer` class because they operate on static document/global state and are better modeled as file-static/private helpers.
- It accepts the descriptive type names `MidiDocument`, `MidiTrackState`, `MidiEvent`, and `MidiStreamWriteContext`.
- It declares `MidiDocument` fields including `datFileSource`, embedded `DATFile datFile`, and `HANDLE fileHandle`.
- It lists helper prototypes including:
  - `static int MidiReadRaw(MidiDocument* document, void* buffer, DWORD bytesToRead, DWORD* bytesRead);`
  - `static int MidiReadExact(MidiDocument* document, void* buffer, DWORD bytesToRead);`
  - `static DWORD MidiSeekSource(MidiDocument* document, LONG offset, DWORD origin);`
  - `static int MidiOpenSource(MidiDocument* document, const wchar_t* path);`
  - `static void MidiReleaseDocument(MidiDocument* document);`
- It states by-type pages for `MidiDocument` and `MidiTrackState` would be helpful but are not required before drafting helper bodies.

B001's accepted [UID:0002C1] implementation report and executed target page are also relevant:

- [UID:0002C1] now emits formal `static DWORD MidiSeekSource(MidiDocument* document, LONG offset, DWORD origin)`.
- It uses the same `document->datFileSource`, `document->datFile`, and `document->fileHandle` field model recommended here.
- It records that the raw/no-route state is a confidence cap, not a no-code blocker, when behavior, owner, and source names are strong enough. [UID:0002BS] is stronger than [UID:0002C1] on route evidence because it is an IDA-modeled function with four direct loader xrefs.

B003's accepted [UID:0002B2] scratch-global declaration pass is relevant but not a reason to edit [UID:0002B2] now:

- [UID:0002B2] emits `MidiEvent`, fill-result constants, fill-state bits, and scratch globals before helper bodies.
- It intentionally does not emit full `MidiDocument`, `MidiTrackState`, or `MidiStreamWriteContext` definitions.
- It says full declarations should eventually move to by-type pages or a shared `MidiPlayer.cpp` declaration block, but their absence no longer blocks the already populated helper C++.

## Positive Evidence

- The exact target is a modeled function with stable half-open range `0x00526650-0x005266a1`.
- MCP confirms `0x005266a1` is outside the function and followed by all-`0xcc` padding before [UID:0002BT].
- The body has a normal source-level helper shape and no split/merge issue.
- Four direct xrefs from [UID:0002C7] show live parser reachability.
- All four call sites branch to failure when the helper returns nonzero, matching the `MidiReadExact` failure-return contract used by generated `MidiLoadDocument`.
- The DAT path and Win32 path use the same source fields as [UID:0002C2] `MidiReadRaw` and [UID:0002C1] `MidiSeekSource`.
- The accepted `MidiDocument` field model maps exactly to target offsets: `datFileSource` at `+0x14`, `datFile` at `+0x18`, and `fileHandle` at `+0x2c`.
- B001 already accepted `MidiReadExact` as the descriptive helper name and prototype for this exact role.
- Generated [UID:0002C7] already calls `MidiReadExact`, so implementing [UID:0002BS] removes a concrete generated-source missing-body mismatch.
- Owner/emitter [UID:0000LD] is supported by the target, parent, file, class, and executed B001/B003 support trail.

## Negative Evidence And Score Caps

- Current MCP did not recover original helper/type symbols for `MidiReadExact` or `MidiDocument`.
- Current `find_regex` found WinMM import strings, DATFile RTTI, and MidiPlayer RTTI, but no separate MIDI document source filename or original source symbol.
- No current by-type page defines full `MidiDocument` or `MidiTrackState`.
- `document->datFile.Read(...)` is a descriptive source call through an accepted field model; original method spelling and exact enclosing declaration style remain inferred.
- A separate `MidiSMFDocument.cpp` remains historically plausible but unproven.
- [UID:0002C2] `MidiSourceRawReadHelper` is still blank and lower-scored; this report should not force sibling C++ during the [UID:0002BS] callback.
- Generated reports and generated C++ are stale; they are validator-owned refresh targets, not evidence to override current by-* docs and MCP facts.

## Heuristic / Inference Reanalysis And Validation

### Owner And Source Placement

Best route: [UID:0000LD] `MidiPlayer.cpp`.

Evidence:

- [UID:0002BS] is physically inside [UID:00023B] `MidiFileReaderAndSMFParserHelpers`, already attached to [UID:0000LD].
- The only direct callers are in [UID:0002C7] `MidiSMFDocumentLoadHelper`, also attached to [UID:0000LD].
- [UID:0000LD] explicitly lists `MidiReadExact` in its accepted private helper set.
- [UID:00008A] explicitly says these parser/source helpers are private file helpers and not `MidiPlayer` object methods.
- The source fields are the same `MidiDocument` source fields used by `MidiReadRaw` and `MidiSeekSource`.

Rejected alternatives:

- `DATFile`: rejected. DATFile supplies the embedded read implementation, but [UID:0002BS] chooses between DAT-backed source and Win32 file handle and belongs to the MIDI document/source wrapper.
- [UID:00008A] `MidiPlayer` class method: rejected. The receiver is the private `MidiDocument` source context, not the 12-byte `MidiPlayer` object.
- New `MidiSMFDocument.cpp`: possible historical source split, but no recovered filename, by-file page, or stronger route exists than `MidiPlayer.cpp`.
- Covered by [UID:00023B]: rejected. [UID:00023B] is an aggregate inventory and should not duplicate exact child helper bodies.
- Covered by [UID:0002C7]: rejected. [UID:0002C7] calls the exact helper; it does not contain or replace the target body.

### First-Draft C++ Versus No-Code

Best disposition: formal first-draft C++.

Reasoning:

- The function is IDA-modeled and directly reached by the SMF loader.
- The body is small, exact, and source-authored.
- The accepted helper name and prototype exist in prior B001 source-quality work.
- The accepted `MidiDocument` field model exactly matches the current decompilation and sibling helper evidence.
- The generated loader already calls the missing helper by name.

Rejected no-code reasons:

- "No original symbols": still true, but current policy and accepted MIDI precedent allow descriptive/inferred names when source shape is strong.
- "No full by-type page": still true, but B001 and B003 explicitly say this no longer blocks helper-body C++ for the MIDI parser family.
- "Generic file I/O helper": rejected because callers and ownership are MIDI-specific.
- "Wait for sibling raw-read C++": rejected because [UID:0002BS] is self-contained and already has stronger modeled/caller evidence than several siblings.

### Split / Range

No split or merge is recommended. Current MCP reconfirms:

- `0x00526650-0x005266a1` is exactly `sub_526650`.
- `0x005266a1-0x005266b0` is padding.
- [UID:0002BT] starts at `0x005266b0`.

### Metadata / Score

Recommended score: `88/91`.

Completion should rise from `86` to `88` because current MCP plus accepted source-quality support now resolve the empty-emitter disposition and provide exact formal C++ text, while preserving the range, owner, emitter, and reconstructable state.

Confidence should rise from `90` to `91` because the target is modeled, has four direct loader callers, a clear decompilation, consistent sibling source-field evidence, and accepted helper/type names. It should not exceed `91` because original symbols, full by-type pages, and original helper-file split remain unrecovered.

## Ranked Source Disposition

| Rank | Disposition | Decision | Reason |
| ---: | --- | --- | --- |
| 1 | Private file-scope `MidiReadExact` in [UID:0000LD] `MidiPlayer.cpp` | Accept | Strong current MCP behavior/call evidence and accepted B001 helper/type naming. |
| 2 | Private helper in future `MidiSMFDocument.cpp` | Reject for now | Plausible source split but no recovered filename/by-file route. |
| 3 | `DATFile` method/wrapper | Reject | Target chooses between DAT-backed and Win32 sources; DATFile is only one branch. |
| 4 | [UID:00008A] `MidiPlayer` class method | Reject | Receiver is `MidiDocument`, not `MidiPlayer`. |
| 5 | Covered by parent/loader or no-code empty emitter | Reject | Exact modeled function body and generated missing-body mismatch require child formal C++. |

## Support-Doc Edit List For Accepted Callback

If accepted for implementation, apply report-level detail to these support docs only as needed:

1. `by-memory/0x00526650-0x005266a1.MidiExactReadHelper.md`
   - Change metadata to `88/91`; keep owner/emitter/reconstructable unchanged.
   - Update Item Summary to mention current B007 MCP session `992d23de`, exact modeled range, four SMF-loader callers, DATFile/Win32 exact-read branches, short-read failure return, and first-draft `MidiReadExact` readiness.
   - Insert the exact formal C++ body between the existing formal markers.
   - Add a `2026-06-29 B007 MCP Source-Quality Refresh` section with session/health, `lookup_funcs`, `xrefs_to`, `callees`, `decompile`, `disasm`, `get_bytes`, generated-stale, support-name, and negative-symbol evidence.
   - Update score rationale and reconstruction notes: old blank-C++ blocker is stale; original-symbol/full-type/source-split gaps remain score caps.
   - Add a change-log entry for this report/callback.

2. `by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md`
   - Add [UID:0002BS] to the source-quality child disposition as formal `MidiReadExact`.
   - Preserve the aggregate as inventory/container and do not duplicate the body.
   - Add concise current B007 evidence: exact-read child modeled `0x51`, four loader callers, DATFile/Win32 exact-read semantics, `0x005266a1-0x005266b0` padding, owner/emitter unchanged.
   - Record that the old exact-read name/type blocker is superseded by accepted `MidiDocument`/`MidiReadExact` names, while sibling blank helpers remain child-specific.

3. `by-file/MidiPlayer.md`
   - Update the MIDI SMF source-quality section to say [UID:0002BS] now carries formal `MidiReadExact` C++ on the exact child page.
   - Preserve [UID:0000LD] `NexusTK/audio/MidiPlayer.cpp` as owner/emitter.
   - Preserve rejected alternatives: not `DATFile`, not `MidiPlayer` class, not new `MidiSMFDocument.cpp`.
   - Do not add a file-level duplicate body.

4. `by-class/MidiPlayer.md`
   - Update related free helpers to mention [UID:0002BS] as private file-scope `MidiReadExact` over `MidiDocument`, not a `MidiPlayer` object method.
   - Preserve the class aggregate blank-C++ rationale.

5. `by-memory/0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper.md`
   - Add or refresh a support note that its existing `MidiReadExact(document, ...)` calls are now backed by formal [UID:0002BS] C++.
   - Do not change its existing C++ body unless a validator formatting pass requires no-op regeneration; it already calls `MidiReadExact`.

Do not edit [UID:0002C2] `MidiSourceRawReadHelper`, [UID:0002C1] `MidiSourceSeekHelper`, [UID:0002B2] `MidiSMFParserScratchGlobals`, by-type pages, generated reports, generated C++ files, manual `-coverage-report.md` files, validator state, lock files, or IDA DB unless a later supervisor callback explicitly expands scope.

## Validators For Accepted Callback

No validators were run in this report-only pass.

Recommended scoped validators after accepted by-* edits, from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0002BS-MidiExactReadHelper-source-quality-removed.md](0002BS-MidiExactReadHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Run the [UID:0002C7] validator only if that support page is edited. Record each command, command id, timestamp, exit code, ok count, warnings, generated refresh state, and validator-owned side effects.

After validators, inspect `auto-generated/NexusTK/audio/MidiPlayer.cpp` for [UID:0002BS]. Expected proof:

- Generated header `validator-command-id` and `validator-refreshed-at` match the latest relevant validator refresh.
- [UID:0002BS] appears at `Completion:88 | Confidence:91`.
- `static int MidiReadExact(MidiDocument* document, void* buffer, DWORD bytesToRead)` is present.
- There is no [UID:0002BS] `Empty Emitter Marker`.
- Existing [UID:0002C7] `MidiLoadDocument` calls continue to compile against/resolve to the helper name in generated text; post-refresh generated call sites are lines `995`, `1000-1003`, `1040`, and `1045`.

Do not manually edit `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/NexusTK/audio/MidiPlayer.cpp`, `tools/validator.ini`, queue/cache/state files, lock files, project-level generated files, or any manual `-coverage-report.md`.

## Claim And Incorporation Ledger

| ID | Claim / fact to incorporate or preserve | Action | Destination | Callback verification state | Evidence / proof |
| --- | --- | --- | --- | --- | --- |
| C01 | Target range is exact `0x00526650-0x005266a1`; `sub_526650` size `0x51`; `0x005266a1` is not a function. | incorporate | Target, parent | applied | Target `Address Range` and `2026-06-29 B007 MCP Source-Quality Refresh`; parent `2026-06-29 MidiReadExact Child Disposition`. Validator commands `000000000415` and `000000000416` returned `ok: 1`. |
| C02 | Padding before/after target is `0xcc`; successor [UID:0002BT] starts at `0x005266b0`. | incorporate | Target, parent | applied | Target boundary table and B007 refresh record `get_bytes` padding; parent covered-range row and child-disposition section preserve `0x005266a1-0x005266b0`. |
| C03 | Target has four direct SMF-loader callers at `0x005274aa`, `0x005274f0`, `0x00527597`, and `0x005275b9`. | incorporate | Target, parent, loader support | applied | Target B007 refresh, parent child-disposition section, and loader `2026-06-29 MidiReadExact Support Sync` list all four call sites. Validators `000000000415`, `000000000416`, and `000000000423` passed. |
| C04 | Each loader call treats nonzero target return as failure. | incorporate | Target, loader support | applied | Target B007 refresh and loader support sync record `test eax, eax` / nonzero failure branch behavior. |
| C05 | Target calls external `ReadFile` only on the Win32 branch. | incorporate | Target | applied | Target Source-State Evidence and B007 refresh record `callees 0x00526650` plus DATFile virtual branch distinction. |
| C06 | `this+0x14` / `document->datFileSource` selects DAT-backed versus Win32 source. | incorporate | Target, parent | applied | Target Source-State Evidence, formal C++, and parent child-disposition section use `document->datFileSource` / `this+0x14`. |
| C07 | `this+0x18` / `document->datFile` is the embedded DATFile member used for virtual read slot `+0x20`. | incorporate | Target, parent, file/class support | applied | Target Source-State Evidence/formal C++, parent source-quality row, by-file private-helper paragraph, and by-class related-helper paragraph preserve DATFile branch as embedded source, not owner. |
| C08 | `this+0x2c` / `document->fileHandle` is the Win32 file handle. | incorporate | Target, parent | applied | Target Source-State Evidence/formal C++ and parent child-disposition section preserve `fileHandle` / `this+0x2c`. |
| C09 | DAT path seeds local byte count to requested length before virtual read; Win32 path lets `ReadFile` write the count. | incorporate | Target C++ and evidence | applied | Target formal C++ initializes `DWORD bytesRead = bytesToRead;`; target B007 refresh and parent child-disposition explain the branch-specific byte-count behavior. |
| C10 | Return contract is nonzero on failed read or short read, zero only on success and exact count. | incorporate | Target C++ and loader support | applied | Target formal C++ returns `readOk == 0 || bytesRead != bytesToRead`; target/loader sections preserve nonzero failure handling. Generated `MidiPlayer.cpp` lines around UID0002BS include the body after validator `000000000423`. |
| C11 | Formal C++ should be `static int MidiReadExact(MidiDocument* document, void* buffer, DWORD bytesToRead)`. | incorporate | Target C++ | applied | Target formal block populated exactly with `static int MidiReadExact(...)`; generated check shows line `431` has the same signature after `validator-command-id: 000000000423`. |
| C12 | Recommended metadata is `88/91`, owner/emitter [UID:0000LD], reconstructable true, blank position. | incorporate | Target header, score rationale | applied | Target header now has `COMPLETION:88`, `CONFIDENCE:91`, unchanged `CANONICAL_OWNER:0000LD`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LD`, blank position. Validator `000000000415` recorded completion/confidence/canonical-owner updates. |
| C13 | [UID:0000LD] `MidiPlayer.cpp` remains best owner/emitter. | incorporate | Target, parent, by-file/class | applied | Target reconstruction notes, parent child disposition, by-file MIDI declarations, and by-class related helpers all preserve [UID:0000LD] / `NexusTK/audio/MidiPlayer.cpp`. |
| C14 | Do not attach to [UID:00008A] `MidiPlayer` class as a class method. | incorporate | Target, class support | applied | Target reconstruction notes and by-class related-helper/data-caveat/changes sections state `MidiReadExact` is private file-scope over `MidiDocument`, not a `MidiPlayer` method. |
| C15 | Do not move to `DATFile`. | incorporate | Target, file/class support | applied | Target reconstruction notes, parent child disposition, by-file declarations/changes, and by-class helper note preserve DATFile as one branch only, not the owner. |
| C16 | Do not create a new `MidiSMFDocument.cpp` route in this callback. | incorporate | Target, file support | applied | Target negative evidence, parent child disposition, by-file declarations/changes, and loader support sync keep `MidiSMFDocument.cpp` as unproven historical possibility only. |
| C17 | Do not mark [UID:0002BS] covered by [UID:00023B] or [UID:0002C7]. | incorporate | Target, parent, loader support | applied | Target reconstruction notes, parent section says aggregate records route only and does not duplicate C++; loader support sync preserves caller/child split. |
| C18 | Current `find_regex` found no original `MidiReadExact`/`MidiDocument` symbol. | incorporate | Target score rationale | applied | Target B007 refresh and score rationale preserve missing original-symbol evidence as confidence cap. |
| C19 | No full by-type `MidiDocument`/`MidiTrackState` pages currently exist. | incorporate | Target/support score rationale | applied | Target B007 refresh, target score rationale, and file declarations preserve full by-type absence as future/final-audit cap, not a C++ blocker. |
| C20 | Absence of full by-type pages no longer blocks first-draft helper bodies. | incorporate | Target reconstruction notes | applied | Target reconstruction notes historicalize the old blank-C++ blocker and explain accepted names/current MCP evidence make formal C++ appropriate. |
| C21 | Generated `MidiPlayer.cpp`, generated research tracker, and generated by-memory coverage are stale for UID0002BS. | historicalize | Target/support notes and checklist | applied | Historical stale state remains in report; validator refresh corrected generated C++: `auto-generated/NexusTK/audio/MidiPlayer.cpp` header `validator-command-id: 000000000423`, UID0002BS at `88/91`, formal body present, no UID0002BS empty marker. Generated tracker/coverage were refreshed only by validator-owned side effects. |
| C22 | Generated files/reports and manual coverage reports must not be manually edited by B007. | not-applicable | Exclusion/checklist | excluded-with-reason | No manual generated/report/coverage edits were made. Validator-owned generated side effects came only from scoped validators; manual `-coverage-report.md` files were untouched. |
| C23 | [UID:0002C2] sibling raw-read helper shares the source-field model but remains outside this implementation scope. | not-applicable | Checklist/support caveat | excluded-with-reason | [UID:0002C2] was not edited. Target and parent mention sibling evidence only as supporting field-model proof; no sibling C++ or metadata changes were applied. |
| C24 | [UID:0002C1] formal `MidiSeekSource` precedent supports using the same `MidiDocument` field model. | already-present | Target/support rationale | already-present | Accepted [UID:0002C1] precedent was already in support docs; target B007 refresh and parent/file support preserve it as rationale without changing [UID:0002C1]. |
| C25 | [UID:0002C7] already calls `MidiReadExact`; support update should preserve body and only note resolved helper backing. | already-present | Loader support doc | applied | Loader C++ body was not changed. Loader Detailed Notes, support sync, and change log now state existing calls are backed by UID0002BS formal C++; validator `000000000423` passed. |
| C26 | Validators must be scoped file-mode commands with `--wait-generated`; record command metadata and generated refresh proof. | incorporate | Implementation checklist | applied | Ran scoped validators `000000000415`, `000000000416`, `000000000418`, `000000000420`, `000000000423`; all exit `0`, `ok: 1`, `generated_refresh: completed`. Generated header matches latest command `000000000423`. |
| C27 | Leases should be short-lived and only for files actively edited during callback. | incorporate | Implementation checklist | applied | Initial accepted lease window expired before validation; renewed exactly five edited by-* files at `2026-06-29T10:20:58Z`, released immediately after edit/validator/generated-check batch. Shared lease report now says `No active leases.` |
| C28 | B007 must not run `execute_report`; supervisor owns report execution after verification. | not-applicable | Implementation checklist/final status | excluded-with-reason | `execute_report` was not run; report remains in Agent-B007 research folder for supervisor verification/execution. |

## Implementation Tracking Checklist

Callback implementation proof:

- [x] Lease only files about to be edited immediately; do not take reservation leases. Proof: renewed exactly the five edited by-* docs at `2026-06-29T10:20:58Z` after the earlier lease expired, then released them after validators/generated check. `tools/leaser/Agents/current_leases.md` now reports `No active leases.`
- [x] Update [UID:0002BS] target metadata to `COMPLETION:88`, `CONFIDENCE:91`, keep `CANONICAL_OWNER:0000LD`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LD`, and blank `EMITTER_POSITION_OPTIONAL`. Proof: target header updated; validator `000000000415` recorded `completion_update 88`, `confidence_update 91`, `canonical_owner_update 0000LD`, exit `0`, `ok: 1`.
- [x] Insert only the recommended `static int MidiReadExact(MidiDocument* document, void* buffer, DWORD bytesToRead)` body between the existing target `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END` lines. Proof: target formal block contains only the accepted function body; generated `MidiPlayer.cpp` line `431` has the signature after refresh.
- [x] Update [UID:0002BS] Item Summary, status, MCP evidence, source-state table, reconstruction notes, score rationale, and change log with current B007 session `992d23de` facts. Proof: target has `2026-06-29 B007 MCP Source-Quality Refresh`, updated Source-State Evidence, Score Rationale, Reconstruction Notes, and change log; validator `000000000415` passed.
- [x] Historicalize/reject the stale target no-code blocker: original symbols/full by-type pages are still missing, but accepted `MidiReadExact`/`MidiDocument` names and current MCP evidence make first-draft C++ appropriate. Proof: target reconstruction notes and score rationale explicitly mark old blank-C++ blocker historical while preserving original-symbol/full-type/source-split caps.
- [x] Update [UID:00023B] parent with formal `MidiReadExact` child disposition, current exact-read evidence, and sibling-specific caveat preservation. Proof: parent has `2026-06-29 MidiReadExact Child Disposition`, updated covered-range row, source-quality name row, open questions, score rationale, and change log; validator `000000000416` passed.
- [x] Update [UID:0000LD] `by-file/MidiPlayer.md` to include [UID:0002BS] among exact pages now carrying formal first-draft C++, without duplicating the body. Proof: by-file MIDI SMF declarations and change log now record UID0002BS as private file-scope `MidiReadExact` under `NexusTK/audio/MidiPlayer.cpp`; validator `000000000418` passed.
- [x] Update [UID:00008A] `by-class/MidiPlayer.md` to mention [UID:0002BS] as private file-scope `MidiReadExact` over `MidiDocument`, not a `MidiPlayer` method. Proof: by-class related helpers, data caveats, score rationale, open questions, and change log updated; validator `000000000420` passed with unrelated existing `missing_ref_uid 0003PF`.
- [x] Update [UID:0002C7] loader support only if needed to state its existing `MidiReadExact(document, ...)` calls now have a formal child helper body; do not rewrite its accepted C++ body. Proof: loader Detailed Notes, `2026-06-29 MidiReadExact Support Sync`, and change log updated; no loader C++ body changes were made; validator `000000000423` passed.
- [x] Do not edit [UID:0002C2], [UID:0002C1], [UID:0002B2], by-type pages, generated reports, generated C++ files, project-level generated files, manual `-coverage-report.md` files, validator/tool state, lock files, or IDA DB unless a later supervisor callback explicitly expands scope. Proof: manual edits were limited to five by-* docs and this Agent-B007 report. Validator-owned generated/project/tool-state side effects were not hand-edited. IDA DB was untouched.
- [x] Run scoped validators from `source-3/project-documentation` for every edited by-* file, normally with the commands listed in this report and `--wait-generated`. Proof: ran all five scoped commands with `--wait-generated`.
- [x] Record validator command id, timestamp, exit code, ok count, warnings, generated refresh state, and validator-owned side effects for each validator command. Proof:
  - `python .\tools\validator.py --mode file --file by-memory\0x00526650-0x005266a1.MidiExactReadHelper.md --apply --queue-timeout 240 --wait-generated`: `command_id 000000000415`, `command_timestamp 2026-06-29T06:21:06-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`; warnings/diagnostics: no UID0002BS-specific failure, broad existing stale/missing registry noise; side effects included validator-owned `autogen_cpp_update`, `memory_auto_coverage_update`, `research_tracker_update`, `projected_stats_update`, `autogen_registry_update`, and generated metadata refresh.
  - `python .\tools\validator.py --mode file --file by-memory\0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md --apply --queue-timeout 240 --wait-generated`: `command_id 000000000416`, `command_timestamp 2026-06-29T06:21:26-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`; warnings/diagnostics: no UID0002BS-specific failure, broad existing stale/missing registry noise; side effects included validator-owned generated metadata/coverage/projected-stats refresh.
  - `python .\tools\validator.py --mode file --file by-file\MidiPlayer.md --apply --queue-timeout 240 --wait-generated`: `command_id 000000000418`, `command_timestamp 2026-06-29T06:21:41-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`; warnings/diagnostics: no UID0002BS-specific failure, broad existing stale/missing registry noise; side effects included `reference_index_add 0002BS` and generated metadata/projected-stats refresh.
  - `python .\tools\validator.py --mode file --file by-class\MidiPlayer.md --apply --queue-timeout 240 --wait-generated`: `command_id 000000000420`, `command_timestamp 2026-06-29T06:21:57-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`; warning `missing_ref_uid 0003PF` is pre-existing/unrelated to UID0002BS; diagnostics also included broad existing stale/missing registry noise; side effects included `reference_index_add 0002BS` and generated metadata/projected-stats refresh.
  - `python .\tools\validator.py --mode file --file by-memory\0x005273a0-0x005277bb.MidiSMFDocumentLoadHelper.md --apply --queue-timeout 240 --wait-generated`: `command_id 000000000423`, `command_timestamp 2026-06-29T06:22:13-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`; warnings/diagnostics: no UID0002BS-specific failure, broad existing stale/missing registry noise; side effects included validator-owned `autogen_cpp_update`, `memory_auto_coverage_update`, `research_tracker_update`, `projected_stats_update`, and `autogen_registry_update`.
- [x] After generated refresh, inspect `auto-generated/NexusTK/audio/MidiPlayer.cpp` for [UID:0002BS] and confirm the generated body is present at `88/91` with no [UID:0002BS] empty-emitter marker. Proof: generated header is `validator-command-id: 000000000423`, `validator-refreshed-at: 2026-06-29T06:22:13-04:00`; line `430` is `UID:0002BS ... Completion:88 | Confidence:91`; line `431` is `static int MidiReadExact(...)`; UID0002BS has no empty marker; generated [UID:0002C7] calls resolve to `MidiReadExact` at lines `995`, `1000-1003`, `1040`, and `1045`; other unrelated non-code aggregate markers remain elsewhere.
- [x] Confirm `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-coverage-report-by-memory.md` refresh through validator/supervisor-owned tooling only; do not hand-edit them. Proof: validators reported validator-owned `research_tracker_update` and `memory_auto_coverage_update`; no manual generated report edits were made.
- [x] Update this report checklist with checked items and proof during the accepted implementation callback. Proof: this checked checklist and the ledger above were updated in place after validation and lease release.
- [x] Release all leases immediately after the edit/validator batch. Proof: `python .\leaser.py B007 unlease` returned `Success` for all five paths; shared lease report now says `No active leases.`
- [x] Do not run `execute_report`; supervisor owns report execution after independent verification. Proof: `execute_report` was not run; report remains at `tools/leaser/Agents/Agent-B007/research/0002BS-MidiExactReadHelper-source-quality.md`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0002BS-MidiExactReadHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0002BS-MidiExactReadHelper-source-quality.md","timestamp":"2026-06-29T06:32:46","uid":"0002BS"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002BS-MidiExactReadHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/0002BS-MidiExactReadHelper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002BS"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
