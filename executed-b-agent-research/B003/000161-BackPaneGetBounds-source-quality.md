** TARGET-REPORT-UID:000161 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B003 Source-Quality Report: [UID:000161] BackPaneGetBounds

Assignment id: `B003-goal2-backpane-get-bounds-source-quality-000161-20260618`  
Report date: 2026-06-18  
Primary target: `by-memory/0x004b8e00-0x004b8e11.BackPaneGetBounds.md`  
Required output path: `tools/leaser/Agents/Agent-B003/research/000161-BackPaneGetBounds-source-quality.md`

## Current Recommendation

[UID:000161] should remain a BackPane-owned, BackPane-emitting source accessor under [UID:00000S]/[UID:0000HO]. The current `CANONICAL_OWNER:00000S` and `EMITTER_UIDS:00000S` are correct. The target should no longer keep formal C++ blank.

Recommended target state:

```text
COMPLETION:87
CONFIDENCE:91
RECONSTRUCTABLE:TRUE
CANONICAL_OWNER:00000S
EMITTER_UIDS:00000S
Formal C++: populate first-draft accessor code.
```

Reason: raw evidence confirms an exact 17-byte `__thiscall` leaf that copies the inherited Pane local bounds rectangle from `this+0x44` into a caller-supplied rectangle pointer and preserves that pointer in `EAX` as the return value. The function has no callees, has clean `int3` padding on both sides, has broad direct call fan-in from BackPane/help/map/UI code, and has no independent pointer/vtable/table route. This is not compiler-only glue; it is a small source-authored convenience accessor that belongs in `BackPane.cpp`.

The only remaining uncertainty is original spelling of the rectangle type and member name. That uncertainty should not block first-draft source because the behavior, owner, signature shape, and field role are now defensible. Use the project documentation type name `RectBounds` and inherited field name `m_bounds` or the supervisor's preferred `Pane::m_localBounds` alias.

## Evidence Checked

Read before analysis:

```text
tools/leaser/Agents/Supervisor.md
tools/leaser/Agents/Agent-B003/goal.md
tools/leaser/Agents/Agent-B003/notes.md
```

Note: the local `goal.md` and `notes.md` still described the previous BowGauge assignment when checked. I followed the user's newer BackPane assignment and treated those stale files only as standing B-agent/report-only rules.

Target/support pages checked:

```text
by-memory/0x004b8e00-0x004b8e11.BackPaneGetBounds.md
by-class/BackPane.md
by-file/BackPane.md
by-memory/0x00467510-0x00467b2d.BackPaneAndBackGroundPane.md
by-memory/0x00467830-0x0046795c.BackPaneConstructionAndDestruction.md
by-memory/0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor.md
by-memory/0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1.md
by-memory/0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2.md
by-memory/0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3.md
by-memory/0x0067a740-0x0067a744.g_pBackPane.md
by-memory/0x00544460-0x00545086.PaneCore.md
by-class/Pane.md
by-type/by-struct/PaneLayout.md
by-type/by-struct/RectBoundsLayout.md
```

Read-only generated/state inputs checked:

```text
project-level/-auto-completion-stats.md
auto-generated/-ag-memory-coverage.md
auto-generated/NexusTK/map/BackPane.cpp
by-memory/-coverage-report.md
```

Prior B-report searches checked:

_Executable command block removed from the research report; preserved in [000161-BackPaneGetBounds-source-quality-removed.md](000161-BackPaneGetBounds-source-quality-removed.md)._

Relevant prior-report facts found:

- `Agent-B001/research/executed/000105-0002F4-0002F6-0002F7-0002F8-chatting-modify-height-source-quality.md` already treated `0x004b8e00` as `BackPane::GetBounds` and described it as copying `this+0x44`.
- `Agent-B003/research/executed/0002EP-0002EU-0002EW-chatting-pane-core-source-quality.md` records a direct call from `0x0047fbe8`.
- `Agent-B002/research/executed/0001O2-swallowlayerpane-core-source-quality.md` treats `BackPane::GetBounds` as a dependency of SwallowLayerPane helpers, not as Swallow-owned code.
- `Agent-B001/research/executed/00024A-UserPaneVirtualDword1340F8Accessor-source-quality.md` records the `0x005ab7c4` caller.

IDA MCP status:

```text
list_mcp_resources
```

returned no resources. No IDA MCP database resource was available in this session. I therefore used existing IDA-backed docs plus raw PE/disassembly checks against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

Raw PE facts checked:

```text
Image base: 0x00400000
.text VA/RVA: 0x00401000 / 0x00001000
.text raw: 0x00000400
Target VA: 0x004b8e00
Target raw offset: 0x000b8200
```

Raw bytes around the target:

```text
0x004b8df0-0x004b8e20:
8d 41 1c c3 cc cc cc cc cc cc cc cc cc cc cc cc
55 8b ec 8b 45 08 0f 10 41 44 0f 11 00 5d c2 04 00
cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc
```

Disassembly:

```asm
0x004b8df0: lea     eax, [ecx + 0x1c]
0x004b8df3: ret
0x004b8df4: int3
...
0x004b8dff: int3

0x004b8e00: push    ebp
0x004b8e01: mov     ebp, esp
0x004b8e03: mov     eax, dword ptr [ebp + 8]
0x004b8e06: movups  xmm0, xmmword ptr [ecx + 0x44]
0x004b8e0a: movups  xmmword ptr [eax], xmm0
0x004b8e0d: pop     ebp
0x004b8e0e: ret     4

0x004b8e11: int3
...
0x004b8e1f: int3
```

Boundary facts:

- The exact modeled half-open range `0x004b8e00-0x004b8e11` is correct.
- The predecessor ends at `0x004b8df3`, followed by 12 bytes of `int3` padding from `0x004b8df4-0x004b8dff`.
- The successor starts at `0x004b8e20`, after 15 bytes of `int3` padding from `0x004b8e11-0x004b8e1f`.
- There are no embedded branches, no fallthrough body, no EH frame, no jump table, and no callees.
- Calling convention is `__thiscall`: `ECX` is the BackPane receiver, `[EBP+8]` is the only explicit stack argument, and `ret 4` callee-pops that argument.
- The function returns the destination pointer in `EAX` because `EAX` is loaded from `[EBP+8]` and is not clobbered after the `movups` store.

Direct rel32 caller scan:

```text
103 direct rel32 calls to 0x004b8e00:
0x00451ee2, 0x0045b5e8, 0x00467a0b, 0x00467a19, 0x00467b51, 0x00468271,
0x00468440, 0x00468777, 0x00468a28, 0x00468b14, 0x0047fbe8, 0x004806e7,
0x00480b09, 0x00495504, 0x00495683, 0x004957f7, 0x00495877, 0x00495ae9,
0x00495b8a, 0x00495d3b, 0x00495dab, 0x00498e8c, 0x00498f0e, 0x00499a69,
0x00499d17, 0x0049ff5a, 0x004b054a, 0x004b6812, 0x004c6b4f, 0x004c70fc,
0x004c80fd, 0x004c8987, 0x004ead6c, 0x004eafc5, 0x004ed8de, 0x004edacc,
0x004edf25, 0x004ef363, 0x004ef5ac, 0x004f0e8d, 0x004f10c6, 0x004f1187,
0x004f2d77, 0x00500956, 0x00504402, 0x0050629e, 0x005094f6, 0x0050be91,
0x0050d86e, 0x0050da6f, 0x0050e225, 0x0050e65f, 0x0050e7d7, 0x0050eb5c,
0x0050eec7, 0x0050effb, 0x0050fe5c, 0x00511978, 0x00512b1d, 0x00522053,
0x00538266, 0x0053858e, 0x0053dcde, 0x00544ba7, 0x00549970, 0x00549a96,
0x0054b0a8, 0x00559c2d, 0x00559c38, 0x00559c79, 0x00559c95, 0x00559d6a,
0x00559d85, 0x00559f25, 0x00559fb3, 0x00559fce, 0x0055a0f1, 0x0055a10c,
0x0055a1da, 0x0055a1f5, 0x0055a460, 0x00599005, 0x00599125, 0x0059d228,
0x0059d288, 0x0059d458, 0x0059d498, 0x005a7aa6, 0x005aa57f, 0x005ab7c4,
0x005ae76b, 0x005aea06, 0x005af08b, 0x005af29d, 0x005afa4b, 0x005afbdf,
0x005b02cb, 0x005b045f, 0x005c2377, 0x005c2592, 0x005c2616, 0x005c279f,
0x005c28b7
```

Pointer/table route scan:

```text
raw little-endian dword target VA 0x004b8e00: 0 hits
raw little-endian dword target RVA 0x000b8e00: 0 hits
raw little-endian dword target raw offset 0x000b8200: 0 hits
raw little-endian dword target end VA 0x004b8e11: 0 hits
rel32 refs to 0x004b8e11: 0 hits
```

Positive-control pointer scan:

```text
raw little-endian dword successor VA 0x004b8e20: 270 hits
rel32 refs to successor 0x004b8e20: 15 hits
```

Interpretation: the scan detects pointer/table routes when they exist nearby. The absence of target VA/RVA/raw/end pointer hits is meaningful and supports the current direct-call-only helper route. The successor at `0x004b8e20` has heavy pointer/table presence; [UID:000161] does not.

Representative caller facts:

- `BackPane::OnPaint`/activation region calls `0x004b8e00` twice at `0x00467a0b` and `0x00467a19`, once per resource branch, before drawing backdrop resources. This is the strongest local BackPane-owned caller evidence.
- Help packet display pages [UID:00018K]/[UID:00018L]/[UID:00018M] record calls through the global/current BackPane path before positioning help UI from BackPane bounds.
- ChattingPane reports record `0x0047fbe8` as a direct caller using BackPane bounds for layout.
- Swallow/weather-related reports record `0x005c279f` and `0x005c28b7` as callers that consume BackPane bounds as a root display extent dependency. They do not imply Swallow ownership.
- UserPane-related reports record `0x005ab7c4` as a caller. Again, this is a consumer route, not owner evidence.

Generated output state:

- `auto-generated/NexusTK/map/BackPane.cpp` exists but is zero bytes at the time of this report.
- `auto-generated/-ag-memory-coverage.md` lists [UID:000161] as an emitting BackPane target with empty final C++.
- `project-level/-auto-completion-stats.md` still lists [UID:000161] at `82/90`.
- `by-memory/-coverage-report.md` lists [UID:000161] at `82% : strong`.

## Heuristic / Inference Reanalysis And Validation

### Source-Facing Helper Name

Best source-facing name: `BackPane::GetBounds`.

Evidence:

- Current target title already uses `BackPaneGetBounds`, and several independent support/research pages refer to the helper as `BackPane::GetBounds`.
- The body does exactly one accessor operation: it copies a 16-byte rectangle from a fixed object field to the caller's output rectangle.
- The broad caller set uses this routine as a common root-pane bounds query before positioning/drawing UI. That matches `GetBounds` much better than a feature-specific name such as `GetHelpBounds`, `GetScreenRect`, or `GetClientRect`.
- `PaneCore` already owns broader inherited geometry helpers such as `Pane::GetScreenBounds` and `Pane::SetBounds`. This target is a BackPane-specific public/convenience query layered on inherited `Pane` rectangle storage, not a generic Pane helper.

Rejected alternatives:

- `sub_4B8E00`: rejected as a generated placeholder. Raw behavior and caller context are sufficient for a descriptive source name.
- `BackPane::CopyBounds`: behaviorally accurate but less source-likely than `GetBounds` because the caller supplies an output pointer and the helper returns that pointer. Existing docs and prior B reports already converge on `GetBounds`.
- `BackPane::GetScreenBounds`: rejected because `PaneCore` has a distinct `Pane::GetScreenBounds` page, and this body copies `this+0x44` directly without adding ancestor origins. `PaneLayout` identifies `+0x44` as the local/bounds rectangle, not computed screen bounds.
- `Pane::GetBounds`: rejected for this target because the current owner/emitter, BackPane file/class docs, and caller style route through BackPane. The copied field is inherited from Pane, but the function body itself is BackPane-owned source in `BackPane.cpp`.
- Feature-caller names such as `SwallowGetBounds`, `HelpGetBounds`, or `ChattingGetBounds`: rejected because calls are spread across many feature modules. The helper is a root BackPane accessor consumed by features.

### Signature And Return Type

Best signature:

```cpp
RectBounds *BackPane::GetBounds(RectBounds *outBounds) const
```

Evidence:

- `ECX` is the receiver and `[EBP+8]` is the output pointer.
- `ret 4` confirms exactly one explicit argument under `__thiscall`.
- `movups xmm0, xmmword ptr [ecx+0x44]` copies exactly 16 bytes from the receiver.
- `movups xmmword ptr [eax], xmm0` writes exactly 16 bytes to the output pointer.
- `EAX` is initialized from the output pointer and remains unchanged through return. The binary therefore returns the output pointer.
- The function makes no calls and performs no null checks, matching a simple inline-like C++ accessor compiled out-of-line.

Rejected alternatives:

- `void BackPane::GetBounds(RectBounds *outBounds) const`: plausible source style because many callers may ignore the return value, but the binary preserves and returns `outBounds`. A pointer-returning draft best captures the actual ABI without adding behavior.
- `RectBounds BackPane::GetBounds() const`: rejected because the ABI is not a return-by-value hidden return in `ECX`; `ECX` is the receiver and `[EBP+8]` is the explicit output pointer. A C++ return-by-value member would usually use a hidden return buffer and shift the receiver, depending on compiler convention. Here the helper's shape is unambiguously receiver plus output pointer.
- `const RectBounds *BackPane::GetBounds() const`: rejected because the helper copies into caller storage rather than returning `this+0x44`.
- `RECT *` instead of `RectBounds *`: possible if final project type aliases to a Win32-like rectangle, but support docs already use `RectBoundsLayout`; the report should use `RectBounds` and allow the supervisor to map it to the established type alias if needed.

### Field And Type Role For `this+0x44`

Best field role: inherited `Pane` local/bounds rectangle at offset `+0x44`, exposed through BackPane as the root pane's current bounds.

Recommended source-facing field name:

```text
Pane::m_bounds
```

or, if the supervisor wants the name to make local-vs-screen semantics explicit:

```text
Pane::m_localBounds
```

Evidence:

- `PaneLayout.md` identifies `Pane +0x44` as the local/bounds rectangle. It is used by `Pane::Show`, `Pane::InvalidateRect`, `Pane::SetBounds`, and related geometry helpers.
- `PaneCore` records `Pane::SetBounds` storing/updating the same inherited geometry region and `Pane::InvalidateRect` consuming local bounds.
- `BackPane` docs currently describe a cached BackPane bounds at `this+0x44`. That is behaviorally right for this object but structurally imprecise: offset `+0x44` is inherited Pane layout, not a BackPane-only derived field.
- This target copies exactly 16 bytes from `+0x44`, matching a four-dword rectangle layout documented by `RectBoundsLayout`.
- BackPane construction/activation pages use the inherited Pane/GrafPort layout before BackPane-specific fields appear later in the object.

Rejected alternatives:

- BackPane-specific `m_cachedBounds` as a derived field: rejected as too owner-specific. The storage lives in inherited Pane layout.
- `m_screenBounds`: rejected because no parent-origin accumulation occurs in this body. The helper returns stored local/root bounds.
- `m_clientRect`: possible human-level meaning, but less aligned with existing project type docs than `m_bounds`/`m_localBounds`.
- A resource/draw rectangle unrelated to Pane: rejected because the same offset is repeatedly documented across Pane support and is used by generic Pane operations.

Impact on support docs:

- `by-class/BackPane.md` should keep the concept that BackPane exposes cached bounds, but should state that the storage is inherited from `Pane +0x44`.
- `by-file/BackPane.md` should identify [UID:000161] as a source-shaped accessor with first-draft C++ ready.
- `PaneLayout.md` does not require a new field if it already names `+0x44` as local/bounds rectangle. If the supervisor wants an alias, add `BackPane::GetBounds` as a consuming accessor example only.

### Caller/Reachability Route

Best reachability classification: ordinary direct-call helper with broad fan-in; no pointer/vtable/table entry route.

Evidence:

- Raw rel32 scan found 103 direct calls to target start.
- No VA/RVA/raw/end pointer hits were found for the target.
- The immediate successor at `0x004b8e20` has many pointer/table hits, proving the route scan detects such cases in the same neighborhood.
- Current docs and prior B reports show consumers in BackPane painting, help packet displays, ChattingPane layout, UserPane-related layout, Swallow/weather flight helpers, and other UI/map contexts.

Rejected alternatives:

- Vtable method: rejected because no target pointer appears in `.rdata` or other raw dword scans. The function is called directly.
- Hidden callback/table route: rejected by VA/RVA/raw scan and successor positive control.
- Dead/unused helper: rejected by 103 direct calls.
- Compiler-generated artifact: rejected because it has an ordinary nameable source role, heavy direct use, and no thunk/scalar-delete pattern.

### Source Placement And Owner Ranking

Owner ranking:

1. [UID:00000S] `BackPane` class / [UID:0000HO] `BackPane.cpp` file: accepted.
2. Inherited `Pane`/root UI helper: rejected as the owning source body, but accepted as the storage/type provider for `+0x44`.
3. Feature callers such as HelpPacketDisplay, ChattingPane, Swallow/weather, UserPane, or map panes: rejected as owners; they only consume the root bounds accessor.
4. Compiler-generated artifact/no source owner: rejected.

Evidence for accepted owner:

- Target page and coverage already route owner/emitter to [UID:00000S].
- `by-file/BackPane.md` includes `BackPane::GetBounds` in the BackPane source file contents.
- `by-class/BackPane.md` lists the method as a BackPane method.
- Local BackPane paint/activation code calls the function from the BackPane method cluster.
- The function's purpose is root pane bounds exposure, which belongs naturally to BackPane.

Why not `Pane.cpp`:

- `PaneCore` has separate generic geometry helpers and no evidence that this exact body is a Pane virtual/common method.
- The helper name and references are BackPane-specific in current docs.
- Direct call addresses are not vtable-dispatched generic Pane calls.

Why not Swallow/weather:

- Swallow docs use the helper as an external BackPane dependency to obtain display bounds.
- The helper predates and serves many non-Swallow callers.
- Swallow/weather ownership would be caller-biased and would conflict with local BackPane callers.

### Split/Range Decision

No split or merge is recommended.

Evidence:

- The target is an exact, self-contained 17-byte function.
- Clean `int3` padding separates it from predecessor and successor.
- The predecessor at `0x004b8df0` is a separate four-byte accessor returning `ecx+0x1c`.
- The successor at `0x004b8e20` is unrelated and has its own pointer/table route.
- The current range has no internal padding or multiple operations that would justify child pages.

### Current Documentation Validation And Contradictions

Validated current-doc claims:

- Exact target range `0x004b8e00-0x004b8e11`.
- Leaf/no-callee status.
- BackPane owner/emitter.
- Broad caller fan-in.
- `this+0x44` rectangle copy.
- Reconstructable status.

Contradicted or stale current-doc claims:

- "Formal C++ remains blank until BackPane class declarations and field names reach reconstruction-code gate" is stale under the current draft-code policy and this reanalysis. The target is reconstructable, owner/emitter routed, source-shaped, and the remaining original-name uncertainty is small enough for first-draft C++.
- Any wording that implies `+0x44` is a BackPane-only derived member should be refined. It is inherited `Pane` local/bounds storage used by BackPane.
- Any "do not emit final C++ yet" wording should be replaced with "populate first-draft C++ using inferred inherited field name."

## First-Draft C++ Recommendation

Populate formal C++ for [UID:000161]. This draft is scoped exactly to the target range and does not emit caller behavior.

```cpp
RectBounds *BackPane::GetBounds(RectBounds *outBounds) const
{
    *outBounds = m_bounds;
    return outBounds;
}
```

If the final class layout names the inherited Pane field more explicitly, use this equivalent spelling:

```cpp
RectBounds *BackPane::GetBounds(RectBounds *outBounds) const
{
    *outBounds = m_localBounds;
    return outBounds;
}
```

If the final project type uses `Rect` instead of `RectBounds`, only the type name should change:

```cpp
Rect *BackPane::GetBounds(Rect *outBounds) const
{
    *outBounds = m_bounds;
    return outBounds;
}
```

Why this is source-shaped rather than decompiler-shaped:

- It names the receiver and method according to established BackPane support docs.
- It models the single output rectangle parameter instead of exposing raw `ECX`, `EBP`, `XMM0`, or offsets.
- It preserves the actual ABI-visible return value without adding checks or side effects.
- It uses the inherited Pane field name rather than raw `*(this+0x44)` notation.
- It leaves vector/SSE implementation details out of the source, because `movups` is compiler codegen for copying a 16-byte rectangle.

No target-specific no-code proof exists. Keeping formal C++ blank would now be a policy/gate artifact rather than an evidence-backed source-shape decision.

## Recommended Metadata And Score Changes

Target [UID:000161]:

```text
COMPLETION: 82 -> 87
CONFIDENCE: 90 -> 91
RECONSTRUCTABLE: TRUE unchanged
CANONICAL_OWNER: 00000S unchanged
EMITTER_UIDS: 00000S unchanged
```

Rationale:

- Completion should rise because source-facing name, signature, owner, field role, range, reachability route, and first-draft C++ readiness are resolved.
- Confidence should rise slightly because raw PE evidence independently confirms the exact bytes, padding, direct-call route, absence of pointer/table route, and destination-pointer return.
- Do not raise to 95+ yet because original source spelling of the rectangle type/member (`RectBounds` vs `Rect`, `m_bounds` vs `m_localBounds`) remains inferred from support docs rather than proven from symbols/source.

Support doc score changes:

- No score change required for [UID:00000S] `BackPane` class or [UID:0000HO] `BackPane.cpp` file solely from this tiny accessor.
- If the supervisor applies a support-doc pass at the same time, BackPane class/file confidence can mention that [UID:000161] is no longer a blank-C++ blocker.

## Exact Supervisor Changes Required

### Target Page [UID:000161]

Placement: metadata block at top of `by-memory/0x004b8e00-0x004b8e11.BackPaneGetBounds.md`.

Replace current score lines with:

```text
COMPLETION:87
CONFIDENCE:91
```

Keep:

```text
RECONSTRUCTABLE:TRUE
CANONICAL_OWNER:00000S
EMITTER_UIDS:00000S
```

Placement: target summary/status section.

Replace any stale blank-C++/deferred wording with:

```text
Source-quality recheck 2026-06-18: first-draft C++ is now recommended. Raw PE evidence confirms an exact 17-byte `__thiscall` leaf at `0x004b8e00-0x004b8e11` (`55 8b ec 8b 45 08 0f 10 41 44 0f 11 00 5d c2 04 00`) with 12 leading and 15 trailing `int3` bytes. The helper copies the inherited Pane local bounds rectangle at `this+0x44` into the caller-supplied `RectBounds *` and returns that same pointer in `EAX`. It has no callees, 103 direct rel32 callers, and no target VA/RVA/raw/end pointer hits; the successor at `0x004b8e20` has many pointer hits as a positive control, so there is no hidden vtable/table route for this target.
```

Placement: source/ownership section.

Insert or replace with:

```text
Ownership remains [UID:00000S] `BackPane`, emitted through `BackPane.cpp` [UID:0000HO]. The storage at `+0x44` is inherited `Pane` local/bounds rectangle storage, not a BackPane-only derived field. BackPane owns this out-of-line convenience accessor because local BackPane paint/setup code and many feature callers query the root BackPane extent through this direct helper. Feature callers such as help packet display, ChattingPane, UserPane, and Swallow/weather helpers are consumers only and should not own or rename the target.
```

Placement: formal C++ block.

Set the formal C++ to:

```cpp
RectBounds *BackPane::GetBounds(RectBounds *outBounds) const
{
    *outBounds = m_bounds;
    return outBounds;
}
```

If `PaneLayout` finalizes the inherited member as `m_localBounds`, use:

```cpp
RectBounds *BackPane::GetBounds(RectBounds *outBounds) const
{
    *outBounds = m_localBounds;
    return outBounds;
}
```

### Support Doc [UID:00000S] `by-class/BackPane.md`

Placement: class layout / field notes mentioning `+0x44`.

Replace wording that describes `+0x44` as a BackPane-owned cached field with:

```text
BackPane inherits Pane's local bounds rectangle at `this+0x44`; [UID:000161] `BackPane::GetBounds` copies that inherited `RectBounds` storage to a caller-supplied output pointer and returns the pointer. Treat the field as `Pane::m_bounds` / `Pane::m_localBounds`, not as a BackPane-only derived member.
```

Placement: method inventory row or notes for `GetBounds`.

Replace/add:

```text
`BackPane::GetBounds(RectBounds *outBounds) const` ([UID:000161], `0x004b8e00-0x004b8e11`) is a 17-byte leaf accessor. It copies 16 bytes from inherited Pane bounds at `this+0x44` into `outBounds`, returns `outBounds`, has no callees, and has broad direct caller fan-in from BackPane paint/setup, help packet display, ChattingPane, UserPane, Swallow/weather, and other UI/map layout consumers. 2026-06-18 B003 recheck recommends first-draft C++.
```

### Support Doc [UID:0000HO] `by-file/BackPane.md`

Placement: source contents / function inventory.

Replace/add:

```text
`BackPane::GetBounds(RectBounds *outBounds) const` ([UID:000161], `0x004b8e00-0x004b8e11`) is source-shaped and should emit first-draft C++ in `BackPane.cpp`. The helper exposes BackPane's inherited Pane local bounds (`+0x44`) to feature layout callers; it is not a vtable callback, compiler thunk, or caller-owned helper.
```

### Optional Support Doc `by-type/by-struct/PaneLayout.md`

Only if the supervisor wants cross-reference enrichment; no required score change.

Placement: field row for `Pane +0x44`.

Append:

```text
[UID:000161] `BackPane::GetBounds` is a direct consumer of this inherited bounds rectangle: it copies the 16-byte field at `this+0x44` to a caller output rectangle and returns the output pointer.
```

## Coverage Report Replacement Text

Current supervisor-owned row in `by-memory/-coverage-report.md`:

```text
- [UID:000161][0x004b8e00-0x004b8e11.BackPaneGetBounds](by-memory/0x004b8e00-0x004b8e11.BackPaneGetBounds.md) 0x004b8e00-0x004b8e11 | method/accessor | BackPaneGetBounds : reconstructable : 82% : strong : BackPane-attached root-pane accessor copying the cached bounds from `this+0x44`; IDA confirms the exact SSE copy body, no callees, alignment at `0x004b8e11`, and broad BackPane/help/map/UI caller fan-in.
```

Recommended replacement row:

```text
- [UID:000161][0x004b8e00-0x004b8e11.BackPaneGetBounds](by-memory/0x004b8e00-0x004b8e11.BackPaneGetBounds.md) 0x004b8e00-0x004b8e11 | method/accessor | BackPane::GetBounds : reconstructable : 87% : very-strong : B003 2026-06-18 source-quality recheck confirms the exact 17-byte `__thiscall` leaf (`55 8b ec 8b 45 08 0f 10 41 44 0f 11 00 5d c2 04 00`), 12 leading and 15 trailing `int3` padding, no callees, `ret 4`, and destination-pointer return in `EAX`; the helper copies the inherited Pane local bounds rectangle at `this+0x44` into a caller `RectBounds *`, has 103 direct rel32 callers across BackPane/help/map/UI layout code, has no target VA/RVA/raw/end pointer hits and no vtable/table route (successor `0x004b8e20` has many pointer hits as a positive control), remains owned/emitted by [UID:00000S] BackPane, and is ready for first-draft C++ as `RectBounds *BackPane::GetBounds(RectBounds *outBounds) const`.
```

## Remaining Blockers

No target-level blocker remains for [UID:000161].

Minor unresolved naming choices that should not cap below the recommended score:

- Original rectangle type spelling is not symbol-proven. `RectBounds` is the best documentation-aligned type because `RectBoundsLayout.md` is the current support type. If the final generated source uses `Rect`, the C++ type can be mechanically renamed without changing behavior.
- Original inherited field spelling is not symbol-proven. `m_bounds` is the best compact source-facing name; `m_localBounds` is a defensible more explicit alias because this body copies stored local/root bounds rather than computed screen bounds.

These naming choices affect final polish only. They do not affect owner/emitter placement, reconstructability, range, behavior, or first-draft C++ readiness.

## Validation Commands For Supervisor

After applying the recommended target/support/coverage changes, run the normal documentation validation and regenerated reports. Exact command names vary by supervisor environment; the relevant checks are:

> Executable block R001 was removed from this report and preserved verbatim in [000161-BackPaneGetBounds-source-quality-removed.md](000161-BackPaneGetBounds-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Recommended raw evidence spot-check if needed:

> Executable block R002 was removed from this report and preserved verbatim in [000161-BackPaneGetBounds-source-quality-removed.md](000161-BackPaneGetBounds-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Regeneration/score commands should then confirm:

- [UID:000161] no longer appears in low reconstructable rows at `82/90`.
- `auto-generated/NexusTK/map/BackPane.cpp` includes the accessor once the emitter is regenerated.
- No generated source wrongly emits this helper under Swallow, ChattingPane, HelpPacketDisplay, PaneCore, or feature caller files.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/000161-BackPaneGetBounds-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:26","uid":"000161"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000161-BackPaneGetBounds-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/000161-BackPaneGetBounds-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000161"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
