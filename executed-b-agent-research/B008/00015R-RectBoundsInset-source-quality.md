** TARGET-REPORT-UID:00015R **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00015R RectBoundsInset Source-Quality Report

Target: `source-3/project-documentation/by-memory/0x004b7910-0x004b795e.RectBoundsInset.md`

Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B008/research/00015R-RectBoundsInset-source-quality.md`

Date: 2026-06-19

Agent: B008

Mode: B-agent report first. No by-* documentation edits performed. No `by-memory/-coverage-report.md` edit performed. Existing `000127-TextEditControlPaneDestructor-source-quality.md` report was preserved.

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00015R] as a `RectBounds` class method owned/emitted by [UID:0000BU] `RectBounds`, routed through [UID:0000N2] `RectBounds.cpp`.
- Final disposition: source-authored, reconstructable, first-draft C++ ready.
- Required action after supervisor review: update target metadata to `90/92`, replace stale no-code/95-gate wording, document source-facing signature `void RectBounds::Inset(int dx, int dy)`, insert the first-draft C++ method body, and update the coverage row through the supervisor-owned coverage workflow.
- Confidence: very strong for behavior, exact range, no-callee status, source-facing signature, and owner/emitter route; medium-strong for final project folder only because the broader parent still carries `ui/core` versus utility-folder caveats.

## Target

- Target UID: `00015R`
- Target path: `source-3/project-documentation/by-memory/0x004b7910-0x004b795e.RectBoundsInset.md`
- Current scores and parent state: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000BU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BU`
- Current source route: [UID:00015R] -> [UID:0000BU] `RectBounds` class -> [UID:0000N2] `RectBounds` file -> `auto-generated/NexusTK/ui/core/RectBounds.cpp`
- Current coverage row: reconstructable `84%`, confidence text `strong`, final C++ blank.
- Current generated output: `auto-generated/NexusTK/ui/core/RectBounds.cpp` contains only empty emitter markers for `00015R` and related `RectBounds` items.

## Executive Recommendation

The strongest source-facing name and signature are:

```cpp
void RectBounds::Inset(int dx, int dy);
```

This is not a returning/chainable `RectBounds*` helper. The raw body never restores `eax` to `this`; `eax` exits as an arithmetic temporary or midpoint value. All known callers ignore the return register. Treat the method as a `void` in-place mutator over the four `RectBounds` edge fields.

Recommended target metadata:

```text
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000BU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000BU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended first-draft C++ for the target `RECONSTRUCTION_CPP CODE` block:

```cpp
void RectBounds::Inset(int dx, int dy)
{
    left += dx;
    right -= dx;
    top += dy;
    bottom -= dy;

    if (left > right) {
        left = right = (left + right) / 2;
    }

    if (top > bottom) {
        top = bottom = (top + bottom) / 2;
    }
}
```

This assumes the final `RectBounds` declaration exposes `left`, `top`, `right`, and `bottom` directly or equivalently through the shared [UID:0001VP] layout. Do not emit generated scaffolding such as a repeated local `RectBoundsLayout` struct or `GetRectBoundsLayout` helper inside this method.

## Supervisor Active Recheck

- The supervisor assigned a report-only B-agent source-quality pass for [UID:00015R].
- The assigned target itself does not need split repair: raw PE confirms the exact target range `0x004b7910-0x004b795e` and clean padding after the return.
- A support follow-up is needed for the parent method cluster: raw bytes show a function-shaped successor at `0x004b7960-0x004b79f7`, so target/support docs should not continue saying `0x004b7960` is not a function start. That successor is outside [UID:00015R] and should be handled as a separate `RectBounds` method-cluster repair, not folded into this exact target.

## Inference Research Guidance Check

Applied guidance:

- `by-structure.md`: source-quality questions must be resolved before C++ entry; current code-entry gate is `RECONSTRUCTABLE:TRUE`, nonblank emitter route, and `(COMPLETION + CONFIDENCE) / 2 > 85`, with final-quality source still required.
- `by-structure.md`: for `by-memory`, C++ must be limited to the exact memory range. This target is exactly one method body, so emitting only `RectBounds::Inset` is appropriate.
- `inference_research.md`: source names and file ownership are probabilistic without debug metadata; use caller/callee patterns, surrounding helper family, layout evidence, negative evidence, and generated-output caveats.

Evidence type separation:

- Direct raw fact: local PE bytes, Capstone disassembly, rel32 call scan, raw VA pointer scan, and section map.
- Documentation evidence: existing `RectBounds`, `RectBounds.cpp`, `RectBoundsLayout`, `RectBoundsMethods`, `RectGeometryHelpers`, `RectArea`, `LivingObjectPaneRenderFrame`, generated coverage, and proposed source-tree pages.
- Inference: source-facing method spelling `Inset`, parameter names `dx`/`dy`, and source file placement under `ui/core/RectBounds.cpp`.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best direction | Rejected alternatives / impact |
| --- | --- | --- | --- |
| Source-facing name | Target behavior, caller uses with `(1, 1)`, sibling `Offset`, free geometry helper docs, `RectBounds` class inventory | `RectBounds::Inset` | `sub_4B7910` / `FUN_004b7910` are raw/generated names only. `Shrink` is descriptive but weaker than established page/class terminology. `Inflate` is misleading for positive deltas because the method shrinks/insets. |
| Signature | `ecx` receiver, `ret 8`, stack args `[ebp+8]` and `[ebp+0xc]`, no callees, callers ignore `eax` | `void RectBounds::Inset(int dx, int dy)` | `RectBounds* RectBounds::Inset(...)` is contradicted by raw return register behavior; the body never sets `eax=this`. `bool`/`int` return is also rejected because `eax` is an incidental arithmetic temporary. |
| Return/aliasing form | Raw disassembly and caller slices at `0x0053bcb7`, `0x0053bcd8`, `0x0053bcf9` | In-place receiver mutator; no output pointer, no returned alias, no meaningful return value | Chainable return form is generated-source pollution. Caller ownership is rejected because `LivingObjectPane::OnDraw` is only a consumer of the shared geometry method. |
| Field semantics | [UID:0001VP] layout plus raw offsets | `+0x00 left`, `+0x04 top`, `+0x08 right`, `+0x0c bottom` | No alternate field ordering remains plausible. The arithmetic and sibling RectBounds pages consistently use this order. |
| Inset behavior | Capstone body at `0x004b7910` | `left += dx`, `right -= dx`, `top += dy`, `bottom -= dy`; collapse only on strict `left > right` or `top > bottom` | Do not document collapse as `>=`; exact zero width/height is left as-is. Negative deltas expand/outset. |
| Midpoint semantics | `cdq; sub eax, edx; sar eax, 1` after summing the two edges | C++ signed `(left + right) / 2` and `(top + bottom) / 2`, matching MSVC signed division by two | Pure arithmetic shift/floor midpoint is not correct for negative sums; the bias sequence is truncation-toward-zero. |
| Owner/emitter | Target metadata, class/file pages, proposed source tree, broad RectBounds helper family, no data/vtable refs to this target | Keep owner/emitter [UID:0000BU], route through [UID:0000N2] | `LivingObjectPane` rejected: only three call sites. Free `RectGeometryHelpers` rejected as a sibling/counterpart family, not the member method owner. `Region` rejected as a consumer/higher-level dirty-region owner. |
| Current no-code state | Target stale 95/95 wording, generated RectBounds output empty marker, current by-structure code gate | Populate first-draft C++ in the target after supervisor callback | Blank C++ is now stale: target is reconstructable, emitting, average score is above gate, and source shape is resolved. |
| Generated scaffolding | Existing docs mention generated output repeated `RectBoundsLayout`/`GetRectBoundsLayout` noise | Source code should directly use `RectBounds` fields | Do not emit decompiler/generator scaffolding inside every method. The shared struct/layout belongs to class/type declarations. |
| Adjacent boundary issue | Raw PE disassembly at `0x004b7960-0x004b79f7`; rel32/raw scan found no refs to `0x004b7960` | Target boundary remains exact, but support docs should acknowledge a function-shaped raw successor outside this target | Existing "0x004b7960 is not a function start" wording is stale. This does not block [UID:00015R] but should cap/support-follow-up for [UID:00015Q]. |

## Evidence Standards Used

- Existing documentation read: target page, [UID:0000BU] `RectBounds`, [UID:0000N2] `RectBounds`, [UID:0001VP] `RectBoundsLayout`, [UID:00015Q] `RectBoundsMethods`, [UID:00015S] `RectGeometryHelpers`, [UID:00015T] `RectArea`, [UID:0003NU] `LivingObjectPaneRenderFrame`, [UID:0002R2] `LivingObjectPaneRenderFrameMethods`, generated memory coverage, generated RectBounds output, proposed source tree, and project-level unresolved-name report.
- IDA MCP: attempted at `http://127.0.0.1:13337/mcp`, but the local endpoint was unavailable in this session.
- Raw binary fallback: local read-only `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, PE section parser, and Capstone 5.0.7.
- Negative evidence: no callees inside the target, no raw VA dword refs to `0x004b7910`, no rel32 refs beyond the three documented `LivingObjectPane::OnDraw` calls, and no meaningful return register.

## Raw PE / Capstone Facts

Executable:

```text
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
```

PE section context:

```text
ImageBase: 0x00400000
.text:  0x00401000-0x0060c4ac
.rdata: 0x0060d000-0x0066c0be
.data:  0x0066d000-0x0069ce24
.rsrc:  0x0069d000-0x006b2c38
```

Target disassembly:

```asm
0x004b7910  push ebp
0x004b7911  mov ebp, esp
0x004b7913  mov eax, dword ptr [ebp + 8]
0x004b7916  add dword ptr [ecx], eax
0x004b7918  sub dword ptr [ecx + 8], eax
0x004b791b  mov eax, dword ptr [ecx + 8]
0x004b791e  push ebx
0x004b791f  mov ebx, dword ptr [ecx]
0x004b7921  push esi
0x004b7922  mov esi, dword ptr [ecx + 0xc]
0x004b7925  sub esi, dword ptr [ebp + 0xc]
0x004b7928  push edi
0x004b7929  mov edi, dword ptr [ecx + 4]
0x004b792c  add edi, dword ptr [ebp + 0xc]
0x004b792f  mov dword ptr [ecx + 4], edi
0x004b7932  mov dword ptr [ecx + 0xc], esi
0x004b7935  cmp ebx, eax
0x004b7937  jle 0x004b7945
0x004b7939  add eax, ebx
0x004b793b  cdq
0x004b793c  sub eax, edx
0x004b793e  sar eax, 1
0x004b7940  mov dword ptr [ecx + 8], eax
0x004b7943  mov dword ptr [ecx], eax
0x004b7945  cmp edi, esi
0x004b7947  jle 0x004b7957
0x004b7949  lea eax, [esi + edi]
0x004b794c  cdq
0x004b794d  sub eax, edx
0x004b794f  sar eax, 1
0x004b7951  mov dword ptr [ecx + 0xc], eax
0x004b7954  mov dword ptr [ecx + 4], eax
0x004b7957  pop edi
0x004b7958  pop esi
0x004b7959  pop ebx
0x004b795a  pop ebp
0x004b795b  ret 8
```

Boundary bytes:

```text
0x004b7908-0x004b7910: cc cc cc cc cc cc cc cc
0x004b795e-0x004b7960: cc cc
```

Direct rel32 call refs to `0x004b7910`:

```text
0x0053bcb7
0x0053bcd8
0x0053bcf9
```

These all occur inside [UID:0003NU] `LivingObjectPaneRenderFrame` / `LivingObjectPane::OnDraw`. Each caller pushes `1`, pushes `1`, loads `ecx` with a stack `RectBounds`, and calls `0x004b7910`, so the direct observed caller use is `scratchRect.Inset(1, 1)`.

Raw VA dword scan:

```text
0x004b7910: none
0x004b795e: none
```

Callee scan:

```text
No direct call instruction inside 0x004b7910-0x004b795e.
```

Adjacent successor note:

```text
0x004b7960-0x004b79f7 is a function-shaped no-xref RectBounds-style method that intersects/collapses this rectangle with another rectangle, returns a bool in al, and zeroes this rectangle on failure.
0x004b79f7-0x004b7a00 is cc padding before the modeled 0x004b7a00 UnionWith body.
```

This adjacent body is outside [UID:00015R]. It should be reviewed under [UID:00015Q] or a new child page, but it does not change the [UID:00015R] target boundary.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004b7910-0x004b795e` | [UID:00015R] target | `RectBounds::Inset` member mutator | TRUE | [UID:0000BU] | recommend `90/92` | first-draft C++ ready |
| `0x004b7960-0x004b79f7` | no exact page currently identified in this pass | adjacent function-shaped RectBounds intersection mutator | likely TRUE | likely [UID:0000BU] / [UID:0000N2] | not scored here | support follow-up, outside this target |
| `0x004b795e-0x004b7960` | no exact padding row currently identified in this pass | two-byte `0xcc` alignment after target | FALSE/padding | parent cluster | not scored here | support follow-up if adjacent child is split |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0053bcb7` | `call 0x004b7910` after `push 1; push 1; lea ecx, [ebp-0x14]` | first nested-frame inset of a local `RectBounds` in `LivingObjectPane::OnDraw` |
| `0x0053bcd8` | same call pattern | second nested-frame inset |
| `0x0053bcf9` | same call pattern | third nested-frame inset |
| `0x004b7910` body | no callees | self-contained geometry field mutation |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- Target page already identifies the helper as `RectBounds` member-style inset/shrink logic over `left`, `top`, `right`, `bottom`.
- [UID:0000BU] `RectBounds` documents `left/top/right/bottom` and lists the target as the inset/shrink method.
- [UID:0000N2] `RectBounds` routes the family to `NexusTK/ui/core/RectBounds.cpp`.
- [UID:0001VP] `RectBoundsLayout` documents the four-int layout and states inset/inflate helpers collapse inverted axes to midpoint.
- [UID:00015Q] `RectBoundsMethods` documents the target as a self-contained class method, with three `LivingObjectPane` caller refs and no callees.
- [UID:0003NU] and [UID:0002R2] document `LivingObjectPane::OnDraw` as a consumer that calls `0x004b7910` while drawing frames.
- `auto-generated/-ag-memory-coverage.md` confirms the target emits through [UID:0000BU] to `auto-generated/NexusTK/ui/core/RectBounds.cpp`.

Existing docs that are stale, incomplete, or contradicted:

- The target status says final `RECONSTRUCTION_CPP` remains blank because the page is below a `95/95` gate. That is stale under current `by-structure.md`; the target meets the active combined-score/emitter gate and source shape is now resolved.
- The target status does not resolve return/aliasing. Raw PE shows the method should be `void`, not chainable.
- The target evidence says `0x004b7960` is not a function start. Raw PE shows a function-shaped body begins at `0x004b7960`. This is outside the target but should be corrected in target/support wording.
- `project-level/-unresolved.md` still reports `sub_4B7910` and `sub_53BB20` raw-name occurrences. For this target, `sub_4B7910` should map to source-facing `RectBounds::Inset`; `sub_53BB20` is a caller-side name already documented by `LivingObjectPaneRenderFrame`.
- Generated RectBounds output currently has only empty emitter markers, so the no-code state is a documentation/autogen population gap rather than a true source-shape blocker.

## Ranked Ownership Analysis

### 1. [UID:0000BU] `RectBounds` class, emitted through [UID:0000N2] `RectBounds.cpp`

- Evidence for: receiver in `ecx`, direct four-field `RectBounds` layout mutation, sibling class-method island, established class page, established file page, generated route to `ui/core/RectBounds.cpp`, and no callee dependencies.
- Evidence against: final `ui/core` versus utility folder remains parent-level medium uncertainty; class/type C++ declarations are still blank in generated output.
- Decision: accept. This is the direct source owner and emitter route for [UID:00015R].

### 2. [UID:0000N2] `RectBounds` file directly

- Evidence for: the broader geometry helper family and source route live in `RectBounds.cpp`; [UID:00015Q] uses file ownership.
- Evidence against: this exact target is a receiver-style class method, so the class is the more precise canonical owner.
- Decision: use as source-file route, not canonical owner.

### 3. [UID:0003NU] / [UID:00007B] `LivingObjectPane`

- Evidence for: all direct rel32 callers are inside `LivingObjectPane::OnDraw`.
- Evidence against: caller/consumer evidence is not ownership; the method mutates a generic `RectBounds`, has no `LivingObjectPane` state, and belongs to the broad shared geometry family.
- Decision: reject owner/emitter.

### 4. [UID:00015S] `RectGeometryHelpers`

- Evidence for: same field layout and similar free-helper inset behavior.
- Evidence against: target is `thiscall` member style; [UID:00015S] is the free-helper island. They are siblings/counterparts under the `RectBounds.cpp` file, not owner/child.
- Decision: reject as direct owner; keep as cross-reference.

### 5. [UID:0000N3] `Region`

- Evidence for: `Region` consumes rectangle primitives.
- Evidence against: this body has no dirty-region state and belongs to lower-level rectangle math.
- Decision: reject owner/emitter.

## Negative Evidence Summary

- No global/data/vtable pointer cells reference `0x004b7910`; only direct calls from one consumer method were found.
- No callees or external helpers are used by the target body.
- No source-specific `LivingObjectPane` field appears in the target body.
- No meaningful return value is produced; generated `RectBounds*` return shapes are rejected.
- No evidence supports moving the method into `Region`, render, or feature-pane files.
- Address adjacency to the no-xref `0x004b7960` successor does not alter this target's exact range or owner.

## Recommended Exact Target Doc Changes

Do not apply until a supervisor sends an implementation callback.

### 1. Metadata

Replace the score lines with:

```text
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep:

```text
*** CANONICAL_OWNER:0000BU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000BU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### 2. Status Section Replacement

Recommended replacement status text:

```markdown
## Status

- Disposition: reconstructable NexusTK project code.
- Entity kind: source-authored `RectBounds` member inset/shrink method.
- Source-facing signature: `void RectBounds::Inset(int dx, int dy)`.
- Owner class: [UID:0000BU][RectBounds](by-class/RectBounds.md).
- Likely source file: [UID:0000N2][RectBounds](by-file/RectBounds.md).
- Confidence: very strong for behavior, exact range, no-callee status, return/aliasing form, and caller set; medium-strong for final source folder because the broader parent still carries `ui/core` versus utility-folder caveats.
- Raw lookup alias: `sub_4B7910`, retained only as a binary-search alias for `RectBounds::Inset`.
- Rebuild handling: source-authored member method; first-draft C++ is ready under the active combined-score/emitter gate.
```

### 3. Behavior Section Replacement / Addendum

Recommended behavior text:

```markdown
This method mutates the receiver in place and returns no meaningful value:

- `left += dx`;
- `right -= dx`;
- `top += dy`;
- `bottom -= dy`;
- if `left > right`, assign both horizontal edges to `(left + right) / 2`;
- if `top > bottom`, assign both vertical edges to `(top + bottom) / 2`.

The midpoint division uses signed MSVC truncation-toward-zero semantics. Equality is not collapsed; exact zero width or height is preserved. Negative `dx`/`dy` values act as an outset/expansion.
```

### 4. Evidence Section Addendum

Recommended addendum:

```markdown
### B008 Raw PE / Source-Quality Recheck (2026-06-19)

B008 could not reach the local IDA MCP endpoint, so the target was rechecked against raw `NexusTK.exe` bytes with Capstone. The exact body is `0x004b7910-0x004b795e`, with `0xcc` padding at `0x004b7908-0x004b7910` and `0x004b795e-0x004b7960`. The method is a `thiscall` receiver mutator with two stack arguments and `ret 8`; it has no callees. A PE-level rel32 scan found only three direct calls to the entry, at `0x0053bcb7`, `0x0053bcd8`, and `0x0053bcf9`, all inside [UID:0003NU][LivingObjectPaneRenderFrame](by-memory/0x0053bb20-0x0053bd1c.LivingObjectPaneRenderFrame.md), each passing `(1, 1)` to a stack `RectBounds`.

The body leaves `eax` as an arithmetic temporary/midpoint and never restores `eax` to `this`; callers ignore the register. Therefore the source-facing signature should be `void RectBounds::Inset(int dx, int dy)`, not `RectBounds*`.

Raw bytes show a function-shaped successor at `0x004b7960-0x004b79f7`, followed by `0xcc` padding to `0x004b7a00`. That successor is outside this exact page and should be reviewed under the parent `RectBoundsMethods` cluster; do not describe `0x004b7960` as padding or as proven non-code.
```

### 5. Reconstruction C++ Insertion

Insert this between the target `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END` markers:

```cpp
void RectBounds::Inset(int dx, int dy)
{
    left += dx;
    right -= dx;
    top += dy;
    bottom -= dy;

    if (left > right) {
        left = right = (left + right) / 2;
    }

    if (top > bottom) {
        top = bottom = (top + bottom) / 2;
    }
}
```

### 6. Changes Entry

Recommended new change log entry:

```markdown
- 2026-06-19 B008 source-quality pass:
  - Before: `COMPLETION:84`, `CONFIDENCE:90`, final C++ blank under stale `95/95` wording.
  - Recommended: `COMPLETION:90`, `CONFIDENCE:92`, owner/emitter unchanged at [UID:0000BU], and first-draft C++ populated.
  - Summary/evidence: raw PE/Capstone confirms exact `0x004b7910-0x004b795e` thiscall body, no callees, three rel32 callers inside `LivingObjectPane::OnDraw`, in-place four-field inset behavior, signed midpoint collapse on strict inversion, no meaningful return value, and clean target padding. Source-facing signature is `void RectBounds::Inset(int dx, int dy)`.
  - Follow-up: parent [UID:00015Q] should review/split the function-shaped no-xref successor at `0x004b7960-0x004b79f7`; it is outside this exact target.
```

## Recommended Support Doc Changes

Do not apply until a supervisor sends an implementation callback.

- [UID:0000BU] `by-class/RectBounds.md`
  - Update the method row for [UID:00015R] to state `void RectBounds::Inset(int dx, int dy)`.
  - Remove "omitted from active output" wording once the target C++ is inserted.
  - Add that the method is a void in-place mutator and not chainable.

- [UID:0000N2] `by-file/RectBounds.md`
  - Update generated-output caveats: the previous `0x004b7910` omission is a stale generated-output issue once the target emits code.
  - Keep `RectBounds.cpp` as the route, but continue to record parent-level `ui/core` versus utility-folder uncertainty.

- [UID:00015Q] `by-memory/0x004b78d0-0x004b7ae8.RectBoundsMethods.md`
  - Correct the target row to `void RectBounds::Inset(int dx, int dy)`.
  - Add a support follow-up for the raw function-shaped successor `0x004b7960-0x004b79f7`, likely a `RectBounds` intersection mutator with bool return and no PE-level refs found in this pass.
  - Do not merge `0x004b7960` into [UID:00015R].

- [UID:0001VP] `RectBoundsLayout`
  - No required layout change. The target confirms existing `left/top/right/bottom` offsets.
  - Future C++ should use one shared `RectBounds` declaration rather than per-method generated layout helpers.

## Score / Metadata Recommendation

Recommended score change: `84/90` -> `90/92`.

Why completion increases:

- Source-facing signature and return form are now resolved.
- First-draft C++ is ready and exact.
- Raw PE evidence confirms range, padding, body, no callees, direct callers, and no meaningful return.
- Generated-name/no-code caveats are identified with exact fixes.

Why confidence increases:

- Behavior is byte-level confirmed.
- Owner/emitter route is already supported by class/file/type pages and active generated route.
- Remaining uncertainty is limited to broader parent/source-folder polish and the adjacent `0x004b7960` support follow-up.

Why not `95+`:

- The class/header declaration and broader `RectBounds.cpp` source organization are not final-audit complete.
- The adjacent raw successor inside [UID:00015Q] needs separate documentation.
- Parent pages still carry broader source-folder and helper-name caveats.

## First-Draft C++ Readiness

Status: ready to populate in the target after supervisor implementation callback.

Gate check:

- `RECONSTRUCTABLE:TRUE`: yes.
- Nonblank emitter route: `EMITTER_UIDS:0000BU`, surfacing to `auto-generated/NexusTK/ui/core/RectBounds.cpp`: yes.
- Combined score after recommendation: `(90 + 92) / 2 > 85`: yes.
- Source shape resolved: yes.

Use this exact first draft:

```cpp
void RectBounds::Inset(int dx, int dy)
{
    left += dx;
    right -= dx;
    top += dy;
    bottom -= dy;

    if (left > right) {
        left = right = (left + right) / 2;
    }

    if (top > bottom) {
        top = bottom = (top + bottom) / 2;
    }
}
```

Do not include:

- `return this;`
- `RectBounds*` return type.
- Repeated local `RectBoundsLayout` struct definitions.
- `GetRectBoundsLayout` helper scaffolding.
- Caller-specific `LivingObjectPane` names or state.
- Raw alias `sub_4B7910` in the C++ symbol name.

## Validator Needs

No validator run was required for this report-only pass.

If the supervisor sends an implementation callback for the target, recommended validation after edits:

> Executable block R001 was removed from this report and preserved verbatim in [00015R-RectBoundsInset-source-quality-removed.md](00015R-RectBoundsInset-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If support pages are updated in the same callback, validate each edited support page, for example:

> Executable block R002 was removed from this report and preserved verbatim in [00015R-RectBoundsInset-source-quality-removed.md](00015R-RectBoundsInset-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After C++ insertion, run an autogen dry-run or apply per supervisor preference:

> Executable block R003 was removed from this report and preserved verbatim in [00015R-RectBoundsInset-source-quality-removed.md](00015R-RectBoundsInset-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Do not edit `by-memory/-coverage-report.md` as B008 while the supervisor ban is active.

## Exact Pending Coverage Text

Replace the existing [UID:00015R] row in `source-3/project-documentation/by-memory/-coverage-report.md` with:

```markdown
    - [UID:00015R][0x004b7910-0x004b795e.RectBoundsInset](by-memory/0x004b7910-0x004b795e.RectBoundsInset.md) 0x004b7910-0x004b795e | class method | RectBounds::Inset : reconstructable : 90% : very-strong : B008 2026-06-19 source-quality reanalysis resolves the exact source-facing signature as `void RectBounds::Inset(int dx, int dy)`; raw PE/Capstone confirms the `thiscall` body with `ret 8`, no callees, only three rel32 callers at `0x0053bcb7`, `0x0053bcd8`, and `0x0053bcf9` inside `LivingObjectPane::OnDraw`, in-place four-field mutation (`left += dx`, `right -= dx`, `top += dy`, `bottom -= dy`), strict inverted-axis midpoint collapse via signed `/ 2`, no meaningful return/aliasing value, and clean `0xcc` padding at `0x004b7908-0x004b7910` and `0x004b795e-0x004b7960`; keep owner/emitter [UID:0000BU] through [UID:0000N2] and populate first-draft C++ under `NexusTK/ui/core/RectBounds.cpp`. Adjacent raw function-shaped `0x004b7960-0x004b79f7` successor is outside this exact row and needs separate parent-cluster follow-up.
```

## Follow-Up Actions

Supervisor actions:

- Review this report before implementation.
- If accepted, send B008 an implementation checklist covering target metadata, target evidence text, target C++ insertion, selected support doc updates, validation commands, and the supervisor-owned coverage row above.
- Apply/update `by-memory/-coverage-report.md` separately while the shared-file edit ban remains active.

B008 implementation callback actions, if requested:

- Lease any by-* target/support docs before editing.
- Apply accepted target and support changes.
- Run validator commands.
- Report changed files and validation output.

Future research outside this exact target:

- Review/split `0x004b7960-0x004b79f7` under the `RectBoundsMethods` cluster. Raw bytes suggest a no-xref `RectBounds` intersection mutator that is not currently represented as an exact child page.
- Consider a coordinated `RectBounds` source-declaration pass so [UID:0000BU] and [UID:0001VP] emit one clean class/layout declaration instead of leaving method bodies to depend on implicit fields.

## Changed Files

Created report only:

```text
source-3/project-documentation/tools/leaser/Agents/Agent-B008/research/00015R-RectBoundsInset-source-quality.md
```

No target by-memory docs changed. No support by-* docs changed. No generated/project-level files changed. No `by-memory/-coverage-report.md` edit performed.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/00015R-RectBoundsInset-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"00015R"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00015R-RectBoundsInset-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/00015R-RectBoundsInset-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00015R"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
