** TARGET-REPORT-UID:0002F5 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002F5 / 0002FB / 0002FI / 0002FY Chatting Destructor Cluster Source-Quality Report

Report-only B005 pass for:

- [UID:0002F5] `by-memory/0x00480860-0x00480889.ChattingModifyHeightPaneDestructor.md`
- [UID:0002FB] `by-memory/0x00480ca0-0x00480cc9.ChattingVarietyPaneDestructor.md`
- [UID:0002FI] `by-memory/0x00481150-0x004811bc.ChattingVarietySelectPaneDestructor.md`
- [UID:0002FY] `by-memory/0x00482b10-0x00482b2f.ChattingColorPaneDestructor.md`

## Final Recommendation

Raise the first three ordinary `Pane`-derived destructor bodies to `88/90`, keep their direct class owners/emitters, and populate first-draft C++:

```text
[UID:0002F5] 84/88 -> 88/90, CANONICAL_OWNER:00001W, EMITTER_UIDS:00001W
[UID:0002FB] 84/88 -> 88/90, CANONICAL_OWNER:00001Y, EMITTER_UIDS:00001Y
[UID:0002FI] 84/88 -> 88/90, CANONICAL_OWNER:00001Z, EMITTER_UIDS:00001Z
```

Move [UID:0002FY] from stale file-owned metadata to the now-valid direct class owner [UID:00001T] `ChattingColorPane`, raise it to `87/90`, and populate an empty source destructor body:

```text
[UID:0002FY] 84/88 -> 87/90, CANONICAL_OWNER:00001T, EMITTER_UIDS:00001T
```

No split, merge, range repair, padding repair, global rename, or direct edit to `by-memory/-coverage-report.md` is recommended. The supervisor should apply the target/support/coverage text below.

## Scope And Evidence Rechecked

Read active instructions and policy:

- `tools/leaser/Agents/Agent-B005/goal.md`
- `tools/leaser/Agents/Agent-B005/notes.md`
- `tools/leaser/Agents/Supervisor.md`
- `by-structure.md`
- `inference_research.md`

Read target/support docs:

- The four assigned target pages.
- [UID:00001W] `ChattingModifyHeightPane`, [UID:00001Y] `ChattingVarietyPane`, [UID:00001Z] `ChattingVarietySelectPane`, [UID:00001T] `ChattingColorPane`.
- [UID:0000I5] `Chatting` file, [UID:000104] `ChattingUI`, [UID:0003AT] `ChattingVtableData`, [UID:0002GI] `ChattingUiDestructorGlueFamily`.
- `PaneCore`, `PaneVtables`, `DialogPane`, `DialogPaneVtables`, and `g_activeDialogCount` support docs.
- Singleton pages for `g_pChattingModifyHeightPane`, `g_pChattingVarietyPane`, and `g_pChattingVarietySelectPane`.
- Current `project-level/-auto-completion-stats.md`, `by-memory/-coverage-report.md`, generated `auto-generated/NexusTK/social/Chatting.cpp`, and the accepted [UID:0002F2] `ChattingBackPaneDestructor` B005 report.

Live IDA MCP on `127.0.0.1:13337` was unavailable during this pass. I therefore used current target docs that already carry live-IDA evidence, current exported IDA function records under `resources/exported_data/functions`, and the checked IDA listing `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.lst`. This is enough for this report because the remaining questions are source-quality/helper-name/owner questions, and the exact instructions/xrefs already exist in stable exported IDA artifacts.

## Target Evidence Summary

| UID | Exact range | Boundary / padding | Ordinary body | Direct ordinary-body xrefs | Scalar deleting route |
| --- | --- | --- | --- | --- | --- |
| `0002F5` | `0x00480860-0x00480889` | Previous constructor ends `0x0048085d`; `0x0048085e-0x00480860` is 2 bytes `0xcc`; `0x00480889-0x00480890` is 7 bytes `0xcc`. | Stores `ChattingModifyHeightPane` vtables `0x00614e18/0x00614e64/0x00614e94`, clears `dword_67ADD4` / `g_pChattingModifyHeightPane`, tail-jumps to `0x00544580`. | None in exported IDA record; no modeled callers. | `0x00483c00-0x00483c5f`, xrefs from adjustor thunks `0x00483a49/0x00483a54` and vtable data `0x00614e18`; mirrors clear and calls base teardown before optional delete. |
| `0002FB` | `0x00480ca0-0x00480cc9` | Previous constructor ends `0x00480c9e`; `0x00480c9f-0x00480ca0` is 1 byte `0xcc`; `0x00480cc9-0x00480cd0` is 7 bytes `0xcc`. | Stores `ChattingVarietyPane` vtables `0x00614ea0/0x00614ef0/0x00614f20`, clears `dword_67ADD8` / `g_pChattingVarietyPane`, tail-jumps to `0x00544580`. | None in exported IDA record; no modeled callers. | `0x00483d50-0x00483daf`, xrefs from adjustor thunks `0x00483a75/0x00483a80` and vtable data `0x00614ea0`; mirrors clear and calls base teardown before optional delete. |
| `0002FI` | `0x00481150-0x004811bc` | Previous raw constructor ends `0x00481145`; `0x00481146-0x00481150` is 10 bytes `0xcc`; `0x004811bc-0x004811c0` is 4 bytes `0xcc`. | SEH-framed body stores `ChattingVarietySelectPane` vtables `0x00614f2c/0x00614f80/0x00614fb0`, calls `0x00544ce0`, calls `0x00544d70`, clears `dword_67ADDC` / `g_pChattingVarietySelectPane`, then calls `0x00544580`. | None in exported IDA record; no modeled callers. | `0x00483db0-0x00483e5d`, xrefs from adjustor thunks `0x00483a8b/0x00483a96` and vtable data `0x00614f2c`; mirrors helper calls, clear, base teardown, optional delete. |
| `0002FY` | `0x00482b10-0x00482b2f` | Previous constructor ends `0x00482b00`; `0x00482b01-0x00482b10` is 15 bytes `0xcc`; `0x00482b2f-0x00482b30` is 1 byte `0xcc`. | Stores `ChattingColorPane` vtables `0x00615048/0x006150a8/0x006150d8`, then tail-jumps to `0x0049d9f0`. It does not clear any singleton/global. | None in exported IDA record; no modeled callers. | `0x00483b40-0x00483b95`, xrefs from adjustor thunks `0x00483a1d/0x00483a28` and vtable data `0x00615048`; mirrors vtable stores, calls `0x0049d9f0`, optional delete. |

IDA listing confirmation:

- `sub_480860` at `0x00480860` contains only three `ChattingModifyHeightPane` vtable stores, `mov dword_67ADD4, 0`, and `jmp sub_544580`.
- `sub_480CA0` at `0x00480ca0` contains only three `ChattingVarietyPane` vtable stores, `mov dword_67ADD8, 0`, and `jmp sub_544580`.
- `sub_481150` at `0x00481150` contains the SEH prologue, three `ChattingVarietySelectPane` vtable stores, calls to `sub_544CE0`, `sub_544D70`, `mov dword_67ADDC, 0`, and call to `sub_544580`.
- `sub_482B10` at `0x00482b10` contains only three `ChattingColorPane` vtable stores and a jump to IDA's polluted `??1exception@boost@@MAE@XZ_0` label at `0x0049d9f0`.

## Helper Name Resolution

### `0x00544580`

Best source-facing name: ordinary non-deleting `Pane::~Pane()` body at `0x00544580-0x00544687`.

Evidence:

- Current `PaneCore` says to reconstruct ordinary `virtual Pane::~Pane()` from `0x00544580-0x00544687` and regenerate adjustor/scalar deleting glue from declarations.
- `PaneCore` function table describes it as restoring the three Pane vtables, unregistering focus/dispatcher/layer state, destroying owned regions/handler subobjects, and chaining to `GrafPort` cleanup.
- `ChattingUiDestructorGlueFamily` was already updated by the accepted [UID:0002F2] pass to identify this shared base helper as ordinary `Pane::~Pane()`.
- Exported IDA function record still has generated Ghidra pollution as `~TextButtonExControlPane`, but the body and Pane docs supersede that label.

Rejected alternatives:

- `TextButtonExControlPane::~TextButtonExControlPane`: rejected as generated-owner/type-propagation pollution.
- `GrafPort::~GrafPort`: rejected because `GrafPort` cleanup is a dependency called inside Pane teardown, not this function.
- Generic "base pane teardown helper": acceptable as old descriptive text but weaker than current source-quality name.

Impact: do not write `Pane::~Pane()` explicitly in the derived target C++ blocks. The compiler emits the base-destructor call after the derived destructor body.

### `0x00544ce0` and `0x00544d70`

Best source-facing names:

- `0x00544ce0-0x00544d2a`: `Pane::RemoveFromLayer`
- `0x00544d70-0x00544dae`: `Pane::UnregisterEventHandler`

Evidence:

- `PaneCore` names `0x00544ce0` as `Pane::RemoveFromLayer`, the layer detach helper reached through primary vtable slot `+0x38`.
- `PaneCore` names `0x00544d70` as `Pane::UnregisterEventHandler`, the dispatcher/event-handler unregister helper for the view at `this + 0xa0`, reached through primary vtable slot `+0x40`.
- `PaneVtables` documents these as inherited Pane slots, not selector-specific helpers.
- [UID:0002FI] and its scalar deleting wrapper call both directly before clearing `g_pChattingVarietySelectPane`, which is consistent with an explicitly detached popup before singleton reset.

Rejected alternatives:

- `sub_544CE0` / `sub_544D70` raw names: rejected because current PaneCore resolves them.
- `ChattingVarietySelectPane` private helpers: rejected because caller fan-in is broad and Pane vtable docs assign these slots to Pane.
- Compiler-only cleanup: rejected because the calls are in the ordinary destructor body before the base destructor, and the best source shape is explicit inherited method calls.

### `0x0049d9f0`

Best source-facing name: ordinary `DialogPane::~DialogPane()` / common dialog cleanup body at `0x0049d9f0-0x0049dacb`.

Evidence:

- `DialogPane` docs identify `0x0049d9f0-0x0049dacb` as cleanup/non-deleting destructor despite local IDA name pollution.
- The body writes DialogPane vtables, decrements `byte_69B380` / `g_activeDialogCount`, releases the control manager at `+0x1fc`, destroys the tile context at `+0x23c`, and calls `Pane::~Pane()`.
- `DialogCoreReadOnlyData` and `DialogPaneVtables` document the `0x00618a64/0x00618ac4/0x00618af4` vtable family and scalar/delete glue. This is a base dialog destructor, not `ChattingColorPane` custom logic.
- Exported IDA/Ghidra names such as `boost::exception::~exception` and `~TransferReplyAlert` are contradicted by the body and current DialogPane docs.

Rejected alternatives:

- `boost::exception::~exception`: rejected as IDA demangle/type pollution.
- `TransferReplyAlert::~TransferReplyAlert`: rejected as Ghidra type propagation from a derived dialog.
- `ChattingColorPane` custom helper: rejected because the body is broadly shared by many dialogs and manipulates DialogPane layout/state.

Impact: [UID:0002FY] source C++ should not explicitly call `DialogPane::~DialogPane()`. It is the implicit base destructor after an empty `ChattingColorPane` destructor body.

## Global And Singleton Validation

- `dword_67ADD4` is the documented `g_pChattingModifyHeightPane` slot at `0x0067add4`. The global page records 7 xrefs and direct constructor/destructor/scalar clear lifecycle. Use `g_pChattingModifyHeightPane` in [UID:0002F5] C++.
- `dword_67ADD8` is the documented `g_pChattingVarietyPane` slot at `0x0067add8`. The global page records 18 xrefs, selector behavior, and target-selection cleanup consumers. Use `g_pChattingVarietyPane` in [UID:0002FB] C++.
- `dword_67ADDC` is the documented `g_pChattingVarietySelectPane` slot at `0x0067addc`. The global page records the 7-ref selector lifecycle and current zero-filled storage bytes. Use `g_pChattingVarietySelectPane` in [UID:0002FI] C++.
- No `g_pChattingColorPane` clear exists in [UID:0002FY], its scalar deleting wrapper, `UiChatClanSingletonSlots`, or the current `ChattingColorPane` constructor/button-handler docs. Rejected source shapes that clear a color-pane singleton are unsupported.

The three singleton clears are unconditional zero stores. Do not add `if (g_p... == this)` guards because no compare exists in the ordinary bodies or scalar deleting wrappers.

## Ownership And Source Placement Ranking

### Accepted owners

1. [UID:00001W] `ChattingModifyHeightPane` for [UID:0002F5].
   - Evidence: exact `ChattingModifyHeightPane` vtable stores, RTTI/COL vtable row, `g_pChattingModifyHeightPane` singleton lifecycle, constructor/mouse/key/set-line/paint class cluster, and source route through [UID:0000I5] `Chatting`.
   - Decision: keep owner/emitter [UID:00001W].

2. [UID:00001Y] `ChattingVarietyPane` for [UID:0002FB].
   - Evidence: exact `ChattingVarietyPane` vtable stores, `g_pChattingVarietyPane` lifecycle, compact selector class cluster, declaration-ready class page, and source route through [UID:0000I5] `Chatting`.
   - Decision: keep owner/emitter [UID:00001Y].

3. [UID:00001Z] `ChattingVarietySelectPane` for [UID:0002FI].
   - Evidence: exact `ChattingVarietySelectPane` vtable stores, `g_pChattingVarietySelectPane` lifecycle, selector popup row/mouse/paint/helper cluster, class declaration route, and explicit inherited Pane cleanup calls.
   - Decision: keep owner/emitter [UID:00001Z].

4. [UID:00001T] `ChattingColorPane` for [UID:0002FY].
   - Evidence: exact `ChattingColorPane` vtable stores, constructor [UID:0002FX] already class-owned/emitted with first-draft C++, button handler and local raw helpers are class-owned in current docs, class page is now `85/88`, and [UID:0002FY] target itself names [UID:00001T] as semantic owner while metadata remains stale file-owned.
   - Decision: change [UID:0002FY] `CANONICAL_OWNER` and `EMITTER_UIDS` from [UID:0000I5] to [UID:00001T]. The generated source still surfaces through `social/Chatting.cpp`.

### Rejected or lower-ranked owners

- [UID:0000I5] `Chatting` as direct owner: correct source file route for all four targets, but less precise than class ownership for exact destructor bodies. Keep file route through class/file containment, not direct target ownership except where a class owner is unavailable.
- [UID:000104] `ChattingUI` aggregate: correct physical neighborhood/index, but too broad for method-body emission.
- [UID:0002GI] `ChattingUiDestructorGlueFamily`: records scalar deleting destructors, adjustor thunks, and cleanup glue. It is compiler-generated support and explicitly non-reconstructable, not source owner.
- [UID:0000A2] / [UID:0000MC] `Pane`: owns `0x00544580`, `0x00544ce0`, and `0x00544d70`, but not the derived vtable stores or singleton clears.
- [UID:00003P] / [UID:0000IS] `DialogPane`: owns `0x0049d9f0`, but not `ChattingColorPane` vtable restoration or destructor identity.
- Peer chat classes (`ChattingBackPane`, `ChattingHandlePane`, `ChattingColorListPane`, `ChattingColorSelectPane`) and generic UI/core owners: rejected by class-specific vtables, RTTI/COL rows, global slots, and local method clusters.
- New `social/ChatColorDialog.cpp`: plausible future file split for `ChattingColorPane`, `ChattingColorSelectPane`, `ChattingColorListPane`, and color constants, but current [UID:0000I5] `Chatting` docs explicitly keep the color-dialog classes in `social/Chatting.cpp` for current emission. Do not move [UID:0002FY] to a new file in this pass.

## First-Draft C++ Recommendation

Populate [UID:0002F5] with:

```cpp
ChattingModifyHeightPane::~ChattingModifyHeightPane()
{
    g_pChattingModifyHeightPane = NULL;
}
```

Populate [UID:0002FB] with:

```cpp
ChattingVarietyPane::~ChattingVarietyPane()
{
    g_pChattingVarietyPane = NULL;
}
```

Populate [UID:0002FI] with:

```cpp
ChattingVarietySelectPane::~ChattingVarietySelectPane()
{
    RemoveFromLayer();
    UnregisterEventHandler();
    g_pChattingVarietySelectPane = NULL;
}
```

Populate [UID:0002FY] with:

```cpp
ChattingColorPane::~ChattingColorPane()
{
}
```

Rationale:

- All four targets clear the active code-entry gate: `RECONSTRUCTABLE:TRUE`, nonblank emitter route, and current `(84 + 88) / 2 = 86` already above the minimum gate before this pass.
- The remaining target-specific blockers are resolved: destructor identities are standard class destructors, `0x00544580` is `Pane::~Pane()`, `0x00544ce0`/`0x00544d70` are inherited Pane layer/event cleanup methods, and `0x0049d9f0` is `DialogPane::~DialogPane()`.
- C++ should model source-authored behavior only. Do not include vtable stores, scalar deleting destructors, adjustor thunks, optional `operator delete`, SEH frames, security cookie checks, or implicit base destructor calls.
- `NULL` matches the accepted [UID:0002F2] pre-C++11 style. `0` is equivalent, but use `NULL` for sibling consistency.
- [UID:0002FY] has no singleton clear or direct source statement. An empty out-of-line destructor is the best first-draft source representation for this exact method target; the binary vtable resets and `DialogPane::~DialogPane()` tail jump are compiler output from the destructor declaration and class inheritance.

No target-specific no-code proof remains. Leaving any of the four formal C++ blocks blank would now preserve stale helper/owner uncertainty that this pass resolves.

## Score And Metadata Recommendation

Recommended target metadata:

```text
[UID:0002F5]
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:00001W
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00001W

[UID:0002FB]
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:00001Y
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00001Y

[UID:0002FI]
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:00001Z
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00001Z

[UID:0002FY]
COMPLETION:87
CONFIDENCE:90
CANONICAL_OWNER:00001T
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00001T
```

Score rationale:

- Completion rises because all open target blockers are resolved: source-facing destructor names, helper/base names, singleton/global names, source body shape, owner/source placement, vtable/scalar route, and first-draft C++ readiness.
- Confidence is capped below final-audit levels because live IDA MCP was unavailable in this session, exact original source file split between `social/Chatting.cpp` and a possible future `social/ChatColorDialog.cpp` is still not final, and broader class pages still have unrelated final-polish helper/type issues.
- [UID:0002FY] receives `87/90` instead of `88/90` because the destructor has no source-authored side effects and depends on `DialogPane` base teardown/source declaration shape; the owner reroute and empty C++ are strong, but slightly less behavior-rich than the singleton-clear destructors.
- No global, class, file, or glue-family score change is required from this report alone. Support docs should incorporate the facts, but the broad class/file pages still have independent open issues.

## Support-Doc Incorporation Recommendations

### Target pages [UID:0002F5], [UID:0002FB], [UID:0002FI]

For each target page, replace the open-question/blocker wording about destructor spelling and `0x00544580` with:

```markdown
## Resolved Source-Quality Questions

- The source-facing identity is the ordinary class destructor, not the scalar deleting destructor wrapper and not an address-named helper.
- The shared base target `0x00544580-0x00544687` is ordinary `Pane::~Pane()` per current PaneCore/Pane vtable evidence. It is emitted by the compiler as the implicit base destructor call and should not be hand-written in this target's C++ body.
- Vtable restoration, adjustor thunks, scalar deleting destructor wrappers, optional delete, and padding are compiler-generated ABI material.
```

For [UID:0002F5], add or replace the first-draft C++ section with the exact `ChattingModifyHeightPane::~ChattingModifyHeightPane()` body above.

For [UID:0002FB], add or replace the first-draft C++ section with the exact `ChattingVarietyPane::~ChattingVarietyPane()` body above.

For [UID:0002FI], add this additional resolved helper note:

```markdown
- The pre-base cleanup callees are inherited Pane methods: `0x00544ce0` is `Pane::RemoveFromLayer()` and `0x00544d70` is `Pane::UnregisterEventHandler()`. They are explicit source-level cleanup calls in the selector destructor before `g_pChattingVarietySelectPane` is cleared and `Pane::~Pane()` runs implicitly.
```

Then add or replace the first-draft C++ section with the exact `ChattingVarietySelectPane::~ChattingVarietySelectPane()` body above.

### Target page [UID:0002FY]

Update status/assignment wording to:

```markdown
- Owner: [UID:00001T][ChattingColorPane](by-class/ChattingColorPane.md).
- Source file route: [UID:0000I5][Chatting](by-file/Chatting.md) / `social/Chatting.cpp`.
- The previous file-owned metadata was stale from the period when [UID:00001T] was below the class-owner gate; the class is now `85/88` and owns the constructor, destructor, button response, and local raw color-dialog helpers.
```

Replace the `0x0049d9f0` open question with:

```markdown
## Resolved Source-Quality Questions

- The source-facing identity is `ChattingColorPane::~ChattingColorPane()`.
- The target has no source-authored side effects: it restores `ChattingColorPane` vtables and compiler-chains to the inherited `DialogPane::~DialogPane()` body at `0x0049d9f0`.
- `0x0049d9f0-0x0049dacb` is `DialogPane` cleanup / non-deleting destructor body, not `boost::exception::~exception`, not `TransferReplyAlert::~TransferReplyAlert`, and not a ChattingColorPane-private helper. The body decrements `g_activeDialogCount`, releases DialogPane control/tile-context state, restores DialogPane vtables, and calls `Pane::~Pane()`.
- No `g_pChattingColorPane` singleton clear exists in this destructor or its scalar deleting wrapper; do not invent one in C++.
```

Add or replace the first-draft C++ section with the exact empty `ChattingColorPane::~ChattingColorPane()` body above.

### Class pages

Placement context: method inventory rows for the relevant destructor children.

Recommended row/text updates:

```markdown
| [UID:0002F5][0x00480860-0x00480889.ChattingModifyHeightPaneDestructor](by-memory/0x00480860-0x00480889.ChattingModifyHeightPaneDestructor.md) | `ChattingModifyHeightPane::~ChattingModifyHeightPane()` | Ordinary source destructor; binary restores three class vtables, clears `g_pChattingModifyHeightPane`, and compiler-chains to ordinary `Pane::~Pane()`. Source body is `g_pChattingModifyHeightPane = NULL;`; scalar deleting wrapper lives in [UID:0002GI]. |
| [UID:0002FB][0x00480ca0-0x00480cc9.ChattingVarietyPaneDestructor](by-memory/0x00480ca0-0x00480cc9.ChattingVarietyPaneDestructor.md) | `ChattingVarietyPane::~ChattingVarietyPane()` | Ordinary source destructor; binary restores three class vtables, clears `g_pChattingVarietyPane`, and compiler-chains to ordinary `Pane::~Pane()`. Source body is `g_pChattingVarietyPane = NULL;`; scalar deleting wrapper lives in [UID:0002GI]. |
| [UID:0002FI][0x00481150-0x004811bc.ChattingVarietySelectPaneDestructor](by-memory/0x00481150-0x004811bc.ChattingVarietySelectPaneDestructor.md) | `ChattingVarietySelectPane::~ChattingVarietySelectPane()` | Ordinary selector destructor; explicitly calls inherited `Pane::RemoveFromLayer()` and `Pane::UnregisterEventHandler()`, clears `g_pChattingVarietySelectPane`, and then compiler-chains to ordinary `Pane::~Pane()`. Scalar deleting wrapper lives in [UID:0002GI]. |
| [UID:0002FY][0x00482b10-0x00482b2f.ChattingColorPaneDestructor](by-memory/0x00482b10-0x00482b2f.ChattingColorPaneDestructor.md) | `ChattingColorPane::~ChattingColorPane()` | Ordinary color-dialog destructor with an empty source body; binary restores three class vtables and compiler-chains to `DialogPane::~DialogPane()` at `0x0049d9f0`. No color-pane singleton clear exists. |
```

### [UID:0000I5] `Chatting` file page

Placement context: `Proposed Contents` rows for the four classes and a new `Boundary And Data Notes` bullet near the accepted [UID:0002F2] note.

Recommended addition:

```markdown
- 2026-06-18 B005 destructor-cluster source-quality execution resolves [UID:0002F5], [UID:0002FB], [UID:0002FI], and [UID:0002FY]. The height and variety pane destructors are ordinary `Pane`-derived destructors whose only source-authored statements clear `g_pChattingModifyHeightPane` and `g_pChattingVarietyPane`. The selector destructor additionally calls inherited `Pane::RemoveFromLayer()` and `Pane::UnregisterEventHandler()` before clearing `g_pChattingVarietySelectPane`. The color-pane destructor has an empty source body and implicitly chains to `DialogPane::~DialogPane()`; it should now be directly class-owned by [UID:00001T], with `social/Chatting.cpp` retained as the source-file route.
```

### [UID:0002GI] `ChattingUiDestructorGlueFamily`

Placement context: replace rows in the `Contents` table.

```markdown
| `0x00483b40-0x00483b95` | scalar deleting destructor | Compiler-generated wrapper for `ChattingColorPane::~ChattingColorPane`; resets `ChattingColorPane` vtables, calls inherited `DialogPane::~DialogPane()` at `0x0049d9f0`, and optionally deletes. Source-authored semantics live in [UID:0002FY] as an empty destructor body. |
| `0x00483c00-0x00483c5f` | scalar deleting destructor | Compiler-generated wrapper for `ChattingModifyHeightPane::~ChattingModifyHeightPane`; resets vtables, clears `g_pChattingModifyHeightPane` at `0x0067add4`, calls ordinary `Pane::~Pane()` at `0x00544580`, and optionally deletes. Source-authored semantics live in [UID:0002F5]. |
| `0x00483d50-0x00483daf` | scalar deleting destructor | Compiler-generated wrapper for `ChattingVarietyPane::~ChattingVarietyPane`; resets vtables, clears `g_pChattingVarietyPane` at `0x0067add8`, calls ordinary `Pane::~Pane()` at `0x00544580`, and optionally deletes. Source-authored semantics live in [UID:0002FB]. |
| `0x00483db0-0x00483e5d` | scalar deleting destructor | Compiler-generated wrapper for `ChattingVarietySelectPane::~ChattingVarietySelectPane`; resets vtables, calls inherited `Pane::RemoveFromLayer()` at `0x00544ce0` and `Pane::UnregisterEventHandler()` at `0x00544d70`, clears `g_pChattingVarietySelectPane` at `0x0067addc`, calls ordinary `Pane::~Pane()` at `0x00544580`, and optionally deletes. Source-authored semantics live in [UID:0002FI]. |
```

No `ChattingVtableData` row changes are required; current rows already identify the correct vtable bases, primary first-slot scalar deleting destructors, and constructor/destructor store refs.

No singleton global score changes are required. Optional evidence-note additions may record that [UID:0002F5], [UID:0002FB], and [UID:0002FI] now carry formal destructor C++ using the existing global names.

## Coverage Row Recommendation

Do not edit `by-memory/-coverage-report.md` directly. Replace these rows in their current ChattingUI address-order placement. No padding row changes are needed.

Replace the [UID:0002F5] row between the `0x0048085e-0x00480860` padding row and the `0x00480889-0x00480890` padding row with:

```markdown
        - [UID:0002F5][0x00480860-0x00480889.ChattingModifyHeightPaneDestructor](by-memory/0x00480860-0x00480889.ChattingModifyHeightPaneDestructor.md) 0x00480860-0x00480889 | destructor body | ChattingModifyHeightPane::~ChattingModifyHeightPane : reconstructable : 88% : strong : B005 source-quality pass resolves the ordinary source destructor body and base-helper name: exact `0x00480860-0x00480889` function, surrounding `0xcc` padding, three `ChattingModifyHeightPane` vtable restores, unconditional `g_pChattingModifyHeightPane` clear at `0x0067add4`, tail jump to ordinary `Pane::~Pane()` at `0x00544580`, no direct inbound xrefs to the compact body, scalar deleting destructor mirror at `0x00483c00` reached through adjustor thunks/vtable slot `0x00614e18`, class owner/emitter route through [UID:00001W]/[UID:0000I5], and first-draft C++ readiness as `g_pChattingModifyHeightPane = NULL;` with base destruction implicit.
```

Replace the [UID:0002FB] row between the `0x00480c9f-0x00480ca0` padding row and the `0x00480cc9-0x00480cd0` padding row with:

```markdown
        - [UID:0002FB][0x00480ca0-0x00480cc9.ChattingVarietyPaneDestructor](by-memory/0x00480ca0-0x00480cc9.ChattingVarietyPaneDestructor.md) 0x00480ca0-0x00480cc9 | destructor body | ChattingVarietyPane::~ChattingVarietyPane : reconstructable : 88% : strong : B005 source-quality pass resolves the ordinary source destructor body and base-helper name: exact `0x00480ca0-0x00480cc9` function, surrounding `0xcc` padding, three `ChattingVarietyPane` vtable restores, unconditional `g_pChattingVarietyPane` clear at `0x0067add8`, tail jump to ordinary `Pane::~Pane()` at `0x00544580`, no direct inbound xrefs to the compact body, scalar deleting destructor mirror at `0x00483d50` reached through adjustor thunks/vtable slot `0x00614ea0`, class owner/emitter route through [UID:00001Y]/[UID:0000I5], and first-draft C++ readiness as `g_pChattingVarietyPane = NULL;` with base destruction implicit.
```

Replace the [UID:0002FI] row between the `0x00481146-0x00481150` padding row and the `0x004811bc-0x004811c0` padding row with:

```markdown
        - [UID:0002FI][0x00481150-0x004811bc.ChattingVarietySelectPaneDestructor](by-memory/0x00481150-0x004811bc.ChattingVarietySelectPaneDestructor.md) 0x00481150-0x004811bc | destructor body | ChattingVarietySelectPane::~ChattingVarietySelectPane : reconstructable : 88% : strong : B005 source-quality pass resolves the ordinary selector destructor body, inherited cleanup helper names, and base-helper name: exact `0x00481150-0x004811bc` function, surrounding `0xcc` padding, three `ChattingVarietySelectPane` vtable restores, explicit inherited `Pane::RemoveFromLayer()` at `0x00544ce0` and `Pane::UnregisterEventHandler()` at `0x00544d70`, unconditional `g_pChattingVarietySelectPane` clear at `0x0067addc`, call to ordinary `Pane::~Pane()` at `0x00544580`, no direct inbound xrefs to the ordinary body, scalar deleting destructor mirror at `0x00483db0` reached through adjustor thunks/vtable slot `0x00614f2c`, class owner/emitter route through [UID:00001Z]/[UID:0000I5], and first-draft C++ readiness with base destruction implicit.
```

Replace the [UID:0002FY] row between the `0x00482b01-0x00482b10` padding row and the `0x00482b2f-0x00482b30` padding row with:

```markdown
        - [UID:0002FY][0x00482b10-0x00482b2f.ChattingColorPaneDestructor](by-memory/0x00482b10-0x00482b2f.ChattingColorPaneDestructor.md) 0x00482b10-0x00482b2f | destructor body | ChattingColorPane::~ChattingColorPane : reconstructable : 87% : strong : B005 source-quality pass resolves the ordinary color-dialog destructor and stale owner/helper blockers: exact `0x00482b10-0x00482b2f` function, surrounding `0xcc` padding, three `ChattingColorPane` vtable restores, no singleton/global clear, tail jump to inherited `DialogPane::~DialogPane()` / dialog cleanup at `0x0049d9f0`, no direct inbound xrefs to the ordinary body, scalar deleting destructor mirror at `0x00483b40` reached through adjustor thunks/vtable slot `0x00615048`, corrected class owner/emitter route through [UID:00001T]/[UID:0000I5] rather than stale file-owned metadata, and first-draft C++ readiness as an empty destructor body with DialogPane base destruction implicit.
```

## Heuristic / Inference Reanalysis And Validation

### Issue: Exact half-open ranges, padding, and split policy

Evidence checked:

- Target pages for all four ranges.
- Current coverage rows.
- Exported IDA function sizes: `0x00480860` size 41, `0x00480ca0` size 41, `0x00481150` size 108, `0x00482b10` size 31.
- IDA listing lines around all four ordinary bodies and adjacent align directives.
- Neighbor constructor and next-method pages.

Rejected alternatives:

- Extend any target into preceding constructor padding or following handler/button-response code: rejected by `align 10h` and next function starts.
- Split any target further: rejected because each body is one compact destructor unit.
- Merge into `ChattingUiDestructorGlueFamily`: rejected because ordinary destructor bodies are source-equivalent class methods; the glue family only records scalar/adjustor support.

Final inference and impact:

- Keep exact half-open ranges as assigned.
- No split/range metadata change.
- Range evidence supports score increases.

### Issue: No direct caller/xref status versus reconstructability

Evidence checked:

- Exported IDA records report no direct callers/xrefs to ordinary bodies `0x00480860`, `0x00480ca0`, `0x00481150`, and `0x00482b10`.
- Scalar deleting wrappers are reached from vtable primary slots and secondary/tertiary adjustor thunks.
- `ChattingVtableData` rows record class vtable bases and scalar first slots.
- [UID:0002F2] accepted report established the same ordinary-body/no-direct-xref pattern for a sibling destructor.

Rejected alternatives:

- Non-reconstructable/no-emitter because the compact bodies lack direct callers: rejected. These are ordinary destructor bodies with source-equivalent effects and class vtable/scalar routes.
- Treat scalar wrappers as source-authored bodies: rejected as compiler-generated deleting-destructor glue.

Final inference and impact:

- No-direct-body-xref is a confidence caveat but not a C++ blocker.
- Keep all four reconstructable.

### Issue: Source-facing destructor identities

Evidence checked:

- Vtable stores, RTTI/COL/vtable rows, class pages, constructor/destructor sibling clusters, and generated `Chatting.cpp`.
- Ghidra/IDA generated names and their pollution patterns.

Rejected alternatives:

- `sub_480860`, `sub_480CA0`, `sub_481150`, `sub_482B10`: rejected as raw names.
- Scalar deleting wrapper names as the formal source body: rejected because wrappers include delete flags and ABI cleanup.
- `boost::exception::~exception` / `TransferReplyAlert::~TransferReplyAlert` for [UID:0002FY]: rejected by `ChattingColorPane` vtable stores and DialogPane body evidence.

Final inference and impact:

- Use `ChattingModifyHeightPane::~ChattingModifyHeightPane()`, `ChattingVarietyPane::~ChattingVarietyPane()`, `ChattingVarietySelectPane::~ChattingVarietySelectPane()`, and `ChattingColorPane::~ChattingColorPane()`.
- Formal C++ should be populated for all four.

### Issue: Source body contents and singleton clears

Evidence checked:

- Ordinary body IDA listing and exported decompilation.
- Scalar deleting wrapper mirrors.
- Singleton global pages and storage pages.
- `UiChatClanSingletonSlots` cluster.

Rejected alternatives:

- Add vtable stores to C++: rejected as compiler output.
- Add explicit `Pane::~Pane()` or `DialogPane::~DialogPane()` calls: rejected as implicit base destructor calls.
- Guard singleton clears with `if (g_p... == this)`: rejected because no compare exists.
- Clear a `g_pChattingColorPane`: rejected because no such clear appears in [UID:0002FY] or the singleton cluster.

Final inference and impact:

- [UID:0002F5] body is `g_pChattingModifyHeightPane = NULL;`.
- [UID:0002FB] body is `g_pChattingVarietyPane = NULL;`.
- [UID:0002FI] body is `RemoveFromLayer(); UnregisterEventHandler(); g_pChattingVarietySelectPane = NULL;`.
- [UID:0002FY] body is empty.

### Issue: Base/helper names

Evidence checked:

- `PaneCore`, `PaneVtables`, `DialogPane`, `DialogPaneVtables`, `g_activeDialogCount`, exported IDA records for `0x00544580`, `0x00544ce0`, `0x00544d70`, and `0x0049d9f0`.
- Accepted [UID:0002F2] report and current `ChattingUiDestructorGlueFamily`.

Rejected alternatives:

- Leave helpers as `sub_544580`, `sub_544CE0`, `sub_544D70`, or address-only names: rejected because support docs resolve them.
- Preserve generated `TextButtonExControlPane` / `boost::exception` / `TransferReplyAlert` labels: rejected as generated pollution.
- Treat `0x00544ce0`/`0x00544d70` as selector-private helpers: rejected by broad Pane ownership and vtable slot docs.

Final inference and impact:

- Use `Pane::~Pane()`, `Pane::RemoveFromLayer()`, `Pane::UnregisterEventHandler()`, and `DialogPane::~DialogPane()`.
- These resolved names remove all target-specific final-C++ blockers.

### Issue: Owner/source placement and [UID:0002FY] stale file owner

Evidence checked:

- Class pages and coverage rows.
- [UID:0000I5] `Chatting` file source-route notes.
- `ChattingColorPane` constructor [UID:0002FX], button handler [UID:0002FZ], local raw helper docs, and generated `Chatting.cpp`.
- `ChattingVtableData` row for `ChattingColorPane`.

Rejected alternatives:

- Keep [UID:0002FY] directly file-owned by [UID:0000I5]: rejected as stale now that [UID:00001T] is above gate and owns the color-dialog method cluster.
- Move to a new `ChatColorDialog.cpp`: rejected for current metadata because [UID:0000I5] explicitly retains color-dialog classes in `social/Chatting.cpp` until a broader source split is justified.
- Assign [UID:0002FY] to `DialogPane`: rejected because `DialogPane` owns only the base destructor callee.

Final inference and impact:

- [UID:0002FY] should be rerouted to [UID:00001T] while retaining [UID:0000I5] as source file route.
- Other target owners stay unchanged.

### Issue: C++ readiness and score cap

Evidence checked:

- Current code-entry rule in `Supervisor.md`: reconstructable, nonblank emitter, and combined score above 85.
- Current stats rows `84/88` for all four targets.
- Existing generated `Chatting.cpp` output showing [UID:0002F2] and [UID:0002FX] already emitted through this source route.

Rejected alternatives:

- Withhold C++ because helper names were historically unresolved: rejected because current Pane/DialogPane docs resolve them.
- Withhold [UID:0002FY] because the source body is empty: rejected because an empty destructor is the correct source-facing representation for this exact binary body.
- Raise above `90` or toward final-audit scores: rejected because live MCP was unavailable and broader class/file final-source polish remains.

Final inference and impact:

- Populate all four first-draft C++ blocks.
- Recommended target scores are conservative but above the low-score queue gate.

## Remaining Risks Or Blockers

No target-specific blocker remains for owner/emitter routing or first-draft C++.

Residual non-blocking risks:

- Live IDA MCP was unavailable in this session; exported IDA artifacts and current docs were used instead.
- Original source file split between `social/Chatting.cpp` and a possible future `social/ChatColorDialog.cpp` remains a broader project-structure question. Current metadata should not move to a new file.
- Broader class pages still have unrelated method/helper/final-layout issues. Those do not block these destructor bodies.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B005/research/0002F5-0002FB-0002FI-0002FY-ChattingDestructorCluster-source-quality.md`

No by-* docs, generated files, or `by-memory/-coverage-report.md` were edited.

## Validation Notes

- Report path should exist after this write.
- Recommendations are claim-by-claim incorporable under Rule 26.
- Coverage replacement text is provided exactly above for supervisor-owned application.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0002F5-0002FB-0002FI-0002FY-ChattingDestructorCluster-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"0002F5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
