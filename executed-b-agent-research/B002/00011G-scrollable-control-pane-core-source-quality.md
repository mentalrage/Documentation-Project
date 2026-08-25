** TARGET-REPORT-UID:00011G **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002 Report: [UID:00011G] ScrollableControlPaneCore Source-Quality Audit

Assignment: `B002-goal2-scrollable-control-pane-core-source-quality-00011G-20260616`

Target: [UID:00011G] `by-memory/0x004985a0-0x004988cc.ScrollableControlPaneCore.md`

Current target score: `82/88`, listed in `Low_Completion` and `Low_Both`.

Recommendation: raise [UID:00011G] to `86/90`. This clears the requested `85/85+` source-quality threshold, but it should not receive final C++ yet.

Final C++ decision: keep `RECONSTRUCTION_CPP CODE` blank. The owner/emitter route is valid and the combined score would clear the project gate, but final emitted source is still blocked by unresolved source-facing method names, exact constructor parameter names/types, the adjusted-this metric interface shape, and renderer/helper names.

Owner/emitter decision: keep `CANONICAL_OWNER:0000CE`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000CE`. The wrapper thunks at `0x004986a0-0x004986df` belong in this `ScrollableControlPane` support range. Their jump destinations at `0x0055e8a0`, `0x0055e8d0`, `0x0055e910`, and `0x0055e950` remain `ScrollablePane` implementation owned by [UID:0001GL]/[UID:0000CF].

## Documents Reviewed

- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Supervisor_notes.md`
- `tools/leaser/Agents/SupervisorAssignments.md`
- `tools/leaser/Agents/Agent-B002/goal.md`
- `tools/leaser/Agents/Agent-B002/notes.md`
- `by-memory/0x004985a0-0x004988cc.ScrollableControlPaneCore.md`
- `by-class/ScrollableControlPane.md`
- `by-file/ScrollableControlPane.md`
- `by-class/ControlPane.md`
- `by-memory/0x0049b4f0-0x0049b557.ScrollableControlPaneScalarDeletingDestructor.md`
- `by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md`
- `by-class/ScrollablePane.md`
- `by-file/ScrollBar.md`
- `by-memory/-ignored.md`
- `by-memory/-coverage-report.md`
- `auto-generated/by-memory-tool-report.md`
- `project-level/-auto-completion-stats.md`
- `auto-generated/-ag-memory-coverage.md`
- `by-structure.md`
- `inference_research.md`
- `by-project-structure/proposed-source-tree.md`

## Current State Checked

- `project-level/-auto-completion-stats.md` generated on 2026-06-16 lists `00011G` at `82/88`, combined `85.0`, in both low-completion queues.
- `by-memory/-coverage-report.md` current row:

```markdown
    - [UID:00011G][0x004985a0-0x004988cc.ScrollableControlPaneCore](by-memory/0x004985a0-0x004988cc.ScrollableControlPaneCore.md) : reconstructable : 82% : strong : ScrollableControlPane core with constructor setup, 44 constructor callers, metric delegation helpers, enable/disable, layer add/remove, non-EPF paint behavior, exact handoff to TextEditControlPane, and class parent attachment documented.
```

- `auto-generated/by-memory-tool-report.md` generated on 2026-06-16 reports no active Barrier, General, Filename, or Advanced scan blockers for this UID.
- `auto-generated/-ag-memory-coverage.md` routes [UID:00011G] through [UID:0000CE] to `auto-generated/NexusTK/ui/controls/ScrollableControlPane.cpp`.
- The generated `ScrollableControlPane.cpp` is still effectively empty, so no final-source body has been emitted.

## IDA / Binary Evidence

IDA MCP session used:

```text
idb_open:
  session id: b002_00011G_scrollable_control_20260616
  binary: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
  idb: E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64
  imagebase: 0x400000
  auto-analysis: ready
  Hex-Rays: ready
```

Modeled and raw range inventory:

| Address | Evidence result |
| --- | --- |
| `0x004985a0` | IDA function `sub_4985A0`, size `0xb6`; constructor body. |
| `0x00498660` | Not an IDA function; raw source-shaped non-deleting cleanup/destructor body from `0x00498660-0x00498695`; zero direct xrefs to start. |
| `0x004986a0` | Not an IDA function; raw forwarding thunk start. |
| `0x004986b0` | Not an IDA function; raw forwarding thunk start. |
| `0x004986c0` | Not an IDA function; raw forwarding thunk start. |
| `0x004986d0` | Not an IDA function; raw forwarding thunk start. |
| `0x004986e0` | IDA function, size `0x1b`; render-region update plus child layout refresh. |
| `0x00498700` | IDA function, size `0x18`; adjusted-this metric accessor delegation. |
| `0x00498720` | IDA function, size `0x18`; adjusted-this metric accessor delegation. |
| `0x00498740` | IDA function, size `0x18`; adjusted-this metric accessor delegation. |
| `0x00498760` | IDA function, size `0x1a`; enable/visible-state transition. |
| `0x00498780` | IDA function, size `0x1a`; disable/visible-state transition. |
| `0x004987a0` | IDA function, size `0xbc`; layer add/attach plus child clip. |
| `0x00498860` | IDA function, size `0x16`; child detach plus base remove. |
| `0x00498880` | IDA function, size `0x4d`; older non-EPF paint focus frame path, ending at `0x004988cc`. |
| `0x004988d0` | Not a function; confirms current core page should end at `0x004988cc` before neighboring handoff/padding. |

Constructor evidence at `0x004985a0`:

- Calls `sub_4949E0(this, 4, a2)`, matching `ControlPane` construction with control kind `4`.
- Stores argument `a3` at `this+0x108`.
- Writes metric arguments into the child object at child offsets `+0x100`, `+0x104`, and `+0x108`.
- Calls child virtual slot `+0x2c`.
- Clears byte `this+0x102`.
- Sets byte `this+0x0ff`.
- Installs three `ScrollableControlPane` vtables at object offsets `+0x000`, `+0x0a0`, and `+0x0a4`.
- `xrefs_to 0x004985a0` reports 44 constructor call sites.

Raw cleanup body at `0x00498660-0x00498695`:

- Restores the same three `ScrollableControlPane` vtable bases at `+0x000`, `+0x0a0`, and `+0x0a4`.
- Loads the owned child pointer from `this+0x108`.
- If non-null, dispatches the child destructor through vtable slot `0` with delete flag `1`.
- Chains to `sub_544580` for base teardown.
- Has zero direct inbound references to the raw start, so it should be documented as a raw source-shaped cleanup body, not promoted to a separately named final method.

Wrapper thunk bytes at `0x004986a0-0x004986df`:

```text
0x004986a0: 55 8B EC 8B 89 08 01 00 00 5D E9 F1 61 0C 00 CC
0x004986b0: 55 8B EC 8B 89 08 01 00 00 5D E9 11 62 0C 00 CC
0x004986c0: 55 8B EC 8B 89 08 01 00 00 5D E9 41 62 0C 00 CC
0x004986d0: 55 8B EC 8B 89 08 01 00 00 5D E9 71 62 0C 00 CC
```

Decoded behavior:

- `0x004986a0`: load `[ecx+0x108]`, then jump to `0x0055e8a0`.
- `0x004986b0`: load `[ecx+0x108]`, then jump to `0x0055e8d0`.
- `0x004986c0`: load `[ecx+0x108]`, then jump to `0x0055e910`.
- `0x004986d0`: load `[ecx+0x108]`, then jump to `0x0055e950`.

Raw PE scan confirmed no VA, RVA, or rel32 inbound hits to the wrapper starts `0x004986a0`, `0x004986b0`, `0x004986c0`, or `0x004986d0`. It also confirmed:

- `0x0055e8a0` has a rel32 hit from the wrapper jump at `0x004986aa`.
- `0x0055e8d0` has a rel32 hit from the wrapper jump at `0x004986ba`.
- `0x0055e910` has many normal call refs plus the wrapper jump at `0x004986ca`.
- `0x0055e950` has many normal call refs plus the wrapper jump at `0x004986da`.

Vtable evidence:

- Vtable bases:
  - `0x0061805c` named `??_7ScrollableControlPane@@6B@`
  - `0x006180c4` named `??_7ScrollableControlPane@@6B@_0`
  - `0x006180f4` named `??_7ScrollableControlPane@@6B@_1`
- Vtable store xrefs to those bases occur in the constructor, raw cleanup body, and scalar deleting destructor.
- Slots include:
  - `0x00618068 -> 0x004986e0`
  - `0x0061808c -> 0x004987a0`
  - `0x00618094 -> 0x00498860`
  - `0x006180a0 -> 0x00498880`
  - `0x006180a8 -> 0x00498760`
  - `0x006180ac -> 0x00498780`
  - `0x006180bc -> 0x0049b900`
  - `0x006180c8 -> 0x00498700`
  - `0x006180cc -> 0x00498720`
  - `0x006180d4 -> 0x00498740`

Function behavior checks:

- `0x004986e0`: calls `sub_4B8E20(a2)`, then dispatches child virtual slot `+0x0c` through the child pointer at `this+0x108`.
- `0x00498700`: adjusted-this delegate to child secondary metrics slot `+0x04`.
- `0x00498720`: adjusted-this delegate to child secondary metrics slot `+0x08`.
- `0x00498740`: adjusted-this delegate to child secondary metrics slot `+0x10`.
- `0x00498760`: if byte `this+0x101` is clear, sets it to `1` and dispatches invalidation/update through vslot `+0x20` using `this+0x44`.
- `0x00498780`: if byte `this+0x101` is set, clears it and dispatches invalidation/update through vslot `+0x20` using `this+0x44`.
- `0x004987a0`: calls base/layer attach `0x00544c70`, converts incoming rectangle to local coordinates through `0x004b7e10`, calls `0x004b8e20`, refreshes child slot `+0x0c`, computes child clip, and calls child slot `+0x30`.
- `0x00498860`: dispatches child slot `+0x38`, then chains to base/layer remove `0x00544ce0`.
- `0x00498880`: if `byte_66DA97 != 1`, calls `sub_4B9660(this, 0)`, calls the draw callback at `unk_69B3FC(this, this+0x44)`, and if bytes `+0x101` and `+0x102` are set, calls `sub_4B9660(this, 128)`, clears `+0x70`, and calls `sub_4BA450(this+0x44)`.

Destination ownership evidence from `ScrollablePane`:

- `0x0055e8a0`: selected-child target setter; chooses `ScrollablePane` child at `+0xf8` or `+0xfc`, then calls `0x0055c310`.
- `0x0055e8d0`: selected-child current setter; chooses child, writes child word `+0xfe`, and dispatches child callback slot `+0x20`.
- `0x0055e910`: selected-child target/range getter; returns child word `+0x100` or zero.
- `0x0055e950`: selected-child current/offset getter; returns child word `+0xfe` or zero.
- [UID:0001GL] already owns those helper bodies. The [UID:00011G] wrapper bytes are caller/forwarding evidence only.

## Heuristic / Inference Reanalysis And Validation

The score can defensibly move above `85/85` because the weak points in the current page are now bounded and validated rather than merely named as unknowns.

Constructor signature inference:

- Best source-facing guess: `ScrollableControlPane::ScrollableControlPane(Pane *parent, ScrollablePane *scrollablePane, int initialPositionOrLineStep, int pageExtent, int rangeExtent)`.
- Evidence: `a2` feeds the `ControlPane` base constructor, `a3` is stored at object `+0x108`, and `a4/a5/a6` are copied into metric fields on the child object before the child initialization virtual is called.
- Rejected alternative: `a3` as a metrics object rather than a scrollable child. The destructor, layer add/remove, update-region, and wrapper thunks all use `+0x108` as a full pane/control object with a vtable, not as a simple metric struct.
- Still unresolved: exact names and signedness/width of the three metric arguments. The child helper bodies read words at `+0xfe` and `+0x100`, but the constructor writes three child offsets and the final source names cannot be proven from this range alone.

Embedded scroll-control field:

- Best source-facing name/type: `m_scrollablePane` or `m_scrollControl`, type `ScrollablePane *`.
- Evidence: `+0x108` is stored by the constructor, deleted by the raw cleanup and scalar deleting destructor, used for child virtual dispatch, forwarded by four wrapper thunks, and passed into `ScrollablePane` helper destinations.
- Preferred name for documentation: `m_scrollablePane`, because the wrapper destinations are in `ScrollablePane` and [UID:0001GL] owns the destination implementation.
- Rejected alternative: `m_metrics` or `m_scrollMetrics` as the primary field. The adjusted metric methods reach through the child object's secondary interface; they do not prove that `+0x108` is itself a metric-only object.

Metric accessor adjusted-this issue:

- Best interpretation: `0x00498700`, `0x00498720`, and `0x00498740` are secondary-vtable methods on the `ScrollableControlPane` interface. Hex-Rays shows child access through `this+0x68`, but the vtable call supplies an adjusted `this` pointer at object `+0x0a0`, so `0x0a0 + 0x68 == 0x108`.
- Evidence: the vtable cells at `0x006180c8`, `0x006180cc`, and `0x006180d4` point to these methods; constructor installs the secondary vtable at `+0x0a0`; and the actual embedded child pointer is consistently at object `+0x108`.
- Rejected alternative: a real independent field at object offset `+0x68`. That conflicts with constructor/destructor/wrapper evidence and with the secondary-vtable adjusted-this layout.

Update/render-region method:

- Best name: keep provisional `UpdateRenderRegion`.
- Evidence: `0x004986e0` first calls the same render-region helper used by surrounding pane/control code, then refreshes child layout through the embedded pane virtual slot.
- Rejected alternative: `OnSize` or `SetClipRect`. The function receives a region/rect-like argument, updates render state, and delegates a child layout hook, but no caller naming evidence proves a higher-level event name.

Enable/disable methods and state bytes:

- Best names: `Enable` and `Disable`.
- Evidence: `0x00498760` and `0x00498780` are vtable-routed, transition only on byte `+0x101`, and invalidate/update `this+0x44` after a state change. `by-class/ControlPane.md` identifies `+0x101` as the inherited visible flag set/clear byte.
- Rejected alternative: source-specific focus/highlight toggles. The same byte and invalidation behavior match base `ControlPane` visibility/enabled behavior, not a unique ScrollableControlPane-only highlight bit.

Focus/highlight and paint state:

- Best field interpretation:
  - `+0x101`: inherited `ControlPane` visible/enabled byte.
  - `+0x102`: inherited `ControlPane` active/focus byte.
  - `+0x0ff`: wrapper dirty/refresh byte set by constructor; exact source-facing name unresolved.
  - `+0x44`: inherited rectangle/bounds used by invalidation and drawing.
  - `+0x70`: inherited draw-state byte cleared before active-frame drawing.
- Evidence: `ControlPane` support docs explicitly identify `+0x101`, `+0x102`, `+0x44`, and `+0x70`; `OnPaint` uses `+0x101/+0x102` in the same active-frame pattern recorded for `ControlPaneDrawActiveFrameHelper`.
- Rejected alternative: stale `by-class/ScrollableControlPane.md` observed-state labels that call `+0x0fb` an overlay/focus enabled flag and `+0x100` a selection/highlight flag. This audit found no fresh supporting evidence for those labels in [UID:00011G], while the ControlPane evidence strongly explains the observed bytes.

AddToLayer and RemoveFromLayer:

- Best names: keep `AddToLayer` and `RemoveFromLayer`.
- Evidence: `0x004987a0` chains to base add, transforms the incoming rectangle, updates render/clip state, and attaches the embedded child through child slot `+0x30`; `0x00498860` detaches the embedded child through slot `+0x38` and then chains to base remove.
- Rejected alternative: child-only `AttachChild`/`DetachChild` helpers. Both functions are vtable-routed and include base layer membership work, so they are class virtual overrides rather than private child helpers.

Wrapper thunk ownership:

- Best documentation treatment: keep `0x004986a0-0x004986df` inside [UID:00011G] as raw forwarding thunk bytes, but keep the jump destinations under [UID:0001GL] `ScrollablePaneCore`.
- Evidence: each thunk loads `this+0x108` and tail-jumps to a `ScrollablePane` selected-axis helper; raw PE and IDA xrefs show the destinations are shared `ScrollablePane` functions, while the thunk bytes sit in the `ScrollableControlPane` class range before its next modeled vtable method.
- Rejected alternative: moving the four destination helper bodies into `ScrollableControlPane`. That would incorrectly steal shared `ScrollablePane` implementation already documented with constructor/destructor/layout evidence in [UID:0001GL].
- Rejected alternative: ignoring the thunks as pure padding. The bytes decode into four complete forwarding stubs with exact relative jumps and unique body pattern. They are raw, source-shaped support code even though current inbound references to the thunk starts were not found.

Raw cleanup body treatment:

- Best documentation treatment: add `0x00498660-0x00498695` as a raw non-deleting cleanup/destructor body in the target page.
- Evidence: it restores all three class vtables, deletes the embedded child with flag `1`, and chains to base teardown. It is semantically class-local and sits between constructor and wrapper thunks.
- Rejected alternative: split to a new memory page. The body is small, contiguous support code inside the already assigned core range and has no independent xrefs or source placement that would benefit from a separate page.
- Rejected alternative: final-source named destructor implementation. The scalar deleting destructor page already documents the externally routed destructor body. This raw body has no inbound references and should not drive final C++ yet.

Compiler/helper boundaries:

- `sub_4B8E20`, `sub_4B9660`, `unk_69B3FC`, and `sub_4BA450` remain external/base renderer helpers or callback slots, not source-owned `ScrollableControlPane` methods.
- The wrapper thunks are likely compiler/linker generated adjustor/forwarding artifacts or source-thin delegation stubs; document exact bytes and ownership, but do not invent user-facing final method names.
- The metric methods are source-facing enough to keep in the function table, but their final names are provisional because the secondary interface and child method names are not yet proven.

Score decision:

- Completion `86`: the target can now document the missing raw cleanup body, exact wrapper-thunk bytes, adjusted-this metric interpretation, corrected field/state offsets, vtable slots, constructor fan-in, and source/owner boundaries.
- Confidence `90`: the binary evidence is strong and cross-validated by IDA function inventory, vtables, xrefs, raw byte decoding, raw PE inbound scans, and support docs.
- Not higher than `90`: final source-facing names and types remain inferred; wrapper starts have no current inbound refs; the raw cleanup body has no direct xrefs; and no final C++ should be generated until the `ScrollablePane`/control interface naming pass is complete.

## Exact Supervisor Actions

1. Update only `by-memory/0x004985a0-0x004988cc.ScrollableControlPaneCore.md` metadata:

```markdown
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000CE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000CE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

2. Keep `RECONSTRUCTION_CPP CODE` blank in [UID:00011G].

3. In the [UID:00011G] function table, add the raw cleanup and wrapper rows and correct metric wording. Supervisor-ready replacement table:

```markdown
| Range | Function | Notes |
| --- | --- | --- |
| `0x004985a0-0x00498655` | `ScrollableControlPane::ScrollableControlPane` | Constructs `ControlPane`, installs three `ScrollableControlPane` vtables, stores owned `ScrollablePane`/scroll-control pointer at `+0x108`, initializes child metric fields, and calls the child initialization virtual. |
| `0x00498660-0x00498695` | raw non-deleting cleanup/destructor body | Restores class vtables, deletes the embedded child at `+0x108` with delete flag `1`, and chains base teardown; no direct xrefs to raw start. |
| `0x004986a0-0x004986df` | raw `ScrollablePane` forwarding thunks | Four exact wrappers load `this+0x108` and tail-jump to `0x0055e8a0`, `0x0055e8d0`, `0x0055e910`, and `0x0055e950`; wrapper bytes belong here, destinations remain `ScrollablePane` owned. |
| `0x004986e0-0x004986fa` | `UpdateRenderRegion` | Calls the inherited/render-region helper, then refreshes embedded scroll-control layout. |
| `0x00498700-0x00498717` | `GetScrollPosition` | Secondary-vtable adjusted-this delegate through embedded child at actual object offset `+0x108`; source name provisional. |
| `0x00498720-0x00498737` | `GetScrollRange` | Secondary-vtable adjusted-this delegate through embedded child at actual object offset `+0x108`; source name provisional. |
| `0x00498740-0x00498757` | `GetScrollPageOrExtent` | Secondary-vtable adjusted-this delegate through embedded child at actual object offset `+0x108`; source name provisional. |
| `0x00498760-0x00498779` | `Enable` | Sets inherited `ControlPane` visible/enabled byte `+0x101` and invalidates `this+0x44` only on transition. |
| `0x00498780-0x00498799` | `Disable` | Clears inherited `ControlPane` visible/enabled byte `+0x101` and invalidates `this+0x44` only on transition. |
| `0x004987a0-0x0049885b` | `AddToLayer` | Adds wrapper pane, computes local clip/render region, refreshes child, and attaches embedded scroll content. |
| `0x00498860-0x00498875` | `RemoveFromLayer` | Removes embedded scroll control before base pane removal. |
| `0x00498880-0x004988cc` | `OnPaint` | In older non-EPF mode, draws the active/focus frame when inherited `+0x101/+0x102` state permits it. |
```

4. Add or replace [UID:00011G] evidence bullets with the following:

```markdown
- 2026-06-16 B002 source-quality audit found an unmodeled raw cleanup body at `0x00498660-0x00498695`. It restores the three `ScrollableControlPane` vtables, deletes the embedded child pointer at `+0x108` with delete flag `1`, and chains to base teardown; no direct xrefs to the raw start were found.
- The wrapper thunk bytes at `0x004986a0-0x004986df` decode as four complete forwarding stubs: `0x004986a0 -> 0x0055e8a0`, `0x004986b0 -> 0x0055e8d0`, `0x004986c0 -> 0x0055e910`, and `0x004986d0 -> 0x0055e950` after loading `[ecx+0x108]`. Keep the wrappers in this page, but keep destination helper ownership with [UID:0001GL][ScrollablePaneCore].
- The metric accessor decompilation offset `this+0x68` is an adjusted-this artifact from the secondary vtable at object `+0x0a0`; it resolves to the actual embedded child pointer at object `+0x108`, not a separate object field at `+0x68`.
- Rechecked inherited state bytes: `+0x101` is the `ControlPane` visible/enabled byte, `+0x102` is the active/focus byte, `+0x44` is the inherited rectangle used by invalidation/drawing, and `+0x70` is inherited draw state cleared before active-frame drawing. The constructor-set byte `+0x0ff` remains a dirty/refresh-state inference with no final source name yet.
```

5. Add [UID:00011G] score rationale text:

```markdown
## Score Rationale

Completion is `86` because the page now covers the modeled method inventory, the raw cleanup body at `0x00498660`, exact wrapper thunks at `0x004986a0-0x004986df`, constructor fan-in, vtable slots, adjusted-this metric accessors, inherited ControlPane state bytes, AddToLayer/RemoveFromLayer/OnPaint behavior, and ownership separation from `ScrollablePane` destination helpers.

Confidence is `90` because the recommendation is backed by fresh IDA function inventory, decompilation, raw disassembly, vtable cells, xrefs, raw PE inbound scans, and supporting `ControlPane`/`ScrollablePane` documentation. It remains below final-source confidence because exact source-facing method names, constructor parameter types/names, metric-interface names, and helper/callback names are still provisional.
```

6. Add [UID:00011G] change log entry:

```markdown
- 2026-06-16 B002 source-quality audit recommendation:
  - Recommended change: raise from `82/88` to `86/90`; keep owner/emitter `0000CE`; keep final C++ blank.
  - Evidence: fresh IDA/PE review found the raw cleanup body at `0x00498660`, exact forwarding thunk bytes at `0x004986a0-0x004986df`, adjusted-this metric access through actual object offset `+0x108`, corrected inherited ControlPane state bytes `+0x101/+0x102`, vtable slot ownership, 44 constructor callers, and `ScrollablePane` destination ownership for thunk targets.
```

7. Update `by-class/ScrollableControlPane.md` observed-state text to replace stale offsets. Supervisor-ready replacement:

````markdown
Important recovered state:

```text
+0x000  primary vtable
+0x0a0  secondary/control-interface vtable area
+0x0a4  tertiary adjustor vtable area
+0x0ff  constructor-set dirty/refresh byte; exact source name unresolved
+0x101  inherited ControlPane visible/enabled byte
+0x102  inherited ControlPane active/focus byte
+0x108  owned embedded ScrollablePane/scroll-control pointer
```

The metric accessors are secondary-vtable adjusted-this methods: the decompiler-visible `this+0x68` access resolves to actual object offset `+0x108` when called with the secondary `this` at object `+0x0a0`.
````

8. Update `by-class/ScrollableControlPane.md` caveat/score language only if the supervisor wants support docs synchronized now:

```markdown
- 2026-06-16 B002 support-note recommendation: the class state block should treat `+0x101/+0x102` as inherited `ControlPane` visible/enabled and active/focus bytes, not ScrollableControlPane-private overlay/selection bytes. The owned embedded child pointer remains `+0x108`; exact source-facing child field name is still provisional.
```

9. Optional `by-file/ScrollableControlPane.md` support note:

```markdown
- 2026-06-16 B002 source-quality note: [UID:00011G] contains raw forwarding thunks at `0x004986a0-0x004986df` that load the embedded child pointer at `+0x108` and jump into `ScrollablePane` helper bodies. The wrapper bytes belong to `ScrollableControlPane.cpp`; the destination helper bodies remain owned by `ScrollablePane`/`ScrollBar` documentation.
```

10. No direct update is recommended for `by-memory/-ignored.md`.

11. No direct B-agent edit should be made to `by-memory/-coverage-report.md`; use the replacement row below if supervisor applies the score change.

## Exact Coverage Row Replacement

Replace the current [UID:00011G] row in `by-memory/-coverage-report.md` with:

```markdown
    - [UID:00011G][0x004985a0-0x004988cc.ScrollableControlPaneCore](by-memory/0x004985a0-0x004988cc.ScrollableControlPaneCore.md) 0x004985a0-0x004988cc | class method cluster | ScrollableControlPaneCore : reconstructable : 86% : strong : B002 source-quality audit recommends raising after fresh IDA/PE evidence: exact constructor, raw non-deleting cleanup body at 0x00498660, four raw wrapper thunks at 0x004986a0-0x004986df, vtable-routed render/metric/enable/layer/paint methods, 44 constructor callers, class vtable stores/slots, embedded ScrollablePane pointer at +0x108, ControlPane state bytes +0x101/+0x102, ScrollablePane destination ownership for thunk targets, and blank final C++ pending final source-facing field/method names.
```

## Validation Commands And Queries

Workspace commands:

> Executable block R001 was removed from this report and preserved verbatim in [00011G-scrollable-control-pane-core-source-quality-removed.md](00011G-scrollable-control-pane-core-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

IDA MCP queries:

```text
idb_open binary=E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe idb=E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64 session=b002_00011G_scrollable_control_20260616
lookup_funcs addrs=0x004985a0,0x00498660,0x004986a0,0x004986b0,0x004986c0,0x004986d0,0x004986e0,0x00498700,0x00498720,0x00498740,0x00498760,0x00498780,0x004987a0,0x00498860,0x00498880,0x004988d0,0x0055e8a0,0x0055e8d0,0x0055e910,0x0055e950
decompile addrs=0x004985a0,0x004986e0,0x00498700,0x00498720,0x00498740,0x00498760,0x00498780,0x004987a0,0x00498860,0x00498880,0x0055e910,0x0055e950
disasm start=0x00498660 end=0x004986e0
disasm start=0x0055e8a0 end=0x0055e990
xrefs_to addrs=0x004985a0,0x00498660,0x004986a0,0x004986b0,0x004986c0,0x004986d0,0x004986e0,0x00498700,0x00498720,0x00498740,0x00498760,0x00498780,0x004987a0,0x00498860,0x00498880,0x0055e8a0,0x0055e8d0,0x0055e910,0x0055e950
xrefs_to addrs=0x0061805c,0x006180c4,0x006180f4
get_bytes start=0x00618058 size=168
make_signature_for_range start=0x004986a0 end=0x004986e0
```

Raw PE validation:

```text
Scanned E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe by section-mapped VA/RVA/rel32 reference search.
Targets checked: 0x00498660, 0x004986a0, 0x004986b0, 0x004986c0, 0x004986d0, 0x0055e8a0, 0x0055e8d0, 0x0055e910, 0x0055e950.
Result: no inbound VA/RVA/rel32 hits to 0x00498660 or wrapper starts; wrapper rel32 jumps are present as the only hits to 0x0055e8a0 and 0x0055e8d0 and as additional hits to 0x0055e910 and 0x0055e950.
```

## No-Edit Confirmation

This B002 report did not edit by-memory docs, by-class docs, by-file docs, generated reports, source files, IDA DB state, or `by-memory/-coverage-report.md`. The only intended output is this report file under `tools/leaser/Agents/Agent-B002/research/`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00011G-scrollable-control-pane-core-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:23","uid":"00011G"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00011G-scrollable-control-pane-core-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00011G-scrollable-control-pane-core-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00011G"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
