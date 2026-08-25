** TARGET-REPORT-UID:0002TX **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002TX AttachmentAnchor Image Bounds Metric Raw Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0002TX] `by-memory/0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw.md` attached to [UID:00000O] `AttachmentAnchorResolver`, routed through [UID:0000HL] `NexusTK/map/AttachmentAnchorResolver.cpp`.
- Best source-quality role name: "AttachmentAnchorResolver raw light-info brightness metric helper". The exact returned member is now best-inferred as `LightInfo::brightness`, not a vague bounds metric.
- Final C++ policy: do not hand-author a real C++ method body for this UID. The range has no IDA function object, no incoming xrefs, no raw dword pointer hits, and no proven source-level API. It is eligible only for a comment-only formal marker if the supervisor wants routed no-entry raw helpers to stop appearing as empty emitters.
- Target score recommendation after implementation: `86/90`, provided the target doc records `g_pLightObjImageLib`, `m_lightImageIndex`, `LightInfo::brightness`, the exact no-code proof, and the current owner/source placement decision. Keep `85/87` if only the current text is retained.
- Coverage-report state: the target header is already `85/87`, but the supervisor-owned `by-memory/-coverage-report.md` row is stale at `82% : strong`. Do not edit that file from a B-agent report; use the exact replacement row below if accepted.

## Supporting Research

## Target

- Target UID: `0002TX`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw.md`
- Source queue/report row: `B011-goal2-attachment-anchor-image-bounds-metric-raw-source-quality-0002TX-20260619`
- Current header state: `COMPLETION:85`, `CONFIDENCE:87`, `CANONICAL_OWNER:00000O`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000O`, blank `RECONSTRUCTION_CPP CODE`.
- Current entity kind: raw helper island, not an IDA function object.
- Current direct owner: [UID:00000O] `AttachmentAnchorResolver`.
- Current emitted source route: [UID:00000O] class -> [UID:0000HL] `AttachmentAnchorResolver`, generated at `auto-generated/NexusTK/map/AttachmentAnchorResolver.cpp`.
- Fresh local checks in this B011 pass:
  - local IDA MCP endpoint `http://127.0.0.1:13337/mcp` was unavailable, so this report does not claim new live IDA observations;
  - scoped validator dry run for the target doc completed with target `0002TX` recognized as `ok`;
  - fresh PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` found zero direct `rel32` calls and zero dword pointer hits to `0x0053c6b0`, with `0xcc` padding before and after the raw body.

## Executive Recommendation

Use this source-quality model:

- Keep the half-open raw range `0x0053c6b0-0x0053c6f7` as its own by-memory child. It is a complete function-shaped body with prologue, body, `fld`, and `ret`, but IDA still does not model it as a function.
- Keep the direct semantic owner as [UID:00000O] `AttachmentAnchorResolver`. The body reads the resolver-local index at `this+0x128`, uses the same `g_pLightObjImageLib` table and index shape as `ComputeScreenBounds` and the light-apply helpers, and is padding-separated from the preceding `LightingObjectPane` lifecycle range.
- Use [UID:0000HL] `AttachmentAnchorResolver.cpp` as the current reconstruction route. The higher-probability original source file may eventually be a private helper inside `AttachedObjectPane.cpp`, but that is a family-level source-root question and should not move UID `0002TX` alone.
- Replace the decompiler-style dependency names in the target text:
  - `dword_69B450` -> `g_pLightObjImageLib` with raw alias retained;
  - `this+0x128` / `this[74]` -> `m_lightImageIndex` or `lightInfoIndex`; prefer `m_lightImageIndex` for consistency with neighboring resolver docs;
  - returned anonymous float -> `LightInfo::brightness` at row offset `+0x10`.
- Do not emit a real method such as `float AttachmentAnchorResolver::GetLightBrightness() const`. That would invent a callable source API that no caller, vtable, callback slot, or pointer table currently proves.
- If implementation wants a nonblank reconstruction block for source-tracker hygiene, make it comment-only and explicit that the raw range is no-entry/no-code.

## Supervisor Active Recheck

- The current user instruction supersedes the stale Agent-B011 notes assignment. This report addresses only UID `0002TX`.
- The assignment is report-only. No by-* docs, coverage reports, auto-generated files, project-level files, or B011 notes were edited.
- The target is not a destructor, not a deleting wrapper, and not a compiler thunk. Its source-quality problem is a raw no-entry helper policy issue.
- The required section `## Heuristic / Inference Reanalysis And Validation` is present below.
- The report resolves or best-infers raw helper role, fields/types/globals/placeholders, caller/reachability, owner/source placement, split/range decisions, open questions, C++ readiness, exact coverage-row text, and implementation checklist.

## Inference Research Guidance Check

- The target meets the metadata routing gate for source discussion: `RECONSTRUCTABLE:TRUE`, owner/emitter route present, and `(85 + 87) / 2 = 86`.
- That gate does not make real C++ safe. Current evidence proves bytes and semantic dependency, not a source-level callable method.
- The stronger source-quality outcome is to document the raw helper precisely and keep the C++ body absent or comment-only. This avoids converting compiler/linker dead code, no-entry helpers, or abandoned source into a fake public/private method.
- Consumer evidence was separated from ownership evidence. `g_pLightObjImageLib` is the consumed data/service dependency; it does not own the helper. Address adjacency to `LightingObjectPane` is also not ownership because there is padding and no lifecycle-field behavior in this body.

## Heuristic / Inference Reanalysis And Validation

### Issue 1: Raw helper role and best-supported name

- Current title/name: `AttachmentAnchorImageBoundsMetricRaw`.
- Best documentation role: `AttachmentAnchorResolver` raw light-info brightness metric helper.
- Best compact role label: `AttachmentAnchorLightInfoBrightnessMetricRaw`.
- Evidence: the selected row is a `LightInfo` row from `g_pLightObjImageLib`; the helper returns row offset `+0x10`, which [UID:0001UX] `LightObjImageLibLayout` identifies as `brightness`.
- Rejected role names:
  - `ImageBoundsMetricRaw` is historically understandable, but imprecise after the `LightInfo` layout evidence because the returned value is not a bounds radius.
  - `GetLightBounds` is wrong for this UID; the modeled neighbor `0x0053c810` calls the actual `LightObjImageLib::GetLightBounds`-style helper and writes a rectangle.
  - `ApplyLight` is wrong for this UID; `0x0053c9c0` and raw twin `0x0053c9f0` own the light-apply slot calls.
- Final direction: update target prose to identify the returned metric as `LightInfo::brightness`. A file/title rename is optional and should be done only as a supervisor-controlled link update; the minimal safe implementation can keep the current path and title while making the role precise in text.

### Issue 2: Field, type, global, and placeholder names

| Raw expression | Best-supported source-quality name | Evidence and constraints |
| --- | --- | --- |
| `dword_69B450` | `g_pLightObjImageLib` | [UID:0001PR] resolves the global at `0x0069b450` as `LightObjImageLib*`; target has data ref `0x0053c6bc -> 0x0069b450`. |
| `[ecx+0x128]` / `this+0x128` | `m_lightImageIndex` | [UID:00000O] records the resolver index field at `+0x128`; sibling resolver and light-apply helpers use the same offset as the light/image table index. |
| `[edx+0x08]` | `g_pLightObjImageLib->lightInfoCount` | [UID:0001UX] places the count at `LightObjImageLib + 0x08`. |
| `[edx+0x0c]` | `g_pLightObjImageLib->lightInfoEntries` | [UID:0001UX] places the entries pointer at `LightObjImageLib + 0x0c`. |
| `edx+0x14` fallback | `g_pLightObjImageLib->fallbackLightInfo` | [UID:0001UX] places the fallback `LightInfo` row at `LightObjImageLib + 0x14`. |
| `index * 0x1c` | `sizeof(LightInfo)` | [UID:0001UX] documents `LightInfo` stride `0x1c`. |
| copied row offset `+0x10` | `LightInfo::brightness` | Local copy starts at `[ebp-0x1c]`; `fld [ebp-0x0c]` reads local offset `+0x10`. |
| `sub_53C6B0` / raw start | no stable source method name | The range has no IDA function record, no callers, and no pointer route. Keep a descriptive raw label, not a generated source method. |

Support fields outside this target remain useful context but are not used by UID `0002TX`: resolver offsets `+0x12c`, `+0x130`, and `+0x134` are the local offset/anchor-source state used by modeled resolver methods, not this brightness helper.

### Issue 3: Returned metric validation

The row-copy and return logic resolves the metric:

```text
0x00..+0x0f copied by movups from [entry]
+0x10..+0x17 copied by movq from [entry+0x10]
local copy begins at [ebp-0x1c]
fld [ebp-0x0c] == local copy + 0x10 == entry + 0x10
LightInfo + 0x10 == brightness
```

This is stronger than the current "floating-point member" wording. The helper returns the selected or fallback `LightInfo::brightness` value. It does not read `radiusX`, `radiusY`, `blendScale`, or `generatedFrame`.

### Issue 4: Caller and reachability

- Documented live IDA facts in the target page: no function object at `0x0053c6b0`, no `CodeRefsTo`, no `DataRefsTo`, and no loaded-segment dword pointer hits to the raw start.
- Related B015 source-quality PE scan: zero direct `rel32` calls and zero pointer hits for raw start `0x0053c6b0`.
- Fresh B011 local PE scan: zero direct `rel32` call hits and zero dword pointer hits to `0x0053c6b0`; the same scan found fifteen `0xcc` bytes before the body and nine `0xcc` bytes after the body.
- Modeled-neighbor reachability does not transfer to this raw helper. `0x0053c700`, `0x0053c810`, and `0x0053c9c0` have callers; UID `0002TX` does not.
- Final direction: document as a raw no-entry child. Do not create a real source method until one of these appears: direct caller, vtable/callback slot, dispatch table pointer, or original-source evidence tying the body to a named helper.

### Issue 5: Owner and source placement

Ranked ownership:

1. [UID:00000O] `AttachmentAnchorResolver` - accepted direct owner. The helper uses the resolver-local light/image index and the same global light-info dependency as the modeled resolver and light-apply siblings.
2. [UID:0000HL] `AttachmentAnchorResolver` by-file root - accepted current source route. It already groups `0x0053c700`, `0x0053c810`, `0x0053c9c0`, and the raw siblings.
3. [UID:0000HJ] `AttachedObjectPane` source root - plausible original compilation-unit umbrella, but not a target-level move. If this family folds into `AttachedObjectPane.cpp`, move the resolver family together.
4. [UID:0000KP] `LightObjImageLib` / [UID:0001PR] `g_pLightObjImageLib` - rejected as owner. The helper consumes the global table but the receiver is resolver state in `ecx`, and sibling resolver methods own the placement behavior.
5. [UID:0000KO] `LightingObjectPane` / [UID:0001DG] lifecycle range - rejected. There is `0xcc` separation, no LightingObjectPane lifecycle behavior, and the field/table pattern matches attachment anchors.
6. Owner NONE or standalone utility - rejected for current docs because the resolver family attachment clears the ownership gate and gives useful source placement.

### Issue 6: Compiler-generated wrapper status

- This target is not a compiler-generated scalar deleting destructor, adjustor thunk, EH helper, or vtable glue.
- It is a raw function-shaped helper island that the current IDB does not promote to a function.
- The correct policy is therefore not "compiler wrapper source emitted by declaring a destructor"; it is "raw no-entry helper, no real C++ body until reachability is proven".
- A comment-only reconstruction marker is acceptable if the supervisor wants the routed emitter to explicitly encode the no-code decision.

### Issue 7: Split/range decision

- Keep exact range: `0x0053c6b0-0x0053c6f7`.
- Start reason: the first byte is a normal prologue `55 8b ec`, and there are fifteen bytes of `0xcc` padding after `0x0053c6a1`.
- End reason: `0x0053c6f6` is `ret`; `0x0053c6f7-0x0053c700` is nine bytes of `0xcc` padding before modeled `0x0053c700`.
- Do not merge backward into [UID:0001DG] `LightingObjectPaneLifecycle`.
- Do not merge forward into [UID:0001DH] `AttachmentAnchorResolver`; UID `0001DH` starts at a modeled function boundary and owns the two reachable resolver methods.
- Do not sub-split inside `0x0053c6b0-0x0053c6f7`; the branch, row selection, local copy, and `fld` return are one helper body.

### Issue 8: Open questions and closure

- Closed: global `dword_69B450` is `g_pLightObjImageLib`.
- Closed: selected row type is `LightInfo`.
- Closed: returned field is `LightInfo::brightness`.
- Closed: owner remains `AttachmentAnchorResolver` for current docs.
- Closed: range is exact and should stay separate from neighbors.
- Closed for implementation policy: no real C++ body is currently justified.
- Still open but non-blocking: original source method name is unknown; original compilation unit might be broader `AttachedObjectPane.cpp`; reachability remains unproven.
- Practical closure: these open items are the reason for comment-only/no-code, not a reason to leave target evidence shallow.

## Evidence Standards Used

- Direct target evidence: raw disassembly, exact half-open range, prior live IDA MCP notes, no function object, no incoming refs, no pointer hits, data ref to `0x0069b450`, and padding on both sides.
- Related by-* evidence:
  - [UID:00000O] `AttachmentAnchorResolver` class layout and method family;
  - [UID:0000HL] `AttachmentAnchorResolver` source route and raw sibling inventory;
  - [UID:0001DH] modeled `ResolveAnchorPoint` and `ComputeScreenBounds`;
  - [UID:0001PR] `g_pLightObjImageLib`;
  - [UID:0001UX] `LightObjImageLibLayout` / `LightInfo` row layout;
  - [UID:0002TZ] modeled `AttachmentAnchorApplyLight`;
  - [UID:0002U0] raw light-apply twin;
  - [UID:0000HJ] `AttachedObjectPane` source-root caveat for possible family folding.
- Generated evidence: `auto-generated/NexusTK/map/AttachmentAnchorResolver.cpp` currently contains only empty markers for the resolver class and children, including UID `0002TX`.
- Fresh local evidence: PE byte scan confirms no direct calls or pointer hits to `0x0053c6b0` and confirms `0xcc` padding boundaries.
- Negative evidence: no caller, no vtable slot, no callback table, no pointer table, no source-level method name, and no reason to move the helper to `LightObjImageLib` or `LightingObjectPane`.

## IDA MCP And Local Validation Facts

Fresh live IDA MCP was unavailable in this B011 pass:

```text
IDA_MCP_UNAVAILABLE: Unable to connect to the remote server
```

Documented prior IDA facts from current by-* pages:

- no IDA function object at `0x0053c6b0`;
- previous function `0x0053c640-0x0053c6a1`, next modeled function `0x0053c700-0x0053c802`;
- zero xrefs to `0x0053c6b0`;
- zero raw pointer hits to `0x0053c6b0`;
- data reference `0x0053c6bc -> 0x0069b450`;
- raw body through `0x0053c6f6`;
- fifteen bytes of `0xcc` before the body and nine bytes before the modeled resolver.

Fresh B011 PE scan facts:

```text
imageBase=0x00400000
target=0x0053c6b0
rel32_call_hits=none
dword_pointer_hits=none
pre15=cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc
body_first_last=55 8b ec 8b 81 28 01 00 ... f4 d9 45 f4 8b e5 5d c3
post9=cc cc cc cc cc cc cc cc cc
```

Scoped validator dry run:

_Executable command block removed from the research report; preserved in [0002TX-AttachmentAnchorImageBoundsMetricRaw-source-quality-removed.md](0002TX-AttachmentAnchorImageBoundsMetricRaw-source-quality-removed.md)._

Result summary: target `0002TX` was recognized as `ok`; dry run only, no files written.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0053c5e0-0x0053c6a1` | [UID:0001DG] `LightingObjectPaneLifecycle` | preceding lighting object lifecycle range | TRUE | lighting object family | not re-evaluated here | boundary predecessor only |
| `0x0053c6a1-0x0053c6b0` | [UID:0000VN] coverage padding row | alignment bytes | ignored | none | `100% : strong` coverage row | confirms separation from lifecycle range |
| `0x0053c6b0-0x0053c6f7` | [UID:0002TX] target | raw no-entry light-info brightness metric helper | TRUE | [UID:00000O] | current `85/87`, recommended `86/90` | no real C++ body |
| `0x0053c6f7-0x0053c700` | implicit padding before modeled resolver | alignment bytes | ignored | none | documented in target | confirms separation from modeled resolver |
| `0x0053c700-0x0053c802` | part of [UID:0001DH] | modeled `ResolveAnchorPoint` | TRUE | [UID:00000O] | `85/87` page | reachable modeled method |
| `0x0053c810-0x0053c92e` | part of [UID:0001DH] | modeled `ComputeScreenBounds` | TRUE | [UID:00000O] | `85/87` page | reachable modeled method, calls light bounds helper |
| `0x0053c930-0x0053c97b` | [UID:0002TY] | raw screen-bounds notify helper | TRUE | [UID:00000O] | `85/87` | no-entry raw sibling |
| `0x0053c9c0-0x0053c9eb` | [UID:0002TZ] | modeled attachment light apply helper | TRUE | [UID:00000O] | `85/87` | caller-backed sibling |
| `0x0053c9f0-0x0053ca1b` | [UID:0002U0] | raw light-apply twin | TRUE | [UID:00000O] | `85/87` | no-entry raw sibling |

## Direct Xref / Caller Inventory

| Address / Item | Evidence | Meaning |
| --- | --- | --- |
| `0x0053c6b0` | no IDA function object; zero code refs; zero data refs; zero pointer hits; fresh PE scan zero direct calls/pointers | no source-level caller is proven for UID `0002TX`. |
| `0x0053c6bc` | data ref to `0x0069b450` | consumes `g_pLightObjImageLib`. |
| `0x0053c810` | modeled neighbor uses same global/index shape and calls light-bounds helper | supports resolver-family ownership but not target reachability. |
| `0x0053c9c0` | two known code refs and same `this+0x128`/light-table argument family | supports the meaning of `+0x128` as light/image index. |
| `0x0053c930` and `0x0053c9f0` | raw siblings with no entry refs | reinforces the local pattern: several no-entry raw islands belong as resolver children but do not get real C++ bodies. |

## Documentation Evidence And Current Gaps

Existing target strengths:

- exact raw range and raw disassembly are already present;
- prior live IDA evidence records no function/xrefs/pointers;
- owner and emitter route are already attached to `AttachmentAnchorResolver`;
- target already notes fallback row logic and same table/index shape as modeled resolver neighbors.

Existing target gaps:

- target still uses `dword_69B450` instead of resolved `g_pLightObjImageLib` in most prose;
- target still uses `this+0x128` instead of a source-quality resolver field name;
- target describes the return as a generic floating-point member rather than `LightInfo::brightness`;
- target says final source name remains open, but does not close the C++ policy with exact no-code proof;
- target does not mention the current coverage-report row discrepancy.

Generated/source gap:

- `auto-generated/NexusTK/map/AttachmentAnchorResolver.cpp` contains only empty markers for UID `0002TX`. This is correct if the page stays blank, but it leaves the route visibly uncoded. A comment-only marker is the best optional source-quality closure.

## Ranked Ownership Analysis

### 1. [UID:00000O] AttachmentAnchorResolver

- Evidence for: `this+0x128` is resolver-local state; modeled resolver methods and light-apply siblings use the same light/image index; `ComputeScreenBounds` consumes the light image library for bounds; `ApplyLight` consumes the same index for light placement.
- Evidence against: no caller proves a source-level method on the class.
- Decision: accepted as direct owner; lack of caller affects C++ policy, not ownership.

### 2. [UID:0000HL] AttachmentAnchorResolver file root

- Evidence for: current generated route, file page contents table, modeled resolver siblings, raw sibling policy, and `NexusTK/map/` placement.
- Evidence against: file page itself notes possible folding into `AttachedObjectPane.cpp`.
- Decision: accepted as current source route. Do not move only UID `0002TX`.

### 3. [UID:0000HJ] AttachedObjectPane file root

- Evidence for: attached overlay family likely includes anchor resolver behavior in original source; `AttachedObjectPane.md` explicitly notes `AttachmentAnchorResolver` may fold into this source.
- Evidence against: current project docs keep a separate resolver class/file page with valid route; target-level source-quality should not cause a partial family move.
- Decision: family-level future question only.

### 4. LightObjImageLib / g_pLightObjImageLib

- Evidence for: target reads the global light-info table and returns a `LightInfo` field.
- Evidence against: the receiver register is resolver `this`; no member field of `LightObjImageLib` is being invoked as a method; target is an adapter around resolver state plus global table.
- Decision: rejected as owner; keep as dependency/type support.

### 5. LightingObjectPane

- Evidence for: physical predecessor range is `LightingObjectPaneLifecycle`, and the global dependency is a light object image library.
- Evidence against: target has padding separation, no LightingObjectPane object fields, and no lifecycle/set-intensity behavior. The `+0x128` index matches the attachment resolver family.
- Decision: rejected.

## C++ Readiness And Exact No-Code Proof

### Real first-draft C++ eligibility

Not eligible.

Reasoning:

- no IDA function object exists at `0x0053c6b0`;
- no direct code refs exist to `0x0053c6b0`;
- no data refs or raw dword pointer refs exist to `0x0053c6b0`;
- fresh PE scan found no `rel32` call to the raw start;
- no vtable, callback, or dispatch table entry is known;
- no original source method name is known;
- neighboring reachable methods already own the source-level resolver behavior that is caller-backed.

The conceptual semantics are clear:

```text
selected = valid(m_lightImageIndex)
         ? g_pLightObjImageLib->lightInfoEntries[m_lightImageIndex]
         : g_pLightObjImageLib->fallbackLightInfo;
return selected.brightness;
```

That is not enough to emit a real source method.

### If a comment-only formal C++ marker is accepted

Use a comment-only reconstruction block, not a callable function:

```cpp
// Raw no-entry AttachmentAnchorResolver light-info brightness metric helper.
// It selects g_pLightObjImageLib LightInfo by m_lightImageIndex and returns brightness,
// but no caller, vtable slot, callback, or pointer route proves a source-level method.
```

Do not emit this as real code:

```cpp
float AttachmentAnchorResolver::GetLightBrightness() const;
```

That declaration would invent source API surface that is not currently supported.

## Open Questions

- Original symbol/method name: unresolved and likely unrecoverable without caller/source evidence.
- Original source file: current route is `AttachmentAnchorResolver.cpp`; possible future family fold into `AttachedObjectPane.cpp` should be handled as a separate source-root pass.
- Reachability: still unproven. This is the hard blocker for real C++.
- Title/path precision: a rename to `AttachmentAnchorLightInfoBrightnessMetricRaw` would be more semantically precise, but the minimal implementation can avoid path churn and update only text.

These open questions do not block a source-quality target update because the no-code policy is now the resolved answer.

## Exact Supervisor-Owned Coverage Row Text

Current exact row in `by-memory/-coverage-report.md`:

```markdown
    - [UID:0002TX][0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw](by-memory/0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw.md) 0x0053c6b0-0x0053c6f7 | raw helper method | AttachmentAnchorImageBoundsMetricRaw : reconstructable : 82% : strong : Attached under `AttachmentAnchorResolver`; live raw disassembly confirms a complete table/index metric helper with `dword_69B450`, `this+0x128`, fallback table entry logic, no incoming refs/pointer hits, modeled-neighbor corroboration, boundary separation, and blank final C++ while reachability/name remain open.
```

Recommended replacement row if the supervisor accepts the target implementation and `86/90` score:

```markdown
    - [UID:0002TX][0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw](by-memory/0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw.md) 0x0053c6b0-0x0053c6f7 | raw helper method | AttachmentAnchorImageBoundsMetricRaw : reconstructable : 86% : very-strong : Attached under `AttachmentAnchorResolver`; raw disassembly and PE scan confirm a complete no-entry light-info brightness metric helper that reads `m_lightImageIndex` (`this+0x128`), selects a `g_pLightObjImageLib` (`dword_69B450`) entry or fallback `LightInfo`, returns `LightInfo::brightness`, has no function object, incoming refs, direct calls, or pointer hits, and should remain blank/comment-only until reachability is proven.
```

If the supervisor chooses not to raise confidence to `90`, the same replacement text can be used with `85% : strong` after syncing the stale row to the current target header.

## Target / Support Implementation Checklist

Target [UID:0002TX] `by-memory/0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw.md`:

- [ ] Keep `CANONICAL_OWNER:00000O`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00000O`.
- [ ] Keep exact half-open range `0x0053c6b0-0x0053c6f7`.
- [ ] Update behavior text from generic image/bounds metric to raw light-info brightness metric.
- [ ] Replace prose references to `dword_69B450` with `g_pLightObjImageLib` while preserving `dword_69B450` as raw/IDA alias.
- [ ] Replace prose references to `this+0x128` / `this[74]` with `m_lightImageIndex` or `m_lightImageIndex` plus raw offset alias.
- [ ] Add the row-layout proof that `fld [ebp-0x0c]` returns selected `LightInfo + 0x10`, i.e. `LightInfo::brightness`.
- [ ] Add the exact no-code proof: no function object, no xrefs, no pointers, no direct PE calls, no vtable/callback route.
- [ ] Add C++ readiness wording: not eligible for real first-draft C++; optional comment-only marker only.
- [ ] Optional if accepted: add the comment-only `RECONSTRUCTION_CPP CODE` block shown above.
- [ ] Recommended score after the above content: `COMPLETION:86`, `CONFIDENCE:90`.

Support [UID:00000O] `by-class/AttachmentAnchorResolver.md`:

- [ ] Add or refine a child note for UID `0002TX`: raw no-entry helper selects `g_pLightObjImageLib` `LightInfo` by `m_lightImageIndex` and returns `brightness`.
- [ ] Keep the field map at `+0x128` source-quality named as `m_lightImageIndex` or explicitly list that alias next to existing `imageIndex`.
- [ ] Do not add a real class method declaration for UID `0002TX` unless reachability is later proven.

Support [UID:0000HL] `by-file/AttachmentAnchorResolver.md`:

- [ ] Update contents table role for UID `0002TX` from generic image/bounds metric to raw light-info brightness metric.
- [ ] Preserve the source-route caveat: current separate `AttachmentAnchorResolver.cpp` route is valid, while possible `AttachedObjectPane.cpp` folding remains a family-level question.
- [ ] Do not move UID `0002TX` alone to `AttachedObjectPane.cpp`.

Support [UID:0001PR] `g_pLightObjImageLib` and [UID:0001UX] `LightObjImageLibLayout`:

- [ ] No required structural edits if those pages already retain `g_pLightObjImageLib` and `LightInfo::brightness`.
- [ ] Optional cross-reference: ensure UID `0002TX` is listed as a read/consumer of `LightInfo::brightness` if support pages maintain read-site inventories.

Supervisor-owned coverage:

- [ ] Do not edit `by-memory/-coverage-report.md` from a B-agent run.
- [ ] If accepted, apply the exact replacement row above or regenerate coverage after target/support docs are updated.

Validation after implementation:

- [ ] Run `python tools\validator.py --queue-timeout 120 --mode file --file by-memory\0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw.md`.
- [ ] If support docs are changed, validate those files too.
- [ ] Rebuild generated reports only through the approved supervisor/validator flow.

## Final Decision

UID `0002TX` is source-quality reconstructable as a documented raw child, not as a handwritten C++ function. The best-supported semantic is an `AttachmentAnchorResolver` no-entry helper that returns `g_pLightObjImageLib` `LightInfo::brightness` for the resolver's `m_lightImageIndex`, with fallback-row behavior for invalid indices. Ownership, range, and dependency names are now strong enough for a target doc update and optional comment-only marker, while the lack of reachability remains a hard blocker for real first-draft C++.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/0002TX-AttachmentAnchorImageBoundsMetricRaw-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"0002TX"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002TX-AttachmentAnchorImageBoundsMetricRaw-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/0002TX-AttachmentAnchorImageBoundsMetricRaw-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002TX"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
