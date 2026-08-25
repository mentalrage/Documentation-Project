** TARGET-REPORT-UID:00016F **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B002 source-quality report: [UID:00016F] ConstantLineCountHelper

Report date: 2026-06-19  
Agent: B002  
Assignment: B-agent report-only source-quality and heuristic pass  
Target: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004bb070-0x004bb078.ConstantLineCountHelper.md`  
Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\00016F-ConstantLineCountHelper-source-quality.md`

## Scope and restrictions

This is a report-only pass. I did not edit the target by-memory page, support by-* docs, generated output, or `by-memory/-coverage-report.md`.

The target currently stands at `COMPLETION:82`, `CONFIDENCE:90`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000OE`, and `EMITTER_UIDS:0000OE`, with a blank formal C++ block. The existing page correctly identifies the function as a constant one-line helper and records four callers, but it leaves source shape, final helper name, owner route, and C++ readiness under-resolved.

## Executive recommendation

Raise the target to `COMPLETION:87`, keep `CONFIDENCE:90`, keep `RECONSTRUCTABLE:TRUE`, and keep the current owner/emitter `[UID:0000OE] SystemMessagePanes` for now, with an explicit ownership caveat: this helper is semantically shared by `ColorStringChattingMessage` and `ColorStringSystemMessage`, and is physically located in the GrafPort/text-helper island, so `[UID:0000OE]` is a pragmatic current emitter rather than proof of original file-local ownership.

Emit first-draft source-style C++. The best source-facing shape is a callback-compatible constant line-count helper:

```cpp
int GetSingleLineCount(void * /*context*/, const wchar_t * /*text*/, int /*length*/, int /*width*/)
{
    return 1;
}
```

The binary-level type should preserve the hidden context receiver:

```cpp
int __thiscall GetSingleLineCount(void *context, const wchar_t *text, int length, int width);
```

The helper body ignores all inputs and returns one row. The `ecx` receiver is still important source evidence because both live caller families load the pane/context pointer into `ecx` immediately before the call and pass the text pointer, UTF-16 length, and width as stack arguments. A plain 3-argument `__stdcall` spelling hides that shared callback interface.

## Evidence checked

### Target and agent instructions

- Read `tools/leaser/Agents/Agent-B002/goal.md`.
- Read the target page `by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md`.
- Confirmed target metadata, caller list, current helper-name caveat, current owner/emitter, and blank C++ block.

### Binary bytes and function boundary

Binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

Exact bytes:

```asm
004bb06a: cc cc cc cc cc cc          ; padding after previous function
004bb070: b8 01 00 00 00             ; mov eax, 1
004bb075: c2 0c 00                   ; ret 0x0c
004bb078: cc cc cc cc cc cc cc cc    ; padding before next function
```

The target boundary `0x004bb070-0x004bb078` is exact. There are no callees, no data reads, no global references, no vtable writes, no stack locals, and no unwind or exception scaffolding. The `ret 0x0c` proves the helper pops three stack arguments. The additional context argument is carried in `ecx` by the callers, not on the stack.

### Route and xref evidence

Direct calls to `0x004bb070`:

- `0x00483658`, inside `ColorStringChattingMessage::MeasureLines` at `0x00483630-0x0048369a`.
- `0x0048368c`, inside the same `ColorStringChattingMessage::MeasureLines`.
- `0x00587b09`, inside `ColorStringSystemMessage::GetLineCount` at `0x00587ae0-0x00587b53`.
- `0x00587b45`, inside the same `ColorStringSystemMessage::GetLineCount`.

No direct calls or absolute VA data references were found beyond those live call sites. The four direct calls are enough to treat this as live source-shaped code, not dead padding or an ignored linker artifact.

Positive control route checks:

- `0x00483630` has a vtable pointer at `0x0061527c`, identifying the live `ColorStringChattingMessage` virtual line-count slot.
- `0x00587ae0` has a vtable pointer at `0x0062d70c`, identifying the live `ColorStringSystemMessage` virtual line-count slot.
- `0x0058af40` has vtable pointers at `0x0062d6c4` and `0x0062d6e8`, identifying header/footer marker line-count slots that return one directly.
- Other text helpers such as `0x004ce100` and `0x0047fc70` have normal direct calls and were used as route-pattern controls.

### Caller shape: ColorStringChattingMessage

`by-memory/0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines.md` and disassembly of `0x00483630-0x0048369a` were checked.

The method:

- Is vtable-backed through `0x0061527c`.
- Reads UTF-16 text from object offset `+0x04`.
- Scans the UTF-16 text manually to compute length.
- Reads the width argument from `[ebp+0x0c]`.
- Loads the pane/context pointer from `[ebp+0x08]` into `ecx`.
- Pushes `width`, `length`, and `text`, then calls `0x004bb070`.
- Compares the helper result through `ax` and clamps the virtual return to at least one line.
- Repeats the length scan and helper call on the non-clamped path, then returns `movzx eax, ax`.

Important source-quality inference: even though the helper currently returns one, the caller source was not written as a raw `return 1;` in this method. The caller preserves a general line-count callback pattern: compute text length, call a line-count helper with context/text/length/width, then clamp to one or more rows.

### Caller shape: ColorStringSystemMessage

`by-class/ColorStringSystemMessage.md`, `by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md`, `by-memory/0x0062d6f0-0x0062d714.ColorStringSystemMessageVtableData.md`, and disassembly of `0x00587ae0-0x00587b53` were checked.

The method:

- Is vtable-backed through `0x0062d70c`.
- Reads UTF-16 text from object offset `+0x04`.
- Scans the text to compute length.
- Loads the width from the second argument and sign-extends it with `movsx edi, word ptr [ebp+0x0c]`.
- Loads the pane/context pointer from `[ebp+0x08]` into `ecx`.
- Pushes `width`, `length`, and `text`, then calls `0x004bb070`.
- Applies the same `max(1, helper(...))` virtual-return structure as the Chatting message method.

The two caller families are structurally similar enough that `0x004bb070` should be documented as a shared color-string/message line-count callback helper. It is not specific to system messages alone.

### Neighbor and source-family checks

Checked support pages:

- `by-file/SystemMessagePanes.md`
- `by-class/ColorStringSystemMessage.md`
- `by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md`
- `by-memory/0x0062d6f0-0x0062d714.ColorStringSystemMessageVtableData.md`
- `by-memory/0x0058af40-0x0058af48.HeaderFooterSystemMessageDefaultTrueVirtual.md`
- `by-class/ColorStringChattingMessage.md`
- `by-memory/0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines.md`
- `by-memory/0x0047fc70-0x0047fd3b.ChattingPaneComputeLineCount.md`
- `by-file/GrafPort.md`
- `by-class/GrafPort.md`
- `by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md`
- `by-memory/0x004bad70-0x004baf92.DrawTextInRect.md`
- `by-memory/0x004bafa0-0x004bb0db.SimpleHelpTextPartPaneTextEffects.md`
- `by-memory/0x004ce100-0x004ce160.ItemHelpPaneCountTextLines.md`
- `auto-generated/NexusTK/social/SystemMessagePanes.cpp`

Findings:

- `0x004bb070` is physically embedded in the `0x004b8bf0-0x004bb8c4` GrafPort/text-helper island and is adjacent to help-text text-effect helpers.
- The adjacent `SimpleHelpTextPartPaneTextEffects` page already separates this helper from the text-effect functions and should keep doing so.
- `DrawTextInRect` and `ItemHelpPaneCountTextLines` are real text measurement/wrapping implementations with loops and helper calls. `0x004bb070` is not a reduced version of those helpers; it has no loop, no `CountCharsFittingWidth`/`0x004ba8b0` call, and no text-width calculation.
- Header/footer system-message line-count slots at `0x0058af40` return one directly with `ret 8`. They are related at the virtual-interface level but are not callers of `0x004bb070`.
- The generated output currently places an empty marker for `[UID:00016F]` in `auto-generated/NexusTK/social/SystemMessagePanes.cpp`. That matches the current owner/emitter but does not prove original sole ownership because a Chatting caller also uses the helper.

## Source-facing names and signatures

### Recommended source-facing name

Primary recommendation:

```cpp
GetSingleLineCount
```

Acceptable alias if local docs prefer verb-first measurement naming:

```cpp
CountSingleLineText
```

Avoid leaving the target as `sub_4BB070` or `ConstantLineCountHelper` in source-facing prose. `ConstantLineCountHelper` is a useful documentation title, but it describes the reverse-engineering fact rather than a plausible source name. `GetSingleLineCount` is the best source-style name because:

- The function returns a line count.
- Its behavior is intentionally constant one-line.
- It is used by two color-string message virtual line-count methods.
- It does not compute wrapping, measure pixel width, draw text, or mutate state.

### Binary-level signature

Recommended IDA/local type:

```cpp
int __thiscall GetSingleLineCount(void *context, const wchar_t *text, int length, int width);
```

Argument evidence:

- `context`: hidden `ecx`, loaded from the caller's first virtual argument, likely a pane or measurement context. It is ignored by the helper.
- `text`: first stack argument at callee entry, UTF-16 text pointer from message field `+0x04`.
- `length`: second stack argument, caller-scanned UTF-16 length.
- `width`: third stack argument, caller-provided target width; system message path sign-extends a 16-bit width before passing it.

The binary return is used as a row count through `ax` by both callers and then widened. A source `int` return is still the simplest and safest spelling. A `short` return would match the caller's `ax` usage but is less likely source-style for a line count and would overfit the compiled compare.

### Source-style signature for documentation C++

```cpp
int GetSingleLineCount(void * /*context*/, const wchar_t * /*text*/, int /*length*/, int /*width*/)
```

This source-style declaration deliberately exposes four logical arguments even though the binary uses `ecx` plus three stack slots. That keeps the source C++ readable while preserving the important callback/context fact in prose and IDA type recommendations.

## Rejected alternatives

### Rejected: no-code compiler/linkage artifact

Rejected. The function is an exact live function with four direct calls from two vtable-backed virtual methods. It has real padding on both sides and a conventional `mov eax, 1; ret 0x0c` body. There is no evidence that it is exception glue, an optimizer artifact, or a linker-retained orphan. It should receive first-draft C++.

### Rejected: source was just `return 1;` inside each caller

Rejected for the target itself. The callers compute text length, load context into `ecx`, pass width, and call the helper twice through a common clamp pattern. A fully inlined per-caller `return 1;` would not explain the shared standalone function and identical helper call sequence.

The higher-level virtual methods may simplify behaviorally to one line today, but their source shape still goes through a helper.

### Rejected: wrapped text measurement helper

Rejected. True wrapping helpers such as `ItemHelpPaneCountTextLines` and GrafPort text-fit helpers call measurement routines and loop through the text. `0x004bb070` has no text access and no callee. It is callback-compatible with a line measurement interface, but its implementation is a deliberate single-line policy.

### Rejected: `GrafPort` class member

Rejected as a class member. Physical locality inside the GrafPort/text-helper island is real, but the helper has no `GrafPort` receiver, no GrafPort field access, no drawing state, and no GrafPort vtable route. The `ecx` value comes from the message virtual method's pane/context argument, not from a GrafPort object. A shared text utility or file-level helper under the broader GrafPort/text area remains plausible, but not a `GrafPort::` method.

### Rejected: `ColorStringSystemMessage`-only helper

Rejected as sole semantic ownership. `ColorStringSystemMessage::GetLineCount` uses the helper, and current generated output routes the target through `SystemMessagePanes.cpp`, but `ColorStringChattingMessage::MeasureLines` also calls the same helper twice. A SystemMessagePanes-only source helper would create a cross-file dependency from Chatting with no evidence of class-specific state.

### Rejected: `ColorStringChattingMessage`-only helper

Rejected for the same reason. The system-message family also uses it through a vtable-backed method.

### Conditional alternative: shared text utility owner

This is plausible and should stay documented. If the project later creates or already recognizes a shared color-string/text-measure utility owner, `0x004bb070` would fit better there than in a single message family. I do not recommend changing the owner/emitter in this pass because the current project routing already emits the target under `[UID:0000OE] SystemMessagePanes`, and no existing by-file support page was found that cleanly owns this exact shared helper.

## Owner, emitter, and source placement ranking

1. Current practical route: keep `CANONICAL_OWNER:0000OE`, `EMITTER_UIDS:0000OE`.
   - Evidence: target already routes there; generated `NexusTK/social/SystemMessagePanes.cpp` contains the UID marker; the system-message caller is vtable-backed and documented; this keeps implementation scoped.
   - Required caveat: docs should say this is a pragmatic emitter route, not proof that the original source helper was private to `SystemMessagePanes.cpp`.

2. Better long-term semantic route if support structure changes: shared text/color-string utility near the GrafPort/text helper island.
   - Evidence: physical address locality near GrafPort text helpers; both Chatting and SystemMessagePanes call it; helper has no message-specific field access.
   - Why not recommend now: current docs do not expose a precise shared utility owner for this helper, and changing owner/emitter would have broader generated-output implications.

3. Direct class ownership by `ColorStringSystemMessage` or `ColorStringChattingMessage`.
   - Rejected as sole ownership because the helper is shared by both families.

4. No-owner/non-emitting route.
   - Rejected because the function is live, reconstructable, and has source-shaped callers.

## First-draft C++ readiness

Ready. This target is a small, exact, standalone helper with no unresolved side effects. The only remaining uncertainty is the original file/namespace and exact spelling of the helper name, not behavior or reconstructability.

Recommended first-draft target C++:

```cpp
int GetSingleLineCount(void * /*context*/, const wchar_t * /*text*/, int /*length*/, int /*width*/)
{
    return 1;
}
```

Implementation note for the target doc: prose must preserve that the binary calling convention is `__thiscall`-like: `ecx` carries the ignored context and `ret 0x0c` pops `text`, `length`, and `width`. The source-style C++ block may use a normal helper signature for readability, but the IDA/local type recommendation should include `__thiscall`.

No-code proof is not justified. The helper is reconstructable, live, bounded, and behaviorally exact.

## Open questions resolved or narrowed

### Final helper name

Best inference: `GetSingleLineCount`. Confidence medium-high. The exact original spelling cannot be proven from symbols or literals, but the behavior and call context support this over raw address names. `CountSingleLineText` is an acceptable alias if the local source model prefers `Count...` helpers.

### Callback-compatible stub versus shared text-measure helper

Resolved as callback-compatible single-line policy helper. It participates in the same interface shape as a text-measure callback, but it deliberately ignores context/text/length/width and returns one. It is not a wrapping/measurement implementation.

### Compiler/linkage artifact

Resolved as no. Live direct calls from two vtable-backed methods and exact function padding make source-shaped helper code much more likely than compiler artifact.

### Caller and reachability

Resolved. Four direct calls, two each from `ColorStringChattingMessage::MeasureLines` and `ColorStringSystemMessage::GetLineCount`. Both caller methods are vtable-backed. No additional direct callers were found in this pass.

### Owner/source placement

Partially resolved with a practical recommendation. Keep current owner/emitter `[UID:0000OE]` for implementation continuity, but explicitly document that semantic ownership is shared and that a future shared text utility owner would be a better structural home if the project introduces one.

### C++ readiness

Resolved as ready. Emit first-draft C++ in the target on implementation callback.

## Details to incorporate into target page

Recommended target metadata:

```yaml
COMPLETION:87
CONFIDENCE:90
RECONSTRUCTABLE:TRUE
CANONICAL_OWNER:0000OE
EMITTER_UIDS:0000OE
```

Recommended summary additions:

- Exact bytes are `b8 01 00 00 00 c2 0c 00`, with six bytes of `0xcc` padding before and eight bytes of `0xcc` padding after.
- The helper returns one and ignores all inputs.
- The binary helper pops three stack arguments with `ret 0x0c`.
- Both live caller families load a pane/context pointer into `ecx` immediately before the call, so the best binary-level signature is `int __thiscall GetSingleLineCount(void *context, const wchar_t *text, int length, int width)`.
- Direct calls are `0x00483658`, `0x0048368c`, `0x00587b09`, and `0x00587b45`.
- Caller `0x00483630-0x0048369a` is `ColorStringChattingMessage::MeasureLines`, vtable-backed at `0x0061527c`.
- Caller `0x00587ae0-0x00587b53` is `ColorStringSystemMessage::GetLineCount`, vtable-backed at `0x0062d70c`.
- Both callers scan UTF-16 text length from message field `+0x04`, pass text/length/width, and clamp the helper result to at least one line.
- The helper is semantically shared between Chatting and SystemMessagePanes and physically located in the GrafPort/text helper island; current `[UID:0000OE]` owner/emitter is a pragmatic generated-output route, not conclusive original private ownership.
- It is not a real wrapping helper and should not be merged into `DrawTextInRect`, `ItemHelpPaneCountTextLines`, or the adjacent help-text text-effect helpers.
- First-draft C++ is ready and should be populated.

Recommended C++ block:

```cpp
int GetSingleLineCount(void * /*context*/, const wchar_t * /*text*/, int /*length*/, int /*width*/)
{
    return 1;
}
```

## Support-doc update recommendations

### `by-memory/0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines.md`

Add or refresh:

- Name `0x004bb070` as `GetSingleLineCount` / constant line-count callback helper.
- State that `ecx` carries the ignored pane/context pointer while stack args are text, length, and width.
- Keep the current caller source shape: scan text length, call helper, clamp to at least one line. Do not reduce the method documentation to only `return 1;` even though the current helper body makes the result one.
- Note that helper naming/signature blocker is resolved enough for source-style C++ in the helper target; this caller may still need its own first-draft pass if its doc is separately assigned.

### `by-class/ColorStringChattingMessage.md`

Add or refresh:

- Method `0x00483630` uses the shared single-line text-count helper and returns at least one display row.
- Field `+0x04` is the owned UTF-16 text pointer already used by constructor/destructor/clone docs.
- The class participates in the same line-count callback path as `ColorStringSystemMessage`.

### `by-class/ColorStringSystemMessage.md`

Add or refresh:

- `GetLineCount` at `0x00587ae0` uses shared helper `0x004bb070`/`GetSingleLineCount`.
- Width is sign-extended from a 16-bit value in the system-message path before the helper call.
- The method is a vtable-backed virtual at `0x0062d70c` and clamps helper results to at least one row.

### `by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md`

Add or refresh:

- `00016F` is not system-message-private; it is also called by `ColorStringChattingMessage::MeasureLines`.
- Current aggregate owner/emitter route is acceptable for generated output, but docs should preserve the shared-helper caveat.
- Do not merge the helper with header/footer direct-one-line virtuals at `0x0058af40`; those are separate marker-entry implementations of the same interface expectation.

### `by-file/SystemMessagePanes.md`

Add or refresh:

- `ColorStringSystemMessage::GetLineCount` source shape calls the shared single-line helper.
- The helper can be emitted through `NexusTK/social/SystemMessagePanes.cpp` under the current project route, with a note that original source placement may have been a shared text utility.

### `by-memory/0x004bafa0-0x004bb0db.SimpleHelpTextPartPaneTextEffects.md`

Add or refresh:

- Keep `00016F` split out. Its physical address lies in the same text-helper island, but its behavior and callers are shared color-string line-count callback behavior, not help-text outline/shadow drawing.

### `by-file/GrafPort.md` and `by-class/GrafPort.md`

Optional support note:

- `0x004bb070` is physically in the GrafPort/text helper island and is a plausible future shared text utility route, but it is not a `GrafPort` class method because it reads no GrafPort state and receives message measurement context in `ecx`.

### `by-memory/0x004ce100-0x004ce160.ItemHelpPaneCountTextLines.md`

Optional cross-reference:

- Contrast `ItemHelpPaneCountTextLines` as a real wrapped-line counter with `00016F` as a callback-compatible single-line policy helper.

## IDA rename, type, and comment recommendations

Function rename:

```text
sub_4BB070 -> GetSingleLineCount
```

If name collision or local convention favors verb-object:

```text
sub_4BB070 -> CountSingleLineText
```

Recommended type:

```cpp
int __thiscall GetSingleLineCount(void *context, const wchar_t *text, int length, int width);
```

Recommended function comment:

```text
Shared color-string/message line-count callback. Callers pass pane/context in ecx and text, UTF-16 length, and width on the stack; this implementation ignores all inputs and returns one display row. Called by ColorStringChattingMessage::MeasureLines and ColorStringSystemMessage::GetLineCount.
```

Recommended call-site comments:

- At `0x00483658` and `0x0048368c`: `GetSingleLineCount(context, text, length, width); context is caller arg, text is ColorStringChattingMessage +0x04.`
- At `0x00587b09` and `0x00587b45`: `GetSingleLineCount(context, text, length, width); width was sign-extended from 16-bit system-message width arg.`

Confidence:

- Rename: medium-high.
- Type/calling convention: high for `ecx` plus three stack args; medium for exact source spelling.
- Function comment: high.

## Exact implementation checklist for a supervisor callback

1. Update target metadata in `by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md`:
   - `COMPLETION:82` -> `COMPLETION:87`
   - Keep `CONFIDENCE:90`.
   - Keep `RECONSTRUCTABLE:TRUE`.
   - Keep `CANONICAL_OWNER:0000OE` and `EMITTER_UIDS:0000OE`, but add the shared-helper/source-placement caveat.

2. Replace the unresolved source-shape caveat with:
   - Exact bytes and boundary.
   - `ret 0x0c` stack cleanup.
   - Hidden `ecx` context loaded by both caller families.
   - Best binary type `int __thiscall GetSingleLineCount(void *context, const wchar_t *text, int length, int width)`.
   - Four direct calls and vtable-backed caller evidence.
   - Rejected alternatives: compiler artifact, system-message-only owner, GrafPort class method, real wrapped text helper.

3. Populate the target first-draft C++ block with:

```cpp
int GetSingleLineCount(void * /*context*/, const wchar_t * /*text*/, int /*length*/, int /*width*/)
{
    return 1;
}
```

4. Update support docs listed above with report-level detail, especially:
   - `by-memory/0x00483630-0x0048369a.ColorStringChattingMessageMeasureLines.md`
   - `by-class/ColorStringChattingMessage.md`
   - `by-class/ColorStringSystemMessage.md`
   - `by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md`
   - `by-file/SystemMessagePanes.md`
   - `by-memory/0x004bafa0-0x004bb0db.SimpleHelpTextPartPaneTextEffects.md`
   - Optional: `by-file/GrafPort.md`, `by-class/GrafPort.md`, `by-memory/0x004ce100-0x004ce160.ItemHelpPaneCountTextLines.md`

5. If autogen is part of the callback, regenerate or rescore the generated `NexusTK/social/SystemMessagePanes.cpp` output from the new target C++ block. Do not hand-edit generated output unless local workflow explicitly expects it.

6. Do not edit `by-memory/-coverage-report.md`; supervisor should apply the exact replacement row below.

## Exact supervisor-owned coverage replacement row

Replace the current `00016F` row in `by-memory/-coverage-report.md` with:

```text
    - [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper](by-memory/0x004bb070-0x004bb078.ConstantLineCountHelper.md) 0x004bb070-0x004bb078 | shared constant line-count callback | ConstantLineCountHelper : reconstructable : 87% : very strong : B002 2026-06-19 source-quality reanalysis confirms exact bytes `b8 01 00 00 00 c2 0c 00`, six-byte pre-padding and eight-byte post-padding, no callees/state/global use, and four direct calls from the vtable-backed `ColorStringChattingMessage::MeasureLines` and `ColorStringSystemMessage::GetLineCount` methods. Both callers pass a pane/context receiver in `ecx` plus text pointer, UTF-16 length, and width on the stack, so source shape is callback-compatible `GetSingleLineCount(context, text, length, width)` returning one line; the helper ignores all inputs, returns `1`, and caller virtuals still clamp to at least one line. Current owner/emitter can remain [UID:0000OE] for generated output, but docs must note this is semantically shared with Chatting and physically located in the GrafPort/text helper island; direct `ColorStringSystemMessage`/`ColorStringChattingMessage` and GrafPort-class ownership are rejected as sole canonical owners. First-draft C++ is ready as a small shared helper unless supervisor chooses a broader shared text utility owner first.
```

## Expected validation commands after implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` after implementation:

> Executable block R001 was removed from this report and preserved verbatim in [00016F-ConstantLineCountHelper-source-quality-removed.md](00016F-ConstantLineCountHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If optional GrafPort or ItemHelpPane support notes are edited:

> Executable block R002 was removed from this report and preserved verbatim in [00016F-ConstantLineCountHelper-source-quality-removed.md](00016F-ConstantLineCountHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If adding target C++ triggers generated output:

> Executable block R003 was removed from this report and preserved verbatim in [00016F-ConstantLineCountHelper-source-quality-removed.md](00016F-ConstantLineCountHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected result: validators should accept the revised target/support docs after any local formatting/autofix changes. If autogen tooling is separate from validator file mode in the active workflow, run the local autogen/rescore command before validating generated output.

## Final B002 conclusion

`00016F` should no longer be treated as a blank-C++ low-completion helper. The exact function is a live, bounded, reconstructable constant line-count callback shared by `ColorStringChattingMessage` and `ColorStringSystemMessage`. Its source-quality blockers are narrowed to exact original file/name spelling, not behavior. The best implementation path is to keep current owner/emitter routing for now, document the shared/GrafPort-island caveat, raise completion to `87`, and emit the small first-draft helper body.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00016F-ConstantLineCountHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"00016F"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00016F-ConstantLineCountHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00016F-ConstantLineCountHelper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00016F"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
