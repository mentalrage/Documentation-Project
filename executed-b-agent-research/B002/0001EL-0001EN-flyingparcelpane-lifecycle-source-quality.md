** TARGET-REPORT-UID:0001EL **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001EL / 0001EN FlyingParcelPane Lifecycle Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation:
  - [UID:0001EL] `0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart` should become a reviewed, non-emitting split inventory/container over exact child source bodies [UID:0002R5] and [UID:0002R6]. Keep the documentation owner as [UID:000058] `FlyingParcelPane`, but set `RECONSTRUCTABLE:FALSE` and clear `EMITTER_UIDS`.
  - [UID:0001EN] `FlyingParcelPaneScalarDeletingDestructor` should stay attached to [UID:000058] `FlyingParcelPane`, stay `RECONSTRUCTABLE:TRUE`, and rise to `86/91`, but its formal C++ block must remain blank because this is the MSVC deleting-destructor wrapper generated from the source-declared `virtual ~FlyingParcelPane()`.
- Final disposition:
  - `0001EL`: non-emitting aggregate/index, recommended `88/91`.
  - `0001EN`: reconstructable binary wrapper with generated-source policy documented, recommended `86/91`.
- Required action:
  - Correct [UID:0001EN]'s half-open byte range to `0x00546ed0-0x00546f37`; the current `...0x00546f36` path/range omits the last byte of the final `ret 4` under the project half-open convention.
  - Add ignored padding row `0x00546f37-0x00546f40`.
  - Refresh stale coverage rows for `0001EL`, nested `0002R5`/`0002R6`, and `0001EN`.
- Confidence: high for source placement, range, aggregate-vs-child policy, destructor wrapper policy, and field/global names; medium for the original source spelling of the raw start-animation method because no direct caller or pointer survives.

## Supporting Research

## Target

- Target UIDs:
  - [UID:0001EL] `by-memory/0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart.md`, current `82/88`, owner/emitter [UID:000058] `FlyingParcelPane`.
  - [UID:0001EN] `by-memory/0x00546ed0-0x00546f36.FlyingParcelPaneScalarDeletingDestructor.md`, current `82/88`, owner/emitter [UID:000058] `FlyingParcelPane`.
- Source queue/report row: `B002-goal2-flyingparcelpane-lifecycle-source-quality-0001EL-0001EN-20260617`.
- Current supervisor classification: report-only B-agent source-quality/source-inference work; no direct edits to by-* docs, generated output, IDA DB, source files, or `by-memory/-coverage-report.md`.
- Direct source route: `NexusTK/ui/panels/ParcelPane.cpp` through [UID:0000MF] `ParcelPane` file and [UID:000058] `FlyingParcelPane` class.

## Executive Recommendation

[UID:0001EL] is not a source method and should not emit C++. It is an address-contiguous lifecycle/start island that already has exact child pages:

| Range | UID | Role | Recommendation |
| --- | --- | --- | --- |
| `0x00546b80-0x00546bb5` | [UID:0002R5] | `FlyingParcelPane` non-deleting cleanup destructor body | Keep as exact reconstructable raw class method under [UID:000058]; source-facing shape is `FlyingParcelPane::~FlyingParcelPane()` cleanup. |
| `0x00546bb5-0x00546bc0` | ignored | `0xcc` alignment | Keep ignored padding. |
| `0x00546bc0-0x00546d64` | [UID:0002R6] | `FlyingParcelPane::StartAnimation` / configure delivery animation raw body | Keep as exact reconstructable raw class method under [UID:000058]; field/global/helper names can now be improved. |

The parent aggregate should be reclassified from `RECONSTRUCTABLE:TRUE` to `RECONSTRUCTABLE:FALSE`, because emitting it would duplicate the two exact child bodies and padding. This matches existing project treatment for duplicate/helper-island inventory rows.

[UID:0001EN] is a valid reconstructable binary artifact but not a handwritten source method. Keep it under `FlyingParcelPane`, score it above the gate after correcting the range and wrapper policy, and leave formal C++ blank. The source-level destructor should be represented by the ordinary destructor body/source declaration, not by manually authoring a scalar deleting destructor wrapper.

## Supervisor Active Recheck

- The assignment requested raw-start/no-IDA-function treatment, child-vs-aggregate emission policy, helper/field/global naming, scheduler semantics, scalar deleting destructor policy, exact range/padding, support-doc updates, final C++ policy, and exact coverage row text.
- No split creation is needed: [UID:0002R5] and [UID:0002R6] already exist and exactly cover [UID:0001EL]'s source-bearing subranges, with the internal `0xcc` gap recorded.
- No direct by-* edits were made. Existing by-memory files for `0001EL` and `0001EN` already had unrelated working-tree metadata/link changes when checked; this report treats those as other-agent changes and does not revert them.

## Inference Research Guidance Check

- `by-structure.md` and the current Supervisor rule 20 require final C++ only when the item is reconstructable, has a valid emitter route, and `(completion + confidence) / 2 > 85`, and still allow blank formal C++ when source shape, wrapper policy, or split/range safety blocks direct code entry.
- Existing documentation was treated as a lead, not authority. The class/file/layout/vtable pages are largely validated, while the `0001EL` parent-emitter status and `0001EN` source-authored wording are stale.
- IDA facts, PE byte scans, and existing documentation evidence agree on `FlyingParcelPane` class/file placement. The main inference is source-facing naming for raw helper bodies, not ownership.

## Heuristic / Inference Reanalysis And Validation

### Raw Aggregate And Child Emission Policy

- Best defensible direction: [UID:0001EL] is a non-source aggregate/index over two exact source-bearing children and padding. It should be non-emitting.
- Evidence checked:
  - IDA reports no function at `0x00546b80`, `0x00546bb5`, `0x00546bc0`, or `0x00546d64`.
  - Existing child pages cover `0x00546b80-0x00546bb5` and `0x00546bc0-0x00546d64` exactly, with padding at `0x00546bb5-0x00546bc0` and successor padding `0x00546d64-0x00546d70`.
  - PE scan found zero absolute VA pointer hits, zero RVA pointer hits, and zero rel32 call/jump edges to `0x00546b80` and `0x00546bc0`.
  - The active generated route currently lists the parent and children under [UID:000058], which would be duplicate emission if formal C++ were entered at both levels.
- Rejected alternatives:
  - Keep `0001EL` reconstructable/emitting: rejected because it has no single source method shape and duplicates child coverage.
  - Mark `0002R5`/`0002R6` ignored as dead code: rejected because their bodies are substantial class-specific behavior with vtable, layout, resource, and sibling-method evidence.
  - Merge the raw cleanup/start bodies with the constructor: rejected because constructor ends at `0x00546b74`, there is `0xcc` padding through `0x00546b80`, and both raw bodies have independent prolog/control-flow shapes.
- Impact: raise `0001EL` confidence as an audited split inventory, but set `RECONSTRUCTABLE:FALSE`, clear emitters, and keep formal C++ blank.

### Cleanup Destructor Body [UID:0002R5]

- Best source-facing direction: non-deleting ordinary destructor cleanup body for `FlyingParcelPane::~FlyingParcelPane()`.
- Evidence checked:
  - Raw body writes the three `FlyingParcelPane` vtable bases at `0x00621ccc`, `0x00621d18`, and `0x00621d48`, releases the owned pointer at `this+0x100` through virtual slot 0 with deleting flag `1`, and tail-jumps to `Pane` base cleanup at `0x00544580`.
  - The constructor [UID:0002KJ] allocates an 8-byte helper at `+0x100` and installs the same vtable family.
  - The scalar deleting destructor [UID:0001EN] contains the same cleanup sequence plus optional storage free.
- Rejected alternatives:
  - Source-authored free helper: rejected because vtable resets and base destructor tail-call are destructor-body patterns.
  - Compiler-only thunk: rejected because it performs real class cleanup, not an adjustor-only jump.
- Impact: update support docs to call this an ordinary destructor cleanup body. It is the source-level destructor body candidate; formal C++ should be coordinated with `0001EN` wrapper policy and not entered through the `0001EL` aggregate.

### Start / Configure Animation Body [UID:0002R6]

- Best source-facing name/signature:
  - Descriptive source-facing name: `FlyingParcelPane::StartAnimation`.
  - More explicit accepted alias: `FlyingParcelPane::StartDeliveryAnimation`.
  - Best signature direction: `void __thiscall FlyingParcelPane::StartAnimation(unsigned char parcelCountOrState, unsigned char leftSlot, unsigned char rightSlot, bool isParcel);`
- Evidence checked:
  - The body ends with `ret 0x10`, proving four stack parameters.
  - Parameter stores are: arg1 to `+0xf9`, arg2 to `+0xfb`, arg3 to `+0xfa`, arg4 to `+0xfc`.
  - It clears `+0xf8`, configures rectangles, attaches/updates the `+0x100` helper through `g_pScreenPane`, invalidates/repositions through pane virtual slots, and schedules the tertiary timer callback.
  - [UID:0002KK] `AnimateStep` consumes `+0xf8/+0xf9/+0xfa/+0xfb`, removes the helper via `ScreenPane::RemoveLayer`, and hands `+0xf9/+0xfb/+0xfa` to `ParcelPaneSetParcelSlotData`.
  - [UID:0002KL] `DrawParcelOrLetter` consumes `+0xfc` to choose parcel art (`ALERTBTN`) versus letter art (`LETTER`).
- Rejected alternatives:
  - Generic `ConfigureLayer`/`ShowPane`: rejected because the payload and sibling handoff are parcel-notification specific.
  - `StartLetterAnimation` only: rejected because `+0xfc` is a mode flag and both parcel and letter art paths are supported.
  - Treat as constructor-inline duplicate: rejected because it has four external parameters, timer scheduling, and runtime branch behavior not matched by construction.
- Impact: support docs can stop using vague helper/global blockers and name the method descriptively. Direct original source callsite is still not proven, so child formal C++ should remain blank until a child-specific final-C++ pass decides how to represent raw no-xref methods.

### Field Names And Types

Best defensible `FlyingParcelPane` field names:

| Offset | Current observed use | Recommended source-facing name/type |
| --- | --- | --- |
| `+0xf8` | Cleared by start body; incremented by `AnimateStep`; compared with `30`. | `unsigned char m_animationFrame` or `m_flyingFrame`. |
| `+0xf9` | First start arg; passed to `ParcelPaneSetParcelSlotData` after animation. | `unsigned char m_parcelCountOrState`; document as parcel payload/state byte. |
| `+0xfa` | Third start arg; passed as right slot payload after animation. | `unsigned char m_rightSlot`. |
| `+0xfb` | Second start arg; passed as left slot payload after animation. | `unsigned char m_leftSlot`. |
| `+0xfc` | Fourth start arg; draw switch: nonzero uses `ALERTBTN`, zero uses `LETTER`. | `bool m_isParcel` or `unsigned char m_isParcelMode`. |
| `+0x100` | 8-byte owned helper allocated by constructor, attached/removed through `ScreenPane` layer helpers, deleted by destructor. | `Layer *m_animationLayer` / `m_screenLayerEntry`; exact class name inferred from the `Layer` constructor and ScreenPane layer-list usage. |

Rejected field/type alternatives:

- `RenderBuffer *`, `SpriteFrame *`, or `ObjectPane *` for `+0x100`: rejected because the object is 8 bytes, constructed by the same `Layer`-style constructor used for global UI layer slots, passed to `ScreenPane::SetLayerFrame`/`RemoveLayer`, and destroyed through a vtable deleting call. The active generated `class_FlyingParcelPane.cpp` names are polluted by decompiler guesses.
- `+0xfc` as animation-state byte: rejected because [UID:0002KL] uses it only to select parcel versus letter draw resources.
- `+0xfa/+0xfb` as coordinates: rejected because [UID:0002KK] passes them to parcel-slot data handoff, while coordinates are immediate constants and pane inherited fields.

### Globals, Helpers, And Timer Semantics

- `byte_66DA97`: best existing name is `g_useEpfAssets`. It is a one-byte asset/UI layout selector initialized to `1` and written by `StartupWindow`, not a parcel-specific flag. In `StartAnimation`, `g_useEpfAssets == 1` takes the current EPF/layout branch.
- `dword_67A7CC`: `g_pScreenPane`. `0x00556ce0` is the ScreenPane layer attach/update helper, documented as `ScreenPane::SetLayerFrame`; `0x00556d20` is `ScreenPane::RemoveLayer`.
- `dword_67A7D0`: `g_pSoundManager`. `0x0057a5c0` is `SoundManager::PlaySample`; `StartAnimation` uses sample id `200` and volume `100` on the current EPF/layout branch.
- `0x005975e0`: timer/scheduler wrapper. The start body schedules the tertiary callback with `100 ms` in the `g_useEpfAssets == 1` branch and `10 ms` in the legacy branch; [UID:0002KK] reschedules the animation step every `10 ms` until frame `30`.
- `g_pParcelPane`: the handoff target in [UID:0002KK], not the owner of [UID:0002R6]. It receives completed slot payload data after the flying animation finishes.

Rejected alternatives:

- `byte_66DA97` as a parcel animation flag: rejected because the global has hundreds of broader UI asset-layout references and a StartupWindow write site.
- Source placement under `ScreenPane`, `Layer`, `SoundManager`, or `TimerHandler`: rejected because those are service dependencies; the fields, vtables, resources, and sibling methods are `FlyingParcelPane`/parcel notification code.

### Scalar Deleting Destructor [UID:0001EN]

- Best source direction: MSVC scalar deleting destructor wrapper generated for `FlyingParcelPane` from the source-declared virtual destructor. It is reconstructable as a binary behavior target but should not receive handwritten source C++.
- Evidence checked:
  - IDA function `sub_546ED0`, size `0x67`.
  - Primary vtable data ref at `0x00621ccc`.
  - Secondary and tertiary adjustor thunks jump to the wrapper from `0x00546e91` and `0x00546e9c`.
  - The wrapper restores the primary/secondary/tertiary vtables, deletes `this+0x100` with flag `1`, calls base cleanup `0x00544580`, and conditionally frees object storage through `0x004f4ac0`.
  - Decompilation shows flag behavior equivalent to: free only when `(flags & 1) != 0 && (flags & 4) == 0`; otherwise return `this`.
  - Raw bytes show the final instruction `C2 04 00` at `0x00546f34-0x00546f36`, so the half-open range is `0x00546ed0-0x00546f37`.
- Rejected alternatives:
  - Source-authored `FlyingParcelPaneScalarDeletingDestructor` function: rejected because the name and flag ABI are compiler-generated deleting-destructor support, not a C++ source declaration.
  - `RECONSTRUCTABLE:FALSE`: rejected because project policy for class deleting destructors generally keeps the wrapper reconstructable/visible when it participates in vtables and delete routing; the source C++ block is simply blank.
  - Attach to [UID:0000MF] file only: rejected because the vtable slot and adjustor thunks prove direct class ownership, while file ownership is only the emitted source-file route.
- Impact: update wording from "source-authored scalar deleting destructor" to "source-declared destructor / generated binary scalar deleting destructor wrapper"; keep owner/emitter [UID:000058]; raise score to `86/91`; blank formal C++.

### Generated Output And Existing Docs

- Active generated/simroot `class_FlyingParcelPane.cpp` omits the raw cleanup/start bodies and uses polluted names such as `RenderBuffer`, `ObjectPane`, and generic helper labels. Treat it as evidence of current generator gaps, not source truth.
- [UID:000058] `FlyingParcelPane`, [UID:0000MF] `ParcelPane`, [UID:0001VI] layout, [UID:0002OH] vtable data, [UID:0001EM] adjustor thunks, [UID:0002KK] animate step, and [UID:0002KL] draw body all support `FlyingParcelPane` source placement.
- Existing A-agent notes for [UID:0002R5] and [UID:0002R6] were useful leads and agree on raw/no-function starts, but the remaining helper/global blockers can now be narrowed to the names listed above.

## Evidence Standards Used

- IDA facts: function lookup, decompilation of modeled functions, xrefs to vtable entries and wrapper starts, callees, and exact byte ranges.
- PE-aware facts: direct scan for absolute VA literals, RVA literals, and rel32 call/jump edges to raw starts and wrapper starts.
- Documentation evidence: class/file/layout/vtable/global docs, existing child pages, generated memory coverage, and A-agent supervisor notes.
- Negative evidence: no IDA function at raw starts, no direct IDA xrefs to raw starts, no PE direct-edge or pointer evidence for raw starts, and generated output omissions.

This evidence is strong enough for owner/source placement and wrapper policy. It is not strong enough to claim the original source spelling of `StartAnimation`; the recommended name is descriptive and source-facing, not original-proof.

## IDA / Binary Facts

- Function/range facts:
  - `0x00546b80`, `0x00546bb5`, `0x00546bc0`, and `0x00546d64`: not IDA function starts.
  - `0x00546d70`: `sub_546D70`, size `0x7e`, [UID:0002KK] animate step.
  - `0x00546df0`: `sub_546DF0`, size `0x7b`, [UID:0002KL] draw parcel/letter.
  - `0x00546ed0`: `sub_546ED0`, size `0x67`, [UID:0001EN] scalar deleting destructor wrapper.
  - `0x00546f40`: successor `sub_546F40`, ParcelIconPane scalar deleting destructor.
- Data/table/padding facts:
  - `0x00546bb5-0x00546bc0`: eleven `0xcc` bytes between cleanup and start bodies.
  - `0x00546d64-0x00546d70`: twelve `0xcc` bytes after start body before `AnimateStep`.
  - `0x00546f37-0x00546f40`: nine `0xcc` bytes after `FlyingParcelPane` scalar deleting destructor before `ParcelIconPane` scalar deleting destructor.
- Xref facts:
  - `xrefs_to 0x00546b80`: none.
  - `xrefs_to 0x00546bc0`: none.
  - `xrefs_to 0x00546ed0`: code jumps from `0x00546e91` and `0x00546e9c`, plus data ref from vtable slot `0x00621ccc`.
  - Vtable write/data evidence ties constructor, raw cleanup, and scalar wrapper to `0x00621ccc`, `0x00621d18`, and `0x00621d48`.
- PE scan facts:
  - Target `0x00546b80`: zero VA pointer hits, zero RVA pointer hits, zero rel32 call/jump hits.
  - Target `0x00546bc0`: zero VA pointer hits, zero RVA pointer hits, zero rel32 call/jump hits.
  - Target `0x00546ed0`: VA pointer hit at `0x00621ccc`; rel32 jumps from `0x00546e91` and `0x00546e9c`; zero RVA hits.
  - Target `0x00546d70`: VA pointer hit at `0x00621d4c`.
  - Target `0x00546df0`: VA pointer hit at `0x00621d10`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score Recommendation | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00546b80-0x00546d64` | [UID:0001EL] `FlyingParcelPaneRawLifecycleAndStart` | Aggregate/index over raw cleanup, padding, and raw start body | Recommend `FALSE` | Documentation owner [UID:000058] | `88/91` | Non-emitting split inventory |
| `0x00546b80-0x00546bb5` | [UID:0002R5] `FlyingParcelPaneCleanupDestructorBody` | Non-deleting destructor cleanup body | `TRUE` | [UID:000058] | keep at least `85/88`; coverage row should no longer say `78%` | Source-bearing child, C++ blank pending destructor coordination |
| `0x00546bc0-0x00546d64` | [UID:0002R6] `FlyingParcelPaneStartAnimation` | Start/configure delivery animation raw body | `TRUE` | [UID:000058] | keep at least `85/88`; coverage row should no longer say `80%` | Source-bearing child, C++ blank pending raw no-caller final pass |
| `0x00546ed0-0x00546f37` | [UID:0001EN] `FlyingParcelPaneScalarDeletingDestructor` | MSVC scalar deleting destructor wrapper | `TRUE` | [UID:000058] | `86/91` | Reconstructable wrapper, formal C++ blank |
| `0x00546f37-0x00546f40` | ignored | Alignment padding | `FALSE` | none | `100/strong` | Add ignored row |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00621ccc` | Data xref to `0x00546ed0`; primary vtable slot | Direct class ownership for scalar deleting destructor. |
| `0x00621d18` | Secondary `FlyingParcelPane` vtable | Adjustor thunk reaches scalar deleting destructor after subtracting `0xa0`. |
| `0x00621d48` | Tertiary `FlyingParcelPane` vtable | Adjustor thunk reaches scalar deleting destructor after subtracting `0xa4`; animate callback slot reaches [UID:0002KK]. |
| `0x00546e91` / `0x00546e9c` | Jumps to `0x00546ed0` | Compiler adjustor thunk paths into scalar deleting destructor. |
| `0x00556ce0` | ScreenPane layer attach/update helper | `StartAnimation` attaches or updates `m_animationLayer`. |
| `0x00556d20` | ScreenPane layer removal helper | `AnimateStep` removes `m_animationLayer` when animation completes. |
| `0x0057a5c0` | `SoundManager::PlaySample` | `StartAnimation` plays sound sample `200` at volume `100` in the current layout branch. |
| `0x005975e0` | Timer/scheduler wrapper | `StartAnimation` and `AnimateStep` schedule tertiary callback timing. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - [UID:000058] `FlyingParcelPane` class: field offsets, method inventory, and source-file route.
  - [UID:0000MF] `ParcelPane` file: parcel notification source family and PatchPane successor boundary.
  - [UID:0001EH] parcel notification aggregate: local executable island and class grouping.
  - [UID:0001VI] layout: FlyingParcelPane offsets at `+0xf8..+0x100`.
  - [UID:0002OH] and [UID:0001YE] vtable docs: primary/secondary/tertiary vtable slots.
  - [UID:0001EM] adjustor thunks: secondary/tertiary deleting-destructor entries.
  - [UID:0000SW]/[UID:0001OH] global docs: `byte_66DA97` as `g_useEpfAssets`.
  - [UID:0000S7]/[UID:0001OX] global docs: `dword_67A7CC` as `g_pScreenPane`.
  - [UID:00028R] and [UID:0001I9]: `dword_67A7D0` as `g_pSoundManager` and `0x0057a5c0` as `SoundManager::PlaySample`.
- Existing docs that are stale or incomplete:
  - [UID:0001EL] currently says reconstructable/emitting; it should be a non-emitting split inventory.
  - [UID:0001EL] says helper/global names are unresolved; the best names above should replace that open-ended wording.
  - [UID:0001EN] currently implies source-authored scalar deleting destructor handling; it should say source-declared destructor, generated scalar deleting wrapper.
  - [UID:0001EN] path/range should use half-open `0x00546ed0-0x00546f37`.
  - `by-memory/-coverage-report.md` stale rows still show `0002R5` at `78%`, `0002R6` at `80%`, and `0001EN` at `82%`.
- Generated/coverage state:
  - `auto-generated/-ag-memory-coverage.md` currently lists parent and children as emitting through [UID:000058], creating a duplicate-emission risk if the aggregate gets formal C++.
  - `auto-generated/NexusTK/ui/panels/ParcelPane.cpp` is currently zero bytes, so no active final source confirms or contradicts these C++ recommendations.

## Ranked Ownership Analysis

### 1. [UID:000058] FlyingParcelPane

- Evidence for:
  - Vtable writes and vtable data refs are exclusively `FlyingParcelPane`.
  - Fields `+0xf8..+0x100` are documented in the `FlyingParcelPane` layout and consumed by sibling `FlyingParcelPane` methods.
  - Constructor, cleanup, start, animate, draw, and scalar destructor are contiguous within the parcel notification source island.
  - [UID:0000MF] file route places the class in `NexusTK/ui/panels/ParcelPane.cpp`.
- Evidence against:
  - Raw starts `0x00546b80` and `0x00546bc0` have no direct caller/pointer evidence.
- Decision:
  - Accept [UID:000058] as direct class owner for exact source-bearing children and [UID:0001EN]. For [UID:0001EL], keep [UID:000058] as documentation owner only and clear emitters.

### 2. [UID:0000MF] ParcelPane File

- Evidence for:
  - The whole parcel notification executable island is file-local to `ParcelPane.cpp`.
  - Shared resources and globals tie ParcelIconPane, ParcelPane, and FlyingParcelPane together.
- Evidence against:
  - The target functions are class methods/wrappers, not free file helpers.
- Decision:
  - Keep as source-file route through the class parent, not direct owner for these class methods.

### 3. ScreenPane / Layer / Timer / SoundManager

- Evidence for:
  - The start/animate methods call ScreenPane layer helpers, timer scheduling, and sound playback.
- Evidence against:
  - These are dependencies only. They do not own the fields, vtables, resources, or class layout.
- Decision:
  - Reject as ownership/source placement.

### 4. PatchPane Or Adjacent Parcel Classes

- Evidence for:
  - Physical adjacency in `ParcelPane.cpp`.
- Evidence against:
  - PatchPane begins at `0x005470b0`, after ParcelPane scalar destructor and padding.
  - ParcelIconPane and ParcelPane have separate vtable slots and scalar destructor wrappers.
- Decision:
  - Reject for these targets.

## Negative Evidence Summary

- No IDA function exists at the raw starts in [UID:0001EL].
- No IDA xrefs or PE VA/RVA/rel32 direct edges target `0x00546b80` or `0x00546bc0`.
- No generated source currently emits the raw bodies.
- These negatives block original-callsite proof and child formal C++ readiness, but they do not justify moving source placement away from `FlyingParcelPane` because the local field/vtable/resource evidence is stronger.

## First-Draft C++ Recommendation

Do not populate formal C++ for [UID:0001EL]. It is not a source method; it is an aggregate/index over [UID:0002R5], padding, and [UID:0002R6]. Formal C++ at this parent would duplicate child bodies and violate range-local source shape.

Do not populate formal C++ for [UID:0001EN]. It meets the numeric gate after the recommended score, but the correct source shape is a source-declared virtual destructor plus compiler-generated deleting-destructor ABI. Hand-authoring this wrapper in the formal block would encode compiler output as source.

The source-level shape that should guide future child/source work is:

```cpp
// Do not enter this in [UID:0001EN]'s formal block.
// This belongs to the ordinary FlyingParcelPane destructor source shape,
// with the compiler regenerating the scalar deleting destructor wrapper.
FlyingParcelPane::~FlyingParcelPane()
{
    if (m_animationLayer != 0) {
        delete m_animationLayer;
        m_animationLayer = 0;
    }
}

void FlyingParcelPane::StartAnimation(
    unsigned char parcelCountOrState,
    unsigned char leftSlot,
    unsigned char rightSlot,
    bool isParcel)
{
    // Source-facing sketch only: keep [UID:0002R6]'s formal block blank in this pass.
    // The binary stores these four payload bytes, attaches m_animationLayer through
    // g_pScreenPane, selects the g_useEpfAssets layout path, and schedules the
    // tertiary animation timer.
}
```

This report explicitly recommends leaving the formal `RECONSTRUCTION_CPP CODE` blocks blank for [UID:0001EL] and [UID:0001EN]. It also recommends not entering child formal C++ for [UID:0002R5] or [UID:0002R6] from this report: [UID:0002R5] needs coordinated destructor-source placement with [UID:0001EN], and [UID:0002R6] still lacks a surviving direct caller or original method-name proof even though its descriptive source shape is now strong.

## Final Recommendation

Recommended metadata:

```text
[UID:0001EL]
COMPLETION:88
CONFIDENCE:91
CANONICAL_OWNER:000058
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
RECONSTRUCTION_CPP: blank

[UID:0001EN]
COMPLETION:86
CONFIDENCE:91
CANONICAL_OWNER:000058
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:000058
RECONSTRUCTION_CPP: blank
Rename/range correction: 0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor.md
```

Support docs to update:

- [UID:000058] `by-class/FlyingParcelPane.md`: record `m_animationFrame`, `m_parcelCountOrState`, `m_rightSlot`, `m_leftSlot`, `m_isParcel`, and `Layer *m_animationLayer`/`m_screenLayerEntry`; distinguish ordinary destructor body from scalar deleting wrapper.
- [UID:0000MF] `by-file/ParcelPane.md`: note `0001EL` is a non-emitting raw lifecycle/start index and exact children carry behavior.
- [UID:0001EH] `ParcelNotificationPanes`: record corrected [UID:0001EN] half-open range and padding before ParcelIconPane destructor.
- [UID:0002R5] cleanup child: replace vague helper wording with `Layer *m_animationLayer` delete/ordinary destructor-body shape.
- [UID:0002R6] start child: replace unresolved globals/helper names with `g_useEpfAssets`, `g_pScreenPane`, `g_pSoundManager`, `ScreenPane::SetLayerFrame`, `SoundManager::PlaySample`, and timer scheduling semantics.
- [UID:0002KK] animate step: ensure it names `ScreenPane::RemoveLayer`, `m_animationFrame`, `m_leftSlot`, `m_rightSlot`, `m_parcelCountOrState`, and `m_animationLayer`.
- [UID:0001VI] layout: update field-name recommendations for `+0xf8..+0x100`.
- [UID:0002OH]/[UID:0001YE] vtable docs: no structural change required; optionally add note that [UID:0001EN]'s half-open end is `0x00546f37`.
- [UID:0001EM] adjustor thunk docs: no score change required; existing jumps to `0x00546ed0` remain evidence for generated wrapper policy.

## Supervisor-Owned Coverage Row Text

Placement context: replace the existing [UID:0001EL] block after the ignored `0x00546b74-0x00546b80` padding row and before the ignored `0x00546d64-0x00546d70` padding row.

```markdown
    - [UID:0001EL][0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart](by-memory/0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart.md) 0x00546b80-0x00546d64 | raw-method aggregate | FlyingParcelPane raw lifecycle/start body index : ignored : 88% : strong : Non-emitting split inventory over exact FlyingParcelPane cleanup-destructor and start-animation raw bodies; PE scan finds no VA/RVA pointer or rel32 edge to the aggregate/raw starts, while child pages carry the source-bearing behavior, `0xcc` padding at `0x00546bb5-0x00546bc0`, vtable/write/layout/global evidence, and final source should emit through exact children/source destructor handling rather than duplicate this aggregate.
        - [UID:0002R5][0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody](by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md) 0x00546b80-0x00546bb5 | raw class method | FlyingParcelPane cleanup destructor body : reconstructable : 85% : strong : Raw non-deleting `FlyingParcelPane::~FlyingParcelPane()` cleanup body; restores FlyingParcelPane vtables, deletes the owned `Layer`/screen-layer entry at `+0x100`, tail-calls Pane base cleanup, has no PE direct edge to the raw start, and must be coordinated with scalar deleting wrapper policy before formal C++ entry.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00546bb5-0x00546bc0 | padding | FlyingParcelPane cleanup to start alignment : ignored : 100% : strong : Confirmed `0xcc` bytes.
        - [UID:0002R6][0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation](by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md) 0x00546bc0-0x00546d64 | raw class method | FlyingParcelPane start animation : reconstructable : 85% : strong : Raw `FlyingParcelPane::StartAnimation`/delivery-animation configuration body; stores payload bytes at `+0xf8..+0xfc`, attaches `+0x100` through `g_pScreenPane`, branches on `g_useEpfAssets`, plays sound sample `200` via `g_pSoundManager`, schedules 10/100 ms timer callbacks, has no PE direct edge to the raw start, and remains formal-C++ blank pending raw no-caller source-entry policy.
```

Placement context: replace the existing [UID:0001EN] row after [UID:0001EM] `ParcelNotificationAdjustorThunks` and before [UID:0001EO] `ParcelIconPaneScalarDeletingDestructor`. Also insert the ignored padding row immediately after [UID:0001EN].

```markdown
    - [UID:0001EN][0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor](by-memory/0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor.md) 0x00546ed0-0x00546f37 | scalar deleting destructor | FlyingParcelPane scalar deleting destructor wrapper : reconstructable : 86% : strong : MSVC deleting-destructor wrapper for source-declared `virtual ~FlyingParcelPane()`; primary vtable slot `0x00621ccc`, secondary/tertiary adjustor jumps at `0x00546e91`/`0x00546e9c`, cleanup sequence releases the owned `Layer`/screen-layer entry at `+0x100`, calls Pane base cleanup, and conditionally frees storage only when `(flags & 1) != 0 && (flags & 4) == 0`; exact size is `0x67`, final byte is at `0x00546f36`, padding begins at `0x00546f37`, and formal C++ must remain blank because source should declare the destructor rather than hand-author this wrapper.
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00546f37-0x00546f40 | padding | FlyingParcelPane scalar deleting destructor to ParcelIconPane scalar deleting destructor alignment : ignored : 100% : strong : Confirmed nine `0xcc` bytes after `FlyingParcelPane` scalar deleting destructor before `ParcelIconPaneScalarDeletingDestructor`.
```

If the supervisor delays the [UID:0001EN] filename rename, the coverage row should still use the corrected half-open range and the target page should record the pending path/range repair explicitly.

## Follow-Up Actions

Supervisor actions:

- Apply the metadata and range recommendations above.
- Rename [UID:0001EN] to `by-memory/0x00546ed0-0x00546f37.FlyingParcelPaneScalarDeletingDestructor.md` or otherwise correct its half-open range in-place if a rename must be deferred.
- Update support docs listed above.
- Apply the supervisor-owned coverage row replacements and inserted padding row.
- Keep formal C++ blank for [UID:0001EL] and [UID:0001EN].

A-agent actions:

- A follow-up child-specific final-C++ pass can target [UID:0002R5] and [UID:0002R6] after the destructor/wrapper and raw-no-caller policies are updated in support docs.
- If child C++ is later entered, ensure only the child pages emit source; [UID:0001EL] must stay non-emitting.

B002 future research actions:

- None required for this assignment after supervisor execution. Further work would be a new assignment on child formal C++ readiness, not on ownership or source placement.

## Confidence

- Recommendation confidence: high.
- Score confidence:
  - [UID:0001EL] `88/91`: high as a reviewed non-emitting split inventory; low risk because no source C++ is emitted.
  - [UID:0001EN] `86/91`: high for wrapper policy and range after correction; not higher because formal C++ remains intentionally blank and the project still models scalar deleting destructors as reconstructable binary artifacts.
- Remaining uncertainty:
  - Original source spelling of [UID:0002R6] is not provable. `StartAnimation`/`StartDeliveryAnimation` is descriptive and evidence-backed, not original-proof.
  - Exact final class name for the 8-byte `+0x100` helper is inferred as `Layer`/screen-layer entry from constructor and ScreenPane usage; if a later type pass renames the class, field docs should keep the semantic `m_animationLayer` name.

## Validator Results

- Commands run by B002 for this report:
  - Read-only `git diff`/`rg`/PowerShell inspections.
  - Read-only PE byte scan for VA/RVA/rel32 evidence.
  - Read-only byte dump for `0x00546ed0-0x00546f40`.
- Validator was not run because this assignment is report-only and no by-* files were edited by B002.

Recommended validation commands after supervisor application:

> Executable block R001 was removed from this report and preserved verbatim in [0001EL-0001EN-flyingparcelpane-lifecycle-source-quality-removed.md](0001EL-0001EN-flyingparcelpane-lifecycle-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the rename cannot be applied immediately, run the [UID:0001EN] validator command on the current filename and keep the corrected range/padding text in the page.

## Changed Files

- Created:
  - `tools/leaser/Agents/Agent-B002/research/0001EL-0001EN-flyingparcelpane-lifecycle-source-quality.md`
- Modified by B002:
  - none outside this report.
- Existing modified files observed but not touched by B002:
  - `by-memory/0x00546b80-0x00546d64.FlyingParcelPaneRawLifecycleAndStart.md`
  - `by-memory/0x00546ed0-0x00546f36.FlyingParcelPaneScalarDeletingDestructor.md`
  - `by-memory/-coverage-report.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0001EL-0001EN-flyingparcelpane-lifecycle-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"0001EL"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001EL-0001EN-flyingparcelpane-lifecycle-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0001EL-0001EN-flyingparcelpane-lifecycle-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001EL"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
