** TARGET-REPORT-UID:0002PY **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B015 Source-Quality Report: [UID:0002PY] LogoPlayerPaneScalarDeletingDestructor

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0002PY] as the documented MSVC scalar deleting destructor wrapper for `LogoPlayerPane`, owned by [UID:00007H] `LogoPlayerPane` and routed through [UID:0000O4] `StartupLogoPanes`, but do not emit formal C++ for this target.
- Final disposition: source-declared/generated-binary wrapper around source-authored `LogoPlayerPane::~LogoPlayerPane()` cleanup. The ordinary destructor C++ should live on [UID:0002PT] `LogoPlayerPaneCleanupDestructor`, not in this wrapper page.
- Required target action if accepted: raise [UID:0002PY] from `84/90` to `87/92`, keep `CANONICAL_OWNER:00007H`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:00007H`, and replace stale "names not final-source quality" blocker text with the explicit no-code proof below.
- Formal C++ policy: leave [UID:0002PY] `RECONSTRUCTION_CPP CODE` blank. Do not hand-port the scalar deleting destructor flags, vtable rewrites, member/base teardown, or operator-delete branch as source C++.
- Confidence: very strong for wrapper behavior and no-code policy. Remaining uncertainty is limited to exact original field spellings and the missing constructor caller/concrete callback binding, not to wrapper ownership, behavior, or source placement.

## Target

- Target UID: `0002PY`
- Target path: `source-3/project-documentation/by-memory/0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor.md`
- Required B015 report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B015/research/0002PY-LogoPlayerPaneScalarDeletingDestructor-source-quality.md`
- Current metadata: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:00007H`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007H`, formal C++ blank.
- Current generated route: `0002PY -> 00007H LogoPlayerPane -> 0000O4 StartupLogoPanes -> auto-generated/NexusTK/app/StartupLogoPanes.cpp`, with no assembled code.
- Current coverage row state: reconstructable scalar deleting destructor, `84%`, strong, final C++ blank.

## Evidence Checked

- Required workflow docs:
  - `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B015/goal.md`
  - `.codex/AGENTS.md`
  - `source-3/project-documentation/by-structure.md`
  - `source-3/project-documentation/inference_research.md`
  - `source-3/project-documentation/by-project-structure/proposed-source-tree.md`
- Primary target/support docs:
  - [UID:0002PY] `LogoPlayerPaneScalarDeletingDestructor`
  - [UID:0002PT] `LogoPlayerPaneCleanupDestructor`
  - [UID:0002PX] `LogoPlayerPaneDeletingDestructorThunks`
  - [UID:0002PS] `LogoPlayerPaneConstructor`
  - [UID:00019D] `LogoPlayerPane` aggregate
  - [UID:00007H] `LogoPlayerPane` class
  - [UID:0000O4] `StartupLogoPanes` file
  - [UID:0003OR] `LogoPlayerPaneVtableData`
- Reconciled neighbors/dependencies:
  - [UID:0002PU] `LogoPlayerPaneAdvanceToNextSegment`
  - [UID:0002PV] `LogoPlayerPaneInputSkipHandlers`
  - [UID:0002PW] `LogoPlayerPaneOnClose`
  - [UID:0000FV], [UID:0000P4], and [UID:0001NT] `VideoPlayerPane`
  - [UID:0001WN], [UID:0000HM], [UID:00019E], [UID:000188], and [UID:0002MR] `AUTOBUF<unsigned char>`
  - [UID:00005L] `FunctionObject0` and [UID:0000JO] `FunctionObjects`
  - [UID:000195] `LObjectRuntimeShell`, [UID:00007D] `LObject`, and [UID:000197] `OperatorDeleteWrapper`
  - [UID:00025O] `LObjectLogoReadOnlyData`
  - Accepted sibling policy docs [UID:0002PM], [UID:0002PQ], and [UID:0002PR] for `LogoPane` destructor cleanup/thunks/scalar wrapper.
- Generated/project state checked:
  - `by-memory/-coverage-report.md` current rows for `00019D`, `0002PT`, `0002PX`, and `0002PY`
  - `auto-generated/-ag-memory-coverage.md` current rows for the LogoPlayerPane island
  - `project-level/-auto-completion-stats.md` current target score row
  - `auto-generated/NexusTK/app/StartupLogoPanes.cpp` empty marker state for `0002PY`
  - `project-level/-resolved.md` / `-unresolved.md` generated-name entries for `sub_4F5680`, `sub_4F4A90`, `sub_4F4AC0`, and `sub_5C0090`
- Prior B reports:
  - [UID:0002PV] B001 executed report for input handlers.
  - [UID:0002PW] B003 executed report for `LogoPlayerPane::OnClose`.
  - Accepted `LogoPane` destructor/thunk policy already present in current docs.
- IDA MCP state:
  - Current-session request to `http://127.0.0.1:13337/mcp` failed with `Unable to connect to the remote server`.
  - This report therefore uses existing IDA-backed documentation plus current raw PE checks.
- Raw PE checked:
  - `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
  - SHA-256: `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`
  - PE sections parsed from headers: `.text` `0x00401000-0x0060c4ac`, `.rdata` `0x0060d000-0x0066c0be`, `.data` `0x0066d000-0x0069ce24`.

## Current-Session Raw PE Check

Raw mapping for [UID:0002PY]:

- VA range: `0x004f5680-0x004f570c`
- File offset: `0x000f4a80`
- Length: `0x8c`, 140 decimal (Verified with `tools/int_convert.py`)
- Following alignment: `0x004f570c-0x004f5710` is four `0xcc` bytes before [UID:00022T]/[UID:0003K6] startup-logo playback code.

Raw bytes for `0x004f5680-0x004f570c` plus the four following padding bytes:

```text
55 8b ec 57 8b f9 8b 8f 0c 01 00 00 c7 07 18 d0 61 00 c7 87 a0 00 00 00 70 d0 61 00 c7 87 a4 00 00 00 a0 d0 61 00 85 c9 74 06 8b 01 6a 01 ff 10 56 ff b7 04 01 00 00 c7 87 00 01 00 00 68 b8 61 00 e8 d3 20 0d 00 83 c4 04 8d 8f 00 01 00 00 e8 bc f3 ff ff 8b cf e8 b5 a9 0c 00 8b 45 08 5e a8 01 74 22 a8 04 75 10 57 e8 d3 f3 ff ff 83 c4 04 8b c7 5f 5d c2 04 00 68 18 01 00 00 57 e8 9e 5f f2 ff 83 c4 08 8b c7 5f 5d c2 04 00 cc cc cc cc
```

Capstone disassembly from the raw PE:

```asm
0x004f5680 push ebp
0x004f5681 mov ebp, esp
0x004f5683 push edi
0x004f5684 mov edi, ecx
0x004f5686 mov ecx, dword ptr [edi + 0x10c]
0x004f568c mov dword ptr [edi], 0x61d018
0x004f5692 mov dword ptr [edi + 0xa0], 0x61d070
0x004f569c mov dword ptr [edi + 0xa4], 0x61d0a0
0x004f56a6 test ecx, ecx
0x004f56a8 je 0x4f56b0
0x004f56aa mov eax, dword ptr [ecx]
0x004f56ac push 1
0x004f56ae call dword ptr [eax]
0x004f56b0 push esi
0x004f56b1 push dword ptr [edi + 0x104]
0x004f56b7 mov dword ptr [edi + 0x100], 0x61b868
0x004f56c1 call 0x5c7799
0x004f56c6 add esp, 4
0x004f56c9 lea ecx, [edi + 0x100]
0x004f56cf call 0x4f4a90
0x004f56d4 mov ecx, edi
0x004f56d6 call 0x5c0090
0x004f56db mov eax, dword ptr [ebp + 8]
0x004f56de pop esi
0x004f56df test al, 1
0x004f56e1 je 0x4f5705
0x004f56e3 test al, 4
0x004f56e5 jne 0x4f56f7
0x004f56e7 push edi
0x004f56e8 call 0x4f4ac0
0x004f56ed add esp, 4
0x004f56f0 mov eax, edi
0x004f56f2 pop edi
0x004f56f3 pop ebp
0x004f56f4 ret 4
0x004f56f7 push 0x118
0x004f56fc push edi
0x004f56fd call 0x41b6a0
0x004f5702 add esp, 8
0x004f5705 mov eax, edi
0x004f5707 pop edi
0x004f5708 pop ebp
0x004f5709 ret 4
```

Current-session raw route scan:

- Raw little-endian pointer hits to `0x004f5680`: exactly one hit at file offset `0x0021ba18`, mapped to `.rdata` VA `0x0061d018`, the primary `LogoPlayerPane` vtable base.
- Raw rel32 `call`/`jmp` hits to `0x004f5680`: exactly two `jmp` hits, at VA `0x004f5670` and `0x004f567b`, both inside [UID:0002PX] deleting-destructor thunks.
- No ordinary direct `call` route was found in `.text`.

This raw check independently confirms the stored IDA evidence: the scalar wrapper is vtable/thunk reachable only, not ordinary handwritten call-reachable source logic.

## Heuristic / Inference Reanalysis And Validation

### 1. Source-quality policy for the scalar deleting destructor

Best policy: document [UID:0002PY] as source-declared/generated-binary scalar deleting destructor wrapper; do not emit formal C++ for the wrapper. Emit ordinary destructor source through [UID:0002PT] instead.

Evidence:

- [UID:0002PY] has the MSVC deleting-destructor signature shape: `this` in `ecx`, delete flags in stack argument, returns the original object pointer, and ends in `ret 4`.
- It is reached by the primary `LogoPlayerPane` vtable slot `0x0061d018` and by two adjusted-this thunks from [UID:0002PX]. There are no ordinary direct callers.
- It performs compiler lowering around cleanup: restore vtables, release callback, run member/base teardown, then branch on delete flags and optional object storage free.
- The same source-policy pattern has already been accepted for [UID:0002PR] `LogoPaneScalarDeletingDestructor`: keep the scalar wrapper documented and reconstructable as generated-binary evidence, but keep its formal C++ blank because the source body lives in [UID:0002PM] `LogoPaneCleanupDestructor`.
- The adjacent `LogoPane` deleting thunks [UID:0002PQ] were reclassified as `RECONSTRUCTABLE:FALSE`, blank emitter, because they are pure adjusted-this tail jumps. The same pure-thunk policy should apply to [UID:0002PX].

Rejected alternatives:

- Populate [UID:0002PY] with C++ equivalent to the full wrapper. Rejected: that would hand-port compiler ABI glue and duplicate automatic destructor/member/base/operator-delete lowering.
- Populate [UID:0002PY] with `LogoPlayerPane::~LogoPlayerPane()`. Rejected: the wrapper page range is not the ordinary source destructor body; [UID:0002PT] is the correct ordinary destructor source range.
- Mark [UID:0002PY] as a dead or ignored thunk. Rejected: unlike [UID:0002PX], this wrapper includes the full derived cleanup sequence and is the primary vtable deleting-destructor entry. It remains rebuild-relevant generated-binary evidence for the `LogoPlayerPane` destructor declaration.

Final direction:

- [UID:0002PY] should remain `RECONSTRUCTABLE:TRUE`, owner/emitter [UID:00007H], but formal C++ must stay blank with a written no-code proof.
- [UID:0002PT] should carry the ordinary destructor C++:

```cpp
LogoPlayerPane::~LogoPlayerPane()
{
    delete m_completionCallback;
}
```

The buffer/member and base destructors are automatic compiler lowering from the class declaration.

### 2. Ordinary destructor source body and callback release

Best source-facing callback field:

```cpp
FunctionObject0* m_completionCallback; // LogoPlayerPane +0x10c
```

Best ordinary destructor source:

```cpp
LogoPlayerPane::~LogoPlayerPane()
{
    delete m_completionCallback;
}
```

Evidence:

- [UID:0002PS] constructor stores the second constructor argument at `this + 0x10c`.
- [UID:0002PW] `OnClose` invokes the same pointer through callback vtable slot `+0x0c`, now documented as `FunctionObject0::Invoke`.
- [UID:0002PT] and [UID:0002PY] both test `this + 0x10c`; when non-null, both push deleting flag `1` and call callback vtable slot `+0x00`.
- [UID:0000JO] `FunctionObjects` and [UID:00005L] `FunctionObject0` document the zero-argument callback family and match this `+0x00` destructor / `+0x0c` invoke pattern.

Inference:

- The source did not need `if (m_completionCallback)` explicitly; C++ `delete` on a pointer compiles to a null guard before invoking the virtual deleting destructor. The binary null test is compatible with source `delete m_completionCallback;`.
- The exact concrete callback template remains open because the `LogoPlayerPane` constructor caller/allocation route is still missing. That does not block the destructor source body because the destructor only needs the base callback interface pointer.

Rejected alternatives:

- `LogoPlayerPaneCallback*`: no distinct vtable/RTTI/constructor evidence.
- Raw function pointer/member-function pointer: contradicted by vtable deletion and `Invoke` calls.
- Leave callback type unknown: no longer justified after [UID:0002PW] and FunctionObjects support evidence.

### 3. AUTOBUF field and destructor behavior

Best field direction:

```cpp
AUTOBUF<unsigned char> m_segmentBuffer; // LogoPlayerPane +0x100
```

Field model:

| Offset | Best source field meaning |
| --- | --- |
| `+0x100` | embedded `_AUTOBUF<unsigned char>` object vptr |
| `+0x104` | `m_segmentBuffer` payload pointer |
| `+0x108` | `m_segmentBuffer` byte count |

Evidence:

- [UID:0002PS] constructs or inlines construction of the embedded AUTOBUF at `+0x100`, clears pointer/count fields at `+0x104/+0x108`, reads file payload into it, and stores first segment size separately at `+0x114`.
- [UID:0001WN] / [UID:00019E] / [UID:000188] document `_AUTOBUF<unsigned char>` as a concrete utility/template object with vptr at `+0x00`, payload pointer at `+0x04`, and count at `+0x08`.
- [UID:0002PY] restores AUTOBUF vtable `0x0061b868` at `+0x100`, frees `[this+0x104]`, then calls `0x004f4a90` on `this+0x100` to run the `LObject`-compatible destructor body.

Source policy:

- Do not emit explicit `free(m_segmentBuffer.data)` in `LogoPlayerPane::~LogoPlayerPane()`.
- Do not emit explicit `m_segmentBuffer.~AUTOBUF<unsigned char>()` unless the project later chooses to represent compiler-inserted member destructors inside memory-page source. The accepted `LogoPane` destructor policy excludes automatic member/base destructor calls from the handwritten destructor block.
- The class declaration/member field should cause the compiler to generate the AUTOBUF teardown.

Rejected alternatives:

- Treat the AUTOBUF as a pointer field: contradicted by the vptr stored at `LogoPlayerPane +0x100`.
- Treat the AUTOBUF helper at [UID:00019E] as `LogoPlayerPane` source: contradicted by direct caller evidence from `MapPane::LoadMapFromFile` and 21 cross-feature `_AUTOBUF<unsigned char>` vtable references.
- Leave the field anonymous: not necessary for this target; `m_segmentBuffer` is a defensible descriptive name for the segmented startup movie payload buffer.

### 4. Base `VideoPlayerPane` teardown

Best source interpretation: [UID:0002PY] calls the non-deleting `VideoPlayerPane` destructor body at `0x005c0090` as compiler-generated base destructor lowering.

Evidence:

- [UID:0001NT] identifies `0x005c0090-0x005c010a` as the non-deleting video-pane destructor body: restores `VideoPlayerPane` vtables, unregisters `term`, closes the Bink handle at `+0xfc`, and tears down base `Pane`.
- [UID:0002PT] tail-jumps to `0x005c0090`; [UID:0002PY] calls it directly after AUTOBUF/LObject member teardown.
- [UID:0000FV]/[UID:0000P4] keep the generic Bink playback teardown in `VideoPlayerPane`, not in `LogoPlayerPane`.

Source policy:

- Do not write `VideoPlayerPane::~VideoPlayerPane()` explicitly in `LogoPlayerPane::~LogoPlayerPane()`. It is automatic base-class teardown.
- Do mention the dependency in [UID:0002PY] and [UID:0002PT] so generated `class_LogoPlayerPane.cpp` does not keep mis-owning `0x005c0090`.

Rejected alternatives:

- Own `0x005c0090` under `StartupLogoPanes`: rejected for direct source ownership. `LogoPlayerPane` is a caller/derived consumer, but `VideoPlayerPane` owns the base Bink handle lifetime.
- Leave the helper as `sub_5C0090`: rejected. Current docs support `VideoPlayerPane` non-deleting destructor body as the best descriptive name.

### 5. Project delete helper and deleting-destructor flags

Best helper name: [UID:000197] `OperatorDeleteWrapper`, the MemoryMan-backed global/project `operator delete` wrapper at `0x004f4ac0`.

Observed [UID:0002PY] flag policy:

- If `(flags & 0x1) == 0`, cleanup runs but object storage is not freed.
- If `(flags & 0x1) != 0` and `(flags & 0x4) == 0`, the wrapper calls `OperatorDeleteWrapper(this)`.
- If `(flags & 0x1) != 0` and `(flags & 0x4) != 0`, the wrapper pushes `0x118` and `this` to the guard/vector-delete path at `0x0041b6a0`, then returns without calling `OperatorDeleteWrapper`.

Conversions verified with `tools/int_convert.py`:

- `0x1` is 1 decimal.
- `0x4` is 4 decimal.
- `0x118` is 280 decimal.

Inference:

- `0x118` is the derived `LogoPlayerPane` object size. It matches fields through `+0x114` plus a 4-byte first-segment-size field: `0x118` total.
- The bit-4 branch is compiler deleting-destructor/vector/guard-mode glue, not handwritten source.

Rejected alternatives:

- Treat `0x004f4ac0` as `LogoPlayerPane` member delete. Rejected: [UID:000197] documents broad MemoryMan-backed global `operator delete` behavior and thousands of callers.
- Reconstruct flag tests in source C++. Rejected: scalar deleting destructor flags are ABI lowering.

### 6. Vtable restore roles

Observed stores:

| Address | Store | Meaning |
| --- | --- | --- |
| `0x004f568c` | `[this+0x00] = 0x0061d018` | restore primary `LogoPlayerPane` vtable |
| `0x004f5692` | `[this+0xa0] = 0x0061d070` | restore secondary Pane/EventHandler view |
| `0x004f569c` | `[this+0xa4] = 0x0061d0a0` | restore tertiary adjusted view |

Evidence:

- [UID:0003OR] documents `0x0061d018-0x0061d0a8` as exact `LogoPlayerPane` vtable data, with heads at `0x0061d018`, `0x0061d070`, and `0x0061d0a0`.
- [UID:0002PS], [UID:0002PT], and [UID:0002PY] all write the same three views.
- [UID:0002PX] uses the `+0xa0` and `+0xa4` adjusted views as destructor thunk sources.

Source policy:

- Do not emit these vtable stores in C++; the compiler generates them from class layout/destructor lowering.
- Keep them in the documentation evidence because they prove owner, multiple-view layout, and wrapper identity.

### 7. Source placement and ownership

Accepted:

- Direct semantic owner: [UID:00007H] `LogoPlayerPane`.
- Source route: [UID:00007H] -> [UID:0000O4] `StartupLogoPanes` -> `NexusTK/app/StartupLogoPanes.cpp`.

Evidence:

- `0x0061d018` primary `LogoPlayerPane` vtable slot points to this scalar deleting destructor.
- The two [UID:0002PX] thunks subtract `0xa0` and `0xa4` from secondary/tertiary interface views and tail-jump here.
- The wrapper releases `LogoPlayerPane` fields (`m_completionCallback`, embedded AUTOBUF segment buffer), then delegates to `VideoPlayerPane` base teardown.
- [UID:0000O4] owns startup logo/video sequencing and already routes `LogoPlayerPane` under `NexusTK/app/StartupLogoPanes.cpp`.

Rejected direct owners:

- [UID:0000FV] / [UID:0000P4] `VideoPlayerPane`: owns `0x005c0090` base teardown and Bink frame pump, not the derived wrapper/fields.
- [UID:0000HM] `AUTOBUF`: owns utility/template support, not the embedded member's containing class destructor.
- [UID:0000JO] `FunctionObjects`: owns the callback interface/template, not the `LogoPlayerPane` field release site.
- [UID:000197] / [UID:0000L7] `MemoryMan`: owns operator delete implementation, not this caller.
- New source file: not needed. The wrapper is a `LogoPlayerPane` method artifact in the already-supported startup-logo module.

### 8. Compiler-generated/raw names to resolve

Recommended source-quality names:

| Raw/generated name | Recommended descriptive name | Ownership |
| --- | --- | --- |
| `sub_4F5680` | `LogoPlayerPaneScalarDeletingDestructor` | [UID:00007H] wrapper evidence, no formal C++ |
| `sub_4F5510` raw body | `LogoPlayerPane::~LogoPlayerPane()` / `LogoPlayerPaneCleanupDestructor` | [UID:0002PT], ordinary source destructor C++ |
| `sub_4F566A` / `sub_4F5675` | `LogoPlayerPane` deleting destructor adjustor thunks | [UID:0002PX], compiler generated, should be non-emitting |
| `sub_4F4A90` | `LObjectDestructorBody` / embedded `LObject` teardown | [UID:000370] via [UID:000195] |
| `sub_4F4AC0` | `OperatorDeleteWrapper` / project `operator delete` | [UID:000197] |
| `sub_5C0090` | `VideoPlayerPane` non-deleting destructor body | [UID:0001NT] |
| `j_j_j___free_base` / `0x005c7799` | CRT/free helper used by AUTOBUF destructor lowering | runtime/helper dependency, not a `LogoPlayerPane` method |
| `0x0041b6a0` guard path | guard/vector-delete support path for bit `0x4` | compiler/runtime glue |

No unresolved generated/raw name remains that should block [UID:0002PY] source-policy cleanup.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Source policy | Direct owner | Status |
| --- | --- | --- | --- | --- | --- |
| `0x004f53b0-0x004f5500` | [UID:0002PS] `LogoPlayerPaneConstructor` | source constructor | source-authored, first C++ still blocked by caller/helper names | [UID:00007H] | support evidence |
| `0x004f5510-0x004f556a` | [UID:0002PT] `LogoPlayerPaneCleanupDestructor` | ordinary non-deleting destructor body | should carry `LogoPlayerPane::~LogoPlayerPane()` first-draft source | [UID:00007H] | recommended support update |
| `0x004f5570-0x004f55c8` | [UID:0002PU] `AdvanceToNextSegment` | skip to second segment | source-authored; C++ blocked by helper/field names | [UID:00007H] | support evidence |
| `0x004f55d0-0x004f561d` | [UID:0002PV] input handlers | key/mouse skip virtuals | source-authored; C++ blank pending event declarations | [UID:00007H] | already improved |
| `0x004f5620-0x004f5634` | [UID:0002PW] `OnClose` | close/completion virtual | source-authored; first-draft C++ already emitted | [UID:00007H] | support evidence |
| `0x004f5640-0x004f566a` | [UID:00019E] AUTOBUF constructor | utility/template constructor | AUTOBUF support, not `LogoPlayerPane` method | [UID:00000P] | support evidence |
| `0x004f566a-0x004f5680` | [UID:0002PX] deleting thunks | adjusted-this tail jumps | pure compiler glue, recommend `RECONSTRUCTABLE:FALSE` | [UID:00007H] evidence only | recommended support update |
| `0x004f5680-0x004f570c` | [UID:0002PY] scalar deleting destructor | deleting wrapper | keep reconstructable/generated-binary, formal C++ blank | [UID:00007H] | primary target |
| `0x0061d018-0x0061d0a8` | [UID:0003OR] vtable data | primary/secondary/tertiary tables | source-declared/generated-binary | [UID:00007H] | support evidence |

## First-Draft C++ / No-Code Proof

### [UID:0002PY] Target C++ Recommendation

Formal [UID:0002PY] `RECONSTRUCTION_CPP CODE` should remain blank.

Exact no-code proof:

- This range is the MSVC scalar deleting destructor wrapper, not a source-authored ordinary method body.
- Its explicit delete-flag parameter, `ret 4`, `(flags & 1)` / `(flags & 4)` tests, optional `OperatorDeleteWrapper` call, and guard-size path are compiler ABI details.
- Its vtable rewrites and calls to `_AUTOBUF<unsigned char>` member teardown and `VideoPlayerPane` base teardown are compiler destructor lowering.
- The ordinary destructor source is represented by [UID:0002PT]. Emitting a body here would either duplicate [UID:0002PT] or incorrectly require handwritten compiler ABI code.

Do not add:

```cpp
// Do not add a source-level scalar deleting destructor body here.
```

as formal emitted source unless the supervisor explicitly wants a comment marker for special no-code emitters. Semantically, the correct source output for this target is no source text.

### [UID:0002PT] Ordinary Destructor Source Recommendation

If the supervisor accepts this report, [UID:0002PT] is ready for first-draft ordinary destructor C++:

```cpp
LogoPlayerPane::~LogoPlayerPane()
{
    delete m_completionCallback;
}
```

Rationale:

- `delete m_completionCallback;` explains the destructor slot `+0x00` call with flag `1` and the binary null guard.
- The embedded AUTOBUF cleanup and `VideoPlayerPane` base cleanup should remain compiler-generated lowering, not explicit user code.
- This mirrors the accepted [UID:0002PM] `LogoPane::~LogoPane()` policy: the ordinary destructor page contains only source-authored cleanup, while member/base/scalar wrapper mechanics are documented as generated.

## Recommended Exact Target Changes

### Metadata

Replace [UID:0002PY] metadata with:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007H | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007H | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Leave formal C++ blank:

```text
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### Status / Reconstruction Notes Replacement

Replace the target's current "Reconstruction Notes" paragraph that says final C++ is blank because names are not final-source quality with:

```text
Keep this page as the MSVC scalar deleting destructor wrapper for `LogoPlayerPane`. The source representation is the class destructor declaration plus the ordinary destructor body documented by [UID:0002PT]. This wrapper is reachable only through the primary `LogoPlayerPane` vtable slot and the two adjusted-this destructor thunks; no ordinary direct code caller exists.

Formal C++ remains intentionally blank as an explicit no-code decision. The wrapper's delete flags, vtable restores, automatic `_AUTOBUF<unsigned char>` member teardown, automatic `VideoPlayerPane` base teardown, optional project `operator delete`, and guard-size branch are compiler-generated ABI/destructor lowering. Do not hand-port those mechanics into source C++. If accepted, the ordinary destructor source body belongs in [UID:0002PT] as `LogoPlayerPane::~LogoPlayerPane() { delete m_completionCallback; }`.
```

### Behavior / Source-Quality Insert

Add or replace behavior details with:

```text
The completion callback field is best documented as `FunctionObject0* m_completionCallback` at `this + 0x10c`. The constructor stores the second constructor argument there, [UID:0002PW] invokes it through callback slot `+0x0c`, and both destructor paths release it by calling callback slot `+0x00` with deleting flag `1` when the pointer is non-null.

The embedded buffer at `this + 0x100` is best documented as an `AUTOBUF<unsigned char>` member, tentatively `m_segmentBuffer`. The scalar wrapper restores the AUTOBUF vtable `0x0061b868`, frees the payload pointer at `this + 0x104`, then calls the embedded `LObject` destructor body at `0x004f4a90`. This is automatic member-destructor lowering, not handwritten `LogoPlayerPane` source.

The call to `0x005c0090` is automatic base-class destructor lowering for `VideoPlayerPane::~VideoPlayerPane()`. [UID:0001NT] owns the base video teardown, including `term` unregistration and Bink handle close.

The final flag path is compiler deleting-destructor ABI: no storage free when bit `0x1` is clear, project `OperatorDeleteWrapper` at `0x004f4ac0` when bit `0x1` is set and bit `0x4` is clear, and the guard/vector-delete path at `0x0041b6a0` with size `0x118` when bit `0x4` is set.
```

### Raw Evidence Insert

Add this current-session evidence block:

```text
2026-06-19 B015 raw PE recheck against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` (SHA-256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`) parsed the PE sections and mapped `0x004f5680` to `.text` file offset `0x000f4a80`. The body is exactly `0x8c` bytes / 140 decimal (Verified with `tools/int_convert.py`), followed by four `0xcc` bytes before `0x004f5710`. Capstone disassembly confirms callback release from `+0x10c`, `LogoPlayerPane` vtable stores at `+0/+0xa0/+0xa4`, AUTOBUF payload free at `+0x104`, AUTOBUF/LObject teardown at `+0x100`, `VideoPlayerPane` base teardown at `0x005c0090`, delete-flag tests, `OperatorDeleteWrapper` at `0x004f4ac0`, and the bit-`0x4` guard path with object size `0x118`. Raw pointer scan found exactly one little-endian pointer to `0x004f5680`, the primary vtable slot at `0x0061d018`; raw rel32 scan found only the two adjacent thunk jumps at `0x004f5670` and `0x004f567b`, with no ordinary direct call route.
```

### Score Rationale Replacement

Replace/extend the target score rationale with:

```text
| Score | Rationale |
| --- | --- |
| Completion `87` | The page records exact wrapper bounds, raw bytes, vtable/thunk-only reachability, callback release semantics, AUTOBUF member teardown, `VideoPlayerPane` base teardown, project delete helper, bit-`0x4` guard-size path, vtable restore roles, source-owner route, and the explicit no-code policy that places ordinary destructor source in [UID:0002PT]. Completion remains below final-audit because the concrete constructor callback binding and exact original field spellings remain unresolved broader class questions. |
| Confidence `92` | Confidence is very strong because current raw PE scans, existing IDA-backed decompilation/disassembly, sibling thunk/vtable docs, `LogoPlayerPane` class docs, `VideoPlayerPane` teardown docs, AUTOBUF utility docs, FunctionObjects callback docs, and accepted `LogoPane` destructor wrapper policy all agree. Confidence remains below 95+ because current-session IDA MCP was unavailable and exact original member spellings are descriptive. |
```

## Recommended Support Doc Changes

### [UID:0002PT] `LogoPlayerPaneCleanupDestructor`

Recommended metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007H | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007H | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended formal C++:

```cpp
LogoPlayerPane::~LogoPlayerPane()
{
    delete m_completionCallback;
}
```

Recommended text:

```text
Source-facing destructor body: `LogoPlayerPane::~LogoPlayerPane()`. The source-authored cleanup is the owned completion callback release at `+0x10c`, best modeled as `delete m_completionCallback;` where `m_completionCallback` is a non-null-at-use but destructor-null-guarded `FunctionObject0*`. The binary null test and virtual deleting-destructor slot call are compatible with C++ `delete` on a polymorphic pointer.

Do not include explicit AUTOBUF payload free, `m_segmentBuffer.~AUTOBUF<unsigned char>()`, `VideoPlayerPane::~VideoPlayerPane()`, vtable stores, or scalar deleting flag logic in the source block. Those are compiler-generated member/base/scalar-wrapper lowering. [UID:0002PY] documents the scalar deleting destructor wrapper that repeats this cleanup and applies delete flags.
```

### [UID:0002PX] `LogoPlayerPaneDeletingDestructorThunks`

Recommended metadata if not superseded by Agent-B009's active report:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007H | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended text:

```text
These two `0x0b` functions are pure compiler-generated adjusted-this deleting-destructor thunks. `0x004f566a` subtracts `0xa0`; `0x004f5675` subtracts `0xa4`; both tail-jump to [UID:0002PY]. They contain no source-authored behavior beyond class-layout destructor dispatch and should be regenerated from the `LogoPlayerPane` declaration/destructor. Keep [UID:00007H] as semantic owner for documentation evidence, but set `RECONSTRUCTABLE:FALSE`, blank emitters, and leave formal C++ blank, matching the accepted [UID:0002PQ] `LogoPane` thunk policy.
```

### [UID:00019D] `LogoPlayerPane` aggregate

Recommended text-only update, score unchanged unless broader constructor/advance issues are addressed:

```text
[UID:0002PT] now carries the ordinary `LogoPlayerPane::~LogoPlayerPane()` source-body recommendation: delete the owned `FunctionObject0* m_completionCallback` at `+0x10c`. The embedded `AUTOBUF<unsigned char>` member at `+0x100/+0x104/+0x108`, the `VideoPlayerPane` base destructor at `0x005c0090`, the vtable restores, and scalar delete-flag handling are compiler-generated lowering documented by [UID:0002PY]. [UID:0002PX] should be treated as non-emitting adjusted-this thunk glue, like [UID:0002PQ] for `LogoPane`.
```

### [UID:00007H] `LogoPlayerPane`

Recommended method/data notes:

```text
| cleanup destructor | `0x004f5510-0x004f556a` | Ordinary `LogoPlayerPane::~LogoPlayerPane()` body. Source-authored cleanup is best represented as `delete m_completionCallback;`; compiler lowering restores vtables, runs the embedded `AUTOBUF<unsigned char>` member destructor, and then runs `VideoPlayerPane` base teardown. |
| scalar deleting destructor | `0x004f5680-0x004f570c` | MSVC scalar deleting destructor wrapper around the ordinary destructor. It repeats callback/AUTOBUF/base cleanup, applies delete flags, and optionally calls project `operator delete`; formal C++ should remain blank because the ordinary destructor source lives at [UID:0002PT]. |

Suggested field names:
- `AUTOBUF<unsigned char> m_segmentBuffer` at `+0x100`, with data pointer at `+0x104` and byte count at `+0x108`.
- `FunctionObject0* m_completionCallback` at `+0x10c`.
- `bool m_advancedToNextSegment` or `m_segmentAdvanceRequested` at `+0x110`.
- `uint32_t m_firstSegmentSize` at `+0x114`.
```

### [UID:0000O4] `StartupLogoPanes`

Recommended evidence note:

```text
2026-06-19 B015 source-quality reanalysis for [UID:0002PY] resolves the `LogoPlayerPane` destructor source policy. `0x004f5680-0x004f570c` is a compiler-generated scalar deleting destructor wrapper with vtable/thunk-only reachability; the source destructor body belongs at [UID:0002PT] and should be represented as `delete m_completionCallback;`. The `AUTOBUF<unsigned char>` segment-buffer teardown, `VideoPlayerPane` base teardown, and project `operator delete` branch are compiler/destructor lowering and should not be emitted as handwritten wrapper code.
```

### [UID:0001NT] / [UID:0000FV] / [UID:0000P4] `VideoPlayerPane`

Recommended text-only clarification:

```text
[UID:0002PY] and [UID:0002PT] call or tail-jump to `0x005c0090` only as automatic base destructor lowering from `LogoPlayerPane::~LogoPlayerPane()`. This confirms `0x005c0090` should remain `VideoPlayerPane` non-deleting destructor body ownership, not `LogoPlayerPane` source ownership.
```

### [UID:0001WN] / [UID:0000HM] `AUTOBUF`

Optional support clarification:

```text
`LogoPlayerPane` embeds an `_AUTOBUF<unsigned char>` object at `+0x100`. The destructor paths reset the AUTOBUF vtable, free the payload pointer at `+0x104`, and call the `LObject`-compatible AUTOBUF destructor body. This is consumer/member-destructor evidence for the shared AUTOBUF template, not `LogoPlayerPane` ownership of AUTOBUF helper code.
```

## Exact Pending Coverage Text

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` directly from B015. If the supervisor accepts this report, replace the current [UID:0002PY] row beginning:

```text
        - [UID:0002PY][0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor]
```

with:

```text
        - [UID:0002PY][0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor](by-memory/0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor.md) 0x004f5680-0x004f570c | scalar deleting destructor | LogoPlayerPaneScalarDeletingDestructor : reconstructable : 87% : very strong : B015 2026-06-19 source-quality reanalysis keeps owner/emitter [UID:00007H][LogoPlayerPane] and resolves this range as an MSVC scalar deleting destructor wrapper, not a source-authored ordinary method. Raw PE check against SHA-256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632` confirms exact `0x8c` / 140-byte body (Verified with int_convert.py), four `0xcc` bytes before `0x004f5710`, callback release from `FunctionObject0* m_completionCallback` at `+0x10c` through vslot `+0x00` with deleting flag `1`, `LogoPlayerPane` vtable restores at `+0/+0xa0/+0xa4`, embedded `AUTOBUF<unsigned char>` member teardown at `+0x100/+0x104` using vtable `0x0061b868`, automatic `VideoPlayerPane` base teardown call to `0x005c0090`, delete-flag logic calling [UID:000197][0x004f4ac0-0x004f4b00.OperatorDeleteWrapper](by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md) only when bit `0x1` is set and bit `0x4` is clear, guarded bit-`0x4` path with object size `0x118` / 280 decimal (Verified with int_convert.py), sole raw pointer route through primary vtable slot `0x0061d018`, only rel32 routes from the two [UID:0002PX][0x004f566a-0x004f5680.LogoPlayerPaneDeletingDestructorThunks](by-memory/0x004f566a-0x004f5680.LogoPlayerPaneDeletingDestructorThunks.md), and no ordinary direct call route. Formal C++ remains blank by explicit no-code proof; ordinary destructor C++ belongs in [UID:0002PT][0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor](by-memory/0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor.md) as `LogoPlayerPane::~LogoPlayerPane() { delete m_completionCallback; }`.
```

If the supervisor also accepts the support update for [UID:0002PT], replace the current [UID:0002PT] row beginning:

```text
        - [UID:0002PT][0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor]
```

with:

```text
        - [UID:0002PT][0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor](by-memory/0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor.md) 0x004f5510-0x004f556a | unpromoted destructor body | LogoPlayerPaneCleanupDestructor : reconstructable : 88% : very strong : B015 2026-06-19 source-quality reanalysis identifies this unpromoted body as the ordinary `LogoPlayerPane::~LogoPlayerPane()` source location. Source-authored cleanup is the owned zero-argument `FunctionObject0* m_completionCallback` at `+0x10c`, best emitted as `delete m_completionCallback;`; the binary null guard and vslot `+0x00` call with deleting flag `1` are compatible with C++ polymorphic delete. Existing IDA evidence confirms bounds `0x004f5510-0x004f556a`, vtable restores at `+0/+0xa0/+0xa4`, callback release, `AUTOBUF<unsigned char>` member teardown at `+0x100/+0x104` with vtable `0x0061b868`, embedded `LObject` destructor call, tail-jump to `VideoPlayerPane` non-deleting destructor `0x005c0090`, exact padding before/after, and parity with scalar wrapper [UID:0002PY]. Formal C++ should contain only `LogoPlayerPane::~LogoPlayerPane() { delete m_completionCallback; }`; AUTOBUF member teardown, `VideoPlayerPane` base teardown, vtable stores, and scalar delete flags are compiler-generated lowering.
```

If the supervisor also accepts the support update for [UID:0002PX] and it is not superseded by Agent-B009's report, replace the current [UID:0002PX] row beginning:

```text
        - [UID:0002PX][0x004f566a-0x004f5680.LogoPlayerPaneDeletingDestructorThunks]
```

with:

```text
        - [UID:0002PX][0x004f566a-0x004f5680.LogoPlayerPaneDeletingDestructorThunks](by-memory/0x004f566a-0x004f5680.LogoPlayerPaneDeletingDestructorThunks.md) 0x004f566a-0x004f5680 | compiler-generated thunks | LogoPlayerPaneDeletingDestructorThunks : ignored : 86% : very strong : B015 2026-06-19 source-policy reanalysis classifies the two `0x0b` adjusted-this deleting-destructor thunks as non-emitting compiler glue, matching accepted [UID:0002PQ][0x004f52de-0x004f52f4.LogoPaneDeletingDestructorThunks](by-memory/0x004f52de-0x004f52f4.LogoPaneDeletingDestructorThunks.md) policy. `0x004f566a` subtracts `0xa0`, `0x004f5675` subtracts `0xa4`, both tail-jump to [UID:0002PY][0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor](by-memory/0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor.md), vtable slots `0x0061d070/0x0061d0a0` are the only dispatch route, there are no ordinary direct callers, and source should regenerate them from the `LogoPlayerPane` class declaration/destructor rather than handwritten C++.
```

## Validator Needs

B015 did not run validators because this was report-only and no by-* docs or coverage files were edited.

If accepted target/support edits are applied, run:

> Executable block R001 was removed from this report and preserved verbatim in [0002PY-LogoPlayerPaneScalarDeletingDestructor-source-quality-removed.md](0002PY-LogoPlayerPaneScalarDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If optional `VideoPlayerPane` or `AUTOBUF` support notes are applied, also validate those edited pages:

> Executable block R002 was removed from this report and preserved verbatim in [0002PY-LogoPlayerPaneScalarDeletingDestructor-source-quality-removed.md](0002PY-LogoPlayerPaneScalarDeletingDestructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Implementation Readiness

- [UID:0002PY] target is ready for implementation as a no-code scalar-wrapper source-policy update.
- [UID:0002PT] support page is ready for first-draft ordinary destructor C++ if supervisor accepts that support change.
- [UID:0002PX] support page is ready for non-emitting compiler-thunk policy if not superseded by Agent-B009's active assignment.
- No split is required for [UID:0002PY]. Its exact range is one wrapper function with four bytes of padding after it.
- No new owner/source file is required.
- No open target-local blocker remains for wrapper behavior, owner/emitter route, source placement, callback release semantics, AUTOBUF member teardown, base teardown, project delete helper, bit-4 path, vtable roles, or no-code formal policy.

## Remaining Open Questions

- Exact original spelling for `m_completionCallback` is not proven. The descriptive name is high-confidence from behavior and accepted [UID:0002PW] source-quality work.
- Exact original spelling for the embedded AUTOBUF member is not proven. `m_segmentBuffer` is a high-probability descriptive name because the buffer contains segmented startup Bink payload data.
- Exact concrete callback object allocated for the `LogoPlayerPane` constructor remains unresolved because the constructor caller is still missing. This affects constructor/source wiring, not [UID:0002PY] wrapper policy.
- Current-session IDA MCP was unavailable. Existing IDA-backed docs and current raw PE checks are sufficient for this report, but an implementation callback can optionally rerun `lookup_funcs`, `xrefs_to`, `callers`, `callees`, `disasm`, and `decompile` for audit parity.

## Changed Files

Created:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B015/research/0002PY-LogoPlayerPaneScalarDeletingDestructor-source-quality.md`

Modified:

- None outside this report.

Preserved:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B015/research/00013G-EncoderWriteShort-source-quality.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B015/research/00014F-TopLevelExceptionFilter-source-quality.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B015/research/0002IR-KeySpeedMgrLoadSystemKeyboardSettings-source-quality.md`

Leases used:

- None. No lease is required for creating a report inside the Agent-B015 research folder.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000004165","destination_path":"executed-b-agent-research/B015/0002PY-LogoPlayerPaneScalarDeletingDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:37","uid":"0002PY"} -->
<!-- {"agent":"B015","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002PY-LogoPlayerPaneScalarDeletingDestructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B015/0002PY-LogoPlayerPaneScalarDeletingDestructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002PY"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
