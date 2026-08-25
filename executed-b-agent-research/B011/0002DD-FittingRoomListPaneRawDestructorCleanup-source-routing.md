** TARGET-REPORT-UID:0002DD **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002DD FittingRoomListPaneRawDestructorCleanup Source-Routing Report

Status: FINISHED
Agent: B011
Assignment: B-only report for [UID:0002DD] `FittingRoomListPaneRawDestructorCleanup`

## Target Paths

- Target by-memory doc: `source-3/project-documentation/by-memory/0x0041ecc0-0x0041ecf5.FittingRoomListPaneRawDestructorCleanup.md`
- Required report: `source-3/project-documentation/tools/leaser/Agents/Agent-B011/research/0002DD-FittingRoomListPaneRawDestructorCleanup-source-routing.md`
- Related source/support docs checked:
  - `source-3/project-documentation/by-memory/0x0041eb90-0x0041ecbd.FittingRoomListPaneConstructor.md`
  - `source-3/project-documentation/by-memory/0x00421410-0x00421477.FittingRoomListPaneScalarDeletingDestructor.md`
  - `source-3/project-documentation/by-class/FittingRoomListPane.md`
  - `source-3/project-documentation/by-class/FittingRoomScrollPane.md`
  - `source-3/project-documentation/by-file/FittingRoom.md`
  - `source-3/project-documentation/by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md`
  - `source-3/project-documentation/by-memory/-ignored.md`
  - `source-3/project-documentation/by-memory/-coverage-report.md` read only
  - `source-3/project-documentation/auto-generated/NexusTK/cashshop/FittingRoom.cpp`

No by-* docs were edited. `by-memory/-coverage-report.md` was not edited.

## Recommendation

Keep [UID:0002DD] non-reconstructable/no-code. The best source-level explanation is not a standalone destructor method, not padding, and not a function to promote in IDA. It is a retained compiler cleanup island for `FittingRoomListPane`, most likely constructor-unwind / non-deleting complete-object cleanup material derived from the source destructor obligation to release the owned scroll child. The source-authored shape belongs with the normal `FittingRoomListPane` destructor path, currently represented in binary by [UID:0002DX] `0x00421410-0x00421477.FittingRoomListPaneScalarDeletingDestructor`.

Recommended target metadata:

```text
COMPLETION:86
CONFIDENCE:92
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
RECONSTRUCTION_CPP: blank
```

The higher score is justified because the no-code/source route is now target-specific: exact bytes, padding, no-entry evidence, duplicated destructor sequence, constructor child ownership, scalar destructor contrast, and vtable slot route all agree. I would not raise above this without recovered EH/unwind state records proving the precise compiler trigger.

## Evidence Checked

- Current target doc records 2026-06-05 live IDA MCP evidence: `0x0041ecc0` is not a function start, `0x0041ecbd` and `0x0041ecf5` are not function starts, `xrefs_to`/`callers` report no inbound xrefs/callers, decompilation fails at the raw start, and `0x0041ed00` is the next modeled function.
- Constructor doc records a 2026-06-16 C001 IDA refresh: `sub_41EB90` is exact `0x0041eb90-0x0041ecbd`, the sole direct constructor caller is `0x0041c01a`, the constructor allocates a `0x110` byte `FittingRoomScrollPane`, initializes it inline, stores it at `this+0x11c`, and the raw cleanup at `0x0041ecc0` still has no function/reachability promotion or VA/RVA pointer hits.
- Scalar deleting destructor doc records modeled `0x00421410-0x00421477`, vtable slot `0x0060dd10 -> 0x00421410`, adjustor thunk jumps at `0x004213e8` and `0x004213f3`, child release at `this+0x11c`, base teardown `0x00544580`, scalar-delete flag handling, optional object free `0x004f4ac0`, and compiler guard branch `0x0041b6a0`.
- `FittingRoomListPane` class doc confirms `this+0x11c` is the owned `FittingRoomScrollPane *m_scrollPane`; the same class owns the normal destructor semantics through [UID:0002DX], while [UID:0002DD] is only a raw cleanup body.
- `FittingRoomScrollPane` class doc confirms the child class is local to `FittingRoom.cpp`, has primary destructor coverage through the scroll-pane family wrapper, and is allocated inline by the list-pane constructor.
- `FittingRoom.md` confirms `FittingRoomListPane` and `FittingRoomScrollPane` source placement under `NexusTK/cashshop/FittingRoom.cpp`, while excluding generic Pane/EventHandler/TimerHandler helpers from direct fitting-room ownership.
- `FittingRoomUiCore.md` and `-ignored.md` already split the apparent `0x0041ecbd-0x0041ed00` gap into padding + raw cleanup + padding, but wording should be strengthened from generic compiler cleanup to the constructor-unwind/destructor-cleanup source route below.
- Read-only PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` confirmed image base `0x00400000`, `.text` range `0x00401000-0x0060c600`, and the exact raw bytes/disassembly below.

## Exact Bytes, Bounds, and Padding

Read-only PE bytes:

- `0x0041ecbd-0x0041ecc0`: `cc cc cc`, length `0x3`, SHA1 `0bd8a2794ea254b6c04eecd2fcbf1fa4fda439ae`
- `0x0041ecc0-0x0041ecf5`: length `0x35`, SHA1 `be360bf91101b8831316c4a26a584cacbaf3dce1`
- `0x0041ecf5-0x0041ed00`: eleven `cc` bytes, length `0xb`, SHA1 `655cd0df1b8fc741c6821d30b393e3e424860c6e`

Target bytes:

```text
56 8b f1 8b 8e 1c 01 00 00 c7 06 10 dd 60 00 c7
86 a0 00 00 00 78 dd 60 00 c7 86 a4 00 00 00 a8
dd 60 00 85 c9 74 06 8b 01 6a 01 ff 10 8b ce 5e
e9 8b 58 12 00
```

Disassembly:

```asm
0041ecc0  push esi
0041ecc1  mov esi, ecx
0041ecc3  mov ecx, dword ptr [esi + 0x11c]
0041ecc9  mov dword ptr [esi], 0x60dd10
0041eccf  mov dword ptr [esi + 0xa0], 0x60dd78
0041ecd9  mov dword ptr [esi + 0xa4], 0x60dda8
0041ece3  test ecx, ecx
0041ece5  je 0x41eced
0041ece7  mov eax, dword ptr [ecx]
0041ece9  push 1
0041eceb  call dword ptr [eax]
0041eced  mov ecx, esi
0041ecef  pop esi
0041ecf0  jmp 0x544580
```

The `0x0041ecf0 -> 0x00544580` tail jump is the base pane/control cleanup handoff. The child call uses the primary virtual slot of `m_scrollPane` with deleting flag `1`, matching ordinary C++ `delete m_scrollPane;` lowering.

## Route and Reference Findings

- PE text transfer scan found zero `call`/`jmp`/`jcc`/short-transfer hits to `0x0041ecc0`, `0x0041ecbd`, or `0x0041ecf5`.
- File-wide absolute dword scan found zero hits for values `0x0041ecc0`, `0x0041ecbd`, or `0x0041ecf5`.
- File-wide absolute dword scan found `0x00421410` only at `.rdata` slot `0x0060dd10`, confirming the modeled scalar deleting destructor is the primary vtable route rather than the raw cleanup island.
- Vtable dword values:
  - `[0x0060dd10] = 0x00421410`
  - `[0x0060dd78] = 0x004213e2`
  - `[0x0060dda8] = 0x004213ed`
- The only direct transfer route into the list destructor family is through [UID:0002DX]: `0x004213e8 -> 0x00421410` and `0x004213f3 -> 0x00421410`. There is no comparable route to [UID:0002DD].
- Absolute vtable-immediate hits for `0x0060dd10/0x0060dd78/0x0060dda8` appear at the constructor, raw cleanup, and scalar destructor write sites, proving all three bodies restore the same complete-object/facet vtables.

## Destructor Factoring

The source-owned destructor behavior is:

```cpp
FittingRoomListPane::~FittingRoomListPane()
{
    delete m_scrollPane;
}
```

This draft is for the class/destructor support docs or [UID:0002DX] source-shape guidance, not for [UID:0002DD]. The C++ source does not contain a separate callable method corresponding to `0x0041ecc0-0x0041ecf5`.

The compiler-lowered details that should not be hand-authored as source body are:

- vtable restores at complete-object primary offset `+0x0`, EventHandler-like adjusted facet `+0xa0`, and TimerHandler-like adjusted facet `+0xa4`;
- the null guard before deleting `m_scrollPane`;
- the virtual destructor call with deleting flag `1`;
- the base cleanup tail jump to `0x00544580`;
- any constructor-unwind landing/cleanup entry mechanics.

[UID:0002DX] contains the source destructor semantics plus MSVC scalar-deleting wrapper logic: it duplicates the child cleanup, calls the same base teardown, then handles deleting flags and optional free through `0x004f4ac0`. [UID:0002DD] contains only the non-deleting cleanup subset and has no vtable slot, no adjustor route, no scalar flags, no object-free path, and no external entry.

## Open Questions and Resolutions

| Question | Resolution |
| --- | --- |
| Should [UID:0002DD] become source-bearing because it is real code bytes? | No. It is real executable cleanup bytes, but no current IDA function, no inbound route, no vtable pointer, no pointer-table hit, and no decompiler function body exist. Source semantics are already represented by constructor ownership and the scalar destructor path. |
| Is it padding? | No. The padding is exactly `0x0041ecbd-0x0041ecc0` and `0x0041ecf5-0x0041ed00`. The middle `0x35` bytes are valid cleanup code. |
| Is it the ordinary destructor? | No as a standalone source row. The ordinary source destructor shape is `delete m_scrollPane;` and is represented by [UID:0002DX] / the class destructor route. This raw island is a no-code non-deleting cleanup fragment. |
| Is it a scalar deleting destructor or delete wrapper? | No. It lacks the MSVC delete-flags parameter, optional object-free path, guard branch, stack frame, and vtable-slot route present in [UID:0002DX]. |
| What is `this+0x11c`? | High confidence: `FittingRoomScrollPane *m_scrollPane`. Constructor [UID:0002DC] allocates and stores it, list methods use it for scroll synchronization, and both cleanup bodies delete it. |
| What are the vtable stores? | `0x0060dd10` is the primary `FittingRoomListPane` vtable slot whose first entry points to [UID:0002DX]; `0x0060dd78` and `0x0060dda8` are secondary/tertiary facet tables whose first entries are adjustor thunks to [UID:0002DX]. These stores are destructor-lowering artifacts, not handwritten source. |
| What is `0x00544580`? | High-confidence shared pane/control base teardown. Exact final source name is still a base-class documentation issue, but target routing does not depend on naming it more tightly. |
| Why is the exact compiler trigger not final? | No EH/unwind state table has been recovered that names this entry. The constructor adjacency, no-route status, non-deleting cleanup shape, and duplicate destructor subset make constructor-unwind/destructor-cleanup the best-supported inference. |

## Recommended Doc Changes

### Target [UID:0002DD]

1. Change metadata to `86/92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter list, blank formal C++.
2. Replace generic "compiler cleanup" wording with:
   - exact no-code classification as retained compiler non-deleting cleanup / likely constructor-unwind cleanup for `FittingRoomListPane`;
   - source-level reason: generated from `FittingRoomListPane::~FittingRoomListPane()` semantics, specifically `delete m_scrollPane`;
   - proof that the byte island has no standalone source method route.
3. Add the exact byte evidence:
   - pre-padding `0x0041ecbd-0x0041ecc0` is three `0xcc`;
   - target body `0x0041ecc0-0x0041ecf5` is `0x35` bytes with the disassembly above;
   - post-padding `0x0041ecf5-0x0041ed00` is eleven `0xcc`.
4. Add PE reference proof:
   - no text transfer or absolute VA hits to `0x0041ecc0`, `0x0041ecbd`, or `0x0041ecf5`;
   - vtable slot/adjustor route goes to [UID:0002DX], not [UID:0002DD].
5. State explicitly that no first-draft C++ belongs on this page.

### [UID:0002DC] Constructor

Add or refine a sentence in the raw cleanup discussion: the adjacent `0x0041ecc0` bytes are best treated as compiler constructor-unwind/destructor-cleanup support for the inline-owned `m_scrollPane`, not as a callable child method or ordinary constructor tail. The constructor remains source-authored and owns allocation/store of `m_scrollPane`.

### [UID:0002DX] Scalar Deleting Destructor

Keep reconstructable under [UID:000053]. Add that the source-facing ordinary destructor body is likely:

```cpp
FittingRoomListPane::~FittingRoomListPane()
{
    delete m_scrollPane;
}
```

Do not hand-author scalar-deleting flags, vtable restores, adjustor thunks, guard branch, or object-free call as gameplay/source logic. Contrast [UID:0002DD] as no-code non-deleting cleanup/unwind material.

### `FittingRoomListPane.md`

Update the [UID:0002DD] method-table row from "raw destructor/cleanup body" to "compiler non-deleting cleanup / likely constructor-unwind destructor cleanup". Add a boundary note that ordinary source destructor semantics are owned by the class destructor route and that [UID:0002DD] must remain formal-C++ blank.

### `FittingRoom.md`

In the `FittingRoomListPane` section, add a short lifecycle note:

- source destructor placement is with `FittingRoomListPane` in `NexusTK/cashshop/FittingRoom.cpp`;
- source destructor releases `m_scrollPane`;
- [UID:0002DD] is generated cleanup evidence only and should not appear as a source-emitting body;
- [UID:0002DX] is the vtable-routed scalar deleting destructor wrapper carrying the source destructor semantics.

### `FittingRoomUiCore.md`

Revise the covered-range row and boundary caution for [UID:0002DD] to say no-code compiler non-deleting cleanup / likely constructor-unwind cleanup, with exact padding/body split. Do not imply it is a normal method boundary.

### `FittingRoomScrollPane.md`

Optional support note only: the list-pane destructor/delete paths call the child through its primary virtual destructor with flag `1`; this is consistent with the child being an owned `FittingRoomScrollPane *` at `FittingRoomListPane +0x11c`.

### `by-memory/-ignored.md`

Update the [UID:0002DD] ignored entry from generic "destructor/exception-cleanup support" to the more specific source route: retained compiler non-deleting cleanup likely generated for constructor unwind/source destructor cleanup of `m_scrollPane`, with no entry refs and no formal source body.

## Exact No-Code Proof

[UID:0002DD] must remain blank formal C++ because all of the following are true:

1. It is not an IDA function and decompilation cannot produce a callable body at the raw start.
2. It has no inbound ordinary code transfers, no inbound absolute VA pointers, no vtable slot, and no adjustor thunk route.
3. It is immediately after the source constructor with `0xcc` padding before and after, a common placement for compiler-retained cleanup islands.
4. It duplicates only the non-deleting prefix of the real destructor wrapper [UID:0002DX].
5. It lacks delete flags, optional `operator delete`/free call, and return mechanics that make [UID:0002DX] the vtable-routed destructor wrapper.
6. Its meaningful source operation is already expressible once as `FittingRoomListPane::~FittingRoomListPane() { delete m_scrollPane; }`.
7. Hand-authoring [UID:0002DD] as a separate function would duplicate source destructor behavior and invent a source entry that the binary evidence does not support.

## Implementation Checklist

1. Edit target [UID:0002DD] metadata to `86/92`, owner `NONE`, reconstructable false, blank emitters, blank C++.
2. Replace the target Summary/Behavior/Reconstruction sections with the specific no-code proof above.
3. Add the current B011 PE byte/reference evidence and keep the existing live IDA no-function/no-xref evidence.
4. Update [UID:0002DC], [UID:0002DX], `FittingRoomListPane.md`, `FittingRoom.md`, `FittingRoomUiCore.md`, and optionally `FittingRoomScrollPane.md` / `-ignored.md` with the support wording above.
5. Do not add [UID:0002DD] to any emitter list and do not add formal C++ to the target.
6. Do not edit `by-memory/-coverage-report.md` directly; supervisor should apply the exact row below if accepting the score change.

## Coverage Row Text

Exact replacement row for `by-memory/-coverage-report.md`:

```text
        - [UID:0002DD][0x0041ecc0-0x0041ecf5.FittingRoomListPaneRawDestructorCleanup](by-memory/0x0041ecc0-0x0041ecf5.FittingRoomListPaneRawDestructorCleanup.md) 0x0041ecc0-0x0041ecf5 | raw cleanup | FittingRoomListPaneRawDestructorCleanup : ignored : 86% : very strong : Read-only PE recheck plus existing live IDA evidence confirm exact `0x35`-byte body, `0xcc` padding at `0x0041ecbd-0x0041ecc0` and `0x0041ecf5-0x0041ed00`, no function object, no inbound xrefs/rel32 transfers/VA pointer hits to `0x0041ecc0`, three list-pane vtable restores, owned `m_scrollPane` delete at `this+0x11c`, base-teardown tail jump `0x0041ecf0 -> 0x00544580`, and no-code constructor-unwind/destructor-cleanup routing through the source `FittingRoomListPane` destructor rather than a standalone method.
```

## Validation Commands Needed After Implementation

Run from `source-3/project-documentation` after the supervisor applies doc edits:

> Executable block R001 was removed from this report and preserved verbatim in [0002DD-FittingRoomListPaneRawDestructorCleanup-source-routing-removed.md](0002DD-FittingRoomListPaneRawDestructorCleanup-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

If only the target page and coverage row are updated, the minimum validator set is the target file plus `autogen --apply`. If support docs are edited, run the corresponding file-mode commands above.

## IDA Recommendations

- Do not create a function at `0x0041ecc0` without new EH/route evidence.
- Safe comment at `0x0041ecc0`: `compiler-generated FittingRoomListPane non-deleting cleanup / likely constructor-unwind destructor cleanup; deletes m_scrollPane then tails to pane base teardown; no standalone source body`.
- Safe comment at constructor [UID:0002DC] or near `0x0041ecbd`: `adjacent raw cleanup island is not constructor tail; see no-code 0002DD`.
- No rename recommendation for [UID:0002DD] as an IDA function. Keep source-facing destructor naming on [UID:0002DX] / `FittingRoomListPane::~FittingRoomListPane`.

## Residual Risk

The only remaining uncertainty is the exact compiler-emission trigger: full EH/unwind metadata has not been recovered. This does not block no-code classification because source routing is already proven by negative route evidence plus positive duplication of [UID:0002DX]'s destructor prefix. Impact is limited to wording: say "likely constructor-unwind/non-deleting cleanup" rather than "proven EH funclet" unless a future unwind-table pass confirms it.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/0002DD-FittingRoomListPaneRawDestructorCleanup-source-routing.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"0002DD"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002DD-FittingRoomListPaneRawDestructorCleanup-source-routing-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/0002DD-FittingRoomListPaneRawDestructorCleanup-source-routing.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002DD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
