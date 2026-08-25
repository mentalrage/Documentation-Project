** TARGET-REPORT-UID:00016W **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00016W HelpTooltip Destructor Thunks Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: split [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](../../../../../by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md) into exact scalar-deleting-destructor child pages, keep the adjustor thunk spans ignored as compiler layout glue, and reclassify `00016W` as a reviewed non-emitting HelpPanes destructor/thunk index after those children exist.
- Recommended parent metadata after split: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000JU`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal C++.
- Do not hand-author C++ for `ScalarDeletingDestructor` or adjustor thunk functions. The correct source-facing shape is normal virtual destructors on the owning classes; MSVC should regenerate scalar deleting wrappers and secondary/tertiary `this` adjustors from class declarations and ordinary destructor bodies.
- Current-session limitation: IDA MCP was unavailable on `127.0.0.1:13337`; this report reanalyzes already-written IDA-backed docs, generated output, prior accepted B reports, and local coverage state. No IDA DB edit was made.

## Target

- Assignment: `B003-goal2-help-tooltip-destructor-thunks-source-quality-00016W-20260617`
- Primary target: [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](../../../../../by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md)
- Current state: `COMPLETION:82`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000JU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JU`, blank C++.
- Current generated state: `auto-generated/-ag-memory-coverage.md` routes [UID:00016W] to `auto-generated/NexusTK/ui/controls/HelpPanes.cpp`, but the staged file contains no code from `00016W`; it currently contains only [UID:000228] singleton close helper code.

## Executive Recommendation

`00016W` should not remain a source-emitting aggregate. It spans:

- Fourteen compiler-generated secondary/tertiary destructor adjustor thunks.
- Seven compiler-generated scalar deleting destructor wrappers for seven different classes.
- Internal `0xcc` alignment padding.

The scalar deleting destructors are still useful reconstructable documentation targets because vtables point to them and they preserve ABI/destructor evidence, but their formal C++ must remain blank. Each should be an exact class-owned child page with a no-code proof. The parent `00016W` should become a non-emitting index once those children exist, matching the accepted [UID:00016V] ItemHelpPaneCore split precedent.

Recommended scalar child pages:

| Range | Recommended page name | Owner / emitter | Score | Formal C++ |
| --- | --- | --- | --- | --- |
| `0x004ce3f0-0x004ce42b` | `HelpPaneScalarDeletingDestructor` | [UID:000063] `HelpPane` | `86/91` | blank, compiler wrapper |
| `0x004ce430-0x004ce4fb` | `ItemHelpPaneScalarDeletingDestructor` | [UID:00006U] `ItemHelpPane` | `87/92` | blank, compiler wrapper |
| `0x004ce500-0x004ce55f` | `SimpleHelpPane2ScalarDeletingDestructor` | [UID:0000D7] `SimpleHelpPane2` | `87/92` | blank, compiler wrapper |
| `0x004ce560-0x004ce618` | `SimpleHelpPaneScalarDeletingDestructor` | [UID:0000D6] `SimpleHelpPane` | `87/92` | blank, compiler wrapper |
| `0x004ce620-0x004ce668` | `HelpPaneSimpleHelpTextPartPaneScalarDeletingDestructor` | [UID:000064] `HelpPane__SimpleHelpTextPartPane` | `86/91` | blank, compiler wrapper |
| `0x004ce670-0x004ce6cf` | `WillBeChangedItemPaneScalarDeletingDestructor` | [UID:0000G5] `WillBeChangedItemPane` | `87/92` | blank, compiler wrapper |
| `0x004ce6d0-0x004ce725` | `WillBeChangedSpellPaneScalarDeletingDestructor` | [UID:0000G6] `WillBeChangedSpellPane` | `87/92` | blank, compiler wrapper |

Recommended ignored/thunk handling:

- Keep the leading adjustor thunk island in [UID:0000VN][-ignored](../../../../../by-memory/-ignored.md), but repair the existing ignored-ledger range list. The current ledger omits the first thunk of `HelpPane__SimpleHelpTextPartPane`, `WillBeChangedItemPane`, and `WillBeChangedSpellPane`.
- Correct full thunk groups are `0x004ce34b-0x004ce361`, `0x004ce361-0x004ce377`, `0x004ce377-0x004ce38d`, `0x004ce38d-0x004ce3a3`, `0x004ce3a3-0x004ce3b9`, `0x004ce3b9-0x004ce3cf`, and `0x004ce3cf-0x004ce3e5`.

## Supervisor Active Recheck

- The assignment asks for source-authored ordinary destructor names/signatures versus compiler scalar-deleting/adjustor-thunk policy for each subrange. The defensible answer is: ordinary destructor source names are class destructors (`~HelpPane`, `~ItemHelpPane`, `~SimpleHelpPane2`, `~SimpleHelpPane`, `~SimpleHelpTextPartPane`, `~WillBeChangedItemPane`, `~WillBeChangedSpellPane`); the ranges in `00016W` are ABI wrapper/thunk ranges, not ordinary source functions.
- The assignment asks whether `00016W` should remain aggregate/container, split into children, or carry no-code wrapper docs. Best policy is split scalar wrappers into exact children and keep the parent as a non-emitting index. If supervisor does not split in the same pass, do not set parent `RECONSTRUCTABLE:FALSE` yet; keep it as a temporary aggregate with blank C++ until children exist.
- The current owner/source family [UID:0000JU] `HelpPanes` remains correct for the parent because the island spans multiple HelpPanes classes. Exact scalar children should use class owners and emit through their class route to `HelpPanes.cpp`.

## Heuristic / Inference Reanalysis And Validation

### Source-authored destructor names and signatures

Best defensible source-facing destructor names:

| Binary wrapper | Source-facing destructor | Ordinary body evidence |
| --- | --- | --- |
| `0x004ce3f0` | `virtual HelpPane::~HelpPane()` | Ordinary body at `0x004c6db0-0x004c6e49`; `HelpPaneCore` documents style/text/embedded-child teardown. |
| `0x004ce430` | `virtual ItemHelpPane::~ItemHelpPane()` | Ordinary body at [UID:0003PM] `0x004c8b20-0x004c8bc2`; frees the 20-entry stat/value buffer table and clears `g_pItemHelpPane`. |
| `0x004ce500` | `virtual SimpleHelpPane2::~SimpleHelpPane2()` | Ordinary teardown at `0x004c75e0-0x004c7609`; clears `g_pSimpleHelpPane2` and jumps to `HelpPane::~HelpPane`. |
| `0x004ce560` | `virtual SimpleHelpPane::~SimpleHelpPane()` | Ordinary teardown at `0x004c7290-0x004c7307`; frees copied text buffer and clears `g_pSimpleHelpPane`. |
| `0x004ce620` | `virtual HelpPane::SimpleHelpTextPartPane::~SimpleHelpTextPartPane()` | No separate ordinary destructor body is currently documented; the wrapper destroys the `SimpleUString` member and base pane. Source should still be an ordinary destructor declaration/body, not a scalar wrapper function. |
| `0x004ce670` | `virtual WillBeChangedItemPane::~WillBeChangedItemPane()` | Non-deleting reset/destructor body at `0x004c7b80-0x004c7ba9`; clears `g_pWillBeChangedItemPane` and tears down `Pane`. |
| `0x004ce6d0` | `virtual WillBeChangedSpellPane::~WillBeChangedSpellPane()` | Non-deleting reset/destructor body at `0x004c80c0-0x004c80df`; restores spell-pane vtables and tears down `Pane`. |

Rejected alternatives:

- Source methods named `Class::ScalarDeletingDestructor(unsigned int flags)`: rejected. Existing B-agent scalar wrapper precedent says these are compiler ABI wrappers and formal C++ should stay blank.
- Hand-authored `this -= 0xa0` / `this -= 0xa4` thunk methods: rejected. The adjustor thunks are compiler-generated vtable glue for inherited secondary and tertiary interface views.
- Keeping source destructor bodies only on `00016W`: rejected. `00016W` spans seven classes and should not own aggregate C++.

### Subrange classification

| Range | Current role | Classification | Source / C++ impact |
| --- | --- | --- | --- |
| `0x004ce34b-0x004ce361` | HelpPane two adjustor thunks | compiler/linker-generated | Ignore as standalone code; generated from HelpPane inheritance/vtables. |
| `0x004ce361-0x004ce377` | ItemHelpPane two adjustor thunks | compiler/linker-generated | Ignore as standalone code; generated from ItemHelpPane inheritance/vtables. |
| `0x004ce377-0x004ce38d` | SimpleHelpPane2 two adjustor thunks | compiler/linker-generated | Ignore as standalone code; generated from SimpleHelpPane2 inheritance/vtables. |
| `0x004ce38d-0x004ce3a3` | SimpleHelpPane two adjustor thunks | compiler/linker-generated | Ignore as standalone code; generated from SimpleHelpPane inheritance/vtables. |
| `0x004ce3a3-0x004ce3b9` | HelpPane text-part two adjustor thunks | compiler/linker-generated | Ignore as standalone code; repair ignored ledger to include the whole pair. |
| `0x004ce3b9-0x004ce3cf` | WillBeChangedItemPane two adjustor thunks | compiler/linker-generated | Ignore as standalone code; repair ignored ledger to include the whole pair. |
| `0x004ce3cf-0x004ce3e5` | WillBeChangedSpellPane two adjustor thunks | compiler/linker-generated | Ignore as standalone code; repair ignored ledger to include the whole pair. |
| `0x004ce3e5-0x004ce3f0` | padding | ignored | `0xcc` alignment before HelpPane wrapper. |
| `0x004ce3f0-0x004ce42b` | HelpPane scalar deleting destructor | reconstructable ABI wrapper, no formal C++ | Exact class-owned child; source declaration impact is `virtual ~HelpPane();`. |
| `0x004ce42b-0x004ce430` | padding | ignored | `0xcc` alignment. |
| `0x004ce430-0x004ce4fb` | ItemHelpPane scalar deleting destructor | reconstructable ABI wrapper, no formal C++ | Exact class-owned child; source declaration impact is `virtual ~ItemHelpPane();`. |
| `0x004ce4fb-0x004ce500` | padding | ignored | `0xcc` alignment. |
| `0x004ce500-0x004ce55f` | SimpleHelpPane2 scalar deleting destructor | reconstructable ABI wrapper, no formal C++ | Exact class-owned child; source declaration impact is `virtual ~SimpleHelpPane2();`. |
| `0x004ce55f-0x004ce560` | padding | ignored | one `0xcc` byte. |
| `0x004ce560-0x004ce618` | SimpleHelpPane scalar deleting destructor | reconstructable ABI wrapper, no formal C++ | Exact class-owned child; source declaration impact is `virtual ~SimpleHelpPane();`. |
| `0x004ce618-0x004ce620` | padding | ignored | `0xcc` alignment. |
| `0x004ce620-0x004ce668` | HelpPane text-part scalar deleting destructor | reconstructable ABI wrapper, no formal C++ | Exact class-owned child; source declaration impact is `virtual ~SimpleHelpTextPartPane();`. |
| `0x004ce668-0x004ce670` | padding | ignored | `0xcc` alignment. |
| `0x004ce670-0x004ce6cf` | WillBeChangedItemPane scalar deleting destructor | reconstructable ABI wrapper, no formal C++ | Exact class-owned child; source declaration impact is `virtual ~WillBeChangedItemPane();`. |
| `0x004ce6cf-0x004ce6d0` | padding | ignored | one `0xcc` byte. |
| `0x004ce6d0-0x004ce725` | WillBeChangedSpellPane scalar deleting destructor | reconstructable ABI wrapper, no formal C++ | Exact class-owned child; source declaration impact is `virtual ~WillBeChangedSpellPane();`. |

### Globals and singleton clears

| Raw name in decompilation | Source-facing name | Type direction | Evidence and impact |
| --- | --- | --- | --- |
| `dword_69AE04` / `unk_69AE04` | `g_pItemHelpPane` | `static ItemHelpPane*` | Global page [UID:0000R9] and storage [UID:0001PD] document 20 xrefs, constructor publish/fallback clear at `0x004c832e/0x004c8335`, ordinary destructor clear at `0x004c8ba1`, support clear at `0x004ce310`, scalar wrapper clear at `0x004ce4b2`, close-helper reads, and item/inventory consumers. |
| `dword_67A7D4` | `g_pSimpleHelpPane2` | `static SimpleHelpPane2*` | Global [UID:0000SA] and storage [UID:0001OY] document nine xrefs: UI read, constructor/factory publish/fallback, ordinary teardown clear, support clear `0x004ce320`, and scalar wrapper clear `0x004ce520`. |
| `dword_69AE00` | `g_pSimpleHelpPane` | `static SimpleHelpPane*` | Global [UID:0000S9] and storage [UID:0001PC] document 23 refs, constructor publish/fallback, ordinary/support/scalar clears, close-helper read, and broad feature consumers. |
| `dword_69B414` | `g_pWillBeChangedItemPane` | `static WillBeChangedItemPane*` | Global [UID:0000SS] and storage [UID:0001PK] document five xrefs, constructor publish/fallback, non-deleting destructor clear, support clear `0x004ce340`, and scalar wrapper clear `0x004ce690`. |

No defensible separate singleton exists for `WillBeChangedSpellPane`; current docs show no spell-preview global analogous to `g_pWillBeChangedItemPane`.

### Field and helper name inferences

- `ItemHelpPane +0x62c`: best source-facing name direction is `m_statValueTextBuffers` or `m_statValueRows`. Evidence: exact destructor [UID:0003PM] and populate child [UID:0003PS] call it a 20-entry stat/text pointer table; generated source uses inconsistent `m_pItemData`, `m_statTable`, and `m_statValueRows`. The table stores 20 pointers to 0x50-byte text buffers and the table itself is also freed. Use a descriptive name, not `m_pItemData`, because generated output also uses `m_pItemData` for item metadata in paint.
- `SimpleHelpPane +0xf8` / `Block[62]`: best name is `m_textBuffer` or `m_copiedTextBuffer`. Evidence: constructor allocates a UTF-16 copy of caller text, paint walks it line by line, ordinary destructor and scalar wrapper free it, and docs call it the copied text buffer.
- `HelpPane::SimpleHelpTextPartPane +0xf8`: best name is `m_text` with type `SimpleUString`. Evidence: constructor constructs a `SimpleUString`, draw path calls `c_str`-like behavior, scalar wrapper destroys the string member. The generated name `m_text` is consistent with the by-memory field table.
- `HelpPane::SimpleHelpTextPartPane +0xfc`: best name direction is `m_styleRuns` / `m_styleArray` pointer. Evidence: raw helper checks a style pointer, `DrawText` uses per-line style records, and generated output calls it `m_pStyleArray`.
- `HelpPane +0xfc`: style/config block, compatible with [UID:00005C] `FontStyle`; includes enabled byte, opacity/float fields, colors, and a vector triplet copied by `HelpPanes_Vector16AssignRange`.
- `HelpPane +0x11c/+0x120`: frame/fill or foreground/background color state used by `OnPaintFrame`. Existing generated output reverses names in places, so source docs should say "paint color fields" until final names are proven.
- `HelpPane +0x124`: embedded `HelpPane::SimpleHelpTextPartPane` child, best source name `m_textPart` / `m_simpleTextPart`.
- Base teardown helpers:
  - `0x004c6db0` is `HelpPane::~HelpPane`.
  - `0x00544580` / `sub_544580` is shared `Pane` teardown / `Pane::~Pane` helper.
  - `0x00582b70` / `sub_582B70` is a shared `SimpleUString`/wide-string member destructor helper.
  - `0x00516030` is `GetMemoryMan`.
  - `0x00516170` is `FreeBufferMemory`.
  - `0x004f4ac0` is the project `operator delete` wrapper, ultimately using `GetMemoryMan` and `FreeBufferMemory`.

### Inheritance and vtable offsets

All HelpPanes classes in this island use three vtable views. Primary view is at object offset `+0x00`; secondary and tertiary views correspond to subobjects at `+0xa0` and `+0xa4`. The adjustor thunk pairs subtract `0xa0` or `0xa4` from the incoming secondary/tertiary `this` pointer and jump to the class primary scalar deleting destructor.

Relevant vtable ownership from [UID:00025G] `HelpItemHelpReadOnlyData`:

| Class | Vtable bases |
| --- | --- |
| `HelpPane::SimpleHelpTextPartPane` | `0x0061aad4`, `0x0061ab20`, `0x0061ab50` |
| `HelpPane` | `0x0061ab5c`, `0x0061aba8`, `0x0061abd8` |
| `SimpleHelpPane` | `0x0061abe4`, `0x0061ac30`, `0x0061ac60` |
| `SimpleHelpPane2` | `0x0061ac6c`, `0x0061acb8`, `0x0061ace8` |
| `WillBeChangedItemPane` | `0x0061acf4`, `0x0061ad40`, `0x0061ad70` |
| `WillBeChangedSpellPane` | `0x0061ad7c`, `0x0061adc8`, `0x0061adf8` |
| `ItemHelpPane` | `0x0061ae04`, `0x0061ae50`, `0x0061ae80` |

This validates inherited/shared virtual slots and current source placement under [UID:0000JU] `HelpPanes`. A future `ItemHelpPane.cpp` or `WillBeChangedPanes.cpp` split remains plausible, but no source-file evidence currently beats the HelpPanes family route.

### Validation or contradiction of current docs

Validated:

- Target function boundaries, scalar wrapper sizes, vtable/data refs, delete-flag behavior, singleton clears, buffer cleanup, and internal padding are already documented with 2026-06-01 and 2026-06-06 IDA MCP evidence.
- [UID:00025G] validates the vtable family and the `HierList` successor boundary.
- [UID:00016S], [UID:00016U], [UID:00016V] and exact ItemHelpPane children validate ordinary destructor/body locations outside `00016W`.

Contradicted or stale:

- `00016W` header says `RECONSTRUCTABLE:TRUE` and `EMITTER_UIDS:0000JU`. As a mixed wrapper/thunk island, it should become non-emitting after exact scalar children exist.
- `by-memory/-ignored.md` adjustor-thunk entry currently omits `0x004ce3a3-0x004ce3ae`, `0x004ce3b9-0x004ce3c4`, and `0x004ce3cf-0x004ce3da`. The target page correctly includes those thunks inside full pair ranges.
- `auto-generated/-ag-memory-coverage.md` says `00016W` emits through `HelpPanes.cpp`, but the actual generated C++ has no `00016W` code. This is a metadata/classification issue, not an autogen failure.

## Evidence Standards Used

- Required project guidance read: `goal.md`, `notes.md`, `inference_research.md`, and `by-structure.md`.
- IDA MCP availability check: `Invoke-WebRequest` to `http://127.0.0.1:13337/mcp` returned "Unable to connect to the remote server"; `Get-NetTCPConnection -LocalPort 13337` returned no listener.
- Documentation evidence read: target [UID:00016W], [UID:0000JU] `HelpPanes`, [UID:00016R], [UID:00016S], [UID:00016U], [UID:00016V], [UID:00022P], HelpPane/SimpleHelpPane/SimpleHelpPane2/ItemHelpPane/WillBeChanged class/global pages, [UID:00025G] read-only data, current coverage rows, ignored ledger, generated `HelpPanes.cpp`, and prior executed B-agent reports.
- Generated-output evidence treated only as leads: `source-3/simroot_v2/class_*HelpPane*.cpp` and `auto-generated/NexusTK/ui/controls/HelpPanes.cpp`.
- Prior accepted precedent used: [UID:00016V] split report, [UID:000228] singleton close report, and scalar-deleting-destructor reports for MapTileImageLib/BlackHole/AlertPane.

## IDA MCP Facts

No fresh live IDA facts were gathered in this session because MCP was unavailable. Stable facts already recorded in current docs and reused here:

- Fourteen contiguous adjustor thunks exist from `0x004ce34b` through `0x004ce3da`, all size `0x0b`; `0x004ce3e5` is not a function.
- Scalar deleting destructor starts and sizes are:
  - `0x004ce3f0`, size `0x3b`.
  - `0x004ce430`, size `0xcb`.
  - `0x004ce500`, size `0x5f`.
  - `0x004ce560`, size `0xb8`.
  - `0x004ce620`, size `0x48`.
  - `0x004ce670`, size `0x5f`.
  - `0x004ce6d0`, size `0x55`, ending exactly at `0x004ce725`.
- Each scalar wrapper has two adjustor-thunk code refs and one primary vtable/data ref: `0x0061ab5c`, `0x0061ae04`, `0x0061ac6c`, `0x0061abe4`, `0x0061aad4`, `0x0061acf4`, and `0x0061ad7c`.
- Scalar wrapper delete semantics: normal teardown first, then `sub_4F4AC0` only when `(flags & 1) != 0` and `(flags & 4) == 0`.
- `0x004ce725-0x004ce730` is `0xcc` alignment after the final `retn 4` byte at `0x004ce724`.

## Function / Child Inventory

| Item | Role | Recommended handling |
| --- | --- | --- |
| `00016W` parent | mixed destructor/thunk island | non-emitting index after split, `88/91`, owner [UID:0000JU], blank emitters/C++ |
| adjustor thunk groups | compiler-generated secondary/tertiary `this` adjustors | ignored ledger, no child pages required unless supervisor wants exact ignored pages |
| seven scalar wrappers | class vtable slot 0 ABI wrappers | exact child pages, class-owned, reconstructable, blank C++ |
| internal padding | alignment | ignored coverage rows |

## Direct Xref / Caller Inventory

The target docs already record all direct wrapper refs at source-quality level:

- `0x004ce3f0` has adjustor refs from `0x004ce34b/0x004ce356` and primary vtable data ref `0x0061ab5c`.
- `0x004ce430` has adjustor refs from `0x004ce361/0x004ce36c` and primary vtable data ref `0x0061ae04`.
- `0x004ce500` has adjustor refs from `0x004ce377/0x004ce382` and primary vtable data ref `0x0061ac6c`.
- `0x004ce560` has adjustor refs from `0x004ce38d/0x004ce398` and primary vtable data ref `0x0061abe4`.
- `0x004ce620` has adjustor refs from `0x004ce3a3/0x004ce3ae` and primary vtable data ref `0x0061aad4`.
- `0x004ce670` has adjustor refs from `0x004ce3b9/0x004ce3c4` and primary vtable data ref `0x0061acf4`.
- `0x004ce6d0` has adjustor refs from `0x004ce3cf/0x004ce3da` and primary vtable data ref `0x0061ad7c`.

No direct ordinary source callers are needed for scalar wrappers; vtable reachability is enough. Ordinary destructors and reset bodies have their own class/memory evidence outside this target.

## Ranked Ownership Analysis

1. [UID:0000JU] `HelpPanes` for the parent index.
   Evidence: all seven classes belong to the documented HelpPanes source family, the vtable island [UID:00025G] is parented to HelpPanes, singleton globals route through HelpPanes, and `HelpPanes.cpp` is the current valid generated source root.

2. Direct class owners for scalar child pages.
   Evidence: each scalar wrapper is vtable slot 0 for exactly one class and has class-specific singleton/field cleanup. The child owners should be the class pages, not the file root.

3. [UID:0000JU] as direct owner for scalar children.
   Rejected as less precise. The file remains the eventual source route, but class pages are the narrowest semantic owners for exact destructor wrappers.

4. Caller feature files or adjacent `HierList`.
   Rejected. The island is vtable/destructor data for HelpPanes classes and ends before `HierListConstructor` at `0x004ce730`; no caller-feature evidence owns the wrappers.

## Negative Evidence Summary

- "Current page emits, so keep it emitting": rejected. Autogen shows a route but no emitted code, and the page body already says correct source is ordinary destructors, not scalar wrappers.
- "Delete all scalar wrapper docs as ignored": rejected. The wrappers are vtable targets and useful ABI evidence; they should remain reconstructable documentation pages with blank formal C++.
- "Use generated names like `TextButtonExControlPane::~Pane`": rejected as base-owner/type pollution. Current docs identify `0x00544580` as shared `Pane` teardown and `0x004c6db0` as `HelpPane::~HelpPane`.
- "Use `m_pItemData` for the `+0x62c` table": rejected as too ambiguous. Generated source also uses that name for item metadata. Use descriptive `m_statValueTextBuffers` / `m_statValueRows` until a type pass proves the original field name.

## First-Draft C++ Recommendation

### Parent [UID:00016W]

Do not populate formal C++ for [UID:00016W]. After split, it should be `RECONSTRUCTABLE:FALSE`, so no code is eligible.

### Scalar deleting destructor child pages

Do not populate formal C++ for any scalar deleting destructor child. Each wrapper should include this no-code proof:

```cpp
// No standalone source body for this by-memory range.
// The compiler emits the scalar deleting destructor from the class' virtual destructor.
```

Source declaration impact only:

```cpp
class HelpPane {
public:
    virtual ~HelpPane();
};

class ItemHelpPane {
public:
    virtual ~ItemHelpPane();
};

class SimpleHelpPane2 {
public:
    virtual ~SimpleHelpPane2();
};

class SimpleHelpPane {
public:
    virtual ~SimpleHelpPane();
};

class HelpPane::SimpleHelpTextPartPane {
public:
    virtual ~SimpleHelpTextPartPane();
};

class WillBeChangedItemPane {
public:
    virtual ~WillBeChangedItemPane();
};

class WillBeChangedSpellPane {
public:
    virtual ~WillBeChangedSpellPane();
};
```

Reason: these declarations plus ordinary destructor implementations are the source representation. Handwriting `Class::ScalarDeletingDestructor(unsigned int flags)` would duplicate compiler ABI glue and is rejected.

### Ordinary destructor bodies outside this target

No formal C++ should be added to `00016W` for ordinary destructor bodies outside its range. Relevant ordinary bodies or reset bodies are already documented at:

- `HelpPane::~HelpPane` at `0x004c6db0-0x004c6e49`.
- `SimpleHelpPane::~SimpleHelpPane` at `0x004c7290-0x004c7307`.
- `SimpleHelpPane2::~SimpleHelpPane2` at `0x004c75e0-0x004c7609`.
- `WillBeChangedItemPane` reset/destructor body at `0x004c7b80-0x004c7ba9`.
- `WillBeChangedSpellPane` reset/destructor body at `0x004c80c0-0x004c80df`.
- [UID:0003PM] `ItemHelpPaneNonDeletingDestructor` at `0x004c8b20-0x004c8bc2`.

`HelpPane::SimpleHelpTextPartPane` needs a future class-layout pass if final ordinary destructor source is required, because no separate ordinary destructor function is currently documented. The wrapper evidence still supports the source destructor's behavior: destroy `m_text` (`SimpleUString` at `+0xf8`) and then tear down the base pane.

## Support Docs To Update

- [UID:00016W] target page:
  - Change status to "reviewed non-emitting destructor/thunk index" after child pages exist.
  - Replace reconstruction notes to say scalar wrappers have exact children and formal C++ stays blank.
  - Add the corrected ignored thunk range list.
- [UID:0000JU] `HelpPanes`:
  - Update the destructor island row to reference the non-emitting parent and exact scalar wrapper children.
  - No score change required.
- Class pages [UID:000063], [UID:000064], [UID:0000D6], [UID:0000D7], [UID:00006U], [UID:0000G5], [UID:0000G6]:
  - Add links to the new scalar wrapper children when created.
  - Preserve blank final C++ for wrapper pages; ordinary destructor C++ remains blocked by class field/source split quality unless separately resolved.
- [UID:0000VN] `by-memory/-ignored.md`:
  - Replace the current Help/tooltip adjustor-thunk range list with the full seven pair ranges listed below.
- [UID:00025G] `HelpItemHelpReadOnlyData`:
  - No score or metadata change required; optional link refresh only after scalar child UIDs exist.

Recommended `by-memory/-ignored.md` replacement for the Help/tooltip thunk heading line:

```markdown
- `0x004ce34b-0x004ce361`, `0x004ce361-0x004ce377`, `0x004ce377-0x004ce38d`, `0x004ce38d-0x004ce3a3`, `0x004ce3a3-0x004ce3b9`, `0x004ce3b9-0x004ce3cf`, and `0x004ce3cf-0x004ce3e5` - Help/tooltip secondary/tertiary destructor adjustor thunks.
```

Keep the existing reason/evidence/replacement/owner prose, but change "The listed ranges intentionally skip alignment gaps and stop before..." to "The listed ranges cover only adjustor thunk functions, intentionally skip alignment gaps, and stop before..."

## Supervisor-Owned Coverage Row Updates

Placement context: replace the current [UID:00016W] row and its following truncated adjustor-thunk ignored row in `by-memory/-coverage-report.md`, immediately after the [UID:00022P] helper rows and before the existing `0x004ce725-0x004ce730` padding row. Create scalar child pages first and substitute the real child UIDs before applying.

```markdown
    - [UID:00016W][0x004ce34b-0x004ce725.HelpTooltipDestructorThunks](by-memory/0x004ce34b-0x004ce725.HelpTooltipDestructorThunks.md) 0x004ce34b-0x004ce725 | destructor/thunk split index | HelpTooltipDestructorThunks : not_reconstructable : 88% : very-strong : B003 2026-06-17 source-quality reanalysis recommends this mixed HelpPanes destructor/thunk island become a non-emitting index after exact scalar-deleting-destructor children exist; the leading fourteen adjustor thunks are compiler-generated secondary/tertiary `this` adjustors, exact scalar wrapper children carry class-owned vtable/destructor evidence with blank formal C++, and internal padding remains ignored.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ce34b-0x004ce361 | compiler adjustor thunks | HelpPane destructor adjustor thunks : ignored : 100% : strong : Two `0x0b` secondary/tertiary destructor adjustor thunks that subtract `0xa0`/`0xa4` and jump to `HelpPaneScalarDeletingDestructor`; generated from HelpPane inheritance and vtable layout.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ce361-0x004ce377 | compiler adjustor thunks | ItemHelpPane destructor adjustor thunks : ignored : 100% : strong : Two `0x0b` secondary/tertiary destructor adjustor thunks that subtract `0xa0`/`0xa4` and jump to `ItemHelpPaneScalarDeletingDestructor`; generated from ItemHelpPane inheritance and vtable layout.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ce377-0x004ce38d | compiler adjustor thunks | SimpleHelpPane2 destructor adjustor thunks : ignored : 100% : strong : Two `0x0b` secondary/tertiary destructor adjustor thunks that subtract `0xa0`/`0xa4` and jump to `SimpleHelpPane2ScalarDeletingDestructor`; generated from SimpleHelpPane2 inheritance and vtable layout.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ce38d-0x004ce3a3 | compiler adjustor thunks | SimpleHelpPane destructor adjustor thunks : ignored : 100% : strong : Two `0x0b` secondary/tertiary destructor adjustor thunks that subtract `0xa0`/`0xa4` and jump to `SimpleHelpPaneScalarDeletingDestructor`; generated from SimpleHelpPane inheritance and vtable layout.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ce3a3-0x004ce3b9 | compiler adjustor thunks | HelpPane text-part destructor adjustor thunks : ignored : 100% : strong : Two `0x0b` secondary/tertiary destructor adjustor thunks that subtract `0xa0`/`0xa4` and jump to `HelpPaneSimpleHelpTextPartPaneScalarDeletingDestructor`; generated from embedded text-part inheritance and vtable layout.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ce3b9-0x004ce3cf | compiler adjustor thunks | WillBeChangedItemPane destructor adjustor thunks : ignored : 100% : strong : Two `0x0b` secondary/tertiary destructor adjustor thunks that subtract `0xa0`/`0xa4` and jump to `WillBeChangedItemPaneScalarDeletingDestructor`; generated from WillBeChangedItemPane inheritance and vtable layout.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ce3cf-0x004ce3e5 | compiler adjustor thunks | WillBeChangedSpellPane destructor adjustor thunks : ignored : 100% : strong : Two `0x0b` secondary/tertiary destructor adjustor thunks that subtract `0xa0`/`0xa4` and jump to `WillBeChangedSpellPaneScalarDeletingDestructor`; generated from WillBeChangedSpellPane inheritance and vtable layout.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ce3e5-0x004ce3f0 | padding | HelpPane destructor wrapper alignment : ignored : 100% : strong : Eleven `0xcc` alignment bytes between adjustor thunks and `HelpPaneScalarDeletingDestructor`.
        - [UID:<UID-HELP-SCALAR>][0x004ce3f0-0x004ce42b.HelpPaneScalarDeletingDestructor](by-memory/0x004ce3f0-0x004ce42b.HelpPaneScalarDeletingDestructor.md) 0x004ce3f0-0x004ce42b | scalar deleting destructor | HelpPaneScalarDeletingDestructor : reconstructable : 86% : very-strong : Exact compiler scalar deleting destructor wrapper for `HelpPane`; primary vtable ref `0x0061ab5c`, two adjustor thunk refs, calls/embeds ordinary `HelpPane::~HelpPane` teardown at `0x004c6db0`, applies MSVC delete flags, and must keep formal C++ blank because the source representation is `virtual ~HelpPane()`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ce42b-0x004ce430 | padding | ItemHelpPane destructor wrapper alignment : ignored : 100% : strong : Five `0xcc` alignment bytes before `ItemHelpPaneScalarDeletingDestructor`.
        - [UID:<UID-ITEM-SCALAR>][0x004ce430-0x004ce4fb.ItemHelpPaneScalarDeletingDestructor](by-memory/0x004ce430-0x004ce4fb.ItemHelpPaneScalarDeletingDestructor.md) 0x004ce430-0x004ce4fb | scalar deleting destructor | ItemHelpPaneScalarDeletingDestructor : reconstructable : 87% : very-strong : Exact compiler scalar deleting destructor wrapper for `ItemHelpPane`; primary vtable ref `0x0061ae04`, two adjustor thunk refs, restores ItemHelpPane vtables, frees the 20-entry stat/value text buffer table at `+0x62c`, clears `g_pItemHelpPane`, tears down the pane base, applies MSVC delete flags, and must keep formal C++ blank because source should emit `virtual ~ItemHelpPane()`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ce4fb-0x004ce500 | padding | SimpleHelpPane2 destructor wrapper alignment : ignored : 100% : strong : Five `0xcc` alignment bytes before `SimpleHelpPane2ScalarDeletingDestructor`.
        - [UID:<UID-SIMPLE2-SCALAR>][0x004ce500-0x004ce55f.SimpleHelpPane2ScalarDeletingDestructor](by-memory/0x004ce500-0x004ce55f.SimpleHelpPane2ScalarDeletingDestructor.md) 0x004ce500-0x004ce55f | scalar deleting destructor | SimpleHelpPane2ScalarDeletingDestructor : reconstructable : 87% : very-strong : Exact compiler scalar deleting destructor wrapper for `SimpleHelpPane2`; primary vtable ref `0x0061ac6c`, two adjustor thunk refs, restores three vtable views, clears `g_pSimpleHelpPane2`, tears down `HelpPane`, applies MSVC delete flags, and must keep formal C++ blank because source should emit `virtual ~SimpleHelpPane2()`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ce55f-0x004ce560 | padding | SimpleHelpPane destructor wrapper alignment : ignored : 100% : strong : One `0xcc` alignment byte before `SimpleHelpPaneScalarDeletingDestructor`.
        - [UID:<UID-SIMPLE-SCALAR>][0x004ce560-0x004ce618.SimpleHelpPaneScalarDeletingDestructor](by-memory/0x004ce560-0x004ce618.SimpleHelpPaneScalarDeletingDestructor.md) 0x004ce560-0x004ce618 | scalar deleting destructor | SimpleHelpPaneScalarDeletingDestructor : reconstructable : 87% : very-strong : Exact compiler scalar deleting destructor wrapper for `SimpleHelpPane`; primary vtable ref `0x0061abe4`, two adjustor thunk refs, frees copied UTF-16 text buffer at `+0xf8`, clears `g_pSimpleHelpPane`, tears down the pane base, applies MSVC delete flags, and must keep formal C++ blank because source should emit `virtual ~SimpleHelpPane()`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ce618-0x004ce620 | padding | HelpPane text-part destructor wrapper alignment : ignored : 100% : strong : Eight `0xcc` alignment bytes before `HelpPaneSimpleHelpTextPartPaneScalarDeletingDestructor`.
        - [UID:<UID-TEXTPART-SCALAR>][0x004ce620-0x004ce668.HelpPaneSimpleHelpTextPartPaneScalarDeletingDestructor](by-memory/0x004ce620-0x004ce668.HelpPaneSimpleHelpTextPartPaneScalarDeletingDestructor.md) 0x004ce620-0x004ce668 | scalar deleting destructor | HelpPaneSimpleHelpTextPartPaneScalarDeletingDestructor : reconstructable : 86% : very-strong : Exact compiler scalar deleting destructor wrapper for `HelpPane::SimpleHelpTextPartPane`; primary vtable ref `0x0061aad4`, two adjustor thunk refs, destroys the `SimpleUString` text member at `+0xf8`, tears down the pane base, applies delete flags, and must keep formal C++ blank because source should emit the nested text-part destructor.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ce668-0x004ce670 | padding | WillBeChangedItemPane destructor wrapper alignment : ignored : 100% : strong : Eight `0xcc` alignment bytes before `WillBeChangedItemPaneScalarDeletingDestructor`.
        - [UID:<UID-WBC-ITEM-SCALAR>][0x004ce670-0x004ce6cf.WillBeChangedItemPaneScalarDeletingDestructor](by-memory/0x004ce670-0x004ce6cf.WillBeChangedItemPaneScalarDeletingDestructor.md) 0x004ce670-0x004ce6cf | scalar deleting destructor | WillBeChangedItemPaneScalarDeletingDestructor : reconstructable : 87% : very-strong : Exact compiler scalar deleting destructor wrapper for `WillBeChangedItemPane`; primary vtable ref `0x0061acf4`, two adjustor thunk refs, restores three vtable views, clears `g_pWillBeChangedItemPane`, tears down the pane base, applies MSVC delete flags, and must keep formal C++ blank because source should emit `virtual ~WillBeChangedItemPane()`.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ce6cf-0x004ce6d0 | padding | WillBeChangedSpellPane destructor wrapper alignment : ignored : 100% : strong : One `0xcc` alignment byte before `WillBeChangedSpellPaneScalarDeletingDestructor`.
        - [UID:<UID-WBC-SPELL-SCALAR>][0x004ce6d0-0x004ce725.WillBeChangedSpellPaneScalarDeletingDestructor](by-memory/0x004ce6d0-0x004ce725.WillBeChangedSpellPaneScalarDeletingDestructor.md) 0x004ce6d0-0x004ce725 | scalar deleting destructor | WillBeChangedSpellPaneScalarDeletingDestructor : reconstructable : 87% : very-strong : Exact compiler scalar deleting destructor wrapper for `WillBeChangedSpellPane`; primary vtable ref `0x0061ad7c`, two adjustor thunk refs, restores three vtable views, tears down the pane base, applies MSVC delete flags, and must keep formal C++ blank because source should emit `virtual ~WillBeChangedSpellPane()`. The final byte at `0x004ce724` is the `retn 4` operand byte.
```

Keep the already-existing next row:

```markdown
    - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ce725-0x004ce730 | padding | HelpTooltipDestructorThunks to HierList alignment : ignored : 100% : strong : Confirmed `0xcc` alignment padding after `WillBeChangedSpellPane::ScalarDeletingDestructor`; `0x004ce724` is the final byte of the preceding `retn 4` instruction, not padding.
```

Expected generated-memory impact after split:

- Parent [UID:00016W] should become `not_reconstructable`, blank emitter.
- New scalar children should appear as `emits` through their class owners to `auto-generated/NexusTK/ui/controls/HelpPanes.cpp`, but with `no` assembled code because formal C++ remains blank.
- Adjustor thunk rows and padding rows should be ignored, not emitted.

## Follow-Up Actions

- Supervisor/A-agent:
  - Create the seven exact scalar deleting destructor child pages.
  - Repair [UID:00016W] metadata only after child pages exist.
  - Repair the `by-memory/-ignored.md` adjustor-thunk range list.
  - Apply the coverage block above with real child UIDs.
  - Run scoped validators for the new child pages, parent page, ignored ledger, HelpPanes file page if touched, and `by-memory/-coverage-report.md`, then regenerate memory coverage reports.
- C-agent/IDA maintenance:
  - No required IDA DB edit for this report.
  - Optional future labels: `HelpPane_ScalarDeletingDestructor`, `ItemHelpPane_ScalarDeletingDestructor`, `SimpleHelpPane2_ScalarDeletingDestructor`, `SimpleHelpPane_ScalarDeletingDestructor`, `HelpPaneSimpleHelpTextPartPane_ScalarDeletingDestructor`, `WillBeChangedItemPane_ScalarDeletingDestructor`, and `WillBeChangedSpellPane_ScalarDeletingDestructor`.

## Confidence

- Recommendation confidence: high.
- Main confidence limiter: no live IDA MCP in this session, so no new decompile/xref output was generated. Existing by-* docs contain multiple recent live IDA checks for exactly these ranges.
- Original field spelling confidence: medium. Use descriptive field names for `m_statValueTextBuffers`, `m_textBuffer`, `m_text`, `m_styleRuns`, and `m_textPart` until a dedicated layout/type pass verifies original names.
- Source placement confidence: high for current HelpPanes family, medium for final original split among `HelpPanes.cpp`, `ItemHelpPane.cpp`, and `WillBeChangedPanes.cpp`.

## Validator Results

Commands/results run for this report:

> Executable block R001 was removed from this report and preserved verbatim in [00016W-help-tooltip-destructor-thunks-source-quality-removed.md](00016W-help-tooltip-destructor-thunks-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result: required instructions and structure guidance read.

> Executable block R002 was removed from this report and preserved verbatim in [00016W-help-tooltip-destructor-thunks-source-quality-removed.md](00016W-help-tooltip-destructor-thunks-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result: MCP unavailable; no listener on port `13337`.

> Executable block R003 was removed from this report and preserved verbatim in [00016W-help-tooltip-destructor-thunks-source-quality-removed.md](00016W-help-tooltip-destructor-thunks-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result: support docs, generated output, coverage rows, ignored ledger, and prior B reports reviewed. No by-* validator was run because this was report-only and no by-* docs were edited.

Recommended validation after supervisor edits:

> Executable block R004 was removed from this report and preserved verbatim in [00016W-help-tooltip-destructor-thunks-source-quality-removed.md](00016W-help-tooltip-destructor-thunks-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Add one validator command per newly created scalar child page.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/00016W-help-tooltip-destructor-thunks-source-quality.md`
- Modified: none outside the B003 research folder.
- By-* docs, generated reports, generated source, source files, IDA DB, and `by-memory/-coverage-report.md`: not edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/00016W-help-tooltip-destructor-thunks-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:26","uid":"00016W"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00016W-help-tooltip-destructor-thunks-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/00016W-help-tooltip-destructor-thunks-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00016W"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
