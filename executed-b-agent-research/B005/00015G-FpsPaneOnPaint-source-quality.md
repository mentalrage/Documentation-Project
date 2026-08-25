** TARGET-REPORT-UID:00015G **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00015G FpsPaneOnPaint Source-Quality Research

## Final Recommendation

- Keep [UID:00015G] as a source-bearing virtual paint method, not compiler glue and not no-code.
- Recommended source-facing name/signature: `void FpsPane::OnPaint()`.
- Recommended metadata: `COMPLETION:88`, `CONFIDENCE:91`, keep `CANONICAL_OWNER:00005F`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00005F`.
- Recommended source route: direct owner [UID:00005F][FpsPane](by-class/FpsPane.md), emitted through [UID:0000JK][FpsPane](by-file/FpsPane.md) to `NexusTK/ui/diagnostics/FpsPane.cpp`.
- Formal C++ is ready for a first draft under the active combined-score/emitter gate. The old 95/95 no-code blocker is stale and should be removed when this report is accepted for implementation.
- No by-* docs, generated files, IDA DB, project-level reports, or `by-memory/-coverage-report.md` were edited in this report-only pass.

## Target Paths

- Assignment id: `B005-goal2-fps-pane-on-paint-source-quality-00015G-20260619`
- Target UID: [UID:00015G]
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004b67b0-0x004b68ab.FpsPaneOnPaint.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B005\research\00015G-FpsPaneOnPaint-source-quality.md`
- Current target state: `84/90`, `CANONICAL_OWNER:00005F`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00005F`, blank formal C++.

## Evidence Checked

- Workflow and source-quality rules:
  - `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
  - `.codex/AGENTS.md`
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B005/goal.md`
  - `source-3/project-documentation/by-structure.md`
  - `source-3/project-documentation/inference_research.md`
  - `source-3/project-documentation/by-project-structure/proposed-source-tree.md`
- Target/support docs:
  - `by-memory/0x004b67b0-0x004b68ab.FpsPaneOnPaint.md`
  - `by-memory/0x004b68b0-0x004b69b0.FpsPaneUpdateStatistics.md`
  - `by-class/FpsPane.md`
  - `by-file/FpsPane.md`
  - `by-type/by-struct/FpsPaneLayout.md`
  - `by-type/by-vtable/FpsPane_vtables.md`
  - `by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md`
  - `by-memory/0x0061a6a4-0x0061a7dc.FpsPaneDiagnosticStringData.md`
  - `by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md`
- Helper/support docs:
  - [UID:000161] `by-memory/0x004b8e00-0x004b8e11.BackPaneGetBounds.md`
  - [UID:000162] `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`
  - [UID:00016C] `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md`
  - [UID:0000TN] `by-global/SurfaceRenderCallbackTable.md`
  - [UID:0002LK] `by-memory/0x00583280-0x005832e3.StringBaseWideFormatCtor.md`
  - [UID:0002RN] `by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md`
  - [UID:0002RS] `by-memory/0x00584160-0x005845af.StringBaseAppendAndFind.md`
  - [UID:0003NM] `by-memory/0x00584990-0x00584d7e.StringBaseSpliceGrowAndSubstring.md`
- Prior report lead:
  - Existing pending `Agent-B007/research/00015G-FpsPaneOnPaint-source-quality.md` was found and preserved. It was used only as a lead; the B005 recommendation below is independently checked against current docs and the local PE.
- Local PE / Capstone recheck:
  - Binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
  - Size: `2679296`
  - MD5: `4247e04e20b65d6414c7238aa8ff5515`
  - SHA256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
  - Image base: `0x00400000`
  - Sections checked: `.text 0x00401000-0x0060c600`, `.rdata 0x0060d000-0x0066c200`, `.data 0x0066d000-0x0069ce24`, `.rsrc 0x0069d000-0x006b2e00`
  - Capstone 5.0.7 was available. `pefile` was not installed, so the PE section table was parsed directly.

## Exact Boundary And Route Evidence

- The exact half-open range remains `0x004b67b0-0x004b68ab`, size `0xfb`.
- Predecessor boundary: bytes at `0x004b67a0-0x004b67b0` are:

```text
00 8b e5 5d c2 04 00 cc cc cc cc cc cc cc cc cc
```

  This preserves the known preceding return at `0x004b67a6` and nine `0xcc` alignment bytes at `0x004b67a7-0x004b67b0`.
- Successor boundary: bytes at `0x004b68ab-0x004b68bb` are:

```text
cc cc cc cc cc 55 8b ec 83 ec 14 a1 24 2f 67 00
```

  This proves five `0xcc` alignment bytes at `0x004b68ab-0x004b68b0`, followed immediately by [UID:00015H] `FpsPane::UpdateStatistics` at `0x004b68b0`.
- Local `.text` branch scan found zero direct `call`, `jmp`, conditional-branch, or short-branch refs to `0x004b67b0` and zero branch refs to the exclusive end `0x004b68ab`.
- Four-byte literal scan found exactly one absolute `0x004b67b0` pointer: `0x0061a664` in `.rdata`.
- No target RVA (`0x000b67b0`), raw offset (`0x000b5bb0`), target end VA (`0x004b68ab`), or target end RVA (`0x000b68ab`) literal hits were found.
- This exactly matches the documented vtable-only dispatch route: primary FpsPane vtable base `0x0061a620`, slot `+0x44` at `0x0061a664`, value `0x004b67b0`.
- Absence of direct callers is not negative evidence for this body. It is the expected route for a primary paint virtual.

## Disassembly-Level Body Evidence

Local Capstone disassembly confirms the target is a normal `__thiscall` method with SEH/security-cookie setup, no explicit stack arguments, and one receiver in `ECX` saved to `ESI`.

Key instruction sequence:

- `0x004b67db`: `movss xmm0, dword ptr [esi + 0x100]`
  - Reads `FpsPane::m_currentFps` as a `float`.
- `0x004b67e6`: `inc dword ptr [esi + 0xf8]`
  - Increments `FpsPane::m_frameCount`.
- `0x004b67ef-0x004b67f2`: converts the `float` to `double` for varargs.
- `0x004b67f7`: pushes string literal `0x0061a7c8`.
- `0x004b67fd`: calls `0x00583280`, the UTF-16 varargs format initializer, with the local string destination and `L"%5.1f FPS"`.
- `0x004b6812`: calls `0x004b8e00` to copy the pane bounds at inherited Pane offset `+0x44` into a local `RectBounds`.
- `0x004b681b`: calls `0x004b9660` with `0`, setting active draw/fill color state before clearing/filling the bounds.
- `0x004b6826`: indirect call through `dword ptr [0x0069b3fc]` with `ECX = this` and `RectBounds *` on the stack.
- First text pass:
  - `0x004b6833`: `0x004b9680(this, 0x80)` sets the primary text/palette color state to `128`.
  - `0x004b683e`: `0x004b9600(this, 1, 13)` sets draw cursor to `(1, 13)`.
  - `0x004b6846`: `0x00584cf0(&fpsText)` returns string length.
  - `0x004b684f`: `0x00584540(&fpsText)` returns string data pointer.
  - `0x004b6857`: `0x004bab70(this, text, length)` draws the UTF-16 text.
- Second text pass:
  - `0x004b6860`: `0x004b9680(this, 0x0e)` sets the primary text/palette color state to `14`.
  - `0x004b686b`: `0x004b9600(this, 0, 12)` sets draw cursor to `(0, 12)`.
  - `0x004b6873`: `0x00584cf0(&fpsText)` returns string length.
  - `0x004b687c`: `0x00584540(&fpsText)` returns string data pointer.
  - `0x004b6884`: `0x004bab70(this, text, length)` draws the UTF-16 text again.
- `0x004b688c`: calls `0x00582b70` to release the temporary wide string buffer.
- `0x004b68a2`: calls security-cookie check `0x005c772f`.

There are no internal branch targets, switch tables, subranges, embedded data, or generated-thunk shape inside the body.

## Heuristic / Inference Reanalysis And Validation

### Source-Bearing Versus No-Code

Best conclusion: [UID:00015G] is handwritten/source-authored `FpsPane::OnPaint`.

Evidence:

- Normal modeled function body at `0x004b67b0-0x004b68ab`.
- Vtable-only dispatch through `0x0061a664`, exactly the FpsPane primary paint slot.
- Direct reads/writes of FpsPane fields `+0xf8` and `+0x100`.
- Source-authored overlay literal `L"%5.1f FPS"` at [UID:0003BJ] `0x0061a7c8`.
- Ordinary UI/render helper callees for bounds, fill, draw state, and wide text.
- Exact padding before and after the body.

Rejected alternatives:

- Compiler-generated thunk: no `this` adjustment, no tail jump, no destructor target, no scalar deleting flags.
- Scalar deleting destructor: no delete flag, no vtable teardown, no `operator delete`, no lifecycle cleanup.
- Vtable data/no-code: the vtable data item is [UID:0002MJ] at `0x0061a61c-0x0061a6a4`; this target is executable source behavior.
- Padding or unknown raw island: the body has a normal prologue, real calls, field accesses, and exact instruction coverage.
- `UpdateStatistics` merge: successor [UID:00015H] begins after five `0xcc` bytes at `0x004b68b0`; the two methods are adjacent but separate vtable targets.

### Name And Signature

Recommended source-facing signature:

```cpp
void FpsPane::OnPaint();
```

Evidence:

- IDA/live docs and local disassembly show a receiver-only `__thiscall` body with no explicit stack arguments and a plain `ret`.
- Primary vtable slot `+0x44` is documented as the FpsPane paint slot.
- Project docs already use `OnPaint` for comparable pane paint methods and for the target behavior.

Uncertainty:

- Exact original spelling is not provable from bytes. `Paint` is the plausible low-confidence alternate if a later naming sweep proves the project used shorter virtual names. `OnPaint` is still the best current source-facing name and should be used in target/support docs now.
- `FpsPaneOnPaint` should remain only the documentation slug, not a source method name.

### Field Names And Types

Recommended field names:

| Offset | Recommended name/type | Evidence |
| --- | --- | --- |
| `+0xf8` | `uint32_t m_frameCount` or `int m_frameCount` | OnPaint increments this dword every paint. [UID:00015H] reaches it as timer-subobject offset `+0x54` after `+0xa4` normalization, samples/resets it, and derives current FPS statistics. Constructor/session docs also treat it as the frame/tick counter. `m_frameCount` is better than `m_tickCounter` because paint increments it once per rendered frame. |
| `+0x100` | `float m_currentFps` | OnPaint reads it with `movss`, converts to double for formatting, and prints it. [UID:00015H] writes it as the current one-second FPS value via timer-subobject offset `+0x5c`. |

Rejected field interpretations:

- `+0xf8` as elapsed time or timer id: the field is incremented by paint, then reset by the update timer, which is frame-count behavior.
- `+0x100` as average/min/max FPS: those logging/statistic fields live later in the FpsPane layout. This field is the displayed current FPS value.

### Relation To [UID:00015H] FpsPaneUpdateStatistics

[UID:00015G] and [UID:00015H] form the display/update pair:

- `OnPaint` increments `m_frameCount` and consumes `m_currentFps` to render the overlay.
- `UpdateStatistics` is a timer/update virtual reached through the tertiary subobject at owner offset `+0xa4`. It samples and resets owner `+0xf8`, writes owner `+0x100`, updates min/max/sample/total fields, samples MapPane/ObjectList counts for diagnostics, reschedules the next 1000 ms timer, and returns `1`.
- The five `0xcc` bytes at `0x004b68ab-0x004b68b0` keep the methods split. No C++ should be merged across this boundary.

### Helper Names And Source Roles

Recommended source-quality helper names for [UID:00015G]:

| Address/raw label | Recommended role in target prose/C++ | Evidence and caveat |
| --- | --- | --- |
| `0x00583280` / `sub_583280` | `StringBaseWideFormatCtor`, or source-facing `mystr::StringBase<wchar_t>` UTF-16 format constructor | [UID:0002LK] confirms this exact helper stores the wide sentinel and forwards format/varargs to the wide vformat worker. OnPaint passes `L"%5.1f FPS"` and a promoted `double`. |
| `0x00584cf0` / `sub_584CF0` | string length accessor, source-facing `fpsText.length()` | [UID:0003NM] documents `0x00584cf0-0x00584cf6` as `return data[-2]` with broad fan-in. |
| `0x00584540` / `sub_584540` | string data pointer accessor, source-facing `fpsText.c_str()` | [UID:0002RS] documents the three-byte `return *this` pointer-backed string accessor with broad fan-in. |
| `0x00582b70` / `sub_582B70` | wide string release/destructor wrapper | [UID:0002RN] documents this as the UTF-16 release wrapper forwarding to `ReleaseWideBuffer`. This should usually be implicit in source C++ via local object destruction. |
| `0x004b8e00` / `sub_4B8E00` | inherited `GetBounds(RectBounds *outBounds)` over Pane `+0x44` bounds | [UID:000161] currently owns this exact helper as `BackPane::GetBounds`, but the observed body copies `this+0x44` and is consumed by many Pane-derived callers. In this target, render it source-facing as `GetBounds(&bounds)` and cite the support page as the exact binary helper. Do not treat FpsPane as BackPane-owned. |
| `0x004b9660` / `sub_4B9660` | `GrafPort::SetDrawColor` / active draw-fill color setter | [UID:000162] and [UID:0000TN] support this role. OnPaint sets it to `0` immediately before the slot `0x0069b3fc` fill/clear call. |
| `0x0069b3fc` / `dword_69B3FC` | SurfaceRenderCallbackTable slot 7, source-facing `FillRect` / active rectangle fill wrapper | [UID:0000TN] documents slot `0x0069b3fc` as the broad invalidation/fill/presentation callback. In control/pane source, prefer descriptive `FillRect(&bounds)` wording and keep the raw slot address as evidence. Do not emit generated `g_pfnLockSurface` as source truth. |
| `0x004b9680` / `sub_4B9680` | `GrafPort::SetTextColor` / primary text palette-color setter | [UID:000162] and [UID:00016C] support `+0x7c` as primary text color in text rendering. Older `SetBkColor` generated alias pollution should not drive this target. Exact public method spelling remains an API-polish caveat. |
| `0x004b9600` / `sub_4B9600` | `GrafPort::MoveTo(int x, int y)` | [UID:000162] documents cursor X/Y storage at `+0x6c/+0x68`. |
| `0x004bab70` / `sub_4BAB70` | `GrafPort::DrawWideText(const wchar_t *text, int charCount)` | [UID:00016C] now emits first-draft C++ for this counted UTF-16 renderer. |

### Two-Pass Draw / Shadow State

The exact paint order is:

1. Increment `m_frameCount`.
2. Format `m_currentFps` as UTF-16 `L"%5.1f FPS"`.
3. Copy current bounds into a local `RectBounds`.
4. Set active draw/fill color `0`.
5. Fill/clear the pane bounds through SurfaceRenderCallbackTable slot `0x0069b3fc`.
6. Set primary text color `128`, move to `(1, 13)`, draw the string.
7. Set primary text color `14`, move to `(0, 12)`, draw the same string again.

The visual effect is a two-pass FPS overlay with an offset/shadow pass. The order draws the `(1,13)` pass first and the `(0,12)` pass second. The docs can call this foreground/shadow or shadow/foreground only if they preserve the exact order and colors. A safer phrasing is "two text passes for the overlay/shadow effect."

### Owner / Emitter / Source Placement

Accepted:

- Direct class owner: [UID:00005F] `FpsPane`.
- Source file/emitter route: [UID:0000JK] `FpsPane`, `NexusTK/ui/diagnostics/FpsPane.cpp`.

Evidence:

- Primary FpsPane vtable slot at `0x0061a664`.
- Fields `+0xf8/+0x100` are established in `FpsPaneLayout`.
- The overlay literal `L"%5.1f FPS"` is in the FpsPane diagnostic string data range and has one xref from `0x004b67f7`.
- `by-file/FpsPane.md` and `proposed-source-tree.md` already identify `ui/diagnostics/FpsPane.cpp` as the source root for the overlay and diagnostics logger.

Rejected owners:

- `GrafPort`: owns the draw-state and text-render helpers, not the FpsPane method.
- `StringBase` / `StringUtil`: own the temporary string helpers, not the paint method.
- `SurfaceRenderCallbackTable` / `Surface`: own slot `0x0069b3fc`, not the FpsPane caller.
- `BackPane`: owns or currently documents the compact `0x004b8e00` bounds helper, but this method is still FpsPane-owned and merely consumes that inherited bounds helper.
- `ParcelPane`, `MapPane`, `ObjectList`, `MainUiGraph`: no state, vtable, literal, or caller evidence makes them owners of this paint body. `UpdateStatistics` consumes MapPane/ObjectList only for diagnostics, and that does not transfer OnPaint ownership.

### Stale Generated-Name And No-Code Issues

The current target still names many dependencies only as `sub_*` and says final C++ is blank because the page is below a 95/95 threshold. Both are stale under current policy:

- Active code-entry rule in `by-structure.md`: a page may receive reconstruction C++ when it is `RECONSTRUCTABLE:TRUE`, has confirmed nonblank emitters that reach a valid source root, and `(COMPLETION + CONFIDENCE) / 2 > 85`, provided source-quality questions are resolved or explicitly documented.
- Current target already averages `87.0`; recommended `88/91` averages `89.5`.
- The emitter route `00005F -> 0000JK -> NexusTK/ui/diagnostics/FpsPane.cpp` is valid.
- Remaining exact original spellings for the string facade, `SetTextColor` helper, and callback typedef are real caveats but not blockers for a first-draft source representation.
- Replace raw generated names in target prose with the helper roles above while preserving exact addresses as evidence.

## First-Draft C++ Readiness

This target is ready for first-draft C++ after supervisor acceptance. The following code is intentionally source-facing rather than decompiler-shaped. Exact final type/API spelling may be adapted to whatever the accepted StringBase/GrafPort declarations use, but behavior and call order should remain unchanged.

```cpp
void FpsPane::OnPaint()
{
    ++m_frameCount;

    mystr::StringBase<wchar_t> fpsText(L"%5.1f FPS",
                                       static_cast<double>(m_currentFps));

    RectBounds bounds;
    GetBounds(&bounds);

    SetDrawColor(0);
    FillRect(&bounds);

    SetTextColor(128);
    MoveTo(1, 13);
    DrawWideText(fpsText.c_str(), fpsText.length());

    SetTextColor(14);
    MoveTo(0, 12);
    DrawWideText(fpsText.c_str(), fpsText.length());
}
```

Implementation notes:

- If the accepted project facade spells this as `SimpleUString`, `WideString`, or a typedef around `mystr::StringBase<wchar_t>`, only adapt the local string type/API spelling. Keep the UTF-16 varargs format and `double` promotion.
- If the accepted render callback wrapper is not globally named `FillRect`, use a local helper/descriptive wrapper tied to [UID:0000TN] slot `0x0069b3fc`. Do not emit raw `dword_69B3FC` or generated `g_pfnLockSurface` in source C++ unless project-wide callback declarations require that raw alias.
- If final GrafPort naming keeps `SetBkColor` for `0x004b9680`, add target prose explaining that this paint path uses it as the text-render primary palette/color state before `DrawWideText`. The cleaner current source-facing name for this method body is `SetTextColor`.

## Recommended Target Changes

Target: `by-memory/0x004b67b0-0x004b68ab.FpsPaneOnPaint.md`

1. Update metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00005F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00005F | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

2. Replace stale blank-C++ explanation:

```text
This page clears the active combined-score/emitter reconstruction-code gate. Formal C++ should be populated as `FpsPane::OnPaint`; remaining caveats are exact original string facade spelling, final GrafPort helper names, and the final callback typedef/wrapper name for SurfaceRenderCallbackTable slot `0x0069b3fc`.
```

3. Populate formal C++ with the first-draft body above.
4. Add exact local PE/Capstone evidence:
   - PE hash and image-base details.
   - Function size `0xfb`.
   - Leading padding `0x004b67a7-0x004b67b0`.
   - Trailing padding `0x004b68ab-0x004b68b0`.
   - Zero direct branch/call refs to start/end.
   - Exactly one absolute target pointer at `0x0061a664`.
5. Add helper-role table from this report.
6. Add field map:
   - `+0xf8` `m_frameCount`.
   - `+0x100` `m_currentFps`.
7. Add relation to [UID:00015H]:
   - `OnPaint` increments `m_frameCount`.
   - `UpdateStatistics` samples/resets owner `+0xf8`, writes owner `+0x100`, and is reached through tertiary/timer view offset `+0xa4`.
8. Add rejected alternatives:
   - reject no-code, compiler thunk, scalar deleting destructor, `UpdateStatistics` merge, `GrafPort`/`StringBase`/`Surface`/`BackPane` ownership, and raw generated `FpsPaneOnPaint` source name.
9. Update change log with B005 source-quality pass, recommended `88/91`, local PE/Capstone recheck, helper-name cleanup, and first-draft C++ readiness.

## Recommended Support-Doc Updates

Only update support docs during an implementation callback if facts are missing or weaker than this report.

- `by-class/FpsPane.md`
  - Add or expand the `OnPaint` row/note to say it is first-draft C++ ready as `void FpsPane::OnPaint()`.
  - Preserve field map `m_frameCount +0xf8` and `m_currentFps +0x100`.
  - Add exact draw order if missing: bounds clear/fill through slot `0x0069b3fc`, first text pass `(1,13)` color `128`, second text pass `(0,12)` color `14`.
  - Note that `OnPaint` and `UpdateStatistics` form a frame-count/current-FPS producer-consumer pair.
- `by-file/FpsPane.md`
  - State that `NexusTK/ui/diagnostics/FpsPane.cpp` should emit the `FpsPane::OnPaint` method body, not an empty marker.
  - Add dependency wording for StringBase, GrafPort text helpers, inherited bounds helper, and SurfaceRenderCallbackTable slot `0x0069b3fc`.
  - Preserve rejection of ParcelPane/MapPane/ObjectList ownership for the paint method.
- `by-type/by-struct/FpsPaneLayout.md`
  - Already has the key field map. If touched, add this target as concrete evidence that `+0xf8` is frame count and `+0x100` is displayed/current FPS.
- `by-type/by-vtable/FpsPane_vtables.md` and `by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md`
  - Already document `0x0061a664 -> 0x004b67b0`. No required support edit unless implementation wants to mention the B005 route-negative scan.
- `by-memory/0x0061a6a4-0x0061a7dc.FpsPaneDiagnosticStringData.md`
  - Already documents UTF-16 `%5.1f FPS` at `0x0061a7c8` with one xref from `0x004b67f7`; no change required.
- `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`
  - Already has enough detail. If touched, mention [UID:00015G] as a concrete consumer of `SetDrawColor`, `SetTextColor`/primary text color, and `MoveTo`.
- `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md`
  - Already documents `GrafPort::DrawWideText`; no change required.
- `by-global/SurfaceRenderCallbackTable.md`
  - Already documents slot `0x0069b3fc` as active rectangle fill wrapper and warns against generated `g_pfnLockSurface`; no change required.
- StringBase helper pages
  - Current helper pages already support this target's string formatting, length, data pointer, and release roles. No support edit required.

## Score And Metadata Rationale

- `COMPLETION:88`: target has exact range, padding, vtable-only route, body call order, field names/types, source name/signature, helper roles, string literal, support relationship, rejected alternatives, and first-draft C++. It stays below 90+ because exact original StringBase facade spelling, final GrafPort public method names, and callback typedef/wrapper names remain inferred/descriptive rather than final-source proven.
- `CONFIDENCE:91`: local PE/Capstone evidence and existing live IDA support docs strongly confirm the body, boundary, dispatch route, field usage, helper order, and source owner. Confidence remains below final-audit levels because some helper API names are project-normalized source-facing names rather than recovered original spellings.
- Keep `CANONICAL_OWNER:00005F`: FpsPane owns the vtable slot, state, behavior, and literal consumer.
- Keep `RECONSTRUCTABLE:TRUE`: this is source-authored code with a valid C++ representation.
- Keep `EMITTER_UIDS:00005F`: class emitter route reaches [UID:0000JK] `FpsPane.cpp`.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` during this report-only pass. Replace the existing [UID:00015G] row with:

```markdown
        - [UID:00015G][0x004b67b0-0x004b68ab.FpsPaneOnPaint](by-memory/0x004b67b0-0x004b68ab.FpsPaneOnPaint.md) 0x004b67b0-0x004b68ab | method | FpsPaneOnPaint : reconstructable : 88% : very-strong : B005 source-quality pass keeps this as source-bearing `FpsPane::OnPaint` under [UID:00005F] with emitter route to [UID:0000JK]; local PE/Capstone scan over `NexusTK.exe` confirms exact `0xfb` body, nine leading `0xcc` bytes before the start, five trailing `0xcc` bytes before [UID:00015H], no direct branch/call refs to start or end, and the only absolute target pointer at vtable slot `0x0061a664`; body evidence resolves frame counter `+0xf8`, current FPS float `+0x100`, UTF-16 `L"%5.1f FPS"` formatting through StringBase, inherited bounds copy, bounds fill/clear via SurfaceRenderCallbackTable slot `0x0069b3fc`, two `DrawWideText` passes at `(1,13)` color `128` and `(0,12)` color `14`, temporary wide-string cleanup, helper names for StringBase/GrafPort/bounds/fill calls, stale 95/95 no-code wording, and first-draft C++ readiness with only final helper typedef/API spelling still descriptive.
```

Placement context: replace the current [UID:00015G] row under the FpsPane diagnostics block near `0x004b6410-0x004b6caf`.

## Validator Needs

No validators were run because this was a report-only assignment and no by-* docs were edited.

Expected validation commands after an implementation callback, from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00015G-FpsPaneOnPaint-source-quality-removed.md](00015G-FpsPaneOnPaint-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Run additional scoped validators for any optional support docs touched, especially:

> Executable block R002 was removed from this report and preserved verbatim in [00015G-FpsPaneOnPaint-source-quality-removed.md](00015G-FpsPaneOnPaint-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Implementation should also inspect generated `auto-generated/NexusTK/ui/diagnostics/FpsPane.cpp` after validation to confirm [UID:00015G] no longer emits only an empty marker.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits were made. Recommended future IDA cleanup:

- Rename `sub_4B67B0` to `FpsPane::OnPaint` or an IDA-safe equivalent such as `FpsPane_OnPaint`.
- Apply type `void __thiscall FpsPane::OnPaint(FpsPane *this)` if the database's type system cannot express member syntax directly.
- Add/confirm FpsPane fields:
  - `+0xf8`: `m_frameCount`, `uint32_t`/`int`.
  - `+0x100`: `m_currentFps`, `float`.
- Name local stack variables:
  - `[ebp-0x24]`: temporary UTF-16 `StringBase` / `fpsText`.
  - `[ebp-0x20]`: `RectBounds bounds`.
- Comments:
  - `0x004b67f7`: `L"%5.1f FPS"` overlay format.
  - `0x004b6826`: SurfaceRenderCallbackTable slot `0x0069b3fc`, active rectangle fill/clear for current bounds.
  - `0x004b6833/0x004b6860`: primary text color setup for two overlay passes.
  - `0x004b683e/0x004b686b`: text cursor positions `(1,13)` and `(0,12)`.
  - `0x0061a664`: FpsPane primary vtable paint slot.

## Remaining Issues And Impact

- Exact original method spelling is not binary-proven. Impact: use `OnPaint` now because project paint-method naming and vtable role support it; `Paint` remains a low-risk naming-sweep alternate only.
- Exact public string facade spelling is not final. Impact: C++ draft uses `mystr::StringBase<wchar_t>` as a support-doc-aligned placeholder; implementation can adapt to a project typedef without behavior changes.
- Exact public names for `0x004b9680` and slot `0x0069b3fc` remain descriptive. Impact: target score stays below 90+ completion; first-draft C++ is still appropriate because helper roles, arguments, and effects are documented.
- Prior B007 report on the same UID exists and remains pending supervisor review. Impact: no conflict with this B005 deliverable; this file preserves the B005 assignment path and independently revalidates the core claims.

FINISHED `source-3/project-documentation/tools/leaser/Agents/Agent-B005/research/00015G-FpsPaneOnPaint-source-quality.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/00015G-FpsPaneOnPaint-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:30","uid":"00015G"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00015G-FpsPaneOnPaint-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/00015G-FpsPaneOnPaint-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00015G"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
