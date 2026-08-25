** TARGET-REPORT-UID:0002F2 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002F2] ChattingBackPaneDestructor Source-Quality Report

Report-only B005 pass for `by-memory/0x004806a0-0x004806c9.ChattingBackPaneDestructor.md`.

## Final Recommendation

Raise [UID:0002F2] from `84/88` to `88/90`, keep `RECONSTRUCTABLE:TRUE`, keep `CANONICAL_OWNER:00001R`, keep `EMITTER_UIDS:00001R`, and populate the formal C++ body as the ordinary source destructor:

```cpp
ChattingBackPane::~ChattingBackPane()
{
    g_pChattingBackPane = NULL;
}
```

This target should not remain blocked on source-level destructor spelling or the base helper name. The best defensible source identity is `ChattingBackPane::~ChattingBackPane()`. The tail target `0x00544580` is no longer an unresolved address-named helper: current PaneCore, Pane class/file, and Pane vtable docs identify `0x00544580-0x00544687` as the ordinary non-deleting base `Pane::~Pane()` body. In source C++, the base destructor call is implicit after the derived destructor body and should not be hand-written in this target's formal block.

No split, merge, owner change, or direct edit to `by-memory/-coverage-report.md` is recommended. Supervisor should apply target/support/coverage text below.

## Scope And Evidence Rechecked

Read active instructions:

- `tools/leaser/Agents/Agent-B005/goal.md`
- `tools/leaser/Agents/Agent-B005/notes.md`
- `tools/leaser/Agents/Supervisor.md`
- `by-structure.md`
- `inference_research.md`

Target and support docs rechecked:

- [UID:0002F2] `by-memory/0x004806a0-0x004806c9.ChattingBackPaneDestructor.md`
- [UID:00001R] `by-class/ChattingBackPane.md`
- [UID:0000I5] `by-file/Chatting.md`
- [UID:000104] `by-memory/0x0047efb0-0x00483ef7.ChattingUI.md`
- [UID:0002F1] `by-memory/0x00480640-0x00480694.ChattingBackPaneConstructor.md`
- [UID:0002GI] `by-memory/0x004839c0-0x00483ef7.ChattingUiDestructorGlueFamily.md`
- [UID:0003AT] `by-memory/0x00614cdc-0x00615284.ChattingVtableData.md`
- [UID:0002X0] `by-memory/0x0067add0-0x0067add4.g_pChattingBackPane.md`
- [UID:0002WZ] `by-global/g_pChattingBackPane.md`
- [UID:0002B5] `by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md`
- [UID:0001EA] `by-memory/0x00544460-0x00545086.PaneCore.md`
- [UID:0000A2] `by-class/Pane.md`
- [UID:0000MC] `by-file/Pane.md`
- [UID:0003CA] `by-memory/0x006219e8-0x00621a6c.PaneVtableData.md`
- Sibling destructor pages for `ChattingModifyHeightPane`, `ChattingVarietyPane`, and `ChattingHandlePane`.

Local IDA/export evidence rechecked:

- `resources/exported_data/functions/0x004806a0.json`
- `resources/exported_data/functions/0x00483aa0.json`
- `resources/exported_data/functions/0x00544580.json`
- `hooks-generation/tests/function_data/ida/0x004806a0.json`
- `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.lst`
- `auto-generated/NexusTK/social/Chatting.cpp`

## Exact Range, Boundary, And Body

The half-open range `0x004806a0-0x004806c9` is correct.

Evidence:

- The target page records IDA `lookup_funcs 0x004806a0` size `0x29`, with no function at `0x00480694` or `0x004806c9` and the next modeled function at `0x004806d0`.
- The IDA listing shows the predecessor constructor ending with `sub_480640 endp` at `0x00480693`, followed by `align 10h` at `0x00480694`.
- The same listing shows `sub_4806A0 proc near` at `0x004806a0`, stores at `0x004806a0`, `0x004806a6`, `0x004806b0`, singleton clear at `0x004806ba`, and `jmp sub_544580` at `0x004806c4`.
- The function end is represented at the tail jump line, and the next `align 10h` starts at `0x004806c9`, proving the exclusive end.
- The next function `sub_4806D0` begins at `0x004806d0`, matching the target and aggregate pages.

Adjacent padding is correct:

- `0x00480694-0x004806a0`: twelve `0xcc` bytes after [UID:0002F1] constructor.
- `0x004806c9-0x004806d0`: seven `0xcc` bytes before [UID:000105] viewport helper.

IDA/export decompilation for `0x004806a0` is:

```cpp
void __thiscall sub_4806A0(_DWORD *this)
{
  *this = &ChattingBackPane::`vftable';
  this[40] = &ChattingBackPane::`vftable';
  this[41] = &ChattingBackPane::`vftable';
  dword_67ADD0 = 0;
  sub_544580(this);
}
```

`resources/exported_data/functions/0x004806a0.json` confirms:

- IDA name `sub_4806A0`.
- IDA size `41`.
- Signature `void __thiscall(_DWORD *this)`.
- `num_callers.ida = 0`.
- `xrefs_to.ida = []`.
- One outbound xref, `JUMP_NEAR` to `0x00544580` / `sub_544580`.

## Vtable And Scalar-Deleting Destructor Route

The three target-body vtable stores are exact and class-owned:

| Instruction site | Receiver offset | Stored table |
| --- | ---: | --- |
| `0x004806a0` | `+0x00` | `0x00614d90`, primary `ChattingBackPane` vtable |
| `0x004806a6` | `+0xa0` | `0x00614ddc`, secondary view |
| `0x004806b0` | `+0xa4` | `0x00614e0c`, tertiary view |

`ChattingVtableData` confirms:

- `ChattingBackPane` primary table at `0x00614d90`, 18 slots.
- Secondary table at `0x00614ddc`, 11 slots.
- Tertiary table at `0x00614e0c`, 2 slots.
- Complete object locators immediately before the three table bases.
- Primary first slot `0x00483aa0`, not `0x004806a0`.
- Store/xref sites include the constructor `0x0048066b`, ordinary destructor body `0x004806a0`, and scalar wrapper `0x00483aa6`.

The IDA listing adds RTTI inheritance evidence:

- `0x00614d8c`, `0x00614dd8`, and `0x00614e08` are the three `ChattingBackPane` COL dwords.
- `0x00614d90` first slot points to `sub_483AA0`.
- `0x00614ddc` first slot points to secondary adjustor `sub_4839EB`.
- `0x00614e0c` first slot points to tertiary adjustor `sub_4839F6`.
- RTTI records show `Singleton<class ChattingBackPane>` at offset `248` (`0xf8`), matching the constructor allocation/derived boundary and the singleton storage model.

The scalar deleting destructor mirror at `0x00483aa0` is confirmed:

- `resources/exported_data/functions/0x00483aa0.json` reports Ghidra/IDA size `95`, IDA signature `_DWORD *__thiscall(_DWORD *Block, char)`.
- IDA decompilation repeats the same three `ChattingBackPane` vtable writes, clears `dword_67ADD0`, calls `sub_544580`, and conditionally calls `sub_4F4AC0` based on deleting flags.
- IDA xrefs to `0x00483aa0` are two adjustor jumps at `0x004839f1` and `0x004839fc`, plus data reference at `0x00614d90`.
- The IDA listing shows the mirror stores at `0x00483aa6`, `0x00483aac`, `0x00483ab6`, singleton clear at `0x00483ac0`, call to `sub_544580` at `0x00483aca`, optional delete at `0x00483adb -> sub_4F4AC0`, and the guarded flag-4 path.

Inference:

- `0x004806a0` is the ordinary non-deleting destructor body for source `ChattingBackPane::~ChattingBackPane()`.
- `0x00483aa0` is compiler-generated scalar deleting destructor output. It should remain documented in `ChattingUiDestructorGlueFamily`, not hand-authored as source.
- The lack of direct code callers to `0x004806a0` is not a no-owner signal. It is a common MSVC destructor pattern here: ordinary destructor bodies are retained for cleanup/unwind or non-deleting paths while primary vtables route through scalar deleting destructors and adjustor thunks.

## Singleton Slot And Source Global Name

`0x0067add0` is strongly resolved as `g_pChattingBackPane`.

Evidence:

- [UID:0002X0] exact storage page says static image value is zero-filled virtual `.data`, and the saved label is `g_pChattingBackPane`.
- [UID:0002WZ] global page gives type hypothesis `ChattingBackPane *`, owner [UID:0000I5] `Chatting`, and current IDA label `g_pChattingBackPane`.
- Current xref set is exactly eight direct xrefs:
  - Constructor publish at `0x00480664`.
  - Ordinary destructor clear at `0x004806ba`.
  - Scalar deleting destructor clear at `0x00483ac0`.
  - Read paths at `0x00480923`, `0x00480af9`, `0x00481e07`, `0x00481e4f`, and `0x00504961`.
- The broader singleton-slot page records `0x0067add0` as the chat back pane slot, written by `sub_480640`, cleared by `sub_4806A0` and `sub_483AA0`, and read by `sub_480890`, `sub_480AD0`, `sub_481D60`, and `sub_5047F0`.

Rejected alternatives:

- `dword_67ADD0` should not remain the source-facing name. It is the old generated/raw label. Current global docs and saved labels resolve the source-facing name as `g_pChattingBackPane`.
- A guarded clear such as `if (g_pChattingBackPane == this)` is not supported by the target bytes. The ordinary destructor emits an unconditional zero store at `0x004806ba`, and the scalar deleting wrapper emits the same unconditional zero store at `0x00483ac0`.

## Base Destructor Helper `0x00544580`

Best source-quality name/role: ordinary base `Pane::~Pane()` body at `0x00544580-0x00544687`.

Evidence:

- [UID:0001EA] `PaneCore` now states: reconstruct ordinary `virtual Pane::~Pane()` from `0x00544580-0x00544687`; regenerate the adjustor thunks and scalar deleting destructor from class/destructor declarations.
- `PaneCore` function map identifies `0x00544580-0x00544687` as `Pane::~Pane` ordinary destructor, restoring the three Pane vtables, unregistering focus/dispatcher/layer state, destroying `+0xdc` and `+0xc4` regions, tearing down handler subobjects, and chaining to `GrafPort` cleanup.
- [UID:0000A2] `Pane` class page method-family table says ordinary `Pane::~Pane` at `0x00544580-0x00544687` releases Pane-owned dispatcher/layer/region/handler state and chains to `GrafPort` cleanup; older `0x004b8d20` references are `GrafPort` cleanup, not Pane.
- [UID:0000MC] `Pane` file page repeats the same source route and labels old `TextButtonExControlPane` ownership as generated-owner pollution.
- [UID:0003CA] `PaneVtableData` confirms Pane constructor/destructor/scalar stores to vtable bases, with destructor/teardown xrefs at `0x005445b4`, `0x005445ba`, and `0x005445c0`.
- `resources/exported_data/functions/0x00544580.json` still shows Ghidra/old generated label pollution as `~TextButtonExControlPane`, but its IDA body writes `Pane` vtables and then calls inherited cleanup. The current PaneCore execution supersedes that generated label.

Rejected alternatives:

- `TextButtonExControlPane::~TextButtonExControlPane`: rejected as generated type propagation / owner pollution. The body writes `Pane` vtables, operates on Pane layout offsets, and is documented by PaneCore as the shared base destructor.
- `BasePane::~BasePane` or "shared base pane teardown helper": acceptable descriptive fallback in older docs, but no longer best quality. Current source-facing name should be `Pane::~Pane()`.
- `GrafPort::~GrafPort`: rejected because `0x004b8d20-0x004b8dc3` is the GrafPort cleanup dependency called by Pane teardown, not this function.

Effect on target source:

- Do not write `Pane::~Pane()` explicitly in [UID:0002F2]'s formal C++ block. A C++ derived destructor implicitly invokes base destructors after the destructor body. The binary tail jump at `0x004806c4` is the compiler's implementation of that implicit base destructor call after the only source statement has run.

## Ownership And Source Placement Ranking

Accepted owner/emitter:

1. [UID:00001R] `ChattingBackPane`: direct semantic owner. Evidence is exact constructor/destructor/update child cluster, matching `ChattingBackPane` vtable stores, RTTI/COL records, singleton lifecycle, current class score `87/90`, and generated route through [UID:0000I5].
2. [UID:0000I5] `Chatting` file: source placement/emitter parent for the class. The file page routes the `Chatting*` UI classes to `social/Chatting.cpp`; `auto-generated/NexusTK/social/Chatting.cpp` already contains `ChattingBackPane::SetChatViewportLineCount` and uses `g_pChattingBackPane`.

Rejected or lower-ranked:

- `ChattingUI` aggregate [UID:000104]: correct physical neighborhood/index, but too broad for source emission. The exact class child is the source owner.
- `ChattingUiDestructorGlueFamily` [UID:0002GI]: records scalar deleting destructor and adjustor glue; explicitly non-reconstructable/compiler generated. It is supporting evidence, not source owner.
- [UID:0000A2] `Pane` / [UID:0000MC] `Pane`: owns the base destructor callee at `0x00544580`, but not the derived singleton clear or ChattingBackPane vtable restores.
- `Chatting` file as direct target owner: correct source file route but less precise than class ownership under by-structure. Keep target `CANONICAL_OWNER:00001R`, emitted through class to file.
- `ChattingModifyHeightPane`, `ChattingHandlePane`, `ChattingVarietyPane`, or generic UI/core: rejected by receiver-specific vtables, `g_pChattingBackPane` slot, and `ChattingBackPane` RTTI.

## First-Draft C++ Recommendation

Populate [UID:0002F2]'s formal block with:

```cpp
ChattingBackPane::~ChattingBackPane()
{
    g_pChattingBackPane = NULL;
}
```

Rationale:

- This target clears the current C++ gate: `RECONSTRUCTABLE:TRUE`, nonblank emitter route, and `(84 + 88) / 2 = 86` already above the gate before this pass.
- The remaining target-specific blockers are resolved: destructor spelling is standard source `ChattingBackPane::~ChattingBackPane()`, the global name is `g_pChattingBackPane`, and `0x00544580` is base `Pane::~Pane()`.
- The formal C++ should model source-authored behavior, not ABI implementation. Vtable restores, scalar deleting wrapper, adjustor thunks, optional `operator delete`, and implicit base destructor call are compiler-generated from the destructor declaration and class layout.
- `NULL` is chosen as plausible pre-C++11 style. If project convention prefers `0`, `g_pChattingBackPane = 0;` is an equivalent source spelling, but the report recommends `NULL` for the exact formal block.

No-code proof is not applicable. There is no unresolved target-specific issue that justifies leaving the body blank.

## Score And Metadata Recommendation

Recommended target metadata:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:00001R
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00001R
```

Why `88/90`:

- Completion increases because the report resolves the two target open questions: source destructor spelling and base helper identity.
- Completion also increases because first-draft C++ is now safe and target-specific.
- Confidence increases to `90` because the range, no-direct-xref state, scalar route, vtable identities, global name, and base destructor identity are independently supported by target docs, current PaneCore docs, structured IDA exports, and IDA listing evidence.
- Do not raise higher than `90` confidence. The ordinary destructor has no direct inbound xrefs, and broader `ChattingBackPane` final declaration details such as update virtual name, alpha member name, and some inherited helper signatures remain descriptive/inferred at the class level. Those do not block this destructor body, but they cap final-source confidence.

## Support-Doc Update Recommendations

Apply these as supervisor-owned documentation updates. I did not edit by-* docs directly.

### Target Page [UID:0002F2]

Replace the two bullets under `## Open Questions` with a resolved section:

```markdown
## Resolved Source-Quality Questions

- Source-level destructor spelling is now resolved as `ChattingBackPane::~ChattingBackPane()`. The source-authored body clears `g_pChattingBackPane`; the three vtable restores, tail jump into `Pane::~Pane()`, and scalar deleting wrapper are compiler-generated destructor output.
- The shared base helper at `0x00544580-0x00544687` is the ordinary non-deleting `Pane::~Pane()` body, not `TextButtonExControlPane` owner material. This follows the 2026-06-18 PaneCore source-quality incorporation in [UID:0001EA], [UID:0000A2], [UID:0000MC], and [UID:0003CA]. In C++ it is the implicit base destructor call after the derived destructor body.
```

Update the `Behavior` sentence to:

```markdown
This ordinary `ChattingBackPane::~ChattingBackPane()` body restores the `ChattingBackPane` primary and secondary vtable pointers, clears the `g_pChattingBackPane` singleton slot at `0x0067add0`, and tail-jumps to the ordinary base `Pane::~Pane()` body at `0x00544580`.
```

Update `Reconstruction Notes` or add if absent:

````markdown
The source body should be populated as:

```cpp
ChattingBackPane::~ChattingBackPane()
{
    g_pChattingBackPane = NULL;
}
```

Do not hand-author the vtable stores, `Pane::~Pane()` call, scalar deleting destructor, adjustor thunks, or optional delete path. Those are generated from the class destructor and inheritance layout.
````

### ChattingBackPane Class Page [UID:00001R]

Update the method row for [UID:0002F2] to:

```markdown
| `~ChattingBackPane` | [UID:0002F2][0x004806a0-0x004806c9.ChattingBackPaneDestructor](by-memory/0x004806a0-0x004806c9.ChattingBackPaneDestructor.md) | Source-authored destructor body clears `g_pChattingBackPane`; compiler restores vtables and implicitly chains to `Pane::~Pane()` at `0x00544580`. |
```

Update the scalar row to:

```markdown
| `ScalarDeletingDestructor` | `0x00483aa0` | Compiler-generated deleting wrapper for `ChattingBackPane::~ChattingBackPane`; mirrors vtable restores and singleton clear, calls `Pane::~Pane()`, and optionally deletes. |
```

Replace the score-rationale blocker phrase:

Current phrase:

```text
source-quality names for the base constructor/destructor helpers, the `dword_67ADE0` chat-handle fields, the `+0x90` alpha member, and the original update virtual name are still unresolved
```

Recommended phrase:

```text
the base destructor helper is resolved as ordinary `Pane::~Pane()` at `0x00544580`; remaining class-level final-source caveats are the exact base constructor signature, `dword_67ADE0` chat-handle field names, the `+0x90` alpha member name, and the original update virtual name
```

No score change is required for the class page from this destructor-only pass, though a future class pass could consider whether the resolved base destructor helper warrants a small confidence update after the constructor/update blockers are handled.

### Chatting File Page [UID:0000I5]

Update the `ChattingBackPane` row role text to:

```markdown
| `ChattingBackPane` | `0x00480640-0x004807aa`, destructor body [UID:0002F2] and scalar wrapper at `0x00483aa0` | `class_ChattingBackPane.cpp` | Transparent chat background pane tied to chat handle visibility/mode state. The ordinary destructor source clears `g_pChattingBackPane`; compiler output restores vtables, chains to `Pane::~Pane()`, and emits the scalar deleting wrapper. Includes visible-line viewport method [UID:000105][0x004806d0-0x00480739.BackPaneViewportRectHelper](by-memory/0x004806d0-0x00480739.BackPaneViewportRectHelper.md). |
```

No file score change recommended.

### ChattingUI Aggregate [UID:000104]

Update the `0x004806a0-0x004806c9` contents row to:

```markdown
| [UID:0002F2][0x004806a0-0x004806c9.ChattingBackPaneDestructor](by-memory/0x004806a0-0x004806c9.ChattingBackPaneDestructor.md) | `ChattingBackPane::~ChattingBackPane` body | Source-authored body clears `g_pChattingBackPane`; compiler restores class vtables and tail-calls base `Pane::~Pane()` at `0x00544580`. |
```

No aggregate score change recommended.

### ChattingUiDestructorGlueFamily [UID:0002GI]

Update the `0x00483aa0-0x00483aff` contents row to:

```markdown
| `0x00483aa0-0x00483aff` | scalar deleting destructor | Compiler-generated wrapper for `ChattingBackPane::~ChattingBackPane`; resets vtables, clears `g_pChattingBackPane` at `0x0067add0`, calls ordinary `Pane::~Pane()` at `0x00544580`, and optionally deletes. Source-authored semantics live in [UID:0002F2]. |
```

Update the page confidence sentence:

Current phrase:

```text
medium for final source-level destructor/helper names
```

Recommended phrase:

```text
medium for a few sibling wrapper/source-name details; the shared base helper used by the ChattingBackPane wrapper is resolved as ordinary `Pane::~Pane()` at `0x00544580`
```

No score/metadata change recommended for the glue family.

### g_pChattingBackPane Pages [UID:0002X0]/[UID:0002WZ]

No metadata change required. Optional evidence-note addition:

```markdown
- B005 2026-06-18 source-quality pass on [UID:0002F2] confirms the ordinary `ChattingBackPane::~ChattingBackPane()` source body clears this slot unconditionally; the scalar deleting wrapper at `0x00483aa0` mirrors the same clear before generated delete handling.
```

### Sibling Chatting Destructor Pages

This target is not assigned to edit siblings, but the same stale base-helper open question appears in [UID:0002F5] `ChattingModifyHeightPaneDestructor` and [UID:0002FB] `ChattingVarietyPaneDestructor`. Recommended support-doc incorporation note for a future sweep:

```markdown
The shared base helper at `0x00544580` should now be named ordinary `Pane::~Pane()` per the executed PaneCore source-quality pass, not left as address-only or `TextButtonExControlPane` generated-owner material.
```

Do not update their scores from this report unless the supervisor chooses to apply a coordinated sibling cleanup.

## Coverage Row Recommendation

Do not edit `by-memory/-coverage-report.md` directly. Replace the existing [UID:0002F2] row at the current ChattingUI placement after the `0x00480694-0x004806a0` padding row and before the `0x004806c9-0x004806d0` padding row.

Current row:

```markdown
        - [UID:0002F2][0x004806a0-0x004806c9.ChattingBackPaneDestructor](by-memory/0x004806a0-0x004806c9.ChattingBackPaneDestructor.md) 0x004806a0-0x004806c9 | destructor body | ChattingBackPaneDestructor : reconstructable : 84% : strong : Live IDA confirms exact destructor body, vtable restores, `0x0067add0` singleton clear, base-destructor tail jump, mirrored scalar deleting wrapper, adjacent padding, and ChattingBackPane class parent attachment.
```

Replacement row:

```markdown
        - [UID:0002F2][0x004806a0-0x004806c9.ChattingBackPaneDestructor](by-memory/0x004806a0-0x004806c9.ChattingBackPaneDestructor.md) 0x004806a0-0x004806c9 | destructor body | ChattingBackPane::~ChattingBackPane : reconstructable : 88% : strong : B005 source-quality pass resolves the ordinary source destructor body and base-helper name: exact `0x004806a0-0x004806c9` function, surrounding `0xcc` padding, three `ChattingBackPane` vtable restores, unconditional `g_pChattingBackPane` clear at `0x0067add0`, tail jump to ordinary `Pane::~Pane` at `0x00544580`, no direct inbound xrefs to the compact body, scalar deleting destructor mirror at `0x00483aa0` reached through adjustor thunks/vtable slot `0x00614d90`, class owner/emitter route through [UID:00001R]/[UID:0000I5], and first-draft C++ readiness as `g_pChattingBackPane = NULL;` with base destruction implicit.
```

No padding row changes are needed.

## Heuristic / Inference Reanalysis And Validation

### Issue: Exact Half-Open Range And Padding

Evidence checked:

- Target page `lookup_funcs`, padding, and `get_bytes` notes.
- ChattingUI aggregate contents rows.
- IDA listing around `0x00480690-0x004806d0`.
- Constructor page [UID:0002F1] and viewport helper [UID:000105].

Rejected alternatives:

- Extending start backward to include `0x00480694-0x004806a0`: rejected because listing and docs show `align 10h` padding after constructor return at `0x00480693`.
- Extending end to `0x004806d0`: rejected because `0x004806c9-0x004806d0` is alignment and `sub_4806D0` begins at `0x004806d0`.
- Splitting inside the body: rejected because it is a single 41-byte function with one tail jump.

Final inference and impact:

- Keep exact half-open range `0x004806a0-0x004806c9`.
- No split/range metadata change.
- Range evidence supports score increase.

### Issue: No Direct Caller / Xref Status

Evidence checked:

- Target page says `callers 0x004806a0` and `xrefs_to 0x004806a0` report no direct references.
- `resources/exported_data/functions/0x004806a0.json` has `num_callers.ida = 0` and empty `xrefs_to.ida`.
- IDA listing search for `sub_4806A0` only found the function definition/end, not calls or jumps to it.
- Positive control: scalar wrapper at `0x00483aa0` has expected xrefs from adjustor thunks and vtable data.

Rejected alternatives:

- Treat no direct xrefs as no-owner/no-emitter: rejected. Vtable/RTTI/scalar-wrapper evidence is stronger and standard for this destructor family.
- Treat ordinary body as dead code: rejected because scalar wrapper mirrors it exactly, the constructor/destructor/global labels include it, and the class/aggregate pages document the pattern among sibling Chatting pane destructors.

Final inference and impact:

- No-direct-xref remains a real caveat, but it affects only confidence cap, not ownership or C++ readiness.
- Keep confidence at `90`, not higher.

### Issue: Source Destructor Identity

Evidence checked:

- IDA decompilation for `0x004806a0`: `void __thiscall sub_4806A0(_DWORD *this)`.
- Vtable stores to `ChattingBackPane` tables at `0x00614d90/0x00614ddc/0x00614e0c`.
- Scalar deleting destructor mirror at `0x00483aa0`.
- RTTI records for `ChattingBackPane` and `Singleton<class ChattingBackPane>`.
- ChattingBackPane class method table already lists this as `~ChattingBackPane` body.

Rejected alternatives:

- `ChattingBackPane::Destroy`, `ClearChattingBackPaneSingleton`, or a helper name: rejected because the function also restores class vtables and tail-calls the base destructor; it is destructor-shaped, not a standalone clear helper.
- Generated scalar destructor as the only source identity: rejected because `0x00483aa0` includes delete-flag ABI handling, while `0x004806a0` is the source ordinary destructor body.

Final inference and impact:

- Source identity is `ChattingBackPane::~ChattingBackPane()`.
- Formal C++ should be populated.
- Target score should rise above old `84` completion.

### Issue: Source Body Contents

Evidence checked:

- Ordinary body only has vtable stores, singleton clear, and base tail jump.
- Scalar wrapper has same clear plus delete-flag handling.
- `g_pChattingBackPane` docs show the clear is unconditional.

Rejected alternatives:

- Add explicit vtable writes to source C++: rejected as compiler output.
- Add explicit `Pane::~Pane()` source call: rejected as implicit base destructor call in C++.
- Add guard `if (g_pChattingBackPane == this)`: rejected because no compare exists in either ordinary or scalar body.

Final inference and impact:

- First-draft body is exactly `g_pChattingBackPane = NULL;`.
- No final-C++ blocker remains for this target.

### Issue: Base Helper Name `0x00544580`

Evidence checked:

- Executed PaneCore source-quality docs and report-derived incorporations.
- Pane class/file docs.
- Pane vtable data refs.
- IDA/export decompilation for `0x00544580`.
- Older generated labels and `wave3_data_issues.md` notes about `TextButtonExControlPane::~Pane` pollution.

Rejected alternatives:

- `TextButtonExControlPane::~TextButtonExControlPane`: rejected as generated type-propagation pollution.
- `GrafPort::~GrafPort`: rejected because `0x004b8d20` is GrafPort cleanup called by Pane, not this target.
- Address-only `sub_544580`: no longer necessary after PaneCore incorporation.

Final inference and impact:

- Name as ordinary `Pane::~Pane()`.
- This resolves one of the target's two open questions and improves C++ readiness.

### Issue: `g_pChattingBackPane` Source Name

Evidence checked:

- Exact memory page [UID:0002X0].
- Global page [UID:0002WZ].
- UiChatClanSingletonSlots table.
- Constructor/destructor/scalar clear xrefs.
- Generated `auto-generated/NexusTK/social/Chatting.cpp` uses `g_pChattingBackPane` in current emitted code.

Rejected alternatives:

- Keep `dword_67ADD0`: rejected as old raw label.
- Use `ChattingBackPane::s_instance` or template-specific singleton member name: RTTI confirms `Singleton<class ChattingBackPane>` base at offset `0xf8`, but docs and emitted support consistently expose global `g_pChattingBackPane`. No stronger original private static name is provable for this target.

Final inference and impact:

- Use `g_pChattingBackPane` in target formal C++.
- No score cap from global naming.

### Issue: Owner And Source Placement

Evidence checked:

- ChattingBackPane class page `87/90`, emitter [UID:0000I5].
- Chatting file page `social/Chatting.cpp` route.
- ChattingUI aggregate and destructor glue pages.
- Vtable/RTTI/source file generated output.

Rejected alternatives:

- Direct owner `Chatting` file: less precise than class owner under by-structure.
- Owner `Pane`: owns only the base callee.
- Owner `ChattingUiDestructorGlueFamily`: generated compiler material only.
- Owner `ChattingModifyHeightPane`/`ChattingHandlePane`/`ChattingVarietyPane`: rejected by vtable and singleton identity.
- No-owner/no-emitter: rejected because owner/emitter route is strong and already above gate.

Final inference and impact:

- Keep `CANONICAL_OWNER:00001R`, `EMITTER_UIDS:00001R`, with file route through [UID:0000I5].
- No reclassification recommended.

### Issue: Sibling Stale Open Questions

Evidence checked:

- Sibling `ChattingModifyHeightPaneDestructor` and `ChattingVarietyPaneDestructor` still leave source destructor spelling and base helper name as open.
- `ChattingHandlePaneDestructor` is already stronger at `86/90`, but still uses older approximate source pseudocode with explicit base call language.

Rejected alternatives:

- Update sibling docs directly in this report-only target pass: rejected by assignment scope.
- Use sibling stale wording to hold [UID:0002F2] down: rejected because current PaneCore evidence is newer and stronger.

Final inference and impact:

- Recommend support-note cleanup for siblings, but only [UID:0002F2] gets score/C++ recommendations here.

## Remaining Risks Or Blockers

No target-specific final-C++ blockers remain.

Residual caveats that cap confidence but do not block this target:

- `0x004806a0` has no direct inbound xrefs; class route is through scalar wrapper/vtable/RTTI and constructor/global evidence.
- Broader `ChattingBackPane` class still has unresolved final names for the base constructor signature, update virtual name, chat-handle fields, and `+0x90` alpha member. These are class-level concerns, not blockers for the destructor body because the destructor does not reference those fields.
- Sibling destructor pages still carry stale open questions. This target should be used as an incorporation seed for a future sibling cleanup.

## Changed Files

Report created:

- `tools/leaser/Agents/Agent-B005/research/0002F2-ChattingBackPaneDestructor-source-quality.md`

No by-* docs, generated files, or `by-memory/-coverage-report.md` were edited.

## Validation Notes

- Report path exists and is the only intended output of this B005 report-only pass.
- Recommendations are claim-by-claim incorporable under Rule 26.
- Coverage replacement text is provided exactly above for supervisor-owned application.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0002F2-ChattingBackPaneDestructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"0002F2"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
