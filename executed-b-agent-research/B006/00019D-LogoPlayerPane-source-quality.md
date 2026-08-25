** TARGET-REPORT-UID:00019D **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00019D LogoPlayerPane Aggregate Source-Quality Report

Assignment: Agent-B006 B-preferred report-only source-quality audit for [UID:00019D] `LogoPlayerPane`

Target: `source-3/project-documentation/by-memory/0x004f53b0-0x004f570c.LogoPlayerPane.md`

Report date: 2026-06-19

## Scope And Constraints

- Report-only. I did not edit target/support by-* docs, generated C++, IDA state, or `by-memory/-coverage-report.md`.
- Preserve existing B006 reports `00011T`, `00015T`, and `00018I`; they remain in `Agent-B006/research/`.
- Required target is the physical LogoPlayerPane island, including constructor, cleanup destructor, advance path, input handlers, `OnClose`, adjacent `_AUTOBUF<unsigned char>` helper, deleting thunks, scalar deleting destructor, and non-contiguous `OpenBinkVideo` / `VideoPlayerPane` dependency.

## Evidence Checked

- Current target and support docs:
  - [UID:00019D] `0x004f53b0-0x004f570c.LogoPlayerPane`
  - [UID:00007H] `LogoPlayerPane`
  - [UID:0000O4] `StartupLogoPanes`
  - Child pages [UID:0002PS], [UID:0002PT], [UID:0002PU], [UID:0002PV], [UID:0002PW], [UID:00019E], [UID:0002PX], [UID:0002PY]
  - [UID:0001NT]/[UID:0000FV]/[UID:0000P4] `VideoPlayerPane`
  - [UID:0001WN]/[UID:00000P]/[UID:0000HM] `_AUTOBUF<unsigned char>` support
  - [UID:0001RN] startup-logo media
  - [UID:0003OR] `LogoPlayerPaneVtableData`
  - [UID:00025O] `LObjectLogoReadOnlyData`
- Current generated output:
  - `auto-generated/NexusTK/app/StartupLogoPanes.cpp`
  - `auto-generated/NexusTK/ui/core/VideoPlayerPane.cpp`
- Coverage reports:
  - `by-memory/-coverage-report.md`
  - `by-class/-coverage-report.md`
  - `by-file/-coverage-report.md`
  - `by-resource/-coverage-report.md`
- Prior accepted B-agent evidence:
  - `Agent-B001/research/executed/0002PV-logoplayer-input-skip-handlers-source-quality.md`
  - `Agent-B003/research/executed/0002PW-LogoPlayerPaneOnClose-source-quality.md`
- Prior-report search across B001/B002/B006 executed reports for `LogoPlayerPane`, `00019D`, `0002PS`, `0002PT`, `0002PU`, `0002PX`, `0002PY`, and `00019E`.
- Live IDA availability check:
  - `tool_search` found no exposed IDA MCP tool.
  - HTTP MCP probe to `http://127.0.0.1:13337/mcp` failed with `Unable to connect to the remote server`.
  - This report therefore relies on current docs containing prior live IDA/PE evidence and accepted B001/B003 raw or live rechecks.

## Main Recommendation

Keep [UID:00019D] as a reconstructable physical island/index, but do not put class declaration or method bodies in the aggregate page. The aggregate's formal C++ should remain blank. The declaration-level first draft belongs in [UID:00007H] `by-class/LogoPlayerPane.md`, with `[[CHILDREN]]` placed after the class declaration so exact by-memory child method definitions emit outside the class.

Recommended aggregate metadata:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `84` | `88` |
| `CONFIDENCE` | `90` | `91` |
| `CANONICAL_OWNER` | `00007H` | `00007H` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `EMITTER_UIDS` | `00007H` | `00007H` |
| Formal C++ | blank | keep blank |

Reason: behavior, ownership, field roles, callback/event semantics, helper ownership, and generated-code split are now source-quality resolved at aggregate level. Remaining uncertainty is exact original spelling/header placement and the missing direct constructor caller, not owner/source shape.

## Source Placement

Accepted source route:

```text
LogoPlayerPane class [UID:00007H]
  -> StartupLogoPanes file [UID:0000O4]
  -> NexusTK/app/StartupLogoPanes.cpp
```

`StartupLogoPanes.cpp` remains the best placement because this class owns the startup segmented Bink policy: read caller-supplied logo movie payload, play first segment, let input skip to the second segment, and invoke the startup completion callback. Do not move this class to `VideoPlayerPane.cpp`; the reusable Bink frame pump, handle lifetime, idle/message behavior, and `OpenBinkVideo` helper remain `VideoPlayerPane` responsibilities.

Rejected source routes:

- `VideoPlayerPane`: owns Bink base mechanics, but not startup segment sequencing, completion callback, or input skip policy.
- `Pane` / `EventHandler`: own dispatch layout and inherited helpers only.
- `FunctionObjects`: owns callback interface/template support, not the feature method using the callback.
- `AUTOBUF`: owns template support, not the pane class.
- A new `LogoPlayerPane.cpp` file: plausible future split, but current strongest documented file root is still the combined `StartupLogoPanes.cpp` startup-logo module.

## Child Split And Emit Model

| UID | Range | Source model | Recommended emit handling |
| --- | --- | --- | --- |
| `0002PS` | `0x004f53b0-0x004f5500` | `LogoPlayerPane::LogoPlayerPane(const wchar_t *moviePath, FunctionObject0 *completionCallback)` | Source-authored constructor. Keep as LogoPlayerPane child; formal body can remain blank until `StdioFile`/`_AUTOBUF` API spelling is coordinated, but class declaration should name the constructor. |
| `0002PT` | `0x004f5510-0x004f556a` | Ordinary non-deleting `LogoPlayerPane::~LogoPlayerPane()` cleanup semantics | This is the source destructor body/factoring anchor. Emit at most one source destructor from this semantics; do not also hand-port the scalar deleting wrapper. |
| `0002PU` | `0x004f5570-0x004f55c8` | `void LogoPlayerPane::AdvanceToNextSegment()` | Source-authored private helper. Formal body can remain blank until helper/API names settle, but the source shape is clear. |
| `0002PV` | `0x004f55d0-0x004f561d` | `bool OnKeyEvent(const KeyEvent *)` and `bool OnMouseEvent(const MouseEvent *)` | Source-authored adjacent virtual pair. Keep current accepted B001 state: no split required; formal C++ blank until shared event declarations settle. |
| `0002PW` | `0x004f5620-0x004f5634` | `void LogoPlayerPane::OnClose()` | Source-authored virtual. Existing first-draft C++ is valid and should remain. |
| `00019E` | `0x004f5640-0x004f566a` | `_AUTOBUF<unsigned char>` constructor helper | Not a LogoPlayerPane method. Route through AUTOBUF/template support, not this class. |
| `0002PX` | `0x004f566a-0x004f5680` | Secondary-base deleting destructor adjustor thunks | Compiler-generated glue. No handwritten C++; regenerate from class/base declaration and destructor. |
| `0002PY` | `0x004f5680-0x004f570c` | Scalar deleting destructor wrapper | Compiler-generated wrapper around destructor cleanup. No handwritten C++; source destructor belongs with `0002PT` semantics. |
| companion | `0x005c0110-0x005c0174` | `VideoPlayerPane::OpenBinkVideo` | Keep with `VideoPlayerPane` as protected memory-backed Bink helper despite current Logo-only callers. |

## Class Declaration Shape

Recommended [UID:00007H] `by-class/LogoPlayerPane.md` first-draft declaration:

```cpp
class LogoPlayerPane : public VideoPlayerPane
{
public:
    LogoPlayerPane(const wchar_t *moviePath, FunctionObject0 *completionCallback);
    virtual ~LogoPlayerPane();

protected:
    virtual void OnClose();
    virtual bool OnKeyEvent(const KeyEvent *event);
    virtual bool OnMouseEvent(const MouseEvent *event);

private:
    void AdvanceToNextSegment();

    _AUTOBUF<unsigned char> m_movieData;       // +0x100
    FunctionObject0 *m_completionCallback;     // +0x10c
    bool m_secondSegmentAttempted;             // +0x110
    unsigned char m_reserved111[3];            // +0x111..+0x113
    unsigned int m_firstSegmentSize;           // +0x114
};

[[CHILDREN]]
```

The `[[CHILDREN]]` marker must be after the class declaration, not inside it, because [UID:0002PW] already emits an out-of-class method definition:

```cpp
void LogoPlayerPane::OnClose()
{
    MarkForDeletion();
    m_completionCallback->Invoke();
}
```

Recommended [UID:00007H] metadata if the class shell is accepted:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `86` | `88` |
| `CONFIDENCE` | `88` | `91` |
| `CANONICAL_OWNER` | `0000O4` | `0000O4` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `EMITTER_UIDS` | `0000O4` | `0000O4` |

## Field And Type Names

Best-supported member names:

| Offset | Recommended name/type | Evidence |
| --- | --- | --- |
| `+0x100` | `_AUTOBUF<unsigned char> m_movieData` | Constructor constructs embedded `_AUTOBUF`; file-read helper fills pointer/count fields; advance path computes Bink segment pointers from it. |
| `+0x104` | `m_movieData` payload pointer subfield | Freed by destructors and used as Bink payload base. |
| `+0x108` | `m_movieData` byte count subfield | Used for remaining second-segment size arithmetic. |
| `+0x10c` | `FunctionObject0 *m_completionCallback` | Constructor stores second argument; destructors release through vslot `+0x00`; `OnClose` invokes vslot `+0x0c`. |
| `+0x110` | `bool m_secondSegmentAttempted` | Cleared in constructor, tested before skip, set before second-segment open attempt, prevents repeated attempts even on failure. |
| `+0x114` | `unsigned int m_firstSegmentSize` | Loaded from first payload dword and used by advance arithmetic. |

Rejected alternatives:

- `m_filePath` / `filePath`: wrong for `+0x100/+0x104`; the field stores loaded bytes, not a path. Also wrong for `OpenBinkVideo`'s first parameter, which receives memory-backed Bink data.
- `m_hasAdvanced` as the only flag name: close, but less exact because the flag is set before the second open succeeds.
- `m_isPlayingSecondSegment`: rejected because failure path still leaves the guard set.
- `LogoPlayerPaneCallback`: no dedicated callback vtable/RTTI/construction evidence; the shared `FunctionObject0` ABI fits the slots.
- `AUTOBUF<unsigned char>` without underscore as the formal field type: useful doc shorthand, but the binary-decorated type is `_AUTOBUF<unsigned char>` (`??_7?$_AUTOBUF@E@@6B@`).

## Method Semantics

Constructor:

- Signature direction: `LogoPlayerPane(const wchar_t *moviePath, FunctionObject0 *completionCallback)`.
- Builds `VideoPlayerPane`, installs three `LogoPlayerPane` vtable views, constructs embedded `_AUTOBUF<unsigned char>`, stores callback, clears `m_secondSegmentAttempted`, reads the whole movie file into `m_movieData`, reads the first dword into `m_firstSegmentSize`, opens first segment at `buffer + 4`, and throws `FileError(L"%s corrupted", moviePath)` when open fails.
- Missing direct constructor caller remains real, but it is not a blocker for class/source shape.

Ordinary destructor factoring:

- The unpromoted cleanup body [UID:0002PT] is the source destructor's semantic anchor.
- Source-level destructor body likely only needs to release the owned callback:

```cpp
LogoPlayerPane::~LogoPlayerPane()
{
    delete m_completionCallback;
}
```

The explicit `_AUTOBUF` member teardown and `VideoPlayerPane` base teardown are compiler-generated around the source destructor body. Do not hand-write the secondary adjustor thunks or scalar deleting wrapper as separate methods.

Advance path:

- Source-facing name: `AdvanceToNextSegment`.
- Checks `m_secondSegmentAttempted` and `VideoPlayerPane` progress below `100`.
- Computes `secondSegmentData = m_movieData.data + 4 + m_firstSegmentSize`.
- Computes `remaining = m_movieData.count - m_firstSegmentSize - 4`.
- Sets `m_secondSegmentAttempted = true` before opening.
- Calls inherited/protected `OpenBinkVideo(secondSegmentData, remaining)`.
- On success calls inherited `StartPlayback`; on failure calls inherited `MarkForDeletion`.
- Size/remaining argument is still unused by recovered `OpenBinkVideo`; keep the parameter but do not invent validation side effects.

Input handlers:

- Accepted B001 semantics stand:
  - `OnKeyEvent` handles EventMan type `8` (`KeyDown`) and advances only for Enter (`0x0d`), Escape (`0x1b`), or Space (`0x20`).
  - `OnMouseEvent` handles EventMan type `3` (`LeftButtonUp` / left-button release).
  - Both are reached via the `+0xa0` secondary Pane/EventHandler view, normalize `this - 0xa0`, call `AdvanceToNextSegment` when triggered, and return handled even when not triggered.
- No immediate split is required; optional future split into `OnKeyEvent` and `OnMouseEvent` pages is safe but not needed for ownership/source-quality.

OnClose:

- Accepted B003 first-draft C++ is valid:

```cpp
void LogoPlayerPane::OnClose()
{
    MarkForDeletion();
    m_completionCallback->Invoke();
}
```

- Keep no null check; raw code unconditionally dereferences the callback.
- Keep delete-mark before callback invocation.

## OpenBinkVideo And VideoPlayerPane

Keep `0x005c0110-0x005c0174` with [UID:0000FV] `VideoPlayerPane`, not `LogoPlayerPane`.

Best source-facing direction:

```cpp
protected:
    bool OpenBinkVideo(const unsigned char *segmentData, unsigned int segmentByteCount);
```

Evidence for `VideoPlayerPane` ownership:

- Physical location in the `VideoPlayerPane` island.
- Operates on base playback fields `+0xf8/+0xfc`.
- Configures DirectSound, registers `term`, closes old Bink handle, and calls `BinkOpen(segmentData, 0x04080000)`.
- Constructor and advance path are current only direct callers, but caller set alone is weaker than implementation and class-field ownership.

Required support-doc cleanup:

- Do not call the first parameter `filePath`.
- In `VideoPlayerPane` docs, keep the caller caveat but state the preferred protected base-helper signature above.
- In `LogoPlayerPane` docs, refer to it as inherited/protected `OpenBinkVideo`, not a LogoPlayerPane-local helper.

## AUTOBUF, Resource, And Rdata Support

`_AUTOBUF<unsigned char>`:

- [UID:00019E] remains a template/type helper, not a pane method.
- [UID:0001WN]/[UID:00000P]/[UID:0000HM] should remain the owning support chain.
- The stale `by-memory/-coverage-report.md` row for [UID:00019E] still says `76%`; the page is now `85/90`. Replacement row is below.

Startup-logo media:

- [UID:0001RN] already has the necessary segmented Bink contract: first dword is first segment size, first segment starts at `buffer + 4`, second segment starts at `buffer + firstSegmentSize + 4`, and Bink flags are `0x04080000`.
- No package-provenance change is needed for this task. The actual payloads remain absent from the audited package.

Read-only/vtable data:

- [UID:0003OR] `LogoPlayerPaneVtableData` should add a B006 note that the source declaration above is sufficient to regenerate the primary/secondary/tertiary vtables. Do not hand-write raw vtable data.
- [UID:00025O] mixed read-only aggregate remains non-reconstructable/index-only; no owner change.

FunctionObjects:

- Existing B003 support in `FunctionObjects.md` is sufficient. If touched, add only a class-level note that [UID:00007H] now uses `FunctionObject0 *m_completionCallback` as its accepted field direction; the concrete bound callback target remains unresolved because the constructor caller is still missing.

## Current Generated Output Issues

`auto-generated/NexusTK/app/StartupLogoPanes.cpp` currently contains:

- `LogoPane::~LogoPane()`
- `LogoPlayerPane::OnClose()`
- empty emitter markers for `LogoPlayerPane`, constructor, aggregate, cleanup destructor, advance helper, input handlers, deleting thunks, scalar deleting destructor, and vtable data.

This is source-quality incomplete for the class shape. The next implementation callback should add the `LogoPlayerPane` class declaration shell to [UID:00007H], not to [UID:00019D]. Exact child bodies can remain blank except [UID:0002PW] until helper/type declarations are coordinated.

`auto-generated/NexusTK/ui/core/VideoPlayerPane.cpp` is still only empty emitter markers. That is outside this target, but `OpenBinkVideo` parameter naming/support should be cleaned there before LogoPlayerPane constructor/advance method bodies are emitted.

## Recommended Target And Support Changes

Target [UID:00019D]:

- Set `COMPLETION:88`, `CONFIDENCE:91`; keep owner/emitter/reconstructable.
- Keep formal C++ blank.
- Add B006 source-quality summary with child split/emit model.
- Replace passive open questions with the accepted member names and rejected alternatives above.
- State explicitly that the class declaration belongs to [UID:00007H], not the by-memory aggregate.

Class [UID:00007H] `LogoPlayerPane`:

- Set `COMPLETION:88`, `CONFIDENCE:91`.
- Add the declaration-level C++ shell with `[[CHILDREN]]` after the class.
- Add field table with `_AUTOBUF<unsigned char> m_movieData`, `FunctionObject0 *m_completionCallback`, `m_secondSegmentAttempted`, and `m_firstSegmentSize`.
- Add method inventory noting source bodies versus generated glue.

File [UID:0000O4] `StartupLogoPanes`:

- Keep file route and current score unless supervisor wants a small confidence bump.
- Add B006 note that the LogoPlayerPane declaration is now ready under this file, with child bodies deferred except `OnClose`.
- Keep `OpenBinkVideo` and `_AUTOBUF` as dependencies, not local ownership.

Child pages:

- [UID:0002PS] add signature/field-name direction and keep body blank.
- [UID:0002PT] document as the ordinary destructor source anchor; source body is callback release, while member/base teardown is compiler generated.
- [UID:0002PU] add `AdvanceToNextSegment`, field names, inherited `OpenBinkVideo`, and `StartPlayback`/`MarkForDeletion` naming.
- [UID:0002PV] no substantive change required beyond class-shell coordination; B001 details are already incorporated.
- [UID:0002PW] no change required; keep first-draft C++.
- [UID:00019E] fix coverage row stale score/type wording; no LogoPlayerPane ownership change.
- [UID:0002PX]/[UID:0002PY] add no-handwritten-C++ wording if not already considered sufficient.

Support:

- [UID:0001NT]/[UID:0000FV]/[UID:0000P4] `VideoPlayerPane`: add protected `OpenBinkVideo(const unsigned char *segmentData, unsigned int segmentByteCount)` direction and reject `filePath`.
- [UID:0001WN]/[UID:00000P]/[UID:0000HM] `_AUTOBUF`: no ownership change; optionally mention this class's accepted `m_movieData` field.
- [UID:0001RN] startup-logo media: no score/ownership change; optionally mention B006 class field names.
- [UID:0003OR] vtable data: add class-declaration regeneration note.
- [UID:00025O] mixed rdata: no metadata change.

## Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` from this report. If accepted, replace these rows.

### by-memory/-coverage-report.md

```text
    - [UID:00019D][0x004f53b0-0x004f570c.LogoPlayerPane](by-memory/0x004f53b0-0x004f570c.LogoPlayerPane.md) 0x004f53b0-0x004f570c | class island | LogoPlayerPane : reconstructable : 88% : very strong : B006 2026-06-19 aggregate source-quality review keeps this as a reconstructable physical island/index, not the class-declaration emitter; source placement is [UID:00007H][LogoPlayerPane](by-class/LogoPlayerPane.md) through [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md). The exact child model is source bodies for constructor [UID:0002PS], ordinary cleanup destructor [UID:0002PT], segment advance [UID:0002PU], input handlers [UID:0002PV], and OnClose [UID:0002PW] (already first-draft C++), while [UID:00019E] is `_AUTOBUF<unsigned char>` template support owned by [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md), [UID:0002PX] are compiler adjustor thunks, and [UID:0002PY] is the scalar deleting wrapper. Best-supported class fields are `_AUTOBUF<unsigned char> m_movieData` at +0x100, `FunctionObject0* m_completionCallback` at +0x10c, `bool m_secondSegmentAttempted` at +0x110, and `unsigned int m_firstSegmentSize` at +0x114; event semantics are key-down Enter/Escape/Space and left-button release/up; `OpenBinkVideo` remains a protected `VideoPlayerPane` memory-backed Bink helper at 0x005c0110. Aggregate C++ should remain blank; by-class/LogoPlayerPane should carry the declaration shell with `[[CHILDREN]]` after the class so exact child method bodies emit outside the declaration.
        - [UID:0002PS][0x004f53b0-0x004f5500.LogoPlayerPaneConstructor](by-memory/0x004f53b0-0x004f5500.LogoPlayerPaneConstructor.md) 0x004f53b0-0x004f5500 | constructor | LogoPlayerPaneConstructor : reconstructable : 86% : very strong : B006 2026-06-19 source-quality aggregation resolves the source-facing constructor as `LogoPlayerPane::LogoPlayerPane(const wchar_t *moviePath, FunctionObject0 *completionCallback)`: it builds the `VideoPlayerPane` base, installs three LogoPlayerPane vtable views, constructs `_AUTOBUF<unsigned char> m_movieData` at +0x100, stores non-null `FunctionObject0* m_completionCallback` at +0x10c, clears `bool m_secondSegmentAttempted` at +0x110, reads the caller-supplied segmented Bink payload through the stack `StdioFile`, stores the first payload dword as `m_firstSegmentSize` at +0x114, opens the first memory-backed segment through inherited/protected `VideoPlayerPane::OpenBinkVideo(buffer + 4, firstSegmentSize)`, and throws `FileError(L"%s corrupted", moviePath)` on open failure. Formal method C++ remains blank pending exact `StdioFile`/`_AUTOBUF` API spelling and the still-missing direct constructor caller.
        - [UID:0002PT][0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor](by-memory/0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor.md) 0x004f5510-0x004f556a | unpromoted destructor body | LogoPlayerPaneCleanupDestructor : reconstructable : 86% : very strong : B006 2026-06-19 source-quality aggregation treats this unpromoted cleanup body as the ordinary `LogoPlayerPane::~LogoPlayerPane()` source destructor anchor: the authored destructor releases owned `FunctionObject0* m_completionCallback`, while `_AUTOBUF<unsigned char> m_movieData` teardown and `VideoPlayerPane` base teardown are compiler-emitted member/base cleanup. Live prior IDA evidence already proves vtable restores at +0/+0xa0/+0xa4, callback delete through +0x10c with flag 1, AUTOBUF vtable reset/free at +0x100/+0x104, embedded LObject teardown, and tail-jump to VideoPlayerPane teardown at 0x004f5565. Do not duplicate this source destructor by emitting [UID:0002PY] as a handwritten method.
        - [UID:0002PU][0x004f5570-0x004f55c8.LogoPlayerPaneAdvanceToNextSegment](by-memory/0x004f5570-0x004f55c8.LogoPlayerPaneAdvanceToNextSegment.md) 0x004f5570-0x004f55c8 | method | LogoPlayerPaneAdvanceToNextSegment : reconstructable : 86% : very strong : B006 2026-06-19 source-quality aggregation resolves this as private `LogoPlayerPane::AdvanceToNextSegment()`: it tests `m_secondSegmentAttempted` at +0x110 and VideoPlayerPane progress below 100 through +0xfc/+0x0c, computes second-segment data from `m_movieData` pointer + `m_firstSegmentSize` + 4, computes remaining bytes from `m_movieData` count - `m_firstSegmentSize` - 4, sets the guard before trying to open, calls inherited/protected `VideoPlayerPane::OpenBinkVideo(segmentData, remainingBytes)`, then calls inherited `StartPlayback` on success or `MarkForDeletion` on failure. Formal C++ remains blank pending exact base helper/event declaration names, but field/helper ownership is no longer an open blocker.
        - [UID:00019E][0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor](by-memory/0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor.md) 0x004f5640-0x004f566a | template constructor helper | AUTOBUFUnsignedCharConstructor : reconstructable : 85% : strong : Current target metadata and C001/B006 evidence classify this as the concrete `_AUTOBUF<unsigned char>` constructor helper, not a LogoPlayerPane method: it calls the LObject shell constructor, writes vtable `0x0061b868`, clears pointer/count fields, has direct caller evidence from MapPane `0x00504d49`, and belongs through [UID:0001WN][AUTOBUF_unsigned_char](by-type/by-template/AUTOBUF_unsigned_char.md) / [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md). Its physical placement inside the LogoPlayerPane island is linker adjacency/template emission; do not migrate or emit it as a LogoPlayerPane member.
        - [UID:0002PX][0x004f566a-0x004f5680.LogoPlayerPaneDeletingDestructorThunks](by-memory/0x004f566a-0x004f5680.LogoPlayerPaneDeletingDestructorThunks.md) 0x004f566a-0x004f5680 | compiler-generated thunks | LogoPlayerPaneDeletingDestructorThunks : reconstructable : 84% : strong : B006 2026-06-19 source-quality aggregation keeps these as compiler-generated secondary-base deleting destructor adjustor thunks: the two 0x0b bodies subtract 0xa0 and 0xa4, tail-jump to 0x004f5680, are reached through vtable slots 0x0061d070/0x0061d0a0, and should be regenerated from the `LogoPlayerPane : public VideoPlayerPane` declaration plus virtual destructor. No handwritten C++ should be emitted for this range.
        - [UID:0002PY][0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor](by-memory/0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor.md) 0x004f5680-0x004f570c | scalar deleting destructor | LogoPlayerPaneScalarDeletingDestructor : reconstructable : 84% : strong : B006 2026-06-19 source-quality aggregation keeps this as compiler-generated scalar deleting destructor wrapper around the ordinary destructor semantics represented by [UID:0002PT]: prior IDA evidence proves callback release, AUTOBUF reset/free, LObject/member teardown, VideoPlayerPane base teardown, optional project delete, guarded bit-0x4 path, thunk/primary-vtable reachability, and successor padding. Source should declare/write `LogoPlayerPane::~LogoPlayerPane()` once and let the compiler regenerate this wrapper; no handwritten C++ should be emitted for this range.
```

Keep the existing [UID:0002PV] and [UID:0002PW] rows unless the supervisor wants to reflow the whole block; they already include accepted B001/B003 source-quality details.

### by-class/-coverage-report.md

```text
- [UID:00007H][LogoPlayerPane](by-class/LogoPlayerPane.md) : reconstructable : 88% : very strong : B006 2026-06-19 aggregate source-quality review resolves the class-level declaration shape under [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md): `LogoPlayerPane : public VideoPlayerPane`, constructor `(const wchar_t *moviePath, FunctionObject0 *completionCallback)`, virtual destructor, `OnClose`, `OnKeyEvent`, `OnMouseEvent`, private `AdvanceToNextSegment`, `_AUTOBUF<unsigned char> m_movieData` at +0x100, `FunctionObject0* m_completionCallback` at +0x10c, `bool m_secondSegmentAttempted` at +0x110, and `unsigned int m_firstSegmentSize` at +0x114. The formal class C++ should be declaration-only with `[[CHILDREN]]` after the class so [UID:0002PW] and future exact child method bodies emit outside the declaration; compiler thunks, scalar deleting destructor, vtables, and the adjacent AUTOBUF helper remain generated/template support rather than handwritten class methods.
```

### by-file/-coverage-report.md

If the supervisor updates the file row text, use this replacement without changing the score unless broader file scoring is also reviewed:

```text
- [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md) : reconstructable : 88% : strong : Startup logo/static and Bink-video pane module under `NexusTK/app/`; B006 2026-06-19 LogoPlayerPane aggregate review confirms this file remains the source route for `LogoPlayerPane` declaration and startup segmented-Bink sequencing, while `VideoPlayerPane::OpenBinkVideo` stays a reusable ui/core base helper and `_AUTOBUF<unsigned char>` stays utility/template support. Existing docs cover LogoPane, LogoPlayerPane, standalone startup Bink playback, restart flag/global state, resources, callback objects, and current static-logo versus video split caveat.
```

## Validation Commands Needed If Accepted

Run after applying accepted target/support/coverage changes:

> Executable block R001 was removed from this report and preserved verbatim in [00019D-LogoPlayerPane-source-quality-removed.md](00019D-LogoPlayerPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If no support-doc wording is changed for `VideoPlayerPane`, `AUTOBUF`, `startup-logo-media`, or vtable data, those specific file validators can be skipped.

## Implementation Readiness

Ready for supervisor implementation callback:

- Add class declaration shell to [UID:00007H].
- Update aggregate [UID:00019D] with B006 split/source-quality conclusion.
- Update constructor/destructor/advance child prose with field names and emit/no-code policy.
- Fix [UID:00019E] coverage stale score/type row.
- Leave [UID:0002PV] and [UID:0002PW] behavior intact.
- Keep aggregate [UID:00019D] formal C++ blank.

Not yet ready without broader support work:

- Full constructor formal method body, because exact `StdioFile` and `_AUTOBUF` public API spellings are still not coordinated.
- Full advance formal method body, because final `VideoPlayerPane::OpenBinkVideo`, `StartPlayback`, and event/base declaration spellings need coordination.
- Input handler formal method bodies, per accepted B001 blocker on shared `KeyEvent`/`MouseEvent` and enum declaration names.

## Changed Files

Created:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B006/research/00019D-LogoPlayerPane-source-quality.md`

No other files were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/00019D-LogoPlayerPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"00019D"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00019D-LogoPlayerPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/00019D-LogoPlayerPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00019D"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
