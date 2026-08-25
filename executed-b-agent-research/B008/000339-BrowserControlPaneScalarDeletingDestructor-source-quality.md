** TARGET-REPORT-UID:000339 **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 000339 BrowserControlPane Scalar Deleting Destructor Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: treat [UID:000339] as an MSVC scalar deleting destructor wrapper for `BrowserControlPane`, not as the source-authored destructor body.
- Final disposition: keep the page as exact ABI/vtable evidence, but do not hand-author scalar-delete wrapper C++ on it. Create an exact ordinary destructor child for `0x0046b990-0x0046ba32` first, then change UID000339 formal C++ to a coverage comment pointing to that ordinary destructor child.
- Required action: split/promote `by-memory/0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor.md` (new UID) from [UID:0000Z6], route it through [UID:000015] / [UID:0000HV], and use it as the source-bearing `BrowserControlPane::~BrowserControlPane()` page. Then update [UID:000339] as compiler-wrapper coverage, preserving vtable/thunk/delete-flag evidence.
- Confidence: high for wrapper-vs-ordinary split; medium-high for final exact source filename because the Browser file root is current policy while a later `BrowserControlPane.cpp` split remains plausible.

## Target

- Target UID: `000339`
- Target path: `by-memory/0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` Not-Covered Files - Reconstructable, `85/88`, reports `0`.
- Current supervisor classification: report-only source-quality research for scalar deleting destructor treatment, active global clearing, base teardown, support docs, and score.
- Current scores and parent state: target `85/88`, `CANONICAL_OWNER:000015`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000015`; class [UID:000015] is `88/90`; Browser source root [UID:0000HV] is `87/89`; core aggregate [UID:0000Z6] is `88/92`.

## Current Target State

UID000339 currently documents `0x00470410-0x004704ec` as the newer `BrowserControlPane` scalar deleting destructor. It records the correct class owner, Browser source-root context, vtable data ref `0x0061344c`, adjustor thunk callers `0x0047027e` and `0x00470289`, `m_webBrowser` release from object offset `+0x120`, `g_activeBrowserControlPane` clear, base pane teardown through `0x00544580`, delete flags, and optional project delete helper.

The open source-quality problem is not evidence weakness. The page is currently an emitting reconstructable page with a blank formal C++ block, while its own Reconstruction Notes already say final C++ should express the class destructor and let the compiler generate the scalar deleting wrapper/adjustors. Current generated coverage also reports `emits_code:false`. That is correct for the wrapper body, but incomplete until the ordinary destructor range has its own source-bearing child.

Related target/support docs checked:

- `by-memory/0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor.md`
- `by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md`
- `by-class/BrowserControlPane.md`
- `by-file/Browser.md`
- `by-global/g_activeBrowserControlPane.md`
- `by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md`
- `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md`
- `by-memory/0x00470278-0x004702fc.BrowserDialogDestructorAdjustorThunks.md`
- `executed-b-agent-research/B002/0000HV-Browser-empty-emitter-family-source-quality.md`
- `executed-b-agent-research/B010/0000Z6-BrowserControlPaneCore-source-quality.md`
- `executed-b-agent-research/B006/00032Y-BrowserNonDeletingDestructor-empty-emitter-source-quality.md`
- `executed-b-agent-research/B001/0000ZF-BrowserOleLegacyAndHelpers.md`

No Wave2/Wave3 instruction source was used as authority. Existing generated output and executed reports were used only as leads or accepted project-state context, then checked against current IDA MCP and by-* docs.

## Evidence Checked

IDA MCP session: `supervisor_resume_20260629`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.

- `lookup_funcs` for `0x00470410`, `0x0046b990`, `0x00470278`, `0x00470283`, `0x004704f0`, `0x0046b520`, `0x0046eff0`, and neighboring browser starts.
- `analyze_function`, `decompile`, `disasm`, and `callees` for `0x00470410`.
- `decompile`, `disasm`, `analyze_function`, `xrefs_to`, and `callees` for `0x0046b990`.
- `xrefs_to` for `0x00470410`, BrowserControlPane vtable cells `0x0061344c`, `0x006134b4`, `0x006134e4`, `0x006134f0`, `0x00613518`, `0x00613558`, `0x00613578`, `0x006135c4`, and global `0x0067ab28`.
- `search_text` for `unk_67AB28` over the target range.
- Project docs and prior-report searches: `000339`, `0x00470410`, `BrowserControlPaneScalarDeletingDestructor`, `BrowserControlPane scalar`, `BrowserControlPaneCore-source-quality`, `0x0046b990`, and scalar-wrapper/ordinary-destructor report patterns.

Failed/unhelpful checks:

- One `func_query` attempt used the wrong schema and returned unrelated early functions. It was not used as evidence; exact `lookup_funcs` and targeted xrefs supplied the needed boundary facts.
- `xref_query` with `target` was schema-incompatible; `xrefs_to` supplied the authoritative xref data.

## IDA MCP Facts

- `lookup_funcs 0x00470410` reports `sub_470410`, size `0xdc`, exactly matching `0x00470410-0x004704ec`.
- `analyze_function 0x00470410` reports prototype `_DWORD *__thiscall(_DWORD *Block, char)`, no ordinary callers, and xrefs to `0x00470410` from two code thunks plus one vtable data slot: `0x0047027e`, `0x00470289`, and `0x0061344c`.
- `disasm 0x00470410` shows the wrapper stores BrowserControlPane vtables at offsets `+0x0`, `+0xa0`, `+0xa4`, `+0x108`, `+0x10c`, `+0x110`, `+0x114`, and `+0x118`; releases the pointer at `+0x120` through vslot `+8`; clears `g_activeBrowserControlPane` at `0x0067ab28`; calls `sub_544580`; then tests delete flags and calls `sub_4F4AC0` only when bit `1` is set and bit `4` is clear. The bit-`4` path pushes size `0x338` to `@_guard_check_icall_nop@4`.
- `callees 0x00470410` reports only `sub_544580`, `sub_4F4AC0`, and `@_guard_check_icall_nop@4`; the COM release is an indirect vtable call.
- `lookup_funcs 0x0046b990` reports `sub_46B990`, size `0xa2`, exactly `0x0046b990-0x0046ba32`.
- `decompile 0x0046b990` is the same source-authored destructor body without delete flags: it restores the same BrowserControlPane vtable views, releases `this[72]` / offset `+0x120` through vslot `+8`, clears `g_activeBrowserControlPane`, and calls `sub_544580`.
- `xrefs_to 0x0046b990` reports no direct xrefs. That matches an ordinary destructor used by compiler EH/unwind or scalar-wrapper duplication rather than a source-called public method.
- `xrefs_to 0x00470278` and `0x00470283` each report one vtable data ref from BrowserControlPane secondary/tertiary vtable slices. The mixed adjustor page documents these as `this -= 0xa0` and `this -= 0xa4` thunks targeting `0x00470410`.
- `xrefs_to 0x0067ab28` reports exactly 24 xrefs, including target clear at `0x00470493`, ordinary destructor clear at `0x0046ba13`, constructor writes at `0x0046b58d`/`0x0046b594`, clear helper `0x00470210`, browser accelerator consumer `0x0046c575`, application guards, and surface/presentation consumers.

## Positive Evidence Summary

- The source-authored cleanup body exists separately at `0x0046b990-0x0046ba32` and is already listed in [UID:000015] and [UID:0000Z6] as `BrowserControlPane::~BrowserControlPane`.
- UID000339 duplicates that ordinary cleanup and adds scalar deleting destructor ABI mechanics: `char` delete flag parameter, `retn 4`, optional `operator delete` helper, guarded bit-`4` size path, and vtable/thunk-only entry routes.
- The two adjustor thunks and primary vtable slot prove UID000339 is the vtable deletion dispatch artifact for BrowserControlPane layout, not an independently source-called helper.
- `g_activeBrowserControlPane` clearing is real BrowserControlPane destructor semantics, but that source semantics belongs to the ordinary destructor child; the wrapper only repeats it as compiler-generated lowering for virtual deletion.

## Negative Evidence Summary

- No ordinary direct caller to `0x00470410` was found. The only code xrefs are compiler adjustor thunks, and the only data xref is the primary vtable cell.
- No ordinary direct caller to `0x0046b990` was found either, but the body shape is the non-deleting destructor source body, not a reason to prefer the wrapper as source. This mirrors accepted Browser and BrowserPane destructor handling: ordinary destructor bodies can have no direct caller while scalar wrappers are vtable-only.
- No evidence supports moving ownership to Application, Surface, WebBoardDialog, BrowserWindow, BrowserPane, BrowserThread, or a standalone compiler-wrapper source file. Those modules either consume active browser-control state or own adjacent browser-family objects.
- No evidence supports hand-emitting delete-flag logic, SEH cookie setup, `retn 4`, or guard-check size branch as human-written NexusTK source.

## Heuristic / Inference Reanalysis And Validation

The best source-shape inference is ordinary Visual C++ virtual destructor lowering:

1. Source declares/defines `BrowserControlPane::~BrowserControlPane()`.
2. The compiler emits the non-deleting destructor body at `0x0046b990`.
3. The compiler emits the scalar deleting destructor at `0x00470410` for vtable deletion dispatch.
4. The compiler emits secondary/tertiary `this` adjustor thunks at `0x00470278` and `0x00470283`.

The target's behavior is not a handwritten `DeleteBrowserControlPane` helper. Its only unique work beyond `0x0046b990` is scalar-delete ABI machinery. Therefore, the implementation-ready repair is not to make UID000339 non-reconstructable by itself; that would hide rebuild-relevant vtable/destructor evidence. The repair is to attach the source-authored body to a new exact ordinary destructor child, then make UID000339 a wrapper/coverage page.

Rejected alternatives:

- Keep UID000339 as the source-emitting destructor body: rejected because it would hand-port compiler delete flags and duplicate ordinary destructor source.
- Set UID000339 to `RECONSTRUCTABLE:FALSE` immediately with blank emitter: rejected as too lossy until the ordinary destructor child exists and carries the source body. Current by-structure practice allows ABI wrapper pages to remain reconstructable/routed with formal coverage comments when they are generated from source declarations/destructors.
- Leave the issue as an open "compiler wrapper" blocker: rejected by assignment. The blocker resolves to a concrete split and coverage-comment sequence.
- Move source to the class page [UID:000015]: rejected for method body emission. The class page is a declaration/support page and already says method bodies should live on exact child pages.
- Move source to the broad aggregate [UID:0000Z6]: rejected by accepted B010 policy. The aggregate spans many methods and compiler metadata; exact children should carry source.

No unresolved target-blocking question remains for wrapper disposition. Remaining broader uncertainty is only exact final source file split (`browser/Browser.cpp` versus later `browser/BrowserControlPane.cpp`), which does not block current owner/emitter route through [UID:000015] to [UID:0000HV].

## Ranked Ownership Analysis

### 1. BrowserControlPane class [UID:000015], emitted through Browser source root [UID:0000HV]

- Evidence for: vtable refs all name BrowserControlPane slices; ordinary destructor at `0x0046b990`, scalar wrapper at `0x00470410`, constructor at `0x0046b520`, COM view fields, active global, and BrowserControlPane class docs agree. Browser source root is current accepted route for this family.
- Evidence against: none for semantic class ownership. Exact one-file versus split-file source path remains unresolved, but current docs intentionally route through Browser.
- Decision: best owner/emitter route.

### 2. Broad BrowserControlPaneCore aggregate [UID:0000Z6]

- Evidence for: contains ordinary destructor range and accepted child-split plan.
- Evidence against: accepted B010 policy says aggregate C++ stays blank and exact child pages carry method source.
- Decision: support/container evidence only; do not emit UID000339 or ordinary destructor source through the aggregate.

### 3. Compiler-generated no-owner/non-emitting wrapper

- Evidence for: scalar deleting wrapper and adjustor mechanics are compiler-generated.
- Evidence against: the wrapper is tied to a known class vtable and source declaration. Existing project pattern keeps class-owned scalar wrappers as reconstructable/routed evidence with coverage comments after ordinary destructor source exists.
- Decision: not a no-owner orphan. It should remain class-associated wrapper coverage.

## Source Placement

Recommended source placement remains the Browser source root [UID:0000HV], with semantic class owner [UID:000015]. The new ordinary destructor child should be named:

- `by-memory/0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor.md`

Source-facing role:

- `BrowserControlPane::~BrowserControlPane`

The formal wrapper page [UID:000339] should not contain a handwritten destructor body. After the ordinary destructor child exists and receives a UID, UID000339 should use only a formal coverage comment equivalent to:

```cpp
// Emitted code for this range is covered by [UID:<new BrowserControlPaneNonDeletingDestructor UID>].
```

Do not use that placeholder literally in by-* docs; the implementation callback should create/validate the child and then reference its real UID.

## Range / Split / Reclassification Analysis

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | ---: | --- |
| `0x0046b990-0x0046ba32` | new recommended child | ordinary non-deleting `BrowserControlPane::~BrowserControlPane` | TRUE | [UID:000015] | recommend `87/91` | create/promote exact source-bearing child |
| `0x00470410-0x004704ec` | [UID:000339] | scalar deleting destructor wrapper | TRUE as ABI coverage after child exists | [UID:000015] | recommend `87/91` after comment coverage | keep wrapper evidence, no handwritten body |
| `0x00470278-0x00470283` / `0x00470283-0x0047028e` | inside [UID:000337] | secondary/tertiary adjustor thunks | FALSE on mixed thunk page | none for cluster; semantic owner BrowserControlPane for these two thunks | no change | already non-emitting compiler thunk cluster |
| `0x0061344c`, `0x006134b4`, `0x006134e4` | inside [UID:0001OB] | BrowserControlPane vtable slots | source-declared/generated-binary through class | mixed index non-emitting | no change | support evidence |

The ordinary destructor child score recommendation `87/91` is justified because current MCP verifies exact function bounds, vtable restores, COM pointer release, global clear, base teardown, and parity with the scalar wrapper. It should remain below `95` because exact final class declaration/source split and original field spellings remain broader BrowserControlPane questions.

UID000339 score recommendation `87/91` is justified after implementation because the wrapper will have exact vtable/thunk-only reachability, duplicate ordinary destructor parity, delete flag handling, optional delete helper, bit-`4` guarded size path, and a formal no-code/coverage comment. It should not rise above low 90s because final proof depends on the newly created ordinary destructor child and broader class declaration completeness.

## First-Draft C++ Recommendation

Eligible for draft C++ on UID000339: no.

Reason formal C++ should remain a coverage comment on UID000339: the target range is compiler-emitted scalar deleting destructor glue. Handwriting it would encode MSVC ABI flags, guard-check behavior, SEH prologue details, and `operator delete` routing as if they were NexusTK source. The source representation is the `BrowserControlPane` virtual destructor declaration plus the ordinary destructor body at `0x0046b990-0x0046ba32`.

Exact no-code proof for UID000339:

- Entry is from the primary BrowserControlPane vtable cell `0x0061344c` and two adjusted-this thunks only.
- Body duplicates `0x0046b990` cleanup, then adds delete-flag mechanics.
- Delete/free behavior is driven by scalar deleting destructor argument bits, not by a source-visible method.
- Source should define the ordinary destructor once and let the compiler regenerate the wrapper and adjustor thunks.

The ordinary destructor child is the eligible source-bearing target. This report does not insert final C++ during report-only work; the implementation callback should create the exact child and then decide whether to add formal first-draft `BrowserControlPane::~BrowserControlPane()` C++ there under the normal child-page validator gate.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| B008-339-C01 | UID000339 is a scalar deleting destructor wrapper, not the source-authored ordinary destructor body. | High | MCP xrefs: vtable `0x0061344c`, thunks `0x0047027e`/`0x00470289`; delete flag disasm. | UID000339 Scope/Reconstruction Notes/IDA Evidence | incorporate | applied; validator `000000004433` ok |
| B008-339-C02 | The ordinary `BrowserControlPane::~BrowserControlPane` body is `0x0046b990-0x0046ba32`. | High | MCP `lookup_funcs`, `decompile`, `disasm`; [UID:0000Z6] and [UID:000015] method lists. | [UID:0004DG][0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor](by-memory/0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor.md); [UID:0000Z6]; [UID:000015] | incorporate | applied; validators `000000004450`, `000000004434`, `000000004435` ok |
| B008-339-C03 | UID000339 duplicates the ordinary cleanup and adds scalar-delete ABI mechanics. | High | MCP decompilation parity and extra `sub_4F4AC0`, `@_guard_check_icall_nop@4`, `retn 4`, flag tests. | UID000339 IDA Evidence/Reconstruction Notes | incorporate | applied; validator `000000004433` ok |
| B008-339-C04 | `g_activeBrowserControlPane` clear is real destructor semantics, but source ownership belongs to the ordinary destructor child. | High | MCP writes at `0x0046ba13` and `0x00470493`; global docs. | ordinary destructor child; `g_activeBrowserControlPane` support docs; UID000339 | incorporate | applied; validators `000000004450`, `000000004436`, `000000004437` ok |
| B008-339-C05 | Do not reclassify UID000339 as an unrelated no-owner/non-emitting orphan. | High | vtable/class owner evidence, project scalar-wrapper coverage precedent. | UID000339 metadata/rationale; BrowserControlPane support docs | incorporate | applied; validators `000000004433`, `000000004435` ok |
| B008-339-C06 | Create ordinary destructor child before converting UID000339 to coverage-comment treatment. | High | B002 empty-emitter row for `000339`; current absence of exact ordinary child page. | implementation checklist; UID000339; new child | incorporate | applied; child assigned stable UID `0004DG` by validator `000000004418`, then body validated by `000000004450` |
| B008-339-C07 | Recommended post-implementation scores: new ordinary child `87/91`; UID000339 `87/91` after coverage comment and evidence refresh. | Medium-high | current MCP depth plus score gate rules and 95+ ceiling. | metadata of new child and UID000339 | incorporate | applied; validators `000000004450`, `000000004433` ok |
| B008-339-C08 | Existing [UID:000337] adjustor thunk page remains correct and should not become source-emitting. | High | MCP `xrefs_to` for `0x00470278`/`0x00470283`; current thunk inventory. | [UID:000337] support note only if needed | already-present | verified no change needed |

## Score And Metadata Recommendation

Current UID000339 metadata:

- `COMPLETION:85`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:000015`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000015`
- formal C++ blank

Recommended UID000339 metadata after ordinary child split:

- `COMPLETION:87`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:000015`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000015`
- formal C++ coverage comment to the real UID of the new ordinary destructor child

Reason not lower: exact range, vtable/thunk entry route, ordinary destructor parity, active-global clear, base teardown, delete flags, and support docs are now verified.

Reason not higher: UID000339 is still compiler-wrapper evidence, not final source; the exact original header/source split and some BrowserControlPane field spellings remain broader source-quality work.

Recommended new ordinary destructor child metadata:

- Path: `by-memory/0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor.md`
- `CANONICAL_OWNER:000015`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000015`
- Suggested score: `87/91`
- Item summary should state it is the exact source-authored ordinary destructor body that restores BrowserControlPane vtable views, releases `m_webBrowser` at `+0x120`, clears `g_activeBrowserControlPane`, and calls base pane teardown.

## Recommended Target Doc Changes

Target path: `by-memory/0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor.md`

Recommended edits after child creation:

- Expand Scope/IDA Evidence with current MCP facts from session `supervisor_resume_20260629`.
- State explicitly that `0x0046b990-0x0046ba32` is the ordinary source destructor and UID000339 is the scalar deleting wrapper.
- Preserve vtable slot `0x0061344c`, adjustor thunk callers `0x0047027e`/`0x00470289`, vtable restores, `m_webBrowser` release, `g_activeBrowserControlPane` clear, base teardown call `0x00544580`, optional `sub_4F4AC0`, and bit-`4` size path.
- Add formal coverage comment referencing the real new ordinary destructor UID.
- Update score to `87/91` if the child split and comment validate cleanly.
- Do not set owner/emitter blank and do not hand-author scalar delete C++.

## Recommended Support Doc Changes

- `by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md`: update Recommended Child Split/Covered Ranges to link the new ordinary destructor child and state UID000339 is its scalar deleting wrapper coverage.
- `by-class/BrowserControlPane.md`: change the method list entry for `0x0046b990-0x0046ba32` from plain text to the new UID link, and update the scalar destructor bullet to say it is compiler wrapper/coverage for the ordinary child.
- `by-file/Browser.md`: add a short BrowserControlPane destructor split note under BrowserControlPane class/source route or empty-emitter family notes; keep current Browser source root.
- `by-global/g_activeBrowserControlPane.md` and `by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md`: ensure writer table distinguishes ordinary destructor clear at `0x0046ba13` from scalar wrapper duplicate clear at `0x00470493` and links the new child.
- `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md`: optionally add a BrowserControlPane destructor-route note like the existing BrowserPane route: ordinary destructor child owns source, UID000339 owns scalar wrapper coverage.
- `by-memory/0x00470278-0x004702fc.BrowserDialogDestructorAdjustorThunks.md`: no required metadata change; optionally link UID000339's final coverage note if supervisor wants the route cross-reference refreshed.

## Open Questions With Attempted Resolution

- Should UID000339 remain reconstructable/emitting or become no-code wrapper treatment? Resolved: keep class-owned reconstructable/routed ABI evidence, but formal C++ should be coverage comment only after ordinary destructor child exists.
- Should source live in the ordinary destructor? Resolved: yes, source semantics live at `0x0046b990-0x0046ba32`; UID000339 is compiler deletion dispatch.
- Is active-browser global clearing unique to UID000339? Resolved: no. Both ordinary and scalar destructor paths clear `g_activeBrowserControlPane`; ordinary destructor is source-bearing.
- Is a new BrowserControlPane-only source file required? Not for this task. Current source root remains Browser; later source-tree split is nonblocking.

## Validator Results

Report-only pass: no validators were run before supervisor acceptance.

Implementation callback scoped file validators:

| Command id | Timestamp | File | Exit | Result |
| --- | --- | --- | ---: | --- |
| `000000004418` | `2026-07-02T07:00:30-04:00` | `by-memory\0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor.md` | 0 | initial child validation assigned stable UID `0004DG`, inserted metadata `87/91`, owner/emitter [UID:000015], and deferred generated refresh |
| `000000004450` | `2026-07-02T07:10:35-04:00` | `by-memory\0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor.md` | 0 | `ok: 1`; projected stats updated, deferred generated refresh |
| `000000004433` | `2026-07-02T07:04:11-04:00` | `by-memory\0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor.md` | 0 | `ok: 1`; registry updated, UID links inserted, deferred generated refresh |
| `000000004434` | `2026-07-02T07:04:16-04:00` | `by-memory\0x0046b520-0x0046cfe0.BrowserControlPaneCore.md` | 0 | `ok: 1`; projected stats updated, deferred generated refresh; existing unrelated `missing_ref_uid 0003OH` noted |
| `000000004435` | `2026-07-02T07:04:18-04:00` | `by-class\BrowserControlPane.md` | 0 | `ok: 1`; projected stats updated, deferred generated refresh |
| `000000004436` | `2026-07-02T07:04:20-04:00` | `by-global\g_activeBrowserControlPane.md` | 0 | `ok: 1`; projected stats updated, deferred generated refresh |
| `000000004437` | `2026-07-02T07:04:22-04:00` | `by-memory\0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md` | 0 | `ok: 1`; projected stats updated, deferred generated refresh |
| `000000004448` | `2026-07-02T07:10:14-04:00` | `by-file\Browser.md` | 0 | `ok: 1`; projected stats updated, deferred generated refresh; existing unrelated missing-ref UID warnings noted |

No `execute_report` command, execute-report variant, registry lifecycle command, manual report move, or archive command was run.

Generated freshness: all validators reported `generated_refresh: deferred` and wrote generated refresh command ids. Supervisor execution remains responsible for final report execution and any generated-output review.

## Changed Files

- Created: `by-memory/0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor.md`
- Modified: `by-memory/0x00470410-0x004704ec.BrowserControlPaneScalarDeletingDestructor.md`
- Modified: `by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md`
- Modified: `by-class/BrowserControlPane.md`
- Modified: `by-file/Browser.md`
- Modified: `by-global/g_activeBrowserControlPane.md`
- Modified: `by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md`
- Modified: `tools/leaser/Agents/Agent-B008/research/000339-BrowserControlPaneScalarDeletingDestructor-source-quality.md`
- Renamed: none.
- Leases used: B008 leased target/support docs for the first edit/validator batch and released them immediately afterward. `by-file/Browser.md` was initially blocked by other agent leases; when available it was already present at accepted detail, was validated under a short B008 lease, and that lease was released. No active B008 lease remains.
- Report execution: not run. B agents must not run `tools/validator.py execute_report`, any dry-run execute variant, registry lifecycle command, manual report move, or archive command.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Accepted for implementation callback by supervisor.
- [x] Create exact ordinary destructor child `by-memory/0x0046b990-0x0046ba32.BrowserControlPaneNonDeletingDestructor.md` with owner/emitter [UID:000015], source root [UID:0000HV], score target `87/91`, and evidence for vtable restores, `m_webBrowser` release, `g_activeBrowserControlPane` clear, and base teardown. Stable UID is `0004DG`.
- [x] Update UID000339 target doc with current MCP facts, wrapper-vs-ordinary source split, vtable/thunk-only route, delete-flag evidence, and formal coverage comment to real new child UID `0004DG`.
- [x] Keep UID000339 `CANONICAL_OWNER:000015`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000015`; do not hand-author scalar delete C++.
- [x] Update [UID:0000Z6] BrowserControlPaneCore child split and destructor notes to link the new ordinary destructor child and UID000339 wrapper.
- [x] Update [UID:000015] BrowserControlPane method list/source-emission state to link the new ordinary destructor child and preserve scalar wrapper no-code policy.
- [x] Update [UID:0000HV] Browser source-root notes for BrowserControlPane destructor split and wrapper coverage sequencing. Initially lease-blocked; when the lease became available the required B008 details were already present at report-level detail, then validated with command `000000004448`.
- [x] Update `g_activeBrowserControlPane` by-global and exact storage docs to distinguish ordinary destructor clear `0x0046ba13` from scalar wrapper duplicate clear `0x00470493`.
- [x] Optionally update [UID:0001OB] BrowserVtablesAndStrings with a BrowserControlPane destructor route note matching the BrowserPane destructor-route pattern. Reviewed and not needed for the accepted required path; no edit made.
- [x] Confirm [UID:000337] adjustor thunk page remains non-emitting; only add a cross-reference if needed. No edit needed.
- [x] Preserve rejected alternatives: no Application/Surface/WebBoardDialog ownership, no handwritten scalar-delete wrapper, no immediate orphan no-owner treatment.
- [x] Run scoped validators for the new ordinary child, UID000339, and each edited support doc; report command ids, timestamps, exit codes, and `ok` counts.
- [x] Check generated Browser/by-memory output freshness after validators if generated empty-emitter state matters. Validators reported `generated_refresh: deferred`; supervisor execution owns final generated refresh/review.
- [x] Supervisor-owned tracker/coverage: no manual `auto-generated` edits. No auto-generated files edited.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Validators run and results recorded.
- [x] Generated report refresh completed by validator or explicit generated-freshness state recorded.
- [x] Remaining unapplied accepted items listed with exact blocker.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004465","destination_path":"executed-b-agent-research/B008/000339-BrowserControlPaneScalarDeletingDestructor-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/000339-BrowserControlPaneScalarDeletingDestructor-source-quality.md","timestamp":"2026-07-02T07:12:39-04:00","uid":"000339"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
