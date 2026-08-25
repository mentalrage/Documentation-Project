** TARGET-REPORT-UID:0002Q1 **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002Q1 BaramAppDeletingDestructorThunk Source Routing

Status: FINISHED
Assignment: B014-goal2-baramapp-deleting-destructor-thunk-source-routing-0002Q1-20260619

## Target

- Primary target: `source-3/project-documentation/by-memory/0x004f66b5-0x004f66bd.BaramAppDeletingDestructorThunk.md`
- UID: `0002Q1`
- Current metadata checked: `COMPLETION:82`, `CONFIDENCE:90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++.
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B014/research/0002Q1-BaramAppDeletingDestructorThunk-source-routing.md`

## Final Recommendation

Keep `0x004f66b5-0x004f66bd` ignored and non-emitting. It is a complete MSVC secondary-base deleting-destructor adjustor thunk, not a source-authored BaramApp method body:

```asm
004f66b5  83 e9 04          sub ecx,4
004f66b8  e9 03 00 00 00    jmp 0x004f66c0
```

Recommended target metadata:

```text
COMPLETION:86
CONFIDENCE:92
CANONICAL_OWNER:00000V
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
```

Rationale for raising the score: the target's bytes, bounds, only route, jump target, and class-layout implication are now resolved. Rationale for keeping it below 90 completion: the page remains no-code compiler glue, the full BaramApp source declaration/source-file partition is still provisional, the neighboring `0x004f66b0-0x004f66b5` compiler jump thunk is not separately modeled in coverage, and BaramApp's full vtable/source naming remains outside this target.

The recommended canonical owner is semantic rather than emitting: `BaramApp` owns the secondary vtable slot and the class declaration/destructor layout that causes this thunk to exist. Keep `RECONSTRUCTABLE:FALSE`, blank emitters, and blank C++ because handwritten source should not emit an adjustor-thunk body. If the supervisor prefers the existing ignored-thunk convention used by `ApplicationScalarDeletingDestructorThunk`, leaving `CANONICAL_OWNER:NONE` is defensible, but B014 recommends `00000V` because the BaramApp constructor installs the secondary vptr at `this+4` and the vtable slot at `0x0061d138` points only here.

## Evidence Checked

Repository and process files:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B014/goal.md`
- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/inference_research.md`
- `source-3/project-documentation/by-project-structure/proposed-source-tree.md`

Target and direct support docs:

- `by-memory/0x004f66b5-0x004f66bd.BaramAppDeletingDestructorThunk.md`
- `by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md` parent aggregate, UID `00019H`
- `by-class/BaramApp.md`
- `by-memory/0x004f5f20-0x004f5f4e.BaramAppConstructorRaw.md`
- `by-memory/0x004f66c0-0x004f66fb.BaramAppScalarDeletingDestructor.md`
- `by-memory/0x0061d118-0x0061d140.BaramAppVtableData.md`
- `by-memory/0x0061d118-0x0061d264.BaramAppReadOnlyData.md`
- `by-file/Application.md`
- `by-class/Application.md`
- `by-memory/0x00463970-0x004639c4.ApplicationDestructor.md`
- `by-memory/0x00467230-0x004672b7.ApplicationScalarDeletingDestructor.md`
- `by-memory/0x004671de-0x004671e6.ApplicationScalarDeletingDestructorThunk.md`
- `by-memory/0x004f52de-0x004f52f4.LogoPaneDeletingDestructorThunks.md`
- `by-memory/0x00465cb0-0x00465ce0.FatalErrorDialogAndBreak.md`
- `by-memory/-ignored.md`
- `by-memory/-coverage-report.md`
- `auto-generated/-ag-memory-coverage.md`

Prior B-agent report search:

- `rg` found no prior executed/current B001/B002/B014 report for `0002Q1`, `BaramAppDeletingDestructorThunk`, or `0x004f66b5`.

Tool availability:

- IDA MCP endpoint `http://127.0.0.1:13337/mcp` was unavailable during this pass (`Unable to connect to the remote server`), so this report relies on existing live-IDA-backed docs plus a direct read-only PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

Read-only PE scan:

- File: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Size: `2679296`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- SHA256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
- Image base: `0x00400000`
- Relevant sections:
  - `.text`: `0x00401000-0x0060c600`
  - `.rdata`: `0x0060d000-0x0066c200`

## Exact Bytes And Bounds

Direct PE bytes around the target:

```text
0x004f66a5: cc cc cc cc cc cc cc cc cc cc cc e9 bb d2 f6 ff 83 e9 04 e9 03 00 00 00 cc cc cc
```

Resolved local layout:

```text
0x004f66a5-0x004f66b0  padding, 11 bytes of 0xcc
0x004f66b0-0x004f66b5  separate 5-byte jump thunk: e9 bb d2 f6 ff -> 0x00463970
0x004f66b5-0x004f66bd  target 0002Q1: 83 e9 04 e9 03 00 00 00 -> sub ecx,4; jmp 0x004f66c0
0x004f66bd-0x004f66c0  padding, 3 bytes of 0xcc
0x004f66c0-0x004f66fb  BaramApp scalar deleting destructor
```

Important correction for support docs: `0x004f66b0-0x004f66b5` is not padding and is not part of `0002Q1`. It is an adjacent compiler cleanup jump thunk to `Application::~Application` at `0x00463970`. The parent aggregate currently does not model this five-byte range as a child row. Do not merge it into `0002Q1`; its route and target are different.

The target bounds `0x004f66b5-0x004f66bd` are correct. The thunk starts exactly after the adjacent `jmp 0x00463970` and ends before three bytes of `int3` padding.

## Route And Reachability

Direct PE xref scan results:

```text
dword hits for 0x004f66b5: 0x0061d138 only
dword hits for 0x004f66c0: 0x0061d118 only
rel32 hits to 0x004f66b5: none
rel32 hits to 0x004f66c0: 0x004f66b8 only
rel32 hits to 0x00463970: 0x004f5e44, 0x004f66b0, 0x004f66c6
```

BaramApp vtable bytes at `0x0061d118`:

```text
0x0061d118 -> 0x004f66c0  primary BaramApp scalar deleting destructor slot
0x0061d11c -> 0x004f4b10
0x0061d120 -> 0x0041b6c0
0x0061d124 -> 0x004f5fb0
0x0061d128 -> 0x004f6490
0x0061d12c -> 0x004669c0
0x0061d130 -> 0x00466a70
0x0061d134 -> 0x0064a014  secondary complete-object-locator pointer
0x0061d138 -> 0x004f66b5  secondary deleting-destructor adjustor thunk
0x0061d13c -> 0x00465ce0
```

The only inbound route to the target is the secondary BaramApp vtable slot at `0x0061d138`. There are no direct call/jump rel32 references to `0x004f66b5`. The thunk's only executable transfer is its tail jump to the primary/scalar deleting destructor at `0x004f66c0`.

The BaramApp constructor support page confirms the class installs:

- primary BaramApp vptr `0x0061d118` at `this+0`
- secondary BaramApp vptr `0x0061d138` at `this+4`

That constructor-side vptr write, the vtable slot, and the thunk's `sub ecx,4` all agree: callers using the secondary view pass `this+4`; the thunk adjusts back to the complete BaramApp object before tail-jumping to `0x004f66c0`.

## Jump Target 0x004f66c0

`0x004f66c0-0x004f66fb.BaramAppScalarDeletingDestructor.md` documents the target as the BaramApp scalar deleting destructor. Direct bytes show the thunk jumps into the beginning of that body:

```text
0x004f66c0: 55 8b ec 56 8b f1 e8 a5 d2 f6 ff ...
```

The scalar deleting destructor then delegates to `ApplicationDestructor` and performs MSVC delete-flag handling. The secondary thunk does not duplicate that logic; it only corrects `ecx` and transfers control.

## Class Layout And Source Declaration Implications

Best-supported class-layout inference:

- `BaramApp` has a complete-object view at offset `0`.
- A secondary base/interface view begins at offset `+4`.
- The secondary vtable has its own RTTI COL pointer at `0x0061d134`, followed by the secondary destructor slot at `0x0061d138`.
- The generated secondary deleting destructor adjusts `ecx` by `-4` to recover the complete object and then runs the normal BaramApp deleting destructor.

This is directly analogous to the documented Application secondary deleting destructor thunk at `0x004671de-0x004671e6`, which also uses `sub ecx,4; jmp scalar_deleting_destructor`. The BaramApp case differs only in the destination (`0x004f66c0`) and the owning secondary vtable slot (`0x0061d138`).

Source-level implication: model the relevant class declaration/destructor layout in `BaramApp`, not this thunk. The source compiler will generate this adjustor thunk from the inheritance layout. A human source tree should not contain an explicit function equivalent to:

```cpp
// Do not emit.
// this -= 4; jump to BaramApp scalar deleting destructor
```

## Ownership / Emitter Analysis

Accepted routing facts:

- Functional owner in source terms: `BaramApp`, because the thunk is reached from BaramApp's secondary vtable and corrects a BaramApp secondary view to the BaramApp complete object.
- Emitter: none. This is generated by the compiler from class layout/destructor metadata, not emitted as handwritten C++.
- Parent aggregate [UID:00019H] is a coverage container for BaramApp/Application startup/destructor support, not the source owner of this thunk.
- `Application` is not the owner of `0002Q1`; `0x004f66b5` jumps to BaramApp's scalar deleting destructor. The adjacent `0x004f66b0` thunk is the one that jumps directly to `Application::~Application`.

Rejected alternatives:

- Not source-authored BaramApp method code: no body beyond `this` adjustment and tail jump, no direct callers, and only a vtable slot route.
- Not the primary BaramApp destructor: primary destructor slot is `0x0061d118 -> 0x004f66c0`.
- Not Application-owned: the target adjusts a secondary BaramApp view and jumps to the BaramApp scalar deleting destructor; the separate neighboring `0x004f66b0` jump handles direct Application destructor cleanup.
- Not padding and not mergeable with `0x004f66b0`: direct bytes show two different code artifacts separated by exact boundaries.
- Not a candidate for first-draft C++: source declaration/layout should regenerate it.

## No-Code Proof

`0002Q1` should remain no-code because all source-observable behavior is represented by class layout and the real destructor path:

1. The target contains only a fixed `ecx -= 4` adjustment and an unconditional tail jump.
2. The only data route is BaramApp's secondary vtable destructor slot at `0x0061d138`.
3. There are no direct rel32 callers to the thunk.
4. The destination `0x004f66c0` is the body that performs destructor/delete behavior.
5. The constructor installs the secondary vptr at `this+4`, matching the adjustor delta exactly.
6. Explicit C++ for this thunk would be compiler-shaped glue, not plausible mid-2000s human source.

Formal C++ should remain blank for this target. The support docs should instead say that BaramApp's class declaration/destructor layout is expected to regenerate a secondary-base deleting-destructor adjustor thunk equivalent to `sub ecx,4; jmp 0x004f66c0`.

## Recommended Target Doc Changes

For `by-memory/0x004f66b5-0x004f66bd.BaramAppDeletingDestructorThunk.md`:

- Raise metadata to `COMPLETION:86`, `CONFIDENCE:92`.
- Set `CANONICAL_OWNER:00000V` if accepting semantic class ownership for ignored thunks; otherwise preserve `NONE` but add a note that BaramApp is the semantic source-layout owner.
- Keep `RECONSTRUCTABLE:FALSE`.
- Keep `EMITTER_UIDS:` blank.
- Keep formal C++ blank.
- Add exact direct bytes:
  - `83 e9 04 e9 03 00 00 00`
  - `sub ecx,4; jmp 0x004f66c0`
- Add route evidence:
  - no rel32 callers to `0x004f66b5`
  - sole absolute dword hit for `0x004f66b5` is `0x0061d138`
  - primary destructor slot `0x0061d118 -> 0x004f66c0`
  - tail jump at `0x004f66b8 -> 0x004f66c0`
- Add class-layout inference:
  - BaramApp constructor installs secondary vptr `0x0061d138` at `this+4`
  - thunk subtracts the same `4` to recover complete object
  - secondary vtable route is vtable-only
- Add adjacency correction:
  - `0x004f66b0-0x004f66b5` is separate `jmp 0x00463970`, not padding and not part of Q1.
- Replace any passive unresolved wording with the current no-code proof above.

## Recommended Support Doc Changes

`by-class/BaramApp.md`:

- Update the `0002Q1` child row to `86/92` and describe it as a BaramApp secondary-base deleting-destructor adjustor thunk.
- Add a concise note that constructor evidence places the secondary BaramApp view/vptr at `this+4`, and the thunk's `sub ecx,4` is the generated destructor adjustment for that view.
- Keep C++ blank at class level unless and until the full BaramApp declaration/source split is implemented; this target does not by itself justify hand-emitting class C++.

`by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md` [UID:00019H]:

- Correct the range narrative around `0x004f66a5-0x004f66c0`:
  - `0x004f66a5-0x004f66b0`: padding
  - `0x004f66b0-0x004f66b5`: separate compiler cleanup jump thunk to `Application::~Application` at `0x00463970`
  - `0x004f66b5-0x004f66bd`: BaramApp secondary deleting-destructor adjustor thunk
  - `0x004f66bd-0x004f66c0`: padding
- Add that `0x004f66b0-0x004f66b5` should be modeled as ignored compiler support or a small child page; it should not remain implicit padding.
- Update the `0002Q1` row/details to `86/92` if the target score is changed.

`by-memory/0x0061d118-0x0061d140.BaramAppVtableData.md`:

- Add direct PE reconfirmation that `0x0061d118` is the primary destructor slot to `0x004f66c0` and `0x0061d138` is the secondary destructor slot to `0x004f66b5`.
- Add that the secondary slot plus constructor vptr write support a secondary view at `this+4`.
- No C++ emission change; vtable data remains generated-binary support.

`by-memory/0x0061d118-0x0061d264.BaramAppReadOnlyData.md`:

- If touched for routing consistency, add the same concise secondary-vtable route note and no-code policy.

`by-memory/0x004f66c0-0x004f66fb.BaramAppScalarDeletingDestructor.md`:

- Add cross-reference that `0x004f66b5` is the secondary-base adjustor route into this scalar deleting destructor.
- No first-draft source body is recommended from this target alone.

`by-memory/0x00463970-0x004639c4.ApplicationDestructor.md`:

- Optional low-risk support note: `0x004f66b0-0x004f66b5` is an adjacent compiler jump thunk to this destructor in the BaramApp/Application startup cluster.

`by-memory/-ignored.md`:

- Keep the existing `0002Q1` ignored entry but refresh it with the PE scan route facts.
- Add a new ignored entry for `0x004f66b0-0x004f66b5` if the supervisor chooses not to create a dedicated child page.

Recommended ignored entry text for `0x004f66b0-0x004f66b5`:

```text
- `0x004f66b0-0x004f66b5` - Application destructor cleanup jump thunk in the BaramApp/Application startup cluster.
  - Why ignored: compiler-emitted five-byte jump-only cleanup thunk; direct bytes are `e9 bb d2 f6 ff`, transferring to [UID:0002GZ] `ApplicationDestructor` at `0x00463970`.
  - Evidence: B014 direct PE scan shows `0x004f66a5-0x004f66b0` is padding, `0x004f66b0-0x004f66b5` is this jump thunk, `0x004f66b5-0x004f66bd` is the BaramApp secondary deleting-destructor adjustor thunk, and `0x004f66bd-0x004f66c0` is padding.
  - Replacement: no standalone source; model the real `Application::~Application` body and compiler cleanup routing in the aggregate/support docs.
```

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` from this report. If the target score/route is accepted, replace the existing `0002Q1` row with:

```text
        - [UID:0002Q1][0x004f66b5-0x004f66bd.BaramAppDeletingDestructorThunk](by-memory/0x004f66b5-0x004f66bd.BaramAppDeletingDestructorThunk.md) 0x004f66b5-0x004f66bd | compiler-generated | BaramAppDeletingDestructorThunk : ignored : 86% : very strong : B014 source-routing recheck confirms exact `0x004f66b5-0x004f66bd` compiler-generated BaramApp secondary deleting-destructor adjustor thunk: bytes `83 e9 04 e9 03 00 00 00` (`sub ecx, 4; jmp 0x004f66c0`), no rel32 callers to the thunk, sole absolute dword hit `0x0061d138`, primary destructor slot `0x0061d118 -> 0x004f66c0`, and constructor/vtable evidence showing the secondary BaramApp view at `this+4`; keep non-emitting/no C++ because the source declaration/destructor layout regenerates it.
```

Recommended new adjacent ignored-support row under the same aggregate, placed before `0002Q1`:

```text
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004f66b0-0x004f66b5 | compiler-generated | ApplicationDestructorCleanupJumpThunk : ignored : 100% : strong : Direct PE scan shows bytes `e9 bb d2 f6 ff`, a five-byte jump to [UID:0002GZ][0x00463970-0x004639c4.ApplicationDestructor](by-memory/0x00463970-0x004639c4.ApplicationDestructor.md); it is adjacent compiler cleanup support between BaramApp shutdown padding and the BaramApp deleting-destructor adjustor thunk, not padding and not source-authored code.
```

If `0000VN` is not acceptable for an ignored-only row, assign a supervisor-owned UID or model this as an ignored ledger entry without a UID. The range should still be recorded because it is executable bytes, not padding.

## IDA Rename / Type / Comment Recommendations

High confidence:

- `0x004f66b5`: rename from `sub_4F66B5` to `BaramApp_secondary_deleting_destructor_adjustor` or keep the shorter doc name `BaramAppDeletingDestructorThunk`.
- `0x004f66b5` comment: `Secondary BaramApp deleting-destructor adjustor; ecx points at +4 secondary view, subtracts 4, tail-jumps to 0x004f66c0. Only referenced by vtable slot 0x0061d138.`
- `0x0061d138` comment: `BaramApp secondary vtable deleting-destructor slot -> 0x004f66b5 adjustor thunk.`
- `0x0061d118` comment: `BaramApp primary vtable deleting-destructor slot -> 0x004f66c0.`

Medium confidence / support cleanup:

- `0x004f66b0`: name/comment as `Application_destructor_cleanup_jump_thunk` or equivalent if the project creates a symbol for ignored jump-only code.
- `0x0061d13c`: leave current target/name untouched; this report only confirms it is a secondary BaramApp vtable slot following the destructor slot, not its source-facing role.

No source type should be assigned to `0x004f66b5`; at most record a compiler-generated thunk signature in IDA comments.

## Validation Commands Needed If Accepted

Run after implementation edits, from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0002Q1-BaramAppDeletingDestructorThunk-source-routing-removed.md](0002Q1-BaramAppDeletingDestructorThunk-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

Do not run a coverage-report edit from B014; keep the exact pending row text above for supervisor-owned application.

## Open Questions Closed Or Narrowed

- Exact thunk bytes/bounds: resolved. `0x004f66b5-0x004f66bd` is exact.
- Secondary BaramApp vtable route: resolved. Sole absolute dword route is `0x0061d138`.
- Jump target: resolved. Tail jump targets `0x004f66c0`, the BaramApp scalar deleting destructor.
- Class-layout implication: high-probability resolved. Secondary view at `this+4`; generated thunk adjusts by `-4`.
- Parent aggregate implication: resolved enough for support update. It currently misses executable bytes at `0x004f66b0-0x004f66b5`.
- Non-emitting policy: resolved. Keep no-code/ignored; model behavior through class layout and destructor docs.
- Source file placement: not finalized for BaramApp overall, but this target does not need a source file because it remains generated compiler glue.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/0002Q1-BaramAppDeletingDestructorThunk-source-routing.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"0002Q1"} -->
<!-- {"agent":"B014","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002Q1-BaramAppDeletingDestructorThunk-source-routing-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B014/0002Q1-BaramAppDeletingDestructorThunk-source-routing.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002Q1"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
