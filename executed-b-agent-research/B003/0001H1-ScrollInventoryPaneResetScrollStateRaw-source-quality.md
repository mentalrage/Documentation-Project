** TARGET-REPORT-UID:0001H1 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001H1 ScrollInventoryPaneResetScrollStateRaw Source-Quality Research

Assignment: `B003-goal2-scroll-inventory-reset-source-quality-0001H1-20260618`

Primary target: [UID:0001H1] `by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md`

## Executive Recommendation

Keep [UID:0001H1] as an exact source-bearing raw helper child for `ScrollInventoryPane`. Change direct ownership and emission from the file UID [UID:0000KB][InventoryScrollPane] to the class UID [UID:0000CK][ScrollInventoryPane], because this is a class method-shaped body touching only `ScrollInventoryPane` instance fields and class-local helper methods. The class already routes to [UID:0000KB][InventoryScrollPane], and [UID:0000LS][NewInventoryPane] remains only a plausible final file-fold candidate, not the direct semantic owner.

Recommended metadata after supervisor application:

```text
COMPLETION:86
CONFIDENCE:89
CANONICAL_OWNER:0000CK
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000CK
```

Recommended source-facing name and signature:

```cpp
void ScrollInventoryPane::ResetScrollState();
```

The supervisor should populate formal first-draft C++ after applying the metadata update. The no-function/no-direct-xref state still blocks IDA function creation and live-caller claims, but it does not block reconstructing this bounded source-authored helper once the active combined-score/emitter gate is accepted. This matches the current treatment of the ScrollVolumePane raw reset helper and is stronger than the stale `95/95` wording now present in this target.

## Target

- Target UID: `0001H1`
- Target path: `by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md`
- Current state from assignment: `84/86`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000KB`, `EMITTER_UIDS:0000KB`, blank formal C++.
- Current documented role: raw method-shaped reset helper in the `ScrollInventoryPane` method island.
- Recommended final disposition: exact source-bearing child method, owned/emitted through [UID:0000CK][ScrollInventoryPane].

## Evidence Checked

Required workflow/source-placement references:

- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Agent-B003/goal.md`
- `tools/leaser/Agents/Agent-B003/notes.md`
- `by-structure.md`
- `inference_research.md`
- `by-project-structure/proposed-source-tree.md`

Primary and direct support docs:

- [UID:0001H1] `by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md`
- [UID:0001GZ] `by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md`
- [UID:0001H0] `by-memory/0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag.md`
- [UID:0000CK] `by-class/ScrollInventoryPane.md`
- [UID:0000KB] `by-file/InventoryScrollPane.md`
- [UID:0000LS] `by-file/NewInventoryPane.md`
- [UID:0001W0] `by-type/by-struct/ScrollInventoryPaneLayout.md`
- [UID:0001YQ] `by-type/by-vtable/ScrollInventoryPaneVtables.md`

Sibling/comparison and helper docs:

- [UID:0001GO] `by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md`
- [UID:0002DB] `by-memory/0x0041eb30-0x0041eb8c.FittingRoomScrollPaneResetScrollStateRaw.md`
- [UID:0001GY] `by-memory/0x00563200-0x0056325c.ScrollCollectionPaneClearHighlightRaw.md`
- [UID:0002LD] `by-memory/0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw.md`
- B003 executed report `tools/leaser/Agents/Agent-B003/research/executed/0002LB-0002LC-0002LD-ScrollVolumePaneRawInteraction-source-quality.md`
- [UID:0001K8] `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md`
- `by-memory/-coverage-report.md`

Fresh IDA MCP status:

- Direct JSON-RPC MCP initialization was attempted against `http://127.0.0.1:13337/mcp`.
- Result: `Unable to connect to the remote server`.
- This report does not claim fresh live IDA changes or fresh IDA function-table state. It uses existing live-IDA-backed docs plus fresh local PE scans.

Fresh local PE checked:

- File: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- SHA1: `c285b73dc7b54c9a0e28ff7591a9bdde2ac55f9a`
- Image base: `0x00400000`
- `.text`: `0x00401000-0x0060c4ac`
- `.rdata`: `0x0060d000-0x0066c0be`
- `.data`: `0x0066d000-0x0069ce24`
- `.rsrc`: `0x0069d000-0x006b2c38`

## Fresh PE Route Recheck

The route scan searched for:

- absolute VA dwords equal to target starts and related helper starts;
- image RVA dwords equal to those addresses minus image base;
- direct `.text` relative calls/jumps to target starts;
- direct branch/call targets into the target range;
- positive controls for modeled helper calls in the same cluster.

### Target And Positive-Control Results

| Target | VA dword hits | RVA dword hits | Direct branch/call hits | Interpretation |
| --- | ---: | ---: | ---: | --- |
| `0x005646b0` target raw start | `0` | `0` | `0` | No direct static route to the reset helper start found. |
| `0x005646ad` previous function end | `0` | `0` | `0` | No pointer/branch route to the previous modeled end. |
| `0x0056470c` target end/padding start | `0` | `0` | `0` | No pointer/branch route to the post-helper boundary. |
| `0x00564520` `UpdateFromDrag` | `0` | `0` | `2` | Positive control: calls at `0x005644bb` and `0x005644e4`, matching existing docs. |
| `0x00564460` active-state dispatcher | `0` | `0` | `3` | Positive control: calls at `0x005635d3`, `0x00563678`, and `0x00564432`. |
| `0x005640a0` part-rectangle helper | `0` | `0` | `13` | Positive control: calls include `0x005646e6` inside this target. |
| `0x00597600` timer remove wrapper | `0` | `0` | `45` | Positive control: broad generic `TimerHandler::RemovePendingTimers` fan-in; includes `0x005646c9` inside this target. |
| `0x005975e0` timer schedule wrapper | `0` | `0` | `163` | Positive control: broad generic timer schedule wrapper fan-in. |
| `0x005608a0` sibling spell reset start | `0` | `0` | `0` | Same no-route pattern as [UID:0001GO]. |
| `0x00565170`, `0x005651e0`, `0x00565490` ScrollVolume raw starts | `0` each | `0` each | `0` each | Same no-route pattern already accepted for raw ScrollVolumePane interaction helpers. |

Range-branch scan for `0x005646b0-0x0056470c` found one branch target inside the range:

```text
0x005646dd short -> 0x005646fd
```

This is the helper's own conditional skip over old-highlight invalidation. No external direct branch/call target into the range was found.

### Interior Pointer-Looking Artifacts

A full-file dword range scan found two pointer-looking hits into `0x005646b0-0x0056470c`, but both are false positives from unaligned instruction bytes, not table entries:

| Location | Value decoded by raw dword scan | Rejection reason |
| --- | --- | --- |
| `0x00508505` | `0x005646e8` | The dword begins at opcode byte `e8` in an unrelated call-instruction byte sequence (`... ff e8 46 56 00 00 b0 01 ...`). It is not aligned data and is not an address materialization. |
| `0x004e0330` | RVA form resolving near `0x005646c7` | The dword begins inside normal instruction bytes (`c7 46 16 00 ...`), not a data slot. It is not a VA/RVA table route. |

This strengthens the existing no-pointer-route note: there is no defensible hidden VA/RVA table route for the raw start or body. Only unaligned instruction-byte artifacts appear when scanning for any interior value.

### Boundary Bytes

Local bytes around the target match the documented boundary:

```text
0x005646ad: cc cc cc
0x005646b0: 55 8b ec 83 ec 14 ...
0x0056470b: c3
0x0056470c: cc cc cc cc
0x00564710: 55 8b ec ...
```

The target body itself appears exactly once in the PE. A tighter body subpattern from `0x005646c3-0x005646f9` also appears exactly once. The sibling [UID:0001GO] spell reset body has the same shape with different relative call displacements and `sub_560290` instead of `sub_5640a0`.

## Heuristic / Inference Reanalysis And Validation

### Raw No-Function / No-Direct-Xref Status

Existing live-IDA-backed docs say IDA does not model `0x005646b0` as a function and reports no xrefs/callers to the start. Fresh MCP was unavailable, but the local PE recheck validates the practical route evidence:

- no absolute-VA dword equal to `0x005646b0`;
- no RVA dword equal to `0x001646b0`;
- no direct call/jump to `0x005646b0`;
- no external branch/call into `0x005646b0-0x0056470c`;
- no real interior pointer-table hit after rejecting unaligned instruction-byte artifacts.

Best inference: this is a retained, source-authored private helper body in the inventory-scrollbar object file, but no current static route proves it is live in this executable. That is consistent with sibling raw reset helpers across fitting-room, collection, spell-inventory, and volume scroll panes. It is not evidence for generic `TimerMgr`, `ScrollBar.cpp`, or `NewInventoryPane` ownership.

Impact:

- Do not create an IDA function or apply IDA names/prototypes solely from this report.
- Keep the raw/no-route caveat in the page.
- The no-route caveat caps the score below final-audit quality, but it no longer justifies blank formal C++ once the source name, owner, fields, helpers, and boundaries are documented and the active code-entry gate is met.

### Hidden Caller / Table / Vtable Possibilities

Candidate routes checked:

- direct branch/call to raw start: rejected by PE scan;
- direct branch/call into the target range: rejected except for the helper's own internal conditional branch;
- absolute VA pointer to raw start or end: rejected;
- image RVA pointer to raw start or end: rejected;
- dword pointer into target body: rejected as unaligned instruction-byte artifacts;
- vtable slot route: rejected because [UID:0001YQ] maps class-specific virtual slots to paint, mouse, false-return, and timer handlers, not to this reset helper;
- generic timer callback route: rejected because `0x00597600` is an outgoing dependency and `+0xa4` is the timer-handler view being canceled, not a callback to this helper.

Remaining possibility: a computed runtime address route or dead-retained object-file method cannot be fully disproven from static bytes alone. No defensible static route is currently present. Treat the helper as source-authored but caller-unproven.

### Source-Facing Method Name And Signature

Best name:

```cpp
void ScrollInventoryPane::ResetScrollState();
```

Evidence:

- The page title, aggregate docs, and fitting-room sibling use the `ResetScrollState` vocabulary for the same timer/active/highlight reset behavior.
- The body does more than clear highlight: it removes pending timer events, clears the active part byte, invalidates a stale highlighted part, and clears the highlight byte.
- `ResetInteractionState` is valid for ScrollVolumePane, where the accepted docs use that name, but inventory/spell/fitting-room scroll panes use "scroll state" phrasing in current docs. Use `ResetScrollState` here for local consistency.

Rejected names:

- `ClearHighlight`: too narrow; misses timer removal and active-part clear.
- `StopTimer`: too narrow; misses active/highlight invalidation.
- `RemovePendingTimers`: this is the generic helper at `0x00597600`, not this method.
- `NewInventoryPane::ResetScrollState`: rejected because the touched fields are in the scrollbar object and the body's `this` is `ScrollInventoryPane`.
- `ScrollBar::ResetScrollState`: rejected because constructor, vtables, layout, part-rect helper, and sole constructor caller are inventory-private.

Signature:

- ABI: thiscall, no stack arguments, plain `retn`.
- Source: `void ScrollInventoryPane::ResetScrollState()`.
- The helper returns no meaningful value and all effects are on `this`.

### Exact Source-Bearing Child Status

This helper should remain an exact source-bearing child. It already has a precise `0x005646b0-0x0056470c` page, and no split is needed:

- predecessor `0x00564520-0x005646ad` is [UID:0001H0] `UpdateFromDrag`;
- `0x005646ad-0x005646b0` is padding;
- `0x005646b0-0x0056470c` is the raw reset helper;
- `0x0056470c-0x00564710` is padding;
- successor `0x00564710` starts `ScrollVolumePane`.

Do not merge the C++ into [UID:0001GZ] aggregate C++. Under `by-structure.md`, this by-memory page owns exactly the raw helper body and can emit its own method body through the class route once accepted.

### Field Names And Roles

Recommended source-facing field names for this target:

| Offset | Recommended name/type | Role and evidence |
| --- | --- | --- |
| `+0xa4` | inherited/embedded `TimerHandler` view, not a normal local scalar | Constructor installs tertiary vtable at `+0xa4`; reset passes `ecx=this+0xa4` to `0x00597600`. Use source calls such as `RemovePendingTimers()` rather than exposing pointer arithmetic in method C++. |
| `+0x103` | `char m_highlightPart` | Old highlighted/hovered scrollbar part. Reset reads it, invalidates its part rect when not `0xff`, then clears it to `0xff`. Sibling docs sometimes say hot/highlight part; `m_highlightPart` is the best shared source-facing name. |
| `+0x104` | `char m_activePart` | Active/pressed/tracking part. Reset clears it to `0xff` unconditionally. `UpdateFromDrag` and the active-state dispatcher use this byte to decide whether thumb/non-thumb interaction is in progress. |

Sentinel:

- Use `-1` or `0xff` as the no-part sentinel. In C++ code below, `-1` is used for readability because `char` storage compiles to `0xff`; docs should still record the byte-level value.

Rejected field interpretations:

- `+0x103` as active part: contradicted by reset using it only for old highlight invalidation and by `+0x104` carrying active/tracking state.
- `+0x104` as highlight: contradicted by raw reset clearing it before conditional old-highlight invalidation and by active-state/drag logic.
- `+0xa4` as widget-local "timer field": too vague. It is the tertiary `TimerHandler`/update-handler subobject view installed by class vtable setup and shared across timer-owning panes.

### Helper Names And Roles

`sub_597600` / `0x00597600`:

- Best source-facing name: `TimerHandler::RemovePendingTimers()` or `TimerHandler::RemoveAllPendingTimers()`.
- Existing [UID:0001K8] documents it as a generic timer-handler remove wrapper forwarding through `g_pTimerMgr` to `0x00597a10`.
- In this target, it is called as a method on the `this+0xa4` timer-handler view to cancel repeat-scroll/interaction timer state.
- Reject caller-biased names such as `InterfaceEfx::RemoveFromUpdateScheduler`, `FittingRoomDialog::CancelTimer`, or `ScrollInventoryPane::RemovePendingTimers` as ownership claims. It is a dependency, not this target's owner.

`sub_5640A0` / `0x005640a0`:

- Best source-facing name: `ScrollInventoryPane::GetPartRect(char part, RectBounds *outRect)` or `GetScrollbarPartRect`.
- Recommended final docs should prefer `GetPartRect` for consistency with FittingRoom/ScrollVolume sibling naming, while noting older class docs call it `GetScrollbarRegionRect`.
- Reset call shape pushes the old part byte and a stack rectangle pointer, then calls this helper with `ecx=this`; no stack cleanup follows at the callsite, so the callee has a thiscall-style two-argument signature.
- Role: compute the screen/pane rectangle for a scrollbar subpart (`0..4`) so the stale highlighted part can be invalidated through Pane vtable slot `+0x20`.

Pane virtual slot `+0x20`:

- Best source-facing name: `InvalidateRect(&rect)` or `Pane::InvalidateRect`.
- This target calls the virtual invalidation path only when old highlight is not `0xff`.

### Relationship To [UID:0001GZ] And [UID:0001H0]

[UID:0001GZ] `ScrollInventoryPane` aggregate:

- Validates the helper as the terminal source-authored body in the inventory-scrollbar range before `ScrollVolumePane`.
- Its current metadata is already `85/89` and routes through [UID:0000CK], but the shared `by-memory/-coverage-report.md` row is stale and still describes old below-gate parent blockers.
- Recommended support update: add the PE no-route scan and target owner/emitter correction; keep aggregate C++ blank unless it contains only `[[CHILDREN]]` routing or method inventory text.

[UID:0001H0] `UpdateFromDrag`:

- Predecessor modeled method at `0x00564520-0x005646ad`.
- It has direct callers at `0x005644bb` and `0x005644e4` from the active-state dispatcher at `0x00564460`, proving the neighboring interaction path is live.
- It uses the same state family: current position `+0xfe`, orientation `+0xfc`, range `+0x100`, drag point `+0x108/+0x10c`, and callback `0x004eba00`.
- The reset helper is the cleanup side of that interaction state family but remains caller-unproven.
- Its coverage row is stale (`82%` and below-gate wording) despite the page now being `85/89`.

### Sibling Comparison With [UID:0001GO]

[UID:0001GO] `ScrollSpellInventoryPaneResetScrollStateRaw` is structurally the closest sibling:

- same size and raw shape (`0x5c` bytes);
- same no-function/no-direct-xref status;
- same `TimerHandler::RemovePendingTimers` call at `0x00597600`;
- same state bytes `+0x103` and `+0x104`;
- same old-highlight invalidation through a class-local part-rect helper and Pane vtable slot `+0x20`;
- same three bytes of pre-padding and four bytes of post-padding.

Differences:

- [UID:0001GO] calls `0x00560290` (`ScrollSpellInventoryPane::GetPartRect`) instead of `0x005640a0`.
- [UID:0001GO] belongs to [UID:0000CN]/[UID:0000NJ] spell-inventory route, not [UID:0000CK]/[UID:0000KB].

Conclusion:

- The sibling validates that `0001H1` is part of a repeated source pattern, not random padding or compiler glue.
- This assignment should not directly modify [UID:0001GO], but it should be flagged for a later parity pass: it likely deserves the same active-gate wording, direct class-owner review, and possibly first-draft C++ once the spell class/file route is rechecked under current rules.

### Stale 95/95-Bar Wording

Current target text says final C++ remains blank under a `95/95` bar. That is stale. The active `by-structure.md` gate is:

```text
RECONSTRUCTABLE:TRUE, nonblank emitter route, and (COMPLETION + CONFIDENCE) / 2 > 85
```

The gate is minimum eligibility, not permission for weak code. For [UID:0001H1], after the recommended `86/89` and `EMITTER_UIDS:0000CK` update, the gate is met and the method body is short enough to support a first-draft C++ block. The raw no-function/no-route caveat should remain as an IDA/reachability caveat, not as a blanket formal-C++ blocker.

## Ranked Ownership And Source Placement Analysis

### 1. [UID:0000CK] ScrollInventoryPane Class

Evidence for:

- The helper's `this` pointer is a `ScrollInventoryPane` object.
- It touches class-local fields `+0x103`, `+0x104`, and the `+0xa4` timer view.
- It calls `ScrollInventoryPane::GetPartRect` at `0x005640a0`.
- It invalidates through the pane vtable on the same object.
- The direct class page is `85/86`, reconstructable, and routes through [UID:0000KB].
- Neighbor [UID:0001H0] already uses [UID:0000CK] as owner/emitter.

Evidence against:

- No direct caller to the raw start.
- Final standalone `InventoryScrollPane.cpp` versus folded `NewInventoryPane.cpp` file split remains open.

Decision:

- Accept as direct owner and emitter. The no-route caveat caps score but does not make the file UID a better semantic owner.

### 2. [UID:0000KB] InventoryScrollPane File

Evidence for:

- Current source route/file parent.
- Proposed source tree lists `InventoryScrollPane.cpp` under `ui/inventory/`.
- The file page is `86/88` and documents the full inventory scrollbar family.

Evidence against:

- `by-structure.md` says class methods should attach to the narrow semantic class owner when that class is known and clears the gate.
- Direct file ownership loses the method/class distinction and is inconsistent with [UID:0001H0].

Decision:

- Use [UID:0000KB] as the file route through [UID:0000CK], not as the direct canonical owner/emitter for this method page.

### 3. [UID:0000LS] NewInventoryPane File

Evidence for:

- Sole observed constructor caller for `ScrollInventoryPane` is `NewInventoryPane::NewInventoryPane` at `0x004eb4e4`.
- Final migration may fold `InventoryScrollPane.cpp` into `NewInventoryPane.cpp`.

Evidence against:

- This helper operates on `ScrollInventoryPane` fields and methods, not `NewInventoryPane` fields.
- The class/file support docs intentionally keep [UID:0000KB] as the current reviewed companion root.
- Constructor-only use is consumer evidence, not direct method ownership.

Decision:

- Reject direct ownership/emission to [UID:0000LS] for this target. Keep as a fold candidate in support docs.

### 4. [UID:0000NF] ScrollBar / Shared Scrollbar Helper Code

Evidence for:

- The reset pattern resembles other scroll controls.
- The timer/remove and invalidate idioms are shared across UI.

Evidence against:

- The constructor caller is inventory-private.
- The vtables and layout are class-specific.
- `sub_5640A0` is inventory-scrollbar part geometry, not the generic `ScrollPane::GetScrollPartRect`.
- The sibling spell/inventory/fitting/volume pages show repeated per-class generated bodies, not a single shared helper.

Decision:

- Reject shared `ScrollBar.cpp` ownership for this exact body. Shared infrastructure is a dependency only.

## Recommended Metadata And Score Changes

Primary target [UID:0001H1]:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000CK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000CK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Score rationale:

- Raise completion from `84` to `86` because the report resolves direct-owner routing, source-facing name/signature, helper names, field names, active code-entry policy, route-scan false positives, and first-draft C++ readiness.
- Raise confidence from `86` to `89` because existing live-IDA-backed docs and the fresh local PE scan agree on exact boundary, no-route status, helper dependencies, and sibling reset pattern.
- Do not raise to `90+` because fresh live IDA was unavailable, no raw-start caller/table route is proven, and final source-file fold remains open.

Support score notes:

- [UID:0001GZ] is already `85/89` in its page but has a stale coverage row; no metadata change needed.
- [UID:0001H0] is already `85/89` in its page but has a stale coverage row; no metadata change needed.
- [UID:0000CK] and [UID:0000KB] already clear the gate; no score change required.
- [UID:0001W0] can keep `85/88`; only field-name wording should be refreshed.

## First-Draft C++ Recommendation

Populate formal C++ for [UID:0001H1] after applying the recommended metadata and owner/emitter changes. This draft is limited to the target's own memory range and does not include sibling methods.

Recommended support assumptions:

```cpp
static const char kNoScrollPart = -1;
```

Recommended first-draft body:

```cpp
void ScrollInventoryPane::ResetScrollState()
{
    RectBounds rect;
    char oldPart;

    RemovePendingTimers();

    oldPart = m_highlightPart;
    m_activePart = kNoScrollPart;

    if (oldPart != kNoScrollPart) {
        GetPartRect(oldPart, &rect);
        InvalidateRect(&rect);
        m_highlightPart = kNoScrollPart;
    }
}
```

Population notes:

- `RemovePendingTimers()` represents the `this+0xa4` `TimerHandler` view call to `0x00597600`.
- `GetPartRect(oldPart, &rect)` represents `0x005640a0` with stack arguments `(part, outRect)`.
- `InvalidateRect(&rect)` represents the Pane virtual slot `+0x20` call.
- The conditional highlight clear mirrors the binary: if the old highlight is already `0xff`, the helper does not store `+0x103` again.
- If later support headers standardize the sentinel as `0xff` or `kNoPart`, use that existing name instead of `kNoScrollPart`.

Do not create an IDA function at `0x005646b0` merely because the source body is now recommended. IDA function creation should wait for a separate IDA-maintenance policy or a proven caller/table route.

## Exact Supervisor Changes Required

### Primary Target Metadata

Placement: top metadata block of `by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md`.

Replace:

```text
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

with:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000CK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000CK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

### Primary Target Source-Quality Paragraph

Placement: in `by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md`, add under `## Reconstruction Notes` or after `## Evidence`.

```markdown
## 2026-06-18 B003 Source-Quality Reanalysis

Keep this raw helper as `ScrollInventoryPane::ResetScrollState()`, an exact source-bearing child owned and emitted through [UID:0000CK][ScrollInventoryPane]. The previous direct file route through [UID:0000KB][InventoryScrollPane] remains the source-file route through the class, but the method's direct semantic owner is the class because the body touches `ScrollInventoryPane` fields `+0x103` and `+0x104`, calls `ScrollInventoryPane::GetPartRect` at `0x005640a0`, and cancels the class's `+0xa4` TimerHandler/update-handler view through `TimerHandler::RemovePendingTimers()` at `0x00597600`.

Fresh B003 local PE scanning of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` (MD5 `4247e04e20b65d6414c7238aa8ff5515`) found zero absolute-VA literals, zero RVA literals, and zero direct branch/call targets to raw start `0x005646b0`. It also found no external direct branch/call into `0x005646b0-0x0056470c`; the only branch target inside the range is the helper's own conditional skip `0x005646dd -> 0x005646fd`. Pointer-looking interior dword hits at `0x00508505` and `0x004e0330` are unaligned instruction-byte artifacts, not table entries. Therefore IDA function creation and live-caller claims remain blocked, but source reconstruction is now supported as a bounded retained/private helper body.

Use source-facing fields `m_highlightPart` for `+0x103`, `m_activePart` for `+0x104`, and a `TimerHandler`/update-handler base view for `+0xa4`. Use `GetPartRect(char part, RectBounds *outRect)` for `sub_5640A0` and generic `TimerHandler::RemovePendingTimers()` for `sub_597600`. Reject `NewInventoryPane`, `ScrollBar.cpp`, `TimerMgr`, and shared scrollbar-helper ownership for this exact body; those are caller/dependency or possible file-fold contexts, not the direct method owner.

The stale `95/95` final-C++ blocker is superseded by the active by-structure code-entry gate: `RECONSTRUCTABLE:TRUE`, nonblank emitter route, and `(COMPLETION + CONFIDENCE) / 2 > 85`, with sufficient source-quality evidence. After this page is raised to `86/89` and routed through [UID:0000CK], first-draft formal C++ is eligible while retaining the raw no-function/no-route caveat.
```

### Primary Target C++ Block

Placement: `RECONSTRUCTION_CPP CODE` block in the target page.

```cpp
void ScrollInventoryPane::ResetScrollState()
{
    RectBounds rect;
    char oldPart;

    RemovePendingTimers();

    oldPart = m_highlightPart;
    m_activePart = -1;

    if (oldPart != -1) {
        GetPartRect(oldPart, &rect);
        InvalidateRect(&rect);
        m_highlightPart = -1;
    }
}
```

### ScrollInventoryPane Layout Support Text

Placement: in [UID:0001W0] `by-type/by-struct/ScrollInventoryPaneLayout.md`, replace or append to the rows for `+0xa4`, `+0x103`, and `+0x104`.

```markdown
| `+0xa4` | tertiary `TimerHandler` / update-handler subobject view | Constructor installs the tertiary vtable at `+0xa4`; interaction helpers pass `ecx=this+0xa4` to generic `TimerHandler` wrappers. `ResetScrollState` calls `TimerHandler::RemovePendingTimers()` at `0x00597600` through this view. Do not model this as an unrelated widget-local scalar field. |
| `+0x103` | `char m_highlightPart` | Highlighted/hovered scrollbar part, with `0xff` / `-1` as no-part sentinel. `SetHighlightRegion` writes it; `ResetScrollState` reads the old value, invalidates that part rectangle when valid, and clears it. |
| `+0x104` | `char m_activePart` | Active/pressed/tracking scrollbar part, with `0xff` / `-1` as no-part sentinel. Begin/active-state helpers write it, `UpdateFromDrag` and timer paths consume it, and `ResetScrollState` clears it unconditionally. |
```

### ScrollInventoryPane Class Support Text

Placement: in [UID:0000CK] `by-class/ScrollInventoryPane.md`, replace the C++ emission note or add after `## Autogen Status`.

```markdown
2026-06-18 B003 source-quality update resolves [UID:0001H1][0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw](by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md) as an exact source-bearing class method `ScrollInventoryPane::ResetScrollState()`. The raw helper still has no IDA function object, no direct raw-start caller, no VA/RVA pointer route, and no external direct branch into the range, so IDA function creation remains unsafe. That caveat no longer blocks first-draft C++ under the active combined-score/emitter gate once the child is raised to `86/89` and routed through this class. The method uses `m_highlightPart` at `+0x103`, `m_activePart` at `+0x104`, the `+0xa4` TimerHandler view, `GetPartRect`, and Pane invalidation.
```

### InventoryScrollPane File Support Text

Placement: in [UID:0000KB] `by-file/InventoryScrollPane.md`, append to the `2026-06-14 C001 IDA MCP Refresh` or source split section.

```markdown
2026-06-18 B003 target reanalysis reroutes [UID:0001H1][0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw](by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md) from direct file ownership to direct class ownership [UID:0000CK][ScrollInventoryPane]. This file remains the current generated source route for that class. The final standalone-versus-folded decision with [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md) is still open, but it does not change the child method's direct class ownership.
```

### Aggregate [UID:0001GZ] Support Text

Placement: in [UID:0001GZ] `by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md`, append under the current live recheck/source-quality notes.

```markdown
- 2026-06-18 B003 local PE route scan confirms the raw reset child [UID:0001H1][0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw](by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md) still has no direct branch/call target, no absolute-VA or RVA pointer route to `0x005646b0`, and no external direct branch/call into `0x005646b0-0x0056470c`; only the helper's own conditional branch targets inside the range. The reset child should route through direct class owner [UID:0000CK][ScrollInventoryPane], not direct file owner [UID:0000KB], and may now carry first-draft `ResetScrollState` C++ after its score update.
```

### Active Gate Wording Replacement

Placement: replace any `95/95` or `95+` final-C++-bar sentence in the target and directly edited support pages for this specific helper.

```markdown
Formal C++ follows the active by-structure gate: `RECONSTRUCTABLE:TRUE`, a nonblank emitter route that surfaces to a generated source file, and `(COMPLETION + CONFIDENCE) / 2 > 85`, with names, boundaries, dependencies, source placement, and helper roles documented well enough for source-quality output. `95+` remains a rare final-audit score, not the routine threshold for first-draft source entry.
```

## Coverage Report Replacement Text

Placement: `by-memory/-coverage-report.md`, around the ScrollInventoryPane block before [UID:0001H2] `ScrollVolumePane`.

Replace the existing [UID:0001GZ], [UID:0001H0], and [UID:0001H1] rows with:

```markdown
    - [UID:0001GZ][0x00563260-0x0056470c.ScrollInventoryPane](by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md) 0x00563260-0x0056470c | class aggregate | ScrollInventoryPane : reconstructable : 85% : strong : Attached to [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md); IDA-backed docs and B003 PE recheck confirm the NewInventoryPane-only constructor caller, modeled function inventory, raw setter/predicate/highlight/drag/reset helper spans, internal padding, dispatcher-to-UpdateFromDrag relationship, layout/vtable field evidence, class/file gate through [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md), and no direct branch or VA/RVA pointer route to the reset raw start.
    - [UID:0001H0][0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag](by-memory/0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag.md) 0x00564520-0x005646ad | method | ScrollInventoryPaneUpdateFromDrag : reconstructable : 85% : strong : Exact update helper attached to [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md), with current decompile, two callers at `0x005644bb` and `0x005644e4` inside the `0x00564460` dispatcher, orientation-specific pointer/track/thumb math, old/new `+0xfe` position comparison, `+0xfc/+0x100/+0x108/+0x10c` field use, owner callback `0x004eba00`, adjacent raw-reset boundary, and class/file gate through [UID:0000KB][InventoryScrollPane](by-file/InventoryScrollPane.md).
    - [UID:0001H1][0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw](by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md) 0x005646b0-0x0056470c | raw method-shaped helper | ScrollInventoryPaneResetScrollStateRaw : reconstructable : 86% : strong : B003 source-quality pass reroutes the exact raw reset helper to direct class owner/emitter [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md), confirms source-facing `ScrollInventoryPane::ResetScrollState()`, `+0xa4` TimerHandler pending-timer removal through `0x00597600`, `+0x104 = m_activePart` clear, conditional old-highlight invalidation and `+0x103 = m_highlightPart` clear through `GetPartRect`/Pane invalidation, exact padding before ScrollVolumePane at `0x00564710`, zero VA/RVA literals and zero external direct branch/call targets to the raw start/range, rejected unaligned instruction-byte pointer artifacts, and first-draft C++ readiness after the score and owner/emitter update.
```

Do not change [UID:0001GO] from this report unless the supervisor intentionally broadens scope to a sibling parity cleanup. The sibling likely needs a similar class-owner/active-gate review, but it is not the primary target.

## Remaining Blockers

- Fresh live IDA MCP was unavailable. Existing live-IDA-backed docs plus local PE scans are enough for `86/89`, but not for final-audit scoring.
- No direct caller, vtable slot, pointer table, or external branch route to `0x005646b0` is proven. This remains an IDA/reachability caveat and should block IDA function creation, but not first-draft C++ after the accepted score/owner update.
- The final file split remains open between standalone [UID:0000KB][InventoryScrollPane] and possible fold into [UID:0000LS][NewInventoryPane]. This does not affect direct class ownership. It only affects final physical `.cpp` organization.
- Exact original helper spelling is not proven by symbols. `ResetScrollState` is a high-probability descriptive/source-facing name based on current target naming, fitting-room/inventory sibling terminology, and body semantics.
- [UID:0001GO] has the same stale raw-helper/c++-gate issue pattern, but changing it should be a separate sibling task or explicit supervisor broadening.

## Validation Commands For Supervisor

After applying the doc and coverage changes:

> Executable block R001 was removed from this report and preserved verbatim in [0001H1-ScrollInventoryPaneResetScrollStateRaw-source-quality-removed.md](0001H1-ScrollInventoryPaneResetScrollStateRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Targeted text checks:

> Executable block R002 was removed from this report and preserved verbatim in [0001H1-ScrollInventoryPaneResetScrollStateRaw-source-quality-removed.md](0001H1-ScrollInventoryPaneResetScrollStateRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Changed Files

Created exactly one report:

- `tools/leaser/Agents/Agent-B003/research/0001H1-ScrollInventoryPaneResetScrollStateRaw-source-quality.md`

Agent-B003 did not edit by-* docs, generated reports, generated source, the IDA DB, or `by-memory/-coverage-report.md`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0001H1-ScrollInventoryPaneResetScrollStateRaw-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"0001H1"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001H1-ScrollInventoryPaneResetScrollStateRaw-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0001H1-ScrollInventoryPaneResetScrollStateRaw-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001H1"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
