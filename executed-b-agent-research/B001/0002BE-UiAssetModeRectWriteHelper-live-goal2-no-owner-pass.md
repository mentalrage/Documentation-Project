** TARGET-REPORT-UID:0002BE **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# FINAL RECOMMENDATION

Keep [UID:0002BE] `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md` as `CANONICAL_OWNER:NONE` with blank `EMITTER_UIDS`.

No canonical owner, emitter, split, merge, reclassification, or new child page is justified by the current evidence. The item should remain `RECONSTRUCTABLE:TRUE` because the exact raw body is source-authored project code with a fully reconstructable local behavior, but it should remain non-emitting because no caller, table, vtable slot, raw pointer, branch target, class-private field, singleton route, or source-use path proves where generated C++ would belong.

Required current metadata:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
RECONSTRUCTION_CPP:
```

Coverage-report action: do not edit `by-memory/-coverage-report.md`. The current row is already accurate and should be retained:

```text
- [UID:0002BE][0x005030c0-0x00503104.UiAssetModeRectWriteHelper](by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md) 0x005030c0-0x00503104 | raw function | UiAssetModeRectWriteHelper : reconstructable : 87% : strong : A001 Batch310 and B001 second-pass confirm no function object/xrefs/raw pointer hits/section-aware PE-level references/nearby table evidence, exact bytes, unique exact-range and wildcarded-entry signatures, two retn 8 exits at 0x005030e9 and 0x00503101, optional EPF/legacy RectBounds(0,0,0xa6/0xad,0x10) writes through sub_4B7C50 with int_convert-verified extents 166/173/16, output-preserving non-1 state, MapName-width association without direct ownership, and `CANONICAL_OWNER:NONE` with blank `EMITTER_UIDS` because no caller/table/source-use emitter route is proven.
```

---

# Research

## Target

- UID: `0002BE`
- Page: `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md`
- Current scores reviewed: `COMPLETION:87`, `CONFIDENCE:91`
- Current state reviewed: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`
- Current tracker row: `tools/leaser/Agents/no_owner_b-agent-tracker.md` assigns the live 2026-06-14 Goal 2 pass to Agent-B001 with this report path.
- Generated coverage snapshot: `auto-generated/-ag-memory-coverage.md` still lists this item in both the no-owner and non-emitting sections.

This pass treated prior reports as leads only. The active target page, aggregate page, related owner candidates, current coverage rows, and live IDA/PE evidence were rechecked for this report.

## Live IDA MCP And PE Evidence

The active IDA MCP session reported the IDB as `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, binary `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, image base `0x400000`, with auto-analysis and Hex-Rays ready.

Function lookup evidence:

- `0x005030c0` is not an IDA function.
- Neighbor raw starts `0x00503060`, `0x005030bc`, `0x00503104`, and `0x00503110` are also not IDA functions.
- The next modeled function is `sub_5031F0` at `0x005031f0`, size `0xd3`.
- The callee `sub_4B7C50` at `0x004b7c50`, size `0x1f`, is the shared `RectBounds` initializer documented by [UID:00015S].

Reference evidence:

- `xrefs_to(0x005030c0)` returned zero start xrefs.
- `xrefs_to(0x00503060)` and `xrefs_to(0x00503110)` also returned zero start xrefs for the surrounding raw cluster.
- Interior `0x005030c9` has only the internal code-flow xref from `0x005030c7`; this is not caller, table, or ownership evidence.
- Scoped text search over `0x00503000-0x00503200` for `byte_66DA97` found the sibling compare at `0x00503079` and this helper's compare at `0x005030c9`.
- The broad xref set to `0x0066da97` confirms `g_useEpfAssets` is process-wide state, not a local owner route.
- The broad xref set to `sub_4B7C50` confirms `RectBounds` is a shared low-level geometry dependency, not an owner route for each caller.

Signature and byte evidence:

- `make_signature_for_range(0x005030c0, 0x00503104)` returned a unique exact-range signature for the full `0x44`-byte helper.
- `make_signature(0x005030c0)` returned a unique wildcarded entry signature beginning `55 8B EC 83 6D ? ? 75 ? 80 3D`.
- Independent section-aware PE scan found the exact helper bytes once, at file offset `0x1024c0`, VA `0x005030c0`, in `.text`.
- The same PE scan found no absolute VA, RVA, `push` immediate, `E8/E9` relative call/jump, `0F 8x` near conditional branch, or short conditional branch reference targeting `0x005030c0`.

MapName/MiniMap-adjacent vtable evidence:

- A dword sweep of the nearby vtable region `0x0061e5b4-0x0061e6b8` found no slot equal to `0x005030c0`.
- The same region contains known MapName/MiniMapButton-adjacent entries such as `0x00503350`, `0x005034a0`, `0x00503650`, and `0x00503900`, but not this raw helper start.
- This rules out the easiest virtual-dispatch ownership route for MapNamePane or MiniMapButtonPane.

Raw body evidence:

```asm
005030c0  push ebp
005030c1  mov  ebp, esp
005030c3  sub  dword ptr [ebp+8], 1
005030c7  jnz  00503100
005030c9  cmp  byte ptr [0x0066da97], 1
005030d0  push 0x10
005030d2  jnz  005030ec
005030d4  push 0xa6
005030d9  push 0
005030db  push 0
005030dd  push dword ptr [ebp+0x0c]
005030e0  call 0x004b7c50
005030e5  add  esp, 0x14
005030e8  pop  ebp
005030e9  retn 8
005030ec  push 0xad
005030f1  push 0
005030f3  push 0
005030f5  push dword ptr [ebp+0x0c]
005030f8  call 0x004b7c50
005030fd  add  esp, 0x14
00503100  pop  ebp
00503101  retn 8
```

The exact bytes from the PE scan are:

```text
55 8b ec 83 6d 08 01 75 37 80 3d 97 da 66 00 01 6a 10 75 18 68 a6 00 00 00 6a 00 6a 00 ff 75 0c e8 6b 4b fb ff 83 c4 14 5d c2 08 00 68 ad 00 00 00 6a 00 6a 00 ff 75 0c e8 53 4b fb ff 83 c4 14 5d c2 08 00
```

`int_convert.py` was rerun for this pass:

- `0x44` = 68 bytes.
- `0xa6` = 166.
- `0xad` = 173.
- `0x10` = 16.

## Behavior

The helper decrements its first stack argument. If the adjusted value is not zero, it returns with `retn 8` without writing the caller-supplied output rectangle.

If the adjusted value is zero, it writes a `RectBounds` through the second stack argument using `sub_4B7C50`:

- `g_useEpfAssets == 1`: `RectBounds(0, 0, 166, 16)`.
- otherwise: `RectBounds(0, 0, 173, 16)`.

This is enough to mark the item reconstructable. The body has stable boundaries, fixed constants, known callee behavior, two known `retn 8` exits, and unique signatures. The missing piece is not behavior, but provenance.

## Split Review

No split is needed.

The current page is already the exact child range for the 68-byte helper. It is nested under [UID:00022Z] `0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers`, which is a non-emitting split inventory for three adjacent raw helpers:

- [UID:0002BD] `0x00503060-0x005030bc`
- [UID:0002BE] `0x005030c0-0x00503104`
- [UID:0002BF] `0x00503110-0x005031e1`

The target body has a single coherent role and no mixed subranges. The bytes after `0x00503104` are alignment before the next child. Creating new child pages would duplicate an already-correct split.

## Ownership Candidates

### 1. MapNamePane / MapNamePane file

Candidate UIDs: [UID:00007P] `by-class/MapNamePane.md`, [UID:0000L2] `by-file/MapNamePane.md`.

Evidence for considering it:

- The helper sits immediately before the documented MapName/MiniMapButtonPane island at `0x005031f0-0x0050395f`.
- The legacy width `0xad` equals 173, matching the MapName width/clamp association documented on MapNamePane.
- Sibling [UID:0002BF] now has a defensible MapNamePane owner because it reads the MapNamePane-owned `this + 0x220` 9X11 font-table field.

Evidence against assigning it:

- This helper has no `this` pointer use.
- It does not access MapNamePane fields such as `+0xf8`, `+0x1f8`, or `+0x220`.
- No caller, vtable slot, raw pointer, RVA, branch target, or table route to `0x005030c0` was found.
- The MapName/MiniMapButton-adjacent vtable sweep contains known nearby class functions but not this start.
- Width similarity alone is a semantic association, not a source-owner proof under the current rules.

Decision: reject as canonical owner and emitter for this target.

### 2. Parent aggregate [UID:00022Z]

Evidence for considering it:

- It is the direct documentation parent and the correct physical split inventory for the raw helper cluster.

Evidence against assigning it:

- The aggregate is intentionally `RECONSTRUCTABLE:FALSE`.
- It is a by-memory container, not a source-level owner or emitter.
- Using it as an emitter would not produce a valid source placement.

Decision: reject as canonical owner and emitter.

### 3. RectGeometryHelpers / InitRectBounds

Candidate UIDs: [UID:00015S] `RectGeometryHelpers`, [UID:0000N2] owning file.

Evidence for considering it:

- The helper calls `sub_4B7C50` to initialize the output rectangle.

Evidence against assigning it:

- `sub_4B7C50` is a shared low-level rectangle initializer with broad fan-in.
- The target chooses UI asset-mode dimensions and reads `g_useEpfAssets`; that policy belongs to the caller side, not the geometry primitive.
- A callee dependency is not an ownership or emitter route.

Decision: reject as canonical owner and emitter.

### 4. g_useEpfAssets / StartupWindow owner

Candidate UIDs: [UID:0000SW] `g_useEpfAssets`, [UID:0000O5] owning file.

Evidence for considering it:

- The helper reads `byte_66DA97` / `g_useEpfAssets`.

Evidence against assigning it:

- `g_useEpfAssets` is process-wide UI asset-mode state with many readers.
- StartupWindow owns initialization of the global, not every consumer helper.
- The target has no direct StartupWindow caller or field relationship.

Decision: reject as canonical owner and emitter.

### 5. MiniMap / MiniMapButtonPane

Evidence for considering it:

- These classes share the nearby MapName/MiniMapButtonPane memory island.

Evidence against assigning it:

- No vtable slot, caller, table entry, field access, singleton access, or MiniMap-specific semantic marker ties `0x005030c0` to these classes.
- The helper only writes a caller-supplied rectangle.

Decision: reject as canonical owner and emitter.

### 6. MainMenu/Login/Account dialog island

Evidence for considering it:

- The raw cluster lies near the earlier MainMenu/Login/Account dialog region.

Evidence against assigning it:

- The raw helper cluster is separated by alignment and lacks dialog-specific fields, resources, callers, or table references.
- The current evidence gives only physical proximity, not ownership.

Decision: reject as canonical owner and emitter.

### 7. New source helper file

Evidence for considering it:

- The cluster contains multiple adjacent raw helpers using UI resource/asset-mode behavior.

Evidence against assigning it:

- The existing aggregate already captures the physical cluster without pretending to know a source file.
- No source-use route proves a standalone helper file or a valid emitter.
- Sibling ownership is not uniform after [UID:0002BF] gained a MapNamePane field-based owner; forcing a new cluster owner would hide that distinction.

Decision: do not create a new owner, emitter, or child source page.

## Why Reconstructable But Non-Emitting Is Correct

This is reconstructable because the body is not padding, not runtime metadata, and not ambiguous data. It is a unique MSVC-shaped helper with known arguments, known constants, known branch condition, known callee, and stable range boundaries. A future reconstruction can describe its behavior precisely.

It is non-emitting because current generated-source placement requires more than local behavior. The current system needs a defensible emitting owner or source route. This target has none. Emitting it into MapNamePane, MiniMap, RectGeometryHelpers, StartupWindow, MainMenu, or a new guessed helper file would create a false ownership claim.

The safest accurate state is therefore:

- Preserve the exact child page and high research scores.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `CANONICAL_OWNER:NONE`.
- Keep `EMITTER_UIDS` blank.
- Do not emit C++ until a real owner route is found.

## Final State

No documentation edits outside this Agent-B001 report are recommended.

No lease was required because `goal.md` explicitly permits creating/updating reports inside `tools/leaser/Agents/Agent-B001/research` without a lease. The shared target page, generated coverage report, and coverage report were read only; scoped `git status` showed those shared files already modified in the worktree before this report was added, so this pass did not touch them.

No validator run was required for this research-only report because no by-structure documentation, split child, metadata, or coverage file was edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002BE-UiAssetModeRectWriteHelper-live-goal2-no-owner-pass.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002BE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
