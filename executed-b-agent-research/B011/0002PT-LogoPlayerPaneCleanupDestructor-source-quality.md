** TARGET-REPORT-UID:0002PT **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002PT LogoPlayerPaneCleanupDestructor Source-Quality Report

Date: 2026-06-19  
Agent: B011  
Target: `source-3/project-documentation/by-memory/0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor.md`  
Assignment type: B-preferred report-only source-quality / heuristic research  
Status: ready for supervisor review; no target/support docs edited

## Finalized Report / Current Recommendation

Current recommendation: keep [UID:0002PT] as source-bearing ordinary destructor output for `LogoPlayerPane::~LogoPlayerPane()`. It is not a no-code scalar deleting destructor and should not remain blocked only because IDA does not promote the exact body as a function.

Final disposition:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `84` | `88` |
| `CONFIDENCE` | `90` | `91` |
| `CANONICAL_OWNER` | `00007H` | `00007H` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `EMITTER_UIDS` | `00007H` | `00007H` |
| Formal C++ | blank | populate first-draft destructor body |

Recommended formal C++:

```cpp
LogoPlayerPane::~LogoPlayerPane()
{
    delete m_completionCallback;
}
```

The compiler lowering around that source body accounts for the binary vtable restores, embedded `_AUTOBUF<unsigned char>` member destructor, `LObject` teardown, and `VideoPlayerPane` base destructor tail-call. Those lowering artifacts should be documented as evidence, not hand-written in this page's C++.

Confidence: very strong for target-local behavior and source/no-code factoring. The remaining uncertainty is the exact original spelling of the completion callback member and concrete callback binding, not the destructor source shape.

## Target

- Target UID: `0002PT`
- Target path: `by-memory/0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor.md`
- Current score and route: `84/90`, `CANONICAL_OWNER:00007H`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007H`
- Source route: [UID:00007H] `LogoPlayerPane` -> [UID:0000O4] `StartupLogoPanes` -> `NexusTK/app/StartupLogoPanes.cpp`
- Parent aggregate: [UID:00019D] `0x004f53b0-0x004f570c.LogoPlayerPane`

## Supervisor Active Recheck

This was assigned as a report-only B-agent pass. I did not edit the target, support docs, generated reports, generated source, `by-memory/-coverage-report.md`, or IDA state.

No split repair is required for [UID:0002PT]. The target is one coherent destructor-shaped range:

- `0x004f5500-0x004f5510`: leading `0xcc` alignment
- `0x004f5510-0x004f556a`: unpromoted non-deleting `LogoPlayerPane` cleanup/destructor body
- `0x004f556a-0x004f5570`: trailing `0xcc` alignment

The lack of an IDA function object at `0x004f5510` should be treated as an IDA promotion/modeling issue, not a source-quality blocker. Existing IDA evidence and raw PE bytes show a complete body, and the scalar deleting destructor at [UID:0002PY] duplicates the same derived cleanup sequence with only delete-flag wrapping added.

## Evidence Checked

Required workflow and policy docs:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B011/goal.md`
- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/inference_research.md`
- `source-3/project-documentation/by-project-structure/proposed-source-tree.md`

Target and immediate destructor family:

- [UID:0002PT] `LogoPlayerPaneCleanupDestructor`
- [UID:0002PY] `LogoPlayerPaneScalarDeletingDestructor`
- [UID:0002PX] `LogoPlayerPaneDeletingDestructorThunks`
- B009 active report lead: `Agent-B009/research/0002PX-LogoPlayerPaneDeletingDestructorThunks-source-quality.md`
- [UID:00019D] `LogoPlayerPane` aggregate
- [UID:0003OR] `LogoPlayerPaneVtableData`

Class/file/type/resource support:

- [UID:00007H] `LogoPlayerPane`
- [UID:0000O4] `StartupLogoPanes`
- [UID:0000FV], [UID:0000P4], [UID:0001NT] `VideoPlayerPane`
- [UID:0001WN], [UID:00000P], [UID:0000HM] `AUTOBUF<unsigned char>` / `AUTOBUF`
- [UID:00019E] `AUTOBUFUnsignedCharConstructor`
- [UID:0002MR] `AUTOBUFUnsignedCharVtableData`
- [UID:000188] `AUTOBUFUnsignedCharResize`
- [UID:00005L], [UID:0001WQ], [UID:0000JO] `FunctionObject0` / FunctionObjects support
- [UID:0001RN] `startup-logo-media`

Related B-agent reports and source-quality precedents:

- Executed B003 report `0002PW-LogoPlayerPaneOnClose-source-quality.md`
- Executed B001 report `0002PV-logoplayer-input-skip-handlers-source-quality.md`
- Current LogoPane destructor family pages: [UID:0002PM] ordinary cleanup destructor, [UID:0002PQ] deleting thunks, [UID:0002PR] scalar deleting destructor
- B011/B009 DescPane implementation precedent accepted by supervisor/user: ordinary destructor source body belongs to the ordinary destructor page; scalar deleting destructor glue remains formal-C++ blank/no-code.

Generated/report state:

- `by-memory/-coverage-report.md`
- `auto-generated/-ag-memory-coverage.md`
- `project-level/-auto-completion-stats.md`
- `auto-generated/NexusTK/app/StartupLogoPanes.cpp`
- `auto-generated/NexusTK/ui/core/VideoPlayerPane.cpp`

Independent raw PE checks:

- Read-only raw bytes from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Confirmed `.text` and `.rdata` mapping, exact target bytes, alignment bytes, thunk bytes, scalar wrapper bytes, vtable dwords at `0x0061d018`, `0x0061d070`, and `0x0061d0a0`, and absence of direct raw rel32 route to `0x004f5510`.
- My first rel32 scan command produced noisy signed-destination conversion errors; I reran bounded arithmetic for the target/thunk relationship and used only the corrected results.

## Raw PE Facts

Raw byte facts from `NexusTK.exe`:

```text
0x004f5500-0x004f5510:
cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc

0x004f5510-0x004f556a:
56 57 8b f9 8b 8f 0c 01 00 00 c7 07 18 d0 61 00 c7 87 a0 00 00 00 70 d0 61 00 c7 87 a4 00 00 00 a0 d0 61 00 85 c9 74 06 8b 01 6a 01 ff 10 ff b7 04 01 00 00 c7 87 00 01 00 00 68 b8 61 00 e8 46 22 0d 00 83 c4 04 8d 8f 00 01 00 00 e8 2f f5 ff ff 8b cf 5f 5e e9 26 ab 0c 00

0x004f556a-0x004f5570:
cc cc cc cc cc cc
```

The target sequence is a complete non-deleting destructor-shaped body:

- `push esi; push edi; mov edi, ecx`
- load callback pointer from `[edi+0x10c]`
- store vtables `0x0061d018`, `0x0061d070`, `0x0061d0a0` into `+0`, `+0xa0`, `+0xa4`
- if callback is non-null, push deleting flag `1` and call callback vtable slot `+0x00`
- push/free payload pointer from `[edi+0x104]`
- store `_AUTOBUF<unsigned char>` vtable `0x0061b868` into `[edi+0x100]`
- call `0x004f4a90` on `this+0x100`
- tail-jump to `0x005c0090` with `ecx == this`

The scalar wrapper and thunk raw bytes are also exact:

```text
0x004f566a-0x004f5680:
81 e9 a0 00 00 00 e9 0b 00 00 00 81 e9 a4 00 00 00 e9 00 00 00 00

0x004f5680-0x004f570c:
55 8b ec 57 8b f9 8b 8f 0c 01 00 00 c7 07 18 d0 61 00 c7 87 a0 00 00 00 70 d0 61 00 c7 87 a4 00 00 00 a0 d0 61 00 85 c9 74 06 8b 01 6a 01 ff 10 56 ff b7 04 01 00 00 c7 87 00 01 00 00 68 b8 61 00 e8 d3 20 0d 00 83 c4 04 8d 8f 00 01 00 00 e8 bc f3 ff ff 8b cf e8 b5 a9 0c 00 8b 45 08 5e a8 01 74 22 a8 04 75 10 57 e8 d3 f3 ff ff 83 c4 04 8b c7 5f 5d c2 04 00 68 18 01 00 00 57 e8 9e 5f f2 ff 83 c4 08 8b c7 5f 5d c2 04 00
```

Raw vtable dwords:

| Address | Dword | Meaning |
| --- | --- | --- |
| `0x0061d018 +0x00` | `0x004f5680` | Primary `LogoPlayerPane` deleting-destructor slot targets scalar wrapper [UID:0002PY]. |
| `0x0061d070 +0x00` | `0x004f566a` | Secondary view deleting-destructor slot targets first adjustor thunk [UID:0002PX]. |
| `0x0061d0a0 +0x00` | `0x004f5675` | Tertiary view deleting-destructor slot targets second adjustor thunk [UID:0002PX]. |
| `0x0061b868 +0x00` | `0x004e62a0` | `_AUTOBUF<unsigned char>` virtual destructor / first virtual slot. |

Corrected raw route scan:

- No dword pointer or rel32 call/jump route to `0x004f5510` was found in the PE scan.
- Rel32 routes to `0x004f5680` were the two thunk tail jumps at `0x004f5670` and `0x004f567b`.
- The primary source/vtable dispatch route is therefore through [UID:0002PY], while [UID:0002PT] is the complete-object/non-deleting destructor body emitted alongside the wrapper.

## Destructor Family Inventory

| Range / Item | UID / Path | Role | Source policy | Recommended state |
| --- | --- | --- | --- | --- |
| `0x004f5510-0x004f556a` | [UID:0002PT] `LogoPlayerPaneCleanupDestructor` | non-deleting destructor body | Source-bearing ordinary `LogoPlayerPane::~LogoPlayerPane()` body plus compiler lowering | `TRUE`, owner/emitter `00007H`, `88/91`, first-draft C++ |
| `0x004f566a-0x004f5680` | [UID:0002PX] `LogoPlayerPaneDeletingDestructorThunks` | two adjusted-this deleting-destructor thunks | Compiler ABI glue; regenerated from class layout | Follow B009: `FALSE`, blank emitters, no C++ |
| `0x004f5680-0x004f570c` | [UID:0002PY] `LogoPlayerPaneScalarDeletingDestructor` | scalar deleting destructor wrapper | Compiler wrapper around the same source destructor cleanup plus delete flags | Formal C++ blank; preferred no-code metadata should be reconciled with B015/supervisor |
| `0x005c0090-0x005c010a` | [UID:0001NT] contained `VideoPlayerPane` destructor | base non-deleting destructor | Source-bearing base `VideoPlayerPane` destructor, emitted as base teardown from derived destructor | Leave with `VideoPlayerPane`, not `LogoPlayerPane` |
| `0x004f5640-0x004f566a` | [UID:00019E] `AUTOBUFUnsignedCharConstructor` | `_AUTOBUF<unsigned char>` constructor helper | Template/type support, not `LogoPlayerPane` method | Leave with AUTOBUF support |

## Heuristic / Inference Reanalysis And Validation

### Source/no-code destructor factoring

Best direction: [UID:0002PT] is the ordinary source destructor body for `LogoPlayerPane::~LogoPlayerPane()`.

Evidence:

- The target range contains the complete derived cleanup sequence but no scalar delete flag parameter.
- The scalar wrapper [UID:0002PY] repeats the same callback/AUTOBUF/base cleanup, then adds MSVC deleting-destructor flag handling and optional `0x004f4ac0` object free.
- The primary vtable points to [UID:0002PY], and secondary/tertiary views point to [UID:0002PX] thunks, so those ranges are virtual-delete ABI dispatch artifacts.
- The same class family pattern exists in `LogoPane`: [UID:0002PM] is the ordinary source destructor with C++; [UID:0002PQ] is ignored thunk glue; [UID:0002PR] is scalar deleting destructor wrapper with blank formal C++.
- The recently accepted DescPane implementation direction used the same split: ordinary destructor source body in the ordinary destructor page, scalar deleting destructor glue no-code.

Rejected alternatives:

- Make [UID:0002PT] no-code compiler glue: rejected because the body contains the source destructor's only visible handwritten ownership release, `delete m_completionCallback`.
- Emit [UID:0002PY] as the destructor source body: rejected because it adds scalar-delete flag handling and optional object free that source C++ should not hand-write.
- Treat [UID:0002PT] as dead/unreachable and ignore it: rejected because the body mirrors the source destructor cleanup required by the scalar wrapper and fits the complete-object destructor emission pattern.

Impact: [UID:0002PT] should receive first-draft C++. [UID:0002PY] and [UID:0002PX] should not emit handwritten C++ for the wrapper/thunks.

### Source body contents

Best first-draft source body:

```cpp
LogoPlayerPane::~LogoPlayerPane()
{
    delete m_completionCallback;
}
```

Evidence:

- Constructor [UID:0002PS] stores the second constructor argument at `this+0x10c`.
- OnClose [UID:0002PW] invokes the same pointer through vtable slot `+0x0c` and B003 resolved it as `FunctionObject0* m_completionCallback`.
- Both [UID:0002PT] and [UID:0002PY] test the pointer, push deleting flag `1`, and call callback vtable slot `+0x00`, which is exactly the compiler lowering for deleting an owned polymorphic callback object.
- Source `delete pointer;` normally compiles to a null check before calling the deleting destructor. The binary null guard therefore does not require an explicit source `if`.

Accepted caveat: `if (m_completionCallback != NULL) { delete m_completionCallback; }` would be source-equivalent and could compile similarly. I recommend the shorter `delete m_completionCallback;` because it is idiomatic C++ and expresses ownership without decompiler-shaped control flow.

Rejected additions:

- Do not set `m_completionCallback = NULL`; the binary does not clear `+0x10c`.
- Do not call `m_completionCallback->Invoke()`; that belongs to [UID:0002PW] `OnClose`, not the destructor.
- Do not manually free the AUTOBUF payload or call `VideoPlayerPane::~VideoPlayerPane()` in the source body; those are compiler member/base destructor lowering.

### Callback release semantics and type

Best source type: `FunctionObject0* m_completionCallback`.

Evidence:

- B003 raw PE/source-quality report and executed docs resolved [UID:0002PW] as `void LogoPlayerPane::OnClose()` and modeled `this+0x10c` as a non-null zero-argument `FunctionObject0`-family callback.
- Constructor stores the second argument at `+0x10c`; no embedded callback object is constructed at that offset.
- [UID:0002PW] invokes slot `+0x0c`, matching the `Invoke` slot pattern in FunctionObjects docs.
- [UID:0002PT] and [UID:0002PY] release slot `+0x00` with delete flag `1`, matching polymorphic callback object deletion.
- [UID:0000JO] `FunctionObjects` already records this LogoPlayerPane completion callback as a feature-owned consumer of the shared zero-argument callback family.

Rejected alternatives:

- Bespoke `LogoPlayerPaneCallback`: no dedicated RTTI/vtable/constructor evidence.
- Raw function pointer or member-function pointer: contradicted by vtable dispatch and deleting-destructor slot usage.
- `EventHandler` or timer callback: contradicted by storage position and FunctionObject slot pattern.

Remaining caveat: the concrete bound target and original member spelling are still class-wide constructor-caller questions because no direct constructor caller has been recovered. This does not block [UID:0002PT] source C++ because the destructor needs only the stable owning interface pointer.

### AUTOBUF member names and destructor behavior

Best source member direction: embedded `_AUTOBUF<unsigned char>` / `AUTOBUF<unsigned char>` at `LogoPlayerPane +0x100`, with descriptive member name `m_logoData` or `m_logoBuffer`. I recommend `m_logoData` in docs because it owns the full segmented startup movie payload, not merely a scratch buffer.

Best internal field direction:

| Object offset | AUTOBUF field offset | Best descriptive field |
| --- | --- | --- |
| `this+0x100` | `+0x00` | AUTOBUF vptr / `LObject`-compatible header |
| `this+0x104` | `+0x04` | `m_data` / owned byte pointer |
| `this+0x108` | `+0x08` | `m_count`, `m_size`, or `m_byteCount` |

Evidence:

- Constructor [UID:0002PS] initializes the embedded object at `+0x100`, clears pointer/count fields, reads the movie file into it, reads the first segment size from `m_data`, and opens `m_data + 4`.
- Advance [UID:0002PU] computes `m_data + 4 + m_firstSegmentSize` and `m_count - m_firstSegmentSize - 4`.
- AUTOBUF class/type docs independently document concrete field layout `+0x00` vptr, `+0x04` owned byte pointer, `+0x08` byte count/capacity field.
- [UID:0002PT] and [UID:0002PY] reset the embedded AUTOBUF vtable, free `+0x104`, then call `LObject` teardown at `0x004f4a90` on `this+0x100`.

Source policy:

- The destructor source body should not explicitly free `m_logoData.m_data`.
- The class declaration should include the embedded AUTOBUF member, and the compiler should emit its member destructor after the source destructor body.
- Exact `_AUTOBUF`/`AUTOBUF` casing and full template API remain project-wide AUTOBUF questions already recorded in [UID:0000HM]/[UID:0001WN]; they do not block the target destructor source body because the first-draft C++ does not name the AUTOBUF member.

### Base `VideoPlayerPane` teardown

Best direction: `0x005c0090` is the `VideoPlayerPane` non-deleting destructor body.

Evidence:

- [UID:0001NT] documents `0x005c0090-0x005c010a` as the base video-pane destructor: restores `VideoPlayerPane` vtables, unregisters `term`, closes active Bink handle, and calls Pane base teardown.
- [UID:0002PT] tail-jumps to `0x005c0090` after derived callback and member cleanup.
- [UID:0002PY] calls the same base teardown before applying scalar delete flags.
- [UID:0001NT] records xrefs from the LogoPlayerPane cleanup path, scalar wrapper, and constructor EH cleanup.

Source policy: do not model this as a direct source call in `LogoPlayerPane::~LogoPlayerPane()`. It is emitted by the compiler because `LogoPlayerPane` derives from `VideoPlayerPane`.

### Vtable restore roles

Best direction: the three target vtable stores are compiler destructor lowering.

Evidence:

- Constructor writes the same `LogoPlayerPane` vtables at `+0`, `+0xa0`, `+0xa4`.
- Both destructor paths restore those vtable views before member/base teardown.
- Raw vtable data confirms primary/secondary/tertiary destructor dispatch slots at `0x0061d018`, `0x0061d070`, and `0x0061d0a0`.
- Pane layout docs and B001/B009 reports support the `+0xa0` EventHandler secondary view and `+0xa4` tertiary view.

Source policy: source code should express the class inheritance/destructor declaration and let the compiler emit vptr writes. Do not hand-write any vtable store in formal C++.

### Helper names and generated/raw names

Best source-facing names:

| Raw/helper address or label | Source-facing interpretation |
| --- | --- |
| `0x004f4a90` / `sub_4F4A90` | `LObject` base/runtime shell teardown for embedded `AUTOBUF` |
| `0x004f4ac0` / `sub_4F4AC0` | project operator-delete wrapper; scalar wrappers only |
| `0x005c0090` / `sub_5C0090` | `VideoPlayerPane::~VideoPlayerPane()` non-deleting base destructor |
| `j_j_j___free_base` in old text | low-level free used by AUTOBUF destructor lowering |
| `sub_4F5510` style names | avoid in source docs except as old IDA search labels; page should say ordinary `LogoPlayerPane::~LogoPlayerPane()` body |

The active docs still contain several generated/raw helper labels in evidence sections. That is acceptable as evidence, but source/reconstruction sections should use the names above.

### Owner/emitter route

Accepted route:

- Direct semantic owner: [UID:00007H] `LogoPlayerPane`
- Emitter route: [UID:00007H] -> [UID:0000O4] `StartupLogoPanes`
- Source path: `NexusTK/app/StartupLogoPanes.cpp`

Evidence:

- The body restores `LogoPlayerPane` vtables and deletes the `LogoPlayerPane +0x10c` completion callback.
- The cleanup matches constructor and OnClose field use in the same class.
- StartupLogoPanes owns the startup logo/movie pane sequencing; VideoPlayerPane owns only reusable Bink base teardown.
- Current gate is satisfied: target already averages `87.0`, recommended `88/91` averages `89.5`, target is `RECONSTRUCTABLE:TRUE`, and emitter route surfaces to `auto-generated/NexusTK/app/StartupLogoPanes.cpp`.

Rejected owners:

- `VideoPlayerPane`: owns base teardown and Bink frame pump, not the derived completion callback.
- `AUTOBUF`: owns the embedded member type and support helpers, not this feature destructor.
- `FunctionObjects`: owns callback declarations, not the feature object's owning pointer.
- No-owner/no-emitter: rejected because class ownership and source route are already strong and above gate.

### Relationship to [UID:0002PX] thunks

B009's active report direction is consistent with this report: [UID:0002PX] should be no-code compiler-generated adjusted-this thunk glue.

Best direction:

- `0x004f566a`: subtracts `0xa0`, then jumps to [UID:0002PY].
- `0x004f5675`: subtracts `0xa4`, then jumps to [UID:0002PY].
- The thunks exist because deletion can occur through secondary/tertiary base/interface views.
- Source responsibility is the class declaration/destructor, not explicit thunk C++.

I recommend the supervisor preserve B009's row and metadata recommendation for [UID:0002PX] unless a later B009 review supersedes it.

### Relationship to [UID:0002PY] scalar deleting destructor

Best source policy: [UID:0002PY] must not appear as an emitting source body and should keep formal C++ blank. The source destructor body belongs to [UID:0002PT].

Evidence:

- Primary vtable slot `0x0061d018` points to `0x004f5680`.
- The two [UID:0002PX] thunks jump to `0x004f5680`.
- [UID:0002PY] duplicates [UID:0002PT]'s cleanup and then adds MSVC scalar-delete flags, optional project delete `0x004f4ac0`, and guard path.
- No ordinary direct callers are documented.

Metadata policy note:

- Existing local LogoPane scalar wrapper [UID:0002PR] still has `RECONSTRUCTABLE:TRUE` with blank C++ while documenting no handwritten wrapper source.
- The newer accepted DescPane implementation direction moved scalar deleting destructor glue to no-code/non-reconstructable metadata.
- B015 is tracked as active for [UID:0002PY], so this report should not be treated as the final scalar-wrapper implementation checklist. If the supervisor wants B011's direction, I recommend converting [UID:0002PY] to no-code compiler glue: `COMPLETION:86`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++.

At minimum, support docs must state that [UID:0002PY] is not the source body and should not contain formal destructor C++.

### Generated-output pollution

Current generated `auto-generated/NexusTK/app/StartupLogoPanes.cpp` contains:

- a real [UID:0002PW] `LogoPlayerPane::OnClose()` body;
- empty emitter markers for [UID:0002PT], [UID:0002PX], [UID:0002PY], and [UID:00019D].

After the recommended [UID:0002PT] implementation, `StartupLogoPanes.cpp` should gain a `LogoPlayerPane::~LogoPlayerPane()` body from [UID:0002PT]. If [UID:0002PX]/[UID:0002PY] are converted to non-reconstructable/no-emitter metadata, their empty emitter markers should disappear after autogen refresh. The aggregate [UID:00019D] should stay a class-island/support aggregate and should not emit a duplicate destructor body.

## Open Questions Closed Or Reframed

| Existing question | Recommendation |
| --- | --- |
| Destructor factoring | Closed: [UID:0002PT] is the ordinary source destructor body; [UID:0002PY]/[UID:0002PX] are compiler destructor dispatch/delete glue. |
| Lack of IDA function promotion | Closed as non-blocking: raw bytes and scalar-wrapper parity prove the body; no direct xrefs is expected/acceptable for complete-object destructor emission. |
| Callback type | Closed enough for target: `FunctionObject0* m_completionCallback`; exact concrete bound target remains a class-wide constructor-caller caveat. |
| Callback release semantics | Closed: destructor owns and deletes the callback object; source should use `delete m_completionCallback;`. |
| AUTOBUF member behavior | Closed for target: embedded `AUTOBUF<unsigned char>` member is compiler-destructed; source body should not manually free its buffer. |
| AUTOBUF field names | Best descriptive fields: `m_data` / `m_count` or `m_byteCount`; exact header/casing is project-wide and not target-blocking. |
| Base teardown | Closed: `0x005c0090` is `VideoPlayerPane` non-deleting destructor lowering. |
| Vtable stores | Closed: compiler destructor lowering; not source C++. |
| Source placement | Closed: [UID:00007H] under [UID:0000O4] `NexusTK/app/StartupLogoPanes.cpp`. |
| Scalar wrapper policy | Source policy closed: no handwritten C++; exact metadata should be reconciled with B015/supervisor. |

## Recommended Target Doc Changes

Header:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007H | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007H | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Formal C++:

```cpp
LogoPlayerPane::~LogoPlayerPane()
{
    delete m_completionCallback;
}
```

Status/rebuild handling should say:

```text
Rebuild handling: source-authored ordinary `LogoPlayerPane::~LogoPlayerPane()` body plus compiler-lowered vtable/member/base destructor cleanup. The handwritten source effect is ownership release of `FunctionObject0* m_completionCallback`; the vtable restores, embedded AUTOBUF destructor, `LObject` teardown, and `VideoPlayerPane` base destructor tail-call are compiler output.
```

Replace the current "final destructor factoring remains open" / "C++ blank because names not final" language with:

```text
Destructor factoring is resolved for this range. [UID:0002PT] is the ordinary non-deleting `LogoPlayerPane::~LogoPlayerPane()` body. [UID:0002PY] is the scalar deleting destructor wrapper that duplicates this cleanup and adds MSVC delete-flag/object-free behavior; [UID:0002PX] is adjusted-this thunk glue. Source C++ belongs here, not in the wrapper or thunks.
```

Add the target-specific source policy:

```text
The source destructor should only delete the owned completion callback:

`delete m_completionCallback;`

The explicit null test and virtual call through callback vslot `+0x00` are compiler lowering for deleting a polymorphic callback pointer. The `_AUTOBUF<unsigned char>` payload free at `+0x104`, `LObject` teardown for the embedded object at `+0x100`, and tail-jump to `VideoPlayerPane::~VideoPlayerPane()` are compiler-generated member/base destructor calls and should not be hand-authored in the formal C++ block.
```

Add raw PE evidence:

```text
2026-06-19 B011 raw PE recheck against `NexusTK.exe` confirmed `0x004f5500-0x004f5510` as sixteen `0xcc` bytes, target bytes `56 57 8b f9 8b 8f 0c 01 00 00 c7 07 18 d0 61 00 c7 87 a0 00 00 00 70 d0 61 00 c7 87 a4 00 00 00 a0 d0 61 00 85 c9 74 06 8b 01 6a 01 ff 10 ff b7 04 01 00 00 c7 87 00 01 00 00 68 b8 61 00 e8 46 22 0d 00 83 c4 04 8d 8f 00 01 00 00 e8 2f f5 ff ff 8b cf 5f 5e e9 26 ab 0c 00`, and `0x004f556a-0x004f5570` as six `0xcc` bytes. The same recheck confirmed no direct raw dword or rel32 route to `0x004f5510`; primary vtable slot `0x0061d018` points to scalar wrapper `0x004f5680`, while secondary/tertiary slots `0x0061d070`/`0x0061d0a0` point to thunks `0x004f566a`/`0x004f5675`.
```

Score rationale:

```text
Completion `88`: target-local destructor factoring, source body, callback type/release semantics, AUTOBUF member destructor behavior, base teardown, vtable restore role, scalar/thunk relationship, source route, exact bytes, padding, and first-draft C++ are now resolved. It remains below final-audit range because exact original member spelling and concrete callback binding are inferred/descriptive rather than recovered from the missing constructor caller.

Confidence `91`: existing live IDA docs, B003 FunctionObject callback evidence, AUTOBUF/VideoPlayerPane support docs, raw PE byte checks, raw vtable dwords, and destructor-family parity agree. Confidence remains below higher final-audit levels because live IDA MCP was not available in this B011 pass and the callback's concrete allocation site is still not found.
```

## Recommended Support-Doc Changes

### [UID:00007H] `by-class/LogoPlayerPane.md`

Update the cleanup destructor row to:

```text
| cleanup destructor | `0x004f5510-0x004f556a` | Ordinary non-deleting `LogoPlayerPane::~LogoPlayerPane()` body. The source body deletes owned `FunctionObject0* m_completionCallback` at `+0x10c`; compiler lowering restores the three `LogoPlayerPane` vtable views, destructs embedded `AUTOBUF<unsigned char> m_logoData` at `+0x100/+0x104/+0x108`, and chains to `VideoPlayerPane::~VideoPlayerPane()` at `0x005c0090`. |
```

Update data notes:

```text
Offset `+0x100` is best modeled as embedded `AUTOBUF<unsigned char> m_logoData` / `m_logoBuffer` for the segmented movie payload. Its internal `+0x04` field at object offset `+0x104` is the owned byte pointer, and internal `+0x08` at object offset `+0x108` is the byte count/capacity used by segment arithmetic. The destructor paths free this through compiler-emitted AUTOBUF member destruction, not through handwritten `LogoPlayerPane` source.
```

Add destructor dispatch note:

```text
[UID:0002PT] owns/emits the source destructor body. [UID:0002PX] secondary/tertiary deleting-destructor thunks and [UID:0002PY] scalar deleting destructor are compiler-generated destructor dispatch/delete glue and must keep formal C++ blank.
```

Score can remain `86/88`; optional support raise to `87/89` is defensible only if the supervisor also updates constructor/advance caveats, so I do not require a class score change.

### [UID:00019D] `by-memory/0x004f53b0-0x004f570c.LogoPlayerPane.md`

Replace the child range row for [UID:0002PT]:

```text
| `0x004f5510-0x004f556a` | [UID:0002PT][0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor](by-memory/0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor.md) | Ordinary non-deleting `LogoPlayerPane::~LogoPlayerPane()` body. Source cleanup is `delete m_completionCallback;`; vtable stores, AUTOBUF member destruction, `LObject` teardown, and `VideoPlayerPane` base teardown are compiler lowering. |
```

Update [UID:0002PX]/[UID:0002PY] child descriptions to say they are compiler-generated destructor dispatch/delete glue and should not emit source bodies.

Recommended aggregate score: optional `84/90 -> 85/90` if the implementation callback updates the aggregate destructor-family narrative. Do not go higher because constructor caller, `AdvanceToNextSegment` helper exposure, and exact field names outside the destructor remain broader open questions.

### [UID:0002PY] `LogoPlayerPaneScalarDeletingDestructor`

Support direction for B015/supervisor reconciliation:

- Keep formal C++ blank.
- State that source destructor emission belongs to [UID:0002PT].
- If applying B011's broader no-code policy, use `COMPLETION:86`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`.
- If the supervisor keeps current LogoPane-style metadata for now, at least replace any wording that treats [UID:0002PY] as an emitting source body.

Suggested source-policy paragraph:

```text
No standalone C++ should be emitted for this range. This is the MSVC scalar deleting destructor wrapper generated from source `LogoPlayerPane::~LogoPlayerPane()`: it repeats the ordinary cleanup, receives a delete-flags parameter, optionally frees the object through `0x004f4ac0`, and handles the guard bit path. The source body is [UID:0002PT]; this wrapper should remain formal-C++ blank.
```

### [UID:0002PX] `LogoPlayerPaneDeletingDestructorThunks`

Follow B009's active report unless superseded:

- `COMPLETION:86`, `CONFIDENCE:92`
- `RECONSTRUCTABLE:FALSE`
- blank `EMITTER_UIDS`
- formal C++ blank
- support docs should state these are compiler-generated adjusted-this thunks caused by `+0xa0` and `+0xa4` views.

### [UID:0003OR] `LogoPlayerPaneVtableData`

Add:

```text
Destructor dispatch slots: primary table `0x0061d018` points to scalar deleting wrapper [UID:0002PY] `0x004f5680`; secondary `0x0061d070` and tertiary `0x0061d0a0` point to compiler adjustor thunks [UID:0002PX] at `0x004f566a` and `0x004f5675`. The ordinary source destructor cleanup body is [UID:0002PT] and is not directly referenced by these vtable slots.
```

### [UID:0000O4] `StartupLogoPanes`

Add or update evidence note:

```text
2026-06-19 B011 source-quality reanalysis for [UID:0002PT][0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor](by-memory/0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor.md) resolves the startup movie pane destructor factoring: `LogoPlayerPane::~LogoPlayerPane()` source body deletes the owned `FunctionObject0* m_completionCallback`, while embedded `AUTOBUF<unsigned char>` cleanup, `VideoPlayerPane` base teardown, scalar deleting destructor [UID:0002PY], and adjusted-this thunks [UID:0002PX] are compiler-generated lowering/ABI glue.
```

No required changes for `FunctionObjects`, `AUTOBUF`, or `VideoPlayerPane` support docs; they already contain sufficient callback/template/base evidence. Optional cross-links are fine if the supervisor wants discoverability.

## Exact Pending Coverage Text

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` directly in this B-pass.

### Required target row

Replace the current [UID:0002PT] row beginning with:

```text
        - [UID:0002PT][0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor]
```

with:

```text
        - [UID:0002PT][0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor](by-memory/0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor.md) 0x004f5510-0x004f556a | destructor body | LogoPlayerPaneCleanupDestructor : reconstructable : 88% : very strong : B011 2026-06-19 source-quality reanalysis resolves this unpromoted non-deleting range as the ordinary source-bearing `LogoPlayerPane::~LogoPlayerPane()` body, not no-code scalar glue; existing IDA evidence and raw PE bytes confirm exact `0x004f5510-0x004f556a` bounds, sixteen `0xcc` bytes before, six `0xcc` bytes after, three compiler vtable restores to `0x0061d018/0x0061d070/0x0061d0a0`, owned `FunctionObject0* m_completionCallback` at `+0x10c` released by deleting callback vslot `+0x00` with flag `1`, embedded `AUTOBUF<unsigned char> m_logoData` member destruction at `+0x100/+0x104/+0x108`, `LObject` teardown through `0x004f4a90`, final compiler base teardown to `VideoPlayerPane::~VideoPlayerPane()` at `0x005c0090`, no raw direct/vtable route to `0x004f5510`, scalar-wrapper parity with [UID:0002PY][0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor](by-memory/0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor.md), source route through [UID:00007H][LogoPlayerPane](by-class/LogoPlayerPane.md) / [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md), and first-draft C++ `delete m_completionCallback;`; do not hand-write vtable stores, AUTOBUF payload free, `LObject` teardown, or base destructor calls.
```

### Recommended aggregate row if [UID:00019D] support text/score is updated

If the supervisor accepts the optional aggregate `84/90 -> 85/90` support change, replace the [UID:00019D] row with:

```text
    - [UID:00019D][0x004f53b0-0x004f570c.LogoPlayerPane](by-memory/0x004f53b0-0x004f570c.LogoPlayerPane.md) 0x004f53b0-0x004f570c | class island | LogoPlayerPane : reconstructable : 85% : strong : Live IDA, raw PE checks, and refreshed child docs cover the LogoPlayerPane island `0x004f53b0-0x004f570c` with constructor, ordinary source destructor [UID:0002PT] `LogoPlayerPane::~LogoPlayerPane()`, advance-to-next-segment, key/mouse skip handlers, OnClose, adjacent AUTOBUF constructor helper, compiler deleting-destructor thunks [UID:0002PX], scalar deleting destructor wrapper [UID:0002PY], vtable slots, padding, non-contiguous OpenBinkVideo/base-teardown dependencies, callback field `FunctionObject0* m_completionCallback` at `+0x10c`, embedded `AUTOBUF<unsigned char>` payload storage at `+0x100/+0x104/+0x108`, and source route through [UID:00007H][LogoPlayerPane](by-class/LogoPlayerPane.md) / [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md). Completion remains capped by the missing constructor caller, final `AdvanceToNextSegment`/OpenBinkVideo exposure, and exact original field/member spelling outside the destructor.
```

If the aggregate score is left unchanged, only remove stale "unresolved destructor factoring" wording from the row when the supervisor next edits it.

### Support row for [UID:0002PX] if merging B009's report

B009 owns the active [UID:0002PX] report. If the supervisor accepts B009's direction while applying this destructor-family cleanup, use B009's exact replacement row:

```text
        - [UID:0002PX][0x004f566a-0x004f5680.LogoPlayerPaneDeletingDestructorThunks](by-memory/0x004f566a-0x004f5680.LogoPlayerPaneDeletingDestructorThunks.md) 0x004f566a-0x004f5680 | compiler-generated thunks | LogoPlayerPaneDeletingDestructorThunks : ignored : 86% : strong : B009 2026-06-19 source-policy cleanup classifies the two `0xb` secondary/tertiary destructor adjustor thunks as non-emitting compiler glue: `0x004f566a` subtracts `0xa0`, `0x004f5675` subtracts `0xa4`, both tail-jump to [UID:0002PY][0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor](by-memory/0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor.md) `LogoPlayerPaneScalarDeletingDestructor`, vtable slots `0x0061d070/0x0061d0a0` are the only dispatch route, the primary scalar-deleting slot is `0x0061d018`, no ordinary direct callers exist, `+0xa0` is the Pane/EventHandler secondary view and `+0xa4` the tertiary timer/event view, and source should regenerate them from the `LogoPlayerPane` class declaration/destructor rather than handwritten C++.
```

### Support row for [UID:0002PY] if supervisor accepts scalar no-code policy

If the supervisor/B015 accepts the newer no-code scalar-wrapper policy, replace the [UID:0002PY] row with:

```text
        - [UID:0002PY][0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor](by-memory/0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor.md) 0x004f5680-0x004f570c | scalar deleting destructor | LogoPlayerPaneScalarDeletingDestructor : ignored : 86% : very strong : B011 2026-06-19 source-policy recommendation classifies this as MSVC scalar deleting destructor glue generated from source `LogoPlayerPane::~LogoPlayerPane()` at [UID:0002PT][0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor](by-memory/0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor.md): primary vtable slot `0x0061d018` points here, [UID:0002PX][0x004f566a-0x004f5680.LogoPlayerPaneDeletingDestructorThunks](by-memory/0x004f566a-0x004f5680.LogoPlayerPaneDeletingDestructorThunks.md) thunks tail-jump here from secondary/tertiary views, the body duplicates the ordinary callback/AUTOBUF/base cleanup, receives a delete-flags parameter, optionally frees object storage through `0x004f4ac0` when bit `1` is set and bit `4` is clear, takes the guard-check path for bit `4`, has no ordinary direct callers, and should keep formal C++ blank because the source body and emitted destructor declaration belong to [UID:0002PT] / [UID:00007H][LogoPlayerPane](by-class/LogoPlayerPane.md).
```

If the supervisor keeps current LogoPane-style scalar metadata for [UID:0002PY] pending B015 review, leave the row `reconstructable` but update its prose to remove any implication that the wrapper owns the source destructor body.

## Validator Needs

Suggested implementation-callback validation commands from `source-3/project-documentation` after applying accepted target/support docs:

> Executable block R001 was removed from this report and preserved verbatim in [0002PT-LogoPlayerPaneCleanupDestructor-source-quality-removed.md](0002PT-LogoPlayerPaneCleanupDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If [UID:0002PX] and/or [UID:0002PY] support metadata is accepted in the same implementation callback:

> Executable block R002 was removed from this report and preserved verbatim in [0002PT-LogoPlayerPaneCleanupDestructor-source-quality-removed.md](0002PT-LogoPlayerPaneCleanupDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor applies coverage rows:

> Executable block R003 was removed from this report and preserved verbatim in [0002PT-LogoPlayerPaneCleanupDestructor-source-quality-removed.md](0002PT-LogoPlayerPaneCleanupDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Because formal C++ and/or emitter metadata changes affect generated output, run:

> Executable block R004 was removed from this report and preserved verbatim in [0002PT-LogoPlayerPaneCleanupDestructor-source-quality-removed.md](0002PT-LogoPlayerPaneCleanupDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Optional post-refresh checks:

> Executable block R005 was removed from this report and preserved verbatim in [0002PT-LogoPlayerPaneCleanupDestructor-source-quality-removed.md](0002PT-LogoPlayerPaneCleanupDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Implementation Readiness

Ready for target implementation callback.

Minimum implementation set:

- Update [UID:0002PT] metadata to `88/91`, keep owner/emitter/reconstructable unchanged.
- Populate formal C++ with `LogoPlayerPane::~LogoPlayerPane() { delete m_completionCallback; }`.
- Replace stale open-question text with resolved source destructor factoring.
- Add raw PE/vtable evidence and source-policy notes.
- Update `LogoPlayerPane`, `LogoPlayerPane` aggregate, `LogoPlayerPaneVtableData`, and `StartupLogoPanes` support docs to state that [UID:0002PT] owns/emits the source destructor body, while [UID:0002PX]/[UID:0002PY] are compiler destructor dispatch/delete glue and formal-C++ blank.
- Do not edit `by-memory/-coverage-report.md`; supervisor owns the pending row replacement.

Remaining non-blocking class-wide caveats:

- Exact constructor caller/allocation route for `LogoPlayerPane` is still missing.
- Exact concrete callback binding and original member spelling for `m_completionCallback` are not recovered.
- Exact `_AUTOBUF`/`AUTOBUF` header casing and member field names remain project-wide utility-template questions.
- `AdvanceToNextSegment` still has final field/helper naming and `OpenBinkVideo` exposure questions.

These caveats do not block [UID:0002PT] source C++ because the target-local source body is only the owned callback deletion.

## Validator Results

Commands run for this report:

- Read-only `Get-Content`, `Select-String`, and `rg` checks over target/support docs, generated reports, project-level reports, and prior reports.
- Read-only raw PE byte/vtable checks against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

Validators run: none. This was a report-only assignment and no by-* docs or coverage reports were edited.

## Changed Files

Created:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B011/research/0002PT-LogoPlayerPaneCleanupDestructor-source-quality.md`

Modified:

- none outside this report.

Leases used:

- none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/0002PT-LogoPlayerPaneCleanupDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"0002PT"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002PT-LogoPlayerPaneCleanupDestructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/0002PT-LogoPlayerPaneCleanupDestructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002PT"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
