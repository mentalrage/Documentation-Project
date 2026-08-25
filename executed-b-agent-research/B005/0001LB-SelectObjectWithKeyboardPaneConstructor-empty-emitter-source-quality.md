** TARGET-REPORT-UID:0001LB **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001LB SelectObjectWithKeyboardPaneConstructor Empty-Emitter Source-Quality Research

## Finalized Report / Current Recommendation

- Assignment: `B005-empty-emitter-report-0001LB-SelectObjectWithKeyboardPaneConstructor-20260629`.
- Current recommendation: promote [UID:0001LB] from a documented-but-blank constructor page to a source-ready first-draft `SelectObjectWithKeyboardPane::SelectObjectWithKeyboardPane()` emitter.
- Final disposition: source-authored constructor for [UID:0000CT][SelectObjectWithKeyboardPane](../../../../by-class/SelectObjectWithKeyboardPane.md), emitted through the existing class route to [UID:0000OH][TargetSelectionInputPanes](../../../../by-file/TargetSelectionInputPanes.md).
- Required action after supervisor acceptance: update the target by-memory page with current MCP proof, replace the stale `95/95` blank-C++ rationale, raise score to `88/91`, and insert the formal constructor C++ block below.
- Confidence: high for behavior, ownership, emitter route, bounds, padding, caller routes, source shape, and C++ readiness; not final-audit because exact original spellings for the singleton pointer and some shared Pane/global declarations remain descriptive.

## Target

- Target UID: `0001LB`
- Target path: `by-memory/0x005af5f0-0x005af6de.SelectObjectWithKeyboardPaneConstructor.md`
- Current generated empty marker: `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`, validator command `000000000595`, refreshed `2026-06-29T10:39:00-04:00`, line `867`.
- Current scores/metadata: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000CT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CT`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
- Current item summary: IDA-confirmed constructor with exact `0xee` boundary, two callers, base setup, singleton publish/clear, three vtable stores, prompt setup, saved-target validation/fallback, highlight update, saved-id write, setup helper call, mode-byte clear, and padding documented.

## Current Target State

The target page already has strong behavior evidence but keeps `RECONSTRUCTION_CPP CODE` blank because it still says the constructor is below the old `95/95` final-code threshold. That threshold is stale under the current `by-structure.md` rule: formal C++ may be added when `RECONSTRUCTABLE:TRUE`, a nonblank emitter route surfaces to a valid by-file source output, and `(COMPLETION + CONFIDENCE) / 2 > 85`. [UID:0001LB] currently averages `88`, routes through [UID:0000CT] to [UID:0000OH], and generated output confirms the only current cause of the UID0001LB empty marker is a blank formal C++ block.

Existing support docs already resolve the main dependency names:

- [UID:000077] / [UID:00035P] document `LineInputPane` and `LineInputPane::LineInputPane`.
- [UID:0002AB] documents `dword_69BF28` as `s_selectObjectTargetId` / `s_selectObjectSavedTargetId`.
- [UID:0002A9] emits `static bool s_selectObjectTargetModeActive = false;`.
- [UID:0002A2] documents `dword_69BF60` as the active `SelectObjectWithKeyboardPane` singleton slot, though it does not yet provide a final source-facing variable spelling.
- [UID:00028J] documents `dword_67A740` as `g_pBackPane`.
- `by-file/Pane.md`, [UID:0001KC] TotemFrame, [UID:0002KB] ParcelPane, and [UID:000310] ModelessDialogPane precedents support representing `0x00544d30` as the inherited Pane dispatcher/order helper. For this target the argument pattern is `SetPaneOrder(NULL, g_pBackPane)`.

## Evidence Checked

IDA MCP current pass used endpoint `http://127.0.0.1:13337/mcp`, active session `B006_0002F1_20260629`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. `server_health` returned `status:"ok"`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`. No IDA DB writes, renames, comments, type changes, patching, or process-management actions were made.

MCP calls and results used:

- `lookup_funcs` for `0x005af5f0`, `0x005af5ea`, `0x005af6de`, `0x005af6e0`, predecessor/successor/support starts, `0x004f1c00`, `0x004f20a0`, `0x00506970`, `0x0053b1b0`, and `0x00544d30`.
- `analyze_function 0x005af5f0`: prototype `_DWORD *__thiscall(_DWORD *this)`, size `238`, callers `sub_5A5BD0` and `sub_5AD450`, callees `sub_4F1C00`, `sub_4F20A0`, `sub_506970`, `sub_53B1B0`, and `sub_544D30`.
- `disasm 0x005af5f0`: exact instruction sites listed below.
- `xrefs_to` for `0x005af5f0`, `0x00630b10`, `0x0069bf60`, `0x0069bf28`, `0x0069bed9`, and vtable bases `0x0062f328`, `0x0062f378`, `0x0062f3a8`.
- `get_bytes`: six `0xcc` bytes at `0x005af5ea-0x005af5f0`, two `0xcc` bytes at `0x005af6de-0x005af6e0`, full target bytes at `0x005af5f0`, zero-initialized data windows at `0x0069bed8`, `0x0069bf20`, and `0x0069bf60`.
- `get_string 0x00630b10`: `Use arrow key to select target then press enter.`
- `insn_query 0x005a5f40-0x005a5f95`: caller-side allocation/open path around `0x005a5f75`.
- `disasm 0x005ad450`: caller-side allocation/open path around `0x005ad4e9`.

Local docs checked:

- Target page [UID:0001LB].
- Support pages named in `goal.md`: [UID:0000CT], [UID:0000OH], [UID:0001L9], [UID:0001LA], [UID:0001LC], [UID:0001LF], [UID:0001LG], [UID:0001LH], [UID:0002AB], [UID:0002A2], [UID:0002A9], prompt string [UID:0003J6], [UID:000077] `LineInputPane`, [UID:00035P] `LineInputPaneConstructor`, [UID:00035Q] `LineInputPaneCleanupBody`, and [UID:00028J] `g_pBackPane`.
- Generated output `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`.

Old report search terms used exactly as assigned: `0001LB`, `005af5f0`, `SelectObjectWithKeyboardPaneConstructor`, `SelectObjectWithKeyboardPane`, `TargetSelectionInputPanes`, `dword_69BF60`, `dword_69BF28`, `byte_69BED9`, `LineInputPane`, and `TargetSelectionModeFlags`.

Relevant old reports used only as leads:

- `executed-b-agent-research/B005/0001L8-TargetSelectionInputPanes-source-quality.md`: aggregate/index route, predecessor/successor padding, UID0001LB child inventory.
- `executed-b-agent-research/B005/0001LD-0001LE-SelectObjectWithKeyboardPaneInputHandlers-source-quality.md`: accepted `s_selectObjectTargetId`, `s_selectObjectTargetModeActive`, helper/source-route naming, and first-draft handler precedent.
- `executed-b-agent-research/B009/0002A9-TargetSelectionModeFlags-source-quality.md`: accepted mode-flag declaration and rejection of grouped struct/class-field alternatives.
- `executed-b-agent-research/B001/0002SA-ShoutInputPaneRawConstructor-source-quality.md` and `executed-b-agent-research/B006/0002S7-SayInputPaneRawConstructor-source-quality.md`: accepted constructor policy that old `95+` blank-code gates and unresolved final original spelling do not block formal first-draft C++ when the constructor source body is exact.
- `executed-b-agent-research/B015/00008K-ModelessDialogPane-class-source-quality.md`, `executed-b-agent-research/B005/0001KC-TotemFrame-source-quality.md`, and [UID:0002KB] support docs: source-facing precedent for `0x00544d30` as Pane interaction/order registration with provisional exact spelling.

No active unexecuted report already existed at the assigned B005 report path before this write.

## IDA MCP Facts

Function and boundary facts:

- `lookup_funcs 0x005af5f0` returns `sub_5AF5F0`, size `0xee`.
- `lookup_funcs 0x005af5ea` and `0x005af6de` return `Not a function`; `lookup_funcs 0x005af6e0` returns sibling destructor `sub_5AF6E0`, size `0x29`.
- `get_bytes 0x005af5ea size 6` returns six `0xcc` bytes after [UID:0001LA] before this constructor.
- `get_bytes 0x005af6de size 2` returns two `0xcc` bytes before [UID:0001LC].

Caller facts:

- `xrefs_to 0x005af5f0` returns exactly two code refs: `0x005a5f75` in `sub_5A5BD0` and `0x005ad4e9` in `sub_5AD450`.
- `insn_query 0x005a5f40-0x005a5f95` shows `sub_5A5BD0` checks `dword_69BF60`, allocates `0x108`, sets `ecx=eax`, calls `sub_5AF5F0` at `0x005a5f75`, returns handled, and otherwise dispatches to an existing active pane path at `0x005a5f81`.
- `disasm 0x005ad450` shows the second route allocates `0x108`, null-checks, sets `ecx=eax`, and calls `sub_5AF5F0` at `0x005ad4e9`.

Constructor instruction facts:

- `0x005af61c`: calls `sub_4F1C00` after pushing `0`, matching `LineInputPane(NULL)`.
- `0x005af637` / `0x005af63e`: writes `dword_69BF60` to `this` or `0`. The clear path is the compiler adjusted-pointer/cleanup guard; normal source shape is singleton publication.
- `0x005af648`: pushes prompt literal `0x00630b10`.
- `0x005af653`, `0x005af659`, `0x005af663`: installs vtable bases `0x0062f328`, `0x0062f378`, and `0x0062f3a8`.
- `0x005af66d`: calls `sub_4F20A0`, the accepted `LineInputPane::SetPromptText` path.
- `0x005af672-0x005af67e`: resolves `dword_69BF28` through `dword_67A764` / `sub_506970`.
- `0x005af689`, `0x005af692`: accepts the saved object only when byte `+0xf8 == 3` and byte `+0x1d0 == 0`.
- `0x005af69b`: falls back to `dword_67A748`, the local player/user-pane object route.
- `0x005af6a5`: calls `sub_53B1B0(target, 1)`, the accepted `LivingObjectPane::SetTargetHighlight(true)` helper.
- `0x005af6b0-0x005af6ba`: reads selected object id at `target+0xfc` and writes it to `dword_69BF28`.
- `0x005af6aa-0x005af6bf`: pushes `dword_67A740`, pushes `0`, sets `ecx=this`, calls `sub_544D30`; current support docs map this helper family to `Pane::SetPaneOrder` / dispatcher order registration, and [UID:00028J] maps `dword_67A740` to `g_pBackPane`.
- `0x005af6c4`: clears `byte_69BED9`, accepted as `s_selectObjectTargetModeActive`.

Data/xref facts:

- `xrefs_to 0x00630b10` returns one data ref, `0x005af648` in this constructor.
- `xrefs_to 0x0069bf60` returns six refs: constructor writes at `0x005af637`/`0x005af63e`, destructor clear at `0x005af6fa`, EH/unwind clear helper `0x005b7620`, scalar deleting destructor clear `0x005b7be0`, and UserPane gate read `0x005a5f3a`.
- `xrefs_to 0x0069bf28` returns 28 refs; this constructor owns refs at `0x005af672` and `0x005af6ba`, and sibling SelectObject handlers/helpers own the expected remaining refs.
- `xrefs_to 0x0069bed9` returns 9 refs; this constructor owns the clear at `0x005af6c4`.
- `xrefs_to` the three vtable bases returns constructor stores, destructor restores, and scalar deleting destructor restores only, matching class lifecycle ownership.

## Positive Evidence Summary

- The target is a normal modeled IDA function with two direct construction callers, not a raw no-route island.
- Both caller paths allocate `0x108` and call the constructor with `ecx` set to the allocated object.
- The body is a complete constructor-lowered sequence: base `LineInputPane(NULL)`, singleton publish, final derived vtable stores, prompt setup, initial target selection, highlight, saved-id write, Pane order registration, mode flag clear, and `this` return.
- Current support docs already provide enough source-facing names for every behavior-bearing operation except the active singleton pointer spelling. The singleton spelling can be represented as a descriptive file/module-scope name with an explicit caveat.
- The current score/emitter gate is satisfied and current generated output proves the blank formal C++ is the UID0001LB empty-emitter cause.

## Negative Evidence Summary

- The vtable stores, SEH frame, security cookie, `this == -0x108` adjusted-pointer guard, and `0xcc` padding are compiler output and must not appear as source statements.
- `LineInputPane` is a base dependency only; it is not the owner because the final vtable stores and singleton slot are `SelectObjectWithKeyboardPane`-specific.
- `MapPane`, `LivingObjectPane`, `BackPane`, `Pane`, `UserPane`, and `TargetSelectionSavedTargetGlobals` are dependencies/support state, not owners.
- The exact original names for `dword_69BF60` and the `0x00544d30` helper are not symbol-proven. That caps score below final-audit quality but does not justify blank C++ because current support docs and accepted constructor precedent allow role-level source names when the call shape is exact.
- The prompt string page remains a literal-data page; the constructor can use the exact wide literal without moving ownership to the string page.

## Heuristic / Inference Reanalysis And Validation

- Old blocker: "final source spelling remains below the `95/95` final-code threshold." Rejected as stale. Current `by-structure.md` code gate is combined-score/emitter based, and UID0001LB clears it.
- Singleton pointer name: infer `s_activeSelectObjectWithKeyboardPane` as a source-facing descriptive module-scope pointer for `dword_69BF60`. This is not original-proof. Evidence: constructor publish, destructor/scalar/EH clear refs, UserPane gate read, and [UID:0002A2] ownership. Rejected class member interpretation because all refs are absolute `.data`.
- Prompt expression: use the exact wide literal `L"Use arrow key to select target then press enter."` in the constructor C++ rather than inventing a constant name. A future prompt-constant normalization pass may factor it, but the current target has exact literal evidence and no original constant symbol.
- Target id name: use `s_selectObjectTargetId`; [UID:0002AB], [UID:0001LD]/[UID:0001LE], and generated handler output already use it. It is descriptive/inferred, not symbol-proven.
- Mode flag name: use `s_selectObjectTargetModeActive`; [UID:0002A9] already emits this declaration and rejects grouped-struct/class-member alternatives.
- Pane helper: use `SetPaneOrder(NULL, g_pBackPane)` because [UID:0002KB] uses the same source-facing helper shape, `by-file/Pane.md` documents `0x00544d30` as `Pane::SetPaneOrder` / dispatcher-order helper, and `dword_67A740` is [UID:00028J] `g_pBackPane`.
- Target validation fields: source code uses `ObjectType() == kLivingObjectType` and `!IsTargetingDisabled()` to match accepted generated ItemWho style for `+0xf8 == 3` and `+0x1d0 == 0`. The exact original enum/helper names remain inferred but already accepted in sibling target-selection output.

## Ranked Ownership Analysis

### 1. [UID:0000CT] SelectObjectWithKeyboardPane

- Evidence for: constructor callers allocate the class object size and call `sub_5AF5F0`; vtable stores are the three `SelectObjectWithKeyboardPane` views; singleton slot is the SelectObject active-pane slot; prompt, saved target id, mode byte, destructor, scalar destructor, key/mouse/object-list/clear/forward helpers all match this class.
- Evidence against: none material. Some dependencies live in LineInputPane/Pane/MapPane/UserPane, but none own the derived constructor.
- Decision: keep `CANONICAL_OWNER:0000CT` and `EMITTER_UIDS:0000CT`.

### 2. [UID:0000OH] TargetSelectionInputPanes file

- Evidence for: file owns the source route, static target ids, mode flags, singleton slots, and sibling target-selection classes.
- Evidence against: file is the route, not the narrow semantic owner for a class constructor.
- Decision: keep as indirect source file route through [UID:0000CT]; do not set direct owner/emitter to the file UID.

### 3. LineInputPane / Pane / MapPane / UserPane / BackPane

- Evidence for: constructor calls base constructor, prompt setter, Pane order helper, map lookup, highlight helper, local player fallback, and uses `g_pBackPane`.
- Evidence against: all are callees, globals, or context dependencies. None install the final vtables or own the class lifecycle.
- Decision: reject as owners; preserve as dependencies in target/support docs.

## Source Placement

Recommended source placement stays `NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` via [UID:0000OH], with direct semantic ownership under [UID:0000CT]. This matches existing generated source route, accepted SelectObject handler reports, static global ownership, prompt-string ownership, and the sibling TargetObject/ItemWho/SpellWho input-pane grouping. Do not route this constructor to `InputPanes.cpp`, `Pane.cpp`, `MapPane.cpp`, or `UserPane.cpp`.

## Range / Split / Padding / Reclassification Analysis

- Predecessor [UID:0001LA] ends at `0x005af5ea`.
- `0x005af5ea-0x005af5f0`: six `0xcc` bytes; keep as predecessor/successor padding evidence, not part of constructor C++.
- Target function: `0x005af5f0-0x005af6de`, modeled function `sub_5AF5F0`, size `0xee`, returns at `0x005af6dd`.
- `0x005af6de-0x005af6e0`: two `0xcc` bytes before [UID:0001LC].
- No split/new child is required. The constructor function is exact and source-authored. The two post-body SEH funclet addresses rendered by `disasm` around `0x60b0bf` are compiler EH support, not part of this page's half-open target range.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes.
- Reason: `RECONSTRUCTABLE:TRUE`, nonblank emitter `0000CT`, generated route to [UID:0000OH], current average score above `85`, current MCP evidence resolves behavior, and all named blockers have either accepted source-facing names or documented descriptive-name caveats.
- Third-party import directive: not applicable.

Exact formal target block after implementation:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
SelectObjectWithKeyboardPane::SelectObjectWithKeyboardPane()
    : LineInputPane(NULL)
{
    s_activeSelectObjectWithKeyboardPane = this;

    SetPromptText(L"Use arrow key to select target then press enter.");

    LivingObjectPane *target =
        g_activeMapPane->FindObjectPaneById(s_selectObjectTargetId);
    if (target == NULL ||
        target->ObjectType() != kLivingObjectType ||
        target->IsTargetingDisabled()) {
        target = g_pUserPane->GetLocalPlayerObject();
    }

    target->SetTargetHighlight(true);
    s_selectObjectTargetId = target->ObjectId();

    SetPaneOrder(NULL, g_pBackPane);
    s_selectObjectTargetModeActive = false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Why it preserves original behavior:

- `LineInputPane(NULL)` corresponds to `push 0; call sub_4F1C00`.
- Singleton publication corresponds to `dword_69BF60 = this`; the impossible adjusted-pointer null branch and unwind clear helper are compiler cleanup artifacts and should remain evidence prose, not source statements.
- `SetPromptText(...)` corresponds to the direct `0x00630b10` literal and `sub_4F20A0`.
- The target lookup/validation/fallback/highlight/id-store sequence matches `dword_69BF28`, `dword_67A764`, `sub_506970`, fields `+0xf8/+0x1d0/+0xfc`, `dword_67A748`, and `sub_53B1B0`.
- `SetPaneOrder(NULL, g_pBackPane)` matches `push dword_67A740; push 0; call sub_544D30`.
- `s_selectObjectTargetModeActive = false` matches the clear at `0x005af6c4`.

Why it matches plausible original mid-2000s source shape:

- It uses a base initializer, ordinary method calls, file/module-scope target-selection state, `NULL`, and no compiler vtable/security/SEH/alignment artifacts.
- It follows accepted generated target-selection style already present in `TargetSelectionInputPanes.cpp` for `LivingObjectPane *target`, `FindObjectPaneById`, `ObjectType`, `IsTargetingDisabled`, `GetLocalPlayerObject`, `SetTargetHighlight`, and `ObjectId`.
- It keeps exact original spelling uncertainty out of the code where possible by using the exact prompt literal instead of an invented prompt constant.

## Recommended Target Doc Changes

Target path: `by-memory/0x005af5f0-0x005af6de.SelectObjectWithKeyboardPaneConstructor.md`

Recommended edits:

- Change metadata to `COMPLETION:88`, `CONFIDENCE:91`; keep `CANONICAL_OWNER:0000CT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CT`, blank `EMITTER_POSITION_OPTIONAL`.
- Replace the formal C++ block with the exact constructor above.
- Replace stale `95/95 final-code threshold` wording with current combined-score/emitter-gate reasoning.
- Add current MCP session `B006_0002F1_20260629`, server health, exact current lookup/analyze/disasm/xref/get-bytes/get-string facts, two caller-side allocation proof sites, and generated empty-marker proof.
- Add source-quality notes for inferred/descriptive names: `s_activeSelectObjectWithKeyboardPane`, `s_selectObjectTargetId`, `s_selectObjectTargetModeActive`, `SetPaneOrder(NULL, g_pBackPane)`, and prompt literal policy.
- Preserve negative evidence: compiler vtable stores/SEH/security/unwind/adjusted-pointer guard/padding are not source statements; LineInputPane/Pane/MapPane/UserPane/BackPane are dependencies, not owners; exact original singleton/helper spellings remain confidence caps.

## Recommended Support Doc Changes

Support docs to edit after supervisor acceptance:

- `by-class/SelectObjectWithKeyboardPane.md`: update constructor row/reconstruction notes to say [UID:0001LB] is now first-draft populated; add the current MCP-backed source shape and descriptive singleton name `s_activeSelectObjectWithKeyboardPane`; preserve class-level caveats for exact original singleton/static declarations and remaining blank helper/destructor child pages. No score change required unless supervisor chooses a class rescore.
- `by-file/TargetSelectionInputPanes.md`: update the SelectObject row/source-route note and generated-empty context to say [UID:0001LB] now emits constructor C++ through [UID:0000CT]; preserve file placement and direct/indirect route distinction. No score change required.
- `by-memory/0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots.md`: add source-facing descriptive names `s_activeSelectObjectWithKeyboardPane` for `dword_69BF60` and `s_activeTargetObjectWithKeyboardPane` for `dword_69BF64` as provisional module-scope pointer names, or at least add the SelectObject name used by this constructor. Keep original-spelling caveat and no split. No formal C++ change is required by this report unless the supervisor chooses to bundle singleton declaration work.
- `by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md`: already has `s_selectObjectTargetId`; no required edit unless adding a back-reference to the constructor C++.
- `by-memory/0x0069bed8-0x0069bee0.TargetSelectionModeFlags.md`: already emits `s_selectObjectTargetModeActive`; no required edit.
- `by-memory/0x00630b10-0x00630b78.SelectObjectKeyboardPromptString.md`: already records the exact literal and single constructor xref; no required edit. Keep blank C++ because the string page is data evidence.
- `by-memory/0x005af6e0-0x005af709.SelectObjectWithKeyboardPaneDestructor.md` and `by-memory/0x005b7bc0-0x005b7c1f.SelectObjectWithKeyboardPaneScalarDeletingDestructor.md`: inspect for contradiction after adopting the singleton name; update prose only if needed so destructor clears are described as `s_activeSelectObjectWithKeyboardPane = NULL` evidence. No C++ insertion is required by this report.
- `by-memory/0x005afc90-0x005afd23.SelectObjectWithKeyboardPaneObjectListVirtual.md`, `by-memory/0x005afd30-0x005afd4f.SelectObjectWithKeyboardPaneClearCurrentTarget.md`, and `by-memory/0x005afe70-0x005afeee.SelectObjectWithKeyboardPaneForwardTabKey.md`: already support `s_selectObjectTargetId` and mode flag behavior; inspect for contradiction, no planned edit unless stale singleton/helper wording is encountered.
- `LineInputPane` support pages: no edit required. They already support the base constructor and prompt setter interpretation.

## Score And Metadata Recommendation

- Current: `86/90`, owner `0000CT`, reconstructable `TRUE`, emitter `0000CT`, blank C++.
- Recommended: `88/91`, owner unchanged, reconstructable unchanged, emitter unchanged, formal constructor C++ populated.
- Reason higher: current MCP revalidated every assigned evidence point, caller-side allocation routes, exact padding, dependency names, source placement, and generated empty-marker cause; the old blank-C++ gate is stale.
- Reason not higher: exact original singleton pointer spelling remains descriptive, helper `0x00544d30` is source-role stable but original spelling still coordinated through Pane/EventDispatcher docs, and broader class/header declaration work is outside this target.

## Open Questions With Attempted Resolution

- Exact original name for `dword_69BF60`: not recovered. Evidence routes checked: current MCP xrefs, singleton support page, class/file docs, old reports, generated output. Best implementation-ready name is `s_activeSelectObjectWithKeyboardPane`; score cap only.
- Exact original prompt constant name: not recovered. Current formal C++ should use the exact literal; this avoids inventing a constant while preserving behavior.
- Exact original spelling for `0x00544d30`: not fully recovered. Current support docs and accepted constructor pages permit `SetPaneOrder(NULL, g_pBackPane)` / Pane dispatcher-order helper as an implementation-ready role name. Score cap only.
- Whether to emit singleton declarations in [UID:0002A2]: outside this target's required implementation unless supervisor bundles support-declaration cleanup. The constructor target can still emit a first-draft body using the documented descriptive name.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state | Callback proof |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C1 | UID0001LB is exact function `sub_5AF5F0`, range `0x005af5f0-0x005af6de`, size `0xee`, with predecessor/successor padding outside the body. | High | MCP `lookup_funcs`, `get_bytes`, disasm return at `0x005af6dd`. | Target Status / Range / Evidence | incorporate | applied | Target `by-memory/0x005af5f0-0x005af6de.SelectObjectWithKeyboardPaneConstructor.md` now records current MCP session, exact `0xee` bounds, six-byte predecessor padding, two-byte successor padding, and range role; validator `000000000638` ok. |
| C2 | The constructor has exactly two current construction callers, `0x005a5f75` and `0x005ad4e9`, both allocation/call paths. | High | MCP `xrefs_to`, `insn_query`, caller disasm. | Target Evidence / Caller Inventory; class/file support notes | incorporate | applied | Target Evidence Notes include both caller allocation paths; class and file support pages now sync UID0001LB as first-draft constructor; validators `000000000638`, `000000000641`, and `000000000642` ok. |
| C3 | Source body begins with `LineInputPane(NULL)` and later calls `SetPromptText` with exact literal `L"Use arrow key to select target then press enter."`. | High | MCP disasm, `analyze_function`, `get_string`, prompt page [UID:0003J6]. | Target C++ / Evidence; class constructor row | incorporate | applied | Target formal C++ uses `: LineInputPane(NULL)` and `SetPromptText(L"Use arrow key to select target then press enter.")`; class constructor row mirrors the source shape. Prompt string page was inspected and already preserves the data-literal role. |
| C4 | Vtable stores at `0x005af653/659/663` are compiler output for `SelectObjectWithKeyboardPane`, not source statements. | High | MCP disasm and vtable xrefs; destructor/scalar parity. | Target Negative Evidence / C++ rationale | incorporate | applied | Target Reconstruction, Behavior, Access table, Ownership Decision, and Changes explicitly exclude vtable stores, SEH/security/unwind/adjusted-pointer/padding from source C++; class support row states vtable stores are compiler output. |
| C5 | `dword_69BF60` is the active SelectObject singleton pointer; recommended source-facing name is provisional `s_activeSelectObjectWithKeyboardPane`. | Medium-high | MCP xrefs to `0x0069bf60`; [UID:0002A2]; caller gate at `0x005a5f40`. | Target notes; [UID:0002A2]; class/file support | incorporate | applied | Target C++ and prose use provisional `s_activeSelectObjectWithKeyboardPane`; singleton support [UID:0002A2], class [UID:0000CT], and file [UID:0000OH] now document the provisional name and original-spelling caveat; validator `000000000644` ok. |
| C6 | Saved target id `dword_69BF28` should be represented as `s_selectObjectTargetId` in constructor C++. | High | [UID:0002AB], B005 handler report, MCP xrefs and constructor read/write sites. | Target C++ / target-state notes | already-present | applied | Target formal C++ uses `s_selectObjectTargetId`; [UID:0002AB] was inspected and already documents `s_selectObjectTargetId` / `s_selectObjectSavedTargetId`, so no support edit was needed. |
| C7 | Initial target validation accepts a saved target only when object type byte is `3` and disabled/dead byte is `0`, otherwise uses the local player object. | High | MCP disasm/decompile at `0x005af689-0x005af69b`; generated ItemWho style. | Target Behavior / C++ | incorporate | applied | Target formal C++ includes `ObjectType() != kLivingObjectType` / `IsTargetingDisabled()` fallback to `g_pUserPane->GetLocalPlayerObject()`; target Evidence and Behavior preserve the raw offsets. |
| C8 | The constructor highlights the chosen target and writes its object id back to `s_selectObjectTargetId`. | High | MCP disasm at `0x005af6a5` and `0x005af6b0-0x005af6ba`; [UID:0001LG]/handler support. | Target Behavior / C++ | incorporate | applied | Target formal C++ includes `target->SetTargetHighlight(true);` and `s_selectObjectTargetId = target->ObjectId();`; target Evidence and Access table preserve the raw call/write evidence. |
| C9 | `sub_544D30(this, 0, dword_67A740)` is best expressed as `SetPaneOrder(NULL, g_pBackPane)`. | Medium-high | MCP disasm; [UID:00028J]; `by-file/Pane.md`; [UID:0002KB] accepted precedent. | Target C++ / dependency notes; class/file support | incorporate | applied | Target formal C++, Evidence, Behavior, and Access table use `SetPaneOrder(NULL, g_pBackPane)` and preserve `sub_544D30` / `dword_67A740` proof; class and file pages mirror the dependency route. |
| C10 | `byte_69BED9` is `s_selectObjectTargetModeActive` and is cleared by the constructor. | High | MCP xrefs and disasm; [UID:0002A9] emitted declarations. | Target C++ / target notes | already-present | applied | Target formal C++ clears `s_selectObjectTargetModeActive`; [UID:0002A9] was inspected and already emits `static bool s_selectObjectTargetModeActive = false;`, so no support edit was needed. |
| C11 | Old `95/95 final-code threshold` language is stale and should be historicalized/replaced with current combined-score/emitter gate. | High | `by-structure.md` current gate; target current average `88`; old target Reconstruction text. | Target Reconstruction / Changes | historicalize | applied | Target Reconstruction now states the current combined-score/emitter gate and preserves old `95/95` only as historical context; target Changes records the historicalization. |
| C12 | Generated empty-emitter marker for UID0001LB is caused by blank formal C++ in a routed, reconstructable target. | High | Generated `TargetSelectionInputPanes.cpp` command `000000000595` line `867`; target metadata. | Target Reconstruction / Generated status; checklist | incorporate | applied | Target formal C++ is populated; generated `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` header is `validator-command-id: 000000000644`, refreshed `2026-06-29T10:57:09-04:00`, contains UID0001LB at line 236 and constructor at line 237, and has no UID0001LB empty-emitter marker. |

## Validators Expected After Implementation

Run from `source-3/project-documentation` with relative `--file` paths:

> Executable block R001 was removed from this report and preserved verbatim in [0001LB-SelectObjectWithKeyboardPaneConstructor-empty-emitter-source-quality-removed.md](0001LB-SelectObjectWithKeyboardPaneConstructor-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If support edits are limited and the supervisor does not accept singleton-page changes, omit the singleton validator. After the target validator with `--wait-generated`, inspect `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` read-only: UID0001LB should no longer be an `Empty Emitter Marker` and should contain `SelectObjectWithKeyboardPane::SelectObjectWithKeyboardPane()` under [UID:0001LB]. Do not edit generated files and do not run `execute_report`.

## Callback Validation Results

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` with relative `--file` paths:

| File | Command | command_id | command_timestamp | Exit | ok | Generated state / notes |
| --- | --- | --- | --- | ---: | ---: | --- |
| Target [UID:0001LB] | `python .\tools\validator.py --mode file --file by-memory\0x005af5f0-0x005af6de.SelectObjectWithKeyboardPaneConstructor.md --apply --queue-timeout 240 --wait-generated` | `000000000638` | `2026-06-29T10:56:33-04:00` | 0 | 1 | `generated_refresh: completed`, same command id/timestamp; validator-owned side effects included generated C++ refresh, generated reports/projected stats/registry updates, and pre-existing unrelated stale-registry/missing-file diagnostics. |
| Class [UID:0000CT] | `python .\tools\validator.py --mode file --file by-class\SelectObjectWithKeyboardPane.md --apply --queue-timeout 240` | `000000000641` | `2026-06-29T10:56:52-04:00` | 0 | 1 | `generated_refresh: deferred`; projected stats update only. |
| File [UID:0000OH] | `python .\tools\validator.py --mode file --file by-file\TargetSelectionInputPanes.md --apply --queue-timeout 240` | `000000000642` | `2026-06-29T10:57:01-04:00` | 0 | 1 | `generated_refresh: deferred`; validator inserted a UID link/reference for UID0001LB. |
| Singleton [UID:0002A2] | `python .\tools\validator.py --mode file --file by-memory\0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots.md --apply --queue-timeout 240` | `000000000644` | `2026-06-29T10:57:09-04:00` | 0 | 1 | `generated_refresh: deferred`; generated `TargetSelectionInputPanes.cpp` header now shows `validator-command-id: 000000000644`, newer than the target validator and still containing UID0001LB constructor output. |

Read-only generated check after validators:

- `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` header: `validator-command-id: 000000000644`, `validator-refreshed-at: 2026-06-29T10:57:09-04:00`, `validator-refresh-source: deferred-generated-refresh`.
- UID0001LB now appears at line 236 with `Completion:88 | Confidence:91`; `SelectObjectWithKeyboardPane::SelectObjectWithKeyboardPane()` appears at line 237.
- `rg "UID:0001LB.*Empty Emitter Marker"` returned no matches. Other unrelated empty markers remain for other UIDs.

## Changed Files

Manual B005 edits during implementation callback:

- Updated: `by-memory/0x005af5f0-0x005af6de.SelectObjectWithKeyboardPaneConstructor.md`
- Updated: `by-class/SelectObjectWithKeyboardPane.md`
- Updated: `by-file/TargetSelectionInputPanes.md`
- Updated: `by-memory/0x0069bf60-0x0069bf68.TargetSelectionKeyboardPaneSingletonSlots.md`
- Updated: `tools/leaser/Agents/Agent-B005/research/0001LB-SelectObjectWithKeyboardPaneConstructor-empty-emitter-source-quality.md`

Validator-owned side effects, not manual edits:

- `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` refreshed by validator; inspected read-only.
- Validator output reported generated reports/projected stats/registry updates, including `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/-ag-research-tracker.md`, and `project-level/-auto-completion-stats.md`.

No generated files, coverage reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, or lock files were edited manually. `execute_report` was not run.

Lease proof:

- Leases taken as B005 at `2026-06-29T14:52:47Z`, expiring `2026-06-29T14:57:47Z`, for the four edited by-* docs: target constructor, class page, file page, and singleton page.
- Release command `python leaser.py B005 unlease` returned `Success` for all four paths.
- Final `tools/leaser/Agents/current_leases.md` readback shows `No active leases.`

## Implementation Tracking Checklist

Initial report-only pass and accepted implementation:

- [x] Supervisor validation required before implementation. Proof: supervisor callback accepted UID0001LB report and started implementation mode in `goal.md`.
- [x] Target [UID:0001LB] metadata to update: `86/90 -> 88/91`; keep owner/emitter/reconstructable unchanged. Proof: target header now `COMPLETION:88`, `CONFIDENCE:91`, owner `0000CT`, reconstructable `TRUE`, emitter `0000CT`; validator `000000000638` ok.
- [x] Target [UID:0001LB] formal `RECONSTRUCTION_CPP CODE` to populate with `SelectObjectWithKeyboardPane::SelectObjectWithKeyboardPane()` exactly as supplied in this report. Proof: target formal block populated; generated output line 237 emits the constructor.
- [x] Target [UID:0001LB] prose to update with MCP session `B006_0002F1_20260629`, server health, exact bounds, two caller routes, predecessor/successor padding, base constructor call, singleton publish/guard-clear evidence, prompt setup, three vtable stores as compiler output, target validation/fallback, highlight, saved-id write, `SetPaneOrder(NULL, g_pBackPane)`, mode-byte clear, generated empty-marker cause, and stale-gate replacement. Proof: target Status/Reconstruction/Evidence/Behavior/Access/Ownership/Changes sections updated; validator `000000000638` ok.
- [x] [UID:0000CT] `by-class/SelectObjectWithKeyboardPane.md` to sync constructor row/reconstruction notes with UID0001LB first-draft C++ readiness and provisional singleton source name. Proof: constructor row and Evidence/Reconstruction/Changes updated; validator `000000000641` ok.
- [x] [UID:0000OH] `by-file/TargetSelectionInputPanes.md` to sync SelectObject constructor source-route/generated-empty status. Proof: file role/source-route/proposed contents/boundary/changes updated for UID0001LB and singleton names; validator `000000000642` ok.
- [x] [UID:0002A2] singleton support page to add provisional source-facing singleton names, or explicitly document if supervisor excludes this support edit. Proof: singleton support page now names `s_activeSelectObjectWithKeyboardPane` and `s_activeTargetObjectWithKeyboardPane` with original-spelling caveats; validator `000000000644` ok.
- [x] [UID:0002AB], [UID:0002A9], [UID:0003J6], LineInputPane support pages, and listed sibling SelectObject helper/destructor pages to inspect for contradictions; update only stale/conflicting wording found during callback. Proof: targeted `rg`/readback found [UID:0002AB] already has `s_selectObjectTargetId`, [UID:0002A9] already emits `s_selectObjectTargetModeActive`, [UID:0003J6] already preserves the exact prompt/data role, LineInputPane docs already support base constructor/prompt setter, and sibling SelectObject helper/destructor pages had no contradiction caused by the accepted singleton/helper/source wording. Their separate blank-code threshold text is outside this UID0001LB callback and was left untouched.
- [x] Claim And Incorporation Ledger to update during callback with `applied`, `already-present`, `excluded-with-reason`, or `blocked` verification states. Proof: ledger rows C1-C12 now have callback states and proof; no blocked rows.
- [x] Historical/stale assumptions to preserve: old `95/95` blank-code gate is stale; vtable/SEH/security/unwind/padding are compiler artifacts; singleton/helper exact spellings remain descriptive confidence caps. Proof: target Reconstruction/Changes and class/file/singleton support pages preserve these caveats.
- [x] Rejected alternatives to preserve: LineInputPane/Pane/MapPane/UserPane/BackPane/global pages are dependencies, not the target owner; prompt string page remains data evidence with blank C++. Proof: target Ownership Decision and file/class support notes preserve dependency-only disposition; prompt string page inspected and unchanged.
- [x] Validators to run from `source-3/project-documentation` with relative `--file` paths as listed above. Proof: validators `000000000638`, `000000000641`, `000000000642`, and `000000000644` all exited 0 with `ok:1`.
- [x] Generated refresh check: after target validator with `--wait-generated`, inspect generated `TargetSelectionInputPanes.cpp` read-only and confirm UID0001LB emits constructor code and no longer appears as an empty marker. Proof: generated header `validator-command-id: 000000000644`, refreshed `2026-06-29T10:57:09-04:00`; UID0001LB at line 236, constructor at line 237, no UID0001LB empty-marker match.
- [x] Manual coverage/tracker action: none. Do not edit manual `-coverage-report.md`, generated reports, validator state, or project-level generated files. Proof: no manual edits to those files; only validator-owned generated/project-state side effects occurred.
- [x] Leases during implementation callback only: take short leases only for immediate target/support edits, release immediately after edit/validator batch, and record proof. Proof: B005 leased four by-* docs at `2026-06-29T14:52:47Z`, release command returned `Success` for all four, and final current lease report shows no active leases.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: current `goal.md` assignment `B005-implement-0001LB-SelectObjectWithKeyboardPaneConstructor-20260629`.
- [x] Accepted target/support doc details incorporated at report-level detail. Proof: four by-* docs updated; support contradiction checks resolved as already-present/not-applicable.
- [x] Ledger verification states updated with proof. Proof: C1-C12 updated above.
- [x] Scoped validators run and results recorded with command id/timestamp/exit/ok/generated-refresh state. Proof: Callback Validation Results table above.
- [x] Generated `TargetSelectionInputPanes.cpp` freshness inspected read-only. Proof: generated header and UID0001LB line checks recorded above.
- [x] Leases released and current lease proof recorded. Proof: release success for all four paths and final `No active leases` readback.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0001LB-SelectObjectWithKeyboardPaneConstructor-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0001LB-SelectObjectWithKeyboardPaneConstructor-empty-emitter-source-quality.md","timestamp":"2026-06-29T11:06:02","uid":"0001LB"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001LB-SelectObjectWithKeyboardPaneConstructor-empty-emitter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/0001LB-SelectObjectWithKeyboardPaneConstructor-empty-emitter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001LB"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
