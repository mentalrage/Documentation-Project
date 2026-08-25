** TARGET-REPORT-UID:00023H **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00023H LivingObjectPaneGetEntityId Source-Quality Reanalysis

Assignment: `B003-goal2-livingobjectpane-entity-state-accessor-source-quality-00023H-20260618`

Target: [UID:00023H] `by-memory/0x00538bb0-0x00538bb7.LivingObjectPaneGetEntityId.md`

Current target state: `COMPLETION:82`, `CONFIDENCE:90`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000KU`, `EMITTER_UIDS:0000KU`, blank formal C++.

Recommendation summary: the target should remain an exact seven-byte reconstructable accessor, but the current `LivingObjectPaneGetEntityId` owner/name is stale. All checked write-side and caller evidence identifies the receiver as an `EffectObjectPane`, not a `LivingObjectPane`. Recommend retitling/renaming this page to `0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md`, changing owner/emitter to [UID:000049] `EffectObjectPane`, raising the score to `88/92`, and populating first-draft C++ as `bool EffectObjectPane::IsLooping() const`.

## Evidence Checked

- Read active workflow/rules: `tools/leaser/Agents/Supervisor.md`, `tools/leaser/Agents/Agent-B003/goal.md`, `tools/leaser/Agents/Agent-B003/notes.md`, `by-structure.md`, and `inference_research.md`.
- Read target [UID:00023H] and support pages:
  - [UID:00007B] `by-class/LivingObjectPane.md`
  - [UID:0000KU] `by-file/LivingObjectPane.md`
  - [UID:0001DE] `0x0053a110-0x0053d818.LivingObjectPaneCore.md`
  - [UID:0002R0] `0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup.md`
  - [UID:000232] `0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md`
  - [UID:0003TE] `0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md`
  - [UID:0003TF] `0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md`
  - [UID:0003TG] `0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md`
  - [UID:0001KM] `0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`
  - [UID:0003U6] `0x005a2e00-0x005a36de.LivingObjectPaneProcessMovement.md`
  - [UID:0001D9] `0x005387b0-0x00538baa.EffectObjectPaneCore.md`
  - [UID:000049] `by-class/EffectObjectPane.md`
  - [UID:000351] `0x006205f8-0x006206ac.EffectObjectPaneVtableData.md`
  - [UID:0001DA] `0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md`
  - [UID:0002HA] `0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo.md`
  - [UID:0001U8] `by-type/by-struct/EffectInfo.md`
  - [UID:0001U7] `by-type/by-struct/EffectFrameRecord.md`
  - [UID:0001OR]/[UID:0000QK] `g_pCollectionData` storage/global docs.
- Searched B-agent executed reports for `00023H`, `0x00538bb0`, `LivingObjectPaneGetEntityId`, `EffectObjectPane`, and `+0x14c`. Prior B001 `0001DE-LivingObjectPaneCore` only preserved the target as a future field-name task; it did not perform the receiver/write-side correction below.
- Tried IDA MCP at `http://127.0.0.1:13337/mcp`. It failed with `IDA_MCP_UNAVAILABLE: Unable to connect to the remote server`. I continued with the read-only executable and existing IDA-backed docs.
- Used `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` with Capstone:
  - Parsed PE sections and image base `0x400000`.
  - Disassembled `0x00538baa-0x00538bc0`.
  - Scanned `.text` rel32 calls/jumps to `0x00538bb0`.
  - Scanned all sections for dword pointer values `0x00538bb0`.
  - Disassembled caller snippets at `0x0050e397`, `0x0050e42d`, `0x0050e8fa`, `0x0050e9a0`, `0x005a2f48`, and `0x005a2fa9`.
  - Disassembled `EffectObjectPane` constructor `0x005387b0-0x0053887c`, start-timer helper `0x005388a0-0x005388b4`, update/timer handler `0x005389d0-0x00538aef`, render `0x00538af0-0x00538baa`, and reuse action helper `0x0050eb90-0x0050ec2e`.
- Checked current `by-memory/-coverage-report.md` row for [UID:00023H].
- Ran `tools/int_convert.py` for values used below: `0x7`/7, `0x14c`/332, `0x148`/328, `0x34`/52, `0xc9`/201, `0xa4`/164, `0x18`/24, `0x12c`/300, `0x13c`/316, `0x140`/320, `0x144`/324, `0x14d`/333, `0x14e`/334, `0x170`/368, `0x174`/372, `0x196`/406, and `0x1e0`/480.

## Raw Bounds, Bytes, And Routes

Exact bytes and padding are stable:

```text
0x00538baa-0x00538bb0: cc cc cc cc cc cc
0x00538bb0-0x00538bb7: 8a 81 4c 01 00 00 c3
0x00538bb7-0x00538bc0: cc cc cc cc cc cc cc cc cc
```

Capstone decodes the body as:

```asm
0x00538bb0: mov al, byte ptr [ecx + 0x14c]
0x00538bb6: ret
```

The range is exactly half-open `0x00538bb0-0x00538bb7`, size `0x7` / 7 bytes. There are no callees.

Rel32 scan results:

- Direct calls to `0x00538bb0`: `0x0050e397`, `0x0050e42d`, `0x0050e8fa`, `0x0050e9a0`, `0x005a2f48`, `0x005a2fa9`.
- Direct jumps to `0x00538bb0`: none.
- Dword VA pointer hits to `0x00538bb0` in all PE sections: none.

Conclusion: no vtable, pointer-table, jump-table, or hidden data route is currently evidenced. This is a tiny source-authored non-virtual accessor reached by six direct call sites, not alignment, not a thunk, and not a compiler-only artifact.

## Caller Reanalysis

At `0x0050e397` in [UID:000232] `MapPaneObjectEffectDescriptorDispatch`, pass 0 scans the target object's child collection at target `+0x174`. It loads a child pointer, compares child `+0x148` against the copied `EffectInfo +0x00` descriptor id at stack local `[ebp-0x40]`, then calls this accessor and requires `test al, al` to branch to the reuse helper:

```asm
0x0050e371: mov ebx, dword ptr [edi + 0x174]
0x0050e388: mov edi, dword ptr [eax]
0x0050e38a: mov eax, dword ptr [edi + 0x148]
0x0050e390: cmp eax, dword ptr [ebp - 0x40]
0x0050e395: mov ecx, edi
0x0050e397: call 0x538bb0
0x0050e39c: test al, al
0x0050e39e: jne 0x50e48c
```

At `0x0050e42d`, the same object-id dispatcher repeats the pattern for pass 1, using target child collection `+0x170` and the same copied descriptor id:

```asm
0x0050e408: mov ebx, dword ptr [edi + 0x170]
0x0050e41e: mov edi, dword ptr [eax]
0x0050e420: mov eax, dword ptr [edi + 0x148]
0x0050e426: cmp eax, dword ptr [ebp - 0x40]
0x0050e42b: mov ecx, edi
0x0050e42d: call 0x538bb0
0x0050e432: test al, al
0x0050e434: jne 0x50e4a1
```

At `0x0050e8fa` in [UID:0003TE] `MapPaneCoordinateEffectDescriptorDispatch`, the coordinate/no-target route obtains an existing effect-child collection through object-list helper `0x005325b0`, verifies the child's current coordinate through `0x005374d0`, compares child `+0x148` to copied descriptor id `[ebp-0x50]`, then calls this accessor:

```asm
0x0050e8d8: mov edi, dword ptr [eax]
0x0050e8de: mov ecx, edi
0x0050e8e0: call 0x5374d0
0x0050e8e8: cmp dword ptr [eax + 4], ecx
0x0050e8ed: mov eax, dword ptr [edi + 0x148]
0x0050e8f3: cmp eax, dword ptr [ebp - 0x50]
0x0050e8f8: mov ecx, edi
0x0050e8fa: call 0x538bb0
0x0050e8ff: test al, al
0x0050e901: jne 0x50e9fb
```

At `0x0050e9a0`, the coordinate route repeats the same coordinate/id/accessor gate for the second list helper `0x00532550`:

```asm
0x0050e97e: mov esi, dword ptr [eax]
0x0050e984: mov ecx, esi
0x0050e986: call 0x5374d0
0x0050e98e: cmp dword ptr [eax + 4], ecx
0x0050e993: mov eax, dword ptr [esi + 0x148]
0x0050e999: cmp eax, dword ptr [ebp - 0x50]
0x0050e99e: mov ecx, esi
0x0050e9a0: call 0x538bb0
0x0050e9a5: test al, al
0x0050e9a7: jne 0x50ea11
```

At `0x005a2f48` in [UID:0003U6] `LivingObjectPaneProcessMovement`, the local-player path first calls `MapPaneObjectEffectDescriptorDispatch` with descriptor `0xc9` / 201 and separately copies the same descriptor through `EffectObjImageLib::GetEffectInfo`. It then scans the local-player/UserPane object at `dword_67A748` child collection `+0x174`, compares child `+0x148` to the copied descriptor id at `[ebp-0x44]`, and calls this accessor. On success it invokes the child's first virtual slot with argument `1`, matching the reuse helper's `-1` stop/delete path:

```asm
0x005a2ed5: push 0xc9
0x005a2ee0: call 0x50e320
0x005a2eee: push 0xc9
0x005a2ef4: call 0x4de3e0
0x005a2f1e: mov ecx, dword ptr [eax + 0x174]
0x005a2f38: mov ecx, dword ptr [eax]
0x005a2f3d: mov eax, dword ptr [ecx + 0x148]
0x005a2f43: cmp eax, dword ptr [ebp - 0x44]
0x005a2f48: call 0x538bb0
0x005a2f4d: test al, al
0x005a2f61: push 1
0x005a2f65: call dword ptr [eax]
```

At `0x005a2fa9`, the same local-player movement path scans `dword_67A748 + 0x170` and repeats the id/accessor/virtual-slot pattern:

```asm
0x005a2f7f: mov ecx, dword ptr [eax + 0x170]
0x005a2f96: mov ecx, dword ptr [eax]
0x005a2f9e: mov eax, dword ptr [ecx + 0x148]
0x005a2fa4: cmp eax, dword ptr [ebp - 0x44]
0x005a2fa9: call 0x538bb0
0x005a2fae: test al, al
0x005a2fc2: push 1
0x005a2fc6: call dword ptr [eax]
```

Caller conclusion: MapPane and LivingObjectPane/UserPane paths are consumers. The object passed in `ecx` at all six call sites is an existing effect child taken from effect-child collections, not the target `LivingObjectPane` itself.

## Write-Side Field Evidence

`EffectObjectPane` constructor `0x005387b0-0x0053887c` proves the receiver type and field meanings:

```asm
0x005387dd: mov ecx, dword ptr [ebp + 0x14]   ; EffectInfo* descriptor
0x005387e6: mov al, byte ptr [ebp + 0x1c]      ; caller flag
0x0053880a: mov byte ptr [edi + 0x14d], al
0x00538810: mov eax, dword ptr [ecx]           ; EffectInfo +0x00
0x00538812: mov dword ptr [edi + 0x148], eax   ; runtime effect id/key
0x0053881a: movups xmm0, xmmword ptr [ecx + 0x1c] ; mode 0 sequence
0x0053882c: movups xmm0, xmmword ptr [ecx + 4]    ; nonzero mode sequence
0x0053883c: movq qword ptr [edi + 0x13c], xmm0
0x00538844: cmp dword ptr [edi + 0x13c], 0
0x00538857: cmp dword ptr [edi + 0x140], 0
0x00538860: mov al, 1
0x00538864: xor al, al
0x00538866: mov byte ptr [edi + 0x14c], al
0x0053886e: mov byte ptr [edi + 0x14e], 0
```

Field conclusions:

- `EffectObjectPane +0x148` is the copied effect descriptor id/key. This matches [UID:0001U8] `EffectInfo`, which already records that descriptor `+0x00` is copied to runtime object `+0x148`.
- `EffectObjectPane +0x14c` is a dynamic loop/reuse flag derived from the selected sequence header's range fields at runtime `+0x13c` and `+0x140`. It is initialized true only when both copied range values are nonnegative.
- `EffectObjectPane +0x14d` is the constructor's caller flag from `[ebp+0x1c]`; current evidence does not need it to name [UID:00023H].
- `EffectObjectPane +0x14e` is initialized to zero and is read by the MapPane reuse/timer-action helper as a positive-duration scheduling guard.

`EffectObjectPane` timer/update handler `0x005389d0-0x00538aef` provides the dynamic-state proof for `+0x14c`. The handler is entered on an adjusted timer/event-handler pointer (`EffectObjectPane +0xa4`); its event/command `2` path clears adjusted `+0xa8`, which is object `+0x14c`:

```asm
0x005389e0: sub eax, 1
0x005389e3: je 0x538a08
0x00538a08: mov byte ptr [edi + 0xa8], 0   ; EffectObjectPane +0x14c
0x00538a0f: mov al, 1
```

`MapPaneApplyEffectObjectPaneTimerAction` `0x0050eb90-0x0050ec2e` explains why external callers need this flag. The helper applies actions to an existing reusable effect child:

- action `-1`: invoke the effect object's first vtable slot with argument `1`;
- action `-2`: cancel timer event id `2` on `EffectObjectPane +0xa4`;
- positive action: if `EffectObjectPane +0x14e` is zero, compare/schedule timer event id `2` with `1000 * action`.

This makes `+0x14c` best interpreted as the current loop/reuse-active state, not an entity id, not a LivingObjectPane field, and not a generic visibility byte. Constructor range checks enable looping/reuse, event id `2` disables it, and all six callers use it to decide whether an existing effect object can be reused/stopped instead of creating another one.

## Heuristic / Inference Reanalysis And Validation

Best receiver/source owner: `EffectObjectPane`.

Evidence:

- The only observed writes to `+0x148` and `+0x14c` in the relevant neighborhood are in `EffectObjectPane` constructor/update code.
- `EffectInfo` support docs already state that descriptor `+0x00` is copied to runtime `EffectObjectPane +0x148`.
- [UID:0001D9] documents constructor flags at `+0x14c/+0x14d/+0x14e`, and [UID:0001DA] documents the same `EffectObjectPane +0xa4` timer subobject used by event id `2`.
- All six callers pass a child object selected from effect-child collections or coordinate effect lists. In the MapPane paths the candidate child is later passed to `MapPaneApplyEffectObjectPaneTimerAction`, whose docs already identify the parameter as `EffectObjectPane`.
- The function is physically adjacent to `EffectObjectPane` methods: it follows `EffectObjectPane::RenderEffect` and six bytes of padding, then precedes the mixed object-overlay cluster. Physical placement is not proof alone, but it aligns with the write/caller evidence.

Rejected owner/name alternatives:

- `LivingObjectPane::GetEntityId`: rejected. The function returns a byte at `+0x14c`, while the dword id is separately read from `+0x148` before the call. If the function returned an entity/effect id, the callers would not need the preceding `mov eax, [child+0x148]` / `cmp` sequence.
- `LivingObjectPane` field roles at `+0x148/+0x14c`: rejected as the main target interpretation. A `LivingObjectPane` or local-player object may own the child lists at `+0x170/+0x174`, but the object passed to this accessor is the list element, and write-side evidence identifies that list element as `EffectObjectPane`.
- `MapPane` ownership: rejected. MapPane owns the dispatch/reuse policy but does not own the child object's `+0x148/+0x14c` fields or the accessor body.
- `EffectObjImageLib` ownership: rejected. The image library owns `EffectInfo` and `EffectFrameRecord` resource data, not runtime loop state on an effect pane.
- `AttachedObjectPane`/`ObjectPane` ownership: rejected. They supply base/list/attachment infrastructure, but the descriptor id, sequence header, loop flag, and timer-event behavior are specific to `EffectObjectPane`.

Best source-facing method name: `EffectObjectPane::IsLooping() const`.

Rationale:

- `+0x14c` is initialized from selected sequence range validity, not from a target object id.
- Timer event `2` clears it, which is naturally "stop looping" / "no longer loop-active".
- MapPane and local-player callers use the returned byte as an existing-effect reuse/stop gate. A source method named `IsLooping` explains both why one-shot effects should not be reused and why the local-player path can stop a matching looped effect through vslot 0.
- `CanReuse()` or `IsReusable()` are acceptable descriptive fallbacks if the supervisor wants a callsite-biased name, but they are less source-shaped because the underlying member is not computed from a requested id or caller context; it is a stored dynamic loop flag.
- `HasLoopRange()` is more construction-biased but weaker dynamically, because event id `2` can clear the byte after construction.

Best field names/types:

- `EffectObjectPane::m_effectId` at `+0x148`, `int`. This is the descriptor key/id copied from `EffectInfo +0x00`; all callers compare it with the requested/copied effect descriptor id.
- `EffectObjectPane::m_looping` at `+0x14c`, `bool` or byte-sized boolean. The generated code returns it directly in `al`, and callers use `test al, al`.
- `EffectObjectPane::m_constructorFlag` or `m_compactEffectFlag` at `+0x14d` remains open outside this target. It is stored from constructor argument `[ebp+0x1c]`; current target does not require final naming.
- `EffectObjectPane::m_timerUpdateBlocked` or `m_durationUpdateBlocked` at `+0x14e` remains provisional. It is zeroed by the constructor and checked before positive timer-action scheduling in `0x0050eb90`; current target should mention it only as a sibling flag, not solve it.

Validation/contradiction of current docs:

- Validated: exact bytes, half-open bounds, padding, no-callee status, direct callsite set, and caller-side `+0x148` compare then `test al, al`.
- Corrected: receiver/owner. The current target, LivingObjectPane class/file pages, and coverage row incorrectly describe this as a `LivingObjectPane` byte accessor. The target should be moved to `EffectObjectPane`.
- Corrected: method name. `GetEntityId` is contradicted by the returned offset and caller pattern.
- Corrected: field roles. `+0x148` is runtime effect id, and `+0x14c` is loop/reuse-active state on `EffectObjectPane`.

Impact:

- Score can clear `85/85+` because the previous blockers are solved or narrowed to non-target sibling flags.
- Owner/emitter should change from [UID:0000KU] `LivingObjectPane` file to [UID:000049] `EffectObjectPane` class.
- Formal C++ should no longer stay blank solely because names were provisional. A concise accessor draft is appropriate with inferred field names.
- LivingObjectPane support docs should remove this target from scattered accessors, while MapPane and local-player docs should keep it as a dependency/consumer context.

## Recommended Metadata And Score Changes

Recommended target metadata:

```text
*** UID:00023H | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000049 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000049 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended title/file:

- Preferred file rename: from `0x00538bb0-0x00538bb7.LivingObjectPaneGetEntityId.md` to `0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md`.
- Preferred H1: `# 0x00538bb0-0x00538bb7 EffectObjectPane IsLooping`.
- If the supervisor defers file renaming, update the current file content/title/coverage label anyway and leave a temporary filename mismatch note.

Score rationale:

- Completion `88`: exact raw body, padding, no-callee state, direct call routes, no pointer/table route, caller semantics, constructor writes, timer clear path, field roles, owner correction, support-doc updates, and first-draft C++ are all resolved. Completion remains below final because exact original symbol spelling for `IsLooping` is inferred rather than recovered, and sibling bytes `+0x14d/+0x14e` still need a later class-layout pass.
- Confidence `92`: raw PE/Capstone, current IDA-backed docs, `EffectInfo`, `EffectObjectPane` constructor/timer docs, and all six caller snippets agree. Confidence stays below final-audit only because source names are descriptive inferences.

## First-Draft C++ Recommendation

Populate formal C++ for [UID:00023H]. The target is exact, reconstructable, emits through a gate-clearing class parent, and the body is a source-authored accessor. Draft:

```cpp
bool EffectObjectPane::IsLooping() const
{
    return m_looping;
}
```

Recommended supporting declarations for class-layout notes, not necessarily all inside the target formal block:

```cpp
class EffectObjectPane : public AttachedObjectPane
{
    // ...
    EffectFrameRecord *m_effectFrames;  // +0x12c
    int m_loopStartFrame;               // +0x13c, selected descriptor range start
    int m_loopEndFrame;                 // +0x140, selected descriptor range end
    int m_currentFrame;                 // +0x144
    int m_effectId;                     // +0x148, copied from EffectInfo::effectKeyOrId
    bool m_looping;                     // +0x14c, cleared by timer event 2
    bool m_effectFlag;                  // +0x14d, final name open
    bool m_durationUpdateBlocked;       // +0x14e, final name open
};
```

Why this is source-shaped rather than raw decompiler output:

- MSVC can compile a byte-sized `bool` accessor returning a member to the observed `mov al, [ecx+0x14c]; ret`.
- The method has no explicit parameters, matching all six `thiscall` call sites.
- The name reflects write-side behavior and timer semantics, not a raw offset or generated `sub_538BB0` label.
- A raw `char __thiscall sub_538BB0(_BYTE *this)` should not be emitted because it preserves the stale wrong receiver and loses the class source meaning.

## Exact Supervisor Changes Required

### 1. Target Page Replacement Direction

Placement: replace the target page body in [UID:00023H]. Preserve UID/header sentinels, updating only allowed metadata values.

Recommended replacement title/status paragraphs:

```markdown
# 0x00538bb0-0x00538bb7 EffectObjectPane IsLooping

## Status

- Disposition: reconstructable NexusTK project code.
- Entity kind: tiny non-virtual `EffectObjectPane` byte/bool accessor.
- Direct owner/emitter: [UID:000049][EffectObjectPane](by-class/EffectObjectPane.md); file owner [UID:0000IZ][Effects](by-file/Effects.md).
- Rebuild handling: source-authored accessor, not compiler padding, not a thunk, and not vtable data.
- Confidence: very strong for exact boundary, direct caller set, no-callee state, write-side field evidence, and corrected `EffectObjectPane` ownership; medium-high for exact original source spelling of `IsLooping`.
- Prior name caveat: the old `LivingObjectPaneGetEntityId`/`GetEntityId` label is stale. The function returns byte `EffectObjectPane + 0x14c`; callers separately compare dword `EffectObjectPane + 0x148` against the requested effect descriptor id before calling this accessor.
```

Recommended behavior replacement:

```markdown
## Behavior

Returns the byte-sized loop/reuse state at `EffectObjectPane + 0x14c` in `al`. The best source-facing name is `EffectObjectPane::IsLooping() const`.

The field is initialized by the `EffectObjectPane` constructor from the selected `EffectInfo` sequence range: it becomes true only when copied range fields at runtime `+0x13c` and `+0x140` are both nonnegative. The `EffectObjectPane` timer/update handler clears the same byte on event id `2`, which is the stop-looping/reuse-expiration path used by MapPane effect scheduling. MapPane and local-player callers use the accessor as a nonzero gate after matching `EffectObjectPane +0x148` against the copied effect descriptor id.
```

Recommended touched-state table:

```markdown
## Touched State

| Offset/global | Access | Meaning |
| --- | --- | --- |
| `this + 0x148` | caller-side read/compare; constructor write | `EffectObjectPane::m_effectId`, copied from `EffectInfo +0x00`; callers compare it with the requested/copied effect descriptor id. |
| `this + 0x14c` | accessor read; constructor write; timer event `2` clear | `EffectObjectPane::m_looping` / loop-reuse-active byte. Returned by this accessor and tested as boolean/nonzero. |
| `this + 0x14d` | constructor write only in checked target context | Neighbor flag copied from constructor argument; final name outside this target. |
| `this + 0x14e` | constructor clear; MapPane timer-action read | Positive duration scheduling guard; final name outside this target. |
| `EffectInfo + 0x00` | copied by constructor | Source effect descriptor id/key. |
```

Recommended evidence additions:

```markdown
## Evidence

- Capstone/raw PE recheck on 2026-06-18 confirms bytes `8a 81 4c 01 00 00 c3` at `0x00538bb0-0x00538bb7`, preceded by six `0xcc` bytes and followed by nine `0xcc` bytes.
- Rel32 scan finds exactly six direct calls to `0x00538bb0`: `0x0050e397`, `0x0050e42d`, `0x0050e8fa`, `0x0050e9a0`, `0x005a2f48`, and `0x005a2fa9`; no direct jumps and no dword pointer values to the target were found in the PE sections.
- `EffectObjectPane` constructor `0x005387b0` stores descriptor `EffectInfo +0x00` into object `+0x148`, copies a selected 24-byte frame/loop sequence header into `+0x12c..+0x143`, then sets byte `+0x14c` to true only when runtime `+0x13c` and `+0x140` are nonnegative.
- `EffectObjectPane` timer/update handler `0x005389d0` clears object byte `+0x14c` through its adjusted timer-handler pointer path on event id `2`.
- `MapPaneApplyEffectObjectPaneTimerAction` `0x0050eb90` handles an existing `EffectObjectPane`: action `-1` invokes vslot 0 with argument `1`, action `-2` cancels timer event id `2`, and positive actions schedule/extend event id `2` when `+0x14e` allows it.
- The six direct callers all compare candidate child `+0x148` against the copied effect descriptor id, then call this accessor and branch on `test al, al`. This proves the target is a loop/reuse-state accessor, not an id getter.
```

Recommended reconstruction notes:

````markdown
## Reconstruction Notes

Emit this as a small `EffectObjectPane` accessor:

```cpp
bool EffectObjectPane::IsLooping() const
{
    return m_looping;
}
```

Do not keep the old `LivingObjectPaneGetEntityId` name. The target object in some caller contexts is a living object or local-player object, but the receiver passed to this accessor is an `EffectObjectPane` child found in effect-child collections.
````

Recommended score rationale:

```markdown
## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `88` | Exact bytes, half-open bounds, padding, no-callee state, direct caller set, no hidden pointer/table route, caller-side effect-id/loop gate pattern, `EffectObjectPane` constructor writes, timer clear path, corrected owner/emitter, rejected stale LivingObjectPane/GetEntityId interpretation, and first-draft accessor C++ are documented. Completion is below final only because the exact original spelling `IsLooping` remains an inferred source name and sibling flags `+0x14d/+0x14e` need a later class-layout pass. |
| Confidence `92` | Raw PE/Capstone evidence, existing IDA-backed docs, `EffectInfo`, `EffectObjectPane` constructor/timer docs, and all six caller snippets agree that this is an `EffectObjectPane` loop/reuse-state accessor. Confidence is not 95+ because source symbol names are inferred rather than recovered. |
```

### 2. LivingObjectPane Class/File Support

Placement: in [UID:00007B] `by-class/LivingObjectPane.md`, replace the `Scattered accessors` method-family row.

Replacement row:

```markdown
| Scattered accessors | [UID:000233][0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck](by-memory/0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck.md), `0x005374d0`, `0x005376c0`, `0x005376d0` | GM suffix check, position/type/id accessors, and animation-state setter. The former [UID:00023H][0x00538bb0-0x00538bb7.LivingObjectPaneGetEntityId](by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md) scattered-accessor candidate is now resolved as `EffectObjectPane::IsLooping`, not a `LivingObjectPane` method. |
```

Placement: in [UID:00007B] boundary caveats, insert:

```markdown
- [UID:00023H][0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping](by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md) should no longer be counted as a `LivingObjectPane` scattered accessor. MapPane and local-player callers reach it while scanning effect-child collections, but the receiver is an `EffectObjectPane`; `+0x148` is the copied effect descriptor id and `+0x14c` is the effect loop/reuse-active flag.
```

Placement: in [UID:0000KU] `by-file/LivingObjectPane.md`, replace its `Scattered accessors` row with the same ownership correction, and remove [UID:00023H] from the `LivingObjectPane` cross-reference inventory or move it to a "Related consumer/dependency caveat" note with the text above.

### 3. EffectObjectPane Class Support

Placement: in [UID:000049] `by-class/EffectObjectPane.md`, add to the Methods table after `0x00538af0-0x00538baa RenderEffect`.

Insert row:

```markdown
| [UID:00023H][0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping](by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md) | `IsLooping` | Seven-byte non-virtual accessor returning byte `+0x14c`; MapPane effect descriptor dispatch and local-player movement effect cleanup call it after matching `+0x148` against the effect descriptor id. |
```

Placement: in [UID:000049] Responsibility or Open Questions, insert:

```markdown
`EffectObjectPane +0x148` is the copied `EffectInfo +0x00` effect id/key. Byte `+0x14c` is best named `m_looping`: the constructor sets it when the selected sequence range fields are valid, timer event id `2` clears it, and MapPane/local-player callers use [UID:00023H] `IsLooping()` as an existing-effect reuse/stop gate. Sibling bytes `+0x14d` and `+0x14e` remain class-layout follow-up items.
```

Add [UID:00023H] to [UID:000049] Cross-References.

### 4. EffectObjectPane Core And Types

Placement: in [UID:0001D9] `EffectObjectPaneCore.md`, update the constructor note.

Replacement sentence:

```markdown
- Constructor decompilation calls `0x005372d0` with object type derived from the effect kind, stores the target object at `+0x128`, writes EffectObjectPane vtables at `+0x00`, `+0xa0`, and `+0xa4`, copies one of two frame descriptor blocks from the constructor data, initializes current-frame state to `-1`, stores the copied effect descriptor id at `+0x148`, sets loop/reuse byte `+0x14c` from the selected range validity at `+0x13c/+0x140`, stores caller flag `+0x14d`, and clears duration/update guard byte `+0x14e`.
```

Placement: in [UID:0001D9] boundary notes, insert:

```markdown
- The tiny successor [UID:00023H][0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping](by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md) follows `0x00538baa-0x00538bb0` padding and belongs to `EffectObjectPane`, not `LivingObjectPane`.
```

Placement: in [UID:0001U8] `EffectInfo.md`, after the runtime consumer bullets, insert:

```markdown
- `EffectObjectPane::IsLooping` [UID:00023H] returns runtime byte `+0x14c`. The constructor sets that byte from the selected sequence range fields copied into runtime `+0x13c/+0x140`, so descriptor ranges with nonnegative start and end become reusable/loop-active effect children.
```

### 5. MapPane/Local-Player Consumer Docs

Placement: in [UID:000232] `MapPaneObjectEffectDescriptorDispatch.md`, replace "LivingObjectPaneGetEntityId" references with:

```markdown
A child can be reused only when its `EffectObjectPane::m_effectId` dword at offset `+0x148` matches the descriptor id copied from `EffectInfo +0x00` and [UID:00023H][EffectObjectPane::IsLooping](by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md) returns nonzero from byte `+0x14c`.
```

Placement: in [UID:0003TE] `MapPaneCoordinateEffectDescriptorDispatch.md`, replace the active/gate helper sentence with:

```markdown
- compares existing `EffectObjectPane` child ids at `+0x148` against the copied descriptor id and applies [UID:00023H][EffectObjectPane::IsLooping](by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md) as the loop/reuse-active gate;
```

Placement: in [UID:0003U6] `LivingObjectPaneProcessMovement.md`, add:

```markdown
The early `0xc9` effect cleanup path is a consumer of `EffectObjectPane` loop state, not owner evidence for [UID:00023H]. After copying descriptor `0xc9` through `EffectObjImageLib::GetEffectInfo`, the method scans local-player/UserPane effect-child collections at `dword_67A748 +0x174` and `+0x170`, matches child `EffectObjectPane +0x148` to the copied descriptor id, calls [UID:00023H] `EffectObjectPane::IsLooping`, and invokes the child's first virtual slot with argument `1` on a match.
```

Placement: in [UID:0003TG] `MapPaneApplyEffectObjectPaneTimerAction.md`, add:

```markdown
Timer event id `2` is the event that clears `EffectObjectPane +0x14c` in the `EffectObjectPane` timer/update handler. Therefore this helper's `-2` cancel path and positive duration scheduling path operate on the same loop/reuse-active state returned by [UID:00023H] `EffectObjectPane::IsLooping`.
```

## Coverage Report Replacement Text

Placement: replace the existing [UID:00023H] row in `by-memory/-coverage-report.md` currently reading `LivingObjectPaneGetEntityId`.

Preferred replacement row if the file is renamed:

```markdown
    - [UID:00023H][0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping](by-memory/0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping.md) 0x00538bb0-0x00538bb7 | accessor | EffectObjectPaneIsLooping : reconstructable : 88% : very strong : Seven-byte `EffectObjectPane::IsLooping` byte/bool accessor returning object `+0x14c`; raw PE recheck confirms exact `0x00538bb0-0x00538bb7` bounds, `0xcc` padding on both sides, no callees, six direct rel32 callers, no pointer/table/jump route, constructor writes `+0x148` from `EffectInfo+0x00`, constructor/timer semantics for loop/reuse byte `+0x14c`, MapPane/local-player effect-child reuse callers, corrected owner/emitter [UID:000049] `EffectObjectPane`, rejected stale `LivingObjectPaneGetEntityId` interpretation, and first-draft C++ readiness.
```

Alternate replacement row if the supervisor keeps the old filename temporarily:

```markdown
    - [UID:00023H][0x00538bb0-0x00538bb7.EffectObjectPaneIsLooping](by-memory/0x00538bb0-0x00538bb7.LivingObjectPaneGetEntityId.md) 0x00538bb0-0x00538bb7 | accessor | EffectObjectPaneIsLooping : reconstructable : 88% : very strong : Seven-byte `EffectObjectPane::IsLooping` byte/bool accessor returning object `+0x14c`; raw PE recheck confirms exact `0x00538bb0-0x00538bb7` bounds, `0xcc` padding on both sides, no callees, six direct rel32 callers, no pointer/table/jump route, constructor writes `+0x148` from `EffectInfo+0x00`, constructor/timer semantics for loop/reuse byte `+0x14c`, MapPane/local-player effect-child reuse callers, corrected owner/emitter [UID:000049] `EffectObjectPane`, rejected stale `LivingObjectPaneGetEntityId` interpretation, and first-draft C++ readiness.
```

## Validation Commands For Supervisor

Commands I ran or equivalent checks:

> Executable block R001 was removed from this report and preserved verbatim in [00023H-LivingObjectPaneGetEntityId-source-quality-removed.md](00023H-LivingObjectPaneGetEntityId-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

IDA MCP was unavailable here:

> Executable block R002 was removed from this report and preserved verbatim in [00023H-LivingObjectPaneGetEntityId-source-quality-removed.md](00023H-LivingObjectPaneGetEntityId-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Observed result: `Unable to connect to the remote server`.

Post-application validators to run:

> Executable block R003 was removed from this report and preserved verbatim in [00023H-LivingObjectPaneGetEntityId-source-quality-removed.md](00023H-LivingObjectPaneGetEntityId-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor keeps the old filename, substitute `by-memory\0x00538bb0-0x00538bb7.LivingObjectPaneGetEntityId.md` in the first validator command.

## Remaining Blockers

- No blocker prevents [UID:00023H] from reaching `85/85+` or receiving first-draft C++.
- The exact original spelling of `EffectObjectPane::IsLooping` is not proven by symbols; it is the highest-probability source-facing name from constructor/timer/caller evidence.
- Sibling fields `EffectObjectPane +0x14d` and `+0x14e` remain class-layout follow-up items. They should not cap this target because [UID:00023H] reads only `+0x14c`, and the current report records enough surrounding evidence to avoid misnaming the accessor.
- IDA MCP was unavailable during this pass, so live IDA-specific commands were not rerun. Existing IDA-backed pages plus raw PE/Capstone checks were sufficient to resolve the target's current source-quality blockers.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/00023H-LivingObjectPaneGetEntityId-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"00023H"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00023H-LivingObjectPaneGetEntityId-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/00023H-LivingObjectPaneGetEntityId-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00023H"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
