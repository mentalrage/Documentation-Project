** TARGET-REPORT-UID:0002PS **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002PS] LogoPlayerPaneConstructor Source-Quality Report

Agent: Agent-B004
Task type: B-agent source-quality / heuristic research
Target: `source-3/project-documentation/by-memory/0x004f53b0-0x004f5500.LogoPlayerPaneConstructor.md`
Report status: report-only; no by-* documentation edits made

## Recommendation

`LogoPlayerPaneConstructor` is ready for implementation. Replace the stale blank-C++ blocker with current gate analysis and populate first-draft constructor C++.

Recommended target metadata:

```text
COMPLETION:88
CONFIDENCE:91
RECONSTRUCTABLE:TRUE
CANONICAL_OWNER:00007H
EMITTER_UIDS:00007H
```

Rationale: the target already clears the current reconstructable code gate. The route is nonblank and source-backed: target [UID:0002PS] -> class owner/emitter [UID:00007H] `LogoPlayerPane` -> file owner/emitter [UID:0000O4] `StartupLogoPanes` -> `NexusTK/app/StartupLogoPanes.cpp`. Current target average is above 85, and the recommended 88/91 score leaves a remaining cap for exact original field spelling, exact formatter helper spelling, and the still-missing direct construction site.

## Evidence Checked

Documentation checked:

- Target doc `by-memory/0x004f53b0-0x004f5500.LogoPlayerPaneConstructor.md`.
- Aggregate doc `by-memory/0x004f53b0-0x004f570c.LogoPlayerPane.md` [UID:00019D].
- Class doc `by-class/LogoPlayerPane.md` [UID:00007H].
- File doc `by-file/StartupLogoPanes.md` [UID:0000O4].
- Child docs for cleanup destructor, advance-to-next-segment, input skip handlers, `OnClose`, scalar deleting destructor, and AUTOBUF helper.
- `by-memory/0x005c0040-0x005c045b.VideoPlayerPane.md`, especially helper `0x005c0110`.
- `by-type/by-template/AUTOBUF_unsigned_char.md` and `by-class/AUTOBUF_unsigned_char.md`.
- `by-resource/startup-logo-media.md`.
- `StdioFile` constructor/open/read/destructor docs.
- `FileError` class and constructor docs.
- `ApplicationStartup`, `BaramAppAndApplicationStartup`, `PlayStartupLogoBinkFile`, LogoPlayerPane vtable data, and startup logo resource string docs.
- Gate and ownership docs: `.codex/AGENTS.md`, Agent-B004 `goal.md`, `by-structure.md`, `inference_research.md`, and `proposed-source-tree.md`.

External/live tooling:

- IDA MCP at `http://127.0.0.1:13337/mcp` was unavailable during this pass (`Unable to connect to the remote server`).
- Local read-only executable used for independent verification: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Binary hashes: MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- Image base `0x00400000`; `.text` range `0x00401000-0x0060c4ac`, `.rdata` range `0x0060d000-0x0066c0be`.
- Raw PE/Capstone disassembly and byte scans were used for this report, while prior docs already carry live IDA-derived evidence.

## Constructor Findings

Exact function range remains `0x004f53b0-0x004f5500`; no split is needed. The bytes are a normal source constructor plus EH cleanup.

Confirmed instruction-level behavior:

- `0x004f53e3` calls `VideoPlayerPane` base constructor `0x005c0040`.
- `0x004f53f7`, `0x004f53fd`, and `0x004f5407` install the three LogoPlayerPane vtable pointers at `this+0x0`, `this+0xa0`, and `this+0xa4`. These are compiler-generated constructor vtable stores, not source ownership evidence for a separate file.
- `0x004f5414-0x004f5429` constructs the embedded `AUTOBUF<unsigned char>` at `this+0x100`, writes AUTOBUF vtable `0x0061b868`, and clears the AUTOBUF payload pointer/count fields at `this+0x104` and `this+0x108`.
- `0x004f542d-0x004f5437` stores the second constructor argument at `this+0x10c`.
- `0x004f543d` clears byte `this+0x110`.
- `0x004f5444`, `0x004f5453`, `0x004f545c`, and `0x004f5482` construct, open, read through, and destroy a stack `StdioFile`.
- The first constructor argument is the movie path passed to `StdioFile::Open`.
- The `StdioFile::ReadRemaining` helper fills the embedded AUTOBUF payload buffer.
- `0x004f5461-0x004f5476` reads the first dword of the AUTOBUF payload into `this+0x114`, passes `buffer+4` and that first size to `0x005c0110`, and opens the first memory-backed Bink segment.
- On open failure, `0x004f549c-0x004f54e4` formats `L"%s corrupted"` with the input movie path, constructs `FileError`, and throws it with throwinfo `0x0065b884`.

Resolved or best-supported names:

- Constructor signature: `LogoPlayerPane::LogoPlayerPane(const wchar_t *moviePath, FunctionObject0 *completionCallback)`.
- `this+0x100`: embedded `AUTOBUF<unsigned char> m_movieData` or `m_binkData`. I recommend `m_movieData` for first draft because it is caller-supplied movie payload, not specifically `LOGO.PAK`/`LOGO.PAD`.
- `this+0x104`: AUTOBUF owned byte pointer, recommended field spelling `m_data`/`data` according to whichever AUTOBUF docs settle globally.
- `this+0x108`: AUTOBUF byte count/capacity/state, recommended field spelling `m_size`/`count` according to global AUTOBUF docs.
- `this+0x10c`: `FunctionObject0 *m_completionCallback`. This is now strongly supported by `OnClose`: destructor releases through vslot `+0x00`, `OnClose` invokes through vslot `+0x0c`, and there is no null check.
- `this+0x110`: one-shot second-segment advance guard. I recommend `bool m_hasAdvancedSegment`. `m_skipRequested` is weaker because the byte is set immediately before the second segment open attempt and prevents repeated segment advance attempts, not merely recording user input.
- `this+0x114`: `unsigned int m_firstSegmentSize`.
- Stack local: `StdioFile movieFile` or `StdioFile file`; exact local spelling is unrecoverable.
- Helper `0x005c0110`: descriptive source name `OpenBinkVideo(segmentData, segmentSize)` is appropriate. The helper physically belongs with `VideoPlayerPane` and Bink handle fields, but its only currently recovered direct callers are this constructor and `LogoPlayerPane::AdvanceToNextSegment`. The second argument is part of the caller-side source shape even though the helper body ignores it.

## First-Draft C++ Recommendation

Populate the target C++ with a source-style constructor. The exact `LString`/format-helper spelling can be adapted to the local string wrapper names used by the implementation pass, but the source shape should not remain blank.

```cpp
LogoPlayerPane::LogoPlayerPane(const wchar_t *moviePath, FunctionObject0 *completionCallback)
    : VideoPlayerPane()
    , m_movieData()
    , m_completionCallback(completionCallback)
    , m_hasAdvancedSegment(false)
{
    StdioFile file;
    file.Open(moviePath);
    file.ReadRemaining(m_movieData);

    const unsigned char *movieData = m_movieData.m_data;
    m_firstSegmentSize = *reinterpret_cast<const unsigned int *>(movieData);

    if (!OpenBinkVideo(movieData + sizeof(unsigned int), m_firstSegmentSize)) {
        LString message(L"%s corrupted", moviePath);
        throw FileError(message);
    }
}
```

Implementation notes:

- Do not add an initializer for `m_firstSegmentSize`; the binary does not clear `this+0x114` before reading the file and storing the first dword.
- If current AUTOBUF docs standardize accessor names, use those names instead of `m_data`.
- If `StdioFile::ReadRemaining` is documented as pointer-taking rather than reference-taking in the generated headers, use `file.ReadRemaining(&m_movieData)`. The binary pushes the member address; either reference or pointer spelling is source-plausible.
- The failure path should preserve the formatted `L"%s corrupted"` message and the `FileError` throw, even if the exact temporary string wrapper is adjusted.

## Missing Direct Construction Site Investigation

This issue should no longer remain a passive open question. I actively checked direct call, data pointer, startup-flow, vtable, allocation, and factory patterns.

Direct references:

- REL32 scan of `.text` found no direct `call` or `jmp` to `0x004f53b0`.
- Whole-file VA and RVA dword scans found no pointer to `0x004f53b0`.
- The constructor is not represented in LogoPlayerPane vtables, as expected for a constructor.

Related function reference checks:

- `0x005c0110` has direct calls at `0x004f5476` from the constructor and `0x004f55af` from `AdvanceToNextSegment`.
- `0x004f5570` has direct calls from the key and mouse skip handlers.
- `0x004f5620` has a vtable pointer reference at `.rdata 0x0061d068`.
- `0x004f5680` has a vtable pointer reference at `.rdata 0x0061d018`.
- LogoPlayerPane vtable head immediates `0x0061d018`, `0x0061d070`, and `0x0061d0a0` appear as text stores only in the constructor, cleanup destructor, and scalar deleting destructor families.

Startup-flow checks:

- `ApplicationStartup` calls standalone `PlayStartupLogoBinkFile` at `0x004f63b5`.
- The `0x004f6381` allocation of `0x120` bytes is followed by a call to `0x004e7f20`; current docs identify this as an `IMEPane` construction path, not LogoPlayerPane.
- The visible startup pane path allocates `0x354` at `0x004f6419`, calls allocator `0x004f4aa0`, and calls `LogoPane` constructor `0x004f4c10` at `0x004f643c` with `NEXON.LGO` and a `PlainMemberFunctionObject0<BaramApp>` callback.
- The missing-logo fallback allocates terminal UI state; it does not construct LogoPlayerPane.

Best-supported conclusion:

The class is source-authored and reconstructable, but the current executable does not expose a static direct construction site. The strongest interpretation is retained/legacy/alternate startup movie pane code in `StartupLogoPanes.cpp` that is not selected by the recovered `ApplicationStartup` path, while the active executable path uses the standalone `PlayStartupLogoBinkFile` helper and/or `LogoPane`. A metadata-gap or computed-indirect construction path is still theoretically possible, but direct call, VA/RVA pointer, vtable, startup allocation, and known factory/callback checks found no evidence for it.

Impact: keep reconstructability and source ownership, but cap below final certainty. Do not cite "direct constructor caller not found" as a reason to leave C++ blank.

## Ownership And Source Placement

Recommended ownership:

- Keep target `CANONICAL_OWNER:00007H` and `EMITTER_UIDS:00007H`.
- Keep class [UID:00007H] routed through [UID:0000O4] `StartupLogoPanes`.
- Keep generated source placement under `NexusTK/app/StartupLogoPanes.cpp`.

Rejected alternatives:

- `VideoPlayerPane` / [UID:0000FV]: rejected as constructor owner. `0x005c0110` physically belongs with VideoPlayerPane/Bink handle state, but this constructor is a LogoPlayerPane source method and installs LogoPlayerPane vtables.
- `startup-logo-media` / [UID:0001RN]: rejected as owner. It documents resource contracts and payload format, not method ownership.
- `AUTOBUF_unsigned_char`: rejected as owner. AUTOBUF is the embedded support type at `this+0x100`; its constructor and layout are shared template/helper concerns.
- `ApplicationStartup`: rejected as direct owner or caller. Its recovered flow calls the standalone Bink helper and `LogoPane`, not this constructor.
- `LogoPane`: rejected as owner. It is a sibling/static `.LGO` pane path, not the segmented Bink LogoPlayerPane class.
- Standalone `PlayStartupLogoBinkFile`: rejected as this constructor's owner. It is a sibling startup Bink playback flow that uses local AUTOBUF and globals rather than a `LogoPlayerPane` instance.

## Recommended Target Doc Changes

In `by-memory/0x004f53b0-0x004f5500.LogoPlayerPaneConstructor.md`:

- Change metadata to `COMPLETION:88` and `CONFIDENCE:91`.
- Keep `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:00007H`, and `EMITTER_UIDS:00007H`.
- Replace the stale "final C++ blank until field/helper names and callback type final-source quality" language with current gate wording: target is reconstructable, routes through [UID:00007H] to [UID:0000O4] / `NexusTK/app/StartupLogoPanes.cpp`, and clears first-draft C++ eligibility.
- Add the first-draft C++ constructor above.
- Add resolved field/type names:
  - `AUTOBUF<unsigned char> m_movieData` at `+0x100`, payload pointer/count at `+0x104/+0x108`.
  - `FunctionObject0 *m_completionCallback` at `+0x10c`.
  - `bool m_hasAdvancedSegment` at `+0x110`.
  - `unsigned int m_firstSegmentSize` at `+0x114`.
- State that the first argument is the movie path and the second argument is the completion callback.
- State that `StdioFile` opens the caller-supplied movie path and reads the remaining bytes into the embedded AUTOBUF.
- State that the first dword of the payload is the first Bink segment size; the first Bink segment starts at `buffer+4`.
- State that `OpenBinkVideo` is the descriptive helper name for `0x005c0110`; it is VideoPlayerPane-local/base-state code called by this constructor and by `AdvanceToNextSegment`.
- Preserve the `FileError` throw path with formatted `L"%s corrupted"` text.
- Replace the passive direct-caller open question with the active investigation conclusion above.
- Keep remaining caveats limited to exact original member/local/formatter spelling, the missing direct construction site, and helper exposure/unused size argument.

## Recommended Support Doc Changes

Implement only if the supervisor accepts this report and issues an implementation callback.

`by-class/LogoPlayerPane.md`:

- Raise or confirm the constructor-related class notes with the same field names.
- Replace "constructor direct caller not recovered and final names not settled" as a blocking statement with the active investigation conclusion: no direct construction site was found after direct call, VA/RVA pointer, vtable, startup-flow, allocation, and factory/callback checks.
- State that constructor C++ is now first-draft ready while exact original spelling remains below-final evidence.
- Keep class owner/emitter route through `StartupLogoPanes`.

`by-memory/0x004f53b0-0x004f570c.LogoPlayerPane.md`:

- Update aggregate notes for [UID:0002PS] to reflect first-draft constructor readiness, resolved callback type, embedded AUTOBUF field naming, one-shot advance guard naming, and active missing-caller investigation.
- Keep the aggregate's child ownership model; no split or new owner is needed.

`by-file/StartupLogoPanes.md`:

- Add or update a short note that `LogoPlayerPane` is reconstructable source in `StartupLogoPanes.cpp`, but current `ApplicationStartup` evidence selects standalone `PlayStartupLogoBinkFile`/`LogoPane` paths and exposes no direct LogoPlayerPane constructor call.
- Keep `VideoPlayerPane` as the helper/base owner for `0x005c0110`, while noting LogoPlayerPane's two direct uses if not already present.

`by-memory/0x004f5570-0x004f55c8.LogoPlayerPaneAdvanceToNextSegment.md`:

- If touched, align `+0x110` naming to `m_hasAdvancedSegment`, `+0x114` to `m_firstSegmentSize`, and the helper call to `OpenBinkVideo(secondSegmentData, remainingSegmentSize)`.

`by-memory/0x005c0040-0x005c045b.VideoPlayerPane.md`:

- If touched, keep `0x005c0110` with VideoPlayerPane helper ownership, but document that the second/size argument is ignored by the helper body despite being supplied by both LogoPlayerPane callers.

Do not edit `by-memory/-coverage-report.md` during implementation. Use the pending replacement row below for supervisor-managed coverage update.

## Heuristic / Inference Reanalysis And Validation

Current stale issue: "below-95 no-code reasoning" should be removed. The current gate is not 95/95. A reconstructable target with a valid emitter route and combined score above 85 can carry first-draft C++ with explicit caveats.

Resolved:

- Callback type/member: `FunctionObject0 *m_completionCallback` at `+0x10c`.
- Skip/advance guard: one-shot second-segment advance guard at `+0x110`; recommended source name `m_hasAdvancedSegment`.
- First segment size: `unsigned int m_firstSegmentSize` at `+0x114`.
- Embedded AUTOBUF: `AUTOBUF<unsigned char> m_movieData` at `+0x100`, with pointer/count fields at `+0x104/+0x108`.
- StdioFile roles: stack file object opens `moviePath`, reads remaining file bytes into `m_movieData`, and is destroyed before constructor success return or EH cleanup.
- FileError path: first Bink open failure formats `L"%s corrupted"` with `moviePath`, constructs `FileError`, and throws.
- OpenBinkVideo call: constructor passes `movieData+4` and `m_firstSegmentSize` to `0x005c0110`.
- Source placement: `LogoPlayerPane` under `StartupLogoPanes.cpp`, not `VideoPlayerPane.cpp`, `AUTOBUF`, or resource docs.

Still caveated:

- Original member names are inferred from semantics and sibling docs, not recovered symbols.
- `LString`/format helper exact source spelling is not final; docs should preserve the binary behavior rather than overclaim exact helper API.
- `OpenBinkVideo` source access level and exact class declaration spelling are not final; helper remains physically owned by VideoPlayerPane even though current direct callers are LogoPlayerPane methods.
- Direct construction site remains absent after active scans. This is evidence for retained/unused or metadata-gap code, not evidence against reconstructing the constructor itself.

## Validator Needs

Report-only task: no validator was run because no target/support by-* docs were edited.

If accepted for implementation, run from `source-3/project-documentation` with `--apply --queue-timeout 240` for every touched doc. Expected minimum if the recommended implementation edits are applied:

> Executable block R001 was removed from this report and preserved verbatim in [0002PS-LogoPlayerPaneConstructor-source-quality-removed.md](0002PS-LogoPlayerPaneConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If implementation also aligns `AdvanceToNextSegment` names or the `VideoPlayerPane` helper note, additionally run:

> Executable block R002 was removed from this report and preserved verbatim in [0002PS-LogoPlayerPaneConstructor-source-quality-removed.md](0002PS-LogoPlayerPaneConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Exact Pending Coverage Replacement Row

Do not edit `by-memory/-coverage-report.md` in this B-agent pass. Pending replacement row:

```text
      - [UID:0002PS][0x004f53b0-0x004f5500.LogoPlayerPaneConstructor](by-memory/0x004f53b0-0x004f5500.LogoPlayerPaneConstructor.md) 0x004f53b0-0x004f5500 | constructor | LogoPlayerPaneConstructor : reconstructable : 88% : very strong : Local PE/Capstone and prior IDA evidence confirm exact constructor bounds, VideoPlayerPane base construction, three LogoPlayerPane vtable installs, embedded AUTOBUF movie payload buffer at +0x100/+0x104/+0x108, FunctionObject0 completion callback store at +0x10c, one-shot segment-advance guard clear at +0x110, StdioFile open/read of caller-supplied movie path, first-segment size store at +0x114, memory-backed OpenBinkVideo call at 0x004f5476, formatted FileError(L"%s corrupted") throw on first-segment open failure, and first-draft constructor C++ eligibility; direct startup-flow/rel32/VA/RVA scans still find no construction site, so treat the class path as retained/unused or metadata-gap startup movie pane code rather than an active ApplicationStartup instantiation.
```

## Implementation Readiness

Ready for supervisor implementation callback.

Suggested implementation scope:

- Target doc: required.
- Support docs: `by-class/LogoPlayerPane.md`, `by-memory/0x004f53b0-0x004f570c.LogoPlayerPane.md`, and `by-file/StartupLogoPanes.md` if their stale blocker/caller language remains.
- Optional support alignment: `LogoPlayerPaneAdvanceToNextSegment` and `VideoPlayerPane` helper notes if exact naming/helper exposure is being standardized in the same callback.

No target/support docs or coverage docs were edited by this report.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0002PS-LogoPlayerPaneConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:30","uid":"0002PS"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002PS-LogoPlayerPaneConstructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0002PS-LogoPlayerPaneConstructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002PS"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
