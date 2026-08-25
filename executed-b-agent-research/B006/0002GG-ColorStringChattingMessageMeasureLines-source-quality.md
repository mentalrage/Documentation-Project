** TARGET-REPORT-UID:0002GG **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002GG] ColorStringChattingMessageMeasureLines source-quality report

Status: FINISHED report-only B006 research pass.

Target: `source-3/project-documentation/by-memory/0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines.md`  
Required report: `source-3/project-documentation/tools/leaser/Agents/Agent-B006/research/0002GG-ColorStringChattingMessageMeasureLines-source-quality.md`

No by-* target/support documentation and no `by-memory/-coverage-report.md` file were edited.

## Final recommendation

- Keep `CANONICAL_OWNER:00002Z` and `EMITTER_UIDS:00002Z`.
- Keep source placement under [UID:0000I5] `by-file/Chatting.md`, generated route `auto-generated/NexusTK/social/Chatting.cpp`.
- Raise the target from `84/90` to `86/90`.
- Populate first-draft C++ for this exact method. This target is code-entry eligible: `RECONSTRUCTABLE:TRUE`, nonblank emitter, valid generated route through `ColorStringChattingMessage` -> `Chatting`, and `(84 + 90) / 2 = 87 > 85`.
- Do not split the target. The exact method body is `0x00483630-0x0048369a`; surrounding bytes are padding.
- Do not rename the behavior as real wrapping. The shared helper at `0x004bb070` currently returns constant `1`, so the observed behavior is one display line, while the source/call shape still passes text, length, and width through a draw/context receiver.

## Target facts

| Item | Value |
| --- | --- |
| UID | `0002GG` |
| Range | `0x00483630-0x0048369a` |
| Size | `0x6a` / 106 bytes |
| Kind | source-authored virtual class method |
| Current owner/emitter | [UID:00002Z] `ColorStringChattingMessage` |
| Current source file route | [UID:0000I5] `Chatting`, `NexusTK/social/Chatting.cpp` |
| Vtable xref | `0x0061527c`, `ColorStringChattingMessage` vtable slot index 4 / offset `+0x10` |
| Unique callee | `0x004bb070` / [UID:00016F] `ConstantLineCountHelper` |
| Direct call sites to helper | `0x00483658` and `0x0048368c` |
| Ordinary direct callers | none; virtual dispatch only |
| Return convention | method ends with `ret 8`, cleaning two post-`this` arguments |

## Evidence checked

Documentation read:

- `tools/leaser/Agents/Supervisor.md`, `.codex/AGENTS.md`, `tools/leaser/Agents/Agent-B006/goal.md`
- `by-structure.md`, `inference_research.md`, `by-project-structure/proposed-source-tree.md`
- Target [UID:0002GG] page
- [UID:00002Z] `by-class/ColorStringChattingMessage.md`
- [UID:0000I5] `by-file/Chatting.md`
- [UID:0002GD] constructor, [UID:0002GE] destructor body, [UID:0002GF] clone, [UID:0002GH] draw-with-tables
- [UID:0003AT] `ChattingVtableData`
- [UID:0002EV] `ChattingPaneOnPaint`
- [UID:0002EX] `ChattingPaneComputeLineCount`
- [UID:00001X] `ChattingPane`
- [UID:00016F] `ConstantLineCountHelper`
- [UID:000030] `ColorStringSystemMessage`, [UID:0000OE] `SystemMessagePanes`, and [UID:0001J6] `SystemMessagePanes` aggregate
- Existing B011 cluster report `tools/leaser/Agents/Agent-B011/research/0002F9-0002G8-0002GA-0002GE-0002GF-0002GG-ChattingPaintColorMessage-source-quality.md`

Generated/exported evidence checked:

- `resources/exported_data/functions/0x00483630.json`
- `resources/exported_data/functions/0x004bb070.json`
- `resources/exported_data/functions/0x00587ae0.json`
- `resources/exported_data/functions/0x0047f8d0.json`
- `resources/exported_data/master_vtables.json`
- `source-3/project-documentation/auto-generated/-ag-memory-coverage.md`
- `source-3/project-documentation/auto-generated/NexusTK/social/Chatting.cpp`
- `source-3/simroot_v2/class_ColorStringChattingMessage.cpp`
- `source-3/simroot_v2/class_ColorStringSystemMessage.cpp`

Direct tool checks run:

- IDA MCP endpoint check at `http://127.0.0.1:13337/mcp`: unavailable in this session (`Unable to connect to the remote server`). Existing live-IDA-backed docs and exported IDA/Ghidra function data were used instead.
- Raw PE byte read against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` confirmed target/helper bytes and padding.

## Boundary and bytes

The function range is exact and should not be split:

```text
0x0048362b: cc cc cc cc cc
0x00483630: 55 8b ec 56 8b f1 57 8b 4e 04 8b d1 8d 7a 02 90 66 8b 02 83 c2 02 66 85 c0 75 f5 2b d7 8b 7d 0c 57 d1 fa 52 51 8b 4d 08 e8 13 7a 03 00 b9 01 00 00 00 66 3b c8 7e 08 5f 8b c1 5e 5d c2 08 00 8b 76 04 8b d6 8d 4a 02 66 8b 02 83 c2 02 66 85 c0 75 f5 2b d1 8b 4d 08 57 d1 fa 52 56 e8 df 79 03 00 5f 0f b7 c0 5e 5d c2 08 00
0x0048369a: cc cc cc cc cc cc
```

The helper boundary is also exact:

```text
0x004bb06a: cc cc cc cc cc cc
0x004bb070: b8 01 00 00 00 c2 0c 00
0x004bb078: cc cc cc cc cc cc cc cc
```

The helper bytes are `mov eax, 1; ret 0x0c`.

## Behavior and source shape

Observed body, decoded from bytes and exported IDA decompilation:

1. Saves `this` in `ESI`.
2. Reads the owned UTF-16 text pointer from `this + 0x04`.
3. Manually scans the string until a zero 16-bit code unit.
4. Computes a character count equivalent to `wcslen(m_text)`.
5. Loads the second post-`this` argument from `[ebp+0x0c]` as the width and pushes it as the third helper stack argument.
6. Pushes the computed text length.
7. Pushes the text pointer.
8. Loads the first post-`this` argument from `[ebp+0x08]` into `ECX`.
9. Calls `0x004bb070`.
10. Compares the returned low 16 bits as a signed short against `1`.
11. If the first result is less than `1`, returns `1`.
12. If the first result is at least `1`, reloads `m_text`, repeats the UTF-16 length scan, reloads the first argument into `ECX`, calls the same helper again with `(text, length, width)`, zero-extends the returned low 16 bits, and returns it as an `int`.

The duplicated length scan and duplicated helper call are real code shape, not a decompiler artifact. Because `0x004bb070` currently returns constant `1`, the current binary behavior is always one line. The repeated call still matters for source-shape fidelity and should be preserved in the first draft unless a later behavior-only rewrite intentionally collapses it.

## Signature inference

Best current source-facing signature:

```cpp
int ColorStringChattingMessage::MeasureLines(GrafPort *drawContext, int width);
```

Confidence: medium-high for the two-argument method shape and width position, medium for the exact `GrafPort *` type spelling.

Evidence:

- The method epilogue is `ret 8`, so it has two post-`this` stack arguments.
- `ChattingPane::OnPaint` calls the message measure vslot with `push 0x30f` / `push this` in current layout and `push 0x198` / `push this` in old layout. Those are widths `783` and `408`; the preceding `push this` is the draw/pane context.
- The target method loads `[ebp+0x08]` into `ECX` immediately before each `0x004bb070` call. This means the first post-`this` argument is not the width, and it is not entirely absent: it is forwarded as the helper receiver/context.
- The target pushes the text pointer, text length, and width before the helper call. The helper returns with `ret 0x0c`, cleaning exactly those three stack arguments. That matches a direct non-virtual `__thiscall` helper on the draw/context object: `drawContext->GetTextLineCount(text, length, width)`.
- The sibling `ColorStringSystemMessage::GetLineCount` at `0x00587ae0` has the same shape: a vtable-backed message method with two post-`this` arguments, first argument loaded into `ECX`, second argument used as width, and two calls to `0x004bb070`.

Rejected signatures:

- `int MeasureLines(int width)`: rejected because the method cleans two stack arguments and forwards the first in `ECX`.
- `int MeasureLines(int width, void *context)`: rejected because `[ebp+0x0c]`, the second post-`this` argument, is pushed as helper width; `[ebp+0x08]` is loaded into `ECX`.
- `short MeasureLines(...)`: callers often narrow the result, but the method returns an `int` register value with the second helper result zero-extended through `movzx eax, ax`. Use `int` in source and document the effective 16-bit line-count return.
- `unsigned int MeasureLines(...)`: less source-natural than `int`; the first comparison treats the helper result as signed 16-bit for the minimum-one-line clamp.
- `int MeasureLines(void *drawContext, int width)`: acceptable fallback if the shared draw-context type is not ready, but less source-quality than `GrafPort *drawContext` because nearby text/draw helper docs increasingly route these draw-context methods to `GrafPort`.

## Field/type inference

Recommended class field name for `this + 0x04`: `m_text`.

Evidence:

- Constructor [UID:0002GD] computes the source UTF-16 byte length including terminator, allocates storage, copies the incoming text, and stores the resulting pointer at `+0x04`.
- Destructor [UID:0002GE] releases the pointer at `+0x04` if non-null.
- Clone [UID:0002GF] forwards `+0x04` to the constructor, and the constructor performs the deep copy.
- Draw [UID:0002GH] reads `+0x04` and renders it through wide-text draw helpers.
- This target reads `+0x04` and scans it as 16-bit text.

Rejected alternatives:

- `m_pText` is acceptable style-wise but less consistent with current Chatting support C++ and generated `class_ColorStringChattingMessage.cpp`, which already uses `m_text`.
- `m_wideText` is descriptive but not used elsewhere in the class docs.
- `m_label` or `m_message` is too broad; the field is the owned UTF-16 buffer, not the message object itself.
- Borrowed/external text pointer is rejected because constructor allocates/copies and destructor frees it.

## Helper `0x004bb070` source-quality resolution

Best descriptive helper role for caller docs: `GrafPort::GetTextLineCount` or `DrawContext::GetTextLineCount`.

Current helper page name `ConstantLineCountHelper` is accurate for binary behavior. For source code, avoid names that imply implemented wrapping, such as `MeasureWrappedTextLines`, unless the helper itself is later replaced by a nontrivial implementation during reconstruction.

Owner/source-placement ranking for the helper, based on this target's evidence:

1. Shared GrafPort/text drawing support. Evidence: address locality immediately inside the text/draw helper region around `0x004bad70-0x004bb0db`, the `ECX` receiver/context call shape, and cross-consumer use from both chat-message and system-message classes.
2. Broad social message source if final project structure folds `Chatting.cpp` and `SystemMessagePanes.cpp` together. Evidence: current callers are only `ColorStringChattingMessage::MeasureLines` and `ColorStringSystemMessage::GetLineCount`, both social/message entry classes.
3. Current [UID:0000OE] `SystemMessagePanes` owner. This is acceptable as historical/current documentation state for [UID:00016F], but weaker as final source ownership if `Chatting.cpp` stays separate because a file-local SystemMessagePanes helper could not naturally be called by Chatting.
4. Private `ColorStringChattingMessage` helper. Rejected because `ColorStringSystemMessage` calls the same physical helper.

This report does not directly change [UID:00016F]; another B-agent assignment is active for that helper. The target implementation should still add the above ranking and the ECX receiver detail to support docs if accepted, or explicitly cross-reference the helper report if it supersedes this recommendation.

## Relationship to sibling docs

### [UID:0002GF] clone

Clone confirms the object layout and text ownership: it allocates `0x1c` bytes and calls the constructor with `m_text`, foreground/background palette IDs, custom flag, and RGB fields. It should keep `m_text` rather than `m_textPointer` or a shallow-copy name because the constructor duplicates the text.

### [UID:0002GH] draw

Draw confirms the first virtual argument family is a draw/GrafPort context passed from `ChattingPane::OnPaint`. The target measure method receives the same context kind and forwards it to `0x004bb070` in `ECX`. Draw also confirms `m_text` is UTF-16 and belongs to `ColorStringChattingMessage`.

### [UID:00002Z] class

The class page should keep the field table from constructor/draw/clone/destructor evidence and add a method-note detail: `MeasureLines(GrafPort *drawContext, int width)` uses `m_text`, forwards `drawContext` as the helper receiver, passes `(m_text, length, width)`, and clamps to at least one line. It should not describe the method as true wrapping unless the helper implementation changes.

### [UID:0000I5] Chatting

The file route is still `social/Chatting.cpp`. [UID:0002EV] `ChattingPaneOnPaint` already calls `message->MeasureLines(this, messageWidth)` in first-draft C++; this report confirms that call shape is correct. The file doc should add that the method's second parameter is the width (`783` or `408`) and the first parameter is a draw/context receiver used only by the shared text-line helper.

### [UID:00016F] ConstantLineCountHelper

Support update should add this target's exact byte/calling-shape evidence:

- two calls from `0x00483658` and `0x0048368c`;
- target loads context argument into `ECX` before each call;
- target pushes `m_text`, UTF-16 length, and width as the three stack arguments;
- helper body is still `return 1; ret 0x0c`;
- current behavior is constant one line, not actual wrapping.

### [UID:000030] ColorStringSystemMessage and [UID:0000OE] SystemMessagePanes

These docs already record the same helper shape for `0x00587ae0`. They should add the same ECX receiver/context nuance and avoid saying the first argument is unused without qualification. It is unused by the target method's own arithmetic and by the current constant helper body, but it is forwarded as the helper receiver.

## Heuristic / inference reanalysis and validation

| Issue | Best conclusion | Evidence | Rejected alternatives |
| --- | --- | --- | --- |
| Method name | `ColorStringChattingMessage::MeasureLines` | Existing target/class docs, `ChattingPaneOnPaint` first-draft call, vtable slot role, returns row count used in `13 * rows` layout | `GetTextLength`, `DrawTextMeasure`, `CountWrappedLines` as final name; these either describe the wrong behavior or overstate wrapping |
| Text field | `m_text` at `+0x04` | constructor alloc/copy, destructor free, clone forward/deep-copy through constructor, draw and measure UTF-16 use | borrowed pointer, `m_label`, `m_message`, raw `mbr_0x4` |
| First argument | draw/context receiver, best `GrafPort *drawContext` | caller pushes `this` before width; target loads `[ebp+8]` into `ECX` before helper calls | width, unused padding, or an event pointer |
| Second argument | width in pixels | caller pushes `0x30f` / 783 or `0x198` / 408; target pushes `[ebp+0x0c]` before helper calls | context argument, color id, line height |
| Helper name | descriptive `GetTextLineCount`; current binary page `ConstantLineCountHelper` remains valid | helper is `mov eax,1; ret 0x0c`; callers pass text/length/width through a receiver | `MeasureWrappedTextLines` or `WrapText` as current behavior |
| Return type | source `int`, effective 16-bit count | first result compared as signed short; second result returned via `movzx eax, ax`; callers use low 16 bits | pure `short` formal return or unsigned-only result |
| Repeated scan/call | preserve in first-draft C++ | exact byte body duplicates the length scan and helper call | collapse to one call in target source before a behavior-only policy is accepted |
| Ownership | class-owned method under `ColorStringChattingMessage`, emitted via `Chatting.cpp` | vtable slot `0x0061527c`, class docs, Chatting file route, generated ag-memory route | helper/file owner, SystemMessagePanes, standalone global function page |
| Split/range | no split | exact modeled size `0x6a`, `0xcc` before/after, one unique callee outside range | absorb padding or helper |
| C++ readiness | first-draft C++ appropriate | code gate cleared and signature/behavior are now resolved enough | no-code proof based only on helper final name uncertainty |

Remaining uncertainty:

- Exact original helper owner/name for `0x004bb070` is unresolved outside this target. This should cap the target at `86/90`, but it does not block first-draft C++ because a descriptive receiver method preserves the observed call shape and behavior.
- Exact final `GrafPort *` versus broader draw-context type should be reconciled with [UID:00005V] `GrafPort` and draw-context docs. If implementers are not ready to expose a `GrafPort` method, use `void *drawContext` in the target block and a documented `GetTextLineCount(drawContext, text, length, width)` adapter, but note that this is less ABI-shaped than the observed ECX receiver call.

## First-draft C++ recommendation

Recommended target `RECONSTRUCTION_CPP`:

```cpp
int ColorStringChattingMessage::MeasureLines(GrafPort *drawContext, int width)
{
    const wchar_t *text = m_text;
    int textLength = WideStringLength(text);
    int lineCount = drawContext->GetTextLineCount(text, textLength, width);

    if ((short)lineCount < 1)
        return 1;

    text = m_text;
    textLength = WideStringLength(text);
    return (unsigned short)drawContext->GetTextLineCount(text, textLength, width);
}
```

Implementation notes:

- `WideStringLength` is a placeholder for the project's existing UTF-16 length helper or direct `wcslen`; do not add a new memory-page helper for the scan. The binary inlines the scan twice.
- `GrafPort::GetTextLineCount` is the best current helper-source shape for the direct `ECX` receiver plus three stack args. If the helper page later resolves to another shared draw-context class, rename the type/method there and update this block consistently.
- Preserve the second helper call in this target because the bytes contain two calls. Do not rewrite to `return max(lineCount, 1)` unless the supervisor explicitly accepts behavior-only simplification.
- Do not add source for `0x004bb070` inside this target; that helper is a separate memory page.

## Recommended exact target changes

Target path: `source-3/project-documentation/by-memory/0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines.md`

Apply:

- `COMPLETION:84 -> 86`
- `CONFIDENCE:90` unchanged
- owner/emitter unchanged
- Add rebuild handling `source-authored` if the target page does not already include it.
- Replace the old blank-C++ reason with: first-draft C++ is appropriate under the current combined-score/emitter gate; helper final spelling remains a support-doc issue, not a target no-code proof.
- Insert the first-draft C++ block above.
- Add sections or paragraphs containing:
  - exact byte/padding evidence;
  - vtable xref `0x0061527c`;
  - helper call sites `0x00483658` and `0x0048368c`;
  - `ret 8` two-argument method signature;
  - first argument forwarded in `ECX` as helper receiver/context;
  - second argument used as width;
  - duplicated UTF-16 length scan and duplicated helper call;
  - signed 16-bit minimum-one-line check;
  - zero-extended 16-bit second result;
  - current helper behavior `return 1`, therefore no real wrapping in the current binary.

## Recommended support-doc changes

Update these support docs during an accepted implementation callback:

1. `source-3/project-documentation/by-class/ColorStringChattingMessage.md`
   - Add source-facing method signature `int MeasureLines(GrafPort *drawContext, int width)`.
   - Add field name `m_text` for `+0x04`.
   - Add that measure vtable slot uses context receiver + width and currently resolves to one line because the shared helper returns `1`.
   - Record rejected alternatives: not true wrapping, not private helper, not borrowed text.

2. `source-3/project-documentation/by-file/Chatting.md`
   - Add that the `ColorStringChattingMessage` measure method is source-ready and routes through `Chatting.cpp`.
   - Add that `ChattingPaneOnPaint`'s `message->MeasureLines(this, messageWidth)` call shape matches the target bytes: first arg context, second arg width.

3. `source-3/project-documentation/by-memory/0x0047f8d0-0x0047fbc5.ChattingPaneOnPaint.md`
   - Add a small cross-note that the called message vslot is [UID:0002GG], with first argument `this` as draw/context receiver and second argument `783`/`408` as width.

4. `source-3/project-documentation/by-memory/0x0047fc70-0x0047fd3b.ChattingPaneComputeLineCount.md`
   - Add that its message measure virtual target uses the same signature and should remain `MeasureLines(drawContext, width)` / `GetLineCount(context, width)` style, not a one-argument width-only call.

5. `source-3/project-documentation/by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md`
   - Add the target-specific call-shape details from this report.
   - Add helper owner/source-placement ranking: shared GrafPort/text support strongest, broad social message source second, SystemMessagePanes-only weaker, ColorStringChattingMessage-private rejected.
   - Add `GrafPort::GetTextLineCount` / `DrawContext::GetTextLineCount` as source-facing candidate names while keeping `ConstantLineCountHelper` as current binary behavior.

6. `source-3/project-documentation/by-class/ColorStringSystemMessage.md` and `source-3/project-documentation/by-file/SystemMessagePanes.md`
   - Add that `0x00587ae0` has the same receiver/context + width signature pattern; avoid saying the first argument is simply unused without noting it is forwarded in `ECX`.

7. `source-3/project-documentation/by-file/GrafPort.md` and/or [UID:00005V] `by-class/GrafPort.md` if the implementation accepts the helper-source ranking
   - Add `0x004bb070` as a candidate tiny text-line-count receiver helper for later helper report reconciliation, but do not move ownership from [UID:00016F] in this pass unless the supervisor explicitly accepts that broader helper change.

## Exact implementation callback instructions

If this report is accepted, send B006 an implementation callback with the following exact work:

1. Lease and update target `source-3/project-documentation/by-memory/0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines.md`.
2. Apply metadata `COMPLETION:86`, `CONFIDENCE:90`, owner/emitter unchanged.
3. Insert the first-draft C++ block from this report.
4. Incorporate all target facts listed above at report-level detail, including bytes/padding, vtable xref, helper call sites, argument ordering, ECX receiver forwarding, duplicate scans/calls, clamp semantics, constant-helper caveat, rejected alternatives, and score rationale.
5. Lease/update support docs listed in the previous section. Preserve negative evidence and rejected alternatives.
6. Do not edit `by-memory/-coverage-report.md`; place the exact replacement row below in implementation notes for supervisor-owned application.
7. Run scoped validators from `source-3/project-documentation` and report exact results.

## Exact supervisor-owned coverage row

Replace the current [UID:0002GG] row in `source-3/project-documentation/by-memory/-coverage-report.md` with:

```text
        - [UID:0002GG][0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines](by-memory/0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines.md) 0x00483630-0x0048369a | virtual method | ColorStringChattingMessageMeasureLines : reconstructable : 86% : strong : Exact ColorStringChattingMessage virtual line-measure method; vtable slot 0x0061527c, five-byte leading and six-byte trailing padding, ret-8 two-argument signature, owned m_text UTF-16 pointer at +0x04, first post-this draw/context argument forwarded in ECX to the shared helper, second post-this argument used as width, duplicated UTF-16 length scans, two calls to the shared constant-one line-count helper at 0x004bb070, signed 16-bit minimum-one-line clamp, and zero-extended 16-bit return.
```

## Validator commands

Not run during this report-only pass because `--apply` validation can update by-* docs/generator state and the assignment forbids by-* edits before supervisor review.

Expected commands after accepted implementation, run from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0002GG-ColorStringChattingMessageMeasureLines-source-quality-removed.md](0002GG-ColorStringChattingMessageMeasureLines-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected result: each edited file validates cleanly; validator may refresh generated route metadata. `auto-generated/-ag-memory-coverage.md` should continue to show [UID:0002GG] as emitting through `auto-generated/NexusTK/social/Chatting.cpp`, now with formal C++ instead of an empty emitter marker after generated output refresh.

## Changed files in this report pass

Created:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B006/research/0002GG-ColorStringChattingMessageMeasureLines-source-quality.md`

Modified:

- none outside the B006 research report path.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0002GG-ColorStringChattingMessageMeasureLines-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"0002GG"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002GG-ColorStringChattingMessageMeasureLines-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/0002GG-ColorStringChattingMessageMeasureLines-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002GG"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
