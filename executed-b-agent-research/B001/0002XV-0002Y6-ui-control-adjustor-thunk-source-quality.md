** TARGET-REPORT-UID:0002XV **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002XV-0002Y6 UI Control Adjustor Thunk Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: raise all seven primary adjustor-thunk pages from `82/88` to `86/90` after adding byte-level thunk evidence, vtable/data xref identities, adjusted-this offsets, scalar deleting destructor targets, and final-C++ rationale.
- Final disposition: keep every primary target `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, and blank reconstruction C++ because these are compiler-generated secondary-vtable destructor adjustor thunks, not source-authored routines.
- Required action: update the seven target pages and supervisor-owned `by-memory/-coverage-report.md`; update the parent aggregate stale ImageButton row and add/replace support text that corrects the `0x0049af11` pair from "SelectBox-only" to shared ButtonControlPane-family destructor adjustors.
- Confidence: high for byte/range/xref/thunk classification; medium-high for original file grouping because the exact source split between `ButtonControlPane.cpp`, `TextButtonControlPane.cpp`, `PopupMenuControls.cpp`, and possible narrower control files remains provisional.

## Target

- Assignment: `B001-goal2-ui-control-adjustor-thunk-source-quality-0002XV-0002XY-0002Y9-0002YB-0002Y2-0002YD-0002Y6-20260616`
- Primary target paths:
  - [UID:0002XV] `by-memory/0x0049af11-0x0049af27.SelectBoxControlPaneAdjustorThunks.md`
  - [UID:0002XY] `by-memory/0x0049af69-0x0049af7f.ImageButtonControlPaneAdjustorThunks.md`
  - [UID:0002Y9] `by-memory/0x0049af95-0x0049afab.PopupMenuControlPaneAdjustorThunks.md`
  - [UID:0002YB] `by-memory/0x0049afab-0x0049afc1.RadioGroupControlPaneAdjustorThunks.md`
  - [UID:0002Y2] `by-memory/0x0049b003-0x0049b019.SliderControlPaneAdjustorThunks.md`
  - [UID:0002YD] `by-memory/0x0049b05b-0x0049b071.TextButtonControlPaneAdjustorThunks.md`
  - [UID:0002Y6] `by-memory/0x0049b071-0x0049b087.TextButtonExControlPaneAdjustorThunks.md`
- Current scores/state for all seven: `COMPLETION:82`, `CONFIDENCE:88`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank C++.
- Parent aggregate checked: [UID:00011Y] `by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md`, currently `86/90`, non-reconstructable, non-emitting mixed destructor/thunk index.

## Executive Recommendation

The seven target pages should rise to `86/90` because live IDA MCP now confirms all important facts that were previously only summarized: exact half-open ranges, exact raw bytes, `this` adjustment offsets, branch targets, vtable/data xrefs, scalar deleting destructor wrapper relationships, and source-file/class placement consequences.

Do not set a canonical owner or emitter for the adjustor pages. The semantic owners are the class declarations/vtable layouts that cause MSVC to emit the thunks, but the thunks themselves are not source objects. Assigning the thunk pages to class owners would pollute generated source routing with compiler glue that should regenerate from class declarations.

One naming correction is recommended:

- [UID:0002XV] should be renamed from `SelectBoxControlPaneAdjustorThunks` to `ButtonControlPaneSharedDeletingDestructorAdjustorThunks` or, if the supervisor wants less churn, its title/body must explicitly say it is shared by `ButtonControlPane`, `SelectBoxControlPane`, `WeatherLayerPane`, and `RainingLayerPane`. Live vtable refs prove the current SelectBox-only title is too narrow.

The other six names are defensible as current descriptive documentation names because their vtable refs are class-specific and their scalar deleting destructor wrappers restore those same class vtables.

## Supervisor Active Recheck

- The assignment is report-only. I did not edit by-* docs, generated reports, source files, IDA DB, generated source, or `by-memory/-coverage-report.md`.
- Split repair is not required. Exact child pages already exist for all seven primary adjustor pairs and for their scalar deleting destructor counterparts.
- The missing work is source-quality evidence and shared-report/support synchronization, not new child creation.

## Inference Research Guidance Check

- `by-structure.md` classifies adjustor thunks as `compiler/linker-generated` and excludes them from handwritten source reconstruction.
- `inference_research.md` requires best defensible names/source directions even when original source proof is absent. The strongest defensible source direction here is "class declarations/vtable layout cause compiler emission"; not "write thunk functions in C++".
- Existing docs were treated as leads, not authority. The main correction found during reanalysis is that [UID:0002XV] is not SelectBox-only; IDA names/xrefs show it is a shared ButtonControlPane-family deleting-destructor adjustor pair.

## Heuristic / Inference Reanalysis And Validation

### Compiler-generated naming

- Best descriptive thunk name pattern: `<ClassOrSharedOwner>DeletingDestructorAdjustor_subA0` and `<ClassOrSharedOwner>DeletingDestructorAdjustor_subA4`.
- Evidence: every target pair is exactly two 11-byte functions with the same two-instruction shape: `sub ecx, 0A0h; jmp <scalar deleting destructor>` and `sub ecx, 0A4h; jmp <same scalar deleting destructor>`.
- Rejected alternative: source-authored helper functions. There are no normal code callers; inbound refs are vtable/data cells only, and the functions only adjust `this` then tail-jump.
- Final direction: keep page-level names as "AdjustorThunks" except rename/clarify [UID:0002XV] as shared ButtonControlPane-family glue.

### Vtable/source ownership

- [UID:0002XY], [UID:0002Y9], [UID:0002YB], [UID:0002Y2], [UID:0002YD], and [UID:0002Y6] each have class-specific secondary-vtable refs and scalar deleting destructor targets. Their related class pages and file pages are the correct source-placement documents.
- [UID:0002XV] has vtable refs from:
  - `0x00617c40` / `0x00617c70`: `ButtonControlPane` secondary views.
  - `0x0061d528` / `0x0061d558`: `SelectBoxControlPane` secondary views.
  - `0x006311e4` / `0x00631214`: `WeatherLayerPane` secondary views.
  - `0x00631274` / `0x006312a4`: `RainingLayerPane` secondary views.
- Best inference: `0x0049b0d0` is a shared no-extra-teardown scalar deleting wrapper for classes whose destructor is equivalent to base `ButtonControlPane`/base pane teardown; the adjustor pair is shared secondary-vtable glue. It should not be documented as exclusively SelectBox-owned.
- Rejected alternative: attach [UID:0002XV] to SelectBox only. That ignores the primary `ButtonControlPane` vtable cell `0x00617bd8` and weather/rain vtable children [UID:0002Z7] and [UID:0002Z8].

### Split/merge/reclassification

- No merge is recommended for the primary targets. They are exact contiguous 0x16-byte pairs inside a larger destructor/thunk island and already split cleanly.
- No reclassification to reconstructable is recommended. The pages are correctly `RECONSTRUCTABLE:FALSE`.
- No new source file is recommended. The source-bearing declarations belong to existing class/file pages: [UID:0000HY] `ButtonControlPane`, [UID:0000OK] `TextButtonControlPane`, and [UID:0000MN] `PopupMenuControls`.

### Final C++ treatment

- Final C++ must remain blank for all seven targets. A handwritten source body such as `ecx -= 0xA0; return destructor(...)` would be decompiler/compiler-glue output, not plausible original C++.
- The correct final-source treatment is to document class declarations, inheritance, destructor declarations, and object layout well enough that the compiler emits equivalent adjustor thunks and scalar deleting wrappers.
- The scalar deleting destructor pages are `source-declared/generated-binary` wrappers. They may remain reconstructable because the declaration-side destructor relationship must be represented, but their C++ blocks should also stay blank until final class declarations are source-quality.

### Score impact

- Current `82/88` scores are too low after byte/xref/source-quality validation. `86/90` is justified for each target because all meaningful facts for a tiny compiler thunk page are known.
- Do not use `95+`: original source declaration spelling, exact class-header layout, and compiler-version reproduction details are still not final-audit complete.

## Evidence Standards Used

- Live IDA MCP session: `b002_00011G_scrollable_control_20260616`, `NexusTK.exe`.
- IDA tools used: `lookup_funcs`, `disasm`, `xrefs_to`, `decompile`, `entity_query`, `make_signature_for_range`.
- Existing docs checked: seven target pages, seven scalar destructor pages, [UID:00011Y] aggregate, related class/file pages, [UID:0002Z7]/[UID:0002Z8] weather/rain vtable data, [UID:000252] control read-only data, generated coverage, project low-score stats, and supervisor-owned `by-memory/-coverage-report.md`.

## IDA MCP Facts

### Function and byte facts

| UID | Range | Functions | Exact bytes | Adjustment | Scalar target |
| --- | --- | --- | --- | --- | --- |
| `0002XV` | `0x0049af11-0x0049af27` | `sub_49AF11`, `sub_49AF1C`, both `0xb` | `81 E9 A0 00 00 00 E9 B4 01 00 00 81 E9 A4 00 00 00 E9 A9 01 00 00` | `-0xA0`, `-0xA4` | `0x0049b0d0` |
| `0002XY` | `0x0049af69-0x0049af7f` | `sub_49AF69`, `sub_49AF74`, both `0xb` | `81 E9 A0 00 00 00 E9 1C 03 00 00 81 E9 A4 00 00 00 E9 11 03 00 00` | `-0xA0`, `-0xA4` | `0x0049b290` |
| `0002Y9` | `0x0049af95-0x0049afab` | `sub_49AF95`, `sub_49AFA0`, both `0xb` | `81 E9 A0 00 00 00 E9 10 04 00 00 81 E9 A4 00 00 00 E9 05 04 00 00` | `-0xA0`, `-0xA4` | `0x0049b3b0` |
| `0002YB` | `0x0049afab-0x0049afc1` | `sub_49AFAB`, `sub_49AFB6`, both `0xb` | `81 E9 A0 00 00 00 E9 6A 04 00 00 81 E9 A4 00 00 00 E9 5F 04 00 00` | `-0xA0`, `-0xA4` | `0x0049b420` |
| `0002Y2` | `0x0049b003-0x0049b019` | `sub_49B003`, `sub_49B00E`, both `0xb` | `81 E9 A0 00 00 00 E9 A2 05 00 00 81 E9 A4 00 00 00 E9 97 05 00 00` | `-0xA0`, `-0xA4` | `0x0049b5b0` |
| `0002YD` | `0x0049b05b-0x0049b071` | `sub_49B05B`, `sub_49B066`, both `0xb` | `81 E9 A0 00 00 00 E9 3A 07 00 00 81 E9 A4 00 00 00 E9 2F 07 00 00` | `-0xA0`, `-0xA4` | `0x0049b7a0` |
| `0002Y6` | `0x0049b071-0x0049b087` | `sub_49B071`, `sub_49B07C`, both `0xb` | `81 E9 A0 00 00 00 E9 E4 07 00 00 81 E9 A4 00 00 00 E9 D9 07 00 00` | `-0xA0`, `-0xA4` | `0x0049b860` |

### Vtable/data xrefs

| UID | First thunk xrefs | Second thunk xrefs | Meaning |
| --- | --- | --- | --- |
| `0002XV` | `0x00617c40`, `0x0061d528`, `0x006311e4`, `0x00631274` | `0x00617c70`, `0x0061d558`, `0x00631214`, `0x006312a4` | Shared secondary views for `ButtonControlPane`, `SelectBoxControlPane`, `WeatherLayerPane`, and `RainingLayerPane`. |
| `0002XY` | `0x00617e34` | `0x00617e64` | `ImageButtonControlPane` secondary views. |
| `0002Y9` | `0x00618020` | `0x00618050` | `PopupMenuControlPane` secondary views. |
| `0002YB` | `0x00617ed8` | `0x00617f08` | `RadioGroupControlPane` secondary views. |
| `0002Y2` | `0x00617f7c` | `0x00617fac` | `SliderControlPane` secondary views. |
| `0002YD` | `0x00617ce8` | `0x00617d18` | `TextButtonControlPane` secondary views. |
| `0002Y6` | `0x00617d90` | `0x00617dc0` | `TextButtonExControlPane` secondary views. |

### Scalar deleting destructor targets

| Target | Wrapper facts |
| --- | --- |
| `0x0049b0d0` | `0x3b` bytes; calls `0x00544580`, optional `0x004f4ac0`, vector-delete guard size `0x10c`; xrefs from two thunks plus primary vtable cells `ButtonControlPane`, `SelectBoxControlPane`, `WeatherLayerPane`, `RainingLayerPane`. |
| `0x0049b290` | `0x55` bytes; restores three `ImageButtonControlPane` vtable views, calls base cleanup, optional free, vector-delete guard size `0x114`. |
| `0x0049b3b0` | `0x67` bytes; restores three `PopupMenuControlPane` vtable views, deletes owned helper at `+0x108`, calls base cleanup/free. |
| `0x0049b420` | `0x67` bytes; restores three `RadioGroupControlPane` vtable views, deletes owned helper at `+0x108`, calls base cleanup/free. |
| `0x0049b5b0` | `0x3b` bytes; calls base cleanup/free, vector-delete guard size `0x2fc`, primary vtable cell `SliderControlPane`. |
| `0x0049b7a0` | `0xb4` bytes; restores three `TextButtonControlPane` vtable views, releases `+0x10c` text buffer/helper, calls base cleanup/free. |
| `0x0049b860` | `0x67` bytes; restores three `TextButtonExControlPane` vtable views, deletes `+0x10c` provider child, calls base cleanup/free. |

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score Recommendation | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0049af11-0x0049af27` | `0002XV` | Shared ButtonControlPane-family destructor adjustor pair | `FALSE` | `NONE` | `82/88 -> 86/90` | Rename or clarify from SelectBox-only. |
| `0x0049af69-0x0049af7f` | `0002XY` | ImageButton destructor adjustor pair | `FALSE` | `NONE` | `82/88 -> 86/90` | Keep title. |
| `0x0049af95-0x0049afab` | `0002Y9` | PopupMenu destructor adjustor pair | `FALSE` | `NONE` | `82/88 -> 86/90` | Keep title. |
| `0x0049afab-0x0049afc1` | `0002YB` | RadioGroup destructor adjustor pair | `FALSE` | `NONE` | `82/88 -> 86/90` | Keep title. |
| `0x0049b003-0x0049b019` | `0002Y2` | Slider destructor adjustor pair | `FALSE` | `NONE` | `82/88 -> 86/90` | Keep title. |
| `0x0049b05b-0x0049b071` | `0002YD` | TextButton destructor adjustor pair | `FALSE` | `NONE` | `82/88 -> 86/90` | Keep title. |
| `0x0049b071-0x0049b087` | `0002Y6` | TextButtonEx destructor adjustor pair | `FALSE` | `NONE` | `82/88 -> 86/90` | Keep title. |

## Documentation Evidence And IDA Status

- [UID:00011Y] correctly classifies the aggregate as a non-reconstructable destructor/thunk index, but it has stale text for the ImageButton scalar destructor assignment and does not list the seven target children in supervisor-owned `by-memory/-coverage-report.md`.
- [UID:0002XZ] ImageButton scalar destructor now says `85/88`, assigned to [UID:00006D]; this contradicts the stale aggregate backlog row saying it is `84/88` and unassigned.
- [UID:0002Z7] and [UID:0002Z8] directly document Weather/Raining vtable slots pointing to `0x0049b0d0`, `0x0049af11`, and `0x0049af1c`, supporting the [UID:0002XV] shared-thunk correction.
- Generated `auto-generated/-ag-memory-coverage.md` lists all seven primary targets as `not_reconstructable` with `NONE` owner/emitter state. That state is correct.
- `project-level/-auto-completion-stats.md` lists all seven targets in low-score sections at `82/88`, confirming why score-only remediation is needed.

## Ranked Ownership Analysis

### 1. Keep adjustor pages ownerless/non-emitting and route source through declarations

- Evidence for: vtable-only inbound refs, raw bytes are pure `this` adjustment plus tail jump, `RECONSTRUCTABLE:FALSE` is already correct, and source declarations/classes own the vtable layout.
- Evidence against: related class pages are the semantic reason the thunks exist, so body text must name them.
- Decision: accepted. Keep metadata `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter and blank C++.

### 2. Assign adjustor pages to direct classes

- Evidence for: each thunk pair is associated with class vtable views; six pairs are class-specific.
- Evidence against: the pages are compiler/linker-generated and would pollute generated output/routing; [UID:0002XV] is shared across several classes.
- Decision: rejected.

### 3. Merge adjustor pages into scalar destructor pages

- Evidence for: each pair only jumps to a scalar deleting destructor.
- Evidence against: exact child pages already preserve byte/range coverage, and neighboring `by-memory/-coverage-report.md` already lists other exact adjustor children separately.
- Decision: rejected. Keep as exact child pages.

### Proposed new file/grouping

- No new file/grouping is needed.
- Source placement remains:
  - `ButtonControlPane.cpp` for `ButtonControlPane`, `ImageButtonControlPane`, `RadioGroupControlPane`, `SliderControlPane`, `TextButtonExControlPane`, and related shared family declarations.
  - `TextButtonControlPane.cpp` for the narrower `TextButtonControlPane` class page/direct file route.
  - `PopupMenuControls.cpp` for `PopupMenuControlPane`.
  - `WeatherLayerPane.cpp` / `RainingLayerPane.cpp` own their class vtable data, but their use of the shared `0x0049b0d0` wrapper does not make [UID:0002XV] weather-owned.

## Exact Target Metadata Recommendations

Apply to each primary target:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Do not add reconstruction C++.

Recommended filename/title change for [UID:0002XV]:

```text
by-memory/0x0049af11-0x0049af27.ButtonControlPaneSharedDeletingDestructorAdjustorThunks.md

# 0x0049af11-0x0049af27 ButtonControlPane Shared Deleting-Destructor Adjustor Thunks
```

If supervisor declines the rename, keep the path but replace the title with:

```text
# 0x0049af11-0x0049af27 SelectBox/ButtonControl Shared Adjustor Thunks
```

## Exact Support-Doc Text To Add / Replace

### Shared text for all seven target pages

Add this under each target `## Evidence` section, adjusted with that page's row from the table above:

```text
- 2026-06-16 B001 live IDA MCP source-quality recheck confirms the exact raw thunk bytes, not just the old function-size summary. The pair is two 11-byte functions: `sub ecx, 0A0h; jmp <scalar deleting destructor>` and `sub ecx, 0A4h; jmp <same scalar deleting destructor>`.
- The `0xA0` and `0xA4` adjusted-this offsets match the secondary and tertiary vtable views in the related class layout. The only inbound references are vtable/data cells; there are no normal code callers.
- This page should remain `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, with blank `EMITTER_UIDS` and blank final C++. The source-level work is the related class declaration/vtable/destructor relationship; these exact stubs are compiler-generated MSVC adjustor glue.
```

### [UID:0002XV] replacement Status/Evidence note

Replace the current related-class-only wording with:

```text
- Related classes: [UID:00001E][ButtonControlPane](by-class/ButtonControlPane.md), [UID:0000CQ][SelectBoxControlPane](by-class/SelectBoxControlPane.md), [UID:0000G1][WeatherLayerPane](by-class/WeatherLayerPane.md), and [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md).
- Source direction: shared `ButtonControlPane`-family deleting-destructor adjustor glue. The current SelectBox-only label is too narrow because live IDA shows `ButtonControlPane`, `SelectBoxControlPane`, `WeatherLayerPane`, and `RainingLayerPane` secondary vtable cells all reference these same two thunks.
- 2026-06-16 B001 live IDA MCP xrefs: `0x0049af11` is referenced from `0x00617c40`, `0x0061d528`, `0x006311e4`, and `0x00631274`; `0x0049af1c` is referenced from `0x00617c70`, `0x0061d558`, `0x00631214`, and `0x006312a4`. Named data cells identify these as `ButtonControlPane`, `SelectBoxControlPane`, `WeatherLayerPane`, and `RainingLayerPane` secondary vtable views.
- Both thunks tail-jump to the shared scalar deleting wrapper at `0x0049b0d0`, whose live decompilation only calls shared pane cleanup `0x00544580`, optional free `0x004f4ac0`, and the vector-delete guard path with object-size constant `0x10c`.
```

### [UID:00011Y] aggregate ImageButton row replacement

Replace the ImageButton backlog row in `## Remaining Split And Gate Backlog` with:

```text
| ImageButtonControlPane | [UID:0002XY][0x0049af69-0x0049af7f.ImageButtonControlPaneAdjustorThunks](by-memory/0x0049af69-0x0049af7f.ImageButtonControlPaneAdjustorThunks.md), [UID:0002XZ][0x0049b290-0x0049b2e5.ImageButtonControlPaneScalarDeletingDestructor](by-memory/0x0049b290-0x0049b2e5.ImageButtonControlPaneScalarDeletingDestructor.md), [UID:00006D][ImageButtonControlPane](by-class/ImageButtonControlPane.md) `85/88`, [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) `86/88`. | Split done; scalar deleting destructor is assigned to [UID:00006D][ImageButtonControlPane](by-class/ImageButtonControlPane.md) because child and direct class parent both meet `85/85`. Adjustors remain ignored/unassigned compiler glue. |
```

### [UID:00011Y] aggregate SelectBox row replacement

Replace the SelectBox row with:

```text
| ButtonControlPane / SelectBox shared no-extra-teardown thunk pair | [UID:0002XV][0x0049af11-0x0049af27.SelectBoxControlPaneAdjustorThunks](by-memory/0x0049af11-0x0049af27.SelectBoxControlPaneAdjustorThunks.md), [UID:0002XW][0x0049b0d0-0x0049b10b.SelectBoxControlPaneScalarDeletingDestructor](by-memory/0x0049b0d0-0x0049b10b.SelectBoxControlPaneScalarDeletingDestructor.md), [UID:00001E][ButtonControlPane](by-class/ButtonControlPane.md), [UID:0000CQ][SelectBoxControlPane](by-class/SelectBoxControlPane.md), [UID:0000G1][WeatherLayerPane](by-class/WeatherLayerPane.md), and [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md). | Split done; the adjustor pair is shared compiler glue for secondary vtable views that tail-jump to the shared `0x0049b0d0` scalar deleting wrapper. Do not assign or emit the adjustor page. Consider renaming the page away from SelectBox-only wording. |
```

### [UID:0002XW] scalar destructor clarification

Add this under [UID:0002XW] Evidence:

```text
- 2026-06-16 B001 live IDA MCP recheck shows this wrapper is shared by primary vtable cells for `ButtonControlPane` (`0x00617bd8`), `SelectBoxControlPane` (`0x0061d4c0`), `WeatherLayerPane` (`0x00631190`), and `RainingLayerPane` (`0x00631220`). The existing SelectBox scalar-destructor title is therefore a narrow descriptive alias, not exclusive ownership evidence.
- The wrapper body performs only shared pane cleanup, optional allocator free, and a vector-delete guard path with size `0x10c`; it does not restore SelectBox-specific vtables or release SelectBox-owned fields.
```

## Exact Supervisor-Owned `by-memory/-coverage-report.md` Rows

Placement context: insert the primary adjustor rows around existing lines for [UID:00011Y], [UID:00011Z], [UID:000120], [UID:000121], [UID:000122], and the scalar destructor rows around existing [UID:000123], [UID:0002XZ], [UID:000124], [UID:000125], [UID:000126], [UID:000127], [UID:0002YE], and [UID:000128].

Recommended insertions:

```text
    - [UID:0002XV][0x0049af11-0x0049af27.SelectBoxControlPaneAdjustorThunks](by-memory/0x0049af11-0x0049af27.SelectBoxControlPaneAdjustorThunks.md) 0x0049af11-0x0049af27 | compiler adjustor thunk pair | ButtonControlPaneSharedDeletingDestructorAdjustorThunks : ignored : 86% : very-strong : Live IDA confirms exact bytes, two 0x0b functions subtracting `this` by `0xA0`/`0xA4` and tail-jumping to shared scalar wrapper `0x0049b0d0`; vtable/data refs prove shared ButtonControlPane, SelectBoxControlPane, WeatherLayerPane, and RainingLayerPane secondary-view use. Keep non-reconstructable/no-owner with blank final C++.
    - [UID:0002XY][0x0049af69-0x0049af7f.ImageButtonControlPaneAdjustorThunks](by-memory/0x0049af69-0x0049af7f.ImageButtonControlPaneAdjustorThunks.md) 0x0049af69-0x0049af7f | compiler adjustor thunk pair | ImageButtonControlPaneAdjustorThunks : ignored : 86% : very-strong : Live IDA confirms exact bytes, two 0x0b functions subtracting `this` by `0xA0`/`0xA4` and tail-jumping to `0x0049b290`; vtable/data refs `0x00617e34`/`0x00617e64` identify ImageButtonControlPane secondary views. Keep non-reconstructable/no-owner with blank final C++.
    - [UID:0002Y9][0x0049af95-0x0049afab.PopupMenuControlPaneAdjustorThunks](by-memory/0x0049af95-0x0049afab.PopupMenuControlPaneAdjustorThunks.md) 0x0049af95-0x0049afab | compiler adjustor thunk pair | PopupMenuControlPaneAdjustorThunks : ignored : 86% : very-strong : Live IDA confirms exact bytes, two 0x0b functions subtracting `this` by `0xA0`/`0xA4` and tail-jumping to `0x0049b3b0`; vtable/data refs `0x00618020`/`0x00618050` identify PopupMenuControlPane secondary views. Keep non-reconstructable/no-owner with blank final C++.
    - [UID:0002YB][0x0049afab-0x0049afc1.RadioGroupControlPaneAdjustorThunks](by-memory/0x0049afab-0x0049afc1.RadioGroupControlPaneAdjustorThunks.md) 0x0049afab-0x0049afc1 | compiler adjustor thunk pair | RadioGroupControlPaneAdjustorThunks : ignored : 86% : very-strong : Live IDA confirms exact bytes, two 0x0b functions subtracting `this` by `0xA0`/`0xA4` and tail-jumping to `0x0049b420`; vtable/data refs `0x00617ed8`/`0x00617f08` identify RadioGroupControlPane secondary views. Keep non-reconstructable/no-owner with blank final C++.
    - [UID:0002Y2][0x0049b003-0x0049b019.SliderControlPaneAdjustorThunks](by-memory/0x0049b003-0x0049b019.SliderControlPaneAdjustorThunks.md) 0x0049b003-0x0049b019 | compiler adjustor thunk pair | SliderControlPaneAdjustorThunks : ignored : 86% : very-strong : Live IDA confirms exact bytes, two 0x0b functions subtracting `this` by `0xA0`/`0xA4` and tail-jumping to `0x0049b5b0`; vtable/data refs `0x00617f7c`/`0x00617fac` identify SliderControlPane secondary views. Keep non-reconstructable/no-owner with blank final C++.
    - [UID:0002YD][0x0049b05b-0x0049b071.TextButtonControlPaneAdjustorThunks](by-memory/0x0049b05b-0x0049b071.TextButtonControlPaneAdjustorThunks.md) 0x0049b05b-0x0049b071 | compiler adjustor thunk pair | TextButtonControlPaneAdjustorThunks : ignored : 86% : very-strong : Live IDA confirms exact bytes, two 0x0b functions subtracting `this` by `0xA0`/`0xA4` and tail-jumping to `0x0049b7a0`; vtable/data refs `0x00617ce8`/`0x00617d18` identify TextButtonControlPane secondary views. Keep non-reconstructable/no-owner with blank final C++.
    - [UID:0002Y6][0x0049b071-0x0049b087.TextButtonExControlPaneAdjustorThunks](by-memory/0x0049b071-0x0049b087.TextButtonExControlPaneAdjustorThunks.md) 0x0049b071-0x0049b087 | compiler adjustor thunk pair | TextButtonExControlPaneAdjustorThunks : ignored : 86% : very-strong : Live IDA confirms exact bytes, two 0x0b functions subtracting `this` by `0xA0`/`0xA4` and tail-jumping to `0x0049b860`; vtable/data refs `0x00617d90`/`0x00617dc0` identify TextButtonExControlPane secondary views. Keep non-reconstructable/no-owner with blank final C++.
```

Related scalar destructor rows that are currently missing from the shared report and should be inserted for consistency:

```text
    - [UID:0002XW][0x0049b0d0-0x0049b10b.SelectBoxControlPaneScalarDeletingDestructor](by-memory/0x0049b0d0-0x0049b10b.SelectBoxControlPaneScalarDeletingDestructor.md) 0x0049b0d0-0x0049b10b | shared scalar deleting destructor | ButtonControlPaneSharedScalarDeletingDestructor : reconstructable : 86% : strong : Assigned to SelectBoxControlPane class historically, but live IDA shows shared primary-vtable use by ButtonControlPane, SelectBoxControlPane, WeatherLayerPane, and RainingLayerPane; exact wrapper calls shared pane cleanup, optional free, and vector-delete guard size `0x10c`. Keep final C++ blank because this is source-declared/generated-binary destructor glue.
    - [UID:0002YA][0x0049b3b0-0x0049b417.PopupMenuControlPaneScalarDeletingDestructor](by-memory/0x0049b3b0-0x0049b417.PopupMenuControlPaneScalarDeletingDestructor.md) 0x0049b3b0-0x0049b417 | scalar deleting destructor | PopupMenuControlPaneScalarDeletingDestructor : reconstructable : 86% : strong : Assigned to direct class parent [UID:0000AN][PopupMenuControlPane](by-class/PopupMenuControlPane.md); exact wrapper restores PopupMenu vtable views, releases owned helper at `+0x108`, calls shared pane cleanup/free, and is reached by the two adjustor thunk branches plus primary vtable cell `0x00617fb8`.
    - [UID:0002YC][0x0049b420-0x0049b487.RadioGroupControlPaneScalarDeletingDestructor](by-memory/0x0049b420-0x0049b487.RadioGroupControlPaneScalarDeletingDestructor.md) 0x0049b420-0x0049b487 | scalar deleting destructor | RadioGroupControlPaneScalarDeletingDestructor : reconstructable : 86% : strong : Assigned to direct class parent [UID:0000BI][RadioGroupControlPane](by-class/RadioGroupControlPane.md); exact wrapper restores RadioGroup vtable views, releases owned helper at `+0x108`, calls shared pane cleanup/free, and is reached by the two adjustor thunk branches plus primary vtable cell `0x00617e70`.
    - [UID:0002Y3][0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor](by-memory/0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor.md) 0x0049b5b0-0x0049b5eb | scalar deleting destructor | SliderControlPaneScalarDeletingDestructor : reconstructable : 86% : strong : Assigned to direct class parent [UID:0000DB][SliderControlPane](by-class/SliderControlPane.md); exact wrapper calls shared pane cleanup/free, has vector-delete guard size `0x2fc`, and is reached by two adjustor branches plus primary vtable cell `0x00617f14`.
    - [UID:0002Y7][0x0049b860-0x0049b8c7.TextButtonExControlPaneScalarDeletingDestructor](by-memory/0x0049b860-0x0049b8c7.TextButtonExControlPaneScalarDeletingDestructor.md) 0x0049b860-0x0049b8c7 | scalar deleting destructor | TextButtonExControlPaneScalarDeletingDestructor : reconstructable : 86% : strong : Assigned to direct class parent [UID:0000EK][TextButtonExControlPane](by-class/TextButtonExControlPane.md); exact wrapper restores TextButtonEx vtable views, releases child provider at `+0x10c`, calls shared pane cleanup/free, and is reached by two adjustor branches plus primary vtable cell `0x00617d24`.
```

## Negative Evidence Summary

- No normal code callers were found for any primary adjustor thunk. All inbound xrefs are data/vtable cells.
- No source-authored behavior exists inside the target ranges: the functions do not read fields, call helpers, branch on flags, allocate, free, or perform control logic.
- Address adjacency inside the destructor band does not prove a single source owner. The aggregate spans multiple UI/control owners and explicit non-button exclusions.
- [UID:0002XV] cannot safely remain SelectBox-only in body text because direct IDA named-data evidence contradicts that narrow ownership.

## Final Recommendation

- Raise all seven primary targets to `86/90`.
- Keep all seven `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitters, blank C++.
- Rename or clarify [UID:0002XV] as shared ButtonControlPane-family deleting-destructor adjustor glue.
- Add exact byte/xref support text to each target.
- Update [UID:00011Y] stale ImageButton backlog row and shared SelectBox/ButtonControl wording.
- Add missing supervisor-owned `by-memory/-coverage-report.md` rows for all seven primary target pages and the missing related scalar destructor pages.
- No IDA DB edit is recommended. The current IDA labels are generic `sub_...`; documentation can carry descriptive names without forcing IDA renames.

## Follow-Up Actions

- Supervisor: apply target/support/coverage edits above or assign an A/C agent to do the by-* edits under lease.
- A-agent: if applying edits, validate every touched target page, related scalar destructor page, aggregate/support pages, and `by-memory/-coverage-report.md`.
- B001: no additional B-agent split research is needed unless supervisor wants a broader audit of the shared `0x0049b0d0` ButtonControlPane/Weather/Raining destructor-wrapper naming.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for `86/90`; not high enough for `95+`.
- Remaining uncertainty: exact original header/source split and class declaration spellings needed to regenerate identical MSVC thunk layout are still not final-source complete.

## Validator Results

Commands run for research evidence:

> Executable block R001 was removed from this report and preserved verbatim in [0002XV-0002Y6-ui-control-adjustor-thunk-source-quality-removed.md](0002XV-0002Y6-ui-control-adjustor-thunk-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Report validation attempts after saving:

> Executable block R002 was removed from this report and preserved verbatim in [0002XV-0002Y6-ui-control-adjustor-thunk-source-quality-removed.md](0002XV-0002Y6-ui-control-adjustor-thunk-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Results: validator did not validate this research report because the file is outside direct by-* folders. First attempt resolved through the validator's configured `C:\FastStorage\NTK_Sources\source-3\project-documentation` root and reported file not found before the report was moved to the required `E:\NTK...source-3\project-documentation` path. Second attempt with the absolute `E:\NTK...` path reported: `file is outside direct by-* folders`. This is a validator scope limitation for Agent research reports, not a by-* documentation validation failure.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B001/research/0002XV-0002Y6-ui-control-adjustor-thunk-source-quality.md`
- Modified: none outside Agent-B001 research.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002XV-0002Y6-ui-control-adjustor-thunk-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002XV"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002XV-0002Y6-ui-control-adjustor-thunk-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0002XV-0002Y6-ui-control-adjustor-thunk-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002XV"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
