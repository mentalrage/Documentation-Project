** TARGET-REPORT-UID:000228 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000228 HelpPane Singleton Close Helpers Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:000228][0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers](../../../../../by-memory/0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers.md) as one reconstructable, emitting HelpPanes-owned helper-pair page.
- Final disposition: executable 85/85+ documentation path. Recommend `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000JU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JU`, blank `EMITTER_POSITION_OPTIONAL`, and supervisor/A-agent-owned first-draft C++ from the section below.
- Required action: supervisor/A-agent should update the target page evidence, score, and coverage row. Do not split this page and do not move it to caller-feature files.
- Confidence: high. Live IDA MCP on 2026-06-17 confirms the exact two wrapper functions, global reads, caller sites, vtable-slot targets, scalar deleting destructor flag behavior, and padding boundaries.

## Supporting Research

## Target

- Target UID: `000228`
- Target path: `by-memory/0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers.md`
- Source queue/report row: supervisor assignment `B001-goal2-help-pane-singleton-close-source-quality-000228-20260617`; current project-level low-completion row shows `82/88`.
- Current supervisor classification: source-quality/inference B-agent target, not an unowned target.
- Current scores and parent state: target `82/88`, owner/emitter [UID:0000JU][HelpPanes](../../../../../by-file/HelpPanes.md), parent `90/86`, emitted to `auto-generated/NexusTK/ui/controls/HelpPanes.cpp`.

## Executive Recommendation

The best source-facing interpretation is a pair of file-local HelpPanes helpers:

| Address | Best source-facing name | Best signature | Evidence status |
| --- | --- | --- | --- |
| `0x004a0d40` | `CloseItemHelpPaneSingleton` | `static void CloseItemHelpPaneSingleton()` | Descriptive/inferred; live IDA still labels it `sub_4A0D40`. |
| `0x004a0d60` | `CloseSimpleHelpPaneSingleton` | `static void CloseSimpleHelpPaneSingleton()` | Descriptive/inferred; live IDA already labels it `CloseSimpleHelpPaneSingleton`. |

Both helpers are side-effect-only close/delete wrappers. IDA gives synthetic `int` returns because `eax` is not normalized on the null path, but every checked caller ignores the return value. Source should treat them as `void`.

Keep source placement with `HelpPanes.cpp`, not `NewInventoryPane.cpp`, `ItemMenuDialogs.cpp`, `ArgumentedMenuDialogs.cpp`, `SelfLookPane.cpp`, `AlertPanes.cpp`, or `DialogSession.cpp`. The caller set spans independent feature files, while the helpers operate only on HelpPanes singleton globals and HelpPanes vtable-owned destructors.

## Supervisor Active Recheck

- The active supervisor assignment requested source-facing helper names/signatures, vtable-slot close/delete semantics, singleton global ownership/name/type validation, caller-family review, HelpPanes versus caller-feature placement, range/padding policy, and exact score/metadata/coverage recommendations.
- The assigned item does not require split repair. It is not a mixed-owner aggregate; it is a two-helper sibling page with internal `0xcc` alignment.
- Every source-bearing child in scope is already represented by this single page. Splitting into two `0x11` pages would duplicate the same ownership, vtable, and caller evidence without improving source reconstruction.

## Inference Research Guidance Check

- `by-structure.md` directs agents to use IDA/MCP as ground truth for functions, xrefs, and boundaries, and to keep final C++ blank unless route, names, dependencies, and source shape are source-quality.
- `inference_research.md` cautions against using adjacency alone for same-file ownership. That matters here because the target sits physically between [UID:000130][VersatileAlertPaneDestructor](../../../../../by-memory/0x004a0cb0-0x004a0d37.VersatileAlertPaneDestructor.md) and [UID:000131][DialogSessionCore](../../../../../by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md); adjacency is weaker than the direct HelpPanes global/vtable/caller evidence.
- Existing documentation was treated as a lead. Live MCP revalidated the current claims and strengthened them by resolving the first vtable slot to concrete scalar deleting destructors.

## Heuristic / Inference Reanalysis And Validation

### Helper names and signatures

- Evidence checked: live `analyze_batch` on `0x004a0d40` and `0x004a0d60`; live call-site instruction slices at `0x004ed0b2`, `0x004ed8fd`, `0x0051b34d`, `0x0051f7ad`, and `0x00568e1c`; existing target/global/class docs.
- Best inference: `CloseItemHelpPaneSingleton` and `CloseSimpleHelpPaneSingleton`, both `static void` file-local helpers.
- Rejected alternatives:
  - `DeleteItemHelpPaneSingleton` / `DeleteSimpleHelpPaneSingleton`: behavior does deallocate through scalar deleting destructor, but caller context is UI close-before-replacement/dismissal, and `Close...` matches existing IDA label for the simple helper.
  - `DismissItemHelpPaneSingleton`: too close to [UID:0003PR][ItemHelpPaneDismissItemHelp](../../../../../by-memory/0x004ccc80-0x004ccc95.ItemHelpPaneDismissItemHelp.md), a class/vtable helper; this target is file-local and covers simple help too.
  - `Destroy...`: too destructor-mechanism-focused and less consistent with UI replacement callers.
- Final direction: descriptive/inferred source names, not proven original names. The unresolved original spelling should not cap ownership or score below 85 because function behavior and placement are proven.

### First-vtable-slot and scalar/delete flag semantics

- Evidence checked: live `get_int` on `0x0061abe4` and `0x0061ae04`, live `analyze_batch` on `0x004ce560`, `0x004ce430`, `0x004c7290`, and `0x004c8b20`, plus [UID:00016W][HelpTooltipDestructorThunks](../../../../../by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md).
- Facts:
  - `SimpleHelpPane` primary vtable `0x0061abe4` slot `0` points to `0x004ce560`, `SimpleHelpPane_ScalarDeletingDestructor`.
  - `ItemHelpPane` primary vtable `0x0061ae04` slot `0` points to `0x004ce430`, the ItemHelpPane scalar deleting destructor body.
  - Both scalar deleting destructors run ordinary teardown, clear the matching singleton, call base pane teardown, and call `sub_4F4AC0` only when `(flags & 1) != 0` and `(flags & 4) == 0`.
  - This target passes literal `1`, so the path is destructor plus object free.
- Best inference: the helper calls are equivalent to deleting the active tooltip singleton through a virtual destructor path. The source-facing expression is likely a `delete` of the active singleton pointer or a file-local close helper that performs that delete.
- Rejected alternatives:
  - "virtual close method" as a separate source-authored slot: rejected because slot `0` resolves to the scalar deleting destructor, not a close event method.
  - "non-deleting destructor call": rejected because flag `1` takes the free path in both scalar deleting destructor bodies.
  - "flag value unknown": rejected for flag `1`; the bit-4 path remains compiler/ABI-specific but is not used by this helper.

### Globals, names, and types

- Evidence checked: live `entity_query(kind=names)` over `0x0069adf0-0x0069ae10`, live `xrefs_to` for `0x0069ae04` and `0x0069ae00`, global docs, and exact storage docs.
- Facts:
  - IDB names are `g_pSimpleHelpPane` at `0x0069ae00` and `g_pItemHelpPane` at `0x0069ae04`.
  - `g_pItemHelpPane` has 20 direct xrefs, including constructor publish/fallback clear, ordinary destructor clear, support clear helper, scalar deleting destructor clear, this close helper, feature readers, and vtable-helper reads.
  - `g_pSimpleHelpPane` has 23 direct xrefs, including constructor publish/fallback clear, ordinary destructor clear, support clear helper, scalar deleting destructor clear, this close helper, and broad feature readers.
- Best type direction:
  - `static SimpleHelpPane* g_pSimpleHelpPane = nullptr;`
  - `static ItemHelpPane* g_pItemHelpPane = nullptr;`
- Source placement: declarations remain with [UID:0000JU][HelpPanes](../../../../../by-file/HelpPanes.md), with the documented caveat that a future proven `ItemHelpPane.cpp` split could move the item global together with `ItemHelpPane`.
- Rejected alternatives:
  - Caller-owned globals: rejected because the xref sets span many independent feature files.
  - `void*` or `Pane*` as the best documentation type: possible at the compiler ABI level, but class-specific constructor/destructor/vtable evidence supports the narrower source types for documentation.

### Caller/reachability interpretation

- Evidence checked: live helper xrefs and instruction slices; caller/support pages for NewInventoryPane, ServerItemMenuItemList, ArgumentedMenuMenuItemList, and SelfLookPane.
- Facts:
  - `0x004a0d40` has code xrefs at `0x004ed0b2` and `0x004ed8fd` inside `NewInventoryPane` input/hover logic, `0x0051b34d` inside `ServerItemMenuItemList`, and `0x0051f7ad` inside `ArgumentedMenuMenuItemList`.
  - `0x004a0d60` has a code xref at `0x00568e1c` inside `SelfLookPaneOnMouseClick`.
  - Checked call sites ignore return values. Replacement paths proceed to allocate/construct new panes after cleanup.
  - `SelfLookPane` also has an inline item-help delete sequence at `0x00568df1-0x00568e01` before using `CloseSimpleHelpPaneSingleton`, proving callers can inline the same idiom and are consumers, not owners.
- Best interpretation: helper reachability is static and direct. These are live cleanup-before-replacement helpers, not dead adjacency leftovers or unreferenced artifacts.

### Source placement, ownership, and emitter route

- Evidence checked: HelpPanes file page, Proposed Source Tree `ui/controls/HelpPanes.cpp`, global/class pages, caller feature docs, adjacent AlertPanes/DialogSession docs, and auto-generated route row.
- Ranking:
  - Best: [UID:0000JU][HelpPanes](../../../../../by-file/HelpPanes.md). It owns the tooltip/help pane source family, globals, vtables, and helper pair route; it is `90/86` and clears the parent gate.
  - Second: [UID:00006U][ItemHelpPane](../../../../../by-class/ItemHelpPane.md) plus [UID:0000D6][SimpleHelpPane](../../../../../by-class/SimpleHelpPane.md). Rejected as direct owner because this page spans two classes and is file-local glue, not a method of either class.
  - Third: caller-feature owners such as NewInventoryPane, ItemMenuDialogs, ArgumentedMenuDialogs, or SelfLookPane. Rejected because callers are consumers from separate source families.
  - Rejected by adjacency: AlertPanes/VersatileAlertPane and DialogSession. No target xrefs or globals bind the helpers to either adjacent source family.
- Final route: `CANONICAL_OWNER:0000JU`, `EMITTER_UIDS:0000JU`, projected source root `NexusTK/ui/controls/HelpPanes.cpp`.

### Split/range policy

- Evidence checked: live `lookup_funcs`, `entity_query(kind=functions)`, and `get_bytes` around `0x004a0d30-0x004a0d90`.
- Facts:
  - Previous function `0x004a0cd0` ends at `0x004a0d37`.
  - `0x004a0d37-0x004a0d40` is nine `0xcc` bytes.
  - `0x004a0d40-0x004a0d51` is one 17-byte helper.
  - `0x004a0d51-0x004a0d60` is fifteen `0xcc` bytes.
  - `0x004a0d60-0x004a0d71` is one 17-byte helper.
  - `0x004a0d71-0x004a0d80` is fifteen `0xcc` bytes.
  - `0x004a0d80` starts `DialogSessionCore`.
- Best policy: keep a single helper-pair page with internal alignment. The pair is source-related, shares one owner, and is too small to justify two separate child pages.

### Final C++ state

- Evidence checked: active code-entry policy in `by-structure.md`, score/route evidence, caller return-use slices, vtable/delete behavior, and generated-output caveats.
- Recommendation: first-draft C++ is not blocked. The best source-facing helper body is a plain `delete` on the matching singleton pointer; MSVC lowers that source to the observed null check plus virtual scalar deleting destructor call with flag `1`.
- Application state: B001 should not directly edit by-* final C++ blocks. Supervisor/A-agent can use the first-draft section below when updating the target page.
- Rejected source spellings:
  - Explicit vtable call: rejected as compiler output, not source.
  - Post-delete `g_p... = nullptr`: rejected because both scalar deleting destructors already clear the matching global and the helper has no post-call store.
  - Non-deleting destructor call plus manual free: rejected because the observed call passes scalar-delete flag `1`.
- Score impact: first-draft C++ is available. Original helper spelling remains inferred, but that is not a source-quality blocker for an 85/85+ documentation path.

## Evidence Standards Used

- Live IDA MCP session: `b002_000133_screen_dimmer_20260617`, opened against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, Hex-Rays ready, imagebase `0x400000`.
- MCP tools used: `idb_open`, `analyze_batch`, `lookup_funcs`, `entity_query`, `xrefs_to`, `get_int`, `get_bytes`, `insn_query`, and `int_convert`.
- Documentation evidence: target page, HelpPanes file page, global/storage pages, SimpleHelpPane/ItemHelpPane class and memory pages, destructor/vtable support pages, caller-family pages, coverage rows, and proposed source tree.
- Strength: high for function boundaries, global reads, caller sites, vtable slot targets, and padding. Medium-high for original source spelling because no original symbols/PDB/source file exists for `0x004a0d40`.

## IDA MCP Facts

- Function/range facts:
  - `0x004a0d40`: `sub_4A0D40`, size `0x11`, seven instructions.
  - `0x004a0d60`: `CloseSimpleHelpPaneSingleton`, size `0x11`, seven instructions.
  - Surrounding functions in `0x004a0c80-0x004a0e20`: `0x004a0cb0`, `0x004a0cbb`, `0x004a0cd0`, `0x004a0d40`, `0x004a0d60`, and `0x004a0d80`.
- Data/table/padding facts:
  - `0x004a0d37-0x004a0d40`, `0x004a0d51-0x004a0d60`, and `0x004a0d71-0x004a0d80` are `0xcc` padding.
  - `0x0061abe4` points to `0x004ce560`.
  - `0x0061ae04` points to `0x004ce430`.
- Xref facts:
  - `0x004a0d40` code xrefs: `0x004ed0b2`, `0x004ed8fd`, `0x0051b34d`, `0x0051f7ad`.
  - `0x004a0d60` code xref: `0x00568e1c`.
  - `0x0069ae04` has 20 direct data refs.
  - `0x0069ae00` has 23 direct data refs.
- Vtable/global/type facts:
  - IDB names `g_pSimpleHelpPane`, `g_pItemHelpPane`, `??_7SimpleHelpPane@@6B@`, and `??_7ItemHelpPane@@6B@` are present.
  - `SimpleHelpPane_ScalarDeletingDestructor` is named at `0x004ce560`; `ItemHelpPane` scalar deleting destructor body is at `0x004ce430`.
- Negative IDA facts:
  - No static callees for either helper because the call is indirect through vtable slot `0`.
  - No target xrefs bind these helpers to AlertPanes or DialogSession despite address adjacency.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004a0d40-0x004a0d51` | part of [UID:000228] | item-help singleton close/delete helper | TRUE | [UID:0000JU] | recommend `86/91` page | keep in pair page |
| `0x004a0d51-0x004a0d60` | internal span | alignment padding | FALSE/padding | [UID:000228] context | n/a | keep internal evidence |
| `0x004a0d60-0x004a0d71` | part of [UID:000228] | simple-help singleton close/delete helper | TRUE | [UID:0000JU] | recommend `86/91` page | keep in pair page |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004ed0b2` | `NewInventoryPane`/`sub_4ECB50` calls `sub_4A0D40` | Item tooltip close path; caller sets its own return state after call. |
| `0x004ed8fd` | `NewInventoryPane`/`sub_4ECB50` calls `sub_4A0D40` | Item tooltip replacement before constructing new tooltip data. |
| `0x0051b34d` | `ServerItemMenuItemList` handler calls `sub_4A0D40` | Closes active rich item tooltip before allocating replacement `ItemHelpPane`. |
| `0x0051f7ad` | `ArgumentedMenuMenuItemListHandleMouseEvent` calls `sub_4A0D40` | Closes active rich item tooltip before replacement. |
| `0x00568e1c` | `SelfLookPaneOnMouseClick` calls `CloseSimpleHelpPaneSingleton` | Closes active simple tooltip before replacement/simple help flow. |
| `0x00568df1-0x00568e01` | `SelfLookPaneOnMouseClick` inline item-help delete | Confirms caller-feature code consumes the HelpPanes idiom but does not own this helper pair. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - [UID:0000JU][HelpPanes](../../../../../by-file/HelpPanes.md) already lists this helper pair in the proposed HelpPanes contents.
  - [UID:0000R9][g_pItemHelpPane](../../../../../by-global/g_pItemHelpPane.md) and [UID:0001PD][g_pItemHelpPane storage](../../../../../by-memory/0x0069ae04-0x0069ae08.g_pItemHelpPane.md) document the 20-ref lifecycle.
  - [UID:0000S9][g_pSimpleHelpPane](../../../../../by-global/g_pSimpleHelpPane.md) and [UID:0001PC][g_pSimpleHelpPane storage](../../../../../by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md) document the 23-ref lifecycle.
  - [UID:00016W][HelpTooltipDestructorThunks](../../../../../by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md) already documents scalar deleting destructor flag semantics.
  - [UID:00025G][Help/ItemHelp Read-Only Data](../../../../../by-memory/0x0061aad4-0x0061b340.HelpItemHelpReadOnlyData.md) maps the vtable heads to HelpPanes classes.
- Existing docs that are stale, incomplete, or contradicted:
  - Target page still scores `82/88` and says "first-vtable-slot dispatch" without resolving slot `0` to concrete scalar deleting destructors.
  - Target page still calls the helper names "candidate" and does not explain why `void` is the best source signature despite IDA's synthetic `int`.
  - Coverage row has the same incomplete vtable-slot wording and stale score.
- Generated/coverage report state:
  - `auto-generated/-ag-memory-coverage.md` already routes [UID:000228] to `auto-generated/NexusTK/ui/controls/HelpPanes.cpp`.
  - `project-level/-auto-completion-stats.md` lists [UID:000228] at `82/88`.

## Ranked Ownership Analysis

### 1. [UID:0000JU] HelpPanes

- Evidence for: direct reads of HelpPanes singleton globals; first vtable slots resolve to HelpPanes class scalar deleting destructors; caller family spans inventory/menu/self-look consumers; HelpPanes source page is already `90/86`; projected source tree places `HelpPanes.cpp` under `ui/controls`.
- Evidence against: physical address is not adjacent to main HelpPanes class cluster at `0x004c65a0+`; helper names are descriptive rather than original-proof.
- Decision: accepted. Address adjacency is weaker than direct global/vtable/caller evidence.

### 2. ItemHelpPane/SimpleHelpPane class owners

- Evidence for: each helper targets a singleton for one class, and the vtable slot target is that class's scalar deleting destructor.
- Evidence against: the page spans two classes, and the helpers are not methods; they are source-level file helpers used by multiple feature modules.
- Decision: reject as direct canonical owner for this page. Keep class pages as support docs.

### 3. Caller feature files

- Evidence for: direct callers exist in `NewInventoryPane`, `ServerItemMenuItemList`, `ArgumentedMenuMenuItemList`, and `SelfLookPane`.
- Evidence against: no single caller family owns both helpers; consumers only close/reopen tooltips. Consumer xrefs are not ownership proof.
- Decision: reject. Caller docs should reference the helper, not own it.

### 4. AlertPanes / DialogSession adjacency

- Evidence for: physical range is between `VersatileAlertPaneDestructor` and `DialogSessionCore`.
- Evidence against: no target global, vtable, or caller evidence ties this helper pair to alerts or dialog sessions.
- Decision: reject. Keep only adjacency/padding references in coverage/ignored docs.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new file recommended. Keep current `ui/controls/HelpPanes.cpp`.
- Likely full contents: existing [UID:0000JU][HelpPanes](../../../../../by-file/HelpPanes.md) contents: `HelpPane`, `SimpleHelpPane`, `SimpleHelpPane2`, `WillBeChanged*Pane`, `ItemHelpPane`, singleton pointers, support helpers, and this close helper pair.
- Candidate related items that belong: target [UID:000228], [UID:0000R9], [UID:0000S9], [UID:00016S], [UID:00006U] support pages, and vtable/read-only data [UID:00025G].
- Candidate related items rejected: caller feature files and adjacent `AlertPanes`/`DialogSession` ranges.
- Standalone, narrow, or broad source-file inference: broad existing HelpPanes source-family inference remains strongest; a future `ItemHelpPane.cpp` split is plausible but not proven for this two-helper page.

## Negative Evidence Summary

- Address locality alone would point at AlertPanes/DialogSession, but direct state and vtable evidence points at HelpPanes.
- Consumer xrefs alone would point at inventory/menu/self-look files, but the consumers are spread across independent source families and are closing HelpPanes-owned singleton state.
- The IDA function name `sub_4A0D40` is not a blocker; the sibling simple helper already has the saved descriptive label, and behavior/caller symmetry supports `CloseItemHelpPaneSingleton`.
- The `int` decompiler return is not source evidence. Call sites ignore it and the null path leaves `eax` uncontrolled, so the source signature should be `void`.

## Final Recommendation

- Exact changes recommended for [UID:000228]:
  - `COMPLETION:82 -> 86`
  - `CONFIDENCE:88 -> 91`
  - `CANONICAL_OWNER:0000JU` unchanged
  - `RECONSTRUCTABLE:TRUE` unchanged
  - `EMITTER_UIDS:0000JU` unchanged
  - `EMITTER_POSITION_OPTIONAL:` unchanged blank
  - `RECONSTRUCTION_CPP CODE`: supervisor/A-agent may apply the first-draft helper declarations/bodies below; B001 makes no direct by-* edit.
- Exact parent assignment recommended: keep [UID:0000JU][HelpPanes](../../../../../by-file/HelpPanes.md).
- Exact items left no-owner/non-emitting: none.
- Exact split/rename recommendation: no split; optional evidence text may rename table rows from "candidate" to descriptive/inferred names.
- Exact future work outside this assignment: final C++ integration for HelpPanes should place the first-draft helpers with the existing HelpPanes declarations and avoid duplicate singleton definitions.

## First-Draft C++ Recommendation

This is a report-only first draft for supervisor/A-agent use. It should be integrated wherever the HelpPanes file declares the singleton globals and local helpers; do not duplicate the global definitions if they already exist in the target reconstruction context.

```cpp
static SimpleHelpPane* g_pSimpleHelpPane = nullptr;
static ItemHelpPane* g_pItemHelpPane = nullptr;

static void CloseItemHelpPaneSingleton();
static void CloseSimpleHelpPaneSingleton();

static void CloseItemHelpPaneSingleton()
{
    delete g_pItemHelpPane;
}

static void CloseSimpleHelpPaneSingleton()
{
    delete g_pSimpleHelpPane;
}
```

Rationale: `delete g_pItemHelpPane;` and `delete g_pSimpleHelpPane;` are null-safe source expressions. In the observed MSVC output, each lowers to `mov ecx, [global]`, `test ecx, ecx`, branch-on-null, load vtable slot `0`, push scalar-deleting flag `1`, and indirect-call the scalar deleting destructor. No helper-local store to `nullptr` should be added because the scalar deleting destructors clear `0x0069ae04` and `0x0069ae00` themselves.

## Support Docs To Update

- Target page [UID:000228]: update score, replace "candidate" wording with descriptive/inferred helper names, add live 2026-06-17 vtable-slot/scalar-delete evidence, add `void` signature rationale, and add call-site return-unused evidence.
- [UID:0000JU][HelpPanes](../../../../../by-file/HelpPanes.md): no score change required; optionally refresh the helper row to say slot `0` resolves to `ItemHelpPane`/`SimpleHelpPane` scalar deleting destructors with flag `1`.
- [UID:0003PR][ItemHelpPaneDismissItemHelp](../../../../../by-memory/0x004ccc80-0x004ccc95.ItemHelpPaneDismissItemHelp.md): optional follow-up only. Its final-C++ blocker can point at this report/source-name decision, while still leaving class/member final C++ blank.
- [UID:0000R9], [UID:0000S9], [UID:0001PD], [UID:0001PC], [UID:00016W], and [UID:00025G]: no required score or metadata changes; current docs already support the conclusion.

## Supervisor-Owned Coverage Row Replacement

Placement context: replace the existing [UID:000228] row between the ignored `0x004a0d37-0x004a0d40` row and the ignored `0x004a0d71-0x004a0d80` row in `by-memory/-coverage-report.md`.

```markdown
    - [UID:000228][0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers](by-memory/0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers.md) 0x004a0d40-0x004a0d71 | file-local helper pair | HelpPaneSingletonCloseHelpers : reconstructable : 86% : very-strong : B001 2026-06-17 live IDA recheck confirms two `0x11` wrappers, exact `0xcc` padding at `0x004a0d37-0x004a0d40`, `0x004a0d51-0x004a0d60`, and `0x004a0d71-0x004a0d80`, `g_pItemHelpPane`/`g_pSimpleHelpPane` reads, direct caller sets from item/menu/simple-tooltip replacement flows, return values ignored at checked callers, and vtable slot `0` dispatch with flag `1` resolving to `ItemHelpPane`/`SimpleHelpPane` scalar deleting destructors. Keep HelpPanes owner/emitter; B001 report includes first-draft C++ as singleton `delete` helpers for supervisor/A-agent application.
```

## Follow-Up Actions

- Supervisor actions:
  - Apply target page score/evidence update and coverage row replacement if accepted.
  - Run scoped validators listed below after edits.
  - Optionally save IDA label `CloseItemHelpPaneSingleton` at `0x004a0d40` in a separate IDB-label maintenance pass; this report did not edit the IDB.
- A-agent actions:
  - If touching caller docs, refer to these helpers as HelpPanes-owned close helpers rather than caller-owned local helpers.
  - Do not split this target unless future evidence shows separate source owners, which current evidence does not.
- B001 future research actions:
  - None required for [UID:000228] after supervisor applies the score/evidence update.

## Confidence

- Recommendation confidence: high.
- Score confidence: `86/91` is justified by tiny function size, exact boundary proof, current direct xrefs, resolved global names, concrete scalar deleting destructor targets, and parent route.
- Remaining uncertainty: original helper spelling and final C++ source expression are inferred/descriptive, not original-proof. This is a final-C++/source-polish blocker only.

## Validator Results

- Commands run by B001 for this report: no by-* validators were run because this was report-only and no by-* files were edited.
- Recommended supervisor validation after applying target/support/coverage edits:

> Executable block R001 was removed from this report and preserved verbatim in [000228-help-pane-singleton-close-source-quality-removed.md](000228-help-pane-singleton-close-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Any unresolved validator warnings/errors: not applicable to this report. The final readback checks below validate only the B001 research file.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/000228-help-pane-singleton-close-source-quality.md`
- Modified: none outside B001 research folder.
- Renamed: none.
- Moved to executed: no.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/000228-help-pane-singleton-close-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"000228"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000228-help-pane-singleton-close-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/000228-help-pane-singleton-close-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000228"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
