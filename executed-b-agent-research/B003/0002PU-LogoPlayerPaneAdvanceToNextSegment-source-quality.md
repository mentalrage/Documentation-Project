** TARGET-REPORT-UID:0002PU **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002PU LogoPlayerPaneAdvanceToNextSegment Source-Quality Report

Agent: Agent-B003  
Assignment: B-preferred source-quality / heuristic research  
Target: [UID:0002PU] `source-3/project-documentation/by-memory/0x004f5570-0x004f55c8.LogoPlayerPaneAdvanceToNextSegment.md`  
Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/0002PU-LogoPlayerPaneAdvanceToNextSegment-source-quality.md`

## Finalized Report / Current Recommendation

Current recommendation: keep [UID:0002PU] as a source-authored `LogoPlayerPane` member method and populate first-draft target C++ on the implementation callback.

Recommended target metadata:

```text
COMPLETION:87
CONFIDENCE:92
CANONICAL_OWNER:00007H
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00007H
```

Source route:

```text
0002PU -> 00007H LogoPlayerPane -> 0000O4 StartupLogoPanes -> auto-generated/NexusTK/app/StartupLogoPanes.cpp
```

Best source-facing method name/signature:

```cpp
void LogoPlayerPane::AdvanceToNextSegment();
```

`SkipToNextSegment` is a plausible descriptive alias because both direct callers are key/mouse skip handlers, but `AdvanceToNextSegment` is the better report/documentation name: the body owns the segment transition and playback restart, while input handlers own the user-skip policy.

The target is eligible for first-draft C++: it is `RECONSTRUCTABLE:TRUE`, has a nonblank emitter chain to a valid source root, the current `(84 + 90) / 2 = 87` clears the active code gate, and the fresh local evidence resolves the prior blockers enough for source-quality draft code.

## Evidence Checked

Instruction sources:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B003/goal.md`
- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/inference_research.md`

Target/support docs:

- [UID:0002PU] `LogoPlayerPaneAdvanceToNextSegment`
- [UID:0002PV] `LogoPlayerPaneInputSkipHandlers`
- [UID:00019D] `LogoPlayerPane`
- [UID:00007H] `LogoPlayerPane`
- [UID:0000O4] `StartupLogoPanes`
- [UID:0002PS] `LogoPlayerPaneConstructor`
- [UID:0002PW] `LogoPlayerPaneOnClose`
- [UID:0003OR] `LogoPlayerPaneVtableData`
- [UID:0001NT] `VideoPlayerPane`
- [UID:0000FV] `VideoPlayerPane`
- [UID:0000P4] `VideoPlayerPane`
- [UID:0002Z5] `VideoPlayerPaneVtableData`
- [UID:0001RN] `startup-logo-media`
- [UID:0001WN] `AUTOBUF<unsigned char>`
- [UID:00019E] `AUTOBUFUnsignedCharConstructor`
- [UID:0001QE] `client_libraries`
- [UID:00029G] `StartupLogoBinkPlaybackGlobals`
- [UID:00022U] `StartupLogoBinkMidpointRestart`
- [UID:0003K6] `PlayStartupLogoBinkFile`

Generated/coverage inputs:

- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-class-coverage.md`
- `auto-generated/-ag-file-coverage.md`
- `auto-generated/NexusTK/app/StartupLogoPanes.cpp`
- `auto-generated/NexusTK/ui/core/VideoPlayerPane.cpp`
- `project-level/-auto-completion-stats.md`
- `by-memory/-coverage-report.md` as read-only input only

Prior executed reports:

- `Agent-B001/research/executed/0002PV-logoplayer-input-skip-handlers-source-quality.md`
- `Agent-B003/research/executed/0002PW-LogoPlayerPaneOnClose-source-quality.md`

IDA MCP status:

- `http://127.0.0.1:13337/mcp` was checked and returned `Unable to connect to the remote server`.
- Fresh validation in this report uses local PE section mapping, raw bytes, Capstone disassembly, direct rel32 call scans, VA dword pointer scans, and `int_convert.py`.

Local binary:

```text
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
```

## Local PE / Capstone Facts

Section map from the local executable:

```text
image_base 0x00400000
.text  0x00401000-0x0060c4ac raw=0x400    rsize=0x20b600
.rdata 0x0060d000-0x0066c0be raw=0x20ba00 rsize=0x5f200
.data  0x0066d000-0x0069ce24 raw=0x26ac00 rsize=0xd800
.rsrc  0x0069d000-0x006b2c38 raw=0x278400 rsize=0x15e00
```

Target range:

```text
0x004f5570-0x004f55c8
size 0x58 / 88 bytes (Verified with int_convert.py)
```

Disassembly summary:

```text
0x004f5573  cmp byte ptr [esi+0x110], 0
0x004f557a  jne 0x004f55c6
0x004f557c  mov eax, [esi+0xfc]
0x004f5582  cmp dword ptr [eax+0x0c], 0x64
0x004f5586  jae 0x004f55c6
0x004f5588  mov ecx, [esi+0x108]
0x004f558e  mov eax, [esi+0x114]
0x004f5594  sub ecx, eax
0x004f5596  mov edx, [esi+0x104]
0x004f559c  sub ecx, 4
0x004f559f  add edx, 4
0x004f55a2  mov byte ptr [esi+0x110], 1
0x004f55a9  push ecx
0x004f55aa  add eax, edx
0x004f55ae  push eax
0x004f55af  call 0x005c0110
0x004f55b4  mov ecx, esi
0x004f55b6  test al, al
0x004f55bb  jmp 0x00544690
0x004f55c3  jmp dword ptr [eax+0x48]
0x004f55c7  ret
```

Direct rel32 references:

| Target | Direct refs found |
|---|---|
| `0x004f5570` | calls from `0x004f55f1` and `0x004f5612` only |
| `0x005c0110` | calls from `0x004f5476` and `0x004f55af` only |
| `0x005c01f0` | no direct rel32 calls; vtable-only through slot `+0x48` |
| `0x00544690` | many shared pane deletion callers; target uses tail-jump at `0x004f55bb` |

Relevant vtable pointer facts:

- `0x0061d060`, `LogoPlayerPane` primary slot `+0x48`, points to `0x005c01f0`.
- `0x00631094`, `VideoPlayerPane` primary slot `+0x48`, also points to `0x005c01f0`.
- `0x005c01f0-0x005c0206` sets `this+0xf5 = 1`, `this+0xf8 = 1`, then calls virtual slot `+0x20` with argument `0`. This is the inherited `VideoPlayerPane::StartPlayback()` path.
- `0x0061d068`, `LogoPlayerPane` primary slot `+0x50`, points to [UID:0002PW] `LogoPlayerPane::OnClose`.
- `0x0061d074` and `0x0061d078` point to [UID:0002PV] mouse/key handlers.

`int_convert.py` conversions used:

- `0x58 = 88`
- `0x64 = 100`
- `0xfc = 252`
- `0x100 = 256`
- `0x104 = 260`
- `0x108 = 264`
- `0x10c = 268`
- `0x110 = 272`
- `0x114 = 276`
- `0x0c = 12`
- `0x48 = 72`
- `0x04080000 = 67633152`
- `0xa0 = 160`
- `0x2c = 44`
- `0x1d = 29`
- `0x14 = 20`
- `0x150 = 336`
- `0x2a = 42`

## Behavior And Source Contract

`LogoPlayerPane::AdvanceToNextSegment()` is a one-shot early segment-advance method for the startup movie pane.

Control flow:

1. Return immediately if the guard byte at `LogoPlayerPane +0x110` is already set.
2. Read the inherited Bink handle at `VideoPlayerPane +0xfc`.
3. Return if the Bink current-frame/progress field at `BINK +0x0c` is at least `0x64` / 100 frames (Verified with int_convert.py).
4. Compute the remaining second-segment byte count:
   `AUTOBUF.count - firstSegmentSize - 4`.
5. Compute the second segment pointer:
   `AUTOBUF.data + 4 + firstSegmentSize`.
6. Set the guard byte before trying to open the second segment.
7. Call `VideoPlayerPane::OpenBinkVideo(secondSegmentData, remainingByteCount)`.
8. If open fails, tail-jump to `Pane::MarkForDeletion()`.
9. If open succeeds, tail-jump through primary vtable slot `+0x48`, which is inherited `VideoPlayerPane::StartPlayback()`.

The guard write order matters. A failed open still leaves the guard set, so repeated key/mouse input will not repeatedly reopen or fail the second segment.

## Source-Quality Names And Signatures

Recommended target method:

```cpp
void LogoPlayerPane::AdvanceToNextSegment();
```

Rejected method alternatives:

- `SkipToNextSegment`: descriptive for the caller policy, but the body is the segment transition and playback restart. Keep "skip" language on [UID:0002PV].
- `OpenNextSegment`: too narrow because the method also checks the guard/current frame, marks failed panes for deletion, and restarts playback on success.
- `AdvanceStartupLogoVideo`: too file-level and less class-local than needed.

Recommended `LogoPlayerPane` fields:

| Offset | Preferred name | Evidence and notes |
|---:|---|---|
| `+0x100` | `m_movieData` / `m_segmentData` | Embedded `_AUTOBUF<unsigned char>` object. Prefer `m_movieData` in C++ because this pane reads a caller-supplied startup movie payload, not generic file data. |
| `+0x104` | `m_movieData.m_data` | AUTOBUF data pointer. Constructor file read fills it; this target uses it as the base for memory-backed Bink segment pointers. |
| `+0x108` | `m_movieData.m_count` | AUTOBUF loaded byte count. In this target it behaves as total payload byte count, not merely capacity. |
| `+0x10c` | `m_completionCallback` | Already resolved by [UID:0002PW] as non-null `FunctionObject0*`-family callback. |
| `+0x110` | `m_hasRequestedSegmentAdvance` | One-shot guard. Preferred over `m_hasAdvancedToNextSegment` because it is set before `OpenBinkVideo`; failed opens still consume the attempt. |
| `+0x114` | `m_firstSegmentSize` | First dword from the startup Bink payload; constructor stores it and this target uses it to find the second segment. |

Recommended inherited/base fields:

| Offset | Preferred name | Evidence and notes |
|---:|---|---|
| `VideoPlayerPane +0xfc` | `m_binkHandle` | Written by `VideoPlayerPane::OpenBinkVideo`; read by idle, stop, destructor, and this target. |
| `BINK +0x0c` | `FrameNum` / current frame number | This target compares it against 100. [UID:00022U] compares the same field against half of `BINK +0x08`, and [UID:0001NT] compares it against `BINK +0x08` before posting `VisD`. Treat SDK spelling as high-probability/descriptive unless a local Bink header is later obtained. |
| `BINK +0x08` | `Frames` / total frame count | Proven by [UID:00022U] and `VideoPlayerPane::OnIdle` comparisons. |

Recommended helper signatures:

```cpp
bool VideoPlayerPane::OpenBinkVideo(const void* segmentData, unsigned int segmentSize);
void VideoPlayerPane::StartPlayback();
void Pane::MarkForDeletion();
```

`OpenBinkVideo`'s second argument remains source-visible even though the recovered helper body does not consume `[ebp+0x0c]`. Both known callers pass a size: the constructor passes the first segment size, and this target passes the remaining byte count. Do not delete the parameter from source docs just because the optimized/recovered body ignores it.

## OpenBinkVideo Ownership

Recommendation: treat `0x005c0110-0x005c0174` as a protected `VideoPlayerPane` helper, with a caller caveat that current direct callers are both `LogoPlayerPane`.

Evidence for `VideoPlayerPane` ownership:

- Physical locality: `0x005c0110` sits inside the `0x005c0040-0x005c045b` `VideoPlayerPane` method/helper island.
- Object state: the helper reads and writes `this+0xfc`, the inherited Bink handle field documented by [UID:0001NT].
- Behavior: it configures Bink DirectSound, closes any previous Bink handle, registers the app `term` notification, and calls `BinkOpen(segmentData, 0x04080000)`.
- Vtable/source context: the success tail after this target calls inherited `StartPlayback()` at `VideoPlayerPane` slot `+0x48`; open/start/stop/idle/message/teardown are a coherent base-video lifecycle.
- Support docs: [UID:0001NT], [UID:0000FV], [UID:0000P4], [UID:0002Z5], and [UID:0001QE] already model the Bink playback helper family as reusable video-pane glue.

Evidence for the rejected `LogoPlayerPane` ownership alternative:

- Only direct callers are `LogoPlayerPane` constructor `0x004f5476` and this target `0x004f55af`.
- Both callers pass pointers into the `LogoPlayerPane` AUTOBUF segmented startup movie payload.

Decision:

- Caller set proves `LogoPlayerPane` use, not source ownership.
- Physical locality, state fields, Bink lifecycle, and surrounding helpers are stronger ownership signals.
- Update docs to make this an affirmative decision instead of a passive blocker: `LogoPlayerPane` owns segment selection and skip policy; `VideoPlayerPane` owns opening a memory-backed Bink stream and base playback state.

## Caller Route From Input Handlers

[UID:0002PV] is the complete direct caller set for this target:

- `LogoPlayerPane::OnKeyEvent` calls at `0x004f55f1`.
- `LogoPlayerPane::OnMouseEvent` calls at `0x004f5612`.

The executed [UID:0002PV] B001 report and local recheck agree:

- Key handler range `0x004f55d0-0x004f55fc` is `0x2c` / 44 bytes (Verified with int_convert.py).
- Mouse handler range `0x004f5600-0x004f561d` is `0x1d` / 29 bytes (Verified with int_convert.py).
- Both are vtable-only handlers reached through the `LogoPlayerPane` secondary/event view at `+0xa0`.
- Both adjust `this` by `-0xa0` before calling this target, restoring the primary `LogoPlayerPane*`.
- Key type `8` is key-down and accepts Enter, Escape, and Space.
- Mouse type `3` is left-button release/up.
- Both handlers return handled even when no advance occurs.

Support-doc direction: keep the event policy in [UID:0002PV], but update it to say the callee now has a first-draft implementation and final source-facing name `AdvanceToNextSegment`.

## Failure And Success Routes

Failure route:

```text
0x004f55b6 test al, al
0x004f55b8 jne 0x004f55c0
0x004f55bb jmp 0x00544690
```

The code reloads `ecx = this` before testing the result, so the tail-jump is an inherited `Pane::MarkForDeletion()` call. This is the same helper used by [UID:0002PW] `LogoPlayerPane::OnClose`, but here it is the failed second-segment open path.

Success route:

```text
0x004f55c0 mov eax, [esi]
0x004f55c3 jmp dword ptr [eax+0x48]
```

The `LogoPlayerPane` primary vtable slot `+0x48` points to `0x005c01f0`, inherited `VideoPlayerPane::StartPlayback()`. The matching `VideoPlayerPane` primary vtable slot `+0x48` also points to `0x005c01f0`. This is not an unknown playback virtual anymore.

## Segmented Startup-Logo Media Contract

The target follows the same segmented payload contract documented in [UID:0001RN]:

```text
payload[0..3]                     -> first segment byte size
payload + 4                       -> first Bink segment
payload + 4 + firstSegmentSize    -> second Bink segment
payloadByteCount - firstSize - 4  -> remaining second-segment byte count
```

The constructor [UID:0002PS] reads the caller-supplied movie file into `m_movieData`, reads the first dword into `m_firstSegmentSize`, and opens `m_movieData.m_data + 4`.

This target is the paired early user-skip path. It opens `m_movieData.m_data + 4 + m_firstSegmentSize`, passes the remaining byte count, and starts playback from that segment.

The standalone startup-logo Bink path [UID:0003K6]/[UID:00022U] uses `LOGO.PAK` / `LOGO.PAD` and a global Bink handle, but the payload shape is the same. The pane path is caller-supplied and object-owned; the standalone path is file-local and global-state based.

## First-Draft C++ Recommendation

Populate [UID:0002PU]'s formal `RECONSTRUCTION_CPP CODE` block on implementation callback with this first draft:

```cpp
void LogoPlayerPane::AdvanceToNextSegment()
{
    if (m_hasRequestedSegmentAdvance)
        return;

    if (m_binkHandle->FrameNum >= 100)
        return;

    const unsigned int firstSegmentSize = m_firstSegmentSize;
    unsigned char* const nextSegmentData =
        m_movieData.m_data + sizeof(unsigned int) + firstSegmentSize;
    const unsigned int nextSegmentSize =
        m_movieData.m_count - firstSegmentSize - sizeof(unsigned int);

    m_hasRequestedSegmentAdvance = true;

    if (!OpenBinkVideo(nextSegmentData, nextSegmentSize)) {
        MarkForDeletion();
        return;
    }

    StartPlayback();
}
```

Draft notes:

- No null check is added for `m_binkHandle`; the raw body dereferences `this+0xfc` unconditionally.
- The guard is set before `OpenBinkVideo`, matching raw behavior.
- `sizeof(unsigned int)` is equivalent to the raw `4` and expresses the first payload dword contract.
- `OpenBinkVideo` is intentionally called as an inherited protected `VideoPlayerPane` helper.
- `StartPlayback()` is the resolved source-facing name for vtable slot `+0x48`.
- If the implementation callback standard prefers literal decompiler constants, replace `sizeof(unsigned int)` with `4` but keep the same arithmetic order.

## Heuristic / Inference Reanalysis And Validation

Issue: source-facing method name.

- Candidates: `AdvanceToNextSegment`, `SkipToNextSegment`, `OpenNextSegment`.
- Evidence: direct callers are skip input handlers; body performs transition, open, failure delete, and playback start.
- Decision: use `AdvanceToNextSegment` for the method and "skip" for caller policy.
- Impact: no C++ blocker remains.

Issue: guard field at `+0x110`.

- Candidates: `m_hasAdvancedToNextSegment`, `m_skipRequested`, `m_hasRequestedSegmentAdvance`.
- Evidence: constructor clears it; target checks it first; target sets it before open; failure still sets it.
- Decision: prefer `m_hasRequestedSegmentAdvance`.
- Rejected: `m_hasAdvancedToNextSegment` is slightly misleading on open failure.
- Impact: closes target field-name blocker.

Issue: first-segment-size field at `+0x114`.

- Candidates: `m_firstSegmentSize`, `m_firstBinkSegmentSize`, `m_segmentSize`.
- Evidence: constructor reads first payload dword and stores at `+0x114`; target adds it to payload base and subtracts it from count.
- Decision: `m_firstSegmentSize`; the class/media docs can spell out that it is a Bink segment size.
- Impact: closes target field-name blocker.

Issue: AUTOBUF fields at `+0x104/+0x108`.

- Candidates: raw pointer/count, start/end, capacity.
- Evidence: AUTOBUF constructor and type docs identify fields `+0x04/+0x08`; constructor file-read fills them; target uses `+0x108` as total loaded byte count and `+0x104` as loaded payload base.
- Decision: document as `m_movieData.m_data` and `m_movieData.m_count`.
- Rejected: treating `+0x108` only as capacity is weaker for this target because the arithmetic uses actual payload extent.
- Impact: closes target field-name blocker.

Issue: progress field.

- Candidates: percent progress, elapsed frame count, Bink current frame.
- Evidence: target compares `BINK +0x0c` against 100; `VideoPlayerPane::OnIdle` compares `BINK +0x0c` against `BINK +0x08`; [UID:00022U] compares `BINK +0x0c` against half of `BINK +0x08`.
- Decision: `BINK +0x0c` is current frame number / `FrameNum`; `BINK +0x08` is total frame count / `Frames`.
- Rejected: percent progress, because comparisons against total frames and half total frames prove frame-index semantics.
- Impact: closes progress-field blocker enough for C++.

Issue: playback virtual slot `+0x48`.

- Candidates: unknown playback virtual, `StartPlayback`, base pane refresh.
- Evidence: `LogoPlayerPane` primary slot `+0x48` and `VideoPlayerPane` primary slot `+0x48` both point to `0x005c01f0`; that body sets active/playback bytes and calls refresh slot `+0x20`.
- Decision: call it `VideoPlayerPane::StartPlayback()`.
- Rejected: generic pane refresh, because refresh is the nested `+0x20` call inside `StartPlayback`.
- Impact: closes final-C++ blocker.

Issue: `OpenBinkVideo` ownership.

- Candidates: `LogoPlayerPane` local startup helper, protected `VideoPlayerPane` helper, free file-local startup helper.
- Evidence: only Logo callers, but helper is inside VideoPlayerPane island and uses base Bink handle/lifecycle state.
- Decision: protected `VideoPlayerPane::OpenBinkVideo(const void*, unsigned int)`.
- Rejected: free startup helper, because it is `thiscall` and mutates `this+0xfc`; `LogoPlayerPane` member, because source locality and state are base-video.
- Impact: close ownership blocker. Target C++ can call inherited helper.

Issue: no-code versus first-draft C++.

- Evidence: target is one exact source-authored method, not an aggregate; it has exact callers, exact callees, exact fields, and valid emitter route.
- Decision: first-draft C++ should be populated.
- Rejected: no-code policy. The prior blockers are now source-quality naming issues, not target-specific no-code proof.

## Recommended Target Doc Changes

Metadata:

```text
COMPLETION:87
CONFIDENCE:92
```

Replace the current open-question/no-code wording with:

```text
First-draft C++ is now ready. The previous blockers are resolved as source-quality names: the method is `LogoPlayerPane::AdvanceToNextSegment()`, `+0x110` is the one-shot `m_hasRequestedSegmentAdvance` guard, `+0x114` is `m_firstSegmentSize`, `+0x104/+0x108` are `m_movieData.m_data/m_count`, the progress read is inherited `m_binkHandle->FrameNum`, slot `+0x48` is inherited `VideoPlayerPane::StartPlayback()`, and `0x005c0110` is a protected `VideoPlayerPane::OpenBinkVideo(const void*, unsigned int)` helper used by LogoPlayerPane.
```

Add or replace source-facing field table:

```text
| Offset / Target | Recommended source name | Meaning |
| --- | --- | --- |
| `VideoPlayerPane +0xfc` | `m_binkHandle` | Current Bink stream handle inherited from `VideoPlayerPane`. |
| `BINK +0x0c` | `FrameNum` | Current frame number/progress; this method only advances before frame 100. |
| `LogoPlayerPane +0x104` | `m_movieData.m_data` | Loaded segmented startup movie payload pointer. |
| `LogoPlayerPane +0x108` | `m_movieData.m_count` | Loaded payload byte count. |
| `LogoPlayerPane +0x110` | `m_hasRequestedSegmentAdvance` | One-shot user segment-advance guard, set before the open attempt. |
| `LogoPlayerPane +0x114` | `m_firstSegmentSize` | First dword of the payload, used to locate the second Bink segment. |
| primary vtable `+0x48` | `StartPlayback()` | Inherited `VideoPlayerPane` playback-start virtual at `0x005c01f0`. |
| `0x005c0110` | `VideoPlayerPane::OpenBinkVideo(const void*, unsigned int)` | Protected memory-backed Bink open helper. |
```

Insert the first-draft C++ from this report into the target `RECONSTRUCTION_CPP CODE` block if the supervisor accepts this report.

## Recommended Support-Doc Updates

[UID:00007H] `LogoPlayerPane`:

- Update the method row for `0x004f5570-0x004f55c8` to state `void LogoPlayerPane::AdvanceToNextSegment()`.
- Update data notes with `m_movieData`, `m_completionCallback`, `m_hasRequestedSegmentAdvance`, and `m_firstSegmentSize`.
- Replace "OpenBinkVideo exposure unresolved" with "OpenBinkVideo is caller-sensitive but best owned as protected VideoPlayerPane helper; LogoPlayerPane owns the segment-selection policy."
- Recommended score direction after incorporation: `86/88 -> 87/89`.

[UID:0000O4] `StartupLogoPanes`:

- Keep `LogoPlayerPane` under `StartupLogoPanes.cpp`.
- Add that [UID:0002PU] is first-draft C++ ready and that the startup movie object path uses a caller-supplied segmented payload with the same first-dword contract as `LOGO.PAK`/`LOGO.PAD`.
- Keep the two-file split caveat for static logo versus video, but do not let `OpenBinkVideo` block this target.
- Recommended score direction after incorporation: `88/85 -> 88/86`.

[UID:00019D] `LogoPlayerPane` aggregate:

- Update the [UID:0002PU] covered-range row with the resolved field/helper names and first-draft C++ readiness.
- Keep the parent aggregate C++ blank or marker-only; children carry source bodies.
- Recommended score direction: `84/90 -> 85/91`.

[UID:0002PV] input handlers:

- Keep score `87/90`.
- Update final-C++ coordination to say the callee name and body are now resolved as `AdvanceToNextSegment()`.
- Keep formal C++ blank until event type declarations or an exact split are accepted.

[UID:0001NT] `VideoPlayerPane` memory:

- Update `0x005c0110` from ambiguous "possible open helper" to source-facing `VideoPlayerPane::OpenBinkVideo(const void* segmentData, unsigned int segmentSize)`.
- Document the second argument as caller-passed but unused in recovered body.
- Update `+0xfc` as `m_binkHandle`, `BINK +0x08` as total frames, and `BINK +0x0c` as current frame number.
- Recommended score direction: `86/90 -> 87/91`.

[UID:0000FV] and [UID:0000P4] `VideoPlayerPane` class/file:

- Replace passive `OpenBinkVideo` ownership caveat with affirmative protected-base-helper direction.
- Keep final C++ blank for the class/file until raw no-xref helpers and broader field names are settled.
- Recommended score direction: class `87/86 -> 88/88`; file `86/86 -> 87/88` if the support sync is accepted.

[UID:0001RN] startup-logo-media:

- Add the object-pane path's resolved names: `m_movieData`, `m_firstSegmentSize`, and `m_hasRequestedSegmentAdvance`.
- Document that `LogoPlayerPane` uses a fixed current-frame cutoff of 100 for user-requested segment advance, while the standalone startup-logo WndProc helper uses a half-total-frame cutoff.
- Score can remain `87/94`; the remaining resource-payload provenance blocker is outside this target.

[UID:0001QE] client_libraries:

- Update the Bink open question: helper ownership best direction is protected `VideoPlayerPane`; the remaining open issue is exact original spelling/header exposure and why the size argument was retained unused.

## Implementation Readiness

Ready for implementation callback:

- Target first-draft C++: yes.
- Target split/rename needed: no.
- Owner/emitter change needed: no.
- Support doc edits needed: yes, as listed above.
- Coverage report direct edit by B003: banned; exact replacement rows are below.

Remaining nonblocking questions:

- Exact original source spelling of `m_hasRequestedSegmentAdvance`, `m_movieData`, and `OpenBinkVideo` is not symbol-proven.
- No local Bink SDK header was found; `FrameNum`/`Frames` are high-probability SDK-compatible descriptive field names from code behavior.
- `OpenBinkVideo`'s second parameter is passed by both callers but unused in recovered code; retain it in the signature until original source/header evidence proves otherwise.
- The `LogoPlayerPane` constructor direct normal caller remains unrecovered, but that does not affect this target's method body.

## Exact Pending Coverage Text

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` directly. If accepted, replace the current [UID:00019D] row with:

```text
    - [UID:00019D][0x004f53b0-0x004f570c.LogoPlayerPane](by-memory/0x004f53b0-0x004f570c.LogoPlayerPane.md) 0x004f53b0-0x004f570c | class island | LogoPlayerPane : reconstructable : 85% : very strong : B003 2026-06-19 source-quality reanalysis keeps the aggregate routed through [UID:00007H][LogoPlayerPane] to [UID:0000O4][StartupLogoPanes.cpp] while resolving the segment-advance blocker: local PE/Capstone confirms exact `0x004f5570-0x004f55c8` 0x58 / 88-byte target bounds (Verified with int_convert.py), exact input-handler callers `0x004f55f1` and `0x004f5612`, `m_movieData.m_data/m_count` at `+0x104/+0x108`, `m_hasRequestedSegmentAdvance` at `+0x110`, `m_firstSegmentSize` at `+0x114`, inherited `m_binkHandle` at `+0xfc`, Bink current-frame field `+0x0c`, protected `VideoPlayerPane::OpenBinkVideo` call at `0x004f55af`, failure tail-jump to `Pane::MarkForDeletion`, success tail-jump through primary slot `+0x48` to `VideoPlayerPane::StartPlayback`, and first-draft C++ readiness for [UID:0002PU]. Aggregate C++ remains blank or marker-only because exact children own source bodies and compiler/template support remains split.
```

Replace the current [UID:0002PU] row with:

```text
        - [UID:0002PU][0x004f5570-0x004f55c8.LogoPlayerPaneAdvanceToNextSegment](by-memory/0x004f5570-0x004f55c8.LogoPlayerPaneAdvanceToNextSegment.md) 0x004f5570-0x004f55c8 | method | LogoPlayerPaneAdvanceToNextSegment : reconstructable : 87% : very strong : B003 2026-06-19 source-quality reanalysis keeps owner/emitter [UID:00007H][LogoPlayerPane] and makes first-draft C++ ready: local PE/Capstone confirms exact 0x58 / 88-byte body (Verified with int_convert.py), guard check/write at `+0x110` as `m_hasRequestedSegmentAdvance`, inherited Bink handle `+0xfc` and current-frame/progress field `BINK+0x0c` checked against 0x64 / 100 (Verified with int_convert.py), AUTOBUF payload pointer/count at `+0x104/+0x108`, first-segment size at `+0x114`, second-segment pointer `m_movieData.m_data + 4 + m_firstSegmentSize`, remaining byte count `m_movieData.m_count - m_firstSegmentSize - 4`, guard write before open, protected `VideoPlayerPane::OpenBinkVideo(const void*, unsigned int)` call at `0x004f55af`, failure tail-jump to `Pane::MarkForDeletion` at `0x004f55bb`, success tail-jump through primary vtable slot `+0x48` to inherited `VideoPlayerPane::StartPlayback`, exact direct callers from [UID:0002PV] key/mouse handlers at `0x004f55f1` and `0x004f5612`, and segmented startup-logo media contract alignment with [UID:0001RN].
```

Optional [UID:0002PV] text-sync replacement row, with unchanged score:

```text
        - [UID:0002PV][0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers](by-memory/0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers.md) 0x004f55d0-0x004f561d | vtable method pair | LogoPlayerPaneInputSkipHandlers : reconstructable : 87% : strong : B001 2026-06-17 source-quality reanalysis keeps owner/emitter [UID:00007H][LogoPlayerPane](by-class/LogoPlayerPane.md) and models the range as the source-authored `OnKeyEvent`/`OnMouseEvent` virtual pair reached through the Pane/EventHandler secondary view at +0xa0; live/local evidence confirms exact key handler `0x004f55d0-0x004f55fc`, internal `0xcc` padding `0x004f55fc-0x004f5600`, mouse handler `0x004f5600-0x004f561d`, vtable-only xrefs `0x0061d078` and `0x0061d074`, no direct code callers, EventMan type `8` as key-down with translated key byte +0x08 matching Enter/Escape/Space (`0x0d/0x1b/0x20`, verified with int_convert.py), EventMan type `3` as left-button release, `this-0xa0` normalization before both calls to now-resolved `LogoPlayerPane::AdvanceToNextSegment`, always-handled returns even for nontriggering events, and LogoPlayerPane/StartupLogoPanes ownership over VideoPlayerPane/Pane/Event alternatives. Formal C++ remains blank pending coordinated EventHandler/KeyEvent/MouseEvent declaration names or a future exact split.
```

Optional [UID:0001NT] support replacement row if the VideoPlayerPane support sync is accepted:

```text
    - [UID:0001NT][0x005c0040-0x005c045b.VideoPlayerPane](by-memory/0x005c0040-0x005c045b.VideoPlayerPane.md) 0x005c0040-0x005c045b | class method aggregate | VideoPlayerPane : reconstructable : 87% : very strong : B003 2026-06-19 support sync resolves the `0x005c0110` helper direction as protected `VideoPlayerPane::OpenBinkVideo(const void* segmentData, unsigned int segmentSize)` despite LogoPlayerPane-only direct callers: local PE/Capstone confirms `0x005c0110-0x005c0174` gets DirectSound through `g_pSoundManager`, calls `BinkSetSoundSystem(BinkOpenDirectSound, ...)`, closes prior `m_binkHandle` at `+0xfc`, registers `term`, opens memory-backed Bink with flags `0x04080000` / 67633152 (Verified with int_convert.py), stores the handle back to `+0xfc`, and returns success; `LogoPlayerPaneAdvanceToNextSegment` now proves success slot `+0x48` is inherited `VideoPlayerPane::StartPlayback` at `0x005c01f0`, while `VideoPlayerPane::OnIdle` and startup midpoint helper comparisons support BINK `+0x08` total frames and `+0x0c` current frame. Final aggregate C++ remains blank pending raw no-xref helper policy, exact Bink header/member spellings, and broader VideoPlayerPane class declaration work.
```

## Validator Commands Needed On Implementation Callback

Run after accepted by-* edits:

_Executable command block removed from the research report; preserved in [0002PU-LogoPlayerPaneAdvanceToNextSegment-source-quality-removed.md](0002PU-LogoPlayerPaneAdvanceToNextSegment-source-quality-removed.md)._

If first-draft C++ is inserted, also run:

_Executable command block removed from the research report; preserved in [0002PU-LogoPlayerPaneAdvanceToNextSegment-source-quality-removed.md](0002PU-LogoPlayerPaneAdvanceToNextSegment-source-quality-removed.md)._

No validators were run for this report-only pass.

## Changed Files

Created only:

```text
source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/0002PU-LogoPlayerPaneAdvanceToNextSegment-source-quality.md
```

No target by-memory doc, support by-* doc, generated output, project-level report, previous B003 report, or `by-memory/-coverage-report.md` was edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002PU-LogoPlayerPaneAdvanceToNextSegment-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:28","uid":"0002PU"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002PU-LogoPlayerPaneAdvanceToNextSegment-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0002PU-LogoPlayerPaneAdvanceToNextSegment-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002PU"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
