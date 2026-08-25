** TARGET-REPORT-UID:0002PX **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B009 Source-Quality Report: [UID:0002PX] LogoPlayerPaneDeletingDestructorThunks

Date: 2026-06-19  
Agent: B009  
Target: `source-3/project-documentation/by-memory/0x004f566a-0x004f5680.LogoPlayerPaneDeletingDestructorThunks.md`  
Assignment type: B-preferred report-only source-quality / heuristic research  
Status: ready for supervisor implementation callback; no target/support docs edited

## Summary Recommendation

`0002PX` should be documented as pure compiler-generated secondary/tertiary deleting-destructor adjustor thunk glue and changed from a reconstructable class-owned emitter to a non-emitting ignored range.

Recommended target metadata:

```yaml
COMPLETION:86
CONFIDENCE:92
CANONICAL_OWNER:00007H
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
```

Recommended formal C++: leave `RECONSTRUCTION_CPP` blank. Do not emit handwritten C++ for either thunk, and do not leave an empty emitter marker in generated source.

Reason: both functions are exact MSVC ABI adjustor thunks. They only subtract the embedded base/interface offset from `ecx` and tail-jump to [UID:0002PY] `LogoPlayerPaneScalarDeletingDestructor`. The source responsibility is the `LogoPlayerPane` class declaration, base layout, virtual destructor, and ordinary cleanup destructor body. The compiler regenerates the secondary/tertiary deleting-destructor thunk entries from that declaration.

## Evidence Checked

Primary target page:

- `0x004f566a` is an 11-byte thunk: `sub ecx, 0A0h; jmp 0x004f5680`.
- `0x004f5675` is an 11-byte thunk: `sub ecx, 0A4h; jmp 0x004f5680`.
- Raw bytes are recorded as:
  - `81 e9 a0 00 00 00 e9 0b 00 00 00`
  - `81 e9 a4 00 00 00 e9 00 00 00 00`
- Xrefs are vtable-only:
  - `0x0061d070` references `0x004f566a`.
  - `0x0061d0a0` references `0x004f5675`.
  - `0x0061d018` references scalar deleting destructor `0x004f5680`.
- No ordinary direct callers are recorded.
- The neighboring range boundary is exact: the previous `_AUTOBUF<unsigned char>` constructor ends at `0x004f566a`; the scalar deleting destructor starts at `0x004f5680`.

Corroborating support docs checked:

- [UID:0002PY] `LogoPlayerPaneScalarDeletingDestructor`: primary scalar wrapper at `0x004f5680`, reached directly from primary vtable slot `0x0061d018` and by both target thunks.
- [UID:0002PT] `LogoPlayerPaneCleanupDestructor`: source-authored cleanup body restores vtables at `+0`, `+0xa0`, and `+0xa4`, frees callback/AUTOBUF state, then chains to `VideoPlayerPane`.
- [UID:00019D] `LogoPlayerPane` aggregate: already records the target as two compiler adjustor thunks and the class-owned destructor island.
- [UID:0003OR] `LogoPlayerPaneVtableData`: primary table head `0x0061d018`, secondary table head `0x0061d070`, tertiary table head `0x0061d0a0`.
- [UID:00007H] `LogoPlayerPane` class: records the three vtable views and object fields at `+0x100` through `+0x114`.
- [UID:0000O4] `StartupLogoPanes` file: owns `LogoPlayerPane` source route.
- [UID:0000FV] / [UID:0001NT] / [UID:0002Z5] `VideoPlayerPane`: same three-view ABI shape and same `-0xa0` / `-0xa4` destructor adjustor-thunk pattern.
- [UID:0002PQ] `LogoPaneDeletingDestructorThunks`: direct policy precedent already cleaned to `RECONSTRUCTABLE:FALSE`, blank emitters, `ignored`, score `86/92`.
- [UID:0001VH] `PaneLayout`: explains the `Pane` object model: primary vptr at `+0`, secondary EventHandler view at `+0xa0`, tertiary timer/event handler view at `+0xa4`.
- [UID:00004N] `EventHandler`: confirms `+0xa0` is the inherited event-handler view used by pane dispatch, not a new `LogoPlayerPane` source method family.

Live MCP note: a fresh `127.0.0.1:13337/mcp` check was attempted on 2026-06-19, but the server was not reachable. This report relies on the prior live-IDA evidence already recorded in the target/support docs and on cross-doc reconciliation.

## Heuristic / Inference Reanalysis And Validation

Current target metadata says `RECONSTRUCTABLE:TRUE` with `EMITTER_UIDS:00007H`, but the body already admits these are compiler/linker-generated thunks and that no handwritten C++ should exist. That combination creates a stale source-quality state: the auto generator treats the range as a class-owned emitter even though the range has no source-level body.

The gate analysis should now be the 85/85 source-quality gate used for generated artifacts:

- Binary understanding is above threshold. Bounds, bytes, operands, tail targets, vtable slots, and no-caller status are all known.
- Source emission is not appropriate. The thunks contain no source-authored behavior beyond the ABI `this` adjustment.
- The right source artifact is not a function body; it is the `LogoPlayerPane` class declaration, inheritance layout, and destructor declaration/body in `StartupLogoPanes.cpp` / class headers.
- Therefore the range is documented and understood, but should be non-reconstructable as standalone C++.

The direct LogoPane precedent [UID:0002PQ] resolves the policy question. `LogoPane` has the same two 11-byte adjustor thunks, the same `-0xa0` and `-0xa4` adjustments, vtable-only references, and scalar deleting destructor target. It was corrected to `RECONSTRUCTABLE:FALSE`, blank emitters, and coverage status `ignored`. `0002PX` should match that policy.

## Multiple-Inheritance / Base-Layout Meaning

High-probability layout inference is strong enough for documentation:

- `0x0061d018` is the primary `LogoPlayerPane` vtable view at object offset `+0`.
- `0x0061d070` is the secondary view used when the object is addressed through the `Pane` / `EventHandler` embedded interface at object offset `+0xa0`.
- `0x0061d0a0` is the tertiary timer/event handler view at object offset `+0xa4`.
- A delete through the secondary view passes `this == object + 0xa0`; thunk `0x004f566a` subtracts `0xa0` to recover the complete object pointer and jumps to the scalar deleting destructor.
- A delete through the tertiary view passes `this == object + 0xa4`; thunk `0x004f5675` subtracts `0xa4` and jumps to the same scalar deleting destructor.

The offsets are not arbitrary decompiler artifacts. They match:

- `LogoPlayerPane` constructor/destructor vtable stores at `+0`, `+0xa0`, and `+0xa4`.
- `PaneLayout` primary/secondary/tertiary view documentation.
- `LogoPane` and `VideoPlayerPane` destructor-thunk pairs.
- `LogoPlayerPaneInputHandlers` evidence that event dispatch reaches the derived object through the `+0xa0` view.

Source class modeling should therefore preserve the pane inheritance/interface layout, not express these adjustments manually. No function named after `sub_4F566A`, `sub_4F5675`, or `LogoPlayerPaneDeletingDestructorThunk` should appear in source.

## Recommended Target Doc Changes

Header:

```diff
-COMPLETION:84
-CONFIDENCE:90
+COMPLETION:86
+CONFIDENCE:92
 CANONICAL_OWNER:00007H
-RECONSTRUCTABLE:TRUE
-EMITTER_UIDS:00007H
+RECONSTRUCTABLE:FALSE
+EMITTER_UIDS:
 EMITTER_POSITION_OPTIONAL:
```

Status / disposition wording:

- Keep `Entity kind: secondary-base deleting destructor adjustor thunks`.
- Change reconstruction disposition to: `Non-reconstructable as source. These are compiler-generated adjusted-this tail jumps produced from the LogoPlayerPane class declaration and virtual destructor; do not hand-write or emit C++ for this range.`
- Keep `CANONICAL_OWNER:00007H` for semantic containment and class-layout ownership, matching the `LogoPane` precedent that keeps class ownership while clearing emitter routing.
- Keep `RECONSTRUCTION_CPP` blank.

Add or replace a source-policy paragraph:

```text
Source policy: no standalone C++ should be emitted for this range. The two functions are exact MSVC deleting-destructor adjustor thunks: they adjust an incoming secondary/tertiary base pointer back to the complete LogoPlayerPane object and tail-jump to the scalar deleting destructor. The source-side requirement is an ordinary LogoPlayerPane class declaration/destructor in the StartupLogoPanes module, with the inherited Pane/EventHandler layout preserved, so the compiler regenerates the vtable slots and thunks.
```

Add or replace the layout paragraph:

```text
Layout meaning: vtable slot 0x0061d070 is the destructor entry for the object viewed at +0xa0, the Pane/EventHandler secondary view; vtable slot 0x0061d0a0 is the destructor entry for the object viewed at +0xa4, the tertiary timer/event view. The primary table slot at 0x0061d018 points directly to 0x004f5680. The thunks subtract 0xa0 or 0xa4 to recover the complete object pointer before entering 0x004f5680.
```

Replace stale reconstructable guidance:

```text
Do not mark this range reconstructable through a class emitter. Mark it non-reconstructable/ignored as compiler glue, and place the source declaration requirement on the LogoPlayerPane class/destructor/vtable docs instead.
```

Recommended score rationale:

```text
Score: 86/92. Bounds, bytes, vtable-only refs, scalar target, and layout offsets are known; no ordinary callers or source-authored behavior are present. Confidence is capped below final only because a fresh MCP session was unavailable for this B-pass, but existing live-IDA notes and parallel LogoPane/VideoPlayerPane evidence are sufficient to resolve source policy.
```

## Recommended Support-Doc Changes

`source-3/project-documentation/by-class/LogoPlayerPane.md`

- Update the method note for `0x004f566a-0x004f5680` to say it is non-reconstructable compiler ABI glue, not a class emitter.
- Add that the class declaration/destructor must preserve the `+0xa0` EventHandler secondary view and `+0xa4` tertiary timer/event view so MSVC regenerates the thunks.
- Remove or replace any wording that says generated source currently needs a handwritten fix for the thunk bodies.

`source-3/project-documentation/by-memory/0x004f53b0-0x004f570c.LogoPlayerPane.md`

- Update the child range entry for `0002PX` to `non-emitting compiler-generated destructor adjustor thunks`.
- Mention that the aggregate remains class-owned, but this child should be `RECONSTRUCTABLE:FALSE` with blank emitters.

`source-3/project-documentation/by-memory/0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor.md`

- Clarify that `0002PY` remains the destructor wrapper evidence page, while `0002PX` is non-reconstructable thunk glue.
- Keep the source action on the ordinary `LogoPlayerPane` destructor declaration/body; do not add explicit thunk C++.

`source-3/project-documentation/by-memory/0x0061d018-0x0061d0a8.LogoPlayerPaneVtableData.md`

- Add that secondary/tertiary destructor entries `0x0061d070` and `0x0061d0a0` point to non-emitting adjustor thunks `0002PX`.
- Keep the vtable data itself source-declared/generated-binary, regenerated from class declarations.

`source-3/project-documentation/by-file/StartupLogoPanes.md`

- Update migration/source cleanup notes to say `LogoPlayerPane` deleting-destructor adjustor thunks now follow the `LogoPane` no-code policy.
- No source file should contain an empty emitter marker or handwritten adjusted-this function for `0002PX`.

No required changes are recommended for `PaneLayout.md`, `EventHandler.md`, `VideoPlayerPane.md`, or `VideoPlayerPaneVtableData.md`; they already provide sufficient layout precedent. Optional cross-reference text may be added later if the supervisor wants stronger discoverability.

## Exact Pending Coverage Text

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` in this B-pass. If the supervisor accepts the report, replace the current `0002PX` row with exactly:

```text
        - [UID:0002PX][0x004f566a-0x004f5680.LogoPlayerPaneDeletingDestructorThunks](by-memory/0x004f566a-0x004f5680.LogoPlayerPaneDeletingDestructorThunks.md) 0x004f566a-0x004f5680 | compiler-generated thunks | LogoPlayerPaneDeletingDestructorThunks : ignored : 86% : strong : B009 2026-06-19 source-policy cleanup classifies the two `0xb` secondary/tertiary destructor adjustor thunks as non-emitting compiler glue: `0x004f566a` subtracts `0xa0`, `0x004f5675` subtracts `0xa4`, both tail-jump to [UID:0002PY][0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor](by-memory/0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor.md) `LogoPlayerPaneScalarDeletingDestructor`, vtable slots `0x0061d070/0x0061d0a0` are the only dispatch route, the primary scalar-deleting slot is `0x0061d018`, no ordinary direct callers exist, `+0xa0` is the Pane/EventHandler secondary view and `+0xa4` the tertiary timer/event view, and source should regenerate them from the `LogoPlayerPane` class declaration/destructor rather than handwritten C++.
```

Expected generated coverage effect after metadata and validator/autogen:

- `0002PX` moves from `emits` to `not_reconstructable` in `auto-generated/-ag-memory-coverage.md`.
- `auto-generated/NexusTK/app/StartupLogoPanes.cpp` no longer contains an empty emitter marker for `0002PX`.
- Project stats row becomes approximately `0002PX | 86 | 92 | 89.0`.

## Validator Needs

Suggested implementation-callback validation commands:

> Executable block R001 was removed from this report and preserved verbatim in [0002PX-LogoPlayerPaneDeletingDestructorThunks-source-quality-removed.md](0002PX-LogoPlayerPaneDeletingDestructorThunks-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor applies the coverage row replacement, also validate:

> Executable block R002 was removed from this report and preserved verbatim in [0002PX-LogoPlayerPaneDeletingDestructorThunks-source-quality-removed.md](0002PX-LogoPlayerPaneDeletingDestructorThunks-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Implementation Readiness

Ready. The implementation callback should be a documentation/metadata cleanup only:

- Change `0002PX` target metadata to non-reconstructable, blank emitters, `86/92`.
- Add no-code proof and layout interpretation.
- Update related class/aggregate/vtable/file notes to point source responsibility at the `LogoPlayerPane` class declaration/destructor.
- Replace the coverage row with the text above.
- Run validator/autogen.

No C++ body is ready or desired for this range. The first-draft C++ requirement is satisfied by proving that the correct source output is no standalone code and by identifying the class declaration/layout requirements that cause the compiler to regenerate these wrappers.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0002PX-LogoPlayerPaneDeletingDestructorThunks-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:33","uid":"0002PX"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002PX-LogoPlayerPaneDeletingDestructorThunks-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/0002PX-LogoPlayerPaneDeletingDestructorThunks-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002PX"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
