** TARGET-REPORT-UID:0003N9 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003N9 **
# 0003N9 ControlPaneDrawActiveFrameHelper Source-Quality Research

Assignment: `B001-goal2-control-pane-active-frame-helper-source-quality-0003N9-20260619`  
Agent: `Agent-B001`  
Date: `2026-06-19`  
Target: `[UID:0003N9] by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md`  
Requested mode: report-only. No by-* documentation edits. No manual coverage-report edits.

## Finalized Report / Current Recommendation

Keep the current target metadata and routing:

```text
COMPLETION: 85
CONFIDENCE: 86
CANONICAL_OWNER: 000038
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 000038
RECONSTRUCTION_CPP: blank
```

The current `ControlPane` owner/emitter route is defensible under the present raw-helper policy. The helper is source-shaped, byte-unique, adjacent to the `ControlPane` state virtual/helper cluster, and operates on `ControlPane` state bytes plus inherited `GrafPort`/`Pane` drawing state. However, the helper still lacks source-grade reachability: there is no IDA function object at `0x00494c50`, no xrefs to the start, no vtable slot, no direct branch/call into the helper, and no pointer encoding found in the local PE scan. Formal C++ should therefore remain blank even though the target meets the current minimum average-score/emitter gate.

The best source-facing name candidate is `ControlPane::DrawActiveFrame()`. The current document/file spelling `ControlPaneDrawActiveFrameHelper` should remain a descriptive research name until the class declaration, helper spelling, and caller/source representation are resolved.

## Target

Target document:

```text
E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md
```

Target range:

```text
0x00494c50-0x00494c80
```

Current raw behavior:

```asm
00494c50  56                    push esi
00494c51  8b f1                 mov esi, ecx
00494c53  80 be 01 01 00 00 00  cmp byte ptr [esi+101h], 0
00494c5a  74 22                 jz short 00494c7e
00494c5c  80 be 02 01 00 00 00  cmp byte ptr [esi+102h], 0
00494c63  74 19                 jz short 00494c7e
00494c65  68 80 00 00 00        push 80h
00494c6a  e8 f1 49 02 00        call 004b9660
00494c6f  8d 46 44              lea eax, [esi+44h]
00494c72  c6 46 70 00           mov byte ptr [esi+70h], 0
00494c76  50                    push eax
00494c77  8b ce                 mov ecx, esi
00494c79  e8 d2 57 02 00        call 004ba450
00494c7e  5e                    pop esi
00494c7f  c3                    retn
```

Plain behavior:

```text
if byte(this + 0x101) != 0 and byte(this + 0x102) != 0:
    GrafPort/this SetDrawColor(0x80)
    byte(this + 0x70) = 0
    GrafPort/this DrawRectFrame(this + 0x44)
return
```

## Supervisor Active Recheck

I used the current `Supervisor.md` requirements and B-agent source-quality rules:

- This is a B-agent implementation/source-quality report, not a metadata edit.
- `by-memory/-coverage-report.md` is supervisor-owned and was not edited.
- by-* documentation is project-owned and was not edited in this report-only pass.
- The report includes the mandatory `## Heuristic / Inference Reanalysis And Validation` section.
- The report resolves or best-infers names, fields, helper meanings, caller/reachability, owner/source placement, open questions, split/range decisions, and C++ readiness.
- The report includes exact supervisor-owned coverage row text for a future supervisor/manual-coverage update.
- The report includes a target/support implementation checklist.

I also checked the current B001 goal notes. The saved B001 goal file points at an older SoundManager assignment, but the user's 2026-06-19 prompt explicitly assigns `0003N9`; this report follows the active user assignment.

## Inference Research Guidance Check

I applied the current `by-structure.md` and `inference_research.md` guidance:

- `CANONICAL_OWNER` is the direct semantic owner, not just the nearest address neighbor.
- `EMITTER_UIDS` is the output route, not proof that source-grade C++ is ready.
- A `RECONSTRUCTABLE: TRUE` target can still have blank `RECONSTRUCTION_CPP` if source representation is not ready.
- Current C++ eligibility requires a valid emitter route and average `(COMPLETION + CONFIDENCE) / 2 > 85`; `0003N9` has `(85 + 86) / 2 = 85.5`, so it passes the mechanical minimum.
- The mechanical gate is not permission to emit weak C++. Missing reachability/source declaration/name evidence is sufficient reason to keep formal C++ blank.
- Evidence was separated into direct facts, supported inferences, and rejected alternatives.
- Address locality alone was not treated as proof of ownership. It was combined with field access, class-family pattern, vtable-adjacent state helpers, caller absence, and PE pointer/branch checks.

## Heuristic / Inference Reanalysis And Validation

### Direct Facts

- The bytes at `0x00494c50-0x00494c80` are exact, compact, source-shaped x86 code using `ECX` as `this`.
- The target starts after six bytes of `0xcc` padding at `0x00494c4a-0x00494c50`.
- The target ends exactly at `0x00494c80`, where the next documented range starts: the `ProgressBar` constructor/body area.
- The target checks two state bytes on `this`: `this+0x101` and `this+0x102`.
- If either state byte is zero, it skips all drawing and returns.
- If both are nonzero, it calls `0x004b9660` with immediate `0x80`.
- It then takes the address `this+0x44`.
- It clears byte `this+0x70`.
- It calls `0x004ba450` with `ECX=this` and the `this+0x44` address as the rectangle argument.
- The current target document reports no IDA function object at `0x00494c50`, zero xrefs to the start, no vtable slot, no pointer/direct branch, a unique signature, six bytes of pre-padding, and the `ProgressBar` constructor boundary at `0x00494c80`.

### Local Binary Revalidation

Live IDA MCP was not reachable from this session on 2026-06-19, so I did not claim a fresh live-IDA query. I used the existing IDA-backed documentation as the project fact base and performed a read-only local PE byte/pointer/branch scan against:

```text
E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe
```

PE facts from the local scan:

```text
ImageBase = 0x00400000
.text VA = 0x00001000, raw pointer = 0x400, raw size = 0x20B600, virtual size = 0x20B4AC
.rdata VA = 0x0020D000, raw pointer = 0x20BA00, raw size = 0x5F200, virtual size = 0x5F0BE
Target RVA = 0x00094C50
Target file offset = 0x94050
```

Bytes at and before the helper:

```text
0x00494c4a-0x00494c80:
CC CC CC CC CC CC
56 8B F1 80 BE 01 01 00 00 00 74 22
80 BE 02 01 00 00 00 74 19
68 80 00 00 00 E8 F1 49 02 00
8D 46 44 C6 46 70 00 50 8B CE
E8 D2 57 02 00 5E C3
```

The complete helper signature was found once in the executable. Pattern checks found zero VA/RVA pointer encodings for:

```text
0x00494c50
0x00494c51
0x00494c53
0x00494c7e
0x00494c80
```

Direct branch/call checks found no branch into the helper start or plausible interior entries. The only branch hits involving the helper range were its two internal conditional jumps to `0x00494c7e`.

Sanity checks did find expected branch/pointer activity for neighboring real entries such as `0x00494b80`, `0x00494c30`, and `0x00494c80`, which makes the negative result for `0x00494c50` more meaningful. The local scan is not a complete disassembler, but it is a useful independent check against hidden obvious pointers/direct calls.

### Vtable Placement Reanalysis

The surrounding `ControlPane` and `ProgressBar` vtable regions contain slots for the documented state helper cluster but not for `0x00494c50`.

Relevant `ControlPane` vtable region:

```text
0x00617AD8: 0x00494B80
0x00617ADC: 0x00494BB0
0x00617AE0: 0x00494BD0
0x00617AE4: 0x00494C00
0x00617AE8: 0x00494C10
0x00617AEC: 0x00494C30
0x00617AF0: 0x0041D690
```

Relevant `ProgressBar` vtable region:

```text
0x00617B7C: 0x00494B80
0x00617B80: 0x00494BB0
0x00617B84: 0x00494BD0
0x00617B88: 0x00494C00
0x00617B8C: 0x00494C10
0x00617B90: 0x00494C30
0x00617B94: 0x0041D690
```

No vtable dword points to `0x00494c50` or a plausible interior entry. This supports the current interpretation that `0003N9` is not a virtual override slot. It is best modeled as a raw out-of-line helper or dead/unreached member-like helper in the `ControlPane` source family.

### Field Meaning Reanalysis

The target field meanings are now stronger than the target document alone currently says.

`this+0x101`:

- Directly paired with the state helper at `0x00494bb0` and its clear helper at `0x00494bd0`.
- Existing ControlPane docs have called this a visible/show state byte.
- Best source-quality inference: a `ControlPane` local visible/shown flag, distinct from the inherited `Pane` visibility byte at `+0xb4`.
- Best provisional names: `m_controlVisible`, `m_isShown`, or `m_visibleFlag`.
- Recommended report wording: "ControlPane-local visible/shown state byte".

`this+0x102`:

- Directly paired with the state helpers at `0x00494c10` and `0x00494c30`.
- Existing ControlPane docs have called these deactivate/activate helpers.
- Best source-quality inference: a `ControlPane` local active/focused state byte controlling whether an active/focus frame is drawn.
- Best provisional names: `m_controlActive`, `m_isActive`, or `m_hasActiveFrame`.
- Recommended report wording: "ControlPane-local active/focus state byte".

`this+0x44`:

- Support docs for `PaneLayout` and `GrafPort::DrawRectFrame` identify this as the inherited rectangle/bounds object used by draw helpers.
- Best source-quality inference: inherited `Pane`/`GrafPort` bounds rectangle.
- Best provisional names: `m_bounds` or `m_localBounds`.
- Recommended current name: `m_bounds`, because support draw code already uses this convention and the helper passes it to `DrawRectFrame`.

`this+0x70`:

- Support docs for `GrafPort` identify this as an inherited draw/blit mode byte.
- `WaterFilterEffecter` sets this byte to draw mode `2`.
- `ProgressBar` drawing clears this byte before frame rendering.
- Best source-quality inference: inherited `GrafPort` draw/blit mode byte, not a `ControlPane`-specific flag.
- Best provisional names: `m_drawMode` or `m_blitMode`.
- Recommended current name: `m_drawMode`, with a note that `m_blitMode` remains a possible final spelling.

Immediate `0x80`:

- Passed to `0x004b9660`.
- `0x004b9660` stores active draw/fill color at `this+0x74`.
- The same color value appears in the `ProgressBar` frame drawing path.
- Best source-quality inference: active/focus/frame color index 128.

`0x004b9660`:

- Support docs identify this as a `GrafPort` draw-state accessor that stores color at `this+0x74`.
- Best current descriptive name: `GrafPort::SetDrawColor`.
- Do not call it text color in this target. This usage is frame drawing.

`0x004ba450`:

- Support docs identify this as `GrafPort::DrawRectFrame(const RectBounds *rect)`.
- It consumes the rectangle pointer passed from `this+0x44`.
- It uses inherited draw state and low-level line drawing behavior.

### Helper / Type / Global Meaning Reanalysis

This target is best understood as a `ControlPane` helper that draws an active-state frame around the pane bounds only when the pane is both locally visible/shown and locally active/focused.

No standalone global variable is involved. All observed state is object-relative through `this`:

```text
this+0x101 -> ControlPane-local visible/shown state
this+0x102 -> ControlPane-local active/focus state
this+0x44  -> inherited bounds rectangle
this+0x70  -> inherited GrafPort draw/blit mode
this+0x74  -> inherited GrafPort draw color, written by SetDrawColor
```

The helper's apparent source role is narrow and side-effectful:

1. Gate active-frame drawing on two `ControlPane` booleans.
2. Select draw color `0x80`.
3. Reset inherited draw mode to mode `0`.
4. Draw a rectangle frame using the pane's inherited bounds.

The helper does not mutate `this+0x101` or `this+0x102`; it only observes them. The mutation of `this+0x70` is part of drawing-state setup, not pane-state transition.

### Caller / Reachability Reanalysis

The reachability evidence remains the main unresolved issue.

Current positive evidence:

- The byte sequence is valid source-shaped code, not padding.
- It has normal function prologue/epilogue shape for a small `thiscall` helper.
- It calls known rendering helpers using the object as `ECX`.
- It sits in the exact family band with `ControlPane` state helpers.
- It is byte-unique in the executable.

Current negative evidence:

- No IDA function object at `0x00494c50`.
- No IDA xrefs to the start in the current target doc.
- No vtable slot.
- No local PE VA/RVA pointer encoding to the start or plausible interiors.
- No local PE direct branch/call into the start or plausible interiors.
- No known caller page names this helper.

Best explanation:

The most plausible source explanation is an out-of-line, non-virtual `ControlPane` helper emitted in the same object/source family but not referenced by any surviving direct call or vtable slot in the final linked binary. That can happen with older compilation/linkage models when an object file contributes unused non-inline member/helper code. This explanation fits the source-shaped body and class-family placement, but it is still an inference.

Why this is not enough for final C++:

Adding formal C++ for a guessed private helper would require source-grade decisions about whether the original was:

- a private `ControlPane` member,
- a protected/base helper intended for derived controls,
- a static/local helper taking `this` by convention,
- a compiler-retained but source-unused member,
- or a fragment that should remain represented only as documented raw code.

The current evidence strongly supports class ownership, but it does not establish a source declaration, source spelling, or caller contract.

### Owner / Source Placement Reanalysis

Recommended owner remains:

```text
CANONICAL_OWNER: 000038
EMITTER_UIDS: 000038
```

Recommended source output route remains:

```text
auto-generated/NexusTK/ui/core/ControlPane.cpp
```

Best source placement:

```text
NexusTK/ui/core/ControlPane.cpp
```

Owner evidence:

- The two gate bytes are in the `ControlPane`-specific state-byte range.
- Neighboring helpers at `0x00494b80`, `0x00494bb0`, `0x00494bd0`, `0x00494c00`, `0x00494c10`, and `0x00494c30` are the `ControlPane` state/interaction helper family.
- The helper uses inherited drawing state through the same object, consistent with `ControlPane` inheriting from UI pane/drawing primitives.
- The body draws a pane frame, which is semantically core `ControlPane` behavior rather than `ProgressBar`-specific behavior.
- `ProgressBar` has a separate constructor/draw region beginning at `0x00494c80`, after this helper boundary.

Rejected owner: `ProgressBar`.

- The successor range at `0x00494c80` is `ProgressBar`, but the helper ends before that boundary.
- The state bytes `+0x101` and `+0x102` are established in the ControlPane state helper cluster.
- The helper draws a generic active frame around inherited bounds rather than any progress-specific state or metric.
- No ProgressBar vtable slot points to the helper.

Rejected owner: `Button` or another concrete control.

- No control-specific fields, text, button-state, or direct placement evidence supports another concrete control.
- The relevant vtable-family evidence is ControlPane/ProgressBar state helper reuse, not Button-specific implementation.

Rejected owner: `GrafPort`.

- The drawing calls are `GrafPort` methods, but the gate bytes at `+0x101/+0x102` are not generic `GrafPort` draw state.
- The source behavior is a UI control active-frame policy, not a primitive draw API.

Rejected owner: no-owner/no-emitter.

- Earlier no-owner conclusions were reasonable under stricter older policies that required an entry/caller to assign ownership.
- Current raw-helper policy allows class ownership when field/source-family evidence is strong enough, even when reachability remains unresolved.
- The current evidence is strong enough to identify the semantic owner as `ControlPane`.
- The no-owner model would hide useful ownership/source placement already supported by field and family evidence.

## Current Documentation And Coverage State

Target document state:

- `COMPLETION: 85`
- `CONFIDENCE: 86`
- `CANONICAL_OWNER: 000038`
- `RECONSTRUCTABLE: TRUE`
- `EMITTER_UIDS: 000038`
- `RECONSTRUCTION_CPP: blank`

Class owner:

```text
UID: 000038
Document: by-class/ControlPane.md
Current route: emits through by-file/ControlPane.md / UID 0000IG
```

File owner:

```text
UID: 0000IG
Document: by-file/ControlPane.md
Proposed reconstruction path: NexusTK/ui/core/
Generated output: auto-generated/NexusTK/ui/core/ControlPane.cpp
```

Generated output currently contains only an empty emitter marker for this target:

```cpp
// UID:0003N9 | by-memory\0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md | Completion:85 | Confidence:86 | Empty Emitter Marker
```

Generated memory coverage contains the current target row:

```text
| [UID:0003N9][0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper](by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) | emits | `000038` | `000038` |  | no | `auto-generated/NexusTK/ui/core/ControlPane.cpp` | `by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md` |  |
```

Manual `by-memory/-coverage-report.md` state observed during this report:

- It contains a stale aggregate row for `[UID:0002PD] 0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers`.
- It does not currently contain a standalone current row for `[UID:0003N9]`.
- Because the manual coverage report is supervisor-owned, this report does not edit it. Exact replacement/insertion text is provided below.

## Function / Range Inventory

The parent physical band is documented by `[UID:0002PD] 0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers`.

Relevant child ranges:

```text
0x00494b50-0x00494b77  [UID:0003N1] ProgressBar current setter
0x00494b77-0x00494b80  padding
0x00494b80-0x00494bad  [UID:0003N2] ControlPaneSetVisualState
0x00494bad-0x00494bb0  padding
0x00494bb0-0x00494bca  [UID:0003N3] ControlPaneSetVisibleFlag
0x00494bca-0x00494bd0  padding
0x00494bd0-0x00494bea  [UID:0003N4] ControlPaneClearVisibleFlag
0x00494bea-0x00494bf0  padding
0x00494bf0-0x00494bf7  [UID:0002PC] ControlPaneIgnoresHitTesting
0x00494bf7-0x00494c00  padding
0x00494c00-0x00494c10  [UID:0003N5] ControlPaneSetIgnoreHitTesting
0x00494c10-0x00494c2a  [UID:0003N6] ControlPaneDeactivate
0x00494c2a-0x00494c30  padding
0x00494c30-0x00494c4a  [UID:0003N7] ControlPaneActivate
0x00494c4a-0x00494c50  padding
0x00494c50-0x00494c80  [UID:0003N9] ControlPaneDrawActiveFrameHelper
```

The split is sound. `0003N9` should remain its own half-open range:

```text
0x00494c50-0x00494c80
```

No merge with `0003N7` is recommended because the six-byte `0xcc` run separates the ranges and `0003N7` is a state setter while `0003N9` is a draw helper.

No merge with the successor `ProgressBar` constructor is recommended because `0x00494c80` is a documented successor boundary and the helper body returns at `0x00494c7f`.

No split inside `0003N9` is recommended. The only internal control-flow targets are the two skip branches to the shared epilogue at `0x00494c7e`; there is no plausible independent entry.

## Direct Xref / Caller Inventory

Known positive direct references to neighboring entries:

- `0x00494b80` appears in vtables and direct calls.
- `0x00494c30` appears in vtables and branch activity.
- `0x00494c80` has direct call activity as the successor `ProgressBar` region.

Known missing references for this target:

- No direct branch/call to `0x00494c50`.
- No direct branch/call to plausible interior entries.
- No VA/RVA pointer encoding to `0x00494c50`.
- No vtable dword to `0x00494c50`.
- No IDA xref in the current target document.

This is the reason confidence should not be raised past the current `86`, and it is the reason formal C++ should stay blank.

## Field / Helper Meaning Summary

Recommended terms for future documentation cleanup:

```text
this+0x101  ControlPane-local visible/shown state byte
this+0x102  ControlPane-local active/focus state byte
this+0x44   inherited bounds rectangle, likely m_bounds
this+0x70   inherited GrafPort draw/blit mode byte, likely m_drawMode
0x004b9660  GrafPort::SetDrawColor / draw-color setter
0x004ba450  GrafPort::DrawRectFrame(const RectBounds *rect)
0x80        active/focus/frame color index
```

Avoid these weaker terms:

- Do not call `this+0x70` a `ControlPane` field without noting it is inherited `GrafPort` draw state.
- Do not call `0x004b9660` a text-color setter for this target.
- Do not treat `+0x101` as the inherited `Pane` `+0xb4` visible flag; it is a separate `ControlPane` local state byte.
- Do not imply `0003N9` is a virtual method; no slot is present.

## First-Draft C++ Recommendation / Readiness

No formal C++ should be inserted for this target in the current state.

Reason:

- The target mechanically passes the current average-score/emitter gate with `85.5`.
- The target has a valid emitter route through `ControlPane`.
- But the missing caller/source declaration/helper spelling is not a cosmetic issue; it changes how the source should be represented.
- Field names remain descriptive/provisional.
- Adding code now would make the generated source look more certain than the evidence supports.

The best non-insertable future candidate shape is:

```cpp
// Do not insert until ControlPane state names and helper declaration are accepted.
void ControlPane::DrawActiveFrame()
{
    if (m_controlVisible && m_controlActive) {
        SetDrawColor(128);
        m_drawMode = 0;
        DrawRectFrame(&m_bounds);
    }
}
```

This candidate intentionally preserves the assembly order inside the draw path:

1. set draw color,
2. clear draw mode,
3. draw the rectangle frame.

Alternative name candidates:

```text
ControlPane::DrawActiveFrame()
ControlPane::DrawFocusFrame()
ControlPane::DrawActivationFrame()
ControlPane::DrawActiveFrameHelper()
```

Recommended current source-facing candidate:

```text
ControlPane::DrawActiveFrame()
```

Recommended current document/descriptive name:

```text
ControlPaneDrawActiveFrameHelper
```

Why not emit as `DrawActiveFrameHelper` now:

- `Helper` is a documentation-safe label but may not be the original source spelling.
- The absence of any known caller makes it unclear whether the original code was declared as a private member, protected member, local helper, dead method, or retained unused source artifact.

## Exact Supervisor-Owned Coverage Text

The current manual coverage report did not contain a standalone current `0003N9` row when checked for this report. The following row is the exact target row I recommend the supervisor insert or use as replacement text in `by-memory/-coverage-report.md`:

```text
        - [UID:0003N9][0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper](by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) 0x00494c50-0x00494c80 | raw-helper | ControlPaneDrawActiveFrameHelper : reconstructable : 85% : strong : B001 2026-06-19 source-quality reanalysis keeps the ControlPane class owner/emitter route for this raw active-frame helper: exact unique bytes check base `ControlPane` state bytes `this+0x101` and `this+0x102`, set active draw color `0x80`, clear inherited GrafPort draw-mode byte `this+0x70`, and call `GrafPort::DrawRectFrame` for inherited bounds `this+0x44`. Local PE recheck reconfirmed six-byte `0xcc` pre-padding, no VA/RVA pointer encoding for `0x00494c50` or plausible interior entries, no ControlPane/ProgressBar vtable slot, and no direct branch/call route into the helper; IDA-backed docs also report no function object and zero xrefs. Keep `CANONICAL_OWNER:000038`, `EMITTER_UIDS:000038`, score `85/86`, and blank formal C++ until source-grade reachability/declaration evidence plus final ControlPane state/helper names are resolved.
```

If the supervisor repairs the stale parent aggregate block at the same time, this support row is recommended for `[UID:0002PD]`:

```text
        - [UID:0002PD][0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers](by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md) 0x00494b50-0x00494c80 | mixed aggregate/index | ControlFamilyStateVirtualHelpers : ignored : 88% : very-strong : Non-reconstructable mixed audit container over the progress current setter, base ControlPane state virtuals/accessors, exact padding spans, and raw [UID:0003N9] active-frame helper. Exact child pages carry source ownership/emission; the aggregate itself remains `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and non-emitting because it is a physical address-band index rather than one original source item.
```

I did not edit `by-memory/-coverage-report.md`.

## Target / Support Implementation Checklist

Future implementation callback checklist for the target and support docs:

- Target `[UID:0003N9]`: keep `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:000038`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000038`, and blank `RECONSTRUCTION_CPP`.
- Target `[UID:0003N9]`: update explanatory text to state that `this+0x70` is inherited `GrafPort` draw/blit mode, not a `ControlPane`-local flag.
- Target `[UID:0003N9]`: update helper references so `0x004b9660` is described as `GrafPort::SetDrawColor` / draw-color setter and `0x004ba450` as `GrafPort::DrawRectFrame`.
- Target `[UID:0003N9]`: describe `this+0x44` as inherited bounds rectangle, currently best named `m_bounds`.
- Target `[UID:0003N9]`: describe `this+0x101` as a `ControlPane` local visible/shown byte and `this+0x102` as a `ControlPane` local active/focus byte; keep exact field names provisional.
- Target `[UID:0003N9]`: state explicitly that no vtable slot/caller/source declaration is known and that this is why formal C++ remains blank.
- Target `[UID:0003N9]`: keep `ControlPaneDrawActiveFrameHelper` as the document/descriptive name, with `ControlPane::DrawActiveFrame()` as the best future source-facing candidate.
- Support `[UID:000038] by-class/ControlPane.md`: preserve the `0003N9` owner relationship but avoid implying virtual-slot reachability.
- Support `[UID:0000IG] by-file/ControlPane.md`: preserve output route through `NexusTK/ui/core/ControlPane.cpp`; note empty emitter marker is intentional until source-quality blockers are resolved.
- Support `[UID:0002PD] ControlFamilyStateVirtualHelpers`: keep it non-reconstructable/non-emitting as a mixed physical-band aggregate; ensure it lists `0003N9` as an assigned child, not as aggregate-owned code.
- Supervisor coverage: insert or replace the exact `0003N9` row above in `by-memory/-coverage-report.md`; optionally repair the stale `0002PD` aggregate row if that block is being updated.
- Validation after any future implementation edits: run the validator on the target memory page, `0002PD`, `by-class/ControlPane.md`, and `by-file/ControlPane.md`; generated coverage should continue to show `0003N9` as routed to `auto-generated/NexusTK/ui/core/ControlPane.cpp` with no C++ body.

## Open Questions

The following questions remain unresolved and block source-grade C++:

- What was the original source spelling of the helper?
- Was the helper declared as a `ControlPane` member, a protected helper for derived controls, or another local/static source helper using `thiscall`-style code generation?
- Was the helper intentionally unused/dead in this executable, or is there an indirect/unmodeled caller not visible through current xref and pointer scans?
- What are the final accepted field names for `this+0x101` and `this+0x102`?
- Should `this+0x70` be finalized as `m_drawMode`, `m_blitMode`, or another existing `GrafPort` source name?
- Is `0x80` a named palette/color constant in the original codebase?

These are not blockers for ownership/routing. They are blockers for formal source insertion.

## Final Recommendation

Keep `0003N9` routed to `ControlPane` and keep the current `85/86` score. Do not demote it back to no-owner/no-emitter, because the field/source-family evidence is now strong enough under current policy. Do not raise the score or emit C++ yet, because no source-grade caller/declaration/name evidence has been found.

The target is reconstructable as documented behavior and as a routed empty emitter marker, but not ready for a formal C++ body.

## Validator Results

No project documentation files were edited in this report-only pass, so no by-document validator run was required for changed docs.

Checks performed:

- Read current target documentation.
- Read current parent aggregate documentation.
- Read current `ControlPane` class/file routing docs.
- Read relevant support docs for `PaneLayout`, `GrafPort`, `GrafPortDrawStateAccessors`, `GrafPortDrawRectFrame`, and `ProgressBar` drawing.
- Read current generated output marker and generated memory coverage row.
- Checked current manual coverage report state without editing it.
- Performed read-only local PE byte, pointer, vtable, and direct-branch sanity checks.

## Changed Files

Created this report only:

```text
E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\0003N9-ControlPaneDrawActiveFrameHelper-source-quality.md
```

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003N9","source_path":"executed-b-agent-research/B001/0003N9-ControlPaneDrawActiveFrameHelper-source-quality-2.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
