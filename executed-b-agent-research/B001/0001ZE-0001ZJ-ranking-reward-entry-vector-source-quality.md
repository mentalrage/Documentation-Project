** TARGET-REPORT-UID:0001ZE **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001 Goal 2 - Ranking Reward Entry / Vector Source-Quality Review

Assignment: `B001-goal2-ranking-reward-entry-vector-source-quality-0001ZE-000202-000203-0001ZF-000204-0001ZI-0001ZK-0001ZJ-20260616`

Agent: B001

Date: 2026-06-16

Scope: report-only review for [UID:0001ZE], [UID:000202], [UID:000203], [UID:0001ZF], [UID:000204], [UID:0001ZI], [UID:0001ZK], and [UID:0001ZJ]. No by-* docs, generated reports, IDA DB, generated source, or `by-memory/-coverage-report.md` were edited.

## Executive Recommendation

The reward-entry parser, reward-item layout, and reward-entry/item vector helpers have enough evidence to move the source-bearing reward pages to 85+ after a narrow source-placement refresh. The direct semantic owner for the reward pages should be [UID:0000BP] `RankingRewardInfoDialog`, with emission routed through that class page and ultimately [UID:0000MZ] `RankingDialog.cpp`. The current direct owner [UID:0000MZ] is the file root, but it is not the narrowest canonical owner after [UID:0000BP] is refreshed to 86+.

[UID:0001ZE] is not reward-entry logic. It is the category-record vector storage free helper and should be rerouted to [UID:0000BK] `RankingCategoryCollection`, matching the recently executed category collection precedent.

[UID:000203] should remain non-reconstructable and no-emitter. It is a compiler EH cleanup thunk for the nested reward-item vector. It can be raised to 85+ only as an ignored/compiler-thunk documentation row, not as final C++.

[UID:0001ZI] is the only target that should not stay source-bearing in its current whole-range form. The range mixes reward vector storage helpers with a shared fixed-capacity wide-format wrapper at `0x0045ef20`. That wrapper has non-ranking callers and matches the existing `StringUtil` fixed-buffer wrapper family. Recommended action is to convert [UID:0001ZI] into a reviewed, non-emitting split/index page at 86/90 and create child pages for the reward helpers plus a `StringUtil` child for the formatter.

## Recommended Target Decisions

| UID | Current role | Recommended score | Owner / emitter | Final C++ decision |
| --- | --- | ---: | --- | --- |
| 0001ZE | Category-record vector storage free helper | 86/90 | owner/emitter [UID:0000BK] | Blank. Source-declared/generated-binary container helper, not standalone final code. |
| 000202 | Raw `RankingRewardEntry` default initializer | 85/89 | owner/emitter [UID:0000BP] | Blank until reward entry declarations are emitted. Eligible as class support after owner refresh. |
| 000203 | Compiler EH cleanup thunk | 85/90 | owner `NONE`, no emitter | Must remain blank and non-reconstructable. |
| 0001ZF | `RankingRewardEntry` parser plus text accessors | 86/90 | owner/emitter [UID:0000BP] | Blank for now; eligible once `RankingRewardEntry` / packet-reader declarations are source-ready. |
| 000204 | `RankingRewardEntry::GetItemAt` accessor | 85/89 | owner/emitter [UID:0000BP] | Blank until item-vector layout declaration is emitted. |
| 0001ZI | Mixed reward vector helpers plus shared formatter | 86/90 as split/index only | owner `NONE`, no direct emitter | Blank. Split children carry source placement. |
| 0001ZK | Reward-entry vector destructor/free helper | 86/90 | owner/emitter [UID:0000BP] | Blank until class vector fields are declared. |
| 0001ZJ | Reward entry/item vector range allocation helpers | 86/90 | owner/emitter [UID:0000BP] | Blank until vector helper declarations are emitted. |

## Heuristic / Inference Reanalysis And Validation

### Source Placement

Best source tree placement remains `NexusTK/ui/dialogs/RankingDialog.cpp` through [UID:0000MZ]. The reward-entry structures and vector helpers are semantically owned by `RankingRewardInfoDialog`, not by the file root directly. This mirrors the executed category-collection work, where direct semantic owner pages were preferred after support pages crossed 85+.

Recommended direct owners:

| Range | Direct owner | Reason |
| --- | --- | --- |
| `0x0045d750-0x0045d78a` | [UID:0000BK] | Sole xref is from category-record vector growth at `0x0045d195`; frees 688-byte `RankingCategoryRecord` storage. |
| Reward entry parser/accessors/vector helpers | [UID:0000BP] | All model `RankingRewardInfoDialog` reward-entry storage, parsing, paint data, and teardown. |
| `0x0045ef20-0x0045ef50` | [UID:0000OB] `StringUtil` | Shared fixed-capacity `wchar_t` formatter with screenshot and user-list callers; matches existing StringUtil wrapper family. |
| `0x0045d7d0-0x0045d7db` | `NONE` | Compiler EH cleanup thunk only; no source-owned function. |

### Reward Entry Layout

Best defensible structure name: `RankingRewardEntry`.

Evidence:

- Parser at `0x0045d7e0` consumes three length-prefixed multibyte strings, converts them with `MultiByteToWideChar`, and writes them into `this + 0x000`, `this + 0x010`, and `this + 0x020`.
- Entry vector stride is `0x230` (560) in append, clone, destroy, and range-allocation helpers.
- Reward packet handler initializes a stack temporary with nested vector triplet zeroed and `+0x220 = 0xff`, then appends deep copies into the dialog vector.
- Dialog destructor at `0x0045f0c0` destroys the vector rooted at dialog offset `+0x26c`.

Recommended fields:

```cpp
struct RankingRewardEntry {
    wchar_t rankStartText[8];        // +0x000
    wchar_t rankEndText[8];          // +0x010
    wchar_t symbolText[256];         // +0x020
    signed char symbolFrameIndex;    // +0x220, default -1
    unsigned char symbolAttribute;   // +0x221, parsed byte; exact UI meaning not fully named
    // +0x222..+0x223 alignment/padding
    RankingRewardItemVector items;   // +0x224, begin/end/capacity
}; // sizeof 0x230
```

Rejected alternatives:

- `minRank` / `maxRank` numeric fields: rejected because the parser stores converted wide strings and accessors return `wchar_t *`.
- `titleText` / `rewardText`: rejected because caller and packet context tie the strings to rank-range and symbol display, not a generic title.
- Treating `+0x220` as padding: rejected because default initialization explicitly writes `0xff`, and parser later overwrites it from packet data.
- Treating `+0x221` as padding: rejected because parser explicitly copies a packet byte there. The exact display meaning remains unresolved, so `symbolAttribute` is safer than overclaiming `symbolPaletteIndex` or `symbolFlags`.

Impact:

- The unresolved exact meaning of `symbolAttribute` should not block 85+ source quality. It is localized, packet-backed, and documented. It should block only a polished final C++ field name if no later paint evidence resolves the UI meaning.

### Reward Item Layout

Best defensible structure name: `RankingRewardItem`.

Evidence:

- Nested item vector stride is `0x208` (520) in item append, item clone, item destroy, item accessor, and allocation helpers.
- Parser writes the item name into a 256-wide-character buffer, then writes a quantity, a 16-bit icon id, and a final byte.
- Item accessor at `0x0045db60` indexes the vector with stride `0x208` from entry offset `+0x224`.

Recommended fields:

```cpp
struct RankingRewardItem {
    wchar_t name[256];        // +0x000
    int quantity;             // +0x200
    uint16_t iconId;          // +0x204
    uint8_t paletteIndex;     // +0x206
    uint8_t reserved;         // +0x207, copied as part of the stride
}; // sizeof 0x208
```

Rejected alternatives:

- `rewardId` instead of `quantity`: rejected because the handler reads this value after item name and before icon metadata, and paint context describes reward quantities.
- `uint32_t iconId`: rejected because parser writes the icon field through the 16-bit slot corresponding to offset `+0x204`.
- Dropping byte `+0x207`: rejected because all storage helpers copy the full 520-byte row. Source can leave it implicit padding, but docs should account for it.

Impact:

- `reserved` / implicit padding at `+0x207` should not block 85+. It may remain unnamed in final C++ if the compiler naturally pads the struct.

### Vector Helpers

Best source-facing names:

| Address | Recommended role/name | Evidence |
| --- | --- | --- |
| `0x0045d750` | `RankingCategoryRecordVectorFreeStorage` | Frees `0x2b0` stride category-record storage; sole caller is category vector insert/growth. |
| `0x0045d790` | `RankingRewardEntryDefaultInit` / `RankingRewardEntry::Init` | Zeroes nested vector triplet at `+0x224/+0x228/+0x22c`, sets `symbolFrameIndex = -1`. |
| `0x0045eae0` | `RankingRewardItemVectorInsertWithGrowth` | Appends one 520-byte item, grows storage, validates max count `0x7E07E0`. |
| `0x0045ec50` | `RankingRewardEntryVectorInsertWithGrowth` | Appends one 560-byte entry, deep-copies nested item vector, cleans old ranges. |
| `0x0045ef50` | `RankingRewardItemVectorClone` | Initializes destination triplet, allocates 520-byte rows, copies item storage. |
| `0x0045f020` | `RankingRewardEntryVectorDestroy` | Destroys each nested item vector and frees 560-byte entry storage. |
| `0x0045f130` | `RankingRewardEntryRangeDestroy` | Iterates 560-byte entries and destroys nested item vectors. |
| `0x0045f160` | `RankingRewardItemVectorDestroy` | Frees 520-byte item vector storage and zeros begin/end/capacity. |
| `0x0045f1d0` | `RankingRewardEntryRangeClone` | Copies fixed entry prefix and clones nested item vectors. |
| `0x0045f290` | `RankingRewardItemVectorAllocateStorage` | Allocates `count * 520` with MSVC large-allocation header handling. |
| `0x0045f300` | `RankingRewardEntryVectorFreeStorage` | Frees `count * 560` entry-vector storage. |

Rejected alternatives:

- Assigning these helpers to `RankingDialog` file root only: rejected because [UID:0000BP] is the narrower semantic class owner once refreshed.
- Treating all helpers as compiler-only STL artifacts: rejected because they encode project-specific element strides, deep-copy semantics, and packet-owned nested-vector layout. They are generated-binary support helpers, but they still need source placement and type names.
- Merging reward-entry and reward-item helper roles under one untyped `vector<void>` helper: rejected because strides and destructors differ and the entry helper owns nested-vector cleanup.

Impact:

- Helpers can be 85+ with final C++ blank. The source-quality requirement is to name the semantics, direct owner, element strides, and deep-copy/destructor behavior, not to force standalone final code for compiler-emitted vector machinery.

### Compiler Cleanup Thunks

[UID:000203] `0x0045d7d0-0x0045d7db`:

```asm
add ecx, 0x224
jmp 0x0045f160
```

Evidence:

- Xref is from the exception helper at `0x005fa3ba`.
- IDA models it as a tail chunk of `sub_45DDD0`, but the body is only an EH cleanup thunk that redirects a `RankingRewardEntry *` to the nested item-vector field.
- The target of the jump is `RankingRewardItemVectorDestroy`.

Rejected alternatives:

- A source-authored `RankingRewardEntry::DestroyItems` method: rejected because there is no prologue, no normal source caller, and the only xref is EH cleanup metadata.
- A normal accessor: rejected because it never returns the adjusted pointer; it immediately jumps to the destructor helper.

Impact:

- Keep `RECONSTRUCTABLE:FALSE`, owner `NONE`, blank emitter, final C++ blank.
- Raise to 85/90 is defensible only as an ignored compiler-thunk row with exact source of the cleanup verified.

### Parser And Accessors

[UID:0001ZF] can be 86/90 after body/name refresh.

Best names:

- `RankingRewardEntry::ParseFromPacket` or `RankingRewardEntry_ReadFromPacket`
- `RankingRewardEntry::GetRankStartText`
- `RankingRewardEntry::GetRankEndText`
- `RankingRewardEntry::GetSymbolText`

Evidence:

- Sole parser caller is the reward info packet handler at `0x0045debf`.
- Packet handler accepts opcode byte `0x7d`, subcommand byte `5`, validates category id against selected ranking category, then reads a reward-entry count and parses entries into a dialog vector.
- Parser returns byte count consumed and calls item append helper for each nested reward item.
- The accessors are small raw methods returning `this`, `this + 0x10`, and `this + 0x20`.

Rejected alternatives:

- `Serialize` / `WriteToPacket`: rejected because all packet helpers read from the incoming buffer and write into `this`.
- `GetRewardName`: rejected because accessor at `0x0045db50` returns the symbol text buffer, not an item/reward name row.
- Treating accessor no-xrefs as dead code: rejected because these are tiny source methods preserved without current code xrefs; they still match exact field layout.

Impact:

- Parser/accessor target can move to 86/90 with direct owner [UID:0000BP].
- Final C++ should remain blank until declarations for `RankingRewardEntry`, `RankingRewardItem`, and packet reader helpers are represented consistently.

### Shared Formatter At 0x0045ef20

`0x0045ef20-0x0045ef50` is not reward-vector storage. It is a shared 256-wide-character formatting wrapper.

Evidence:

- Decompiler signature: `int sub_45EF20(wchar_t *Buffer, wchar_t *Format, ...)`.
- Body calls `sub_41B9A0`, then `__stdio_common_vswprintf_s(*opts, Buffer, 0x100, Format, 0, va)`, returning `-1` on negative result.
- Callers:
  - `0x0045e931` in `RankingRewardInfoDialog` paint.
  - `0x0055794e` screenshot JPG path.
  - `0x00557bae` screenshot BMP path.
  - `0x00557f94` screenshot PNG path.
  - `0x0059de96` user-list source-message helper.
- [UID:0000OB] `StringUtil` already owns fixed-capacity wide-format wrappers with capacities `0x104`, `0x20`, and `0x80`.

Rejected alternatives:

- Leave under [UID:0000BP]: rejected because most evidence says the function is shared utility code with multiple non-ranking callers.
- Ignore as pure CRT glue: plausible but rejected for this codebase because the existing `StringUtil` precedent reconstructs and tracks sibling fixed-capacity wrappers.
- Treat as screenshot utility: rejected because it has a ranking caller and a user-list caller in addition to screenshot paths.

Impact:

- Current [UID:0001ZI] cannot honestly be source-bearing as a single reward-owned helper page without either misowning `0x0045ef20` or leaving source placement unresolved.
- Recommended fix is a split: [UID:0001ZI] becomes a reviewed non-emitting split/index page; `0x0045ef20-0x0045ef50` becomes a new [UID:ASSIGN_WIDE_FORMAT_256] child owned/emitted by [UID:0000OB].

## Unresolved Issues And Defended Outcomes

| Issue | Evidence checked | Candidate interpretations | Rejected alternatives | Impact |
| --- | --- | --- | --- | --- |
| Exact UI meaning of `RankingRewardEntry +0x221` | Parser writes a packet byte after `symbolFrameIndex`; current docs call it a flag/extra byte. | `symbolAttribute` is safest; `symbolPaletteIndex` is possible. | Padding rejected because parser writes it. Hard `flags` rejected because no bit tests were verified. | Does not block 85+. Keep final field name conservative. |
| Item byte at `+0x207` | Parser writes low byte at `+0x206`; storage copies full 520-byte row. | Natural source padding/reserved byte. | Named semantic field rejected due lack of reads. | Does not block 85+. Use implicit padding in final source unless later evidence names it. |
| No xrefs to raw initializer/accessor helpers | IDA xrefs for `0x0045d790`, `0x0045db10`, `0x0045db20`, `0x0045db50`, `0x0045db60` are absent. Bodies and field offsets match parser/layout. | Preserved small methods or construction helpers not called in current binary paths. | Dead/unrelated code rejected because offsets, strides, and adjacent placement match reward entry exactly. | Allows 85/89, but final C++ should remain blank until declaration routing is stable. |
| `0x0045ef20` ownership | Formatter has ranking, screenshot, and user-list callers; StringUtil owns sibling fixed wrappers. | Shared `StringUtil` utility wrapper. | Reward-owned helper rejected. Ignore-only rejected by local precedent. | Requires split of [UID:0001ZI] before source-bearing 85+ is clean. |
| Whether vector helpers should emit final C++ | Helpers are source-derived/generated-binary vector support with explicit strides and allocation behavior. | Document as source-placed helper/runtime artifacts and leave final code blank. | Forcing hand-authored standalone C++ rejected because local declarations are not emitted and helper shape is compiler-specific. | 85+ score is appropriate; final C++ remains blank. |

## Recommended Metadata Edits

Apply only after the supervising owner approves the report. These are exact recommended metadata targets, not edits performed by this B-agent pass.

### [UID:0001ZE]

```yaml
COMPLETION: 86
CONFIDENCE: 90
CANONICAL_OWNER: 0000BK
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000BK
```

Recommended title/name: `RankingCategoryRecordVectorFreeStorage`.

Recommended status/body edits:

- Replace generic `sub_45D750` wording with `RankingCategoryRecordVectorFreeStorage`; retain `current IDA label: sub_45D750` only as an evidence alias.
- State that the helper frees `0x2b0`-stride `RankingCategoryRecord` storage with MSVC large-allocation validation.
- State that its sole verified caller is category-record vector insert/growth at `0x0045d195`.
- Source placement: [UID:0000BK] `RankingCategoryCollection`; [UID:0000MZ] remains only the file root.
- Final C++: blank.

### [UID:000202]

```yaml
COMPLETION: 85
CONFIDENCE: 89
CANONICAL_OWNER: 0000BP
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000BP
```

Recommended title/name: `RankingRewardEntryDefaultInit`.

Recommended status/body edits:

- Describe body as raw helper at `0x0045d790`, not currently an IDA function.
- Record exact writes: `items.begin/end/capacity = nullptr` at `+0x224/+0x228/+0x22c`, `symbolFrameIndex = -1` at `+0x220`.
- Note no current xrefs, but the same default initialization pattern appears in the stack temporary used by the reward info packet handler.
- Final C++: blank until `RankingRewardEntry` declaration is emitted.

### [UID:000203]

```yaml
COMPLETION: 85
CONFIDENCE: 90
CANONICAL_OWNER: NONE
RECONSTRUCTABLE: FALSE
EMITTER_UIDS:
```

Recommended title/name: `RankingRewardEntryItemVectorUnwindThunk`.

Recommended status/body edits:

- Keep in ignored/compiler-thunk ledger.
- Body should show the exact thunk:

```asm
add ecx, 0x224
jmp RankingRewardItemVectorDestroy
```

- State xref source: EH cleanup helper at `0x005fa3ba`.
- State no final C++ and no emitter.

### [UID:0001ZF]

```yaml
COMPLETION: 86
CONFIDENCE: 90
CANONICAL_OWNER: 0000BP
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000BP
```

Recommended title/name: `RankingRewardEntryParseAndAccessors`.

Recommended status/body edits:

- Replace blocker-style `sub_45D7E0`, `sub_45DB10`, `sub_45DB20`, `sub_45DB50` wording with:
  - `RankingRewardEntry::ParseFromPacket`
  - `RankingRewardEntry::GetRankStartText`
  - `RankingRewardEntry::GetRankEndText`
  - `RankingRewardEntry::GetSymbolText`
- Include the resolved entry and item layouts from this report.
- State parser consumes incoming packet data and returns bytes consumed.
- State sole verified parser caller is reward info packet handler at `0x0045debf`.
- Final C++: blank until packet-reader and reward-entry declarations are source-ready.

### [UID:000204]

```yaml
COMPLETION: 85
CONFIDENCE: 89
CANONICAL_OWNER: 0000BP
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000BP
```

Recommended title/name: `RankingRewardEntryItemAt`.

Recommended status/body edits:

- Replace `sub_45DB50`/raw-helper language with `RankingRewardEntry::GetItemAt`.
- Record exact semantics: count is `(items.end - items.begin) / 0x208`; if `count <= index`, returns null; otherwise returns `items.begin + index * 0x208`.
- Note helper has no negative-index guard; known callers should pass nonnegative indices.
- Final C++: blank until `RankingRewardItemVector` declaration is emitted.

### [UID:0001ZI]

```yaml
COMPLETION: 86
CONFIDENCE: 90
CANONICAL_OWNER: NONE
RECONSTRUCTABLE: FALSE
EMITTER_UIDS:
```

Recommended title/name: `RankingRewardVectorStorageHelpers`.

Recommended status/body edits:

- Convert current whole-range page to a reviewed split/index page, not a direct source-bearing emitter.
- Explicitly list child pages:
  - [UID:ASSIGN_RRI_ITEM_VEC_INSERT] `0x0045eae0-0x0045ec43.RankingRewardItemVectorInsertWithGrowth.md`, owner/emitter [UID:0000BP], 86/90.
  - [UID:ASSIGN_RRE_VEC_INSERT] `0x0045ec50-0x0045ef1f.RankingRewardEntryVectorInsertWithGrowth.md`, owner/emitter [UID:0000BP], 86/90.
  - [UID:ASSIGN_WIDE_FORMAT_256] `0x0045ef20-0x0045ef50.WideFormatWrapper256.md`, owner/emitter [UID:0000OB], 85/90.
  - [UID:ASSIGN_RRI_VEC_CLONE] `0x0045ef50-0x0045efd0.RankingRewardItemVectorClone.md`, owner/emitter [UID:0000BP], 86/90.
- State no padding/ignored row is needed inside the split; `0x0045ef20` and `0x0045ef50` are adjacent function starts.
- Final C++ for [UID:0001ZI]: blank. Children remain blank until declarations are emitted.

### [UID:0001ZK]

```yaml
COMPLETION: 86
CONFIDENCE: 90
CANONICAL_OWNER: 0000BP
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000BP
```

Recommended title/name: `RankingRewardEntryVectorDestroy`.

Recommended status/body edits:

- Replace `sub_45F020` with `RankingRewardEntryVectorDestroy`; retain old label only as current IDA alias.
- Record xrefs from constructor cleanup, scalar deleting destructor, and EH cleanup.
- State it iterates `0x230`-stride entries, destroys nested item vectors at `+0x224`, frees entry storage, and zeros the vector triplet.
- Final C++: blank.

### [UID:0001ZJ]

```yaml
COMPLETION: 86
CONFIDENCE: 90
CANONICAL_OWNER: 0000BP
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000BP
```

Recommended title/name: `RankingRewardVectorRangeAllocationHelpers`.

Recommended status/body edits:

- Replace unresolved helper labels with source-facing names:
  - `RankingRewardEntryRangeDestroy` at `0x0045f130`.
  - `RankingRewardItemVectorDestroy` at `0x0045f160`.
  - `RankingRewardEntryRangeClone` at `0x0045f1d0`.
  - `RankingRewardItemVectorAllocateStorage` at `0x0045f290`.
  - `RankingRewardEntryVectorFreeStorage` at `0x0045f300`.
- Record element sizes: 560-byte entries and 520-byte items.
- State large-allocation header validation is MSVC allocator behavior, not domain logic.
- Final C++: blank.

## Recommended Support-Doc Updates

### [UID:0000BP] `by-class/RankingRewardInfoDialog.md`

Recommended metadata:

```yaml
COMPLETION: 86
CONFIDENCE: 90
```

Recommended body additions:

- Add `RankingRewardEntry` layout:
  - `rankStartText[8]` at `+0x000`.
  - `rankEndText[8]` at `+0x010`.
  - `symbolText[256]` at `+0x020`.
  - `symbolFrameIndex` at `+0x220`, default `-1`.
  - `symbolAttribute` at `+0x221`.
  - nested `RankingRewardItemVector` at `+0x224`.
  - total size `0x230`.
- Add `RankingRewardItem` layout:
  - `name[256]` at `+0x000`.
  - `quantity` at `+0x200`.
  - `iconId` at `+0x204`.
  - `paletteIndex` at `+0x206`.
  - implicit/reserved byte at `+0x207`.
  - total size `0x208`.
- Add source placement note: reward-entry parser/accessors/vector helpers are direct children of `RankingRewardInfoDialog`; `RankingDialog.cpp` remains the file emitter root through [UID:0000MZ].
- Add split note: `0x0045ef20` is a shared StringUtil fixed-256 wide formatter, not a reward-vector helper.

### [UID:0001ZG] `RankingRewardInfoDialogCore`

Recommended metadata:

```yaml
COMPLETION: 86
CONFIDENCE: 90
CANONICAL_OWNER: 0000BP
EMITTER_UIDS: 0000BP
```

Recommended body additions:

- Cross-link [UID:0001ZF], [UID:0001ZK], [UID:0001ZJ], and the split children from [UID:0001ZI].
- State constructor/destructor lifecycle:
  - dialog vector at offset `+0x26c`;
  - destructor calls `RankingRewardEntryVectorDestroy`;
  - packet handler appends deep-copied `RankingRewardEntry` rows and invalidates the dialog.

### [UID:0000OB] `by-file/StringUtil.md`

Recommended body addition only; score can remain 87/88 or optionally rise to 87/89:

- Add child [UID:ASSIGN_WIDE_FORMAT_256] `0x0045ef20-0x0045ef50.WideFormatWrapper256.md`.
- Note capacity `0x100` wide characters and callers from ranking reward paint, screenshot paths, and user-list source-message formatting.

### [UID:0000XZ] and [UID:0000MZ]

Recommended body updates only:

- [UID:0000XZ] should reflect direct reward helper ownership through [UID:0000BP] after the class refresh.
- [UID:0000MZ] remains the generated file root for `NexusTK/ui/dialogs/RankingDialog.cpp`; no score change required.
- Mention the [UID:0001ZI] split so the aggregate no longer implies the fixed wide formatter belongs to reward vector storage.

## Recommended Ignored-Row Changes

No new ignored padding rows are required.

Keep existing padding rows:

```text
0x0045d740-0x0045d750
0x0045d78a-0x0045d790
0x0045d7c2-0x0045d7d0
0x0045d7db-0x0045d7e0
0x0045db54-0x0045db60
0x0045db9e-0x0045dba0
```

Keep [UID:000203] as ignored/compiler-thunk documentation, but update score to 85/90 and body wording as described above.

Do not add an ignored row around `0x0045ef20-0x0045ef50`; it should be split to a `StringUtil` child page rather than ignored.

## Supervisor-Owned Coverage Replacement Rows

Recommended replacement excerpt for `by-memory/-coverage-report.md` after the metadata/body changes are applied. UID placeholders under [UID:0001ZI] require supervisor/A-agent UID assignment before execution.

```text
- [UID:0001ZE] `0x0045d750-0x0045d78a` | by-memory/0x0045d750-0x0045d78a.RankingCategoryRecordVectorFreeHelper.md | function | RankingCategoryRecordVectorFreeStorage : reconstructable : 86% : very strong : Source-declared/generated-binary category-record vector storage free helper; direct owner/emitter [UID:0000BK], final C++ blank.
- padding `0x0045d78a-0x0045d790` | by-memory/-ignored.md | padding/alignment | alignment : ignored : 100% : high : Existing alignment before reward-entry initializer.
- [UID:000202] `0x0045d790-0x0045d7c2` | by-memory/0x0045d790-0x0045d7c2.RankingRewardEntryVectorInit.md | raw-helper | RankingRewardEntryDefaultInit : reconstructable : 85% : very strong : Initializes `RankingRewardEntry` nested item-vector triplet and default symbol frame; direct owner/emitter [UID:0000BP], final C++ blank pending declarations.
- padding `0x0045d7c2-0x0045d7d0` | by-memory/-ignored.md | padding/alignment | alignment : ignored : 100% : high : Existing alignment before EH cleanup thunk.
- [UID:000203] `0x0045d7d0-0x0045d7db` | by-memory/0x0045d7d0-0x0045d7db.RankingRewardEntryItemVectorUnwindThunk.md | compiler-thunk | RankingRewardEntryItemVectorUnwindThunk : ignored : 85% : very strong : EH cleanup thunk adjusting `this + 0x224` and tail-jumping to `RankingRewardItemVectorDestroy`; no owner, no emitter, final C++ blank.
- padding `0x0045d7db-0x0045d7e0` | by-memory/-ignored.md | padding/alignment | alignment : ignored : 100% : high : Existing alignment before parser.
- [UID:0001ZF] `0x0045d7e0-0x0045db54` | by-memory/0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors.md | function-group | RankingRewardEntryParseAndAccessors : reconstructable : 86% : very strong : Packet parser plus rank/symbol text accessors for 560-byte reward entries; direct owner/emitter [UID:0000BP], final C++ blank pending declarations.
- padding `0x0045db54-0x0045db60` | by-memory/-ignored.md | padding/alignment | alignment : ignored : 100% : high : Existing alignment before item accessor.
- [UID:000204] `0x0045db60-0x0045db9e` | by-memory/0x0045db60-0x0045db9e.RankingRewardEntryItemAt.md | raw-helper | RankingRewardEntryItemAt : reconstructable : 85% : very strong : Bounds-checked nested reward-item accessor using 520-byte stride; direct owner/emitter [UID:0000BP], final C++ blank pending declarations.
- padding `0x0045db9e-0x0045dba0` | by-memory/-ignored.md | padding/alignment | alignment : ignored : 100% : high : Existing alignment before reward dialog constructor.
  - [UID:0001ZI] `0x0045eae0-0x0045efd0` | by-memory/0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers.md | split-index | RankingRewardVectorStorageHelpers : reviewed-container : 86% : very strong : Non-emitting split/index for reward vector storage helpers plus extracted shared formatter; child pages carry owner/emitter placement, final C++ blank.
    - [UID:ASSIGN_RRI_ITEM_VEC_INSERT] `0x0045eae0-0x0045ec43` | by-memory/0x0045eae0-0x0045ec43.RankingRewardItemVectorInsertWithGrowth.md | function | RankingRewardItemVectorInsertWithGrowth : reconstructable : 86% : very strong : Appends/grows 520-byte reward-item vectors; owner/emitter [UID:0000BP], final C++ blank.
    - [UID:ASSIGN_RRE_VEC_INSERT] `0x0045ec50-0x0045ef1f` | by-memory/0x0045ec50-0x0045ef1f.RankingRewardEntryVectorInsertWithGrowth.md | function | RankingRewardEntryVectorInsertWithGrowth : reconstructable : 86% : very strong : Appends/grows 560-byte reward-entry vectors with nested item-vector clone/destruction; owner/emitter [UID:0000BP], final C++ blank.
    - [UID:ASSIGN_WIDE_FORMAT_256] `0x0045ef20-0x0045ef50` | by-memory/0x0045ef20-0x0045ef50.WideFormatWrapper256.md | function | WideFormatWrapper256 : reconstructable : 85% : very strong : Shared `StringUtil` fixed-capacity `wchar_t[256]` formatting wrapper used by ranking, screenshot, and user-list code; owner/emitter [UID:0000OB], final C++ blank.
    - [UID:ASSIGN_RRI_VEC_CLONE] `0x0045ef50-0x0045efd0` | by-memory/0x0045ef50-0x0045efd0.RankingRewardItemVectorClone.md | function | RankingRewardItemVectorClone : reconstructable : 86% : very strong : Deep-copies 520-byte reward-item vector storage; owner/emitter [UID:0000BP], final C++ blank.
  - [UID:0001ZK] `0x0045f020-0x0045f0a7` | by-memory/0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy.md | function | RankingRewardEntryVectorDestroy : reconstructable : 86% : very strong : Destroys nested item vectors and frees 560-byte reward-entry vector storage; direct owner/emitter [UID:0000BP], final C++ blank.
- [UID:0001ZJ] `0x0045f130-0x0045f33a` | by-memory/0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers.md | function-group | RankingRewardVectorRangeAllocationHelpers : reconstructable : 86% : very strong : Reward entry/item vector range destroy, clone, allocation, and free-storage helpers; direct owner/emitter [UID:0000BP], final C++ blank.
```

## Validation Commands And Order

Recommended validation order after supervisor/A-agent applies the edits:

> Executable block R001 was removed from this report and preserved verbatim in [0001ZE-0001ZJ-ranking-reward-entry-vector-source-quality-removed.md](0001ZE-0001ZJ-ranking-reward-entry-vector-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Final C++ status after the recommended edits:

- [UID:0001ZE], [UID:000202], [UID:0001ZF], [UID:000204], [UID:0001ZK], [UID:0001ZJ]: 85+ source-quality eligible but final C++ should remain blank until source declarations and emitter routing are refreshed.
- [UID:0001ZI]: final C++ must remain blank as a non-emitting split/index page.
- [UID:000203]: final C++ must remain blank permanently as an ignored compiler-thunk row.
- [UID:ASSIGN_WIDE_FORMAT_256] and other proposed child pages: final C++ blank initially; they become eligible only after their owning support pages emit compatible declarations.

## Evidence Log

Files inspected:

- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Agent-B001/goal.md`
- `tools/leaser/Agents/Agent-B001/notes.md`
- `tools/leaser/Agents/Agent-B001/inference_research.md`
- `by-structure.md`
- `by-project-structure/proposed-source-tree.md`
- Primary target pages for [UID:0001ZE], [UID:000202], [UID:000203], [UID:0001ZF], [UID:000204], [UID:0001ZI], [UID:0001ZK], [UID:0001ZJ]
- Context pages [UID:0000BP], [UID:0000MZ], [UID:0000XZ], [UID:0001ZG], [UID:0001ZH]
- Category precedent pages [UID:0000BK], [UID:0000BL], [UID:0001VN]
- Executed B002 reports for ranking category collection and ranking user-entry append
- `by-file/StringUtil.md`
- `by-memory/-report.old.md`
- `by-memory/-ignored.md`
- `by-memory/-coverage-report.md`
- `project-level/-auto-completion-stats.md`
- `auto-generated/-ag-memory-coverage.md`

IDA MCP checks performed:

- Function lookup and xref checks for all target entry points and internal helper starts.
- Decompiler analysis for `0x0045cf50`, `0x0045d7e0`, `0x0045ddd0`, `0x0045eae0`, `0x0045ec50`, `0x0045ef20`, `0x0045ef50`, `0x0045f020`, `0x0045f0c0`, `0x0045f160`, `0x0045f1d0`, `0x0045f290`, `0x0045f300`.
- Disassembly checks for raw/no-function ranges `0x0045d790`, `0x0045d7d0`, `0x0045db10`, `0x0045db20`, `0x0045db50`, and `0x0045db60`.

Key xrefs:

- `0x0045d750`: sole xref from `0x0045d195` in category-record vector growth.
- `0x0045d7d0`: xref from EH cleanup helper `0x005fa3ba`.
- `0x0045d7e0`: xref from reward info packet handler `0x0045debf`.
- `0x0045eae0`: xref from parser item loop `0x0045dacd`.
- `0x0045ec50`: xref from reward info packet handler `0x0045df2f`.
- `0x0045ef20`: xrefs from ranking paint, screenshot JPG/BMP/PNG paths, and user-list source-message helper.
- `0x0045ef50`: xrefs from reward packet handler, entry insert/grow, and entry range clone.
- `0x0045f020`: xrefs from constructor cleanup, scalar deleting destructor, and EH cleanup.
- `0x0045f160`: xrefs from EH thunk, packet temp cleanup, vector insert/grow cleanup, entry destructor, and entry range destroy.

## Final Call

All primary targets have a defensible path to 85/85+ if the source-placement and split recommendations above are executed. The only target that should not remain directly source-bearing is [UID:0001ZI] because of the embedded shared formatter. [UID:000203] should remain non-reconstructable forever, but can still be scored 85+ as a fully explained compiler-thunk/ignored row.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001ZE-0001ZJ-ranking-reward-entry-vector-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"0001ZE"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001ZE-0001ZJ-ranking-reward-entry-vector-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001ZE-0001ZJ-ranking-reward-entry-vector-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001ZE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
